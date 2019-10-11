#ifndef __SWM_H
#define __SWM_H

#include "efd.h"

namespace swm {

//
// Primary Objects
//

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    FDDictionaryEntryApplication &app()                     { return m_app; }

    FDDictionaryEntryCommand &cmdDER()                     	{ return m_cmd_der; }
    FDDictionaryEntryCommand &cmdDEA()                     	{ return m_cmd_dea; }
    FDDictionaryEntryCommand &cmdAAR()                     	{ return m_cmd_aar; }
    FDDictionaryEntryCommand &cmdAAA()                     	{ return m_cmd_aaa; }
    FDDictionaryEntryCommand &cmdSTR()                     	{ return m_cmd_str; }
    FDDictionaryEntryCommand &cmdSTA()                     	{ return m_cmd_sta; }
    FDDictionaryEntryCommand &cmdASR()                     	{ return m_cmd_asr; }
    FDDictionaryEntryCommand &cmdASA()                     	{ return m_cmd_asa; }
    FDDictionaryEntryCommand &cmdRAR()                     	{ return m_cmd_rar; }
    FDDictionaryEntryCommand &cmdRAA()                     	{ return m_cmd_raa; }

    FDDictionaryEntryVendor &vndETSI()                     	{ return m_vnd_Etsi; }
    FDDictionaryEntryVendor &vnd3GPP()                     	{ return m_vnd_3gpp; }

