/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRTTG_private.h
//! @brief     (DPRTTG) Module Private Header.

#ifndef DPRTTG_PRIVATE_H_
#define DPRTTG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define RDPSA	//!< RDPSA sub-component input macro switch.
#define DPRTTG	//!< DPRTTG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRTTG.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DPRTTG_SenReset		0xF0 //!< DPRTTG module reset runnable identifier.
#define RUNNABLE_ID_DPRTTG_SenProcess	0xF1 //!< DPRTTG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPRTTG_SenDbgType *DPRTTG_SenDbgPtr = NULL; //!< DPRTTG module sensor debug data pointer.
void DPRTTG_SenInitDbgPtr(DPRTTG_SenDbgType *DPRTTG_SenDbgArg) { DPRTTG_SenDbgPtr = DPRTTG_SenDbgPtr == NULL ? DPRTTG_SenDbgArg : DPRTTG_SenDbgPtr; }
const DPRTTG_SenDbgType* DPRTTG_SenGetDbgPtr(void) { return (const DPRTTG_SenDbgType*) DPRTTG_SenDbgPtr; }

static DPRTTG_SenOutType *DPRTTG_SenOutPtr = NULL; //!< DPRTTG module sensor output data pointer.
void DPRTTG_SenInitOutPtr(DPRTTG_SenOutType *DPRTTG_SenOutArg) { DPRTTG_SenOutPtr = DPRTTG_SenOutPtr == NULL ? DPRTTG_SenOutArg : DPRTTG_SenOutPtr; }
const DPRTTG_SenOutType* DPRTTG_SenGetOutPtr(void) { return (const DPRTTG_SenOutType*) DPRTTG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPRTTG_LeTgtTrajPosY0_met
#define	S_DPRTTG_LeTgtTrajPosY0_met (DPRTTG_SenDbgPtr->S_DPRTTG_LeTgtTrajPosY0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeTgtTrajPosY0_met(val)	(S_DPRTTG_LeTgtTrajPosY0_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiTgtTrajPosY0_met
#define	S_DPRTTG_RiTgtTrajPosY0_met (DPRTTG_SenDbgPtr->S_DPRTTG_RiTgtTrajPosY0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiTgtTrajPosY0_met(val)	(S_DPRTTG_RiTgtTrajPosY0_met = (val)) //!< DPRTTG debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DPRTTG_LeCridrBndCrvChng_1pm2
#define	S_DPRTTG_LeCridrBndCrvChng_1pm2 (DPRTTG_SenOutPtr->S_DPRTTG_LeCridrBndCrvChng_1pm2) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeCridrBndCrvChng_1pm2(val)	(S_DPRTTG_LeCridrBndCrvChng_1pm2 = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_LeCridrBndCrv_1pm
#define	S_DPRTTG_LeCridrBndCrv_1pm (DPRTTG_SenOutPtr->S_DPRTTG_LeCridrBndCrv_1pm) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeCridrBndCrv_1pm(val)	(S_DPRTTG_LeCridrBndCrv_1pm = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_LeCridrBndHeadAng_rad
#define	S_DPRTTG_LeCridrBndHeadAng_rad (DPRTTG_SenOutPtr->S_DPRTTG_LeCridrBndHeadAng_rad) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeCridrBndHeadAng_rad(val)	(S_DPRTTG_LeCridrBndHeadAng_rad = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_LeCridrBndLength_met
#define	S_DPRTTG_LeCridrBndLength_met (DPRTTG_SenOutPtr->S_DPRTTG_LeCridrBndLength_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeCridrBndLength_met(val)	(S_DPRTTG_LeCridrBndLength_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_LeCridrBndPosX0_met
#define	S_DPRTTG_LeCridrBndPosX0_met (DPRTTG_SenOutPtr->S_DPRTTG_LeCridrBndPosX0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeCridrBndPosX0_met(val)	(S_DPRTTG_LeCridrBndPosX0_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_LeCridrBndPosY0_met
#define	S_DPRTTG_LeCridrBndPosY0_met (DPRTTG_SenOutPtr->S_DPRTTG_LeCridrBndPosY0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_LeCridrBndPosY0_met(val)	(S_DPRTTG_LeCridrBndPosY0_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiCridrBndCrvChng_1pm2
#define	S_DPRTTG_RiCridrBndCrvChng_1pm2 (DPRTTG_SenOutPtr->S_DPRTTG_RiCridrBndCrvChng_1pm2) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiCridrBndCrvChng_1pm2(val)	(S_DPRTTG_RiCridrBndCrvChng_1pm2 = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiCridrBndCrv_1pm
#define	S_DPRTTG_RiCridrBndCrv_1pm (DPRTTG_SenOutPtr->S_DPRTTG_RiCridrBndCrv_1pm) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiCridrBndCrv_1pm(val)	(S_DPRTTG_RiCridrBndCrv_1pm = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiCridrBndHeadAng_rad
#define	S_DPRTTG_RiCridrBndHeadAng_rad (DPRTTG_SenOutPtr->S_DPRTTG_RiCridrBndHeadAng_rad) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiCridrBndHeadAng_rad(val)	(S_DPRTTG_RiCridrBndHeadAng_rad = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiCridrBndLength_met
#define	S_DPRTTG_RiCridrBndLength_met (DPRTTG_SenOutPtr->S_DPRTTG_RiCridrBndLength_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiCridrBndLength_met(val)	(S_DPRTTG_RiCridrBndLength_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiCridrBndPosX0_met
#define	S_DPRTTG_RiCridrBndPosX0_met (DPRTTG_SenOutPtr->S_DPRTTG_RiCridrBndPosX0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiCridrBndPosX0_met(val)	(S_DPRTTG_RiCridrBndPosX0_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_RiCridrBndPosY0_met
#define	S_DPRTTG_RiCridrBndPosY0_met (DPRTTG_SenOutPtr->S_DPRTTG_RiCridrBndPosY0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_RiCridrBndPosY0_met(val)	(S_DPRTTG_RiCridrBndPosY0_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_TgtTrajCrvChng_1pm2
#define	S_DPRTTG_TgtTrajCrvChng_1pm2 (DPRTTG_SenOutPtr->S_DPRTTG_TgtTrajCrvChng_1pm2) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_TgtTrajCrvChng_1pm2(val)	(S_DPRTTG_TgtTrajCrvChng_1pm2 = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_TgtTrajCrv_1pm
#define	S_DPRTTG_TgtTrajCrv_1pm (DPRTTG_SenOutPtr->S_DPRTTG_TgtTrajCrv_1pm) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_TgtTrajCrv_1pm(val)	(S_DPRTTG_TgtTrajCrv_1pm = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_TgtTrajHeadAng_rad
#define	S_DPRTTG_TgtTrajHeadAng_rad (DPRTTG_SenOutPtr->S_DPRTTG_TgtTrajHeadAng_rad) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_TgtTrajHeadAng_rad(val)	(S_DPRTTG_TgtTrajHeadAng_rad = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_TgtTrajLength_met
#define	S_DPRTTG_TgtTrajLength_met (DPRTTG_SenOutPtr->S_DPRTTG_TgtTrajLength_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_TgtTrajLength_met(val)	(S_DPRTTG_TgtTrajLength_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_TgtTrajPosX0_met
#define	S_DPRTTG_TgtTrajPosX0_met (DPRTTG_SenOutPtr->S_DPRTTG_TgtTrajPosX0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_TgtTrajPosX0_met(val)	(S_DPRTTG_TgtTrajPosX0_met = (val)) //!< DPRTTG debug macro setter.

#undef	S_DPRTTG_TgtTrajPosY0_met
#define	S_DPRTTG_TgtTrajPosY0_met (DPRTTG_SenOutPtr->S_DPRTTG_TgtTrajPosY0_met) //!< DPRTTG debug macro.
#define	SET_S_DPRTTG_TgtTrajPosY0_met(val)	(S_DPRTTG_TgtTrajPosY0_met = (val)) //!< DPRTTG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DPRTTG_PRIVATE_H_
