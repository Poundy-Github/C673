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
//! @file     TCTLGC_type.h
//! @brief     (TCTLGC) Module Type Header.

#ifndef TCTLGC_TYPE_H_
#define TCTLGC_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! TCTLGC module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_CrvReqBAC_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CrvReqBAC_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_CrvReqDte_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CrvReqDte_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_CrvReqFfcFrz_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CrvReqFfcFrz_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_CrvReqFfcGrdLimT1_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CrvReqFfcGrdLimT1_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_CrvReqFfcGrdLimT2_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CrvReqFfcGrdLimT2_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_CrvReqFfcGrdLim_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CrvReqFfcGrdLim_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_SumCrvReqFbFrz_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_SumCrvReqFbFrz_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_SumCrvReqFbGrdLim_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_SumCrvReqFbGrdLim_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_SumCrvReqFbSatLim_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_SumCrvReqFbSatLim_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTLGC_SumCrvReqFb_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_SumCrvReqFb_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTLGC_CtrlCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_CtrlCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTLGC_CtrlCrv_DE_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_CtrlCrv_DE_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTLGC_FFCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_FFCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTLGC_TgtCrv_DENoLatSlp_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_TgtCrv_DENoLatSlp_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTLGC_TgtCrv_DE_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_TgtCrv_DE_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTLGC_TgtCrv_NoDE_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_TgtCrv_NoDE_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_deg_m720_720_1em3_t D_TCTLGC_DeltaFBAC_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_DeltaFBAC_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t D_TCTLGC_DeltaFCmdDC_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_DeltaFCmdDC_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t D_TCTLGC_DeltaFCmdFFC_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_DeltaFCmdFFC_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t D_TCTLGC_DeltaFCmdUnlimited_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_DeltaFCmdUnlimited_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t S_TCTLGC_DeltaFCmd_deg; /*!< @description
	*	Steering Angle Command for DMC \n\n
	*	\@asap_name: S_TCTLGC_DeltaFCmd_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_m_m10_10_1em3_t D_TCTLGC_LdcAloneLaDmcComp_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAloneLaDmcComp_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t D_TCTLGC_LdcAlonePT1YErr_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAlonePT1YErr_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacDT1Cmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacDT1Cmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacICmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacICmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacLaDmcComp_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacLaDmcComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacPCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacPCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacPT1Cmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacPT1Cmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_CacPT1CoAnErr_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacPT1CoAnErr_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m12p57_12p57_1em4_t D_TCTLGC_DeltaFCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_DeltaFCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -12.57 \n
	*	\@max: 12.57
	*/
	
	f32_rad_m6_6_1em3_t S_TCTLGC_CtrlErrHeadAglCrtd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTLGC_CtrlErrHeadAglCrtd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcAloneCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAloneCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcAloneDT1Cmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAloneDT1Cmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcAloneICmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAloneICmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcAlonePCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAlonePCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcAlonePT1Cmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAlonePT1Cmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcDT1Cmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcDT1Cmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcICmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcICmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcLaDmcComp_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcLaDmcComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcPCmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcPCmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcPT1Cmd_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcPT1Cmd_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTLGC_LdcPT1Input_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcPT1Input_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_CacIntReset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacIntReset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_CacPT1Reset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_CacPT1Reset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_EnableCtrl_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_EnableCtrl_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_Hold_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_Hold_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_LdcAloneIntReset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAloneIntReset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_LdcAlonePT1Reset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcAlonePT1Reset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_LdcIntReset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcIntReset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_LdcPT1Reset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_LdcPT1Reset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_PGainCacGrdLimTrig_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_PGainCacGrdLimTrig_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_PGainLdcGrdLimTrig_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_PGainLdcGrdLimTrig_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_Reset_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_Reset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTLGC_SafetyFunctionActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTLGC_SafetyFunctionActive_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TCTLGC_VehDbgType; /*!< @description TCTLGC module vehicle debug data structure for MTS measurement. */

/*! TCTLGC module vehicle output data structure. */
typedef struct
{
	
	u8_NoUnit_1_3_0_1_t D_TCTLGC_ActiveLgcParamSet_nu; /*!< @description
	*	Active LGC Paramter Set: \n
	*	1: Lane Centering \n
	*	2: Object Following \n
	*	3: Safety Function \n\n
	*	\@asap_name: D_TCTLGC_ActiveLgcParamSet_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 3
	*/
	
} TCTLGC_VehOutType; /*!< @description TCTLGC module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TCTLGC_TYPE_H_
