/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_input_checks.c

  DESCRIPTION:            Headlight assist input checks.

  CREATION DATE:          2014-04-10
  
  CPU:                    Independent

  VERSION:                $Revision: 1.15.1.1 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hla_defs.h"
#include "hla_input_checks.h"
#include "hla_errorhandling.h"
#include "hla_cpar_init.h"
#include "hla_utils.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* PRQA S 7013 EOF # 2019-05-28 M.Mutschler: screw the 750 line limitation! */

/* Allowed Cycle Counter Diffs */
#define HLA_DEM_ALLOWED_CYCLE_COUNTER_DIFF_INPUT    (2u)
#define HLA_DEM_ALLOWED_CYCLE_COUNTER_DIFF_IMAGE    (4u)
#define HLA_DEM_ALLOWED_CYCLE_COUNTER_DIFF_VDY      (3u)
#define HLA_DEM_ALLOWED_CYCLE_COUNTER_DIFF_IPC      (6u)

/* Allowed successive invalid cycle counter for certain non critical inputs */
#define HLA_CYCLE_COUNTER_ALLOWED_INVALID_INPUT_STRICT     (0u)
#define HLA_CYCLE_COUNTER_ALLOWED_INVALID_INPUT_MEDIUM     (10u)
#define HLA_CYCLE_COUNTER_ALLOWED_INVALID_INPUT_RELAXED    (100u)

/* In case of a wrap around of timestamp, difference to previous timestamp is huge */
#define HLA_WRAPAROUND_TIMESTAMP_DIFF    ((sint64)UI32_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_TIME))
/* In case of a wrap around of measurement counter, difference to previous measurement counter is huge*/
#define HLA_WRAPAROUND_MEAS_COUNTER_DIFF ((sint32)UI16_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_CYCLES))

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static void HLA_InputChecks_ServicesAvailability(const AS_t_ServiceFuncts* const Services);

static void HLA_InputChecks_ProPortsAvailability(const proHlaPrtList_t* const pProPorts);

static void HLA_InputChecks_ReqPortsAvailability( const BaseOpMode_t           eOpMode,
                                                  const reqHlaPrtList_t* const pReqPorts
                                                );

static void HLA_InputChecks_ReqPortsVersion( const BaseOpMode_t           eOpMode,
                                             const reqHlaPrtList_t* const pReqPorts
                                           );

static void HLA_InputChecks_ReqPortsSigStatus( const BaseOpMode_t           eOpMode,
                                               const reqHlaPrtList_t* const pReqPorts
                                             );

static void HLA_InputChecks_ReqPortsTimestamps( const BaseOpMode_t           eOpMode,
                                                const Hla_SyncRef_t*   const pHlaSyncRefPrevCycle,
                                                const reqHlaPrtList_t* const pReqPorts
                                              );

static void HLA_InputChecks_ReqPortsMeasCounter( const BaseOpMode_t           eOpMode,
                                                 const Hla_SyncRef_t*   const pHlaSyncRefPrevCycle,
                                                 const reqHlaPrtList_t* const pReqPorts
                                               );

static void HLA_InputChecks_BusSignalState(const reqHlaPrtList_t* const pReqPorts);

static void HLA_InputChecks_CriticalInputData( const BaseOpMode_t           eOpMode,
                                               const reqHlaPrtList_t* const pReqPorts
                                             );

static void HLA_InputChecks_ReqPortsSigStatusInvalid( const BaseOpMode_t           eOpMode,
                                                      const reqHlaPrtList_t* const pReqPorts
                                                    );

static void HLA_InputChecks_ReqPortsSigStatusInit(const reqHlaPrtList_t* const pReqPorts);

static void HLA_InputChecks_SetSoftErrorState( const e_ErrorHandling_Errors   errorBit,
                                               const e_ErrorHandling_Warnings warningBit,
                                               const AlgoCycleCounter_t       measCnt
                                             );

static void HLA_InputChecks_CPARRangeChecksHlafPar(const CPAR_HLAF_Parameter_t* const pCParHlafPar);

static void HLA_InputChecks_CPARPlausibilityChecksHlafPar(const CPAR_HLAF_Parameter_t* const pCParHlafPar);

static void HLA_InputChecks_CPARDiff2DefaultsHlafPar(const CPAR_HLAF_Parameter_t* const pCParHlafPar);


/*****************************************************************************
  GLOBAL FUNCTIONS DEFINITION
*****************************************************************************/
/* *******************************************************************************
  Performs input checks specified by algo architecture
******************************************************************************** */
void HLA_InputChecks( const BaseOpMode_t           eOpMode,
                      const reqHlaPrtList_t* const pReqPorts, 
                      const Hla_SyncRef_t*   const pHlaSyncRefPrevCycle
                    )
{
  /* Check for availability of critical request ports 
     null pointer check */
  HLA_InputChecks_ReqPortsAvailability( eOpMode, 
                                       pReqPorts
                                      );

  /* If there were no errors found we can continue with further checks */
  if(HLA_ErrorHandling_GetNumErrors() == 0u)
  {
#ifndef HLA_REMOVE_VERSIONNUMBER_CHECK
    /* Check interface version of request ports */
    HLA_InputChecks_ReqPortsVersion( eOpMode, 
                                    pReqPorts
                                   );
#endif
  }

  /* If there were no errors found we can continue with further checks */
  if(HLA_ErrorHandling_GetNumErrors() == 0u)
  {
#ifndef HLA_REMOVE_SIGSTATUS_CHECK
    /* Check signal status of request ports */
    HLA_InputChecks_ReqPortsSigStatus( eOpMode,
                                      pReqPorts
                                     );
#endif
  }

  /* If there were no errors found and we are not in soft error state we can continue with further checks */
  if((HLA_ErrorHandling_GetNumErrors() + HLA_ErrorHandling_GetSoftErrorState()) == 0u)
  {
#ifndef HLA_REMOVE_ALIVE_CHECK
    /* Check timestamps of request ports */
    HLA_InputChecks_ReqPortsTimestamps( eOpMode, 
                                       pHlaSyncRefPrevCycle,
                                       pReqPorts
                                      );
    /* Check measurement counters of request ports */
    HLA_InputChecks_ReqPortsMeasCounter( eOpMode, 
                                        pHlaSyncRefPrevCycle,
                                        pReqPorts
                                       );
#endif
  }

  /* If there were no errors found and we are not in soft error state we can continue with further checks */
  if((HLA_ErrorHandling_GetNumErrors() + HLA_ErrorHandling_GetSoftErrorState()) == 0u)
  {
    /* Following port checks are only needed during run mode */
    if(eOpMode == (uint16)BASE_OM_RUN)
    {
      /* Check bus signals' state */
      HLA_InputChecks_BusSignalState(pReqPorts);
    }

    /* All following checks are not mandatory from architectural point of view. */

    /* Check signal status of request ports */
    HLA_InputChecks_CriticalInputData( eOpMode,
                                      pReqPorts
                                     );
  }
}

/* *******************************************************************************
  Minimum check to ensure a proper algo execution
******************************************************************************** */
boolean HLA_InputChecks_MinimumInputs( const reqHlaPrtList_t*    const pReqPorts, 
                                      const proHlaPrtList_t*    const pProPorts,
                                      const AS_t_ServiceFuncts* const Services
                                     )
{
  /* Check provide ports and fill error stack */
  HLA_InputChecks_ProPortsAvailability(pProPorts);

#ifndef HLA_REMOVE_SERVICEFCT
  /* Check algo service functions */
  HLA_InputChecks_ServicesAvailability(Services);
#endif
  /* Check BSW Ctrl Data */
  if(pReqPorts == NULL)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LIST);
  }
  else
  {
    if(pReqPorts->pBaseCtrlData == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BASE_CONTROL_DATA);
    }
    else
    {
      if(pReqPorts->pBaseCtrlData->uiVersionNumber != (AlgoInterfaceVersionNumber_t)BASE_CTRL_DATA_INTFVER)
      {
        HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA);
      }      
      if(pReqPorts->pBaseCtrlData->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK)
      {
        HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_BASE_CONTROL_DATA);
      }
    }
  }

  /* Since we start with an empty error stack there should not have been found any errors */
  return (HLA_ErrorHandling_GetNumErrors() == 0u);
}

/*****************************************************************************
  LOCAL FUNCTIONS DEFINITION
*****************************************************************************/
/** ************************************************************************************************ 
  \brief
    Checks provide ports for NULL pointers.
                    
  \pre
    None
  \post
    None
                    
  \param[in]  pProPorts  provide port pointer list
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation 
    Every provide port is checked against being a NULL pointer. If it
    is a NULL pointer appropriate error bit is set in error stack.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_ProPortsAvailability(const proHlaPrtList_t* const pProPorts)
{
  if(pProPorts == NULL)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_PRO_PORT_NULL_POINTER_LIST);
  }
  else
  {
    if(pProPorts->pAlgoCompState == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_PRO_PORT_NULL_POINTER_COMP_STATE);
    }
    if(pProPorts->pHlaf_HeadlightControl == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_PRO_PORT_NULL_POINTER_HEADLIGHT_CONTROL);
    }
  }
}
/** ************************************************************************************************ 
  \brief
    Checks services for NULL pointers.
                    
  \pre
    None

  \post
    None
                    
  \param[in]  Services  Pointer to algo services provided by frame SW
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    Every service function is checked against being a NULL pointer. If it
    is a NULL pointer appropriate error bit is set in error stack.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_ServicesAvailability(const AS_t_ServiceFuncts* const Services)
{
  if(Services == NULL)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_SERVICES_NULL_POINTER_LIST);
  }
  else
  {
    if(Services->pfRTAAlgoServiceAddEvent == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_SERVICES_NULL_POINTER_ADD_RTA_EVENT);
    }
    if(Services->pfMeasStartFuncCycle == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_SERVICES_NULL_POINTER_MEAS_START_CYCLE);
    }
    if(Services->pfMeasFreeze == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_SERVICES_NULL_POINTER_MEAS_FREEZE);
    }
    if(Services->pfDem_SetEventStatus == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_SERVICES_NULL_POINTER_DEM_SET_EVENT);
    }
    if(Services->pfDem_SetEventStatusPreExtData == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_SERVICES_NULL_POINTER_DEM_EXT_DATA);
    }
  }
}
/** ************************************************************************************************
  \brief
    Checks request ports for NULL pointers. In the OpMode run the following ports are checked for Null 
    pointers:

    \li pCPar_HlafPar
    \li pLsdEnvironmentData
    \li pLsdLightObjectList
    \li pLsdLightList
    \li pCbOutputs
    \li pGenObjectList
    \li pMonoCalibration
    \li pVehDyn
    \li pVehSig
    \li pHlaRadarObjectList

    If a null pointer was detected an error in the error stack will be set. pGenObjectList and
    pHlaRadarObjectList is not a mandatory request port and only an information in the error stack will
    be set.

    @startuml HLA_InputChecks_ReqPortsAvailability.png
    title Request ports check
        
    start
    if(OpMode is run) then (Yes)
      if(pCPar_HlafPar is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pLsdEnvironmentData is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pLsdLightObjectList is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pLsdLightList is NULL) then (Yes)
      :Set error in error stack;
      else (No)
      endif
      if(pCbOutputs is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pMonoCalibration is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pVehDyn is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pVehSig is NULL) then (Yes)
        :Set error in error stack;
      else (No)
      endif
    else (No)
    endif
    
    if(pGenObjectList is NULL) then (Yes)
      :Set information in error stack;
    else (No)
    endif
    if(pHlaRadarObjectList is NULL) then (Yes)
      :Set information in error stack;
    else (No)
    endif
    stop
        
    @enduml
  
  \pre
    None

  \post
    If an error occurred it is stored in the internal error stack variable.

  \param [in]  eOpMode    Operation mode (reset, run)
  \param [in]  pReqPorts  Pointer to request port list

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsAvailability( const BaseOpMode_t           eOpMode,
                                                  const reqHlaPrtList_t* const pReqPorts
                                                )
{
  /* At first, request ports that are needed all the time */
  /* None at the moment */

  /* Request ports that are only needed in reset phase */
  /* None at the moment */

  /* Request ports that are only needed in run mode */
  if(eOpMode == (uint16)BASE_OM_RUN)
  {
    if(pReqPorts->pCPar_HlafPar == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_CPAR_HLAF);
    }
#if (HLA_Mono_CALIBRATION == STD_ON)
    if(pReqPorts->pMonoCalibration == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_MONO_CALI);
    }
#endif
    if(pReqPorts->pCbOutputs == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE);
    }
    if(pReqPorts->pHlaBusInputSignals == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS);
    }
    if(pReqPorts->pVehDyn == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VDY_DATA);
    }
    if(pReqPorts->pVehSig == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VEH_SIG);
    }
    if(pReqPorts->pLsdEnvironmentData == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA);
    }
#if (HLA_LSD == STD_ON)
    if(pReqPorts->pLsdLightObjectList == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST);
    }
    if(pReqPorts->pLsdLightList == NULL)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTLIST);
    }
#endif
  }

  /* Finally, non-mandatory request ports, i.e. only information bits will be set. They will be checked during algo execution. */
  if(pReqPorts->pGenObjectList == NULL)
  {
    HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST);
  }
  if(pReqPorts->pHlaRadarObjectList == NULL)
  {
    HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_HLA_RADAR_OBJECT_LIST);
  }
}
/** ************************************************************************************************
  \brief
    Checks request ports for interface version mismatch. Every request port interface is checked
    whether it is compatible currently defined one in RTE.

    @startuml HLA_InputChecks_ReqPortsVersion.png
    title Request ports version number check
        
    start
    if(OpMode is run) then (Yes)
      if(pCPar_HlafPar version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pLsdEnvironmentData version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pLsdLightObjectList version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pLsdLightList version number doesn't match INTFVER from RTE) then (Yes)
      :Set error in error stack;
      else (No)
      endif
      if(pCbOutputs version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pMonoCalibration version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pVehDyn version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
      if(pVehSig version number doesn't match INTFVER from RTE) then (Yes)
        :Set error in error stack;
      else (No)
      endif
    else (No)
    endif
    
    if(pGenObjectList is not NULL\npGenObjectList version number doesn't match INTFVER from RTE) then (Yes)
      :Set information in error stack;
    else (No)
    endif
    if(pHlaRadarObjectList is not NULL\pHlaRadarObjectList version number doesn't match INTFVER from RTE) then (Yes)
      :Set information in error stack;
    else (No)
    endif
    stop
        
    @enduml
  
  \pre
    None

  \post
    In case of a failed checked an error in the error stack will be set.

  \param [in]  eOpMode    Operation mode (reset, run)
  \param [in]  pReqPorts  Pointer to request port list

  \return
    None

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsVersion( const BaseOpMode_t           eOpMode,
                                             const reqHlaPrtList_t* const pReqPorts
                                           )
{
  /* At first, request ports that are needed all the time */

  /* Request ports that are only needed in reset phase */
  /* None at the moment */

  /* Request ports that are only needed in run mode */
  if(eOpMode == (uint16)BASE_OM_RUN)
  {
#ifdef HLA_RPORT_PCPAR_HLAFPAR
    if(pReqPorts->pCPar_HlafPar->uiVersionNumber != (AlgoInterfaceVersionNumber_t)CPAR_HLAF_PARAMETER_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_CPAR_HLAF);
    }
