/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 ACC_LA (Adaptive Cruise Control - Lane Association)

PACKAGENAME:               la_camera_lane_assoc.c

DESCRIPTION:               This is the main file for implementation of camera-based lane association

AUTHOR:                    Grant Davtjan (uidg3349)

CREATION DATE:             

VERSION:                   $Revision: 1.16 $


  ---*/ /*---
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_camera_lane_assoc LA camera lane association
@ingroup la_laneassociation
@brief          Check if object is associated to ego lane or adjacent lane based on the camera information \n\n

@{

*/
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
/*! Check if object is associated to ego lane based on the camera information */
#define LA_OBJ_LONG_DIST_CAM_LANE_ASSO_MAX    (80.f)
#define LA_CAM_LANE_VISIBILITY_RANGE_FAC_MIN  (0.5f)

#if (LA_CFG_CAM_INLANE_STABLE_SELECTION)
/* Counter (0.18 seconds) for which the camera lane related inputs must satisfy the set threshold */
#define LA_CAM_INLANE_COUNTER_THRESHOLD       (3u)
#endif /* END IF LA_CFG_CAM_INLANE_STABLE_SELECTION */

#if LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE
#define LA_EGO_LANE_CHANGE_THR_CAM_INLANE     (20u)
#endif /*end of LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE*/

#if LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR
/*Ego lane change limited to 4s i.e LA_EGO_LANE_CHANGE_LIMITER = (LA_EGO_LANE_CHANGE_IND_TIMER_MAX-4)
  below value must also be updated if LA_EGO_LANE_CHANGE_IND_TIMER_MAX changed. Calculated as above*/
#define LA_EGO_LANE_CHANGE_LIMITER           (1.5f)
#endif /* end of LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR */

/*****************************************************************************
  FUNCTION
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    LA_b_CheckCameraObjAssoToEgoLane                                                                 */ /*!

  @brief           Check if object is associated to ego lane based on the camera information

  @description     Check if object is associated to ego lane based on the camera information
  
  @startuml
  Partition CheckCameraObjAssoToEgoLane{
  Start
  : Get quality of assigned ego lane association for object;
  : Get longitudinal displacement of object;
  : Get Cam Lane object Association;
  : Get Camera lane visibility distance, Object Dynamic Property, LC Phase,\n Left and right OOI;
  If (No lanechange AND Left or Right\n OOI AND Object is moving) then (TRUE)
  If (quality of assigned ego lane is more than\n minimal ego lane threshold) then (TRUE)
  : Set quality of assigned ego lane flag;
  Else (FALSE)
  Endif
  Else (FALSE)
  If (quality of assigned ego lane is more than\n ego lane threshold) then (TRUE)
  : Set quality of assigned ego lane flag;
  Else (FALSE)
  Endif
  Endif
  If (quality of assigned ego lane is more than threshold AND\n Camera lane object accociation is valid AND\n Object Longitudinal displacement is less than Maximum Longitudinal displacement OR\n Camera lane visibility distance is high) then (TRUE)
  : Increment the Camera Inlane Counter value by 1;
  : Set Inlane Camera value to true;
  Else (FALSE)
  : Reset the Camera Inlane Counter;
  : Set Inlane Camera value to false;
  Endif
  If (Inlane Counter is more than Threshold) then (TRUE)
  : Set the Inlane Camera value to true and limit the Counter value to set threshold;
  Else (FALSE)
  : Set the Inlane Camera value to false;
  Endif
  : Return Inlane Camera value;
  End
  }
  @enduml

  @return          TRUE if object is associated to ego lane [TRUE, FALSE]

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_FIPOA.pt_AssignedLaneQual(i) : Quality of the assigned ego lane association for object i 
                      provided by the camera  [percentage_t as defined in Rte_type.h]       

  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].u_CamInlaneCounter : Inlane counter based on Camera

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   LA_CFG_CAM_INLANE_STABLE_SELECTION : Configuration switch which enables the Counter which checks the 
                                                        validation of camera lane inputs for 0.18 sec before associating objects to Ego lane
  @c_switch_full   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.02.2016
  @changed         11.02.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
boolean LA_b_CheckCameraObjAssoToEgoLane(const ObjNumber_t iObj)
{
  boolean bInlaneCamValue;
  percentage_t t_AssignedLaneQual = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_AssignedLaneQual;
  float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
#if (LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR)
  float32 f_IndTimeLeft = pt_LAOutput->f_TurnIndLeftTime;
  float32 f_IndTimeRight= pt_LAOutput->f_TurnIndRightTime;
#endif /*end of LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR*/
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
  const boolean b_CamLaneObjAssocValid = (pt_LAInput->pt_FIPCamLane->b_CamLaneAssocValid);/*!< Info if camera lane object association is valid */
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
  const float32 f_CamLaneVisibilityDist= (pt_LAInput->pt_FIPCamLane->f_VisibilityDist);/*!< Visibility distance of camera lane */
