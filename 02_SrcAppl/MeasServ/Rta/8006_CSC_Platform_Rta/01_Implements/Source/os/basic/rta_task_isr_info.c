// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements the setFunction which is used by PMA to provide the address of the corresponding task and isr-dataset.

#include <Std_Types.h>
#include <rta_req_if.h>
#include <rta_task_isr_datasets.h>
#include <rta_task_isr_info.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

void RTA_v_SetTaskIsrInfo(RTA_t_TaskIsrInfo* const p_TaskIsrInfo)
{
  const uint32                          u_CORE_ID           = RTA_ReqIf_u_GetCoreId();

  if(rta_taskIsrInfoHandler.u_numberOfCores > u_CORE_ID)
  {
    rta_taskIsrInfoHandler.p_taskIsrInfo[u_CORE_ID]                  = p_TaskIsrInfo;
    rta_taskIsrInfoHandler.p_taskIsrInfo[u_CORE_ID]->IntStat.u_Index = (uint8)0;
  }
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
