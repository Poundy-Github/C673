/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJATVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJATVG_private.h
//! @brief     (TJATVG) Module Private Header.

#ifndef TJATVG_PRIVATE_H_
#define TJATVG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJATVG	//!< TJATVG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJATVG.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TJATVG_SenReset		0xF0 //!< TJATVG module reset runnable identifier.
#define RUNNABLE_ID_TJATVG_SenProcess	0xF1 //!< TJATVG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJATVG_SenOutType *TJATVG_SenOutPtr = NULL; //!< TJATVG module sensor output data pointer.
void TJATVG_SenInitOutPtr(TJATVG_SenOutType *TJATVG_SenOutArg) { TJATVG_SenOutPtr = TJATVG_SenOutPtr == NULL ? TJATVG_SenOutArg : TJATVG_SenOutPtr; }
const TJATVG_SenOutType* TJATVG_SenGetOutPtr(void) { return (const TJATVG_SenOutType*) TJATVG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TJATVG_CrvAmplActivated_nu
#define	S_TJATVG_CrvAmplActivated_nu (TJATVG_SenOutPtr->S_TJATVG_CrvAmplActivated_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_CrvAmplActivated_nu(val)	(S_TJATVG_CrvAmplActivated_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_DeratingLevel_nu
#define	S_TJATVG_DeratingLevel_nu (TJATVG_SenOutPtr->S_TJATVG_DeratingLevel_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_DeratingLevel_nu(val)	(S_TJATVG_DeratingLevel_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_DistYTolLeTgtArea_met
#define	S_TJATVG_DistYTolLeTgtArea_met (TJATVG_SenOutPtr->S_TJATVG_DistYTolLeTgtArea_met) //!< TJATVG debug macro.
#define	SET_S_TJATVG_DistYTolLeTgtArea_met(val)	(S_TJATVG_DistYTolLeTgtArea_met = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_DistYTolRiTgtArea_met
#define	S_TJATVG_DistYTolRiTgtArea_met (TJATVG_SenOutPtr->S_TJATVG_DistYTolRiTgtArea_met) //!< TJATVG debug macro.
#define	SET_S_TJATVG_DistYTolRiTgtArea_met(val)	(S_TJATVG_DistYTolRiTgtArea_met = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_FTireAclMax_mps2
#define	S_TJATVG_FTireAclMax_mps2 (TJATVG_SenOutPtr->S_TJATVG_FTireAclMax_mps2) //!< TJATVG debug macro.
#define	SET_S_TJATVG_FTireAclMax_mps2(val)	(S_TJATVG_FTireAclMax_mps2 = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_FTireAclMin_mps2
#define	S_TJATVG_FTireAclMin_mps2 (TJATVG_SenOutPtr->S_TJATVG_FTireAclMin_mps2) //!< TJATVG debug macro.
#define	SET_S_TJATVG_FTireAclMin_mps2(val)	(S_TJATVG_FTireAclMin_mps2 = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_GrdLimitTgtCrvTGC_1pms
#define	S_TJATVG_GrdLimitTgtCrvTGC_1pms (TJATVG_SenOutPtr->S_TJATVG_GrdLimitTgtCrvTGC_1pms) //!< TJATVG debug macro.
#define	SET_S_TJATVG_GrdLimitTgtCrvTGC_1pms(val)	(S_TJATVG_GrdLimitTgtCrvTGC_1pms = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_HighStatAccu_bool
#define	S_TJATVG_HighStatAccu_bool (TJATVG_SenOutPtr->S_TJATVG_HighStatAccu_bool) //!< TJATVG debug macro.
#define	SET_S_TJATVG_HighStatAccu_bool(val)	(S_TJATVG_HighStatAccu_bool = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_LimiterActivated_nu
#define	S_TJATVG_LimiterActivated_nu (TJATVG_SenOutPtr->S_TJATVG_LimiterActivated_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_LimiterActivated_nu(val)	(S_TJATVG_LimiterActivated_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_LimiterTimeDuration_sec
#define	S_TJATVG_LimiterTimeDuration_sec (TJATVG_SenOutPtr->S_TJATVG_LimiterTimeDuration_sec) //!< TJATVG debug macro.
#define	SET_S_TJATVG_LimiterTimeDuration_sec(val)	(S_TJATVG_LimiterTimeDuration_sec = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_LimiterType_nu
#define	S_TJATVG_LimiterType_nu (TJATVG_SenOutPtr->S_TJATVG_LimiterType_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_LimiterType_nu(val)	(S_TJATVG_LimiterType_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_LtcyCompActivated_nu
#define	S_TJATVG_LtcyCompActivated_nu (TJATVG_SenOutPtr->S_TJATVG_LtcyCompActivated_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_LtcyCompActivated_nu(val)	(S_TJATVG_LtcyCompActivated_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_MaxCrvGrdBuildup_1pms
#define	S_TJATVG_MaxCrvGrdBuildup_1pms (TJATVG_SenOutPtr->S_TJATVG_MaxCrvGrdBuildup_1pms) //!< TJATVG debug macro.
#define	SET_S_TJATVG_MaxCrvGrdBuildup_1pms(val)	(S_TJATVG_MaxCrvGrdBuildup_1pms = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_MaxCrvGrdRed_1pms
#define	S_TJATVG_MaxCrvGrdRed_1pms (TJATVG_SenOutPtr->S_TJATVG_MaxCrvGrdRed_1pms) //!< TJATVG debug macro.
#define	SET_S_TJATVG_MaxCrvGrdRed_1pms(val)	(S_TJATVG_MaxCrvGrdRed_1pms = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_MaxCrvTrajGuiCtrl_1pm
#define	S_TJATVG_MaxCrvTrajGuiCtrl_1pm (TJATVG_SenOutPtr->S_TJATVG_MaxCrvTrajGuiCtrl_1pm) //!< TJATVG debug macro.
#define	SET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm(val)	(S_TJATVG_MaxCrvTrajGuiCtrl_1pm = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_MaxJerkAllowed_mps3
#define	S_TJATVG_MaxJerkAllowed_mps3 (TJATVG_SenOutPtr->S_TJATVG_MaxJerkAllowed_mps3) //!< TJATVG debug macro.
#define	SET_S_TJATVG_MaxJerkAllowed_mps3(val)	(S_TJATVG_MaxJerkAllowed_mps3 = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_MaxTrqScalGrad_1ps
#define	S_TJATVG_MaxTrqScalGrad_1ps (TJATVG_SenOutPtr->S_TJATVG_MaxTrqScalGrad_1ps) //!< TJATVG debug macro.
#define	SET_S_TJATVG_MaxTrqScalGrad_1ps(val)	(S_TJATVG_MaxTrqScalGrad_1ps = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_MaxTrqScalLimit_nu
#define	S_TJATVG_MaxTrqScalLimit_nu (TJATVG_SenOutPtr->S_TJATVG_MaxTrqScalLimit_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_MaxTrqScalLimit_nu(val)	(S_TJATVG_MaxTrqScalLimit_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_ObstacleAclX_mps2
#define	S_TJATVG_ObstacleAclX_mps2 (TJATVG_SenOutPtr->S_TJATVG_ObstacleAclX_mps2) //!< TJATVG debug macro.
#define	SET_S_TJATVG_ObstacleAclX_mps2(val)	(S_TJATVG_ObstacleAclX_mps2 = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_ObstacleDistX_met
#define	S_TJATVG_ObstacleDistX_met (TJATVG_SenOutPtr->S_TJATVG_ObstacleDistX_met) //!< TJATVG debug macro.
#define	SET_S_TJATVG_ObstacleDistX_met(val)	(S_TJATVG_ObstacleDistX_met = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_ObstacleDistY_met
#define	S_TJATVG_ObstacleDistY_met (TJATVG_SenOutPtr->S_TJATVG_ObstacleDistY_met) //!< TJATVG debug macro.
#define	SET_S_TJATVG_ObstacleDistY_met(val)	(S_TJATVG_ObstacleDistY_met = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_ObstacleVelX_mps
#define	S_TJATVG_ObstacleVelX_mps (TJATVG_SenOutPtr->S_TJATVG_ObstacleVelX_mps) //!< TJATVG debug macro.
#define	SET_S_TJATVG_ObstacleVelX_mps(val)	(S_TJATVG_ObstacleVelX_mps = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_ObstacleWidth_met
#define	S_TJATVG_ObstacleWidth_met (TJATVG_SenOutPtr->S_TJATVG_ObstacleWidth_met) //!< TJATVG debug macro.
#define	SET_S_TJATVG_ObstacleWidth_met(val)	(S_TJATVG_ObstacleWidth_met = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_PlanningHorizon_sec
#define	S_TJATVG_PlanningHorizon_sec (TJATVG_SenOutPtr->S_TJATVG_PlanningHorizon_sec) //!< TJATVG debug macro.
#define	SET_S_TJATVG_PlanningHorizon_sec(val)	(S_TJATVG_PlanningHorizon_sec = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_PredTimeCrv_sec
#define	S_TJATVG_PredTimeCrv_sec (TJATVG_SenOutPtr->S_TJATVG_PredTimeCrv_sec) //!< TJATVG debug macro.
#define	SET_S_TJATVG_PredTimeCrv_sec(val)	(S_TJATVG_PredTimeCrv_sec = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_PredTimeHeadAng_sec
#define	S_TJATVG_PredTimeHeadAng_sec (TJATVG_SenOutPtr->S_TJATVG_PredTimeHeadAng_sec) //!< TJATVG debug macro.
#define	SET_S_TJATVG_PredTimeHeadAng_sec(val)	(S_TJATVG_PredTimeHeadAng_sec = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_SensorTStamp_sec
#define	S_TJATVG_SensorTStamp_sec (TJATVG_SenOutPtr->S_TJATVG_SensorTStamp_sec) //!< TJATVG debug macro.
#define	SET_S_TJATVG_SensorTStamp_sec(val)	(S_TJATVG_SensorTStamp_sec = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_StrWhStifGrad_1ps
#define	S_TJATVG_StrWhStifGrad_1ps (TJATVG_SenOutPtr->S_TJATVG_StrWhStifGrad_1ps) //!< TJATVG debug macro.
#define	SET_S_TJATVG_StrWhStifGrad_1ps(val)	(S_TJATVG_StrWhStifGrad_1ps = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_StrWhStifLimit_nu
#define	S_TJATVG_StrWhStifLimit_nu (TJATVG_SenOutPtr->S_TJATVG_StrWhStifLimit_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_StrWhStifLimit_nu(val)	(S_TJATVG_StrWhStifLimit_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_TrajGuiQu_nu
#define	S_TJATVG_TrajGuiQu_nu (TJATVG_SenOutPtr->S_TJATVG_TrajGuiQu_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_TrajGuiQu_nu(val)	(S_TJATVG_TrajGuiQu_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_TrajPlanServQu_nu
#define	S_TJATVG_TrajPlanServQu_nu (TJATVG_SenOutPtr->S_TJATVG_TrajPlanServQu_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_TrajPlanServQu_nu(val)	(S_TJATVG_TrajPlanServQu_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_TriggerReplan_nu
#define	S_TJATVG_TriggerReplan_nu (TJATVG_SenOutPtr->S_TJATVG_TriggerReplan_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_TriggerReplan_nu(val)	(S_TJATVG_TriggerReplan_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_TrqRampGrad_1ps
#define	S_TJATVG_TrqRampGrad_1ps (TJATVG_SenOutPtr->S_TJATVG_TrqRampGrad_1ps) //!< TJATVG debug macro.
#define	SET_S_TJATVG_TrqRampGrad_1ps(val)	(S_TJATVG_TrqRampGrad_1ps = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_WeightEndTime_nu
#define	S_TJATVG_WeightEndTime_nu (TJATVG_SenOutPtr->S_TJATVG_WeightEndTime_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_WeightEndTime_nu(val)	(S_TJATVG_WeightEndTime_nu = (val)) //!< TJATVG debug macro setter.

#undef	S_TJATVG_WeightTgtDistY_nu
#define	S_TJATVG_WeightTgtDistY_nu (TJATVG_SenOutPtr->S_TJATVG_WeightTgtDistY_nu) //!< TJATVG debug macro.
#define	SET_S_TJATVG_WeightTgtDistY_nu(val)	(S_TJATVG_WeightTgtDistY_nu = (val)) //!< TJATVG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TJATVG_PRIVATE_H_
