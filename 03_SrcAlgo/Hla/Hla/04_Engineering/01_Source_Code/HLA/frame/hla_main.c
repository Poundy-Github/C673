/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_main.c

  DESCRIPTION:            headlight assist main

  CREATION DATE:          2012-12-13
  
  CPU:                    Independent

  VERSION:                $Revision: 1.13.1.3 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hla_main.h"
#include "hla_defs.h"
#include "hla_outputs.h"
#include "hlaf_ext.h"
#include "hla_input_checks.h"
#include "hla_output_checks.h"
#include "hla_errorhandling.h"
#include "hla_rta_type.h"
#include "hla_measfreeze_data.h"

/* Include pdo tags file so that it get scanned by PDO tool in MFC5xx projects */
#include "hla_pdo_tags_file.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
/* Maximum number of additional bytes that are sent for each DEM Event */
#define HLA_DEM_MAX_NUM_ADDITIONAL_BYTES     (8u)

/* Number of cycles we tolerate algo service functions */
#define HLA_DEM_SERVICES_MAX_NUM_ERROR_CYCLES (5u)

/* Interface version of sync ref struct */
#define HLA_SYNC_REF_INTERFACE_VERSION (3u)
/*****************************************************************************
  LOCAL TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/
/* Control variable to make sure that global variables of hla_main.c are initialized */
HLA_GLOBAL_STATIC boolean bGlobVarsInitialized = b_FALSE;

/* Request/Provide port headers */
HLA_GLOBAL_STATIC Hla_SyncRef_t HLA_SyncRef;
HLA_GLOBAL_STATIC Hla_SyncRef_t HLA_SyncRef_PrevCycle;

/* HLA cycle counter */
HLA_GLOBAL_STATIC AlgoCycleCounter_t HLA_CycleCounter = 0u;


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static void HLA_InitGlobVars(void);

static void HLA_OpModeReset( const reqHlaPrtList_t*    const pReqPorts, 
                             const AS_t_ServiceFuncts* const Services,
                                   proHlaPrtList_t*    const pProPorts
                            );
HLA_GLOBAL_STATIC void HLA_OpModeRun( const reqHlaPrtList_t*    const pReqPorts,
                                      const AS_t_ServiceFuncts* const Services,
                                            proHlaPrtList_t*    const pProPorts
                                     );
static void HLA_OpModeIdle( const reqHlaPrtList_t* const pReqPorts, 
                                  proHlaPrtList_t* const pProPorts
                           );
static void HLA_OpModeDemo( const reqHlaPrtList_t* const pReqPorts, 
                                  proHlaPrtList_t* const pProPorts
                           );


static void HLA_OpModeError( const reqHlaPrtList_t* const pReqPorts, 
                                   proHlaPrtList_t* const pProPorts 
                            );
HLA_GLOBAL_STATIC void HLA_MapErrors2DemEvents( const reqHlaPrtList_t*    const pReqPorts,
                                                const AS_t_ServiceFuncts* const Services
                                               );
static void HLA_MapErrors2DemEventsFusiErrors( const uint8 numAdditionalBytes,
                                                     uint8 pAdditionalData[]
                                              );
static uint8 HLA_MapErrors2DemEventsSetFusiError( const uint8                   numAdditionalBytes,
                                                  const uint8                   errorValueLow,
                                                  const uint8                   errorValueHigh,
                                                  const FusiErrorExtDirection_t errorDirection,
                                                  const FusiErrorExtType_t      errorType,
                                                        uint8                   pAdditionalData[]
                                                 );
static void HLA_MapErrors2DemEventsBusDataErrors( const uint8 numAdditionalBytes,
                                                        uint8 pAdditionalData[]
                                                 );
static void HLA_MeasfreezePorts( const proHlaPrtList_t*    const pProPorts,
                                 const AS_t_ServiceFuncts* const Services
                                );

static void HLA_SetSyncRef( const reqHlaPrtList_t* const pReqPorts,
                                  Hla_SyncRef_t*   const pHlaSyncRef_PrevCycle,
                                  Hla_SyncRef_t*   const pHlaSyncRef
                           );

/*****************************************************************************
  GLOBAL FUNCTIONS DEFINITION
*****************************************************************************/
/** ************************************************************************************************
  \brief  
    Main entry function of HLA algorithm
  
  \pre
    None

  \post
    None

  \param[in]      reqPorts   request port pointer list
  \param[out]     proPorts   provide port pointer list
  \param[in]      services   algo services provided by frame SW 

  \return
    Base return code, i.e. boolean-like ok or not-ok.

  \globals
    \ref bGlobVarsInitialized, \ref HLA_CycleCounter, \ref HLA_SyncRef, \ref HLA_SyncRef_PrevCycle

  \InOutCorrelation
    The global variables are initialized during the very first call of this function.

    The \ref HLA_CycleCounter gets incremented by one in any case and error handling is initialized.

    Once minimum input checks are passed a new cycle for HLA algorithm is started (measfreeze cycle, RTA events, etc.).
    Main task of this function is operation mode handling.
    
    If minimum input checks failed an error is returned and provide ports are set to NULL.
    
  \callsequence
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
BaseReturnCode_t HlaExec( const reqHlaPrtList_t*    const reqPorts, 
                                proHlaPrtList_t*    const proPorts, 
                          const AS_t_ServiceFuncts* const services
                         )
{
  BaseReturnCode_t returnCode = BASE_RETURN_ERROR;
  boolean bMinimumInputsAvailable;

  /* Initialize global variables, but only the very first time 
     syncref and syncref_prevcyc*/
  if(bGlobVarsInitialized == b_FALSE)
  {
    HLA_InitGlobVars();
  }

  /* increment HLA call counter */
  HLA_CycleCounter++;

  /* Initialize error handling before doing anything else 
     clear error stack*/
  HLA_ErrorHandling_Init();

  /* Minimal input checks for basic functionality like error reporting and meas freezes 
     null pointer provide port and service func port check*/
  bMinimumInputsAvailable = HLA_InputChecks_MinimumInputs( reqPorts,
                                                          proPorts,
                                                          services
                                                         );

  /* We can only proceed if a basic set of inputs is available */
  if(bMinimumInputsAvailable == b_TRUE)
  {
#ifndef HLA_REMOVE_SERVICEFCT
    services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_EXEC, (uint8)reqPorts->pBaseCtrlData->eOpMode);

    /* Increase measfreeze cycle counter for single frame/cycle stepping during .rec file playback */
    services->pfMeasStartFuncCycle(TASK_ID_HLA);
