// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief In this file the RTA_v_PreIsrHook() and the RTA_v_PreTaskHook() are implemented which have to be called by the OS
///        before starting a task or an interrupt. \n
///        For this file we provide three variants: \n
///        - RTA functionality completely off \n
///        - RTA task instrumentation on but no ISR instrumentation \n
///        - RTA task and ISR instrumentation on \n
///        In this file the variant "RTA task and ISR instrumentation on" is implemented

#include <Std_Types.h>
#include <rta_os.h>
#include <rta_os_hooks.h>
#include <rta_task_isr_info_priv.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

void RTA_v_PreIsrHook(const uint32 u_ISR_ID)
{
  // Generate related rtaEvents
  RTA_v_PreIsrHookIntern(u_ISR_ID);
  // Have the interruptHistory updated
  v_updateIsrInfo(u_ISR_ID);
}


void RTA_v_PreTaskHook(const uint32 u_TASK_ID)
{
  // Generate related rtaEvents
  RTA_v_PreTaskHookIntern(u_TASK_ID);
  // Have the taskInformation updated
  v_updateTaskInfo(u_TASK_ID);
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
