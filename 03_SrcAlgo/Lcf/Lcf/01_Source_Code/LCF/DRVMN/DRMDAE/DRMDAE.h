/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMDAE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMDAE.h
//! @brief     (DRMDAE) Module Header.

#ifndef DRMDAE_H_
#define DRMDAE_H_

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
 *	DRMDAE module vehicle initialization function. Function initializes DRMDAE vehicle debug data pointer.
 *	
 *	@param
 *		[in] DRMDAE_VehDbgArg Pointer to DRMDAE vehicle debug data.
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
extern void DRMDAE_VehInitDbgPtr(DRMDAE_VehDbgType *DRMDAE_VehDbgArg);

/*!
 *	DRMDAE module vehicle initialization function. Function initializes DRMDAE vehicle output data pointer.
 *	
 *	@param
 *		[in] DRMDAE_VehOutArg Pointer to DRMDAE vehicle output data.
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
extern void DRMDAE_VehInitOutPtr(DRMDAE_VehOutType *DRMDAE_VehOutArg);

/*!
 *	DRMDAE module vehicle reset function.
 *	
 *	@pre
 *		- The DRMDAE vehicle initialization function(s) must be called once.
 *		- The DRMDAE vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_DRMDAE_AbuseWarning_bool](@ref DRMDAE_VehDbgType::S_DRMDAE_AbuseWarning_bool) \n
 *		[Debug  Signal] [S_DRMDAE_SysWarning_nu](@ref DRMDAE_VehDbgType::S_DRMDAE_SysWarning_nu) \n
 *		[Output Signal] [D_DRMDAE_AbuseWarnDuration_sec](@ref DRMDAE_VehOutType::D_DRMDAE_AbuseWarnDuration_sec) \n
 *		[Output Signal] [D_DRMDAE_ActToi_nu](@ref DRMDAE_VehOutType::D_DRMDAE_ActToi_nu) \n
 *		[Output Signal] [D_DRMDAE_CriticalEventsNo_nu](@ref DRMDAE_VehOutType::D_DRMDAE_CriticalEventsNo_nu) \n
 *		[Output Signal] [D_DRMDAE_ElapsedTime_sec](@ref DRMDAE_VehOutType::D_DRMDAE_ElapsedTime_sec) \n
 *		[Output Signal] [D_DRMDAE_HoffTrigger_nu](@ref DRMDAE_VehOutType::D_DRMDAE_HoffTrigger_nu) \n
 *		[Output Signal] [D_DRMDAE_ResetWarnCnt_nu](@ref DRMDAE_VehOutType::D_DRMDAE_ResetWarnCnt_nu) \n
 *		[Output Signal] [D_DRMDAE_SpeedOk_bool](@ref DRMDAE_VehOutType::D_DRMDAE_SpeedOk_bool) \n
 *		[Output Signal] [S_DRMDAE_DrvAttentionConf_perc](@ref DRMDAE_VehOutType::S_DRMDAE_DrvAttentionConf_perc) \n
 *		[Output Signal] [S_DRMDAE_DrvAttention_perc](@ref DRMDAE_VehOutType::S_DRMDAE_DrvAttention_perc) \n\n
 *		For signal details, see sub-section [Globals](@ref DRMDAE_VehProcess_Globals) of the function @ref DRMDAE_VehProcess.
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
extern void DRMDAE_VehReset(void);

/*!
 *	DRMDAE module vehicle process function.
 *	
 *	@pre
 *		- The DRMDAE vehicle initialization function(s) must be called once.
 *		- The DRMDAE vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor DRMDAE_VehProcess_Globals
 *		[S_DRMDAE_AbuseWarning_bool](@ref DRMDAE_VehDbgType::S_DRMDAE_AbuseWarning_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Warning signal if driver is handsOff while funciton is interveening. \n
 *		1 - audiovisual warning on \n
 *		0 - stop abuse warning \n\n
 *		[S_DRMDAE_SysWarning_nu](@ref DRMDAE_VehDbgType::S_DRMDAE_SysWarning_nu) \n
 *		\@kind: Debug Signal \n
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
 *		[D_DRMDAE_AbuseWarnDuration_sec](@ref DRMDAE_VehOutType::D_DRMDAE_AbuseWarnDuration_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Duration of the Driver Abuse Warning \n\n
 *		[D_DRMDAE_ActToi_nu](@ref DRMDAE_VehOutType::D_DRMDAE_ActToi_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1 if in a critical momment (one of the monitored funcitons is in controlling) \n\n
 *		[D_DRMDAE_CriticalEventsNo_nu](@ref DRMDAE_VehOutType::D_DRMDAE_CriticalEventsNo_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Number of critical events since last reset \n
 *		Used for Driver Abuse Monitoring \n\n
 *		[D_DRMDAE_ElapsedTime_sec](@ref DRMDAE_VehOutType::D_DRMDAE_ElapsedTime_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Time without Driver Abuse of Functions \n\n
 *		[D_DRMDAE_HoffTrigger_nu](@ref DRMDAE_VehOutType::D_DRMDAE_HoffTrigger_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Debug trigger signal \n\n
 *		[D_DRMDAE_ResetWarnCnt_nu](@ref DRMDAE_VehOutType::D_DRMDAE_ResetWarnCnt_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Debug reset for warning signal \n\n
 *		[D_DRMDAE_SpeedOk_bool](@ref DRMDAE_VehOutType::D_DRMDAE_SpeedOk_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Speed Check Flag \n\n
 *		[S_DRMDAE_DrvAttentionConf_perc](@ref DRMDAE_VehOutType::S_DRMDAE_DrvAttentionConf_perc) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref s8_Perc_m128_127_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: -128 \n
 *		\@max: 127 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DRMDAE_DrvAttention_perc](@ref DRMDAE_VehOutType::S_DRMDAE_DrvAttention_perc) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Perc_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DRMHOD_HandsOffConfirmed_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_HMIOC_AvailableFunction_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_ActFctLevel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Active Function Level. Used to change time thresholds in different scenarios. \n
 *		Range shall be 0..9 .  \n
 *		In ARAMIS is specified full range, to be able to implement range check in SDA (otherwise, code will not be generated because checked range is the same as input range, so the generator will optimize). \n\n
 *		@ref S_LCFRCV_ActToi_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		From LatDMC. \n
 *		Boolean Signal. 1 if requested torque is != 0. \n
 *		0 if the requested torque is 0. \n\n
 *		@ref S_LCFRCV_SysCycleTimeVeh_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p03_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.03 \n
 *		\@description: \n
 *		Cycle Time for VEH task \n\n
 *		@ref S_LCFRCV_VehSync4LCO_us \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u32_us_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: us \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		Timestamp of VDY signals for latency compensation \n\n
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
 *		@ref P_DRMDAE_1stIncCycle_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		First HandsOff cycle with Active funciton when the duration of the warning should be incremented \n\n
 *		@ref P_DRMDAE_Abuse1stDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Time to warn the driver at first Abuse attempt \n\n
 *		@ref P_DRMDAE_AbuseFunctions_btf \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield to define for which functions, DriverAbuseMonitoring is enabled. \n\n
 *		@ref P_DRMDAE_ConsecIntervTimer_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Max time between 2 consecutive interventions to monitor Driver Function Abuse \n\n
 *		@ref P_DRMDAE_DebHorAfterHandsOff_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Debounce time between physical driver hands off and hands on request warning \n\n
 *		@ref P_DRMDAE_DebounceTorAfterHor_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Debounce time between hands on request and take over request \n\n
 *		@ref P_DRMDAE_IncNextWarning_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Time to increment the warning sound duration if driver does not cooperate \n\n
 *		@ref P_DRMDAE_RlvntConfFct_btf \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Mask to determine which functions are relvant for Driver Monitoring System warning. \n
 *		Should be the confort functions, which are being degraded in case of hands off. \n\n
 *		@ref P_DRMDAE_SpeedLimitHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Hysteresis for speed limit \n\n
 *		@ref P_DRMDAE_SpeedMin_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Speed limit, under which Hands Off Detection is deactivated => always hands on, if the speed is bellow 10kph \n\n
 *		@ref P_DRMDAE_TrigDegrAftTorTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Time to Keep the Take Over Request warning. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DRMDAE Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DRMDAE_Testcase_Initialization) Initialization of the ODPROP
 *		-# [Test1](@ref DRMDAE_Test1) 
 *		-# [Test2](@ref DRMDAE_Test2) 
 *		-# [Test3](@ref DRMDAE_Test3) 
 *		-# [Test4](@ref DRMDAE_Test4) 
 *		-# [Test5](@ref DRMDAE_Test5) 
 *		-# [Test6](@ref DRMDAE_Test6) 
 *		-# [Test7](@ref DRMDAE_Test7) 
 *		-# [Test8](@ref DRMDAE_Test8) 
 *		-# [Test9](@ref DRMDAE_Test9) 
 *		-# [Test10](@ref DRMDAE_Test10) 
 *		-# [Test11](@ref DRMDAE_Test11) 
 *		-# [Test12](@ref DRMDAE_Test12) 
 *		-# [Test13](@ref DRMDAE_Test13) 
 *		-# [Test14](@ref DRMDAE_Test14) 
 *		-# [Test15](@ref DRMDAE_Test15) 
 *		-# [Test16](@ref DRMDAE_Test16) 
 *		-# [Test17](@ref DRMDAE_Test17) 
 *		-# [Test18](@ref DRMDAE_Test18) 
 *		-# [Test19](@ref DRMDAE_Test19) 
 *		-# [Test20](@ref DRMDAE_Test20) 
 *		-# [Test21](@ref DRMDAE_Test21) 
 *		-# [Test22](@ref DRMDAE_Test22) 
 *		-# [Test23](@ref DRMDAE_Test23) 
 *		-# [Test24](@ref DRMDAE_Test24) 
 *		-# [Test25](@ref DRMDAE_Test25) 
 *		-# [Test26](@ref DRMDAE_Test26) 
 *		-# [Test27](@ref DRMDAE_Test27) 
 *		-# [Test28](@ref DRMDAE_Test28) 
 *		-# [Test29](@ref DRMDAE_Test29) 
 *		-# [Test30](@ref DRMDAE_Test30) 
 *		-# [Test31](@ref DRMDAE_Test31) 
 *		-# [Test32](@ref DRMDAE_Test32) 
 *		-# [Testcase_VehSync](@ref DRMDAE_Testcase_VehSync) 
 *		
 *	@traceability
 *		[\@link: DRMDAE Module Requirements]()
 */
extern void DRMDAE_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DRMDAE_H_
