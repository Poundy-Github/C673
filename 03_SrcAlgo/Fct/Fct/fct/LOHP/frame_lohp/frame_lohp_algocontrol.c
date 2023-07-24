/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_algocontrol.c

DESCRIPTION:               Setting of LOHP State matrix (states of LOHP Sub-components)

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lohp_algocontrol Frame_lohp_algo_control
@ingroup    lohp_base_frame
@brief      Functions to control LOHP internal states
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lohp.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*! @endcond Doxygen_Suppress */

#if (FCT_CFG_ACT_CODE_VERSION)    //  GEN 4

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             LOHP_v_SetAlgoErrorBuffer */ /*! 

  @brief          Set the Algo Error Buffer

  @description    Set the Algo Error in priority
                  not possible to change to a lower priority than already set

  @param[in]      ErrorQualifier : the Error to set [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]
  @param[out]     pErrorBuffer   : pointer to the buffered error [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]

  @pre            nothing

  @post           properly buffered Error

  @author         Christian Obst
**************************************************************************** */
void LOHP_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
{
  if ( (pErrorBuffer != NULL) && (ErrorQualifier != ALGO_QUAL_OK) ) /*pointer check and entry condition*/
  {
    if (*pErrorBuffer == ALGO_QUAL_OK)
    {
      *pErrorBuffer = ErrorQualifier;
    }
    else
    {
      if (ErrorQualifier < *pErrorBuffer)
      {
        *pErrorBuffer = ErrorQualifier;
      }
    }
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    LOHP_v_ProcessStates                                                                             */ /*!

  @brief           Set operation modes of all sub-components

  @description     Sets the states of the sub-components based on the global
                   FCT state passed.

  @return          void

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         b_LOHPIsInitialized : fct sen and it's subcomponents initialization status [TRUE, FALSE]
  @glob_in         StateSPM : SPM sub-module state                    [StateSPM_t as in spm_ext.h]
  @glob_in         FCTSenFrame.eFCTState : FCT current operation mode [FCTSenState_t as in fct_sen-h]
  
  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP processing

  @pre             ACTL has to set Opmode via FCTSetOpMode() before FCTProcess()
  @post            Changed OpModes for all (Sub-)Components.

  @created         09.11.2009
  @changed         21.10.2015

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
void LOHP_v_ProcessStates (FCT_OP_MODE_t eOpMode)
{
  /*! ---  FCT State Matrix ---  */
  /*! set operation modes of all components depending on FCT OpMode  */

  if (b_LOHPIsInitialized != TRUE)
  {
    eOpMode = FCT_MOD_INIT;
  }

  switch (eOpMode)
  {
  /*  TC  */
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    {
      LOHP_v_SetOperationMode(LOHP_INIT);
      TC_v_SetOperationMode(TC_INIT);
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    {
      LOHP_v_SetOperationMode(LOHP_RUN);
      TC_v_SetOperationMode(TC_OK);
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
    {
      LOHP_v_SetOperationMode(LOHP_SHUTDOWN);
      TC_v_SetOperationMode(TC_INIT);
      break;
    }
  default:
    {
      LOHP_v_SetOperationMode(LOHP_INIT);
      TC_v_SetOperationMode(TC_INIT);
      break;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_SignalErrorShutdown                                                                       */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error

  @return          void

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FASLE]

  @glob_in         GET_PERF_DEG_DATA_PTR->sSigHeader.eSigStatus :                                       [AlgoSignalState_t as in Rte_Type.h]
  @glob_out        b_LOHPIsInitialized : FCT_SEN and it's subcomponents initialization status           [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP processing

  @pre             None 
  @post            No changes 

  @created         21.05.2013
  @changed         23.10.2015

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com
*************************************************************************************************************************/
void LOHP_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  b_LOHPIsInitialized = FALSE;

  if (isRecoveryPossible != TRUE)
  {
    LOHP_v_SetOperationMode(LOHP_ERROR);
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
    LOHP_v_SetOperationMode(LOHP_SHUTDOWN);
  }
}

#else     //  GEN 3

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             LOHP_v_SetAlgoErrorBuffer */ /*! 

  @brief          Set the Algo Error Buffer

  @description    Set the Algo Error in priority
                  not possible to change to a lower priority than already set

  @param[in]      ErrorQualifier : the Error to set [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]
  @param[out]     pErrorBuffer   : pointer to the buffered error [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]

  @pre            nothing

  @post           properly buffered Error

  @author         Christian Obst
**************************************************************************** */
void LOHP_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
{
  if ( (pErrorBuffer != NULL) && (ErrorQualifier != ALGO_QUAL_OK) ) /*pointer check and entry condition*/
  {
    if (*pErrorBuffer == ALGO_QUAL_OK)
    {
      *pErrorBuffer = ErrorQualifier;
    }
    else
    {
      if (ErrorQualifier < *pErrorBuffer)
      {
        *pErrorBuffer = ErrorQualifier;
      }
    }
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    LOHP_v_ProcessStates                                                                             */ /*!

  @brief           Set operation modes of all sub-components

  @description     Sets the states of the sub-components based on the global
                   FCT state passed.

					@startuml
						Start
						Partition LOHP_v_ProcessStates {
							If(Initialization status bit is set) then (TURE)
								-Set the HP intialization operation mode
								-Set the LOHP intialization operation mode
							Else (FALSE)
								-Set operation modes of HP accroding to FCT mode
								-Set operation modes of LOHP accroding to FCT mode
							Endif 
						}	
						End	
					@enduml


  @return          void

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         b_LOHPIsInitialized : fct sen and it's subcomponents initialization status [TRUE, FALSE]
  @glob_in         StateSPM : SPM sub-module state                    [StateSPM_t as in spm_ext.h]
  @glob_in         FCTSenFrame.eFCTState : FCT current operation mode [FCTSenState_t as in fct_sen-h]
  
  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP processing

  @pre             ACTL has to set Opmode via FCTSetOpMode() before FCTProcess()
  @post            Changed OpModes for all (Sub-)Components.

  @created         09.11.2009
  @changed         21.10.2015

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-85-0008a201
  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
void LOHP_v_ProcessStates (FCT_OP_MODE_t eOpMode)
{
  /*! ---  FCT State Matrix ---  */
  /*! set operation modes of all components depending on FCT OpMode  */

  if (b_LOHPIsInitialized != TRUE)
  {
    eOpMode = FCT_MOD_INIT;
  }

  switch (eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    {
      LOHP_v_SetOperationMode(LOHP_INIT);
      HP_v_SetOperationMode(HP_INIT);
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    {
      LOHP_v_SetOperationMode(LOHP_RUN);
      HP_v_SetOperationMode(HP_OK);
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
    {
      LOHP_v_SetOperationMode(LOHP_SHUTDOWN);
      HP_v_SetOperationMode(HP_INIT);
      break;
    }
  default:
    {
      LOHP_v_SetOperationMode(LOHP_INIT);
      HP_v_SetOperationMode(HP_INIT);
      break;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    LOHP_v_SignalErrorShutdown                                                                       */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error

					@startuml
					Start
					Partition LOHP_v_SignalErrorShutdown {
						If(Is recovery not possible) then (True)
						- Set the LOHP in LOHP_SHUTDOWN operation mode
						- Set the HP in HP_INIT operation mode
						Else (False)
						- Set the LOHP in LOHP_ERROR operation mode
						- Set the HP in HP_INIT operation mode
						Endif  
					}
					End	
					@enduml

  @return          void

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FASLE]

  @glob_in         GET_PERF_DEG_DATA_PTR->sSigHeader.eSigStatus :                                       [AlgoSignalState_t as in Rte_Type.h]
  @glob_out        b_LOHPIsInitialized : FCT_SEN and it's subcomponents initialization status           [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP processing

  @pre             None 
  @post            No changes 

  @created         21.05.2013
  @changed         23.10.2015

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-86-0008a201

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com
*************************************************************************************************************************/
void LOHP_v_SignalErrorShutdown(const boolean isRecoveryPossible)
{
  b_LOHPIsInitialized = FALSE;

  if (isRecoveryPossible == FALSE)
  {
    /* Recovery not possible. Fatal error. Component shut down */
    LOHP_v_SetOperationMode(LOHP_SHUTDOWN);
    HP_v_SetOperationMode(HP_INIT);
  }
  else
  {
    /* Recovery is possible. Not a fatal error */
    LOHP_v_SetOperationMode(LOHP_ERROR);
    HP_v_SetOperationMode(HP_INIT);
  }
}

#endif /*!< (FCT_CFG_ACT_CODE_VERSION) */

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

