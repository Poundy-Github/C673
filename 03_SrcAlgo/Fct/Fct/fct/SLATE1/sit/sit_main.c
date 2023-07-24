/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)
  
CPU:                       CPU-Independent
  
COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_main.c

DESCRIPTION:               Main functions for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             16.06.2016

VERSION:                   $Revision: 1.41 $

LEGACY VERSION:            Revision: 2.3.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_custom.h"



#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_main Main
@ingroup sit
@brief          This module provides amongst others the main function of the SLATE Component. \n\n
@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

SET_MEMSEC_VAR(SIT_t_State)
SLATECompState_t SIT_t_State;       /*!< Operating modes of SIT sub-component */

/*! Definition of component global pointer to output structure for global access within component*/
SET_MEMSEC_VAR(pt_SITOutput)
SITOutput_t * pt_SITOutput;

/*! Definition of component internal pointer to SIT Input structure for global access within SIT */
SET_MEMSEC_VAR(pt_SITInput)
SITInputConst_t * pt_SITInput;

SET_MEMSEC_VAR(pt_SITInputModify)
SITInputModify_t * pt_SITInputModify;

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
static void SIT_v_InitPRE(void);
static void SIT_v_InitEveryCycle(void);
static void SIT_v_InitPersistentData(void);
//static void SIT_v_InitOutputPRE(void);
static void SIT_v_InitPOST(void);
static void SIT_v_SetInput(void);
static void SIT_v_MeasFreeze(void);
static void SIT_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);

/*************************************************************************************************************************
  Functionname:    SIT_v_ProcessPRE                                                                                 */ /*!

  @brief           Handles Operating modes of SIT
   
  @description     Handles Operating modes of SIT: if mode is in SIT_INIT state, it will do initialization and if mode is in SIT_OK it will do normal processing

		@startuml
		Start
		Partition SIT_v_ProcessPRE{
			: Assign local pointers for access within the component;
			: Set component global pointer to output structure for global access within the component;
			If (check if SIT State is Running) then (yes)
				: Initialize data for every cycle;
				: Ego lane change detection. Result can be used later on in entire code;
				: Select the corridor for Objects;
				: Analyze SIT O2O;
				: Preprocessing calculation of object features;
			Else (no)
				Note Right: SIT states(COMP_STATE_NOT_INITIALIZED, \n COMP_STATE_TEMPORARY_ERROR and \n COMP_STATE_PERMANENT_ERROR) \ncould be not initialized or error
				: Preinitialized data;
			Endif 
			: Reset SIT Inputs;
		}
		End
		@enduml

  @return          -

  @param[in]       pt_SIT_InputGlobal       : Reference to input structure of SIT component
  @param[in]       pt_SIT_InputModifyGlobal : Reference to input structure of SIT component
  @param[in]       pt_SIT_OutputGlobal      : Reference to output structure of SIT component
  @param[out]      -

  @glob_in         SIT_t_State       : Operating modes of sub-component ACC Situation (SIT) 
  @glob_out        pt_SITInput       : Reference to SIT input data structure
  @glob_out        pt_SITInputModify : Reference to SIT input data structure
  @glob_out        pt_SITOutput      : Reference to SIT output data structure
    
  @c_switch_part   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module 
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component

  @pre             SIT_v_PreProcess() should be called to initialize/set all the inputs
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
void SIT_v_ProcessPRE(SITInputConst_t * pt_SIT_InputGlobal, SITInputModify_t * pt_SIT_InputModifyGlobal, SITOutput_t * pt_SIT_OutputGlobal)
{
  /* Assign local pointers for access within the component */
  pt_SITInput = pt_SIT_InputGlobal;

  pt_SITInputModify = pt_SIT_InputModifyGlobal;

  /*! Set component global pointer to output structure for global access within the component */
  pt_SITOutput = pt_SIT_OutputGlobal;

  switch(SIT_t_State)
  {
  case COMP_STATE_RUNNING:
      /*! Functions calls for normal operation mode */

      /*! Initialize data for every cycle */
      SIT_v_InitEveryCycle();

      /* Ego lane change detection. Result can be used later on in entire code. */
      SIT_v_DetectLaneChange();

      SIT_v_SelectCorridorObjects();
	  
#if (SIT_O2O_ANALYSIS)
      SIT_v_O2OAnalysis();
#endif

      SIT_v_CalcObjectFeaturesPre();

      /* Set Lane change time gap */

    break;
  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR: /* this operation mode not yet set/used */
  case COMP_STATE_PERMANENT_ERROR: /* this operation mode not yet set/used */
  default:
    /*! Initialization */
    /*! Default */
    SIT_v_InitPRE();
    break;
  }
  /* Reset local pointers */
  pt_SITInput = NULL;
  pt_SITInputModify = NULL;
  /*! Init component global pointer to output structure since not used anymore */
  pt_SITOutput = NULL;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_ProcessPOST                                                                                */ /*!

  @brief           Handles post processing depending on Operating modes of SIT

  @description     Handles post processing depending on Operating modes of SIT

		@startuml
		Start
		Partition SIT_v_ProcessPOST {
		: Set component global pointer to input structure for global access within the component;
		: Set component global pointer to output structure for global access within the component;
		If (Check if SIT State is Running) then (yes)
			: Calculate cut-in, cut-out potential;
			partition #LightBlue "**~#if (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD)**" {
				: Fills the signal which says whether there is any obstacle in the front or not;
			}
			partition #LightBlue "**~#if SIT_CFG_TRAFFIC_DENSITY **" {
				: Calculate traffic density/traffic estimation (uses lane association of the objects);
			}
			partition #LightBlue "**~#if SIT_CFG_TRAFFIC_ESTIMATION **" {
				: Calculate traffic jam probability;
			}
		Else (no)
			Note Left: SIT states(COMP_STATE_NOT_INITIALIZED, \n COMP_STATE_TEMPORARY_ERROR and \n COMP_STATE_PERMANENT_ERROR) \ncould be not initialized or error
			: Post initialized data;
		Endif
		: SIT Measurement Freezed;
		: Initialize component global input pointer since not used anymore;
		}
		End
		@enduml

  @return          -

  @param[in]       pt_SIT_InputGlobal       : Reference to input structure of SIT component
  @param[in]       pt_SIT_InputModifyGlobal : Reference to input structure of SIT component
  @param[in]       pt_SIT_OutputGlobal      : Reference to output structure of SIT component
  @param[out]      -
   
  @glob_in         SIT_t_State       : Operating modes of sub-component ACC Situation (SIT) 
  @glob_out        pt_SITInput       : Reference to SIT input data structure
  @glob_out        pt_SITInputModify : Reference to SIT input data structure
  @glob_out        pt_SITOutput      : Reference to SIT output data structure

  @c_switch_part   SIT_CFG_TRAFFIC_DENSITY    : Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c)
  @c_switch_part   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION      :  FCT support for ACC SIT (situation) sub-component

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
void SIT_v_ProcessPOST(SITInputConst_t * pt_SIT_InputGlobal, SITInputModify_t * pt_SIT_InputModifyGlobal, SITOutput_t * pt_SIT_OutputGlobal)
{
  /*! Set component global pointer to input structure for global access within the component */
  pt_SITInput = pt_SIT_InputGlobal;

  pt_SITInputModify = pt_SIT_InputModifyGlobal;

  /*! Set component global pointer to output structure for global access within the component */
  pt_SITOutput = pt_SIT_OutputGlobal;

  switch(SIT_t_State)
  {
  case COMP_STATE_RUNNING:
    /*! Functions calls for normal operation mode */
    
    /* Calculate cut-in, cut-out potential */
    SIT_v_CalcBaseFeatures();

    /* Fills the signal which says whether there is any obstacle in the front or not */
#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))
    pt_SITOutput->t_SIT_FrontObstacleDetection.b_FrontObstDetcd = SIT_b_FrontObstacleFilling();
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */

    /* Calculate traffic density/traffic estimation (uses lane association of the objects) */
#if (SIT_CFG_TRAFFIC_DENSITY)
    SIT_v_TrafficProcess();
    SIT_v_TrafficEstiProcess();
    SIT_v_DrawTrafficDensity();
#endif

    /* Calculate traffic jam probability */
#if (SIT_CFG_TRAFFIC_ESTIMATION)
    SIT_v_TrafficJamEstimationMain();
#endif
    break;
  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /*! Initialization */
    /*! Default */
     SIT_v_InitPOST();
    break;
  }
  /* SIT Measurement Freeze */
  SIT_v_MeasFreeze();

  /*! Initialize component global input pointer since not used anymore */
  pt_SITInput = NULL;
  pt_SITInputModify = NULL;
  /*! Init component global pointer to output structure since not used anymore */
  pt_SITOutput = NULL;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_InitPRE                                                                                    */ /*!

  @brief           Pre Initialization Function

  @description     Pre Initialization Function

		@startuml
		Start
		Partition SIT_v_InitPRE {
			: Initialize data for every cycle;
			: Initialize persistent data of the component;
			: Initialize lane change detection module;
			Partition #LightBlue "**~#if SIT_CFG_OBJECT_SCORING **" {
				: Initialize object scores;
			}
		Repeat
			: Delete Object;
		Repeat While (For Entire Object list)
		}
		end
		@enduml

  @return          -

  @param[in]       - 
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   SIT_CFG_OBJECT_SCORING :  Configuration switch to enable new object scoring module
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component

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
static void SIT_v_InitPRE(void)
{
  ObjNumber_t nr;

  /*! Initialize data for every cycle */
  SIT_v_InitEveryCycle();

  /*! Initialize persistent data of the component */
  SIT_v_InitPersistentData();

  /* Initialize lane change detection module */
  SIT_v_InitLaneChange();

