/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTEST
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTEST.h
//! @brief     (TCTEST) Module Header.

#ifndef TCTEST_H_
#define TCTEST_H_

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
 *	TCTEST module vehicle initialization function. Function initializes TCTEST vehicle debug data pointer.
 *	
 *	@param
 *		[in] TCTEST_VehDbgArg Pointer to TCTEST vehicle debug data.
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
extern void TCTEST_VehInitDbgPtr(TCTEST_VehDbgType *TCTEST_VehDbgArg);

/*!
 *	TCTEST module vehicle reset function.
 *	
 *	@pre
 *		- The TCTEST vehicle initialization function(s) must be called once.
 *		- The TCTEST vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TCTEST_CrObsCrosswindRaw_New](@ref TCTEST_VehDbgType::D_TCTEST_CrObsCrosswindRaw_New) \n
 *		[Debug  Signal] [D_TCTEST_HdrMean_bool](@ref TCTEST_VehDbgType::D_TCTEST_HdrMean_bool) \n
 *		[Debug  Signal] [D_TCTEST_HdrMean_perc](@ref TCTEST_VehDbgType::D_TCTEST_HdrMean_perc) \n
 *		[Debug  Signal] [D_TCTEST_HdrMul_bool](@ref TCTEST_VehDbgType::D_TCTEST_HdrMul_bool) \n
 *		[Debug  Signal] [D_TCTEST_HdrMul_perc](@ref TCTEST_VehDbgType::D_TCTEST_HdrMul_perc) \n
 *		[Debug  Signal] [D_TCTEST_InPlObsCurvature_1pm](@ref TCTEST_VehDbgType::D_TCTEST_InPlObsCurvature_1pm) \n
 *		[Debug  Signal] [D_TCTEST_InPlObsDeltaY_met](@ref TCTEST_VehDbgType::D_TCTEST_InPlObsDeltaY_met) \n
 *		[Debug  Signal] [D_TCTEST_KObsKappa_1pm](@ref TCTEST_VehDbgType::D_TCTEST_KObsKappa_1pm) \n
 *		[Debug  Signal] [D_TCTEST_PlObsDeltaTheta_rad](@ref TCTEST_VehDbgType::D_TCTEST_PlObsDeltaTheta_rad) \n
 *		[Debug  Signal] [D_TCTEST_PlObsDeltaY_met](@ref TCTEST_VehDbgType::D_TCTEST_PlObsDeltaY_met) \n
 *		[Debug  Signal] [D_TCTEST_SObsBeta_rad](@ref TCTEST_VehDbgType::D_TCTEST_SObsBeta_rad) \n
 *		[Debug  Signal] [D_TCTEST_SObsPsiDot_rps](@ref TCTEST_VehDbgType::D_TCTEST_SObsPsiDot_rps) \n
 *		[Debug  Signal] [D_TCTEST_SteerAngleLaDMC_rad](@ref TCTEST_VehDbgType::D_TCTEST_SteerAngleLaDMC_rad) \n
 *		[Debug  Signal] [D_TCTEST_SteerAngleVDY_rad](@ref TCTEST_VehDbgType::D_TCTEST_SteerAngleVDY_rad) \n
 *		[Debug  Signal] [S_TCTEST_CrObsCrosswind_New](@ref TCTEST_VehDbgType::S_TCTEST_CrObsCrosswind_New) \n
 *		[Debug  Signal] [S_TCTEST_CurSteerAngle_rad](@ref TCTEST_VehDbgType::S_TCTEST_CurSteerAngle_rad) \n
 *		[Debug  Signal] [S_TCTEST_KObsKappa_1pm](@ref TCTEST_VehDbgType::S_TCTEST_KObsKappa_1pm) \n
 *		[Debug  Signal] [S_TCTEST_MccA11_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA11_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccA12_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA12_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccA21_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA21_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccA22_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA22_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccB11_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccB11_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccB21_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccB21_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccH11Cw_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccH11Cw_nu) \n
 *		[Debug  Signal] [S_TCTEST_MccH21Cw_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccH21Cw_nu) \n
 *		[Debug  Signal] [S_TCTEST_PlObsDeltaTheta_rad](@ref TCTEST_VehDbgType::S_TCTEST_PlObsDeltaTheta_rad) \n
 *		[Debug  Signal] [S_TCTEST_PlObsDeltaY_met](@ref TCTEST_VehDbgType::S_TCTEST_PlObsDeltaY_met) \n
 *		[Debug  Signal] [S_TCTEST_QualifierService_nu](@ref TCTEST_VehDbgType::S_TCTEST_QualifierService_nu) \n
 *		[Debug  Signal] [S_TCTEST_SObsBeta_rad](@ref TCTEST_VehDbgType::S_TCTEST_SObsBeta_rad) \n\n
 *		For signal details, see sub-section [Globals](@ref TCTEST_VehProcess_Globals) of the function @ref TCTEST_VehProcess.
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
extern void TCTEST_VehReset(void);

/*!
 *	TCTEST module vehicle process function.
 *	
 *	@pre
 *		- The TCTEST vehicle initialization function(s) must be called once.
 *		- The TCTEST vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TCTEST_VehProcess_Globals
 *		[D_TCTEST_CrObsCrosswindRaw_New](@ref TCTEST_VehDbgType::D_TCTEST_CrObsCrosswindRaw_New) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_N_m100000_100000_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: N \n
 *		\@min: -100000 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_HdrMean_bool](@ref TCTEST_VehDbgType::D_TCTEST_HdrMean_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_HdrMean_perc](@ref TCTEST_VehDbgType::D_TCTEST_HdrMean_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_HdrMul_bool](@ref TCTEST_VehDbgType::D_TCTEST_HdrMul_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_HdrMul_perc](@ref TCTEST_VehDbgType::D_TCTEST_HdrMul_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_InPlObsCurvature_1pm](@ref TCTEST_VehDbgType::D_TCTEST_InPlObsCurvature_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_InPlObsDeltaY_met](@ref TCTEST_VehDbgType::D_TCTEST_InPlObsDeltaY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_KObsKappa_1pm](@ref TCTEST_VehDbgType::D_TCTEST_KObsKappa_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Estimated curvature, debug signal in front of the enable / freeze blocks \n\n
 *		[D_TCTEST_PlObsDeltaTheta_rad](@ref TCTEST_VehDbgType::D_TCTEST_PlObsDeltaTheta_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_PlObsDeltaY_met](@ref TCTEST_VehDbgType::D_TCTEST_PlObsDeltaY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_SObsBeta_rad](@ref TCTEST_VehDbgType::D_TCTEST_SObsBeta_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Estimated Side Slip Angle of Side Slip Angle observer without saturations \n\n
 *		[D_TCTEST_SObsPsiDot_rps](@ref TCTEST_VehDbgType::D_TCTEST_SObsPsiDot_rps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_radps_m1p5708_1p5708_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: -1.5708 \n
 *		\@max: 1.5708 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_SteerAngleLaDMC_rad](@ref TCTEST_VehDbgType::D_TCTEST_SteerAngleLaDMC_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTEST_SteerAngleVDY_rad](@ref TCTEST_VehDbgType::D_TCTEST_SteerAngleVDY_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_CrObsCrosswind_New](@ref TCTEST_VehDbgType::S_TCTEST_CrObsCrosswind_New) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_N_m100000_100000_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: N \n
 *		\@min: -100000 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Estimated Crosswind / Newton \n\n
 *		[S_TCTEST_CurSteerAngle_rad](@ref TCTEST_VehDbgType::S_TCTEST_CurSteerAngle_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Current steer angle of the front wheels \n\n
 *		[S_TCTEST_KObsKappa_1pm](@ref TCTEST_VehDbgType::S_TCTEST_KObsKappa_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Estimated Curvature \n\n
 *		[S_TCTEST_MccA11_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA11_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccA12_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA12_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccA21_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA21_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccA22_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccA22_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccB11_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccB11_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccB21_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccB21_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccH11Cw_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccH11Cw_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_MccH21Cw_nu](@ref TCTEST_VehDbgType::S_TCTEST_MccH21Cw_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_PlObsDeltaTheta_rad](@ref TCTEST_VehDbgType::S_TCTEST_PlObsDeltaTheta_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Estimated DeltaTheta of PlantObserver \n\n
 *		[S_TCTEST_PlObsDeltaY_met](@ref TCTEST_VehDbgType::S_TCTEST_PlObsDeltaY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Estimated DeltaY of PlantObserver \n\n
 *		[S_TCTEST_QualifierService_nu](@ref TCTEST_VehDbgType::S_TCTEST_QualifierService_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u32_NoUnit_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTEST_SObsBeta_rad](@ref TCTEST_VehDbgType::S_TCTEST_SObsBeta_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Estimated Side Slip Angle of SideSlip Angle Observer \n\n
 *		@ref S_LCFRCV_OffCompStWheelAngle_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		Offset compensated steering wheel angle / rad \n\n
 *		@ref S_LCFRCV_SteerAngleLatDMC_deg \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_deg_m50_50_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -50 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Offset compensated steer angle at the front wheels provided by the LatDMC \n\n
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
 *		@ref S_TCTFFC_Crv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Curvature control signal part of the feedforward controller \n\n
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TPLCEN_ReplanCurValues_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFBT_CurDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFBT_TrajDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
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
 *		@ref S_TPLFBT_TrajTgtCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_TCTEST_DelayCyclesDeltaSs_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_5_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Number of cycles the RTE Steer Angle Signal is delayed in the Side Slip Angle Observer \n\n
 *		@ref P_TCTEST_HdrDThetaDotEnd_rps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1p5_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1.5 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrDThetaDotPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrDThetaDotStart_rps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1p5_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1.5 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrDYDotEnd_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrDYDotPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrDYDotStart_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrMeanDThetaWghtOf_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrMeanDThetaWghtSf_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrMeanDThetaWght_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrMeanDYWghtOf_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrMeanDYWghtSf_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_HdrMeanDYWght_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_IssPlObsCurvature_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_1_4_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_MinimumSpeed_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0p001_20_1em5_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0.001 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_PT1CrObsCrosswind_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the PT1 used to filter the estimated crosswind \n\n
 *		@ref P_TCTEST_PT1PlObsInCurvature_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_SObsActive_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTEST_UseSteerAngleLatDMC_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		0: Use Steer Angle signal provided by VDY \n
 *		1: Use Steer Angle signal provided by LatDMC \n\n
 *		@ref P_VEH_CenterOfPressure_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Distance between the center of gravity and the center of pressure \n\n
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
 *		@ref X_TCTEST_InputVehVelSat_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		- \n\n
 *		@ref X_TCTEST_StwGearRatio_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_12_1em4_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 12 \n
 *		\@description: \n
 *		Grid Points for the LookUp table for the steering ratio comprising steering wheel angles between 0rad and 12rad. Assumption: Symmetric Steering. \n\n
 *		@ref X_TCTEST_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		- \n\n
 *		@ref Y_TCTEST_CrObsLueGain11_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		First element of first column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
 *		@ref Y_TCTEST_CrObsLueGain12_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		First element of second column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
 *		@ref Y_TCTEST_CrObsLueGain21_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Second element of first column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
 *		@ref Y_TCTEST_CrObsLueGain22_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Second element of second column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
 *		@ref Y_TCTEST_CrObsLueGain31_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Third element of first column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
 *		@ref Y_TCTEST_CrObsLueGain32_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Third element of second column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
 *		@ref Y_TCTEST_HdrMeanThreshOf_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_HdrMeanThreshSf_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_HdrMeanThresh_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_HdrMulThreshOf_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_HdrMulThreshSf_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_HdrMulThresh_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_KObsLueGain11_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		First element of first column of gain matrix of the Luenberger observer to estimate the curvature \n\n
 *		@ref Y_TCTEST_KObsLueGain21_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Second element of first column of gain matrix of the Luenberger observer to estimate the curvature \n\n
 *		@ref Y_TCTEST_KObsLueGain31_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Third element of first column of gain matrix of the Luenberger observer to estimate the curvature \n\n
 *		@ref Y_TCTEST_PlObsDeltaThetaSat_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_3p14_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 3.14 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_PlObsDeltaYSat_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_PlObsLueGain11_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		First element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain12_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		First element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain13_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		First element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain21_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Second element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain22_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Second element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain23_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Second element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain31_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Third element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain32_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Third element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain33_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Third element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain41_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Fourth element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain42_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Fourth element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PlObsLueGain43_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Fourth element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
 *		@ref Y_TCTEST_PreviewDistX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_SObsBetaSat_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_3p14_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 3.14 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTEST_SObsLueGain1_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		First element of the Gain-Vector of the Luenberger Observer used to estimate the Side Slip Angle. \n\n
 *		@ref Y_TCTEST_SObsLueGain2_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Second element of the Gain-Vector of the Luenberger Observer used to estimate the Side Slip Angle. \n\n
 *		@ref Y_TCTEST_StwGearRatio_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Gear Ratio of the vehicle, corresponding grid points are located in X_TCTDTE_StwGearRatio_rad. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TCTEST Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TCTEST_Testcase_Initialization) Initialization of the TCTEST
 *		-# [Testcase_Saturation](@ref TCTEST_Testcase_Saturation) Test Saturation of DeltaY, DeltaTheta and Beta (Doors ID FCT_CMP_TRJCTR_621, FCT_CMP_TRJCTR_623, FCT_CMP_TRJCTR_624)
 *		-# [Testcase_FreezeEnable](@ref TCTEST_Testcase_FreezeEnable) Testcase for Hold and Enable Conditions (Doors ID FCT_CMP_TRJCTR_618, FCT_CMP_TRJCTR_619)
 *		-# [Testcase_ModelCoeff](@ref TCTEST_Testcase_ModelCoeff) Testcase for coverage of Model Coefficients Calculation
 *		-# [TestcaseForCoverage](@ref TCTEST_TestcaseForCoverage) Increase coverage by reaching all possible branches
 *		
 *	@traceability
 *		[\@link: TCTEST Module Requirements]()
 */
extern void TCTEST_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TCTEST_H_