    FDDictionaryEntryAVP &avpSubscriptionIdType()          	{ return m_avp_subscription_id_type; }
    FDDictionaryEntryAVP &avpPreEmptionCapability()        	{ return m_avp_pre_emption_capability; }
    FDDictionaryEntryAVP &avpFeatureListId()               	{ return m_avp_feature_list_id; }
    FDDictionaryEntryAVP &avpAmbr()                        	{ return m_avp_ambr; }
    FDDictionaryEntryAVP &avpMip6HomeLinkPrefix()          	{ return m_avp_mip6_home_link_prefix; }
    FDDictionaryEntryAVP &avpTerminationCause()            	{ return m_avp_termination_cause; }
    FDDictionaryEntryAVP &avpCoreNetworkRestrictions()     	{ return m_avp_core_network_restrictions; }
    FDDictionaryEntryAVP &avpOcSequenceNumber()            	{ return m_avp_oc_sequence_number; }
    FDDictionaryEntryAVP &avpTrackingAreaIdentity()        	{ return m_avp_tracking_area_identity; }
    FDDictionaryEntryAVP &avpLoadValue()                   	{ return m_avp_load_value; }
    FDDictionaryEntryAVP &avpFeatureList()                 	{ return m_avp_feature_list; }
    FDDictionaryEntryAVP &avpOmcId()                       	{ return m_avp_omc_id; }
    FDDictionaryEntryAVP &avpOcReportType()                	{ return m_avp_oc_report_type; }
    FDDictionaryEntryAVP &avpUeUsageType()                 	{ return m_avp_ue_usage_type; }
    FDDictionaryEntryAVP &avpLoadType()                    	{ return m_avp_load_type; }
    FDDictionaryEntryAVP &avpOcFeatureVector()             	{ return m_avp_oc_feature_vector; }
    FDDictionaryEntryAVP &avpAaaFailureIndication()        	{ return m_avp_aaa_failure_indication; }
    FDDictionaryEntryAVP &avpListOfMeasurements()          	{ return m_avp_list_of_measurements; }
    FDDictionaryEntryAVP &avpMdtConfiguration()            	{ return m_avp_mdt_configuration; }
    FDDictionaryEntryAVP &avpDrmp()                        	{ return m_avp_drmp; }
    FDDictionaryEntryAVP &avpPreferredDataMode()           	{ return m_avp_preferred_data_mode; }
    FDDictionaryEntryAVP &avpAarFlags()                    	{ return m_avp_aar_flags; }
    FDDictionaryEntryAVP &avpPriorityLevel()               	{ return m_avp_priority_level; }
    FDDictionaryEntryAVP &avpPreEmptionVulnerability()     	{ return m_avp_pre_emption_vulnerability; }
    FDDictionaryEntryAVP &avpQosClassIdentifier()          	{ return m_avp_qos_class_identifier; }
    FDDictionaryEntryAVP &avpAreaScope()                   	{ return m_avp_area_scope; }
    FDDictionaryEntryAVP &avpTraceNeTypeList()             	{ return m_avp_trace_ne_type_list; }
    FDDictionaryEntryAVP &avpDestinationHost()             	{ return m_avp_destination_host; }
    FDDictionaryEntryAVP &avpQosCapability()               	{ return m_avp_qos_capability; }
    FDDictionaryEntryAVP &avpLocationAreaIdentity()        	{ return m_avp_location_area_identity; }
    FDDictionaryEntryAVP &avpLoggingInterval()             	{ return m_avp_logging_interval; }
    FDDictionaryEntryAVP &avpUeLocalIpAddress()            	{ return m_avp_ue_local_ip_address; }
    FDDictionaryEntryAVP &avpMbsfnArea()                   	{ return m_avp_mbsfn_area; }
    FDDictionaryEntryAVP &avpJobType()                     	{ return m_avp_job_type; }
    FDDictionaryEntryAVP &avpMip6FeatureVector()           	{ return m_avp_mip6_feature_vector; }
    FDDictionaryEntryAVP &avpWlanOffloadability()          	{ return m_avp_wlan_offloadability; }
    FDDictionaryEntryAVP &avpMipHomeAgentHost()            	{ return m_avp_mip_home_agent_host; }
    FDDictionaryEntryAVP &avpPdnType()                     	{ return m_avp_pdn_type; }
    FDDictionaryEntryAVP &avp3gppChargingCharacteristics() 	{ return m_avp_3gpp_charging_characteristics; }
    FDDictionaryEntryAVP &avpOriginRealm()                 	{ return m_avp_origin_realm; }
    FDDictionaryEntryAVP &avpOriginHost()                  	{ return m_avp_origin_host; }
    FDDictionaryEntryAVP &avpEventThresholdRsrq()          	{ return m_avp_event_threshold_rsrq; }
    FDDictionaryEntryAVP &avpVplmnDynamicAddressAllowed()  	{ return m_avp_vplmn_dynamic_address_allowed; }
    FDDictionaryEntryAVP &avpApnConfiguration()            	{ return m_avp_apn_configuration; }
    FDDictionaryEntryAVP &avpSubscriptionIdData()          	{ return m_avp_subscription_id_data; }
    FDDictionaryEntryAVP &avpMbsfnAreaId()                 	{ return m_avp_mbsfn_area_id; }
    FDDictionaryEntryAVP &avpTraceCollectionEntity()       	{ return m_avp_trace_collection_entity; }
    FDDictionaryEntryAVP &avpWlanOffloadabilityEutran()    	{ return m_avp_wlan_offloadability_eutran; }
    FDDictionaryEntryAVP &avpQosProfileTemplate()          	{ return m_avp_qos_profile_template; }
    FDDictionaryEntryAVP &avpScefId()                      	{ return m_avp_scef_id; }
    FDDictionaryEntryAVP &avpTraceEventList()              	{ return m_avp_trace_event_list; }
    FDDictionaryEntryAVP &avpSsid()                        	{ return m_avp_ssid; }
    FDDictionaryEntryAVP &avpMip6AgentInfo()               	{ return m_avp_mip6_agent_info; }
    FDDictionaryEntryAVP &avpLoggingDuration()             	{ return m_avp_logging_duration; }
    FDDictionaryEntryAVP &avpCollectionPeriodRrmUmts()     	{ return m_avp_collection_period_rrm_umts; }
    FDDictionaryEntryAVP &avpNonIpPdnTypeIndicator()       	{ return m_avp_non_ip_pdn_type_indicator; }
    FDDictionaryEntryAVP &avpPositioningMethod()           	{ return m_avp_positioning_method; }
    FDDictionaryEntryAVP &avpOcOlr()                       	{ return m_avp_oc_olr; }
    FDDictionaryEntryAVP &avpTraceData()                   	{ return m_avp_trace_data; }
    FDDictionaryEntryAVP &avpSourceid()                    	{ return m_avp_sourceid; }
    FDDictionaryEntryAVP &avpSpecificApnInfo()             	{ return m_avp_specific_apn_info; }
    FDDictionaryEntryAVP &avpOcReductionPercentage()       	{ return m_avp_oc_reduction_percentage; }
    FDDictionaryEntryAVP &avpReportInterval()              	{ return m_avp_report_interval; }
    FDDictionaryEntryAVP &avpEpsSubscribedQosProfile()     	{ return m_avp_eps_subscribed_qos_profile; }
    FDDictionaryEntryAVP &avpApnOiReplacement()            	{ return m_avp_apn_oi_replacement; }
    FDDictionaryEntryAVP &avpSupportedFeatures()           	{ return m_avp_supported_features; }
    FDDictionaryEntryAVP &avpEventThresholdEvent1i()       	{ return m_avp_event_threshold_event_1i; }
    FDDictionaryEntryAVP &avpRatType()                     	{ return m_avp_rat_type; }
    FDDictionaryEntryAVP &avpEventThresholdEvent1f()       	{ return m_avp_event_threshold_event_1f; }
    FDDictionaryEntryAVP &avpRdsIndicator()                	{ return m_avp_rds_indicator; }
    FDDictionaryEntryAVP &avpAllocationRetentionPriority() 	{ return m_avp_allocation_retention_priority; }
    FDDictionaryEntryAVP &avpCellGlobalIdentity()          	{ return m_avp_cell_global_identity; }
    FDDictionaryEntryAVP &avpOcValidityDuration()          	{ return m_avp_oc_validity_duration; }
    FDDictionaryEntryAVP &avpServiceSelection()            	{ return m_avp_service_selection; }
    FDDictionaryEntryAVP &avpAccessNetworkInfo()           	{ return m_avp_access_network_info; }
    FDDictionaryEntryAVP &avpEapPayload()                  	{ return m_avp_eap_payload; }
    FDDictionaryEntryAVP &avpLogicalAccessId()             	{ return m_avp_logical_access_id; }
    FDDictionaryEntryAVP &avpExtendedMaxRequestedBwDl()    	{ return m_avp_extended_max_requested_bw_dl; }
    FDDictionaryEntryAVP &avpMeasurementPeriodLte()        	{ return m_avp_measurement_period_lte; }
    FDDictionaryEntryAVP &avpResultCode()                  	{ return m_avp_result_code; }
    FDDictionaryEntryAVP &avpAuthRequestType()             	{ return m_avp_auth_request_type; }
    FDDictionaryEntryAVP &avpQosProfileId()                	{ return m_avp_qos_profile_id; }
    FDDictionaryEntryAVP &avpWlanOffloadabilityUtran()     	{ return m_avp_wlan_offloadability_utran; }
    FDDictionaryEntryAVP &avpOperatorName()                	{ return m_avp_operator_name; }
    FDDictionaryEntryAVP &avpMaxRequestedBandwidthDl()     	{ return m_avp_max_requested_bandwidth_dl; }
    FDDictionaryEntryAVP &avpTraceInterfaceList()          	{ return m_avp_trace_interface_list; }
    FDDictionaryEntryAVP &avpPdnConnectionContinuity()     	{ return m_avp_pdn_connection_continuity; }
    FDDictionaryEntryAVP &avpInterworking5gsIndicator()    	{ return m_avp_interworking_5gs_indicator; }
    FDDictionaryEntryAVP &avpLoad()                        	{ return m_avp_load; }
    FDDictionaryEntryAVP &avpContextIdentifier()           	{ return m_avp_context_identifier; }
    FDDictionaryEntryAVP &avpEUtranCellGlobalIdentity()    	{ return m_avp_e_utran_cell_global_identity; }
    FDDictionaryEntryAVP &avpOcSupportedFeatures()         	{ return m_avp_oc_supported_features; }
    FDDictionaryEntryAVP &avpEventThresholdRsrp()          	{ return m_avp_event_threshold_rsrp; }
    FDDictionaryEntryAVP &avpTerminalInformation()         	{ return m_avp_terminal_information; }
    FDDictionaryEntryAVP &avpLocationInformation()         	{ return m_avp_location_information; }
    FDDictionaryEntryAVP &avpCollectionPeriodRrmLte()      	{ return m_avp_collection_period_rrm_lte; }
    FDDictionaryEntryAVP &avpAuthApplicationId()           	{ return m_avp_auth_application_id; }
    FDDictionaryEntryAVP &avpLipaPermission()              	{ return m_avp_lipa_permission; }
    FDDictionaryEntryAVP &avpExtendedMaxRequestedBwUl()    	{ return m_avp_extended_max_requested_bw_ul; }
    FDDictionaryEntryAVP &avpEmergencyServices()           	{ return m_avp_emergency_services; }
    FDDictionaryEntryAVP &avpVisitedNetworkIdentifier()    	{ return m_avp_visited_network_identifier; }
    FDDictionaryEntryAVP &avpSubscriptionId()              	{ return m_avp_subscription_id; }
    FDDictionaryEntryAVP &avpRestorationPriority()         	{ return m_avp_restoration_priority; }
    FDDictionaryEntryAVP &avpPdnGwAllocationType()         	{ return m_avp_pdn_gw_allocation_type; }
    FDDictionaryEntryAVP &avpReAuthRequestType()           	{ return m_avp_re_auth_request_type; }
    FDDictionaryEntryAVP &avpMdtAllowedPlmnId()            	{ return m_avp_mdt_allowed_plmn_id; }
    FDDictionaryEntryAVP &avpReportingTrigger()            	{ return m_avp_reporting_trigger; }
    FDDictionaryEntryAVP &avpRoutingAreaIdentity()         	{ return m_avp_routing_area_identity; }
    FDDictionaryEntryAVP &avpEapMasterSessionKey()         	{ return m_avp_eap_master_session_key; }
    FDDictionaryEntryAVP &avpTraceReference()              	{ return m_avp_trace_reference; }
    FDDictionaryEntryAVP &avpMobileNodeIdentifier()        	{ return m_avp_mobile_node_identifier; }
    FDDictionaryEntryAVP &avpCarrierFrequency()            	{ return m_avp_carrier_frequency; }
    FDDictionaryEntryAVP &avpMeasurementQuantity()         	{ return m_avp_measurement_quantity; }
    FDDictionaryEntryAVP &avpServedPartyIpAddress()        	{ return m_avp_served_party_ip_address; }
    FDDictionaryEntryAVP &avpSessionTimeout()              	{ return m_avp_session_timeout; }
    FDDictionaryEntryAVP &avpTraceDepth()                  	{ return m_avp_trace_depth; }
    FDDictionaryEntryAVP &avpSoftwareVersion()             	{ return m_avp_software_version; }
    FDDictionaryEntryAVP &avpSiptoLocalNetworkPermission() 	{ return m_avp_sipto_local_network_permission; }
    FDDictionaryEntryAVP &avpVendorId()                    	{ return m_avp_vendor_id; }
    FDDictionaryEntryAVP &avpLocationData()                	{ return m_avp_location_data; }
    FDDictionaryEntryAVP &avpMaxRequestedBandwidthUl()     	{ return m_avp_max_requested_bandwidth_ul; }
    FDDictionaryEntryAVP &avpImei()                        	{ return m_avp_imei; }
    FDDictionaryEntryAVP &avpNonIpDataDeliveryMechanism()  	{ return m_avp_non_ip_data_delivery_mechanism; }
    FDDictionaryEntryAVP &avpAuthSessionState()            	{ return m_avp_auth_session_state; }
    FDDictionaryEntryAVP &avpRedirectHost()                	{ return m_avp_redirect_host; }
    FDDictionaryEntryAVP &avpDestinationRealm()            	{ return m_avp_destination_realm; }
    FDDictionaryEntryAVP &avpSessionId()                   	{ return m_avp_session_id; }
    FDDictionaryEntryAVP &avpUserName()                    	{ return m_avp_user_name; }
    FDDictionaryEntryAVP &avpScefRealm()                   	{ return m_avp_scef_realm; }
    FDDictionaryEntryAVP &avpBssid()                       	{ return m_avp_bssid; }
    FDDictionaryEntryAVP &avpSiptoPermission()             	{ return m_avp_sipto_permission; }
    FDDictionaryEntryAVP &avpEmergencyInfo()               	{ return m_avp_emergency_info; }
    FDDictionaryEntryAVP &avpReportAmount()                	{ return m_avp_report_amount; }
    FDDictionaryEntryAVP &avpMipHomeAgentAddress()         	{ return m_avp_mip_home_agent_address; }
    FDDictionaryEntryAVP &avpMeasurementPeriodUmts()       	{ return m_avp_measurement_period_umts; }
    FDDictionaryEntryAVP &avpUserLocationInfoTime()        	{ return m_avp_user_location_info_time; }
    FDDictionaryEntryAVP &avpTraceInfo()                   	{ return m_avp_trace_info; }

private:
    FDDictionaryEntryApplication m_app;                    