#if (SIT_CFG_OBJECT_SCORING)
  /* Initialize object scores */
  SIT_v_InitObjectScores();
#endif

  for(nr = (ObjNumber_t)(EM_N_OBJECTS - 1); nr >= 0; nr--)
  {
    SIT_v_DeleteObject(nr); // can be deleted, redundant to lines above
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_InitPOST                                                                                   */ /*!

  @brief           Post Initialization Function

  @description     Post Initialization Function

		@startuml
		Start
		Partition SIT_v_InitPOST{
		: Initialize blocked path relevant information;
		Partition #LightBlue "**~#if SIT_CFG_TRAFFIC_DENSITY **" {
			: Initialize traffic density/estimation relevant information;
		} 
		Partition #LightBlue "**~#if SIT_CFG_TRAFFIC_DENSITY **" {
			: Initialize traffic jam probability relevant information;
		}
		}
		End
		@enduml

  @return          -

  @param[in]       - 
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   SIT_CFG_TRAFFIC_DENSITY    : Configuration switch to enable/disable the calculation of the traffic density
  @c_switch_part   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability
  @c_switch_full   FCT_CFG_ACC_SITUATION      : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author 
*************************************************************************************************************************/
static void SIT_v_InitPOST(void)
{
  /*! Initialize blocked path relevant infos */
  SIT_v_InitBlockedPath();

  /*! Initialize traffic density/estimation relevant infos */
#if(SIT_CFG_TRAFFIC_DENSITY)
  SIT_v_TrafficInit();
  SIT_v_TrafficEstiInit();
#endif

  /*! Initialize traffic jam probability relevant infos */
#if(SIT_CFG_TRAFFIC_ESTIMATION)
  SIT_v_TrafficJamInit();
#endif
}

/*************************************************************************************************************************
  Functionname:    SIT_v_MergeDeleteObjects                                                                         */ /*!

  @brief           Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

  @description     Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

		@startuml
		Start
		Partition SIT_v_MergeDeleteObjects{
		Repeat
		: Make a local copy of the object ID present in merge release list;
		If (Object is deleted) then (yes)
			: Delete objects which were set to be deleted by Frame;
		Endif
		If (Objects are merged) then (yes)
			: Merge Objects that are marked for merging;
			: Delete Objects that are marked for deleting;
			If (New Object or Deleted Object) then (yes)
				: Delete the Object from Object List;
			Endif
		Else if (Object is not merged) then (yes)
			: Old object is merged to new object at the same position in FCT List. \nFirst, the information which is copied during the merge, has to be stored locally. \nThen, the old FCT-object can be deleted and afterwards the "merge"-information can be considered;
		Else (no)
			: Do Nothing;
		Endif
		Repeat While (For all EM Objects)
		}
		End
		@enduml

  @return          -

  @param[in]       t_MergeDeleteObjList : Reference to merge-delete decision list from Frame
                      t_ObjectToKeep    : Object ID to keep                                    [0u ... EM_N_OBJECTS-1]
                      b_ObjectToDelete  : Object ID to delete                                  [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            Macro OBJ_IS_NEW and SLATE_b_GetObjIsDeleted are replaced by outputs from FIP-OA. Since merge delete occurs 
                   before inputs to SIT are set, the access functions from FCTSen are used directly.

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).


  @created         11.11.2016
  @changed         11.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void SIT_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  ObjNumber_t t_Obj, t_ObjToKeep;
  boolean b_DeleteObject,b_ObjIsNew,b_ObjIsDeleted;

  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    /* Make a local copy of the object ID present in merge release list */
    t_ObjToKeep = t_MergeDeleteObjList[t_Obj].t_ObjectToKeep;
    b_DeleteObject = t_MergeDeleteObjList[t_Obj].b_ObjectToDelete;

    /* 1. Delete objects which were set to be deleted by Frame */
    if (b_DeleteObject == TRUE)
    {
      SIT_v_DeleteObject(t_Obj);
    }
    /* 2. Merge Objects */
    if ((t_ObjToKeep > OBJ_INDEX_NO_OBJECT) && (t_ObjToKeep != t_Obj))
    {
      /* 2.1 Merge Objects that are marked for merging */
      SIT_v_MergeObjects(t_ObjToKeep, t_Obj);
      
      b_ObjIsNew=SLATE_b_GetObjIsNew(t_Obj);
      b_ObjIsDeleted=SLATE_b_GetObjIsDeleted(t_Obj);
      /* 2.2 Delete Objects that are marked for deleting */      
      if((b_ObjIsNew)|| (b_ObjIsDeleted))
      {
        SIT_v_DeleteObject(t_Obj);
      }
    } else if (t_ObjToKeep == t_Obj) {
      /* 3. Old object is merged to new object at the same position in FCT List. 
      First, the information which is copied during the merge, has to be stored locally. 
      Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
      SIT_v_MergeDeleteObjectSameFCTID(t_Obj);
    }
    else
    {
      /*Dummy else to solve QAC error*/
    }
  } /* END Loop over EM_N_Objects*/
}

