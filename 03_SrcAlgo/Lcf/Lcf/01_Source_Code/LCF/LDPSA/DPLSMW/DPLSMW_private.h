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
//! @file     DPLSMW_private.h
//! @brief     (DPLSMW) Module Private Header.

#ifndef DPLSMW_PRIVATE_H_
#define DPLSMW_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define LDPSA	//!< LDPSA sub-component input macro switch.
#define DPLSMW	//!< DPLSMW module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLSMW.h"
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

#define RUNNABLE_ID_DPLSMW_SenReset		0xF0 //!< DPLSMW module reset runnable identifier.
#define RUNNABLE_ID_DPLSMW_SenProcess	0xF1 //!< DPLSMW module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPLSMW_SenDbgType *DPLSMW_SenDbgPtr = NULL; //!< DPLSMW module sensor debug data pointer.
void DPLSMW_SenInitDbgPtr(DPLSMW_SenDbgType *DPLSMW_SenDbgArg) { DPLSMW_SenDbgPtr = DPLSMW_SenDbgPtr == NULL ? DPLSMW_SenDbgArg : DPLSMW_SenDbgPtr; }
const DPLSMW_SenDbgType* DPLSMW_SenGetDbgPtr(void) { return (const DPLSMW_SenDbgType*) DPLSMW_SenDbgPtr; }

static DPLSMW_SenOutType *DPLSMW_SenOutPtr = NULL; //!< DPLSMW module sensor output data pointer.
void DPLSMW_SenInitOutPtr(DPLSMW_SenOutType *DPLSMW_SenOutArg) { DPLSMW_SenOutPtr = DPLSMW_SenOutPtr == NULL ? DPLSMW_SenOutArg : DPLSMW_SenOutPtr; }
const DPLSMW_SenOutType* DPLSMW_SenGetOutPtr(void) { return (const DPLSMW_SenOutType*) DPLSMW_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DPLSMW_Cancel_btf
#define	D_DPLSMW_Cancel_btf (DPLSMW_SenDbgPtr->D_DPLSMW_Cancel_btf) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_Cancel_btf(val)	(D_DPLSMW_Cancel_btf = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_DlcLeThreshold_met
#define	D_DPLSMW_DlcLeThreshold_met (DPLSMW_SenDbgPtr->D_DPLSMW_DlcLeThreshold_met) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_DlcLeThreshold_met(val)	(D_DPLSMW_DlcLeThreshold_met = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_DlcRiThreshold_met
#define	D_DPLSMW_DlcRiThreshold_met (DPLSMW_SenDbgPtr->D_DPLSMW_DlcRiThreshold_met) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_DlcRiThreshold_met(val)	(D_DPLSMW_DlcRiThreshold_met = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_StrongReady_btf
#define	D_DPLSMW_StrongReady_btf (DPLSMW_SenDbgPtr->D_DPLSMW_StrongReady_btf) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_StrongReady_btf(val)	(D_DPLSMW_StrongReady_btf = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_SysStateLDW_btf
#define	D_DPLSMW_SysStateLDW_btf (DPLSMW_SenDbgPtr->D_DPLSMW_SysStateLDW_btf) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_SysStateLDW_btf(val)	(D_DPLSMW_SysStateLDW_btf = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_TlcLeThreshold_sec
#define	D_DPLSMW_TlcLeThreshold_sec (DPLSMW_SenDbgPtr->D_DPLSMW_TlcLeThreshold_sec) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_TlcLeThreshold_sec(val)	(D_DPLSMW_TlcLeThreshold_sec = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_TlcRiThreshold_sec
#define	D_DPLSMW_TlcRiThreshold_sec (DPLSMW_SenDbgPtr->D_DPLSMW_TlcRiThreshold_sec) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_TlcRiThreshold_sec(val)	(D_DPLSMW_TlcRiThreshold_sec = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_TriggerLe_btf
#define	D_DPLSMW_TriggerLe_btf (DPLSMW_SenDbgPtr->D_DPLSMW_TriggerLe_btf) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_TriggerLe_btf(val)	(D_DPLSMW_TriggerLe_btf = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_TriggerRi_btf
#define	D_DPLSMW_TriggerRi_btf (DPLSMW_SenDbgPtr->D_DPLSMW_TriggerRi_btf) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_TriggerRi_btf(val)	(D_DPLSMW_TriggerRi_btf = (val)) //!< DPLSMW debug macro setter.

#undef	D_DPLSMW_WeakReady_btf
#define	D_DPLSMW_WeakReady_btf (DPLSMW_SenDbgPtr->D_DPLSMW_WeakReady_btf) //!< DPLSMW debug macro.
#define	SET_D_DPLSMW_WeakReady_btf(val)	(D_DPLSMW_WeakReady_btf = (val)) //!< DPLSMW debug macro setter.

#undef	S_DPLSMW_DangerousSide_nu
#define	S_DPLSMW_DangerousSide_nu (DPLSMW_SenDbgPtr->S_DPLSMW_DangerousSide_nu) //!< DPLSMW debug macro.
#define	SET_S_DPLSMW_DangerousSide_nu(val)	(S_DPLSMW_DangerousSide_nu = (val)) //!< DPLSMW debug macro setter.

#undef	S_DPLSMW_ReadyToTrigger_bool
#define	S_DPLSMW_ReadyToTrigger_bool (DPLSMW_SenDbgPtr->S_DPLSMW_ReadyToTrigger_bool) //!< DPLSMW debug macro.
#define	SET_S_DPLSMW_ReadyToTrigger_bool(val)	(S_DPLSMW_ReadyToTrigger_bool = (val)) //!< DPLSMW debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPLSMW_SysStateLDWLe_nu
#define	S_DPLSMW_SysStateLDWLe_nu (DPLSMW_SenOutPtr->S_DPLSMW_SysStateLDWLe_nu) //!< DPLSMW debug macro.
#define	SET_S_DPLSMW_SysStateLDWLe_nu(val)	(S_DPLSMW_SysStateLDWLe_nu = (val)) //!< DPLSMW debug macro setter.

#undef	S_DPLSMW_SysStateLDWRi_nu
#define	S_DPLSMW_SysStateLDWRi_nu (DPLSMW_SenOutPtr->S_DPLSMW_SysStateLDWRi_nu) //!< DPLSMW debug macro.
#define	SET_S_DPLSMW_SysStateLDWRi_nu(val)	(S_DPLSMW_SysStateLDWRi_nu = (val)) //!< DPLSMW debug macro setter.

#undef	S_DPLSMW_SysStateLDW_nu
#define	S_DPLSMW_SysStateLDW_nu (DPLSMW_SenOutPtr->S_DPLSMW_SysStateLDW_nu) //!< DPLSMW debug macro.
#define	SET_S_DPLSMW_SysStateLDW_nu(val)	(S_DPLSMW_SysStateLDW_nu = (val)) //!< DPLSMW debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPLSMW_PRIVATE_H_
