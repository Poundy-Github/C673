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


#if ( LOHP_CFG_PRED )
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       pred_customfunctions Pred_Customfunctions
@ingroup        pred_custom
@brief          File containing customer specific functions for ACC PRED module.
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
static boolean PRED_t_NaviInputVldCustom( const SLATE_NAVI_OUTPUT_t * p_NaviInpData );
static float32 PRED_t_ConvertSlopeCustom( uint16 u16_Slope );

/*************************************************************************************************************************
  Functionname:    PRED_t_NaviInputVldCustom                                                                      */ /*!

  @brief           Calculation of Navi input data validity

  @description     Calculation of Navi input data validity based on logic checks and data consistency
  
  @startuml
  Start
    Partition PRED_t_NaviInputVldCustom {
      If (       Signal header status is OK
          \n AND NAVI Data quality is better than minimum threshold
          \n AND amount of used segments is greater than 0
          \n AND amount of used segments is smaller than maximum allowed value
          \n AND Navi System is not in hanging state
          ) then (yes)
        : Declare Navi data as valid;
      Else (no)
        : Declare Navi data as invalid;
      Endif
      If (Navi data valid) then (yes)
        If (      number of lanes is equal to zero
            \n OR number of lanes exceeds maximum number of valid lanes
            \n OR street type is either Signal Unfilled or Unknown
            \n OR length of segment is less than zero
            ) then (yes)
          : Declare segment's data as invalid;
        Else (no)
          : Declare segment's data as valid;
        Endif
      Endif
      If (Navi data valid \n AND all segments valid) then (yes)
        : Return TRUE;
        Else (no)
        : Return FALSE;
      Endif
    }
  End
  @enduml

  @return          boolean : Validity of Navi Input

  @param[in]       p_NaviInpData            : Reference to incoming NAVI data     [SLATE_NAVI_OUTPUT_t as per slate_ext.h]
                      u_NumUsedSegments     : number of the used segments         [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY-1u]
                      sSigHeader.eSigStatus : Signal header status                [AlgoSignalState_t as in Rte_Type.h]
                      Segments[i]           : segment i                           [Segments_array_t as in Rte_Type.h]
                      u_QuanLanes           : number of lanes                     [0u ... FIP_NAV_MAX_VALID_LANE_NUM]
                      TypStreet             : street type                         [t_NavStreetType as in Rte_Type.h]
                      f_Length              : length of near segment              [full range of datatype float32 >= 0.F] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   @ref PRED_USE_VW_EHR_NAVI_DATA \n
  @c_switch_part   @ref PRED_USE_STREET_TYP \n
  @c_switch_full   @ref LOHP_CFG_PRED  \n

  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
static boolean PRED_t_NaviInputVldCustom( const SLATE_NAVI_OUTPUT_t * p_NaviInpData )
{
#if ( PRED_USE_VW_EHR_NAVI_DATA )

  /* Local variables */
  uint8 i;
  boolean lv_ActPredCurveCtrl = FALSE;
  boolean lv_NaviDataVld;
  boolean lv_RoadSegVld;

  /* Check if NAVI Data quality is better than minimum threshold. This information is stored in a quality variable */
  /* In case of a insufficient quality, the plausibility is set as FALSE */
  /* Furthermore it is checked if the port is valid , if the amount of used segments is greater than 0 */
  /* and the Navi System shall not be in a hanging state */
  lv_NaviDataVld =
    (   /* 1 [-], 0 ... 0x02 */
        ( p_NaviInpData->sSigHeader.eSigStatus == AL_SIG_STATE_OK )
        /* 1 [-], 0 ... 0x04 */
      && ( p_NaviInpData->u_NaviDataQuality > AACC_MIN_NAVI_QUALITY )
        /* 1 [-], 0 ... 0xFF */
      && ( p_NaviInpData->u_NumUsedSegments >= AACC_MIN_AV_NAVI_SEG )
        /* 1 [-], 0 ... 0xFF */
      && ( p_NaviInpData->u_NumUsedSegments <= AACC_MAX_NR_NAV_SEG )
      && ( p_NaviInpData->b_HangNaviTree == FALSE )
//     && ( p_NaviInpData->b_MppNew == FALSE )
    );

  /* Initialize Segment's validity */
  lv_RoadSegVld = lv_NaviDataVld;

  /* Only check Segment's validity if previous validity check was successful */
  if ( lv_NaviDataVld == TRUE )
  {
    /* Process data only if Quality is acceptable */
    for ( i = 0u; (( i < p_NaviInpData->u_NumUsedSegments ) && ( lv_RoadSegVld == TRUE )); i++ )
    {
      /*! Determine if one of the segments is invalid:
          number of lanes exceeds zeros street type has to be valid
          length of segment has to be higher zero (starting from the 1-th segment)  */
      if (   /* 1 [-], 0 ... 0xFF */
              ( p_NaviInpData->t_NaviSegments[i].u_QuanLanes == ( uint8 )0 )
              /* 1 [-], 0 ... 0xFF */
          || ( p_NaviInpData->t_NaviSegments[i].u_QuanLanes > AACC_MAX_NR_NAV_LANES )
#if ( PRED_USE_STREET_TYP )               
              /* 1 [-], 0 ... 0xFF */
          || ( p_NaviInpData->t_NaviSegments[i].TypStreet == NAV_STT_SIGNAL_UNFILLED )
              /* 1 [-], 0 ... 0xFF */
          || ( p_NaviInpData->t_NaviSegments[i].TypStreet == NAV_STT_UNKNOWN )
#endif
          || (   /* 1 [-], 0 ... 0xFF */
                  ( i > ( uint8 )0 )
              && ( p_NaviInpData->t_NaviSegments[i].f_Length <= C_F32_DELTA )
              )
          )
      {
        lv_RoadSegVld = FALSE;
      }
    }
  }
  /* If all velocity conditions and Navi data validity are fulfilled */
  /* predictive curve control can be activated */
  lv_ActPredCurveCtrl =
    (   ( lv_NaviDataVld == TRUE )
     && ( lv_RoadSegVld  == TRUE )
    );

  return lv_ActPredCurveCtrl;

