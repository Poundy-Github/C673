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
//! @file     CSCLTA_data.h
//! @brief     (CSCLTA) Module Data Header.

#ifndef CSCLTA_DATA_H_
#define CSCLTA_DATA_H_

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
 *	CSCLTA module sensor get function. Function gets CSCLTA sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>CSCLTA_SenOutPtr</b> Global static pointer to CSCLTA sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const CSCLTA_SenOutType* CSCLTA_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_CSCLTA_DeratingLevel_nu
#define S_CSCLTA_DeratingLevel_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_DeratingLevel_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_DeratingLevel_nu() (S_CSCLTA_DeratingLevel_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_DeratingLevel_nu

#ifndef S_CSCLTA_DistYTolLeTgtArea_met
#define S_CSCLTA_DistYTolLeTgtArea_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_DistYTolLeTgtArea_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_DistYTolLeTgtArea_met() (S_CSCLTA_DistYTolLeTgtArea_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_DistYTolLeTgtArea_met

#ifndef S_CSCLTA_DistYTolRiTgtArea_met
#define S_CSCLTA_DistYTolRiTgtArea_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_DistYTolRiTgtArea_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_DistYTolRiTgtArea_met() (S_CSCLTA_DistYTolRiTgtArea_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_DistYTolRiTgtArea_met

#ifndef S_CSCLTA_FTireAclMax_mps2
#define S_CSCLTA_FTireAclMax_mps2 (CSCLTA_SenGetOutPtr()->S_CSCLTA_FTireAclMax_mps2) //!< CSCLTA output macro.
#define GET_S_CSCLTA_FTireAclMax_mps2() (S_CSCLTA_FTireAclMax_mps2) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_FTireAclMax_mps2

#ifndef S_CSCLTA_FTireAclMin_mps2
#define S_CSCLTA_FTireAclMin_mps2 (CSCLTA_SenGetOutPtr()->S_CSCLTA_FTireAclMin_mps2) //!< CSCLTA output macro.
#define GET_S_CSCLTA_FTireAclMin_mps2() (S_CSCLTA_FTireAclMin_mps2) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_FTireAclMin_mps2

#ifndef S_CSCLTA_GrdLimitTgtCrvTGC_1pms
#define S_CSCLTA_GrdLimitTgtCrvTGC_1pms (CSCLTA_SenGetOutPtr()->S_CSCLTA_GrdLimitTgtCrvTGC_1pms) //!< CSCLTA output macro.
#define GET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms() (S_CSCLTA_GrdLimitTgtCrvTGC_1pms) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_GrdLimitTgtCrvTGC_1pms

#ifndef S_CSCLTA_HighStatAccu_bool
#define S_CSCLTA_HighStatAccu_bool (CSCLTA_SenGetOutPtr()->S_CSCLTA_HighStatAccu_bool) //!< CSCLTA output macro.
#define GET_S_CSCLTA_HighStatAccu_bool() (S_CSCLTA_HighStatAccu_bool) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_HighStatAccu_bool

#ifndef S_CSCLTA_LatencyCompActivated_nu
#define S_CSCLTA_LatencyCompActivated_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_LatencyCompActivated_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LatencyCompActivated_nu() (S_CSCLTA_LatencyCompActivated_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LatencyCompActivated_nu

#ifndef S_CSCLTA_LeCridrBndCrvChng_1pm2
#define S_CSCLTA_LeCridrBndCrvChng_1pm2 (CSCLTA_SenGetOutPtr()->S_CSCLTA_LeCridrBndCrvChng_1pm2) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LeCridrBndCrvChng_1pm2() (S_CSCLTA_LeCridrBndCrvChng_1pm2) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LeCridrBndCrvChng_1pm2

#ifndef S_CSCLTA_LeCridrBndCrv_1pm
#define S_CSCLTA_LeCridrBndCrv_1pm (CSCLTA_SenGetOutPtr()->S_CSCLTA_LeCridrBndCrv_1pm) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LeCridrBndCrv_1pm() (S_CSCLTA_LeCridrBndCrv_1pm) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LeCridrBndCrv_1pm

#ifndef S_CSCLTA_LeCridrBndHeadAng_rad
#define S_CSCLTA_LeCridrBndHeadAng_rad (CSCLTA_SenGetOutPtr()->S_CSCLTA_LeCridrBndHeadAng_rad) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LeCridrBndHeadAng_rad() (S_CSCLTA_LeCridrBndHeadAng_rad) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LeCridrBndHeadAng_rad

#ifndef S_CSCLTA_LeCridrBndLength_met
#define S_CSCLTA_LeCridrBndLength_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_LeCridrBndLength_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LeCridrBndLength_met() (S_CSCLTA_LeCridrBndLength_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LeCridrBndLength_met

#ifndef S_CSCLTA_LeCridrBndPosX0_met
#define S_CSCLTA_LeCridrBndPosX0_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_LeCridrBndPosX0_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LeCridrBndPosX0_met() (S_CSCLTA_LeCridrBndPosX0_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LeCridrBndPosX0_met

#ifndef S_CSCLTA_LeCridrBndPosY0_met
#define S_CSCLTA_LeCridrBndPosY0_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_LeCridrBndPosY0_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LeCridrBndPosY0_met() (S_CSCLTA_LeCridrBndPosY0_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LeCridrBndPosY0_met

#ifndef S_CSCLTA_LimiterActivated_nu
#define S_CSCLTA_LimiterActivated_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_LimiterActivated_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LimiterActivated_nu() (S_CSCLTA_LimiterActivated_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LimiterActivated_nu

#ifndef S_CSCLTA_LimiterTimeDuration_sec
#define S_CSCLTA_LimiterTimeDuration_sec (CSCLTA_SenGetOutPtr()->S_CSCLTA_LimiterTimeDuration_sec) //!< CSCLTA output macro.
#define GET_S_CSCLTA_LimiterTimeDuration_sec() (S_CSCLTA_LimiterTimeDuration_sec) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_LimiterTimeDuration_sec

#ifndef S_CSCLTA_MaxCrvGrdBuildup_1pms
#define S_CSCLTA_MaxCrvGrdBuildup_1pms (CSCLTA_SenGetOutPtr()->S_CSCLTA_MaxCrvGrdBuildup_1pms) //!< CSCLTA output macro.
#define GET_S_CSCLTA_MaxCrvGrdBuildup_1pms() (S_CSCLTA_MaxCrvGrdBuildup_1pms) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_MaxCrvGrdBuildup_1pms

#ifndef S_CSCLTA_MaxCrvGrdRed_1pms
#define S_CSCLTA_MaxCrvGrdRed_1pms (CSCLTA_SenGetOutPtr()->S_CSCLTA_MaxCrvGrdRed_1pms) //!< CSCLTA output macro.
#define GET_S_CSCLTA_MaxCrvGrdRed_1pms() (S_CSCLTA_MaxCrvGrdRed_1pms) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_MaxCrvGrdRed_1pms

#ifndef S_CSCLTA_MaxCrvTrajGuiCtrl_1pm
#define S_CSCLTA_MaxCrvTrajGuiCtrl_1pm (CSCLTA_SenGetOutPtr()->S_CSCLTA_MaxCrvTrajGuiCtrl_1pm) //!< CSCLTA output macro.
#define GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm() (S_CSCLTA_MaxCrvTrajGuiCtrl_1pm) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_MaxCrvTrajGuiCtrl_1pm

#ifndef S_CSCLTA_MaxJerkAllowed_mps3
#define S_CSCLTA_MaxJerkAllowed_mps3 (CSCLTA_SenGetOutPtr()->S_CSCLTA_MaxJerkAllowed_mps3) //!< CSCLTA output macro.
#define GET_S_CSCLTA_MaxJerkAllowed_mps3() (S_CSCLTA_MaxJerkAllowed_mps3) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_MaxJerkAllowed_mps3

