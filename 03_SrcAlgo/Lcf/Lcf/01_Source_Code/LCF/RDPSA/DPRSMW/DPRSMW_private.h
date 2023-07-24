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
//! @file     DPRSMW_private.h
//! @brief     (DPRSMW) Module Private Header.

#ifndef DPRSMW_PRIVATE_H_
#define DPRSMW_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define RDPSA	//!< RDPSA sub-component input macro switch.
#define DPRSMW	//!< DPRSMW module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRSMW.h"
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

#define RUNNABLE_ID_DPRSMW_SenReset		0xF0 //!< DPRSMW module reset runnable identifier.
#define RUNNABLE_ID_DPRSMW_SenProcess	0xF1 //!< DPRSMW module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPRSMW_SenDbgType *DPRSMW_SenDbgPtr = NULL; //!< DPRSMW module sensor debug data pointer.
void DPRSMW_SenInitDbgPtr(DPRSMW_SenDbgType *DPRSMW_SenDbgArg) { DPRSMW_SenDbgPtr = DPRSMW_SenDbgPtr == NULL ? DPRSMW_SenDbgArg : DPRSMW_SenDbgPtr; }
const DPRSMW_SenDbgType* DPRSMW_SenGetDbgPtr(void) { return (const DPRSMW_SenDbgType*) DPRSMW_SenDbgPtr; }

