/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_main.c

DESCRIPTION:               Main functions for ACC FCT Input Preprocessing (FIP)

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             12.11.2012

VERSION:                   $Revision: 1.21 $

LEGACY VERSION:            Revision: 2.2.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup fip_main Main
@ingroup fip
@brief           Main file for FIP. All the subcomponent process functions are called from here, and all the FIP-component level ports are set.. \n\n

@{
*/

/*****************************************************************************
  GLOBAL CONSTANTS
*****************************************************************************/

//#if defined(FCT_SIMU) && !defined(ACC_MEAS_ID_FIP_OBJECT_LIST)
//#define ACC_MEAS_ID_FIP_OBJECT_LIST   0x20211400uL
//#endif


/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(FIPState)
SLATECompState_t FIPState;      /*!< Operating modes of FIP sub-component */

/*! Definition of component internal pointer to FIP Input structure for global access within FIP */
SET_MEMSEC_VAR(pt_FIP_RTE_Input)
FIPInputRTEConst_t * pt_FIP_RTE_Input;

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

//#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
//SET_MEMSEC_VAR(t_FIPNaviDebugMeasFreeze)
//static FIP_NaviDebugMeasInfo_t t_FIPNaviDebugMeasFreeze;       /*!< Navi debug freeze data */
//#endif

//#ifdef FCT_SIMU
//static const MEASInfo_t t_FIP_ObjectListMeasInfo =
//{
//  ACC_MEAS_ID_FIP_OBJECT_LIST,      /*!<.VirtualAddress */
//  sizeof(t_FIP_ObjectList),         /*!<.Length */
//  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
//  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
//};
//#endif
//
//#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
//SET_MEMSEC_VAR(t_FIPNaviDebugMeasFreeze)
//static FIP_NaviDebugMeasInfo_t t_FIPNaviDebugMeasFreeze;       /*!< Navi debug freeze data */
//
//static const MEASInfo_t t_FIPNaviDebugMeasFreezeInfo =
//{
//  FCT_MEAS_ID_NAVI_FIP_DEBUG,        /*!<.VirtualAddress */
//  sizeof(t_FIPNaviDebugMeasFreeze),  /*!<.Length */
//  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
//  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
//};
//#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void FIPInit(FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal, FIP_ALL_Output_t * pt_FIP_ALL_OutputGlobal);    /*!< Initialization of FCT Input Preprocessing */
static void FIP_v_InitObjectList(void);
static void FIP_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);
static void FIP_v_MeasFreeze(FIP_ALL_Output_t * pt_FIP_ALL_OutputGlobal, FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal);
static void FIP_v_SetRTEInput(void);

/*************************************************************************************************************************
  Functionname:    FIP_v_PreProcess                                                                                 */ /*!

  @brief           FIP Pre-Process function where inputs to FIP module are set/processed before the actual module begins process

  @description     FIP Pre-Process function where inputs to FIP module are set/processed before the actual module begins process

  @startuml 
    Partition FIP_v_PreProcess
    Start
    	Note right: This function preprocesses inputs \n before the actual module begins process	
    	- Depending on the available \n sources set all the FIP input data
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_ALL_InputGlobal : Reference to input structure for FIP module
                   t_FIPSen_MDObjList[] : Array containing the MergeDelete Data for FCT internal lists
  @glob_in         -
  @glob_out        -

  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT support for lane matrix FCT Input Preprocessing (FIP)
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch enabling FIP Object Trace Preprocessing
  @c_switch_part   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_part   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         21.10.2016
  @changed         21.10.2016

  @todo            Currently no input processing is done, this is an empty skeleton to be filled up later on.

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_PreProcess(FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal, FCTSen_MergeDeleteObject_t t_FIPSen_MDObjList[])
{
  /* Merge Delete Object lists/attributes */
  FIP_v_MergeDeleteObjects(t_FIPSen_MDObjList);

  /* Assign local pointers */
  pt_FIP_RTE_Input = &(pt_FIP_ALL_InputGlobal->t_RTE);

   /* Set input */
  FIP_v_SetRTEInput();

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  FIP_v_LM_PreProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_LM_InputConst));
#endif /* FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  FIP_v_ND_PreProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_ND_InputConst));
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

  FIP_v_OA_PreProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_OA_InputConst));

  FIP_v_RD_PreProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_RD_InputConst));

  FIP_v_RT_PreProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_RT_InputConst));

  FIP_v_TO_PreProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_TO_InputConst));
  
  /* Reset local pointers */
  pt_FIP_RTE_Input = NULL;

}

