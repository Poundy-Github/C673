/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_main.c

DESCRIPTION:               Main functions for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.60 $

LEGACY VERSION:            Revision: 2.3.1.2

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
@defgroup la_main Main
@ingroup la
@brief          This module provides amongst others the main function of the SLATE Component. \n\n

@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/



/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/
#if ((LA_CFG_O2O_EGO_LANE_ASSOC) || (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) || (LA_CFG_DTR_OBJ_SELECTION))
SET_MEMSEC_VAR(t_LA_InternalObjectData)
LA_InternalObjectData_t t_LA_InternalObjectData;
#endif

SET_MEMSEC_VAR(LA_t_State)
SLATECompState_t LA_t_State;       /*!< Operating modes of LA sub-component */

/*! Definition of component internal pointer to LA Input structure for global access within LA */
SET_MEMSEC_VAR(pt_LAInput)
LAInputConst_t * pt_LAInput;

/*! Definition of constant extern pointer to LA output structure for usage in other components */
SET_MEMSEC_VAR(pt_LAOutput)
LAOutput_t * pt_LAOutput;

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
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

static void LA_v_Init(void);
static void LA_v_InitEveryCycle(void);
static void LA_v_InitPersistentData(void);
static void LA_v_SetInput(void);
static void LA_v_Obj2TrajInit (void);
static void LA_v_MeasFreeze(void);
static void LA_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);

/*************************************************************************************************************************
  Functionname:    LA_v_PreProcess                                                                                  */ /*!

  @brief           Preprocess / Set inputs to LA module

  @description     Preprocess / Set inputs to LA module
                   @startuml
                   Partition LA_v_PreProcess{
                   Start
                   Partition #Lightblue **LA_v_MergeDeleteObjects** {
                   -Handle all merging and deleting of objects lists based on decisions taken in Frame
                   }
                   
                   Partition #Lightblue **LA_v_SetInput** {
                   -Fill out input structure in LA module using outputs from other provider modules
                   }
                   
                   end
                   }
                   @enduml

  @return          void

  @param[in,out]   pt_LA_InputGlobal : Reference to LA input structure instantiated in Frame

  @glob_in         -
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

  @created         24.10.2016
  @changed         24.10.2016
  
  @todo            Replace OBJ_GET_CP macro

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void LA_v_PreProcess(LAInputConst_t * pt_LA_InputGlobal, LAOutput_t * pt_LA_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  /* Assign local pointers */
  pt_LAInput = pt_LA_InputGlobal;
  pt_LAOutput = pt_LA_OutputGlobal;

  /* Handle Merge Delete Object Lists */
  LA_v_MergeDeleteObjects(t_MergeDeleteObjList);

  /* Set Inputs */
  LA_v_SetInput();

  /* Reset local pointers */
  pt_LAInput = NULL;
  pt_LAOutput = NULL;
}

/*************************************************************************************************************************
  Functionname:    LA_v_Process                                                                                     */ /*!

  @brief           Main processing function of LA sub-component

  @description     Main processing function of LA sub-component

                   @startuml
                   Partition LA_v_Process {
                   Start
                   if (LA_OK) then (OK)
                        :Initialization for every cycle
                        <b>LA_v_InitEveryCycle</b>;
                        repeat
                        :Update object distance to trajectory
                        <b>CPUpdateObjDist2Traj</b>;
                        :Search for a near neighboring object for the given object which is on the same side of the ACC-trajectory 
                        as the given object. The given object should be on the ego lane.
                        <b>LA_t_FindNearNeighboringObjToEgoLane</b>;
                        repeat while (do for every objects\n<b>EM_N_OBJECTS</b>)
                        :Perform O2O relation based lane association
                        <b>LA_v_PerformO2OLaneAssociation</b>;
                        :Preselect objects for acc functionality
                        <b>LA_v_ObjectPreselection</b>;
                        :Calculate the associated lane for each object.
                        <b>LA_v_LaneAssociation</b>;
                      else (NOT_OK)
                        :Initialization
                        <b>LA_v_Init</b>;
                      endif
                   end
                   }
                   @enduml

  @return          void

  @param[in,out]   pt_LA_InputGlobal : Reference to LA input structure
                     pt_LAInput->t_CP.pt_TrajectoryData : Pointer Structure containing Ego Course Prediction Data claculated in CP component
  @param[in,out]   pt_LA_OutputGlobal : Reference to LA output structure

  @glob_in         LA_t_State : Operating modes of LA sub-component       Datatype of enum LAState_t as defined in la_ext.h
  @glob_out        pt_LAInput : Pointer to LA input structure
  @glob_out        pt_LAOutput : Pointer to LA output structure

  @c_switch_part   LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : Configuration switch to enbale bracket extension for relvant object
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : Configuration switch to enable restriction based on relevant object trace
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             LA_v_PreProcess (LAInputConst_t * pt_LA_InputGlobal) Inputs should be set
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         5/14/2017

  @todo            -

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void LA_v_Process(LAInputConst_t * pt_LA_InputGlobal, LAOutput_t * pt_LA_OutputGlobal)
{
  ObjNumber_t iObj; /* RESTUCTURE: Move loop in separate function */
  boolean bObjIsDeleted;
  const CP_t_TrajectoryData * pTrajectoryData;

  /*! Set component global pointer to input structure for global access within the component */
  pt_LAInput = pt_LA_InputGlobal;
  pt_LAOutput = pt_LA_OutputGlobal;

  pTrajectoryData = pt_LAInput->t_CP.pt_TrajectoryData; 
  switch(LA_t_State)
  {
  case COMP_STATE_RUNNING:
    /*! Functions calls for normal operation mode */
    
    /* Initialize Input-Output for LA module */
    LA_v_InitEveryCycle();

    /* RESTUCTURE: Move loop in separate function */
    for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
    {
      bObjIsDeleted = SLATE_b_GetObjIsDeleted(iObj);
      if( !bObjIsDeleted)
      {
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
        CPUpdateObjDist2Traj(iObj , 3.0f * SLATE_p_GetEMARSObjKinematic(iObj)->fMaxAccelY + LA_ACC_MAXACCELTRAJDIST, pTrajectoryData, &(OBJ_GET_CP(iObj)));
#else
        CPUpdateObjDist2Traj(iObj , 3.0f + LA_ACC_MAXACCELTRAJDIST, pTrajectoryData, &(OBJ_GET_CP(iObj)));
#endif
      }
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
      LA_t_FindNearNeighboringObjToEgoLane(iObj);
#endif
    }

    /* Perform object-to-object (O2O) relation based lane association */
    LA_v_PerformO2OLaneAssociation(); /* Restructure, if O2O finalized: move to SIT (including LA-Object-List attributes) */

    /*! Perform object ACC pre-selection */
    LA_v_ObjectPreselection();

#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
      LA_v_Camera_CutIn_CutOut_Potential();
#endif
    /*! Corridor calculation and lane association -> Function call corridor calculation to be moved here */
    LA_v_LaneAssociation();
    break;
  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
    /*! Default */
    LA_v_Init();
    break;
  }

  /* LA Measurement Freeze */
  LA_v_MeasFreeze();

  /*! Initialize component global input pointer since not used anymore */
  pt_LAInput = NULL;
  pt_LAOutput = NULL;
}


