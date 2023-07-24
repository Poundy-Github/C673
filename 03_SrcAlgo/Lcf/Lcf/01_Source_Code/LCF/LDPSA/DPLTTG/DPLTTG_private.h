/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLTTG_private.h
//! @brief     (DPLTTG) Module Private Header.

#ifndef DPLTTG_PRIVATE_H_
#define DPLTTG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define LDPSA	//!< LDPSA sub-component input macro switch.
#define DPLTTG	//!< DPLTTG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLTTG.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DPLTTG_SenReset		0xF0 //!< DPLTTG module reset runnable identifier.
#define RUNNABLE_ID_DPLTTG_SenProcess	0xF1 //!< DPLTTG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPLTTG_SenDbgType *DPLTTG_SenDbgPtr = NULL; //!< DPLTTG module sensor debug data pointer.
void DPLTTG_SenInitDbgPtr(DPLTTG_SenDbgType *DPLTTG_SenDbgArg) { DPLTTG_SenDbgPtr = DPLTTG_SenDbgPtr == NULL ? DPLTTG_SenDbgArg : DPLTTG_SenDbgPtr; }
const DPLTTG_SenDbgType* DPLTTG_SenGetDbgPtr(void) { return (const DPLTTG_SenDbgType*) DPLTTG_SenDbgPtr; }

