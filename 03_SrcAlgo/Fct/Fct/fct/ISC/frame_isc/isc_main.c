/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC (Adaptive Cruise Control - Interface and State Coordinator)

PACKAGENAME:               isc_main.c

DESCRIPTION:               Main functions for Adaptive Cruise Control (ACC) ISC module in FCT_VEH task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.12 $

---*/ /*---
CHANGES:                    $Log: isc_main.c  $
CHANGES:                    Revision 1.12 2018/06/27 10:06:46CEST uidj5069 
CHANGES:                    Propagation of new Port to SM Module
CHANGES:                    Revision 1.11 2018/06/11 15:02:02CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    New Ports added for LOPC based Start Coordination
CHANGES:                    Revision 1.10 2018/03/16 11:15:02CET Mistry, Niraj (uidq5738) 
CHANGES:                    Bufix version usage
CHANGES:                    Revision 1.9 2018/03/14 09:55:17CET Mistry, Niraj (uidq5738) 
CHANGES:                    Simplified cdl check (similar to EM implementation)
CHANGES:                    Revision 1.8 2018/02/28 11:53:30CET Mistry, Niraj (uidq5738) 
CHANGES:                    Sigheader and Versionnumber for ports made generic
CHANGES:                    Revision 1.7 2017/12/01 13:09:55CET Umesh Babu, Harsha (uidj3583) 
CHANGES:                    Fix DevGate Include Issue with string.h
CHANGES:                    Revision 1.6 2017/11/20 09:23:31CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Renaming to RTE Port Type Names
CHANGES:                    Revision 1.5 2017/10/20 14:22:44CEST Mistry, Niraj (uidq5738) 
CHANGES:                    Usage of ISC version number
CHANGES:                    Revision 1.4 2017/10/12 16:23:46CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Ports and Functionality for Target Control (ACC) added
CHANGES:                    Revision 1.3 2017/10/11 08:03:36CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Updates for GEN 4
CHANGES:                    Revision 1.2 2017/10/05 08:32:31CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Revision for ACC GEN 4
CHANGES:                    Revision 1.1 2017/03/10 10:48:13CET Koschalka, Mike (uidg3250) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOKMC_LongitudinalKinematicMotionControl/04_Engineering/01_Source_Code/LOKMC/frame_lokmc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lokmc/project.pj
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "isc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))

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
/*fct veh isc and it's subcomponents initialization status*/
SET_MEMSEC_VAR(b_IscIsInitialized)
boolean b_IscIsInitialized = FALSE;            /*!<flag showing once completed algo cycle (!=shutdown).*/

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(FCTVehIscInputCounters)
static Isc_InputMeasCounter FCTVehIscInputCounters = {0};   /*!<aggregation struct that keeps update information for all input interfaces.*/
#endif

/* start of definition for local alias for external ports (shall be same same than provide and receive ports */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(ISC_pServiceFuncts)
const AS_t_ServiceFuncts *ISC_pServiceFuncts;       /*!<internal pointer to external service functions interface.*/
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(ISC_pCompState)
static AlgoCompState_t  *ISC_pCompState;  /*!<internal pointer to external Algo Component State OUTPUT interface.*/
#endif

/* Meas freeze reference */
SET_MEMSEC_VAR(ISC_SyncRef)
ISC_SyncRef_t ISC_SyncRef;                 /*!<struct that stores signal headers of all input interfaces for simulation synchronization.*/

/* frame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(ISCFrame)
ISCFrame_t ISCFrame;                            /*!<internal structure that stores the status of the Algo.*/


/*! Declaration of pointers to ISC input ports for access within this component */
SET_MEMSEC_CONST(pt_ISC_IN_IIP)
const ACT_ISC_InformationPort_t           *pt_ISC_IN_IIP;

SET_MEMSEC_CONST(pt_ISC_IN_ICP)
const ACT_ISC_CommandPort_t               *pt_ISC_IN_ICP;

#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_CONST(pt_ISC_IN_CCSP)
  const ACT_CruiseControlStatePort_t      *pt_ISC_IN_CCSP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  SET_MEMSEC_CONST(pt_ISC_IN_TCSP)
  const TargetControlStatePort_t          *pt_ISC_IN_TCSP;
