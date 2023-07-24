/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_main.c

DESCRIPTION:               Main frame functions for LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.40 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lohp_main Frame_lohp_main
@ingroup    lohp_base_frame
@brief      Main functions for LOHP component
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lohp.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

/*! Fct sen ACC and it's subcomponents initialization status */
SET_MEMSEC_VAR(b_LOHPIsInitialized)
boolean b_LOHPIsInitialized = FALSE;

/* Input Port Measurement Counter struct */
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*PRQA S 3218 2*/ /* 20150827 CO: kept here for better maintainability */
SET_MEMSEC_VAR(t_LOHPInputCounters)
static FCTSenHC_InputMeasCounter_t t_LOHPInputCounters = {0};
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(LOHP_pServiceFuncts)
const AS_t_ServiceFuncts *LOHP_pServiceFuncts;
#endif

/* Meas freeze reference */
SET_MEMSEC_VAR(t_LOHP_SyncRef)
LOHP_SyncRef_t t_LOHP_SyncRef;

/*! Fame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(t_LOHPFrame)
LOHPFrame_t t_LOHPFrame;


#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

/*! Declaration of pointers to LOHP input ports for access within this component */
SET_MEMSEC_CONST(pt_LOHP_IN_TCCP)
const TargetControlCommandPort_t *pt_LOHP_IN_TCCP;

/*! Real existing DMC port */
SET_MEMSEC_CONST(pt_LOHP_IN_EgoVehDynCtrl)
const LongCtrlInput_t *pt_LOHP_IN_EgoVehDynCtrl;

/*! Real existing VDY port */
SET_MEMSEC_CONST(pt_LOHP_IN_EgoVehDynState)
const VehDyn_t *pt_LOHP_IN_EgoVehDynState;

/*! Real existing OOI port */
SET_MEMSEC_CONST(pt_LOHP_IN_TarVehDynState)
const FCTSenAccOOI_t *pt_LOHP_IN_TarVehDynState;

/*! Real existing HC Data port */
SET_MEMSEC_CONST(pt_LOHP_IN_HC_Data)
const SLATE_HC_Data_t *pt_LOHP_IN_HC_Data;

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*! Real existing Signal Performance Monitoring port */
SET_MEMSEC_CONST(pt_LOHP_IN_SysPerfMonitor)
const SysPerfMonStates_t *pt_LOHP_IN_SysPerfMonitor;
#endif

/*! Declaration of generic LOHP input ports for access within this component */
SET_MEMSEC_VAR(t_LOHP_IN_EVI)
LOHP_EgoVehicleInfo_t t_LOHP_IN_EVI;

SET_MEMSEC_VAR(t_LOHP_IN_TVI)
LOHP_TargetVehicleInfo_t t_LOHP_IN_TVI;

/*! Declaration of pointers to LOHP ports for access within this component */
#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_CONST(pt_LOHP_IN_TFSP)
  const TargetFollowStatePort_t *pt_LOHP_IN_TFSP;

  SET_MEMSEC_VAR(pt_LOHP_OUT_TFCP)
  TargetFollowCommandPort_t *pt_LOHP_OUT_TFCP;
#endif

/*! Declaration of pointers to LOHP output ports for access within this component */
SET_MEMSEC_VAR(pt_LOHP_OUT_TCSP)
TargetControlStatePort_t *pt_LOHP_OUT_TCSP;

#else   /* GEN 3 */

/* Pointers to the input/output data of the FCT component */
SET_MEMSEC_CONST(LOHP_pSenCtrlData)
const FCTCtrlData_t           * LOHP_pSenCtrlData;
//SET_MEMSEC_CONST(FCTSEN_pACCEgoDynObjSync)
//const VehDyn_t                * FCTSEN_pACCEgoDynObjSync;
SET_MEMSEC_CONST(LOHP_pEgoDynRaw)
const VehDyn_t                * LOHP_pEgoDynRaw;
SET_MEMSEC_CONST(LOHP_pGlobEgoStatic)
const VehPar_t                * LOHP_pGlobEgoStatic;
#if (FCT_CFG_EM_FCT_CYCLEMODE)
SET_MEMSEC_CONST(LOHP_pEmFctCycleMode)
const EmFctCycleMode_t        * LOHP_pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
SET_MEMSEC_CONST(LOHP_pEmGenObjList)
const EM_t_GenObjectList      * LOHP_pEmGenObjList;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
SET_MEMSEC_CONST(LOHP_pEmARSObjList)
const EM_t_ARSObjectList      * LOHP_pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
SET_MEMSEC_CONST(LOHP_pEmCamObjList)
const EM_t_CamObjectList      * LOHP_pEmCamObjList;
#endif
#else /* FCT_USE_EM_GENERIC_OBJECT_LIST */
SET_MEMSEC_CONST(LOHP_pEmObjList)
const ObjectList_t            * LOHP_pEmObjList;
#endif /* FCT_USE_EM_GENERIC_OBJECT_LIST */
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
SET_MEMSEC_CONST(LOHP_pPubFctObjList)
const AssessedObjList_t             * LOHP_pPubFctObjList;
#endif
#endif /* FCT_CFG_OBJECT_LIST_PROC */

#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
/* Longitudinal control input ports */
//const FctVeh2SenInfo_t        * pFctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
SET_MEMSEC_CONST(LOHP_pFctVehLongOut)
const FctVeh2SenInfo_t             * LOHP_pFctVehLongOut;
#endif

#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_CONST(LOHP_pAlignmentMonInput)
const ALN_S_Monitoring_t      * LOHP_pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif  

#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//const VehSig_t                * pVehSig;            /*!< Direct access to vehicle signals */
SET_MEMSEC_CONST(LOHP_pVehSig)
const VehSig_t             * LOHP_pVehSig;
#endif

#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC))
/* customer specific input/output */
SET_MEMSEC_CONST(LOHP_pCustomOutputInput)
const FCTCustomOutput_t        * LOHP_pCustomOutputInput;     /*!< FCT custom output */
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
SET_MEMSEC_CONST(LOHP_pBswAlgoParameters)
const BSW_s_AlgoParameters_t  * LOHP_pBswAlgoParameters; /*!< Input algo parameters from BSW */
#endif

#if (FCT_CFG_SLATE_COMPONENT)
SET_MEMSEC_CONST(LOHP_pSLATEData)
const SLATE_HC_Data_t     * LOHP_pSLATEData;        /*!< SLATE to HC input data */
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
SET_MEMSEC_CONST(LOHP_pAccOOIData)
const FCTSenAccOOI_t        * LOHP_pAccOOIData;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
SET_MEMSEC_CONST(LOHP_pCustomInput)
const FCTCustomInput_t        * LOHP_pCustomInput;
#endif

/* Provide ports */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(LOHP_pCompState)
AlgoCompState_t             * LOHP_pCompState;
#endif
SET_MEMSEC_VAR(LOHP_pAccDisplayObj)
acc_object_t                * LOHP_pAccDisplayObj; /*!< ACC_DISPLAY_OBJECT output from LOHP */
SET_MEMSEC_VAR(LOHP_pAccOutput)
acc_output_data_t           * LOHP_pAccOutput;  /*!< ACC_OUTPUT_DATA from LOHP */


#if (FCT_CFG_RUNTIME_MEAS)
/*! FCT ACC time measurement info */
SET_MEMSEC_VAR(t_LOHP_RuntimeInfo)
FCT_HCRuntimeInfo_t t_LOHP_RuntimeInfo;
#endif

#if (FCT_CFG_RUNTIME_MEAS)
/* Meas freeze structure for FCT ACC runtime info */ 
SET_MEMSEC_VAR(t_LOHP_Runtime_MeasInfo)
static const MEASInfo_t t_LOHP_Runtime_MeasInfo = {
    FCT_MEAS_ID_HC_RUNTIME_DEBUG,      /* VirtualAddress */
    sizeof(FCT_HCRuntimeInfo_t),      /* Length */
    FCT_HC_MEAS_FUNC_ID,               /* FuncID */
    FCT_HC_MEAS_FUNC_CHAN_ID           /* FuncChannelID */
};
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

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

/* Port Lists for TC Subcomponent */
SET_MEMSEC_VAR(t_TC_ReqPortList)
TC_ReqPortList_t t_TC_ReqPortList;

SET_MEMSEC_VAR(t_TC_ProPortList)
TC_ProPortList_t t_TC_ProPortList;

SET_MEMSEC_VAR(t_OOI_0_DEF)
AccOOINextLong_t t_OOI_0_DEF = {0};

SET_MEMSEC_VAR(t_OOI_N_DEF)
AccOOI_t t_OOI_N_DEF = {0};

#endif /* FCT_CFG_ACT_CODE_VERSION */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

static void LOHP_v_SetFrameData(const FCTSenFrame_t * p_FCTSenFrame);
static void LOHP_v_SetupSyncRef(const LOHP_ReqPortList_t *pRequirePorts);
static void LOHP_v_SetupPorts(const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts);

static void LOHP_v_Set_TC_Ports(TC_ReqPortList_t *pRequirePorts, TC_ProPortList_t *pProvidePorts);
static void LOHP_v_Assign_TC_Input_Ports (void);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void LOHP_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
static void LOHP_v_SetCompState (AlgoCompState_t * const p_CompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
static void LOHP_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void LOHP_v_CheckProvideHeaders(const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts);
#endif

/*! Utility function to set signal header to error */
static void LOHP_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);
static void LOHP_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void LOHP_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void LOHP_v_SetProvideHeaderStates(const LOHP_ProPortList_t *pProvidePorts, AlgoSignalState_t eSigState);
static void LOHP_v_SetProvideHeader(const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts);