/*************************************************************************************************************************
  Functionname:    SIT_v_DeleteObject                                                                               */ /*!

  @brief           Handle Deleting of object from object lists 

  @description     Handle Deleting of object from object lists 
  
		@startuml
		Start
		Partition SIT_v_DeleteObject{
			: Handle Deleting of object from object lists;
		}
		End
		@enduml  

  @return          -

  @param[in]       ObjId : Object Number which is to be deleted                                            [0u ... EM_N_OBJECTS-1] 
  @param[out]      -

  @glob_in         -
  @glob_out        pt_SITOutput : Reference to SIT output data structure
                      t_Bool.SelectedByPathDecision : Object was selected by blocked path, Boolean         [Full range of SelectedByPathDecision as defined in sit_ext.h] [0u, 1u]
                      t_Bool.OccludedByTrace : Object is marked as occluded by trace analysis, Boolean     [Full range of OccludedByTrace as defined in sit_ext.h] [0u, 1u]
                      f_CrossingDistTrace :                                                                [Full range of f_CrossingDistTrace as defined in sit_ext.h]
					  u_BlockedPathSelectionTimer: Path SelectionTimer for Blocked path objects, uint8     [Full range of PathSelectionTimer as defined in sit_ext.h]
                     

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

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
void SIT_v_DeleteObject(ObjNumber_t ObjId)
{
  pt_SITOutput->t_ObjList[ObjId].t_Bool.SelectedByPathDecision = 0u;
  pt_SITOutput->t_ObjList[ObjId].t_Bool.OccludedByTrace = 0u;
  pt_SITOutput->t_ObjList[ObjId].f_CrossingDistTrace = 0.0f;
  pt_SITOutput->t_ObjList[ObjId].u_BlockedPathSelectionTimer = 0u;
  pt_SITOutput->t_ObjList[ObjId].u_ObjCutInPotential = 0u;
  pt_SITOutput->t_ObjList[ObjId].u_ObjCutOutPotential = 0u;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_MergeObjects                                                                               */ /*!

  @brief           Handle Merging of object from object lists 

  @description     Handle Merging of object from object lists 
  
		@startuml
		Start
		Partition SIT_v_MergeObjects{
		If (Blocked Path selection Timer of Object to keep is less than Blocked Path Selection Timer of Object to delete) then (yes)
			: value of path selection timer must be kept;
		Endif
		: merge customer specific data;
		}
		End
		@enduml  

  @return          -

  @param[in]       iObjectToKeep    : Object ID to keep                                                            [0u ... EM_N_OBJECTS-1]
  @parma[in]       iObjectToDelete  : Object ID to delete                                                          [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         pt_SITOutput->t_ObjList[iObjectToDelete].u_BlockedPathSelectionTimer: Path selection timer  [Full range of PathSelectionTimer as defined in sit_ext.h]
  @glob_out        pt_SITOutput->t_ObjList[iObjectToDelete].u_BlockedPathSelectionTimer: Path selection timer  [Full range of PathSelectionTimer as defined in sit_ext.h]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

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
void SIT_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete)
{
  /*! Take care: If new information considered here, check if the same information should be considered in SIMergeDeleteObjectSameFCTID(...) !!! */

  /* value of path selection timer must be kept */
  if(pt_SITOutput->t_ObjList[iObjectToKeep].u_BlockedPathSelectionTimer < pt_SITOutput->t_ObjList[iObjectToDelete].u_BlockedPathSelectionTimer)
  {
    pt_SITOutput->t_ObjList[iObjectToKeep].u_BlockedPathSelectionTimer = pt_SITOutput->t_ObjList[iObjectToDelete].u_BlockedPathSelectionTimer;
  }

  /* merge customer specific data */
  SIT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete );
}


/*************************************************************************************************************************
  Functionname:    SIT_v_MergeDeleteObjectSameFCTID                                                                 */ /*!

  @brief           Handle Merging of old object to new object at the same position in FCT List
  
  @description     Handle Merging of old object to new object at the same position in FCT List

		@startuml
		Start
		Partition SIT_v_MergeDeleteObjectSameFCTID{
		: Store the information locally which is considered for merging;
		: Delete the FCT-object;
		: Decide which merge-information should be copied;
		If (Blocked Path Selection Timer is less than Path selection Timer) then (yes)
			: Value of path selection timer must be kept;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       ObjNr : Object Number (Object ID)                                                      [0u ... EM_N_OBJECTS-1]              
  @parma[out]      -

  @glob_in         pt_SITOutput->t_ObjList[ObjNr].u_BlockedPathSelectionTimer: Path selection timer  [Full range of PathSelectionTimer as defined in sit_ext.h]
  @glob_out        pt_SITOutput->t_ObjList[ObjNr].u_BlockedPathSelectionTimer: Path selection timer  [Full range of PathSelectionTimer as defined in sit_ext.h]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

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
void SIT_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr)
{
    /*! Take care: If new information considered here, check if the same information should be considered in SIMergeObjects(...) !!! */

  /*! First: Store the information locally which is considered for merging */
  uint8 ui_PathSelectionTimer = pt_SITOutput->t_ObjList[ObjNr].u_BlockedPathSelectionTimer;

  /*! Store customer specific data locally (compare to OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) ) */

  /*! Second: Delete the FCT-object */
  SIT_v_DeleteObject(ObjNr);

  /*! Third: Decide which merge-information should be copied */

  /*! Value of path selection timer must be kept */
  if(pt_SITOutput->t_ObjList[ObjNr].u_BlockedPathSelectionTimer < ui_PathSelectionTimer)
  {
	  pt_SITOutput->t_ObjList[ObjNr].u_BlockedPathSelectionTimer = ui_PathSelectionTimer;
  }

  /*! Merge customer specific data: It might be necessary based on the implementation of OUT_v_MergeCustomObjects to merge the custom specific data.
    The function OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) must be adapted for the case that iObjectToKeep = iObjectToDelete */
}

