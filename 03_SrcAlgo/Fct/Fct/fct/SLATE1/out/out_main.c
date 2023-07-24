/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_main.c

DESCRIPTION:               Main functions for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.45 $

LEGACY VERSION:            Revision: 2.3.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "out.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "out_custom.h"



#if (FCT_CFG_ACC_OUTPUT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup out_main Main
@ingroup out
@brief          This module provides amongst others the main function of the SLATE Component. \n\n
@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

SET_MEMSEC_VAR(OUT_t_State)
SLATECompState_t OUT_t_State;       /*!< Operating modes of OUT sub-component */

/*! Definition of component global pointer to output structure for global access within component*/
SET_MEMSEC_VAR(pt_OUTOutput)
OUTOutput_t * pt_OUTOutput;

/*! Definition of component internal pointer to OUT Input structure for global access within OUT */
SET_MEMSEC_VAR(pt_OUTInput)
OUTInputConst_t * pt_OUTInput;


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

SET_MEMSEC_VAR(t_OUT_CustomOutputDebugData)
static OUT_t_CustomOutputDebugInfo t_OUT_CustomOutputDebugData = {/* PRQA S 3218 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:kept for better maintainability */ 
#if (LA_CFG_DTR_OBJ_SELECTION)
0u,
#endif /*!< LA_CFG_DTR_OBJ_SELECTION */
#if (FCT_CFG_CUSTOM_PASSING_STATE)
OUT_NO_LC_POSSIBILITY_INFRASTRUCTURE,
FALSE,
#endif /*!< FCT_CFG_CUSTOM_PASSING_STATE */
#if ((LA_CFG_DTR_OBJ_SELECTION == SWITCH_OFF) && (FCT_CFG_CUSTOM_PASSING_STATE == SWITCH_OFF)) 
0u
#endif
}; /*Need to be filled in custom part!!!!*/// PRQA S 3218
/* date: 2017-01-6, reviewer: Rahul Raj R (uid41599), reason: static local for saving data across function calls/cycles */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void OUT_v_Init(void);
static void OUT_v_InitEveryCycle(void);
static void OUT_v_InitProvidePorts(void);
static void OUT_v_InitPersistentData(void);
static void OUT_v_SetInput(void);
static void OUT_v_MeasFreeze(void);
static void OUT_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);


/*************************************************************************************************************************
  Functionname:    OUT_v_Process                                                                                 */ /*!

  @brief           Process Output

  @description     This function produces the process output

                   @startuml
                   Partition OUT_v_Process{
                   Start
                     : Initialize output FCT public object list version;
                     : Set component global pointer to input structure for global access within the component;
                     : Set component global pointer to output structure for global access within the component;
                     If (normal operation mode) then (TRUE)
                         : Initialize data for every cycle;
                         : Generate output data;
                         : Set state of output data together with cycle counter;
                     elseif (State is Not Initialized, Temporary or Permanent Error) then (TRUE)
                         : Initialize Output;
                         : Set output data to invalid;
                     Else (nothing)
                         : Generates measurement freeze;
                         : Initialize component global input pointer since not used anymore;
                         : Init component global pointer to output structure since not used anymore;
                     Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pt_OUT_InputGlobal  : Reference to input structure of OUT component       
  @parma[in]       pt_OUT_OutputGlobal : Reference to output structure of OUT component      
  @param[out]      - 

  @glob_in         OUT_t_State : Operating modes of OUT sub-component
  @glob_in         GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiTimeStamp  : Time stamp of target measurement            [Full range of datatype AlgoDataTimeStamp_t as defined in Rte_Type.h]
  @glob_in         GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiMeasurementCounter : Counter of target measurement       [Full range of datatype AlgoCycleCounter_t as defined in Rte_Type.h]
  @glob_in         FCTSenFrame.uiCycleCounter : The FCT_SEN cycle counter                                         [Full range of datatype AlgoCycleCounter_t as defined in Rte_Type.h]
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : Macro to access number of objects (based on GET_EM_PUB_OBJ_DATA_PTR)  [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @glob_out        FCT_PUB_OBJ_LIST_VERSION : Assessed Object List for lane assigned of datatype AssessedObjList_t as defined in Rte_Type.h
  @glob_out        pt_OUTInput  : Reference to OUT input data structure
  @glob_out        pt_OUTOutput : Reference to OUT output data structure
  @glob_out        GET_FCT_PUB_OBJ_DATA_PTR
                      sSigHeader.uiTimeStamp : Time stamp of target measurement               [Full range of datatype AlgoDataTimeStamp_t as defined in Rte_Type.h]
                      sSigHeader.uiMeasurementCounter : Counter of target measurement         [Full range of datatype AlgoCycleCounter_t as defined in Rte_Type.h]
                      sSigHeader.uiCycleCounter : Rolling alive counter of source component   [Full range of datatype AlgoCycleCounter_t as defined in Rte_Type.h]
                      sSigHeader.eSigStatus : Validity status of object list                  [Full range of datatype AlgoSignalState_t as defined in Rte_Type.h]
  @glob_out        FCT_PUB_OBJ_LIST_NUM_OBJS : Public list of number of used objects          [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_full   FCT_CFG_ACC_OUTPUT       : Configuration switch to configure OUT (Output) sub-component for FCT_ACC 
                   -

  @pre             - 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.09.2016
  @changed         06.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_Process(OUTInputConst_t * pt_OUT_InputGlobal,OUTOutput_t * pt_OUT_OutputGlobal)
{

#if (FCT_CFG_OBJECT_LIST_PROC)
  /* Initialize output FCT public object list version */
  SLATE_p_GetFCTPubObjList()->uiVersionNumber = FCT_ASSESSED_OBJ_INTFVER;
  //FCT_PUB_OBJ_LIST_VERSION    = FCT_ASSESSED_OBJ_INTFVER;
#endif

  /*! Set component global pointer to input structure for global access within the component */
  pt_OUTInput = pt_OUT_InputGlobal;

  /*! Set component global pointer to output structure for global access within the component */
  pt_OUTOutput = pt_OUT_OutputGlobal;

  switch(OUT_t_State)
  {
  case COMP_STATE_RUNNING:
    /*! Functions calls for normal operation mode */

    /*! Initialize data for every cycle */
    OUT_v_InitEveryCycle();

    /* Generate output data */
    OUT_v_GenerateOutputData();

    OUT_v_CustomProcess();

    /* Set state of output data together with cycle counter */
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.uiTimeStamp          = GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiTimeStamp;
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.uiMeasurementCounter = GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiMeasurementCounter;
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.uiCycleCounter       = FCTSenFrame.uiCycleCounter;
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
    SLATE_p_GetFCTPubObjListHeader()->iNumOfUsedObjects       = SLATE_t_GetNumOfObjectsUsed();
    //FCT_PUB_OBJ_LIST_NUM_OBJS                                 = SLATE_t_GetNumOfObjectsUsed();

    break;
  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /*! Initialization */
    /*! Default */
    OUT_v_Init();

    /* Set output data to invalid */
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.uiTimeStamp          = GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiTimeStamp;
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.uiMeasurementCounter = GET_EM_PUB_OBJ_DATA_PTR->sSigHeader.uiMeasurementCounter;
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.uiCycleCounter       = FCTSenFrame.uiCycleCounter;
    GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.eSigStatus           = ((OUT_t_State == COMP_STATE_NOT_INITIALIZED)?AL_SIG_STATE_INIT:AL_SIG_STATE_INVALID);
    SLATE_p_GetFCTPubObjListHeader()->iNumOfUsedObjects       = 0;
    //FCT_PUB_OBJ_LIST_NUM_OBJS                 = 0;
    break;
  }
  
  OUT_v_MeasFreeze();

  /*! Initialize component global input pointer since not used anymore */
  pt_OUTInput = NULL;
  /*! Init component global pointer to output structure since not used anymore */
  pt_OUTOutput = NULL;
}

/*************************************************************************************************************************
  Functionname:    OUT_v_Init                                                                                 */ /*!

  @brief           Output initialization

  @description     This function initializes the output function

				   @startuml
				   Partition OUT_v_Init{
				   Start
					 : Initialize data for every cycle;
					 : Initialize persistent data of the component;
					 : Set no object selected as relevant object;
					 : Initialize provide ports;
					 : Initializes custom output;
				   end
				   }
				   @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
                   -
                   -

  @pre             - 
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.09.2016
  @changed         05.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
static void OUT_v_Init(void)
{
  ObjNumber_t nr;

  /*! Initialize data for every cycle */
  OUT_v_InitEveryCycle();

  /*! Initialize persistent data of the component */
  OUT_v_InitPersistentData();

  /* Set no object selected as relevant object */
  OUT_v_SeReObPutRelTrckObjNumber(OBJ_INDEX_NO_OBJECT);

  for(nr = (ObjNumber_t)(EM_N_OBJECTS - 1); nr >= 0; nr--)
  {
    OUT_v_DeleteObject(nr);
  }

  OUT_v_InitProvidePorts();

  OUT_v_InitCustom();

}

/*************************************************************************************************************************
  Functionname:    OUT_v_PreProcess                                                                            */ /*!

  @brief           Initialize and Set input before the beginning of the process function

  @description     Initialize and Set input before the beginning of the process function

                   @startuml
                   Partition OUT_v_PreProcess{
                   Start
                     : Reference to input and output structure of OUT component;
                     : Handle Merge Delete Object Lists;
                     : Set input to OUT module;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pt_OUT_InputGlobal   : Reference to input structure of OUT component      
  @parma[in]       pt_OUT_OutputGlobal  : Reference to output structure of OUT component     
  @param[in]       t_MergeDeleteObjList : Reference to merge-delete decision list from Frame 
  @param[out]      -

  @glob_in         -
  @glob_out        pt_OUTInput  : Reference to OUT input data structure  
  @glob_out        pt_OUTOutput : Reference to OUT output data structure 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.10.2016
  @changed         24.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
void OUT_v_PreProcess(OUTInputConst_t * pt_OUT_InputGlobal, OUTOutput_t * pt_OUT_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  pt_OUTInput = pt_OUT_InputGlobal;
  pt_OUTOutput = pt_OUT_OutputGlobal;
  
  /* Handle Merge Delete Object Lists */
  OUT_v_MergeDeleteObjects(t_MergeDeleteObjList);
  
  /* Set input to OUT module */
  OUT_v_SetInput();
  
  pt_OUTInput = NULL;
  pt_OUTOutput = NULL;
}

/*************************************************************************************************************************
  Functionname:    OUT_v_InitEveryCycle                                                                            */ /*!

  @brief           Initialize static data of the component in each cycle

  @description     Initialize static data (inputs and outputs) of component each cycle

                   @startuml
                   Partition OUT_v_InitEveryCycle{
                   Start
                   : Initialize inputs;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -  
  @glob_out        pt_OUTInput : Reference to OUT input data structure
                      b_Dummy  : Dummy member so that structure is not empty [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.10.2016
  @changed         24.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void OUT_v_InitEveryCycle(void)
{
  /* Initialize inputs */
