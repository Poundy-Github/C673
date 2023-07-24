/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_io.c

DESCRIPTION:               Function Processing I/O-Wrapper Main Module

                            Manages Input- and Output-Subroutines
                            FCTSenProcessInput()
                            FCT = Function

AUTHOR:                    Thomas Berndt

CREATION DATE:             18.05.2006

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_sen.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer: Prabhu Sundaramurthy, reason: This does not effect the functionality*/
#include "fct_par.h"
/**
@defgroup fct_io Fct_io
@ingroup frame_sen
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


#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 FCTSenCheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                     sMeasCycleMonitor *pLastMeasCycle, 
                                     float32 fTargetCycleTime, 
                                     uint8 iAcceptableDrops);
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/
/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/* ***********************************************************************
  @fn             FCTSenCheckPortUpdated */ /*! 
  @brief          compares saved and current meas timestamp
  @description    checks current timestamp against last timestamp
                  counts frozen cycles (expected but not received data)
                  if duration since last update is greater than given in debounce and cycle time set error
                  @startuml 
                     Start
                        Partition FCTSenCheckPortUpdated{
                            - compares saved and current meas timestamp
                            If(currently received timestamp of interface is less than pLastMeasCycle->uiTimeStamp ) then (true)
                                 : uiDeltaTimeUs = ( (0u)^(0u)) - (pLastMeasCycle->uiTimeStamp - *pInputPortMeasCycle);
                            Else (false)
                               : uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
                            Endif
                            If(uiDeltaTimeUs is equal to 0 ) then (true)		
                                If((pLastMeasCycle->uiLastUpdateCounter + 1) * uiTargetCycleTimeCallUs)  < uiMaxAcceptableDropTimeUs ) then (true)
                                    -pLastMeasCycle->uiLastUpdateCounter += 1u
                                Else (false)
                                    - uErrorFlag is equal to 1
                                Endif
                            Else (false)
                                If(uiDeltaTimeUs > uiMaxAcceptableDropTimeUs) then (true)
                                    - uErrorFlag is equal to 1
                                Else (false)
                                    - pLastMeasCycle->uiLastUpdateCounter is equal to 0
                                Endif
                            Endif
                        End 
                    @enduml

  @param[in]      pInputPortMeasCycle   : currently received timestamp of interface
  @param[in]      fTargetCycleTime      : expected reception cycle time
  @param[in]      iAcceptableDrops      : number of acceptable frame drops
  @param[in,out]  pLastMeasCycle        : contains last seen timestamp and the dropped frame counter;
                                          is updated with currently received timestamp
  @return         error (!= zero) in case of frozen port

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author         Christian Obst
**************************************************************************** */
static uint32 FCTSenCheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                      sMeasCycleMonitor *pLastMeasCycle,
                                      float32 fTargetCycleTime, 
                                      uint8 iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /*20150325 C. Obst: intended behavior to cast float to uInt. fractional part is neglectible.*/
  /*PRQA S 4119 3*/
  const AlgoDataTimeStamp_t uiReceiveCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * MILLION);         /*conversion second to microsecond*/
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiReceiveCycleTimeUs ); /*accepted drops + current Cycle + 0.5 safety margin*/
  const AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_SEN_TARGET_CYCLE_TIME * (float32)MILLION);

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

/* ***********************************************************************
  @fn             FCTSenCheckInputUpdate */ /*! 
  @brief          Checks updated counters for input ports.
  @description    calls the update checker of every input interface.
  @param[in]      pRequirePorts               : input port structure provided to FCTSen.
  @param[in]      pFCTSenInputMeasTimeStamps  : aggregation struct for all input port update information.
  @param[in]      fTargetCycleTime            : target update cycle time (in Sen it's ego calling cycle time).
  @return         number of out of update interfaces.
  @author         Christian Obst
**************************************************************************** */

uint32 FCTSenCheckInputUpdate(const reqFCTSenPrtList_t * pRequirePorts, FCTSen_InputMeasCounter_t *pFCTSenInputMeasTimeStamps, float32 fTargetCycleTime )
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;

  /* Check Input Port Measurement Counters */
  /*ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pSenCtrlData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pSenCtrlData), fCycleTime, AcceptableDrops );*/
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEmFctCycleMode->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmFctCycleMode), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEmGenObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmGenObjList), fTargetCycleTime, AcceptableDrops );
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEmCustObjLis->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmCustObjList), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEmARSObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmARSObjList), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEmCamObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmCamObjList), fTargetCycleTime, AcceptableDrops );
#endif

#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pMovObjTraces->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pMovObjTraces), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pObjectTraces->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pObjectTraces), fTargetCycleTime, AcceptableDrops );
#endif
#endif
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEgoDynObjSync->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEgoDynObjSync), fTargetCycleTime, AcceptableDrops );
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEgoDynRaw->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEgoDynRaw), fTargetCycleTime, AcceptableDrops );
/*  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEgoStaticData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEgoStaticData), fCycleTime, AcceptableDrops );*/
#if (FCT_CFG_RSP_OUTPUT_PD)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pRSPOutputPD->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pRSPOutputPD), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pPerfDegrData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pPerfDegrData), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_ROAD_INPUT)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pRoadData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pRoadData), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pRSPContextData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pRSPContextData), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pFctVehLongOut->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pFctVehLongOut), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* customer specific input/output */
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pFCTCustomInput->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pFCTCustomInput), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Fusion output information from camera */
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pCameraObjData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pCameraObjData), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pAlignmentMonInput->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pAlignmentMonInput), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pVehSig->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pVehSig), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Mobil-eye raw input for debugging */
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pME_in->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pME_in), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pBswAlgoParameters->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pBswAlgoParameters), fTargetCycleTime, AcceptableDrops );
#endif
#if (0) /*no alive counters in CPARs*/
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pCPAR_FCT_Parameters), fTargetCycleTime, AcceptableDrops );
#endif
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Macom SRD blockage info for SPM */
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pPerfDegrExtInput->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pPerfDegrExtInput), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pDIMOutputCustom->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pDIMOutputCustom), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pNaviData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pNaviData), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pCamLaneData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pCamLaneData), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pEmFusionObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmFusionObjList ), fTargetCycleTime, AcceptableDrops );
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pTSAInputData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pTSAInputData ), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pCamSLAInputData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pCamSLAInputData ), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
  ErrorCounter += FCTSenCheckPortUpdated( &(pRequirePorts->pLongCtrlResp->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pLongCtrlResp ), fTargetCycleTime, AcceptableDrops );
#endif /* ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)) */
    return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */



