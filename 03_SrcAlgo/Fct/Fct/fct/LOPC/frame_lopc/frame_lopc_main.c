/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc_main.c

DESCRIPTION:               Main functions for Adaptive Cruise Control (ACC) LOPC module

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.38 $

LEGACY VERSION:            Revision: 2.4

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lopc_main Frame_lopc_main
@ingroup    lopc_base_frame
@brief      Main functions for LOPC componennt
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lopc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))

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
/*fct veh lopc and it's subcomponents initialization status*/
SET_MEMSEC_VAR(b_LopcIsInitialized)
boolean b_LopcIsInitialized = FALSE;            /*!<flag showing once completed algo cycle (!=shutdown).*/

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LopcInputCounters)
static Lopc_InputMeasCounter LopcInputCounters = {0};   /*!<aggregation struct that keeps update information for all input interfaces.*/
#endif

/*!< Static Memory for LOPC component containing Framedata and Syncrefs*/
SET_MEMSEC_VAR(LOPC_STATIC_MEMORY)
lopc_static_mem_t LOPC_STATIC_MEMORY;           

#if (FCT_CFG_ACT_CODE_VERSION)

/*! Declaration of pointers to LOPC input ports for access within this component - NEW */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  SET_MEMSEC_CONST(pt_LOPC_IN_CC_VSCP)
  const ACT_CC_VehicleSpeedCommandPort_t *pt_LOPC_IN_CC_VSCP;
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  SET_MEMSEC_CONST(pt_LOPC_IN_SLA_VSCP)
  const ACT_SLA_VehicleSpeedCommandPort_t *pt_LOPC_IN_SLA_VSCP;
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  SET_MEMSEC_CONST(pt_LOPC_IN_SLA_DSCP)
  const ACT_SLA_DistanceSpeedCommandPort_t *pt_LOPC_IN_SLA_DSCP;
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  SET_MEMSEC_CONST(pt_LOPC_IN_CP_DCCP)
  const ACT_CP_DistanceCurveCommandPort_t *pt_LOPC_IN_CP_DCCP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_CONST(pt_LOPC_IN_HP_TFCP)
  const TargetFollowCommandPort_t *pt_LOPC_IN_HP_TFCP;
#endif

  SET_MEMSEC_CONST(pt_LOPC_IN_LVCP)
  const ACT_LogicVehicleCommandPort_t *pt_LOPC_IN_LVCP;

/* Real existing DMC port */
  SET_MEMSEC_CONST(pt_LOPC_IN_EgoVehDynCtrl)
  const LongCtrlInput_t *pt_LOPC_IN_EgoVehDynCtrl;

/* Real existing VDY port */
  SET_MEMSEC_CONST(pt_LOPC_IN_EgoVehDynState)
  const VehDyn_t *pt_LOPC_IN_EgoVehDynState;


/*! Declaration of pointers to LOPC output ports for access within this component - NEW */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  SET_MEMSEC_VAR(pt_LOPC_OUT_CC_VSSP)
  ACT_CC_VehicleSpeedStatePort_t *pt_LOPC_OUT_CC_VSSP;
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  SET_MEMSEC_VAR(pt_LOPC_OUT_SLA_VSSP)
  ACT_SLA_VehicleSpeedStatePort_t *pt_LOPC_OUT_SLA_VSSP;
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(pt_LOPC_OUT_SLA_DSSP)
  ACT_SLA_DistanceSpeedStatePort_t *pt_LOPC_OUT_SLA_DSSP;
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(pt_LOPC_OUT_CP_DCSP)
  ACT_CP_DistanceCurveStatePort_t *pt_LOPC_OUT_CP_DCSP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_VAR(pt_LOPC_OUT_HP_TFSP)
  TargetFollowStatePort_t *pt_LOPC_OUT_HP_TFSP;
#endif

  SET_MEMSEC_VAR(pt_LOPC_OUT_LVSP)
  ACT_LogicVehicleStatePort_t *pt_LOPC_OUT_LVSP;

  SET_MEMSEC_VAR(pt_LOPC_OUT_EVCP)
  ACT_EgoVehicleCommandPort_t *pt_LOPC_OUT_EVCP;

#else /* Legacy code */

/* start of definition for local alias for external ports (shall be same same than provide and receive ports */
SET_MEMSEC_CONST(LOPC_pEgoDynRaw)
const VehDyn_t  * LOPC_pEgoDynRaw;                      /*!<internal pointer to external raw ego dynamics INPUT interface.*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(LOPC_pServiceFuncts)
const AS_t_ServiceFuncts * LOPC_pServiceFuncts;       /*!<internal pointer to external service functions interface.*/
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(LOPC_pCompState)
static AlgoCompState_t  * LOPC_pCompState;  /*!<internal pointer to external Algo Component State OUTPUT interface.*/
#endif

#if (FCT_VEH_CFG_VEH_SIG_INPUT)
SET_MEMSEC_CONST(LOPC_pVehSig)
const VehSig_t *              LOPC_pVehSig;             /*!<internal pointer to external VDY sensor signals INPUT. Pointer to raw vehicle signals.*/
#else
#error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
SET_MEMSEC_CONST(LOPC_pAccLever)
const AccLeverInput_t             * LOPC_pAccLever;
SET_MEMSEC_CONST(LOPC_pLongCtrlResp)
const LongCtrlInput_t             * LOPC_pLongCtrlResp;
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
SET_MEMSEC_CONST(LOPC_pAccDisplayObj)
const acc_object_t                * LOPC_pAccDisplayObj;
SET_MEMSEC_CONST(LOPC_pAccOutput)
const acc_output_data_t           * LOPC_pAccOutput;
SET_MEMSEC_VAR(LOPC_pFctVehLongOut)
FctVeh2SenInfo_t            * LOPC_pFctVehLongOut;
#endif
SET_MEMSEC_VAR(LOPC_pLongCtrlOutput)
LongCtrlOutput_t            * LOPC_pLongCtrlOutput;

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
SET_MEMSEC_CONST(LOPC_pAccOOIData)
const FCTSenAccOOI_t        * LOPC_pAccOOIData;
#endif

#if (FCT_CFG_TCI)
SET_MEMSEC_CONST(LOPC_pTCIInput)
const TCIInput_t                  * LOPC_pTCIInput;
SET_MEMSEC_VAR(LOPC_pTCIOutput)
TCIOutput_t                       * LOPC_pTCIOutput;
#endif

#if (FCT_CFG_SLA_FEATURE)
SET_MEMSEC_CONST(LOPC_pSLAData)
const SLAData_t                   * LOPC_pSLAData;
#endif

#if (FCT_VEH_CFG_CUSTOMINPUT)
SET_MEMSEC_CONST(LOPC_pFctVehCustInput)
const FCTVehCustomInput_t    * LOPC_pFctVehCustInput;
#endif

#if (FCT_CFG_ERROR_OUTPUT_VEH)
SET_MEMSEC_VAR(LOPC_pErrorOut)
LOPCErrorOut_t * LOPC_pErrorOut;                /*!<internal data buffer for measfreezing FCTVeh error OUTPUT interface.*/
#endif

#if (FCT_VEH_CFG_CUSTOMOUTPUT)
SET_MEMSEC_VAR(LOPC_pFctVehOutArbitrated)
FCTVehOutArbitrated_t * LOPC_pFctVehOutArbitrated;         
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
SET_MEMSEC_CONST(LOPC_pBswAlgoParameters)
const BSW_s_AlgoParameters_t * LOPC_pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
SET_MEMSEC_CONST(LOPC_pLoDmcOut)
const Lodmc_output_t * LOPC_pLoDmcOut;
#endif

#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
SET_MEMSEC_CONST(LOPC_pHeadOutputCustom)
const HEADOutputCustom_t * LOPC_pHeadOutputCustom;
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */

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

#if (FCT_CFG_ACT_CODE_VERSION)

/* Local Ports LOPC => LOP/LOC */
SET_MEMSEC_VAR(t_LOPC_IN_EVS)
LOPC_EgoVehicleState_t t_LOPC_IN_EVS;

/* Local Ports LOP => LOC */
SET_MEMSEC_VAR(t_LOPC_LOC_IVC)
LOPC_IdealVehicleCommand_t t_LOPC_LOC_IVC;

/* Local Ports LOC => LOP */
SET_MEMSEC_VAR(t_LOPC_LOC_IVS)
LOPC_IdealVehicleState_t t_LOPC_LOC_IVS;


/* Port Lists for LOP Subcomponent */
SET_MEMSEC_VAR(t_LOP_ReqPortList)
LOP_ReqPortList_t t_LOP_ReqPortList;

SET_MEMSEC_VAR(t_LOP_ProPortList)
LOP_ProPortList_t t_LOP_ProPortList;


/* Port Lists for LOC Subcomponent */
SET_MEMSEC_VAR(t_LOC_ReqPortList)
LOC_ReqPortList_t t_LOC_ReqPortList;