#if(OUT_CFG_CUSTOM_COLUMN_OBJECT)
  pt_OUTOutput->f_LeftMeanVelocity = 0.f;
  pt_OUTOutput->f_RightMeanVelocity = 0.f;
  pt_OUTOutput->f_LeftMaxVelocity = 0.f;
  pt_OUTOutput->f_RightMaxVelocity = 0.f;
  pt_OUTOutput->t_LeftMaxValobjId = OBJ_INDEX_NO_OBJECT;
  pt_OUTOutput->t_RightMaxValobjId = OBJ_INDEX_NO_OBJECT;
  pSLATE_CustomOutput->TrafficDensityData.f_ColumnMeanvL = 0.f;
  pSLATE_CustomOutput->TrafficDensityData.f_ColumnMaxvL =  0.f;
  pSLATE_CustomOutput->TrafficDensityData.f_ColumnMeanvR = 0.f;
  pSLATE_CustomOutput->TrafficDensityData.f_ColumnMaxvR =  0.f;
  pSLATE_CustomOutput->TrafficDensityData.b_ColumnLeft = FALSE;
  pSLATE_CustomOutput->TrafficDensityData.b_ColumnRight = FALSE;
#else
  pt_OUTInput->b_Dummy = FALSE;
#endif /*END IF OUT_CFG_CUSTOM_COLUMN_OBJECT*/

}

/*************************************************************************************************************************
  Functionname:    OUT_v_InitProvidePorts                                                                     */ /*!

  @brief           Initialize provide ports when the operation mode is INIT

  @description     Initialize provide ports when the operation mode is INIT

                   @startuml
                   Partition OUT_v_InitProvidePorts{
                   Start
                   : Call for Initialize provide port ACC six object list to FCT_VEH for INIT mode;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.06.2017
  @changed         26.06.2017

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void OUT_v_InitProvidePorts(void)
{
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  OUT_v_CustomInitSEN2VEHOOI();
#endif
}

/*************************************************************************************************************************
  Functionname:    OUT_v_InitPersistentData                                                                        */ /*!

  @brief           Initialize persistent data of the component

  @description     Initialize persistent data of the component only in INIT mode. 
                   This is data which need to be retained over several cycles.

				   @startuml
                   Partition OUT_v_InitPersistentData{
                   Start
                     : Initialize seek lane width, range of moving object, Range Factor,\n Object list lane association, Object loss reason for OOI Objects, FIP lane matrix;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        pt_OUTInput : Reference to OUT input data structure
                      t_LAInput.pf_SeekLaneWidth : pointer to global seek lane width                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pt_MovingObjPickUpRange  : Pickup range of moving object                                                        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAInput.pf_Rangefac : Range Factor                                                                                      [0.f, 1.f]
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to gradient filter of object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m                                    [Full range of datatype pf_ObjToRefDistGradFilt (float) as defined in out_ext.h]
                      t_LAInput.pf_ObjToRefDistGradFiltVar : Pointer to variance of gradient filter of object to reference distance measurement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m                                 [Full range of datatype pf_ObjToRefDistGradFiltVar (float) as defined in out_ext.h]
                      t_LAInput.pt_LAObjectList : Outut Object list for LA (lane association)                                                   [Full range of datatype LAObjOutput_t as defined in la_ext.h]                                            [Full range of datatype LAObjOutput_t as defined in la_ext.h]
                      t_FIPInput.pf_ObjAbsVelX   : Velocity (absolute) in X direction                                                           [-330f   330f] m/s
                      t_FIPInput.pf_ObjAbsAccelX : Acceleration (absolute) in X direction                                                       [-100f   100f] m/s^2
                      t_SIT.pb_FrontObstSigVal : Front Obstacle Detected Signal Value                                                           [TRUE, FALSE]

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION   : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   FCT_CFG_ACC_SITUATION          : FCT switch for ACC SIT (situation) sub-component
  @c_switch_part   SIT_CFG_OBJECT_SCORING         : Configuration switch to enable object scoring module
  @c_switch_part   SLATE_CFG_TCI_BASE             : Configuration switch which enables SLATE support for TCI Module
  @c_switch_part   SLATE_CFG_TCI_FRONT_OBST_DETCD : Configuration switch which enables SLATE support for TCI Module - Front Obstacle Detection functionality
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING   : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_ACC_OUTPUT             : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.10.2016
  @changed         24.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void OUT_v_InitPersistentData(void)
{
#if (OUT_CFG_FUNC_LANEASSOC_LA)
  uint8 iObj;
  ObjNumber_t ObjNr;
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */
/* Initialize inputs */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_OUTInput->t_LAInput.pf_SeekLaneWidth = NULL;
  pt_OUTInput->t_LAInput.pt_MovingObjPickUpRange = NULL;
  pt_OUTInput->t_LAInput.pf_Rangefac = NULL;
  pt_OUTInput->t_LAInput.pt_LAObjectList = NULL;
#endif /*FCT_CFG_ACC_LANE_ASSOCIATION*/
#if (FCT_CFG_ACC_OOI)
  pt_OUTInput->t_OUT_OOI_Input.pt_OOIObjLossReason = NULL;
  pt_OUTInput->t_OUT_OOI_Input.pf_PredictedLatDispl = NULL;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  pt_OUTInput->t_OUT_OOI_Input.pu_OOIListObjId = NULL;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#endif  /* (FCT_CFG_ACC_OOI) */

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  pt_OUTInput->t_CP.pt_ObjLaneChangeInfo = NULL;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

