/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJACMB
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.6 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:23:13CEST $
  $Log: TJACMB_private.h  $
  Revision 1.6 2020/04/09 14:23:13CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.5 2019/11/29 09:05:06CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJACMB_private.h
//! @brief     (TJACMB) Module Private Header.

#ifndef TJACMB_PRIVATE_H_
#define TJACMB_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJACMB	//!< TJACMB module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJACMB.h"
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

#define RUNNABLE_ID_TJACMB_SenReset		0xF0 //!< TJACMB module reset runnable identifier.
#define RUNNABLE_ID_TJACMB_SenProcess	0xF1 //!< TJACMB module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJACMB_SenDbgType *TJACMB_SenDbgPtr = NULL; //!< TJACMB module sensor debug data pointer.
void TJACMB_SenInitDbgPtr(TJACMB_SenDbgType *TJACMB_SenDbgArg) { TJACMB_SenDbgPtr = TJACMB_SenDbgPtr == NULL ? TJACMB_SenDbgArg : TJACMB_SenDbgPtr; }
const TJACMB_SenDbgType* TJACMB_SenGetDbgPtr(void) { return (const TJACMB_SenDbgType*) TJACMB_SenDbgPtr; }

static TJACMB_SenOutType *TJACMB_SenOutPtr = NULL; //!< TJACMB module sensor output data pointer.
void TJACMB_SenInitOutPtr(TJACMB_SenOutType *TJACMB_SenOutArg) { TJACMB_SenOutPtr = TJACMB_SenOutPtr == NULL ? TJACMB_SenOutArg : TJACMB_SenOutPtr; }
const TJACMB_SenOutType* TJACMB_SenGetOutPtr(void) { return (const TJACMB_SenOutType*) TJACMB_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJACMB_CombinedInvalid_btf
#define	D_TJACMB_CombinedInvalid_btf (TJACMB_SenDbgPtr->D_TJACMB_CombinedInvalid_btf) //!< TJACMB debug macro.
#define	SET_D_TJACMB_CombinedInvalid_btf(val)	(D_TJACMB_CombinedInvalid_btf = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_Cancel_bool
#define	S_TJACMB_Cancel_bool (TJACMB_SenDbgPtr->S_TJACMB_Cancel_bool) //!< TJACMB debug macro.
#define	SET_S_TJACMB_Cancel_bool(val)	(S_TJACMB_Cancel_bool = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedCrvChng_1pm2
#define	S_TJACMB_CombinedCrvChng_1pm2 (TJACMB_SenDbgPtr->S_TJACMB_CombinedCrvChng_1pm2) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedCrvChng_1pm2(val)	(S_TJACMB_CombinedCrvChng_1pm2 = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedCrv_1pm
#define	S_TJACMB_CombinedCrv_1pm (TJACMB_SenDbgPtr->S_TJACMB_CombinedCrv_1pm) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedCrv_1pm(val)	(S_TJACMB_CombinedCrv_1pm = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedHeading_rad
#define	S_TJACMB_CombinedHeading_rad (TJACMB_SenDbgPtr->S_TJACMB_CombinedHeading_rad) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedHeading_rad(val)	(S_TJACMB_CombinedHeading_rad = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedLength_met
#define	S_TJACMB_CombinedLength_met (TJACMB_SenDbgPtr->S_TJACMB_CombinedLength_met) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedLength_met(val)	(S_TJACMB_CombinedLength_met = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedPosY0_met
#define	S_TJACMB_CombinedPosY0_met (TJACMB_SenDbgPtr->S_TJACMB_CombinedPosY0_met) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedPosY0_met(val)	(S_TJACMB_CombinedPosY0_met = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_StrongReady_bool
#define	S_TJACMB_StrongReady_bool (TJACMB_SenDbgPtr->S_TJACMB_StrongReady_bool) //!< TJACMB debug macro.
#define	SET_S_TJACMB_StrongReady_bool(val)	(S_TJACMB_StrongReady_bool = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_WeakReady_bool
#define	S_TJACMB_WeakReady_bool (TJACMB_SenDbgPtr->S_TJACMB_WeakReady_bool) //!< TJACMB debug macro.
#define	SET_S_TJACMB_WeakReady_bool(val)	(S_TJACMB_WeakReady_bool = (val)) //!< TJACMB debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJACMB_TransitionInvalid_btf
#define	D_TJACMB_TransitionInvalid_btf (TJACMB_SenOutPtr->D_TJACMB_TransitionInvalid_btf) //!< TJACMB debug macro.
#define	SET_D_TJACMB_TransitionInvalid_btf(val)	(D_TJACMB_TransitionInvalid_btf = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedLePosY0_met
#define	S_TJACMB_CombinedLePosY0_met (TJACMB_SenOutPtr->S_TJACMB_CombinedLePosY0_met) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedLePosY0_met(val)	(S_TJACMB_CombinedLePosY0_met = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedMode_nu
#define	S_TJACMB_CombinedMode_nu (TJACMB_SenOutPtr->S_TJACMB_CombinedMode_nu) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedMode_nu(val)	(S_TJACMB_CombinedMode_nu = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedPosX0_met
#define	S_TJACMB_CombinedPosX0_met (TJACMB_SenOutPtr->S_TJACMB_CombinedPosX0_met) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedPosX0_met(val)	(S_TJACMB_CombinedPosX0_met = (val)) //!< TJACMB debug macro setter.

#undef	S_TJACMB_CombinedRiPosY0_met
#define	S_TJACMB_CombinedRiPosY0_met (TJACMB_SenOutPtr->S_TJACMB_CombinedRiPosY0_met) //!< TJACMB debug macro.
#define	SET_S_TJACMB_CombinedRiPosY0_met(val)	(S_TJACMB_CombinedRiPosY0_met = (val)) //!< TJACMB debug macro setter.

#ifdef __cplusplus
}
#endif

#endif /* TJACMB_PRIVATE_H_*/