    FDDictionaryEntryCommand m_cmd_der;
    FDDictionaryEntryCommand m_cmd_dea;
    FDDictionaryEntryCommand m_cmd_aar;
    FDDictionaryEntryCommand m_cmd_aaa;
    FDDictionaryEntryCommand m_cmd_str;
    FDDictionaryEntryCommand m_cmd_sta;
    FDDictionaryEntryCommand m_cmd_asr;
    FDDictionaryEntryCommand m_cmd_asa;
    FDDictionaryEntryCommand m_cmd_rar;
    FDDictionaryEntryCommand m_cmd_raa;

    FDDictionaryEntryVendor m_vnd_Etsi;
    FDDictionaryEntryVendor m_vnd_3gpp;

    FDDictionaryEntryAVP m_avp_subscription_id_type;
    FDDictionaryEntryAVP m_avp_pre_emption_capability;
    FDDictionaryEntryAVP m_avp_feature_list_id;
    FDDictionaryEntryAVP m_avp_ambr;
    FDDictionaryEntryAVP m_avp_mip6_home_link_prefix;
    FDDictionaryEntryAVP m_avp_termination_cause;
    FDDictionaryEntryAVP m_avp_core_network_restrictions;
    FDDictionaryEntryAVP m_avp_oc_sequence_number;
    FDDictionaryEntryAVP m_avp_tracking_area_identity;
    FDDictionaryEntryAVP m_avp_load_value;
    FDDictionaryEntryAVP m_avp_feature_list;
    FDDictionaryEntryAVP m_avp_omc_id;
    FDDictionaryEntryAVP m_avp_oc_report_type;
    FDDictionaryEntryAVP m_avp_ue_usage_type;
    FDDictionaryEntryAVP m_avp_load_type;
    FDDictionaryEntryAVP m_avp_oc_feature_vector;
    FDDictionaryEntryAVP m_avp_aaa_failure_indication;
    FDDictionaryEntryAVP m_avp_list_of_measurements;
    FDDictionaryEntryAVP m_avp_mdt_configuration;
    FDDictionaryEntryAVP m_avp_drmp;
    FDDictionaryEntryAVP m_avp_preferred_data_mode;
    FDDictionaryEntryAVP m_avp_aar_flags;
    FDDictionaryEntryAVP m_avp_priority_level;
    FDDictionaryEntryAVP m_avp_pre_emption_vulnerability;
    FDDictionaryEntryAVP m_avp_qos_class_identifier;
    FDDictionaryEntryAVP m_avp_area_scope;
    FDDictionaryEntryAVP m_avp_trace_ne_type_list;
    FDDictionaryEntryAVP m_avp_destination_host;
    FDDictionaryEntryAVP m_avp_qos_capability;
    FDDictionaryEntryAVP m_avp_location_area_identity;
    FDDictionaryEntryAVP m_avp_logging_interval;
    FDDictionaryEntryAVP m_avp_ue_local_ip_address;
    FDDictionaryEntryAVP m_avp_mbsfn_area;
    FDDictionaryEntryAVP m_avp_job_type;
    FDDictionaryEntryAVP m_avp_mip6_feature_vector;
    FDDictionaryEntryAVP m_avp_wlan_offloadability;
    FDDictionaryEntryAVP m_avp_mip_home_agent_host;
    FDDictionaryEntryAVP m_avp_pdn_type;
    FDDictionaryEntryAVP m_avp_3gpp_charging_characteristics;
    FDDictionaryEntryAVP m_avp_origin_realm;
    FDDictionaryEntryAVP m_avp_origin_host;
    FDDictionaryEntryAVP m_avp_event_threshold_rsrq;
    FDDictionaryEntryAVP m_avp_vplmn_dynamic_address_allowed;
    FDDictionaryEntryAVP m_avp_apn_configuration;
    FDDictionaryEntryAVP m_avp_subscription_id_data;
    FDDictionaryEntryAVP m_avp_mbsfn_area_id;
    FDDictionaryEntryAVP m_avp_trace_collection_entity;
    FDDictionaryEntryAVP m_avp_wlan_offloadability_eutran;
    FDDictionaryEntryAVP m_avp_qos_profile_template;
    FDDictionaryEntryAVP m_avp_scef_id;
    FDDictionaryEntryAVP m_avp_trace_event_list;
    FDDictionaryEntryAVP m_avp_ssid;
    FDDictionaryEntryAVP m_avp_mip6_agent_info;
    FDDictionaryEntryAVP m_avp_logging_duration;
    FDDictionaryEntryAVP m_avp_collection_period_rrm_umts;
    FDDictionaryEntryAVP m_avp_non_ip_pdn_type_indicator;
    FDDictionaryEntryAVP m_avp_positioning_method;
    FDDictionaryEntryAVP m_avp_oc_olr;
    FDDictionaryEntryAVP m_avp_trace_data;
    FDDictionaryEntryAVP m_avp_sourceid;
    FDDictionaryEntryAVP m_avp_specific_apn_info;
    FDDictionaryEntryAVP m_avp_oc_reduction_percentage;
    FDDictionaryEntryAVP m_avp_report_interval;
    FDDictionaryEntryAVP m_avp_eps_subscribed_qos_profile;
    FDDictionaryEntryAVP m_avp_apn_oi_replacement;
    FDDictionaryEntryAVP m_avp_supported_features;
    FDDictionaryEntryAVP m_avp_event_threshold_event_1i;
    FDDictionaryEntryAVP m_avp_rat_type;
    FDDictionaryEntryAVP m_avp_event_threshold_event_1f;
    FDDictionaryEntryAVP m_avp_rds_indicator;
    FDDictionaryEntryAVP m_avp_allocation_retention_priority;
    FDDictionaryEntryAVP m_avp_cell_global_identity;
    FDDictionaryEntryAVP m_avp_oc_validity_duration;
    FDDictionaryEntryAVP m_avp_service_selection;
    FDDictionaryEntryAVP m_avp_access_network_info;
    FDDictionaryEntryAVP m_avp_eap_payload;
    FDDictionaryEntryAVP m_avp_logical_access_id;
    FDDictionaryEntryAVP m_avp_extended_max_requested_bw_dl;
    FDDictionaryEntryAVP m_avp_measurement_period_lte;
    FDDictionaryEntryAVP m_avp_result_code;
    FDDictionaryEntryAVP m_avp_auth_request_type;
    FDDictionaryEntryAVP m_avp_qos_profile_id;
    FDDictionaryEntryAVP m_avp_wlan_offloadability_utran;
    FDDictionaryEntryAVP m_avp_operator_name;
    FDDictionaryEntryAVP m_avp_max_requested_bandwidth_dl;
    FDDictionaryEntryAVP m_avp_trace_interface_list;
    FDDictionaryEntryAVP m_avp_pdn_connection_continuity;
    FDDictionaryEntryAVP m_avp_interworking_5gs_indicator;
    FDDictionaryEntryAVP m_avp_load;
    FDDictionaryEntryAVP m_avp_context_identifier;
    FDDictionaryEntryAVP m_avp_e_utran_cell_global_identity;
    FDDictionaryEntryAVP m_avp_oc_supported_features;
    FDDictionaryEntryAVP m_avp_event_threshold_rsrp;
    FDDictionaryEntryAVP m_avp_terminal_information;
    FDDictionaryEntryAVP m_avp_location_information;
    FDDictionaryEntryAVP m_avp_collection_period_rrm_lte;
    FDDictionaryEntryAVP m_avp_auth_application_id;
    FDDictionaryEntryAVP m_avp_lipa_permission;
    FDDictionaryEntryAVP m_avp_extended_max_requested_bw_ul;
    FDDictionaryEntryAVP m_avp_emergency_services;
    FDDictionaryEntryAVP m_avp_visited_network_identifier;
    FDDictionaryEntryAVP m_avp_subscription_id;
    FDDictionaryEntryAVP m_avp_restoration_priority;
    FDDictionaryEntryAVP m_avp_pdn_gw_allocation_type;
    FDDictionaryEntryAVP m_avp_re_auth_request_type;
    FDDictionaryEntryAVP m_avp_mdt_allowed_plmn_id;
    FDDictionaryEntryAVP m_avp_reporting_trigger;
    FDDictionaryEntryAVP m_avp_routing_area_identity;
    FDDictionaryEntryAVP m_avp_eap_master_session_key;
    FDDictionaryEntryAVP m_avp_trace_reference;
    FDDictionaryEntryAVP m_avp_mobile_node_identifier;
    FDDictionaryEntryAVP m_avp_carrier_frequency;
    FDDictionaryEntryAVP m_avp_measurement_quantity;
    FDDictionaryEntryAVP m_avp_served_party_ip_address;
    FDDictionaryEntryAVP m_avp_session_timeout;
    FDDictionaryEntryAVP m_avp_trace_depth;
    FDDictionaryEntryAVP m_avp_software_version;
    FDDictionaryEntryAVP m_avp_sipto_local_network_permission;
    FDDictionaryEntryAVP m_avp_vendor_id;
    FDDictionaryEntryAVP m_avp_location_data;
    FDDictionaryEntryAVP m_avp_max_requested_bandwidth_ul;
    FDDictionaryEntryAVP m_avp_imei;
    FDDictionaryEntryAVP m_avp_non_ip_data_delivery_mechanism;
    FDDictionaryEntryAVP m_avp_auth_session_state;
    FDDictionaryEntryAVP m_avp_redirect_host;
    FDDictionaryEntryAVP m_avp_destination_realm;
    FDDictionaryEntryAVP m_avp_session_id;
    FDDictionaryEntryAVP m_avp_user_name;
    FDDictionaryEntryAVP m_avp_scef_realm;
    FDDictionaryEntryAVP m_avp_bssid;
    FDDictionaryEntryAVP m_avp_sipto_permission;
    FDDictionaryEntryAVP m_avp_emergency_info;
    FDDictionaryEntryAVP m_avp_report_amount;
    FDDictionaryEntryAVP m_avp_mip_home_agent_address;
    FDDictionaryEntryAVP m_avp_measurement_period_umts;
    FDDictionaryEntryAVP m_avp_user_location_info_time;
    FDDictionaryEntryAVP m_avp_trace_info;

};

