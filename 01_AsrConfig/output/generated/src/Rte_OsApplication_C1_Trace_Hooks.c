// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTE - RealTimeEnvironment
/// @file  Rte_xxx_Application_xxx_Trace_Hooks.c
/// @brief This file contains all the pre- and postHookFunctions of the runables called in tasks of the related application.
///        Note: This file is generated by the RteStandardRtaInstrGenerator. Therefore it must not be altered in the sections between the
///              startTag and the related endTag eg. ___GENERATOR_TAG___XXX___SECTION_START___, ___GENERATOR_TAG___XXX___SECTION_END___
///              as these parts are overwritten at next generatorRun. But code can be added manually outside of these sections. This applies also
///              to the generated functions: Before the startTag and after the endTag code can be added manually but not in between these two tags.

#include <Rte_Trace_Hooks.h>
#include <Std_Types.h>
#include <Os.h>
#include <rta.h>

/* The following GENERATOR_TAG indicates the start of the implementation of all the traceHoocFunctions.
 * All the lines above the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 * ___GENERATOR_TAG___TRACE_HOOK_FUNCTIONS___SECTION_START___ */

/* All traceHooks for Core1_OsTask_Appl_10ms. [SECTION_START] ********************************************************************/ 
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_MainFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms, RTE_Core1OsTaskAppl10ms_FctAdapter_Main, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_MainFunction_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_MainFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms, RTE_Core1OsTaskAppl10ms_FctAdapter_Main, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_MainFunction_Return */



FUNC(void, RTE_APPL_CODE) Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_MainFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms, RTE_Core1OsTaskAppl10ms_RtaAdapter_C1_Main, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_MainFunction_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_MainFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms, RTE_Core1OsTaskAppl10ms_RtaAdapter_C1_Main, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_MainFunction_Return */



FUNC(void, RTE_APPL_CODE) SchM_Schedulable_WdgM_1_CORE_1_MainFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms, RTE_Core1OsTaskAppl10ms_WdgM_1_CORE_1_Main, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_WdgM_1_CORE_1_MainFunction_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_WdgM_1_CORE_1_MainFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Appl_10ms, RTE_Core1OsTaskAppl10ms_WdgM_1_CORE_1_Main, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_WdgM_1_CORE_1_MainFunction_Return */



/* All traceHooks for Core1_OsTask_Appl_10ms. [SECTION_END] ********************************************************************/ 



/* All traceHooks for Core1_OsTask_Bsw_20ms. [SECTION_START] ********************************************************************/ 
FUNC(void, RTE_APPL_CODE) SchM_Schedulable_EcuM_1_Core_1_MainFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_EcuM_1_Core_1_MainFunction_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_EcuM_1_Core_1_MainFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_EcuM_1_Core_1_MainFunction_Return */



FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MainFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MainFunction_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MainFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MainFunction_Return */



FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Core1_Esm_Core1_MainFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_Esm_Core1_Esm_Core1_MainFunction_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Core1_Esm_Core1_MainFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_Esm_Core1_Esm_Core1_MainFunction_Return */



FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D_Return */



FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B_Return */



FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D_Return */



FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Bsw_20ms, RTE_Core1OsTaskBsw20ms_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1_Return */



/* All traceHooks for Core1_OsTask_Bsw_20ms. [SECTION_END] ********************************************************************/ 



/* All traceHooks for Core1_OsTask_OperationInovkedProxy. [SECTION_START] ********************************************************************/ 
FUNC(void, RTE_APPL_CODE) SchM_Schedulable_EcuM_1_Core_1_UpdateSleepMode_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_EcuM_1_Core_1_UpdateSleepMode_Start */

FUNC(void, RTE_APPL_CODE) SchM_Schedulable_EcuM_1_Core_1_UpdateSleepMode_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* SchM_Schedulable_EcuM_1_Core_1_UpdateSleepMode_Return */



/* All traceHooks for Core1_OsTask_OperationInovkedProxy. [SECTION_END] ********************************************************************/ 



/* All traceHooks for Core1_InitTask_Appl. [SECTION_START] ********************************************************************/ 
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_InitFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_InitTask_Appl, RTE_Core1InitTaskAppl_RtaAdapter_C1_InitFunction, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_InitFunction_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_InitFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_InitTask_Appl, RTE_Core1InitTaskAppl_RtaAdapter_C1_InitFunction, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_RtaAdapter_C1_RtaAdapter_C1_InitFunction_Return */



FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Core1_Esm_Core1_InitFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_Esm_Core1_Esm_Core1_InitFunction_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Core1_Esm_Core1_InitFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_Esm_Core1_Esm_Core1_InitFunction_Return */



FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_InitFunction_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_InitFunction_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_InitFunction_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_InitFunction_Return */



/* All traceHooks for Core1_InitTask_Appl. [SECTION_END] ********************************************************************/ 



/* All traceHooks for Core1_OsTask_Appl_60ms. [SECTION_START] ********************************************************************/ 
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_FCTSen_Exec_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Appl_60ms, RTE_Core1OsTaskAppl60ms_FctAdapter_FCTSen_Exec, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_FCTSen_Exec_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_FCTSen_Exec_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Appl_60ms, RTE_Core1OsTaskAppl60ms_FctAdapter_FCTSen_Exec, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_FCTSen_Exec_Return */



/* All traceHooks for Core1_OsTask_Appl_60ms. [SECTION_END] ********************************************************************/ 



/* All traceHooks for Core1_OsTask_Appl_20ms. [SECTION_START] ********************************************************************/ 
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_FCTVeh_Exec_Start(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOSTART, RTE_GLOBAL_ID_Core1_OsTask_Appl_20ms, RTE_Core1OsTaskAppl20ms_FctAdapter_FCTVeh_Exec, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_FCTVeh_Exec_Start */

FUNC(void, RTE_APPL_CODE) Rte_Runnable_FctAdapter_FctAdapter_FCTVeh_Exec_Return(void) 
{
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  RTA_v_AddEvent(RTA_EVT_ALGOEND, RTE_GLOBAL_ID_Core1_OsTask_Appl_20ms, RTE_Core1OsTaskAppl20ms_FctAdapter_FCTVeh_Exec, 0u); 

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */

} /* Rte_Runnable_FctAdapter_FctAdapter_FCTVeh_Exec_Return */



/* All traceHooks for Core1_OsTask_Appl_20ms. [SECTION_END] ********************************************************************/ 



/* All traceHooks for runnables called from different tasks. [SECTION_START] ********************************************************************/ 

/* All traceHooks for runnables called from different tasks. [SECTION_END] ********************************************************************/ 

/* ___GENERATOR_TAG___TRACE_HOOK_FUNCTIONS___SECTION_END___
 * The GENERATOR_TAG above indicates the end of the implementation of all the traceHoocFunctions.
 * All the lines below the GENERATOR_TAG will not be changed by the codeGenerator at all.
 * DO NOT change or remove this comment block as it is needed by codeGenerator adding the rtaInstrumentation (GenerateRteStandardRtaInstrumentation)!!!
 */
