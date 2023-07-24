/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_main.c

DESCRIPTION:               Main functions for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.27 $

LEGACY VERSION:            Revision: 2.2.1.1

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
@defgroup ooi_main Main
@ingroup ooi
@brief          This module provides amongst others the main function of the SLATE Component. \n\n
@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

SET_MEMSEC_VAR(OOI_State)
SLATECompState_t OOI_State;       /*!< Operating modes of OOI sub-component */


/*! The OOI private object data */
SET_MEMSEC_VAR(t_OOI_ObjectList)
OOI_ObjectList_t t_OOI_ObjectList;

/*! Definition of component internal pointer to OOI input structure for global access within the component */
SET_MEMSEC_VAR(pt_OOI_Input)
OOIInputConst_t * pt_OOI_Input;

/*! Definition of component global pointer to output structure for global access within component*/
SET_MEMSEC_CONST(pt_OOI_Output)
OOIOutput_t * pt_OOI_Output;

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

static void OOI_v_Init(void);
static void OOI_v_InitEveryCycle(void);
static void OOI_v_InitPersistentData(void);
static void OOI_InitSelectionMarks(void);
static void OOI_v_SetInput(void);
static void OOI_v_MeasFreeze(void);
static void OOI_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);


/*************************************************************************************************************************
  Functionname:    OOI_v_Process                                                                                    */ /*!

  @brief           Object Of Interest Main

  @description     Object Of Interest Main : If the OOI operation mode is OK, the different sub-modules of the OOI module are called. 
                   Otherwise, the OOI initialization is called
				   
				   @startuml
						Start 
							Partition OOI_MainProcess {
								-Initialize OOI Input and Output global structure
								If (OOI operation mode is Normal) then (true)
									- Normal working mode. Initialize data for every cycle for all objects
									Note left: resetting relevant object loss reason for all objects
									- Initialize OOI selection data
									Note left: resetting OOI selection data
									If (increased angle thresholds for object crossing detection is Enabled) then (true)
										- check whether the object is crossing based on the object's orientation.
									Endif
									- Select the objects of interest and fill the relevant object structure
								Elseif (OOI operation mode is Initialization) then (true)
									- module is called for first time or there was a reset. Initialize all data again. Initialize Object of Interest data
								Else (false)
									- Initialize the Object of Interest data
								Endif
							}
						End 
					@enduml

  @return          -

  @param[in]       pt_OOI_InputGlobal  : Reference to OOI input data structure  
  @param[in]       pt_OOI_OutputGlobal : Reference to OOI input data structure  
  @param[out]      -

  @glob_in         OOI_State : Operating modes of OOI sub-component
  @glob_out        pt_OOI_Input  : Reference to OOI input data structure        
  @glob_out        pt_OOI_Output : Reference to OOI output data structure       

  @c_switch_part   OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD : Config switch for using different thresholds to determine crossing objects
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             OOI_v_PreProcess() should be called to initialize/set all the inputs
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
void OOI_v_Process(OOIInputConst_t * pt_OOI_InputGlobal,OOIOutput_t * pt_OOI_OutputGlobal)
{
  /*! Set component global pointer to input structure for global access within the component */
  pt_OOI_Input = pt_OOI_InputGlobal;

  /*! Set component global pointer to output structure for global access within the component */
  pt_OOI_Output = pt_OOI_OutputGlobal;

  switch(OOI_State)
  {
  case COMP_STATE_RUNNING:
    /*! Functions calls for normal operation mode */

    /*! Initialize data every cycle */
    OOI_v_InitEveryCycle();

    /* Init OOI list cycle marks */
    OOI_InitSelectionMarks();

#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
    /* Set crossing flag */
    OOI_v_SetCrossingObjectFlag();
#endif/*!< OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD */

    /* Base selection of the objects of interest */
    OOI_v_SelectBaseObjectsOfInterest();

    /* Fill relevant object structure (is information for the next cycle) */
    OOI_v_FillRelevantObjectStructure();

    break;
  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
    /*! Default */
    OOI_v_Init();
    break;
  }

  /* OOI Measurement Freeze */
  OOI_v_MeasFreeze();

  /*! Initialize component global input pointer since not used anymore */
  pt_OOI_Input = NULL;

  /*! Initialize component global output pointer since not used anymore */
  pt_OOI_Output = NULL;
}


