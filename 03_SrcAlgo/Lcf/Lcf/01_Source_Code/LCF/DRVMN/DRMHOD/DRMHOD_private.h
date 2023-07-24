/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMHOD
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMHOD_private.h
//! @brief     (DRMHOD) Module Private Header.

#ifndef DRMHOD_PRIVATE_H_
#define DRMHOD_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define DRVMN	//!< DRVMN sub-component input macro switch.
#define DRMHOD	//!< DRMHOD module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRMHOD.h"
#include "ecmath.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DRMHOD_VehReset		0xF0 //!< DRMHOD module reset runnable identifier.
#define RUNNABLE_ID_DRMHOD_VehProcess	0xF1 //!< DRMHOD module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DRMHOD_VehDbgType *DRMHOD_VehDbgPtr = NULL; //!< DRMHOD module vehicle debug data pointer.
void DRMHOD_VehInitDbgPtr(DRMHOD_VehDbgType *DRMHOD_VehDbgArg) { DRMHOD_VehDbgPtr = DRMHOD_VehDbgPtr == NULL ? DRMHOD_VehDbgArg : DRMHOD_VehDbgPtr; }
const DRMHOD_VehDbgType* DRMHOD_VehGetDbgPtr(void) { return (const DRMHOD_VehDbgType*) DRMHOD_VehDbgPtr; }

static DRMHOD_VehOutType *DRMHOD_VehOutPtr = NULL; //!< DRMHOD module vehicle output data pointer.
void DRMHOD_VehInitOutPtr(DRMHOD_VehOutType *DRMHOD_VehOutArg) { DRMHOD_VehOutPtr = DRMHOD_VehOutPtr == NULL ? DRMHOD_VehOutArg : DRMHOD_VehOutPtr; }
const DRMHOD_VehOutType* DRMHOD_VehGetOutPtr(void) { return (const DRMHOD_VehOutType*) DRMHOD_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DRMHOD_EstHandTor_Nm
#define	D_DRMHOD_EstHandTor_Nm (DRMHOD_VehDbgPtr->D_DRMHOD_EstHandTor_Nm) //!< DRMHOD debug macro.
#define	SET_D_DRMHOD_EstHandTor_Nm(val)	(D_DRMHOD_EstHandTor_Nm = (val)) //!< DRMHOD debug macro setter.

#undef	S_DRMHOD_HandsOffConfirmed_bool
#define	S_DRMHOD_HandsOffConfirmed_bool (DRMHOD_VehDbgPtr->S_DRMHOD_HandsOffConfirmed_bool) //!< DRMHOD debug macro.
#define	SET_S_DRMHOD_HandsOffConfirmed_bool(val)	(S_DRMHOD_HandsOffConfirmed_bool = (val)) //!< DRMHOD debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DRMHOD_CorrectedTorque_Nm
#define	D_DRMHOD_CorrectedTorque_Nm (DRMHOD_VehOutPtr->D_DRMHOD_CorrectedTorque_Nm) //!< DRMHOD debug macro.
#define	SET_D_DRMHOD_CorrectedTorque_Nm(val)	(D_DRMHOD_CorrectedTorque_Nm = (val)) //!< DRMHOD debug macro setter.

#undef	D_DRMHOD_EstHandTorCounter_nu
#define	D_DRMHOD_EstHandTorCounter_nu (DRMHOD_VehOutPtr->D_DRMHOD_EstHandTorCounter_nu) //!< DRMHOD debug macro.
#define	SET_D_DRMHOD_EstHandTorCounter_nu(val)	(D_DRMHOD_EstHandTorCounter_nu = (val)) //!< DRMHOD debug macro setter.

#undef	D_DRMHOD_EstHandTorState_nu
#define	D_DRMHOD_EstHandTorState_nu (DRMHOD_VehOutPtr->D_DRMHOD_EstHandTorState_nu) //!< DRMHOD debug macro.
#define	SET_D_DRMHOD_EstHandTorState_nu(val)	(D_DRMHOD_EstHandTorState_nu = (val)) //!< DRMHOD debug macro setter.

#undef	D_DRMHOD_HdOffDtctStatus_nu
#define	D_DRMHOD_HdOffDtctStatus_nu (DRMHOD_VehOutPtr->D_DRMHOD_HdOffDtctStatus_nu) //!< DRMHOD debug macro.
#define	SET_D_DRMHOD_HdOffDtctStatus_nu(val)	(D_DRMHOD_HdOffDtctStatus_nu = (val)) //!< DRMHOD debug macro setter.

#undef	D_DRMHOD_LowPassC
#define	D_DRMHOD_LowPassC (DRMHOD_VehOutPtr->D_DRMHOD_LowPassC) //!< DRMHOD debug macro.
#define	SET_D_DRMHOD_LowPassC(val)	(D_DRMHOD_LowPassC = (val)) //!< DRMHOD debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DRMHOD_PRIVATE_H_
