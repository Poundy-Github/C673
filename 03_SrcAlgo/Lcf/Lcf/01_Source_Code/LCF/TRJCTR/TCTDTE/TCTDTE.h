/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTDTE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTDTE.h
//! @brief     (TCTDTE) Module Header.

#ifndef TCTDTE_H_
#define TCTDTE_H_

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
 *	TCTDTE module vehicle initialization function. Function initializes TCTDTE vehicle debug data pointer.
 *	
 *	@param
 *		[in] TCTDTE_VehDbgArg Pointer to TCTDTE vehicle debug data.
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
extern void TCTDTE_VehInitDbgPtr(TCTDTE_VehDbgType *TCTDTE_VehDbgArg);

/*!
 *	TCTDTE module vehicle reset function.
 *	
 *	@pre
 *		- The TCTDTE vehicle initialization function(s) must be called once.
 *		- The TCTDTE vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TCTDTE_CrvReqBnkAglComp_1pm](@ref TCTDTE_VehDbgType::D_TCTDTE_CrvReqBnkAglComp_1pm) \n
 *		[Debug  Signal] [D_TCTDTE_CrvReqDistrbStmTf_1pm](@ref TCTDTE_VehDbgType::D_TCTDTE_CrvReqDistrbStmTf_1pm) \n
 *		[Debug  Signal] [D_TCTDTE_DeltaSetBnkAglComp_rad](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetBnkAglComp_rad) \n
 *		[Debug  Signal] [D_TCTDTE_DeltaSetCroWiComp_deg](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetCroWiComp_deg) \n
 *		[Debug  Signal] [D_TCTDTE_DeltaSetCroWiComp_rad](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetCroWiComp_rad) \n
 *		[Debug  Signal] [D_TCTDTE_DeltaSetDstrbStmTf_rad](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetDstrbStmTf_rad) \n
 *		[Debug  Signal] [S_TCTDTE_CrvReqBnkAglComp_1pm](@ref TCTDTE_VehDbgType::S_TCTDTE_CrvReqBnkAglComp_1pm) \n
 *		[Debug  Signal] [S_TCTDTE_CrvReqDstrbComp_1pm](@ref TCTDTE_VehDbgType::S_TCTDTE_CrvReqDstrbComp_1pm) \n
 *		[Debug  Signal] [S_TCTDTE_DeltaSetBnkAglComp_rad](@ref TCTDTE_VehDbgType::S_TCTDTE_DeltaSetBnkAglComp_rad) \n
 *		[Debug  Signal] [S_TCTDTE_DeltaSetCroWiComp_rad](@ref TCTDTE_VehDbgType::S_TCTDTE_DeltaSetCroWiComp_rad) \n
 *		[Debug  Signal] [S_TCTDTE_DeltaSetDstrbComp_rad](@ref TCTDTE_VehDbgType::S_TCTDTE_DeltaSetDstrbComp_rad) \n
 *		[Debug  Signal] [S_TCTDTE_MccGLaDmcDenS0_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS0_nu) \n
 *		[Debug  Signal] [S_TCTDTE_MccGLaDmcDenS1_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS1_nu) \n
 *		[Debug  Signal] [S_TCTDTE_MccGLaDmcDenS2_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS2_nu) \n
 *		[Debug  Signal] [S_TCTDTE_MccGLaDmcDenS3_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS3_nu) \n
 *		[Debug  Signal] [S_TCTDTE_MccGLaDmcNumS0_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcNumS0_nu) \n
 *		[Debug  Signal] [S_TCTDTE_MccGLaDmcNumS1_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcNumS1_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TCTDTE_VehProcess_Globals) of the function @ref TCTDTE_VehProcess.
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
extern void TCTDTE_VehReset(void);

/*!
 *	TCTDTE module vehicle process function.
 *	
 *	@pre
 *		- The TCTDTE vehicle initialization function(s) must be called once.
 *		- The TCTDTE vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TCTDTE_VehProcess_Globals
 *		[D_TCTDTE_CrvReqBnkAglComp_1pm](@ref TCTDTE_VehDbgType::D_TCTDTE_CrvReqBnkAglComp_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTDTE_CrvReqDistrbStmTf_1pm](@ref TCTDTE_VehDbgType::D_TCTDTE_CrvReqDistrbStmTf_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Curvature request of the disturbance compensator based on the single track model \n\n
 *		[D_TCTDTE_DeltaSetBnkAglComp_rad](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetBnkAglComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTDTE_DeltaSetCroWiComp_deg](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetCroWiComp_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m50_50_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -50 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTDTE_DeltaSetCroWiComp_rad](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetCroWiComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Control signal /rad used to compensate crosswind \n\n
 *		[D_TCTDTE_DeltaSetDstrbStmTf_rad](@ref TCTDTE_VehDbgType::D_TCTDTE_DeltaSetDstrbStmTf_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTDTE_CrvReqBnkAglComp_1pm](@ref TCTDTE_VehDbgType::S_TCTDTE_CrvReqBnkAglComp_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTDTE_CrvReqDstrbComp_1pm](@ref TCTDTE_VehDbgType::S_TCTDTE_CrvReqDstrbComp_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTDTE_DeltaSetBnkAglComp_rad](@ref TCTDTE_VehDbgType::S_TCTDTE_DeltaSetBnkAglComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTDTE_DeltaSetCroWiComp_rad](@ref TCTDTE_VehDbgType::S_TCTDTE_DeltaSetCroWiComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Control signal /rad used to compensate crosswind \n\n
 *		[S_TCTDTE_DeltaSetDstrbComp_rad](@ref TCTDTE_VehDbgType::S_TCTDTE_DeltaSetDstrbComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Additional steer angle control signal part needed to compensate disturbances \n\n
 *		[S_TCTDTE_MccGLaDmcDenS0_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS0_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		s^0 coefficient of the approximated LaDMC transfer function's denominator \n\n
 *		[S_TCTDTE_MccGLaDmcDenS1_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS1_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		s^1 coefficient of the approximated LaDMC transfer function's denominator \n\n
 *		[S_TCTDTE_MccGLaDmcDenS2_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS2_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		s^2 coefficient of the approximated LaDMC transfer function's denominator \n\n
 *		[S_TCTDTE_MccGLaDmcDenS3_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcDenS3_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		s^3 coefficient of the approximated LaDMC transfer function's denominator \n\n
 *		[S_TCTDTE_MccGLaDmcNumS0_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcNumS0_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		s^0 coefficient of the approximated LaDMC transfer function's numerator \n\n
 *		[S_TCTDTE_MccGLaDmcNumS1_nu](@ref TCTDTE_VehDbgType::S_TCTDTE_MccGLaDmcNumS1_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		s^1 coefficient of the approximated LaDMC transfer function's numerator \n\n
 *		@ref S_LCFRCV_EPS_ManualTrqActualVal_Nm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Rename of S_RTE_EPS_ManualTrqActualVal_Nm \n\n
 *		@ref S_LCFRCV_RoadBankAngle_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Road bank angle /rad provided by VDY \n\n
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
 *		@ref S_LCFRCV_VehYawRate_rps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_radps_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Ego Vehicle yaw rate (VDY); \n
 *		TODO:Check signal range and choose the corresponding datatype range \n\n
 *		@ref S_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_TCTEST_CrObsCrosswind_New \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_N_m100000_100000_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: N \n
 *		\@min: -100000 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Estimated Crosswind / Newton \n\n
 *		@ref S_TCTEST_CurSteerAngle_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Current steer angle of the front wheels \n\n
 *		@ref S_TCTEST_MccA11_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccA12_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccA21_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccA22_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccB11_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccB21_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccH11Cw_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_MccH21Cw_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_ReplanCurValues_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFBT_TrajGuiQualifier_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier send by TPLFBT \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_TCTDTE_BnkAglCompActive_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_BnkAglCrvReqGrd_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Gradient Limit of the curvature request needed to compensate the bank angle. \n\n
 *		@ref P_TCTDTE_CroCGainS1_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_CroCGainS2_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_CroWindCompActive_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_CroWindDeltaSetGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_CrvReqBnkAglGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_DelayCyclesDeltaDi_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_5_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Number of cycles the RTE Steer Angle Signal is delayed in the Disturbance Observer \n\n
 *		@ref P_TCTDTE_DelayCyclesLaDMC_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_5_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Number of cycle delays of the LaDMC \n\n
 *		@ref P_TCTDTE_DeltaSetBnkAglGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_DistrbCompActive_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_DmcT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		First Time Constant of the DMC's transfer function (command steering angle -> driven curvature) \n\n
 *		@ref P_TCTDTE_DmcT1comp_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		First Time Constant of the of second order low pass needed for the inversion of the DMC's trasfer function \n\n
 *		@ref P_TCTDTE_DmcT2_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Second Time Constant of the DMC's transfer function (command steering angle -> driven curvature) \n\n
 *		@ref P_TCTDTE_DmcT2comp_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Second Time Constant of the second order low pass needed for the inversion of the DMC's transfer function \n\n
 *		@ref P_TCTDTE_Dss_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_2_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		P_TCTDTE_Dss_nu \n
 *		(Disturbance Source Select) \n
 *		---------------------------------------------------- \n
 *		0 = Off \n
 *		1 = Feedthrough of General Disturbance Compensator \n
 *		2 = Arbitration of BaC and CroC (Default) \n\n
 *		@ref P_TCTDTE_MinimumSpeed_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0p001_20_1em5_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0.001 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTDTE_PT1CrvReqBAC_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant for PT1 filter of curvature signal from bank angle compensation \n\n
 *		@ref P_TCTDTE_TConstSteerAngle_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the PT1 element used to filter the steering angle \n\n
 *		@ref P_VEH_CorStiffFrontAxle_Npr \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Npr_0_500000_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: N/rad \n
 *		\@min: 0 \n
 *		\@max: 500000 \n
 *		\@description: \n
 *		Cornering stiffness coefficient of the tires at the front axle \n\n
 *		@ref P_VEH_CorStiffRearAxle_Npr \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Npr_0_500000_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: N/rad \n
 *		\@min: 0 \n
 *		\@max: 500000 \n
 *		\@description: \n
 *		Cornering stiffness coefficient of the tires at the rear axle \n\n
 *		@ref P_VEH_DistCogToFrontAxle_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Distance between front axle and the vehicle's center of gravity \n\n
 *		@ref P_VEH_DistCogToRearAxle_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Distance between rear axle and the vehicle's center of gravity \n\n
 *		@ref P_VEH_Inertia_kgm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kgm2_1_100000_1em2_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: kgm^2 \n
 *		\@min: 1 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Inertia of the Vehicle \n\n
 *		@ref P_VEH_Mass_kg \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_kg_0_10000_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: kg \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Mass of the vehicle \n\n
 *		@ref P_VEH_SelfSteeringGrd_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Self Steering Gradient of the Vehicle \n\n
 *		@ref X_TCTDTE_InputVehVelSat_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_TCTDTE_KappaAngle_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_250_1em3_t \n
 *		\@size: 1x12x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 250 \n
 *		\@description: \n
 *		Grid points for the x-Axis of the LaDMC Look Up Table "Kappa To Angle" \n\n
 *		@ref X_TCTDTE_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTDTE_CroWindDeltaSetSat_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Absolute value of the saturation of the control signal used to compensate the crosswind / rad in dependence on the velocity \n\n
 *		@ref Y_TCTDTE_DeltaSetBnkAglSat_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTDTE_DeltaSetDstrbGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Gain of the Disturbance Compensator set value \n\n
 *		@ref Y_TCTDTE_DeltaSetDstrbSat_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Saturation of the delta command needed to compensate disturbances \n\n
 *		@ref Y_TCTDTE_GLaDmcDenS0_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Coefficient of the Lateral DMC transfer function's denominator concerning s^0 \n\n
 *		@ref Y_TCTDTE_GLaDmcDenS1_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Coefficient of the Lateral DMC transfer function's denominator concerning s^1 \n\n
 *		@ref Y_TCTDTE_GLaDmcDenS2_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Coefficient of the Lateral DMC transfer function's denominator concerning s^2 \n\n
 *		@ref Y_TCTDTE_GLaDmcDenS3_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Coefficient of the Lateral DMC transfer function's denominator concerning s^3 \n\n
 *		@ref Y_TCTDTE_GLaDmcNumS0_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Coefficient of the Lateral DMC transfer function's numerator concerning s^0 \n\n
 *		@ref Y_TCTDTE_GLaDmcNumS1_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_65535_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Coefficient of the Lateral DMC transfer function's numerator concerning s^1 \n\n
 *		@ref Y_TCTDTE_GainKappaDstrbReq_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Gain of the calculated curvature needed to compensate the disturbances in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTDTE_KappaAngle_degm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degm_0_5000_1em2_t \n
 *		\@size: 1x12x1 \n
 *		\@unit: degm \n
 *		\@min: 0 \n
 *		\@max: 5000 \n
 *		\@description: \n
 *		Grid points of the y-Axis of the LaDMC Look Up Table "Kappa To Angle". \n
 *		Input: Curvature /m \n
 *		Output: Steer Angle /degree \n\n
 *		@ref Y_TCTDTE_VelXToMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		 \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TCTDTE Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TCTDTE_Testcase_Initialization) Initialization of the TCTDTE
 *		-# [Testcase_HoldEnable](@ref TCTDTE_Testcase_HoldEnable) Test Freeze and Enable Conditions (Doors ID: FCT_CMP_TRJCTR_597, FCT_CMP_TRJCTR_598)
 *		-# [Testcase_Reset](@ref TCTDTE_Testcase_Reset) Test of Reset Conditions
 *		-# [Testcase_DTE_Off](@ref TCTDTE_Testcase_DTE_Off) Test of the Activation Logic (Doors ID: FCT_CMP_TRJCTR_615)
 *		-# [Testcase_DTE_On_BankAngleExt](@ref TCTDTE_Testcase_DTE_On_BankAngleExt) Test of the bank angle compensation (Doors ID: FCT_CMP_TRJCTR_601, FCT_CMP_TRJCTR_602)
 *		-# [Testcase_Dss](@ref TCTDTE_Testcase_Dss) Testcase for Disturbance Source Selector (Doors ID: FCT_CMP_TRJCTR_614)
 *		-# [Testcase_Limits](@ref TCTDTE_Testcase_Limits) Testcase for gradient limits and saturation (Doors ID: FCT_CMP_TRJCTR_604, FCT_CMP_TRJCTR_605, FCT_CMP_TRJCTR_608, FCT_CMP_TRJCTR_609, FCT_CMP_TRJCTR_610, FCT_CMP_TRJCTR_611)
 *		-# [Testcase_ModelCoeff](@ref TCTDTE_Testcase_ModelCoeff) Testcase for coverage of Model Coefficients Calculation
 *		
 *	@traceability
 *		[\@link: TCTDTE Module Requirements]()
 */
extern void TCTDTE_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TCTDTE_H_