/*************************************************************************************************************************
  Functionname:    SIT_v_PreProcessPRE                                                                              */ /*!

  @brief           Inputs are set/processed before the actual component process begins

  @description     Inputs are set/processed before the actual component process begins

		@startuml
		Start
		Partition SIT_v_PreProcessPRE{
		: Handle Merge Delete Object Lists;
		: Set/assign values to SIT input;
		}
		End
		@enduml

  @return          -

 
  @param[in]       pt_SIT_InputGlobal       : Reference to input structure of SIT component
  @param[in]       pt_SIT_InputModifyGlobal : Reference to input structure of SIT component
  @param[in]       pt_SIT_OutputGlobal      : Reference to output structure of SIT component
  @param[in]       t_MergeDeleteObjList     : Object list used for Merging and Deleting 
  @param[out]      -

  @glob_in         -
  @glob_out        pt_SITInput       : Reference to SIT input data structure
  @glob_out        pt_SITInputModify : Reference to SIT input data structure
  @glob_out        pt_SITOutput      : Reference to SIT output data structure

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         18.10.2016
  @changed         18.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void SIT_v_PreProcessPRE(SITInputConst_t * pt_SIT_InputGlobal, SITInputModify_t * pt_SIT_InputModifyGlobal, SITOutput_t * pt_SIT_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  pt_SITInput = pt_SIT_InputGlobal;
  pt_SITInputModify = pt_SIT_InputModifyGlobal;
  pt_SITOutput = pt_SIT_OutputGlobal;

  /* Handle Merge Delete Object Lists */
  SIT_v_MergeDeleteObjects(t_MergeDeleteObjList);
  
  /* Set input */
  SIT_v_SetInput();
  
  pt_SITInput = NULL;
  pt_SITOutput = NULL;
  pt_SITInputModify = NULL;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitEveryCycle                                                                            */ /*!

  @brief           Initialize static data of the component in each cycle

  @description     Initialize static data (inputs and outputs) of component each cycle; this is not to be called from SIT Post

		@startuml
		Start
		Partition SIT_v_InitEveryCycle{
			Partition #LightBlue "**~#if SIT_O2O_ANALYSIS **" {
				Repeat 
					: Update SIT O2O Analysis for Object List;
				Repeat While (For All Objects)
			}
		Repeat
			: Update SIT Path Occupation Array;
		Repeat While (For Entire Path Occupation Length Array)
		: Update SIT Path Occupation Output;
		: Closest and far objects ID are set to -1;
		: Set Probability of Multiple Objects in Left side and right side to 0;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @parma[out]      -

  @glob_in         -
  @glob_out        pt_SITOutput : Reference to SIT output data structure
                      t_CamLaneMarkerCrossed : Enum to describe the camera lane marker crossing state                                               [Full range of datatype SITLCStateCamLaneMarkerCrossed_t as defined in fct_sen_feedback.h ]
                      t_LaneChangeCamPreMoveState : Enum to describe if the ego vehicle moves to the new lane in the first stage of the lane change [LANE_CHANGE_CAM_PRE_MOVE_RIGHT ... LANE_CHANGE_CAM_PRE_MOVE_LEFT] 
                      t_LaneChangeTimeGap.f_LCPhaseProb : Lane change Phase probability                                                             [Full range of datatype f_LCPhaseProb (float32) as defined in sit_ext.h ]
                      t_LaneChangeTimeGap.t_LCPhaseState : Lane change state                                                                        [LC_RIGHT ... LC_LEFT]
                      t_LaneChangeTimeGap.t_LCTrafficOrientation : Traffic orientation                                                              [LC_TRAFFIC_ORIENT_UNKNOWN ... LC_TRAFFIC_ORIENT_LEFT] 
                      s_LCProbability :  Lane change probability                                                                                    [-100 100]
                      t_ObjList[iObjNr].t_ScoringAssocLane : Reference to array of type SIObjScoreData_t as defined in sit_ext.h                    [Full range of datatype eAssociatedLane_t as defined in Rte_Type.h] 
                      t_SIT_ObjectScores[iObjNr] : The lane assigned to an object by the module
  @glob_out        pt_SITInput->b_Dummy : Dummy member so that structure is not empty                                                               [TRUE, FALSE]

  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN 
  @c_switch_part   SIT_CFG_OBJECT_SCORING         : Configuration switch to enable new object scoring module
  @c_switch_full   FCT_CFG_ACC_SITUATION          : FCT support for ACC SIT (Situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.10.2016
  @changed         06.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_InitEveryCycle(void)
{

	uint8 i;

#if (SIT_O2O_ANALYSIS)
  ObjNumber_t iObjNr;
  uint8 j;
  for (iObjNr = (ObjNumber_t)0; iObjNr < EM_N_OBJECTS; iObjNr++)
  {
    pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.f_LongDist = 0.0f;
    pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.f_LatDist = 0.0f;
    pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.f_DistBorderLeft = 0.f;
    pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.f_DistBorderRight = 0.f;
    pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_ObjID = OBJ_INDEX_NO_OBJECT;
    pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_ObjScoreLane = ASSOC_LANE_UNKNOWN;
    for (j=0u; j<SIT_O2O_NEAR_OBJECTS;j++)
    {
      pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_NearObjIDLeft[j] = OBJ_INDEX_NO_OBJECT;
      pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_NearObjIDRight[j] = OBJ_INDEX_NO_OBJECT;
    }
  }
#endif /* END IF SIT_O2O_ANALYSIS */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_SITOutput->t_CamLaneMarkerCrossed = UNKNOWN_CROSS_CAMLANE;
  pt_SITOutput->t_LaneChangeCamPreMoveState = LANE_CHANGE_CAM_PRE_MOVE_NO;
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/ 

  for(i=0u; i<(uint8)SIT_PATH_OCC_ENTRIES; i++)
  {
	  pt_SITOutput->t_SITPathOccMov2Mov[i].DistTrajToObjEdge = 0.0f;
	  pt_SITOutput->t_SITPathOccMov2Mov[i].LengthTrajEgoFrontToObj = 0.0f;
	  pt_SITOutput->t_SITPathOccMov2Mov[i].next = NULL;
	  pt_SITOutput->t_SITPathOccMov2Mov[i].ObjID = OBJ_INDEX_NO_OBJECT;
	  pt_SITOutput->t_SITPathOccMov2Mov[i].prev = NULL;

	  pt_SITOutput->t_SITPathOccStat2Stat[i].DistTrajToObjEdge = 0.0f;
	  pt_SITOutput->t_SITPathOccStat2Stat[i].LengthTrajEgoFrontToObj = 0.0f;
	  pt_SITOutput->t_SITPathOccStat2Stat[i].next = NULL;
	  pt_SITOutput->t_SITPathOccStat2Stat[i].ObjID = OBJ_INDEX_NO_OBJECT;
	  pt_SITOutput->t_SITPathOccStat2Stat[i].prev = NULL;
  }
  pt_SITOutput->t_SITPathOccStat2Stat[0].next = &(pt_SITOutput->t_SITPathOccStat2Stat[2]);
  pt_SITOutput->t_SITPathOccStat2Stat[1].next = &(pt_SITOutput->t_SITPathOccStat2Stat[3]);

  pt_SITOutput->t_SITPathOccStat2Stat[2].prev = &(pt_SITOutput->t_SITPathOccStat2Stat[0]);
  pt_SITOutput->t_SITPathOccStat2Stat[3].prev = &(pt_SITOutput->t_SITPathOccStat2Stat[1]);

  pt_SITOutput->t_SITPathOccStat2Stat[2].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT;
  pt_SITOutput->t_SITPathOccStat2Stat[3].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT;


  pt_SITOutput->t_SITPathOccMov2Mov[0].next = &(pt_SITOutput->t_SITPathOccMov2Mov[2]);
  pt_SITOutput->t_SITPathOccMov2Mov[1].next = &(pt_SITOutput->t_SITPathOccMov2Mov[3]);

  pt_SITOutput->t_SITPathOccMov2Mov[2].prev = &(pt_SITOutput->t_SITPathOccMov2Mov[0]);
  pt_SITOutput->t_SITPathOccMov2Mov[3].prev = &(pt_SITOutput->t_SITPathOccMov2Mov[1]);

  pt_SITOutput->t_SITPathOccMov2Mov[2].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT;
  pt_SITOutput->t_SITPathOccMov2Mov[3].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT;

#ifdef FCT_SIMU
  pt_SITOutput->StatCloseObjId = OBJ_INDEX_NO_OBJECT;
  pt_SITOutput->StatFarObjId   = OBJ_INDEX_NO_OBJECT;
  pt_SITOutput->CloseObjId     = OBJ_INDEX_NO_OBJECT;
  pt_SITOutput->FarObjId       = OBJ_INDEX_NO_OBJECT;
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft = 0.f;
  pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight = 0.f;
#endif
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight = 0.f;
  pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft = 0.f;
