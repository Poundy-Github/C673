/*****************************************************************************
  INCLUDES#
*****************************************************************************/
#include "spm_int.h" /* PRQA S 0380 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: multiple header files inherited according to include strategy */
#include "spm_par.h"


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if(FCT_CFG_SIGNAL_PERF_MONITORING)
/*****************************************************************************
  MACROS
*****************************************************************************/

#define SPM_SET_REQPORT_HANDLER(pREQPORT, pGLOBAL, pSYNCREF, pREQPORTS, pHANDLERLIST)                              \
  do{                                                                                                              \
      SPMReqPortHandler_t * pCurrentReqHandler = &((pHANDLERLIST)->ReqPortHandler[(pHANDLERLIST)->uNoOfReqPorts]); \
      (pCurrentReqHandler)->ppGlobal = (void const **)&(pGLOBAL);                                                  \
      (pCurrentReqHandler)->pReqSigHeaderSyncRef = (pSYNCREF);                                                     \
      if( ((pREQPORTS) != NULL) && ((pREQPORT) != NULL) )                                                          \
      {                                                                                                            \
        (pCurrentReqHandler)->uSize = sizeof(*(pREQPORT));                                                         \
        (pCurrentReqHandler)->pReqPort = (const void *)(pREQPORT);                                                 \
        (pCurrentReqHandler)->pReqPortSigHeader = &((pREQPORT)->sSigHeader);                                       \
      }                                                                                                            \
      (pHANDLERLIST)->uNoOfReqPorts++;                                                                             \
    }while(0) /* PRQA S 3456 */ /* 2020-04-27, reviewer:Opreai01, Popam05, Palloi, reason: not safety critical*/

#define SPM_SET_REQPORT_HANDLER_NO_HEADER(pREQPORT, pGLOBAL, pSYNCREF, pREQPORTS, pHANDLERLIST)                    \
  do{                                                                                                              \
      SPMReqPortHandler_t * const pCurrentReqHandler = &((pHANDLERLIST)->ReqPortHandler[(pHANDLERLIST)->uNoOfReqPorts]); \
      (pCurrentReqHandler)->ppGlobal = (void const **)&(pGLOBAL);                                                  \
      (pCurrentReqHandler)->pReqSigHeaderSyncRef = (pSYNCREF);                                                     \
      if( ((pREQPORTS) != NULL) && ((pREQPORT) != NULL) )                                                          \
      {                                                                                                            \
        (pCurrentReqHandler)->uSize = sizeof(*(pREQPORT));                                                         \
        (pCurrentReqHandler)->pReqPort = (const void *)(pREQPORT);                                                 \
        (pCurrentReqHandler)->pReqPortSigHeader = NULL;                                                            \
      }                                                                                                            \
      (pHANDLERLIST)->uNoOfReqPorts++;                                                                             \
    }while(0) /* PRQA S 3456 */ /* 2020-04-27, reviewer:Opreai01, Popam05, Palloi, reason: not safety critical*/

#define SPM_SET_PROPORT_HANDLER(pPROPORT, pREQPORT, pGLOBAL, pCOMPSTATE, uVERNUMBER, uFREEZEADDRESS, pREQPORTS, pPROPORTS, pHANDLERLIST) \
  do{                                                                                                                  \
      SPMProPortHandler_t * pCurrentProHandler = &((pHANDLERLIST)->ProPortHandler[(pHANDLERLIST)->uNoOfProPorts]);     \
      (pCurrentProHandler)->ppGlobal = (void**)&(pGLOBAL);                                                             \
      (pCurrentProHandler)->pProNewSigState = (pCOMPSTATE);                                                            \
      (pCurrentProHandler)->uPorNewVersionNumber = (uVERNUMBER);                                                       \
      (pCurrentProHandler)->uMeasFreezeAddress = (uFREEZEADDRESS);                                                     \
      if(((pREQPORTS) != NULL) && ((pREQPORT) != NULL))                                                                \
      {                                                                                                                \
        (pCurrentProHandler)->pReqPortSigHeader = &((pREQPORT)->sSigHeader);                                           \
      }                                                                                                                \
      if(((pPROPORTS) != NULL) && ((pPROPORT) != NULL))                                                                \
      {                                                                                                                \
        (pCurrentProHandler)->uSize = sizeof(*(pPROPORT));                                                             \
        (pCurrentProHandler)->pProPort = (void*)(pPROPORT);                                                            \
        (pCurrentProHandler)->pProVersionNumber = (uint32*)&((pPROPORT)->uiVersionNumber);                             \
        (pCurrentProHandler)->pProPortSigHeader = &((pPROPORT)->sSigHeader);                                           \
      }                                                                                                                \
      (pHANDLERLIST)->uNoOfProPorts++;                                                                                 \
    }while(0) /* PRQA S 3456 */ /* 2020-04-27, reviewer:Opreai01, Popam05, Palloi, reason: not safety critical*/