/*************************************************************************************************************************
  Functionname:    FIP_v_Process                                                                                       */ /*!

  @brief           FCT Input Preprocessing Main

  @description     FCT Input Preprocessing Main: If the FIP operation mode is OK, 
                   the different sub-modules of the FIP module are called. Otherwise, the FIP initialization is called.
  
  @startuml 
    Partition FIP_v_Process
    Start
  	  Note right: This function is the Main Input Preprocess	
  	  : FIP State|
    	Split
    	: OK state&gt;
    		- Assign local pointers
    		- Perform Input preprocessing without fusion \n FIP object attributes preprocesing \n FIP Object Trace Preprocessing \n FCT Navi Data Preprocessing \n FCT Camera Lane Data Preprocessing
    		- Perform Input preprocessing with fusion of different input sources \n Traffic Orientation Processing \n Road Processing \n FIP Lane Matrix Preprocessing \n FIP Curvature Change Fusion
  	    - Reset local pointers
    	Split again
  	  : INIT State&gt;
    		- Initialization
    	Split again
    	: default state&gt;
  	  	- Initialization of FCT Input Preprocessing
  	  End split
    Stop
  @enduml
  
  @return          -

  @param[in]       pt_FIP_ALL_InputGlobal : Reference to FIP ALL input structure instantiated in Frame module
  @param[in]       pt_FIP_ALL_OutputGlobal : Reference to FIP ALL output structure instantiated in Frame module

  @glob_in         FIPState : Operating modes of FIP sub-component [full range of datatype FIPState_t in fip_ext.h]
  @glob_out        -

  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT support for lane matrix FCT Input Preprocessing (FIP)
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch enabling FIP Object Trace Preprocessing
  @c_switch_part   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_part   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.04.2013
  @changed         -

  @todo            Currently only OA IO pointers are passed around, this has to be extended to a global structure where all
                   sub-modules of FIP are represented

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_Process(FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal, FIP_ALL_Output_t * pt_FIP_ALL_OutputGlobal)
{

  switch(FIPState)
  {
  case COMP_STATE_RUNNING:
    /* Assign local pointers */
    pt_FIP_RTE_Input = &(pt_FIP_ALL_InputGlobal->t_RTE);

    /*----------- Input preprocessing WITHOUT FUSION -----------*/

    /*! FIP object attributes */
    FIP_v_OA_CalcObjAttributes(&(pt_FIP_ALL_InputGlobal->t_FIP_OA_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_OA_Output));

    /*! FIP Object Trace Preprocessing */
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE)) 
    FIP_v_ObjTraceProcess(&(pt_FIP_ALL_OutputGlobal->t_FIP_MOT_Output));
#endif
    /*! FCT Navi Data Preprocessing */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
    FIPNaviDataProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_ND_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_ND_Output));
#endif
    /*! FCT Camera Lane Data Preprocessing */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
    FIP_v_CamLaneDataProcess(&(pt_FIP_ALL_OutputGlobal->t_FIP_CL_Output));
#endif

    /*----------- FUSION of different input sources -----------*/

    /*! Traffic Orientation Processing */
    FIP_v_TrafficOrientationProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_TO_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_TO_Output));
    /* Road Processing */
    FIP_v_RoadProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_RD_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_RD_Output));
    FIP_v_Process_FuseRoadType(&(pt_FIP_ALL_InputGlobal->t_FIP_RT_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_RT_Output));
    /*! FIP Lane Matrix Preprocessing */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
    FIP_v_LaneMatrixProcess(&(pt_FIP_ALL_InputGlobal->t_FIP_LM_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_LM_Output));
#endif
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
    /*! FIP Curvature Change Fusion */
    FIP_v_CurvatureChangeFusionProcess(&(pt_FIP_ALL_OutputGlobal->t_FIP_CC_Output));
#endif
    /* Reset local pointers */
    pt_FIP_RTE_Input = NULL;

    break;

  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /*! Initialization */
    /*! Default */
    FIPInit(pt_FIP_ALL_InputGlobal, pt_FIP_ALL_OutputGlobal);
    break;
  }

  FIP_v_MeasFreeze(pt_FIP_ALL_OutputGlobal, pt_FIP_ALL_InputGlobal);
}


