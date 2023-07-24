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
//! @file     TJATVG.h
//! @brief     (TJATVG) Module Header.

#ifndef TJATVG_H_
#define TJATVG_H_

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
 *	TJATVG module sensor initialization function. Function initializes TJATVG sensor output data pointer.
 *	
 *	@param
 *		[in] TJATVG_SenOutArg Pointer to TJATVG sensor output data.
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
extern void TJATVG_SenInitOutPtr(TJATVG_SenOutType *TJATVG_SenOutArg);

/*!
 *	TJATVG module sensor reset function.
 *	
 *	@pre
 *		- The TJATVG sensor initialization function(s) must be called once.
 *		- The TJATVG sensor debug/output data pointer(s) should not be NULL.
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
 *		[Output Signal] [S_TJATVG_CrvAmplActivated_nu](@ref TJATVG_SenOutType::S_TJATVG_CrvAmplActivated_nu) \n
 *		[Output Signal] [S_TJATVG_DeratingLevel_nu](@ref TJATVG_SenOutType::S_TJATVG_DeratingLevel_nu) \n
 *		[Output Signal] [S_TJATVG_DistYTolLeTgtArea_met](@ref TJATVG_SenOutType::S_TJATVG_DistYTolLeTgtArea_met) \n
 *		[Output Signal] [S_TJATVG_DistYTolRiTgtArea_met](@ref TJATVG_SenOutType::S_TJATVG_DistYTolRiTgtArea_met) \n
 *		[Output Signal] [S_TJATVG_FTireAclMax_mps2](@ref TJATVG_SenOutType::S_TJATVG_FTireAclMax_mps2) \n
 *		[Output Signal] [S_TJATVG_FTireAclMin_mps2](@ref TJATVG_SenOutType::S_TJATVG_FTireAclMin_mps2) \n
 *		[Output Signal] [S_TJATVG_GrdLimitTgtCrvTGC_1pms](@ref TJATVG_SenOutType::S_TJATVG_GrdLimitTgtCrvTGC_1pms) \n
 *		[Output Signal] [S_TJATVG_HighStatAccu_bool](@ref TJATVG_SenOutType::S_TJATVG_HighStatAccu_bool) \n
 *		[Output Signal] [S_TJATVG_LimiterActivated_nu](@ref TJATVG_SenOutType::S_TJATVG_LimiterActivated_nu) \n
 *		[Output Signal] [S_TJATVG_LimiterTimeDuration_sec](@ref TJATVG_SenOutType::S_TJATVG_LimiterTimeDuration_sec) \n
 *		[Output Signal] [S_TJATVG_LimiterType_nu](@ref TJATVG_SenOutType::S_TJATVG_LimiterType_nu) \n
 *		[Output Signal] [S_TJATVG_LtcyCompActivated_nu](@ref TJATVG_SenOutType::S_TJATVG_LtcyCompActivated_nu) \n
 *		[Output Signal] [S_TJATVG_MaxCrvGrdBuildup_1pms](@ref TJATVG_SenOutType::S_TJATVG_MaxCrvGrdBuildup_1pms) \n
 *		[Output Signal] [S_TJATVG_MaxCrvGrdRed_1pms](@ref TJATVG_SenOutType::S_TJATVG_MaxCrvGrdRed_1pms) \n
 *		[Output Signal] [S_TJATVG_MaxCrvTrajGuiCtrl_1pm](@ref TJATVG_SenOutType::S_TJATVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		[Output Signal] [S_TJATVG_MaxJerkAllowed_mps3](@ref TJATVG_SenOutType::S_TJATVG_MaxJerkAllowed_mps3) \n
 *		[Output Signal] [S_TJATVG_MaxTrqScalGrad_1ps](@ref TJATVG_SenOutType::S_TJATVG_MaxTrqScalGrad_1ps) \n
 *		[Output Signal] [S_TJATVG_MaxTrqScalLimit_nu](@ref TJATVG_SenOutType::S_TJATVG_MaxTrqScalLimit_nu) \n
 *		[Output Signal] [S_TJATVG_ObstacleAclX_mps2](@ref TJATVG_SenOutType::S_TJATVG_ObstacleAclX_mps2) \n
 *		[Output Signal] [S_TJATVG_ObstacleDistX_met](@ref TJATVG_SenOutType::S_TJATVG_ObstacleDistX_met) \n
 *		[Output Signal] [S_TJATVG_ObstacleDistY_met](@ref TJATVG_SenOutType::S_TJATVG_ObstacleDistY_met) \n
 *		[Output Signal] [S_TJATVG_ObstacleVelX_mps](@ref TJATVG_SenOutType::S_TJATVG_ObstacleVelX_mps) \n
 *		[Output Signal] [S_TJATVG_ObstacleWidth_met](@ref TJATVG_SenOutType::S_TJATVG_ObstacleWidth_met) \n
 *		[Output Signal] [S_TJATVG_PlanningHorizon_sec](@ref TJATVG_SenOutType::S_TJATVG_PlanningHorizon_sec) \n
 *		[Output Signal] [S_TJATVG_PredTimeCrv_sec](@ref TJATVG_SenOutType::S_TJATVG_PredTimeCrv_sec) \n
 *		[Output Signal] [S_TJATVG_PredTimeHeadAng_sec](@ref TJATVG_SenOutType::S_TJATVG_PredTimeHeadAng_sec) \n
 *		[Output Signal] [S_TJATVG_SensorTStamp_sec](@ref TJATVG_SenOutType::S_TJATVG_SensorTStamp_sec) \n
 *		[Output Signal] [S_TJATVG_StrWhStifGrad_1ps](@ref TJATVG_SenOutType::S_TJATVG_StrWhStifGrad_1ps) \n
 *		[Output Signal] [S_TJATVG_StrWhStifLimit_nu](@ref TJATVG_SenOutType::S_TJATVG_StrWhStifLimit_nu) \n
 *		[Output Signal] [S_TJATVG_TrajGuiQu_nu](@ref TJATVG_SenOutType::S_TJATVG_TrajGuiQu_nu) \n
 *		[Output Signal] [S_TJATVG_TrajPlanServQu_nu](@ref TJATVG_SenOutType::S_TJATVG_TrajPlanServQu_nu) \n
 *		[Output Signal] [S_TJATVG_TriggerReplan_nu](@ref TJATVG_SenOutType::S_TJATVG_TriggerReplan_nu) \n
 *		[Output Signal] [S_TJATVG_TrqRampGrad_1ps](@ref TJATVG_SenOutType::S_TJATVG_TrqRampGrad_1ps) \n
 *		[Output Signal] [S_TJATVG_WeightEndTime_nu](@ref TJATVG_SenOutType::S_TJATVG_WeightEndTime_nu) \n
 *		[Output Signal] [S_TJATVG_WeightTgtDistY_nu](@ref TJATVG_SenOutType::S_TJATVG_WeightTgtDistY_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TJATVG_SenProcess_Globals) of the function @ref TJATVG_SenProcess.
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
extern void TJATVG_SenReset(void);

/*!
 *	TJATVG module sensor process function.
 *	
 *	@pre
 *		- The TJATVG sensor initialization function(s) must be called once.
 *		- The TJATVG sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJATVG_SenProcess_Globals
 *		[S_TJATVG_CrvAmplActivated_nu](@ref TJATVG_SenOutType::S_TJATVG_CrvAmplActivated_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_DeratingLevel_nu](@ref TJATVG_SenOutType::S_TJATVG_DeratingLevel_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the TJA function \n\n
 *		[S_TJATVG_DistYTolLeTgtArea_met](@ref TJATVG_SenOutType::S_TJATVG_DistYTolLeTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_DistYTolRiTgtArea_met](@ref TJATVG_SenOutType::S_TJATVG_DistYTolRiTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_FTireAclMax_mps2](@ref TJATVG_SenOutType::S_TJATVG_FTireAclMax_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_FTireAclMin_mps2](@ref TJATVG_SenOutType::S_TJATVG_FTireAclMin_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_GrdLimitTgtCrvTGC_1pms](@ref TJATVG_SenOutType::S_TJATVG_GrdLimitTgtCrvTGC_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_HighStatAccu_bool](@ref TJATVG_SenOutType::S_TJATVG_HighStatAccu_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		[S_TJATVG_LimiterActivated_nu](@ref TJATVG_SenOutType::S_TJATVG_LimiterActivated_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_LimiterTimeDuration_sec](@ref TJATVG_SenOutType::S_TJATVG_LimiterTimeDuration_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_LimiterType_nu](@ref TJATVG_SenOutType::S_TJATVG_LimiterType_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_LtcyCompActivated_nu](@ref TJATVG_SenOutType::S_TJATVG_LtcyCompActivated_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_MaxCrvGrdBuildup_1pms](@ref TJATVG_SenOutType::S_TJATVG_MaxCrvGrdBuildup_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_MaxCrvGrdRed_1pms](@ref TJATVG_SenOutType::S_TJATVG_MaxCrvGrdRed_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_MaxCrvTrajGuiCtrl_1pm](@ref TJATVG_SenOutType::S_TJATVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_MaxJerkAllowed_mps3](@ref TJATVG_SenOutType::S_TJATVG_MaxJerkAllowed_mps3) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		[S_TJATVG_MaxTrqScalGrad_1ps](@ref TJATVG_SenOutType::S_TJATVG_MaxTrqScalGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		[S_TJATVG_MaxTrqScalLimit_nu](@ref TJATVG_SenOutType::S_TJATVG_MaxTrqScalLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		[S_TJATVG_ObstacleAclX_mps2](@ref TJATVG_SenOutType::S_TJATVG_ObstacleAclX_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_ObstacleDistX_met](@ref TJATVG_SenOutType::S_TJATVG_ObstacleDistX_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_ObstacleDistY_met](@ref TJATVG_SenOutType::S_TJATVG_ObstacleDistY_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_ObstacleVelX_mps](@ref TJATVG_SenOutType::S_TJATVG_ObstacleVelX_mps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_ObstacleWidth_met](@ref TJATVG_SenOutType::S_TJATVG_ObstacleWidth_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_PlanningHorizon_sec](@ref TJATVG_SenOutType::S_TJATVG_PlanningHorizon_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_PredTimeCrv_sec](@ref TJATVG_SenOutType::S_TJATVG_PredTimeCrv_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_PredTimeHeadAng_sec](@ref TJATVG_SenOutType::S_TJATVG_PredTimeHeadAng_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_SensorTStamp_sec](@ref TJATVG_SenOutType::S_TJATVG_SensorTStamp_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n
 *		OF: radar time stamp \n
 *		ELSE: camera time stamp \n\n
 *		[S_TJATVG_StrWhStifGrad_1ps](@ref TJATVG_SenOutType::S_TJATVG_StrWhStifGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		[S_TJATVG_StrWhStifLimit_nu](@ref TJATVG_SenOutType::S_TJATVG_StrWhStifLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		[S_TJATVG_TrajGuiQu_nu](@ref TJATVG_SenOutType::S_TJATVG_TrajGuiQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		[S_TJATVG_TrajPlanServQu_nu](@ref TJATVG_SenOutType::S_TJATVG_TrajPlanServQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_TriggerReplan_nu](@ref TJATVG_SenOutType::S_TJATVG_TriggerReplan_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_TrqRampGrad_1ps](@ref TJATVG_SenOutType::S_TJATVG_TrqRampGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		[S_TJATVG_WeightEndTime_nu](@ref TJATVG_SenOutType::S_TJATVG_WeightEndTime_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		[S_TJATVG_WeightTgtDistY_nu](@ref TJATVG_SenOutType::S_TJATVG_WeightTgtDistY_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_ABPLBP_ABDTimeStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		ABD data timestamp in seconds \n\n
 *		@ref S_ABPLBP_LaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane width \n\n
 *		@ref S_LCFRCV_DrivingMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Driving Mode Selection Signal. It can be selected among driving modes such as Sport, Eco or Comfort. \n\n
 *		@ref S_LCFRCV_VehStopped_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if the vehicle is in stop position \n\n
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
 *		@ref S_ODPFOP_AccFRObjTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Timestamp of object detection \n\n
 *		@ref S_TJAGEN_Abort_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA shall be aborted (no rampout) \n\n
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TJASTM_SysStateTJA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TJATTG_PredictionEnable_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if module outputs are predicted \n\n
 *		@ref S_TJATTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TransTriggerReplan_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Flag to trigger TRJPLN replan during mode transition \n\n
 *		@ref P_TJALKA_RampoutPredictOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable rampout prediction (lane prediction while LatDMC output is set to zero) \n\n
 *		@ref P_TJATTG_TransDurationPredct_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Transition duration to switch from predicted lane data to new detected lane data \n\n
 *		@ref P_TJATVG_DistYToleranceLeftTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_DistYToleranceRightTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_FTireAccelMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_FTireAccelMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_FactorCrvGrdBuildUp_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_FactorCrvGrdRed_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_HighStatAccu_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if high stationary accuracy is required. \n\n
 *		@ref P_TJATVG_LimiterMaxCrvGrd_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_LimiterMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_MD1DeratingLevel_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		MD1DeratingLevel \n\n
 *		@ref P_TJATVG_MD2DeratingLevel_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		MD2DeratingLevel \n\n
 *		@ref P_TJATVG_MD3DeratingLevel_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		MD3DeratingLevel \n\n
 *		@ref P_TJATVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum allowed jerk \n\n
 *		@ref P_TJATVG_MaxSteeringAngle_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_0_180_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: 0 \n
 *		\@max: 180 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_MaxTrqScalLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		TJATVG_APARAM \n\n
 *		@ref P_TJATVG_MaxTrqScalRampInGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum torque scaling gradient during ramp-in \n\n
 *		@ref P_TJATVG_MaxTrqScalRampOutGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum torque scaling gradient during ramp-out \n\n
 *		@ref P_TJATVG_MinFactorCrvGrd_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_APARAM \n\n
 *		@ref P_TJATVG_ModeTransTrigReplan_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable trigger replan during mode transitions \n\n
 *		@ref P_TJATVG_PlanHorzLaneChange_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Planning Horizon during lane change maneuver \n\n
 *		@ref P_TJATVG_PredTimeHeadAng_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_PredictionTimeCrv_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_SetMaxCrvAndGrdLims_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_StrWhStifAbortGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		TMC: \n
 *		Steering Wheel Stiffness Abort Ramp Out Gradient \n\n
 *		@ref P_TJATVG_StrWhStifLimitPredct_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		TJA specific steering wheel stiffness limiter during rampout prediction \n\n
 *		@ref P_TJATVG_StrWhStifLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		TJA specific steering wheel stiffness limiter \n\n
 *		@ref P_TJATVG_StrWhStifRampInGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering wheel stiffness gradient during ramp-in \n\n
 *		@ref P_TJATVG_StrWhStifRampOutGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering wheel stiffness gradient during ramp-out \n\n
 *		@ref P_TJATVG_TrajPlanValServQu_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_TrajPlanValSrvQuSALC_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Trajectory planning service qualifier for semi-automatic lane change \n
 *		(enables lane cross check) \n\n
 *		@ref P_TJATVG_TriggerReplan_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to trigger replanning \n\n
 *		@ref P_TJATVG_TrqAbortGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		TMC: \n
 *		Torque Ramp Abort Ramp Out Gradient \n\n
 *		@ref P_TJATVG_TrqRampInGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque ramp gradient during ramp-in \n\n
 *		@ref P_TJATVG_TrqRampOutGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque ramp gradient during ramp-out \n\n
 *		@ref P_TJATVG_UseLtcyCompCMB_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of latency compensation during CMB mode \n\n
 *		@ref P_TJATVG_UseLtcyCompLC_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of latency compensation during LC mode \n\n
 *		@ref P_TJATVG_UseLtcyCompOF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of latency compensation during OF mode \n\n
 *		@ref P_TJATVG_UseLtcyCompSALC_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of latency compensation during SALC mode \n\n
 *		@ref P_TJATVG_WeightEndtime_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_PARAMETER \n\n
 *		@ref P_TJATVG_WeightTgtDistY_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_APARAM \n\n
 *		@ref P_VEH_Wheelbase_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_LCF_LaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_TJATVG_CrvPlanHorizon_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		X axis for the Planning Horizon \n\n
 *		@ref X_TJATVG_VehVelX_RedFact_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_APARAM for Y_TJATVG_RedFact_Vel_nu \n\n
 *		@ref X_TJATVG_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_APARAM \n\n
 *		@ref Y_TJATVG_LWDeratLvlScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table for lane width derating level scaling factort \n\n
 *		@ref Y_TJATVG_PlanHorizonObjFolVal_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Lookup table for vehicle speed dependend planning horizon for OF \n\n
 *		@ref Y_TJATVG_PlanHorizonScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Y axis of the Planning Horizon scaling factor \n\n
 *		@ref Y_TJATVG_PlanningHorizonVal_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Lookup table for vehicle speed dependend planning horizon \n\n
 *		@ref Y_TJATVG_RedFact_Vel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATVG_APARAM \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJATVG Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJATVG_SEN/TJATVG/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJATVG_Testcase_Initialization) Initialization of the TJATVG
 *		-# [Testcase_ConstantSignals](@ref TJATVG_Testcase_ConstantSignals) All constant signals are set correctly
 *		-# [Testcase_S_TJATVG_TrajGuiQu_nu](@ref TJATVG_Testcase_S_TJATVG_TrajGuiQu_nu) DetermineTrajGuiQualifier
 *		-# [Testcase_S_TJATVG_PlanningHorizon_sec](@ref TJATVG_Testcase_S_TJATVG_PlanningHorizon_sec) Set Planning Horizon
 *		-# [Testcase_TorqueLimitationAndGradients](@ref TJATVG_Testcase_TorqueLimitationAndGradients) Set Torque Limiter and Gradients
 *		-# [Testcase_TargetCurvatureGradients](@ref TJATVG_Testcase_TargetCurvatureGradients) Set Torque Limiter and Gradients
 *		-# [Testcase_SensorTimeStamp](@ref TJATVG_Testcase_SensorTimeStamp) S_TJATVG_SensorTStamp_sec
 *		-# [Testcase_LatCompActivation](@ref TJATVG_Testcase_LatCompActivation) S_TJATVG_LtcyCompActivated_nu
 *		-# [Testcase_S_TJATVG_DeratingLevel_nu](@ref TJATVG_Testcase_S_TJATVG_DeratingLevel_nu) S_TJATVG_DeratingLevel_nu
 *		
 *	@traceability
 *		[\@link: TJATVG Module Requirements]()
 */
extern void TJATVG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TJATVG_H_
