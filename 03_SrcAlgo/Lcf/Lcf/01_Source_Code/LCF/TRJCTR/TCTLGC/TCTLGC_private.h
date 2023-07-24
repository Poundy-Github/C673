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
//! @file     TCTLGC_private.h
//! @brief     (TCTLGC) Module Private Header.

#ifndef TCTLGC_PRIVATE_H_
#define TCTLGC_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJCTR	//!< TRJCTR sub-component input macro switch.
#define TCTLGC	//!< TCTLGC module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTLGC.h"
#include "Bitop.h"  //MFC5J3
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TCTLGC_VehReset		0xF0 //!< TCTLGC module reset runnable identifier.
#define RUNNABLE_ID_TCTLGC_VehProcess	0xF1 //!< TCTLGC module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TCTLGC_VehDbgType *TCTLGC_VehDbgPtr = NULL; //!< TCTLGC module vehicle debug data pointer.
void TCTLGC_VehInitDbgPtr(TCTLGC_VehDbgType *TCTLGC_VehDbgArg) { TCTLGC_VehDbgPtr = TCTLGC_VehDbgPtr == NULL ? TCTLGC_VehDbgArg : TCTLGC_VehDbgPtr; }
const TCTLGC_VehDbgType* TCTLGC_VehGetDbgPtr(void) { return (const TCTLGC_VehDbgType*) TCTLGC_VehDbgPtr; }