SET_MEMSEC_VAR(t_LOC_ProPortList)
LOC_ProPortList_t t_LOC_ProPortList;

#endif  /* FCT_CFG_ACT_CODE_VERSION */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LOPC_v_SetFrameData (const LOPC_ReqPortList_t *pRequirePorts);
static void LOPC_v_SetupSyncRef (const LOPC_ReqPortList_t *pRequirePorts);

#if (FCT_CFG_ACT_CODE_VERSION) /* New architecture */
static void LOPC_v_SetupPorts (const LOPC_ReqPortList_t *pRequirePorts, const LOPC_ProPortList_t *pProvidePorts);
static void LOPC_v_Set_LOP_Ports (LOP_ReqPortList_t *pRequirePorts, LOP_ProPortList_t *pProvidePorts);
static void LOPC_v_Set_LOC_Ports (LOC_ReqPortList_t *pRequirePorts, LOC_ProPortList_t *pProvidePorts);
static void LOPC_v_Assign_LOC_Input_Ports (LOC_ReqPortList_t *pRequirePorts);
#else /* Legacy code */
static void LOPC_v_SetupKMCPorts( const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts);
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void LOPC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
static void LOPC_v_SetCompState (AlgoCompState_t * const p_CompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
static void LOPC_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void LOPC_v_CheckProvideHeaders(const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts);
#endif

/*! Utility function to set signal header to error */
static void LOPC_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);
static void LOPC_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void LOPC_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void LOPC_v_SetProvideHeaderStates(const LOPC_ProPortList_t * pProvidePorts, AlgoSignalState_t eSigState);
static void LOPC_v_SetProvideHeader(const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts);

static void LOPC_v_CheckPorts(  const LOPC_ReqPortList_t * pRequirePorts,
                                const LOPC_ProPortList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
                                  , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                  , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                             );

static void LOPC_v_SetErrorProvidePorts (const LOPC_ProPortList_t * pProvidePorts);

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 LOPC_v_CheckInputUpdate(const LOPC_ReqPortList_t * pRequirePorts, Lopc_InputMeasCounter *pLopcInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen );
static uint32 LOPC_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                              sMeasCycleMonitor *pLastMeasCycle,
                                              float32 fTargetCycleTime, 
                                              uint8 iAcceptableDrops);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
