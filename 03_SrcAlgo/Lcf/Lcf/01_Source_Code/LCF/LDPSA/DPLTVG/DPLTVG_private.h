/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLTVG_private.h
//! @brief     (DPLTVG) Module Private Header.

#ifndef DPLTVG_PRIVATE_H_
#define DPLTVG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define LDPSA	//!< LDPSA sub-component input macro switch.
#define DPLTVG	//!< DPLTVG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLTVG.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DPLTVG_SenReset		0xF0 //!< DPLTVG module reset runnable identifier.
#define RUNNABLE_ID_DPLTVG_SenProcess	0xF1 //!< DPLTVG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPLTVG_SenOutType *DPLTVG_SenOutPtr = NULL; //!< DPLTVG module sensor output data pointer.
void DPLTVG_SenInitOutPtr(DPLTVG_SenOutType *DPLTVG_SenOutArg) { DPLTVG_SenOutPtr = DPLTVG_SenOutPtr == NULL ? DPLTVG_SenOutArg : DPLTVG_SenOutPtr; }
const DPLTVG_SenOutType* DPLTVG_SenGetOutPtr(void) { return (const DPLTVG_SenOutType*) DPLTVG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPLTVG_DeratingLevel_nu
#define	S_DPLTVG_DeratingLevel_nu (DPLTVG_SenOutPtr->S_DPLTVG_DeratingLevel_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_DeratingLevel_nu(val)	(S_DPLTVG_DeratingLevel_nu = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_DistYTolLeTgtArea_met
#define	S_DPLTVG_DistYTolLeTgtArea_met (DPLTVG_SenOutPtr->S_DPLTVG_DistYTolLeTgtArea_met) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_DistYTolLeTgtArea_met(val)	(S_DPLTVG_DistYTolLeTgtArea_met = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_DistYTolRiTgtArea_met
#define	S_DPLTVG_DistYTolRiTgtArea_met (DPLTVG_SenOutPtr->S_DPLTVG_DistYTolRiTgtArea_met) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_DistYTolRiTgtArea_met(val)	(S_DPLTVG_DistYTolRiTgtArea_met = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_FTireAclMax_mps2
#define	S_DPLTVG_FTireAclMax_mps2 (DPLTVG_SenOutPtr->S_DPLTVG_FTireAclMax_mps2) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_FTireAclMax_mps2(val)	(S_DPLTVG_FTireAclMax_mps2 = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_FTireAclMin_mps2
#define	S_DPLTVG_FTireAclMin_mps2 (DPLTVG_SenOutPtr->S_DPLTVG_FTireAclMin_mps2) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_FTireAclMin_mps2(val)	(S_DPLTVG_FTireAclMin_mps2 = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_GrdLimitTgtCrvTGC_1pms
#define	S_DPLTVG_GrdLimitTgtCrvTGC_1pms (DPLTVG_SenOutPtr->S_DPLTVG_GrdLimitTgtCrvTGC_1pms) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_GrdLimitTgtCrvTGC_1pms(val)	(S_DPLTVG_GrdLimitTgtCrvTGC_1pms = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_HighStatAccu_bool
#define	S_DPLTVG_HighStatAccu_bool (DPLTVG_SenOutPtr->S_DPLTVG_HighStatAccu_bool) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_HighStatAccu_bool(val)	(S_DPLTVG_HighStatAccu_bool = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_LimiterActivated_bool
#define	S_DPLTVG_LimiterActivated_bool (DPLTVG_SenOutPtr->S_DPLTVG_LimiterActivated_bool) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_LimiterActivated_bool(val)	(S_DPLTVG_LimiterActivated_bool = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_LimiterTimeDuration_sec
#define	S_DPLTVG_LimiterTimeDuration_sec (DPLTVG_SenOutPtr->S_DPLTVG_LimiterTimeDuration_sec) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_LimiterTimeDuration_sec(val)	(S_DPLTVG_LimiterTimeDuration_sec = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_LtcyCompActivated_bool
#define	S_DPLTVG_LtcyCompActivated_bool (DPLTVG_SenOutPtr->S_DPLTVG_LtcyCompActivated_bool) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_LtcyCompActivated_bool(val)	(S_DPLTVG_LtcyCompActivated_bool = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_MaxCrvGrdBuildup_1pms
#define	S_DPLTVG_MaxCrvGrdBuildup_1pms (DPLTVG_SenOutPtr->S_DPLTVG_MaxCrvGrdBuildup_1pms) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_MaxCrvGrdBuildup_1pms(val)	(S_DPLTVG_MaxCrvGrdBuildup_1pms = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_MaxCrvGrdRed_1pms
#define	S_DPLTVG_MaxCrvGrdRed_1pms (DPLTVG_SenOutPtr->S_DPLTVG_MaxCrvGrdRed_1pms) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_MaxCrvGrdRed_1pms(val)	(S_DPLTVG_MaxCrvGrdRed_1pms = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_MaxCrvTrajGuiCtrl_1pm
#define	S_DPLTVG_MaxCrvTrajGuiCtrl_1pm (DPLTVG_SenOutPtr->S_DPLTVG_MaxCrvTrajGuiCtrl_1pm) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_MaxCrvTrajGuiCtrl_1pm(val)	(S_DPLTVG_MaxCrvTrajGuiCtrl_1pm = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_MaxJerkAllowed_mps3
#define	S_DPLTVG_MaxJerkAllowed_mps3 (DPLTVG_SenOutPtr->S_DPLTVG_MaxJerkAllowed_mps3) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_MaxJerkAllowed_mps3(val)	(S_DPLTVG_MaxJerkAllowed_mps3 = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_MaxTrqScalGrad_1ps
#define	S_DPLTVG_MaxTrqScalGrad_1ps (DPLTVG_SenOutPtr->S_DPLTVG_MaxTrqScalGrad_1ps) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_MaxTrqScalGrad_1ps(val)	(S_DPLTVG_MaxTrqScalGrad_1ps = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_MaxTrqScalLimit_nu
#define	S_DPLTVG_MaxTrqScalLimit_nu (DPLTVG_SenOutPtr->S_DPLTVG_MaxTrqScalLimit_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_MaxTrqScalLimit_nu(val)	(S_DPLTVG_MaxTrqScalLimit_nu = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_ObstacleAclX_mps2
#define	S_DPLTVG_ObstacleAclX_mps2 (DPLTVG_SenOutPtr->S_DPLTVG_ObstacleAclX_mps2) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_ObstacleAclX_mps2(val)	(S_DPLTVG_ObstacleAclX_mps2 = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_ObstacleDistX_met
#define	S_DPLTVG_ObstacleDistX_met (DPLTVG_SenOutPtr->S_DPLTVG_ObstacleDistX_met) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_ObstacleDistX_met(val)	(S_DPLTVG_ObstacleDistX_met = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_ObstacleDistY_met
#define	S_DPLTVG_ObstacleDistY_met (DPLTVG_SenOutPtr->S_DPLTVG_ObstacleDistY_met) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_ObstacleDistY_met(val)	(S_DPLTVG_ObstacleDistY_met = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_ObstacleVelX_mps
#define	S_DPLTVG_ObstacleVelX_mps (DPLTVG_SenOutPtr->S_DPLTVG_ObstacleVelX_mps) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_ObstacleVelX_mps(val)	(S_DPLTVG_ObstacleVelX_mps = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_ObstacleWidth_met
#define	S_DPLTVG_ObstacleWidth_met (DPLTVG_SenOutPtr->S_DPLTVG_ObstacleWidth_met) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_ObstacleWidth_met(val)	(S_DPLTVG_ObstacleWidth_met = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_PlanningHorizon_sec
#define	S_DPLTVG_PlanningHorizon_sec (DPLTVG_SenOutPtr->S_DPLTVG_PlanningHorizon_sec) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_PlanningHorizon_sec(val)	(S_DPLTVG_PlanningHorizon_sec = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_PredTimeCrv_sec
#define	S_DPLTVG_PredTimeCrv_sec (DPLTVG_SenOutPtr->S_DPLTVG_PredTimeCrv_sec) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_PredTimeCrv_sec(val)	(S_DPLTVG_PredTimeCrv_sec = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_PredTimeHeadAng_sec
#define	S_DPLTVG_PredTimeHeadAng_sec (DPLTVG_SenOutPtr->S_DPLTVG_PredTimeHeadAng_sec) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_PredTimeHeadAng_sec(val)	(S_DPLTVG_PredTimeHeadAng_sec = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_SensorTStamp_sec
#define	S_DPLTVG_SensorTStamp_sec (DPLTVG_SenOutPtr->S_DPLTVG_SensorTStamp_sec) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_SensorTStamp_sec(val)	(S_DPLTVG_SensorTStamp_sec = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_StrWhStifGrad_1ps
#define	S_DPLTVG_StrWhStifGrad_1ps (DPLTVG_SenOutPtr->S_DPLTVG_StrWhStifGrad_1ps) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_StrWhStifGrad_1ps(val)	(S_DPLTVG_StrWhStifGrad_1ps = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_StrWhStifLimit_nu
#define	S_DPLTVG_StrWhStifLimit_nu (DPLTVG_SenOutPtr->S_DPLTVG_StrWhStifLimit_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_StrWhStifLimit_nu(val)	(S_DPLTVG_StrWhStifLimit_nu = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_TrajGuiQu_nu
#define	S_DPLTVG_TrajGuiQu_nu (DPLTVG_SenOutPtr->S_DPLTVG_TrajGuiQu_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_TrajGuiQu_nu(val)	(S_DPLTVG_TrajGuiQu_nu = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_TrajPlanServQu_nu
#define	S_DPLTVG_TrajPlanServQu_nu (DPLTVG_SenOutPtr->S_DPLTVG_TrajPlanServQu_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_TrajPlanServQu_nu(val)	(S_DPLTVG_TrajPlanServQu_nu = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_TriggerReplan_bool
#define	S_DPLTVG_TriggerReplan_bool (DPLTVG_SenOutPtr->S_DPLTVG_TriggerReplan_bool) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_TriggerReplan_bool(val)	(S_DPLTVG_TriggerReplan_bool = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_TrqRampGrad_1ps
#define	S_DPLTVG_TrqRampGrad_1ps (DPLTVG_SenOutPtr->S_DPLTVG_TrqRampGrad_1ps) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_TrqRampGrad_1ps(val)	(S_DPLTVG_TrqRampGrad_1ps = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_WeightEndTime_nu
#define	S_DPLTVG_WeightEndTime_nu (DPLTVG_SenOutPtr->S_DPLTVG_WeightEndTime_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_WeightEndTime_nu(val)	(S_DPLTVG_WeightEndTime_nu = (val)) //!< DPLTVG debug macro setter.

#undef	S_DPLTVG_WeightTgtDistY_nu
#define	S_DPLTVG_WeightTgtDistY_nu (DPLTVG_SenOutPtr->S_DPLTVG_WeightTgtDistY_nu) //!< DPLTVG debug macro.
#define	SET_S_DPLTVG_WeightTgtDistY_nu(val)	(S_DPLTVG_WeightTgtDistY_nu = (val)) //!< DPLTVG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPLTVG_PRIVATE_H_