#endif
    /* Set HLA SyncRef */
    HLA_SetSyncRef( reqPorts,
                    &HLA_SyncRef_PrevCycle,
                    &HLA_SyncRef
                   );

    /* Clear return code */
    returnCode = BASE_RETURN_OK;

    switch(reqPorts->pBaseCtrlData->eOpMode)
    {
    case (uint16)BASE_OM_IDLE:
      /* Idle mode, i.e. set all outputs to zero, set signal state to invalid and do a measfreeze */
      HLA_OpModeIdle(reqPorts, proPorts);
      break;

    case (uint16)BASE_OM_RESET:
#ifndef HLA_REMOVE_SERVICEFCT
      services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_RESET, 0u);
#endif
      HLA_OpModeReset(reqPorts, services, proPorts);
#ifndef HLA_REMOVE_SERVICEFCT
      services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_RESET, 0u);
#endif
      break;

    case (uint16)BASE_OM_DEMO:
      HLA_OpModeDemo(reqPorts, proPorts);
      break;

    case (uint16)BASE_OM_RUN:
#ifndef HLA_REMOVE_SERVICEFCT
      services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_RUN, 0u);
#endif
      HLA_OpModeRun(reqPorts, services, proPorts);
#ifndef HLA_REMOVE_SERVICEFCT
      services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_RUN, 0u);
#endif
      break;

    default:
      HLA_OpModeError(reqPorts, proPorts);
      break;
    }

    /* Map all detected errors to DEM events */
#ifndef HLA_REMOVE_SERVICEFCT
    services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_DEM_EVENTS, 0u);
    HLA_MapErrors2DemEvents( reqPorts, 
                             services
                            );
    services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_DEM_EVENTS, 0u);
    
    /* Measfreeze all our outputs */
    HLA_MeasfreezePorts(proPorts, services);

    services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_EXEC , (uint8)reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter);
#endif
  }
  else
  {
    /* According to architecture all provide pointers shall be set to zero in this case */
    proPorts->pAlgoCompState          = NULL;
    proPorts->pHlaf_HeadlightControl  = NULL;
  }

  return returnCode;
}

/* *******************************************************************************
  Resets algo in a state like it would be right after start-up. Used in simulation only.
  ******************************************************************************** */
void HLA_FirstStatupState(void)
{
  bGlobVarsInitialized = b_FALSE;
}

/*****************************************************************************
  LOCAL FUNCTIONS DEFINITION
*****************************************************************************/
/** ************************************************************************************************
  \brief  
    Initializes global variables of hla_main.c
  
  \pre
    None

  \post
    None

  \param
    None

  \return
    void

  \globals
    \ref bGlobVarsInitialized, \ref HLA_SyncRef, \ref HLA_SyncRef_PrevCycle

  \InOutCorrelation
    SyncRef variables are reset to zero while \ref bGlobVarsInitialized is set to True, of course.

  \callsequence
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InitGlobVars(void)
{
  /* Initialize sync ref structs */
  /* PRQA S 0315 2 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset(&HLA_SyncRef, 0, sizeof(HLA_SyncRef));
  (void)memset(&HLA_SyncRef_PrevCycle, 0, sizeof(HLA_SyncRef_PrevCycle));

  /* HLACycleCounter is initialized in reset mode */

  /* Make sure that global variables are not overwritten */
  bGlobVarsInitialized = b_TRUE;
}

/** ************************************************************************************************
  \brief  
    Initialization of HLA
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      pReqPorts  pointer to request port list coming from RTE
  \param[in]      Services   pointer to algo services provided by frame SW 
  \param[out]     pProPorts  pointer to provide port list going to RTE

  \return
    void

  \globals
    \ref HLA_CycleCounter, \ref HLA_SyncRef, \ref HLA_SyncRef_PrevCycle

  \InOutCorrelation
    Executes HLA initialization routine:
    - input checks
    - set default data to provide ports and algo comp state struct is filled like this:
      - Comp state: "success"
      - sig state: "init"
      - algo qualifier: "ok"
    - executes initialization functions of algo kernel

    If input checks fail outputs are set to default values and algo comp state struct is filled like this:
      - Comp state: "not initialized"
      - sig state: "init"
      - algo qualifier: "critical input error"

  \callsequence
     @startuml ActivityHLAOpModeReset.png
       title HLA_OpModeReset \n in hla_main.c
       (*) --> "Reset HLA counter: \c HLA_CycleCounter = 0u; "
           --> "Init of soft error state by 0"
           --> Error Check
           --> if "<color:green> Error available?" then
                 -left-> [YES] "No proper data available for NvmLearningValues -> Ensure that NVM gets not updated "
                      --> "Set default values for provide ports \n 
                           Comp state should be set to not initialized, sig state to init and algo qualifier to critical input error"
                      --> (*)
               else
                 -down->[NO] "Set default values for provide ports \n 
                                Comp state should be set to success, sig state to init and algo qualifier to ok"
                      --> "Initialize hlaf sub-component :  \c HLAF_v_Init(pReqPorts); "
               endif 
       --> "todo"
       --> (*)
     @enduml
 
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_OpModeReset( const reqHlaPrtList_t*    const pReqPorts, 
                             const AS_t_ServiceFuncts* const Services,
                                   proHlaPrtList_t*    const pProPorts
                            )
{ 
  /* Reset HLA counter */
  HLA_CycleCounter = 0u;

  /* Init soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* Check Input Errors */