/*************************************************************************************************************************
  Functionname:    OOI_v_Init                                                                                       */ /*!

  @brief           Initialization of Object Of Interest

  @description     Initialization of Object Of Interest : The initialization functions for the different sub-modules of the OOI module are called
					
					@startuml
						Start
							Partition OOI_Initialization {
								- Initialize static/persistent structures in OOI module
								- Initialize non-static/non-persistent data
								}
						End 
					@enduml

  @return          -

  @param[in]       - 
  @param[out]      -

  @glob_in         -
  @glob_out        pt_OOI_Output->OOI_ObjNumber[i] : Object-ID of ACC assessed 6-element array of objects of interest [0u ... EM_N_OBJECTS-1] 
                                                     with i in [0u ... OOI_NUMBER_OF_OOI] with OOI_NUMBER_OF_OOI as defined in ooi_ext.h

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             OOI_v_PreProcess : Initialization of all input, output and other modules of the OOI modules
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
static void OOI_v_Init(void)
{
  ObjNumber_t nr;

  /* Initialize persistent memory in OOI module */  
  OOI_v_InitPersistentData();

  /*! Initialize data every cycle */
  OOI_v_InitEveryCycle();

  /*! Initialization function for relevant object loss */
  OOI_v_ObReObInit();

  /*clear all objects in ooi*/
  for(nr = 0; nr < OOI_NUMBER_OF_OOI; nr++)
  {
    pt_OOI_Output->OOI_ObjNumber[nr] = OBJ_INDEX_NO_OBJECT;
  }

  /*clear all SI related information in TPObject*/
  for(nr = (ObjNumber_t)(EM_N_OBJECTS - 1); nr >= 0; nr--)
  {
    OOI_v_DeleteObject(nr);
  }

#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
    OOI_v_InitCustomGaurdRailStatObjSuppress();
#endif

}

/*************************************************************************************************************************
  Functionname:    OOI_v_PreProcess                                                                            */ /*!

  @brief           OOI Pre-Process function where inputs to OOI module are set/processed before the actual module begins process

  @description     OOI Pre-Process function where inputs to OOI module are set/processed before the actual module begins process
					
					@startuml
						Start
							Partition OOI_PreProcess {
								- Initialize OOI Input and Output global structure
								- Handle all merging and deleting of object lists based on decisions taken in Frame
								- Set all inputs/data being used in OOI module with proper values
							}
						End 
					@enduml

  @return          -

  @param[in]       pt_OOI_InputGlobal   : Reference to OOI input data structure              
  @param[in]       pt_OOI_OutputGlobal  : Reference to OOI output data structure             
  @param[in]       t_MergeDeleteObjList : Reference to merge-delete decision list from Frame 
  @param[out]      -


  @glob_in         pt_OOI_Input  : Reference to OOI input data structure  
  @glob_out        pt_OOI_Output : Reference to OOI output data structure 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.10.2016
  @changed         25.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void OOI_v_PreProcess(OOIInputConst_t * pt_OOI_InputGlobal, OOIOutput_t * pt_OOI_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  pt_OOI_Input = pt_OOI_InputGlobal;
  pt_OOI_Output = pt_OOI_OutputGlobal;
  
  /* Handle Merge Delete Object Lists */
  OOI_v_MergeDeleteObjects(t_MergeDeleteObjList);

  /* Set input to OUT module */
  OOI_v_SetInput();
  
  /* Reset local pointers */
  pt_OOI_Input = NULL;
  pt_OOI_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    OOI_v_InitEveryCycle                                                                            */ /*!

  @brief           Initialize static data of the component in each cycle

  @description     Initialize static data (inputs and outputs) of component each cycle
					
					@startuml
						Start
							Partition OOI_Initialization {
								- Initialize input and output data (non-persistent) used during each cycle and clear all previous information about objects in OOI
							}
						End 
					@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_out        pt_OOI_Output : Reference to OOI output data structure        
                      OOI_t_eRelObjVerlustGrund[i] : Relevant object loss reason [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
                                                     with i in [0u ... OOI_NUMBER_OF_OOI]
                      f_PredictedLatDispl[i]: Object predicted distance to trajectory [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                     with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             OOI_v_PreProcess : All the input and ouput pointers should be initialized
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.10.2016
  @changed         25.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void OOI_v_InitEveryCycle(void)
{
  ObjNumber_t t_Obj;

  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    pt_OOI_Output->f_PredictedLatDispl[t_Obj] = 0.f;
  }
}

/*************************************************************************************************************************
  Functionname:    OOI_v_InitPersistentData                                                                        */ /*!

  @brief           Initialize persistent data of the component

  @description     Initialize persistent data of the component only in INIT mode. 
                   This is data which need to be retained over several cycles.

					@startuml
						Start
							Partition OOI_Initialize_global_static_data {
								If (increased angle thresholds for object crossing detection config is Enabled) then (true)
								Repeat
									- reset crossing status for all Objects
								Repeat while (for entire object list)
								Endif
								- Initalize global static input data
								Note left: reset input data with default value, i.e., NULL
							}
						End 
					@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        pt_OOI_Input : Reference to OOI input data structure                                                                         
                      t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to object to reference velocity measurement                                   [-330f   330f] m/s
                      t_LAInput.pb_BasePreselObjList : Pre-selection decision for one object, Boolean                                           [TRUE, FALSE]
                      t_LAInput.pt_LAObjectList : Output Object list for LA (lane association)                                                  [Full range of datatype LAObjOutput_t as defined in la_ext.h]
                      t_FIPInput.pf_ObjAbsVelX : Velocity (absolute) in X direction                                                             [-330f   330f] m/s
                      t_FIPInput.pf_ObjAbsAccelX : Acceleration (absolute) in X direction                                                       [-100f   100f] m/s^2

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD : Config switch for using different thresholds to determine crossing objects
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP) sub-component
  @c_switch_full   FCT_CFG_ACC_OOI              : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             OOI_v_PreProcess : All the input and ouput pointers should be initialized
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.10.2016
  @changed         25.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void OOI_v_InitPersistentData(void)
{
   ObjNumber_t nr;

#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
  ObjNumber_t t_Obj;

  for (t_Obj = 0u; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    pt_OOI_Output->OOI_CrossingFlag[t_Obj] = FALSE;
  }
#endif/*!< OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD */

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_OOI_Input->t_LAInput.pf_ObjToRefDistMeas = NULL;
  pt_OOI_Input->t_LAInput.pf_ObjToRefDistGradFilt = NULL;
  pt_OOI_Input->t_LAInput.pb_BasePreselObjList = NULL;
  pt_OOI_Input->t_LAInput.pt_LAObjectList = NULL;
