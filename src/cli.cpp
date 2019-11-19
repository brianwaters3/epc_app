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

#include "estats.h"
#include "etime.h"

#include "cli.h"

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

CliStatsGet::CliStatsGet(ELogger &audit)
   : EManagementHandler( EManagementHandler::HttpMethod::httpGet, "/statistics", audit )
{
}

Void CliStatsGet::process(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter &response)
{
   RAPIDJSON_NAMESPACE::Document doc;
   RAPIDJSON_NAMESPACE::Document::AllocatorType &allocator( doc.GetAllocator() );

   doc.SetObject();

   doc.AddMember( "reporttime", RAPIDJSON_NAMESPACE::Value().SetString(ETime::Now().Format("%Y-%m-%dT%H:%M:%S.%0",True),allocator), allocator );

   RAPIDJSON_NAMESPACE::Value interfaces(RAPIDJSON_NAMESPACE::kArrayType);

   for (auto &ifc : EStatistics::getInterfaces())
   {
      RAPIDJSON_NAMESPACE::Value interface(RAPIDJSON_NAMESPACE::kObjectType);

      interface.AddMember( "name", RAPIDJSON_NAMESPACE::Value().SetString(ifc.second.getName(),allocator), allocator );
      switch (ifc.second.getProtocol())
      {
         case EStatistics::ProtocolType::diameter: { interface.AddMember ("protocol", RAPIDJSON_NAMESPACE::Value().SetString("diameter"), allocator); break; }
         case EStatistics::ProtocolType::gtpv2c:   { interface.AddMember ("protocol", RAPIDJSON_NAMESPACE::Value().SetString("gtpv2c"), allocator); break; }
         case EStatistics::ProtocolType::gtpv1u:   { interface.AddMember ("protocol", RAPIDJSON_NAMESPACE::Value().SetString("gtpv1u"), allocator); break; }
         case EStatistics::ProtocolType::pfcp:     { interface.AddMember ("protocol", RAPIDJSON_NAMESPACE::Value().SetString("pfcp"), allocator); break; }
      }

      RAPIDJSON_NAMESPACE::Value peers(RAPIDJSON_NAMESPACE::kArrayType);
      for (auto &p : ifc.second.getPeers() )
      {
         RAPIDJSON_NAMESPACE::Value peer(RAPIDJSON_NAMESPACE::kObjectType);

         RAPIDJSON_NAMESPACE::Value address(RAPIDJSON_NAMESPACE::kObjectType);
         switch (ifc.second.getProtocol())
         {
            case EStatistics::ProtocolType::diameter: { address.AddMember ("diameterid", RAPIDJSON_NAMESPACE::Value().SetString(p.second.getName(),allocator), allocator); break; }
            case EStatistics::ProtocolType::gtpv2c:   { address.AddMember ("ipv4", RAPIDJSON_NAMESPACE::Value().SetString(p.second.getName(),allocator), allocator); break; }
            case EStatistics::ProtocolType::gtpv1u:   { address.AddMember ("ipv4", RAPIDJSON_NAMESPACE::Value().SetString(p.second.getName(),allocator), allocator); break; }
            case EStatistics::ProtocolType::pfcp:     { address.AddMember ("ipv4", RAPIDJSON_NAMESPACE::Value().SetString(p.second.getName(),allocator), allocator); break; }
         }
         peer.AddMember( "address", address, allocator );

         peer.AddMember( "lastactivity", RAPIDJSON_NAMESPACE::Value().SetString(p.second.getLastActivity().Format("%Y-%m-%dT%H:%M:%S.%0",True),allocator), allocator );

         RAPIDJSON_NAMESPACE::Value messages(RAPIDJSON_NAMESPACE::kArrayType);

         for ( auto &m : p.second.getMessageStats() )
         {
            Bool nonzero = False;

            RAPIDJSON_NAMESPACE::Value msgstats(RAPIDJSON_NAMESPACE::kObjectType);

            msgstats.AddMember( "type", RAPIDJSON_NAMESPACE::Value().SetString(m.second.getName().c_str(),allocator), allocator);

            if (m.second.getRequestSentErrors())            { msgstats.AddMember("rqst_send_errors", m.second.getRequestSentErrors(), allocator); nonzero = True; }
            if (m.second.getRequestReceivedErrors())        { msgstats.AddMember("rqst_rcvd_errors", m.second.getRequestReceivedErrors(), allocator); nonzero = True; }
            if (m.second.getRequestSentOk())                { msgstats.AddMember("rqst_send_ok", m.second.getRequestSentOk(), allocator); nonzero = True; }
            if (m.second.getRequestReceivedOk())            { msgstats.AddMember("rqst_rcvd_ok", m.second.getRequestReceivedOk(), allocator); nonzero = True; }
            if (m.second.getResponseSentErrors())           { msgstats.AddMember("resp_send_errors", m.second.getResponseSentErrors(), allocator); nonzero = True; }
            if (m.second.getResponseReceivedErrors())       { msgstats.AddMember("resp_rcvd_errors", m.second.getResponseReceivedErrors(), allocator); nonzero = True; }
            if (m.second.getResponseSentOkAccepted())       { msgstats.AddMember("resp_send_ok_accept", m.second.getResponseSentOkAccepted(), allocator); nonzero = True; }
            if (m.second.getResponseSentOkRejected())       { msgstats.AddMember("resp_send_ok_reject", m.second.getResponseSentOkRejected(), allocator); nonzero = True; }
            if (m.second.getResponseReceivedOkAccepted())   { msgstats.AddMember("resp_rcvd_ok_accept", m.second.getResponseReceivedOkAccepted(), allocator); nonzero = True; }
            if (m.second.getResponseReceivedOkRejected())   { msgstats.AddMember("resp_rcvd_ok_reject", m.second.getResponseReceivedOkRejected(), allocator); nonzero = True; }

            if (nonzero)
               messages.PushBack( msgstats, allocator );
         }

         peer.AddMember( "messages", messages, allocator );
         peers.PushBack( peer, allocator );
      }

      interface.AddMember( "peers", peers, allocator );
      interfaces.PushBack( interface, allocator );
   }

   doc.AddMember( "interfaces", interfaces, allocator );

   RAPIDJSON_NAMESPACE::StringBuffer buf;
   RAPIDJSON_NAMESPACE::Writer<RAPIDJSON_NAMESPACE::StringBuffer> writer( buf );
   doc.Accept( writer );

   response.send( Pistache::Http::Code::Ok, buf.GetString() );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

CliStatsResetPut::CliStatsResetPut(ELogger &audit)
   : EManagementHandler( EManagementHandler::HttpMethod::httpPut, "/statistics", audit )
{
}

Void CliStatsResetPut::process(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter &response)
{
   EStatistics::reset();
   response.send( Pistache::Http::Code::Ok );
}
