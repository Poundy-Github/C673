/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_sen_main.c

DESCRIPTION:               FCT (function) component main module FCT_SEN

AUTHOR:                    Gergely Ungvary

CREATION DATE:             02.11.09

VERSION:                   $Revision: 1.103 $

LEGACY VERSION:            Revision: 2.0.1.2

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_sen.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer: Prabhu Sundaramurthy, reason: This does not effect the functionality*/

 /* needed for memset*/
#ifndef __PDO__
 #include <string.h>
#endif /* #ifndef __PDO__ */
/*********************************************************************************/
/**
@defgroup fct_sen_main Fct_sen_main
@ingroup frame_sen
@{
*/

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/
/*! @cond Doxygen_Suppress */
#if (FCT_CFG_RUNTIME_MEAS)
/* Meas freeze structure for FCT ACC runtime info */ 
SET_MEMSEC_VAR(t_FCTSEN_Runtime_MeasInfo)
static const MEASInfo_t t_FCTSEN_Runtime_MeasInfo = { // PRQA S 3218
/* date: 2017-10-31, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
  FCT_MEAS_ID_RUNTIME_DEBUG,      /* VirtualAddress */
  sizeof(FCT_t_RuntimeInfo),      /* Length */
  FCT_MEAS_FUNC_ID,               /* FuncID */
  FCT_MEAS_FUNC_CHAN_ID           /* FuncChannelID */
};
#endif

/* Input Port Measurement Counter struct */
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*PRQA S 3218 2*/ /* 20150827 CO: kept here for better maintainability */
SET_MEMSEC_VAR(FCTSenInputCounters)
static FCTSen_InputMeasCounter_t FCTSenInputCounters = {0};
#endif
/* Meas freeze reference */
SET_MEMSEC_VAR(FCTSenSyncRef)
FCTSen_SyncRef_t FCTSenSyncRef;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(pFCTSenServiceFuncts)
const AS_t_ServiceFuncts *pFCTSenServiceFuncts;
#endif

/* frame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(FCTSenFrame)
FCTSenFrame_t FCTSenFrame;

/* Pointers to the input/output data of the FCT component */
SET_MEMSEC_CONST(FCTSEN_pSenCtrlData)
#if (FCT_CFG_USE_BASECTRLDATA)
const BaseCtrlData_t           * FCTSEN_pSenCtrlData;
#else
const FCTCtrlData_t            * FCTSEN_pSenCtrlData;
#endif

#if (FCT_CFG_EM_FCT_CYCLEMODE)
SET_MEMSEC_CONST(FCTSEN_pEmFctCycleMode)
const EmFctCycleMode_t        * FCTSEN_pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
SET_MEMSEC_CONST(FCTSEN_pEmGenObjList)
const EM_t_GenObjectList      * FCTSEN_pEmGenObjList;
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
SET_MEMSEC_CONST(FCTSEN_pEmCustObjList)
const EM_t_ObjectList_Custom  * FCTSEN_pEmCustObjList;
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
SET_MEMSEC_CONST(FCTSEN_pEmARSObjList)
const EM_t_ARSObjectList      * FCTSEN_pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
SET_MEMSEC_CONST(FCTSEN_pEmCamObjList)
const EM_t_CamObjectList      * FCTSEN_pEmCamObjList;
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
SET_MEMSEC_CONST(FCTSEN_pMovObjTraces)
const MovingObjectTraces_t    * FCTSEN_pMovObjTraces;
#if (FCT_CFG_NEW_TRACES_INTERFACE)
SET_MEMSEC_CONST(FCTSEN_pObjectTraces)
const ObjectTraceList_t       * FCTSEN_pObjectTraces;
#endif /* FCT_CFG_NEW_TRACES_INTERFACE */
#endif /* FCT_CFG_USE_EM_MOVING_OBJECT_TRACES */
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
SET_MEMSEC_VAR(FCTSEN_pPubFctObjList)
AssessedObjList_t             * FCTSEN_pPubFctObjList;
#endif
#endif /* FCT_CFG_OBJECT_LIST_PROC */

SET_MEMSEC_CONST(FCTSEN_pEgoDynObjSync)
const VehDyn_t                * FCTSEN_pEgoDynObjSync;
SET_MEMSEC_CONST(FCTSEN_pEgoDynRaw)
const VehDyn_t                * FCTSEN_pEgoDynRaw;
SET_MEMSEC_CONST(FCTSEN_pGlobEgoStatic)
const VehPar_t                * FCTSEN_pGlobEgoStatic;
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
SET_MEMSEC_CONST(FCTSEN_pPerfDegrData)
const PerfDegr_t              * FCTSEN_pPerfDegrData;
SET_MEMSEC_VAR(FCTSEN_pSysPerfMonStates)
SysPerfMonStates_t            * FCTSEN_pSysPerfMonStates;
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
SET_MEMSEC_CONST(FCTSEN_pRSPOutputPD)
const RSPOutputPD_t           * FCTSEN_pRSPOutputPD;
#endif
#if (FCT_CFG_ROAD_INPUT)
SET_MEMSEC_CONST(FCTSEN_pRoadData)
const Road_t                  * FCTSEN_pRoadData;
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
SET_MEMSEC_CONST(FCTSEN_pRSPContextData)
const RSPKontextData_t        * FCTSEN_pRSPContextData;
#endif

#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
SET_MEMSEC_CONST(pLongCtrlResp)
const LongCtrlInput_t                *FCTSEN_pLongCtrlResp;    /* Dynamic controller response */

SET_MEMSEC_CONST(pt_FCT_IN_TCCP)
const TargetControlCommandPort_t *pt_FCT_IN_TCCP;   /* Command Input from ISC to LOHP */

SET_MEMSEC_CONST(pt_FCT_IN_TFSP)
const TargetFollowStatePort_t *pt_FCT_IN_TFSP;   /* Status Input from LOPC to LOHP */
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/* customer specific input/output */
SET_MEMSEC_CONST(FCTSEN_pCustomInput)
const FCTCustomInput_t        * FCTSEN_pCustomInput;
SET_MEMSEC_VAR(FCTSEN_pCustomOutput)
FCTCustomOutput_t             * FCTSEN_pCustomOutput;
#endif

#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
SET_MEMSEC_VAR(FCTSEN_pCDCustomOutput)
FCTCDOutputCustom_t           * FCTSEN_pCDCustomOutput;
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
SET_MEMSEC_CONST(FCTSEN_pCameraObjData)
const EM_t_ObjectList_Custom  * FCTSEN_pCameraObjData;
#endif

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
SET_MEMSEC_CONST(FCTSEN_pEmFusionObjList)
const EM_t_FusionObjectList  * FCTSEN_pEmFusionObjList;
#endif

#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_CONST(FCTSEN_pAlignmentMonInput)
const ALN_S_Monitoring_t      * FCTSEN_pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif  /* Provide ports */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(FCTSEN_pSenCompState)
  AlgoCompState_t             * FCTSEN_pSenCompState;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
SET_MEMSEC_VAR(FCT_pCDHypothesesSen)
HypothesisIntf_t              * FCT_pCDHypothesesSen;     /*!< FCT CD hypotheses */
#endif

#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
SET_MEMSEC_CONST(FCTSEN_pME_in)
const ME_in_t                 * FCTSEN_pME_in;            /*!< FCT mobil-eye input */
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
SET_MEMSEC_CONST(FCTSEN_pBswAlgoParameters)
const BSW_s_AlgoParameters_t  * FCTSEN_pBswAlgoParameters; /*!< Input algo parameters from BSW */
#endif

#if (FCT_CFG_CPAR_PARAMS)
SET_MEMSEC_CONST(FCTSEN_pCPAR_FCT_Parameters)
const CPAR_FCT_Parameters_t * FCTSEN_pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
#endif

#if (FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT)
SET_MEMSEC_CONST(FCTSEN_pDIMOutputCustom)
const DIMOutputCustom_t       * FCTSEN_pDIMOutputCustom;    /*!< DIM output custom from FCT_VEH */
#endif

#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)
SET_MEMSEC_CONST(FCTSEN_pNaviData)
const t_NaviInputData         * FCTSEN_pNaviData;           /*!< Simple navi input data */
#endif

#if (FCT_CFG_USE_BUS_DEBUG)
SET_MEMSEC_CONST(FCTSEN_pBusDebugData)
const BusDebugData_t          * FCTSEN_pBusDebugData;       /*!< Debug data Sensor */
#endif

#if (FCT_CFG_SEN_CAM_LANE_INTERFACE)
SET_MEMSEC_CONST(FCTSEN_pCamLaneData)
const t_CamLaneInputData      * FCTSEN_pCamLaneData;        /*!< Camera lane input data */
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
SET_MEMSEC_VAR(FCTSEN_pAccOOIData)
FCTSenAccOOI_t             * FCTSEN_pAccOOIData;
#endif

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/* Provide OOI-0 Object from SLATE to TJA */
SET_MEMSEC_VAR(FCTSEN_pOOITJAData)
TJATargetObj_t              * FCTSEN_pOOITJAData;
#endif

#if (FCT_CFG_RUNTIME_MEAS)
/*! FCT ACC time measurement info */
SET_MEMSEC_VAR(t_FCTSEN_RuntimeInfo)
FCT_t_RuntimeInfo t_FCTSEN_RuntimeInfo;/*!< FCT time freeze */
#endif

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_SLATE_COMPONENT))
SET_MEMSEC_VAR(t_SLATE_HC_Data)
static SLATE_HC_Data_t t_SLATE_HC_Data;/*PRQA S 3218  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
#if (FCT_CFG_SLATE_COMPONENT)
SET_MEMSEC_VAR(t_SLATE_SPM_Data)
static SLATE_SPM_Data_t t_SLATE_SPM_Data;// PRQA S 3218
/* date: 2017-10-31, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
#endif//FCT_CFG_SLATE_COMPONENT
#endif

#if ((FCT_CFG_COLLISION_DETECTION) && (FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
SET_MEMSEC_VAR(t_SLATE_CD_Data)
static SLATE_CD_Data_t t_SLATE_CD_Data;// PRQA S 3218
/* date: 2017-10-31, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
#endif

#if ((FCT_CFG_SIGNAL_PERF_MONITORING) && (FCT_CFG_LOHP_COMPONENT))
SET_MEMSEC_VAR(t_SPM_HC_Data)
static SPM_HC_Data_t t_SPM_HC_Data;/*PRQA S 3218  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#endif

#if (defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER))
SET_MEMSEC_CONST(FCTSEN_pTSAInputData)
const TSA_SLATE_Input_t * FCTSEN_pTSAInputData;       /*!< Required port pointer, TSA input data from camera */
#endif
#if (FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER))
SET_MEMSEC_CONST(FCTSEN_pCamSLAInputData)
const CamSLAInputData_t * FCTSEN_pCamSLAInputData;       /*!< Required port pointer, SLA input data from camera */
#endif

#if (FCT_CFG_SLA_FEATURE)
SET_MEMSEC_VAR(FCTSEN_pSLAData)
SLAData_t               * FCTSEN_pSLAData;   /*!< Provide port pointer, SLA speed limit data from FCT_SEN */
#endif

#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) && (FCT_CFG_ACC_HEADWAY_PLANNER))
SET_MEMSEC_VAR(t_LOHP_UsageState)
static LOHP_ObjUsageState_t   t_LOHP_UsageState;   /* Object Ids of relevant objects *//*PRQA S 3218  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#endif

#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
SET_MEMSEC_VAR(pt_FCT_OUT_TCSP)
TargetControlStatePort_t *pt_FCT_OUT_TCSP;     /* Status Output from LOHP to ISC */

SET_MEMSEC_VAR(pt_FCT_OUT_TFCP)
TargetFollowCommandPort_t *pt_FCT_OUT_TFCP; /* Command Output from LOHP to LOPC */
#endif

/* Instantiation of component port lists (LOHP) */
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
SET_MEMSEC_VAR(t_LOHP_RequirePorts)
LOHP_ReqPortList_t t_LOHP_RequirePorts;

SET_MEMSEC_VAR(t_LOHP_ProvidePorts)
LOHP_ProPortList_t t_LOHP_ProvidePorts;
#endif

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN - Simulation Freeze Addresses
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES 
*****************************************************************************/
#if (FCT_CFG_ACDC_COMPONENT)
#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
/* ACDC process memory */
static GA_ACDC_Mem_DataInterCycleMeas ACDCInterMeas = {0u};/*PRQA S 3218  */
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static GA_ACDC_Mem_DataInterCycle     ACDCInter     = {0u};/*PRQA S 3218  */
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static GA_ACDC_Mem_DataIntraCycleMeas ACDCIntraMeas = {0u};/*PRQA S 3218  */
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static GA_ACDC_Mem_DataIntraCycle     ACDCIntra     = {0u};/*PRQA S 3218  */
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#ifdef FCT_SIMU
static GA_ACDC_Mem_DataSimu           ACDCSimuData  = {0};
#endif
#endif
#endif /*(FCT_CFG_ACDC_COMPONENT)*/
/*****************************************************************************
  MODULE LOCAL VARIABLES - Simulation Freezes
*****************************************************************************/



/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (FCT_CFG_ACDC_COMPONENT)
#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
static void FCTSen_FreezeACDCProcMem(ACDC_ProcMem_t const * const pACDCProcMem);
#endif
static void FCTSen_v_ACDC_Process( reqACDCPrtList_t   const * const p_ACDCRequirePorts
                                  ,provACDCPrtList_t        * const p_ACDCProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                  ,AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif
  );
#endif /*(FCT_CFG_ACDC_COMPONENT)*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void FCTSenSetCompState (AlgoCompState_t * const pSenCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
static boolean FCTSenCheckServiceFunc( const AS_t_ServiceFuncts * pServiceFuncts );
#endif

static boolean FCTSenCheckReqPorts( const reqFCTSenPrtList_t * pRequirePorts );

static boolean FCTSenCheckReqPortsSigStatus( const reqFCTSenPrtList_t * pRequirePorts);

static boolean FCTSenCheckProPorts( const proFCTSenPrtList_t * pProvidePorts);

static void FCTSetSenFrameData( const reqFCTSenPrtList_t * pRequirePorts
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                               , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                               );


static void FCTSenPreProcessing(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                , GenAlgoQualifiers_t *const pErrorBuffer

#endif 
                                );

static void FCTSenSetInterfaceVersionProvidePorts( const proFCTSenPrtList_t * pProvidePorts );
static void FCTSenSetupPorts( const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts );

static void FCTSenSetupSyncRef(const reqFCTSenPrtList_t * pRequirePorts);
static void FCTSenSetProvideHeader(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts);
static void FCTSenSetProvideHeaderStates(const proFCTSenPrtList_t * pProvidePorts, AlgoSignalState_t eSigState);
#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
static void FCTSenCheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void FCTSenCheckProvideHeaders(reqFCTSenPrtList_t const * const pRequirePorts, proFCTSenPrtList_t const * const pProvidePorts); 
#endif

#if (FCT_CFG_RUNTIME_MEAS)
static void FCTSEN_RuntimeMeasInit(void);
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
 static void FCTSEN_SERVICE_ADD_EVENT_FCT( const RTA_t_Events      t_RuntimeEvtType, const sint32 u_EventID);
#else
 static void FCTSEN_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType t_RuntimeEvtType, const sint32 u_EventID);
#endif  /* ENDIF (RTA_INTERFACE_VERSION >= 4)) */
#else
 static void FCTSEN_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType t_RuntimeEvtType, const sint32 u_EventID);
#endif  /* (defined(RTA_INTERFACE_VERSION) */
#endif

/*! Utility function to set signal header to error */
static void FCTSenSetSigHeaderError(SignalHeader_t * const pSigHeader);

/*! Utility function to default fill signal header */
static void FCTSenFillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void FCTSenSetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);

/*! Initialize FCT_SEN provide ports */
#if (FCT_CFG_ERROR_OUTPUT_SEN)
static void FCTSen_v_InitErrorOut(FCTSenErrorOut_t * pDest);
#endif

#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
/*! Set SLATE provide ports based on FCT_SEN provide ports */
static void FctSen_v_SetSLATEProPort(const proFCTSenPrtList_t * p_ProvidePorts, 
#if (FCT_CFG_LOHP_COMPONENT)
  SLATE_HC_Data_t * pt_SLATE_HC_Data, 
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SLATE_SPM_Data_t * pt_SLATE_SPM_Data,
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  SLATE_CD_Data_t * pt_SLATE_CD_Data,
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  SLATEErrorOutProPort_t * p_SLATEErrorOut,
#endif 
  provSLATEPortList_t * p_SLATEProvidePorts);
  
/*! Set SLATE require ports based on FCT_SEN require ports */
static void FctSen_v_SetSLATEReqPort(const reqFCTSenPrtList_t * p_RequirePorts, reqSLATEPortList_t * p_SLATERequirePorts);

#endif /* END IF FCT_CFG_ADAPTIVE_CRUISE_CONTROL */

#if(FCT_CFG_SIGNAL_PERF_MONITORING)
static void FctSen_v_SetSPMReqPort(const reqFCTSenPrtList_t * p_RequirePorts, const AssessedObjList_t * pPubFctObj, 
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL == SWITCH_ON)
  SLATE_SPM_Data_t * pSLATE_SPM_Data,
#endif
  reqFCTSenSPMPrtList_t * p_SPMRequirePorts);

static void FctSen_v_SetSPMProPort(const proFCTSenPrtList_t * p_ProvidePorts
#if (FCT_CFG_LOHP_COMPONENT)
  , SPM_HC_Data_t * p_SPM_HC_Data
#endif
  , SPMProPort_t * p_SPMProvidePorts
#if(FCT_CFG_ERROR_OUTPUT_SEN)
  , SPMErrorOutProPort_t * const t_SPMErrorOut
#endif
);
#endif



/* Port List Assignment for Components (LOHP) */
#if (FCT_CFG_LOHP_COMPONENT)

#if (FCT_CFG_ACT_CODE_VERSION)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
static void FCTSen_v_Set_LOHP_Ports(LOHP_ReqPortList_t *pRequirePorts, LOHP_ProPortList_t *pProvidePorts, SPMProPort_t *pSPMProPorts);
#else
static void FCTSen_v_Set_LOHP_Ports(LOHP_ReqPortList_t *pRequirePorts, LOHP_ProPortList_t *pProvidePorts);
#endif

#else /* FCT_CFG_ACT_CODE_VERSION */
/*! Set HC provide ports based on FCT_SEN provide ports */
static void FCTSen_v_SetLOHPProPort(const proFCTSenPrtList_t * p_ProvidePorts, LOHP_ObjUsageState_t* pLOHPUsageState, LOHPProPort_t * p_LOHPProvidePorts);
/*! Set HC provide ports based on FCT_SEN provide ports */
static void FCTSen_v_SetLOHPReqPort(const reqFCTSenPrtList_t * p_RequirePorts, const AssessedObjList_t * p_PubFctObj, 
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  const FCTSenAccOOI_t* pFCTAccOOIData,
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  const FCTCustomInput_t * p_CustomInput,
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  const FCTCustomOutput_t * p_CustomOutput, 
#endif
#endif
#if (FCT_CFG_SLATE_COMPONENT)
  const SLATE_HC_Data_t * p_SLATE_LOHP_Data, 
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const SysPerfMonStates_t * pSysPerfMonStates,
#endif
  reqLOHPPrtList_t * p_LOHPRequirePorts);

