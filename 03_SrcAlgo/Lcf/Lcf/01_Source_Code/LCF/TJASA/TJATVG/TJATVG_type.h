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
//! @file     TJATVG_type.h
//! @brief     (TJATVG) Module Type Header.

#ifndef TJATVG_TYPE_H_
#define TJATVG_TYPE_H_

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

/*! TJATVG module sensor output data structure. */
typedef struct
{
	
	f32_1pm_m1_1_1em3_t S_TJATVG_MaxCrvTrajGuiCtrl_1pm; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_MaxCrvTrajGuiCtrl_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pms_m1000_1000_1em3_t S_TJATVG_GrdLimitTgtCrvTGC_1pms; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_GrdLimitTgtCrvTGC_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_1pms_m1000_1000_1em3_t S_TJATVG_MaxCrvGrdBuildup_1pms; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_MaxCrvGrdBuildup_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_1pms_m1000_1000_1em3_t S_TJATVG_MaxCrvGrdRed_1pms; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_MaxCrvGrdRed_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t S_TJATVG_MaxTrqScalLimit_nu; /*!< @description
	*	Maximum Torque Scaling Limiter (Torque saturation) \n\n
	*	\@asap_name: S_TJATVG_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t S_TJATVG_StrWhStifLimit_nu; /*!< @description
	*	Steering Wheel Stiffness Limiter \n\n
	*	\@asap_name: S_TJATVG_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t S_TJATVG_WeightEndTime_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_WeightEndTime_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t S_TJATVG_WeightTgtDistY_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_Pers_0_10000_1em3_t S_TJATVG_MaxTrqScalGrad_1ps; /*!< @description
	*	Maximum Torque Scaling Gradient \n\n
	*	\@asap_name: S_TJATVG_MaxTrqScalGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t S_TJATVG_StrWhStifGrad_1ps; /*!< @description
	*	Steering Wheel Stiffness Gradient \n\n
	*	\@asap_name: S_TJATVG_StrWhStifGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t S_TJATVG_TrqRampGrad_1ps; /*!< @description
	*	Torque Ramp Gradient \n\n
	*	\@asap_name: S_TJATVG_TrqRampGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_m_0_150_1em3_t S_TJATVG_DistYTolLeTgtArea_met; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_DistYTolLeTgtArea_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_TJATVG_DistYTolRiTgtArea_met; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_DistYTolRiTgtArea_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_TJATVG_ObstacleWidth_met; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_ObstacleWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATVG_ObstacleDistX_met; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_ObstacleDistX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATVG_ObstacleDistY_met; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_ObstacleDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_mps2_m20_20_1em3_t S_TJATVG_FTireAclMax_mps2; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_FTireAclMax_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TJATVG_FTireAclMin_mps2; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_FTireAclMin_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TJATVG_ObstacleAclX_mps2; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_ObstacleAclX_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps3_0_50_1em3_t S_TJATVG_MaxJerkAllowed_mps3; /*!< @description
	*	Maximum Jerk Allowed in the trajectory planning \n\n
	*	\@asap_name: S_TJATVG_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_mps_m20_150_1em3_t S_TJATVG_ObstacleVelX_mps; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_ObstacleVelX_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_s_0_4295_1em6_t S_TJATVG_SensorTStamp_sec; /*!< @description
	*	Sensor time stamp in seconds \n
	*	OF: radar time stamp \n
	*	ELSE: camera time stamp \n\n
	*	\@asap_name: S_TJATVG_SensorTStamp_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 4295
	*/
	
	f32_s_0_60_1em3_t S_TJATVG_LimiterTimeDuration_sec; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_LimiterTimeDuration_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_TJATVG_PlanningHorizon_sec; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_PlanningHorizon_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_TJATVG_PredTimeCrv_sec; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_PredTimeCrv_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_TJATVG_PredTimeHeadAng_sec; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_LCF_TGQ_Type_t S_TJATVG_TrajGuiQu_nu; /*!< @description
	*	Trajectory Guidance Qualifier Output \n\n
	*	\@asap_name: S_TJATVG_TrajGuiQu_nu \n
	*	\@values: E_LCF_TGQ_Type \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_100_0_1_t S_TJATVG_DeratingLevel_nu; /*!< @description
	*	DMC Derating Level of the TJA function \n\n
	*	\@asap_name: S_TJATVG_DeratingLevel_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATVG_CrvAmplActivated_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_CrvAmplActivated_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATVG_HighStatAccu_bool; /*!< @description
	*	High Stationary Accuracy required \n\n
	*	\@asap_name: S_TJATVG_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATVG_LimiterActivated_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_LimiterActivated_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATVG_LimiterType_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_LimiterType_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATVG_LtcyCompActivated_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_LtcyCompActivated_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATVG_TriggerReplan_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_TriggerReplan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_TJATVG_TrajPlanServQu_nu; /*!< @description
	*	TJATVG_OUTPUT \n\n
	*	\@asap_name: S_TJATVG_TrajPlanServQu_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TJATVG_SenOutType; /*!< @description TJATVG module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TJATVG_TYPE_H_
