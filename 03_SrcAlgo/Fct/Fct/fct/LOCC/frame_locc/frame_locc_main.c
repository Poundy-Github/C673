/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_locc_main.c

DESCRIPTION:               Main functions for Adaptive Cruise Control (ACC) LOCC module

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.4

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_locc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) && (FCT_CFG_ACT_CODE_VERSION))

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */


/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/
/*fct veh locc and it's subcomponents initialization status*/
SET_MEMSEC_VAR(b_LoccIsInitialized)
boolean b_LoccIsInitialized = FALSE;            /*!<flag showing once completed algo cycle (!=shutdown).*/

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LoccInputCounters)
  static Locc_InputMeasCounter LoccInputCounters = {0};   /*!<aggregation struct that keeps update information for all input interfaces.*/
#endif

/* Meas freeze reference */
SET_MEMSEC_VAR(LOCC_SyncRef)
LOCC_SyncRef_t LOCC_SyncRef;                 /*!<struct that stores signal headers of all input interfaces for simulation synchronization.*/

/* frame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(LOCCFrame)
LOCCFrame_t LOCCFrame;                            /*!<internal structure that stores the status of the Algo.*/

/*! Declaration of pointers to LOCC input ports for access within this component */
SET_MEMSEC_CONST(pt_LOCC_IN_CCCP)
const ACT_CruiseControlCommandPort_t *pt_LOCC_IN_CCCP;

/*! Real existing DMC port */
SET_MEMSEC_CONST(pt_LOCC_IN_EgoVehDynCtrl)
const LongCtrlInput_t *pt_LOCC_IN_EgoVehDynCtrl;

/*! Real existing VDY port */
SET_MEMSEC_CONST(pt_LOCC_IN_EgoVehDynState)
const VehDyn_t *pt_LOCC_IN_EgoVehDynState;

/*! Declaration of generic LOCC input ports for access within this component */
SET_MEMSEC_VAR(t_LOCC_IN_EVI)
LOCC_EgoVehicleInfo_t t_LOCC_IN_EVI;

/*! Declaration of pointers to LOCC ports for access within this component */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  SET_MEMSEC_CONST(pt_LOCC_IN_VSSP)
  const ACT_CC_VehicleSpeedStatePort_t *pt_LOCC_IN_VSSP;

  SET_MEMSEC_VAR(pt_LOCC_OUT_VSCP)
  ACT_CC_VehicleSpeedCommandPort_t *pt_LOCC_OUT_VSCP;
#endif

/*! Declaration of pointers to LOCC output ports for access within this component */
SET_MEMSEC_VAR(pt_LOCC_OUT_CCSP)
ACT_CruiseControlStatePort_t *pt_LOCC_OUT_CCSP;


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

/* Port Lists for CC Subcomponent */
SET_MEMSEC_VAR(t_CC_ReqPortList)
CC_ReqPortList_t t_CC_ReqPortList;

SET_MEMSEC_VAR(t_CC_ProPortList)
CC_ProPortList_t t_CC_ProPortList;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LOCC_v_AlgoInit (void);
static void LOCC_v_SetFrameData(const LOCC_ReqPortList_t *pRequirePorts);
static void LOCC_v_SetupSyncRef(const LOCC_ReqPortList_t *pRequirePorts);
static void LOCC_v_SetupPorts(const LOCC_ReqPortList_t *pRequirePorts, const LOCC_ProPortList_t *pProvidePorts);

static void LOCC_v_Set_CC_Ports(CC_ReqPortList_t *pRequirePorts, CC_ProPortList_t *pProvidePorts);
static void LOCC_v_Assign_CC_Input_Ports (CC_ReqPortList_t *pRequirePorts);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void LOCC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
static void LOCC_v_SetCompState (AlgoCompState_t * const p_CompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
static void LOCC_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void LOCC_v_CheckProvideHeaders(const LOCC_ReqPortList_t * pRequirePorts, const LOCC_ProPortList_t * pProvidePorts);
#endif

/*! Utility function to set signal header to error */
static void LOCC_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);
static void LOCC_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void LOCC_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void LOCC_v_SetProvideHeaderStates(const LOCC_ProPortList_t * pProvidePorts, AlgoSignalState_t eSigState);
static void LOCC_v_SetProvideHeader(const LOCC_ReqPortList_t * pRequirePorts, const LOCC_ProPortList_t * pProvidePorts);

static void LOCC_v_CheckPorts(const LOCC_ReqPortList_t *pRequirePorts, const LOCC_ProPortList_t *pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
                                , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                             );

