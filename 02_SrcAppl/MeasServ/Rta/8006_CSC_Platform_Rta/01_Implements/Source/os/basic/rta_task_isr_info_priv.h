// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements the update function for task and interrupt information for normal OS.

#ifndef RTA_TASK_ISR_INFO_PRIV_H
#define RTA_TASK_ISR_INFO_PRIV_H

#include <rta_task_isr_datasets.h>
#include <rta_req_if.h>
#include <rta_defs.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

static inline void v_updateTaskInfo(const uint32 u_taskID)
{
  RTA_t_TaskIsrInfo*  p_taskIsrInfo;
  const uint32        u_CORE_ID      = RTA_ReqIf_u_GetCoreId();

  if(rta_taskIsrInfoHandler.u_numberOfCores > u_CORE_ID)
  {
    p_taskIsrInfo     = rta_taskIsrInfoHandler.p_taskIsrInfo[u_CORE_ID];
  }
  else
  {
    p_taskIsrInfo = NULL;
  }

  // Check whether we got a valid pointer
  // Note: It can be that we didn't get the valid address from PMA (calling RTA_v_SetTaskIsrInfo() up to now)
  if(NULL != p_taskIsrInfo)
  {
    // Check whether the current taskID is different then the last one
    if((uint8)u_taskID != p_taskIsrInfo->u_OsCurrentTask)
    {
      // It's a new task update the taskIsrInfo
      p_taskIsrInfo->u_OsPreviousTask = p_taskIsrInfo->u_OsCurrentTask;
      p_taskIsrInfo->u_OsCurrentTask  = (uint8)u_taskID;
    }
  }
}


static inline void v_updateIsrInfo(const uint32 u_isrID)
{
  RTA_t_TaskIsrInfo*  p_taskIsrInfo;
  const uint32        u_CORE_ID      = RTA_ReqIf_u_GetCoreId();

  if(rta_taskIsrInfoHandler.u_numberOfCores > u_CORE_ID)
  {
    p_taskIsrInfo     = rta_taskIsrInfoHandler.p_taskIsrInfo[u_CORE_ID];
  }
  else
  {
    p_taskIsrInfo = NULL;
  }

  // Check whether we got a valid pointer
  // Note: It can be that we didn't get the valid address from PMA (calling RTA_v_SetTaskIsrInfo() up to now)
  if(NULL != p_taskIsrInfo)
  {
    const uint64 u_interruptedAddress      = RTA_ReqIf_u_GetInterruptedAddress();

    p_taskIsrInfo->IntStat.IntHist[p_taskIsrInfo->IntStat.u_Index].u_InterruptedAddrLower32bits  = (uint32)(u_interruptedAddress);
    p_taskIsrInfo->IntStat.IntHist[p_taskIsrInfo->IntStat.u_Index].u_InterruptedAddrHigher32bits = (uint32)(u_interruptedAddress >> RTA_SHIFT_BY_32);

    // Update the remaining elements of this entry
    p_taskIsrInfo->IntStat.IntHist[p_taskIsrInfo->IntStat.u_Index].u_Id             = u_isrID;
    p_taskIsrInfo->IntStat.IntHist[p_taskIsrInfo->IntStat.u_Index].u_Timestamp      = RTA_ReqIf_u_GetLocalTimeInUs();

    // Check if index for ISR history has reached already its maxValue
    if((RTA_CFG_SECTION_INT_STAT_SIZE - (uint8)1) > p_taskIsrInfo->IntStat.u_Index)
    {
      // MaxValue not reached -> increment the index
      p_taskIsrInfo->IntStat.u_Index++;
    }
    else
    {
      // MaxValue already reached -> reset the index
      p_taskIsrInfo->IntStat.u_Index = (uint8)0;
    }
  }
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif

#endif // RTA_TASK_ISR_INFO_PRIV_H
