/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC functions)

PACKAGENAME:               pred_curve.c

DESCRIPTION:               This file contains functions concerning predictive curve control

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             09.01.2019

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   pred_main Pred_main
@ingroup    pred
@brief      Main functions for PRED module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "pred.h"

#if ( LOHP_CFG_PRED )

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*! @cond Doxygen_Suppress */
SET_MEMSEC_VAR(PRED_State)
PRED_t_State PRED_State;
/*! @endcond Doxygen_Suppress */

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:    PRED_v_Init                                                                                      */ /*!

  @brief           All curve control output values are initialized to neutral values

  @description     All curve control output values are initialized to neutral values
  
  @startuml 
  Start
    Partition PRED_v_Init {
      : Set all segments' acceleration requests and setspeeds to neutral values;
      : All Inputs values are initialized to neutral values;
      : All Output values are initialized to neutral values;
      : Init customer specific variables;
    }
  End
  @enduml

  @return          -

  @param[in,out]   p_PredData               : Pointer to AACC PRED output           [PRED_Output_t as per pred_ext.h]
                      t_PredBufferedInput   : Pointer to PRED's Input Buffer        [PRED_BufferedInput_t as per pred_ext.h]
                      t_PredOutput          : Pointer to AACC PRED output           [PRED_Output_t as per pred_ext.h]

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
void PRED_v_Init( PRED_StaticMem_t * p_PredData )
{
  /* Initialization of generic data */
  /* Local vars */
  uint8 i;
  acceleration_t s16_MaxAccelReq;
  PRED_BufferedInput_t * p_PredInpBuffer = &p_PredData->t_PredBufferedInput;
  PRED_Output_t * p_PredOut = &p_PredData->t_PredOutput;

  /* Calculate maximal AACC acceleration request */
  s16_MaxAccelReq = ( acceleration_t )AACC_MAX_ACCEL_REQ * Acceleration_s;

  /* Init all segments' acceleration requests and setspeeds */
  for ( i = 0; i < PRED_NUM_USED_NAVI_SEG; i++ )
  {
    p_PredInpBuffer->t_NaviSeg[i].f_Curvature             = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].f_CurvatureChange       = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].f_AngleToPrevSeg        = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].f_Length                = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].t_Slope.f_Slope         = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].t_Slope.f_OffsDist      = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.f_OffsDist = ( float32 )0;
    p_PredInpBuffer->t_NaviSeg[i].t_SpeedLimit.s16_SpeedLimit = ( velocity_t )0;

    p_PredOut->t_SegReq[i].s16_AccelReqSeg = s16_MaxAccelReq;
    p_PredOut->t_SegReq[i].s16_SetSpeedSeg = ( velocity_t )0;
  }

  /* All Curve control Input values are initialized to neutral values */
  p_PredInpBuffer->u8_NumUsedSeg = ( uint8 )0;

  /* All PRED control output values are initialized to neutral values */
  p_PredOut->lv_PredCtrlAct = FALSE;
  p_PredOut->u8_SegUsedForCtrl = ( uint8 )255;
  p_PredOut->u16_TmrDataInv = AACC_TIMER_MAX_INVALID;
  p_PredOut->s16_AccelReqUsedForCtrl = s16_MaxAccelReq;
  p_PredOut->s16_SetSpeedUsedForCtrl = ( velocity_t )0;
  p_PredOut->f_DistUsedForCtrl = ( float32 )0;

  /* All features' control output values are initialized to neutral values */
  p_PredOut->t_CrvCtrlOut.lv_FeatAct = FALSE;
  p_PredOut->t_CrvCtrlOut.s16_AccelReq = s16_MaxAccelReq;
  p_PredOut->t_CrvCtrlOut.s16_SetSpeed = ( velocity_t )0;
  p_PredOut->t_CrvCtrlOut.u8_CtrlSeg = ( uint8 )255;
  p_PredOut->t_CrvCtrlOut.f_Dist = ( float32 )0;

  p_PredOut->t_SpdLimOut.lv_FeatAct = FALSE;
  p_PredOut->t_SpdLimOut.s16_AccelReq = s16_MaxAccelReq;
  p_PredOut->t_SpdLimOut.s16_SetSpeed = ( velocity_t )0;
  p_PredOut->t_SpdLimOut.u8_CtrlSeg = ( uint8 )255;
  p_PredOut->t_SpdLimOut.f_Dist = ( float32 )0;

  p_PredOut->t_GreenOut.lv_FeatAct = FALSE;
  p_PredOut->t_GreenOut.s16_AccelReq = s16_MaxAccelReq;
  p_PredOut->t_GreenOut.s16_SetSpeed = ( velocity_t )0;
  p_PredOut->t_GreenOut.u8_CtrlSeg = ( uint8 )255;
  p_PredOut->t_GreenOut.f_Dist = ( float32 )0;

  /* Initialization of customer specific data */
  /* ... */
}

/*************************************************************************************************************************
  Functionname:    PRED_v_PreProcess                                                                      */ /*!

  @brief           Preprocess Navi Input Data

  @description     Preprocess Navi Input Data
  
  @startuml 
  Start
    Partition PRED_v_PreProcess {
      : Call customer specific Navi data preprocessing;
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

  @c_switch_part   -
  @c_switch_full   @ref LOHP_CFG_PRED  \n
  
  @pre             -
  @post            -

  @created         28.08.2018
  @changed         28.08.2018

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 8382 9699 573
*************************************************************************************************************************/
void PRED_v_PreProcess( velocity_t s16_EgoSpeed, const SLATE_NAVI_OUTPUT_t * p_NaviInpData, PRED_StaticMem_t * p_PredData )
{
  /* Mostly Navi Input data and its reconstruction and validity checks are customer specific */
  /* Call customer specific Navi data preprocessing */
  PRED_v_PreProcessCustom( s16_EgoSpeed, p_NaviInpData, p_PredData );
}

/*************************************************************************************************************************
  Functionname:    PRED_v_Process                                                                      */ /*!

  @brief           Limitation of longitudinal acceleration based on navi routing curve information

  @description     Limit the longitudinal acceleration so that the lateral acceleration is comfortable
                   while driving through curves. The acceleration/deceleration request depends on the
                   curves which are part of the active navi route
  
  @startuml 
  Start
    Partition PRED_v_Process {
      : Call predictive curve controller module's cyclic function;
      : Call green ACC module's cyclic function;
      If (    AACC acceleration request
           \n below distance control acceleration request
         ) then (yes)
        : Set AACC curve control activation flag;
        If ( AACC calibration switch is set ) then (yes)
          : Overwrite distance control acceleration request with AACC request;
        Endif
      Else (no)
        : Reset AACC curve control activation flag;
      Endif
    }
  End
  @enduml

  @return          -

  @param[in]       velocity_t                 : s16_EgoSpeed                        [0x8000 ... 0x7FFF] m/s (with factor Velocity_s)
  @param[in,out]   p_PredData                 : Pointer to AACC PRED output         [PRED_Output_t as per pred_ext.h]
                      t_PredBufferedInput     : Pointer to PRED's Input Buffer      [PRED_BufferedInput_t as per pred_ext.h]
                      t_PredOutput            : Pointer to AACC PRED output         [PRED_Output_t as per pred_ext.h]
  @param[in,out]   p_AccOutput                : Pointer to ACC Output Data          [acc_output_data_t as per Rte_type.h]
                      DISTANCE_CTRL_ACCEL_MAX : ACC accel request                   [0x8000 ... 0x7FFF] m/s2 (with factor Acceleration_s)
  

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
void PRED_v_Process
(  
   velocity_t s16_EgoSpeed
 , PRED_StaticMem_t * p_PredData
 , acc_output_data_t * p_AccOutputData
)
{
  /* Initialization of generic data */
  /* Local vars */
  PRED_BufferedInput_t * p_PredInpBuffer = &p_PredData->t_PredBufferedInput;
  PRED_Output_t * p_PredOut = &p_PredData->t_PredOutput;
  
