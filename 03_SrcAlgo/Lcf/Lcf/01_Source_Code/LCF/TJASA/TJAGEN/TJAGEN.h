/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAGEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJAGEN.h
//! @brief     (TJAGEN) Module Header.

#ifndef TJAGEN_H_
#define TJAGEN_H_

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
 *	TJAGEN module sensor initialization function. Function initializes TJAGEN sensor debug data pointer.
 *	
 *	@param
 *		[in] TJAGEN_SenDbgArg Pointer to TJAGEN sensor debug data.
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
extern void TJAGEN_SenInitDbgPtr(TJAGEN_SenDbgType *TJAGEN_SenDbgArg);

/*!
 *	TJAGEN module sensor initialization function. Function initializes TJAGEN sensor output data pointer.
 *	
 *	@param
 *		[in] TJAGEN_SenOutArg Pointer to TJAGEN sensor output data.
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
extern void TJAGEN_SenInitOutPtr(TJAGEN_SenOutType *TJAGEN_SenOutArg);

/*!
 *	TJAGEN module sensor reset function.
 *	
 *	@pre
 *		- The TJAGEN sensor initialization function(s) must be called once.
 *		- The TJAGEN sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TJAGEN_CancelStatus_btf](@ref TJAGEN_SenDbgType::D_TJAGEN_CancelStatus_btf) \n
 *		[Debug  Signal] [D_TJAGEN_StrongReadyInvalid_btf](@ref TJAGEN_SenDbgType::D_TJAGEN_StrongReadyInvalid_btf) \n
 *		[Debug  Signal] [D_TJAGEN_WeakReadyInvalid_btf](@ref TJAGEN_SenDbgType::D_TJAGEN_WeakReadyInvalid_btf) \n
 *		[Debug  Signal] [S_TJAGEN_Abort_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_Abort_bool) \n
 *		[Debug  Signal] [S_TJAGEN_LKAOnlySwitch_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_LKAOnlySwitch_bool) \n
 *		[Debug  Signal] [S_TJAGEN_StrongReady_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_StrongReady_bool) \n
 *		[Debug  Signal] [S_TJAGEN_WeakReady_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_WeakReady_bool) \n
 *		[Output Signal] [S_TJAGEN_Cancel_nu](@ref TJAGEN_SenOutType::S_TJAGEN_Cancel_nu) \n
 *		[Output Signal] [S_TJAGEN_Clearance_bool](@ref TJAGEN_SenOutType::S_TJAGEN_Clearance_bool) \n
 *		[Output Signal] [S_TJAGEN_CodeFunction_bool](@ref TJAGEN_SenOutType::S_TJAGEN_CodeFunction_bool) \n
 *		[Output Signal] [S_TJAGEN_Degradation_bool](@ref TJAGEN_SenOutType::S_TJAGEN_Degradation_bool) \n
 *		[Output Signal] [S_TJAGEN_Error_bool](@ref TJAGEN_SenOutType::S_TJAGEN_Error_bool) \n
 *		[Output Signal] [S_TJAGEN_FunctionSwitch_bool](@ref TJAGEN_SenOutType::S_TJAGEN_FunctionSwitch_bool) \n\n
 *		For signal details, see sub-section [Globals](@ref TJAGEN_SenProcess_Globals) of the function @ref TJAGEN_SenProcess.
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
extern void TJAGEN_SenReset(void);

/*!
 *	TJAGEN module sensor process function.
 *	
 *	@pre
 *		- The TJAGEN sensor initialization function(s) must be called once.
 *		- The TJAGEN sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJAGEN_SenProcess_Globals
 *		[D_TJAGEN_CancelStatus_btf](@ref TJAGEN_SenDbgType::D_TJAGEN_CancelStatus_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		DEBUG: bit field signal for cancel conditions \n\n
 *		[D_TJAGEN_StrongReadyInvalid_btf](@ref TJAGEN_SenDbgType::D_TJAGEN_StrongReadyInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		DEBUG: bit field signal for strong ready conditions \n\n
 *		[D_TJAGEN_WeakReadyInvalid_btf](@ref TJAGEN_SenDbgType::D_TJAGEN_WeakReadyInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		DEBUG: bit field signal for weak ready conditions \n\n
 *		[S_TJAGEN_Abort_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_Abort_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA shall be aborted (no rampout) \n\n
 *		[S_TJAGEN_LKAOnlySwitch_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_LKAOnlySwitch_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable LKA only \n\n
 *		[S_TJAGEN_StrongReady_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_StrongReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA strong ready conditions are fulfilled \n\n
 *		[S_TJAGEN_WeakReady_bool](@ref TJAGEN_SenDbgType::S_TJAGEN_WeakReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA weak ready conditions are fulfilled \n\n
 *		[S_TJAGEN_Cancel_nu](@ref TJAGEN_SenOutType::S_TJAGEN_Cancel_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA cancel conditions are fulfilled \n\n
 *		[S_TJAGEN_Clearance_bool](@ref TJAGEN_SenOutType::S_TJAGEN_Clearance_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA received clearance from mode control \n\n
 *		[S_TJAGEN_CodeFunction_bool](@ref TJAGEN_SenOutType::S_TJAGEN_CodeFunction_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA is coded. \n\n
 *		[S_TJAGEN_Degradation_bool](@ref TJAGEN_SenOutType::S_TJAGEN_Degradation_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if rampout is completed \n\n
 *		[S_TJAGEN_Error_bool](@ref TJAGEN_SenOutType::S_TJAGEN_Error_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA error conditions are fulfilled \n\n
 *		[S_TJAGEN_FunctionSwitch_bool](@ref TJAGEN_SenOutType::S_TJAGEN_FunctionSwitch_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA is switched on \n\n
 *		@ref S_CUSTOM_PrjSpecQu_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield containing all the relevant information of the customer projects. \n\n
 *		@ref S_LCFRCV_ErrorStateLKA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if any LKA relevant input signal is corrupted \n\n
 *		@ref S_LCFRCV_ErrorStateTJA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if any TJA relevant input signal is corrupted \n\n
 *		@ref S_LCFRCV_LKASwitch_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if LKA is manually switched on by the driver \n\n
 *		@ref S_LCFRCV_SteerWAngle_deg \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Steering Wheel Angle from CAN Bus \n\n
 *		@ref S_LCFRCV_SysCycleTimeSen_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Cycle time for LCF_SEN components (60ms): \n
 *		minimum possible cycle time:1ms \n
 *		maximum possible cycle time:100ms \n\n
 *		@ref S_LCFRCV_SysStOnLatDMC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if DMC_LAT_STATUS = 1, 2 or 3 (LCF_LADMC_ON) \n\n
 *		@ref S_LCFRCV_TJASwitch_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TJA is manually switched on by the driver \n\n
 *		@ref S_LCFRCV_VDy_VehVelocity_kph \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Tachometer Vehicle Speed in kilometers/hour \n\n
 *		@ref S_LCFRCV_VehAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Vehicle longitudinal acceleration \n\n
 *		@ref S_LCFRCV_VehAclY_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Vehicle lateral acceleration \n\n
 *		@ref S_LCFRCV_VehCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Vehicle curvature \n\n
 *		@ref S_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_TCTCLM_QuServTrajCtr_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Trajectory controller qualifier. Includes relevant information for the Situation Assessment components. \n\n
 *		@ref S_TJASTM_SysStateTJA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TPLFBT_QuStatusTrajPlan_nu \n
 *		\@kind: Input Signal \n
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
 *		@ref S_VDPDRV_ActiveStCtrl_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: ActiveCtrlABS \n
 *		1: ActiveCtrlACC \n
 *		2: ActiveCtrlESC \n
 *		3: ActiveCtrlTCS \n
 *		4: ActiveCtrlVSM \n
 *		5: Reserved \n
 *		6: Reserved \n
 *		7: Reserved \n\n
 *		@ref S_VDPDRV_DrvStInvalid_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: AccelPedalRateInvalid \n
 *		1: DriverNotBuckledUp \n
 *		2: TurnSignalHarzard \n
 *		3: TurnSignalLeftOrRight \n
 *		4: DrvInattentivenessDetected \n
 *		5: ManualTorqueOverride \n
 *		6: Reserved (0 by default) \n
 *		7: Reserved (0 by default) \n\n
 *		@ref S_VDPDRV_SysStError_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: SystemErrorABS \n
 *		1: SystemErrorACC \n
 *		2: SystemErrorESC \n
 *		3: SystemErrorTCS \n
 *		4: SystemErrorVSM \n
 *		5: SystemErrorVDY \n
 *		6: SystemErrorLatDMC \n
 *		7: Reserved \n\n
 *		@ref S_VDPDRV_SysStNotAvailable_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: SystemNotAvailableABS \n
 *		1: SystemNotAvailableACC \n
 *		2: SystemNotAvailableESC \n
 *		3: SystemNotAvailableTCS \n
 *		4: SystemNotAvailableVSM \n
 *		5: Reserved \n
 *		6: Reserved \n
 *		7: Reserved \n\n
 *		@ref S_VDPDRV_VehStInvalid_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: DoorOpen \n
 *		1: VehicleNotReadyToStart \n
 *		2: TrailerPresent \n
 *		3: InvalidGearEngaged \n
 *		4: VehDoesMovesBckwd \n
 *		5: OversteerDetected \n
 *		6: UndersteerDetected \n
 *		7: RollerBenchDetected \n
 *		8: SteeringStopDetected \n
 *		9: Reserved (0 by default) \n
 *		10: Reserved (0 by default) \n
 *		11: Reserved (0 by default) \n
 *		12: Reserved (0 by default) \n
 *		13: Reserved (0 by default) \n
 *		14: Reserved (0 by default) \n
 *		15: Reserved (0 by default) \n\n
 *		@ref P_LKA_Available_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if LKA is a coded function of the system \n\n
 *		@ref P_TJAGEN_AccelXHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum long acceleration for TJA activation (hysteresis) \n\n
 *		@ref P_TJAGEN_AccelYHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum lateral acceleration for TJA activation (hysteresis) \n\n
 *		@ref P_TJAGEN_AclXMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum long acceleration for TJA activation \n\n
 *		@ref P_TJAGEN_AclXMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum long deceleration for TJA activation \n\n
 *		@ref P_TJAGEN_AclYMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum lateral acceleration for TJA activation \n\n
 *		@ref P_TJAGEN_ActiveStCtrlSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask for active state check of vehicle safety functions \n\n
 *		@ref P_TJAGEN_BlockTimeTJA_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJA blocking time \n\n
 *		@ref P_TJAGEN_CheckTJAErrorState_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable TJA error state check of S_RTE_ErrorStateTJA_bool \n\n
 *		@ref P_TJAGEN_DrvStInvalidC_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask value for driver state checks of the cancel condition \n\n
 *		@ref P_TJAGEN_DrvStInvalidSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask value for driver state checks of the strong ready condition \n\n
 *		@ref P_TJAGEN_DrvStInvalidWR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask value for driver state checks of the weak ready condition \n\n
 *		@ref P_TJAGEN_PrjSpecQuA_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific abort conditions for all TJA modes \n\n
 *		@ref P_TJAGEN_PrjSpecQuC_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific cancel conditions for all TJA modes \n\n
 *		@ref P_TJAGEN_PrjSpecQuSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific strong ready conditions for all TJA modes \n\n
 *		@ref P_TJAGEN_PrjSpecQuWR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific weak ready conditions for all TJA modes \n\n
 *		@ref P_TJAGEN_QuTrajCtrCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask check for S_TCTCLM_QuServTrajCtr_nu as cancel condition \n\n
 *		@ref P_TJAGEN_QuTrajCtrClearance_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask check for S_TCTCLM_QuServTrajCtr_nu as clearance condition \n\n
 *		@ref P_TJAGEN_QuTrajPlanCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask check for S_TPLTJC_QuStatusTrajPlan_nu as cancel condition \n\n
 *		@ref P_TJAGEN_QuTrajPlanClearance_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask check for S_TPLTJC_QuStatusTrajPlan_nu as clearance condition \n\n
 *		@ref P_TJAGEN_RampoutTimeMax_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum rampout time \n\n
 *		@ref P_TJAGEN_SetSysStOnLatDMC_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Manual switch to set LatDMC system state ON \n\n
 *		@ref P_TJAGEN_SteerWAngleMaxWR_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_0_180_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: 0 \n
 *		\@max: 180 \n
 *		\@description: \n
 *		Maximum steering wheel angle for function activation \n\n
 *		@ref P_TJAGEN_SysStErrorSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask for system error check of vehicle safety functions (ABS, ESC, etc.) for SR condition \n\n
 *		@ref P_TJAGEN_SysStNotAvailableWR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask to check for weak ready conditions if vehicle safety functions are not available \n\n
 *		@ref P_TJAGEN_VehStInvalidC_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask value for vehicle state checks of the cancel condition \n\n
 *		@ref P_TJAGEN_VehStInvalidSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for vehicle state checks of the strong ready condition \n\n
 *		@ref P_TJAGEN_VehStInvalidWR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for vehicle state checks of the weak ready condition \n\n
 *		@ref P_TJA_Available_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TJA is a coded function of the system \n\n
 *		@ref P_TJA_ManFunctionSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJA manual function switch (if HMI not working): 1: TJA switch off, 0: TJA switched off \n\n
 *		@ref X_TJAGEN_VehVelX_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		TJAGEN vehicle speed x-axis for Y_TJAGEN_VehRadiusMaxWR_met \n\n
 *		@ref Y_TJAGEN_VehRadiusMinWR_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5000 \n
 *		\@description: \n
 *		Minimum required vehicle radius at function start \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJAGEN Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJAGEN_SEN/TJAGEN/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJAGEN_Testcase_Initialization) Initialization of the TJAGEN module
 *		-# [Testcase_StrongReadyDebugSignal](@ref TJAGEN_Testcase_StrongReadyDebugSignal) Strong Ready Debug Signal
 *		-# [Testcase_StrongReadyConditions](@ref TJAGEN_Testcase_StrongReadyConditions) Strong Ready Condition Check
 *		-# [Testcase_WeakReadyConditions](@ref TJAGEN_Testcase_WeakReadyConditions) Weak Ready Condition Check
 *		-# [Testcase_CancelConditions](@ref TJAGEN_Testcase_CancelConditions) Cancel Condition Check
 *		-# [Testcase_ClearanceConditions](@ref TJAGEN_Testcase_ClearanceConditions) Clearance Condition Check
 *		-# [Testcase_DegradationConditions](@ref TJAGEN_Testcase_DegradationConditions) Degradation Condition Check
 *		-# [Testcase_ErrorConditions](@ref TJAGEN_Testcase_ErrorConditions) Error Condition Check
 *		-# [Testcase_CodedAndFunctionSwitch](@ref TJAGEN_Testcase_CodedAndFunctionSwitch) Function Switch and coded function condition Check
 *		-# [Testcase_CustomSpecificQualifier](@ref TJAGEN_Testcase_CustomSpecificQualifier) Custom specific qualifier
 *		
 *	@traceability
 *		[\@link: TJAGEN Module Requirements]()
 */
extern void TJAGEN_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TJAGEN_H_