/*************************************************************************************************************************
  Functionname:    FIPInit                                                                                          */ /*!

  @brief           Initialization of FCT Input Preprocessing

  @description     Initialization of FCT Input Preprocessing: The initialization functions for the different sub-modules of 
                   the FIP module are called
  
  @startuml 
    Partition FIPInit
    Start
  	  Note right: This function initializes \n FCT Input Preprocessing	
  	  - Depending on the available sources \n initialize all the input data structure
    Stop 
  @enduml

  @return          -

  @param[in]       pt_FIP_ALL_InputGlobal : Reference to FIP ALL input structure instantiated in Frame module
  @param[in]       pt_FIP_ALL_OutputGlobal : Reference to FIP ALL output structure instantiated in Frame module

  @glob_in         -
  @glob_out        -

  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT support for lane matrix FCT Input Preprocessing (FIP)
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch enabling FIP Object Trace Preprocessing
  @c_switch_part   FCT_CFG_USE_FCT_DYNAMIC_TRACES . Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_part   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.04.2013
  @changed         22.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPInit(FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal, FIP_ALL_Output_t * pt_FIP_ALL_OutputGlobal)
{
  /*! Initialization of FIP object list */
  FIP_v_InitObjectList();

  /*! Initialization of global FIP object trace data */
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
  FIP_v_InitGlobalObjTraceData(&(pt_FIP_ALL_OutputGlobal->t_FIP_MOT_Output));
#endif
  /*! Initialization of global NAVI data */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  FIPInitGlobalNaviData(&(pt_FIP_ALL_InputGlobal->t_FIP_ND_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_ND_Output));
#endif

  /*! Initialization of global camera lane data */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  FIP_v_InitGlobalCamLaneData(&(pt_FIP_ALL_OutputGlobal->t_FIP_CL_Output));
#endif

  /*! Initialization of global FIP lane matrix data */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  FIP_v_InitGlobalLaneMatrixData(&(pt_FIP_ALL_InputGlobal->t_FIP_LM_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_LM_Output));
#endif
  /*! Initialization of global FIP traffic orientation data */
  FIP_v_InitGlobalLaneTrafficOrientation(&(pt_FIP_ALL_InputGlobal->t_FIP_TO_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_TO_Output));
  /*! Initialization of global FIP road type data */
  FIP_v_Init_Road(&(pt_FIP_ALL_InputGlobal->t_FIP_RD_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_RD_Output));
  FIP_v_Init_FuseRoadType(&(pt_FIP_ALL_InputGlobal->t_FIP_RT_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_RT_Output));
  /*! Initialization of global FIP object attribute data */
  FIP_v_InitGlobalObjAttributes(&(pt_FIP_ALL_InputGlobal->t_FIP_OA_InputConst), &(pt_FIP_ALL_OutputGlobal->t_FIP_OA_Output));
  
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  /*! Initialization of FIP fused curvature change data */
  FIP_v_InitCurvatureChangeFusionData(&(pt_FIP_ALL_OutputGlobal->t_FIP_CC_Output)); 
#endif
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) 
#if (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY)
  /* init custom internal Data */
  FIP_v_InitCustInternalData(); 
