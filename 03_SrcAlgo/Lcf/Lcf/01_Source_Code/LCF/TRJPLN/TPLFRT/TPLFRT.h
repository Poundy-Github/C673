/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFRT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLFRT.h
//! @brief     (TPLFRT) Module Header.

#ifndef TPLFRT_H_
#define TPLFRT_H_

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
 *	TPLFRT module vehicle initialization function. Function initializes TPLFRT vehicle debug data pointer.
 *	
 *	@param
 *		[in] TPLFRT_VehDbgArg Pointer to TPLFRT vehicle debug data.
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
extern void TPLFRT_VehInitDbgPtr(TPLFRT_VehDbgType *TPLFRT_VehDbgArg);

/*!
 *	TPLFRT module vehicle initialization function. Function initializes TPLFRT vehicle output data pointer.
 *	
 *	@param
 *		[in] TPLFRT_VehOutArg Pointer to TPLFRT vehicle output data.
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
extern void TPLFRT_VehInitOutPtr(TPLFRT_VehOutType *TPLFRT_VehOutArg);

/*!
 *	TPLFRT module vehicle reset function.
 *	
 *	@pre
 *		- The TPLFRT vehicle initialization function(s) must be called once.
 *		- The TPLFRT vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_TPLFRT_CurDistY1stDeriv_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY1stDeriv_mps) \n
 *		[Debug  Signal] [S_TPLFRT_CurDistY1stToPrev_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY1stToPrev_mps) \n
 *		[Debug  Signal] [S_TPLFRT_CurDistY2ndDeriv_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY2ndDeriv_mps2) \n
 *		[Debug  Signal] [S_TPLFRT_CurDistYPreview_met](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistYPreview_met) \n
 *		[Debug  Signal] [S_TPLFRT_CurDistY_met](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY_met) \n
 *		[Debug  Signal] [S_TPLFRT_DistY1stToDevHead_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_DistY1stToDevHead_mps) \n
 *		[Debug  Signal] [S_TPLFRT_DistY2ndToDevHead_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_DistY2ndToDevHead_mps2) \n
 *		[Debug  Signal] [S_TPLFRT_NumPointsCridrLeft_nu](@ref TPLFRT_VehDbgType::S_TPLFRT_NumPointsCridrLeft_nu) \n
 *		[Debug  Signal] [S_TPLFRT_NumTgtPoints_nu](@ref TPLFRT_VehDbgType::S_TPLFRT_NumTgtPoints_nu) \n
 *		[Debug  Signal] [S_TPLFRT_PlanHorizonVisRange_sec](@ref TPLFRT_VehDbgType::S_TPLFRT_PlanHorizonVisRange_sec) \n
 *		[Debug  Signal] [S_TPLFRT_PreviewTimeHeading_sec](@ref TPLFRT_VehDbgType::S_TPLFRT_PreviewTimeHeading_sec) \n
 *		[Debug  Signal] [S_TPLFRT_TgtDistY1stDeriv_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtDistY1stDeriv_mps) \n
 *		[Debug  Signal] [S_TPLFRT_TgtDistY2ndDeriv_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtDistY2ndDeriv_mps2) \n
 *		[Debug  Signal] [S_TPLFRT_TgtDistY_met](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtDistY_met) \n
 *		[Debug  Signal] [S_TPLFRT_TgtPoints_nu](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtPoints_nu) \n
 *		[Debug  Signal] [S_TPLFRT_TrajAclRefCurve_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajAclRefCurve_mps2) \n
 *		[Debug  Signal] [S_TPLFRT_TrajDistY1stToPrev_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajDistY1stToPrev_mps) \n
 *		[Debug  Signal] [S_TPLFRT_TrajDistY2ndToPrev_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajDistY2ndToPrev_mps2) \n
 *		[Debug  Signal] [S_TPLFRT_TrajDistYPrev_met](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajDistYPrev_met) \n
 *		[Debug  Signal] [S_TPLFRT_TrajPlanningHorizon_sec](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajPlanningHorizon_sec) \n
 *		[Debug  Signal] [S_TPLFRT_TrajVelRefCurve_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajVelRefCurve_mps) \n
 *		[Output Signal] [S_TPLFRT_LeftDistY_met](@ref TPLFRT_VehOutType::S_TPLFRT_LeftDistY_met) \n\n
 *		For signal details, see sub-section [Globals](@ref TPLFRT_VehProcess_Globals) of the function @ref TPLFRT_VehProcess.
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
extern void TPLFRT_VehReset(void);

/*!
 *	TPLFRT module vehicle process function.
 *	
 *	@pre
 *		- The TPLFRT vehicle initialization function(s) must be called once.
 *		- The TPLFRT vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TPLFRT_VehProcess_Globals
 *		[S_TPLFRT_CurDistY1stDeriv_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY1stDeriv_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_CurDistY1stToPrev_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY1stToPrev_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_CurDistY2ndDeriv_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY2ndDeriv_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_CurDistYPreview_met](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistYPreview_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_CurDistY_met](@ref TPLFRT_VehDbgType::S_TPLFRT_CurDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_DistY1stToDevHead_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_DistY1stToDevHead_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_DistY2ndToDevHead_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_DistY2ndToDevHead_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_NumPointsCridrLeft_nu](@ref TPLFRT_VehDbgType::S_TPLFRT_NumPointsCridrLeft_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_NumTgtPoints_nu](@ref TPLFRT_VehDbgType::S_TPLFRT_NumTgtPoints_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_PlanHorizonVisRange_sec](@ref TPLFRT_VehDbgType::S_TPLFRT_PlanHorizonVisRange_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_PreviewTimeHeading_sec](@ref TPLFRT_VehDbgType::S_TPLFRT_PreviewTimeHeading_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TgtDistY1stDeriv_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtDistY1stDeriv_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TgtDistY2ndDeriv_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtDistY2ndDeriv_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TgtDistY_met](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TgtPoints_nu](@ref TPLFRT_VehDbgType::S_TPLFRT_TgtPoints_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TrajAclRefCurve_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajAclRefCurve_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TrajDistY1stToPrev_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajDistY1stToPrev_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TrajDistY2ndToPrev_mps2](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajDistY2ndToPrev_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TrajDistYPrev_met](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajDistYPrev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TrajPlanningHorizon_sec](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajPlanningHorizon_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_TrajVelRefCurve_mps](@ref TPLFRT_VehDbgType::S_TPLFRT_TrajVelRefCurve_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFRT_LeftDistY_met](@ref TPLFRT_VehOutType::S_TPLFRT_LeftDistY_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x100x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_CSCLTA_PlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_LCFRCV_KappaSumCommand_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		sum curvature command from DMC \n\n
 *		@ref S_LCFRCV_VehAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Vehicle longitudinal acceleration \n\n
 *		@ref S_LCFRCV_VehCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Vehicle curvature \n\n
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
 *		@ref S_TPLCEN_PredictionTimeHead_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Prediction time of the heading, saturated, ramped up \n\n
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
 *		@ref S_TPLCEN_TrajPlanEnbl_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_TrigReplanTgtTraj_nu \n
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
 *		@ref S_TPLFBT_TrajDistYPrev_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFBT_TrajHeadingPrev_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFBT_TrajTgtCrvPrev_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLLCO_DevDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		vehicle ego lateral distance in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_DevHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		vehicle heading angle in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_LeftCorridorCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		left corridor curvature in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_LeftCorridorHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		left corridor heading angle in right corridor cooridnate system \n\n
 *		@ref S_TPLLCO_LeftCorridorLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		left corridor valid length in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_LeftCorridorPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		left corridor longitudinal start position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_LeftCorridorPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		left corridor lateral position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_LeftCridrChngOfCrv_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		left corridor curvature change in right corridor cooridinate system \n\n
 *		@ref S_TPLLCO_ReplanDevDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		deviation in lateral position by replanning \n\n
 *		@ref S_TPLLCO_ReplanDevHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		heading angle deviation by replanning \n\n
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
 *		@ref S_TPLLCO_RightCorridorPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		right corridor longitudinal start position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_RightCorridorPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		right corridor lateral position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_RightCridrHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		right corridor heading angle in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetCorridorCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		target corridor curvature in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetCorridorPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		target corridor longitudinal start position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetCorridorPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		target corridor lateral position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetCridrHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		target corridor heading angle in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetCridrLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		target corridor valid length in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TgtCridrChngOfCrv_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		target corridor curvature change in right corridor coordinate system \n\n
 *		@ref P_TPLFRT_CalcLeftCridrEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLFRT_CridrSwitchDetection_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLFRT_PlnHrznMinBarrier_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Planning Horizon Minimum Barrier \n\n
 *		@ref P_TPLFRT_TgtPointMin_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Min. target point for trajectory planning (in time te) \n\n
 *		@ref P_TPLFRT_UseDMCSumCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		switch between the planer curvature and the dmc sum curvature as start curvature \n\n
 *		@ref P_TPLFRT_UseTgtTrajX0_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TPLFRT Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TPLFRT_Testcase_Initialization) Initialization of the TPLFRT
 *		-# [Testcase_S_TPLFRT_CurDistY_met](@ref TPLFRT_Testcase_S_TPLFRT_CurDistY_met) S_TPLFRT_CurDistY_met
 *		-# [Testcase_S_TPLFRT_CurDistY1stDeriv_mps](@ref TPLFRT_Testcase_S_TPLFRT_CurDistY1stDeriv_mps) S_TPLFRT_CurDistY1stDeriv_mps
 *		-# [Testcase_S_TPLFRT_CurDistY2ndDeriv_mps2](@ref TPLFRT_Testcase_S_TPLFRT_CurDistY2ndDeriv_mps2) S_TPLFRT_CurDistY2ndDeriv_mps2
 *		-# [Testcase_S_TPLFRT_TrajVelRefCurve_mps](@ref TPLFRT_Testcase_S_TPLFRT_TrajVelRefCurve_mps) DOORS ID FCT_CMP_TRJPLN_290
 *		-# [Testcase_S_TPLFRT_TrajAclRefCurve_mps2](@ref TPLFRT_Testcase_S_TPLFRT_TrajAclRefCurve_mps2) S_TPLFRT_TrajAclRefCurve_mps2
 *		-# [Testcase_S_TPLFRT_TgtDistY_met](@ref TPLFRT_Testcase_S_TPLFRT_TgtDistY_met) S_TPLFRT_TgtDistY_met
 *		-# [Testcase_S_TPLFRT_LeftDistY_met](@ref TPLFRT_Testcase_S_TPLFRT_LeftDistY_met) S_TPLFRT_LeftDistY_met
 *		-# [Testcase_S_TPLFRT_TgtDistY2ndDeriv_mps2](@ref TPLFRT_Testcase_S_TPLFRT_TgtDistY2ndDeriv_mps2) S_TPLFRT_TgtDistY2ndDeriv_mps2
 *		-# [Testcase_S_TPLFRT_LeftDistY_met](@ref TPLFRT_Testcase_S_TPLFRT_LeftDistY_met) S_TPLFRT_LeftDistY_met
 *		-# [Testcase_S_TPLFRT_TgtPoints_nu](@ref TPLFRT_Testcase_S_TPLFRT_TgtPoints_nu) S_TPLFRT_TgtPoints_nu
 *		-# [Testcase_S_TPLFRT_TrajDistYPrev_met](@ref TPLFRT_Testcase_S_TPLFRT_TrajDistYPrev_met) S_TPLFRT_TrajDistYPrev_met
 *		-# [Testcase_S_TPLFRT_TrajDistY1stToPrev_mps](@ref TPLFRT_Testcase_S_TPLFRT_TrajDistY1stToPrev_mps) S_TPLFRT_TrajDistY1stToPrev_mps
 *		-# [Testcase_S_TPLFRT_TrajDistY2ndToPrev_mps2](@ref TPLFRT_Testcase_S_TPLFRT_TrajDistY2ndToPrev_mps2) S_TPLFRT_TrajDistY2ndToPrev_mps2
 *		-# [Testcase_S_TPLFRT_NumTgtPoints_nu](@ref TPLFRT_Testcase_S_TPLFRT_NumTgtPoints_nu) S_TPLFRT_NumTgtPoints_nu
 *		-# [Testcase_S_TPLFRT_TgtPoints_nu](@ref TPLFRT_Testcase_S_TPLFRT_TgtPoints_nu) S_TPLFRT_TgtPoints_nu
 *		
 *	@traceability
 *		[\@link: TPLFRT Module Requirements]()
 */
extern void TPLFRT_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TPLFRT_H_
