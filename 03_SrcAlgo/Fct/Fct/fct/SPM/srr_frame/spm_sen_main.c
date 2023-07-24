/*! \file **********************************************************************

  COPYRIGHT (C) CONTINENTAL

  $FILENAME:                 spm_sen_main.c $

  $PROJECT:                  SRR5xx $

  $DESCRIPTION:              SPM (function) component main module SPM_SEN  $

  LAST REVISION:             $Revision: 1.3 $

  LAST AUTHOR:               $Author: Pallo, Istvan (palloi) $

  ---*/ /*---
  CHANGES:                   $Log: spm_sen_main.c  $
  CHANGES:                   Revision 1.3 2020/06/26 09:53:46CEST Pallo, Istvan (palloi) 
  CHANGES:                   Fix devgate compile errors
  CHANGES:                   Revision 1.2 2020/06/25 18:10:43CEST Pallo, Istvan (palloi) 
  CHANGES:                   Remove unused globals and functions
  CHANGES:                   Revision 1.1 2020/06/25 07:02:34CEST Pallo, Istvan (palloi) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/srr_frame/project.pj
  CHANGES:                   Initial revision

**************************************************************************** */
/* Reducing lines of code changes component structure. */
/* PRQA S 7013 EOF */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm.h"

#if(SPM_SRR_TECHNOLOGY == SWITCH_ON)
#include "spm_sen.h"


/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/* frame (cycle time, cycle counter, opmode ...) */
SPM_SenFrame_t SPMFrameData;


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*! Utility function to set signal header to error */
// void SPM_SenSetSigHeaderError(SignalHeader_t * const pSigHeader);


#if(SPM_USE_SERVICE_POINTER_FUNCTS)
void  SpmExecSPM_Exec (SpmReqPortsSPM_Exec const*const reqPorts, SpmProPortsSPM_Exec const*const proPorts,SPM_ProcMem const*const  procMem, SPM_Services_SPM_EXEC const*const  services)
#else
void  SpmExecSPM_Exec (SpmReqPortsSPM_Exec const*const reqPorts, SpmProPortsSPM_Exec const*const proPorts)
#endif
{
  //local variables declaration/initialization
  AlgoErrorState_t *puiSelftestEvent;
  float32 fCurrentVehicleSpeed;
  fTime_t fCurrentCycleTime;

  puiSelftestEvent = AL_ERR_STATE_UNKNOWN;

  //process states
  SPM_v_ProcessStates(reqPorts->controlData->opMode);

  //check ports
#if(SPM_USE_SERVICE_POINTER_FUNCTS == SWITCH_ON)
  SPM_v_CheckPorts(reqPorts, proPorts, services);
#else
  SPM_v_CheckPorts(reqPorts, proPorts);
#endif

  if(SPMFrameData.eSPMState != SPM_SEN_ERROR)
  {
    //get current speed for blockage processing
    fCurrentVehicleSpeed = reqPorts->vehDyn->Longitudinal.Velocity;

    //get current cycle time
    fCurrentCycleTime = reqPorts->globalOutput->fCycletime;

    SPM_v_SetProPortsHeader(reqPorts, proPorts);

    SPM_v_PreProcess(reqPorts, proPorts);

    SPMProcess(reqPorts->perfDegr,
               proPorts->senErrorOut, 
               puiSelftestEvent, 
               fCurrentVehicleSpeed, 
               reqPorts->vehDyn->MotionState.bRollerTestBench,
               &reqPorts->alnMonitoring->PartialBlockage,
               &reqPorts->bswAlgoParameters->Fct.Blockage
              );

    SPM_v_PostProcess(reqPorts, proPorts);
  }
  else
  {
    //init SPM output
    SPM_v_InitErrorOut(proPorts->senErrorOut);
    //init SPM frame data
    SPM_v_AlgoInit();
  }

  _PARAM_UNUSED(reqPorts);
  _PARAM_UNUSED(proPorts);
#if(SPM_USE_SERVICE_POINTER_FUNCTS)
  _PARAM_UNUSED(procMem);
  _PARAM_UNUSED(services);
#endif
}

ALGO_STATIC void SPM_v_ProcessStates(SPM_OpMode opMode)
{
  switch(opMode)
  {
  case spm_opModeNormal:
    SPMFrameData.eSPMState = SPM_SEN_RUN;
    break;
  case spm_opModePause:
    SPMFrameData.eSPMState = SPM_SEN_PAUSE;
    break;
  case spm_opModeReset:
  default:
    SPMFrameData.eSPMState = SPM_SEN_INIT;
    break;
  }
  SPMFrameData.eSPMOpMode = opMode;
  SPMFrameData.uiCycleCounter++;
  SPMFrameData.Version = SPM_SW_VERSION_NUMBER;
}