/* ***********************************************************************
  @fn             LOPC_v_AlgoServiceAddEvent                                  */ /*!

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
void LOPC_v_AlgoServiceAddEvent(RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#else
void LOPC_v_AlgoServiceAddEvent(AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#endif
{
  if ((LOPC_pServiceFuncts                            != NULL) &&
      (LOPC_pServiceFuncts->pfRTAAlgoServiceAddEvent  != NULL))
  {
#ifdef RTA_GLOBALID_FCT_VEH
    LOPC_pServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, RTA_GLOBALID_FCT_VEH, u_IdLocal, u_OptData);
#else
    LOHP_pServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT, u_IdLocal, u_OptData);
#endif
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    LOPC_v_SetOperationMode                                                                          */ /*!

  @brief           Component OpMode is updated

  @description     Component OpMode is updated

@startuml
start
Partition LOPC_v_SetOperationMode(){
:Update current Operation mode of LOPC;
}
end
@enduml


  @return          -

  @param[in]       t_LOPCOpModeValue : 

  @glob_in         -
  @glob_out        LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState : 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             None ?
  @post            No changes ?

  @created         26.01.2017
  @changed         26.01.2017

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-135-0008a220

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOPC_v_SetOperationMode(const LOPCState_t t_LOPCOpModeValue)
{
  LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState = t_LOPCOpModeValue;
}

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             LOPC_v_SetAlgoErrorBuffer */ /*! 
  @brief          Set the Algo Error Buffer
  @description    Set the ErrorQualifier to pErrorBuffer if it is more severe than the stored one.
                  It's not possible to change to a lower priority than already set.
  @param[in]      ErrorQualifier : the Error to set
  @param[in,out]  pErrorBuffer   : pointer to the buffered error
  @pre            None
  @author         Christian Obst
**************************************************************************** */
static void LOPC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
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
  @fn           LOPC_v_SetCompState                                  */ /*!
  @brief        Set the Algo Component State.
  @description  Set the Algo Component State based on scheduler request and internal status.
  @param[out]   p_CompState : pointer to Algo Component State that shall be set.
  @param[in]    ScheduledOpMode : operation mode given by global scheduler.
  @param[in]    BufferedQualifier : internal buffer for AlgoQualifier (error status).
  @pre          Algo ran, component error states are set.
  @return       none
  @author       Christian Obst
**************************************************************************** */
static void LOPC_v_SetCompState (AlgoCompState_t * const p_CompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
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
    p_CompState->uiAlgoVersionNumber = LOPC_STATIC_MEMORY.LOPC_Frame.Versions.uiLopc;
#if COMP_STATE_INTFVER > 2u
    p_CompState->uiApplicationNumber = 0u;
    p_CompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    p_CompState->ApplicationNumber = 0u;
    p_CompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState)
    {
    case LOPC_INIT:
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
    case LOPC_RUN:
      p_CompState->eCompState = COMP_STATE_RUNNING;
      p_CompState->eErrorCode = COMP_ERROR_NO_ERROR;
      p_CompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case LOPC_SHUTDOWN:
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
  Functionname:    LOPC_v_CheckPortUpdated                                                                          */ /*!

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
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC
                   
  @pre             -
  @post            -

  @created         -
  @changed         2/11/2016

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 LOPC_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
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
  Functionname:    LOPC_v_CheckInputUpdate                                                                          */ /*!

  @brief           Checks for frame drops and frozen input interfaces based on provided timestamps.

  @description     calls the Update Checker function for every used input interface and writes it to the InputCounters struct.

  @return          static uint32 : number of interfaces which are not updated longer than debounce time.

  @param[in]       pRequirePorts : input interface provided to FCTVeh. 
  @param[in]       pFCTVehInputCounters : internal memory struct to store update information.
  @param[in]       fTargetCycleTimeVeh : target cycle time for the FCTVeh Task. 
  @param[in]       fTargetCycleTimeSen : target cycle time for the Camera (FCTSen) Task (Sensor cycle).

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling HP processing
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
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support
  @c_switch_full   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             -
  @post            -

  @created         -
  @changed         22/09/2017

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update).

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 LOPC_v_CheckInputUpdate(const LOPC_ReqPortList_t * pRequirePorts, Lopc_InputMeasCounter *pLopcInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen)
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */

#else /* Legacy code */
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pVehCtrlData->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sVehCtrlData), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pEgoDynRaw->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sEgoDynRaw), fTargetCycleTimeSen, AcceptableDrops );
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pLongCtrlResp->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sLongCtrlInput), fTargetCycleTimeVeh, AcceptableDrops );
#if ((CFG_ACC_LEVER_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pAccLever->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sAccLeverInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if ((FCT_CFG_ACC_HEADWAY_PLANNER) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pAccDisplayObj->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sAcc_object), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pAccOutput->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sAcc_output_data), fTargetCycleTimeVeh, AcceptableDrops );
#endif 
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts.pAccOOIData->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sFCTSenAccOOI), fTargetCycleTimeSen, AcceptableDrops );
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pVehSig->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sVehSig), fTargetCycleTimeSen, AcceptableDrops );
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  ErrorCounter += LOPC_v_CheckPortUpdated( &(pRequirePorts->pFctVehCustInput->sSigHeader.uiTimeStamp), &(pLopcInputCounters->sFctVehCustInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if (FCT_CFG_TCI)
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pTCIInput->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pTCIInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if (FCT_CFG_SLA_FEATURE)
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pSLAData->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pTCIInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             LOPC_v_SetDem                                  */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTVehServiceFuncts connected to input service ports
  @todo           review
  @author         Christian Obst
**************************************************************************** */
void LOPC_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pFCTVehServiceFuncts != NULL) && (pFCTVehServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pFCTVehServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif

#if (FCT_CFG_ACT_CODE_VERSION)
/*************************************************************************************************************************
  Functionname:    LOPC_v_SetupPorts                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       LOPC_ReqPortList_pt pRequirePorts
  @param[in]       LOPC_ProPortList_pt pProvidePorts

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         14.06.2017
  @changed         14.06.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-8382-9699-839
*************************************************************************************************************************/
static void LOPC_v_SetupPorts(const LOPC_ReqPortList_t *pRequirePorts, const LOPC_ProPortList_t *pProvidePorts)
{
/*! Assignment of external pointers to LOPC input ports for access within this component */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  pt_LOPC_IN_CC_VSCP = pRequirePorts->pt_LOPC_IN_CC_VSCP;
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  pt_LOPC_IN_SLA_VSCP = pRequirePorts->pt_LOPC_IN_SLA_VSCP;
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  pt_LOPC_IN_SLA_DSCP = pRequirePorts->pt_LOPC_IN_SLA_DSCP;
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  pt_LOPC_IN_CP_DCCP = pRequirePorts->pt_LOPC_IN_CP_DCCP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  pt_LOPC_IN_HP_TFCP = pRequirePorts->pt_LOPC_IN_HP_TFCP;
#endif

  pt_LOPC_IN_LVCP = pRequirePorts->pt_LOPC_IN_LVCP;

  pt_LOPC_IN_EgoVehDynState = pRequirePorts->pt_LOPC_IN_EgoVehDynState;
  pt_LOPC_IN_EgoVehDynCtrl  = pRequirePorts->pt_LOPC_IN_EgoVehDynCtrl;


/*! Assignment of external pointers to LOPC output ports for access within this component */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  pt_LOPC_OUT_CC_VSSP = pProvidePorts->pt_LOPC_OUT_CC_VSSP;
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  pt_LOPC_OUT_SLA_VSSP = pProvidePorts->pt_LOPC_OUT_SLA_VSSP;
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  pt_LOPC_OUT_SLA_DSSP = pProvidePorts->pt_LOPC_OUT_SLA_DSSP;
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  pt_LOPC_OUT_CP_DCSP = pProvidePorts->pt_LOPC_OUT_CP_DCSP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  pt_LOPC_OUT_HP_TFSP = pProvidePorts->pt_LOPC_OUT_HP_TFSP;
#endif

  pt_LOPC_OUT_LVSP = pProvidePorts->pt_LOPC_OUT_LVSP;
  pt_LOPC_OUT_EVCP = pProvidePorts->pt_LOPC_OUT_EVCP;
}


#else /* Legacy code */
/*************************************************************************************************************************
  Functionname:    LOPC_v_SetupKMCPorts                                                                             */ /*!

  @brief           Mapping of required and provide ports to local pointers

  @description     Mapping of required and provide ports to local pointers

@startuml
Start
Partition LOPC_v_SetupKMCPorts(){
: Mapping of External required and provide ports to local pointers\nAcc Lever Input, TCI input, Speed Limit data, ACC Object Information, Algo parameters \n Longitudinal Control response,Ego Dynamic Information\nTCI Output, error Output, Longitudinal Vehicle Output;
}
end
@enduml

  @return          -

  @param[in]       pRequirePorts : Require ports to LOPC
  @param[in]       pProvidePorts : Provide ports from LOPC

  @glob_in         -
  @glob_out        LOPC_pEgoDynRaw
                   LOPC_pVehSig
                   LOPC_pAccLever
                   LOPC_pLongCtrlResp
                   LOPC_pAccDisplayObj
                   LOPC_pAccOutput
                   LOPC_pAccOOIData
                   LOPC_pFctVehCustInput
                   LOPC_pBswAlgoParameters
                   LOPC_pTCIInput
                   LOPC_pSLAData
                   LOPC_pFctVehLongOut
                   LOPC_pLongCtrlOutput
                   LOPC_pErrorOut
                   LOPC_pTCIOutput

  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT          : FCT support for ACC HP (Headway Planner) sub-component.
  @c_switch_part   CFG_ACC_LEVER_INPUT                : ACC Lever Input port interface
  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER        : FCT support for ACC HP (Headway Planner)
  @c_switch_part   FCT_CFG_TCI                        : FCT support for TCI module
  @c_switch_part   FCT_CFG_SLA_FEATURE                : Activation switch for SLA support
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT       : Interface port for information from FCT Sen to Veh
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT            : FCT veh custom input interface
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS            : Configuration switch enabling passing of algo parameters to the FCT component
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             -
  @post            LOPC_v_Exec

  @created         24.01.2017
  @changed         23.09.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_SetupKMCPorts( const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts)
{
  /* Initialize global pointers used by macros */
  /* Request Ports */
  LOPC_pEgoDynRaw         = pRequirePorts->pEgoDynRaw;
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
  LOPC_pVehSig            = pRequirePorts->pVehSig;
#endif
  LOPC_pAccLever          = pRequirePorts->pAccLever;
  LOPC_pLongCtrlResp      = pRequirePorts->pLongCtrlResp;
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  LOPC_pAccDisplayObj     = pRequirePorts->pAccDisplayObj;
  LOPC_pAccOutput         = pRequirePorts->pAccOutput;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  LOPC_pAccOOIData        = pRequirePorts->pAccOOIData;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  LOPC_pFctVehCustInput   = pRequirePorts->pFctVehCustInput;
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
  LOPC_pBswAlgoParameters = pRequirePorts->pBswAlgoParameters;
#endif
#if (FCT_CFG_TCI)
  LOPC_pTCIInput          = pRequirePorts->pTCIInput;
#endif
#if (FCT_CFG_SLA_FEATURE)
  LOPC_pSLAData           = pRequirePorts->pSLAData;
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
  LOPC_pLoDmcOut          = pRequirePorts->pLoDmcOutput;
#endif
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
  LOPC_pHeadOutputCustom  = pRequirePorts->pHEADOutputCustom;
#endif

  /* Provide ports */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  LOPC_pFctVehLongOut     = pProvidePorts->pFctVehLongOut;
#endif
  LOPC_pLongCtrlOutput    = pProvidePorts->pLongCtrlOutput;

#if (FCT_CFG_ERROR_OUTPUT_VEH)
  LOPC_pErrorOut          = pProvidePorts->pErrorOut;
#endif
#if (FCT_CFG_TCI)
  LOPC_pTCIOutput         = pProvidePorts->pTCIOutput;
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
  LOPC_pFctVehOutArbitrated = pProvidePorts->pFCTVehOutArbitrated;
#endif

}
#endif  /* FCT_CFG_ACT_CODE_VERSION */

/*************************************************************************************************************************
  Functionname:    LOPC_v_FillSigHeader                                                                             */ /*!

  @brief           Output ptr signal header is filled

  @description     Output ptr signal header is filled

@startuml
Start
 Partition LOPC_v_FillSigHeader(){
 : load timestamp, Measurement Counter and the Cycle Counter values from input to Output pointers;
}
end
@enduml

  @return          static void

  @param[in,out]   pSigHeader : 
  @param[in]       pSourceHdr : 

  @created         31.01.2017
  @changed         31.01.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = LOPC_STATIC_MEMORY.LOPC_Frame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SetSigHeaderState                                                                         */ /*!

  @brief           Set signal header state

  @description     Set signal header state

@startuml
start
 partition LOPC_v_SetSigHeaderState(){
: map signal states to the pointer;
}
End
@enduml

  @return          -

  @param[in,out]   pSigHeader : pointer to signal header struct
  @param[in]       eSigState : signal state to be set

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             -
  @post            -

  @created         31.01.2017
  @changed         31.01.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus            = eSigState;
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SetProvideHeaderStates                                                                    */ /*!

  @brief           Set the state in the SigHeader for all used provide ports

  @description     Set the state in the SigHeader for all used provide ports

@startuml
Start
Partition LOPC_v_SetProvideHeaderStates(){
: Set the states in the Sigheader for all used provide ports;
}
end
@enduml

  @return          -

  @param[in]       pProvidePorts : Provide ports from LOPC as defined in frame_lopc_ext.h
  @param[in]       eSigState : the state to set for the 'eSigStatus' field [AlgoSignalState_t  as in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE          : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER        :  FCT support for ACC HP (Headway Planner) sub-component. Needed for ACT reaction to objects
  @c_switch_part   FCT_CFG_TCI                        : FCT support for TCI module
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH           : brief FCT error output from FCT_VEH
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_SetProvideHeaderStates(const LOPC_ProPortList_t * pProvidePorts, AlgoSignalState_t eSigState) 
{
#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */
  _PARAM_UNUSED(pProvidePorts);
  _PARAM_UNUSED(eSigState);
#else /* Legacy code */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  LOPC_v_SetSigHeaderState(&pProvidePorts->pVehCompState->sSigHeader, eSigState);
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  LOPC_v_SetSigHeaderState(&pProvidePorts->pFctVehLongOut->sSigHeader, eSigState);
#endif
#if (FCT_CFG_TCI)
  LOPC_v_SetSigHeaderState(&pProvidePorts->pTCIOutput->sSigHeader, eSigState);
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  LOPC_v_SetSigHeaderState(&pProvidePorts->pErrorOut->sSigHeader, eSigState);
#endif
  LOPC_v_SetSigHeaderState(&pProvidePorts->pLongCtrlOutput->sSigHeader, eSigState);
#endif /* FCT_CFG_ACT_CODE_VERSION */
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SetProvideHeader                                                                          */ /*!

  @brief           Signal headers of output pointers are filled

  @description     Function coordinates the filling of signal headers of output pointers

@startuml
Start
partition LOPC_v_SetProvideHeader(){
: Fill Signal header for the Output ports by copying from Specified input ports;
}
end
@enduml 


  @return          static void

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             None ?
  @post            No changes ?

  @created         31.01.2017
  @changed         31.01.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_SetProvideHeader(const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts) 
{
#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */
  _PARAM_UNUSED(pRequirePorts);
  _PARAM_UNUSED(pProvidePorts);
#else /* Legacy code */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  LOPC_v_FillSigHeader(&pProvidePorts->pFctVehLongOut->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
#endif
#if ((FCT_CFG_TCI) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  LOPC_v_FillSigHeader(&pProvidePorts->pTCIOutput->sSigHeader, &pRequirePorts->pTCIInput->sSigHeader);
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  LOPC_v_FillSigHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
#endif
  LOPC_v_FillSigHeader(&pProvidePorts->pLongCtrlOutput->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
#endif /* FCT_CFG_ACT_CODE_VERSION */
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SetSigHeaderError                                                                         */ /*!

  @brief           Signal header initialized for error mode

  @description     Signal header of pointer initialized for error mode

  @startuml

Start
partition LOPC_v_SetSigHeaderError(){
: Set cycle counter value of the port to LOPC Cycle Counter;
: Set Signal Status of the Port to Invalid (value 2);
}
end
@enduml 

  @return          static void

  @param[in,out]   pSigHeader

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @created         31.01.2017
  @changed         31.01.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiCycleCounter        = LOPC_STATIC_MEMORY.LOPC_Frame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    LOPC_v_CheckProvideHeader                                                                        */ /*!

  @brief           Check whether the signal header has changed during the call of the components

  @description     Detailed Design

  @return          static void

  @param[in]       pProvidedSigHeader : 
  @param[in]       pReceivedSigHeader : 

  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             None ?
  @post            No changes ?

  @created         23.02.2016
  @changed         23.02.2016

  @todo            Remove this entire line if not needed

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOPC_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
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
  Functionname:    LOPC_v_CheckProvideHeaders                                                                       */ /*!

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
static void LOPC_v_CheckProvideHeaders(const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts) 
{
#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */
  _PARAM_UNUSED(pRequirePorts);
  _PARAM_UNUSED(pProvidePorts);
#else /* Legacy code */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  LOPC_v_CheckProvideHeader(&pProvidePorts->pFctVehLongOut->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
  LOPC_v_CheckProvideHeader(&pProvidePorts->pLongCtrlOutput->sSigHeader, &pRequirePorts.pLongCtrlResp->sSigHeader);
#if ((FCT_CFG_TCI) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  LOPC_v_CheckProvideHeader(&pProvidePorts->pTCIOutput->sSigHeader, &pRequirePorts->pTCIInput->sSigHeader);
#endif
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  LOPC_v_CheckProvideHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
}
#endif

/*************************************************************************************************************************
  Functionname:    LOPC_v_CheckPorts                                                                           */ /*!

  @brief           Component pointers checked for null condition

  @description     Null pointer check of component input/output pointers to trigger state changes

@startuml
start
Partition LOPC_v_CheckPorts(){
If ( pointers mapping to Input and Output Ports are Null ) Then (True)
: set LOPC Component State to Init;
Else (False)
: Do Nothing;
endif
}
End
@enduml

  @return          -

  @param[in]       pRequirePorts : 
  @param[in]       (FCT_CFG_USE_SERVICE_POINTER_FUNCTS : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @created         31.01.2017
  @changed         31.01.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_CheckPorts( const LOPC_ReqPortList_t * pRequirePorts, const LOPC_ProPortList_t * pProvidePorts
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
#if (FCT_CFG_ACT_CODE_VERSION)
    /* Todo: Write for new ports */
    || (pRequirePorts->pt_LOPC_IN_CC_VSCP == NULL)

#else /* Legacy code */
    || (pRequirePorts->pVehCtrlData == NULL)
    || (pRequirePorts->pEgoDynRaw == NULL)
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
    || (pRequirePorts->pVehSig == NULL)
#endif
#if (CFG_ACC_LEVER_INPUT)
    || (pRequirePorts->pAccLever == NULL)
#endif
    || (pRequirePorts->pLongCtrlResp == NULL)
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    || (pRequirePorts->pAccDisplayObj == NULL)
    || (pRequirePorts->pAccOutput == NULL)
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    || (pRequirePorts->pAccOOIData == NULL)
#endif
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
    || (pRequirePorts->pFctVehCustInput == NULL)
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
    || (pRequirePorts->pBswAlgoParameters == NULL)
#endif
#if (FCT_CFG_TCI)
    || (pRequirePorts->pTCIInput == NULL)
#endif
#if (FCT_CFG_SLA_FEATURE)
    || (pRequirePorts->pSLAData == NULL)
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
    || (pRequirePorts->pLoDmcOutput == NULL)
#endif
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
    || (pRequirePorts->pHEADOutputCustom == NULL)
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
    )
  {
    /* Some request port pointer is NULL => DEM and shutdown */

#if (FCT_CFG_USE_DEM)
    /*validity of service pointer isn't clear here*/
    LOPC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /* setup the Algo Error Buffer */
    LOPC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    /* shutdown the system */
    LOPC_v_SignalErrorShutdown(FALSE);
  }
  else
  {
    /* Verify that provide port buffer pointers are set (non-null) */
    if (
      (pProvidePorts == NULL)
#if (FCT_CFG_ACT_CODE_VERSION)
      /* Todo: Write for new ports */
      || (pProvidePorts->pt_LOPC_OUT_CC_VSSP == NULL)

#else /* Legacy code */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
      || (pProvidePorts->pFctVehLongOut == NULL)
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
      || (pProvidePorts->pErrorOut == NULL)
#endif
      || (pProvidePorts->pLongCtrlOutput == NULL)
#if (FCT_CFG_TCI)
      || (pProvidePorts->pTCIOutput == NULL)
#endif
#endif 
      )
    {
#if (FCT_CFG_USE_DEM)
      /* Some provide port pointer is NULL => DEM -> shutdown */
      LOPC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      LOPC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      LOPC_v_SignalErrorShutdown(FALSE);
    }
    else
    {
#if (FCT_CFG_USE_DEM)
      /* receive and provide ports are fine */
      LOPC_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
    }

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
    /* no NullPointer in request ports*/
    /* check for SignalState in requestPorts*/
    if(
#if (FCT_CFG_ACT_CODE_VERSION)
      /* Todo: Write for new ports */
      (pRequirePorts->pt_LOPC_IN_CC_VSCP->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      || (pRequirePorts->pt_LOPC_IN_CP_DCCP->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#else /* Legacy code */
      (pRequirePorts->pVehCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      || (pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
      || (pRequirePorts->pVehSig->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (CFG_ACC_LEVER_INPUT)
      || (pRequirePorts->pAccLever->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
      || (pRequirePorts->pLongCtrlResp->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
      || (pRequirePorts->pAccDisplayObj->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      || (pRequirePorts->pAccOutput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
      || (pRequirePorts->pAccOOIData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
      || (pRequirePorts->pFctVehCustInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_TCI)
      || (pRequirePorts->pTCIInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_SLA_FEATURE)
      || (pRequirePorts->pSLAData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
      )
    {
      /*signal state broken -> no dem only shutdown*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /* setup the Algo Error Buffer */
      LOPC_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      /* shutdown the system */
      LOPC_v_SignalErrorShutdown(FALSE);
    }
#endif /*FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK*/
  }
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SetErrorProvidePorts                                                                      */ /*!

  @brief           Output pointer signal headers filled for error state

  @description     Output pointer signal headers filled for error state

@startuml
start
Partition LOPC_v_SetErrorProvidePorts(){
If (provide port is not Null) Then (True)
: set Provide port version number;
: set Provide Port Cycle counter and signal status;
Else (false)
: set Local Pointers to null;
Endif
}
End
@enduml

  @return          -

  @param[in]       pProvidePorts

  @c_switch_part        @ref FCT_CFG_TCI \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_ERROR_OUTPUT_VEH \n
                        @ref FCT_CFG_TCI \n
                        @ref FCT_CFG_ACC_HEADWAY_PLANNER \n
                        @ref ACT_CFG_SLA_VSC_PORT_CNT \n
                        @ref ACT_CFG_CC_VSC_PORT_CNT \n
                        @ref FCT_CFG_ACT_CODE_VERSION \n
                        @ref COMP_STATE_INTFVER \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @InOutCorrelation     Covered in plantuml design

  @created         31.01.2017
  @changed         31.01.2017

  @author          Niraj Mistry | Niraj.Mistry@continental-corporation.com | +49 (69) 7603-6827
*************************************************************************************************************************/
static void LOPC_v_SetErrorProvidePorts (const LOPC_ProPortList_t * pProvidePorts)
{
  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pVehCompState != NULL)
    {
      LOPC_pCompState                  = pProvidePorts->pVehCompState;
#if COMP_STATE_INTFVER > 2u
      LOPC_pCompState->uiVersionNumber  = COMP_STATE_INTFVER;
#else
      LOPC_pCompState->uVersionNumber  = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      LOPC_pCompState = NULL;
    }
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
    /* Todo: Write for new ports */
#if (ACT_CFG_CC_VSC_PORT_CNT)
    if(pProvidePorts->pt_LOPC_OUT_CC_VSSP != NULL)
    {
      pProvidePorts->pt_LOPC_OUT_CC_VSSP->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
      LOPC_v_SetSigHeaderError(&pProvidePorts->pt_LOPC_OUT_CC_VSSP->sSigHeader);
    }
#endif
#if (ACT_CFG_SLA_VSC_PORT_CNT)
    if(pProvidePorts->pt_LOPC_OUT_SLA_VSSP != NULL)
    {
      pProvidePorts->pt_LOPC_OUT_SLA_VSSP->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
      LOPC_v_SetSigHeaderError(&pProvidePorts->pt_LOPC_OUT_SLA_VSSP->sSigHeader);
    }
#endif
#else /* Legacy code */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    if(pProvidePorts->pFctVehLongOut != NULL)
    {
      pProvidePorts->pFctVehLongOut->uiVersionNumber = FCT_VEH_2_SEN_INFO_VERSION;
      LOPC_v_SetSigHeaderError(&pProvidePorts->pFctVehLongOut->sSigHeader);
      LOPC_pFctVehLongOut = pProvidePorts->pFctVehLongOut;
    }
    else
    {
      LOPC_pFctVehLongOut = NULL;
    }
#endif
    if (pProvidePorts->pLongCtrlOutput != NULL)
    {
      pProvidePorts->pLongCtrlOutput->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
      LOPC_v_SetSigHeaderError(&pProvidePorts->pLongCtrlOutput->sSigHeader);
      LOPC_pLongCtrlOutput = pProvidePorts->pLongCtrlOutput;
    }
    else
    {
      LOPC_pLongCtrlOutput = NULL;
    }
#if (FCT_CFG_TCI)
    if (pProvidePorts->pTCIOutput != NULL)
    {
      pProvidePorts->pTCIOutput->uiVersionNumber = TCIOutput_INTFVER;
      LOPC_v_SetSigHeaderError(&pProvidePorts->pTCIOutput->sSigHeader);
      LOPC_pTCIOutput = pProvidePorts->pTCIOutput;
    }
    else
    {
      LOPC_pTCIOutput = NULL;
    }
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
    if (pProvidePorts->pErrorOut != NULL)
    {
      if ((LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCOpMode != FCT_MOD_SHUTDOWN) && (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_SHUTDOWN))
      {
        pProvidePorts->pErrorOut->PortError = AL_ERR_STATE_ACTIVE;
      }
    }
#endif
  }
  else
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOPC_pCompState = NULL;
#endif
    LOPC_pFctVehLongOut = NULL;
    LOPC_pLongCtrlOutput = NULL;
#if (FCT_CFG_TCI)
    LOPC_pTCIOutput = NULL;
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
  }
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SetupSyncRef                                                                              */ /*!

  @brief           Component syncref structure filled

  @description     Component syncref structure filled

@startuml
Start
Partition LOPC_v_SetupSyncRef(){
If (Specified input port is available) Then (True)
: copy Signal Header from Input Port\n to SyncRef Header Structure;
Else (False)
: set Signal Status of SyncRef signal\n header to invalid (Value 2);
       Note Right 
        Vehicle Dynamic Information\n
        ACC Lever Input\n
        LongCtrl Input\n
        ACC Object\n
      AccOutputData\n
      SLAData\n
      TCI Input\n
      Signal Invalid State\n
 End Note
Endif
: Fill signal header of SyncRef port with\n valid data from Vehilce Control Input; 
}
End
@enduml

  @return          static void

  @param[in]       pRequirePorts : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC


  @created         31.01.2017
  @changed         31.01.2017


  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
#if (FCT_CFG_ACT_CODE_VERSION)

static void LOPC_v_SetupSyncRef(const LOPC_ReqPortList_t *pRequirePorts)
{
  /*setting whole syncref to zero */
  (void)memset(&LOPC_STATIC_MEMORY.LOPC_SyncRef, 0, sizeof(LOPC_STATIC_MEMORY.LOPC_SyncRef));

  if (pRequirePorts != NULL)
  {
    /* pt_LOPC_IN_Ctrl */
    if (pRequirePorts->pt_LOPC_IN_Ctrl != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      LOPC_v_FillSigHeader(&(LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader), &(pRequirePorts->pt_LOPC_IN_Ctrl->sSigHeader));
      LOPC_v_SetSigHeaderState(&LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader, AL_SIG_STATE_OK);

      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_SH_CTRL = pRequirePorts->pt_LOPC_IN_Ctrl->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (ACT_CFG_CC_VSC_PORT_CNT)
    /* pt_LOPC_IN_CC_VSCP */
    if (pRequirePorts->pt_LOPC_IN_CC_VSCP != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_CC_VSCP = pRequirePorts->pt_LOPC_IN_CC_VSCP->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
    /* pt_LOPC_IN_SLA_VSCP */
    if (pRequirePorts->pt_LOPC_IN_SLA_VSCP != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_SLA_VSCP = pRequirePorts->pt_LOPC_IN_SLA_VSCP->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
    /* pt_LOPC_IN_SLA_DSCP */
    if (pRequirePorts->pt_LOPC_IN_SLA_DSCP != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_SLA_DSCP = pRequirePorts->pt_LOPC_IN_SLA_DSCP->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
    /* pt_LOPC_IN_CP_DCCP */
    if (pRequirePorts->pt_LOPC_IN_CP_DCCP != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_CP_DCCP = pRequirePorts->pt_LOPC_IN_CP_DCCP->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
    /* pt_LOPC_IN_HP_TFCP */
    if (pRequirePorts->pt_LOPC_IN_HP_TFCP != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_HP_TFCP = pRequirePorts->pt_LOPC_IN_HP_TFCP->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    /* pt_LogVehCommand */
    if (pRequirePorts->pt_LOPC_IN_LVCP != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_LogVehCommand = pRequirePorts->pt_LOPC_IN_LVCP->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_EgoVehDynCtrl */
    if (pRequirePorts->pt_LOPC_IN_EgoVehDynCtrl != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_EgoVehDynCtrl = pRequirePorts->pt_LOPC_IN_EgoVehDynCtrl->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_EgoVehDynState */
    if (pRequirePorts->pt_LOPC_IN_EgoVehDynState != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.t_EgoVehDynState = pRequirePorts->pt_LOPC_IN_EgoVehDynState->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }

}

#else /* Legacy code */

static void LOPC_v_SetupSyncRef(const LOPC_ReqPortList_t *pRequirePorts)
{
  /*setting whole syncref to zero */
  (void)memset(&(LOPC_STATIC_MEMORY.LOPC_SyncRef), 0u, sizeof(LOPC_SyncRef_t)); // PRQA S 2840,2845
    /* date: 2019-05-28, reviewer:Rasish Verma(uib25204), reason: no reference to null pointer */ 

  if (pRequirePorts != NULL)
  {
    /*pVehCtrlData*/
    if (pRequirePorts->pVehCtrlData != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      LOPC_v_FillSigHeader(&LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader, &pRequirePorts->pVehCtrlData->sSigHeader);
      LOPC_v_SetSigHeaderState(&LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader, AL_SIG_STATE_OK);
      LOPC_STATIC_MEMORY.LOPC_SyncRef.FCTCtrlData              = pRequirePorts->pVehCtrlData->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pEgoDynRaw*/
    if (pRequirePorts->pEgoDynRaw != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.VehDyn                   = pRequirePorts->pEgoDynRaw->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (CFG_ACC_LEVER_INPUT)
    /*pVehSig*/
    if (pRequirePorts->pVehSig != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.VehSig                   = pRequirePorts->pVehSig->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (CFG_ACC_LEVER_INPUT)
    /*pAccLever*/
    if (pRequirePorts->pAccLever != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.AccLeverInput            = pRequirePorts->pAccLever->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    /*pLongCtrlResp*/
    if (pRequirePorts->pLongCtrlResp != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.LongCtrlInput            = pRequirePorts->pLongCtrlResp->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    /*pAccDisplayObj*/
    if (pRequirePorts->pAccDisplayObj != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.AccObject               = pRequirePorts->pAccDisplayObj->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pAccDisplayObj*/
    if (pRequirePorts->pAccOutput != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.AccOutputData          = pRequirePorts->pAccOutput->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    /*pAccDisplayObj*/
    if (pRequirePorts->pAccOOIData != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.FCTAccOOIData            = pRequirePorts->pAccOOIData->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
#endif /* (FCT_CFG_ACC_HEADWAY_PLANNER) */

#if (FCT_VEH_CFG_CUSTOMINPUT)
    /*pFctVehCustInput*/
    if (pRequirePorts->pFctVehCustInput != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.FctVehCustInput            = pRequirePorts->pFctVehCustInput->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_TCI)
    /*pTCIInput*/
    if (pRequirePorts->pTCIInput != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.TCIInput              = pRequirePorts->pTCIInput->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_SLA_FEATURE)
    /*pSLAData*/
    if (pRequirePorts->pSLAData != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.SLAData                = pRequirePorts->pSLAData->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
    if (pRequirePorts->pLoDmcOutput != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.LoDmcOutput            = pRequirePorts->pLoDmcOutput->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
    if (pRequirePorts->pHEADOutputCustom != NULL)
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.HeadOutputCustom      = pRequirePorts->pHEADOutputCustom->sSigHeader;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
  }
  else
  {
    LOPC_STATIC_MEMORY.LOPC_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }

}

#endif /* FCT_CFG_ACT_CODE_VERSION */

#if (FCT_CFG_ACT_CODE_VERSION)
/*************************************************************************************************************************
  Functionname:    LOPC_v_Set_LOP_Ports                                                                              */ /*!

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

  @created         14.07.2017
  @changed         14.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void LOPC_v_Set_LOP_Ports(LOP_ReqPortList_t *pRequirePorts, LOP_ProPortList_t *pProvidePorts)
{
/*! Connection LOPC Input => LOP Input */
#if (ACT_CFG_CC_VSC_PORT_CNT + ACT_CFG_SLA_VSC_PORT_CNT == LOP_CFG_VSC_PORT_CNT)
#if (ACT_CFG_CC_VSC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_CC_VSC_PORT_CNT; i++)
  {
//  pRequirePorts->at_LOP_IN_VSCP[i].pt_SigHeader = &(pt_LOPC_IN_CC_VSCP->sSigHeader);
    pRequirePorts->at_LOP_IN_VSCP[i].pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_CC_VSCP);
    pRequirePorts->at_LOP_IN_VSCP[i].pt_VSC       = &(pt_LOPC_IN_CC_VSCP->at_VSC[i]);
  }
}
#endif
#if (ACT_CFG_SLA_VSC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_SLA_VSC_PORT_CNT; i++)
  {
//  pRequirePorts->at_LOP_IN_VSCP[ACT_CFG_CC_VSC_PORT_CNT+i].pt_SigHeader = &(pt_LOPC_IN_SLA_VSCP->sSigHeader);
    pRequirePorts->at_LOP_IN_VSCP[ACT_CFG_CC_VSC_PORT_CNT+i].pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_SLA_VSCP);
    pRequirePorts->at_LOP_IN_VSCP[ACT_CFG_CC_VSC_PORT_CNT+i].pt_VSC       = &(pt_LOPC_IN_SLA_VSCP->at_VSC[i]);
  }
}
#endif
#else
  #error Port Sizes Incompatible: (ACT_CFG_CC_VSC_PORT_CNT + ACT_CFG_SLA_VSC_PORT_CNT != LOP_CFG_VSC_PORT_CNT);
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT == LOP_CFG_DSC_PORT_CNT)
#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_SLA_DSC_PORT_CNT; i++)
  {
//  pRequirePorts->at_LOP_IN_DSCP[i].pt_SigHeader = &(pt_LOPC_IN_SLA_DSCP->sSigHeader);
    pRequirePorts->at_LOP_IN_DSCP[i].pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_SLA_DSCP);
    pRequirePorts->at_LOP_IN_DSCP[i].pt_DSC       = &(pt_LOPC_IN_SLA_DSCP->at_DSC[i]);
  }
}
#endif
#else
  #error Port Sizes Incompatible: (ACT_CFG_SLA_DSC_PORT_CNT != LOP_CFG_DSC_PORT_CNT);
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT == LOP_CFG_DCC_PORT_CNT)
#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_CP_DCC_PORT_CNT; i++)
  {
//  pRequirePorts->at_LOP_IN_DCCP[i].pt_SigHeader = &(pt_LOPC_IN_CP_DCCP->sSigHeader);
    pRequirePorts->at_LOP_IN_DCCP[i].pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_CP_DCCP);
    pRequirePorts->at_LOP_IN_DCCP[i].pt_DCC       = &(pt_LOPC_IN_CP_DCCP->at_DCC[i]);
  }
}
#endif
#else
  #error Port Sizes Incompatible: (ACT_CFG_CP_DCC_PORT_CNT != LOP_CFG_DCC_PORT_CNT);
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
//  pRequirePorts->at_LOP_IN_TFCP[i].pt_SigHeader = &(pt_LOPC_IN_HP_TFCP->sSigHeader);
    pRequirePorts->at_LOP_IN_TFCP[i].pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_HP_TFCP);
    pRequirePorts->at_LOP_IN_TFCP[i].pt_TFC       = &(pt_LOPC_IN_HP_TFCP->at_TFC[i]);
  }
}
#endif

  /*! Connection LOPC Input => LOP Input */
//pRequirePorts->t_LOP_IN_EVSP.pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_EgoVehDynCtrl);    /* TODO - Select relevant Signal Header */
  pRequirePorts->t_LOP_IN_EVSP.pt_SigHeader = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_EgoVehDynState);   /* TODO - Select relevant Signal Header */
  pRequirePorts->t_LOP_IN_EVSP.pt_EVS = &t_LOPC_IN_EVS;

/*! Connection LOC Output => LOP Input */
  pRequirePorts->t_LOP_IN_IVSP.pt_IVS = &t_LOPC_LOC_IVS;


  /*! Connection LOP Output => LOPC Output */
#if (ACT_CFG_CC_VSC_PORT_CNT + ACT_CFG_SLA_VSC_PORT_CNT == LOP_CFG_VSC_PORT_CNT)
#if (ACT_CFG_CC_VSC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_CC_VSC_PORT_CNT; i++)
  {
    pProvidePorts->at_LOP_OUT_VSSP[i].pt_SigHeader = &(pt_LOPC_OUT_CC_VSSP->sSigHeader);
    pProvidePorts->at_LOP_OUT_VSSP[i].pt_VSS       = &(pt_LOPC_OUT_CC_VSSP->at_VSS[i]);
  }
}
#endif
#if (ACT_CFG_SLA_VSC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_SLA_VSC_PORT_CNT; i++)
  {
    pProvidePorts->at_LOP_OUT_VSSP[ACT_CFG_CC_VSC_PORT_CNT+i].pt_SigHeader = &(pt_LOPC_OUT_SLA_VSSP->sSigHeader);
    pProvidePorts->at_LOP_OUT_VSSP[ACT_CFG_CC_VSC_PORT_CNT+i].pt_VSS       = &(pt_LOPC_OUT_SLA_VSSP->at_VSS[i]);
  }
}
#endif
#else
  #error Port Sizes Incompatible: (ACT_CFG_CC_VSC_PORT_CNT + ACT_CFG_SLA_VSC_PORT_CNT != LOP_CFG_VSC_PORT_CNT);
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT == LOP_CFG_DSC_PORT_CNT)
#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_SLA_DSC_PORT_CNT; i++)
  {
    pProvidePorts->at_LOP_OUT_DSSP[i].pt_SigHeader = &(pt_LOPC_OUT_SLA_DSSP->sSigHeader);
    pProvidePorts->at_LOP_OUT_DSSP[i].pt_DSS       = &(pt_LOPC_OUT_SLA_DSSP->at_DSS[i]);
  }
}
#endif
#else
  #error Port Sizes Incompatible: (ACT_CFG_SLA_DSC_PORT_CNT != LOP_CFG_DSC_PORT_CNT);
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT == LOP_CFG_DCC_PORT_CNT)
#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_CP_DCC_PORT_CNT; i++)
  {
    pProvidePorts->at_LOP_OUT_DCSP[i].pt_SigHeader = &(pt_LOPC_OUT_CP_DCSP->sSigHeader);
    pProvidePorts->at_LOP_OUT_DCSP[i].pt_DCS       = &(pt_LOPC_OUT_CP_DCSP->at_DCS[i]);
  }
}
#endif
#else
  #error Port Sizes Incompatible: (ACT_CFG_CP_DCC_PORT_CNT != LOP_CFG_DCC_PORT_CNT);
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    pProvidePorts->at_LOP_OUT_TFSP[i].pt_SigHeader = &(pt_LOPC_OUT_HP_TFSP->sSigHeader);
    pProvidePorts->at_LOP_OUT_TFSP[i].pt_TFS       = &(pt_LOPC_OUT_HP_TFSP->at_TFS[i]);
  }
}
#endif

/*! Connection LOP Output => LOC Input */
  pProvidePorts->t_LOP_OUT_IVCP.pt_IVC = &t_LOPC_LOC_IVC;
}


/*************************************************************************************************************************
  Functionname:    LOPC_v_Set_LOC_Ports                                                                              */ /*!

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

  @created         14.07.2017
  @changed         14.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void LOPC_v_Set_LOC_Ports(LOC_ReqPortList_t *pRequirePorts, LOC_ProPortList_t *pProvidePorts)
{
  /*! Connection: LOPC Input => LOC Input */
//pRequirePorts->t_LOC_IN_EVSP.pt_SigHeader   = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_EgoVehDynCtrl);    /* TODO - Select relevant Signal Header */
  pRequirePorts->t_LOC_IN_EVSP.pt_SigHeader   = &(LOPC_STATIC_MEMORY.LOPC_SyncRef.t_EgoVehDynState);   /* TODO - Select relevant Signal Header */
  pRequirePorts->t_LOC_IN_EVSP.pt_EVS         = &t_LOPC_IN_EVS;

  pRequirePorts->t_LOC_IN_LVCP.pt_SigHeader   = &(pt_LOPC_IN_LVCP->sSigHeader);
  pRequirePorts->t_LOC_IN_LVCP.pt_LVC         = &(pt_LOPC_IN_LVCP->t_LVC);

  /*! Connection: LOP Output => LOC Input */
  pRequirePorts->t_LOC_IN_IVCP.pt_IVC         = &t_LOPC_LOC_IVC;


  /*! Connection: LOC Output => LOPC Output */
  pProvidePorts->t_LOC_OUT_EVCP.pt_SigHeader  = &(pt_LOPC_OUT_EVCP->sSigHeader);
  pProvidePorts->t_LOC_OUT_EVCP.pt_EVC        = &(pt_LOPC_OUT_EVCP->t_EVC);

  pProvidePorts->t_LOC_OUT_LVSP.pt_SigHeader  = &(pt_LOPC_OUT_LVSP->sSigHeader);
  pProvidePorts->t_LOC_OUT_LVSP.pt_LVS        = &(pt_LOPC_OUT_LVSP->t_LVS);

  /*! Connection: LOC Output => LOP Input */
  pProvidePorts->t_LOC_OUT_IVSP.pt_IVS        = &t_LOPC_LOC_IVS;
}


/*************************************************************************************************************************
  Functionname:    LOPC_v_Assign_LOC_Input_Ports                                                                        */ /*!

  @brief           Transformation and Assignment of existing Input Ports to generic LOC Ports

  @return          -

  @param           - 

  @pre             None ?
  @post            No changes ?

  @created         23.06.2017
  @changed         23.06.2017

  @author          Wolfgang Borgs |  | +49 (8382) 9699-839
*************************************************************************************************************************/
static void LOPC_v_Assign_LOC_Input_Ports (LOC_ReqPortList_t *pRequirePorts)
{
  if (pRequirePorts->t_LOC_IN_EVSP.pt_SigHeader->eSigStatus == AL_SIG_STATE_OK)
  {
    t_LOPC_IN_EVS.b_Valid = TRUE;
    t_LOPC_IN_EVS.b_Standstill = pt_LOPC_IN_EgoVehDynCtrl->KinCtrlDynInput.stand_still_detected;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
    t_LOPC_IN_EVS.f_LongVelocity = pt_LOPC_IN_EgoVehDynState->Longitudinal.Velocity;
    t_LOPC_IN_EVS.f_LongAcceleration = pt_LOPC_IN_EgoVehDynState->Longitudinal.Accel;
#else
    t_LOPC_IN_EVS.f_LongVelocity = pt_LOPC_IN_EgoVehDynState->Longitudinal.MotVar.Velocity;
    t_LOPC_IN_EVS.f_LongAcceleration = pt_LOPC_IN_EgoVehDynState->Longitudinal.MotVar.Accel;
#endif
  }
  else
  {
    t_LOPC_IN_EVS.b_Valid = FALSE;
    t_LOPC_IN_EVS.b_Standstill = FALSE;
    t_LOPC_IN_EVS.f_LongVelocity = 0.0f;
    t_LOPC_IN_EVS.f_LongAcceleration = 0.0f;
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    LOPC_v_SetFrameData                                                                              */ /*!

  @brief           Component state/opmode is set

  @description     Component state/opmode is set

@startuml
Start
partition LOPC_v_SetFramedata(){
If (Required ports are not equal to Null) Then (True) 
:Store Vehicle Operation Control Mode data;
Else (False) 
:Store LOPC operation mode as Shut Down and so simultaneously set LOPC state to Init;
Endif
}
end
@enduml

  @return          static void

  @param[in]       pRequirePorts : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             None ?
  @post            No changes ?

  @created         27.01.2017
  @changed         27.01.2017


  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOPC_v_SetFrameData( const LOPC_ReqPortList_t * pRequirePorts ) 
{
  if ((pRequirePorts != NULL)&&
#if (FCT_CFG_ACT_CODE_VERSION)
    (pRequirePorts->pt_LOPC_IN_Ctrl != NULL)
#else
    (pRequirePorts->pVehCtrlData != NULL)
#endif
    )
  {
#if (FCT_CFG_ACT_CODE_VERSION)
    LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCOpMode = pRequirePorts->pt_LOPC_IN_Ctrl->OpMode;
#else
    LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCOpMode = pRequirePorts->pVehCtrlData->OpMode;
#endif
  }
  else
  {
    LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCOpMode = FCT_MOD_SHUTDOWN;
    LOPC_v_SignalErrorShutdown(FALSE);
  }
  LOPC_STATIC_MEMORY.LOPC_Frame.uiCycleCounter++;

  /* setup sub-module version numbers */

  LOPC_STATIC_MEMORY.LOPC_Frame.Versions.LOPC_VERSION_AS_TEXT     = (uint32)LOPC_SW_VERSION_NUMBER; 
  LOPC_STATIC_MEMORY.LOPC_Frame.Versions.uiLopc                   = (uint32)LOPC_SW_VERSION_NUMBER; 

}

/*************************************************************************************************************************
  Functionname:    LOPC_v_Exec                                                                                 */ /*!

  @brief           LOPC component exec function for vehicle data

  @description     Main function for vehicle data cycle. 
                   It updates Frame Data and set OpMode.
                   Sets the process states for all subcomponents.
                   Sets up the input port header sync structure.
                   Sets up port pointers.
                   Sets up the signal headers of all provide ports
                   Starts KMC
                   Processes meas freezes

@startuml
start
Partition LOPC_v_Exec(){

: Update Frame Data and set Operation modes;
: Set operation modes of sub functions and also set the process states of Sub Functions;
: Set up the Input Port header sync structure;
If (LOPC State and lOPC Opmode are not Shutdwon) Then (true)
     If (LOPC state is Init) Then (True)
     : Call LOPC_v_Init algo function;
     Else (false)
     : Boolean bfirstcycledone set to true;
     Endif
     : KMC ports are setup , Signal Headers of Provide ports are setup;
     : KMC_ProcessFunction is called and Measfreeze are done;
     : LOPC is set to initialised;
Else (false)
: Sigheader of provide ports are set to error;
: Call LOPC_v_Init algo function;
: LOPC is set to not Initialised;
Endif
}
End
@enduml


  @return          -

  @param[in]       p_RequirePorts : 
  @param[in]       t_OpMode : 
  @param[in]       *p_ServiceFuncts : 

  @glob_in         -
  @glob_out        -

  @c_switch_part        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_MEASUREMENT \n
                        @ref defined \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_VEH_CFG_VEH_SIG_INPUT \n
                        @ref FCT_CFG_SEN2VEH_ACC_OOI_PORT \n
                        @ref FCT_CFG_ACC_HEADWAY_PLANNER \n
                        @ref FCT_CFG_TCI \n
                        @ref FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT \n
                        @ref FCT_VEH_CFG_USE_LODMC_OUTPUT \n
                        @ref FCT_CFG_SLA_FEATURE \n
                        @ref FCT_CFG_SEN2VEH_ACC_OOI_PORT \n
                        @ref FCT_CFG_ACC_HEADWAY_PLANNER \n
                        @ref CFG_ACC_LEVER_INPUT \n
                        @ref FCT_VEH_CFG_VEH_SIG_INPUT \n
                        @ref FCT_CFG_ACT_CODE_VERSION \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
                        @ref FCT_CFG_ACT_CODE_VERSION \n
                        @ref FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL    : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT             : FCT switch for LOPC Component for ACC

  @pre             SLATE, LOHP component exec functions completed
  @post            Signals copied from LOPC output to HMI/Actuators

  @created         24.01.2017
  @changed         24.01.2017

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-145-0008a220

  @InOutCorrelation     Covered in plantuml design

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n
                   Test of QAC level 2 "critical" warnings (static module test).

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void LOPC_v_Exec(const LOPC_ReqPortList_t * p_RequirePorts, const LOPC_ProPortList_t * p_ProvidePorts, const FCT_OP_MODE_t t_OpMode, const AS_t_ServiceFuncts *p_ServiceFuncts)
#else
void LOPC_v_Exec(const LOPC_ReqPortList_t * p_RequirePorts, const LOPC_ProPortList_t * p_ProvidePorts, const FCT_OP_MODE_t t_OpMode)
#endif
{
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
  const float32 fCycleTimelopc = FCT_VEH_TARGET_CYCLE_TIME;
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
  if (p_ServiceFuncts != NULL)
  {
    /* Sends RTA-Start event for whole procedure runtime */
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOPC_RTA_PROCESS, 0);
    /* Sends RTA-Start event for data preparation runtime */
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOPC_RTA_PREPRE_PROCESS, 0);
  }
#endif

  /*---------------------------------------------------------------------------*/
  /* Start data preparation                                                    */
  /*---------------------------------------------------------------------------*/

  /* update Frame Data and set OpMode */
  LOPC_v_SetFrameData(p_RequirePorts);

  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  /* set the process states for all subcomponents */
  LOPC_v_ProcessStates(t_OpMode);
  
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  LOPC_pServiceFuncts = p_ServiceFuncts;
#endif

  /* check for NULLpointer => trigger ErrorShutdown */
  LOPC_v_CheckPorts(p_RequirePorts, p_ProvidePorts /* Includes Error Management and OP-Mode-Changing */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    , &AlgoErrorBuffer
#endif
    );

  /* setup the input port header sync structure */
  LOPC_v_SetupSyncRef(p_RequirePorts); 

  if ((LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState != LOPC_ERROR) && (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState != LOPC_SHUTDOWN))
  {
    /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
    /*Init in init Mode*/
    if (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_INIT)
    {
      LOPC_STATIC_MEMORY.LOPC_Frame.bFirstCycleDone = FALSE;
    }
    else
    {
      LOPC_STATIC_MEMORY.LOPC_Frame.bFirstCycleDone = TRUE;
    }

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
    if ( LOPC_v_CheckInputUpdate(p_RequirePorts, &LopcInputCounters,FCT_VEH_CYCLE_TIME, fCycleTimelopc) != 0u )   /*error condition*/
    {
      LOPC_v_SetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
    }
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

    /* Opmode indicates liveliness => setup port pointers */
#if (FCT_CFG_ACT_CODE_VERSION)
    LOPC_v_SetupPorts(p_RequirePorts, p_ProvidePorts);
    LOPC_v_Set_LOP_Ports(&t_LOP_ReqPortList, &t_LOP_ProPortList);
    LOPC_v_Set_LOC_Ports(&t_LOC_ReqPortList, &t_LOC_ProPortList);
#else /* Legacy code */
    LOPC_v_SetupKMCPorts(p_RequirePorts, p_ProvidePorts);
#endif

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start */
    if ((p_ServiceFuncts != NULL) && ((p_ServiceFuncts->pfMeasStartFuncCycle) != NULL))
    {
      (p_ServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
    }
#endif
    /* set all the signal headers of all provide ports to invalid*/
   LOPC_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);
   LOPC_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);
    /* Sends RTA-Start event for Longitudinal control runtime */
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOPC_RTA_PREPRE_PROCESS, 0);
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOPC_RTA_KMC_PROCESS, 0);
#endif

