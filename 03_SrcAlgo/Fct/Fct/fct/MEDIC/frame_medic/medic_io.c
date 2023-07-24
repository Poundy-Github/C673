/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control) 

PACKAGENAME:               medic_io.c

DESCRIPTION:               Function Processing I/O-Wrapper Main Module for MEDIC component

AUTHOR:                    Sadhanashree Srinivasa

CREATION DATE:             $Date: 2020/10/26 11:08:10CET $

VERSION:                   $Revision: 1.63 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* ifndef __PDO__ */

/*PRQA S 0314 EOF*//*(Reviewer Sadhanashree Srinivasa : generic implementation for all Ports)*/
/*PRQA S 3332 EOF*//*(Reviewer Nalina M : Supressing because it is configured for perticulate configuration)*/
/*PRQA S 3332 EOF #date: 2020-06-02, reviewer: Nalina M, reason: Supressing because it is configured for perticulate configuration*/

/*****************************************************************************
  MACROS
*****************************************************************************/
#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)
#ifdef PRQA_SIZE_T
#pragma PRQA_NO_SIDE_EFFECTS MEDIC_b_SetupPorts /* Function marked as free from side effects*/
#endif
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@brief          The In-/Output module contains functions that handle In- and Outputs.
@description    The module provides the following functionalities:
                - Check the MEDIC Ports and set up the necessary globals to enable MEDIC to run properly: @ref MEDIC_v_ProcessPorts
                - Fill the Signal headers of the MEDIC provide ports after the subcomponents have been called: @ref MEDIC_v_FillProPortHeaders
                .
                If a new port shall be added, the following steps have to be executed:
                - Require Port:
                  - Add port to @ref reqMEDICPrtList_t
                  - Add port to @ref MEDICSyncRef_t
                  - Add the ports switch to the macro @ref MEDIC_NOF_REQ_PORTS
                  - Add the port to the function @ref MEDIC_v_SetupReqPortHandlers, where its PortHandler has to be filled.
                - Provide Port:
                  - Add port to @ref provMEDICPrtList_t
                  - Add the ports switch to the macro @ref MEDIC_NOF_PRO_PORTS
                  - Add the port to the function @ref MEDIC_v_SetupProPortHandlers, where its PortHandler has to be filled:
                    - Decide which subcomponents the ProPorts signal state shall depend on.
                    - Decide which ReqPort shall fill the ProPorts signal header.
                    - Decide if the port shall be frozen (assign MeasFreezeAdress) or not (assign 0).

*/
/*****************************************************************************
  MACROS
*****************************************************************************/
#if (MEDIC_CFG_ENABLE_DEM_OUTPUT)
/* Time stamp error bitmask*/
#define MEDIC_TIMESTAMP_ERROR                     7u
/* Bit mask for req port error*/
#define MEDIC_REQPORT_ERROR                       8u
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*PRQA S 3332 EOF #date: 2020-06-02, reviewer: Nalina M, reason: Supressing because it is configured for perticulate configuration*/
#if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
static AlgoDataTimeStamp_t uiPreviousTimestamp;
#endif
#if (MEDIC_CFG_ENABLE_DEM_OUTPUT)
/* To count the number of cycles for which req port data has not been changed*/
static uint8 ReqPort_DEMctr[MEDIC_NOF_REQ_PORTS];
/* Store the previous timestamp of req port data*/
static AlgoDataTimeStamp_t     ReqPort_PrevTimestamp[MEDIC_NOF_REQ_PORTS];
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK)
static boolean MEDIC_b_CheckPortUpdate(AlgoDataTimeStamp_t const * const pInputPortMeasCycle,
                                       sMeasCycleMonitor         * const pLastMeasCycle,
                                       float32                     const fTargetCycleTime,
                                       uint8                             iAcceptableDrops);
#endif /* MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK */

static void MEDIC_v_SetSignalHeader(SignalHeader_t       * const pDestSignalHeader,
                                    SignalHeader_t const * const pSourceSignalHeader, 
                                    AlgoSignalState_t      const eSignalState);

static void MEDIC_v_SetSignalHeaderError(SignalHeader_t  * const pSignalHeader);

static void MEDIC_v_SetupProPortHandler(void                       * const        pProPort,
                                        void                         const *const pReqPort,
                                        MEDICSubCompIndices_t        const        uInfluencingSubcomponents,
                                        AlgoInterfaceVersionNumber_t const        uVersionNumber,
                                        uint32                       const        uMeasFreezeAddress,
                                        uint32                       const        uFreezeSize,
                                        MEDICPortHandlerList_t     * const        pPortHandlerList);

static void MEDIC_v_SetupReqPortHandlers(
                                        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
                                        reqMEDICPtrList_t       const * const pRequirePorts,
                                        #else
                                        MEDIC01_ReqPorts        const * const pRequirePorts,
                                        #endif
                                        MEDICPortHandlerList_t * const         pPortHandlerList);
#if (MEDIC_CFG_ENABLE_DEM_OUTPUT)
static void MEDIC_v_CheckReqPort_DEM(MEDICPortHandlerList_t   * const pPortHandlerList);

static void MEDIC_v_SetDEMOutput(uint8                  const ui_ReqPortnum);
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
static void MEDIC_v_SetupProPortHandlers(proMEDICPtrList_t      const * const pProvidePorts,
                                         reqMEDICPtrList_t      const * const pRequirePorts,
                                         MEDICPortHandlerList_t       * const pPortHandlerList);

static void MEDIC_v_SetupReqPortHandler(void                     const *const pReqPort,
                                        MEDICSubCompIndices_t    const        uInfluencedSubcomponents,
                                        boolean                  const        bSignalContainsGenericPortData,
                                        SignalHeader_t         * const        pSyncRefSignalHeader,
                                        MEDICPortHandlerList_t * const        pPortHandlerList);

static void MEDIC_v_PortSpecificHandling(reqMEDICPtrList_t const * const pRequirePorts);
#else
static void MEDIC_v_PortSpecificHandling(MEDIC01_ReqPorts const * const pRequirePorts);
#endif

static boolean MEDIC_b_SetupPorts(MEDICPortHandlerList_t * const pPortHandlerList);
static void    MEDIC_v_InitPortHandlerList(MEDICPortHandlerList_t * const pPortHandlerList);

void MEDIC_v_ProcessPorts(/*PRQA S 3447*/ /* date: 2020-07-06, Reviewer Nalina M, Reason:Function decl is in a .c file and cant be moved to .h file*/
                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10) 
                          reqMEDICPtrList_t const  * const pRequirePorts,
                          proMEDICPtrList_t        * const pProvidePorts,
                          #else
                          MEDIC01_ReqPorts   const * const pRequirePorts,
                          MEDIC01_ProPorts   const * const pProvidePorts,
                          #endif
                          MEDICPortHandlerList_t   * const pPortHandlerList
                          #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
                          , AS_t_ServiceFuncts const * const pServiceFuncts
                          #else
                          , MEDIC_Services     const * const pServiceFuncts
                          #endif
                          #endif
                          #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
                          , GenAlgoQualifiers_t       * const pErrorBuffer
                          #endif
                          );

#if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
static boolean MEDIC_b_CheckServiceFunctions(AS_t_ServiceFuncts const * const pServiceFuncts);
#else
static boolean MEDIC_b_CheckServiceFunctions(MEDIC_Services     const * const pServiceFuncts);
#endif
#endif /* end of service pointer func use check */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

#if (MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK)
/*************************************************************************************************************************
  Functionname:         MEDIC_b_CheckPortUpdate                                                                  */ /*!

  @brief                Checks if a port has been updated.

  @description          Compares the current port timestamp to the last timestamp and evaluates the result by raising 
                        an error flag in case of a skipped cycle or a missing port update.
                        @startuml MEDIC_b_CheckPortUpdate_activity.png
                        start
                          :Calculate maximum delta time;
                          note left
                            Expected time between current and 
                            previous timestamp
                            >see formula "Acceptable drop time"
                          end note
                          :Calculate delta time to last timestamp;
                          note left: Also consider overflow
                          if(Timestamp is equal to the last timestamp (=>Port was not updated)?) then (Yes)
                            if(Number of cycle since last update is below tolerance?) then (Yes)
                              :1}
                              :No update expected,
                              Increase last update counter;
                            else (No)
                              :2}
                              :Update was expected, 
                              Raise error flag;
                            endif
                          else (No)
                            if(Delta time is above expected maximum delta time?) then (Yes)
                              :3}
                              :Cycle was skipped, 
                              Raise error flag;
                            else (No)
                              :4}
                              :New cycle was received in time,
                              Reset last update counter;
                            endif
                            :Set current cycle time as last cycle time;
                          endif
                        stop
                        @enduml

  @return               boolean : True if error occurred (cycle was skipped or interface was not updated).

  @param[in]            pInputPortMeasCycle : Currently received timestamp. @phys_unit [s]
  @param[in,out]        pLastMeasCycle      : Contains last seen timestamp and the dropped frame counter.
                                              It is updated with the currently received timestamp.
  @param[in]            fTargetCycleTime    : Expected reception cycle time. @phys_unit [s] @range ]0,+...[
  @param[in]            iAcceptableDrops    : Number of acceptable frame drops. @range [0,+...[
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST \n
                        @ref MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     \f$N = \f$ Number of acceptable Drops
                        - **Formula Acceptable drop time:** \n
                          \f$t_{Accept} =  (N + 1.5) \cdot t_{Cycle} \f$

  @testmethod           @Generic_Testmethods

  @traceability        Design Decision

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static boolean MEDIC_b_CheckPortUpdate(AlgoDataTimeStamp_t const * const pInputPortMeasCycle,
                                       sMeasCycleMonitor         * const pLastMeasCycle,
                                       float32             const         fTargetCycleTime,
                                       uint8                             iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /* PRQA S 4119 5*//*date: 2015-03-25 Reviewer: C. Obst: intended behavior to cast float to uInt. fractional part is neglectible. */
  /* conversion second to microsecond */
  const AlgoDataTimeStamp_t uiReceiveCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * MEDIC_TIMESTAMP_TO_MICROSECONDS);
  /* accepted drops + current Cycle + 0.5 safety margin */
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiReceiveCycleTimeUs ); 
  const AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_SEN_CYCLE_TIME * MEDIC_TIMESTAMP_TO_MICROSECONDS);

  boolean bError = FALSE;

  /* Calculating Time since last input */
  if ( *pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp )
  {
    /* OVERFLOW */
    uiDeltaTimeUs = ( (0u)^(0u)) - (pLastMeasCycle->uiTimeStamp - *pInputPortMeasCycle);
  }
  else 
  {
    /* NO Overflow */
    uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
  }

  if ( uiDeltaTimeUs == 0u)
  {
    /* NO update */
    if ( ((pLastMeasCycle->uiLastUpdateCounter + 1) * uiTargetCycleTimeCallUs)  < uiMaxAcceptableDropTimeUs)
    {
      /* no update needed (max time including drops not reached) */
      pLastMeasCycle->uiLastUpdateCounter += 1u;   /* increment update counter */
    }
    else
    {
      /* update expected */
      bError = TRUE;        /* raise error */
    }
  }
  else
  {
    /* update */
    if ( uiDeltaTimeUs > uiMaxAcceptableDropTimeUs )
    {
      /* skipped cycle */
      bError = TRUE;        /* raise error */
    }
    else
    {
      /* new cycle received in time */
      pLastMeasCycle->uiLastUpdateCounter = 0u;    /* reset update counter */
    }
    pLastMeasCycle->uiTimeStamp = *pInputPortMeasCycle;
  }
  return bError;
}
#endif /* MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK */

/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetSignalHeader                                                                      */ /*!

  @brief                Copies information from one signal header to another. 

  @description          Copies Time Stamp and Measurement counter from pSourceSignalHeader to pDestSignalHeader. 
                        Sets the cycle counter of pDestSignalHeader to the Cycle counter of @ref MEDIC_p_GetFrameData and its \n
                        Signal state to a given signal state.

  @return               void

  @param[in,out]        pDestSignalHeader   : The signal header to be filled.
  @param[in]            pSourceSignalHeader : The source signal header.
  @param[in]            eSignalState        : The signal state that shall be written to the DestSignal header.

  @glob_in              @ref MEDIC_p_GetFrameData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static void MEDIC_v_SetSignalHeader(SignalHeader_t          * const pDestSignalHeader, 
                                    SignalHeader_t    const * const pSourceSignalHeader, 
                                    AlgoSignalState_t         const eSignalState)
{
  pDestSignalHeader->uiTimeStamp          = pSourceSignalHeader->uiTimeStamp;
  pDestSignalHeader->uiMeasurementCounter = pSourceSignalHeader->uiMeasurementCounter;
  pDestSignalHeader->uiCycleCounter       = MEDIC_p_GetFrameData()->uiCycleCounter;
  pDestSignalHeader->eSigStatus           = eSignalState;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetSignalHeaderError                                                                 */ /*!

  @brief                Resets the Signal Header of a signal for which an error was detected. 
                        The current cycle counter is kept.

  @description          Init the @ref SignalHeader_t structure with default values for MEDIC. These default 
                        values are the cycle counter of MEDIC and the signal state @ref AL_SIG_STATE_INVALID. \n
                        Timestamp and measurement counter are set to zero.

  @return               void

  @param[in,out]        pSignalHeader : Header of a signal for which an error was detected.

  @glob_in              @ref MEDIC_p_GetFrameData : uiCycleCounter, used to set signal header cycle counter
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     see description 

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static void MEDIC_v_SetSignalHeaderError(SignalHeader_t * const pSignalHeader)
{
  pSignalHeader->uiTimeStamp          = 0u;
  pSignalHeader->uiMeasurementCounter = 0u;
  pSignalHeader->uiCycleCounter       = MEDIC_p_GetFrameData()->uiCycleCounter;
  pSignalHeader->eSigStatus           = AL_SIG_STATE_INVALID;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetupProPortHandler                                                                   */ /*!

  @brief                Function to set up a handler for a Provide Port.

  @description          This function fills a handler to enable a generic handling of all provide ports.
                        If the Require Port or the Provide port is zero, the corresponding pointers are not filled. \n
                        As they are initialized in each cycle (see @ref MEDIC_v_InitPortHandlerList) they are NULL 
                        pointers in this case.

  @return               void

  @param[in,out]        pProPort : Void pointer to the current provide port
  @param[in]            pReqPort : Require port which shall be used to fill the signal header of the provide port.
  @param[in]            uInfluencingSubcomponents : Bitfield of all subcomponents which are influencing the provide port. 
                                                    (Used to set the signal state of the provide port signal header). @range [MEDIC_SUB_COMP_NONE,MEDIC_SUB_COMP_ALL]
  @param[in]            uVersionNumber : Version number of the provide port.
  @param[in]            uMeasFreezeAddress : Meas freeze address of the provide port (if 0, no meas freeze is executed).
  @param[in]            uFreezeSize : Size of the provide port (required for meas freeze).
  @param[in,out]        pPortHandlerList : Pointer to the Port Handler List which shall be filled.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1122-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static void MEDIC_v_SetupProPortHandler(void                               *const pProPort,
                                        void                         const *const pReqPort,
                                        MEDICSubCompIndices_t        const        uInfluencingSubcomponents,
                                        AlgoInterfaceVersionNumber_t const        uVersionNumber,
                                        uint32                       const        uMeasFreezeAddress,
                                        uint32                       const        uFreezeSize,
                                        MEDICPortHandlerList_t     * const        pPortHandlerList)
{
  MEDICProPortHandler_t  * pCurrProHandler  = &(pPortHandlerList->ProPortHandler[pPortHandlerList->uNofProPorts]);
  
  pCurrProHandler->uProNewVersionNumber      = uVersionNumber;
  pCurrProHandler->uMeasFreezeAddress        = uMeasFreezeAddress;
  pCurrProHandler->uInfluencingSubComponents = uInfluencingSubcomponents;
  pCurrProHandler->uSize                     = uFreezeSize;
  pCurrProHandler->pProPort                  = pProPort;
  
  /* Get the Version Number and Signal Header of the ports. Assure that each port which is passed here has the generic Port data!! */
  pCurrProHandler->pGenericProPortData       = (MEDICGenericPortData_t       *const)pProPort;
  pCurrProHandler->pGenericReqPortData       = (MEDICGenericPortData_t const *const)pReqPort;


  pPortHandlerList->uNofProPorts++;
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetupProPortHandlers                                                                  */ /*!

  @brief                Sets up the port handlers for all provide ports.

  @description          Sets up the handlers of all provide ports by executing the function @ref MEDIC_v_SetupProPortHandler
                        to add the following information to the handler:
                        - Source signal header for the provide port signal header.
                        - Component states that influence the provide port signal header state.
                        - Interface version of the provide port.
                        - Address for a possible meas freeze.
                        - Size of the port for the meas freeze.
                        .
                        More information regarding the Port Handler concept can be found here: @ref MEDIC_v_ProcessPorts.
                        @startuml MEDIC_v_SetupProPortHandlers_activity.png
                          start
                          partition "Execute for each provide port" {
                              #Orange:Fill Provide port handler:
                              <b>MEDIC_v_SetupProPortHandler</b> >
                            }
                          stop
                        @enduml
  
  @return               void

  @param[in,out]        pProvidePorts :     Pointer to a structure containing all provide port pointers.
  @param[in]            pRequirePorts :     Pointer to a structure containing all require port pointers.
  @param[in,out]        pPortHandlerList :  Pointer to a list with all port handlers.

  @glob_in              None
  @glob_out             None

  @c_switch_part        if MEDIC_ARCHITECTURE_VERSION < 0x10         \n
                        @ref MEDIC_CFG_INCLUDE_UNUSED_INTF           \n
                        @ref MEDIC_CFG_USE_ALGOCOMPSTATE             \n
                        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   \n
                        @ref MEDIC_CFG_ERROR_OUTPUT_VEH              \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
                        if MEDIC_ARCHITECTURE_VERSION >= 0x10        \n
                        @ref CFG_MEDIC_OUT_HBA                       \n
                        @ref CFG_MEDIC_OUT_PREFILL                   \n
                        @ref CFG_MEDIC_OUT_PREBRAKE                  \n
                        @ref CFG_MEDIC_OUT_WARNINGS                  \n
                        @ref CFG_MEDIC_OUT_PRECRASH                  \n
                        @ref CFG_MEDIC_OUT_DRIVEROFFPREV             \n
                        @ref CFG_MEDIC_OUT_ESA                       \n
                        @ref CFG_MEDIC_OUT_HYPREACTIONS              \n
                        @ref CFG_MEDIC_OUT_FCTQUALIFIER              \n
                        @ref CFG_MEDIC_OUT_FCTDATA                   \n
                        @ref CFG_MEDIC_OUT_TOYOTA                    \n
                        @ref CFG_MEDIC_OUT_DIMOUTPUT                 \n
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST        \n
                        @ref MEDIC_ARCHITECTURE_VERSION

  @pre                  Assure that pRequirePorts != NULL
                        Assure that pProvidePorts != NULL
  @post                 Pro port information in the PortHandler is filled

  @InOutCorrelation     Output the MEDIC ProPorthandlers from the Input pRequirePorts,pProvidePorts and pPortHandlerList

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1122-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
static void MEDIC_v_SetupProPortHandlers(     proMEDICPtrList_t const * const pProvidePorts,
                                              reqMEDICPtrList_t const * const pRequirePorts,
                                         MEDICPortHandlerList_t       * const pPortHandlerList)
{
/*PRQA S 0314 25*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Cast to void is intended as to allow generic port handling*/
  /*     | Provide port                                                            | Require Port (for Sig Header)                   | Relevant Components (for SigState)                               | Version Number                        | Measfreeze address (0:No freeze)|     Size (for Meas Freeze)                   | PortHandlerList |*/
 
  #if((MEDIC_CFG_USE_ALGOCOMPSTATE)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->pVehCompState,           (void const *const) pRequirePorts->pEgoDynRaw,    MEDIC_SUB_COMP_ALL,                                               COMP_STATE_INTFVER,                    FCT_MEAS_ID_VEH_EBA_COMP_STATE,         sizeof(AlgoCompState_t ),                pPortHandlerList);
  #endif
 
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->pDIMOutputCustom,        (void const *const) pRequirePorts->pEgoDynRaw,    MEDIC_SUB_COMP_DIM + MEDIC_SUB_COMP_HEAD,                         FCT_DIM_OUTPUT_CUSTOM_INTFVER,         FCT_MEAS_ID_DIM_OUTPUT_CUSTOM,         sizeof(DIMOutputCustom_t),                pPortHandlerList);
  #endif

  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->pHEADOutputGeneric,      (void const *const) pRequirePorts->pEgoDynRaw,    MEDIC_SUB_COMP_HEAD,                                              FCT_HEAD_OUTPUT_GENERIC_INTFVER,       FCT_MEAS_ID_HEAD_OUTPUT_GENERIC,       sizeof(HEADOutputGeneric_t),              pPortHandlerList);
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->pHEADOutputCustom,       (void const *const) pRequirePorts->pEgoDynRaw,    MEDIC_SUB_COMP_HEAD,                                              FCT_HEAD_OUTPUT_CUSTOM_INTFVER,        FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM,        sizeof(HEADOutputCustom_t),               pPortHandlerList);
  #endif

  #if ((MEDIC_CFG_ERROR_OUTPUT_VEH)|| (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->pErrorOut,               (void const *const) pRequirePorts->pEgoDynRaw,    MEDIC_SUB_COMP_ALL,                                               FCT_SEN_ERROR_OUT_INTFVER,             FCT_MEAS_ID_VEH_ERROR_OUT_VADDR,       sizeof(FCTVehErrorOut_t),                 pPortHandlerList);  
  #endif

  #if ((!MEDIC_CFG_INCLUDE_UNUSED_INTF) && (!MEDIC_CFG_USE_ALGOCOMPSTATE) && (!MEDIC_CFG_ERROR_OUTPUT_VEH) && (!MEDIC_CFG_DRIVER_INTENTION_MONITORING) && (!MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION))
  #if !defined(__NO_ARS_COMPILER_MESSAGES)
  #endif
  unsigned int dummy;
  #endif
}
#else
static void MEDIC_v_SetupProPortHandlers(MEDIC01_ProPorts       const * const pProvidePorts,
                                         MEDIC01_ReqPorts       const * const pRequirePorts,
                                         MEDICPortHandlerList_t       * const pPortHandlerList)
{
  /*                         | Provide port                                        | Require Port (for Sig Header)                   | Relevant Components (for SigState)                               | Version Number                        | Measfreeze address (0:No freeze)| Size (for Meas Freeze)              | PortHandlerList |*/
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->algoCompState            ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , COMP_STATE_INTFVER                    , 0u                               , sizeof(AlgoCompState_t)             , pPortHandlerList);
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->brakeCascades            ,(void const *const) pRequirePorts->controlData   , MEDIC_SUB_COMP_ALL                                               , MEDIC_BRAKE_CASCADES_INTVER           , 0u                               , sizeof(MEDIC_t_BrakeCascades)       , pPortHandlerList);  // Use control data as header source to avoid circular degradation with ACDC
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->trajPlanerCtrlLimits     ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_TARGET_REQUEST_T_INTVER         , 0u                               , sizeof(MEDIC_TargetRequest_t)       , pPortHandlerList);
  #if (CFG_MEDIC_OUT_HBA == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->hbaHydrBrkAss            ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_HBA_OUT_INTFVER                 , 0u                               , sizeof(MEDIC_t_HBA)                 , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_PREFILL == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->prefill                  ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_PREFILL_OUT_INTFVER             , 0u                               , sizeof(MEDIC_t_Prefill)             , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_PREBRAKE == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->preBrake                 ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_PREBRAKE_OUT_INTFVER            , 0u                               , sizeof(MEDIC_t_PreBrake)            , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_WARNINGS == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->warnings                 ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_WARNINGS_OUT_INTFVER            , 0u                               , sizeof(MEDIC_t_Warnings)            , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_PRECRASH == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->preCrash                 ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_PRECRASH_OUT_INTFVER            , 0u                               , sizeof(MEDIC_t_PreCrash)            , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_DRIVEROFFPREV == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->driveOffPrev             ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_DRIVEOFF_OUT_INTFVER            , 0u                               , sizeof(MEDIC_t_DriveOffPrev)        , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_ESA == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->steerAssist              ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_STEERASSIST_OUT_INTFVER         , 0u                               , sizeof(MEDIC_t_SteerAssist)         , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_HYPREACTIONS == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->hypReactions             ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_HYPREACTIONS_OUT_INTFVER        , 0u                               , sizeof(MEDIC_t_HypReactions_Interf) , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_FCTQUALIFIERS == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->fctQualifiers            ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_FCTQUALIFIERS_OUT_INTFVER       , 0u                               , sizeof(MEDIC_t_FCTQualifiers_Interf), pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_FCTDATA == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->fctData                  ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_FCTDATA_OUT_INTFVER             , 0u                               , sizeof(MEDIC_t_FCTData_Interf)      , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_TOYOTA == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->tmcOutput                ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_TMC_OUT_INTFVER                 , 0u                               , sizeof(MEDIC_t_TMCOutput_Interf)    , pPortHandlerList);
  #endif
  #if (CFG_MEDIC_OUT_DIMOUTPUT == 1)
  MEDIC_v_SetupProPortHandler((void *const)pProvidePorts->dimOutput                ,(void const *const) pRequirePorts->hypothesis    , MEDIC_SUB_COMP_ALL                                               , MEDIC_DIM_OUT_INTFVER                 , 0u                               , sizeof(MEDIC_t_DIMOutput_Interf)    , pPortHandlerList);
  #endif
}
#endif