#endif

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

  pt_SITOutput->t_SIT_FrontObstacleDetection.b_FrontObstDetcd = FALSE; 
  pt_SITOutput->t_SIT_FrontObstacleDetection.ObjID = OBJ_INDEX_NO_OBJECT; 
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_SITOutput->t_LaneChangePhase.b_EgoLaneStatus = FALSE;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */

}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitPersistentData                                                                        */ /*!

  @brief           Initialize persistent data of the component

  @description     Initialize persistent data of the component only in INIT mode. 
                   This is data which need to be retained over several cycles.

		@startuml
		Start
		Partition SIT_v_InitPersistentData{
		: Initialized Inputs;
		: Initialize persistent data of the component;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -  
  @glob_out        pt_SITInput : Reference to SIT input data structure
                      pt_SITInput->pt_FIPNaviData       : Pointer to Fip Navi Data structure

                      t_FIPOA.pf_GetObjWidthforCorridor : Object Width for corrdior calculations                             [0.f   10.f]
                      pt_SITInput->pt_FIPRoad           : Pointer to Fip Road Data structure

                      t_FIPTO.pt_FIPTrafficOrientation : FIP Fused Traffic Orientation Value                                 [Full Range of datatype eTrafficOrientation_t as defined in Rte_Type.h]
                      t_FIPOA.pf_ObjAbsVelX : absolute velocity of the object i                                              [-330.f ... 330.f] m/s
                      t_FIPOA.pf_ObjAbsAccelX : the absolute acceleration of the object i                                    [-100.f … +100.f] m/s2
                      t_CP.pf_CourseCurve : Radius of the curve provided by the VDY trajectory                               [-1.f ... +1.f] m^(-1)
                      t_CP.pt_TracePoly : Structure storing the second degree polynomial approximation of a trace            
                      t_FIPMOT.pt_FIPMovObjStaticTrace :                                                                     
                      t_FIPMOT.pu_FIPStaticTraceID : Trace index                                                                                [Full Range of datatype TraceID_t as defined in Rte_Type.h]
                      t_FIPMOT.b_Dummy : Dummy member so that structure is not empty                                                            [TRUE, FALSE]
                      t_LAInput.pf_SeekLaneWidth : pointer to global seek lane width                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pt_ScaleBracketState : state of trace bracket adaption                                                          [Full range of LA_t_ScaleBracketState as defined in la_ext.h]
                      t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m       
                      t_LAInput.pf_ObjToRefDistFiltVar : Pointer to variance of object to reference distance measurement                        [0 ... PI/2*RW_FCT_MAX] m     
                      t_LAInput.pf_ObjDistOnTraj : Distance from vehicle center of gravity to object on trajectory                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m        
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to gradient filter of object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m    
                      t_LAInput.pf_ObjToRefDistGradFiltVar : Pointer to variance of gradient filter of object to reference distance measurement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      t_LAInput.pb_BasePreselObjList : Pre-selection decision for one object, Boolean                                           [TRUE, FALSE]  
                      t_LAInput.pt_ObjAssociatedLane : Associated Lane for object                                                               [Full range of eAssociatedLane_t as defined in Rte_Type.h]
                      t_LAInput.pt_ObjFuncLane : Associated Functional Lane for object                                                          [Full range of eAssociatedLane_t as defined in Rte_Type.h]
                      pt_SITInput->pt_FIPCamLane : Pointer to Fip Camera lane data structure

 @glob_out         pt_SITOutput : Reference to SIT output data structure
                      t_ObjList[t_ObjNr].t_Bool.OccludedByTrace : Information if object i is occluded by a trace                                        [TRUE, FALSE]
                                                                  with i in [0 ... EM_N_OBJECTS-1] and EM_N_OBJECTS as defined in Rte_SWCEmAdapt_Type.h
                      t_ObjList[t_ObjNr].t_Bool.SelectedByPathDecision : Selected By Path Decision                                                      [TRUE,FALSE]
                      t_ObjList[i].u_ObjCutInPotential : Cut in potential of object i                                                                   [0u ... 100u]
                      t_ObjList[i].u_ObjCutOutPotential : Cut out potential of object i                                                                 [0u ... 100u]
                      t_ObjList[ObjNr].f_CrossingDistTrace : Point where trace and trajectory meet,float32 Longitudinal distance of the crossing point  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] 
                      b_Dummy : Dummy member so that structure is not empty                                                                             [TRUE, FALSE]
  @glob_out        pt_SITInputModify->t_LAInputModify.pt_ObjLaneState : The object lane assignment state          

  @c_swirch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE                                  : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING                                : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_part   FCT_CFG_USE_FCT_DYNAMIC_TRACES                                     : Configuration switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_part   FIP_CFG_USE_EGO_TRACE                                              : Configuration switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c-switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_part   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE                              : Configuration switch to enable multi object analyze as one input for the cutin potential
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_ACC_SITUATION                                              : FCT support for ACC SIT (Situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         18.10.2016
  @changed         18.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_InitPersistentData(void)
{
  ObjNumber_t t_ObjNr;
  
  /* Initialize inputs */


#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_SITInput->pt_FIPRoad            = NULL;
  pt_SITInput->pt_FIPTO              = NULL;
  pt_SITInput->pt_FIPOA              = NULL;
  pt_SITInput->pt_FIPRoadType        = NULL;

#if(SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_SITInput->pt_FIPNaviData                     = NULL;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */  
#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
  pt_SITInput->pt_FIPLM                           = NULL;
#endif
#endif
  pt_SITInput->t_CP.pf_CourseCurve = NULL;
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_SITInput->t_CP.pt_TracePoly = NULL;
#if ((FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE) || (FCT_CFG_USE_FCT_STATIC_TRACES))
  pt_SITInput->pt_FIPMOT = NULL;
#endif
  pt_SITInput->t_FIPMOTTraceId.pu_FIPStaticTraceID       = NULL;
#endif
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  pt_SITInput->t_LAInput.pt_ScaleBracketState = NULL;
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
         LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
         LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
  
  pt_SITInput->t_LAInput.pf_ObjToRefDistMeas           = NULL;
  pt_SITInput->t_LAInput.pf_ObjDependantMaxRange       = NULL;
  pt_SITInput->t_LAInput.pt_PredTimeThreshold          = NULL;
  pt_SITInput->t_LAInput.pt_TotalTimeToInlap           = NULL;
  pt_SITInput->t_LAInput.pt_TotalTimeToInlapDrop       = NULL;
  pt_SITInput->t_LAInput.pt_f_DistanceToInlap          = NULL;
  pt_SITInput->t_LAInput.pt_f_DistanceToInlapDrop      = NULL;
  pt_SITInput->t_LAInput.pt_f_TotalDistanceToInlap     = NULL; 
  pt_SITInput->t_LAInput.pt_f_TotalDistanceToInlapDrop = NULL;
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
  pt_SITInput->t_LAInput.pf_ObjToRefDistFiltVar        = NULL;
  pt_SITInput->t_LAInput.pf_ObjToRefDistGradFilt       = NULL;
  pt_SITInput->t_LAInput.pf_ObjToRefDistGradFiltVar    = NULL;
  pt_SITInput->t_LAInput.pf_SeekLaneWidth              = NULL;
  pt_SITInput->t_LAInput.pf_ObjInLap                   = NULL;
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
  pt_SITInput->t_LAInput.pf_CameraCutInPotential  = NULL;
