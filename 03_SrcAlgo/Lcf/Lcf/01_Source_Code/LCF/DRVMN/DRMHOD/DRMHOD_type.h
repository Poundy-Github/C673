/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMHOD
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMHOD_type.h
//! @brief     (DRMHOD) Module Type Header.

#ifndef DRMHOD_TYPE_H_
#define DRMHOD_TYPE_H_

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

/*! DRMHOD module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_Nm_m100_100_1em3_t D_DRMHOD_EstHandTor_Nm; /*!< @description
	*	Estimated torque produced by driver hand. \n\n
	*	\@asap_name: D_DRMHOD_EstHandTor_Nm \n
	*	\@type: value \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t S_DRMHOD_HandsOffConfirmed_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DRMHOD_HandsOffConfirmed_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	u8_NoUnit_0_1_0_1_t reserved[3];
	
} DRMHOD_VehDbgType; /*!< @description DRMHOD module vehicle debug data structure for MTS measurement. */

/*! DRMHOD module vehicle output data structure. */
typedef struct
{
	
	f32_Nm_m100_100_1em3_t D_DRMHOD_CorrectedTorque_Nm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_DRMHOD_CorrectedTorque_Nm \n
	*	\@type: value \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t D_DRMHOD_LowPassC; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_DRMHOD_LowPassC \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u16_NoUnit_0_65535_0_1_t D_DRMHOD_EstHandTorCounter_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_DRMHOD_EstHandTorCounter_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	E_DRMHOD_IntStateType_t D_DRMHOD_EstHandTorState_nu; /*!< @description
	*	Internal state of hands off detection module \n\n
	*	\@asap_name: D_DRMHOD_EstHandTorState_nu \n
	*	\@values: E_DRMHOD_IntStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_255_0_1_t D_DRMHOD_HdOffDtctStatus_nu; /*!< @description
	*	Debug signal \n\n
	*	\@asap_name: D_DRMHOD_HdOffDtctStatus_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DRMHOD_VehOutType; /*!< @description DRMHOD module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DRMHOD_TYPE_H_
