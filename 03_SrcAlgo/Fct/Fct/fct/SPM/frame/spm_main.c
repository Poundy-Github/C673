// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.47 $

/*!**********************************************************************
CHANGES:                   $Log: spm_main.c  $
CHANGES:                   Revision 1.47 2021/02/15 17:04:37CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix pragma comment
CHANGES:                   Revision 1.46 2021/02/02 09:35:36CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC boolean issue
CHANGES:                   Revision 1.45 2020/09/01 07:05:37CEST Pallo, Istvan (palloi) 
CHANGES:                   Initilize blockage category and partial blockage level
CHANGES:                   Revision 1.44 2020/07/14 14:19:55CEST Pallo, Istvan (palloi) 
CHANGES:                   Update blockage type config switch
CHANGES:                   Revision 1.43 2020/06/30 16:28:21CEST Pallo, Istvan (palloi) 
CHANGES:                   Revert SRR SPM split changes on trunk
CHANGES:                   Revision 1.42 2020/06/26 09:48:57CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix compilation warnings on devgate
CHANGES:                   Revision 1.41 2020/06/25 08:07:58CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.40 2020/06/12 06:26:12CEST Pallo, Istvan (palloi) 
CHANGES:                   Initialize blockage type in ErrorOut
CHANGES:                   Revision 1.39 2020/06/02 16:23:07CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove call of compute weather factor and VehSig global variable.
CHANGES:                   Revision 1.38 2020/04/24 12:38:05CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC level 3 warnings
CHANGES:                   Revision 1.37 2020/04/08 13:29:10CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC level 4 warnings
CHANGES:                   Revision 1.36 2020/03/03 08:12:45CET Pallo, Istvan (palloi) 
CHANGES:                   Add new global variable for VehSig. Call computation function for weather factor
CHANGES:                   Revision 1.35 2019/05/29 10:49:38CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add suppress message
CHANGES:                   Revision 1.34 2019/05/28 07:47:03CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.33 2019/05/16 10:28:36CEST Pallo, Istvan (palloi) 
CHANGES:                   Add implementation for RTA_CYCLEID_FCT_SEN if defined
CHANGES:                   Revision 1.32 2019/04/22 13:28:20CEST Pallo, Istvan (palloi) 
CHANGES:                   Define the new global variable for vehicle data
CHANGES:                   Revision 1.31 2018/09/24 15:13:26CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.30 2018/04/24 06:18:50CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix call of setup provide ports
CHANGES:                   Revision 1.29 2018/04/13 10:02:41CEST Pallo, Istvan (palloi) 
CHANGES:                   Correct config switch for ALN global variable
CHANGES:                   Revision 1.28 2018/04/12 14:37:34CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new global variable for request port added. Use internal variables instead of port variables.
CHANGES:                   Revision 1.27 2018/03/26 14:10:34CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove set port functions
CHANGES:                   Revision 1.26 2018/03/20 14:57:22CET Pallo, Istvan (palloi) 
CHANGES:                   Correct consideration of veh dyn int ver in setting roller bench test flag
CHANGES:                   Revision 1.25 2018/03/15 14:02:53CET Pallo, Istvan (palloi) 
CHANGES:                   Declare global variable for ALN monitoring. Call SPMProcess with correct parameters. Set ALN monitoring req port for SPM.
CHANGES:                   Revision 1.24 2018/03/09 13:21:27CET Pallo, Istvan (palloi) 
CHANGES:                   Rename version variables and defines
CHANGES:                   Revision 1.23 2018/02/28 12:12:53CET Pallo, Istvan (palloi) 
CHANGES:                   Remove eba safety distance initialization as it is no longer computed by SPM
CHANGES:                   Revision 1.22 2018/02/28 11:31:00CET Pallo, Istvan (palloi) 
CHANGES:                   Replace VAR with CONST for setting of constant variables
CHANGES:                   Revision 1.21 2018/02/27 17:16:17CET Pallo, Istvan (palloi) 
CHANGES:                   Remove extern static declaration
CHANGES:                   Revision 1.20 2018/02/27 17:11:25CET Pallo, Istvan (palloi) 
CHANGES:                   Remove PDO comment
CHANGES:                   Revision 1.19 2018/02/27 11:51:48CET Pallo, Istvan (palloi) 
CHANGES:                   Remove string library include.
CHANGES:                   Add global variables.
CHANGES:                   Remove const from function parameters.
CHANGES:                   Revision 1.18 2018/02/23 14:27:22CET Pallo, Istvan (palloi) 
CHANGES:                   Restructure port and error handling. Remove obsolute functions.
CHANGES:                   Revision 1.17 2017/12/05 18:47:03CET Pallo, Istvan (palloi) 
CHANGES:                   Add pdo guard for string include.
CHANGES:                   Add global variable for SPMErrorOut.
CHANGES:                   New function for init error out each cycle.
CHANGES:                   Update functions headers with new SPM ports name.
CHANGES:                   Revision 1.16 2017/11/22 08:59:45CET Pallo, Istvan (palloi) 
CHANGES:                   Add QAC comment
CHANGES:                   Revision 1.15 2017/11/22 08:06:40CET Pallo, Istvan (palloi) 
CHANGES:                   Replace LOPC config switch with LOHP config switch as pSPM_HC_Data is used in LOHP
CHANGES:                   Revision 1.14 2017/11/16 15:04:13CET Pallo, Istvan (palloi) 
CHANGES:                   Add missing port initialization in FCTSenErrorOut
CHANGES:                   Revision 1.13 2017/11/16 14:51:59CET Pallo, Istvan (palloi) 
CHANGES:                   Implementation for setting provide ports signal status based of SPM operating mode
CHANGES:                   Revision 1.12 2017/10/27 08:12:34CEST Pallo, Istvan (palloi) 
CHANGES:                   New function header for add service event
CHANGES:                   Revision 1.11 2017/10/17 15:12:40CEST Pallo, Istvan (palloi) 
CHANGES:                   Check require and provide ports. Make ref sync. Set init flag on true for SPM after first processing cycle is done.
CHANGES:                   Revision 1.10 2017/10/13 11:20:30CEST Pallo, Istvan (palloi) 
CHANGES:                   Set initialization flag to true after calling init in init state. Check for signal header before set freeze state of SPM
CHANGES:                   Revision 1.9 2017/08/17 08:30:49CEST Kramer, Andreas (uidv8254) 
CHANGES:                   Reverted changed comment style
CHANGES:                   Revision 1.6 2017/08/11 08:32:45CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix for QA-C warnings
CHANGES:                   Revision 1.5 2017/08/02 11:38:21CEST Pallo, Istvan (palloi) 
CHANGES:                   Addapt velocity speed for new VDY interface
CHANGES:                   Revision 1.4 2017/07/28 07:04:57CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove function declarations from file. Remove headers.
CHANGES:                   Revision 1.3 2017/07/10 08:38:47CEST Umesh Babu, Harsha (uidj3583) 
CHANGES:                   Corrected structure member access
CHANGES:                   Revision 1.2 2017/06/21 09:51:09CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove most of the function headers.
CHANGES:                   Change the file header
CHANGES:                   Revision 1.1 2017/03/17 13:16:57CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj


**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_main.h" /* PRQA S 0380 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: multiple header files inherited according to include strategy */


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

