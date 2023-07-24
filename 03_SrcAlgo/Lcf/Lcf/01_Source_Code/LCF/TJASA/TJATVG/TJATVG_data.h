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
//! @file     TJATVG_data.h
//! @brief     (TJATVG) Module Data Header.

#ifndef TJATVG_DATA_H_
#define TJATVG_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TJATVG module sensor get function. Function gets TJATVG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJATVG_SenOutPtr</b> Global static pointer to TJATVG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJATVG_SenOutType* TJATVG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TJATVG_CrvAmplActivated_nu
#define S_TJATVG_CrvAmplActivated_nu (TJATVG_SenGetOutPtr()->S_TJATVG_CrvAmplActivated_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_CrvAmplActivated_nu() (S_TJATVG_CrvAmplActivated_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_CrvAmplActivated_nu

#ifndef S_TJATVG_DeratingLevel_nu
#define S_TJATVG_DeratingLevel_nu (TJATVG_SenGetOutPtr()->S_TJATVG_DeratingLevel_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_DeratingLevel_nu() (S_TJATVG_DeratingLevel_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_DeratingLevel_nu

#ifndef S_TJATVG_DistYTolLeTgtArea_met
#define S_TJATVG_DistYTolLeTgtArea_met (TJATVG_SenGetOutPtr()->S_TJATVG_DistYTolLeTgtArea_met) //!< TJATVG output macro.
#define GET_S_TJATVG_DistYTolLeTgtArea_met() (S_TJATVG_DistYTolLeTgtArea_met) //!< TJATVG output macro getter.
#endif // S_TJATVG_DistYTolLeTgtArea_met

#ifndef S_TJATVG_DistYTolRiTgtArea_met
#define S_TJATVG_DistYTolRiTgtArea_met (TJATVG_SenGetOutPtr()->S_TJATVG_DistYTolRiTgtArea_met) //!< TJATVG output macro.
#define GET_S_TJATVG_DistYTolRiTgtArea_met() (S_TJATVG_DistYTolRiTgtArea_met) //!< TJATVG output macro getter.
#endif // S_TJATVG_DistYTolRiTgtArea_met

#ifndef S_TJATVG_FTireAclMax_mps2
#define S_TJATVG_FTireAclMax_mps2 (TJATVG_SenGetOutPtr()->S_TJATVG_FTireAclMax_mps2) //!< TJATVG output macro.
#define GET_S_TJATVG_FTireAclMax_mps2() (S_TJATVG_FTireAclMax_mps2) //!< TJATVG output macro getter.
#endif // S_TJATVG_FTireAclMax_mps2

#ifndef S_TJATVG_FTireAclMin_mps2
#define S_TJATVG_FTireAclMin_mps2 (TJATVG_SenGetOutPtr()->S_TJATVG_FTireAclMin_mps2) //!< TJATVG output macro.
#define GET_S_TJATVG_FTireAclMin_mps2() (S_TJATVG_FTireAclMin_mps2) //!< TJATVG output macro getter.
#endif // S_TJATVG_FTireAclMin_mps2

#ifndef S_TJATVG_GrdLimitTgtCrvTGC_1pms
#define S_TJATVG_GrdLimitTgtCrvTGC_1pms (TJATVG_SenGetOutPtr()->S_TJATVG_GrdLimitTgtCrvTGC_1pms) //!< TJATVG output macro.
#define GET_S_TJATVG_GrdLimitTgtCrvTGC_1pms() (S_TJATVG_GrdLimitTgtCrvTGC_1pms) //!< TJATVG output macro getter.
#endif // S_TJATVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_TJATVG_HighStatAccu_bool
#define S_TJATVG_HighStatAccu_bool (TJATVG_SenGetOutPtr()->S_TJATVG_HighStatAccu_bool) //!< TJATVG output macro.
#define GET_S_TJATVG_HighStatAccu_bool() (S_TJATVG_HighStatAccu_bool) //!< TJATVG output macro getter.
#endif // S_TJATVG_HighStatAccu_bool