//Forward declaration of Application;
class Application;

//
// DIAMETER REQUEST Processing - DiameterEapRequest (Application / Receiver)
// This message is used by a peer acting as the application to listen for
// DER request from Clients.
//-
class DERcmd : public FDCommandRequest
{
public:
    DERcmd( Application &app );
    ~DERcmd();

    virtual Int process( FDMessageRequest *req );

    Application &getApplication() { return m_app; }
    Dictionary &getDict();

private:
    DERcmd();

    Application &m_app;
};

//
// DIAMETER REQUEST - DiameterEapRequest (Client / Sender)
// This message is used by a peer acting as a Client to send a DER
// to the Diameter application and process the corresponding answer.
//
class DERreq : public FDMessageRequest
{
public:
    DERreq( Application &app );
    virtual ~DERreq();

    virtual Void processAnswer( FDMessageAnswer &ans );
 
    Application &getApplication() { return m_app; }
    Dictionary &getDict();
    const std::string &getSessionId() { return m_session.getSessionId(); }
    Void addSessionId( FDDictionaryEntryAVP &deSessionId ) { m_session.addSessionId( *this, deSessionId ); }

private:
    DERreq();
    Application &m_app;
    FDSession m_session;
};
 
//Forward declaration of Application;
class Application;

//
// DIAMETER REQUEST Processing - AaRequest (Application / Receiver)
// This message is used by a peer acting as the application to listen for
// AAR request from Clients.
//-
class AARcmd : public FDCommandRequest
{
public:
    AARcmd( Application &app );
    ~AARcmd();

