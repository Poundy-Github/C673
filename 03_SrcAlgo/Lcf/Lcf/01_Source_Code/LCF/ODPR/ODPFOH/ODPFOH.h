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
  $Date: 2020/04/09 14:20:46CEST $
  $Log: ODPFOH.h  $
  Revision 1.4.1.2 2020/04/09 14:20:46CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:02:25CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOH.h
//! @brief     (ODPFOH) Module Header.

#ifndef ODPFOH_H_
#define ODPFOH_H_

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
 *	ODPFOH module sensor initialization function. Function initializes ODPFOH sensor debug data pointer.
 *	
 *	@param
 *		[in] ODPFOH_SenDbgArg Pointer to ODPFOH sensor debug data.
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
extern void ODPFOH_SenInitDbgPtr(ODPFOH_SenDbgType *ODPFOH_SenDbgArg);

/*!
 *	ODPFOH module sensor initialization function. Function initializes ODPFOH sensor output data pointer.
 *	
 *	@param
 *		[in] ODPFOH_SenOutArg Pointer to ODPFOH sensor output data.
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
extern void ODPFOH_SenInitOutPtr(ODPFOH_SenOutType *ODPFOH_SenOutArg);

/*!
 *	ODPFOH module sensor reset function.
 *	
 *	@pre
 *		- The ODPFOH sensor initialization function(s) must be called once.
 *		- The ODPFOH sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_ODPFOH_AddNewSample_bool](@ref ODPFOH_SenDbgType::D_ODPFOH_AddNewSample_bool) \n
 *		[Debug  Signal] [D_ODPFOH_LastStoredPntAge_sec](@ref ODPFOH_SenDbgType::D_ODPFOH_LastStoredPntAge_sec) \n
 *		[Debug  Signal] [D_ODPFOH_LastStoredPntX_met](@ref ODPFOH_SenDbgType::D_ODPFOH_LastStoredPntX_met) \n
 *		[Debug  Signal] [D_ODPFOH_LastStoredPntY_met](@ref ODPFOH_SenDbgType::D_ODPFOH_LastStoredPntY_met) \n
 *		[Debug  Signal] [D_ODPFOH_MaxGapEgoToHist_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MaxGapEgoToHist_met) \n
 *		[Debug  Signal] [D_ODPFOH_MeanDevToTraj_1st_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MeanDevToTraj_1st_met) \n
 *		[Debug  Signal] [D_ODPFOH_MeanDevToTraj_3rd_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MeanDevToTraj_3rd_met) \n
 *		[Debug  Signal] [D_ODPFOH_MinHistLength_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MinHistLength_met) \n
 *		[Debug  Signal] [D_ODPFOH_MinHistStartPosX_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MinHistStartPosX_met) \n
 *		[Debug  Signal] [D_ODPFOH_NumValidSamples_nu](@ref ODPFOH_SenDbgType::D_ODPFOH_NumValidSamples_nu) \n
 *		[Debug  Signal] [S_ODPFOH_AccObjTraceCrv_1pm](@ref ODPFOH_SenDbgType::S_ODPFOH_AccObjTraceCrv_1pm) \n
 *		[Debug  Signal] [S_ODPFOH_ObjTraceCrvQual_perc](@ref ODPFOH_SenDbgType::S_ODPFOH_ObjTraceCrvQual_perc) \n
 *		[Debug  Signal] [S_ODPFOH_ObjTraceQual_perc](@ref ODPFOH_SenDbgType::S_ODPFOH_ObjTraceQual_perc) \n
 *		[Debug  Signal] [S_ODPFOH_ObjTraceStraight_perc](@ref ODPFOH_SenDbgType::S_ODPFOH_ObjTraceStraight_perc) \n
 *		[Debug  Signal] [S_ODPFOH_TgtObjClothoidInv_btf](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjClothoidInv_btf) \n
 *		[Debug  Signal] [S_ODPFOH_TgtObjCrv_1pm](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjCrv_1pm) \n
 *		[Debug  Signal] [S_ODPFOH_TgtObjHeadAng_rad](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjHeadAng_rad) \n
 *		[Debug  Signal] [S_ODPFOH_TgtObjLength_met](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjLength_met) \n
 *		[Debug  Signal] [S_ODPFOH_TgtObjPosX0_met](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjPosX0_met) \n
 *		[Debug  Signal] [S_ODPFOH_TgtObjPosY0_met](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjPosY0_met) \n
 *		[Output Signal] [D_ODPFOH_FirstStoredPntAge_sec](@ref ODPFOH_SenOutType::D_ODPFOH_FirstStoredPntAge_sec) \n
 *		[Output Signal] [D_ODPFOH_FirstStoredPntX_met](@ref ODPFOH_SenOutType::D_ODPFOH_FirstStoredPntX_met) \n
 *		[Output Signal] [D_ODPFOH_MeanStoredPntAge_sec](@ref ODPFOH_SenOutType::D_ODPFOH_MeanStoredPntAge_sec) \n
 *		[Output Signal] [S_ODPFOH_TgtObjCrvChng_1pm2](@ref ODPFOH_SenOutType::S_ODPFOH_TgtObjCrvChng_1pm2) \n\n
 *		For signal details, see sub-section [Globals](@ref ODPFOH_SenProcess_Globals) of the function @ref ODPFOH_SenProcess.
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
extern void ODPFOH_SenReset(void);

/*!
 *	ODPFOH module sensor process function.
 *	
 *	@pre
 *		- The ODPFOH sensor initialization function(s) must be called once.
 *		- The ODPFOH sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor ODPFOH_SenProcess_Globals
 *		[D_ODPFOH_AddNewSample_bool](@ref ODPFOH_SenDbgType::D_ODPFOH_AddNewSample_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_LastStoredPntAge_sec](@ref ODPFOH_SenDbgType::D_ODPFOH_LastStoredPntAge_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_LastStoredPntX_met](@ref ODPFOH_SenDbgType::D_ODPFOH_LastStoredPntX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_LastStoredPntY_met](@ref ODPFOH_SenDbgType::D_ODPFOH_LastStoredPntY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_MaxGapEgoToHist_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MaxGapEgoToHist_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_MeanDevToTraj_1st_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MeanDevToTraj_1st_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_MeanDevToTraj_3rd_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MeanDevToTraj_3rd_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_MinHistLength_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MinHistLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_MinHistStartPosX_met](@ref ODPFOH_SenDbgType::D_ODPFOH_MinHistStartPosX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_ODPFOH_NumValidSamples_nu](@ref ODPFOH_SenDbgType::D_ODPFOH_NumValidSamples_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_ODPFOH_AccObjTraceCrv_1pm](@ref ODPFOH_SenDbgType::S_ODPFOH_AccObjTraceCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		ACC trace curvature \n\n
 *		[S_ODPFOH_ObjTraceCrvQual_perc](@ref ODPFOH_SenDbgType::S_ODPFOH_ObjTraceCrvQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Trace curvature quality signal \n\n
 *		[S_ODPFOH_ObjTraceQual_perc](@ref ODPFOH_SenDbgType::S_ODPFOH_ObjTraceQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality signal of object trace trajectory (History Polyfit) \n\n
 *		[S_ODPFOH_ObjTraceStraight_perc](@ref ODPFOH_SenDbgType::S_ODPFOH_ObjTraceStraight_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Probability of a straight object trace trajectory (dominant 1st order History Polyfit) \n\n
 *		[S_ODPFOH_TgtObjClothoidInv_btf](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjClothoidInv_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		ODPFOH Invalid Bitfield: \n
 *		0: AccObjInvalidAsNewSample \n
 *		1: AccObjPosFreeze \n
 *		2: ObjValidTransitionOngoing \n
 *		3: CutInTransitionOngoing \n
 *		4: CutOutTransitionOngoing \n
 *		5: FreezeStopTransOngoing \n
 *		6: TrajNotUpdated \n
 *		7: TrajInvalid \n
 *		8: HistoryModeInactive (Polyfit) \n
 *		9: LowSpeedModeInactive \n
 *		10: LowSpeedModeTransitionOngoing \n
 *		11: TrajInvTransitionOngoing \n
 *		12: HistoryDisabled \n
 *		13: HistroyReset \n\n
 *		[S_ODPFOH_TgtObjCrv_1pm](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Target object curvature \n\n
 *		[S_ODPFOH_TgtObjHeadAng_rad](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjHeadAng_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Target object heading angle \n\n
 *		[S_ODPFOH_TgtObjLength_met](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Target object trajectory length \n\n
 *		[S_ODPFOH_TgtObjPosX0_met](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Target object position X0 \n\n
 *		[S_ODPFOH_TgtObjPosY0_met](@ref ODPFOH_SenDbgType::S_ODPFOH_TgtObjPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Target object position Y0 \n\n
 *		[D_ODPFOH_FirstStoredPntAge_sec](@ref ODPFOH_SenOutType::D_ODPFOH_FirstStoredPntAge_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		[D_ODPFOH_FirstStoredPntX_met](@ref ODPFOH_SenOutType::D_ODPFOH_FirstStoredPntX_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		[D_ODPFOH_MeanStoredPntAge_sec](@ref ODPFOH_SenOutType::D_ODPFOH_MeanStoredPntAge_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		[S_ODPFOH_TgtObjCrvChng_1pm2](@ref ODPFOH_SenOutType::S_ODPFOH_TgtObjCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Target object curvature change \n\n
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
 *		@ref S_ODPFOP_AccObjInvBitfield_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ODPFOP_AccObjPosXStdDev_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Standard deviation of PositionPosX__m. Negative if invalid. \n\n
 *		@ref S_ODPFOP_AccObjPosX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. \n\n
 *		@ref S_ODPFOP_AccObjPosYStdDev_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Standard deviation of PositionPosY__m. Negative if invalid. \n\n
 *		@ref S_ODPFOP_AccObjPosY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. \n\n
 *		@ref S_ODPFOP_AccObjRelVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). \n\n
 *		@ref S_ODPFOP_AccObjRelVelY_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. \n\n
 *		@ref S_ODPFOP_AccObjRelYawAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Relative Yaw angle between Object axis and Ego axis \n\n
 *		@ref S_ODPFOP_EstimatedObjPosX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Estimated X-Position based on current X-Position and longitudinal ego kinematics \n\n
 *		@ref S_ODPFOP_EstimatedObjPosY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Estimated Y-Position based on current Y-Position and lateral ego kinematics \n\n
 *		@ref S_TJAOBF_ObjInLaneValid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if target object validated to be driving within the ego lane \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_ODPFOH_AccObjChange_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for S_ODPFOP_AccObjInvBitfield_btf to observe ACC object changes \n\n
 *		@ref P_ODPFOH_AccObjCheckLane_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of TJAOBF object-lane-check for target object validation \n\n
 *		@ref P_ODPFOH_AccObjChngDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum transition time duration during ACC object change \n\n
 *		@ref P_ODPFOH_AccObjDtct_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for S_ODPFOP_AccObjInvBitfield_btf to check if a new ACC obj has been detected \n\n
 *		@ref P_ODPFOH_AccObjFreeze_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for S_ODPFOP_AccObjInvBitfield_btf to check if ACC obj position is frozen \n\n
 *		@ref P_ODPFOH_AccObjKfUpdate_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for check of Acc object validity for KF measurement update \n\n
 *		@ref P_ODPFOH_AccObjValidLSM_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for check of Acc object validity for Low Speed Mode \n\n
 *		@ref P_ODPFOH_CrvStdDev_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_EnableObjTraceKF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_EnableTransAtStart_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if transition handling is enabled at Kalman initialization \n\n
 *		@ref P_ODPFOH_FeatPtsMinPosXTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Minimum time to longitudinal position x (behind front axle) for history point to be valid \n\n
 *		@ref P_ODPFOH_FeatPtsMinPosX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum longitudinal position x (with respect to front axle) for history point to be valid \n\n
 *		@ref P_ODPFOH_HeadingAngStdDev_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_LowSpeedHystVel_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_250_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 250 \n
 *		\@description: \n
 *		Hysteresis for maximum Ego velocity for Low Speed Mode \n\n
 *		@ref P_ODPFOH_LowSpeedMaxVel_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_250_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 250 \n
 *		\@description: \n
 *		Below this maximum Ego velocity the Low Speed Mode is valid (incl. Hysteresis) \n\n
 *		@ref P_ODPFOH_MaxDeltaEgoCrvLSM_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum allowed curvature in LowSpeedMode between calculated and EgoCurvature \n\n
 *		@ref P_ODPFOH_MaxGradCrv_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_MaxGradHeadAng_rps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_MaxGradPosY0_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_MaxHistStartX0_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		 \n\n
 *		@ref P_ODPFOH_MaxObjDistHystLSM_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		Object hysteresis distance for Low Speed Mode \n\n
 *		@ref P_ODPFOH_MaxObjHistSampleD_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Maximum distance between new and old object history sample point \n\n
 *		@ref P_ODPFOH_MaxObjHistSampleT_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Maximum time for new object history sample \n\n
 *		@ref P_ODPFOH_MaxRangeCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_MaxRangeHead_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_MaxRangePosY0_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_MinHistLengthTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Minimum history length in seconds to be treated as valid \n\n
 *		@ref P_ODPFOH_MinHistLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum required history length for validity \n\n
 *		@ref P_ODPFOH_MinObjHistSampleD_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		Minimum distance between new and old object history sample point \n\n
 *		@ref P_ODPFOH_MinObjValidityTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum object validity time for starting measurement update \n\n
 *		@ref P_ODPFOH_MinPosXVelXOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE to switch on velocity dependent minimum long object position logic \n\n
 *		@ref P_ODPFOH_MinTrajValidTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum Trajectory validity time for switch to Object History Mode \n\n
 *		@ref P_ODPFOH_MinValidEntries_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_20_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum required valid history points \n\n
 *		@ref P_ODPFOH_MinVelForKF_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_NumObjDistHistParts_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Number of sections relatively to object x-distance \n\n
 *		@ref P_ODPFOH_ObjKFDecQualDegr_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDecQualPred_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDegrUpdGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDegrUpdWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDegrUpdateQu_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDegrUpdate_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDynCrvFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDynDistYFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFDynYawFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFIncrQual_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFInitRFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFKGainFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFMinInitQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKFMinUpdateQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKinMaxLatAccel_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKinMaxLatJerk_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ObjKinRefVel_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_PF_CrvChngDecay_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_PF_CrvDecay_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_PT1CrvEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if low pass filter for curvature is enabled \n\n
 *		@ref P_ODPFOH_PT1HeadEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if low pass filter for heading is enabled \n\n
 *		@ref P_ODPFOH_PT1PosY0Enable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE means low pass filter for lateral target position is enabled \n
 *		FALSE means low pass filter for lateral target position is disabled \n\n
 *		@ref P_ODPFOH_PT1PosYEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE means low pass filter for lateral position is enabled \n
 *		FALSE means low pass filter for lateral position is disabled \n\n
 *		@ref P_ODPFOH_PT1YawRateEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE means low pass filter for input yaw rate is enabled \n
 *		FALSE means low pass filter for input yaw rate is disabled \n\n
 *		@ref P_ODPFOH_PosY0StdDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_PredTimeMaxPosX0_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Maximum prediction (extrapolation) time from history X0 to ego vehicle front axle \n\n
 *		@ref P_ODPFOH_ScalingFactorCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ScalingFactorHead_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_ScalingFactorPosY0_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_SignLimMinObjPosY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_SignLimStrEstLSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_SignLimStrEstRSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_StrEstimMeanDevFac_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_StrEstimMeanDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_StrEstimNegGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_m1000_0_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: -1000 \n
 *		\@max: 0 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_StrEstimPT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_StrEstimPosGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseCrvOnlyLSM_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: only curvature is used for target trajectory (PosY0 and heading angle are set to 0) \n
 *		FALSE: PosY0 and heading angle are used, curvature is set to 0 \n\n
 *		@ref P_ODPFOH_UseEstimPosY_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseOutputGradLim_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseOutputRangeLim_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UsePosYReduction_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: input object y-position is squared if it is below a certain threshold \n
 *		FALSE: original object y-position is used \n\n
 *		@ref P_ODPFOH_UsePosYcorr_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseSignLimCrv_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseSignLimHead_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseSignLimPosY0_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseStrEstimGradLim_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseStrEstimLimit_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseStrEstimPT1_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_UseStraightEstim_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: own straight estimation calculation [%] will be used for weighting between 1st and 2nd order polyfit [0..1] \n
 *		FALSE: original Polyfit output is used \n\n
 *		@ref P_ODPFOH_VehYawRateStdDev_radps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_ODPFOH_YawRateDelayCycles_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_20_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_ODPFOH_StraightEstim_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		x-axis for straight estimation [%] / 100.0 --> [0..1] \n\n
 *		@ref X_ODPFOH_VehVelXPT1_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_250_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 250 \n
 *		\@description: \n
 *		Velocity axis for PT1 time constant speed dependent tuning \n\n
 *		@ref X_ODPFOH_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		x-axis for ego veh. vel. [mps] \n\n
 *		@ref Y_ODPFOH_LSMPT1TimePosY_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of speed dependent PT1 time constant values for lateral position in Low Speed Mode (not as Kalman Input) \n\n
 *		@ref Y_ODPFOH_MaxObjDistLSM_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lookup table to define speed dependent maximum object distance for Low Speed Mode \n\n
 *		@ref Y_ODPFOH_MaxSampleAge_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100_1em4_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximim age for a saved object data sample point to be treated as valid \n\n
 *		@ref Y_ODPFOH_MinTrajectoryLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lookup table to define speed dependent minimum trajectory length for Kalman Filter input \n\n
 *		@ref Y_ODPFOH_PT1StrEstCrv_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of straight estimation dependent PT1 time constant values for curvature \n\n
 *		@ref Y_ODPFOH_PT1StrEstHead_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of straight estimation dependent PT1 time constant values for curvature \n\n
 *		@ref Y_ODPFOH_PT1StrEstPosY0_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of straight estimation dependent PT1 time constant values for curvature \n\n
 *		@ref Y_ODPFOH_PT1TimeConstCrv_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of speed dependent PT1 time constant values for curvature \n\n
 *		@ref Y_ODPFOH_PT1TimeConstHead_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of speed dependent PT1 time constant values for heading \n\n
 *		@ref Y_ODPFOH_PT1TimeConstPosY0_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of speed dependent PT1 time constant values for lateral position \n\n
 *		@ref Y_ODPFOH_PT1TimeConstPosY_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of speed dependent PT1 time constant values for lateral position \n\n
 *		@ref Y_ODPFOH_PT1TimeConstYawRate_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lookup table of speed dependent PT1 time constant values for input yaw rate \n\n
 *		@ref Y_ODPFOH_WeightCrvPolyfit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x14x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Lookup table of speed dependent weighting factor for polyfit coefficients [0..1] \n\n
 *		@ref Y_ODPFOH_WeightLastPolyfit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Lookup table of speed dependent weighting factor with last polyfit [0..1] \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: ODPFOH Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/ODPR/ODPFOH_SEN/ODPFOH/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref ODPFOH_Testcase_Initialization) Initialization of the ODPFOH
 *		-# [Testcase_InvalidBitfield_ObjInvalid](@ref ODPFOH_Testcase_InvalidBitfield_ObjInvalid) Test invalid bitfield for ObjectInvalid btm
 *		-# [Testcase_InvalidBitfield_MinObjPosX](@ref ODPFOH_Testcase_InvalidBitfield_MinObjPosX) Test invalid bitfield for min. Object x-Position
 *		-# [Testcase_InvalidBitfield_CutIn](@ref ODPFOH_Testcase_InvalidBitfield_CutIn) Test invalid bitfield for Object Cut-In
 *		-# [Testcase_InvalidBitfield_CutOut](@ref ODPFOH_Testcase_InvalidBitfield_CutOut) Test invalid bitfield for Object Cut-Out
 *		-# [Testcase_InvalidBitfield_LowSpeedMode](@ref ODPFOH_Testcase_InvalidBitfield_LowSpeedMode) Test Low Speed Mode
 *		-# [Testcase_InvalidBitfield_NewSample](@ref ODPFOH_Testcase_InvalidBitfield_NewSample) Test ring-buffer fill-up
 *		-# [Testcase_GradientLimiter](@ref ODPFOH_Testcase_GradientLimiter) Test gradient limiter for Safety Req.
 *		-# [Testcase_RangeLimiter](@ref ODPFOH_Testcase_RangeLimiter) Test range limiter for Safety Req.
 *		-# [Testcase_PT1](@ref ODPFOH_Testcase_PT1) Test all PT1 filters for coverage
 *		-# [Testcase_UseSwitches](@ref ODPFOH_Testcase_UseSwitches) Test further bool switches for coverage
 *		-# [Testcase_ObjInLane](@ref ODPFOH_Testcase_ObjInLane) Test new input signal for coverage
 *		-# [Testcase_ZDV_Parameter](@ref ODPFOH_Testcase_ZDV_Parameter) Test ZDV protection for parameters for coverage
 *		-# [Testcase_PF_MaxAgeAndPoints](@ref ODPFOH_Testcase_PF_MaxAgeAndPoints) Test ZDV protection for parameters for coverage
 *		-# [Testcase_MinTrajValid](@ref ODPFOH_Testcase_MinTrajValid) Test conditions for Obj. History to become valid
 *		-# [Testcase_StraightEstimation](@ref ODPFOH_Testcase_StraightEstimation) Test straight estimation
 *		-# [Testcase_ModeTransition](@ref ODPFOH_Testcase_ModeTransition) Test Mode Transition
 *		
 *	@traceability
 *		[\@link: ODPFOH Module Requirements]()
 */
extern void ODPFOH_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* ODPFOH_H_*/
