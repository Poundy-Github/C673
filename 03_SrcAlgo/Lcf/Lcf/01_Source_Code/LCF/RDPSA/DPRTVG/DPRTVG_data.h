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
//! @file     DPRTVG_data.h
//! @brief     (DPRTVG) Module Data Header.

#ifndef DPRTVG_DATA_H_
#define DPRTVG_DATA_H_

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
 *	DPRTVG module sensor get function. Function gets DPRTVG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRTVG_SenOutPtr</b> Global static pointer to DPRTVG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRTVG_SenOutType* DPRTVG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPRTVG_DeratingLevel_nu
#define S_DPRTVG_DeratingLevel_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_DeratingLevel_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_DeratingLevel_nu() (S_DPRTVG_DeratingLevel_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_DeratingLevel_nu

#ifndef S_DPRTVG_DistYTolLeTgtArea_met
#define S_DPRTVG_DistYTolLeTgtArea_met (DPRTVG_SenGetOutPtr()->S_DPRTVG_DistYTolLeTgtArea_met) //!< DPRTVG output macro.
#define GET_S_DPRTVG_DistYTolLeTgtArea_met() (S_DPRTVG_DistYTolLeTgtArea_met) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_DistYTolLeTgtArea_met

#ifndef S_DPRTVG_DistYTolRiTgtArea_met
#define S_DPRTVG_DistYTolRiTgtArea_met (DPRTVG_SenGetOutPtr()->S_DPRTVG_DistYTolRiTgtArea_met) //!< DPRTVG output macro.
#define GET_S_DPRTVG_DistYTolRiTgtArea_met() (S_DPRTVG_DistYTolRiTgtArea_met) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_DistYTolRiTgtArea_met

#ifndef S_DPRTVG_FTireAclMax_mps2
#define S_DPRTVG_FTireAclMax_mps2 (DPRTVG_SenGetOutPtr()->S_DPRTVG_FTireAclMax_mps2) //!< DPRTVG output macro.
#define GET_S_DPRTVG_FTireAclMax_mps2() (S_DPRTVG_FTireAclMax_mps2) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_FTireAclMax_mps2

#ifndef S_DPRTVG_FTireAclMin_mps2
#define S_DPRTVG_FTireAclMin_mps2 (DPRTVG_SenGetOutPtr()->S_DPRTVG_FTireAclMin_mps2) //!< DPRTVG output macro.
#define GET_S_DPRTVG_FTireAclMin_mps2() (S_DPRTVG_FTireAclMin_mps2) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_FTireAclMin_mps2

#ifndef S_DPRTVG_GrdLimitTgtCrvTGC_1pms
#define S_DPRTVG_GrdLimitTgtCrvTGC_1pms (DPRTVG_SenGetOutPtr()->S_DPRTVG_GrdLimitTgtCrvTGC_1pms) //!< DPRTVG output macro.
#define GET_S_DPRTVG_GrdLimitTgtCrvTGC_1pms() (S_DPRTVG_GrdLimitTgtCrvTGC_1pms) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_DPRTVG_HighStatAccu_bool
#define S_DPRTVG_HighStatAccu_bool (DPRTVG_SenGetOutPtr()->S_DPRTVG_HighStatAccu_bool) //!< DPRTVG output macro.
#define GET_S_DPRTVG_HighStatAccu_bool() (S_DPRTVG_HighStatAccu_bool) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_HighStatAccu_bool

#ifndef S_DPRTVG_LimiterActivated_bool
#define S_DPRTVG_LimiterActivated_bool (DPRTVG_SenGetOutPtr()->S_DPRTVG_LimiterActivated_bool) //!< DPRTVG output macro.
#define GET_S_DPRTVG_LimiterActivated_bool() (S_DPRTVG_LimiterActivated_bool) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_LimiterActivated_bool

#ifndef S_DPRTVG_LimiterTimeDuration_sec
#define S_DPRTVG_LimiterTimeDuration_sec (DPRTVG_SenGetOutPtr()->S_DPRTVG_LimiterTimeDuration_sec) //!< DPRTVG output macro.
#define GET_S_DPRTVG_LimiterTimeDuration_sec() (S_DPRTVG_LimiterTimeDuration_sec) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_LimiterTimeDuration_sec

#ifndef S_DPRTVG_LtcyCompActivated_bool
#define S_DPRTVG_LtcyCompActivated_bool (DPRTVG_SenGetOutPtr()->S_DPRTVG_LtcyCompActivated_bool) //!< DPRTVG output macro.
#define GET_S_DPRTVG_LtcyCompActivated_bool() (S_DPRTVG_LtcyCompActivated_bool) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_LtcyCompActivated_bool

