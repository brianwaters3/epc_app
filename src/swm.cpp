
#include <string>
#include <iostream>
#include <sstream>

#include "swm.h"
#include "swm_impl.h"

namespace swm {

Dictionary::Dictionary()
    : m_app( "SWm"),
    m_cmd_der( "Diameter-EAP-Request" ),
    m_cmd_dea( "Diameter-EAP-Answer" ),
    m_cmd_aar( "AA-Request" ),
    m_cmd_aaa( "AA-Answer" ),
    m_cmd_str( "Session-Termination-Request" ),
    m_cmd_sta( "Session-Termination-Answer" ),
    m_cmd_asr( "Abort-Session-Request" ),
    m_cmd_asa( "Abort-Session-Answer" ),
    m_cmd_rar( "Re-Auth-Request" ),
    m_cmd_raa( "Re-Auth-Answer" ),
    m_vnd_Etsi( "ETSI" ),
    m_vnd_3gpp( "3GPP" ),
    m_avp_subscription_id_type( "Subscription-Id-Type" ),
    m_avp_pre_emption_capability( "Pre-emption-Capability", m_vnd_3gpp.getId() ),
    m_avp_feature_list_id( "Feature-List-ID", m_vnd_3gpp.getId() ),
    m_avp_ambr( "AMBR", m_vnd_3gpp.getId() ),
    m_avp_mip6_home_link_prefix( "MIP6-Home-Link-Prefix" ),
    m_avp_termination_cause( "Termination-Cause" ),
    m_avp_core_network_restrictions( "Core-Network-Restrictions", m_vnd_3gpp.getId() ),
    m_avp_oc_sequence_number( "OC-Sequence-Number" ),
    m_avp_tracking_area_identity( "Tracking-Area-Identity", m_vnd_3gpp.getId() ),
    m_avp_load_value( "Load-Value" ),
    m_avp_feature_list( "Feature-List", m_vnd_3gpp.getId() ),
    m_avp_omc_id( "OMC-Id", m_vnd_3gpp.getId() ),
    m_avp_oc_report_type( "OC-Report-Type" ),
    m_avp_ue_usage_type( "UE-Usage-Type", m_vnd_3gpp.getId() ),
    m_avp_load_type( "Load-Type" ),
    m_avp_oc_feature_vector( "OC-Feature-Vector" ),
    m_avp_aaa_failure_indication( "AAA-Failure-Indication", m_vnd_3gpp.getId() ),
    m_avp_list_of_measurements( "List-Of-Measurements", m_vnd_3gpp.getId() ),
    m_avp_mdt_configuration( "MDT-Configuration", m_vnd_3gpp.getId() ),
    m_avp_drmp( "DRMP" ),
    m_avp_preferred_data_mode( "Preferred-Data-Mode", m_vnd_3gpp.getId() ),
    m_avp_aar_flags( "AAR-Flags", m_vnd_3gpp.getId() ),
    m_avp_priority_level( "Priority-Level", m_vnd_3gpp.getId() ),
    m_avp_pre_emption_vulnerability( "Pre-emption-Vulnerability", m_vnd_3gpp.getId() ),
    m_avp_qos_class_identifier( "QoS-Class-Identifier", m_vnd_3gpp.getId() ),
    m_avp_area_scope( "Area-Scope", m_vnd_3gpp.getId() ),
    m_avp_trace_ne_type_list( "Trace-NE-Type-List", m_vnd_3gpp.getId() ),
    m_avp_destination_host( "Destination-Host" ),
    m_avp_qos_capability( "QoS-Capability" ),
    m_avp_location_area_identity( "Location-Area-Identity", m_vnd_3gpp.getId() ),
    m_avp_logging_interval( "Logging-Interval", m_vnd_3gpp.getId() ),
    m_avp_ue_local_ip_address( "UE-Local-IP-Address", m_vnd_3gpp.getId() ),
    m_avp_mbsfn_area( "MBSFN-Area", m_vnd_3gpp.getId() ),
    m_avp_job_type( "Job-Type", m_vnd_3gpp.getId() ),
    m_avp_mip6_feature_vector( "MIP6-Feature-Vector" ),
    m_avp_wlan_offloadability( "WLAN-offloadability", m_vnd_3gpp.getId() ),
    m_avp_mip_home_agent_host( "MIP-Home-Agent-Host" ),
    m_avp_pdn_type( "PDN-Type", m_vnd_3gpp.getId() ),
    m_avp_3gpp_charging_characteristics( "3GPP-Charging-Characteristics", m_vnd_3gpp.getId() ),
    m_avp_origin_realm( "Origin-Realm" ),
    m_avp_origin_host( "Origin-Host" ),
    m_avp_event_threshold_rsrq( "Event-Threshold-RSRQ", m_vnd_3gpp.getId() ),
    m_avp_vplmn_dynamic_address_allowed( "VPLMN-Dynamic-Address-Allowed", m_vnd_3gpp.getId() ),
    m_avp_apn_configuration( "APN-Configuration", m_vnd_3gpp.getId() ),
    m_avp_subscription_id_data( "Subscription-Id-Data" ),
    m_avp_mbsfn_area_id( "MBSFN-Area-ID", m_vnd_3gpp.getId() ),
    m_avp_trace_collection_entity( "Trace-Collection-Entity", m_vnd_3gpp.getId() ),
    m_avp_wlan_offloadability_eutran( "WLAN-offloadability-EUTRAN", m_vnd_3gpp.getId() ),
    m_avp_qos_profile_template( "QoS-Profile-Template" ),
    m_avp_scef_id( "SCEF-ID", m_vnd_3gpp.getId() ),
    m_avp_trace_event_list( "Trace-Event-List", m_vnd_3gpp.getId() ),
    m_avp_ssid( "SSID", m_vnd_3gpp.getId() ),
    m_avp_mip6_agent_info( "MIP6-Agent-Info" ),
    m_avp_logging_duration( "Logging-Duration", m_vnd_3gpp.getId() ),
    m_avp_collection_period_rrm_umts( "Collection-Period-RRM-UMTS", m_vnd_3gpp.getId() ),
    m_avp_non_ip_pdn_type_indicator( "Non-IP-PDN-Type-Indicator", m_vnd_3gpp.getId() ),
    m_avp_positioning_method( "Positioning-Method", m_vnd_3gpp.getId() ),
    m_avp_oc_olr( "OC-OLR" ),
    m_avp_trace_data( "Trace-Data", m_vnd_3gpp.getId() ),
    m_avp_sourceid( "SourceID" ),
    m_avp_specific_apn_info( "Specific-APN-Info", m_vnd_3gpp.getId() ),
    m_avp_oc_reduction_percentage( "OC-Reduction-Percentage" ),
    m_avp_report_interval( "Report-Interval", m_vnd_3gpp.getId() ),
    m_avp_eps_subscribed_qos_profile( "EPS-Subscribed-QoS-Profile", m_vnd_3gpp.getId() ),
    m_avp_apn_oi_replacement( "APN-OI-Replacement", m_vnd_3gpp.getId() ),
    m_avp_supported_features( "Supported-Features", m_vnd_3gpp.getId() ),
    m_avp_event_threshold_event_1i( "Event-Threshold-Event-1I", m_vnd_3gpp.getId() ),
    m_avp_rat_type( "RAT-Type", m_vnd_3gpp.getId() ),
    m_avp_event_threshold_event_1f( "Event-Threshold-Event-1F", m_vnd_3gpp.getId() ),
    m_avp_rds_indicator( "RDS-Indicator", m_vnd_3gpp.getId() ),
    m_avp_allocation_retention_priority( "Allocation-Retention-Priority", m_vnd_3gpp.getId() ),
    m_avp_cell_global_identity( "Cell-Global-Identity", m_vnd_3gpp.getId() ),
    m_avp_oc_validity_duration( "OC-Validity-Duration" ),
    m_avp_service_selection( "Service-Selection" ),
    m_avp_access_network_info( "Access-Network-Info", m_vnd_3gpp.getId() ),
    m_avp_eap_payload( "EAP-Payload" ),
    m_avp_logical_access_id( "Logical-Access-Id", m_vnd_Etsi.getId() ),
    m_avp_extended_max_requested_bw_dl( "Extended-Max-Requested-BW-DL", m_vnd_3gpp.getId() ),
    m_avp_measurement_period_lte( "Measurement-Period-LTE", m_vnd_3gpp.getId() ),
    m_avp_result_code( "Result-Code" ),
    m_avp_auth_request_type( "Auth-Request-Type" ),
    m_avp_qos_profile_id( "QoS-Profile-Id" ),
    m_avp_wlan_offloadability_utran( "WLAN-offloadability-UTRAN", m_vnd_3gpp.getId() ),
    m_avp_operator_name( "Operator-Name" ),
    m_avp_max_requested_bandwidth_dl( "Max-Requested-Bandwidth-DL", m_vnd_3gpp.getId() ),
    m_avp_trace_interface_list( "Trace-Interface-List", m_vnd_3gpp.getId() ),
    m_avp_pdn_connection_continuity( "PDN-Connection-Continuity", m_vnd_3gpp.getId() ),
    m_avp_interworking_5gs_indicator( "Interworking-5GS-Indicator", m_vnd_3gpp.getId() ),
    m_avp_load( "Load" ),
    m_avp_context_identifier( "Context-Identifier", m_vnd_3gpp.getId() ),
    m_avp_e_utran_cell_global_identity( "E-UTRAN-Cell-Global-Identity", m_vnd_3gpp.getId() ),
    m_avp_oc_supported_features( "OC-Supported-Features" ),
    m_avp_event_threshold_rsrp( "Event-Threshold-RSRP", m_vnd_3gpp.getId() ),
    m_avp_terminal_information( "Terminal-Information", m_vnd_3gpp.getId() ),
    m_avp_location_information( "Location-Information" ),
    m_avp_collection_period_rrm_lte( "Collection-Period-RRM-LTE", m_vnd_3gpp.getId() ),
    m_avp_auth_application_id( "Auth-Application-Id" ),
    m_avp_lipa_permission( "LIPA-Permission", m_vnd_3gpp.getId() ),
    m_avp_extended_max_requested_bw_ul( "Extended-Max-Requested-BW-UL", m_vnd_3gpp.getId() ),
    m_avp_emergency_services( "Emergency-Services", m_vnd_3gpp.getId() ),
    m_avp_visited_network_identifier( "Visited-Network-Identifier", m_vnd_3gpp.getId() ),
    m_avp_subscription_id( "Subscription-Id" ),
    m_avp_restoration_priority( "Restoration-Priority", m_vnd_3gpp.getId() ),
    m_avp_pdn_gw_allocation_type( "PDN-GW-Allocation-Type", m_vnd_3gpp.getId() ),
    m_avp_re_auth_request_type( "Re-Auth-Request-Type" ),
    m_avp_mdt_allowed_plmn_id( "MDT-Allowed-PLMN-Id", m_vnd_3gpp.getId() ),
    m_avp_reporting_trigger( "Reporting-Trigger", m_vnd_3gpp.getId() ),
    m_avp_routing_area_identity( "Routing-Area-Identity", m_vnd_3gpp.getId() ),
    m_avp_eap_master_session_key( "EAP-Master-Session-Key" ),
    m_avp_trace_reference( "Trace-Reference", m_vnd_3gpp.getId() ),
    m_avp_mobile_node_identifier( "Mobile-Node-Identifier" ),
    m_avp_carrier_frequency( "Carrier-Frequency", m_vnd_3gpp.getId() ),
    m_avp_measurement_quantity( "Measurement-Quantity", m_vnd_3gpp.getId() ),
    m_avp_served_party_ip_address( "Served-Party-IP-Address", m_vnd_3gpp.getId() ),
    m_avp_session_timeout( "Session-Timeout" ),
    m_avp_trace_depth( "Trace-Depth", m_vnd_3gpp.getId() ),
    m_avp_software_version( "Software-Version", m_vnd_3gpp.getId() ),
    m_avp_sipto_local_network_permission( "SIPTO-Local-Network-Permission", m_vnd_3gpp.getId() ),
    m_avp_vendor_id( "Vendor-Id" ),
    m_avp_location_data( "Location-Data" ),
    m_avp_max_requested_bandwidth_ul( "Max-Requested-Bandwidth-UL", m_vnd_3gpp.getId() ),
    m_avp_imei( "IMEI", m_vnd_3gpp.getId() ),
    m_avp_non_ip_data_delivery_mechanism( "Non-IP-Data-Delivery-Mechanism", m_vnd_3gpp.getId() ),
    m_avp_auth_session_state( "Auth-Session-State" ),
    m_avp_redirect_host( "Redirect-Host" ),
    m_avp_destination_realm( "Destination-Realm" ),
    m_avp_session_id( "Session-Id" ),
    m_avp_user_name( "User-Name" ),
    m_avp_scef_realm( "SCEF-Realm", m_vnd_3gpp.getId() ),
    m_avp_bssid( "BSSID", m_vnd_3gpp.getId() ),
    m_avp_sipto_permission( "SIPTO-Permission", m_vnd_3gpp.getId() ),
    m_avp_emergency_info( "Emergency-Info", m_vnd_3gpp.getId() ),
    m_avp_report_amount( "Report-Amount", m_vnd_3gpp.getId() ),
    m_avp_mip_home_agent_address( "MIP-Home-Agent-Address" ),
    m_avp_measurement_period_umts( "Measurement-Period-UMTS", m_vnd_3gpp.getId() ),
    m_avp_user_location_info_time( "User-Location-Info-Time", m_vnd_3gpp.getId() ),
    m_avp_trace_info( "Trace-Info", m_vnd_3gpp.getId() )
{
    std::cout << "Registering swm dictionary" << std::endl;
};

Dictionary::~Dictionary()
{
};

DERcmd::DERcmd( Application & app )
    : FDCommandRequest( app.getDict().cmdDER() ),
      m_app( app )
{
}

DERcmd::~DERcmd()
{
}

Dictionary &DERcmd::getDict()
{
   return m_app.getDict();
}

DERreq::DERreq( Application &app )
    : FDMessageRequest( &app.getDict().app(), &app.getDict().cmdDER() ),
      m_app(app)
{
}

DERreq::~DERreq()
{
}

Dictionary &DERreq::getDict()
{
   return m_app.getDict();
}

 
AARcmd::AARcmd( Application & app )
    : FDCommandRequest( app.getDict().cmdAAR() ),
      m_app( app )
{
}

AARcmd::~AARcmd()
{
}

Dictionary &AARcmd::getDict()
{
   return m_app.getDict();
}

AARreq::AARreq( Application &app )
    : FDMessageRequest( &app.getDict().app(), &app.getDict().cmdAAR() ),
      m_app(app)
{
}

AARreq::~AARreq()
{
}

Dictionary &AARreq::getDict()
{
   return m_app.getDict();
}

 
STRcmd::STRcmd( Application & app )
    : FDCommandRequest( app.getDict().cmdSTR() ),
      m_app( app )
{
}

STRcmd::~STRcmd()
{
}

Dictionary &STRcmd::getDict()
{
   return m_app.getDict();
}

STRreq::STRreq( Application &app )
    : FDMessageRequest( &app.getDict().app(), &app.getDict().cmdSTR() ),
      m_app(app)
{
}

STRreq::~STRreq()
{
}

Dictionary &STRreq::getDict()
{
   return m_app.getDict();
}

 
ASRcmd::ASRcmd( Application & app )
    : FDCommandRequest( app.getDict().cmdASR() ),
      m_app( app )
{
}

ASRcmd::~ASRcmd()
{
}

Dictionary &ASRcmd::getDict()
{
   return m_app.getDict();
}

ASRreq::ASRreq( Application &app )
    : FDMessageRequest( &app.getDict().app(), &app.getDict().cmdASR() ),
      m_app(app)
{
}

ASRreq::~ASRreq()
{
}

Dictionary &ASRreq::getDict()
{
   return m_app.getDict();
}

 
RARcmd::RARcmd( Application & app )
    : FDCommandRequest( app.getDict().cmdRAR() ),
      m_app( app )
{
}

RARcmd::~RARcmd()
{
}

Dictionary &RARcmd::getDict()
{
   return m_app.getDict();
}

RARreq::RARreq( Application &app )
    : FDMessageRequest( &app.getDict().app(), &app.getDict().cmdRAR() ),
      m_app(app)
{
}

RARreq::~RARreq()
{
}

Dictionary &RARreq::getDict()
{
   return m_app.getDict();
}

 
ApplicationBase::ApplicationBase()
{
    setDictionaryEntry( &m_dict.app() );

};

ApplicationBase::~ApplicationBase()
{
};



AmbrExtractor::AmbrExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpAmbr() ),
    max_requested_bandwidth_ul( *this, dict.avpMaxRequestedBandwidthUl() ),
    max_requested_bandwidth_dl( *this, dict.avpMaxRequestedBandwidthDl() ),
    extended_max_requested_bw_ul( *this, dict.avpExtendedMaxRequestedBwUl() ),
    extended_max_requested_bw_dl( *this, dict.avpExtendedMaxRequestedBwDl() )
{
    add( max_requested_bandwidth_ul );
    add( max_requested_bandwidth_dl );
    add( extended_max_requested_bw_ul );
    add( extended_max_requested_bw_dl );
}