#endif /* (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY) */
#endif /* (SLATE_CFG_SEN_SIMPLE_NAVI_INTERFACE) */
  return;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_InitObjectList                                                                             */ /*!

  @brief           Initialization of the object list

  @description     The function FIP_v_DeleteObject is called to delect the content from the last cycle for every object.

  @startuml 
    Partition FIP_v_InitObjectList
    Start
    	Note right: This function initializes the object list	
    	- Iterate through each of the 40 Object
    	- Delete the content from the last cycle for every object
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @todo            The brief and the decription of the function header need to be checked.
*************************************************************************************************************************/
static void FIP_v_InitObjectList(void)
{
  ObjNumber_t ObjId;
  for(ObjId = (ObjNumber_t)(EM_N_OBJECTS - 1); ObjId >= 0; ObjId--)
  {
    FIP_v_DeleteObject(ObjId);
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_MergeDeleteObjects                                                                         */ /*!

  @brief           Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

  @description     Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

  @startuml 
    Partition FIP_v_MergeDeleteObjects
    Start
    	Note right: This function handles all merging \n and deleting of objects lists	
    	- Iterate through each of the 40 Object
  	
    	If (Delete Object is set) then (True)
    		- Delete the object 
    	Else (False)
    	Endif
  
    	If (Object to Keep is not Invalid \n AND \n Object to keep is not equal to current object)
    		- Merge Objects that are marked for merging
    		If (Delete Object or New obeject boolean is set to TRUE) then (True)
    			- Delete Objects that are marked for deleting
  	  	Else (False)
    		If (Object to keep is equal to current object) then (True)
    			- Old object is merged to new object \n at the same position in FCT List
    		Else (False)
    		Endif
    	Endif
    	Endif
    Stop
  @enduml

  @return          -

  @param[in]      t_MergeDeleteObjList[] : Reference to merge-delete decision list from Frame

  @glob_in         None
  @glob_out        None

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.11.2016
  @changed         11.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
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
      FIP_v_DeleteObject(t_Obj);
    }
    /* 2. Merge Objects */
    if ((t_ObjToKeep > OBJ_INDEX_NO_OBJECT) && (t_ObjToKeep != t_Obj))
    {
      /* 2.1 Merge Objects that are marked for merging */
      FIP_v_MergeObjects(t_ObjToKeep, t_Obj);

      b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(t_Obj);
      b_ObjIsNew = SLATE_b_GetObjIsNew(t_Obj);
      /* 2.2 Delete Objects that are marked for deleting */      
      if((b_ObjIsDeleted || b_ObjIsNew))
      {
        FIP_v_DeleteObject(t_Obj);
      }
    } else if (t_ObjToKeep == t_Obj) {
      /* 3. Old object is merged to new object at the same position in FCT List. 
      First, the information which is copied during the merge, has to be stored locally. 
      Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
      FIP_v_MergeDeleteObjectSameFCTID(t_Obj);
    }
    else
    {
      /* dummy else to keep QAC happy */
    }
  } /* END Loop over EM_N_Objects*/
}

/*************************************************************************************************************************
  Functionname:    FIP_v_DeleteObject                                                                               */ /*!

  @brief           Delete object information

  @description     Delete the FCT-content of "NEW"-objects from the last cycle

  @startuml 
    Partition FIP_v_DeleteObject
    Start
    	Note right: This function deletes the content \n of new objects from the last cycle	
    	- Set all the object counters to 0
  	
    	If (absolute speed calculation per object in SIT switch is enabled) then (True)
    		- Set Absolute velocity to zero
    	Else (False)
    	Endif
  	
    	If (absolute filtered absolute acceleration calculation per object in SIT switch is enabled) then (True)
    		- Set Absolute acceleration to zero
    	Else (False)
    	Endif
  
    Stop
  @enduml

  @return          -

  @param[in]       ObjId : Object ID [0...EM_N_OBJECTS]

  @glob_in         -
  @glob_out        t_FIP_ObjectList [i]: Reference to FIP private object data with i in [0...EM_N_OBJECTS[
                    t_Bool.Moving : Object was Moving at some time [TRUE, FALSE]
                    t_Bool.Oncoming : Object was Oncoming at some time [TRUE, FALSE]
                    t_Bool.Stationary : Object was Stationary at some time [TRUE, FALSE]
                    StatObjWasOncoming : structure stationary object was treated as oncoming
                    uiOncomingCounter : No. of cycles which an object was seen oncoming [full range uint8]
                    fAbsVelocity : Absolute longitudinal speed [-100...100] m/s
                    fAbsAcceleration . Absolute longitudinal speed [-20...20] m/s2                    
  @glob_out        t_FIP_ALL_Output : Reference to the output structure of the FIP ALL module
                     t_FIP_OA_Output: Reference to the output structure of the FIP Object Attributes sub module
                       t_ObjList[i] : Object specific output with i in [0...EM_N_OBJECTS[
                         t_Bool.bit_StatObjWasOncoming : Boolean if stationary object was treated as oncoming [TRUE, FALSE]
  @c_switch_part   SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES : Config switch for using Traces computed in EM, ATTENTION this is mutually exclusive with FCT_CFG_USE_FCT_STATIC_TRACES
  @c_switch_part   SIT_CFG_FILTER_ABS_OBJ_SPEED : configuration switch for enabling absolute speed calculation per object in SI
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT Custom I/O Interface
  @c_switch_part   FCT_CFG_CUSTOM_IO_ABS_KINEMATIC : FCT absolute kinematic data in custom interface 
  @c_switch_part   SIT_CFG_FILTER_ABS_OBJ_ACCEL : Configuration switch for enabling filtered absolute acceleration
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.12.2016
  @changed         07.12.2016

  @todo            The brief and the description of the function header need to be checked.
  @todo            The description of the structure StatObjWasOncoming in the function header needs to be checked.
*************************************************************************************************************************/
void FIP_v_DeleteObject(ObjNumber_t ObjId)
{
  /* TODO - Change Direct Access to FIP Output */
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].t_Bool.bit_StatObjWasOncoming   = 0u;
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].t_Bool.bit_ObjWasMoving         = 0u;
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].t_Bool.bit_ObjWasOncoming       = 0u;
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].t_Bool.bit_ObjWasStationary     = 0u;
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].f_ObjectWidthCorridor = 0.f;
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].StatObjWasOncoming.uiOncomingCounter   = 0u;