#if(SPM_USE_SERVICE_POINTER_FUNCTS == SWITCH_ON)
ALGO_STATIC void SPM_v_CheckPorts(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts, const SPM_Services_SPM_EXEC * services)
#else
ALGO_STATIC void SPM_v_CheckPorts(const SpmReqPortsSPM_Exec *reqPorts, const SpmProPortsSPM_Exec * proPorts)
#endif
{
  //check request ports
  if(
 #if(SPM_USE_SERVICE_POINTER_FUNCTS)
      (services == NULL)                   ||
 #endif
      (reqPorts == NULL)                   ||
      (reqPorts->bswAlgoParameters == NULL)||
      (reqPorts->controlData == NULL)      ||
      (reqPorts->perfDegr == NULL)         ||
      (reqPorts->vehDyn == NULL)           ||
      (reqPorts->vehSig == NULL)           ||
      (reqPorts->bswAlgoParameters->sSigHeader.eSigStatus != AL_SIG_STATE_OK)||
      (reqPorts->controlData->sigHeader.eSigStatus != AL_SIG_STATE_OK)       ||
      (reqPorts->perfDegr->sSigHeader.eSigStatus != AL_SIG_STATE_OK)         ||
      (reqPorts->vehDyn->sSigHeader.eSigStatus != AL_SIG_STATE_OK)           ||
      (reqPorts->vehSig->sSigHeader.eSigStatus != AL_SIG_STATE_OK)
    )
  {
    SPMFrameData.eSPMState = SPM_SEN_ERROR;
  }
  //check provide ports
  if((proPorts == NULL)||
      (proPorts->senErrorOut == NULL)||
      (proPorts->algoCompState ==NULL)
    )
  {
    SPMFrameData.eSPMState = SPM_SEN_ERROR;
  }
}


/* ***********************************************************************/ /*!
  @brief          Do initialization of SPM algo variables/states

  @description    Init FCT frame. (note: reset's global SPMSenFrame.bFirstCycleDone
                  flag.

  @return         void

  @author         Jochen Spruck & Gergely Ungvary
**************************************************************************** */
ALGO_STATIC void SPM_v_AlgoInit ()
{
  /* reset FirstCycleDone */
  SPMFrameData.bFirstCycleDone   = FALSE;
  SPMFrameData.uiCycleCounter    = 0u;
}

ALGO_STATIC void SPM_v_InitErrorOut(SPM_t_SenErrorOutType * pErrorOut)
{
  pErrorOut->BlockageStateBSD = AL_ERR_STATE_UNKNOWN;
  pErrorOut->BlockageStateFCTA = AL_ERR_STATE_UNKNOWN;
  pErrorOut->BlockageStateFCTB = AL_ERR_STATE_UNKNOWN;
  pErrorOut->BlockageStateLCA = AL_ERR_STATE_UNKNOWN;
  pErrorOut->BlockageStateRCTA = AL_ERR_STATE_UNKNOWN;
  pErrorOut->BlockageStateRCTB = AL_ERR_STATE_UNKNOWN;
  pErrorOut->PartialBlockageObserver = AL_ERR_STATE_UNKNOWN;
  pErrorOut->RangeObserver = AL_ERR_STATE_UNKNOWN;
  pErrorOut->TimeoutObserver = AL_ERR_STATE_UNKNOWN;
  pErrorOut->uSelftest = GDB_PD_STARTUP;

  pErrorOut->sigHeader.eSigStatus = AL_SIG_STATE_INIT;
}

ALGO_STATIC void SPM_v_SetProPortsHeader(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts)
{
  SPM_v_FillSigHeaderSigStatus(&proPorts->senErrorOut->sigHeader, &reqPorts->perfDegr->sSigHeader, AL_SIG_STATE_INVALID);
  SPM_v_FillSigHeaderSigStatus(&proPorts->algoCompState->sSigHeader, &reqPorts->controlData->sigHeader, AL_SIG_STATE_INVALID);
}

ALGO_STATIC void SPM_v_PreProcess(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts)
{
  SPM_v_SetVersion(proPorts);
  //copy cycle time for SPM internal usage
  SPMFrameData.fCycleTime = reqPorts->globalOutput->fCycletime;
  //set SPM state based on operation mode

  switch(SPMFrameData.eSPMState)
  {
    case SPM_SEN_RUN:
    case SPM_SEN_PAUSE:
    {
      SPMFrameData.bFirstCycleDone = TRUE;
      break;
    }
    case SPM_SEN_INIT:
    case SPM_SEN_SHUTDOWN:
    case SPM_SEN_ERROR:
    default:
    {
      SPM_v_AlgoInit();
      break;
    }
  }

  _PARAM_UNUSED(proPorts);
  _PARAM_UNUSED(reqPorts);
}

