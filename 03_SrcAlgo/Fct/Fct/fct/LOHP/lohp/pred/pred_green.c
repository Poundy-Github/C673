/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC functions)

PACKAGENAME:               pred_green.c

DESCRIPTION:               This file contains functions concerning predictive curve control

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             09.01.2019

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   pred_green Pred_green
@ingroup    pred
@brief      Green functions for PRED module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "pred.h"

#if ( LOHP_CFG_PRED && PRED_ACT_GREEN_ACC )

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:    PRED_v_ProcessGreen                                                                      */ /*!

  @brief           Calculate Green ACC relevant calculations

  @description     Calculate Green ACC relevant calculations
  
  @startuml 
  Start
    Partition PRED_v_ProcessGreen {
      : Call customer specific Green calculations;
      : To be filled;
    }
  End
  @enduml

  @return          -

  @param[in]       velocity_t                 : s16_EgoSpeed                          [0x8000 ... 0x7FFF] m/s   (with factor Velocity_s)
  @param[in]       p_PredInpBuffer            : Pointer to PRED's Input Buffer        [PRED_BufferedInput_t as per pred_ext.h]
                      u8_NumUsedSeg           : Number of available buffered segments [0x00 ... 0xFF]
                      t_NaviSeg[]             : Buffered segment's data               [PRED_NaviSeg_t as per pred_ext.h]
  @param[in,out]   p_PredOut                  : Pointer to AACC PRED output           [PRED_Output_t as per pred_ext.h]
                      t_SegReq[]              : Navi segments' PRED control data      [PRED_SegReq_t as per pred_ext.h]
                      lv_CurveCtrlAct         : flag for curve control activation     [FALSE...TRUE]
                      u8_SegUsedForCtrl       : Segment number used for control       [0x00 ... 0xFF]
                      u16_TmrDataInv          : Navi Data invalidity timer            [0x0000 ... 0xFFFF] s     (with factor times_t)
                      s16_AccelReqUsedForCtrl : Arbitrated acceleration request       [0x8000 ... 0x7FFF] m/s2  (with factor Acceleration_s)
                      s16_SetSpeedUsedForCtrl : Arbitrated setspeed                   [0x8000 ... 0x7FFF] m/s   (with factor Velocity_s)
                      f_DistUsedForCtrl       : Distance to reach setspeed control    [0.f ... 1000000.f]
                      
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   @ref PRED_ACT_GREEN_ACC  \n
  
  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
void PRED_v_ProcessGreen( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut )
{
  /* Call customer specific Green ACC functions */
  PRED_v_ProcessGreenCustom( s16_EgoSpeed, p_PredInpBuffer, p_PredOut );
}

#endif  /* ( LOHP_CFG_PRED && PRED_ACT_GREEN_ACC ) */

/** @} end defgroup */