#if (SIT_CFG_FILTER_ABS_OBJ_SPEED)
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].fAbsVelocity = 0.f;
#endif

#if (SIT_CFG_FILTER_ABS_OBJ_ACCEL)
  t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjId].fAbsAcceleration = 0.f;
#endif
}

/*************************************************************************************************************************
  Functionname:    FIP_v_MergeObjects                                                                               */ /*!

  @brief           Special handling of information transfer in case of object merge. Significant information from both 
                   objects will be merged into object iObjectToKeep.

  @description     Special handling of information transfer in case of object merge. Significant information from both 
                   objects will be merged into object iObjectToKeep.
                    - Merge boolean flags of seen moving/oncoming/stationary
                     Remark: If new information considered here, check if the same information should be considered in FIP_v_MergeDeleteObjectSameFCTID(...) !!!

  @startuml 
    Partition FIP_v_MergeObjects
    Start
    	Note right: This function performs Special handling of \n information transfer in case of object merge
  	
    	If (Object to delete was moving) then (True)
    		- Set Object to Keep to moving
    	Else(False)
    	Endif
  
    	If (Object to delete was oncoming) then (True)
    		- Set Object to Keep to oncoming
    	Else(False)
    	Endif
  
    	If (Object to delete was stationary) then (True)
    		- Set Object to Keep to stationary
    	Else(False)
    	Endif
  
    	If (Stationary Object to delete was oncoming) then (True)
    		- Set Stationary Object to Keep to oncoming
    	Else(False)
    	Endif
  
    Stop
  @enduml

  @return          -

  @param[in]       iObjectToKeep : Object ID to be kept [0...EM_N_OBJECTS[
  @param[in]       iObjectToDelete : Object ID to be deleted [0...EM_N_OBJECTS[

  @glob_in         t_FIP_ObjectList [i] : Reference to FIP private object data with i in [0...EM_N_OBJECTS[
                    t_Bool.Moving : Object was Moving at some time [TRUE, FALSE]
                    t_Bool.Oncoming : Object was Oncoming at some time [TRUE, FALSE]
                    t_Bool.Stationary : Object was Stationary at some time [TRUE, FALSE]
  @glob_out        t_FIP_ObjectList [i] : Reference to FIP private object data with i in [0...EM_N_OBJECTS[
                    t_Bool.Moving : Object was Moving at some time [TRUE, FALSE]
                    t_Bool.Oncoming : Object was Oncoming at some time [TRUE, FALSE]
                    t_Bool.Stationary : Object was Stationary at some time [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.12.2016
  @changed         07.12.2016

  @todo            The brief and the description of the function header need to be checked.
  @todo            The writing form of structure t_FIP_ObjectList as global out at the same time as global in in the 
                   function header needs to be checked.
*************************************************************************************************************************/
void FIP_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete)
{
  /* Merge boolean flags of seen moving/oncoming/stationary */
  if (t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToDelete].t_Bool.bit_ObjWasMoving)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToKeep].t_Bool.bit_ObjWasMoving = 1u;
  }
  if (t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToDelete].t_Bool.bit_ObjWasOncoming)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToKeep].t_Bool.bit_ObjWasOncoming = 1u;
  }
  if (t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToDelete].t_Bool.bit_ObjWasStationary)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToKeep].t_Bool.bit_ObjWasStationary = 1u;
  }

  if (t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToDelete].t_Bool.bit_StatObjWasOncoming)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[iObjectToKeep].t_Bool.bit_StatObjWasOncoming = 1u;
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_MergeDeleteObjectSameFCTID                                                                 */ /*!

  @brief           FIP specific merging and deleting of objects if the object which is merged and the object into which 
                   the old object was merged have the same FCT-ID

  @description     FIP specific merging and deleting of objects if the object which is merged and the object into which 
                   the old object was merged have the same FCT-ID. Here, buffering of information in local variables 
                   is necessary in contrast to FIP_v_MergeObjects.
                   Special handling of information transfer in case of object merge. Significant information from both 
                   objects will be merged into object iObjectToKeep.
                   - Merge boolean flags of seen moving/oncomming/stationary
                   Remark: If new information considered here, check if the same information should be considered in FIP_v_MergeObjects(...) !!!
  
  @startuml 
    Partition FIP_v_MergeDeleteObjectSameFCTID
    Start
  	  Note right: This function performs specific merging and deleting \n of objects if the object which is merged and the object \n into which the old object was merged have the same FCT-ID
  	
  	  If (Object was moving) then (True)
  	  	- Set current object to moving
  	  Else (False)
  	  Endif	
  
  	  If (Object was oncoming) then (True)
  	  	- Set current object to oncoming
  	  Else (False)
    	Endif
  
    	If (Object was stationary) then (True)
    		- Set current object to stationary
  	  Else (False)
  	  Endif
  
  	  If (Stationary Object was oncoming) then (True)
  	  	- Set Stationary current object to oncoming
  	  Else (False)
    	Endif
  
    Stop
  @enduml

  @return          -

  @param[in]       ObjNr : Object ID [0...EM_N_OBJECTS[

  @glob_in         -
  @glob_out        t_FIP_ObjectList [i] : Reference to FIP private object data with i in [0...EM_N_OBJECTS[
                    t_Bool.Moving : Object was Moving at some time [TRUE, FALSE]
                    t_Bool.Oncoming : Object was Oncoming at some time [TRUE, FALSE]
                    t_Bool.Stationary : Object was Stationary at some time [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.12.2016
  @changed         07.12.2016

  @todo            The brief and the description of the function header need to be checked.
*************************************************************************************************************************/
void FIP_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr) 
{
  boolean b_Moving = (boolean)t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_ObjWasMoving;
  boolean b_Oncoming = (boolean)t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_ObjWasOncoming;
  boolean b_Stationary = (boolean)t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_ObjWasStationary;
  boolean b_StatObjWasOncoming = (boolean)t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_StatObjWasOncoming;

  /*! Merge boolean flags of seen moving/oncoming/stationary */
  if (b_Moving == TRUE)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_ObjWasMoving = 1u;
  }
  if (b_Oncoming == TRUE)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_ObjWasOncoming = 1u;
  }
  if (b_Stationary == TRUE)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_ObjWasStationary = 1u;
  }
  if (b_StatObjWasOncoming == TRUE)
  {
    t_FIP_ALL_Output.t_FIP_OA_Output.t_ObjList[ObjNr].t_Bool.bit_StatObjWasOncoming = 1u;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_MeasFreeze                                                                                 */ /*!

  @brief           Freeze the measured data

  @description     Freeze the measured data: first write the data, and then freeze.

  @startuml 
    Partition FIP_v_MeasFreeze
    Start
    	Note right: This function freezes the measured data
    	- Get FIP specific Lane Matrix information
    	- Get FIP specific Navigation information
    	- Freeze device data
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_ALL_OutputGlobal : Reference to FIP ALL output structure instantiated in Frame module

  @glob_in         FIP_DeviceMeasInfo : device measurement information
                     t_NaviMeasInfo : navi measurement information
                   t_FIP_DeviceMeasInfoFreeze : structure used to storing navi measurement information
                   t_FIP_SimMeasInfoFreeze: structure used to storing simulation measurement information
                   t_FIP_SimMeasInfo : simulation measurement information
  @glob_out        -

  @c_switch_part   FCT_SIMU : FCT simulation enabling switch
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.12.2016
  @changed         07.12.2016

  @todo            The brief and the description of the function header need to be checked.
  @todo            The descriptions of the variables FIP_DeviceMeasInfo.t_NaviMeasInfo, t_FIP_DeviceMeasInfoFreeze, 
                   t_FIP_SimMeasInfoFreeze and t_FIP_SimMeasInfo in the function header need to be checked.
*************************************************************************************************************************/
static void FIP_v_MeasFreeze(FIP_ALL_Output_t * pt_FIP_ALL_OutputGlobal, FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal)
{
  /* Get FIP specific LM information */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  FIP_v_LMSetMeasData(&(pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_DeviceMeasInfo->t_FIPLaneMatrix), &(pt_FIP_ALL_OutputGlobal->t_FIP_LM_Output));
#endif

  /* Get FIP specific TO information */
  FIP_v_TOSetMeasData(&(pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_DeviceMeasInfo->t_FIPTrafficOrientInfo), &(pt_FIP_ALL_OutputGlobal->t_FIP_TO_Output));

  /* Get FIP specific NAVI information */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  FIP_v_NaviSetMeasData(&(pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_DeviceMeasInfo->t_NaviMeasInfo), &(pt_FIP_ALL_OutputGlobal->t_FIP_ND_Output));
#endif

  /*! Freeze device data */
  FCT_FREEZE_DATA(pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_DeviceMeasInfoFreeze, pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_DeviceMeasInfo, NULL); //PRQA S 3200
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: The return value of MEASFreezeDataMTS is not used currently */

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_SimMeasInfo->t_FIP_FreezeAllOutput = *(pt_FIP_ALL_OutputGlobal);
  /*! Freeze simulation data */
  FCT_FREEZE_DATA(pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_SimMeasInfoFreeze, pt_FIP_ALL_InputGlobal->t_FrameFreeze.pt_FIP_SimMeasInfo, NULL);
#endif
}

/*************************************************************************************************************************
  Functionname:    FIP_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of FIP sub-component

  @description     Set operation mode of FIP sub-component based on given value

  @startuml 
  Partition FIP_v_SetOperationMode
  Start
  	Note right: This function sets operation mode of FIP sub-component
  	- Set operation mode of FIP sub-component based on given value
  Stop
  @enduml

  @return          -

  @param[in]       CompState : Operation mode that will be set for FIP [as defined in slate_types.h]

  @glob_in         -
  @glob_out        @ref FIPState

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_SetOperationMode(SLATECompState_t const t_FIPOpModeValue)
{
  FIPState = t_FIPOpModeValue;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_SetRTEInput                                                                                   */ /*!

  @brief           Set/assign values to FIP input structure

  @description     Set/assign values to FIP input structure

  @startuml 
  Partition FIP_v_SetRTEInput
  Start
  	Note right: This function sets/assigns values to FIP input structure
  	- Update the pointers of FIP input structure
  Stop
  @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -none                                                  

  @glob_out        -none  
                    

  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (Situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.9.2017
  @changed         03.9.2017

  @author          Srivatsav Gowda | Srivatsav.Gowda@Continental-Corporation.com | +9180-6679-6591
*************************************************************************************************************************/
static void FIP_v_SetRTEInput(void)
{
/*! Input of RTE Input Ports */
  pt_FIP_RTE_Input->pf_ObjLongDisp               = &SLATE_pf_GetObjLongDisp;
  pt_FIP_RTE_Input->pf_ObjLatDisp                = &SLATE_pf_GetObjLatDisp;
  pt_FIP_RTE_Input->pf_ObjVRelX                  = &SLATE_pf_GetObjVrelX;
  pt_FIP_RTE_Input->pf_ObjArelX                  = &SLATE_pf_GetObjArelX;
  pt_FIP_RTE_Input->pf_EgoVelObjSync             = SLATE_pf_GetEgoLongVel();
  pt_FIP_RTE_Input->pf_EgoAccObjSync             = SLATE_pf_GetEgoLongAccel();
  pt_FIP_RTE_Input->pf_EgoCurve                  = SLATE_pf_GetEgoCurve();
  pt_FIP_RTE_Input->pt_ObjDynamicProperty        = &SLATE_pt_GetObjDynProperty;
}

///@}
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