#ifndef S_TJATVG_LimiterActivated_nu
#define S_TJATVG_LimiterActivated_nu (TJATVG_SenGetOutPtr()->S_TJATVG_LimiterActivated_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_LimiterActivated_nu() (S_TJATVG_LimiterActivated_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_LimiterActivated_nu

#ifndef S_TJATVG_LimiterTimeDuration_sec
#define S_TJATVG_LimiterTimeDuration_sec (TJATVG_SenGetOutPtr()->S_TJATVG_LimiterTimeDuration_sec) //!< TJATVG output macro.
#define GET_S_TJATVG_LimiterTimeDuration_sec() (S_TJATVG_LimiterTimeDuration_sec) //!< TJATVG output macro getter.
#endif // S_TJATVG_LimiterTimeDuration_sec

#ifndef S_TJATVG_LimiterType_nu
#define S_TJATVG_LimiterType_nu (TJATVG_SenGetOutPtr()->S_TJATVG_LimiterType_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_LimiterType_nu() (S_TJATVG_LimiterType_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_LimiterType_nu

#ifndef S_TJATVG_LtcyCompActivated_nu
#define S_TJATVG_LtcyCompActivated_nu (TJATVG_SenGetOutPtr()->S_TJATVG_LtcyCompActivated_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_LtcyCompActivated_nu() (S_TJATVG_LtcyCompActivated_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_LtcyCompActivated_nu

#ifndef S_TJATVG_MaxCrvGrdBuildup_1pms
#define S_TJATVG_MaxCrvGrdBuildup_1pms (TJATVG_SenGetOutPtr()->S_TJATVG_MaxCrvGrdBuildup_1pms) //!< TJATVG output macro.
#define GET_S_TJATVG_MaxCrvGrdBuildup_1pms() (S_TJATVG_MaxCrvGrdBuildup_1pms) //!< TJATVG output macro getter.
#endif // S_TJATVG_MaxCrvGrdBuildup_1pms

#ifndef S_TJATVG_MaxCrvGrdRed_1pms
#define S_TJATVG_MaxCrvGrdRed_1pms (TJATVG_SenGetOutPtr()->S_TJATVG_MaxCrvGrdRed_1pms) //!< TJATVG output macro.
#define GET_S_TJATVG_MaxCrvGrdRed_1pms() (S_TJATVG_MaxCrvGrdRed_1pms) //!< TJATVG output macro getter.
#endif // S_TJATVG_MaxCrvGrdRed_1pms

#ifndef S_TJATVG_MaxCrvTrajGuiCtrl_1pm
#define S_TJATVG_MaxCrvTrajGuiCtrl_1pm (TJATVG_SenGetOutPtr()->S_TJATVG_MaxCrvTrajGuiCtrl_1pm) //!< TJATVG output macro.
#define GET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm() (S_TJATVG_MaxCrvTrajGuiCtrl_1pm) //!< TJATVG output macro getter.
#endif // S_TJATVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_TJATVG_MaxJerkAllowed_mps3
#define S_TJATVG_MaxJerkAllowed_mps3 (TJATVG_SenGetOutPtr()->S_TJATVG_MaxJerkAllowed_mps3) //!< TJATVG output macro.
#define GET_S_TJATVG_MaxJerkAllowed_mps3() (S_TJATVG_MaxJerkAllowed_mps3) //!< TJATVG output macro getter.
#endif // S_TJATVG_MaxJerkAllowed_mps3

#ifndef S_TJATVG_MaxTrqScalGrad_1ps
#define S_TJATVG_MaxTrqScalGrad_1ps (TJATVG_SenGetOutPtr()->S_TJATVG_MaxTrqScalGrad_1ps) //!< TJATVG output macro.
#define GET_S_TJATVG_MaxTrqScalGrad_1ps() (S_TJATVG_MaxTrqScalGrad_1ps) //!< TJATVG output macro getter.
#endif // S_TJATVG_MaxTrqScalGrad_1ps

