/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC functions)

PACKAGENAME:               pred_lib.c

DESCRIPTION:               This file contains library functions concerning anticipatory ACC

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             23.01.2019

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "pred.h"


#if ( LOHP_CFG_PRED )
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       pred_lib Pred_Lib
@ingroup        pred_lib
@brief          File containing calculations for general use in ACC PRED module.
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
  Functionname:    PRED_f_CalcCurvatureFromAngle                                                                      */ /*!

  @brief           Convert an angle into a curvature

  @description     Convert an angle into a curvature based on an interpolation table
  
  @startuml 
  Start
    Partition PRED_f_CalcCurvatureFromAngle {
      : Convert angle to a radius using an interpolation table;
      : Convert radius to curvature;
      : Return curvature;
    }
  End
  @enduml

  @return          float32 : segment's angle

  @param[in]       float 32: f_Angle                    [-180.f ... 180.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   @ref LOHP_CFG_PRED  \n
  
  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
float32 PRED_f_CalcCurvatureFromAngle( float32 f_Angle )
{
  /* local vars */
  float32 f_Curvature = 0.0f;

  /* Only calculate a curvature if Angle is greater than 0 deg */
  if ( fABS( f_Angle ) > Aacc_alat_angle_to_radius[( Aacc_alat_angle_to_radius_points - 1u )] )
  {
    /* local vars */
    float32 f_Radius;

    /* Calculate a curve radius corresponding to the given angle between segments */
    /* Calculation based on 1D linear map interpolation */
    f_Radius =
      cal_calculate_param_value_1D
      (  Aacc_alat_angle_to_radius
       , Aacc_alat_curve_radius
       , Aacc_alat_curve_radius_points
       , fABS( f_Angle )    
      );

    /* Convert Radius into a curvature */
    f_Curvature = 1.0f / f_Radius;

    /* Check if Angle is negative for correct conversion in curvature */
    /* Negative Angle/Curvature ==> right curve */
    /* Positive Angle/Curvature ==> left  curve */
    if ( f_Angle < 0.0f )
    {
      f_Curvature *= -1.0f;
    }
  }

  return f_Curvature;
}

/*************************************************************************************************************************
  Functionname:    PRED_t_CalcPredCurveVelo                                                                      */ /*!

  @brief           Calculate Curve's Setspeed

  @description     Calculate the setspeed for a Navi Segment based on its curvature
  
  @startuml 
  Start
    Partition PRED_t_CalcPredCurveVelo {
      : Calculate Curve Radius from received curvature;
      : Calculate the desired ego Setspeed based on the curve radius;
      : Limit result and convert to fixed point;
      : Return Setspeed;
    }
  End
  @enduml

  @return          velocity_t : curve's setspeed

  @param[in]       float 32: f_Curvature                    [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   @ref LOHP_CFG_PRED  \n
  
  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
velocity_t PRED_t_CalcPredCurveVelo( float32 f_Curvature )
{
  float32 f_CurveRadius;
  float32 f_CurveSetSpeed;
  velocity_t s16_CurveSetSpeed;

  /* Calculate Curve Radius from Navi input data segment's curvature */
  f_CurveRadius = 1.0f / MAX_FLOAT( fABS( f_Curvature ), AACC_CURVATURE_MIN );

  /* Calculate the desired ego velocity based on the curve radius */
  /* Calculation based on 1D linear map interpolation */
  f_CurveSetSpeed =
    cal_calculate_param_value_1D
    (  Aacc_alat_curve_radius
     , Aacc_alat_curve_setspeed
     , Aacc_alat_curve_setspeed_points
     , f_CurveRadius    
    );

  /* Convert to fixed point value */
  f_CurveSetSpeed *= ( float32 )Velocity_s;

  if ( f_CurveSetSpeed >= ( float32 )Velocity_max )
  {
    /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
    s16_CurveSetSpeed = ( velocity_t )Velocity_max;
  }
  else
  {
    /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
    s16_CurveSetSpeed = ( velocity_t )ROUND_TO_INT( f_CurveSetSpeed );
  }

  return s16_CurveSetSpeed;
}