#ifndef HLA_REMOVE_SERVICEFCT
  Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_INPUT_CHECKS, 0u);
#endif
  HLA_InputChecks( BASE_OM_RESET,
                  pReqPorts, 
                  &HLA_SyncRef_PrevCycle
                 );
#ifndef HLA_REMOVE_SERVICEFCT
  Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_INPUT_CHECKS, HLA_ErrorHandling_GetNumErrors());
#endif

  /* Check whether we detected an error in sub-components */
  if(HLA_ErrorHandling_GetNumErrors() == 0u)
  {
    /* Set default values for provide ports
     * According to SW-Algo-Interface:
     * Comp state should be set to "success", sig state to "init" and algo qualifier to "ok"
     */
#ifndef HLA_REMOVE_SERVICEFCT
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_SET_DEFAULTS, 0u);
#endif
    HLA_SetOutputDefaults( COMP_STATE_SUCCESS,
                           COMP_ERROR_NO_ERROR,
                           ALGO_QUAL_OK,
                           AL_SIG_STATE_INIT,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                           HLA_CycleCounter,
                           &HLA_SyncRef,
                           pProPorts
                          );
#ifndef HLA_REMOVE_SERVICEFCT
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_SET_DEFAULTS, 0u);
#endif
    /* Initialize functional sub-component */
    HLAF_v_Init( pReqPorts);
  }
  else
  /* Error reporting */
  {
    /* According to SW-Algo-Interface:
     * Comp state should be set to "not initialized", sig state to "init" and algo qualifier to "critical input error"
     */
    HLA_SetOutputDefaults( COMP_STATE_NOT_INITIALIZED,
                           COMP_ERROR_UNKNOWN,
                           ALGO_QUAL_CRITICAL_INPUT_ERROR,
                           AL_SIG_STATE_INIT,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                           HLA_CycleCounter,
                           &HLA_SyncRef,
                           pProPorts
                          );
  }
}

/** ************************************************************************************************
  \brief  
    Main routine of HLA
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      pReqPorts  pointer to request port list coming from RTE
  \param[in]      Services   pointer to algo services provided by frame SW 
  \param[out]     pProPorts  pointer to provide port list going to RTE

  \return
    void

  \globals
    \ref HLA_CycleCounter, \ref HLA_SyncRef, \ref HLA_SyncRef_PrevCycle

  \InOutCorrelation
    First of all input checks are performed. If input checks fail outputs are set to default values.

    In case of a soft error state algo comp state struct is filled like this:
      - Comp state: "running"
      - sig state: "init"
      - algo qualifier: "OK"

    In case of a normal error state algo comp state struct is filled like this:
      - Comp state: "temporary error"
      - sig state: "invalid"
      - algo qualifier: "critical input error"

    In all other cases we have valid inputs. Algo comp state struct is filled like this:
      - Comp state: "running"
      - sig state: "ok"
      - algo qualifier: "ok"
    Only if optional input \c pGenObjectList is missing comp state is set to "reduced availability".

    Then, VDY data and blockage input data are overwritten if coding parameter test mode is one following:
      - RTE_HLA_TESTMODE_LAB
      - RTE_HLA_TESTMODE_LAB_ENHANCED
      - RTE_HLA_TESTMODE_SAE
   
    Finally, algo kernel is called followed by required output checks.

  \callsequence
    @startuml ActivityHLAOpModeRun.png
      title HLA_OpModeRun \n in hla_main.c
      (*) --> "Check Input Errors"
          --> if "<color:green> Error available?" then
                -left-> [No] "copy of request port list to take internal buffer for NVM learning values "
                     --> "Set default values for provide ports \n 
                          Comp state set to running, sig state to ok and algo qualifier to ok"
                     --> "Run functional sub-component: \c HLAF_v_Exec()"
                     --> "Error reporting"
              else
                -down-> [Yes] "Error reporting"
              endif 
      --> (*)
    @enduml
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
HLA_GLOBAL_STATIC void HLA_OpModeRun( const reqHlaPrtList_t*    const pReqPorts,
                                      const AS_t_ServiceFuncts* const Services,
                                            proHlaPrtList_t*    const pProPorts
                                     )
{
  static VehDyn_t HLA_VehicleDynamics;
  static VehSig_t HLA_VehicleSignals;
  static CB_t_ProvidedOutputs_t HLA_BlockageOutput;

  /* Check Input Errors */
#ifndef HLA_REMOVE_SERVICEFCT
  Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_INPUT_CHECKS, 0u);
#endif
  HLA_InputChecks( BASE_OM_RUN,
                  pReqPorts, 
                  &HLA_SyncRef_PrevCycle
                 );
#ifndef HLA_REMOVE_SERVICEFCT
  Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_INPUT_CHECKS, HLA_ErrorHandling_GetNumErrors());
#endif

  /* Continue only if all mandatory data is available and we are not in soft error state */
  if((HLA_ErrorHandling_GetNumErrors() + HLA_ErrorHandling_GetSoftErrorState()) == 0u)
  {
    reqHlaPrtList_t HLA_ReqPortsList;
    CompState_t compState = COMP_STATE_RUNNING;

    /* Prepare copy of request port list to take internal buffer for NVM learning values */
    /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
    /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
    (void)memcpy( &HLA_ReqPortsList, pReqPorts, CML_Min(sizeof(*pReqPorts), sizeof(HLA_ReqPortsList)));

    /* Set default values for provide ports
     * According to SW-Algo-Interface:
     * Comp state should be set to "running", sig state to "ok" and algo qualifier to "ok"
     */
#ifndef HLA_REMOVE_SERVICEFCT
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_SET_DEFAULTS, 0u);
#endif

    /* In case of missing optional request ports we should switch to reduced availability */
    if(   (HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST)   == b_TRUE)
       || (HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_EM_OBJECT_LIST) == b_TRUE)
       || (HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_SIG_STATE_EM_OBJECT_LIST)      == b_TRUE)
       || (HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST)      == b_TRUE)
       || (HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST)   == b_TRUE)
      )
    {
      compState = COMP_STATE_REDUCED_AVAILABILITY;
    }

    HLA_SetOutputDefaults( compState,
                           COMP_ERROR_NO_ERROR,
                           ALGO_QUAL_OK,
                           AL_SIG_STATE_OK,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                           HLA_CycleCounter,
                           &HLA_SyncRef,
                           pProPorts
                          );