#if ( PRED_ACT_CURVE_CTRL )
  /* Call predictive curve controller module's cyclic function */
  PRED_v_ProcessCurve( s16_EgoSpeed, p_PredInpBuffer, p_PredOut );
#endif /* PRED_ACT_CURVE_CTRL */

#if ( PRED_ACT_SPEED_LIM_CTRL )
  /* Call Speed Limit module's cyclic function */
  PRED_v_ProcessSpeedlimit( s16_EgoSpeed, p_PredInpBuffer, p_PredOut );
#endif /* PRED_ACT_SPEED_LIM_CTRL */

#if ( PRED_ACT_GREEN_ACC )
  /* Call green ACC module's cyclic function */
  PRED_v_ProcessGreen( s16_EgoSpeed, p_PredInpBuffer, p_PredOut );
#endif /* PRED_ACT_GREEN_ACC */

  /* Choose the feature as control relevant with the smallest acceleration request */
  /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
  if ( p_PredOut->t_CrvCtrlOut.s16_AccelReq <= p_PredOut->t_SpdLimOut.s16_AccelReq )
  {
    /* Set PRED output variables using CrvCtrl Output values */
    /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
    p_PredOut->s16_AccelReqUsedForCtrl = p_PredOut->t_CrvCtrlOut.s16_AccelReq;
    /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
    p_PredOut->s16_SetSpeedUsedForCtrl = p_PredOut->t_CrvCtrlOut.s16_SetSpeed;
    /* 1 [-], 0 ... 0xFF */
    p_PredOut->u8_SegUsedForCtrl = p_PredOut->t_CrvCtrlOut.u8_CtrlSeg;
    /* Set distance */
    p_PredOut->f_DistUsedForCtrl = p_PredOut->t_CrvCtrlOut.f_Dist;
  }
  else
  {
    /* Set PRED output variables using SpdLim Output values */
    /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
    p_PredOut->s16_AccelReqUsedForCtrl = p_PredOut->t_SpdLimOut.s16_AccelReq;
    /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
    p_PredOut->s16_SetSpeedUsedForCtrl = p_PredOut->t_SpdLimOut.s16_SetSpeed;
    /* 1 [-], 0 ... 0xFF */
    p_PredOut->u8_SegUsedForCtrl = p_PredOut->t_SpdLimOut.u8_CtrlSeg;
    /* Set distance */
    p_PredOut->f_DistUsedForCtrl = p_PredOut->t_SpdLimOut.f_Dist;
  }

  /* Arbitrate AACC curve control acceleration request with */
  /* the distance control acceleration request calculated in HP */
  /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
  if (  p_PredOut->s16_AccelReqUsedForCtrl
      < p_AccOutputData->DISTANCE_CTRL_ACCEL_MAX
     )
  {
    /* Set AACC curve control activation flag */
    p_PredOut->lv_PredCtrlAct = TRUE;

    /* Only allow the predictive curve controller to intervene if calibration switch is set */
    if ( Lc_act_pred_ctrl == TRUE )
    {
      /* Overwrite distance control acceleration request with AACC request */
      /* 1e-3 [m/s²], 0x8000 ... 0x7FFF */
      p_AccOutputData->DISTANCE_CTRL_ACCEL_MAX = p_PredOut->s16_AccelReqUsedForCtrl;
    }
  }
  else
  {
    /* Reset AACC curve control activation flag */
    p_PredOut->lv_PredCtrlAct = FALSE;
  }
}

#endif  /* ( LOHP_CFG_PRED ) */

/** @} end defgroup */
