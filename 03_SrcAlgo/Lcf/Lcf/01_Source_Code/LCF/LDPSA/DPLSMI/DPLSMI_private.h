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
//! @file     DPLSMI_private.h
//! @brief     (DPLSMI) Module Private Header.

#ifndef DPLSMI_PRIVATE_H_
#define DPLSMI_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define LDPSA	//!< LDPSA sub-component input macro switch.
#define DPLSMI	//!< DPLSMI module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLSMI.h"
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

#define RUNNABLE_ID_DPLSMI_SenReset		0xF0 //!< DPLSMI module reset runnable identifier.
#define RUNNABLE_ID_DPLSMI_SenProcess	0xF1 //!< DPLSMI module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPLSMI_SenDbgType *DPLSMI_SenDbgPtr = NULL; //!< DPLSMI module sensor debug data pointer.
void DPLSMI_SenInitDbgPtr(DPLSMI_SenDbgType *DPLSMI_SenDbgArg) { DPLSMI_SenDbgPtr = DPLSMI_SenDbgPtr == NULL ? DPLSMI_SenDbgArg : DPLSMI_SenDbgPtr; }
const DPLSMI_SenDbgType* DPLSMI_SenGetDbgPtr(void) { return (const DPLSMI_SenDbgType*) DPLSMI_SenDbgPtr; }

static DPLSMI_SenOutType *DPLSMI_SenOutPtr = NULL; //!< DPLSMI module sensor output data pointer.
void DPLSMI_SenInitOutPtr(DPLSMI_SenOutType *DPLSMI_SenOutArg) { DPLSMI_SenOutPtr = DPLSMI_SenOutPtr == NULL ? DPLSMI_SenOutArg : DPLSMI_SenOutPtr; }
const DPLSMI_SenOutType* DPLSMI_SenGetOutPtr(void) { return (const DPLSMI_SenOutType*) DPLSMI_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DPLSMI_Cancel_btf
#define	D_DPLSMI_Cancel_btf (DPLSMI_SenDbgPtr->D_DPLSMI_Cancel_btf) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_Cancel_btf(val)	(D_DPLSMI_Cancel_btf = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_DlcLeThreshold_met
#define	D_DPLSMI_DlcLeThreshold_met (DPLSMI_SenDbgPtr->D_DPLSMI_DlcLeThreshold_met) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_DlcLeThreshold_met(val)	(D_DPLSMI_DlcLeThreshold_met = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_DlcRiThreshold_met
#define	D_DPLSMI_DlcRiThreshold_met (DPLSMI_SenDbgPtr->D_DPLSMI_DlcRiThreshold_met) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_DlcRiThreshold_met(val)	(D_DPLSMI_DlcRiThreshold_met = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_StrongReady_btf
#define	D_DPLSMI_StrongReady_btf (DPLSMI_SenDbgPtr->D_DPLSMI_StrongReady_btf) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_StrongReady_btf(val)	(D_DPLSMI_StrongReady_btf = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_SysStateLDP_btf
#define	D_DPLSMI_SysStateLDP_btf (DPLSMI_SenDbgPtr->D_DPLSMI_SysStateLDP_btf) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_SysStateLDP_btf(val)	(D_DPLSMI_SysStateLDP_btf = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_TlcLeThreshold_sec
#define	D_DPLSMI_TlcLeThreshold_sec (DPLSMI_SenDbgPtr->D_DPLSMI_TlcLeThreshold_sec) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_TlcLeThreshold_sec(val)	(D_DPLSMI_TlcLeThreshold_sec = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_TlcRiThreshold_sec
#define	D_DPLSMI_TlcRiThreshold_sec (DPLSMI_SenDbgPtr->D_DPLSMI_TlcRiThreshold_sec) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_TlcRiThreshold_sec(val)	(D_DPLSMI_TlcRiThreshold_sec = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_TriggerLe_btf
#define	D_DPLSMI_TriggerLe_btf (DPLSMI_SenDbgPtr->D_DPLSMI_TriggerLe_btf) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_TriggerLe_btf(val)	(D_DPLSMI_TriggerLe_btf = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_TriggerRi_btf
#define	D_DPLSMI_TriggerRi_btf (DPLSMI_SenDbgPtr->D_DPLSMI_TriggerRi_btf) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_TriggerRi_btf(val)	(D_DPLSMI_TriggerRi_btf = (val)) //!< DPLSMI debug macro setter.

#undef	D_DPLSMI_WeakReady_btf
#define	D_DPLSMI_WeakReady_btf (DPLSMI_SenDbgPtr->D_DPLSMI_WeakReady_btf) //!< DPLSMI debug macro.
#define	SET_D_DPLSMI_WeakReady_btf(val)	(D_DPLSMI_WeakReady_btf = (val)) //!< DPLSMI debug macro setter.

#undef	S_DPLSMI_DangerousSide_nu
#define	S_DPLSMI_DangerousSide_nu (DPLSMI_SenDbgPtr->S_DPLSMI_DangerousSide_nu) //!< DPLSMI debug macro.
#define	SET_S_DPLSMI_DangerousSide_nu(val)	(S_DPLSMI_DangerousSide_nu = (val)) //!< DPLSMI debug macro setter.

#undef	S_DPLSMI_FunctionAborted_bool
#define	S_DPLSMI_FunctionAborted_bool (DPLSMI_SenDbgPtr->S_DPLSMI_FunctionAborted_bool) //!< DPLSMI debug macro.
#define	SET_S_DPLSMI_FunctionAborted_bool(val)	(S_DPLSMI_FunctionAborted_bool = (val)) //!< DPLSMI debug macro setter.

#undef	S_DPLSMI_ReadyToTrigger_bool
#define	S_DPLSMI_ReadyToTrigger_bool (DPLSMI_SenDbgPtr->S_DPLSMI_ReadyToTrigger_bool) //!< DPLSMI debug macro.
#define	SET_S_DPLSMI_ReadyToTrigger_bool(val)	(S_DPLSMI_ReadyToTrigger_bool = (val)) //!< DPLSMI debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPLSMI_SysStateLDPLe_nu
#define	S_DPLSMI_SysStateLDPLe_nu (DPLSMI_SenOutPtr->S_DPLSMI_SysStateLDPLe_nu) //!< DPLSMI debug macro.
#define	SET_S_DPLSMI_SysStateLDPLe_nu(val)	(S_DPLSMI_SysStateLDPLe_nu = (val)) //!< DPLSMI debug macro setter.

#undef	S_DPLSMI_SysStateLDPRi_nu
#define	S_DPLSMI_SysStateLDPRi_nu (DPLSMI_SenOutPtr->S_DPLSMI_SysStateLDPRi_nu) //!< DPLSMI debug macro.
#define	SET_S_DPLSMI_SysStateLDPRi_nu(val)	(S_DPLSMI_SysStateLDPRi_nu = (val)) //!< DPLSMI debug macro setter.

#undef	S_DPLSMI_SysStateLDP_nu
#define	S_DPLSMI_SysStateLDP_nu (DPLSMI_SenOutPtr->S_DPLSMI_SysStateLDP_nu) //!< DPLSMI debug macro.
#define	SET_S_DPLSMI_SysStateLDP_nu(val)	(S_DPLSMI_SysStateLDP_nu = (val)) //!< DPLSMI debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPLSMI_PRIVATE_H_