static DPLTTG_SenOutType *DPLTTG_SenOutPtr = NULL; //!< DPLTTG module sensor output data pointer.
void DPLTTG_SenInitOutPtr(DPLTTG_SenOutType *DPLTTG_SenOutArg) { DPLTTG_SenOutPtr = DPLTTG_SenOutPtr == NULL ? DPLTTG_SenOutArg : DPLTTG_SenOutPtr; }
const DPLTTG_SenOutType* DPLTTG_SenGetOutPtr(void) { return (const DPLTTG_SenOutType*) DPLTTG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPLTTG_LeTgtTrajPosY0_met
#define	S_DPLTTG_LeTgtTrajPosY0_met (DPLTTG_SenDbgPtr->S_DPLTTG_LeTgtTrajPosY0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeTgtTrajPosY0_met(val)	(S_DPLTTG_LeTgtTrajPosY0_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiTgtTrajPosY0_met
#define	S_DPLTTG_RiTgtTrajPosY0_met (DPLTTG_SenDbgPtr->S_DPLTTG_RiTgtTrajPosY0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiTgtTrajPosY0_met(val)	(S_DPLTTG_RiTgtTrajPosY0_met = (val)) //!< DPLTTG debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPLTTG_LeCridrBndCrvChng_1pm2
#define	S_DPLTTG_LeCridrBndCrvChng_1pm2 (DPLTTG_SenOutPtr->S_DPLTTG_LeCridrBndCrvChng_1pm2) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeCridrBndCrvChng_1pm2(val)	(S_DPLTTG_LeCridrBndCrvChng_1pm2 = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_LeCridrBndCrv_1pm
#define	S_DPLTTG_LeCridrBndCrv_1pm (DPLTTG_SenOutPtr->S_DPLTTG_LeCridrBndCrv_1pm) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeCridrBndCrv_1pm(val)	(S_DPLTTG_LeCridrBndCrv_1pm = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_LeCridrBndHeadAng_rad
#define	S_DPLTTG_LeCridrBndHeadAng_rad (DPLTTG_SenOutPtr->S_DPLTTG_LeCridrBndHeadAng_rad) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeCridrBndHeadAng_rad(val)	(S_DPLTTG_LeCridrBndHeadAng_rad = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_LeCridrBndLength_met
#define	S_DPLTTG_LeCridrBndLength_met (DPLTTG_SenOutPtr->S_DPLTTG_LeCridrBndLength_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeCridrBndLength_met(val)	(S_DPLTTG_LeCridrBndLength_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_LeCridrBndPosX0_met
#define	S_DPLTTG_LeCridrBndPosX0_met (DPLTTG_SenOutPtr->S_DPLTTG_LeCridrBndPosX0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeCridrBndPosX0_met(val)	(S_DPLTTG_LeCridrBndPosX0_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_LeCridrBndPosY0_met
#define	S_DPLTTG_LeCridrBndPosY0_met (DPLTTG_SenOutPtr->S_DPLTTG_LeCridrBndPosY0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_LeCridrBndPosY0_met(val)	(S_DPLTTG_LeCridrBndPosY0_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiCridrBndCrvChng_1pm2
#define	S_DPLTTG_RiCridrBndCrvChng_1pm2 (DPLTTG_SenOutPtr->S_DPLTTG_RiCridrBndCrvChng_1pm2) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiCridrBndCrvChng_1pm2(val)	(S_DPLTTG_RiCridrBndCrvChng_1pm2 = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiCridrBndCrv_1pm
#define	S_DPLTTG_RiCridrBndCrv_1pm (DPLTTG_SenOutPtr->S_DPLTTG_RiCridrBndCrv_1pm) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiCridrBndCrv_1pm(val)	(S_DPLTTG_RiCridrBndCrv_1pm = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiCridrBndHeadAng_rad
#define	S_DPLTTG_RiCridrBndHeadAng_rad (DPLTTG_SenOutPtr->S_DPLTTG_RiCridrBndHeadAng_rad) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiCridrBndHeadAng_rad(val)	(S_DPLTTG_RiCridrBndHeadAng_rad = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiCridrBndLength_met
#define	S_DPLTTG_RiCridrBndLength_met (DPLTTG_SenOutPtr->S_DPLTTG_RiCridrBndLength_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiCridrBndLength_met(val)	(S_DPLTTG_RiCridrBndLength_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiCridrBndPosX0_met
#define	S_DPLTTG_RiCridrBndPosX0_met (DPLTTG_SenOutPtr->S_DPLTTG_RiCridrBndPosX0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiCridrBndPosX0_met(val)	(S_DPLTTG_RiCridrBndPosX0_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_RiCridrBndPosY0_met
#define	S_DPLTTG_RiCridrBndPosY0_met (DPLTTG_SenOutPtr->S_DPLTTG_RiCridrBndPosY0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_RiCridrBndPosY0_met(val)	(S_DPLTTG_RiCridrBndPosY0_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_TgtTrajCrvChng_1pm2
#define	S_DPLTTG_TgtTrajCrvChng_1pm2 (DPLTTG_SenOutPtr->S_DPLTTG_TgtTrajCrvChng_1pm2) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_TgtTrajCrvChng_1pm2(val)	(S_DPLTTG_TgtTrajCrvChng_1pm2 = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_TgtTrajCrv_1pm
#define	S_DPLTTG_TgtTrajCrv_1pm (DPLTTG_SenOutPtr->S_DPLTTG_TgtTrajCrv_1pm) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_TgtTrajCrv_1pm(val)	(S_DPLTTG_TgtTrajCrv_1pm = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_TgtTrajHeadAng_rad
#define	S_DPLTTG_TgtTrajHeadAng_rad (DPLTTG_SenOutPtr->S_DPLTTG_TgtTrajHeadAng_rad) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_TgtTrajHeadAng_rad(val)	(S_DPLTTG_TgtTrajHeadAng_rad = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_TgtTrajLength_met
#define	S_DPLTTG_TgtTrajLength_met (DPLTTG_SenOutPtr->S_DPLTTG_TgtTrajLength_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_TgtTrajLength_met(val)	(S_DPLTTG_TgtTrajLength_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_TgtTrajPosX0_met
#define	S_DPLTTG_TgtTrajPosX0_met (DPLTTG_SenOutPtr->S_DPLTTG_TgtTrajPosX0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_TgtTrajPosX0_met(val)	(S_DPLTTG_TgtTrajPosX0_met = (val)) //!< DPLTTG debug macro setter.

#undef	S_DPLTTG_TgtTrajPosY0_met
#define	S_DPLTTG_TgtTrajPosY0_met (DPLTTG_SenOutPtr->S_DPLTTG_TgtTrajPosY0_met) //!< DPLTTG debug macro.
#define	SET_S_DPLTTG_TgtTrajPosY0_met(val)	(S_DPLTTG_TgtTrajPosY0_met = (val)) //!< DPLTTG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPLTTG_PRIVATE_H_
