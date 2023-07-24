/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_laneassociation_stateflow.c

DESCRIPTION:               It is subsidiary file of la_laneassociation.c which during each cycle calculates 
                           state flow for all the objects which determines whether the object is associated to 
                           ego lane or adjacent lanes. During each cycle state/association of all the objects to 
                           ego lane/adjacent lane is checked depending on different parameters like position, 
                           prediction, inlane timers, inlap/overlap of object to ego lane.

                           This also determines if the object was previously in ego lane is it still associated to ego lane or
                           making a transition to adjacent lane. similarly, if object was previously was in adjacent lane check 
                           if it is making a transition towards ego lane. Hence, the state of the object is determined during each 
                           cycle for lane association purpose

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             -

VERSION:                   $Revision: 1.14 $

LEGACY VERSION:            Revision: 2.2
  
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_laneassociation_stateflow LA stateflow
@ingroup la_laneassociation
@brief          calculates state flow for all the objects which determines whether the object is associated to 
                ego lane or adjacent lanes. \n\n

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
#define LA_IN2OUTLANE_MAX_TRANSITIONTIME (42u)  /*!< 42 cycles, that means about three seconds */

/*! Check if object is associated to ego lane based on the camera information */
#if(FCT_CFG_CAMERA_OBJECT_DETECTION)
#define LA_OBJ_LONG_DIST_CAM_LANE_ASSO_MAX    (70.f)
#define LA_CAM_LANE_VISIBILITY_RANGE_FAC_MIN  (0.5f)
#endif

/*! Parameters to determine when a stationary object is not selected as OOI 
    since it is an oncoming and stopped object */

/*! Minimum speed-sum (obj_v_rel + v_ego) for an oncoming object to become relevant */
#define LA_PAR_SPEED_SUM_ROLL_BACK_MIN           (-15.F/C_KMH_MS)

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/


#if 1
#endif