#endif  /* FCT_CFG_ACT_CODE_VERSION */
#endif  /* FCT_CFG_LOHP_COMPONENT */


#if (FCT_CFG_ACDC_COMPONENT)
/* Set ACDC provide ports based on FCT_SEN provide ports */
static void FctSen_v_SetACDCProPort(proFCTSenPrtList_t     const * const p_FCTSenProvidePorts
                                   ,ACDCErrorOutProPort_t        * const pACDCErrorOut
                                   ,provACDCPrtList_t            *       p_ACDCProvidePorts);
/* Set ACDC require ports based on FCT_SEN require ports */
static void FctSen_v_SetACDCReqPort(reqFCTSenPrtList_t const * const p_FCTSenRequirePorts, 
#if ((FCT_CFG_COLLISION_DETECTION) && (FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
                                    SLATE_CD_Data_t    const * const pSLATE_CD_Data,
#endif
                                    reqACDCPrtList_t         *       p_ACDCRequirePorts);
#endif

static void FctSen_v_FusePorts(proFCTSenPrtList_t     const * const p_FCTSenProvidePorts
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
                              ,provSLATEPortList_t     const * const p_SLATEProvidePorts
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                              ,SPMProPort_t     const * const p_SPMProvidePorts
#endif
#if (FCT_CFG_ACDC_COMPONENT)
                              ,provACDCPrtList_t      const * const p_ACDCProvidePorts
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                              ,LOHPProPort_t          const * const p_LOHPProvidePorts
#endif
                              );

static void FCTSenPostProcessing(proFCTSenPrtList_t     const * const p_FCTSenProvidePorts
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
                                ,provSLATEPortList_t     const * const p_SLATEProvidePorts
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                                ,SPMProPort_t            const * const p_SPMProvidePorts
#endif
#if (FCT_CFG_ACDC_COMPONENT)
                                ,provACDCPrtList_t      const * const p_ACDCProvidePorts
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                ,LOHPProPort_t          const * const p_LOHPProvidePorts
#endif
                                );
/*! @endcond Doxygen_Suppress */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    FCTSEN_SERVICE_ADD_EVENT                                                                         */ /*!

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

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.05.2016
  @changed         04.05.2016


  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
void FCTSEN_SERVICE_ADD_EVENT( const RTA_t_Events RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#else
void FCTSEN_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#endif
#else
void FCTSEN_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#endif
{
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  if (    (FCTSen_p_GetFCTServicePointer()                           != NULL)
       && (FCTSen_p_GetFCTServicePointer()->pfRTAAlgoServiceAddEvent != NULL) )
  {
#ifdef RTA_GLOBALID_FCT_SEN
  FCTSen_p_GetFCTServicePointer()->pfRTAAlgoServiceAddEvent(RtaEvtType, RTA_GLOBALID_FCT_SEN, u_IdLocal + FCTFRAME_RTA_OFFSET, u_OptData);
#else
  FCTSen_p_GetFCTServicePointer()->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT60, u_IdLocal + FCTFRAME_RTA_OFFSET, u_OptData);
#endif/* (RTA_GLOBALID_FCT_SEN) */
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  /* Check NULL pointer. 
  Check whether additional parameter (i.e. Object ID) is defined. This cannot be handled */
  if (    (pFCTSenServiceFuncts                     != NULL)
       && (pFCTSenServiceFuncts->pfGetTimestampuS32 != NULL) 
       && (u_OptData                                           == 0   ))
  {
    FCTSEN_SERVICE_ADD_EVENT_FCT( RtaEvtType, (sint32)u_IdLocal);
  }
#endif
  _PARAM_UNUSED(RtaEvtType);//PRQA S 3119 3
 /* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Variable might be used in future*/
  _PARAM_UNUSED(u_IdLocal);
  _PARAM_UNUSED(u_OptData);
}

#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:    FCTSEN_RuntimeMeasInit                                                                           */ /*!

  @brief           Init global FCT runtime measurement array

  @description     Init global FCT runtime measurement array

  @return          -

  @param[in]       -

  @glob_in        -
  @glob_out         t_FCTSEN_RuntimeInfo.uRuntime : Array of size FCTSEN_RTA_NOF_CHECKPOINTS containing the runtime 
                        of FCT_SEN subcomponents (microseconds) [0u ... 1s]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_RUNTIME_MEAS : FCT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.05.2016
  @changed         04.05.2016

  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void FCTSEN_RuntimeMeasInit(void)
{
  uint32 i;
  /* Init global FCT runtime measurement array */
  for (i = 0u; i < FCTSEN_RTA_NOF_CHECKPOINTS; i++)
  {
    t_FCTSEN_RuntimeInfo.uRuntime[i]   = 0u;
  }
}
#endif /* FCT_CFG_RUNTIME_MEAS */

#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:    FCTSEN_SERVICE_ADD_EVENT_FCT                                                                         */ /*!

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

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.11.2015
  @changed         24.11.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
static void FCTSEN_SERVICE_ADD_EVENT_FCT( const RTA_t_Events       t_RuntimeEvtType, const sint32 u_EventID)
#else
static void FCTSEN_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
#endif
#else
  static void FCTSEN_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
#endif
{
  if(t_RuntimeEvtType == e_RTA_EVT_AlgoStart) 
  {
    FCT_ASSERT(t_FCTSEN_RuntimeInfo.uRuntime[u_EventID] == 0u);
    /* In case of a start event, the current timestamp is stored in the array. */
    t_FCTSEN_RuntimeInfo.uRuntime[u_EventID] = pFCTSenServiceFuncts->pfGetTimestampuS32();
  }
  else if(t_RuntimeEvtType == e_RTA_EVT_AlgoEnd)
  {
    FCT_ASSERT( t_FCTSEN_RuntimeInfo.uRuntime[u_EventID] > 0u);
    /* In case of an end event, the time difference between the start and end event is stored in the array. 
        Precondition: Valid start event must have been called before. */
    t_FCTSEN_RuntimeInfo.uRuntime[u_EventID] = pFCTSenServiceFuncts->pfGetTimestampuS32() - t_FCTSEN_RuntimeInfo.uRuntime[u_EventID];
  }
  else
  {
    /* Reset runtime info:
    if no valid event type
    if no valid start event has been called before the end event. */
    t_FCTSEN_RuntimeInfo.uRuntime[u_EventID] = 0u;
    FCT_ASSERT(FALSE);
  }
}
#endif /*FCT_CFG_RUNTIME_MEAS*/

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             FCTSenSetDem                                  */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTSenServiceFuncts connected to input service ports

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @todo           review
  @author         Christian Obst
