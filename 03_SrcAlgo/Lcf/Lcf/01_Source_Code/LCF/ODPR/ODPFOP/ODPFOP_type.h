/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:21:16CEST $
  $Log: ODPFOP_type.h  $
  Revision 1.4.1.2 2020/04/09 14:21:16CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:02:19CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOP_type.h
//! @brief     (ODPFOP) Module Type Header.

#ifndef ODPFOP_TYPE_H_
#define ODPFOP_TYPE_H_

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

/*! ODPFOP module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_0_300_1em3_t S_ODPFOP_AccObjPosX_met; /*!< @description
	*	Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. \n\n
	*	\@asap_name: S_ODPFOP_AccObjPosX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t S_ODPFOP_EstimatedObjPosX_met; /*!< @description
	*	Estimated X-Position based on current X-Position and longitudinal ego kinematics \n\n
	*	\@asap_name: S_ODPFOP_EstimatedObjPosX_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_m100_100_1em3_t S_ODPFOP_AccObjPosXStdDev_met; /*!< @description
	*	Standard deviation of PositionPosX__m. Negative if invalid. \n\n
	*	\@asap_name: S_ODPFOP_AccObjPosXStdDev_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m30_30_1em3_t S_ODPFOP_AccObjPosYStdDev_met; /*!< @description
	*	Standard deviation of PositionPosY__m. Negative if invalid. \n\n
	*	\@asap_name: S_ODPFOP_AccObjPosYStdDev_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_m_m30_30_1em3_t S_ODPFOP_AccObjPosY_met; /*!< @description
	*	Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. \n\n
	*	\@asap_name: S_ODPFOP_AccObjPosY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_m_m30_30_1em3_t S_ODPFOP_EstimatedObjPosY_met; /*!< @description
	*	Estimated Y-Position based on current Y-Position and lateral ego kinematics \n\n
	*	\@asap_name: S_ODPFOP_EstimatedObjPosY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -30 \n
	*	\@max: 30
	*/
	
	f32_mps2_m20_20_1em3_t S_ODPFOP_AccObjRelAclX_mps2; /*!< @description
	*	Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. \n\n
	*	\@asap_name: S_ODPFOP_AccObjRelAclX_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_ODPFOP_AccObjRelAclY_mps2; /*!< @description
	*	Relative lateral acceleration: Acceleration in lateral direction of the object, relative to the host vehicle. This value shall be positive when the object accelerates towards the right. \n\n
	*	\@asap_name: S_ODPFOP_AccObjRelAclY_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_150_1em3_t S_ODPFOP_AccObjRelVelX_mps; /*!< @description
	*	Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). \n\n
	*	\@asap_name: S_ODPFOP_AccObjRelVelX_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_mps_m20_20_1em3_t S_ODPFOP_AccObjRelVelY_mps; /*!< @description
	*	Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. \n\n
	*	\@asap_name: S_ODPFOP_AccObjRelVelY_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_ODPFOP_AccObjRelYawAng_rad; /*!< @description
	*	Relative Yaw angle between Object axis and Ego axis \n\n
	*	\@asap_name: S_ODPFOP_AccObjRelYawAng_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_4295_1em6_t S_ODPFOP_AccFRObjTStamp_sec; /*!< @description
	*	Timestamp of object detection \n\n
	*	\@asap_name: S_ODPFOP_AccFRObjTStamp_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 4295
	*/
	
	u16_NoUnit_0_65535_0_1_t S_ODPFOP_AccObjInvBitfield_btf; /*!< @description
	*	Invalid Bitfield Description: \n
	*	Bit 0: ACC Object Detected \n
	*	Bit 1: Object Quality \n
	*	Bit 2: Object Measurement state \n
	*	Bit 3: PosY \n
	*	Bit 4: PosX \n
	*	Bit 5: Object Width \n
	*	Bit 6: Object longitudinal velocity \n
	*	Bit 7: Object lateral velocity \n
	*	Bit 8: Object longitudinal acceleration \n
	*	Bit 9: Object type \n
	*	Bit 10: Object Fusion state \n
	*	Bit 11: Object ID switch \n
	*	Bit 12: unused \n
	*	Bit 13: unused \n
	*	Bit 14: unused \n
	*	Bit 15: unused \n\n
	*	\@asap_name: S_ODPFOP_AccObjInvBitfield_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
} ODPFOP_SenDbgType; /*!< @description ODPFOP module sensor debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif /* ODPFOP_TYPE_H_*/
