/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJALKA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJALKA_type.h
//! @brief     (TJALKA) Module Type Header.

#ifndef TJALKA_TYPE_H_
#define TJALKA_TYPE_H_

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

/*! TJALKA module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	u16_NoUnit_0_65535_0_1_t D_TJALKA_LaneCenterInvalid_btf; /*!< @description
	*	TJALKA_DEBUG Bitfield \n
	*	 \n
	*	0: SR: EgoLanesInvalid \n
	*	1: SR: VelLimitExceed \n
	*	2: SR: DistToLnBoundInvalid \n
	*	3: SR: LaneWidthInvalid \n
	*	4: SR: CurvaturRadiusInvalid \n
	*	5: SR: TurnIndicatorEngaged \n
	*	6: SR: ConstSiteDetected \n
	*	7: SR: LC_Disabled \n
	*	8: SR: CustomSRInvalid \n
	*	9: SR: ObjFollowOnlyMode \n
	*	10: WR: CustomWRInvalid \n
	*	11: WR: LaneNotInCaptRange \n
	*	12: WR: BlockingTimeOn \n
	*	13: C: CustomCancel \n
	*	14: C: CancelCondFulfilled \n
	*	15: Reserved \n\n
	*	\@asap_name: D_TJALKA_LaneCenterInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	E_HMORQG_BndValidType_t S_TJALKA_LnBndValid_nu; /*!< @description
	*	TJA lane valid qualifier \n
	*	 \n
	*	0: Both lanes invalid \n
	*	1: Left lane valid \n
	*	2: Right lane valid \n
	*	3: Both lanes valid \n\n
	*	\@asap_name: S_TJALKA_LnBndValid_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJALKA_Cancel_bool; /*!< @description
	*	TJALKA_OUTPUT \n
	*	 \n
	*	Indicates true if cancel condition for lane centering are fulfilled. \n\n
	*	\@asap_name: S_TJALKA_Cancel_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJALKA_LanePredictValid_bool; /*!< @description
	*	TJALKA_OUTPUT \n
	*	 \n
	*	Indicates TRUE if both-sided lane prediction shall be enabled \n\n
	*	\@asap_name: S_TJALKA_LanePredictValid_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJALKA_StrongReady_bool; /*!< @description
	*	TJALKA_OUTPUT \n
	*	 \n
	*	Indicates true if strong ready condition for lane centering are fulfilled. \n\n
	*	\@asap_name: S_TJALKA_StrongReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJALKA_WeakReady_bool; /*!< @description
	*	TJALKA_OUTPUT \n
	*	 \n
	*	Indicates true if weak ready condition for lane centering are fulfilled. \n\n
	*	\@asap_name: S_TJALKA_WeakReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TJALKA_SenDbgType; /*!< @description TJALKA module sensor debug data structure for MTS measurement. */

/*! TJALKA module sensor output data structure. */
typedef struct
{
	
	u16_NoUnit_0_65535_0_1_t D_TJALKA_LaneInvalid_btf; /*!< @description
	*	Lane Invalid Debug Bitfield \n\n
	*	\@asap_name: D_TJALKA_LaneInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJALKA_CombinedLaneSR_bool; /*!< @description
	*	Indicates TRUE if lane are considered SR valid for combined mode \n\n
	*	\@asap_name: S_TJALKA_CombinedLaneSR_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJALKA_CombinedLaneWR_bool; /*!< @description
	*	Indicates TRUE if lane are considered WR valid for combined mode \n\n
	*	\@asap_name: S_TJALKA_CombinedLaneWR_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TJALKA_SenOutType; /*!< @description TJALKA module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TJALKA_TYPE_H_