#endif
#if (HLA_Mono_CALIBRATION == STD_ON)
    if(pReqPorts->pMonoCalibration->uiVersionNumber != (AlgoInterfaceVersionNumber_t)MONO_CALIBRATION_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_MONO_CALI);
    }
#endif
#ifdef HLA_RPORT_PHLABUSINPUTSIGNALS
    if(pReqPorts->pHlaBusInputSignals->uiVersionNumber != (AlgoInterfaceVersionNumber_t)HLA_BUS_INPUT_SIGNALS_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_HLA_BUS_INPUT_SIGNALS);
    }
#endif
#ifdef HLA_RPORT_PVEHSIG
    if(pReqPorts->pVehSig->uiVersionNumber != (AlgoInterfaceVersionNumber_t)BSW_VEH_SIG_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VEH_SIG);
    }
#endif
#ifdef HLA_RPORT_PVEHDYN
    if(pReqPorts->pVehDyn->uiVersionNumber != (AlgoInterfaceVersionNumber_t)VDY_VEH_DYN_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VDY_DATA);
    }
#endif
#ifdef HLA_RPORT_PCBOUTPUTS
    if(pReqPorts->pCbOutputs->uiVersionNumber != (AlgoInterfaceVersionNumber_t)CB_PROVIDED_OUTPUTS_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BLOCKAGE);
    }
#endif
#if (HLA_LSD == STD_ON)
#ifdef HLA_RPORT_PLSDENVIRONMENTDATA
    if(pReqPorts->pLsdEnvironmentData->uiVersionNumber != (AlgoInterfaceVersionNumber_t)LSD_ENVIRONMENT_DATA_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_ENVIRONMENT_DATA);
    }
#endif


    if(pReqPorts->pLsdLightObjectList->uiVersionNumber != (AlgoInterfaceVersionNumber_t)LSD_LIGHT_OBJECT_LIST_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTOBJECTLIST);
    }
    if(pReqPorts->pLsdLightList->uiVersionNumber != (AlgoInterfaceVersionNumber_t)LSD_LIGHT_LIST_INTFVER)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTLIST);
    }
#endif

  }
#if 0
  /* Finally, non-mandatory request ports, i.e. only information bits will be set. They will be checked during algo execution. */
  if(   (pReqPorts->pGenObjectList != NULL)
     && (pReqPorts->pGenObjectList->uiVersionNumber != ((AlgoInterfaceVersionNumber_t)EM_GEN_OBJECT_LIST_INTFVER | (AlgoInterfaceVersionNumber_t)EM_GEN_OBJECT_INTFVER))
    )
  {
    HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_EM_OBJECT_LIST);
  }
  if(   (pReqPorts->pHlaRadarObjectList != NULL)
     && (pReqPorts->pHlaRadarObjectList->uiVersionNumber != (AlgoInterfaceVersionNumber_t)HLA_RADAR_OBJECT_LIST_INTFVER)
    )
  {
    HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_HLA_RADAR_OBJECT_LIST);
  }
#endif
}
/** ************************************************************************************************
  \brief
  Checks request ports for signal state errors. Every request port signal state is checked whether it
  is in initialization state or even invalid. Invalid signals lead to an error situation whereas
  initialization states are fine in reset mode. In run mode this will lead to a soft error state if
  it doesn't persist too long. An information is set in case the signal status of the em object list or
  the hla radar object list is not ok.

  @startuml HLA_InputChecks_ReqPortsSigStatus.png
  title Request ports signal status check
      
  start
  if(OpMode is run) then (Yes)
    :Check signal status  of request ports for init;
    if(No Errors or Warnings are set) then (Yes)
      :Set Soft Error State to zero;
    else(No)
    endif
  else (No)
  endif
  :Check signal status  of request ports for invalid;
  
  if(pGenObjectList is not zero \nSignal status is not ok) then (Yes)
    :Set Information;
  else(No)
  endif
  if(pHlaRadarObjectList is not zero \nSignal status is not ok) then (Yes)
    :Set Information;
  else(No)
  endif
  stop
      
  @enduml
  
  \pre
    None

  \post
    In case of a failed checked an error in the error stack will be set.

  \param [in]  eOpMode    Operation mode (reset, run)
  \param [in]  pReqPorts  Pointer to request port list

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsSigStatus( const BaseOpMode_t           eOpMode,
                                               const reqHlaPrtList_t* const pReqPorts
                                             )
{
  /* **************
     INIT SIG STATE 
   ************** */
  /* At first, check for soft error state. But only in RUN mode */
  if(eOpMode == (uint16)BASE_OM_RUN)
  {
    uint8 numErrors, numWarnings;

    HLA_InputChecks_ReqPortsSigStatusInit(pReqPorts);

    /* This check is only called if there is no error/warning in error stack.
     * Hence, if error stack is still empty we are (no longer) in soft error state
     * and we can clean soft error state by setting corresponding measurement counter to zero
     */
    numErrors   = HLA_ErrorHandling_GetNumErrors();
    numWarnings = HLA_ErrorHandling_GetNumWarnings();

    if(   (numErrors == 0u)
       && (numWarnings == 0u)
      )
    {
      HLA_ErrorHandling_SetSoftErrorState(0u);
    }
  }

  /* *****************
     INVALID SIG STATE 
   ***************** */
  /* Second step is to check for INVALID sig state and issue an error */
  HLA_InputChecks_ReqPortsSigStatusInvalid( eOpMode,
                                            pReqPorts
                                          );
#if 0
  /* *********************************
     NON-MANDATORY REQ PORTS SIG STATE 
   ********************************* */
  /* Finally, non-mandatory request ports, i.e. only information bits will be set. They will be checked during algo execution. */
  if(   (pReqPorts->pGenObjectList != NULL)
     && (pReqPorts->pGenObjectList->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK)
    )
  {
    HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_SIG_STATE_EM_OBJECT_LIST);
  }
  if(   (pReqPorts->pHlaRadarObjectList != NULL)
     && (pReqPorts->pHlaRadarObjectList->sSigHeader.eSigStatus != (uint8)AL_SIG_STATE_OK)
    )
  {
    HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_SIG_STATE_HLA_RADAR_OBJECT_LIST);
  }
#endif
}
/** ************************************************************************************************
  \brief
    Checks request ports for timestamp errors. Every non-static request port is checked for timestamp 
    errors, i.e. timestamp must increase monotonically. In order to cover wrap-arounds time stamp
    difference between this and previous cycle must not be too big.\n
    Additionally, time difference compared to base ctrl data must not be greater than
    ALGO_FUSI_DEBOUNCE_TIME.

    @startuml HLA_InputChecks_ReqPortsTimestamps.png
    title Request ports timestamp check
        
    start
    
    :Check timestamp diff from current and previous frame of Base Control Data;
    if(OpMode is run) then (Yes)
      :Check timestamp diff from current and previous frame and \ndiff of signal to base control data for \npMonoCalibration \npHlaBusInputSignals \npVehSig \npVehDyn \npCbOutputs \npLsdEnvironmentData \npLsdLightObjectList \npLsdLightList;
      :Set error if test failed;
    else(No)
    endif
    
    :Check timestamp diff from current and previous frame and \ndiff of signal to base control data for pGenObjectList;
    :Set information if test failed;
    :Check timestamp diff from current and previous frame and \ndiff of signal to base control data for pHlaRadarObjectList;
    :Set information if test failed;
    stop
        
    @enduml
  
  \pre
    None

  \post
    In case of timestamp error an error in the error stack was set

  \param [in]  eOpMode               Operation mode (reset, run)
  \param [in]  pHlaSyncRefPrevCycle  Pointer to sync ref struct of previous cycle
  \param [in]  pReqPorts             Pointer to request port list

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsTimestamps( const BaseOpMode_t           eOpMode,
                                                const Hla_SyncRef_t*   const pHlaSyncRefPrevCycle,
                                                const reqHlaPrtList_t* const pReqPorts
                                              )
{
  sint64 timeStampDiff;
  sint64 timeStampBaseCtrlDiff;

  /* At first, request ports that are needed all the time */

  /* BSW CTRL DATA */
  timeStampDiff = (sint64)pHlaSyncRefPrevCycle->sBaseCtrl.sSigHeader.uiTimeStamp - (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
  if(   (timeStampDiff > 0)
     && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF) 
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA);
  }

  /* Request ports that are only needed in reset phase */
  /* None at the moment */

  /* Request ports that are only needed in run mode */
  if(eOpMode == (uint16)BASE_OM_RUN)
  {

#if (HLA_Mono_CALIBRATION == STD_ON)
    /* MONO CALI */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pMonoCalibration.uiTimeStamp - (sint64)pReqPorts->pMonoCalibration->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pMonoCalibration->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI);
    }
