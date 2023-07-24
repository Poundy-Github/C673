/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

MODULNAME:                 ooi_objselection.c

DESCRIPTION:               Selection of the objects of interest

AUTHOR:                    Boll, Marie-Theres (uidu1091) 

CREATION DATE:             10.08.2016 

VERSION:                   $Revision: 1.32 $

LEGACY VERSION:            Revision: 2.1.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "ooi.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_ACC_OOI)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup ooi_objselection Object of Interest selection
@ingroup ooi
@brief          This module select the 6 relevant objects as object of interest from all objects. \n\n
@{
*/
#ifdef  FCT_SIMU
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#endif  /* FCT_SIMU */

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/



/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/
SET_MEMSEC_VAR(t_OOI_LastCycleOOIObjID)
ObjNumber_t t_OOI_LastCycleOOIObjID[OOI_NUMBER_OF_OOI];

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

#define OOI_PICKUP_DISTANCE_HARD_BRAKE_EGO_DECELERATION (4.f)
#define OOI_PICKUP_DISTANCE_COMFORT_BRAKE_EGO_DECELERATION (2.f)
#define OOI_PICKUP_DISTANCE_GAP_TIME (1.8f)
#define OOI_PICKUP_DISTANCE_LATENCY_TIME (1.0f)
#define OOI_RELEVANTOBJ_COUNTER_MAX (200u)  /* Maximum value of relevant object counter */

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/



/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void OOI_v_SelectOOI(ObjNumber_t ObjectToSelect);
static void OOI_v_UnSelectOOI(ObjNumber_t ObjectToUnSelect);
static void OOI_v_ComputePredictedDistance(void);

/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
/*************************************************************************************************************************
  Functionname:    OOI_v_SelectBaseObjectsOfInterest                                                                    */ /*!

  @brief           This function handles the selection of the objects of interest for Conti ACC (6 objects)

  @description     The function SISelectObjectsOfInterest calls all necessary functions 
                   for the selection of the six objects of interest (OOI) (standard output interface)
                   - Save object IDs of last cycle OOIs
                   - Select next objects at host lane (moving, stationary, oncoming), 
                      i.e. OBJ_NEXT_OOI and OBJ_HIDDEN_NEXT_OOI
                   - Check blocked path objects
                   - Select next distance object on adjacent lanes (moving, stationary, oncoming), 
                      i.e. OBJ_NEXT_LONG_LEFT_OOI and OBJ_NEXT_LONG_RIGHT_OOI
                   - Select next lateral displacement object on adjacent lanes (moving, stationary, oncoming), 
                      i.e. OBJ_NEXT_LAT_LEFT_OOI and OBJ_NEXT_LAT_RIGHT_OOI
                   - Set AlreadyOOI flag
                   - Reset cut-in potential
                   - Determine object loss reason for objects of interest
                   - Fill in relevant object loss reason in external interface

          @startuml
          Start
            Partition OOI_SelectBaseObjectsOfInterest {
              Repeat
                - Save the object ID’s of last cycle decision;
              Repeat while (Loop over for OOI_NUMBER_OF_OOI)
              - Select next objects at host lane (moving, stationary, oncoming), i.e. OOI 0 and OOI 1
              - Check blocked path objects
              - Select next distance object on adjacent lanes (moving, stationary, oncoming), i.e. OOI 4 and OOI 5
              - Select next lateral displacement object on adjacent lanes (moving, stationary, oncoming), i.e. OOI 2 and OOI 3
              - Select OOI 1 during Bike Overtake
              - Set Already OOI flag
              - Reset cut-in potential
              - Determine object loss reason for objects of interest
              - Fill in relevant object loss reason in external interface
            }
          End 
          @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_OOI_Output->OOI_ObjNumber[i] : Object-ID of ACC assessed 6-element array of objects of interest [0u ... EM_N_OBJECTS-1]   
                                                     with i in [0u ... OOI_NUMBER_OF_OOI] with OOI_NUMBER_OF_OOI as defined in ooi_ext.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Macro to retrieve dynamic property of given object i  [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                                             with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_GET_OOI_POS(i) : Macro to retrieve position of Object with given ObjectID  [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
                                        with i in [0u ... OOI_NUMBER_OF_OOI] with OOI_NUMBER_OF_OOI as in ooi_ext.h
  @glob_out        t_OOI_LastCycleOOIObjID[i] : Array describing 6-OOI object IDs of last cycle, array size [0u ... EM_N_OBJECTS-1]
                                                with i in [0u ... OOI_NUMBER_OF_OOI] with OOI_NUMBER_OF_OOI as in ooi_ext.h
  @glob_out        OOI_OBJ_SET_OBJ_OF_INTEREST(i, j) : Macro to set the new OOI position j of given object i [Full range of datatype eObjOOI_t as defined in Rte_Type.h] 
                                                       with i in [0u ... EM_N_OBJECTS-1] and j in [-1 ... -5 ]
  @glob_out        pt_OOI_Output : Reference to OOI output data structure 
                      OOI_ObjNumber[i] : Object-ID of ACC assessed 6-element array of objects of interest  [0u ... EM_N_OBJECTS-1]  
                                         with i in [0u ... OOI_NUMBER_OF_OOI] with OOI_NUMBER_OF_OOI as in ooi_ext.h
                      t_OOI_RelObject[i] : Information describing about the objects of interest
  @glob_out        t_OOI_ObjectList[i].t_Bool.AlreadyOOI : Status flag to check whether given object is already OOI [0u, 1u] 
                                                           with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OBJ_GET_CUT_IN_POTENTIAL(i) : Macro to retrieve cut-in potential of object i with given ObjectID  [0u ... 100u]
                                                 with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        GET_FCT_PUB_OBJ_DATA_PTR->HeaderAssessedObjList.eRelObjLossReason : Reason for OOI-0 object loss [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h] 

  @c_switch_part   OOI_CFG_SELECT_OOI_4_AND_5_NEXT_LONG : Configuration switch, which sets selection of OOI objects 4 & 5 as next longitudinal instead of next predicted lateral
  @c_switch_full   FCT_CFG_ACC_OOI                      : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             Object lane association has to be finished for the current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
   
  @traceability    279:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-279-00061542 \n
                   179:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-179-00061542 \n
                   180:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-180-00061542 \n
                   181:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-181-00061542 \n
                   182:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-182-00061542 \n
                   183:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-183-00061542 \n
                   184:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-184-00061542 \n
                   278:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-278-00061542 \n

  @created         -
  @changed         3/2/2016

  @author          Robert Thiel / Fridolin Kolb
*************************************************************************************************************************/
void OOI_v_SelectBaseObjectsOfInterest(void)
{
  sint8 nr;
  ObjNumber_t NewObjId;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;

  /* save Object IDs of last cycle decision */
  for(nr = 0; nr < OOI_NUMBER_OF_OOI; nr++)
  {
    t_OOI_LastCycleOOIObjID[nr]= pt_OOI_Output->OOI_ObjNumber[nr];
  }

  /* Compute the predicted distance needed and specific to OOI selection */
  OOI_v_ComputePredictedDistance();

  /*caution: order of execution is relevant!*/
  /*select next objects at host lane*/
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_EGO, OOI_OBJ_SELECTION_NEXT_LONG);
  OOI_v_SelectStationaryObject(&NewObjId, OBJ_NEXT_OOI);
  OOI_v_SelectOncomingObject(&NewObjId, OBJ_NEXT_OOI);
  /* Check if the relevant object has changed from the previous cycle */
  if ((NewObjId < 0) || (NewObjId != pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI]))
  {
    /* Get previous relevant object ID and check if there was one */
    const ObjNumber_t PrevRelObjId = pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI];
    if ((PrevRelObjId >= 0) && (PrevRelObjId < EM_N_OBJECTS))
    {
      /* There was a previous rel object, reset it's relevant info */
      SLATE_p_GetFCTPubObj_OOI(PrevRelObjId)->eObjOOI = OBJ_NOT_OOI;
      //OOI_OBJ_SET_OBJ_OF_INTEREST(PrevRelObjId, OBJ_NOT_OOI);
    }
  }
  pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] = NewObjId;
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_EGO, OOI_OBJ_SELECTION_NEXT_LONG);
  OOI_v_SelectStationaryObject(&NewObjId, OBJ_HIDDEN_NEXT_OOI);

  pt_OOI_Output->OOI_ObjNumber[OBJ_HIDDEN_NEXT_OOI] = NewObjId;

  OOI_v_BlockedPathDecision(&pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI], &pt_OOI_Output->OOI_ObjNumber[OBJ_HIDDEN_NEXT_OOI]);


  /*select next distance object on adjacent lanes*/
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_LEFT, OOI_OBJ_SELECTION_NEXT_LONG);
  OOI_v_SelectStationaryObject(&NewObjId, OBJ_NEXT_LONG_LEFT_OOI);
  if (NewObjId < 0)
  {
    OOI_v_SelectOncomingObject(&NewObjId, OBJ_NEXT_LONG_LEFT_OOI);
  }
  pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LONG_LEFT_OOI] = NewObjId;

  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_RIGHT, OOI_OBJ_SELECTION_NEXT_LONG);
  OOI_v_SelectStationaryObject(&NewObjId, OBJ_NEXT_LONG_RIGHT_OOI);
  if (NewObjId < 0)
  {
    OOI_v_SelectOncomingObject(&NewObjId, OBJ_NEXT_LONG_RIGHT_OOI);
  }
  pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LONG_RIGHT_OOI] = NewObjId;


  /*select next lateral displacement object on adjacent lanes*/