static DPRSMW_SenOutType *DPRSMW_SenOutPtr = NULL; //!< DPRSMW module sensor output data pointer.
void DPRSMW_SenInitOutPtr(DPRSMW_SenOutType *DPRSMW_SenOutArg) { DPRSMW_SenOutPtr = DPRSMW_SenOutPtr == NULL ? DPRSMW_SenOutArg : DPRSMW_SenOutPtr; }
const DPRSMW_SenOutType* DPRSMW_SenGetOutPtr(void) { return (const DPRSMW_SenOutType*) DPRSMW_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DPRSMW_Cancel_btf
#define	D_DPRSMW_Cancel_btf (DPRSMW_SenDbgPtr->D_DPRSMW_Cancel_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_Cancel_btf(val)	(D_DPRSMW_Cancel_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_DlcLeThreshold_met
#define	D_DPRSMW_DlcLeThreshold_met (DPRSMW_SenDbgPtr->D_DPRSMW_DlcLeThreshold_met) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_DlcLeThreshold_met(val)	(D_DPRSMW_DlcLeThreshold_met = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_DlcRiThreshold_met
#define	D_DPRSMW_DlcRiThreshold_met (DPRSMW_SenDbgPtr->D_DPRSMW_DlcRiThreshold_met) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_DlcRiThreshold_met(val)	(D_DPRSMW_DlcRiThreshold_met = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_DrcLeThreshold_met
#define	D_DPRSMW_DrcLeThreshold_met (DPRSMW_SenDbgPtr->D_DPRSMW_DrcLeThreshold_met) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_DrcLeThreshold_met(val)	(D_DPRSMW_DrcLeThreshold_met = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_DrcRiThreshold_met
#define	D_DPRSMW_DrcRiThreshold_met (DPRSMW_SenDbgPtr->D_DPRSMW_DrcRiThreshold_met) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_DrcRiThreshold_met(val)	(D_DPRSMW_DrcRiThreshold_met = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_StrongReady_btf
#define	D_DPRSMW_StrongReady_btf (DPRSMW_SenDbgPtr->D_DPRSMW_StrongReady_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_StrongReady_btf(val)	(D_DPRSMW_StrongReady_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_SysStateRDW_btf
#define	D_DPRSMW_SysStateRDW_btf (DPRSMW_SenDbgPtr->D_DPRSMW_SysStateRDW_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_SysStateRDW_btf(val)	(D_DPRSMW_SysStateRDW_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TlcLeThreshold_sec
#define	D_DPRSMW_TlcLeThreshold_sec (DPRSMW_SenDbgPtr->D_DPRSMW_TlcLeThreshold_sec) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TlcLeThreshold_sec(val)	(D_DPRSMW_TlcLeThreshold_sec = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TlcRiThreshold_sec
#define	D_DPRSMW_TlcRiThreshold_sec (DPRSMW_SenDbgPtr->D_DPRSMW_TlcRiThreshold_sec) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TlcRiThreshold_sec(val)	(D_DPRSMW_TlcRiThreshold_sec = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TrcLeThreshold_sec
#define	D_DPRSMW_TrcLeThreshold_sec (DPRSMW_SenDbgPtr->D_DPRSMW_TrcLeThreshold_sec) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TrcLeThreshold_sec(val)	(D_DPRSMW_TrcLeThreshold_sec = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TrcRiThreshold_sec
#define	D_DPRSMW_TrcRiThreshold_sec (DPRSMW_SenDbgPtr->D_DPRSMW_TrcRiThreshold_sec) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TrcRiThreshold_sec(val)	(D_DPRSMW_TrcRiThreshold_sec = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TriggerLnLe_btf
#define	D_DPRSMW_TriggerLnLe_btf (DPRSMW_SenDbgPtr->D_DPRSMW_TriggerLnLe_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TriggerLnLe_btf(val)	(D_DPRSMW_TriggerLnLe_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TriggerLnReLe_btf
#define	D_DPRSMW_TriggerLnReLe_btf (DPRSMW_SenDbgPtr->D_DPRSMW_TriggerLnReLe_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TriggerLnReLe_btf(val)	(D_DPRSMW_TriggerLnReLe_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TriggerLnReRi_btf
#define	D_DPRSMW_TriggerLnReRi_btf (DPRSMW_SenDbgPtr->D_DPRSMW_TriggerLnReRi_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TriggerLnReRi_btf(val)	(D_DPRSMW_TriggerLnReRi_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TriggerLnRi_btf
#define	D_DPRSMW_TriggerLnRi_btf (DPRSMW_SenDbgPtr->D_DPRSMW_TriggerLnRi_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TriggerLnRi_btf(val)	(D_DPRSMW_TriggerLnRi_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TriggerReLe_btf
#define	D_DPRSMW_TriggerReLe_btf (DPRSMW_SenDbgPtr->D_DPRSMW_TriggerReLe_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TriggerReLe_btf(val)	(D_DPRSMW_TriggerReLe_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_TriggerReRi_btf
#define	D_DPRSMW_TriggerReRi_btf (DPRSMW_SenDbgPtr->D_DPRSMW_TriggerReRi_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_TriggerReRi_btf(val)	(D_DPRSMW_TriggerReRi_btf = (val)) //!< DPRSMW debug macro setter.

#undef	D_DPRSMW_WeakReady_btf
#define	D_DPRSMW_WeakReady_btf (DPRSMW_SenDbgPtr->D_DPRSMW_WeakReady_btf) //!< DPRSMW debug macro.
#define	SET_D_DPRSMW_WeakReady_btf(val)	(D_DPRSMW_WeakReady_btf = (val)) //!< DPRSMW debug macro setter.

#undef	S_DPRSMW_DangerousSide_nu
#define	S_DPRSMW_DangerousSide_nu (DPRSMW_SenDbgPtr->S_DPRSMW_DangerousSide_nu) //!< DPRSMW debug macro.
#define	SET_S_DPRSMW_DangerousSide_nu(val)	(S_DPRSMW_DangerousSide_nu = (val)) //!< DPRSMW debug macro setter.

#undef	S_DPRSMW_ReadyToTrigger_bool
#define	S_DPRSMW_ReadyToTrigger_bool (DPRSMW_SenDbgPtr->S_DPRSMW_ReadyToTrigger_bool) //!< DPRSMW debug macro.
#define	SET_S_DPRSMW_ReadyToTrigger_bool(val)	(S_DPRSMW_ReadyToTrigger_bool = (val)) //!< DPRSMW debug macro setter.

#undef	S_DPRSMW_TriggerReason_nu
#define	S_DPRSMW_TriggerReason_nu (DPRSMW_SenDbgPtr->S_DPRSMW_TriggerReason_nu) //!< DPRSMW debug macro.
#define	SET_S_DPRSMW_TriggerReason_nu(val)	(S_DPRSMW_TriggerReason_nu = (val)) //!< DPRSMW debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPRSMW_SysStateRDWLe_nu
#define	S_DPRSMW_SysStateRDWLe_nu (DPRSMW_SenOutPtr->S_DPRSMW_SysStateRDWLe_nu) //!< DPRSMW debug macro.
#define	SET_S_DPRSMW_SysStateRDWLe_nu(val)	(S_DPRSMW_SysStateRDWLe_nu = (val)) //!< DPRSMW debug macro setter.

#undef	S_DPRSMW_SysStateRDWRi_nu
#define	S_DPRSMW_SysStateRDWRi_nu (DPRSMW_SenOutPtr->S_DPRSMW_SysStateRDWRi_nu) //!< DPRSMW debug macro.
#define	SET_S_DPRSMW_SysStateRDWRi_nu(val)	(S_DPRSMW_SysStateRDWRi_nu = (val)) //!< DPRSMW debug macro setter.

#undef	S_DPRSMW_SysStateRDW_nu
#define	S_DPRSMW_SysStateRDW_nu (DPRSMW_SenOutPtr->S_DPRSMW_SysStateRDW_nu) //!< DPRSMW debug macro.
#define	SET_S_DPRSMW_SysStateRDW_nu(val)	(S_DPRSMW_SysStateRDW_nu = (val)) //!< DPRSMW debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPRSMW_PRIVATE_H_