    virtual Int process( FDMessageRequest *req );

    Application &getApplication() { return m_app; }
    Dictionary &getDict();

private:
    AARcmd();

    Application &m_app;
};

//
// DIAMETER REQUEST - AaRequest (Client / Sender)
// This message is used by a peer acting as a Client to send a AAR
// to the Diameter application and process the corresponding answer.
//
class AARreq : public FDMessageRequest
{
public:
    AARreq( Application &app );
    virtual ~AARreq();

    virtual Void processAnswer( FDMessageAnswer &ans );
 
    Application &getApplication() { return m_app; }
    Dictionary &getDict();
    const std::string &getSessionId() { return m_session.getSessionId(); }
    Void addSessionId( FDDictionaryEntryAVP &deSessionId ) { m_session.addSessionId( *this, deSessionId ); }

private:
    AARreq();
    Application &m_app;
    FDSession m_session;
};
 
//Forward declaration of Application;
class Application;

//
// DIAMETER REQUEST Processing - SessionTerminationRequest (Application / Receiver)
// This message is used by a peer acting as the application to listen for
// STR request from Clients.
//-
class STRcmd : public FDCommandRequest
{
public:
    STRcmd( Application &app );
    ~STRcmd();

    virtual Int process( FDMessageRequest *req );

    Application &getApplication() { return m_app; }
    Dictionary &getDict();

private:
    STRcmd();

    Application &m_app;
};

//
// DIAMETER REQUEST - SessionTerminationRequest (Client / Sender)
// This message is used by a peer acting as a Client to send a STR
// to the Diameter application and process the corresponding answer.
//
class STRreq : public FDMessageRequest
{
public:
    STRreq( Application &app );
    virtual ~STRreq();

    virtual Void processAnswer( FDMessageAnswer &ans );
 
    Application &getApplication() { return m_app; }
    Dictionary &getDict();
    const std::string &getSessionId() { return m_session.getSessionId(); }
    Void addSessionId( FDDictionaryEntryAVP &deSessionId ) { m_session.addSessionId( *this, deSessionId ); }

private:
    STRreq();
    Application &m_app;
    FDSession m_session;
};
 
//Forward declaration of Application;
class Application;

//
// DIAMETER REQUEST Processing - AbortSessionRequest (Application / Receiver)
// This message is used by a peer acting as the application to listen for
// ASR request from Clients.
//-
class ASRcmd : public FDCommandRequest
{
public:
    ASRcmd( Application &app );
    ~ASRcmd();

    virtual Int process( FDMessageRequest *req );

    Application &getApplication() { return m_app; }
    Dictionary &getDict();

private:
    ASRcmd();

    Application &m_app;
};

//
// DIAMETER REQUEST - AbortSessionRequest (Client / Sender)
// This message is used by a peer acting as a Client to send a ASR
// to the Diameter application and process the corresponding answer.
//
class ASRreq : public FDMessageRequest
{
public:
    ASRreq( Application &app );
    virtual ~ASRreq();

    virtual Void processAnswer( FDMessageAnswer &ans );
 
    Application &getApplication() { return m_app; }
    Dictionary &getDict();
    const std::string &getSessionId() { return m_session.getSessionId(); }
    Void addSessionId( FDDictionaryEntryAVP &deSessionId ) { m_session.addSessionId( *this, deSessionId ); }

private:
    ASRreq();
    Application &m_app;
    FDSession m_session;
};
 
//Forward declaration of Application;
class Application;

