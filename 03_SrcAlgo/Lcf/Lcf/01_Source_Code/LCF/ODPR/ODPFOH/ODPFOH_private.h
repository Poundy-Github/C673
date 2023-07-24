/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOH
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.8 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:20:45CEST $
  $Log: ODPFOH_private.h  $
  Revision 1.8 2020/04/09 14:20:45CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.7 2019/11/29 09:02:25CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOH_private.h
//! @brief     (ODPFOH) Module Private Header.

#ifndef ODPFOH_PRIVATE_H_
#define ODPFOH_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ODPR	//!< ODPR sub-component input macro switch.
#define ODPFOH	//!< ODPFOH module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ODPFOH.h"
#include "Bitop.h"  //MFC5J3
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

#define RUNNABLE_ID_ODPFOH_SenReset		0xF0 //!< ODPFOH module reset runnable identifier.
#define RUNNABLE_ID_ODPFOH_SenProcess	0xF1 //!< ODPFOH module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static ODPFOH_SenDbgType *ODPFOH_SenDbgPtr = NULL; //!< ODPFOH module sensor debug data pointer.
void ODPFOH_SenInitDbgPtr(ODPFOH_SenDbgType *ODPFOH_SenDbgArg) { ODPFOH_SenDbgPtr = ODPFOH_SenDbgPtr == NULL ? ODPFOH_SenDbgArg : ODPFOH_SenDbgPtr; }
const ODPFOH_SenDbgType* ODPFOH_SenGetDbgPtr(void) { return (const ODPFOH_SenDbgType*) ODPFOH_SenDbgPtr; }