/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetupReqPortHandler                                                                    */ /*!

  @brief                Fills a handler for a require port

  @description          Copies the given arguments to a port handler. Afterwards increases the number of req port handlers.

  @return               void

  @param[in]            pReqPort : Void pointer to the require port
  @param[in]            uInfluencedSubcomponents : Bitfield indicating which subcomponents are affected by the ReqPort
  @param[in]            bSignalContainsGenericPortData : Flag indicating if the require port corresponds to the MEDICGenericPortData_t.
  @param[in,out]        pSyncRefSignalHeader : Signal header of the sync ref structure that shall be filled by the signal header of the ReqPort.
  @param[in,out]        pPortHandlerList : Pointer to the port handler list.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see the description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1127-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static void MEDIC_v_SetupReqPortHandler(void                  const * const pReqPort,
                                       MEDICSubCompIndices_t  const         uInfluencedSubcomponents,
                                       boolean                const         bSignalContainsGenericPortData,
                                       SignalHeader_t               * const pSyncRefSignalHeader,
                                       MEDICPortHandlerList_t       * const pPortHandlerList)
{
  MEDICReqPortHandler_t  * pCurrReqHandler  = &(pPortHandlerList->ReqPortHandler[pPortHandlerList->uNofReqPorts]);
  if (bSignalContainsGenericPortData == b_TRUE)
  {
    pCurrReqHandler->pGenericReqPortData   = (MEDICGenericPortData_t const * const)pReqPort;
  }
  else
  {
    pCurrReqHandler->pGenericReqPortData   = NULL;
  }
  pCurrReqHandler->pReqSignalHeaderSyncRef = pSyncRefSignalHeader;
  pCurrReqHandler->pReqPort                = pReqPort;
  pCurrReqHandler->InfluencedSubComponents = uInfluencedSubcomponents;

  pPortHandlerList->uNofReqPorts++;
}



/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetupReqPortHandlers                                                                  */ /*!

  @brief                Sets up the port handlers for all require ports.

  @description          Sets up the handlers of all require ports by executing the function @ref MEDIC_v_SetupReqPortHandler
                        to add the following information to the handler:
                        - Pointer to the SyncRef structure that corresponds to the require port.
                        - Bitfield of all subcomponents that are influenced by the require port.
                        .
                        More information regarding the Port Handler concept can be found here: @ref MEDIC_v_ProcessPorts.
                        @startuml MEDIC_v_SetupReqPortHandlers_activity.png
                          start
                          partition "Execute for each require port" {
                            #Orange:Fill require port handler:
                            <b>MEDIC_v_SetupReqPortHandler</b> >
                          }
                          stop
                        @enduml

  @return               void

  @param[in]            pRequirePorts    : Pointer to a structure containing all require port pointers.
  @param[in,out]        pPortHandlerList : Pointer to a list with all port handlers.

  @glob_in              @ref MEDIC_SyncRef
  @glob_out             None

  @c_switch_part        if MEDIC_ARCHITECTURE_VERSION < 0x10         \n
                        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION  \n
                        @ref MEDIC_CFG_USE_BASECTRLDATA              \n
                        @ref MEDIC_CFG_INCLUDE_UNUSED_INTF           \n
                        @ref MEDIC_CFG_CPAR_PARAMS                   \n
                        @ref MEDIC_CFG_CUSTOMINPUT                   \n
                        @ref MEDIC_CFG_VEH_SIG_INPUT                 \n
                        @ref MEDIC_CFG_BSW_ALGO_PARAMS               \n
                        if MEDIC_ARCHITECTURE_VERSION >= 0x10        \n
                        @ref CFG_MEDIC_IN_TOYOTA
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST        \n
                        @ref MEDIC_ARCHITECTURE_VERSION

  @pre                  Assure that pRequirePorts != NULL
  @post                 Require port information filled in port handler 

  @remark               Make sure that the GenericPortData flag is only set for ports that have a 
                        Version Number and Signal header as their first structure elements!!

  @InOutCorrelation     Output the MEDIC ProPorthandlers from the Input pRequirePorts and pPortHandlerList

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1127-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
static void MEDIC_v_SetupReqPortHandlers (reqMEDICPtrList_t      const * const pRequirePorts,
                                          MEDICPortHandlerList_t       * const pPortHandlerList) 
{
  MEDICSyncRef_t * const pSyncRef = MEDIC_p_ModSyncRef();
/*PRQA S 0314 44*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Cast to void is intended as to allow generic port handling*/
  /*                       | Require Port                                              | Influenced Subcomponents                                         | GenericPortData?      | Pointer to SyncRef                    | Port handler List| */
 
  #if ((MEDIC_CFG_USE_BASECTRLDATA)||(MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pVehCtrlData           , MEDIC_SUB_COMP_ALL                                              , b_FALSE                 , &(pSyncRef->VehCtrlData           ), pPortHandlerList);  // 0
  #else
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pVehCtrlData           , MEDIC_SUB_COMP_ALL                                              , FALSE                 , &(pSyncRef->VehCtrlData           ), pPortHandlerList);  // 0
  #endif

  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pEgoDynRaw             , MEDIC_SUB_COMP_ALL                                              , b_TRUE                 , &(pSyncRef->EgoDynRaw             ), pPortHandlerList);  // 1
  
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pDIMInputGeneric       , MEDIC_SUB_COMP_HEAD + MEDIC_SUB_COMP_DIM                        , b_TRUE                  , &(pSyncRef->DIMInputGeneric       ), pPortHandlerList);  // 2
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pDIMInputCustom        , MEDIC_SUB_COMP_HEAD + MEDIC_SUB_COMP_DIM                        , b_FALSE                 , &(pSyncRef->DIMInputCustom        ), pPortHandlerList);  // 3
  #endif 

  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pFCTCDHypotheses       , MEDIC_SUB_COMP_ALL                                              , b_TRUE                 , &(pSyncRef->FCTCDHypotheses       ), pPortHandlerList);  // 4
  #endif

  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))                                           
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pHEADInputGeneric      , MEDIC_SUB_COMP_HEAD                                             , b_TRUE                  , &(pSyncRef->HEADInputGeneric      ), pPortHandlerList);  // 5
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pHEADInputCustom       , MEDIC_SUB_COMP_HEAD                                             , b_FALSE                 , &(pSyncRef->HEADInputCustom       ), pPortHandlerList);  // 6
  #endif

  #if ((MEDIC_CFG_CPAR_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pCPAR_FCT_Parameters   , MEDIC_SUB_COMP_HEAD                                             , b_FALSE                 , &(pSyncRef->CPAR_FCT_Parameters   ), pPortHandlerList);  // 7
  #endif

  #if ((MEDIC_CFG_VEH_SIG_INPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pVehSig                , MEDIC_SUB_COMP_ALL                                              , b_TRUE                  , &(pSyncRef->VehSig                ), pPortHandlerList);  // 8
  #endif

  #if ((MEDIC_CFG_BSW_ALGO_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pBswAlgoParameters     , MEDIC_SUB_COMP_ALL                                              , FALSE                 , &(pSyncRef->BswAlgoParameters     ), pPortHandlerList);  // 9
  #endif

  #if ((MEDIC_CFG_CUSTOMINPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->pFctVehCustInput        , MEDIC_SUB_COMP_ALL                                             , FALSE                 , &(pSyncRef->FctVehCustInput       ), pPortHandlerList);  // 10
  #endif
}
#else
static void MEDIC_v_SetupReqPortHandlers (MEDIC01_ReqPorts       const * const pRequirePorts,
                                          MEDICPortHandlerList_t       * const pPortHandlerList) 
{
  MEDICSyncRef_t * const pSyncRef = MEDIC_p_ModSyncRef();

  //                          |                  Require Port                          | Influenced Subcomponents                                         | GenericPortData?          | Pointer to SyncRef                   | Port handler List|
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->controlData            , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicControlData)         , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->egoMotion              , MEDIC_SUB_COMP_ALL                                               , b_FALSE                 , &(pSyncRef->MedicEgoMotion)           , pPortHandlerList);  // deactivate check until egomotion requestport contains a version number
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->vehSig                 , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->pMedicVehSig)             , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->hypothesis             , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicHypotheses)          , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->evasionTargets         , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicEvasionTargets)      , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->brakeTargets           , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicBrakeTargets)        , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->degradation            , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicDegradation)         , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->switches               , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicSwitches)            , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->vehicle                , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicVehicle)             , pPortHandlerList);  
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->driverMonitor          , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicDriverMonitor)       , pPortHandlerList);  
  #if (CFG_MEDIC_IN_TOYOTA == 1)
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->customInput_TMC        , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicCustomInput_TMC)     , pPortHandlerList);
  #endif
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->medicParameters        , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicParameters)          , pPortHandlerList);
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->ebaStateControl        , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicStateControl)        , pPortHandlerList);
  #if (MEDIC_CFG_USE_VDY)
  MEDIC_v_SetupReqPortHandler((void const*const) pRequirePorts->vDY_In                 , MEDIC_SUB_COMP_ALL                                               , b_TRUE                  , &(pSyncRef->MedicVDY_In)              , pPortHandlerList);
  #endif
  // activate when connected in SIL
  //#if (CFG_MEDIC_IN_BMW == 1)
  //MEDIC_v_SetupReqPortHandler((void const*const)pRequirePorts->customInput_BMW         , MEDIC_SUB_COMP_ALL                                               , b_FALSE                 , &(pSyncRef->MedicCustomInput_BMW)     , pPortHandlerList);
  //#endif 
  //MEDIC_v_SetupReqPortHandler((void const*const)pRequirePorts->loggingInfo             , MEDIC_SUB_COMP_ALL                                               , b_FALSE                 , &(pSyncRef->MedicloggingInfo)         , pPortHandlerList);
}
#endif