#if (FCT_CFG_ACC_SITUATION)
  pt_OUTInput->t_SIT.pt_SITObjectList = &SIT_pt_GetSITObjOutputList;
#if ((FCT_CFG_CUSTOM_PASSING_STATE) || (FCT_CFG_LOHP_COMPONENT))
  pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo = NULL;
#endif /* ENDIF ((FCT_CFG_CUSTOM_PASSING_STATE) || (FCT_CFG_LOHP_COMPONENT)) */
#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

  pt_OUTInput->t_SIT.pb_FrontObstSigVal = NULL;
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
#endif /* END IF FCT_CFG_ACC_SITUATION */

#if (OUT_CFG_FUNC_LANEASSOC_LA)
  pt_OUTInput->t_RTE.pt_TurnIndicator = NULL;

  pt_OUTOutput->b_flag_LaneAss_LC = FALSE;

  for (ObjNr = 0; ObjNr < (ObjNumber_t)EM_N_OBJECTS; ObjNr++)
  {
    pt_OUTOutput->t_FuncLA_LC[ObjNr] = ASSOC_LANE_UNKNOWN;
  }

  for (iObj = 0u; iObj < (uint8) OOI_NUMBER_OF_OOI; iObj++)
  {
    pSLATE_HC_Data->t_FuncLaneAss_LC[iObj] = ASSOC_LANE_UNKNOWN;
  }
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */

#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_OUTInput->pt_FIPOA = NULL;
#if(OUT_CFG_CUSTOM_HMI_OBJECTS)
  pt_OUTInput->pt_FIPRD = NULL;
#endif
  pt_OUTInput->pt_FIPRoadType = NULL;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)  
  pt_OUTInput->t_FIPTraceId.pt_ObjTraceID = NULL;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */  
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  pt_OUTInput->pt_FIPLaneMatrix     = NULL;
#endif 
#if(SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_OUTInput->pt_FIPND = NULL;
#endif
#if (OUT_CFG_OVERTAKE_PREVENTION_FEATURE)
  pt_OUTInput->pt_FIPTO = NULL;
#endif /* END IF OUT_CFG_OVERTAKE_PREVENTION_FEATURE */
#endif /* END IF FCT_CFG_INPUT_PREPROCESSSING */
}

/*************************************************************************************************************************
  Functionname:    OOI_v_MergeDeleteObjects                                                                         */ /*!

  @brief           Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

  @description     Handle all merging and deleting of objects lists in FIP in this function based on decisions taken in Frame

                   @startuml
                   Partition OUT_v_MergeDeleteObjects{
                   Start
                   : Make a local copy of the object ID present in merge release list;
                   : Delete objects which were set to be deleted by Frame;
                   If (Object ID to be merged is greater than Object Index NO Object) then (TRUE)
                   : Merge Objects that are marked for merging;
                   : Delete Objects that are marked for deleting;
                   If (Object is Deleted or New) then (TRUE)
                   : Delete Object;
                   Else (FALSE)
                   Endif
                   Elseif (Object to Keep is Object) then (TRUE)
                   : Old object is merged to new object at the same position in FCT List\nFirst, the information which is copied during the merge, has to be stored locally\nThen, the old FCT-object can be deleted and afterwards the "merge"-information can be considered;
                   Else (FALSE)
                   : Do Nothing;
                   Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       t_MergeDeleteObjList : Reference to merge-delete decision list from Frame 
                      t_ObjectToKeep : Object ID that has to be merged                       [0u ... EM_N_OBJECTS-1]    
                      b_ObjectToDelete : Boolean Object to be Deleted Boolean                [TRUE, FALSE]

  @glob_in         - 
  @glob_out        -

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             -
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         14.11.2016
  @changed         14.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OUT_v_MergeDeleteObjects(FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[])
{
  ObjNumber_t t_Obj, t_ObjToKeep;
  boolean b_DeleteObject,b_GetObjIsDeleted,b_GetObjIsNew;
  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    /* Make a local copy of the object ID present in merge release list */
    t_ObjToKeep = t_MergeDeleteObjList[t_Obj].t_ObjectToKeep;
    b_DeleteObject = t_MergeDeleteObjList[t_Obj].b_ObjectToDelete;

    /* 1. Delete objects which were set to be deleted by Frame */
    if (b_DeleteObject == TRUE)
    {
      OUT_v_DeleteObject(t_Obj);
    }
    /* 2. Merge Objects */
    if ((t_ObjToKeep > OBJ_INDEX_NO_OBJECT) && (t_ObjToKeep != t_Obj))
    {
      /* 2.1 Merge Objects that are marked for merging */
      OUT_v_MergeObjects(t_ObjToKeep, t_Obj);

      /* 2.2 Delete Objects that are marked for deleting */      
      //if((SLATE_b_GetObjIsDeleted(t_Obj) || OBJ_IS_NEW(t_Obj)))
      b_GetObjIsDeleted = SLATE_b_GetObjIsDeleted(t_Obj);
      b_GetObjIsNew = SLATE_b_GetObjIsNew(t_Obj);

      if((b_GetObjIsDeleted) || (b_GetObjIsNew))
      {
        OUT_v_DeleteObject(t_Obj);
      }
    } else if (t_ObjToKeep == t_Obj) {
      /* 3. Old object is merged to new object at the same position in FCT List. 
      First, the information which is copied during the merge, has to be stored locally. 
      Then, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
      OUT_v_MergeDeleteObjectSameFCTID(t_Obj);
    }
    else
    {
      /*Dummy else  loop for fixing QAC*/
    }
  } /* END Loop over EM_N_Objects*/
}

