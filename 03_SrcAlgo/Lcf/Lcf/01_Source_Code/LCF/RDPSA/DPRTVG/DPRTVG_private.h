/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRTVG_private.h
//! @brief     (DPRTVG) Module Private Header.

#ifndef DPRTVG_PRIVATE_H_
#define DPRTVG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define RDPSA	//!< RDPSA sub-component input macro switch.
#define DPRTVG	//!< DPRTVG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRTVG.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DPRTVG_SenReset		0xF0 //!< DPRTVG module reset runnable identifier.
#define RUNNABLE_ID_DPRTVG_SenProcess	0xF1 //!< DPRTVG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPRTVG_SenOutType *DPRTVG_SenOutPtr = NULL; //!< DPRTVG module sensor output data pointer.
void DPRTVG_SenInitOutPtr(DPRTVG_SenOutType *DPRTVG_SenOutArg) { DPRTVG_SenOutPtr = DPRTVG_SenOutPtr == NULL ? DPRTVG_SenOutArg : DPRTVG_SenOutPtr; }
const DPRTVG_SenOutType* DPRTVG_SenGetOutPtr(void) { return (const DPRTVG_SenOutType*) DPRTVG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPRTVG_DeratingLevel_nu
#define	S_DPRTVG_DeratingLevel_nu (DPRTVG_SenOutPtr->S_DPRTVG_DeratingLevel_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_DeratingLevel_nu(val)	(S_DPRTVG_DeratingLevel_nu = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_DistYTolLeTgtArea_met
#define	S_DPRTVG_DistYTolLeTgtArea_met (DPRTVG_SenOutPtr->S_DPRTVG_DistYTolLeTgtArea_met) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_DistYTolLeTgtArea_met(val)	(S_DPRTVG_DistYTolLeTgtArea_met = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_DistYTolRiTgtArea_met
#define	S_DPRTVG_DistYTolRiTgtArea_met (DPRTVG_SenOutPtr->S_DPRTVG_DistYTolRiTgtArea_met) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_DistYTolRiTgtArea_met(val)	(S_DPRTVG_DistYTolRiTgtArea_met = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_FTireAclMax_mps2
#define	S_DPRTVG_FTireAclMax_mps2 (DPRTVG_SenOutPtr->S_DPRTVG_FTireAclMax_mps2) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_FTireAclMax_mps2(val)	(S_DPRTVG_FTireAclMax_mps2 = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_FTireAclMin_mps2
#define	S_DPRTVG_FTireAclMin_mps2 (DPRTVG_SenOutPtr->S_DPRTVG_FTireAclMin_mps2) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_FTireAclMin_mps2(val)	(S_DPRTVG_FTireAclMin_mps2 = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_GrdLimitTgtCrvTGC_1pms
#define	S_DPRTVG_GrdLimitTgtCrvTGC_1pms (DPRTVG_SenOutPtr->S_DPRTVG_GrdLimitTgtCrvTGC_1pms) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_GrdLimitTgtCrvTGC_1pms(val)	(S_DPRTVG_GrdLimitTgtCrvTGC_1pms = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_HighStatAccu_bool
#define	S_DPRTVG_HighStatAccu_bool (DPRTVG_SenOutPtr->S_DPRTVG_HighStatAccu_bool) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_HighStatAccu_bool(val)	(S_DPRTVG_HighStatAccu_bool = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_LimiterActivated_bool
#define	S_DPRTVG_LimiterActivated_bool (DPRTVG_SenOutPtr->S_DPRTVG_LimiterActivated_bool) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_LimiterActivated_bool(val)	(S_DPRTVG_LimiterActivated_bool = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_LimiterTimeDuration_sec
#define	S_DPRTVG_LimiterTimeDuration_sec (DPRTVG_SenOutPtr->S_DPRTVG_LimiterTimeDuration_sec) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_LimiterTimeDuration_sec(val)	(S_DPRTVG_LimiterTimeDuration_sec = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_LtcyCompActivated_bool
#define	S_DPRTVG_LtcyCompActivated_bool (DPRTVG_SenOutPtr->S_DPRTVG_LtcyCompActivated_bool) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_LtcyCompActivated_bool(val)	(S_DPRTVG_LtcyCompActivated_bool = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_MaxCrvGrdBuildup_1pms
#define	S_DPRTVG_MaxCrvGrdBuildup_1pms (DPRTVG_SenOutPtr->S_DPRTVG_MaxCrvGrdBuildup_1pms) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_MaxCrvGrdBuildup_1pms(val)	(S_DPRTVG_MaxCrvGrdBuildup_1pms = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_MaxCrvGrdRed_1pms
#define	S_DPRTVG_MaxCrvGrdRed_1pms (DPRTVG_SenOutPtr->S_DPRTVG_MaxCrvGrdRed_1pms) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_MaxCrvGrdRed_1pms(val)	(S_DPRTVG_MaxCrvGrdRed_1pms = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_MaxCrvTrajGuiCtrl_1pm
#define	S_DPRTVG_MaxCrvTrajGuiCtrl_1pm (DPRTVG_SenOutPtr->S_DPRTVG_MaxCrvTrajGuiCtrl_1pm) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_MaxCrvTrajGuiCtrl_1pm(val)	(S_DPRTVG_MaxCrvTrajGuiCtrl_1pm = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_MaxJerkAllowed_mps3
#define	S_DPRTVG_MaxJerkAllowed_mps3 (DPRTVG_SenOutPtr->S_DPRTVG_MaxJerkAllowed_mps3) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_MaxJerkAllowed_mps3(val)	(S_DPRTVG_MaxJerkAllowed_mps3 = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_MaxTrqScalGrad_1ps
#define	S_DPRTVG_MaxTrqScalGrad_1ps (DPRTVG_SenOutPtr->S_DPRTVG_MaxTrqScalGrad_1ps) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_MaxTrqScalGrad_1ps(val)	(S_DPRTVG_MaxTrqScalGrad_1ps = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_MaxTrqScalLimit_nu
#define	S_DPRTVG_MaxTrqScalLimit_nu (DPRTVG_SenOutPtr->S_DPRTVG_MaxTrqScalLimit_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_MaxTrqScalLimit_nu(val)	(S_DPRTVG_MaxTrqScalLimit_nu = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_ObstacleAclX_mps2
#define	S_DPRTVG_ObstacleAclX_mps2 (DPRTVG_SenOutPtr->S_DPRTVG_ObstacleAclX_mps2) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_ObstacleAclX_mps2(val)	(S_DPRTVG_ObstacleAclX_mps2 = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_ObstacleDistX_met
#define	S_DPRTVG_ObstacleDistX_met (DPRTVG_SenOutPtr->S_DPRTVG_ObstacleDistX_met) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_ObstacleDistX_met(val)	(S_DPRTVG_ObstacleDistX_met = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_ObstacleDistY_met
#define	S_DPRTVG_ObstacleDistY_met (DPRTVG_SenOutPtr->S_DPRTVG_ObstacleDistY_met) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_ObstacleDistY_met(val)	(S_DPRTVG_ObstacleDistY_met = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_ObstacleVelX_mps
#define	S_DPRTVG_ObstacleVelX_mps (DPRTVG_SenOutPtr->S_DPRTVG_ObstacleVelX_mps) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_ObstacleVelX_mps(val)	(S_DPRTVG_ObstacleVelX_mps = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_ObstacleWidth_met
#define	S_DPRTVG_ObstacleWidth_met (DPRTVG_SenOutPtr->S_DPRTVG_ObstacleWidth_met) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_ObstacleWidth_met(val)	(S_DPRTVG_ObstacleWidth_met = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_PlanningHorizon_sec
#define	S_DPRTVG_PlanningHorizon_sec (DPRTVG_SenOutPtr->S_DPRTVG_PlanningHorizon_sec) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_PlanningHorizon_sec(val)	(S_DPRTVG_PlanningHorizon_sec = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_PredTimeCrv_sec
#define	S_DPRTVG_PredTimeCrv_sec (DPRTVG_SenOutPtr->S_DPRTVG_PredTimeCrv_sec) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_PredTimeCrv_sec(val)	(S_DPRTVG_PredTimeCrv_sec = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_PredTimeHeadAng_sec
#define	S_DPRTVG_PredTimeHeadAng_sec (DPRTVG_SenOutPtr->S_DPRTVG_PredTimeHeadAng_sec) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_PredTimeHeadAng_sec(val)	(S_DPRTVG_PredTimeHeadAng_sec = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_SensorTStamp_sec
#define	S_DPRTVG_SensorTStamp_sec (DPRTVG_SenOutPtr->S_DPRTVG_SensorTStamp_sec) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_SensorTStamp_sec(val)	(S_DPRTVG_SensorTStamp_sec = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_StrWhStifGrad_1ps
#define	S_DPRTVG_StrWhStifGrad_1ps (DPRTVG_SenOutPtr->S_DPRTVG_StrWhStifGrad_1ps) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_StrWhStifGrad_1ps(val)	(S_DPRTVG_StrWhStifGrad_1ps = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_StrWhStifLimit_nu
#define	S_DPRTVG_StrWhStifLimit_nu (DPRTVG_SenOutPtr->S_DPRTVG_StrWhStifLimit_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_StrWhStifLimit_nu(val)	(S_DPRTVG_StrWhStifLimit_nu = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_TrajGuiQu_nu
#define	S_DPRTVG_TrajGuiQu_nu (DPRTVG_SenOutPtr->S_DPRTVG_TrajGuiQu_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_TrajGuiQu_nu(val)	(S_DPRTVG_TrajGuiQu_nu = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_TrajPlanServQu_nu
#define	S_DPRTVG_TrajPlanServQu_nu (DPRTVG_SenOutPtr->S_DPRTVG_TrajPlanServQu_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_TrajPlanServQu_nu(val)	(S_DPRTVG_TrajPlanServQu_nu = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_TriggerReplan_bool
#define	S_DPRTVG_TriggerReplan_bool (DPRTVG_SenOutPtr->S_DPRTVG_TriggerReplan_bool) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_TriggerReplan_bool(val)	(S_DPRTVG_TriggerReplan_bool = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_TrqRampGrad_1ps
#define	S_DPRTVG_TrqRampGrad_1ps (DPRTVG_SenOutPtr->S_DPRTVG_TrqRampGrad_1ps) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_TrqRampGrad_1ps(val)	(S_DPRTVG_TrqRampGrad_1ps = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_WeightEndTime_nu
#define	S_DPRTVG_WeightEndTime_nu (DPRTVG_SenOutPtr->S_DPRTVG_WeightEndTime_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_WeightEndTime_nu(val)	(S_DPRTVG_WeightEndTime_nu = (val)) //!< DPRTVG debug macro setter.

#undef	S_DPRTVG_WeightTgtDistY_nu
#define	S_DPRTVG_WeightTgtDistY_nu (DPRTVG_SenOutPtr->S_DPRTVG_WeightTgtDistY_nu) //!< DPRTVG debug macro.
#define	SET_S_DPRTVG_WeightTgtDistY_nu(val)	(S_DPRTVG_WeightTgtDistY_nu = (val)) //!< DPRTVG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPRTVG_PRIVATE_H_
