/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULE        : MCTLFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MCTLFC_private.h
//! @brief     (MCTLFC) Module Private Header.

#ifndef MCTLFC_PRIVATE_H_
#define MCTLFC_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define MDCTR	//!< MDCTR sub-component input macro switch.
#define MCTLFC	//!< MCTLFC module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "MCTLFC.h"
#include "ecmath.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_MCTLFC_SenReset		0xF0 //!< MCTLFC module reset runnable identifier.
#define RUNNABLE_ID_MCTLFC_SenProcess	0xF1 //!< MCTLFC module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static MCTLFC_SenOutType *MCTLFC_SenOutPtr = NULL; //!< MCTLFC module sensor output data pointer.
void MCTLFC_SenInitOutPtr(MCTLFC_SenOutType *MCTLFC_SenOutArg) { MCTLFC_SenOutPtr = MCTLFC_SenOutPtr == NULL ? MCTLFC_SenOutArg : MCTLFC_SenOutPtr; }
const MCTLFC_SenOutType* MCTLFC_SenGetOutPtr(void) { return (const MCTLFC_SenOutType*) MCTLFC_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_MCTLFC_ControllingFunction_nu
#define	S_MCTLFC_ControllingFunction_nu (MCTLFC_SenOutPtr->S_MCTLFC_ControllingFunction_nu) //!< MCTLFC debug macro.
#define	SET_S_MCTLFC_ControllingFunction_nu(val)	(S_MCTLFC_ControllingFunction_nu = (val)) //!< MCTLFC debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // MCTLFC_PRIVATE_H_
