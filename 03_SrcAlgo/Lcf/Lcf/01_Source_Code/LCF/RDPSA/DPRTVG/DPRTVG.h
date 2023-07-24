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
//! @file     DPRTVG.h
//! @brief     (DPRTVG) Module Header.

#ifndef DPRTVG_H_
#define DPRTVG_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "DPRTVG_type.h" //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DPRTVG module sensor initialization function. Function initializes DPRTVG sensor output data pointer.
 *	
 *	@param
 *		[in] DPRTVG_SenOutArg Pointer to DPRTVG sensor output data.
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
extern void DPRTVG_SenInitOutPtr(DPRTVG_SenOutType *DPRTVG_SenOutArg);

/*!
 *	DPRTVG module sensor reset function.
 *	
 *	@pre
 *		- The DPRTVG sensor initialization function(s) must be called once.
 *		- The DPRTVG sensor debug/output data pointer(s) should not be NULL.
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
 *		[Output Signal] [S_DPRTVG_DeratingLevel_nu](@ref DPRTVG_SenOutType::S_DPRTVG_DeratingLevel_nu) \n
 *		[Output Signal] [S_DPRTVG_DistYTolLeTgtArea_met](@ref DPRTVG_SenOutType::S_DPRTVG_DistYTolLeTgtArea_met) \n
 *		[Output Signal] [S_DPRTVG_DistYTolRiTgtArea_met](@ref DPRTVG_SenOutType::S_DPRTVG_DistYTolRiTgtArea_met) \n
 *		[Output Signal] [S_DPRTVG_FTireAclMax_mps2](@ref DPRTVG_SenOutType::S_DPRTVG_FTireAclMax_mps2) \n
 *		[Output Signal] [S_DPRTVG_FTireAclMin_mps2](@ref DPRTVG_SenOutType::S_DPRTVG_FTireAclMin_mps2) \n
 *		[Output Signal] [S_DPRTVG_GrdLimitTgtCrvTGC_1pms](@ref DPRTVG_SenOutType::S_DPRTVG_GrdLimitTgtCrvTGC_1pms) \n
 *		[Output Signal] [S_DPRTVG_HighStatAccu_bool](@ref DPRTVG_SenOutType::S_DPRTVG_HighStatAccu_bool) \n
 *		[Output Signal] [S_DPRTVG_LimiterActivated_bool](@ref DPRTVG_SenOutType::S_DPRTVG_LimiterActivated_bool) \n
 *		[Output Signal] [S_DPRTVG_LimiterTimeDuration_sec](@ref DPRTVG_SenOutType::S_DPRTVG_LimiterTimeDuration_sec) \n
 *		[Output Signal] [S_DPRTVG_LtcyCompActivated_bool](@ref DPRTVG_SenOutType::S_DPRTVG_LtcyCompActivated_bool) \n
 *		[Output Signal] [S_DPRTVG_MaxCrvGrdBuildup_1pms](@ref DPRTVG_SenOutType::S_DPRTVG_MaxCrvGrdBuildup_1pms) \n
 *		[Output Signal] [S_DPRTVG_MaxCrvGrdRed_1pms](@ref DPRTVG_SenOutType::S_DPRTVG_MaxCrvGrdRed_1pms) \n
 *		[Output Signal] [S_DPRTVG_MaxCrvTrajGuiCtrl_1pm](@ref DPRTVG_SenOutType::S_DPRTVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		[Output Signal] [S_DPRTVG_MaxJerkAllowed_mps3](@ref DPRTVG_SenOutType::S_DPRTVG_MaxJerkAllowed_mps3) \n
 *		[Output Signal] [S_DPRTVG_MaxTrqScalGrad_1ps](@ref DPRTVG_SenOutType::S_DPRTVG_MaxTrqScalGrad_1ps) \n
 *		[Output Signal] [S_DPRTVG_MaxTrqScalLimit_nu](@ref DPRTVG_SenOutType::S_DPRTVG_MaxTrqScalLimit_nu) \n
 *		[Output Signal] [S_DPRTVG_ObstacleAclX_mps2](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleAclX_mps2) \n
 *		[Output Signal] [S_DPRTVG_ObstacleDistX_met](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleDistX_met) \n
 *		[Output Signal] [S_DPRTVG_ObstacleDistY_met](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleDistY_met) \n
 *		[Output Signal] [S_DPRTVG_ObstacleVelX_mps](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleVelX_mps) \n
 *		[Output Signal] [S_DPRTVG_ObstacleWidth_met](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleWidth_met) \n
 *		[Output Signal] [S_DPRTVG_PlanningHorizon_sec](@ref DPRTVG_SenOutType::S_DPRTVG_PlanningHorizon_sec) \n
 *		[Output Signal] [S_DPRTVG_PredTimeCrv_sec](@ref DPRTVG_SenOutType::S_DPRTVG_PredTimeCrv_sec) \n
 *		[Output Signal] [S_DPRTVG_PredTimeHeadAng_sec](@ref DPRTVG_SenOutType::S_DPRTVG_PredTimeHeadAng_sec) \n
 *		[Output Signal] [S_DPRTVG_SensorTStamp_sec](@ref DPRTVG_SenOutType::S_DPRTVG_SensorTStamp_sec) \n
 *		[Output Signal] [S_DPRTVG_StrWhStifGrad_1ps](@ref DPRTVG_SenOutType::S_DPRTVG_StrWhStifGrad_1ps) \n
 *		[Output Signal] [S_DPRTVG_StrWhStifLimit_nu](@ref DPRTVG_SenOutType::S_DPRTVG_StrWhStifLimit_nu) \n
 *		[Output Signal] [S_DPRTVG_TrajGuiQu_nu](@ref DPRTVG_SenOutType::S_DPRTVG_TrajGuiQu_nu) \n
 *		[Output Signal] [S_DPRTVG_TrajPlanServQu_nu](@ref DPRTVG_SenOutType::S_DPRTVG_TrajPlanServQu_nu) \n
 *		[Output Signal] [S_DPRTVG_TriggerReplan_bool](@ref DPRTVG_SenOutType::S_DPRTVG_TriggerReplan_bool) \n
 *		[Output Signal] [S_DPRTVG_TrqRampGrad_1ps](@ref DPRTVG_SenOutType::S_DPRTVG_TrqRampGrad_1ps) \n
 *		[Output Signal] [S_DPRTVG_WeightEndTime_nu](@ref DPRTVG_SenOutType::S_DPRTVG_WeightEndTime_nu) \n
 *		[Output Signal] [S_DPRTVG_WeightTgtDistY_nu](@ref DPRTVG_SenOutType::S_DPRTVG_WeightTgtDistY_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref DPRTVG_SenProcess_Globals) of the function @ref DPRTVG_SenProcess.
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
extern void DPRTVG_SenReset(void);

/*!
 *	DPRTVG module sensor process function.
 *	
 *	@pre
 *		- The DPRTVG sensor initialization function(s) must be called once.
 *		- The DPRTVG sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPRTVG_SenProcess_Globals
 *		[S_DPRTVG_DeratingLevel_nu](@ref DPRTVG_SenOutType::S_DPRTVG_DeratingLevel_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the RDP function \n\n
 *		[S_DPRTVG_DistYTolLeTgtArea_met](@ref DPRTVG_SenOutType::S_DPRTVG_DistYTolLeTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_DistYTolRiTgtArea_met](@ref DPRTVG_SenOutType::S_DPRTVG_DistYTolRiTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_FTireAclMax_mps2](@ref DPRTVG_SenOutType::S_DPRTVG_FTireAclMax_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_FTireAclMin_mps2](@ref DPRTVG_SenOutType::S_DPRTVG_FTireAclMin_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_GrdLimitTgtCrvTGC_1pms](@ref DPRTVG_SenOutType::S_DPRTVG_GrdLimitTgtCrvTGC_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_HighStatAccu_bool](@ref DPRTVG_SenOutType::S_DPRTVG_HighStatAccu_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		[S_DPRTVG_LimiterActivated_bool](@ref DPRTVG_SenOutType::S_DPRTVG_LimiterActivated_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		[S_DPRTVG_LimiterTimeDuration_sec](@ref DPRTVG_SenOutType::S_DPRTVG_LimiterTimeDuration_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_LtcyCompActivated_bool](@ref DPRTVG_SenOutType::S_DPRTVG_LtcyCompActivated_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for the latency compensation in the TRJPLN. \n\n
 *		[S_DPRTVG_MaxCrvGrdBuildup_1pms](@ref DPRTVG_SenOutType::S_DPRTVG_MaxCrvGrdBuildup_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_MaxCrvGrdRed_1pms](@ref DPRTVG_SenOutType::S_DPRTVG_MaxCrvGrdRed_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_MaxCrvTrajGuiCtrl_1pm](@ref DPRTVG_SenOutType::S_DPRTVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_MaxJerkAllowed_mps3](@ref DPRTVG_SenOutType::S_DPRTVG_MaxJerkAllowed_mps3) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		[S_DPRTVG_MaxTrqScalGrad_1ps](@ref DPRTVG_SenOutType::S_DPRTVG_MaxTrqScalGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		[S_DPRTVG_MaxTrqScalLimit_nu](@ref DPRTVG_SenOutType::S_DPRTVG_MaxTrqScalLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		[S_DPRTVG_ObstacleAclX_mps2](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleAclX_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_ObstacleDistX_met](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleDistX_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_ObstacleDistY_met](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleDistY_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_ObstacleVelX_mps](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleVelX_mps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_ObstacleWidth_met](@ref DPRTVG_SenOutType::S_DPRTVG_ObstacleWidth_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_PlanningHorizon_sec](@ref DPRTVG_SenOutType::S_DPRTVG_PlanningHorizon_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_PredTimeCrv_sec](@ref DPRTVG_SenOutType::S_DPRTVG_PredTimeCrv_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_PredTimeHeadAng_sec](@ref DPRTVG_SenOutType::S_DPRTVG_PredTimeHeadAng_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_SensorTStamp_sec](@ref DPRTVG_SenOutType::S_DPRTVG_SensorTStamp_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		[S_DPRTVG_StrWhStifGrad_1ps](@ref DPRTVG_SenOutType::S_DPRTVG_StrWhStifGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		[S_DPRTVG_StrWhStifLimit_nu](@ref DPRTVG_SenOutType::S_DPRTVG_StrWhStifLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		[S_DPRTVG_TrajGuiQu_nu](@ref DPRTVG_SenOutType::S_DPRTVG_TrajGuiQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		[S_DPRTVG_TrajPlanServQu_nu](@ref DPRTVG_SenOutType::S_DPRTVG_TrajPlanServQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_TriggerReplan_bool](@ref DPRTVG_SenOutType::S_DPRTVG_TriggerReplan_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		It has to be 1 for TRJPLN to calculate a trajectory. \n\n
 *		[S_DPRTVG_TrqRampGrad_1ps](@ref DPRTVG_SenOutType::S_DPRTVG_TrqRampGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		[S_DPRTVG_WeightEndTime_nu](@ref DPRTVG_SenOutType::S_DPRTVG_WeightEndTime_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTVG_WeightTgtDistY_nu](@ref DPRTVG_SenOutType::S_DPRTVG_WeightTgtDistY_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
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
 *		@ref S_DPRSIA_VelLatLnLeRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_VelLatLnRiRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_VelLatReLeRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left road edge for the RDP. \n\n
 *		@ref S_DPRSIA_VelLatReRiRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right road edge for the RDP. \n\n
 *		@ref S_DPRSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_DPRSMI_FunctionAborted_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		RDP aborted a lateral intervention. \n\n
 *		@ref S_DPRSMI_SysStateRDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the RDP function. \n\n
 *		@ref S_DPRSMI_TriggerReason_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Trigger Reason of the RDP function. \n\n
 *		@ref S_DPRTTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajPosY0_met \n
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
 *		@ref P_DPRTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_FTireAccelMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_FTireAccelMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_HighStatAccu_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy enabler \n\n
 *		@ref P_DPRTVG_LimiterActivated_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		@ref P_DPRTVG_LimiterMaxCrvGrd_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_5_1em7_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Maximal limiter curvature gradient allowed. \n\n
 *		@ref P_DPRTVG_LimiterMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_50_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximal limiter curvature allowed. \n\n
 *		@ref P_DPRTVG_LimiterTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Duration of the target curvature imit in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		@ref P_DPRTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref P_DPRTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		@ref P_DPRTVG_MaxTrqScalRampInGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Ramp In Gradient \n\n
 *		@ref P_DPRTVG_MaxTrqScalRampOutGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Ramp Out Gradient \n\n
 *		@ref P_DPRTVG_PredTimeCrv_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_PredTimeHeadAng_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_StrWhStifAbortROGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Abort Steering Wheel Stiffness Ramp Out Gradient \n\n
 *		@ref P_DPRTVG_StrWhStifLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		@ref P_DPRTVG_StrWhStifROGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Standard Steering Wheel Stiffness Ramp Out Gradient \n\n
 *		@ref P_DPRTVG_TrajPlanServQu_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_TriggerReplan_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Trigger replan flag. Enables a replanning when there is corridor information update. \n\n
 *		@ref P_DPRTVG_TrqAbortROGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Abort Torque Ramp Ramp Out Gradient \n\n
 *		@ref P_DPRTVG_TrqRampInGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Ramp In Gradient \n\n
 *		@ref P_DPRTVG_TrqRampOutGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Ramp Out Gradient \n\n
 *		@ref P_DPRTVG_UseLtcyComp_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTVG_WeightTgtDistY_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Weight of the target position in the trajectory planning \n\n
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
 *		@ref Y_DPRTVG_CrvPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant. \n\n
 *		@ref Y_DPRTVG_D2TPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Distance to Target dependant. \n\n
 *		@ref Y_DPRTVG_VXPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. VX dependant. \n\n
 *		@ref Y_DPRTVG_VXWeightEndtime_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Weight of the target final time in the trajectory planning. Speed dependent. \n\n
 *		@ref Y_DPRTVG_VYMD1DeratingLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the RDP function when Driving Mode is either equal to 1 or to a default value. Lateral Velocity dependant. \n\n
 *		@ref Y_DPRTVG_VYMD2DeratingLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the RDP function when Driving Mode is equal to 2. Lateral Velocity dependant. \n\n
 *		@ref Y_DPRTVG_VYMD3DeratingLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the RDP function when Driving Mode is equal to 3. Lateral Velocity dependant. \n\n
 *		@ref Y_DPRTVG_VYPlanHorizonLn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Planning Horizon for the calculation in the TRJPLN. Lateral Velocity dependant. Trigger due to road edge + lane marking. \n\n
 *		@ref Y_DPRTVG_VYPlanHorizonRe_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Planning Horizon for the calculation in the TRJPLN. Lateral Velocity dependant. Trigger due to road edge only. \n\n
 *		@ref Y_DPRTVG_VYStrWhStifRIGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Standard Steering Wheel Stiffness Ramp In Gradient. Lateral velocity dependant. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPRTVG Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPRTVG_Testcase_Initialization) Initialization of the DPRTVG
 *		-# [Testcase_Timestamp](@ref DPRTVG_Testcase_Timestamp) Timestamp
 *		-# [Testcase_ConstantOutputs](@ref DPRTVG_Testcase_ConstantOutputs) Constant Outputs
 *		-# [Testcase_ParameterOutputs](@ref DPRTVG_Testcase_ParameterOutputs) Parameter Outputs
 *		-# [Testcase_Trajectory_Guidance_Qualifier](@ref DPRTVG_Testcase_Trajectory_Guidance_Qualifier) Trajectory Guidance Qualifier
 *		-# [Testcase_LookUp_Tables](@ref DPRTVG_Testcase_LookUp_Tables) Lookup Tables
 *		-# [Testcase_Stiffness](@ref DPRTVG_Testcase_Stiffness) Stiffness
 *		
 *	@traceability
 *		[\@link: DPRTVG Module Requirements]()
 */
extern void DPRTVG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPRTVG_H_