//
// DIAMETER REQUEST Processing - ReAuthRequest (Application / Receiver)
// This message is used by a peer acting as the application to listen for
// RAR request from Clients.
//-
class RARcmd : public FDCommandRequest
{
public:
    RARcmd( Application &app );
    ~RARcmd();

    virtual Int process( FDMessageRequest *req );

    Application &getApplication() { return m_app; }
    Dictionary &getDict();

private:
    RARcmd();

    Application &m_app;
};

//
// DIAMETER REQUEST - ReAuthRequest (Client / Sender)
// This message is used by a peer acting as a Client to send a RAR
// to the Diameter application and process the corresponding answer.
//
class RARreq : public FDMessageRequest
{
public:
    RARreq( Application &app );
    virtual ~RARreq();

    virtual Void processAnswer( FDMessageAnswer &ans );
 
    Application &getApplication() { return m_app; }
    Dictionary &getDict();
    const std::string &getSessionId() { return m_session.getSessionId(); }
    Void addSessionId( FDDictionaryEntryAVP &deSessionId ) { m_session.addSessionId( *this, deSessionId ); }

private:
    RARreq();
    Application &m_app;
    FDSession m_session;
};
 

class ApplicationBase : public FDApplication
{
public:
    ApplicationBase();
    ~ApplicationBase();

    Dictionary &getDict() { return m_dict; }

private:
    Dictionary m_dict;
};

//
// Extractor Patterns
//
//    Single occurrance AVP (not grouped) is an instance of FDExtractorAvp
//    Multi-occurrance AVP (not grouped) is an instance of FDExtractorAvpList
//    Single occurance grouped AVP corresonds to a class that is derived from FDExtractor
//        example: class AccountingRequestExtractor
//    Multi-Occurance grouped AVP corresponds to a class that is derived from FDExtractorList
//        example: class SubscriptionIdExtractorList
//
class AmbrExtractor : public FDExtractor
{
 public:
    AmbrExtractor( FDExtractor &parent, Dictionary &dict );
    ~AmbrExtractor();

    FDExtractorAvp max_requested_bandwidth_ul;
    FDExtractorAvp max_requested_bandwidth_dl;
    FDExtractorAvp extended_max_requested_bw_ul;
    FDExtractorAvp extended_max_requested_bw_dl;
};

class AreaScopeExtractor : public FDExtractor
{
 public:
    AreaScopeExtractor( FDExtractor &parent, Dictionary &dict );
    ~AreaScopeExtractor();

    FDExtractorAvpList cell_global_identity;
    FDExtractorAvpList e_utran_cell_global_identity;
    FDExtractorAvpList routing_area_identity;
    FDExtractorAvpList location_area_identity;
    FDExtractorAvpList tracking_area_identity;
};

class MbsfnAreaExtractor : public FDExtractor
{
 public:
    MbsfnAreaExtractor( FDExtractor &parent, Dictionary &dict );
    ~MbsfnAreaExtractor();

    FDExtractorAvp mbsfn_area_id;
    FDExtractorAvp carrier_frequency;
};

class MbsfnAreaExtractorList : public FDExtractorList
{
 public:
    MbsfnAreaExtractorList( FDExtractor &parent, Dictionary &dict );
    ~MbsfnAreaExtractorList();

    FDExtractor *createExtractor() { return new MbsfnAreaExtractor( getParent(), m_dict ); }
    std::list<MbsfnAreaExtractor*> &getList() { return (std::list<MbsfnAreaExtractor*>&)FDExtractorList::getList(); }

 private:

    Dictionary &m_dict;
};

class MdtConfigurationExtractor : public FDExtractor
{
 public:
    MdtConfigurationExtractor( FDExtractor &parent, Dictionary &dict );
    ~MdtConfigurationExtractor();

    FDExtractorAvp job_type;
    AreaScopeExtractor area_scope;
    FDExtractorAvp list_of_measurements;
    FDExtractorAvp reporting_trigger;
    FDExtractorAvp report_interval;
    FDExtractorAvp report_amount;
    FDExtractorAvp event_threshold_rsrp;
    FDExtractorAvp event_threshold_rsrq;
    FDExtractorAvp logging_interval;
    FDExtractorAvp logging_duration;
    FDExtractorAvp measurement_period_lte;
    FDExtractorAvp measurement_period_umts;
    FDExtractorAvp collection_period_rrm_lte;
    FDExtractorAvp collection_period_rrm_umts;
    FDExtractorAvp positioning_method;
    FDExtractorAvp measurement_quantity;
    FDExtractorAvp event_threshold_event_1f;
    FDExtractorAvp event_threshold_event_1i;
    FDExtractorAvpList mdt_allowed_plmn_id;
    MbsfnAreaExtractorList mbsfn_area;
};

class QosProfileTemplateExtractor : public FDExtractor
{
 public:
    QosProfileTemplateExtractor( FDExtractor &parent, Dictionary &dict );
    ~QosProfileTemplateExtractor();

    FDExtractorAvp vendor_id;
    FDExtractorAvp qos_profile_id;
};

class QosProfileTemplateExtractorList : public FDExtractorList
{
 public:
    QosProfileTemplateExtractorList( FDExtractor &parent, Dictionary &dict );
    ~QosProfileTemplateExtractorList();

    FDExtractor *createExtractor() { return new QosProfileTemplateExtractor( getParent(), m_dict ); }
    std::list<QosProfileTemplateExtractor*> &getList() { return (std::list<QosProfileTemplateExtractor*>&)FDExtractorList::getList(); }

 private:

    Dictionary &m_dict;
};

class QosCapabilityExtractor : public FDExtractor
{
 public:
    QosCapabilityExtractor( FDExtractor &parent, Dictionary &dict );
    ~QosCapabilityExtractor();

    QosProfileTemplateExtractorList qos_profile_template;
};

class WlanOffloadabilityExtractor : public FDExtractor
{
 public:
    WlanOffloadabilityExtractor( FDExtractor &parent, Dictionary &dict );
    ~WlanOffloadabilityExtractor();

    FDExtractorAvp wlan_offloadability_eutran;
    FDExtractorAvp wlan_offloadability_utran;
};

class AllocationRetentionPriorityExtractor : public FDExtractor
{
 public:
    AllocationRetentionPriorityExtractor( FDExtractor &parent, Dictionary &dict );
    ~AllocationRetentionPriorityExtractor();

    FDExtractorAvp priority_level;
    FDExtractorAvp pre_emption_capability;
    FDExtractorAvp pre_emption_vulnerability;
};

class EpsSubscribedQosProfileExtractor : public FDExtractor
{
 public:
    EpsSubscribedQosProfileExtractor( FDExtractor &parent, Dictionary &dict );
    ~EpsSubscribedQosProfileExtractor();