#ifndef HLA_REMOVE_SERVICEFCT
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_SET_DEFAULTS, 0u);

    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_EXEC, (uint8)pReqPorts->pLsdLightObjectList->numObjects);
#endif
    /* Run functional sub-component */
    HLAF_v_Exec( &HLA_ReqPortsList,
                 pProPorts,
                 Services
                );
#ifndef HLA_REMOVE_SERVICEFCT
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_EXEC, pProPorts->pHlaf_HeadlightControl->Matrix.HighBeamState);

    /* Perform output checks */
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_OUTPUT_CHECKS, 0u);
#endif
    HLA_OutputChecks(pProPorts);
#ifndef HLA_REMOVE_SERVICEFCT
    Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_OUTPUT_CHECKS, 0u);
#endif
  }
  else
  {
    /* Handle soft error state here */
    if(HLA_ErrorHandling_GetSoftErrorState() != 0u)
    {
      /* According to SW-Algo-Interface:
       * Comp state should be set to "running", sig state to "INIT" and algo qualifier to "OK"
       */
      HLA_SetOutputDefaults( COMP_STATE_RUNNING,
                             COMP_ERROR_NO_ERROR,
                             ALGO_QUAL_OK,
                             AL_SIG_STATE_INIT,
                             pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                             pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                             HLA_CycleCounter,
                             &HLA_SyncRef,
                             pProPorts
                            );
    }
  }

  /* Was there an major issue during input check or while algo kernel was running? */
  if(HLA_ErrorHandling_GetNumErrors() != 0u)
  {
    /* According to SW-Algo-Interface:
     * Comp state should be set to "temporary error", sig state to "invalid" and algo qualifier to "critical input error"
     */
    HLA_SetOutputDefaults( COMP_STATE_TEMPORARY_ERROR,
                           COMP_ERROR_UNKNOWN,
                           ALGO_QUAL_CRITICAL_INPUT_ERROR,
                           AL_SIG_STATE_INVALID,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                           pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                           HLA_CycleCounter,
                           &HLA_SyncRef,
                           pProPorts
                          );
  }
 
}

/** ************************************************************************************************
  \brief  
    Idle mode of HLA
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      pReqPorts  pointer to request port list coming from RTE
  \param[out]     pProPorts  pointer to provide port list going to RTE

  \return
    void

  \globals
    \ref HLA_SyncRef, \ref HLA_CycleCounter

  \InOutCorrelation
    Runs HLA in idle mode, i.e. do "nothing".
    - set all outputs to defaults
    - set signal state to invalid 

  \callsequence
    @startuml ActivityHLAOpModeIdle.png
      title HLA_OpModeIdle \n in hla_main.c
      (*) --> "  HLA_SetOutputDefaults(  
                            COMP_STATE_NOT_RUNNING, 
                            COMP_ERROR_NO_ERROR, 
                            ALGO_QUAL_OK,
                            AL_SIG_STATE_INVALID,
                            pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                            pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                            HLA_CycleCounter,
                            &HLA_SyncRef,
                            pProPorts      ); "
    note left: Comp state is set to "not running", sig state set to "invalid" and algo qualifier set to "OK"
      --> (*)
    @enduml
 
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_OpModeIdle( const reqHlaPrtList_t* const pReqPorts, 
                                  proHlaPrtList_t* const pProPorts
                           )
{
  /* According to SW-Algo-Interface:
   * Comp state should be set to "not running", sig state to "invalid" and algo qualifier to "OK"
   */
  HLA_SetOutputDefaults( COMP_STATE_NOT_RUNNING,
                         COMP_ERROR_NO_ERROR,
                         ALGO_QUAL_OK,
                         AL_SIG_STATE_INVALID,
                         pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                         pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                         HLA_CycleCounter,
                         &HLA_SyncRef,
                         pProPorts
                        );
}

/** ************************************************************************************************
  \brief  
    Demonstration mode of HLA
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      pReqPorts  pointer to request port list coming from RTE
  \param[out]     pProPorts  pointer to provide port list going to RTE

  \return
    void

  \globals
    \ref HLA_CycleCounter

  \InOutCorrelation
    Simulates an HLA run by outputting valid but static data which are always the same.

  \callsequence
    @startuml ActivityHLAOpModeDemo.png
      title HLA_OpModeDemo \n in hla_main.c
      (*) --> "Set default values for provide ports ( except NVM) : \n 
               Comp state should be set to success, sig state to ok and algo qualifier to ok."
          --> "write demo output for RTE output (HeadlightControl Data) \n \c HLA_SetOutputDemo(...)"
      note right: NVM is not updated in OpModeDEMO 
      --> (*)
    @enduml 
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_OpModeDemo( const reqHlaPrtList_t* const pReqPorts, 
                                  proHlaPrtList_t* const pProPorts
                           )
{
  /* According to SW-Algo-Interface:
   * Comp state should be set to "success", sig state to "ok" and algo qualifier to "ok"
   */
  HLA_SetOutputDefaults( COMP_STATE_SUCCESS,
                         COMP_ERROR_NO_ERROR,
                         ALGO_QUAL_OK,
                         AL_SIG_STATE_OK,
                         pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                         pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                         HLA_CycleCounter,
                         &HLA_SyncRef,
                         pProPorts
                        );

  /* Overwrite some default values for demo purposes */
  HLA_SetOutputDemo(pProPorts); 
}