/*****************************************************************************
  FUNCTIONS DEFINITIONS
*****************************************************************************/
void SPM_v_InitPortHandlerList(boolean bKeepMeasDataCycle)
{
  SPMPortHandlerList_t * pPortHandlerList = &SPMPortHandlerList;
  uint8 uPortNo;
  pPortHandlerList->uNoOfProPorts = 0u;
  pPortHandlerList->uNoOfReqPorts = 0u;

  /* set request ports data to default values */
  for(uPortNo = 0u; uPortNo < SPM_NO_OF_REQ_PORTS; uPortNo++) /* PRQA S 4548, 4304 */ /* 2020-04-27, reviewer:Opreai01, Popam05, reason: logical operations based on configuration switches*/
  {
    pPortHandlerList->ReqPortHandler[uPortNo].ppGlobal             = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqPort             = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqPortSigHeader    = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqSigHeaderSyncRef = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].uSize                =   0U;
    /*Reset MeasCycle in case of an external init. Otherwise keep MeasCycle data.*/
    if(bKeepMeasDataCycle == b_FALSE)
    {
      pPortHandlerList->ReqPortHandler[uPortNo].MeasCycleMonitor.uiLastUpdateCounter = 0u;
      pPortHandlerList->ReqPortHandler[uPortNo].MeasCycleMonitor.uiTimeStamp         = 0u;
    }
  }

  for(uPortNo = 0u; uPortNo< SPM_NO_OF_PRO_PORTS; uPortNo++) /* PRQA S 4548, 4304 */ /* 2020-04-27, reviewer:Opreai01, Popam05, reason: logical operations based on configuration switches */
  {
    pPortHandlerList->ProPortHandler[uPortNo].ppGlobal             = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProNewSigState      = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProPort             = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProPortSigHeader    = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pReqPortSigHeader    = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProVersionNumber    = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].uMeasFreezeAddress   =   0u;
    pPortHandlerList->ProPortHandler[uPortNo].uPorNewVersionNumber =   0u;
    pPortHandlerList->ProPortHandler[uPortNo].uSize                =   0u;
  }
}

static void SPM_v_SetSigHeader(SignalHeader_t * const pDestSigHeader, SignalHeader_t const * const pSourceSigHeader, AlgoSignalState_t eSigState)
{
  pDestSigHeader->uiTimeStamp = pSourceSigHeader->uiTimeStamp;
  pDestSigHeader->uiMeasurementCounter = pSourceSigHeader->uiMeasurementCounter;
  pDestSigHeader->uiCycleCounter = t_FCTSenSPMFrame.uiCycleCounter;
  pDestSigHeader->eSigStatus = eSigState;
}

static void SPM_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiTimeStamp = 0u;
  pSigHeader->uiMeasurementCounter = 0u;
  pSigHeader->uiCycleCounter = t_FCTSenSPMFrame.uiCycleCounter;
  pSigHeader->eSigStatus = AL_SIG_STATE_INVALID;
}

#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
static boolean SPM_b_CheckServiceFunctions(const AS_t_ServiceFuncts * pServiceFuncts)
{
  boolean bError = b_FALSE;

  if(pServiceFuncts != NULL)
  {
    if(pServiceFuncts->pfMeasFreeze == NULL)
    {
      bError = b_TRUE;
    }
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    if(pServiceFuncts->pfMeasStartFuncCycle == NULL)
    {
      bError = b_TRUE;
    }
#endif
#if (FCT_CFG_RTA_PROFILING)
    if(pServiceFuncts->pfRTAAlgoServiceAddEvent == NULL)
    {
      bError = b_TRUE;
    }
#endif
  }
  else
  {
    bError = b_TRUE;
  }

  return bError;
}
#endif

