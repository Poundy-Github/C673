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
//! @file     TCTLGC_data.h
//! @brief     (TCTLGC) Module Data Header.

#ifndef TCTLGC_DATA_H_
#define TCTLGC_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH/LCFVEH_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TCTLGC module vehicle get function. Function gets TCTLGC vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTLGC_VehDbgPtr</b> Global static pointer to TCTLGC vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTLGC_VehDbgType* TCTLGC_VehGetDbgPtr(void);

/*!
 *	TCTLGC module vehicle get function. Function gets TCTLGC vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTLGC_VehOutPtr</b> Global static pointer to TCTLGC vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTLGC_VehOutType* TCTLGC_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTLGC_CacCmd_rad
#define D_TCTLGC_CacCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacCmd_rad() (D_TCTLGC_CacCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacCmd_rad

#ifndef D_TCTLGC_CacDT1Cmd_rad
#define D_TCTLGC_CacDT1Cmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacDT1Cmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacDT1Cmd_rad() (D_TCTLGC_CacDT1Cmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacDT1Cmd_rad

#ifndef D_TCTLGC_CacICmd_rad
#define D_TCTLGC_CacICmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacICmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacICmd_rad() (D_TCTLGC_CacICmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacICmd_rad

#ifndef D_TCTLGC_CacIntReset_nu
#define D_TCTLGC_CacIntReset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacIntReset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacIntReset_nu() (D_TCTLGC_CacIntReset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacIntReset_nu

#ifndef D_TCTLGC_CacLaDmcComp_rad
#define D_TCTLGC_CacLaDmcComp_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacLaDmcComp_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacLaDmcComp_rad() (D_TCTLGC_CacLaDmcComp_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacLaDmcComp_rad

#ifndef D_TCTLGC_CacPCmd_rad
#define D_TCTLGC_CacPCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacPCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacPCmd_rad() (D_TCTLGC_CacPCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacPCmd_rad

#ifndef D_TCTLGC_CacPT1Cmd_rad
#define D_TCTLGC_CacPT1Cmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacPT1Cmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacPT1Cmd_rad() (D_TCTLGC_CacPT1Cmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacPT1Cmd_rad

#ifndef D_TCTLGC_CacPT1CoAnErr_rad
#define D_TCTLGC_CacPT1CoAnErr_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacPT1CoAnErr_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacPT1CoAnErr_rad() (D_TCTLGC_CacPT1CoAnErr_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacPT1CoAnErr_rad

#ifndef D_TCTLGC_CacPT1Reset_nu
#define D_TCTLGC_CacPT1Reset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CacPT1Reset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CacPT1Reset_nu() (D_TCTLGC_CacPT1Reset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CacPT1Reset_nu

#ifndef D_TCTLGC_CrvReqBAC_1pm
#define D_TCTLGC_CrvReqBAC_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CrvReqBAC_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CrvReqBAC_1pm() (D_TCTLGC_CrvReqBAC_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CrvReqBAC_1pm

#ifndef D_TCTLGC_CrvReqDte_1pm
#define D_TCTLGC_CrvReqDte_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CrvReqDte_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CrvReqDte_1pm() (D_TCTLGC_CrvReqDte_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CrvReqDte_1pm

#ifndef D_TCTLGC_CrvReqFfcFrz_1pm
#define D_TCTLGC_CrvReqFfcFrz_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CrvReqFfcFrz_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CrvReqFfcFrz_1pm() (D_TCTLGC_CrvReqFfcFrz_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CrvReqFfcFrz_1pm

#ifndef D_TCTLGC_CrvReqFfcGrdLimT1_1pm
#define D_TCTLGC_CrvReqFfcGrdLimT1_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CrvReqFfcGrdLimT1_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CrvReqFfcGrdLimT1_1pm() (D_TCTLGC_CrvReqFfcGrdLimT1_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CrvReqFfcGrdLimT1_1pm

#ifndef D_TCTLGC_CrvReqFfcGrdLimT2_1pm
#define D_TCTLGC_CrvReqFfcGrdLimT2_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CrvReqFfcGrdLimT2_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CrvReqFfcGrdLimT2_1pm() (D_TCTLGC_CrvReqFfcGrdLimT2_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CrvReqFfcGrdLimT2_1pm

#ifndef D_TCTLGC_CrvReqFfcGrdLim_1pm
#define D_TCTLGC_CrvReqFfcGrdLim_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_CrvReqFfcGrdLim_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_CrvReqFfcGrdLim_1pm() (D_TCTLGC_CrvReqFfcGrdLim_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_CrvReqFfcGrdLim_1pm

#ifndef D_TCTLGC_DeltaFBAC_deg
#define D_TCTLGC_DeltaFBAC_deg (TCTLGC_VehGetDbgPtr()->D_TCTLGC_DeltaFBAC_deg) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_DeltaFBAC_deg() (D_TCTLGC_DeltaFBAC_deg) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_DeltaFBAC_deg

#ifndef D_TCTLGC_DeltaFCmdDC_deg
#define D_TCTLGC_DeltaFCmdDC_deg (TCTLGC_VehGetDbgPtr()->D_TCTLGC_DeltaFCmdDC_deg) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_DeltaFCmdDC_deg() (D_TCTLGC_DeltaFCmdDC_deg) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_DeltaFCmdDC_deg

#ifndef D_TCTLGC_DeltaFCmdFFC_deg
#define D_TCTLGC_DeltaFCmdFFC_deg (TCTLGC_VehGetDbgPtr()->D_TCTLGC_DeltaFCmdFFC_deg) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_DeltaFCmdFFC_deg() (D_TCTLGC_DeltaFCmdFFC_deg) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_DeltaFCmdFFC_deg

#ifndef D_TCTLGC_DeltaFCmdUnlimited_deg
#define D_TCTLGC_DeltaFCmdUnlimited_deg (TCTLGC_VehGetDbgPtr()->D_TCTLGC_DeltaFCmdUnlimited_deg) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_DeltaFCmdUnlimited_deg() (D_TCTLGC_DeltaFCmdUnlimited_deg) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_DeltaFCmdUnlimited_deg

#ifndef D_TCTLGC_DeltaFCmd_rad
#define D_TCTLGC_DeltaFCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_DeltaFCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_DeltaFCmd_rad() (D_TCTLGC_DeltaFCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_DeltaFCmd_rad

#ifndef D_TCTLGC_EnableCtrl_nu
#define D_TCTLGC_EnableCtrl_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_EnableCtrl_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_EnableCtrl_nu() (D_TCTLGC_EnableCtrl_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_EnableCtrl_nu

#ifndef D_TCTLGC_Hold_nu
#define D_TCTLGC_Hold_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_Hold_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_Hold_nu() (D_TCTLGC_Hold_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_Hold_nu

#ifndef D_TCTLGC_LdcAloneCmd_rad
#define D_TCTLGC_LdcAloneCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAloneCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAloneCmd_rad() (D_TCTLGC_LdcAloneCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAloneCmd_rad

#ifndef D_TCTLGC_LdcAloneDT1Cmd_rad
#define D_TCTLGC_LdcAloneDT1Cmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAloneDT1Cmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAloneDT1Cmd_rad() (D_TCTLGC_LdcAloneDT1Cmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAloneDT1Cmd_rad

#ifndef D_TCTLGC_LdcAloneICmd_rad
#define D_TCTLGC_LdcAloneICmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAloneICmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAloneICmd_rad() (D_TCTLGC_LdcAloneICmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAloneICmd_rad

#ifndef D_TCTLGC_LdcAloneIntReset_nu
#define D_TCTLGC_LdcAloneIntReset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAloneIntReset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAloneIntReset_nu() (D_TCTLGC_LdcAloneIntReset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAloneIntReset_nu

#ifndef D_TCTLGC_LdcAloneLaDmcComp_met
#define D_TCTLGC_LdcAloneLaDmcComp_met (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAloneLaDmcComp_met) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAloneLaDmcComp_met() (D_TCTLGC_LdcAloneLaDmcComp_met) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAloneLaDmcComp_met

#ifndef D_TCTLGC_LdcAlonePCmd_rad
#define D_TCTLGC_LdcAlonePCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAlonePCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAlonePCmd_rad() (D_TCTLGC_LdcAlonePCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAlonePCmd_rad

#ifndef D_TCTLGC_LdcAlonePT1Cmd_rad
#define D_TCTLGC_LdcAlonePT1Cmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAlonePT1Cmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAlonePT1Cmd_rad() (D_TCTLGC_LdcAlonePT1Cmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAlonePT1Cmd_rad

#ifndef D_TCTLGC_LdcAlonePT1Reset_nu
#define D_TCTLGC_LdcAlonePT1Reset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAlonePT1Reset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAlonePT1Reset_nu() (D_TCTLGC_LdcAlonePT1Reset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAlonePT1Reset_nu

#ifndef D_TCTLGC_LdcAlonePT1YErr_met
#define D_TCTLGC_LdcAlonePT1YErr_met (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcAlonePT1YErr_met) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcAlonePT1YErr_met() (D_TCTLGC_LdcAlonePT1YErr_met) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcAlonePT1YErr_met

#ifndef D_TCTLGC_LdcCmd_rad
#define D_TCTLGC_LdcCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcCmd_rad() (D_TCTLGC_LdcCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcCmd_rad

#ifndef D_TCTLGC_LdcDT1Cmd_rad
#define D_TCTLGC_LdcDT1Cmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcDT1Cmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcDT1Cmd_rad() (D_TCTLGC_LdcDT1Cmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcDT1Cmd_rad

#ifndef D_TCTLGC_LdcICmd_rad
#define D_TCTLGC_LdcICmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcICmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcICmd_rad() (D_TCTLGC_LdcICmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcICmd_rad

#ifndef D_TCTLGC_LdcIntReset_nu
#define D_TCTLGC_LdcIntReset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcIntReset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcIntReset_nu() (D_TCTLGC_LdcIntReset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcIntReset_nu

#ifndef D_TCTLGC_LdcLaDmcComp_rad
#define D_TCTLGC_LdcLaDmcComp_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcLaDmcComp_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcLaDmcComp_rad() (D_TCTLGC_LdcLaDmcComp_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcLaDmcComp_rad

#ifndef D_TCTLGC_LdcPCmd_rad
#define D_TCTLGC_LdcPCmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcPCmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcPCmd_rad() (D_TCTLGC_LdcPCmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcPCmd_rad

#ifndef D_TCTLGC_LdcPT1Cmd_rad
#define D_TCTLGC_LdcPT1Cmd_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcPT1Cmd_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcPT1Cmd_rad() (D_TCTLGC_LdcPT1Cmd_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcPT1Cmd_rad

#ifndef D_TCTLGC_LdcPT1Input_rad
#define D_TCTLGC_LdcPT1Input_rad (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcPT1Input_rad) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcPT1Input_rad() (D_TCTLGC_LdcPT1Input_rad) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcPT1Input_rad

#ifndef D_TCTLGC_LdcPT1Reset_nu
#define D_TCTLGC_LdcPT1Reset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_LdcPT1Reset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_LdcPT1Reset_nu() (D_TCTLGC_LdcPT1Reset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_LdcPT1Reset_nu

#ifndef D_TCTLGC_PGainCacGrdLimTrig_nu
#define D_TCTLGC_PGainCacGrdLimTrig_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_PGainCacGrdLimTrig_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_PGainCacGrdLimTrig_nu() (D_TCTLGC_PGainCacGrdLimTrig_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_PGainCacGrdLimTrig_nu

#ifndef D_TCTLGC_PGainLdcGrdLimTrig_nu
#define D_TCTLGC_PGainLdcGrdLimTrig_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_PGainLdcGrdLimTrig_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_PGainLdcGrdLimTrig_nu() (D_TCTLGC_PGainLdcGrdLimTrig_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_PGainLdcGrdLimTrig_nu

#ifndef D_TCTLGC_Reset_nu
#define D_TCTLGC_Reset_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_Reset_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_Reset_nu() (D_TCTLGC_Reset_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_Reset_nu

#ifndef D_TCTLGC_SafetyFunctionActive_nu
#define D_TCTLGC_SafetyFunctionActive_nu (TCTLGC_VehGetDbgPtr()->D_TCTLGC_SafetyFunctionActive_nu) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_SafetyFunctionActive_nu() (D_TCTLGC_SafetyFunctionActive_nu) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_SafetyFunctionActive_nu

#ifndef D_TCTLGC_SumCrvReqFbFrz_1pm
#define D_TCTLGC_SumCrvReqFbFrz_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_SumCrvReqFbFrz_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_SumCrvReqFbFrz_1pm() (D_TCTLGC_SumCrvReqFbFrz_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_SumCrvReqFbFrz_1pm

#ifndef D_TCTLGC_SumCrvReqFbGrdLim_1pm
#define D_TCTLGC_SumCrvReqFbGrdLim_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_SumCrvReqFbGrdLim_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_SumCrvReqFbGrdLim_1pm() (D_TCTLGC_SumCrvReqFbGrdLim_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_SumCrvReqFbGrdLim_1pm

#ifndef D_TCTLGC_SumCrvReqFbSatLim_1pm
#define D_TCTLGC_SumCrvReqFbSatLim_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_SumCrvReqFbSatLim_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_SumCrvReqFbSatLim_1pm() (D_TCTLGC_SumCrvReqFbSatLim_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_SumCrvReqFbSatLim_1pm

#ifndef D_TCTLGC_SumCrvReqFb_1pm
#define D_TCTLGC_SumCrvReqFb_1pm (TCTLGC_VehGetDbgPtr()->D_TCTLGC_SumCrvReqFb_1pm) //!< TCTLGC debug macro.
#define GET_D_TCTLGC_SumCrvReqFb_1pm() (D_TCTLGC_SumCrvReqFb_1pm) //!< TCTLGC debug macro getter.
#endif // D_TCTLGC_SumCrvReqFb_1pm

#ifndef S_TCTLGC_CtrlCrv_1pm
#define S_TCTLGC_CtrlCrv_1pm (TCTLGC_VehGetDbgPtr()->S_TCTLGC_CtrlCrv_1pm) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_CtrlCrv_1pm() (S_TCTLGC_CtrlCrv_1pm) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_CtrlCrv_1pm

#ifndef S_TCTLGC_CtrlCrv_DE_1pm
#define S_TCTLGC_CtrlCrv_DE_1pm (TCTLGC_VehGetDbgPtr()->S_TCTLGC_CtrlCrv_DE_1pm) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_CtrlCrv_DE_1pm() (S_TCTLGC_CtrlCrv_DE_1pm) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_CtrlCrv_DE_1pm

#ifndef S_TCTLGC_CtrlErrHeadAglCrtd_rad
#define S_TCTLGC_CtrlErrHeadAglCrtd_rad (TCTLGC_VehGetDbgPtr()->S_TCTLGC_CtrlErrHeadAglCrtd_rad) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_CtrlErrHeadAglCrtd_rad() (S_TCTLGC_CtrlErrHeadAglCrtd_rad) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_CtrlErrHeadAglCrtd_rad

#ifndef S_TCTLGC_DeltaFCmd_deg
#define S_TCTLGC_DeltaFCmd_deg (TCTLGC_VehGetDbgPtr()->S_TCTLGC_DeltaFCmd_deg) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_DeltaFCmd_deg() (S_TCTLGC_DeltaFCmd_deg) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_DeltaFCmd_deg

#ifndef S_TCTLGC_FFCrv_1pm
#define S_TCTLGC_FFCrv_1pm (TCTLGC_VehGetDbgPtr()->S_TCTLGC_FFCrv_1pm) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_FFCrv_1pm() (S_TCTLGC_FFCrv_1pm) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_FFCrv_1pm

#ifndef S_TCTLGC_TgtCrv_DENoLatSlp_1pm
#define S_TCTLGC_TgtCrv_DENoLatSlp_1pm (TCTLGC_VehGetDbgPtr()->S_TCTLGC_TgtCrv_DENoLatSlp_1pm) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_TgtCrv_DENoLatSlp_1pm() (S_TCTLGC_TgtCrv_DENoLatSlp_1pm) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_TgtCrv_DENoLatSlp_1pm

#ifndef S_TCTLGC_TgtCrv_DE_1pm
#define S_TCTLGC_TgtCrv_DE_1pm (TCTLGC_VehGetDbgPtr()->S_TCTLGC_TgtCrv_DE_1pm) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_TgtCrv_DE_1pm() (S_TCTLGC_TgtCrv_DE_1pm) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_TgtCrv_DE_1pm

#ifndef S_TCTLGC_TgtCrv_NoDE_1pm
#define S_TCTLGC_TgtCrv_NoDE_1pm (TCTLGC_VehGetDbgPtr()->S_TCTLGC_TgtCrv_NoDE_1pm) //!< TCTLGC debug macro.
#define GET_S_TCTLGC_TgtCrv_NoDE_1pm() (S_TCTLGC_TgtCrv_NoDE_1pm) //!< TCTLGC debug macro getter.
#endif // S_TCTLGC_TgtCrv_NoDE_1pm

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTLGC_ActiveLgcParamSet_nu
#define D_TCTLGC_ActiveLgcParamSet_nu (TCTLGC_VehGetOutPtr()->D_TCTLGC_ActiveLgcParamSet_nu) //!< TCTLGC output macro.
#define GET_D_TCTLGC_ActiveLgcParamSet_nu() (D_TCTLGC_ActiveLgcParamSet_nu) //!< TCTLGC output macro getter.
#endif // D_TCTLGC_ActiveLgcParamSet_nu

#ifdef __cplusplus
}
#endif

#endif // TCTLGC_DATA_H_
