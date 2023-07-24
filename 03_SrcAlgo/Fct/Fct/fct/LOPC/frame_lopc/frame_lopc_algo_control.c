/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc_algo_control.c

DESCRIPTION:               Functions for LOPC algo control purpose

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lopc_algocontrol Frame_lopc_algo_control
@ingroup    lopc_base_frame
@brief      Functions to control LOPC internal states
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lopc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    LOPC_v_ProcessStates                                                                             */ /*!

  @brief           Set operation modes of subcomponents in LOPC

  @description     Sets the states of the sub-components based on the global
                   FCT state passed.
@startuml
Start
Partition LOPC_v_Processstates(){
if (LOPC is not initialized) then (True)
: Operation Mode is set to Function mode to Init state;
Endif
: Set component states according to FCT State;
}
end
@enduml

  @return          -

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         b_LopcIsInitialized : fct veh and it's subcomponents initialization status [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   @ref FCT_CFG_ACT_CODE_VERSION \n
  @c_switch_full   FCT_CFG_LOPC_COMPONENT
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @created         01.03.2017
  @changed         01.03.2017

  @InOutCorrelation     Covered in plantuml design

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-62-0008a220

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOPC_v_ProcessStates (FCT_OP_MODE_t eOpMode)
{
  /* ensure that each component runs in init state at least once */
  if (b_LopcIsInitialized != TRUE)
  {
    eOpMode = FCT_MOD_INIT;
  }

  /*set component states according to FCT state */
  switch (eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    {
      LOPC_v_SetOperationMode(LOPC_INIT);
#if (FCT_CFG_ACT_CODE_VERSION)
      LOC_v_SetOperationMode(LOC_INIT);
      LOP_v_SetOperationMode(LOP_INIT);
#endif
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    LOPC_v_SetOperationMode(LOPC_RUN);
#if (FCT_CFG_ACT_CODE_VERSION)
    LOC_v_SetOperationMode(LOC_OK);
    LOP_v_SetOperationMode(LOP_OK);
#endif
    break;
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
    LOPC_v_SetOperationMode(LOPC_SHUTDOWN);
#if (FCT_CFG_ACT_CODE_VERSION)
    LOC_v_SetOperationMode(LOC_INIT);
    LOP_v_SetOperationMode(LOP_INIT);
#endif
    break;
  default:
    LOPC_v_SetOperationMode(LOPC_INIT);
#if (FCT_CFG_ACT_CODE_VERSION)
    LOC_v_SetOperationMode(LOC_INIT);
    LOP_v_SetOperationMode(LOP_INIT);
#endif
    break;

  }
}

/*************************************************************************************************************************
  Functionname:    LOPC_v_SignalErrorShutdown                                                                       */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error

@startuml
Start
Partition LOPC_v_SignalErrorShutDown(){
If (Recovery Condition is not Possible)Then (True)
: Set operation modes of LOPC in Init;
Else (false)
: Set operation mode of LOPC in Shut Down mode;
Endif
}
end
@enduml

  @return          -

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FALSE]

  @glob_in         b_LopcIsInitialized : LOPC and it's subcomponents initialization status    [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @created         01.03.2017
  @changed         01.03.2017

  @InOutCorrelation     Covered in plantuml design

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-112-0008a220

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOPC_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  b_LopcIsInitialized = FALSE;

  if (isRecoveryPossible == FALSE)
  {
    /* Recovery not possible. Fatal error. Component shut down */
    LOPC_v_SetOperationMode(LOPC_SHUTDOWN);
#if (FCT_CFG_ACT_CODE_VERSION)
    LOC_v_SetOperationMode(LOC_INIT);
    LOP_v_SetOperationMode(LOP_INIT);
#endif
  }
  else
  {
    /* Recovery is possible. Not a fatal error */
    LOPC_v_SetOperationMode(LOPC_ERROR);
#if (FCT_CFG_ACT_CODE_VERSION)
    LOC_v_SetOperationMode(LOC_INIT);
    LOP_v_SetOperationMode(LOP_INIT);
#endif
  }
}

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