/*! Fame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(t_FCTSenSPMFrame)
FCTSenSPMFrame_t t_FCTSenSPMFrame;

#if (FCT_CFG_RUNTIME_MEAS)
/*! FCT ACC time measurement info */
SET_MEMSEC_VAR(t_FCTSEN_SPMRuntimeInfo)
static FCT_SPMRuntimeInfo_t t_FCTSEN_SPMRuntimeInfo;
#endif

#if(FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(pSPMCompState)
AlgoCompState_t * pSPMCompState;
#endif

#if (FCT_CFG_RUNTIME_MEAS)
/* Meas freeze structure for FCT ACC runtime info */ 
SET_MEMSEC_VAR(t_FCTSEN_SPMRuntime_MeasInfo)
  /* PalloI, 09.08.2017, Reason: MTS variable */
  /*PRQA S 3408*/const MEASInfo_t t_FCTSEN_SPMRuntime_MeasInfo = {
  FCT_MEAS_ID_SPM_RUNTIME_DEBUG,      /* VirtualAddress */
  sizeof(FCT_SPMRuntimeInfo_t),      /* Length */
  FCT_SPM_MEAS_FUNC_ID,               /* FuncID */
  FCT_SPM_MEAS_FUNC_CHAN_ID           /* FuncChannelID */
};
#endif


