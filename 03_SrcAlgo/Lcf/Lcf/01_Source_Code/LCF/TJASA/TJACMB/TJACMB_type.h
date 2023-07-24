/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJACMB
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.5 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:23:13CEST $
  $Log: TJACMB_type.h  $
  Revision 1.5 2020/04/09 14:23:13CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4 2019/11/29 09:05:05CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJACMB_type.h
//! @brief     (TJACMB) Module Type Header.

#ifndef TJACMB_TYPE_H_
#define TJACMB_TYPE_H_

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

/*! TJACMB module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm2_m0p001_0p001_1em3_t S_TJACMB_CombinedCrvChng_1pm2; /*!< @description
	*	Combined Curvature Change \n\n
	*	\@asap_name: S_TJACMB_CombinedCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TJACMB_CombinedCrv_1pm; /*!< @description
	*	Combined Curvature \n\n
	*	\@asap_name: S_TJACMB_CombinedCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_300_1em3_t S_TJACMB_CombinedLength_met; /*!< @description
	*	Combined Trajectory Length \n\n
	*	\@asap_name: S_TJACMB_CombinedLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_m15_15_1em3_t S_TJACMB_CombinedPosY0_met; /*!< @description
	*	Combined PosY0 \n\n
	*	\@asap_name: S_TJACMB_CombinedPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_TJACMB_CombinedHeading_rad; /*!< @description
	*	Combined Heading Angle \n\n
	*	\@asap_name: S_TJACMB_CombinedHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	u16_NoUnit_0_65535_0_1_t D_TJACMB_CombinedInvalid_btf; /*!< @description
	*	TJACMB Debug Signal \n\n
	*	\@asap_name: D_TJACMB_CombinedInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJACMB_Cancel_bool; /*!< @description
	*	Indicates TRUE if at least one cancel condition for combined mode is fulfilled. \n\n
	*	\@asap_name: S_TJACMB_Cancel_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJACMB_StrongReady_bool; /*!< @description
	*	Indicates TRUE if all strong ready conditions for combined mode are fulfilled. \n\n
	*	\@asap_name: S_TJACMB_StrongReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TJACMB_WeakReady_bool; /*!< @description
	*	Indicates TRUE if all weak ready conditions for combined mode are fulfilled. \n\n
	*	\@asap_name: S_TJACMB_WeakReady_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TJACMB_SenDbgType; /*!< @description TJACMB module sensor debug data structure for MTS measurement. */

/*! TJACMB module sensor output data structure. */
typedef struct
{
	
	f32_m_m15_15_1em3_t S_TJACMB_CombinedLePosY0_met; /*!< @description
	*	Combined Left PosY0 \n\n
	*	\@asap_name: S_TJACMB_CombinedLePosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_TJACMB_CombinedRiPosY0_met; /*!< @description
	*	Combined Right PosY0 \n\n
	*	\@asap_name: S_TJACMB_CombinedRiPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m30_30_1em3_t S_TJACMB_CombinedPosX0_met; /*!< @description
	*	Combined PosX0 \n\n
	*	\@asap_name: S_TJACMB_CombinedPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	u16_NoUnit_0_65535_0_1_t D_TJACMB_TransitionInvalid_btf; /*!< @description
	*	TJACMB Debug: Internal transition \n\n
	*	\@asap_name: D_TJACMB_TransitionInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	E_TJACMB_CombModeType_t S_TJACMB_CombinedMode_nu; /*!< @description
	*	Combined mode state \n\n
	*	\@asap_name: S_TJACMB_CombinedMode_nu \n
	*	\@values: E_TJACMB_CombModeType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
} TJACMB_SenOutType; /*!< @description TJACMB module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif /* TJACMB_TYPE_H_*/