/** ************************************************************************************************
  \brief  
    Error handling for unknown opmodes
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      pReqPorts  pointer to request port list coming from RTE
  \param[out]     pProPorts  pointer to provide port list going to RTE

  \return
    void

  \globals
    \ref HLA_SyncRef, \ref HLA_CycleCounter

  \InOutCorrelation
    Handles unknown OpMode case:
    - set all outputs to zero
    - set signal state to invalid 
    - report back a fatal error to global scheduler

  \callsequence
    @startuml ActivityHLAOpModeError.png
      title HLA_OpModeError \n in hla_main.c
      (*) --> "Call the HLA_SetOutputDefaults() function, with the following values"
      --> "Set compstate to permanent error"
      --> "Set error code to unkown"
      --> "Set AlgoCompstate eCompState to 'success'"
      --> "Set algo qualifier to critical input error"
      --> "Set SigState to invalid"
      --> (*)
    @enduml

  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_OpModeError( const reqHlaPrtList_t* const pReqPorts, 
                                   proHlaPrtList_t* const pProPorts 
                            )
{
  /* According to SW-Algo-Interface:
   * Comp state should be set to "permanent error", sig state to "invalid" and algo qualifier to "critical input error"
   */
  HLA_SetOutputDefaults( COMP_STATE_PERMANENT_ERROR,
                         COMP_ERROR_UNKNOWN,
                         ALGO_QUAL_CRITICAL_INPUT_ERROR,
                         AL_SIG_STATE_INVALID,
                         pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp,
                         pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                         HLA_CycleCounter,
                         &HLA_SyncRef,
                         pProPorts
                        );
}
/** ************************************************************************************************
  \brief  
    Maps detected errors to DEM events in RUN mode.
  
  \pre
    Valid input pointers

  \post
    None

  \param[in]      pReqPorts  pointer to request port list coming from RTE
  \param[in]      Services   pointer to algo services provided by frame SW 

  \return
    void

  \globals
    None

  \InOutCorrelation
    All relevant errors are detected and collected in error stack. According to architectural definitions these errors are mapped
    to DEM events. Additional data is provided according to architecture, too.

  \callsequence
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
HLA_GLOBAL_STATIC void HLA_MapErrors2DemEvents( const reqHlaPrtList_t*    const pReqPorts,
                                                const AS_t_ServiceFuncts* const Services
                                               )
{
  /* DEM events are set to passed if not in RUN mode */
  if(pReqPorts->pBaseCtrlData->eOpMode != (uint16)BASE_OM_RUN)
  {
    Services->pfDem_SetEventStatus(HLA_FUSI_ERROR, DEM_EVENT_STATUS_PASSED);
    Services->pfDem_SetEventStatus(HLA_SERVICE_ERROR, DEM_EVENT_STATUS_PASSED);
    Services->pfDem_SetEventStatus(HLA_BUS_DATA_ERROR, DEM_EVENT_STATUS_PASSED);
    Services->pfDem_SetEventStatus(HLA_INTERNAL_ERROR, DEM_EVENT_STATUS_PASSED);
  } 
  else
  {
    uint8 additionalData[HLA_DEM_MAX_NUM_ADDITIONAL_BYTES];
    
    /* Clean-up additional data */
    /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
    (void)memset( additionalData, 0, sizeof(additionalData));
        
    /**************************************************
     * HLA_FUSI_ERROR -> INPUT/OUTPUT CHECKS FAILED   *
     * Fill additional data:                          *
     * [0]: Directional flag: FusiErrorExtDirection_t *
     * [1]: Type of check: FusiErrorExtType_t         *
     * [2]: Index of affected port                    *
     **************************************************/
    /* Check relevant error bits */
    HLA_MapErrors2DemEventsFusiErrors( HLA_DEM_MAX_NUM_ADDITIONAL_BYTES,
                                       additionalData
                                      );
    
    /* In case a relevant FUSI error bit was set there is some data in additionalData */
    if(additionalData[0] != 0u)
    {  
      Services->pfDem_SetEventStatusPreExtData(HLA_FUSI_ERROR, DEM_EVENT_STATUS_FAILED, additionalData, sizeof(additionalData));
      
      /* Clean-up additional data for next DEM event*/
      /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
      (void)memset( additionalData, 0, sizeof(additionalData));
    }
    else
    {
      Services->pfDem_SetEventStatus(HLA_FUSI_ERROR, DEM_EVENT_STATUS_PASSED);
    }
    
    /********************************************************
     * HLA_SERVICE_ERROR -> ALGO SERVICE FUNCTIONS          *
     ********************************************************/
    /* No service errors are trigger in algo kernel */
    Services->pfDem_SetEventStatus(HLA_SERVICE_ERROR, DEM_EVENT_STATUS_PASSED);

    /********************************************
     * HLA_BUS_DATA_ERROR -> VDY BUS SIGNALS    *
     ********************************************/
    /* Check relevant error bits */
    HLA_MapErrors2DemEventsBusDataErrors( HLA_DEM_MAX_NUM_ADDITIONAL_BYTES,
                                          additionalData
                                         );
    
    /* In case a relevant BUS DATA error bit was set there is some data in additionalData */
    /* PRQA S 3120 1 # 2019-05-28 A.Fischer: array index can not be considered as a magic constant */
    if(additionalData[7] != 0u)
    {  
      Services->pfDem_SetEventStatusPreExtData(HLA_BUS_DATA_ERROR, DEM_EVENT_STATUS_FAILED, additionalData, sizeof(additionalData));
    }
    else
    {
      Services->pfDem_SetEventStatus(HLA_BUS_DATA_ERROR, DEM_EVENT_STATUS_PASSED);
    }
    
    /**********************************************
     * HLA_INTERNAL_ERROR                         *
     **********************************************/
    if(HLA_ErrorHandling_GetError(HLA_ERROR_BLOCKAGE_NO_VALID_INPUT) == b_TRUE)
    {
      Services->pfDem_SetEventStatus(HLA_INTERNAL_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      Services->pfDem_SetEventStatus(HLA_INTERNAL_ERROR, DEM_EVENT_STATUS_PASSED);
    }
  }
}