static void LOCC_v_SetErrorProvidePorts (const LOCC_ProPortList_t * pProvidePorts);

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 LOCC_v_CheckInputUpdate(const LOCC_ReqPortList_t * pRequirePorts, Locc_InputMeasCounter *pLoccInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen );
static uint32 LOCC_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                              sMeasCycleMonitor *pLastMeasCycle,
                                              float32 fTargetCycleTime, 
                                              uint8 iAcceptableDrops);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
/* ***********************************************************************
  @fn             LOCC_v_AlgoServiceAddEvent                                  */ /*!

  @brief          set RTA event via service function

  @description    set RTA event via service function

  @param[in]      RtaEvtType
  @param[in]      u_IdGlobal
  @param[in]      u_IdLocal
  @param[in]      u_OptData

  @param[in,out]  pServiceFuncts: service function pointer

  @pre            none

  @author         Christian Obst
**************************************************************************** */
#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
void LOCC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#else
void LOCC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#endif
{
  if (pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL)
  {
    (pServiceFuncts->pfRTAAlgoServiceAddEvent) (RtaEvtType, u_IdGlobal, u_IdLocal, u_OptData);
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    LOCC_v_AlgoInit                                                                                  */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       void : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         27.01.2017
  @changed         27.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_AlgoInit (void)
{
  /*--- VARIABLES ---*/

  LOCCFrame.bFirstCycleDone   = FALSE;
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetOperationMode                                                                          */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[in]       t_LOCCOpModeValue : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         26.01.2017
  @changed         26.01.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOCC_v_SetOperationMode(const LOCCState_t t_LOCCOpModeValue)
{
  LOCCFrame.eLOCCState = t_LOCCOpModeValue;
}

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             LOCC_v_SetAlgoErrorBuffer */ /*! 
  @brief          Set the Algo Error Buffer
  @description    Set the ErrorQualifier to pErrorBuffer if it is more severe than the stored one.
                  It's not possible to change to a lower priority than already set.
  @param[in]      ErrorQualifier : the Error to set
  @param[in,out]  pErrorBuffer   : pointer to the buffered error
  @pre            None
  @author         Christian Obst
**************************************************************************** */
static void LOCC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
{
  if ( (pErrorBuffer != NULL) && (ErrorQualifier != ALGO_QUAL_OK) ) /*pointer check and entry condition*/
  {
    if (*pErrorBuffer == ALGO_QUAL_OK)
    {
      *pErrorBuffer = ErrorQualifier;
    }
    else
    {
      if (ErrorQualifier < *pErrorBuffer)
      {
        *pErrorBuffer = ErrorQualifier;
      }
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* **********************************************************************
  @fn           LOCC_v_SetCompState                                  */ /*!
  @brief        Set the Algo Component State.
  @description  Set the Algo Component State based on scheduler request and internal status.
  @param[out]   p_CompState : pointer to Algo Component State that shall be set.
  @param[in]    ScheduledOpMode : operation mode given by global scheduler.
  @param[in]    BufferedQualifier : internal buffer for AlgoQualifier (error status).
  @pre          Algo ran, component error states are set.
  @return       none
  @author       Christian Obst
**************************************************************************** */
static void LOCC_v_SetCompState (AlgoCompState_t * const p_CompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
{
#if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) )
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: REMOVE REDEFINITION (obviously the RTE is updated)!")// PRQA S 3116
#endif
#ifndef MFC_VERSION_INFO_LENGTH
#define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
#endif 

  /* The define MFC_VERSION_INFO_LENGTH is to be renamed. The name has to be more generalized regarding the used thechnology */
#if COMP_STATE_INTFVER > 3
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));
#else
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
#endif
  if (p_CompState != NULL)
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(p_CompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    p_CompState->uiAlgoVersionNumber = LOCCFrame.Versions.uiLocc;
#if COMP_STATE_INTFVER > 2u
    p_CompState->uiApplicationNumber = 0u;
    p_CompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    p_CompState->ApplicationNumber = 0u;
    p_CompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (LOCCFrame.eLOCCState)
    {
    case LOCC_INIT:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        p_CompState->eCompState = COMP_STATE_RUNNING;
        p_CompState->eErrorCode = COMP_ERROR_NO_ERROR;
        p_CompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*some issue occurred either no pVehCtrlData pointer or internal init*/
        p_CompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        p_CompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          p_CompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          p_CompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case LOCC_RUN:
      p_CompState->eCompState = COMP_STATE_RUNNING;
      p_CompState->eErrorCode = COMP_ERROR_NO_ERROR;
      p_CompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case LOCC_SHUTDOWN:
      /*in case on missing input signal pointer or invalid signal status*/
    default:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        p_CompState->eCompState = COMP_STATE_RUNNING;
        p_CompState->eErrorCode = COMP_ERROR_NO_ERROR;
        p_CompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*internal recoverable error*/
        p_CompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        p_CompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          p_CompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          p_CompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*************************************************************************************************************************
  Functionname:    LOCC_v_CheckPortUpdated                                                                          */ /*!

  @brief           Check if input interface update is missing.

  @description     Checks if update is older than allowed (target cycle time and acceptable drops).
                   FCTVeh cycle time is taken from FCT_VEH_TARGET_CYCLE_TIME.

  @return          static uint32 

  @param[in]       *pInputPortMeasCycle : current timestamp of the interface. [AlgoDataTimeStamp_t as per Rte_Type.h]
  @param[in,out]   *pLastMeasCycle : pointer to the internal stored update information.
                      pLastMeasCycle->uiTimeStamp : [AlgoDataTimeStamp_t as per Rte_Type.h]
                      pLastMeasCycle->uiLastUpdateCounter : [full range of unsigned char]
  @param[in]       fTargetCycleTime : target cycle time for the input interface to check. [Full range of float32]
  @param[in]       iAcceptableDrops : allowed number of dropped providing frame updates. [Full range of unsigned char]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
                   
  @pre             -
  @post            -

  @created         -
  @changed         2/11/2016

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 LOCC_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                      sMeasCycleMonitor *pLastMeasCycle,
                                      float32 fTargetCycleTime, 
                                      uint8 iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /*20150327 C. Obst: intended behavior to cast float to uInt. fractional part is neglectible.*/
  /*PRQA S 4119 3*/
  const AlgoDataTimeStamp_t uiCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * 1000000u);         /*conversion second to microsecond*/
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiCycleTimeUs ); /*accepted drops + current Cycle + 0.5 safety margin*/
  AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_VEH_TARGET_CYCLE_TIME * (float32)1000000u);

  uint32 uErrorFlag = 0u;

  /*Calculating Time since last input*/
  if ( *pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp )
  {
    /*OVERFLOW*/
    uiDeltaTimeUs = ( (0u)^(0u)) - (pLastMeasCycle->uiTimeStamp - *pInputPortMeasCycle);
  }
  else 
  {
    /*NO Overflow*/
    uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
  }
  
  if ( uiDeltaTimeUs == 0u)
  {
    /*NO update*/
    if ( ((pLastMeasCycle->uiLastUpdateCounter + 1) * uiTargetCycleTimeCallUs)  < uiMaxAcceptableDropTimeUs)
    {
      /*no update needed (max time including drops not reached)*/
      pLastMeasCycle->uiLastUpdateCounter += 1u;   /*increment update counter*/
    }
    else
    {
      /*update expected*/
      uErrorFlag = 1u;        /*raise error*/
    }
  }
  else
  {
    /*update*/
    if ( uiDeltaTimeUs > uiMaxAcceptableDropTimeUs )
    {
      /*skipped cycle*/
      uErrorFlag = 1u;        /*raise error*/
    }
    else
    {
      /*new cycle received in time*/
      pLastMeasCycle->uiLastUpdateCounter = 0u;    /*reset update counter*/
    }
    pLastMeasCycle->uiTimeStamp = *pInputPortMeasCycle;
  }
  return uErrorFlag;
}
#endif

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*************************************************************************************************************************
  Functionname:    LOCC_v_CheckInputUpdate                                                                          */ /*!

  @brief           Checks for frame drops and frozen input interfaces based on provided timestamps.

  @description     calls the Update Checker function for every used input interface and writes it to the InputCounters struct.

  @return          static uint32 : number of interfaces which are not updated longer than debounce time.

  @param[in]       pRequirePorts : input interface provided to FCTVeh. 
  @param[in]       pFCTVehInputCounters : internal memory struct to store update information.
  @param[in]       fTargetCycleTimeVeh : target cycle time for the FCTVeh Task. 
  @param[in]       fTargetCycleTimeSen : target cycle time for the Camera (FCTSen) Task (Sensor cycle).

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_LOCC_COMPONENT : Configuration switch for enabling LOCC processing
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
                                                 port structures, even if the current configuration does not use them. This 
                                                 enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_COLLISION_DETECTION                : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION       : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the 
                                                            SW environment provides this information
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface
  @c_switch_full   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters

  @pre             -
  @post            -

  @created         -
  @changed         2/11/2016

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update).

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 LOCC_v_CheckInputUpdate(const LOCC_ReqPortList_t * pRequirePorts, Locc_InputMeasCounter *pLoccInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen)
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
  return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             LOCC_v_SetDem                                  */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTVehServiceFuncts connected to input service ports
  @todo           review
  @author         Christian Obst
**************************************************************************** */
void LOCC_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pFCTVehServiceFuncts != NULL) && (pFCTVehServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pFCTVehServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetupPorts                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       LOCC_ReqPortList_pt pRequirePorts
  @param[in]       LOCC_ProPortList_pt pProvidePorts

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         14.06.2017
  @changed         14.06.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-8382-9699-839
*************************************************************************************************************************/
static void LOCC_v_SetupPorts(const LOCC_ReqPortList_t *pRequirePorts, const LOCC_ProPortList_t *pProvidePorts)
{
/*! Assignment of external pointers to LOCC input ports for access within this component */
  pt_LOCC_IN_CCCP = pRequirePorts->pt_LOCC_IN_CCCP;
  pt_LOCC_IN_EgoVehDynState = pRequirePorts->pt_LOCC_IN_EgoVehDynState;
  pt_LOCC_IN_EgoVehDynCtrl  = pRequirePorts->pt_LOCC_IN_EgoVehDynCtrl;

/*! Assignment of external pointers to LOCC ports for access within this component */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  pt_LOCC_IN_VSSP = pRequirePorts->pt_LOCC_IN_VSSP;
  pt_LOCC_OUT_VSCP = pProvidePorts->pt_LOCC_OUT_VSCP;
#endif

/*! Assignment of external pointers to LOCC output ports for access within this component */
  pt_LOCC_OUT_CCSP = pProvidePorts->pt_LOCC_OUT_CCSP;
}


/*************************************************************************************************************************
  Functionname:    LOCC_v_FillSigHeader                                                                             */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in,out]   pSigHeader : 
  @param[in]       pSourceHdr : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = LOCCFrame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetSigHeaderState                                                                         */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in,out]   pSigHeader : 
  @param[in]       eSigState : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus            = eSigState;
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetProvideHeaderStates                                                                    */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pProvidePorts : 
  @param[in]       eSigState : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetProvideHeaderStates(const LOCC_ProPortList_t * pProvidePorts, AlgoSignalState_t eSigState) 
{

  /* Todo: Write for new ports */
_PARAM_UNUSED(pProvidePorts);
_PARAM_UNUSED(eSigState);
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetProvideHeader                                                                          */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetProvideHeader(const LOCC_ReqPortList_t *pRequirePorts, const LOCC_ProPortList_t *pProvidePorts) 
{
  /* Todo: Write for new ports */
  _PARAM_UNUSED(pProvidePorts);
  _PARAM_UNUSED(pRequirePorts);
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetSigHeaderError                                                                         */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in,out]   pSigHeader : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiCycleCounter        = LOCCFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    LOCC_v_CheckProvideHeader                                                                        */ /*!

  @brief           Check whether the signal header has changed during the call of the components

  @description     Detailed Design

  @return          static void

  @param[in]       pProvidedSigHeader : 
  @param[in]       pReceivedSigHeader : 

  @pre             None ?
  @post            No changes ?

  @created         23.02.2016
  @changed         23.02.2016

  @todo            Remove this entire line if not needed

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOCC_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
{
  _PARAM_UNUSED(pProvidedSigHeader);
  _PARAM_UNUSED(pReceivedSigHeader);

  CML_ASSERT(    (pProvidedSigHeader->uiMeasurementCounter == pReceivedSigHeader->uiMeasurementCounter)
              && (pProvidedSigHeader->uiTimeStamp          == pReceivedSigHeader->uiTimeStamp         )
           /* && (pProvidedSigHeader->eSigStatus           != AL_SIG_STATE_INVALID                    ) */);
}
#endif

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    LOCC_v_CheckProvideHeaders                                                                       */ /*!

  @brief           Call the check of the SigHeader for all used ports

  @return          static void

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @pre             None ?
  @post            No changes ?

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOCC_v_CheckProvideHeaders(const LOCC_ReqPortList_t * pRequirePorts, const LOCC_ProPortList_t * pProvidePorts) 
{
  /* Todo: Write for new ports */

}
#endif