SET_MEMSEC_VAR(SPMPortHandlerList)
SPMPortHandlerList_t SPMPortHandlerList;

#if(FCT_CFG_ERROR_OUTPUT_SEN)
SET_MEMSEC_VAR(SPM_pErrorOut)
SPMErrorOutProPort_t * SPM_pErrorOut;
#endif

/* Meas freeze reference */
SET_MEMSEC_VAR(t_FCTSenSPMSyncRef)
FCTSen_SPMSyncRef_t t_FCTSenSPMSyncRef;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(pFCTSenSPMServiceFuncts)
const AS_t_ServiceFuncts *pFCTSenSPMServiceFuncts;
#endif

#if (FCT_CFG_EM_FCT_CYCLEMODE)
SET_MEMSEC_CONST(FCTSEN_pSPMEmFctCycleMode)
const EmFctCycleMode_t       * FCTSEN_pSPMEmFctCycleMode;   /* Global system cycle mode etc. data */
#endif

SET_MEMSEC_CONST(FCTSEN_pSPMPerfDegrData)
const PerfDegr_t             * FCTSEN_pSPMPerfDegrData;     /* Performance degradation input data */

SET_MEMSEC_CONST(FCTSEN_pSPMEgoDynRaw)
const VehDyn_t               * FCTSEN_pSPMEgoDynRaw;     /* Performance degradation input data */

SET_MEMSEC_CONST(pSPMEgoDynObjSync)
const VehDyn_t            * pSPMEgoDynObjSync;         /* The dynamic vehicle ego data object sync */

SET_MEMSEC_VAR(FCTSEN_pSPMSysPerfMonStates)
SysPerfMonStates_t           * FCTSEN_pSPMSysPerfMonStates; /* System performance monitor output data */

#if (FCT_CFG_OBJECT_LIST_PROC)
  #if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    SET_MEMSEC_CONST(FCTSEN_pSPMPubFctObj)
    const AssessedObjList_t * FCTSEN_pSPMPubFctObj;         /* The public FCT object data */
  #endif
  #if (FCT_USE_EM_GENERIC_OBJECT_LIST)
    SET_MEMSEC_CONST(FCTSEN_pSPMEmGenObjList)
    const EM_t_GenObjectList * FCTSEN_pSPMEmGenObjList;     /* The generic EM object data */
    #if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      SET_MEMSEC_CONST(FCTSEN_pSPMEmARSObjList)
      const EM_t_ARSObjectList * FCTSEN_pSPMEmARSObjList;
    #endif
  #else
    SET_MEMSEC_CONST(FCTSEN_pSPMEmObjList)
    const ObjectList_t * FCTSEN_pSPMEmObjList;        /* The public EM object data */
  #endif
#endif

#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_CONST(pSPMPerfDegrExtInput)
const PerfDegrExtInput_t * pSPMPerfDegrExtInput;
#endif

SET_MEMSEC_CONST(pSPMCtrlData)
const FCTCtrlData_t * pSPMCtrlData; /* PRQA S 2200 */ /* 2020-04-27, reviewer:Opreai01, Popam05, PalloI, reason: No indentation problem */

SET_MEMSEC_CONST(pSPMBswAlgoParameters)
const BSW_s_AlgoParameters_t * pSPMBswAlgoParameters;

#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
SET_MEMSEC_CONST(FCTSEN_pSLATE_SPM_Data)
const SLATE_SPM_Data_t * FCTSEN_pSLATE_SPM_Data;
#endif

#if (SYS_PERF_MON_OUT_INTFVER >= 3u)
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_VAR(pSPMSysPerfMonStates)
SysPerfMonStates_t * pSPMSysPerfMonStates;
#endif
#endif
#endif

#if(FCT_CFG_LOHP_COMPONENT)
SET_MEMSEC_VAR(pSPMHCData)
SPM_HC_Data_t * pSPMHCData;
#endif

