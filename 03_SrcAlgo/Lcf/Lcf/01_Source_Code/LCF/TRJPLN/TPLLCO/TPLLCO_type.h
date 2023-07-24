/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLLCO
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLLCO_type.h
//! @brief     (TPLLCO) Module Type Header.

#ifndef TPLLCO_TYPE_H_
#define TPLLCO_TYPE_H_

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

/*! TPLLCO module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm2_m0p001_0p001_1em3_t S_TPLLCO_LeftCridrChngOfCrv_1pm2; /*!< @description
	*	left corridor curvature change in right corridor cooridinate system \n\n
	*	\@asap_name: S_TPLLCO_LeftCridrChngOfCrv_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_TPLLCO_RiCridrChngOfCrv_1pm2; /*!< @description
	*	right corridor curvature change in right corridor cooridnate system \n\n
	*	\@asap_name: S_TPLLCO_RiCridrChngOfCrv_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm2_m0p001_0p001_1em3_t S_TPLLCO_TgtCridrChngOfCrv_1pm2; /*!< @description
	*	target corridor curvature change in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_TgtCridrChngOfCrv_1pm2 \n
	*	\@type: value \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.001 \n
	*	\@max: 0.001
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TPLLCO_LeftCorridorCrv_1pm; /*!< @description
	*	left corridor curvature in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_LeftCorridorCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TPLLCO_RightCorridorCrv_1pm; /*!< @description
	*	right corridor curvature in right corridor cooridnate system \n\n
	*	\@asap_name: S_TPLLCO_RightCorridorCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TPLLCO_TargetCorridorCrv_1pm; /*!< @description
	*	target corridor curvature in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_TargetCorridorCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TPLLCO_TargetPathCrv_rad; /*!< @description
	*	curvature of the target path (target corridor with X0 = 0) \n\n
	*	\@asap_name: S_TPLLCO_TargetPathCrv_rad \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_1_1em6_t D_TPLLCO_CCCPassedPerc_nu; /*!< @description
	*	Testpoint DistX / Length of the reference \n\n
	*	\@asap_name: D_TPLLCO_CCCPassedPerc_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_1000_1em3_t D_TPLLCO_CCCTestPointDistX_met; /*!< @description
	*	DistX of the test point \n\n
	*	\@asap_name: D_TPLLCO_CCCTestPointDistX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_m_0_100_1em5_t D_TPLLCO_CCCLength_met; /*!< @description
	*	Length of the reference \n\n
	*	\@asap_name: D_TPLLCO_CCCLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_10_1em3_t S_TPLLCO_LeftCorridorPosY0_met; /*!< @description
	*	left corridor lateral position in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_LeftCorridorPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_150_1em3_t S_TPLLCO_LeftCorridorLength_met; /*!< @description
	*	left corridor valid length in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_LeftCorridorLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_TPLLCO_RightCorridorLength_met; /*!< @description
	*	right corridor valid length in right corridor cooridnate system \n\n
	*	\@asap_name: S_TPLLCO_RightCorridorLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t S_TPLLCO_TargetCridrLength_met; /*!< @description
	*	target corridor valid length in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_TargetCridrLength_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_1_1em3_t D_TPLLCO_LeCridrTransDev_met[4]; /*!< @description
	*	Deviation of the lateral position between the orginal and transformed left corridor boundary. \n\n
	*	\@asap_name: D_TPLLCO_LeCridrTransDev_met \n
	*	\@type: curve \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_1_1em3_t D_TPLLCO_RiCridrTransDev_met[4]; /*!< @description
	*	Deviation of the lateral position between the orginal and transformed right corridor boundary \n\n
	*	\@asap_name: D_TPLLCO_RiCridrTransDev_met \n
	*	\@type: curve \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_1_1em3_t D_TPLLCO_TgtCridrTransDev_met[4]; /*!< @description
	*	Deviation of the lateral position between the orginal and transformed target corridor \n\n
	*	\@asap_name: D_TPLLCO_TgtCridrTransDev_met \n
	*	\@type: curve \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_m1000_1000_1em3_t D_TPLLCO_CCCDeviation_met; /*!< @description
	*	Lateral deviation of CCC (course consistency check) \n\n
	*	\@asap_name: D_TPLLCO_CCCDeviation_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m100_100_1em3_t S_TPLLCO_LeftCorridorPosX0_met; /*!< @description
	*	left corridor longitudinal start position in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_LeftCorridorPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t S_TPLLCO_RightCorridorPosX0_met; /*!< @description
	*	right corridor longitudinal start position in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_RightCorridorPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t S_TPLLCO_TargetCorridorPosX0_met; /*!< @description
	*	target corridor longitudinal start position in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_TargetCorridorPosX0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m10_10_1em3_t D_TPLLCO_DeltaProjPosX_met; /*!< @description
	*	Projection on x axle of the foot of the perpendicular from reference point (e.g. front axle middle) to the right corridor boundary in the vehicle coordinate system. \n\n
	*	\@asap_name: D_TPLLCO_DeltaProjPosX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t D_TPLLCO_DeltaProjPosY_met; /*!< @description
	*	Projection on y axle of the foot of the perpendicular from reference point (e.g. front axle middle) to the right corridor boundary in the vehicle coordinate system. \n\n
	*	\@asap_name: D_TPLLCO_DeltaProjPosY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t D_TPLLCO_EgoDistYPre_met; /*!< @description
	*	ego disty prediction based on ego curvature and preview distance \n\n
	*	\@asap_name: D_TPLLCO_EgoDistYPre_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t S_TPLLCO_ReplanDevDistY_met; /*!< @description
	*	deviation in lateral position by replanning \n\n
	*	\@asap_name: S_TPLLCO_ReplanDevDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t S_TPLLCO_RightCorridorPosY0_met; /*!< @description
	*	right corridor lateral position in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_RightCorridorPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t S_TPLLCO_TargetCorridorPosY0_met; /*!< @description
	*	target corridor lateral position in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_TargetCorridorPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t S_TPLLCO_TargetPathY0_met; /*!< @description
	*	lateral position of the target path (target corridor with X0 = 0) \n\n
	*	\@asap_name: S_TPLLCO_TargetPathY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t S_TPLLCO_DevDistY_met; /*!< @description
	*	vehicle ego lateral distance in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_DevDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t D_TPLLCO_RightOri_rad; /*!< @description
	*	Orientation of the right corridor at the foot of the perpendicular \n\n
	*	\@asap_name: D_TPLLCO_RightOri_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TPLLCO_DevHeading_rad; /*!< @description
	*	vehicle heading angle in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_DevHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TPLLCO_LeftCorridorHeading_rad; /*!< @description
	*	left corridor heading angle in right corridor cooridnate system \n\n
	*	\@asap_name: S_TPLLCO_LeftCorridorHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TPLLCO_ReplanDevHeading_rad; /*!< @description
	*	heading angle deviation by replanning \n\n
	*	\@asap_name: S_TPLLCO_ReplanDevHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TPLLCO_RightCridrHeading_rad; /*!< @description
	*	right corridor heading angle in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_RightCridrHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TPLLCO_TargetCridrHeading_rad; /*!< @description
	*	target corridor heading angle in right corridor coordinate system \n\n
	*	\@asap_name: S_TPLLCO_TargetCridrHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TPLLCO_TargetPathHeading_rad; /*!< @description
	*	heading angle of the target path (target corridor with X0 = 0) \n\n
	*	\@asap_name: S_TPLLCO_TargetPathHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t D_TPLLCO_EgoHeadingPre_rad; /*!< @description
	*	ego heading prediction based on ego curvature and preview distance \n\n
	*	\@asap_name: D_TPLLCO_EgoHeadingPre_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_s_0_1_1em3_t S_TPLLCO_MeasDeltaT_sec; /*!< @description
	*	Delta between LD and VDY time stamps \n\n
	*	\@asap_name: S_TPLLCO_MeasDeltaT_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLLCO_CCCInvalid_nu; /*!< @description
	*	CCC failed \n\n
	*	\@asap_name: D_TPLLCO_CCCInvalid_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLLCO_CCCReset_nu; /*!< @description
	*	reference reset \n\n
	*	\@asap_name: D_TPLLCO_CCCReset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLLCO_CCCWarning_nu; /*!< @description
	*	CCC Deviation over the threshold detected \n\n
	*	\@asap_name: D_TPLLCO_CCCWarning_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLLCO_TriggerReplan_nu; /*!< @description
	*	trigger for replanning \n\n
	*	\@asap_name: S_TPLLCO_TriggerReplan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_TPLLCO_PlausiCheckStatus_nu; /*!< @description
	*	Bitfield indicates the detailed information of the plausibility check in TPLLCO 1: NOT OK 0: OK \n
	*	Bit 0: vehicle's lateral position \n
	*	Bit 1: right corridor disty \n
	*	Bit 2: right corridor heading \n
	*	Bit 3: right corridor curvature \n
	*	Bit 4: left corridor disty \n
	*	Bit 5: left corridor heading \n
	*	Bit 6: left corridor curvature \n\n
	*	\@asap_name: D_TPLLCO_PlausiCheckStatus_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_TPLLCO_PlausiCheckStatus_nu; /*!< @description
	*	Bitfield indicates the information of the plausibility check in TPLLCO 1: NOT OK 0: OK \n
	*	Bit 0: vehicle's lateral position \n
	*	Bit 1: right corridor transformation \n
	*	Bit 2: left corridor transformation \n\n
	*	\@asap_name: S_TPLLCO_PlausiCheckStatus_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TPLLCO_VehDbgType; /*!< @description TPLLCO module vehicle debug data structure for MTS measurement. */

/*! TPLLCO module vehicle output data structure. */
typedef struct
{
	
	f32_m_m100_100_1em3_t D_TPLLCO_CCCEgoDistX_met; /*!< @description
	*	ego dist X from CCC \n\n
	*	\@asap_name: D_TPLLCO_CCCEgoDistX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m10_10_1em3_t D_TPLLCO_CCCEgoDistY_met; /*!< @description
	*	ego dist Y from CCC \n\n
	*	\@asap_name: D_TPLLCO_CCCEgoDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t D_TPLLCO_CCCEgoYawangle_rad; /*!< @description
	*	Ego Yaw angle from CCC \n\n
	*	\@asap_name: D_TPLLCO_CCCEgoYawangle_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
} TPLLCO_VehOutType; /*!< @description TPLLCO module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TPLLCO_TYPE_H_
