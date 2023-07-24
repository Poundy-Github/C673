/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_customfunctions.c

DESCRIPTION:               ACC FCT custom functions for pre-processing of Navi Data

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             12.05.2015

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 1.13

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip.h"

#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       fip_customfunctions Custom functions
@ingroup        fip
@brief          This module contains customer specific functions for ACC Function Input Processing module.
@{
*/

#include "fip_par.h"

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
#include "fip_navi_data_process.h"
#endif  /* (SLATE_CFG_SIMPLE_NAVI_INTERFACE) */

/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  STATIC FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  NON-STATIC FUNCTIONS
*****************************************************************************/

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_InitNaviCustomData                                                                         */ /*!

  @brief           function to initialize custom navi data for local copies of the FCTSEN input structure

  @description     function to initialize custom navi data for local copies of the FCTSEN input structure

  @startuml 
  Partition FIP_v_InitNaviCustomData
  Start
    - Depending on the available sources initialize custom navigation data 
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @created         01.02.2016
  @changed         01.02.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
void FIP_v_InitNaviCustomData(void)
{

}
#endif /*!< SLATE_CFG_SIMPLE_NAVI_INTERFACE */

/*************************************************************************************************************************
  Functionname:    FIP_v_Init_CustomTrafficOrientation                                                               */ /*!

  @brief           Init Custom Traffic Orientation signals

  @description     Init Custom Traffic Orientation signals

                    @startuml
                        Start
                            Partition FIP_v_Init_CustomTrafficOrientation {
                                - Init Custom Traffic Orientation signals
                            }
                        End
                    @enduml

  @return          -

  @param[in]       - 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @created         14.04.2016
  @changed         14.04.2016

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 (69) 67869-6110
*************************************************************************************************************************/
void FIP_v_Init_CustomTrafficOrientation(void)
{

}

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY))
/*************************************************************************************************************************
  Functionname:    FIP_v_InitCustInternalData                                                                         */ /*!

  @brief           function to initialize internal variables

  @description     function to initialize internal variables

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY : Calculate probability that ego veh will not follow navi path

  @pre             -
  @post            -

  @created         30.03.2017
  @changed         -

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 (69) 67869-6110
*************************************************************************************************************************/
void FIP_v_InitCustInternalData(void)
{
   
}
#endif /* ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY)) */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIPCalcNaviDataValid                                                                             */ /*!

  @brief           Determine if the NAVI path data are valid

  @description     Determine if the NAVI path data are valid based on 
                   - MAP Quality is acceptable,
                   - Number of lanes exceeds zero and 
                   - Valid street type for each segment
  
  @startuml 
  Partition FIPCalcNaviDataValid
  Start
    Note right: This function determines if the NAVI path data are valid
    If (Navigation Data quality is better than minimum threshold) then (True)
      - This information is stored in a quality bit
    Else (False)
      - Unsufficient quality, the plausibility is set as FALSE
    Endif

    If (Navigation path data is Valid \n AND \n number of used segments is over 0 \n AND \n Signal header status is OK) then (True)
      If (number of lanes is equal to zero \n OR \n number of lanes exceeds maximum number of valid lanes \n OR \n street type is either Signal Unfilled or Unknown \n OR \n length of segment is less than zero) then (True)
        - Set Navigation path data as False
      Else (False)
      Endif
    Else (False)
      - Set Navigation path data as False
    Endif
  Stop
  @enduml

  @return          bDataValid : TRUE, if function logic permits it AND NAVI path data is valid.
                                FALSE, if function logic permits it OR NAVI path data is invalid.

  @param[in]       pNaviData : Reference to incoming NAVI data
                      u_QualityNavData         [0u ... 4u]
                      u_NumUsedSegments : number of the used segments [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY-1u]
                      sSigHeader.eSigStatus : Signal header status [AlgoSignalState_t as in Rte_Type.h]
                      Segments[i] : segment i  [Segments_array_t as in Rte_Type.h]
                       u_QuanLanes : number of lanes [0u ... FIP_NAV_MAX_VALID_LANE_NUM[
                       TypStreet : street type [t_NavStreetType as in Rte_Type.h]
                       f_Length : length of near segment [full range of datatype float32 >= 0.F] m

  @glob_in         -
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple Navi input data to FCT_SEN

  @pre             None
  @post            None

  @created         21.05.2015
  @changed         10.09.2015

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
boolean FIPCalcNaviDataValid(const t_NaviInputData * pNaviData)
{
  boolean bDataValid = TRUE;
  uint8 i;

    /*! Check if NAVI Data quality is better than minimum threshold. This information is stored in a quality bit.
      In case of a unsufficient quality, the plausibility is set as FALSE; 
      FIP_NAVI_DATA_QUALITY_THRESHOLD_MIN defined in fip_ext.h */
  if(pNaviData->u_QualityNavData < FIP_NAVI_DATA_QUALITY_THRESHOLD_MIN)
  {
    FIPSet_MapIsADASQuality(FALSE);
    bDataValid = FALSE;
    
  }
  else
  {
    FIPSet_MapIsADASQuality(TRUE);
  }

  /*! Determine if one of the segments is invalid:
        number of lanes exceeds zeros
        street type has to be valid
        length of segment has to be higher zero (starting from the 1-th segment)  */
  if( (bDataValid == TRUE) &&
      (pNaviData->u_NumUsedSegments > 0u) && 
      (pNaviData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    /* Process data only if Quality is acceptable */
    /* for (i = 0u; (i < pNaviData->u_NumUsedSegments) && (bDataValid == TRUE); i++) */
    for (i = 0u; (i < FIP_NAVI_MAXSEG_FORDATAVALIDITY) && (bDataValid == TRUE); i++)
    {
      if( (pNaviData->Segments[i].u_QuanLanes == 0u) || 
          (pNaviData->Segments[i].u_QuanLanes > FIP_NAV_MAX_VALID_LANE_NUM) ||
          (pNaviData->Segments[i].TypStreet == NAV_STT_SIGNAL_UNFILLED) || 
          (pNaviData->Segments[i].TypStreet == NAV_STT_UNKNOWN) ||
          ( (i >= SEGMENT_1) && (pNaviData->Segments[i].f_Length <= C_F32_DELTA) )
        )
      {
        bDataValid = FALSE;
      }
    }
  }
  else
  {
    /* No usable segments comping from input */
    bDataValid = FALSE;
  }

  return bDataValid;
}
#endif /*!< SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIPSamplePosAbsNaviPathArcRel                                                                    */ /*!

  @brief           Determine the absolute position of a sample point based on the arc length relative to the beginning to 
                   the NAVI segment.

  @description     Determine the absolute position of a sample point based on the arc length relative to the beginning to 
                   the NAVI segment. This is based on a ration and translation of the sample points.
  
  @startuml 
  Partition FIPSamplePosAbsNaviPathArcRel
  Start
  Note right: This function determines the absolute position \n of a sample point based on the arc length \n relative to the beginning to the Navigation segment
  
  If (Type of approximation used for clothoid is Curvy Segment) then (True)
    If (Curvature of segment is not 0) then (True)
      - Compute radius of segment
    Else (False)
      - Set radius of segment to Maximal radius of a segment of the navigaiton path
    Endif
    
    If (Radius is not zero) then (True)
      - Compute Angle arc using radius
    Else (False) 
      - Compute Angle arc using curvature
    Endif
  Else (False)
    - In case of a straight segment, the distance of the \n sample point to the starting point of the segment \n is stored in the arc length (= x-position)
  Endif
  
  - Rotate the coordinate system by the accumulated \n rotation angle between the origin of the \n current segment and Navigation path
  - Move coordinate system to the origin of the navigation path
  Stop
  @enduml

  @return          -

  @param[in,out]   pfX : reference to x-position of determined position of sample point                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in,out]   pfY : reference to y-position of determined position of sample point                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       fAngleArcSampleRel_j : arc length of the sample point relative to the beginning of the NAVI segment
                                                                                                          [0.f ... 400.f]
  @param[in]       p_NaviSegment : reference to NAVI segment information
                      f_Curvature : curvature [-1.f ... 1.f]
                      f_CurvatureChange : Curvature change of the camera lane [-2.f ... 2.f]
  @param[in]       fCosAngleAccu : cosine of accumulated orientation of the starting point of the segment [-1.f ... 1.f]
  @param[in]       fSinAngleAccu : sine of accumulated orientation of the starting point of the segment   [-1.f ... 1.f]
  @param[in]       fXSegmentStart : x-position of starting point of the beginning of the NAVI segment     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       fYSegmentStart : y-position of starting point of the beginning of the NAVI segment     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX m]
  @param[in]       t_NaviPathCurvatureType : type of approximation used for clothoid                      [FIPNaviPathCurvatureType_t as in fip_navi_data_process.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @created         17.02.2016
  @changed         17.02.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
extern void FIPSamplePosAbsNaviPathArcRel( float32 * pfX, float32 * pfY, const float32 fAngleArcSampleRel_j, 
  const t_NavSegment * p_NaviSegment, const float32 fCosAngleAccu, const float32 fSinAngleAccu, const float32 fXSegmentStart, 
  const float32 fYSegmentStart, FIPNaviPathCurvatureType_t t_NaviPathCurvatureType)
{
  float32 fXSampleRel_j, fYSampleRel_j, fXSampleRelRot_j, fYSampleRelRot_j;

  float32 fAngleArc;        /* angle of the circle segment (only used in case of circular segments) */
  float32 fRadius;          /* radius of the segment (only used if constant radius over segment) */


  /*! First: Calculate the x- and y-position of the sample point relative to the starting point of the segment */
  if (t_NaviPathCurvatureType == NAVI_PATH_CURVY)
  {
    if (fABS(p_NaviSegment->f_Curvature) > C_F32_DELTA)
    {
      fRadius = 1.f / p_NaviSegment->f_Curvature;
    }
    else
    {
      fRadius = FIP_NAVI_SEGMENT_MAX_RADIUS;
    }

    if (fABS(fRadius) > C_F32_DELTA)
    {
      fAngleArc = fAngleArcSampleRel_j / fRadius;
    }
    else
    {
      fAngleArc = fAngleArcSampleRel_j * p_NaviSegment->f_Curvature;
    }

    fXSampleRel_j = SIN_HD_(fAngleArc) * fRadius;
    fYSampleRel_j = fRadius * (1.f - COS_HD_(fAngleArc));
  }
  else
  {
    /*! In case of a straight segment, the distance of the sample point to the starting point of the segment is stored in the arc length (= x-position) */
    fXSampleRel_j = fAngleArcSampleRel_j;
    fYSampleRel_j = 0.f;
  }
  
  /*! Second: Rotate the coordinate system by the accumulated rotation angle between the origin of the current segment and 
              the coordinate system at the origin of the NAVI path */
  fXSampleRelRot_j = (fCosAngleAccu * fXSampleRel_j) - (fSinAngleAccu * fYSampleRel_j);
  fYSampleRelRot_j = (fSinAngleAccu * fXSampleRel_j) + (fCosAngleAccu * fYSampleRel_j);

  /*! Third: Move coordinate system to the origin of the NAVI path */
  *pfX = fXSampleRelRot_j + fXSegmentStart;
  *pfY = fYSampleRelRot_j + fYSegmentStart;
}
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_t_GetNaviPathCurvatureType                                                                      */ /*!

  @brief           get navi path curvature type

  @description     get navi path curvature type which is to be used for approximation of given clothoid
                   straight line approximation, circle approximation
  
  @startuml 
  Partition FIP_t_GetNaviPathCurvatureType
  Start
  Note right: This function is used to get navigation path curvature type
  If (Curvature of navigation path is over small threshold (0.0001)) then (True)
    - Navigation path is Curvy type
  Else (False)
    - Navigation path is straight line
  Endif
  Stop
  @enduml

  @return          t_approxType : approximation type for clothoid approximation   
                                                                    [FIPNaviPathCurvatureType_t as in fip_navi_data_process.h]

  @param[in]       p_NaviSegment : navi segment information
                      f_Curvature                    [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   !FIP_EVAL_SHAPE_POINTS

  @pre             -
  @post            -

  @created         19.01.2016
  @changed         19.01.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
extern FIPNaviPathCurvatureType_t FIP_t_GetNaviPathCurvatureType( const t_NavSegment * p_NaviSegment )
{
  FIPNaviPathCurvatureType_t t_approxType = NAVI_PATH_STRAIGHT;

  if (fABS(p_NaviSegment->f_Curvature) > C_F32_DELTA)
  {
    t_approxType = NAVI_PATH_CURVY;
  }
  else
  {
    t_approxType = NAVI_PATH_STRAIGHT;
  }

  return t_approxType;
}
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_f_CalcSegAngleBasedOnCurve                                                                     */ /*!

  @brief           Calculation of segment angle based on curve for clothoids

  @description     Calculation of segment angle based on curve for clothoids
                   in case of BMW project the angle is angle to x-y-position of end of segment
  
  @startuml 
  Partition FIP_f_CalcSegAngleBasedOnCurve
  Start
  Note right: This function calculates segment angle based on curve for clothoids
  If (Navigation path is Curvy type) then (True)
    If (Curvature of navigation path is below small threshold (0.0001)) then (True)
      - Set Angle based on curve to zero
    Else (False)
      - Compute Angle based on curve using x-position, y-position and Angle arc length
    Endif
  Else (False)
  Endif
  Stop
  @enduml

  @return          f_SegAngleBasedOnCurve : angle at the given point on the segment relative to starting orientation of the segment
                                                                          [-PI ... PI] rad

  @param[in]       f_length : length of clothoid                          [0.f ... 400.f] m
  @param[in]       p_NaviSegment : navi segment information
  @param[in]       t_approxType : approximation type                      [FIPNaviPathCurvatureType_t as in fip_navi_data_procecss.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @created         14.01.2016
  @changed         14.01.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
float32 FIP_f_CalcSegAngleBasedOnCurve( float32 f_length, const t_NavSegment * p_NaviSegment, FIPNaviPathCurvatureType_t t_approxType)
{
  float32 f_SegAngleBasedOnCurve = 0.f; /* segment angle based on curve */

  _PARAM_UNUSED(f_length);
  _PARAM_UNUSED(p_NaviSegment);
  _PARAM_UNUSED(t_approxType);

  if (t_approxType == NAVI_PATH_CURVY)
  {
    if (p_NaviSegment->f_Curvature < C_F32_DELTA)
    {
      f_SegAngleBasedOnCurve = 0.f;
    }
    else
    {
      float32 f_AngleArc = f_length * p_NaviSegment->f_Curvature;
      float32 f_XPos = SIN_HD_(f_AngleArc) / p_NaviSegment->f_Curvature;
      float32 f_YPos = (1.f - COS_HD_(f_AngleArc)) / p_NaviSegment->f_Curvature;
      f_SegAngleBasedOnCurve = ATAN2_(f_YPos, f_XPos);
    }
  }

  return f_SegAngleBasedOnCurve;
}
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_f_UpdateAccumOrientPrevSegments                                                              */ /*!

  @brief           Update accumulated orientation to previous segments.

  @description     Update accumulated orientation to previous segments. Consider angle to previous segment and angle based 
                   on segment curvature.
                   In case of BMW only angle from navi input data has to be considered.
  
  @startuml 
  Partition FIP_f_UpdateAccumOrientPrevSegments
  Start
    - Add angle to previous segment to accumulated orientation to previous segments
  Stop
  @enduml

  @return          f_AccumOrientPrevSegments_Update : updated accumulated orientation to previous segments          
                                                                 [-PI ... PI] rad

  @param[in, out]  f_AccumOrientPrevSegments : accumulated orientation to previous segments from previous segments  
                                                                 [-PI ... PI] rad
  @param[in]       p_NaviSegment : navi segment information
                      p_NaviSegment->f_AnglePrevSeg              [-PI ... PI] rad
                      p_NaviSegment->f_Length                    [0.f ... 400.f] m
  @param[in]       t_NaviPathCurvatureType : approximation type  [FIPNaviPathCurvatureType_t as in fip_navi_data_procecss.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @created         17.02.2016
  @changed         17.02.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
void FIP_f_UpdateAccumOrientPrevSegments( float32 * f_AccumOrientPrevSegments, const t_NavSegment * p_NaviSegment, const FIPNaviPathCurvatureType_t t_NaviPathCurvatureType )
{
  _PARAM_UNUSED(t_NaviPathCurvatureType);

  /* Add angle to previous segment to accumulated orientation to previous segments */
  *f_AccumOrientPrevSegments += DEG2RAD(p_NaviSegment->f_AnglePrevSeg);
}
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_CUSTOM_PASSING_STATE))
/*************************************************************************************************************************
  Functionname:    FIP_b_OvertakeLaneIsExitLane                                                       */ /*!

  @brief           Returns Information if Overtaking Lane is exit lane

  @description     Returns Information if overtake lane is exit lane considering valid navi path, angle of navi exit segments and traffic orientation.
                   If function returns true, lane cannot be used for overtaking. 

  @return          b_OvertakeLaneIsExitLane : Returns TRUE if overtakelane is exitlane [TRUE,FALSE]

  @param[in]       -

  @glob_in         t_FIP_ALL_Output.t_FIP_ND_Output.b_NaviPathIsValid : information if NAVI data is valid [TRUE, FALSE]

  @glob_in         pSLATE_NaviData : Reference to incoming NAVI data
                      pSLATE_NaviData->u_DistNextExitLaneEnd                                       [u_DistNextExitLaneEnd as in Rte_Type.h] m
                      pSLATE_NaviData->u_DistNextExitLaneStart                                     [u_DistNextExitLaneStart] m
                      pSLATE_NaviData->pNaviData->Segments                                         [Segments_array_t as in Rte_Type.h]
                      pSLATE_NaviData->pNaviData->Segments[i].ExitSegments[i]                      [ExitSegments_array_t as in Rte_Type.h]
                      pSLATE_NaviData->pNaviData->Segments[i].ExitSegments[i].f_Length             [0m .. 200m]
                      pSLATE_NaviData->pNaviData->Segments[i].ExitSegments[i].f_Angle              [-180 ... 180]degree

  @glob_out        -

  @c_switch_part   -

  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_CUSTOM_PASSING_STATE : Dependency Switch Configuration switch for activating the calculation of the passing state

  @pre             -
  @post            used in out_customfunctions.c in OUT_t_LCPossibilityBasedOnInfrastructure()

  @created         04.05.2017
  @changed         -

  @author          Hrvoje Barnjak |hrvoje.barnjak@conti-engineering.com | +49(69)-67869-6366
*************************************************************************************************************************/
boolean FIP_b_OvertakeLaneIsExitLane(void)
{
  boolean b_OvertakeLaneIsExitLane = FALSE; /* Set default overtakelane is not exitlane */  
  return b_OvertakeLaneIsExitLane;
}
#endif /* END INF ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_CUSTOM_PASSING_STATE)) */

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY))
/*************************************************************************************************************************
  Functionname:    FIP_u_UpdateBranchProbability                                                                      */ /*!

  @brief           Based on Navi data, calculates the probability that ego will leave the most probability path 
                   (ego takes highway exit, intersection, branch). Returns probability.

  @description     Based on Navi data, calculates the probability that ego will leave the most probability path.
                   If the Navi path is not in 'route palned' state, the probability that ego will not follow the MPP is calculated.
                   The function checks if there is an alternative path to navi most probability path, which can be taken by ego vehicle.
                   The returned branch probability is proportional to the difference between ego logitudinal acceleration and
                   acceleration which is needed to adapt the ego speed to the branch/exit maximum speed. 
                   The branch probability is set back to 0 only when ego vehicle leaved the branch segment
                   and debounce time passed.

  @return          uint8 : probability ego veh. will not follow navi path [0% .. 100%]

  @param[out]      -

  @glob_in        pt_FIP_ND_Input->t_LAInput.pt_MovingObjPickUpRange                     The base pick up range for moving objects [m]
                   pSLATE_NaviData : Reference to incoming NAVI data
                      pSLATE_NaviData->pNaviData->u_NumUsedSegments                     [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY-1u]
                      pSLATE_NaviData->pNaviData->Segments                              [Segments_array_t as in Rte_Type.h]
                        pSLATE_NaviData->Segments[i].f_AnglePrevBranch                  [-180 ... 180] degree
                        pSLATE_NaviData->Segments[i].f_Length                           [0 ... 250] m
                        pSLATE_NaviData->Segments[i].ExitSegments                       [Exit Segments_array_t as in Rte_Type.h]
                          pSLATE_NaviData->Segments[i].ExitSegments[0].u_SegmentID      [0 ... MAX uint16]     
                          pSLATE_NaviData->Segments[i].ExitSegments[0].f_Angle          [-180 ... 180] degree

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY : Calculate probability that ego veh will not follow navi path

  @pre             -
  @post            -

  @created         30.03.2017
  @changed         -

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 (69) 67869-6110
*************************************************************************************************************************/
uint8 FIP_u_UpdateBranchProbability(void)
{
  uint8 u_DummyBranchPrev = 0; 
  return u_DummyBranchPrev;
}
#endif /* ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY)) */

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetCameraObjData                                                           */ /*!

  @brief           Updating FIP camera object data and camera object External ID from camera information.

  @description     Updating FIP camera object data and camera object External ID from camera information.

  @startuml 
  Partition FIP_v_SetCameraObjData
  Start
    Note right: This function updates FIP camera object data and camera object External ID from camera information
    - Map the FIP Turn Light State with Camera Turn Light State
    - Map the FIP Brake Light state with Camera Brake Light state
    - Map the FIP object lane association with Camera object lane association
    - Map the FIP object maneuver state with Camera based object maneuver state
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pSLATE_FusionObjList->aObject[ObjNr].CamData : Camera object infromation from fusion object list.
  @glob_in         pSLATE_CameraObjData->CustObjects[ObjNr].u_ExternalID_Cam : Custom object external ID.
  
  @glob_out        pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData : Initialization of camera object data.
  @glob_out        pt_FIP_OA_Output->t_ObjList[ObjNr].u_ExternalID_Cam : Initialization of camera object External ID.

  @c_switch_part   OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT : Internal configuration switch enabling custom object width output.
  @c_switch_part   OUT_CFG_USE_ME_CLASS_DIRECTLY : Internal configuration switch to directly access ME input structure to 
           output ME object class based wide object output.

  @c_switch_full   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object detection inputs

  @pre             -
  @post            -

  @created         15.02.2017
  @changed         07.12.2017

  @author          Ajay Talakadu | Ajay.Talakadu@continental-corporation.com | +91 (80) 6679-1170
*************************************************************************************************************************/
void  FIP_v_SetCameraObjData(FIP_OA_Output_t * pt_FIP_OA_Output, const ObjNumber_t ObjNr)
{
  FIP_t_CamAssociatedLane t_CamAssociatedLane;
  FIP_t_CamTurnLightsState t_CamTurnLightsState;
  FIP_t_CamBrakeLight t_CamBrakeLight;
  FIP_t_CamObjManeuver t_CamObjManeuver;

  pt_FIP_OA_Output->t_ObjList[ObjNr].u_ExternalID_Cam = (uint8)pSLATE_FusionObjList->aObject[ObjNr].uiSensorObjID[0];
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_CamConfirmationProb = (percentage_t)pSLATE_FusionObjList->aObject[ObjNr].uiSensorConfirmation[0];
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssignedLaneQual = pSLATE_FusionObjList->aObject[ObjNr].CamData.percentageOwnDrivingLane;
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssLaneLeftQual = pSLATE_FusionObjList->aObject[ObjNr].CamData.percentageSideDrivingLaneLeft;
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_AssLaneRightQual = pSLATE_FusionObjList->aObject[ObjNr].CamData.percentageSideDrivingLaneRight;

  /* Map Turn lights of FIP with RTE */
  switch (pSLATE_FusionObjList->aObject[ObjNr].CamData.eStatusTurnIndicator)
  {
  case EM_CAM_OBJ_TURN_INDICATOR_NO_FLASHING : 
    t_CamTurnLightsState = FIP_CAM_TURN_LIGHT_OFF;
    break;
  case EM_CAM_OBJ_TURN_INDICATOR_FLASHING_LEFT : 
    t_CamTurnLightsState = FIP_CAM_TURN_LIGHT_LEFT;
    break;
  case EM_CAM_OBJ_TURN_INDICATOR_FLASHING_RIGHT : 
    t_CamTurnLightsState = FIP_CAM_TURN_LIGHT_RIGHT;
    break;
  case EM_CAM_OBJ_TURN_INDICATOR_HAZARD_FLASHING : 
    t_CamTurnLightsState = FIP_CAM_TURN_LIGHT_HAZARD;
    break;
  case EM_CAM_OBJ_TURN_INDICATOR_UNKNOWN : 
  default:
    t_CamTurnLightsState = FIP_CAM_TURN_LIGHT_UNKNOWN;
    break;
  } /* END of Switch for eTurnLightsState */
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eTurnLightsState = t_CamTurnLightsState;

  /* Map Brake Light State of FIP with correct RTE signal */
  switch (pSLATE_FusionObjList->aObject[ObjNr].CamData.eStatusBrakeLight)
  {
  case EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING : 
    t_CamBrakeLight = FIP_CAM_BRAKE_LIGHT_OFF;
    break;
  case EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING : 
  case EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING : 
    t_CamBrakeLight = FIP_CAM_BRAKE_LIGHT_ON;
    break;
  case EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN : 
  default:
    t_CamBrakeLight = FIP_CAM_BRAKE_LIGHT_UNKNOWN;
    break;
  } /* END of Switch for eTurnLightsState */
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eBrakeLight = t_CamBrakeLight;
  
  /* Map camera object lane association of FIP with correct RTE signal */
  switch (pSLATE_FusionObjList->aObject[ObjNr].CamData.eAssociatedLane)
  {
  case EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT:
    t_CamAssociatedLane = FIP_CAM_ASSOC_LANE_FAR_LEFT;
    break;
  case EM_CAM_OBJ_ASSOC_LANE_LEFT :
    t_CamAssociatedLane = FIP_CAM_ASSOC_LANE_LEFT;
    break;
  case EM_CAM_OBJ_ASSOC_LANE_EGO :
    t_CamAssociatedLane = FIP_CAM_ASSOC_LANE_EGO;
    break;
  case EM_CAM_OBJ_ASSOC_LANE_RIGHT :
    t_CamAssociatedLane = FIP_CAM_ASSOC_LANE_RIGHT;
    break;
  case EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT:
    t_CamAssociatedLane = FIP_CAM_ASSOC_LANE_FAR_RIGHT;
    break;
  case EM_CAM_OBJ_ASSOC_LANE_UNKNOWN:
  default :
    t_CamAssociatedLane = FIP_CAM_ASSOC_LANE_UNKNOWN;
    break;
  } /* END Switch for eAssociatedLane */
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eAssociatedLane = t_CamAssociatedLane;
  
  /* Map camera based object object maneuver state of FIP with correct RTE signal */
  switch (pSLATE_FusionObjList->aObject[ObjNr].CamData.eLaneChangeManeuver)
  {
  case EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT :
  case EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT : 
    t_CamObjManeuver = FIP_CAM_OM_CUT_IN;
    break;
  case EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT : 
  case EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT : 
    t_CamObjManeuver = FIP_CAM_OM_CUT_OUT;
    break;
  case EM_CAM_OBJ_LANE_CHANGE_NONE :
  default:
    t_CamObjManeuver = FIP_CAM_OM_NONE;
    break;
  } /* END of Switch eObjManeuver */
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.eObjManeuver = t_CamObjManeuver;

#if ((OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT) && (OUT_CFG_USE_ME_CLASS_DIRECTLY))
  pt_FIP_OA_Output->t_ObjList[ObjNr].t_CamObjectData.t_CamConfirmationProb = (percentage_t)pSLATE_FusionObjList->aObject[ObjNr].uiSensorConfirmation[0];
  pt_FIP_OA_Output->t_ObjList[ObjNr].u_ExternalID_Cam = (uint8)pSLATE_FusionObjList->aObject[ObjNr].uiSensorObjID[0];
#endif

#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  pt_FIP_OA_Output->t_ObjList[ObjNr].f_CamOverlapDst = FIP_f_GetObjOverlapFromCamera(ObjNr);  
  pt_FIP_OA_Output->t_ObjList[ObjNr].f_CamObjWidth = pSLATE_EmCustObjList->CustObjects[ObjNr].CamObjectData.f_CamWidth ;  
#endif /*FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL*/


}
#endif /* FCT_CFG_INCLUDE_FUSION_OBJECT_LIST */
#endif /* END IF (FCT_CFG_CAMERA_OBJECT_DETECTION) */