#if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE)
SET_MEMSEC_VAR(pAlignState)
e_AlignState_t * pAlignState;
#endif

#if((FCT_CFG_ALIGNMENT_MONITORING_INPUT) && (FCT_CFG_ALIGNMENT_MONITORING_INPUT))
SET_MEMSEC_CONST(pALNMonitoring)
const ALN_S_Monitoring_t * pALNMonitoring;
#endif

#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_CONST(pFctVehLongOut)
const FctVeh2SenInfo_t *pFctVehLongOut;
#endif

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

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (FCT_CFG_ERROR_OUTPUT_SEN)
static void SPM_v_InitErrorOut(SPMErrorOutProPort_t * p_ErrorOut);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void FCTSen_SPM_Exec(const reqFCTSenSPMPrtList_t * p_RequirePorts, SPMProPort_t * const p_ProvidePorts, const FCT_OP_MODE_t t_FCTSenFrameFCTOpMode, const AS_t_ServiceFuncts *p_ServiceFuncts)
#else
void FCTSen_SPM_Exec(const reqFCTSenSPMPrtList_t * p_RequirePorts, SPMProPort_t * const p_ProvidePorts,const FCT_OP_MODE_t t_FCTSenFrameFCTOpMode)
#endif
{
  AlgoErrorState_t t_Blockage, t_SelfTest;
  float32 fEgoSpeedXObjSync;
  boolean bRollerBenchTest = b_FALSE;


#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif 

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  if (p_ServiceFuncts != NULL)
  {
    pFCTSenSPMServiceFuncts = p_ServiceFuncts;
  }
  else
  {
    FCT_ASSERT(b_FALSE); // PRQA S 3119
    // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: function kept for reporting integrity of data
    pFCTSenSPMServiceFuncts = NULL;
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  FCTSEN_SPMRuntimeMeasInit();
#endif

  /*---------------------------------------------------------------------------*/
  /* Start SPM  System performance monitoring                                  */
  /*---------------------------------------------------------------------------*/

  /* Send RTA-Start Event for System Performance Monitor runtime */
  FCTSEN_SPM_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart, (uint8)FCTSEN_RTA_SPM, 0U);

  /* set the FrameData for Sensor */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  FCT_v_SetSenSPMFrameData(p_RequirePorts, &AlgoErrorBuffer);
#else
  FCT_v_SetSenSPMFrameData(p_RequirePorts);
#endif

  /* set process state from CtrlData - will be overwritten by other procedures */
  /* setup opmodes for subfuctions */
  FCTSen_v_SPMProcessStates(t_FCTSenSPMFrame.eSPMOpMode);

  // process request and provide ports for SPM component
  SPM_v_ProcessPorts(p_RequirePorts
                   , p_ProvidePorts
#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                   , p_ServiceFuncts
#endif
#if(FCT_CFG_USE_ALGOCOMPSTATE)
                   ,&AlgoErrorBuffer
#endif
    );

  if(   (t_FCTSenSPMFrame.eSPMState == COMP_STATE_NOT_INITIALIZED)
     || (t_FCTSenSPMFrame.eSPMState == COMP_STATE_RUNNING) )
  {
#if(FCT_CFG_USE_FREEZE_CYCLE_START && FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    if(pFCTSenSPMServiceFuncts->pfMeasStartFuncCycle != NULL)
    {
      (pFCTSenSPMServiceFuncts->pfMeasStartFuncCycle)((AS_t_MeasFuncID)(FCT_SPM_MEAS_FUNC_CHAN_ID));
    }
#endif

    /* Send RTA-Start event for PreProcessing runtime */
    FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, (uint8)SPM_RTA_PRE_PROCESS, 0U);
    /* Call PreProcessing function */
    FCTSen_v_SPMPreProcessing(p_RequirePorts, p_ProvidePorts);
    /* Send RTA-End event for PreProcessing runtime */
    FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, (uint8)SPM_RTA_PRE_PROCESS, 0U);

    /* Send RTA-Start event for Blockage process runtime */
    FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, (uint8)SPM_RTA_BLOCKAGE_PROCESS, 0U);

    /*setup different variables needed for SPM */
    // roller bench state
    #if(VDY_VEH_DYN_INTFVER == 8U)
      bRollerBenchTest = p_RequirePorts->pEgoDynRaw->Longitudinal.VeloCorr.bRollerTestBench;
    #endif
    #if(VDY_VEH_DYN_INTFVER >= VDY_VEH_DYN_INT_VER_THLD)
      bRollerBenchTest = p_RequirePorts->pEgoDynRaw->MotionState.bRollerTestBench;
    #endif

    //
    #if(VDY_VEH_DYN_INTFVER >= VDY_VEH_DYN_INT_VER_THLD)
      fEgoSpeedXObjSync = p_RequirePorts->pEgoDynObjSync->Longitudinal.Velocity;
    #else
      fEgoSpeedXObjSync = p_RequirePorts->pEgoDynObjSync->Longitudinal.MotVar.Velocity;
    #endif

    /* Call Blockage process main function */
    SPMProcess( p_RequirePorts->pPerfDegrData,
              &t_Blockage,
              &t_SelfTest,
              bRollerBenchTest,
              #if(SPM_CFG_SHORT_RANGE_SENSOR_INFO)
                p_RequirePorts->pPerfDegrExtInput->eSRDSysDamp,
              #endif
              #if( ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) && ((SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE) || (SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)) )
                p_RequirePorts->pt_ALNMonitoring,
              #endif
              fEgoSpeedXObjSync,//EGO_SPEED_X_OBJ_SYNC,
              p_RequirePorts->pEmFctCycleMode->fEmFctCycleTime,//TASK_CYCLE_TIME,
              //&p_RequirePorts->pBswAlgoParameters->Fct.Blockage  
              p_RequirePorts->pt_BSWAlgoBlockage
              );
    /* Send RTA-End event for Blockage process runtime */
    FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, (uint8)SPM_RTA_BLOCKAGE_PROCESS, 0U);