#endif

SET_MEMSEC_VAR(pt_ISC_IN_LVSP)
const ACT_LogicVehicleStatePort_t         *pt_ISC_IN_LVSP;

/*! Declaration of pointers to ISC output ports for access within this component */
#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(pt_ISC_OUT_CCCP)
  ACT_CruiseControlCommandPort_t          *pt_ISC_OUT_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  SET_MEMSEC_VAR(pt_ISC_OUT_TCCP)
  TargetControlCommandPort_t              *pt_ISC_OUT_TCCP;
#endif

SET_MEMSEC_CONST(pt_ISC_OUT_LVCP)
ACT_LogicVehicleCommandPort_t             *pt_ISC_OUT_LVCP;

SET_MEMSEC_VAR(pt_ISC_OUT_ISP)
ACT_ISC_StatusPort_t                      *pt_ISC_OUT_ISP;


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

/* Local Ports HMI => SM */
SET_MEMSEC_VAR(t_ISC_LOC_SMC)
ISC_SM_Command_t t_ISC_LOC_SMC;


/* Local Ports SM => HMI */
SET_MEMSEC_VAR(t_ISC_LOC_SMS)
ISC_SM_Status_t t_ISC_LOC_SMS;


/* Port Lists for HMI Subcomponent */
SET_MEMSEC_VAR(t_HMI_ReqPortList)
HMI_ReqPortList_t t_HMI_ReqPortList;

SET_MEMSEC_VAR(t_HMI_ProPortList)
HMI_ProPortList_t t_HMI_ProPortList;


/* Port Lists for SM Subcomponent */
SET_MEMSEC_VAR(t_SM_ReqPortList)
SM_ReqPortList_t t_SM_ReqPortList;

SET_MEMSEC_VAR(t_SM_ProPortList)
SM_ProPortList_t t_SM_ProPortList;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void ISC_v_AlgoInit (void);
static void ISC_v_SetFrameData(const ISC_ReqPortList_t *pRequirePorts);
static void ISC_v_SetupSyncRef(const ISC_ReqPortList_t *pRequirePorts);
static void ISC_v_SetupPorts(const ISC_ReqPortList_t *pRequirePorts, const ISC_ProPortList_t *pProvidePorts);

static void ISC_v_Set_HMI_Ports(HMI_ReqPortList_t *pRequirePorts, HMI_ProPortList_t *pProvidePorts);
static void ISC_v_Set_SM_Ports(SM_ReqPortList_t *pRequirePorts, SM_ProPortList_t *pProvidePorts);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void ISC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
static void ISC_v_SetCompState (AlgoCompState_t * const pVehCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
static void ISC_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void ISC_v_CheckProvideHeaders(const ISC_ReqPortList_t * pRequirePorts, const ISC_ProPortList_t * pProvidePorts);
#endif

/*! Utility function to set signal header to error */
static void ISC_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);
static void ISC_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void ISC_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void ISC_v_SetProvideHeaderStates(const ISC_ProPortList_t * pProvidePorts, AlgoSignalState_t eSigState);
static void ISC_v_SetProvideHeader(const ISC_ReqPortList_t * pRequirePorts, const ISC_ProPortList_t * pProvidePorts);

static void ISC_v_CheckPorts( const ISC_ReqPortList_t *pRequirePorts, const ISC_ProPortList_t *pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
                                  , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                  , GenAlgoQualifiers_t *const pErrorBuffer
#endif
  );
static void ISC_v_SetErrorProvidePorts (const ISC_ProPortList_t * pProvidePorts);

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 ISC_v_CheckInputUpdate(const ISC_ReqPortList_t * pRequirePorts, Isc_InputMeasCounter *pFCTVehInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen );
static uint32 ISC_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                              sMeasCycleMonitor *pLastMeasCycle,
                                              float32 fTargetCycleTime, 
                                              uint8 iAcceptableDrops);

