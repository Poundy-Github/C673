// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements all public functions for the feature 'emergency buffer freeze'.
///        It is intended for the case where the feature 'emergency buffer freeze' shall be disabled, therefore all functions are empty.

#include <Std_Types.h>
#include <rta_emergency_freeze.h>

// PRQA S 5087 L111
// date:          2020-11-25, reviewer: Dj. Vujic, M. Kammerl
// Reason :       Msg(5087) Use of #include directive after code fragment.
// Justification: This is the AutoSar way to handle memory mapping.

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

void RTA_v_EmergencyBufferFreeze(const RTA_t_BuildUnits BUILD_UNITS_TO_FREEZE, const boolean b_TASKING_DISABLED)
{
  // Emergency freeze feature disabled - do nothing
}


void RTA_v_CacheWriteBackRtaBuffers(void)
{
  // Emergency freeze feature disabled - do nothing
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif

// PRQA L:L111
