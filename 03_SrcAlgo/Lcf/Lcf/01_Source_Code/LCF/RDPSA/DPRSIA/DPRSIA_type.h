/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSIA_type.h
//! @brief     (DPRSIA) Module Type Header.

#ifndef DPRSIA_TYPE_H_
#define DPRSIA_TYPE_H_

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

/*! DPRSIA module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_0_10_1em3_t S_DPRSIA_LaneWidthRDP_met; /*!< @description
	*	New calculated Lane Width used across RDP. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: S_DPRSIA_LaneWidthRDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_DPRSIA_LaneWidthRDW_met; /*!< @description
	*	New calculated Lane Width used across RDW. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: S_DPRSIA_LaneWidthRDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DlcLeRDP_met; /*!< @description
	*	Distance to cross the left lane marking for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_DlcLeRDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DlcLeRDW_met; /*!< @description
	*	Distance to cross the left lane marking for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_DlcLeRDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DlcRiRDP_met; /*!< @description
	*	Distance to cross the right lane marking for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_DlcRiRDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DlcRiRDW_met; /*!< @description
	*	Distance to cross the right lane marking for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_DlcRiRDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DrcLeRDP_met; /*!< @description
	*	Distance to cross the left road edge for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_DrcLeRDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DrcLeRDW_met; /*!< @description
	*	Distance to cross the left road edge for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_DrcLeRDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DrcRiRDP_met; /*!< @description
	*	Distance to cross the right road edge for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_DrcRiRDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPRSIA_DrcRiRDW_met; /*!< @description
	*	Distance to cross the right road edge for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_DrcRiRDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatLnLeRDP_mps; /*!< @description
	*	Lateral velocity towards the left lane marking for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_VelLatLnLeRDP_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatLnLeRDW_mps; /*!< @description
	*	Lateral velocity towards the left lane marking for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_VelLatLnLeRDW_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatLnRiRDP_mps; /*!< @description
	*	Lateral velocity towards the right lane marking for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_VelLatLnRiRDP_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatLnRiRDW_mps; /*!< @description
	*	Lateral velocity towards the right lane marking for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_VelLatLnRiRDW_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatReLeRDP_mps; /*!< @description
	*	Lateral velocity towards the left road edge for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_VelLatReLeRDP_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatReLeRDW_mps; /*!< @description
	*	Lateral velocity towards the left road edge for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_VelLatReLeRDW_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatReRiRDP_mps; /*!< @description
	*	Lateral velocity towards the right road edge for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_VelLatReRiRDP_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPRSIA_VelLatReRiRDW_mps; /*!< @description
	*	Lateral velocity towards the right road edge for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_VelLatReRiRDW_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TlcLeRDP_sec; /*!< @description
	*	Time to cross the left lane marking for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_TlcLeRDP_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TlcLeRDW_sec; /*!< @description
	*	Time to cross the left lane marking for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_TlcLeRDW_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TlcRiRDP_sec; /*!< @description
	*	Time to cross the right lane marking for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_TlcRiRDP_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TlcRiRDW_sec; /*!< @description
	*	Time to cross the right lane marking for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_TlcRiRDW_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TrcLeRDP_sec; /*!< @description
	*	Time to cross the left road edge for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_TrcLeRDP_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TrcLeRDW_sec; /*!< @description
	*	Time to cross the left road edge for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_TrcLeRDW_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TrcRiRDP_sec; /*!< @description
	*	Time to cross the right road edge for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_TrcRiRDP_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPRSIA_TrcRiRDW_sec; /*!< @description
	*	Time to cross the right road edge for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_TrcRiRDW_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_DPRSMI_TrgReasType_t S_DPRSIA_TriggerReasonLeRDP_nu; /*!< @description
	*	Left side Trigger Reason of the RDP function. \n\n
	*	\@asap_name: S_DPRSIA_TriggerReasonLeRDP_nu \n
	*	\@values: E_DPRSMI_TrgReasType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4
	*/
	
	E_DPRSMI_TrgReasType_t S_DPRSIA_TriggerReasonLeRDW_nu; /*!< @description
	*	Left side Trigger Reason of the RDW function. \n\n
	*	\@asap_name: S_DPRSIA_TriggerReasonLeRDW_nu \n
	*	\@values: E_DPRSMI_TrgReasType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4
	*/
	
	E_DPRSMI_TrgReasType_t S_DPRSIA_TriggerReasonRiRDP_nu; /*!< @description
	*	Right side Trigger Reason of the RDP function. \n\n
	*	\@asap_name: S_DPRSIA_TriggerReasonRiRDP_nu \n
	*	\@values: E_DPRSMI_TrgReasType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4
	*/
	
	E_DPRSMI_TrgReasType_t S_DPRSIA_TriggerReasonRiRDW_nu; /*!< @description
	*	Right side Trigger Reason of the RDW function. \n\n
	*	\@asap_name: S_DPRSIA_TriggerReasonRiRDW_nu \n
	*	\@values: E_DPRSMI_TrgReasType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4
	*/
	
	E_HMORQG_BndValidType_t S_DPRSIA_LnBndValidRDP_nu; /*!< @description
	*	Validity of both lane markings for the RDP function. \n\n
	*	\@asap_name: S_DPRSIA_LnBndValidRDP_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	E_HMORQG_BndValidType_t S_DPRSIA_LnBndValidRDW_nu; /*!< @description
	*	Validity of both lane markings for the RDW function. \n\n
	*	\@asap_name: S_DPRSIA_LnBndValidRDW_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	E_HMORQG_BndValidType_t S_DPRSIA_RdBndValidRDP_nu; /*!< @description
	*	Validity of both road edges for the RDP function. \n\n
	*	\@asap_name: S_DPRSIA_RdBndValidRDP_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	E_HMORQG_BndValidType_t S_DPRSIA_RdBndValidRDW_nu; /*!< @description
	*	Validity of both road edges for the RDW function. \n\n
	*	\@asap_name: S_DPRSIA_RdBndValidRDW_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndLeCancelValidRDP_bool; /*!< @description
	*	Validity of the left lane marking for the RDP in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_LnBndLeCancelValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndLeCancelValidRDW_bool; /*!< @description
	*	Validity of the left lane marking for the RDW in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_LnBndLeCancelValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndLeTrgValidRDP_bool; /*!< @description
	*	Validity of the left lane marking for the RDP in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_LnBndLeTrgValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndLeTrgValidRDW_bool; /*!< @description
	*	Validity of the left lane marking for the RDW in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_LnBndLeTrgValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndRiCancelValidRDP_bool; /*!< @description
	*	Validity of the right lane marking for the RDP in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_LnBndRiCancelValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndRiCancelValidRDW_bool; /*!< @description
	*	Validity of the right lane marking for the RDW in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_LnBndRiCancelValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndRiTrgValidRDP_bool; /*!< @description
	*	Validity of the right lane marking for the RDP in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_LnBndRiTrgValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_LnBndRiTrgValidRDW_bool; /*!< @description
	*	Validity of the right lane marking for the RDW in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_LnBndRiTrgValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndLeCancelValidRDP_bool; /*!< @description
	*	Validity of the left road edge for the RDP in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_RdBndLeCancelValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndLeCancelValidRDW_bool; /*!< @description
	*	Validity of the left road edge for the RDW in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_RdBndLeCancelValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndLeTrgValidRDP_bool; /*!< @description
	*	Validity of the left road edge for the RDP in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_RdBndLeTrgValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndLeTrgValidRDW_bool; /*!< @description
	*	Validity of the left road edge for the RDW in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_RdBndLeTrgValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndRiCancelValidRDP_bool; /*!< @description
	*	Validity of the right road edge for the RDP in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_RdBndRiCancelValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndRiCancelValidRDW_bool; /*!< @description
	*	Validity of the right road edge for the RDW in order to cancel. \n\n
	*	\@asap_name: D_DPRSIA_RdBndRiCancelValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndRiTrgValidRDP_bool; /*!< @description
	*	Validity of the right road edge for the RDP in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_RdBndRiTrgValidRDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPRSIA_RdBndRiTrgValidRDW_bool; /*!< @description
	*	Validity of the right road edge for the RDW in order to trigger. \n\n
	*	\@asap_name: D_DPRSIA_RdBndRiTrgValidRDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPRSIA_TgtCntrLnEnable_bool; /*!< @description
	*	Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
	*	\@asap_name: S_DPRSIA_TgtCntrLnEnable_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPRSIA_SideCondRDPLe_btf; /*!< @description
	*	Bitfield with the left side conditions for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_SideCondRDPLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPRSIA_SideCondRDPRi_btf; /*!< @description
	*	Bitfield with the right side conditions for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_SideCondRDPRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPRSIA_SideCondRDWLe_btf; /*!< @description
	*	Bitfield with the left side conditions for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_SideCondRDWLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPRSIA_SideCondRDWRi_btf; /*!< @description
	*	Bitfield with the right side conditions for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_SideCondRDWRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPRSIA_SpecificRDP_btf; /*!< @description
	*	Bitfield with the specific conditions for the RDP. \n\n
	*	\@asap_name: S_DPRSIA_SpecificRDP_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPRSIA_SpecificRDW_btf; /*!< @description
	*	Bitfield with the specific conditions for the RDW. \n\n
	*	\@asap_name: S_DPRSIA_SpecificRDW_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPRSIA_SenDbgType; /*!< @description DPRSIA module sensor debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // DPRSIA_TYPE_H_