static boolean SPM_b_CheckPortUpdate(AlgoDataTimeStamp_t const * const pInputPortMeasCycle, sMeasCycleMonitor * const pLastMeasCycle, 
                                    float32 const fTargetCycleTime, uint8 uAcceptableDrops)
{
  boolean bError = b_FALSE;
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0U;
  AlgoDataTimeStamp_t uiMaximumTimestamp = ~((AlgoDataTimeStamp_t)0);  // set maximum value based of the type of AlgoDataTimeStamp_t. Example: uint32, unsigned long,...

  /* PRQA S 4119, 4395 4 */
  // 2020-03-17, reviewer:Opreai01, OlaruM, PalloI, reason: Low data lost when casting from float to integral type
  const AlgoDataTimeStamp_t uiRecievedCyclesTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * SPM_TIMESTAMP_TO_MICROSECONDS);
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)(((float32)uAcceptableDrops + 1.5F) * (float32)uiRecievedCyclesTimeUs);
  const AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_SEN_CYCLE_TIME * SPM_TIMESTAMP_TO_MICROSECONDS);

  if(*pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp)
  {
    /*overflow*/
    uiDeltaTimeUs = (uiMaximumTimestamp - pLastMeasCycle->uiTimeStamp) + *pInputPortMeasCycle;
  }
  else
  {
    /*no overflow*/
    uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
  }

  if(uiDeltaTimeUs == 0u)
  {
    /*no update*/
    if( (((uint32)pLastMeasCycle->uiLastUpdateCounter + 1u) * uiTargetCycleTimeCallUs < uiMaxAcceptableDropTimeUs) )
    {
      /* max time not reached => no upate expected */
      pLastMeasCycle->uiLastUpdateCounter += 1u;
    }
    else
    {
      /*update expected => rise error*/
      bError = b_TRUE;
    }
  }
  else
  {
    /*update*/
    if(uiDeltaTimeUs > uiMaxAcceptableDropTimeUs)
    {
      /* cycle was skipped => rise error*/
      bError = b_TRUE;
    }
    else
    {
      /*new cycle recieved in time => reset update counter*/
      pLastMeasCycle->uiLastUpdateCounter = 0u;
    }
    pLastMeasCycle->uiTimeStamp = *pInputPortMeasCycle;
  }

  return bError;
}

static boolean SPM_b_SetupPorts(SPMPortHandlerList_t * pPortHandlerList)
{
  boolean bError = b_FALSE;
  boolean bSigHeaderError = b_FALSE;
  uint8 uPortNo = 0U;
  // date: 2020-04-27, reviewer: Palloi,Popam05, Opreai01, reason:safe as values of operand involved in logical operation is either zero or one
  /* PRQA S 4304, 4548 2 */
  uint8 uDefNoOfReqPorts = SPM_NO_OF_REQ_PORTS;
  uint8 uDefNoOfProPorts = SPM_NO_OF_PRO_PORTS;
  uint8 uNoOfReqPorts = CML_Min(pPortHandlerList->uNoOfReqPorts, uDefNoOfReqPorts);
  uint8 uNoOfProPorts = CML_Min(pPortHandlerList->uNoOfProPorts, uDefNoOfProPorts);
  SPMReqPortHandler_t * pCurrentReqPort;
  SPMProPortHandler_t * pCurrentProPort;

  if(pPortHandlerList->uNoOfReqPorts != SPM_NO_OF_REQ_PORTS)/* PRQA S 4304, 4548 */
  {
    bError = b_TRUE;
  }
  if(pPortHandlerList->uNoOfProPorts != SPM_NO_OF_PRO_PORTS)/* PRQA S 4304, 4548 */
  {
    bError = b_TRUE;
  }

  for(uPortNo = 0U; uPortNo < uNoOfReqPorts; ++uPortNo)
  {
    pCurrentReqPort = &(pPortHandlerList->ReqPortHandler[uPortNo]);
    if(pCurrentReqPort->pReqPort != NULL)
    {
      *(pCurrentReqPort->ppGlobal) = pCurrentReqPort->pReqPort;

      if(pCurrentReqPort->pReqPortSigHeader != NULL)
      {
        *(pCurrentReqPort->pReqSigHeaderSyncRef) = *(pCurrentReqPort->pReqPortSigHeader);
        // date: 2020-04-27, reviewer: Palloi,Popam05, Opreai01, reason:safe as values of operand involved in logical operation is either zero or one
        /* PRQA S 4304,4430,4502 2 */
        bSigHeaderError |= (boolean)(pCurrentReqPort->pReqPortSigHeader->eSigStatus == AL_SIG_STATE_INVALID);
        bSigHeaderError |= SPM_b_CheckPortUpdate(&(pCurrentReqPort->pReqPortSigHeader->uiTimeStamp),
                                                 &(pCurrentReqPort->MeasCycleMonitor),
                                                 FCT_SEN_CYCLE_TIME, SPM_INPUT_ACCEPTABLE_DROPS);
      }
      else
      {
        SPM_v_SetSigHeaderError(pCurrentReqPort->pReqSigHeaderSyncRef);
      }
    }
    else
    {
      SPM_v_SetSigHeaderError(pCurrentReqPort->pReqSigHeaderSyncRef);
      *(pCurrentReqPort->ppGlobal) = NULL;
      bError = b_TRUE;
    }
  }

  for(uPortNo = 0U; uPortNo < uNoOfProPorts; ++uPortNo)
  {
    pCurrentProPort = &(pPortHandlerList->ProPortHandler[uPortNo]);
    if(pCurrentProPort->pProPort != NULL)
    {
      *(pCurrentProPort->ppGlobal) = pCurrentProPort->pProPort;
    }
    else
    {
      *(pCurrentProPort->ppGlobal) = NULL;
      bError = b_TRUE;
    }
  }

#if(FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
  bError |= bSigHeaderError;
#endif

  return bError;
}

