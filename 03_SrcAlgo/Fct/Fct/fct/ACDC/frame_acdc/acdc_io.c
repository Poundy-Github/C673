/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification 

PACKAGENAME:               acdc_io.c

DESCRIPTION:               Function Processing I/O-Wrapper Main Module for ACDC component

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/09/07 07:48:55CEST $

VERSION:                   $Revision: 1.50 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_int.h"


/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* for ifndef __PDO__ */

#if (ACDC_CFG_FRAME)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup frame_io In-/Output
@ingroup frame
@brief          The In-/Output module contains functions that handle In- and Outputs.
@description    The module provides the following functionalities:
                - Check the ACDC Ports and set up the necessary globals to enable ACDC to run properly: @ref ACDC_v_ProcessPorts
                - Fill the Signal headers of the ACDC provide ports after the subcomponents have been called: @ref ACDC_v_FillProPortHeaders
                .
                If a new port shall be added, the following steps have to be executed:
                - Require Port:
                  - Add port to @ref reqACDCPrtList_t
                  - Add port to @ref ACDCSyncRef_t
                  - Add the ports switch to the macro @ref ACDC_NOF_REQ_PORTS
                  - Add the port to the function @ref ACDC_v_SetupReqPortHandlers, where its PortHandler has to be filled.
                - Provide Port:
                  - Add port to @ref provACDCPrtList_t
                  - Add the ports switch to the macro @ref ACDC_NOF_PRO_PORTS
                  - Add the port to the function @ref ACDC_v_SetupProPortHandlers, where its PortHandler has to be filled:
                    - Decide which subcomponents the ProPorts signal state shall depend on.
                    - Decide which ReqPort shall fill the ProPorts signal header.
                    - Decide if the port shall be frozen (assign MeasFreezeAdress) or not (assign 0).

                    @{
*/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK)
static boolean ACDC_b_CheckPortUpdate(AlgoDataTimeStamp_t const * const pInputPortMeasCycle,
                                        sMeasCycleMonitor       * const pLastMeasCycle,
                                                  float32         const fTargetCycleTime,
                                                    uint8               iAcceptableDrops);
#endif /*ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK*/

static void ACDC_v_SetSignalHeader(    SignalHeader_t       * const pDestSignalHeader,
                                       SignalHeader_t const * const pSourceSignalHeader, 
                                    AlgoSignalState_t               eSignalState);

static void ACDC_v_SetSignalHeaderError(SignalHeader_t         * const pSignalHeader);

static void ACDC_v_SetupProPortHandler(void                               *const pProPort,
                                       void                         const *const pReqPort,
                                       ACDCSubCompIndices_t         const        uInfluencingSubcomponents,
                                       AlgoInterfaceVersionNumber_t const        uVersionNumber,
                                       uint32                       const        uMeasFreezeAddress,
                                       uint32                       const        uFreezeSize,
                                       ACDCPortHandlerList_t              *const pPortHandlerList);

static void ACDC_v_SetupProPortHandlers(    provACDCPrtList_t       * const pProvidePorts,
                                             reqACDCPrtList_t const * const pRequirePorts,
                                        ACDCPortHandlerList_t       * const pPortHandlerList);

static void ACDC_v_SetupReqPortHander(void                  const *const pReqPort,
                                      ACDCSubCompIndices_t  const        uInfluencedSubcomponents,
                                      boolean               const        bSignalContainsGenericPortData,
                                      SignalHeader_t              *const pSyncRefSignalHeader,
                                      ACDCPortHandlerList_t       *const pPortHandlerList);

static void ACDC_v_SetupReqPortHandlers(     reqACDCPrtList_t const * const pRequirePorts,
                                        ACDCPortHandlerList_t       * const pPortHandlerList);

static void ACDC_v_PortSpecificHandling(reqACDCPrtList_t const * const pRequirePorts);

static boolean ACDC_b_SetupPorts(ACDCPortHandlerList_t * const pPortHandlerList);

static void ACDC_v_InitPortHandlerList(ACDCPortHandlerList_t   * const pPortHandlerList);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
static boolean ACDC_b_CheckServiceFunctions(AS_t_ServiceFuncts const * const pServiceFuncts);
#endif /* for if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

#if (ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK)
/*************************************************************************************************************************
  Functionname:         ACDC_b_CheckPortUpdate                                                                  */ /*!

  @brief                Checks if a port has been updated.

  @description          Compares the current port timestamp to the last timestamp and evaluates the result by raising 
                        an error flag in case of a skipped cycle or a missing port update.
                        @startuml ACDC_b_CheckPortUpdate_activity.png
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
  @c_switch_full        @ref ACDC_CFG_FRAME \n
                        @ref ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     \f$N = \f$ Number of acceptable Drops
                        - **Formula Acceptable drop time:** \n
                          \f$t_{Accept} =  (N + 1.5) \cdot t_{Cycle} \f$

  @testmethod           @ref TEST_ACDC_B_CHECKPORTUPDATE_001 \n
                        @ref TEST_ACDC_B_CHECKPORTUPDATE_002 \n
						@ref TEST_ACDC_B_CHECKPORTUPDATE_003 \n
                        @ref TEST_ACDC_B_CHECKPORTUPDATE_004 \n

  @author               Christian Obst
*************************************************************************************************************************/
static boolean ACDC_b_CheckPortUpdate(AlgoDataTimeStamp_t const * const pInputPortMeasCycle,
                                        sMeasCycleMonitor       * const pLastMeasCycle,
                                                  float32         const fTargetCycleTime,
                                                    uint8               iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /*PRQA S 4119 5*//*date: 2015-03-25 Reviewer: C. Obst: intended behavior to cast float to uInt. fractional part is neglectible.*/
  /*conversion second to microsecond*/
  const AlgoDataTimeStamp_t uiReceiveCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * ACDC_TIMESTAMP_TO_MICROSECONDS);
  /*accepted drops + current Cycle + 0.5 safety margin*/
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiReceiveCycleTimeUs ); 
  const AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_SEN_CYCLE_TIME * ACDC_TIMESTAMP_TO_MICROSECONDS);

  boolean bError = FALSE;

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
      bError = TRUE;        /*raise error*/
    }
  }
  else
  {
    /*update*/
    if ( uiDeltaTimeUs > uiMaxAcceptableDropTimeUs )
    {
      /*skipped cycle*/
      bError = TRUE;        /*raise error*/
    }
    else
    {
      /*new cycle received in time*/
      pLastMeasCycle->uiLastUpdateCounter = 0u;    /*reset update counter*/
    }
    pLastMeasCycle->uiTimeStamp = *pInputPortMeasCycle;
  }
  return bError;
}
#endif /* ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK */

/*************************************************************************************************************************
  Functionname:         ACDC_v_SetSignalHeader                                                                      */ /*!

  @brief                Copies information from one signal header to another. 

  @description          Copies Time Stamp and Measurement counter from pSourceSignalHeader to pDestSignalHeader. 
                        Sets the cycle counter of pDestSignalHeader to the Cycle counter of @ref ACDC_p_GetFrameData and its \n
                        Signal state to a given signal state.

  @return               void

  @param[in,out]        pDestSignalHeader   : The signal header to be filled.
  @param[in]            pSourceSignalHeader : The source signal header.
  @param[in]            eSignalState        : The signal state that shall be written to the DestSignal header.

  @glob_in              @ref ACDC_p_GetFrameData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_SETSIGNALHEADER_001

  @traceability         Design Decision

  @author               Gergely Ungvary
*************************************************************************************************************************/
static void ACDC_v_SetSignalHeader(   SignalHeader_t       * const pDestSignalHeader, 
                                      SignalHeader_t const * const pSourceSignalHeader, 
                                   AlgoSignalState_t               eSignalState)
{
  pDestSignalHeader->uiTimeStamp           = pSourceSignalHeader->uiTimeStamp;
  pDestSignalHeader->uiMeasurementCounter  = pSourceSignalHeader->uiMeasurementCounter;
  pDestSignalHeader->uiCycleCounter        = ACDC_p_GetFrameData()->uiCycleCounter;
  pDestSignalHeader->eSigStatus            = eSignalState;
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_SetSignalHeaderError                                                                 */ /*!

  @brief                Resets the Signal Header of a signal for which an error was detected. 
                        The current cycle counter is kept.

  @description          Init the @ref SignalHeader_t structure with default values for ACDC. These default 
                        values are the cycle counter of ACDC and the signal state @ref AL_SIG_STATE_INVALID. \n
                        Timestamp and measurement counter are set to zero.

  @return               void

  @param[in,out]        pSignalHeader : Header of a signal for which an error was detected.

  @glob_in              @ref ACDC_p_GetFrameData : uiCycleCounter, used to set signal header cycle counter
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_SETSIGNALHEADERERROR_001

  @traceability         Design Decision

  @author               Gergely Ungvary
*************************************************************************************************************************/
static void ACDC_v_SetSignalHeaderError(SignalHeader_t * const pSignalHeader)
{
  pSignalHeader->uiTimeStamp           = 0u;
  pSignalHeader->uiMeasurementCounter  = 0u;
  pSignalHeader->uiCycleCounter        = ACDC_p_GetFrameData()->uiCycleCounter;
  pSignalHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}



/*************************************************************************************************************************
  Functionname:         ACDC_v_SetupProPortHandler                                                                   */ /*!

  @brief                Function to set up a handler for a Provide Port.

  @description          This function fills a handler to enable a generic handling of all provide ports.
                        If the Require Port or the Provide port is zero, the corresponding pointers are not filled. \n
                        As they are initialized in each cycle (see @ref ACDC_v_InitPortHandlerList) they are NULL 
                        pointers in this case.

  @return               void

  @param[in,out]        pProPort : Void pointer to the current provide port
  @param[in]            pReqPort : Require port which shall be used to fill the signal header of the provide port.
  @param[in]            uInfluencingSubcomponents : Bitfield of all subcomponents which are influencing the provide port. 
                                                    (Used to set the signal state of the provide port signal header). @range [ACDC_SUB_COMP_NONE,ACDC_SUB_COMP_ALL]
  @param[in]            uVersionNumber : Version number of the provide port.
  @param[in]            uMeasFreezeAddress : Meas freeze address of the provide port (if 0, no meas freeze is executed).
  @param[in]            uFreezeSize : Size of the provide port (required for meas freeze).
  @param[in,out]        pPortHandlerList : Pointer to the Port Handler List which shall be filled.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods 

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void ACDC_v_SetupProPortHandler(void                               *const pProPort,
                                       void                         const *const pReqPort,
                                       ACDCSubCompIndices_t         const        uInfluencingSubcomponents,
                                       AlgoInterfaceVersionNumber_t const        uVersionNumber,
                                       uint32                       const        uMeasFreezeAddress,
                                       uint32                       const        uFreezeSize,
                                       ACDCPortHandlerList_t              *const pPortHandlerList)
{
  ACDCProPortHandler_t  * pCurrProHandler  = &(pPortHandlerList->ProPortHandler[pPortHandlerList->uNofProPorts]);
  
  pCurrProHandler->uProNewVersionNumber      = uVersionNumber;
  pCurrProHandler->uMeasFreezeAddress        = uMeasFreezeAddress;
  pCurrProHandler->uInfluencingSubComponents = uInfluencingSubcomponents;
  pCurrProHandler->uSize                     = uFreezeSize;
  pCurrProHandler->pProPort                  = pProPort;
  
  /* Get the Version Number and Signal Header of the ports. Assure that each port which is passed here has the generic Port data!! */
  pCurrProHandler->pGenericProPortData       = (ACDCGenericPortData_t       *const)pProPort;
  pCurrProHandler->pGenericReqPortData       = (ACDCGenericPortData_t const *const)pReqPort;


  pPortHandlerList->uNofProPorts++;
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_SetupProPortHandlers                                                                  */ /*!

  @brief                Sets up the port handlers for all provide ports.

  @description          Sets up the handlers of all provide ports by executing the function @ref ACDC_v_SetupProPortHandler
                        to add the following information to the handler:
                        - Source signal header for the provide port signal header.
                        - Component states that influence the provide port signal header state.
                        - Interface version of the provide port.
                        - Address for a possible meas freeze.
                        - Size of the port for the meas freeze.
                        .
                        More information regarding the Port Handler concept can be found here: @ref ACDC_v_ProcessPorts.
                        @startuml ACDC_v_SetupProPortHandlers_activity.png
                          start
                          partition "Execute for each provide port" {
                              #Orange:Fill Provide port handler:
                              <b>ACDC_v_SetupProPortHandler</b> >
                            }
                          stop
                        @enduml
  
  @return               void

  @param[in,out]        pProvidePorts :     Pointer to a structure containing all provide port pointers.
  @param[in]            pRequirePorts :     Pointer to a structure containing all require port pointers.
  @param[in,out]        pPortHandlerList :  Pointer to a list with all port handlers.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_COLLISION_DETECTION     \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE       \n
                        @ref FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  Assure that pRequirePorts != NULL
                        Assure that pProvidePorts != NULL
  @post                 Pro port information in the PortHandler is filled

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_SETUPPROPORTHANDLERS_001
	

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2018-08-29, reviewer: Danner Andreas, reason: pProvidePorts must not be const as it is filled into the port handler */
static void ACDC_v_SetupProPortHandlers(     provACDCPrtList_t       * const pProvidePorts,
                                              reqACDCPrtList_t const * const pRequirePorts,
                                         ACDCPortHandlerList_t       * const pPortHandlerList)
{
/*PRQA S 0314 12*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Cast to void is intended as to allow generic port handling*/
/*                          | Provide port                               | Require Port (for Sig Header)                   | Relevant Components (for SigState)     | Version Number              | Measfreeze address (0:No freeze)| Size (for Meas Freeze)                | PortHandlerList |*/
  ACDC_v_SetupProPortHandler((void *const)pProvidePorts->pErrorOut       , (void const *const) pRequirePorts->pEmGenObjList, (ACDC_SUB_COMP_ESPM)                   , ACDC_ERROR_OUT_INTFVER      , 0                               , sizeof(ACDCErrorOutProPort_t         ), pPortHandlerList);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  ACDC_v_SetupProPortHandler((void *const)pProvidePorts->pSenCompState   , (void const *const) pRequirePorts->pEmGenObjList, (ACDC_SUB_COMP_NONE)                   , COMP_STATE_INTFVER          , FCT_MEAS_ID_SEN_EBA_COMP_STATE  , sizeof(AlgoCompState_t               ), pPortHandlerList);
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  ACDC_v_SetupProPortHandler((void *const)pProvidePorts->pHypotheses     , (void const *const) pRequirePorts->pEmGenObjList, (ACDC_SUB_COMP_CD + ACDC_SUB_COMP_ESPM), FCT_HYPOTHESIS_INTFVER      , FCT_MEAS_ID_SEN_HYPO_OUT        , sizeof(HypothesisIntf_t              ), pPortHandlerList);
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
  ACDC_v_SetupProPortHandler((void *const)pProvidePorts->pCDCustomOutput , (void const *const) pRequirePorts->pEmGenObjList, (ACDC_SUB_COMP_CD)                     , FCT_CD_OUTPUT_CUSTOM_INTFVER, FCT_MEAS_ID_CD_CUSTOM_OUTPUT    , sizeof(FCTCDOutputCustom_t           ), pPortHandlerList);
#endif
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_SetupReqPortHander                                                                    */ /*!

  @brief                Fills a handler for a require port

  @description          Copies the given arguments to a port handler. Afterwards increases the number of req port handlers.

  @return               void

  @param[in]            pReqPort : Void pointer to the require port
  @param[in]            uInfluencedSubcomponents : Bitfield indicating which subcomponents are affected by the ReqPort
  @param[in]            bSignalContainsGenericPortData : Flag indicating if the require port corresponds to the ACDCGenericPortData_t.
  @param[in,out]        pSyncRefSignalHeader : Signal header of the sync ref structure that shall be filled by the signal header of the ReqPort.
  @param[in,out]        pPortHandlerList : Pointer to the port handler list.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_SETUPREQPORTHANDER_001

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void ACDC_v_SetupReqPortHander(void                  const *const pReqPort,
                                      ACDCSubCompIndices_t  const        uInfluencedSubcomponents,
                                      boolean               const        bSignalContainsGenericPortData,
                                      SignalHeader_t              *const pSyncRefSignalHeader,
                                      ACDCPortHandlerList_t       *const pPortHandlerList)
{
  ACDCReqPortHandler_t  * pCurrReqHandler  = &(pPortHandlerList->ReqPortHandler[pPortHandlerList->uNofReqPorts]);

  pCurrReqHandler->pGenericReqPortData     = (bSignalContainsGenericPortData == b_TRUE) ? ((ACDCGenericPortData_t const* const)pReqPort) : (NULL);
  pCurrReqHandler->pReqSignalHeaderSyncRef = pSyncRefSignalHeader;
  pCurrReqHandler->pReqPort                = pReqPort;
  pCurrReqHandler->InfluencedSubComponents = uInfluencedSubcomponents;

  pPortHandlerList->uNofReqPorts++;
}


/*************************************************************************************************************************
  Functionname:         ACDC_v_SetupReqPortHandlers                                                                  */ /*!

  @brief                Sets up the port handlers for all require ports.

  @description          Sets up the handlers of all require ports by executing the function @ref ACDC_v_SetupReqPortHander
                        to add the following information to the handler:
                        - Pointer to the SyncRef structure that corresponds to the require port.
                        - Bitfield of all subcomponents that are influenced by the require port.
                        .
                        More information regarding the Port Handler concept can be found here: @ref ACDC_v_ProcessPorts.
                        @startuml ACDC_v_SetupReqPortHandlers_activity.png
                          start
                          partition "Execute for each require port" {
                            #Orange:Fill require port handler:
                            <b>ACDC_v_SetupReqPortHander</b> >
                          }
                          stop
                        @enduml

  @return               void

  @param[in]            pRequirePorts    : Pointer to a structure containing all require port pointers.
  @param[in,out]        pPortHandlerList : Pointer to a list with all port handlers.

  @glob_in              @ref ACDC_p_ModSyncRef\n
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_EM_FCT_CYCLEMODE \n
                        @ref FCT_CFG_BSW_ALGO_PARAMS \n
                        @ref FCT_CFG_COLLISION_DETECTION \n
                        @ref FCT_CFG_ALIGNMENT_MONITORING_INPUT \n
                        @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST \n
                        @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST \n
                        @ref FCT_USE_EM_CUSTOM_OBJECT_LIST \n
                        @ref FCT_CFG_SHORT_RANGE_FUNCTIONS \n
                        @ref FCT_CFG_USE_BASECTRLDATA
  @c_switch_full        @ref ACDC_CFG_FRAME

  @pre                  Assure that pRequirePorts != NULL
  @post                 Require port information filled in port handler 

  @remark               Make sure that the GenericPortData flag is only set for ports that have a 
                        Version Number and Signal header as their first structure elements!!

  @InOutCorrelation     see description

  @todo                 Review the Influenced Subcomponents. Check if all ReqPorts set their Signal state correctly 
                        (currently pSenCtrlData, pEmFusionObjList and pSLATE_CD_Data do not)

  @testmethod           @ref TEST_ACDC_V_SETUPREQPORTHANDLERS_001

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void ACDC_v_SetupReqPortHandlers (     reqACDCPrtList_t const * const pRequirePorts,
                                         ACDCPortHandlerList_t       * const pPortHandlerList)
{
  ACDCSyncRef_t * const pSyncRef = ACDC_p_ModSyncRef();
/*PRQA S 0314 40*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Cast to void is intended as to allow generic port handling*/
  /*                       | Require Port                                       | Influenced Subcomponents                                   | GenericPortData? | Pointer to SyncRef               | Port handler List|*/
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEgoDynRaw        , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD + ACDC_SUB_COMP_ESPM), b_TRUE             , &(pSyncRef->EgoDynRaw        ), pPortHandlerList);
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEgoStaticData    , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD + ACDC_SUB_COMP_ESPM), b_FALSE            , &(pSyncRef->EgoStaticData    ), pPortHandlerList);
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEmGenObjList     , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD                     ), b_TRUE             , &(pSyncRef->EmGenObjList     ), pPortHandlerList);


