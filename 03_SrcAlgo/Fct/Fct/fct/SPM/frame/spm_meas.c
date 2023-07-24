/*! \file **********************************************************************
// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.11 $

---*/ /*---
CHANGES:                   $Log: spm_meas.c  $
CHANGES:                   Revision 1.11 2021/02/15 17:05:02CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add pragma for FCT_SPM_FREEZE_DATA
CHANGES:                   Revision 1.10 2020/06/25 08:07:21CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.9 2019/05/29 10:49:09CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add suppress message
CHANGES:                   Revision 1.8 2019/05/28 07:26:30CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.7 2018/09/24 15:12:32CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.6 2018/03/09 09:00:57CET Pallo, Istvan (palloi) 
CHANGES:                   Define error out and HC data meas info and freeze data structures
CHANGES:                   Revision 1.5 2018/02/27 17:11:57CET Pallo, Istvan (palloi) 
CHANGES:                   Remove address defines and PDO comments
CHANGES:                   Revision 1.4 2018/02/27 11:52:09CET Pallo, Istvan (palloi) 
CHANGES:                   Remove string library include.
CHANGES:                   Revision 1.3 2017/12/05 18:49:19CET Pallo, Istvan (palloi) 
CHANGES:                   Add pdo guard for string include.
CHANGES:                   Update function header with new SPM ports naming.
CHANGES:                   Revision 1.2 2017/06/21 09:40:07CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove functions headers. 
CHANGES:                   Remove function declaration.
CHANGES:                   Revision 1.1 2017/03/17 13:16:58CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

**************************************************************************** */



/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "spm_main.h" /* PRQA S 0380 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: multiple header files inherited according to include strategy */


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)
/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @cond Doxygen_Suppress */
/* Freeze job uses application buffer  -> referenced data has to be kept global or static */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Ungvary date: 24-09-2012 reason: function-like macro reduces pre-processor branching in code */
//#define MEAS_FREEZE_SPM_BUFFERED(VADDR_,ADDR_,SIZE_) /*lint -e{717} */ do  { \ /* maybe to be activated again */
//  MEASInfo_t desc; 
//  desc.VirtualAddress = (VADDR_);                 
//  desc.Length         = (SIZE_);                  
//  desc.FuncID         = FCT_SPM_MEAS_FUNC_ID;       
//  desc.FuncChannelID  = FCT_SPM_MEAS_FUNC_CHAN_ID;  
//  (void) FCT_SPM_FREEZE_DATA(&desc,(void *)(ADDR_),&FCTSen_v_SPMMeasCallback); 
//} while(0) /* (no trailing ; ) */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if (FCT_MEASUREMENT)

/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*input ports*/

/*output ports*/
//#if (FCT_CFG_USE_BUS_DEBUG) // to be removed (not active in VACC)
//SET_MEMSEC_VAR(FCTSen_FreezeBufferBusDebugData)
//  static BusDebugData_t FCTSen_FreezeBufferBusDebugData; /*!< BusDebugData_t freeze data */
//#endif /* FCT_CFG_USE_BUS_DEBUG */
#if (FCT_SEN_CFG_FREEZE_CTRL_DATA) /* to be clarified */
SET_MEMSEC_VAR(FCTSen_SPMFreezeBufferSenCtrlData)
static FCTCtrlData_t FCTSen_SPMFreezeBufferSenCtrlData;
#endif

#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#endif  /* #if (FCT_MEASUREMENT) */


/*****************************************************************************
  VARIABLES
*****************************************************************************/
/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*input ports*/

