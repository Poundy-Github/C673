/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRSMI_data.h
//! @brief     (LCRSMI) Module Data Header.

#ifndef LCRSMI_DATA_H_
#define LCRSMI_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"
#include "LCRSMI_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCRSMI module sensor get function. Function gets LCRSMI sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRSMI_SenDbgPtr</b> Global static pointer to LCRSMI sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRSMI_SenDbgType* LCRSMI_SenGetDbgPtr(void);

/*!
 *	LCRSMI module sensor get function. Function gets LCRSMI sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRSMI_SenOutPtr</b> Global static pointer to LCRSMI sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRSMI_SenOutType* LCRSMI_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_LCRSMI_Cancel_btf
#define D_LCRSMI_Cancel_btf (LCRSMI_SenGetDbgPtr()->D_LCRSMI_Cancel_btf) //!< LCRSMI debug macro.
#define GET_D_LCRSMI_Cancel_btf() (D_LCRSMI_Cancel_btf) //!< LCRSMI debug macro getter.
#endif // D_LCRSMI_Cancel_btf

#ifndef D_LCRSMI_StrongReady_btf
#define D_LCRSMI_StrongReady_btf (LCRSMI_SenGetDbgPtr()->D_LCRSMI_StrongReady_btf) //!< LCRSMI debug macro.
#define GET_D_LCRSMI_StrongReady_btf() (D_LCRSMI_StrongReady_btf) //!< LCRSMI debug macro getter.
#endif // D_LCRSMI_StrongReady_btf

#ifndef D_LCRSMI_SysStateALCA_btf
#define D_LCRSMI_SysStateALCA_btf (LCRSMI_SenGetDbgPtr()->D_LCRSMI_SysStateALCA_btf) //!< LCRSMI debug macro.
#define GET_D_LCRSMI_SysStateALCA_btf() (D_LCRSMI_SysStateALCA_btf) //!< LCRSMI debug macro getter.
#endif // D_LCRSMI_SysStateALCA_btf

#ifndef D_LCRSMI_WeakReady_btf
#define D_LCRSMI_WeakReady_btf (LCRSMI_SenGetDbgPtr()->D_LCRSMI_WeakReady_btf) //!< LCRSMI debug macro.
#define GET_D_LCRSMI_WeakReady_btf() (D_LCRSMI_WeakReady_btf) //!< LCRSMI debug macro getter.
#endif // D_LCRSMI_WeakReady_btf

#ifndef S_LCRSMI_DangerousSide_nu
#define S_LCRSMI_DangerousSide_nu (LCRSMI_SenGetDbgPtr()->S_LCRSMI_DangerousSide_nu) //!< LCRSMI debug macro.
#define GET_S_LCRSMI_DangerousSide_nu() (S_LCRSMI_DangerousSide_nu) //!< LCRSMI debug macro getter.
#endif // S_LCRSMI_DangerousSide_nu

#ifndef S_LCRSMI_FunctionAborted_bool
#define S_LCRSMI_FunctionAborted_bool (LCRSMI_SenGetDbgPtr()->S_LCRSMI_FunctionAborted_bool) //!< LCRSMI debug macro.
#define GET_S_LCRSMI_FunctionAborted_bool() (S_LCRSMI_FunctionAborted_bool) //!< LCRSMI debug macro getter.
#endif // S_LCRSMI_FunctionAborted_bool

#ifndef S_LCRSMI_ReadyToTrigger_bool
#define S_LCRSMI_ReadyToTrigger_bool (LCRSMI_SenGetDbgPtr()->S_LCRSMI_ReadyToTrigger_bool) //!< LCRSMI debug macro.
#define GET_S_LCRSMI_ReadyToTrigger_bool() (S_LCRSMI_ReadyToTrigger_bool) //!< LCRSMI debug macro getter.
#endif // S_LCRSMI_ReadyToTrigger_bool

#ifndef S_LCRSMI_SysStateALCA_nu
#define S_LCRSMI_SysStateALCA_nu (LCRSMI_SenGetDbgPtr()->S_LCRSMI_SysStateALCA_nu) //!< LCRSMI debug macro.
#define GET_S_LCRSMI_SysStateALCA_nu() (S_LCRSMI_SysStateALCA_nu) //!< LCRSMI debug macro getter.
#endif // S_LCRSMI_SysStateALCA_nu

//luhui.2023.01.30.move from out to dbg for MTS
#ifndef D_LCRSMI_DlcLeThreshold_met
#define D_LCRSMI_DlcLeThreshold_met (LCRSMI_SenGetDbgPtr()->D_LCRSMI_DlcLeThreshold_met) //!< LCRSMI output macro.
#define GET_D_LCRSMI_DlcLeThreshold_met() (D_LCRSMI_DlcLeThreshold_met) //!< LCRSMI output macro getter.
#endif // D_LCRSMI_DlcLeThreshold_met

#ifndef D_LCRSMI_DlcRiThreshold_met
#define D_LCRSMI_DlcRiThreshold_met (LCRSMI_SenGetDbgPtr()->D_LCRSMI_DlcRiThreshold_met) //!< LCRSMI output macro.
#define GET_D_LCRSMI_DlcRiThreshold_met() (D_LCRSMI_DlcRiThreshold_met) //!< LCRSMI output macro getter.
#endif // D_LCRSMI_DlcRiThreshold_met

#ifndef D_LCRSMI_TlcLeThreshold_sec
#define D_LCRSMI_TlcLeThreshold_sec (LCRSMI_SenGetDbgPtr()->D_LCRSMI_TlcLeThreshold_sec) //!< LCRSMI output macro.
#define GET_D_LCRSMI_TlcLeThreshold_sec() (D_LCRSMI_TlcLeThreshold_sec) //!< LCRSMI output macro getter.
#endif // D_LCRSMI_TlcLeThreshold_sec

#ifndef D_LCRSMI_TlcRiThreshold_sec
#define D_LCRSMI_TlcRiThreshold_sec (LCRSMI_SenGetDbgPtr()->D_LCRSMI_TlcRiThreshold_sec) //!< LCRSMI output macro.
#define GET_D_LCRSMI_TlcRiThreshold_sec() (D_LCRSMI_TlcRiThreshold_sec) //!< LCRSMI output macro getter.
#endif // D_LCRSMI_TlcRiThreshold_sec

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/



#ifndef S_LCRSMI_SysStateALCALe_nu
#define S_LCRSMI_SysStateALCALe_nu (LCRSMI_SenGetOutPtr()->S_LCRSMI_SysStateALCALe_nu) //!< LCRSMI output macro.
#define GET_S_LCRSMI_SysStateALCALe_nu() (S_LCRSMI_SysStateALCALe_nu) //!< LCRSMI output macro getter.
#endif // S_LCRSMI_SysStateALCALe_nu

#ifndef S_LCRSMI_SysStateALCARi_nu
#define S_LCRSMI_SysStateALCARi_nu (LCRSMI_SenGetOutPtr()->S_LCRSMI_SysStateALCARi_nu) //!< LCRSMI output macro.
#define GET_S_LCRSMI_SysStateALCARi_nu() (S_LCRSMI_SysStateALCARi_nu) //!< LCRSMI output macro getter.
#endif // S_LCRSMI_SysStateALCARi_nu

#ifdef __cplusplus
}
#endif

#endif // LCRSMI_DATA_H_