static boolean SPM_b_PortSpecificHandling(const reqFCTSenSPMPrtList_t * pRequirePorts, const SPMProPort_t * pProvidePorts)
{
  boolean bError = b_FALSE;

  if(pRequirePorts != NULL)
  {
    if(pRequirePorts->pPerfDegrData != NULL)
    {
      if(pRequirePorts->pPerfDegrData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      {
        FCTSen_v_SPMSignalErrorShutdown(b_FALSE);
      }
    }
    if(pRequirePorts->pSenCtrlData != NULL)
    {
      SPM_v_SetSigHeader(&(t_FCTSenSPMSyncRef.sSigHeader), &(pRequirePorts->pSenCtrlData->sSigHeader), pRequirePorts->pSenCtrlData->sSigHeader.eSigStatus);
    }
    else
    {
      SPM_v_SetSigHeaderError(&(t_FCTSenSPMSyncRef.sSigHeader));
    }
  }

  _PARAM_UNUSED(pProvidePorts);/* PRQA S 3119 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: possible usage in the future */

  return bError;
}

extern void SPM_v_ProcessPorts( reqFCTSenSPMPrtList_t const * const pRequestPorts,
                                SPMProPort_t          const * const pProvidePorts
#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                , AS_t_ServiceFuncts  const * const pServiceFuncts
#endif
#if(FCT_CFG_USE_ALGOCOMPSTATE)
                                , GenAlgoQualifiers_t       * const pErrorBuffer
#endif
                                )
{
  SPMPortHandlerList_t * pPortHandlerList = &SPMPortHandlerList;
  boolean bError = b_FALSE;

  /* Initialize SPM Port Handler list */
  SPM_v_InitPortHandlerList(b_TRUE);

  /* Evaluate and setup request ports */
  SPM_v_SetupReqPortHandlers(pRequestPorts, pPortHandlerList);

  /* Evaluate and setup provide ports */
  SPM_v_SetupProPortHandlers(pProvidePorts, pRequestPorts, pPortHandlerList);

#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  if(SPM_b_CheckServiceFunctions(pServiceFuncts) == b_TRUE)
  {
    bError = b_TRUE;
  }
#endif

  if(SPM_b_SetupPorts(pPortHandlerList) == b_TRUE)
  {
    bError = b_TRUE;
  }
  if(SPM_b_PortSpecificHandling(pRequestPorts, pProvidePorts) == b_TRUE)
  {
    bError = b_TRUE;
  }

  if(bError == b_TRUE)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    SPM_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif

    FCTSen_v_SPMSignalErrorShutdown(b_FALSE);
  }
}

