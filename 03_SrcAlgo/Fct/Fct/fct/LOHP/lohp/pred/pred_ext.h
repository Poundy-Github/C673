/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC)

PACKAGENAME:               pred.h

DESCRIPTION:               Internal header file for PRED in LOHP

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             03.09.2018

VERSION:                   $Revision: 1.5 $

**************************************************************************** */

#ifndef PRED_EXT_H
#define PRED_EXT_H


/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
   @defgroup pred (Predictive ACC)
@ingroup    lohp_base_lohp
@brief      Module for PRED functionalities
@description
In this context PRED in LoHP is responsible for:\n
   - Calculation of setspeeds depending on Navi system information like curves and roundabouts.\n
   - Calculation of Energy efficient longitudinal acceleration control strategies (Green ACC).\n
   - Calculation of an acceleration request in order to reach desired Setspeed at desired distance.\n
 */

/** 
@defgroup   pred_ext Pred_ext_h
@ingroup pred
@brief      HP external header file
@{ */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lohp_ext.h"
#include "pred_cfg.h"

#if ( LOHP_CFG_PRED )

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/
/* Definition of the required MTS alignment, added to unions to assure that */
/* the alignment requirements are met */
#define MTS_ALIGNMENT_DUMMY     uint32 MTS_DUMMY; // PRQA S 3412
/* date: 2015-09-16, reviewer: Chirag, reason: Not safety critical */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*! @brief operating modes of sub-component */
typedef enum
{
  PRED_INIT,          /*!< initialize all */
  PRED_OK             /*!< normal processing */
}
PRED_t_State;

/*! Curve Control information for 1 Navi segment */
typedef struct
{
  acceleration_t  s16_AccelReqSeg;
  velocity_t      s16_SetSpeedSeg;
}
PRED_SegReq_t;

/*! Slope Attribute for 1 Navi Segment */
typedef struct
{
  float32  f_Slope;
  float32  f_OffsDist;
}
PRED_SegSlope_t;

/*! Speedlimit inside 1 Navi Segment */
typedef struct
{
  velocity_t s16_SpeedLimit;
  float32  f_OffsDist;
}
PRED_SegSpdLim_t;

/*! All feature dependent Control output values in PRED subcomponent */
typedef struct
{
  acceleration_t  s16_AccelReq;
  velocity_t      s16_SetSpeed;
  float32         f_Dist;
  uint8           u8_CtrlSeg;
  boolean         lv_FeatAct;
}
PRED_FeatCtrlOut_t;

/*! Input Signals provided by SLATE component before processing */
typedef struct
{
  float32 f_Curvature;
  float32 f_CurvatureChange;
  float32 f_AngleToPrevSeg;
  float32 f_Length;
  PRED_SegSlope_t t_Slope;
  PRED_SegSpdLim_t t_SpeedLimit;
}
PRED_NaviSeg_t;

/*! Input Signals provided by SLATE component before processing */
typedef struct
{
  uint8 u8_NumUsedSeg;
  PRED_NaviSeg_t t_NaviSeg[PRED_NUM_USED_NAVI_SEG];
}
PRED_BufferedInput_t;

/*! Output Ports provided by PRED component after processing */
typedef struct
{
  PRED_SegReq_t       t_SegReq[PRED_NUM_USED_NAVI_SEG];
  PRED_FeatCtrlOut_t  t_CrvCtrlOut;
  PRED_FeatCtrlOut_t  t_SpdLimOut;
  PRED_FeatCtrlOut_t  t_GreenOut;
  boolean             lv_PredCtrlAct;
  uint8               u8_SegUsedForCtrl;
  times_t             u16_TmrDataInv;
  acceleration_t      s16_AccelReqUsedForCtrl;
  velocity_t          s16_SetSpeedUsedForCtrl;
  float32             f_DistUsedForCtrl;
}
PRED_Output_t;

/*! Output Ports provided by PRED component after processing */
typedef struct
{
  PRED_BufferedInput_t  t_PredBufferedInput;
  PRED_Output_t         t_PredOutput;
}
PRED_StaticMem_t;

typedef union
{
  PRED_StaticMem_t        PRED_StaticMemory;       /*!< AACC Curve control output signals */
  MTS_ALIGNMENT_DUMMY                                       /*!< Needed to align the data to the MTS requirement */
} PRED_StaticMemUnion_u_t;

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
extern MEMSEC_REF PRED_t_State PRED_State;

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*  pred_main.c  */
extern void PRED_v_Init( PRED_StaticMem_t * p_PredData );
extern void PRED_v_PreProcess( velocity_t s16_EgoSpeed, const SLATE_NAVI_OUTPUT_t * p_NaviInpData, PRED_StaticMem_t * p_PredData );
extern void PRED_v_Process( velocity_t s16_EgoSpeed, PRED_StaticMem_t * p_PredData, acc_output_data_t * p_AccOutputData );

#endif  /* ( LOHP_CFG_PRED ) */

/** @} end defgroup */

#endif  /* PRED_EXT_H */