ALGO_STATIC void SPM_v_PostProcess(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts)
{
  switch(SPMFrameData.eSPMState)
  {
  case SPM_SEN_RUN:
  case SPM_SEN_PAUSE:
    {
      SPM_v_SetProPortsSigHeader(reqPorts, proPorts, AL_SIG_STATE_OK);
      break;
    }
  case SPM_SEN_INIT:
    {
      SPM_v_SetProPortsSigHeader(reqPorts, proPorts, AL_SIG_STATE_INIT);
      break;
    }
  case SPM_SEN_ERROR:
  case SPM_SEN_SHUTDOWN:
    {
      SPM_v_SetProPortsSigHeader(reqPorts, proPorts, AL_SIG_STATE_INVALID);
      break;
    }
  default:
    {
      SPM_v_SetProPortsSigHeader(reqPorts, proPorts, AL_SIG_STATE_INIT);
      break;
    }
  }
  
  _PARAM_UNUSED(reqPorts);
  _PARAM_UNUSED(proPorts);
}

ALGO_STATIC void SPM_v_SetVersion(const SpmProPortsSPM_Exec * proPorts)
{
  proPorts->senErrorOut->versionNumber = SPM_SW_VERSION_NUMBER;
  proPorts->algoCompState->uiVersionNumber = SPM_SW_VERSION_NUMBER;
}

ALGO_STATIC void SPM_v_SetProPortsSigHeader(const SpmReqPortsSPM_Exec * reqPorts, const SpmProPortsSPM_Exec * proPorts, SigState_t sigState)
{
  //set error out sig header
  proPorts->senErrorOut->sigHeader.uiCycleCounter = SPMFrameData.uiCycleCounter;
  proPorts->senErrorOut->sigHeader.uiMeasurementCounter = reqPorts->globalOutput->sigHeader.uiMeasurementCounter;
  proPorts->senErrorOut->sigHeader.uiTimeStamp = reqPorts->globalOutput->sigHeader.uiTimeStamp;
  proPorts->senErrorOut->sigHeader.eSigStatus = sigState;

  //set 
  proPorts->algoCompState->sSigHeader.uiCycleCounter = SPMFrameData.uiCycleCounter;
  proPorts->algoCompState->sSigHeader.uiMeasurementCounter = reqPorts->globalOutput->sigHeader.uiMeasurementCounter;
  proPorts->algoCompState->sSigHeader.uiTimeStamp = reqPorts->globalOutput->sigHeader.uiTimeStamp;
  proPorts->algoCompState->sSigHeader.eSigStatus = sigState;
}


/* ***********************************************************************/ /*!
  @brief          Set signal header with error values

  @description    Init SignalHeader_t struct with default values for FCT_SEN.
                  These default values are the cycle counter of FCT_SEN, signal
                  state invalid.

  @param[out]     pSigHeader   the signal header to be filled

  @return         void

  @author         Gergely Ungvary
**************************************************************************** */
ALGO_STATIC void SPMSenSetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiTimeStamp           = 0u;
  pSigHeader->uiMeasurementCounter  = 0u;
  pSigHeader->uiCycleCounter        = SPMFrameData.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

/* ***********************************************************************/ /*!
  @brief          Fill FCT Sen signal header with default values

  @description    Fill SignalHeader_t struct with default values for FCT_SEN.
                  These default values are the cycle counter of FCT_SEN, and
                  the signal state based on the passed parameter

  @param[in]      eSigState    the state to set for the 'eSigStatus' field
  @param[in]      pSourceHdr   the source signal header (measurement cycle
                               counter and timestamp are copied from this source)

  @param[out]     pSigHeader   the signal header to be filled

  @return         void

  @pre            FCT component initialized!

  @author         Gergely Ungvary
**************************************************************************** */
ALGO_STATIC void SPM_v_FillSigHeaderSigStatus(SignalHeader_t * const pSigHeader,const SignalHeader_t * pSourceHdr, SigState_t eSigStatus)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = SPMFrameData.uiCycleCounter;
  pSigHeader->eSigStatus            = eSigStatus;
}

ALGO_STATIC void SPM_v_FillSigHeaderNoHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t *pSourceHdr, SigState_t eSigStatus)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = SPMFrameData.uiCycleCounter;
  pSigHeader->eSigStatus            = eSigStatus;
}
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

