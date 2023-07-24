/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MFJSCT
  MODULE        : JCNCTR
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     JCNCTR_private.h
//! @brief     (JCNCTR) Module Private Header.

#ifndef JCNCTR_PRIVATE_H_
#define JCNCTR_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define MFJSCT	//!< MFJSCT sub-component input macro switch.
#define JCNCTR	//!< JCNCTR module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "JCNCTR.h"
#include "Bitop.h"  //MFC5J3
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_JCNCTR_SenReset		0xF0 //!< JCNCTR module reset runnable identifier.
#define RUNNABLE_ID_JCNCTR_SenProcess	0xF1 //!< JCNCTR module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/
static JCNCTR_SenDbgType *JCNCTR_SenDbgPtr = NULL; //!< JCNCTR module sensor debug data pointer.
void JCNCTR_SenInitDbgPtr(JCNCTR_SenOutType *JCNCTR_SenDbgArg) { JCNCTR_SenDbgPtr = JCNCTR_SenDbgPtr == NULL ? JCNCTR_SenDbgArg : JCNCTR_SenDbgPtr; }
const JCNCTR_SenDbgType* JCNCTR_SenGetDbgPtr(void) { return (const JCNCTR_SenDbgType*) JCNCTR_SenDbgPtr; }

static JCNCTR_SenOutType *JCNCTR_SenOutPtr = NULL; //!< JCNCTR module sensor output data pointer.
void JCNCTR_SenInitOutPtr(JCNCTR_SenOutType *JCNCTR_SenOutArg) { JCNCTR_SenOutPtr = JCNCTR_SenOutPtr == NULL ? JCNCTR_SenOutArg : JCNCTR_SenOutPtr; }
const JCNCTR_SenOutType* JCNCTR_SenGetOutPtr(void) { return (const JCNCTR_SenOutType*) JCNCTR_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_JCNCTR_PrjSpecQu_btf
#define	S_JCNCTR_PrjSpecQu_btf (JCNCTR_SenOutPtr->S_JCNCTR_PrjSpecQu_btf) //!< JCNCTR debug macro.
#define	SET_S_JCNCTR_PrjSpecQu_btf(val)	(S_JCNCTR_PrjSpecQu_btf = (val)) //!< JCNCTR debug macro setter.

#undef	S_JCNCTR_LDWPrjSpecQu_btf
#define	S_JCNCTR_LDWPrjSpecQu_btf (JCNCTR_SenDbgPtr->S_JCNCTR_LDWPrjSpecQu_btf) //!< JCNCTR debug macro.
#define	SET_S_JCNCTR_LDWPrjSpecQu_btf(val)	(S_JCNCTR_LDWPrjSpecQu_btf = (val)) //!< JCNCTR debug macro setter.

#undef	S_JCNCTR_LKAPrjSpecQu_btf
#define	S_JCNCTR_LKAPrjSpecQu_btf (JCNCTR_SenDbgPtr->S_JCNCTR_LKAPrjSpecQu_btf) //!< JCNCTR debug macro.
#define	SET_S_JCNCTR_LKAPrjSpecQu_btf(val)	(S_JCNCTR_LKAPrjSpecQu_btf = (val)) //!< JCNCTR debug macro setter.

#undef	S_JCNCTR_ELKPrjSpecQu_btf
#define	S_JCNCTR_ELKPrjSpecQu_btf (JCNCTR_SenDbgPtr->S_JCNCTR_ELKPrjSpecQu_btf) //!< JCNCTR debug macro.
#define	SET_S_JCNCTR_ELKPrjSpecQu_btf(val)	(S_JCNCTR_ELKPrjSpecQu_btf = (val)) //!< JCNCTR debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // JCNCTR_PRIVATE_H_
