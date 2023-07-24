// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief         Contains functions for runtime measurements.
///                This file makes it possible to suspend / resume
///                the RTA event adding on all cores.
///
///                A typical use case (maybe the only one) is to
///                suspend the RTA event adding while using the
///                ECU in EDP mode. Here we want to add the RTA
///                markers only while an algo is running.

#include <Std_Types.h>
#include <rta_suspend.h>
#include <rta_suspend_priv.h>

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

void RTA_v_SuspendSyncOnSlave(void)
{
}


void RTA_v_SuspendSyncChangeStateMultiCore(const RTA_SuspendStateTransition e_state)
{
  // PRQA S 3119 5
  // 2020-08-26; uib50915
  // summary: Msg(3:3119) This statement has no side-effect - it can be removed.
  // reason:  We use this here to avoid compiler warnings of unused Argument.
  //          We use this Function to keep the same Prototypes for different configs (EDP etc.)
  (void)e_state;
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>

#ifdef __cplusplus
}
#endif

//PRQA L:L111