#else

  return TRUE;

#endif /* ( PRED_USE_VW_EHR_NAVI_DATA ) */
}

/*************************************************************************************************************************
  Functionname:    PRED_t_ConvertSlopeCustom                                                                      */ /*!

  @brief           Conversion of slope from fixed point to floating point

  @description     Conversion of slope from fixed point to floating point
  
  @startuml
  Start
    Partition PRED_t_ConvertSlopeCustom {
      : Init return value with 0;
      If ( Slope input is inside allowed range )then (yes)
      : Convert slope to floating point;
    Endif
    }
  End
  @enduml

  @return          float : slope

  @param[in]       uint16                   : u16_Slope

  @glob_in         -
  @glob_out        -

  @c_switch_part   @ref PRED_USE_VW_EHR_NAVI_DATA \n
  @c_switch_full   @ref LOHP_CFG_PRED  \n

  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
static float32 PRED_t_ConvertSlopeCustom( uint16 u16_Slope )
{
#if ( PRED_USE_VW_EHR_NAVI_DATA )

  /* Local variables */
  float32 f_Slope = ( float32 )0;

  /* Check range and validity of slope input */
  if (   /* 1e-2 [%], 0 ... 0xFFFF, Offs. 0x2710 */
         ( u16_Slope >= AACC_MIN_SLOPE )
      && ( u16_Slope <= AACC_MAX_SLOPE )
     )
  {
    f_Slope = (( float32 )u16_Slope * AACC_SLOPE_CONV_FAC ) - AACC_SLOPE_OFFS;
  }
  
  return f_Slope;

#else

  return f_Slope;

#endif /* ( PRED_USE_VW_EHR_NAVI_DATA ) */
}

