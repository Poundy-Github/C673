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
  $Date: 2020/04/09 14:23:59CEST $
  $Log: TJAOBF_type.h  $
  Revision 1.7 2020/04/09 14:23:59CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.6 2019/11/29 09:05:11CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJAOBF_type.h
//! @brief     (TJAOBF) Module Type Header.

#ifndef TJAOBF_TYPE_H_
#define TJAOBF_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! TJAOBF module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	u16_NoUnit_0_65535_0_1_t D_TJAOBF_ObjFollowInvalid_btf; /*!< @description
	*	TJAOBF_DEBUG: ObjFollowInvalid_btf \n
	*	 \n
	*	0: LaneCheckDisabled \n
	*	1: AccObjectInvalid \n
	*	2: NoLeftLaneDetected \n
	*	3: LeLaneLengthInvalid \n
	*	4: NoRightLaneDetected \n
	*	5: RiLaneLengthInvalid \n
	*	6: ObjNotInEgoLane \n
	*	7: Dist2LeBndInvalid \n
	*	8: Dist2RiBndInvalid \n
	*	9-15: Reserved (0 by default) \n\n
	*	\@asap_name: D_TJAOBF_ObjFollowInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t D_TJAOBF_ObjInLaneInvalid_btf; /*!< @description
	*	TJAOBF_DEBUG: ObjectInLaneCheck__Bitfield \n
	*	 \n
	*	0: LaneCheckDisabled \n
	*	1: AccObjectInvalid \n
	*	2: NoLeftLaneDetected \n
	*	3: LeLaneLengthInvalid \n
	*	4: NoRightLaneDetected \n
	*	5: RiLaneLengthInvalid \n
	*	6: ObjNotInEgoLane \n
	*	7: Dist2LeBndInvalid \n
	*	8: Dist2RiBndInvalid \n
	*	9-15: Reserved (0 by default) \n\n
	*	\@asap_name: D_TJAOBF_ObjInLaneInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAOBF_Cancel_bool; /*!< @description
	*	TJAOBF_OUTPUT \n
	*	 \n
	*	Indicates true if cancel condition for object following are fulfilled. \n\n
	*	\@asap_name: S_TJAOBF_Cancel_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAOBF_ObjInLaneValid_bool; /*!< @description
	*	Indicates TRUE if target object validated to be driving within the ego lane \n\n
	*	\@asap_name: S_TJAOBF_ObjInLaneValid_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAOBF_StrongReady_bool; /*!< @description
	*	TJAOBF_OUTPUT \n
	*	 \n
	*	Indicates true if strong ready condition for object following are fulfilled. \n\n
	*	\@asap_name: S_TJAOBF_StrongReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAOBF_TgtObjDataValid_bool; /*!< @description
	*	Indicates TRUE if target object data is valid for controlling in OF or CMB mode \n\n
	*	\@asap_name: S_TJAOBF_TgtObjDataValid_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAOBF_WeakReady_bool; /*!< @description
	*	TJAOBF_OUTPUT \n
	*	 \n
	*	Indicates true if weak ready condition for object following are fulfilled. \n\n
	*	\@asap_name: S_TJAOBF_WeakReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_TJAOBF_TgtObjDataInvalid_btf; /*!< @description
	*	TJAOBF_DEBUG: TgtObjDataInvalid_btf \n\n
	*	\@asap_name: D_TJAOBF_TgtObjDataInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TJAOBF_SenDbgType; /*!< @description TJAOBF module sensor debug data structure for MTS measurement. */

/*! TJAOBF module sensor output data structure. */
typedef struct
{
	
	f32_1pm_m0p1_0p1_1em3_t S_TJAOBF_CombObjectCrv_1pm; /*!< @description
	*	Object curvature based on ACC object measurement position and lateral offset / heading angle of ABPR center lane \n\n
	*	\@asap_name: S_TJAOBF_CombObjectCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TJAOBF_ObjectCrv_1pm; /*!< @description
	*	Object curvature based on ACC object measurement position \n\n
	*	\@asap_name: S_TJAOBF_ObjectCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAOBF_AccObjValid_bool; /*!< @description
	*	Indicates TRUE, if ACC object is valid for object following mode. \n\n
	*	\@asap_name: S_TJAOBF_AccObjValid_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TJAOBF_SenOutType; /*!< @description TJAOBF module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif /* TJAOBF_TYPE_H_*/