/*************************************************************************************************************************
  Functionname:    LA_v_Init                                                                                        */ /*!

  @brief           Initialize input-output data structures for LA component

  @description     Initialize input-output data structures for LA component
                   @startuml
                   Partition LA_v_Init {
                   Start
                   Partition #Lightblue  **LA_v_InitPersistentData** {
                   -Initialize persistent memory in LA module
                   }
                   
                   Partition #Lightblue  **LA_v_InitEveryCycle** {
                   - Initialize Input-Output for LA module
                   }
                   End
                   }
                   @enduml
  @return          static void

  @param[in]       -

  @glob_in         -
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

  @created         -
  @changed         5/14/2017

  @todo            -

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_Init(void)
{
  /* Initialize persistent memory in LA module */  
  LA_v_InitPersistentData();

  /* Initialize Input-Output for LA module */
  LA_v_InitEveryCycle();
}

/*************************************************************************************************************************
  Functionname:    LA_v_InitPersistentData                                                                          */ /*!

  @brief           Initialize persistent memory structures in LA module

  @description     Initialize persistent memory structures in LA module
                   @startuml
                   Partition LA_v_InitPersistentData {
                   Start
                   - Initialize inputs to LA module
                   - Initialize input from SIT
                   - Initialize outputs
                   - Initialize the pick up range for moving objects depending on ego relative velocity
                   - Initialize the timer based on Indicator
                   Partition #Lightblue **LA_v_InitAccFunPreselection** {
                   - Initialize ACC function pre-selection
                   }
                   
                   Partition #Lightblue **LA_v_CorridorInit** {
                   - Initialize SI corridor module specific data
                   }
                   
                   Partition #Lightblue **LA_v_Obj2TrajInit** {
                   - initializes all Object to Trajectory related variables
                   }
                   
                   Repeat 
                   Partition #Lightblue **LA_v_DeleteObject** {                                                                    
                   - Delete objects marked for deletion
                   }
                   Repeat while(For all EM object list)
                   
                   Partition #Lightblue **LA_v_InitCustom** {                                                                    
                   - Initialize customer specific object data
                   }
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       -

  @glob_in         None 
  @glob_out        pt_LAInput->t_FIPOA.pf_GetObjWidthforCorridor : (Pointer to ) Get object width for corridor calculations [0.f  10.f]
  @glob_out        pt_LA_Output->f_LA_StateScaleBracket          : state of trace bracket adaption [LA_t_ScaleBracketState defined in la_ext.h]
  @glob_out        None 

  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Configuration switch, which adapts the trace brackets based on the ego position in lane as defined in sit_cfg.h
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Configuration switch, which adapts the trace brackets in case of no lane change as defined in sit_cfg.h
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch, which adapts the trace brackets in case of the blinker feature as defined in sit_cfg.h
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE :
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE :
  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION : 
  @c_switch_part   LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME : Configuration switch which enables the adaptation of Inlane Time Threshold using blocked path timer
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ : Configuration switch to enable Camera Trajectory Lane Association
  @c_switch_part   LA_CFG_TURN_INDICATOR_COUNTER  : Configuration Switch for Enabling Counter for Ego lane change indicator
  @c_switch_part   LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER : Configuration Switch to enable timer for ego lane change restriction
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.10.2016
  @changed         24.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_InitPersistentData(void)
{
  ObjNumber_t nr;

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  /* Initialize inputs to LA module */
  pt_LAInput->pt_FIPCC                              = NULL;
#endif
  /* Initialize inputs to LA module */
  pt_LAInput->t_RTE.pf_ObjLatDisp                   = NULL;
  pt_LAInput->t_RTE.pf_ObjLongDisp                  = NULL;
  pt_LAInput->t_RTE.pf_ObjLatDisp                   = NULL;
  pt_LAInput->t_RTE.pf_ObjVrelX                     = NULL;
  pt_LAInput->t_RTE.pf_ObjVrelY                     = NULL;
  pt_LAInput->t_RTE.pf_ObjArelX                     = NULL;
  pt_LAInput->t_RTE.pf_ObjOrientation               = NULL;
  pt_LAInput->t_RTE.pf_ObjOrientationStd            = NULL;
  pt_LAInput->t_RTE.pf_EgoVelObjSync                = NULL;
  pt_LAInput->t_RTE.pf_EgoAccObjSync                = NULL;
  pt_LAInput->t_RTE.pf_EgoCurve                     = NULL;
  pt_LAInput->t_RTE.pf_EgoCurveRaw                  = NULL;
  pt_LAInput->t_RTE.pt_ObjClassification            = NULL;
  pt_LAInput->t_RTE.pt_ObjDynamicProperty           = NULL;
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_LAInput->t_RTE.pt_CamLaneData                  = NULL;
#endif

#if ((SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) && (LA_CFG_EGO_TURNIND_BASED_PICKUP))
  pt_LAInput->t_RTE.pt_TurnIndicator               = NULL;
#endif /* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT && LA_CFG_EGO_TURNIND_BASED_PICKUP*/

#if (SLATE_CFG_USE_DRIVE_MODE)
  pt_LAInput->t_RTE.pt_edrivemode                   = NULL;
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  pt_LAInput->pt_FIPLaneMatrix                      = NULL;
#endif
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_LAInput->pt_FIPNaviData = NULL;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_LAInput->pt_FIPOA                              = NULL;
  pt_LAInput->pt_FIPRoadType                        = NULL;
  pt_LAInput->pt_FIPRoad                            = NULL;
  pt_LAInput->pt_FIPTO                              = NULL;
#endif
  /* Initialize input from SIT */
#if (FCT_CFG_ACC_SITUATION)
  pt_LAInput->t_SIT.pt_ObjBool = NULL;
   /* Blocked path selection Timer */
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
  pt_LAInput->t_SIT.pu_BlockedPathSelectionTimer = NULL;
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
#endif /* END IF FCT_CFG_ACC_SITUATION */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_LAInput->t_SIT.pt_SITLaneChangeCamPreMoveState = NULL;
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_LAInput->t_SIT.pf_CrossingDistTrace = NULL;
#endif
#if (SIT_CFG_OBJECT_SCORING)
  pt_LAInput->t_SIT.pt_ScoringAssocLane = NULL;
#endif /* END IF SIT_CFG_OBJECT_SCORING */
  pt_LAInput->t_CP.pt_TrajectoryData        = NULL;
  pt_LAInput->t_CP.pf_CourseCurve           = NULL;
  pt_LAInput->t_CP.pf_CourseCurveGradient   = NULL;
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_LAInput->t_CP.pt_TracePoly             = NULL;
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if ((FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE) || (FCT_CFG_USE_FCT_STATIC_TRACES) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES))
  pt_LAInput->pt_FIPMOT                                    = NULL;
#endif
  pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID          = NULL;
#endif
#endif
  /*Initialize outputs*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
   pt_LAOutput->f_LA_StateScaleBracket = SLATE_LANE_CHANGE_UNKNOWN;
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_LAInput->pt_FIPCamLane = NULL;
#endif
  /*Initialize the pick up range for moving objects depending on ego relative velocity */
  pt_LAOutput->f_LAMovingObjPickUpRange = 0.f;
  pt_LAOutput->f_LAMovingObjBasePickUpRange = 0.f;
  pt_LAOutput->f_LAMovingObjRangeLimitMin = 0.f;
  pt_LAOutput->f_LAMovingObjRangeLimitMax = 0.f;