#endif
#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_OOI_Input->pt_FIPInput =    NULL;
#endif
#if (FCT_CFG_ACC_SITUATION)
  pt_OOI_Input->t_SITInput.pt_BlockedPathCloseObjID = NULL;
  pt_OOI_Input->t_SITInput.pt_BlockedPathFarObjID = NULL;
  pt_OOI_Input->t_SITInput.pu_BlockedPathSelectionTimer = NULL;
  pt_OOI_Input->t_SITInput.pf_FarObjDistTraj = NULL;
  pt_OOI_Input->t_SITInput.pf_DistXFarObjId = NULL;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_OOI_Input->t_SITInput.pf_DistXCloseObjId = NULL;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  pt_OOI_Input->t_SITInput.pf_CloseObjDistTraj = NULL;
  pt_OOI_Input->t_SITInput.pt_GetLaneChangePhase = NULL;
  pt_OOI_Input->t_SITInput.pt_GetLaneChangeProb = NULL;
#endif
/* Initialize RTE Input Ports */
  pt_OOI_Input->t_RTE.pf_ObjLongDisp               = NULL;
  pt_OOI_Input->t_RTE.pf_ObjLatDisp                = NULL;
  pt_OOI_Input->t_RTE.pf_ObjVRelX                  = NULL;
  pt_OOI_Input->t_RTE.pf_ObjArelX                  = NULL;
  pt_OOI_Input->t_RTE.pf_EgoVelObjSync             = NULL;
  pt_OOI_Input->t_RTE.pf_EgoCurve                  = NULL;
  pt_OOI_Input->t_RTE.pf_ObjDynProperty            = NULL;

  /*clear all objects in ooi*/
  for(nr = 0; nr < OOI_NUMBER_OF_OOI; nr++)
  {
     pt_OOI_Output->OOI_t_eRelObjVerlustGrund[nr]  = OBJ_LOSS_NO_INFO;
  }  

#if (OBJLOSS_NUMBER_OF_OOI > 1)
  for(nr = 0; nr < OBJLOSS_NUMBER_OF_OOI; nr++)
  {
     /* Initialize OOI_RelObject structure */
     OOI_v_SIReSiDaRelObjInit(nr);
  }
#else
  nr = 0;
  OOI_v_SIReSiDaRelObjInit(nr);
#endif /* (OBJLOSS_NUMBER_OF_OOI > 1) */
}

