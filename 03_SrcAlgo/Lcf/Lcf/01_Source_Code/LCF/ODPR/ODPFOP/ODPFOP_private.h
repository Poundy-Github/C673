/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.8 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:21:15CEST $
  $Log: ODPFOP_private.h  $
  Revision 1.8 2020/04/09 14:21:15CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.7 2019/11/29 09:02:18CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOP_private.h
//! @brief     (ODPFOP) Module Private Header.

#ifndef ODPFOP_PRIVATE_H_
#define ODPFOP_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ODPR	//!< ODPR sub-component input macro switch.
#define ODPFOP	//!< ODPFOP module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ODPFOP.h"
#include "bitop.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_ODPFOP_SenReset		0xF0 //!< ODPFOP module reset runnable identifier.
#define RUNNABLE_ID_ODPFOP_SenProcess	0xF1 //!< ODPFOP module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static ODPFOP_SenDbgType *ODPFOP_SenDbgPtr = NULL; //!< ODPFOP module sensor debug data pointer.
void ODPFOP_SenInitDbgPtr(ODPFOP_SenDbgType *ODPFOP_SenDbgArg) { ODPFOP_SenDbgPtr = ODPFOP_SenDbgPtr == NULL ? ODPFOP_SenDbgArg : ODPFOP_SenDbgPtr; }
const ODPFOP_SenDbgType* ODPFOP_SenGetDbgPtr(void) { return (const ODPFOP_SenDbgType*) ODPFOP_SenDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_ODPFOP_AccFRObjTStamp_sec
#define	S_ODPFOP_AccFRObjTStamp_sec (ODPFOP_SenDbgPtr->S_ODPFOP_AccFRObjTStamp_sec) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccFRObjTStamp_sec(val)	(S_ODPFOP_AccFRObjTStamp_sec = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjInvBitfield_btf
#define	S_ODPFOP_AccObjInvBitfield_btf (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjInvBitfield_btf) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjInvBitfield_btf(val)	(S_ODPFOP_AccObjInvBitfield_btf = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjPosXStdDev_met
#define	S_ODPFOP_AccObjPosXStdDev_met (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjPosXStdDev_met) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjPosXStdDev_met(val)	(S_ODPFOP_AccObjPosXStdDev_met = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjPosX_met
#define	S_ODPFOP_AccObjPosX_met (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjPosX_met) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjPosX_met(val)	(S_ODPFOP_AccObjPosX_met = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjPosYStdDev_met
#define	S_ODPFOP_AccObjPosYStdDev_met (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjPosYStdDev_met) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjPosYStdDev_met(val)	(S_ODPFOP_AccObjPosYStdDev_met = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjPosY_met
#define	S_ODPFOP_AccObjPosY_met (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjPosY_met) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjPosY_met(val)	(S_ODPFOP_AccObjPosY_met = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjRelAclX_mps2
#define	S_ODPFOP_AccObjRelAclX_mps2 (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjRelAclX_mps2) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjRelAclX_mps2(val)	(S_ODPFOP_AccObjRelAclX_mps2 = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjRelAclY_mps2
#define	S_ODPFOP_AccObjRelAclY_mps2 (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjRelAclY_mps2) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjRelAclY_mps2(val)	(S_ODPFOP_AccObjRelAclY_mps2 = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjRelVelX_mps
#define	S_ODPFOP_AccObjRelVelX_mps (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjRelVelX_mps) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjRelVelX_mps(val)	(S_ODPFOP_AccObjRelVelX_mps = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjRelVelY_mps
#define	S_ODPFOP_AccObjRelVelY_mps (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjRelVelY_mps) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjRelVelY_mps(val)	(S_ODPFOP_AccObjRelVelY_mps = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_AccObjRelYawAng_rad
#define	S_ODPFOP_AccObjRelYawAng_rad (ODPFOP_SenDbgPtr->S_ODPFOP_AccObjRelYawAng_rad) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_AccObjRelYawAng_rad(val)	(S_ODPFOP_AccObjRelYawAng_rad = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_EstimatedObjPosX_met
#define	S_ODPFOP_EstimatedObjPosX_met (ODPFOP_SenDbgPtr->S_ODPFOP_EstimatedObjPosX_met) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_EstimatedObjPosX_met(val)	(S_ODPFOP_EstimatedObjPosX_met = (val)) //!< ODPFOP debug macro setter.

#undef	S_ODPFOP_EstimatedObjPosY_met
#define	S_ODPFOP_EstimatedObjPosY_met (ODPFOP_SenDbgPtr->S_ODPFOP_EstimatedObjPosY_met) //!< ODPFOP debug macro.
#define	SET_S_ODPFOP_EstimatedObjPosY_met(val)	(S_ODPFOP_EstimatedObjPosY_met = (val)) //!< ODPFOP debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* ODPFOP_PRIVATE_H_*/