#if (OOI_CFG_SELECT_OOI_4_AND_5_NEXT_LONG)
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_LEFT, OOI_OBJ_SELECTION_NEXT_LONG);
#else
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_LEFT, OOI_OBJ_SELECTION_NEXT_LATERAL);
#endif
  OOI_v_SelectStationaryObject(&NewObjId, OBJ_NEXT_LAT_LEFT_OOI);
  if (NewObjId < 0)
  {
    if(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LONG_LEFT_OOI] >= 0)
    {
     t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LONG_LEFT_OOI]);
     if(t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
     {
       OOI_v_SelectOncomingObject(&NewObjId, OBJ_NEXT_LAT_LEFT_OOI);
     }
    }
  }
  pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LAT_LEFT_OOI] = NewObjId;

#if (OOI_CFG_SELECT_OOI_4_AND_5_NEXT_LONG)
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_RIGHT, OOI_OBJ_SELECTION_NEXT_LONG);
#else
  NewObjId = OOI_t_SelectNextObjectMoving(ASSOC_LANE_RIGHT, OOI_OBJ_SELECTION_NEXT_LATERAL);
#endif
  OOI_v_SelectStationaryObject(&NewObjId, OBJ_NEXT_LAT_RIGHT_OOI);
  if (NewObjId < 0)
  {
    if(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LONG_RIGHT_OOI] >= 0)
    {
       t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LONG_RIGHT_OOI]);
       if((t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING))
       {
          OOI_v_SelectOncomingObject(&NewObjId, OBJ_NEXT_LAT_RIGHT_OOI);
       }
    }
  }
  pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_LAT_RIGHT_OOI] = NewObjId;
  
