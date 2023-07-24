/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : CTRSC
  MODULE        : CSCLTA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     CSCLTA_private.h
//! @brief     (CSCLTA) Module Private Header.

#ifndef CSCLTA_PRIVATE_H_
#define CSCLTA_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define CTRSC	//!< CTRSC sub-component input macro switch.
#define CSCLTA	//!< CSCLTA module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "CSCLTA.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_CSCLTA_SenReset		0xF0 //!< CSCLTA module reset runnable identifier.
#define RUNNABLE_ID_CSCLTA_SenProcess	0xF1 //!< CSCLTA module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static CSCLTA_SenOutType *CSCLTA_SenOutPtr = NULL; //!< CSCLTA module sensor output data pointer.
void CSCLTA_SenInitOutPtr(CSCLTA_SenOutType *CSCLTA_SenOutArg) { CSCLTA_SenOutPtr = CSCLTA_SenOutPtr == NULL ? CSCLTA_SenOutArg : CSCLTA_SenOutPtr; }
const CSCLTA_SenOutType* CSCLTA_SenGetOutPtr(void) { return (const CSCLTA_SenOutType*) CSCLTA_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_CSCLTA_DeratingLevel_nu
#define	S_CSCLTA_DeratingLevel_nu (CSCLTA_SenOutPtr->S_CSCLTA_DeratingLevel_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_DeratingLevel_nu(val)	(S_CSCLTA_DeratingLevel_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_DistYTolLeTgtArea_met
#define	S_CSCLTA_DistYTolLeTgtArea_met (CSCLTA_SenOutPtr->S_CSCLTA_DistYTolLeTgtArea_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_DistYTolLeTgtArea_met(val)	(S_CSCLTA_DistYTolLeTgtArea_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_DistYTolRiTgtArea_met
#define	S_CSCLTA_DistYTolRiTgtArea_met (CSCLTA_SenOutPtr->S_CSCLTA_DistYTolRiTgtArea_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_DistYTolRiTgtArea_met(val)	(S_CSCLTA_DistYTolRiTgtArea_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_FTireAclMax_mps2
#define	S_CSCLTA_FTireAclMax_mps2 (CSCLTA_SenOutPtr->S_CSCLTA_FTireAclMax_mps2) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_FTireAclMax_mps2(val)	(S_CSCLTA_FTireAclMax_mps2 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_FTireAclMin_mps2
#define	S_CSCLTA_FTireAclMin_mps2 (CSCLTA_SenOutPtr->S_CSCLTA_FTireAclMin_mps2) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_FTireAclMin_mps2(val)	(S_CSCLTA_FTireAclMin_mps2 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_GrdLimitTgtCrvTGC_1pms
#define	S_CSCLTA_GrdLimitTgtCrvTGC_1pms (CSCLTA_SenOutPtr->S_CSCLTA_GrdLimitTgtCrvTGC_1pms) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms(val)	(S_CSCLTA_GrdLimitTgtCrvTGC_1pms = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_HighStatAccu_bool
#define	S_CSCLTA_HighStatAccu_bool (CSCLTA_SenOutPtr->S_CSCLTA_HighStatAccu_bool) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_HighStatAccu_bool(val)	(S_CSCLTA_HighStatAccu_bool = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LatencyCompActivated_nu
#define	S_CSCLTA_LatencyCompActivated_nu (CSCLTA_SenOutPtr->S_CSCLTA_LatencyCompActivated_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LatencyCompActivated_nu(val)	(S_CSCLTA_LatencyCompActivated_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LeCridrBndCrvChng_1pm2
#define	S_CSCLTA_LeCridrBndCrvChng_1pm2 (CSCLTA_SenOutPtr->S_CSCLTA_LeCridrBndCrvChng_1pm2) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LeCridrBndCrvChng_1pm2(val)	(S_CSCLTA_LeCridrBndCrvChng_1pm2 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LeCridrBndCrv_1pm
#define	S_CSCLTA_LeCridrBndCrv_1pm (CSCLTA_SenOutPtr->S_CSCLTA_LeCridrBndCrv_1pm) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LeCridrBndCrv_1pm(val)	(S_CSCLTA_LeCridrBndCrv_1pm = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LeCridrBndHeadAng_rad
#define	S_CSCLTA_LeCridrBndHeadAng_rad (CSCLTA_SenOutPtr->S_CSCLTA_LeCridrBndHeadAng_rad) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LeCridrBndHeadAng_rad(val)	(S_CSCLTA_LeCridrBndHeadAng_rad = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LeCridrBndLength_met
#define	S_CSCLTA_LeCridrBndLength_met (CSCLTA_SenOutPtr->S_CSCLTA_LeCridrBndLength_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LeCridrBndLength_met(val)	(S_CSCLTA_LeCridrBndLength_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LeCridrBndPosX0_met
#define	S_CSCLTA_LeCridrBndPosX0_met (CSCLTA_SenOutPtr->S_CSCLTA_LeCridrBndPosX0_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LeCridrBndPosX0_met(val)	(S_CSCLTA_LeCridrBndPosX0_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LeCridrBndPosY0_met
#define	S_CSCLTA_LeCridrBndPosY0_met (CSCLTA_SenOutPtr->S_CSCLTA_LeCridrBndPosY0_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LeCridrBndPosY0_met(val)	(S_CSCLTA_LeCridrBndPosY0_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LimiterActivated_nu
#define	S_CSCLTA_LimiterActivated_nu (CSCLTA_SenOutPtr->S_CSCLTA_LimiterActivated_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LimiterActivated_nu(val)	(S_CSCLTA_LimiterActivated_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_LimiterTimeDuration_sec
#define	S_CSCLTA_LimiterTimeDuration_sec (CSCLTA_SenOutPtr->S_CSCLTA_LimiterTimeDuration_sec) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_LimiterTimeDuration_sec(val)	(S_CSCLTA_LimiterTimeDuration_sec = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_MaxCrvGrdBuildup_1pms
#define	S_CSCLTA_MaxCrvGrdBuildup_1pms (CSCLTA_SenOutPtr->S_CSCLTA_MaxCrvGrdBuildup_1pms) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_MaxCrvGrdBuildup_1pms(val)	(S_CSCLTA_MaxCrvGrdBuildup_1pms = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_MaxCrvGrdRed_1pms
#define	S_CSCLTA_MaxCrvGrdRed_1pms (CSCLTA_SenOutPtr->S_CSCLTA_MaxCrvGrdRed_1pms) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_MaxCrvGrdRed_1pms(val)	(S_CSCLTA_MaxCrvGrdRed_1pms = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_MaxCrvTrajGuiCtrl_1pm
#define	S_CSCLTA_MaxCrvTrajGuiCtrl_1pm (CSCLTA_SenOutPtr->S_CSCLTA_MaxCrvTrajGuiCtrl_1pm) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm(val)	(S_CSCLTA_MaxCrvTrajGuiCtrl_1pm = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_MaxJerkAllowed_mps3
#define	S_CSCLTA_MaxJerkAllowed_mps3 (CSCLTA_SenOutPtr->S_CSCLTA_MaxJerkAllowed_mps3) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_MaxJerkAllowed_mps3(val)	(S_CSCLTA_MaxJerkAllowed_mps3 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_MaxTrqScalGrad_1ps
#define	S_CSCLTA_MaxTrqScalGrad_1ps (CSCLTA_SenOutPtr->S_CSCLTA_MaxTrqScalGrad_1ps) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_MaxTrqScalGrad_1ps(val)	(S_CSCLTA_MaxTrqScalGrad_1ps = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_MaxTrqScalLimit_nu
#define	S_CSCLTA_MaxTrqScalLimit_nu (CSCLTA_SenOutPtr->S_CSCLTA_MaxTrqScalLimit_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_MaxTrqScalLimit_nu(val)	(S_CSCLTA_MaxTrqScalLimit_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_ObstacleAclX_mps2
#define	S_CSCLTA_ObstacleAclX_mps2 (CSCLTA_SenOutPtr->S_CSCLTA_ObstacleAclX_mps2) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_ObstacleAclX_mps2(val)	(S_CSCLTA_ObstacleAclX_mps2 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_ObstacleDistX_met
#define	S_CSCLTA_ObstacleDistX_met (CSCLTA_SenOutPtr->S_CSCLTA_ObstacleDistX_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_ObstacleDistX_met(val)	(S_CSCLTA_ObstacleDistX_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_ObstacleDistY_met
#define	S_CSCLTA_ObstacleDistY_met (CSCLTA_SenOutPtr->S_CSCLTA_ObstacleDistY_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_ObstacleDistY_met(val)	(S_CSCLTA_ObstacleDistY_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_ObstacleVelX_mps
#define	S_CSCLTA_ObstacleVelX_mps (CSCLTA_SenOutPtr->S_CSCLTA_ObstacleVelX_mps) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_ObstacleVelX_mps(val)	(S_CSCLTA_ObstacleVelX_mps = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_ObstacleWidth_met
#define	S_CSCLTA_ObstacleWidth_met (CSCLTA_SenOutPtr->S_CSCLTA_ObstacleWidth_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_ObstacleWidth_met(val)	(S_CSCLTA_ObstacleWidth_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_PlanningHorizon_sec
#define	S_CSCLTA_PlanningHorizon_sec (CSCLTA_SenOutPtr->S_CSCLTA_PlanningHorizon_sec) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_PlanningHorizon_sec(val)	(S_CSCLTA_PlanningHorizon_sec = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_PredTimeHeadAng_sec
#define	S_CSCLTA_PredTimeHeadAng_sec (CSCLTA_SenOutPtr->S_CSCLTA_PredTimeHeadAng_sec) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_PredTimeHeadAng_sec(val)	(S_CSCLTA_PredTimeHeadAng_sec = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_PredictionTimeCrv_sec
#define	S_CSCLTA_PredictionTimeCrv_sec (CSCLTA_SenOutPtr->S_CSCLTA_PredictionTimeCrv_sec) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_PredictionTimeCrv_sec(val)	(S_CSCLTA_PredictionTimeCrv_sec = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_RiCridrBndCrvChng_1pm2
#define	S_CSCLTA_RiCridrBndCrvChng_1pm2 (CSCLTA_SenOutPtr->S_CSCLTA_RiCridrBndCrvChng_1pm2) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_RiCridrBndCrvChng_1pm2(val)	(S_CSCLTA_RiCridrBndCrvChng_1pm2 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_RiCridrBndCrv_1pm
#define	S_CSCLTA_RiCridrBndCrv_1pm (CSCLTA_SenOutPtr->S_CSCLTA_RiCridrBndCrv_1pm) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_RiCridrBndCrv_1pm(val)	(S_CSCLTA_RiCridrBndCrv_1pm = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_RiCridrBndHeadAng_rad
#define	S_CSCLTA_RiCridrBndHeadAng_rad (CSCLTA_SenOutPtr->S_CSCLTA_RiCridrBndHeadAng_rad) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_RiCridrBndHeadAng_rad(val)	(S_CSCLTA_RiCridrBndHeadAng_rad = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_RiCridrBndLength_met
#define	S_CSCLTA_RiCridrBndLength_met (CSCLTA_SenOutPtr->S_CSCLTA_RiCridrBndLength_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_RiCridrBndLength_met(val)	(S_CSCLTA_RiCridrBndLength_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_RiCridrBndPosX0_met
#define	S_CSCLTA_RiCridrBndPosX0_met (CSCLTA_SenOutPtr->S_CSCLTA_RiCridrBndPosX0_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_RiCridrBndPosX0_met(val)	(S_CSCLTA_RiCridrBndPosX0_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_RiCridrBndPosY0_met
#define	S_CSCLTA_RiCridrBndPosY0_met (CSCLTA_SenOutPtr->S_CSCLTA_RiCridrBndPosY0_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_RiCridrBndPosY0_met(val)	(S_CSCLTA_RiCridrBndPosY0_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_SensorTStamp_sec
#define	S_CSCLTA_SensorTStamp_sec (CSCLTA_SenOutPtr->S_CSCLTA_SensorTStamp_sec) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_SensorTStamp_sec(val)	(S_CSCLTA_SensorTStamp_sec = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_StrWhStifGrad_1ps
#define	S_CSCLTA_StrWhStifGrad_1ps (CSCLTA_SenOutPtr->S_CSCLTA_StrWhStifGrad_1ps) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_StrWhStifGrad_1ps(val)	(S_CSCLTA_StrWhStifGrad_1ps = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_StrWhStifLimit_nu
#define	S_CSCLTA_StrWhStifLimit_nu (CSCLTA_SenOutPtr->S_CSCLTA_StrWhStifLimit_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_StrWhStifLimit_nu(val)	(S_CSCLTA_StrWhStifLimit_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_SysStateLCF_enum
#define	S_CSCLTA_SysStateLCF_enum (CSCLTA_SenOutPtr->S_CSCLTA_SysStateLCF_enum) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_SysStateLCF_enum(val)	(S_CSCLTA_SysStateLCF_enum = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TgtTrajCrvChng_1pm2
#define	S_CSCLTA_TgtTrajCrvChng_1pm2 (CSCLTA_SenOutPtr->S_CSCLTA_TgtTrajCrvChng_1pm2) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TgtTrajCrvChng_1pm2(val)	(S_CSCLTA_TgtTrajCrvChng_1pm2 = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TgtTrajCrv_1pm
#define	S_CSCLTA_TgtTrajCrv_1pm (CSCLTA_SenOutPtr->S_CSCLTA_TgtTrajCrv_1pm) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TgtTrajCrv_1pm(val)	(S_CSCLTA_TgtTrajCrv_1pm = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TgtTrajHeadAng_rad
#define	S_CSCLTA_TgtTrajHeadAng_rad (CSCLTA_SenOutPtr->S_CSCLTA_TgtTrajHeadAng_rad) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TgtTrajHeadAng_rad(val)	(S_CSCLTA_TgtTrajHeadAng_rad = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TgtTrajLength_met
#define	S_CSCLTA_TgtTrajLength_met (CSCLTA_SenOutPtr->S_CSCLTA_TgtTrajLength_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TgtTrajLength_met(val)	(S_CSCLTA_TgtTrajLength_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TgtTrajPosX0_met
#define	S_CSCLTA_TgtTrajPosX0_met (CSCLTA_SenOutPtr->S_CSCLTA_TgtTrajPosX0_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TgtTrajPosX0_met(val)	(S_CSCLTA_TgtTrajPosX0_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TgtTrajPosY0_met
#define	S_CSCLTA_TgtTrajPosY0_met (CSCLTA_SenOutPtr->S_CSCLTA_TgtTrajPosY0_met) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TgtTrajPosY0_met(val)	(S_CSCLTA_TgtTrajPosY0_met = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TrajGuiQualifier_nu
#define	S_CSCLTA_TrajGuiQualifier_nu (CSCLTA_SenOutPtr->S_CSCLTA_TrajGuiQualifier_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TrajGuiQualifier_nu(val)	(S_CSCLTA_TrajGuiQualifier_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TrajPlanServQu_nu
#define	S_CSCLTA_TrajPlanServQu_nu (CSCLTA_SenOutPtr->S_CSCLTA_TrajPlanServQu_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TrajPlanServQu_nu(val)	(S_CSCLTA_TrajPlanServQu_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TriggerReplan_nu
#define	S_CSCLTA_TriggerReplan_nu (CSCLTA_SenOutPtr->S_CSCLTA_TriggerReplan_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TriggerReplan_nu(val)	(S_CSCLTA_TriggerReplan_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_TrqRampGrad_1ps
#define	S_CSCLTA_TrqRampGrad_1ps (CSCLTA_SenOutPtr->S_CSCLTA_TrqRampGrad_1ps) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_TrqRampGrad_1ps(val)	(S_CSCLTA_TrqRampGrad_1ps = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_WeightEndTime_nu
#define	S_CSCLTA_WeightEndTime_nu (CSCLTA_SenOutPtr->S_CSCLTA_WeightEndTime_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_WeightEndTime_nu(val)	(S_CSCLTA_WeightEndTime_nu = (val)) //!< CSCLTA debug macro setter.

#undef	S_CSCLTA_WeightTgtDistY_nu
#define	S_CSCLTA_WeightTgtDistY_nu (CSCLTA_SenOutPtr->S_CSCLTA_WeightTgtDistY_nu) //!< CSCLTA debug macro.
#define	SET_S_CSCLTA_WeightTgtDistY_nu(val)	(S_CSCLTA_WeightTgtDistY_nu = (val)) //!< CSCLTA debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // CSCLTA_PRIVATE_H_
