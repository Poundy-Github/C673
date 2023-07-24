/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMHOD
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMHOD.h
//! @brief     (DRMHOD) Module Header.

#ifndef DRMHOD_H_
#define DRMHOD_H_

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
 *	DRMHOD module vehicle initialization function. Function initializes DRMHOD vehicle debug data pointer.
 *	
 *	@param
 *		[in] DRMHOD_VehDbgArg Pointer to DRMHOD vehicle debug data.
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
extern void DRMHOD_VehInitDbgPtr(DRMHOD_VehDbgType *DRMHOD_VehDbgArg);

/*!
 *	DRMHOD module vehicle initialization function. Function initializes DRMHOD vehicle output data pointer.
 *	
 *	@param
 *		[in] DRMHOD_VehOutArg Pointer to DRMHOD vehicle output data.
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
extern void DRMHOD_VehInitOutPtr(DRMHOD_VehOutType *DRMHOD_VehOutArg);

/*!
 *	DRMHOD module vehicle reset function.
 *	
 *	@pre
 *		- The DRMHOD vehicle initialization function(s) must be called once.
 *		- The DRMHOD vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DRMHOD_EstHandTor_Nm](@ref DRMHOD_VehDbgType::D_DRMHOD_EstHandTor_Nm) \n
 *		[Debug  Signal] [S_DRMHOD_HandsOffConfirmed_bool](@ref DRMHOD_VehDbgType::S_DRMHOD_HandsOffConfirmed_bool) \n
 *		[Output Signal] [D_DRMHOD_CorrectedTorque_Nm](@ref DRMHOD_VehOutType::D_DRMHOD_CorrectedTorque_Nm) \n
 *		[Output Signal] [D_DRMHOD_EstHandTorCounter_nu](@ref DRMHOD_VehOutType::D_DRMHOD_EstHandTorCounter_nu) \n
 *		[Output Signal] [D_DRMHOD_EstHandTorState_nu](@ref DRMHOD_VehOutType::D_DRMHOD_EstHandTorState_nu) \n
 *		[Output Signal] [D_DRMHOD_HdOffDtctStatus_nu](@ref DRMHOD_VehOutType::D_DRMHOD_HdOffDtctStatus_nu) \n
 *		[Output Signal] [D_DRMHOD_LowPassC](@ref DRMHOD_VehOutType::D_DRMHOD_LowPassC) \n\n
 *		For signal details, see sub-section [Globals](@ref DRMHOD_VehProcess_Globals) of the function @ref DRMHOD_VehProcess.
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
extern void DRMHOD_VehReset(void);

/*!
 *	DRMHOD module vehicle process function.
 *	
 *	@pre
 *		- The DRMHOD vehicle initialization function(s) must be called once.
 *		- The DRMHOD vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor DRMHOD_VehProcess_Globals
 *		[D_DRMHOD_EstHandTor_Nm](@ref DRMHOD_VehDbgType::D_DRMHOD_EstHandTor_Nm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Estimated torque produced by driver hand. \n\n
 *		[S_DRMHOD_HandsOffConfirmed_bool](@ref DRMHOD_VehDbgType::S_DRMHOD_HandsOffConfirmed_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_DRMHOD_CorrectedTorque_Nm](@ref DRMHOD_VehOutType::D_DRMHOD_CorrectedTorque_Nm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_DRMHOD_EstHandTorCounter_nu](@ref DRMHOD_VehOutType::D_DRMHOD_EstHandTorCounter_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_DRMHOD_EstHandTorState_nu](@ref DRMHOD_VehOutType::D_DRMHOD_EstHandTorState_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_DRMHOD_IntStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Internal state of hands off detection module \n\n
 *		[D_DRMHOD_HdOffDtctStatus_nu](@ref DRMHOD_VehOutType::D_DRMHOD_HdOffDtctStatus_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Debug signal \n\n
 *		[D_DRMHOD_LowPassC](@ref DRMHOD_VehOutType::D_DRMHOD_LowPassC) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_EPS_ManualTrqActualVal_Nm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Rename of S_RTE_EPS_ManualTrqActualVal_Nm \n\n
 *		@ref S_LCFRCV_HandsOffConfirmedExt_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_boolean_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_SteerWAngleRate_degps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Steering Wheel Angle Rate from CAN Bus \n\n
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
 *		@ref P_DRMHOD_AngleSensAvailable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1 - Use Angle variant \n
 *		0 - Use torque bsaed algorithm \n\n
 *		@ref P_DRMHOD_BasicDebounceOnly_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_DebugMode_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref E_DRMHOD_DebugModeType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Debug mode for DRMHOD \n\n
 *		@ref P_DRMHOD_EstHandTqOffsetN_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Negative Torque Offset \n\n
 *		@ref P_DRMHOD_EstHandTqOffsetP_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Positive Torque Offset \n\n
 *		@ref P_DRMHOD_ExternalSensorUsed_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HandsOffLimit_gen \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HandsOffQlfMaxTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_600_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 600 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HandsOffQlfTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_600_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 600 \n
 *		\@description: \n
 *		Qualification Time \n\n
 *		@ref P_DRMHOD_HandsOnLimit_gen \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HandsOnQlfTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_600_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 600 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HandsOnTorLimAbs_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HdOffDltProlTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_600_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 600 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HdOffSensedTqDelta_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DRMHOD_HdOffTqStepLim_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_DRMHOD_VelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x16x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_LCF_VelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DRMHOD_HandsOffTqLim_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x16x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref Y_DRMHOD_HandsOnTqLim_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x16x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref Y_DRMHOD_VXLowPassC_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DRMHOD Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		
 *	@traceability
 *		[\@link: DRMHOD Module Requirements]()
 */
extern void DRMHOD_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DRMHOD_H_