#ifndef S_DPRTVG_MaxCrvGrdBuildup_1pms
#define S_DPRTVG_MaxCrvGrdBuildup_1pms (DPRTVG_SenGetOutPtr()->S_DPRTVG_MaxCrvGrdBuildup_1pms) //!< DPRTVG output macro.
#define GET_S_DPRTVG_MaxCrvGrdBuildup_1pms() (S_DPRTVG_MaxCrvGrdBuildup_1pms) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_MaxCrvGrdBuildup_1pms

#ifndef S_DPRTVG_MaxCrvGrdRed_1pms
#define S_DPRTVG_MaxCrvGrdRed_1pms (DPRTVG_SenGetOutPtr()->S_DPRTVG_MaxCrvGrdRed_1pms) //!< DPRTVG output macro.
#define GET_S_DPRTVG_MaxCrvGrdRed_1pms() (S_DPRTVG_MaxCrvGrdRed_1pms) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_MaxCrvGrdRed_1pms

#ifndef S_DPRTVG_MaxCrvTrajGuiCtrl_1pm
#define S_DPRTVG_MaxCrvTrajGuiCtrl_1pm (DPRTVG_SenGetOutPtr()->S_DPRTVG_MaxCrvTrajGuiCtrl_1pm) //!< DPRTVG output macro.
#define GET_S_DPRTVG_MaxCrvTrajGuiCtrl_1pm() (S_DPRTVG_MaxCrvTrajGuiCtrl_1pm) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_DPRTVG_MaxJerkAllowed_mps3
#define S_DPRTVG_MaxJerkAllowed_mps3 (DPRTVG_SenGetOutPtr()->S_DPRTVG_MaxJerkAllowed_mps3) //!< DPRTVG output macro.
#define GET_S_DPRTVG_MaxJerkAllowed_mps3() (S_DPRTVG_MaxJerkAllowed_mps3) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_MaxJerkAllowed_mps3

#ifndef S_DPRTVG_MaxTrqScalGrad_1ps
#define S_DPRTVG_MaxTrqScalGrad_1ps (DPRTVG_SenGetOutPtr()->S_DPRTVG_MaxTrqScalGrad_1ps) //!< DPRTVG output macro.
#define GET_S_DPRTVG_MaxTrqScalGrad_1ps() (S_DPRTVG_MaxTrqScalGrad_1ps) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_MaxTrqScalGrad_1ps

#ifndef S_DPRTVG_MaxTrqScalLimit_nu
#define S_DPRTVG_MaxTrqScalLimit_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_MaxTrqScalLimit_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_MaxTrqScalLimit_nu() (S_DPRTVG_MaxTrqScalLimit_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_MaxTrqScalLimit_nu

#ifndef S_DPRTVG_ObstacleAclX_mps2
#define S_DPRTVG_ObstacleAclX_mps2 (DPRTVG_SenGetOutPtr()->S_DPRTVG_ObstacleAclX_mps2) //!< DPRTVG output macro.
#define GET_S_DPRTVG_ObstacleAclX_mps2() (S_DPRTVG_ObstacleAclX_mps2) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_ObstacleAclX_mps2

#ifndef S_DPRTVG_ObstacleDistX_met
#define S_DPRTVG_ObstacleDistX_met (DPRTVG_SenGetOutPtr()->S_DPRTVG_ObstacleDistX_met) //!< DPRTVG output macro.
#define GET_S_DPRTVG_ObstacleDistX_met() (S_DPRTVG_ObstacleDistX_met) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_ObstacleDistX_met

#ifndef S_DPRTVG_ObstacleDistY_met
#define S_DPRTVG_ObstacleDistY_met (DPRTVG_SenGetOutPtr()->S_DPRTVG_ObstacleDistY_met) //!< DPRTVG output macro.
#define GET_S_DPRTVG_ObstacleDistY_met() (S_DPRTVG_ObstacleDistY_met) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_ObstacleDistY_met

#ifndef S_DPRTVG_ObstacleVelX_mps
#define S_DPRTVG_ObstacleVelX_mps (DPRTVG_SenGetOutPtr()->S_DPRTVG_ObstacleVelX_mps) //!< DPRTVG output macro.
#define GET_S_DPRTVG_ObstacleVelX_mps() (S_DPRTVG_ObstacleVelX_mps) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_ObstacleVelX_mps

#ifndef S_DPRTVG_ObstacleWidth_met
#define S_DPRTVG_ObstacleWidth_met (DPRTVG_SenGetOutPtr()->S_DPRTVG_ObstacleWidth_met) //!< DPRTVG output macro.
#define GET_S_DPRTVG_ObstacleWidth_met() (S_DPRTVG_ObstacleWidth_met) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_ObstacleWidth_met

