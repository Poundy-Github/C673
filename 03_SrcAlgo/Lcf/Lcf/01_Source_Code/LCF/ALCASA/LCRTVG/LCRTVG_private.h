/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRTVG_private.h
//! @brief     (LCRTVG) Module Private Header.

#ifndef LCRTVG_PRIVATE_H_
#define LCRTVG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ALCASA	//!< ALCASA sub-component input macro switch.
#define LCRTVG	//!< LCRTVG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCRTVG.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_LCRTVG_SenReset		0xF0 //!< LCRTVG module reset runnable identifier.
#define RUNNABLE_ID_LCRTVG_SenProcess	0xF1 //!< LCRTVG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static LCRTVG_SenDbgType *LCRTVG_SenDbgPtr = NULL; //!< LCRTVG module sensor debug data pointer.
void LCRTVG_SenInitDbgPtr(LCRTVG_SenDbgType *LCRTVG_SenDbgArg) { LCRTVG_SenDbgPtr = LCRTVG_SenDbgPtr == NULL ? LCRTVG_SenDbgArg : LCRTVG_SenDbgPtr; }
const LCRTVG_SenDbgType* LCRTVG_SenGetDbgPtr(void) { return (const LCRTVG_SenDbgType*) LCRTVG_SenDbgPtr; }