/** ************************************************************************************************
  \brief  
    Checks FUSI relevant errors of error stack.
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      numAdditionalBytes Number of bytes that pAdditionalData can hold.
  \param[out]     pAdditionalData    Array where additional data must be stored

  \return
    void

  \globals
    None

  \InOutCorrelation
    All FUSI relevant error bits of error stack are checked. Each category is checked separately. Most important one is checked 
    last since several errors will overwrite each other.

  \callsequence
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_MapErrors2DemEventsFusiErrors( const uint8 numAdditionalBytes,
                                                     uint8 pAdditionalData[]
                                              )
{
  uint16 nextFreeIndex, index;

  /* Loop over all output checks bits */
  nextFreeIndex = HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                                       (uint8)HLA_ERROR_OUTPUT_CHECK_SIG_STATE,
                                                       (uint8)HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL,
                                                       FUSI_ERROR_DIR_OUTPUT,
                                                       FUSI_ERROR_TYPE_VERIFICATION,
                                                       pAdditionalData
                                                      );

  /* Provide as many details as possible, i.e. which output value was buggy */
  index = (uint16)HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID;
  while(   (nextFreeIndex < numAdditionalBytes)
        && (index <= (uint16)HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_OBJID)
       )
  {
    /* Check if corresponding error is set */
    /* PRQA S 4342 1 # 2019-05-28 A.Fischer: Casting to error type is intended */
    if(HLA_ErrorHandling_GetError((e_ErrorHandling_Errors)index) == b_TRUE)
    {
      /* Store enum difference */
      pAdditionalData[nextFreeIndex] = (uint8)(index - (uint16)HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID);
  
      nextFreeIndex++;
    }
    index++;
  }

  /* Loop over all critical data and CPAR check bits */
  (void)HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                             (uint8)HLA_ERROR_CRITICAL_INPUTS_MONO_CALI,
                                             (uint8)HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_SPEED_PARAMETERS,
                                             FUSI_ERROR_DIR_INPUT,
                                             FUSI_ERROR_TYPE_VERIFICATION,
                                             pAdditionalData
                                            );

  /* Loop over all measurement counter checks bits */
  (void)HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                             (uint8)HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA,
                                             (uint8)HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST,
                                             FUSI_ERROR_DIR_INPUT,
                                             FUSI_ERROR_TYPE_COUNTER,
                                             pAdditionalData
                                            );

  /* Loop over all timestamp checks bits */
  (void)HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                             (uint8)HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA,
                                             (uint8)HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST,
                                             FUSI_ERROR_DIR_INPUT,
                                             FUSI_ERROR_TYPE_COUNTER,
                                             pAdditionalData
                                            );

  /* DEM mapping for AL_SIG_STATE_INVALID is not required since a DEM event is already sent by provider of this invalid request port */

  /* Loop over all signal state checks bits (for AL_SIG_STATE_INIT) */
  (void)HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                             (uint8)HLA_ERROR_REQ_PORTS_SIG_STATE_BASE_CONTROL_DATA,
                                             (uint8)HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTOBJECTLIST,
                                             FUSI_ERROR_DIR_INPUT,
                                             FUSI_ERROR_TYPE_SIGNALSTATE,
                                             pAdditionalData
                                            );

  /* Loop over all version number checks bits */
  (void)HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                             (uint8)HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA,
                                             (uint8)HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTOBJECTLIST,
                                             FUSI_ERROR_DIR_INPUT,
                                             FUSI_ERROR_TYPE_VERSIONNUMBER,
                                             pAdditionalData
                                            );

  /* Loop over all NULL pointer checks bits */
  (void)HLA_MapErrors2DemEventsSetFusiError( numAdditionalBytes,
                                             (uint8)HLA_ERROR_REQ_PORTS_NULL_POINTER_BASE_CONTROL_DATA,
                                             (uint8)HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST,
                                             FUSI_ERROR_DIR_INPUT,
                                             FUSI_ERROR_TYPE_NULLPOINTER,
                                             pAdditionalData
                                            );
}

/** ************************************************************************************************
  \brief  
    Actually, checks FUSI relevant errors of error stack and set DEM additional data accordingly.
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      numAdditionalBytes Number of bytes that pAdditionalData can hold.
  \param[in]      errorValueLow      Enum value of e_ErrorHandling_Errors where checks should start.
  \param[in]      errorValueHigh     Enum value of e_ErrorHandling_Errors where checks should end.
  \param[in]      errorDirection     Directional flag, i.e. input or output checks.
  \param[in]      errorType          Type of check, e.g. null pointer, version number, etc.
  \param[out]     pAdditionalData    Array where additional data must be stored

  \return
    Returns next free index in additional data array

  \globals
    None

  \InOutCorrelation
    All FUSI relevant error bits of error stack are checked. If an error bit is detected corresponding additional data is filled: \n
      [0]: Directional flag: FusiErrorExtDirection_t\n
      [1]: Type of check: FusiErrorExtType_t\n
      [2]: Index of affected port\n
      [3]: For critical inputs this and following bytes are set in case there
            are more than one error. If contains difference between first 
            critical input enum value and the corresponding one.\n\n

  \callsequence
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static uint8 HLA_MapErrors2DemEventsSetFusiError( const uint8                   numAdditionalBytes,
                                                  const uint8                   errorValueLow,
                                                  const uint8                   errorValueHigh,
                                                  const FusiErrorExtDirection_t errorDirection,
                                                  const FusiErrorExtType_t      errorType,
                                                        uint8                   pAdditionalData[]
                                                 )
{
  /* PRQA S 3120 ++ # 2019-05-28 A.Fischer: initialization of array index, not really a magic number */
  uint8 nextFreeIndex = 2u;
  uint8 index         = errorValueLow;

  /* Loop over all critical data and provide as much information as possible */
  while(   (nextFreeIndex < numAdditionalBytes)
        && (index <= errorValueHigh)
       )
  {
    /* Check if corresponding error is set */
    /* PRQA S 4342 1 # 2019-05-28 A.Fischer: Casting to error type is intended */
    if(HLA_ErrorHandling_GetError((e_ErrorHandling_Errors)index) == b_TRUE)
    {
      /* Store enum difference */
      pAdditionalData[0]             = errorDirection;
      pAdditionalData[1]             = errorType;
      /* <ArrayOOBCheck> 2016-09-28 # 2019-05-28 M.Mutschler: Array access is limited by "numAdditionalBytes" */
      pAdditionalData[nextFreeIndex] = (uint8)(index - errorValueLow);
  
      nextFreeIndex++;
    }
    index++;
  }
  /* PRQA S 3120 -- */

  return nextFreeIndex;
}

