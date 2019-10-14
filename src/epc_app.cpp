/*
* Copyright (c) 2019 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <signal.h>
#include <iostream>
#include <limits>

#include "epctools.h"
#include "epc_app.h"


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

EpcApplication g_app;

void signal_handler(int signal)
{
   ELogger::log(LOG_SYSTEM).startup( "Caught signal ({})", signal );

   switch (signal)
   {
      case SIGINT:
      case SIGTERM:
      {
         ELogger::log(LOG_SYSTEM).startup( "Setting shutdown event" );
         g_app.setShutdownEvent();
         break;
      }
   }
}

Void init_signal_handler()
{
   sigset_t sigset;

   /* mask SIGALRM in all threads by default */
   sigemptyset(&sigset);
   sigaddset(&sigset, SIGRTMIN);
   sigaddset(&sigset, SIGUSR1);
   sigprocmask(SIG_BLOCK, &sigset, NULL);   

   struct sigaction sa;

   /* Setup the signal handler */
   sa.sa_handler = signal_handler;

   /* Restart the system call, if at all possible */
   sa.sa_flags = SA_RESTART;

   /* Block every signal during the handler */
   sigfillset(&sa.sa_mask);

   if (sigaction(SIGINT, &sa, NULL) == -1)
      throw EError( EError::Warning, errno, "Unable to register SIGINT handler") ;
   ELogger::log(LOG_SYSTEM).startup( "signal handler registered for SIGINT" );

   if (sigaction(SIGTERM, &sa, NULL) == -1)
      throw EError( EError::Warning, errno, "Unable to register SIGTERM handler" );
   ELogger::log(LOG_SYSTEM).startup( "signal handler registered for SIGTERM" );

   if (sigaction(SIGRTMIN+1, &sa, NULL) == -1)
      throw EError( EError::Warning, errno, "Unable to register SIGRTMIN handler" );
   ELogger::log(LOG_SYSTEM).startup( "signal handler registered for SIGRTMIN" );
}

Void usage()
{
   cpStr msg =
       "USAGE:  epc_app [--print] [--help] [--file optionfile]\n";

   std::cout << msg;
}

