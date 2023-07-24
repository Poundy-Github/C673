/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOH
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:20:45CEST $
  $Log: ODPFOH_type.h  $
  Revision 1.4.1.2 2020/04/09 14:20:45CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:02:26CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOH_type.h
//! @brief     (ODPFOH) Module Type Header.

#ifndef ODPFOH_TYPE_H_
#define ODPFOH_TYPE_H_

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

/*! ODPFOH module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p1_0p1_1em3_t S_ODPFOH_AccObjTraceCrv_1pm; /*!< @description
	*	ACC trace curvature \n\n
	*	\@asap_name: S_ODPFOH_AccObjTraceCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ODPFOH_TgtObjCrv_1pm; /*!< @description
	*	Target object curvature \n\n
	*	\@asap_name: S_ODPFOH_TgtObjCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_300_1em3_t S_ODPFOH_TgtObjLength_met; /*!< @description
	*	Target object trajectory length \n\n
	*	\@asap_name: S_ODPFOH_TgtObjLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ODPFOH_TgtObjPosX0_met; /*!< @description
	*	Target object position X0 \n\n
	*	\@asap_name: S_ODPFOH_TgtObjPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_m100_100_1em3_t D_ODPFOH_LastStoredPntX_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_LastStoredPntX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t D_ODPFOH_MaxGapEgoToHist_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_MaxGapEgoToHist_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t D_ODPFOH_MinHistLength_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_MinHistLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t D_ODPFOH_MinHistStartPosX_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_MinHistStartPosX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m30_30_1em3_t D_ODPFOH_LastStoredPntY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_LastStoredPntY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_m_m30_30_1em3_t D_ODPFOH_MeanDevToTraj_1st_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_MeanDevToTraj_1st_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_m_m30_30_1em3_t D_ODPFOH_MeanDevToTraj_3rd_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_MeanDevToTraj_3rd_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_m_m30_30_1em3_t S_ODPFOH_TgtObjPosY0_met; /*!< @description
	*	Target object position Y0 \n\n
	*	\@asap_name: S_ODPFOH_TgtObjPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ODPFOH_TgtObjHeadAng_rad; /*!< @description
	*	Target object heading angle \n\n
	*	\@asap_name: S_ODPFOH_TgtObjHeadAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_s_0_100_1em4_t D_ODPFOH_LastStoredPntAge_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_LastStoredPntAge_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ODPFOH_TgtObjClothoidInv_btf; /*!< @description
	*	ODPFOH Invalid Bitfield: \n
	*	0: AccObjInvalidAsNewSample \n
	*	1: AccObjPosFreeze \n
	*	2: ObjValidTransitionOngoing \n
	*	3: CutInTransitionOngoing \n
	*	4: CutOutTransitionOngoing \n
	*	5: FreezeStopTransOngoing \n
	*	6: TrajNotUpdated \n
	*	7: TrajInvalid \n
	*	8: HistoryModeInactive (Polyfit) \n
	*	9: LowSpeedModeInactive \n
	*	10: LowSpeedModeTransitionOngoing \n
	*	11: TrajInvTransitionOngoing \n
	*	12: HistoryDisabled \n
	*	13: HistroyReset \n\n
	*	\@asap_name: S_ODPFOH_TgtObjClothoidInv_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u8_NoUnit_0_100_0_1_t D_ODPFOH_NumValidSamples_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_NumValidSamples_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t D_ODPFOH_AddNewSample_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_ODPFOH_AddNewSample_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t S_ODPFOH_ObjTraceCrvQual_perc; /*!< @description
	*	Trace curvature quality signal \n\n
	*	\@asap_name: S_ODPFOH_ObjTraceCrvQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ODPFOH_ObjTraceQual_perc; /*!< @description
	*	Quality signal of object trace trajectory (History Polyfit) \n\n
	*	\@asap_name: S_ODPFOH_ObjTraceQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ODPFOH_ObjTraceStraight_perc; /*!< @description
	*	Probability of a straight object trace trajectory (dominant 1st order History Polyfit) \n\n
	*	\@asap_name: S_ODPFOH_ObjTraceStraight_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
} ODPFOH_SenDbgType; /*!< @description ODPFOH module sensor debug data structure for MTS measurement. */

/*! ODPFOH module sensor output data structure. */
typedef struct
{
	
	f32_1pm2_m0p001_0p001_1em3_t S_ODPFOH_TgtObjCrvChng_1pm2; /*!< @description
	*	Target object curvature change \n\n
	*	\@asap_name: S_ODPFOH_TgtObjCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_m_m100_100_1em3_t D_ODPFOH_FirstStoredPntX_met; /*!< @description
	*	 \n\n
	*	\@asap_name: D_ODPFOH_FirstStoredPntX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_100_1em4_t D_ODPFOH_FirstStoredPntAge_sec; /*!< @description
	*	 \n\n
	*	\@asap_name: D_ODPFOH_FirstStoredPntAge_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_100_1em4_t D_ODPFOH_MeanStoredPntAge_sec; /*!< @description
	*	 \n\n
	*	\@asap_name: D_ODPFOH_MeanStoredPntAge_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
} ODPFOH_SenOutType; /*!< @description ODPFOH module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif /* ODPFOH_TYPE_H_*/