static LCRTVG_SenOutType *LCRTVG_SenOutPtr = NULL; //!< LCRTVG module sensor output data pointer.
void LCRTVG_SenInitOutPtr(LCRTVG_SenOutType *LCRTVG_SenOutArg) { LCRTVG_SenOutPtr = LCRTVG_SenOutPtr == NULL ? LCRTVG_SenOutArg : LCRTVG_SenOutPtr; }
const LCRTVG_SenOutType* LCRTVG_SenGetOutPtr(void) { return (const LCRTVG_SenOutType*) LCRTVG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_LCRTVG_DistYTolLeTgtArea_met
#define	S_LCRTVG_DistYTolLeTgtArea_met (LCRTVG_SenDbgPtr->S_LCRTVG_DistYTolLeTgtArea_met) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_DistYTolLeTgtArea_met(val)	(S_LCRTVG_DistYTolLeTgtArea_met = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_DistYTolRiTgtArea_met
#define	S_LCRTVG_DistYTolRiTgtArea_met (LCRTVG_SenDbgPtr->S_LCRTVG_DistYTolRiTgtArea_met) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_DistYTolRiTgtArea_met(val)	(S_LCRTVG_DistYTolRiTgtArea_met = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_FTireAclMax_mps2
#define	S_LCRTVG_FTireAclMax_mps2 (LCRTVG_SenDbgPtr->S_LCRTVG_FTireAclMax_mps2) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_FTireAclMax_mps2(val)	(S_LCRTVG_FTireAclMax_mps2 = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_FTireAclMin_mps2
#define	S_LCRTVG_FTireAclMin_mps2 (LCRTVG_SenDbgPtr->S_LCRTVG_FTireAclMin_mps2) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_FTireAclMin_mps2(val)	(S_LCRTVG_FTireAclMin_mps2 = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_GrdLimitTgtCrvTGC_1pms
#define	S_LCRTVG_GrdLimitTgtCrvTGC_1pms (LCRTVG_SenDbgPtr->S_LCRTVG_GrdLimitTgtCrvTGC_1pms) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_GrdLimitTgtCrvTGC_1pms(val)	(S_LCRTVG_GrdLimitTgtCrvTGC_1pms = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_HighStatAccu_bool
#define	S_LCRTVG_HighStatAccu_bool (LCRTVG_SenDbgPtr->S_LCRTVG_HighStatAccu_bool) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_HighStatAccu_bool(val)	(S_LCRTVG_HighStatAccu_bool = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_LimiterActivated_bool
#define	S_LCRTVG_LimiterActivated_bool (LCRTVG_SenDbgPtr->S_LCRTVG_LimiterActivated_bool) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_LimiterActivated_bool(val)	(S_LCRTVG_LimiterActivated_bool = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_LimiterTimeDuration_sec
#define	S_LCRTVG_LimiterTimeDuration_sec (LCRTVG_SenDbgPtr->S_LCRTVG_LimiterTimeDuration_sec) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_LimiterTimeDuration_sec(val)	(S_LCRTVG_LimiterTimeDuration_sec = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_LtcyCompActivated_bool
#define	S_LCRTVG_LtcyCompActivated_bool (LCRTVG_SenDbgPtr->S_LCRTVG_LtcyCompActivated_bool) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_LtcyCompActivated_bool(val)	(S_LCRTVG_LtcyCompActivated_bool = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_MaxCrvGrdBuildup_1pms
#define	S_LCRTVG_MaxCrvGrdBuildup_1pms (LCRTVG_SenDbgPtr->S_LCRTVG_MaxCrvGrdBuildup_1pms) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_MaxCrvGrdBuildup_1pms(val)	(S_LCRTVG_MaxCrvGrdBuildup_1pms = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_MaxCrvGrdRed_1pms
#define	S_LCRTVG_MaxCrvGrdRed_1pms (LCRTVG_SenDbgPtr->S_LCRTVG_MaxCrvGrdRed_1pms) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_MaxCrvGrdRed_1pms(val)	(S_LCRTVG_MaxCrvGrdRed_1pms = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_MaxCrvTrajGuiCtrl_1pm
#define	S_LCRTVG_MaxCrvTrajGuiCtrl_1pm (LCRTVG_SenDbgPtr->S_LCRTVG_MaxCrvTrajGuiCtrl_1pm) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_MaxCrvTrajGuiCtrl_1pm(val)	(S_LCRTVG_MaxCrvTrajGuiCtrl_1pm = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_MaxTrqScalGrad_1ps
#define	S_LCRTVG_MaxTrqScalGrad_1ps (LCRTVG_SenDbgPtr->S_LCRTVG_MaxTrqScalGrad_1ps) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_MaxTrqScalGrad_1ps(val)	(S_LCRTVG_MaxTrqScalGrad_1ps = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_MaxTrqScalLimit_nu
#define	S_LCRTVG_MaxTrqScalLimit_nu (LCRTVG_SenDbgPtr->S_LCRTVG_MaxTrqScalLimit_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_MaxTrqScalLimit_nu(val)	(S_LCRTVG_MaxTrqScalLimit_nu = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_ObstacleAclX_mps2
#define	S_LCRTVG_ObstacleAclX_mps2 (LCRTVG_SenDbgPtr->S_LCRTVG_ObstacleAclX_mps2) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_ObstacleAclX_mps2(val)	(S_LCRTVG_ObstacleAclX_mps2 = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_ObstacleDistX_met
#define	S_LCRTVG_ObstacleDistX_met (LCRTVG_SenDbgPtr->S_LCRTVG_ObstacleDistX_met) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_ObstacleDistX_met(val)	(S_LCRTVG_ObstacleDistX_met = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_ObstacleDistY_met
#define	S_LCRTVG_ObstacleDistY_met (LCRTVG_SenDbgPtr->S_LCRTVG_ObstacleDistY_met) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_ObstacleDistY_met(val)	(S_LCRTVG_ObstacleDistY_met = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_ObstacleVelX_mps
#define	S_LCRTVG_ObstacleVelX_mps (LCRTVG_SenDbgPtr->S_LCRTVG_ObstacleVelX_mps) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_ObstacleVelX_mps(val)	(S_LCRTVG_ObstacleVelX_mps = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_ObstacleWidth_met
#define	S_LCRTVG_ObstacleWidth_met (LCRTVG_SenDbgPtr->S_LCRTVG_ObstacleWidth_met) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_ObstacleWidth_met(val)	(S_LCRTVG_ObstacleWidth_met = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_PlanningHorizon_sec
#define	S_LCRTVG_PlanningHorizon_sec (LCRTVG_SenDbgPtr->S_LCRTVG_PlanningHorizon_sec) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_PlanningHorizon_sec(val)	(S_LCRTVG_PlanningHorizon_sec = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_PredTimeCrv_sec
#define	S_LCRTVG_PredTimeCrv_sec (LCRTVG_SenDbgPtr->S_LCRTVG_PredTimeCrv_sec) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_PredTimeCrv_sec(val)	(S_LCRTVG_PredTimeCrv_sec = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_PredTimeHeadAng_sec
#define	S_LCRTVG_PredTimeHeadAng_sec (LCRTVG_SenDbgPtr->S_LCRTVG_PredTimeHeadAng_sec) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_PredTimeHeadAng_sec(val)	(S_LCRTVG_PredTimeHeadAng_sec = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_StrWhStifGrad_1ps
#define	S_LCRTVG_StrWhStifGrad_1ps (LCRTVG_SenDbgPtr->S_LCRTVG_StrWhStifGrad_1ps) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_StrWhStifGrad_1ps(val)	(S_LCRTVG_StrWhStifGrad_1ps = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_StrWhStifLimit_nu
#define	S_LCRTVG_StrWhStifLimit_nu (LCRTVG_SenDbgPtr->S_LCRTVG_StrWhStifLimit_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_StrWhStifLimit_nu(val)	(S_LCRTVG_StrWhStifLimit_nu = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_TrajGuiQu_nu
#define	S_LCRTVG_TrajGuiQu_nu (LCRTVG_SenDbgPtr->S_LCRTVG_TrajGuiQu_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_TrajGuiQu_nu(val)	(S_LCRTVG_TrajGuiQu_nu = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_TrajPlanServQu_nu
#define	S_LCRTVG_TrajPlanServQu_nu (LCRTVG_SenDbgPtr->S_LCRTVG_TrajPlanServQu_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_TrajPlanServQu_nu(val)	(S_LCRTVG_TrajPlanServQu_nu = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_TriggerReplan_bool
#define	S_LCRTVG_TriggerReplan_bool (LCRTVG_SenDbgPtr->S_LCRTVG_TriggerReplan_bool) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_TriggerReplan_bool(val)	(S_LCRTVG_TriggerReplan_bool = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_TrqRampGrad_1ps
#define	S_LCRTVG_TrqRampGrad_1ps (LCRTVG_SenDbgPtr->S_LCRTVG_TrqRampGrad_1ps) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_TrqRampGrad_1ps(val)	(S_LCRTVG_TrqRampGrad_1ps = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_WeightEndTime_nu
#define	S_LCRTVG_WeightEndTime_nu (LCRTVG_SenDbgPtr->S_LCRTVG_WeightEndTime_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_WeightEndTime_nu(val)	(S_LCRTVG_WeightEndTime_nu = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_WeightTgtDistY_nu
#define	S_LCRTVG_WeightTgtDistY_nu (LCRTVG_SenDbgPtr->S_LCRTVG_WeightTgtDistY_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_WeightTgtDistY_nu(val)	(S_LCRTVG_WeightTgtDistY_nu = (val)) //!< LCRTVG debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_LCRTVG_DeratingLevel_nu
#define	S_LCRTVG_DeratingLevel_nu (LCRTVG_SenOutPtr->S_LCRTVG_DeratingLevel_nu) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_DeratingLevel_nu(val)	(S_LCRTVG_DeratingLevel_nu = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_MaxJerkAllowed_mps3
#define	S_LCRTVG_MaxJerkAllowed_mps3 (LCRTVG_SenOutPtr->S_LCRTVG_MaxJerkAllowed_mps3) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_MaxJerkAllowed_mps3(val)	(S_LCRTVG_MaxJerkAllowed_mps3 = (val)) //!< LCRTVG debug macro setter.

#undef	S_LCRTVG_SensorTStamp_sec
#define	S_LCRTVG_SensorTStamp_sec (LCRTVG_SenOutPtr->S_LCRTVG_SensorTStamp_sec) //!< LCRTVG debug macro.
#define	SET_S_LCRTVG_SensorTStamp_sec(val)	(S_LCRTVG_SensorTStamp_sec = (val)) //!< LCRTVG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // LCRTVG_PRIVATE_H_