int main(int argc, char *argv[])
{
   EGetOpt::Option options[] = {
       {"-h", "--help", EGetOpt::no_argument, EGetOpt::dtNone},
       {"-f", "--file", EGetOpt::required_argument, EGetOpt::dtString},
       {"-p", "--print", EGetOpt::no_argument, EGetOpt::dtBool},
       {"", "", EGetOpt::no_argument, EGetOpt::dtNone},
   };

   EGetOpt opt;
   EString optfile;

   try
   {
      opt.loadCmdLine(argc, argv, options);
      if (opt.getCmdLine("-h,--help",false))
      {
         usage();
         return 0;
      }

      optfile.format("%s.json", argv[0]);
      if (EUtility::file_exists(optfile))
         opt.loadFile(optfile);
      
      optfile = opt.getCmdLine( "-f,--file", "__unknown__" );
      if (EUtility::file_exists(optfile))
         opt.loadFile(optfile);
      
      if (opt.getCmdLine( "-p,--print", false))
         opt.print();
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
      return 1;
   }

   try
   {
      EpcTools::Initialize(opt);
      ELogger::log(LOG_SYSTEM).startup("EpcTools initialization complete" );

      try
      {
         init_signal_handler();

         g_app.startup(opt);
         g_app.waitForShutdown();
         g_app.shutdown();
      }
      catch(const std::exception& e)
      {
         ELogger::log(LOG_SYSTEM).major( e.what() );
      }
      
      ELogger::log(LOG_SYSTEM).startup("Shutting down EpcTools" );
      EpcTools::UnInitialize();
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
      return 2;
   }
   
   return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Void EpcApplication::shutdown()
{
   if (m_worker)
   {
      m_worker->quit();
      m_worker->join();
      delete m_worker;
   }
   m_diameter.uninit(false);
}

Void EpcApplication::startup(EGetOpt &opt)
{
   try
   {
      // set the role
      EString role = opt.get("/EpcApplication/role", "client");
      m_role = role.tolower() == "client" ? EpcApplication::Role::client : EpcApplication::Role::server;
      ELogger::log(LOG_SYSTEM).startup("Configuring application as [{}]", role);

      // set the diameter configuration file
      m_diameter.setConfigFile( opt.get("/EpcApplication/freeDiameter/configfile","./conf/epc_app.conf") );

      // initialize diameter
      if ( !m_diameter.init() )
      {
         ELogger::log(LOG_SYSTEM).minor("Failure initializing Diameter");
         return;
      }

      // initialize the swm application
      m_swm = new swm::Application( *this );

      // advertise support for the accounting application
      FDDictionaryEntryVendor vnd3gpp( m_swm->getDict().app() );
      m_diameter.advertiseSupport( m_swm->getDict().app(), vnd3gpp, 1, 0 );

      //TODO get the list of peers from the database
      FDPeer *peer = new FDPeer();
      peer->setDiameterId( (DiamId_t)opt.get("/EpcApplication/freeDiameter/peerhost","epc_app.localdomain") );
      peer->setDestinationIp( opt.get("/EpcApplication/freeDiameter/peerip","127.0.0.1") );
      peer->setPort( opt.get("/EpcApplication/freeDiameter/peerport",3868) );
      peer->add();
      m_swm->setPeer( peer );

      // register the message handlers
      m_swm->registerHandlers( getRole() == Role::client );

      // add the interface
      EStatistics::Interface &ifcswm( EStatistics::addInterface(m_swm->getDict().app().getId(), EStatistics::ProtocolType::diameter, "SWm") );

      // add the template messages
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdDER().getCommandCode(), m_swm->getDict().cmdDER().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdDEA().getCommandCode() | DIAMETER_ANSWER_BIT, m_swm->getDict().cmdDEA().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdAAR().getCommandCode(), m_swm->getDict().cmdAAR().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdAAA().getCommandCode() | DIAMETER_ANSWER_BIT, m_swm->getDict().cmdAAA().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdSTR().getCommandCode(), m_swm->getDict().cmdSTR().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdSTA().getCommandCode() | DIAMETER_ANSWER_BIT, m_swm->getDict().cmdSTA().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdASR().getCommandCode(), m_swm->getDict().cmdASR().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdASA().getCommandCode() | DIAMETER_ANSWER_BIT, m_swm->getDict().cmdASA().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdRAR().getCommandCode(), m_swm->getDict().cmdRAR().getName() );
      ifcswm.addMessageStatsTemplate( m_swm->getDict().cmdRAA().getCommandCode() | DIAMETER_ANSWER_BIT, m_swm->getDict().cmdRAA().getName() );

      // initialize the statistics
      EStatistics::init( ELogger::log(LOG_SYSTEM) );

      // intialize the CLI
      m_cliep = new ECliEndpoint( opt.get("/EpcApplication/cliport",1234) );

      m_statsget = new CliStatsGet( ELogger::log(LOG_AUDIT) );
      m_cliep->registerHandler( *m_statsget );

      m_statsresetput = new CliStatsResetPut( ELogger::log(LOG_AUDIT) );
      m_cliep->registerHandler( *m_statsresetput );

      m_cliep->start();

      // start diameter
      if(!m_diameter.start())
      {
         ELogger::log(LOG_SYSTEM).major("Failure starting Diameter");
         return;
      }

      // start the worker thread
      m_worker = new EpcWorker(*this);
      m_worker->init(1, 1, NULL, 200000);

      // start the menu thread
      m_menu = new MenuThread(*this);
      m_menu->init(m_menu);
   }
   catch ( FDException &e )
   {
      ELogger::log(LOG_SYSTEM).startup("Exception initializing diameter - {}", e.what());
      return;
   }
   catch (...)
   {
      ELogger::log(LOG_SYSTEM).startup("Exception initializing EpcApplication");
      return;
   }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(EpcWorker, EThreadPrivate)
   ON_MESSAGE(EVT_SEND_DER, EpcWorker::onSendDER)
   ON_MESSAGE(EVT_SEND_AAR, EpcWorker::onSendAAR)
   ON_MESSAGE(EVT_SEND_STR, EpcWorker::onSendSTR)
   ON_MESSAGE(EVT_SEND_ASR, EpcWorker::onSendASR)
   ON_MESSAGE(EVT_SEND_RAR, EpcWorker::onSendRAR)
   ON_MESSAGE(EVT_RCVD_DER, EpcWorker::onRcvdDER)
   ON_MESSAGE(EVT_RCVD_AAR, EpcWorker::onRcvdAAR)
   ON_MESSAGE(EVT_RCVD_STR, EpcWorker::onRcvdSTR)
   ON_MESSAGE(EVT_RCVD_ASR, EpcWorker::onRcvdASR)
   ON_MESSAGE(EVT_RCVD_RAR, EpcWorker::onRcvdRAR)
   ON_MESSAGE(EVT_RCVD_DEA, EpcWorker::onRcvdDEA)
   ON_MESSAGE(EVT_RCVD_AAA, EpcWorker::onRcvdAAA)
   ON_MESSAGE(EVT_RCVD_STA, EpcWorker::onRcvdSTA)
   ON_MESSAGE(EVT_RCVD_ASA, EpcWorker::onRcvdASA)
   ON_MESSAGE(EVT_RCVD_RAA, EpcWorker::onRcvdRAA)
END_MESSAGE_MAP()

EpcWorker::EpcWorker(EpcApplication &app)
   : m_app( app )
{
}

Void EpcWorker::onInit()
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onInit" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onQuit()
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onQuit" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

Void EpcWorker::onSendDER(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onSendDER" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   m_app.getSwmApplication().sendDERreq( m_app.getSwmApplication().getPeer() );
}

Void EpcWorker::onSendAAR(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onSendAAR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   // alternate method of populating and sending a request

   //  creates the AARreq object
   swm::AARreq *s = new swm::AARreq( m_app.getSwmApplication() );

   // setting preserve to TRUE prevents the Answer object recieved in the
   // processAnswer() method from being destroyed after processAnswer() returns.
   // This would be required if the answer object were to be processed by
   // another thread.
   s->setPreserveAnswer( True );

   //TODO - Code must be added to correctly
   //         populate the DER request object
   s->add( m_app.getSwmDictionary().avpSessionId(), s->getSessionId() );
   s->add( m_app.getSwmDictionary().avpAuthApplicationId(),  m_app.getSwmDictionary().app().getId() );
   s->addOrigin();
   s->add( m_app.getSwmDictionary().avpDestinationHost(), m_app.getSwmApplication().getDestinationHost() );
   s->add( m_app.getSwmDictionary().avpDestinationRealm(), m_app.getSwmApplication().getDestinationRealm() );
   s->add( m_app.getSwmDictionary().avpAuthRequestType(), 2 /* AUTHORIZE_ONLY */ );
   s->add( m_app.getSwmDictionary().avpUserName(), "realm-H!username@realm-X" );

   s->dump();
   s->send();
   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onSendSTR(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onSendSTR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   // alternate method of populating and sending a request

   //  creates the AARreq object
   swm::STRreq *s = new swm::STRreq( m_app.getSwmApplication() );

   // setting preserve to TRUE prevents the Answer object recieved in the
   // processAnswer() method from being destroyed after processAnswer() returns.
   // This would be required if the answer object were to be processed by
   // another thread.
   s->setPreserveAnswer( True );

   //TODO - Code must be added to correctly
   //         populate the DER request object
   s->add( m_app.getSwmDictionary().avpSessionId(), s->getSessionId() );
   s->addOrigin();
   s->add( m_app.getSwmDictionary().avpDestinationHost(), m_app.getSwmApplication().getDestinationHost() );
   s->add( m_app.getSwmDictionary().avpDestinationRealm(), m_app.getSwmApplication().getDestinationRealm() );
   s->add( m_app.getSwmDictionary().avpAuthApplicationId(),  m_app.getSwmDictionary().app().getId() );
   s->add( m_app.getSwmDictionary().avpTerminationCause(), 1 /* DIAMETER_LOGOUT */ );
   s->add( m_app.getSwmDictionary().avpUserName(), "realm-H!username@realm-X" );

   s->dump();
   s->send();
   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onSendASR(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onSendASR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   // alternate method of populating and sending a request

   //  creates the AARreq object
   swm::ASRreq *s = new swm::ASRreq( m_app.getSwmApplication() );

   // setting preserve to TRUE prevents the Answer object recieved in the
   // processAnswer() method from being destroyed after processAnswer() returns.
   // This would be required if the answer object were to be processed by
   // another thread.
   s->setPreserveAnswer( True );

   //TODO - Code must be added to correctly
   //         populate the DER request object
   s->add( m_app.getSwmDictionary().avpSessionId(), s->getSessionId() );
   s->addOrigin();
   s->add( m_app.getSwmDictionary().avpDestinationHost(), m_app.getSwmApplication().getDestinationHost() );
   s->add( m_app.getSwmDictionary().avpDestinationRealm(), m_app.getSwmApplication().getDestinationRealm() );
   s->add( m_app.getSwmDictionary().avpAuthApplicationId(),  m_app.getSwmDictionary().app().getId() );
   s->add( m_app.getSwmDictionary().avpTerminationCause(), 1 /* DIAMETER_LOGOUT */ );
   s->add( m_app.getSwmDictionary().avpUserName(), "realm-H!username@realm-X" );

   s->dump();
   s->send();
   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onSendRAR(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onSendRAR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   // alternate method of populating and sending a request

   //  creates the AARreq object
   swm::RARreq *s = new swm::RARreq( m_app.getSwmApplication() );

   // setting preserve to TRUE prevents the Answer object recieved in the
   // processAnswer() method from being destroyed after processAnswer() returns.
   // This would be required if the answer object were to be processed by
   // another thread.
   s->setPreserveAnswer( True );

   //TODO - Code must be added to correctly
   //         populate the DER request object
   s->add( m_app.getSwmDictionary().avpSessionId(), s->getSessionId() );
   s->addOrigin();
   s->add( m_app.getSwmDictionary().avpDestinationHost(), m_app.getSwmApplication().getDestinationHost() );
   s->add( m_app.getSwmDictionary().avpDestinationRealm(), m_app.getSwmApplication().getDestinationRealm() );
   s->add( m_app.getSwmDictionary().avpAuthApplicationId(),  m_app.getSwmDictionary().app().getId() );
   s->add( m_app.getSwmDictionary().avpReAuthRequestType(), 0 /* AUTHORIZE_ONLY */ );
   s->add( m_app.getSwmDictionary().avpUserName(), "realm-H!username@realm-X" );

   s->dump();
   s->send();
   std::cout << std::string(80,'*') << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

Void EpcWorker::onRcvdDER(EThreadMessage &msg)
{
   FDMessageRequest *rqst = (FDMessageRequest*)msg.getVoidPtr();

   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdDER" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   rqst->dump();
   std::cout << std::string(80,'*') << std::endl;

   swm::Dictionary &dict( m_app.getSwmDictionary() );
   swm::DiameterEapRequestExtractor der( *rqst, dict );

   // create the answer from the request
   FDMessageAnswer dea( rqst );

   // populate the answer
   // the Session-Id is automatically added to the answer
   dea.add( der.auth_application_id );
   dea.add( der.auth_request_type );
   dea.add( dict.avpResultCode(), 2001 );
   dea.addOrigin();
   dea.add( der.eap_payload );
   dea.add( der.user_name );

   dea.dump();
   std::cout << std::string(80,'*') << std::endl;

   dea.send();
   delete rqst;
}

Void EpcWorker::onRcvdAAR(EThreadMessage &msg)
{
   FDMessageRequest *rqst = (FDMessageRequest*)msg.getVoidPtr();

   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdAAR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   rqst->dump();
   std::cout << std::string(80,'*') << std::endl;

   swm::Dictionary &dict( m_app.getSwmDictionary() );
   swm::AaRequestExtractor aar( *rqst, dict );

   // create the answer from the request
   FDMessageAnswer aaa( rqst );

   // populate the answer
   // the Session-Id is automatically added to the answer
   aaa.add( aar.auth_application_id );
   aaa.add( aar.auth_request_type );
   aaa.add( dict.avpResultCode(), 2001 );
   aaa.addOrigin();
   aaa.add( aar.user_name );

   aaa.dump();
   std::cout << std::string(80,'*') << std::endl;

   aaa.send();
   delete rqst;
}

Void EpcWorker::onRcvdSTR(EThreadMessage &msg)
{
   FDMessageRequest *rqst = (FDMessageRequest*)msg.getVoidPtr();

   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdSTR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   rqst->dump();
   std::cout << std::string(80,'*') << std::endl;

   swm::Dictionary &dict( m_app.getSwmDictionary() );
   swm::SessionTerminationRequestExtractor str( *rqst, dict );

   // create the answer from the request
   FDMessageAnswer sta( rqst );

   // populate the answer
   // the Session-Id is automatically added to the answer
   sta.add( dict.avpResultCode(), 2001 );
   sta.addOrigin();

   sta.dump();
   std::cout << std::string(80,'*') << std::endl;

   sta.send();
   delete rqst;
}

Void EpcWorker::onRcvdASR(EThreadMessage &msg)
{
   FDMessageRequest *rqst = (FDMessageRequest*)msg.getVoidPtr();

   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdASR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   rqst->dump();
   std::cout << std::string(80,'*') << std::endl;

   swm::Dictionary &dict( m_app.getSwmDictionary() );
   swm::AbortSessionRequestExtractor asr( *rqst, dict );

   // create the answer from the request
   FDMessageAnswer sta( rqst );

   // populate the answer
   // the Session-Id is automatically added to the answer
   sta.add( dict.avpResultCode(), 2001 );
   sta.addOrigin();

   sta.dump();
   std::cout << std::string(80,'*') << std::endl;

   sta.send();
   delete rqst;
}

Void EpcWorker::onRcvdRAR(EThreadMessage &msg)
{
   FDMessageRequest *rqst = (FDMessageRequest*)msg.getVoidPtr();

   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdRAR" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   rqst->dump();
   std::cout << std::string(80,'*') << std::endl;

   swm::Dictionary &dict( m_app.getSwmDictionary() );
   swm::ReAuthRequestExtractor rar( *rqst, dict );

   // create the answer from the request
   FDMessageAnswer raa( rqst );

   // populate the answer
   // the Session-Id is automatically added to the answer
   raa.add( dict.avpResultCode(), 2001 );
   raa.addOrigin();
   raa.add( rar.user_name );

   raa.dump();
   std::cout << std::string(80,'*') << std::endl;

   raa.send();
   delete rqst;
}

////////////////////////////////////////////////////////////////////////////////

Void EpcWorker::onRcvdDEA(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdDEA" << std::endl;
   std::cout << std::string(80,'*') << std::endl;
   
   FDMessageAnswer *ans = (FDMessageAnswer*)msg.getVoidPtr();
   swm::DiameterEapAnswerExtractor dea( *ans, m_app.getSwmDictionary() );

   ans->dump();
   delete ans;

   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onRcvdAAA(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdAAA" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   FDMessageAnswer *ans = (FDMessageAnswer*)msg.getVoidPtr();
   swm::AaAnswerExtractor aaa( *ans, m_app.getSwmDictionary() );
   
   ans->dump();
   delete ans;

   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onRcvdSTA(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdSTA" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   FDMessageAnswer *ans = (FDMessageAnswer*)msg.getVoidPtr();
   swm::SessionTerminationAnswerExtractor sta( *ans, m_app.getSwmDictionary() );
   
   ans->dump();
   delete ans;

   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onRcvdASA(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdASA" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   FDMessageAnswer *ans = (FDMessageAnswer*)msg.getVoidPtr();
   swm::AbortSessionAnswerExtractor asa( *ans, m_app.getSwmDictionary() );
   
   ans->dump();
   delete ans;

   std::cout << std::string(80,'*') << std::endl;
}

Void EpcWorker::onRcvdRAA(EThreadMessage &msg)
{
   std::cout << std::string(80,'*') << std::endl;
   std::cout << "EpcWorker::onRcvdRAA" << std::endl;
   std::cout << std::string(80,'*') << std::endl;

   FDMessageAnswer *ans = (FDMessageAnswer*)msg.getVoidPtr();
   swm::ReAuthAnswerExtractor raa( *ans, m_app.getSwmDictionary() );
   
   ans->dump();
   delete ans;

   std::cout << std::string(80,'*') << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

MenuThread::MenuThread( EpcApplication &app)
   : m_app(app),
      m_shutdown(False)
{
}

Void MenuThread::shutdown()
{
   m_shutdown = True;
}

Dword MenuThread::threadProc(pVoid arg)
{
   int choice;

   while (!m_shutdown)
   {
      displayMenu();

      if ( std::cin >> choice )
      {
         if (m_app.getRole() == EpcApplication::Role::client)
         {
            switch ( choice )
            {
               case 1: { m_app.getWorker().sendMessage(EVT_SEND_DER); break; }
               case 2: { m_app.getWorker().sendMessage(EVT_SEND_AAR); break; }
               case 3: { m_app.getWorker().sendMessage(EVT_SEND_STR); break; }
               case 99: { break; }
               default:
               {
                  std::cout << "Unrecognized menu option" << std::endl;
               }
            }

            if ( choice == 99 )
               break;
         }
         else
         {
            switch ( choice )
            {
               case 1: { m_app.getWorker().sendMessage(EVT_SEND_ASR); break; }
               case 2: { m_app.getWorker().sendMessage(EVT_SEND_RAR); break; }
               case 99: { break; }
               default:
               {
                  std::cout << "Unrecognized menu option" << std::endl;
               }
            }

            if ( choice == 99 )
               break;
         }
      }
      else
      {
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }      
   }

   m_app.setShutdownEvent();

   return 0;
}

Void MenuThread::displayMenu()
{
   if (m_app.getRole() == EpcApplication::Role::client)
   {
      std::cout << std::endl << std::endl
         << "**********  Client Menu  **********" << std::endl
         << "  1) Send Diameter-EAP-Request (DER)" << std::endl
         << "  2) Send AA-Request (AAR)" << std::endl
         << "  3) Send Session-Termination-Request (STR)" << std::endl
         << " 99) Quit" << std::endl
         ;
   }
   else
   {
      std::cout << std::endl << std::endl
         << "**********  Server Menu  **********" << std::endl
         << "  1) Send Abort-Session-Request (ASR)" << std::endl
         << "  2) Send Re-Auth-Request (RAR)" << std::endl
         << " 99) Quit" << std::endl
         ;
   }
}