/*************************************************************************************************************************
  Functionname:    OUT_v_DeleteObject                                                                                 */ /*!

  @brief           it represents deleted objects

  @description     it represents deleted objects

                   @startuml
                   Partition OUT_v_DeleteObject{
                   Start
                   : Represents deleted objects like CutInProbability and CutOutProbability;
                   End
                   }
                   @enduml
				   
  @return          -

  @param[in]       ObjId : Object ID of datatype ObjNumber_t as defined in Rte_type.h                                 [0u ... EM_N_OBJECTS-1]
  @parma[out]      -

  @glob_in         -
  @glob_out        OBJ_GET_CUT_IN_POTENTIAL(i)  : Macro to retrieve cut-in potential of object i with given ObjectID  [0u ... 100u]
                                                  with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OBJ_GET_CUT_OUT_POTENTIAL(i) : Macro to retrieve cut-out potential of object i with given ObjectID [0u ... 100u]
                                                  with i in [0u ... EM_N_OBJECTS-1]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             - 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.09.2016
  @changed         05.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_DeleteObject(ObjNumber_t ObjId)
{
  SLATE_p_GetFCTPubObj(ObjId)->LaneInformation.uiCutInProbability = 0u;
  //OBJ_GET_CUT_IN_POTENTIAL(ObjId)   = 0u;
  SLATE_p_GetFCTPubObj(ObjId)->LaneInformation.uiCutOutProbability = 0u;
  //OBJ_GET_CUT_OUT_POTENTIAL(ObjId)  = 0u;
#if (OUT_CFG_FUNC_LANEASSOC_LA)
  pt_OUTOutput->t_FuncLA_LC[ObjId] = ASSOC_LANE_UNKNOWN;
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */
}

/*************************************************************************************************************************
  Functionname:    OUT_v_SetInput                                                                                   */ /*!

  @brief           Set/assign values to OUT input structure

  @description     Set/assign values to OUT input structure

                   @startuml
                   Partition OUT_v_SetInput{
                   Start
                   : Assign values to OUT input structure;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -
                      
  @glob_in         -
  @glob_out        pt_OUTInput : Reference to OUT input data structure
                      b_Dummy : Dummy member so that structure is not empty                                                                     [TRUE, FALSE]
                      t_LAInput.pf_SeekLaneWidth : pointer to global seek lane width                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pt_MovingObjPickUpRange  : Pickup range of moving object                                                        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAInput.pf_Rangefac : Range Factor                                                                                      [0.f, 1.f]
                      t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistFiltVar : Pointer to variance of object to reference distance measurement                        [0 ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistGradFilt : Pointer to gradient filter of object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjToRefDistGradFiltVar : Pointer to variance of gradient filter of object to reference distance measurement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAInput.pf_ObjDistOnTraj : Distance from vehicle center of gravity to object on trajectory                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAInput.pt_LAObjectList : Outut Object list for LA (lane association)                                                   [Full range of datatype LAObjOutput_t as defined in la_ext.h]
                      t_SIT.pt_SITObjectScores : Pointer to access the score pointer of a given object
                      t_SIT.pb_FrontObstSigVal : Front Obstacle Detected Signal Value                                                           [0.f, 1.f]
                      t_OUT_OOI_Input.OOI_t_eRelObjLossReason_Zero : Object loss reason for zeroth element                                      [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
                      t_CP.pt_TrajectoryCurrent : Trajectory data from the current cycle                                                        
                      t_CP.pt_TrajectoryState : Trajectory  State                                                                               
                      t_FIPInput.pf_ObjAbsVelX : Velocity (absolute) in X direction                                                             [-330f   330f] m/s
                      t_FIPInput.pf_ObjAbsAccelX : Acceleration (absolute) in X direction                                                       [-100f   100f] m/s^2
                      t_RTE.pt_ObjClassification : Object Classification for object i                                                           [Full range of datatype SLATE_t_Obj_CLassification as defined in Rte_Type.h]
                      t_RTE.pt_ObjDynProperty : Dynamic property of an object i                                                                 [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                      t_RTE.pt_ObjDynSubProperty : Dynamic sub property of object                                                               [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                      t_RTE.pu_ObjExtID : External Object ID of object                                                                          [Full range of datatype unsigned char]
                      t_RTE.pf_ObjLifeTime : Time period since object creation                                                                  [-2.8595 ... +2.8595]
                      t_RTE.pt_ObjLifeCycles : Lifetime in terms of number of cycles                                                            [Full range of AlgoCycleCounter_t defined in Rte_Type.h]
                      t_RTE.pt_ObjMaintenanceState : Administration state of the object                                                         [Full range of datatype EM_t_GenObjMaintenanceState defined in Rte_Type.h]
                      t_RTE.pf_ObjLongDisp : Longitudinal displacement                                                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      t_RTE.pf_ObjLatDisp  : Lateral displacement                                                                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_RTE.pf_ObjArelX : Longitudinal (relative) acceleration                                                                  [-100f   100f] m/s^2
                      t_RTE.pf_ObjVrelX : Longitudinal (relative) velocity                                                                      [-330f   330f] m/s 
                      t_RTE.pf_ObjVrelY : Lateral (relative) velocity                                                                           [-330f   330f] m/s
                      t_RTE.pf_ObjArelY : Lateral (relative) acceleration                                                                       [-100f   100f] m/s^2
                      t_RTE.pf_ObjAabsY : Acceleration (absolute) in Y direction                                                                [-100f   100f] m/s^2
                      t_RTE.pf_ObjVabsY : Velocity (absolute) in Y direction                                                                    [-330f   330f] m/s

  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object detection inputs.
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION    : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   FCT_CFG_ACC_SITUATION           : FCT switch for ACC SIT (situation) sub-component
  @c_switch_part   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable object scoring module
  @c_switch_part   FCT_CFG_ACC_OOI                 : FCT switch for ACC OOI (Object Of Interest selection) sub-component
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING    : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   SLATE_CFG_USE_EXT_OBJ_ID      : Configuration switch to enable SI external object ID assignment
  @c-switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST  : Configuration switch enables EM-Generic_Object list and disables ObjectList_t
  @c-switch_part   SLATE_CFG_TCI_BASE              : Configuration switch which enables the SLATE support for TCI Module
  @c-switch_part   SLATE_CFG_TCI_FRONT_OBST_DETCD  : Configuration switch which enables the SLATE support for TCI Module - Front Ostacle Detected Functionality
  @c_switch_full   FCT_CFG_ACC_OUTPUT              : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

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
static void OUT_v_SetInput(void)
{
#if (FCT_CFG_CUSTOM_PASSING_STATE) && (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_OUTInput->pt_FIPND = FIP_pt_ND_GetNaviData();
#endif /* ENDIF FCT_CFG_CUSTOM_PASSING_STATE */

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_OUTInput->t_LAInput.pf_SeekLaneWidth = LA_pf_SeekLaneWidth();
  pt_OUTInput->t_LAInput.pt_MovingObjPickUpRange = LA_pt_GetMovingObjPickupRange();
  pt_OUTInput->t_LAInput.pf_Rangefac = LA_pf_GetfRangeFac();
  pt_OUTInput->t_LAInput.pf_ObjToRefDistMeas = &LA_pf_ObjToRefDistMeas;
  pt_OUTInput->t_LAInput.pf_ObjDistOnTraj = &LA_pf_ObjDistOnTraj;
  pt_OUTInput->t_LAInput.pf_ObjToRefDistFiltVar = &LA_pf_TrajGetObjToRefDistFiltVar;
  pt_OUTInput->t_LAInput.pt_LAObjectList = &LA_pt_GetLAObjOutputList;
