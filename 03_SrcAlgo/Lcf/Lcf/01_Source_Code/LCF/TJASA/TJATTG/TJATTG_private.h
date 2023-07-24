/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJATTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJATTG_private.h
//! @brief     (TJATTG) Module Private Header.

#ifndef TJATTG_PRIVATE_H_
#define TJATTG_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJATTG	//!< TJATTG module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJATTG.h"
#include "Bitop.h" //MFC5J3
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TJATTG_SenReset		0xF0 //!< TJATTG module reset runnable identifier.
#define RUNNABLE_ID_TJATTG_SenProcess	0xF1 //!< TJATTG module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJATTG_SenDbgType *TJATTG_SenDbgPtr = NULL; //!< TJATTG module sensor debug data pointer.
void TJATTG_SenInitDbgPtr(TJATTG_SenDbgType *TJATTG_SenDbgArg) { TJATTG_SenDbgPtr = TJATTG_SenDbgPtr == NULL ? TJATTG_SenDbgArg : TJATTG_SenDbgPtr; }
const TJATTG_SenDbgType* TJATTG_SenGetDbgPtr(void) { return (const TJATTG_SenDbgType*) TJATTG_SenDbgPtr; }

static TJATTG_SenOutType *TJATTG_SenOutPtr = NULL; //!< TJATTG module sensor output data pointer.
void TJATTG_SenInitOutPtr(TJATTG_SenOutType *TJATTG_SenOutArg) { TJATTG_SenOutPtr = TJATTG_SenOutPtr == NULL ? TJATTG_SenOutArg : TJATTG_SenOutPtr; }
const TJATTG_SenOutType* TJATTG_SenGetOutPtr(void) { return (const TJATTG_SenOutType*) TJATTG_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJATTG_TgtCorridorInvalid_btf
#define	D_TJATTG_TgtCorridorInvalid_btf (TJATTG_SenDbgPtr->D_TJATTG_TgtCorridorInvalid_btf) //!< TJATTG debug macro.
#define	SET_D_TJATTG_TgtCorridorInvalid_btf(val)	(D_TJATTG_TgtCorridorInvalid_btf = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TgtTrajCrvChng_1pm2
#define	S_TJATTG_TgtTrajCrvChng_1pm2 (TJATTG_SenDbgPtr->S_TJATTG_TgtTrajCrvChng_1pm2) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TgtTrajCrvChng_1pm2(val)	(S_TJATTG_TgtTrajCrvChng_1pm2 = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TgtTrajCrv_1pm
#define	S_TJATTG_TgtTrajCrv_1pm (TJATTG_SenDbgPtr->S_TJATTG_TgtTrajCrv_1pm) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TgtTrajCrv_1pm(val)	(S_TJATTG_TgtTrajCrv_1pm = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TgtTrajHeadAng_rad
#define	S_TJATTG_TgtTrajHeadAng_rad (TJATTG_SenDbgPtr->S_TJATTG_TgtTrajHeadAng_rad) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TgtTrajHeadAng_rad(val)	(S_TJATTG_TgtTrajHeadAng_rad = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TgtTrajLength_met
#define	S_TJATTG_TgtTrajLength_met (TJATTG_SenDbgPtr->S_TJATTG_TgtTrajLength_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TgtTrajLength_met(val)	(S_TJATTG_TgtTrajLength_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TgtTrajPosX0_met
#define	S_TJATTG_TgtTrajPosX0_met (TJATTG_SenDbgPtr->S_TJATTG_TgtTrajPosX0_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TgtTrajPosX0_met(val)	(S_TJATTG_TgtTrajPosX0_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TgtTrajPosY0_met
#define	S_TJATTG_TgtTrajPosY0_met (TJATTG_SenDbgPtr->S_TJATTG_TgtTrajPosY0_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TgtTrajPosY0_met(val)	(S_TJATTG_TgtTrajPosY0_met = (val)) //!< TJATTG debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TJATTG_LeCridrBndCrvChng_1pm2
#define	S_TJATTG_LeCridrBndCrvChng_1pm2 (TJATTG_SenOutPtr->S_TJATTG_LeCridrBndCrvChng_1pm2) //!< TJATTG debug macro.
#define	SET_S_TJATTG_LeCridrBndCrvChng_1pm2(val)	(S_TJATTG_LeCridrBndCrvChng_1pm2 = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_LeCridrBndCrv_1pm
#define	S_TJATTG_LeCridrBndCrv_1pm (TJATTG_SenOutPtr->S_TJATTG_LeCridrBndCrv_1pm) //!< TJATTG debug macro.
#define	SET_S_TJATTG_LeCridrBndCrv_1pm(val)	(S_TJATTG_LeCridrBndCrv_1pm = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_LeCridrBndHeadAng_rad
#define	S_TJATTG_LeCridrBndHeadAng_rad (TJATTG_SenOutPtr->S_TJATTG_LeCridrBndHeadAng_rad) //!< TJATTG debug macro.
#define	SET_S_TJATTG_LeCridrBndHeadAng_rad(val)	(S_TJATTG_LeCridrBndHeadAng_rad = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_LeCridrBndLength_met
#define	S_TJATTG_LeCridrBndLength_met (TJATTG_SenOutPtr->S_TJATTG_LeCridrBndLength_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_LeCridrBndLength_met(val)	(S_TJATTG_LeCridrBndLength_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_LeCridrBndPosX0_met
#define	S_TJATTG_LeCridrBndPosX0_met (TJATTG_SenOutPtr->S_TJATTG_LeCridrBndPosX0_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_LeCridrBndPosX0_met(val)	(S_TJATTG_LeCridrBndPosX0_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_LeCridrBndPosY0_met
#define	S_TJATTG_LeCridrBndPosY0_met (TJATTG_SenOutPtr->S_TJATTG_LeCridrBndPosY0_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_LeCridrBndPosY0_met(val)	(S_TJATTG_LeCridrBndPosY0_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_PredictionEnable_bool
#define	S_TJATTG_PredictionEnable_bool (TJATTG_SenOutPtr->S_TJATTG_PredictionEnable_bool) //!< TJATTG debug macro.
#define	SET_S_TJATTG_PredictionEnable_bool(val)	(S_TJATTG_PredictionEnable_bool = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_RiCridrBndCrvChng_1pm2
#define	S_TJATTG_RiCridrBndCrvChng_1pm2 (TJATTG_SenOutPtr->S_TJATTG_RiCridrBndCrvChng_1pm2) //!< TJATTG debug macro.
#define	SET_S_TJATTG_RiCridrBndCrvChng_1pm2(val)	(S_TJATTG_RiCridrBndCrvChng_1pm2 = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_RiCridrBndCrv_1pm
#define	S_TJATTG_RiCridrBndCrv_1pm (TJATTG_SenOutPtr->S_TJATTG_RiCridrBndCrv_1pm) //!< TJATTG debug macro.
#define	SET_S_TJATTG_RiCridrBndCrv_1pm(val)	(S_TJATTG_RiCridrBndCrv_1pm = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_RiCridrBndHeadAng_rad
#define	S_TJATTG_RiCridrBndHeadAng_rad (TJATTG_SenOutPtr->S_TJATTG_RiCridrBndHeadAng_rad) //!< TJATTG debug macro.
#define	SET_S_TJATTG_RiCridrBndHeadAng_rad(val)	(S_TJATTG_RiCridrBndHeadAng_rad = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_RiCridrBndLength_met
#define	S_TJATTG_RiCridrBndLength_met (TJATTG_SenOutPtr->S_TJATTG_RiCridrBndLength_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_RiCridrBndLength_met(val)	(S_TJATTG_RiCridrBndLength_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_RiCridrBndPosX0_met
#define	S_TJATTG_RiCridrBndPosX0_met (TJATTG_SenOutPtr->S_TJATTG_RiCridrBndPosX0_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_RiCridrBndPosX0_met(val)	(S_TJATTG_RiCridrBndPosX0_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_RiCridrBndPosY0_met
#define	S_TJATTG_RiCridrBndPosY0_met (TJATTG_SenOutPtr->S_TJATTG_RiCridrBndPosY0_met) //!< TJATTG debug macro.
#define	SET_S_TJATTG_RiCridrBndPosY0_met(val)	(S_TJATTG_RiCridrBndPosY0_met = (val)) //!< TJATTG debug macro setter.

#undef	S_TJATTG_TransTriggerReplan_bool
#define	S_TJATTG_TransTriggerReplan_bool (TJATTG_SenOutPtr->S_TJATTG_TransTriggerReplan_bool) //!< TJATTG debug macro.
#define	SET_S_TJATTG_TransTriggerReplan_bool(val)	(S_TJATTG_TransTriggerReplan_bool = (val)) //!< TJATTG debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TJATTG_PRIVATE_H_
