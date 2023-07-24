/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC functions)

PACKAGENAME:               pred_speedlimit.c

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
@defgroup   pred_speedlimit Pred_speedlimit
@ingroup    pred
@brief      Speedlimit functions for PRED module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "pred.h"

#if( LOHP_CFG_PRED && PRED_ACT_SPEED_LIM_CTRL )

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    PRED_v_ProcessSpeedlimit                                                                      */ /*!

  @brief           Execute all Speedlimit relevant calculations

  @description     Execute all Speedlimit relevant calculations
  
  @startuml 
  Start
    Partition PRED_v_ProcessSpeedlimit {
      : Call customer specific Speedlimit calculations;
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
  @c_switch_full   @ref PRED_ACT_SPEED_LIM_CTRL  \n
  
  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
void PRED_v_ProcessSpeedlimit( velocity_t s16_EgoSpeed, PRED_BufferedInput_t * p_PredInpBuffer, PRED_Output_t * p_PredOut )
{
  /* Call customer specific Green ACC functions */
  PRED_v_ProcessSpeedlimitCustom( s16_EgoSpeed, p_PredInpBuffer, p_PredOut );

  /* Check if Data is available */
  /* 1 [-], 0 ... 0xFF */
  if ( p_PredInpBuffer->u8_NumUsedSeg > ( uint8 )0 )
  {
    /* Local variables */
    uint8 i;
    float32 f_DistToSpdLim = ( float32 )0;
    float32 f_EgoSpeed = ( float32 )s16_EgoSpeed / ( float32 )Velocity_s;
    acceleration_t s16_AccelReqSpdLim;
    
    /* Reset feature activation flag */
    p_PredOut->t_SpdLimOut.lv_FeatAct = FALSE;
    
    /* Set Accel Req Output to max value */
    /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
    p_PredOut->t_SpdLimOut.s16_AccelReq = ( acceleration_t )( AACC_MAX_ACCEL_REQ * ( float32 )Acceleration_s );

    /* Check if Speed Limit is present in Navi segments and calculate its acceleration request */
    for ( i = 0; i < p_PredInpBuffer->u8_NumUsedSeg; i++ )
    {
      /* Check if speed limit is available for current segment */
      if (   ( p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.s16_SpeedLimit > ( velocity_t )0 )
          && ( p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.f_OffsDist     > ( float32 )0 )
         )
      {
        /* Calculate distance to speed limit distance point */
        f_DistToSpdLim += p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.f_OffsDist;

        /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
        s16_AccelReqSpdLim =
          /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
          PRED_t_CalcDistBasedAccelReq
          (  s16_EgoSpeed
           , p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.s16_SpeedLimit
           , f_DistToSpdLim
           , Aacc_desired_decel
          );

        /* Check if acceleration request is smaller than current request calculated previously */
        if (   /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
               ( s16_AccelReqSpdLim <= Aacc_desired_decel )
            && (   ( f_DistToSpdLim > ( Aacc_min_dist_act_ctrl * f_EgoSpeed ))
                   /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
                || (   p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.s16_SpeedLimit
                    == p_PredOut->t_SpdLimOut.s16_SetSpeed
                   )
               )
           )
        {
          /* Save acceleration request */
          /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
          p_PredOut->t_SpdLimOut.s16_AccelReq = s16_AccelReqSpdLim;

          /* Save corresponding setspeed */
          /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
          p_PredOut->t_SpdLimOut.s16_SetSpeed = p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.s16_SpeedLimit;

          /* Save distance to corresponding curve */
          p_PredOut->t_SpdLimOut.f_Dist = f_DistToSpdLim;

          /* Save the segment used for control */
          p_PredOut->t_SpdLimOut.u8_CtrlSeg = i;

          /* Set feature activation flag */
          p_PredOut->t_SpdLimOut.lv_FeatAct = TRUE;
        }
        else
        {
          /* Reset SpdLim output values */
          p_PredOut->t_SpdLimOut.s16_SetSpeed = ( velocity_t )0;
          p_PredOut->t_SpdLimOut.f_Dist = ( float32 )0;
          p_PredOut->t_SpdLimOut.u8_CtrlSeg = ( uint8 )255;
        }

        /* Stop execution of for loop */
        break;
      }
      else
      {
        /* Add complete segment's length */
        f_DistToSpdLim += p_PredInpBuffer->t_NaviSeg[i].f_Length;

        /* Check for last iteration */
        /* 1 [-], 0 ... 0xFF */
        if ( i == ( p_PredInpBuffer->u8_NumUsedSeg - 1u ))
        {
          /* Reset SpdLim output values */
          p_PredOut->t_SpdLimOut.s16_SetSpeed = ( velocity_t )0;
          p_PredOut->t_SpdLimOut.f_Dist = ( float32 )0;
          p_PredOut->t_SpdLimOut.u8_CtrlSeg = ( uint8 )255;
        }
      }
    }
  }
}

#endif  /* ( LOHP_CFG_PRED && PRED_ACT_SPEED_LIM_CTRL ) */

/** @} end defgroup */