    FDExtractorAvp qos_class_identifier;
    AllocationRetentionPriorityExtractor allocation_retention_priority;
};

class Mip6AgentInfoExtractor : public FDExtractor
{
 public:
    Mip6AgentInfoExtractor( FDExtractor &parent, Dictionary &dict );
    ~Mip6AgentInfoExtractor();

    FDExtractorAvpList mip_home_agent_address;
    FDExtractorAvp mip_home_agent_host;
    FDExtractorAvp mip6_home_link_prefix;
};

class SpecificApnInfoExtractor : public FDExtractor
{
 public:
    SpecificApnInfoExtractor( FDExtractor &parent, Dictionary &dict );
    ~SpecificApnInfoExtractor();

    FDExtractorAvp service_selection;
    Mip6AgentInfoExtractor mip6_agent_info;
    FDExtractorAvp visited_network_identifier;
};

class SpecificApnInfoExtractorList : public FDExtractorList
{
 public:
    SpecificApnInfoExtractorList( FDExtractor &parent, Dictionary &dict );
    ~SpecificApnInfoExtractorList();

    FDExtractor *createExtractor() { return new SpecificApnInfoExtractor( getParent(), m_dict ); }
    std::list<SpecificApnInfoExtractor*> &getList() { return (std::list<SpecificApnInfoExtractor*>&)FDExtractorList::getList(); }

 private:

    Dictionary &m_dict;
};

class ApnConfigurationExtractor : public FDExtractor
{
 public:
    ApnConfigurationExtractor( FDExtractor &parent, Dictionary &dict );
    ~ApnConfigurationExtractor();

    FDExtractorAvp context_identifier;
    FDExtractorAvpList served_party_ip_address;
    FDExtractorAvp pdn_type;
    FDExtractorAvp service_selection;
    EpsSubscribedQosProfileExtractor eps_subscribed_qos_profile;
    FDExtractorAvp vplmn_dynamic_address_allowed;
    Mip6AgentInfoExtractor mip6_agent_info;
    FDExtractorAvp visited_network_identifier;
    FDExtractorAvp pdn_gw_allocation_type;
    FDExtractorAvp tgpp_charging_characteristics;
    AmbrExtractor ambr;
    SpecificApnInfoExtractorList specific_apn_info;
    FDExtractorAvp apn_oi_replacement;
    FDExtractorAvp sipto_permission;
    FDExtractorAvp lipa_permission;
    FDExtractorAvp restoration_priority;
    FDExtractorAvp sipto_local_network_permission;
    WlanOffloadabilityExtractor wlan_offloadability;
    FDExtractorAvp non_ip_pdn_type_indicator;
    FDExtractorAvp non_ip_data_delivery_mechanism;
    FDExtractorAvp scef_id;
    FDExtractorAvp scef_realm;
    FDExtractorAvp preferred_data_mode;
    FDExtractorAvp pdn_connection_continuity;
    FDExtractorAvp rds_indicator;
    FDExtractorAvp interworking_5gs_indicator;
};

class OcOlrExtractor : public FDExtractor
{
 public:
    OcOlrExtractor( FDExtractor &parent, Dictionary &dict );
    ~OcOlrExtractor();

    FDExtractorAvp oc_sequence_number;
    FDExtractorAvp oc_report_type;
    FDExtractorAvp oc_reduction_percentage;
    FDExtractorAvp oc_validity_duration;
};

class TraceDataExtractor : public FDExtractor
{
 public:
    TraceDataExtractor( FDExtractor &parent, Dictionary &dict );
    ~TraceDataExtractor();

    FDExtractorAvp trace_reference;
    FDExtractorAvp trace_depth;
    FDExtractorAvp trace_ne_type_list;
    FDExtractorAvp trace_interface_list;
    FDExtractorAvp trace_event_list;
    FDExtractorAvp omc_id;
    FDExtractorAvp trace_collection_entity;
    MdtConfigurationExtractor mdt_configuration;
};

class SupportedFeaturesExtractor : public FDExtractor
{
 public:
    SupportedFeaturesExtractor( FDExtractor &parent, Dictionary &dict );
    ~SupportedFeaturesExtractor();

    FDExtractorAvp vendor_id;
    FDExtractorAvp feature_list_id;
    FDExtractorAvp feature_list;
};

class AccessNetworkInfoExtractor : public FDExtractor
{
 public:
    AccessNetworkInfoExtractor( FDExtractor &parent, Dictionary &dict );
    ~AccessNetworkInfoExtractor();

    FDExtractorAvp ssid;
    FDExtractorAvp bssid;
    FDExtractorAvp location_information;
    FDExtractorAvp location_data;
    FDExtractorAvp operator_name;
    FDExtractorAvp logical_access_id;
};

class LoadExtractor : public FDExtractor
{
 public:
    LoadExtractor( FDExtractor &parent, Dictionary &dict );
    ~LoadExtractor();

    FDExtractorAvp load_type;
    FDExtractorAvp load_value;
    FDExtractorAvp sourceid;
};

class OcSupportedFeaturesExtractor : public FDExtractor
{
 public:
    OcSupportedFeaturesExtractor( FDExtractor &parent, Dictionary &dict );
    ~OcSupportedFeaturesExtractor();

    FDExtractorAvp oc_feature_vector;
};

class TerminalInformationExtractor : public FDExtractor
{
 public:
    TerminalInformationExtractor( FDExtractor &parent, Dictionary &dict );
    ~TerminalInformationExtractor();

    FDExtractorAvp imei;
    FDExtractorAvp software_version;
};

class SubscriptionIdExtractor : public FDExtractor
{
 public:
    SubscriptionIdExtractor( FDExtractor &parent, Dictionary &dict );
    ~SubscriptionIdExtractor();

    FDExtractorAvp subscription_id_type;
    FDExtractorAvp subscription_id_data;
};

class EmergencyInfoExtractor : public FDExtractor
{
 public:
    EmergencyInfoExtractor( FDExtractor &parent, Dictionary &dict );
    ~EmergencyInfoExtractor();

    Mip6AgentInfoExtractor mip6_agent_info;
};

class TraceInfoExtractor : public FDExtractor
{
 public:
    TraceInfoExtractor( FDExtractor &parent, Dictionary &dict );
    ~TraceInfoExtractor();

    TraceDataExtractor trace_data;
    FDExtractorAvp trace_reference;
};