#endif
#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  pt_SITInput->t_LAInput.pf_CameraCutOutPotential = NULL;
#endif
  pt_SITInputModify->t_LAInputModify.pt_ObjLaneState  = NULL;
  pt_SITInput->t_LAInput.pt_ObjAssociatedLane         = NULL;
  pt_SITInput->t_LAInput.pt_ObjFuncLane               = NULL;
#endif /*FCT_CFG_ACC_LANE_ASSOCIATION*/
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_SITInput->pt_FIPCamLane = NULL;
#endif/*END IF FCT_CFG_SEN_CAM_LANE_INTERFACE*/
#if (FCT_CFG_ACC_OOI)
  pt_SITInput->t_OOI.pu_OOIListObjId = NULL;
  pt_SITInput->t_OOI.pt_OOIRelObj = NULL;
#endif
  /*! Initialize output structure */
  for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
  {
    pt_SITOutput->t_ObjList[t_ObjNr].t_Bool.OccludedByTrace         = 0u;
    pt_SITOutput->t_ObjList[t_ObjNr].t_Bool.SelectedByPathDecision  = 0u;
    pt_SITOutput->t_ObjList[t_ObjNr].u_ObjCutInPotential            = 0u;
    pt_SITOutput->t_ObjList[t_ObjNr].u_ObjCutOutPotential           = 0u;
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
    pt_SITOutput->t_ObjList[t_ObjNr].f_CrossingDistTrace            = 0.0f;
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
    pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb = 0u;
    pt_SITOutput->t_LaneChangePhase.t_LCPhaseState = LC_FOLLOW;
    pt_SITOutput->s_LCProb = 0;
    pt_SITOutput->t_ObjList[t_ObjNr].u_BlockedPathSelectionTimer = 0u;
  }
  pt_SITOutput->t_BlockedPathCloseObjID = OBJ_INDEX_NO_OBJECT;
  pt_SITOutput->t_BlockedPathFarObjID = OBJ_INDEX_NO_OBJECT;
  pt_SITOutput->f_CloseObjDistTraj = 0.f;
  pt_SITOutput->f_DistXFarObjId = 0.f;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_SITOutput->f_DistXCloseObjId = 0.f;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  pt_SITOutput->f_FarObjDistTraj = 0.f;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_SetInput                                                                                   */ /*!

  @brief           Set/assign values to SIT input structure

  @description     Set/assign values to SIT input structure

		@startuml
		Start
		Partition SIT_v_SetInput {
		: Set/assign values to SIT inputs;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pSLATE_PerfDegrData->fTunnelProbability : Probability for a tunnel                                                          [0.0.f ... 1.0.f]
  @glob_out        pt_SITInput : Reference to SIT input data structure  
                      pt_SITInput->pt_FIPNaviData       : Pointer to Fip Navi Data structure


                      t_FIPOA.pf_GetObjWidthforCorridor  : Object Width for corrdior calculations                                               [0.f ... 10.f] 
                      pt_SITInput->pt_FIPRoad           : Pointer to Fip Road Data structure

                      t_FIPTO.pt_FIPTrafficOrientation : FIP Fused Traffic Orientation Value                                                    [Full Range of datatype eTrafficOrientation_t as defined in Rte_Type.h]
                      t_LAInput.pt_ScaleBracketState : state of trace bracket adaption                                                          [LA_t_ScalBracketState defined in la_ext.h]
                      t_LAInput.pf_SeekLaneWidth : Seek lane width variable                                                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m       
                      t_LAInput.pf_ObjToRefDistFiltVar : Pointer to variance of object to reference distance measurement                        [0 ... PI/2*RW_FCT_MAX] m     
                      t_LAInput.pf_ObjDistOnTraj : Distance from vehicle center of gravity to object on trajectory                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m        
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to gradient filter of object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m    
                      t_LAInput.pf_ObjToRefDistGradFiltVar : Pointer to variance of gradient filter of object to reference distance measurement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      t_LAInput.pb_BasePreselObjList : Pre-selection decision for one object, Boolean                                           [TRUE, FALSE]  
                      t_LAInput.pt_ObjAssociatedLane : Associated Lane for object                                                               [Full range of eAssociatedLane_t as defined in Rte_Type.h]
                      t_LAInput.pt_ObjFuncLane : Associated Functional Lane for object                                                          [Full range of eAssociatedLane_t as defined in Rte_Type.h]
                      pt_SITInput->pt_FIPCamLane : Pointer to Fip Camera lane data structure

                      t_FIPMOT.pt_FIPMovObjStaticTrace :                                                                     
                      t_FIPMOT.pu_FIPStaticTraceID : Trace index                                                                                [Full Range of datatype TraceID_t as defined in Rte_Type.h]
                      b_Dummy : Dummy member so that structure is not empty                                                                     [TRUE, FALSE]
                      t_CP.pf_CourseCurve : Radius of the curve provided by the VDY trajectory                                                  [-1.f ... +1.f] m^(-1)
                      t_CP.pt_TracePoly : Structure storing the second degree polynomial approximation of a trace            
                      t_FIPOA.pf_ObjAbsVelX(i) : absolute velocity of the object i                                                              [-330.f ... +330.f] m/s
                      t_FIPOA.pf_ObjAbsAccelX(i) : the absolute acceleration of the object i                                                    [-100.f ... +100.f] m/s2
                      t_RTE.pf_ObjLongDisp : Longitudinal displacement of an object                                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_RTE.pf_ObjLatDisp : Lateral displacement of an object i                                                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                      t_RTE.pf_ObjVrelX : Longitudinal (relative) velocity                                                                      [-330.f ... +330.f] m/s
                      t_RTE.pf_ObjArelX : Longitudinal (relative) acceleration                                                                  [-100.f ... +100.f] m/s2
                      t_RTE.pu_AccObjQuality : ACC Object Quality                                                                               [Full range of pu_AccObjQuality as defined in sit_ext.h]
                      t_RTE.pf_EgoLongVel : Longitudinal speed of ego vehicle                                                                   [-330.f ... 330.f] m/s
                      t_RTE.pf_EgoLongAccel : Longitudinal acceleration of ego vehicle                                                          [-100.f ... 100.f] m/s^2
                      t_RTE.pf_EgoCurve : Ego curve                                                                                             [-1 ... +1] m^-2
                      t_RTE.pf_EgoCurveGrad : Curvature Gradient of ego vehicle path                                                            [-1 ... +1] m^-2
                      t_RTE.pf_EgoDrvIntCurve : Curvature of ego vehicle path driving into a curve                                              [-1 ... +1] m^-2
                      t_RTE.pf_EgoDrvIntCurveVar : Curvature variance of ego vehicle path driving into a curve                                  [0 ... +1] m^-2
                      t_RTE.pf_FCTBumperToCoG : Sensor Position Relative to CoG                                                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_RTE.pu_ObjLifeCycles : Lifetime of an object                                                                            [Full range of AlgoCycleCounter_t as defined in Rte_Type.h]
                      t_RTE.pf_ObjVrelYStd : Standard deviation of relative lateral velocity of object                                          [-330.f ... 330.f] m/s
                      t_RTE.pu_DistXSortedObj : List of objects sorted as per distance from EM                                                  [Full range of ObjNumber_t as defined in Rte_Type.h]
                      t_RTE.pt_CamLaneData :  Input Camera Lane Data                                                                            [Full range of t_CamLaneInputData as defined in cp_ext.h]
                      t_RTE.pt_ObjDynProperty : Dynamic property of an object i                                                                 [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                      t_RTE.pt_ObjClassification : : Object Classification for object i                                                         [Full range of datatype SLATE_t_Obj_CLassification as defined in Rte_Type.h]
                      t_RTE.pf_ObjOrientation : Orientation of object                                                                           [Full range of pf_ObjOrientation as defined in sit_ext.h]
                      t_RTE.b_ObjIsMovingToStationary : Boolean informing if object was moving                                                  [TRUE, FALSE]
                      t_RTE.b_ObjIsNew : Boolean informing if object is new                                                                     [TRUE, FALSE]
                      t_RTE.b_ObjIsDeleted : Boolean informing if object is deleted                                                             [TRUE, FALSE]
                      t_RTE.pf_TunnelProbability : Probability for a tunnel                                                                     [0.0.f ... 1.0.f]
                      t_RTE.pt_TurnIndicator : Turn indicator information from input                                                            [Full range of eTurnIndicator_t as defined in Rte_Type.h]
                      t_OOI.pu_OOIListObjId : Get object number of object of interest                                                           [0u ... EM_N_OBJECTS-1

  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE                                  : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c-switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @C_switch_part   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE                              : Configuration switch to enable multi object analyze as one input for the cutin potential
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING                                : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_part   FCT_CFG_USE_FCT_STATIC_TRACES                                      : Configuration Switch for enabling or disabling FCT Computed static Trace in FIP module
  @c_switch_part   SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES                                : Configuration switch for EM old traces
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST                                    : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING                                     : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE                                        : Configuration switch to enable selecting a different parameter set during the operation
  @c_switch_part   FCT_CFG_ACC_OOI                                                    : Configuration switch to configure OOI sub-component for FCT_ACC

  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (Situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.10.2016
  @changed         10.28.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_SetInput(void)
{

#if (FCT_CFG_INPUT_PREPROCESSSING)

  pt_SITInput->pt_FIPRoad                         = FIP_pt_RD_GetRoadData();
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_SITInput->pt_FIPNaviData                     = FIP_pt_ND_GetNaviData();
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
  pt_SITInput->pt_FIPOA              = FIP_pt_GetObjAttributes();
#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE || SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_SITInput->pt_FIPLM            = FIP_pt_LM_GetLaneMatrixData();
#endif
  pt_SITInput->pt_FIPTO   = FIP_pt_TO_GetTrafficOrientation();
  pt_SITInput->pt_FIPRoadType = FIP_pt_RT_GetRoadType();
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION) 
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  pt_SITInput->t_LAInput.pt_ScaleBracketState = LA_pt_ScaleBracketState();
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
          LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
          LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
  pt_SITInput->t_LAInput.pf_ObjToRefDistMeas = &LA_pf_ObjToRefDistMeas;
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
  pt_SITInput->t_LAInput.pf_CameraCutInPotential = &LA_pu_GetCameraBasedCutInPotential;
#endif
#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  pt_SITInput->t_LAInput.pf_CameraCutOutPotential = &LA_pu_GetCameraBasedCutOutPotential;
#endif
  pt_SITInputModify->t_LAInputModify.pt_ObjLaneState   = &LA_pt_GetLAObjLaneState;
  pt_SITInput->t_LAInput.pt_ObjAssociatedLane          = &LA_pt_GetObjAssociatedLane;
  pt_SITInput->t_LAInput.pt_ObjFuncLane                = &LA_pt_GetObjFuncLane;
  pt_SITInput->t_LAInput.pf_ObjDependantMaxRange       = &LA_pf_GetObjDependantMaxRange;
  pt_SITInput->t_LAInput.pt_PredTimeThreshold          = &LA_pt_GetPredTimeThreshold;
  pt_SITInput->t_LAInput.pt_TotalTimeToInlap           = &LA_pt_GetTotalTimeToInlap;
  pt_SITInput->t_LAInput.pt_TotalTimeToInlapDrop       = &LA_pt_GetTotalTimeToInlapDrop;
  pt_SITInput->t_LAInput.pt_f_DistanceToInlap          = &LA_pt_GetDistanceToInlap;
  pt_SITInput->t_LAInput.pt_f_DistanceToInlapDrop      = &LA_pt_GetDistanceToInlapDrop;
  pt_SITInput->t_LAInput.pt_f_TotalDistanceToInlap     = &LA_pt_GetTotalDistanceToInlap;
  pt_SITInput->t_LAInput.pt_f_TotalDistanceToInlapDrop = &LA_pt_GetTotalDistanceToInlapDrop;
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
  pt_SITInput->t_LAInput.pf_ObjToRefDistFiltVar        = &LA_pf_TrajGetObjToRefDistFiltVar;
  pt_SITInput->t_LAInput.pf_ObjToRefDistGradFilt       = &LA_pf_TrajGetObjToRefDistGradFilt;
  pt_SITInput->t_LAInput.pf_ObjToRefDistGradFiltVar    = &LA_pf_TrajGetObjToRefVarDistGradFilt;
  pt_SITInput->t_LAInput.pf_SeekLaneWidth              = LA_pf_SeekLaneWidth();
  pt_SITInput->t_LAInput.pf_ObjInLap                   = &LA_pf_GetObjectInlap;
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */
#endif /* FCT_CFG_ACC_LANE_ASSOCIATION */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
   pt_SITInput->pt_FIPCamLane = FIP_pt_CL_GetCamLaneData();
#endif/*END IF SLATE_CFG_CAM_LANE_INTERFACE */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
  pt_SITInput->pt_FIPMOT                             = FIP_pt_GetMOTData();
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
  pt_SITInput->t_FIPMOTTraceId.pu_FIPStaticTraceID          = &FIP_pu_GetStaticTraceID;
#elif (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
  pt_SITInput->t_FIPMOTTraceId.pu_FIPStaticTraceID          = &SLATE_pu_GetEMARSObjTraceID;
#endif
#endif /* FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)    
  pt_SITInput->t_CP.pt_TracePoly = &CP_pt_GetTracePoly;
#endif
  pt_SITInput->t_CP.pf_CourseCurve = CP_f_GetCourseCurve();
/*! Input of RTE Input Ports */
  pt_SITInput->t_RTE.pf_ObjLongDisp               = &SLATE_pf_GetObjLongDisp;
  pt_SITInput->t_RTE.pf_ObjLatDisp                = &SLATE_pf_GetObjLatDisp;
  pt_SITInput->t_RTE.pf_ObjVrelX                  = &SLATE_pf_GetObjVrelX;
  pt_SITInput->t_RTE.pf_ObjVrelY                  = &SLATE_pf_GetObjVrelY;
  pt_SITInput->t_RTE.pf_ObjArelX                  = &SLATE_pf_GetObjArelX;
  pt_SITInput->t_RTE.pu_AccObjQuality             = &SLATE_u_GetAccQuality;
  pt_SITInput->t_RTE.pf_EgoLongVel                = SLATE_pf_GetEgoLongVel();
  pt_SITInput->t_RTE.pf_EgoLongAccel              = SLATE_pf_GetEgoLongAccel();
  pt_SITInput->t_RTE.pf_EgoCurve                  = SLATE_pf_GetEgoCurve();
  pt_SITInput->t_RTE.pf_EgoCurveGrad              = SLATE_pf_GetEgoCurveGrad();
  pt_SITInput->t_RTE.pf_EgoDrvIntCurve            = SLATE_pf_GetEgoDrvIntCurve();
  pt_SITInput->t_RTE.pf_EgoDrvIntCurveVar         = SLATE_pf_GetEgoDrvIntCurveVar();
  pt_SITInput->t_RTE.pf_FCTBumperToCoG            = SLATE_pf_GetBumperToCoG();
  pt_SITInput->t_RTE.pu_ObjLifeCycles             = &SLATE_pu_GetObjLifeCycles;
  pt_SITInput->t_RTE.pf_ObjVrelYStd               = &SLATE_pf_GetObjVrelYStd;
  pt_SITInput->t_RTE.pu_DistXSortedObj            = &SLATE_pu_GetDistXSortedObj;
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_SITInput->t_RTE.pt_CamLaneData               = SLATE_pt_GetCamLaneData();
#endif
  pt_SITInput->t_RTE.pt_ObjDynProperty            = &SLATE_pt_GetObjDynProperty;
  pt_SITInput->t_RTE.pt_ObjClassification         = &SLATE_pt_GetObjClassification;
  pt_SITInput->t_RTE.b_ObjIsMovingToStationary    = &SLATE_b_GetObjIsMovingToStationary;
  pt_SITInput->t_RTE.pf_ObjOrientation            = &SLATE_f_GetObjOrientation;
  pt_SITInput->t_RTE.b_ObjIsNew                   = &SLATE_b_GetObjIsNew;
  pt_SITInput->t_RTE.b_ObjIsDeleted               = &SLATE_b_GetObjIsDeleted;
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  pt_SITInput->t_RTE.pf_TunnelProbability = (const float32 *) &(SLATE_p_GetPerfDegr()->fTunnelProbability);
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  pt_SITInput->t_RTE.pt_TurnIndicator             = SLATE_pt_GetTurnIndicator();
#endif
#if (FCT_CFG_ACC_OOI)
  pt_SITInput->t_OOI.pu_OOIListObjId              = &OOI_pu_GetOOIListObjId;
  pt_SITInput->t_OOI.pt_OOIRelObj                = OOI_pt_GetRelObj();
