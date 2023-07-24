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
  $Revision: 1.7 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:23:58CEST $
  $Log: TJAOBF_data.h  $
  Revision 1.7 2020/04/09 14:23:58CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.6 2019/11/29 09:05:13CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJAOBF_data.h
//! @brief     (TJAOBF) Module Data Header.

#ifndef TJAOBF_DATA_H_
#define TJAOBF_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TJAOBF module sensor get function. Function gets TJAOBF sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJAOBF_SenDbgPtr</b> Global static pointer to TJAOBF sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJAOBF_SenDbgType* TJAOBF_SenGetDbgPtr(void);

/*!
 *	TJAOBF module sensor get function. Function gets TJAOBF sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJAOBF_SenOutPtr</b> Global static pointer to TJAOBF sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJAOBF_SenOutType* TJAOBF_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJAOBF_ObjFollowInvalid_btf
#define D_TJAOBF_ObjFollowInvalid_btf (TJAOBF_SenGetDbgPtr()->D_TJAOBF_ObjFollowInvalid_btf) //!< TJAOBF debug macro.
#define GET_D_TJAOBF_ObjFollowInvalid_btf() (D_TJAOBF_ObjFollowInvalid_btf) //!< TJAOBF debug macro getter.
#endif // D_TJAOBF_ObjFollowInvalid_btf

#ifndef D_TJAOBF_ObjInLaneInvalid_btf
#define D_TJAOBF_ObjInLaneInvalid_btf (TJAOBF_SenGetDbgPtr()->D_TJAOBF_ObjInLaneInvalid_btf) //!< TJAOBF debug macro.
#define GET_D_TJAOBF_ObjInLaneInvalid_btf() (D_TJAOBF_ObjInLaneInvalid_btf) //!< TJAOBF debug macro getter.
#endif // D_TJAOBF_ObjInLaneInvalid_btf

#ifndef D_TJAOBF_TgtObjDataInvalid_btf
#define D_TJAOBF_TgtObjDataInvalid_btf (TJAOBF_SenGetDbgPtr()->D_TJAOBF_TgtObjDataInvalid_btf) //!< TJAOBF debug macro.
#define GET_D_TJAOBF_TgtObjDataInvalid_btf() (D_TJAOBF_TgtObjDataInvalid_btf) //!< TJAOBF debug macro getter.
#endif // D_TJAOBF_TgtObjDataInvalid_btf

#ifndef S_TJAOBF_Cancel_bool
#define S_TJAOBF_Cancel_bool (TJAOBF_SenGetDbgPtr()->S_TJAOBF_Cancel_bool) //!< TJAOBF debug macro.
#define GET_S_TJAOBF_Cancel_bool() (S_TJAOBF_Cancel_bool) //!< TJAOBF debug macro getter.
#endif // S_TJAOBF_Cancel_bool

#ifndef S_TJAOBF_ObjInLaneValid_bool
#define S_TJAOBF_ObjInLaneValid_bool (TJAOBF_SenGetDbgPtr()->S_TJAOBF_ObjInLaneValid_bool) //!< TJAOBF debug macro.
#define GET_S_TJAOBF_ObjInLaneValid_bool() (S_TJAOBF_ObjInLaneValid_bool) //!< TJAOBF debug macro getter.
#endif // S_TJAOBF_ObjInLaneValid_bool

#ifndef S_TJAOBF_StrongReady_bool
#define S_TJAOBF_StrongReady_bool (TJAOBF_SenGetDbgPtr()->S_TJAOBF_StrongReady_bool) //!< TJAOBF debug macro.
#define GET_S_TJAOBF_StrongReady_bool() (S_TJAOBF_StrongReady_bool) //!< TJAOBF debug macro getter.
#endif // S_TJAOBF_StrongReady_bool

#ifndef S_TJAOBF_TgtObjDataValid_bool
#define S_TJAOBF_TgtObjDataValid_bool (TJAOBF_SenGetDbgPtr()->S_TJAOBF_TgtObjDataValid_bool) //!< TJAOBF debug macro.
#define GET_S_TJAOBF_TgtObjDataValid_bool() (S_TJAOBF_TgtObjDataValid_bool) //!< TJAOBF debug macro getter.
#endif // S_TJAOBF_TgtObjDataValid_bool

#ifndef S_TJAOBF_WeakReady_bool
#define S_TJAOBF_WeakReady_bool (TJAOBF_SenGetDbgPtr()->S_TJAOBF_WeakReady_bool) //!< TJAOBF debug macro.
#define GET_S_TJAOBF_WeakReady_bool() (S_TJAOBF_WeakReady_bool) //!< TJAOBF debug macro getter.
#endif // S_TJAOBF_WeakReady_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TJAOBF_AccObjValid_bool
#define S_TJAOBF_AccObjValid_bool (TJAOBF_SenGetOutPtr()->S_TJAOBF_AccObjValid_bool) //!< TJAOBF output macro.
#define GET_S_TJAOBF_AccObjValid_bool() (S_TJAOBF_AccObjValid_bool) //!< TJAOBF output macro getter.
#endif // S_TJAOBF_AccObjValid_bool

#ifndef S_TJAOBF_CombObjectCrv_1pm
#define S_TJAOBF_CombObjectCrv_1pm (TJAOBF_SenGetOutPtr()->S_TJAOBF_CombObjectCrv_1pm) //!< TJAOBF output macro.
#define GET_S_TJAOBF_CombObjectCrv_1pm() (S_TJAOBF_CombObjectCrv_1pm) //!< TJAOBF output macro getter.
#endif // S_TJAOBF_CombObjectCrv_1pm

#ifndef S_TJAOBF_ObjectCrv_1pm
#define S_TJAOBF_ObjectCrv_1pm (TJAOBF_SenGetOutPtr()->S_TJAOBF_ObjectCrv_1pm) //!< TJAOBF output macro.
#define GET_S_TJAOBF_ObjectCrv_1pm() (S_TJAOBF_ObjectCrv_1pm) //!< TJAOBF output macro getter.
#endif // S_TJAOBF_ObjectCrv_1pm

#ifdef __cplusplus
}
#endif

#endif /* TJAOBF_DATA_H_*/