#endif /*(FCT_CFG_ACC_LANE_ASSOCIATION)*/
#if (FCT_CFG_ACC_SITUATION)
  pt_OUTInput->t_SIT.pt_SITObjectList = &SIT_pt_GetSITObjOutputList;
#if ((FCT_CFG_CUSTOM_PASSING_STATE) || (FCT_CFG_LOHP_COMPONENT))
  pt_OUTInput->t_SIT.pt_LaneChangePhaseInfo = SIT_pt_GetLaneChangePhase();
#endif /* ENDIF ((FCT_CFG_CUSTOM_PASSING_STATE) || (FCT_CFG_LOHP_COMPONENT)) */
#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

  pt_OUTInput->t_SIT.pb_FrontObstSigVal = SIT_pb_GetFrontObstSigVal();
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
#endif /*END IF FCT_CFG_ACC_SITUATION */
#if (FCT_CFG_ACC_OOI)
  pt_OUTInput->t_OUT_OOI_Input.pt_OOIObjLossReason  = &OOI_t_LM_ObOOIGetOOILossReason;
  pt_OUTInput->t_OUT_OOI_Input.pf_PredictedLatDispl = &OOI_pf_GetPredictedLatDispl;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  pt_OUTInput->t_OUT_OOI_Input.pu_OOIListObjId      = &OOI_pu_GetOOIListObjId;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#endif  /* (FCT_CFG_ACC_OOI) */
  pt_OUTInput->b_Dummy = FALSE;
  /*! Input of CP component */
  pt_OUTInput->t_CP.pt_TrajectoryCurrent = CP_pt_GetTrajectoryCurrent();
  pt_OUTInput->t_CP.pt_TrajectoryState = CP_pt_GetTrajectoryState();
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_OUTInput->t_CP.pt_TraceTrajectory = CP_pt_GetACCTraceTrajectory();
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  pt_OUTInput->t_CP.pt_ObjLaneChangeInfo = &CP_pt_GetTraceLaneChangeInfo;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_OUTInput->pt_FIPOA = FIP_pt_GetObjAttributes();
#if(OUT_CFG_CUSTOM_HMI_OBJECTS)
  pt_OUTInput->pt_FIPRD = FIP_pt_RD_GetRoadData();
#endif
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  pt_OUTInput->pt_FIPLaneMatrix = FIP_pt_LM_GetLaneMatrixData();
#endif
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
  pt_OUTInput->t_FIPTraceId.pt_ObjTraceID                = &FIP_pu_GetStaticTraceID;
#elif (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) 
  pt_SITInput->t_FIPTraceId.pt_ObjTraceID                = &SLATE_pu_GetEMARSObjTraceID;
#endif
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */   

#if (OUT_CFG_OVERTAKE_PREVENTION_FEATURE)
  pt_OUTInput->pt_FIPTO = FIP_pt_TO_GetTrafficOrientation();
  pt_OUTInput->pt_FIPRoadType = FIP_pt_RT_GetRoadType(); 
#endif /* END IF OUT_CFG_OVERTAKE_PREVENTION_FEATURE */
#endif  /* END IF FCT_CFG_INPUT_PREPROCESSSING */

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  pt_OUTInput->t_RTE.pt_ObjDynSubProperty = &SLATE_pt_GetObjDynSubProperty;
#endif /* ENDIF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
#if (SLATE_CFG_USE_EXT_OBJ_ID)
  pt_OUTInput->t_RTE.pu_ObjExtID = &SLATE_pt_GetExtObjID;
