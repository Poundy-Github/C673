/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRTTG_type.h
//! @brief     (DPRTTG) Module Type Header.

#ifndef DPRTTG_TYPE_H_
#define DPRTTG_TYPE_H_

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

/*! DPRTTG module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m15_15_1em3_t S_DPRTTG_LeTgtTrajPosY0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeTgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRTTG_RiTgtTrajPosY0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiTgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
} DPRTTG_SenDbgType; /*!< @description DPRTTG module sensor debug data structure for MTS measurement. */

/*! DPRTTG module sensor output data structure. */
typedef struct
{
	
	f32_1pm2_m1_1_1em3_t S_DPRTTG_LeCridrBndCrvChng_1pm2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeCridrBndCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm2_m1_1_1em3_t S_DPRTTG_RiCridrBndCrvChng_1pm2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiCridrBndCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm2_m1_1_1em3_t S_DPRTTG_TgtTrajCrvChng_1pm2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_TgtTrajCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm_m1_1_1em3_t S_DPRTTG_LeCridrBndCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeCridrBndCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm_m1_1_1em3_t S_DPRTTG_RiCridrBndCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiCridrBndCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm_m1_1_1em3_t S_DPRTTG_TgtTrajCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_TgtTrajCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_LeCridrBndLength_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeCridrBndLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_LeCridrBndPosX0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeCridrBndPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_LeCridrBndPosY0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeCridrBndPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_RiCridrBndLength_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiCridrBndLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_RiCridrBndPosX0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiCridrBndPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_RiCridrBndPosY0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiCridrBndPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_TgtTrajLength_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_TgtTrajLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_TgtTrajPosX0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_TgtTrajPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_DPRTTG_TgtTrajPosY0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_TgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_rad_m10_10_1em3_t S_DPRTTG_LeCridrBndHeadAng_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_LeCridrBndHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m10_10_1em3_t S_DPRTTG_RiCridrBndHeadAng_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_RiCridrBndHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m10_10_1em3_t S_DPRTTG_TgtTrajHeadAng_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DPRTTG_TgtTrajHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
} DPRTTG_SenOutType; /*!< @description DPRTTG module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DPRTTG_TYPE_H_