static TCTLGC_VehOutType *TCTLGC_VehOutPtr = NULL; //!< TCTLGC module vehicle output data pointer.
void TCTLGC_VehInitOutPtr(TCTLGC_VehOutType *TCTLGC_VehOutArg) { TCTLGC_VehOutPtr = TCTLGC_VehOutPtr == NULL ? TCTLGC_VehOutArg : TCTLGC_VehOutPtr; }
const TCTLGC_VehOutType* TCTLGC_VehGetOutPtr(void) { return (const TCTLGC_VehOutType*) TCTLGC_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTLGC_CacCmd_rad
#define	D_TCTLGC_CacCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacCmd_rad(val)	(D_TCTLGC_CacCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacDT1Cmd_rad
#define	D_TCTLGC_CacDT1Cmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacDT1Cmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacDT1Cmd_rad(val)	(D_TCTLGC_CacDT1Cmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacICmd_rad
#define	D_TCTLGC_CacICmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacICmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacICmd_rad(val)	(D_TCTLGC_CacICmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacIntReset_nu
#define	D_TCTLGC_CacIntReset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_CacIntReset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacIntReset_nu(val)	(D_TCTLGC_CacIntReset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacLaDmcComp_rad
#define	D_TCTLGC_CacLaDmcComp_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacLaDmcComp_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacLaDmcComp_rad(val)	(D_TCTLGC_CacLaDmcComp_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacPCmd_rad
#define	D_TCTLGC_CacPCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacPCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacPCmd_rad(val)	(D_TCTLGC_CacPCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacPT1Cmd_rad
#define	D_TCTLGC_CacPT1Cmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacPT1Cmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacPT1Cmd_rad(val)	(D_TCTLGC_CacPT1Cmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacPT1CoAnErr_rad
#define	D_TCTLGC_CacPT1CoAnErr_rad (TCTLGC_VehDbgPtr->D_TCTLGC_CacPT1CoAnErr_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacPT1CoAnErr_rad(val)	(D_TCTLGC_CacPT1CoAnErr_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CacPT1Reset_nu
#define	D_TCTLGC_CacPT1Reset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_CacPT1Reset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CacPT1Reset_nu(val)	(D_TCTLGC_CacPT1Reset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CrvReqBAC_1pm
#define	D_TCTLGC_CrvReqBAC_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_CrvReqBAC_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CrvReqBAC_1pm(val)	(D_TCTLGC_CrvReqBAC_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CrvReqDte_1pm
#define	D_TCTLGC_CrvReqDte_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_CrvReqDte_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CrvReqDte_1pm(val)	(D_TCTLGC_CrvReqDte_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CrvReqFfcFrz_1pm
#define	D_TCTLGC_CrvReqFfcFrz_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_CrvReqFfcFrz_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CrvReqFfcFrz_1pm(val)	(D_TCTLGC_CrvReqFfcFrz_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CrvReqFfcGrdLimT1_1pm
#define	D_TCTLGC_CrvReqFfcGrdLimT1_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_CrvReqFfcGrdLimT1_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CrvReqFfcGrdLimT1_1pm(val)	(D_TCTLGC_CrvReqFfcGrdLimT1_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CrvReqFfcGrdLimT2_1pm
#define	D_TCTLGC_CrvReqFfcGrdLimT2_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_CrvReqFfcGrdLimT2_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CrvReqFfcGrdLimT2_1pm(val)	(D_TCTLGC_CrvReqFfcGrdLimT2_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_CrvReqFfcGrdLim_1pm
#define	D_TCTLGC_CrvReqFfcGrdLim_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_CrvReqFfcGrdLim_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_CrvReqFfcGrdLim_1pm(val)	(D_TCTLGC_CrvReqFfcGrdLim_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_DeltaFBAC_deg
#define	D_TCTLGC_DeltaFBAC_deg (TCTLGC_VehDbgPtr->D_TCTLGC_DeltaFBAC_deg) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_DeltaFBAC_deg(val)	(D_TCTLGC_DeltaFBAC_deg = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_DeltaFCmdDC_deg
#define	D_TCTLGC_DeltaFCmdDC_deg (TCTLGC_VehDbgPtr->D_TCTLGC_DeltaFCmdDC_deg) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_DeltaFCmdDC_deg(val)	(D_TCTLGC_DeltaFCmdDC_deg = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_DeltaFCmdFFC_deg
#define	D_TCTLGC_DeltaFCmdFFC_deg (TCTLGC_VehDbgPtr->D_TCTLGC_DeltaFCmdFFC_deg) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_DeltaFCmdFFC_deg(val)	(D_TCTLGC_DeltaFCmdFFC_deg = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_DeltaFCmdUnlimited_deg
#define	D_TCTLGC_DeltaFCmdUnlimited_deg (TCTLGC_VehDbgPtr->D_TCTLGC_DeltaFCmdUnlimited_deg) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_DeltaFCmdUnlimited_deg(val)	(D_TCTLGC_DeltaFCmdUnlimited_deg = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_DeltaFCmd_rad
#define	D_TCTLGC_DeltaFCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_DeltaFCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_DeltaFCmd_rad(val)	(D_TCTLGC_DeltaFCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_EnableCtrl_nu
#define	D_TCTLGC_EnableCtrl_nu (TCTLGC_VehDbgPtr->D_TCTLGC_EnableCtrl_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_EnableCtrl_nu(val)	(D_TCTLGC_EnableCtrl_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_Hold_nu
#define	D_TCTLGC_Hold_nu (TCTLGC_VehDbgPtr->D_TCTLGC_Hold_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_Hold_nu(val)	(D_TCTLGC_Hold_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAloneCmd_rad
#define	D_TCTLGC_LdcAloneCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAloneCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAloneCmd_rad(val)	(D_TCTLGC_LdcAloneCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAloneDT1Cmd_rad
#define	D_TCTLGC_LdcAloneDT1Cmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAloneDT1Cmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAloneDT1Cmd_rad(val)	(D_TCTLGC_LdcAloneDT1Cmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAloneICmd_rad
#define	D_TCTLGC_LdcAloneICmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAloneICmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAloneICmd_rad(val)	(D_TCTLGC_LdcAloneICmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAloneIntReset_nu
#define	D_TCTLGC_LdcAloneIntReset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAloneIntReset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAloneIntReset_nu(val)	(D_TCTLGC_LdcAloneIntReset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAloneLaDmcComp_met
#define	D_TCTLGC_LdcAloneLaDmcComp_met (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAloneLaDmcComp_met) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAloneLaDmcComp_met(val)	(D_TCTLGC_LdcAloneLaDmcComp_met = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAlonePCmd_rad
#define	D_TCTLGC_LdcAlonePCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAlonePCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAlonePCmd_rad(val)	(D_TCTLGC_LdcAlonePCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAlonePT1Cmd_rad
#define	D_TCTLGC_LdcAlonePT1Cmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAlonePT1Cmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAlonePT1Cmd_rad(val)	(D_TCTLGC_LdcAlonePT1Cmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAlonePT1Reset_nu
#define	D_TCTLGC_LdcAlonePT1Reset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAlonePT1Reset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAlonePT1Reset_nu(val)	(D_TCTLGC_LdcAlonePT1Reset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcAlonePT1YErr_met
#define	D_TCTLGC_LdcAlonePT1YErr_met (TCTLGC_VehDbgPtr->D_TCTLGC_LdcAlonePT1YErr_met) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcAlonePT1YErr_met(val)	(D_TCTLGC_LdcAlonePT1YErr_met = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcCmd_rad
#define	D_TCTLGC_LdcCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcCmd_rad(val)	(D_TCTLGC_LdcCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcDT1Cmd_rad
#define	D_TCTLGC_LdcDT1Cmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcDT1Cmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcDT1Cmd_rad(val)	(D_TCTLGC_LdcDT1Cmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcICmd_rad
#define	D_TCTLGC_LdcICmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcICmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcICmd_rad(val)	(D_TCTLGC_LdcICmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcIntReset_nu
#define	D_TCTLGC_LdcIntReset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_LdcIntReset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcIntReset_nu(val)	(D_TCTLGC_LdcIntReset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcLaDmcComp_rad
#define	D_TCTLGC_LdcLaDmcComp_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcLaDmcComp_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcLaDmcComp_rad(val)	(D_TCTLGC_LdcLaDmcComp_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcPCmd_rad
#define	D_TCTLGC_LdcPCmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcPCmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcPCmd_rad(val)	(D_TCTLGC_LdcPCmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcPT1Cmd_rad
#define	D_TCTLGC_LdcPT1Cmd_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcPT1Cmd_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcPT1Cmd_rad(val)	(D_TCTLGC_LdcPT1Cmd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcPT1Input_rad
#define	D_TCTLGC_LdcPT1Input_rad (TCTLGC_VehDbgPtr->D_TCTLGC_LdcPT1Input_rad) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcPT1Input_rad(val)	(D_TCTLGC_LdcPT1Input_rad = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_LdcPT1Reset_nu
#define	D_TCTLGC_LdcPT1Reset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_LdcPT1Reset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_LdcPT1Reset_nu(val)	(D_TCTLGC_LdcPT1Reset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_PGainCacGrdLimTrig_nu
#define	D_TCTLGC_PGainCacGrdLimTrig_nu (TCTLGC_VehDbgPtr->D_TCTLGC_PGainCacGrdLimTrig_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_PGainCacGrdLimTrig_nu(val)	(D_TCTLGC_PGainCacGrdLimTrig_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_PGainLdcGrdLimTrig_nu
#define	D_TCTLGC_PGainLdcGrdLimTrig_nu (TCTLGC_VehDbgPtr->D_TCTLGC_PGainLdcGrdLimTrig_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_PGainLdcGrdLimTrig_nu(val)	(D_TCTLGC_PGainLdcGrdLimTrig_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_Reset_nu
#define	D_TCTLGC_Reset_nu (TCTLGC_VehDbgPtr->D_TCTLGC_Reset_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_Reset_nu(val)	(D_TCTLGC_Reset_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_SafetyFunctionActive_nu
#define	D_TCTLGC_SafetyFunctionActive_nu (TCTLGC_VehDbgPtr->D_TCTLGC_SafetyFunctionActive_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_SafetyFunctionActive_nu(val)	(D_TCTLGC_SafetyFunctionActive_nu = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_SumCrvReqFbFrz_1pm
#define	D_TCTLGC_SumCrvReqFbFrz_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_SumCrvReqFbFrz_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_SumCrvReqFbFrz_1pm(val)	(D_TCTLGC_SumCrvReqFbFrz_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_SumCrvReqFbGrdLim_1pm
#define	D_TCTLGC_SumCrvReqFbGrdLim_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_SumCrvReqFbGrdLim_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_SumCrvReqFbGrdLim_1pm(val)	(D_TCTLGC_SumCrvReqFbGrdLim_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_SumCrvReqFbSatLim_1pm
#define	D_TCTLGC_SumCrvReqFbSatLim_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_SumCrvReqFbSatLim_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_SumCrvReqFbSatLim_1pm(val)	(D_TCTLGC_SumCrvReqFbSatLim_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	D_TCTLGC_SumCrvReqFb_1pm
#define	D_TCTLGC_SumCrvReqFb_1pm (TCTLGC_VehDbgPtr->D_TCTLGC_SumCrvReqFb_1pm) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_SumCrvReqFb_1pm(val)	(D_TCTLGC_SumCrvReqFb_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_CtrlCrv_1pm
#define	S_TCTLGC_CtrlCrv_1pm (TCTLGC_VehDbgPtr->S_TCTLGC_CtrlCrv_1pm) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_CtrlCrv_1pm(val)	(S_TCTLGC_CtrlCrv_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_CtrlCrv_DE_1pm
#define	S_TCTLGC_CtrlCrv_DE_1pm (TCTLGC_VehDbgPtr->S_TCTLGC_CtrlCrv_DE_1pm) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_CtrlCrv_DE_1pm(val)	(S_TCTLGC_CtrlCrv_DE_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_CtrlErrHeadAglCrtd_rad
#define	S_TCTLGC_CtrlErrHeadAglCrtd_rad (TCTLGC_VehDbgPtr->S_TCTLGC_CtrlErrHeadAglCrtd_rad) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_CtrlErrHeadAglCrtd_rad(val)	(S_TCTLGC_CtrlErrHeadAglCrtd_rad = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_DeltaFCmd_deg
#define	S_TCTLGC_DeltaFCmd_deg (TCTLGC_VehDbgPtr->S_TCTLGC_DeltaFCmd_deg) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_DeltaFCmd_deg(val)	(S_TCTLGC_DeltaFCmd_deg = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_FFCrv_1pm
#define	S_TCTLGC_FFCrv_1pm (TCTLGC_VehDbgPtr->S_TCTLGC_FFCrv_1pm) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_FFCrv_1pm(val)	(S_TCTLGC_FFCrv_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_TgtCrv_DENoLatSlp_1pm
#define	S_TCTLGC_TgtCrv_DENoLatSlp_1pm (TCTLGC_VehDbgPtr->S_TCTLGC_TgtCrv_DENoLatSlp_1pm) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_TgtCrv_DENoLatSlp_1pm(val)	(S_TCTLGC_TgtCrv_DENoLatSlp_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_TgtCrv_DE_1pm
#define	S_TCTLGC_TgtCrv_DE_1pm (TCTLGC_VehDbgPtr->S_TCTLGC_TgtCrv_DE_1pm) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_TgtCrv_DE_1pm(val)	(S_TCTLGC_TgtCrv_DE_1pm = (val)) //!< TCTLGC debug macro setter.

#undef	S_TCTLGC_TgtCrv_NoDE_1pm
#define	S_TCTLGC_TgtCrv_NoDE_1pm (TCTLGC_VehDbgPtr->S_TCTLGC_TgtCrv_NoDE_1pm) //!< TCTLGC debug macro.
#define	SET_S_TCTLGC_TgtCrv_NoDE_1pm(val)	(S_TCTLGC_TgtCrv_NoDE_1pm = (val)) //!< TCTLGC debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTLGC_ActiveLgcParamSet_nu
#define	D_TCTLGC_ActiveLgcParamSet_nu (TCTLGC_VehOutPtr->D_TCTLGC_ActiveLgcParamSet_nu) //!< TCTLGC debug macro.
#define	SET_D_TCTLGC_ActiveLgcParamSet_nu(val)	(D_TCTLGC_ActiveLgcParamSet_nu = (val)) //!< TCTLGC debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TCTLGC_PRIVATE_H_
