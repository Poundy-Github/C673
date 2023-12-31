// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTE - RealTimeEnvironment
/// @file  Rte_Trace_Hooks.h
/// @brief This file contains defines and localID-enums required for the RTA instrumentation of the RTE. 
///        Note: This file is generated by the RteStandardRtaInstrGenerator. Therefore it must not be altered in the sections between the 
///              startTag and the related endTag eg. ___GENERATOR_TAG___XXX___SECTION_START___, ___GENERATOR_TAG___XXX___SECTION_END___
///              as these parts are overwritten at next generatorRun. But code can be added manually outside of these sections. It is also  
///              possible to extend the localID-enumerations manually but this has to be done AFTER the related generatorTag!
 

#ifndef RTE_TRACE_HOOKS_INCLUDED
#define RTE_TRACE_HOOKS_INCLUDED


/* The following GENERATOR_TAG indicates the start of the section where all defines of the globalIDs used by RTE are implemented.
 * DO NOT DO manually codeChanges within this section. 
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!! 
 * ___GENERATOR_TAG___GLOBAL_ID_DEFINES___SECTION_START___ */ 

#define RTE_GLOBAL_ID_Core0_OsTask_Bsw_20ms                ((RTA_t_GlobalID)214)
#define RTE_GLOBAL_ID_Core0_OsTask_Bsw_5ms                 ((RTA_t_GlobalID)200)
#define RTE_GLOBAL_ID_Core0_OsTask_Bsw_10ms                ((RTA_t_GlobalID)213)
#define RTE_GLOBAL_ID_Core0_InitTask_Appl                  ((RTA_t_GlobalID)211)
#define RTE_GLOBAL_ID_Core0_OsTask_Appl_5ms                ((RTA_t_GlobalID)215)
#define RTE_GLOBAL_ID_Core0_OsTask_Appl_10ms               ((RTA_t_GlobalID)216)
#define RTE_GLOBAL_ID_Core0_OsTask_OperationInovkedProxy   ((RTA_t_GlobalID)203)
#define RTE_GLOBAL_ID_Core0_OsTask_Appl_20ms               ((RTA_t_GlobalID)201)
#define RTE_GLOBAL_ID_Core0_OsTask_FunctionSafety_5ms      ((RTA_t_GlobalID)212)
#define RTE_GLOBAL_ID_Core0_OsTask_Appl_60ms               ((RTA_t_GlobalID)202)
#define RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms               ((RTA_t_GlobalID)205)
#define RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms                ((RTA_t_GlobalID)204)
#define RTE_GLOBAL_ID_Core1_OsTask_OperationInovkedProxy   ((RTA_t_GlobalID)221)
#define RTE_GLOBAL_ID_Core1_InitTask_Appl                  ((RTA_t_GlobalID)218)
#define RTE_GLOBAL_ID_Core1_OsTask_Appl_60ms               ((RTA_t_GlobalID)220)
#define RTE_GLOBAL_ID_Core1_OsTask_Appl_20ms               ((RTA_t_GlobalID)219)
#define RTE_GLOBAL_ID_Core2_OsTask_Bsw_20ms                ((RTA_t_GlobalID)206)
#define RTE_GLOBAL_ID_Core2_OsTask_OperationInovkedProxy   ((RTA_t_GlobalID)224)
#define RTE_GLOBAL_ID_Core2_InitTask_Appl                  ((RTA_t_GlobalID)223)
#define RTE_GLOBAL_ID_Core2_OsTask_Appl_5ms                ((RTA_t_GlobalID)207)
#define RTE_GLOBAL_ID_Core3_OsTask_Bsw_20ms                ((RTA_t_GlobalID)208)
#define RTE_GLOBAL_ID_Core3_OsTask_OperationInovkedProxy   ((RTA_t_GlobalID)209)
#define RTE_GLOBAL_ID_Core3_InitTask_Appl                  ((RTA_t_GlobalID)226)
#define RTE_GLOBAL_ID_Core3_OsTask_Appl_50ms               ((RTA_t_GlobalID)228)
#define RTE_GLOBAL_ID_Core3_OsTask_Appl_10ms               ((RTA_t_GlobalID)227)
#define RTE_GLOBAL_ID_Core3_OsTask_Appl_60ms               ((RTA_t_GlobalID)229)