#if (FCT_CFG_ACT_CODE_VERSION)
    /* New architecture */
    /* Call Process of LOP Subcomponent */
    LOP_v_Process(&t_LOP_ReqPortList, &t_LOP_ProPortList);

    /* Transform input port members from existing port to generic LOC port */
    LOPC_v_Assign_LOC_Input_Ports (&t_LOC_ReqPortList);

    /* Call Process of LOC Subcomponent */
    LOC_v_Process(&t_LOC_ReqPortList, &t_LOC_ProPortList);

#else /* Legacy code */
    p_ProvidePorts->pLongCtrlOutput->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
    p_ProvidePorts->pFctVehLongOut->uiVersionNumber = FCT_VEH_2_SEN_INFO_VERSION;

    KMC_v_Process((times_t)(FCT_VEH_CYCLE_TIME * ((float32)Time_s)),
                  LOPC_pEgoDynRaw,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                  &LOPC_pVehSig->PowerTrain,
#else
    #error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
#if (CFG_ACC_LEVER_INPUT)
                  LOPC_pAccLever,
#endif
                  LOPC_pLongCtrlResp,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                  LOPC_pAccDisplayObj,
                  LOPC_pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                  LOPC_pAccOOIData,
#endif
#if (FCT_CFG_SLA_FEATURE)
                  LOPC_pSLAData,
#endif

                  LOPC_pFctVehLongOut,
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
                  LOPC_pLoDmcOut,
#endif
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
                  LOPC_pHeadOutputCustom,
#endif
                  LOPC_pLongCtrlOutput);

