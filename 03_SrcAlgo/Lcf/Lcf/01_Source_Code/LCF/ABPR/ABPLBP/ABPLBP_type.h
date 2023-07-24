/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPLBP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPLBP_type.h
//! @brief     (ABPLBP) Module Type Header.

#ifndef ABPLBP_TYPE_H_
#define ABPLBP_TYPE_H_

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

/*! ABPLBP module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPLBP_CntrLnClthCrvChng_1pm2; /*!< @description
	*	Lane center clothoid curvature change \n\n
	*	\@asap_name: S_ABPLBP_CntrLnClthCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPLBP_LeLnClthCrvChng_1pm2; /*!< @description
	*	Left lane clothoid change of curvature \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPLBP_LeLnClthCrvRtSIF_1pm2; /*!< @description
	*	Left lane clothoid change of curvature (SIF) \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthCrvRtSIF_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPLBP_RiLnClthCrvChng_1pm2; /*!< @description
	*	Right lane clothoid curvature change \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPLBP_RiLnClthCrvRtSIF_1pm2; /*!< @description
	*	Right lane clothoid curvature change (SIF) \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthCrvRtSIF_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPLBP_CntrLnClthCrv_1pm; /*!< @description
	*	Lane center clothoid curvature \n\n
	*	\@asap_name: S_ABPLBP_CntrLnClthCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPLBP_LeLnClthCrvSIF_1pm; /*!< @description
	*	Left lane clothoid curvature (safety interface) \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthCrvSIF_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPLBP_LeLnClthCrv_1pm; /*!< @description
	*	Left lane clothoid curvature \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPLBP_RiLnClthCrvSIF_1pm; /*!< @description
	*	Right lane clothoid curvature (safety interface) \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthCrvSIF_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPLBP_RiLnClthCrv_1pm; /*!< @description
	*	Right lane clothoid curvature \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_10_1em3_t S_ABPLBP_CoupledLaneWidth_met; /*!< @description
	*	Raw lane width of ABD interface coupled lane data \n\n
	*	\@asap_name: S_ABPLBP_CoupledLaneWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_ABPLBP_LaneWidth_met; /*!< @description
	*	Lane width \n\n
	*	\@asap_name: S_ABPLBP_LaneWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_ABPLBP_UncoupledLaneWidth_met; /*!< @description
	*	Raw lane width of ABD interface uncoupled lane data \n\n
	*	\@asap_name: S_ABPLBP_UncoupledLaneWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_300_1em3_t S_ABPLBP_CntrLnClthLength_met; /*!< @description
	*	Lane center clothoid length \n\n
	*	\@asap_name: S_ABPLBP_CntrLnClthLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ABPLBP_LeLnClthLength_met; /*!< @description
	*	Left lane clothoid length \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ABPLBP_LeLnLengthSIF_met; /*!< @description
	*	Left lane clothoid length (SIF) \n\n
	*	\@asap_name: S_ABPLBP_LeLnLengthSIF_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ABPLBP_RiLnClthLength_met; /*!< @description
	*	Right lane clothoid length \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ABPLBP_RiLnLengthSIF_met; /*!< @description
	*	Right lane clothoid length (SIF) \n\n
	*	\@asap_name: S_ABPLBP_RiLnLengthSIF_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_m15_15_1em3_t S_ABPLBP_CntrLnClthPosY0_met; /*!< @description
	*	Lane center clothoid Y0 position \n\n
	*	\@asap_name: S_ABPLBP_CntrLnClthPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPLBP_LeLnClthPosY0SIF_met; /*!< @description
	*	Left lane clothoid Y0 position (safety interface) \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthPosY0SIF_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPLBP_LeLnClthPosY0_met; /*!< @description
	*	Left lane clothoid Y0 position (init +10m) \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPLBP_RiLnClthPosY0SIF_met; /*!< @description
	*	Right lane clothoid Y0 position (safety interface) \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthPosY0SIF_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPLBP_RiLnClthPosY0_met; /*!< @description
	*	Right lane clothoid Y0 position (init -10m) \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPLBP_CntrLnClthHeading_rad; /*!< @description
	*	Lane center clothoid heading angle \n\n
	*	\@asap_name: S_ABPLBP_CntrLnClthHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPLBP_LeLnClthHeadingSIF_rad; /*!< @description
	*	Left lane clothoid heading angle (safety interface) \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthHeadingSIF_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPLBP_LeLnClthHeading_rad; /*!< @description
	*	Left lane clothoid heading angle \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPLBP_RiLnClthHeadingSIF_rad; /*!< @description
	*	Right lane clothoid heading angle \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthHeadingSIF_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPLBP_RiLnClthHeading_rad; /*!< @description
	*	Right lane clothoid heading angle \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_s_0_4295_1em6_t S_ABPLBP_ABDTimeStamp_sec; /*!< @description
	*	ABD data timestamp in seconds \n\n
	*	\@asap_name: S_ABPLBP_ABDTimeStamp_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 4295
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ABPLBP_LeLnInvalidQu_btf; /*!< @description
	*	Bit 0: Not available \n
	*	Bit 1: Lateral distance step \n
	*	Bit 2: Lenght invalid \n
	*	Bit 3: Lateral distance step (output data) \n
	*	Bit 4: Heading step (output data) \n
	*	Bit 5: Curvature step (output data) \n
	*	Bit 6: Curvature rate step (output data) \n
	*	Bit 7: Kalman filter status not valid \n
	*	Bit 8: Input data out of range \n
	*	Bit 9: Output data out of range \n
	*	Bit10:Lane type invalid \n
	*	Bit11:Lane color invalid \n
	*	Bit12:Lane quality invalid \n
	*	Bit13:Lane bridged \n
	*	Bit14:LD virtual lane \n
	*	Bit15:- \n\n
	*	\@asap_name: S_ABPLBP_LeLnInvalidQu_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ABPLBP_OutRangeCheckQuali_btf; /*!< @description
	*	Bit 0: Left lateral position out of range \n
	*	Bit 1: Right lateral position out of range \n
	*	Bit 2: Center lateral position out of range \n
	*	Bit 3: Left heading out of range \n
	*	Bit 4: Right heading out of range \n
	*	Bit 5: Center heading out of range \n
	*	Bit 6: Left curvature out of range \n
	*	Bit 7: Right curvature out of range \n
	*	Bit 8: Center curvature out of range \n
	*	Bit 9: Left curvature rate out of range \n
	*	Bit 10: Right curvature rate out of range \n
	*	Bit 11: Center curvature rate out of range \n\n
	*	\@asap_name: S_ABPLBP_OutRangeCheckQuali_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ABPLBP_RangeCheckQualifier_btf; /*!< @description
	*	Input range check qualifier bitfield: \n
	*	 \n
	*	Bit 0: Left lateral position out of range \n
	*	Bit 1: Left lateral position out of range \n
	*	Bit 2: Right lateral position out of range \n
	*	Bit 3: Left yaw angle out of range \n
	*	Bit 4: Right yaw angle out of range \n
	*	Bit 5: Left curvature out of range \n
	*	Bit 6: Right curvature out of range \n
	*	Bit 7: Left curvature rate out of range \n
	*	Bit 8: Rightcurvature rate out of range \n\n
	*	\@asap_name: S_ABPLBP_RangeCheckQualifier_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ABPLBP_RiLnInvalidQu_btf; /*!< @description
	*	Bit 0: Not available \n
	*	Bit 1: Lateral distance step \n
	*	Bit 2: Lenght invalid \n
	*	Bit 3: Lateral distance step (output data) \n
	*	Bit 4: Heading step (output data) \n
	*	Bit 5: Curvature step (output data) \n
	*	Bit 6: Curvature rate step (output data) \n
	*	Bit 7: Kalman filter status not valid \n
	*	Bit 8: Input data out of range \n
	*	Bit 9: Output data out of range \n
	*	Bit10:Lane type invalid \n
	*	Bit11:Lane color invalid \n
	*	Bit12:Lane quality invalid \n
	*	Bit13:Lane bridged \n
	*	Bit14:LD virtual lane \n
	*	Bit15:- \n\n
	*	\@asap_name: S_ABPLBP_RiLnInvalidQu_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	E_ABPLBP_KalmanStatusType_t S_ABPLBP_CntrLnKalmanStatus_nu; /*!< @description
	*	Center lane kalman filter status \n
	*	0: not valid \n
	*	1: full update \n
	*	2: degraded update \n
	*	3: predict \n
	*	4: init \n
	*	5: reset \n\n
	*	\@asap_name: S_ABPLBP_CntrLnKalmanStatus_nu \n
	*	\@values: E_ABPLBP_KalmanStatusType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_100_0_1_t S_ABPLBP_StraightPathDtct_nu; /*!< @description
	*	Confidence for straight detection - value from 0 to 100 \n\n
	*	\@asap_name: S_ABPLBP_StraightPathDtct_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t S_ABPLBP_ConstructionSite_bool; /*!< @description
	*	TRUE: Construction site detected; \n
	*	FALSE: No construction site detected \n\n
	*	\@asap_name: S_ABPLBP_ConstructionSite_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_ABPLBP_LaneChangeDetected_bool; /*!< @description
	*	Flag that indicates a detected lane change \n\n
	*	\@asap_name: S_ABPLBP_LaneChangeDetected_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_ABPLBP_LeUncoupBrid_bool; /*!< @description
	*	left lane uncoupled lane bridging possible \n\n
	*	\@asap_name: S_ABPLBP_LeUncoupBrid_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_ABPLBP_PitchingDetected_bool; /*!< @description
	*	Determines if pitching situation has been detected \n\n
	*	\@asap_name: S_ABPLBP_PitchingDetected_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_ABPLBP_RiUncoupBrid_bool; /*!< @description
	*	Right lane uncouplded bridging possible \n\n
	*	\@asap_name: S_ABPLBP_RiUncoupBrid_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_LaneValidQualDMC_nu; /*!< @description
	*	Lane valid qualifier for Lat DMC: \n
	*	0 - no ego lanes \n
	*	1 - one sided ego lane detection \n
	*	2 - both sided ego lane detection \n\n
	*	\@asap_name: S_ABPLBP_LaneValidQualDMC_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_LaneValidQualVis_nu; /*!< @description
	*	Qualifier for the visualization: \n
	*	0- no lanes detected \n
	*	1 - left lane detected \n
	*	2 - right lane detected \n
	*	3 - left lane bridged \n
	*	4 - right lane bridged \n
	*	5  - both lanes detected \n
	*	6 - left lane LD virtual \n
	*	7 - right lane LD virtual \n\n
	*	\@asap_name: S_ABPLBP_LaneValidQualVis_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_LeLnInvalidQuSIF_btf; /*!< @description
	*	Left lane invalid qualifier for the safety interface \n
	*	Bit0: Jump in lateral distance stored \n
	*	Bit1: Jump in heading stored \n
	*	Bit2: Jump in curvature stored \n
	*	Bit3: Quality invalid (LD virtual lane) \n\n
	*	\@asap_name: S_ABPLBP_LeLnInvalidQuSIF_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_RiLnInvalidQuSIF_btf; /*!< @description
	*	Right lane invalid qualifier for the safety interface \n
	*	Bit0: Jump in lateral distance stored \n
	*	Bit1: Jump in heading stored \n
	*	Bit2: Jump in curvature stored \n
	*	Bit3: Quality invalid (LD virtual) \n\n
	*	\@asap_name: S_ABPLBP_RiLnInvalidQuSIF_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_UncoupledLaneBrid_btf; /*!< @description
	*	Uncoupled lane bridging bitfield  \n
	*	Bit 0: Left uncoupled lane step \n
	*	Bit 1: Right uncoupled lane step \n
	*	Bit 2: Left exit \n
	*	Bit 3: Right exit  \n
	*	Bit 4: Left curvature dev \n
	*	Bit 5: Right curvature dev \n
	*	Bit 6: Left heading dev \n
	*	Bit 7: Right heading dev \n\n
	*	\@asap_name: S_ABPLBP_UncoupledLaneBrid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_CntrLnKalmanQual_perc; /*!< @description
	*	Center lane kalman quality \n\n
	*	\@asap_name: S_ABPLBP_CntrLnKalmanQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_ExitLeft_perc; /*!< @description
	*	Exit flag for left side \n\n
	*	\@asap_name: S_ABPLBP_ExitLeft_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_ExitRight_perc; /*!< @description
	*	Exit flag for right side \n\n
	*	\@asap_name: S_ABPLBP_ExitRight_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_LeCoupLnQual_perc; /*!< @description
	*	Left coupled lane quality \n\n
	*	\@asap_name: S_ABPLBP_LeCoupLnQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_LeCrvQuality_perc; /*!< @description
	*	Quality of the curvature information based on standard deviations and the lookahead distance \n\n
	*	\@asap_name: S_ABPLBP_LeCrvQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_LeLnQualitySIF_perc; /*!< @description
	*	Left lane safety interface quality (SIF) \n\n
	*	\@asap_name: S_ABPLBP_LeLnQualitySIF_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_LeLnQuality_perc; /*!< @description
	*	Quality of the left ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
	*	\@asap_name: S_ABPLBP_LeLnQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_LeUncoupLnQual_perc; /*!< @description
	*	Left uncoupled lane quality \n\n
	*	\@asap_name: S_ABPLBP_LeUncoupLnQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_PitchingProb_perc; /*!< @description
	*	Pitching detection probability \n\n
	*	\@asap_name: S_ABPLBP_PitchingProb_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_RiCoupLnQual_perc; /*!< @description
	*	Right coupled lane quality \n\n
	*	\@asap_name: S_ABPLBP_RiCoupLnQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_RiCrvQuality_perc; /*!< @description
	*	Quality of the curvature information based on standard deviations and the lookahead distance \n\n
	*	\@asap_name: S_ABPLBP_RiCrvQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_RiLnQualitySIF_perc; /*!< @description
	*	Right lane safety interface quality (SIF) \n\n
	*	\@asap_name: S_ABPLBP_RiLnQualitySIF_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_RiLnQuality_perc; /*!< @description
	*	Quality of the right ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
	*	\@asap_name: S_ABPLBP_RiLnQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_RiUncoupLnQual_perc; /*!< @description
	*	Right uncoupled lane quality \n\n
	*	\@asap_name: S_ABPLBP_RiUncoupLnQual_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPLBP_UpDownHillDtct_perc; /*!< @description
	*	Indicates downhill / uphill scenario detection confidence \n\n
	*	\@asap_name: S_ABPLBP_UpDownHillDtct_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
} ABPLBP_SenDbgType; /*!< @description ABPLBP module sensor debug data structure for MTS measurement. */