#if(FCT_CFG_USE_ALGOCOMPSTATE)
    SPM_v_SetCompState(p_ProvidePorts->pSenCompState, t_FCTSenSPMFrame.eSPMOpMode, AlgoErrorBuffer);
#endif

    /* all the processing steps are done, set init */
    t_FCTSenSPMFrame.bSPMIsInitialized = b_TRUE;
  }
  else
  {
#if((FCT_CFG_USE_FREEZE_CYCLE_START)&&(FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    if(pFCTSenSPMServiceFuncts != NULL && pFCTSenSPMServiceFuncts->pfMeasStartFuncCycle != NULL)
    {
      (pFCTSenSPMServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_SPM_MEAS_FUNC_ID))
    }
#endif

    /* Call SPM init function */
    FCTSen_v_SPMAlgoInit();
#if(FCT_CFG_USE_ALGOCOMPSTATE)
    if(p_ProvidePorts != NULL)
    {
      if(p_RequirePorts != NULL && p_RequirePorts->pSenCtrlData != NULL)
      {
        SPM_v_SetCompState(p_ProvidePorts->pSenCompState, t_FCTSenSPMFrame.eSPMOpMode, AlgoErrorBuffer);
      }
      else
      {
        SPM_v_SetCompState(p_ProvidePorts->pSenCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
      }
    }
#endif
  }
  /* Send RTA-End Event for System Performance Monitor runtime */
  FCTSEN_SPM_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd, (uint8)FCTSEN_RTA_SPM, 0U);

  /* Fill provide ports data and port headers */
  SPM_v_SetProPortsData(p_ProvidePorts, &t_Blockage, &t_SelfTest);
  SPM_v_FillProPortHeaders();

 /* Output Meas Freezes */
#if (FCT_MEASUREMENT)
  /* Process other meas freezes */
  FCTSen_v_SPMProcessMeasFreeze(p_ProvidePorts);
#endif /* FCT_MEASUREMENT */

#if (FCT_MEASUREMENT)
  /* Freeze frame meas data in all cases, even in case of Error*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Safeguard for NULL-Pointer */
  if ((p_ServiceFuncts != NULL) 
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    && (pServiceFuncts->pfMeasStartFuncCycle != NULL)
#endif
    && (p_ServiceFuncts->pfMeasFreeze != NULL)
    && (pFCTSenSPMServiceFuncts != NULL)
    && (pFCTSenSPMServiceFuncts->pfMeasFreeze != NULL) )
  {
    FCTSen_v_SPMFrameFreeze();
  }