#endif
    /* HLA SIG */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pHlaBusInputSignals.uiTimeStamp - (sint64)pReqPorts->pHlaBusInputSignals->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pHlaBusInputSignals->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS);
    }

    /* VEH SIG */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pVehSig.uiTimeStamp - (sint64)pReqPorts->pVehSig->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pVehSig->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG);
    }

    /* VDY DATA */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pVehDyn.uiTimeStamp - (sint64)pReqPorts->pVehDyn->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pVehDyn->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA);
    }
#if (HLA_LSD == STD_ON)
    /* BLOCKAGE */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pCbOutputs.uiTimeStamp - (sint64)pReqPorts->pCbOutputs->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pCbOutputs->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE);
    }
    /* LSD ENVIRONMENT DATA */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pLsdEnvironmentData.uiTimeStamp - (sint64)pReqPorts->pLsdEnvironmentData->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pLsdEnvironmentData->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA);
    }
    /* LSD LIGHTOBJECTS LIST */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pLsdLightObjectList.uiTimeStamp - (sint64)pReqPorts->pLsdLightObjectList->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pLsdLightObjectList->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST);
    }

    /* LSD LIGHT LIST */
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pLsdLightList.uiTimeStamp - (sint64)pReqPorts->pLsdLightList->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pLsdLightList->sSigHeader.uiTimeStamp;
    if(   (   (timeStampDiff > 0)
           && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST);
    }
#endif
  }
#if (HLA_EM_OBJ == STD_ON)
  /* Finally, non-mandatory request ports, i.e. only information bits will be set. They will be checked during algo execution. */
  /* EM OBJECT LIST */
  if(pReqPorts->pGenObjectList != NULL)
  {
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pGenObjectList.uiTimeStamp - (sint64)pReqPorts->pGenObjectList->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pGenObjectList->sSigHeader.uiTimeStamp;
    if(  (   (timeStampDiff > 0)
          && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
         )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST);
    }
  }
  }
#endif
#if (HLA_RADAR_OBJ == STD_ON)
  /* HLA RADAR OBJECT LIST */
  if(pReqPorts->pHlaRadarObjectList != NULL)
  {
    timeStampDiff = (sint64)pHlaSyncRefPrevCycle->pHlaRadarObjectList.uiTimeStamp - (sint64)pReqPorts->pHlaRadarObjectList->sSigHeader.uiTimeStamp;
    timeStampBaseCtrlDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)pReqPorts->pHlaRadarObjectList->sSigHeader.uiTimeStamp;
    if(  (   (timeStampDiff > 0)
          && (timeStampDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
         )
       || (   (timeStampBaseCtrlDiff > ALGO_FUSI_DEBOUNCE_TIME)
           && (timeStampBaseCtrlDiff < HLA_WRAPAROUND_TIMESTAMP_DIFF)
          )
      )
    {
      HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_HLA_RADAR_OBJECT_LIST);
    }
  }
#endif
}
/** ************************************************************************************************
  \brief
    Checks request ports for measurement counter errors. Every non-static request port is checked for
    measurement counter errors, i.e. measurement counters must increase monotonically. In order to 
    cover wrap-arounds measurement counter difference between this and  previous cycle must not be too
    big.\n
    Additionally, measurement counters of images must be equal to the one of base ctrl data if image is
    from same cycle. Or one less if image is from previous cycle.

    @startuml HLA_InputChecks_ReqPortsMeasCounter.png
    title Request ports measurement counter check
        
    start
    
    :Check measurement counter diff from current and previous frame of Base Control Data;
    if(OpMode is run) then (Yes)
      :Check measurement diff from current and previous frame and \ndiff of signal to base control data for \npMonoCalibration \npHlaBusInputSignals \npVehSig \npVehDyn \npCbOutputs \npLsdEnvironmentData \npLsdLightObjectList \npLsdLightList;
      :Set error if test failed;
    else(No)
    endif
    
    :Check measurement diff from current and previous frame and \ndiff of signal to base control data for pGenObjectList;
    :Set information if test failed;
    :Check measurement diff from current and previous frame and \ndiff of signal to base control data for pHlaRadarObjectList;
    :Set information if test failed;
    stop
        
    @enduml
  
  \pre
    None

  \post
    In case of measurement counter diff an error in the error stack was set

  \param [in]  eOpMode               Operation mode (reset, run)
  \param [in]  pHlaSyncRefPrevCycle  Pointer to sync ref struct of previous cycle
  \param [in]  pReqPorts             Pointer to request port list

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsMeasCounter( const BaseOpMode_t           eOpMode,
                                                 const Hla_SyncRef_t*   const pHlaSyncRefPrevCycle,
                                                 const reqHlaPrtList_t* const pReqPorts
                                               )
{
  sint32 measCounterDiff;

  /* At first, request ports that are needed all the time */
  /* BSW CTRL DATA */
  measCounterDiff = (sint32)pHlaSyncRefPrevCycle->sBaseCtrl.sSigHeader.uiMeasurementCounter - (sint32)pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
  if(   (measCounterDiff > 0)
     && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF) 
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA);
  }

  /* Request ports that are only needed in reset phase */
  /* None at the moment */
  
  /* Request ports that are only needed in run mode */
  if(eOpMode == (uint16)BASE_OM_RUN)
  {
  #if (HLA_Mono_CALIBRATION == STD_ON)
    /* MONO CALI */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pMonoCalibration.uiMeasurementCounter - (sint32)pReqPorts->pMonoCalibration->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI);
    }
#endif
    /* HLA SIG */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pHlaBusInputSignals.uiMeasurementCounter - (sint32)pReqPorts->pHlaBusInputSignals->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS);
    }

    /* VEH SIG */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pVehSig.uiMeasurementCounter - (sint32)pReqPorts->pVehSig->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG);
    }

    /* VDY DATA */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pVehDyn.uiMeasurementCounter - (sint32)pReqPorts->pVehDyn->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA);
    }
    /* BLOCKAGE */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pCbOutputs.uiMeasurementCounter - (sint32)pReqPorts->pCbOutputs->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE);
    }
    /* LSD ENVIRONMENT DATA */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pLsdEnvironmentData.uiMeasurementCounter - (sint32)pReqPorts->pLsdEnvironmentData->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA);
    }
#if (HLA_LSD == STD_ON)
    /* LSD LIGHTOBJECT LIST */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pLsdLightObjectList.uiMeasurementCounter - (sint32)pReqPorts->pLsdLightObjectList->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST);
    }

    /* LSD LIGHT LIST */
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pLsdLightList.uiMeasurementCounter - (sint32)pReqPorts->pLsdLightList->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
      && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST);
    }