#if (LA_CFG_TURN_INDICATOR_COUNTER)
  /*Initialize the timer based on Indicator*/
  pt_LAOutput->f_TurnIndLeftTime = 0.f;
  pt_LAOutput->f_TurnIndRightTime = 0.f;
#if (LA_CFG_USE_TURNIND_LASTSTATUS)
  pt_LAOutput->TurnIndLastState = eTurnIndicator_Off;
#endif /* LA_CFG_USE_TURNIND_LASTSTATUS */
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
  /* Intitialize the timer for ego lane change restriction */
  pt_LAOutput->f_EgoLCRestrictTimer = 0.f;
  /* Intitialize the last relevant object which is released during ego lane change */
  pt_LAOutput->iLastRelObjNr = OBJ_INDEX_NO_OBJECT;
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */
#endif /*(LA_CFG_TURN_INDICATOR_COUNTER)*/

  #if (FCT_CFG_ACC_OOI)
  pt_LAInput->t_OOI.pu_OOIListObjId = NULL;
  pt_LAInput->t_OOI.pt_OOIRelObj = NULL;
  #endif /* END IF FCT_CFG_ACC_OOI */
  /*! Range reduction factor @min:0 @max:1 */
  pt_LAOutput->fRangeFac = 0.f;

  /* Initialize ACC function pre-selection */
  LA_v_InitAccFunPreselection();

  LA_v_CorridorInit();

  /* initializes all Object to Trajectory related variables*/
  LA_v_Obj2TrajInit();

  for(nr = (ObjNumber_t)(EM_N_OBJECTS - 1); nr >= 0; nr--)
  {
    /*Check if all members of struct are deleted!!! */
    LA_v_DeleteObject(nr);
#if (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
    /* Initialize the Camera Trajectory based Lane Association */
    pt_LAOutput->t_LAObjOutputList[nr].t_ObjCamTrajLaneAssoc  = LA_OBJ_CAM_LANE_UNDEFINED;
    pt_LAOutput->t_LAObjOutputList[nr].f_ObjCamTrajLaneAssocProb = 0.F;
#endif /*(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */
  }

  LA_v_InitCustom();

}

/*************************************************************************************************************************
  Functionname:    LA_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output structures in LA module

  @description     Initialize input-output structures in LA module
                   @startuml
                   Partition LA_v_InitEveryCycle {
                   Start
                   - Initialize outputs from LA module
                   - Initialize the pick up range for moving objects depending on ego relative velocity
                   Partition #Lightblue **LA_v_InitCorridorScene** {                                                                    
                   - Initialize corridor scene relevant information
                   }
                   
                   Partition #Lightblue **LA_v_InitCustom** {                                                                    
                   - Initialize customer specific object data
                   }
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       -

  @glob_in         None 
  @glob_out        t_FIPLaneMatrix : Reference to LA input structure where FIPLaneMatrix data is received 
  @glob_out        t_FIPRoadType : Reference to LA input structure where FIPRoadType data is received 
  @glob_out        t_LAOutput : Reference to LA output structure
  @glob_out        pt_LAOutput : Pointer to LA output structure which is accessible from outside LA module

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.09.2016
  @changed         29.09.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_InitEveryCycle(void)
{
  ObjNumber_t t_ObjNr;
  uint8 i = 0u;

  /* Initialize outputs from LA module */
  pt_LAOutput->f_LA_SeekLaneWidth = 0.f;
  pt_LAOutput->f_LA_TrackLaneWidth = 0.f;

#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
   for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
   {
     pt_LAOutput->t_NearNeighboringObj[t_ObjNr] = OBJ_INDEX_NO_OBJECT;
   }
#endif /*(LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)*/

   /*Initialize the pick up range for moving objects depending on ego relative velocity */
   pt_LAOutput->f_LAMovingObjPickUpRange = 0.f;
   pt_LAOutput->f_LAMovingObjBasePickUpRange = 0.f;
   pt_LAOutput->f_LAMovingObjRangeLimitMin = 0.f;
   pt_LAOutput->f_LAMovingObjRangeLimitMax = 0.f;

   for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
   {
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].t_PredTimeThreshold = 0.0f;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].t_TotalTimeToInlap = LA_PRED_TIME_INIT_HIGH;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].t_TotalTimeToInlapDrop = LA_PRED_TIME_INIT_HIGH;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].f_DistanceToInlap = 0.0f;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].f_DistanceToInlapDrop = 0.0f;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].f_TotalDistanceToInlap = LA_PRED_DIST_INIT_HIGH;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].f_TotalDistanceToInlapDrop = LA_PRED_DIST_INIT_HIGH;
     pt_LAOutput->t_LAObjOutputList[t_ObjNr].fInLaneTimeThres = 0.f;
#if (LA_CFG_ENABLE_PARKED_DETECTION)
     pt_LAOutput->b_RoadSideParkedObj[t_ObjNr]      = FALSE;
#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */
#if (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
     pt_LAOutput->b_EgoObjTracCutOut[t_ObjNr]      = FALSE;
#endif  /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */
   }
    #if (LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE)
      #if ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS))
        pt_LAOutput->s_LaneWidthClass =  FIP_LANE_WIDTH_CLASS_UNKNOWN;
      #endif /* LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE */
    #endif /* END IF  ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS)) */
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)

  for(i=0u; i<(uint8)SIT_PATH_OCC_ENTRIES;i++)
  {
    pt_LAOutput->a_PathOccObj2Obstacle[i].LengthTrajEgoFrontToObj = 0.f;
    pt_LAOutput->a_PathOccObj2Obstacle[i].DistTrajToObjEdge = 0.f;
    pt_LAOutput->a_PathOccObj2Obstacle[i].ObjID = OBJ_INDEX_NO_OBJECT;
    pt_LAOutput->a_PathOccObj2Obstacle[i].prev = NULL;
    pt_LAOutput->a_PathOccObj2Obstacle[i].next = NULL;
  }
  /* set starting points */
  pt_LAOutput->a_PathOccObj2Obstacle[0u].next = &(pt_LAOutput->a_PathOccObj2Obstacle[2u]);
  pt_LAOutput->a_PathOccObj2Obstacle[1u].next = &(pt_LAOutput->a_PathOccObj2Obstacle[3u]);

  pt_LAOutput->a_PathOccObj2Obstacle[2u].prev = &(pt_LAOutput->a_PathOccObj2Obstacle[0u]);
  pt_LAOutput->a_PathOccObj2Obstacle[3u].prev = &(pt_LAOutput->a_PathOccObj2Obstacle[1u]);

  pt_LAOutput->a_PathOccObj2Obstacle[2u].LengthTrajEgoFrontToObj = LA_SCENE_DEFAULT_DISTTOOBJ;
  pt_LAOutput->a_PathOccObj2Obstacle[3u].LengthTrajEgoFrontToObj = LA_SCENE_DEFAULT_DISTTOOBJ;

#else
  _PARAM_UNUSED(i);
#endif /*END IF(LA_CFG_BLOCKED_OBSTACLE_EXTENSION)*/
/*! Initialize corridor scene relevant infos */
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  LA_v_InitCorridorScene();
#endif
  LA_v_InitCustom();
}