/*************************************************************************************************************************
  Functionname:    PRED_v_PreProcessCustom                                                                      */ /*!

  @brief           Customer specific data preprocessing for PRED subcomponent's functions

  @description     Customer specific data like Navi Input and Ego vehicle data are adapted and buffered
  
  @startuml 
  Start
    Partition PRED_v_PreProcessCustom {
      : Check Navi Input data validity;
      If ( Navi Input Data valid \n AND \n Number valid Input Segments is greater or equal than amount of local buffered Segments )then (yes)
        : Reset Navi Input Data invalidity Timer;
        : Update the amount of used valid Navi Segments;
        : Update local buffered Segments;
      Else (no)
        : Increment Navi Input Data invalidity Timer;
        If ( Segment(s) available in local Buffer )then (yes)
          : Estimate driven distance;
          If ( 1st Segment has slope )then (yes)
            : Subtract driven distance from slope offset distance;
            If ( Slope distance point passed )then (yes)
              : Reset slope and offset distance for 1st segment;
            Endif
          Endif
          If ( 1st Segment has speed limit )then (yes)
            : Subtract driven distance from speed limit offset distance;
            If ( speed limit distance point passed )then (yes)
              : Reset speed limit and offset distance for 1st segment;
            Endif
          Endif
          : Subtract driven distance from 1st segment's length;
          If ( 1st Segment's length below threshold )then (yes)
            : Reduce number of available segments;
            : New Sorting of local Segment Buffer;
          Endif
        Else (no)
          : Initialize all predictive curve control data to neutral values;
        Endif
      Endif
    }
  End
  @enduml

  @return          -

  @param[in]       velocity_t               : s16_EgoSpeed                        [0x8000 ... 0x7FFF] m/s (with factor Velocity_s)
  @param[in]       p_NaviInpData            : Reference to incoming NAVI data     [SLATE_NAVI_OUTPUT_t as per slate_ext.h]
                      u_NumUsedSegments     : number of the used segments         [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY-1u]
                      sSigHeader.eSigStatus : Signal header status                [AlgoSignalState_t as in Rte_Type.h]
                      Segments[i]           : segment i                           [Segments_array_t as in Rte_Type.h]
                      u_QuanLanes           : number of lanes                     [0u ... FIP_NAV_MAX_VALID_LANE_NUM]
                      TypStreet             : street type                         [t_NavStreetType as in Rte_Type.h]
                      f_Length              : length of near segment              [full range of datatype float32 >= 0.F] m
  @param[in,out]   p_PredData               : Pointer to AACC PRED output         [PRED_Output_t as per pred_ext.h]
                      t_PredBufferedInput   : Pointer to PRED's Input Buffer      [PRED_BufferedInput_t as per pred_ext.h]
                      t_PredOutput          : Pointer to AACC PRED output         [PRED_Output_t as per pred_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   @ref PRED_USE_VW_EHR_NAVI_DATA \n
  @c_switch_full   @ref LOHP_CFG_PRED  \n
  
  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
void PRED_v_PreProcessCustom
(
   velocity_t s16_EgoSpeed
 , const SLATE_NAVI_OUTPUT_t * p_NaviInpData
 , PRED_StaticMem_t * p_PredData
)
{
#if ( PRED_USE_VW_EHR_NAVI_DATA )

  /* Local variables */
  uint8 i;
  boolean lv_NaviDataVld;
  PRED_BufferedInput_t * p_PredInpBuffer = &p_PredData->t_PredBufferedInput;
  PRED_Output_t * p_PredOut = &p_PredData->t_PredOutput;
  
  /* Check if Navi Data is valid */
  lv_NaviDataVld = PRED_t_NaviInputVldCustom( p_NaviInpData );

  /* In case Navi Data is valid all available Segments can be copied */
  if (   ( lv_NaviDataVld == TRUE )
         /* 1 [-], 0 ... 0xFF  */
      && ( p_NaviInpData->u_NumUsedSegments >= p_PredInpBuffer->u8_NumUsedSeg )
     )
  {
    /* local vars */
    float32 f_SpeedLimit;
    float32 f_SpeedConvFac = ( float32 )Speed_conv_factor_kmh / ( float32 )Factor_s;

    /* Reset Navi Data validity timer */
    /* 1e-3 [s], 0 ... 0xFFFF */
    p_PredOut->u16_TmrDataInv = ( times_t )0;
    
    /* 1 [-], 0 ... 0xFF  */
   p_PredInpBuffer->u8_NumUsedSeg = p_NaviInpData->u_NumUsedSegments;

    for ( i = 0; i < p_NaviInpData->u_NumUsedSegments; i++ )
    {
      /* Copy Segment's curvature */
      p_PredInpBuffer->t_NaviSeg[i].f_Curvature = p_NaviInpData->t_NaviSegments[i].f_Curvature;

      /* Copy Segment's curvature change */
      p_PredInpBuffer->t_NaviSeg[i].f_CurvatureChange = p_NaviInpData->t_NaviSegments[i].f_CurvatureChange;
        
      /* Copy Segment's angle to previous segment */
      p_PredInpBuffer->t_NaviSeg[i].f_AngleToPrevSeg = p_NaviInpData->t_NaviSegments[i].f_AnglePrevSeg;

      /* Copy Segment's length */
      p_PredInpBuffer->t_NaviSeg[i].f_Length = p_NaviInpData->t_NaviSegments[i].f_Length;

      
      /* Copy Segment's slope */
      p_PredInpBuffer->t_NaviSeg[i].t_Slope.f_Slope =
        PRED_t_ConvertSlopeCustom( p_NaviInpData->t_NaviSegments[i].AttrSlope.u_Slope );

      /* Copy Segment's slope offset distance */
      p_PredInpBuffer->t_NaviSeg[i].t_Slope.f_OffsDist =
        ( float32 )p_NaviInpData->t_NaviSegments[i].AttrSlope.u_Offset / ( float32 )Distance_s;

      
      /* Convert speed limit's unit to [m/s] */
      f_SpeedLimit = ( float32 )p_NaviInpData->t_NaviSegments[i].SpeedLimitLocal.u_SpeedLimit / f_SpeedConvFac;
      /* Copy Segment's speed limit */
      /* 1 [m/s], 0x8000 ... 0x7FFF  */
      p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.s16_SpeedLimit =
        ( velocity_t )ROUND_TO_INT(( f_SpeedLimit * ( float32 )Velocity_s ));

      /* Copy Segment's speed limit offset distance */
      p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.f_OffsDist =
        ( float32 )p_NaviInpData->t_NaviSegments[i].SpeedLimitLocal.u_Offset / ( float32 )Distance_s;
    }
  } 
  else
  {
    /* Increase Navi data invalidity timer */
    /* 1e-3 [s], 0 ... 0xFFFF */
    p_PredOut->u16_TmrDataInv = MAT_S16_ADD_S16_S16( p_PredOut->u16_TmrDataInv, AACC_CYCLE_TIME );

    /* Check if Segment's information is still valid from previous cycles */
    /* 1 [-], 0 ... 0xFF  */
    if ( p_PredInpBuffer->u8_NumUsedSeg > ( uint8 )0 )
    {
      /* local vars */
      float32 f_EgoSpeed = ( float32 )s16_EgoSpeed / ( float32 )Velocity_s;
      float32 f_CycleTime = ( float32 )AACC_CYCLE_TIME / ( float32 )Time_s;
      float32 f_DrivenDist = f_EgoSpeed * f_CycleTime;
      
      /* Only subtract driven distance if slope exists inside ego segment */
      if (   ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_Slope.f_Slope    != ( float32 )0 )
          && ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_Slope.f_OffsDist >  ( float32 )0 )
         )
      {
        /* Subtract driven distance from slope offset distance */
        p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_Slope.f_OffsDist -= f_DrivenDist;

        /* Check if slope distance point was passed */
        if ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_Slope.f_OffsDist < AACC_MIN_DIST )
        {
          /* Reset ego segment's slope data */
          p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_Slope.f_Slope    = ( float32 )0;
          p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_Slope.f_OffsDist = ( float32 )0;
        }
      }
      
      /* Only subtract driven distance if speed limit exists inside ego segment */
      if (   ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_SpeedLimit.s16_SpeedLimit > ( velocity_t )0 )
          && ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_SpeedLimit.f_OffsDist     > ( float32 )0 )
         )
      {
        /* Subtract driven distance from speed limit offset distance */
        p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_SpeedLimit.f_OffsDist -= f_DrivenDist;

        /* Check if speed limit distance point was passed */
        if ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_SpeedLimit.f_OffsDist < AACC_MIN_DIST )
        {
          /* Reset ego segment's speed limit data */
          p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_SpeedLimit.s16_SpeedLimit = ( velocity_t )0;
          p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].t_SpeedLimit.f_OffsDist     = ( float32 )0;
        }
      }
      
      /* Subtract driven distance from segment 0 length */
      p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].f_Length -= f_DrivenDist;
      
      /* Check if ego segment was passed */
      if ( p_PredInpBuffer->t_NaviSeg[AACC_FIRST_SEG].f_Length < AACC_MIN_DIST )
      {
        /* Reduce number of available segments */
        /* 1 [-], 0 ... 0xFF  */
        p_PredInpBuffer->u8_NumUsedSeg -= ( uint8 )1;
        
        for ( i = 0; i < p_PredInpBuffer->u8_NumUsedSeg; i++ )
        {
            /* Copy Segment's data */
            p_PredInpBuffer->t_NaviSeg[i] = p_PredInpBuffer->t_NaviSeg[( i + 1u )];
        }
      }
    }
    else
    {
      PRED_v_Init( p_PredData );
    }
  }
