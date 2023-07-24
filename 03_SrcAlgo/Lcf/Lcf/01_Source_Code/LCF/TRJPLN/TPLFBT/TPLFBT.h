/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFBT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLFBT.h
//! @brief     (TPLFBT) Module Header.

#ifndef TPLFBT_H_
#define TPLFBT_H_

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
 *	TPLFBT module vehicle initialization function. Function initializes TPLFBT vehicle debug data pointer.
 *	
 *	@param
 *		[in] TPLFBT_VehDbgArg Pointer to TPLFBT vehicle debug data.
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
extern void TPLFBT_VehInitDbgPtr(TPLFBT_VehDbgType *TPLFBT_VehDbgArg);

/*!
 *	TPLFBT module vehicle initialization function. Function initializes TPLFBT vehicle output data pointer.
 *	
 *	@param
 *		[in] TPLFBT_VehOutArg Pointer to TPLFBT vehicle output data.
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
extern void TPLFBT_VehInitOutPtr(TPLFBT_VehOutType *TPLFBT_VehOutArg);

/*!
 *	TPLFBT module vehicle reset function.
 *	
 *	@pre
 *		- The TPLFBT vehicle initialization function(s) must be called once.
 *		- The TPLFBT vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TPLFBT_DeltaTargetCrv_1pm](@ref TPLFBT_VehDbgType::D_TPLFBT_DeltaTargetCrv_1pm) \n
 *		[Debug  Signal] [D_TPLFBT_DeltaTargetHeading_rad](@ref TPLFBT_VehDbgType::D_TPLFBT_DeltaTargetHeading_rad) \n
 *		[Debug  Signal] [D_TPLFBT_DeltaTargetPosY0_met](@ref TPLFBT_VehDbgType::D_TPLFBT_DeltaTargetPosY0_met) \n
 *		[Debug  Signal] [D_TPLFBT_GradLimitActive_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_GradLimitActive_nu) \n
 *		[Debug  Signal] [D_TPLFBT_PlausiCheckStatus_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_PlausiCheckStatus_nu) \n
 *		[Debug  Signal] [D_TPLFBT_QuStatusTrajPlan_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_QuStatusTrajPlan_nu) \n
 *		[Debug  Signal] [D_TPLFBT_TargetSwitch_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_TargetSwitch_nu) \n
 *		[Debug  Signal] [D_TPLFBT_UseTargetCorridor_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_UseTargetCorridor_nu) \n
 *		[Debug  Signal] [S_TPLFBT_CtrlErrDistY_met](@ref TPLFBT_VehDbgType::S_TPLFBT_CtrlErrDistY_met) \n
 *		[Debug  Signal] [S_TPLFBT_CtrlErrHeadAglPrev_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_CtrlErrHeadAglPrev_rad) \n
 *		[Debug  Signal] [S_TPLFBT_CtrlErrHeadingAngle_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_CtrlErrHeadingAngle_rad) \n
 *		[Debug  Signal] [S_TPLFBT_CurDistY_met](@ref TPLFBT_VehDbgType::S_TPLFBT_CurDistY_met) \n
 *		[Debug  Signal] [S_TPLFBT_CurHeading_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_CurHeading_rad) \n
 *		[Debug  Signal] [S_TPLFBT_QuStatusTrajPlan_nu](@ref TPLFBT_VehDbgType::S_TPLFBT_QuStatusTrajPlan_nu) \n
 *		[Debug  Signal] [S_TPLFBT_TrajDistYPrev_met](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajDistYPrev_met) \n
 *		[Debug  Signal] [S_TPLFBT_TrajDistY_met](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajDistY_met) \n
 *		[Debug  Signal] [S_TPLFBT_TrajGuiQualifier_nu](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajGuiQualifier_nu) \n
 *		[Debug  Signal] [S_TPLFBT_TrajHeadInclPrev_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajHeadInclPrev_rad) \n
 *		[Debug  Signal] [S_TPLFBT_TrajHeadingPrev_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajHeadingPrev_rad) \n
 *		[Debug  Signal] [S_TPLFBT_TrajHeading_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajHeading_rad) \n
 *		[Debug  Signal] [S_TPLFBT_TrajTgtCrvPrev_1pm](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajTgtCrvPrev_1pm) \n
 *		[Debug  Signal] [S_TPLFBT_TrajTgtCrv_1pm](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajTgtCrv_1pm) \n
 *		[Output Signal] [D_TPLFBT_TgtCorridorCrvGrd_1pms](@ref TPLFBT_VehOutType::D_TPLFBT_TgtCorridorCrvGrd_1pms) \n
 *		[Output Signal] [D_TPLFBT_TgtCorridorCrv_1pm](@ref TPLFBT_VehOutType::D_TPLFBT_TgtCorridorCrv_1pm) \n
 *		[Output Signal] [D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms](@ref TPLFBT_VehOutType::D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms) \n
 *		[Output Signal] [D_TPLFBT_TgtTrjCrvPrvwDT_1pm](@ref TPLFBT_VehOutType::D_TPLFBT_TgtTrjCrvPrvwDT_1pm) \n
 *		[Output Signal] [D_TPLFBT_TrajHeadingPrvw_rad](@ref TPLFBT_VehOutType::D_TPLFBT_TrajHeadingPrvw_rad) \n
 *		[Output Signal] [D_TPLFBT_TrajPlanInvalid_nu](@ref TPLFBT_VehOutType::D_TPLFBT_TrajPlanInvalid_nu) \n
 *		[Output Signal] [D_TPLFBT_TrajTgtCrvGrdPrev_1pms](@ref TPLFBT_VehOutType::D_TPLFBT_TrajTgtCrvGrdPrev_1pms) \n\n
 *		For signal details, see sub-section [Globals](@ref TPLFBT_VehProcess_Globals) of the function @ref TPLFBT_VehProcess.
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
extern void TPLFBT_VehReset(void);

/*!
 *	TPLFBT module vehicle process function.
 *	
 *	@pre
 *		- The TPLFBT vehicle initialization function(s) must be called once.
 *		- The TPLFBT vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TPLFBT_VehProcess_Globals
 *		[D_TPLFBT_DeltaTargetCrv_1pm](@ref TPLFBT_VehDbgType::D_TPLFBT_DeltaTargetCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Difference between planned trajectory curvature and target corridor curvature \n\n
 *		[D_TPLFBT_DeltaTargetHeading_rad](@ref TPLFBT_VehDbgType::D_TPLFBT_DeltaTargetHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		Difference between planned trajectory heading and target corridor heading \n\n
 *		[D_TPLFBT_DeltaTargetPosY0_met](@ref TPLFBT_VehDbgType::D_TPLFBT_DeltaTargetPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		difference between planned trajectory lateral distance and target corridor lateral distance \n\n
 *		[D_TPLFBT_GradLimitActive_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_GradLimitActive_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TPLFBT_PlausiCheckStatus_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_PlausiCheckStatus_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates if the target disty is plausible. \n\n
 *		[D_TPLFBT_QuStatusTrajPlan_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_QuStatusTrajPlan_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Notes for D_TPLTJC_QuStatusTrajPlan_nu: \n
 *		Bitfield indicates the status of trajectory planner: 1 Not OK, 0 OK \n
 *		0 bit: min acceleration check  \n
 *		1 bit: max acceleration check  \n
 *		2 bit: right corridor boundary collision check  \n
 *		3 bit: left corridor boundary collision check  \n
 *		4 bit: object collision check  \n
 *		5 bit: matrix invertible   \n
 *		6 bit: trajectory length  \n
 *		7 bit: max jerk check  \n
 *		8 bit: lane cross check  \n
 *		9 bit: target lateral distance  \n
 *		10 bit: vehicle lateral distance  \n
 *		11 bit: right corridor transformation  \n
 *		12 bit: target corridor transformation  \n
 *		13 bit: left corridor transformation  \n
 *		14 bit: input target corridor heading \n\n
 *		[D_TPLFBT_TargetSwitch_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_TargetSwitch_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TPLFBT_UseTargetCorridor_nu](@ref TPLFBT_VehDbgType::D_TPLFBT_UseTargetCorridor_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_CtrlErrDistY_met](@ref TPLFBT_VehDbgType::S_TPLFBT_CtrlErrDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_CtrlErrHeadAglPrev_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_CtrlErrHeadAglPrev_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_CtrlErrHeadingAngle_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_CtrlErrHeadingAngle_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_CurDistY_met](@ref TPLFBT_VehDbgType::S_TPLFBT_CurDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_CurHeading_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_CurHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_QuStatusTrajPlan_nu](@ref TPLFBT_VehDbgType::S_TPLFBT_QuStatusTrajPlan_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Notes for S_TPLTJC_QuStatusTrajPlan_nu: \n
 *		Bitfield indicates the status of trajectory planner: 1 Not OK, 0 OK \n
 *		0 bit: min acceleration check  \n
 *		1 bit: max acceleration check  \n
 *		2 bit: right corridor boundary collision check  \n
 *		3 bit: left corridor boundary collision check  \n
 *		4 bit: object collision check  \n
 *		5 bit: matrix invertible   \n
 *		6 bit: trajectory length  \n
 *		7 bit: max jerk check  \n
 *		8 bit: lane cross check  \n
 *		9 bit: target lateral distance  \n
 *		10 bit: vehicle lateral distance  \n
 *		11 bit: right corridor transformation  \n
 *		12 bit: target corridor transformation  \n
 *		13 bit: left corridor transformation  \n
 *		14 bit: input target corridor heading \n\n
 *		[S_TPLFBT_TrajDistYPrev_met](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajDistYPrev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_TrajDistY_met](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_TrajGuiQualifier_nu](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajGuiQualifier_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier send by TPLFBT \n\n
 *		[S_TPLFBT_TrajHeadInclPrev_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajHeadInclPrev_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		 \n\n
 *		[S_TPLFBT_TrajHeadingPrev_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajHeadingPrev_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_TrajHeading_rad](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_TrajTgtCrvPrev_1pm](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajTgtCrvPrev_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLFBT_TrajTgtCrv_1pm](@ref TPLFBT_VehDbgType::S_TPLFBT_TrajTgtCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TPLFBT_TgtCorridorCrvGrd_1pms](@ref TPLFBT_VehOutType::D_TPLFBT_TgtCorridorCrvGrd_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		curvature gradient of the target corridor \n\n
 *		[D_TPLFBT_TgtCorridorCrv_1pm](@ref TPLFBT_VehOutType::D_TPLFBT_TgtCorridorCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Target corridor curvature \n\n
 *		[D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms](@ref TPLFBT_VehOutType::D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		curvature gradient of the target trajectory under consideration of preview and dead time \n\n
 *		[D_TPLFBT_TgtTrjCrvPrvwDT_1pm](@ref TPLFBT_VehOutType::D_TPLFBT_TgtTrjCrvPrvwDT_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		curvature of the target trajectory under consideration of preview and dead time \n\n
 *		[D_TPLFBT_TrajHeadingPrvw_rad](@ref TPLFBT_VehOutType::D_TPLFBT_TrajHeadingPrvw_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		trajectory heading inclusive preview time \n\n
 *		[D_TPLFBT_TrajPlanInvalid_nu](@ref TPLFBT_VehOutType::D_TPLFBT_TrajPlanInvalid_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: trajectory planner is invalid \n
 *		0: trajectory planner is valid \n\n
 *		[D_TPLFBT_TrajTgtCrvGrdPrev_1pms](@ref TPLFBT_VehOutType::D_TPLFBT_TrajTgtCrvGrdPrev_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Target trajectory curvature gradient \n\n
 *		@ref S_CSCLTA_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_SysStateLCF_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TrajGuiQualifier_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
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
 *		@ref S_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
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
 *		@ref S_TPLCEN_TrajPlanEnbl_nu \n
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
 *		@ref S_TPLFRT_CurDistY1stToPrev_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFRT_CurDistYPreview_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
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
 *		@ref S_TPLFRT_TrajVelRefCurve_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
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
 *		@ref S_TPLLCO_LeftCorridorPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		left corridor lateral position in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_PlausiCheckStatus_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield indicates the information of the plausibility check in TPLLCO 1: NOT OK 0: OK \n
 *		Bit 0: vehicle's lateral position \n
 *		Bit 1: right corridor transformation \n
 *		Bit 2: left corridor transformation \n\n
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
 *		@ref S_TPLLCO_RightCorridorPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		right corridor lateral position in right corridor coordinate system \n\n
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
 *		@ref S_TPLLCO_TargetCridrLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		target corridor valid length in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetPathHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		heading angle of the target path (target corridor with X0 = 0) \n\n
 *		@ref S_TPLLCO_TargetPathY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		lateral position of the target path (target corridor with X0 = 0) \n\n
 *		@ref S_TPLLCO_TgtCridrChngOfCrv_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		target corridor curvature change in right corridor coordinate system \n\n
 *		@ref S_TPLTJC_QuStatusTrajPlan_nu \n
 *		\@kind: Input Signal \n
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
 *		@ref S_TPLTJC_TrajDistY1stDeriv_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_TrajDistY2ndDeriv_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_TrajDistY3rdDeriv_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_TrajDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_YDt2TrjFmKpPrevDT_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_YDt2TrjFmKpPrev_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_YDt3TrjFmKpPrevDT_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLTJC_YDtTrjFmHeadPrev_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLFBT_CheckTrajPlanStatus_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit mask decides which bits of the trajectory planner status shall be checked: \n
 *		0 bit: min acceleration check \n
 *		1 bit: max acceleration check \n
 *		2 bit: right corridor boundary collision check \n
 *		3 bit: left corridor boundary collision check \n
 *		4 bit: object collision check \n
 *		5 bit: matrix invertible  \n
 *		6 bit: trajectory length \n
 *		7 bit: max jerk check \n
 *		8 bit: physical max curvature \n
 *		9 bit: target lateral distance \n
 *		10 bit: vehicle lateral distance \n
 *		11 bit: right corridor transformation \n
 *		12 bit: left corridor transformation \n\n
 *		@ref P_TPLFBT_CrvPredictionEnbl_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		enable prediction on the target corridor curvature \n\n
 *		@ref P_TPLFBT_DeltaTargetCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Threshold of the difference between planned trajectoy curvature and target corridor curvature for target switching. \n\n
 *		@ref P_TPLFBT_DeltaTargetHeading_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		Threshold of the difference between planned trajectoy heading and target corridor heading for target switching. \n\n
 *		@ref P_TPLFBT_DeltaTargetPosY0_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Threshold of the difference between planned trajectoy disty and target corridor disty for target switching. \n\n
 *		@ref P_TPLFBT_DurationGradLimit_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		duration for the gradient limitation by target switch \n\n
 *		@ref P_TPLFBT_GradLimitCrv_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p5_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.5 \n
 *		\@description: \n
 *		gradient limit of the curvature with regards to the distance \n\n
 *		@ref P_TPLFBT_GradLimitHeadHigh_rps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		heading gradient limitation after the duration defined by P_TPLFBT_DurationGradLimit_sec \n\n
 *		@ref P_TPLFBT_GradLimitHead_rps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		heading gradient limitation by target switch \n\n
 *		@ref P_TPLFBT_GradLimitPosYHigh_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_250_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 250 \n
 *		\@description: \n
 *		disty gradient limitation after the duration defined by P_TPLFBT_DurationGradLimit_sec \n\n
 *		@ref P_TPLFBT_GradLimitPosY_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		disty gradient limitation by target switch \n\n
 *		@ref P_TPLFBT_HeadCheckTolOBF_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Heading plausi check tolerance for object following \n\n
 *		@ref P_TPLFBT_HeadCheckTolerance_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Heading plausi check tolerance for all the functions and modes except object following \n\n
 *		@ref P_TPLFBT_HoldAllBits_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to determine if all the Qualifier Bits shall be stored during the hold phase \n\n
 *		@ref P_TPLFBT_MaxQuStatusHold_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Max. duration for holding the QuStatus \n\n
 *		@ref P_TPLFBT_MinQuStatusHold_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Min. duration for holding the QuStatus \n\n
 *		@ref P_TPLFBT_QuStatusHold_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter to disable the holding logic for QuStatus for test purpose. \n\n
 *		@ref P_TPLFBT_UseLongQuStatus_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		switch between the long and short qu status \n\n
 *		@ref P_TPLFBT_UseTgtCridrHeading_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		switch to decide if take the calculated target corridor heading angle or 0 as the target heading angle \n\n
 *		@ref X_TPLFBT_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		x axle: longitudinal velocity \n\n
 *		@ref Y_TPLFBT_GradLimitCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Y axle: speed dependent factor on the gradient limitation of curvature \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TPLFBT Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TPLFBT_Testcase_Initialization) Initialization of the TPLFBT
 *		-# [Testcase_S_TPLFBT_TrajHeading_rad](@ref TPLFBT_Testcase_S_TPLFBT_TrajHeading_rad) DOORS ID FCT_CMP_TRJPLN_291
 *		-# [Testcase_S_TPLFBT_TrajHeadInclPrev_rad](@ref TPLFBT_Testcase_S_TPLFBT_TrajHeadInclPrev_rad) DOORS ID FCT_CMP_TRJPLN_293
 *		-# [Testcase_S_TPLFBT_TrajDistY_met](@ref TPLFBT_Testcase_S_TPLFBT_TrajDistY_met) DOORS ID FCT_CMP_TRJPLN_292
 *		-# [Testcase_S_TPLFBT_TrajTgtCrv_1pm](@ref TPLFBT_Testcase_S_TPLFBT_TrajTgtCrv_1pm) DOORS ID FCT_CMP_TRJPLN_310, FCT_CMP_TRJPLN_312
 *		-# [Testcase_D_TPLFBT_PlausiCheckStatus_nu](@ref TPLFBT_Testcase_D_TPLFBT_PlausiCheckStatus_nu) DOORS ID FCT_CMP_TRJPLN_246, FCT_CMP_TRJPLN_317
 *		-# [Testcase_S_TPLFBT_QuStatusTrajPlan_nu](@ref TPLFBT_Testcase_S_TPLFBT_QuStatusTrajPlan_nu) DOORS ID FCT_CMP_TRJPLN_299, FCT_CMP_TRJPLN_250, FCT_CMP_TRJPLN_319
 *		-# [Testcase_D_TPLFBT_TrajPlanInvalid_nu](@ref TPLFBT_Testcase_D_TPLFBT_TrajPlanInvalid_nu) DOORS ID FCT_CMP_TRJPLN_353
 *		-# [Testcase_S_TPLFBT_TrajGuiQualifier_nu](@ref TPLFBT_Testcase_S_TPLFBT_TrajGuiQualifier_nu) DOORS ID FCT_CMP_TRJPLN_285
 *		-# [Testcase_S_TPLFBT_CurDistY_met](@ref TPLFBT_Testcase_S_TPLFBT_CurDistY_met) DOORS ID FCT_CMP_TRJPLN_252
 *		-# [Testcase_S_TPLFBT_TrajDistYPrev_met](@ref TPLFBT_Testcase_S_TPLFBT_TrajDistYPrev_met) DOORS ID FCT_CMP_TRJPLN_325
 *		-# [Testcase_D_TPLFBT_TgtCorridorCrv_1pm](@ref TPLFBT_Testcase_D_TPLFBT_TgtCorridorCrv_1pm) DOORS ID FCT_CMP_TRJPLN_313
 *		-# [Testcase_D_TPLFBT_TgtCrvPrvwDT_1pm](@ref TPLFBT_Testcase_D_TPLFBT_TgtCrvPrvwDT_1pm) DOORS ID FCT_CMP_TRJPLN_326
 *		-# [Testcase_S_TPLFBT_CurHeading_rad](@ref TPLFBT_Testcase_S_TPLFBT_CurHeading_rad) DOORS ID FCT_CMP_TRJPLN_271
 *		-# [Testcase_S_TPLFBT_TrajHeadingPrev_rad](@ref TPLFBT_Testcase_S_TPLFBT_TrajHeadingPrev_rad) DOORS ID FCT_CMP_TRJPLN_323
 *		-# [Testcase_D_TPLFBT_TrajHeadingPrvw_rad](@ref TPLFBT_Testcase_D_TPLFBT_TrajHeadingPrvw_rad) DOORS ID FCT_CMP_TRJPLN_324
 *		-# [Testcase_S_TPLFBT_TrajTgtCrvPrev_1pm](@ref TPLFBT_Testcase_S_TPLFBT_TrajTgtCrvPrev_1pm) DOORS ID FCT_CMP_TRJPLN_341
 *		-# [Testcase_D_TPLFBT_TgtTrjCrvPrvwDT_1pm](@ref TPLFBT_Testcase_D_TPLFBT_TgtTrjCrvPrvwDT_1pm) DOORS ID FCT_CMP_TRJPLN_314
 *		-# [Testcase_D_TPLFBT_TgtCorridorCrvGrd_1pms](@ref TPLFBT_Testcase_D_TPLFBT_TgtCorridorCrvGrd_1pms) DOORS ID FCT_CMP_TRJPLN_328
 *		-# [Testcase_D_TPLFBT_TrajTgtCrvGrdPrev_1pms](@ref TPLFBT_Testcase_D_TPLFBT_TrajTgtCrvGrdPrev_1pms) DOORS ID FCT_CMP_TRJPLN_342
 *		-# [Testcase_D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms](@ref TPLFBT_Testcase_D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms) DOORS ID FCT_CMP_TRJPLN_329
 *		-# [Testcase_D_TPLFBT_TargetSwitch_nu](@ref TPLFBT_Testcase_D_TPLFBT_TargetSwitch_nu) DOORS ID FCT_CMP_TRJPLN_316
 *		-# [Testcase_D_TPLFBT_UseTargetCorridor_nu](@ref TPLFBT_Testcase_D_TPLFBT_UseTargetCorridor_nu) DOORS ID FCT_CMP_TRJPLN_315
 *		-# [Testcase_D_TPLFBT_GradLimitActive_nu](@ref TPLFBT_Testcase_D_TPLFBT_GradLimitActive_nu) DOORS ID FCT_CMP_TRJPLN_330
 *		-# [Testcase_S_TPLFBT_CtrlErrDistY_met](@ref TPLFBT_Testcase_S_TPLFBT_CtrlErrDistY_met) DOORS ID FCT_CMP_TRJPLN_363
 *		-# [Testcase_S_TPLFBT_CtrlErrHeadAglPrev_rad](@ref TPLFBT_Testcase_S_TPLFBT_CtrlErrHeadAglPrev_rad) DOORS ID FCT_CMP_TRJPLN_365
 *		-# [Testcase_S_TPLFBT_CtrlErrHeadingAngle_rad](@ref TPLFBT_Testcase_S_TPLFBT_CtrlErrHeadingAngle_rad) DOORS ID FCT_CMP_TRJPLN_364
 *		-# [Testcase_TrajCalc_FBT_AvoidZero](@ref TPLFBT_Testcase_TrajCalc_FBT_AvoidZero) Code Coverage
 *		
 *	@traceability
 *		[\@link: TPLFBT Module Requirements]()
 */
extern void TPLFBT_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TPLFBT_H_