#endif
}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    SIT_v_MeasCallback                                                                                   */ /*!

  @brief           Central SIT MEASFreezeDataMTS callback function

  @description     Central SIT MEASFreezeDataMTS callback function. Since callback information is not used in SIT, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SIT internal data frozen.

		@startuml
		Start
		Partition SIT_v_MeasCallback {
		: Central SIT MEASFreezeDataMTS callback function;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @parma[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code

  @pre             -
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
void SIT_v_MeasCallback(void)
{
  return;
}
#endif

/*************************************************************************************************************************
  Functionname:    SIT_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of SIT sub-component

  @description     Set operation mode of SIT sub-component based on given value

		@startuml
		Start
		Partition SIT_v_SetOperationMode {
		: Set operation mode of SIT sub-component;
		}
		End
		@enduml

  @return          -

  @param[in]       t_SITOpModeValue : SIT operation mode value [full range of datatype SLATECompState_t as in slate_types.h]

  @glob_in         -
  @glob_out        @ref SIT_t_State

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         16.03.2017
  @changed         16.03.2017
  @author          $Author: Raj, Rahul (uid41599) $
*************************************************************************************************************************/
void SIT_v_SetOperationMode(SLATECompState_t const t_SITOpModeValue)
{
  SIT_t_State = t_SITOpModeValue;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_MeasFreeze                                                                                 */ /*!

  @brief           Function for freezing simulation and device data
  @description     Function for freezing simulation and device data

		@startuml
		Start
		Partition SIT_v_MeasFreeze {
		Repeat
			: Get data for measurement freeze in device;
		Repeat While (For all EM Objects)
		: Freeze simulation data;
		: Copy data for Device Freeze;
		: Freeze device data;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         SITCutInObjData[ObjID] : Struct for CutIn-potential specific object data
                                            with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_SITOutput : Reference to SIT output data structure
  @glob_in         pt_SITInput : Reference to SIT input data structure
                      t_FrameFreezes.pt_SIT_SimMeasInfoFreeze : Structure for SIT simulation meas info freeze
                      t_FrameFreezes.pt_SIT_SimMeasInfo : Sim Freeze of SIT from Frame
                      t_FrameFreezes.pt_SIT_DeviceMeasInfoFreeze : Structure for SIT device meas info freeze
                      t_FrameFreezes.pt_SIT_DeviceMeasInfo : Sim Freeze of CP from Frame
  @glob_in         SITGlobalDensityData : Struct combination for all lanes
  @glob_out        pt_SITInput : Reference to SIT input data structure
                      t_FrameFreezes.pt_SIT_DeviceMeasInfo->t_SITObjData_Meas[i].t_SITObjCutInPotMeas : Struct for CutIn-potential specific object data
                                                                                                        with i in [0u ... EM_N_OBJECTS-1]
                      t_FrameFreezes.pt_SIT_SimMeasInfo->t_SIT_FreezeOutput : Freeze output of SIT                             
                      t_FrameFreezes.pt_SIT_DeviceMeasInfo->t_SIT_GlobalTrafficDensity_Meas : Struct combination for all lanes
                      
  @c_switch_part   FCT_SIMU                   : FCT simulation enabling switch
  @c_switch_part   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION      : FCT support for ACC SIT (situation) sub-component

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
static void SIT_v_MeasFreeze(void)
{
  ObjNumber_t ObjID;

  /* Get data for measurement freeze in simulation */
  for (ObjID = 0; ObjID < EM_N_OBJECTS; ObjID++)
  {
    /* Get data for measurement freeze in device */
    pt_SITInput->t_FrameFreezes.pt_SIT_DeviceMeasInfo->t_SITObjData_Meas[ObjID].t_SITObjCutInPotMeas = (SITCutInObjData[ObjID]);
    pt_SITInput->t_FrameFreezes.pt_SIT_DeviceMeasInfo->t_SITObjData_Meas[ObjID].uiCutOutProbability = pt_SITOutput->t_ObjList[ObjID].u_ObjCutOutPotential;
    pt_SITInput->t_FrameFreezes.pt_SIT_DeviceMeasInfo->t_SITObjData_Meas[ObjID].uiCutInProbability = pt_SITOutput->t_ObjList[ObjID].u_ObjCutInPotential;
  }

#ifdef FCT_SIMU
  pt_SITInput->t_FrameFreezes.pt_SIT_SimMeasInfo->t_SIT_FreezeOutput = *(pt_SITOutput);
  /*! Freeze simulation data */
  FCT_FREEZE_DATA(pt_SITInput->t_FrameFreezes.pt_SIT_SimMeasInfoFreeze, pt_SITInput->t_FrameFreezes.pt_SIT_SimMeasInfo, NULL);
#endif /* END IF FCT_SIMU */

  /* Copy data for Device Freeze */
#if (SIT_CFG_TRAFFIC_ESTIMATION)
  pt_SITInput->t_FrameFreezes.pt_SIT_DeviceMeasInfo->t_SIT_GlobalTrafficDensity_Meas = (SITGlobalDensityData);
#endif
  /*! Freeze device data */
  (void)FCT_FREEZE_DATA(pt_SITInput->t_FrameFreezes.pt_SIT_DeviceMeasInfoFreeze, pt_SITInput->t_FrameFreezes.pt_SIT_DeviceMeasInfo, NULL);

}
/// @}
#endif /*!< FCT_CFG_ACC_SITUATION */
