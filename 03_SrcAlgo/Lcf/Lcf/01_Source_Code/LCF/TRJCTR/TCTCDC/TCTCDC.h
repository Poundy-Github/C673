/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCDC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTCDC.h
//! @brief     (TCTCDC) Module Header.

#ifndef TCTCDC_H_
#define TCTCDC_H_

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
 *	TCTCDC module vehicle initialization function. Function initializes TCTCDC vehicle debug data pointer.
 *	
 *	@param
 *		[in] TCTCDC_VehDbgArg Pointer to TCTCDC vehicle debug data.
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
extern void TCTCDC_VehInitDbgPtr(TCTCDC_VehDbgType *TCTCDC_VehDbgArg);

/*!
 *	TCTCDC module vehicle reset function.
 *	
 *	@pre
 *		- The TCTCDC vehicle initialization function(s) must be called once.
 *		- The TCTCDC vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TCTCDC_DeltaThetaEsti_rad](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaThetaEsti_rad) \n
 *		[Debug  Signal] [D_TCTCDC_DeltaThetaPT1_rad](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaThetaPT1_rad) \n
 *		[Debug  Signal] [D_TCTCDC_DeltaThetaRaw_rad](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaThetaRaw_rad) \n
 *		[Debug  Signal] [D_TCTCDC_DeltaYPT1_met](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaYPT1_met) \n
 *		[Debug  Signal] [D_TCTCDC_DeltaYRaw_met](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaYRaw_met) \n
 *		[Debug  Signal] [D_TCTCDC_QualifierService_nu](@ref TCTCDC_VehDbgType::D_TCTCDC_QualifierService_nu) \n
 *		[Debug  Signal] [D_TCTCDC_WatchdogStatus_nu](@ref TCTCDC_VehDbgType::D_TCTCDC_WatchdogStatus_nu) \n
 *		[Debug  Signal] [S_TCTCDC_CtrlErrDistY_met](@ref TCTCDC_VehDbgType::S_TCTCDC_CtrlErrDistY_met) \n
 *		[Debug  Signal] [S_TCTCDC_CtrlErrHeadAglPrev_rad](@ref TCTCDC_VehDbgType::S_TCTCDC_CtrlErrHeadAglPrev_rad) \n
 *		[Debug  Signal] [S_TCTCDC_CtrlErrHeadAgl_rad](@ref TCTCDC_VehDbgType::S_TCTCDC_CtrlErrHeadAgl_rad) \n
 *		[Debug  Signal] [S_TCTCDC_QualifierService_nu](@ref TCTCDC_VehDbgType::S_TCTCDC_QualifierService_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TCTCDC_VehProcess_Globals) of the function @ref TCTCDC_VehProcess.
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
extern void TCTCDC_VehReset(void);

/*!
 *	TCTCDC module vehicle process function.
 *	
 *	@pre
 *		- The TCTCDC vehicle initialization function(s) must be called once.
 *		- The TCTCDC vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TCTCDC_VehProcess_Globals
 *		[D_TCTCDC_DeltaThetaEsti_rad](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaThetaEsti_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Course Angle Deviation calculated by means of "HAF estimator" \n\n
 *		[D_TCTCDC_DeltaThetaPT1_rad](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaThetaPT1_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		PT1 filtered Course Angle Deviation \n\n
 *		[D_TCTCDC_DeltaThetaRaw_rad](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaThetaRaw_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Course Angle Deviation \n\n
 *		[D_TCTCDC_DeltaYPT1_met](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaYPT1_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral Deviation, PT1 filtered \n\n
 *		[D_TCTCDC_DeltaYRaw_met](@ref TCTCDC_VehDbgType::D_TCTCDC_DeltaYRaw_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral Deviation \n\n
 *		[D_TCTCDC_QualifierService_nu](@ref TCTCDC_VehDbgType::D_TCTCDC_QualifierService_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCDC_WatchdogStatus_nu](@ref TCTCDC_VehDbgType::D_TCTCDC_WatchdogStatus_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		0: Watchdog inactive \n
 *		1: Watchdog active \n\n
 *		[S_TCTCDC_CtrlErrDistY_met](@ref TCTCDC_VehDbgType::S_TCTCDC_CtrlErrDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTCDC_CtrlErrHeadAglPrev_rad](@ref TCTCDC_VehDbgType::S_TCTCDC_CtrlErrHeadAglPrev_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		 \n\n
 *		[S_TCTCDC_CtrlErrHeadAgl_rad](@ref TCTCDC_VehDbgType::S_TCTCDC_CtrlErrHeadAgl_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		 \n\n
 *		[S_TCTCDC_QualifierService_nu](@ref TCTCDC_VehDbgType::S_TCTCDC_QualifierService_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Qualifier signal of TCTCDC: \n
 *		xxxx xxx1: Too high deviation in the control error regarding the Y-Coordinate \n
 *		xxxx xx1x: Too high deviation in the control error regarding the Course Angle \n
 *		xxxx x1xx: Too high deviation in the control error regarding the Course Angle with Preview \n\n
 *		@ref S_CSCLTA_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
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
 *		@ref S_TCTEST_PlObsDeltaTheta_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Estimated DeltaTheta of PlantObserver \n\n
 *		@ref S_TCTEST_PlObsDeltaY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Estimated DeltaY of PlantObserver \n\n
 *		@ref S_TCTEST_SObsBeta_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Estimated Side Slip Angle of SideSlip Angle Observer \n\n
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
 *		@ref S_TPLFBT_CurHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
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
 *		@ref S_TPLFBT_TrajHeadInclPrev_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		 \n\n
 *		@ref S_TPLFBT_TrajTgtCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_DelayCycleNum_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_7_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Cylce numer for the delay in the heading angle signal \n\n
 *		@ref P_TCTCDC_KMCDeltaPsiAttenu_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_KMCDeltaPsiObsGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_OssDeltaTheta_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_1_4_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Output Source Selection of DeltaTheta \n
 *		------------------------------------------ \n
 *		1: Raw unfiltered \n
 *		2: PT1 Filter \n
 *		3: Plant Observer \n
 *		4: Old Course Angle Observer \n\n
 *		@ref P_TCTCDC_OssDeltaY_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_1_3_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Output Source Selection of DeltaY \n
 *		------------------------------------------ \n
 *		1: Raw unfiltered \n
 *		2: PT1 Filter \n
 *		3: Plant Observer \n\n
 *		@ref P_TCTCDC_PT1CurDistYTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_PT1CurHeadingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p04_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.04 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_UseAltOBFApproach_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_UseTrajCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTCDC_WtchdgActive_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Watchdog is activated \n
 *		0: Watchdog is deactivated \n\n
 *		@ref P_TCTCDC_WtchdgLimCoAnErr_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_3p14_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 3.14 \n
 *		\@description: \n
 *		Absolute value of the threshold used to classify the Course Angle Error as too high \n\n
 *		@ref P_TCTCDC_WtchdgLimYErr_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Absolute value of the threshold used to classify the Y-Coordinate Error as too high \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TCTCDC Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TCTCDC_Testcase_Initialization) Initialization of the TCTCDC
 *		-# [Testcase_ErrorsWithoutFilter](@ref TCTCDC_Testcase_ErrorsWithoutFilter) Control Errors (Doors ID FCT_CMP_TRJCTR_485, FCT_CMP_TRJCTR_486)
 *		-# [Testcase_WatchdogDeActivation](@ref TCTCDC_Testcase_WatchdogDeActivation) DeActivation of Watchdog (Doors ID FCT_CMP_TRJCTR_480)
 *		-# [Testcase_QualifierService](@ref TCTCDC_Testcase_QualifierService) S_TCTCDC_QualifierService_nu (Doors ID FCT_CMP_TRJCTR_481, FCT_CMP_TRJCTR_482)
 *		-# [Testcase_Reset](@ref TCTCDC_Testcase_Reset) Test Enable, Reset and Freeze (Doors ID  FCT_CMP_TRJCTR_576, FCT_CMP_TRJCTR_577)
 *		-# [Testcase_DeltaPsiEstimation](@ref TCTCDC_Testcase_DeltaPsiEstimation) D_TCTCDC_DeltaThetaEsti_rad
 *		-# [Testcase_TCTESTErrors](@ref TCTCDC_Testcase_TCTESTErrors) Errors from TCTEST DOORS ID FCT_CMP_TRJCTR_485, FCT_CMP_TRJCTR_486
 *		-# [Testcase_ErrorsWithFilter](@ref TCTCDC_Testcase_ErrorsWithFilter) Errors with Filter DOORS ID FCT_CMP_TRJCTR_485, FCT_CMP_TRJCTR_486
 *		-# [Testcase_OBFOverride](@ref TCTCDC_Testcase_OBFOverride) Test logic for new object following approach
 *		
 *	@traceability
 *		[\@link: TCTCDC Module Requirements]()
 */
extern void TCTCDC_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TCTCDC_H_