/* Run the Traffic Continuation Indication (TCI) process function */
#if (FCT_CFG_TCI)
  p_ProvidePorts->pTCIOutput->uiVersionNumber = TCIOutput_INTFVER;

  TCI_v_Process(LOPC_pLongCtrlResp,
                LOPC_pEgoDynRaw,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                LOPC_pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                LOPC_pAccOOIData,
#endif
                LOPC_pAccDisplayObj,
#endif
                LOPC_pLongCtrlOutput,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                  &LOPC_pVehSig->PowerTrain,
#else
    #error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
                LOPC_pTCIInput,
                LOPC_pTCIOutput
                );
#endif  /* FCT_CFG_TCI */
#endif /* FCT_CFG_ACT_CODE_VERSION */

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOPC_RTA_KMC_PROCESS, 0);
#endif

#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
    LOPC_v_CheckProvideHeaders(p_RequirePorts, p_ProvidePorts); 
#endif
    /* Set all signal header values again to avoid errors if a component accidentialy overwrite the SigHeader*/
    LOPC_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);
	
#if (FCT_MEASUREMENT)
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-Start event for Process Measfreeze runtime */
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOPC_RTA_PROCESSFREEZE, 0);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTVeh_v_LOPCSetCompState (LOPC_pCompState, p_RequirePorts->pVehCtrlData->OpMode, AlgoErrorBuffer);
#endif

    /* Filling sig headers for oprovide ports based on component state */
    if (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_RUN)
    {
      LOPC_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_OK);
    }
    else if (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_INIT)
    {
      LOPC_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INIT);
    }
    else
    {
      LOPC_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);
    }

    /* Process meas freezes */
    LOPC_v_ProcessMeasFreeze();

    /*computation chain ran through. FCT Vehicle is initialized or running.*/
    b_LopcIsInitialized  = TRUE;

    /* Sends RTA-End event for Longitudinal control runtime */
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOPC_RTA_PROCESSFREEZE, 0);
#endif
#endif /* FCT_MEASUREMENT */
  }
  else  /************************* end of non-error path, beginning of error path *************************/
  {
    /* Component in state ERROR/SHUTDOWN => fill invalidate the available provide ports and fill whole sigHeader */

    LOPC_v_SetErrorProvidePorts(p_ProvidePorts);
#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    if ((p_ServiceFuncts != NULL) && (p_ServiceFuncts->pfMeasStartFuncCycle != NULL))
    {
      /* send MTS Freeze Cycle Start if Service is available */
      (p_ServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
    }
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /*ERROR path! Need to check existence of pointers*/
    if (LOPC_pCompState != NULL)
    {
      if ( (p_RequirePorts != NULL) && (p_RequirePorts->pVehCtrlData != NULL) )
      {
        LOPC_v_SetCompState (LOPC_pCompState, p_RequirePorts->pVehCtrlData->OpMode, AlgoErrorBuffer);
      }
      else
      {
        LOPC_v_SetCompState (LOPC_pCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
      }
    }
#endif
    /*make sure in error case init of sub components is performed next cycle*/
    b_LopcIsInitialized = FALSE;
    LOPC_STATIC_MEMORY.LOPC_Frame.bFirstCycleDone = FALSE;

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    if (p_ServiceFuncts != NULL)
    {
      /* Sends RTA-End event for data preparation runtime in errorcase*/
      LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOPC_RTA_PROCESS, 0);
    }
#endif
  } /*********************** end of error path, beginning common *******************************/

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
   if (p_ServiceFuncts != NULL)
   {
     /* Sends RTA-Start event for Frame Measfreeze runtime */
     LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_FCT, LOPC_RTA_FRAMEFREEZE, 0);
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
     LOPC_v_FrameFreeze();
   }
#else
   LOPC_v_FrameFreeze();
#endif
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
   if (p_ServiceFuncts != NULL)
   {
     /* Sends RTA-End event for Frame Measfreeze runtime */
     LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOPC_RTA_FRAMEFREEZE, 0);
     /* Sends RTA-End event for whole procedure runtime */
     LOPC_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_FCT, LOPC_RTA_PROCESS, 0);
   }
#endif
}
#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

/** @} end defgroup */

