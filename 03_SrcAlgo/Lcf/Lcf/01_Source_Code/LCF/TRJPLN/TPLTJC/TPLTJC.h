/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLTJC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLTJC.h
//! @brief     (TPLTJC) Module Header.

#ifndef TPLTJC_H_
#define TPLTJC_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH/LCFVEH_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TPLTJC module vehicle initialization function. Function initializes TPLTJC vehicle debug data pointer.
 *	
 *	@param
 *		[in] TPLTJC_VehDbgArg Pointer to TPLTJC vehicle debug data.
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
extern void TPLTJC_VehInitDbgPtr(TPLTJC_VehDbgType *TPLTJC_VehDbgArg);

/*!
 *	TPLTJC module vehicle reset function.
 *	
 *	@pre
 *		- The TPLTJC vehicle initialization function(s) must be called once.
 *		- The TPLTJC vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TPLTJC_MaxAclTraj_mps2](@ref TPLTJC_VehDbgType::D_TPLTJC_MaxAclTraj_mps2) \n
 *		[Debug  Signal] [D_TPLTJC_MaxJerkOK_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_MaxJerkOK_nu) \n
 *		[Debug  Signal] [D_TPLTJC_MaxJerkTraj_mps3](@ref TPLTJC_VehDbgType::D_TPLTJC_MaxJerkTraj_mps3) \n
 *		[Debug  Signal] [D_TPLTJC_OptimalCost_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_OptimalCost_nu) \n
 *		[Debug  Signal] [D_TPLTJC_PassedTrajLenPercent_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_PassedTrajLenPercent_nu) \n
 *		[Debug  Signal] [D_TPLTJC_WeightEndTime_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_WeightEndTime_nu) \n
 *		[Debug  Signal] [D_TPLTJC_WeightTgtDistY_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_WeightTgtDistY_nu) \n
 *		[Debug  Signal] [S_TPLTJC_EndPointTrajectory_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_EndPointTrajectory_nu) \n
 *		[Debug  Signal] [S_TPLTJC_LengthOK_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_LengthOK_nu) \n
 *		[Debug  Signal] [S_TPLTJC_MatrixInverseOK_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_MatrixInverseOK_nu) \n
 *		[Debug  Signal] [S_TPLTJC_QuStatusTrajPlan_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_QuStatusTrajPlan_nu) \n
 *		[Debug  Signal] [S_TPLTJC_TrajDistY1stDeriv_mps](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY1stDeriv_mps) \n
 *		[Debug  Signal] [S_TPLTJC_TrajDistY2ndDeriv_mps2](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY2ndDeriv_mps2) \n
 *		[Debug  Signal] [S_TPLTJC_TrajDistY3rdDeriv_mps3](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY3rdDeriv_mps3) \n
 *		[Debug  Signal] [S_TPLTJC_TrajDistYFmPrev_met](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistYFmPrev_met) \n
 *		[Debug  Signal] [S_TPLTJC_TrajDistY_met](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY_met) \n
 *		[Debug  Signal] [S_TPLTJC_TrajEnd_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajEnd_nu) \n
 *		[Debug  Signal] [S_TPLTJC_TrajParam_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajParam_nu) \n
 *		[Debug  Signal] [S_TPLTJC_YDt2TrjFmKpPrevDT_mps2](@ref TPLTJC_VehDbgType::S_TPLTJC_YDt2TrjFmKpPrevDT_mps2) \n
 *		[Debug  Signal] [S_TPLTJC_YDt2TrjFmKpPrev_mps2](@ref TPLTJC_VehDbgType::S_TPLTJC_YDt2TrjFmKpPrev_mps2) \n
 *		[Debug  Signal] [S_TPLTJC_YDt3TrjFmKpPrevDT_mps3](@ref TPLTJC_VehDbgType::S_TPLTJC_YDt3TrjFmKpPrevDT_mps3) \n
 *		[Debug  Signal] [S_TPLTJC_YDtTrjFmHeadPrev_mps](@ref TPLTJC_VehDbgType::S_TPLTJC_YDtTrjFmHeadPrev_mps) \n\n
 *		For signal details, see sub-section [Globals](@ref TPLTJC_VehProcess_Globals) of the function @ref TPLTJC_VehProcess.
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
extern void TPLTJC_VehReset(void);

/*!
 *	TPLTJC module vehicle process function.
 *	
 *	@pre
 *		- The TPLTJC vehicle initialization function(s) must be called once.
 *		- The TPLTJC vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TPLTJC_VehProcess_Globals
 *		[D_TPLTJC_MaxAclTraj_mps2](@ref TPLTJC_VehDbgType::D_TPLTJC_MaxAclTraj_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Max. lateral acceleration of the planned trajectory. \n\n
 *		[D_TPLTJC_MaxJerkOK_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_MaxJerkOK_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Max jerk check result \n\n
 *		[D_TPLTJC_MaxJerkTraj_mps3](@ref TPLTJC_VehDbgType::D_TPLTJC_MaxJerkTraj_mps3) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps3_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Max jerk of the planned trajectory \n\n
 *		[D_TPLTJC_OptimalCost_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_OptimalCost_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Cost of the optimal trajectory \n\n
 *		[D_TPLTJC_PassedTrajLenPercent_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_PassedTrajLenPercent_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		percentage of the passed trajectory length \n\n
 *		[D_TPLTJC_WeightEndTime_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_WeightEndTime_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		used weight end time by planning \n\n
 *		[D_TPLTJC_WeightTgtDistY_nu](@ref TPLTJC_VehDbgType::D_TPLTJC_WeightTgtDistY_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		used weight target disty by planning \n\n
 *		[S_TPLTJC_EndPointTrajectory_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_EndPointTrajectory_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_LengthOK_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_LengthOK_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_MatrixInverseOK_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_MatrixInverseOK_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_QuStatusTrajPlan_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_QuStatusTrajPlan_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield indicates the planner status: 1: NOT OK 0: OK \n
 *		0 bit: min acceleration check \n
 *		1 bit: max acceleration check \n
 *		2 bit: right corridor boundary collision check \n
 *		3 bit: left corridor boundary collision check \n
 *		4 bit: object collision check \n
 *		5 bit: matrix invertible  \n
 *		6 bit: trajectory length \n
 *		7 bit: max jerk check \n
 *		8 bit: physical max curvature \n\n
 *		[S_TPLTJC_TrajDistY1stDeriv_mps](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY1stDeriv_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_TrajDistY2ndDeriv_mps2](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY2ndDeriv_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_TrajDistY3rdDeriv_mps3](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY3rdDeriv_mps3) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps3_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_TrajDistYFmPrev_met](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistYFmPrev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_TrajDistY_met](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_TrajEnd_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajEnd_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_TrajParam_nu](@ref TPLTJC_VehDbgType::S_TPLTJC_TrajParam_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_YDt2TrjFmKpPrevDT_mps2](@ref TPLTJC_VehDbgType::S_TPLTJC_YDt2TrjFmKpPrevDT_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_YDt2TrjFmKpPrev_mps2](@ref TPLTJC_VehDbgType::S_TPLTJC_YDt2TrjFmKpPrev_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_YDt3TrjFmKpPrevDT_mps3](@ref TPLTJC_VehDbgType::S_TPLTJC_YDt3TrjFmKpPrevDT_mps3) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps3_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLTJC_YDtTrjFmHeadPrev_mps](@ref TPLTJC_VehDbgType::S_TPLTJC_YDtTrjFmHeadPrev_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_CSCLTA_DistYTolLeTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_DistYTolRiTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_FTireAclMax_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_FTireAclMin_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_MaxJerkAllowed_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref S_CSCLTA_ObstacleAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_ObstacleDistX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_ObstacleDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_ObstacleVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_ObstacleWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TrajPlanServQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_WeightEndTime_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_WeightTgtDistY_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_LCFRCV_SysCycleTimeVeh_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p03_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.03 \n
 *		\@description: \n
 *		Cycle Time for VEH task \n\n
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
 *		@ref S_TPLCEN_DelayVehGui_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_PredictionTimeCrv_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Prediction time of the curvature, saterated, ramped up \n\n
 *		@ref S_TPLCEN_ReplanCurValues_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_ReplanModeArcLength_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_ReplanTgtValues_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_TrigCustFctActn_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_TrigTrajReplan_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_CurDistY1stDeriv_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_CurDistY2ndDeriv_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_CurDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_LeftDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x100x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_NumPointsCridrLeft_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_NumTgtPoints_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_PlanHorizonVisRange_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_PreviewTimeHeading_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TgtDistY1stDeriv_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TgtDistY2ndDeriv_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TgtDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TgtPoints_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TrajAclRefCurve_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TrajDistY1stToPrev_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TrajDistY2ndToPrev_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TrajDistYPrev_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TrajPlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_TrajVelRefCurve_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLLCO_LeftCorridorLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		left corridor valid length in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_LeftCorridorPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		left corridor lateral position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_RiCridrChngOfCrv_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		right corridor curvature change in right corridor cooridnate system \n\n
 *		@ref S_TPLLCO_RightCorridorCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		right corridor curvature in right corridor cooridnate system \n\n
 *		@ref S_TPLLCO_RightCorridorLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		right corridor valid length in right corridor cooridnate system \n\n
 *		@ref P_TPLTJC_AllowedTimetoCross_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Allowed time to cross the lane boundary \n\n
 *		@ref P_TPLTJC_FTireAclMinScaling_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Scaling factor to dis/enable FTireAclMin check \n\n
 *		@ref P_TPLTJC_MaxArcLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLTJC_NumCircles_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_1_7_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLTJC_ParamCostFctInternal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLTJC_TMax_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p001_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLTJC_TimeTrajEndEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLTJC_WeightDistBased_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLTJC_WeightTgtDistY_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_VEH_Length_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Vehicle length \n\n
 *		@ref P_VEH_WidthWithMirrors_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Vehicle width with mirrors \n\n
 *		@ref P_VEH_Width_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_TPLTJC_PlanningHorizon_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x5x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		x axle with planning horizon \n\n
 *		@ref X_TPLTJC_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		x axle with vehicle longitudinal velocity \n\n
 *		@ref X_TPLTJC_WghtTgtDistYCustFct_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_TPLTJC_WghtTgtTimeCustFct_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TPLTJC_MaxAclY_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_0_20_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: 0 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		y axle with max. lateral accleration \n\n
 *		@ref Y_TPLTJC_WeightEndTime_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_20_1em3_t \n
 *		\@size: 1x5x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		y axle with weight end time \n\n
 *		@ref Y_TPLTJC_WghtTgtDistYCharact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TPLTJC_WghtTgtTimeCharact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TPLTJC Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TPLTJC_Testcase_Initialization) Initialization of the TPLTJC
 *		-# [Testcase_S_TPLTJC_QuStatusTrajPlan_nu](@ref TPLTJC_Testcase_S_TPLTJC_QuStatusTrajPlan_nu) DOORS ID FCT_CMP_TRJPLN_288 FCT_CMP_TRJPLN_224
 *		-# [Testcase_S_TPLTJC_TrajParam_nu](@ref TPLTJC_Testcase_S_TPLTJC_TrajParam_nu) S_TPLTJC_TrajParam_nu
 *		-# [Testcase_D_TPLTJC_WeightEndTime_nu](@ref TPLTJC_Testcase_D_TPLTJC_WeightEndTime_nu) D_TPLTJC_WeightEndTime_nu
 *		-# [Testcase_TrajCalc_MinFloat](@ref TPLTJC_Testcase_TrajCalc_MinFloat) subfunction in sfunction
 *		-# [Testcase_CovCalOptTrajektorie](@ref TPLTJC_Testcase_CovCalOptTrajektorie) Coverage in sfunction
 *		-# [Testcase_Sfunc](@ref TPLTJC_Testcase_Sfunc) Sfunc
 *		
 *	@traceability
 *		[\@link: TPLTJC Module Requirements]()
 */
extern void TPLTJC_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TPLTJC_H_