/*************************************************************************************************************************
  Functionname:    OOI_v_MergeDeleteObjects                                                                         */ /*!

  @brief           Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

  @description     Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame
					
					@startuml
						Start
							Partition OOI_Merging_and_Deleting_Objects {
								Repeat
									If (Check if object is marked for deletion) then (true)
										- Delete objects that are set to be delete by Frame
									Else (false)
										: Do nothing;
									Endif
									If (Object is valid object and it is not already existing in object list) then (true)
										- Merge Objects that are marked for merging
										If (Object is marked for deletion or Object is New) then (true)
											- Delete objects that are marked for deletion
										Else (false)
											: Do nothing;
										Endif
									Elseif (old object to keep is similar to existing object) then (true)
										- Old object informationm is merged to new object at the same position in FCT List and old object is deleted 
									Else (false)
										: Do nothing;
									Endif
								Repeat while (for the entire object list)
							}
						End 
					@enduml

  @return          -

  @param[in]       t_MergeDeleteObjList : Reference to merge-delete decision list from Frame [0u ... EM_N_OBJECTS-1] 
                      t_ObjectToKeep    : Object ID to keep                                                          [0u ... EM_N_OBJECTS-1]
                      b_ObjectToDelete  : Object ID to delete                                                        [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         SLATE_b_GetObjIsDeleted(i) : Boolean, returns true if the object i is deleted                              [TRUE, FALSE] with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         SLATE_b_GetObjIsNew(i)     : Boolean, returns true if the object i is new                                  [TRUE, FALSE] with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             - 
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
static void OOI_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
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
      OOI_v_DeleteObject(t_Obj);
    }
    /* 2. Merge Objects */
    if ((t_ObjToKeep > OBJ_INDEX_NO_OBJECT) && (t_ObjToKeep != t_Obj))
    {
      /* 2.1 Merge Objects that are marked for merging */
      OOI_v_MergeObjects(t_ObjToKeep, t_Obj);

      b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(t_Obj);
      b_ObjIsNew = SLATE_b_GetObjIsNew(t_Obj);
      /* 2.2 Delete Objects that are marked for deleting */      
      if(b_ObjIsDeleted || b_ObjIsNew)
      {
        OOI_v_DeleteObject(t_Obj);
      }
    } else if (t_ObjToKeep == t_Obj) {
      /* 3. Old object is merged to new object at the same position in FCT List. 
      First, the information which is copied during the merge, has to be stored locally. 
      Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
      OOI_v_MergeDeleteObjectSameFCTID(t_Obj);
    }
    else
    {
      /*Dummy else loop for keeping QAC happy*/
    }
  } /* END Loop over EM_N_Objects*/
}
/*************************************************************************************************************************
  Functionname:    OOI_v_DeleteObject                                                                               */ /*!

  @brief           Delete objects which are marked for deleting in the relevant fields

  @description     Delete objects which are marked for deleting in the relevant fields
					
					@startuml
					Start
						Partition OOI_DeleteObject {
							- Delete objects marked for deletion
						}
					End 
					@enduml

  @return          -

  @param[in]       ObjId : Object Number (Object ID) of datatype ObjNumber_t as defined in Rte_type.h         [0u ... EM_N_OBJECTS-1]   
  @param[out]      -

  @glob_in         -
  @glob_out        OOI_OBJ_SET_OBJ_OF_INTEREST(i, j) : Setting object of interest using ObjId and OBJ_NOT_OOI [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
                                                       with i in [0u ... EM_N_OBJECTS-1]
                                                       j is      [-1 ... -5]
  @glob_out        t_OOI_ObjectList[i] : Structure describing Object Of Interest of object ObjId              
                                         with i in [0u ... EM_N_OBJECTS-1]
                        SelectedAsOOI                                                                         [Full range of ubit8_t as defined in algo_type.h] [0u, 1u]
                        AlreadyOOI                                                                            [Full range of ubit8_t as defined in algo_type.h] [0u, 1u]

  @c_switch_part   OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD : Config switch for using different thresholds to determine crossing objects
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

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
void OOI_v_DeleteObject(ObjNumber_t ObjId)
{
  //OOI_OBJ_SET_OBJ_OF_INTEREST(ObjId, OBJ_NOT_OOI); 
  SLATE_p_GetFCTPubObj_OOI(ObjId)->eObjOOI = OBJ_NOT_OOI;
  t_OOI_ObjectList[ObjId].t_Bool.SelectedAsOOI                = 0u;
  t_OOI_ObjectList[ObjId].t_Bool.AlreadyOOI                   = 0u;

#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
  pt_OOI_Output->OOI_CrossingFlag[ObjId] = FALSE;
#endif/*!< OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD */
}