/*************************************************************************************************************************
  Functionname:    LA_v_SetInput                                                                                    */ /*!

  @brief           Set inputs to LA module

  @description     Fill out input structure in LA module using outputs from other provider modules
                   @startuml
                   Partition LA_v_SetInput {
                   Start
                   -Set Input of RTE Input Ports
                   -Set Input of FIP curvature change
                   -Set Input of FIP Lane Matrix
                   -Set Input from FIP Navi Data
                   -Set Input of FIP Object Attributes
                   -Set Input of FIP moving object traces component
                   -Set Input of SIT component
                   - Blocked path selection Timer
                   - Get lane change information
                   - Set Input of CP component
                   - Set Input of OOI component
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       -

  @glob_in         None
  @glob_out        t_FIPLaneMatrix : Reference to LA input structure where FIPLaneMatrix data is received 
  @glob_out        t_LAOutput : Reference to LA output structure
  @glob_out        pt_LA_Output : Pointer to LA output structure which is accessible from outside LA module
  @glob_out        t_FIPRoadType : Reference to LA input structure where FIPRoadType data is received 

  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE : usage of object turn indicator signal in SLATE
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE :
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE :
  @c_switch_part   SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES :
  @c_switch_part   FCT_CFG_USE_FCT_STATIC_TRACES :
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING :
  @c_switch_part   FCT_CFG_ACC_SITUATION :
  @c_switch_part   FCT_CFG_ACC_OOI :
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION :
  @c_switch_part   SIT_CFG_OBJECT_SCORING :
  @c_switch_part   LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME : Configuration switch which enables the adaptation of Inlane Time Threshold using blocked path timer
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.09.2016
  @changed         29.09.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_SetInput(void)
{

/*! Set inputs to LA module */
/*! Input of RTE Input Ports */
  pt_LAInput->t_RTE.pf_ObjLatDisp                     = &SLATE_pf_GetObjLatDisp;
  pt_LAInput->t_RTE.pf_ObjLongDisp                    = &SLATE_pf_GetObjLongDisp;
  pt_LAInput->t_RTE.pt_ObjDynamicProperty             = &SLATE_pt_GetObjDynProperty;
  pt_LAInput->t_RTE.pt_ObjClassification              = &SLATE_pt_GetObjClassification;
  pt_LAInput->t_RTE.pf_ObjVrelX                       = &SLATE_pf_GetObjVrelX;
  pt_LAInput->t_RTE.pf_ObjVrelY                       = &SLATE_pf_GetObjVrelY;
  pt_LAInput->t_RTE.pf_ObjArelX                       = &SLATE_pf_GetObjArelX;
  pt_LAInput->t_RTE.pf_ObjOrientation                 = &SLATE_f_GetObjOrientation;
  pt_LAInput->t_RTE.pf_ObjOrientationStd              = &SLATE_f_GetObjOrientationStd;
  pt_LAInput->t_RTE.pf_EgoVelObjSync                  = SLATE_pf_GetEgoLongVel();
  pt_LAInput->t_RTE.pf_EgoAccObjSync                  = SLATE_pf_GetEgoLongAccel();
  pt_LAInput->t_RTE.pf_EgoCurve                       = SLATE_pf_GetEgoCurve();
  pt_LAInput->t_RTE.pf_EgoCurveRaw                    = SLATE_pf_GetEgoCurveRaw();
  pt_LAInput->t_RTE.f_EgoYawRateQuality               = SLATE_f_GetEGORawYawRateQuality();
#if (SLATE_CFG_USE_DRIVE_MODE)
  pt_LAInput->t_RTE.pt_edrivemode                     = SLATE_pt_GetDrivemode();
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  pt_LAInput->t_RTE.pf_TunnelProbability              = (const float32 *) &(SLATE_p_GetPerfDegr()->fTunnelProbability);
#endif

#if (FCT_CFG_EMERGENCY_BRAKE_ASSIST)
  pt_LAInput->t_RTE.pt_EbaObjClass                    = &SLATE_pt_GetEbaObjClass;
#endif

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  pt_LAInput->t_RTE.p_ARSSensorSpecific               = &SLATE_p_GetEMARSObjSensorSpecific;
#endif
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  pt_LAInput->t_RTE.p_EMCustObj                       = &SLATE_p_GetEMCustObjData;
#endif

#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_LAInput->t_RTE.pt_CamLaneData                    = SLATE_pt_GetCamLaneData();
#endif

#if ((SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) && (LA_CFG_EGO_TURNIND_BASED_PICKUP))
  pt_LAInput->t_RTE.pt_TurnIndicator                 = SLATE_pt_GetTurnIndicator();
#endif /* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT && LA_CFG_EGO_TURNIND_BASED_PICKUP*/

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
/*! Input of FIP curvature change */
  pt_LAInput->pt_FIPCC                                = FIP_pf_CC_GetCCComputation();
  #endif

/*! Input of FIP Lane Matrix */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  pt_LAInput->pt_FIPLaneMatrix = FIP_pt_LM_GetLaneMatrixData();
#endif
/*! Input from FIP Navi Data */
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_LAInput->pt_FIPNaviData = FIP_pt_ND_GetNaviData();
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
/*! Input of FIP Object Attributes */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_LAInput->pt_FIPOA                    = FIP_pt_GetObjAttributes();
  pt_LAInput->pt_FIPRoadType              = FIP_pt_RT_GetRoadType();
  pt_LAInput->pt_FIPRoad                  = FIP_pt_RD_GetRoadData();
  pt_LAInput->pt_FIPTO                    = FIP_pt_TO_GetTrafficOrientation();
#endif
  pt_LAInput->t_RTE.pb_ObjIsShadow        = &SLATE_b_GetObjIsShadow;
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_LAInput->pt_FIPCamLane               = FIP_pt_CL_GetCamLaneData();
#endif

  /*! Input of FIP moving object traces component */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
  pt_LAInput->pt_FIPMOT                                    = FIP_pt_GetMOTData();
#endif /* #if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
  pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID          = &FIP_pu_GetStaticTraceID;
#elif (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
  pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID          = &SLATE_pu_GetEMARSObjTraceID;
#endif /* END IF (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

/*! Input of SIT component */
#if (FCT_CFG_ACC_SITUATION)
  pt_LAInput->t_SIT.pt_ObjBool = &SIT_pu_GetBool;
  /* Blocked path selection Timer */
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
  pt_LAInput->t_SIT.pu_BlockedPathSelectionTimer = &SIT_pu_BlockedPathSelectionTimer;
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
  /*get lane change information*/
  pt_LAInput->t_SIT.pt_GetLaneChangeInfo = SIT_pt_GetLaneChangePhase();
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_LAInput->t_SIT.pt_SITLaneChangeCamPreMoveState = SIT_pt_LaneChangeCamPreMoveState();
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_LAInput->t_SIT.pf_CrossingDistTrace = &SIT_pf_GetCrossingDistTrace;
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
#if (SIT_CFG_OBJECT_SCORING)
  pt_LAInput->t_SIT.pt_ScoringAssocLane = &SIT_pt_GetScoringAssocLane;
