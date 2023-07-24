/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTFFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTFFC_type.h
//! @brief     (TCTFFC) Module Type Header.

#ifndef TCTFFC_TYPE_H_
#define TCTFFC_TYPE_H_

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

/*! TCTFFC module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTFFC_DiffMeasEstKappa_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_DiffMeasEstKappa_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTFFC_DynFfcDecel_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_DynFfcDecel_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTFFC_DynFfcGeneral_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_DynFfcGeneral_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTFFC_DynFfcUpDwnHill_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_DynFfcUpDwnHill_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTFFC_DynFfc_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_DynFfc_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTFFC_TrajTgtCrvFilt_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_TrajTgtCrvFilt_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTFFC_Crv_1pm; /*!< @description
	*	Curvature control signal part of the feedforward controller \n\n
	*	\@asap_name: S_TCTFFC_Crv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTFFC_DynGainPrecFulfilled_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTFFC_DynGainPrecFulfilled_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TCTFFC_VehDbgType; /*!< @description TCTFFC module vehicle debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // TCTFFC_TYPE_H_
