/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJASTM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJASTM_private.h
//! @brief     (TJASTM) Module Private Header.

#ifndef TJASTM_PRIVATE_H_
#define TJASTM_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJASTM	//!< TJASTM module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJASTM.h"
#include "Bitop.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TJASTM_SenReset		0xF0 //!< TJASTM module reset runnable identifier.
#define RUNNABLE_ID_TJASTM_SenProcess	0xF1 //!< TJASTM module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJASTM_SenDbgType *TJASTM_SenDbgPtr = NULL; //!< TJASTM module sensor debug data pointer.
void TJASTM_SenInitDbgPtr(TJASTM_SenDbgType *TJASTM_SenDbgArg) { TJASTM_SenDbgPtr = TJASTM_SenDbgPtr == NULL ? TJASTM_SenDbgArg : TJASTM_SenDbgPtr; }
const TJASTM_SenDbgType* TJASTM_SenGetDbgPtr(void) { return (const TJASTM_SenDbgType*) TJASTM_SenDbgPtr; }

static TJASTM_SenOutType *TJASTM_SenOutPtr = NULL; //!< TJASTM module sensor output data pointer.
void TJASTM_SenInitOutPtr(TJASTM_SenOutType *TJASTM_SenOutArg) { TJASTM_SenOutPtr = TJASTM_SenOutPtr == NULL ? TJASTM_SenOutArg : TJASTM_SenOutPtr; }
const TJASTM_SenOutType* TJASTM_SenGetOutPtr(void) { return (const TJASTM_SenOutType*) TJASTM_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJASTM_TJAInvalid_btf
#define	D_TJASTM_TJAInvalid_btf (TJASTM_SenDbgPtr->D_TJASTM_TJAInvalid_btf) //!< TJASTM debug macro.
#define	SET_D_TJASTM_TJAInvalid_btf(val)	(D_TJASTM_TJAInvalid_btf = (val)) //!< TJASTM debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TJASTM_LatCtrlMode_nu
#define	S_TJASTM_LatCtrlMode_nu (TJASTM_SenOutPtr->S_TJASTM_LatCtrlMode_nu) //!< TJASTM debug macro.
#define	SET_S_TJASTM_LatCtrlMode_nu(val)	(S_TJASTM_LatCtrlMode_nu = (val)) //!< TJASTM debug macro setter.

#undef	S_TJASTM_SysStateTJA_nu
#define	S_TJASTM_SysStateTJA_nu (TJASTM_SenOutPtr->S_TJASTM_SysStateTJA_nu) //!< TJASTM debug macro.
#define	SET_S_TJASTM_SysStateTJA_nu(val)	(S_TJASTM_SysStateTJA_nu = (val)) //!< TJASTM debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TJASTM_PRIVATE_H_
