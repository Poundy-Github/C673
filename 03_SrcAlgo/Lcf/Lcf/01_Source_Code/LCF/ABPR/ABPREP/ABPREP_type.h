/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPREP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPREP_type.h
//! @brief     (ABPREP) Module Type Header.

#ifndef ABPREP_TYPE_H_
#define ABPREP_TYPE_H_

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

/*! ABPREP module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPREP_LeReClthCrvChng_1pm2; /*!< @description
	*	Left road edge clothoid curvature rate \n\n
	*	\@asap_name: S_ABPREP_LeReClthCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_ABPREP_RiReClthCrvChng_1pm2; /*!< @description
	*	Right road edge clothoid curvature rate \n\n
	*	\@asap_name: S_ABPREP_RiReClthCrvChng_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPREP_LeReClthCrvSIF_1pm; /*!< @description
	*	Left road edge clothoid curvature (safety interface) \n\n
	*	\@asap_name: S_ABPREP_LeReClthCrvSIF_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPREP_LeReClthCrv_1pm; /*!< @description
	*	Left road edge clothoid curvature \n\n
	*	\@asap_name: S_ABPREP_LeReClthCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPREP_RiReClthCrvSIF_1pm; /*!< @description
	*	Right road edge clothoid curvature (safety interface); \n\n
	*	\@asap_name: S_ABPREP_RiReClthCrvSIF_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_ABPREP_RiReClthCrv_1pm; /*!< @description
	*	Right road edge clothoid curvature \n\n
	*	\@asap_name: S_ABPREP_RiReClthCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_300_1em3_t S_ABPREP_LeReLength_met; /*!< @description
	*	Left road edge clothoid length (lookahead distance) \n\n
	*	\@asap_name: S_ABPREP_LeReLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ABPREP_RiReLength_met; /*!< @description
	*	Right road edge clothoid length (lookahead distance) \n\n
	*	\@asap_name: S_ABPREP_RiReLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_m15_15_1em3_t S_ABPREP_LeReClthPosY0SIF_met; /*!< @description
	*	Left road edge clothoid lateral distance (safety interface) \n\n
	*	\@asap_name: S_ABPREP_LeReClthPosY0SIF_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPREP_LeRePosY0_met; /*!< @description
	*	Left road edge clothoid lateral distance (Y0 position) \n\n
	*	\@asap_name: S_ABPREP_LeRePosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPREP_RiReClthPosY0SIF_met; /*!< @description
	*	Right road edge clothoid lateral distance (safety interface); \n\n
	*	\@asap_name: S_ABPREP_RiReClthPosY0SIF_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_ABPREP_RiRePosY0_met; /*!< @description
	*	Right road edge clothoid lateral distance (Pos Y0) \n\n
	*	\@asap_name: S_ABPREP_RiRePosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_mps_m100_100_1em3_t S_ABPREP_LeReLatVel_mps; /*!< @description
	*	Left road edge lateral veloctiy \n\n
	*	\@asap_name: S_ABPREP_LeReLatVel_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps_m100_100_1em3_t S_ABPREP_RiReLatVel_mps; /*!< @description
	*	Right road edge lateral veloctiy \n\n
	*	\@asap_name: S_ABPREP_RiReLatVel_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPREP_LeReClthHeadingSIF_rad; /*!< @description
	*	Left road edge clothoid yaw angle (safety interface) \n\n
	*	\@asap_name: S_ABPREP_LeReClthHeadingSIF_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPREP_LeReHeading_rad; /*!< @description
	*	Left road edge clothoid yaw angle \n\n
	*	\@asap_name: S_ABPREP_LeReHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPREP_RiReClthHeadingSIF_rad; /*!< @description
	*	Right road edge clothoid yaw angle (safety interface); \n\n
	*	\@asap_name: S_ABPREP_RiReClthHeadingSIF_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t S_ABPREP_RiReHeading_rad; /*!< @description
	*	Right road edge clothoid yaw angle \n\n
	*	\@asap_name: S_ABPREP_RiReHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ABPREP_LeReInvalidQu_btf; /*!< @description
	*	Bit 0: Road edge availability invalid \n
	*	Bit 1: Existence probability invalid \n
	*	Bit 2: Road edge type invalid \n
	*	Bit 3: Road edge minimum length invalid \n
	*	Bit 4: Lateral distance step debounced \n
	*	Bit 5: Heading step debounced \n
	*	Bit 6: Curvature step debounced \n
	*	Bit 7: Curvature rate step debounced \n
	*	Bit 8: Lateral distance out of range \n
	*	Bit 9:  Yaw angle out of range \n
	*	Bit 10: Curvature out of range \n
	*	Bit 11: Curvature rate out of range \n
	*	Bit 12: Valid length out of range \n
	*	Bit 13: Road Edge bridging \n
	*	Bit 14: Road Kalman Filter not valid \n\n
	*	\@asap_name: S_ABPREP_LeReInvalidQu_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ABPREP_RiReInvalidQu_btf; /*!< @description
	*	Right invalid road edge qualifier. \n
	*	Bit 0: Road edge availability invalid \n
	*	Bit 1: Existence probability invalid \n
	*	Bit 2: Road edge type invalid \n
	*	Bit 3: Road edge minimum length invalid \n
	*	Bit 4: Lateral distance step debounced \n
	*	Bit 5: Heading step debounced \n
	*	Bit 6: Curvature step debounced \n
	*	Bit 7: Curvature rate step debounced \n
	*	Bit 8: Lateral distance out of range \n
	*	Bit 9:  Yaw angle out of range \n
	*	Bit 10: Curvature out of range \n
	*	Bit 11: Curvature rate out of range \n
	*	Bit 12: Valid length out of range \n
	*	Bit 13: Road Edge bridging \n
	*	Bit 14: Road Kalman Filter not valid \n\n
	*	\@asap_name: S_ABPREP_RiReInvalidQu_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	E_ABPLBP_KalmanStatusType_t S_ABPREP_LeReKFStatus_enum; /*!< @description
	*	Left road edge kalman filter status \n
	*	 \n
	*	0: not valid \n
	*	1: full update \n
	*	2: degraded update \n
	*	3: predict \n
	*	4: init \n
	*	5: reset \n\n
	*	\@asap_name: S_ABPREP_LeReKFStatus_enum \n
	*	\@values: E_ABPLBP_KalmanStatusType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	E_ABPLBP_KalmanStatusType_t S_ABPREP_RiReKFStatus_enum; /*!< @description
	*	Right road edge kalman filter status \n
	*	 \n
	*	0: not valid \n
	*	1: full update \n
	*	2: degraded update \n
	*	3: predict \n
	*	4: init \n
	*	5: reset \n\n
	*	\@asap_name: S_ABPREP_RiReKFStatus_enum \n
	*	\@values: E_ABPLBP_KalmanStatusType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPREP_LaneStabilization_btf; /*!< @description
	*	Bitfield determines lane stabilization \n
	*	Bit0: LeReStabilized; \n
	*	Bit1: RiReSTabilized; \n
	*	Bit2: LeReSIFStabilized; \n
	*	Bit3: RiReSIFStabilized; \n\n
	*	\@asap_name: S_ABPREP_LaneStabilization_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPREP_LeReInvalidQuSIF_btf; /*!< @description
	*	Left road edge clothoid invalid qualifier (safety interface); \n
	*	 \n
	*	Bit 0: Lateral distance jump debounced; \n
	*	Bit 1: Yaw angle jump debounce; \n
	*	Bit 2: Curvature jump debounced; \n
	*	Bit 3: Quality invalid \n
	*	Bit 4: Bridging \n\n
	*	\@asap_name: S_ABPREP_LeReInvalidQuSIF_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPREP_LnBndGradLimActive_btf; /*!< @description
	*	Gradient limiter active bitfield: \n
	*	 \n
	*	Bit 0: Left lateral position gradient limiter active \n
	*	Bit 1: Left yaw angle gradient limiter active \n
	*	Bit 2: Left curvature gradient limiter active \n
	*	Bit 3: Left curvature rate gradient limiter active \n
	*	Bit 4: Right lateral position gradient limiter active \n
	*	Bit 5: Right heading angle gradient limiter active \n
	*	Bit 6: Right curvature gradient limiter active \n
	*	Bit 7: Right curvature rate gradient limiter active \n\n
	*	\@asap_name: S_ABPREP_LnBndGradLimActive_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_ABPREP_RiReInvalidQuSIF_btf; /*!< @description
	*	Right road edge clothoid invalid qualifier (safety interface); \n
	*	 \n
	*	Bit 0: Lateral distance jump debounced; \n
	*	Bit 1: Yaw angle jump debounce; \n
	*	Bit 2: Curvature jump debounced; \n
	*	Bit 3: Quality invalid \n
	*	Bit 4: Bridging \n\n
	*	\@asap_name: S_ABPREP_RiReInvalidQuSIF_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_Perc_0_100_0_1_t S_ABPREP_LeReKFQuality_perc; /*!< @description
	*	Leftroad edge kalman filter quality \n\n
	*	\@asap_name: S_ABPREP_LeReKFQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPREP_LeReQuality_perc; /*!< @description
	*	Left road edge quality \n\n
	*	\@asap_name: S_ABPREP_LeReQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPREP_RiReKFQuality_perc; /*!< @description
	*	Right road edge kalman filter quality \n\n
	*	\@asap_name: S_ABPREP_RiReKFQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t S_ABPREP_RiReQuality_perc; /*!< @description
	*	Right road edge quality \n\n
	*	\@asap_name: S_ABPREP_RiReQuality_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
} ABPREP_SenDbgType; /*!< @description ABPREP module sensor debug data structure for MTS measurement. */

/*! ABPREP module sensor output data structure. */
typedef struct
{
	
	f32_m_m300_300_1em3_t S_ABPREP_LeReClthPosX0_met; /*!< @description
	*	Left road edge clothoid X0 coordinate \n\n
	*	\@asap_name: S_ABPREP_LeReClthPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_m_m300_300_1em3_t S_ABPREP_RiReClthPosX0_met; /*!< @description
	*	Right road edge clothoid X0 coordinate \n\n
	*	\@asap_name: S_ABPREP_RiReClthPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
} ABPREP_SenOutType; /*!< @description ABPREP module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // ABPREP_TYPE_H_