#endif /* ENDIF SLATE_CFG_USE_EXT_OBJ_ID */

  pt_OUTInput->t_RTE.pt_ObjClassification = &SLATE_pt_GetObjClassification;
  pt_OUTInput->t_RTE.pt_ObjDynProperty = &SLATE_pt_GetObjDynProperty;

  pt_OUTInput->t_RTE.pf_ObjLifeTime = &SLATE_pt_GetObjLifeTime;
  pt_OUTInput->t_RTE.pt_ObjLifeCycles = &SLATE_pt_GetObjLifeCycles;
  pt_OUTInput->t_RTE.pt_ObjMaintenanceState = &SLATE_pt_GetObjMaintenanceState;

#if(OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY)
  pt_OUTInput->t_RTE.pt_ObjObstacleProbability = &SLATE_pt_GetObjObstacleProbability;
#endif /* (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY) */

#if (OUT_CFG_FUNC_LANEASSOC_LA)
  pt_OUTInput->t_RTE.pt_TurnIndicator             = SLATE_pt_GetTurnIndicator();
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */

  pt_OUTInput->t_RTE.pf_ObjLongDisp = &SLATE_pf_GetObjLongDisp;
  pt_OUTInput->t_RTE.pf_ObjLatDisp = &SLATE_pf_GetObjLatDisp;
  pt_OUTInput->t_RTE.pf_ObjArelX = &SLATE_pf_GetObjArelX;
  pt_OUTInput->t_RTE.pf_ObjVrelX = &SLATE_pf_GetObjVrelX;
  pt_OUTInput->t_RTE.pf_ObjVrelY = &SLATE_pf_GetObjVrelY;
  pt_OUTInput->t_RTE.pf_ObjArelY = &SLATE_pf_GetObjArelY;
  pt_OUTInput->t_RTE.pf_ObjAabsY = &SLATE_pf_GetObjAabsY;
  pt_OUTInput->t_RTE.pf_ObjVabsY = &SLATE_pf_GetObjVabsY;
  pt_OUTInput->t_RTE.pf_EgoVelObjSync = SLATE_pf_GetEgoLongVel();
}

/*************************************************************************************************************************
  Functionname:    OUT_v_MergeObjects                                                                                 */ /*!

  @brief           merged objects

  @description     it merges the objects

                   @startuml
                   Partition OUT_v_MergeObjects{
                   Start
                   : Keep object relevance;
                   If (Object is Relevant) then (TRUE)
                   : Write information of relevance;
                   Else (FALSE)
                   Endif
                   : Merge customer specific data;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       uiObjectToKeep   : Information describing the object to keep of datatype ObjNumber_t as defined in Rte_type.h    [0u ... EM_N_OBJECTS-1]
  @param[in]       uiObjectToDelete : Information describing the object to delete of datatype ObjNumber_t as defined in Rte_type.h  [0u ... EM_N_OBJECTS-1]
  @param[out]      -
   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC
  @pre             - 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.09.2016
  @changed         05.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete)
{
  /*! Take care: If new information considered here, check if the same information should be considered in SIMergeDeleteObjectSameFCTID(...) !!! */

  /* keep object relevance */
  //if (SLATE_b_GetObjIsRelevant(iObjectToDelete))
  const boolean b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(iObjectToDelete);
  if (b_ObjIsRelevant)
  {
    /* Write information of relevance (OOI-0) */
    OUT_v_SeReObPutRelTrckObjNumber(iObjectToKeep);
  }

  /* merge customer specific data */
  OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete );
}
/*************************************************************************************************************************
  Functionname:    OUT_v_MergeDeleteObjectSameFCTID                                                                                 */ /*!

  @brief           merged/deleted objects at the same function ID

  @description     this function shows the merged and deleted objects at the same function ID

                   @startuml
                   Partition OUT_v_MergeDeleteObjectSameFCTID{
                   Start
                   : Get object relevance;
                   : Delete the FCT-object;
                   If (Object is Relevant) then (TRUE)
                   : Write the object id of the relevant tracked object;
                   Else (FALSE)
                   Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       ObjNr : Object ID of datatype ObjNumber_t as defined in Rte_type.h  [0u ... EM_N_OBJECTS-1]
  @param[out]      -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

  @pre             - 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.09.2016
  @changed         05.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
void OUT_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr)
{
  /*! Take care: If new information considered here, check if the same information should be considered in SIMergeObjects(...) !!! */

  /*! First: Store the information locally which is considered for merging */
  //boolean b_ObjIsRelevant = (boolean)SLATE_b_GetObjIsRelevant(ObjNr);
  boolean b_ObjIsRelevant = (boolean)SLATE_b_GetObjIsRelevant(ObjNr);

  /*! Store customer specific data locally (compare to OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) ) */

  /*! Second: Delete the FCT-object */
  OUT_v_DeleteObject(ObjNr);

  /*! Third: Decide which merge-information should be copied */

  /*! Keep object relevance */
  if (b_ObjIsRelevant == TRUE)
  {
    /*! Write the object id of the relevant tracked object */
    OUT_v_SeReObPutRelTrckObjNumber(ObjNr);
  }

  /*! Merge customer specific data: It might be necessary based on the implementation of OUT_v_MergeCustomObjects to merge the custom specific data.
    The function OUT_v_MergeCustomObjects( iObjectToKeep , iObjectToDelete ) must be adapted for the case that iObjectToKeep = iObjectToDelete */
}