static void SPM_v_SetupReqPortHandlers(reqFCTSenSPMPrtList_t const * const pRequirePorts, SPMPortHandlerList_t * const pPortHandlerList)
{
  /*PRQA S 0314, 0310 35 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: Cast to void is intended as to allow generic port handling   */
/*SPM_SET_REQPORT_HANDLER|             reqPort             |      Global pointer      |            SyncRef pointer             | Require ports| Port Handler List|*/
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pEgoDynRaw        , FCTSEN_pSPMEgoDynRaw        , &(t_FCTSenSPMSyncRef.EgoDynRaw)        , pRequirePorts, pPortHandlerList);
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pSenCtrlData      , pSPMCtrlData                , &(t_FCTSenSPMSyncRef.SenCtrlData)      , pRequirePorts, pPortHandlerList);
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pEgoDynObjSync    , pSPMEgoDynObjSync           , &(t_FCTSenSPMSyncRef.EgoDynObjSync)    , pRequirePorts, pPortHandlerList);
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pFctVehLongOut,     pFctVehLongOut,     &(t_FCTSenSPMSyncRef.FctVehLongOut)              , pRequirePorts, pPortHandlerList);
#endif
#if((FCT_CFG_OBJECT_LIST_PROC)&&(FCT_USE_EM_GENERIC_OBJECT_LIST))
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pEmGenObjList   , FCTSEN_pSPMEmGenObjList       , &(t_FCTSenSPMSyncRef.EmGenObjList)     , pRequirePorts, pPortHandlerList);
#endif
#if((FCT_CFG_OBJECT_LIST_PROC)&&(FCT_USE_EM_GENERIC_OBJECT_LIST)&&(FCT_USE_EM_ARS_TECH_OBJECT_LIST))
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pEmARSObjList   , FCTSEN_pSPMEmARSObjList       , &(t_FCTSenSPMSyncRef.EmARSObjList)     , pRequirePorts, pPortHandlerList);
#else
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pPubEmObj       , FCTSEN_pSPMEmObjList          , &(t_FCTSenSPMSyncRef.PubEmObj)         , pRequirePorts, pPortHandlerList);
#endif
#if(FCT_CFG_SIGNAL_PERF_MONITORING)
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pPerfDegrData   , FCTSEN_pSPMPerfDegrData       , &(t_FCTSenSPMSyncRef.PerfDegrData)     , pRequirePorts, pPortHandlerList);
#endif
#if((FCT_CFG_OBJECT_LIST_PROC)&&(FCT_CFG_ASSESSED_OBJ_OUT_INTF))
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pPubFctObj      , FCTSEN_pSPMPubFctObj          , &(t_FCTSenSPMSyncRef.PubFctObj)        , pRequirePorts, pPortHandlerList);
#endif
#if(FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pSLATE_SPM_Data , FCTSEN_pSLATE_SPM_Data       , &(t_FCTSenSPMSyncRef.SlateData)         , pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pPerfDegrExtInput ,   pSPMPerfDegrExtInput     , &(t_FCTSenSPMSyncRef.PerfDegrExtInput)  , pRequirePorts, pPortHandlerList);
#endif
#if((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SPM_SET_REQPORT_HANDLER(pRequirePorts->pt_ALNMonitoring ,               pALNMonitoring, &(t_FCTSenSPMSyncRef.ALNMonitoring)     , pRequirePorts, pPortHandlerList);
#endif

  SPM_SET_REQPORT_HANDLER_NO_HEADER(pRequirePorts->pt_BSWAlgoBlockage, pSPMBswAlgoParameters, &(t_FCTSenSPMSyncRef.BswAlgoParameters), pRequirePorts, pPortHandlerList);
#if(FCT_CFG_EM_FCT_CYCLEMODE)
  SPM_SET_REQPORT_HANDLER_NO_HEADER(pRequirePorts->pEmFctCycleMode, FCTSEN_pSPMEmFctCycleMode, &(t_FCTSenSPMSyncRef.EmFctCycleMode)  , pRequirePorts, pPortHandlerList);
#endif

} /*PRQA S 7002, 7004 */ /*2020-04-27, reviewer:Opreai01, Popam05, PalloI, reason: Cyclomatic complexity is to high   */

