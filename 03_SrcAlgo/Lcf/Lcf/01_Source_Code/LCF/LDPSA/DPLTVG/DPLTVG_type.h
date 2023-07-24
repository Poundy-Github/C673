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
//! @file     DPLTVG_type.h
//! @brief     (DPLTVG) Module Type Header.

#ifndef DPLTVG_TYPE_H_
#define DPLTVG_TYPE_H_

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

/*! DPLTVG module sensor output data structure. */
typedef struct
{
	
	f32_1pm_m1_1_1em3_t S_DPLTVG_MaxCrvTrajGuiCtrl_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_MaxCrvTrajGuiCtrl_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pms_m1000_1000_1em3_t S_DPLTVG_GrdLimitTgtCrvTGC_1pms; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_GrdLimitTgtCrvTGC_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_1pms_m1000_1000_1em3_t S_DPLTVG_MaxCrvGrdBuildup_1pms; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_MaxCrvGrdBuildup_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_1pms_m1000_1000_1em3_t S_DPLTVG_MaxCrvGrdRed_1pms; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_MaxCrvGrdRed_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t S_DPLTVG_MaxTrqScalLimit_nu; /*!< @description
	*	Maximum Torque Scaling Limiter (Torque saturation) \n\n
	*	\@asap_name: S_DPLTVG_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t S_DPLTVG_StrWhStifLimit_nu; /*!< @description
	*	Steering Wheel Stiffness Limiter \n\n
	*	\@asap_name: S_DPLTVG_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t S_DPLTVG_WeightEndTime_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_WeightEndTime_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t S_DPLTVG_WeightTgtDistY_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t S_DPLTVG_MaxTrqScalGrad_1ps; /*!< @description
	*	Maximum Torque Scaling Gradient \n\n
	*	\@asap_name: S_DPLTVG_MaxTrqScalGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t S_DPLTVG_StrWhStifGrad_1ps; /*!< @description
	*	Steering Wheel Stiffness Gradient \n\n
	*	\@asap_name: S_DPLTVG_StrWhStifGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t S_DPLTVG_TrqRampGrad_1ps; /*!< @description
	*	Torque Ramp Gradient \n\n
	*	\@asap_name: S_DPLTVG_TrqRampGrad_1ps \n
	*	\@type: value \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_m_0_10_1em3_t S_DPLTVG_DistYTolLeTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_DistYTolLeTgtArea_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_DPLTVG_DistYTolRiTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_DistYTolRiTgtArea_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_DPLTVG_ObstacleWidth_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_ObstacleWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m300_300_1em3_t S_DPLTVG_ObstacleDistX_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_ObstacleDistX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_m_m300_300_1em3_t S_DPLTVG_ObstacleDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_ObstacleDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_mps2_m20_20_1em3_t S_DPLTVG_FTireAclMax_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_FTireAclMax_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_DPLTVG_FTireAclMin_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_FTireAclMin_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_DPLTVG_ObstacleAclX_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_ObstacleAclX_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps3_0_50_1em3_t S_DPLTVG_MaxJerkAllowed_mps3; /*!< @description
	*	Maximum Jerk Allowed in the trajectory planning \n\n
	*	\@asap_name: S_DPLTVG_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_mps_m100_100_1em3_t S_DPLTVG_ObstacleVelX_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_ObstacleVelX_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_4295_1em6_t S_DPLTVG_SensorTStamp_sec; /*!< @description
	*	Sensor time stamp in seconds \n\n
	*	\@asap_name: S_DPLTVG_SensorTStamp_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 4295
	*/
	
	f32_s_0_60_1em3_t S_DPLTVG_LimiterTimeDuration_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_LimiterTimeDuration_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPLTVG_PlanningHorizon_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_PlanningHorizon_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPLTVG_PredTimeCrv_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_PredTimeCrv_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPLTVG_PredTimeHeadAng_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_LCF_TGQ_Type_t S_DPLTVG_TrajGuiQu_nu; /*!< @description
	*	Trajectory Guidance Qualifier Output \n\n
	*	\@asap_name: S_DPLTVG_TrajGuiQu_nu \n
	*	\@values: E_LCF_TGQ_Type \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_100_0_1_t S_DPLTVG_DeratingLevel_nu; /*!< @description
	*	DMC Derating Level of the LDP function \n\n
	*	\@asap_name: S_DPLTVG_DeratingLevel_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLTVG_HighStatAccu_bool; /*!< @description
	*	High Stationary Accuracy required \n\n
	*	\@asap_name: S_DPLTVG_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLTVG_LimiterActivated_bool; /*!< @description
	*	Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
	*	\@asap_name: S_DPLTVG_LimiterActivated_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLTVG_LtcyCompActivated_bool; /*!< @description
	*	Switch for the latency compensation in the TRJPLN. \n\n
	*	\@asap_name: S_DPLTVG_LtcyCompActivated_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLTVG_TriggerReplan_bool; /*!< @description
	*	It has to be 1 for TRJPLN to calculate a trajectory. \n\n
	*	\@asap_name: S_DPLTVG_TriggerReplan_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLTVG_TrajPlanServQu_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPLTVG_TrajPlanServQu_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPLTVG_SenOutType; /*!< @description DPLTVG module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DPLTVG_TYPE_H_