/*output ports*/
#if (FCT_CFG_USE_ALGOCOMPSTATE) /* to be clarified */
SET_MEMSEC_VAR(FCTSen_SPMFreezeBufferSenCompState)
static AlgoCompState_t FCTSen_SPMFreezeBufferSenCompState;
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
/****************   Eof Buffers for MeasFreezes *******************/
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#if (FCT_CFG_USE_ALGOCOMPSTATE) /* to be clarified */
/* only for PDO tagging */
typedef AlgoCompState_t pSenSPMCompState;
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*! @endcond Doxygen_Suppress */
/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (FCT_MEASUREMENT)
static void FCTSenSPMFreezeInput(void) 
{
#if (FCT_SEN_CFG_FREEZE_CTRL_DATA) /* to be clarified */
  static const MEASInfo_t FCT_SenSPMCtrlMeasInfo = {           
      FCT_MEAS_ID_SEN_SPM_CTRL_DATA,   /* VirtualAddress */
      sizeof(FCTCtrlData_t),        /* Length */
      FCT_SPM_MEAS_FUNC_ID,             /* FuncID */
      FCT_SPM_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA) /* to be clarified */
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&FCTSen_SPMFreezeBufferSenCtrlData,FCTSEN_pSPMSenCtrlData,sizeof(FCTCtrlData_t));
  (void)FCT_SPM_FREEZE_DATA(&FCT_SenSPMCtrlMeasInfo, &FCTSen_SPMFreezeBufferSenCtrlData, &FCTSen_v_SPMMeasCallback);
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)FCT_SPM_FREEZE_DATA(&FCT_SenSPMCtrlMeasInfo, FCTSEN_pSPMSenCtrlData, NULL);
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif /*FCT_SEN_CFG_FREEZE_CTRL_DATA*/
}
#endif


#if (FCT_MEASUREMENT)
void FCTSen_v_SPMFrameFreeze(void)
{
  static const MEASInfo_t FCT_SenSPMFrameMeasInfo = {
      FCT_MEAS_ID_SEN_SPM_FRAME_DATA,   /* VirtualAddress */
      sizeof(FCTSenSPMFrame_t),        /* Length */
      FCT_SPM_MEAS_FUNC_ID,             /* FuncID */
      FCT_SPM_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
  static const MEASInfo_t FCT_SenSPMSyncRefMeasInfo = {
      FCT_MEAS_ID_SEN_SPM_INPUT_SIGHEADERS,   /* VirtualAddress */
      sizeof(FCTSen_SPMSyncRef_t),        /* Length */
      FCT_SPM_MEAS_FUNC_ID,             /* FuncID */
      FCT_SPM_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };

#if (FCT_CFG_USE_ALGOCOMPSTATE) /* to be clarified */
  static const MEASInfo_t FCT_Sen_SPMCompStateMeasInfo = {
    FCT_MEAS_ID_SEN_SPM_COMP_STATE,   /* VirtualAddress */
    sizeof(AlgoCompState_t),          /* Length */
    FCT_SPM_MEAS_FUNC_ID,                 /* FuncID */
    FCT_SPM_MEAS_FUNC_CHAN_ID             /* FuncChannelID */
  };
#endif

  // 2020-02-10, reviewer:Opreai01, Popam05,Palloi reason: Pointer is a generic type
  // PRQA S 0315 3
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)FCT_SPM_FREEZE_DATA(&FCT_SenSPMFrameMeasInfo, &t_FCTSenSPMFrame, &FCTSen_v_SPMMeasCallback);
  (void)FCT_SPM_FREEZE_DATA(&FCT_SenSPMSyncRefMeasInfo, &t_FCTSenSPMSyncRef, &FCTSen_v_SPMMeasCallback);
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)FCT_SPM_FREEZE_DATA(&FCT_SenSPMFrameMeasInfo, &t_FCTSenSPMFrame, NULL);
  (void)FCT_SPM_FREEZE_DATA(&FCT_SenSPMSyncRefMeasInfo, &t_FCTSenSPMSyncRef, NULL);
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#if (FCT_CFG_USE_ALGOCOMPSTATE) /* to be clarified */
  if (FCTSEN_pSPMSenCompState != NULL)
  {
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
    (void)memcpy(&FCTSen_SPMFreezeBufferSenCompState, FCTSEN_pSPMSenCompState, sizeof(AlgoCompState_t));
    (void)FCT_SPM_FREEZE_DATA(&FCT_Sen_SPMCompStateMeasInfo, &FCTSen_SPMFreezeBufferSenCompState, &FCTSen_v_SPMMeasCallback);
#else
    /* Freeze Sensor Algo Comp State (internal storage -> no need for buffering*/
    (void)FCT_SPM_FREEZE_DATA(&FCT_Sen_SPMCompStateMeasInfo, (void*) FCTSEN_pSPMSenCompState, &FCTSen_v_SPMMeasCallback);
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
}
#endif  /* #if FCT_MEASUREMENT */