#if (FCT_CFG_USE_BASECTRLDATA)
  ACDC_v_SetupReqPortHander((void const*const)pRequirePorts->pSenCtrlData       , (ACDC_SUB_COMP_ALL                                        ), b_TRUE             , &(pSyncRef->SenCtrlData      ), pPortHandlerList);
#else
  /* The signal header of the sen ctrl data is currently not filled correctly in Radar, therefore the Signal header shall not be checked => set GenericPortData to false */
  ACDC_v_SetupReqPortHander((void const*const)pRequirePorts->pSenCtrlData       , (ACDC_SUB_COMP_ALL                                        ), FALSE            , &(pSyncRef->SenCtrlData      ), pPortHandlerList);
#endif

#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEgoDynObjSync    , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD + ACDC_SUB_COMP_ESPM), b_TRUE             , &(pSyncRef->EgoDynObjSync    ), pPortHandlerList);
#endif
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEmCustObjList    , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD                     ), TRUE             , &(pSyncRef->EmCustObjList    ), pPortHandlerList);
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEmARSObjList     , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD                     ), TRUE             , &(pSyncRef->EmARSObjList     ), pPortHandlerList);
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEmCamObjList     , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD                     ), b_TRUE             , &(pSyncRef->EmCamObjList     ), pPortHandlerList);
#endif
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pAlignmentMonInput, (                                       ACDC_SUB_COMP_ESPM), TRUE             , &(pSyncRef->AlignmentMonInput), pPortHandlerList);
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEmFusionObjList  , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD                     ), FALSE            , &(pSyncRef->EmFusionObjList  ), pPortHandlerList);
#endif
#if ((FCT_CFG_COLLISION_DETECTION) && (FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pSLATE_CD_Data    , (                    ACDC_SUB_COMP_CD                     ), b_FALSE            , &(pSyncRef->SLATE_CD_Data    ), pPortHandlerList);
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pBswAlgoParameters, (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD + ACDC_SUB_COMP_ESPM), FALSE            , &(pSyncRef->BswAlgoParameters), pPortHandlerList);
#endif
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  ACDC_v_SetupReqPortHander((void const*const) pRequirePorts->pEmFctCycleMode   , (ACDC_SUB_COMP_AIP + ACDC_SUB_COMP_CD + ACDC_SUB_COMP_ESPM), FALSE            , &(pSyncRef->EmFctCycleMode   ), pPortHandlerList);
#endif

}