/*************************************************************************************************************************
  Functionname:    OUT_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of OUT sub-component

  @description     Set operation mode of OUT sub-component based on given value

                   @startuml
                   Partition OUT_v_SetOperationMode{
                   Start
                   : Get Operating modes of OUT sub-component;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       t_OUTOpModeValue : OUT operation mode value [full range of datatype SLATECompState_t as in slate_types.h]

  @glob_in         -
  @glob_out        @ref OUTState

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for OUT

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
void OUT_v_SetOperationMode(SLATECompState_t const t_OUTOpModeValue)
{
  OUT_t_State = t_OUTOpModeValue;
}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    OUT_v_MeasCallback                                                                                   */ /*!

  @brief           Central OUT MEASFreezeDataMTS callback function

  @description     Central OUT MEASFreezeDataMTS callback function. Since callback information is not used in OUT, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering OUT internal data frozen.

				   @startuml
                   Partition OUT_v_MeasCallback{
                   Start
                   : Return nothing;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT    : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_ACC_OUTPUT : Configuration switch to configure OUT (Output) sub-component for FCT_ACC

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
void OUT_v_MeasCallback(void)
{
  return;
}
#endif


/*************************************************************************************************************************
  Functionname:    OUT_v_MeasFreeze                                                                                 */ /*!

  @brief           measurement freeze

  @description     this function generates measurement freeze

                   @startuml
                   Partition OUT_v_MeasFreeze{
                   Start
                   : ACC Public Object Data freeze;
                   : Get data for measurement freeze in device;
                   : Freeze device data;
                   : Get data for measurement freeze in simulation;
                   : Freeze simulation data;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      - 

  @glob_in         pt_OUTInput : Reference to OUT input data structure                                                                 
                      t_FrameFreeze.pt_OUT_PubObjListMeasInfoFreeze : Reference to memory where FCT Public Object List will be freezed 
                      t_FrameFreeze.pt_OUT_CustomOutputMeasInfoFreeze :Reference to memory where FCT Custom output will be freezed     
                      t_FrameFreeze.pt_OUT_DeviceMeasInfo->t_OOIList : Custom measurement data for OOI objects                         
                      t_FrameFreeze.pt_OUT_DeviceMeasInfoFreeze : Reference to memory where Device measurement info will be freezed    
                      t_FrameFreeze.pt_OUT_DeviceMeasInfo : Device Freeze of OUT from Frame                                            
                      t_FrameFreeze.pt_OUT_SimMeasInfoFreeze : Reference to memory where Simulation measurement info will be freezed   
  @glob_in         GET_FCT_PUB_OBJ_DATA_PTR                                                                                                               
  @glob_in         pSLATE_CustomOutput : Custom Outputs for FCT component                                                             
  @glob_in         t_OUT_CustomOutputDebugData : OUT custom debug data                                                                 
  @glob_in         pt_OUTOutput : Reference to OUT output data structure                                                               
  @glob_out        pt_OUTInput->t_FrameFreeze.pt_OUT_DeviceMeasInfo->t_OUT_CustomOutputDebugData : OUT custom debug data               
  @glob_out        pt_OUTInput->t_FrameFreeze.pt_OUT_SimMeasInfo->t_OUT_FreezeOutput : Freeze Output of OUT                            

  @c_switch_part   FCT_CFG_ASSESSED_OBJ_OUT_INTF : Interface switch
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE   : FCT Custom I/O Interface
  @c_switch_part   FCT_MEASUREMENT               : Activate Measurement Output Code 
  @c_switch_part   FCT_SIMU                      : FCT support for ACC Simulation
  @c_switch_full   FCT_CFG_ACC_OUTPUT            : Configuration switch to configure OUT (Output) sub-component for FCT_ACC


  @pre             - 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.09.2016
  @changed         01.09.2016

  @author          Amir Jabbari | amir.jabbari@continental-corporation.com | 
*************************************************************************************************************************/
static void OUT_v_MeasFreeze(void)
{
  /* Freeze output ports */
  /* ACC Public Object Data freeze */
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  (void)FCT_FREEZE_DATA(pt_OUTInput->t_FrameFreeze.pt_OUT_PubObjListMeasInfoFreeze, GET_FCT_PUB_OBJ_DATA_PTR, &OUT_v_MeasCallback);
#endif

  /* Freeze internal data */

  /*! Get data for measurement freeze in device */
  pt_OUTInput->t_FrameFreeze.pt_OUT_DeviceMeasInfo->t_OUT_CustomOutputDebugData = t_OUT_CustomOutputDebugData;
  
#if (FCT_MEASUREMENT)
  OUT_v_FreezeData(pt_OUTInput->t_FrameFreeze.pt_OUT_DeviceMeasInfo->t_OOIList);
#endif
  /*! Freeze device data */
  (void)FCT_FREEZE_DATA(pt_OUTInput->t_FrameFreeze.pt_OUT_DeviceMeasInfoFreeze, pt_OUTInput->t_FrameFreeze.pt_OUT_DeviceMeasInfo, &OUT_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  pt_OUTInput->t_FrameFreeze.pt_OUT_SimMeasInfo->t_OUT_FreezeOutput = *(pt_OUTOutput);
  /*! Freeze simulation data */
  FCT_FREEZE_DATA(pt_OUTInput->t_FrameFreeze.pt_OUT_SimMeasInfoFreeze, pt_OUTInput->t_FrameFreeze.pt_OUT_SimMeasInfo, NULL);
#endif

}
/** @} end defgroup */
#endif /*!< FCT_CFG_ACC_OUTPUT */
