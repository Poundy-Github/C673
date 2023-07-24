/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAOBF
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.9 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:23:58CEST $
  $Log: TJAOBF_private.h  $
  Revision 1.9 2020/04/09 14:23:58CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.8 2019/11/29 09:05:12CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJAOBF_private.h
//! @brief     (TJAOBF) Module Private Header.

#ifndef TJAOBF_PRIVATE_H_
#define TJAOBF_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TJASA	//!< TJASA sub-component input macro switch.
#define TJAOBF	//!< TJAOBF module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJAOBF.h"
#include "Bitop.h"  //MFC5J3
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TJAOBF_SenReset		0xF0 //!< TJAOBF module reset runnable identifier.
#define RUNNABLE_ID_TJAOBF_SenProcess	0xF1 //!< TJAOBF module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TJAOBF_SenDbgType *TJAOBF_SenDbgPtr = NULL; //!< TJAOBF module sensor debug data pointer.
void TJAOBF_SenInitDbgPtr(TJAOBF_SenDbgType *TJAOBF_SenDbgArg) { TJAOBF_SenDbgPtr = TJAOBF_SenDbgPtr == NULL ? TJAOBF_SenDbgArg : TJAOBF_SenDbgPtr; }
const TJAOBF_SenDbgType* TJAOBF_SenGetDbgPtr(void) { return (const TJAOBF_SenDbgType*) TJAOBF_SenDbgPtr; }

static TJAOBF_SenOutType *TJAOBF_SenOutPtr = NULL; //!< TJAOBF module sensor output data pointer.
void TJAOBF_SenInitOutPtr(TJAOBF_SenOutType *TJAOBF_SenOutArg) { TJAOBF_SenOutPtr = TJAOBF_SenOutPtr == NULL ? TJAOBF_SenOutArg : TJAOBF_SenOutPtr; }
const TJAOBF_SenOutType* TJAOBF_SenGetOutPtr(void) { return (const TJAOBF_SenOutType*) TJAOBF_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TJAOBF_ObjFollowInvalid_btf
#define	D_TJAOBF_ObjFollowInvalid_btf (TJAOBF_SenDbgPtr->D_TJAOBF_ObjFollowInvalid_btf) //!< TJAOBF debug macro.
#define	SET_D_TJAOBF_ObjFollowInvalid_btf(val)	(D_TJAOBF_ObjFollowInvalid_btf = (val)) //!< TJAOBF debug macro setter.

#undef	D_TJAOBF_ObjInLaneInvalid_btf
#define	D_TJAOBF_ObjInLaneInvalid_btf (TJAOBF_SenDbgPtr->D_TJAOBF_ObjInLaneInvalid_btf) //!< TJAOBF debug macro.
#define	SET_D_TJAOBF_ObjInLaneInvalid_btf(val)	(D_TJAOBF_ObjInLaneInvalid_btf = (val)) //!< TJAOBF debug macro setter.

#undef	D_TJAOBF_TgtObjDataInvalid_btf
#define	D_TJAOBF_TgtObjDataInvalid_btf (TJAOBF_SenDbgPtr->D_TJAOBF_TgtObjDataInvalid_btf) //!< TJAOBF debug macro.
#define	SET_D_TJAOBF_TgtObjDataInvalid_btf(val)	(D_TJAOBF_TgtObjDataInvalid_btf = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_Cancel_bool
#define	S_TJAOBF_Cancel_bool (TJAOBF_SenDbgPtr->S_TJAOBF_Cancel_bool) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_Cancel_bool(val)	(S_TJAOBF_Cancel_bool = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_ObjInLaneValid_bool
#define	S_TJAOBF_ObjInLaneValid_bool (TJAOBF_SenDbgPtr->S_TJAOBF_ObjInLaneValid_bool) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_ObjInLaneValid_bool(val)	(S_TJAOBF_ObjInLaneValid_bool = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_StrongReady_bool
#define	S_TJAOBF_StrongReady_bool (TJAOBF_SenDbgPtr->S_TJAOBF_StrongReady_bool) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_StrongReady_bool(val)	(S_TJAOBF_StrongReady_bool = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_TgtObjDataValid_bool
#define	S_TJAOBF_TgtObjDataValid_bool (TJAOBF_SenDbgPtr->S_TJAOBF_TgtObjDataValid_bool) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_TgtObjDataValid_bool(val)	(S_TJAOBF_TgtObjDataValid_bool = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_WeakReady_bool
#define	S_TJAOBF_WeakReady_bool (TJAOBF_SenDbgPtr->S_TJAOBF_WeakReady_bool) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_WeakReady_bool(val)	(S_TJAOBF_WeakReady_bool = (val)) //!< TJAOBF debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TJAOBF_AccObjValid_bool
#define	S_TJAOBF_AccObjValid_bool (TJAOBF_SenOutPtr->S_TJAOBF_AccObjValid_bool) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_AccObjValid_bool(val)	(S_TJAOBF_AccObjValid_bool = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_CombObjectCrv_1pm
#define	S_TJAOBF_CombObjectCrv_1pm (TJAOBF_SenOutPtr->S_TJAOBF_CombObjectCrv_1pm) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_CombObjectCrv_1pm(val)	(S_TJAOBF_CombObjectCrv_1pm = (val)) //!< TJAOBF debug macro setter.

#undef	S_TJAOBF_ObjectCrv_1pm
#define	S_TJAOBF_ObjectCrv_1pm (TJAOBF_SenOutPtr->S_TJAOBF_ObjectCrv_1pm) //!< TJAOBF debug macro.
#define	SET_S_TJAOBF_ObjectCrv_1pm(val)	(S_TJAOBF_ObjectCrv_1pm = (val)) //!< TJAOBF debug macro setter.

#ifdef __cplusplus
}
#endif

#endif /* TJAOBF_PRIVATE_H_*/