#if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
/*************************************************************************************************************************
  Functionname:         MEDIC_b_CheckServiceFunctions                                                                 */ /*!

  @brief                Checks the Service function structure for NULL pointers

  @description          Checks if the pointer to the service function structure is valid. If this is the case,
                        the Pointers inside of the structure are checked.
                        @startuml MEDIC_b_CheckServiceFunctions_activity.png
                        start
                          partition "Execute for each service function pointer" {
                            if(Pointer is NULL pointer?) then (Yes)
                              :1}
                              :Raise error flag;
                            else(No)
                              :2}
                            endif
                          }
                          :Return Error Flag;
                        stop
                        @enduml

  @return               boolean bError : True if error was detected.

  @param[in]            pServiceFuncts : Pointer to a structure containing all service function pointers.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_USE_DEM \n
                        @ref MEDIC_CFG_RTA_PROFILING \n
                        @ref MEDIC_CFG_USE_FREEZE_CYCLE_START \n
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST \n
                        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS \n

  @pre                  Assure that pServiceFuncts != NULL
  @post                 None

  @InOutCorrelation     Not applicable 

  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_915}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
static boolean MEDIC_b_CheckServiceFunctions(AS_t_ServiceFuncts const * const pServiceFuncts)
#else
static boolean MEDIC_b_CheckServiceFunctions(MEDIC_Services     const * const pServiceFuncts)
#endif
{
  boolean bError = b_FALSE;

  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  bError = bError || (boolean)(pServiceFuncts->pfMeasFreeze == NULL);/*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  #if (MEDIC_CFG_USE_FREEZE_CYCLE_START)
  bError = bError || (boolean)(pServiceFuncts->pfMeasStartFuncCycle == NULL);
  #endif
  #if (MEDIC_CFG_RTA_PROFILING)
  bError |= (boolean)(pServiceFuncts->pfRTAAlgoServiceAddEvent == NULL);
  #endif
  #if (MEDIC_CFG_USE_DEM)
  bError |= (boolean)(pServiceFuncts->pfDem_SetEventStatus == NULL);
  #endif

  MEDIC_ASSERT(bError == FALSE); /*PRQA S 3112,3119 *//* date: 2019-1-21, reviewer: Sadhanashree Srinivasa, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
  #else
  // Service pointer for meas freeze is not available to components in architecture >= 10
  _PARAM_UNUSED(pServiceFuncts); /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  #endif

  return bError;
}
#endif /* MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS */

/*************************************************************************************************************************
  Functionname:         MEDIC_b_SetupPorts                                                                            */ /*!

  @brief                Uses the port handler structure to set up require and provide ports as soon as related structures 
                        at the beginning of each cycle.

  @description          This function loops through the previously filled PortHandler structure. It checks and 
                        sets up all Ports. The following actions are executed for valid require ports:
                        - Copy port signal header to the SyncRef structure for simulation purposes.
                        - Apply the signal state to the influenced subcomponents
                        - Check if port has been updated within the required time
                        .
                        Most of the provide port handling has to be done after the call of the subcomponents 
                        (see @ref MEDIC_v_FillProPortHeaders). Only one action has to executed before:
                        - Set the content of all provide ports to 0.
                        .
                        If one of the given ports is a NULL pointer the function returns an error.
                        @startuml MEDIC_b_SetupPorts_activity.png
                        start
                          if(Have all require and provide ports\nbeen written into the Handler List?) Then (Yes)
                            :1}
                          else(No)
                            :2}
                            #Yellow:Raise **Error flag** and display warning:
                            <b>MEDIC_ASSERT</b> |
                          endif
                          partition "Execute for all Require Ports\nin the MEDIC_PortHandlerList"{
                            if(Require Port is NULL pointer?) then (No)
                              if(SignalHeader is Null Pointer?) then (Yes)
                                :3}
                                #Orange:Reset corresponding SyncRef structure:
                                <b>MEDIC_v_SetSignalHeaderError</b> >
                                note left
                                  Some Ports do not have a Signal header. 
                                  If this is the case, the signal header 
                                  pointer in the Port Handler is set 
                                  explicitly to NULL. This is no error case!
                                end note
                              else(No)
partition #LightBlue **MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK** {
                                #Orange:Port Update check: Assure that the port has 
                                been updated withing the required time:
                                <b>MEDIC_b_CheckPortUpdate</b> >
}
                                if(Port Update Check failed?) then (Yes)
                                  :4}
                                  :**InitialCompState** = COMP_STATE_TEMPORARY_ERROR;
                                else (No)
                                  :5}
                                  :**InitialCompState** = Signal State;
                                endif

                                #Orange:Set the state of all subcomponents to 
                                the **InitialCompState**:
                                <b>MEDIC_v_SetSubComponentStates</b> >

                                :Copy Port Signal Header to 
                                corresponding SyncRef Structure;
                              endif
                            else(Yes)
                            :6}
                              #Orange:Reset corresponding SyncRef structure:
                              <b>MEDIC_v_SetSignalHeaderError</b> >
                              #Orange:Set the states of all influenced 
                              subcomponents to error:
                              <b>MEDIC_v_SetSubComponentStates</b> >
                              #Yellow:Raise **Error flag** and display warning:
                              <b>MEDIC_ASSERT</b> |
                            endif
                          }
                          partition "Execute for all Provide Ports\nin the MEDIC_PortHandlerList"{
                            note left
                              Further Provide port handling has to be done after the 
                              call of the subcomponents. (see **MEDIC_v_FillProPortHeaders**)
                            end note
                            if(Provide Port is NULL pointer?) then (No)
                              :7}
                              :Initialize the entire structure to 0;
                            else(Yes)
                              :8}
                              #Yellow:Raise **Error flag** and display warning:
                              <b>MEDIC_ASSERT</b> |
                            endif
                          }
                        stop
                        @enduml

  @return               boolean bError : Error flag, True if error was detected.

  @param[in,out]        pPortHandlerList : List containing Port handlers for all require and provide ports.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK\n
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  MEDIC_PortHandlerList has been filled by calls to the functions 
                        @ref MEDIC_v_SetupReqPortHandlers and @ref MEDIC_v_SetupProPortHandlers
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability
                        @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_918}
                        @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_916}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2017-11-22, reviewer: Andreas Danner, reason: pPortHandlerList is modified by means of pCurrPort*/
