/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_int.h

DESCRIPTION:               header file for MEDIC evaluation module in FCT_Veh task

AUTHOR:                    $Author: Sekar, Balaji02 (uids6618) $

CREATION DATE:             $Date: 2020/09/10 10:00:31CEST $

VERSION:                   $Revision: 1.60 $

**************************************************************************** */

#ifndef MEDIC_INT_H_INCLUDED
#define MEDIC_INT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_ext.h"
#include "frame_medic/medic_custom_types.h"
#include "frame_medic/medic_par.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
#if (MEDIC_CFG_DIM20)
#include "dim20/dim20_ext.h"
#else
#include "dim/dim_ext.h"
#endif // (MEDIC_CFG_DIM20)
#endif // (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#if (MEDIC_CFG_HEAD20)
#include "head20/head20_ext.h"
#include "head20/head20_custOutput.h"
#else
#include "head/head_ext.h"
#endif // (MEDIC_CFG_HEAD20)
#endif // (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)

#if MEDIC_CFG_TARGET_PLANNER
#include "targetplanner/targetplanner_wrapper.h"  // TODO: there should be an targetplanner_ext.h containing the process function declaration instead
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/
#if (MEDIC_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_VEH_EBA_COMP_STATE
#define FCT_MEAS_ID_VEH_EBA_COMP_STATE  (20274200u) 
#endif
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*! Process MEDIC Custom Output. */
extern void MEDICProcessCustomOutput (void);

#if (MEDIC_CFG_USE_DEM)
/*! Set DEM event */
extern void MEDIC_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus);
#endif

/*--- medic_algocontrol.c ---*/
extern void MEDIC_v_SignalErrorShutdown(const boolean isRecoveryPossible);
extern MEDICCompState_t MEDIC_e_GetWorstSubComponentState(MEDICSubCompIndices_t const SubCompIndices);
extern MEDICCompState_t MEDIC_e_GetSubCompState(MEDICSubCompIndices_t const SubCompIndex);
extern void MEDIC_v_SetSubComponentStates(MEDICSubCompIndices_t const SubCompIndices, MEDICCompState_t const CompState);
extern void MEDIC_v_InitFrameData(const MEDICOpMode_t eOpMode);

#if (MEDIC_CFG_USE_ALGOCOMPSTATE)
extern void MEDIC_v_SetAlgoErrorBuffer(GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif

/*--- medic_main.c ---*/
extern void MEDIC_v_SetState(const MEDICCompState_t t_MEDICStateValue);

/*---medic_io.c---*/

extern void MEDIC_v_FillProPortHeaders(MEDICPortHandlerList_t * const pPortHandlerList);


#if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)) // PRQA S 3332
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose */
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
extern void MEDIC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
#else
extern void MEDIC_v_AlgoServiceAddEvent(const MEDIC_Services *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
#endif
#endif

extern void MEDIC_v_EBAMeasCallback(void); 
extern void MeasFreeze_Medic_GlobVar(const uint32 VADDR_,  void const * const ADDR_, const uint32 SIZE_);
extern void MeasFreeze_Medic_StackVar(const uint32 VADDR_, void const * const ADDR_, const uint32 SIZE_);

#ifdef MEDIC_CFG_AUTOSAR_WRAPPER
#if (MEDIC_CFG_AUTOSAR_WRAPPER)/*PRQA S 3332*//*Author: Nalina M, Reason: Supressing because of no side effects*/
extern void GA_MeasFreeze(
  uint32                            virtualAddr,
  void const                      * dataLocation,
  uint32                            dataSize,
  MEASFuncID_t                      funcID,
  MEASFuncChannelID_t               funcChannelID,
  AS_t_ServiceFuncts   const *const services
);
#endif // MEDIC_CFG_AUTOSAR_WRAPPER
#endif

#ifdef __cplusplus
};
#endif /* __cplusplus                      */
#endif /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */
#endif /* MEDIC_INT_H_INCLUDED            */

