/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULE        : MCTLFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MCTLFC.h
//! @brief     (MCTLFC) Module Header.

#ifndef MCTLFC_H_
#define MCTLFC_H_

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
 *	MCTLFC module sensor initialization function. Function initializes MCTLFC sensor output data pointer.
 *	
 *	@param
 *		[in] MCTLFC_SenOutArg Pointer to MCTLFC sensor output data.
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
extern void MCTLFC_SenInitOutPtr(MCTLFC_SenOutType *MCTLFC_SenOutArg);

/*!
 *	MCTLFC module sensor reset function.
 *	
 *	@pre
 *		- The MCTLFC sensor initialization function(s) must be called once.
 *		- The MCTLFC sensor debug/output data pointer(s) should not be NULL.
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
 *		[Output Signal] [S_MCTLFC_ControllingFunction_nu](@ref MCTLFC_SenOutType::S_MCTLFC_ControllingFunction_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref MCTLFC_SenProcess_Globals) of the function @ref MCTLFC_SenProcess.
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
extern void MCTLFC_SenReset(void);

/*!
 *	MCTLFC module sensor process function.
 *	
 *	@pre
 *		- The MCTLFC sensor initialization function(s) must be called once.
 *		- The MCTLFC sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor MCTLFC_SenProcess_Globals
 *		[S_MCTLFC_ControllingFunction_nu](@ref MCTLFC_SenOutType::S_MCTLFC_ControllingFunction_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_DPLSMI_SysStateLDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the LDP function. \n\n
 *		@ref S_DPOSTM_SysStateLDPOC_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of LDPOC \n
 *		Enum: \n
 *		E_LCF_SYSSTATE_NOTPRESENT = 0; \n
 *		E_LCF_SYSSTATE_DISABLED = 1; \n
 *		E_LCF_SYSSTATE_PASSIVE = 2; \n
 *		E_LCF_SYSSTATE_REQUEST = 3; \n
 *		E_LCF_SYSSTATE_CONTROLLING = 4; \n
 *		E_LCF_SYSSTATE_RAMPOUT = 5; \n
 *		E_LCF_SYSSTATE_ERROR = 6; \n\n
 *		@ref S_DPRSMI_SysStateRDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the RDP function. \n\n
 *		@ref S_ESASTM_SysStateESA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		ESA System State \n\n
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
 *		@ref S_LCRSMI_SysStateALCA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCSSTM_SysStateAOLC_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TJASTM_SysStateTJA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref P_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Error Injection value for S_MCTLFC_ControllingFunction_nu \n\n
 *		@ref P_MCTLFC_ErrInjEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Error Injection Switch for MCTLFC \n\n
 *		@ref P_MCTLFC_FollowUpDurationVec_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Follow up Duration vector for every function in MDCTR. \n\n
 *		@ref P_MCTLFC_PriorityVector_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		The order in the priority of the functions will be [TJA LDP LDPOC RDP ALCA AOLC ESA]. No two numbers shall be equal, except for 0. \n\n
 *		@ref P_MCTLFC_RampOutOverwrite_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If the corresponding bit is activated, a function in degradation can be overwritten by a function with a lower priority. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: MCTLFC Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref MCTLFC_Testcase_Initialization) Initialization of the MCTLFC
 *		-# [Testcase_NoPrio](@ref MCTLFC_Testcase_NoPrio) All priorities are 0
 *		-# [Testcase_TJA](@ref MCTLFC_Testcase_TJA) TJA States
 *		-# [Testcase_LDP](@ref MCTLFC_Testcase_LDP) LDP States
 *		-# [Testcase_LDPOC](@ref MCTLFC_Testcase_LDPOC) LDPOC States
 *		-# [Testcase_RDP](@ref MCTLFC_Testcase_RDP) RDP States
 *		-# [Testcase_ALCA](@ref MCTLFC_Testcase_ALCA) ALCA States
 *		-# [Testcase_AOLC](@ref MCTLFC_Testcase_AOLC) AOLC States
 *		-# [Testcase_ESA](@ref MCTLFC_Testcase_ESA) ESA States
 *		-# [Testcase_TJA_overwritten](@ref MCTLFC_Testcase_TJA_overwritten) TJA Overwritten
 *		-# [Testcase_LDP_overwritten](@ref MCTLFC_Testcase_LDP_overwritten) LDP Overwritten
 *		-# [Testcase_LDPOC_overwritten](@ref MCTLFC_Testcase_LDPOC_overwritten) LDPOC Overwritten
 *		-# [Testcase_RDP_overwritten](@ref MCTLFC_Testcase_RDP_overwritten) RDP Overwritten
 *		-# [Testcase_ALCA_overwritten](@ref MCTLFC_Testcase_ALCA_overwritten) ALCA Overwritten
 *		-# [Testcase_AOLC_overwritten](@ref MCTLFC_Testcase_AOLC_overwritten) AOLC Overwritten
 *		-# [Testcase_ESA_overwritten](@ref MCTLFC_Testcase_ESA_overwritten) ESA Overwritten
 *		-# [Testcase_TJA_overwrites_fct_degr](@ref MCTLFC_Testcase_TJA_overwrites_fct_degr) TJA Overwrites a function in DEGRADATION
 *		-# [Testcase_LDP_overwrites_fct_degr](@ref MCTLFC_Testcase_LDP_overwrites_fct_degr) LDP Overwrites a function in DEGRADATION
 *		-# [Testcase_LDPOC_overwrites_fct_degr](@ref MCTLFC_Testcase_LDPOC_overwrites_fct_degr) LDPOC Overwrites a function in DEGRADATION
 *		-# [Testcase_RDP_overwrites_fct_degr](@ref MCTLFC_Testcase_RDP_overwrites_fct_degr) RDP Overwrites a function in DEGRADATION
 *		-# [Testcase_ALCA_overwrites_fct_degr](@ref MCTLFC_Testcase_ALCA_overwrites_fct_degr) ALCA Overwrites a function in DEGRADATION
 *		-# [Testcase_AOLC_overwrites_fct_degr](@ref MCTLFC_Testcase_AOLC_overwrites_fct_degr) AOLC Overwrites a function in DEGRADATION
 *		-# [Testcase_ESA_overwrites_fct_degr](@ref MCTLFC_Testcase_ESA_overwrites_fct_degr) ESA Overwrites a function in DEGRADATION
 *		-# [Testcase_ErorInjection](@ref MCTLFC_Testcase_ErorInjection) Error Injection test
 *		
 *	@traceability
 *		[\@link: MCTLFC Module Requirements]()
 */
extern void MCTLFC_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // MCTLFC_H_