**************************************************************************** */
void FCTSenSetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pFCTSenServiceFuncts != NULL) && (pFCTSenServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pFCTSenServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif /*FCT_CFG_USE_DEM*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)

/*************************************************************************************************************************
  Functionname:    FCTSenSetCompState                                                                               */ /*!

  @brief           Setup AlgoCompState

  @description  Setup AlgoCompState (output to Scheduler)

  @return          static void

  @param[in,out]   pSenCompState : 
  @param[in]       ScheduledOpMode : 
  @param[in]       BufferedQualifier : 

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author          Christian Obst
*************************************************************************************************************************/
static void FCTSenSetCompState (AlgoCompState_t * const pSenCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
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
  if (pSenCompState != NULL) 
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(pSenCompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pSenCompState->uiAlgoVersionNumber = FCTSenFrame.Versions.uiFCTSEN;
#if COMP_STATE_INTFVER > 2u
    pSenCompState->uiApplicationNumber = 0u;
    pSenCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pSenCompState->ApplicationNumber = 0u;
    pSenCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (FCTSenFrame.eFCTState)
    {
    case FCT_SEN_INIT:
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
    case FCT_SEN_RUN:
    case FCT_SEN_RG_HIGH:
      /*everything's fine*/
      pSenCompState->eCompState = COMP_STATE_RUNNING;
      pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pSenCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case FCT_SEN_SHUTDOWN:
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
    case FCT_SEN_ERROR:
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
  Functionname:    FCTSenSetupSyncRef                                                                               */ /*!

  @brief           Creates sync data for Simulation synchronization

  @description     1. Puts signal headers of all input ports into one structure 
                   2. Checks validity of interface
                   3. Sets sSigHeader of SyncRef structure (any NullPointer -> INVALID)

  @return          -

  @param[in]       pRequirePorts : The input data used by FCT component
                      pSenCtrlData : FCT COntrol data [FCTCtrlData_t as defined in Rte_Type.h]
                      pEgoDynObjSync : The dynamic vehicle ego data object sync [VehDyn_t as defined in Rte_Type.h]
                      pEgoDynRaw : The dynamic vehicle ego data raw [VehDyn_t as defined in Rte_Type.h]
                      pEgoStaticData : The static vehicle ego data [VehPar_t as defined in Rte_Type.h]
                      pEmGenObjList : EM generic object list [EM_t_GenObjectList as defined in Rte_Type.h]
                      pEmCustObjList : EM customer specific object list [EM_t_ObjectList_Custom as defined in Rte_Type.h]
                      pEmARSObjList : EM ARS-technology-specific object list [EM_t_ARSObjectList as defined in Rte_Type.h]
                      pEmCamObjList : EM Camera-technology-specific object list [EM_t_CamObjectList as defined in Rte_Type.h]
                      pEmFusionObjList : EM Fusion object list [EM_t_FusionObjectList as defined in Rte_Type.h]
                      pPubEmObj : The public EM object data [ObjectList_t as defined in Rte_Type.h]
                      pMovObjTraces : Moving object traces [MovingObjectTraces_t as defined in Rte_Type.h]
                      pRSPOutputPD : RSP roadbeam information [RSPOutputPD_t as defined in Rte_Type.h]
                      pPerfDegrData : Performance degradation input data [PerfDegr_t as defined in Rte_Type.h]
                      pRoadData : Road/lane information [Road_t as defined in Rte_Type.h]
                      pRSPContextData : RSP Kontext data [RSPKontextData_t as defined in interfacerspkontextdata.h]
                      pFctVehLongOut : Longitudinal control internal buffer for passing information from FCT_VEH to FCT_SEN [FctVeh2SenInfo_t as defined in Rte_Type.h]
                      pFCTCustomInput : Custom input [FCTCustomInput_t as defined in Rte_Type.h]
                      pCameraObjData : EM Camera fusion output data [EM_t_ObjectList_Custom as defined in Rte_Type.h]
                      pAlignmentMonInput : Alignment monitoring output data [ALN_Monitoring_t as defined in Rte_Type.h]
                      pVehSig : Direct access to vehicle signals [VehSig_t as defined in Rte_Type.h
                      pME_in : Input from mobil-eye directly for debugging [ME_in_t as defined in Rte_Type.h]
                      pCPAR_FCT_Parameters : FCT Coding parameters [CPAR_FCT_Parameters_t as defined in Rte_Type.h]
                      pPerfDegrExtInput : Performance degradation external input [PerfDegrExtInput_t  as defined in Rte_Type.h]
                      pDIMOutputCustom : Custom DIM input [DIMOutputCustom_t as defined in Rte_Type.h]
                      pNaviData : Navi input data to FCT [t_NaviInputData as defined in Rte_Type.h]
                      pCamLaneData : Camera lane input data [t_CamLaneInputData as defined in Rte_Type.h]
                      pSenCtrlData : FCT control data [FCTCtrlData_t as defined in Rte_Type.h]
                      pCamSLAInputData : SLA input data from camera
                      pTSAInputData : TSA input data from camera
                      sSigHeader : Signal Headers of every Input Port defined above is also an input to this function [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         FCTSenSyncRef : Simulation sync structure contains Signal Headers of every Input Port
                      EmFctCycleMode : [SignalHeader_t as defined in Rte_Type.h]

  @glob_out        FCTSenSyncRef : Simulation sync structure contains Signal Headers of every Input Port
                      sSigHeader.eSigStatus : [AlgoSignalState_t as defined by Rte_Type.h]
                      SenCtrlData : [SignalHeader_t as defined in Rte_Type.h]
                      sBaseCtrl : [BaseCtrlData_t as defined in Rte_Type.h]
                      EgoDynObjSync : [SignalHeader_t as defined in Rte_Type.h]
                      EgoDynRaw : [SignalHeader_t as defined in Rte_Type.h]
                      EgoStaticData : [SignalHeader_t as defined in Rte_Type.h]
                      EmFctCycleMode : [SignalHeader_t as defined in Rte_Type.h]
                      EmGenObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmCustObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmARSObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmCamObjList : [SignalHeader_t as defined in Rte_Type.h]
                      PubEmObj : [SignalHeader_t as defined in Rte_Type.h]
                      MovObjTraces : [SignalHeader_t as defined in Rte_Type.h]
                      RSPOutputPD : [SignalHeader_t as defined in Rte_Type.h]
                      PerfDegrData : [SignalHeader_t as defined in Rte_Type.h]
                      RoadData : [SignalHeader_t as defined in Rte_Type.h]
                      RSPContextData : [SignalHeader_t as defined in Rte_Type.h]
                      FctVehLongOut : [SignalHeader_t as defined in Rte_Type.h] 
                      FCTCustomInput : [SignalHeader_t as defined in Rte_Type.h]
                      CameraObjData : [SignalHeader_t as defined in Rte_Type.h]
                      AlignmentMonInput : [SignalHeader_t as defined in Rte_Type.h]
                      VehSig : [SignalHeader_t as defined in Rte_Type.h]
                      ME_in : [SignalHeader_t as defined in Rte_Type.h]
                      BswAlgoParameters : [SignalHeader_t as defined in Rte_Type.h]
                      CPAR_FCT_Parameters : [SignalHeader_t as defined in Rte_Type.h]
                      PerfDegrExtInput : [SignalHeader_t as defined in Rte_Type.h]
                      DIMOutputCustom : [SignalHeader_t as defined in Rte_Type.h]
                      NaviData : [SignalHeader_t as defined in Rte_Type.h]
                      CamLaneData : [SignalHeader_t as defined in Rte_Type.h]
                      pCamSLAInputData : [SignalHeader_t as defined in Rte_Type.h]
                      pTSAInputData : [SignalHeader_t as defined in Rte_Type.h]

  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode configuration switch
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_CUSTOM_OBJECT_LIST : Configuration switch enabling EM custom object list 
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list 
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_USE_EM_MOVING_OBJECT_TRACES : Configuration switch for EM old traces
  @c_switch_part   FCT_CFG_RSP_OUTPUT_PD : FCT has access to RSP output PD signal
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT
  @c_switch_part   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT direct access to vehicle signals
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of ALGO parameters to the FCT component
  @c_switch_part   FCT_CFG_CPAR_PARAMS : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_CFG_PERF_DEGR_EXT_INPUT : Configuration switch enabling PerfDegrExtInput_t type input to FCT_SEN
  @c_switch_part   FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT : Configuration switch enabling DIMOutputCustom to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   CamSLAInputData_INTFVER : Interface version number for port CamSLAInputData
  @c_switch_part   FCT_CFG_USE_BASECTRLDATA : Switch that enables the FCT Base Control Data struct and disables the OPMode-port

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.05.2013
  @changed         22.09.2017

  @author          Christian Obst | Christian.Obst@continental-corporation.com 
*************************************************************************************************************************/
static void FCTSenSetupSyncRef(const reqFCTSenPrtList_t * pRequirePorts)
{
  /*setting whole syncref to zero */
  (void)memset(&FCTSenSyncRef, 0, sizeof(FCTSenSyncRef));//PRQA S 0315
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Cast to void intended as use of generic interface */

  if (pRequirePorts != NULL)
  {
    /*pSenCtrlData*/
    if (pRequirePorts->pSenCtrlData != NULL)
    {
      FCTSenSyncRef.SenCtrlData          = pRequirePorts->pSenCtrlData->sSigHeader;
#if (FCT_CFG_USE_BASECTRLDATA)
      FCTSenSyncRef.sBaseCtrl            = *pRequirePorts->pSenCtrlData;
#endif
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pEgoDynObjSync*/
    if (pRequirePorts->pEgoDynObjSync != NULL)
    {
      FCTSenSyncRef.EgoDynObjSync         = pRequirePorts->pEgoDynObjSync->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*EgoDynRaw*/
    if (pRequirePorts->pEgoDynRaw != NULL)
    {
      FCTSenSyncRef.EgoDynRaw               = pRequirePorts->pEgoDynRaw->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*EgoStaticData*/
    if (pRequirePorts->pEgoStaticData != NULL)
    {
      FCTSenSyncRef.EgoStaticData           = pRequirePorts->pEgoStaticData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_EM_FCT_CYCLEMODE)
    /*pEmFctCycleMode*/
    /* Cycle mode struct currently has no signal header, reset to zero */
    /*FCTSenSyncRef.EmFctCycleMode        = pRequirePorts->pEmFctCycleMode->sSigHeader;*/
    FCTSenSetSigHeaderError(&FCTSenSyncRef.EmFctCycleMode);
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)
    /*pEmGenObjList*/
    if (pRequirePorts->pEmGenObjList != NULL)
    {
      FCTSenSyncRef.EmGenObjList          = pRequirePorts->pEmGenObjList->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    /*pEmCustObjList*/
    if (pRequirePorts->pEmCustObjList != NULL)
    {
      FCTSenSyncRef.EmCustObjList         = pRequirePorts->pEmCustObjList->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    /*pEmARSObjList*/
    if (pRequirePorts->pEmARSObjList != NULL)
    {
      FCTSenSyncRef.EmARSObjList          = pRequirePorts->pEmARSObjList->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    /*pEmCamObjList*/
    if (pRequirePorts->pEmCamObjList != NULL)
    {
      FCTSenSyncRef.EmCamObjList          = pRequirePorts->pEmCamObjList->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
    if (pRequirePorts->pMovObjTraces != NULL)
    {
      FCTSenSyncRef.MovObjTraces          = pRequirePorts->pMovObjTraces->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_NEW_TRACES_INTERFACE)
    /*pObjectTraces*/
    if (pRequirePorts->pObjectTraces != NULL)
    {
      FCTSenSyncRef.ObjectTraces          = pRequirePorts->pObjectTraces->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
#endif

#if (FCT_CFG_RSP_OUTPUT_PD)
    /*pRSPOutputPD*/
    if (pRequirePorts-> != NULL)
    {
      FCTSenSyncRef.RSPOutputPD             = pRequirePorts->pRSPOutputPD->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    /*pPerfDegrData*/
    if (pRequirePorts->pPerfDegrData != NULL)
    {
      FCTSenSyncRef.PerfDegrData            = pRequirePorts->pPerfDegrData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ROAD_INPUT)
    /*pRoadData*/
    if (pRequirePorts->pRoadData != NULL)
    {
      FCTSenSyncRef.RoadData                = pRequirePorts->pRoadData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_RSP_CONTEXT_INPUT)
    /*pRSPContextData*/
    if (pRequirePorts->pRSPContextData != NULL)
    {
      FCTSenSyncRef.RSPContextData          = pRequirePorts->pRSPContextData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_LOPC_COMPONENT)
    /*pFctVehLongOut*/
    if (pRequirePorts->pFctVehLongOut != NULL)
    {
      FCTSenSyncRef.FctVehLongOut           = pRequirePorts->pFctVehLongOut->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    /*pFCTCustomInput*/
    if (pRequirePorts->pFCTCustomInput != NULL)
    {
      FCTSenSyncRef.FCTCustomInput          = pRequirePorts->pFCTCustomInput->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) && (!FCT_USE_EM_CUSTOM_OBJECT_LIST))
    /*pCameraObjData*/
    if (pRequirePorts->pCameraObjData != NULL)
    {
      FCTSenSyncRef.CameraObjData           = pRequirePorts->pCameraObjData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
    /*pAlignmentMonInput*/
    if (pRequirePorts->pAlignmentMonInput != NULL)
    {
      FCTSenSyncRef.AlignmentMonInput       = pRequirePorts->pAlignmentMonInput->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_SEN_CFG_VEH_SIG_INPUT)
    /*pVehSig*/
    if (pRequirePorts->pVehSig != NULL)
    {
      FCTSenSyncRef.VehSig                  = pRequirePorts->pVehSig->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
    /*pME_in*/
    if (pRequirePorts->pME_in != NULL)
    {
      FCTSenSyncRef.ME_in                  = pRequirePorts->pME_in->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
  /* BSW algo parameters currently has no signal header */
  /*FCTSenSyncRef.BswAlgoParameters       = pRequirePorts->pBswAlgoParameters->sSigHeader;*/
  FCTSenSetSigHeaderError(&FCTSenSyncRef.BswAlgoParameters);
#endif

#if (FCT_CFG_CPAR_PARAMS)
    /*pCPAR_FCT_Parameters*/
  if (pRequirePorts->pCPAR_FCT_Parameters != NULL)
  {
    FCTSenSyncRef.CPAR_FCT_Parameters     = pRequirePorts->pCPAR_FCT_Parameters->sSigHeader;
  }
  else
  {
    FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
#endif

#if (FCT_CFG_PERF_DEGR_EXT_INPUT)
    /*pPerfDegrExtInput*/
    if (pRequirePorts->pPerfDegrExtInput != NULL)
    {
      FCTSenSyncRef.PerfDegrExtInput       = pRequirePorts->pPerfDegrExtInput->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT)
    /*pDIMOutputCustom*/
    if (pRequirePorts->pDIMOutputCustom != NULL)
    {
      FCTSenSyncRef.DIMOutputCustom         = pRequirePorts->pDIMOutputCustom->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)
    /*pNaviData*/
    if (pRequirePorts->pNaviData != NULL)
    {
      FCTSenSyncRef.NaviData                = pRequirePorts->pNaviData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_SEN_CAM_LANE_INTERFACE)
    /*pCamLaneData*/
    if (pRequirePorts->pCamLaneData != NULL)
    {
      FCTSenSyncRef.CamLaneData             = pRequirePorts->pCamLaneData->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    /*pEmFusionObjList*/
    if (pRequirePorts->pEmFusionObjList != NULL)
    {
      FCTSenSyncRef.EmFusionObjList         = pRequirePorts->pEmFusionObjList->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    if (pRequirePorts->pSenCtrlData != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      FCTSenFillSigHeader(&FCTSenSyncRef.sSigHeader, &pRequirePorts->pSenCtrlData->sSigHeader);
      FCTSenSetSigHeaderState(&FCTSenSyncRef.sSigHeader, AL_SIG_STATE_OK);
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }

#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /*Camera TSA Input*/
  if (pRequirePorts->pTSAInputData != NULL)// PRQA S 505
  /* date: 2018-02-26, reviewer: Ravi kiran Gurrala, reason: being checked before calling this function  */
  {
    FCTSenSyncRef.CamTSAInputData     = pRequirePorts->pTSAInputData->sSigHeader;
  }
  else
  {
    FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
#endif

#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /*Camera SLA Input*/
  if (pRequirePorts->pCamSLAInputData != NULL)
  {
    FCTSenSyncRef.CamSLAInputData     = pRequirePorts->pCamSLAInputData->sSigHeader;
  }
  else
  {
    FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
#endif

#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
    /* t_SH_LongCtrlResp */
    if (pRequirePorts->pLongCtrlResp != NULL)
    {
      FCTSenSyncRef.t_SH_LongCtrlResp = pRequirePorts->pLongCtrlResp->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* t_FCT_IN_SH_TCCP */
    if (pRequirePorts->pt_FCT_IN_TCCP != NULL)
    {
      FCTSenSyncRef.t_FCT_IN_SH_TCCP = pRequirePorts->pt_FCT_IN_TCCP->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /* t_FCT_IN_SH_TFSP */
    if (pRequirePorts->pt_FCT_IN_TFSP != NULL)
    {
      FCTSenSyncRef.t_FCT_IN_SH_TFSP = pRequirePorts->pt_FCT_IN_TFSP->sSigHeader;
    }
    else
    {
      FCTSenSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

}// PRQA S 7002
/* date: 2019-02-25, reviewer: Timken George, reason: doesn't impact the functionality*/

/*************************************************************************************************************************
  Functionname:    FCTSenCheckServiceFunc                                                                                 */ /*!

  @brief           Check the Service functions pointers for valid pointer

  @description     Check if the pointer to the service function is valid. If not, set the boolean
                   to TRUE, otherwise a FALSE boolean is sent out.
                   @startuml FCTSenCheckServiceFunc_activity.png
                   start
                     partition "Execute for all Service function pointers"{
                       if  (Service function pointers are not valid?) then (No)
                           :Set the b_ServiceFuncError to TRUE;
                       else(Yes)
                           :Set the b_ServiceFuncError to FALSE;
                       endif
                   stop
                   @enduml

  @return          b_ServiceFuncError: TRUE if service function pointers are not valid

  @param[in]       pServiceFuncts : Reference to service functions provided by Frame            [AS_t_ServiceFuncts as defined in algo_services_types.h]

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_USE_SERVICE_POINTER_FUNCTS : FCT switch to use third parameter in Exec methods to call the Function. 
                                                        Third parameter is a structure to service functions provided by the Frame.
  @c_switch_part   FCT_CFG_RTA_PROFILING : Configuration switch for enabling profiling on ECU
  @c_switch_part   FCT_CFG_USE_FREEZE_CYCLE_START : FCT switch to enable setting of Measfreeze Cycle Start Service
  @c_switch_part   FCT_CFG_USE_DEM : Switch that enables the DEM reporting towards Service Interface

  
  @c_switch_full   -

  @pre             -
  @post            No changes 

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.02.2018

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean FCTSenCheckServiceFunc( const AS_t_ServiceFuncts * pServiceFuncts )// PRQA S 3219, 3450
/* date: 2018-04-10, reviewer: Ravikiran Gurrala, reason: Will be used in future.*/
{
  boolean b_ServiceFuncError;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)                             
  /* Assign Service functions to internal global alias no matter if NULL or not (used for DEM events) */
  pFCTSenServiceFuncts = pServiceFuncts;
#endif

  /* Check for NULL pointer of the service function pointers */
  if ( (pServiceFuncts == NULL)
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
    )
  {
    /* Error boolean is set to true when any of the above pointers are NULL */
    b_ServiceFuncError = TRUE;
  }
  else
  {
    /* No Error */
    b_ServiceFuncError = FALSE;
  }

  return b_ServiceFuncError;
}

/*************************************************************************************************************************
  Functionname:    FCTSenCheckReqPorts                                                                                 */ /*!

  @brief           Check the require ports for valid pointers

  @description     Check if the require port pointers are valid. If not, set the boolean
                   to TRUE, otherwise a FALSE boolean is sent out.
                   @startuml FCTSenCheckReqPorts_activity.png
                   start
                     partition "Execute for all require ports" {
                       if  (Any of the Require port pointers is NULL?) then (No)
                           :Set the b_RequirePortError to TRUE;
                       else(Yes)
                           :Set the b_RequirePortError to FALSE;
                       endif
                     }
                   stop
                   @enduml

  @return          b_RequirePortError: TRUE if any of the Require port pointers is NULL

  @param[in]       pRequirePorts : the inputs passed to the FCT_SEN main function               [reqFCTSenPrtList_t as defined in fct_sen_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode (ARS3xx specific)
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_CUSTOM_OBJECT_LIST : Configuration switch enabling EM custom object list 
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_USE_EM_MOVING_OBJECT_TRACES : Switch for EM-OLD traces
  @c_switch_part   FCT_CFG_NEW_TRACES_INTERFACE : Switch for EM-NEW traces (INCOMPLETE Implementation, NOT ACTIVE)
  @c_switch_part   FCT_CFG_RSP_OUTPUT_PD : FCT has access to RSP output PD signal
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT
  @c_switch_part   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface 
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide port structures, 
                                                  even if the current configuration does not use them. This enables the adapter to 
                                                  be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT uses direct access to vehicle signals
  @c_switch_part   FCT_CFG_ME_INPUT_FOR_DEBUG : FCT configuration for debugging input of MOBIL-eye data (only meas output)
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT component.
                                              This should be enabled, if the SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS : Configuration switch enabling usage of the FCT Coding Parameters Port 
  @c_switch_part   FCT_CFG_PERF_DEGR_EXT_INPUT : Configuration switch enabling PerfDegrExtInput_t type input to FCT_SEN
  @c_switch_part   FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT : Configuration switch enabling DIMOutputCustom to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_USE_DEM : Switch that enables the DEM reporting towards Service Interface
  @c_switch_part   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK : Switch that enables signal status input check
  @c_switch_part   TSA_SLATE_INPUT_ENABLE : RTE Interface for camera TSA input
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   CamSLAInputData_INTFVER : Interface version number for port CamSLAInputData
  @c_switch_part   FCT_CFG_ACT_CODE_VERSION : Configuration switch for enabling revised ACT Code

  
  @c_switch_full   -

  @pre             -
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.02.2018

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean FCTSenCheckReqPorts( const reqFCTSenPrtList_t * pRequirePorts )
{
  boolean b_RequirePortError;

  /* Check if require port pointers are set to non NULL */
  if ( (pRequirePorts == NULL)
    || (pRequirePorts->pSenCtrlData == NULL)
#if (FCT_CFG_EM_FCT_CYCLEMODE)
    || (pRequirePorts->pEmFctCycleMode == NULL)
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
    || (pRequirePorts->pEmGenObjList == NULL)
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    || (pRequirePorts->pEmCustObjList == NULL)
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    || (pRequirePorts->pEmARSObjList == NULL)
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    || (pRequirePorts->pEmCamObjList == NULL)
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
    || (pRequirePorts->pMovObjTraces == NULL)
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
    || (pRequirePorts->pObjectTraces == NULL)
#endif
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
    || (pRequirePorts->pEmSRRObjList == NULL)
    || (pRequirePorts->pEmGlobalOutput == NULL)
#endif
#endif
    || (pRequirePorts->pEgoDynObjSync == NULL)
    || (pRequirePorts->pEgoDynRaw == NULL)
    || (pRequirePorts->pEgoStaticData == NULL)
#if (FCT_CFG_RSP_OUTPUT_PD)
    || (pRequirePorts->pRSPOutputPD == NULL)
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    || (pRequirePorts->pPerfDegrData == NULL)
#endif
#if (FCT_CFG_ROAD_INPUT)
    || (pRequirePorts->pRoadData == NULL)
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
    || (pRequirePorts->pRSPContextData == NULL)
#endif
#if (FCT_CFG_LOPC_COMPONENT)
    || (pRequirePorts->pFctVehLongOut == NULL)
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pFCTCustomInput == NULL)
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) && ((!FCT_USE_EM_CUSTOM_OBJECT_LIST))) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pCameraObjData == NULL)
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pAlignmentMonInput == NULL)
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pVehSig == NULL)
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pME_in == NULL)
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pBswAlgoParameters == NULL)
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pCPAR_FCT_Parameters == NULL)
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pPerfDegrExtInput == NULL)
#endif
#if ((FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pDIMOutputCustom == NULL)
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pNaviData == NULL)
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pCamLaneData == NULL)
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    || (pRequirePorts->pEmFusionObjList == NULL)
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pTSAInputData == NULL)
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pRequirePorts->pCamSLAInputData == NULL)
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
    || (pRequirePorts->pLongCtrlResp == NULL)
    || (pRequirePorts->pt_FCT_IN_TCCP == NULL)
    || (pRequirePorts->pt_FCT_IN_TFSP == NULL)
#endif
    )
  {
    /* Some require port pointer is NULL */
    b_RequirePortError = TRUE;
  }
  else
  {
    /* All valid require port pointers */
    b_RequirePortError = FALSE;
  }

  return b_RequirePortError;
}

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*************************************************************************************************************************
  Functionname:    FCTSenCheckReqPortsSigStatus                                                                                 */ /*!

  @brief           Check the require ports signal status for valid status

  @description     Check if the require port signal statuses are valid. If not, set the boolean
                   to TRUE, otherwise a FALSE boolean is sent out.
                   @startuml FCTSenCheckReqPortsSigStatus_activity.png
                   start
                     partition "Execute for all Require port's signal status" {
                       if  (Any of the Require port's signal status is invalid?) then (No)
                           :Set the b_ReqPortSigStatusError to TRUE;
                       else(Yes)
                           :Set the b_ReqPortSigStatusError to FALSE;
                       endif
                   stop
                   @enduml

  @return          b_ReqPortSigStatusError: TRUE if any of the Require port signal status is NULL

  @param[in]       pRequirePorts : the inputs passed to the FCT_SEN main function               [reqFCTSenPrtList_t as defined in fct_sen_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK : Switch that enables signal status input check
  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode (ARS3xx specific)
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_CUSTOM_OBJECT_LIST : Configuration switch enabling EM custom object list 
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_USE_EM_MOVING_OBJECT_TRACES : Switch for EM-OLD traces
  @c_switch_part   FCT_CFG_NEW_TRACES_INTERFACE : Switch for EM-NEW traces (INCOMPLETE Implementation, NOT ACTIVE)
  @c_switch_part   FCT_CFG_RSP_OUTPUT_PD : FCT has access to RSP output PD signal
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT
  @c_switch_part   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface 
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide port structures, 
                                                  even if the current configuration does not use them. This enables the adapter to 
                                                  be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT uses direct access to vehicle signals
  @c_switch_part   FCT_CFG_ME_INPUT_FOR_DEBUG : FCT configuration for debugging input of MOBIL-eye data (only meas output)
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT component.
                                              This should be enabled, if the SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS : Configuration switch enabling usage of the FCT Coding Parameters Port 
  @c_switch_part   FCT_CFG_PERF_DEGR_EXT_INPUT : Configuration switch enabling PerfDegrExtInput_t type input to FCT_SEN
  @c_switch_part   FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT : Configuration switch enabling DIMOutputCustom to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_USE_DEM : Switch that enables the DEM reporting towards Service Interface
  @c_switch_part   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK : Switch that enables signal status input check
  @c_switch_part   TSA_SLATE_INPUT_ENABLE : RTE Interface for camera TSA input
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   CamSLAInputData_INTFVER : Interface version number for port CamSLAInputData
  @c_switch_part   FCT_CFG_ACT_CODE_VERSION : Configuration switch for enabling revised ACT Code

  
  @c_switch_full   -

  @pre             -
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.02.2018

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean FCTSenCheckReqPortsSigStatus( const reqFCTSenPrtList_t * pRequirePorts)
{
  boolean b_ReqPortSigStatusError;

  if  ( (pRequirePorts->pSenCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_EM_FCT_CYCLEMODE)
      /*no SigHeader*/
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
     || (pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
     || (pRequirePorts->pEmCustObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
     || (pRequirePorts->pEmARSObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
     || (pRequirePorts->pEmCamObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
     || (pRequirePorts->pMovObjTraces->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
     || (pRequirePorts->pObjectTraces->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
     || (pRequirePorts->pEmSRRObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
     || (pRequirePorts->pEmGlobalOutput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif
     || (pRequirePorts->pEgoDynObjSync->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
     || (pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
     || (pRequirePorts->pEgoStaticData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_RSP_OUTPUT_PD)
     || (pRequirePorts->pRSPOutputPD->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
     || (pRequirePorts->pPerfDegrData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_ROAD_INPUT)
     || (pRequirePorts->pRoadData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
     || (pRequirePorts->pRSPContextData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_LOPC_COMPONENT)
     || (pRequirePorts->pFctVehLongOut->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pFCTCustomInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) && ((!FCT_USE_EM_CUSTOM_OBJECT_LIST))) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pCameraObjData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pAlignmentMonInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pVehSig->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pME_in->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     /*no SigHeader*/
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pPerfDegrExtInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT)          || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pDIMOutputCustom->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)                || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pNaviData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pCamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
     || (pRequirePorts->pEmFusionObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pTSAInputData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
     || (pRequirePorts->pCamSLAInputData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
     )
  {
    /* Error in the signal status of the require ports (AL_SIG_STATE_INVALID) */
    b_ReqPortSigStatusError = TRUE;
  }
  else
  {
    /* Signal status of the require ports are valid */
    b_ReqPortSigStatusError = FALSE;
  }

  return b_ReqPortSigStatusError;
}
#endif

/*************************************************************************************************************************
  Functionname:    FCTSenCheckProPorts                                                                                 */ /*!

  @brief           Check the provide ports buffers for valid pointers

  @description     Check if the provide port pointers are valid. If not, set the boolean
                   to TRUE, otherwise a FALSE boolean is sent out.
                   @startuml FCTSenCheckProPorts_activity.png
                   start
                     partition "Execute for all Provide ports" {
                       if  (Any of the Provide port pointers is NULL?) then (No)
                           :Set the b_ProvidePortError to TRUE;
                       else(Yes)
                           :Set the b_ProvidePortError to FALSE;
                       endif
                   stop
                   @enduml

  @return          b_ProvidePortError: TRUE if any of the Require port pointers is NULL

  @param[in]       pProvidePorts : the outputs from FCT_SEN                                     [proFCTSenPrtList_t as defined in fct_sen_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC           : Object list processing interface input/output
  @c_switch_part   FCT_CFG_ASSESSED_OBJ_OUT_INTF      : Interface switch
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING     : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE : FCT CD sub-component custom output interface
  @c_switch_part   FCT_CFG_COLLISION_DETECTION        : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_LOHP_COMPONENT             : Configuration switch for enabling LOHP processing
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE        : FCT custom I/O interface
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN           : FCT error output from FCT_SEN
  @c_switch_part   FCT_CFG_SENSOR_CONTROL_INTF        : FCT sensor control interface
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE          : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT       : FCT config for sensor to vehicle ACC Object of interest Port as defined in Rte_SWCEmAdapt_Type.h
  @c_switch_part   FCT_CFG_SEN2TJA_ACC_OOI_PORT       : FCT config switch to TJA provide port
  @c_switch_part   FCT_CFG_SLA_FEATURE                : Activation switch for SLA support
  @c_switch_part   FCT_CFG_LOHP_COMPONENT             : FCT switch for LOHP Component for ACC

  @c_switch_full   -

  @pre             -
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.02.2018

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean FCTSenCheckProPorts( const proFCTSenPrtList_t * pProvidePorts)
{
  boolean b_ProvidePortError;

  /* Verify that provide port buffer pointers are set (non-null) */
  if ( (pProvidePorts == NULL)
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    || (pProvidePorts->pPubFctObj == NULL)
#endif
#endif
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
    || (pProvidePorts->pFctSRFStates == NULL)
#endif
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pSysPerfMonStates == NULL)
#endif
#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pAccDisplayObj == NULL)
    || (pProvidePorts->pAccOutput == NULL)
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pFCTCustomOutput == NULL)
#endif
#if ((FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pCollDetOutput == NULL)
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pFCTCDHypotheses == NULL)
#endif
#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pErrorOut == NULL)
#endif
#if ((FCT_CFG_SENSOR_CONTROL_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pSensorCtrl == NULL)
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    || (pProvidePorts->pSenCompState == NULL)
#endif
#if ((FCT_CFG_USE_BUS_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pFCTSenBusDebugData == NULL)
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pFCTAccOOIData == NULL)
#endif
#if ((FCT_CFG_SEN2TJA_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pFCTTJAOOIData == NULL)
#endif
#if ((FCT_CFG_SLA_FEATURE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    || (pProvidePorts->pSLAData == NULL)
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
    || (pProvidePorts->pt_FCT_OUT_TCSP == NULL)
    || (pProvidePorts->pt_FCT_OUT_TFCP == NULL)
#endif
    )
  {
    /* Some provide port pointer is NULL */
    b_ProvidePortError = TRUE;
  }
  else
  {
    /* NO Error */
    b_ProvidePortError = FALSE;
  }

  return b_ProvidePortError;
}

/*************************************************************************************************************************
  Functionname:    FCTSetSenFrameData                                                                               */ /*!

  @brief           Set the Frame Data for Freeze

  @description     Set the Frame Data for Freeze, i.e. FCT operation mode and component version number

  @return          -

  @param[in]       pRequirePorts : the inputs passed to the FCT_SEN main function [reqFCTSenPrtList_t as defined in fct_sen_ext.h]
  @param[in]       pErrorBuffer : error buffer [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]

  @glob_in         -
  @glob_out        FCTSenFrame :  FCT frame consisting of cycle time, cycle counter and opmode [as defined in fct_sen.h]
                      FCTSenFrame.eFCTOpMode : FCT requested operation mode       [FCT_OP_MODE_t as defined in Rte_Type.h]
                      FCTSenFrame.uiCycleCounter : The FCT_SEN cycle counter      [AlgoCycleCounter_t as defined in Rte_Type.h]
                      FCTSenFrame.Versions.uiCP : FCT sub-component version       [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.uiSI : FCT sub-component version       [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.uiCD : FCT sub-component version       [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.uiSPM : FCT sub-component version      [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.uiFIP : FCT sub-component version      [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.uProjectID : FCT sub-component version [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.FctVersionNumVar : FCT sub-component version [FCTSwVersion_t as defined in fct_ver.h]
                      FCTSenFrame.Versions.uiFCTSEN : FCT sub-component version [FCTSwVersion_t as defined in fct_ver.h]

  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT switch for CP sub-component
  @c_switch_part   FCT_CFG_SLATE_COMPONENT : FCT switch for ACC object selection 
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring switch
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   -

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         21.05.2013
  @changed         09.11.2015

  @author          Clemens Schnurr | clemens.schnurr@continental-corporation.com
*************************************************************************************************************************/
static void FCTSetSenFrameData( const reqFCTSenPrtList_t * pRequirePorts
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                               , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                               ) 
{
  /* Store operation mode received from outside in sen frame for freezing */
  if ((pRequirePorts != NULL)&&(pRequirePorts->pSenCtrlData != NULL))
  {
#if (FCT_CFG_USE_BASECTRLDATA)
    switch (pRequirePorts->pSenCtrlData->eOpMode)
    {
    case BASE_OM_RUN:
      FCTSenFrame.eFCTOpMode = FCT_MOD_RUNNING;
      break;
    case BASE_OM_IDLE:
    case BASE_OM_RESET:
    default:
      FCTSenFrame.eFCTOpMode = FCT_MOD_INIT;
      break;
    }
#else
    FCTSenFrame.eFCTOpMode = pRequirePorts->pSenCtrlData->OpMode;
#endif
  }
  else
  {
    FCTSenFrame.eFCTOpMode = FCT_MOD_SHUTDOWN;
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSenSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    FCTSenSignalErrorShutdown(FALSE);
  }
  FCTSenFrame.uiCycleCounter++;


#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  FCTSenFrame.Versions.uiSPM               =   SPM_VERSION;
#endif


  FCTSenFrame.Versions.uProjectID          =   (uint32)FCTALL_SW_PROJ_ID;
  FCTSenFrame.Versions.FCT_VERSION_AS_TEXT =   FCTALL_SW_VERSION_NUMBER;
  FCTSenFrame.Versions.uiFCTSEN            =   FCTALL_SW_VERSION_NUMBER;
}

/*************************************************************************************************************************
  Functionname:    FCTSenSetProvideHeader                                                                           */ /*!

  @brief           Set the signal headers of provide ports

  @description     Set the signal headers of provide ports

  @return          -

  @param[in]       pRequirePorts : Pointer to FCT_SEN output ports
  @param[in]       pProvidePorts : 
                      pPubFctObj->sSigHeader            [SignalHeader_t as defined in Rte_Type.h]
                      pEmGenObjList->sSigHeader         [SignalHeader_t as defined in Rte_Type.h]
                      pSysPerfMonStates->sSigHeader     [SignalHeader_t as defined in Rte_Type.h]
                      pPerfDegrData->sSigHeader         [SignalHeader_t as defined in Rte_Type.h]
                      pAccDisplayObj->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pEmGenObjList->sSigHeader         [SignalHeader_t as defined in Rte_Type.h]
                      pAccOutput->sSigHeader            [SignalHeader_t as defined in Rte_Type.h]
                      pFCTCustomOutput->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pCollDetOutput->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pFCTCDHypotheses->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pErrorOut->sSigHeader             [SignalHeader_t as defined in Rte_Type.h]
                      pSensorCtrl->sSigHeader           [SignalHeader_t as defined in Rte_Type.h]
                      pFCTAccOOIData->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pSLAData->sSigHeader              [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP processing
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface 
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide port structures, even if the current configuration does not use them. 
                                                 This enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE : FCT CD sub-component custom output interface
  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN
  @c_switch_part   FCT_CFG_SENSOR_CONTROL_INTF : FCT sensor control interface
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Switch for OOI port to vehicle task
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   CamSLAInputData_INTFVER : Interface version number for port CamSLAInputData
  @c_switch_full   None 

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.6.2013
  @changed         22.09.2017

  @author          Christian Obst | christian.obst@continental-corporation.com
*************************************************************************************************************************/
static void FCTSenSetProvideHeader(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts) 
{
#if ((FCT_CFG_OBJECT_LIST_PROC) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if ((FCT_CFG_ASSESSED_OBJ_OUT_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pPubFctObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#endif
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pSysPerfMonStates->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pAccDisplayObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
  FCTSenFillSigHeader(&pProvidePorts->pAccOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pFCTCustomOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pCollDetOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pFCTCDHypotheses->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SENSOR_CONTROL_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pSensorCtrl->sSigHeader, pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pFCTAccOOIData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SEN2TJA_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pFCTTJAOOIData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_SLA_FEATURE)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pSLAData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_SLA_FEATURE)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenFillSigHeader(&pProvidePorts->pSLAData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
  FCTSenFillSigHeader(&pProvidePorts->pt_FCT_OUT_TCSP->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
  FCTSenFillSigHeader(&pProvidePorts->pt_FCT_OUT_TFCP->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
}

#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
/*************************************************************************************************************************
  Functionname:    FCTSenCheckProvideHeader                                                                         */ /*!

  @brief           Check whether the signal header has changed during the call of the components

  @description     Check whether the signal header has changed during the call of the components

  @return          -

  @param[in]       pProvidedSigHeader : 
  @param[in]       pReceivedSigHeader : 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSenCheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
{
  _PARAM_UNUSED(pProvidedSigHeader);
  _PARAM_UNUSED(pReceivedSigHeader);

  CML_ASSERT(    (pProvidedSigHeader->uiMeasurementCounter == pReceivedSigHeader->uiMeasurementCounter)
              && (pProvidedSigHeader->uiTimeStamp          == pReceivedSigHeader->uiTimeStamp         )
            /*&& (pProvidedSigHeader->eSigStatus           != AL_SIG_STATE_INVALID                    )*/ );
}

/*************************************************************************************************************************
  Functionname:    FCTSenCheckProvideHeaders                                                                        */ /*!

  @brief           Call the check of the SigHeader for all used ports

  @return          -

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         22.09.2017

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSenCheckProvideHeaders(reqFCTSenPrtList_t const * const pRequirePorts, proFCTSenPrtList_t const * const pProvidePorts) 
{
#if ((FCT_CFG_OBJECT_LIST_PROC) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if ((FCT_CFG_ASSESSED_OBJ_OUT_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pPubFctObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#endif
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pSysPerfMonStates->sSigHeader, &pRequirePorts->pPerfDegrData->sSigHeader);
#endif
#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pAccDisplayObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
  FCTSenCheckProvideHeader(&pProvidePorts->pAccOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pFCTCustomOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pCollDetOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pFCTCDHypotheses->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SENSOR_CONTROL_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pSensorCtrl->sSigHeader, pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pFCTAccOOIData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SEN2TJA_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pFCTTJAOOIData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && FCT_CFG_SLA_FEATURE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pSLAData->sSigHeader, &pRequirePorts->pTSAInputData->sSigHeader);
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(SLAData_INTFVER) && FCT_CFG_SLA_FEATURE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenCheckProvideHeader(&pProvidePorts->pSLAData->sSigHeader, &pRequirePorts->pCamSLAInputData->sSigHeader);
#endif
}
#endif

/*************************************************************************************************************************
  Functionname:    FCTSenSetProvideHeaderStates                                                                     */ /*!

  @brief           Set the state in the SigHeader for all used provide ports

  @return          -

  @param[in]       pProvidePorts : 
  @param[in]       eSigState : 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         22.09.2017

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSenSetProvideHeaderStates(const proFCTSenPrtList_t * pProvidePorts, AlgoSignalState_t eSigState) 
{
#if ((FCT_CFG_OBJECT_LIST_PROC) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if ((FCT_CFG_ASSESSED_OBJ_OUT_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pPubFctObj->sSigHeader, eSigState);
#endif
#endif
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pSysPerfMonStates->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pAccDisplayObj->sSigHeader, eSigState);
  FCTSenSetSigHeaderState(&pProvidePorts->pAccOutput->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pFCTCustomOutput->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pCollDetOutput->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pFCTCDHypotheses->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pErrorOut->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_SENSOR_CONTROL_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pSensorCtrl->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pFCTAccOOIData->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_SEN2TJA_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pFCTTJAOOIData->sSigHeader, eSigState);
#endif
#if ((FCT_CFG_SLA_FEATURE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenSetSigHeaderState(&pProvidePorts->pSLAData->sSigHeader, eSigState);
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
  FCTSenSetSigHeaderState(&pProvidePorts->pt_FCT_OUT_TCSP->sSigHeader, eSigState);
  FCTSenSetSigHeaderState(&pProvidePorts->pt_FCT_OUT_TFCP->sSigHeader, eSigState);
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTSenPreProcessing                                                                              */ /*!

  @brief           Do FCT sensor information pre-processing

  @description     Do pre-processing needed by FCT component. 
                    - Calls function for setting the interface versions of the provide ports
                    - Checks signal header status
                    - Calls function for calculation of the sensor position relative to CoG and 
                      for updating ego motion matrices based on current motion data
                    - Calls function for preprocessing of object list
                    - Calls FIPProcess
                    - Preprocessing based on FCT state
                    - Checking of input measurement counters for service pointer

  @return          -

  @param[in]       pRequirePorts : the inputs passed to FCT_SEN
                    pEmGenObjList->sSigHeader.eSigStatus  [AlgoSignalState_t as in Rte_Type.h]
                    pPubEmObj->eSigStatus                 [AlgoSignalState_t as in Rte_Type.h]
  @param[in]       pProvidePorts : Outputs of FCT_SEN
  @param[in]       pServiceFuncts : External service functions interface
  @param[out]      pErrorBuffer : Pointer to the buffered error

  @glob_in         FCTSenFrame : FCT frame data
                      eFCTState : FCT current operation mode        [FCTSenState_t as in fct_seh.h]
                   FCTObjectList : FCT specific list of Objects     [FCTPrivObjectList_t as defined in fct_sen.h]
  @glob_out        FCTSenFrame : FCT frame data
                      bFirstCycleDone [TRUE, FALSE]

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS : FCT switch to use third parameter in Exec methods to call the Function. 
                      Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_USE_SIG_HEADER : FCT switch to enable the generic Signal Header in Interfaces
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.06.2013
  @changed         22.10.2015

  @author          Jochen Spruck, Gergely Ungvary
*************************************************************************************************************************/
static void FCTSenPreProcessing(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts
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

  FCTSenSetInterfaceVersionProvidePorts(pProvidePorts);

  /* If operation mode indicates run, but we our object list is invalid, then
  force to init mode. Note: FCT_SEN_RUN Implies that InputPort pointers are valid. */
#if (FCT_CFG_USE_SIG_HEADER)
  if ((FCTSenFrame.eFCTState == COMP_STATE_RUNNING) && (pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus != AL_SIG_STATE_OK))
#else
  if ((FCTSenFrame.eFCTState == COMP_STATE_RUNNING) && (pRequirePorts->pPubEmObj->eSigStatus != AL_SIG_STATE_OK))
#endif
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSenSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    FCTSenSignalErrorShutdown(TRUE); /*Shutdown without error*/
  }

#if ( (FCT_CFG_USE_SERVICE_POINTER_FUNCTS) && (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING) )
  /*call update check*/
  if (FCTSenFrame.eFCTState != COMP_STATE_TEMPORARY_ERROR )
  {
    if ( FCTSenCheckInputUpdate(pRequirePorts, &FCTSenInputCounters, FCT_SEN_TARGET_CYCLE_TIME) != 0u)               /*error condition*/
    {
      FCTSenSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
    }
  }
#endif
}


/*************************************************************************************************************************
  Functionname:    FCTSenSetupPorts                                                                                 */ /*!

  @brief           Setup the Ports to local aliases

  @description     Setup the Ports to local aliases for FCT_SEN inputs and outputs

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
  @glob_out        FCT_pCDHypothesesSen : Collision hypothesis FCT_SEN data
  @glob_out        FCTSEN_pCDCustomOutput : Collision detection custom output
  @glob_out        FCTSEN_pSenCompState : Algo Component State
  @glob_out        FCTSEN_pBusDebugData : Bus debug data
  @glob_out        FCTSEN_pCamSLAInputData :  SLA input data from camera
  @glob_out        FCTSEN_pTSAInputData :  TSA input data from camera
  @glob_out        FCTSEN_pSLAData : SLA speed limit data from FCT_SEN

  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_CUSTOM_OBJECT_LIST : Configuration switch enabling EM custom object list
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   FCT_CFG_USE_EM_MOVING_OBJECT_TRACES : Switch for old traces
  @c_switch_part   FCT_CFG_NEW_TRACES_INTERFACE : Enable Interface for new Traces
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT
  @c_switch_part   FCT_CFG_RSP_OUTPUT_PD : FCT has access to RSP output PD signal
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   FCT_CFG_ME_INPUT_FOR_DEBUG : FCT configuration for debugging input of mobil-eye data (only meas output)
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
                                                 port structures, even if the current configuration does not use them.
                                                 This enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT component.
                                             This should be enabled, if the SW environment provides this information.
  @c_switch_part   FCT_CFG_CPAR_PARAMS : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT : Configuration switch enabling DIMOutputCustom to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_part   FCT_CFG_SEN_CAM_LANE_INTERFACE : Configuration switch to enable support for camera lane fusion features when changing lanes
  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG : Configuration switch for enabling BusDebugMessages
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   FCT_CFG_LOPC_COMPONENT : FCT switch for LOPC Component for ACC
  @c_switch_part   SLAData_INTFVER : Interface version number for port SLAData
  @c_switch_part   CamSLAInputData_INTFVER : Interface version number for port CamSLAInputData

  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.09.2010
  @changed         22.09.2017

  @author          Clemens Schnurr
*************************************************************************************************************************/
static void FCTSenSetupPorts( const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts )
{
  /* Initialize global pointers used by macros */
  /* Request Ports */
  if (pRequirePorts != NULL)
  {
    FCTSEN_pSenCtrlData     = pRequirePorts->pSenCtrlData;
#if (FCT_CFG_EM_FCT_CYCLEMODE)
    FCTSEN_pEmFctCycleMode  = pRequirePorts->pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
    FCTSEN_pEmGenObjList    = pRequirePorts->pEmGenObjList;
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    FCTSEN_pEmCustObjList   = pRequirePorts->pEmCustObjList;
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    FCTSEN_pEmARSObjList    = pRequirePorts->pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    FCTSEN_pEmCamObjList    = pRequirePorts->pEmCamObjList;
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
    FCTSEN_pMovObjTraces        = pRequirePorts->pMovObjTraces;
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
    GET_OBJ_TRACE_LIST_DATA_PTR = pRequirePorts->pObjectTraces;
#endif
#endif
    FCTSEN_pEgoDynObjSync = pRequirePorts->pEgoDynObjSync;
    FCTSEN_pEgoDynRaw = pRequirePorts->pEgoDynRaw;
    FCTSEN_pGlobEgoStatic       = pRequirePorts->pEgoStaticData;
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    FCTSEN_pPerfDegrData = pRequirePorts->pPerfDegrData;
#endif
#if (FCT_CFG_ROAD_INPUT)
    FCTSEN_pRoadData = pRequirePorts->pRoadData;
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
    FCTSEN_pRSPContextData = pRequirePorts->pRSPContextData;
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
    FCTSEN_pRSPOutputPD = pRequirePorts->pRSPOutputPD;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    /* customer specific input */
    FCTSEN_pCustomInput         = pRequirePorts->pFCTCustomInput;
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) && (!FCT_USE_EM_CUSTOM_OBJECT_LIST))
    FCTSEN_pCameraObjData       = pRequirePorts->pCameraObjData;
#else
    FCTSEN_pCameraObjData       = pRequirePorts->pEmCustObjList;
#endif
#endif

#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
    FCTSEN_pME_in               = pRequirePorts->pME_in;
#endif

#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) 
    FCTSEN_pAlignmentMonInput   = pRequirePorts->pAlignmentMonInput;
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
    FCTSEN_pBswAlgoParameters   = pRequirePorts->pBswAlgoParameters;
#endif

#if (FCT_CFG_CPAR_PARAMS)
    FCTSEN_pCPAR_FCT_Parameters = pRequirePorts->pCPAR_FCT_Parameters;
#endif

#if (FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT)
    FCTSEN_pDIMOutputCustom     = pRequirePorts->pDIMOutputCustom;
#endif

#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)
    FCTSEN_pNaviData            = pRequirePorts->pNaviData;
#endif

#if (FCT_CFG_SEN_CAM_LANE_INTERFACE)
    FCTSEN_pCamLaneData         = pRequirePorts->pCamLaneData;
#endif

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    FCTSEN_pEmFusionObjList   = pRequirePorts->pEmFusionObjList;
#endif

#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    FCTSEN_pTSAInputData     = pRequirePorts->pTSAInputData;
#endif

#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    FCTSEN_pCamSLAInputData     = pRequirePorts->pCamSLAInputData;
#endif

#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
    FCTSEN_pLongCtrlResp = pRequirePorts->pLongCtrlResp;
    pt_FCT_IN_TCCP = pRequirePorts->pt_FCT_IN_TCCP;
    pt_FCT_IN_TFSP = pRequirePorts->pt_FCT_IN_TFSP;
#endif
  }

  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    FCTSEN_pPubFctObjList       = pProvidePorts->pPubFctObj;
#endif
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    FCTSEN_pSysPerfMonStates    = pProvidePorts->pSysPerfMonStates;
#endif

#if (FCT_CFG_COLLISION_DETECTION)
    FCT_pCDHypothesesSen        = pProvidePorts->pFCTCDHypotheses;
#endif

#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
    FCTSEN_pCDCustomOutput      = pProvidePorts->pCollDetOutput;
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSEN_pSenCompState        = pProvidePorts->pSenCompState;
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    FCTSEN_pBusDebugData        = pProvidePorts->pFCTSenBusDebugData;
#endif

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    /* Provide OOI Objects from SEN to VEH */
    FCTSEN_pAccOOIData          = pProvidePorts->pFCTAccOOIData;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    FCTSEN_pCustomOutput        = pProvidePorts->pFCTCustomOutput;
#endif 

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
    /* Provide OOI-0 Object from SLATE to TJA */
    FCTSEN_pOOITJAData            = pProvidePorts->pFCTTJAOOIData;
#endif

#if (FCT_CFG_SLA_FEATURE)
    FCTSEN_pSLAData             = pProvidePorts->pSLAData;
#endif

#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
    pt_FCT_OUT_TCSP = pProvidePorts->pt_FCT_OUT_TCSP;
    pt_FCT_OUT_TFCP = pProvidePorts->pt_FCT_OUT_TFCP;
#endif
  }
}


/*************************************************************************************************************************
  Functionname:    FCTSenSetInterfaceVersionProvidePorts                                                            */ /*!

  @brief           Set interface versions of the provide ports

  @description     Set interface versions of the provide ports based on the interface version given in the RTE

  @return          -

  @param[out]      pProvidePorts : provide ports of FCT, i.e. output ports
                      pProvidePorts->pPubFctObj->uiVersionNumber        [full range of datatype uint32]
                      pProvidePorts->pSysPerfMonStates->uiVersionNumber [full range of datatype uint32]
                      pProvidePorts->pAccOutput->uiVersionNumber        [full range of datatype uint32]
                      pProvidePorts->pAccDisplayObj->uiVersionNumber    [full range of datatype uint32]
                      pProvidePorts->pFCTCustomOutput->uiVersionNumber  [full range of datatype uint32]
                      pProvidePorts->pCollDetOutput->uiVersionNumber    [full range of datatype uint32]
                      pProvidePorts->pFCTCDHypotheses->uiVersionNumber  [full range of datatype uint32]
                      pProvidePorts->pSenCompState->uiVersionNumber     [full range of datatype uint32]
                      pProvidePorts->pFCTAccOOIData->uiVersionNumber    [full range of datatype uint32]
                      pProvidePorts->pSLAData->uiVersionNumber    [full range of datatype uint32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
                    port structures, even if the current configuration does not use them. This 
                    enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP processing
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface
  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN
  @c_switch_part   FCT_CFG_SENSOR_CONTROL_INTF : FCT sensor control interface
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   FCT_CFG_LOPC_COMPONENT : FCT switch for LOPC Component for ACC
  @c_switch_part   SLAData_INTFVER : Interface version number for port SLAData
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         22.09.2017

  @author          Clemens Schnurr
*************************************************************************************************************************/
static void FCTSenSetInterfaceVersionProvidePorts( const proFCTSenPrtList_t * pProvidePorts )
{
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  pProvidePorts->pSysPerfMonStates->uiVersionNumber = SYS_PERF_MON_OUT_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pSysPerfMonStates->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_LOHP_COMPONENT)
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pAccOutput->uiVersionNumber = DUMMY_INTERFACE_VERSION;
  pProvidePorts->pAccDisplayObj->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
  pProvidePorts->pCollDetOutput->uiVersionNumber = FCT_CD_OUTPUT_CUSTOM_INTFVER;
#elif(FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pCollDetOutput->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  pProvidePorts->pFCTCDHypotheses->uiVersionNumber = FCT_HYPOTHESIS_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pFCTCDHypotheses->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  pProvidePorts->pErrorOut->uiVersionNumber = FCT_SEN_ERROR_OUT_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pErrorOut->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_SENSOR_CONTROL_INTF)
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Add Inteface Version")
#endif
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Add Inteface Version")
#endif
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
#if COMP_STATE_INTFVER > 2u
  pProvidePorts->pSenCompState->uiVersionNumber = COMP_STATE_INTFVER;
#else
  pProvidePorts->pSenCompState->uVersionNumber = COMP_STATE_INTFVER;
#endif
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  pProvidePorts->pFCTAccOOIData->uiVersionNumber = FCT_SEN_ACC_OOI_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pFCTAccOOIData->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
  pProvidePorts->pFCTTJAOOIData->uiVersionNumber = FCT_TJA_TARGET_OBJ_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pFCTTJAOOIData->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_SLA_FEATURE)
  pProvidePorts->pSLAData->uiVersionNumber = SLAData_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pSLAData->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
  pProvidePorts->pt_FCT_OUT_TCSP->uiVersionNumber = LOHP_TCSP_INTFVER;
  pProvidePorts->pt_FCT_OUT_TFCP->uiVersionNumber = LOPC_TFCP_INTFVER;
#elif (FCT_CFG_INCLUDE_UNUSED_INTF)
  pProvidePorts->pt_FCT_OUT_TCSP->uiVersionNumber = DUMMY_INTERFACE_VERSION;
  pProvidePorts->pt_FCT_OUT_TFCP->uiVersionNumber = DUMMY_INTERFACE_VERSION;
#endif
}

#if (FCT_CFG_SLATE_COMPONENT)

/*************************************************************************************************************************
  Functionname:    FctSen_v_SetSLATEProPort                                                                           */ /*!

  @brief           Set ACC provide ports based on FCT_SEN provide ports

  @description     Set ACC provide ports based on FCT_SEN provide ports. 
                   ACC provide ports combine pointer to the FCT_SEN provide port buffer.

  @return          -

  @param[in]       p_ProvidePorts : Pointer to FCT_SEN provide ports
  @param[in,out]   p_SLATEProvidePorts : Pointer to ACC provide ports

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT

  @pre             -
  @post            -

  @created         20.10.2016
  @changed         04.12.2017

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FctSen_v_SetSLATEProPort(const proFCTSenPrtList_t * p_ProvidePorts, 
#if (FCT_CFG_LOHP_COMPONENT)
  SLATE_HC_Data_t * pt_SLATE_HC_Data, 
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SLATE_SPM_Data_t * pt_SLATE_SPM_Data,
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  SLATE_CD_Data_t * pt_SLATE_CD_Data,
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  SLATEErrorOutProPort_t * p_SLATEErrorOut,
#endif 
  provSLATEPortList_t * p_SLATEProvidePorts)
{
  if (p_ProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    //AlgoCompState_t             * pSenCompState;  /*!< AlgoCompState interface to scheduler */
    p_SLATEProvidePorts->pSenCompState = p_ProvidePorts->pSenCompState;
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
    p_SLATEProvidePorts->pt_SLATEErrorOut = p_SLATEErrorOut;
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_SHORT_RANGE_FUNCTIONS))
    p_SLATEProvidePorts->pFCTCustomOutput = p_ProvidePorts->pFCTCustomOutput;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    //AssessedObjList_t           * pPubFctObj;         /*!< The public FCT object data */
    p_SLATEProvidePorts->pPubFctObj = p_ProvidePorts->pPubFctObj;
#endif
#endif

#if (FCT_CFG_USE_BUS_DEBUG)
    //BusDebugData_t              * pFCTSenBusDebugData; /*!< Debug data */
    p_SLATEProvidePorts->pFCTSenBusDebugData = p_ProvidePorts->pFCTSenBusDebugData;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    //FCTSenAccOOI_t             * pFCTAccOOIData; /* FCT OOI Objects */
    p_SLATEProvidePorts->pFCTAccOOIData = p_ProvidePorts->pFCTAccOOIData;
#endif
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
    //  TJATargetObj_t             * pFCTTJAOOIData; /* FCT OOI Objects */
    p_SLATEProvidePorts->pFCTTJAOOIData = p_ProvidePorts->pFCTTJAOOIData;
#endif
#if (FCT_CFG_SLA_FEATURE)
    p_SLATEProvidePorts->pSLAData = p_ProvidePorts->pSLAData;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
    p_SLATEProvidePorts->pSLATE_HC_Data = pt_SLATE_HC_Data;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    p_SLATEProvidePorts->pSLATE_SPM_Data = pt_SLATE_SPM_Data;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
    p_SLATEProvidePorts->pSLATE_CD_Data = pt_SLATE_CD_Data;
#endif
  }
  else
  {
    p_SLATEProvidePorts = NULL;// PRQA S 3199, 2983
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
  }

}

/*************************************************************************************************************************
  Functionname:    FctSen_v_SetSLATEReqPort                                                                           */ /*!

  @brief           Set SLATE require ports based on FCT_SEN require ports

  @description     Set SLATE require ports based on FCT_SEN require ports. 

  @return          -

  @param[in]       p_RequirePorts : Pointer to FCT_SEN provide ports
  @param[in,out]   p_SLATERequirePorts : Pointer to ACC provide ports

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_part   FCT_CFG_SHORT_RANGE_FUNCTIONS : FCT switch for activating side rear functionality
  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode (ARS3xx specific)
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Switch enabling simple navi input data to SLATE
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.12.2017
  @changed         -

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
// Addtiona meeting needed to setup to clarfify how the ports set, required, checking shall be done , including EBA 09.03.2017 Shang
static void FctSen_v_SetSLATEReqPort(const reqFCTSenPrtList_t * p_RequirePorts, reqSLATEPortList_t * p_SLATERequirePorts)
{
  if (p_RequirePorts != NULL)
  {
    p_SLATERequirePorts->pSenCtrlData = p_RequirePorts->pSenCtrlData;
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
    //const VehDyn_t                * pEgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
    p_SLATERequirePorts ->pEgoDynObjSync = p_RequirePorts->pEgoDynObjSync; // Confirm with Harsha whether to remove this or not 09.03.2017 Shang
#endif
    p_SLATERequirePorts ->pEgoDynRaw = p_RequirePorts->pEgoDynRaw; /*!< The dynamic vehicle ego data raw */
    p_SLATERequirePorts ->pEgoStaticData = p_RequirePorts->pEgoStaticData; /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
    p_SLATERequirePorts ->pEmFctCycleMode = p_RequirePorts->pEmFctCycleMode; /*!< The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
    p_SLATERequirePorts->pEmGenObjList = p_RequirePorts->pEmGenObjList; /*!< EM generic object list */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    p_SLATERequirePorts->pEmCustObjList = p_RequirePorts->pEmCustObjList; /*!< EM customer specific object list */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    p_SLATERequirePorts->pEmARSObjList = p_RequirePorts->pEmARSObjList; /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    p_SLATERequirePorts->pEmCamObjList = p_RequirePorts->pEmCamObjList; /*!< EM Camera-technology-specific object list */
#endif
#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
    p_SLATERequirePorts->pMovObjTraces = p_RequirePorts->pMovObjTraces; /*!< Moving object traces */
#endif
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    p_SLATERequirePorts->pPerfDegrData = p_RequirePorts->pPerfDegrData; /*!< Performance degradation input data */
#endif
#if (FCT_CFG_ROAD_INPUT)
    p_SLATERequirePorts->pRoadData = p_RequirePorts->pRoadData; /*!< Road/lane information */
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
    p_SLATERequirePorts->pRSPContextData = p_RequirePorts->pRSPContextData; /*!< RSP Kontext data */
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pFCTCustomInput = p_RequirePorts->pFCTCustomInput; /*!< Custom input */
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) && ((!FCT_USE_EM_CUSTOM_OBJECT_LIST))) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pCameraObjData = p_RequirePorts->pCameraObjData; /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pAlignmentMonInput = p_RequirePorts->pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pME_in = p_RequirePorts->pME_in; /*!< Input from mobil-eye directly for debugging */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pBswAlgoParameters = p_RequirePorts->pBswAlgoParameters; /*!< Input algo parameters from BSW */
#endif
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pNaviData = p_RequirePorts->pNaviData; /*!< Simple navi input data */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    p_SLATERequirePorts->pEmFusionObjList = p_RequirePorts->pEmFusionObjList;
#endif
#if ((SLATE_CFG_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pCamLaneData = p_RequirePorts->pCamLaneData; /*!< Camera lane input data */
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pTSAInputData = p_RequirePorts->pTSAInputData;
#elif ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_SLATERequirePorts->pCamSLAInputData = p_RequirePorts->pCamSLAInputData;
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
	p_SLATERequirePorts->pLongCtrlResp = p_RequirePorts->pLongCtrlResp; /* Dynamic controller response, in SLATE currently used to get drivemode input */
