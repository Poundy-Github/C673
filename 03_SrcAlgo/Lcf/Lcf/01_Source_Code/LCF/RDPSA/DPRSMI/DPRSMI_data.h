/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSMI_data.h
//! @brief     (DPRSMI) Module Data Header.

#ifndef DPRSMI_DATA_H_
#define DPRSMI_DATA_H_

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
 *	DPRSMI module sensor get function. Function gets DPRSMI sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRSMI_SenDbgPtr</b> Global static pointer to DPRSMI sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRSMI_SenDbgType* DPRSMI_SenGetDbgPtr(void);

/*!
 *	DPRSMI module sensor get function. Function gets DPRSMI sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRSMI_SenOutPtr</b> Global static pointer to DPRSMI sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRSMI_SenOutType* DPRSMI_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DPRSMI_Cancel_btf
#define D_DPRSMI_Cancel_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_Cancel_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_Cancel_btf() (D_DPRSMI_Cancel_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_Cancel_btf

#ifndef D_DPRSMI_DlcLeThreshold_met
#define D_DPRSMI_DlcLeThreshold_met (DPRSMI_SenGetDbgPtr()->D_DPRSMI_DlcLeThreshold_met) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_DlcLeThreshold_met() (D_DPRSMI_DlcLeThreshold_met) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_DlcLeThreshold_met

#ifndef D_DPRSMI_DlcRiThreshold_met
#define D_DPRSMI_DlcRiThreshold_met (DPRSMI_SenGetDbgPtr()->D_DPRSMI_DlcRiThreshold_met) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_DlcRiThreshold_met() (D_DPRSMI_DlcRiThreshold_met) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_DlcRiThreshold_met

#ifndef D_DPRSMI_DrcLeThreshold_met
#define D_DPRSMI_DrcLeThreshold_met (DPRSMI_SenGetDbgPtr()->D_DPRSMI_DrcLeThreshold_met) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_DrcLeThreshold_met() (D_DPRSMI_DrcLeThreshold_met) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_DrcLeThreshold_met

#ifndef D_DPRSMI_DrcRiThreshold_met
#define D_DPRSMI_DrcRiThreshold_met (DPRSMI_SenGetDbgPtr()->D_DPRSMI_DrcRiThreshold_met) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_DrcRiThreshold_met() (D_DPRSMI_DrcRiThreshold_met) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_DrcRiThreshold_met

#ifndef D_DPRSMI_StrongReady_btf
#define D_DPRSMI_StrongReady_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_StrongReady_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_StrongReady_btf() (D_DPRSMI_StrongReady_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_StrongReady_btf

#ifndef D_DPRSMI_SysStateRDP_btf
#define D_DPRSMI_SysStateRDP_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_SysStateRDP_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_SysStateRDP_btf() (D_DPRSMI_SysStateRDP_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_SysStateRDP_btf

#ifndef D_DPRSMI_TlcLeThreshold_sec
#define D_DPRSMI_TlcLeThreshold_sec (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TlcLeThreshold_sec) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TlcLeThreshold_sec() (D_DPRSMI_TlcLeThreshold_sec) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TlcLeThreshold_sec

#ifndef D_DPRSMI_TlcRiThreshold_sec
#define D_DPRSMI_TlcRiThreshold_sec (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TlcRiThreshold_sec) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TlcRiThreshold_sec() (D_DPRSMI_TlcRiThreshold_sec) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TlcRiThreshold_sec

#ifndef D_DPRSMI_TrcLeThreshold_sec
#define D_DPRSMI_TrcLeThreshold_sec (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TrcLeThreshold_sec) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TrcLeThreshold_sec() (D_DPRSMI_TrcLeThreshold_sec) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TrcLeThreshold_sec

#ifndef D_DPRSMI_TrcRiThreshold_sec
#define D_DPRSMI_TrcRiThreshold_sec (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TrcRiThreshold_sec) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TrcRiThreshold_sec() (D_DPRSMI_TrcRiThreshold_sec) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TrcRiThreshold_sec

#ifndef D_DPRSMI_TriggerLnLe_btf
#define D_DPRSMI_TriggerLnLe_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TriggerLnLe_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TriggerLnLe_btf() (D_DPRSMI_TriggerLnLe_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TriggerLnLe_btf

#ifndef D_DPRSMI_TriggerLnReLe_btf
#define D_DPRSMI_TriggerLnReLe_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TriggerLnReLe_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TriggerLnReLe_btf() (D_DPRSMI_TriggerLnReLe_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TriggerLnReLe_btf

#ifndef D_DPRSMI_TriggerLnReRi_btf
#define D_DPRSMI_TriggerLnReRi_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TriggerLnReRi_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TriggerLnReRi_btf() (D_DPRSMI_TriggerLnReRi_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TriggerLnReRi_btf

#ifndef D_DPRSMI_TriggerLnRi_btf
#define D_DPRSMI_TriggerLnRi_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TriggerLnRi_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TriggerLnRi_btf() (D_DPRSMI_TriggerLnRi_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TriggerLnRi_btf

#ifndef D_DPRSMI_TriggerReLe_btf
#define D_DPRSMI_TriggerReLe_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TriggerReLe_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TriggerReLe_btf() (D_DPRSMI_TriggerReLe_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TriggerReLe_btf

#ifndef D_DPRSMI_TriggerReRi_btf
#define D_DPRSMI_TriggerReRi_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_TriggerReRi_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_TriggerReRi_btf() (D_DPRSMI_TriggerReRi_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_TriggerReRi_btf

#ifndef D_DPRSMI_WeakReady_btf
#define D_DPRSMI_WeakReady_btf (DPRSMI_SenGetDbgPtr()->D_DPRSMI_WeakReady_btf) //!< DPRSMI debug macro.
#define GET_D_DPRSMI_WeakReady_btf() (D_DPRSMI_WeakReady_btf) //!< DPRSMI debug macro getter.
#endif // D_DPRSMI_WeakReady_btf

#ifndef S_DPRSMI_DangerousSide_nu
#define S_DPRSMI_DangerousSide_nu (DPRSMI_SenGetDbgPtr()->S_DPRSMI_DangerousSide_nu) //!< DPRSMI debug macro.
#define GET_S_DPRSMI_DangerousSide_nu() (S_DPRSMI_DangerousSide_nu) //!< DPRSMI debug macro getter.
#endif // S_DPRSMI_DangerousSide_nu

#ifndef S_DPRSMI_FunctionAborted_bool
#define S_DPRSMI_FunctionAborted_bool (DPRSMI_SenGetDbgPtr()->S_DPRSMI_FunctionAborted_bool) //!< DPRSMI debug macro.
#define GET_S_DPRSMI_FunctionAborted_bool() (S_DPRSMI_FunctionAborted_bool) //!< DPRSMI debug macro getter.
#endif // S_DPRSMI_FunctionAborted_bool

#ifndef S_DPRSMI_ReadyToTrigger_bool
#define S_DPRSMI_ReadyToTrigger_bool (DPRSMI_SenGetDbgPtr()->S_DPRSMI_ReadyToTrigger_bool) //!< DPRSMI debug macro.
#define GET_S_DPRSMI_ReadyToTrigger_bool() (S_DPRSMI_ReadyToTrigger_bool) //!< DPRSMI debug macro getter.
#endif // S_DPRSMI_ReadyToTrigger_bool

#ifndef S_DPRSMI_TriggerReason_nu
#define S_DPRSMI_TriggerReason_nu (DPRSMI_SenGetDbgPtr()->S_DPRSMI_TriggerReason_nu) //!< DPRSMI debug macro.
#define GET_S_DPRSMI_TriggerReason_nu() (S_DPRSMI_TriggerReason_nu) //!< DPRSMI debug macro getter.
#endif // S_DPRSMI_TriggerReason_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPRSMI_SysStateRDPLe_nu
#define S_DPRSMI_SysStateRDPLe_nu (DPRSMI_SenGetOutPtr()->S_DPRSMI_SysStateRDPLe_nu) //!< DPRSMI output macro.
#define GET_S_DPRSMI_SysStateRDPLe_nu() (S_DPRSMI_SysStateRDPLe_nu) //!< DPRSMI output macro getter.
#endif // S_DPRSMI_SysStateRDPLe_nu

#ifndef S_DPRSMI_SysStateRDPRi_nu
#define S_DPRSMI_SysStateRDPRi_nu (DPRSMI_SenGetOutPtr()->S_DPRSMI_SysStateRDPRi_nu) //!< DPRSMI output macro.
#define GET_S_DPRSMI_SysStateRDPRi_nu() (S_DPRSMI_SysStateRDPRi_nu) //!< DPRSMI output macro getter.
#endif // S_DPRSMI_SysStateRDPRi_nu

#ifndef S_DPRSMI_SysStateRDP_nu
#define S_DPRSMI_SysStateRDP_nu (DPRSMI_SenGetOutPtr()->S_DPRSMI_SysStateRDP_nu) //!< DPRSMI output macro.
#define GET_S_DPRSMI_SysStateRDP_nu() (S_DPRSMI_SysStateRDP_nu) //!< DPRSMI output macro getter.
#endif // S_DPRSMI_SysStateRDP_nu

#ifdef __cplusplus
}
#endif

#endif // DPRSMI_DATA_H_
