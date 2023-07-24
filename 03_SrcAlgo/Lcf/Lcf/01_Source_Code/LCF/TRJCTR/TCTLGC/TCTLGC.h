/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTLGC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTLGC.h
//! @brief     (TCTLGC) Module Header.

#ifndef TCTLGC_H_
#define TCTLGC_H_

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
 *	TCTLGC module vehicle initialization function. Function initializes TCTLGC vehicle debug data pointer.
 *	
 *	@param
 *		[in] TCTLGC_VehDbgArg Pointer to TCTLGC vehicle debug data.
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
extern void TCTLGC_VehInitDbgPtr(TCTLGC_VehDbgType *TCTLGC_VehDbgArg);

/*!
 *	TCTLGC module vehicle initialization function. Function initializes TCTLGC vehicle output data pointer.
 *	
 *	@param
 *		[in] TCTLGC_VehOutArg Pointer to TCTLGC vehicle output data.
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
extern void TCTLGC_VehInitOutPtr(TCTLGC_VehOutType *TCTLGC_VehOutArg);

/*!
 *	TCTLGC module vehicle reset function.
 *	
 *	@pre
 *		- The TCTLGC vehicle initialization function(s) must be called once.
 *		- The TCTLGC vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TCTLGC_CacCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacDT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacDT1Cmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacICmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacICmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacIntReset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_CacIntReset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_CacLaDmcComp_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacLaDmcComp_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacPCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacPT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPT1Cmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacPT1CoAnErr_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPT1CoAnErr_rad) \n
 *		[Debug  Signal] [D_TCTLGC_CacPT1Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPT1Reset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_CrvReqBAC_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqBAC_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_CrvReqDte_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqDte_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_CrvReqFfcFrz_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcFrz_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_CrvReqFfcGrdLimT1_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcGrdLimT1_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_CrvReqFfcGrdLimT2_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcGrdLimT2_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_CrvReqFfcGrdLim_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcGrdLim_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_DeltaFBAC_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFBAC_deg) \n
 *		[Debug  Signal] [D_TCTLGC_DeltaFCmdDC_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmdDC_deg) \n
 *		[Debug  Signal] [D_TCTLGC_DeltaFCmdFFC_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmdFFC_deg) \n
 *		[Debug  Signal] [D_TCTLGC_DeltaFCmdUnlimited_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmdUnlimited_deg) \n
 *		[Debug  Signal] [D_TCTLGC_DeltaFCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_EnableCtrl_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_EnableCtrl_nu) \n
 *		[Debug  Signal] [D_TCTLGC_Hold_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_Hold_nu) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAloneCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAloneDT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneDT1Cmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAloneICmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneICmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAloneIntReset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneIntReset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAloneLaDmcComp_met](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneLaDmcComp_met) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAlonePCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAlonePT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePT1Cmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAlonePT1Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePT1Reset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_LdcAlonePT1YErr_met](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePT1YErr_met) \n
 *		[Debug  Signal] [D_TCTLGC_LdcCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcDT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcDT1Cmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcICmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcICmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcIntReset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcIntReset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_LdcLaDmcComp_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcLaDmcComp_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcPCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPCmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcPT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPT1Cmd_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcPT1Input_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPT1Input_rad) \n
 *		[Debug  Signal] [D_TCTLGC_LdcPT1Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPT1Reset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_PGainCacGrdLimTrig_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_PGainCacGrdLimTrig_nu) \n
 *		[Debug  Signal] [D_TCTLGC_PGainLdcGrdLimTrig_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_PGainLdcGrdLimTrig_nu) \n
 *		[Debug  Signal] [D_TCTLGC_Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_Reset_nu) \n
 *		[Debug  Signal] [D_TCTLGC_SafetyFunctionActive_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_SafetyFunctionActive_nu) \n
 *		[Debug  Signal] [D_TCTLGC_SumCrvReqFbFrz_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFbFrz_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_SumCrvReqFbGrdLim_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFbGrdLim_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_SumCrvReqFbSatLim_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFbSatLim_1pm) \n
 *		[Debug  Signal] [D_TCTLGC_SumCrvReqFb_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFb_1pm) \n
 *		[Debug  Signal] [S_TCTLGC_CtrlCrv_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_CtrlCrv_1pm) \n
 *		[Debug  Signal] [S_TCTLGC_CtrlCrv_DE_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_CtrlCrv_DE_1pm) \n
 *		[Debug  Signal] [S_TCTLGC_CtrlErrHeadAglCrtd_rad](@ref TCTLGC_VehDbgType::S_TCTLGC_CtrlErrHeadAglCrtd_rad) \n
 *		[Debug  Signal] [S_TCTLGC_DeltaFCmd_deg](@ref TCTLGC_VehDbgType::S_TCTLGC_DeltaFCmd_deg) \n
 *		[Debug  Signal] [S_TCTLGC_FFCrv_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_FFCrv_1pm) \n
 *		[Debug  Signal] [S_TCTLGC_TgtCrv_DENoLatSlp_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_TgtCrv_DENoLatSlp_1pm) \n
 *		[Debug  Signal] [S_TCTLGC_TgtCrv_DE_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_TgtCrv_DE_1pm) \n
 *		[Debug  Signal] [S_TCTLGC_TgtCrv_NoDE_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_TgtCrv_NoDE_1pm) \n
 *		[Output Signal] [D_TCTLGC_ActiveLgcParamSet_nu](@ref TCTLGC_VehOutType::D_TCTLGC_ActiveLgcParamSet_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TCTLGC_VehProcess_Globals) of the function @ref TCTLGC_VehProcess.
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
extern void TCTLGC_VehReset(void);

/*!
 *	TCTLGC module vehicle process function.
 *	
 *	@pre
 *		- The TCTLGC vehicle initialization function(s) must be called once.
 *		- The TCTLGC vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TCTLGC_VehProcess_Globals
 *		[D_TCTLGC_CacCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacDT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacDT1Cmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacICmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacICmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacIntReset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_CacIntReset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacLaDmcComp_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacLaDmcComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacPCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacPT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPT1Cmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacPT1CoAnErr_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPT1CoAnErr_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CacPT1Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_CacPT1Reset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CrvReqBAC_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqBAC_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CrvReqDte_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqDte_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CrvReqFfcFrz_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcFrz_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CrvReqFfcGrdLimT1_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcGrdLimT1_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CrvReqFfcGrdLimT2_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcGrdLimT2_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_CrvReqFfcGrdLim_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_CrvReqFfcGrdLim_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_DeltaFBAC_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFBAC_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_DeltaFCmdDC_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmdDC_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_DeltaFCmdFFC_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmdFFC_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_DeltaFCmdUnlimited_deg](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmdUnlimited_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_DeltaFCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_DeltaFCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m12p57_12p57_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -12.57 \n
 *		\@max: 12.57 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_EnableCtrl_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_EnableCtrl_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_Hold_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_Hold_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAloneCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAloneDT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneDT1Cmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAloneICmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneICmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAloneIntReset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneIntReset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAloneLaDmcComp_met](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAloneLaDmcComp_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAlonePCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAlonePT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePT1Cmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAlonePT1Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePT1Reset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcAlonePT1YErr_met](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcAlonePT1YErr_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcDT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcDT1Cmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcICmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcICmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcIntReset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcIntReset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcLaDmcComp_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcLaDmcComp_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcPCmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPCmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcPT1Cmd_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPT1Cmd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcPT1Input_rad](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPT1Input_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_LdcPT1Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_LdcPT1Reset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_PGainCacGrdLimTrig_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_PGainCacGrdLimTrig_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_PGainLdcGrdLimTrig_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_PGainLdcGrdLimTrig_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_Reset_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_Reset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_SafetyFunctionActive_nu](@ref TCTLGC_VehDbgType::D_TCTLGC_SafetyFunctionActive_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_SumCrvReqFbFrz_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFbFrz_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_SumCrvReqFbGrdLim_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFbGrdLim_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_SumCrvReqFbSatLim_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFbSatLim_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_SumCrvReqFb_1pm](@ref TCTLGC_VehDbgType::D_TCTLGC_SumCrvReqFb_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_CtrlCrv_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_CtrlCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_CtrlCrv_DE_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_CtrlCrv_DE_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_CtrlErrHeadAglCrtd_rad](@ref TCTLGC_VehDbgType::S_TCTLGC_CtrlErrHeadAglCrtd_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_DeltaFCmd_deg](@ref TCTLGC_VehDbgType::S_TCTLGC_DeltaFCmd_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Steering Angle Command for DMC \n\n
 *		[S_TCTLGC_FFCrv_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_FFCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_TgtCrv_DENoLatSlp_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_TgtCrv_DENoLatSlp_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_TgtCrv_DE_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_TgtCrv_DE_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTLGC_TgtCrv_NoDE_1pm](@ref TCTLGC_VehDbgType::S_TCTLGC_TgtCrv_NoDE_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTLGC_ActiveLgcParamSet_nu](@ref TCTLGC_VehOutType::D_TCTLGC_ActiveLgcParamSet_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_1_3_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Active LGC Paramter Set: \n
 *		1: Lane Centering \n
 *		2: Object Following \n
 *		3: Safety Function \n\n
 *		@ref S_CSCLTA_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m2_2_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -2 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_MaxCrvGrdBuildup_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m2_2_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -2 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_MaxCrvGrdRed_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m2_2_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -2 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_MaxCrvTrajGuiCtrl_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
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
 *		@ref S_TCTCDC_CtrlErrDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTCDC_CtrlErrHeadAglPrev_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		 \n\n
 *		@ref S_TCTDEV_CrvTestSignal_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Test signal for curvature output of lateral KMC \n\n
 *		@ref S_TCTDEV_DeltaFCmdTestSignal_deg \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Test signal for steering angle command from LaKMC to DMC \n\n
 *		@ref S_TCTDTE_CrvReqBnkAglComp_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTDTE_CrvReqDstrbComp_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTDTE_DeltaSetBnkAglComp_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTDTE_DeltaSetCroWiComp_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Control signal /rad used to compensate crosswind \n\n
 *		@ref S_TCTDTE_DeltaSetDstrbComp_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6p28_6p28_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6.28 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Additional steer angle control signal part needed to compensate disturbances \n\n
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
 *		@ref P_TCTLGC_ActivateDynBacGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTLGC_ActivateOverride_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Force ENABLE OUTPUT = 1 \n
 *		0: Normal ENABLE OUTPUT behavior \n\n
 *		@ref P_TCTLGC_CacILimit_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_6p28_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Absolute value of the Course Angle Controller's integral part saturation \n\n
 *		@ref P_TCTLGC_CacLaDmcCompEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Enable filter to compensate the LaDMC's transmission behavior \n
 *		0: Disable filter to compensate the LaDMC's transmission behavior \n\n
 *		@ref P_TCTLGC_CacMode_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Course Angle Controller Mode: \n
 *		xxxx xxx0	Controller deactivated \n
 *		xxxx xxx1	P-Controller \n
 *		xxxx xx11	PDT1-Controller, DT1-Controller parallel to the P-Controller \n
 *		xxxx x1x1	PI-Controller, I-Part parallel to the P-Controller \n
 *		xxxx 1xx1	PPT1-Controller, PT1-Part parallel to the P-Controller \n\n
 *		@ref P_TCTLGC_CacOfPGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional master gain of the Course Angle Controller \n\n
 *		@ref P_TCTLGC_CacPGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional master gain of the Course Angle Controller \n\n
 *		@ref P_TCTLGC_CacSfPGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional master gain of the Course Angle Controller \n\n
 *		@ref P_TCTLGC_CssCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Mode of TCTLGC (Curvature interface): \n
 *		Source  |  Controller \n
 *		0000 0000: Off \n
 *		0000 xxx1: FBC active \n
 *		0000 xx1x: FFC active \n
 *		0000 x1xx: DC active \n
 *		0000 1xxx: BAC active \n
 *		0001 0000: Chirp active \n\n
 *		@ref P_TCTLGC_CssDeltaF_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Mode of TCTLGC (Steer Angle interface): \n
 *		Source  |  Controller \n
 *		0000 0000: Off \n
 *		0000 xxx1: FBC active \n
 *		0000 xx1x: FFC active \n
 *		0000 x1xx: DC active \n
 *		0000 1xxx: BAC active \n
 *		0001 0000: Chirp active \n\n
 *		@ref P_TCTLGC_DynIntResetSelect_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTLGC_DynPT1ResetSelect_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		0000 0000 : Dynamic PT1 reset deactivated \n
 *		0000 xxx1 : Reset based on lateral deviation active \n
 *		0000 xx1x : Reset based on driver torque active \n
 *		0000 x1xx : Reset based on standstill active \n\n
 *		@ref P_TCTLGC_IntResMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTLGC_IntResMaxLatErr_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTLGC_IntResMaxManTrq_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TCTLGC_LdcILimit_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_6p28_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 6.28 \n
 *		\@description: \n
 *		Absolute value of the Y-Coordinate Controller's integral part saturation \n\n
 *		@ref P_TCTLGC_LdcLaDmcCompEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Enable filter to compensate the LaDMC's transmission behavior \n
 *		0: Disable filter to compensate the LaDMC's transmission behavior \n\n
 *		@ref P_TCTLGC_LdcMode_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Y-Coordinate Controller Mode: \n
 *		xxxx xxx0	Controller is deactivated \n
 *		xxxx xxx1	P-Controller \n
 *		xxxx xx11	PDT1-Controller, DT1-Controller parallel to the P-Controller \n
 *		xxxx x1x1	PI-Controller, I-Part parallel to the P-Controller \n
 *		xxxx 1xx1	PPT1-Controller, PT1-Part parallel to the P-Controller \n\n
 *		@ref P_TCTLGC_LdcOfP_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional master gain of the Lateral Deviation Controller \n\n
 *		@ref P_TCTLGC_LdcPT1MaxGrd_radpms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpsm_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/sm \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Absolute value of the maximum allowed gradient of the PT1 control signal part of the lateral deviation controller \n\n
 *		@ref P_TCTLGC_LdcP_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpm_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional master gain of the Lateral Deviation Controller \n\n
 *		@ref P_TCTLGC_LdcSfP_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpm_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional master gain of the Lateral Deviation Controller \n\n
 *		@ref P_TCTLGC_MaxDeltaFGrd_dps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_0_360_1em2_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: 0 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum allowed gradient of the steer angle command signal which is send to the LaDMC \n\n
 *		@ref P_TCTLGC_MaxDeltaF_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Maximum allowed steer angle command signal which is send to the LaDMC \n\n
 *		@ref P_TCTLGC_PGainGrdLimit_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_2_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Gradient Limit for P-Gain Transition \n\n
 *		@ref P_TCTLGC_PT1CoAnErrEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Enable low pass first order for filtering the control error regarding the Course Angle \n
 *		0: Disable low pass first order for filtering the control error regarding the Course Angle \n\n
 *		@ref P_TCTLGC_PT1DeltaFCmdEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Enable low pass first order for filtering the control signal DeltaFCmd \n
 *		0: Disable low pass first order for filtering the control signal DeltaFCmd \n\n
 *		@ref P_TCTLGC_PT1YErrEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		1: Enable low pass first order for filtering the control error regarding the Y-Coordinate \n
 *		0: Disable low pass first order for filtering the control error regarding the Y-Coordinate \n\n
 *		@ref P_TCTLGC_StandstillThreshVel_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Definition of standstill for TCTLGC \n\n
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
 *		@ref P_VEH_SelfSteeringGrd_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Self Steering Gradient of the Vehicle \n\n
 *		@ref X_TCTLGC_CrvFFC_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x9x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_TCTLGC_CtrlErrDistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_TCTLGC_Vel_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTLGC_CacDGain_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Course Angle Controller's differential part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacDT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the first order low pass needed to filter the Course Angle Controller's D-part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacIGain_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Gain of the Course Angle Controller's integral part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacOfDGain_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Course Angle Controller's differential part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacOfDT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the first order low pass needed to filter the Course Angle Controller's D-part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacOfIGain_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Gain of the Course Angle Controller's integral part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacOfPGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Course Angle Controller P-Gain for object following mode \n\n
 *		@ref Y_TCTLGC_CacOfPT1Gain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Course Angle Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_CacOfPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time Constant of the Course Angle Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_CacPGainCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_2_1em3_t \n
 *		\@size: 1x9x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTLGC_CacPGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional gain of the Course Angle Controller in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacPT1Gain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Course Angle Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_CacPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time Constant of the Course Angle Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_CacSfDGain_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Course Angle Controller's differential part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacSfDT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the first order low pass needed to filter the Course Angle Controller's D-part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacSfIGain_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Gain of the Course Angle Controller's integral part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacSfPGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional gain of the Course Angle Controller in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_CacSfPT1Gain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Course Angle Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_CacSfPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time Constant of the Course Angle Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_DynBacGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_5_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTLGC_GLaDmcCompNumS0_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		s^0 coefficient of the approximated LaDMC transfer function's numerator \n\n
 *		@ref Y_TCTLGC_GLaDmcCompNumS1_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		s^1 coefficient of the approximated LaDMC transfer function's numerator \n\n
 *		@ref Y_TCTLGC_GLaDmcCompPole1_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_m1000_0_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/s \n
 *		\@min: -1000 \n
 *		\@max: 0 \n
 *		\@description: \n
 *		Pole 1 of the approximated LaDMC transfer function \n\n
 *		@ref Y_TCTLGC_GLaDmcCompPole2_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_m1000_0_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/s \n
 *		\@min: -1000 \n
 *		\@max: 0 \n
 *		\@description: \n
 *		Pole 2 of the approximated LaDMC transfer function \n\n
 *		@ref Y_TCTLGC_LdcDGain_radspm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radspm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rads/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Y-Coorindate Controller's differential part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcDT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the first order low pass needed to filter the Y-Coorindate Controller's D-part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcIGain_radpsm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpsm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rad/sm \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Y-Coordinate Controller's integral part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcOfDGain_radspm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radspm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rads/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Y-Coorindate Controller's differential part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcOfDT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the first order low pass needed to filter the Y-Coorindate Controller's D-part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcOfIGain_radpsm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpsm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rad/sm \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Y-Coordinate Controller's integral part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcOfPT1Gain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Lateral Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_LdcOfPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time Constant of the Lateral Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_LdcOfP_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rad/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lateral Deviation Controller P-Gain for object following mode \n\n
 *		@ref Y_TCTLGC_LdcPGainCrv_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpm_0_2_1em3_t \n
 *		\@size: 1x9x1 \n
 *		\@unit: rad/m \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TCTLGC_LdcPT1Gain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Lateral Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_LdcPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time Constant of the Lateral Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_LdcP_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rad/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional gain of the Y-Coordinate Controller in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcSfDGain_radspm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radspm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rads/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Y-Coorindate Controller's differential part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcSfDT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the first order low pass needed to filter the Y-Coorindate Controller's D-part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcSfIGain_radpsm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpsm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rad/sm \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Y-Coordinate Controller's integral part in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_LdcSfPT1Gain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gain of the Lateral Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_LdcSfPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time Constant of the Lateral Deviation Controller's PT1-Branch \n\n
 *		@ref Y_TCTLGC_LdcSfP_radpm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radpm_0_100_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: rad/m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Proportional gain of the Y-Coordinate Controller in dependence on the vehicle's velocity \n\n
 *		@ref Y_TCTLGC_PT1CoAnErrTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the low pass filter used to filter the control error regarding the Course Angle \n\n
 *		@ref Y_TCTLGC_PT1DeltaFCmdTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Velocity dependend value of the low pass' time constant to filter DeltaFCmd \n\n
 *		@ref Y_TCTLGC_PT1YErrTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the low pass filter used to filter the control error regarding the Y-Coordinate \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TCTLGC Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TCTLGC_Testcase_Initialization) Initialization of the TCTLGC
 *		-# [Testcase_TCTLGC_CommandSourceSelect_DeltaF](@ref TCTLGC_Testcase_TCTLGC_CommandSourceSelect_DeltaF) Test of summation of different control parts (steer angle interface) (Doors ID FCT_CMP_TRJCTR_625)
 *		-# [Testcase_TCTLGC_CommandSourceSelect_Crv](@ref TCTLGC_Testcase_TCTLGC_CommandSourceSelect_Crv) Test of summation of different control parts (curvature interface) (Doors ID FCT_CMP_TRJCTR_625)
 *		-# [Testcase_TCTLGC_ModeTransition](@ref TCTLGC_Testcase_TCTLGC_ModeTransition) Test of transition between control modes
 *		-# [Testcase_TCTLGC_FFC_Limit](@ref TCTLGC_Testcase_TCTLGC_FFC_Limit) Test of FFC Gradient Limitation DOORS ID FCT_CMP_TRJCTR_552
 *		-# [Testcase_TCTLGC_DeltaFCmd_Limit](@ref TCTLGC_Testcase_TCTLGC_DeltaFCmd_Limit) Test of command steering angle (Gradient) Limitation (DOORS ID FCT_CMP_TRJCTR_556, FCT_CMP_TRJCTR_562, FCT_CMP_TRJCTR_627)
 *		-# [Testcase_TCTLGC_CtrlCrv_DE_Limit](@ref TCTLGC_Testcase_TCTLGC_CtrlCrv_DE_Limit) Test of (Gradient) Limitation of S_TCTLGC_CtrlCrv_DE_1pm (DOORS ID: FCT_CMP_TRJCTR_554, FCT_CMP_TRJCTR_560, FCT_CMP_TRJCTR_627
 *		-# [Testcase_TCTLGC_DeltaFCmd_deg](@ref TCTLGC_Testcase_TCTLGC_DeltaFCmd_deg) Test of Freeze and Enable TCTLGC_DeltaFCmd_deg (Doors ID FCT_CMP_TRJCTR_631, FCT_CMP_TRJCTR_632)
 *		-# [Testcase_TCTLGC_CtrlCrv_DE_1pm](@ref TCTLGC_Testcase_TCTLGC_CtrlCrv_DE_1pm) Test of Freeze and Enable S_TCTLGC_CtrlCrv_DE_1pm (Doors ID FCT_CMP_TRJCTR_631, FCT_CMP_TRJCTR_632)
 *		-# [Testcase_TCTLGC_FFCrv_1pm](@ref TCTLGC_Testcase_TCTLGC_FFCrv_1pm) Test of Freeze, Enable and Deactivation S_TCTLGC_FFCrv_1pm (Doors ID FCT_CMP_TRJCTR_631, FCT_CMP_TRJCTR_632)
 *		-# [Testcase_TCTLGC_TgtCrv_DE_1pm](@ref TCTLGC_Testcase_TCTLGC_TgtCrv_DE_1pm) Test of Freeze and Enable S_TCTLGC_TgtCrv_DE_1pm (Doors ID FCT_CMP_TRJCTR_631, FCT_CMP_TRJCTR_632)
 *		-# [Testcase_Reset](@ref TCTLGC_Testcase_Reset) Test Reset Conditions (Doors ID FCT_CMP_TRJCTR_633)
 *		-# [Testcase_CoverSpecialCases](@ref TCTLGC_Testcase_CoverSpecialCases) Testcase only for coverage
 *		-# [Testcase_IntegratorLimits](@ref TCTLGC_Testcase_IntegratorLimits) Test Limits of integrators in LaDMC Compesation
 *		
 *	@traceability
 *		[\@link: TCTLGC Module Requirements]()
 */
extern void TCTLGC_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TCTLGC_H_