#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/*************************************************************************************************************************
  Functionname:         ACDC_b_CheckServiceFunctions                                                                 */ /*!

  @brief                Checks the Service function structure for NULL pointers

  @description          Checks if the pointer to the service function structure is valid. If this is the case,
                        the Pointers inside of the structure are checked.
                        @startuml ACDC_b_CheckServiceFunctions_activity.png
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

  @c_switch_part        @ref FCT_CFG_USE_DEM \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
  @c_switch_full        @ref ACDC_CFG_FRAME \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n

  @pre                  Assure that pServiceFuncts != NULL
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_B_CHECKSERVICEFUNCTIONS_001\n          
                        @ref TEST_ACDC_B_CHECKSERVICEFUNCTIONS_002\n
                        @ref TEST_ACDC_B_CHECKSERVICEFUNCTIONS_003

  @traceability         Design Decision

  @todo                 think about handling the service function ports with a handler similar to the require ports

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static boolean ACDC_b_CheckServiceFunctions(AS_t_ServiceFuncts const * const pServiceFuncts)
{
  boolean bError = b_FALSE;

  bError = (bError)||(boolean)(pServiceFuncts->pfMeasFreeze == NULL);
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
  bError = (bError) ||(boolean)(pServiceFuncts->pfMeasStartFuncCycle == NULL);
#endif
#if (FCT_CFG_RTA_PROFILING)
  bError = (bError) ||(boolean)(pServiceFuncts->pfRTAAlgoServiceAddEvent == NULL);
#endif
#if (FCT_CFG_USE_DEM)
  bError = (bError) ||(boolean)(pServiceFuncts->pfDem_SetEventStatus == NULL);
#endif

  ACDC_ASSERT(bError == b_FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */

  return bError;
}
#endif /* for if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) */

