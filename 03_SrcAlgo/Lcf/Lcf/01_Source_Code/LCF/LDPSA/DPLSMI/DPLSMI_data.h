/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSMI_data.h
//! @brief     (DPLSMI) Module Data Header.

#ifndef DPLSMI_DATA_H_
#define DPLSMI_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DPLSMI module sensor get function. Function gets DPLSMI sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLSMI_SenDbgPtr</b> Global static pointer to DPLSMI sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLSMI_SenDbgType* DPLSMI_SenGetDbgPtr(void);

/*!
 *	DPLSMI module sensor get function. Function gets DPLSMI sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLSMI_SenOutPtr</b> Global static pointer to DPLSMI sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLSMI_SenOutType* DPLSMI_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DPLSMI_Cancel_btf
#define D_DPLSMI_Cancel_btf (DPLSMI_SenGetDbgPtr()->D_DPLSMI_Cancel_btf) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_Cancel_btf() (D_DPLSMI_Cancel_btf) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_Cancel_btf

#ifndef D_DPLSMI_DlcLeThreshold_met
#define D_DPLSMI_DlcLeThreshold_met (DPLSMI_SenGetDbgPtr()->D_DPLSMI_DlcLeThreshold_met) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_DlcLeThreshold_met() (D_DPLSMI_DlcLeThreshold_met) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_DlcLeThreshold_met

#ifndef D_DPLSMI_DlcRiThreshold_met
#define D_DPLSMI_DlcRiThreshold_met (DPLSMI_SenGetDbgPtr()->D_DPLSMI_DlcRiThreshold_met) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_DlcRiThreshold_met() (D_DPLSMI_DlcRiThreshold_met) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_DlcRiThreshold_met

#ifndef D_DPLSMI_StrongReady_btf
#define D_DPLSMI_StrongReady_btf (DPLSMI_SenGetDbgPtr()->D_DPLSMI_StrongReady_btf) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_StrongReady_btf() (D_DPLSMI_StrongReady_btf) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_StrongReady_btf

#ifndef D_DPLSMI_SysStateLDP_btf
#define D_DPLSMI_SysStateLDP_btf (DPLSMI_SenGetDbgPtr()->D_DPLSMI_SysStateLDP_btf) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_SysStateLDP_btf() (D_DPLSMI_SysStateLDP_btf) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_SysStateLDP_btf

#ifndef D_DPLSMI_TlcLeThreshold_sec
#define D_DPLSMI_TlcLeThreshold_sec (DPLSMI_SenGetDbgPtr()->D_DPLSMI_TlcLeThreshold_sec) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_TlcLeThreshold_sec() (D_DPLSMI_TlcLeThreshold_sec) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_TlcLeThreshold_sec

#ifndef D_DPLSMI_TlcRiThreshold_sec
#define D_DPLSMI_TlcRiThreshold_sec (DPLSMI_SenGetDbgPtr()->D_DPLSMI_TlcRiThreshold_sec) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_TlcRiThreshold_sec() (D_DPLSMI_TlcRiThreshold_sec) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_TlcRiThreshold_sec

#ifndef D_DPLSMI_TriggerLe_btf
#define D_DPLSMI_TriggerLe_btf (DPLSMI_SenGetDbgPtr()->D_DPLSMI_TriggerLe_btf) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_TriggerLe_btf() (D_DPLSMI_TriggerLe_btf) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_TriggerLe_btf

#ifndef D_DPLSMI_TriggerRi_btf
#define D_DPLSMI_TriggerRi_btf (DPLSMI_SenGetDbgPtr()->D_DPLSMI_TriggerRi_btf) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_TriggerRi_btf() (D_DPLSMI_TriggerRi_btf) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_TriggerRi_btf

#ifndef D_DPLSMI_WeakReady_btf
#define D_DPLSMI_WeakReady_btf (DPLSMI_SenGetDbgPtr()->D_DPLSMI_WeakReady_btf) //!< DPLSMI debug macro.
#define GET_D_DPLSMI_WeakReady_btf() (D_DPLSMI_WeakReady_btf) //!< DPLSMI debug macro getter.
#endif // D_DPLSMI_WeakReady_btf

#ifndef S_DPLSMI_DangerousSide_nu
#define S_DPLSMI_DangerousSide_nu (DPLSMI_SenGetDbgPtr()->S_DPLSMI_DangerousSide_nu) //!< DPLSMI debug macro.
#define GET_S_DPLSMI_DangerousSide_nu() (S_DPLSMI_DangerousSide_nu) //!< DPLSMI debug macro getter.
#endif // S_DPLSMI_DangerousSide_nu

#ifndef S_DPLSMI_FunctionAborted_bool
#define S_DPLSMI_FunctionAborted_bool (DPLSMI_SenGetDbgPtr()->S_DPLSMI_FunctionAborted_bool) //!< DPLSMI debug macro.
#define GET_S_DPLSMI_FunctionAborted_bool() (S_DPLSMI_FunctionAborted_bool) //!< DPLSMI debug macro getter.
#endif // S_DPLSMI_FunctionAborted_bool

#ifndef S_DPLSMI_ReadyToTrigger_bool
#define S_DPLSMI_ReadyToTrigger_bool (DPLSMI_SenGetDbgPtr()->S_DPLSMI_ReadyToTrigger_bool) //!< DPLSMI debug macro.
#define GET_S_DPLSMI_ReadyToTrigger_bool() (S_DPLSMI_ReadyToTrigger_bool) //!< DPLSMI debug macro getter.
#endif // S_DPLSMI_ReadyToTrigger_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPLSMI_SysStateLDPLe_nu
#define S_DPLSMI_SysStateLDPLe_nu (DPLSMI_SenGetOutPtr()->S_DPLSMI_SysStateLDPLe_nu) //!< DPLSMI output macro.
#define GET_S_DPLSMI_SysStateLDPLe_nu() (S_DPLSMI_SysStateLDPLe_nu) //!< DPLSMI output macro getter.
#endif // S_DPLSMI_SysStateLDPLe_nu

#ifndef S_DPLSMI_SysStateLDPRi_nu
#define S_DPLSMI_SysStateLDPRi_nu (DPLSMI_SenGetOutPtr()->S_DPLSMI_SysStateLDPRi_nu) //!< DPLSMI output macro.
#define GET_S_DPLSMI_SysStateLDPRi_nu() (S_DPLSMI_SysStateLDPRi_nu) //!< DPLSMI output macro getter.
#endif // S_DPLSMI_SysStateLDPRi_nu

#ifndef S_DPLSMI_SysStateLDP_nu
#define S_DPLSMI_SysStateLDP_nu (DPLSMI_SenGetOutPtr()->S_DPLSMI_SysStateLDP_nu) //!< DPLSMI output macro.
#define GET_S_DPLSMI_SysStateLDP_nu() (S_DPLSMI_SysStateLDP_nu) //!< DPLSMI output macro getter.
#endif // S_DPLSMI_SysStateLDP_nu

#ifdef __cplusplus
}
#endif

#endif // DPLSMI_DATA_H_