#endif
  }

  /* Finally, non-mandatory request ports, i.e. only information bits will be set. They will be checked during algo execution. */
#if (HLA_EM_OBJ == STD_ON)  
  /* EM OBJECT LIST */
  if(pReqPorts->pGenObjectList != NULL)
  {
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pGenObjectList.uiMeasurementCounter - (sint32)pReqPorts->pGenObjectList->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST);
    }
  }
#endif
#if (HLA_RADAR_OBJ == STD_ON) 
  /* HLA RADAR OBJECT LIST */
  if(pReqPorts->pHlaRadarObjectList != NULL)
  {
    measCounterDiff = (sint32)pHlaSyncRefPrevCycle->pHlaRadarObjectList.uiMeasurementCounter - (sint32)pReqPorts->pHlaRadarObjectList->sSigHeader.uiMeasurementCounter;
    if(   (measCounterDiff > 0)
       && (measCounterDiff < HLA_WRAPAROUND_MEAS_COUNTER_DIFF)
      )
    {
      HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_HLA_RADAR_OBJECT_LIST);
    }
  }
#endif
}
/** ************************************************************************************************
  \brief
    Checks state flag of bus signals. For each bus signal provided by VDY a separate state flag was
    set telling use whether we signal is valid or not. This status of this flag is checked in this
    function.
    Check VDY_SOUT_POS_YAWRATE, VDY_SOUT_POS_VELOCITY, VDY_SOUT_POS_ACCEL, VDY_SOUT_POS_MOTIONSTATE
    states of pVehDyn. If this state flag is not valid or init an error in the internal error
    stack will be set. Then VEH_SIG_ADD_SPEEDO_SPEED, VEH_SIG_ADD_WIPER_STATE of pVehSig are
    checked. If this state flag is not valid or init (or not available in case of the wiper sate) an
    error in the internal error stack will be set.

    @startuml HLA_InputChecks_BusSignalState.png
    title Request ports bus signals check

    start

    :Check \nVDY_SOUT_POS_YAWRATE \nVDY_SOUT_POS_VELOCITY \nVDY_SOUT_POS_ACCEL \nVDY_SOUT_POS_MOTIONSTATE \nstates of pVehDyn;
    : Set error if state flag is not valid or init;
    :Check\nVEH_SIG_ADD_SPEEDO_SPEED \nof pVehSig;
    : Set error if state flag is not valid or init;
    :VEH_SIG_ADD_WIPER_STATE \nof pVehSig;
    : Set error if state flag is not valid, init ot not available;
    stop

    @enduml

  \pre
    None

  \post
    In case of bus signal error an error in the error stack was set

  \param [in]  pReqPorts   Pointer to request port list

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_BusSignalState( const reqHlaPrtList_t* const pReqPorts)
{
  VDYIoStateTypes_t stateFlag;
  
  /* Check yaw rate signal state */
  stateFlag = pReqPorts->pVehDyn->State[VDY_SOUT_POS_YAWRATE];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehDyn->Lateral.YawRate.YawRate - (intptr_t)pReqPorts->pVehDyn
                                     );
  }
  /* Check curve signal state */
  stateFlag = pReqPorts->pVehDyn->State[VDY_SOUT_POS_CURVE];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_CURVE);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehDyn->Lateral.Curve.Curve - (intptr_t)pReqPorts->pVehDyn
                                     );
  }
  /* Check steering wheel angle signal state */
  stateFlag = pReqPorts->pVehSig->VehSigMain.State[VDY_SIN_POS_SWA];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_SWA);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehDyn->Lateral.OffCompStWheelAngle - (intptr_t)pReqPorts->pVehDyn
                                     );
  }
  /* Check velocity signal state */
  stateFlag = pReqPorts->pVehDyn->State[VDY_SOUT_POS_VELOCITY];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehDyn->Longitudinal.Velocity - (intptr_t)pReqPorts->pVehDyn
                                     );
  }
  /* Check acceleration signal state */
  stateFlag = pReqPorts->pVehDyn->State[VDY_SOUT_POS_ACCEL];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehDyn->Longitudinal.Accel - (intptr_t)pReqPorts->pVehDyn
                                     );
  }
  /* Check motion state signal state */
  stateFlag = pReqPorts->pVehDyn->State[VDY_SOUT_POS_MOTIONSTATE];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehDyn->MotionState.MotState - (intptr_t)pReqPorts->pVehDyn
                                     );
  }
  /* Check display speed signal state */
  stateFlag = pReqPorts->pVehSig->VehSigAdd.State[VEH_SIG_ADD_SPEEDO_SPEED];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehSig->VehSigAdd.SpeedoSpeed - (intptr_t)pReqPorts->pVehSig
                                     );
  }
  /* Check wiper state signal state */
  stateFlag = pReqPorts->pVehSig->VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE];
  if(   (stateFlag != (uint8)VDY_IO_STATE_VALID)
     && (stateFlag != (uint8)VDY_IO_STATE_INIT)
     && (stateFlag != (uint8)VDY_IO_STATE_NOTAVAIL)
    )
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE);
    HLA_ErrorHandling_SetBusSigState( stateFlag, 
                                      (intptr_t)pReqPorts->pVehSig->VehSigAdd.WiperState - (intptr_t)pReqPorts->pVehSig
                                     );
  }
}
/** ************************************************************************************************
  \brief
    Checks critical input data of validity. Some inputs are essential for algo execution. They are
    used several times inside the algo. Hence, they are checked beforehand.

    @startuml HLA_InputChecks_CriticalInputData.png
    title Critical input data check
        
    start
    
    if(OpMode is run) then (Yes)
      :Check camera type;
      :Check fFocalX and fFocalY are not zerofrom calibration;
      :Set error if one of the tests failed;
    else (No)
    endif
    
    if(OpMode is reset) then (Yes)
      :Check Hlaf cpar ranges;
      :Check Hlaf cpar plausibility;
      :Set error if one of these tests failed;
      :Check hlaf cpar diff to default values;
      :Set warning if one of these tests failed;
    else(No)
    endif
    
    stop
        
    @enduml
  
  \pre
    None
  
  \post
    error or warning in the error stack was set in case of mismatch

  \param [in]  eOpMode    Operation mode (reset, run)
  \param [in]  pReqPorts  Pointer to request port list

  \return
    Void

  \globals
    Errors are stored in global error stack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLA_InputChecks_CriticalInputData( const BaseOpMode_t           eOpMode,
                                               const reqHlaPrtList_t* const pReqPorts
                                             )
{
#if (HLA_MONO_CALIBARATION == STD_ON)
  boolean bCaliInvalid;
#endif
  boolean bVDYInvalid;

  if(eOpMode == (uint16)BASE_OM_RUN)
  {
  #if (HLA_MONO_CALIBARATION == STD_ON)
    /* Mono calibration camera type must be of type "imager" else coordinates of principle point are not matching. */ 
    /* Focal length must not be zero as use as divisor */
    bCaliInvalid =                 (pReqPorts->pMonoCalibration->eCameraType != (uint8)MC_CAMERA_TYPE_RROI);
    bCaliInvalid = bCaliInvalid || (CML_f_IsNonZero(pReqPorts->pMonoCalibration->sIntrinsic.fFocalX) == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sIntrinsic.fFocalX)         == b_FALSE);
    bCaliInvalid = bCaliInvalid || (CML_f_IsNonZero(pReqPorts->pMonoCalibration->sIntrinsic.fFocalY) == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sIntrinsic.fFocalY)         == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sIntrinsic.fCenterX)           == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sIntrinsic.fCenterX)        == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sIntrinsic.fCenterY)           == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sIntrinsic.fCenterY)        == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sPoseCalibration.fTx)          == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sPoseCalibration.fTx)       == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sPoseCalibration.fTy)          == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sPoseCalibration.fTy)       == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sPoseCalibration.fTz)          == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sPoseCalibration.fTz)       == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sPoseCalibration.fRoll)        == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sPoseCalibration.fRoll)     == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sPoseCalibration.fPitch)       == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sPoseCalibration.fPitch)    == b_FALSE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsNAN(pReqPorts->pMonoCalibration->sPoseCalibration.fYaw)         == b_TRUE);
    bCaliInvalid = bCaliInvalid || (HLAUtilsIsFinite(pReqPorts->pMonoCalibration->sPoseCalibration.fYaw)      == b_FALSE);
    
    if( bCaliInvalid == b_TRUE )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI);
    }