#ifndef S_CSCLTA_MaxTrqScalGrad_1ps
#define S_CSCLTA_MaxTrqScalGrad_1ps (CSCLTA_SenGetOutPtr()->S_CSCLTA_MaxTrqScalGrad_1ps) //!< CSCLTA output macro.
#define GET_S_CSCLTA_MaxTrqScalGrad_1ps() (S_CSCLTA_MaxTrqScalGrad_1ps) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_MaxTrqScalGrad_1ps

#ifndef S_CSCLTA_MaxTrqScalLimit_nu
#define S_CSCLTA_MaxTrqScalLimit_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_MaxTrqScalLimit_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_MaxTrqScalLimit_nu() (S_CSCLTA_MaxTrqScalLimit_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_MaxTrqScalLimit_nu

#ifndef S_CSCLTA_ObstacleAclX_mps2
#define S_CSCLTA_ObstacleAclX_mps2 (CSCLTA_SenGetOutPtr()->S_CSCLTA_ObstacleAclX_mps2) //!< CSCLTA output macro.
#define GET_S_CSCLTA_ObstacleAclX_mps2() (S_CSCLTA_ObstacleAclX_mps2) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_ObstacleAclX_mps2

#ifndef S_CSCLTA_ObstacleDistX_met
#define S_CSCLTA_ObstacleDistX_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_ObstacleDistX_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_ObstacleDistX_met() (S_CSCLTA_ObstacleDistX_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_ObstacleDistX_met

#ifndef S_CSCLTA_ObstacleDistY_met
#define S_CSCLTA_ObstacleDistY_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_ObstacleDistY_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_ObstacleDistY_met() (S_CSCLTA_ObstacleDistY_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_ObstacleDistY_met

#ifndef S_CSCLTA_ObstacleVelX_mps
#define S_CSCLTA_ObstacleVelX_mps (CSCLTA_SenGetOutPtr()->S_CSCLTA_ObstacleVelX_mps) //!< CSCLTA output macro.
#define GET_S_CSCLTA_ObstacleVelX_mps() (S_CSCLTA_ObstacleVelX_mps) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_ObstacleVelX_mps

#ifndef S_CSCLTA_ObstacleWidth_met
#define S_CSCLTA_ObstacleWidth_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_ObstacleWidth_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_ObstacleWidth_met() (S_CSCLTA_ObstacleWidth_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_ObstacleWidth_met

#ifndef S_CSCLTA_PlanningHorizon_sec
#define S_CSCLTA_PlanningHorizon_sec (CSCLTA_SenGetOutPtr()->S_CSCLTA_PlanningHorizon_sec) //!< CSCLTA output macro.
#define GET_S_CSCLTA_PlanningHorizon_sec() (S_CSCLTA_PlanningHorizon_sec) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_PlanningHorizon_sec

#ifndef S_CSCLTA_PredTimeHeadAng_sec
#define S_CSCLTA_PredTimeHeadAng_sec (CSCLTA_SenGetOutPtr()->S_CSCLTA_PredTimeHeadAng_sec) //!< CSCLTA output macro.
#define GET_S_CSCLTA_PredTimeHeadAng_sec() (S_CSCLTA_PredTimeHeadAng_sec) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_PredTimeHeadAng_sec

#ifndef S_CSCLTA_PredictionTimeCrv_sec
#define S_CSCLTA_PredictionTimeCrv_sec (CSCLTA_SenGetOutPtr()->S_CSCLTA_PredictionTimeCrv_sec) //!< CSCLTA output macro.
#define GET_S_CSCLTA_PredictionTimeCrv_sec() (S_CSCLTA_PredictionTimeCrv_sec) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_PredictionTimeCrv_sec

