/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : VDPR
  MODULE        : VDPDRV
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     VDPDRV_private.h
//! @brief     (VDPDRV) Module Private Header.

#ifndef VDPDRV_PRIVATE_H_
#define VDPDRV_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define VDPR	//!< VDPR sub-component input macro switch.
#define VDPDRV	//!< VDPDRV module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "VDPDRV.h"
#include "Bitop.h"  //MFC5J3
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_VDPDRV_SenReset		0xF0 //!< VDPDRV module reset runnable identifier.
#define RUNNABLE_ID_VDPDRV_SenProcess	0xF1 //!< VDPDRV module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static VDPDRV_SenDbgType *VDPDRV_SenDbgPtr = NULL; //!< VDPDRV module sensor debug data pointer.
void VDPDRV_SenInitDbgPtr(VDPDRV_SenDbgType *VDPDRV_SenDbgArg) { VDPDRV_SenDbgPtr = VDPDRV_SenDbgPtr == NULL ? VDPDRV_SenDbgArg : VDPDRV_SenDbgPtr; }
const VDPDRV_SenDbgType* VDPDRV_SenGetDbgPtr(void) { return (const VDPDRV_SenDbgType*) VDPDRV_SenDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_VDPDRV_ActiveStCtrl_btf
#define	S_VDPDRV_ActiveStCtrl_btf (VDPDRV_SenDbgPtr->S_VDPDRV_ActiveStCtrl_btf) //!< VDPDRV debug macro.
#define	SET_S_VDPDRV_ActiveStCtrl_btf(val)	(S_VDPDRV_ActiveStCtrl_btf = (val)) //!< VDPDRV debug macro setter.

#undef	S_VDPDRV_DrvStInvalid_btf
#define	S_VDPDRV_DrvStInvalid_btf (VDPDRV_SenDbgPtr->S_VDPDRV_DrvStInvalid_btf) //!< VDPDRV debug macro.
#define	SET_S_VDPDRV_DrvStInvalid_btf(val)	(S_VDPDRV_DrvStInvalid_btf = (val)) //!< VDPDRV debug macro setter.

#undef	S_VDPDRV_SysStError_btf
#define	S_VDPDRV_SysStError_btf (VDPDRV_SenDbgPtr->S_VDPDRV_SysStError_btf) //!< VDPDRV debug macro.
#define	SET_S_VDPDRV_SysStError_btf(val)	(S_VDPDRV_SysStError_btf = (val)) //!< VDPDRV debug macro setter.

#undef	S_VDPDRV_SysStNotAvailable_btf
#define	S_VDPDRV_SysStNotAvailable_btf (VDPDRV_SenDbgPtr->S_VDPDRV_SysStNotAvailable_btf) //!< VDPDRV debug macro.
#define	SET_S_VDPDRV_SysStNotAvailable_btf(val)	(S_VDPDRV_SysStNotAvailable_btf = (val)) //!< VDPDRV debug macro setter.

#undef	S_VDPDRV_VehStInvalid_btf
#define	S_VDPDRV_VehStInvalid_btf (VDPDRV_SenDbgPtr->S_VDPDRV_VehStInvalid_btf) //!< VDPDRV debug macro.
#define	SET_S_VDPDRV_VehStInvalid_btf(val)	(S_VDPDRV_VehStInvalid_btf = (val)) //!< VDPDRV debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // VDPDRV_PRIVATE_H_
