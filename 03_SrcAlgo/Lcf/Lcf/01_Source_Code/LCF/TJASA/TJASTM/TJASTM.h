/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJASTM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJASTM.h
//! @brief     (TJASTM) Module Header.

#ifndef TJASTM_H_
#define TJASTM_H_

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
 *	TJASTM module sensor initialization function. Function initializes TJASTM sensor debug data pointer.
 *	
 *	@param
 *		[in] TJASTM_SenDbgArg Pointer to TJASTM sensor debug data.
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
extern void TJASTM_SenInitDbgPtr(TJASTM_SenDbgType *TJASTM_SenDbgArg);

/*!
 *	TJASTM module sensor initialization function. Function initializes TJASTM sensor output data pointer.
 *	
 *	@param
 *		[in] TJASTM_SenOutArg Pointer to TJASTM sensor output data.
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
extern void TJASTM_SenInitOutPtr(TJASTM_SenOutType *TJASTM_SenOutArg);

/*!
 *	TJASTM module sensor reset function.
 *	
 *	@pre
 *		- The TJASTM sensor initialization function(s) must be called once.
 *		- The TJASTM sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TJASTM_TJAInvalid_btf](@ref TJASTM_SenDbgType::D_TJASTM_TJAInvalid_btf) \n
 *		[Output Signal] [S_TJASTM_LatCtrlMode_nu](@ref TJASTM_SenOutType::S_TJASTM_LatCtrlMode_nu) \n
 *		[Output Signal] [S_TJASTM_SysStateTJA_nu](@ref TJASTM_SenOutType::S_TJASTM_SysStateTJA_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TJASTM_SenProcess_Globals) of the function @ref TJASTM_SenProcess.
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
extern void TJASTM_SenReset(void);

/*!
 *	TJASTM module sensor process function.
 *	
 *	@pre
 *		- The TJASTM sensor initialization function(s) must be called once.
 *		- The TJASTM sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJASTM_SenProcess_Globals
 *		[D_TJASTM_TJAInvalid_btf](@ref TJASTM_SenDbgType::D_TJASTM_TJAInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJASTM_DEBUG \n
 *		 \n
 *		0: TJA: StrongReadyInvalid \n
 *		1: TJA: WeakReadyInvalid \n
 *		2: LC: StrongReadyInvalid \n
 *		3: LC: WeakReadyInvalid \n
 *		4: OF: StrongReadyInvalid \n
 *		5: OF: WeakReadyInvalid \n
 *		6: SLC: StrongReadyInvalid \n
 *		7: SLC: WeakReadyInvalid \n
 *		8: TJA: CancelCondFulfilled \n
 *		9: TJA: FunctionSwitchInvalid \n
 *		10: TJA: RampoutComplete \n
 *		11: TJA: NoClearance \n
 *		12: TJA: FunctionNotCoded \n
 *		13: TJA: ErrorState \n
 *		14-15: Reserved (0 by default) \n\n
 *		[S_TJASTM_LatCtrlMode_nu](@ref TJASTM_SenOutType::S_TJASTM_LatCtrlMode_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		[S_TJASTM_SysStateTJA_nu](@ref TJASTM_SenOutType::S_TJASTM_SysStateTJA_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TJACMB_Cancel_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if at least one cancel condition for combined mode is fulfilled. \n\n
 *		@ref S_TJACMB_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if all strong ready conditions for combined mode are fulfilled. \n\n
 *		@ref S_TJACMB_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if all weak ready conditions for combined mode are fulfilled. \n\n
 *		@ref S_TJAGEN_Cancel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA cancel conditions are fulfilled \n\n
 *		@ref S_TJAGEN_Clearance_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA received clearance from mode control \n\n
 *		@ref S_TJAGEN_CodeFunction_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA is coded. \n\n
 *		@ref S_TJAGEN_Degradation_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if rampout is completed \n\n
 *		@ref S_TJAGEN_Error_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA error conditions are fulfilled \n\n
 *		@ref S_TJAGEN_FunctionSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA is switched on \n\n
 *		@ref S_TJAGEN_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA strong ready conditions are fulfilled \n\n
 *		@ref S_TJAGEN_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if TJA weak ready conditions are fulfilled \n\n
 *		@ref S_TJALKA_Cancel_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for lane centering are fulfilled. \n\n
 *		@ref S_TJALKA_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for lane centering are fulfilled. \n\n
 *		@ref S_TJALKA_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for lane centering are fulfilled. \n\n
 *		@ref S_TJAOBF_Cancel_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for object following are fulfilled. \n\n
 *		@ref S_TJAOBF_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for object following are fulfilled. \n\n
 *		@ref S_TJAOBF_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for object following are fulfilled. \n\n
 *		@ref S_TJAOBS_CancelLC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if critical situation is observed, which required cancelation of lane centering mode \n\n
 *		@ref S_TJAOBS_CancelOF_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if critical situation is observed, which required cancelation of object following mode \n\n
 *		@ref S_TJASLC_Cancel_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJASLC_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for lane change mode are fulfilled. \n\n
 *		@ref S_TJASLC_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJASLC_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for lane change mode are fulfilled. \n\n
 *		@ref S_TJASLC_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJASLC_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for lane change mode are fulfilled. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJASTM Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJASTM_SEN/TJASTM/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJASTM_Testcase_Initialization) Initialization of the TJASTM
 *		-# [Testcase_DebugSignal](@ref TJASTM_Testcase_DebugSignal) Debug Signal check
 *		-# [Testcase_NotPresentState](@ref TJASTM_Testcase_NotPresentState) Not present states check
 *		-# [Testcase_PassiveState](@ref TJASTM_Testcase_PassiveState) Check of transitions between DISABLED and PASSIVE
 *		-# [Testcase_RequestState](@ref TJASTM_Testcase_RequestState) Check of transitions from PASSIVE to REQUEST
 *		-# [Testcase_SysState_Request2Passive](@ref TJASTM_Testcase_SysState_Request2Passive) Check of transitions from REQUEST to PASSIVE
 *		-# [Testcase_SysState_Request2Controlling](@ref TJASTM_Testcase_SysState_Request2Controlling) Check of transitions from REQUEST to CONTROLLING
 *		-# [Testcase_ControllingState_SetModes](@ref TJASTM_Testcase_ControllingState_SetModes) Set all lateral control modes in CONTROLLING
 *		-# [Testcase_RequestState_ModeTransitions](@ref TJASTM_Testcase_RequestState_ModeTransitions) Check of transitions to CONTROLLING
 *		-# [Testcase_ControllingState_ModeTransitions](@ref TJASTM_Testcase_ControllingState_ModeTransitions) Check of transitions to CONTROLLING
 *		-# [Testcase_ControllingState_SALC](@ref TJASTM_Testcase_ControllingState_SALC) Check of transitions to CONTROLLING SALC
 *		-# [Testcase_SysState_Controlling2Rampout](@ref TJASTM_Testcase_SysState_Controlling2Rampout) Check of transitions from CONTROLLING to RAMPOUT
 *		-# [Testcase_SysState_Rampout2Disabled](@ref TJASTM_Testcase_SysState_Rampout2Disabled) Check of transitions from RAMPOUT to DISABLED
 *		-# [Testcase_SysState_Rampout2Passive](@ref TJASTM_Testcase_SysState_Rampout2Passive) Check of transitions from RAMPOUT to PASSIVE
 *		-# [Testcase_ErrorState](@ref TJASTM_Testcase_ErrorState) Check of transitions to ERROR
 *		
 *	@traceability
 *		[\@link: TJASTM Module Requirements]()
 */
extern void TJASTM_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TJASTM_H_