#endif
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
/* ***********************************************************************
  @fn             ISCAlgoServiceAddEvent                                  */ /*!

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
void ISCAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#else
void ISCAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#endif
{
  if (pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL)
  {
    (pServiceFuncts->pfRTAAlgoServiceAddEvent) (RtaEvtType, u_IdGlobal, u_IdLocal, u_OptData);
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    ISCAlgoInit                                                                                    */ /*!

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
static void ISC_v_AlgoInit (void)
{
  /*--- VARIABLES ---*/

  ISCFrame.bFirstCycleDone   = FALSE;
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetOperationMode                                                                   */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[in]       t_ISCOpModeValue : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         26.01.2017
  @changed         26.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void ISC_v_SetOperationMode(const ISCState_t t_ISCOpModeValue)
{
  ISCFrame.eISCState = t_ISCOpModeValue;
}

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             ISC_v_SetAlgoErrorBuffer */ /*! 
  @brief          Set the Algo Error Buffer
  @description    Set the ErrorQualifier to pErrorBuffer if it is more severe than the stored one.
                  It's not possible to change to a lower priority than already set.
  @param[in]      ErrorQualifier : the Error to set
  @param[in,out]  pErrorBuffer   : pointer to the buffered error
  @pre            None
  @author         Christian Obst
**************************************************************************** */
static void ISC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
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
  @fn           ISC_v_SetCompState                                  */ /*!
  @brief        Set the Algo Component State.
  @description  Set the Algo Component State based on scheduler request and internal status.
  @param[out]   pVehCompState : pointer to Algo Component State that shall be set.
  @param[in]    ScheduledOpMode : operation mode given by global scheduler.
  @param[in]    BufferedQualifier : internal buffer for AlgoQualifier (error status).
  @pre          Algo ran, component error states are set.
  @return       none
  @author       Christian Obst
**************************************************************************** */
static void ISC_v_SetCompState (AlgoCompState_t * const pVehCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
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
  if (pVehCompState != NULL)
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(pVehCompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pVehCompState->uiAlgoVersionNumber = ISCFrame.Versions.uiIsc;
#if COMP_STATE_INTFVER > 2u
    pVehCompState->uiApplicationNumber = 0u;
    pVehCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pVehCompState->ApplicationNumber = 0u;
    pVehCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (ISCFrame.eISCState)
    {
    case ISC_INIT:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pVehCompState->eCompState = COMP_STATE_RUNNING;
        pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pVehCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*some issue occurred either no pVehCtrlData pointer or internal init*/
        pVehCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pVehCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pVehCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pVehCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case ISC_RUN:
      pVehCompState->eCompState = COMP_STATE_RUNNING;
      pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pVehCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case ISC_SHUTDOWN:
      /*in case on missing input signal pointer or invalid signal status*/
    default:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pVehCompState->eCompState = COMP_STATE_RUNNING;
        pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pVehCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*internal recoverable error*/
        pVehCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pVehCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pVehCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pVehCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*************************************************************************************************************************
  Functionname:    ISC_v_CheckPortUpdated                                                                           */ /*!

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
static uint32 ISC_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
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
  Functionname:    ISC_v_CheckInputUpdate                                                                           */ /*!

  @brief           Checks for frame drops and frozen input interfaces based on provided timestamps.

  @description     calls the Update Checker function for every used input interface and writes it to the InputCounters struct.

  @return          static uint32 : number of interfaces which are not updated longer than debounce time.

  @param[in]       pRequirePorts : input interface provided to FCTVeh. 
  @param[in]       pFCTVehInputCounters : internal memory struct to store update information.
  @param[in]       fTargetCycleTimeVeh : target cycle time for the FCTVeh Task. 
  @param[in]       fTargetCycleTimeSen : target cycle time for the Camera (FCTSen) Task (Sensor cycle).

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_ISC_COMPONENT : Configuration switch for enabling FCT_LONG processing
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
static uint32 ISC_v_CheckInputUpdate(const ISC_ReqPortList_t * pRequirePorts, Isc_InputMeasCounter *pIscInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen)
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pVehCtrlData->sSigHeader.uiTimeStamp), &(pIscInputCounters->sVehCtrlData), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pEgoDynRaw->sSigHeader.uiTimeStamp), &(pIscInputCounters->sEgoDynRaw), fTargetCycleTimeSen, AcceptableDrops );
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pLongCtrlResp->sSigHeader.uiTimeStamp), &(pIscInputCounters->sLongCtrlInput), fTargetCycleTimeVeh, AcceptableDrops );
#if ((CFG_ACC_LEVER_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pAccLever->sSigHeader.uiTimeStamp), &(pIscInputCounters->sAccLeverInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if ((FCT_CFG_ACC_HEADWAY_PLANNER) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pAccDisplayObj->sSigHeader.uiTimeStamp), &(pIscInputCounters->sAcc_object), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pAccOutput->sSigHeader.uiTimeStamp), &(pIscInputCounters->sAcc_output_data), fTargetCycleTimeVeh, AcceptableDrops );
#endif 
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts.pAccOOIData->sSigHeader.uiTimeStamp), &(pIscInputCounters->sFCTSenAccOOI), fTargetCycleTimeSen, AcceptableDrops );
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pVehSig->sSigHeader.uiTimeStamp), &(pIscInputCounters->sVehSig), fTargetCycleTimeSen, AcceptableDrops );
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  ErrorCounter += ISC_v_CheckPortUpdated( &(pRequirePorts->pFctVehCustInput->sSigHeader.uiTimeStamp), &(pIscInputCounters->sFctVehCustInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             ISC_v_SetDem                                  */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            ISC_pServiceFunctss connected to input service ports
  @todo           review
  @author         Christian Obst
**************************************************************************** */
void ISC_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((ISC_pServiceFuncts != NULL) && (ISC_pServiceFunctsISC_pServiceFunctspfDem_SetEventStatus != NULL))
  {
    ISC_pServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    ISC_v_SetupPorts                                                                         */ /*!

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

  @created         29.08.2017
  @changed         29.08.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void ISC_v_SetupPorts(const ISC_ReqPortList_t *pRequirePorts, const ISC_ProPortList_t *pProvidePorts)
{
/*! Assignment of external pointers to ISC input ports for access within this component */
  pt_ISC_IN_IIP  = pRequirePorts->pt_ISC_IN_IIP;
  pt_ISC_IN_ICP  = pRequirePorts->pt_ISC_IN_ICP;
  pt_ISC_IN_LVSP = pRequirePorts->pt_ISC_IN_LVSP;

/*! Assignment of external pointers to ISC ports for access within this component */
#if (FCT_CFG_LOCC_COMPONENT)
  pt_ISC_IN_CCSP  = pRequirePorts->pt_ISC_IN_CCSP;
  pt_ISC_OUT_CCCP = pProvidePorts->pt_ISC_OUT_CCCP;
#endif

/*! Assignment of external pointers to ISC ports for access within this component */
#if (FCT_CFG_LOHP_COMPONENT)
  pt_ISC_IN_TCSP  = pRequirePorts->pt_ISC_IN_TCSP;
  pt_ISC_OUT_TCCP = pProvidePorts->pt_ISC_OUT_TCCP;
#endif

/*! Assignment of external pointers to ISC output ports for access within this component */
  pt_ISC_OUT_LVCP = pProvidePorts->pt_ISC_OUT_LVCP;
  pt_ISC_OUT_ISP  = pProvidePorts->pt_ISC_OUT_ISP;
}

/*************************************************************************************************************************
  Functionname:    ISC_v_FillSigHeader                                                                        */ /*!

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
static void ISC_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = ISCFrame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetSigHeaderState                                                                    */ /*!

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
static void ISC_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus            = eSigState;
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetProvideHeaderStates                                                               */ /*!

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
static void ISC_v_SetProvideHeaderStates(const ISC_ProPortList_t * pProvidePorts, AlgoSignalState_t eSigState) 
{
_PARAM_UNUSED(pProvidePorts);
_PARAM_UNUSED(eSigState);
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetProvideHeader                                                                     */ /*!

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
static void ISC_v_SetProvideHeader(const ISC_ReqPortList_t * pRequirePorts, const ISC_ProPortList_t * pProvidePorts) 
{
  _PARAM_UNUSED(pProvidePorts);
  _PARAM_UNUSED(pRequirePorts);
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetSigHeaderError                                                                    */ /*!

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
static void ISC_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiCycleCounter        = ISCFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    ISC_v_CheckProvideHeader                                                                         */ /*!

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
static void ISC_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
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
  Functionname:    ISC_v_CheckProvideHeaders                                                                        */ /*!

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
static void ISC_v_CheckProvideHeaders(const ISC_ReqPortList_t * pRequirePorts, const ISC_ProPortList_t * pProvidePorts) 
{
#if ((FCT_CFG_ISC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ISC_v_CheckProvideHeader(&pProvidePorts.pFctVehLongOut->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
  ISC_v_CheckProvideHeader(&pProvidePorts.pLongCtrlOutput->sSigHeader, &pRequirePorts.pLongCtrlResp->sSigHeader);
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  ISC_v_CheckProvideHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
#endif
}
#endif

/*************************************************************************************************************************
  Functionname:    ISC_v_CheckPorts                                                                           */ /*!

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
static void ISC_v_CheckPorts( const ISC_ReqPortList_t * pRequirePorts, const ISC_ProPortList_t * pProvidePorts
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

    )
  {
    /* Some request port pointer is NULL => DEM and shutdown */

#if (FCT_CFG_USE_DEM)
    /*validity of service pointer isn't clear here*/
    ISC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /* setup the Algo Error Buffer */
    ISC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    /* shutdown the system */
    ISC_v_SignalErrorShutdown(FALSE);
  }
  else
  {
    /* Verify that provide port buffer pointers are set (non-null) */
    if (
      (pProvidePorts == NULL)
      )
    {
#if (FCT_CFG_USE_DEM)
      /* Some provide port pointer is NULL => DEM -> shutdown */
      ISC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      ISC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      ISC_v_SignalErrorShutdown(FALSE);
    }
    else
    {
#if (FCT_CFG_USE_DEM)
      /* receive and provide ports are fine */
      ISC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
    }

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
    /* no NullPointer in request ports*/
    /* check for SignalState in requestPorts*/
    if(
      (pRequirePorts->pVehCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_VEH_CFG_CUSTOMINPUT)
      || (pRequirePorts->pFctVehCustInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
      )
    {
      /*signal state broken -> no dem only shutdown*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /* setup the Algo Error Buffer */
      ISC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      /* shutdown the system */
      ISC_v_SignalErrorShutdown(FALSE);
    }
#endif /*FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK*/
  }
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetErrorProvidePorts                                                                 */ /*!

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
static void ISC_v_SetErrorProvidePorts (const ISC_ProPortList_t * pProvidePorts)
{
  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pVehCompState != NULL)
    {
      ISC_pCompState                  = pProvidePorts->pVehCompState;
#if COMP_STATE_INTFVER > 2u
      ISC_pCompState->uiVersionNumber  = COMP_STATE_INTFVER;
#else
      ISC_pCompState->uVersionNumber  = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      ISC_pCompState = NULL;
    }
#endif

  }
  else
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    ISC_pCompState = NULL;
#endif
  }
}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetupSyncRef                                                                         */ /*!

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
static void ISC_v_SetupSyncRef(const ISC_ReqPortList_t *pRequirePorts)
{
  /*setting whole syncref to zero */
  (void)memset(&ISC_SyncRef, 0, sizeof(ISC_SyncRef));

  if (pRequirePorts != NULL)
  {
    /* pt_ISC_IN_Ctrl */
    if (pRequirePorts->pt_ISC_IN_Ctrl != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      ISC_v_FillSigHeader(&(ISC_SyncRef.sSigHeader), &(pRequirePorts->pt_ISC_IN_Ctrl->sSigHeader));
      ISC_v_SetSigHeaderState(&ISC_SyncRef.sSigHeader, AL_SIG_STATE_OK);

      ISC_SyncRef.t_SH_CTRL = pRequirePorts->pt_ISC_IN_Ctrl->sSigHeader;
    }
    else
    {
      ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_ISC_IN_IIP */
    if (pRequirePorts->pt_ISC_IN_IIP != NULL)
    {
      ISC_SyncRef.t_ISC_IN_IIP = pRequirePorts->pt_ISC_IN_IIP->sSigHeader;
    }
    else
    {
      ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_ISC_IN_ICP */
    if (pRequirePorts->pt_ISC_IN_ICP != NULL)
    {
      ISC_SyncRef.t_ISC_IN_ICP = pRequirePorts->pt_ISC_IN_ICP->sSigHeader;
    }
    else
    {
      ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_LOCC_COMPONENT)
    /* pt_ISC_IN_CCSP */
    if (pRequirePorts->pt_ISC_IN_CCSP != NULL)
    {
      ISC_SyncRef.t_ISC_IN_CCSP = pRequirePorts->pt_ISC_IN_CCSP->sSigHeader;
    }
    else
    {
      ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_LOHP_COMPONENT)
    /* pt_ISC_IN_TCSP */
    if (pRequirePorts->pt_ISC_IN_TCSP != NULL)
    {
      ISC_SyncRef.t_ISC_IN_TCSP = pRequirePorts->pt_ISC_IN_TCSP->sSigHeader;
    }
    else
    {
      ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    /* pt_ISC_IN_LVSP */
    if (pRequirePorts->pt_ISC_IN_LVSP != NULL)
    {
      ISC_SyncRef.t_ISC_IN_LVSP = pRequirePorts->pt_ISC_IN_LVSP->sSigHeader;
    }
    else
    {
      ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    ISC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
}

/*************************************************************************************************************************
  Functionname:    ISC_v_Set_HMI_Ports                                                                              */ /*!

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

  @created         29.08.2017
  @changed         29.08.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void ISC_v_Set_HMI_Ports(HMI_ReqPortList_t *pRequirePorts, HMI_ProPortList_t *pProvidePorts)
{
  /* t_HMI_IN_HMIP */
  pRequirePorts->t_HMI_IN_HMIP.pt_HMI = &(pt_ISC_IN_IIP->t_ISCI);

  /* t_HMI_IN_HMCP */
  pRequirePorts->t_HMI_IN_HMCP.pt_HMC = &(pt_ISC_IN_ICP->t_ISCC);

  /* t_HMI_OUT_HMSP */
  pProvidePorts->t_HMI_OUT_HMSP.pt_HMS = &(pt_ISC_OUT_ISP->t_ISCS);
  
#if (FCT_CFG_LOCC_COMPONENT)
  /* t_HMI_OUT_CCDP */
  pProvidePorts->t_HMI_OUT_CCDP.pt_HMD = &(pt_ISC_OUT_CCCP->t_Degrade);
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  /* t_HMI_OUT_TCDP */
  pProvidePorts->t_HMI_OUT_TCDP.pt_HMD = &(pt_ISC_OUT_TCCP->t_Degrade);
#endif

  /* t_HMI_OUT_SMCP */
  pProvidePorts->t_HMI_OUT_SMCP.pt_SMC = &t_ISC_LOC_SMC;

  /* t_HMI_IN_SMSP */
  pRequirePorts->t_HMI_IN_SMSP.pt_SMS = &t_ISC_LOC_SMS;

  /* t_HMI_OUT_LVCP */
  pProvidePorts->t_HMI_OUT_LVCP.pt_LVC = &(pt_ISC_OUT_LVCP->t_LVC);

  /* t_HMI_IN_LVSP */
  pRequirePorts->t_HMI_IN_LVSP.pt_LVS = &(pt_ISC_IN_LVSP->t_LVS);
}

/*************************************************************************************************************************
  Functionname:    ISC_v_Set_SM_Ports                                                                              */ /*!

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

  @created         29.08.2017
  @changed         29.08.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void ISC_v_Set_SM_Ports(SM_ReqPortList_t *pRequirePorts, SM_ProPortList_t *pProvidePorts)
{
  /* t_SM_IN_SMCP */
  pRequirePorts->t_SM_IN_SMCP.pt_SMC = &t_ISC_LOC_SMC;

  /* t_SM_OUT_SMSP */
  pProvidePorts->t_SM_OUT_SMSP.pt_SMS = &t_ISC_LOC_SMS;

#if (FCT_CFG_LOCC_COMPONENT)
  /* t_SM_IN_CCSP */
  pRequirePorts->t_SM_IN_CCSP.pt_CCS = &(pt_ISC_IN_CCSP->t_State);

  /* t_SM_OUT_CCCP */
  pProvidePorts->t_SM_OUT_CCCP.pt_CCC = &(pt_ISC_OUT_CCCP->t_Command);
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  /* t_SM_IN_TCSP */
  pRequirePorts->t_SM_IN_TCSP.pt_TCS = &(pt_ISC_IN_TCSP->t_State);

  /* t_SM_OUT_TCCP */
  pProvidePorts->t_SM_OUT_TCCP.pt_TCC = &(pt_ISC_OUT_TCCP->t_Command);
#endif

  /* t_SM_IN_LOCSP */
  pRequirePorts->t_SM_IN_LOCSP.pt_LVS = &(pt_ISC_IN_LVSP->t_LVS);

}

/*************************************************************************************************************************
  Functionname:    ISC_v_SetFrameData                                                                          */ /*!

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
static void ISC_v_SetFrameData(const ISC_ReqPortList_t *pRequirePorts) 
{
  _PARAM_UNUSED(pRequirePorts);

  ISCFrame.uiCycleCounter++;

  /* setup sub-module version numbers */

  ISCFrame.Versions.FCT_ISC_VERSION_AS_TEXT  =   ISC_SW_VERSION_NUMBER;
  ISCFrame.Versions.uiIsc = ISC_SW_VERSION_NUMBER;

}

/*************************************************************************************************************************
  Functionname:    ISC_v_Exec                                                                                  */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[in]       p_IscRequirePorts : 
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
void ISC_v_Exec(const ISC_ReqPortList_t *p_RequirePorts, const ISC_ProPortList_t *p_ProvidePorts, const FCT_OP_MODE_t t_FCTVehFrameFCTOpMode, const AS_t_ServiceFuncts *p_ServiceFuncts)
#else
void ISC_v_Exec(const ISC_ReqPortList_t *p_RequirePorts, const ISC_ProPortList_t *p_ProvidePorts, const FCT_OP_MODE_t t_FCTVehFrameFCTOpMode)
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
    IscAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, ISC_RTA_PROCESS, 0);
    /* Sends RTA-Start event for data preparation runtime */
    IscAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, ISC_RTA_PREPRE_PROCESS, 0);
  }
#endif

  /*---------------------------------------------------------------------------*/
  /* Start data preparation                                                    */
  /*---------------------------------------------------------------------------*/

  /* update Frame Data and set OpMode */
  ISC_v_SetFrameData(p_RequirePorts);

  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  /* set the process states for all subcomponents */
  ISC_v_ProcessStates(t_FCTVehFrameFCTOpMode);
  
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  ISC_pServiceFuncts = p_ServiceFuncts;
#endif

  /* check for NULLpointer => trigger ErrorShutdown */
  ISC_v_CheckPorts(p_RequirePorts, p_ProvidePorts /* Includes Error Management and OP-Mode-Changing */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    , &AlgoErrorBuffer
#endif
    );

  /* setup the input port header sync structure */
  ISC_v_SetupSyncRef(p_RequirePorts); 

  if ((ISCFrame.eISCOpMode != FCT_MOD_SHUTDOWN) && (ISCFrame.eISCState != FCT_VEH_SHUTDOWN))
  {
    /*Init in init Mode*/
    if (ISCFrame.eISCState == FCT_VEH_INIT)
    {
      ISC_v_AlgoInit ();
    }
    else
    {
      ISCFrame.bFirstCycleDone = TRUE;
    }
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
    if ( ISC_v_CheckInputUpdate(p_RequirePorts, &FCTVehIscInputCounters,FCT_VEH_CYCLE_TIME, fCycleTimeSen) != 0u )   /*error condition*/
    {
      ISC_v_SetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
    }
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

     /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
    /* Opmode indicates liveliness => setup port pointers */
    ISC_v_SetupPorts(p_RequirePorts, p_ProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start */
    if ((p_ServiceFuncts != NULL) && ((p_ServiceFuncts->pfMeasStartFuncCycle) != NULL))
    {
      (p_ServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
    }
#endif
    /* set all the signal headers of all provide ports to invalid*/
    ISC_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);
    ISC_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);
    /* Sends RTA-Start event for Longitudinal control runtime */
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    ISCAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, ISC_RTA_PREPRE_PROCESS, 0);
    ISCAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, ISC_RTA_LC_PROCESS, 0);
