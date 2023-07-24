/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_io.c

DESCRIPTION:               Function processing I/O Wrapper Main module
                           Manages input and output subroutines

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lohp_io Frame_lohp_io
@ingroup    lohp_base_frame
@brief      Functions to manage input and output subroutines
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lohp.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))
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

//static void FCT_v_ACCCalcMotionMatrices(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 LOHP_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                     sMeasCycleMonitor *pLastMeasCycle, 
                                     float32 fTargetCycleTime, 
                                     uint8 iAcceptableDrops);
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/
/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/* ***********************************************************************
  @fn             FCTSen_v_ACCCheckPortUpdated */ /*! 
  @brief          compares saved and current meas timestamp
  @description    checks current timestamp against last timestamp
                  counts frozen cycles (expected but not received data)
                  if duration since last update is greater than given in debounce and cycle time set error
  @param[in]      pInputPortMeasCycle   : currently received timestamp of interface
  @param[in]      fTargetCycleTime      : expected reception cycle time
  @param[in]      iAcceptableDrops      : number of acceptable frame drops
  @param[in,out]  pLastMeasCycle        : contains last seen timestamp and the dropped frame counter;
                                          is updated with currently received timestamp
  @return         error (!= zero) in case of frozen port
  @author         Christian Obst
**************************************************************************** */
static uint32 LOHP_v_CheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
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
#endif

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/* ***********************************************************************
  @fn             FCTSen_v_ACCCheckInputUpdate */ /*! 
  @brief          Checks updated counters for input ports.
  @description    calls the update checker of every input interface.
  @param[in]      pRequirePorts               : input port structure provided to FCTSen.
  @param[in]      pFCTSenInputMeasTimeStamps  : aggregation struct for all input port update information.
  @param[in]      fTargetCycleTime            : target update cycle time (in Sen it's ego calling cycle time).
  @return         number of out of update interfaces.
  @author         Christian Obst
**************************************************************************** */

uint32 LOHP_v_CheckInputUpdate(const reqLOHPPrtList_t * pRequirePorts, FCTSenHC_InputMeasCounter_t *pFCTSenInputMeasTimeStamps, float32 fTargetCycleTime)
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
  /*ErrorCounter += FCTSen_v_ACCCheckPortUpdated( &(pRequirePorts->pSenCtrlData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pSenCtrlData), fCycleTime, AcceptableDrops );*/
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEmFctCycleMode->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmFctCycleMode), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEmGenObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmGenObjList), fTargetCycleTime, AcceptableDrops );
//#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
//    ErrorCounter += FCTSen_v_ACCCheckPortUpdated( &(pRequirePorts->pEmCustObjLis->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmCustObjList), fTargetCycleTime, AcceptableDrops );
//#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEmARSObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmARSObjList), fTargetCycleTime, AcceptableDrops );
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEmCamObjList->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEmCamObjList), fTargetCycleTime, AcceptableDrops );
#endif
#else
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pPubEmObj->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pPubEmObj), fTargetCycleTime, AcceptableDrops );
#endif

#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pPubFctObj->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pPubFctObj), fTargetCycleTime, AcceptableDrops );
#endif
#endif
  //ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEgoDynObjSync->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEgoDynObjSync), fTargetCycleTime, AcceptableDrops );
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEgoDynRaw->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEgoDynRaw), fTargetCycleTime, AcceptableDrops );
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pEgoStaticData->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pEgoStaticData), fTargetCycleTime, AcceptableDrops );

#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pFctVehLongOut->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pFctVehLongOut), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pAlignmentMonInput->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pAlignmentMonInput), fTargetCycleTime, AcceptableDrops );
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pVehSig->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pVehSig), fTargetCycleTime, AcceptableDrops );
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pFCTCustomOutput->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pFCTCustomOutput), fTargetCycleTime, AcceptableDrops );
#endif
#endif
#if (FCT_CFG_LOHP_COMPONENT)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pSLATE_HC_Data->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pSLATE_HC_Data), fTargetCycleTime, AcceptableDrops );
#endif
#if #if(FCT_CFG_SIGNAL_PERF_MONITORING)
  ErrorCounter += LOHP_v_CheckPortUpdated( &(pRequirePorts->pSPM_HC_Data->sSigHeader.uiTimeStamp), &(pFCTSenInputMeasTimeStamps->pSPM_HC_Data), fTargetCycleTime, AcceptableDrops );
#endif

  return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

