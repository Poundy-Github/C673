/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSMW_data.h
//! @brief     (DPLSMW) Module Data Header.

#ifndef DPLSMW_DATA_H_
#define DPLSMW_DATA_H_

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
 *	DPLSMW module sensor get function. Function gets DPLSMW sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLSMW_SenDbgPtr</b> Global static pointer to DPLSMW sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLSMW_SenDbgType* DPLSMW_SenGetDbgPtr(void);

/*!
 *	DPLSMW module sensor get function. Function gets DPLSMW sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLSMW_SenOutPtr</b> Global static pointer to DPLSMW sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLSMW_SenOutType* DPLSMW_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DPLSMW_Cancel_btf
#define D_DPLSMW_Cancel_btf (DPLSMW_SenGetDbgPtr()->D_DPLSMW_Cancel_btf) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_Cancel_btf() (D_DPLSMW_Cancel_btf) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_Cancel_btf

#ifndef D_DPLSMW_DlcLeThreshold_met
#define D_DPLSMW_DlcLeThreshold_met (DPLSMW_SenGetDbgPtr()->D_DPLSMW_DlcLeThreshold_met) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_DlcLeThreshold_met() (D_DPLSMW_DlcLeThreshold_met) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_DlcLeThreshold_met

#ifndef D_DPLSMW_DlcRiThreshold_met
#define D_DPLSMW_DlcRiThreshold_met (DPLSMW_SenGetDbgPtr()->D_DPLSMW_DlcRiThreshold_met) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_DlcRiThreshold_met() (D_DPLSMW_DlcRiThreshold_met) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_DlcRiThreshold_met

#ifndef D_DPLSMW_StrongReady_btf
#define D_DPLSMW_StrongReady_btf (DPLSMW_SenGetDbgPtr()->D_DPLSMW_StrongReady_btf) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_StrongReady_btf() (D_DPLSMW_StrongReady_btf) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_StrongReady_btf

#ifndef D_DPLSMW_SysStateLDW_btf
#define D_DPLSMW_SysStateLDW_btf (DPLSMW_SenGetDbgPtr()->D_DPLSMW_SysStateLDW_btf) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_SysStateLDW_btf() (D_DPLSMW_SysStateLDW_btf) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_SysStateLDW_btf

#ifndef D_DPLSMW_TlcLeThreshold_sec
#define D_DPLSMW_TlcLeThreshold_sec (DPLSMW_SenGetDbgPtr()->D_DPLSMW_TlcLeThreshold_sec) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_TlcLeThreshold_sec() (D_DPLSMW_TlcLeThreshold_sec) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_TlcLeThreshold_sec

#ifndef D_DPLSMW_TlcRiThreshold_sec
#define D_DPLSMW_TlcRiThreshold_sec (DPLSMW_SenGetDbgPtr()->D_DPLSMW_TlcRiThreshold_sec) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_TlcRiThreshold_sec() (D_DPLSMW_TlcRiThreshold_sec) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_TlcRiThreshold_sec

#ifndef D_DPLSMW_TriggerLe_btf
#define D_DPLSMW_TriggerLe_btf (DPLSMW_SenGetDbgPtr()->D_DPLSMW_TriggerLe_btf) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_TriggerLe_btf() (D_DPLSMW_TriggerLe_btf) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_TriggerLe_btf

#ifndef D_DPLSMW_TriggerRi_btf
#define D_DPLSMW_TriggerRi_btf (DPLSMW_SenGetDbgPtr()->D_DPLSMW_TriggerRi_btf) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_TriggerRi_btf() (D_DPLSMW_TriggerRi_btf) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_TriggerRi_btf

#ifndef D_DPLSMW_WeakReady_btf
#define D_DPLSMW_WeakReady_btf (DPLSMW_SenGetDbgPtr()->D_DPLSMW_WeakReady_btf) //!< DPLSMW debug macro.
#define GET_D_DPLSMW_WeakReady_btf() (D_DPLSMW_WeakReady_btf) //!< DPLSMW debug macro getter.
#endif // D_DPLSMW_WeakReady_btf

#ifndef S_DPLSMW_DangerousSide_nu
#define S_DPLSMW_DangerousSide_nu (DPLSMW_SenGetDbgPtr()->S_DPLSMW_DangerousSide_nu) //!< DPLSMW debug macro.
#define GET_S_DPLSMW_DangerousSide_nu() (S_DPLSMW_DangerousSide_nu) //!< DPLSMW debug macro getter.
#endif // S_DPLSMW_DangerousSide_nu

#ifndef S_DPLSMW_ReadyToTrigger_bool
#define S_DPLSMW_ReadyToTrigger_bool (DPLSMW_SenGetDbgPtr()->S_DPLSMW_ReadyToTrigger_bool) //!< DPLSMW debug macro.
#define GET_S_DPLSMW_ReadyToTrigger_bool() (S_DPLSMW_ReadyToTrigger_bool) //!< DPLSMW debug macro getter.
#endif // S_DPLSMW_ReadyToTrigger_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPLSMW_SysStateLDWLe_nu
#define S_DPLSMW_SysStateLDWLe_nu (DPLSMW_SenGetOutPtr()->S_DPLSMW_SysStateLDWLe_nu) //!< DPLSMW output macro.
#define GET_S_DPLSMW_SysStateLDWLe_nu() (S_DPLSMW_SysStateLDWLe_nu) //!< DPLSMW output macro getter.
#endif // S_DPLSMW_SysStateLDWLe_nu

#ifndef S_DPLSMW_SysStateLDWRi_nu
#define S_DPLSMW_SysStateLDWRi_nu (DPLSMW_SenGetOutPtr()->S_DPLSMW_SysStateLDWRi_nu) //!< DPLSMW output macro.
#define GET_S_DPLSMW_SysStateLDWRi_nu() (S_DPLSMW_SysStateLDWRi_nu) //!< DPLSMW output macro getter.
#endif // S_DPLSMW_SysStateLDWRi_nu

#ifndef S_DPLSMW_SysStateLDW_nu
#define S_DPLSMW_SysStateLDW_nu (DPLSMW_SenGetOutPtr()->S_DPLSMW_SysStateLDW_nu) //!< DPLSMW output macro.
#define GET_S_DPLSMW_SysStateLDW_nu() (S_DPLSMW_SysStateLDW_nu) //!< DPLSMW output macro getter.
#endif // S_DPLSMW_SysStateLDW_nu

#ifdef __cplusplus
}
#endif

#endif // DPLSMW_DATA_H_
