/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRTTG.h
//! @brief     (DPRTTG) Module Header.

#ifndef DPRTTG_H_
#define DPRTTG_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "DPRTTG_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DPRTTG module sensor initialization function. Function initializes DPRTTG sensor debug data pointer.
 *	
 *	@param
 *		[in] DPRTTG_SenDbgArg Pointer to DPRTTG sensor debug data.
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
extern void DPRTTG_SenInitDbgPtr(DPRTTG_SenDbgType *DPRTTG_SenDbgArg);

/*!
 *	DPRTTG module sensor initialization function. Function initializes DPRTTG sensor output data pointer.
 *	
 *	@param
 *		[in] DPRTTG_SenOutArg Pointer to DPRTTG sensor output data.
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
extern void DPRTTG_SenInitOutPtr(DPRTTG_SenOutType *DPRTTG_SenOutArg);

/*!
 *	DPRTTG module sensor reset function.
 *	
 *	@pre
 *		- The DPRTTG sensor initialization function(s) must be called once.
 *		- The DPRTTG sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_DPRTTG_LeTgtTrajPosY0_met](@ref DPRTTG_SenDbgType::S_DPRTTG_LeTgtTrajPosY0_met) \n
 *		[Debug  Signal] [S_DPRTTG_RiTgtTrajPosY0_met](@ref DPRTTG_SenDbgType::S_DPRTTG_RiTgtTrajPosY0_met) \n
 *		[Output Signal] [S_DPRTTG_LeCridrBndCrvChng_1pm2](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndCrvChng_1pm2) \n
 *		[Output Signal] [S_DPRTTG_LeCridrBndCrv_1pm](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndCrv_1pm) \n
 *		[Output Signal] [S_DPRTTG_LeCridrBndHeadAng_rad](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndHeadAng_rad) \n
 *		[Output Signal] [S_DPRTTG_LeCridrBndLength_met](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndLength_met) \n
 *		[Output Signal] [S_DPRTTG_LeCridrBndPosX0_met](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndPosX0_met) \n
 *		[Output Signal] [S_DPRTTG_LeCridrBndPosY0_met](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndPosY0_met) \n
 *		[Output Signal] [S_DPRTTG_RiCridrBndCrvChng_1pm2](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndCrvChng_1pm2) \n
 *		[Output Signal] [S_DPRTTG_RiCridrBndCrv_1pm](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndCrv_1pm) \n
 *		[Output Signal] [S_DPRTTG_RiCridrBndHeadAng_rad](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndHeadAng_rad) \n
 *		[Output Signal] [S_DPRTTG_RiCridrBndLength_met](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndLength_met) \n
 *		[Output Signal] [S_DPRTTG_RiCridrBndPosX0_met](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndPosX0_met) \n
 *		[Output Signal] [S_DPRTTG_RiCridrBndPosY0_met](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndPosY0_met) \n
 *		[Output Signal] [S_DPRTTG_TgtTrajCrvChng_1pm2](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajCrvChng_1pm2) \n
 *		[Output Signal] [S_DPRTTG_TgtTrajCrv_1pm](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajCrv_1pm) \n
 *		[Output Signal] [S_DPRTTG_TgtTrajHeadAng_rad](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajHeadAng_rad) \n
 *		[Output Signal] [S_DPRTTG_TgtTrajLength_met](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajLength_met) \n
 *		[Output Signal] [S_DPRTTG_TgtTrajPosX0_met](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajPosX0_met) \n
 *		[Output Signal] [S_DPRTTG_TgtTrajPosY0_met](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajPosY0_met) \n\n
 *		For signal details, see sub-section [Globals](@ref DPRTTG_SenProcess_Globals) of the function @ref DPRTTG_SenProcess.
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
extern void DPRTTG_SenReset(void);

/*!
 *	DPRTTG module sensor process function.
 *	
 *	@pre
 *		- The DPRTTG sensor initialization function(s) must be called once.
 *		- The DPRTTG sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPRTTG_SenProcess_Globals
 *		[S_DPRTTG_LeTgtTrajPosY0_met](@ref DPRTTG_SenDbgType::S_DPRTTG_LeTgtTrajPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiTgtTrajPosY0_met](@ref DPRTTG_SenDbgType::S_DPRTTG_RiTgtTrajPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_LeCridrBndCrvChng_1pm2](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_LeCridrBndCrv_1pm](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_LeCridrBndHeadAng_rad](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_LeCridrBndLength_met](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_LeCridrBndPosX0_met](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_LeCridrBndPosY0_met](@ref DPRTTG_SenOutType::S_DPRTTG_LeCridrBndPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiCridrBndCrvChng_1pm2](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiCridrBndCrv_1pm](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiCridrBndHeadAng_rad](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiCridrBndLength_met](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiCridrBndPosX0_met](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_RiCridrBndPosY0_met](@ref DPRTTG_SenOutType::S_DPRTTG_RiCridrBndPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_TgtTrajCrvChng_1pm2](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_TgtTrajCrv_1pm](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_TgtTrajHeadAng_rad](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_TgtTrajLength_met](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_TgtTrajPosX0_met](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_DPRTTG_TgtTrajPosY0_met](@ref DPRTTG_SenOutType::S_DPRTTG_TgtTrajPosY0_met) \n
 *		\@kind: Output Signal \n
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
 *		@ref S_ABPREP_LeReClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left road edge clothoid curvature rate \n\n
 *		@ref S_ABPREP_LeReClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left road edge clothoid curvature \n\n
 *		@ref S_ABPREP_LeReClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left road edge clothoid X0 coordinate \n\n
 *		@ref S_ABPREP_LeReHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left road edge clothoid yaw angle \n\n
 *		@ref S_ABPREP_LeReLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left road edge clothoid length (lookahead distance) \n\n
 *		@ref S_ABPREP_LeRePosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left road edge clothoid lateral distance (Y0 position) \n\n
 *		@ref S_ABPREP_RiReClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right road edge clothoid curvature rate \n\n
 *		@ref S_ABPREP_RiReClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right road edge clothoid curvature \n\n
 *		@ref S_ABPREP_RiReClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right road edge clothoid X0 coordinate \n\n
 *		@ref S_ABPREP_RiReHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right road edge clothoid yaw angle \n\n
 *		@ref S_ABPREP_RiReLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right road edge clothoid length (lookahead distance) \n\n
 *		@ref S_ABPREP_RiRePosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right road edge clothoid lateral distance (Pos Y0) \n\n
 *		@ref S_DPRSIA_LaneWidthRDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across RDP. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref S_DPRSIA_TgtCntrLnEnable_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
 *		@ref S_DPRSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_DPRSMI_SysStateRDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the RDP function. \n\n
 *		@ref S_DPRSMI_TriggerReason_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Trigger Reason of the RDP function. \n\n
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
 *		@ref P_DPRTTG_TargetLatDistLn_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Target when a lane marking is available next to the road edge. \n\n
 *		@ref P_DPRTTG_TargetLatDistRe_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Target when no lane marking is available next to the road edge. \n\n
 *		@ref P_DPRTTG_TargetTrajPT1Active_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRTTG_TgtCntrLnEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that enables the target in the center of the lane. \n\n
 *		@ref P_DPRTTG_TgtCntrRdEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If there is a road edge in the dangerous side and a lane marking in the opposite side, this parameter enables the target to be placed in the center of them both. \n\n
 *		@ref P_DPRTTG_TgtMaxDistanceLn_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the hazardous lane marking and the planned target. \n\n
 *		@ref P_DPRTTG_TgtMaxDistanceRe_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the hazardous road edge and the planned target. \n\n
 *		@ref P_DPRTTG_TgtMaxLatDevLn_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the middle of the vehicle and the planned target for a road edge + lane marking situation. \n\n
 *		@ref P_DPRTTG_TgtMaxLatDevRe_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the middle of the vehicle and the planned target for a road edge only situation. \n\n
 *		@ref P_DPRTTG_TgtTrjPT1TimeConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time constant for the PT1 output filter \n\n
 *		@ref P_VEH_Width_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPRTTG Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPRTTG_Testcase_Initialization) Initialization of the DPRTTG
 *		-# [Testcase_Road_Edge_Only](@ref DPRTTG_Testcase_Road_Edge_Only) Road Edge Only
 *		-# [Testcase_Road_Edge_Lane_Contiguous](@ref DPRTTG_Testcase_Road_Edge_Lane_Contiguous) Road Edge Lane Contiguous
 *		-# [Testcase_Road_Edge_Lane_Opposite](@ref DPRTTG_Testcase_Road_Edge_Lane_Opposite) Road Edge Lane Opposite
 *		-# [Testcase_Road_Edge_Both_Lanes](@ref DPRTTG_Testcase_Road_Edge_Both_Lanes) Road Edge Both Lane Markings
 *		-# [Testcase_Target_Center_Filtered](@ref DPRTTG_Testcase_Target_Center_Filtered) Testcase_Target_Center_Filtered
 *		
 *	@traceability
 *		[\@link: DPRTTG Module Requirements]()
 */
extern void DPRTTG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPRTTG_H_