#endif

    /* New architecture */
    /* Assign Port Lists of HMI Subcomponent */
    ISC_v_Set_HMI_Ports(&t_HMI_ReqPortList, &t_HMI_ProPortList);

    /* Assign Port Lists of SM Subcomponent */
    ISC_v_Set_SM_Ports(&t_SM_ReqPortList, &t_SM_ProPortList);

    /* Call first ! Process of HMI Subcomponent */
    HMI_v_Process(&t_HMI_ReqPortList, &t_HMI_ProPortList);

    /* Call second ! Process of SM Subcomponent */
    SM_v_Process(&t_SM_ReqPortList, &t_SM_ProPortList);

/* TODO !!! */
    /* Assign Signal Headers of Output Ports */
    //pt_ISC_OUT_CCCP->uiVersionNumber =
    //pt_ISC_OUT_CCCP->sSigHeader =
    //pt_ISC_OUT_ISP->uiVersionNumber =
    //pt_ISC_OUT_ISP->sSigHeader =
/* TODO !!! */


#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    ISCAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, ISC_RTA_LC_PROCESS, 0);
#endif

#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
    ISC_v_CheckProvideHeaders(p_RequirePorts, p_ProvidePorts); 
#endif
    /* Set all signal header values again to avoid errors if a component accidentialy overwrite the SigHeader*/
    ISC_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);
	