AmbrExtractor::~AmbrExtractor()
{
}

AreaScopeExtractor::AreaScopeExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpAreaScope() ),
    cell_global_identity( *this, dict.avpCellGlobalIdentity() ),
    e_utran_cell_global_identity( *this, dict.avpEUtranCellGlobalIdentity() ),
    routing_area_identity( *this, dict.avpRoutingAreaIdentity() ),
    location_area_identity( *this, dict.avpLocationAreaIdentity() ),
    tracking_area_identity( *this, dict.avpTrackingAreaIdentity() )
{
    add( cell_global_identity );
    add( e_utran_cell_global_identity );
    add( routing_area_identity );
    add( location_area_identity );
    add( tracking_area_identity );
}

AreaScopeExtractor::~AreaScopeExtractor()
{
}

MbsfnAreaExtractor::MbsfnAreaExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpMbsfnArea() ),
    mbsfn_area_id( *this, dict.avpMbsfnAreaId() ),
    carrier_frequency( *this, dict.avpCarrierFrequency() )
{
    add( mbsfn_area_id );
    add( carrier_frequency );
}

MbsfnAreaExtractor::~MbsfnAreaExtractor()
{
}

MbsfnAreaExtractorList::MbsfnAreaExtractorList( FDExtractor &parent, Dictionary &dict )
    : FDExtractorList( parent, dict.avpMbsfnArea() ),
    m_dict( dict )
{
}

