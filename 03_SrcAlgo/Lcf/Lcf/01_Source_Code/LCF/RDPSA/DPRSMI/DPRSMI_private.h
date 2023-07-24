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
//! @file     DPRSMI_private.h
//! @brief     (DPRSMI) Module Private Header.

#ifndef DPRSMI_PRIVATE_H_
#define DPRSMI_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define RDPSA	//!< RDPSA sub-component input macro switch.
#define DPRSMI	//!< DPRSMI module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRSMI.h"
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

#define RUNNABLE_ID_DPRSMI_SenReset		0xF0 //!< DPRSMI module reset runnable identifier.
#define RUNNABLE_ID_DPRSMI_SenProcess	0xF1 //!< DPRSMI module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPRSMI_SenDbgType *DPRSMI_SenDbgPtr = NULL; //!< DPRSMI module sensor debug data pointer.
void DPRSMI_SenInitDbgPtr(DPRSMI_SenDbgType *DPRSMI_SenDbgArg) { DPRSMI_SenDbgPtr = DPRSMI_SenDbgPtr == NULL ? DPRSMI_SenDbgArg : DPRSMI_SenDbgPtr; }
const DPRSMI_SenDbgType* DPRSMI_SenGetDbgPtr(void) { return (const DPRSMI_SenDbgType*) DPRSMI_SenDbgPtr; }