#ifndef S_TJATVG_MaxTrqScalLimit_nu
#define S_TJATVG_MaxTrqScalLimit_nu (TJATVG_SenGetOutPtr()->S_TJATVG_MaxTrqScalLimit_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_MaxTrqScalLimit_nu() (S_TJATVG_MaxTrqScalLimit_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_MaxTrqScalLimit_nu

#ifndef S_TJATVG_ObstacleAclX_mps2
#define S_TJATVG_ObstacleAclX_mps2 (TJATVG_SenGetOutPtr()->S_TJATVG_ObstacleAclX_mps2) //!< TJATVG output macro.
#define GET_S_TJATVG_ObstacleAclX_mps2() (S_TJATVG_ObstacleAclX_mps2) //!< TJATVG output macro getter.
#endif // S_TJATVG_ObstacleAclX_mps2

#ifndef S_TJATVG_ObstacleDistX_met
#define S_TJATVG_ObstacleDistX_met (TJATVG_SenGetOutPtr()->S_TJATVG_ObstacleDistX_met) //!< TJATVG output macro.
#define GET_S_TJATVG_ObstacleDistX_met() (S_TJATVG_ObstacleDistX_met) //!< TJATVG output macro getter.
#endif // S_TJATVG_ObstacleDistX_met

#ifndef S_TJATVG_ObstacleDistY_met
#define S_TJATVG_ObstacleDistY_met (TJATVG_SenGetOutPtr()->S_TJATVG_ObstacleDistY_met) //!< TJATVG output macro.
#define GET_S_TJATVG_ObstacleDistY_met() (S_TJATVG_ObstacleDistY_met) //!< TJATVG output macro getter.
#endif // S_TJATVG_ObstacleDistY_met

#ifndef S_TJATVG_ObstacleVelX_mps
#define S_TJATVG_ObstacleVelX_mps (TJATVG_SenGetOutPtr()->S_TJATVG_ObstacleVelX_mps) //!< TJATVG output macro.
#define GET_S_TJATVG_ObstacleVelX_mps() (S_TJATVG_ObstacleVelX_mps) //!< TJATVG output macro getter.
#endif // S_TJATVG_ObstacleVelX_mps

#ifndef S_TJATVG_ObstacleWidth_met
#define S_TJATVG_ObstacleWidth_met (TJATVG_SenGetOutPtr()->S_TJATVG_ObstacleWidth_met) //!< TJATVG output macro.
#define GET_S_TJATVG_ObstacleWidth_met() (S_TJATVG_ObstacleWidth_met) //!< TJATVG output macro getter.
#endif // S_TJATVG_ObstacleWidth_met

#ifndef S_TJATVG_PlanningHorizon_sec
#define S_TJATVG_PlanningHorizon_sec (TJATVG_SenGetOutPtr()->S_TJATVG_PlanningHorizon_sec) //!< TJATVG output macro.
#define GET_S_TJATVG_PlanningHorizon_sec() (S_TJATVG_PlanningHorizon_sec) //!< TJATVG output macro getter.
#endif // S_TJATVG_PlanningHorizon_sec

#ifndef S_TJATVG_PredTimeCrv_sec
#define S_TJATVG_PredTimeCrv_sec (TJATVG_SenGetOutPtr()->S_TJATVG_PredTimeCrv_sec) //!< TJATVG output macro.
#define GET_S_TJATVG_PredTimeCrv_sec() (S_TJATVG_PredTimeCrv_sec) //!< TJATVG output macro getter.
#endif // S_TJATVG_PredTimeCrv_sec