MbsfnAreaExtractorList::~MbsfnAreaExtractorList()
{
}

MdtConfigurationExtractor::MdtConfigurationExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpMdtConfiguration() ),
    job_type( *this, dict.avpJobType() ),
    area_scope( *this, dict ),
    list_of_measurements( *this, dict.avpListOfMeasurements() ),
    reporting_trigger( *this, dict.avpReportingTrigger() ),
    report_interval( *this, dict.avpReportInterval() ),
    report_amount( *this, dict.avpReportAmount() ),
    event_threshold_rsrp( *this, dict.avpEventThresholdRsrp() ),
    event_threshold_rsrq( *this, dict.avpEventThresholdRsrq() ),
    logging_interval( *this, dict.avpLoggingInterval() ),
    logging_duration( *this, dict.avpLoggingDuration() ),
    measurement_period_lte( *this, dict.avpMeasurementPeriodLte() ),
    measurement_period_umts( *this, dict.avpMeasurementPeriodUmts() ),
    collection_period_rrm_lte( *this, dict.avpCollectionPeriodRrmLte() ),
    collection_period_rrm_umts( *this, dict.avpCollectionPeriodRrmUmts() ),
    positioning_method( *this, dict.avpPositioningMethod() ),
    measurement_quantity( *this, dict.avpMeasurementQuantity() ),
    event_threshold_event_1f( *this, dict.avpEventThresholdEvent1f() ),
    event_threshold_event_1i( *this, dict.avpEventThresholdEvent1i() ),
    mdt_allowed_plmn_id( *this, dict.avpMdtAllowedPlmnId() ),
    mbsfn_area( *this, dict )
{
    add( job_type );
    add( area_scope );
    add( list_of_measurements );
    add( reporting_trigger );
    add( report_interval );
    add( report_amount );
    add( event_threshold_rsrp );
    add( event_threshold_rsrq );
    add( logging_interval );
    add( logging_duration );
    add( measurement_period_lte );
    add( measurement_period_umts );
    add( collection_period_rrm_lte );
    add( collection_period_rrm_umts );
    add( positioning_method );
    add( measurement_quantity );
    add( event_threshold_event_1f );
    add( event_threshold_event_1i );
    add( mdt_allowed_plmn_id );
    add( mbsfn_area );
}

MdtConfigurationExtractor::~MdtConfigurationExtractor()
{
}

QosProfileTemplateExtractor::QosProfileTemplateExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpQosProfileTemplate() ),
    vendor_id( *this, dict.avpVendorId() ),
    qos_profile_id( *this, dict.avpQosProfileId() )
{
    add( vendor_id );
    add( qos_profile_id );
}

QosProfileTemplateExtractor::~QosProfileTemplateExtractor()
{
}

QosProfileTemplateExtractorList::QosProfileTemplateExtractorList( FDExtractor &parent, Dictionary &dict )
    : FDExtractorList( parent, dict.avpQosProfileTemplate() ),
    m_dict( dict )
{
}

QosProfileTemplateExtractorList::~QosProfileTemplateExtractorList()
{
}

QosCapabilityExtractor::QosCapabilityExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpQosCapability() ),
    qos_profile_template( *this, dict )
{
    add( qos_profile_template );
}

QosCapabilityExtractor::~QosCapabilityExtractor()
{
}

WlanOffloadabilityExtractor::WlanOffloadabilityExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpWlanOffloadability() ),
    wlan_offloadability_eutran( *this, dict.avpWlanOffloadabilityEutran() ),
    wlan_offloadability_utran( *this, dict.avpWlanOffloadabilityUtran() )
{
    add( wlan_offloadability_eutran );
    add( wlan_offloadability_utran );
}

WlanOffloadabilityExtractor::~WlanOffloadabilityExtractor()
{
}

AllocationRetentionPriorityExtractor::AllocationRetentionPriorityExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpAllocationRetentionPriority() ),
    priority_level( *this, dict.avpPriorityLevel() ),
    pre_emption_capability( *this, dict.avpPreEmptionCapability() ),
    pre_emption_vulnerability( *this, dict.avpPreEmptionVulnerability() )
{
    add( priority_level );
    add( pre_emption_capability );
    add( pre_emption_vulnerability );
}

AllocationRetentionPriorityExtractor::~AllocationRetentionPriorityExtractor()
{
}

EpsSubscribedQosProfileExtractor::EpsSubscribedQosProfileExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpEpsSubscribedQosProfile() ),
    qos_class_identifier( *this, dict.avpQosClassIdentifier() ),
    allocation_retention_priority( *this, dict )
{
    add( qos_class_identifier );
    add( allocation_retention_priority );
}

EpsSubscribedQosProfileExtractor::~EpsSubscribedQosProfileExtractor()
{
}

Mip6AgentInfoExtractor::Mip6AgentInfoExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpMip6AgentInfo() ),
    mip_home_agent_address( *this, dict.avpMipHomeAgentAddress() ),
    mip_home_agent_host( *this, dict.avpMipHomeAgentHost() ),
    mip6_home_link_prefix( *this, dict.avpMip6HomeLinkPrefix() )
{
    add( mip_home_agent_address );
    add( mip_home_agent_host );
    add( mip6_home_link_prefix );
}

Mip6AgentInfoExtractor::~Mip6AgentInfoExtractor()
{
}

SpecificApnInfoExtractor::SpecificApnInfoExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpSpecificApnInfo() ),
    service_selection( *this, dict.avpServiceSelection() ),
    mip6_agent_info( *this, dict ),
    visited_network_identifier( *this, dict.avpVisitedNetworkIdentifier() )
{
    add( service_selection );
    add( mip6_agent_info );
    add( visited_network_identifier );
}

SpecificApnInfoExtractor::~SpecificApnInfoExtractor()
{
}

SpecificApnInfoExtractorList::SpecificApnInfoExtractorList( FDExtractor &parent, Dictionary &dict )
    : FDExtractorList( parent, dict.avpSpecificApnInfo() ),
    m_dict( dict )
{
}

SpecificApnInfoExtractorList::~SpecificApnInfoExtractorList()
{
}

ApnConfigurationExtractor::ApnConfigurationExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpApnConfiguration() ),
    context_identifier( *this, dict.avpContextIdentifier() ),
    served_party_ip_address( *this, dict.avpServedPartyIpAddress() ),
    pdn_type( *this, dict.avpPdnType() ),
    service_selection( *this, dict.avpServiceSelection() ),
    eps_subscribed_qos_profile( *this, dict ),
    vplmn_dynamic_address_allowed( *this, dict.avpVplmnDynamicAddressAllowed() ),
    mip6_agent_info( *this, dict ),
    visited_network_identifier( *this, dict.avpVisitedNetworkIdentifier() ),
    pdn_gw_allocation_type( *this, dict.avpPdnGwAllocationType() ),
    tgpp_charging_characteristics( *this, dict.avp3gppChargingCharacteristics() ),
    ambr( *this, dict ),
    specific_apn_info( *this, dict ),
    apn_oi_replacement( *this, dict.avpApnOiReplacement() ),
    sipto_permission( *this, dict.avpSiptoPermission() ),
    lipa_permission( *this, dict.avpLipaPermission() ),
    restoration_priority( *this, dict.avpRestorationPriority() ),
    sipto_local_network_permission( *this, dict.avpSiptoLocalNetworkPermission() ),
    wlan_offloadability( *this, dict ),
    non_ip_pdn_type_indicator( *this, dict.avpNonIpPdnTypeIndicator() ),
    non_ip_data_delivery_mechanism( *this, dict.avpNonIpDataDeliveryMechanism() ),
    scef_id( *this, dict.avpScefId() ),
    scef_realm( *this, dict.avpScefRealm() ),
    preferred_data_mode( *this, dict.avpPreferredDataMode() ),
    pdn_connection_continuity( *this, dict.avpPdnConnectionContinuity() ),
    rds_indicator( *this, dict.avpRdsIndicator() ),
    interworking_5gs_indicator( *this, dict.avpInterworking5gsIndicator() )
{
    add( context_identifier );
    add( served_party_ip_address );
    add( pdn_type );
    add( service_selection );
    add( eps_subscribed_qos_profile );
    add( vplmn_dynamic_address_allowed );
    add( mip6_agent_info );
    add( visited_network_identifier );
    add( pdn_gw_allocation_type );
    add( tgpp_charging_characteristics );
    add( ambr );
    add( specific_apn_info );
    add( apn_oi_replacement );
    add( sipto_permission );
    add( lipa_permission );
    add( restoration_priority );
    add( sipto_local_network_permission );
    add( wlan_offloadability );
    add( non_ip_pdn_type_indicator );
    add( non_ip_data_delivery_mechanism );
    add( scef_id );
    add( scef_realm );
    add( preferred_data_mode );
    add( pdn_connection_continuity );
    add( rds_indicator );
    add( interworking_5gs_indicator );
}

