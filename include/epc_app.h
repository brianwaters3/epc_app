#ifndef __EPC_APP_H
#define __EPC_APP_H

#include "epctools.h"
#include "efd.h"
#include "estats.h"
#include "esynch.h"
#include "ethread.h"

#include "swm.h"
#include "swm_impl.h"

#define LOG_SYSTEM 1
#define LOG_AUDIT 2
#define LOG_STATS 3
#define LOG_SWM 4
#define LOG_DIAMETER 5

class EpcApplication;

const UInt EVT_SEND_DER = EM_USER + 1;
const UInt EVT_SEND_AAR = EM_USER + 2;
const UInt EVT_SEND_STR = EM_USER + 3;
const UInt EVT_SEND_ASR = EM_USER + 4;
const UInt EVT_SEND_RAR = EM_USER + 5;
const UInt EVT_RCVD_DER = EM_USER + 6;
const UInt EVT_RCVD_AAR = EM_USER + 7;
const UInt EVT_RCVD_STR = EM_USER + 8;
const UInt EVT_RCVD_ASR = EM_USER + 9;
const UInt EVT_RCVD_RAR = EM_USER + 10;
const UInt EVT_RCVD_DEA = EM_USER + 11;
const UInt EVT_RCVD_AAA = EM_USER + 12;
const UInt EVT_RCVD_STA = EM_USER + 13;
const UInt EVT_RCVD_ASA = EM_USER + 14;
const UInt EVT_RCVD_RAA = EM_USER + 15;

class EpcWorker : public EThreadPrivate
{
public:
   EpcWorker(EpcApplication &app);

   Void onInit();
   Void onQuit();

   Void onSendDER(EThreadMessage &msg);
   Void onSendAAR(EThreadMessage &msg);
   Void onSendSTR(EThreadMessage &msg);
   Void onSendASR(EThreadMessage &msg);
   Void onSendRAR(EThreadMessage &msg);
   Void onRcvdDER(EThreadMessage &msg);
   Void onRcvdAAR(EThreadMessage &msg);
   Void onRcvdSTR(EThreadMessage &msg);
   Void onRcvdASR(EThreadMessage &msg);
   Void onRcvdRAR(EThreadMessage &msg);
   Void onRcvdDEA(EThreadMessage &msg);
   Void onRcvdAAA(EThreadMessage &msg);
   Void onRcvdSTA(EThreadMessage &msg);
   Void onRcvdASA(EThreadMessage &msg);
   Void onRcvdRAA(EThreadMessage &msg);

   DECLARE_MESSAGE_MAP()

private:
   EpcApplication &m_app;
};

class MenuThread : public EThreadBasic
{
public:
   MenuThread( EpcApplication &app);

   Void shutdown();
   Dword threadProc(pVoid arg);

private:
   Void displayMenu();

   EpcApplication &m_app;
   Bool m_shutdown;
};

class EpcApplication
{
public:
   enum class Role
   {
      client,
      server
   };

   EpcApplication()
      : m_worker(NULL)
   {
   }

   ~EpcApplication()
   {
   }

   Void startup(EGetOpt &opt);
   Void shutdown();

   Void setShutdownEvent() { m_shutdown.set(); m_menu->shutdown(); }
   Void waitForShutdown() { m_shutdown.wait(); }

   Role getRole() { return m_role; }

   EpcWorker &getWorker() { return *m_worker; }
   swm::Application &getSwmApplication() { return *m_swm; }
   swm::Dictionary &getSwmDictionary() { return m_swm->getDict(); }

private:
   FDEngine m_diameter;
   EEvent m_shutdown;
   Role m_role;
   EpcWorker *m_worker;
   MenuThread *m_menu;

   swm::Application *m_swm;
};

#endif // #ifndef __EPC_APP_H