class SupportedFeaturesExtractorList : public FDExtractorList
{
 public:
    SupportedFeaturesExtractorList( FDExtractor &parent, Dictionary &dict );
    ~SupportedFeaturesExtractorList();

    FDExtractor *createExtractor() { return new SupportedFeaturesExtractor( getParent(), m_dict ); }
    std::list<SupportedFeaturesExtractor*> &getList() { return (std::list<SupportedFeaturesExtractor*>&)FDExtractorList::getList(); }

 private:

    Dictionary &m_dict;
};

class DiameterEapRequestExtractor : public FDExtractor
{
 public:
    DiameterEapRequestExtractor( FDMessage &msg, Dictionary &dict );
    ~DiameterEapRequestExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp destination_realm;
    FDExtractorAvp destination_host;
    FDExtractorAvp auth_request_type;
    FDExtractorAvp eap_payload;
    FDExtractorAvp user_name;
    FDExtractorAvp rat_type;
    FDExtractorAvp service_selection;
    FDExtractorAvp mip6_feature_vector;
    QosCapabilityExtractor qos_capability;
    FDExtractorAvp visited_network_identifier;
    FDExtractorAvp aaa_failure_indication;
    SupportedFeaturesExtractorList supported_features;
    FDExtractorAvp ue_local_ip_address;
    OcSupportedFeaturesExtractor oc_supported_features;
    TerminalInformationExtractor terminal_information;
    FDExtractorAvp emergency_services;
};

class LoadExtractorList : public FDExtractorList
{
 public:
    LoadExtractorList( FDExtractor &parent, Dictionary &dict );
    ~LoadExtractorList();

    FDExtractor *createExtractor() { return new LoadExtractor( getParent(), m_dict ); }
    std::list<LoadExtractor*> &getList() { return (std::list<LoadExtractor*>&)FDExtractorList::getList(); }

 private:

    Dictionary &m_dict;
};

class DiameterEapAnswerExtractor : public FDExtractor
{
 public:
    DiameterEapAnswerExtractor( FDMessage &msg, Dictionary &dict );
    ~DiameterEapAnswerExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp auth_request_type;
    FDExtractorAvp result_code;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp eap_payload;
    FDExtractorAvp user_name;
    FDExtractorAvp eap_master_session_key;
    FDExtractorAvp apn_oi_replacement;
    ApnConfigurationExtractor apn_configuration;
    FDExtractorAvp mip6_feature_vector;
    FDExtractorAvp mobile_node_identifier;
    TraceInfoExtractor trace_info;
    SubscriptionIdExtractor subscription_id;
    FDExtractorAvp session_timeout;
    Mip6AgentInfoExtractor mip6_agent_info;
    FDExtractorAvp tgpp_charging_characteristics;
    FDExtractorAvpList redirect_host;
    SupportedFeaturesExtractorList supported_features;
    OcSupportedFeaturesExtractor oc_supported_features;
    OcOlrExtractor oc_olr;
    LoadExtractorList load;
    AccessNetworkInfoExtractor access_network_info;
    FDExtractorAvp user_location_info_time;
    FDExtractorAvp ue_usage_type;
    EmergencyInfoExtractor emergency_info;
    FDExtractorAvp core_network_restrictions;
};

class AaRequestExtractor : public FDExtractor
{
 public:
    AaRequestExtractor( FDMessage &msg, Dictionary &dict );
    ~AaRequestExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp destination_realm;
    FDExtractorAvp destination_host;
    FDExtractorAvp auth_request_type;
    FDExtractorAvp user_name;
    OcSupportedFeaturesExtractor oc_supported_features;
    FDExtractorAvp aar_flags;
    FDExtractorAvp ue_local_ip_address;
};

class AaAnswerExtractor : public FDExtractor
{
 public:
    AaAnswerExtractor( FDMessage &msg, Dictionary &dict );
    ~AaAnswerExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp auth_request_type;
    FDExtractorAvp result_code;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp user_name;
    FDExtractorAvp apn_oi_replacement;
    ApnConfigurationExtractor apn_configuration;
    TraceInfoExtractor trace_info;
    SubscriptionIdExtractor subscription_id;
    FDExtractorAvp tgpp_charging_characteristics;
    FDExtractorAvp session_timeout;
    OcSupportedFeaturesExtractor oc_supported_features;
    OcOlrExtractor oc_olr;
    LoadExtractorList load;
    AccessNetworkInfoExtractor access_network_info;
    FDExtractorAvp user_location_info_time;
};

class SessionTerminationRequestExtractor : public FDExtractor
{
 public:
    SessionTerminationRequestExtractor( FDMessage &msg, Dictionary &dict );
    ~SessionTerminationRequestExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp destination_realm;
    FDExtractorAvp destination_host;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp termination_cause;
    FDExtractorAvp user_name;
    OcSupportedFeaturesExtractor oc_supported_features;
};

class SessionTerminationAnswerExtractor : public FDExtractor
{
 public:
    SessionTerminationAnswerExtractor( FDMessage &msg, Dictionary &dict );
    ~SessionTerminationAnswerExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp result_code;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    OcSupportedFeaturesExtractor oc_supported_features;
    OcOlrExtractor oc_olr;
    LoadExtractorList load;
};

class AbortSessionRequestExtractor : public FDExtractor
{
 public:
    AbortSessionRequestExtractor( FDMessage &msg, Dictionary &dict );
    ~AbortSessionRequestExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp destination_realm;
    FDExtractorAvp destination_host;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp user_name;
    FDExtractorAvp auth_session_state;
};

class AbortSessionAnswerExtractor : public FDExtractor
{
 public:
    AbortSessionAnswerExtractor( FDMessage &msg, Dictionary &dict );
    ~AbortSessionAnswerExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp result_code;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
};

class ReAuthRequestExtractor : public FDExtractor
{
 public:
    ReAuthRequestExtractor( FDMessage &msg, Dictionary &dict );
    ~ReAuthRequestExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp destination_realm;
    FDExtractorAvp destination_host;
    FDExtractorAvp auth_application_id;
    FDExtractorAvp re_auth_request_type;
    FDExtractorAvp user_name;
};

class ReAuthAnswerExtractor : public FDExtractor
{
 public:
    ReAuthAnswerExtractor( FDMessage &msg, Dictionary &dict );
    ~ReAuthAnswerExtractor();

    FDExtractorAvp session_id;
    FDExtractorAvp drmp;
    FDExtractorAvp result_code;
    FDExtractorAvp origin_host;
    FDExtractorAvp origin_realm;
    FDExtractorAvp user_name;
};


}

#endif // __SWM_H