ApnConfigurationExtractor::~ApnConfigurationExtractor()
{
}

OcOlrExtractor::OcOlrExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpOcOlr() ),
    oc_sequence_number( *this, dict.avpOcSequenceNumber() ),
    oc_report_type( *this, dict.avpOcReportType() ),
    oc_reduction_percentage( *this, dict.avpOcReductionPercentage() ),
    oc_validity_duration( *this, dict.avpOcValidityDuration() )
{
    add( oc_sequence_number );
    add( oc_report_type );
    add( oc_reduction_percentage );
    add( oc_validity_duration );
}

OcOlrExtractor::~OcOlrExtractor()
{
}

TraceDataExtractor::TraceDataExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpTraceData() ),
    trace_reference( *this, dict.avpTraceReference() ),
    trace_depth( *this, dict.avpTraceDepth() ),
    trace_ne_type_list( *this, dict.avpTraceNeTypeList() ),
    trace_interface_list( *this, dict.avpTraceInterfaceList() ),
    trace_event_list( *this, dict.avpTraceEventList() ),
    omc_id( *this, dict.avpOmcId() ),
    trace_collection_entity( *this, dict.avpTraceCollectionEntity() ),
    mdt_configuration( *this, dict )
{
    add( trace_reference );
    add( trace_depth );
    add( trace_ne_type_list );
    add( trace_interface_list );
    add( trace_event_list );
    add( omc_id );
    add( trace_collection_entity );
    add( mdt_configuration );
}

TraceDataExtractor::~TraceDataExtractor()
{
}

SupportedFeaturesExtractor::SupportedFeaturesExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpSupportedFeatures() ),
    vendor_id( *this, dict.avpVendorId() ),
    feature_list_id( *this, dict.avpFeatureListId() ),
    feature_list( *this, dict.avpFeatureList() )
{
    add( vendor_id );
    add( feature_list_id );
    add( feature_list );
}

SupportedFeaturesExtractor::~SupportedFeaturesExtractor()
{
}

AccessNetworkInfoExtractor::AccessNetworkInfoExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpAccessNetworkInfo() ),
    ssid( *this, dict.avpSsid() ),
    bssid( *this, dict.avpBssid() ),
    location_information( *this, dict.avpLocationInformation() ),
    location_data( *this, dict.avpLocationData() ),
    operator_name( *this, dict.avpOperatorName() ),
    logical_access_id( *this, dict.avpLogicalAccessId() )
{
    add( ssid );
    add( bssid );
    add( location_information );
    add( location_data );
    add( operator_name );
    add( logical_access_id );
}

AccessNetworkInfoExtractor::~AccessNetworkInfoExtractor()
{
}

LoadExtractor::LoadExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpLoad() ),
    load_type( *this, dict.avpLoadType() ),
    load_value( *this, dict.avpLoadValue() ),
    sourceid( *this, dict.avpSourceid() )
{
    add( load_type );
    add( load_value );
    add( sourceid );
}

LoadExtractor::~LoadExtractor()
{
}

OcSupportedFeaturesExtractor::OcSupportedFeaturesExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpOcSupportedFeatures() ),
    oc_feature_vector( *this, dict.avpOcFeatureVector() )
{
    add( oc_feature_vector );
}

OcSupportedFeaturesExtractor::~OcSupportedFeaturesExtractor()
{
}

TerminalInformationExtractor::TerminalInformationExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpTerminalInformation() ),
    imei( *this, dict.avpImei() ),
    software_version( *this, dict.avpSoftwareVersion() )
{
    add( imei );
    add( software_version );
}

TerminalInformationExtractor::~TerminalInformationExtractor()
{
}

SubscriptionIdExtractor::SubscriptionIdExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpSubscriptionId() ),
    subscription_id_type( *this, dict.avpSubscriptionIdType() ),
    subscription_id_data( *this, dict.avpSubscriptionIdData() )
{
    add( subscription_id_type );
    add( subscription_id_data );
}

SubscriptionIdExtractor::~SubscriptionIdExtractor()
{
}

EmergencyInfoExtractor::EmergencyInfoExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpEmergencyInfo() ),
    mip6_agent_info( *this, dict )
{
    add( mip6_agent_info );
}

