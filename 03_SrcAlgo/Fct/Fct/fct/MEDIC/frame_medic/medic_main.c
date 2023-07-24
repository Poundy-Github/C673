/*! \file **********************************************************************


COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_main.c

DESCRIPTION:               Main function file for MEDIC evaluation module 

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/11/11 12:08:27CET $

VERSION:                   $Revision: 1.133 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)
extern void MEDIC_v_ProcessPorts( /*PRQA S 3447*/ /*date: 2020-07-02, Reviewer:Nalina M, Reason:Function decl is in a .c file and cant be moved to .h file*/
                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10) 
                          reqMEDICPtrList_t const * const pRequirePorts,
                          proMEDICPtrList_t       * const pProvidePorts,
                          #else
                          MEDIC01_ReqPorts   const * const p_MEDICRequirePorts,
                          MEDIC01_ProPorts   const * const p_MEDICProvidePorts,
                          #endif
                          MEDICPortHandlerList_t * const pPortHandlerList
                          #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10) 
                          , AS_t_ServiceFuncts const * const pServiceFuncts
                          #else
                          , MEDIC_Services     const * const pServiceFuncts
                          #endif
                          #endif
                          #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
                          , GenAlgoQualifiers_t * const pErrorBuffer
                          #endif
                          );

#if (MEDIC_CFG_MEASUREMENT)
extern void MEDIC_v_FreezePorts(MEDICPortHandlerList_t const * const pMEDIC_PortHandlerList); /*PRQA S 3447*/ /*Function decl is in a .c file and cant be moved to .h file*/
extern void MEDIC_v_FreezeWorkingData(MEDIC_Working_t const * const pWorkData); /*PRQA S 3447*/ /*date: 2020-06-02, Reviewer:Nalina M, Reason:Function decl is in a .c file and cant be moved to .h file*/
#endif

extern boolean bHEADInitInputOutputDone; /*PRQA S 3447*/ /*date: 2020-07-02, Reviewer:Nalina M, Reason:variable decl is in a .c file and cant be moved to .h file*/

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* ifndef __PDO__ */

/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/
/**
@defgroup frame_main Main
@ingroup frame
@brief          This module provides amongst others the main function of the MEDIC Component. \n\n

@description    The following functionalities are provided by this module:
                - Main function of the MEDIC Component which calls the main routines of all subcomponents: @ref MEDIC_v_Exec.
                - Determination of the runtime of the MEDIC Component: @ref MEDIC_SERVICE_ADD_EVENT.
@{
*/
/* Initialization status of MEDIC and it's subcomponents */

#if  MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY
/* MEDIC process memory */
static GA_MEDIC_Mem_DataInterCycleMeas MEDICInterMeas = {0}; /*PRQA S 3207*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: This variable will be used later on, hence suppressed for now  */
static GA_MEDIC_Mem_DataInterCycle     MEDICInter     = {0}; /*PRQA S 3207*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: This variable will be used later on, hence suppressed for now  */
static GA_MEDIC_Mem_DataIntraCycleMeas MEDICIntraMeas = {0}; /*PRQA S 3207*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: This variable will be used later on, hence suppressed for now  */
#endif

SET_MEMSEC_VAR(MEDICAccessData)
MEDICAccessData_t  MEDICAccessData;
static uint8       uPreviousOpMode = MEDIC_MOD_UNDEFINED; /*PRQA S 3218*//*Reviewer:Rashmi Ramachandra, Reason: needed for future use */

#ifdef MEDIC_SIMU
void (*MEDIC_SimulationOutput)(MEDICAccessData_t*) = NULL;
#endif

#if (MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
SET_MEMSEC_VAR(FCTVehMedicInputCounters)
static Medic_InputMeasCounter FCTVehMedicInputCounters = {0};  /*!<aggregation struct that keeps update information for all input interfaces.*/
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void MEDIC_v_AlgoInit (void);

static eGDBError_t MEDIC_e_AssignStaticMemoryToAccessData(MEDIC_ProcMem_t const * const p_MedicProcMem, MEDIC_DataWrapperStack_t * const pMEDICStackData);

static void MEDIC_v_AssignAccessPointers(
                                        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
                                         reqMEDICPtrList_t  const * const p_MEDICRequirePorts
                                        ,proMEDICPtrList_t        * const p_MEDICProvidePorts
                                        #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                                        ,AS_t_ServiceFuncts const * const p_ServiceFuncts
                                        #endif
                                        #else
                                         MEDIC01_ReqPorts   const * const p_MEDICRequirePorts
                                        ,MEDIC01_ProPorts   const * const p_MEDICProvidePorts
                                        #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                                        ,MEDIC_Services     const * const p_ServiceFuncts
                                        #endif
                                        #endif
                                        );

#if (MEDIC_CFG_USE_ALGOCOMPSTATE)
static void MEDIC_v_SetCompState(AlgoCompState_t *const pVehCompState, const MEDICOpMode_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK
static void MEDIC_v_CheckProvideHeader(SignalHeader_t const *const pProvidedSigHeader, SignalHeader_t const *const pReceivedSigHeader);
static void MEDIC_v_CheckProvideHeaders(const reqMEDICPtrList_t *pRequirePorts, const proMEDICPtrList_t *pProvidePorts);
#endif

#if MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 MEDIC_v_CheckInputUpdate(const reqMEDICPtrList_t *pRequirePorts, Medic_InputMeasCounter *pFCTVehInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen);
static uint32 MEDIC_v_CheckPortUpdated(const AlgoDataTimeStamp_t *pInputPortMeasCycle, sMeasCycleMonitor *pLastMeasCycle, float32 fTargetCycleTime, uint8 iAcceptableDrops);
#endif

static void MEDIC_v_InitInterCycleData(MEDIC_ProcMem_t const * const p_MedicProcMem);

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
static void MEDIC_v_SetCompState(eCompState_t eCompState, CompErrorCode_t eErrorCode);
boolean MEDIC_b_CheckExternalMemorySize(void);
boolean MEDIC_b_CheckNullPointers(MEDIC01_ReqPorts const*const p_MedicRequirePorts, MEDIC01_ProPorts const*const p_MedicProvidePorts, MEDIC_ProcMem const*const p_MedicProcMem, MEDIC_Services const*const p_MedicServices);
void    MEDIC_v_CalculateCycleTime(MEDIC_Services const*const p_MedicServices);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
/* ***********************************************************************
  Functionname         MEDIC_v_AlgoServiceAddEvent                                  */ /*!

  @brief               set RTA event via service function

  @description         this is used for sending RTA events to various processes
                       with the corresponding data.

  @return              eGDBError_t

  @param[in]           RtaEvtType:
  @param[in]           u_IdGlobal:
  @param[in]           u_IdLocal:
  @param[in]           u_OptData:
  @param[in,out]       pServiceFuncts: service function pointer

  @glob_in             None 
  @glob_out            None

  @c_switch_part       None 
  @c_switch_full       MEDIC_CFG_EMERGENCY_BRAKE_ASSIST, MEDIC_CFG_RTA_PROFILING, MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS 

  @pre                 None
  @post                None

  @InOutCorrelation    see description
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Christian Obst | Christian Obst@continental-corporation.com
*************************************************************************************************************************/

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
void MEDIC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#else
void MEDIC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#endif
{
  if (pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL)
  {
    (pServiceFuncts->pfRTAAlgoServiceAddEvent) (RtaEvtType, u_IdGlobal, u_IdLocal, u_OptData);
  }
}
#else
void MEDIC_v_AlgoServiceAddEvent(const MEDIC_Services *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
{
  if (pServiceFuncts != NULL)
  {
    if (pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL)
    {
      (pServiceFuncts->pfRTAAlgoServiceAddEvent) (RtaEvtType, u_IdGlobal, u_IdLocal, u_OptData);
    }
  }
}
#endif
#endif

/*************************************************************************************************************************
  Functionname:        MEDIC_v_AlgoInit                                                                         */ /*!

  @brief               Set MEDIc algo initialization status

  @description         Resets the algo initiailization status which generally happens during module initilization
                        @startuml
                        start
                          :Initialise FirstCycleDone;
                          :Initialise CycleCounter;
                        stop
                        @enduml
          
  @return              void

  @param[in]           void
  

  @glob_in             MEDICFrame 
  @glob_out            MEDICFrame

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                 None
  @post                None

  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1102-0007e0f8}

  @author              Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
static void MEDIC_v_AlgoInit (void)
{
  MEDIC_p_ModFrameData()->bFirstCycleDone = b_FALSE;
  MEDIC_p_ModFrameData()->uiCycleCounter  = 0;
}
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:        MEDIC_v_SetState                                                                        */ /*!

  @brief               Writes the current State to the MEDIC Frame variable. 

  @description         Writes the current State to the MEDIC Frame variable.
          
  @return              void

  @param[in]           t_MEDICStateValue :State that shall be written into the global variable
   
  @glob_in             None 
  @glob_out            @ref MEDICFrame 

  @c_switch_part        
  @c_switch_full       @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST  

  @pre                 None  
  @post                None  

  @InOutCorrelation    None  
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
void MEDIC_v_SetState(const MEDICCompState_t t_MEDICStateValue)
{
  MEDIC_p_ModFrameData()->eMEDICState = t_MEDICStateValue;
}
#endif 

#if (MEDIC_CFG_USE_ALGOCOMPSTATE)
/*************************************************************************************************************************
  Functionname:        MEDIC_v_SetCompState                                                                       */ /*!

  @brief               Set the Algo Component State.

  @description         Set the Algo Component State based on scheduler request and internal status.
                       Detailed design:
                       @startuml
                       Start
                       :receive pointer to veh comp state buffer;
                       :receive scheduled opmode for veh comp;
                       :receive buffer for qualifiers;
                       If (null pointer check ok?) then (yes)
                       :algo version info filled to vehcomp state buffer;
                       :get FCTveh frame after freeze;
                       :Check current state of FCT;
                       If(FCT in RUN state?) then (yes)
                       :set com state running;
                       :set no error state;
                       :set algo qualifiers from the buffer;
                       Else (no)
                       If(FCT not scheduled to run?)
                       :fill status as no error;
                       :algo state ok;
                       :component state set to running;
                       Else (no)
                       : component state is temp error;
                       :comp error set to unknown error type;
                       If(qualifier buffer is not empty?) then (yes)
                       :save qual info to veh comp state buffer;
                       Else (no)
                       :save generic qual value to veh comp state buff;
                       Endif
                       endif
                       Endif
                       endif
                       Stop
                       @enduml

  
  @return              void

  @param[out]          pVehCompState : pointer to Algo Component State that shall be set.
  @param[in]           ScheduledOpMode : operation mode given by global scheduler.
  @param[in]           BufferedQualifier : internal buffer for AlgoQualifier (error status).
   
  @glob_in             None 
  @glob_out            None

  @c_switch_part       MFC_VERSION_INFO_LENGTH, 
  @c_switch_full       MEDIC_CFG_EMERGENCY_BRAKE_ASSIST, MEDIC_CFG_USE_ALGOCOMPSTATE

  @pre                 Algo ran, component error states are set. 
  @post                None 

  @InOutCorrelation    Not defined
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Christian Obst | Christian Obst@continental-corporation.com 
*************************************************************************************************************************/
static void MEDIC_v_SetCompState (AlgoCompState_t * const pVehCompState, const MEDICOpMode_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
{
  #if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) )
  #pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: REMOVE REDEFINITION (obviously the RTE is updated)!")// PRQA S 3116
  #endif
  #ifndef MFC_VERSION_INFO_LENGTH
  #define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
  #endif 

  /* The define MFC_VERSION_INFO_LENGTH is to be renamed. The name has to be more generalized regarding the used thechnology */
  #if COMP_STATE_INTFVER > 3
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));/*PRQA S 1844, 4464, 3493, 1842 #date: 2020-06-09, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  #else
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
  #endif
  if (pVehCompState != NULL)
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    MEDIC_MEMCPY(pVehCompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);/*PRQA S 0315, 1495 #date: 2020-07-02, reviewer: Nalina M, reason: Generic Implementation */
    pVehCompState->uiAlgoVersionNumber = MEDIC_p_ModFrameData()->Versions.uiMedic;
    #if COMP_STATE_INTFVER > 2u
    pVehCompState->uiApplicationNumber = 0u;
    pVehCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
    #else
    pVehCompState->ApplicationNumber = 0u;
    pVehCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
    #endif
    switch (MEDIC_p_GetFrameData()->eMEDICState)
    {
    case COMP_STATE_NOT_INITIALIZED:
      if (ScheduledOpMode != MEDIC_MOD_RUNNING)
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
    case COMP_STATE_RUNNING:
      pVehCompState->eCompState = COMP_STATE_RUNNING;
      pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pVehCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    /*in case on missing input signal pointer or invalid signal status*/
    default:
      if (ScheduledOpMode != MEDIC_MOD_RUNNING)
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
#endif /* MEDIC_CFG_USE_ALGOCOMPSTATE */


#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:        MEDIC_v_SetCompState                                                                         */ /*!

  @brief               Set the Algo Component State.

  @description         Set the Algo Component State by evaluating the MEDIC OpMode

                       @startuml
                       Start
                       If (null pointer check ok?) then (yes)
                       :set version number;
                       :set algo version number;
                       :set comp state;
                       :set Error code;
                       endif
                       stop
                       @enduml

  @return              void

  @param[out]          pCompState : pointer to Algo Component State that shall be set.
  @param[in]           MedicOpMode: MEDIC operation mode

  @glob_in             None
  @glob_out            None

  @c_switch_part   ....None
  @c_switch_full   ....@ref MEDIC_ARCHITECTURE_VERSION

  @InOutCorrelation    see the description

  @testmethod          Test of output data (dynamic module test)

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1100-0007e0f8}

  @author              Armin Vogl | Armin.Vogl@continental-corporation.com
*************************************************************************************************************************/
static void MEDIC_v_SetCompState(eCompState_t eCompState, CompErrorCode_t eErrorCode)
{
  AlgoCompState_t *pCompStateProvidePort = MEDIC_p_ModCompState();

  if (pCompStateProvidePort != NULL)
  {
    pCompStateProvidePort->uiVersionNumber     = COMP_STATE_INTFVER;
    pCompStateProvidePort->uiAlgoVersionNumber = MEDIC_p_ModFrameData()->Versions.uiMedic;
    pCompStateProvidePort->eCompState          = eCompState;
    pCompStateProvidePort->eErrorCode          = eErrorCode;
  }
}
#endif


#if MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/*************************************************************************************************************************
  Functionname:    MEDIC_v_CheckPortUpdated                                                                           */ /*!

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

  @glob_in         None
  @glob_out        None
                   
  @c_switch_part   None
  @c_switch_full   MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
                   
  @pre             None
  @post            None

  @InOutCorrelation    Not defined
  
  @testmethod      Test of output data (dynamic module test) 

  @traceability    Design Decision

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 MEDIC_v_CheckPortUpdated(const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                       sMeasCycleMonitor *pLastMeasCycle,
                                       float32 fTargetCycleTime, 
                                       uint8 iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /*20150327 C. Obst: intended behavior to cast float to uInt. fractional part is neglectible.*/
  /*PRQA S 1800, 4119 3 #date: 2020-06-02, reviewer: Nalina M, reason: intended behavior to cast float to uInt. fractional part is neglectible.*/
  const AlgoDataTimeStamp_t uiCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * 1000000u);         /*conversion second to microsecond*/ /*PRQA S 4395 2 #date: 2020-06-02, reviewer: Nalina M, reason: intended behavior to cast float to uInt. fractional part is neglectible.*/
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiCycleTimeUs ); /*accepted drops + current Cycle + 0.5 safety margin*/
  AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_VEH_TARGET_CYCLE_TIME * (float32)1000000u);

  uint32 uErrorFlag = 0u;

  /*Calculating Time since last input*/
  if ( *pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp )
  {
    /*OVERFLOW*/
    uiDeltaTimeUs = ( (0u)^(0u)) - (pLastMeasCycle->uiTimeStamp - *pInputPortMeasCycle);/*PRQA S 2982, 2986 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  }
  else 
  {
    /*NO Overflow*/
    uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
  }
  
  if ( uiDeltaTimeUs == 0u)
  {
    /*NO update*/
    if ( ((pLastMeasCycle->uiLastUpdateCounter + (uint8)1u) * uiTargetCycleTimeCallUs)  < uiMaxAcceptableDropTimeUs)/*PRQA S 1891 #date: 2020-06-02, reviewer: Nalina M, reason: Suppressing, because of no side effects */
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

/*************************************************************************************************************************
  Functionname:    MEDIC_v_CheckInputUpdate                                                                           */ /*!

  @brief           Checks for frame drops and frozen input interfaces based on provided timestamps.

  @description     calls the Update Checker function for every used input interface and writes it to the InputCounters struct.
                   It also checks for the errors in writing to the input ports and return this error count to
                   the calling function.

  @return          static uint32 : number of interfaces which are not updated longer than debounce time.

  @param[in]       pRequirePorts : input interface provided to FCTVeh. 
  @param[in]       pFCTVehInputCounters : internal memory struct to store update information.
  @param[in]       fTargetCycleTimeVeh : target cycle time for the FCTVeh Task. 
  @param[in]       fTargetCycleTimeSen : target cycle time for the Camera (FCTSen) Task (Sensor cycle).

  @glob_in         None
  @glob_out        None

  @c_switch_part   MEDIC_CFG_INCLUDE_UNUSED_INTF             : Special configuration switch to include all interfaces in request/provide
                                                               port structures, even if the current configuration does not use them. This 
                                                               enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   MEDIC_CFG_DRIVER_INTENTION_MONITORING     : MEDIC driver intention monitoring switch
  @c_switch_part   MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION    : MEDIC hypothesis evaluation and decision switch
  @c_switch_part   MEDIC_CFG_VEH_SIG_INPUT                   : MEDIC configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_full   MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters

  @pre             None
  @post            None

  @InOutCorrelation     Not defined
  
  @testmethod      Test of output data (dynamic module test) 

  @traceability    
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_393}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_1322}
  
  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update).

  @author          Christian Obst| Christian Obst@continental-corporation.com
*************************************************************************************************************************/
static uint32 MEDIC_v_CheckInputUpdate(const reqMEDICPtrList_t *pRequirePorts, Medic_InputMeasCounter *pFCTVehInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen)
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
  ErrorCounter += MEDIC_v_CheckPortUpdated( &(pRequirePorts->pEgoDynRaw->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pEgoDynRaw), fTargetCycleTimeSen, AcceptableDrops );/*PRQA S 2986, 2982 #date: 2020-06-02, reviewer: Nalina M, reason: Supressing because arguments are different and operation is redundant.*/
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += MEDIC_v_CheckPortUpdated( &(pRequirePorts->pDIMInputGeneric->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pDIMInputGeneric), FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
  ErrorCounter += MEDIC_v_CheckPortUpdated( &(pRequirePorts->pDIMInputCustom->sSigHeader.uiTimeStamp) , &(pFCTVehInputCounters->pDIMInputCustom) , FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
  #endif 
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  /* Hypothesis interface */
  ErrorCounter += MEDIC_v_CheckPortUpdated( &(pRequirePorts->pFCTCDHypotheses->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pFCTCDHypotheses), fTargetCycleTimeSen, AcceptableDrops );
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += MEDIC_v_CheckPortUpdated( &(pRequirePorts->pHEADInputGeneric->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pHEADInputGeneric), FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
  ErrorCounter += MEDIC_v_CheckPortUpdated( &(pRequirePorts->pHEADInputCustom->sSigHeader.uiTimeStamp) , &(pFCTVehInputCounters->pHEADInputCustom) , FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
  #endif
  _PARAM_UNUSED(fTargetCycleTimeVeh);/*PRQA S 3119 #date: 2020-06-02, reviewer: Nalina M, reason: Variable will be used in future. */
  return ErrorCounter;
}
#endif /*MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (MEDIC_CFG_USE_DEM)
/*************************************************************************************************************************
  Functionname:        MEDIC_v_SetDem                                                                        */ /*!

  @brief               set DEM message

  @description         Set error management for MEDIC, furthermore the function acts as access function using MEDIC_CFG_USE_DEM switch
  
  @return              void

  @param[in]           Dem_EventId the DEM EVENT ID
  @param[in]           Dem_EventStatus the DEM EVENT STATUS
   
  @glob_in             None 
  @glob_out            None 

  @c_switch_part       None 
  @c_switch_full       @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST
                       @ref MEDIC_CFG_USE_DEM

  @pre                 pFCTVehServiceFuncts connected to input service ports
  @post                None 

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Christian Obst | Christian Obst@continental-corporation.com 
*************************************************************************************************************************/
void MEDIC_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pFCTVehServiceFuncts != NULL) && (pFCTVehServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pFCTVehServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif


#if MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK
/*************************************************************************************************************************
  Functionname:        MEDIC_v_CheckProvideHeader                                                                         */ /*!

  @brief               Check whether the signal header has changed during the call of the components
                
  @description         Check whether the signal header that was received by the frame medic is
                       same as the signal header information that was sent to the sub components. This 
                       function mainly checks the timestamp and counter information in the signal header of 
                       that particular signal for which the check is being done.

                       Detailed Design
                       @startuml
                       Start
                       :check for measurement counter sync between pro ports and req ports;
                       :check for time stamp sync between pro ports and req ports;
                       :assert if not in sync;
                       Stop 
                       @enduml
  
  @return              void
 
  @param[in]           pProvidedSigHeader
  @param[in]           pReceivedSigHeader 
   
  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_EMERGENCY_BRAKE_ASSIST, MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK

  @pre                 None
  @post                None

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Andreas Kramer | Andreas Kramer@continental-corporation.com 
*************************************************************************************************************************/
static void MEDIC_v_CheckProvideHeader(SignalHeader_t const *const pProvidedSigHeader, SignalHeader_t const *const pReceivedSigHeader)
{
  _PARAM_UNUSED(pProvidedSigHeader);
  _PARAM_UNUSED(pReceivedSigHeader);

  CML_ASSERT(    (pProvidedSigHeader->uiMeasurementCounter == pReceivedSigHeader->uiMeasurementCounter)
              && (pProvidedSigHeader->uiTimeStamp          == pReceivedSigHeader->uiTimeStamp         ));
}

/*************************************************************************************************************************
  Functionname:        MEDIC_v_CheckProvideHeaders                                                                  */ /*!

  @brief               Call the check of the SigHeader for all used ports
                
  @description         Checks for the signal header information that is received by frame medic and that is
                       sent out to the medic subcomponents using the assert.

                       Detailed Design
                       @startuml
                       Start
                       :get pro ports and req ports;
                       :check for sync of Dim ports;
                       :check for sync of HEAD ports;
                       :check for sync of ego signal ports;
                       :assert if not in sync;
                       Stop
                       @enduml

  @return              void
 
  @param[in]           pRequirePorts
  @param[in]           pProvidePorts 
 
  @glob_in             None
  @glob_out            None

  @c_switch_part       MEDIC_CFG_DRIVER_INTENTION_MONITORING,MEDIC_CFG_INCLUDE_UNUSED_INTF,MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION,
                       MEDIC_CFG_ERROR_OUTPUT_VEH
  @c_switch_full       MEDIC_CFG_EMERGENCY_BRAKE_ASSIST, MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK

  @pre                 None
  @post                None

  @InOutCorrelation    Not defined
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Andreas Kramer | Andreas Kramer@continental-corporation.com 
*************************************************************************************************************************/
static void MEDIC_v_CheckProvideHeaders(const reqMEDICPtrList_t *pRequirePorts, const proMEDICPtrList_t *pProvidePorts) 
{
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_CheckProvideHeader(&pProvidePorts->pDIMOutputCustom->sSigHeader, &pRequirePorts->pDIMInputGeneric->sSigHeader);
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_CheckProvideHeader(&pProvidePorts->pHEADOutputGeneric->sSigHeader, &pRequirePorts->pFCTCDHypotheses->sSigHeader);
  MEDIC_v_CheckProvideHeader(&pProvidePorts->pHEADOutputCustom->sSigHeader, &pRequirePorts->pFCTCDHypotheses->sSigHeader);
  #endif
  #if (MEDIC_CFG_ERROR_OUTPUT_VEH)
  MEDIC_v_CheckProvideHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
  #endif
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_v_InitInterCycleData                                                                    */ /*!

  @brief                Initialize the inter cycle data if MEDIC is called in INIT.

  @description          Keep special values to guarantee the function and avoid deadlocks.
                        @startuml MEDIC_v_InitInterCycleData_activity.png
                        start
                          :Get the OpMode provided by FCT 
                          via the VehCtrl Data port;
                          if(OpMode is **MEDIC_MOD_INIT**\nOR MEDIC has not been initialised yet?) then (Yes)
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

  @param[in]            p_MedicProcMem :      Pointers to the memory provided by SW

  @glob_in              @ref MEDIC_p_GetReqPortList
                        @ref MEDIC_p_GetFrameData
  @glob_out             @ref MEDIC_p_ModFrameData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  None 
  @post                 None 

  @remark               All Ports that are used here need to be checked explicitly for a possible Null pointer error!

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1101-0007e0f8}

  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
static void MEDIC_v_InitInterCycleData(MEDIC_ProcMem_t const * const p_MedicProcMem)
{
  /*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
  MEDICOpMode_t eOpMode;

  eOpMode = MEDIC_u_GetOpMode();

  /* Init the complete internal memory if MEDIC is called in init mode or if it was not initialized yet */
  if ((eOpMode == MEDIC_MOD_INIT) || (MEDIC_p_GetFrameData()->bIsInitialized == b_FALSE))
  {
    /* Safe the frame structure to keep specific values after the initialization of the internal memory */
    MEDICFrame_t           sMEDICFrameTemp;
    sint32                 i;
    MEDICPortHandlerList_t sPortHandlerList;

    sMEDICFrameTemp  = *MEDIC_p_GetFrameData();
    sPortHandlerList = *MEDIC_p_GetPortHandlerList();

    if (((eOpMode == MEDIC_MOD_INIT) && (uPreviousOpMode != MEDIC_MOD_INIT)) || (MEDIC_p_GetFrameData()->bIsInitialized == b_FALSE))
    {
      /*PRQA S 0315 2*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
      (void)MEDIC_MEMSET(p_MedicProcMem->pMemInterCycle,     0, sizeof(GA_MEDIC_Mem_DataInterCycle)    );
      (void)MEDIC_MEMSET(p_MedicProcMem->pMemInterCycleMeas, 0, sizeof(GA_MEDIC_Mem_DataInterCycleMeas));

      bHEADInitialized         = b_FALSE;  // HEAD global memory is in InterMeas => all head pointers are deleted and need to be re-initialized
      bHEADInitInputOutputDone = b_FALSE;  // HEAD global memory is in InterMeas => all head pointers are deleted and need to be re-initialized

      /* The MeasCycle monitor has to be preserved */
      for (i = (sint32)(MEDIC_NOF_REQ_PORTS-1u); i >= 0; i--)  /*PRQA S 4548*//* uic45572: no issue as the signed integer is only used with >= operator */
      {
        MEDIC_p_ModPortHandlerList()->ReqPortHandler[i].MeasCycleMonitor = sPortHandlerList.ReqPortHandler[i].MeasCycleMonitor;
      }
    }

    /* The cycle counter should be increased at every call for debug purposes */
    MEDIC_p_ModFrameData()->uiCycleCounter = sMEDICFrameTemp.uiCycleCounter;
    /* The internal init state should be kept after it was set once. */
    MEDIC_p_ModFrameData()->bIsInitialized = sMEDICFrameTemp.bIsInitialized;
  }
  uPreviousOpMode = eOpMode;
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_b_CheckExternalMemorySize                                                             */ /*!

  @brief                Check if the provided external memory is big enough

  @description          Check if the provided external memory is big enough and fill members of diagnostic structure
                        
                        @startuml
                        Start
                        :bSizeTooSmall is assigned FALSE;
                        Partition #LightBlue **(switch)** {
                        :assigning sizeof MEDIC global memory;
                                        }
                        Note right
                        -> When switch USE_MEDICWRAPPER_INTER is ON sizeof Inter  is assigned.
                        -> When switch USE_MEDICWRAPPER_INTERMEAS is ON sizeof Inter meas  is assigned.
                        -> When switch USE_MEDICWRAPPER_INTRAMEAS is ON sizeof Intra meas  is assigned.
                        End note
                        Partition #LightBlue **(switch)** {
                        if(If sizeof global MEMORY is greater than allocated memory ?) then (Yes)
                        :Provided external memory is not big enough and Memory size too small error message is sent ;
                        Partition #LightBlue **(MEDIC_CFG_DIAGNOSTIC_OUTPUT)** {
                        :Respective MEDIC diagnostic member is filled with size of MEMORY is too small;
                                                                               }
                        endif
                                                          }
                        Note right
                        Here switch are
                        -> USE_MEDICWRAPPER_INTER
                        -> USE_MEDICWRAPPER_INTERMEAS
                        -> USE_MEDICWRAPPER_INTRAMEAS
                        End note
                        stop
                        @enduml

  @param[in]            None

  @return               boolean

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_DIAGNOSTIC_OUTPUT
  @c_switch_full....... @ref MEDIC_ARCHITECTURE_VERSION

  @InOutCorrelation     see description

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1101-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
boolean MEDIC_b_CheckExternalMemorySize(void)
{
  boolean bSizeTooSmallError = b_FALSE;

  #if (USE_MEDICWRAPPER_INTER)
  uint32  uiSizeInter     = sizeof(MEDIC_DataWrapperInter_t);
  #endif
  #if (USE_MEDICWRAPPER_INTERMEAS)
  uint32  uiSizeInterMeas = sizeof(MEDIC_DataWrapperInterMeas_t);
  #endif
  #if (USE_MEDICWRAPPER_INTRAMEAS)
  uint32  uiSizeIntraMeas = sizeof(MEDIC_DataWrapperIntraMeas_t);
  #endif

  #if (USE_MEDICWRAPPER_INTER)
  if (uiSizeInter > GA_MEDIC_ASILB_SLOW_INTER_SIZE_MEM_DATA) /* PRQA S 3493,1840,1842,2992,2996*//* reviewer:VoglA, reason: intentional check of external constant */
  {
    bSizeTooSmallError = b_TRUE; /* PRQA S 2880 *//* reviewer:Nalina M, reason: intentional check of external constant */
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bInterSizeTooSmall = b_TRUE;
    #endif
  }
  #endif /* end of MEDIC WRAPPER INTER check */
  #if (USE_MEDICWRAPPER_INTERMEAS)
  if (uiSizeInterMeas > GA_MEDIC_ASILB_SLOW_INTER_MEAS_SIZE_MEM_DATA) /* PRQA S 3494,1840,1842,2996,2880,2992,2996 *//* reviewer:VoglA, reason: intentional check of external constant */
  {
    bSizeTooSmallError = b_TRUE;/* PRQA S 2880 *//* reviewer:Nalina M, reason: intentional check of external constant */
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bInterMeasSizeTooSmall = b_TRUE;
    #endif
  }
  #endif /* end of MEDIC WRAPPER INTER MEAS check */
  #if (USE_MEDICWRAPPER_INTRAMEAS)
  if (uiSizeIntraMeas > GA_MEDIC_ASILB_SLOW_INTRA_MEAS_SIZE_MEM_DATA) /* PRQA S 3493,1840,1842,2992,2996 *//* reviewer:VoglA, reason: intentional check of external constant */
  {
    bSizeTooSmallError = b_TRUE;/* PRQA S 2880 *//* reviewer:Nalina M, reason: intentional check of external constant */
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bIntraMeasSizeTooSmall = b_TRUE;
    #endif
  }
  #endif /* end of MEDIC WRAPPER INTRA MEAS check */

  return bSizeTooSmallError;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_b_CheckNullPointers                                                                   */ /*!

  @brief                Check if any of the required pointers are NULL

  @description          Check if any of the required pointers are NULL, return status and fill diagnostic info structure

                        @startuml
                        Start
                        If(if there is no data in require ports ?) then (yes)
                        :Boolen null pointer error is set to True;
                        Partition #LightBlue **(MEDIC_CFG_DIAGNOSTIC_OUTPUT)** {
                        :Boolen null pointer to MEDIC Request Ports in medic diagnostics is assigned True;
                        }
                        Else(No)
                        If(if there is no data one of the members of ports?) then (yes)
                        :Boolen null pointer error is set to True;
                        Partition #LightBlue **(MEDIC_CFG_DIAGNOSTIC_OUTPUT)** {
                        : Boolen null pointer to corresponding MEDIC Ports in medic diagnostics is assigned True;
                        }
                        endif
                        Note right
                        Here members of require port are.
                        -> control Data.
                        -> Ego Motion signal.
                        -> Vehicle signal.
                        -> Hypothesis .
                        -> Envasion Target .
                        -> ACDC Brake Target .
                        -> ACDC degradation .
                        -> MEDIC Switches .
                        -> MEDIC Vehicle
                        -> MEDIC Driver Monitor
                        -> MEDIC Qualifiers .
                        -> medic custom inputs for BMW when CFG_MEDIC_IN_TOYOTA is enabled .
                        -> MEDIC parameters.
                        -> EBA state control.
                        Provide ports.
                        Provided global memory.
                        Stack data
                        Here checking if any of the above are NULL
                        End note
                        Endif
                        stop
                        @enduml

  @param[in]            p_MedicDiag
                        p_MedicRequirePorts
                        p_MedicProvidePorts
                        p_MedicProcMem
                        p_MedicServices

  @return               boolean
  
  @glob_in              Null
  @glob_out             Null

  @c_switch_part        @ref MEDIC_CFG_DIAGNOSTIC_OUTPUT
  @c_switch_full        @ref MEDIC_ARCHITECTURE_VERSION

  @InOutCorrelation     see description

  @traceability         
  ......................@satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com

*************************************************************************************************************************/
boolean MEDIC_b_CheckNullPointers(MEDIC01_ReqPorts const*const p_MedicRequirePorts, MEDIC01_ProPorts const*const p_MedicProvidePorts, MEDIC_ProcMem const*const p_MedicProcMem, MEDIC_Services const*const p_MedicServices)
{
  boolean bNullPointerError = b_FALSE;

  // check request ports for null pointers
  if (p_MedicRequirePorts == NULL)
  {
    bNullPointerError                         = b_TRUE;
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bRequirePortsNull = b_TRUE;
    #endif
  }
  else
  {
    if (p_MedicRequirePorts->controlData == NULL)
    {
      bNullPointerError                        = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bControlDataNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->egoMotion == NULL)
    {
      bNullPointerError                      = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bEgoMotionNull = b_TRUE;
      #endif
    }
    #if (MEDIC_CFG_USE_VDY)
    if (p_MedicRequirePorts->vDY_In == NULL)
    {
      bNullPointerError = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bVehDyn_InNull = b_TRUE;
      #endif
    }
    #endif
    if (p_MedicRequirePorts->vehSig == NULL)
    {
      bNullPointerError                   = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bVehSigNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->hypothesis == NULL)
    {
      bNullPointerError                       = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bHypothesisNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->evasionTargets == NULL)
    {
      bNullPointerError                           = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bEvasionTargetsNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->brakeTargets == NULL)
    {
      bNullPointerError                         = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bBrakeTargetsNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->degradation == NULL)
    {
      bNullPointerError                        = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bDegradationNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->switches == NULL)
    {
      bNullPointerError                     = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bSwitchesNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->vehicle == NULL)
    {
      bNullPointerError                    = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bVehicleNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->driverMonitor == NULL)
    {
      bNullPointerError                          = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bDriverMonitorNull = b_TRUE;
      #endif
    }
    #if (CFG_MEDIC_IN_TOYOTA == 1)
    if (p_MedicRequirePorts->customInput_TMC == NULL)
    {
      bNullPointerError             = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bCustomInputTMCNull = b_TRUE;
      #endif
    }
    #endif
    if (p_MedicRequirePorts->medicParameters == NULL)
    {
      bNullPointerError                            = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bMedicParametersNull = b_TRUE;
      #endif
    }
    if (p_MedicRequirePorts->ebaStateControl == NULL)
    {
      bNullPointerError                            = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bEbaStateControlNull = b_TRUE;
      #endif
    }
    /*
    #if (CFG_MEDIC_IN_BMW == 1)
    if (p_MedicRequirePorts->customInput_BMW == NULL)
    {
      // bNullPointerError = b_TRUE;   => activate when connected in SIL
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bCustomInputBMWNull = b_TRUE;
      #endif
    }
    #endif
    if (p_MedicRequirePorts->loggingInfo == NULL)
    {
      // bNullPointerError = b_TRUE;  => activate when connected in SIL
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bloggingInfoNull = b_TRUE;
      #endif
    }
    */
  }

  // check provide ports for null pointers
  if (p_MedicProvidePorts == NULL)
  {
    bNullPointerError                         = b_TRUE;
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bProvidePortsNull = b_TRUE;
    #endif
  }
  if (p_MedicProcMem == NULL)
  {
    bNullPointerError                    = b_TRUE;
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bProcMemNull = b_TRUE;
    #endif
  }
  if (p_MedicServices == NULL)
  {
    bNullPointerError                     = b_TRUE;
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bServicesNull = b_TRUE;
    #endif
  }

  // check the provided global memory for null pointers
  if (p_MedicProcMem != NULL)
  {
    #if (USE_MEDICWRAPPER_INTER)
    if (p_MedicProcMem->memASILBSlowInter == NULL)
    {
      bNullPointerError                      = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bInterCyleNull = b_TRUE;
      #endif
    }
    #endif
    #if (USE_MEDICWRAPPER_INTERMEAS)
    if (p_MedicProcMem->memASILBSlowInterMeas == NULL)
    {
      bNullPointerError                          = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bInterCyleMeasNull = b_TRUE;
      #endif
    }
    #endif
    #if (USE_MEDICWRAPPER_INTRAMEAS)
    if (p_MedicProcMem->memASILBSlowIntraMeas == NULL)
    {
      bNullPointerError                          = b_TRUE;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->bIntraCyleMeasNull = b_TRUE;
      #endif
    }
    #endif
  }
  if (MEDIC_p_ModWorkingData()->pStackData == NULL)
  {
    bNullPointerError                      = b_TRUE;
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    MEDIC_p_ModMEDICDiag()->bStackDataNull = b_TRUE;
    #endif
  }

  return bNullPointerError;
} /* PRQA S 7004, 7002 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing cyclomatic complexity for better code maintainability */

/*************************************************************************************************************************
  Functionname:         MEDIC01_v_Exec                                                                              */ /*!

  @brief                Main function of the MEDIC Component. Calls all subcomponents, handles pointer checks and operation modes 

  @description          MEDIC execution cycle for new architecture (FSF.500)
                        @startuml
                        Start
                        Partition #LightBlue **(MEDIC_CFG_USE_ALGOCOMPSTATE)** {
                        #orange:Update the MEDIC global error buffer to ALGO_QUAL_OK;
                                        }
                        if(p_MedicProcMem is not NULL?) then (yes)
                        Partition #LightBlue **(USE_MEDICWRAPPER_INTER)** {
                        #orange:Initialising InterCycle;
                                        }
                        Partition #LightBlue **(USE_MEDICWRAPPER_INTERMEAS)** {
                        #orange:Initialising InterCycle Meas;
                                        }
                        Partition #LightBlue **(USE_MEDICWRAPPER_INTRAMEAS)** {
                        #orange:Initialising IntraCycle Meas;
                                        }
                        #orange:Assign memory to structures of medic
                        <b> MEDIC_e_AssignStaticMemoryToAccessData <b> >
                        #orange: Checks if memory size provided is big enough and puts into  diagnostic
                        <b> MEDIC_b_CheckExternalMemorySize <b> >
                        if((Is static memory error null?) AND (bMemorySizeError == b_TRUE?)) then (yes)
                        :Set as memory size too low,set this only if there is no other error ;
                        Endif
                        Partition #LightBlue **(MEDIC_CFG_DIAGNOSTIC_OUTPUT)** {
                        if(pointer to inter cycle meas is not null?) then (yes)
                        if(pointer to the diagnostic info structure is not null?) then (yes)
                        :diagnostics info is available;
                        endif
                        Endif
                        If(If diagnostics info is available ?) then (yes)
                        :Reset diagnostic infomation structure ;
                        #orange:Check if any required ports are assigned to null
                        <b> MEDIC_b_CheckNullPointers <b> >
                        Else(No)
                        endif
                        :Set Null pointer error to true;
                                        }
                        #orange:Check if any required ports are assigned to null
                        <b> MEDIC_b_CheckNullPointers <b> >
                        Else(No)
                        :Set Null pointer error to true;
                        Endif
                        if((Is there is no any memory error?) AND (IF none of required ports are NULL?)) then (yes)
                        Partition #LightBlue **(USE_MEDICWRAPPER_INTRAMEAS)** {
                        if(If pointer to Intra Cycle Meas is not Null ?) then (Yes)
                        :Reset intra Cycle meas;
                        endif
                                       }
                        #orange:Input is assigned with required ports and output with provide ports
                        <b> MEDIC_v_AssignAccessPointers <b> >
                        Note left:initialising input/outputs .
                        #orange:Initialize data for inter cycle
                        <b> MEDIC_v_InitInterCycleData <b> >
                        Note left:Initialize inter cycle.
                        #orange:checking and setting up of ports all internal data
                        <b> MEDIC_v_ProcessPorts <b> >
                        Note left:Checking and setting ports.
                        if((If medic state not initialised?) OR (If medic state set to running?)) then (yes)
                        if(If medic state not initialised?) then (yes)
                        #orange: status of algo initiailization is reset .
                        <b> MEDIC_v_AlgoInit <b> >
                        Note left:Also initialization is reset.
                        Else(No)
                        :First cycle check is set to true;
                        Endif
                        Partition #LightBlue **(MEDIC_CFG_DRIVER_INTENTION_MONITORING)** {
                        #orange:initialize DIM module, takes inputs and generates output
                        <b> DIMProcess <b> >
                        Note left:main function of DIM.
                                     }
                        Partition #LightBlue **(MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)** {
                        #orange:initialise head wrapper.
                        <b> HEADProcess <b> >
                        Note left:initialises head wrapper.
                                     }
                        Partition #LightBlue **(MEDIC_CFG_TARGET_PLANNER)** {
                        #orange:initialise process.
                        <b> TPProcess <b> >
                        Note left:initialise sprocess.
                                     }
                        #orange:Checking headers for ports.
                        <b> EDIC_v_CheckProvideHeaders <b> >
                        #orange:Setting MEDIC component state.
                        <b> MEDIC_v_SetCompState <b> >
                        :Medic is neither initialies nor running;
                        Else(No)
                        #orange: status of algo initiailization is reset .
                        <b> MEDIC_v_AlgoInit <b> >
                        #orange:Setting MEDIC component state.
                        <b> MEDIC_v_SetCompState <b>
                        :Medic is neither initialies nor running;
                        Endif
                        #orange:Headers of provide port signals are filled.
                        <b> MEDIC_v_FillProPortHeaders <b> >
                        Note left:provide port signals are filled.
                        #orange:Brake cascade ports are filled.
                        <b> HEADSetBrakeCascadePort <b> >
                        Partition #LightBlue **(MEDIC_ARCHITECTURE_VERSION)** {
                        #orange:Freeze data meas for MEDIC ports .
                        <b> MEDIC_v_FreezePorts <b> >
                        #orange:Freeze working data of medic.
                        <b> MEDIC_v_FreezeWorkingData <b> >
                                          }
                        Else(NO)
                        #orange:error during assignment of static memory or NULL pointers received from frame software.
                        <b> MEDIC_v_SetCompState <b> >
                        Endif
                        if(If simulation Output is not NULL?) then (Yes)
                        #orange:Provides pointer to internal data.
                        <b> MEDIC_SimulationOutput <b> >
                        Note right:Provides pointer to internal data.
                        Endif
                        If(if service pointer not null?) then (yes)
                        :Nothing;
                        endif
                        stop
                        @enduml

  @return               void

  @param[in]            p_ServiceFuncts : Service functions structure
  @param[in]            p_MedicRequirePorts : MEDIC require port structure
  @param[in]            p_MedicProvidePorts : MEDIC provide port structure
  @param[in,out]        p_MedicProcMem : pointer to GA data

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_USE_ALGOCOMPSTATE
                        @ref MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING
                        @ref MEDIC_CFG_RTA_PROFILING
                        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS
                        @ref MEDIC_CFG_USE_FREEZE_CYCLE_START
                        @ref MEDIC_CFG_MEASUREMENT
                        @ref MEDIC_SIMU
                        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
                        @ref MEDIC_CFG_DIAGNOSTIC_OUTPUT
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1101-0007e0f8}


  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void MEDIC01_Exec(MEDIC01_ReqPorts const*const p_MedicRequirePorts, /*PRQA S 0624,1330 */
                  MEDIC01_ProPorts const*const p_MedicProvidePorts, /*PRQA S 0624,1330 */
                  MEDIC_ProcMem    const*const p_MedicProcMem     , /*PRQA S 0624,1330 */
                  MEDIC_Services   const*const p_MedicServices    ) /*PRQA S 0624,1330 */ /*Reviewer : Nagaraja Veerashettappa : Change of variable names and type names is intended*/ 
{
  eGDBError_t              eStaticMemoryError = GDB_ERROR_NONE;
  boolean                  bNullPointerError;
  boolean                  bMemorySizeError;
  #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
  boolean                  bDiagAvailable = b_FALSE;
  #endif
  MEDIC_DataWrapperStack_t MEDICStackData = {0};
  MEDIC_ProcMem_t          MEDICProcMem   = {0};

  #if (MEDIC_CFG_RTA_PROFILING)
  MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PROCESS       , 0); // runtime of the whole exec function (start)
  MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PREPRE_PROCESS, 0); // preprocessing runtime (start)
  #endif

  #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
  /* global Error buffer */
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
  #endif

  /* PRQA S 3212,0310,3305 12 *//* 2019-Sep-18, reviewer: Armin Vogl, casts are needed to avoid compiler warning about different array subscripts */
  if (p_MedicProcMem != NULL)
  {
    #if (USE_MEDICWRAPPER_INTER)
    MEDICProcMem.pMemInterCycle     = (GA_MEDIC_Mem_DataInterCycle     *)p_MedicProcMem->memASILBSlowInter; 
    #endif
    #if (USE_MEDICWRAPPER_INTERMEAS)
    MEDICProcMem.pMemInterCycleMeas = (GA_MEDIC_Mem_DataInterCycleMeas *)p_MedicProcMem->memASILBSlowInterMeas;
    #endif
    #if (USE_MEDICWRAPPER_INTRAMEAS)
    MEDICProcMem.pMemIntraCycleMeas = (GA_MEDIC_Mem_DataIntraCycleMeas *)p_MedicProcMem->memASILBSlowIntraMeas;
    #endif

    // Assign the input memory pointer to MEDIC structures
    eStaticMemoryError = MEDIC_e_AssignStaticMemoryToAccessData(&MEDICProcMem, &MEDICStackData);

    // Check if the provided memory size is big enough and add info to diagnostic structure
    bMemorySizeError = MEDIC_b_CheckExternalMemorySize();
    if ((eStaticMemoryError == GDB_ERROR_NONE) && (bMemorySizeError == b_TRUE))
    {
      eStaticMemoryError = GDB_ERROR_ARRAY_SIZE_TOO_LOW;  // only fill if no other error is present
    }

    // Check if the pointer to diagnostic info is available
    #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
    if ((MEDICAccessData.Working.pInterCycleMeas != NULL))
    {
      if (MEDIC_p_ModMEDICDiag() != NULL)
      {
        bDiagAvailable = b_TRUE;
      }
    }
    if (bDiagAvailable == b_TRUE)
    {
      // Clear diagnostic info
      MEDIC_MEMSET(MEDIC_p_ModMEDICDiag(), 0, sizeof(MEDIC_Diagnostic_t)); /*PRQA S 0315*/ /* date: 2019-11-13, reviewer: VoglA, reason: cast to void intended (use of generic interface) */

      // Check interface for NULL pointers
      bNullPointerError = MEDIC_b_CheckNullPointers(p_MedicRequirePorts, p_MedicProvidePorts, p_MedicProcMem, p_MedicServices);
    }
    else
    {
      bNullPointerError = b_TRUE;
    }
    #else
    bNullPointerError = MEDIC_b_CheckNullPointers(p_MedicRequirePorts, p_MedicProvidePorts, p_MedicProcMem, p_MedicServices);
    #endif
  }
  else
  {
    bNullPointerError = b_TRUE;
  }

  if ((eStaticMemoryError == GDB_ERROR_NONE) && (bNullPointerError == b_FALSE))  
  {
    // Reset the structure to guarantee the non-persistent behavior of the memory
    #if (USE_MEDICWRAPPER_INTRAMEAS)
    if (MEDICProcMem.pMemIntraCycleMeas != NULL)
    {
      /* PRQA S 0315 1 */ /* date: 2019-Sep-18, reviewer: VoglA, reason: cast to void is intended (use of generic interface) */
      MEDIC_MEMSET(MEDICProcMem.pMemIntraCycleMeas, 0, sizeof(GA_MEDIC_Mem_DataIntraCycleMeas));
    }
    #endif

    MEDIC_v_AssignAccessPointers(p_MedicRequirePorts,
                                 p_MedicProvidePorts
                                 #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                                 ,p_MedicServices
                                 #endif
                                );

    // Init the inter cycle data
    MEDIC_v_InitInterCycleData(&MEDICProcMem);

    /*---------------------------------------------------------------------------*/
    /* Start data preparation                                                    */
    /*---------------------------------------------------------------------------*/
    MEDIC_v_ProcessPorts(MEDIC_p_GetReqPortList()
                        ,MEDIC_p_ModProPortList()
                        ,MEDIC_p_ModPortHandlerList()
                        #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                        ,MEDIC_p_GetServiceFuncts()
                        #endif
                        #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
                        ,&AlgoErrorBuffer
                        #endif
                        ); 

    // Calculate real algorithm cycle time 
    MEDIC_v_CalculateCycleTime(p_MedicServices);
    
    if ((MEDIC_p_GetFrameData()->eMEDICState == COMP_STATE_NOT_INITIALIZED) || (MEDIC_p_GetFrameData()->eMEDICState == COMP_STATE_RUNNING))
    {
      /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
      /*Init in init Mode*/
      if (MEDIC_p_GetFrameData()->eMEDICState == COMP_STATE_NOT_INITIALIZED)
      {
        MEDIC_v_AlgoInit();
      }
      else
      {
        MEDIC_p_ModFrameData()->bFirstCycleDone = b_TRUE;
      }
      
      #if (MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
      if ( MEDIC_v_CheckInputUpdate(p_MedicRequirePorts, &FCTVehMedicInputCounters, MEDIC_f_GetCycleTime(), FCT_VEH_TARGET_CYCLE_TIME) != 0u )   /*error condition*/
      {
        MEDIC_v_SetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
      }
      #endif /* MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING */

      #if ((MEDIC_CFG_USE_FREEZE_CYCLE_START) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* send MTS Freeze Cycle Start */
      if ((MEDIC_p_GetServiceFuncts() != NULL) && ((MEDIC_p_GetServiceFuncts()->pfMeasStartFuncCycle) != NULL))
      {
        (MEDIC_p_GetServiceFuncts()->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (MEDIC_MEAS_FUNC_CHAN_ID));
      }
      #endif

      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PREPRE_PROCESS, 0); // preprocessing runtime (end)
      #endif

      #if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
      /*---------------------------------------------------------------------------*/
      /* Start DIM                                                                 */
      /*---------------------------------------------------------------------------*/
      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_DIM_PROCESS, 0); // DIM runtime (start)
      #endif

      DIMProcess(MEDIC_f_GetCycleTime());

      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_DIM_PROCESS, 0); // DIM runtime (end)
      #endif
      #endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */

      #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
      /*---------------------------------------------------------------------------*/
      /* Start HEAD                                                                */
      /*---------------------------------------------------------------------------*/
      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_PROCESS, 0); // HEAD runtime (start)
      #endif

      (void)HEADProcess(MEDIC_f_GetCycleTime());

      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_PROCESS, 0); // HEAD runtime (end)
      #endif
      #endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */

      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_TP_PROCESS, 0); // TP runtime (start)
      #endif

      #if MEDIC_CFG_TARGET_PLANNER
      (void)TPProcess();
      #endif

      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_TP_PROCESS, 0); // TP runtime (end)
      #endif

      #if defined(MEDIC_SIMU) && (MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK)
      MEDIC_v_CheckProvideHeaders(p_MedicRequirePorts, p_MedicProvidePorts); 
      #endif

      #if (MEDIC_CFG_MEASUREMENT)
      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PROCESSFREEZE, 0); // Processfreeze (start)
      #endif

      /* Set MEDIC Component State */
      MEDIC_v_SetCompState(COMP_STATE_SUCCESS, COMP_ERROR_NO_ERROR);

      /* Computation chain ran through. MEDIC is initialized or running. */
      MEDIC_p_ModFrameData()->bIsInitialized = b_TRUE;

      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PROCESSFREEZE, 0); // Processfreeze (end)
      #endif
      #endif /* MEDIC_CFG_MEASUREMENT */
    }
    else  /************************* end of non-error path, beginning of error path *************************/
    {
      #if (MEDIC_CFG_RTA_PROFILING)
      MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PREPRE_PROCESS, 0); // preprocessing runtime (end)
      #endif

      /* MEDIC_MOD_SHUTDOWN => fill invalidate the available provide ports and fill whole sigHeader */
      #if ((MEDIC_CFG_USE_FREEZE_CYCLE_START) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      if ((MEDIC_p_GetServiceFuncts() != NULL) && (MEDIC_p_GetServiceFuncts()->pfMeasStartFuncCycle != NULL))
      {
        /* send MTS Freeze Cycle Start if Service is available */
        (MEDIC_p_GetServiceFuncts()->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (MEDIC_MEAS_FUNC_CHAN_ID));
      }
      #endif

      /* Init MEDIC Algo */
      MEDIC_v_AlgoInit();

      /* Set MEDIC Component State */
      if (p_MedicProvidePorts->algoCompState->eCompState != COMP_STATE_ERROR)
      {
          MEDIC_v_SetCompState(COMP_STATE_SUCCESS, COMP_ERROR_NO_ERROR);
      }
      /* make sure in error case init of sub components is performed next cylcle */
      MEDIC_p_ModFrameData()->bIsInitialized = b_FALSE;
    } /*********************** end of error path, beginning common *******************************/

    #if (MEDIC_CFG_RTA_PROFILING)
    MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_POSTPROCESS, 0); // post processing runtime (start)
    #endif

    MEDIC_v_FillProPortHeaders(MEDIC_p_ModPortHandlerList());  
    
    // Fill the brake cascade provide port
    HEADSetBrakeCascadePort();
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    #if (MEDIC_CFG_RTA_PROFILING)
    MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_FRAMEFREEZE, 0); // framefreeze (start)
    #endif

    /* Process meas freezes */
    MEDIC_v_FreezePorts(MEDIC_p_GetPortHandlerList());
    #if (MEDIC_CFG_RTA_PROFILING)
    MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_FRAMEFREEZE, 0); // framefreeze (end)
    #endif
    #if (MEDIC_CFG_RTA_PROFILING)
    MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_FRAMEFREEZE, 1); // framefreeze (start)
    #endif

     /* Freeze all working data */
    MEDIC_v_FreezeWorkingData(MEDIC_p_GetWorkingData());

    #if (MEDIC_CFG_RTA_PROFILING)
    MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_FRAMEFREEZE, 1); // framefreeze (end)
    #endif 
    #endif
    #if (MEDIC_CFG_RTA_PROFILING)
    MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_POSTPROCESS, 0); // post processing runtime (end)
    #endif  
  }
  else
  {
    // error during assignment of static memory or NULL pointers received from frame software
    MEDIC_v_SetCompState(COMP_STATE_ERROR, COMP_ERROR_INPUT_INTERFACE_NULL);
  }
 #if(MEDIC_CFG_ENABLE_DEM_OUTPUT)
 #if(MEDIC_FCTDATA_OUT_INTFVER == 12u)
  if ((p_MedicProvidePorts != NULL) && (p_MedicProvidePorts->fctData != NULL)&&(p_MedicProvidePorts->algoCompState != NULL))
  {
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.eCompState                      = p_MedicProvidePorts->algoCompState->eCompState;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.eErrorCode                      = p_MedicProvidePorts->algoCompState->eErrorCode;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.uiAlgoVersionNumber             = p_MedicProvidePorts->algoCompState->uiAlgoVersionNumber;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.uiVersionNumber                 = p_MedicProvidePorts->algoCompState->uiVersionNumber;
      // p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.sSigHeader.a_reserve            = p_MedicProvidePorts->algoCompState->sSigHeader.a_reserve;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.sSigHeader.eSigStatus           = p_MedicProvidePorts->algoCompState->sSigHeader.eSigStatus;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.sSigHeader.uiCycleCounter       = p_MedicProvidePorts->algoCompState->sSigHeader.uiCycleCounter;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.sSigHeader.uiMeasurementCounter = p_MedicProvidePorts->algoCompState->sSigHeader.uiMeasurementCounter;
      p_MedicProvidePorts->fctData->AlgoCompStateFcuCopy.sSigHeader.uiTimeStamp          = p_MedicProvidePorts->algoCompState->sSigHeader.uiTimeStamp;
  }
 #endif
 #endif
  #ifdef MEDIC_SIMU
  if (MEDIC_SimulationOutput != NULL)
  {
    // Provide the pointer to internal data (including stack data) for output in simulation framework
    MEDIC_SimulationOutput(&MEDICAccessData);
  }
  #endif
  if (p_MedicServices != NULL)
  {
    // avoid _PARAM_UNUSED(p_MedicServices); QAF message
  }
  #if (MEDIC_CFG_RTA_PROFILING)
  MEDIC_v_AlgoServiceAddEvent(p_MedicServices, e_RTA_EVT_AlgoEnd  , (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_PROCESS, 0); // runtime of the whole exec function (end)
  #endif
} /*PRQA S 7002 */ /*date: 2020-10-21, Reviewer: Siri Prakash, Reason:suppressing cyclomatic complexity for better code maintainability*/  

