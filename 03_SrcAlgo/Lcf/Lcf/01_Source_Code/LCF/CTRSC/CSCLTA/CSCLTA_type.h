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
//! @file     CSCLTA_type.h
//! @brief     (CSCLTA) Module Type Header.

#ifndef CSCLTA_TYPE_H_
#define CSCLTA_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! CSCLTA module sensor output data structure. */
typedef struct
{
	
	f32_1pm2_m0p001_0p001_1em3_t S_CSCLTA_LeCridrBndCrvChng_1pm2; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LeCridrBndCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_CSCLTA_RiCridrBndCrvChng_1pm2; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_RiCridrBndCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_CSCLTA_TgtTrajCrvChng_1pm2; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TgtTrajCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_CSCLTA_LeCridrBndCrv_1pm; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LeCridrBndCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_CSCLTA_MaxCrvTrajGuiCtrl_1pm; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_MaxCrvTrajGuiCtrl_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_CSCLTA_RiCridrBndCrv_1pm; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_RiCridrBndCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_CSCLTA_TgtTrajCrv_1pm; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TgtTrajCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_m2_2_1em8_t S_CSCLTA_GrdLimitTgtCrvTGC_1pms; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_GrdLimitTgtCrvTGC_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -2 \n
	*	\@max: 2
	*/
	
	f32_1pms_m2_2_1em8_t S_CSCLTA_MaxCrvGrdBuildup_1pms; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_MaxCrvGrdBuildup_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -2 \n
	*	\@max: 2
	*/
	
	f32_1pms_m2_2_1em8_t S_CSCLTA_MaxCrvGrdRed_1pms; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_MaxCrvGrdRed_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -2 \n
	*	\@max: 2
	*/
	
	f32_NoUnit_0_100_1em3_t S_CSCLTA_MaxTrqScalLimit_nu; /*!< @description
	*	Maximum Torque Scaling Limiter (Torque saturation) \n\n
	*	\@asap_name: S_CSCLTA_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t S_CSCLTA_StrWhStifLimit_nu; /*!< @description
	*	Steering Wheel Stiffness Limiter \n\n
	*	\@asap_name: S_CSCLTA_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t S_CSCLTA_WeightEndTime_nu; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_WeightEndTime_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t S_CSCLTA_WeightTgtDistY_nu; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_Pers_0_10000_1em3_t S_CSCLTA_MaxTrqScalGrad_1ps; /*!< @description
	*	Maximum Torque Scaling Gradient \n\n
	*	\@asap_name: S_CSCLTA_MaxTrqScalGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t S_CSCLTA_StrWhStifGrad_1ps; /*!< @description
	*	Steering Wheel Stiffness Gradient \n\n
	*	\@asap_name: S_CSCLTA_StrWhStifGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t S_CSCLTA_TrqRampGrad_1ps; /*!< @description
	*	Torque Ramp Gradient \n\n
	*	\@asap_name: S_CSCLTA_TrqRampGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_m_0_10_1em3_t S_CSCLTA_DistYTolLeTgtArea_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_DistYTolLeTgtArea_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_CSCLTA_DistYTolRiTgtArea_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_DistYTolRiTgtArea_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_150_1em3_t S_CSCLTA_LeCridrBndLength_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LeCridrBndLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_CSCLTA_ObstacleWidth_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_ObstacleWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_CSCLTA_RiCridrBndLength_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_RiCridrBndLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_CSCLTA_TgtTrajLength_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TgtTrajLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_m1000_1000_1em3_t S_CSCLTA_ObstacleDistX_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_ObstacleDistX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_CSCLTA_ObstacleDistY_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_ObstacleDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m15_15_1em3_t S_CSCLTA_LeCridrBndPosY0_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LeCridrBndPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_CSCLTA_RiCridrBndPosY0_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_RiCridrBndPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_CSCLTA_TgtTrajPosY0_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m300_300_1em3_t S_CSCLTA_LeCridrBndPosX0_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LeCridrBndPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_m_m300_300_1em3_t S_CSCLTA_RiCridrBndPosX0_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_RiCridrBndPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_m_m300_300_1em3_t S_CSCLTA_TgtTrajPosX0_met; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TgtTrajPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_mps2_m20_20_1em3_t S_CSCLTA_FTireAclMax_mps2; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_FTireAclMax_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_CSCLTA_FTireAclMin_mps2; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_FTireAclMin_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_CSCLTA_ObstacleAclX_mps2; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_ObstacleAclX_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps3_0_50_1em3_t S_CSCLTA_MaxJerkAllowed_mps3; /*!< @description
	*	Maximum Jerk Allowed in the trajectory planning \n\n
	*	\@asap_name: S_CSCLTA_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_mps_m20_150_1em3_t S_CSCLTA_ObstacleVelX_mps; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_ObstacleVelX_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_CSCLTA_LeCridrBndHeadAng_rad; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LeCridrBndHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_CSCLTA_RiCridrBndHeadAng_rad; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_RiCridrBndHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_CSCLTA_TgtTrajHeadAng_rad; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TgtTrajHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_4295_1em6_t S_CSCLTA_SensorTStamp_sec; /*!< @description
	*	Timestamp of the corridor information signals \n\n
	*	\@asap_name: S_CSCLTA_SensorTStamp_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 4295
	*/
	
	f32_s_0_60_1em3_t S_CSCLTA_LimiterTimeDuration_sec; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LimiterTimeDuration_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_CSCLTA_PlanningHorizon_sec; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_PlanningHorizon_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_CSCLTA_PredTimeHeadAng_sec; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_CSCLTA_PredictionTimeCrv_sec; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_PredictionTimeCrv_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_LCF_SysStateType_t S_CSCLTA_SysStateLCF_enum; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_SysStateLCF_enum \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
	E_LCF_TGQ_Type_t S_CSCLTA_TrajGuiQualifier_nu; /*!< @description
	*	Trajectory Guidance Qualifier Output \n\n
	*	\@asap_name: S_CSCLTA_TrajGuiQualifier_nu \n
	*	\@values: E_LCF_TGQ_Type \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_100_0_1_t S_CSCLTA_DeratingLevel_nu; /*!< @description
	*	DMC Derating Level of the LCF \n\n
	*	\@asap_name: S_CSCLTA_DeratingLevel_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t S_CSCLTA_HighStatAccu_bool; /*!< @description
	*	High Stationary Accuracy required \n\n
	*	\@asap_name: S_CSCLTA_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_CSCLTA_LatencyCompActivated_nu; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LatencyCompActivated_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_CSCLTA_LimiterActivated_nu; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_LimiterActivated_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_CSCLTA_TriggerReplan_nu; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TriggerReplan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_CSCLTA_TrajPlanServQu_nu; /*!< @description
	*	CSCLTA_OUTPUT \n\n
	*	\@asap_name: S_CSCLTA_TrajPlanServQu_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} CSCLTA_SenOutType; /*!< @description CSCLTA module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // CSCLTA_TYPE_H_