#endif /* END IF SIT_CFG_OBJECT_SCORING */
#endif /*END IF FCT_CFG_ACC_SITUATION */
/*! Input of CP component */
  pt_LAInput->t_CP.pt_TrajectoryData = CP_pt_GetTrajectoryData();
  pt_LAInput->t_CP.pf_CourseCurve = CP_f_GetCourseCurve();
  pt_LAInput->t_CP.pf_CourseCurveGradient = CP_f_GetCourseCurveGradient();
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_LAInput->t_CP.pt_TracePoly = &CP_pt_GetTracePoly;
#endif
#if (FCT_CFG_ACC_OOI)
  pt_LAInput->t_OOI.pt_OOIRelObj = OOI_pt_GetRelObj();
  pt_LAInput->t_OOI.pu_OOIListObjId = &OOI_pu_GetOOIListObjId;
#endif
}


/*************************************************************************************************************************
  Functionname:    LA_v_DeleteObject                                                                                */ /*!

  @brief           Delete objects marked for deletion

  @description     Delete objects marked for deletion
                   @startuml
                   Partition LA_v_DeleteObject {
                   
                   Start
                   Partition #Lightblue **LA_v_CorridorObjInit** {                                                                    
                   - Initialize the corridor object passed
                   }
                   - Initialize objects marked for deletion with default values
                   - Initialize object to object data with default values
                   End
                   }
                   @enduml

  @return          void

  @param[in]       ObjId : Object Number of Object marked for deletion        [0 ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput : LA Output Structure
  @glob_out        pt_LAOutput : LA Output Structure
                    t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantTime : Time for which object was relavnt     [fTime_t type as defined in Rte_type.h]
                    LABasePreselObjList[i] : Object preselection flag                                                   [TRUE....FALSE]
                    t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantDist : Distance covered by EGO while 
                                                                                      obeject was relavant              [fDistance_t as defined in Rte_Type.h]
                    t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState :  Object Lane Association State 
                                                                                      without quality consideration     [LA_t_LaneState type enum as defined in fct_sen_feedback.h]
                    t_LAObjOutputList[i].ObjLaneAccStatus.LAActLaneState : Object Lane Association State 
                                                                                     with quality consideration         [LA_t_LaneState type enum as defined in fct_sen_feedback.h]
                    LAObjOutputList[i].ObjLaneAccStatus.In2OutlaneTransition : Inlane to outlane transition counter 
                                                                                       for outlane decision of objects  [full range of uint8]
                    t_LAObjOutputList[i].t_Bool.FctPreselTG : Object is within preselection timegap distance            [0...1]
                    t_LAObjOutputList[i].t_Bool.InLInlapValue : Inlane inlap flag                                       [0...1]
                    t_LAObjOutputList[i].t_Bool.InLCustomValue : Inlane custom flag (predicted inlane)                  [0...1]
                    t_LAObjOutputList[i].t_Bool.InLQualityValue : Inlane quality value                                  [0...1]
                    t_LAObjOutputList[i].t_Bool.InLTimeValue : Inlane timer satisfied                                   [0...1]
                    t_LAObjOutputList[i].t_Bool.OutLInlapValue : Outlane inlap flag                                     [0...1]
                    t_LAObjOutputList[i].t_Bool.OutLCustomValue : Outlane custom flag                                   [0...1]
                    t_LAObjOutputList[i].ObjTrajRefPoint.fX : Object's trajectory reference point X coordinate          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajRefPoint.fY : Object's trajectory reference point Y coordinate          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajRefPoint.fDistToTraj : Distance to trajectory                           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajRefPoint.fDistOnTraj : Distance from vehicle center of 
                                                                       gravity to object on trajectory                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajDistWidth.fDistance : Distance between center of the corridor and the 
                                                                                                 center of the object   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajDistWidth.fDistanceVar : Variance of Distance between center of the 
                                                                         corridor and the center of the object          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajDistWidth.fObjectWidth : object width based on classification           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajDistWidth.fObjectWidthVar : object width variance                       [0 ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajDistWidth.fTrajectoryWidth : width of the object's Corridor             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajDistWidth.fTrajectoryWidthVar : objectcorridor width varaince           [0.0f... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajRelation.fInlap : Inlap value of the object.                         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjTrajRelation.fInlapVar : Varaition of object inlap value                 [0.0f ... PI/2*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjDependantMaxRange : object depedent maximum range of object i for 
                                                                                        display in simulation        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_LAObjOutputList[i].ObjAssociatedLane : associated lane information of an object i              [0u ... 5u]
                    t_LAObjOutputList[i].ObjFuncLane : functional lane association of an object i                    [eAssociatedLane_t as in Rte_Type.h]
                    t_NearNeighboringObj[ObjId] : Object on neighboring lane close to Ego                            [-1 ... EM_N_OBJECTS-1]
                   t_LA_InternalObjectData[i] : LA Private Object Data
                     t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj :                         [TRUE....FALSE]
                     t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj :                           [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintRelObjDistToTraj :                              [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintRelObjTrace :                                   [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintRelObjBorderDist :                              [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintRelObjCutOut :                                  [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintO2ODoubleObject :                               [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintO2OMirror :                                     [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintO2OLaneMatrix :                                 [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintO2OVrel :                                       [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintO2OTraceDistances :                             [TRUE....FALSE]
                     t_O2ODebugInfo.b_hintO2OPosition :                                   [TRUE....FALSE]
                     t_O2ODebugInfo.t_ObjNrEgoLaneByO2O : Object Id of object near Ego    [-1 ... EM_N_OBJECTS-1]
                     ui_ClusterVarianceLevel : Difficulty level of object i with high 
                                                                cluster variance          [LA_CLUST_VAR_LEVEL_LOW ... LA_CLUST_VAR_LEVEL_DIFFICULT]
                     For all above i is in the range of                                   [0 ... EM_N_OBJECTS-1]


  @c_switch_part   LA_CFG_O2O_EGO_LANE_ASSOC : Configuration switch to enable O2O based lane association
                   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE : Configuration switch to enable multi object analyse as one input for the cutin potential 
                   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Configuration switch to enable cluster variance usage for in-lane decision
                   LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : Configuration switch to enbale bracket extension for relvant object
                   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : Configuration switch to enable restriction based on relevant object trace
                   FCT_SIMU : Compiler switch used for simulation purpose
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         5/14/2017

  @todo            -

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void LA_v_DeleteObject(ObjNumber_t ObjId)
{
  LA_v_CorridorObjInit(&(pt_LAOutput->t_LAObjOutputList[ObjId].ObjCor));

  pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.fCorridorRelevantTime = 0.0f;

  pt_LAOutput->t_LAObjOutputList[ObjId].t_PredTimeThreshold = 0.0f;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_TotalTimeToInlap = LA_PRED_TIME_INIT_HIGH;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_TotalTimeToInlapDrop = LA_PRED_TIME_INIT_HIGH;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_PredInlaneTimer = 0.0f;
  pt_LAOutput->t_LAObjOutputList[ObjId].u_PredOutlaneCounter = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap = 0.0f;
  pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop = 0.0f;
  pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlap = LA_PRED_DIST_INIT_HIGH;
  pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlapDrop = LA_PRED_DIST_INIT_HIGH;
  pt_LAOutput->LABasePreselObjList[ObjId] = FALSE;
  pt_LAOutput->t_LAObjOutputList[ObjId].fInLaneTimeThres = 0.f;
#if (LA_CFG_CAM_INLANE_STABLE_SELECTION)
  pt_LAOutput->t_LAObjOutputList[ObjId].u_CamInlaneCounter = 0u;
#endif /* END IF LA_CFG_CAM_INLANE_STABLE_SELECTION */
  pt_LAOutput->t_LAObjOutputList[ObjId].b_SetEgoLaneValidity = TRUE;
