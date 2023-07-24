
#ifndef BSWM_TRACE_H
#define BSWM_TRACE_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
#ifndef DBG_BSWM_INIT_ENTRY
/** \brief Entry point of function BswM_Init */
#define DBG_BSWM_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_INIT_EXIT
/** \brief Exit point of function BswM_Init */
#define DBG_BSWM_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_EXIT
/** \brief Exit point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_BSWM_DEINIT_ENTRY
/** \brief Entry point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_ENTRY()
#endif

#ifndef DBG_BSWM_DEINIT_EXIT
/** \brief Exit point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_EXIT()
#endif

#ifndef DBG_BSWM_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY()
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT()
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY
/** \brief Entry point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT
/** \brief Exit point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_ENTRY(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_EXIT(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NMIF_CARWAKEUPINDICATION_ENTRY
/** \brief Entry point of function BswM_NmIf_CarWakeUpIndication */
#define DBG_BSWM_NMIF_CARWAKEUPINDICATION_ENTRY(a)
#endif

#ifndef DBG_BSWM_NMIF_CARWAKEUPINDICATION_EXIT
/** \brief Exit point of function BswM_NmIf_CarWakeUpIndication */
#define DBG_BSWM_NMIF_CARWAKEUPINDICATION_EXIT(a)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY
/** \brief Entry point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY(a)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT
/** \brief Exit point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY
/** \brief Entry point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT
/** \brief Exit point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT(a,b)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY
/** \brief Entry point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT
/** \brief Exit point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_MAINFUNCTION_ENTRY
/** \brief Entry point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_BSWM_MAINFUNCTION_EXIT
/** \brief Exit point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_EXIT()
#endif

#ifndef DBG_BSWM_CORE_INIT_ENTRY
/** \brief Entry point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_CORE_INIT_EXIT
/** \brief Exit point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_EXIT()
#endif

#ifndef DBG_BSWM_PARTITION_INIT_ENTRY
/** \brief Entry point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_PARTITION_INIT_EXIT
/** \brief Exit point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_PB_INIT_ENTRY
/** \brief Entry point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_ENTRY(a,b,c)
#endif

#ifndef DBG_BSWM_PB_INIT_EXIT
/** \brief Exit point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_EXIT(a,b,c,d)
#endif

#ifndef DBG_BSWM_RT_INIT_ENTRY
/** \brief Entry point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_RT_INIT_EXIT
/** \brief Exit point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C0_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C0_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C0_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C0_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C0_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C0_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C1_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C1_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C1_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C1_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C1_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C1_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C2_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C2_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C2_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C2_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C2_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C2_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C3_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C3_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C3_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C3_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C3_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C3_INIT_EXIT()
#endif

/* Dynamically generated macros */
#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEA_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEA_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEA_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEB_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEB_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEB_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_RUNTWO_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOA_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOA_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOA_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOB_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOB_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOB_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPUBLICCAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanNoComPublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPUBLICCAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPUBLICCAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanNoComPublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPUBLICCAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPUBLICCAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPUBLICCAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPUBLICCAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPUBLICCAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPUBLICCAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanFullComPublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPUBLICCAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPUBLICCAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanFullComPublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPUBLICCAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_PrpShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_PrpShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPRIVATECAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanNoComPrivateCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPRIVATECAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPRIVATECAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanNoComPrivateCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPRIVATECAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPRIVATECAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPrivateCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPRIVATECAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPRIVATECAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPrivateCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPRIVATECAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPRIVATECAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanFullComPrivateCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPRIVATECAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPRIVATECAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanFullComPrivateCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPRIVATECAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWMACTION_WAKUPVALIDATION_PUBLICCAN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswMAction_WakupValidation_PublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWMACTION_WAKUPVALIDATION_PUBLICCAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWMACTION_WAKUPVALIDATION_PUBLICCAN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswMAction_WakupValidation_PublicCan */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWMACTION_WAKUPVALIDATION_PUBLICCAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUP_TWO_D_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_STARTUP_TWO_D */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUP_TWO_D_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUP_TWO_D_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_STARTUP_TWO_D */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUP_TWO_D_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GO_OFF_ONE_D_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_GO_OFF_ONE_D */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GO_OFF_ONE_D_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GO_OFF_ONE_D_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_GO_OFF_ONE_D */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GO_OFF_ONE_D_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280301_DISRXTX_NORM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280301_DisRxTx_Norm */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280301_DISRXTX_NORM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280301_DISRXTX_NORM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280301_DisRxTx_Norm */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280301_DISRXTX_NORM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280001_ENRXTX_NORM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280001_EnRxTx_Norm */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280001_ENRXTX_NORM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280001_ENRXTX_NORM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280001_EnRxTx_Norm */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280001_ENRXTX_NORM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280302_DISRXTX_NM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280302_DisRxTx_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280302_DISRXTX_NM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280302_DISRXTX_NM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280302_DisRxTx_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280302_DISRXTX_NM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280002_ENRXTX_NM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280002_EnRxTx_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280002_ENRXTX_NM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280002_ENRXTX_NM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_0x280002_EnRxTx_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280002_ENRXTX_NM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_USERCALLOUT_COMCO_INIT_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_UserCallout_Comco_Init */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_USERCALLOUT_COMCO_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_USERCALLOUT_COMCO_INIT_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_UserCallout_Comco_Init */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_USERCALLOUT_COMCO_INIT_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_ACTIVE_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_Active */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_ACTIVE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_ACTIVE_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_Active */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_ACTIVE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_INACTIVE_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_InActive */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_INACTIVE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_INACTIVE_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_InActive */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_INACTIVE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_ACTIVE_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_Active */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_ACTIVE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_ACTIVE_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_Active */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_ACTIVE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_INACTIVE_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_InActive */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_INACTIVE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_INACTIVE_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_InActive */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_INACTIVE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_EXECUTE_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_EXECUTE */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_EXECUTE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_EXECUTE_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_EXECUTE */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_EXECUTE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_HARD_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_HARD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_HARD_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_HARD_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_HARD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_HARD_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_SOFT_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_SOFT */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_SOFT_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_SOFT_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_SOFT */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_SOFT_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_JUMPTOSYSSUPPLIERBOOTLOADER_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_JUMPTOSYSSUPPLIERBOOTLOADER_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_JUMPTOSYSSUPPLIERBOOTLOADER_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_JUMPTOSYSSUPPLIERBOOTLOADER_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_BUSOFF_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_Busoff */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_BUSOFF_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_BUSOFF_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_Busoff */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_BUSOFF_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_FULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_FullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_FULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_FULLCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_FullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_FULLCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_SLIENTCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_SlientCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_SLIENTCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_SLIENTCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_SlientCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_SLIENTCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_NOCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_NoCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_NOCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_NOCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_NoCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_NOCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_BUSOFF_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_Busoff */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_BUSOFF_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_BUSOFF_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_Busoff */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_BUSOFF_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_FULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_FullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_FULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_FULLCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_FullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_FULLCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_SLIENTCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_SlientCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_SLIENTCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_SLIENTCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_SlientCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_SLIENTCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_NOCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_NoCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_NOCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_NOCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_NoCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_NOCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_C1_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown_C1 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_C1_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_C1_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown_C1 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_C1_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_NM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_NM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_NM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_NM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_NM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_NM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_NM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM_NM */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_NM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_PUBLICCAN_BUSOFF_RECORVERY_TJA1043_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_Act_PublicCAN_BusOff_Recorvery_Tja1043 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_PUBLICCAN_BUSOFF_RECORVERY_TJA1043_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_PUBLICCAN_BUSOFF_RECORVERY_TJA1043_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_Act_PublicCAN_BusOff_Recorvery_Tja1043 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_PUBLICCAN_BUSOFF_RECORVERY_TJA1043_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOC_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_StartupTwoC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOC_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOC_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_StartupTwoC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOC_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOD_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_StartupTwoD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOD_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOD_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_StartupTwoD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUPTWOD_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONEC_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_GoOffOneC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONEC_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONEC_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_GoOffOneC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONEC_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONED_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_GoOffOneD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONED_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONED_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_GoOffOneD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_GOOFFONED_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_PREPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_PREPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_PREPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_PREPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOC_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_StartupTwoC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOC_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOC_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_StartupTwoC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOC_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONEC_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_GoOffOneC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONEC_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONEC_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_GoOffOneC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONEC_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONED_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_GoOffOneD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONED_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONED_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_GoOffOneD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONED_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_PREPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_PREPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_PREPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_PREPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOD_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_StartupTwoD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOD_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOD_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_StartupTwoD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOD_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOC_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_StartupTwoC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOC_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOC_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_StartupTwoC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOC_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONEC_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_GoOffOneC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONEC_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONEC_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_GoOffOneC */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONEC_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONED_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_GoOffOneD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONED_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONED_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_GoOffOneD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_GOOFFONED_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_PREPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_PREPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_PREPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_PrepShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_PREPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOD_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_StartupTwoD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOD_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOD_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_StartupTwoD */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUPTWOD_EXIT()
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[end of file]===========================================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_TRACE_H */
/*==================[end of file]============================================*/

