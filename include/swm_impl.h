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