#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
  if(((pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI]) >= 0) && ((pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI]) < EM_N_OBJECTS))
  {
    /* Select OOI-1 as OOI-0 when OOI-0 is a bike and is trying to overtake OOI-1 to avoid late approach of OOI-1 when OOI-0(Bike) is cut out */  
    OOI_v_BikeOvertake();
  }
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)*/

  /*save relevant object data*/
  if(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI] >= 0)
  {
    SLATE_p_GetFCTPubObj_OOI(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI])->eObjOOI = OBJ_NEXT_OOI;
    //OOI_OBJ_SET_OBJ_OF_INTEREST(pt_OOI_Output->OOI_ObjNumber[OBJ_NEXT_OOI], OBJ_NEXT_OOI);
  }

  OOI_v_ReInit();

  /*set relevantObjNr and object speed/accel*/
  for(nr = 0; nr < OOI_NUMBER_OF_OOI; nr++)
  {
    const ObjNumber_t CurObjId = pt_OOI_Output->OOI_ObjNumber[nr];
    if(CurObjId >= 0)
    {
      /* Set the AlreadyOOI flag, so that in the next loop of processing we
      can see that it has already been selected (even without the selection
      marks which are cleared at the beginning of each cycle) */
      t_OOI_ObjectList[CurObjId].t_Bool.AlreadyOOI = 1u;

      /* Check what object position the object had in the previous cycle */
      if (SLATE_p_GetFCTPubObj_OOI(CurObjId)->eObjOOI != OBJ_NOT_OOI)
      {
        /* The object was already one of the objects of interest in the
        previous cycle, so any state transition processing needed */
        switch(nr) 
        {
          /* Reset potentials if object changed lane from lateral to host lane.
            Reason: Potential on lateral lanes is Cut In potential, potential on host lane is Cut out potential,
            so these are different things and have to be calculated totally new. */
          case OBJ_NEXT_OOI:
          case OBJ_HIDDEN_NEXT_OOI:
            if (SLATE_p_GetFCTPubObj_OOI(CurObjId)->eObjOOI > OBJ_HIDDEN_NEXT_OOI)
            {
              SLATE_p_GetFCTPubObj(CurObjId)->LaneInformation.uiCutInProbability = 0u;
              //OBJ_GET_CUT_IN_POTENTIAL(CurObjId)  = 0u;
            }
            break;

          case OBJ_NEXT_LONG_LEFT_OOI:
          case OBJ_NEXT_LONG_RIGHT_OOI:
          case OBJ_NEXT_LAT_LEFT_OOI:
          case OBJ_NEXT_LAT_RIGHT_OOI:
            if (SLATE_p_GetFCTPubObj_OOI(CurObjId)->eObjOOI <= OBJ_HIDDEN_NEXT_OOI)
            {
              SLATE_p_GetFCTPubObj(CurObjId)->LaneInformation.uiCutInProbability = 0u;
              //OBJ_GET_CUT_IN_POTENTIAL(CurObjId)  = 0u;
            }
            break;

          default:
            break;
        }
      }
      else
      {
      }

      /* Store the relevant object number associated with the object */
      SLATE_p_GetFCTPubObj_OOI(CurObjId)->eObjOOI = nr;
      //OOI_OBJ_SET_OBJ_OF_INTEREST(CurObjId, nr);
    }
  }

  /* Determine relevant object loss reason. Note: this has to be called before 'pt_OOI_Output->t_OOI_RelObject' is updated
  with new selections information. The call in this position assumes that it has not yet been updated
  since the previous cycle. Previously this called was made directly after single object selection.
  Moved here so that object loss reason is set _after_ blocked path decision was also made to make
  object loss signal consistent with object selection. 
  Earlier this was called after OOI-0 selection but we also beed other OOI info as well,Moved at the bottom after all OOI's are filled */
#if (OBJLOSS_NUMBER_OF_OOI > 1)
  for(nr = 0; nr < OBJLOSS_NUMBER_OF_OOI; nr++)
  {
    OOI_v_ObReObRelObjLossReason(pt_OOI_Output->OOI_ObjNumber[nr], &pt_OOI_Output->t_OOI_RelObject[nr], nr);
  }
#else
  nr = 0;
  OOI_v_ObReObRelObjLossReason(pt_OOI_Output->OOI_ObjNumber[nr], &pt_OOI_Output->t_OOI_RelObject[nr], nr);
#endif /* (OBJLOSS_NUMBER_OF_OOI > 1) */
  
  /* Fill in relevant object loss reason in external interface */
  GET_FCT_PUB_OBJ_DATA_PTR->HeaderAssessedObjList.eRelObjLossReason = pt_OOI_Output->OOI_t_eRelObjVerlustGrund[OBJ_NEXT_OOI];
}/* PRQA S 7004 */
/* date: 2019-09-10, reviewer: Gowthama P , reason : Cyclomatic complexity. Not Safety critical*/

