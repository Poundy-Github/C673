// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - real time analysis
/// \file
/// \brief    In this file all interface functions required by the RTA need to be implemented.
///           The includes and also the called functions have to be adapted to the project.

#include <Std_Types.h>
//#include <rta_req_if.h>
//#include <sys_pal.h>
//#include <sys_time.h>
//#include <sys_interrupt.h>
//#include <MTSI.h>
//#include <cache.h>
//#include <sys_mem.h>
//#include <PAL_CoreRegs.h>
#include "Time.h"
#include "IfxStm_reg.h"
#include "Meas.h"
#include "rta_req_if.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

//RTA_GET_LOCALTIME_COUNTER_TICKS
uint32 RTA_ReqIf_u_GetLocalTimeInUs(void)
{
  // #warning RTA_REQ_IF - To be implemented
  // return PAL_TICKS_TO_US(SYS_TimeGetCount());
  SuspendAllInterrupts();
  uint32 localtime_us = (uint32)(((STM0_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000000);
  ResumeAllInterrupts();
  return localtime_us;
}

//RTA_GET_SYSTEM_TIME_US
uint64 RTA_ReqIf_u_GetSystemTimeInUs(void)
{
  // #warning RTA_REQ_IF - To be implemented
  // return SYS_u_TimeGet64_us();
  uint64 systime_ns;
  (void)Time_GetTimeStampNs(&systime_ns);
  return (systime_ns / 1000);
}

//RTA_DISABLE_INTERRUPTS
void RTA_ReqIf_v_DisableInterrupts(void)
{
  // #warning RTA_REQ_IF - To be implemented
  // SYS_SaveDisableInt();
  SuspendAllInterrupts();
}

//RTA_ENABLE_INTERRUPTS
void RTA_ReqIf_v_EnableInterrupts(void)
{
  // #warning RTA_REQ_IF - To be implemented
  // SYS_RestoreEnableInt();
  ResumeAllInterrupts();
}

//RTA_GET_CORE_ID
uint32 RTA_ReqIf_u_GetCoreId(void)
{
  // #warning RTA_REQ_IF - To be implemented
  // TODO: currently supporting only one core, to be extended to support all 4
  // return Pal_Sys_u_FetchCoreNumber();
  return ((uint32)GetCoreID());

}

//RTA_MEAS_FREEZE_DATA
uint32 RTA_ReqIf_u_MeasFreezeData(const RTA_t_MeasFreezeInfo* const p_measFreezeInfo)
{
  // #warning RTA_REQ_IF - To be implemented
  MEASInfo_t freezeInfo;

  freezeInfo.VirtualAddress    = p_measFreezeInfo->u_virtAddr;
  freezeInfo.Length            = p_measFreezeInfo->u_lenght;
  freezeInfo.FuncID            = p_measFreezeInfo->u_functionId;

  // return (uint32)MTSI_FreezeData(&freezeInfo, p_measFreezeInfo->p_data, p_measFreezeInfo->p_callBack);
  return (uint32)MEASFreezeDataMTS(&freezeInfo, p_measFreezeInfo->p_data, p_measFreezeInfo->p_callBack);
}

//RTA_CACHE_WRITEBACK_ACTIVATED
void RTA_ReqIf_v_WritebackCache(void* const p_block, const uint32 u_length)
{
  // #warning RTA_REQ_IF - To be implemented
  // Pal_v_DCacheFlushAndInvalidate();
}

//RTA_MEM_SET
void RTA_ReqIf_v_MemSet(void* const p_dest, const uint8 u_value, const uint32 u_length)
{
  // #warning RTA_REQ_IF - To be implemented
  memset(p_dest, u_value, u_length);
}



void RTA_ReqIf_v_GetSpinLock(const uint32 u_SPIN_LOCK_ID)
{
  // Only required in case of multiCore suspend
}

void RTA_ReqIf_v_ReleaseSpinLock(const uint32 u_SPIN_LOCK_ID)
{
  // Only required in case of multiCore suspend
}

//Only required in case of enabled suspend feature
void RTA_ReqIf_v_SetOsEdpSyncEvent(const uint32 u_osTaskId)
{
  // Only required in case of multiCore suspend
}

uint64 RTA_ReqIf_u_GetInterruptedAddress(void)
{
  return 0x0000000000000000;
}


// This function gives the possibility to block single globalIDs if needed
// Please consider that this function is called very, very often - when ever an RTA-Event is generated.
// Therefore it is really important that the runtime is as short as possible!
// TODO: Switch to RTA_t_GlobalID as soon as adas_embed_mon_if 3.1.1 is integrated!
//       Currently the standard type is used to make an integration into the projects possible even without 3.1.1
//boolean RTA_ReqIf_v_IsGlobalIdEnabled(const RTA_t_GlobalID u_globalID)
boolean RTA_ReqIf_v_IsGlobalIdEnabled(const uint16 u_globalID)
{
  return b_TRUE;
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>

#ifdef __cplusplus
}
#endif
