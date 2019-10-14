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

#include <string>
#include <iostream>
#include <sstream>

#include "epctools.h"
#include "epc_app.h"
#include "swm_impl.h"

namespace swm {

// Member functions that customize the individual application
Application::Application(EpcApplication& epcapp)
    : ApplicationBase()
    , m_cmd_der( *this )
    , m_cmd_aar( *this )
    , m_cmd_str( *this )
    , m_cmd_asr( *this )
    , m_cmd_rar( *this )
    , m_epcapp( epcapp )
{
    //registerHandlers();
}

Application::~Application()
{
   if (m_peer)
   {
      delete m_peer;
      m_peer = NULL;
   }
}

Void Application::registerHandlers(Bool isClient)
{
    m_isclient = isClient;

    // Remove the comments for any Command this application should
    // listen for (receive).
    if (m_isclient)
    {
        ELogger::log(LOG_SWM).info("Registering SWm command handlers for Client (ePDG)");
        ELogger::log(LOG_SWM).info("Registering ASR command handler");
        registerHandler( m_cmd_asr );
        ELogger::log(LOG_SWM).info("Registering RAR command handler");
        registerHandler( m_cmd_rar );
    }
    else
    {
        ELogger::log(LOG_SWM).info("Registering SWm command handlers for Server (AAA)");
        ELogger::log(LOG_SWM).info("Registering DER command handler");
        registerHandler( m_cmd_der );
        ELogger::log(LOG_SWM).info("Registering AAR command handler");
        registerHandler( m_cmd_aar );
        ELogger::log(LOG_SWM).info("Registering STR command handler");
        registerHandler( m_cmd_str );
    }
    
    //std::cout << "Registering DER command handler" << std::endl;
    //registerHandler( m_cmd_der );
    //std::cout << "Registering AAR command handler" << std::endl;
    //registerHandler( m_cmd_aar );
    //std::cout << "Registering STR command handler" << std::endl;
    //registerHandler( m_cmd_str );
    //std::cout << "Registering ASR command handler" << std::endl;
    //registerHandler( m_cmd_asr );
    //std::cout << "Registering RAR command handler" << std::endl;
    //registerHandler( m_cmd_rar );
}

// DER Request (req) Command member functions


// Sends a DER Request to the corresponding Peer
Bool Application::sendDERreq(FDPeer &peer)
{
    //TODO - This code may be modified based on specific
    //         processing needs to send the DER Command
    DERreq *s = createDERreq( peer );

    try
    {
        if ( s )
        {
            s->dump();
            s->send();
        }
    }
    catch ( FDException &ex )
    {
        ELogger::log(LOG_SWM).minor("Exception while sending DER - {}", ex.what());
        delete s;
        s = NULL;
    }

    // DO NOT free the newly created DERreq object!!
    // It will be deleted by the framework after the
    // answer is received and processed.
    return s != NULL;
}

// A factory for DER reuqests
DERreq *Application::createDERreq(FDPeer &peer)
{
    //  creates the DERreq object
    DERreq *s = new DERreq( *this );

    // setting preserve to TRUE prevents the Answer object recieved in the
    // processAnswer() method from being destroyed after processAnswer() returns.
    // This would be required if the answer object were to be processed by
    // another thread.
    s->setPreserveAnswer( True );

    //TODO - Code must be added to correctly
    //         populate the DER request object
    s->add( getDict().avpSessionId(), s->getSessionId() );
    s->add( getDict().avpAuthApplicationId(), getDict().app().getId() );
    s->addOrigin();
    s->add( getDict().avpDestinationHost(), getDestinationHost() );
    s->add( getDict().avpDestinationRealm(), getDestinationRealm() );
    s->add( getDict().avpAuthRequestType(), 3 /* AUTHORIZE_AUTHENTICATE */ );
    s->add( getDict().avpEapPayload(), "I don't know what needs to be in this AVP, but it is required" );
    s->add( getDict().avpUserName(), "realm-H!username@realm-X" );

    /* and whatever other AVP's need to be added */

    return s;
}

// A handler for Answers corresponding to this specific Request
Void DERreq::processAnswer( FDMessageAnswer &ans )
{
   m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_DEA, &ans );
}

// DER Command (cmd) member function

// Function invoked when a DER Command is received
Int DERcmd::process( FDMessageRequest *req )
{
// TODO - This code must be implemented IF the application
// receives the DER command.
    m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_DER, req );
    return 0;
}
 
// AAR Request (req) Command member functions


// Sends a AAR Request to the corresponding Peer
Bool Application::sendAARreq(FDPeer &peer)
{
    //TODO - This code may be modified based on specific
    //         processing needs to send the AAR Command
    AARreq *s = createAARreq( peer );

    try
    {
         if ( s )
         {
              s->send();
         }
    }
    catch ( FDException &ex )
    {
         std::cout << EUtility::currentTime() << " - EXCEPTION - " << ex.what() << std::endl;
         delete s;
         s = NULL;
    }

    // DO NOT free the newly created AARreq object!!
    // It will be deleted by the framework after the
    // answer is received and processed.
    return s != NULL;
}

