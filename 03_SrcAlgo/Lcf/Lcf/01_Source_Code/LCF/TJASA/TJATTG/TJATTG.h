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
//! @file     TJATTG.h
//! @brief     (TJATTG) Module Header.

#ifndef TJATTG_H_
#define TJATTG_H_

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
 *	TJATTG module sensor initialization function. Function initializes TJATTG sensor debug data pointer.
 *	
 *	@param
 *		[in] TJATTG_SenDbgArg Pointer to TJATTG sensor debug data.
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
extern void TJATTG_SenInitDbgPtr(TJATTG_SenDbgType *TJATTG_SenDbgArg);

/*!
 *	TJATTG module sensor initialization function. Function initializes TJATTG sensor output data pointer.
 *	
 *	@param
 *		[in] TJATTG_SenOutArg Pointer to TJATTG sensor output data.
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
extern void TJATTG_SenInitOutPtr(TJATTG_SenOutType *TJATTG_SenOutArg);

/*!
 *	TJATTG module sensor reset function.
 *	
 *	@pre
 *		- The TJATTG sensor initialization function(s) must be called once.
 *		- The TJATTG sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TJATTG_TgtCorridorInvalid_btf](@ref TJATTG_SenDbgType::D_TJATTG_TgtCorridorInvalid_btf) \n
 *		[Debug  Signal] [S_TJATTG_TgtTrajCrvChng_1pm2](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajCrvChng_1pm2) \n
 *		[Debug  Signal] [S_TJATTG_TgtTrajCrv_1pm](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajCrv_1pm) \n
 *		[Debug  Signal] [S_TJATTG_TgtTrajHeadAng_rad](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajHeadAng_rad) \n
 *		[Debug  Signal] [S_TJATTG_TgtTrajLength_met](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajLength_met) \n
 *		[Debug  Signal] [S_TJATTG_TgtTrajPosX0_met](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajPosX0_met) \n
 *		[Debug  Signal] [S_TJATTG_TgtTrajPosY0_met](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajPosY0_met) \n
 *		[Output Signal] [S_TJATTG_LeCridrBndCrvChng_1pm2](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndCrvChng_1pm2) \n
 *		[Output Signal] [S_TJATTG_LeCridrBndCrv_1pm](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndCrv_1pm) \n
 *		[Output Signal] [S_TJATTG_LeCridrBndHeadAng_rad](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndHeadAng_rad) \n
 *		[Output Signal] [S_TJATTG_LeCridrBndLength_met](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndLength_met) \n
 *		[Output Signal] [S_TJATTG_LeCridrBndPosX0_met](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndPosX0_met) \n
 *		[Output Signal] [S_TJATTG_LeCridrBndPosY0_met](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndPosY0_met) \n
 *		[Output Signal] [S_TJATTG_PredictionEnable_bool](@ref TJATTG_SenOutType::S_TJATTG_PredictionEnable_bool) \n
 *		[Output Signal] [S_TJATTG_RiCridrBndCrvChng_1pm2](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndCrvChng_1pm2) \n
 *		[Output Signal] [S_TJATTG_RiCridrBndCrv_1pm](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndCrv_1pm) \n
 *		[Output Signal] [S_TJATTG_RiCridrBndHeadAng_rad](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndHeadAng_rad) \n
 *		[Output Signal] [S_TJATTG_RiCridrBndLength_met](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndLength_met) \n
 *		[Output Signal] [S_TJATTG_RiCridrBndPosX0_met](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndPosX0_met) \n
 *		[Output Signal] [S_TJATTG_RiCridrBndPosY0_met](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndPosY0_met) \n
 *		[Output Signal] [S_TJATTG_TransTriggerReplan_bool](@ref TJATTG_SenOutType::S_TJATTG_TransTriggerReplan_bool) \n\n
 *		For signal details, see sub-section [Globals](@ref TJATTG_SenProcess_Globals) of the function @ref TJATTG_SenProcess.
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
extern void TJATTG_SenReset(void);

/*!
 *	TJATTG module sensor process function.
 *	
 *	@pre
 *		- The TJATTG sensor initialization function(s) must be called once.
 *		- The TJATTG sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJATTG_SenProcess_Globals
 *		[D_TJATTG_TgtCorridorInvalid_btf](@ref TJATTG_SenDbgType::D_TJATTG_TgtCorridorInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJATTG Debug signal \n\n
 *		[S_TJATTG_TgtTrajCrvChng_1pm2](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_TgtTrajCrv_1pm](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_TgtTrajHeadAng_rad](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajHeadAng_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_TgtTrajLength_met](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_TgtTrajPosX0_met](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_TgtTrajPosY0_met](@ref TJATTG_SenDbgType::S_TJATTG_TgtTrajPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_LeCridrBndCrvChng_1pm2](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_LeCridrBndCrv_1pm](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_LeCridrBndHeadAng_rad](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_LeCridrBndLength_met](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_LeCridrBndPosX0_met](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_LeCridrBndPosY0_met](@ref TJATTG_SenOutType::S_TJATTG_LeCridrBndPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_PredictionEnable_bool](@ref TJATTG_SenOutType::S_TJATTG_PredictionEnable_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if module outputs are predicted \n\n
 *		[S_TJATTG_RiCridrBndCrvChng_1pm2](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_RiCridrBndCrv_1pm](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_RiCridrBndHeadAng_rad](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_RiCridrBndLength_met](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_RiCridrBndPosX0_met](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_RiCridrBndPosY0_met](@ref TJATTG_SenOutType::S_TJATTG_RiCridrBndPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		[S_TJATTG_TransTriggerReplan_bool](@ref TJATTG_SenOutType::S_TJATTG_TransTriggerReplan_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Flag to trigger TRJPLN replan during mode transition \n\n
 *		@ref S_ABPALP_LeAdjLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left adjacent lane clothoid curvature rate \n\n
 *		@ref S_ABPALP_LeAdjLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left adjacent lane clothoid curvature \n\n
 *		@ref S_ABPALP_LeAdjLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left adjacent lane clothoid heading angle \n\n
 *		@ref S_ABPALP_LeAdjLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left adjacent lane clothoid length \n\n
 *		@ref S_ABPALP_LeAdjLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left adjacent lane clothoid x_0 position \n\n
 *		@ref S_ABPALP_LeAdjLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left adjacent lane clothoid Y0 position (init +15m) \n\n
 *		@ref S_ABPALP_RiAdjLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right adjacent lane clothoid curvature rate \n\n
 *		@ref S_ABPALP_RiAdjLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right adjacent lane clothoid curvature \n\n
 *		@ref S_ABPALP_RiAdjLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right adjacent lane clothoid heading angle \n\n
 *		@ref S_ABPALP_RiAdjLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right adjacent lane clothoid length \n\n
 *		@ref S_ABPALP_RiAdjLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right adjacent lane clothoid x_0 position \n\n
 *		@ref S_ABPALP_RiAdjLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right adjacent lane clothoid Y0 position (init -15m) \n\n
 *		@ref S_ABPLBP_CntrLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Lane center clothoid curvature change \n\n
 *		@ref S_ABPLBP_CntrLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Lane center clothoid curvature \n\n
 *		@ref S_ABPLBP_CntrLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Lane center clothoid heading angle \n\n
 *		@ref S_ABPLBP_CntrLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lane center clothoid length \n\n
 *		@ref S_ABPLBP_CntrLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lane center clothoid X0-Position \n\n
 *		@ref S_ABPLBP_CntrLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lane center clothoid Y0 position \n\n
 *		@ref S_ABPLBP_LeLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left lane clothoid change of curvature \n\n
 *		@ref S_ABPLBP_LeLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left lane clothoid curvature \n\n
 *		@ref S_ABPLBP_LeLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left lane clothoid heading angle \n\n
 *		@ref S_ABPLBP_LeLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid length \n\n
 *		@ref S_ABPLBP_LeLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid X0 position \n\n
 *		@ref S_ABPLBP_LeLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (init +10m) \n\n
 *		@ref S_ABPLBP_RiLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right lane clothoid curvature change \n\n
 *		@ref S_ABPLBP_RiLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right lane clothoid curvature \n\n
 *		@ref S_ABPLBP_RiLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right lane clothoid heading angle \n\n
 *		@ref S_ABPLBP_RiLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid length \n\n
 *		@ref S_ABPLBP_RiLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid X0 position \n\n
 *		@ref S_ABPLBP_RiLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (init -10m) \n\n
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
 *		@ref S_ODPFOH_TgtObjCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Target object curvature change \n\n
 *		@ref S_ODPFOH_TgtObjCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Target object curvature \n\n
 *		@ref S_ODPFOH_TgtObjHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Target object heading angle \n\n
 *		@ref S_ODPFOH_TgtObjLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Target object trajectory length \n\n
 *		@ref S_ODPFOH_TgtObjPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Target object position X0 \n\n
 *		@ref S_ODPFOH_TgtObjPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Target object position Y0 \n\n
 *		@ref S_TJACMB_CombinedCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Combined Curvature Change \n\n
 *		@ref S_TJACMB_CombinedCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Combined Curvature \n\n
 *		@ref S_TJACMB_CombinedHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Combined Heading Angle \n\n
 *		@ref S_TJACMB_CombinedLePosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Combined Left PosY0 \n\n
 *		@ref S_TJACMB_CombinedLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Combined Trajectory Length \n\n
 *		@ref S_TJACMB_CombinedMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJACMB_CombModeType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Combined mode state \n\n
 *		@ref S_TJACMB_CombinedPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Combined PosX0 \n\n
 *		@ref S_TJACMB_CombinedPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Combined PosY0 \n\n
 *		@ref S_TJACMB_CombinedRiPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Combined Right PosY0 \n\n
 *		@ref S_TJALKA_LanePredictValid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates TRUE if both-sided lane prediction shall be enabled \n\n
 *		@ref S_TJASLC_LaneChangeTrig_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LnChngTriggerType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Indicates if and to which side lane change is triggered by driver \n\n
 *		@ref S_TJASLC_ManeuverState_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASLC_MnvStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		TJASLC_OUTPUT \n
 *		 \n
 *		Outputs the lane change maneuver state \n\n
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TJASTM_SysStateTJA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_TJALKA_RampoutPredictOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable rampout prediction (lane prediction while LatDMC output is set to zero) \n\n
 *		@ref P_TJATTG_EnableVirtAdjLane_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable virtual adjacent lane width for SALC \n\n
 *		@ref P_TJATTG_LnPredMinTrajLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Minimum trajectory length for lane prediction \n\n
 *		@ref P_TJATTG_NewPredEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable new prediction implementation \n\n
 *		@ref P_TJATTG_ObjFolVirtLnWdth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		TJATTG_APARAM \n\n
 *		@ref P_TJATTG_PredCrvChngPT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Curvature change PT1 time constant during prediction (if signal is set to zero) \n\n
 *		@ref P_TJATTG_PredCrvPT1_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Curvature PT1 time constant during prediction (if signal is set to zero) \n\n
 *		@ref P_TJATTG_PredFreezeCrvChng_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if curvature change signal shall be frozen during prediction \n\n
 *		@ref P_TJATTG_PredFreezeCrv_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if curvature signal shall be frozen during prediction \n\n
 *		@ref P_TJATTG_PredResetTrajLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Remaining saved trajectory length for prediction reset \n\n
 *		@ref P_TJATTG_TransDurationCMB_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Transition duration for mode switch to combined data \n\n
 *		@ref P_TJATTG_TransDurationLD_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Transition duration for mode switch to lane data \n\n
 *		@ref P_TJATTG_TransDurationOD_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Transition duration for mode switch to object data \n\n
 *		@ref P_TJATTG_TransDurationPredct_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Transition duration to switch from predicted lane data to new detected lane data \n\n
 *		@ref P_TJATTG_TransHandleEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable mode transition handling \n\n
 *		@ref P_TJATTG_TriggerReplanCMBLC2OF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable replan trigger during Kalman transition lane-based to object-based combined mode \n\n
 *		@ref P_TJATTG_VirtAdjLaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Virtual adjacent lane width \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJATTG Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJATTG_SEN/TJATTG/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJATTG_Testcase_Initialization) Check outputs during initialization
 *		-# [Testcase_TJA_Passive](@ref TJATTG_Testcase_TJA_Passive) Check outputs during passive state
 *		-# [Testcase_TJA_LaneCenteringRequest](@ref TJATTG_Testcase_TJA_LaneCenteringRequest) Check outputs during TJA lane centering request
 *		-# [Testcase_TJA_LaneCenteringControlling](@ref TJATTG_Testcase_TJA_LaneCenteringControlling) Check outputs during TJA lane centering controlling
 *		-# [Testcase_TJA_LaneCenteringRampout](@ref TJATTG_Testcase_TJA_LaneCenteringRampout) Check outputs during TJA lane centering rampout
 *		-# [Testcase_TJA_ObjectFollowingRequest](@ref TJATTG_Testcase_TJA_ObjectFollowingRequest) Check outputs during TJA object following request
 *		-# [Testcase_TJA_ObjectFollowingControlling](@ref TJATTG_Testcase_TJA_ObjectFollowingControlling) Check outputs during TJA object following controlling
 *		-# [Testcase_TJA_ObjectFollowingRampout](@ref TJATTG_Testcase_TJA_ObjectFollowingRampout) Check outputs during TJA object following rampout
 *		-# [Testcase_TJA_CombinedRequest](@ref TJATTG_Testcase_TJA_CombinedRequest) Check outputs during TJA combined mode request
 *		-# [Testcase_TJA_CombinedControlling](@ref TJATTG_Testcase_TJA_CombinedControlling) Check outputs during TJA combined mode controlling
 *		-# [Testcase_TJA_CombinedRampout](@ref TJATTG_Testcase_TJA_CombinedRampout) Check outputs during TJA combined mode rampout
 *		-# [Testcase_TJA_LaneChangeLeft](@ref TJATTG_Testcase_TJA_LaneChangeLeft) Check outputs during TJA lane change left
 *		-# [Testcase_TJA_LaneChangeLeftVirtual](@ref TJATTG_Testcase_TJA_LaneChangeLeftVirtual) Check outputs during TJA lane change left with virtual adjacent lane
 *		-# [Testcase_TJA_LaneChangeRight](@ref TJATTG_Testcase_TJA_LaneChangeRight) Check outputs during TJA lane change to right side
 *		-# [Testcase_TJA_LaneChangeRightVirtual](@ref TJATTG_Testcase_TJA_LaneChangeRightVirtual) Check outputs during TJA lane change to right side with virtual adjacent lane
 *		-# [Testcase_TJA_ModeTransOD2LD](@ref TJATTG_Testcase_TJA_ModeTransOD2LD) Check outputs during TJA mode transition
 *		-# [Testcase_TJA_ModeTransCMB2OD](@ref TJATTG_Testcase_TJA_ModeTransCMB2OD) Check outputs during TJA mode transition
 *		-# [Testcase_TJA_ModeTransLD2OD](@ref TJATTG_Testcase_TJA_ModeTransLD2OD) Check outputs during TJA mode transition
 *		-# [Testcase_TJA_ModeTransLD2CMB](@ref TJATTG_Testcase_TJA_ModeTransLD2CMB) Check outputs during TJA mode transition
 *		-# [Testcase_TJA_ModeTransOD2CMB](@ref TJATTG_Testcase_TJA_ModeTransOD2CMB) Check outputs during TJA mode transition
 *		-# [Testcase_TJA_ModeTransCMB2LD](@ref TJATTG_Testcase_TJA_ModeTransCMB2LD) Check outputs during TJA mode transition
 *		-# [Testcase_TJA_LC_PredictionCrvZero](@ref TJATTG_Testcase_TJA_LC_PredictionCrvZero) Check outputs during TJA lane centering controlling
 *		-# [Testcase_TJA_LC_PredictionCrvFreeze](@ref TJATTG_Testcase_TJA_LC_PredictionCrvFreeze) Check outputs during TJA lane centering controlling
 *		-# [Testcase_TJA_LC_PredictionCntrPosYNegative](@ref TJATTG_Testcase_TJA_LC_PredictionCntrPosYNegative) Check outputs during TJA lane centering controlling
 *		
 *	@traceability
 *		[\@link: TJATTG Module Requirements]()
 */
extern void TJATTG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TJATTG_H_