/*************************************************************************************************************************
  Functionname:        MEDIC_v_CalculateCycleTime                                                                   */ /*!

  @brief               Calculate the MEDIC algorithm cycle time

  @description         Calculate the MEDIC algorithm cycle time
                       @startuml
                       Start
                       :Initialize with default cycle time;
                       Partition #LightBlue **(MEDIC_CFG_CALC_CYCLETIME_USING_CONTROLDATA)** {
                       If (MEDIC Control data not NULL) then(yes)
                        If (New timestamp is larger than the one from last cycle) then(yes)
                         If (Previous cycle time stamp != 0) then(yes)
                          :Cycle time = Current Time Stamp – Previous Time Stamp;
                         Endif
                        Endif
                        :Store current timestamp as reference for next cycle;
                       Else(no)
                        :Set timestamp to zero;
                       Endif
                                      }
                       Partition #LightBlue **(MEDIC_CFG_CALC_CYCLETIME_USING_SERVICEFUNCTION)** {
                       If (MEDIC Service pointer and its Real Time time-stamp not NULL) then(yes)
                        If (New timestamp is larger than the one from last cycle) then(yes)
                         If (Previous cycle time stamp != 0) then(yes)
                          :Cycle time = Current Time Stamp – Previous Time Stamp;
                         Endif
                        Endif
                        :Store current timestamp as reference for next cycle;
                        If (cycle time < 10 ms) then(yes)
                         :Limit cycle time to a minimum of 10 ms;
                        Endif
                        If (cycle time > 200 ms) then(yes)
                         :Limit cycle time to a maximum of 200 ms;
                        Endif
                       Else(no)
                        :Set timestamp to zero;
                       Endif
                                      }
                       Stop
                       @enduml

  @return              void

  @param[out]          None
  @param[in]           p_MedicServices : Service pointer

  @glob_in             MEDIC_p_ModAlgoTimestamp \n
                       MEDIC_p_ModAlgoCycleTime
  @glob_out            MEDIC_p_ModAlgoTimestamp \n
                       MEDIC_p_ModAlgoCycleTime

  @c_switch_part       @ref MEDIC_CFG_CALC_CYCLETIME_USING_CONTROLDATA \n
                       @ref MEDIC_CFG_CALC_CYCLETIME_USING_SERVICEFUNCTION
  @c_switch_full   ....@ref MEDIC_ARCHITECTURE_VERSION

  @InOutCorrelation    see the description

  @testmethod          Test of output data (dynamic module test)

  @traceability        Design Decision

  @author              Armin Vogl | Armin.Vogl@continental-corporation.com
*************************************************************************************************************************/
void MEDIC_v_CalculateCycleTime(MEDIC_Services const*const p_MedicServices)
{
  // Initialize with default cycle time
  *MEDIC_p_ModAlgoCycleTime() = (uint32)(MEDIC_CYCLE_TIME * 1000000.0f);

  #if (MEDIC_CFG_CALC_CYCLETIME_USING_CONTROLDATA == MEDIC_ON)
  // --------------------------------------------------------------------------------------------
  // Calculate the MEDIC cycle time by evaluating the signal header timestamp of port controlData
  // --------------------------------------------------------------------------------------------
  if (MEDICAccessData.Input.ReqPorts.controlData != NULL)
  {
    if (MEDICAccessData.Input.ReqPorts.controlData->sigHeader.uiTimeStamp > *MEDIC_p_ModAlgoTimestamp())
    {
      // New timestamp is larger that the one from last cycle => cycle time can be calculated
      if (*MEDIC_p_ModAlgoTimestamp() != 0u)
      {
        *MEDIC_p_ModAlgoCycleTime() = (uint32)(MEDICAccessData.Input.ReqPorts.controlData->sigHeader.uiTimeStamp - *MEDIC_p_ModAlgoTimestamp());
      }
    }
    // store current timestamp as reference for next cycle
    *MEDIC_p_ModAlgoTimestamp() = MEDICAccessData.Input.ReqPorts.controlData->sigHeader.uiTimeStamp;
  }
  else
  {
    *MEDIC_p_ModAlgoTimestamp() = 0u;
  }
  _PARAM_UNUSED(p_MedicServices); /*PRQA S 3119 *//* date: 2020-10-21, Reviewer:Siri Prakash, Reason: Needed for future implementation */
  #endif

  #if (MEDIC_CFG_CALC_CYCLETIME_USING_SERVICEFUNCTION == MEDIC_ON)
  // ---------------------------------------------------------------------------------------
  // Calculate the MEDIC cycle time by using a service function to get the current timestamp
  // ---------------------------------------------------------------------------------------
  if ((p_MedicServices != NULL) && (p_MedicServices->pfGetTimestamp64Us != NULL))
  {
    if ((p_MedicServices->pfGetTimestamp64Us)() > *MEDIC_p_ModAlgoTimestamp())
    {
      // New timestamp is larger that the one from last cycle => cycle time can be calculated
      if (*MEDIC_p_ModAlgoTimestamp() != 0u)
      {
        *MEDIC_p_ModAlgoCycleTime() = (uint32)((p_MedicServices->pfGetTimestamp64Us)() - *MEDIC_p_ModAlgoTimestamp());
      }
    }
    // store current timestamp as reference for next cycle
    *MEDIC_p_ModAlgoTimestamp() = (p_MedicServices->pfGetTimestamp64Us)();

    // Limit cycle time to a minimum of 10 ms
    if (*MEDIC_p_ModAlgoCycleTime() < 10000u)
    {
      *MEDIC_p_ModAlgoCycleTime() = 10000u;
    }
    // Limit cycle time to a maximum of 200 ms
    if (*MEDIC_p_ModAlgoCycleTime() > 200000u)
    {
      *MEDIC_p_ModAlgoCycleTime() = 200000u;
    }
  }
  else
  {
    *MEDIC_p_ModAlgoTimestamp() = 0u;
  }
  #endif

  #if ((MEDIC_CFG_CALC_CYCLETIME_USING_CONTROLDATA == MEDIC_OFF) && (MEDIC_CFG_CALC_CYCLETIME_USING_SERVICEFUNCTION == MEDIC_OFF))
  // No timestamp shall be used -> initialize with 0
  *MEDIC_p_ModAlgoTimestamp() = 0u;
  _PARAM_UNUSED(p_MedicServices);
  #endif
}
#endif