#endif /*((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))*/
  }
  else
  {
    p_SLATERequirePorts = NULL;// PRQA S 3199, 2983
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
  }
}
#endif


#if(FCT_CFG_SIGNAL_PERF_MONITORING)
/*************************************************************************************************************************
  Functionname:    FctSen_v_SetSPMReqPort                                                                           */ /*!

  @brief           Check for require ports validity and set SPM require ports in case that FCT require ports are available.

  @description     Check for require ports validity and set SPM require ports in case that FCT require ports are available.
                   @startuml "Call sequence for FctSen_v_SetSPMProPort"
                     fct_sen_main -> fct_sen_main : FCTSen_Exec() calls\nFctSen_v_SetSPMProPort(proFCTSenPrtList_t, SPM_HC_Data_t, SPMProPort_t, SPMErrorOutProPort_t)
                     activate fct_sen_main
                       fct_sen_main --> fct_sen_main : 
                     deactivate fct_sen_main
                    @enduml

  @return          void

  @param[in]       p_RequirePorts : the inputs passed to the FCT_SEN main function               [reqFCTSenPrtList_t as defined in fct_sen_ext.h]
  @param[in]       pPubFctObj : Assessed Object List as defined in Rte_type.h
  @param[in]       pSLATE_SPM_Data : Specific output of FIP Object attributes
  @param[in]       p_SPMRequirePorts : Inputs required by SPM component for sensor cycle processing

  @glob_in         -
  @glob_out        -

  @c_switch_part   VDY_VEH_DYN_INTFVER : Vehicle dynamics interface version
  @c_switch_part   SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE : Use align state as input for SPM
  @c_switch_part   FCT_CFG_PERF_DEGR_EXT_INPUT : Configuration switch enabling PerfDegrExtInput_t type input
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
port structures
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_CFG_ASSESSED_OBJ_OUT_INTF : FCT assessed object list
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : EM-Generic_Object list
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : ARS-technology specific object list
  @c_switch_part   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control)
  @c_switch_part   SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF : Use probability and confidence as input for SPM
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input


  
  @c_switch_full   -FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             -
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.03.2018

  @author          Istvan Benianim Pallo | istvan.pallo@continental-corporation.com | +40-374-33-4723
*************************************************************************************************************************/
static void FctSen_v_SetSPMReqPort(const reqFCTSenPrtList_t * p_RequirePorts, const AssessedObjList_t * pPubFctObj, 
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  SLATE_SPM_Data_t * pSLATE_SPM_Data,
#endif
  reqFCTSenSPMPrtList_t * p_SPMRequirePorts)
{
  if(p_RequirePorts != NULL)
  {
      p_SPMRequirePorts->pEgoDynObjSync = p_RequirePorts->pEgoDynObjSync;
      p_SPMRequirePorts->pEgoDynRaw = p_RequirePorts->pEgoDynRaw;
      p_SPMRequirePorts->pt_BSWAlgoBlockage = &(p_RequirePorts->pBswAlgoParameters->Fct.Blockage);
      p_SPMRequirePorts->pSenCtrlData = p_RequirePorts->pSenCtrlData;
    #if (FCT_CFG_EM_FCT_CYCLEMODE)
      p_SPMRequirePorts->pEmFctCycleMode = p_RequirePorts->pEmFctCycleMode;
    #endif
      p_SPMRequirePorts->pPerfDegrData = p_RequirePorts->pPerfDegrData;
    #if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      /*!< Performance degradation external input (short range sensor info) */
      p_SPMRequirePorts->pPerfDegrExtInput = p_RequirePorts->pPerfDegrExtInput;
    #endif
    #if (FCT_CFG_OBJECT_LIST_PROC)
    #if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
      //AssessedObjList_t           * pPubFctObj;         /*!< The public FCT object data */
      p_SPMRequirePorts->pPubFctObj = pPubFctObj;
    #endif
    #endif
    #if (FCT_CFG_OBJECT_LIST_PROC)
    #if (FCT_USE_EM_GENERIC_OBJECT_LIST)
      //const EM_t_GenObjectList      * pEmGenObjList;    /*!< EM generic object list */
      p_SPMRequirePorts->pEmGenObjList = p_RequirePorts->pEmGenObjList;
    #if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      //const EM_t_ARSObjectList      * pEmARSObjList;    /*!< EM ARS-technology-specific object list */
      p_SPMRequirePorts->pEmARSObjList = p_RequirePorts->pEmARSObjList;
    #endif
    #else
      //const ObjectList_t            * pPubEmObj;        /*!< The public EM object data */
      p_SPMRequirePorts->pPubEmObj = p_RequirePorts->pPubEmObj;
    #endif
    #endif
    #if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
      p_SPMRequirePorts->pSLATE_SPM_Data = pSLATE_SPM_Data;
    #endif
    #if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      p_SPMRequirePorts->pt_ALNMonitoring = p_RequirePorts->pAlignmentMonInput;
    #endif
    #if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      p_SPMRequirePorts->pFctVehLongOut     = p_RequirePorts->pFctVehLongOut;
    #endif
  }
  else
  {
    p_SPMRequirePorts = NULL;// PRQA S 3199, 2983
    /* date: 2018-04-06, reviewer: Ravi Kiran Gurrala, reason: Redundant, but may be used in future*/
  }
}