#ifndef S_DPRTVG_PlanningHorizon_sec
#define S_DPRTVG_PlanningHorizon_sec (DPRTVG_SenGetOutPtr()->S_DPRTVG_PlanningHorizon_sec) //!< DPRTVG output macro.
#define GET_S_DPRTVG_PlanningHorizon_sec() (S_DPRTVG_PlanningHorizon_sec) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_PlanningHorizon_sec

#ifndef S_DPRTVG_PredTimeCrv_sec
#define S_DPRTVG_PredTimeCrv_sec (DPRTVG_SenGetOutPtr()->S_DPRTVG_PredTimeCrv_sec) //!< DPRTVG output macro.
#define GET_S_DPRTVG_PredTimeCrv_sec() (S_DPRTVG_PredTimeCrv_sec) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_PredTimeCrv_sec

#ifndef S_DPRTVG_PredTimeHeadAng_sec
#define S_DPRTVG_PredTimeHeadAng_sec (DPRTVG_SenGetOutPtr()->S_DPRTVG_PredTimeHeadAng_sec) //!< DPRTVG output macro.
#define GET_S_DPRTVG_PredTimeHeadAng_sec() (S_DPRTVG_PredTimeHeadAng_sec) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_PredTimeHeadAng_sec

#ifndef S_DPRTVG_SensorTStamp_sec
#define S_DPRTVG_SensorTStamp_sec (DPRTVG_SenGetOutPtr()->S_DPRTVG_SensorTStamp_sec) //!< DPRTVG output macro.
#define GET_S_DPRTVG_SensorTStamp_sec() (S_DPRTVG_SensorTStamp_sec) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_SensorTStamp_sec

#ifndef S_DPRTVG_StrWhStifGrad_1ps
#define S_DPRTVG_StrWhStifGrad_1ps (DPRTVG_SenGetOutPtr()->S_DPRTVG_StrWhStifGrad_1ps) //!< DPRTVG output macro.
#define GET_S_DPRTVG_StrWhStifGrad_1ps() (S_DPRTVG_StrWhStifGrad_1ps) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_StrWhStifGrad_1ps

#ifndef S_DPRTVG_StrWhStifLimit_nu
#define S_DPRTVG_StrWhStifLimit_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_StrWhStifLimit_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_StrWhStifLimit_nu() (S_DPRTVG_StrWhStifLimit_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_StrWhStifLimit_nu

#ifndef S_DPRTVG_TrajGuiQu_nu
#define S_DPRTVG_TrajGuiQu_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_TrajGuiQu_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_TrajGuiQu_nu() (S_DPRTVG_TrajGuiQu_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_TrajGuiQu_nu

#ifndef S_DPRTVG_TrajPlanServQu_nu
#define S_DPRTVG_TrajPlanServQu_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_TrajPlanServQu_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_TrajPlanServQu_nu() (S_DPRTVG_TrajPlanServQu_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_TrajPlanServQu_nu

#ifndef S_DPRTVG_TriggerReplan_bool
#define S_DPRTVG_TriggerReplan_bool (DPRTVG_SenGetOutPtr()->S_DPRTVG_TriggerReplan_bool) //!< DPRTVG output macro.
#define GET_S_DPRTVG_TriggerReplan_bool() (S_DPRTVG_TriggerReplan_bool) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_TriggerReplan_bool

#ifndef S_DPRTVG_TrqRampGrad_1ps
#define S_DPRTVG_TrqRampGrad_1ps (DPRTVG_SenGetOutPtr()->S_DPRTVG_TrqRampGrad_1ps) //!< DPRTVG output macro.
#define GET_S_DPRTVG_TrqRampGrad_1ps() (S_DPRTVG_TrqRampGrad_1ps) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_TrqRampGrad_1ps

#ifndef S_DPRTVG_WeightEndTime_nu
#define S_DPRTVG_WeightEndTime_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_WeightEndTime_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_WeightEndTime_nu() (S_DPRTVG_WeightEndTime_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_WeightEndTime_nu

#ifndef S_DPRTVG_WeightTgtDistY_nu
#define S_DPRTVG_WeightTgtDistY_nu (DPRTVG_SenGetOutPtr()->S_DPRTVG_WeightTgtDistY_nu) //!< DPRTVG output macro.
#define GET_S_DPRTVG_WeightTgtDistY_nu() (S_DPRTVG_WeightTgtDistY_nu) //!< DPRTVG output macro getter.
#endif // S_DPRTVG_WeightTgtDistY_nu

#ifdef __cplusplus
}
#endif

#endif // DPRTVG_DATA_H_