/*************************************************************************************************************************
  Functionname:         ACDC_b_SetupPorts                                                                            */ /*!

  @brief                Uses the port handler structure to set up require and provide ports as soon as related structures 
                        at the beginning of each cycle.

  @description          This function loops through the previously filled PortHandler structure. It checks and 
                        sets up all Ports. The following actions are executed for valid require ports:
                        - Copy port signal header to the SyncRef structure for simulation purposes.
                        - Apply the signal state to the influenced subcomponents
                        - Check if port has been updated within the required time
                        .
                        Most of the provide port handling has to be done after the call of the subcomponents 
                        (see @ref ACDC_v_FillProPortHeaders). Only one action has to executed before:
                        - Set the content of all provide ports to 0.
                        .
                        If one of the given ports is a NULL pointer the function returns an error.
                        @startuml ACDC_b_SetupPorts_activity.png
                        start
                          if(Have all require and provide ports\nbeen written into the Handler List?) Then (Yes)
                            :1}
                          else(No)
                            :2}
                            #Yellow:Raise **Error flag** and display warning:
                            <b>ACDC_ASSERT</b> |
                          endif
                          partition "Execute for all Require Ports\nin the ACDC_PortHandlerList"{
                            if(Require Port is NULL pointer?) then (No)
                              if(SignalHeader is Null Pointer?) then (Yes)
                                :3}
                                #Orange:Reset corresponding SyncRef structure:
                                <b>ACDC_v_SetSignalHeaderError</b> >
                                note left
                                  Some Ports do not have a Signal header. 
                                  If this is the case, the signal header 
                                  pointer in the Port Handler is set 
                                  explicitly to NULL. This is no error case!
                                end note
                              else(No)
                                partition #LightBlue **ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK** {
                                #Orange:Port Update check: Assure that the port has 
                                been updated withing the required time:
                                <b>ACDC_b_CheckPortUpdate</b> >
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
                                <b>ACDC_v_SetSubComponentStates</b> >

                                :Copy Port Signal Header to 
                                corresponding SyncRef Structure;
                              endif
                            else(Yes)
                            :6}
                              #Orange:Reset corresponding SyncRef structure:
                              <b>ACDC_v_SetSignalHeaderError</b> >
                              #Orange:Set the states of all influenced 
                              subcomponents to error:
                              <b>ACDC_v_SetSubComponentStates</b> >
                              #Yellow:Raise **Error flag** and display warning:
                              <b>ACDC_ASSERT</b> |
                            endif
                          }
                          partition "Execute for all Provide Ports\nin the ACDC_PortHandlerList"{
                            note left
                              Further Provide port handling has to be done after the 
                              call of the subcomponents. (see **ACDC_v_FillProPortHeaders**)
                            end note
                            if(Provide Port is NULL pointer?) then (No)
                              :7}
                              :Initialize the entire structure to 0;
                            else(Yes)
                              :8}
                              #Yellow:Raise **Error flag** and display warning:
                              <b>ACDC_ASSERT</b> |
                            endif
                          }
                        stop
                        @enduml

  @return               boolean bError : Error flag, True if error was detected.

  @param[in,out]        pPortHandlerList : List containing Port handlers for all require and provide ports.

  @glob_in              None
  @glob_out             @ref ACDC_v_SetSubComponentStates

  @c_switch_part        @ref ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK\n
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  ACDC_PortHandlerList has been filled by calls to the functions 
                        @ref ACDC_v_SetupReqPortHandlers and @ref ACDC_v_SetupProPortHandlers
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_B_SETUPPORTS_001 \n
                        @ref TEST_ACDC_B_SETUPPORTS_002 \n
						@ref TEST_ACDC_B_SETUPPORTS_003

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2017-11-22, reviewer: Andreas Danner, reason: pPortHandlerList is modified by means of pCurrPort*/
static boolean ACDC_b_SetupPorts(ACDCPortHandlerList_t * const pPortHandlerList)
{
  uint32                 uPortNo         = 0u;
  /*PRQA S 3494,3493,4548 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
  uint8                  uNofReqPorts    = MIN(pPortHandlerList->uNofReqPorts,ACDC_NOF_REQ_PORTS);
  uint8                  uNofProPorts    = MIN(pPortHandlerList->uNofProPorts,ACDC_NOF_PRO_PORTS);
  boolean                bError          = b_FALSE;
  ACDCReqPortHandler_t * pCurrReqPort;
  ACDCProPortHandler_t * pCurrProPort;

  /*Check if number of ports matches number of activated ports. Can help to detect unchecked ports.
  This is done in two separate "ifs" to distinguish between the asserts for Pro and Req Ports*/
  if(pPortHandlerList->uNofProPorts!=ACDC_NOF_PRO_PORTS)
  {
    ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    bError = b_TRUE;
  }
  /*PRQA S 3494,3493,4548 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
  if(pPortHandlerList->uNofReqPorts!=ACDC_NOF_REQ_PORTS)
  {
    ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    bError = b_TRUE;
  }

  /*Set Up Require Ports*/
  for (uPortNo = 0; uPortNo < uNofReqPorts; ++uPortNo)
  {
    pCurrReqPort = &(pPortHandlerList->ReqPortHandler[uPortNo]);
    if(pCurrReqPort->pReqPort!=NULL)
    {
      /*Check signal header*/
      if(pCurrReqPort->pGenericReqPortData != NULL)
      {
        ACDCCompState_t InitialCompState;
        
        /* ----- Check signal header state ----- */
        switch(pCurrReqPort->pGenericReqPortData->sSigHeader.eSigStatus)
        {
          case AL_SIG_STATE_INIT    : 
            InitialCompState = COMP_STATE_NOT_INITIALIZED; 
            break;
          case AL_SIG_STATE_OK      : 
            InitialCompState = COMP_STATE_RUNNING;
            break;
          case AL_SIG_STATE_INVALID : 
            InitialCompState = COMP_STATE_TEMPORARY_ERROR; 
            break;
          default:
            InitialCompState = COMP_STATE_TEMPORARY_ERROR; 
            break;
        }

        /* ----- Check timestamp for consistency ----- */
#if (ACDC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK)
        if(    (ACDC_p_GetFrameData()->eOpMode == FCT_MOD_RUNNING)
            && (TRUE == ACDC_b_CheckPortUpdate(&(pCurrReqPort->pGenericReqPortData->sSigHeader.uiTimeStamp), 
                                               &(pCurrReqPort->MeasCycleMonitor), 
                                               FCT_SEN_CYCLE_TIME, 
                                               FCT_INPUT_ACCEPTABLE_DROPS)))
        {
          InitialCompState = COMP_STATE_TEMPORARY_ERROR;
        }
#endif

        /* ----- Set the determined state as initial state for all influenced subcomponents ----- */
        ACDC_v_SetSubComponentStates(pCurrReqPort->InfluencedSubComponents,InitialCompState);
        
        /* ----- Copy the signal header to the sync ref structure ----- */
        *(pCurrReqPort->pReqSignalHeaderSyncRef)  = pCurrReqPort->pGenericReqPortData->sSigHeader;
      }
      else
      { /* Pointer is set to 0 if a port does not have a signal header. This is not an error case! */
        ACDC_v_SetSignalHeaderError(pCurrReqPort->pReqSignalHeaderSyncRef);
      }
    }
    else
    {
      ACDC_v_SetSubComponentStates(pCurrReqPort->InfluencedSubComponents, COMP_STATE_TEMPORARY_ERROR);
      ACDC_v_SetSignalHeaderError(pCurrReqPort->pReqSignalHeaderSyncRef);
      bError = b_TRUE;
      ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    }
  }
  
  /*Set Up Provide Ports*/
  for (uPortNo = 0; uPortNo < uNofProPorts; ++uPortNo)
  {
    pCurrProPort = &(pPortHandlerList->ProPortHandler[uPortNo]);
    if(pCurrProPort->pProPort!=NULL)
    {
      /* Initialize all provide port structures to 0 */
			/* PRQA S 2869 1 #Date:2020-06-03,Reviewer: Praveen Annareddy , Reason: uSize was updated with the current ProPort_structure size during the initalization, So size parameter of the function call can not be zero.*/
      (void)memset(pCurrProPort->pProPort, 0, (size_t)pCurrProPort->uSize);
    }
    else
    {
      bError = b_TRUE;
      ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    }
  }

  return bError;
}/* PRQA S 7002,7004 # Date:2020-06-03, Reviewer: Praveen Annareddy , Reason: suppressing cyclomatic complexity for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         ACDC_v_InitPortHandlerList                                                                   */ /*!

  @brief                Resets all elements in the Port handler list.

  @description          Sets all elements of the port handler list to 0. Keeps the information of 
                        the MeasCycleMonitoring. \n
                        This function should be called each cycle at the beginning of the PortProcessing.
                        @startuml ACDC_v_InitPortHandlerList_activity.png
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
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_INITPORTHANDLERLIST_001

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void ACDC_v_InitPortHandlerList(ACDCPortHandlerList_t   * const pPortHandlerList)
{
  uint8 uPortNo;
  pPortHandlerList->uNofProPorts = 0u;
  pPortHandlerList->uNofReqPorts = 0u;

  /*PRQA S 3494,3493,4548 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
  for (uPortNo = 0; uPortNo < ACDC_NOF_REQ_PORTS; uPortNo++)
  {
    pPortHandlerList->ReqPortHandler[uPortNo].pReqPort                 = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pGenericReqPortData      = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqSignalHeaderSyncRef  = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].InfluencedSubComponents  = ACDC_SUB_COMP_NONE;

    /* MeasCycle data has to be kept over the cycles to make a monitoring of the timestamps possible (see function @ref ACDC_b_CheckPortUpdate). 
       There is no need to reset it in the init case, as this check is only relevant if ACDC is in Running Mode (see @ref ACDC_b_SetupPorts).
       As the component has to be called in init at least once before it switches to run, the Meas cycle data will be updated during this init call 
       and will be correct when ACDC is called in Running for the first time.*/

  }

  for (uPortNo = 0; uPortNo < ACDC_NOF_PRO_PORTS; uPortNo++)
  {
    pPortHandlerList->ProPortHandler[uPortNo].pProPort                 = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pGenericProPortData      = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pGenericReqPortData      = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].uInfluencingSubComponents= ACDC_SUB_COMP_NONE;
    pPortHandlerList->ProPortHandler[uPortNo].uMeasFreezeAddress       = 0u;
    pPortHandlerList->ProPortHandler[uPortNo].uProNewVersionNumber     = 0u;
    pPortHandlerList->ProPortHandler[uPortNo].uSize                    = 0u;
  }
}