#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
static void LOHP_v_AlgoServiceAddEvent( const RTA_t_Events RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#else
static void LOHP_v_AlgoServiceAddEvent( const AS_t_RtaEventType RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#endif

static void LOHP_v_PreProcessing(const LOHP_ReqPortList_t * pRequirePorts, const LOHP_ProPortList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  , GenAlgoQualifiers_t *const pErrorBuffer

#endif 
  );

static void LOHP_v_CheckPorts(const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
                                , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                             );

static void LOHP_v_SetErrorProvidePorts (const LOHP_ProPortList_t * pProvidePorts);

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 LOHP_v_CheckInputUpdate(const LOHP_ReqPortList_t *pRequirePorts, Lohp_InputMeasCounter *pLoccInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen);
static uint32 LOHP_v_CheckPortUpdated(const AlgoDataTimeStamp_t *pInputPortMeasCycle, sMeasCycleMonitor *pLastMeasCycle, float32 fTargetCycleTime, uint8 iAcceptableDrops);
#endif

#else   /* GEN 3 */

static void LOHP_v_SetupPorts(const reqLOHPPrtList_t * pRequirePorts, const LOHPProPort_t * pProvidePorts);

#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
static void LOHP_v_AlgoServiceAddEvent( const RTA_t_Events RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#else
static void LOHP_v_AlgoServiceAddEvent( const AS_t_RtaEventType RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#endif

#if (FCT_CFG_RUNTIME_MEAS)
static void LOHP_v_RuntimeMeasInit(void);
#endif
#if (FCT_CFG_RUNTIME_MEAS)
static void LOHP_v_AlgoServiceAddEvent_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID);
#endif

static void LOHP_v_SetFrameData( const FCTSenFrame_t * p_FCTSenFrame
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  , GenAlgoQualifiers_t *const pErrorBuffer
#endif
  );

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void LOHP_v_SetCompState (AlgoCompState_t * const pSenCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

static void LOHP_v_CheckPorts( const reqLOHPPrtList_t * pRequirePorts,
  const LOHPProPort_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
  , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  , GenAlgoQualifiers_t *const pErrorBuffer
#endif
  );

#if (FCT_CFG_USE_DEM)
static void LOHP_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus);
#endif /*FCT_CFG_USE_DEM*/

static void LOHP_v_SetupSyncRef(const reqLOHPPrtList_t * pRequirePorts);
static void LOHP_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);
static void LOHP_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void LOHP_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void LOHP_v_SetErrorProvidePorts (const LOHPProPort_t * pProvidePorts);
static void LOHP_v_SetProvideHeaderStates(const LOHPProPort_t * pProvidePorts, AlgoSignalState_t eSigState);
static void LOHP_v_SetProvideHeader(const reqLOHPPrtList_t * pRequirePorts, const LOHPProPort_t * pProvidePorts);

#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
static void LOHP_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void LOHP_v_CheckProvideHeaders(reqLOHPPrtList_t const * const pRequirePorts, LOHPProPort_t const * const pProvidePorts);
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetOperationMode                                                                          */ /*!

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
void LOHP_v_SetOperationMode(const LOHPState_t t_OpModeValue)
{
  t_LOHPFrame.eLOHPState = t_OpModeValue;
}

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             LOHP_v_SetDem                                  */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTVehServiceFuncts connected to input service ports
  @todo           review
  @author         Christian Obst
**************************************************************************** */
void LOHP_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pFCTVehServiceFuncts != NULL) && (pFCTVehServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pFCTVehServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    LOHP_v_Exec                                                                                 */ /*!

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
void LOHP_v_Exec(const LOHP_ReqPortList_t * p_RequirePorts, const LOHP_ProPortList_t * p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame, const AS_t_ServiceFuncts *p_ServiceFuncts)
#else
void LOHP_v_Exec(const LOHP_ReqPortList_t * p_RequirePorts, const LOHP_ProPortList_t * p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame)
#endif
{

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  if (p_ServiceFuncts != NULL)
  {
    LOHP_pServiceFuncts = p_ServiceFuncts;
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  LOHP_v_RuntimeMeasInit();
#endif

  /*---------------------------------------------------------------------------*/
  /* Start longitudinal controller processing                                  */
  /*---------------------------------------------------------------------------*/

  /* Sends RTA-Start Event for whole procedure runtime */
  LOHP_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, LOHP_RTA_PROCESS, 0);
  /* data preparation runtime */
  LOHP_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, LOHP_RTA_PREPRE_PROCESS, 0);

  /* set the FrameData for Sensor */
  LOHP_v_SetFrameData(p_FCTSenFrame);

  /*! Set operation mode of LOHP based on FCT OpMode  */
  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  LOHP_v_ProcessStates(t_LOHPFrame.eFCTOpMode);

  LOHP_v_CheckPorts(p_RequirePorts, p_ProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
    , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    , &AlgoErrorBuffer
#endif
    );

  /* setup sync ref no matter what (sync in running and non running mode)*/
  LOHP_v_SetupSyncRef(p_RequirePorts);

  if (t_LOHPFrame.eLOHPState != FCT_SEN_ERROR)
  {
    /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
    /* Ports OK, CtrlData indicates no error */
    LOHP_v_SetupPorts(p_RequirePorts, p_ProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start */
    if ((LOHP_pServiceFuncts->pfMeasStartFuncCycle) != NULL) /*PRQA S 0505*//* pServiceFuncts can't be NULL here: checked in FCTSenCheckPorts */
    {
      (LOHP_pServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_HC_MEAS_FUNC_CHAN_ID));
    }
#endif

    /* set all the signal headers of all provide ports to invalid*/
    LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);
    LOHP_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);

    /* Send RTA-End Event for data preparation runtime in non-error state*/
    LOHP_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, LOHP_RTA_PREPRE_PROCESS, 0);
    /* Send RTA-Start Event for data preprocessing runtime in non-error state*/
    LOHP_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, LOHP_RTA_PRE_PROCESS, 0);

    /* FCT Main Time */
    LOHP_v_PreProcessing(p_RequirePorts, p_ProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
      , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      , &AlgoErrorBuffer
#endif
      );

    /* Send RTA-End Event for data preprocessing runtime in non-error state*/
    LOHP_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, LOHP_RTA_PRE_PROCESS, 0);
    
    /* Send RTA-Start Event for Longitudinal Processing runtime */
    LOHP_v_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, LOHP_RTA_HP_PROCESS, 0);
  
    /* Assign Port Lists of CC Subcomponent */
    LOHP_v_Set_TC_Ports(&t_TC_ReqPortList, &t_TC_ProPortList);

    /* Assign Generic Input Port Members for TC Subcomponent */
    LOHP_v_Assign_TC_Input_Ports ();

    /* Call Process of TC Subcomponent */
    TC_v_Process(&t_TC_ReqPortList, &t_TC_ProPortList);

    /* Send RTA-End Event for Longitudinal Processing runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd, LOHP_RTA_HP_PROCESS, 0);
  
    /* Send RTA-Start Event for Post processing runtime */
    //LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_HC_POST_PROCESS, 0);

    /* Send RTA-End Event for Post processing runtime */
    //LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_HC_POST_PROCESS, 0);
    /* Send RTA-Start Event for Process Measfreeze runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  LOHP_RTA_PROCESSFREEZE, 0);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOHP_v_SetCompState (p_ProvidePorts->pSenCompState, p_RequirePorts->pSenCtrlData->OpMode, AlgoErrorBuffer);
#endif

#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
    /* if enabled this function checks all SigHeaders */
    LOHP_v_CheckProvideHeaders(p_RequirePorts, p_ProvidePorts);
#endif
    /* setup all provide port headers (cyclecounter, measurementcounter, timestamp) */
    LOHP_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);

    /* Filling sig headers for provide ports based on component state */
    if (t_LOHPFrame.eLOHPState == LOHP_RUN)
    {
      LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_OK);
    }
    else if (t_LOHPFrame.eLOHPState == LOHP_INIT)
    {
      LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INIT);
    }
    else
    {
      LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);
    }

    /* Output Meas Freezes */
#if (FCT_MEASUREMENT)
    /* Process other meas freezes */
    LOHP_v_ProcessMeasFreeze(p_ProvidePorts);
#endif /* FCT_MEASUREMENT */

    /*! Computation chain ran through. FCT Sensor is initialized or running.*/
    b_LOHPIsInitialized = TRUE;

    /* Send RTA-End Event for Process Measfreeze runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  LOHP_RTA_PROCESSFREEZE, 0);
  } /* (t_LOHPFrame.eLOHPState != FCT_SEN_ERROR) */
  else
  {
    /* error occurred, set available provide ports */
    LOHP_v_SetErrorProvidePorts(p_ProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start if Service is available */
    if ((LOHP_pServiceFuncts != NULL) && (LOHP_pServiceFuncts->pfMeasStartFuncCycle != NULL))
    {
      (LOHP_pServiceFuncts->pfMeasStartFuncCycle ) ((AS_t_MeasFuncID) (FCT_HC_MEAS_FUNC_CHAN_ID));
    }
#endif

    LOHP_v_AlgoInit();

#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /*ERROR path! need to check existence of pointers*/
    if (p_ProvidePorts != NULL) 
    {
      if ( (p_RequirePorts != NULL) && (p_RequirePorts->pSenCtrlData != NULL) )
      {
        LOHP_v_SetCompState (p_ProvidePorts->pSenCompState, p_RequirePorts->pSenCtrlData->OpMode, AlgoErrorBuffer);
      }
      else
      {
        /*assuming running status from scheduler ==> pointer error, Frame-mode is INIT ==> Input error is set*/
        LOHP_v_SetCompState (p_ProvidePorts->pSenCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
      }
    }
#endif

    /*! Make sure in error case init of sub components is performed next cycle*/
    //b_LOHPIsInitialized = FALSE; // redundant to LOHP_v_AlgoInit

    /* Send RTA-End Event for data preparation runtime in error state */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  LOHP_RTA_PREPRE_PROCESS, 0);
  }

  /* Send RTA-Start Event for Frame Measfreeze runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  LOHP_RTA_FRAMEFREEZE, 0);

#if (FCT_MEASUREMENT)
  /* Freeze frame meas data in all cases, even in case of Error*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Safeguard for NULL-Pointer */
  if ((p_ServiceFuncts != NULL) 
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    && (pServiceFuncts->pfMeasStartFuncCycle != NULL)
#endif
    && (p_ServiceFuncts->pfMeasFreeze != NULL)
    && (LOHP_pServiceFuncts != NULL)
    && (LOHP_pServiceFuncts->pfMeasFreeze != NULL) )
  {
    LOHP_v_FrameFreeze();
  }
#else
  LOHP_v_FrameFreeze();
#endif
#endif

  /* Send RTA-End Event for Frame Measfreeze runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  LOHP_RTA_FRAMEFREEZE, 0);
  /* Sends RTA-End Event for whole procedure runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  LOHP_RTA_PROCESS, 0);

#if (FCT_CFG_RUNTIME_MEAS)
  /* Freeze FCT ACC runtime info */
  FCT_HC_FREEZE_DATA(&t_LOHP_Runtime_MeasInfo, &t_LOHP_RuntimeInfo, NULL);
#endif

}


static void LOHP_v_PreProcessing(const LOHP_ReqPortList_t * pRequirePorts, const LOHP_ProPortList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                , GenAlgoQualifiers_t *const pErrorBuffer

#endif 
                                )

{
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  _PARAM_UNUSED(pServiceFuncts);
#endif

  /* If operation mode indicates run, but we our object list is invalid, then
  force to init mode. Note: FCT_SEN_RUN Implies that InputPort pointers are valid. */
#if (FCT_CFG_USE_SIG_HEADER)
  if ((t_LOHPFrame.eLOHPState == LOHP_RUN) && (pRequirePorts->pt_LOHP_IN_Ctrl->sSigHeader.eSigStatus != AL_SIG_STATE_OK))
#else
#endif
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    LOHP_v_SignalErrorShutdown(TRUE); /*Shutdown without error*/
  }

  switch (t_LOHPFrame.eLOHPState)
  {
  case LOHP_RUN:
  case LOHP_RG_HIGH:
    /*! Set information: cycle was processed */
    t_LOHPFrame.bFirstCycleDone = TRUE;
    break;

  case LOHP_INIT:
    /* init TP frame */
    LOHP_v_AlgoInit();
    break;

  case LOHP_SHUTDOWN:
    break;

  case LOHP_ERROR:
  default:
    LOHP_v_AlgoInit();
    break;
  } /* endswitch */

#if ( (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) && (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING) )
  /*call update check*/
  if (t_LOHPFrame.eLOHPState != FCT_SEN_ACC_ERROR )
  {
    if ( LOHP_v_CheckInputUpdate(pRequirePorts, &t_LOHPInputCounters, TASK_CYCLE_TIME) != 0u)               /*error condition*/
    {
      LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
    }
  }