/*************************************************************************************************************************
  Functionname:    FctSen_v_SetSPMProPort                                                                           */ /*!

  @brief           Check for provide ports validity and set SPM require provide ports.

  @description     Set the SPM specific request ports from p_SPMRequirePorts using data from FCT_SEN require ports,
                   assessed objects list and SLATE component data.
                   @startuml "Call sequence for FctSen_v_SetSPMReqPort"
                     fct_sen_main -> fct_sen_main : FCTSen_Exec() calls\nFctSen_v_SetSPMReqPort(reqFCTSenPrtList_t, AssessedObjList_t, SLATE_SPM_Data_t, reqFCTSenSPMPrtList_t)
                     activate fct_sen_main
                       fct_sen_main --> fct_sen_main : 
                     deactivate fct_sen_main
                   @enduml

  @return          void

  @param[in] p_RequirePorts : FCT_SEN require ports as defined in fct_sen_ext.h
  @param[in] pPubFctObj : List of assessed objects as defined in rte_types.h
  @param[in] pSLATE_SPM_Data : SLATE component output data as defined in slate_ext.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_LOHP_COMPONENT : FCT switch for LOHP Component for ACC
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : Brief FCT error output from FCT_SEN
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : Configuration switch enabling PerfDegrExtInput_t type input
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
port structures
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface

  @c_switch_full   -FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             -
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.03.2018

  @author          Istvan Benianim Pallo | istvan.pallo@continental-corporation.com | +40-374-33-4723
*************************************************************************************************************************/
static void FctSen_v_SetSPMProPort(const proFCTSenPrtList_t * p_ProvidePorts
#if (FCT_CFG_LOHP_COMPONENT)
  , SPM_HC_Data_t * p_SPM_HC_Data
#endif
  , SPMProPort_t * p_SPMProvidePorts
#if(FCT_CFG_ERROR_OUTPUT_SEN)
  , SPMErrorOutProPort_t * const t_SPMErrorOut
#endif
  )
{
  if(p_ProvidePorts != NULL)
  {
    p_SPMProvidePorts->pErrorOut = t_SPMErrorOut;

    #if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
      #if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
        //SysPerfMonStates_t * pSysPerfMonStates;  /*!< System performance monitor output data */
        p_SPMProvidePorts->pSysPerfMonStates = p_ProvidePorts->pSysPerfMonStates;
      #endif
    #endif

    #if (FCT_CFG_LOHP_COMPONENT)
      p_SPMProvidePorts->pSPM_HC_Data = p_SPM_HC_Data;
    #endif

    #if(FCT_CFG_USE_ALGOCOMPSTATE)
      p_SPMProvidePorts->pSenCompState = pSenCompState->pSenCompState;
    #endif
  }
  else
  {
    p_SPMProvidePorts = NULL;// PRQA S 3199, 2983
    /* date: 2018-04-06, reviewer: Ravi Kiran Gurrala, reason: Redundant, but may be used in future*/
  }
}

