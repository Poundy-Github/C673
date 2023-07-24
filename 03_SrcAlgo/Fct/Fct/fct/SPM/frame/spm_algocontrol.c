/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.7 $

---*/ /*---
CHANGES:                   $Log: spm_algocontrol.c  $
CHANGES:                   Revision 1.7 2021/02/01 16:38:06CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC boolean issue
CHANGES:                   Revision 1.6 2020/06/25 08:10:19CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.5 2020/04/08 13:20:19CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC level 4 warnings
CHANGES:                   Revision 1.4 2018/09/24 15:16:31CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.3 2018/02/23 14:26:52CET Pallo, Istvan (palloi) 
CHANGES:                   Remove obsolute function call.
CHANGES:                   Replace old component states with the new ones.
CHANGES:                   Rework ShutDownWithError function.
CHANGES:                   Revision 1.2 2017/06/21 09:11:05CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove function header
CHANGES:                   Revision 1.1 2017/03/17 13:16:56CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

**************************************************************************** */



/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_main.h"
#include "spm_access_func.h"

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

void FCTSen_v_SPMProcessStates (FCT_OP_MODE_t eOpMode)
{
  uint8 uSHUTDOWSTATE = (uint8)FCT_SEN_SHUTDOWN;
  /* Reset port handler list if SPM is called in init mode.*/
  if(eOpMode == FCT_MOD_INIT)
  {
    SPM_v_InitPortHandlerList(b_FALSE);
  }

  if (t_FCTSenSPMFrame.bSPMIsInitialized != b_TRUE)
  {
    eOpMode = FCT_MOD_INIT;
  }

  switch (eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
  {
    if ((SPMState == COMP_STATE_NOT_RUNNING) && (FCTSenFrame.eFCTState == uSHUTDOWSTATE))
    {
      /**
        * check if BlockageInformation should be hold despite being in 'InitMode' which could be forced with FCTSenIsInitialized == FALSE.
        *         
        * last state of SPM is used for indication if BlockageInformation is to be hold.
        *    -> SPM_FREEZE.
        * to get some more safety, also the FCT state is used which is set to FCT_SEN_SHUTDOWN in this case because
        * EM is in 'InitMode' due to invalid inputs and does not provide a valid 'ObjectList'.
      **/
      FCTSen_v_SetSPMOperationMode(COMP_STATE_NOT_RUNNING);
    }
    else
    {
      FCTSen_v_SetSPMOperationMode(COMP_STATE_NOT_INITIALIZED);
    }
    break;
  }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    FCTSen_v_SetSPMOperationMode(COMP_STATE_RUNNING);
    break;

  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
  case (FCT_OP_MODE_t)FCT_MOD_PAUSE:
    FCTSen_v_SetSPMOperationMode(COMP_STATE_NOT_RUNNING);
    break;

  default:
    FCTSen_v_SetSPMOperationMode(COMP_STATE_TEMPORARY_ERROR);
    break;
  }
}


void FCTSen_v_SPMSignalErrorShutdown(const boolean isRecoveryPossible)
{
  t_FCTSenSPMFrame.bSPMIsInitialized = b_FALSE;

  if (isRecoveryPossible != b_TRUE)
  {
    FCTSen_v_SetSPMOperationMode(COMP_STATE_TEMPORARY_ERROR);
  }
  else if(t_FCTSenSPMFrame.eSPMState != COMP_STATE_TEMPORARY_ERROR)
  {
     /*
     * this path is currently reached in case of an invalid 'ObjectList' which can be caused by EM_MOD_INVALID_INPUTS.
     * check if this is the case by investigating status of 'PerformanceDegradation' data.
     * this structure should have the status of the 'ObjectList', namely AL_SIG_STATE_INIT.
     * except the situation where BlockageInformation should be hold.
     * this is signaled by setting SigHeaderStatus of 'PerfDegr_t' struct to 'AL_SIG_STATE_OK.
     * Freezing BlockageInformation is only allowed in EmFctCycleMode EM_FCT_CYCLE_INIT to prevent
     * false freezing in 'RunningMode'.
     *
     * this is only valid in case of having EM and FCT running synchronously which seems currently 
     * not to be the case -> skip second condition temporarily since 'EmFctCycleMode' data is currently used from recording
     * instead of the one from simulation!
     */
    FCTSen_v_SetSPMOperationMode(COMP_STATE_NOT_INITIALIZED);
  }
  else
  {
    /* SPM is in error. Don't change state.*/
  }
}
#endif/*!< (FCT_CFG_SIGNAL_PERF_MONITORING) */
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