#ifndef S_CSCLTA_RiCridrBndCrvChng_1pm2
#define S_CSCLTA_RiCridrBndCrvChng_1pm2 (CSCLTA_SenGetOutPtr()->S_CSCLTA_RiCridrBndCrvChng_1pm2) //!< CSCLTA output macro.
#define GET_S_CSCLTA_RiCridrBndCrvChng_1pm2() (S_CSCLTA_RiCridrBndCrvChng_1pm2) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_RiCridrBndCrvChng_1pm2

#ifndef S_CSCLTA_RiCridrBndCrv_1pm
#define S_CSCLTA_RiCridrBndCrv_1pm (CSCLTA_SenGetOutPtr()->S_CSCLTA_RiCridrBndCrv_1pm) //!< CSCLTA output macro.
#define GET_S_CSCLTA_RiCridrBndCrv_1pm() (S_CSCLTA_RiCridrBndCrv_1pm) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_RiCridrBndCrv_1pm

#ifndef S_CSCLTA_RiCridrBndHeadAng_rad
#define S_CSCLTA_RiCridrBndHeadAng_rad (CSCLTA_SenGetOutPtr()->S_CSCLTA_RiCridrBndHeadAng_rad) //!< CSCLTA output macro.
#define GET_S_CSCLTA_RiCridrBndHeadAng_rad() (S_CSCLTA_RiCridrBndHeadAng_rad) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_RiCridrBndHeadAng_rad

#ifndef S_CSCLTA_RiCridrBndLength_met
#define S_CSCLTA_RiCridrBndLength_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_RiCridrBndLength_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_RiCridrBndLength_met() (S_CSCLTA_RiCridrBndLength_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_RiCridrBndLength_met

#ifndef S_CSCLTA_RiCridrBndPosX0_met
#define S_CSCLTA_RiCridrBndPosX0_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_RiCridrBndPosX0_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_RiCridrBndPosX0_met() (S_CSCLTA_RiCridrBndPosX0_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_RiCridrBndPosX0_met

#ifndef S_CSCLTA_RiCridrBndPosY0_met
#define S_CSCLTA_RiCridrBndPosY0_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_RiCridrBndPosY0_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_RiCridrBndPosY0_met() (S_CSCLTA_RiCridrBndPosY0_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_RiCridrBndPosY0_met

#ifndef S_CSCLTA_SensorTStamp_sec
#define S_CSCLTA_SensorTStamp_sec (CSCLTA_SenGetOutPtr()->S_CSCLTA_SensorTStamp_sec) //!< CSCLTA output macro.
#define GET_S_CSCLTA_SensorTStamp_sec() (S_CSCLTA_SensorTStamp_sec) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_SensorTStamp_sec

#ifndef S_CSCLTA_StrWhStifGrad_1ps
#define S_CSCLTA_StrWhStifGrad_1ps (CSCLTA_SenGetOutPtr()->S_CSCLTA_StrWhStifGrad_1ps) //!< CSCLTA output macro.
#define GET_S_CSCLTA_StrWhStifGrad_1ps() (S_CSCLTA_StrWhStifGrad_1ps) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_StrWhStifGrad_1ps

#ifndef S_CSCLTA_StrWhStifLimit_nu
#define S_CSCLTA_StrWhStifLimit_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_StrWhStifLimit_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_StrWhStifLimit_nu() (S_CSCLTA_StrWhStifLimit_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_StrWhStifLimit_nu

#ifndef S_CSCLTA_SysStateLCF_enum
#define S_CSCLTA_SysStateLCF_enum (CSCLTA_SenGetOutPtr()->S_CSCLTA_SysStateLCF_enum) //!< CSCLTA output macro.
#define GET_S_CSCLTA_SysStateLCF_enum() (S_CSCLTA_SysStateLCF_enum) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_SysStateLCF_enum

#ifndef S_CSCLTA_TgtTrajCrvChng_1pm2
#define S_CSCLTA_TgtTrajCrvChng_1pm2 (CSCLTA_SenGetOutPtr()->S_CSCLTA_TgtTrajCrvChng_1pm2) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TgtTrajCrvChng_1pm2() (S_CSCLTA_TgtTrajCrvChng_1pm2) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TgtTrajCrvChng_1pm2

