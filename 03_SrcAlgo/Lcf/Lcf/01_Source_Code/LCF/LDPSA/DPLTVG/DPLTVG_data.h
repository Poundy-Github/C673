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
//! @file     DPLTVG_data.h
//! @brief     (DPLTVG) Module Data Header.

#ifndef DPLTVG_DATA_H_
#define DPLTVG_DATA_H_

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
 *	DPLTVG module sensor get function. Function gets DPLTVG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLTVG_SenOutPtr</b> Global static pointer to DPLTVG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLTVG_SenOutType* DPLTVG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPLTVG_DeratingLevel_nu
#define S_DPLTVG_DeratingLevel_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_DeratingLevel_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_DeratingLevel_nu() (S_DPLTVG_DeratingLevel_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_DeratingLevel_nu

#ifndef S_DPLTVG_DistYTolLeTgtArea_met
#define S_DPLTVG_DistYTolLeTgtArea_met (DPLTVG_SenGetOutPtr()->S_DPLTVG_DistYTolLeTgtArea_met) //!< DPLTVG output macro.
#define GET_S_DPLTVG_DistYTolLeTgtArea_met() (S_DPLTVG_DistYTolLeTgtArea_met) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_DistYTolLeTgtArea_met

#ifndef S_DPLTVG_DistYTolRiTgtArea_met
#define S_DPLTVG_DistYTolRiTgtArea_met (DPLTVG_SenGetOutPtr()->S_DPLTVG_DistYTolRiTgtArea_met) //!< DPLTVG output macro.
#define GET_S_DPLTVG_DistYTolRiTgtArea_met() (S_DPLTVG_DistYTolRiTgtArea_met) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_DistYTolRiTgtArea_met

#ifndef S_DPLTVG_FTireAclMax_mps2
#define S_DPLTVG_FTireAclMax_mps2 (DPLTVG_SenGetOutPtr()->S_DPLTVG_FTireAclMax_mps2) //!< DPLTVG output macro.
#define GET_S_DPLTVG_FTireAclMax_mps2() (S_DPLTVG_FTireAclMax_mps2) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_FTireAclMax_mps2

#ifndef S_DPLTVG_FTireAclMin_mps2
#define S_DPLTVG_FTireAclMin_mps2 (DPLTVG_SenGetOutPtr()->S_DPLTVG_FTireAclMin_mps2) //!< DPLTVG output macro.
#define GET_S_DPLTVG_FTireAclMin_mps2() (S_DPLTVG_FTireAclMin_mps2) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_FTireAclMin_mps2

#ifndef S_DPLTVG_GrdLimitTgtCrvTGC_1pms
#define S_DPLTVG_GrdLimitTgtCrvTGC_1pms (DPLTVG_SenGetOutPtr()->S_DPLTVG_GrdLimitTgtCrvTGC_1pms) //!< DPLTVG output macro.
#define GET_S_DPLTVG_GrdLimitTgtCrvTGC_1pms() (S_DPLTVG_GrdLimitTgtCrvTGC_1pms) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_DPLTVG_HighStatAccu_bool
#define S_DPLTVG_HighStatAccu_bool (DPLTVG_SenGetOutPtr()->S_DPLTVG_HighStatAccu_bool) //!< DPLTVG output macro.
#define GET_S_DPLTVG_HighStatAccu_bool() (S_DPLTVG_HighStatAccu_bool) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_HighStatAccu_bool

#ifndef S_DPLTVG_LimiterActivated_bool
#define S_DPLTVG_LimiterActivated_bool (DPLTVG_SenGetOutPtr()->S_DPLTVG_LimiterActivated_bool) //!< DPLTVG output macro.
#define GET_S_DPLTVG_LimiterActivated_bool() (S_DPLTVG_LimiterActivated_bool) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_LimiterActivated_bool

#ifndef S_DPLTVG_LimiterTimeDuration_sec
#define S_DPLTVG_LimiterTimeDuration_sec (DPLTVG_SenGetOutPtr()->S_DPLTVG_LimiterTimeDuration_sec) //!< DPLTVG output macro.
#define GET_S_DPLTVG_LimiterTimeDuration_sec() (S_DPLTVG_LimiterTimeDuration_sec) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_LimiterTimeDuration_sec

#ifndef S_DPLTVG_LtcyCompActivated_bool
#define S_DPLTVG_LtcyCompActivated_bool (DPLTVG_SenGetOutPtr()->S_DPLTVG_LtcyCompActivated_bool) //!< DPLTVG output macro.
#define GET_S_DPLTVG_LtcyCompActivated_bool() (S_DPLTVG_LtcyCompActivated_bool) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_LtcyCompActivated_bool

#ifndef S_DPLTVG_MaxCrvGrdBuildup_1pms
#define S_DPLTVG_MaxCrvGrdBuildup_1pms (DPLTVG_SenGetOutPtr()->S_DPLTVG_MaxCrvGrdBuildup_1pms) //!< DPLTVG output macro.
#define GET_S_DPLTVG_MaxCrvGrdBuildup_1pms() (S_DPLTVG_MaxCrvGrdBuildup_1pms) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_MaxCrvGrdBuildup_1pms

#ifndef S_DPLTVG_MaxCrvGrdRed_1pms
#define S_DPLTVG_MaxCrvGrdRed_1pms (DPLTVG_SenGetOutPtr()->S_DPLTVG_MaxCrvGrdRed_1pms) //!< DPLTVG output macro.
#define GET_S_DPLTVG_MaxCrvGrdRed_1pms() (S_DPLTVG_MaxCrvGrdRed_1pms) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_MaxCrvGrdRed_1pms

#ifndef S_DPLTVG_MaxCrvTrajGuiCtrl_1pm
#define S_DPLTVG_MaxCrvTrajGuiCtrl_1pm (DPLTVG_SenGetOutPtr()->S_DPLTVG_MaxCrvTrajGuiCtrl_1pm) //!< DPLTVG output macro.
#define GET_S_DPLTVG_MaxCrvTrajGuiCtrl_1pm() (S_DPLTVG_MaxCrvTrajGuiCtrl_1pm) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_DPLTVG_MaxJerkAllowed_mps3
#define S_DPLTVG_MaxJerkAllowed_mps3 (DPLTVG_SenGetOutPtr()->S_DPLTVG_MaxJerkAllowed_mps3) //!< DPLTVG output macro.
#define GET_S_DPLTVG_MaxJerkAllowed_mps3() (S_DPLTVG_MaxJerkAllowed_mps3) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_MaxJerkAllowed_mps3

#ifndef S_DPLTVG_MaxTrqScalGrad_1ps
#define S_DPLTVG_MaxTrqScalGrad_1ps (DPLTVG_SenGetOutPtr()->S_DPLTVG_MaxTrqScalGrad_1ps) //!< DPLTVG output macro.
#define GET_S_DPLTVG_MaxTrqScalGrad_1ps() (S_DPLTVG_MaxTrqScalGrad_1ps) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_MaxTrqScalGrad_1ps

#ifndef S_DPLTVG_MaxTrqScalLimit_nu
#define S_DPLTVG_MaxTrqScalLimit_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_MaxTrqScalLimit_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_MaxTrqScalLimit_nu() (S_DPLTVG_MaxTrqScalLimit_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_MaxTrqScalLimit_nu

#ifndef S_DPLTVG_ObstacleAclX_mps2
#define S_DPLTVG_ObstacleAclX_mps2 (DPLTVG_SenGetOutPtr()->S_DPLTVG_ObstacleAclX_mps2) //!< DPLTVG output macro.
#define GET_S_DPLTVG_ObstacleAclX_mps2() (S_DPLTVG_ObstacleAclX_mps2) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_ObstacleAclX_mps2

#ifndef S_DPLTVG_ObstacleDistX_met
#define S_DPLTVG_ObstacleDistX_met (DPLTVG_SenGetOutPtr()->S_DPLTVG_ObstacleDistX_met) //!< DPLTVG output macro.
#define GET_S_DPLTVG_ObstacleDistX_met() (S_DPLTVG_ObstacleDistX_met) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_ObstacleDistX_met

#ifndef S_DPLTVG_ObstacleDistY_met
#define S_DPLTVG_ObstacleDistY_met (DPLTVG_SenGetOutPtr()->S_DPLTVG_ObstacleDistY_met) //!< DPLTVG output macro.
#define GET_S_DPLTVG_ObstacleDistY_met() (S_DPLTVG_ObstacleDistY_met) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_ObstacleDistY_met

#ifndef S_DPLTVG_ObstacleVelX_mps
#define S_DPLTVG_ObstacleVelX_mps (DPLTVG_SenGetOutPtr()->S_DPLTVG_ObstacleVelX_mps) //!< DPLTVG output macro.
#define GET_S_DPLTVG_ObstacleVelX_mps() (S_DPLTVG_ObstacleVelX_mps) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_ObstacleVelX_mps

#ifndef S_DPLTVG_ObstacleWidth_met
#define S_DPLTVG_ObstacleWidth_met (DPLTVG_SenGetOutPtr()->S_DPLTVG_ObstacleWidth_met) //!< DPLTVG output macro.
#define GET_S_DPLTVG_ObstacleWidth_met() (S_DPLTVG_ObstacleWidth_met) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_ObstacleWidth_met