static ODPFOH_SenOutType *ODPFOH_SenOutPtr = NULL; //!< ODPFOH module sensor output data pointer.
void ODPFOH_SenInitOutPtr(ODPFOH_SenOutType *ODPFOH_SenOutArg) { ODPFOH_SenOutPtr = ODPFOH_SenOutPtr == NULL ? ODPFOH_SenOutArg : ODPFOH_SenOutPtr; }
const ODPFOH_SenOutType* ODPFOH_SenGetOutPtr(void) { return (const ODPFOH_SenOutType*) ODPFOH_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_ODPFOH_AddNewSample_bool
#define	D_ODPFOH_AddNewSample_bool (ODPFOH_SenDbgPtr->D_ODPFOH_AddNewSample_bool) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_AddNewSample_bool(val)	(D_ODPFOH_AddNewSample_bool = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_LastStoredPntAge_sec
#define	D_ODPFOH_LastStoredPntAge_sec (ODPFOH_SenDbgPtr->D_ODPFOH_LastStoredPntAge_sec) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_LastStoredPntAge_sec(val)	(D_ODPFOH_LastStoredPntAge_sec = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_LastStoredPntX_met
#define	D_ODPFOH_LastStoredPntX_met (ODPFOH_SenDbgPtr->D_ODPFOH_LastStoredPntX_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_LastStoredPntX_met(val)	(D_ODPFOH_LastStoredPntX_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_LastStoredPntY_met
#define	D_ODPFOH_LastStoredPntY_met (ODPFOH_SenDbgPtr->D_ODPFOH_LastStoredPntY_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_LastStoredPntY_met(val)	(D_ODPFOH_LastStoredPntY_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_MaxGapEgoToHist_met
#define	D_ODPFOH_MaxGapEgoToHist_met (ODPFOH_SenDbgPtr->D_ODPFOH_MaxGapEgoToHist_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_MaxGapEgoToHist_met(val)	(D_ODPFOH_MaxGapEgoToHist_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_MeanDevToTraj_1st_met
#define	D_ODPFOH_MeanDevToTraj_1st_met (ODPFOH_SenDbgPtr->D_ODPFOH_MeanDevToTraj_1st_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_MeanDevToTraj_1st_met(val)	(D_ODPFOH_MeanDevToTraj_1st_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_MeanDevToTraj_3rd_met
#define	D_ODPFOH_MeanDevToTraj_3rd_met (ODPFOH_SenDbgPtr->D_ODPFOH_MeanDevToTraj_3rd_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_MeanDevToTraj_3rd_met(val)	(D_ODPFOH_MeanDevToTraj_3rd_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_MinHistLength_met
#define	D_ODPFOH_MinHistLength_met (ODPFOH_SenDbgPtr->D_ODPFOH_MinHistLength_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_MinHistLength_met(val)	(D_ODPFOH_MinHistLength_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_MinHistStartPosX_met
#define	D_ODPFOH_MinHistStartPosX_met (ODPFOH_SenDbgPtr->D_ODPFOH_MinHistStartPosX_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_MinHistStartPosX_met(val)	(D_ODPFOH_MinHistStartPosX_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_NumValidSamples_nu
#define	D_ODPFOH_NumValidSamples_nu (ODPFOH_SenDbgPtr->D_ODPFOH_NumValidSamples_nu) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_NumValidSamples_nu(val)	(D_ODPFOH_NumValidSamples_nu = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_AccObjTraceCrv_1pm
#define	S_ODPFOH_AccObjTraceCrv_1pm (ODPFOH_SenDbgPtr->S_ODPFOH_AccObjTraceCrv_1pm) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_AccObjTraceCrv_1pm(val)	(S_ODPFOH_AccObjTraceCrv_1pm = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_ObjTraceCrvQual_perc
#define	S_ODPFOH_ObjTraceCrvQual_perc (ODPFOH_SenDbgPtr->S_ODPFOH_ObjTraceCrvQual_perc) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_ObjTraceCrvQual_perc(val)	(S_ODPFOH_ObjTraceCrvQual_perc = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_ObjTraceQual_perc
#define	S_ODPFOH_ObjTraceQual_perc (ODPFOH_SenDbgPtr->S_ODPFOH_ObjTraceQual_perc) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_ObjTraceQual_perc(val)	(S_ODPFOH_ObjTraceQual_perc = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_ObjTraceStraight_perc
#define	S_ODPFOH_ObjTraceStraight_perc (ODPFOH_SenDbgPtr->S_ODPFOH_ObjTraceStraight_perc) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_ObjTraceStraight_perc(val)	(S_ODPFOH_ObjTraceStraight_perc = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjClothoidInv_btf
#define	S_ODPFOH_TgtObjClothoidInv_btf (ODPFOH_SenDbgPtr->S_ODPFOH_TgtObjClothoidInv_btf) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjClothoidInv_btf(val)	(S_ODPFOH_TgtObjClothoidInv_btf = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjCrv_1pm
#define	S_ODPFOH_TgtObjCrv_1pm (ODPFOH_SenDbgPtr->S_ODPFOH_TgtObjCrv_1pm) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjCrv_1pm(val)	(S_ODPFOH_TgtObjCrv_1pm = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjHeadAng_rad
#define	S_ODPFOH_TgtObjHeadAng_rad (ODPFOH_SenDbgPtr->S_ODPFOH_TgtObjHeadAng_rad) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjHeadAng_rad(val)	(S_ODPFOH_TgtObjHeadAng_rad = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjLength_met
#define	S_ODPFOH_TgtObjLength_met (ODPFOH_SenDbgPtr->S_ODPFOH_TgtObjLength_met) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjLength_met(val)	(S_ODPFOH_TgtObjLength_met = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjPosX0_met
#define	S_ODPFOH_TgtObjPosX0_met (ODPFOH_SenDbgPtr->S_ODPFOH_TgtObjPosX0_met) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjPosX0_met(val)	(S_ODPFOH_TgtObjPosX0_met = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjPosY0_met
#define	S_ODPFOH_TgtObjPosY0_met (ODPFOH_SenDbgPtr->S_ODPFOH_TgtObjPosY0_met) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjPosY0_met(val)	(S_ODPFOH_TgtObjPosY0_met = (val)) //!< ODPFOH debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_ODPFOH_FirstStoredPntAge_sec
#define	D_ODPFOH_FirstStoredPntAge_sec (ODPFOH_SenOutPtr->D_ODPFOH_FirstStoredPntAge_sec) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_FirstStoredPntAge_sec(val)	(D_ODPFOH_FirstStoredPntAge_sec = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_FirstStoredPntX_met
#define	D_ODPFOH_FirstStoredPntX_met (ODPFOH_SenOutPtr->D_ODPFOH_FirstStoredPntX_met) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_FirstStoredPntX_met(val)	(D_ODPFOH_FirstStoredPntX_met = (val)) //!< ODPFOH debug macro setter.

#undef	D_ODPFOH_MeanStoredPntAge_sec
#define	D_ODPFOH_MeanStoredPntAge_sec (ODPFOH_SenOutPtr->D_ODPFOH_MeanStoredPntAge_sec) //!< ODPFOH debug macro.
#define	SET_D_ODPFOH_MeanStoredPntAge_sec(val)	(D_ODPFOH_MeanStoredPntAge_sec = (val)) //!< ODPFOH debug macro setter.

#undef	S_ODPFOH_TgtObjCrvChng_1pm2
#define	S_ODPFOH_TgtObjCrvChng_1pm2 (ODPFOH_SenOutPtr->S_ODPFOH_TgtObjCrvChng_1pm2) //!< ODPFOH debug macro.
#define	SET_S_ODPFOH_TgtObjCrvChng_1pm2(val)	(S_ODPFOH_TgtObjCrvChng_1pm2 = (val)) //!< ODPFOH debug macro setter.

#ifdef __cplusplus
}
#endif

#endif /* ODPFOH_PRIVATE_H_*/
