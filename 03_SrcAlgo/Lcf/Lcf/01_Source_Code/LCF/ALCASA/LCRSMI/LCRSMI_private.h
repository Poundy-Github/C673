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
//! @file     LCRSMI_private.h
//! @brief     (LCRSMI) Module Private Header.

#ifndef LCRSMI_PRIVATE_H_
#define LCRSMI_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ALCASA	//!< ALCASA sub-component input macro switch.
#define LCRSMI	//!< LCRSMI module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCRSMI.h"
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

#define RUNNABLE_ID_LCRSMI_SenReset		0xF0 //!< LCRSMI module reset runnable identifier.
#define RUNNABLE_ID_LCRSMI_SenProcess	0xF1 //!< LCRSMI module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static LCRSMI_SenDbgType *LCRSMI_SenDbgPtr = NULL; //!< LCRSMI module sensor debug data pointer.
void LCRSMI_SenInitDbgPtr(LCRSMI_SenDbgType *LCRSMI_SenDbgArg) { LCRSMI_SenDbgPtr = LCRSMI_SenDbgPtr == NULL ? LCRSMI_SenDbgArg : LCRSMI_SenDbgPtr; }
const LCRSMI_SenDbgType* LCRSMI_SenGetDbgPtr(void) { return (const LCRSMI_SenDbgType*) LCRSMI_SenDbgPtr; }

static LCRSMI_SenOutType *LCRSMI_SenOutPtr = NULL; //!< LCRSMI module sensor output data pointer.
void LCRSMI_SenInitOutPtr(LCRSMI_SenOutType *LCRSMI_SenOutArg) { LCRSMI_SenOutPtr = LCRSMI_SenOutPtr == NULL ? LCRSMI_SenOutArg : LCRSMI_SenOutPtr; }
const LCRSMI_SenOutType* LCRSMI_SenGetOutPtr(void) { return (const LCRSMI_SenOutType*) LCRSMI_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_LCRSMI_Cancel_btf
#define	D_LCRSMI_Cancel_btf (LCRSMI_SenDbgPtr->D_LCRSMI_Cancel_btf) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_Cancel_btf(val)	(D_LCRSMI_Cancel_btf = (val)) //!< LCRSMI debug macro setter.

#undef	D_LCRSMI_StrongReady_btf
#define	D_LCRSMI_StrongReady_btf (LCRSMI_SenDbgPtr->D_LCRSMI_StrongReady_btf) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_StrongReady_btf(val)	(D_LCRSMI_StrongReady_btf = (val)) //!< LCRSMI debug macro setter.

#undef	D_LCRSMI_SysStateALCA_btf
#define	D_LCRSMI_SysStateALCA_btf (LCRSMI_SenDbgPtr->D_LCRSMI_SysStateALCA_btf) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_SysStateALCA_btf(val)	(D_LCRSMI_SysStateALCA_btf = (val)) //!< LCRSMI debug macro setter.

#undef	D_LCRSMI_WeakReady_btf
#define	D_LCRSMI_WeakReady_btf (LCRSMI_SenDbgPtr->D_LCRSMI_WeakReady_btf) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_WeakReady_btf(val)	(D_LCRSMI_WeakReady_btf = (val)) //!< LCRSMI debug macro setter.

#undef	S_LCRSMI_DangerousSide_nu
#define	S_LCRSMI_DangerousSide_nu (LCRSMI_SenDbgPtr->S_LCRSMI_DangerousSide_nu) //!< LCRSMI debug macro.
#define	SET_S_LCRSMI_DangerousSide_nu(val)	(S_LCRSMI_DangerousSide_nu = (val)) //!< LCRSMI debug macro setter.

#undef	S_LCRSMI_FunctionAborted_bool
#define	S_LCRSMI_FunctionAborted_bool (LCRSMI_SenDbgPtr->S_LCRSMI_FunctionAborted_bool) //!< LCRSMI debug macro.
#define	SET_S_LCRSMI_FunctionAborted_bool(val)	(S_LCRSMI_FunctionAborted_bool = (val)) //!< LCRSMI debug macro setter.

#undef	S_LCRSMI_ReadyToTrigger_bool
#define	S_LCRSMI_ReadyToTrigger_bool (LCRSMI_SenDbgPtr->S_LCRSMI_ReadyToTrigger_bool) //!< LCRSMI debug macro.
#define	SET_S_LCRSMI_ReadyToTrigger_bool(val)	(S_LCRSMI_ReadyToTrigger_bool = (val)) //!< LCRSMI debug macro setter.

#undef	S_LCRSMI_SysStateALCA_nu
#define	S_LCRSMI_SysStateALCA_nu (LCRSMI_SenDbgPtr->S_LCRSMI_SysStateALCA_nu) //!< LCRSMI debug macro.
#define	SET_S_LCRSMI_SysStateALCA_nu(val)	(S_LCRSMI_SysStateALCA_nu = (val)) //!< LCRSMI debug macro setter.

//luhui.2023.01.30. move from out to dbg
#undef	D_LCRSMI_DlcLeThreshold_met
#define	D_LCRSMI_DlcLeThreshold_met (LCRSMI_SenDbgPtr->D_LCRSMI_DlcLeThreshold_met) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_DlcLeThreshold_met(val)	(D_LCRSMI_DlcLeThreshold_met = (val)) //!< LCRSMI debug macro setter.

#undef	D_LCRSMI_DlcRiThreshold_met
#define	D_LCRSMI_DlcRiThreshold_met (LCRSMI_SenDbgPtr->D_LCRSMI_DlcRiThreshold_met) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_DlcRiThreshold_met(val)	(D_LCRSMI_DlcRiThreshold_met = (val)) //!< LCRSMI debug macro setter.

#undef	D_LCRSMI_TlcLeThreshold_sec
#define	D_LCRSMI_TlcLeThreshold_sec (LCRSMI_SenDbgPtr->D_LCRSMI_TlcLeThreshold_sec) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_TlcLeThreshold_sec(val)	(D_LCRSMI_TlcLeThreshold_sec = (val)) //!< LCRSMI debug macro setter.

#undef	D_LCRSMI_TlcRiThreshold_sec
#define	D_LCRSMI_TlcRiThreshold_sec (LCRSMI_SenDbgPtr->D_LCRSMI_TlcRiThreshold_sec) //!< LCRSMI debug macro.
#define	SET_D_LCRSMI_TlcRiThreshold_sec(val)	(D_LCRSMI_TlcRiThreshold_sec = (val)) //!< LCRSMI debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/
#undef	S_LCRSMI_SysStateALCALe_nu
#define	S_LCRSMI_SysStateALCALe_nu (LCRSMI_SenOutPtr->S_LCRSMI_SysStateALCALe_nu) //!< LCRSMI debug macro.
#define	SET_S_LCRSMI_SysStateALCALe_nu(val)	(S_LCRSMI_SysStateALCALe_nu = (val)) //!< LCRSMI debug macro setter.

#undef	S_LCRSMI_SysStateALCARi_nu
#define	S_LCRSMI_SysStateALCARi_nu (LCRSMI_SenOutPtr->S_LCRSMI_SysStateALCARi_nu) //!< LCRSMI debug macro.
#define	SET_S_LCRSMI_SysStateALCARi_nu(val)	(S_LCRSMI_SysStateALCARi_nu = (val)) //!< LCRSMI debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // LCRSMI_PRIVATE_H_