/* ___GENERATOR_TAG___GLOBAL_ID_DEFINES___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the section where all defines of the globalIDs used by RTE are implemented.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all. 
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!! 
 */ 




/* The following GENERATOR_TAG indicates the start of the section where all localID-enumerations used by RTE traceHooks are implemented.
 * DO NOT DO manually codeChanges within this section. 
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!! 
 * ___GENERATOR_TAG___LOCAL_ID_ENUM___SECTION_START___ */ 

typedef enum {
  RTE_Core0OsTaskBsw20ms_TaskRuntime   = 0 
  , RTE_Core0OsTaskBsw20ms_ComM_Main_0 = 1 
  , RTE_Core0OsTaskBsw20ms_ComM_Main_1 = 2 
  , RTE_Core0OsTaskBsw20ms_EcuM_Main   = 3 
  , RTE_Core0OsTaskBsw20ms_Xcp_Main    = 4 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskBsw20ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskBsw5ms_TaskRuntime               = 0 
  , RTE_Core0OsTaskBsw5ms_Com_MainRx              = 1 
  , RTE_Core0OsTaskBsw5ms_Com_MainRouteSig        = 2 
  , RTE_Core0OsTaskBsw5ms_Com_MainTx              = 3 
  , RTE_Core0OsTaskBsw5ms_CanTp_Main              = 4 
  , RTE_Core0OsTaskBsw5ms_CanSM_Main              = 5 
  , RTE_Core0OsTaskBsw5ms_CanTSyn_Main            = 6 
  , RTE_Core0OsTaskBsw5ms_Can_17_McmCan_Main_Mode = 7 
  , RTE_Core0OsTaskBsw5ms_Spi_Main_Handling       = 8 
  , RTE_Core0OsTaskBsw5ms_CanNm_Main              = 9 
  , RTE_Core0OsTaskBsw5ms_Nm_Main                 = 10 
  , RTE_Core0OsTaskBsw5ms_Time_Main               = 11 
  , RTE_Core0OsTaskBsw5ms_StbM_Main               = 12 
  , RTE_Core0OsTaskBsw5ms_WdgM_Main               = 13 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskBsw5ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskBsw10ms_TaskRuntime                    = 0 
  , RTE_Core0OsTaskBsw10ms_BswM_1_OsApplication_C0_Main = 1 
  , RTE_Core0OsTaskBsw10ms_Dcm_Main                     = 2 
  , RTE_Core0OsTaskBsw10ms_Dem_Main                     = 3 
  , RTE_Core0OsTaskBsw10ms_FiM_Main                     = 4 
  , RTE_Core0OsTaskBsw10ms_NvM_Main                     = 5 
  , RTE_Core0OsTaskBsw10ms_Fee_Main                     = 6 
  , RTE_Core0OsTaskBsw10ms_Fls_17_Dmu_Main              = 7 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskBsw10ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0InitTaskAppl_TaskRuntime                     = 0 
  , RTE_Core0InitTaskAppl_RtaAdapter_C0_InitFunction    = 1 
  , RTE_Core0InitTaskAppl_Med_InitFunction              = 2 
  , RTE_Core0InitTaskAppl_Sed_InitFunction              = 3 
  , RTE_Core0InitTaskAppl_Cpr_InitFunction              = 4 
  , RTE_Core0InitTaskAppl_Cps_InitFunction              = 5 
  , RTE_Core0InitTaskAppl_Fcu_InitFunction              = 6 
  , RTE_Core0InitTaskAppl_Cdm_InitFunction              = 7 
  , RTE_Core0InitTaskAppl_HlaAdapter_InitFunction       = 8 
  , RTE_Core0InitTaskAppl_TsaAdapter_InitFunction       = 9 
  , RTE_Core0InitTaskAppl_Cdd_HeartbeatDet_InitFunction = 10 
  , RTE_Core0InitTaskAppl_Esm_InitFunction              = 11 
  , RTE_Core0InitTaskAppl_SpiSync_InitFunction          = 12 
  , RTE_Core0InitTaskAppl_FSMon_InitFunction            = 13 
  , RTE_Core0InitTaskAppl_VdyAdapter_InitFunction       = 14 
  , RTE_Core0InitTaskAppl_Dsm_Init                      = 15 
  , RTE_Core0InitTaskAppl_Sdc_InitFunction              = 16 
  , RTE_Core0InitTaskAppl_Time_InitFunction             = 17 
  , RTE_Core0InitTaskAppl_VoltMonI_InitFunction         = 18 
  , RTE_Core0InitTaskAppl_Esh_InitFunction              = 19 
  , RTE_Core0InitTaskAppl_Qsm_InitFunction              = 20 
  , RTE_Core0InitTaskAppl_AebDsInitFunction             = 21 
  , RTE_Core0InitTaskAppl_Logging_InitFunction          = 22 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0InitTaskAppl_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskAppl5ms_TaskRuntime             = 0 
  , RTE_Core0OsTaskAppl5ms_Cdd_HeartbeatDet_Main = 1 
  , RTE_Core0OsTaskAppl5ms_SpiSync_Main          = 2 
  , RTE_Core0OsTaskAppl5ms_CtCdSPI_5ms           = 3 
  , RTE_Core0OsTaskAppl5ms_Sdc_Main_5ms          = 4 
  , RTE_Core0OsTaskAppl5ms_Cdd_EvAdc_Main        = 5 
  , RTE_Core0OsTaskAppl5ms_AebDsMain             = 6 
  , RTE_Core0OsTaskAppl5ms_Logging_Main          = 7 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskAppl5ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskAppl10ms_TaskRuntime               = 0 
  , RTE_Core0OsTaskAppl10ms_ModM_Main               = 1 
  , RTE_Core0OsTaskAppl10ms_Cpr_Main                = 2 
  , RTE_Core0OsTaskAppl10ms_Fcu_Main_Rx             = 3 
  , RTE_Core0OsTaskAppl10ms_Fcu_Main_Tx             = 4 
  , RTE_Core0OsTaskAppl10ms_Cps_Main                = 5 
  , RTE_Core0OsTaskAppl10ms_Fcu_Main                = 6 
  , RTE_Core0OsTaskAppl10ms_Dsm_Main                = 7 
  , RTE_Core0OsTaskAppl10ms_Med_Main                = 8 
  , RTE_Core0OsTaskAppl10ms_Sed_Main                = 9 
  , RTE_Core0OsTaskAppl10ms_Cdm_Main                = 10 
  , RTE_Core0OsTaskAppl10ms_VoltMonI_Main           = 11 
  , RTE_Core0OsTaskAppl10ms_Cpr_DataProcessFunction = 12 
  , RTE_Core0OsTaskAppl10ms_Cps_DataProcessFunction = 13 
  , RTE_Core0OsTaskAppl10ms_Comco_Main              = 14 
  , RTE_Core0OsTaskAppl10ms_Esh_Main                = 15 
  , RTE_Core0OsTaskAppl10ms_Qsm_Main                = 16 
  , RTE_Core0OsTaskAppl10ms_Sdc_Main_10ms           = 17 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskAppl10ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskOperationInovkedProxy_TaskRuntime                                                                                    = 0 
  , RTE_Core0OsTaskOperationInovkedProxy_Det_Rte_ReportError                                                                          = 1 
  , RTE_Core0OsTaskOperationInovkedProxy_EcuM_SelectShutdownTarget                                                                    = 2 
  , RTE_Core0OsTaskOperationInovkedProxy_StbM_GetCurrentTime                                                                          = 3 
  , RTE_Core0OsTaskOperationInovkedProxy_StbM_GetRateDeviation                                                                        = 4 
  , RTE_Core0OsTaskOperationInovkedProxy_StbM_GetTimeBaseStatus                                                                       = 5 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_Exec                     = 6 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_HARD                     = 7 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_JUMPTOBOOTLOADER         = 8 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_JUMPTOSYSSupplBOOTLOADER = 9 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_KEYONOFF                 = 10 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_NONE                     = 11 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_SOFT                     = 12 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_En_RX_TX_NORM         = 13 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_En_RX_Dis_TX_NORM     = 14 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_Dis_RX_En_TX_NORM     = 15 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_Dis_RX_TX_NORM        = 16 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_En_RX_TX_NM           = 17 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_En_RX_Dis_TX_NM       = 18 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_Dis_RX_En_TX_NM       = 19 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_Dis_RX_TX_NM          = 20 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_En_RX_TX_NORM_NM      = 21 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_En_RX_Dis_TX_NORM_NM  = 22 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_Dis_RX_En_TX_NORM_NM  = 23 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmComCtrl_DCM_Dis_RX_TX_NORM_NM     = 24 
  , RTE_Core0OsTaskOperationInovkedProxy_Comco_u_NMWakupFlag_Read                                                                     = 25 
  , RTE_Core0OsTaskOperationInovkedProxy_Time_GetTimeStampMs                                                                          = 26 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_RxReq                          = 27 
  , RTE_Core0OsTaskOperationInovkedProxy_BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_TxReq                          = 28 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskOperationInovkedProxy_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskAppl20ms_TaskRuntime          = 0 
  , RTE_Core0OsTaskAppl20ms_Esm_Main           = 1 
  , RTE_Core0OsTaskAppl20ms_VdyAdapter_Main    = 2 
  , RTE_Core0OsTaskAppl20ms_VdyAdapter_VdyExec = 3 
  , RTE_Core0OsTaskAppl20ms_Sdc_Main_20ms      = 4 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskAppl20ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskFunctionSafety5ms_TaskRuntime   = 0 
  , RTE_Core0OsTaskFunctionSafety5ms_FSMon_Main  = 1 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskFunctionSafety5ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core0OsTaskAppl60ms_TaskRuntime          = 0 
  , RTE_Core0OsTaskAppl60ms_HlaAdapter_Main    = 1 
  , RTE_Core0OsTaskAppl60ms_HlaAdapter_HlaExec = 2 
  , RTE_Core0OsTaskAppl60ms_TsaAdapter_Main    = 3 
  , RTE_Core0OsTaskAppl60ms_TsaAdapter_TsaExec = 4 
  , RTE_Core0OsTaskAppl60ms_RtaAdapter_C0_Main = 5 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core0OsTaskAppl60ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core1OsTaskAppl10ms_TaskRuntime          = 0 
  , RTE_Core1OsTaskAppl10ms_FctAdapter_Main    = 1 
  , RTE_Core1OsTaskAppl10ms_RtaAdapter_C1_Main = 2 
  , RTE_Core1OsTaskAppl10ms_WdgM_1_CORE_1_Main = 3 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core1OsTaskAppl10ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core1OsTaskBsw20ms_TaskRuntime                                                                             = 0 
  , RTE_Core1OsTaskBsw20ms_EcuM_1_Core_1_Main                                                                    = 1 
  , RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_Main                                                          = 2 
  , RTE_Core1OsTaskBsw20ms_Esm_Core1_Main                                                                        = 3 
  , RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D           = 4 
  , RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B          = 5 
  , RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D          = 6 
  , RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1 = 7 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core1OsTaskBsw20ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core1OsTaskOperationInovkedProxy_TaskRuntime                     = 0 
  , RTE_Core1OsTaskOperationInovkedProxy_EcuM_1_Core_1_UpdateSleepMode = 1 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core1OsTaskOperationInovkedProxy_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core1InitTaskAppl_TaskRuntime                  = 0 
  , RTE_Core1InitTaskAppl_RtaAdapter_C1_InitFunction = 1 
  , RTE_Core1InitTaskAppl_Esm_Core1_InitFunction     = 2 
  , RTE_Core1InitTaskAppl_FctAdapter_InitFunction    = 3 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core1InitTaskAppl_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core1OsTaskAppl60ms_TaskRuntime              = 0 
  , RTE_Core1OsTaskAppl60ms_FctAdapter_FCTSen_Exec = 1 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core1OsTaskAppl60ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core1OsTaskAppl20ms_TaskRuntime              = 0 
  , RTE_Core1OsTaskAppl20ms_FctAdapter_FCTVeh_Exec = 1 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core1OsTaskAppl20ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core2OsTaskBsw20ms_TaskRuntime                                                                             = 0 
  , RTE_Core2OsTaskBsw20ms_EcuM_1_Core_2_Main                                                                    = 1 
  , RTE_Core2OsTaskBsw20ms_BswM_1_OsApplication_C2_Main                                                          = 2 
  , RTE_Core2OsTaskBsw20ms_BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D           = 3 
  , RTE_Core2OsTaskBsw20ms_BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B          = 4 
  , RTE_Core2OsTaskBsw20ms_BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D          = 5 
  , RTE_Core2OsTaskBsw20ms_BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1 = 6 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core2OsTaskBsw20ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core2OsTaskOperationInovkedProxy_TaskRuntime                     = 0 
  , RTE_Core2OsTaskOperationInovkedProxy_EcuM_1_Core_2_UpdateSleepMode = 1 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core2OsTaskOperationInovkedProxy_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core2InitTaskAppl_TaskRuntime                  = 0 
  , RTE_Core2InitTaskAppl_RtaAdapter_C2_InitFunction = 1 
  , RTE_Core2InitTaskAppl_Esm_Core2_InitFunction     = 2 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core2InitTaskAppl_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core2OsTaskAppl5ms_TaskRuntime          = 0 
  , RTE_Core2OsTaskAppl5ms_Esm_Core2_Main     = 1 
  , RTE_Core2OsTaskAppl5ms_RtaAdapter_C2_Main = 2 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core2OsTaskAppl5ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core3OsTaskBsw20ms_TaskRuntime                                                                             = 0 
  , RTE_Core3OsTaskBsw20ms_EcuM_1_Core_3_Main                                                                    = 1 
  , RTE_Core3OsTaskBsw20ms_BswM_1_OsApplication_C3_Main                                                          = 2 
  , RTE_Core3OsTaskBsw20ms_Esm_Core3_Main                                                                        = 3 
  , RTE_Core3OsTaskBsw20ms_BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D           = 4 
  , RTE_Core3OsTaskBsw20ms_BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B          = 5 
  , RTE_Core3OsTaskBsw20ms_BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D          = 6 
  , RTE_Core3OsTaskBsw20ms_BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1 = 7 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core3OsTaskBsw20ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core3OsTaskOperationInovkedProxy_TaskRuntime                     = 0 
  , RTE_Core3OsTaskOperationInovkedProxy_EcuM_1_Core_3_UpdateSleepMode = 1 
  , RTE_Core3OsTaskOperationInovkedProxy_CDD_MTSI_Callback             = 2 
  , RTE_Core3OsTaskOperationInovkedProxy_MtsiAdapter_MeasFreezeData    = 3 
  , RTE_Core3OsTaskOperationInovkedProxy_MtsiAdapter_UpdateTaskCycle   = 4 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core3OsTaskOperationInovkedProxy_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core3InitTaskAppl_TaskRuntime                  = 0 
  , RTE_Core3InitTaskAppl_RtaAdapter_C3_InitFunction = 1 
  , RTE_Core3InitTaskAppl_MtsiAdapter_InitFunction   = 2 
  , RTE_Core3InitTaskAppl_Esm_Core3_InitFunction     = 3 
  , RTE_Core3InitTaskAppl_LcfAdapter_InitFunction    = 4 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core3InitTaskAppl_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core3OsTaskAppl50ms_TaskRuntime             = 0 
  , RTE_Core3OsTaskAppl50ms_LcfAdapter_LcfSenExec = 1 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core3OsTaskAppl50ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core3OsTaskAppl10ms_TaskRuntime             = 0 
  , RTE_Core3OsTaskAppl10ms_LcfAdapter_Main       = 1 
  , RTE_Core3OsTaskAppl10ms_LcfAdapter_LcfVehExec = 2 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core3OsTaskAppl10ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

typedef enum {
  RTE_Core3OsTaskAppl60ms_TaskRuntime          = 0 
  , RTE_Core3OsTaskAppl60ms_MtsiAdapter_Main   = 1 
  , RTE_Core3OsTaskAppl60ms_RtaAdapter_C3_Main = 2 
  /* ___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
} RTE_t_Core3OsTaskAppl60ms_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */
/* ___GENERATOR_TAG___LOCAL_ID_ENUM___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the section where all localID-enumerations used by RTE traceHooks are implemented.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all. 
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!! 
 */ 




/* The following GENERATOR_TAG indicates the start of the section where all errors/warnings related to the RTE/RTA configuration are implemented.
 * DO NOT DO manually codeChanges within this section. 
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!! 
 * ___GENERATOR_TAG___ERROR_WARNING_INFO___SECTION_START___ */ 


/* 
No error, no warnings - FINE!! 

*/

/* ___GENERATOR_TAG___ERROR_WARNING_INFO___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the section where errors/warnings related to the RTE/RTA configuration are implemented.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all. 
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!! 
 */ 



#endif //RTE_TRACE_HOOKS_INCLUDED
