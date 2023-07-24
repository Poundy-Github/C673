/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAGEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJAGEN_type.h
//! @brief     (TJAGEN) Module Type Header.

#ifndef TJAGEN_TYPE_H_
#define TJAGEN_TYPE_H_

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

/*! TJAGEN module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_Abort_bool; /*!< @description
	*	Indicates TRUE, if TJA shall be aborted (no rampout) \n\n
	*	\@asap_name: S_TJAGEN_Abort_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_LKAOnlySwitch_bool; /*!< @description
	*	Switch to enable LKA only \n\n
	*	\@asap_name: S_TJAGEN_LKAOnlySwitch_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_StrongReady_bool; /*!< @description
	*	Indicates TRUE, if TJA strong ready conditions are fulfilled \n\n
	*	\@asap_name: S_TJAGEN_StrongReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_WeakReady_bool; /*!< @description
	*	Indicates TRUE, if TJA weak ready conditions are fulfilled \n\n
	*	\@asap_name: S_TJAGEN_WeakReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_TJAGEN_CancelStatus_btf; /*!< @description
	*	DEBUG: bit field signal for cancel conditions \n\n
	*	\@asap_name: D_TJAGEN_CancelStatus_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_TJAGEN_StrongReadyInvalid_btf; /*!< @description
	*	DEBUG: bit field signal for strong ready conditions \n\n
	*	\@asap_name: D_TJAGEN_StrongReadyInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_TJAGEN_WeakReadyInvalid_btf; /*!< @description
	*	DEBUG: bit field signal for weak ready conditions \n\n
	*	\@asap_name: D_TJAGEN_WeakReadyInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TJAGEN_SenDbgType; /*!< @description TJAGEN module sensor debug data structure for MTS measurement. */

/*! TJAGEN module sensor output data structure. */
typedef struct
{
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_Cancel_nu; /*!< @description
	*	Indicates TRUE, if TJA cancel conditions are fulfilled \n\n
	*	\@asap_name: S_TJAGEN_Cancel_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_Clearance_bool; /*!< @description
	*	Indicates TRUE, if TJA received clearance from mode control \n\n
	*	\@asap_name: S_TJAGEN_Clearance_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_CodeFunction_bool; /*!< @description
	*	Indicates TRUE, if TJA is coded. \n\n
	*	\@asap_name: S_TJAGEN_CodeFunction_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_Degradation_bool; /*!< @description
	*	Indicates TRUE, if rampout is completed \n\n
	*	\@asap_name: S_TJAGEN_Degradation_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_Error_bool; /*!< @description
	*	Indicates TRUE, if TJA error conditions are fulfilled \n\n
	*	\@asap_name: S_TJAGEN_Error_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJAGEN_FunctionSwitch_bool; /*!< @description
	*	Indicates TRUE, if TJA is switched on \n\n
	*	\@asap_name: S_TJAGEN_FunctionSwitch_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TJAGEN_SenOutType; /*!< @description TJAGEN module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TJAGEN_TYPE_H_