#endif

/*************************************************************************************************************************
  Functionname:    FCTSen_Exec                                                                                      */ /*!

  @brief           FCT component main execution function for sensor data cycle

  @description     FCT component main execution function for sensor data cycle. 
                    -Call function to set frame data
                    -Call function to set operation modes of all sub-components
                    -Call function to set sync ref structures
                    -Call function to setup the ports to local aliases for FCT_SEN inputs and outputs
                    -Call function to set all provide port headers
                    -Call function for FCT_SEN preprocessing
                    -Sub-components are called: CP, SI, SPM, CD, External object determination, LONG, UWD
                    -Call functions for error handling
                    -Call function to freeze data
                    -Call functions for runtime measurements

                  <a style="font-weight:bold" href="integrity://ims-adas:7001/si/viewproject?project=%23/ADAS/SW%23Components/FCT_Function%23forceJump%3D%23n%3D%2305_Testing/05_Test_Environment/Dynamic_Tests/FCT/Courage/test_scripts/frame_sen&selection=%22test_fct_sen_main.c%22">Test_Script_path</a>

                    @startuml
                    Start
                      -FCTSen_Exec
                       Note right
                        fct_sen_main.c
                       End note
                      -COU_TEST23_FCT_Sen_main_25
                       Note right
                        test_fct_sen_main.c
                       End note
                    End
                    @enduml

  @return          -

  @param[in]       pRequirePorts : The input data used by FCT component
  @param[in]       pProvidePorts : The output data provided by FCT component
                      Note: this is also used to store state information of FCT,
                      thus the same buffer shall be used or care should be taken
                      to copy data from previous cycle!
  @param[in]       pServiceFuncts : Service functions provided by the frame SW

  @glob_in         FCTSenFrame : FCT frame data
                      eFCTOpMode  [FCT_OP_MODE_t as in fct_sen.h]
                      eFCTState   [FCTSenState_t as in fct_sen.h]
  @glob_out        -

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS : FCT switch to use third parameter in Exec methods to call the Function. 
                    Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling FCT_LONG processing
  @c_switch_part   FCT_CFG_RTA_PROFILING : Configuration switch for enabling profiling on ECU
  @c_switch_part   FCT_CFG_USE_FREEZE_CYCLE_START : FCT switch to enable setting of Measfreeze Cycle Start Service
  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component
  @c_switch_part   FCT_CFG_SLATE_COMPONENT : FCT support for ACC object selection
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   FCT_SEN_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT uses direct access to vehicle signals
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN
  @c_switch_part   FCT_MEASUREMENT : Activate Measurement Output Code
  @c_switch_part   FCT_SEN_CFG_CUSTOM_POST_PROC : Configuration switch enabling custom post-processing function call after all other
                        FCT_SEN processing has taken place
  @c_switch_full   -

  @pre             FCT component initialized!
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    -


  @created         -
  @changed         04.11.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void FCTSen_Exec(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts, const AS_t_ServiceFuncts *pServiceFuncts)
#else
void FCTSen_Exec(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts)
#endif
{

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif

  /*! ACC/EBA/SPM local provide ports */
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  provSLATEPortList_t t_ACCProvidePorts;
#endif
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ERROR_OUTPUT_SEN))
  SLATEErrorOutProPort_t t_SLATEErrorOut;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SPMProPort_t t_SPMProvidePorts;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING) && (FCT_CFG_ERROR_OUTPUT_SEN)
  SPMErrorOutProPort_t t_SPMErrorOut;
#endif

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))
  LOHPProPort_t t_LOHPProvidePorts;
#endif
#if (FCT_CFG_ACDC_COMPONENT)
  provACDCPrtList_t t_ACDCProvidePorts;
#endif

  /*! ACC/EBA/SPM local require ports */ // local or global???
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  reqSLATEPortList_t t_ACCRequirePorts;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  reqFCTSenSPMPrtList_t t_SPMRequirePorts;
#endif
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))
  reqLOHPPrtList_t t_LOHPRequirePorts;
#endif
#if (FCT_CFG_ACDC_COMPONENT)
  reqACDCPrtList_t t_ACDCRequirePorts;
#endif

  /* Allocate memory for the provideports */
#if (FCT_CFG_ACDC_COMPONENT)
  ACDCErrorOutProPort_t t_ACDCErrorOut;
#endif

  /* Port check booleans, TRUE if there is an error in the respective port */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  boolean b_ServiceFuncError;
#endif
  boolean b_RequirePortError, b_ProvidePortError;
#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
   boolean b_RequirePortSigStatusError;
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  if (pServiceFuncts != NULL)
  {
    pFCTSenServiceFuncts = pServiceFuncts;
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  FCTSEN_RuntimeMeasInit();
#endif

  /* Sends RTA-Start Event for whole procedure runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_PROCESS, 0u);//PRQA S 4424 4
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */
  /* data preparation runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_PREPRE_PROCESS, 0u);


  /*---------------------------------------------------------------------------*/
  /* Start data preparation                                                    */
  /*---------------------------------------------------------------------------*/

  /* set the FrameData for Sensor */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  FCTSetSenFrameData(pRequirePorts, &AlgoErrorBuffer);
#else
  FCTSetSenFrameData(pRequirePorts);
#endif
  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  FCTSenProcessStates(FCTSenFrame.eFCTOpMode);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  b_ServiceFuncError = FCTSenCheckServiceFunc(pServiceFuncts);
#endif

  b_RequirePortError = FCTSenCheckReqPorts(pRequirePorts);

  b_ProvidePortError = FCTSenCheckProPorts(pProvidePorts);

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
  if (b_RequirePortError == FALSE)
  {
    b_RequirePortSigStatusError = FCTSenCheckReqPortsSigStatus(pRequirePorts);
  }
  else
  {
    b_RequirePortSigStatusError = FALSE;
  }
#endif

  if (
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
      (b_ServiceFuncError) ||
#endif
      (b_RequirePortError)// PRQA S 4115 2
    ||(b_ProvidePortError) //PRQA S 0380,4558
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: b_ProvidePortError is unsigned char, which does not have any side effects */
     )
  {
#if (FCT_CFG_USE_DEM)
    FCTSenSetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSenSetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    FCTSenSignalErrorShutdown(FALSE);
  }
#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
  else if (b_RequirePortSigStatusError)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSenSetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    FCTSenSignalErrorShutdown(FALSE);
  }
#endif
  else
  {
    /* receive and provide ports are fine */
#if (FCT_CFG_USE_DEM)
    FCTSenSetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
  }

  /* setup sync ref no matter what (sync in running and non running mode)*/
  FCTSenSetupSyncRef(pRequirePorts);

  FCTSenSetupPorts(pRequirePorts, pProvidePorts);
#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
  /* send MTS Freeze Cycle Start */
  if ((pServiceFuncts->pfMeasStartFuncCycle) != NULL) /*PRQA S 0505*//* pServiceFuncts can't be NULL here: checked in FCTSenCheckPorts */
  {
    (pServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
  }
#endif

  if (b_ProvidePortError != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
  {
    /* set all the signal headers of all provide ports to invalid*/
    FCTSenSetProvideHeaderStates(pProvidePorts, AL_SIG_STATE_INVALID);
    if (b_RequirePortError != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
    {
      FCTSenSetProvideHeader(pRequirePorts, pProvidePorts);
    }
  }

  /* Send RTA-End Event for data preparation runtime in non-error state*/
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_PREPRE_PROCESS, 0u);//PRQA S 4424 4
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */
  /* Send RTA-Start Event for data preprocessing runtime in non-error state*/
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_PRE_PROCESS, 0u);

  /*---------------------------------------------------------------------------*/
  /* Start Pre-Processing (FCT)                                                */
  /*---------------------------------------------------------------------------*/
  /* FCT Main Time */
  if ((b_RequirePortError != TRUE) && (b_ProvidePortError != TRUE) //PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    && (b_ServiceFuncError != TRUE)
#endif
    )
  {
    FCTSenPreProcessing(pRequirePorts, pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
      , pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      , &AlgoErrorBuffer
#endif
      );
  }

  /* Send RTA-End Event for data preprocessing runtime in non-error state*/
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_PRE_PROCESS, 0u);//PRQA S 4424
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */
  /*! Run Adaptive Cruise Control (ACC) - object evaluation in Sensor Task */
#if (FCT_CFG_SLATE_COMPONENT)
  /*! Set Adaptive Cruise Control (ACC) require ports */
  FctSen_v_SetSLATEReqPort(pRequirePorts, &t_ACCRequirePorts);
  /*! Set Adaptive Cruise Control (ACC) provide ports as pointer to FCT_SEN provide port signals */
  FctSen_v_SetSLATEProPort(pProvidePorts, 
#if (FCT_CFG_LOHP_COMPONENT)
    &t_SLATE_HC_Data,
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    &t_SLATE_SPM_Data,
#endif
#if (FCT_CFG_COLLISION_DETECTION)
    &t_SLATE_CD_Data,
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
    &t_SLATEErrorOut,
#endif 
    &t_ACCProvidePorts);
  /*! Run Adaptive Cruise Control (ACC) execution function */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  SLATE_v_Exec(&t_ACCRequirePorts, &t_ACCProvidePorts, pServiceFuncts, &FCTSenFrame);
#else
  // SLATE_v_Exec(&t_ACCRequirePorts, &t_ACCProvidePorts, &FCTSenFrame);
#endif
#endif  /* END IF (FCT_CFG_SLATE_COMPONENT) */
  /* Run System Performance Monitoring (SPM) */

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    /*! Set System Performance Monitoring (SPM) require ports */
    FctSen_v_SetSPMReqPort(pRequirePorts, pProvidePorts->pPubFctObj, 
#if (FCT_CFG_SLATE_COMPONENT)
      &t_SLATE_SPM_Data,
#endif
      &t_SPMRequirePorts);

    /*! Set System Performance Monitoring (SPM) provide ports as pointer to FCT_SEN provide port signals */
    FctSen_v_SetSPMProPort(pProvidePorts
#if (FCT_CFG_LOHP_COMPONENT)
      , &t_SPM_HC_Data
#endif
      , &t_SPMProvidePorts
#if(FCT_CFG_ERROR_OUTPUT_SEN)
      , &t_SPMErrorOut
#endif
      );
  /*! Run System Performance Monitoring (SPM) execution function */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  FCTSen_SPM_Exec(&t_SPMRequirePorts, &t_SPMProvidePorts, /*&t_Blockage, &t_SelfTest,*/ FCTSenFrame.eFCTOpMode, pServiceFuncts);
#else
  FCTSen_SPM_Exec(&t_SPMRequirePorts, &t_SPMProvidePorts, /*&t_Blockage, &t_SelfTest,*/ FCTSenFrame.eFCTOpMode);//FCTSenFrame.eFCTState);// PRQA S 3349
  /* date: 2018-03-26, reviewer: Ravi kiran Gurrala, reason: Not a safety critical */  
#endif
#endif  /* END IF (FCT_CFG_SIGNAL_PERF_MONITORING) */

#if (FCT_CFG_ACDC_COMPONENT)
  /*! Set Emergency Brake Assist (EBA) ACDC require ports */
  FctSen_v_SetACDCReqPort(pRequirePorts 
#if ((FCT_CFG_COLLISION_DETECTION) && (FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
    ,&t_SLATE_CD_Data
#endif
    ,&t_ACDCRequirePorts);

  /*! Set Emergency Brake Assist (EBA) ACDC provide ports as pointer to FCT_SEN provide port signals */
  FctSen_v_SetACDCProPort(pProvidePorts
    ,&t_ACDCErrorOut
    ,&t_ACDCProvidePorts);

  /*! Run Emergency Brake Assist (EBA) ACDC execution function */
  FCTSen_v_ACDC_Process(&t_ACDCRequirePorts
                       ,&t_ACDCProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                       , pServiceFuncts
#endif
                       );


#endif /* #if (FCT_CFG_ACDC_COMPONENT) */

  /*! Run Adaptive Cruise Control (ACC) - Headway Control in Sensor Task */
#if ( (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT) )

#if (FCT_CFG_ACT_CODE_VERSION)
  if ((b_RequirePortError != TRUE) && (b_ProvidePortError != TRUE))
  {
    FCTSen_v_Set_LOHP_Ports(&t_LOHP_RequirePorts, &t_LOHP_ProvidePorts, &t_SPMProvidePorts);
  }

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    LOHP_v_Exec(&t_LOHP_RequirePorts, &t_LOHP_ProvidePorts, &FCTSenFrame, pServiceFuncts);
#else
    LOHP_v_Exec(&t_LOHP_RequirePorts, &t_LOHP_ProvidePorts, &FCTSenFrame);
#endif

#else /* ACT Gen3 */

    /*! Set Headway Control (HC) require ports */
//     FCTSen_v_SetLOHPReqPort(pRequirePorts, pProvidePorts->pPubFctObj, 
// #if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
//       pProvidePorts->pFCTAccOOIData,
// #endif
// #if (FCT_CFG_CUSTOM_IO_INTERFACE)
//       pRequirePorts->pFCTCustomInput,
// #if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
//       pProvidePorts->pFCTCustomOutput, 
// #endif
// #endif
// #if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_SLATE_COMPONENT))
//       t_ACCProvidePorts.pSLATE_HC_Data,
// #endif
// #if (FCT_CFG_SIGNAL_PERF_MONITORING)
//       t_SPMProvidePorts.pSysPerfMonStates,
// #endif
//       &t_LOHPRequirePorts);

    /*! Set Headway Control (HC) provide ports as pointer to FCT_SEN provide port signals */
    FCTSen_v_SetLOHPProPort(pProvidePorts, &t_LOHP_UsageState, &t_LOHPProvidePorts);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  LOHP_v_Exec(&t_LOHPRequirePorts, &t_LOHPProvidePorts, &FCTSenFrame, pServiceFuncts);
#else
  // LOHP_v_Exec(&t_LOHPRequirePorts, &t_LOHPProvidePorts, &FCTSenFrame);
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */
#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT) */

  /* Custom function for custom outputs from FCT */
#if (FCT_SEN_CFG_CUSTOM_POST_PROC)
  if ((b_RequirePortError != TRUE) && (b_ProvidePortError != TRUE))
  {
    FCTSenCustomProc(pRequirePorts, pProvidePorts);
  }
#endif

  /*---------------------------------------------------------------------------*/
  /* Start Post-Processing (FCT)                                               */
  /*---------------------------------------------------------------------------*/

  /* Send RTA-Start Event for Post processing runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_POST_PROCESS, 0u);//PRQA S 4424
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */

  /* FCT is processed successfully. Set the signal status of SenCompState to Valid */
  /* The SenCompState is independent of input from other components */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  pProvidePorts->pSenCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
#endif

  if (b_ProvidePortError != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
  {
    FCTSenPostProcessing(pProvidePorts
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
      ,&t_ACCProvidePorts
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
      ,&t_SPMProvidePorts
#endif
#if (FCT_CFG_ACDC_COMPONENT)
      ,&t_ACDCProvidePorts
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
      ,&t_LOHPProvidePorts
#endif
      );
  }
  /* Send RTA-End Event for Post processing runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_POST_PROCESS, 0u);//PRQA S 4424 4
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */
  /* Send RTA-Start Event for Process Measfreeze runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_PROCESSFREEZE, 0u);

  if (b_ProvidePortError != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSenSetCompState (pProvidePorts->pSenCompState, FCTSenFrame.eFCTOpMode, AlgoErrorBuffer);
#endif
    if (b_RequirePortError != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
    {
#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
      /* if enabled this function checks all SigHeaders */
      FCTSenCheckProvideHeaders(pRequirePorts, pProvidePorts);
#endif
      /* setup all provide port headers (cyclecounter, measurementcounter, timestamp) */
      FCTSenSetProvideHeader(pRequirePorts, pProvidePorts);
    }
  }
  /* Output Meas Freezes */
#if (FCT_MEASUREMENT)
  if (b_ProvidePortError != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
  {
    /* Process other meas freezes */
    FCTSenProcessMeasFreeze(pProvidePorts);
  }
#endif /* FCT_MEASUREMENT */

  /* Send RTA-End Event for Process Measfreeze runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_PROCESSFREEZE, 0u);//PRQA S 4424 
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */

  /* Send RTA-Start Event for Frame Measfreeze runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  FCTSEN_RTA_FRAMEFREEZE, 0u);//PRQA S 4424 
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */

#if (FCT_MEASUREMENT)
  /* Freeze frame meas data in all cases, even in case of Error*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Safeguard for NULL-Pointer */
  if ((pServiceFuncts != NULL) 
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    && (pServiceFuncts->pfMeasStartFuncCycle != NULL)
#endif
    && (pServiceFuncts->pfMeasFreeze != NULL)
    && (pFCTSenServiceFuncts != NULL)
    && (pFCTSenServiceFuncts->pfMeasFreeze != NULL) )
  {
    FCTSenFrameFreeze();
  }
#else
  FCTSenFrameFreeze();
#endif
#endif

  /* Send RTA-End Event for Frame Measfreeze runtime */
  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_FRAMEFREEZE, 0u);//PRQA S 4424 4
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: enum is being converted to unsigned char, which does not have any side effects */
  /* Sends RTA-End Event for whole procedure runtime */

  FCTSEN_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  FCTSEN_RTA_PROCESS, 0u);