/*************************************************************************************************************************
  Functionname:         ACDC_v_PortSpecificHandling                                                                  */ /*!

  @brief                Handles special logic that shall only be executed for selected ports.

  @description          For certain ports special checks shall be executed. Therefore this function is used.
                        As at this point in the cycle it is not clear if the ports are valid, all port checks \n
                        have to be done again for each port here. Also the switches that de-/activate a port have 
                        to be repeated here.\n
                        Currently the following ports are handled different from the generic port handling:
                        - **SenCtrlData:** \n
                          The SenCtrlData contains the information about the current OpMode in which ACDC shall be called, 
                          therefore it is the first port that has to be handled. The OpMode is used to initialize @ref the ACDC_p_GetFrameData \n
                          which contains the component states of ACDC and all of its subcomponents.\n
                          Additionally the signal headers of the structures @ref ACDC_p_ModSyncRef and 
                          @ref ACDC_p_ModWorkingData are filled with the signal header of the SenCtrlData.
                        - **EgoDynRaw:** \n
                          The VDY Signal EgoDynRaw has a special structure, that indicates the current quality 
                          of its content. This quality shall be checked before the port is used.\n
                          Therefore a counter uiVDYSigErrorCnt (part of @ref ACDC_Frame) is increased if a state is found to be invalid.
                          If the counter exceeds a given limit (@ref ACDC_MAX_VDY_SIG_ERRORS) the State of the CD subcomponent \n
                          is set to COMP_STATE_TEMPORARY_ERROR. The consequence is a call of CD in State @ref COMP_STATE_TEMPORARY_ERROR
                          and an invalidation of all output ports that are influence by CD.
                        .
                        <b>ATTENTION:</b> Try to keep this function as small as possible. The ports should be handled 
                        as generic as possible to simplify maintainability.
                        @startuml ACDC_v_PortSpecificHandling_activity.png
                        start
                          partition **REQ:SenCtrlData** {
                          if(Pointer to SenControl Data is valid?) then (Yes)
                            note right:This should be done at the very beginning to\nassure that the ACDC Frame is initialized.
                            :1}                            
                              partition #LightBlue **FCT_CFG_USE_BASECTRLDATA** {
                              if(Base OpMode from SenControl Data port is Running?) then (Yes)
                              :2} 
                                :Set current OpMode to Running;
                              else (No)
                              :3}
                                :Set current OpMode to Init;
                              endif
                            }
                            partition #LightBlue **!FCT_CFG_USE_BASECTRLDATA** {
                            : Set current OpMode to SenControl Data port OpMode >
                            }
                            #Orange:Initialize the ACDCFrame data accordingly with current OpMode:
                            <b>ACDC_v_InitFrameData</b> >
                            #Orange:Set the signal header of the SyncRef structure to 
                            the signal header of the SenControl Data:
                            <b>ACDC_v_SetSignalHeader</b> >
                            partition #LightBlue **USE_ACDCWRAPPER_INTER** {
                            #Orange: Set memory version number
                            <b>ACDC_p_ModWorkingData</b> >
                            #Orange: Set the signal header with InterCycle data
                            <b>ACDC_v_SetSignalHeader</b> >
                            }
                            partition #LightBlue **USE_ACDCWRAPPER_INTERMEAS** {
                            #Orange: Set memory version number
                            <b>ACDC_p_ModWorkingData</b> >
                            #Orange: Set the signal header with InterCycleMeas data
                            <b>ACDC_v_SetSignalHeader</b> >
                            }
                            partition #LightBlue **USE_ACDCWRAPPER_INTRA** {
                            #Orange: Set the signal header with IntraCycle data
                            <b>ACDC_v_SetSignalHeader</b> >
                            }
                            partition #LightBlue **USE_ACDCWRAPPER_INTRAMEAS** {
                            #Orange: Set the signal header with IntraCycleMeas data
                            <b>ACDC_v_SetSignalHeader</b> >
                            }
                            partition #LightBlue **USE_ACDCWRAPPER_STACK** {
                            #Orange: Set the signal header with Stack data
                            <b>ACDC_v_SetSignalHeader</b> >
                            }
                            partition #LightBlue **USE_ACDCWRAPPER_SIMU** {
                            #Orange: Set the signal header with Simulation data
                            <b>ACDC_v_SetSignalHeader</b> >
                            }
                          else(No)
                            :4}
                            #Orange:Initialize the ACDC Frame with FCT_MOD_SHUTDOWN:
                            <b>ACDC_v_InitFrameData</b> >
                            #Orange:Set the signal header of the SyncRef structure to error:
                            <b>ACDC_v_SetSignalHeaderError</b> >
                          endif
                          }
                          partition **REQ:EgoDynRaw** {
                          if(Pointer to EgoDynRaw is valid?) then (Yes)
                            if(Check of signal status of ego speed, acceleration and yaw rate passed?) then (Yes)
                              :5}
                              :Reset VDY signal error counter;
                            else(No)
                              :6}
                              :Increase VDY signal error counter;
                              note left: Limited to maximum value
                              if(VDY signal error counter is at max value?) then (Yes)
                              :7}
                              :Set CD component state to temporary error;
                              else(No)
                              :8}
                              endif
                            endif
                          else(No)
                            :9}
                          endif
                          }
                          stop
                        @enduml

  @return               void

  @param[in]            pRequirePorts : Pointer to all require ports.

  @glob_in              @ref ACDC_p_ModWorkingData \n
                        @ref ACDC_u_GetIOStateEgoSpeedX \n
                        @ref ACDC_u_GetIOStateEgoAccelX \n
                        @ref ACDC_u_GetIOStateEgoYawRate
                        @ref ACDC_p_GetFrameData \n
  @glob_out             @ref ACDC_p_ModSyncRef \n
                        @ref ACDC_p_ModFrameData \n
                        @ref ACDC_p_ModWorkingData

  @c_switch_part        @ref FCT_CFG_USE_BASECTRLDATA \n
                        @ref USE_ACDCWRAPPER_INTER \n
                        @ref USE_ACDCWRAPPER_INTERMEAS \n
                        @ref USE_ACDCWRAPPER_INTRA \n
                        @ref USE_ACDCWRAPPER_INTRAMEAS \n
                        @ref USE_ACDCWRAPPER_STACK \n
                        @ref USE_ACDCWRAPPER_SIMU \n
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  Assure that pointer to pRequirePorts is != NULL
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_PORTSPECIFICHANDLING_001 \n
                        @ref TEST_ACDC_V_PORTSPECIFICHANDLING_002 \n
						@ref TEST_ACDC_V_PORTSPECIFICHANDLING_003 \n
						@ref TEST_ACDC_V_PORTSPECIFICHANDLING_004

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void ACDC_v_PortSpecificHandling(reqACDCPrtList_t const * const pRequirePorts)
{
/* ======== pRequirePorts ==========*/

  /* ---------- pSenCtrlData ---------- */

  /* The sen ctrl port handling has to be executed first to assure that the OpMode is 
     correctly transferred into the (Sub-) component states */
  if(pRequirePorts->pSenCtrlData!= NULL)
  {
    /* Get the current requested OpMode from the SenCtrlData Port*/
#if (FCT_CFG_USE_BASECTRLDATA)
      FCT_OP_MODE_t const eOpMode = (pRequirePorts->pSenCtrlData->eOpMode == BASE_OM_RUN)? FCT_MOD_RUNNING : FCT_MOD_INIT;
#else
    /*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
      FCT_OP_MODE_t const eOpMode = pRequirePorts->pSenCtrlData->OpMode;
#endif
    
    /* Setup the ACDC frame according to the requested OpMode from the SenCtrlData Port. In case of pointer errors: set shutdown*/
    ACDC_v_InitFrameData(eOpMode);
    ACDC_v_SetSignalHeader(&(ACDC_p_ModSyncRef()->sSigHeader),                                            &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);

    /* Set the header values for the internal data also */
#if (USE_ACDCWRAPPER_INTER)
    ACDC_p_ModWorkingData()->pInterCycle->uVersion     = ACDC_INTER_CYCLE_MEMORY_VERSION;
    ACDC_v_SetSignalHeader(&(ACDC_p_ModWorkingData()->pInterCycle->sSigHeader),                   &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);
#endif
#if (USE_ACDCWRAPPER_INTERMEAS)
    ACDC_p_ModWorkingData()->pInterCycleMeas->uVersion = ACDC_INTER_CYCLEMEAS_MEMORY_VERSION;
    ACDC_v_SetSignalHeader(&(ACDC_p_ModWorkingData()->pInterCycleMeas->sSigHeader),               &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);
#endif
#if (USE_ACDCWRAPPER_INTRA)
    ACDC_v_SetSignalHeader(&(ACDC_p_ModWorkingData()->pIntraCycle->sSigHeader),                   &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);
#endif
#if (USE_ACDCWRAPPER_INTRAMEAS)
    ACDC_v_SetSignalHeader(&(ACDC_p_ModWorkingData()->pIntraCycleMeas->sSigHeader),               &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);
#endif
#if (USE_ACDCWRAPPER_STACK)
    ACDC_v_SetSignalHeader(&(ACDC_p_ModWorkingData()->pStackData->sSigHeader),                    &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);
#endif
#ifdef ACDC_SIMU
#if (USE_ACDCWRAPPER_SIMU)
    ACDC_v_SetSignalHeader(&(ACDC_p_ModWorkingData()->pSimuData->sSigHeader),                     &(pRequirePorts->pEmGenObjList->sSigHeader),pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus);
#endif
#endif


  }
  else
  {
    ACDC_v_InitFrameData(FCT_MOD_SHUTDOWN);
    ACDC_v_SetSignalHeaderError(&(ACDC_p_ModSyncRef()->sSigHeader));
  }

  /* ---------- pEgoDynRaw ---------- */

  if(pRequirePorts->pEgoDynRaw!= NULL)
  {
    /*Supervise state of the VDY velocity, acceleration and YawRate information*/
    if(    (ACDC_u_GetIOStateEgoSpeedX()  != VDY_IO_STATE_VALID)
        || (ACDC_u_GetIOStateEgoAccelX()  != VDY_IO_STATE_VALID)
        || (ACDC_u_GetIOStateEgoYawRate() != VDY_IO_STATE_VALID) )
    {
      
      ACDC_p_ModFrameData()->uiVDYSigErrorCnt = MIN((ACDC_p_GetFrameData()->uiVDYSigErrorCnt + 1u),(ACDC_MAX_VDY_SIG_ERRORS + 1u));

      if (ACDC_p_GetFrameData()->uiVDYSigErrorCnt > ACDC_MAX_VDY_SIG_ERRORS)
      {
        ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_CD, COMP_STATE_TEMPORARY_ERROR);
      }
    }
    else
    {
      ACDC_p_ModFrameData()->uiVDYSigErrorCnt = 0u;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_ProcessPorts                                                                          */ /*!

  @brief                Processes require ports, provide ports and service functions to enable an error free 
                        operation of the ACDC component. 

  @description          Executes pointer and signal state checks and sets up all internal data that is 
                        related to the ports. This is done by means of Port Handlers. Each require and \n
                        provide port has its own handler (see @ref ACDC_PortHandlerList), that is filled in the 
                        functions @ref ACDC_v_SetupProPortHandlers or @ref ACDC_v_SetupProPortHandlers. \n
                        The handlers contain all information that is necessary to set up a port. The advantage 
                        of this procedure is the generic handling of all ports: The Possibility to fill the \n
                        handlers at one point in the code eliminates the eventuality of missing a port in a 
                        later processing step. The handlers are processed in two functions:
                        - After the handlers where filled, the function @ref ACDC_b_SetupPorts is called. It checks the 
                          pointers and signal state.
                        - The function @ref ACDC_v_FillProPortHeaders is called AFTER the call of the subcomponents. It fills 
                          the provide port signal headers according to the calculation results.
                        .
                        @startuml ACDC_v_ProcessPorts_activity.png
                        start
                          partition "Filling of port handlers" {
                          #Orange:Initialize the port handlers:
                          <b>ACDC_v_InitPortHandlerList</b> >
                          #Orange:Set up the require port handlers:
                          <b>ACDC_v_SetupReqPortHandlers</b> >
                          #Orange:Set up the provide port handlers:
                          <b>ACDC_v_SetupProPortHandlers</b> >
                          }
                          partition "Checking of ports" {
                          #Orange:Execute port specific handling for certain ports:
                          <b>ACDC_v_PortSpecificHandling</b> >
                          note left:Has to be called before ACDC_b_SetupPorts\nas ACDC_p_GetFrameData is filled here
                          partition #LightBlue **FCT_CFG_USE_SERVICE_POINTER_FUNCTS** {
                          #Orange:Check Service function pointers for NULL pointer:
                          <b>ACDC_b_CheckServiceFunctions</b> >
                          }
                          #Orange:Check and set up all require and provide 
                          ports by using the port handlers
                          <b>ACDC_b_SetupPorts</b> >
                          }
                          partition "Error Routine" {
                          if(**Error flag** was set by one\nof the function calls?) then (Yes)
                            :1}
partition #LightBlue **FCT_CFG_USE_DEM** { 
                            #Orange:Set DEM event **Failed**: <b>ACDC_v_SetDem</b> > 
}
partition #LightBlue **FCT_CFG_USE_ALGOCOMPSTATE** {
                            #Orange:Write **Critical error** to error buffer:
                            <b>ACDC_v_SetAlgoErrorBuffer</b> >
}
                            #Orange:Switch to ACDC Error Mode:
                            <b>ACDC_v_SignalErrorShutdown</b> >
                          else(No)
                            :2}
partition #LightBlue **FCT_CFG_USE_DEM** { 
                            #Orange:Set DEM event **Passed**: <b>ACDC_v_SetDem</b> >
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

  @c_switch_part        @ref FCT_CFG_USE_ALGOCOMPSTATE\n
                        @ref FCT_CFG_USE_DEM\n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  Assure that pointers pRequirePorts, pProvidePorts, pServiceFuncts and pErrorBuffer are != NULL.
  @post                 @ref ACDC_v_FillProPortHeaders has to be called after the call of the subcomponents.

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_PROCESSPORTS_001 \n
                        @ref TEST_ACDC_V_PROCESSPORTS_002

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
extern void ACDC_v_ProcessPorts(   reqACDCPrtList_t const * const pRequirePorts,
                                  provACDCPrtList_t       * const pProvidePorts,
                                  ACDCPortHandlerList_t   * const pPortHandlerList
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                               , AS_t_ServiceFuncts const * const pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                              , GenAlgoQualifiers_t       * const pErrorBuffer
#endif
  )
{
  boolean bError = b_FALSE;


  /* ---------- Filling of Port Handlers ---------- */

  /* Initialize the port handlers */
  ACDC_v_InitPortHandlerList(pPortHandlerList);

  /* Set up Require Port handlers */
  ACDC_v_SetupReqPortHandlers(pRequirePorts, pPortHandlerList);

  /* Set up Provide Ports handlers */
  ACDC_v_SetupProPortHandlers(pProvidePorts, pRequirePorts, pPortHandlerList);


  /* ---------- Checking of Ports ---------- */

  /* The port specific handling treats all port related actions that can not be executed by means of the port handler.
     It has to be called before ACDC_b_SetupPorts to assure that the Frame and the (sub-)component states are initialized */
  ACDC_v_PortSpecificHandling(pRequirePorts);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Evaluate Service Function pointers*/
/* PRQA S 3415 1# Date:2020-06-03, Reviewer: Praveen Annareddy , Reason: defensive programming with parameters and No side effects*/
  bError = (bError)||ACDC_b_CheckServiceFunctions(pServiceFuncts);
#endif

  /* Check and set up all ports by evaluating the Port handlers */
  /*PRQA S 2986,3415 1*//*date: 2019-05-19 Reviewer: C. Schnurr: redundancy accepted due to feature configuration.*/
  bError = (bError) || (ACDC_b_SetupPorts(pPortHandlerList));


  /* ---------- Error Routine ---------- */

  if (bError == b_TRUE)
  {
    /* Some port pointer is NULL => DEM and shutdown */
    /* Validity of service pointer isn't clear here, anyway assign internal global alias*/
#if FCT_CFG_USE_DEM
    ACDC_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    ACDC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    ACDC_v_SignalErrorShutdown(b_FALSE);
  }
  else
  {
#if FCT_CFG_USE_DEM
    ACDC_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif

  }

}