/** ************************************************************************************************
  \brief  
    Checks BUS DATA relevant errors of error stack.
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      numAdditionalBytes Number of bytes that pAdditionalData can hold.
  \param[out]     pAdditionalData    Array where additional data must be stored

  \return
    void

  \globals
    None

  \InOutCorrelation
    All BUS DATA relevant error bits of error stack are checked.
    If an error bit is detected corresponding additional data is filled: \n
    [0-3]: virtual address of signal struct\n
    [4-5]: offset inside signal struct\n
    [6]:   Status flag of signal\n
    [7]:   Should not be zero\n\n

  \callsequence
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_MapErrors2DemEventsBusDataErrors( const uint8 numAdditionalBytes,
                                                        uint8 pAdditionalData[]
                                                 )
{
  uint8 i;

  /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten. */
  /* PRQA S 3120 ++ # 2019-05-28 A.Fischer: index number of arrays is ok as magic number */
  if(numAdditionalBytes >= 8u)
  /* COU_COV_ENABLE */
  {
    const uint32 measIdVehDyn = VDY_MEAS_ID_VEH_DYN;

    /* Loop over all VDY DATA checks bits */
    for(i = (uint8)HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE; i <= (uint8)HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE; i++)
    {
      /* Check if corresponding error is set */
      /* PRQA S 4342 1 # 2019-05-28 A.Fischer: Casting to error type is intended */
      if(HLA_ErrorHandling_GetError((e_ErrorHandling_Errors)i) == b_TRUE)
      {
        const uint16 structOffset = HLA_ErrorHandling_GetBusSigStateOffset();
        /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
        /* PRQA S 0315, 1495, 3494 2 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 1495: Target buffer is an array and gets filled with additional data here. 3494: Defensive programming */
        (void)memcpy( &pAdditionalData[0], &measIdVehDyn, CML_Min(4u, sizeof(measIdVehDyn)));
        (void)memcpy( &pAdditionalData[4], &structOffset, CML_Min(2u, sizeof(structOffset)));
        /* COU_COV_ENABLE */

        pAdditionalData[6] = HLA_ErrorHandling_GetBusSigStateFlag();
        pAdditionalData[7] = (uint8)(i - (uint8)HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE + 1u);
      }
    }
  
    /* Loop over all VEH SIG checks bits */
    for(i = (uint8)HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED; i <= (uint8)HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE; i++)
    {
      /* Check if corresponding error is set */
      /* PRQA S 4342 1 # 2019-05-28 A.Fischer: Casting to error type is intended */
      if(HLA_ErrorHandling_GetError((e_ErrorHandling_Errors)i) == b_TRUE)
      {
        const uint16 structOffset = HLA_ErrorHandling_GetBusSigStateOffset();
        /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
        /* PRQA S 0315, 1495, 3494 2 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 1495: Target buffer is an array and gets filled with additional data here. 3494: Defensive programming */
        (void)memcpy( &pAdditionalData[0], &measIdVehDyn, CML_Min(4u, sizeof(measIdVehDyn)));
        (void)memcpy( &pAdditionalData[4], &structOffset, CML_Min(2u, sizeof(structOffset)));
        /* COU_COV_ENABLE */

        pAdditionalData[6] = HLA_ErrorHandling_GetBusSigStateFlag();
        pAdditionalData[7] = (uint8)(i - (uint8)HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED + 1u);
      }
    }
  }
  /* PRQA S 3120 -- */
}

