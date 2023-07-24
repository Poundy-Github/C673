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
  $Log: ODPFOP.h  $
  Revision 1.4.1.2 2020/04/09 14:21:16CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:02:19CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOP.h
//! @brief     (ODPFOP) Module Header.

#ifndef ODPFOP_H_
#define ODPFOP_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	ODPFOP module sensor initialization function. Function initializes ODPFOP sensor debug data pointer.
 *	
 *	@param
 *		[in] ODPFOP_SenDbgArg Pointer to ODPFOP sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void ODPFOP_SenInitDbgPtr(ODPFOP_SenDbgType *ODPFOP_SenDbgArg);

/*!
 *	ODPFOP module sensor reset function.
 *	
 *	@pre
 *		- The ODPFOP sensor initialization function(s) must be called once.
 *		- The ODPFOP sensor debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		[Debug  Signal] [S_ODPFOP_AccFRObjTStamp_sec](@ref ODPFOP_SenDbgType::S_ODPFOP_AccFRObjTStamp_sec) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjInvBitfield_btf](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjInvBitfield_btf) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjPosXStdDev_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosXStdDev_met) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjPosX_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosX_met) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjPosYStdDev_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosYStdDev_met) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjPosY_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosY_met) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjRelAclX_mps2](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelAclX_mps2) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjRelAclY_mps2](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelAclY_mps2) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjRelVelX_mps](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelVelX_mps) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjRelVelY_mps](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelVelY_mps) \n
 *		[Debug  Signal] [S_ODPFOP_AccObjRelYawAng_rad](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelYawAng_rad) \n
 *		[Debug  Signal] [S_ODPFOP_EstimatedObjPosX_met](@ref ODPFOP_SenDbgType::S_ODPFOP_EstimatedObjPosX_met) \n
 *		[Debug  Signal] [S_ODPFOP_EstimatedObjPosY_met](@ref ODPFOP_SenDbgType::S_ODPFOP_EstimatedObjPosY_met) \n\n
 *		For signal details, see sub-section [Globals](@ref ODPFOP_SenProcess_Globals) of the function @ref ODPFOP_SenProcess.
 *		
 *	@InOutCorrelation
 *		Resets all static global variables.
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void ODPFOP_SenReset(void);

/*!
 *	ODPFOP module sensor process function.
 *	
 *	@pre
 *		- The ODPFOP sensor initialization function(s) must be called once.
 *		- The ODPFOP sensor debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		@anchor ODPFOP_SenProcess_Globals
 *		[S_ODPFOP_AccFRObjTStamp_sec](@ref ODPFOP_SenDbgType::S_ODPFOP_AccFRObjTStamp_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Timestamp of object detection \n\n
 *		[S_ODPFOP_AccObjInvBitfield_btf](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjInvBitfield_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Invalid Bitfield Description: \n
 *		Bit 0: ACC Object Detected \n
 *		Bit 1: Object Quality \n
 *		Bit 2: Object Measurement state \n
 *		Bit 3: PosY \n
 *		Bit 4: PosX \n
 *		Bit 5: Object Width \n
 *		Bit 6: Object longitudinal velocity \n
 *		Bit 7: Object lateral velocity \n
 *		Bit 8: Object longitudinal acceleration \n
 *		Bit 9: Object type \n
 *		Bit 10: Object Fusion state \n
 *		Bit 11: Object ID switch \n
 *		Bit 12: unused \n
 *		Bit 13: unused \n
 *		Bit 14: unused \n
 *		Bit 15: unused \n\n
 *		[S_ODPFOP_AccObjPosXStdDev_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosXStdDev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Standard deviation of PositionPosX__m. Negative if invalid. \n\n
 *		[S_ODPFOP_AccObjPosX_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. \n\n
 *		[S_ODPFOP_AccObjPosYStdDev_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosYStdDev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Standard deviation of PositionPosY__m. Negative if invalid. \n\n
 *		[S_ODPFOP_AccObjPosY_met](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjPosY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. \n\n
 *		[S_ODPFOP_AccObjRelAclX_mps2](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelAclX_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. \n\n
 *		[S_ODPFOP_AccObjRelAclY_mps2](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelAclY_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative lateral acceleration: Acceleration in lateral direction of the object, relative to the host vehicle. This value shall be positive when the object accelerates towards the right. \n\n
 *		[S_ODPFOP_AccObjRelVelX_mps](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelVelX_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). \n\n
 *		[S_ODPFOP_AccObjRelVelY_mps](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelVelY_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. \n\n
 *		[S_ODPFOP_AccObjRelYawAng_rad](@ref ODPFOP_SenDbgType::S_ODPFOP_AccObjRelYawAng_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Relative Yaw angle between Object axis and Ego axis \n\n
 *		[S_ODPFOP_EstimatedObjPosX_met](@ref ODPFOP_SenDbgType::S_ODPFOP_EstimatedObjPosX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Estimated X-Position based on current X-Position and longitudinal ego kinematics \n\n
 *		[S_ODPFOP_EstimatedObjPosY_met](@ref ODPFOP_SenDbgType::S_ODPFOP_EstimatedObjPosY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Estimated Y-Position based on current Y-Position and lateral ego kinematics \n\n
 *		@ref S_LCFRCV_AccFRObjClassType_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_ODPFOP_ACCObjClassType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 9 \n
 *		\@description: \n
 *		This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles \n\n
 *		@ref S_LCFRCV_AccFRObjDetected_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates whether TJA target object is detected. \n\n
 *		@ref S_LCFRCV_AccFRObjID_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Target Object ID which should be between 0 and 39. \n
 *		255: no target object available \n\n
 *		@ref S_LCFRCV_AccFRObjMeasState_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_OBPFOP_ACCObjMeasStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		ACC object measurement state \n\n
 *		@ref S_LCFRCV_AccFRObjPosXStdDev_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Standard deviation of PositionPosX__m. Negative if invalid. \n\n
 *		@ref S_LCFRCV_AccFRObjPosX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. \n\n
 *		@ref S_LCFRCV_AccFRObjPosYStdDev_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Standard deviation of PositionPosY__m. Negative if invalid. \n\n
 *		@ref S_LCFRCV_AccFRObjPosY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. \n\n
 *		@ref S_LCFRCV_AccFRObjQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Function preselection ACC object quality (0-100): \n
 *		<=70% shall not be selected as OOI \n
 *		> 70% may be selected as neighbor lane OOI \n
 *		> 85 % may be selected as in lane OOI \n\n
 *		@ref S_LCFRCV_AccFRObjRelAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. \n\n
 *		@ref S_LCFRCV_AccFRObjRelAclY_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative lateral acceleration: Acceleration in lateral direction of the object, relative to the host vehicle. This value shall be positive when the object accelerates towards the right. \n\n
 *		@ref S_LCFRCV_AccFRObjRelVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). \n\n
 *		@ref S_LCFRCV_AccFRObjRelVelY_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. \n\n
 *		@ref S_LCFRCV_AccFRObjRelYawAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Relative Yaw angle between Object axis and Ego axis \n\n
 *		@ref S_LCFRCV_AccFRObjSensorSource_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield for a combination of given enum values to point out what sensor participated at measurement of the object. The object assocaition shall consider different acquisition times and  expected update cycles (properly avoid toggling) \n
 *		 \n
 *		EM_GEN_OBJECT_MS_NONE = 0x0000 \n
 *		EM_GEN_OBJECT_MS_LRR = 0x0001 \n
 *		EM_GEN_OBJECT_MS_MRR = 0x0002 \n
 *		EM_GEN_OBJECT_MS_SRR = 0x0004 \n
 *		EM_GEN_OBJECT_MS_SRL = 0x0008 \n
 *		EM_GEN_OBJECT_MS_CAM = 0x0010 \n
 *		EM_GEN_OBJECT_MS_USN = 0x0020 \n
 *		EM_GEN_OBJECT_MS_HFL = 0x0040 \n
 *		EM_GEN_OBJECT_MS_IR = 0x0080 \n\n
 *		@ref S_LCFRCV_AccFRObjTStamp_usec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u32_us_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: us \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		Object data timestamp \n\n
 *		@ref S_LCFRCV_AccFRObjWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class \n\n
 *		@ref S_LCFRCV_SysCycleTimeSen_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Cycle time for LCF_SEN components (60ms): \n
 *		minimum possible cycle time:1ms \n
 *		maximum possible cycle time:100ms \n\n
 *		@ref S_LCFRCV_VehCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Vehicle curvature \n\n
 *		@ref S_LCFRCV_VehVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Vehicle Speed in miles/hour, computed based on the wheel speeds \n
 *		Negative values when vehicle moves backward \n\n
 *		@ref S_LCFRCV_VehYawRate_rps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_radps_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Ego Vehicle yaw rate (VDY); \n
 *		TODO:Check signal range and choose the corresponding datatype range \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_ODPFOP_DistYMaxCrvOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum lateral curvature offset at target object position \n\n
 *		@ref P_ODPFOP_DriveoffDelayTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time until moving state of both Objects and Ego vehicle is delayed at transition from standstill to driveoff. \n\n
 *		@ref P_ODPFOP_DriveoffTolTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time after driveoff until new lateral object position should be inside tolerance compared to previously frozen lateral position. \n\n
 *		@ref P_ODPFOP_DriveoffVelReset_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Velocity threshold to reset lateral movement freeze flag after standstill \n\n
 *		@ref P_ODPFOP_EnableLatMovFreeze_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE enables freeze of lateral object data (position, velocity, acceleration). FALSE disables it. \n\n
 *		@ref P_ODPFOP_FacMaxDistYActive_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Factor for max dist Y activation \n\n
 *		@ref P_ODPFOP_FusionMCamFront_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Note: Should be an constant -> Cam fusion state \n\n
 *		@ref P_ODPFOP_FusionRadarFront_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Note: Should be a constant -> radar fusion \n\n
 *		@ref P_ODPFOP_LongDistMaxHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Hysteresis distance for Object x-position \n\n
 *		@ref P_ODPFOP_MaxDistYHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum hysteresis for lateral object position validation \n\n
 *		@ref P_ODPFOP_MaxDistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum valid lateral target object distance \n\n
 *		@ref P_ODPFOP_MaxLatAcl_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum lateral acceleration \n\n
 *		@ref P_ODPFOP_MaxLatVelHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum lateral object velocity hysteresis \n\n
 *		@ref P_ODPFOP_MaxLatVel_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum lateral object velocity \n\n
 *		@ref P_ODPFOP_MaxLongAclHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum object longitudinal acceleration hysteresis \n\n
 *		@ref P_ODPFOP_MaxLongAcl_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum valid longitudinal object acceleration \n\n
 *		@ref P_ODPFOP_MaxLongVelHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum longitudinal object velocity hysteresis \n\n
 *		@ref P_ODPFOP_MaxLongVel_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum longitudinal object velocity \n\n
 *		@ref P_ODPFOP_MaxPosXDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Threshold for object switch detection \n\n
 *		@ref P_ODPFOP_MaxPosYDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Threshold for PosY0 object switch detection \n\n
 *		@ref P_ODPFOP_MaxSteerAngle_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximum steering angle \n\n
 *		@ref P_ODPFOP_MinDurCamFusBefBrid_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum duration for cam fusion before bridging \n\n
 *		@ref P_ODPFOP_MinMeasStateForPred_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time span for the object measurement to be 'MEASURED' state before 'PREDITED' state is allowed \n\n
 *		@ref P_ODPFOP_MinObjQualitiy_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum object quality for the validation \n\n
 *		@ref P_ODPFOP_MinWidthTgtObjHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Hysteresis for minimum target object width \n\n
 *		@ref P_ODPFOP_MinWidthTgtObj_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum target object width \n\n
 *		@ref P_ODPFOP_ObjLossDebounceT_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Object loss debounce time \n\n
 *		@ref P_ODPFOP_ObjPosYPT1Time4Yaw_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		PT1 time constant for PosY which is only used for object yaw angle calculation - not for PosY output signal! \n\n
 *		@ref P_ODPFOP_ObjRelToRadar_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines if the objects are expressed in the radar coordinate system \n\n
 *		@ref P_ODPFOP_ObjSyncDelay_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Latency time between ACC target object data and ego VDY input data \n\n
 *		@ref P_ODPFOP_ObjTypeDebounceTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time time for target object validation \n\n
 *		@ref P_ODPFOP_ObjYawPT1Time_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		PT1 filter time constant for either own calculated or input yaw angle signal \n\n
 *		@ref P_ODPFOP_ObjYawSampleDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Sample distance used for update frequency of calculated object yaw angle based on travelled object x distance \n\n
 *		@ref P_ODPFOP_ObjYawSampleTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Sample time used for update frequency of calculated object yaw angle based on travelled object x and y distance during this time \n\n
 *		@ref P_ODPFOP_PosStepDebounceTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time after step has been detected for both PosX and PosY input signal \n\n
 *		@ref P_ODPFOP_RearAxleCoordSys_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Flag if the object data should be transformed to the rear axle coordinate system. \n\n
 *		@ref P_ODPFOP_StandstillVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Below this standstill velocity threshold both Ego and Object moving state is assumed as stationary/stopped. \n\n
 *		@ref P_ODPFOP_UseEstimPosY4Yaw_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If TRUE the internally estimated PosY is used with respect to RelVelY and a constant time. \n
 *		If FALSE the AccObjPosY is used. \n\n
 *		@ref P_ODPFOP_UseOwnObjYaw_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If TRUE then own calculated object yaw angle is used, if FALSE then input signal is used \n\n
 *		@ref P_VEH_OverhangFront_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Front overhang for transformation from radar to front axle coordinate system \n\n
 *		@ref P_VEH_Wheelbase_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_ODPFOP_LongDistMaxVel_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Velocity axis for object distance validation \n\n
 *		@ref Y_ODPFOP_LongDistMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Maximum longitudinal distance for object validation \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: ODPFOP Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/ODPR/ODPFOP_SEN/ODPFOP/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref ODPFOP_Testcase_Initialization) Initialization of the ODPFOP
 *		-# [Testcase_ACCObjectSignalFlow](@ref ODPFOP_Testcase_ACCObjectSignalFlow) Test signal flow in ODPFOP
 *		-# [Testcase_DebounceObjectSelection](@ref ODPFOP_Testcase_DebounceObjectSelection) Debounce object selection test
 *		-# [Testcase_LongitudinalPosTranslation](@ref ODPFOP_Testcase_LongitudinalPosTranslation) Test of the object longitudinal position translation
 *		-# [Testcase_ValidObjectHysteresis](@ref ODPFOP_Testcase_ValidObjectHysteresis) Object hysteresis validation
 *		-# [Testcase_InvalidLongitudinalPos](@ref ODPFOP_Testcase_InvalidLongitudinalPos) Test object longitudinal position validation
 *		-# [Testcase_InvalidQuality](@ref ODPFOP_Testcase_InvalidQuality) Test object quality validation
 *		-# [Testcase_InvalidMaintenanceState](@ref ODPFOP_Testcase_InvalidMaintenanceState) Test object maintenance state validation
 *		-# [Testcase_InvalidLateralPosition](@ref ODPFOP_Testcase_InvalidLateralPosition) Test object lateral position validation
 *		-# [Testcase_InvalidWidth](@ref ODPFOP_Testcase_InvalidWidth) Test object width validation
 *		-# [Testcase_InvalidRelLongVel](@ref ODPFOP_Testcase_InvalidRelLongVel) Test object relative longitudinal velocity validation
 *		-# [Testcase_InvalidRelLongAcl](@ref ODPFOP_Testcase_InvalidRelLongAcl) Test object relative longitudinal acceleration validation
 *		-# [Testcase_InvalidRelLatVel](@ref ODPFOP_Testcase_InvalidRelLatVel) Test object relative lateral velocity validation
 *		-# [Testcase_CameraConfirmationAndBridging](@ref ODPFOP_Testcase_CameraConfirmationAndBridging) Test object fusion state/bridging validation
 *		-# [Testcase_InvalidObjectClass](@ref ODPFOP_Testcase_InvalidObjectClass) Test object class validation
 *		-# [Testcase_FreezeObjectPosition](@ref ODPFOP_Testcase_FreezeObjectPosition) Test lateral object position in standstill
 *		-# [Testcase_StepDetectionPosX](@ref ODPFOP_Testcase_StepDetectionPosX) Test step detection for longitudinal position
 *		-# [Testcase_StepDetectionPosY](@ref ODPFOP_Testcase_StepDetectionPosY) Test step detection for lateral position
 *		-# [Testcase_StepDetectionPassive](@ref ODPFOP_Testcase_StepDetectionPassive) Test step detection with missing conditions
 *		-# [Testcase_EstimatedPosX](@ref ODPFOP_Testcase_EstimatedPosX) Test estimated longitudinal position
 *		-# [Testcase_EstimatedPosY](@ref ODPFOP_Testcase_EstimatedPosY) Test estimated lateral position
 *		-# [Testcase_ExternalYawAng](@ref ODPFOP_Testcase_ExternalYawAng) Test external yaw angle
 *		-# [Testcase_InternalYawAng](@ref ODPFOP_Testcase_InternalYawAng) Test internal yaw angle
 *		-# [Testcase_InternalYawAngEstimPos](@ref ODPFOP_Testcase_InternalYawAngEstimPos) Test internal yaw angle with estimated y-position
 *		-# [Testcase_InternalYawAngSampleDistLim](@ref ODPFOP_Testcase_InternalYawAngSampleDistLim) Test limited integrated object distance
 *		-# [Testcase_InternalYawAngLimPos](@ref ODPFOP_Testcase_InternalYawAngLimPos) Test internal yaw angle with pos. limited yaw rotation
 *		-# [Testcase_InternalYawAngLimNeg](@ref ODPFOP_Testcase_InternalYawAngLimNeg) Test internal yaw angle with neg. limited yaw rotation
 *		
 *	@traceability
 *		[\@link: ODPFOP Module Requirements]()
 */
extern void ODPFOP_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* ODPFOP_H_*/
