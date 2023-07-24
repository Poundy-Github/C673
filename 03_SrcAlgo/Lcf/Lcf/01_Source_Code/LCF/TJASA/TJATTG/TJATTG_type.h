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
//! @file     TJATTG_type.h
//! @brief     (TJATTG) Module Type Header.

#ifndef TJATTG_TYPE_H_
#define TJATTG_TYPE_H_

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

/*! TJATTG module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm2_m1_1_1em3_t S_TJATTG_TgtTrajCrvChng_1pm2; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_TgtTrajCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm_m1_1_1em3_t S_TJATTG_TgtTrajCrv_1pm; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_TgtTrajCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_m_0_150_1em3_t S_TJATTG_TgtTrajLength_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_TgtTrajLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATTG_TgtTrajPosX0_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_TgtTrajPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATTG_TgtTrajPosY0_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_TgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_rad_m10_10_1em3_t S_TJATTG_TgtTrajHeadAng_rad; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_TgtTrajHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	u16_NoUnit_0_65535_0_1_t D_TJATTG_TgtCorridorInvalid_btf; /*!< @description
	*	TJATTG Debug signal \n\n
	*	\@asap_name: D_TJATTG_TgtCorridorInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
} TJATTG_SenDbgType; /*!< @description TJATTG module sensor debug data structure for MTS measurement. */

/*! TJATTG module sensor output data structure. */
typedef struct
{
	
	f32_1pm2_m1_1_1em3_t S_TJATTG_LeCridrBndCrvChng_1pm2; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_LeCridrBndCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm2_m1_1_1em3_t S_TJATTG_RiCridrBndCrvChng_1pm2; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_RiCridrBndCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm_m1_1_1em3_t S_TJATTG_LeCridrBndCrv_1pm; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_LeCridrBndCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_1pm_m1_1_1em3_t S_TJATTG_RiCridrBndCrv_1pm; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_RiCridrBndCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_m_0_150_1em3_t S_TJATTG_LeCridrBndLength_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_LeCridrBndLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_TJATTG_RiCridrBndLength_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_RiCridrBndLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATTG_LeCridrBndPosX0_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_LeCridrBndPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATTG_LeCridrBndPosY0_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_LeCridrBndPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATTG_RiCridrBndPosX0_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_RiCridrBndPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t S_TJATTG_RiCridrBndPosY0_met; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_RiCridrBndPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_rad_m10_10_1em3_t S_TJATTG_LeCridrBndHeadAng_rad; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_LeCridrBndHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m10_10_1em3_t S_TJATTG_RiCridrBndHeadAng_rad; /*!< @description
	*	TJATTG_OUTPUT \n\n
	*	\@asap_name: S_TJATTG_RiCridrBndHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATTG_PredictionEnable_bool; /*!< @description
	*	Indicates TRUE if module outputs are predicted \n\n
	*	\@asap_name: S_TJATTG_PredictionEnable_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJATTG_TransTriggerReplan_bool; /*!< @description
	*	Flag to trigger TRJPLN replan during mode transition \n\n
	*	\@asap_name: S_TJATTG_TransTriggerReplan_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TJATTG_SenOutType; /*!< @description TJATTG module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TJATTG_TYPE_H_