#ifdef MEDIC_SIMU
/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetSimulationOutputCallback                                                                  */ /*!

  @brief                Assigning simulation output.

  @description          Assigning MEDIC simulation output.

  @return               None

  @param[in]            MEDICAccessData_t

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        None

  @pre                  None
  @post                 @ref MEDIC_SIMU

  @InOutCorrelation     see description

  @traceability         Design Decision

  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
void MEDIC_v_SetSimulationOutputCallback(void(*func)(MEDICAccessData_t*))
{
  MEDIC_SimulationOutput = func;
}
#endif


#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*************************************************************************************************************************
  Functionname:         MEDIC_v_Exec                                                              */ /*!

  @brief                Main function of the MEDIC Component. Calls all subcomponents, handles pointer checks and operation modes 

  @description          First function call for the FCT VEH cycle execution 
                        @startuml
                        start
                          :Update the MEDIC global error buffer
                          And Cycle time with current data;
                          :Initialize the RTA profiling switches;
                          :Update the Medic frame data;
                        Note right: Function call to update the frame data and operation modes
                          :EBA process states;
                        Note right:Setup opmodes and process states for all the subcomponents  
                        if(MEDIC State is error?) then (No)
                            :setup input header FCTVeh sync structure;
                          Note right : MEDIC algo Initialization
                            :Copy cycle information;
                            :start the DIM module; 
                          Note right: function call to DIM 
                            :start the HEAD module;
                          Note right: function call to HEAD 
                            :start the measurement; 
                          Note right: cycle start for MTS freeze 
                            :EBA data frame freeze;
                        else(Yes)
                            :Reset provide ports;
                            :Initialize all data;
                        endif
                            :Freeze all frame information for mts;
                        stop
                        @enduml

  @return               void
 
  @param[in]            p_ServiceFuncts : Service functions structure 
  @param[in]            p_MedicRequirePorts : MEDIC require port structure
  @param[in]            p_MedicProvidePorts : MEDIC provide port structure 
  @param[in,out]        p_MedicProcMem : pointer to GA data
 
  @glob_in              None
  @glob_out             b_IsMedicInitialized: flag showing that at least one algo cycle is completed

  @c_switch_part        @ref MEDIC_CFG_USE_ALGOCOMPSTATE
                        @ref MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING
                        @ref MEDIC_CFG_RTA_PROFILING
                        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS
                        @ref MEDIC_CFG_USE_FREEZE_CYCLE_START
                        @ref MEDIC_CFG_MEASUREMENT
                        @ref MEDIC_SIMU
                        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com
*************************************************************************************************************************/
void MEDIC_v_Exec(const reqMEDICPtrList_t *p_MedicRequirePorts 
                  ,proMEDICPtrList_t *p_MedicProvidePorts
                  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                  ,const AS_t_ServiceFuncts *p_ServiceFuncts 
                  #endif
                  #if (!MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY)
                  ,MEDIC_ProcMem_t    const * const p_MedicProcMem
                  #endif
                 )
{
  eGDBError_t eStaticMemoryError;
  MEDIC_DataWrapperStack_t MEDICStackData = {0};

  #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
  /* global Error buffer */
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
  #endif

  #if MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY
  /* MEDIC process memory */
  MEDIC_ProcMem_t               MEDICProcMem = {0};
  MEDIC_ProcMem_t const * const p_MedicProcMem = &MEDICProcMem;
  /* Assign memory pointer */
  MEDICProcMem.pMemInterCycle     = &MEDICInter;
  MEDICProcMem.pMemInterCycleMeas = &MEDICInterMeas;
  MEDICProcMem.pMemIntraCycleMeas = &MEDICIntraMeas;

  /* Reset the structure to guarantee the non-persistent behavior of the memory */
  MEDIC_MEMSET(&MEDICIntraMeas, 0, sizeof(GA_MEDIC_Mem_DataIntraCycleMeas)); /* PRQA S 0315 *//* pointer type cannot be changed in the function and has no functional impact */

  #endif // MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY

  /************************************************************************/
  /* Assign the input memory pointer to MEDIC structures                   */
  /************************************************************************/
  eStaticMemoryError = MEDIC_e_AssignStaticMemoryToAccessData(p_MedicProcMem, &MEDICStackData);

  if (eStaticMemoryError == GDB_ERROR_NONE)
  {
    /************************************************************************/
    /*                 Copy ports structure to AccessData                   */
    /************************************************************************/
    MEDIC_v_AssignAccessPointers( p_MedicRequirePorts,
                                  p_MedicProvidePorts
                                  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                                  ,p_ServiceFuncts
                                  #endif
                                );

    /* Init the inter cycle data if all conditions are fulfilled */
    MEDIC_v_InitInterCycleData(p_MedicProcMem);

    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    if (MEDIC_p_GetServiceFuncts() != NULL)
    {
      /* Sends RTA-Start event for whole procedure runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_PROCESS, 0);
      /* Sends RTA-Start event for data preparation runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_PREPRE_PROCESS, 0);
    }
    #endif

    /*---------------------------------------------------------------------------*/
    /* Start data preparation                                                    */
    /*---------------------------------------------------------------------------*/
    MEDIC_v_ProcessPorts(MEDIC_p_GetReqPortList()
                        ,MEDIC_p_ModProPortList()
                        ,MEDIC_p_ModPortHandlerList()
                        #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                        ,MEDIC_p_GetServiceFuncts()
                        #endif
                        #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
                        ,&AlgoErrorBuffer
                        #endif
                        ); 

    if ((MEDIC_p_GetFrameData()->eMEDICState == COMP_STATE_NOT_INITIALIZED) || (MEDIC_p_GetFrameData()->eMEDICState == COMP_STATE_RUNNING))
    {
      /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
      /*Init in init Mode*/
      if (MEDIC_p_GetFrameData()->eMEDICState == COMP_STATE_NOT_INITIALIZED)
      {
        MEDIC_v_AlgoInit();
      }
      else
      {
        MEDIC_p_ModFrameData()->bFirstCycleDone = b_TRUE;
      }
      #if (MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
      if ( MEDIC_v_CheckInputUpdate(p_MedicRequirePorts, &FCTVehMedicInputCounters, MEDIC_f_GetCycleTime(), FCT_VEH_TARGET_CYCLE_TIME) != 0u )   /*error condition*/
      {
        MEDIC_v_SetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
      }
      #endif /* MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING */

      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-End event for data preparation runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_PREPRE_PROCESS, 0);
      #endif

      #if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
      /*---------------------------------------------------------------------------*/
      /* Start DIM                                                                 */
      /*---------------------------------------------------------------------------*/
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-Start event for Driver Intention Monitoring runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_DIM_PROCESS, 0);
      #endif

      DIMProcess(MEDIC_f_GetCycleTime());

      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-End event for Driver Intention Monitoring runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_DIM_PROCESS, 0);
      #endif
      #endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */

      #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
      /*---------------------------------------------------------------------------*/
      /* Start HEAD                                                                */
      /*---------------------------------------------------------------------------*/
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-Start event for Hypothesis Evaluation and Decision runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_HEAD_PROCESS, 0);
      #endif

      (void)HEADProcess(MEDIC_f_GetCycleTime());

      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-End event for Hypothesis Evaluation and Decision runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_HEAD_PROCESS, 0);
      #endif
      #endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */

      #if defined(MEDIC_SIMU) && (MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK)
      MEDIC_v_CheckProvideHeaders(p_MedicRequirePorts, p_MedicProvidePorts); 
      #endif

      #if (MEDIC_CFG_MEASUREMENT)
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-Start event for Process Measfreeze runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_PROCESSFREEZE, 0);
      #endif
      #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
      MEDIC_v_SetCompState (MEDIC_p_GetVehCompState(), MEDIC_p_ModFrameData()->eMEDICOpMode, AlgoErrorBuffer);
      #endif

      /* Computation chain ran through. MEDIC is initialized or running. */
      MEDIC_p_ModFrameData()->bIsInitialized = b_TRUE;

      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-End event for Process Measfreeze runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_PROCESSFREEZE, 0);
      #endif
      #endif /* MEDIC_CFG_MEASUREMENT */
    }
    else  /************************* end of non-error path, beginning of error path *************************/
    {
      /* MEDIC_MOD_SHUTDOWN => fill invalidate the available provide ports and fill whole sigHeader */

      /* Init MEDIC Algo */
      MEDIC_v_AlgoInit();

      #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
      /* ERROR path! Need to check existence of pointers */
      if (MEDIC_p_GetVehCompState() != NULL)
      {
        if ( (p_MedicRequirePorts != NULL) && (p_MedicRequirePorts->pVehCtrlData != NULL) )
        {
          MEDIC_v_SetCompState (MEDIC_p_GetVehCompState(), MEDIC_p_GetFrameData()->eMEDICOpMode, AlgoErrorBuffer);
        }
        else
        {
          MEDIC_v_SetCompState (MEDIC_p_GetVehCompState(), MEDIC_MOD_RUNNING, AlgoErrorBuffer);
        }
      }
      #endif

      /* make sure in error case init of sub components is performed next cylcle */
      MEDIC_p_ModFrameData()->bIsInitialized = b_FALSE;
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      if (MEDIC_p_GetServiceFuncts() != NULL)
      {
        /* Sends RTA-End event for data preparation runtime in errorcase*/
        MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_PROCESS, 0);
      }
      #endif
    } /*********************** end of error path, beginning common *******************************/

    MEDIC_v_FillProPortHeaders(MEDIC_p_ModPortHandlerList());  //added

    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    if (MEDIC_p_GetServiceFuncts() != NULL)
    {
      /* Sends RTA-Start event for Frame Measfreeze runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_FRAMEFREEZE, 0);
    }
    #endif

    /* Process meas freezes */
    MEDIC_v_FreezePorts(MEDIC_p_GetPortHandlerList());

     /* Freeze all working data */
    MEDIC_v_FreezeWorkingData(MEDIC_p_GetWorkingData());

    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    if (MEDIC_p_GetServiceFuncts() != NULL)
    {
      /* Sends RTA-End event for Frame Measfreeze runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_FRAMEFREEZE, 0);
      /* Sends RTA-End event for whole procedure runtime */
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_PROCESS, 0);
    }
    #endif
  }
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_e_AssignStaticMemoryToAccessData                                                        */ /*!

  @brief                Assign pointers to MEDIC process memory

  @description          Checks for valid pointers to the process memory. Afterwards sets the pointers to define four storage
                        areas inside the memory section.
                        Returns GDB_ERROR_POINTER_NULL in case a null pointer is detected.
                        @startuml
                        start
                          :Check for static memory sizes;
                          :Check validity of memory pointers;
                        stop
                        @enduml
 
  @return               eGDBError_t : Error type to communicate if pointer to proc mem is valid

  @param[in]            p_MedicProcMem : Container of all memory types

  @glob_in              None
  @glob_out             @ref MEDIC_p_ModAccessData

  @c_switch_part        @ref MEDIC_SIMU\n
                        @ref USE_MEDICWRAPPER_INTRAMEAS\n
                        @ref USE_MEDICWRAPPER_INTRA\n
                        @ref USE_MEDICWRAPPER_INTERMEAS\n
  @c_switch_full        @ref MEDIC_CFG_FRAME\n

  @pre                  None
  @post                 If this function did not successfully finish there is no global memory available. \n
                        MEDIC cannot run.

  @InOutCorrelation     see description

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1101-0007e0f8}

  @author               Nagaraja Veerashettappa | Nagaraja.Verrashettappa@continental-corporation.com 
*************************************************************************************************************************/
static eGDBError_t MEDIC_e_AssignStaticMemoryToAccessData(MEDIC_ProcMem_t const * const p_MedicProcMem, MEDIC_DataWrapperStack_t * const pMEDICStackData)
{
  eGDBError_t eRetError = GDB_ERROR_NONE;
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  /* PRQA S 3205,1271 USAGE */
  /* check of static memory sizes during compilation, no runtime effects */
  #if (USE_MEDICWRAPPER_INTER)
  /* Compile error occurs if size is to small */
  MEDIC_STATIC_ASSERT(sizeof(MEDIC_DataWrapperInter_t)     <= GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE);
  #endif /* end of MEDIC WRAPPER INTER check */
  #if (USE_MEDICWRAPPER_INTERMEAS)
  /* Compile error occurs if size is to small */
  MEDIC_STATIC_ASSERT(sizeof(MEDIC_DataWrapperInterMeas_t) <= GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE_MEAS);
  #endif /* end of MEDIC WRAPPER INTER MEAS check */
  #if (USE_MEDICWRAPPER_INTRAMEAS)
  /* Compile error occurs if size is to small */
  MEDIC_STATIC_ASSERT(sizeof(MEDIC_DataWrapperIntraMeas_t) <= GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS);
  #endif /* end of MEDIC WRAPPER INTRA MEAS check */
  #else
  /* check of static memory sizes during compilation, no runtime effects */
  #if (USE_MEDICWRAPPER_INTER)
  /* PRQA S 3205,1271,3493 USAGE */
  /* Compile error occurs if size is to small (For ANSI C this ASSERT only works in Visual Studio 2010 and smaller) */
  MEDIC_STATIC_ASSERT(sizeof(MEDIC_DataWrapperInter_t)     <= GA_MEDIC_ASILB_SLOW_INTER_SIZE_MEM_DATA);
  #endif /* end of MEDIC WRAPPER INTER check */
  #if (USE_MEDICWRAPPER_INTERMEAS)
  /* Compile error occurs if size is to small (For ANSI C this ASSERT only works in Visual Studio 2010 and smaller) */
  MEDIC_STATIC_ASSERT(sizeof(MEDIC_DataWrapperInterMeas_t) <= GA_MEDIC_ASILB_SLOW_INTER_MEAS_SIZE_MEM_DATA); /*PRQA S 3494*/ /* date: 2020-10-21, Reviewer: Siri Prakash, Reason: Implementation is intended */
  #endif /* end of MEDIC WRAPPER INTER MEAS check */
  #if (USE_MEDICWRAPPER_INTRAMEAS)
  /* Compile error occurs if size is to small (For ANSI C this ASSERT only works in Visual Studio 2010 and smaller) */
  MEDIC_STATIC_ASSERT(sizeof(MEDIC_DataWrapperIntraMeas_t) <= GA_MEDIC_ASILB_SLOW_INTRA_MEAS_SIZE_MEM_DATA);
  #endif /* end of MEDIC WRAPPER INTRA MEAS check */
  #endif
 
  /* PRQA L:USAGE */

  /*PRQA S 3441 GETTER*//* 2018-11-15, reviewer: Oliver Brand, get function without sideffects*/
  /*PRQA S 0315 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
  (void)MEDIC_MEMSET(MEDIC_p_ModAccessData(), 0, sizeof(MEDICAccessData_t));
  /*PRQA L:GETTER*/

  /* Check validity of memory pointers */
  if (    (p_MedicProcMem                     != NULL)
       #if (USE_MEDICWRAPPER_INTER)
       && (p_MedicProcMem->pMemInterCycle     != NULL)
       #endif
       #if (USE_MEDICWRAPPER_INTERMEAS)
       && (p_MedicProcMem->pMemInterCycleMeas != NULL)
       #endif
       #if (USE_MEDICWRAPPER_INTRAMEAS)
       && (p_MedicProcMem->pMemIntraCycleMeas != NULL)
       #endif
       && (pMEDICStackData                    != NULL)
     )
  {
    /* pointer conversion */
    /* PRQA S 0314 17*//* date: 2019-05-22, reviewer:C. Schnurr, Internal Data types used for compatibility over different architectures */
    #if (USE_MEDICWRAPPER_INTER)
    MEDIC_p_ModWorkingData()->pInterCycle     = (MEDIC_DataWrapperInter_t     *)((void *)(p_MedicProcMem->pMemInterCycle)    );
    #endif
    #if (USE_MEDICWRAPPER_INTERMEAS)
    MEDIC_p_ModWorkingData()->pInterCycleMeas = (MEDIC_DataWrapperInterMeas_t *)((void *)(p_MedicProcMem->pMemInterCycleMeas));
    #endif
    #if (USE_MEDICWRAPPER_INTRAMEAS)
    MEDIC_p_ModWorkingData()->pIntraCycleMeas = (MEDIC_DataWrapperIntraMeas_t *)((void *)(p_MedicProcMem->pMemIntraCycleMeas));
    #endif
    MEDIC_p_ModWorkingData()->pStackData      = pMEDICStackData;
  }
  else
  {
    eRetError = GDB_ERROR_POINTER_NULL;
  }

  return eRetError;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_AssignAccessPointers                                                                  */ /*!
  @brief                Take the input pointers and copy them to a global available access data structure.
  @description          assigns the request and provide ports to the input and output respectively.
                        @startuml
                        start
                          :Assign request ports to input;
                          :Assign provide ports to output;
                          If(service functions enabled?) then (yes)
                          :Fetch and assign \nservice function pointer\nto access data;
                          Endif
                        stop
                        @enduml
  @return               void
  @param[in]            p_MEDICRequirePorts : Request port
  @param[in]            p_MEDICProvidePorts : Provide  port
  @param[in]            p_ServiceFuncts : Request port
  @glob_in              None
  @glob_out             @ref MEDIC_p_ModAccessData 
  @c_switch_part        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        @ref MEDIC_CFG_FRAME
  @pre                  None 
  @post                 None 
  @InOutCorrelation     see description
  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-503e822e5ec3651e-O-1120-0007e0f8}
  @author               Nagaraja Veerashettappa | Nagaraja.Verrashettappa@continental-corporation.com 
*************************************************************************************************************************/
/*PRQA S 3673 6*/ /* date: 2018-07-25, reviewer: Nagaraja Veerashettappa, reason: The pointer assigned here needs write access. */
static void MEDIC_v_AssignAccessPointers(
                                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
                                          reqMEDICPtrList_t   const * const p_MEDICRequirePorts,
                                          proMEDICPtrList_t         * const p_MEDICProvidePorts
                                          #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                                          ,AS_t_ServiceFuncts const * const p_ServiceFuncts
                                          #endif
                                          #else
                                          MEDIC01_ReqPorts    const * const p_MEDICRequirePorts,
                                          MEDIC01_ProPorts    const * const p_MEDICProvidePorts
                                          #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                                          ,MEDIC_Services const * const p_ServiceFuncts
                                          #endif
                                          #endif
                                        )
{
  if (p_MEDICRequirePorts != NULL)
  {
    /* Assign request ports to input */
    MEDICAccessData.Input.ReqPorts      = *p_MEDICRequirePorts;
  }
  if (p_MEDICProvidePorts != NULL)
  {
    /* Assign provide ports to output */
    MEDICAccessData.Output.ProPorts     = *p_MEDICProvidePorts;
  }
  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
  if (p_ServiceFuncts != NULL)
  {
    MEDICAccessData.Input.ServiceFuncts = *p_ServiceFuncts;
  }
  #endif
}

#endif /*!FCT_CFG_EMERGENCY_BRAKE_ASSIST*/


