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
//! @file     DPLTVG.h
//! @brief     (DPLTVG) Module Header.

#ifndef DPLTVG_H_
#define DPLTVG_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DPLTVG module sensor initialization function. Function initializes DPLTVG sensor output data pointer.
 *	
 *	@param
 *		[in] DPLTVG_SenOutArg Pointer to DPLTVG sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void DPLTVG_SenInitOutPtr(DPLTVG_SenOutType *DPLTVG_SenOutArg);

/*!
 *	DPLTVG module sensor reset function.
 *	
 *	@pre
 *		- The DPLTVG sensor initialization function(s) must be called once.
 *		- The DPLTVG sensor debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		[Output Signal] [S_DPLTVG_DeratingLevel_nu](@ref DPLTVG_SenOutType::S_DPLTVG_DeratingLevel_nu) \n
 *		[Output Signal] [S_DPLTVG_DistYTolLeTgtArea_met](@ref DPLTVG_SenOutType::S_DPLTVG_DistYTolLeTgtArea_met) \n
 *		[Output Signal] [S_DPLTVG_DistYTolRiTgtArea_met](@ref DPLTVG_SenOutType::S_DPLTVG_DistYTolRiTgtArea_met) \n
 *		[Output Signal] [S_DPLTVG_FTireAclMax_mps2](@ref DPLTVG_SenOutType::S_DPLTVG_FTireAclMax_mps2) \n
 *		[Output Signal] [S_DPLTVG_FTireAclMin_mps2](@ref DPLTVG_SenOutType::S_DPLTVG_FTireAclMin_mps2) \n
 *		[Output Signal] [S_DPLTVG_GrdLimitTgtCrvTGC_1pms](@ref DPLTVG_SenOutType::S_DPLTVG_GrdLimitTgtCrvTGC_1pms) \n
 *		[Output Signal] [S_DPLTVG_HighStatAccu_bool](@ref DPLTVG_SenOutType::S_DPLTVG_HighStatAccu_bool) \n
 *		[Output Signal] [S_DPLTVG_LimiterActivated_bool](@ref DPLTVG_SenOutType::S_DPLTVG_LimiterActivated_bool) \n
 *		[Output Signal] [S_DPLTVG_LimiterTimeDuration_sec](@ref DPLTVG_SenOutType::S_DPLTVG_LimiterTimeDuration_sec) \n
 *		[Output Signal] [S_DPLTVG_LtcyCompActivated_bool](@ref DPLTVG_SenOutType::S_DPLTVG_LtcyCompActivated_bool) \n
 *		[Output Signal] [S_DPLTVG_MaxCrvGrdBuildup_1pms](@ref DPLTVG_SenOutType::S_DPLTVG_MaxCrvGrdBuildup_1pms) \n
 *		[Output Signal] [S_DPLTVG_MaxCrvGrdRed_1pms](@ref DPLTVG_SenOutType::S_DPLTVG_MaxCrvGrdRed_1pms) \n
 *		[Output Signal] [S_DPLTVG_MaxCrvTrajGuiCtrl_1pm](@ref DPLTVG_SenOutType::S_DPLTVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		[Output Signal] [S_DPLTVG_MaxJerkAllowed_mps3](@ref DPLTVG_SenOutType::S_DPLTVG_MaxJerkAllowed_mps3) \n
 *		[Output Signal] [S_DPLTVG_MaxTrqScalGrad_1ps](@ref DPLTVG_SenOutType::S_DPLTVG_MaxTrqScalGrad_1ps) \n
 *		[Output Signal] [S_DPLTVG_MaxTrqScalLimit_nu](@ref DPLTVG_SenOutType::S_DPLTVG_MaxTrqScalLimit_nu) \n
 *		[Output Signal] [S_DPLTVG_ObstacleAclX_mps2](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleAclX_mps2) \n
 *		[Output Signal] [S_DPLTVG_ObstacleDistX_met](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleDistX_met) \n
 *		[Output Signal] [S_DPLTVG_ObstacleDistY_met](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleDistY_met) \n
 *		[Output Signal] [S_DPLTVG_ObstacleVelX_mps](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleVelX_mps) \n
 *		[Output Signal] [S_DPLTVG_ObstacleWidth_met](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleWidth_met) \n
 *		[Output Signal] [S_DPLTVG_PlanningHorizon_sec](@ref DPLTVG_SenOutType::S_DPLTVG_PlanningHorizon_sec) \n
 *		[Output Signal] [S_DPLTVG_PredTimeCrv_sec](@ref DPLTVG_SenOutType::S_DPLTVG_PredTimeCrv_sec) \n
 *		[Output Signal] [S_DPLTVG_PredTimeHeadAng_sec](@ref DPLTVG_SenOutType::S_DPLTVG_PredTimeHeadAng_sec) \n
 *		[Output Signal] [S_DPLTVG_SensorTStamp_sec](@ref DPLTVG_SenOutType::S_DPLTVG_SensorTStamp_sec) \n
 *		[Output Signal] [S_DPLTVG_StrWhStifGrad_1ps](@ref DPLTVG_SenOutType::S_DPLTVG_StrWhStifGrad_1ps) \n
 *		[Output Signal] [S_DPLTVG_StrWhStifLimit_nu](@ref DPLTVG_SenOutType::S_DPLTVG_StrWhStifLimit_nu) \n
 *		[Output Signal] [S_DPLTVG_TrajGuiQu_nu](@ref DPLTVG_SenOutType::S_DPLTVG_TrajGuiQu_nu) \n
 *		[Output Signal] [S_DPLTVG_TrajPlanServQu_nu](@ref DPLTVG_SenOutType::S_DPLTVG_TrajPlanServQu_nu) \n
 *		[Output Signal] [S_DPLTVG_TriggerReplan_bool](@ref DPLTVG_SenOutType::S_DPLTVG_TriggerReplan_bool) \n
 *		[Output Signal] [S_DPLTVG_TrqRampGrad_1ps](@ref DPLTVG_SenOutType::S_DPLTVG_TrqRampGrad_1ps) \n
 *		[Output Signal] [S_DPLTVG_WeightEndTime_nu](@ref DPLTVG_SenOutType::S_DPLTVG_WeightEndTime_nu) \n
 *		[Output Signal] [S_DPLTVG_WeightTgtDistY_nu](@ref DPLTVG_SenOutType::S_DPLTVG_WeightTgtDistY_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref DPLTVG_SenProcess_Globals) of the function @ref DPLTVG_SenProcess.
 *		
 *	@InOutCorrelation
 *		Resets all static global variables.
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void DPLTVG_SenReset(void);

/*!
 *	DPLTVG module sensor process function.
 *	
 *	@pre
 *		- The DPLTVG sensor initialization function(s) must be called once.
 *		- The DPLTVG sensor debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		@anchor DPLTVG_SenProcess_Globals
 *		[S_DPLTVG_DeratingLevel_nu](@ref DPLTVG_SenOutType::S_DPLTVG_DeratingLevel_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function \n\n
 *		[S_DPLTVG_DistYTolLeTgtArea_met](@ref DPLTVG_SenOutType::S_DPLTVG_DistYTolLeTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_DistYTolRiTgtArea_met](@ref DPLTVG_SenOutType::S_DPLTVG_DistYTolRiTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_FTireAclMax_mps2](@ref DPLTVG_SenOutType::S_DPLTVG_FTireAclMax_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_FTireAclMin_mps2](@ref DPLTVG_SenOutType::S_DPLTVG_FTireAclMin_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_GrdLimitTgtCrvTGC_1pms](@ref DPLTVG_SenOutType::S_DPLTVG_GrdLimitTgtCrvTGC_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_HighStatAccu_bool](@ref DPLTVG_SenOutType::S_DPLTVG_HighStatAccu_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		[S_DPLTVG_LimiterActivated_bool](@ref DPLTVG_SenOutType::S_DPLTVG_LimiterActivated_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		[S_DPLTVG_LimiterTimeDuration_sec](@ref DPLTVG_SenOutType::S_DPLTVG_LimiterTimeDuration_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_LtcyCompActivated_bool](@ref DPLTVG_SenOutType::S_DPLTVG_LtcyCompActivated_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for the latency compensation in the TRJPLN. \n\n
 *		[S_DPLTVG_MaxCrvGrdBuildup_1pms](@ref DPLTVG_SenOutType::S_DPLTVG_MaxCrvGrdBuildup_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_MaxCrvGrdRed_1pms](@ref DPLTVG_SenOutType::S_DPLTVG_MaxCrvGrdRed_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_MaxCrvTrajGuiCtrl_1pm](@ref DPLTVG_SenOutType::S_DPLTVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_MaxJerkAllowed_mps3](@ref DPLTVG_SenOutType::S_DPLTVG_MaxJerkAllowed_mps3) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		[S_DPLTVG_MaxTrqScalGrad_1ps](@ref DPLTVG_SenOutType::S_DPLTVG_MaxTrqScalGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		[S_DPLTVG_MaxTrqScalLimit_nu](@ref DPLTVG_SenOutType::S_DPLTVG_MaxTrqScalLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		[S_DPLTVG_ObstacleAclX_mps2](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleAclX_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_ObstacleDistX_met](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleDistX_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_ObstacleDistY_met](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleDistY_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_ObstacleVelX_mps](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleVelX_mps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_ObstacleWidth_met](@ref DPLTVG_SenOutType::S_DPLTVG_ObstacleWidth_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_PlanningHorizon_sec](@ref DPLTVG_SenOutType::S_DPLTVG_PlanningHorizon_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_PredTimeCrv_sec](@ref DPLTVG_SenOutType::S_DPLTVG_PredTimeCrv_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_PredTimeHeadAng_sec](@ref DPLTVG_SenOutType::S_DPLTVG_PredTimeHeadAng_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_SensorTStamp_sec](@ref DPLTVG_SenOutType::S_DPLTVG_SensorTStamp_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		[S_DPLTVG_StrWhStifGrad_1ps](@ref DPLTVG_SenOutType::S_DPLTVG_StrWhStifGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		[S_DPLTVG_StrWhStifLimit_nu](@ref DPLTVG_SenOutType::S_DPLTVG_StrWhStifLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		[S_DPLTVG_TrajGuiQu_nu](@ref DPLTVG_SenOutType::S_DPLTVG_TrajGuiQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		[S_DPLTVG_TrajPlanServQu_nu](@ref DPLTVG_SenOutType::S_DPLTVG_TrajPlanServQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_TriggerReplan_bool](@ref DPLTVG_SenOutType::S_DPLTVG_TriggerReplan_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		It has to be 1 for TRJPLN to calculate a trajectory. \n\n
 *		[S_DPLTVG_TrqRampGrad_1ps](@ref DPLTVG_SenOutType::S_DPLTVG_TrqRampGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		[S_DPLTVG_WeightEndTime_nu](@ref DPLTVG_SenOutType::S_DPLTVG_WeightEndTime_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPLTVG_WeightTgtDistY_nu](@ref DPLTVG_SenOutType::S_DPLTVG_WeightTgtDistY_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_ABPLBP_ABDTimeStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		ABD data timestamp in seconds \n\n
 *		@ref S_DPLSIA_CurveTypeLe_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_DPLSIA_CurveTypeRi_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_DPLSIA_VelLatLeLDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the LDP. \n\n
 *		@ref S_DPLSIA_VelLatRiLDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the LDP. \n\n
 *		@ref S_DPLSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_DPLSMI_FunctionAborted_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		The signal is 1 for the whole rampout duration if the rampout was caused by an abort condition. \n\n
 *		@ref S_DPLSMI_SysStateLDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the LDP function. \n\n
 *		@ref S_DPLTTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_DrivingMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Driving Mode Selection Signal. It can be selected among driving modes such as Sport, Eco or Comfort. \n\n
 *		@ref S_LCFRCV_VehVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Vehicle Speed in miles/hour, computed based on the wheel speeds \n
 *		Negative values when vehicle moves backward \n\n
 *		@ref P_DPLTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_FTireAclMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_FTireAclMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_HighStatAccu_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for a high stationary accuracy in the LaDMC \n\n
 *		@ref P_DPLTVG_LimiterActivated_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		@ref P_DPLTVG_LimiterMaxCrvGrd_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_5_1em7_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Maximal limiter curvature gradient allowed. \n\n
 *		@ref P_DPLTVG_LimiterMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_50_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximal limiter curvature allowed. \n\n
 *		@ref P_DPLTVG_LimiterTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Duration of the target curvature imit in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		@ref P_DPLTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref P_DPLTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient maximum value \n\n
 *		@ref P_DPLTVG_MaxTrqScalRampInGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling ramp in gradient \n\n
 *		@ref P_DPLTVG_MaxTrqScalRampOutGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling ramp out gradient \n\n
 *		@ref P_DPLTVG_PredTimeCrv_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_PredTimeHeadAng_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_StrWhStifAbortROGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Abort Ramp Out Gradient \n\n
 *		@ref P_DPLTVG_StrWhStifLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limit \n\n
 *		@ref P_DPLTVG_StrWhStifROGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Standard Ramp Out Gradient \n\n
 *		@ref P_DPLTVG_TrajPlanServQu_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_TriggerReplan_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Trigger replan flag. Enables a replanning when there is corridor information update. \n\n
 *		@ref P_DPLTVG_TrqAbortROGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Out Abort Gradient \n\n
 *		@ref P_DPLTVG_TrqRampInGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Standard Ramp In Gradient \n\n
 *		@ref P_DPLTVG_TrqRampOutGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Standard Ramp Out Gradient \n\n
 *		@ref P_DPLTVG_UseLtcyComp_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLTVG_WeightTgtDistY_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_LCF_Curvature_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		X-axis for all the curvature dependant parameters. \n\n
 *		@ref X_LCF_DistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		X-axis for the Lateral Distance Dependant Look-Up Tables along LCF. \n\n
 *		@ref X_LCF_VelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_LCF_VelY_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPLTVG_CrvICPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an inner curve. \n\n
 *		@ref Y_DPLTVG_CrvOCPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an outer curve. \n\n
 *		@ref Y_DPLTVG_D2TPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Distance to target dependant. \n\n
 *		@ref Y_DPLTVG_VXPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. VX dependant. \n\n
 *		@ref Y_DPLTVG_VXWeightEndtime_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Weight of the end time for the calculation in the TRJPLN. Speed dependant. \n\n
 *		@ref Y_DPLTVG_VYMD1DeratingLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function when Driving Mode is either equal to 1 or to a default value. Lateral Velocity dependant. \n\n
 *		@ref Y_DPLTVG_VYMD2DeratingLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function when Driving Mode is equal to 2. Lateral Velocity dependant. \n\n
 *		@ref Y_DPLTVG_VYMD3DeratingLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function when Driving Mode is equal to 3. Lateral Velocity dependant. \n\n
 *		@ref Y_DPLTVG_VYPlanningHorizon_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Planning Horizon for the calculation in the TRJPLN. VY dependant. \n\n
 *		@ref Y_DPLTVG_VYStrWhStifRIGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Standard Steering Wheel Stiffness Ramp In Gradient. VY dependant. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPLTVG Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPLTVG_Testcase_Initialization) Initialization of the DPLTVG
 *		-# [Testcase_Timestamp](@ref DPLTVG_Testcase_Timestamp) Timestamp
 *		-# [Testcase_ConstantOutputs](@ref DPLTVG_Testcase_ConstantOutputs) Constant Outputs
 *		-# [Testcase_ParameterOutputs](@ref DPLTVG_Testcase_ParameterOutputs) Parameter Outputs
 *		-# [Testcase_Trajectory_Guidance_Qualifier](@ref DPLTVG_Testcase_Trajectory_Guidance_Qualifier) Trajectory Guidance Qualifier
 *		-# [Testcase_LookUp_Tables](@ref DPLTVG_Testcase_LookUp_Tables) Lookup Tables
 *		-# [Testcase_Stiffness](@ref DPLTVG_Testcase_Stiffness) Stiffness
 *		
 *	@traceability
 *		[\@link: DPLTVG Module Requirements]()
 */
extern void DPLTVG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPLTVG_H_