#endif
    /* Check critical data of VDY */
    bVDYInvalid =                (HLAUtilsIsNAN(pReqPorts->pVehDyn->Longitudinal.Accel)         == b_TRUE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsFinite(pReqPorts->pVehDyn->Longitudinal.Accel)      == b_FALSE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsNAN(pReqPorts->pVehDyn->Longitudinal.Velocity)      == b_TRUE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsFinite(pReqPorts->pVehDyn->Longitudinal.Velocity)   == b_FALSE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsNAN(pReqPorts->pVehDyn->Lateral.Curve.Curve)        == b_TRUE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsFinite(pReqPorts->pVehDyn->Lateral.Curve.Curve)     == b_FALSE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsNAN(pReqPorts->pVehDyn->Lateral.YawRate.YawRate)    == b_TRUE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsFinite(pReqPorts->pVehDyn->Lateral.YawRate.YawRate) == b_FALSE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsNAN(pReqPorts->pVehSig->VehSigAdd.SpeedoSpeed)      == b_TRUE);
    bVDYInvalid = bVDYInvalid || (HLAUtilsIsFinite(pReqPorts->pVehSig->VehSigAdd.SpeedoSpeed)   == b_FALSE);

    
    if( bVDYInvalid == b_TRUE )
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_CRITICAL_INPUTS_VDY);
    }
  }

  /* Check coding parameters but only during reset mode */
  if(eOpMode == (uint16)BASE_OM_RESET)
  {
    /* Check ranges CPARs */
    HLA_InputChecks_CPARRangeChecksHlafPar(pReqPorts->pCPar_HlafPar);

    /* Check plausibility of CPARs */
    HLA_InputChecks_CPARPlausibilityChecksHlafPar(pReqPorts->pCPar_HlafPar);

    /* Check whether CPARs differ from defaults defined in cpar_init.h */
    HLA_InputChecks_CPARDiff2DefaultsHlafPar(pReqPorts->pCPar_HlafPar);
  }
}
/** ************************************************************************************************ 
  \brief
    Checks request ports for invalid signal states.
                    
  \pre
    None
  \post
    None
                    
  \param[in]  eOpMode  Operation mode (reset, run)
  \param[in]  pReqPorts  Pointer to request port list
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    Every request port signal state is checked whether it is invalid.
    Invalid signals lead to an error situation.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsSigStatusInvalid( const BaseOpMode_t           eOpMode,
                                                      const reqHlaPrtList_t* const pReqPorts
                                                    )
{
  /* At first, request ports that are needed all the time */
  /* None at the moment */

  /* Request ports that are only needed in reset phase */
  /* None at the moment */

  /* Request ports that are only needed in run mode */
  if(eOpMode == (uint16)BASE_OM_RUN)
  {
    if(pReqPorts->pCPar_HlafPar->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_CPAR_HLAF);
    }
#if ( HLA_MONO_CALIRATION == STD_ON )
    if(pReqPorts->pMonoCalibration->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_MONO_CALI);
    }
#endif
    if(pReqPorts->pHlaBusInputSignals->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_HLA_BUS_INPUT_SIGNALS);
    }
    if(pReqPorts->pVehSig->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VEH_SIG);
    }
    if(pReqPorts->pVehDyn->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VDY_DATA);
    }
    if(pReqPorts->pCbOutputs->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_BLOCKAGE);
    }
    if(pReqPorts->pLsdEnvironmentData->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_ENVIRONMENT_DATA);
    }
#if ( HLA_LSD == STD_ON )
    if(pReqPorts->pLsdLightObjectList->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTOBJECTLIST);
    }
    if(pReqPorts->pLsdLightList->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INVALID)
    {
      HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTLIST);
    }