#else
  FCTSen_v_SPMFrameFreeze();
#endif
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  _PARAM_UNUSED(p_ServiceFuncts); // PRQA S 3119
  // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: variable kept for further implementation
#endif

  _PARAM_UNUSED(t_FCTSenFrameFCTOpMode); /* PRQA S 3119 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: variable kept for further implementation*/
}

static void SPM_v_SetProPortsData(SPMProPort_t * const pProvidePorts, AlgoErrorState_t * tBlockageState, AlgoErrorState_t * tSelftestState)
{
#if (SYS_PERF_MON_OUT_INTFVER >= 3u)
  pProvidePorts->pSysPerfMonStates->uSPMSelfTestState = *(tSelftestState);
  pProvidePorts->pSysPerfMonStates->uSPMBlockageState = *(tBlockageState);
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  /* If blockage is set active or self-test not completed yet, then force sensor to
  'blocked' state effectively suppressing activation of long ctrl */
  #ifndef FCT_SIM_EXT
    if ((*(tBlockageState) == AL_ERR_STATE_ACTIVE) || (*(tSelftestState) != AL_ERR_STATE_INACTIVE))
    {
      pProvidePorts->pSPM_HC_Data->b_SensorBlocked = TRUE;
    }
    else
    {
      pProvidePorts->pSPM_HC_Data->b_SensorBlocked = FALSE;
    }
  #endif
#endif

  /* Fill error out structure with the data computed */
  FCTSen_v_SPMFillErrorOut(pProvidePorts->pErrorOut);
}


void FCTSen_v_SPMAlgoInit (void)
{
  /* reset FirstCycleDone */
  t_FCTSenSPMFrame.bFirstCycleDone   = b_FALSE;

  /* Set initialized flag to false */
  t_FCTSenSPMFrame.bSPMIsInitialized = b_FALSE; 
}

#if (FCT_CFG_ERROR_OUTPUT_SEN)
// init SPM error out structure
static void SPM_v_InitErrorOut(SPMErrorOutProPort_t * p_ErrorOut)
{
  // set version and signal status
  p_ErrorOut->uiVersionNumber = FCT_SEN_ERROR_OUT_INTFVER;
  p_ErrorOut->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  // initialize SPM events with default values
  p_ErrorOut->t_Blockage = AL_ERR_STATE_UNKNOWN;
  p_ErrorOut->t_DecreaseBlockage = AL_ERR_STATE_UNKNOWN;
  p_ErrorOut->t_IncreaseBlockage = AL_ERR_STATE_UNKNOWN;
  p_ErrorOut->t_InterferenceRange = AL_ERR_STATE_UNKNOWN;
  p_ErrorOut->t_ObjectNotMeasTmp = AL_ERR_STATE_UNKNOWN;
  p_ErrorOut->t_ObjectNotMeasured = AL_ERR_STATE_UNKNOWN;
  p_ErrorOut->t_SRDDampingState = AL_ERR_STATE_UNKNOWN;
  #if((FCT_SEN_ERROR_OUT_INTFVER >= 20U) && (SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON) && (ALGO_ARS500Sensor))
  p_ErrorOut->t_BlockageType = (uint8)SPM_BLOCKAGE_TYPE_UNKNOWN;
  p_ErrorOut->t_BlockageCategory = (uint8)SPM_BLOCKAGE_CAT_UNKNOWN;
  p_ErrorOut->t_PartialBlockageLevel = (uint8)SPM_UNKNOWN_PARTIAL_BLOCKAGE;
  #endif
  
  // initialize other error out variables with default values
  p_ErrorOut->b_RequestRoadBeam = b_FALSE;
  p_ErrorOut->u_NoOfObjLosses = 0U;
}
#endif


void FCTSen_v_SetSPMOperationMode(const SPMCompState_t t_SPMCompState)
{
  t_FCTSenSPMFrame.eSPMState = t_SPMCompState;
  SPMState = t_SPMCompState;
}


