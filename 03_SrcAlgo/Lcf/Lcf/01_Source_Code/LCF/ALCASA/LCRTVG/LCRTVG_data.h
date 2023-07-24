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
//! @file     LCRTVG_data.h
//! @brief     (LCRTVG) Module Data Header.

#ifndef LCRTVG_DATA_H_
#define LCRTVG_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"
#include "LCRTVG_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCRTVG module sensor get function. Function gets LCRTVG sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRTVG_SenDbgPtr</b> Global static pointer to LCRTVG sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRTVG_SenDbgType* LCRTVG_SenGetDbgPtr(void);

/*!
 *	LCRTVG module sensor get function. Function gets LCRTVG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRTVG_SenOutPtr</b> Global static pointer to LCRTVG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRTVG_SenOutType* LCRTVG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_LCRTVG_DistYTolLeTgtArea_met
#define S_LCRTVG_DistYTolLeTgtArea_met (LCRTVG_SenGetDbgPtr()->S_LCRTVG_DistYTolLeTgtArea_met) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_DistYTolLeTgtArea_met() (S_LCRTVG_DistYTolLeTgtArea_met) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_DistYTolLeTgtArea_met

#ifndef S_LCRTVG_DistYTolRiTgtArea_met
#define S_LCRTVG_DistYTolRiTgtArea_met (LCRTVG_SenGetDbgPtr()->S_LCRTVG_DistYTolRiTgtArea_met) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_DistYTolRiTgtArea_met() (S_LCRTVG_DistYTolRiTgtArea_met) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_DistYTolRiTgtArea_met

#ifndef S_LCRTVG_FTireAclMax_mps2
#define S_LCRTVG_FTireAclMax_mps2 (LCRTVG_SenGetDbgPtr()->S_LCRTVG_FTireAclMax_mps2) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_FTireAclMax_mps2() (S_LCRTVG_FTireAclMax_mps2) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_FTireAclMax_mps2

#ifndef S_LCRTVG_FTireAclMin_mps2
#define S_LCRTVG_FTireAclMin_mps2 (LCRTVG_SenGetDbgPtr()->S_LCRTVG_FTireAclMin_mps2) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_FTireAclMin_mps2() (S_LCRTVG_FTireAclMin_mps2) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_FTireAclMin_mps2

#ifndef S_LCRTVG_GrdLimitTgtCrvTGC_1pms
#define S_LCRTVG_GrdLimitTgtCrvTGC_1pms (LCRTVG_SenGetDbgPtr()->S_LCRTVG_GrdLimitTgtCrvTGC_1pms) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_GrdLimitTgtCrvTGC_1pms() (S_LCRTVG_GrdLimitTgtCrvTGC_1pms) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_LCRTVG_HighStatAccu_bool
#define S_LCRTVG_HighStatAccu_bool (LCRTVG_SenGetDbgPtr()->S_LCRTVG_HighStatAccu_bool) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_HighStatAccu_bool() (S_LCRTVG_HighStatAccu_bool) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_HighStatAccu_bool

#ifndef S_LCRTVG_LimiterActivated_bool
#define S_LCRTVG_LimiterActivated_bool (LCRTVG_SenGetDbgPtr()->S_LCRTVG_LimiterActivated_bool) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_LimiterActivated_bool() (S_LCRTVG_LimiterActivated_bool) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_LimiterActivated_bool

#ifndef S_LCRTVG_LimiterTimeDuration_sec
#define S_LCRTVG_LimiterTimeDuration_sec (LCRTVG_SenGetDbgPtr()->S_LCRTVG_LimiterTimeDuration_sec) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_LimiterTimeDuration_sec() (S_LCRTVG_LimiterTimeDuration_sec) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_LimiterTimeDuration_sec

#ifndef S_LCRTVG_LtcyCompActivated_bool
#define S_LCRTVG_LtcyCompActivated_bool (LCRTVG_SenGetDbgPtr()->S_LCRTVG_LtcyCompActivated_bool) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_LtcyCompActivated_bool() (S_LCRTVG_LtcyCompActivated_bool) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_LtcyCompActivated_bool

#ifndef S_LCRTVG_MaxCrvGrdBuildup_1pms
#define S_LCRTVG_MaxCrvGrdBuildup_1pms (LCRTVG_SenGetDbgPtr()->S_LCRTVG_MaxCrvGrdBuildup_1pms) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_MaxCrvGrdBuildup_1pms() (S_LCRTVG_MaxCrvGrdBuildup_1pms) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_MaxCrvGrdBuildup_1pms

#ifndef S_LCRTVG_MaxCrvGrdRed_1pms
#define S_LCRTVG_MaxCrvGrdRed_1pms (LCRTVG_SenGetDbgPtr()->S_LCRTVG_MaxCrvGrdRed_1pms) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_MaxCrvGrdRed_1pms() (S_LCRTVG_MaxCrvGrdRed_1pms) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_MaxCrvGrdRed_1pms

#ifndef S_LCRTVG_MaxCrvTrajGuiCtrl_1pm
#define S_LCRTVG_MaxCrvTrajGuiCtrl_1pm (LCRTVG_SenGetDbgPtr()->S_LCRTVG_MaxCrvTrajGuiCtrl_1pm) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_MaxCrvTrajGuiCtrl_1pm() (S_LCRTVG_MaxCrvTrajGuiCtrl_1pm) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_LCRTVG_MaxTrqScalGrad_1ps
#define S_LCRTVG_MaxTrqScalGrad_1ps (LCRTVG_SenGetDbgPtr()->S_LCRTVG_MaxTrqScalGrad_1ps) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_MaxTrqScalGrad_1ps() (S_LCRTVG_MaxTrqScalGrad_1ps) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_MaxTrqScalGrad_1ps

#ifndef S_LCRTVG_MaxTrqScalLimit_nu
#define S_LCRTVG_MaxTrqScalLimit_nu (LCRTVG_SenGetDbgPtr()->S_LCRTVG_MaxTrqScalLimit_nu) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_MaxTrqScalLimit_nu() (S_LCRTVG_MaxTrqScalLimit_nu) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_MaxTrqScalLimit_nu

#ifndef S_LCRTVG_ObstacleAclX_mps2
#define S_LCRTVG_ObstacleAclX_mps2 (LCRTVG_SenGetDbgPtr()->S_LCRTVG_ObstacleAclX_mps2) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_ObstacleAclX_mps2() (S_LCRTVG_ObstacleAclX_mps2) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_ObstacleAclX_mps2

#ifndef S_LCRTVG_ObstacleDistX_met
#define S_LCRTVG_ObstacleDistX_met (LCRTVG_SenGetDbgPtr()->S_LCRTVG_ObstacleDistX_met) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_ObstacleDistX_met() (S_LCRTVG_ObstacleDistX_met) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_ObstacleDistX_met

#ifndef S_LCRTVG_ObstacleDistY_met
#define S_LCRTVG_ObstacleDistY_met (LCRTVG_SenGetDbgPtr()->S_LCRTVG_ObstacleDistY_met) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_ObstacleDistY_met() (S_LCRTVG_ObstacleDistY_met) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_ObstacleDistY_met

#ifndef S_LCRTVG_ObstacleVelX_mps
#define S_LCRTVG_ObstacleVelX_mps (LCRTVG_SenGetDbgPtr()->S_LCRTVG_ObstacleVelX_mps) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_ObstacleVelX_mps() (S_LCRTVG_ObstacleVelX_mps) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_ObstacleVelX_mps

#ifndef S_LCRTVG_ObstacleWidth_met
#define S_LCRTVG_ObstacleWidth_met (LCRTVG_SenGetDbgPtr()->S_LCRTVG_ObstacleWidth_met) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_ObstacleWidth_met() (S_LCRTVG_ObstacleWidth_met) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_ObstacleWidth_met

#ifndef S_LCRTVG_PlanningHorizon_sec
#define S_LCRTVG_PlanningHorizon_sec (LCRTVG_SenGetDbgPtr()->S_LCRTVG_PlanningHorizon_sec) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_PlanningHorizon_sec() (S_LCRTVG_PlanningHorizon_sec) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_PlanningHorizon_sec

#ifndef S_LCRTVG_PredTimeCrv_sec
#define S_LCRTVG_PredTimeCrv_sec (LCRTVG_SenGetDbgPtr()->S_LCRTVG_PredTimeCrv_sec) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_PredTimeCrv_sec() (S_LCRTVG_PredTimeCrv_sec) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_PredTimeCrv_sec

#ifndef S_LCRTVG_PredTimeHeadAng_sec
#define S_LCRTVG_PredTimeHeadAng_sec (LCRTVG_SenGetDbgPtr()->S_LCRTVG_PredTimeHeadAng_sec) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_PredTimeHeadAng_sec() (S_LCRTVG_PredTimeHeadAng_sec) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_PredTimeHeadAng_sec

#ifndef S_LCRTVG_StrWhStifGrad_1ps
#define S_LCRTVG_StrWhStifGrad_1ps (LCRTVG_SenGetDbgPtr()->S_LCRTVG_StrWhStifGrad_1ps) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_StrWhStifGrad_1ps() (S_LCRTVG_StrWhStifGrad_1ps) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_StrWhStifGrad_1ps

#ifndef S_LCRTVG_StrWhStifLimit_nu
#define S_LCRTVG_StrWhStifLimit_nu (LCRTVG_SenGetDbgPtr()->S_LCRTVG_StrWhStifLimit_nu) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_StrWhStifLimit_nu() (S_LCRTVG_StrWhStifLimit_nu) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_StrWhStifLimit_nu

#ifndef S_LCRTVG_TrajGuiQu_nu
#define S_LCRTVG_TrajGuiQu_nu (LCRTVG_SenGetDbgPtr()->S_LCRTVG_TrajGuiQu_nu) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_TrajGuiQu_nu() (S_LCRTVG_TrajGuiQu_nu) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_TrajGuiQu_nu

#ifndef S_LCRTVG_TrajPlanServQu_nu
#define S_LCRTVG_TrajPlanServQu_nu (LCRTVG_SenGetDbgPtr()->S_LCRTVG_TrajPlanServQu_nu) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_TrajPlanServQu_nu() (S_LCRTVG_TrajPlanServQu_nu) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_TrajPlanServQu_nu

#ifndef S_LCRTVG_TriggerReplan_bool
#define S_LCRTVG_TriggerReplan_bool (LCRTVG_SenGetDbgPtr()->S_LCRTVG_TriggerReplan_bool) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_TriggerReplan_bool() (S_LCRTVG_TriggerReplan_bool) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_TriggerReplan_bool

#ifndef S_LCRTVG_TrqRampGrad_1ps
#define S_LCRTVG_TrqRampGrad_1ps (LCRTVG_SenGetDbgPtr()->S_LCRTVG_TrqRampGrad_1ps) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_TrqRampGrad_1ps() (S_LCRTVG_TrqRampGrad_1ps) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_TrqRampGrad_1ps

#ifndef S_LCRTVG_WeightEndTime_nu
#define S_LCRTVG_WeightEndTime_nu (LCRTVG_SenGetDbgPtr()->S_LCRTVG_WeightEndTime_nu) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_WeightEndTime_nu() (S_LCRTVG_WeightEndTime_nu) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_WeightEndTime_nu

#ifndef S_LCRTVG_WeightTgtDistY_nu
#define S_LCRTVG_WeightTgtDistY_nu (LCRTVG_SenGetDbgPtr()->S_LCRTVG_WeightTgtDistY_nu) //!< LCRTVG debug macro.
#define GET_S_LCRTVG_WeightTgtDistY_nu() (S_LCRTVG_WeightTgtDistY_nu) //!< LCRTVG debug macro getter.
#endif // S_LCRTVG_WeightTgtDistY_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_LCRTVG_DeratingLevel_nu
#define S_LCRTVG_DeratingLevel_nu (LCRTVG_SenGetOutPtr()->S_LCRTVG_DeratingLevel_nu) //!< LCRTVG output macro.
#define GET_S_LCRTVG_DeratingLevel_nu() (S_LCRTVG_DeratingLevel_nu) //!< LCRTVG output macro getter.
#endif // S_LCRTVG_DeratingLevel_nu

#ifndef S_LCRTVG_MaxJerkAllowed_mps3
#define S_LCRTVG_MaxJerkAllowed_mps3 (LCRTVG_SenGetOutPtr()->S_LCRTVG_MaxJerkAllowed_mps3) //!< LCRTVG output macro.
#define GET_S_LCRTVG_MaxJerkAllowed_mps3() (S_LCRTVG_MaxJerkAllowed_mps3) //!< LCRTVG output macro getter.
#endif // S_LCRTVG_MaxJerkAllowed_mps3

#ifndef S_LCRTVG_SensorTStamp_sec
#define S_LCRTVG_SensorTStamp_sec (LCRTVG_SenGetOutPtr()->S_LCRTVG_SensorTStamp_sec) //!< LCRTVG output macro.
#define GET_S_LCRTVG_SensorTStamp_sec() (S_LCRTVG_SensorTStamp_sec) //!< LCRTVG output macro getter.
#endif // S_LCRTVG_SensorTStamp_sec

#ifdef __cplusplus
}
#endif

#endif // LCRTVG_DATA_H_