#endif
  }
}
/** ************************************************************************************************ 
  \brief
    During run mode every request port is checked for signal state in initialization state.
                    
  \pre
    None
  \post
    None
                    
  \param[in]  pReqPorts  Pointer to request port list
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    In run mode every request port signal state is checked whether it is in initialization state. 
    This will lead to a soft error state. If that one persists too long we will switch to an 
    error state.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_ReqPortsSigStatusInit(const reqHlaPrtList_t* const pReqPorts)
{
  const AlgoCycleCounter_t currentMeasCnt = pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;

  if(pReqPorts->pCPar_HlafPar->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_CPAR_HLAF,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF,
                                       currentMeasCnt
                                     );
  }
#if (HLA_MONO_CALIBARATION == STD_ON )
  if(pReqPorts->pMonoCalibration->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_MONO_CALI,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_MONO_CALI,
                                       currentMeasCnt
                                     );
  }
#endif  
  if(pReqPorts->pHlaBusInputSignals->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_HLA_BUS_INPUT_SIGNALS,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS,
                                       currentMeasCnt
                                     );
  }
  if(pReqPorts->pVehSig->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VEH_SIG,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_VEH_SIG,
                                       currentMeasCnt
                                     );
  }
  if(pReqPorts->pVehDyn->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VDY_DATA,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_VDY_DATA,
                                       currentMeasCnt
                                     );
  }
  if(pReqPorts->pCbOutputs->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_BLOCKAGE,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_BLOCKAGE,
                                       currentMeasCnt
                                     );
  }
  #if (HLA_LSD == STD_ON )
  if(pReqPorts->pLsdEnvironmentData->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_ENVIRONMENT_DATA,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA,
                                       currentMeasCnt
                                     );
  }
  if(pReqPorts->pLsdLightObjectList->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTOBJECTLIST,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST,
                                       currentMeasCnt
                                     );
  }
  if(pReqPorts->pLsdLightList->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_INIT)
  {
    HLA_InputChecks_SetSoftErrorState( HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTLIST,
                                       HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTLIST,
                                       currentMeasCnt
                                     );
  }
#endif
}
/** ************************************************************************************************ 
  \brief
    Sets soft error state 
                    
  \pre
    None
    
  \post
    None
                    
  \param[in] errorBit    Error bit for this signal header
  \param[in] warningBit  Warning bit for this signal header
  \param[in] measCnt     Current measurement counter
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    Sets soft error state if not yet done, i.e. a warning bit in error stack. If we are already in that
    state we will check for how long. If it persists too long we switch to real error state by setting
    corresponding error bit in error stack.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_SetSoftErrorState( const e_ErrorHandling_Errors   errorBit,
                                               const e_ErrorHandling_Warnings warningBit,
                                               const AlgoCycleCounter_t       measCnt
                                             )
{
  const AlgoCycleCounter_t softErrorMeasCnt = HLA_ErrorHandling_GetSoftErrorState();

  /* Check whether this is the first cycle of soft error state */
  if(softErrorMeasCnt == 0u)
  {
    /* Set soft error state */
    HLA_ErrorHandling_SetSoftErrorState(measCnt);
    HLA_ErrorHandling_SetWarning(warningBit);
  }
  else
  {
    /* Soft error state persists for some cycles. Check if switch to real error state is applicable */
    sint32 measCounterDiff = (sint32)measCnt - (sint32)softErrorMeasCnt; 

    /* Handle possible wrap-around */
    if(measCounterDiff < 0)
    {
      measCounterDiff += (sint32)UI16_T_MAX;
    }
    /* Check since when we are in soft error state. Factor of 2 since we are called every second image. */
     /* PRQA S 3120 1 # 2019-05-28 A.Fischer: magic number is justified by comment */
    if(measCounterDiff > (ALGO_FUSI_DEBOUNCE_CYCLES * 2))
    {
      /* We are too long in soft error state -> issue an error */
      HLA_ErrorHandling_SetError(errorBit);
    }
    else
    {
      /* Still send a warning */
      HLA_ErrorHandling_SetWarning(warningBit);
    }
  }
}
/** ************************************************************************************************ 
  \brief
    This check ensures that HLAF coding parameters are in valid range.
                    
  \pre
    None
    
  \post
    None
                    
  \param[in]  pCParHlafPar  Pointer to HLAF coding parameters
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    Each HLAF coding parameter is checked against defined range in hla_algo_interface_types.xls.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_CPARRangeChecksHlafPar(const CPAR_HLAF_Parameter_t* const pCParHlafPar)
{
  /* PRQA S 3120 ++ # 2019-05-28 A.Fischer: magic numbers ok for range checks */
  /* PRQA S 3121 ++ # 2019-05-28 A.Fischer: magic numbers ok for range checks */
  /* PRQA S 2986 ++ # 2019-05-06 A.Manz: Behaviour is due to usage of CML_SetBit. */
  boolean HlafParOutOfRange;
  uint32 i;

  /* Algo config - No need to check lower edge of range as pCParHlafPar->AlgoCfg.XXX is of unsigned type and XXX_UNKNOWN is 0. */
  HlafParOutOfRange =                      (pCParHlafPar->AlgoCfg.TestMode > (uint8)RTE_HLA_TESTMODE_2 );
  HlafParOutOfRange = HlafParOutOfRange || (pCParHlafPar->AlgoCfg.FogDetection > (uint8)RTE_HLA_FOGDET_ACTIVE);

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS);
  }

  /* Keep-on delay - No need to check lower edge of range, if it is 0, of pCParHlafPar->KeepOnDelay.XXX if it is of unsigned type. */
  HlafParOutOfRange =                      (pCParHlafPar->KeepOnDelay.distanceOncomingVehicle     > 5000u);
  HlafParOutOfRange = HlafParOutOfRange || (pCParHlafPar->KeepOnDelay.distancePrecedingVehicleMin > 5000u);
  HlafParOutOfRange = HlafParOutOfRange || (pCParHlafPar->KeepOnDelay.distancePrecedingVehicleMax > 5000u);

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS);
  }

  /* TurnOnDelay */
  HlafParOutOfRange =                      (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.OncomingMin)         == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.OncomingMax)         == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.OncomingMaxHighway)  == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.PrecedingMin)        == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.PrecedingMinWiperOn) == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.PrecedingMaxShort)   == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 20.0f, pCParHlafPar->TurnOnDelay.PrecedingMaxLong)    == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 30.0f, pCParHlafPar->TurnOnDelay.SlowOvertaking)      == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 30.0f, pCParHlafPar->TurnOnDelay.Fog)                 == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 30.0f, pCParHlafPar->TurnOnDelay.Blockage)            == b_FALSE);

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS);
  }

  /* TurnOffDelay */
  HlafParOutOfRange =                      (CML_f_IsInRange(0.0f, 30.0f, pCParHlafPar->TurnOffDelay.oncomingVehicle)  == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 30.0f, pCParHlafPar->TurnOffDelay.precedingVehicle) == b_FALSE);

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS);
  }

  /* Speed */
  HlafParOutOfRange =                      (CML_f_IsInRange(0.0f, 100.0f, pCParHlafPar->Speed.DeactivateSpeed)          == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 300.0f, pCParHlafPar->Speed.DeactivateSpeedHigh)      == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 100.0f, pCParHlafPar->Speed.ActivateSpeed)            == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 300.0f, pCParHlafPar->Speed.ActivateSpeedHigh)        == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 100.0f, pCParHlafPar->Speed.AlwaysActiveSpeed)        == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 100.0f, pCParHlafPar->Speed.KeepOff_VeryLowSpeed)     == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 500.0f, pCParHlafPar->Speed.KeepOff_LowRadius)        == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f,  20.0f, pCParHlafPar->Speed.KeepOff_HighAcceleration) == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f,  20.0f, pCParHlafPar->Speed.KeepOff_AccTime)          == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f,  20.0f, pCParHlafPar->Speed.KeepOff_Delay)            == b_FALSE);

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS);
  }

  /* Matrix - No need to check lower edge of range, if it is 0, of pCParHlafPar->Matrix.XXX if it is of unsigned type. */
  HlafParOutOfRange =                      (pCParHlafPar->Matrix.MaxNumGlarefreeArea > (uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS);

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_MATRIX_PARAMETERS);
  }
#if (HLA_DIMMING == STD_ON )
  /* Dimming - No need to check lower edge of range, if it is 0, of pCParHlafPar->Dimming.XXX if it is of unsigned type. */
  HlafParOutOfRange =                      (pCParHlafPar->Dimming.DimmingDetection > (uint8)RTE_HLA_DIMMDET_ACTIVE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 100.0f, pCParHlafPar->Dimming.ReductThreshLevel1) == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f, 100.0f, pCParHlafPar->Dimming.ReductThreshLevel2) == b_FALSE);
  HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(0.0f,  10.0f, pCParHlafPar->Dimming.TurnOnDelay)        == b_FALSE);
  for(i = 0u; i < (uint32)RTE_HLA_NUM_DIMM_AREAS_BORDERS; i++)
  {
    HlafParOutOfRange = HlafParOutOfRange || (CML_f_IsInRange(CML_Deg2Rad(-19.0f), CML_Deg2Rad(19.0f), pCParHlafPar->Dimming.AreaRightBorderArray[i]) == b_FALSE);
  }

  if(HlafParOutOfRange == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS);
  }
  /* PRQA S 3120 -- */
  /* PRQA S 3121 -- */
  /* PRQA S 2986 -- # 2019-05-06 A.Manz: Behaviour is due to usage of CML_SetBit. */
