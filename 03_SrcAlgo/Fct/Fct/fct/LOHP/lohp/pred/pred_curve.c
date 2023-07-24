/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC functions)

PACKAGENAME:               pred_curve.c

DESCRIPTION:               This file contains functions concerning predictive curve control

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             03.09.2018

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "pred.h"


#if ( LOHP_CFG_PRED && PRED_ACT_CURVE_CTRL )
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       pred_curve Pred_Curve
@ingroup        pred_curve
@brief          File containing all calculations related ego velocity control based on curves for ACC PRED module.
@{
*/
/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULE FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    PRED_v_ProcessCurve                                                                      */ /*!

  @brief           Cyclic call of customer specific calculations for Anticipatory ACC functions and features

  @description     Cyclic call of customer specific calculations for Anticipatory ACC functions and features
  
  @startuml 
  Start
    Partition PRED_v_ProcessCurve {
      : Calculate customer specific functions for predictive curve control;
      If ( Segment(s) available in local Buffer )then (yes)
        : Initialize arbitrated acceleration request for minimum selection;
        : Calculation of the end Curvature for the last segment \n K_end[seg] = K_begin[seg] + ( dK/ds[seg] * s[seg] );
        : Convert angles between segments into curvatures and add them to the actual segments' curvatures;
        : Calculate setspeeds for all upcoming available Navi segments based on segments' curvatures;
        : Calculate acceleration requests for all upcoming available Navi segments;
        : Search for the segment with the lowest acceleration request and set it as control relevant;
      Endif
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
                      f_DistUsedForCtrl       : Distance to reach setspeed control    [0.f ... 1000000.f] m
  

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   @ref PRED_ACT_CURVE_CTRL  \n

  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
void PRED_v_ProcessCurve
(  
   velocity_t s16_EgoSpeed
 , PRED_BufferedInput_t * p_PredInpBuffer
 , PRED_Output_t * p_PredOut
)
{
  /* Calculate customer specific functions for predictive curve control */
  PRED_v_ProcessCurveCustom( s16_EgoSpeed, p_PredInpBuffer, p_PredOut );

  /* Check if Data is available */
  /* 1 [-], 0 ... 0xFF */
  if ( p_PredInpBuffer->u8_NumUsedSeg > ( uint8 )0 )
  {
    /* Local variables */
    uint8 i;
    float32 f_EndCurvLastSeg;
    float32 f_CurvInclAngle;
    float32 f_DistToCurve = ( float32 )0;
    float32 f_EgoSpeed = ( float32 )s16_EgoSpeed / ( float32 )Velocity_s;
    
    /* Reset feature activation flag */
    p_PredOut->t_CrvCtrlOut.lv_FeatAct = FALSE;
    
    /* Initialize arbitrated acceleration request for minimum selection */
    /* 1e-3 [m/s�], 0x8000 ... 0x7FFF */
    p_PredOut->t_CrvCtrlOut.s16_AccelReq = ( acceleration_t )( AACC_MAX_ACCEL_REQ * ( float32 )Acceleration_s );

    /* The end Curvature for the last segment has to be calculated manually */
    /* K_end[seg] = K_begin[seg] + ( dK/ds[seg] * s[seg] ) */
    f_EndCurvLastSeg =
        /* K_begin[seg] */
        p_PredInpBuffer->t_NaviSeg[( p_PredInpBuffer->u8_NumUsedSeg - 1u )].f_Curvature
      + (  /* dK/ds[seg] */
            p_PredInpBuffer->t_NaviSeg[( p_PredInpBuffer->u8_NumUsedSeg - 1u )].f_CurvatureChange
            /* s[seg] */
          * p_PredInpBuffer->t_NaviSeg[( p_PredInpBuffer->u8_NumUsedSeg - 1u )].f_Length
        );    
    
    /* Calculate setspeeds for all upcoming available navi segments */
    for ( i = 0; i < p_PredInpBuffer->u8_NumUsedSeg; i++ )
    {
      /* Check for the last iteration */
      /* 1 [-], 0 ... 0xFF */
      if ( i < ( p_PredInpBuffer->u8_NumUsedSeg - 1u ))
      {
        /* Convert Angle to a Curvature */
        f_CurvInclAngle =
          PRED_f_CalcCurvatureFromAngle( p_PredInpBuffer->t_NaviSeg[( i + 1u )].f_AngleToPrevSeg );

        /* Add Curvature to previous calculated angle dependent curvature */
        f_CurvInclAngle += p_PredInpBuffer->t_NaviSeg[( i + 1u )].f_Curvature;
        
        /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
        p_PredOut->t_SegReq[i].s16_SetSpeedSeg =
          /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
          PRED_t_CalcPredCurveVelo( f_CurvInclAngle );
      } 
      else
      {
        /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
        p_PredOut->t_SegReq[i].s16_SetSpeedSeg =
          /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
          PRED_t_CalcPredCurveVelo( f_EndCurvLastSeg );
      }
      
      /* Calculate distance to the end of the active segment */
      f_DistToCurve += p_PredInpBuffer->t_NaviSeg[i].f_Length;
      
      /* 1e-3 [m/s�], 0x8000 ... 0x7FFF */
      p_PredOut->t_SegReq[i].s16_AccelReqSeg =
        /* 1e-3 [m/s�], 0x8000 ... 0x7FFF */
        PRED_t_CalcDistBasedAccelReq
        (  s16_EgoSpeed
         , p_PredOut->t_SegReq[i].s16_SetSpeedSeg
         , f_DistToCurve
         , Aacc_desired_decel
        );

      /* Search for the smallest acceleration request of all segments */
      if (   /* 1e-3 [m/s�], 0x8000 ... 0x7FFF */
             (  p_PredOut->t_SegReq[i].s16_AccelReqSeg < p_PredOut->t_CrvCtrlOut.s16_AccelReq )
          && (   ( f_DistToCurve > ( Aacc_min_dist_act_ctrl * f_EgoSpeed ))
                 /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
              || ( p_PredOut->t_CrvCtrlOut.s16_SetSpeed == p_PredOut->t_SegReq[i].s16_SetSpeedSeg )
             )
         )
      {
        /* Save acceleration request */
        /* 1e-3 [m/s�], 0x8000 ... 0x7FFF */
        p_PredOut->t_CrvCtrlOut.s16_AccelReq = p_PredOut->t_SegReq[i].s16_AccelReqSeg;
        
        /* Save corresponding setspeed */
        /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
        p_PredOut->t_CrvCtrlOut.s16_SetSpeed = p_PredOut->t_SegReq[i].s16_SetSpeedSeg;
        
        /* Save distance to corresponding curve */
        p_PredOut->t_CrvCtrlOut.f_Dist = f_DistToCurve;

        /* Save the segment used for control */
        p_PredOut->t_CrvCtrlOut.u8_CtrlSeg = i;

        /* Set feature activation flag */
        p_PredOut->t_CrvCtrlOut.lv_FeatAct = TRUE;
      }
      else
      {
        /* Check for the last iteration */
        if (   /* 1 [-], 0 ... 0xFF */
               ( i == ( p_PredInpBuffer->u8_NumUsedSeg - 1u ))
            && ( p_PredOut->t_CrvCtrlOut.lv_FeatAct == FALSE )
           )
        {
          /* Reset CrvCtrl output values */
          p_PredOut->t_CrvCtrlOut.s16_SetSpeed = ( velocity_t )0;
          p_PredOut->t_CrvCtrlOut.f_Dist = ( float32 )0;
          p_PredOut->t_CrvCtrlOut.u8_CtrlSeg = ( uint8 )255;
        }
      }
    }
  }
}


#endif  /* ( LOHP_CFG_PRED && PRED_ACT_CURVE_CTRL ) */

/** @} end defgroup */