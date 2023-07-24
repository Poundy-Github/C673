/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPREP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPREP_private.h
//! @brief     (ABPREP) Module Private Header.

#ifndef ABPREP_PRIVATE_H_
#define ABPREP_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ABPR	//!< ABPR sub-component input macro switch.
#define ABPREP	//!< ABPREP module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPREP.h"
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

#define RUNNABLE_ID_ABPREP_SenReset		0xF0 //!< ABPREP module reset runnable identifier.
#define RUNNABLE_ID_ABPREP_SenProcess	0xF1 //!< ABPREP module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static ABPREP_SenDbgType *ABPREP_SenDbgPtr = NULL; //!< ABPREP module sensor debug data pointer.
void ABPREP_SenInitDbgPtr(ABPREP_SenDbgType *ABPREP_SenDbgArg) { ABPREP_SenDbgPtr = ABPREP_SenDbgPtr == NULL ? ABPREP_SenDbgArg : ABPREP_SenDbgPtr; }
const ABPREP_SenDbgType* ABPREP_SenGetDbgPtr(void) { return (const ABPREP_SenDbgType*) ABPREP_SenDbgPtr; }

static ABPREP_SenOutType *ABPREP_SenOutPtr = NULL; //!< ABPREP module sensor output data pointer.
void ABPREP_SenInitOutPtr(ABPREP_SenOutType *ABPREP_SenOutArg) { ABPREP_SenOutPtr = ABPREP_SenOutPtr == NULL ? ABPREP_SenOutArg : ABPREP_SenOutPtr; }
const ABPREP_SenOutType* ABPREP_SenGetOutPtr(void) { return (const ABPREP_SenOutType*) ABPREP_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_ABPREP_LaneStabilization_btf
#define	S_ABPREP_LaneStabilization_btf (ABPREP_SenDbgPtr->S_ABPREP_LaneStabilization_btf) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LaneStabilization_btf(val)	(S_ABPREP_LaneStabilization_btf = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReClthCrvChng_1pm2
#define	S_ABPREP_LeReClthCrvChng_1pm2 (ABPREP_SenDbgPtr->S_ABPREP_LeReClthCrvChng_1pm2) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReClthCrvChng_1pm2(val)	(S_ABPREP_LeReClthCrvChng_1pm2 = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReClthCrvSIF_1pm
#define	S_ABPREP_LeReClthCrvSIF_1pm (ABPREP_SenDbgPtr->S_ABPREP_LeReClthCrvSIF_1pm) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReClthCrvSIF_1pm(val)	(S_ABPREP_LeReClthCrvSIF_1pm = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReClthCrv_1pm
#define	S_ABPREP_LeReClthCrv_1pm (ABPREP_SenDbgPtr->S_ABPREP_LeReClthCrv_1pm) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReClthCrv_1pm(val)	(S_ABPREP_LeReClthCrv_1pm = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReClthHeadingSIF_rad
#define	S_ABPREP_LeReClthHeadingSIF_rad (ABPREP_SenDbgPtr->S_ABPREP_LeReClthHeadingSIF_rad) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReClthHeadingSIF_rad(val)	(S_ABPREP_LeReClthHeadingSIF_rad = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReClthPosY0SIF_met
#define	S_ABPREP_LeReClthPosY0SIF_met (ABPREP_SenDbgPtr->S_ABPREP_LeReClthPosY0SIF_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReClthPosY0SIF_met(val)	(S_ABPREP_LeReClthPosY0SIF_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReHeading_rad
#define	S_ABPREP_LeReHeading_rad (ABPREP_SenDbgPtr->S_ABPREP_LeReHeading_rad) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReHeading_rad(val)	(S_ABPREP_LeReHeading_rad = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReInvalidQuSIF_btf
#define	S_ABPREP_LeReInvalidQuSIF_btf (ABPREP_SenDbgPtr->S_ABPREP_LeReInvalidQuSIF_btf) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReInvalidQuSIF_btf(val)	(S_ABPREP_LeReInvalidQuSIF_btf = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReInvalidQu_btf
#define	S_ABPREP_LeReInvalidQu_btf (ABPREP_SenDbgPtr->S_ABPREP_LeReInvalidQu_btf) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReInvalidQu_btf(val)	(S_ABPREP_LeReInvalidQu_btf = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReKFQuality_perc
#define	S_ABPREP_LeReKFQuality_perc (ABPREP_SenDbgPtr->S_ABPREP_LeReKFQuality_perc) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReKFQuality_perc(val)	(S_ABPREP_LeReKFQuality_perc = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReKFStatus_enum
#define	S_ABPREP_LeReKFStatus_enum (ABPREP_SenDbgPtr->S_ABPREP_LeReKFStatus_enum) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReKFStatus_enum(val)	(S_ABPREP_LeReKFStatus_enum = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReLatVel_mps
#define	S_ABPREP_LeReLatVel_mps (ABPREP_SenDbgPtr->S_ABPREP_LeReLatVel_mps) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReLatVel_mps(val)	(S_ABPREP_LeReLatVel_mps = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReLength_met
#define	S_ABPREP_LeReLength_met (ABPREP_SenDbgPtr->S_ABPREP_LeReLength_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReLength_met(val)	(S_ABPREP_LeReLength_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeRePosY0_met
#define	S_ABPREP_LeRePosY0_met (ABPREP_SenDbgPtr->S_ABPREP_LeRePosY0_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeRePosY0_met(val)	(S_ABPREP_LeRePosY0_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LeReQuality_perc
#define	S_ABPREP_LeReQuality_perc (ABPREP_SenDbgPtr->S_ABPREP_LeReQuality_perc) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReQuality_perc(val)	(S_ABPREP_LeReQuality_perc = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_LnBndGradLimActive_btf
#define	S_ABPREP_LnBndGradLimActive_btf (ABPREP_SenDbgPtr->S_ABPREP_LnBndGradLimActive_btf) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LnBndGradLimActive_btf(val)	(S_ABPREP_LnBndGradLimActive_btf = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReClthCrvChng_1pm2
#define	S_ABPREP_RiReClthCrvChng_1pm2 (ABPREP_SenDbgPtr->S_ABPREP_RiReClthCrvChng_1pm2) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReClthCrvChng_1pm2(val)	(S_ABPREP_RiReClthCrvChng_1pm2 = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReClthCrvSIF_1pm
#define	S_ABPREP_RiReClthCrvSIF_1pm (ABPREP_SenDbgPtr->S_ABPREP_RiReClthCrvSIF_1pm) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReClthCrvSIF_1pm(val)	(S_ABPREP_RiReClthCrvSIF_1pm = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReClthCrv_1pm
#define	S_ABPREP_RiReClthCrv_1pm (ABPREP_SenDbgPtr->S_ABPREP_RiReClthCrv_1pm) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReClthCrv_1pm(val)	(S_ABPREP_RiReClthCrv_1pm = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReClthHeadingSIF_rad
#define	S_ABPREP_RiReClthHeadingSIF_rad (ABPREP_SenDbgPtr->S_ABPREP_RiReClthHeadingSIF_rad) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReClthHeadingSIF_rad(val)	(S_ABPREP_RiReClthHeadingSIF_rad = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReClthPosY0SIF_met
#define	S_ABPREP_RiReClthPosY0SIF_met (ABPREP_SenDbgPtr->S_ABPREP_RiReClthPosY0SIF_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReClthPosY0SIF_met(val)	(S_ABPREP_RiReClthPosY0SIF_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReHeading_rad
#define	S_ABPREP_RiReHeading_rad (ABPREP_SenDbgPtr->S_ABPREP_RiReHeading_rad) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReHeading_rad(val)	(S_ABPREP_RiReHeading_rad = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReInvalidQuSIF_btf
#define	S_ABPREP_RiReInvalidQuSIF_btf (ABPREP_SenDbgPtr->S_ABPREP_RiReInvalidQuSIF_btf) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReInvalidQuSIF_btf(val)	(S_ABPREP_RiReInvalidQuSIF_btf = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReInvalidQu_btf
#define	S_ABPREP_RiReInvalidQu_btf (ABPREP_SenDbgPtr->S_ABPREP_RiReInvalidQu_btf) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReInvalidQu_btf(val)	(S_ABPREP_RiReInvalidQu_btf = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReKFQuality_perc
#define	S_ABPREP_RiReKFQuality_perc (ABPREP_SenDbgPtr->S_ABPREP_RiReKFQuality_perc) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReKFQuality_perc(val)	(S_ABPREP_RiReKFQuality_perc = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReKFStatus_enum
#define	S_ABPREP_RiReKFStatus_enum (ABPREP_SenDbgPtr->S_ABPREP_RiReKFStatus_enum) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReKFStatus_enum(val)	(S_ABPREP_RiReKFStatus_enum = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReLatVel_mps
#define	S_ABPREP_RiReLatVel_mps (ABPREP_SenDbgPtr->S_ABPREP_RiReLatVel_mps) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReLatVel_mps(val)	(S_ABPREP_RiReLatVel_mps = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReLength_met
#define	S_ABPREP_RiReLength_met (ABPREP_SenDbgPtr->S_ABPREP_RiReLength_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReLength_met(val)	(S_ABPREP_RiReLength_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiRePosY0_met
#define	S_ABPREP_RiRePosY0_met (ABPREP_SenDbgPtr->S_ABPREP_RiRePosY0_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiRePosY0_met(val)	(S_ABPREP_RiRePosY0_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReQuality_perc
#define	S_ABPREP_RiReQuality_perc (ABPREP_SenDbgPtr->S_ABPREP_RiReQuality_perc) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReQuality_perc(val)	(S_ABPREP_RiReQuality_perc = (val)) //!< ABPREP debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_ABPREP_LeReClthPosX0_met
#define	S_ABPREP_LeReClthPosX0_met (ABPREP_SenOutPtr->S_ABPREP_LeReClthPosX0_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_LeReClthPosX0_met(val)	(S_ABPREP_LeReClthPosX0_met = (val)) //!< ABPREP debug macro setter.

#undef	S_ABPREP_RiReClthPosX0_met
#define	S_ABPREP_RiReClthPosX0_met (ABPREP_SenOutPtr->S_ABPREP_RiReClthPosX0_met) //!< ABPREP debug macro.
#define	SET_S_ABPREP_RiReClthPosX0_met(val)	(S_ABPREP_RiReClthPosX0_met = (val)) //!< ABPREP debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // ABPREP_PRIVATE_H_