// A factory for AAR reuqests
AARreq *Application::createAARreq(FDPeer &peer)
{
    //  creates the AARreq object
    AARreq *s = new AARreq( *this );

    //TODO - Code must be added to correctly
    //         populate the AAR request object

    // return the newly created request object
    return s;
}

// A handler for Answers corresponding to this specific Request
Void AARreq::processAnswer( FDMessageAnswer &ans )
{
// TODO - This code must be implemented IF the application
// receives Answers for this command, i.e. it sends the
// AAR Command
   m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_AAA, &ans );
}

// AAR Command (cmd) member function

// Function invoked when a AAR Command is received
Int AARcmd::process( FDMessageRequest *req )
{
// TODO - This code must be implemented IF the application
// receives the AAR command.
    m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_AAR, req );
    return 0;
}
 
// STR Request (req) Command member functions


// Sends a STR Request to the corresponding Peer
Bool Application::sendSTRreq(FDPeer &peer)
{
    //TODO - This code may be modified based on specific
    //         processing needs to send the STR Command
    STRreq *s = createSTRreq( peer );

    try
    {
         if ( s )
         {
              s->send();
         }
    }
    catch ( FDException &ex )
    {
         std::cout << EUtility::currentTime() << " - EXCEPTION - " << ex.what() << std::endl;
         delete s;
         s = NULL;
    }

    // DO NOT free the newly created STRreq object!!
    // It will be deleted by the framework after the
    // answer is received and processed.
    return s != NULL;
}

// A factory for STR reuqests
STRreq *Application::createSTRreq(FDPeer &peer)
{
    //  creates the STRreq object
    STRreq *s = new STRreq( *this );

    //TODO - Code must be added to correctly
    //         populate the STR request object

    // return the newly created request object
    return s;
}

// A handler for Answers corresponding to this specific Request
Void STRreq::processAnswer( FDMessageAnswer &ans )
{
// TODO - This code must be implemented IF the application
// receives Answers for this command, i.e. it sends the
// STR Command
   m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_STA, &ans );
}

// STR Command (cmd) member function

// Function invoked when a STR Command is received
Int STRcmd::process( FDMessageRequest *req )
{
// TODO - This code must be implemented IF the application
// receives the STR command.
    m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_STR, req );
    return 0;
}
 
// ASR Request (req) Command member functions


// Sends a ASR Request to the corresponding Peer
Bool Application::sendASRreq(FDPeer &peer)
{
    //TODO - This code may be modified based on specific
    //         processing needs to send the ASR Command
    ASRreq *s = createASRreq( peer );

    try
    {
         if ( s )
         {
              s->send();
         }
    }
    catch ( FDException &ex )
    {
         std::cout << EUtility::currentTime() << " - EXCEPTION - " << ex.what() << std::endl;
         delete s;
         s = NULL;
    }

    // DO NOT free the newly created ASRreq object!!
    // It will be deleted by the framework after the
    // answer is received and processed.
    return s != NULL;
}

// A factory for ASR reuqests
ASRreq *Application::createASRreq(FDPeer &peer)
{
    //  creates the ASRreq object
    ASRreq *s = new ASRreq( *this );

    //TODO - Code must be added to correctly
    //         populate the ASR request object

    // return the newly created request object
    return s;
}

// A handler for Answers corresponding to this specific Request
Void ASRreq::processAnswer( FDMessageAnswer &ans )
{
// TODO - This code must be implemented IF the application
// receives Answers for this command, i.e. it sends the
// ASR Command
   m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_ASA, &ans );
}

// ASR Command (cmd) member function

// Function invoked when a ASR Command is received
Int ASRcmd::process( FDMessageRequest *req )
{
// TODO - This code must be implemented IF the application
// receives the ASR command.
    m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_ASR, req );
    return 0;
}
 
// RAR Request (req) Command member functions


// Sends a RAR Request to the corresponding Peer
Bool Application::sendRARreq(FDPeer &peer)
{
    //TODO - This code may be modified based on specific
    //         processing needs to send the RAR Command
    RARreq *s = createRARreq( peer );

    try
    {
         if ( s )
         {
              s->send();
         }
    }
    catch ( FDException &ex )
    {
         std::cout << EUtility::currentTime() << " - EXCEPTION - " << ex.what() << std::endl;
         delete s;
         s = NULL;
    }

    // DO NOT free the newly created RARreq object!!
    // It will be deleted by the framework after the
    // answer is received and processed.
    return s != NULL;
}

// A factory for RAR reuqests
RARreq *Application::createRARreq(FDPeer &peer)
{
    //  creates the RARreq object
    RARreq *s = new RARreq( *this );

    //TODO - Code must be added to correctly
    //         populate the RAR request object

    // return the newly created request object
    return s;
}

// A handler for Answers corresponding to this specific Request
Void RARreq::processAnswer( FDMessageAnswer &ans )
{
// TODO - This code must be implemented IF the application
// receives Answers for this command, i.e. it sends the
// RAR Command
   m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_RAA, &ans );
}

// RAR Command (cmd) member function

// Function invoked when a RAR Command is received
Int RARcmd::process( FDMessageRequest *req )
{
// TODO - This code must be implemented IF the application
// receives the RAR command.
    m_app.getEpcApp().getWorker().sendMessage( EVT_RCVD_RAR, req );
    return 0;
}
 

}