#endif
}
/** ************************************************************************************************ 
  \brief
    Checks whether CPARs are plausible.
                    
  \pre
    None
    
  \post
    None
                    
  \param[in]  pCParHlafPar  Pointer to HLAF coding parameters
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    For some HLAF coding parameters we check whether they are plausible,
    for instance, lower threshold is smaller than upper limit.
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_CPARPlausibilityChecksHlafPar(const CPAR_HLAF_Parameter_t* const pCParHlafPar)
{
  boolean CparErr ;

  /* plausibility check of keep-on parameters */
  CparErr = (pCParHlafPar->KeepOnDelay.distancePrecedingVehicleMax < pCParHlafPar->KeepOnDelay.distancePrecedingVehicleMin); /* Reset of CparErr */

  if(CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_KEEP_ON_PARAMETERS);
  }

  /* plausibility check of turn-on parameters */
  CparErr =            (pCParHlafPar->TurnOnDelay.OncomingMax        < pCParHlafPar->TurnOnDelay.OncomingMin);           /* Reset of CparErr */
  CparErr = CparErr || (pCParHlafPar->TurnOnDelay.OncomingMaxHighway < pCParHlafPar->TurnOnDelay.OncomingMin);
  CparErr = CparErr || (pCParHlafPar->TurnOnDelay.PrecedingMaxShort  < pCParHlafPar->TurnOnDelay.PrecedingMin);
  CparErr = CparErr || (pCParHlafPar->TurnOnDelay.PrecedingMaxLong   < pCParHlafPar->TurnOnDelay.PrecedingMin);
  CparErr = CparErr || (pCParHlafPar->TurnOnDelay.PrecedingMaxShort  < pCParHlafPar->TurnOnDelay.PrecedingMinWiperOn);
  CparErr = CparErr || (pCParHlafPar->TurnOnDelay.PrecedingMaxLong   < pCParHlafPar->TurnOnDelay.PrecedingMinWiperOn);

  if(CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_TURN_ON_PARAMETERS);
  }

  /* plausibility check of speed parameters */
  CparErr =            (pCParHlafPar->Speed.DeactivateSpeedHigh < pCParHlafPar->Speed.ActivateSpeedHigh);    /* Reset of CparErr */
  CparErr = CparErr || (pCParHlafPar->Speed.ActivateSpeedHigh   < pCParHlafPar->Speed.AlwaysActiveSpeed);
  CparErr = CparErr || (pCParHlafPar->Speed.AlwaysActiveSpeed   < pCParHlafPar->Speed.ActivateSpeed);
  CparErr = CparErr || (pCParHlafPar->Speed.ActivateSpeed       < pCParHlafPar->Speed.DeactivateSpeed);
  CparErr = CparErr || (pCParHlafPar->Speed.DeactivateSpeed     < pCParHlafPar->Speed.KeepOff_VeryLowSpeed);

  if(CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_SPEED_PARAMETERS);
  }
}
/** ************************************************************************************************ 
  \brief
     Checks whether CPARs are still defaults as defined in cpar_init.h
                    
  \pre
    None
    
  \post
    None
                    
  \param[in]  pCParHlafPar  Pointer to HLAF coding parameters
                    
  \return
    void
                    
  \globals
    None
  
  \InOutCorrelation
    Each HLAF coding parameter is checked against its default value defined in cpar_init.h
  
  \callsequence     
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
static void HLA_InputChecks_CPARDiff2DefaultsHlafPar(const CPAR_HLAF_Parameter_t* const pCParHlafPar)
{
  /* PRQA S 3120 ++ # 2019-05-28 A.Fischer: array index is not a magic number */
  CPAR_HLAF_Parameter_t CPar_HlafPar_Ref;
  boolean CparErr;

  /* Initialize default parameters */
  CParInitCPAR_HLAF_Parameter(&CPar_HlafPar_Ref);

  /* compare algo config parameters with default values */
  CparErr  =            (CPar_HlafPar_Ref.AlgoCfg.TestMode != pCParHlafPar->AlgoCfg.TestMode);          /* Reset of CparErr */
  CparErr  = CparErr || (CPar_HlafPar_Ref.AlgoCfg.FogDetection != pCParHlafPar->AlgoCfg.FogDetection);

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_ALGO_CONFIG_PARAMETERS);
  }

  /* compare KeepOnDelay parameters with default values */
  CparErr =            (CPar_HlafPar_Ref.KeepOnDelay.distanceOncomingVehicle     != pCParHlafPar->KeepOnDelay.distanceOncomingVehicle);      /* Reset of CparErr */
  CparErr = CparErr || (CPar_HlafPar_Ref.KeepOnDelay.distancePrecedingVehicleMin != pCParHlafPar->KeepOnDelay.distancePrecedingVehicleMin);
  CparErr = CparErr || (CPar_HlafPar_Ref.KeepOnDelay.distancePrecedingVehicleMax != pCParHlafPar->KeepOnDelay.distancePrecedingVehicleMax);

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_KEEP_ON_DELAY_PARAMETERS);
  }

  /* compare TurnOnDelay parameters with default values */
  CparErr =            (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.OncomingMin         - pCParHlafPar->TurnOnDelay.OncomingMin));          /* Reset of CparErr */
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.OncomingMax         - pCParHlafPar->TurnOnDelay.OncomingMax));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.OncomingMaxHighway  - pCParHlafPar->TurnOnDelay.OncomingMaxHighway));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.PrecedingMin        - pCParHlafPar->TurnOnDelay.PrecedingMin));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.PrecedingMinWiperOn - pCParHlafPar->TurnOnDelay.PrecedingMinWiperOn));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.PrecedingMaxShort   - pCParHlafPar->TurnOnDelay.PrecedingMaxShort));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.PrecedingMaxLong    - pCParHlafPar->TurnOnDelay.PrecedingMaxLong));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.SlowOvertaking      - pCParHlafPar->TurnOnDelay.SlowOvertaking));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.Fog                 - pCParHlafPar->TurnOnDelay.Fog));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOnDelay.Blockage            - pCParHlafPar->TurnOnDelay.Blockage));

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_ON_DELAY_PARAMETERS);
  }

  /* compare TurnOffDelay parameters with default values */
  CparErr =            (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOffDelay.oncomingVehicle - pCParHlafPar->TurnOffDelay.oncomingVehicle));    /* Reset of CparErr */
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.TurnOffDelay.precedingVehicle - pCParHlafPar->TurnOffDelay.precedingVehicle));

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_OFF_DELAY_PARAMETERS);
  }

  /* compare speed parameters with default values */
  CparErr =            (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.DeactivateSpeed          - pCParHlafPar->Speed.DeactivateSpeed));     /* Reset of CparErr */
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.DeactivateSpeedHigh      - pCParHlafPar->Speed.DeactivateSpeedHigh));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.ActivateSpeed            - pCParHlafPar->Speed.ActivateSpeed));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.ActivateSpeedHigh        - pCParHlafPar->Speed.ActivateSpeedHigh));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.AlwaysActiveSpeed        - pCParHlafPar->Speed.AlwaysActiveSpeed));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.KeepOff_VeryLowSpeed     - pCParHlafPar->Speed.KeepOff_VeryLowSpeed));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.KeepOff_LowRadius        - pCParHlafPar->Speed.KeepOff_LowRadius));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.KeepOff_HighAcceleration - pCParHlafPar->Speed.KeepOff_HighAcceleration));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.KeepOff_AccTime          - pCParHlafPar->Speed.KeepOff_AccTime));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Speed.KeepOff_Delay            - pCParHlafPar->Speed.KeepOff_Delay));

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_SPEED_PARAMETERS);
  }

  /* compare dimming parameters with default values */
  CparErr =            (CML_f_IsNonZero(CPar_HlafPar_Ref.Dimming.AreaRightBorderArray[0] - pCParHlafPar->Dimming.AreaRightBorderArray[0]));  /* Reset of CparErr */
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Dimming.AreaRightBorderArray[1] - pCParHlafPar->Dimming.AreaRightBorderArray[1]));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Dimming.AreaRightBorderArray[2] - pCParHlafPar->Dimming.AreaRightBorderArray[2]));
  CparErr = CparErr || (CML_f_IsNonZero(CPar_HlafPar_Ref.Dimming.AreaRightBorderArray[3] - pCParHlafPar->Dimming.AreaRightBorderArray[3]));

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_DIMMING_PARAMETERS);
  }

  /* compare matrix parameters with default values */
  CparErr =            (CPar_HlafPar_Ref.Matrix.MaxNumGlarefreeArea != pCParHlafPar->Matrix.MaxNumGlarefreeArea);  /* Reset of CparErr */

  if (CparErr == b_TRUE)
  {
    HLA_ErrorHandling_SetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_MATRIX_PARAMETERS);
  }
   /* PRQA S 3120 -- */ 
}
