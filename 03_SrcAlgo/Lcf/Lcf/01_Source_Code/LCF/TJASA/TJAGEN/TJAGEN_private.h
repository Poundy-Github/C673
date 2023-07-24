/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAGEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJAGEN_private.h
//! @brief     (TJAGEN) Module Private Header.

#ifndef TJAGEN_PRIVATE_H_
#define TJAGEN_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJAGEN	//!< TJAGEN module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJAGEN.h"
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

#define RUNNABLE_ID_TJAGEN_SenReset		0xF0 //!< TJAGEN module reset runnable identifier.
#define RUNNABLE_ID_TJAGEN_SenProcess	0xF1 //!< TJAGEN module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJAGEN_SenDbgType *TJAGEN_SenDbgPtr = NULL; //!< TJAGEN module sensor debug data pointer.
void TJAGEN_SenInitDbgPtr(TJAGEN_SenDbgType *TJAGEN_SenDbgArg) { TJAGEN_SenDbgPtr = TJAGEN_SenDbgPtr == NULL ? TJAGEN_SenDbgArg : TJAGEN_SenDbgPtr; }
const TJAGEN_SenDbgType* TJAGEN_SenGetDbgPtr(void) { return (const TJAGEN_SenDbgType*) TJAGEN_SenDbgPtr; }

static TJAGEN_SenOutType *TJAGEN_SenOutPtr = NULL; //!< TJAGEN module sensor output data pointer.
void TJAGEN_SenInitOutPtr(TJAGEN_SenOutType *TJAGEN_SenOutArg) { TJAGEN_SenOutPtr = TJAGEN_SenOutPtr == NULL ? TJAGEN_SenOutArg : TJAGEN_SenOutPtr; }
const TJAGEN_SenOutType* TJAGEN_SenGetOutPtr(void) { return (const TJAGEN_SenOutType*) TJAGEN_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJAGEN_CancelStatus_btf
#define	D_TJAGEN_CancelStatus_btf (TJAGEN_SenDbgPtr->D_TJAGEN_CancelStatus_btf) //!< TJAGEN debug macro.
#define	SET_D_TJAGEN_CancelStatus_btf(val)	(D_TJAGEN_CancelStatus_btf = (val)) //!< TJAGEN debug macro setter.

#undef	D_TJAGEN_StrongReadyInvalid_btf
#define	D_TJAGEN_StrongReadyInvalid_btf (TJAGEN_SenDbgPtr->D_TJAGEN_StrongReadyInvalid_btf) //!< TJAGEN debug macro.
#define	SET_D_TJAGEN_StrongReadyInvalid_btf(val)	(D_TJAGEN_StrongReadyInvalid_btf = (val)) //!< TJAGEN debug macro setter.

#undef	D_TJAGEN_WeakReadyInvalid_btf
#define	D_TJAGEN_WeakReadyInvalid_btf (TJAGEN_SenDbgPtr->D_TJAGEN_WeakReadyInvalid_btf) //!< TJAGEN debug macro.
#define	SET_D_TJAGEN_WeakReadyInvalid_btf(val)	(D_TJAGEN_WeakReadyInvalid_btf = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_Abort_bool
#define	S_TJAGEN_Abort_bool (TJAGEN_SenDbgPtr->S_TJAGEN_Abort_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_Abort_bool(val)	(S_TJAGEN_Abort_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_LKAOnlySwitch_bool
#define	S_TJAGEN_LKAOnlySwitch_bool (TJAGEN_SenDbgPtr->S_TJAGEN_LKAOnlySwitch_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_LKAOnlySwitch_bool(val)	(S_TJAGEN_LKAOnlySwitch_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_StrongReady_bool
#define	S_TJAGEN_StrongReady_bool (TJAGEN_SenDbgPtr->S_TJAGEN_StrongReady_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_StrongReady_bool(val)	(S_TJAGEN_StrongReady_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_WeakReady_bool
#define	S_TJAGEN_WeakReady_bool (TJAGEN_SenDbgPtr->S_TJAGEN_WeakReady_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_WeakReady_bool(val)	(S_TJAGEN_WeakReady_bool = (val)) //!< TJAGEN debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TJAGEN_Cancel_nu
#define	S_TJAGEN_Cancel_nu (TJAGEN_SenOutPtr->S_TJAGEN_Cancel_nu) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_Cancel_nu(val)	(S_TJAGEN_Cancel_nu = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_Clearance_bool
#define	S_TJAGEN_Clearance_bool (TJAGEN_SenOutPtr->S_TJAGEN_Clearance_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_Clearance_bool(val)	(S_TJAGEN_Clearance_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_CodeFunction_bool
#define	S_TJAGEN_CodeFunction_bool (TJAGEN_SenOutPtr->S_TJAGEN_CodeFunction_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_CodeFunction_bool(val)	(S_TJAGEN_CodeFunction_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_Degradation_bool
#define	S_TJAGEN_Degradation_bool (TJAGEN_SenOutPtr->S_TJAGEN_Degradation_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_Degradation_bool(val)	(S_TJAGEN_Degradation_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_Error_bool
#define	S_TJAGEN_Error_bool (TJAGEN_SenOutPtr->S_TJAGEN_Error_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_Error_bool(val)	(S_TJAGEN_Error_bool = (val)) //!< TJAGEN debug macro setter.

#undef	S_TJAGEN_FunctionSwitch_bool
#define	S_TJAGEN_FunctionSwitch_bool (TJAGEN_SenOutPtr->S_TJAGEN_FunctionSwitch_bool) //!< TJAGEN debug macro.
#define	SET_S_TJAGEN_FunctionSwitch_bool(val)	(S_TJAGEN_FunctionSwitch_bool = (val)) //!< TJAGEN debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TJAGEN_PRIVATE_H_
