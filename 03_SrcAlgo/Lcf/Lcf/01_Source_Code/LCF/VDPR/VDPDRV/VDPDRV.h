/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : VDPR
  MODULE        : VDPDRV
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     VDPDRV.h
//! @brief     (VDPDRV) Module Header.

#ifndef VDPDRV_H_
#define VDPDRV_H_

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
 *	VDPDRV module sensor initialization function. Function initializes VDPDRV sensor debug data pointer.
 *	
 *	@param
 *		[in] VDPDRV_SenDbgArg Pointer to VDPDRV sensor debug data.
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
extern void VDPDRV_SenInitDbgPtr(VDPDRV_SenDbgType *VDPDRV_SenDbgArg);

/*!
 *	VDPDRV module sensor reset function.
 *	
 *	@pre
 *		- The VDPDRV sensor initialization function(s) must be called once.
 *		- The VDPDRV sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_VDPDRV_ActiveStCtrl_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_ActiveStCtrl_btf) \n
 *		[Debug  Signal] [S_VDPDRV_DrvStInvalid_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_DrvStInvalid_btf) \n
 *		[Debug  Signal] [S_VDPDRV_SysStError_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_SysStError_btf) \n
 *		[Debug  Signal] [S_VDPDRV_SysStNotAvailable_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_SysStNotAvailable_btf) \n
 *		[Debug  Signal] [S_VDPDRV_VehStInvalid_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_VehStInvalid_btf) \n\n
 *		For signal details, see sub-section [Globals](@ref VDPDRV_SenProcess_Globals) of the function @ref VDPDRV_SenProcess.
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
extern void VDPDRV_SenReset(void);

/*!
 *	VDPDRV module sensor process function.
 *	
 *	@pre
 *		- The VDPDRV sensor initialization function(s) must be called once.
 *		- The VDPDRV sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor VDPDRV_SenProcess_Globals
 *		[S_VDPDRV_ActiveStCtrl_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_ActiveStCtrl_btf) \n
 *		\@kind: Debug Signal \n
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
 *		[S_VDPDRV_DrvStInvalid_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_DrvStInvalid_btf) \n
 *		\@kind: Debug Signal \n
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
 *		[S_VDPDRV_SysStError_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_SysStError_btf) \n
 *		\@kind: Debug Signal \n
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
 *		[S_VDPDRV_SysStNotAvailable_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_SysStNotAvailable_btf) \n
 *		\@kind: Debug Signal \n
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
 *		[S_VDPDRV_VehStInvalid_btf](@ref VDPDRV_SenDbgType::S_VDPDRV_VehStInvalid_btf) \n
 *		\@kind: Debug Signal \n
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
 *		@ref S_DRMDAE_SysWarning_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DRMDAE_SysWarnType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		0 - NoWarning \n
 *		1 - AttentivnessRequest \n
 *		2 - TakeOverRequest  \n
 *		3 - DegradationTrigger \n\n
 *		@ref S_LCFRCV_AccelPedalPos_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Acceleration pedal position \n\n
 *		@ref S_LCFRCV_ActiveStCtrlABS_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ABS in actively controlling \n\n
 *		@ref S_LCFRCV_ActiveStCtrlACC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ACC in actively controlling \n\n
 *		@ref S_LCFRCV_ActiveStCtrlEBA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if EBA in actively controlling \n\n
 *		@ref S_LCFRCV_ActiveStCtrlESC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ESC in actively controlling \n\n
 *		@ref S_LCFRCV_ActiveStCtrlTCS_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TCS in actively controlling \n\n
 *		@ref S_LCFRCV_ActiveStCtrlTSA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TSA in actively controlling \n\n
 *		@ref S_LCFRCV_ActiveStCtrlVSM_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if VSM in actively controlling \n\n
 *		@ref S_LCFRCV_BrightnessState_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_VDPR_BrightnStType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		LSD Brightness State: \n
 *		 \n
 *		 \n
 *		 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN = 0 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY = 1 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1 = 2 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2 = 3 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3 = 4 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT = 5 \n\n
 *		@ref S_LCFRCV_CurrentGearNeutral_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if the neutral gear is engaged \n\n
 *		@ref S_LCFRCV_CurrentGearParking_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if the parking gear is engaged \n\n
 *		@ref S_LCFRCV_CurrentGearReverse_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if the reverse gear is engaged \n\n
 *		@ref S_LCFRCV_DoorOpen_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if the door is opened \n\n
 *		@ref S_LCFRCV_DriverNotBuckledUp_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if the driver is not buckled \n\n
 *		@ref S_LCFRCV_EPS_ManualTrqActualVal_Nm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Rename of S_RTE_EPS_ManualTrqActualVal_Nm \n\n
 *		@ref S_LCFRCV_OversteeringDetected_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if oversteering has been detected \n\n
 *		@ref S_LCFRCV_RollerBenchDetected_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if vehicle is on roller bench \n\n
 *		@ref S_LCFRCV_SteeringAngleFrontAxleEff_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Effective steering angle at front axle \n\n
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
 *		@ref S_LCFRCV_SysStAvailableABS_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ABS is available \n\n
 *		@ref S_LCFRCV_SysStAvailableACC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ACC is available \n\n
 *		@ref S_LCFRCV_SysStAvailableEBA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if EBA is available \n\n
 *		@ref S_LCFRCV_SysStAvailableESC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ESC is available \n\n
 *		@ref S_LCFRCV_SysStAvailableTCS_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TCS is available \n\n
 *		@ref S_LCFRCV_SysStAvailableTSA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TSA is available \n\n
 *		@ref S_LCFRCV_SysStAvailableVSM_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if VSM is available \n\n
 *		@ref S_LCFRCV_SysStErrorABS_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ABS is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorACC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ACC is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorEBA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if EBA is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorESC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if ESC is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorLatDMC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if LatDMC is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorTCS_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TCS is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorTSA_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if TSA is in error state \n\n
 *		@ref S_LCFRCV_SysStErrorVSM_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if VSM is in error state \n\n
 *		@ref S_LCFRCV_TrailerPresent_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if trailer is attached \n\n
 *		@ref S_LCFRCV_TurnSignalHazard_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if hazard light is on \n\n
 *		@ref S_LCFRCV_TurnSignalLeft_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if left turn signal is engaged \n\n
 *		@ref S_LCFRCV_TurnSignalRight_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if right turn signal is engaged \n\n
 *		@ref S_LCFRCV_UndersteeringDetected_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if understeering has been detected \n\n
 *		@ref S_LCFRCV_VehMovesBckwd_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if vehicles moves backward \n\n
 *		@ref S_LCFRCV_VehReadyToStart_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if vehicle is ready to start \n\n
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
 *		@ref S_LCFRCV_WiperStage_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_WIPER_STAGE_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		Wiper state \n\n
 *		@ref S_LCFRCV_WiperState_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_WIPER_STATE_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Wiper State \n\n
 *		@ref P_VDPDRV_DebTimeAccPedRate_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		VDPDRV_APARAM \n\n
 *		@ref P_VDPDRV_DebTimeActStCtrl_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		VDPDRV_APARAM \n\n
 *		@ref P_VDPDRV_DebTimeTurnSignal_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		VDPDRV_APARAM \n\n
 *		@ref P_VDPDRV_DebugWiperStateActive_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Deactivate Wiper State Signal \n\n
 *		@ref P_VDPDRV_HoldTimeErrorSt_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Hold time for error state bit field \n
 *		(previous: P_VDPDRV_MinDurtnSysStError_sec) \n\n
 *		@ref P_VDPDRV_ManTrqOvrrdMaxTrq_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Manual steering torque threshold, which will lead in any case to rampout. \n\n
 *		@ref P_VDPDRV_ManTrqOvrrdTrnOnTm_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn-on delay time for manual steering torque override trigger \n\n
 *		@ref P_VDPDRV_MaxAccelPedalRate_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		VDPDRV_APARAM \n\n
 *		@ref P_VDPDRV_MaxVelLimStrngStp_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m150_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -150 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		InitValue: 5.6 \n\n
 *		@ref P_VDPDRV_NoDaytBrightState_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Define NoDaytime condition with the following states: \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN = 0 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY = 1 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1 = 2 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2 = 3 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3 = 4 \n
 *		LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT = 5 \n\n
 *		@ref P_VDPDRV_NoDaytCndTimeMin_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Min time to activate NoDaytime condition \n\n
 *		@ref P_VDPDRV_NoDaytCndTrnOff_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn off time of NoDaytime condition \n\n
 *		@ref P_VDPDRV_ThStrngStpDtctd_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		InitValue: 0.5235 \n\n
 *		@ref P_VDPDRV_ThStrngStpNotDtctd_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		InitValue: 0.4365 \n\n
 *		@ref P_VDPDRV_TurnOffTimeErrorSt_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn off delay time for error state bit field \n\n
 *		@ref P_VDPDRV_TurnOnTimeErrorSt_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for error state bit field \n\n
 *		@ref P_VDPDRV_WiperActiveTimeMin_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Wiper minimum active time for considering it as one wiper event \n\n
 *		@ref P_VDPDRV_WiperEventsGapTimeMax_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum time gap between wiper events for continuous wiping check \n\n
 *		@ref P_VDPDRV_WiperMinContinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time of continuous wiping for considering rainy conditions \n\n
 *		@ref P_VDPDRV_WiperStageActive_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Activate/Deactivate Conditons which are valid for Wiper Stage.  Bits follow enums of S_LCFRCV_WiperStage_nu \n
 *		(State 0 = Bit 0) \n
 *		255 is deactivation of Stage check \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: VDPDRV Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref VDPDRV_Testcase_Initialization) Initialization of the VDPDRV module
 *		-# [Testcase_S_VDPDRV_SysStNotAvailable_btf](@ref VDPDRV_Testcase_S_VDPDRV_SysStNotAvailable_btf) S_VDPDRV_SysStNotAvailable_btf
 *		-# [Testcase_S_VDPDRV_SysStError_btf](@ref VDPDRV_Testcase_S_VDPDRV_SysStError_btf) S_VDPDRV_SysStError_btf
 *		-# [Testcase_S_VDPDRV_ActiveStCtrl_btf](@ref VDPDRV_Testcase_S_VDPDRV_ActiveStCtrl_btf) S_VDPDRV_ActiveStCtrl_btf
 *		-# [Testcase_S_VDPDRV_VehStInvalid_btf](@ref VDPDRV_Testcase_S_VDPDRV_VehStInvalid_btf) S_VDPDRV_VehStInvalid_btf
 *		-# [Testcase_S_VDRDRV_DrvStInvalid](@ref VDPDRV_Testcase_S_VDRDRV_DrvStInvalid) S_VDRDRV_DrvStInvalid
 *		
 *	@traceability
 *		[\@link: VDPDRV Module Requirements]()
 */
extern void VDPDRV_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // VDPDRV_H_
