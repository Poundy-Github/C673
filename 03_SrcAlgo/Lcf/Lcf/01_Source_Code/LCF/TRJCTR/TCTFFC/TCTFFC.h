/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTFFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTFFC.h
//! @brief     (TCTFFC) Module Header.

#ifndef TCTFFC_H_
#define TCTFFC_H_

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
 *	TCTFFC module vehicle initialization function. Function initializes TCTFFC vehicle debug data pointer.
 *	
 *	@param
 *		[in] TCTFFC_VehDbgArg Pointer to TCTFFC vehicle debug data.
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
extern void TCTFFC_VehInitDbgPtr(TCTFFC_VehDbgType *TCTFFC_VehDbgArg);

/*!
 *	TCTFFC module vehicle reset function.
 *	
 *	@pre
 *		- The TCTFFC vehicle initialization function(s) must be called once.
 *		- The TCTFFC vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TCTFFC_DiffMeasEstKappa_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DiffMeasEstKappa_1pm) \n
 *		[Debug  Signal] [D_TCTFFC_DynFfcDecel_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfcDecel_1pm) \n
 *		[Debug  Signal] [D_TCTFFC_DynFfcGeneral_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfcGeneral_1pm) \n
 *		[Debug  Signal] [D_TCTFFC_DynFfcUpDwnHill_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfcUpDwnHill_1pm) \n
 *		[Debug  Signal] [D_TCTFFC_DynFfc_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfc_1pm) \n
 *		[Debug  Signal] [D_TCTFFC_DynGainPrecFulfilled_nu](@ref TCTFFC_VehDbgType::D_TCTFFC_DynGainPrecFulfilled_nu) \n
 *		[Debug  Signal] [D_TCTFFC_TrajTgtCrvFilt_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_TrajTgtCrvFilt_1pm) \n
 *		[Debug  Signal] [S_TCTFFC_Crv_1pm](@ref TCTFFC_VehDbgType::S_TCTFFC_Crv_1pm) \n\n
 *		For signal details, see sub-section [Globals](@ref TCTFFC_VehProcess_Globals) of the function @ref TCTFFC_VehProcess.
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
extern void TCTFFC_VehReset(void);

/*!
 *	TCTFFC module vehicle process function.
 *	
 *	@pre
 *		- The TCTFFC vehicle initialization function(s) must be called once.
 *		- The TCTFFC vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TCTFFC_VehProcess_Globals
 *		[D_TCTFFC_DiffMeasEstKappa_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DiffMeasEstKappa_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTFFC_DynFfcDecel_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfcDecel_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTFFC_DynFfcGeneral_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfcGeneral_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTFFC_DynFfcUpDwnHill_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfcUpDwnHill_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTFFC_DynFfc_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_DynFfc_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTFFC_DynGainPrecFulfilled_nu](@ref TCTFFC_VehDbgType::D_TCTFFC_DynGainPrecFulfilled_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTFFC_TrajTgtCrvFilt_1pm](@ref TCTFFC_VehDbgType::D_TCTFFC_TrajTgtCrvFilt_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTFFC_Crv_1pm](@ref TCTFFC_VehDbgType::S_TCTFFC_Crv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Curvature control signal part of the feedforward controller \n\n
 *		@ref D_TPLFBT_UseTargetCorridor_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_ABPLBP_UpDownHillDtct_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Indicates downhill / uphill scenario detection confidence \n\n
 *		@ref S_LCFRCV_EPS_ManualTrqActualVal_Nm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Rename of S_RTE_EPS_ManualTrqActualVal_Nm \n\n
 *		@ref S_LCFRCV_SysCycleTimeVeh_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p03_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.03 \n
 *		\@description: \n
 *		Cycle Time for VEH task \n\n
 *		@ref S_LCFRCV_VehAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Vehicle longitudinal acceleration \n\n
 *		@ref S_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_TCTCDC_CtrlErrDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTCLM_DeltaFCmd_deg \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_KObsKappa_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Estimated Curvature \n\n
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
 *		@ref P_TCTFFC_DecelAclXGrdLD_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DecelAclXGrdLU_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DecelHystLSP_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DecelModeHyst_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DecelReduction_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DecelThrsAxEnd_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DecelThrsAxStart_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainFadingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainMaxAdaption_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainMode_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainPreThrDY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainPreThrDriver_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainPrecCtrlFcn_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainPrecCtrlMode_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainPrecSelect_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_DynGainPrecThrKappa_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_OssDynGain_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_OssFfcCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_2_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_PT1TgtCrvFiltTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_UpDwnHllReduction_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_UpDwnHllThres_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTFFC_UseAltOBFApproach_nu \n
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
 *		[\@link: TCTFFC Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TCTFFC_Testcase_Initialization) Initialization of the TCTFFC
 *		-# [Testcase_CrvInterface](@ref TCTFFC_Testcase_CrvInterface) Curvature Interface (Doors ID FCT_CMP_TRJCTR_547)
 *		-# [Testcase_Qualifier](@ref TCTFFC_Testcase_Qualifier) Test of Freeze and Request Off (Doors ID FCT_CMP_TRJCTR_548)
 *		-# [Testcase_Preconditions](@ref TCTFFC_Testcase_Preconditions) Test of all Preconditions for Dynamic Feedforward Gain (Doors ID FCT_CMP_TRJCTR_580)
 *		-# [Testcase_CalcDynFFGain](@ref TCTFFC_Testcase_CalcDynFFGain) Calculation of the dynamic feedforward gain (Doors ID FCT_CMP_TRJCTR_581, FCT_CMP_TRJCTR_582)
 *		-# [Testcase_CalcUpDwnHill](@ref TCTFFC_Testcase_CalcUpDwnHill) Calculation of the up/downhill case (Doors ID FCT_CMP_TRJCTR_583)
 *		-# [Testcase_CalcDecel](@ref TCTFFC_Testcase_CalcDecel) Calculation of the deceleration case (Doors ID FCT_CMP_TRJCTR_588)
 *		-# [Testcase_DynGainSelection](@ref TCTFFC_Testcase_DynGainSelection) Test of selection logic for the different dynamic gain methods (Doors ID FCT_CMP_TRJCTR_585)
 *		
 *	@traceability
 *		[\@link: TCTFFC Module Requirements]()
 */
extern void TCTFFC_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TCTFFC_H_
