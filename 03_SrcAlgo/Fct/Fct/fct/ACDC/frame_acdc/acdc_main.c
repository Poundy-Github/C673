/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               acdc_main.c

DESCRIPTION:               Main function file for ACDC evaluation module

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/24 06:18:27CEST $

VERSION:                   $Revision: 1.73 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "acdc_int.h"

#if (ACDC_CFG_FRAME)

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup frame_main Main
@ingroup frame
@brief          This module provides amongst others the main function of the ACDC Component. \n\n

@description    The following functionalities are provided by this module:
                - Main function of the ACDC Component which calls the main routines of all subcomponents: @ref ACDC_v_Exec.
                - Determination of the runtime of the ACDC Component: @ref ACDC_SERVICE_ADD_EVENT.
@{
*/

/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/
/*PRQA S 3211 GLOBVAR*/ /* date: 2017-11-28, reviewer: Andreas Danner, reason: Global Variables kept here for better maintainability */
#if FCT_CFG_USE_ACDC_INTERNAL_MEMORY
/* ACDC process memory */
static GA_ACDC_Mem_DataInterCycle     ACDCInter     = {0};
static GA_ACDC_Mem_DataInterCycleMeas ACDCInterMeas = {0};
static GA_ACDC_Mem_DataIntraCycle     ACDCIntra     = {0};
static GA_ACDC_Mem_DataIntraCycleMeas ACDCIntraMeas = {0};
#ifdef ACDC_SIMU
static GA_ACDC_Mem_DataSimu           ACDCSimuData  = {0};
#endif  /* #ifdef ACDC_SIMU */
#endif /* #if FCT_CFG_USE_ACDC_INTERNAL_MEMORY */


SET_MEMSEC_VAR(ACDCAccessData)
  ACDCAccessData_t                      ACDCAccessData;


/*PRQA L:GLOBVAR*/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void ACDC_v_SetCompState(AlgoCompState_t           * const pSenCompState    ,
                                FCT_OP_MODE_t       const         ScheduledOpMode  ,
                                GenAlgoQualifiers_t const         BufferedQualifier );
#endif /* #if (FCT_CFG_USE_ALGOCOMPSTATE) */

static void ACDC_v_AlgoInit      ( void );

static void ACDC_v_PostProcessing( void );

static void ACDC_v_PreProcessing(  reqACDCPrtList_t const * const pRequirePorts);





#if (FCT_CFG_USE_DEM)
static void ACDC_v_SetDem( AS_t_Dem_EventIDType     const         Dem_EventId     ,
                           AS_t_Dem_EventStatusType const         Dem_EventStatus  );
#endif /*FCT_CFG_USE_DEM*/



#if (FCT_CFG_RUNTIME_MEAS)
static void ACDC_v_RuntimeMeasInit(void);
#endif /* #if (FCT_CFG_RUNTIME_MEAS) */
static void ACDC_v_MergeDeleteObj(EM_t_GenObjectList const * const pObjList);

static eGDBError_t ACDC_e_AssignStaticMemoryToAccessData( ACDC_ProcMem_t const * const p_ACDCProcMem
#if USE_ACDCWRAPPER_STACK
                                                        , ACDC_DataWrapperStack_t * const pACDCStackData
#endif /* #if USE_ACDCWRAPPER_STACK */
                                                        );
static void        ACDC_v_AssignAccessPointers( reqACDCPrtList_t const * const p_ACDCRequirePorts
                                               ,provACDCPrtList_t      * const p_ACDCProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                               ,AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif /* #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */
                                               );
static void ACDC_v_InitInterCycleData(ACDC_ProcMem_t const * const p_ACDCProcMem);

#if (FCT_MEASUREMENT)
static void ACDC_v_FillDebugData(void);
#endif /* #if (FCT_MEASUREMENT) */

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         ACDC_v_AlgoInit                                                                              */ /*!

  @brief                Initializes the ACDC component.

  @description          Sets the variable bIsInitialized of the @ref ACDC_p_GetFrameData to false and sets the flag 
                        bCollisionAvoidActive of the port pErrorOut to FALSE.

  @return               void

  @glob_in              @ref ACDC_p_GetProPortList
  @glob_out             @ref ACDC_p_ModFrameData
                        @ref ACDC_p_ModProPortList

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_ALGOINIT_001 \n
                        @ref TEST_ACDC_V_ALGOINIT_002 

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void ACDC_v_AlgoInit (void)
{
  /* reset FirstCycleDone */
  ACDC_p_ModFrameData()->bIsInitialized  = b_FALSE;

  if (ACDC_p_GetProPortList()->pErrorOut != NULL)
  {
    ACDC_p_ModProPortList()->pErrorOut->bCollisionAvoidActive = b_FALSE;
  }
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_PreProcessing                                                                          */ /*!

  @brief                Handles the PreProcessing in each cycle before the call of the modules of the ACDC component.

  @description          According to the ACDC OpMode, several steps are executed:\n
                        @startuml ACDC_v_PreProcessing_activity.png
                        start
                          if(Operation mode is **COMP_STATE_RUNNING**?) then (Yes)
                            :1}
                            #Orange:Handle objects that were merged in EM:
                            <b>ACDC_v_MergeDeleteObj</b> >
                          elseif(Operation mode is **COMP_STATE_NOT_INITIALIZED**?)
                            :2}
                            #Orange:Call the ACDC initialization function:
                            <b>ACDC_v_AlgoInit</b> >
                            #Orange:Handle objects that were merged in EM:
                            <b>ACDC_v_MergeDeleteObj</b> >
                          else(No)
                            :3}
                            #Orange:Call the ACDC initialization function:
                            <b>ACDC_v_AlgoInit</b> >
                          endif
                        stop
                        @enduml
  @return               void

  @param[in]            pRequirePorts :  Pointer to the require port list.

  @glob_in              @ref ACDC_e_GetSubCompState \n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod            @ref TEST_ACDC_V_PREPROCESSING_001  \n
                         @ref TEST_ACDC_V_PREPROCESSING_002  \n
                         @ref TEST_ACDC_V_PREPROCESSING_003  \n

  @traceability          Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void ACDC_v_PreProcessing(reqACDCPrtList_t const * const pRequirePorts)
{
  ACDCCompState_t const ACDCState = ACDC_e_GetSubCompState(ACDC_SUB_COMP_ACDC);

  switch (ACDCState)
  {
  case COMP_STATE_RUNNING:
    /* Merge and Delete or Delete fct Object data*/
    ACDC_v_MergeDeleteObj(pRequirePorts->pEmGenObjList);

    break;

  case COMP_STATE_NOT_INITIALIZED:
    ACDC_v_AlgoInit();
    /* Merge and Delete or Delete fct Object data*/
    ACDC_v_MergeDeleteObj(pRequirePorts->pEmGenObjList);
    break;
    
  case COMP_STATE_PERMANENT_ERROR:
  case COMP_STATE_TEMPORARY_ERROR:
  default:
  /*This path is not reachable, as the ACDC state is checked before in ACDC_v_Exec*//* init EBA frame */
    ACDC_v_AlgoInit ();
    break;
  } /* endswitch */

}