#ifndef S_DPLTVG_PlanningHorizon_sec
#define S_DPLTVG_PlanningHorizon_sec (DPLTVG_SenGetOutPtr()->S_DPLTVG_PlanningHorizon_sec) //!< DPLTVG output macro.
#define GET_S_DPLTVG_PlanningHorizon_sec() (S_DPLTVG_PlanningHorizon_sec) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_PlanningHorizon_sec

#ifndef S_DPLTVG_PredTimeCrv_sec
#define S_DPLTVG_PredTimeCrv_sec (DPLTVG_SenGetOutPtr()->S_DPLTVG_PredTimeCrv_sec) //!< DPLTVG output macro.
#define GET_S_DPLTVG_PredTimeCrv_sec() (S_DPLTVG_PredTimeCrv_sec) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_PredTimeCrv_sec

#ifndef S_DPLTVG_PredTimeHeadAng_sec
#define S_DPLTVG_PredTimeHeadAng_sec (DPLTVG_SenGetOutPtr()->S_DPLTVG_PredTimeHeadAng_sec) //!< DPLTVG output macro.
#define GET_S_DPLTVG_PredTimeHeadAng_sec() (S_DPLTVG_PredTimeHeadAng_sec) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_PredTimeHeadAng_sec

#ifndef S_DPLTVG_SensorTStamp_sec
#define S_DPLTVG_SensorTStamp_sec (DPLTVG_SenGetOutPtr()->S_DPLTVG_SensorTStamp_sec) //!< DPLTVG output macro.
#define GET_S_DPLTVG_SensorTStamp_sec() (S_DPLTVG_SensorTStamp_sec) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_SensorTStamp_sec

#ifndef S_DPLTVG_StrWhStifGrad_1ps
#define S_DPLTVG_StrWhStifGrad_1ps (DPLTVG_SenGetOutPtr()->S_DPLTVG_StrWhStifGrad_1ps) //!< DPLTVG output macro.
#define GET_S_DPLTVG_StrWhStifGrad_1ps() (S_DPLTVG_StrWhStifGrad_1ps) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_StrWhStifGrad_1ps

#ifndef S_DPLTVG_StrWhStifLimit_nu
#define S_DPLTVG_StrWhStifLimit_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_StrWhStifLimit_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_StrWhStifLimit_nu() (S_DPLTVG_StrWhStifLimit_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_StrWhStifLimit_nu

#ifndef S_DPLTVG_TrajGuiQu_nu
#define S_DPLTVG_TrajGuiQu_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_TrajGuiQu_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_TrajGuiQu_nu() (S_DPLTVG_TrajGuiQu_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_TrajGuiQu_nu

#ifndef S_DPLTVG_TrajPlanServQu_nu
#define S_DPLTVG_TrajPlanServQu_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_TrajPlanServQu_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_TrajPlanServQu_nu() (S_DPLTVG_TrajPlanServQu_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_TrajPlanServQu_nu

#ifndef S_DPLTVG_TriggerReplan_bool
#define S_DPLTVG_TriggerReplan_bool (DPLTVG_SenGetOutPtr()->S_DPLTVG_TriggerReplan_bool) //!< DPLTVG output macro.
#define GET_S_DPLTVG_TriggerReplan_bool() (S_DPLTVG_TriggerReplan_bool) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_TriggerReplan_bool

#ifndef S_DPLTVG_TrqRampGrad_1ps
#define S_DPLTVG_TrqRampGrad_1ps (DPLTVG_SenGetOutPtr()->S_DPLTVG_TrqRampGrad_1ps) //!< DPLTVG output macro.
#define GET_S_DPLTVG_TrqRampGrad_1ps() (S_DPLTVG_TrqRampGrad_1ps) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_TrqRampGrad_1ps

#ifndef S_DPLTVG_WeightEndTime_nu
#define S_DPLTVG_WeightEndTime_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_WeightEndTime_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_WeightEndTime_nu() (S_DPLTVG_WeightEndTime_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_WeightEndTime_nu

#ifndef S_DPLTVG_WeightTgtDistY_nu
#define S_DPLTVG_WeightTgtDistY_nu (DPLTVG_SenGetOutPtr()->S_DPLTVG_WeightTgtDistY_nu) //!< DPLTVG output macro.
#define GET_S_DPLTVG_WeightTgtDistY_nu() (S_DPLTVG_WeightTgtDistY_nu) //!< DPLTVG output macro getter.
#endif // S_DPLTVG_WeightTgtDistY_nu

#ifdef __cplusplus
}
#endif

#endif // DPLTVG_DATA_H_