#if (FCT_CFG_RUNTIME_MEAS)
  /* Freeze FCT ACC runtime info */
  FCT_FREEZE_DATA(&t_FCTSEN_Runtime_MeasInfo, &t_FCTSEN_RuntimeInfo, NULL);
#endif
}// PRQA S 7002
/* date: 2019-02-25, reviewer: Timken George, reason: doesn't impact the functionality*/


/*************************************************************************************************************************
Functionname:    FCTSenSetSigHeaderError                                                                          */ /*!

  @brief           Set signal header with error values

  @description     Init SignalHeader_t struct with default values for FCT_SEN.
                    These default values are the cycle counter of FCT_SEN and the signal state invalid. 
                    Timestamp and measurement counter are set to zero.

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

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         28.10.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void FCTSenSetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiTimeStamp           = 0u;
  pSigHeader->uiMeasurementCounter  = 0u;
  pSigHeader->uiCycleCounter        = FCTSenFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

/*************************************************************************************************************************
  Functionname:    FCTSenFillSigHeader                                                                              */ /*!

  @brief           Fill FCT Sen signal header with default values

  @description     Fill SignalHeader_t struct with default values for FCT_SEN. These default values are the 
                    cycle counter of FCT_SEN, and the signal state based on the passed parameter.

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

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         22.10.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void FCTSenFillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = FCTSenFrame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    FCTSenSetSigHeaderState                                                                          */ /*!

  @brief           Set signal header state

  @return          -

  @param[in,out]   pSigHeader : pointer to signal header struct
  @param[in]       eSigState : signal state to be set

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSenSetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus            = eSigState;
}


#if (FCT_CFG_ERROR_OUTPUT_SEN)
static void FCTSen_v_InitErrorOut(FCTSenErrorOut_t * pDest)
{
  /* Fill in version number */
  pDest->uiVersionNumber        = FCT_SEN_ERROR_OUT_INTFVER;
  pDest->sSigHeader.eSigStatus  = AL_SIG_STATE_INVALID;
  /* Fill failure outputs with default unknown (i.e.: untested) state */
  pDest->ObjectNotMeasured    = AL_ERR_STATE_UNKNOWN;
  pDest->ObjectNotMeasTmp     = AL_ERR_STATE_UNKNOWN;
  pDest->Blockage             = AL_ERR_STATE_UNKNOWN;
  pDest->IncreaseBlockage     = AL_ERR_STATE_UNKNOWN;
  pDest->DecreaseBlockage     = AL_ERR_STATE_UNKNOWN;
#if(FCT_SEN_ERROR_OUT_INTFVER >= 0x0C)
  pDest->BelowMinPerfDist_AZ  = AL_ERR_STATE_UNKNOWN;
  pDest->BelowMinPerfDist_EL  = AL_ERR_STATE_UNKNOWN;
  pDest->BelowMinPerfDist_VDY = AL_ERR_STATE_UNKNOWN;
#endif
  pDest->bRequestRoadBeam = FALSE;

  pDest->bObjSelectionActive    = FALSE;
  pDest->bCollisionAvoidActive  = FALSE;
  
  pDest->SRDDampingState = AL_ERR_STATE_UNKNOWN;
#if (ALGO_ARS400Sensor)
  pDest->tSafetyDistanceEBA = 0.f;
#endif /* #if (ALGO_ARS400Sensor) */
  pDest->uiNoOfObjLosses = 0u; //?
  pDest->InterferenceRange = AL_ERR_STATE_UNKNOWN;
#if((FCT_SEN_ERROR_OUT_INTFVER >= 17U) && (ALGO_SensorType == ALGO_CFG_ARS510))
  pDest->ObjLossObserver = AL_ERR_STATE_UNKNOWN;
  pDest->RangeObserver = AL_ERR_STATE_UNKNOWN;
  pDest->TimeoutObserver = AL_ERR_STATE_UNKNOWN;
  pDest->PartialBlockageObserver = AL_ERR_STATE_UNKNOWN;
#endif
}
#endif

#if (FCT_CFG_LOHP_COMPONENT)
#if (FCT_CFG_ACT_CODE_VERSION)
/*************************************************************************************************************************
  Functionname:    FCT_v_Set_LOHP_Ports                                                                          */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[out]      pRequirePorts : 
  @param[out]      pProvidePorts : 

  @glob_in         FCTVeh_pCtrlData :
  @glob_in         FCTVEH_pLongCtrlResp :
  @glob_in         FCTVEH_pEgoDynRaw :
  @glob_in         &t_LOCC_TO_LOPC_VSCP :
  @glob_in         &t_LOPC_TO_LOCC_VSSP :
  @glob_in         &t_LOPC_TO_FCT_EVCP :

  @c_switch_part   FCT_CFG_HP_TFC_PORT_CNT
  @c_switch_full   FCT_CFG_ACT_CODE_VERSION
  @c_switch_full   FCT_CFG_LOHP_COMPONENT

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         13.10.2017
  @changed         13.10.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.Borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
static void FCTSen_v_Set_LOHP_Ports(LOHP_ReqPortList_t *pRequirePorts, LOHP_ProPortList_t *pProvidePorts, SPMProPort_t *pSPMProPorts)
#else
static void FCTSen_v_Set_LOHP_Ports(LOHP_ReqPortList_t *pRequirePorts, LOHP_ProPortList_t *pProvidePorts)
#endif
{
  if (pRequirePorts != NULL)
  {
    pRequirePorts->pt_LOHP_IN_Ctrl = FCTSEN_pSenCtrlData;

    pRequirePorts->pt_LOHP_IN_EgoVehDynCtrl = FCTSEN_pLongCtrlResp;
    pRequirePorts->pt_LOHP_IN_EgoVehDynState = FCTSEN_pEgoDynRaw;
    pRequirePorts->pt_LOHP_IN_TarVehDynState = FCTSEN_pAccOOIData;
    pRequirePorts->pt_LOHP_IN_HC_Data = &t_SLATE_HC_Data;

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    pRequirePorts->pt_LOHP_IN_SysPerfMonitor = pSPMProPorts->pSysPerfMonStates;
#endif

    pRequirePorts->pt_LOHP_IN_TCCP = pt_FCT_IN_TCCP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
    pRequirePorts->pt_LOHP_IN_TFSP = pt_FCT_IN_TFSP;
#endif
  }
  else
  {
    pRequirePorts = NULL;
  }

#if (FCT_CFG_HP_TFC_PORT_CNT)
  pProvidePorts->pt_LOHP_OUT_TFCP = pt_FCT_OUT_TFCP;
#endif

  pProvidePorts->pt_LOHP_OUT_TCSP = pt_FCT_OUT_TCSP;
}


#else /* FCT_CFG_ACT_CODE_VERSION */

/*************************************************************************************************************************
  Functionname:         FCTSen_v_SetLOHPReqPort                                                                      */ /*!

  @brief                Set LOHP require ports based on FCT_SEN require ports, SLATE provide ports and SPM provide ports

  @description          Set LOHP require ports based on FCT_SEN require ports, SLATE provide ports and SPM provide ports

  @return               -

  @param[in]            p_RequirePorts :Pointer to FCT_SEN require ports
  @param[in]            p_PubFctObj : Pointer to assessed object list output from FCTSen
  @param[in]            pFCTAccOOIData : Pointer to 6 OOI Interface output from FCTSen
  @param[in]            p_CustomOutput : Pointer to custom output from FCT
  @param[in]            p_SLATE_LOHP_Data : Pointer to data from SLATE to LOHP
  @param[in]            p_SPM_LOHP_Data : Pointer to data from SPM to LOHP
  @param[out]           p_LOHPRequirePorts : Pointer to LOHP require ports

  @glob_in              -
  @glob_out             -

  @c_switch_part        @ref FCT_CFG_SEN2VEH_ACC_OOI_PORT \n
                        @ref FCT_CFG_SIGNAL_PERF_MONITORING \n
                        @ref FCT_CFG_SLATE_COMPONENT \n
                        @ref FCT_CFG_CUSTOM_IO_INTERFACE \n
                        @ref FCT_CFG_BSW_ALGO_PARAMS \n
                        @ref FCT_SEN_CFG_VEH_SIG_INPUT \n
                        @ref FCT_CFG_ALIGNMENT_MONITORING_INPUT \n
                        @ref FCT_CFG_LOPC_COMPONENT \n
                        @ref FCT_CFG_ASSESSED_OBJ_OUT_INTF \n
                        @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST \n
                        @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST \n
                        @ref FCT_CFG_OBJECT_LIST_PROC \n
                        @ref FCT_CFG_EM_FCT_CYCLEMODE \n
  @c_switch_full        @ref FCT_CFG_ERROR_OUTPUT_SEN  \n
                        @ref FCT_CFG_LOHP_COMPONENT  \n
                        @ref FCT_CFG_ACT_CODE_VERSION  \n

  @pre                  -
  @post                 -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     One to one mapping

  @author               Niraj Mistry | Niraj.Mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void FCTSen_v_SetLOHPReqPort(const reqFCTSenPrtList_t * p_RequirePorts, 
                  const AssessedObjList_t * p_PubFctObj, 
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                  const FCTSenAccOOI_t* pFCTAccOOIData,
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
                  const FCTCustomInput_t  * p_CustomInput,
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
                  const FCTCustomOutput_t * p_CustomOutput, 
#endif
#endif
#if (FCT_CFG_SLATE_COMPONENT)
                  const SLATE_HC_Data_t * p_SLATE_LOHP_Data, 
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                  const SysPerfMonStates_t * pSysPerfMonStates,
#endif
                  reqLOHPPrtList_t * p_LOHPRequirePorts)
{
  if (p_RequirePorts != NULL)
  {
    p_LOHPRequirePorts->pSenCtrlData = p_RequirePorts->pSenCtrlData;
    p_LOHPRequirePorts->pEgoDynRaw = p_RequirePorts->pEgoDynRaw;
    p_LOHPRequirePorts->pEgoStaticData = p_RequirePorts->pEgoStaticData;
#if (FCT_CFG_EM_FCT_CYCLEMODE)
    p_LOHPRequirePorts->pEmFctCycleMode = p_RequirePorts->pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
    p_LOHPRequirePorts->pEmGenObjList = p_RequirePorts->pEmGenObjList;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    p_LOHPRequirePorts->pEmARSObjList = p_RequirePorts->pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    p_LOHPRequirePorts->pEmCamObjList = p_RequirePorts->pEmCamObjList; //??
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    p_LOHPRequirePorts->pPubFctObj = p_PubFctObj;
#endif
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    /* Longitudinal control input ports */
    p_LOHPRequirePorts->pFctVehLongOut = p_RequirePorts->pFctVehLongOut;
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_LOHPRequirePorts->pAlignmentMonInput = p_RequirePorts->pAlignmentMonInput;
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_LOHPRequirePorts->pVehSig = p_RequirePorts->pVehSig;
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    /* algo parameters from BSW */
    p_LOHPRequirePorts->pBswAlgoParameters = p_RequirePorts->pBswAlgoParameters;
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    p_LOHPRequirePorts->pFCTCustomInput = p_CustomInput;
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
    p_LOHPRequirePorts->pFCTCustomOutput = p_CustomOutput;
#endif
#endif
#if (FCT_CFG_SLATE_COMPONENT)
    p_LOHPRequirePorts->pSLATE_HC_Data = p_SLATE_LOHP_Data;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    p_LOHPRequirePorts->pSysPerfMonStates = pSysPerfMonStates;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    p_LOHPRequirePorts->pFCTAccOOIData = pFCTAccOOIData;
#endif
  }
  else
  {
    p_LOHPRequirePorts = NULL;// PRQA S 3199, 2983
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
  }

}


/*************************************************************************************************************************
  Functionname:         FCTSen_v_SetLOHPProPort                                                                      */ /*!

  @brief                Set LOHP provide ports based on FCT_SEN provide ports

  @description          Set LOHP provide ports based on FCT_SEN provide ports

  @return               -

  @param[in]            p_ProvidePorts : Pointer to FCT_SEN provide ports
  @param[in,out]        pLOHPUsageState : Pointer to global variable for LOHP Usage state output
  @param[in,out]        p_LOHPProvidePorts : Pointer to LOHP provide ports

  @glob_in              @ref pLOHPUsageState \n
  @glob_out             -

  @c_switch_part        @ref FCT_CFG_SEN2VEH_ACC_OOI_PORT \n
                        @ref FCT_CFG_USE_BUS_DEBUG \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE \n
  @c_switch_full        @ref FCT_CFG_ERROR_OUTPUT_SEN  \n
                        @ref FCT_CFG_LOHP_COMPONENT  \n
                        @ref FCT_CFG_ACT_CODE_VERSION  \n

  @pre                  -
  @post                 Calling of LOHP_v_Exec

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     One to one mapping

  @author               Niraj Mistry | Niraj.Mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void FCTSen_v_SetLOHPProPort(const proFCTSenPrtList_t * p_ProvidePorts,LOHP_ObjUsageState_t* pLOHPUsageState, LOHPProPort_t * p_LOHPProvidePorts)
{
  if (p_ProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    p_LOHPProvidePorts->pSenCompState = p_ProvidePorts->pSenCompState;  /*!< AlgoCompState interface to scheduler */
#endif
    p_LOHPProvidePorts->pAccDisplayObj = p_ProvidePorts->pAccDisplayObj;
    p_LOHPProvidePorts->pAccOutput = p_ProvidePorts->pAccOutput;
#if (FCT_CFG_USE_BUS_DEBUG)
    p_LOHPProvidePorts->pFCTSenBusDebugData = p_ProvidePorts->pFCTSenBusDebugData; /*!< Debug data */
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    p_LOHPProvidePorts->pLOHPUsageState = pLOHPUsageState;
#endif
  }
  else
  {
    p_LOHPProvidePorts = NULL;// PRQA S 3199, 2983
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
  }
}

#endif  /* FCT_CFG_ACT_CODE_VERSION */
#endif  /* FCT_CFG_LOHP_COMPONENT */

#if (FCT_CFG_ACDC_COMPONENT)
/*************************************************************************************************************************
  Functionname:         FctSen_v_SetACDCProPort                                                                      */ /*!

  @brief                Set ACDC provide ports based on FCT_SEN provide ports

  @description          Maps the FCT provide ports (@ref proFCTSenPrtList_t ) to the ACDC provide ports 
                        (@ref provFCTSenEBAPrtList_t ).

  @return               void

  @param[in]            p_FCTSenProvidePorts : Provided ports of FCT.
  @param[in]            pACDCErrorOut        : ACDC error output
  @param[out]           p_ACDCProvidePorts   : Provide ports of ACDC.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_ERROR_OUTPUT_SEN        \n
                        @ref FCT_CFG_USE_ALGOCOMPSTATE       \n
                        @ref FCT_CFG_COLLISION_DETECTION     \n
                        @ref FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE
  @c_switch_full        @ref FCT_CFG_ACDC_COMPONENT

  @pre                  None
  @post                 None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     see description

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void FctSen_v_SetACDCProPort(proFCTSenPrtList_t     const * const p_FCTSenProvidePorts
                                   ,ACDCErrorOutProPort_t        * const pACDCErrorOut
                                   ,provACDCPrtList_t            *       p_ACDCProvidePorts)
{
  if (p_FCTSenProvidePorts != NULL)
  {
    p_ACDCProvidePorts->pErrorOut         = pACDCErrorOut;
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    p_ACDCProvidePorts->pSenCompState     = p_FCTSenProvidePorts->pSenCompState;
#endif
#if (FCT_CFG_COLLISION_DETECTION) 
    p_ACDCProvidePorts->pHypotheses       = p_FCTSenProvidePorts->pFCTCDHypotheses;
#endif
#if (FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE)
    p_ACDCProvidePorts->pCDCustomOutput   = p_FCTSenProvidePorts->pCollDetOutput;
#endif
  }
  else
  {
    p_ACDCProvidePorts = NULL;// PRQA S 3199, 2983
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
  }
}

/*************************************************************************************************************************
  Functionname:         FctSen_v_SetACDCReqPort                                                                      */ /*!

  @brief                Maps the FCT require ports and output data to the ACDC require ports and output data.

  @description          Maps the FCT require ports (@ref reqFCTSenPrtList_t ) to the ACDC require ports 
                        (@ref reqACDCPrtList_t ). Maps also additional information about the current \n
                        ACCObject coming from the SLATE component to the ACDC require ports. The information 
                        is used for the ACC Hypothesis. This function is required as ACDC is not an entirely \n
                        independent component yet. It has its own ports but communicates them to FCT instead 
                        of to RTE. This will change as soon as a simulation on base of the new architecture \n
                        is possible.

  @return               void 

  @param[in]            p_FCTSenRequirePorts   : Require ports of FCT.
  @param[in]            pSLATE_CD_Data   : Structure filled by the SLATE component, contains ACC object.
  @param[in]            p_ACDCRequirePorts: Require ports of ACDC.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_COLLISION_DETECTION        \n
                        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL    \n
                        @ref FCT_CFG_SHORT_RANGE_FUNCTIONS      \n
                        @ref FCT_CFG_EM_FCT_CYCLEMODE           \n
                        @ref FCT_USE_EM_CUSTOM_OBJECT_LIST      \n
                        @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST    \n
                        @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST    \n
                        @ref FCT_CFG_ALIGNMENT_MONITORING_INPUT \n
                        @ref FCT_CFG_INCLUDE_UNUSED_INTF        \n
                        @ref FCT_CFG_INCLUDE_FUSION_OBJECT_LIST
  @c_switch_full        @ref FCT_CFG_ACDC_COMPONENT

  @pre                  None
  @post                 None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     see description

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void FctSen_v_SetACDCReqPort(reqFCTSenPrtList_t const * const p_FCTSenRequirePorts, 
#if ((FCT_CFG_COLLISION_DETECTION) && (FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
                                    SLATE_CD_Data_t    const * const pSLATE_CD_Data,
#endif
                                    reqACDCPrtList_t         *       p_ACDCRequirePorts)
{
  if (p_FCTSenRequirePorts != NULL)
  {
    p_ACDCRequirePorts->pSenCtrlData       = p_FCTSenRequirePorts->pSenCtrlData;          /*< Control data containing the operation mode */

#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
    p_ACDCRequirePorts->pEgoDynObjSync     = p_FCTSenRequirePorts->pEgoDynObjSync;        /*< VDY vehicle dynamics data synchronized with object data */