/*************************************************************************************************************************
  Functionname:    OOI_v_ComputePredictedDistance                                                                    */ /*!

  @brief           The function computes the predicted displacement to course and fills it to the output structure

  @description     The function computes the predicted displacement to course for all objects and fills it to the output structure

                   @startuml
                   Start
                   Partition OOI_v_ComputePredictedDistance{
                   Repeat 
                   :  Get Distance and Rel Trajectory;
                   Repeat While (Object number less than Number of Objects)
                   : Get Predicted Disp;
                   }
                  End
                  @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_OOI_Input : Reference to OOI input data structure                                                                        
                      t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to object to reference velocity measurement  [-330f   330f] m/s
  @glob_out        pt_OOI_Output : Reference to OOI output data structure
                      f_PredictedLatDispl[i]: Object predicted distance to trajectory [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0u ... OOI_NUMBER_OF_OOI]

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             Object lane association has to be finished for the current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.07.2018
  @changed         11.07.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static void OOI_v_ComputePredictedDistance(void)
{
  ObjNumber_t t_Obj;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  float32 f_DistanceToTraj;
  float32 f_VRelToTraj;

  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    f_DistanceToTraj = *(pt_OOI_Input->t_LAInput.pf_ObjToRefDistMeas(t_Obj));
    f_VRelToTraj     = *(pt_OOI_Input->t_LAInput.pf_ObjToRefDistGradFilt(t_Obj));

    pt_OOI_Output->f_PredictedLatDispl[t_Obj] = (f_DistanceToTraj) + (OOI_LAT_DISPL_PREDICTION_TIME * ((f_VRelToTraj)));
  }
#else
  for (t_Obj = 0u; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    pt_OOI_Output->f_PredictedLatDispl[t_Obj] = *(pt_OOI_Input->t_RTE.pf_ObjLatDisp(t_Obj));
  }
#endif
}

/*************************************************************************************************************************
  Functionname:    OOI_v_FillRelevantObjectStructure                                                                */ /*!

  @brief           Fill relevant object structure (is information for the next cycle) 

  @description     Fill relevant object structure (is information for the next cycle) 
          
          @startuml
          Start 
            Partition OOI_FillRelevantObjectStructure {
              If (Object is relevant object) then (true)
                - Update object attributes, i.e., OOI Output structure
              Else (false)
                - Reset Object of Interest data
              Endif 
              - Update object loss reason for objects of interest
            }
          End 
          @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_OOI_Output : Reference to OOI output data structure 
                      t_OOI_RelObject[i].ObjectNr      : Object Number (Object ID) range [0u ... EM_N_OBJECTS-1]
                      OOI_ObjNumber[OBJ_NEXT_OOI]   : Object-ID of ACC assessed 6-element array of objects of interest                       [0u ... EM_N_OBJECTS-1]   
                                                      with i in [0u ... OOI_NUMBER_OF_OOI] with OOI_NUMBER_OF_OOI as in ooi_ext.h
                      t_FIPInput.pf_ObjAbsVelX(i)   : Absolute object speed                                                                  [-330f   330f] m/s
                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_FIPInput.pf_ObjAbsAccelX(i) : Absolute object acceleration                                                           [-100f   100f] m/s^2
                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjCor.TrckFahr.dAblage_SpurGrenze_L : Maximal allowed deviation to left from ideal trajectory  [Full range of datatype dAblage_SpurGrenze_L as defined in la_ext.h] 
                                                                                           with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjCor.TrckFahr.dAblage_SpurGrenze_R : Maximal allowed deviation to right from ideal trajectory [Full range of datatype dAblage_SpurGrenze_R as defined in la_ext.h]
                                                                                           with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjTrajRelation                                                                        
                                                                    with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjCor.ObjCriteriaMatrix                                                               
                                                                             with i in [0u ... EM_N_OBJECTS-1]
                      OOI_t_eRelObjVerlustGrund(i) : Object loss reason                                                                    [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
                                                                        with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjLaneAccStatus.fCorridorRelevantDist : Distance of relevant object                   [0 ... 5*RW_FCT_MAX] m
                                                                                             with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjLaneAccStatus.LAInlaneState  : Lane assignment (confirmed with all criteria)        [Full range of datatype LA_t_LaneState as defined in fct_sen_feedback.h]
                                                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjLaneAccStatus.LAActLaneState : Lane assignment without timer and distance criteria  [Full range of datatype LA_t_LaneState as defined in fct_sen_feedback.h]
                                                                                      with i in [0u ... EM_N_OBJECTS-1]
                      t_LAInput.pt_LAObjectList(i)->ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [Full range of datatype fTime_t (float) as defined in Rte_Type.h]
                                                                                             with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Macro to retrieve dynamic property of given object i                                          [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                                             with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving by the radar earlier                 [TRUE, FALSE]
                                                   with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         * pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Lonigtudinal (X) distance of the object                                                      [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                                              with i in [0u ... EM_N_OBJECTS-1]   
  @glob_in         pt_OOI_Input->t_RTE.pf_ObjVRelX(i) : Relative velocity of object                                                                          [-330f   330f] m/s
                                      with i in [0u ... EM_N_OBJECTS-1]     
  @glob_in         pt_OOI_Input->t_RTE.pf_ObjArelX(i) : Relative acceleration of object                                                                      [-100f   100f] m/s^2
                                      with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OOI_Input->t_RTE.pf_EgoVelObjSync :                                                                                                  [-330.f ... 330.f] m/s
  @glob_in         EGO_MERGED_EGO_ACCEL_X_OBJ_SYNC :                                                                                       [-100.f … +100.f] m/s2 
  @glob_in         SLATE_f_GetObjectAngle(i) : Object angle                                                                                             [-PI   PI] rad
                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *pt_OOIInput->t_RTE.pf_ObjLatDisp(i) : Object lateral distance                                                                       [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                                             with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         OBJ_LAT_VREL(i) : Relative velocity of object                                                                           [-330f   330f] m/s
                                     with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         SLATE_b_GetObjIsNew(i)   : Boolean                                                                                               [TRUE, FALSE]
                                     with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        pt_OOI_Output : Reference to OOI output data structure [Full range of datatype OOIOutput_t as defined in ooi_ext.h]
                      t_OOI_RelObject[i].iLastObjektNr : Last Object Number (Object ID) range                                                 [0u ... EM_N_OBJECTS-1]
                      t_OOI_RelObject[i].ObjValid : Boolean which denotes if object is valid                                                  [TRUE, FALSE]
                      t_OOI_RelObject[i].StatObj : Boolean which denotes if object is stationary                                              [TRUE, FALSE]
                      t_OOI_RelObject[i].MovingToStat : Boolean which denotes if object turned from moving stationary                         [TRUE, FALSE]
                      t_OOI_RelObject[i].DistX : Lonigtudinal (X) distance of the object                                                      [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      t_OOI_RelObject[i].RelSpeedX : Relative velocity of object in X direction                                               [-330f   330f] m/s
                      t_OOI_RelObject[i].RelAcclX : Relative acceleration of object in X direction                                            [-100f   100f] m/s^2
                      t_OOI_RelObject[i].ObjSpeed : Absolute object speed                                                                     [-330f   330f] m/s
                      t_OOI_RelObject[i].ObjAccl : Absolute object acceleration                                                               [-100f   100f] m/s^2
                      t_OOI_RelObject[i].ObjAngle : Object angle                                                                              [-PI   PI] rad
                      t_OOI_RelObject[i].ObjDistY : Object lateral distance                                                                   [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      t_OOI_RelObject[i].RelSpeedY : Relative speed in lateral direction                                                      [-330f   330f] m/s
                      t_OOI_RelObject[i].LatDisplRoadBordL : lateral displacement of lane border (left)                                       [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      t_OOI_RelObject[i].LatDisplRoadBordR : lateral displacement of lane border (right)                                      [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                      t_OOI_RelObject[i].RelPickupDist : pick up (X) distance                                                                 [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      t_OOI_RelObject[i].ObjectNr : Object number                                                                             [ObjNumber_t defined in Rte_Type.h] [-1   39]
                      t_OOI_RelObject[i].fDist_4mss : Distance to hard brake                                                                  [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      t_OOI_RelObject[i].fDist_2mss : Distance to comfort brake                                                               [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                      t_OOI_RelObject[i].ObjTrajRelation                                                                                      
                      t_OOI_RelObject[i].ObjCriteriaMatrix                                                                                    
                      t_OOI_RelObject[i].LossReason : Relevant object loss reason                                                             [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
                      t_OOI_RelObject[i].ObjLaneAccStatus.fCorridorRelevantDist : Distance of relevant object                                 [0 ... 5*RW_FCT_MAX] m
                      t_OOI_RelObject[i].ObjLaneAccStatus.LAInlaneState : Lane assignment (confirmed with all criteria)                       [Full range of datatype LA_t_LaneState as defined in fct_sen_feedback.h]
                      t_OOI_RelObject[i].ObjLaneAccStatus.LAActLaneState : Lane assignment without timer and distance criteria (unconfirmed)  [Full range of datatype LA_t_LaneState as defined in fct_sen_feedback.h]
                      t_OOI_RelObject[i].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane               [Full range of datatype fTime_t (float) as defined in Rte_Type.h]
                      
  @c_switch_part   FCT_SIMU                     : FCT Simulation switch
  @c_switch_part   SIT_CFG_FILTER_ABS_OBJ_SPEED : Configuration switch for enabling absolute speed calculation per object in SI
  @c_switch_part   SIT_CFG_FILTER_ABS_OBJ_ACCEL : Configuration switch for enabling filtered absolute acceleration
  @c_swirch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_OOI              : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          -
*************************************************************************************************************************/
void OOI_v_FillRelevantObjectStructure(void)
{
  ObjNumber_t nr;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  boolean b_ObjIsMovingToStationary;
  for (nr = 0; nr < OBJLOSS_NUMBER_OF_OOI;nr++)
  {
    /* Store last object index */
    pt_OOI_Output->t_OOI_RelObject[nr].iLastObjektNr = pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr;

    if (pt_OOI_Output->OOI_ObjNumber[nr] >= 0)
    {
      const ObjNumber_t CurObjId = pt_OOI_Output->OOI_ObjNumber[nr];
      pt_OOI_Output->t_OOI_RelObject[nr].ObjValid = TRUE;
      t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(CurObjId);
      if( (t_ObjDynProperty  == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
       || (t_ObjDynProperty  == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
        )
      {
        pt_OOI_Output->t_OOI_RelObject[nr].StatObj = TRUE;
      }
      else
      {
        pt_OOI_Output->t_OOI_RelObject[nr].StatObj = FALSE;
      }

      b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(CurObjId);
      if (b_ObjIsMovingToStationary)
      {
        pt_OOI_Output->t_OOI_RelObject[nr].MovingToStat        = TRUE;
      }
      else
      {
        pt_OOI_Output->t_OOI_RelObject[nr].MovingToStat        = FALSE;
      }

      pt_OOI_Output->t_OOI_RelObject[nr].DistX               = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(CurObjId);
      pt_OOI_Output->t_OOI_RelObject[nr].RelSpeedX           = *pt_OOI_Input->t_RTE.pf_ObjVRelX(CurObjId);
      pt_OOI_Output->t_OOI_RelObject[nr].RelAcclX            = *pt_OOI_Input->t_RTE.pf_ObjArelX(CurObjId);

#if (SIT_CFG_FILTER_ABS_OBJ_SPEED)
      pt_OOI_Output->t_OOI_RelObject[nr].ObjSpeed            = pt_OOI_Input->pt_FIPInput->t_ObjList[CurObjId].fAbsVelocity;
#else
      pt_OOI_Output->t_OOI_RelObject[nr].ObjSpeed            = *pt_OOI_Input->t_RTE.pf_ObjVRelX(CurObjId) + *pt_OOI_Input->t_RTE.pf_EgoVelObjSync;
#endif
#if (SIT_CFG_FILTER_ABS_OBJ_ACCEL)
      pt_OOI_Output->t_OOI_RelObject[nr].ObjAccl             = pt_OOI_Input->pt_FIPInput->t_ObjList[CurObjId].fAbsAcceleration;
#else
      pt_OOI_Output->t_OOI_RelObject[nr].ObjAccl             = *pt_OOI_Input->t_RTE.pf_ObjArelX(CurObjId) + SLATE_f_GetEgoCorrectedAccel();
#endif

      pt_OOI_Output->t_OOI_RelObject[nr].ObjAngle            = SLATE_f_GetObjectAngle(CurObjId);
      pt_OOI_Output->t_OOI_RelObject[nr].ObjDistY            = *pt_OOI_Input->t_RTE.pf_ObjLatDisp(CurObjId);
      pt_OOI_Output->t_OOI_RelObject[nr].RelSpeedY           = *pt_OOI_Input->t_RTE.pf_ObjVRelY(CurObjId);
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      pt_OOI_Output->t_OOI_RelObject[nr].LatDisplRoadBordL   = (pt_OOI_Input->t_LAInput.pt_LAObjectList(CurObjId)->ObjCor.TrckFahr.dAblage_SpurGrenze_L);
      pt_OOI_Output->t_OOI_RelObject[nr].LatDisplRoadBordR   = (pt_OOI_Input->t_LAInput.pt_LAObjectList(CurObjId)->ObjCor.TrckFahr.dAblage_SpurGrenze_R);
#endif

      /* On relevant object change, store the first pickup distance (formerly stored separately
      for each object in dAbst_RelevantNeu */
      if (pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr != CurObjId)
      {
        pt_OOI_Output->t_OOI_RelObject[nr].RelPickupDist     = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(CurObjId);
      }

      pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr            = CurObjId;

#if (OBJLOSS_NUMBER_OF_OOI > 1)
      if (nr == 0)
      {
        OUT_v_SeReObPutRelTrckObjNumber(CurObjId);
      }
#else
      OUT_v_SeReObPutRelTrckObjNumber(CurObjId);
#endif /* (OBJLOSS_NUMBER_OF_OOI > 1) */

#ifdef FCT_SIMU

      pt_OOI_Output->t_OOI_RelObject[nr].fDist_4mss = GDBGetPickupDist(pt_OOI_Output->t_OOI_RelObject[nr].RelSpeedX, *pt_OOI_Input->t_RTE.pf_EgoVelObjSync, OOI_PICKUP_DISTANCE_HARD_BRAKE_EGO_DECELERATION, OOI_PICKUP_DISTANCE_GAP_TIME, OOI_PICKUP_DISTANCE_LATENCY_TIME); /*Dsitance hard breake*/
      pt_OOI_Output->t_OOI_RelObject[nr].fDist_2mss = GDBGetPickupDist(pt_OOI_Output->t_OOI_RelObject[nr].RelSpeedX, *pt_OOI_Input->t_RTE.pf_EgoVelObjSync, OOI_PICKUP_DISTANCE_COMFORT_BRAKE_EGO_DECELERATION, OOI_PICKUP_DISTANCE_GAP_TIME, OOI_PICKUP_DISTANCE_LATENCY_TIME); /*Distance comfort break*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      pt_OOI_Output->t_OOI_RelObject[nr].ObjTrajRelation   = (pt_OOI_Input->t_LAInput.pt_LAObjectList(CurObjId)->ObjTrajRelation);
      pt_OOI_Output->t_OOI_RelObject[nr].ObjCriteriaMatrix = (pt_OOI_Input->t_LAInput.pt_LAObjectList(CurObjId)->ObjCor.ObjCriteriaMatrix);
#endif

#endif

      /* Project specific */
    }
    else
    {
      /* Initialisierung des relevanten Objekts */
      OOI_v_SIReSiDaRelObjInit(nr);

#if (OBJLOSS_NUMBER_OF_OOI > 1)
      if (nr == 0)
      {
        OUT_v_SeReObPutRelTrckObjNumber(OBJ_INDEX_NO_OBJECT);
      }
#else
      OUT_v_SeReObPutRelTrckObjNumber(OBJ_INDEX_NO_OBJECT);
#endif /* (OBJLOSS_NUMBER_OF_OOI > 1) */
    }

    pt_OOI_Output->t_OOI_RelObject[nr].LossReason  = pt_OOI_Output->OOI_t_eRelObjVerlustGrund[nr];

    /* Update the RelObjCounter when same object is OOI in consecutive cycles*/
    if ((pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr != OBJ_INDEX_NO_OBJECT) && 
      (pt_OOI_Output->t_OOI_RelObject[nr].iLastObjektNr  == pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr))
    {
      if(pt_OOI_Output->t_OOI_RelObject[nr].RelObjCounter < OOI_RELEVANTOBJ_COUNTER_MAX)
      {
        pt_OOI_Output->t_OOI_RelObject[nr].RelObjCounter += 1u;
      
      }
      else
      {
        pt_OOI_Output->t_OOI_RelObject[nr].RelObjCounter = OOI_RELEVANTOBJ_COUNTER_MAX;
      }
    }
    else /* if current cycle OOI does not have object ID or is not equal to last cycle OOI*/
    {
      pt_OOI_Output->t_OOI_RelObject[nr].RelObjCounter = 0u;
    }

#ifdef FCT_SIMU
    if(pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr != pt_OOI_Output->t_OOI_RelObject[nr].iLastObjektNr)
    {
      if(pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr >= 0)
      {
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.fCorridorRelevantDist  = (pt_OOI_Input->t_LAInput.pt_LAObjectList(pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr)->ObjLaneAccStatus.fCorridorRelevantDist);
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.LAInlaneState          = (pt_OOI_Input->t_LAInput.pt_LAObjectList(pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr)->ObjLaneAccStatus.LAInlaneState);
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.LAActLaneState         = (pt_OOI_Input->t_LAInput.pt_LAObjectList(pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr)->ObjLaneAccStatus.LAActLaneState);
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.fCorridorRelevantTime  = (pt_OOI_Input->t_LAInput.pt_LAObjectList(pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr)->ObjLaneAccStatus.fCorridorRelevantTime);
#endif /* END IF (FCT_CFG_ACC_LANE_ASSOCIATION) */
      }
      else
      {
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.fCorridorRelevantDist  = 0.0f;
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.LAInlaneState          = OBJ_STATE_INLANE;
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.LAActLaneState         = OBJ_STATE_INLANE;
        pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus.fCorridorRelevantTime  = 0.0f;
      }
    }

  //FCT_FREEZE_DATA(&OOI_RelObject_MeasInfo, &pt_OOI_Output->t_OOI_RelObject, &OOI_v_MeasCallback);
#endif
  }
}

/*************************************************************************************************************************
  Functionname:    OOI_v_SIReSiDaRelObjInit                                                                               */ /*!

  @brief           Initializing relevant objects

  @description     Initializing relevant objects
          
          @startuml
          Start 
            Partition OOI_RelevantObjectInitialization {
              - Initialize objects of interest data
            }
          End 
          @enduml

  @return          static void

  @param[in]       -
  @param[out]      -

  @glob_in          pt_OOI_Output->t_OOI_RelObject[i].ObjCriteriaMatrix                                                
  @glob_in          pt_OOI_Output->t_OOI_RelObject[i].ObjTrajRelation                                                  
  @glob_in          pt_OOI_Output->t_OOI_RelObject[i].ObjLaneAccStatus                                                 
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].ObjValid : To check if object is valid, boolean                           [TRUE, FALSE]
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].StatObj : To check if object is stationary, boolean                       [TRUE, FALSE]
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].MovingToStat : To check if a moving object has turned stationary, boolean [TRUE, FALSE]
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].DistX : Lonigtudinal (X) distance of the object                           [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].RelSpeedX : Relative velocity of object in X direction                    [-330f   330f] m/s
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].RelAcclX : Relative acceleration of object in X direction                 [-100f   100f] m/s^2
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].ObjSpeed : Absolute object speed                                          [-330f   330f] m/s
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].ObjAccl : absolute object acceleration                                    [-100f   100f] m/s^2
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].ObjAngle : object angle                                                   [-PI   PI] rad
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].ObjDistY : Object lateral distance                                        [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].RelSpeedY : Relative speed in lateral direction                           [-330f   330f] m/s
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].LatDisplRoadBordL : lateral displacement of lane border (left)            [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].LatDisplRoadBordR : lateral displacement of lane border (right)           [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].RelPickupDist : pick up (X) distance                                      [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].ObjectNr : Object number                                                  [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].fDist_4mss : Distance to hard brake                                       [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
  @glob_out         pt_OOI_Output->t_OOI_RelObject[i].fDist_2mss : Distance to comfort brake                                    [-5*RW_FCT_MAX   5*RW_FCT_MAX] m

  @c_switch_part   FCT_SIMU : FCT Simulation switch
  @c_switch_full   -

  @pre             SI finished
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/22/2016

  @todo            create function

  @author          Robert Thiel
*************************************************************************************************************************/
void OOI_v_SIReSiDaRelObjInit ( ObjNumber_t nr )
{
  pt_OOI_Output->t_OOI_RelObject[nr].ObjValid            = FALSE;
  pt_OOI_Output->t_OOI_RelObject[nr].StatObj             = FALSE;
  pt_OOI_Output->t_OOI_RelObject[nr].MovingToStat        = FALSE;

  pt_OOI_Output->t_OOI_RelObject[nr].DistX               = 0.0f;
  pt_OOI_Output->t_OOI_RelObject[nr].RelSpeedX           = 0.0f;
  pt_OOI_Output->t_OOI_RelObject[nr].RelAcclX            = 0.0f;

  pt_OOI_Output->t_OOI_RelObject[nr].ObjSpeed            = 0.0f;
  pt_OOI_Output->t_OOI_RelObject[nr].ObjAccl             = 0.0f;

  pt_OOI_Output->t_OOI_RelObject[nr].ObjAngle            = 0.0f;
  pt_OOI_Output->t_OOI_RelObject[nr].ObjDistY            = 0.0f;
  pt_OOI_Output->t_OOI_RelObject[nr].RelSpeedY           = 0.0f;

  pt_OOI_Output->t_OOI_RelObject[nr].LatDisplRoadBordL   = 0.0f;
  pt_OOI_Output->t_OOI_RelObject[nr].LatDisplRoadBordR   = 0.0f;

  pt_OOI_Output->t_OOI_RelObject[nr].RelPickupDist       = 0.f;

  pt_OOI_Output->t_OOI_RelObject[nr].ObjectNr            = OBJ_INDEX_NO_OBJECT;

#ifdef FCT_SIMU

  pt_OOI_Output->t_OOI_RelObject[nr].fDist_4mss = 0.0F; /*Distance hard brake*/
  pt_OOI_Output->t_OOI_RelObject[nr].fDist_2mss = 0.0F; /*Distance comfort brake*/

  memset(&pt_OOI_Output->t_OOI_RelObject[nr].ObjCriteriaMatrix, 0, sizeof(pt_OOI_Output->t_OOI_RelObject[nr].ObjCriteriaMatrix));
  memset(&pt_OOI_Output->t_OOI_RelObject[nr].ObjTrajRelation, 0, sizeof(pt_OOI_Output->t_OOI_RelObject[nr].ObjTrajRelation));
  memset(&pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus, 0, sizeof(pt_OOI_Output->t_OOI_RelObject[nr].ObjLaneAccStatus));

#endif
}

/*************************************************************************************************************************
  Functionname:    OOI_v_SelectOOI                                                                                      */ /*!

  @brief           This function handles the flags for selection

  @description     This function handles the flags for selection
  
  					@startuml
					Start 
						Partition OOI_SelectOOI {
							- select object as one of the Object Of Interest
						}
					End 
					@enduml

  @return          -

  @param[in]       ObjectToSelect : Object number to be selected                                                  [-1 ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        t_OOI_ObjectList[ObjectToSelect].t_Bool.SelectedAsOOI : Object is candidate for the OOI list           [0,1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI :  FCT support for ACC OOI sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Fridolin Kolb | Fridolin Kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void OOI_v_SelectOOI(ObjNumber_t ObjectToSelect)
{
  t_OOI_ObjectList[ObjectToSelect].t_Bool.SelectedAsOOI = 1u;
}

/*************************************************************************************************************************
  Functionname:    OOI_v_UnSelectOOI                                                                                    */ /*!

  @brief           Unselect passed object as object of interest

  @description     Unselect passed object as object of interest
  
  					@startuml
					Start 
						Partition OOI_UnSelectOOI {
							- deselect object as Object of Interest
						}
					End 
					@enduml

  @return          -

  @param[in]       ObjectToUnSelect : Object number to be unselected                                                [-1 ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        t_OOI_ObjectList[ObjectToUnSelect].t_Bool.SelectedAsOOI : Object is candidate for the OOI list           [0,1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI :  FCT support for ACC OOI sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Fridolin Kolb | Fridolin Kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void OOI_v_UnSelectOOI(ObjNumber_t ObjectToUnSelect)
{
  t_OOI_ObjectList[ObjectToUnSelect].t_Bool.SelectedAsOOI = 0u;
}

/*************************************************************************************************************************
  Functionname:    OOI_v_BlockedPathDecision                                                                                   */ /*!

  @brief           Blocked path objects decision

  @description     Function gets addresses of pointer to relevant object and hidden object passed. If previously run 
                    algorithms did not select these objects, than the pointers pointed to may be NULL 
                    If blocked corridor detection indicates that vehicle path is blocked,
                    then these pointers are replaced by the objects blocking the path.
					@startuml
					Start 
						Partition OOI_BlockedPathDecision {
							If (Objects blocking path detected) then (TRUE)
								- Calculate close and Far objects
								If (Are objects different from single object selection selected object) then (TRUE)
									If (Next object is valid) then (TRUE)
										- Calculate long displacement
									Endif 
									If (Next object is valid and long displacement is less than far object displacement) then (TRUE)
					
									Else (FALSE)
										If (Far object is in last cycle or Next object) then (TRUE)
											If (Far object was relevant object in last cycle) then (TRUE)
												If (Next object is valid)
													- Unselect single inlane objects
												Endif 
												- Far object relevance changes to close object only if far object dist to trajectory is twice as big as close object
												- Close object is relevant object, far object is next hidden
											Else (FALSE)
												- Next object gets hidden next, if existing
												- Select Far object as OOI object
											Endif 
										Else if (Close object is OOI 0 in last cycle) then (TRUE)
											If (Close object was relevant object in last cycle) then (TRUE)
												If (Next object is not Far object) then (TRUE)
													If (Hidden object is valid) then (TRUE)
														- Unselect hidden object

													Endif 
													- Select hidden object as Next object
												Endif 
												- Select Next object as Far object
												- Select Far object as OOI object
											Else (FALSE)
												- Unselect single inlane objects
												- Keep relevance of close object, far object is next hidden
											Endif 
										Else (FALSE)
											If (Far object distance trajectory is more than Close object distance trajectory) then (TRUE)
												- Unselect single inlane objects
												- Select close object is relevant object, far object is next hidden
											Else (FALSE)
												If (Hidden object exits) then (TRUE)
													- Unselect hidden object 
													- Select far object gets relevant, leave close object free for neigbour object selection
												Endif 
											Endif 	
										Endif 
									Endif 
		
								Endif  
							Endif 
	
						}
					End 
					@enduml

  @return          -

  @param[in,out]   pNextObjId : Pointer to ID of currently selected next object (relevant object). If blocked corridor
                        examination determines a blocked path, the object pointer is replaced by the ID of the object 
                        blocking the path                                                                                           [-1 ... 39]
  @param[in,out]   pHiddenObjId : Pointer to ID of currently selected hidden object (object in path but farther away than 
                        relevant object). If blocked corridor examination determines a blocked path, the object ID is replaced
                        by the ID of the object blocking the path                                                                   [-1 ... 39]

  @glob_out         -

  @glob_in          -

  @c_switch_part   -

  @c_switch_full   FCT_CFG_ACC_OOI :  FCT support for ACC OOI sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    186:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-186-00061542 \n

  @created         07.07.2017
  @changed         -

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void OOI_v_BlockedPathDecision(ObjNumber_t * const pNextObjId, ObjNumber_t * const pHiddenObjId)
{
  float32 FarObjDistTraj;
  float32 CloseObjDistTraj;
  float32 fDistXFarObjId;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  float32 fDistXCloseObjId;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  float32 ObjLongDispNextObjId=0.f;
  uint8 u_PathSelectionTimer_CloseObj, u_PathSelectionTimer_FarObj, u_BlockedPathSelectionTime;
  ObjNumber_t CloseObjId, FarObjId;
  boolean b_EgoLaneValidity = TRUE;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  const boolean b_EgoLaneStatus = (pt_OOI_Input->t_SITInput.pt_GetLaneChangePhase->b_EgoLaneStatus);
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
 
  CloseObjId = *pt_OOI_Input->t_SITInput.pt_BlockedPathCloseObjID;
  FarObjId = *pt_OOI_Input->t_SITInput.pt_BlockedPathFarObjID;
  fDistXFarObjId = *pt_OOI_Input->t_SITInput.pf_DistXFarObjId;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  fDistXCloseObjId = *pt_OOI_Input->t_SITInput.pf_DistXCloseObjId;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  FarObjDistTraj = *pt_OOI_Input->t_SITInput.pf_FarObjDistTraj;
  CloseObjDistTraj = *pt_OOI_Input->t_SITInput.pf_CloseObjDistTraj;

  /* Objects blocking path detected ? */
  if ((CloseObjId >= 0) && (FarObjId >= 0))
  {
    b_EgoLaneValidity = (pt_OOI_Input->t_LAInput.pt_LAObjectList(CloseObjId)->b_SetEgoLaneValidity);
    u_PathSelectionTimer_CloseObj = *pt_OOI_Input->t_SITInput.pu_BlockedPathSelectionTimer(CloseObjId);
    u_PathSelectionTimer_FarObj = *pt_OOI_Input->t_SITInput.pu_BlockedPathSelectionTimer(FarObjId);

    /* Minimum time threshold needed for the objects to be selected as blocked path close and far objects */
      u_BlockedPathSelectionTime = SIT_BLOCKED_PATH_DECISION_TIME_THRESHOLD;

    if( ((u_PathSelectionTimer_CloseObj > u_BlockedPathSelectionTime) ||
        (u_PathSelectionTimer_FarObj > u_BlockedPathSelectionTime)) &&
        (b_EgoLaneValidity == TRUE) /* Blocked path object check considered only with Ego Lane Validity */
      )
    {
      /* Are objects different from single object selection selected object */
      if ((CloseObjId != *pNextObjId) && (FarObjId != *pNextObjId))
      {
        if(*pNextObjId >= 0)
        {
          ObjLongDispNextObjId = (*SLATE_pf_GetObjLongDisp(*pNextObjId));
        }
        /* check for next object */
        if ((*pNextObjId >= 0) && (ObjLongDispNextObjId < fDistXFarObjId))
        {
          /* Review: N. Apel & G. Ungvary: the code in this branch for ARS300/ARS310 was completely
          inactive - removed. Logically this is the case when single object selection selected an
          object closer than FarObj. */
        }
        else 
        {
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
            if((b_EgoLaneStatus == TRUE) || ( FarObjDistTraj > CloseObjDistTraj)) 
            {
              if(*pNextObjId < 0)
              {
                /* close object only gets relevant if far object dist to trajectory
                is twice as big as close object or 
                Close object is selected as Ego is in Left most or right most lane.
                --> close object is relevant object, far object is next hidden */
                *pNextObjId = CloseObjId;
                OOI_v_SelectOOI(CloseObjId);
              }
              else
              {
                if(ObjLongDispNextObjId > fDistXCloseObjId)
                {
                  OOI_v_UnSelectOOI(*pNextObjId);

                  /* close object only gets relevant if far object dist to trajectory
                  is twice as big as close object or 
                  Close object is selected as Ego is in Left most or right most lane.
                  --> close object is relevant object, far object is next hidden */
                  *pNextObjId = CloseObjId;
                  OOI_v_SelectOOI(CloseObjId);
                }
                else
                {
                  /*Present OOI-0 is selected as OOI-0 until the blocked path counter becomes less than 9.*/
                }

              }
				
            }
#else
            /* no in lane  object in last cycle */
            if( FarObjDistTraj > CloseObjDistTraj)
            {
              /* Unselect single inlane objects */
              if(*pNextObjId >= 0)//PRQA S 715
                /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Need to change control structure if rule agrred upon*/
              {
                OOI_v_UnSelectOOI(*pNextObjId);
              }
              /* close object only gets relevant if far object dist to trajectory
              is twice as big as close object
              --> close object is relevant object, far object is next hidden */
              *pNextObjId = CloseObjId;
              OOI_v_SelectOOI(CloseObjId);
            }
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
            else
            {
              /* next object gets hidden next, if existing */
              if(*pHiddenObjId >= 0)//PRQA S 715
                /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Need to change control structure if rule agrred upon*/
              {
                /* Unselect hidden object */
                OOI_v_UnSelectOOI(*pHiddenObjId);
              }

              *pHiddenObjId = *pNextObjId;

              /* far object gets relevant, leave close object free for neigbour object selection */
              *pNextObjId = FarObjId;
              OOI_v_SelectOOI(FarObjId);
            }
          

#if (LA_CFG_DTR_OBJ_SELECTION)
          /* DTR specific lane and lane-timer assignment */
          if(( *pNextObjId == CloseObjId)
            || (*pNextObjId == FarObjId)  )
          {
            /* One of the blocking object has been selected as OOI-0, but the object may
            still be associated to an adjacent lane, instead of the ego-lane.
            This is fixed here for the DTR specific lane assignment. */
            pSLATE_CustomOutput->CustObjData[*pNextObjId].DTR_ObjData.DTR_Obj_LaneDistTime = 1u;
            pSLATE_CustomOutput->CustObjData[*pNextObjId].DTR_ObjData.DTR_Obj_Lane_v2      = DTR_LANE_EGO;
          }
#endif

        }
      } /* End if Far/Close object not selected by single-object selection */
    }/* end if blocked path timer ? */
  }
    else
    {
      /* Blocking path object not found (far/close object ID negative) */
    }
}
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup ooi*/
#endif /* END IF FCT_CFG_ACC_OOI */


/*****************************************************************************
AUFHEBUNG MODULLOKALER SYMBOLISCHE KONSTANTEN
*****************************************************************************/