#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)  
  pt_LAOutput->t_LAObjOutputList[ObjId].b_SetInLaneTimeCurve = FALSE;
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */ 

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
  t_LA_InternalObjectData[ObjId].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj = FALSE;
#ifdef FCT_SIMU
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintRelObjDistToTraj  = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintRelObjOccluded    = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintRelObjTrace       = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintRelObjBorderDist  = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintRelObjCutOut      = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintO2ODoubleObject   = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintO2OMirror         = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintO2OLaneMatrix     = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintO2OVrel           = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintO2OTraceDistances = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.b_hintO2OPosition       = FALSE;
  t_LA_InternalObjectData[ObjId].t_O2ODebugInfo.t_ObjNrEgoLaneByO2O     = OBJ_INDEX_NO_OBJECT;
#endif /* END IF FCT_SIMU */
#endif /* END IF (LA_CFG_O2O_EGO_LANE_ASSOC) */
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.fCorridorRelevantDist = 0.0f;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.LAInlaneState    = OBJ_STATE_OUTLANE;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.LAActLaneState   = OBJ_STATE_OUTLANE;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.In2OutlaneTransition  = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.FctPreselTG                  = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.InLInlapValue                = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.InLCustomValue               = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.InLQualityValue              = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.InLTimeValue                 = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.OutLInlapValue               = 0u;
  pt_LAOutput->t_LAObjOutputList[ObjId].t_Bool.OutLCustomValue              = 0u;
#if (LA_CFG_DTR_OBJ_SELECTION)
  t_LA_InternalObjectData[ObjId].uiPedestrianHighCounter                = 0u;  
#endif /* END IF (LA_CFG_DTR_OBJ_SELECTION)*/

#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRefPoint.fX           = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRefPoint.fY           = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRefPoint.fDistToTraj  = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRefPoint.fDistOnTraj  = 0.0F;

  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth.fDistance           = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth.fDistanceVar        = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth.fObjectWidth        = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth.fObjectWidthVar     = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth.fTrajectoryWidth    = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth.fTrajectoryWidthVar = 0.0F;

  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRelation.fInlap        = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRelation.fInlapVar     = 0.0F;

  pt_LAOutput->t_LAObjOutputList[ObjId].ObjDependantMaxRange                = 0.0F;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjAssociatedLane                   = ASSOC_LANE_UNKNOWN;
  pt_LAOutput->t_LAObjOutputList[ObjId].ObjFuncLane                         = ASSOC_LANE_UNKNOWN;
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  pt_LAOutput->t_LAObjOutputList[ObjId].u_CameraCutInPotential = 0U;  
  pt_LAOutput->t_LAObjOutputList[ObjId].u_CameraCutOutPotential = 0U; 
  pt_LAOutput->t_LAObjOutputList[ObjId].t_CutInCutOutstate = LA_POTENTIAL_INIT;                
  pt_LAOutput->t_LAObjOutputList[ObjId].f_CAM_Overlap_prev_cycle = 0.f;           
  pt_LAOutput->t_LAObjOutputList[ObjId].f_CAM_Overlap_delta = 0.f;                     
#endif
#endif /* END IF (FCT_SIMU) */
#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
    t_LA_InternalObjectData[ObjId].ui_ClusterVarianceLevel     = 0u;
#ifdef FCT_SIMU
    t_LA_InternalObjectData[ObjId].f_ObjDistToRoadborder       = 0u;
#endif /* END IF (FCT_SIMU) */
#endif /* END IF (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) */

#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
 t_LA_InternalObjectData[ObjId].ui_ClusterVarianceLevelforobstacles =0u;
#endif /* LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES */

#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  pt_LAOutput->t_NearNeighboringObj[ObjId] = OBJ_INDEX_NO_OBJECT;
#endif
#if (LA_CFG_ENABLE_PARKED_DETECTION)
  pt_LAOutput->b_RoadSideParkedObj[ObjId]      = FALSE;
#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */
}