#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
/*************************************************************************************************************************
  Functionname:    FIP_f_GetObjOverlapFromCamera                                                                        */ /*!

  @brief           Calculates object lateral overlap distance with ego lane based on custom camera signals

  @description     Calculates object overlap distance with ego lane based on custom camera input signals.
                   Two overlap angles are used to calculate the overlap distance. If one of the signals is not available it is compensated and filtered.
                   The function resturns overlap distance with ego lane [m]. In case the result could not be calculated invalid value out of range is set FIP_CAM_INVALID_OVERLAP_DST

  @return          float32  f_overlap_dst_result : function result, object overlap distance with ego lane [m]
                                                   The value is positive when object /part of the object occupies ego lane.
                                                   The valie is negative when object is outside ego lane.
                                                   If the result is set to FIP_CAM_INVALID_OVERLAP_DST, the result is not valid.

  @param[in]       ObjNumber_t iCurObj : object ID for overlap calculation, shall be a moving ooi object

  @glob_in         pSLATE_EmCustObjList->CustObjects[i].CamObjectData.f_ObjLineCoverAngleR : Object angle overlap between right ego lane border and left rear object corner. 
                                                                                              Positive if left rear object corner is right to right ego lane border [rad]
                   pSLATE_EmCustObjList->CustObjects[i].CamObjectData.f_ObjLineCoverAngleL : Object angle overlap between left ego lane border and right rear object corner. 
                                                                                              Positive if right rear object corner is right to left ego lane border [rad]
                   t_FIP_ALL_Output.t_FIP_CL_Output.f_VisibilityDist : Camera longitudinal visability [m]
                   t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iCurObj].f_Cam_overlap_diff_left_and_right : difference between left to right overlap value [m]
                   t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iCurObj].u_Cam_overlap_compensation_cnt :  offset validity counter  [0 .. FIP_CAM_VALID_OFFSET_CNT_INIT]

  @glob_out        t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iCurObj].f_Cam_overlap_diff_left_and_right : difference between left to right overlap value [m]
                   t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iCurObj].u_Cam_overlap_compensation_cnt :  offset validity counter  [0 .. FIP_CAM_VALID_OFFSET_CNT_INIT]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_CAMERA_CUTIN_POTENTIAL  : Camera based cut-in probability for ooi lane association, or
  @c_switch_full   FCT_CFG_CAMERA_CUTOUT_POTENTIAL : Camera based cut-out probability for ooi lane association

  @pre             -
  @post            -

  @created         03.04.2017
  @changed         27.04.2017

  @author          Piotr Pelechaty |FIP_v_InitCustInternalData piotr.pelechaty@conti-engineering.com | +49 69 67869 6110
*************************************************************************************************************************/
float32 FIP_f_GetObjOverlapFromCamera(const ObjNumber_t iCurObj)
{
  float32 f_overlap_dst_result = 0.F;
  _PARAM_UNUSED(iCurObj);
  return f_overlap_dst_result;
}
#endif /*(FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)*/