EmergencyInfoExtractor::~EmergencyInfoExtractor()
{
}

TraceInfoExtractor::TraceInfoExtractor( FDExtractor &parent, Dictionary &dict )
   : FDExtractor( parent, dict.avpTraceInfo() ),
    trace_data( *this, dict ),
    trace_reference( *this, dict.avpTraceReference() )
{
    add( trace_data );
    add( trace_reference );
}

TraceInfoExtractor::~TraceInfoExtractor()
{
}

SupportedFeaturesExtractorList::SupportedFeaturesExtractorList( FDExtractor &parent, Dictionary &dict )
    : FDExtractorList( parent, dict.avpSupportedFeatures() ),
    m_dict( dict )
{
}

SupportedFeaturesExtractorList::~SupportedFeaturesExtractorList()
{
}

DiameterEapRequestExtractor::DiameterEapRequestExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    destination_realm( *this, dict.avpDestinationRealm() ),
    destination_host( *this, dict.avpDestinationHost() ),
    auth_request_type( *this, dict.avpAuthRequestType() ),
    eap_payload( *this, dict.avpEapPayload() ),
    user_name( *this, dict.avpUserName() ),
    rat_type( *this, dict.avpRatType() ),
    service_selection( *this, dict.avpServiceSelection() ),
    mip6_feature_vector( *this, dict.avpMip6FeatureVector() ),
    qos_capability( *this, dict ),
    visited_network_identifier( *this, dict.avpVisitedNetworkIdentifier() ),
    aaa_failure_indication( *this, dict.avpAaaFailureIndication() ),
    supported_features( *this, dict ),
    ue_local_ip_address( *this, dict.avpUeLocalIpAddress() ),
    oc_supported_features( *this, dict ),
    terminal_information( *this, dict ),
    emergency_services( *this, dict.avpEmergencyServices() )
{
    add( session_id );
    add( drmp );
    add( auth_application_id );
    add( origin_host );
    add( origin_realm );
    add( destination_realm );
    add( destination_host );
    add( auth_request_type );
    add( eap_payload );
    add( user_name );
    add( rat_type );
    add( service_selection );
    add( mip6_feature_vector );
    add( qos_capability );
    add( visited_network_identifier );
    add( aaa_failure_indication );
    add( supported_features );
    add( ue_local_ip_address );
    add( oc_supported_features );
    add( terminal_information );
    add( emergency_services );
}

DiameterEapRequestExtractor::~DiameterEapRequestExtractor()
{
}

LoadExtractorList::LoadExtractorList( FDExtractor &parent, Dictionary &dict )
    : FDExtractorList( parent, dict.avpLoad() ),
    m_dict( dict )
{
}

LoadExtractorList::~LoadExtractorList()
{
}