/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjLaneQuality                                                                         */ /*!

  @brief           Checks, if an object passes base-preselection and thus may be assigned to a lane. 

  @description     Checks, if an object passes base-preselection and thus may be assigned to a lane.
                   Base-preselection includes checks for sufficient ACC-quality and TimeGap-Criterion
                   If the function returns 'FALSE' then the object's lane must be set to ASSOC_LANE_UNKNOWN
                   @startuml
                   Partition LA_b_CheckObjLaneQuality {
                   Start
                   -Checks, if an object passes base-preselection and thus may be assigned to a lane
                   End
                   }
                   @enduml

  @return          boolean , TRUE if object may be associated to lane (ego-, left-, far-right-lane, etc...)
                             FALSE if object's lane must be set to unknown                                      [TRUE or FALSE]

  @param[in]       s_Obj : object for which lane associatability is checked. ObjNumber_t defined in Rte_type.h, [ 0 ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->LABasePreselObjList : of type BasePreselObjList_t, defined in la_ext.h                      [TRUE or FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    299:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-299-00061542 \n

  @created         -
  @changed         3/23/2016

  @todo            -

  @author          Thomas Bock | Thomas.2.Bock@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
boolean LA_b_CheckObjLaneQuality(const ObjNumber_t s_Obj)
{
  boolean b_Ret = TRUE;
  /*  Objects which do not pass base pre-selection, may not be associated to a lane */
  if (pt_LAOutput->LABasePreselObjList[s_Obj] == FALSE)
  {
    b_Ret = FALSE;
  }
  return b_Ret;
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjOncRollBack                                                                         */ /*!

  @brief           Checks, if an oncoming object is allowed to be set on host lane.

  @description     Checks, if an oncoming object is allowed to be set on host lane.
                   Oncoming (AND NOT crossing) objects may only be set on ego-lane 
                   in case of the special 'relevant object rolling back' situation, 
                   which is defined as follows:
                    - Object was moving at some time
                    - Object is already selected as relevant object
                    - Object's longitudinal distance is less than 25m
                    - Object's relative vehicle speed plus ego speed is greater 
                      than -15 km/h
                   If the function returns 'FALSE' then that effectively prevents 
                   the oncoming object from becoming relevant.
                   @startuml 
                   partition LA_b_CheckObjOncRollBack {
                   Start
                     if(object is on coming and object is not crossing) then (yes)
                       if(the base associated lane in associated ego lane) then (yes)
                   	   if(Object is moving at some time and
                   	   Object is already selected as relevant object and
                   	   Object's longitudinal distance is less than Maximum X distance for an oncoming object to become relevant and Sum of Object's relative vehicle speed and ego speed is greater than  Minimum speed sum of Object's relative vehicle speed and ego speed for an oncoming object to become relevant
                   ) then (yes)
                   	     -Return True as object passes the check and thus is allowed to be set on ego lane
                   	   else
                   	     -Return False as object is not passes the check and thus is allowed to be set on ego lane
                   
                   	   endif	
                   	 endif
                     endif
                   end
                   }
                   @enduml

  @return          boolean : TRUE if object passes the check and thus is allowed to be set 
                   on ego lane.                                                               [TRUE or FALSE]

  @param[in]       s_Obj : object, which is checked for special 'relevant object 
                   rolling back' situation. ObjNumber_t defined in Rte_type.h,                [ 0 ... EM_N_OBJECTS-1]
  @param[in]       e_BaseAssocLane : the base associated lane without quality considerations. [eAssociatedLane_t, defined in Rte_Type.h]

  @glob_in         *SLATE_pt_GetObjDynProperty   : Dynamic property of an object                     [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in         *SLATE_pt_GetObjDynSubProperty :  Dynamic sub property of an object              [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsRelevant : Returns wheather the object is relevant or not.         [0 or 1, as defined in fct_sen.h]
  @glob_in         pt_LAInput->t_FIPOA.pt_ObjBool(s_Obj)->bit_ObjWasMoving : Info if object was moving once          [0 or 1, as defined in si_ext.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync :  ego speed                                          [-330.f ... 330.f]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : Longitudinal displacement of the object            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX : Longitudinal relative velocity                             [-330.f ... 330.f]
  @glob_out        -

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             Checked object is valid
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/23/2016

  @todo            -

  @author          Thomas Bock | Thomas.2.Bock@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
 boolean LA_b_CheckObjOncRollBack(const ObjNumber_t s_Obj,  const eAssociatedLane_t e_BaseAssocLane)
{
  float32 f_ObjDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(s_Obj);
  float32 f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(s_Obj);
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  boolean b_Ret = TRUE;
  boolean b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(s_Obj);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(s_Obj);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SLATE_t_Obj_DynamicSubProperty t_ObjDynSubProperty = *SLATE_pt_GetObjDynSubProperty(s_Obj);
#endif
  /* Only oncoming (AND NOT crossing) objects are considered in this check */
  if ( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
     &&(t_ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING)
#endif
     )
  {
  /* Handling for oncoming ego lane objects: These may only return true for the special 'relevant
     object rolling back' situation, as described above */
    if (e_BaseAssocLane == ASSOC_LANE_EGO)
    {
      if ( (pt_LAInput->pt_FIPOA->t_ObjList[s_Obj].t_Bool.bit_ObjWasMoving == (ubit8_t)1u)
#if (LA_CFG_DTR_OBJ_SELECTION == SWITCH_OFF)
          &&(b_ObjIsRelevant == TRUE)
#endif
          &&(f_ObjDistX < FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX)
          &&((f_ObjVrelX + f_EgoVelObjSync) > LA_PAR_SPEED_SUM_ROLL_BACK_MIN)
         )
      {
        b_Ret = TRUE;
      }
      else
      {
        b_Ret = FALSE;
      }
    }
  }
  return b_Ret;
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjAdjLaneValidity                                                                     */ /*!

  @brief           Checks the validity of the associated neighboring lane for OOI-selection.

  @description     Checks, if the base associated lane (without quality considerations)
                   is valid regarding the OOI-selection on adjacent lanes. Moving and 
                   stationary objects with invalid lane assignment or oncoming objects 
                   beyond the road border will not be considered in OOI-selection.

                   The conditions for a TRUE return value are defined as follows:
                    - Moving (OR Crossing):
                     - Valid lane based on lane matrix OR
                     - Object is already in OOI-list OR
                     - Object confirmed by camera OR
                     - Object is classified as Bike or Motorcycle 
                       and located within estimated road border 
                   - Stationary (AND NOT Crossing):
                     - Valid lane based on lane matrix OR
                     - Object is already in OOI-list OR
                     - Object confirmed by camera
                   - Oncoming (AND NOT crossing):
                     - Object is located within estimated road border OR
                     - Road border estimation is too uncertain

                   If the function returns 'FALSE' then this effectively prevents 
                   the object from becoming an OOI on one of the adjacent lanes.
                   @startuml 
                   partition LA_b_CheckObjAdjLaneValidity {
                   Start
                     if(the base associated lane is associated to left lane) then (yes)
                       -Get number of lanes based on FCT Input Preprocessing Management
                   	 if(road estimation is reliable enough) then (yes)
                   	  -Set left bicycle clip distance to road border distance
                   	 else
                          -set left bicycle clip distance to default distance
                        endif	   
                     elseif(the base associated lane is associated to right lane) then (yes)
                       if(road estimation is reliable enough) then (yes)
                   	  -Set Right bicycle clip distance to road border distance
                   	 else
                          -set Right bicycle clip distance to default distance
                        endif
                     else
                       -set Number Of Lanes to 1
                     endif
                     
                     if(Object is moving or crossing) then (yes)
                       -Verify that there is a valid adjacent lane based on the lane matrix or the object was already OOI,or it is confirmed by the camera (thus definitely not a mirror or ghost). Moving objects, which are classified as bike or motorcycle are also selectable as OOI, even if there is no valid lane based on lane matrix. For all other moving objects this is actually a mirror suppression
                      elseif(object is stationary or stopped) then (yes)
                        - Verify that there is a valid adjacent lane based on the lane matrix or the object was already OOI, or it is confirmed by the camera thus definitely not a mirror or ghost
                      elseif(object is oncoming) then (yes)
                        if(checks the validity of adjacent lanes) then (yes)
                   	   -set the return value TRUE
                   	 elseif(Check objects on left adjacent lane including objects, that are not associated to left lane , but which are on the left side of the ego-course) then (yes)
                   	    -Return value is set TRUE, if the oncoming object on the left adjacent lane is located within the estimated road border or if the road border estimation is not reliable enough. Oncoming objects located behind the guard rail will be ignored in OOI-selection. 	
                   	 elseif(objects on right adjacent lane including objects, that are not associated to right lane, but which are on the right side of the ego-course) then (yes)
                   	 -Return value is set TRUE, if the oncoming object on the left adjacent lane is located within the estimated road border or if the road border estimation is not reliable enough. Oncoming objects located behind the guard rail will be ignored in OOI-selection.
                   	 else
                   	 endif
                     endif
                     
                   end
                   }
                   @enduml

  @return          boolean  : TRUE if object passes the check and thus is allowed to be set on right/left lane         [TRUE or FALSE]

  @param[in]       s_Obj : object, which is checked for a valid adjacent lane. ObjNumber_t defined in Rte_type.h,      [ 0 ... EM_N_OBJECTS-1]
  @param[in]       e_BaseAssocLane : the base associated lane without quality considerations.                          [eAssociatedLane_t, defined in Rte_Type.h]
  
  @glob_in         OBJ_GET_OBJ_TO_REF_DISTANCE                                                                         [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft : Left road border status                                         [0u ... 100u]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight : Right road border status                                       [0u ... 100u]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Distance up to which road estimation on left side is available    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Distance up to which road estimation on right side is available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         *SLATE_pt_GetObjDynProperty   : Dynamic property of an object                                              [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in         *SLATE_pt_GetObjDynSubProperty :  Dynamic sub property of an object                                       [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         t_OOI_ObjectList().t_Bool.AlreadyOOI : Status flag to check whether given object is already OOI             [ubit32_t type as defined in algo_type.h]  [0 or 1]
  @glob_in         *SLATE_pt_GetObjClassification : object class                                                                   [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : Longitudinal displacement of the object                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SLATE_p_GetEMGenObjAttributes()->eObjectOcclusion : Occlusion of object                                             [EM_t_GenObjOclusionState as in Rte_Type.h]
  @glob_in         pSLATE_CameraObjData->CustObjects[].CamObjectData.cCamConfirmationProb : Probability of camera confirmation of object i
                                                                                                                       [0 ... 100.f]
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel                                                       [0.0f ... 1.0f]
  @glob_out        -

  @c_switch_part   LA_CFG_NOLANE_BIKE_SELECTION : Configuration switch, which sets selection of bicycles and motocycles on left and right OOI position ON, even if no lane was recognized.
  @c_switch_part   LA_CFG_NOLANE_VEHICLE_SELECTION : Configuration switch, which sets selection of cars and trucks on left and right OOI position ON, even if no lane was recognized.
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             Checked object is valid; Road estimation has to be available
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/23/2016

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Thomas Bock | Thomas.2.Bock@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
boolean LA_b_CheckObjAdjLaneValidity(const ObjNumber_t s_Obj,  const eAssociatedLane_t e_BaseAssocLane)/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Gireesh , Reason:This warning is suppressed as Indentation does not have any critical impact the functionality. */
{
#if (LA_CFG_NOLANE_VEHICLE_SELECTION)
  float32 f_ObjDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(s_Obj);
#endif
  boolean b_Ret = TRUE;
  sint32 s_NumberOfLanes;
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(s_Obj);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(s_Obj);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SLATE_t_Obj_DynamicSubProperty t_ObjDynSubProperty = *SLATE_pt_GetObjDynSubProperty(s_Obj);
#endif
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  percentage_t t_camConfirmationProb = pt_LAInput->pt_FIPOA->t_ObjList[s_Obj].t_CamObjectData.t_CamConfirmationProb;
#endif
#if ((LA_CFG_NOLANE_BIKE_SELECTION) ||(LA_CFG_NOLANE_VEHICLE_SELECTION))
  /* Set the default lateral distance, up to which moving bikes or motorcycles  
     may be OOI on left or right lane, even if there is no valid adjacent lane */
  float32 f_AbsDistBorder = LA_MOVING_CLIP_BIKE_ROAD_BORDER_ABSDIST;
  float32 f_ObjToRefDistMeas = *LA_pf_ObjToRefDistMeas(s_Obj);
  /* Get the absolute value of object's lateral distance */
  float32 f_AbsDistObj2Ref = fABS(f_ObjToRefDistMeas);
#endif
  
#if (FCT_CFG_ROAD_INPUT)
    float32 f_AbsDistBorderOncoming = LA_ONCOMING_CLIP_ABSDIST; /* if no roadborder availabe, restrict oncoming selection to to LA_ONCOMING_CLIP_ABSDIST */

  /* Road estimation input to FCT available */
  /* Determine number of valid adjacent lanes on the left side */
  if (e_BaseAssocLane == ASSOC_LANE_LEFT)
  {
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
    /* Get number of lanes based on FCT Input Preprocessing Management (navi, camera lane)*/
    s_NumberOfLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
#else
    /* Set default */
    s_NumberOfLanes = 1;
#endif
#if ((LA_CFG_NOLANE_BIKE_SELECTION) || (LA_CFG_NOLANE_VEHICLE_SELECTION))
    /* Set left bicycle clip distance to road border dist, if road estimation is reliable enough */
    if((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) == LA_ONCOMMING_ROAD_BORDER_CLIP_MIN_STAT)
    {
      f_AbsDistBorder = MIN_FLOAT(fABS((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)), LA_MOVING_CLIP_BIKE_ROAD_BORDER_MAX);
    }
    /*Otherwise set left bicycle clip distance to default dist*/
    else
    {
      f_AbsDistBorder = LA_MOVING_CLIP_BIKE_ROAD_BORDER_ABSDIST;
    }
#endif
  }
  /* Determine number of valid adjacent lanes on the right side */
  else if (e_BaseAssocLane == ASSOC_LANE_RIGHT)
  {
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
     /* Get number of lanes based on FCT Input Preprocessing Management (road, navi, camera lane)*/
    s_NumberOfLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
    /* Set default */
    s_NumberOfLanes = 1;
#endif
#if ((LA_CFG_NOLANE_BIKE_SELECTION) || (LA_CFG_NOLANE_VEHICLE_SELECTION))
    if((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) == LA_ONCOMMING_ROAD_BORDER_CLIP_MIN_STAT)
    /* Set left bicycle clip distance to road border dist, if road estimation is reliable enough */
    {
      f_AbsDistBorder = MAX_FLOAT(fABS((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)), LA_MOVING_CLIP_BIKE_ROAD_BORDER_MAX);
    }
    /*Otherwise set left bicycle clip distance to default dist*/
    else
    {
      f_AbsDistBorder = LA_MOVING_CLIP_BIKE_ROAD_BORDER_ABSDIST;
    }
#endif
  }
  else
  {
    /* This function checks the validity of adjacent lanes. Thus set number of  
       lanes to one for the ego lane in order to pass further checks */
    s_NumberOfLanes = 1;
  }
#else
  /* No road estimation input to FCT available, so assume one valid adjacent lane */
  s_NumberOfLanes = 1;
#endif  /* FCT_CFG_ROAD_INPUT */

  /* Handling of moving and crossing objects */
  if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    ||(t_ObjDynSubProperty  == SLATE_OBJECT_SUBPROP_CROSSING) 
#endif
    )
  {
    /* Verify that there is a valid adjacent lane based on the lane matrix or the object was already OOI, 
       or it is confirmed by the camera (thus definitely not a mirror or ghost). Moving objects, which 
       are classified as bike or motorcycle are also selectable as OOI, even if there is no valid lane 
       based on lane matrix. For all other moving objects this is actually a mirror suppression.*/
    if ( (s_NumberOfLanes != 0)
       ||(t_OOI_ObjectList[s_Obj].t_Bool.AlreadyOOI)
#if (LA_CFG_NOLANE_BIKE_SELECTION) 
       ||( (f_AbsDistObj2Ref < f_AbsDistBorder)
         &&((t_ObjClassification == SLATE_OBJCLASS_BICYCLE) || (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE)) )
#endif
#if (LA_CFG_NOLANE_VEHICLE_SELECTION)
       ||( (f_AbsDistObj2Ref < f_AbsDistBorder)
         &&((t_ObjClassification == SLATE_OBJCLASS_CAR) || (t_ObjClassification == SLATE_OBJCLASS_TRUCK))
         &&(f_ObjDistX > LA_MOVING_CLIP_VEH_DISTX_MIN) 
         &&(SLATE_p_GetEMGenObjAttributes(s_Obj)->eObjectOcclusion < EM_GEN_OBJECT_OCCL_PARTLY)
         &&(t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) )
#endif
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
       ||(t_camConfirmationProb >= LA_PAR_CAM_CONF_MIN)
#endif
       )
    {
      b_Ret = TRUE;
    }
    else
    {
      b_Ret = FALSE;
    }
  }

  /* Handling of stationary objects */
  else if( ( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA) 
          || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */ 
          )
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
         &&(t_ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING) //PRQA S 3355
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason:It has been checked logically, it is not always true*/
#endif // /*FCT_EM_ARS_TECH_OBJECT_LIST
         )
  {
    /* Verify that there is a valid adjacent lane based on the lane matrix or the object was already OOI, 
       or it is confirmed by the camera (thus definitely not a mirror or ghost). */
    if ( (s_NumberOfLanes != 0)
       ||(t_OOI_ObjectList[s_Obj].t_Bool.AlreadyOOI)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
       ||(t_camConfirmationProb >= LA_PAR_CAM_CONF_MIN)
#endif
       )
    {
      b_Ret = TRUE;
    }
    else
    {
      b_Ret = FALSE;
    }
  }

  /* Handling of oncoming objects*/
  else if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
         &&(t_ObjDynSubProperty  != SLATE_OBJECT_SUBPROP_CROSSING) //PRQA S 3355
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason:It has been checked logically, it is not always true*/
#endif
         )
  {
    float32 f_DistanceToTraj = pt_LAOutput->t_LAObjOutputList[s_Obj].TrajDist.TrajDistMeas.Y.f0;
    /* Get distance to trajectory to decide if object is on left or right side  of lane */

    if(e_BaseAssocLane == ASSOC_LANE_EGO)
    {
      /* This function checks the validity of adjacent lanes. Thus set the return value
         TRUE for ego lane objects. The special 'relevant object rolling back' situation
         for oncoming objects on the ego-lane is checked in LA_b_CheckObjOncRollBack. */
      b_Ret = TRUE;
    }
   /* Check objects on left adjacent lane (including objects, that are not associated to 
      ASSOC_LANE_LEFT, but which are on the left side of the ego-course) */
    else if( ((e_BaseAssocLane == ASSOC_LANE_LEFT)
            ||(f_DistanceToTraj >= 0.0f)) )
    {
#if (FCT_CFG_ROAD_INPUT)
      /* Return value is set TRUE, if the oncoming object on the left adjacent lane is located within
         the estimated road border or if the road border estimation is not reliable enough. Oncoming 
         objects located behind the guard rail will be ignored in OOI-selection. */
      if ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= LA_ONCOMMING_ROAD_BORDER_CLIP_MIN_STAT)
      {
        f_AbsDistBorderOncoming = (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft);
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
        /* in tunnels distance to road border is not reliable */
        if ( *pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES )
        {
          /* set high distance to road border to avoid drop-outs of objects on adjacent lane */
          f_AbsDistBorderOncoming = MAX(f_AbsDistBorderOncoming, LA_ONCOMMING_MIN_DIST2ROADBORDER_TUNNEL);
        }
#endif
      }
      if( f_AbsDistBorderOncoming > f_DistanceToTraj )
      {
        b_Ret = TRUE;
      }
      else
      {
        b_Ret = FALSE;
      }
#else
      /* No road estimation input to FCT available, so assume valid left lane */
      b_Ret = TRUE;
#endif /* FCT_CFG_ROAD_INPUT */
    }
    /* Check objects on right adjacent lane (including objects, that are not associated to 
      ASSOC_LANE_RIGHT, but which are on the right side of the ego-course) */
    else if( ((e_BaseAssocLane == ASSOC_LANE_RIGHT)
            ||(f_DistanceToTraj < 0.0f)) )
    {
#if (FCT_CFG_ROAD_INPUT)
      float32 f_Abs_DistanceToTraj;
      /* Return value is set TRUE, if the oncoming object on the left adjacent lane is located within
         the estimated road border or if the road border estimation is not reliable enough. Oncoming 
         objects located behind the guard rail will be ignored in OOI-selection. */
      if ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= LA_ONCOMMING_ROAD_BORDER_CLIP_MIN_STAT)
      {
        f_AbsDistBorderOncoming = fABS((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight));
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
        /* in tunnels distance to road border is not reliable */
        if ( *pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES )
        {
          /* set high distance to road border to avoid drop-outs of objects on adjacent lane */
          f_AbsDistBorderOncoming = MAX(f_AbsDistBorderOncoming, LA_ONCOMMING_MIN_DIST2ROADBORDER_TUNNEL);
        }
#endif /* END IF FCT_CFG_SIGNAL_PERF_MONITORING */
      }
      f_Abs_DistanceToTraj = fABS(f_DistanceToTraj);
      if( f_AbsDistBorderOncoming > f_Abs_DistanceToTraj ) 
      {
        b_Ret = TRUE;
      }
      else
      {
        b_Ret = FALSE;
      }
#else
      /* No road estimation input to FCT available, so assume valid right lane */
      b_Ret = TRUE;
#endif /* FCT_CFG_ROAD_INPUT */
    }
    else
    {
      /* do nothing, only objects on adjacent lanes to host lane are checked */
    }
  }
  else
  {
    /* do nothing, no valid dynamic property */
  }
  return b_Ret;
}

/** @} end defgroup */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