/*************************************************************************************************************************
  Functionname:    OOI_v_ReInit                                                                                     */ /*!

  @brief           This function resets the SIT information if object is lost or not selected as OOI

  @description     This function resets the SIT information if object is lost or not selected as OOI for all objects
					
					@startuml
					Start 
						Partition OOI_ReInitialization {
							Repeat 
								If (Object is not selected as OOI) then (true)
									- Reset situation speific global data of objects not selected as OOI
								Else (false)
									: Do nothing;
								Endif
							Repeat while (for the entire objectlist)
						}
					End 
					@enduml

  @return          -

  @param[in]       - 
  @param[out]      -

  @glob_in         t_OOI_ObjectList[i].t_Bool.SelectedAsOOI : Boolean, Object is candidate for the OOI list             [Full range of ubit8_t as defined in algo_type.h] [0u, 1u]
                                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OOI_OBJ_SET_OBJ_OF_INTEREST(i, j) : Setting object of interest using i and OBJ_NOT_OOI               [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
                                                       with i in [0u ... EM_N_OBJECTS-1]
                                                       j is  [-1 ... -5 ]
  @glob_out        t_SIT_ObjectList[i] : Structure describing Situational Interpretation of object i                    
                                         with i in [0u ... EM_N_OBJECTS-1]  
  @glob_out        OBJ_GET_CUT_IN_POTENTIAL(i) : Macro to retrieve cut-in potential of object i with given ObjectID     [0u ... 100u]
                                                 with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OBJ_GET_CUT_OUT_POTENTIAL(i) : Macro to retrieve cut-out potential of object i with given ObjectID   [0u ... 100u]
                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        t_OOI_ObjectList[i] : Structure describing Object Of Interest of object ObjId                        
                                         with i in [0u ... EM_N_OBJECTS-1]
                         SelectedAsOOI                                                                                  [Full range of ubit8_t as defined in algo_type.h] [0u, 1u]
                         AlreadyOOI                                                                                     [Full range of ubit8_t as defined in algo_type.h] [0u, 1u]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

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
void OOI_v_ReInit(void)
{
  ObjNumber_t i;

  /*clear all SI related information in TPObject if not selected as OOI*/
  for(i = (ObjNumber_t)(EM_N_OBJECTS - 1); i >= 0; i--)
  {
    if (t_OOI_ObjectList[i].t_Bool.SelectedAsOOI == FALSE)
    {
      SLATE_p_GetFCTPubObj_OOI(i)->eObjOOI = OBJ_NOT_OOI;
      //OOI_OBJ_SET_OBJ_OF_INTEREST(i, OBJ_NOT_OOI);
      SLATE_p_GetFCTPubObj(i)->LaneInformation.uiCutInProbability = 0u;
      //OBJ_GET_CUT_IN_POTENTIAL(i)       = 0u; 
      SLATE_p_GetFCTPubObj(i)->LaneInformation.uiCutOutProbability = 0u;
      //OBJ_GET_CUT_OUT_POTENTIAL(i)      = 0u; 
      t_OOI_ObjectList[i].t_Bool.SelectedAsOOI  = 0u;
      t_OOI_ObjectList[i].t_Bool.AlreadyOOI     = 0u;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    OOI_InitSelectionMarks                                                                             */ /*!

  @brief           This function intializes the boolean flag SelectedAsOOI of object OOI

  @description     This function intializes the boolean flag SelectedAsOOI of object OOI for all objects
					
					@startuml
					Start 
						Partition OOI_InitializeSelectionMarks {
							Repeat 
								- reset the selected OOI object flag for all objects
							Repeat while (For the entire objectlist)
						}
					End 
					@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        t_OOI_ObjectList[i] : Structure describing OOI of object i as defined in ooi_ext.h
                                         with i in [0u ... EM_N_OBJECTS-1]
                                         SelectedAsOOI                    [Full range of ubit8_t as defined in algo_type.h] [0u, 1u] 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.03.2016

  @author          Fridolin Kolb
*************************************************************************************************************************/
static void OOI_InitSelectionMarks(void)
{
  ObjNumber_t i;

  for(i = (ObjNumber_t)(EM_N_OBJECTS - 1); i >= 0; i--)
  {
    t_OOI_ObjectList[i].t_Bool.SelectedAsOOI = 0u;
  }
}

/*************************************************************************************************************************
  Functionname:    OOI_v_SetInput                                                                                   */ /*!

  @brief           Set/assign values to OOI input structure

  @description     Set/assign values to OOI input structure
					
					@startuml
					Start 
						Partition OOI_SetInput {
							- set OOI input values
						}
					End 
					@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in          -
  @glob_out         pt_OOI_Input : Reference to OOI input data structure                                                                        
                      t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to object to reference velocity measurement                                   [-330f   330f] m/s
                      t_LAInput.pb_BasePreselObjList : Pre-selection decision for one object, Boolean                                           [TRUE, FALSE]
                      t_LAInput.pt_LAObjectList : Outut Object list for LA (lane association)                                                   [Full range of datatype LAObjOutput_t as defined in la_ext.h]
                      t_FIPInput.pf_ObjAbsVelX : Velocity (absolute) in X direction                                                             [-330f   330f] m/s
                      t_FIPInput.pf_ObjAbsAccelX : Acceleration (absolute) in X direction                                                       [-100f   100f] m/s^2

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP) sub-component
  @c_switch_full   FCT_CFG_ACC_OOI              : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             OOI_v_PreProcess : All the input and ouput pointers should be initialized
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.10.2016
  @changed         06.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OOI_v_SetInput(void)
{
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_OOI_Input->t_LAInput.pf_ObjToRefDistMeas     = &LA_pf_ObjToRefDistMeas;
  pt_OOI_Input->t_LAInput.pf_ObjToRefDistGradFilt = &LA_pf_TrajGetObjToRefDistGradFilt;
  pt_OOI_Input->t_LAInput.pb_BasePreselObjList = &LA_pt_GetBasePreselectionState;
  pt_OOI_Input->t_LAInput.pt_LAObjectList = &LA_pt_GetLAObjOutputList;
#endif

#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_OOI_Input->pt_FIPInput = FIP_pt_GetObjAttributes();
#endif
#if (FCT_CFG_ACC_SITUATION)
  pt_OOI_Input->t_SITInput.pt_BlockedPathCloseObjID = SIT_pt_GetBlockedPathCloseObjID();
  pt_OOI_Input->t_SITInput.pt_BlockedPathFarObjID = SIT_pt_GetBlockedPathFarObjID();
  pt_OOI_Input->t_SITInput.pf_CloseObjDistTraj = SIT_pf_GetCloseObjDistTraj();
  pt_OOI_Input->t_SITInput.pf_DistXFarObjId = SIT_pf_GetDistXFarObjId();
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_OOI_Input->t_SITInput.pf_DistXCloseObjId = SIT_pf_GetDistXCloseObjId();
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  pt_OOI_Input->t_SITInput.pf_FarObjDistTraj = SIT_pf_GetFarObjDistTraj();
  pt_OOI_Input->t_SITInput.pu_BlockedPathSelectionTimer = &SIT_pu_BlockedPathSelectionTimer;
  pt_OOI_Input->t_SITInput.pt_GetLaneChangeProb = SIT_pt_GetLaneChangeInfo();
  pt_OOI_Input->t_SITInput.pt_GetLaneChangePhase = SIT_pt_GetLaneChangePhase();
#endif

  /*! Input of RTE Input Ports */
  pt_OOI_Input->t_RTE.pf_ObjLongDisp               = &SLATE_pf_GetObjLongDisp;
  pt_OOI_Input->t_RTE.pf_ObjLatDisp                = &SLATE_pf_GetObjLatDisp;
  pt_OOI_Input->t_RTE.pf_ObjVRelX                  = &SLATE_pf_GetObjVrelX;
  pt_OOI_Input->t_RTE.pf_ObjVRelY                  = &SLATE_pf_GetObjVrelY;
  pt_OOI_Input->t_RTE.pf_ObjArelX                  = &SLATE_pf_GetObjArelX;
  pt_OOI_Input->t_RTE.pf_EgoVelObjSync             = SLATE_pf_GetEgoLongVel();
  pt_OOI_Input->t_RTE.pf_EgoCurve                  = SLATE_pf_GetEgoCurve();
  pt_OOI_Input->t_RTE.pf_ObjDynProperty            = &SLATE_pt_GetObjDynProperty;
#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
  pt_OOI_Input->t_RTE.pf_ObjClassification         = &SLATE_pt_GetObjClassification;
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)*/
}


/*************************************************************************************************************************
  Functionname:    OOI_v_MergeObjects                                                                               */ /*!

  @brief           Merge Objects that are marked for merging

  @description     Merge Objects that are marked for merging
					
					@startuml
					Start 
						Partition OOI_MergeObjects {
							If (Object to be merged is relevant object) then (true)
								- Merge object relavancy information
							Else (false)
								: Do nothing;
							Endif
							- Merge customer specific data
						}
					End
					@enduml

  @return          -

  @param[in]       iObjectToKeep   : Information describing the object to keep        [ 0u ... EM_N_OBJECTS-1]
  @param[in]       iObjectToDelete : Information describing the object to delete      [ 0u ... EM_N_OBJECTS-1]

  @glob_in         SLATE_b_GetObjIsRelevant(i) :  Boolean if object i is the relevant object [TRUE, FALSE]
                                          with i in   [0u ... EM_N_OBJECTS-1]
  @glob_out        OOI_OBJ_SET_OBJ_OF_INTEREST(i, j) : Setting object of interest using iObjectToKeep and OBJ_NOT_OOI [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
                                                       with i in   [0u ... EM_N_OBJECTS-1]
                                                       j is        [-1 ... -5 ]
      
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

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
void OOI_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete)
{
  /*! Take care: If new information considered here, check if the same information should be considered in SIMergeDeleteObjectSameFCTID(...) !!! */

  /* keep object relevance */
  boolean bObjIsRelevant = SLATE_b_GetObjIsRelevant(iObjectToDelete);
  if (bObjIsRelevant)
  {
    SLATE_p_GetFCTPubObj_OOI(iObjectToKeep)->eObjOOI = OBJ_NEXT_OOI;
    //OOI_OBJ_SET_OBJ_OF_INTEREST(iObjectToKeep, OBJ_NEXT_OOI);
  }

  /* merge customer specific data */
  OOI_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete );
}


/*************************************************************************************************************************
  Functionname:    OOI_v_MergeDeleteObjectSameFCTID                                                                 */ /*!

  @brief           Merge and delete the object having same FCT ID

  @description     Old object is merged to new object at the same position in FCT List. 
                   First, the information which is copied during the merge, has to be stored locally. 
                   Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered

					@startuml
					Start
						Partition OOI_MergeDeleteObjectSameFCTID {
							If (Object to be deleted is relevant object) then (true)
								- Merge the object relavancy information first
							Else (false)
								: Do nothing;
							Endif
              - Then Delete the object
						}
					End
					@enduml

  @return          -

  @param[in]       ObjNr : Object Number (Object ID) of datatype ObjNumber_t as defined in Rte_type.h          [0u ... EM_N_OBJECTS-1]  
  @param[out]      -

  @glob_in         SLATE_b_GetObjIsRelevant(i) :  Boolean if object i is the relevant object                           [TRUE, FALSE]
                                          with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OOI_OBJ_SET_OBJ_OF_INTEREST(i, j) : Setting object of interest using ObjNr and OBJ_NOT_OOI  [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
                                                       with i in   [0u ... EM_N_OBJECTS-1]
                                                       j is        [-1 ... -5 ]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

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
void OOI_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr)
{
  /*! Take care: If new information considered here, check if the same information should be considered in SIMergeObjects(...) !!! */

  /*! First: Store the information locally which is considered for merging */
  boolean b_ObjIsRelevant = (boolean)SLATE_b_GetObjIsRelevant(ObjNr);

  /*! Store customer specific data locally (compare to OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) ) */

  /*! Second: Delete the FCT-object */
  OOI_v_DeleteObject(ObjNr);

  /*! Third: Decide which merge-information should be copied */

  /*! Keep object relevance */
  if (b_ObjIsRelevant == TRUE)
  {
    SLATE_p_GetFCTPubObj_OOI(ObjNr)->eObjOOI = OBJ_NEXT_OOI;
    //OOI_OBJ_SET_OBJ_OF_INTEREST(ObjNr, OBJ_NEXT_OOI);
  }

  /*! Merge customer specific data: It might be necessary based on the implementation of OUT_v_MergeCustomObjects to merge the custom specific data.
    The function OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) must be adapted for the case that iObjectToKeep = iObjectToDelete */
}

/*************************************************************************************************************************
  Functionname:    OOI_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of OOI sub-component

  @description     Set operation mode of OOI sub-component based on given value
					
					@startuml
					Start 
						Partition OOI_SetOperationMode {
							- Set OOI operational state/mode
						}
					End 
					@enduml

  @return          -

  @param[in]       t_OOIOpModeValue : OOI operation mode value [full range of datatype LA_t_State as in slate_types.h]

  @glob_in         -
  @glob_out        @ref OOI_State

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
  @author          $Author: Raj, Rahul (uid41599) $
*************************************************************************************************************************/
void OOI_v_SetOperationMode(SLATECompState_t const t_OOIOpModeValue)
{
  OOI_State = t_OOIOpModeValue;
}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    OOI_v_MeasCallback                                                                                   */ /*!

  @brief           OOI Meas freeze callback function

  @description     OOI Meas freeze callback function
					
					@startuml
					Start 
						Partition OOI_MeasCallback {
							- DO nothing
						}
					End 
					@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC
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

  @todo            Check if this funciton can be deleted

  @author          Gergely Ungvary
*************************************************************************************************************************/
void OOI_v_MeasCallback(void)
{
  return;
}
#endif

/*************************************************************************************************************************
  Functionname:    OOI_v_MeasFreeze                                                                                 */ /*!

  @brief           Freeze OOI Object data for simulation

  @description     Freeze OOI Object data for simulation
					
					@startuml
					Start 
						Partition OOI_MeasFreeze {
							- Freeze simulation data
						}
					End 
					@enduml

  @return          -

  @param[in]       - 
  @param[out]      -

  @glob_in         t_OOI_ObjectList[i] : Structure describing OOI of object ObjId as defined in ooi_ext.h
                                         with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OOI_Output : Reference to OOI output data structure                                                                  
  @glob_in         pt_OOI_Input->t_FrameSimFreeze.pt_OOI_SimMeasInfoFreeze : Structure for OOI simulation meas info freeze                                                               
  @glob_in         pt_OOI_Input->t_FrameSimFreeze.pt_OOI_SimMeasInfo : Sim Freeze of SIT from Frame                                        
  @glob_out        pt_OOI_Input  : Reference to OOI input data structure                                                                   
                      t_FrameSimFreeze.pt_OOI_SimMeasInfo->t_OOI_ObjectList[i] : Information describing Object Of Interest of object ObjId 
                                                                                 with i in [0u ... EM_N_OBJECTS-1]
                      t_FrameSimFreeze.pt_OOI_SimMeasInfo->t_OOI_FreezeOutput  : Freeze output of OOI                                      

  @c_switch_part   FCT_SIMU        : FCT support for ACC Simulation
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             OOI_v_PreProcess : All the input and ouput pointers should be initialized
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
static void OOI_v_MeasFreeze(void)
{

#ifdef FCT_SIMU
  ObjNumber_t ObjID;
#endif

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  for (ObjID = 0u; ObjID < EM_N_OBJECTS; ObjID++)
  {
    pt_OOI_Input->t_FrameSimFreeze.pt_OOI_SimMeasInfo->t_OOI_ObjectList[ObjID] = t_OOI_ObjectList[ObjID];
  }
  pt_OOI_Input->t_FrameSimFreeze.pt_OOI_SimMeasInfo->t_OOI_FreezeOutput = *(pt_OOI_Output);

  /*! Freeze simulation data */
  FCT_FREEZE_DATA(pt_OOI_Input->t_FrameSimFreeze.pt_OOI_SimMeasInfoFreeze,pt_OOI_Input->t_FrameSimFreeze.pt_OOI_SimMeasInfo, NULL);  