/*************************************************************************************************************************
  Functionname:         ACDC_v_PostProcessing                                                                        */ /*!

  @brief                Function to group actions that shall be executed after the call of the main ACDC Subcomponents.

  @description          This function executes the following steps:
                        - Fusion of the states of all ACDC subcomponents into the ACDC State: 
                          @ref ACDC_v_SetSubComponentStates & @ref ACDC_e_GetWorstSubComponentState
                        - Setting of the legacy Error out interface signal bCollisionAvoidActive based on the state of CD.
                        - Setting of the Number of hypotheses in the header of the Hypotheses list to @ref MAX_NUM_OF_HYPS.
                        .

  @return               void

  @param[in]            void

  @glob_in              @ref ACDC_e_GetSubCompState\n
                        @ref ACDC_e_GetWorstSubComponentState\n
                        @ref ACDC_p_ModProPortList
  @glob_out             @ref ACDC_p_ModProPortList \n
                        @ref ACDC_v_SetSubComponentStates

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     None

  @testmethod           @ref TEST_ACDC_V_POSTPROCESSING_001 \n
                        @ref TEST_ACDC_V_POSTPROCESSING_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void ACDC_v_PostProcessing(void)
{

  /* ---------- Component States Fusion---------- */
  /* Write the Fused state to the ACDCState */
  ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_ACDC, ACDC_e_GetWorstSubComponentState(ACDC_SUB_COMP_ALL));

  /* ---------- Error out Interface---------- */
  /* Specific handling of legacy interface in FCTSenErrorOut   */
  /* Set the signal bCollisionAvoidActive based on the CDState */
  if (ACDC_e_GetSubCompState(ACDC_SUB_COMP_CD) == COMP_STATE_RUNNING)
  {
    ACDC_p_ModProPortList()->pErrorOut->bCollisionAvoidActive = b_TRUE;
  }
  else
  {
    ACDC_p_ModProPortList()->pErrorOut->bCollisionAvoidActive = b_FALSE;
  }

  /* ---------- pHypotheses Interface---------- */
  /* Initialize the number of Hypotheses in the output structure */
  ACDC_p_ModProPortList()->pHypotheses->Header.uiNumOfHypotheses = (uint8) MAX_NUM_OF_HYPS;

}

/*************************************************************************************************************************
  Functionname:         ACDC_SERVICE_ADD_EVENT                                                                       */ /*!

  @brief                Determine runtime of the ACDC component based on service functions provided by Base SW.

  @description          Determine runtime of the ACDC component based on service functions.
                        The time difference between the start of an event and its end is considered as Run Time.
                        - e_RTA_EVT_AlgoStart : Store the current Timestamp as run time for the given Event.
                        - e_RTA_EVT_AlgoEnd   : Subtract the timestamp that is stored for the given event from the
                                                current timestamp. Store the result as Run Time.
                        The service functions are provided via function pointers in the structure @ref AS_t_RtaEventType.
                        @startuml ACDC_SERVICE_ADD_EVENT_activity.png
                        start
                        partition #LightBlue "**defined(RTA_INTERFACE_VERSION) &&**\n**(RTA_INTERFACE_VERSION >= 4)**" {
                        :Use RTA_t_Events as event type input parameter for function;
                        }
                        partition #LightBlue "**(defined(RTA_INTERFACE_VERSION) &&**\n**(RTA_INTERFACE_VERSION < 4)) ||**\n**(!defined(RTA_INTERFACE_VERSION))**" {
                        :Use AS_t_RtaEventType as event type input parameter for function;
                        }
                        partition #LightBlue "**FCT_CFG_RTA_PROFILING &&**\n**FCT_CFG_USE_SERVICE_POINTER_FUNCTS**" {
                          :Report process state towards
                          RTE by adding of service event;
                        }
                          if(Service function pointer is not NULL? ) then (Yes)
                            partition #LightBlue **FCT_CFG_RUNTIME_MEAS** {
                            if(Eventtype is Start?) then (Yes)
                              :1}
                              :Store the current timestamp in the
                              Runtime Info Array at the location
                              of the EventID;
                            elseif(Eventtype is End?) then (Yes)
                              :2}
                              :Subtract the timestamp that is at the
                              Event ID form the current timestamp;
                              :Store the result at the event ID;
                            else(No)
                              :3}
                              :Reset the timestamp at the Event ID;
                            endif
                            }
                          else(No)
                            :4}
                          endif

                        stop
                        @enduml
                        ATTENTION: The function always has to be called in the specified order:
                        1. e_RTA_EVT_AlgoStart
                        2. e_RTA_EVT_AlgoEnd

  @return               void

  @param[in]            RtaEvtType : RTE Event type that shall be triggered.
  @param[in]            u_IDRtaMapping :  Identifier of the event that is affected by the RTE event.
  @param[in]            u_OptData :  Optional information data.

  @glob_in              ACDC_p_GetRuntimeInfo
  @glob_in              ACDC_p_GetServiceFunctionsList
  @glob_out             ACDC_p_ModRuntimeInfo

  @c_switch_full        @ref ACDC_CFG_FRAME
  @c_switch_part        @ref FCT_CFG_RTA_PROFILING  \n
                        @ref FCT_CFG_RUNTIME_MEAS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_SERVICE_ADD_EVENT_001 \n
                        @ref TEST_ACDC_SERVICE_ADD_EVENT_002 \n
						@ref TEST_ACDC_SERVICE_ADD_EVENT_003 \n
						@ref TEST_ACDC_SERVICE_ADD_EVENT_004 \n
						@ref TEST_ACDC_SERVICE_ADD_EVENT_005

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION))
#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
void ACDC_SERVICE_ADD_EVENT( const RTA_t_Events RtaEvtType, const ACDC_t_RtaMapping u_IDRtaMapping, const uint8 u_OptData)
#else
void ACDC_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const ACDC_t_RtaMapping u_IDRtaMapping, const uint8 u_OptData)
#endif /* #if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4)) */
#else
void ACDC_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const ACDC_t_RtaMapping u_IDRtaMapping, const uint8 u_OptData)
#endif /* #if (defined(RTA_INTERFACE_VERSION)) */
{

  const uint8 u_IdLocal = (uint8)u_IDRtaMapping;
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  if (    (ACDC_p_GetServiceFunctionsList()                           != NULL)
       && (ACDC_p_GetServiceFunctionsList()->pfRTAAlgoServiceAddEvent != NULL) )
  {
    ACDC_p_GetServiceFunctionsList()->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT60, u_IdLocal + ACDC_RTA_OFFSET, u_OptData);
  }
#endif /* #if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)) */

#if (FCT_CFG_RUNTIME_MEAS)
  /* Check NULL pointer. 
  Check whether additional parameter (i.e. Object ID) is defined. This cannot be handled */
  if (    (ACDC_p_GetServiceFunctionsList()                     != NULL)
       && (ACDC_p_GetServiceFunctionsList()->pfGetTimestampuS32 != NULL)
       && (u_OptData                                            == 0u  ) )
  {
    if(RtaEvtType == e_RTA_EVT_AlgoStart) 
    {
      ACDC_ASSERT(ACDC_p_GetRuntimeInfo()->uACDCRuntime[u_IdLocal] == 0u);
      /* In case of a start event, the current timestamp is stored in the array. */
      ACDC_p_ModRuntimeInfo()->uACDCRuntime[u_IdLocal] = ACDC_p_GetServiceFunctionsList()->pfGetTimestampuS32();
    }
    else if(RtaEvtType == e_RTA_EVT_AlgoEnd)
    {
      ACDC_ASSERT( ACDC_p_GetRuntimeInfo()->uACDCRuntime[u_IdLocal] > 0u);
      /* In case of an end event, the time difference between the start and end event is stored in the array. 
          Precondition: Valid start event must have been called before. */
      ACDC_p_ModRuntimeInfo()->uACDCRuntime[u_IdLocal] = ACDC_p_GetServiceFunctionsList()->pfGetTimestampuS32() - ACDC_p_GetRuntimeInfo()->uACDCRuntime[u_IdLocal];
    }
    else
    {
      /* Reset runtime info:
      if no valid event type
      if no valid start event has been called before the end event. */
      ACDC_p_ModRuntimeInfo()->uACDCRuntime[u_IdLocal] = 0u;
      ACDC_ASSERT(FALSE);
    }
  }