static void FCTSen_v_SPMPreProcessing(const reqFCTSenSPMPrtList_t * pRequirePorts, SPMProPort_t * const pProvidePorts)
{
  SPM_v_InitErrorOut(pProvidePorts->pErrorOut);

  switch(t_FCTSenSPMFrame.eSPMState)
  {
    case COMP_STATE_RUNNING:
      t_FCTSenSPMFrame.bFirstCycleDone = b_TRUE;
      break;

    case COMP_STATE_NOT_INITIALIZED:
      FCTSen_v_SPMAlgoInit();
      break;

    case COMP_STATE_PERMANENT_ERROR:
    case COMP_STATE_TEMPORARY_ERROR:
    default:
      FCTSen_v_SPMAlgoInit();
      break;
  }

  // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: variable kept for further implementation
  // PRQA S 3119 2
  _PARAM_UNUSED(pProvidePorts);
  _PARAM_UNUSED(pRequirePorts);
}


#ifdef RTA_INTERFACE_VERSION
#if(RTA_INTERFACE_VERSION >= 4)
  static void FCTSEN_SPM_SERVICE_ADD_EVENT( const RTA_t_Events      RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#else
  static void FCTSEN_SPM_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#endif
#else
  static void FCTSEN_SPM_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#endif
{
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  if (    (pFCTSenSPMServiceFuncts                           != NULL)
       && (pFCTSenSPMServiceFuncts->pfRTAAlgoServiceAddEvent != NULL) )
  {
    #ifdef RTA_GLOBALID_FCT_SEN
        pFCTSenSPMServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, RTA_GLOBALID_FCT_SEN, u_IdLocal, u_OptData);
    #else
        pFCTSenSPMServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT60, u_IdLocal + SPM_RTA_OFFSET, u_OptData);
    #endif
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  /* Check NULL pointer. 
  Check whether additional parameter (i.e. Object ID) is defined. This cannot be handled */
  if (    (pFCTSenSPMServiceFuncts                     != NULL)
       && (pFCTSenSPMServiceFuncts->pfGetTimestampuS32 != NULL) 
       && (u_OptData                                           == 0U   ))
  {
    FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( RtaEvtType, (sint32)u_IdLocal);
  }
#endif
  // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: variable kept for further implementation
  // PRQA S 3119 3
  _PARAM_UNUSED(RtaEvtType);
  _PARAM_UNUSED(u_IdLocal);
  _PARAM_UNUSED(u_OptData);
}

#if (FCT_CFG_RUNTIME_MEAS)
static void FCTSEN_SPMRuntimeMeasInit(void)
{
  uint32 i;
  /* Init global FCT runtime measurement array */
  for (i = 0u; i < (uint32)FCTSEN_RTA_SPM_NOF_CHECKPOINTS; i++)
  {
    t_FCTSEN_SPMRuntimeInfo.uRuntime[i] = 0u;
  }
}
#endif /* FCT_CFG_RUNTIME_MEAS */


#if (FCT_CFG_RUNTIME_MEAS)
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
 static void FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( const RTA_t_Events       t_RuntimeEvtType, const sint32 u_EventID)
#else
 static void FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
#endif
#else
 static void FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
#endif
{
  if(t_RuntimeEvtType == e_RTA_EVT_AlgoStart) 
  {
    FCT_ASSERT(t_FCTSEN_SPMRuntimeInfo.uRuntime[u_EventID] == 0u); // PRQA S 3119
    // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: function kept for checking integrity of data

    // In case of a start event, the current timestamp is stored in the array.
    t_FCTSEN_SPMRuntimeInfo.uRuntime[u_EventID] = pFCTSenSPMServiceFuncts->pfGetTimestampuS32();
  }
  else if(t_RuntimeEvtType == e_RTA_EVT_AlgoEnd)
  {
    FCT_ASSERT(t_FCTSEN_SPMRuntimeInfo.uRuntime[u_EventID] > 0u); // PRQA S 3119
    // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: function kept for checking integrity of data

    // In case of an end event, the time difference between the start and end event is stored in the array. 
    // Precondition: Valid start event must have been called before.
    t_FCTSEN_SPMRuntimeInfo.uRuntime[u_EventID] = pFCTSenSPMServiceFuncts->pfGetTimestampuS32() - t_FCTSEN_SPMRuntimeInfo.uRuntime[u_EventID];
  }
  else
  {
    /* Reset runtime info:
    if no valid event type
    if no valid start event has been called before the end event. */
    t_FCTSEN_SPMRuntimeInfo.uRuntime[u_EventID] = 0u;
    FCT_ASSERT(b_FALSE); // PRQA S 3119
    // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: function kept for checking integrity of data
  }
}
#endif /*FCT_CFG_RUNTIME_MEAS*/