/*! ABPLBP module sensor output data structure. */
typedef struct
{
	
	f32_m_m300_300_1em3_t S_ABPLBP_CntrLnClthPosX0_met; /*!< @description
	*	Lane center clothoid X0-Position \n\n
	*	\@asap_name: S_ABPLBP_CntrLnClthPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_m_m300_300_1em3_t S_ABPLBP_LeLnClthPosX0_met; /*!< @description
	*	Left lane clothoid X0 position \n\n
	*	\@asap_name: S_ABPLBP_LeLnClthPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_m_m300_300_1em3_t S_ABPLBP_RiLnClthPosX0_met; /*!< @description
	*	Right lane clothoid X0 position \n\n
	*	\@asap_name: S_ABPLBP_RiLnClthPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_LeftLaneType_enum; /*!< @description
	*	NO_LINE= 0 \n
	*	PAINTED_CONTINUOUS = 1 \n
	*	PAINTED_DASHED = 2 \n
	*	PAINTED_DECORATIVE = 3 \n
	*	DOTTED_CONTINUOUS = 4 \n
	*	DOTTED_DASHED = 5  \n
	*	ELEVATED_CONTINUOUS=6 \n
	*	ELEVATED_DISCRETE = 7 \n
	*	CURBSTONE =8 \n
	*	ROADEDGE =9 \n
	*	UNKNOWN = 10 \n\n
	*	\@asap_name: S_ABPLBP_LeftLaneType_enum \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPLBP_RightLaneType_enum; /*!< @description
	*	NO_LINE= 0 \n
	*	PAINTED_CONTINUOUS = 1 \n
	*	PAINTED_DASHED = 2 \n
	*	PAINTED_DECORATIVE = 3 \n
	*	DOTTED_CONTINUOUS = 4 \n
	*	DOTTED_DASHED = 5  \n
	*	ELEVATED_CONTINUOUS=6 \n
	*	ELEVATED_DISCRETE = 7 \n
	*	CURBSTONE =8 \n
	*	ROADEDGE =9 \n
	*	UNKNOWN = 10 \n\n
	*	\@asap_name: S_ABPLBP_RightLaneType_enum \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} ABPLBP_SenOutType; /*!< @description ABPLBP module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // ABPLBP_TYPE_H_
