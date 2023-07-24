// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements all public functions for the feature 'auxiliary cores'.
///        It is intended for the case where the feature 'auxiliary cores' shall be disabled, therefore all functions are empty.

// Date:          2020-11-25, reviewer: Dj. Vujic, M. Kammerl
// Reason :       Msg(5087) Use of #include directive after code fragment.
// Justification: This is the AutoSar way to handle memory mapping.

#include <Std_Types.h>
#include <rta.h>
#include <rta_aux_cores.h>
#include <rta_aux_cores_priv.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_AUX_START_SEC_INIT_CODE
#include <rta_memmap_cfg.h>

void RTA_v_AuxCoresInit(void)
{
  // Feature AuxCores disabled - do noting
}

#define CddSwc_RTA_AUX_STOP_SEC_INIT_CODE
#include <rta_memmap_cfg.h>


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

void RTA_v_AddEventAuxiliaryCores (const RTA_t_auxCoreID u_auxCoreID, const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData)
{
  // Feature AuxCores disabled - do noting
}


void RTA_v_AddEventVirtCore (const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData)
{
  // Feature AuxCores disabled - do noting
}


void RTA_v_AuxCoresSwitchAllBuffers(void)
{
  // Feature AuxCores disabled - do noting
}


void RTA_v_AuxCoresFreezeAllBuffers(void)
{
  // Feature AuxCores disabled - do noting
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif

// PRQA L:L111