/*************************************************************************************************************************
  Functionname:    LOCC_v_CheckPorts                                                                           */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          -

  @param[in]       pRequirePorts : 
  @param[in]       (FCT_CFG_USE_SERVICE_POINTER_FUNCTS : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_CheckPorts( const LOCC_ReqPortList_t * pRequirePorts, const LOCC_ProPortList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                  , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                  , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                                  ) 
{
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /*assign Service functions to internal global alias no matter if NULL or not (used for DEM events)*/
  pFCTVehServiceFuncts = pServiceFuncts;
#endif

  /* Verify that all request port pointers are set to non-null */
  if(
    (pRequirePorts == NULL)
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    /* Save ServiceFunction Pointer */
    || (pServiceFuncts == NULL)
    || (pServiceFuncts->pfMeasFreeze == NULL)
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    || (pServiceFuncts->pfMeasStartFuncCycle == NULL)
#endif
#if (FCT_CFG_RTA_PROFILING)
    || (pServiceFuncts->pfRTAAlgoServiceAddEvent == NULL)
#endif
#if (FCT_CFG_USE_DEM)
    || (pServiceFuncts->pfDem_SetEventStatus == NULL)
#endif
#endif
    /* Todo: Write for new ports */
    || (pRequirePorts->pt_LOCC_IN_Ctrl == NULL)

    )
  {
    /* Some request port pointer is NULL => DEM and shutdown */

#if (FCT_CFG_USE_DEM)
    /*validity of service pointer isn't clear here*/
    LOCC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /* setup the Algo Error Buffer */
    LOCC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    /* shutdown the system */
    LOCC_v_SignalErrorShutdown(FALSE);
  }
  else
  {
    /* Verify that provide port buffer pointers are set (non-null) */
    if ((pProvidePorts == NULL) || (pProvidePorts->pt_LOCC_OUT_CCSP == NULL))
    {
#if (FCT_CFG_USE_DEM)
      /* Some provide port pointer is NULL => DEM -> shutdown */
      LOCC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      LOCC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      LOCC_v_SignalErrorShutdown(FALSE);
    }
    else
    {
#if (FCT_CFG_USE_DEM)
      /* receive and provide ports are fine */
      LOCC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
    }

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
    /* no NullPointer in request ports*/
    /* check for SignalState in requestPorts*/
    if(pRequirePorts->pt_LOCC_IN_EgoCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    {
      /*signal state broken -> no dem only shutdown*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /* setup the Algo Error Buffer */
      LOCC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      /* shutdown the system */
      LOCC_v_SignalErrorShutdown(FALSE);
    }
#endif /*FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK*/
  }
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetErrorProvidePorts                                                                      */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pProvidePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetErrorProvidePorts (const LOCC_ProPortList_t * pProvidePorts)
{
  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pVehCompState != NULL)
    {
      LOCC_pCompState                  = pProvidePorts->pVehCompState;
#if COMP_STATE_INTFVER > 2u
      LOCC_pCompState->uiVersionNumber  = COMP_STATE_INTFVER;
#else
      LOCC_pCompState->uVersionNumber  = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      LOCC_pCompState = NULL;
    }
#endif

    /* Todo: Write for new ports */
#if (ACT_CFG_CC_VSC_PORT_CNT)
    if(pProvidePorts->pt_LOCC_OUT_VSCP != NULL)
    {
      pProvidePorts->pt_LOCC_OUT_VSCP->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
      LOCC_v_SetSigHeaderError(&pProvidePorts->pt_LOCC_OUT_VSCP->sSigHeader);
    }
#endif
  }
  else
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOCC_pCompState = NULL;
#endif
  }
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SetupSyncRef                                                                              */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pRequirePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetupSyncRef(const LOCC_ReqPortList_t *pRequirePorts)
{
  /* setting whole syncref to zero */
  (void)memset(&LOCC_SyncRef, 0, sizeof(LOCC_SyncRef));

  if (pRequirePorts != NULL)
  {
    /* pt_LOCC_IN_Ctrl */
    if (pRequirePorts->pt_LOCC_IN_Ctrl != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      LOCC_v_FillSigHeader(&(LOCC_SyncRef.sSigHeader), &(pRequirePorts->pt_LOCC_IN_Ctrl->sSigHeader));
      LOCC_v_SetSigHeaderState(&LOCC_SyncRef.sSigHeader, AL_SIG_STATE_OK);

      LOCC_SyncRef.t_SH_CTRL = pRequirePorts->pt_LOCC_IN_Ctrl->sSigHeader;
    }
    else
    {
      LOCC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_LOCC_IN_CCCP */
    if (pRequirePorts->pt_LOCC_IN_CCCP != NULL)
    {
      LOCC_SyncRef.t_LOCC_IN_CCCP = pRequirePorts->pt_LOCC_IN_CCCP->sSigHeader;
    }
    else
    {
      LOCC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (ACT_CFG_CC_VSC_PORT_CNT)
    /* pt_LOCC_IN_CC_VSSP */
    if (pRequirePorts->pt_LOCC_IN_VSSP != NULL)
    {
      LOCC_SyncRef.t_LOCC_IN_VSSP = pRequirePorts->pt_LOCC_IN_VSSP->sSigHeader;
    }
    else
    {
      LOCC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    /* pt_LOCC_IN_EgoVehDynCtrl */
    if (pRequirePorts->pt_LOCC_IN_EgoVehDynCtrl != NULL)
    {
      LOCC_SyncRef.t_EgoVehDynCtrl = pRequirePorts->pt_LOCC_IN_EgoVehDynCtrl->sSigHeader;
    }
    else
    {
      LOCC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_LOCC_IN_EgoVehDynState */
    if (pRequirePorts->pt_LOCC_IN_EgoVehDynState != NULL)
    {
      LOCC_SyncRef.t_EgoVehDynState = pRequirePorts->pt_LOCC_IN_EgoVehDynState->sSigHeader;
    }
    else
    {
      LOCC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    LOCC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
}


/*************************************************************************************************************************
  Functionname:    LOCC_v_Set_CC_Ports                                                                              */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         05.07.2017
  @changed         05.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void LOCC_v_Set_CC_Ports(CC_ReqPortList_t *pRequirePorts, CC_ProPortList_t *pProvidePorts)
{
  /* pt_LOCC_IN_CCCP */
  pRequirePorts->t_CC_IN_CCCP.pt_CCC = &(pt_LOCC_IN_CCCP->t_Command);
  pRequirePorts->t_CC_IN_CCCP.pt_FD  = &(pt_LOCC_IN_CCCP->t_Degrade);

  /* t_LOCC_IN_EVI */
//pRequirePorts->t_CC_IN_EVIP.pt_SigHeader = &(LOCC_SyncRef.t_EgoVehDynCtrl);   /* TODO - Select correct Signal Header */
  pRequirePorts->t_CC_IN_EVIP.pt_SigHeader = &(LOCC_SyncRef.t_EgoVehDynState);  /* TODO - Select correct Signal Header */
  pRequirePorts->t_CC_IN_EVIP.pt_EVI = &t_LOCC_IN_EVI;

#if (ACT_CFG_CC_VSC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_CC_VSC_PORT_CNT; i++)
  {
    /* t_LOCC_IN_VSSP */
    pRequirePorts->at_CC_IN_VSSP[i].pt_VSS = &(pt_LOCC_IN_VSSP->at_VSS[i]);

    /* t_LOCC_OUT_VSCP */
    pProvidePorts->at_CC_OUT_VSCP[i].pt_VSC = &(pt_LOCC_OUT_VSCP->at_VSC[i]);
  }
}
#endif

  /* pt_LOCC_OUT_CCSP */
  pProvidePorts->t_CC_OUT_CCSP.pt_CCS = &(pt_LOCC_OUT_CCSP->t_State);
}


/*************************************************************************************************************************
  Functionname:    LOCC_v_Assign_CC_Input_Ports                                                                        */ /*!

  @brief           Transformation and Assignment of existing Input Ports to generic LOC Ports

  @return          -

  @param           - 

  @pre             None ?
  @post            No changes ?

  @created         06.07.2017
  @changed         06.07.2017

  @author          Wolfgang Borgs |  | +49 (8382) 9699-839
*************************************************************************************************************************/
static void LOCC_v_Assign_CC_Input_Ports (CC_ReqPortList_t *pRequirePorts)
{
  if (pRequirePorts->t_CC_IN_EVIP.pt_SigHeader->eSigStatus == AL_SIG_STATE_OK)
  {
    t_LOCC_IN_EVI.b_Valid = TRUE;
    t_LOCC_IN_EVI.b_StandStill = pt_LOCC_IN_EgoVehDynCtrl->KinCtrlDynInput.stand_still_detected;
    t_LOCC_IN_EVI.b_Override_Accel = pt_LOCC_IN_EgoVehDynCtrl->KinCtrlDynInput.driver_override_accel_pedal;
    t_LOCC_IN_EVI.b_Override_Decel = pt_LOCC_IN_EgoVehDynCtrl->KinCtrlDynInput.driver_override_decel_pedal;
    t_LOCC_IN_EVI.b_VeloDispUnitKmh = (pt_LOCC_IN_EgoVehDynCtrl->DisplayOutput.speed_unit == SPD_UNIT_KMH);
    t_LOCC_IN_EVI.f_LongVeloDisplay = (float)pt_LOCC_IN_EgoVehDynCtrl->DisplayOutput.speedometer_speed / (float)Velocity_s;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
    t_LOCC_IN_EVI.f_LongVeloReal = pt_LOCC_IN_EgoVehDynState->Longitudinal.Velocity;
    t_LOCC_IN_EVI.f_LongAcceleration = pt_LOCC_IN_EgoVehDynState->Longitudinal.Accel;
#else
    t_LOCC_IN_EVI.f_LongVeloReal = pt_LOCC_IN_EgoVehDynState->Longitudinal.MotVar.Velocity;
    t_LOCC_IN_EVI.f_LongAcceleration = pt_LOCC_IN_EgoVehDynState->Longitudinal.MotVar.Accel;
#endif
    t_LOCC_IN_EVI.f_DriverIntendCurve = pt_LOCC_IN_EgoVehDynState->Lateral.DrvIntCurve.Curve;
  }
  else
  {
    t_LOCC_IN_EVI.b_Valid = FALSE;
    t_LOCC_IN_EVI.b_StandStill = FALSE;
    t_LOCC_IN_EVI.b_Override_Accel = FALSE;
    t_LOCC_IN_EVI.b_Override_Decel = FALSE;
    t_LOCC_IN_EVI.b_VeloDispUnitKmh = FALSE;
    t_LOCC_IN_EVI.f_LongVeloDisplay = 0.0f;
    t_LOCC_IN_EVI.f_LongVeloReal = 0.0f;
    t_LOCC_IN_EVI.f_LongAcceleration = 0.0f;
    t_LOCC_IN_EVI.f_DriverIntendCurve = 0.0f;
  }
}


/*************************************************************************************************************************
  Functionname:    LOCC_v_SetFrameData                                                                              */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pRequirePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         27.01.2017
  @changed         27.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOCC_v_SetFrameData(const LOCC_ReqPortList_t *pRequirePorts) 
{
  if ((pRequirePorts != NULL) && (pRequirePorts->pt_LOCC_IN_Ctrl != NULL))
  {
    LOCCFrame.eLOCCOpMode = pRequirePorts->pt_LOCC_IN_Ctrl->OpMode;
  }
  else
  {
    LOCCFrame.eLOCCOpMode = FCT_MOD_SHUTDOWN;
    LOCC_v_SignalErrorShutdown(FALSE);
  }
  LOCCFrame.uiCycleCounter++;

  /* setup sub-module version numbers */

  LOCCFrame.Versions.FCT_LOCC_VERSION_AS_TEXT  =   LOCC_SW_VERSION_NUMBER; //TODO:define for Locc
  LOCCFrame.Versions.uiLocc = LOCC_SW_VERSION_NUMBER; //TODO:define for Locc

}


/*************************************************************************************************************************
  Functionname:    LOCC_v_Exec                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[in]       p_RequirePorts : 
  @param[in,out]   t_FCTVehFrameFCTOpMode : 
  @param[in]       *p_ServiceFuncts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         24.01.2017
  @changed         24.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void LOCC_v_Exec(const LOCC_ReqPortList_t * p_RequirePorts, const LOCC_ProPortList_t * p_ProvidePorts, const FCT_OP_MODE_t t_OpMode, const AS_t_ServiceFuncts *p_ServiceFuncts)
#else
void LOCC_v_Exec(const LOCC_ReqPortList_t * p_RequirePorts, const LOCC_ProPortList_t * p_ProvidePorts, const FCT_OP_MODE_t t_OpMode)
#endif
{
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
  const float32 fCycleTimeSen = FCT_VEH_TARGET_CYCLE_TIME;
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
  if (p_ServiceFuncts != NULL)
  {
    /* Sends RTA-Start event for whole procedure runtime */
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOCC_RTA_PROCESS, 0);
    /* Sends RTA-Start event for data preparation runtime */
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOCC_RTA_PREPRE_PROCESS, 0);
  }
#endif

  /*---------------------------------------------------------------------------*/
  /* Start data preparation                                                    */
  /*---------------------------------------------------------------------------*/

  /* update Frame Data and set OpMode */
  LOCC_v_SetFrameData(p_RequirePorts);

  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  /* set the process states for all subcomponents */
  LOCC_v_ProcessStates(t_OpMode);
  
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  LOCC_pServiceFuncts = p_ServiceFuncts;
#endif

  /* check for NULLpointer => trigger ErrorShutdown */
  LOCC_v_CheckPorts(p_RequirePorts, p_ProvidePorts /* Includes Error Management and OP-Mode-Changing */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    , &AlgoErrorBuffer
#endif
    );

  /* setup the input port header sync structure */
  LOCC_v_SetupSyncRef(p_RequirePorts); 

  if ((LOCCFrame.eLOCCOpMode != FCT_MOD_SHUTDOWN) && (LOCCFrame.eLOCCState != FCT_VEH_SHUTDOWN))
  {
    /*Init in init Mode*/
    if (LOCCFrame.eLOCCState == FCT_VEH_INIT)
    {
      LOCC_v_AlgoInit ();
    }
    else
    {
      LOCCFrame.bFirstCycleDone = TRUE;
    }
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
    if ( LOCC_v_CheckInputUpdate(p_RequirePorts, &LoccInputCounters,FCT_VEH_CYCLE_TIME, fCycleTimeSen) != 0u )   /*error condition*/
    {
      LOCC_v_SetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
    }
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

     /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
    /* Opmode indicates liveliness => setup port pointers */
    LOCC_v_SetupPorts(p_RequirePorts, p_ProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start */
    if ((p_ServiceFuncts != NULL) && ((p_ServiceFuncts->pfMeasStartFuncCycle) != NULL))
    {
      (p_ServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
    }
#endif
    /* set all the signal headers of all provide ports to invalid*/
   LOCC_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);
   LOCC_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);
    /* Sends RTA-Start event for Longitudinal control runtime */
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOCC_RTA_PREPRE_PROCESS, 0);
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOCC_RTA_CC_PROCESS, 0);
#endif

    /* New architecture */
    /* Assign Port Lists of CC Subcomponent */
    LOCC_v_Set_CC_Ports(&t_CC_ReqPortList, &t_CC_ProPortList);

    /* Assign Generic Input Port Members for CC Subcomponent */
    LOCC_v_Assign_CC_Input_Ports(&t_CC_ReqPortList);

    /* Call Process of CC Subcomponent */
    CC_v_Process(&t_CC_ReqPortList, &t_CC_ProPortList);

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOCC_RTA_CC_PROCESS, 0);
#endif

#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
    LOCC_v_CheckProvideHeaders(p_RequirePorts, p_ProvidePorts); 
#endif
    /* Set all signal header values again to avoid errors if a component accidentialy overwrite the SigHeader*/
    LOCC_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);
	
#if (FCT_MEASUREMENT)
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-Start event for Process Measfreeze runtime */
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOCC_RTA_PROCESSFREEZE, 0);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTVeh_v_LOCCSetCompState (LOCC_pCompState, p_RequirePorts->pVehCtrlData->OpMode, AlgoErrorBuffer);
#endif
    /* Process meas freezes */
    LOCC_v_ProcessMeasFreeze();

    /*computation chain ran through. FCT Vehicle is initialized or running.*/
    b_LoccIsInitialized  = TRUE;

    /* Sends RTA-End event for Longitudinal control runtime */
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOCC_RTA_PROCESSFREEZE, 0);
#endif
#endif /* FCT_MEASUREMENT */
  }
   else  /************************* end of non-error path, beginning of error path *************************/
   {
     /* FCT_MOD_SHUTDOWN => fill invalidate the available provide ports and fill whole sigHeader */

     LOCC_v_SetErrorProvidePorts(p_ProvidePorts);
#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
     if ((p_ServiceFuncts != NULL) && (p_ServiceFuncts->pfMeasStartFuncCycle != NULL))
     {
       /* send MTS Freeze Cycle Start if Service is available */
       (p_ServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
     }
#endif

     /* Init LOCC Algo */
     LOCC_v_AlgoInit();

#if (FCT_CFG_USE_ALGOCOMPSTATE)
     /* ERROR path! Need to check existence of pointers */
     if (LOCC_pCompState != NULL)
     {
       if ( (p_RequirePorts != NULL) && (p_RequirePorts->pVehCtrlData != NULL) )
       {
         LOCC_v_SetCompState (LOCC_pCompState, p_RequirePorts->pVehCtrlData->OpMode, AlgoErrorBuffer);
       }
       else
       {
         LOCC_v_SetCompState (LOCC_pCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
       }
     }
#endif
    /* make sure in error case init of sub components is performed next cycle */
    b_LoccIsInitialized = FALSE;

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
     if (p_ServiceFuncts != NULL)
     {
       /* Sends RTA-End event for data preparation runtime in errorcase*/
       LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOCC_RTA_PROCESS, 0);
     }
#endif
   } /*********************** end of error path, beginning common *******************************/
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
   if (p_ServiceFuncts != NULL)
   {
     /* Sends RTA-Start event for Frame Measfreeze runtime */
     LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOCC_RTA_FRAMEFREEZE, 0);
   }
#endif
   /* Freeze frame meas data */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
   /* Safeguard for NULL-Pointer */
   if ( (p_ServiceFuncts != NULL) 
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
     && (p_ServiceFuncts->pfMeasStartFuncCycle != NULL)
#endif
     && (p_ServiceFuncts->pfMeasFreeze != NULL)
     && (pFCTVehServiceFuncts != NULL)
     && (pFCTVehServiceFuncts->pfMeasFreeze != NULL) )
   {
     LOCC_v_FrameFreeze();
   }
#else
   LOCC_v_FrameFreeze();
#endif
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
   if (p_ServiceFuncts != NULL)
   {
     /* Sends RTA-End event for Frame Measfreeze runtime */
     LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOCC_RTA_FRAMEFREEZE, 0);
     /* Sends RTA-End event for whole procedure runtime */
     LOCC_v_AlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOCC_RTA_PROCESS, 0);
   }
#endif
}

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) && (FCT_CFG_ACT_CODE_VERSION)*/

