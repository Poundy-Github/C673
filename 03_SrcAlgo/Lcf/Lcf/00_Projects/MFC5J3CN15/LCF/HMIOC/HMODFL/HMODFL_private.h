/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3CN15
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : HMIOC
  MODULE        : HMODFL
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     HMODFL_private.h
//! @brief     (HMODFL) Module Private Header.

#ifndef HMODFL_PRIVATE_H_
#define HMODFL_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define HMIOC	//!< HMIOC sub-component input macro switch.
#define HMODFL	//!< HMODFL module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "HMODFL.h"
#include "Bitop.h"
#include "HMODFL_type.h"  //MFC5J3CN15

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_HMODFL_SenReset		0xF0 //!< HMODFL module reset runnable identifier.
#define RUNNABLE_ID_HMODFL_SenProcess	0xF1 //!< HMODFL module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static HMODFL_SenOutType *HMODFL_SenOutPtr = NULL; //!< HMODFL module sensor output data pointer.
void HMODFL_SenInitOutPtr(HMODFL_SenOutType *HMODFL_SenOutArg) { HMODFL_SenOutPtr = HMODFL_SenOutPtr == NULL ? HMODFL_SenOutArg : HMODFL_SenOutPtr; }
const HMODFL_SenOutType* HMODFL_SenGetOutPtr(void) { return (const HMODFL_SenOutType*) HMODFL_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_HMODFL_AvailableFunction_btf
#define	S_HMODFL_AvailableFunction_btf (HMODFL_SenOutPtr->S_HMODFL_AvailableFunction_btf) //!< HMODFL debug macro.
#define	SET_S_HMODFL_AvailableFunction_btf(val)	(S_HMODFL_AvailableFunction_btf = (val)) //!< HMODFL debug macro setter.

#undef	S_HMODFL_LKAInforStatus_nu
#define	S_HMODFL_LKAInforStatus_nu (HMODFL_SenOutPtr->S_HMODFL_LKAInforStatus_nu) //!< HMODFL debug macro.
#define	SET_S_HMODFL_LKAInforStatus_nu(val)	(S_HMODFL_LKAInforStatus_nu = (val)) //!< HMODFL debug macro setter.

#undef	S_HMODFL_LKAStatusChange_nu
#define	S_HMODFL_LKAStatusChange_nu (HMODFL_SenOutPtr->S_HMODFL_LKAStatusChange_nu) //!< HMODFL debug macro.
#define	SET_S_HMODFL_LKAStatusChange_nu(val)	(S_HMODFL_LKAStatusChange_nu = (val)) //!< HMODFL debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // HMODFL_PRIVATE_H_