/*************************************************************************************************************************
  Functionname:    LA_v_Obj2TrajInit                                                                                   */ /*!

  @brief           Initializing the modules to be used in the lane association.

  @description     Initializing the modules to be used in the lane association and CP Trajectory
                   @startuml
                   Partition LA_v_Obj2TrajInit {
                   Start
                   Repeat
                   Partition #Lightblue **LA_v_InitObjDist2Traj** {                                                                    
                   -Initializes the kalman Matrices and distance to the trajectory parameters 
                   }
                    
                   Repeat while(For all EM object list)
                   End
                   }
                   @enduml
  @return          static void

  @param[in]       - 

  @glob_in         CP_t_TrajectoryData : structure of type CP_t_TrajectoryData, describes the Trajectory. Defined in si_main.c.
  @glob_in         OBJ_GET_CP : Predicted course information per object of type FCTCoursePred_t. Defined in cp_ext.h
                        OBJ_GET_CP(iObj) : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_out        -

  @c_switch_part   CP_SW_VERSION_NUMBER : Version number of CP software version.
  @c_switch_part   FCT_SIMU             : Compiler switch used for simulation purpose.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         5/08/2008
  @changed         3/23/2016

  @todo            Replace OBJ_GET_CP macro

  @author          Norman Apel | norman.apel@contiautomotive.com | +49 (8382) 9699-365
*************************************************************************************************************************/
static void LA_v_Obj2TrajInit (void)
{
  ObjNumber_t           iObj;
  CPObjDist2Traj_tMeas  ObjDistMeas;

  ObjDistMeas.Y.f0  = 0.0f;
#ifdef FCT_SIMU
  ObjDistMeas.Y.f1  = 0.0f;
#endif
  ObjDistMeas.R.f00 = 0.0f;
  for (iObj = (ObjNumber_t)(EM_N_OBJECTS      - 1); iObj >= 0; iObj--)
  {
    LA_v_InitObjDist2Traj(&ObjDistMeas , &(OBJ_GET_CP(iObj)));
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_MergeDeleteObjects                                                                          */ /*!

  @brief           Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

  @description     Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame
                   @startuml
                   Partition LA_v_MergeDeleteObjects {
                   Start
                   Repeat 
                   If(objects were set to be deleted by Frame)then (Yes)
                     Partition #Lightblue  **LA_v_DeleteObject** {                                                                    
                     -Delete objects which were set to be deleted by Frame
                     }
                   Endif
                   
                   If(objects are marked for merging) then(Yes)
                   
                     Partition #Lightblue  **LA_v_MergeObjects** {                                                                    
                     - Merge Objects that are marked for merging
                     }
                   
                     If(Object is deleted OR Object is new)then(yes)
                     Partition #Lightblue  **LA_v_DeleteObject** {                                                                    
                     - Delete Objects that are marked for deleting
                     }
                     Endif
                   Elseif(Object is to keep)then(yes)
                     Partition #Lightblue  **LA_v_MergeDeleteObjectSameFCTID** {                                                                    
                     - Merge and delete the object having same FCT ID
                     }
                   endif
				   Repeat while(For all EM objects)
                   End
                   }
                   @enduml


  @return          static void

  @param[in,out]   pt_MergeDeleteObjList : Reference to merge-delete decision list from Frame

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         14.11.2016
  @changed         14.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  ObjNumber_t t_Obj, t_ObjToKeep;
  boolean b_DeleteObject, b_ObjIsDeleted, b_ObjIsNew;
  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    /* Make a local copy of the object ID present in merge release list */
    t_ObjToKeep = t_MergeDeleteObjList[t_Obj].t_ObjectToKeep;
    b_DeleteObject = t_MergeDeleteObjList[t_Obj].b_ObjectToDelete;

    /* 1. Delete objects which were set to be deleted by Frame */
    if (b_DeleteObject == TRUE)
    {
      LA_v_DeleteObject(t_Obj);
    }
    /* 2. Merge Objects */
    if ((t_ObjToKeep > OBJ_INDEX_NO_OBJECT) && (t_ObjToKeep != t_Obj))
    {
      /* 2.1 Merge Objects that are marked for merging */
      LA_v_MergeObjects(t_ObjToKeep, t_Obj);

      b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(t_Obj);
      b_ObjIsNew = SLATE_b_GetObjIsNew(t_Obj);
      /* 2.2 Delete Objects that are marked for deleting */      
      if(b_ObjIsDeleted || b_ObjIsNew)
      {
        LA_v_DeleteObject(t_Obj);
      }
    } else if (t_ObjToKeep == t_Obj) {
      /* 3. Old object is merged to new object at the same position in FCT List. 
      First, the information which is copied during the merge, has to be stored locally. 
      Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
      LA_v_MergeDeleteObjectSameFCTID(t_Obj);
    }
    else 
    {
      /* Dummy else to keep QAC happy */
    }

  } /* END Loop over EM_N_Objects*/
}
/*************************************************************************************************************************
  Functionname:    LA_v_MergeObjects                                                                                */ /*!

  @brief           Merge Objects marked for merging

  @description     Merge Objects marked for merging
                   @startuml
                   Partition LA_v_MergeObjects{
                   Start
                   If (Object considerd for deletion is relevant)then (Yes)
                   -Take over the duration of relevance
                   Endif
                   
                   -Merge object corridor data pulling merged object toward ego lane
                   -Keep higher of two inlane to outlane transition counters
                   -Keep higher of two corridor relevant timers
                   -Keep higher of two corridor relevant distances
                   
                     Partition #Lightblue  **LA_v_MergeCustomObjects** {                                                                    
                     - merge customer specific data
                     }
                   
                   End
                   }
                   @enduml

  @return          void

  @param[in]       iObjectToKeep : Object ID of object to keep                        [0 ... EM_N_OBJECTS-1]
  @param[in]       iObjectToDelete : Object ID of object mark for deletion            [0 ... EM_N_OBJECTS-1]

  @glob [in,out]   pt_LAOutput->t_LAObjOutputList[i].ObjCor.TrckFahr.dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track lane width
                                                                                                  depending on time and distance   [0...1]
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState :             Lane Association State .         [LA_t_LaneState type enum as defined in fct_sen_feedback.h]
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.In2OutlaneTransition :      Inlane to outlane transition counter for outlane decision of objects
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantTime :     Corridor relvant time            [fTime_t type as defined in Rte_type.h]
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantDist :     Corridor relvant distance        [fDistance_t as defined in Rte_Type.h]
                                                                                                  For all above i in the range of  [0 ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         5/14/2017

  @todo            -

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void LA_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete)
{
  /*! Take care: If new information considered here, check if the same information should be considered in SIMergeDeleteObjectSameFCTID(...) !!! */

  boolean b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(iObjectToDelete);
  if (b_ObjIsRelevant) // is this condition necessary???
  {
    /* The duration of relevance must be taken over.  */
    pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjCor.TrckFahr.dRelSpurErweiterungsFaktor = pt_LAOutput->t_LAObjOutputList[iObjectToDelete].ObjCor.TrckFahr.dRelSpurErweiterungsFaktor;
  }

  /* Merge object corridor data pulling merged object toward ego lane (i.e.: prioritizing inlane) */
  pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.LAInlaneState          = MIN(pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.LAInlaneState, pt_LAOutput->t_LAObjOutputList[iObjectToDelete].ObjLaneAccStatus.LAInlaneState);
  /* Keep higher of two inlane to outlane transition counters */
  pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.In2OutlaneTransition   = MAX(pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.In2OutlaneTransition, pt_LAOutput->t_LAObjOutputList[iObjectToDelete].ObjLaneAccStatus.In2OutlaneTransition);
  /* Keep higher of two corridor relevant timers */
  pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.fCorridorRelevantTime  = MAX_FLOAT(pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.fCorridorRelevantTime, pt_LAOutput->t_LAObjOutputList[iObjectToDelete].ObjLaneAccStatus.fCorridorRelevantTime);
  /* Keep higher of two corridor relevant distances */
  pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.fCorridorRelevantDist  = MAX_FLOAT(pt_LAOutput->t_LAObjOutputList[iObjectToKeep].ObjLaneAccStatus.fCorridorRelevantDist, pt_LAOutput->t_LAObjOutputList[iObjectToDelete].ObjLaneAccStatus.fCorridorRelevantDist);


  /* merge customer specific data */
  LA_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete );
}

