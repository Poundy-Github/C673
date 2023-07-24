/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_customfunctions.c

DESCRIPTION:               Custom Functions for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.13.6.1 $

LEGACY VERSION:            Revision: 1.5

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "ooi.h"

#if (FCT_CFG_ACC_OOI)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       ooi_customfunctions Custom functions
@ingroup        ooi
@brief          This module contains customer specific data for  ACC Object Of Interest (OOI) selection module.
@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/
#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
  static boolean b_Bike_Overtakelastcycle = FALSE; /*To indicate OOI-1 has been selected as OOI-0 in last cycle */
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE) */
/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/
#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
#define OOI_NO_LANES                            0
#define OOI_NO_LANES_PROB_THRESH                0.70f
#define OOI_MOV_OBJ_COUNTER_MAX                 10u
#define OOI_MOV_OBJ_COUNTER_HIST                4u
#define OOI_EGO_VEL_THRESHOLD_STAT_OBJ_SUPRESS  10.0f
#endif 

/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/



/*************************************************************************************************************************
  Functionname:    OOI_v_MergeCustomObjects                                                                         */ /*!

  @brief           Merge customer specific object data

  @description     Merge customer specific object data

                    @startuml
                        Start
                            Partition OOI_v_MergeCustomObjects {
                                -Merge customer specific object data
                            }
                        End
                    @enduml

  @return          -

  @param[in]       uiObjectToKeep   : Information describing the object to keep     [0u ... EM_N_OBJECTS-1]
  @param[in]       uiObjectToDelete : Information describing the object to delete   [0u ... EM_N_OBJECTS-1] 
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            -

  @created         -
  @changed         -

  @author          -
*************************************************************************************************************************/
void OOI_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete )
{
  /* merge customer specific object data */
  uiObjectToKeep = uiObjectToKeep; // PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
  uiObjectToDelete = uiObjectToDelete;// PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
}

#if (OOI_CFG_OBJLOSS_LOWDIST)
/*************************************************************************************************************************
  Functionname:         OOI_v_ObjLossLowDist                                                                         */ /*!

  @brief                Set the object lost reason at low distance

  @description          Set the object lost reason at low distance

  @return               eRelObjLossReason_t 

  @param[in]            

  @glob_in              
  @glob_out             OBJ_LOSS_DISAPPEARED

  @c_switch_part   OOI_CFG_OBJLOSS_LOWDIST : Configuration switch enabling ObjectLossReason at low distance
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 This is a temporary solution for customizing the object reason at low distances.
                        The next step consists of extracting the part of the code, in ooi_objloss.c, responsible for OLR at low distances,
                        and migrate it to this custom function. The custom function should be called in ooi_main after OOI_v_SelectBaseObjectsOfInterest()


  @author               Marouane Ben Romdhane | marouane.ben.romdhane@continental-corporation.com | +49 (8382) 9699-402
*************************************************************************************************************************/
eRelObjLossReason_t OOI_v_ObjLossLowDist(void)
{
  return OBJ_LOSS_DISAPPEARED;
}
#endif /* END IF OOI_CFG_OBJLOSS_LOWDIST */


#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
/*************************************************************************************************************************
  Functionname:    OOI_v_InitCustomGaurdRailStatObjSuppress                                                                         */ /*!

  @brief           Initializes the Moving object counter

  @description          

  @return               

  @param[in]            

  @glob_in              
  @glob_out             

  @c_switch_part   OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS : Configuration switch enabling supression of stationary object 
                                                                formed in between a moving object in OOI 0 position and EGO vehicle.
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author               Shubham Tandon | shubham.tandon@continental-corporation.com 
*************************************************************************************************************************/
void OOI_v_InitCustomGaurdRailStatObjSuppress(void)
{
  pt_OOI_Output->OOI_uOOIObjCount    = 0u;
}
#endif