#endif /* #if (FCT_CFG_RUNTIME_MEAS) */
  /* PRQA S 3119 3 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
  _PARAM_UNUSED(RtaEvtType);
  _PARAM_UNUSED(u_IdLocal);
  _PARAM_UNUSED(u_OptData);
}

#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:         ACDC_v_RuntimeMeasInit                                                                       */ /*!

  @brief                Initializes the entire array uACDCRuntime of the global variable @ref ACDC_p_ModRuntimeInfo.

  @return               void

  @glob_in              None
  @glob_out             @ref ACDC_p_ModRuntimeInfo

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME \n
                        @ref FCT_CFG_RUNTIME_MEAS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_RUNTIMEMEASINIT_001 

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void ACDC_v_RuntimeMeasInit(void)
{
  uint32 i;
  /* Init global FCT runtime measurement array */
  for (i = 0u; i < ACDC_RTA_NOF_CHECKPOINTS; i++)
  {
    ACDC_p_ModRuntimeInfo()->uACDCRuntime[i]   = 0u;
  }
}
#endif /* FCT_CFG_RUNTIME_MEAS */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/*************************************************************************************************************************
  Functionname:         ACDC_v_SetCompState                                                                           */ /*!

  @brief                Sets the ACDC Comp State

  @description          Function follows the subsequent steps:
                        @startuml ACDC_v_SetCompState_activity.png
                        start
                          if(Pointers are valid?) then (Yes)
                            if(ACDCCompState is\n**COMP_STATE_NOT_INITIALIZED**) then (Yes)
                              note left:These conditions check whether\nACDC has degraded its state\nduring the component call.
                              
                              if(FCT Op Mode was Running?) then (Yes)
                                :1}
                                :CompState = Temporary Error
                                ErrorCode = Unknown
                                AlgoQuality = Buffered Qualifier;
                              else(No)
                                :2}
                                :CompState = Running
                                ErrorCode = No Error
                                AlgoQuality = Ok;
                              endif
                            elseif(ACDCCompState is\n**COMP_STATE_RUNNING**) then (Yes)
                              :3}
                              :CompState = Running
                              ErrorCode = No Error
                              AlgoQuality = Ok;
                            elseif(ACDCCompState is\n**COMP_STATE_NOT_RUNNING**) then (Yes)
                              if(FCT Op Mode was Running?) then (Yes)
                                :4}
                                :CompState = Running
                                ErrorCode = No Error
                                AlgoQuality = Buffered Qualifier;
                              else(No)
                                :5}
                                :CompState = Temporary Error
                                ErrorCode = Unknown
                                AlgoQuality = Buffered Qualifier;
                              endif
                            else (No)
                               :6}
                               :CompState = Temporary Error
                                ErrorCode = Unknown
                                AlgoQuality = Buffered Qualifier;
                            endif
                          else(No)
                            :7}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in,out]        pSenCompState :     Determined Comp state.
  @param[in]            ScheduledOpMode :   Provided Operation mode (from FCT to the ACDC component).
  @param[in]            BufferedQualifier : Provided Algo quality buffer.

  @glob_in              @ref ACDC_p_GetFrameData \n
                        @ref ACDC_e_GetSubCompState
  @glob_out             None

  @c_switch_part        @ref COMP_STATE_INTFVER \n
                        @ref _MSC_VER
  @c_switch_full        @ref ACDC_CFG_FRAME \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Christian Obst
*************************************************************************************************************************/
/* PRQA S 1330 1 # Date:2020-06-02, Reviewer: Praveen Annareddy , Reason: defensive programming with parameters and No side effects*/
static void ACDC_v_SetCompState(    AlgoCompState_t       * const pACDCCompState, 
                                      FCT_OP_MODE_t const         ScheduledOpMode, 
                                GenAlgoQualifiers_t const         BufferedQualifier)
{

#if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) )
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: REMOVE REDEFINITION (obviously the RTE is updated)!")// PRQA S 3116
#endif /* #if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) ) */
#ifndef MFC_VERSION_INFO_LENGTH
#define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
#endif  /* #ifndef MFC_VERSION_INFO_LENGTH */
  
  

  /* The define MFC_VERSION_INFO_LENGTH is to be renamed. The name has to be more generalized regarding the used technology */
#if COMP_STATE_INTFVER > 3
/*PRQA S 1844,1842,3493 1*/ /* date: 2019-06-04, reviewer: Praveen Annareddy, reason: defensive programming with parameters*/
  uint8 uiAlgoVersionInfoFillSize = (uint8)MIN(sizeof(VERSION_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));
#else
///@cond Doxygen_Suppress
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
///@endcond
#endif /* #if COMP_STATE_INTFVER > 3 */
   
  if (pACDCCompState != NULL)
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    /*PRQA S 0315,1495 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
    (void)memcpy(pACDCCompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pACDCCompState->uiAlgoVersionNumber = ACDC_p_GetFrameData()->Versions.ACDCSwVersion;
#if COMP_STATE_INTFVER > 2u
    pACDCCompState->uiApplicationNumber = 0u;
    pACDCCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pACDCCompState->ApplicationNumber = 0u;
    pACDCCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif /* #if COMP_STATE_INTFVER > 2u */
    
    switch (ACDC_e_GetSubCompState(ACDC_SUB_COMP_ACDC))
    {
    case COMP_STATE_NOT_INITIALIZED:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pACDCCompState->eCompState = COMP_STATE_RUNNING;
        pACDCCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pACDCCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        pACDCCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pACDCCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pACDCCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pACDCCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case COMP_STATE_RUNNING:
      /*everything's fine*/
      pACDCCompState->eCompState = COMP_STATE_RUNNING;
      pACDCCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pACDCCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case COMP_STATE_NOT_RUNNING:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pACDCCompState->eCompState = COMP_STATE_RUNNING;
        pACDCCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pACDCCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*internal recoverable error*/
        pACDCCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pACDCCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pACDCCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pACDCCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case COMP_STATE_TEMPORARY_ERROR:
      /*triggered with input interface errors*/
    default:
      pACDCCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
      pACDCCompState->eErrorCode = COMP_ERROR_UNKNOWN;
      if (BufferedQualifier != ALGO_QUAL_OK)
      {
        pACDCCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
      }
      else
      {
        pACDCCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
      }
      break;
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */


#if (FCT_CFG_USE_DEM)
/*************************************************************************************************************************
  Functionname:         ACDC_v_SetDem                                                                           */ /*!

  @brief                Sets a DEM Event with the given ID and the given Status.

  @description          Sets a DEM event by calling the function pfDem_SetEventStatus that is provided 
                        by the Service Functions

  @return               void

  @param[in]            Dem_EventId :     The ID of the triggered DEM EVENT.
  @param[in]            Dem_EventStatus : The DEM status that shall be set.

  @glob_in              @ref ACDC_p_GetServiceFunctionsList
  @glob_out             @ref ACDC_p_GetServiceFunctionsList

  @c_switch_part        None
  @c_switch_full        @ref FCT_CFG_USE_DEM \n
                        @ref ACDC_CFG_FRAME

  @pre                  pFCTSenServiceFuncts connected to input service ports
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Christian Obst
*************************************************************************************************************************/
static void ACDC_v_SetDem(    AS_t_Dem_EventIDType const Dem_EventId, 
                          AS_t_Dem_EventStatusType const Dem_EventStatus)
{
  if ((ACDC_p_GetServiceFunctionsList()->pfDem_SetEventStatus != NULL))
  {
    ACDC_p_GetServiceFunctionsList()->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif /*FCT_CFG_USE_DEM*/

/*************************************************************************************************************************
  Functionname:         ACDC_v_MergeDeleteObj                                                                            */ /*!

  @brief                Handles the merging of several objects to one object that takes place in EM for the ACDC component.

  @description          The merge status of an object is indicated by the @ref EM_t_GenObjSplitMergeState of an object.
                        If its status is @ref EM_GEN_OBJECT_SM_STATE_MERGE, a merge operation took place in EM. \n
                        The uiMergeID indicates the type of merging:
                        - Merge ID = Object ID : Another object was merged into the object that used to have the Object ID.
                          This variation is handled by a call of the function @ref CDMergeDeleteObjectsSameFCTID.
                        - Merge ID != Object ID : The Object has been merged into an Object with the Merge ID.
                          This variation is handled by a call of the function @ref CDMergeObjects.
                        @startuml ACDC_v_MergeDeleteObj_activity.png
                        start
                          partition "Execute for each object" {
                            if(Object is "NEW" AND\nWas not merged?) then (Yes)
                              :1}
                              #Orange:Delete the ACDC internal object:
                              <b>CDDeleteObject</b> >
                            else(No)
                              :2}
                            endif
                          }
                          partition "Execute for each object" {
                            if (Objects MergeID is Objects ID?\nOR Objects merge ID is invalid?) then (Yes)
                              if(Objects MergeID is valid?) then (Yes)
                                :3}
                                #Orange:Merge the object into the object 
                                at the position "MergeID"
                                <b>CDMergeObjects</b> >
                              else(No)
                                :4}
                              endif
                              #Orange:Check if object is new or deleted:
                              <b>ACDC_b_GetEMGenObjIsDeleted</b>
                              <b>ACDC_b_GetEMGenObjIsNew</b> >

                              if(Check passed?) then (Yes)
                                :5}
                                #Orange:Delete the object also in ACDC:
                                <b>CDDeleteObject</b> >
                              else(No)
                                :6}
                              endif

                            else (No)
                              :7}
                              #Orange:Merge old object into a new 
                              object at the same position 
                              as the old object:
                              <b>CDMergeDeleteObjectsSameFCTID</b> >
                            endif
                          }

                        stop
                        @enduml
  @return               void

  @param[in]            pObjList : Pointer to a list containing all objects.

  @glob_in              @ref ACDC_b_GetEMGenObjIsNew \n
                        @ref ACDC_b_GetEMGenObjIsDeleted
  @glob_out             None

  @c_switch_part        @ref ACDC_CFG_CD
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_MERGEDELETEOBJ_001 \n
                        @ref TEST_ACDC_V_MERGEDELETEOBJ_002

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void ACDC_v_MergeDeleteObj(EM_t_GenObjectList const * const pObjList)
{
#if (ACDC_CFG_CD)
  ObjNumber_t iObj;
  /* First: Delete the FCT-content of "NEW"-objects which have no merge information from the last cycle (eSplitMergeState = EM_GEN_OBJECT_SM_STATE_NONE). 
      Necessary, if another object has a merge reference to a "NEW" object. */
  for (iObj = (ObjNumber_t)0; iObj < EM_N_OBJECTS; iObj++)
  {
    if( (pObjList->aObject[iObj].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_NEW) &&
        (pObjList->aObject[iObj].General.eSplitMergeState == EM_GEN_OBJECT_SM_STATE_NONE)
      )
    {
      CDDeleteObject (iObj);
    }
  }

   /* Second: Do the "merge" operation (copy information of the last cycle if necessary) */
  for (iObj = (ObjNumber_t)0; iObj < EM_N_OBJECTS; iObj++)
  {
    const EM_t_GenObject * pCurObj = &(pObjList->aObject[iObj]);
    const uint8 uiObjMergeFlag = pCurObj->General.uiMergeID;
    /* If the object's merge-split ID is a valid ID (range between 0 and EM_N_OBJECTS -1), then a merge 
    operation took place in the current EM cycle. If the merge ID is not equal to the object ID iObj, 
    the object was merged into another object. If the merge ID is equal to the object ID iObj, the object was merged into a new object on the same 
    FCT-list position and a special handing is necessary. 
    In case of no merge or a merge to a unknown object, the merge ID is EM_GEN_OBJECT_SM_ID_NONE.
    Both cases are handled as if no merge took place since no information about the object is available in FCT. */
    /* Behavior as on the old version: If no merge or a merge into an unknown object (uiMergeID >= EM_N_OBJECTS) or "normal" merge (valid ID in uiMergeID and if uiMergeID != ID of object),
        First the merge takes place and then the old FCT object can be deleted */

      /* Merge, if valid ID in uiMergeID and if uiSplitMergeID != ID of object */
    if ( (uiObjMergeFlag >= (uint8) EM_N_OBJECTS) || (uiObjMergeFlag != (uint8)iObj) )
    {
        /* For safeties sake verify that the merge flag is valid */
      if (uiObjMergeFlag < (uint8) EM_N_OBJECTS)
      {
        /* Cast is save as validity is checked */
        const ObjNumber_t iObjToKeep = (ObjNumber_t) uiObjMergeFlag;
        CDMergeObjects(iObjToKeep, iObj);
      }
      /* If the object is set to deleted, then delete any information associated */
      if(    (ACDC_b_GetEMGenObjIsDeleted((ObjNumber_t)iObj) != b_FALSE) 
          || (ACDC_b_GetEMGenObjIsNew((ObjNumber_t)iObj)     != b_FALSE) )
      {
        CDDeleteObject (iObj);
      }
    }
    else
    {
      /* The old object is merged into the new object at the same position in the FCT-list 
        ->  First, the information which is copied during the merge, has to be stored locally. 
            Than, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
      CDMergeDeleteObjectsSameFCTID(iObj);
    }
  }
#else
  _PARAM_UNUSED(pObjList);
#endif /* #if (ACDC_CFG_CD) */
}

/*************************************************************************************************************************
  Functionname:         ACDC_e_AssignStaticMemoryToAccessData                                                        */ /*!

  @brief                Assign pointers to ACDC process memory

  @description          Checks for a valid pointer to the process memory. Afterwards sets the pointers to define four storage
                        areas inside the memory section.
                        Returns GDB_ERROR_POINTER_NULL in case a null pointer is detected.

  @return               eGDBError_t : Error type to communicate if pointer to proc mem is valid

  @param[in]            p_ACDCProcMem : Container of all memory types

  @glob_in              None
  @glob_out             @ref ACDC_p_GetAccessData

  @c_switch_part        @ref USE_ACDCWRAPPER_SIMU\n
                        @ref USE_ACDCWRAPPER_STACK
                        @ref ACDC_SIMU\n
                        @ref USE_ACDCWRAPPER_INTRAMEAS\n
                        @ref USE_ACDCWRAPPER_INTRA\n
                        @ref USE_ACDCWRAPPER_INTERMEAS\n
                        @ref USE_ACDCWRAPPER_INTER
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 If this function did not successfully finish there is no global memory available. \n
                        ACDC cannot run.

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_E_ASSIGNSTATICMEMORYTOACCESSDATA_001 \n
                        @ref TEST_ACDC_E_ASSIGNSTATICMEMORYTOACCESSDATA_002 \n
						@ref TEST_ACDC_E_ASSIGNSTATICMEMORYTOACCESSDATA_003 \n
						@ref TEST_ACDC_E_ASSIGNSTATICMEMORYTOACCESSDATA_004 \n
                        @ref TEST_ACDC_E_ASSIGNSTATICMEMORYTOACCESSDATA_005 \n
						@ref TEST_ACDC_E_ASSIGNSTATICMEMORYTOACCESSDATA_006

  @traceability         Design Decision

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t ACDC_e_AssignStaticMemoryToAccessData( ACDC_ProcMem_t const * const p_ACDCProcMem
#if USE_ACDCWRAPPER_STACK
                                                        , ACDC_DataWrapperStack_t * const pACDCStackData
#endif /* #if USE_ACDCWRAPPER_STACK */
  )
{
  eGDBError_t eRetError = GDB_ERROR_NONE;
  
  /* PRQA S 3205,1271 USAGE */
  /* check of static memory sizes during compilation, no runtime effects */
#if (USE_ACDCWRAPPER_INTER)
  /* Compile error occurs if size is to small */
  GA_assert(sizeof(ACDC_DataWrapperInter_t)     <= GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE);
#endif /* #if (USE_ACDCWRAPPER_INTER) */
#if (USE_ACDCWRAPPER_INTERMEAS)
  /* Compile error occurs if size is to small */
  GA_assert(sizeof(ACDC_DataWrapperInterMeas_t) <= GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE_MEAS);
#endif /* #if (USE_ACDCWRAPPER_INTERMEAS) */
#if (USE_ACDCWRAPPER_INTRA)
  /* Compile error occurs if size is to small */
  GA_assert(sizeof(ACDC_DataWrapperIntra_t)     <= GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE     );
#endif /* #if (USE_ACDCWRAPPER_INTRA) */
#if (USE_ACDCWRAPPER_INTRAMEAS)
  /* Compile error occurs if size is to small */
  GA_assert(sizeof(ACDC_DataWrapperIntraMeas_t) <= GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS);
#endif /* #if (USE_ACDCWRAPPER_INTRAMEAS) */
#if (USE_ACDCWRAPPER_STACK)
  /* Compile error occurs if size is to small */
  GA_assert(sizeof(ACDC_DataWrapperStack_t)     <= GA_ACDC_SIZE_MEM_DATA_STACK           );
#endif /* #if (USE_ACDCWRAPPER_STACK) */
#ifdef ACDC_SIMU
#if (USE_ACDCWRAPPER_SIMU)
  /* Compile error occurs if size is to small */
  GA_assert(sizeof(ACDC_DataWrapperSimu_t)      <= GA_ACDC_SIZE_MEM_DATA_SIMU            );
#endif /* #if (USE_ACDCWRAPPER_SIMU) */
#endif /* #ifdef ACDC_SIMU */
  
  /* PRQA L:USAGE */

  /* Set AccessData structure to 0 */
  /*PRQA S 3441 GETTER*//* 2018-11-15, reviewer: Oliver Brand, get function without sideffects*/
  /*PRQA S 0315 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  (void) memset (ACDC_p_ModAccessData(), 0, sizeof(ACDCAccessData_t));
  /*PRQA L:GETTER*/

  /* Check validity of memory pointers */
  if (    (p_ACDCProcMem                     != NULL)
       && (p_ACDCProcMem->pMemInterCycle     != NULL)
       && (p_ACDCProcMem->pMemInterCycleMeas != NULL)
       && (p_ACDCProcMem->pMemIntraCycle     != NULL)
       && (p_ACDCProcMem->pMemIntraCycleMeas != NULL)
#ifdef ACDC_SIMU
       && (p_ACDCProcMem->pMemSimu           != NULL)
#endif /* #ifdef ACDC_SIMU */
#if USE_ACDCWRAPPER_STACK
       && (pACDCStackData                    != NULL)
#endif /* #if USE_ACDCWRAPPER_STACK */
       )
  {
    /* pointer conversion */
  /* PRQA S 0314 16*//* date: 2019-05-14, reviewer:C. Schnurr, Internal Data types used for compatibility over different architectures */
#if (USE_ACDCWRAPPER_INTER)
    ACDC_p_ModWorkingData()->pInterCycle     = (ACDC_DataWrapperInter_t     *)((void *)(p_ACDCProcMem->pMemInterCycle)    );
#endif /* #if (USE_ACDCWRAPPER_INTER) */
#if (USE_ACDCWRAPPER_INTERMEAS)
    ACDC_p_ModWorkingData()->pInterCycleMeas = (ACDC_DataWrapperInterMeas_t *)((void *)(p_ACDCProcMem->pMemInterCycleMeas));
#endif /* #if (USE_ACDCWRAPPER_INTERMEAS) */
#if (USE_ACDCWRAPPER_INTRA)
    ACDC_p_ModWorkingData()->pIntraCycle     = (ACDC_DataWrapperIntra_t     *)((void *)(p_ACDCProcMem->pMemIntraCycle)    );
#endif /* #if (USE_ACDCWRAPPER_INTRA) */
#if (USE_ACDCWRAPPER_INTRAMEAS)
    ACDC_p_ModWorkingData()->pIntraCycleMeas = (ACDC_DataWrapperIntraMeas_t *)((void *)(p_ACDCProcMem->pMemIntraCycleMeas));
#endif /* #if (USE_ACDCWRAPPER_INTRAMEAS) */
#ifdef ACDC_SIMU
#if (USE_ACDCWRAPPER_SIMU)
    ACDC_p_ModWorkingData()->pSimuData       = (ACDC_DataWrapperSimu_t      *)((void *)(p_ACDCProcMem->pMemSimu));
#endif /* #if (USE_ACDCWRAPPER_SIMU) */
#endif /* #ifdef ACDC_SIMU */
#if USE_ACDCWRAPPER_STACK
    /* No cast is needed, because this structure is a internal ACDC structure with a known type. */
    ACDC_p_ModWorkingData()->pStackData      = pACDCStackData;
#endif /* #if USE_ACDCWRAPPER_STACK */
  }
  else
  {
    eRetError = GDB_ERROR_POINTER_NULL;
  }

  return eRetError;
}


/*************************************************************************************************************************
  Functionname:         ACDC_v_AssignAccessPointers                                                                  */ /*!

  @brief                Takes the ReqPort, ProPort and Service pointers and copies them to a globally available access 
                        data structure.

  @description          Assigns the Port pointers to the corresponding structures in the access data. After this 
                        point any access to a port should be done via the access data. This assures that the pointers 
                        to the Require / the provide port list are not NULL.

  @return               void
  
  @param[in]            p_ACDCRequirePorts : Request port
  @param[in]            p_ACDCProvidePorts : Request port
  @param[in]            p_ServiceFuncts : Request port

  @glob_in              None
  @glob_out             @ref ACDC_p_ModAccessData

  @c_switch_part        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None 
  @post                 Input and Output structures of the Access data are filled.

  @testmethod           @ref TEST_ACDC_V_ASSIGNACCESSPOINTERS_001 \n
                        @ref TEST_ACDC_V_ASSIGNACCESSPOINTERS_002

  @traceability         Design Decision

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
/*PRQA S 3673 6*/ /* date: 2018-07-25, reviewer: Andreas Kramer, reason: The pointer assigned here needs write access. */
static void ACDC_v_AssignAccessPointers( reqACDCPrtList_t   const * const p_ACDCRequirePorts
                                        ,provACDCPrtList_t        * const p_ACDCProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                        ,AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif /* #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */
                                        )
{

  if (p_ACDCRequirePorts != NULL)
  {
    /* Assign request ports to input */
    ACDC_p_ModAccessData()->Input.ReqPorts        = *p_ACDCRequirePorts;
  }

  if (p_ACDCProvidePorts != NULL)
  {
    /* Assign provide ports to output */
    ACDC_p_ModAccessData()->Output.ProPorts       = *p_ACDCProvidePorts;
  }

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  if (p_ServiceFuncts != NULL)
  {
    ACDC_p_ModAccessData()->Input.ServiceFuncts   = *p_ServiceFuncts;
  }
#endif /* #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */
}


/*************************************************************************************************************************
  Functionname:         ACDC_v_InitInterCycleData                                                                    */ /*!

  @brief                Initialize the inter cycle data if ACDC is called in INIT.

  @description          Keep special values to guarantee the function and avoid deadlocks.
                        @startuml ACDC_v_InitInterCycleData_activity.png
                        start
                          :Get the OpMode provided by FCT 
                          via the SenCtrl Data port;
                          if(OpMode is **FCT_MOD_INIT**\nOR ACDC has not been initialised yet?) then (Yes)
                            :1}
                            :Store Information that shall be kept;
                            note left: e.g. Cycle Counter,...
                            :Reset the entire inter cycle memory;
                            :Write the previously stored values back 
                            to the inter cycle memory;
                          else (No)
                            :2}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            p_ACDCProcMem :      Pointers to the memory provided by SW

  @glob_in              @ref ACDC_p_GetReqPortList
                        @ref ACDC_p_GetFrameData
  @glob_out             @ref ACDC_p_ModFrameData

  @c_switch_part        @ref ACDC_SIMU\n
                        @ref FCT_CFG_USE_BASECTRLDATA\n
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None 
  @post                 None 

  @remark               All Ports that are used here need to be checked explicitly for a possible Null pointer error!

  @todo                 Add the port handler structure here.

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_ACDC_V_INITINTERCYCLEDATA_001 \n
                        @ref TEST_ACDC_V_INITINTERCYCLEDATA_002 \n
						@ref TEST_ACDC_V_INITINTERCYCLEDATA_003 \n 
						@ref TEST_ACDC_V_INITINTERCYCLEDATA_004 \n
						@ref TEST_ACDC_V_INITINTERCYCLEDATA_005 

  @traceability         Design Decision

*************************************************************************************************************************/
static void ACDC_v_InitInterCycleData(ACDC_ProcMem_t const * const p_ACDCProcMem)
{
  /*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
  FCT_OP_MODE_t eOpMode;

  /* Check for NULL pointers */
  if (ACDC_p_GetReqPortList()->pSenCtrlData != NULL)
  {
#if (FCT_CFG_USE_BASECTRLDATA)
    eOpMode = (ACDC_p_GetReqPortList()->pSenCtrlData->eOpMode == BASE_OM_RUN)? FCT_MOD_RUNNING : FCT_MOD_INIT;
#else
    eOpMode = ACDC_p_GetReqPortList()->pSenCtrlData->OpMode;
#endif /* #if (FCT_CFG_USE_BASECTRLDATA) */
  }
  else
  {
    /* Set the operation mode to init if an NULL pointer is received. */
    eOpMode = FCT_MOD_INIT;
  }

  /* Init the complete internal memory if ACDC is called in init mode or if it was not initialized yet*/
  if (    (eOpMode                                  == FCT_MOD_INIT   )
       || (ACDC_p_GetFrameData()->bIsInitialized    == b_FALSE             ) )
  {
    /* Safe the frame structure to keep specific values after the initialization of the internal memory */
    sint32                i;
    ACDCPortHandlerList_t sPortHandlerList;
    ACDCFrame_t           sACDCFrameTemp;

    sPortHandlerList     = *ACDC_p_GetPortHandlerList();
    sACDCFrameTemp       = *ACDC_p_GetFrameData();

    /*PRQA S 0315 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
    (void) memset (p_ACDCProcMem->pMemInterCycle,     0, sizeof(GA_ACDC_Mem_DataInterCycle)    );
    (void) memset (p_ACDCProcMem->pMemInterCycleMeas, 0, sizeof(GA_ACDC_Mem_DataInterCycleMeas));

    /* The MeasCycle monitor has to be preserved */
    /*PRQA S 3494,3493,4548 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    for (i = ((sint32)ACDC_NOF_REQ_PORTS-1); i>=0; i--)
    {
      ACDC_p_ModPortHandlerList()->ReqPortHandler[i].MeasCycleMonitor = sPortHandlerList.ReqPortHandler[i].MeasCycleMonitor;
    }

    /* The cycle counter should be increased at every call for debug purposes */
    ACDC_p_ModFrameData()->uiCycleCounter = sACDCFrameTemp.uiCycleCounter;
    /* The internal init state should be kept after it was set once. */
    ACDC_p_ModFrameData()->bIsInitialized = sACDCFrameTemp.bIsInitialized;

#ifdef ACDC_SIMU
    (void) memset (p_ACDCProcMem->pMemSimu,           0, sizeof(GA_ACDC_Mem_DataSimu)          );
#endif /* #ifdef ACDC_SIMU */
  }
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_Exec                                                                              */ /*!

  @brief                Main function of the ACDC Component. Calls all subcomponents, handles pointer checks and operation modes.

  @description          The main ACDC Routine is called by the main FCT function @ref FCTSen_Exec. It executes 
                        pointer checks for the require and provide ports and calls all ACDC subcomponents. \n
                        .
                        @startuml ACDC_v_Exec_activity.png
                        start
                          #Orange:Assign the Pointers to the working memory:
                          <b>ACDC_e_AssignStaticMemoryPtrs</b> >
                          if(Pointer Error?) then (No)
                          #Orange:Check and set up all ports,
                          fill port handler structure:
                          <b>ACDC_v_ProcessPorts</b> >
                          if(ACDC State is **Error**?) then (No)
                            :1}
                            note left
                              In this case all provide and require 
                              port pointers are valid. No more 
                              pointer checks are required.
                            end note
                            #Orange: Execute ACDC PreProcessing:
                            <b>ACDC_v_PreProcessing</b> >
partition #LightBlue **ACDC_CFG_ESPM** {
                            #Orange:Call of the ESPM subcomponent:
                            <b>ESPM_v_DegradationProcess</b> >
}
partition #LightBlue **ACDC_CFG_CD** {
                            #Orange:Call of the CD subcomponent:
                            <b>CDProcess</b> >
}
                            #Orange:Execute acdc functions after the 
                            call of the subcomponents:
                            <b>ACDC_v_PostProcessing</b> >

partition #LightBlue **FCT_CFG_USE_ALGOCOMPSTATE** {
                            #Orange: Set the EBA Component state:
                            <b>ACDC_v_SetCompState</b> >
}
                          else(Yes)
                            :2}
                            #Orange:Initialize all ACDC specific data:
                            <b>ACDC_v_AlgoInit</b> >
partition #LightBlue **ACDC_CFG_AIP** {
                            #Orange:Initialize the ACDC object list:
                            <b>AIP_v_InitObjectList</b> >
}

partition #LightBlue **FCT_CFG_USE_ALGOCOMPSTATE** {
                            #Orange:Set the EBA Component state:
                            <b>ACDC_v_SetCompState</b> >
}
                          endif
                          #Orange:Fill the signal headers of the provide ports:
                          <b>ACDC_v_FillProPortHeaders</b> >
partition #LightBlue **FCT_MEASUREMENT** {
                          #Orange:Freeze information for mts
                          <b>ACDC_v_ProcessMeasFreeze</b> >
}
                          else(Yes)
                            :3}
                            :Set Assert & Call Error Routine;
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            p_ACDCRequirePorts :      Require ports, provided by the RTE.
  @param[in,out]        p_ACDCProvidePorts :      Provide ports, provided towards the RTE.
  @param[in]            p_ACDCProcMem :           Pointer to different memory types used in ACDC
  @param[in]            p_ServiceFuncts :         Service function pointers provided by the RTE.

  @glob_in              @ref ACDC_p_GetProPortList  \n
                        @ref ACDC_p_GetReqPortList  \n
                        @ref ACDC_p_GetServiceFunctionsList \n
                        @ref ACDC_p_GetPortHandlerList *
                        @ref ACDC_p_GetFrameData 
  @glob_out             @ref ACDC_p_ModProPortList \n
                        @ref ACDC_p_ModPortHandlerList
                        @ref ACDC_p_ModFrameData 

  @c_switch_part        @ref FCT_MEASUREMENT\n
  @c_switch_part        @ref FCT_CFG_USE_ACDC_INTERNAL_MEMORY
  @c_switch_part        @ref USE_ACDCWRAPPER_STACK
  @c_switch_part        @ref ACDC_CFG_AIP
                        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_ESPM\n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START\n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE\n
                        @ref FCT_CFG_RUNTIME_MEAS\n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_EXEC_001 \n
                        @ref TEST_ACDC_V_EXEC_002 \n
						@ref TEST_ACDC_V_EXEC_003 \n
						@ref TEST_ACDC_V_EXEC_004 \n
						@ref TEST_ACDC_V_EXEC_005

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
/* PRQA S 3673 8 */ /* date: 2017-10-25, reviewer: Wenting Huang, reason: when FCT_CFG_USE_ALGOCOMPSTATE is SWITCH_ON, p_EBAProvidePorts cannot be const */
extern void ACDC_v_Exec( reqACDCPrtList_t   const * const p_ACDCRequirePorts 
                        ,provACDCPrtList_t        * const p_ACDCProvidePorts
#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
                        ,ACDC_ProcMem_t     const * const p_ACDCProcMem
#endif /* #if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                        ,AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif /* #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */
                         )
{
  eGDBError_t eStaticMemoryError;
#if USE_ACDCWRAPPER_STACK
  ACDC_DataWrapperStack_t ACDCStackData = {0};
#endif /* #if USE_ACDCWRAPPER_STACK */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif  /* #if (FCT_CFG_USE_ALGOCOMPSTATE) */
#if FCT_CFG_USE_ACDC_INTERNAL_MEMORY
  /* ACDC process memory */
  ACDC_ProcMem_t               ACDCProcMem   = {0};
  ACDC_ProcMem_t const * const p_ACDCProcMem = &ACDCProcMem;
  /* Assign memory pointer */
  ACDCProcMem.pMemInterCycle     = &ACDCInter;
  ACDCProcMem.pMemInterCycleMeas = &ACDCInterMeas;
  ACDCProcMem.pMemIntraCycle     = &ACDCIntra;
  ACDCProcMem.pMemIntraCycleMeas = &ACDCIntraMeas;
#ifdef ACDC_SIMU
  ACDCProcMem.pMemSimu           = &ACDCSimuData;
#endif /* #ifdef ACDC_SIMU */

  /* Reset the structure to guarantee the non-persistent behavior of the memory */
  (void) memset (&ACDCIntraMeas, 0, sizeof(GA_ACDC_Mem_DataIntraCycleMeas));
  (void) memset (&ACDCIntra,     0, sizeof(GA_ACDC_Mem_DataIntraCycle)    );
#endif /* #if FCT_CFG_USE_ACDC_INTERNAL_MEMORY */

  /************************************************************************/
  /* Assign the input memory pointer to ACDC structures                   */
  /************************************************************************/
  eStaticMemoryError = ACDC_e_AssignStaticMemoryToAccessData(p_ACDCProcMem
#if USE_ACDCWRAPPER_STACK
                                                            ,&ACDCStackData
#endif /* #if USE_ACDCWRAPPER_STACK */
    );

  /* Only continue if no error occurred while assigning the static data */
  if (eStaticMemoryError == GDB_ERROR_NONE)
  {
  
    /************************************************************************/
    /*                 Copy ports structure to AccessData                   */
    /************************************************************************/
    ACDC_v_AssignAccessPointers(p_ACDCRequirePorts,
                                p_ACDCProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                               ,p_ServiceFuncts
#endif /* #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */
                               );

    /* Init the inter cycle data if all conditions are fulfilled */
    ACDC_v_InitInterCycleData(p_ACDCProcMem);

#if (FCT_CFG_RUNTIME_MEAS)
    ACDC_v_RuntimeMeasInit();
#endif /* #if (FCT_CFG_RUNTIME_MEAS) */
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_PROCESS, 0);
    
    /************************************************************************/
    /*                  Process request and provide ports                   */
    /************************************************************************/
    /*PRQA S 3441 GETTER*//* 2018-11-15, reviewer: Oliver Brand, get function without sideffects*/
    ACDC_v_ProcessPorts(ACDC_p_GetReqPortList()
                       ,ACDC_p_ModProPortList()
                       ,ACDC_p_ModPortHandlerList()
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                       ,ACDC_p_GetServiceFunctionsList()
#endif /* #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                       ,&AlgoErrorBuffer
#endif /* #if (FCT_CFG_USE_ALGOCOMPSTATE) */
                       );
    /*PRQA L:GETTER*/ 
    if (    (ACDC_e_GetSubCompState(ACDC_SUB_COMP_ACDC)== COMP_STATE_NOT_INITIALIZED)
         || (ACDC_e_GetSubCompState(ACDC_SUB_COMP_ACDC)== COMP_STATE_RUNNING        ) )
    {
      /************************************************************************/
      /*                      Start of NON error path                         */
      /************************************************************************/


      /* Send RTA-Start Event for PreProcessing runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_PRE_PROCESS, 0);
      /************************************************************************/
      /*                          Call PreProcessing                          */
      /************************************************************************/
      ACDC_v_PreProcessing(ACDC_p_GetReqPortList());
      /* Send RTA-End Event for PreProcessing runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_PRE_PROCESS, 0);


#if (ACDC_CFG_AIP)
      /* Send RTA-Start Event for ACDC input processing runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_AIP, 0);
      /************************************************************************/
      /*            Call the ACDC Input processing subcomponent               */
      /************************************************************************/
      AIP_v_Process();
      /* Send RTA-End Event for ACDC input processing runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_AIP, 0);
#endif /* #if(ACDC_CFG_AIP) */

#if (ACDC_CFG_ESPM)
      /* Send RTA-Start Event for EBA Safety Performance Monitoring runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_ESPM, 0);
      /************************************************************************/
      /*       Call EBA Safety Performance Monitoring (ESPM) subcomponent     */
      /************************************************************************/
      ESPM_v_DegradationProcess(&(ACDC_p_ModProPortList()->pHypotheses->Degradation), ACDC_p_ModProPortList()->pErrorOut);
      /* Send RTA-End Event for EBA Safety Performance Monitoring runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_ESPM, 0);
#endif /* (ACDC_CFG_ESPM) */

#if (ACDC_CFG_CD)
      /* Send RTA-Start Event for Collision Detection runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD, 0);
      /************************************************************************/
      /*             Call Collision Detection (CD) subcomponent               */
      /************************************************************************/
      CDProcess();
      /* Send RTA-End Event for Collision Detection runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD, 0);
#endif  /* (ACDC_CFG_CD) */

      /* Send RTA-Start Event for ACDC post process runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_POST_PROCESS, 0);
      /************************************************************************/
      /*                         Call PostProcessing                          */
      /************************************************************************/
      ACDC_v_PostProcessing();
      /* Send RTA-End Event for Post processing runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_POST_PROCESS, 0);
      
      /* Collect selected data for debug freezes */
      ACDC_v_FillDebugData();
      
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /************************************************************************/
      /*                         Set component state                          */
      /************************************************************************/
      ACDC_v_SetCompState (ACDC_p_ModProPortList()->pSenCompState, ACDC_p_GetFrameData()->eOpMode, AlgoErrorBuffer);
#endif /* #if (FCT_CFG_USE_ALGOCOMPSTATE) */

      ACDC_p_ModFrameData()->bIsInitialized = b_TRUE;
    }
    else
    {
      /************************************************************************/
      /*                        Start of error path                           */
      /************************************************************************/



      /************************************************************************/
      /*                   Call initialization of ACDC data                   */
      /************************************************************************/
      ACDC_v_AlgoInit ();
#if (ACDC_CFG_AIP)
      AIP_v_InitObjectList ();
#endif /* #if (ACDC_CFG_AIP) */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /* ERROR path! need to check existence of pointers */
      if (ACDC_p_GetProPortList()->pSenCompState != NULL) 
      {
        /************************************************************************/
        /*                         Set component state                          */
        /************************************************************************/
        if ((ACDC_p_GetReqPortList()->pSenCtrlData != NULL) )
        {
          ACDC_v_SetCompState (ACDC_p_ModProPortList()->pSenCompState, ACDC_p_GetFrameData()->eOpMode, AlgoErrorBuffer);
        }
        else
        {
          /* Assuming running status from scheduler ==> pointer error, Frame-mode is INIT ==> Input error is set */
          ACDC_v_SetCompState (ACDC_p_ModProPortList()->pSenCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
        }
      }
#endif /* #if (FCT_CFG_USE_ALGOCOMPSTATE) */
    }

    /*PRQA S 3441 GETTER*//* 2018-11-15, reviewer: Oliver Brand, get function without sideffects*/
    ACDC_v_FillProPortHeaders(ACDC_p_ModPortHandlerList());
    /*PRQA L:GETTER*/

#if (FCT_MEASUREMENT)
    /* Send RTA-Start Event for Process Measfreeze runtime */
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart, ACDC_RTA_PROCESSFREEZE, 0);
    /************************************************************************/
    /*                     Call MeasFreeze processing                       */
    /************************************************************************/
    /* Freeze all ports */
    ACDC_v_FreezePorts(ACDC_p_GetPortHandlerList());

    /* Freeze all working data */
    ACDC_v_FreezeWorkingData(ACDC_p_GetWorkingData());

    /* Send RTA-End Event for Process Measfreeze runtime */
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd, ACDC_RTA_PROCESSFREEZE, 0);
#endif /* FCT_MEASUREMENT */
   
    /* Sends RTA-End Event for whole procedure runtime */
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_PROCESS, 0);

  }
  else
  {
    ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  }

}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:         ACDC_v_FillDebugData                                                                         */ /*!

  @brief                Fill data of the relevant hypothesis to the debug structure.

  @description          Find the most relevant object and save position, movement,
                        geometry, static evasion data, evasion data, and TTX data
                        to ACDC and CD debug structures
                        @startuml ACDC_v_FillDebugData.png
                        start
                          : Find most relevant hypothesis and corresponding object;
                          note right
                            If two hypotheses have the same relevance value the first is chosen
                          end note
                          if( most relevant object exists ) then (Yes)
                            : save object data to acdc and cd debug structs;
                          else(No)
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            void : 

  @glob_in              @ref ACDC_p_GetCurrentIntHypotheses
  @glob_in              @ref ACDC_p_GetCurrentIntHypothesis
  @glob_in              @ref ACDC_p_GetObjPositions
  @glob_in              @ref ACDC_p_GetObjMovement
  @glob_in              @ref ACDC_p_GetObjGeometry
  @glob_in              @ref ACDC_p_GetObjStaticEvasionData
  @glob_in              @ref ACDC_p_GetObjEvasionData
  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModWorkingData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n
                        @ref FCT_MEASUREMENT\n

  @pre                  None 
  @post                 None 

  @InOutCorrelation     None

  @testmethod           @ref TEST_ACDC_V_FILLDEBUGDATA_01 \n
                        @ref TEST_ACDC_V_FILLDEBUGDATA_02 \n
						@ref TEST_ACDC_V_FILLDEBUGDATA_03

  @traceability         Design Decision

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void ACDC_v_FillDebugData(void)
{
#if (ACDC_CFG_CD) 
  ObjNumber_t iMostRelHypObj    = OBJ_INDEX_NO_OBJECT;
  sint8       iMostRelHyp       = -1;
  float32     fHighestRelevance = 0.0f;
  uint32      uHyp;
  ACDCDebugObj_t * const pAIPObjDebug = &(ACDC_p_ModWorkingData()->pIntraCycleMeas->sGlobData.AIP.DebugRelObj);
  CDDebugObj_t   * const pCDObjDebug  = &(ACDC_p_ModWorkingData()->pIntraCycleMeas->sGlobData.CD.DebugRelObj);

  /* Get object id related to the most relevant hypothesis */
  for (uHyp= 0; uHyp < ACDC_p_GetCurrentIntHypotheses()->uNumOfHyps; ++uHyp)
  {
    CDIntHypothesis_t const * pCurrentIntHyp = ACDC_p_GetCurrentIntHypothesis(uHyp);
    if (pCurrentIntHyp->fRelevance > fHighestRelevance)
    {
      fHighestRelevance = pCurrentIntHyp->fRelevance;
      iMostRelHyp       = pCurrentIntHyp->iExtHypID;
      iMostRelHypObj    = pCurrentIntHyp->iObjectRef;
    }
  }

  /* Assign object and internal hypothesis ID */
  pAIPObjDebug->iObj         = iMostRelHypObj;
  pAIPObjDebug->iHyp         = iMostRelHyp;
  /* If a hypothesis was found use the object */ 
  if (    (iMostRelHypObj >= 0           )
       && (iMostRelHypObj <  EM_N_OBJECTS) )
  {
    pAIPObjDebug->Pos          = *ACDC_p_GetObjPositions(iMostRelHypObj);
    pAIPObjDebug->Movement     = *ACDC_p_GetObjMovement(iMostRelHypObj);
    pAIPObjDebug->Geometry     = *ACDC_p_GetObjGeometry(iMostRelHypObj);
    pCDObjDebug->EvasionStatic = *ACDC_p_GetObjStaticEvasionData(iMostRelHypObj);
    pCDObjDebug->Evasion       = *ACDC_p_GetObjEvasionData(iMostRelHypObj);
    pCDObjDebug->TTX           = *ACDC_p_GetObjTTXData(iMostRelHypObj);
  }
#endif /*(ACDC_CFG_CD)*/
}
#endif /* #if (FCT_MEASUREMENT) */
//!@}
#endif /*!(ACDC_CFG_FRAME) */
