// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements all public functions for the feature 'suspend'.
///        It is intended for the case where the feature 'suspend' shall be disabled, therefore almost all functions are empty.
///        Only the timing functions are implemented in the normal way - without the supsend feature.

#include <Std_Types.h>
#include <rta_suspend.h>
#include <rta_suspend_priv.h>
#include <rta_req_if.h>

// PRQA S 0861, 5087 L111
// date:          2020-11-27, reviewer: M. Kammerl , M. Kovac
// reason:        (Msg:0861):This #include <%s> directive is redundant.
//                (Msg:5087):#include statements in a file should only be preceded by other preprocessor directives or comments.
// justification: File includes in mitten of the file is due to the memMap concept of autoSar.

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

boolean RTA_b_Suspended(void)
{
  // Suspend feature is disabled - just return b_FALSE
  return b_FALSE;
}


void RTA_v_Suspend(void)
{
}


void RTA_v_Resume(void)
{
}


void RTA_v_SuspendAllCores(void)
{
}


void RTA_v_ResumeAllCores(void)
{
}


uint64 RTA_u_GetSystemTime(void)
{
  const uint64 u_SystemTime = RTA_ReqIf_u_GetSystemTimeInUs();
  return u_SystemTime;
}


uint32 RTA_u_GetRelativeLocalTime(const uint32 u_referenceTime)
{
  // PRQA S 1252,1255,1281 4
  // date:          2020-03-17, reviewer: M. Kammerl , M. Kovac
  // reason:        Casting problem coming from the define PAL_MICROSEC_TIMER_CNT which is used in the macro
  // justification: Other component dependency.
  const uint32 u_timeLocalNow = RTA_ReqIf_u_GetLocalTimeInUs();
  uint32       u_relativeTime;

  u_relativeTime = u_timeLocalNow - u_referenceTime;

  return u_relativeTime;
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif

//PRQA L:L111