static void SPM_v_SetupProPortHandlers(SPMProPort_t const * const pProvidePorts, reqFCTSenSPMPrtList_t const * const pRequirePorts, SPMPortHandlerList_t * const pPortHandlerList)
{
  /*PRQA S 0314, 0310 15 */ /*2019-05-29, reviewer:Opreai01, Popam05, reason: Cast to void is intended as to allow generic port handling   */
  SPM_SET_PROPORT_HANDLER(pProvidePorts->pErrorOut, pRequirePorts->pPerfDegrData, SPM_pErrorOut, &SPMState, FCT_SEN_ERROR_OUT_INTFVER, FCT_MEAS_ID_SEN_ERROR_OUT_VADDR, pRequirePorts,                           pProvidePorts, pPortHandlerList);
#if (SYS_PERF_MON_OUT_INTFVER >= 3u)
  #if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
    #if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      SPM_SET_PROPORT_HANDLER(pProvidePorts->pSysPerfMonStates, pRequirePorts->pEmGenObjList, pSPMSysPerfMonStates, &SPMState, FCT_SEN_ERROR_OUT_INTFVER,                                                              FCT_MEAS_ID_SEN_ERROR_OUT_VADDR, pRequirePorts, pProvidePorts, pPortHandlerList);
    #endif
  #endif
#endif

#if(FCT_CFG_LOHP_COMPONENT)
  SPM_SET_PROPORT_HANDLER(pProvidePorts->pSPM_HC_Data, pRequirePorts->pEmGenObjList, pSPMHCData, &SPMState, FCT_SEN_ERROR_OUT_INTFVER, FCT_MEAS_ID_SEN_ERROR_OUT_VADDR, pRequirePorts,                             pProvidePorts, pPortHandlerList);
#endif
}


extern void SPM_v_FillProPortHeaders(void)
{
  uint8 uPortNo = 0U;
  AlgoSignalState_t tNewSigState = AL_SIG_STATE_INVALID;
  SPMPortHandlerList_t * pPortHandlerList = &SPMPortHandlerList;
  SPMProPortHandler_t * pCurrentPort;

  for(uPortNo = 0U; (uPortNo < pPortHandlerList->uNoOfProPorts); ++ uPortNo)
  {
    pCurrentPort = &(pPortHandlerList->ProPortHandler[uPortNo]);
    if(pCurrentPort->pProPort != NULL)
    {
      if(pCurrentPort->pProVersionNumber != NULL)
      {
        *(pCurrentPort->pProVersionNumber) = pCurrentPort->uPorNewVersionNumber;
      }
      if(  (pCurrentPort->pReqPortSigHeader != NULL)
        && (pCurrentPort->pProNewSigState != NULL)
        )
      {
        switch(*(pCurrentPort->pProNewSigState))
        {
          case COMP_STATE_PERMANENT_ERROR:
          case COMP_STATE_TEMPORARY_ERROR:
          case COMP_STATE_REDUCED_AVAILABILITY:
            tNewSigState = AL_SIG_STATE_INVALID;
            break;

          case COMP_STATE_NOT_INITIALIZED:
          case COMP_STATE_NOT_RUNNING:
            tNewSigState = AL_SIG_STATE_INIT;
            break;

          case COMP_STATE_RUNNING:
          case COMP_STATE_SUCCESS:
            tNewSigState = pCurrentPort->pReqPortSigHeader->eSigStatus;
            break;

          default:
            tNewSigState = AL_SIG_STATE_INVALID;
            break;
        }
        SPM_v_SetSigHeader(pCurrentPort->pProPortSigHeader,
                           pCurrentPort->pReqPortSigHeader,
                           tNewSigState);
      }
      else
      {
        SPM_v_SetSigHeaderError(pCurrentPort->pProPortSigHeader);
      }
      if(  (t_FCTSenSPMFrame.eSPMState == COMP_STATE_NOT_INITIALIZED)
        && (pCurrentPort->pProPortSigHeader->eSigStatus != AL_SIG_STATE_INVALID))
      {
        pCurrentPort->pProPortSigHeader->eSigStatus = AL_SIG_STATE_INIT;
      }
      else
      {
        if(t_FCTSenSPMFrame.eSPMState != COMP_STATE_RUNNING)
        {
          pCurrentPort->pProPortSigHeader->eSigStatus = AL_SIG_STATE_INVALID;
        }
      }
    }
    else
    {
      FCT_ASSERT(b_FALSE); // PRQA S 3119
      // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: function kept for checking integrity of data
    }
  }
}
#endif /*FCT_CFG_SIGNAL_PERF_MONITORING*/
#endif /*SPM_SRR_TECHNOLOGY*/