#endif

#if (LA_CFG_LIMIT_CAM_LANE_GATE_PICKUP)
  boolean t_AssignedLaneQual_flag = FALSE;
  const SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj);
  const SIT_LC_t_LaneChangePhaseEnum t_LCPhase = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase;
  const ObjNumber_t t_LeftOOI = (*pt_LAInput->t_OOI.pu_OOIListObjId(OBJ_NEXT_LONG_LEFT_OOI));
  const ObjNumber_t t_RightOOI = (*pt_LAInput->t_OOI.pu_OOIListObjId(OBJ_NEXT_LONG_RIGHT_OOI));

  if( ( t_LCPhase !=  LC_NO_LANECHANGE) && 
      ((t_LeftOOI == iObj) || (t_RightOOI == iObj)) && 
      ((t_ObjDynamicProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
    && (t_ObjDynamicProperty != SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
      )
    )    
  {
    if (t_AssignedLaneQual > LA_PAR_CAM_LANE_ASSIGN_MIN_GATE_PICKUP)
    {
      t_AssignedLaneQual_flag = TRUE;
    }
  }
  else
  {
    if (t_AssignedLaneQual > LA_PAR_CAM_LANE_ASSIGN_GATE_PICKUP)
    {
      t_AssignedLaneQual_flag = TRUE;
    }
  }

  if ( (t_AssignedLaneQual_flag)
#else
  if ( (t_AssignedLaneQual > LA_PAR_CAM_LANE_ASSIGN_GATE_PICKUP)
#endif/* LA_CFG_LIMIT_CAM_LANE_GATE_PICKUP */
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
    && (b_CamLaneObjAssocValid == TRUE)
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
#if (LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE)
    && (( pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb <= LA_EGO_LANE_CHANGE_THR_CAM_INLANE ))
#endif /*end of LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE*/
#if LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR
    &&  ( ( ( f_IndTimeLeft < LA_EGO_LANE_CHANGE_LIMITER) && ( f_IndTimeRight < LA_EGO_LANE_CHANGE_LIMITER) ) )
#endif /* end of LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR */
#endif
    && ( (f_ObjLongDisp <= LA_OBJ_LONG_DIST_CAM_LANE_ASSO_MAX)
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
      || (f_CamLaneVisibilityDist >= (LA_CAM_LANE_VISIBILITY_RANGE_FAC_MIN * f_ObjLongDisp))
#endif
       )
     )
  {
#if (LA_CFG_CAM_INLANE_STABLE_SELECTION)
    /*  If the above conditions are satisified, Increment the Camera Inlane Counter value by 1 */
    pt_LAOutput->t_LAObjOutputList[iObj].u_CamInlaneCounter += 1u;
#else
    bInlaneCamValue = TRUE;
#endif /* END IF LA_CFG_CAM_INLANE_STABLE_SELECTION */
  }
  else
  {
#if (LA_CFG_CAM_INLANE_STABLE_SELECTION)
    /* If above conditions are not satisified, Reset the Camera Inlane Counter */
    pt_LAOutput->t_LAObjOutputList[iObj].u_CamInlaneCounter = 0u;
#else
    bInlaneCamValue = FALSE;
#endif /* END IF LA_CFG_CAM_INLANE_STABLE_SELECTION */
  }

#if (LA_CFG_CAM_INLANE_STABLE_SELECTION)
  if (pt_LAOutput->t_LAObjOutputList[iObj].u_CamInlaneCounter >= LA_CAM_INLANE_COUNTER_THRESHOLD)
  {
    /* If Counter value is greater than the counter threshold (Indicates that camera related inputs are consistent for 0.18 sec
       Set the bInlaneCamValue to TRUE and limit the Counter value to set threshold so that overflow is taken care */
    bInlaneCamValue = TRUE;
    pt_LAOutput->t_LAObjOutputList[iObj].u_CamInlaneCounter = LA_CAM_INLANE_COUNTER_THRESHOLD;
  }
  else
  {
    bInlaneCamValue = FALSE;
  }
#endif /* END IF LA_CFG_CAM_INLANE_STABLE_SELECTION */

  return bInlaneCamValue;
}


/*************************************************************************************************************************
  Functionname:    LA_b_CheckCameraObjAssoToOutLane                                                                 */ /*!

  @brief           Check if object is associated to adjacent lane based on the camera information

  @description     Check if object is associated to adjacent lane based on the camera information

  @startuml
  Partition CheckCameraObjAssoToOutLane{
  Start
  : Get Quality of the assigned left and right lane association,\n Object Longitudinal displacement,
  : Get Valid Camera lane Object Association, Camera lane visibility distance;
  If (Quality of the assigned left OR right lane association\n is more than Pickup threshold AND\n Logitudinal displacement is less than maximum displacement OR\n Camera lane visibility is more than Minimum visibility) then (TRUE)
  : Set Outlane camera value to true;
  Else (FALSE)
  : Set Outlane camera value to false;
  Endif
  : Return Outlane camera value;
  End
  }
  @enduml

  @return          TRUE if object is associated to left or right lane [TRUE, FALSE]

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_FIPOA.pt_AssLaneLeftQual(i) : Quality of the assigned left lane association for object i
                      provided by the camera [percentage_t as defined in Rte_type.h]
  @glob_in         pt_LAInput->t_FIPOA.pt_AssLaneRightQual(i) : Quality of the assigned right lane association for object i
                      provided by the camera [percentage_t as defined in Rte_type.h]
  @glob_out        -

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.02.2016
  @changed         11.02.2016

  @author          Thomas Bock | Thomas.2.Bock@continental-corporation.com | +49 (8382) 9699-755
*************************************************************************************************************************/
boolean LA_b_CheckCameraObjAssoToOutLane(const ObjNumber_t iObj)
{
  boolean bOutlaneCamValue;
  percentage_t t_AssLaneLeftQual = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_AssLaneLeftQual;
  percentage_t t_AssLaneRightQual = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_AssLaneRightQual;
  float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
  #if LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR
  float32 f_IndTimeLeft = pt_LAOutput->f_TurnIndLeftTime;
  float32 f_IndTimeRight= pt_LAOutput->f_TurnIndRightTime;
  #endif /*end of LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR*/

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
  const boolean b_CamLaneObjAssocValid = (pt_LAInput->pt_FIPCamLane->b_CamLaneAssocValid);/*!< Info if camera lane object association is valid */
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
  const float32 f_CamLaneVisibilityDist= (pt_LAInput->pt_FIPCamLane->f_VisibilityDist); /*!< Visibility distance of camera lane */
#endif

  if ( ( (t_AssLaneLeftQual > LA_PAR_CAM_LANE_ASSIGN_GATE_PICKUP)
      || (t_AssLaneRightQual > LA_PAR_CAM_LANE_ASSIGN_GATE_PICKUP)
       )
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
    && (b_CamLaneObjAssocValid == TRUE)
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
#if LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE
    && (( pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb <= LA_EGO_LANE_CHANGE_THR_CAM_INLANE ))
#endif /*end of LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE*/
#if LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR
    &&  (  ( ( f_IndTimeLeft < LA_EGO_LANE_CHANGE_LIMITER) && ( f_IndTimeRight < LA_EGO_LANE_CHANGE_LIMITER) ) )
#endif /*end of LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR*/
#endif
    && ( (f_ObjLongDisp <= LA_OBJ_LONG_DIST_CAM_LANE_ASSO_MAX)
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
      || (f_CamLaneVisibilityDist >= (LA_CAM_LANE_VISIBILITY_RANGE_FAC_MIN * f_ObjLongDisp))
#endif
      )
    )
  {
    bOutlaneCamValue = TRUE;
  }
  else
  {
    bOutlaneCamValue = FALSE;
  }

  return bOutlaneCamValue;
}
/** @} end defgroup */
#endif /* (FCT_CFG_CAMERA_OBJECT_DETECTION) */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */
