/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC (Adaptive Cruise Control - Interface and State Coordinator)

PACKAGENAME:               isc_algo_control.c

DESCRIPTION:               Functions for ISC algo control purpose

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.2 $

---*/ /*---
CHANGES:                    $Log: isc_algo_control.c  $
CHANGES:                    Revision 1.2 2017/10/05 08:32:29CEST uidj5069 
CHANGES:                    Initial Revision for ACC GEN 4
CHANGES:                    Revision 1.1 2017/03/10 10:48:12CET Koschalka, Mike (uidg3250) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOKMC_LongitudinalKinematicMotionControl/04_Engineering/01_Source_Code/LOKMC/frame_lokmc/project.pj
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "isc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    ISC_v_ProcessStates                                                                        */ /*!

  @brief           Set operation modes of subcomponents in ISC

  @description     Sets the states of the sub-components based on the global
                   FCT state passed.

  @return          -

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         b_FCTVehLokmcIsInitialized : fct veh and it's subcomponents initialization status [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ISC_COMPONENT
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @created         01.03.2017
  @changed         01.03.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void ISC_v_ProcessStates (FCT_OP_MODE_t eOpMode)
{
  /* ensure that each component runs in init state at least once */
  if (b_IscIsInitialized != TRUE)
  {
    eOpMode = FCT_MOD_INIT;
  }

  /*set component states according to FCT state */
  switch (eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    ISC_v_SetOperationMode(ISC_INIT);
    HMI_v_SetOperationMode(HMI_INIT);
    SM_v_SetOperationMode(SM_INIT);
    break;

  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    ISC_v_SetOperationMode(ISC_RUN);
    HMI_v_SetOperationMode(HMI_OK);
    SM_v_SetOperationMode(SM_OK);
    break;

  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:

    ISC_v_SetOperationMode(ISC_SHUTDOWN);
    HMI_v_SetOperationMode(HMI_INIT);
    SM_v_SetOperationMode(SM_INIT);
    break;

  default:
    ISC_v_SetOperationMode(ISC_INIT);
    HMI_v_SetOperationMode(HMI_INIT);
    SM_v_SetOperationMode(SM_INIT);
    break;

  }
}

/*************************************************************************************************************************
  Functionname:    FCTVeh_v_ISCSignalErrorShutdown                                                                  */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error

  @return          -

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FALSE]

  @glob_in         b_FCTVehLokmcIsInitialized : FCT_VEH and it's subcomponents initialization status    [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ISC_COMPONENT
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @created         01.03.2017
  @changed         01.03.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void ISC_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  b_IscIsInitialized = FALSE;

  if (isRecoveryPossible != TRUE)
  {
  ISC_v_SetOperationMode(ISC_INIT);
  HMI_v_SetOperationMode(HMI_INIT);
  SM_v_SetOperationMode(SM_INIT);
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
    ISC_v_SetOperationMode(ISC_SHUTDOWN);
    HMI_v_SetOperationMode(HMI_INIT);
    SM_v_SetOperationMode(SM_INIT);
  }
}

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