/*************************************************************************************************************************
  Functionname:    LA_v_MergeDeleteObjectSameFCTID                                                                  */ /*!

  @brief           Merge and delete the object having same FCT ID

  @description     Old object is merged to new object at the same position in FCT List. 
                   First, the information which is copied during the merge, has to be stored locally. 
                   Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered
                   @startuml
                   Partition LA_v_MergeDeleteObjectSameFCTID {
                   Start
                   - Store the information locally which is considered for merging
                   
                     Partition #Lightblue  **LA_v_DeleteObject** {                                                                    
                     - Delete the FCT-object
                     }
                   
                   If (Object is relavent) then(yes)
                   - Retain Duration of relevance
                   Endif
                   
                   - Merge object corridor data pulling merged object toward ego lane
                   - Keep higher of two inlane to outlane transition counters
                   - Keep higher of two corridor relevant timers
                   - Keep higher of two corridor relevant distances
                   End
                   }
                   @enduml

  @return          void

  @param[in]       ObjNr : Object ID of object to merge/delete                 [0 ... EM_N_OBJECTS-1]

  @glob_in         OBJ_GET_RELEVANT(ObjNr) : Macro to check whether object is relvant object or not      [TRUE...FALSE]
  @glob [in,out]   pt_LAOutput->t_LAObjOutputList[i].ObjCor.TrckFahr.dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track lane width
                                                                                                  depending on time and distance   [0...1]
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState :             Lane Association State .         [LA_t_LaneState type enum as defined in fct_sen_feedback.h]
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.In2OutlaneTransition :      Inlane to outlane transition counter for outlane decision of objects
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantTime :     Corridor relvant time            [fTime_t type as defined in Rte_type.h]
                   pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantDist :     Corridor relvant distance        [fDistance_t as defined in Rte_Type.h]
                                                                                                  For all above i in the range of  [0 ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         5/14/2017

  @todo            -

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void LA_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr)
{
   /*! Take care: If new information considered here, check if the same information should be considered in SIMergeObjects(...) !!! */

  /*! First: Store the information locally which is considered for merging */
  boolean b_ObjIsRelevant = (boolean)SLATE_b_GetObjIsRelevant(ObjNr);
  float32 f_RelSpurErweiterungsFaktor = pt_LAOutput->t_LAObjOutputList[ObjNr].ObjCor.TrckFahr.dRelSpurErweiterungsFaktor;
  LA_t_LaneState SILateState = pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.LAInlaneState;
  uint8 ui_In2OutlaneTransition = pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.In2OutlaneTransition;
  float32 f_CorridorRelevantTime = pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.fCorridorRelevantTime;
  float32 f_CorridorRelevantDist = pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.fCorridorRelevantDist;

  /*! Store customer specific data locally (compare to OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) ) */

  /*! Second: Delete the FCT-object */
  LA_v_DeleteObject(ObjNr);

  /*! Third: Decide which merge-information should be copied */

  /*! Keep object relevance */
  if (b_ObjIsRelevant == TRUE)
  {
    /*! Duration of relevance must be retained */    
    pt_LAOutput->t_LAObjOutputList[ObjNr].ObjCor.TrckFahr.dRelSpurErweiterungsFaktor = f_RelSpurErweiterungsFaktor;
  }

  /*! Merge object corridor data pulling merged object toward ego lane (i.e.: prioritizing inlane) */
  pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.LAInlaneState          = MIN(pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.LAInlaneState, SILateState);
  /*! Keep higher of two inlane to outlane transition counters */
  pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.In2OutlaneTransition   = MAX(pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.In2OutlaneTransition, ui_In2OutlaneTransition);
  /*! Keep higher of two corridor relevant timers */
  pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.fCorridorRelevantTime  = MAX_FLOAT(pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.fCorridorRelevantTime, f_CorridorRelevantTime);
  /*! Keep higher of two corridor relevant distances */
  pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.fCorridorRelevantDist  = MAX_FLOAT(pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.fCorridorRelevantDist, f_CorridorRelevantDist);

  /*! Merge customer specific data: It might be necessary based on the implementation of OUT_v_MergeCustomObjects to merge the custom specific data.
    The function OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) must be adapted for the case that iObjectToKeep = iObjectToDelete */
}


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LA_v_MeasCallback                                                                                   */ /*!

  @brief           Central SI MEASFreezeDataMTS callback function

  @description     Central SI MEASFreezeDataMTS callback function. Since callback information is not used in SI, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.
                   @startuml
                   Partition LA_v_MeasCallback {
                   Start
                   End
                   }
                   @enduml
  @return          void

  @param[in]       -

  @glob_in         ptLAOutput->f_LA_SeekLaneWidth : global seek lane width variable        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code

  @pre             LA_v_CalculateBaseLaneWidths has to be calculated for pt_LAOutput->f_LA_SeekLaneWidth
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         07.03.2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
void LA_v_MeasCallback(void)
{
  return;
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_MeasFreeze                                                                                  */ /*!

  @brief           Freeze LA Object data for simulation and device

  @description     Freeze LA Object data for simulation and device
                   @startuml
                   Partition LA_v_MeasFreeze {
                   Start
                   - Store range factor data into LA device freeze structure
                   - Get LA specific navigation information
                   - Freeze device data 
                   - Get data for measurement freeze in simulation
                   - Freeze simulation data
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       -

  @glob_in         pt_LAInput : LA Input Structure
                    t_FrameFreeze.pt_LA_DeviceInfo->t_NaviMeasInfo : Navi measurement data
                    t_FrameFreeze.pt_LA_DeviceInfoFreeze : LA measurement device data to be freeze
                    t_FrameFreeze.pt_LA_DeviceInfo : LA measurement device data
                    t_FrameFreeze.pt_LA_SimMeasInfoFreeze : LA measurement data for simulation
                    t_FrameFreeze.pt_LA_SimMeasInfo : LA measurement data
                   pt_LAOutput : LA Output Structure
                    fRangeFac : factor used for curvature depedant range reduction    [0.0f ... 1.0f]
                    f_LA_SeekLaneWidth : global seek lane width variable              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        pt_LAInput : LA Input Structure
                     t_FrameFreeze.pt_LA_DeviceInfo->t_LA_CurveObs.RangeFactor : factor used for curvature depedant range reduction  [0.0f ... 1.0f]
                     t_FrameFreeze.pt_LA_DeviceInfo->f_LaneWidth : global seek lane width variable                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     t_FrameFreeze.pt_LA_SimMeasInfo->t_LA_FreezeOutput : LA measurement output

  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
                   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
                   FCT_SIMU : Compiler switch used for simulation purpose.

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         5/14/2017

  @todo            -

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_MeasFreeze(void)
{
  ObjNumber_t ObjID;
  /*! Get data for measurement freeze in device */
  /* Storing range factor data into LA device freeze structure */
  pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->t_LA_CurveObs.RangeFactor = pt_LAOutput->fRangeFac;

  /*! Get LA specific navi information */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  LA_v_NaviSetMeasData(&(pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->t_NaviMeasInfo));
#endif
  pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->f_LaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;

  for(ObjID = 0; ObjID < EM_N_OBJECTS; ObjID++)
  {
	 pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->t_LA_PubObj[ObjID].t_LA_laneAssocInfo.eObjAssocLane =  pt_LAOutput->t_LAObjOutputList[ObjID].ObjAssociatedLane;
	 pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->t_LA_PubObj[ObjID].t_LA_laneAssocInfo.e_ObjFuncLane =  pt_LAOutput->t_LAObjOutputList[ObjID].ObjFuncLane;
	 pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->t_LA_PubObj[ObjID].ObjToRefDist = pt_LAOutput->t_LAObjOutputList[ObjID].TrajDist.TrajDistMeas.Y.f0;
  }

  /*! Freeze device data */
  FCT_FREEZE_DATA(pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfoFreeze, pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo, NULL); //PRQA S 3200
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Currently MEASFreezeDataMTS return value is not used */

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
 
  pt_LAInput->t_FrameFreeze.pt_LA_SimMeasInfo->t_LA_FreezeOutput = *(pt_LAOutput);
  /*! Freeze simulation data */
  FCT_FREEZE_DATA(pt_LAInput->t_FrameFreeze.pt_LA_SimMeasInfoFreeze, pt_LAInput->t_FrameFreeze.pt_LA_SimMeasInfo, NULL);
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of LA sub-component

  @description     Set operation mode of LA sub-component based on given value
                   @startuml
                   Partition LA_v_SetOperationMode {
                   Start
                   - Set operation mode of LA sub-component
                   End
                   }
                   @enduml

  @return          -

  @param[in]       t_LAOpModeValue : LA operation mode value [full range of datatype SLATECompState_t as in slate_types.h]

  @glob_in         -
  @glob_out        @ref LA_t_State

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         20.02.2017
  @changed         20.02.2017
  @author          Gobichettipalayam Sankar, Bharadwaj (uidk9952)
*************************************************************************************************************************/
void LA_v_SetOperationMode(SLATECompState_t const t_LAOpModeValue)
{
  LA_t_State = t_LAOpModeValue;
}
/** @} end defgroup */
#endif /*!< FCT_CFG_ACC_LANE_ASSOCIATION */