/*************************************************************************************************************************
  Functionname:         ACDC_v_FillProPortHeaders                                                                    */ /*!

  @brief                Fills the provide port signal headers after the call to the subcomponents.

  @description          Fills the signal header of a provide port according to the signal header of a require port. \n
                        Fills the state of this signal header according to the worst component state of the influencing 
                        subcomponents. \n
                        Sets all signal states to invalid if an error was detected.
                        @startuml ACDC_v_FillProPortHeaders_activity.png
                        start
                          partition "Execute for all provide port handlers" {
                            if(Provide Port Pointer is valid?\nAND Pointer to the GenericProPortData is valid?) then (Yes)
                              :Write version number to the port;
                              if(Pointer to the related require\nport signal header is valid?) then (Yes)
                                :1}
                                #Orange:Get the worst comp state of all assigned subcomponents:
                                <b>ACDC_e_GetWorstSubComponentState</b> >
                                note left
                                  If no subcomponent is assigned (ACDC_SUB_COMP_NONE), 
                                  the Comp state COMP_STATE_SUCCESS is returned by the function. 
                                  To make this logic independent of the behavior of the 
                                  function ACDC_e_GetWorstSubComponentState, this condition 
                                  is checked here explicitly by using an if.
                                end note
                                
                                #Orange:Set the signal state of the provide port 
                                according to the worst comp state:
                                <b>ACDC_v_SetSignalHeader</b> >

                              else(No)
                                :2}
                                #Orange:Set Signal header to default and
                                Signal State to **INVALID**:
                                <b>ACDC_v_SetSignalHeaderError</b> >
                              endif
                            else(No)
                              :3}
                              #Yellow:Display warning:
                              <b>ACDC_ASSERT</b> |
                              note right
                                Assert is not necessary here, as it
                                would already have been triggered 
                                in ACDC_v_ProcessPorts. Nevertheless 
                                keep here to assure safety.
                              end note
                            endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in]            pPortHandlerList: Pointer to the port handler list

  @glob_in              @ref ACDC_e_GetWorstSubComponentState
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n

  @pre                  @ref ACDC_v_ProcessPorts has been called at the beginning of the cycle.
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ACDC_V_FILLPROPORTHEADERS_001 \n
                        @ref TEST_ACDC_V_FILLPROPORTHEADERS_002 \n
						@ref TEST_ACDC_V_FILLPROPORTHEADERS_003 \n
						@ref TEST_ACDC_V_FILLPROPORTHEADERS_004 \n
						@ref TEST_ACDC_V_FILLPROPORTHEADERS_005 \n
						@ref TEST_ACDC_V_FILLPROPORTHEADERS_006

  @traceability         Design Decision

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2018-08-29, reviewer: Danner Andreas, reason: pPortHandlerList is modified via pCurrPort*/
extern void ACDC_v_FillProPortHeaders(ACDCPortHandlerList_t * const pPortHandlerList)
{
  uint32 uPortNo = 0;

  for (uPortNo = 0; (uPortNo < pPortHandlerList->uNofProPorts); ++uPortNo)
  { 
    ACDCProPortHandler_t  * const pCurrPort = &(pPortHandlerList->ProPortHandler[uPortNo]);
    if (    (pCurrPort->pProPort            != NULL)
         && (pCurrPort->pGenericProPortData != NULL) )
    {
      /* If ProPort pointer is valid, fill the provide ports signal header */
      pCurrPort->pGenericProPortData->uiVersionNumber = pCurrPort->uProNewVersionNumber;
    
      if( pCurrPort->pGenericReqPortData != NULL )
      {
        AlgoSignalState_t NewSigState;
        ACDCCompState_t   eFusedCompState;
        
        if(pCurrPort->uInfluencingSubComponents == ACDC_SUB_COMP_NONE)
        {
          /* This case can only be reached if no SubComponent is contained in uInfluencingSubComponents. In that case the SigState is always OK
             Do this check explicitly here to be independent of the behavior of the function ACDC_e_GetWorstSubComponentState */
          eFusedCompState = COMP_STATE_SUCCESS;
        }
        else
        {
          eFusedCompState = ACDC_e_GetWorstSubComponentState(pCurrPort->uInfluencingSubComponents);
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
               ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
               break;
        }

        /*Fill with given ReqPort SigHeader if the ReqPort Signal was valid*/
        ACDC_v_SetSignalHeader(&(pCurrPort->pGenericProPortData->sSigHeader),
                               &(pCurrPort->pGenericReqPortData->sSigHeader),
                               NewSigState                    );
      }
      else
      {
        /* Fill with default if ReqPort Signal was invalid */
        ACDC_v_SetSignalHeaderError(&(pCurrPort->pGenericProPortData->sSigHeader));
      }
    }
    else
    {
      /* No assert necessary, is already set in previous step */
      /* Nothing can be done, pointer is invalid */
      ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    }
  }
}



///\}
#endif //ACDC_CFG_FRAME


