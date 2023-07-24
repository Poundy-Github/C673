/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRTTG_private.h
//! @brief     (LCRTTG) Module Private Header.

#ifndef LCRTTG_PRIVATE_H_
#define LCRTTG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ALCASA	//!< ALCASA sub-component input macro switch.
#define LCRTTG	//!< LCRTTG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCRTTG.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_LCRTTG_SenReset		0xF0 //!< LCRTTG module reset runnable identifier.
#define RUNNABLE_ID_LCRTTG_SenProcess	0xF1 //!< LCRTTG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static LCRTTG_SenDbgType *LCRTTG_SenDbgPtr = NULL; //!< LCRTTG module sensor debug data pointer.
void LCRTTG_SenInitDbgPtr(LCRTTG_SenDbgType *LCRTTG_SenDbgArg) { LCRTTG_SenDbgPtr = LCRTTG_SenDbgPtr == NULL ? LCRTTG_SenDbgArg : LCRTTG_SenDbgPtr; }
const LCRTTG_SenDbgType* LCRTTG_SenGetDbgPtr(void) { return (const LCRTTG_SenDbgType*) LCRTTG_SenDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_LCRTTG_LeCridrBndCrvChng_1pm2
#define	S_LCRTTG_LeCridrBndCrvChng_1pm2 (LCRTTG_SenDbgPtr->S_LCRTTG_LeCridrBndCrvChng_1pm2) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeCridrBndCrvChng_1pm2(val)	(S_LCRTTG_LeCridrBndCrvChng_1pm2 = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_LeCridrBndCrv_1pm
#define	S_LCRTTG_LeCridrBndCrv_1pm (LCRTTG_SenDbgPtr->S_LCRTTG_LeCridrBndCrv_1pm) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeCridrBndCrv_1pm(val)	(S_LCRTTG_LeCridrBndCrv_1pm = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_LeCridrBndHeadAng_rad
#define	S_LCRTTG_LeCridrBndHeadAng_rad (LCRTTG_SenDbgPtr->S_LCRTTG_LeCridrBndHeadAng_rad) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeCridrBndHeadAng_rad(val)	(S_LCRTTG_LeCridrBndHeadAng_rad = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_LeCridrBndLength_met
#define	S_LCRTTG_LeCridrBndLength_met (LCRTTG_SenDbgPtr->S_LCRTTG_LeCridrBndLength_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeCridrBndLength_met(val)	(S_LCRTTG_LeCridrBndLength_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_LeCridrBndPosX0_met
#define	S_LCRTTG_LeCridrBndPosX0_met (LCRTTG_SenDbgPtr->S_LCRTTG_LeCridrBndPosX0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeCridrBndPosX0_met(val)	(S_LCRTTG_LeCridrBndPosX0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_LeCridrBndPosY0_met
#define	S_LCRTTG_LeCridrBndPosY0_met (LCRTTG_SenDbgPtr->S_LCRTTG_LeCridrBndPosY0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeCridrBndPosY0_met(val)	(S_LCRTTG_LeCridrBndPosY0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_LeTgtTrajPosY0_met
#define	S_LCRTTG_LeTgtTrajPosY0_met (LCRTTG_SenDbgPtr->S_LCRTTG_LeTgtTrajPosY0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_LeTgtTrajPosY0_met(val)	(S_LCRTTG_LeTgtTrajPosY0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiCridrBndCrvChng_1pm2
#define	S_LCRTTG_RiCridrBndCrvChng_1pm2 (LCRTTG_SenDbgPtr->S_LCRTTG_RiCridrBndCrvChng_1pm2) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiCridrBndCrvChng_1pm2(val)	(S_LCRTTG_RiCridrBndCrvChng_1pm2 = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiCridrBndCrv_1pm
#define	S_LCRTTG_RiCridrBndCrv_1pm (LCRTTG_SenDbgPtr->S_LCRTTG_RiCridrBndCrv_1pm) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiCridrBndCrv_1pm(val)	(S_LCRTTG_RiCridrBndCrv_1pm = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiCridrBndHeadAng_rad
#define	S_LCRTTG_RiCridrBndHeadAng_rad (LCRTTG_SenDbgPtr->S_LCRTTG_RiCridrBndHeadAng_rad) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiCridrBndHeadAng_rad(val)	(S_LCRTTG_RiCridrBndHeadAng_rad = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiCridrBndLength_met
#define	S_LCRTTG_RiCridrBndLength_met (LCRTTG_SenDbgPtr->S_LCRTTG_RiCridrBndLength_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiCridrBndLength_met(val)	(S_LCRTTG_RiCridrBndLength_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiCridrBndPosX0_met
#define	S_LCRTTG_RiCridrBndPosX0_met (LCRTTG_SenDbgPtr->S_LCRTTG_RiCridrBndPosX0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiCridrBndPosX0_met(val)	(S_LCRTTG_RiCridrBndPosX0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiCridrBndPosY0_met
#define	S_LCRTTG_RiCridrBndPosY0_met (LCRTTG_SenDbgPtr->S_LCRTTG_RiCridrBndPosY0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiCridrBndPosY0_met(val)	(S_LCRTTG_RiCridrBndPosY0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_RiTgtTrajPosY0_met
#define	S_LCRTTG_RiTgtTrajPosY0_met (LCRTTG_SenDbgPtr->S_LCRTTG_RiTgtTrajPosY0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_RiTgtTrajPosY0_met(val)	(S_LCRTTG_RiTgtTrajPosY0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_TgtTrajCrvChng_1pm2
#define	S_LCRTTG_TgtTrajCrvChng_1pm2 (LCRTTG_SenDbgPtr->S_LCRTTG_TgtTrajCrvChng_1pm2) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_TgtTrajCrvChng_1pm2(val)	(S_LCRTTG_TgtTrajCrvChng_1pm2 = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_TgtTrajCrv_1pm
#define	S_LCRTTG_TgtTrajCrv_1pm (LCRTTG_SenDbgPtr->S_LCRTTG_TgtTrajCrv_1pm) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_TgtTrajCrv_1pm(val)	(S_LCRTTG_TgtTrajCrv_1pm = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_TgtTrajHeadAng_rad
#define	S_LCRTTG_TgtTrajHeadAng_rad (LCRTTG_SenDbgPtr->S_LCRTTG_TgtTrajHeadAng_rad) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_TgtTrajHeadAng_rad(val)	(S_LCRTTG_TgtTrajHeadAng_rad = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_TgtTrajLength_met
#define	S_LCRTTG_TgtTrajLength_met (LCRTTG_SenDbgPtr->S_LCRTTG_TgtTrajLength_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_TgtTrajLength_met(val)	(S_LCRTTG_TgtTrajLength_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_TgtTrajPosX0_met
#define	S_LCRTTG_TgtTrajPosX0_met (LCRTTG_SenDbgPtr->S_LCRTTG_TgtTrajPosX0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_TgtTrajPosX0_met(val)	(S_LCRTTG_TgtTrajPosX0_met = (val)) //!< LCRTTG debug macro setter.

#undef	S_LCRTTG_TgtTrajPosY0_met
#define	S_LCRTTG_TgtTrajPosY0_met (LCRTTG_SenDbgPtr->S_LCRTTG_TgtTrajPosY0_met) //!< LCRTTG debug macro.
#define	SET_S_LCRTTG_TgtTrajPosY0_met(val)	(S_LCRTTG_TgtTrajPosY0_met = (val)) //!< LCRTTG debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // LCRTTG_PRIVATE_H_