void FCTSen_v_SPMProcessMeasFreeze(SPMProPort_t * const pProvidePorts)
{
#if(FCT_CFG_ERROR_OUTPUT_SEN)
  static const MEASInfo_t SPMErrorOutPortMeasInfo = 
  {
    SPM_MEAS_ID_ERROR_OUT_PORT,
    sizeof(SPMErrorOutProPort_t),
    FCT_SPM_MEAS_FUNC_ID,
    FCT_SPM_MEAS_FUNC_CHAN_ID
  };
#endif

#if(FCT_CFG_LOHP_COMPONENT)
    static const MEASInfo_t SPMHcDataMeasInfo = 
  {
    SPM_MEAS_ID_HC_DATA_PORT,
    sizeof(SPM_HC_Data_t), 
    FCT_SPM_MEAS_FUNC_ID,
    FCT_SPM_MEAS_FUNC_CHAN_ID
  };
#endif

  // Freeze SPM provide ports
  // 2020-02-10, reviewer:Opreai01, Popam05,Palloi reason: Pointer is a generic type
  // PRQA S 0315 2
#if(FCT_CFG_ERROR_OUTPUT_SEN)
  (void)FCT_SPM_FREEZE_DATA(&SPMErrorOutPortMeasInfo, pProvidePorts->pErrorOut, NULL);
#endif
#if(FCT_CFG_LOHP_COMPONENT)
    (void)FCT_SPM_FREEZE_DATA(&SPMHcDataMeasInfo, pProvidePorts->pSPM_HC_Data, NULL);
#endif

  /*******************/
  /* INPUT-Port-Data */
  /*******************/
#if (FCT_MEASUREMENT)
  FCTSenSPMFreezeInput(); /* PRQA S 2987 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: inside code under config switch */
#endif

  /**********************/
  /* OUTPUT PORT-Data   */
  /**********************/
  //FCTMeasFreezeFCTOutput();  // to be split up after output split up (ACC-SPM)


#if (FCT_MEASUREMENT)

//#if (FCT_CFG_ERROR_OUTPUT_SEN)
//  (void)FCT_SPM_FREEZE_DATA(&FCT_SenErrorsMeasInfo, (void*)pProvidePorts->pErrorOut, NULL);
//#endif

//#if (FCT_CFG_USE_BUS_DEBUG)
//#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
//    (void)memcpy(&FCTSen_FreezeBufferBusDebugData, FCTSEN_pBusDebugData, sizeof(BusDebugData_t));
//    (void)FCT_SPM_FREEZE_DATA(&FCT_Sen_BusDebugInfo, &FCTSen_FreezeBufferBusDebugData, &FCTSen_v_SPMMeasCallback);
//#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
//    (void)FCT_SPM_FREEZE_DATA(&FCT_Sen_BusDebugInfo, FCTSEN_pBusDebugData, NULL);
//#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
//#endif /*FCT_CFG_USE_BUS_DEBUG*/

#endif /* #if (FCT_MEASUREMENT) */

//#if (!FCT_MEASUREMENT) || (!FCT_CFG_ERROR_OUTPUT_SEN)
//  _PARAM_UNUSED(pProvidePorts); /* PRQA S 3112 */
//#endif
  _PARAM_UNUSED(pProvidePorts); /* PRQA S 3119 */ /* 2019-05-29, reviewer:Opreai01, Popam05, reason: possible usage in the future */
}


void FCTSen_v_SPMMeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
#endif/* (FCT_CFG_SIGNAL_PERF_MONITORING) */
#endif/*SPM_SRR_TECHNOLOGY*/