/*************************************************************************************************************************
  Functionname:    PRED_t_CalcDistBasedAccelReq

  @brief           Calculate required deceleration for comfortable driving with AACC

  @description     Calculate required deceleration for reaching a desired setspeed in a given absolute distance
  
  @startuml 
  Start
    Partition PRED_t_CalcDistBasedAccelReq {
      If ( Ego speed is greater than given setspeed ) then (yes)
        : Calculate the maximal distance range in which predictive accel request shall be calculated
          depending on the desired control deceleration
          s = ( Vego^2 - Vset^2 ) / (-2 * a);
        If (       Distance to curve or speed limit is smaller than previous calculated maximal distance
            \n AND Distance to curve or speed is greater than minimum allowed distance
           ) then (yes)
          : Calculate the necessary acceleration/deceleration
            to reach the setspeed at the given distance
            a = ( Vego^2 - Vset^2 ) / (-2 * s);
          : Limit the acceleration result to the allowed AACC control limits;
        Else (no)
          : Set acceleration request to the maximal allowed value;
        Endif
      Else (no)
        : Set acceleration request to the maximal allowed value;
      Endif
    }
  End
  @enduml

  @return          acceleration_t : AACC control acceleration request

  @param[in]       velocity_t : s16_EgoSpeed                [0x8000 ... 0x7FFF]
  @param[in]       velocity_t : s16_SetSpeed                [0x8000 ... 0x7FFF]
  @param[in]       float 32: f_DistToCurve                  [0.f ... 1000000.f]
  @param[in]       float 32: f_DesDecel                     [-6.f ... +4.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   @ref LOHP_CFG_PRED  \n

  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
acceleration_t PRED_t_CalcDistBasedAccelReq( velocity_t s16_EgoSpeed, velocity_t s16_SetSpeed, float32 f_Dist, float32 f_DesDecel )
{
  /* Local variables */
  acceleration_t s16_AaccAccelReq;

  /* Only calculate deceleration request in case ego speed is greater than the requested setspeed */
  /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
  if ( s16_EgoSpeed > s16_SetSpeed )
  {
    /* Local variables */
    float32 f_MaxCtrlDist;
    float32 f_EgoSpeed = ( float32 )s16_EgoSpeed / ( float32 )Velocity_s;
    float32 f_CurveSetSpeed = ( float32 )s16_SetSpeed / ( float32 )Velocity_s;
        
    /* Calculate the maximal distance range in which predictive AACC shall be active */
    /* depending on the desired control deceleration */
    /* s = ( Vego² - Vset² ) / (-2 * a) */
    f_MaxCtrlDist = ( SQR( f_EgoSpeed ) - SQR( f_CurveSetSpeed )) / ( -2.0f * f_DesDecel );

    if ( f_MaxCtrlDist < AACC_MIN_DIST )
    {
      f_MaxCtrlDist = AACC_MIN_DIST;
    }

    /* Calculate the necessary acceleration/deceleration to reach the setspeed */
    /* at the given distance only if Distance is smaller than previous calculated maximal distance */
    /* and in case the distance to the curve is greater than a threshold */
    if (   ( f_Dist < f_MaxCtrlDist )
        && ( f_Dist > AACC_MIN_DIST )
       )
    {
      /* Local variables */
      float32 f_AaccAccelReq;
    
      /* Calculate deceleration */
      /* a = ( Vego² - Vset² ) / (-2 * s) */
      f_AaccAccelReq = ( SQR( f_EgoSpeed ) - SQR( f_CurveSetSpeed )) / ( -2.0f * f_Dist );
      
      /* Limit the acceleration result to the allowed AACC control limits */
      if ( f_AaccAccelReq < Aacc_min_accel_req )
      {
        f_AaccAccelReq = Aacc_min_accel_req;
      }
      else if ( f_AaccAccelReq > AACC_MAX_ACCEL_REQ )
      {
        f_AaccAccelReq = AACC_MAX_ACCEL_REQ;
      }

      /* Convert to fixed point return value */
      /* Floating point constant Aacc_alat_min_accel_req must be greater than -32.0f */
      /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
      s16_AaccAccelReq = ( acceleration_t )ROUND_TO_INT(( f_AaccAccelReq * ( float32 )Acceleration_s ));
    }
    else
    {
      /* If conditions are not fulfilled AACC acceleration request is set to the maximal allowed value */
      /* Floating point constant AACC_MAX_ACCEL_REQ must be smaller than 32.0f */
      /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
      s16_AaccAccelReq = ( acceleration_t )( AACC_MAX_ACCEL_REQ * ( float32 )Acceleration_s );
    }
  }
  else
  {
    /* If conditions are not fulfilled AACC acceleration request is set to the maximal allowed value */
    /* Floating point constant AACC_MAX_ACCEL_REQ must be smaller than 32.0f */
    /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
    s16_AaccAccelReq = ( acceleration_t )( AACC_MAX_ACCEL_REQ * ( float32 )Acceleration_s );
  }
  
  return s16_AaccAccelReq;
}

#endif  /* ( LOHP_CFG_PRED ) */

/** @} end defgroup */