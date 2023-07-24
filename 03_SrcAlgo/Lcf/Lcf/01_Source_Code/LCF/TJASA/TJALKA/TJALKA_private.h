/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJALKA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJALKA_private.h
//! @brief     (TJALKA) Module Private Header.

#ifndef TJALKA_PRIVATE_H_
#define TJALKA_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJALKA	//!< TJALKA module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJALKA.h"
#include "Bitop.h"  //MFC5J3
#include "ecmath.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TJALKA_SenReset		0xF0 //!< TJALKA module reset runnable identifier.
#define RUNNABLE_ID_TJALKA_SenProcess	0xF1 //!< TJALKA module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJALKA_SenDbgType *TJALKA_SenDbgPtr = NULL; //!< TJALKA module sensor debug data pointer.
void TJALKA_SenInitDbgPtr(TJALKA_SenDbgType *TJALKA_SenDbgArg) { TJALKA_SenDbgPtr = TJALKA_SenDbgPtr == NULL ? TJALKA_SenDbgArg : TJALKA_SenDbgPtr; }
const TJALKA_SenDbgType* TJALKA_SenGetDbgPtr(void) { return (const TJALKA_SenDbgType*) TJALKA_SenDbgPtr; }

static TJALKA_SenOutType *TJALKA_SenOutPtr = NULL; //!< TJALKA module sensor output data pointer.
void TJALKA_SenInitOutPtr(TJALKA_SenOutType *TJALKA_SenOutArg) { TJALKA_SenOutPtr = TJALKA_SenOutPtr == NULL ? TJALKA_SenOutArg : TJALKA_SenOutPtr; }
const TJALKA_SenOutType* TJALKA_SenGetOutPtr(void) { return (const TJALKA_SenOutType*) TJALKA_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJALKA_LaneCenterInvalid_btf
#define	D_TJALKA_LaneCenterInvalid_btf (TJALKA_SenDbgPtr->D_TJALKA_LaneCenterInvalid_btf) //!< TJALKA debug macro.
#define	SET_D_TJALKA_LaneCenterInvalid_btf(val)	(D_TJALKA_LaneCenterInvalid_btf = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_Cancel_bool
#define	S_TJALKA_Cancel_bool (TJALKA_SenDbgPtr->S_TJALKA_Cancel_bool) //!< TJALKA debug macro.
#define	SET_S_TJALKA_Cancel_bool(val)	(S_TJALKA_Cancel_bool = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_LanePredictValid_bool
#define	S_TJALKA_LanePredictValid_bool (TJALKA_SenDbgPtr->S_TJALKA_LanePredictValid_bool) //!< TJALKA debug macro.
#define	SET_S_TJALKA_LanePredictValid_bool(val)	(S_TJALKA_LanePredictValid_bool = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_LnBndValid_nu
#define	S_TJALKA_LnBndValid_nu (TJALKA_SenDbgPtr->S_TJALKA_LnBndValid_nu) //!< TJALKA debug macro.
#define	SET_S_TJALKA_LnBndValid_nu(val)	(S_TJALKA_LnBndValid_nu = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_StrongReady_bool
#define	S_TJALKA_StrongReady_bool (TJALKA_SenDbgPtr->S_TJALKA_StrongReady_bool) //!< TJALKA debug macro.
#define	SET_S_TJALKA_StrongReady_bool(val)	(S_TJALKA_StrongReady_bool = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_WeakReady_bool
#define	S_TJALKA_WeakReady_bool (TJALKA_SenDbgPtr->S_TJALKA_WeakReady_bool) //!< TJALKA debug macro.
#define	SET_S_TJALKA_WeakReady_bool(val)	(S_TJALKA_WeakReady_bool = (val)) //!< TJALKA debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJALKA_LaneInvalid_btf
#define	D_TJALKA_LaneInvalid_btf (TJALKA_SenOutPtr->D_TJALKA_LaneInvalid_btf) //!< TJALKA debug macro.
#define	SET_D_TJALKA_LaneInvalid_btf(val)	(D_TJALKA_LaneInvalid_btf = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_CombinedLaneSR_bool
#define	S_TJALKA_CombinedLaneSR_bool (TJALKA_SenOutPtr->S_TJALKA_CombinedLaneSR_bool) //!< TJALKA debug macro.
#define	SET_S_TJALKA_CombinedLaneSR_bool(val)	(S_TJALKA_CombinedLaneSR_bool = (val)) //!< TJALKA debug macro setter.

#undef	S_TJALKA_CombinedLaneWR_bool
#define	S_TJALKA_CombinedLaneWR_bool (TJALKA_SenOutPtr->S_TJALKA_CombinedLaneWR_bool) //!< TJALKA debug macro.
#define	SET_S_TJALKA_CombinedLaneWR_bool(val)	(S_TJALKA_CombinedLaneWR_bool = (val)) //!< TJALKA debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TJALKA_PRIVATE_H_