#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
/*************************************************************************************************************************
  Functionname:    OOI_v_UpdateMovingObjectCounter                                                                         */ /*!

  @brief           Updates a counter if a moving object is detected in OOI0 position for consecutive cycles.

  @description          

  @return               

  @param[in]       pNewObjId  : Object ID of a moving vehicle detected in the EGO lane [0u ... EM_N_OBJECTS-1]   
                   eRelObjType: OOI position for which the stationary object is being checked. [OBJ_NOT_OOI .. 
  @glob_in                                                                                          OBJ_NEXT_LAT_RIGHT_OOI]
  @glob_out             

  @c_switch_part   OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS : Configuration switch enabling supression of stationary object 
                                                                formed in between a moving object in OOI 0 position and EGO vehicle.
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author               Shubham Tandon | shubham.tandon@continental-corporation.com 
*************************************************************************************************************************/
void OOI_v_UpdateMovingObjectCounter(const ObjNumber_t * const pNewObjId, OOI_RelObjEnum_t eRelObjType)
{
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  sint8   iNoLaneLeft      = ROAD_GET_LANE_NO_LEFT;
  sint8   iNoLaneRight     = ROAD_GET_LANE_NO_RIGHT;
  float32 fNoLaneProbLeft  = ROAD_GET_NO_LANE_MATRIX_PROB_LEFT;
  float32 fNoLaneProbRight = ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT;
  
  if(*pNewObjId >= 0)
  {
    t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(*pNewObjId);
  } 
  else
  {
    /* The object ID is -1 */
    t_ObjDynProperty = EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
  }


  if(((iNoLaneLeft  == OOI_NO_LANES) && (fNoLaneProbLeft  > OOI_NO_LANES_PROB_THRESH)) ||
     ((iNoLaneRight == OOI_NO_LANES) && (fNoLaneProbRight > OOI_NO_LANES_PROB_THRESH))   )
  {
    if (eRelObjType == OBJ_NEXT_OOI)
    {
      if ((*pNewObjId >= 0) &&
          (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) &&
          (t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI]  == *pNewObjId)                    )
      {
        pt_OOI_Output->OOI_uOOIObjCount = pt_OOI_Output->OOI_uOOIObjCount + 1u;
        pt_OOI_Output->OOI_uOOIObjCount = (pt_OOI_Output->OOI_uOOIObjCount > OOI_MOV_OBJ_COUNTER_MAX)
                                            ? OOI_MOV_OBJ_COUNTER_MAX : pt_OOI_Output->OOI_uOOIObjCount;
      }    
      else
      {
        pt_OOI_Output->OOI_uOOIObjCount = 0u;    
      }
    }
    else /*if (eRelObjType == OBJ_NEXT_OOI)*/
    {
    }
  }
  else /* if EGO is not in the left most or right most lane*/
  {
    pt_OOI_Output->OOI_uOOIObjCount = 0u;
  }
  

}
#endif

#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
/*************************************************************************************************************************
  Functionname:    OOI_b_CheckPartofGaurdRail                                                                         */ /*!

  @brief           Checks if stationary object is part of the gaurd rail.

  @description     This function relies on the availability of a moving object infront of the EGO vehicle. Once the moving
                    object has been confirmed to be in OOI0 position for a certain number of cycles, then we can suppress the
                    selection of any stationary object in between the moving vehicle and EGO (it is based on the assumption
                    that if there is a moving vehicle infron of the EGO then it would have driven through the point where
                    the stationary object is currently located, hence that stationary object cannot be an obstacle).

  @return               

  @param[in]            

  @glob_in              
  @glob_out             

  @c_switch_part   OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS : Configuration switch enabling supression of stationary object 
                                                                formed in between a moving object in OOI 0 position and EGO vehicle.
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author               Shubham Tandon | shubham.tandon@continental-corporation.com 
*************************************************************************************************************************/
boolean OOI_b_CheckPartofGaurdRail(OOI_RelObjEnum_t eRelObjType)
{
  float32 f_EgoVelObjSync      = SLATE_f_GetEgoVelObjSync();  
  boolean b_NotPartofGaurdRail = TRUE;

  if ((f_EgoVelObjSync > OOI_EGO_VEL_THRESHOLD_STAT_OBJ_SUPRESS) &&
      (eRelObjType == OBJ_NEXT_OOI)                                  )
  {
    b_NotPartofGaurdRail =  (boolean)(pt_OOI_Output->OOI_uOOIObjCount <= (OOI_MOV_OBJ_COUNTER_MAX - OOI_MOV_OBJ_COUNTER_HIST));
  }
  else
  {
  }  

  return b_NotPartofGaurdRail;

}
#endif