#endif

  _PARAM_UNUSED(pProvidePorts);
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_AlgoInit                                                                                  */ /*!

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
void LOHP_v_AlgoInit (void)
{
  /*--- VARIABLES ---*/

  t_LOHPFrame.bFirstCycleDone = FALSE;
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetFrameData                                                                              */ /*!

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
static void LOHP_v_SetFrameData(const FCTSenFrame_t * p_FCTSenFrame) 
{
    /* Store operation mode received from outside in sen frame for freezing */
  if ( (p_FCTSenFrame->eFCTState != COMP_STATE_TEMPORARY_ERROR)
    && (p_FCTSenFrame->eFCTState != COMP_STATE_NOT_RUNNING))
  {
    t_LOHPFrame.eFCTOpMode = p_FCTSenFrame->eFCTOpMode;
  }
  else
  {
    /*No error handling (e.g. DEM, CompState) is required here as all 
    ports are checked later on in LOHP_v_CheckPorts*/
    t_LOHPFrame.eFCTOpMode = FCT_MOD_SHUTDOWN;
    LOHP_v_SignalErrorShutdown(FALSE);
  }
  t_LOHPFrame.uiCycleCounter++;

  /* setup sub-module version numbers */

  t_LOHPFrame.Versions.LOHP_VERSION_AS_TEXT   = LOHP_SW_VERSION_NUMBER; //TODO:define for Locc
  t_LOHPFrame.Versions.uiLohp                 = LOHP_SW_VERSION_NUMBER; //TODO:define for Lohp

}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetupSyncRef                                                                              */ /*!

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
static void LOHP_v_SetupSyncRef(const LOHP_ReqPortList_t *pRequirePorts)
{
  /* setting whole syncref to zero */
  (void)memset(&t_LOHP_SyncRef, 0, sizeof(t_LOHP_SyncRef));

  if (pRequirePorts != NULL)
  {
    /* pt_LOHP_IN_Ctrl */
    if (pRequirePorts->pt_LOHP_IN_Ctrl != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      LOHP_v_FillSigHeader(&(t_LOHP_SyncRef.sSigHeader), &(pRequirePorts->pt_LOHP_IN_Ctrl->sSigHeader));
      LOHP_v_SetSigHeaderState(&t_LOHP_SyncRef.sSigHeader, AL_SIG_STATE_OK);

      t_LOHP_SyncRef.t_SH_CTRL = pRequirePorts->pt_LOHP_IN_Ctrl->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_LOHP_IN_TCCP */
    if (pRequirePorts->pt_LOHP_IN_TCCP != NULL)
    {
      t_LOHP_SyncRef.t_LOHP_IN_TCCP = pRequirePorts->pt_LOHP_IN_TCCP->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_HP_TFC_PORT_CNT)
    /* pt_LOHP_IN_TFSP */
    if (pRequirePorts->pt_LOHP_IN_TFSP != NULL)
    {
      t_LOHP_SyncRef.t_LOHP_IN_TFSP = pRequirePorts->pt_LOHP_IN_TFSP->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    /* pt_LOCC_IN_EgoVehDynCtrl */
    if (pRequirePorts->pt_LOHP_IN_EgoVehDynCtrl != NULL)
    {
      t_LOHP_SyncRef.t_EgoVehDynCtrl = pRequirePorts->pt_LOHP_IN_EgoVehDynCtrl->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_LOCC_IN_EgoVehDynState */
    if (pRequirePorts->pt_LOHP_IN_EgoVehDynState != NULL)
    {
      t_LOHP_SyncRef.t_EgoVehDynState = pRequirePorts->pt_LOHP_IN_EgoVehDynState->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* pt_LOCC_IN_TarVehDynState */
    if (pRequirePorts->pt_LOHP_IN_TarVehDynState != NULL)
    {
      t_LOHP_SyncRef.t_TarVehDynState = pRequirePorts->pt_LOHP_IN_TarVehDynState->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetupPorts                                                                                 */ /*!

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
static void LOHP_v_SetupPorts(const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts)
{
/*! Assignment of external pointers to LOHP input ports for access within this component */
  pt_LOHP_IN_TCCP           = pRequirePorts->pt_LOHP_IN_TCCP;
  pt_LOHP_IN_EgoVehDynCtrl  = pRequirePorts->pt_LOHP_IN_EgoVehDynCtrl;
  pt_LOHP_IN_EgoVehDynState = pRequirePorts->pt_LOHP_IN_EgoVehDynState;
  pt_LOHP_IN_TarVehDynState = pRequirePorts->pt_LOHP_IN_TarVehDynState;
  pt_LOHP_IN_HC_Data        = pRequirePorts->pt_LOHP_IN_HC_Data;

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  pt_LOHP_IN_SysPerfMonitor = pRequirePorts->pt_LOHP_IN_SysPerfMonitor;
#endif

/*! Assignment of external pointers to LOHP ports for access within this component */
#if (FCT_CFG_HP_TFC_PORT_CNT)
  pt_LOHP_IN_TFSP = pRequirePorts->pt_LOHP_IN_TFSP;
  pt_LOHP_OUT_TFCP = pProvidePorts->pt_LOHP_OUT_TFCP;
#endif

/*! Assignment of external pointers to LOHP output ports for access within this component */
  pt_LOHP_OUT_TCSP = pProvidePorts->pt_LOHP_OUT_TCSP;
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_Set_TC_Ports                                                                              */ /*!

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
static void LOHP_v_Set_TC_Ports(TC_ReqPortList_t *pRequirePorts, TC_ProPortList_t *pProvidePorts)
{
  /* pt_LOHP_IN_TCCP */
  pRequirePorts->t_TC_IN_TCCP.pt_TCC = &(pt_LOHP_IN_TCCP->t_Command);
  pRequirePorts->t_TC_IN_TCCP.pt_FD  = &(pt_LOHP_IN_TCCP->t_Degrade);

  /* t_LOHP_IN_EVI */
//pRequirePorts->t_TC_IN_EVIP.pt_SigHeader = &(t_LOHP_SyncRef.t_EgoVehDynCtrl);   /* TODO - Select correct Signal Header */
  pRequirePorts->t_TC_IN_EVIP.pt_SigHeader = &(t_LOHP_SyncRef.t_EgoVehDynState);  /* TODO - Select correct Signal Header */
  pRequirePorts->t_TC_IN_EVIP.pt_EVI = &t_LOHP_IN_EVI;

  /* t_LOHP_IN_TVI */
  pRequirePorts->t_TC_IN_TVIP.pt_SigHeader = &(t_LOHP_SyncRef.t_TarVehDynState);  /* TODO - Select correct Signal Header */
  pRequirePorts->t_TC_IN_TVIP.pt_TVI = &t_LOHP_IN_TVI;

#if (FCT_CFG_HP_TFC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    /* t_LOHP_IN_TFSP */
    pRequirePorts->at_TC_IN_TFSP[i].pt_TFS = &(pt_LOHP_IN_TFSP->at_TFS[i]);

    /* t_LOHP_OUT_TFCP */
    pProvidePorts->at_TC_OUT_TFCP[i].pt_TFC = &(pt_LOHP_OUT_TFCP->at_TFC[i]);
  }
}
#endif

  /* pt_LOHP_OUT_TCSP */
  pProvidePorts->t_TC_OUT_TCSP.pt_TCS = &(pt_LOHP_OUT_TCSP->t_State);
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_Assign_TC_Input_Ports                                                                        */ /*!

  @brief           Transformation and Assignment of existing Input Ports to generic LOC Ports

  @return          -

  @param           - 

  @pre             None ?
  @post            No changes ?

  @created         06.07.2017
  @changed         06.07.2017

  @author          Wolfgang Borgs |  | +49 (8382) 9699-839
*************************************************************************************************************************/
static void LOHP_v_Assign_TC_Input_Ports (void)
{
  t_LOHP_IN_EVI.b_Valid = TRUE;
  t_LOHP_IN_EVI.b_StandStill = pt_LOHP_IN_EgoVehDynCtrl->KinCtrlDynInput.stand_still_detected;
  t_LOHP_IN_EVI.b_Override_Accel = pt_LOHP_IN_EgoVehDynCtrl->KinCtrlDynInput.driver_override_accel_pedal;
  t_LOHP_IN_EVI.b_Override_Decel = pt_LOHP_IN_EgoVehDynCtrl->KinCtrlDynInput.driver_override_decel_pedal;
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  t_LOHP_IN_EVI.f_LongVeloReal = pt_LOHP_IN_EgoVehDynState->Longitudinal.Velocity;
  t_LOHP_IN_EVI.f_LongAcceleration = pt_LOHP_IN_EgoVehDynState->Longitudinal.Accel;
#else
  t_LOHP_IN_EVI.f_LongVeloReal = pt_LOHP_IN_EgoVehDynState->Longitudinal.MotVar.Velocity;
  t_LOHP_IN_EVI.f_LongAcceleration = pt_LOHP_IN_EgoVehDynState->Longitudinal.MotVar.Accel;
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  if (pt_LOHP_IN_SysPerfMonitor->uSPMBlockageState == AL_ERR_STATE_ACTIVE)
  {
    t_LOHP_IN_TVI.AccOOINextLong = t_OOI_0_DEF;
    t_LOHP_IN_TVI.AccOOIHiddenNextLong = t_OOI_N_DEF;
    t_LOHP_IN_TVI.AccOOINextLeft = t_OOI_N_DEF;
    t_LOHP_IN_TVI.AccOOINextRight = t_OOI_N_DEF;
    t_LOHP_IN_TVI.AccOOIHiddenNextLeft = t_OOI_N_DEF;
    t_LOHP_IN_TVI.AccOOIHiddenNextRight = t_OOI_N_DEF;
    t_LOHP_IN_TVI.OvertakeDirection = LOHP_OT_NONE;
    t_LOHP_IN_TVI.b_Valid = FALSE;
  }
  else
#endif
  {
    t_LOHP_IN_TVI.AccOOINextLong = pt_LOHP_IN_TarVehDynState->AccOOINextLong;
    t_LOHP_IN_TVI.AccOOIHiddenNextLong = pt_LOHP_IN_TarVehDynState->AccOOIHiddenNextLong;
    t_LOHP_IN_TVI.AccOOINextLeft = pt_LOHP_IN_TarVehDynState->AccOOINextLeft;
    t_LOHP_IN_TVI.AccOOINextRight = pt_LOHP_IN_TarVehDynState->AccOOINextRight;
    t_LOHP_IN_TVI.AccOOIHiddenNextLeft = pt_LOHP_IN_TarVehDynState->AccOOIHiddenNextLeft;
    t_LOHP_IN_TVI.AccOOIHiddenNextRight = pt_LOHP_IN_TarVehDynState->AccOOIHiddenNextRight;

    if (pt_LOHP_IN_HC_Data->t_SLATE_LC.b_AllowOvertake)
    {
      switch (pt_LOHP_IN_HC_Data->t_SLATE_LC.e_LCDirection)
      {
      case SLATE_LC_NONE:
      default:
        t_LOHP_IN_TVI.OvertakeDirection = LOHP_OT_NONE;
        break;

      case SLATE_LC_LEFT:
        t_LOHP_IN_TVI.OvertakeDirection = LOHP_OT_LEFT;
        break;

      case SLATE_LC_RIGHT:
        t_LOHP_IN_TVI.OvertakeDirection = LOHP_OT_RIGHT;
        break;
      }
    }
    else
    {
      t_LOHP_IN_TVI.OvertakeDirection = LOHP_OT_NONE;
    }

    t_LOHP_IN_TVI.b_Valid = TRUE;
  }
}

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             LOHP_v_SetAlgoErrorBuffer */ /*! 
  @brief          Set the Algo Error Buffer
  @description    Set the ErrorQualifier to pErrorBuffer if it is more severe than the stored one.
                  It's not possible to change to a lower priority than already set.
  @param[in]      ErrorQualifier : the Error to set
  @param[in,out]  pErrorBuffer   : pointer to the buffered error
  @pre            None
  @author         Christian Obst
**************************************************************************** */
static void LOHP_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
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
  @fn           LOHP_v_SetCompState                                  */ /*!
  @brief        Set the Algo Component State.
  @description  Set the Algo Component State based on scheduler request and internal status.
  @param[out]   p_CompState : pointer to Algo Component State that shall be set.
  @param[in]    ScheduledOpMode : operation mode given by global scheduler.
  @param[in]    BufferedQualifier : internal buffer for AlgoQualifier (error status).
  @pre          Algo ran, component error states are set.
  @return       none
  @author       Christian Obst
**************************************************************************** */
static void LOHP_v_SetCompState (AlgoCompState_t * const p_CompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
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
    p_CompState->uiAlgoVersionNumber = LOHPFrame.Versions.uiLohp;
#if COMP_STATE_INTFVER > 2u
    p_CompState->uiApplicationNumber = 0u;
    p_CompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    p_CompState->ApplicationNumber = 0u;
    p_CompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (LOHPFrame.eLOCCState)
    {
    case LOHP_INIT:
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
    case LOHP_RUN:
      p_CompState->eCompState = COMP_STATE_RUNNING;
      p_CompState->eErrorCode = COMP_ERROR_NO_ERROR;
      p_CompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case LOHP_SHUTDOWN:
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

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckProvideHeader                                                                        */ /*!

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
static void LOHP_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
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
  Functionname:    LOHP_v_CheckProvideHeaders                                                                       */ /*!

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
static void LOHP_v_CheckProvideHeaders(const LOCC_ReqPortList_t * pRequirePorts, const LOCC_ProPortList_t * pProvidePorts) 
{
  /* Todo: Write for new ports */

}
#endif

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetSigHeaderError                                                                         */ /*!

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
static void LOHP_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiCycleCounter        = t_LOHPFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_FillSigHeader                                                                             */ /*!

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
static void LOHP_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = t_LOHPFrame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetSigHeaderState                                                                         */ /*!

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
static void LOHP_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus = eSigState;
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
static void LOHP_v_SetProvideHeaderStates(const LOHP_ProPortList_t *pProvidePorts, AlgoSignalState_t eSigState) 
{
  /* Todo: Write for new ports */
  _PARAM_UNUSED(pProvidePorts);
  _PARAM_UNUSED(eSigState);
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetProvideHeader                                                                          */ /*!

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
static void LOHP_v_SetProvideHeader(const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts) 
{
  /* Todo: Write for new ports */
  _PARAM_UNUSED(pProvidePorts);
  _PARAM_UNUSED(pRequirePorts);
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_AlgoServiceAddEvent                                                                         */ /*!

  @brief           Determine runtime of FCT component based on service functions provided by Base SW.

  @description     Determine runtime of FCT component based on service functions depending on wheter pfRTAAlgoServiceAddEvent are available or not
                    If it is available this function is used otherwise the function FCTSEN_SERVICE_ADD_EVENT_FCT is called which determines the time difference between start and end events
  @return          -

  @param[in]       RtaEvtType : 
  @param[in]       u_IdLocal : 
  @param[in]       u_OptData : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_RUNTIME_MEAS : CT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers 
  @c_switch_full   FCT_CFG_RTA_PROFILING FCT_CFG_USE_SERVICE_POINTER_FUNCTS: Compiler switch used around this function/file

  @pre             -
  @post            -

  @created         04.05.2016
  @changed         04.05.2016


  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
static void LOHP_v_AlgoServiceAddEvent( const RTA_t_Events RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData)
#else
static void LOHP_v_AlgoServiceAddEvent( const AS_t_RtaEventType RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData)
#endif
{
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  if (    (LOHP_pServiceFuncts                           != NULL)
       && (LOHP_pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL) )
  {
    LOHP_pServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT60, u_IdLocal, u_OptData);
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  /* Check NULL pointer. 
  Check whether additional parameter (i.e. Object ID) is defined. This cannot be handled */
  if (    (LOHP_pServiceFuncts                     != NULL)
       && (LOHP_pServiceFuncts->pfGetTimestampuS32 != NULL) 
       && (u_OptData                                           == 0   ))
  {
    LOHP_v_AlgoServiceAddEvent_FCT( RtaEvtType, (sint32)u_IdLocal);
  }
#endif
  _PARAM_UNUSED(RtaEvtType);
  _PARAM_UNUSED(u_IdLocal);
  _PARAM_UNUSED(u_OptData);
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckPorts                                                                           */ /*!

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
static void LOHP_v_CheckPorts( const LOHP_ReqPortList_t *pRequirePorts, const LOHP_ProPortList_t *pProvidePorts
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
    || (pRequirePorts->pt_LOHP_IN_Ctrl == NULL)

    )
  {
    /* Some request port pointer is NULL => DEM and shutdown */

#if (FCT_CFG_USE_DEM)
    /*validity of service pointer isn't clear here*/
    LOHP_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /* setup the Algo Error Buffer */
    LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    /* shutdown the system */
    LOHP_v_SignalErrorShutdown(FALSE);
  }
  else
  {
    /* Verify that provide port buffer pointers are set (non-null) */
    if ((pProvidePorts == NULL) || (pProvidePorts->pt_LOHP_OUT_TCSP == NULL))
    {
#if (FCT_CFG_USE_DEM)
      /* Some provide port pointer is NULL => DEM -> shutdown */
      LOHP_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      LOHP_v_SignalErrorShutdown(FALSE);
    }
    else
    {
#if (FCT_CFG_USE_DEM)
      /* receive and provide ports are fine */
      LOHP_v_SetDem(FCTVEH_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
    }

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
    /* no NullPointer in request ports*/
    /* check for SignalState in requestPorts*/
    if(pRequirePorts->pt_LOHP_IN_EgoCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    {
      /*signal state broken -> no dem only shutdown*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /* setup the Algo Error Buffer */
      LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      /* shutdown the system */
      LOHP_v_SignalErrorShutdown(FALSE);
    }
#endif /*FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK*/
  }
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetErrorProvidePorts                                                                      */ /*!

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
static void LOHP_v_SetErrorProvidePorts (const LOHP_ProPortList_t * pProvidePorts)
{
  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pVehCompState != NULL)
    {
      LOHP_pCompState                  = pProvidePorts->pVehCompState;
#if COMP_STATE_INTFVER > 2u
      LOHP_pCompState->uiVersionNumber  = COMP_STATE_INTFVER;
#else
      LOHP_pCompState->uVersionNumber  = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      LOHP_pCompState = NULL;
    }
#endif

    /* Todo: Write for new ports */
#if (FCT_CFG_HP_TFC_PORT_CNT)
    if(pProvidePorts->pt_LOHP_OUT_TFCP != NULL)
    {
      pProvidePorts->pt_LOHP_OUT_TFCP->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
      LOHP_v_SetSigHeaderError(&pProvidePorts->pt_LOHP_OUT_TFCP->sSigHeader);
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

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckInputUpdate                                                                          */ /*!

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
static uint32 LOHP_v_CheckInputUpdate(const LOHP_ReqPortList_t *pRequirePorts, Lohp_InputMeasCounter *pLoccInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen)
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
  return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckPortUpdated                                                                          */ /*!

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
static uint32 LOHP_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
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

#else   /* GEN 3 */




/*************************************************************************************************************************
  Functionname:         LOHP_v_Exec                                                                                  */ /*!

  @brief                Main execution function of component LOHP

  @description          Execute all function processes

						@startuml
						Start
						Partition LOHP_v_Exec {
							-Sends RTA-Start Event for whole procedure runtime
							-Set the FrameData for Sensor
							-Set LOHP process state based on FCT OpMode
							-Do Checking of Input and output ports for valid pointer
							-Creates sync data for Simulation synchronization
							If(Ports are OK and CtrlData indicates no error) then (Ture)
								-Setup the Ports to local aliases for LOHP inputs and outputs
								-Set the signal headers of provide ports
								-Call LOHP process function
								-Set the state in the SigHeader for all used provide ports
								-Send RTA-End Event for data preparation runtime in non-error state
								-Call the LOHP_v_ProcessMeasFreeze
							else
								-Set error state to provid ports
								-Clear the b_LOHPIsInitialized bit 
								-Send RTA-End Event for data preparation runtime in error state
							Endif
							-Send RTA-Start Event for Frame Measfreeze runtime
							-Freezes Frame Measurement Data (SW versions)
						End	
						@enduml

  @return               -

  @param[in]            p_RequirePorts : Pointer to require ports list of LOHP [defined in frame_lohp_ext.h]
  @param[in]            p_ProvidePorts : Pointer to provide ports list of LOHP [defined in frame_lohp_ext.h]
  @param[in]            p_FCTSenFrame : Frame data from FCTSen component containing cycle time, OpMode and relevant ctrl data\n
                        [defined in fct_types.h]

  @glob_in              -
  @glob_out             @ LOHP_pSenCtrlData
                        @ LOHP_pEgoDynRaw;
                        @ LOHP_pGlobEgoStatic
                        @ LOHP_pEmFctCycleMode
                        @ LOHP_pFctVehLongOut
                        @ LOHP_pAlignmentMonInput
                        @ LOHP_pCustomOutputInput
                        @ LOHP_pCustomInput
                        @ LOHP_pBswAlgoParameters
                        @ LOHP_pSLATEData
                        @ LOHP_pAccOOIData
                        @ LOHP_pCompState
                        @ LOHP_pAccDisplayObj
                        @ LOHP_pAccOutput
                        @ b_LOHPIsInitialized
                        @ t_LOHP_SyncRef
                        @ t_LOHPFrame

  @c_switch_part        @ref FCT_CFG_RUNTIME_MEAS \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_MEASUREMENT \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
                        @ref FCT_MEASUREMENT \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_CUSTOM_IO_INTERFACE \n
                        @ref FCT_CFG_SIGNAL_PERF_MONITORING \n
                        @ref !FCT_CFG_ALIGNMENT_MONITORING_INPUT \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
                        @ref FCT_CFG_RUNTIME_MEAS \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
  @c_switch_full        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL  \n
                        @ref FCT_CFG_LOHP_COMPONENT  \n
                        @ref FCT_CFG_ACT_CODE_VERSION  \n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS  \n

  @pre                  SLATE component call is completed
  @post                 -

  @InOutCorrelation     Covered in detail in component L4 Requirements. Covers all processing of LOHP functions.
 
  @traceability			doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-92-0008a201

  @author               Niraj Mistry | Niraj.Mistry@continental-corporation.com | +49 (69) 7603-6827
*************************************************************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void LOHP_v_Exec(/*const boolean b_SensorBlocked, */ const reqLOHPPrtList_t * p_RequirePorts, const LOHPProPort_t * p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame, const AS_t_ServiceFuncts *p_ServiceFuncts)
#else
void LOHP_v_Exec(/*const boolean b_SensorBlocked, */const reqLOHPPrtList_t * p_RequirePorts, const LOHPProPort_t * p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame)
#endif
{

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  if (p_ServiceFuncts != NULL)
  {
    LOHP_pServiceFuncts = p_ServiceFuncts;
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  LOHP_v_RuntimeMeasInit();
#endif

  /*---------------------------------------------------------------------------*/
  /* Start longitudinal controller processing                                  */
  /*---------------------------------------------------------------------------*/

  /* Sends RTA-Start Event for whole procedure runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  (uint8)LOHP_RTA_PROCESS, 0u);
  /* data preparation runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  (uint8)LOHP_RTA_PREPRE_PROCESS, 0u);

  /* set the FrameData for Sensor */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  LOHP_v_SetFrameData(p_FCTSenFrame, &AlgoErrorBuffer);
#else
  LOHP_v_SetFrameData(p_FCTSenFrame);
#endif

  /*! Set operation mode of LOHP based on FCT OpMode  */
  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  LOHP_v_ProcessStates(t_LOHPFrame.eFCTOpMode);

  LOHP_v_CheckPorts(p_RequirePorts, p_ProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
    , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    , &AlgoErrorBuffer
#endif
    );

  /* setup sync ref no matter what (sync in running and non running mode)*/
  LOHP_v_SetupSyncRef(p_RequirePorts);

  if ((t_LOHPFrame.eLOHPState != LOHP_ERROR) && (t_LOHPFrame.eLOHPState != LOHP_SHUTDOWN))
  {
    /* ---------------------------------------------------- start of NON error path -------------------------------------------------*/
    /* Ports OK, CtrlData indicates no error */
    /*Init in init Mode*/
    if (t_LOHPFrame.eLOHPState == LOHP_INIT)
    {
      t_LOHPFrame.bFirstCycleDone = FALSE;
    }
    else
    {
      t_LOHPFrame.bFirstCycleDone = TRUE;
    }

    LOHP_v_SetupPorts(p_RequirePorts, p_ProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start */
    if ((LOHP_pServiceFuncts->pfMeasStartFuncCycle) != NULL) /*PRQA S 0505*//* pServiceFuncts can't be NULL here: checked in FCTSenCheckPorts */
    {
      (LOHP_pServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_HC_MEAS_FUNC_CHAN_ID));
    }
#endif

    /* set all the signal headers of all provide ports to invalid*/
    LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INVALID);

    /* Send RTA-End Event for data preparation runtime in non-error state*/
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  (uint8)LOHP_RTA_PREPRE_PROCESS, 0u);
    /* Send RTA-Start Event for data preprocessing runtime in non-error state*/
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  (uint8)LOHP_RTA_PRE_PROCESS, 0u);

#if ( (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) && (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING) )
    /*call update check*/
    if ( LOHP_v_CheckInputUpdate(pRequirePorts, &t_LOHPInputCounters, TASK_CYCLE_TIME) != 0u)               /*error condition*/
    {
      LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
    }
#endif

    /* Send RTA-End Event for data preprocessing runtime in non-error state*/
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd, (uint8)LOHP_RTA_PRE_PROCESS, 0u);
    
    /* Send RTA-Start Event for Longitudinal Processing runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart, (uint8)LOHP_RTA_HP_PROCESS, 0u);
  
#if (!FCT_CFG_ALIGNMENT_MONITORING_INPUT)
#error LOHP_v_Process requires alignment monitoring output as input to determine sensor misalignment!
#endif
    LOHP_v_Process((times_t)((p_RequirePorts->pEmFctCycleMode->fEmFctCycleTime) * (fTime_t)Time_s),
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
      p_RequirePorts->pSysPerfMonStates,
#endif
      p_RequirePorts->pAlignmentMonInput,
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
      p_RequirePorts->pEmGenObjList,
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      p_RequirePorts->pEmARSObjList,
#endif
#else
      p_RequirePorts->pPubEmObj,
#endif
      p_RequirePorts->pPubFctObj,
      p_RequirePorts->pEgoDynRaw,
#if (FCT_SEN_CFG_VEH_SIG_INPUT)
      p_RequirePorts->pVehSig,
#endif
#if (FCT_CFG_SLATE_COMPONENT)
      p_RequirePorts->pSLATE_HC_Data,
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
      p_RequirePorts->pFCTCustomInput,
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
      p_RequirePorts->pFCTCustomOutput,
#endif
#endif
      p_RequirePorts->pFctVehLongOut,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
      p_RequirePorts->pFCTAccOOIData,
      p_ProvidePorts->pLOHPUsageState,
#endif
      p_ProvidePorts->pAccDisplayObj,
      p_ProvidePorts->pAccOutput);

  /* Send RTA-End Event for Longitudinal Processing runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd, (uint8)LOHP_RTA_HP_PROCESS, 0u);

    /* Send RTA-Start Event for Process Measfreeze runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  (uint8)LOHP_RTA_PROCESSFREEZE, 0u);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOHP_v_SetCompState (p_ProvidePorts->pSenCompState, p_RequirePorts->pSenCtrlData->OpMode, AlgoErrorBuffer);
#endif

#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
    /* if enabled this function checks all SigHeaders */
    LOHP_v_CheckProvideHeaders(p_RequirePorts, p_ProvidePorts);
#endif
    /* setup all provide port headers (cyclecounter, measurementcounter, timestamp) */
    LOHP_v_SetProvideHeader(p_RequirePorts, p_ProvidePorts);

    /* Filling sig headers for provide ports based on component state */
    if (t_LOHPFrame.eLOHPState == LOHP_RUN)
    {
      LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_OK);
    }
    else
    { /* LOHP_INIT */
      LOHP_v_SetProvideHeaderStates(p_ProvidePorts, AL_SIG_STATE_INIT);
    }

    /* Output Meas Freezes */
#if (FCT_MEASUREMENT)
    /* Process other meas freezes */
    LOHP_v_ProcessMeasFreeze(p_ProvidePorts);
#endif /* FCT_MEASUREMENT */

    /*! Computation chain ran through. FCT Sensor is initialized or running.*/
    b_LOHPIsInitialized = TRUE;

    /* Send RTA-End Event for Process Measfreeze runtime */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  (uint8)LOHP_RTA_PROCESSFREEZE, 0u);
  }   /* ((t_LOHPFrame.eLOHPState != LOHP_ERROR) && (t_LOHPFrame.eLOHPState != LOHP_SHUTDOWN)) */
  else  /************************* end of non-error path, beginning of error path *************************/
  {
    /* error occurred, set available provide ports */
    LOHP_v_SetErrorProvidePorts(p_ProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start if Service is available */
    if ((LOHP_pServiceFuncts != NULL) && (LOHP_pServiceFuncts->pfMeasStartFuncCycle != NULL))
    {
      (LOHP_pServiceFuncts->pfMeasStartFuncCycle ) ((AS_t_MeasFuncID) (FCT_HC_MEAS_FUNC_CHAN_ID));
    }
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /*ERROR path! need to check existence of pointers*/
    if (p_ProvidePorts != NULL) 
    {
      if ( (p_RequirePorts != NULL) && (p_RequirePorts->pSenCtrlData != NULL) )
      {
        LOHP_v_SetCompState (p_ProvidePorts->pSenCompState, p_RequirePorts->pSenCtrlData->OpMode, AlgoErrorBuffer);
      }
      else
      {
        /*assuming running status from scheduler ==> pointer error, Frame-mode is INIT ==> Input error is set*/
        LOHP_v_SetCompState (p_ProvidePorts->pSenCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
      }
    }
#endif

    /*! Make sure in error case init of sub components is performed next cycle*/
    b_LOHPIsInitialized = FALSE; 
    t_LOHPFrame.bFirstCycleDone = FALSE;

    /* Send RTA-End Event for data preparation runtime in error state */
    LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  (uint8)LOHP_RTA_PREPRE_PROCESS, 0u);
  }

  /* Send RTA-Start Event for Frame Measfreeze runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoStart,  (uint8)LOHP_RTA_FRAMEFREEZE, 0u);

#if (FCT_MEASUREMENT)
  /* Freeze frame meas data in all cases, even in case of Error*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Safeguard for NULL-Pointer */
  if ((p_ServiceFuncts != NULL) 
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    && (pServiceFuncts->pfMeasStartFuncCycle != NULL)
#endif
    && (p_ServiceFuncts->pfMeasFreeze != NULL)
    && (LOHP_pServiceFuncts != NULL)
    && (LOHP_pServiceFuncts->pfMeasFreeze != NULL) )
  {
    LOHP_v_FrameFreeze();
  }
#else
  LOHP_v_FrameFreeze();
#endif
#endif

  /* Send RTA-End Event for Frame Measfreeze runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  (uint8)LOHP_RTA_FRAMEFREEZE, 0u);
  /* Sends RTA-End Event for whole procedure runtime */
  LOHP_v_AlgoServiceAddEvent( e_RTA_EVT_AlgoEnd,  (uint8)LOHP_RTA_PROCESS, 0u);

#if (FCT_CFG_RUNTIME_MEAS)
  /* Freeze FCT ACC runtime info */
  FCT_HC_FREEZE_DATA(&t_LOHP_Runtime_MeasInfo, &t_LOHP_RuntimeInfo, NULL);
#endif

}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetOperationMode                                                                          */ /*!

  @brief           Set operation mode of LOHP component in FCT_SEN task

  @description     Set operation mode of LOHP component in FCT_SEN task based on given value
				  
				  @startuml
					Start
					Partition LOHP_v_SetOperationMode {
						Note Left:State:\n LOHP_INIT \n LOHP_RUN \n LOHP_ERROR \nLOHP_SHUTDOWN
						-Set operation mode of LOHP component 
					}	
					End	
				  @enduml
				  
  @return          -

  @param[in]       t_OpModeValue : LOHP operation mode value in FCT_SEN task [full range of datatype FCTSenHCState_t as in frame_lohp.h]

  @glob_in         t_LOHPFrame.eLOHPState : LOHP operation mode variable in FCT_SEN task [full range of datatype LOHPState_t as in frame_lohp.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-48-0008a201

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void LOHP_v_SetOperationMode(const LOHPState_t t_OpModeValue)
{
  t_LOHPFrame.eLOHPState = t_OpModeValue;
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetupPorts                                                                                */ /*!

  @brief           Setup the Ports to local aliases

  @description     Setup the Ports to local aliases for FCT_SEN inputs and outputs

				  @startuml
					Start
					Partition LOHP_v_SetupPorts {
					-Update the Sensor control data
					-Update  Ego dynamic raw data
					-Update the Static Vehicle parameters
					-Update EM FCT Cycle mode data
					-Update the Generic object list from EM
					-Update the ARS specific object list from EM
					-Update Public object data list
					-Update the Longitudinal control internal buffer
					-Update the Alignment information
					-Update the custom iput output data
					-Update the  BSW algo parameters
					-Update the ACC OOi list 
					-SLATE to HC input data
					-Update the ACC display object  
					-Update the ACC output data
					}
					End	
				@enduml

  @return          -

  @param[in]       pRequirePorts : Inputs passed to FCT_SEN [reqFCTSenPrtList_t as defined in fct_sen_ext.h]
  @param[in]       pProvidePorts : Outputs of FCT_SEN       [proFCTSenPrtList_t as defined in fct_sen_ext.h]

  @glob_in         -
  @glob_out        FCTSEN_pSenCtrlData :  Sensor control data
  @glob_out        FCTSEN_pEmFctCycleMode : EM FCT Cycle mode 
  @glob_out        FCTSEN_pEmGenObjList : Generic object list from EM
  @glob_out        FCTSEN_pEmCustObjList : Custom object list from EM
  @glob_out        FCTSEN_pEmARSObjList : ARS specific object list from EM
  @glob_out        FCTSEN_pEmCamObjList : Camera specific object list from EM
  @glob_out        FCTSEN_pEmObjList : Object list from EM
  @glob_out        FCTSEN_pMovObjTraces : Moving object traces
  @glob_out        FCTSEN_pObjectTraces : New object traces
  @glob_out        FCTSEN_pEgoDynObjSync : Ego dynamic object sync
  @glob_out        FCTSEN_pEgoDynRaw : Ego dynamic raw
  @glob_out        FCTSEN_pGlobEgoStatic : Static Vehicle parameters
  @glob_out        FCTSEN_pPerfDegrData : Performance degradation information
  @glob_out        FCTSEN_pRoadData : Road data
  @glob_out        FCTSEN_pRSPContextData : RSP context data
  @glob_out        FCTSEN_pRSPOutputPD : RSP range output information
  @glob_out        FCTSEN_pCustomOutput : Custom output data
  @glob_out        FCTSEN_pCustomInput : Custom input data
  @glob_out        FCTSEN_pCameraObjData : Camera object data
  @glob_out        FCTSEN_pME_in : Camera input
  @glob_out        FCTSEN_pAlignmentMonInput : Alignment information
  @glob_out        FCTSEN_pBswAlgoParameters : BSW algo parameters
  @glob_out        FCTSEN_pCPAR_FCT_Parameters : FCT Coding Parameters
  @glob_out        FCTSEN_pDIMOutputCustom : DIM custom output
  @glob_out        FCTSEN_pNaviData : Navi input data
  @glob_out        FCTSEN_pCamLaneData : Camera lane data
  @glob_out        FCTSEN_pPubFctObjList : Public object data
  @glob_out        FCTSEN_pSysPerfMonStates : SPM data
  @glob_out        FCTSEN_pSenACCCompState : Algo Component State
  @glob_out        FCTSEN_pBusDebugData : Bus debug data
  @glob_out        FCTSEN_pAccOOIData : ACC FCT_SEN to FCT_VEH data

  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface
  @c_switch_part   FCT_CFG_ME_INPUT_FOR_DEBUG : FCT configuration for debugging input of mobil-eye data (only meas output)
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
                                                 port structures, even if the current configuration does not use them.
                                                 This enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT component.
                                             This should be enabled, if the SW environment provides this information.
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG : Configuration switch for enabling BusDebugMessages
  @c_switch_full   -

  @pre             -
  @post            -

  @created         09.09.2010
  @changed         29.10.2015

  @author          Clemens Schnurr
*************************************************************************************************************************/
static void LOHP_v_SetupPorts( const reqLOHPPrtList_t * pRequirePorts, const LOHPProPort_t * pProvidePorts )
{
  LOHP_pSenCtrlData = pRequirePorts->pSenCtrlData;
  LOHP_pEgoDynRaw = pRequirePorts->pEgoDynRaw;
  LOHP_pGlobEgoStatic = pRequirePorts->pEgoStaticData;
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  LOHP_pEmFctCycleMode = pRequirePorts->pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  LOHP_pEmGenObjList = pRequirePorts->pEmGenObjList;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  LOHP_pEmARSObjList = pRequirePorts->pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  LOHP_pEmCamObjList = pRequirePorts->pEmCamObjList;
#endif
#else /* FCT_USE_EM_GENERIC_OBJECT_LIST */
  LOHP_pEmObjList = pRequirePorts->pPubEmObj;
#endif /* FCT_USE_EM_GENERIC_OBJECT_LIST */
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  LOHP_pPubFctObjList = pRequirePorts->pPubFctObj;
#endif
#endif /* FCT_CFG_OBJECT_LIST_PROC */

#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  LOHP_pFctVehLongOut = pRequirePorts->pFctVehLongOut;
#endif

#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  LOHP_pAlignmentMonInput = pRequirePorts->pAlignmentMonInput;
#endif 
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  LOHP_pVehSig = pRequirePorts->pVehSig;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  LOHP_pCustomOutputInput = pRequirePorts->pFCTCustomOutput;
#endif
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
  LOHP_pBswAlgoParameters   = pRequirePorts->pBswAlgoParameters;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  /* Provide OOI Objects from SEN to VEH */
  LOHP_pAccOOIData = pRequirePorts->pFCTAccOOIData;
#endif
#if (FCT_CFG_SLATE_COMPONENT)
  LOHP_pSLATEData = pRequirePorts->pSLATE_HC_Data;
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  LOHP_pCustomInput = pRequirePorts->pFCTCustomInput;
#endif

/* Provide ports */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  LOHP_pCompState = pProvidePorts->pSenCompState;
#endif
  LOHP_pAccDisplayObj = pProvidePorts->pAccDisplayObj;
  LOHP_pAccOutput = pProvidePorts->pAccOutput;
#if (FCT_CFG_USE_BUS_DEBUG)
  LOHP_pBusDebugData = pProvidePorts->pFCTSenBusDebugData;       /*!< Debug data Sensor */
#endif

}

/*************************************************************************************************************************
  Functionname:    LOHP_v_AlgoServiceAddEvent                                                                         */ /*!

  @brief           Determine runtime of FCT component based on service functions provided by Base SW.

  @description     Determine runtime of FCT component based on service functions depending on wheter pfRTAAlgoServiceAddEvent are available or not
                    If it is available this function is used otherwise the function FCTSEN_SERVICE_ADD_EVENT_FCT is called which determines the time difference between start and end events
  @return          -

  @param[in]       RtaEvtType : 
  @param[in]       u_IdLocal : 
  @param[in]       u_OptData : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_RUNTIME_MEAS : CT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers 
  @c_switch_full   FCT_CFG_RTA_PROFILING FCT_CFG_USE_SERVICE_POINTER_FUNCTS: Compiler switch used around this function/file

  @pre             -
  @post            -

  @created         04.05.2016
  @changed         04.05.2016


  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
static void LOHP_v_AlgoServiceAddEvent( const RTA_t_Events RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData)
#else
static void LOHP_v_AlgoServiceAddEvent( const AS_t_RtaEventType RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData)
#endif
{
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  if (    (LOHP_pServiceFuncts                           != NULL)
       && (LOHP_pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL) )
  {
#ifdef RTA_GLOBALID_FCT_SEN
    LOHP_pServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, RTA_GLOBALID_FCT_SEN, u_IdLocal, u_OptData);
#else
    LOHP_pServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT60, u_IdLocal, u_OptData);
#endif 
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  /* Check NULL pointer. 
  Check whether additional parameter (i.e. Object ID) is defined. This cannot be handled */
  if (    (LOHP_pServiceFuncts                     != NULL)
       && (LOHP_pServiceFuncts->pfGetTimestampuS32 != NULL) 
       && (u_OptData                                           == 0   ))
  {
    LOHP_v_AlgoServiceAddEvent_FCT( RtaEvtType, (sint32)u_IdLocal);
  }
#endif
  _PARAM_UNUSED(RtaEvtType);
  _PARAM_UNUSED(u_IdLocal);
  _PARAM_UNUSED(u_OptData);
}

#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:    LOHP_v_RuntimeMeasInit                                                                           */ /*!

  @brief           Init global FCT runtime measurement array

  @description     Init global FCT runtime measurement array

  @return          -

  @param[in]       -

  @glob_in        -
  @glob_out         t_LOHP_RuntimeInfo.uRuntime : Array of size FCTSEN_RTA_NOF_CHECKPOINTS containing the runtime 
                        of FCT_SEN subcomponents (microseconds) [0u ... 1s]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_RUNTIME_MEAS : FCT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers 

  @pre             -
  @post            -

  @created         04.05.2016
  @changed         04.05.2016

  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void LOHP_v_RuntimeMeasInit(void)
{
  uint32 i;
  /* Init global FCT runtime measurement array */
  for (i = 0u; i < LOHP_RTA_LAST_ENTRY; i++)
  {
    t_LOHP_RuntimeInfo.uRuntime[i] = 0u;
  }
}
#endif /* FCT_CFG_RUNTIME_MEAS */


#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:    LOHP_v_AlgoServiceAddEvent_FCT                                                                         */ /*!

  @brief           Determine runtime of FCT (Radar) component based on service functions provided by Base SW.

  @description     Determine runtime of FCT (Radar)  component based on service functions provided by Base SW.
                   The time difference is determined between start and end events.

  @return          -

  @param[in]       *pServiceFuncts : Service pointer provided by frame SW
                        pfGetTimestampuS32 [full range of AS_t_GetTimestampuS32 as in algo_service_types.h]
  @param[in]       t_RuntimeEvtType : Event type [full range of datatype FCT_t_ACCRuntimeCheckpointTypeEnum as in fct_sen.h]
  @param[in]       u_IdGlobal : Dummy variable which is unused. Necessary for compatibility with camera projects.
                                [full range of datatype uint8]
  @param[in]       u_IdLocal : Index in FCT ACC runtime measurement array [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[
  @param[in]       u_OptData : Dummy variable which is unused. Necessary for compatibility with camera projects. 
                                [full range of datatype uint8]

  @glob_in         -
  @glob_out        t_FCT_ACCTimeArray : FCT ACC runtime info
                            t_FCT_ACCTimeArray[i] [full range of datatype uint32] with i in [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[

  @c_switch_part   -
  @c_switch_full   FCT_CFG_RUNTIME_MEAS : FCT switch to enable runtime measurement for ACC
                           (ONLY for radar projects); only possible with service pointers

  @pre             Start and End Events for each runtime measurement have to be called in the code.
  @post            -

  @created         24.11.2015
  @changed         24.11.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void LOHP_v_AlgoServiceAddEvent_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
{
  if(t_RuntimeEvtType == e_RTA_EVT_AlgoStart) 
  {
    FCT_ASSERT(t_LOHP_RuntimeInfo.uRuntime[u_EventID] == 0u);
    /* In case of a start event, the current timestamp is stored in the array. */
    t_LOHP_RuntimeInfo.uRuntime[u_EventID] = LOHP_pServiceFuncts->pfGetTimestampuS32();
  }
  else if(t_RuntimeEvtType == e_RTA_EVT_AlgoEnd)
  {
    FCT_ASSERT(t_LOHP_RuntimeInfo.uRuntime[u_EventID] > 0u);
    /* In case of an end event, the time difference between the start and end event is stored in the array. 
        Precondition: Valid start event must have been called before. */
    t_LOHP_RuntimeInfo.uRuntime[u_EventID] = LOHP_pServiceFuncts->pfGetTimestampuS32() - t_LOHP_RuntimeInfo.uRuntime[u_EventID];
  }
  else
  {
    /* Reset runtime info:
    if no valid event type
    if no valid start event has been called before the end event. */
    t_LOHP_RuntimeInfo.uRuntime[u_EventID] = 0u;
    FCT_ASSERT(FALSE);
  }
}
#endif /*FCT_CFG_RUNTIME_MEAS*/

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetFrameData                                                                              */ /*!

  @brief           Set the Frame Data for Freeze

  @description     Set the Frame Data for Freeze, i.e. LOHP operation mode and component version number

				  @startuml
					Start
					Partition LOHP_v_SetFrameData {
					If(There are no any error states) then (Ture)	
						-Set the operation mode of LOHP\n from frame data of FCTSen
					Else (False)
						-Set FCT current operation mode to FCT_MOD_SHUTDOWN
						-Set LOHP operation mode to LOHP_SHUTDOWN
						-Set HP operation mode to HP_INIT	
					Endif 
					}	
					End	
   				  @enduml

  @return          -

  @param[in]       p_FCTSenFrame : Input data struct from FCTSen [FCTSenFrame_t as defined in fct_types.h]

  @glob_in         -
  @glob_out        t_LOHPFrame :  LOHP frame consisting of cycle time, cycle counter and opmode [as defined in frame_lohp.h]
                      t_LOHPFrame.eFCTOpMode : FCT requested operation mode       [FCT_OP_MODE_t as defined in Rte_Type.h]
                      t_LOHPFrame.uiCycleCounter : The LOHP cycle counter         [AlgoCycleCounter_t as defined in Rte_Type.h]
                      t_LOHPFrame.Versions.uiLohp : LOHP component version number [FCTSwVersion_t as defined in fct_ver.h]

  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component

  @pre             -
  @post            -

  @created         21.05.2013
  @changed         10.10.2017

  @author          Clemens Schnurr | clemens.schnurr@continental-corporation.com
*************************************************************************************************************************/
static void LOHP_v_SetFrameData( const FCTSenFrame_t * p_FCTSenFrame
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                               , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                               ) 
{
  /* Store operation mode received from outside in sen frame for freezing */
  if ( (p_FCTSenFrame->eFCTState != COMP_STATE_TEMPORARY_ERROR)
    && (p_FCTSenFrame->eFCTState != COMP_STATE_NOT_RUNNING))
  {
    t_LOHPFrame.eFCTOpMode = p_FCTSenFrame->eFCTOpMode;
  }
  else
  {
    /*No error handling (e.g. DEM, CompState) is required here as all 
    ports are checked later on in LOHP_v_CheckPorts*/
    t_LOHPFrame.eFCTOpMode = FCT_MOD_SHUTDOWN;
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    LOHP_v_SignalErrorShutdown(FALSE);
  }

  t_LOHPFrame.uiCycleCounter++;

  t_LOHPFrame.Versions.LOHP_VERSION_AS_TEXT       = (uint32)LOHP_SW_VERSION_NUMBER;
  t_LOHPFrame.Versions.uiLohp                     = (uint32)LOHP_SW_VERSION_NUMBER;
}

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/*************************************************************************************************************************
  Functionname:    LOHP_v_SetCompState                                                                              */ /*!

  @brief           Setup AlgoCompState

  @description  Setup AlgoCompState (output to Scheduler)

  @return          static void

  @param[in,out]   pSenCompState : 
  @param[in]       ScheduledOpMode : 
  @param[in]       BufferedQualifier : 

  @author          Christian Obst
*************************************************************************************************************************/
static void LOHP_v_SetCompState (AlgoCompState_t * const pSenCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
{
#if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) )
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: REMOVE REDEFINITION (obviously the RTE is updated)!")// PRQA S 3116
#endif
#ifndef MFC_VERSION_INFO_LENGTH
#define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
#endif 

  /* The define MFC_VERSION_INFO_LENGTH is to be renamed. The name has to be more generalized regarding the used thechnology */
#if COMP_STATE_INTFVER > 3
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_LOHP_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));
#else
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_LOHP_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
#endif
  if (pSenCompState != NULL) 
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(pSenCompState->AlgoVersionInfo, VERSION_LOHP_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pSenCompState->uiAlgoVersionNumber = t_LOHPFrame.Versions.uiLohp;
#if COMP_STATE_INTFVER > 2u
    pSenCompState->uiApplicationNumber = 0u;
    pSenCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pSenCompState->ApplicationNumber = 0u;
    pSenCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (t_LOHPFrame.eLOHPState)
    {
    case LOHP_INIT:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pSenCompState->eCompState = COMP_STATE_RUNNING;
        pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pSenCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case LOHP_RUN:
    case FCT_SEN_RG_HC_HIGH:
      /*everything's fine*/
      pSenCompState->eCompState = COMP_STATE_RUNNING;
      pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pSenCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case LOHP_SHUTDOWN:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pSenCompState->eCompState = COMP_STATE_RUNNING;
        pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*internal recoverable error*/
        pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pSenCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case LOHP_ERROR:
      /*triggered with input interface errors*/
    default:
      pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
      pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
      if (BufferedQualifier != ALGO_QUAL_OK)
      {
        pSenCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
      }
      else
      {
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
      }
      break;
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */


/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckPorts                                                                                */ /*!

  @brief           Do Checking of Input and output ports for valid pointer

  @description     Do Checking of input and output ports for valid pointer 
                   and trigger the error management

				   @startuml
					Start
					Partition LOHP_v_CheckPorts {
					If(All request ports have valid addresses) then (Ture)
						If(Any provide port has invalid address)then (True)
							-Set the LOHP mode to shutdown	
						endif
						If(Object list port eSigStatus is invalid) then(Ture)
						-Set the LOHP mode to error 	
						endif
					Else (False) 	 
	  					-Trigger the error management
					Endif
				   }	
				   End	
				  @enduml

  @return          -

  @param[in]       pProvidePorts : the outputs from FCT_SEN                                     [proFCTSenPrtList_t as defined in fct_sen_ext.h]
  @param[in]       pRequirePorts : the inputs passed to the FCT_SEN main function               [reqFCTSenPrtList_t as defined in fct_sen_ext.h]
  @param[in]       pServiceFuncts : Reference to service functions provided by Frame            [AS_t_ServiceFuncts as defined in algo_services_types.h]
  @param[in]       pErrorBuffer : Generic algo qualifiers should be used on the algo component  [GenAlgoQualifiers_t as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS : FCT switch to use third parameter in Exec methods to call the Function. 
                                                        Third parameter is a structure to service functions provided by the Frame.
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode (ARS3xx specific)
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface 
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide port structures, even if the current configuration does not use them. 
                                                 This enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT uses direct access to vehicle signals
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the SW environment provides this information
  @c_switch_part   FCT_CFG_USE_DEM : Switch that enables the DEM reporting towards Service Interface
  @c_switch_part   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK : Switch that enables signal status input check
  
  @c_switch_full   -

  @pre             None 
  @post            No changes 

  @created         09.09.2010
  @changed         09.11.2015

  @author          Clemens Schnurr | clemens.schnurr@continental-corporation.com
*************************************************************************************************************************/
static void LOHP_v_CheckPorts( const reqLOHPPrtList_t * pRequirePorts,
                               const LOHPProPort_t * pProvidePorts
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
  LOHP_pServiceFuncts = pServiceFuncts;
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
      || (pRequirePorts->pSenCtrlData == NULL)
#if (FCT_CFG_EM_FCT_CYCLEMODE)
      || (pRequirePorts->pEmFctCycleMode == NULL)
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
      || (pRequirePorts->pEmGenObjList == NULL)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      || (pRequirePorts->pEmARSObjList == NULL)
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
      || (pRequirePorts->pEmCamObjList == NULL)
#endif
#else
      || (pRequirePorts->pPubEmObj == NULL)
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
      || (pRequirePorts->pPubFctObj == NULL)
#endif
#endif
      || (pRequirePorts->pEgoDynRaw == NULL)
      || (pRequirePorts->pEgoStaticData == NULL)
#if (FCT_CFG_LOPC_COMPONENT)
      || (pRequirePorts->pFctVehLongOut == NULL)
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
      || (pRequirePorts->pFCTAccOOIData == NULL)
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      || (pRequirePorts->pAlignmentMonInput == NULL)
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      || (pRequirePorts->pVehSig == NULL)
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      || (pRequirePorts->pBswAlgoParameters == NULL)
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
      || (pRequirePorts->pFCTCustomOutput == NULL)
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
      || (pRequirePorts->pFCTCustomInput == NULL)
#endif
#endif
#if (FCT_CFG_SLATE_COMPONENT)
      || (pRequirePorts->pSLATE_HC_Data == NULL)
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
      || (pRequirePorts->pSysPerfMonStates == NULL)
#endif
    )
  {
    /* Some request port pointer is NULL => DEM and shutdown */
#if FCT_CFG_USE_DEM
    LOHP_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    LOHP_v_SignalErrorShutdown(FALSE);
  }
  else
  {
    /*SigStatus not invalid in all interfaces*/
    /* Verify that provide port buffer pointers are set (non-null) */
    if(
        (pProvidePorts == NULL)
        || (pProvidePorts->pAccDisplayObj == NULL)
        || (pProvidePorts->pAccOutput == NULL)
#if (FCT_CFG_USE_ALGOCOMPSTATE)
        || (pProvidePorts->pSenCompState == NULL)
#endif
        ||(pProvidePorts->pLOHPUsageState == NULL)
      )
      {
        /* Some provide port pointer is NULL => DEM -> shutdown */
#if (FCT_CFG_USE_DEM)
        LOHP_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
        LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
        LOHP_v_SignalErrorShutdown(FALSE);
      }
      else
      {
        /* receive and provide ports are fine */
#if (FCT_CFG_USE_DEM)
        LOHP_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
      }
  
#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
    /* no NullPointer in request ports*/
    /* check for SignalState in requestPorts*/
    if (
      (pRequirePorts->pSenCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_EM_FCT_CYCLEMODE)
      /*no SigHeader*/
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
      || (pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      || (pRequirePorts->pEmARSObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
      || (pRequirePorts->pEmCamObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#else
      || (pRequirePorts->pPubEmObj->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif
      //|| (pRequirePorts->pEgoDynObjSync->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      || (pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      || (pRequirePorts->pEgoStaticData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_LOPC_COMPONENT)
      || (pRequirePorts->pFctVehLongOut->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
      || (pRequirePorts->pFCTAccOOIData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      || (pRequirePorts->pAlignmentMonInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      || (pRequirePorts->pVehSig->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      /*no SigHeader*/
#endif
    )
    {
      /*signal state broken -> no dem only shutdown*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      /* setup the Algo Error Buffer */
      LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      /* shutdown the system */
      LOHP_v_SignalErrorShutdown(FALSE);
    }
#endif /*FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK*/

    /* If object list is invalid, then force to init mode
      Note: InputPort pointers are existing */
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
    if (pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus != AL_SIG_STATE_OK)
#else
    if (pRequirePorts->pPubEmObj->eSigStatus != AL_SIG_STATE_OK)
#endif
    {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      LOHP_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      LOHP_v_SignalErrorShutdown(TRUE); /* Temporary Error without shutdown */
    }

  }
}

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             LOHP_v_SetDem                                     */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTSenServiceFuncts connected to input service ports
  @todo           review
  @author         Christian Obst
**************************************************************************** */
static void LOHP_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((LOHP_pServiceFuncts != NULL) && (LOHP_pServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    LOHP_pServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif /*FCT_CFG_USE_DEM*/


/*************************************************************************************************************************
  Functionname:    LOHP_v_SetupSyncRef                                                                              */ /*!

  @brief           Creates sync data for Simulation synchronization

  @description     1. Puts signal headers of all input ports into one structure 
                   2. Checks validity of interface
                   3. Sets sSigHeader of SyncRef structure (any NullPointer -> INVALID)

				   @startuml
						Start
						Partition LOHP_v_SetupSyncRef {
						If(All input ports have valid address ) then (True)
							-Sets sSigHeader of SyncRef structure
						Else (False)
							-Set the main eSigStatus status to invalid state
						endif
					}	
					End	
				   @enduml

  @return          -

  @param[in]       pRequirePorts : The input data used by FCT component
                      pSenCtrlData : FCT COntrol data [FCTCtrlData_t as defined in Rte_Type.h]
                      pEgoDynObjSync : The dynamic vehicle ego data object sync [VehDyn_t as defined in Rte_Type.h]
                      pEgoDynRaw : The dynamic vehicle ego data raw [VehDyn_t as defined in Rte_Type.h]
                      pEgoStaticData : The static vehicle ego data [VehPar_t as defined in Rte_Type.h]
                      pEmGenObjList : EM generic object list [EM_t_GenObjectList as defined in Rte_Type.h]
                      pEmARSObjList : EM ARS-technology-specific object list [EM_t_ARSObjectList as defined in Rte_Type.h]
                      pEmCamObjList : EM Camera-technology-specific object list [EM_t_CamObjectList as defined in Rte_Type.h]
                      pPubEmObj : The public EM object data [ObjectList_t as defined in Rte_Type.h]
                      pFctVehLongOut : Longitudinal control internal buffer for passing information from FCT_VEH to FCT_SEN [FctVeh2SenInfo_t as defined in Rte_Type.h]
                      pFCTCustomInput : Custom input [FCTCustomInput_t as defined in Rte_Type.h]
                      pAlignmentMonInput : Alignment monitoring output data [ALN_Monitoring_t as defined in Rte_Type.h]
                      pVehSig : Direct access to vehicle signals [VehSig_t as defined in Rte_Type.h
                      pSenCtrlData : FCT control data [FCTCtrlData_t as defined in Rte_Type.h]
                      sSigHeader : Signal Headers of every Input Port defined above is also an input to this function [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         t_LOHP_SyncRef : Simulation sync structure contains Signal Headers of every Input Port
                      EmFctCycleMode : [SignalHeader_t as defined in Rte_Type.h]

  @glob_out        t_LOHP_SyncRef : Simulation sync structure contains Signal Headers of every Input Port
                      sSigHeader.eSigStatus : [AlgoSignalState_t as defined by Rte_Type.h]
                      SenCtrlData : [SignalHeader_t as defined in Rte_Type.h]
                      EgoDynObjSync : [SignalHeader_t as defined in Rte_Type.h]
                      EgoDynRaw : [SignalHeader_t as defined in Rte_Type.h]
                      EgoStaticData : [SignalHeader_t as defined in Rte_Type.h]
                      EmFctCycleMode : [SignalHeader_t as defined in Rte_Type.h]
                      EmGenObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmARSObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmCamObjList : [SignalHeader_t as defined in Rte_Type.h]
                      PubEmObj : [SignalHeader_t as defined in Rte_Type.h]
                      PerfDegrData : [SignalHeader_t as defined in Rte_Type.h]
                      FctVehLongOut : [SignalHeader_t as defined in Rte_Type.h] 
                      FCTCustomInput : [SignalHeader_t as defined in Rte_Type.h]
                      AlignmentMonInput : [SignalHeader_t as defined in Rte_Type.h]
                      VehSig : [SignalHeader_t as defined in Rte_Type.h]

  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode configuration switch
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t 
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list 
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT direct access to vehicle signals
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of ALGO parameters to the FCT component
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             None
  @post            No changes

  @created         24.05.2013
  @changed         02.02.2016

  @author          Christian Obst | Christian.Obst@continental-corporation.com 
*************************************************************************************************************************/
static void LOHP_v_SetupSyncRef(const reqLOHPPrtList_t * pRequirePorts)
{
  /*setting whole syncref to zero */
  (void)memset(&t_LOHP_SyncRef, 0, sizeof(t_LOHP_SyncRef));

  if (pRequirePorts != NULL)
  {
    /*pSenCtrlData*/
    if (pRequirePorts->pSenCtrlData != NULL)
    {
      t_LOHP_SyncRef.SenCtrlData          = pRequirePorts->pSenCtrlData->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*EgoDynRaw*/
    if (pRequirePorts->pEgoDynRaw != NULL)
    {
      t_LOHP_SyncRef.EgoDynRaw               = pRequirePorts->pEgoDynRaw->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*EgoStaticData*/
    if (pRequirePorts->pEgoStaticData != NULL)
    {
      t_LOHP_SyncRef.EgoStaticData           = pRequirePorts->pEgoStaticData->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_EM_FCT_CYCLEMODE)
    /*pEmFctCycleMode*/
    LOHP_v_SetSigHeaderError(&t_LOHP_SyncRef.EmFctCycleMode);
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
    /*pEmGenObjList*/
    if (pRequirePorts->pEmGenObjList != NULL)
    {
      t_LOHP_SyncRef.EmGenObjList          = pRequirePorts->pEmGenObjList->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    /*pEmARSObjList*/
    if (pRequirePorts->pEmARSObjList != NULL)
    {
      t_LOHP_SyncRef.EmARSObjList          = pRequirePorts->pEmARSObjList->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    /*pEmCamObjList*/
    if (pRequirePorts->pEmCamObjList != NULL)
    {
      t_LOHP_SyncRef.EmCamObjList          = pRequirePorts->pEmCamObjList->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#else 
    /*pPubEmObj*/
    if (pRequirePorts->pPubEmObj != NULL)
    {
      t_LOHP_SyncRef.PubEmObj              = pRequirePorts->pPubEmObj->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#endif

#if (FCT_CFG_LOPC_COMPONENT)
    /*pFctVehLongOut*/
    if (pRequirePorts->pFctVehLongOut != NULL)
    {
      t_LOHP_SyncRef.FctVehLongOut           = pRequirePorts->pFctVehLongOut->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
    /*pAlignmentMonInput*/
    if (pRequirePorts->pAlignmentMonInput != NULL)
    {
      t_LOHP_SyncRef.AlignmentMonInput       = pRequirePorts->pAlignmentMonInput->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_SEN_CFG_VEH_SIG_INPUT)
    /*pVehSig*/
    if (pRequirePorts->pVehSig != NULL)
    {
      t_LOHP_SyncRef.VehSig                  = pRequirePorts->pVehSig->sSigHeader;
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    if (pRequirePorts->pSenCtrlData != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      LOHP_v_FillSigHeader(&t_LOHP_SyncRef.sSigHeader, &pRequirePorts->pSenCtrlData->sSigHeader);
      LOHP_v_SetSigHeaderState(&t_LOHP_SyncRef.sSigHeader, AL_SIG_STATE_OK);
    }
    else
    {
      t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    t_LOHP_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_SetSigHeaderError                                                                          */ /*!

  @brief           Set signal header with error values

  @description     Init SignalHeader_t struct with default values for FCT_SEN.
                    These default values are the cycle counter of FCT_SEN and the signal state invalid. 
                    Timestamp and measurement counter are set to zero.

					@startuml
					Start
						Partition LOHP_v_SetSigHeaderError {
							- Reset the uiTimeStamp value
							- Reset the uiMeasurementCounter 
							- Update the pSigHeader->uiCycleCounter by t_LOHPFrame.uiCycleCounter 
							- Update the eSigStatus by AL_SIG_STATE_INVALID 
					}	
					End	
					@enduml

  @return          -

  @param[out]      pSigHeader : The signal header to be filled
                        uiTimeStamp           [AlgoDataTimeStamp_t as in Rte_Type.h]
                        uiMeasurementCounter  [AlgoCycleCounter_t as in Rte_Type.h]
                        uiCycleCounter        [AlgoCycleCounter_t as in Rte_Type.h]
                        eSigStatus            [AlgoSignalState_t as in Rte_Type.h]

  @glob_in         FCTSenFrame : Global FctSen frame data
                      uiCycleCounter [AlgoCycleCounter_t as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         -
  @changed         28.10.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void LOHP_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiTimeStamp           = 0u;
  pSigHeader->uiMeasurementCounter  = 0u;
  pSigHeader->uiCycleCounter        = t_LOHPFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_FillSigHeader                                                                             */ /*!

  @brief           Fill FCT Sen signal header with default values

  @description     Fill SignalHeader_t struct with default values for FCT_SEN. These default values are the 
                   cycle counter of FCT_SEN, and the signal state based on the passed parameter.

					@startuml
					Start
						Partition LOHP_v_FillSigHeader {
						-Fill time stamp and measurement counter based on source port 
						-Fill cycle counter based on LOHP frame 
					}	
					End	
					@enduml

  @return          -

  @param[in]       pSourceHdr : The source signal header (measurement cycle counter and timestamp are 
                                copied from this source)
                      uiTimeStamp [AlgoDataTimeStamp_t as in Rte_Type.h]
                      uiMeasurementCounter [AlgoCycleCounter_t as in Rte_Type.h]
  @param[in]       eSigState : The state to set for the 'eSigStatus' field [AlgoSignalState_t as in Rte_Type.h]
  @param[out]      pSigHeader : The signal header to be filled
                      uiTimeStamp           [AlgoDataTimeStamp_t as in Rte_Type.h]
                      uiMeasurementCounter  [AlgoCycleCounter_t as in Rte_Type.h]
                      uiCycleCounter        [AlgoCycleCounter_t as in Rte_Type.h]
                      eSigStatus            [AlgoSignalState_t as in Rte_Type.h]

  @glob_in         FCTSenFrame : Global FctSen frame data
                      uiCycleCounter         [AlgoCycleCounter_t as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             FCT component initialized
  @post            None

  @created         -
  @changed         22.10.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void LOHP_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = t_LOHPFrame.uiCycleCounter;
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_SetSigHeaderState                                                                         */ /*!

  @brief           Set signal header state
  
  @description	  
					@startuml
						Start
						Partition LOHP_v_SetSigHeaderState {
					Note left:State:\nAL_SIG_STATE_INVALID\nAL_SIG_STATE_INIT\nAL_SIG_STATE_OK
						 -Set signal header state
					}	
					End	
					@enduml

  @return          -

  @param[in,out]   pSigHeader : pointer to signal header struct
  @param[in]       eSigState : signal state to be set

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOHP_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus            = eSigState;
}

/*************************************************************************************************************************
  Functionname:    LOHP_v_SetErrorProvidePorts                                                                   */ /*!

  @brief           Setup available provide ports in ERROR case

  @description     Setup sigHeaders of available provide ports in ERROR case invalidates the Signal Status and setup version number

				  @startuml
					Start
					Partition LOHP_v_SetErrorProvidePorts {
					 If(Provide port is null) then (True)
						-Set the LOHP_pAccDisplayObj to NULL
						-Set the LOHP_pAccOutput to NULL
					Else (False)
						If(pAccDisplayObj and pAccOutput have vaild address) then (Ture)
							-Set the LOHP_pAccDisplayObj to actual output port 
							-Set the LOHP_pAccOutput to actual output port 
						Else (Flase)
							-Set the LOHP_pAccDisplayObj to NULL
							-Set the LOHP_pAccOutput to NULL
						Endif 
					endif
				  }	
				  End	
				  @enduml

  @return          -

  @param[in]       pProvidePorts : Outputs of LOHP
                      pProvidePorts->pAccDisplayObj                     [acc_object_t as defined in Rte_Type.h]
                      pProvidePorts->pAccOutput                         [acc_output_data_t as defined in Rte_Type.h]
                      
  @glob_in         -

  @c_switch_full    @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL  \n
                    @ref FCT_CFG_LOHP_COMPONENT  \n
                    @ref FCT_CFG_ACT_CODE_VERSION  \n

  @pre             LOHP state in error
  @post            -

  @created         01.07.2013
  @changed         15.07.2019

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com 
*************************************************************************************************************************/
static void LOHP_v_SetErrorProvidePorts (const LOHPProPort_t * pProvidePorts)
{
  acc_object_t         AccDisplayObj;     
  acc_output_data_t    AccOutput;         
  LOHP_ObjUsageState_t LOHPUsageState;


  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pSenCompState != NULL)
    {
      LOHP_pCompState      = pProvidePorts->pSenCompState;
#if COMP_STATE_INTFVER > 2u
      pProvidePorts->pSenCompState->uiVersionNumber = COMP_STATE_INTFVER;
#else
      pProvidePorts->pSenCompState->uVersionNumber = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      LOHP_pCompState = NULL;
    }
#endif

    /* Calling init function for local variables of output ports */
    LOHP_v_Init(&AccDisplayObj, &AccOutput, &LOHPUsageState);

    if (pProvidePorts->pAccDisplayObj != NULL)
    {
      LOHP_pAccDisplayObj = pProvidePorts->pAccDisplayObj;
      *(pProvidePorts->pAccDisplayObj) = AccDisplayObj;
      pProvidePorts->pAccDisplayObj->uiVersionNumber  = ACC_DISPLAY_OBJECT_INTFVER;
      LOHP_v_SetSigHeaderError(&pProvidePorts->pAccDisplayObj->sSigHeader);
    }
    else
    {
      LOHP_pAccDisplayObj = NULL;
    }
    if (pProvidePorts->pAccOutput != NULL)
    {
      LOHP_pAccOutput = pProvidePorts->pAccOutput;
      *(pProvidePorts->pAccOutput) = AccOutput;
      pProvidePorts->pAccOutput->uiVersionNumber      = FCT_ACC_OUTPUT_DATA_INTFVER;
      LOHP_v_SetSigHeaderError(&pProvidePorts->pAccOutput->sSigHeader);
    }
    else
    {
      LOHP_pAccOutput = NULL;
    }

#if (FCT_CFG_USE_BUS_DEBUG)
    /* Seutp Bus debug port for Sensor in error case */
    if (pProvidePorts->pFCTSenBusDebugData != NULL)
    {
      LOHP_pBusDebugData          = pProvidePorts->pFCTSenBusDebugData;
    }
    else
    {
      LOHP_pBusDebugData = NULL;
    }
#endif
  }
  else
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    pSLATE_SenCompState = NULL;
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    LOHP_pBusDebugData = NULL;
#endif
  LOHP_pAccDisplayObj = NULL;
  LOHP_pAccOutput = NULL;
  }
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_SetProvideHeaderStates                                                                    */ /*!

  @brief           Set the state in the SigHeader for all used provide ports

  @description   
				@startuml
				Start
					Partition LOHP_v_SetProvideHeaderStates {
					-Set the state in the SigHeader for all used provide ports
				}	
				End	
				@enduml

  @return          -

  @param[in]       pProvidePorts : 
  @param[in]       eSigState : 

  @pre             None ?
  @post            No changes ?

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOHP_v_SetProvideHeaderStates(const LOHPProPort_t * pProvidePorts, AlgoSignalState_t eSigState) 
{

  LOHP_v_SetSigHeaderState(&pProvidePorts->pAccDisplayObj->sSigHeader, eSigState);
  LOHP_v_SetSigHeaderState(&pProvidePorts->pAccOutput->sSigHeader, eSigState);

}


/*************************************************************************************************************************
  Functionname:    LOHP_v_SetProvideHeader                                                                          */ /*!

  @brief           Set the signal headers of provide ports

  @description     Set the signal headers of provide ports

					@startuml
					Start
					Partition LOHP_v_SetProvideHeader {
					 -Set the signal headers of provide ports
					}	
					End	
					@enduml

  @return          -

  @param[in]       pRequirePorts : Pointer to FCT_SEN output ports
  @param[in]       pProvidePorts : 
                      pAccDisplayObj->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pAccOutput->sSigHeader            [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   None 

  @pre             None 
  @post            No changes 

  @created         24.6.2013
  @changed         09.11.2015

  @author          Christian Obst | christian.obst@continental-corporation.com
*************************************************************************************************************************/
static void LOHP_v_SetProvideHeader(const reqLOHPPrtList_t * pRequirePorts, const LOHPProPort_t * pProvidePorts) 
{
  LOHP_v_FillSigHeader(&pProvidePorts->pAccDisplayObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
  LOHP_v_FillSigHeader(&pProvidePorts->pAccOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);

}


#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckProvideHeader                                                                         */ /*!

  @brief           Check whether the signal header has changed during the call of the components

  @description     Check whether the signal header has changed during the call of the components

  @return          -

  @param[in]       pProvidedSigHeader : 
  @param[in]       pReceivedSigHeader : 

  @pre             None ?
  @post            No changes ?

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOHP_v_CheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
{
  _PARAM_UNUSED(pProvidedSigHeader);
  _PARAM_UNUSED(pReceivedSigHeader);

  CML_ASSERT(    (pProvidedSigHeader->uiMeasurementCounter == pReceivedSigHeader->uiMeasurementCounter)
              && (pProvidedSigHeader->uiTimeStamp          == pReceivedSigHeader->uiTimeStamp         )
            /*&& (pProvidedSigHeader->eSigStatus           != AL_SIG_STATE_INVALID                    )*/ );
}
#endif


#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
/*************************************************************************************************************************
  Functionname:    LOHP_v_CheckProvideHeaders                                                                       */ /*!

  @brief           Call the check of the SigHeader for all used ports

  @return          -

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @pre             None ?
  @post            No changes ?

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void LOHP_v_CheckProvideHeaders(reqLOHPPrtList_t const * const pRequirePorts, LOHPProPort_t const * const pProvidePorts)
{
  LOHP_v_CheckProvideHeader(&pProvidePorts->pAccDisplayObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
  LOHP_v_CheckProvideHeader(&pProvidePorts->pAccOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
}
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */

#endif /*(FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)*/

/** @} end defgroup */