#ifndef S_TJATVG_PredTimeHeadAng_sec
#define S_TJATVG_PredTimeHeadAng_sec (TJATVG_SenGetOutPtr()->S_TJATVG_PredTimeHeadAng_sec) //!< TJATVG output macro.
#define GET_S_TJATVG_PredTimeHeadAng_sec() (S_TJATVG_PredTimeHeadAng_sec) //!< TJATVG output macro getter.
#endif // S_TJATVG_PredTimeHeadAng_sec

#ifndef S_TJATVG_SensorTStamp_sec
#define S_TJATVG_SensorTStamp_sec (TJATVG_SenGetOutPtr()->S_TJATVG_SensorTStamp_sec) //!< TJATVG output macro.
#define GET_S_TJATVG_SensorTStamp_sec() (S_TJATVG_SensorTStamp_sec) //!< TJATVG output macro getter.
#endif // S_TJATVG_SensorTStamp_sec

#ifndef S_TJATVG_StrWhStifGrad_1ps
#define S_TJATVG_StrWhStifGrad_1ps (TJATVG_SenGetOutPtr()->S_TJATVG_StrWhStifGrad_1ps) //!< TJATVG output macro.
#define GET_S_TJATVG_StrWhStifGrad_1ps() (S_TJATVG_StrWhStifGrad_1ps) //!< TJATVG output macro getter.
#endif // S_TJATVG_StrWhStifGrad_1ps

#ifndef S_TJATVG_StrWhStifLimit_nu
#define S_TJATVG_StrWhStifLimit_nu (TJATVG_SenGetOutPtr()->S_TJATVG_StrWhStifLimit_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_StrWhStifLimit_nu() (S_TJATVG_StrWhStifLimit_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_StrWhStifLimit_nu

#ifndef S_TJATVG_TrajGuiQu_nu
#define S_TJATVG_TrajGuiQu_nu (TJATVG_SenGetOutPtr()->S_TJATVG_TrajGuiQu_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_TrajGuiQu_nu() (S_TJATVG_TrajGuiQu_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_TrajGuiQu_nu

#ifndef S_TJATVG_TrajPlanServQu_nu
#define S_TJATVG_TrajPlanServQu_nu (TJATVG_SenGetOutPtr()->S_TJATVG_TrajPlanServQu_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_TrajPlanServQu_nu() (S_TJATVG_TrajPlanServQu_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_TrajPlanServQu_nu

#ifndef S_TJATVG_TriggerReplan_nu
#define S_TJATVG_TriggerReplan_nu (TJATVG_SenGetOutPtr()->S_TJATVG_TriggerReplan_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_TriggerReplan_nu() (S_TJATVG_TriggerReplan_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_TriggerReplan_nu

#ifndef S_TJATVG_TrqRampGrad_1ps
#define S_TJATVG_TrqRampGrad_1ps (TJATVG_SenGetOutPtr()->S_TJATVG_TrqRampGrad_1ps) //!< TJATVG output macro.
#define GET_S_TJATVG_TrqRampGrad_1ps() (S_TJATVG_TrqRampGrad_1ps) //!< TJATVG output macro getter.
#endif // S_TJATVG_TrqRampGrad_1ps

#ifndef S_TJATVG_WeightEndTime_nu
#define S_TJATVG_WeightEndTime_nu (TJATVG_SenGetOutPtr()->S_TJATVG_WeightEndTime_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_WeightEndTime_nu() (S_TJATVG_WeightEndTime_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_WeightEndTime_nu

#ifndef S_TJATVG_WeightTgtDistY_nu
#define S_TJATVG_WeightTgtDistY_nu (TJATVG_SenGetOutPtr()->S_TJATVG_WeightTgtDistY_nu) //!< TJATVG output macro.
#define GET_S_TJATVG_WeightTgtDistY_nu() (S_TJATVG_WeightTgtDistY_nu) //!< TJATVG output macro getter.
#endif // S_TJATVG_WeightTgtDistY_nu

#ifdef __cplusplus
}
#endif

#endif // TJATVG_DATA_H_