DiameterEapAnswerExtractor::DiameterEapAnswerExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    auth_request_type( *this, dict.avpAuthRequestType() ),
    result_code( *this, dict.avpResultCode() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    eap_payload( *this, dict.avpEapPayload() ),
    user_name( *this, dict.avpUserName() ),
    eap_master_session_key( *this, dict.avpEapMasterSessionKey() ),
    apn_oi_replacement( *this, dict.avpApnOiReplacement() ),
    apn_configuration( *this, dict ),
    mip6_feature_vector( *this, dict.avpMip6FeatureVector() ),
    mobile_node_identifier( *this, dict.avpMobileNodeIdentifier() ),
    trace_info( *this, dict ),
    subscription_id( *this, dict ),
    session_timeout( *this, dict.avpSessionTimeout() ),
    mip6_agent_info( *this, dict ),
    tgpp_charging_characteristics( *this, dict.avp3gppChargingCharacteristics() ),
    redirect_host( *this, dict.avpRedirectHost() ),
    supported_features( *this, dict ),
    oc_supported_features( *this, dict ),
    oc_olr( *this, dict ),
    load( *this, dict ),
    access_network_info( *this, dict ),
    user_location_info_time( *this, dict.avpUserLocationInfoTime() ),
    ue_usage_type( *this, dict.avpUeUsageType() ),
    emergency_info( *this, dict ),
    core_network_restrictions( *this, dict.avpCoreNetworkRestrictions() )
{
    add( session_id );
    add( drmp );
    add( auth_application_id );
    add( auth_request_type );
    add( result_code );
    add( origin_host );
    add( origin_realm );
    add( eap_payload );
    add( user_name );
    add( eap_master_session_key );
    add( apn_oi_replacement );
    add( apn_configuration );
    add( mip6_feature_vector );
    add( mobile_node_identifier );
    add( trace_info );
    add( subscription_id );
    add( session_timeout );
    add( mip6_agent_info );
    add( tgpp_charging_characteristics );
    add( redirect_host );
    add( supported_features );
    add( oc_supported_features );
    add( oc_olr );
    add( load );
    add( access_network_info );
    add( user_location_info_time );
    add( ue_usage_type );
    add( emergency_info );
    add( core_network_restrictions );
}

DiameterEapAnswerExtractor::~DiameterEapAnswerExtractor()
{
}

AaRequestExtractor::AaRequestExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    destination_realm( *this, dict.avpDestinationRealm() ),
    destination_host( *this, dict.avpDestinationHost() ),
    auth_request_type( *this, dict.avpAuthRequestType() ),
    user_name( *this, dict.avpUserName() ),
    oc_supported_features( *this, dict ),
    aar_flags( *this, dict.avpAarFlags() ),
    ue_local_ip_address( *this, dict.avpUeLocalIpAddress() )
{
    add( session_id );
    add( drmp );
    add( auth_application_id );
    add( origin_host );
    add( origin_realm );
    add( destination_realm );
    add( destination_host );
    add( auth_request_type );
    add( user_name );
    add( oc_supported_features );
    add( aar_flags );
    add( ue_local_ip_address );
}

AaRequestExtractor::~AaRequestExtractor()
{
}

AaAnswerExtractor::AaAnswerExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    auth_request_type( *this, dict.avpAuthRequestType() ),
    result_code( *this, dict.avpResultCode() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    user_name( *this, dict.avpUserName() ),
    apn_oi_replacement( *this, dict.avpApnOiReplacement() ),
    apn_configuration( *this, dict ),
    trace_info( *this, dict ),
    subscription_id( *this, dict ),
    tgpp_charging_characteristics( *this, dict.avp3gppChargingCharacteristics() ),
    session_timeout( *this, dict.avpSessionTimeout() ),
    oc_supported_features( *this, dict ),
    oc_olr( *this, dict ),
    load( *this, dict ),
    access_network_info( *this, dict ),
    user_location_info_time( *this, dict.avpUserLocationInfoTime() )
{
    add( session_id );
    add( drmp );
    add( auth_application_id );
    add( auth_request_type );
    add( result_code );
    add( origin_host );
    add( origin_realm );
    add( user_name );
    add( apn_oi_replacement );
    add( apn_configuration );
    add( trace_info );
    add( subscription_id );
    add( tgpp_charging_characteristics );
    add( session_timeout );
    add( oc_supported_features );
    add( oc_olr );
    add( load );
    add( access_network_info );
    add( user_location_info_time );
}

AaAnswerExtractor::~AaAnswerExtractor()
{
}

SessionTerminationRequestExtractor::SessionTerminationRequestExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    destination_realm( *this, dict.avpDestinationRealm() ),
    destination_host( *this, dict.avpDestinationHost() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    termination_cause( *this, dict.avpTerminationCause() ),
    user_name( *this, dict.avpUserName() ),
    oc_supported_features( *this, dict )
{
    add( session_id );
    add( drmp );
    add( origin_host );
    add( origin_realm );
    add( destination_realm );
    add( destination_host );
    add( auth_application_id );
    add( termination_cause );
    add( user_name );
    add( oc_supported_features );
}

SessionTerminationRequestExtractor::~SessionTerminationRequestExtractor()
{
}

SessionTerminationAnswerExtractor::SessionTerminationAnswerExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    result_code( *this, dict.avpResultCode() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    oc_supported_features( *this, dict ),
    oc_olr( *this, dict ),
    load( *this, dict )
{
    add( session_id );
    add( drmp );
    add( result_code );
    add( origin_host );
    add( origin_realm );
    add( oc_supported_features );
    add( oc_olr );
    add( load );
}

SessionTerminationAnswerExtractor::~SessionTerminationAnswerExtractor()
{
}

AbortSessionRequestExtractor::AbortSessionRequestExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    destination_realm( *this, dict.avpDestinationRealm() ),
    destination_host( *this, dict.avpDestinationHost() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    user_name( *this, dict.avpUserName() ),
    auth_session_state( *this, dict.avpAuthSessionState() )
{
    add( session_id );
    add( drmp );
    add( origin_host );
    add( origin_realm );
    add( destination_realm );
    add( destination_host );
    add( auth_application_id );
    add( user_name );
    add( auth_session_state );
}

AbortSessionRequestExtractor::~AbortSessionRequestExtractor()
{
}

AbortSessionAnswerExtractor::AbortSessionAnswerExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    result_code( *this, dict.avpResultCode() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() )
{
    add( session_id );
    add( drmp );
    add( result_code );
    add( origin_host );
    add( origin_realm );
}

AbortSessionAnswerExtractor::~AbortSessionAnswerExtractor()
{
}

ReAuthRequestExtractor::ReAuthRequestExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    destination_realm( *this, dict.avpDestinationRealm() ),
    destination_host( *this, dict.avpDestinationHost() ),
    auth_application_id( *this, dict.avpAuthApplicationId() ),
    re_auth_request_type( *this, dict.avpReAuthRequestType() ),
    user_name( *this, dict.avpUserName() )
{
    add( session_id );
    add( drmp );
    add( origin_host );
    add( origin_realm );
    add( destination_realm );
    add( destination_host );
    add( auth_application_id );
    add( re_auth_request_type );
    add( user_name );
}

ReAuthRequestExtractor::~ReAuthRequestExtractor()
{
}

ReAuthAnswerExtractor::ReAuthAnswerExtractor( FDMessage &msg, Dictionary &dict )
   : FDExtractor( msg ),
    session_id( *this, dict.avpSessionId() ),
    drmp( *this, dict.avpDrmp() ),
    result_code( *this, dict.avpResultCode() ),
    origin_host( *this, dict.avpOriginHost() ),
    origin_realm( *this, dict.avpOriginRealm() ),
    user_name( *this, dict.avpUserName() )
{
    add( session_id );
    add( drmp );
    add( result_code );
    add( origin_host );
    add( origin_realm );
    add( user_name );
}

ReAuthAnswerExtractor::~ReAuthAnswerExtractor()
{
}


}