#endif
  
}

#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
/*************************************************************************************************************************
  Functionname:    OOI_v_SetCrossingObjectFlag                                                                            */ /*!

  @brief           Check if object is crossing

  @description     Check if object is crossing based on the object's orientation.
					
					@startuml
					Start 
						Partition OOI_Check_Object_is_Crossing {
							Repeat
								If (Object is not marked for deletion/deleted) then (true)
									- Calculate Object orientation
									If (OOI object is not classified as crossing object) then (true)
										If (Object orientation more than lower threshold orientation and less than higher threshold orientation) then (true)
											- based on obejct orientation object is deemed as crossing object
										Else (false)
											: Do nothing;
										Endif 
									Else (false)
										If (Object orientation less than lower threshold orientation and more than higher threshold orientation) then (true)
											- based on obejct orientation object is not deemed as crossing object
										Else (false)
											: Do nothing;
										Endif 
									Endif 
								Endif 
							Repeat while (Loop over for all EM objects)
						}
					End 
					@enduml

  @return          -

  @param[in]       iObj : index of the object of type signed char  [ 0 ... EM_N_OBJECTS-1s]

  @glob_in         pt_OOI_Output->OOI_CrossingFlag(i) : Holds the crossing value of object i
                            with i in [0u ... EM_N_OBJECTS]
  @glob_in         OBJ_ORIENTATION(i) : Orientation of object i
                            with i in [0u ... EM_N_OBJECTS]
  @glob_in         OBJ_IS_DELETED(i) : Boolean if object i is deleted [TRUE, FALSE]
                              with i in [0u ... EM_N_OBJECTS]
  @glob_out        pt_OOI_Output->OOI_CrossingFlag(i) : Holds the crossing value of object i
                            with i in [0u ... EM_N_OBJECTS]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : FCT support for ACC OOI (Object Of Interest selection) sub-component
  @c_switch_full   OOI_OBJCROSSING_INCREASED_THRESHOLD : Config switch for using different thresholds to determine crossing objects

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         3/28/2017
  @changed         3/28/2017

  @author          George Chiriac | george.2.chiriac@continental-corporation.com | +49-(8382)-9699-1966
*************************************************************************************************************************/
static void OOI_v_SetCrossingObjectFlag(void)
{
  ObjNumber_t t_Obj;
  float32 f_AbsOrient;
  boolean b_ObjIsDeleted;
  /*! Set the crossing value for each existing object */
  for (t_Obj = 0u; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
  	b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(t_Obj);
    if (b_ObjIsDeleted == FALSE)
    {
      f_AbsOrient = CML_f_Abs(OBJ_ORIENTATION(t_Obj));
      /*! If the object is not crossing then check if it is crossing */
      if( pt_OOI_Output->OOI_CrossingFlag[t_Obj] == FALSE )
      {
        if ( (f_AbsOrient > OOI_LOW_THRESHOLD_ORIENTATION_RAD) && (f_AbsOrient < OOI_HIGH_THRESHOLD_ORIENTATION_RAD) )
        {
          pt_OOI_Output->OOI_CrossingFlag[t_Obj] = TRUE;
        }    
      }
      /*! If the object is crossing then keep this state until the object orientation exceeds the thresholds of the hysteresis */
      else /* case ( pt_OOI_Output->OOI_CrossingFlag[t_Obj] == TRUE ) */
      {
        if ( (f_AbsOrient < OOI_LOW_THRESHOLD_HYSTERESIS_ORIENTATION_RAD) || (f_AbsOrient > OOI_HIGH_THRESHOLD_HYSTERESIS_ORIENTATION_RAD) )
        {
          pt_OOI_Output->OOI_CrossingFlag[t_Obj] = FALSE;
        }
      }
    } /* END IF Object is deleted */
  } /* END For Loop EM_N_Objects */
}
#endif /*!< OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD */
/** @} end defgroup ooi*/
#endif /*!< FCT_CFG_ACC_OOI */