#if (FCT_MEASUREMENT)
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-Start event for Process Measfreeze runtime */
    ISCAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, ISC_RTA_PROCESSFREEZE, 0);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    ISC_v_SetCompState (ISC_pCompState, p_RequirePorts->pVehCtrlData->OpMode, AlgoErrorBuffer);
#endif
    /* Process meas freezes */
    ISC_v_ProcessMeasFreeze();

    /*computation chain ran through. FCT Vehicle is initialized or running.*/
    b_IscIsInitialized  = TRUE;

    /* Sends RTA-End event for Longitudinal control runtime */
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    ISCAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, ISC_RTA_PROCESSFREEZE, 0);
#endif
#endif /* FCT_MEASUREMENT */
  }
   else  /************************* end of non-error path, beginning of error path *************************/
   {
     /* FCT_MOD_SHUTDOWN => fill invalidate the available provide ports and fill whole sigHeader */

     ISC_v_SetErrorProvidePorts(p_ProvidePorts);
#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
     if ((p_ServiceFuncts != NULL) && (p_ServiceFuncts->pfMeasStartFuncCycle != NULL))
     {
       /* send MTS Freeze Cycle Start if Service is available */
       (p_ServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
     }
#endif

     /* Init ISC Algo */
     ISC_v_AlgoInit();

#if (FCT_CFG_USE_ALGOCOMPSTATE)
     /*ERROR path! Need to check existence of pointers*/
     if (ISC_pCompState != NULL)
     {
       if ( (p_RequirePorts != NULL) && (p_RequirePorts->pVehCtrlData != NULL) )
       {
         ISC_v_SetCompState (ISC_pCompState, p_RequirePorts->pVehCtrlData->OpMode, AlgoErrorBuffer);
       }
       else
       {
         ISC_v_SetCompState (ISC_pCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
       }
     }
#endif
    /*make sure in error case init of sub components is performed next cylcle*/
    b_IscIsInitialized = FALSE;

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
     if (p_ServiceFuncts != NULL)
     {
       /* Sends RTA-End event for data preparation runtime in errorcase*/
       IscAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, ISC_RTA_PROCESS, 0);
     }
#endif
   } /*********************** end of error path, beginning common *******************************/
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
   if (p_ServiceFuncts != NULL)
   {
     /* Sends RTA-Start event for Frame Measfreeze runtime */
     IscAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, ISC_RTA_FRAMEFREEZE, 0);
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
     ISC_v_FrameFreeze();
   }
#else
   ISC_v_FrameFreeze();
#endif
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
   if (p_ServiceFuncts != NULL)
   {
     /* Sends RTA-End event for Frame Measfreeze runtime */
     IscAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, ISC_RTA_FRAMEFREEZE, 0);
     /* Sends RTA-End event for whole procedure runtime */
     IscAlgoServiceAddEvent(p_ServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, ISC_RTA_PROCESS, 0);
   }
#endif
}
#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT) */