#endif /* ( PRED_USE_VW_EHR_NAVI_DATA ) */
}

#if ( PRED_ACT_CURVE_CTRL )
/*************************************************************************************************************************
  Functionname:    PRED_v_ProcessCurveCustom                                                                      */ /*!

  @brief           Cyclic call of customer specific calculations for Anticipatory ACC functions and features

  @description     Cyclic call of customer specific calculations for Anticipatory ACC functions and features
  
  @startuml 
  Start
    Partition PRED_v_ProcessCurveCustom {
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
  @c_switch_full   @ref PRED_ACT_CURVE_CTRL  \n

  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
void PRED_v_ProcessCurveCustom
(  
   velocity_t s16_EgoSpeed
 , PRED_BufferedInput_t * p_PredInpBuffer
 , PRED_Output_t * p_PredOut
)
{
  _PARAM_UNUSED( s16_EgoSpeed );
  _PARAM_UNUSED( p_PredInpBuffer );
  _PARAM_UNUSED( p_PredOut );
}
#endif /* PRED_ACT_CURVE_CTRL */


#if ( PRED_ACT_GREEN_ACC )
/*************************************************************************************************************************
  Functionname:    PRED_v_ProcessGreenCustom                                                                      */ /*!

  @brief           Cyclic call of customer specific calculations for Anticipatory ACC functions and features

  @description     Cyclic call of customer specific calculations for Anticipatory ACC functions and features
  
  @startuml 
  Start
    Partition PRED_v_ProcessGreenCustom {
      : To be filled;
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
void PRED_v_ProcessGreenCustom
(  
   velocity_t s16_EgoSpeed
 , PRED_BufferedInput_t * p_PredInpBuffer
 , PRED_Output_t * p_PredOut
)
{
  _PARAM_UNUSED( s16_EgoSpeed );
  _PARAM_UNUSED( p_PredInpBuffer );
  _PARAM_UNUSED( p_PredOut );
}
#endif /* PRED_ACT_GREEN_ACC */

#if ( PRED_ACT_SPEED_LIM_CTRL )
/*************************************************************************************************************************
  Functionname:    PRED_v_ProcessSpeedlimitCustom                                                                      */ /*!

  @brief           Cyclic call of customer specific calculations for Anticipatory ACC functions and features

  @description     Cyclic call of customer specific calculations for Anticipatory ACC functions and features
  
  @startuml 
  Start
    Partition PRED_v_ProcessSpeedlimitCustom {
      : To be filled;
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
void PRED_v_ProcessSpeedlimitCustom
(  
   velocity_t s16_EgoSpeed
 , PRED_BufferedInput_t * p_PredInpBuffer
 , PRED_Output_t * p_PredOut
)
{
  _PARAM_UNUSED( s16_EgoSpeed );
  _PARAM_UNUSED( p_PredInpBuffer );
  _PARAM_UNUSED( p_PredOut );
}
#endif /* PRED_ACT_SPEED_LIM_CTRL */

/** @} end defgroup */

#endif  /* ( LOHP_CFG_PRED ) */
