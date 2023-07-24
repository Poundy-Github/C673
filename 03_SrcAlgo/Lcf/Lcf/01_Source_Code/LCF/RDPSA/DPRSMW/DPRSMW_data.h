/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSMW_data.h
//! @brief     (DPRSMW) Module Data Header.

#ifndef DPRSMW_DATA_H_
#define DPRSMW_DATA_H_

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
 *	DPRSMW module sensor get function. Function gets DPRSMW sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRSMW_SenDbgPtr</b> Global static pointer to DPRSMW sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRSMW_SenDbgType* DPRSMW_SenGetDbgPtr(void);

/*!
 *	DPRSMW module sensor get function. Function gets DPRSMW sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRSMW_SenOutPtr</b> Global static pointer to DPRSMW sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRSMW_SenOutType* DPRSMW_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DPRSMW_Cancel_btf
#define D_DPRSMW_Cancel_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_Cancel_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_Cancel_btf() (D_DPRSMW_Cancel_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_Cancel_btf

#ifndef D_DPRSMW_DlcLeThreshold_met
#define D_DPRSMW_DlcLeThreshold_met (DPRSMW_SenGetDbgPtr()->D_DPRSMW_DlcLeThreshold_met) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_DlcLeThreshold_met() (D_DPRSMW_DlcLeThreshold_met) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_DlcLeThreshold_met

#ifndef D_DPRSMW_DlcRiThreshold_met
#define D_DPRSMW_DlcRiThreshold_met (DPRSMW_SenGetDbgPtr()->D_DPRSMW_DlcRiThreshold_met) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_DlcRiThreshold_met() (D_DPRSMW_DlcRiThreshold_met) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_DlcRiThreshold_met

#ifndef D_DPRSMW_DrcLeThreshold_met
#define D_DPRSMW_DrcLeThreshold_met (DPRSMW_SenGetDbgPtr()->D_DPRSMW_DrcLeThreshold_met) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_DrcLeThreshold_met() (D_DPRSMW_DrcLeThreshold_met) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_DrcLeThreshold_met

#ifndef D_DPRSMW_DrcRiThreshold_met
#define D_DPRSMW_DrcRiThreshold_met (DPRSMW_SenGetDbgPtr()->D_DPRSMW_DrcRiThreshold_met) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_DrcRiThreshold_met() (D_DPRSMW_DrcRiThreshold_met) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_DrcRiThreshold_met

#ifndef D_DPRSMW_StrongReady_btf
#define D_DPRSMW_StrongReady_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_StrongReady_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_StrongReady_btf() (D_DPRSMW_StrongReady_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_StrongReady_btf

#ifndef D_DPRSMW_SysStateRDW_btf
#define D_DPRSMW_SysStateRDW_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_SysStateRDW_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_SysStateRDW_btf() (D_DPRSMW_SysStateRDW_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_SysStateRDW_btf

#ifndef D_DPRSMW_TlcLeThreshold_sec
#define D_DPRSMW_TlcLeThreshold_sec (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TlcLeThreshold_sec) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TlcLeThreshold_sec() (D_DPRSMW_TlcLeThreshold_sec) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TlcLeThreshold_sec

#ifndef D_DPRSMW_TlcRiThreshold_sec
#define D_DPRSMW_TlcRiThreshold_sec (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TlcRiThreshold_sec) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TlcRiThreshold_sec() (D_DPRSMW_TlcRiThreshold_sec) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TlcRiThreshold_sec

#ifndef D_DPRSMW_TrcLeThreshold_sec
#define D_DPRSMW_TrcLeThreshold_sec (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TrcLeThreshold_sec) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TrcLeThreshold_sec() (D_DPRSMW_TrcLeThreshold_sec) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TrcLeThreshold_sec

#ifndef D_DPRSMW_TrcRiThreshold_sec
#define D_DPRSMW_TrcRiThreshold_sec (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TrcRiThreshold_sec) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TrcRiThreshold_sec() (D_DPRSMW_TrcRiThreshold_sec) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TrcRiThreshold_sec

#ifndef D_DPRSMW_TriggerLnLe_btf
#define D_DPRSMW_TriggerLnLe_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TriggerLnLe_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TriggerLnLe_btf() (D_DPRSMW_TriggerLnLe_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TriggerLnLe_btf

#ifndef D_DPRSMW_TriggerLnReLe_btf
#define D_DPRSMW_TriggerLnReLe_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TriggerLnReLe_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TriggerLnReLe_btf() (D_DPRSMW_TriggerLnReLe_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TriggerLnReLe_btf

#ifndef D_DPRSMW_TriggerLnReRi_btf
#define D_DPRSMW_TriggerLnReRi_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TriggerLnReRi_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TriggerLnReRi_btf() (D_DPRSMW_TriggerLnReRi_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TriggerLnReRi_btf

#ifndef D_DPRSMW_TriggerLnRi_btf
#define D_DPRSMW_TriggerLnRi_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TriggerLnRi_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TriggerLnRi_btf() (D_DPRSMW_TriggerLnRi_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TriggerLnRi_btf

#ifndef D_DPRSMW_TriggerReLe_btf
#define D_DPRSMW_TriggerReLe_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TriggerReLe_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TriggerReLe_btf() (D_DPRSMW_TriggerReLe_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TriggerReLe_btf

#ifndef D_DPRSMW_TriggerReRi_btf
#define D_DPRSMW_TriggerReRi_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_TriggerReRi_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_TriggerReRi_btf() (D_DPRSMW_TriggerReRi_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_TriggerReRi_btf

#ifndef D_DPRSMW_WeakReady_btf
#define D_DPRSMW_WeakReady_btf (DPRSMW_SenGetDbgPtr()->D_DPRSMW_WeakReady_btf) //!< DPRSMW debug macro.
#define GET_D_DPRSMW_WeakReady_btf() (D_DPRSMW_WeakReady_btf) //!< DPRSMW debug macro getter.
#endif // D_DPRSMW_WeakReady_btf

#ifndef S_DPRSMW_DangerousSide_nu
#define S_DPRSMW_DangerousSide_nu (DPRSMW_SenGetDbgPtr()->S_DPRSMW_DangerousSide_nu) //!< DPRSMW debug macro.
#define GET_S_DPRSMW_DangerousSide_nu() (S_DPRSMW_DangerousSide_nu) //!< DPRSMW debug macro getter.
#endif // S_DPRSMW_DangerousSide_nu

#ifndef S_DPRSMW_ReadyToTrigger_bool
#define S_DPRSMW_ReadyToTrigger_bool (DPRSMW_SenGetDbgPtr()->S_DPRSMW_ReadyToTrigger_bool) //!< DPRSMW debug macro.
#define GET_S_DPRSMW_ReadyToTrigger_bool() (S_DPRSMW_ReadyToTrigger_bool) //!< DPRSMW debug macro getter.
#endif // S_DPRSMW_ReadyToTrigger_bool

#ifndef S_DPRSMW_TriggerReason_nu
#define S_DPRSMW_TriggerReason_nu (DPRSMW_SenGetDbgPtr()->S_DPRSMW_TriggerReason_nu) //!< DPRSMW debug macro.
#define GET_S_DPRSMW_TriggerReason_nu() (S_DPRSMW_TriggerReason_nu) //!< DPRSMW debug macro getter.
#endif // S_DPRSMW_TriggerReason_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPRSMW_SysStateRDWLe_nu
#define S_DPRSMW_SysStateRDWLe_nu (DPRSMW_SenGetOutPtr()->S_DPRSMW_SysStateRDWLe_nu) //!< DPRSMW output macro.
#define GET_S_DPRSMW_SysStateRDWLe_nu() (S_DPRSMW_SysStateRDWLe_nu) //!< DPRSMW output macro getter.
#endif // S_DPRSMW_SysStateRDWLe_nu

#ifndef S_DPRSMW_SysStateRDWRi_nu
#define S_DPRSMW_SysStateRDWRi_nu (DPRSMW_SenGetOutPtr()->S_DPRSMW_SysStateRDWRi_nu) //!< DPRSMW output macro.
#define GET_S_DPRSMW_SysStateRDWRi_nu() (S_DPRSMW_SysStateRDWRi_nu) //!< DPRSMW output macro getter.
#endif // S_DPRSMW_SysStateRDWRi_nu

#ifndef S_DPRSMW_SysStateRDW_nu
#define S_DPRSMW_SysStateRDW_nu (DPRSMW_SenGetOutPtr()->S_DPRSMW_SysStateRDW_nu) //!< DPRSMW output macro.
#define GET_S_DPRSMW_SysStateRDW_nu() (S_DPRSMW_SysStateRDW_nu) //!< DPRSMW output macro getter.
#endif // S_DPRSMW_SysStateRDW_nu

#ifdef __cplusplus
}
#endif

#endif // DPRSMW_DATA_H_