static DPRSMI_SenOutType *DPRSMI_SenOutPtr = NULL; //!< DPRSMI module sensor output data pointer.
void DPRSMI_SenInitOutPtr(DPRSMI_SenOutType *DPRSMI_SenOutArg) { DPRSMI_SenOutPtr = DPRSMI_SenOutPtr == NULL ? DPRSMI_SenOutArg : DPRSMI_SenOutPtr; }
const DPRSMI_SenOutType* DPRSMI_SenGetOutPtr(void) { return (const DPRSMI_SenOutType*) DPRSMI_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DPRSMI_Cancel_btf
#define	D_DPRSMI_Cancel_btf (DPRSMI_SenDbgPtr->D_DPRSMI_Cancel_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_Cancel_btf(val)	(D_DPRSMI_Cancel_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_DlcLeThreshold_met
#define	D_DPRSMI_DlcLeThreshold_met (DPRSMI_SenDbgPtr->D_DPRSMI_DlcLeThreshold_met) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_DlcLeThreshold_met(val)	(D_DPRSMI_DlcLeThreshold_met = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_DlcRiThreshold_met
#define	D_DPRSMI_DlcRiThreshold_met (DPRSMI_SenDbgPtr->D_DPRSMI_DlcRiThreshold_met) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_DlcRiThreshold_met(val)	(D_DPRSMI_DlcRiThreshold_met = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_DrcLeThreshold_met
#define	D_DPRSMI_DrcLeThreshold_met (DPRSMI_SenDbgPtr->D_DPRSMI_DrcLeThreshold_met) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_DrcLeThreshold_met(val)	(D_DPRSMI_DrcLeThreshold_met = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_DrcRiThreshold_met
#define	D_DPRSMI_DrcRiThreshold_met (DPRSMI_SenDbgPtr->D_DPRSMI_DrcRiThreshold_met) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_DrcRiThreshold_met(val)	(D_DPRSMI_DrcRiThreshold_met = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_StrongReady_btf
#define	D_DPRSMI_StrongReady_btf (DPRSMI_SenDbgPtr->D_DPRSMI_StrongReady_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_StrongReady_btf(val)	(D_DPRSMI_StrongReady_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_SysStateRDP_btf
#define	D_DPRSMI_SysStateRDP_btf (DPRSMI_SenDbgPtr->D_DPRSMI_SysStateRDP_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_SysStateRDP_btf(val)	(D_DPRSMI_SysStateRDP_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TlcLeThreshold_sec
#define	D_DPRSMI_TlcLeThreshold_sec (DPRSMI_SenDbgPtr->D_DPRSMI_TlcLeThreshold_sec) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TlcLeThreshold_sec(val)	(D_DPRSMI_TlcLeThreshold_sec = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TlcRiThreshold_sec
#define	D_DPRSMI_TlcRiThreshold_sec (DPRSMI_SenDbgPtr->D_DPRSMI_TlcRiThreshold_sec) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TlcRiThreshold_sec(val)	(D_DPRSMI_TlcRiThreshold_sec = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TrcLeThreshold_sec
#define	D_DPRSMI_TrcLeThreshold_sec (DPRSMI_SenDbgPtr->D_DPRSMI_TrcLeThreshold_sec) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TrcLeThreshold_sec(val)	(D_DPRSMI_TrcLeThreshold_sec = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TrcRiThreshold_sec
#define	D_DPRSMI_TrcRiThreshold_sec (DPRSMI_SenDbgPtr->D_DPRSMI_TrcRiThreshold_sec) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TrcRiThreshold_sec(val)	(D_DPRSMI_TrcRiThreshold_sec = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TriggerLnLe_btf
#define	D_DPRSMI_TriggerLnLe_btf (DPRSMI_SenDbgPtr->D_DPRSMI_TriggerLnLe_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TriggerLnLe_btf(val)	(D_DPRSMI_TriggerLnLe_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TriggerLnReLe_btf
#define	D_DPRSMI_TriggerLnReLe_btf (DPRSMI_SenDbgPtr->D_DPRSMI_TriggerLnReLe_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TriggerLnReLe_btf(val)	(D_DPRSMI_TriggerLnReLe_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TriggerLnReRi_btf
#define	D_DPRSMI_TriggerLnReRi_btf (DPRSMI_SenDbgPtr->D_DPRSMI_TriggerLnReRi_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TriggerLnReRi_btf(val)	(D_DPRSMI_TriggerLnReRi_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TriggerLnRi_btf
#define	D_DPRSMI_TriggerLnRi_btf (DPRSMI_SenDbgPtr->D_DPRSMI_TriggerLnRi_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TriggerLnRi_btf(val)	(D_DPRSMI_TriggerLnRi_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TriggerReLe_btf
#define	D_DPRSMI_TriggerReLe_btf (DPRSMI_SenDbgPtr->D_DPRSMI_TriggerReLe_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TriggerReLe_btf(val)	(D_DPRSMI_TriggerReLe_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_TriggerReRi_btf
#define	D_DPRSMI_TriggerReRi_btf (DPRSMI_SenDbgPtr->D_DPRSMI_TriggerReRi_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_TriggerReRi_btf(val)	(D_DPRSMI_TriggerReRi_btf = (val)) //!< DPRSMI debug macro setter.

#undef	D_DPRSMI_WeakReady_btf
#define	D_DPRSMI_WeakReady_btf (DPRSMI_SenDbgPtr->D_DPRSMI_WeakReady_btf) //!< DPRSMI debug macro.
#define	SET_D_DPRSMI_WeakReady_btf(val)	(D_DPRSMI_WeakReady_btf = (val)) //!< DPRSMI debug macro setter.

#undef	S_DPRSMI_DangerousSide_nu
#define	S_DPRSMI_DangerousSide_nu (DPRSMI_SenDbgPtr->S_DPRSMI_DangerousSide_nu) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_DangerousSide_nu(val)	(S_DPRSMI_DangerousSide_nu = (val)) //!< DPRSMI debug macro setter.

#undef	S_DPRSMI_FunctionAborted_bool
#define	S_DPRSMI_FunctionAborted_bool (DPRSMI_SenDbgPtr->S_DPRSMI_FunctionAborted_bool) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_FunctionAborted_bool(val)	(S_DPRSMI_FunctionAborted_bool = (val)) //!< DPRSMI debug macro setter.

#undef	S_DPRSMI_ReadyToTrigger_bool
#define	S_DPRSMI_ReadyToTrigger_bool (DPRSMI_SenDbgPtr->S_DPRSMI_ReadyToTrigger_bool) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_ReadyToTrigger_bool(val)	(S_DPRSMI_ReadyToTrigger_bool = (val)) //!< DPRSMI debug macro setter.

#undef	S_DPRSMI_TriggerReason_nu
#define	S_DPRSMI_TriggerReason_nu (DPRSMI_SenDbgPtr->S_DPRSMI_TriggerReason_nu) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_TriggerReason_nu(val)	(S_DPRSMI_TriggerReason_nu = (val)) //!< DPRSMI debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPRSMI_SysStateRDPLe_nu
#define	S_DPRSMI_SysStateRDPLe_nu (DPRSMI_SenOutPtr->S_DPRSMI_SysStateRDPLe_nu) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_SysStateRDPLe_nu(val)	(S_DPRSMI_SysStateRDPLe_nu = (val)) //!< DPRSMI debug macro setter.

#undef	S_DPRSMI_SysStateRDPRi_nu
#define	S_DPRSMI_SysStateRDPRi_nu (DPRSMI_SenOutPtr->S_DPRSMI_SysStateRDPRi_nu) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_SysStateRDPRi_nu(val)	(S_DPRSMI_SysStateRDPRi_nu = (val)) //!< DPRSMI debug macro setter.

#undef	S_DPRSMI_SysStateRDP_nu
#define	S_DPRSMI_SysStateRDP_nu (DPRSMI_SenOutPtr->S_DPRSMI_SysStateRDP_nu) //!< DPRSMI debug macro.
#define	SET_S_DPRSMI_SysStateRDP_nu(val)	(S_DPRSMI_SysStateRDP_nu = (val)) //!< DPRSMI debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPRSMI_PRIVATE_H_