/*************************************************************************************************************************
  Functionname:    OOI_b_CheckforCriticalObjLossReason                                                                         */ /*!

  @brief           Checks if Critical Object loss reason is set for Objects within Ego and OOI0 object loss.

  @description     This function relies on the OOI0 object loss. Once the OOI0 is lost, a new moving 
                    object (without sufficient ACC quality is detected) which is geometrically inlane (E.g. Low Boy vehicle Cut-in) having
                    minimum longitudinal distance from Ego vehicle as compared to Lost OOI0 is confirmed and critical object loss reason
                    is set for that object).

  @return               

  @param[in]            

  @glob_in              
  @glob_out             

  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author               Kirti Patil | Kirti.Patil@continental-corporation.com 
*************************************************************************************************************************/
void OOI_b_CheckforCriticalObjLossReason(const OOI_ROVDataInput_t *ROVDataInput)
{
  _PARAM_UNUSED(ROVDataInput);
}

/*************************************************************************************************************************
  Functionname:    OOI_b_CheckTargetLossDueToLateralPositionDrift                                                    */ /*!

  @brief           OOI-0 loss due to lateral drift of target object during EGO and Target standstill situation

  @description     This function looks for OOI-0 loss due to lateral drift of target vehicle when both EGO and target are
                   in standstill situation. So at standstill situation if the lateral drift of target is more than the 
                   OOI0_MIN_LAT_DRIFT_AT_STANDSTILL with longitudnal distance fluctuation less than 
                   OOI0_MAX_LONG_DISP_FLUCTUATION_AT_STANDSTILL and OOI0 is lost and becomes OOI2 or OOI3.
                   This situation is evaluated only for object classification CAR and TRUCK.

  @return          

  @param[in]       ROVDataInput

  @glob_in         SLATE_t_GetEGOMotionState() gives the EGO motion state Eg: VDY_LONG_MOT_STATE_STDST
  @glob_in         SLATE_u_EgoMotionState() give the EGO motion state confidence 
  @glob_in         SLATE_b_GetObjIsMovingToStationary() give the TRUE/FALSE. TRUE states target is STOPPED 
  @glob_in         SLATE_pt_GetObjDynProperty() gives the dynamic property of the target.
  @glob_in         *pt_OOI_Input->t_RTE.pf_ObjLatDisp(ROVDataInput->RelTrckObjNr) gives target lateral distance
  @glob_in         *pt_OOI_Input->t_RTE.pf_ObjLongDisp(ROVDataInput->RelTrckObjNr) gives target longitudnal distance
  @glob_in         SLATE_pt_GetObjClassification(ROVDataInput->RelTrckObjNr) gives target object classification
  @glob_in         FCTSEN_pPubFctObjList->ObjList[ROVDataInput->pRelObj->ObjectNr].ObjOfInterest.eObjOOI gives OOI number
  @glob_in         SLATE_f_GetEgoVelObjSync() give the EGO velocity
  @glob_in         *SLATE_pf_GetObjVrelX(ROVDataInput->RelTrckObjNr) givers the target relative velocity

  @glob_out         pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] will update the object loss reason.

  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author               Amit Sharma | amit.sharma@continental-corporation.com 
*************************************************************************************************************************/
void OOI_b_CheckTargetLossDueToLateralPositionDrift(const OOI_ROVDataInput_t *ROVDataInput)
{
  _PARAM_UNUSED(ROVDataInput);
}

