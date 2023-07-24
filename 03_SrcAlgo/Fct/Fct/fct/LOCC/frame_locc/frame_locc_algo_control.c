/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_locc_algo_control.c

DESCRIPTION:               Functions for LOCC algo control purpose

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_locc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) && (FCT_CFG_ACT_CODE_VERSION))
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    LOCC_v_ProcessStates                                                                             */ /*!

  @brief           Set operation modes of subcomponents in LOCC

  @description     Sets the states of the sub-components based on the global
                   FCT state passed.

  @return          -

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         b_LoccIsInitialized : fct veh and it's subcomponents initialization status [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOCC_COMPONENT
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @created         01.03.2017
  @changed         01.03.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOCC_v_ProcessStates (FCT_OP_MODE_t eOpMode)
{
  /* ensure that each component runs in init state at least once */
  if (b_LoccIsInitialized != TRUE)
  {
    eOpMode = FCT_MOD_INIT;
  }

  /*set component states according to FCT state */
  switch (eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    {
      LOCC_v_SetOperationMode(LOCC_INIT);
#if (FCT_CFG_ACT_CODE_VERSION)
      CC_v_SetOperationMode(CC_INIT);
#endif
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    LOCC_v_SetOperationMode(LOCC_RUN);
#if (FCT_CFG_ACT_CODE_VERSION)
    CC_v_SetOperationMode(CC_OK);
#endif
    break;
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
    LOCC_v_SetOperationMode(LOCC_SHUTDOWN);
#if (FCT_CFG_ACT_CODE_VERSION)
    CC_v_SetOperationMode(CC_INIT);
#endif
    break;
  default:
    LOCC_v_SetOperationMode(LOCC_INIT);
#if (FCT_CFG_ACT_CODE_VERSION)
    CC_v_SetOperationMode(CC_INIT);
#endif
    break;

  }
}

/*************************************************************************************************************************
  Functionname:    LOCC_v_SignalErrorShutdown                                                                       */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error

  @return          -

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FALSE]

  @glob_in         b_LoccIsInitialized : LOCC and it's subcomponents initialization status    [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOCC_COMPONENT
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @created         01.03.2017
  @changed         01.03.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOCC_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  b_LoccIsInitialized = FALSE;

  if (isRecoveryPossible != TRUE)
  {
    LOCC_v_SetOperationMode(LOCC_INIT);
#if (FCT_CFG_ACT_CODE_VERSION)
    CC_v_SetOperationMode(CC_INIT);
#endif
  }
  else
  {
    /**
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
    LOCC_v_SetOperationMode(LOCC_SHUTDOWN);
#if (FCT_CFG_ACT_CODE_VERSION)
    CC_v_SetOperationMode(CC_INIT);
#endif
  }
}

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) && (FCT_CFG_ACT_CODE_VERSION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

