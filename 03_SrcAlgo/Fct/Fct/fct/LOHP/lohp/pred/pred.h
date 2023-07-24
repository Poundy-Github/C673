/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC)

PACKAGENAME:               pred.h

DESCRIPTION:               Internal header file for PRED in LOHP

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             03.09.2018

VERSION:                   $Revision: 1.4 $

**************************************************************************** */

#ifndef PRED_H_INCLUDED
#define PRED_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   pred_h Pred_h
@ingroup    pred
@brief      PRED internal header file
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "lohp.h"

#if ( LOHP_CFG_PRED )

#include "pred_cfg.h"
#include "pred_par.h"
/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES 
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/*--- pred_curve.c ---*/
extern void PRED_v_ProcessCurve( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut );

/*--- pred_lib.c ---*/
extern float32 PRED_f_CalcCurvatureFromAngle( float32 f_Angle );
extern velocity_t PRED_t_CalcPredCurveVelo( float32 f_Curvature );
extern acceleration_t PRED_t_CalcDistBasedAccelReq( velocity_t s16_EgoSpeed, velocity_t s16_SetSpeed, float32 f_DistToCurve, float32 f_DesDecel );

/*--- pred_green.c ---*/
extern void PRED_v_ProcessGreen( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut );

/*--- pred_speedlimit.c ---*/
extern void PRED_v_ProcessSpeedlimit( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut );

/*--- pred_customfunctions.c ---*/
extern void PRED_v_PreProcessCustom( velocity_t s16_EgoSpeed, const SLATE_NAVI_OUTPUT_t * p_NaviInpData, PRED_StaticMem_t * p_PredData );
extern void PRED_v_ProcessCurveCustom( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut );
extern void PRED_v_ProcessGreenCustom( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut );
extern void PRED_v_ProcessSpeedlimitCustom( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut );

#ifdef __cplusplus
};
#endif

#endif /* ( LOHP_CFG_PRED ) */

/** @} end defgroup */

#endif /* PRED_H_INCLUDED */