/*************************************************************************************************************************
  Functionname:    OOI_b_CheckCustomObjLossReason                                                                         */ /*!

  @brief           Set custom Object loss reason.

  @description     Set custom Object loss reason.

  @return               

  @param[in]            

  @glob_in              
  @glob_out             

  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author          Amit Sharma | amit.sharma@continental-corporation.com 
*************************************************************************************************************************/
void OOI_b_CheckCustomObjLossReason(const OOI_ROVDataInput_t *ROVDataInput)
{
  _PARAM_UNUSED(ROVDataInput);

}
#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
/*************************************************************************************************************************
  Functionname:    OOI_v_BikeOvertake                                                                         */ /*!

  @brief           Check whether the OOI-0 is bike and is overtaking OOI-1. If so select OOI-1 as OOI-0 to avoid late approach.

  @description     Check whether the OOI-0 is bike and is overtaking OOI-1. If so select OOI-1 as OOI-0 to avoid late approach.Checking relative velocity,TTC between OOI-0 and OOI-1 to identify Overtake. To be applied only in CITY.

  @startuml
  Start
  Partition OOI_v_BikeOvertake {
    IF (OOI-0 classification is Bike or bicycle) THEN(TRUE)
      IF (Check if a valid OOI-1 is present) THEN (TRUE)
        IF (The classification of OOI-1 is not bike or bicycle) THEN (TRUE)
          IF((TTC of OOI-0 > TTC of OOI-1) AND (Velocity of OOI-0 > Velocity of OOI-1 + Offset) && (Ego Velocity > Velocity of OOI-1 + Offset) && (TTC of OOI-1 < OOI_OOI1_MAX_TTC_FOR_BIKE_OVERTAKE) && (Ego Velocity < OOI_EGO_MAX_VEL_FOR_BIKE_OVERTAKE) && (Longitudinal displacement of OOI-0 < OOI_OOI0_MAX_DIST_FOR_BIKE_OVERTAKE) && (Longitudinal distance between OOi-1 and OOI-0 < OOI_MAX_DIST_DIFF_INITIAL) && (Distance to trajectory of OOI-0 > OOI_OOI0_MIN_DIST2TRAJ_INITIAL)) THEN (TRUE)
            - Select OOI-1 as OOI-0 and assign the object in front of OOI-1 as OOI-1
            - Set bike overtake last cycle as TRUE
          ELSE (FALSE)
            - Set bike overtake last cycle as FALSE
          ENDIF
        ENDIF
      ELSEIF ((Bike overtake last cycle is TRUE) AND (Last cycle OOI-0 has valid ID) AND (Last cycle OOI-0 is not equal to present cycle OOI-0)) THEN (TRUE)
        IF ((Last cycle object is not deleted) && (Last cycle object is selected as OOI is TRUE)) THEN (TRUE)
          IF (Distance to trajectory is less than OOI_OOI1_MAX_DIST2TRAJ ) THEN (TRUE)
            IF ((Velocity of OOI-0 > Velocity of OOI-1 + Offset) AND (Longitudinal distance between OOi-1 and OOI-0 < OOI_MAX_DIST_DIFF_FINAL) AND (Distance to trajectory of present OOi-0 > OOI_OOI0_MIN_DIST2TRAJ_FINAL)) THEN(TRUE)
              - Select OOI-1 as OOI-0 and assign the object in front of OOI-1 as OOI-1
              - Set bike overtake last cycle as TRUE
            ELSE (FALSE)
              - Set bike overtake last cycle as FALSE
            ENDIF
          ELSE(FALSE)
            - Set bike overtake last cycle as FALSE
          ENDIF
        ELSE
          - Set bike overtake last cycle as FALSE
        ENDIF
      ELSE (FALSE)
        -Set bike overtake last cycle as FALSE		
      ENDIF
    ENDIF
  
    IF ((OOI-0 to be selected is not equal to last cycle OOI-0) AND (OOI-0 to be selected is not equal to present cycle OOI-0)) THEN (TRUE)
    - Set bike overtake last cycle as FALSE
    ENDIF
  }
  End
  @enduml
  @return               

  @param[in]            

  @glob_in              pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] - Object ID of OOI-0
  @glob_in              *pt_OOI_Input->t_RTE.pf_ObjClassification(Obj) - Classification of Object
  @glob_in              *pt_OOI_Input->t_RTE.pf_EgoVelObjSync - Ego velocity
  @glob_in              pt_OOI_Input->pt_FIPInput->t_ObjList[Obj].fAbsVelocity - Velocity of the object
  @glob_in              *pt_OOI_Input->t_RTE.pf_ObjLongDisp(Obj) - Longitudinal displacement of the Object
  @glob_in              pt_OOI_Input->t_LAInput.pt_LAObjectList(Obj)->TrajDist.TrajDistMeas.Y.f0 - Distance to trajectory of the Object
  @glob_in              *pt_OOI_Input->t_RTE.pf_ObjVRelX(Obj) - Relative velocity of the Object
  @glob_in              t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI] - Object ID of OOI-0 of last cycle
  @glob_out             t_OOI_ObjectList[Obj].t_Bool.SelectedAsOOI - Object selected as OOI-0 is set as TRUE
  @glob_out             pt_OOI_Output->OOI_ObjNumber[OBJ_HIDDEN_NEXT_OOI] - Object ID of OOI-1
  @glob_out             pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] - Object ID of OOI-0
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC
  @c_switch_full   OOI_CFG_SELECT_OOI1_DURING_BIKE_OVERTAKE : Configuration switch to select OOI-1 as OOI-0 when OOI-0 is a bike and is trying to overtake OOI-1

  @pre                  
  @post                 

  @InOutCorrelation     

  @todo                 


  @author          Madhusudhanan Dhanikachalam| madhusudhanan.dhanikachalam@continental-corporation.com 
*************************************************************************************************************************/
void OOI_v_BikeOvertake(void)
{
  
  float32 f_VelOOI0;
  float32 f_VelOOI1;
  float32 f_ObjLongDisp_OOI0;
  float32 f_ObjLongDisp_OOI1;
  float32 f_TTC_OOI0 = OOI_MAX_TTC0;
  float32 f_TTC_OOI1 = OOI_MAX_TTC1;
  ObjNumber_t t_Next_ObjID;
  ObjNumber_t t_NewObjId;
  ObjNumber_t t_Present_ObjID = pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI];
  float32 f_AbsDistToTraj_PresentObj;
  SLATE_t_Obj_CLassification t_ObjClassification = (*pt_OOI_Input->t_RTE.pf_ObjClassification(t_Present_ObjID));
  float32 f_EgoVelObjSync = *pt_OOI_Input->t_RTE.pf_EgoVelObjSync;
  
  /* Check whether the OOI-0 is Bike or Bicycle */
  if  ((t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE) || (t_ObjClassification == SLATE_OBJCLASS_BICYCLE))
  {
    t_Next_ObjID = pt_OOI_Output->OOI_ObjNumber[OBJ_HIDDEN_NEXT_OOI];
    f_VelOOI0 = pt_OOI_Input->pt_FIPInput->t_ObjList[t_Present_ObjID].fAbsVelocity;
    f_ObjLongDisp_OOI0   = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(t_Present_ObjID);
    f_AbsDistToTraj_PresentObj = fABS(pt_OOI_Input->t_LAInput.pt_LAObjectList(t_Present_ObjID)->TrajDist.TrajDistMeas.Y.f0);
    
    /* Check to find if there is a valid OOI-1 */
    if (((t_Next_ObjID >= 0) && (t_Next_ObjID < EM_N_OBJECTS)))
    {
      SLATE_t_Obj_CLassification t_ObjClassification_NextObj = (*pt_OOI_Input->t_RTE.pf_ObjClassification(t_Next_ObjID));

      /* Check to avoid selection of OOI-1 as OOI-0 when OOI-1 is also a Bike or a Bicycle */
      if((t_ObjClassification_NextObj != SLATE_OBJCLASS_MOTORCYCLE) && (t_ObjClassification_NextObj != SLATE_OBJCLASS_BICYCLE))
      {

        float32 f_Vrelx_OOI0 = *pt_OOI_Input->t_RTE.pf_ObjVRelX(t_Present_ObjID);
        float32 f_Vrelx_OOI1 = *pt_OOI_Input->t_RTE.pf_ObjVRelX(t_Next_ObjID);
        f_VelOOI1 = pt_OOI_Input->pt_FIPInput->t_ObjList[t_Next_ObjID].fAbsVelocity;
        f_ObjLongDisp_OOI1 = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(t_Next_ObjID);
            
        /*Find TTC of OOI-0 and OOI-1 when their respective relative velocities are less than zero */
        if(f_Vrelx_OOI0 < -C_F32_DELTA )
        {
          f_TTC_OOI0 = (f_ObjLongDisp_OOI0 / -(f_Vrelx_OOI0));
        }

        if(f_Vrelx_OOI1 < -C_F32_DELTA )
        {
          f_TTC_OOI1 = (f_ObjLongDisp_OOI1 / -(f_Vrelx_OOI1));
        }

        /*Conditions to identify whether OOI-0 which is bike trying to overtake OOI-1 to avoid late approach of OOI-1 when OOI-0 is cut out.TTC of OOI-0 will be higher than OOI-1 when OOI-0 is tryinh to overtake OOI-1.
           Distance to trajectory is considered to avoid dropouts.Offset is checked for Velocities to avoid fluctuation is selection of OOI-0*/
        if(   (f_TTC_OOI0 > f_TTC_OOI1)
              && (f_VelOOI0 > (f_VelOOI1 + OOI_OOI1_OOI0_VEL_OFFSET))
              && (f_EgoVelObjSync > (f_VelOOI1 + OOI_OOI1_EGO_VEL_OFFSET))
              && (f_TTC_OOI1 < OOI_OOI1_MAX_TTC_FOR_BIKE_OVERTAKE)
              && (f_EgoVelObjSync < OOI_EGO_MAX_VEL_FOR_BIKE_OVERTAKE)
              && (f_ObjLongDisp_OOI0 < OOI_OOI0_MAX_DIST_FOR_BIKE_OVERTAKE)
              &&((f_ObjLongDisp_OOI1 - f_ObjLongDisp_OOI0) < OOI_MAX_DIST_DIFF_INITIAL)
              && (f_AbsDistToTraj_PresentObj > OOI_OOI0_MIN_DIST2TRAJ_INITIAL))
           {
             /* Select OOI-1 as OOI-0 and assign the object in front of OOI-1 as OOI-1. Set Bike overtake last cycle to avoid reselection of Bike again*/
             t_OOI_ObjectList[t_Present_ObjID].t_Bool.SelectedAsOOI = 0u;
             pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] = t_Next_ObjID;
             t_OOI_ObjectList[t_Next_ObjID].t_Bool.SelectedAsOOI = 1u;
             t_NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_EGO, OOI_OBJ_SELECTION_NEXT_LONG);
             OOI_v_SelectStationaryObject(&t_NewObjId, OBJ_HIDDEN_NEXT_OOI);
             pt_OOI_Output->OOI_ObjNumber[OBJ_HIDDEN_NEXT_OOI] = t_NewObjId;
             b_Bike_Overtakelastcycle = TRUE;
           }
         else
           {
             b_Bike_Overtakelastcycle = FALSE;
           }
      }
          
    }
    else if((b_Bike_Overtakelastcycle == TRUE) && ((t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI] >= 0) && (t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI] < EM_N_OBJECTS)) && (t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI] != pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI])) 
     {
       ObjNumber_t t_LastCycleObj = t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI];
       boolean b_isObjDeleted = SLATE_b_GetObjIsDeleted(t_LastCycleObj);

       if((b_isObjDeleted != TRUE) && (t_OOI_ObjectList[t_LastCycleObj].t_Bool.SelectedAsOOI == TRUE))
       {
         float32 f_AbsDistToTrajLastCycleObj = fABS(pt_OOI_Input->t_LAInput.pt_LAObjectList(t_LastCycleObj)->TrajDist.TrajDistMeas.Y.f0);
       
         /*Conditions to be checked when Bike over take last cycle signal is set.Select OOI-1 if and only if it's distance to trajectory is within 1.2m */
         if(f_AbsDistToTrajLastCycleObj < OOI_OOI1_MAX_DIST2TRAJ)
          {
            f_VelOOI1 = pt_OOI_Input->pt_FIPInput->t_ObjList[t_LastCycleObj].fAbsVelocity;
            f_ObjLongDisp_OOI1 = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(t_LastCycleObj);
            if((f_VelOOI0 > (f_VelOOI1 + OOI_OOI1_OOI0_VEL_OFFSET)) && ((f_ObjLongDisp_OOI1 - f_ObjLongDisp_OOI0) < OOI_MAX_DIST_DIFF_FINAL) && (f_AbsDistToTraj_PresentObj > OOI_OOI0_MIN_DIST2TRAJ_FINAL))
            {
              t_OOI_ObjectList[t_Present_ObjID].t_Bool.SelectedAsOOI = 0u;
              pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] = t_LastCycleObj;
              t_OOI_ObjectList[t_LastCycleObj].t_Bool.SelectedAsOOI = 1u;
              t_NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_EGO, OOI_OBJ_SELECTION_NEXT_LONG);
              OOI_v_SelectStationaryObject(&t_NewObjId, OBJ_HIDDEN_NEXT_OOI);
              pt_OOI_Output->OOI_ObjNumber[OBJ_HIDDEN_NEXT_OOI] = t_NewObjId;
              b_Bike_Overtakelastcycle = TRUE;
            }
            else
            {
              b_Bike_Overtakelastcycle = FALSE;
            }
          }
          else
          {
            b_Bike_Overtakelastcycle = FALSE;
          }
       }
       else
       {
         b_Bike_Overtakelastcycle = FALSE;
       }
     }
     else
     {
       b_Bike_Overtakelastcycle = FALSE;
     }
          
  }

  if((pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] != t_OOI_LastCycleOOIObjID[OBJ_NEXT_OOI]) && (pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] != t_Present_ObjID))
  {
    b_Bike_Overtakelastcycle = FALSE;
  }

  
}
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE) */
///@}
#endif /*!< FCT_CFG_ACC_OOI */


