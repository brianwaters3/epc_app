#ifndef __SWM_IMPL_H
#define __SWM_IMPL_H

#include "swm.h"

class EpcApplication;

namespace swm {

// Member functions that customize the individual application
class Application : public ApplicationBase
{
    friend DERreq;
    friend AARreq;
    friend STRreq;
    friend ASRreq;
    friend RARreq;

public:
    Application(EpcApplication& epcapp);
    ~Application();

    DERcmd &getDERcmd() { return m_cmd_der; }
    AARcmd &getAARcmd() { return m_cmd_aar; }
    STRcmd &getSTRcmd() { return m_cmd_str; }
    ASRcmd &getASRcmd() { return m_cmd_asr; }
    RARcmd &getRARcmd() { return m_cmd_rar; }

    // Parameters for sendXXXreq, if present below, may be changed
    // based upon processing needs
    Bool sendDERreq(FDPeer &peer);
    Bool sendAARreq(FDPeer &peer);
    Bool sendSTRreq(FDPeer &peer);
    Bool sendASRreq(FDPeer &peer);
    Bool sendRARreq(FDPeer &peer);

    Void registerHandlers(Bool isClient);

    const EString &getDestinationHost() { return m_peer->getDestinationHost(); }
    const EString &getDestinationRealm() { return m_peer->getDestinationRealm(); }

    FDPeer *setPeer(FDPeer *peer) { return m_peer = peer; }
    FDPeer &getPeer() { return *m_peer; }

    EpcApplication &getEpcApp() { return m_epcapp; }

private:
    EpcApplication &m_epcapp;
    Bool m_isclient;
    FDPeer *m_peer;

    DERcmd m_cmd_der;
    AARcmd m_cmd_aar;
    STRcmd m_cmd_str;
    ASRcmd m_cmd_asr;
    RARcmd m_cmd_rar;

    // the parameters for createXXXreq, if present below, may be
    // changed based processing needs
    DERreq *createDERreq(FDPeer &peer);
    AARreq *createAARreq(FDPeer &peer);
    STRreq *createSTRreq(FDPeer &peer);
    ASRreq *createASRreq(FDPeer &peer);
    RARreq *createRARreq(FDPeer &peer);
};

}

#endif // __SWM_IMPL_H