#endif
    p_ACDCRequirePorts->pEgoDynRaw         = p_FCTSenRequirePorts->pEgoDynRaw;            /*< VDY vehicle dynamics data */
    p_ACDCRequirePorts->pEgoStaticData     = p_FCTSenRequirePorts->pEgoStaticData;        /*< VDY vehicle static parameter data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
    p_ACDCRequirePorts->pEmFctCycleMode    = p_FCTSenRequirePorts->pEmFctCycleMode;       /*< The global sensor state */
#endif
#if(ACDC_CFG_USE_FPS || ACDC_AIP_CFG_SHIFT_COORDINATE)
    p_ACDCRequirePorts->pEmGenObjList      = (EM_t_GenObjectList * )p_FCTSenRequirePorts->pEmGenObjList;         /*< EM generic object list */
#else
	p_ACDCRequirePorts->pEmGenObjList = p_FCTSenRequirePorts->pEmGenObjList;         /*< EM generic object list */
#endif
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    p_ACDCRequirePorts->pEmCustObjList     = p_FCTSenRequirePorts->pEmCustObjList;        /*< EM customer specific object list */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    p_ACDCRequirePorts->pEmARSObjList      = p_FCTSenRequirePorts->pEmARSObjList;         /*< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    p_ACDCRequirePorts->pEmCamObjList      = p_FCTSenRequirePorts->pEmCamObjList;         /*< EM Camera-technology-specific object list */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_ACDCRequirePorts->pAlignmentMonInput = p_FCTSenRequirePorts->pAlignmentMonInput;    /*< Alignment monitoring output data */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    p_ACDCRequirePorts->pBswAlgoParameters = p_FCTSenRequirePorts->pBswAlgoParameters;    /*< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_COLLISION_DETECTION)&&(FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
    p_ACDCRequirePorts->pSLATE_CD_Data     = pSLATE_CD_Data;                              /*< Data from SLATE component  */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    p_ACDCRequirePorts->pEmFusionObjList   = p_FCTSenRequirePorts->pEmFusionObjList; /* EM Fusion Object List */
#endif

  }
  else
  {
    p_ACDCRequirePorts = NULL;// PRQA S 3199, 2983
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
  }
}
#endif /* FCT_CFG_ACDC_COMPONENT */

/*************************************************************************************************************************
  Functionname:         FctSen_v_FusePorts                                                                      */ /*!

  @brief                Fuse error output ports to FCT sensor provide port

  @description          Fuse ACC (@ref provSLATEPortList_t), SPM (@ref SPMProPort_t) and ACDC provide ports 
                        (@ref provACDCPrtList_t) to FCT sensor provide port (@ref proFCTSenPrtList_t).\n
                        Map the worst eSigStatus among all error output ports to the error output of FCT 
                        sensor provide port.

  @return               void 

  @param[in]            p_FCTSenProvidePorts:  provide ports of FCT.
  @param[in]            p_SLATEProvidePorts:     provide ports of ACC.
  @param[in]            p_SPMProvidePorts:     provide ports of SPM.
  @param[in]            p_ACDCProvidePorts:    provide ports of ACDC.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL \n
                        @ref FCT_CFG_SIGNAL_PERF_MONITORING  \n
                        @ref FCT_CFG_ACDC_COMPONENT \n
                        @ref FCT_CFG_ERROR_OUTPUT_SEN
  @c_switch_full        None

  @pre                  @ref FCTSen_v_InitErrorOut was called.
  @post                 None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     see description

  @todo                 Fuse port for FCTCustomOutput
  
  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
static void FctSen_v_FusePorts(proFCTSenPrtList_t     const * const p_FCTSenProvidePorts
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
                              ,provSLATEPortList_t     const * const p_SLATEProvidePorts
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                              ,SPMProPort_t     const * const p_SPMProvidePorts
#endif
#if (FCT_CFG_ACDC_COMPONENT)
                              ,provACDCPrtList_t      const * const p_ACDCProvidePorts
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                              ,LOHPProPort_t          const * const p_LOHPProvidePorts
#endif
                              )
{
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  AlgoSignalState_t eSignalStatus = AL_SIG_STATE_OK;
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  p_FCTSenProvidePorts->pErrorOut->bObjSelectionActive  = (p_SLATEProvidePorts->pt_SLATEErrorOut->b_ObjSelectionActive);
  p_FCTSenProvidePorts->pErrorOut->BelowMinPerfDist_AZ  = (p_SLATEProvidePorts->pt_SLATEErrorOut->t_BelowMinPerfDist_AZ);
  p_FCTSenProvidePorts->pErrorOut->BelowMinPerfDist_EL  = (p_SLATEProvidePorts->pt_SLATEErrorOut->t_BelowMinPerfDist_EL);
  p_FCTSenProvidePorts->pErrorOut->BelowMinPerfDist_VDY = (p_SLATEProvidePorts->pt_SLATEErrorOut->t_BelowMinPerfDist_VDY);
  if (p_SLATEProvidePorts->pt_SLATEErrorOut->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
  {
    eSignalStatus = AL_SIG_STATE_INVALID;
  }
  else
  {
    if (p_SLATEProvidePorts->pt_SLATEErrorOut->sSigHeader.eSigStatus == AL_SIG_STATE_INIT)
    {
      eSignalStatus = AL_SIG_STATE_INIT;
    }
  }
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  p_FCTSenProvidePorts->pErrorOut->bRequestRoadBeam  = p_SPMProvidePorts->pErrorOut->b_RequestRoadBeam;
  p_FCTSenProvidePorts->pErrorOut->Blockage          = p_SPMProvidePorts->pErrorOut->t_Blockage;
  p_FCTSenProvidePorts->pErrorOut->DecreaseBlockage  = p_SPMProvidePorts->pErrorOut->t_DecreaseBlockage;
  p_FCTSenProvidePorts->pErrorOut->IncreaseBlockage  = p_SPMProvidePorts->pErrorOut->t_IncreaseBlockage;
  p_FCTSenProvidePorts->pErrorOut->InterferenceRange = p_SPMProvidePorts->pErrorOut->t_InterferenceRange;
  p_FCTSenProvidePorts->pErrorOut->ObjectNotMeasTmp  = p_SPMProvidePorts->pErrorOut->t_ObjectNotMeasTmp;
  p_FCTSenProvidePorts->pErrorOut->ObjectNotMeasured = p_SPMProvidePorts->pErrorOut->t_ObjectNotMeasured;
  p_FCTSenProvidePorts->pErrorOut->SRDDampingState   = p_SPMProvidePorts->pErrorOut->t_SRDDampingState;
  p_FCTSenProvidePorts->pErrorOut->uiNoOfObjLosses   = p_SPMProvidePorts->pErrorOut->u_NoOfObjLosses;
  #if((SPM_OBSERVERS_HISOTRY == SWITCH_ON) && (FCT_SEN_ERROR_OUT_INTFVER >= 17U) && (ALGO_SensorType == ALGO_CFG_ARS510))
    p_FCTSenProvidePorts->pErrorOut->ObjLossObserver = p_SPMProvidePorts->pErrorOut->t_ObjectLossObserver;
    p_FCTSenProvidePorts->pErrorOut->RangeObserver = p_SPMProvidePorts->pErrorOut->t_RangeObserver;
    p_FCTSenProvidePorts->pErrorOut->TimeoutObserver = p_SPMProvidePorts->pErrorOut->t_TimeoutObserver;
    p_FCTSenProvidePorts->pErrorOut->PartialBlockageObserver = p_SPMProvidePorts->pErrorOut->t_PartialBlockageObserver;
  #endif


  if ((eSignalStatus == AL_SIG_STATE_INVALID)||(p_SPMProvidePorts->pErrorOut->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID))
  {
    eSignalStatus = AL_SIG_STATE_INVALID;
  }
  else
  {
    if (p_SPMProvidePorts->pErrorOut->sSigHeader.eSigStatus == AL_SIG_STATE_INIT)
    {
      eSignalStatus = AL_SIG_STATE_INIT;
    }
  }
  #if((SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)&&(FCT_SEN_ERROR_OUT_INTFVER >= 20U) && (ALGO_ARS500Sensor))
    p_FCTSenProvidePorts->pErrorOut->BlockageType = p_SPMProvidePorts->pErrorOut->t_BlockageType;
    p_FCTSenProvidePorts->pErrorOut->BlockageCategory = p_SPMProvidePorts->pErrorOut->t_BlockageCategory;
    p_FCTSenProvidePorts->pErrorOut->PartialBlockageLevel = p_SPMProvidePorts->pErrorOut->t_PartialBlockageLevel;
  #endif
#endif
#if (FCT_CFG_ACDC_COMPONENT)

  p_FCTSenProvidePorts->pErrorOut->bCollisionAvoidActive = p_ACDCProvidePorts->pErrorOut->bCollisionAvoidActive;
#if (ALGO_ARS400Sensor)
  p_FCTSenProvidePorts->pErrorOut->tSafetyDistanceEBA    = p_ACDCProvidePorts->pErrorOut->fSafetyDistanceEBA;
#if (FCT_SEN_ERROR_OUT_INTFVER >= 16u)
  p_FCTSenProvidePorts->pErrorOut->eSafetyDistStateEBA   = p_ACDCProvidePorts->pErrorOut->eSafetyDistanceEBAState;
#endif
#endif /* #if (ALGO_ARS400Sensor) */

  if ((eSignalStatus == AL_SIG_STATE_INVALID)||(p_ACDCProvidePorts->pErrorOut->sSigHeader.eSigStatus== AL_SIG_STATE_INVALID))
  {
    eSignalStatus = AL_SIG_STATE_INVALID;
  }
  else
  {
    if (p_ACDCProvidePorts->pErrorOut->sSigHeader.eSigStatus == AL_SIG_STATE_INIT)
    {
      eSignalStatus = AL_SIG_STATE_INIT;
    }
  }
#endif
  p_FCTSenProvidePorts->pErrorOut->sSigHeader.eSigStatus = eSignalStatus;
#endif

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  p_FCTSenProvidePorts->pFCTAccOOIData->AccOOINextLong.Attributes.eUsageState         = p_LOHPProvidePorts->pLOHPUsageState->UsageState_OOI_0;
  p_FCTSenProvidePorts->pFCTAccOOIData->AccOOIHiddenNextLong.Attributes.eUsageState   = p_LOHPProvidePorts->pLOHPUsageState->UsageState_OOI_1;
  p_FCTSenProvidePorts->pFCTAccOOIData->AccOOINextLeft.Attributes.eUsageState         = p_LOHPProvidePorts->pLOHPUsageState->UsageState_OOI_2;
  p_FCTSenProvidePorts->pFCTAccOOIData->AccOOINextRight.Attributes.eUsageState        = p_LOHPProvidePorts->pLOHPUsageState->UsageState_OOI_3;
  p_FCTSenProvidePorts->pFCTAccOOIData->AccOOIHiddenNextLeft.Attributes.eUsageState   = p_LOHPProvidePorts->pLOHPUsageState->UsageState_OOI_4;
  p_FCTSenProvidePorts->pFCTAccOOIData->AccOOIHiddenNextRight.Attributes.eUsageState  = p_LOHPProvidePorts->pLOHPUsageState->UsageState_OOI_5;
#endif

  _PARAM_UNUSED(p_FCTSenProvidePorts);//PRQA S 3119 12
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason: Variable kept for further implementation*/
#if (FCT_CFG_ACDC_COMPONENT)
  _PARAM_UNUSED(p_ACDCProvidePorts);
#endif
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  _PARAM_UNUSED(p_SLATEProvidePorts);
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  _PARAM_UNUSED(p_SPMProvidePorts);
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  _PARAM_UNUSED(p_LOHPProvidePorts);
#endif
}

/*************************************************************************************************************************
  Functionname:         FCTSenPostProcessing                                                                      */ /*!

  @brief                Do FCT sensor information post-processing

  @description          Do post-processing needed by FCT component. 
                         - Calls function for initializing the FCT sensor error output states: @ref FCTSen_v_InitErrorOut.
                         - Calls function for fusing error output ports to FCT sensor provide port: @ref FctSen_v_FusePorts.

  @return               void 

  @param[in]            p_FCTSenProvidePorts: provide ports of FCT.
  @param[in]            p_SLATEProvidePorts:    provide ports of ACC.
  @param[in]            p_SPMProvidePorts:    provide ports of SPM.
  @param[in]            p_ACDCProvidePorts:   provide ports of ACDC.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL \n
                        @ref FCT_CFG_SIGNAL_PERF_MONITORING  \n
                        @ref FCT_CFG_ACDC_COMPONENT \n
                        @ref FCT_CFG_ERROR_OUTPUT_SEN
  @c_switch_full        None

  @pre                  None
  @post                 None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     see description

  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
static void FCTSenPostProcessing(proFCTSenPrtList_t     const * const p_FCTSenProvidePorts
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
                                ,provSLATEPortList_t     const * const p_SLATEProvidePorts
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                                ,SPMProPort_t           const * const p_SPMProvidePorts
#endif
#if (FCT_CFG_ACDC_COMPONENT)
                                ,provACDCPrtList_t      const * const p_ACDCProvidePorts
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                ,LOHPProPort_t          const * const p_LOHPProvidePorts
#endif
                                )
{
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  FCTSen_v_InitErrorOut(p_FCTSenProvidePorts->pErrorOut);
#endif
  FctSen_v_FusePorts(p_FCTSenProvidePorts
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
                    ,p_SLATEProvidePorts
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
                    ,p_SPMProvidePorts
#endif
#if (FCT_CFG_ACDC_COMPONENT)
                    ,p_ACDCProvidePorts
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                    ,p_LOHPProvidePorts
#endif
                    );
}

#if (FCT_CFG_ACDC_COMPONENT)
/*************************************************************************************************************************
  Functionname:         FCTSen_v_ACDC_Process                                                                     */ /*!

  @brief                Process function to call ACDC_v_Exec this has to be called from the FCT Frame. 
                        If ACDC is called without FCT the functionality here has to be implemented in the sim code respectively in SW.

  @description          Provide the necessary memory, call ACDC_v_Exec and freeze the ACDC data 

  @return               void
  
  @param[in]            p_ACDCRequirePorts :       Require ports, provided by the RTE.
  @param[in,out]        p_ACDCProvidePorts :       Provide ports, provided towards the RTE.
  @param[in]            p_ServiceFuncts :          Service function pointers provided by the RTE.


  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref FCT_SIMU\n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        None

  @pre                  None 
  @post                 None 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     Not defined 


  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSen_v_ACDC_Process( reqACDCPrtList_t   const * const p_ACDCRequirePorts 
                                  ,provACDCPrtList_t        * const p_ACDCProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                  ,AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif
                                                                                       )
{
#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
  /* ACDC process memory */
  ACDC_ProcMem_t ACDCProcMem     = {NULL};
  /* Assign memory pointer */
  ACDCProcMem.pMemInterCycle     = &ACDCInter;
  ACDCProcMem.pMemInterCycleMeas = &ACDCInterMeas;
  ACDCProcMem.pMemIntraCycle     = &ACDCIntra;
  ACDCProcMem.pMemIntraCycleMeas = &ACDCIntraMeas;
#ifdef FCT_SIMU
  ACDCProcMem.pMemSimu           = &ACDCSimuData;
#endif

  /* Reset the structure to guarantee the non-persistent behavior of the memory */
  (void) memset (&ACDCIntraMeas, 0, sizeof(GA_ACDC_Mem_DataIntraCycleMeas));//PRQA S 0315 2
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Case to void intended as use of generic interface */
  (void) memset (&ACDCIntra,     0, sizeof(GA_ACDC_Mem_DataIntraCycle)    );
#endif

  /*! Run Emergency Brake Assist (EBA) ACDC execution function */
  ACDC_v_Exec( p_ACDCRequirePorts
             , p_ACDCProvidePorts
#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
             , &ACDCProcMem
#endif
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
             , p_ServiceFuncts
#endif
    );

#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
  FCTSen_FreezeACDCProcMem(&ACDCProcMem);
#endif
}

#if !FCT_CFG_USE_ACDC_INTERNAL_MEMORY
/*************************************************************************************************************************
  Functionname:         FCTSen_FreezeACDCProcMem                                                                     */ /*!

  @brief                Freeze all data from ACDC 

  @description          Freeze all data from ACDC 

  @return               void
  
  @param[in]            pACDCProcMem : Pointer to the memory used in ACDC

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref FCT_SIMU\n
  @c_switch_full        None

  @pre                  None 
  @post                 None 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     Not defined 


  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSen_FreezeACDCProcMem(ACDC_ProcMem_t const * const pACDCProcMem)
{
  MEASInfo_t MeasInfo = {(uint32)0, (uint32)0, FCT_MEAS_FUNC_ID, FCT_MEAS_FUNC_CHAN_ID };

  MeasInfo.VirtualAddress = GA_ACDC_MEAS_ID_INTRA_CYCLE_MEAS_DATA;
  MeasInfo.Length         = GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS;
  FCT_FREEZE_DATA(&MeasInfo, pACDCProcMem->pMemIntraCycleMeas, &FCTSenMeasCallback);//PRQA S 3200 , 0315
  /* date: 2018-09-11, reviewer:Ravi Kiran Gurrala, reason: The return value of MEASFreezeDataMTS is not used currently, Not Critical */

  MeasInfo.VirtualAddress = GA_ACDC_MEAS_ID_INTER_CYCLE_MEAS_DATA;
  MeasInfo.Length         = GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE_MEAS;
  FCT_FREEZE_DATA(&MeasInfo, pACDCProcMem->pMemInterCycleMeas,  &FCTSenMeasCallback);//PRQA S 3200, 0315
  /* date: 2018-09-11, reviewer:Ravi Kiran Gurrala, reason: The return value of MEASFreezeDataMTS is not used currently, Not Critical */

#ifdef FCT_SIMU

  MeasInfo.VirtualAddress = GA_ACDC_MEAS_ID_INTER_CYCLE_DATA;
  MeasInfo.Length         = GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE;
  FCT_FREEZE_DATA(&MeasInfo, pACDCProcMem->pMemInterCycle,  &FCTSenMeasCallback);//PRQA S 3200
  /* date: 2018-09-11, reviewer:Ravi Kiran Gurrala, reason: The return value of MEASFreezeDataMTS is not used currently, Not Critical */


  /* In simulation freeze also ecu data which is not frozen in ECU */
  MeasInfo.VirtualAddress = GA_ACDC_MEAS_ID_INTRA_CYCLE_DATA;
  MeasInfo.Length         = GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE;
  FCT_FREEZE_DATA(&MeasInfo, pACDCProcMem->pMemIntraCycle,  &FCTSenMeasCallback);

  /* In simulation freeze all simulation data */
  MeasInfo.VirtualAddress = GA_ACDC_MEAS_ID_SIMU;
  MeasInfo.Length         = GA_ACDC_SIZE_MEM_DATA_SIMU;
  FCT_FREEZE_DATA(&MeasInfo, pACDCProcMem->pMemSimu,        &FCTSenMeasCallback);
#endif

}
#endif

#endif /*(FCT_CFG_ACDC_COMPONENT)*/
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

/* date: 2019-03-19, reviewer: Ravi Kiran Gurrala, reason: Number of lines exceeded per file, not safety critical */
// PRQA S 7013