static boolean MEDIC_b_SetupPorts(MEDICPortHandlerList_t * const pPortHandlerList)
{
  uint32                        uPortNo         = 0u;
  uint8                         uNofReqPorts    = MIN(pPortHandlerList->uNofReqPorts,MEDIC_NOF_REQ_PORTS); /* PRQA S 4548*/
  uint8                         uNofProPorts    = MIN(pPortHandlerList->uNofProPorts,MEDIC_NOF_PRO_PORTS); /* PRQA S 4548*/
  boolean                       bError          = b_FALSE;
  MEDICReqPortHandler_t const * pCurrReqPort;
  MEDICProPortHandler_t const * pCurrProPort;

  /* Check if number of ports matches number of activated ports. Can help to detect unchecked ports. */
  /* This is done in two separate "ifs" to distinguish between the asserts for Pro and Req Ports     */
  if(pPortHandlerList->uNofProPorts != MEDIC_NOF_PRO_PORTS) /*PRQA S 4548*//* uic45572: type matches as the macro is also typecasted to uint8 */
  {
    MEDIC_ASSERT(b_FALSE);/*PRQA S 3112,3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
    bError = b_TRUE;
  }
  if(pPortHandlerList->uNofReqPorts != MEDIC_NOF_REQ_PORTS) /*PRQA S 4548*//* uic45572: type matches as the macro is also typecasted to uint8 */
  {
    MEDIC_ASSERT(b_FALSE);/*PRQA S 3112, 3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
    bError = b_TRUE;
  }

  /* Set Up Require Ports */
  for (uPortNo = 0u; uPortNo < uNofReqPorts; ++uPortNo)
  {
    pCurrReqPort = &(pPortHandlerList->ReqPortHandler[uPortNo]);
    if(pCurrReqPort->pReqPort!=NULL)
    {
      /* Check signal header */
      if(pCurrReqPort->pGenericReqPortData != NULL)
      {
        MEDICCompState_t InitialCompState;
        
        /* ----- Check signal header state ----- */
        switch(pCurrReqPort->pGenericReqPortData->sSigHeader.eSigStatus)
        {
          case AL_SIG_STATE_INIT    : 
            InitialCompState = COMP_STATE_NOT_INITIALIZED; 
            #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
            MEDIC_p_ModMEDICDiag()->uiReqPortsNotInitialized = MEDIC_p_ModMEDICDiag()->uiReqPortsNotInitialized | ((uint32)1<<uPortNo);
            #endif
            break;
          case AL_SIG_STATE_OK      : 
            InitialCompState = COMP_STATE_RUNNING;
            break;
          case AL_SIG_STATE_INVALID : 
            InitialCompState = COMP_STATE_TEMPORARY_ERROR;
            #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
            MEDIC_p_ModMEDICDiag()->uiReqPortsError = MEDIC_p_ModMEDICDiag()->uiReqPortsError | ((uint32)1<<uPortNo);
            #endif
            break;
          default:
            InitialCompState = COMP_STATE_TEMPORARY_ERROR; 
            #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
            MEDIC_p_ModMEDICDiag()->uiReqPortsError = MEDIC_p_ModMEDICDiag()->uiReqPortsError | ((uint32)1<<uPortNo);
            #endif
            break;
        }

        /* ----- Check timestamp for consistency ----- */
        #if (MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK)
        if(    (MEDIC_p_GetFrameData()->eOpMode == MEDIC_MOD_RUNNING)
            && (TRUE == MEDIC_b_CheckPortUpdate(&(pCurrReqPort->pGenericReqPortData->sSigHeader.uiTimeStamp), 
                                                &(pCurrReqPort->MeasCycleMonitor), 
                                                FCT_SEN_CYCLE_TIME, 
                                                FCT_INPUT_ACCEPTABLE_DROPS)))
        {
          InitialCompState = COMP_STATE_TEMPORARY_ERROR;
        }
        #endif

        /* ----- Set the determined state as initial state for all influenced subcomponents ----- */
        MEDIC_v_SetSubComponentStates(pCurrReqPort->InfluencedSubComponents,InitialCompState);
        
        /* ----- Copy the signal header to the sync ref structure ----- */
        *(pCurrReqPort->pReqSignalHeaderSyncRef)  = pCurrReqPort->pGenericReqPortData->sSigHeader;
      }
      else
      { /* Pointer is set to 0 if a port does not have a signal header. This is not an error case! */
        MEDIC_v_SetSignalHeaderError(pCurrReqPort->pReqSignalHeaderSyncRef);
      }
    }
    else
    {
      MEDIC_v_SetSubComponentStates(pCurrReqPort->InfluencedSubComponents, COMP_STATE_TEMPORARY_ERROR);
      MEDIC_v_SetSignalHeaderError(pCurrReqPort->pReqSignalHeaderSyncRef);
      bError = b_TRUE;
      MEDIC_ASSERT(b_FALSE);/*PRQA S 3112, 3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
    }
  }
  
  /*Set Up Provide Ports*/
  for (uPortNo = 0u; uPortNo < uNofProPorts; ++uPortNo)
  {
    pCurrProPort = &(pPortHandlerList->ProPortHandler[uPortNo]);
    if(pCurrProPort->pProPort!=NULL)
    {
      /* Initialize all provide port structures to 0 */
      (void)MEDIC_MEMSET(pCurrProPort->pProPort, 0, (uint16)pCurrProPort->uSize); /*PRQA S 2869, 0315 2 #date: 2020-06-11, reviewer: Nalina M, reason: Generic Implementation */
    }
    else
    {
      bError = b_TRUE;
      MEDIC_ASSERT(b_FALSE);/*PRQA S 3112, 3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
    }
  }

  return bError;
}/* PRQA S 7002 *//*suppressing cyclomatic complexity for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         MEDIC_v_InitPortHandlerList                                                                   */ /*!

  @brief                Resets all elements in the Port handler list.

  @description          Sets all elements of the port handler list to 0. Keeps the information of 
                        the MeasCycleMonitoring. \n
                        This function should be called each cycle at the beginning of the PortProcessing.
                        @startuml MEDIC_v_InitPortHandlerList_activity.png
                        start
                          partition "Execute for all REQ ports" {
                            :Set all elements except
                            the MeasCycleData to 0;
                          }
                          partition "Execute for all PRO ports" {
                            :Set all elements to 0;
                          }
                        stop
                        @enduml

  @return               void

  @param[in,out]        pPortHandlerList : Pointer to the port handler List

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     Not Applicable 

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static void MEDIC_v_InitPortHandlerList(MEDICPortHandlerList_t   * const pPortHandlerList)
{
  uint8 uPortNo;
  pPortHandlerList->uNofProPorts = 0u;
  pPortHandlerList->uNofReqPorts = 0u;

  for (uPortNo = 0u; uPortNo < MEDIC_NOF_REQ_PORTS; uPortNo++) /*PRQA S 4548 *//* uic45572:type matches as the macro is also typecasted to uint8 */
  {
    pPortHandlerList->ReqPortHandler[uPortNo].pReqPort                 = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pGenericReqPortData      = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqSignalHeaderSyncRef  = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].InfluencedSubComponents  = MEDIC_SUB_COMP_NONE;

    /* MeasCycle data has to be kept over the cycles to make a monitoring of the timestamps possible (see function @ref MEDIC_b_CheckPortUpdate). 
       There is no need to reset it in the init case, as this check is only relevant if MEDIC is in Running Mode (see @ref MEDIC_b_SetupPorts).
       As the component has to be called in init at least once before it switches to run, the Meas cycle data will be updated during this init call 
       and will be correct when MEDIC is called in Running for the first time. */

  }

  for (uPortNo = 0u; uPortNo < MEDIC_NOF_PRO_PORTS; uPortNo++) /*PRQA S 4548 *//* uic45572: type matches as the macro is also typecasted to uint8 */
  {
    pPortHandlerList->ProPortHandler[uPortNo].pProPort                 = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pGenericProPortData      = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pGenericReqPortData      = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].uInfluencingSubComponents= MEDIC_SUB_COMP_NONE;
    pPortHandlerList->ProPortHandler[uPortNo].uMeasFreezeAddress       = 0u;
    pPortHandlerList->ProPortHandler[uPortNo].uProNewVersionNumber     = 0u;
    pPortHandlerList->ProPortHandler[uPortNo].uSize                    = 0u;
  }
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_PortSpecificHandling                                                                  */ /*!

  @brief                Handles special logic that shall only be executed for selected ports.

  @description          For certain ports special checks shall be executed. Therefore this function is used.
                        As at this point in the cycle it is not clear if the ports are valid, all port checks \n
                        have to be done again for each port here. Also the switches that de-/activate a port have 
                        to be repeated here.\n
                        Currently the following ports are handled different from the generic port handling:
                        - **VehCtrlData:** \n
                          The VehCtrlData contains the information about the current OpMode in which MEDIC shall be called, 
                          therefore it is the first port that has to be handled. The OpMode is used to initialize @ref the MEDIC_p_GetFrameData \n
                          which contains the component states of MEDIC and all of its subcomponents.\n
                          Additionally the signal header of the structure @ref MEDIC_SyncRef is filled with the signal header of the VehCtrlData.
                        - **EgoDynRaw:** \n
                          The VDY Signal EgoDynRaw has a special structure, that indicates the current quality 
                          of its content. This quality shall be checked before the port is used.\n
                          Therefore a counter uiVDYSigErrorCnt (part of @ref MEDIC_Frame) is increased if a state is found to be invalid.
                          If the counter exceeds a given limit (@ref MEDIC_MAX_VDY_SIG_ERRORS) the State of the CD subcomponent \n
                          is set to COMP_STATE_TEMPORARY_ERROR. The consequence is a call of CD in State @ref COMP_STATE_TEMPORARY_ERROR
                          and an invalidation of all output ports that are influence by CD.
                        .
                        <b>ATTENTION:</b> Try to keep this function as small as possible. The ports should be handled 
                        as generic as possible to simplify maintainability.
                        @startuml MEDIC_v_PortSpecificHandling_activity.png
                        start
                          partition **REQ:SenCtrlData** {
                          if(Pointer to SenControl Data is valid?) then (Yes)
                            note right:This should be done at the very beginning to\nassure that the MEDIC Frame is initialized.
                            :1}
                            #Orange:Get the MEDIC OpMode from the SenCtrlData request port 
                            and initialize the MEDICFrame data accordingly:
                            <b>MEDIC_v_InitFrameData</b> >
                            #Orange:Set the signal header of the SyncRef structure to 
                            the signal header of the SenControl Data:
                            <b>MEDIC_v_SetSignalHeader</b> >
                          else(No)
                            :2}
                            #Orange:Initialize the MEDIC Frame with MEDIC_MOD_SHUTDOWN:
                            <b>MEDIC_v_InitFrameData</b> >
                            #Orange:Set the signal header of the SyncRef structure to error:
                            <b>MEDIC_v_SetSignalHeaderError</b> >
                          endif
                          }
                          partition **REQ:EgoDynRaw** {
                          if(Pointer to EgoDynRaw is valid?) then (Yes)
                            :Check signal status of ego speed,
                            acceleration and yaw rate;
                            if(Check passed?) then (Yes)
                              :3}
                              :Reset VDY signal error counter;
                            else(No)
                              :4}
                              :Increase VDY signal error counter;
                              note left: Limited to maximum value
                            endif
                          else(No)
                            :5}
                          endif
                          }
                          stop
                        @enduml

  @return               void

  @param[in]            pRequirePorts : Pointer to all require ports.

  @glob_in              @ref MEDIC_u_GetOpMode \n
                        @ref MEDIC_p_GetWorkingData
  @glob_out             @ref MEDIC_p_ModSyncRef

  @c_switch_part        @ref MEDIC_ARCHITECTURE_VERSION              \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION  \n
                        @ref USE_MEDICWRAPPER_INTER                  \n
                        @ref USE_MEDICWRAPPER_INTERMEAS              \n
                        @ref USE_MEDICWRAPPER_INTRAMEAS              \n
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST        \n

  @pre                  Assure that pointer to pRequirePorts is != NULL
  @post                 None

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1127-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
static void MEDIC_v_PortSpecificHandling(
                                        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
                                        reqMEDICPtrList_t const * const pRequirePorts
                                        #else
                                        MEDIC01_ReqPorts  const * const pRequirePorts
                                        #endif
                                        )
{
  /* ======== pRequirePorts ==========*/

  /* ---------- pVehCtrlData ---------- */

  /* The veh ctrl port handling has to be executed first to assure that the OpMode is 
     correctly transferred into the (Sub-) component states */
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  if (pRequirePorts->pVehCtrlData != NULL)
  #else
  if (pRequirePorts->controlData  != NULL)
  #endif
  {
    #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    /* Get the current requested OpMode from the VehCtrlData Port */
    /*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
    MEDICOpMode_t const   eOpMode = (MEDICOpMode_t)MEDIC_u_GetOpMode();
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    const SignalHeader_t* pSigHeader = &(pRequirePorts->pEgoDynRaw->sSigHeader);
    #else
    SignalHeader_t        SigHeader;
    const SignalHeader_t* pSigHeader = NULL;
    if (pRequirePorts->egoMotion != NULL)
    {
      const CEM_SignalHeader_t* pCEMSigHeader = &(pRequirePorts->egoMotion->sigHeader);
      SigHeader.uiTimeStamp          = (AlgoDataTimeStamp_t)(pCEMSigHeader->uiTimeStamp);
      SigHeader.eSigStatus           = pCEMSigHeader->eSigStatus;
      SigHeader.uiCycleCounter       = pCEMSigHeader->uiCycleCounter;
      SigHeader.uiMeasurementCounter = pCEMSigHeader->uiMeasurementCounter;
      pSigHeader = &SigHeader;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      if (uiPreviousTimestamp > 0u)
      {
        MEDIC_p_ModMEDICDiag()->iDataAge = (sint32)((uint32)(SigHeader.uiTimeStamp - uiPreviousTimestamp));
      }
      uiPreviousTimestamp = SigHeader.uiTimeStamp;
      #endif
    }
    else
    {
      SigHeader.uiTimeStamp           = (AlgoDataTimeStamp_t)(0u);
      SigHeader.eSigStatus            = AL_SIG_STATE_INVALID;
      SigHeader.uiCycleCounter        = 0u;
      SigHeader.uiMeasurementCounter  = 0u;
      pSigHeader = &SigHeader;
      #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
      MEDIC_p_ModMEDICDiag()->iDataAge = 0;
      uiPreviousTimestamp = 0u;
      #endif
    }
    #endif
    
    /* Setup the MEDIC frame according to the requested OpMode from the VehCtrlData Port. In case of pointer errors: set shutdown */
    MEDIC_v_InitFrameData(eOpMode);
    MEDIC_v_SetSignalHeader(&(MEDIC_p_ModSyncRef()->sSigHeader)                                , pSigHeader, pSigHeader->eSigStatus);
    /* Set the header values for the internal data also */
    #if (USE_MEDICWRAPPER_INTER)
    MEDIC_p_GetWorkingData()->pInterCycle->uVersion     = MEDIC_INTER_CYCLE_MEMORY_VERSION;
    MEDIC_v_SetSignalHeader(&(MEDIC_p_GetWorkingData()->pInterCycle->sSigHeader)               , pSigHeader, pSigHeader->eSigStatus);
    #endif
    #if (USE_MEDICWRAPPER_INTERMEAS)
    MEDIC_p_GetWorkingData()->pInterCycleMeas->uVersion = MEDIC_INTER_CYCLEMEAS_MEMORY_VERSION;
    MEDIC_v_SetSignalHeader(&(MEDIC_p_GetWorkingData()->pInterCycleMeas->sSigHeader)           , pSigHeader, pSigHeader->eSigStatus);
    #endif
    #if (USE_MEDICWRAPPER_INTRAMEAS)
    MEDIC_v_SetSignalHeader(&(MEDIC_p_GetWorkingData()->pIntraCycleMeas->sSigHeader)           , pSigHeader, pSigHeader->eSigStatus);
    #endif
    MEDIC_v_SetSignalHeader(&(MEDIC_p_GetWorkingData()->pStackData->sSigHeader)                , pSigHeader, pSigHeader->eSigStatus);
    #endif // MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  }
  else
  {
    MEDIC_v_InitFrameData(MEDIC_MOD_SHUTDOWN);
    MEDIC_v_SetSignalHeaderError(&(MEDIC_p_ModSyncRef()->sSigHeader));
  }
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_ProcessPorts                                                                          */ /*!

  @brief                Processes require ports, provide ports and service functions to enable an error free 
                        operation of the MEDIC component. 

  @description          Executes pointer and signal state checks and sets up all internal data that is 
                        related to the ports. This is done by means of Port Handlers. Each require and \n
                        provide port has its own handler (see @ref MEDIC_PortHandlerList), that is filled in the 
                        functions @ref MEDIC_v_SetupProPortHandlers or @ref MEDIC_v_SetupProPortHandlers. \n
                        The handlers contain all information that is necessary to set up a port. The advantage 
                        of this procedure is the generic handling of all ports: The Possibility to fill the \n
                        handlers at one point in the code eliminates the eventuality of missing a port in a 
                        later processing step. The handlers are processed in two functions:
                        - After the handlers where filled, the function @ref MEDIC_b_SetupPorts is called. It checks the 
                          pointers and signal state.
                        - The function @ref MEDIC_v_FillProPortHeaders is called AFTER the call of the subcomponents. It fills 
                          the provide port signal headers according to the calculation results.
                        .
                        @startuml MEDIC_v_ProcessPorts_activity.png
                        start
                          partition "Filling of port handlers" {
                          #Orange:Initialize the port handlers:
                          <b>MEDIC_v_InitPortHandlerList</b> >
                          #Orange:Set up the require port handlers:
                          <b>MEDIC_v_SetupReqPortHandlers</b> >
                          #Orange:Set up the provide port handlers:
                          <b>MEDIC_v_SetupProPortHandlers</b> >
                          }
                          partition "Checking of ports" {
                          #Orange:Execute port specific handling for certain ports:
                          <b>MEDIC_v_PortSpecificHandling</b> >
                          note left:Has to be called before MEDIC_b_SetupPorts\nas MEDIC_p_GetFrameData is filled here
                          partition #LightBlue **MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS** {
                          #Orange:Check Service function pointers for NULL pointer:
                          <b>MEDIC_b_CheckServiceFunctions</b> >
                          }
                          #Orange:Check and set up all require and provide 
                          ports by using the port handlers
                          <b>MEDIC_b_SetupPorts</b> >
                          partition #LightBlue **MEDIC_CFG_ENABLE_DEM_OUTPUT** {
                          #Orange:Check the require ports for enabling DEM output:
                          <b>MEDIC_v_CheckReqPort_DEM</b> >
                          }
                          }
                          partition "Error Routine" {
                          if(**Error flag** was set by one\nof the function calls?) then (Yes)
                            :1}
partition #LightBlue **MEDIC_CFG_USE_DEM** { 
                            #Orange:Set DEM event **Failed**: <b>MEDIC_v_SetDem</b> > 
}
partition #LightBlue **MEDIC_CFG_USE_ALGOCOMPSTATE** {
                            #Orange:Write **Critical error** to error buffer:
                            <b>MEDIC_v_SetAlgoErrorBuffer</b> >
}
                            #Orange:Switch to MEDIC Error Mode:
                            <b>MEDIC_v_SignalErrorShutdown</b> >
                          else(No)
                            :2}
partition #LightBlue **MEDIC_CFG_USE_DEM** { 
                            #Orange:Set DEM event **Passed**: <b>MEDIC_v_SetDem</b> >
}
                          endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in]            pRequirePorts :   Pointer to a structure with all require port pointers.
  @param[in,out]        pProvidePorts :   Pointer to a structure with all provide port pointers.
  @param[in,out]        pPortHandlerList: Pointer to the port handler list
  @param[in]            pServiceFuncts :  Pointer to a structure with all service function pointers.
  @param[in,out]        pErrorBuffer :    Error buffer to which the current error shall be written.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_USE_ALGOCOMPSTATE\n
                        @ref MEDIC_CFG_USE_DEM\n
                        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  Assure that pointers pRequirePorts, pProvidePorts, pServiceFuncts and pErrorBuffer are != NULL.
  @post                 @ref MEDIC_v_FillProPortHeaders has to be called after the call of the subcomponents.

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1120-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
void MEDIC_v_ProcessPorts(/*PRQA S 3408*//* uic45572: function is defined as extern in medic_main.c */
                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10) 
                          reqMEDICPtrList_t const  * const pRequirePorts,
                          proMEDICPtrList_t        * const pProvidePorts,
                          #else
                          MEDIC01_ReqPorts   const * const pRequirePorts,
                          MEDIC01_ProPorts   const * const pProvidePorts,
                          #endif
                          MEDICPortHandlerList_t   * const pPortHandlerList
                          #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
                          #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
                          , AS_t_ServiceFuncts const * const pServiceFuncts
                          #else
                          , MEDIC_Services     const * const pServiceFuncts
                          #endif
                          #endif
                          #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
                          , GenAlgoQualifiers_t       * const pErrorBuffer
                          #endif
                          )
{
  boolean bError = b_FALSE;


  /* ---------- Filling of Port Handlers ---------- */

  /* Initialize the port handlers */
  MEDIC_v_InitPortHandlerList(pPortHandlerList);

  /* Set up Require Port handlers */
  MEDIC_v_SetupReqPortHandlers(pRequirePorts, pPortHandlerList);

  /* Set up Provide Ports handlers */
  MEDIC_v_SetupProPortHandlers(pProvidePorts, pRequirePorts, pPortHandlerList);

  /* ---------- Checking of Ports ---------- */

  /* The port specific handling treats all port related actions that can not be executed by means of the port handler.
     It has to be called before MEDIC_b_SetupPorts to assure that the Frame and the (sub-)component states are initialized */
  MEDIC_v_PortSpecificHandling(pRequirePorts);

  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Evaluate Service Function pointers*/
  bError = (boolean)(bError || MEDIC_b_CheckServiceFunctions(pServiceFuncts)); /*PRQA S 4115,4558,3415 *//* uic45572: check is needed */
  #endif

  /* Check and set up all ports by evaluating the Port handlers */
  /*PRQA S 2986 */ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
  bError = (boolean)((bError) || (MEDIC_b_SetupPorts(pPortHandlerList))); /*PRQA S 4115,4558 *//* uic45572: check is needed */

  /* Check the require ports for enabling DEM output*/
  #if (MEDIC_CFG_ENABLE_DEM_OUTPUT)
  MEDIC_v_CheckReqPort_DEM(pPortHandlerList);
  #endif
  /* ---------- Error Routine ---------- */

  if (bError == b_TRUE)
  {
    /* Some port pointer is NULL => DEM and shutdown */
    /* Validity of service pointer isn't clear here, anyway assign internal global alias*/
    #if (MEDIC_CFG_USE_DEM)
    MEDIC_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_FAILED);
    #endif
    #if (MEDIC_CFG_USE_ALGOCOMPSTATE)
    MEDIC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
    #endif
    MEDIC_v_SignalErrorShutdown(b_FALSE);
  }
  else
  {
    #if (MEDIC_CFG_USE_DEM)
    MEDIC_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_PASSED);
    #endif
  }
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_FillProPortHeaders                                                                    */ /*!

  @brief                Fills the provide port signal headers after the call to the subcomponents.

  @description          Fills the signal header of a provide port according to the signal header of a require port. \n
                        Fills the state of this signal header according to the worst component state of the influencing 
                        subcomponents. \n
                        Sets all signal states to invalid if an error was detected.
                        @startuml MEDIC_v_FillProPortHeaders_activity.png
                        start
                          partition "Execute for all provide port handlers" {
                            if(Provide Port Pointer is valid?\nAND Pointer to the GenericProPortData is valid?) then (Yes)
                              :Write version number to the port;
                              if(Pointer to the related require\nport signal header is valid?) then (Yes)
                                :1}
                                #Orange:Get the worst comp state of all assigned subcomponents:
                                <b>MEDIC_e_GetWorstSubComponentState</b> >
                                note left
                                  If no subcomponent is assigned (MEDIC_SUB_COMP_NONE), 
                                  the Comp state COMP_STATE_SUCCESS is returned by the function. 
                                  To make this logic independent of the behavior of the 
                                  function MEDIC_e_GetWorstSubComponentState, this condition 
                                  is checked here explicitly by using an if.
                                end note
                                
                                #Orange:Set the signal state of the provide port 
                                according to the worst comp state:
                                <b>MEDIC_v_SetSignalHeader</b> >

                              else(No)
                                :2}
                                #Orange:Set Signal header to default and
                                Signal State to **INVALID**:
                                <b>MEDIC_v_SetSignalHeaderError</b> >
                              endif
                            else(No)
                              :3}
                              #Yellow:Display warning:
                              <b>MEDIC_ASSERT</b> |
                              note right
                                Assert is not necessary here, as it
                                would already have been triggered 
                                in MEDIC_v_ProcessPorts. Nevertheless 
                                keep here to assure safety.
                              end note
                            endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in]            pPortHandlerList: Pointer to the port handler list

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST\n

  @pre                  @ref MEDIC_v_ProcessPorts has been called at the beginning of the cycle.
  @post                 None

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1120-0007e0f8}

  @author               Sadhanashree Srinivasa | Sadhanashree.Srinivasa@continental-corporation.com | +91-80-66791100-8439
*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2018-08-29, reviewer: Danner Andreas, reason: pPortHandlerList is modified via pCurrPort*/
void MEDIC_v_FillProPortHeaders(MEDICPortHandlerList_t * const pPortHandlerList)
{
  uint32 uPortNo = 0;

  for (uPortNo = 0; (uPortNo < pPortHandlerList->uNofProPorts); ++uPortNo)
  { 
    MEDICProPortHandler_t const * const pCurrPort = &(pPortHandlerList->ProPortHandler[uPortNo]);
    if (    (pCurrPort->pProPort            != NULL)
         && (pCurrPort->pGenericProPortData != NULL) )
    {
      /* If ProPort pointer is valid, fill the provide ports signal header */
      pCurrPort->pGenericProPortData->uiVersionNumber = pCurrPort->uProNewVersionNumber;
    
      if( pCurrPort->pGenericReqPortData != NULL )
      {
        AlgoSignalState_t NewSigState;
        MEDICCompState_t  eFusedCompState;
        
        if(pCurrPort->uInfluencingSubComponents == MEDIC_SUB_COMP_NONE)
        {
          /* This case can only be reached if no SubComponent is contained in uInfluencingSubComponents. In that case the SigState is always OK
             Do this check explicitly here to be independent of the behavior of the function MEDIC_e_GetWorstSubComponentState */
          eFusedCompState = COMP_STATE_SUCCESS;
        }
        else
        {
          eFusedCompState = MEDIC_e_GetWorstSubComponentState(pCurrPort->uInfluencingSubComponents);
        }
        
        switch(eFusedCompState)
        {
          case COMP_STATE_PERMANENT_ERROR:
          case COMP_STATE_TEMPORARY_ERROR:
          case COMP_STATE_REDUCED_AVAILABILITY:
               NewSigState = AL_SIG_STATE_INVALID;
               break;
          case COMP_STATE_NOT_INITIALIZED:
          case COMP_STATE_NOT_RUNNING:
               NewSigState = AL_SIG_STATE_INIT;
               break;
          case COMP_STATE_RUNNING:
          case COMP_STATE_SUCCESS:
               NewSigState = AL_SIG_STATE_OK;
               break;
          default:
               NewSigState = AL_SIG_STATE_INVALID;
               MEDIC_ASSERT(b_FALSE); /*PRQA S 3112,3119*//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
               break;
        }

        /* Fill with given ReqPort SigHeader if the ReqPort Signal was valid */
        MEDIC_v_SetSignalHeader(&(pCurrPort->pGenericProPortData->sSigHeader),
                                &(pCurrPort->pGenericReqPortData->sSigHeader),
                                NewSigState                    );
      }
      else
      {
        /* Fill with default if ReqPort Signal was invalid */
        MEDIC_v_SetSignalHeaderError(&(pCurrPort->pGenericProPortData->sSigHeader));
      }
    }
    else
    {
      /* No assert necessary, is already set in previous step */
      /* Nothing can be done, pointer is invalid */
      MEDIC_ASSERT(b_FALSE); /*PRQA S 3112, 3019,3119 *//* date: 2019-1-3, reviewer: Pronnoy Chowdhury, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
    }
  }
}
#if (MEDIC_CFG_ENABLE_DEM_OUTPUT)
/*************************************************************************************************************************
  Functionname:         MEDIC_v_CheckReqPortDEM                                                                   */ /*!

  @brief                Check the RequirePorts for Timestamperror.

  @description          Checks all the Require Ports if contains timestamp error
                        then set the DEM output.
                        @startuml MEDIC_v_CheckReqPortDEM_activity.png
                        start
                          partition "Execute for each Require Port" {
                            if(Pointer to GenericReqPortData is Valid?) then (Yes)
                               if(Difference between the current timestamp and Previous timestamp of the req port is greater than specified data age) then (Yes)
                                  :set timestamp error;
                                  :Reset the counter as the timestamp has changed since the previous cycle;
                               else(No)
                                  if(Difference between current timestamp and Previous timestamp of the req port is zero) then (Yes)
                                     :Increment the counter which is used to track for how many cycles the data is unchanged;
                                     if(The timestamp counter value is greater than the specified cycles?) then (Yes)
                                        :set timestamp error;
                                     endif
                                  else(No)
                                     :Reset the counter as the timestamp has changed since the previous cycle;
                                  endif
                               :Store the current timestamp value to be used as previous timestamp value in next cycle;
                               endif
                            else(No)
                              :No Signal Header (Do nothing);
                            endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in,out]        pPortHandlerList : Pointer to the port handler List

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST \n
                        @ref MEDIC_CFG_ENABLE_DEM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     Not Applicable

  @testmethod           Test of output data (dynamic module test)

  @traceability
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Minuthi.H U | minuthi.h.u@continental-corporation.com
*************************************************************************************************************************/
static void MEDIC_v_CheckReqPort_DEM(MEDICPortHandlerList_t   * const pPortHandlerList)
{
    uint8 ui_CurrReqPort;
    MEDICReqPortHandler_t const * pCurrReqPort;
    for (ui_CurrReqPort = 0; ui_CurrReqPort < MEDIC_NOF_REQ_PORTS; ui_CurrReqPort++)
    {
      #ifdef MEDIC_SIMU
      if (ui_CurrReqPort != 10) // Temporary workaround for MEDIC Parameters Timestamp being constant in MTS
      #endif
      {
        pCurrReqPort = &(pPortHandlerList->ReqPortHandler[ui_CurrReqPort]);
        if (pCurrReqPort->pGenericReqPortData != NULL)
        {
            if ((pCurrReqPort->pGenericReqPortData->sSigHeader.uiTimeStamp - ReqPort_PrevTimestamp[ui_CurrReqPort]) > MEDIC_CFG_TIMESTAMP_MAX_AGE_US)
            {
                /* set the error*/
                MEDIC_v_SetDEMOutput(ui_CurrReqPort);
                ReqPort_DEMctr[ui_CurrReqPort] = 0u;
            }
            else
            {
                if ((pCurrReqPort->pGenericReqPortData->sSigHeader.uiTimeStamp - ReqPort_PrevTimestamp[ui_CurrReqPort]) == 0u)
                {
                    ReqPort_DEMctr[ui_CurrReqPort] += 1u;
                    if (ReqPort_DEMctr[ui_CurrReqPort] > MEDIC_CFG_TIMESTAMP_MAX_UNCHANGED_CYCLES)
                    {
                        /* set error*/
                        MEDIC_v_SetDEMOutput(ui_CurrReqPort);
                    }
                }
                else
                {
                    ReqPort_DEMctr[ui_CurrReqPort] = 0u;
                }
            }
            ReqPort_PrevTimestamp[ui_CurrReqPort] = pCurrReqPort->pGenericReqPortData->sSigHeader.uiTimeStamp;
        }
        else
        {
            /*No Signal header Do nothing*/
        }
      }
    }
}


/*************************************************************************************************************************
  Functionname:         MEDIC_v_SetDEMOutput                                                                   */ /*!

  @brief                Set the Timestamperror and corresponding req port number in eErrorCode

  @description          Set the timestamp error, set the Algo component and subcomponent state to Temporary error.
                        @startuml MEDIC_v_SetDEMOutput_activity.png
                        Start
                        If (null pointer check ok?) then (yes)
                        :Set the Timeerror Mask;
                        :Set the ReqPort Mask to covey due to which req port the error is caused;
                        :set Error code;
                        :set comp state;
                        :set the subcomponent state;
                        endif
                        stop
                        @enduml

  @return               void

  @param[in,out]        ui_ReqPortnum : Require Port number 

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_EMERGENCY_BRAKE_ASSIST \n
                        @ref MEDIC_CFG_ENABLE_DEM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     Not Applicable

  @testmethod           Test of output data (dynamic module test)

  @traceability
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1121-0007e0f8}

  @author               Minuthi.H U | minuthi.h.u@continental-corporation.com
*************************************************************************************************************************/
static void MEDIC_v_SetDEMOutput(uint8 const ui_ReqPortnum)
{
    AlgoCompState_t *pCompStateProvidePort   = MEDIC_p_ModCompState();
    if (pCompStateProvidePort != NULL)
    {
        uint32 ui_Timerrormask             = (uint32)(1u << MEDIC_TIMESTAMP_ERROR);
        uint32 ui_ReqPortMask              = (uint32)(1u << (MEDIC_REQPORT_ERROR + ui_ReqPortnum));
        pCompStateProvidePort->eErrorCode |= (ui_Timerrormask | ui_ReqPortMask);
        pCompStateProvidePort->eCompState  = COMP_STATE_ERROR;
        MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_ALL, COMP_STATE_ERROR);
    }
} 
#endif /* MEDIC_CFG_ENABLE_DEM_OUTPUT */

#endif /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */

