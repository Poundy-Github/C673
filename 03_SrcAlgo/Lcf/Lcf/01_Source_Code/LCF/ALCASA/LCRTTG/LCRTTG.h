/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRTTG.h
//! @brief     (LCRTTG) Module Header.

#ifndef LCRTTG_H_
#define LCRTTG_H_

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
 *	LCRTTG module sensor initialization function. Function initializes LCRTTG sensor debug data pointer.
 *	
 *	@param
 *		[in] LCRTTG_SenDbgArg Pointer to LCRTTG sensor debug data.
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
extern void LCRTTG_SenInitDbgPtr(LCRTTG_SenDbgType *LCRTTG_SenDbgArg);

/*!
 *	LCRTTG module sensor reset function.
 *	
 *	@pre
 *		- The LCRTTG sensor initialization function(s) must be called once.
 *		- The LCRTTG sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_LCRTTG_LeCridrBndCrvChng_1pm2](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndCrvChng_1pm2) \n
 *		[Debug  Signal] [S_LCRTTG_LeCridrBndCrv_1pm](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndCrv_1pm) \n
 *		[Debug  Signal] [S_LCRTTG_LeCridrBndHeadAng_rad](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndHeadAng_rad) \n
 *		[Debug  Signal] [S_LCRTTG_LeCridrBndLength_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndLength_met) \n
 *		[Debug  Signal] [S_LCRTTG_LeCridrBndPosX0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndPosX0_met) \n
 *		[Debug  Signal] [S_LCRTTG_LeCridrBndPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndPosY0_met) \n
 *		[Debug  Signal] [S_LCRTTG_LeTgtTrajPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeTgtTrajPosY0_met) \n
 *		[Debug  Signal] [S_LCRTTG_RiCridrBndCrvChng_1pm2](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndCrvChng_1pm2) \n
 *		[Debug  Signal] [S_LCRTTG_RiCridrBndCrv_1pm](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndCrv_1pm) \n
 *		[Debug  Signal] [S_LCRTTG_RiCridrBndHeadAng_rad](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndHeadAng_rad) \n
 *		[Debug  Signal] [S_LCRTTG_RiCridrBndLength_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndLength_met) \n
 *		[Debug  Signal] [S_LCRTTG_RiCridrBndPosX0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndPosX0_met) \n
 *		[Debug  Signal] [S_LCRTTG_RiCridrBndPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndPosY0_met) \n
 *		[Debug  Signal] [S_LCRTTG_RiTgtTrajPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiTgtTrajPosY0_met) \n
 *		[Debug  Signal] [S_LCRTTG_TgtTrajCrvChng_1pm2](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajCrvChng_1pm2) \n
 *		[Debug  Signal] [S_LCRTTG_TgtTrajCrv_1pm](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajCrv_1pm) \n
 *		[Debug  Signal] [S_LCRTTG_TgtTrajHeadAng_rad](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajHeadAng_rad) \n
 *		[Debug  Signal] [S_LCRTTG_TgtTrajLength_met](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajLength_met) \n
 *		[Debug  Signal] [S_LCRTTG_TgtTrajPosX0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajPosX0_met) \n
 *		[Debug  Signal] [S_LCRTTG_TgtTrajPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajPosY0_met) \n\n
 *		For signal details, see sub-section [Globals](@ref LCRTTG_SenProcess_Globals) of the function @ref LCRTTG_SenProcess.
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
extern void LCRTTG_SenReset(void);

/*!
 *	LCRTTG module sensor process function.
 *	
 *	@pre
 *		- The LCRTTG sensor initialization function(s) must be called once.
 *		- The LCRTTG sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor LCRTTG_SenProcess_Globals
 *		[S_LCRTTG_LeCridrBndCrvChng_1pm2](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_LeCridrBndCrv_1pm](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_LeCridrBndHeadAng_rad](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndHeadAng_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_LeCridrBndLength_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_LeCridrBndPosX0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_LeCridrBndPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeCridrBndPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_LeTgtTrajPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_LeTgtTrajPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiCridrBndCrvChng_1pm2](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiCridrBndCrv_1pm](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiCridrBndHeadAng_rad](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndHeadAng_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiCridrBndLength_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiCridrBndPosX0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiCridrBndPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiCridrBndPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_RiTgtTrajPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_RiTgtTrajPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_TgtTrajCrvChng_1pm2](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_TgtTrajCrv_1pm](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_TgtTrajHeadAng_rad](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajHeadAng_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_TgtTrajLength_met](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_TgtTrajPosX0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTTG_TgtTrajPosY0_met](@ref LCRTTG_SenDbgType::S_LCRTTG_TgtTrajPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
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
 *		@ref S_LCRSIA_CurveTypeLe_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_LCRSIA_CurveTypeRi_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_LCRSIA_LaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across ALCA. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref S_LCRSIA_TgtCntrLnEnable_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
 *		@ref S_LCRSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRSMI_SysStateALCA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTTG_TargetTrajPT1Active_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTTG_TgtCntrLnEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTTG_TgtMaxDistance_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTTG_TgtMaxLatDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTTG_TgtTrjPT1TimeConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_VEH_Width_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_LCF_Curvature_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		X-axis for all the curvature dependant parameters. \n\n
 *		@ref X_LCF_LaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_LCRTTG_CrvICTgtOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_LCRTTG_CrvOCTgtOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_LCRTTG_LWTargetLatDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		 \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: LCRTTG Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref LCRTTG_Testcase_Initialization) Initialization of the LCRTTG
 *		-# [Testcase1](@ref LCRTTG_Testcase1) 
 *		-# [Testcase2](@ref LCRTTG_Testcase2) 
 *		-# [Testcase3](@ref LCRTTG_Testcase3) 
 *		-# [Testcase_new](@ref LCRTTG_Testcase_new) 
 *		-# [Testcase_updated](@ref LCRTTG_Testcase_updated) 
 *		
 *	@traceability
 *		[\@link: LCRTTG Module Requirements]()
 */
extern void LCRTTG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // LCRTTG_H_