/** ************************************************************************************************
  \brief
    Meas freezes all provide ports and internal data like error stack.
  
  \pre
    None

  \post
    None

  \param [in]  pProPorts  Pointer to provide port list going to RTE
  \param [in]  Services   Pointer to service functions

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Meas freeze is performed for the global variables HLA_SyncRef and the error stack. Then the provide
    ports (algo comp state and headlight control) are meas freezed. The number of meas freeze bytes is
    added to an internal counter.

  \callsequence

  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_MeasfreezePorts( const proHlaPrtList_t*    const pProPorts,
                                 const AS_t_ServiceFuncts* const Services
                                )
{
  static const AS_t_MeasInfo HLA_SyncRefMeasInfo      = {HLA_MEAS_VADDR_SYNC_REF,                  sizeof(Hla_SyncRef_t),               TASK_ID_HLA, TASK_ID_HLA};
  static const AS_t_MeasInfo HLA_ErrorStackMeasInfo   = {HLA_MEAS_VADDR_ERROR_STACK,               sizeof(t_ErrorHandling_ErrorStack),  TASK_ID_HLA, TASK_ID_HLA};
  static const AS_t_MeasInfo AlgoCompStateMeasInfo    = {HLA_MEAS_VADDR_PRO_PORT_ALGO_COMP_STATE,  sizeof(AlgoCompState_t),             TASK_ID_HLA, TASK_ID_HLA};
  static const AS_t_MeasInfo HeadlightControlMeasInfo = {HLA_MEAS_VADDR_PRO_PORT_HEADLIGHT_CTRL,   sizeof(RTE_HLAF_HeadlightControl_t), TASK_ID_HLA, TASK_ID_HLA};

  /* Freeze global variables */
  /* PRQA S 0314 2 # 2019-05-06 A.Manz: Explicit conversion intended, only way how this is working */
  (void)Services->pfMeasFreeze(&HLA_SyncRefMeasInfo,    (const void*)&HLA_SyncRef,                      NULL);
  (void)Services->pfMeasFreeze(&HLA_ErrorStackMeasInfo, (const void*)HLA_ErrorHandling_GetErrorStack(), NULL);

  /* Freeze provide ports */
  /* PRQA S 0314 2 # 2019-05-06 A.Manz: Explicit conversion intended, only way how this is working */
  (void)Services->pfMeasFreeze(&AlgoCompStateMeasInfo,    (const void*)pProPorts->pAlgoCompState,         NULL);
  (void)Services->pfMeasFreeze(&HeadlightControlMeasInfo, (const void*)pProPorts->pHlaf_HeadlightControl, NULL);

  /* Add number of measfreeze bytes to internal counter */
  HLA_ErrorHandling_AddMeasfreezeAmount(HLA_SyncRefMeasInfo.Length);
  HLA_ErrorHandling_AddMeasfreezeAmount(HLA_ErrorStackMeasInfo.Length);
  HLA_ErrorHandling_AddMeasfreezeAmount(AlgoCompStateMeasInfo.Length);
  HLA_ErrorHandling_AddMeasfreezeAmount(HeadlightControlMeasInfo.Length);
}


/** ************************************************************************************************
  \brief  
    Fills signal header list with headers of current request ports.
  
  \pre
    Valid input pointers as checked in \ref HLA_InputChecks_MinimumInputs().

  \post
    None

  \param[in]      pReqPorts             Pointer to request port list coming from RTE
  \param[out]     pHlaSyncRef_PrevCycle Pointer to signal header list of previous cycle
  \param[in,out]  pHlaSyncRef           Pointer to signal header list used for synchronization in SIL

  \return
    void

  \globals
    \ref HLA_SyncRef

  \InOutCorrelation
    Signal headers of previous cycle are backed-up, firstly. Then base ctrl data and all signal headers of current request ports 
    - if available - are stored in this signal header list.

  \callsequence
 
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_SetSyncRef( const reqHlaPrtList_t* const pReqPorts,
                                  Hla_SyncRef_t*   const pHlaSyncRef_PrevCycle,
                                  Hla_SyncRef_t*   const pHlaSyncRef
                           )
{
  /* Save SyncRef data for different signal header checks later on. */
  /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
  /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
  (void)memcpy(pHlaSyncRef_PrevCycle, pHlaSyncRef, CML_Min(sizeof(*pHlaSyncRef_PrevCycle), sizeof(*pHlaSyncRef)));
  /* COU_COV_ENABLE */

  /* Reset HLA SyncRef */
  /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
  (void)memset(pHlaSyncRef, 0, sizeof(*pHlaSyncRef));

  /* Fill version number */
  pHlaSyncRef->uiVersionNumber = HLA_SYNC_REF_INTERFACE_VERSION;

  /* Signal header must be equal to the one of provide ports, i.e. will be filled later in HLA_SetOutputDefaults() */

  /* Base ctrl data must be copied completely. We reach this part of the code only if pBaseCtrlData is not NULL */
  /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
  /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
  (void)memcpy(&(pHlaSyncRef->sBaseCtrl), pReqPorts->pBaseCtrlData, CML_Min(sizeof(pHlaSyncRef->sBaseCtrl), sizeof(*(pReqPorts->pBaseCtrlData))));
  /* COU_COV_ENABLE */

  if(pReqPorts->pCPar_HlafPar != NULL)
  {
    pHlaSyncRef->pCPar_HlafPar = pReqPorts->pCPar_HlafPar->sSigHeader;
  }
  if(pReqPorts->pCbOutputs != NULL)
  {
    pHlaSyncRef->pCbOutputs = pReqPorts->pCbOutputs->sSigHeader;
  }
  if (pReqPorts->pGenObjectList != NULL)
  {
    pHlaSyncRef->pGenObjectList = pReqPorts->pGenObjectList->sSigHeader;
  }

  if(pReqPorts->pHlaBusInputSignals != NULL)
  {
    pHlaSyncRef->pHlaBusInputSignals = pReqPorts->pHlaBusInputSignals->sSigHeader;
  }
  if(pReqPorts->pHlaRadarObjectList != NULL)
  {
    pHlaSyncRef->pHlaRadarObjectList = pReqPorts->pHlaRadarObjectList->sSigHeader;
  }

  if(pReqPorts->pVehDyn != NULL)
  {
    pHlaSyncRef->pVehDyn = pReqPorts->pVehDyn->sSigHeader;
  }

  if (pReqPorts->pVehSig != NULL)
  {
    pHlaSyncRef->pVehSig = pReqPorts->pVehSig->sSigHeader;
  }

  if (pReqPorts->pLsdEnvironmentData != NULL)
  {
    pHlaSyncRef->pLsdEnvironmentData = pReqPorts->pLsdEnvironmentData->sSigHeader;
  }

  if (pReqPorts->pLsdLightObjectList != NULL)
  {
    pHlaSyncRef->pLsdLightObjectList = pReqPorts->pLsdLightObjectList->sSigHeader;
  }

  if (pReqPorts->pLsdLightList != NULL)
  {
    pHlaSyncRef->pLsdLightList = pReqPorts->pLsdLightList->sSigHeader;
  }
}