// 2020-04-27, reviewer:Opreai01, Popam05, PalloI, reason: No indentation problem
static void FCT_v_SetSenSPMFrameData( const reqFCTSenSPMPrtList_t * pRequirePorts /* PRQA S 2200 */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                               , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                               ) 
{
  /* Store operation mode received from outside in sen frame for freezing */
  if ((pRequirePorts != NULL)&&(pRequirePorts->pSenCtrlData != NULL))
  {
    t_FCTSenSPMFrame.eSPMOpMode = pRequirePorts->pSenCtrlData->OpMode;
  }
  else
  {
    t_FCTSenSPMFrame.eSPMOpMode = FCT_MOD_SHUTDOWN;

    FCTSen_v_SPMSignalErrorShutdown(b_FALSE);
  }

  t_FCTSenSPMFrame.uiCycleCounter++;

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  t_FCTSenSPMFrame.Versions.uiSPM               =   SPM_VERSION;
#endif
  t_FCTSenSPMFrame.Versions.uProjectID          =   (uint32)SPM_SW_PROJ_ID;
#ifdef __PDO__
  t_FCTSenSPMFrame.Versions.SPM_VERSION_AS_TEXT  =   SPM_SW_VERSION_NUMBER;
#else
  t_FCTSenSPMFrame.Versions.SPMVersionNumVar  =   SPM_SW_VERSION_NUMBER;
#endif
  t_FCTSenSPMFrame.Versions.SPMSwVersion      =   SPM_SW_VERSION_NUMBER;
}

#if(FCT_CFG_USE_ALGOCOMPSTATE)
static void SPM_v_SetCompState(AlgoCompState_t * const pSenCompState, FCT_OP_MODE_t const scheduledOpMode, GenAlgoQualifiers_t const bufferedQualifier)
{
#ifndef MFC_VERSION_INFO_LENGTH
  #define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
#endif 
#if COMP_STATE_INTFVER > 3
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));
#else
///@cond Doxygen_Suppress
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
///@endcond
#endif

  if (pSenCompState != NULL)
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(pSenCompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pSenCompState->uiAlgoVersionNumber = ACDC_Frame.Versions.ACDCSwVersion;
#if COMP_STATE_INTFVER > 2u
    pSenCompState->uiApplicationNumber = 0u;
    pSenCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pSenCompState->ApplicationNumber = 0u;
    pSenCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    
    switch (t_FCTSenSPMFrame.eSPMState)
    {
    case COMP_STATE_NOT_INITIALIZED:
      if (scheduledOpMode != FCT_MOD_RUNNING)
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
        if (bufferedQualifier != ALGO_QUAL_OK)
        {
          pSenCompState->eGenAlgoQualifier = bufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case COMP_STATE_RUNNING:
      /*everything's fine*/
      pSenCompState->eCompState = COMP_STATE_RUNNING;
      pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pSenCompState->eGenAlgoQualifier = bufferedQualifier;
      break;
    case COMP_STATE_NOT_RUNNING:
      if (scheduledOpMode != FCT_MOD_RUNNING)
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
        if (bufferedQualifier != ALGO_QUAL_OK)
        {
          pSenCompState->eGenAlgoQualifier = bufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case COMP_STATE_TEMPORARY_ERROR:
      /*triggered with input interface errors*/
    default:
      pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
      pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
      if (bufferedQualifier != ALGO_QUAL_OK)
      {
        pSenCompState->eGenAlgoQualifier = bufferedQualifier; /*buffer is filled, put Qualifier*/
      }
      else
      {
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
      }
      break;
    }
  }
}
#endif
#endif/*!< FCT_CFG_SIGNAL_PERF_MONITORING */

#endif // SPM_SRR_TECHNOLOGY