#ifndef S_CSCLTA_TgtTrajCrv_1pm
#define S_CSCLTA_TgtTrajCrv_1pm (CSCLTA_SenGetOutPtr()->S_CSCLTA_TgtTrajCrv_1pm) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TgtTrajCrv_1pm() (S_CSCLTA_TgtTrajCrv_1pm) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TgtTrajCrv_1pm

#ifndef S_CSCLTA_TgtTrajHeadAng_rad
#define S_CSCLTA_TgtTrajHeadAng_rad (CSCLTA_SenGetOutPtr()->S_CSCLTA_TgtTrajHeadAng_rad) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TgtTrajHeadAng_rad() (S_CSCLTA_TgtTrajHeadAng_rad) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TgtTrajHeadAng_rad

#ifndef S_CSCLTA_TgtTrajLength_met
#define S_CSCLTA_TgtTrajLength_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_TgtTrajLength_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TgtTrajLength_met() (S_CSCLTA_TgtTrajLength_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TgtTrajLength_met

#ifndef S_CSCLTA_TgtTrajPosX0_met
#define S_CSCLTA_TgtTrajPosX0_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_TgtTrajPosX0_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TgtTrajPosX0_met() (S_CSCLTA_TgtTrajPosX0_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TgtTrajPosX0_met

#ifndef S_CSCLTA_TgtTrajPosY0_met
#define S_CSCLTA_TgtTrajPosY0_met (CSCLTA_SenGetOutPtr()->S_CSCLTA_TgtTrajPosY0_met) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TgtTrajPosY0_met() (S_CSCLTA_TgtTrajPosY0_met) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TgtTrajPosY0_met

#ifndef S_CSCLTA_TrajGuiQualifier_nu
#define S_CSCLTA_TrajGuiQualifier_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_TrajGuiQualifier_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TrajGuiQualifier_nu() (S_CSCLTA_TrajGuiQualifier_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TrajGuiQualifier_nu

#ifndef S_CSCLTA_TrajPlanServQu_nu
#define S_CSCLTA_TrajPlanServQu_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_TrajPlanServQu_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TrajPlanServQu_nu() (S_CSCLTA_TrajPlanServQu_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TrajPlanServQu_nu

#ifndef S_CSCLTA_TriggerReplan_nu
#define S_CSCLTA_TriggerReplan_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_TriggerReplan_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TriggerReplan_nu() (S_CSCLTA_TriggerReplan_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TriggerReplan_nu

#ifndef S_CSCLTA_TrqRampGrad_1ps
#define S_CSCLTA_TrqRampGrad_1ps (CSCLTA_SenGetOutPtr()->S_CSCLTA_TrqRampGrad_1ps) //!< CSCLTA output macro.
#define GET_S_CSCLTA_TrqRampGrad_1ps() (S_CSCLTA_TrqRampGrad_1ps) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_TrqRampGrad_1ps

#ifndef S_CSCLTA_WeightEndTime_nu
#define S_CSCLTA_WeightEndTime_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_WeightEndTime_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_WeightEndTime_nu() (S_CSCLTA_WeightEndTime_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_WeightEndTime_nu

#ifndef S_CSCLTA_WeightTgtDistY_nu
#define S_CSCLTA_WeightTgtDistY_nu (CSCLTA_SenGetOutPtr()->S_CSCLTA_WeightTgtDistY_nu) //!< CSCLTA output macro.
#define GET_S_CSCLTA_WeightTgtDistY_nu() (S_CSCLTA_WeightTgtDistY_nu) //!< CSCLTA output macro getter.
#endif // S_CSCLTA_WeightTgtDistY_nu

#ifdef __cplusplus
}
#endif

#endif // CSCLTA_DATA_H_