/*************************************************************************************************************************
  Functionname:    FIP_v_Set_CustomTrafficOrientation                                                               */ /*!

  @brief           Set Custom Traffic Orientation signals

  @description     Set Custom Traffic Orientation signals using the fip fused traffic orientation

                    @startuml
                        Start
                            Partition FIP_v_Set_CustomTrafficOrientation {
                                - Set Custom Traffic Orientation signals
                            }
                        End
                    @enduml

  @return          -

  @param[in]       - 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @created         14.04.2016
  @changed         25.04.2018

  @author          Gangadhar Badiger | gangadhar.badiger@continental-corporation.com | +91 (80) 6679-6105
*************************************************************************************************************************/
void FIP_v_Set_CustomTrafficOrientation(FIP_TO_Output_t * pt_FIP_TO_Output)
{
  _PARAM_UNUSED(pt_FIP_TO_Output);
}

#if (FCT_CFG_TJA_OBJECT_TRACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_OutputTrajectoryCustomData                                                                 */ /*!

  @brief           Output of Trajectory to Custom Port

  @description     Output of Object Trace Trajectory to Custom Port

  @startuml 
  Partition FIP_v_OutputTrajectoryCustomData
  Start
    - Provides Output of Object Trace Trajectory to Custom Port
  Stop
  @enduml

  @return          -

  @param[in]       pObjTrajs : Pointer to Object Trace Trajectory structure
                       uiTrajsCount : Number of valid trajectories in following array [0u ... FIP_TRACE_NO_OF_TRACES[
                   ObjTrajects[i] : Array of Trace Trajectory structures with i in [0u ... FIP_TRACE_NO_OF_TRACES[
                       tObjNum : FCT ID of trajectory object [0u ... EM_N_OBJECTS[ for i in [0u ... FIP_TRACE_NO_OF_TRACES[
                       fLength : Valid length [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                       fPosX0 : Min X-Position [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                       fPosY0 : Y-Position at X=0 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       fAngle : Slope at X=0 [-PI/2 ... PI/2] rad
                       fCurveC0 : Curvature at X=0 [-1.0 ... 1.0] 1/m
                       fCurveC1 : Change of Curvature [-1.0 ... 1.0] 1/m^2
                       fPosY0Dev : Standard Deviation of Y-Position [full range of datatype float32]
                       fAngleDev : Standard Deviation of Slope [full range of datatype float32]
                       fCurveC0Dev : Standard Deviation of Curvature [full range of datatype float32]
                       fCurveC1Dev : Standard Deviation of Curvature change [full range of datatype float32]
  @param[in]       tTimeStamp : Timestamp [AlgoDataTimeStamp_t as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_TJA_OBJECT_TRACE : FCT support for Object Trace Preprocessing (FIP)
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @created         04.04.2016
  @changed         04.04.2016

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
void FIP_v_OutputTrajectoryCustomData(const FIP_ObjTraceTrajectory_t* const pObjTrajs, AlgoDataTimeStamp_t tTimeStamp)
{
  _PARAM_UNUSED (pObjTrajs);
  _PARAM_UNUSED (tTimeStamp);
}
#endif /*!< FCT_CFG_TJA_OBJECT_TRACE */

#if (SLATE_CFG_CAM_LANE_INTERFACE)
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
/*************************************************************************************************************************
  Functionname:    FIP_b_CamLaneExistanceProb                                                               */ /*!

  @brief           Get camera lane existance 

  @description     checks camera lane existance probability and return camera lane existance (right or/and left)

                    @startuml
                        Start
                            Partition FIP_b_CamLaneExistanceProb {
                                If(Signal status and Left and Right Camera lane probability higher than threshould) then (Ture)
                                    - the camera lane is cosidere as valid
                                Else (False)
                                    - the camera lane is cosidere as invalid
                                endif
                            }
                        End
                    @enduml

  @return         Camera Lane existance

  @param[in]       - 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         06.06.2018
  @changed         

  @author          Dyamana.gouda|Dyamana.gouda@continental-corporation.com | +91 (80) 6679-8429
*************************************************************************************************************************/
boolean FIP_b_CamLaneExistanceProb(void)
{
	boolean ret = FALSE;
	if( 
		(pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
		( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
		  (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) )
	  )
	{
		ret = TRUE;
	}
	
	return ret;
}
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
#endif /*!< SLATE_CFG_CAM_LANE_INTERFACE */

/*****************************************************************************
  STATIC FUNCTIONS
*****************************************************************************/

///@}
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
