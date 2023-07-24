/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT 

MODULNAME:                 fct_algocontrol.c

DESCRIPTION:               set FCT State Matrix (states of FCT sub-components)

AUTHOR:                    Gergely Ungvary

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.1.1.1

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_sen.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer: Prabhu Sundaramurthy, reason: This does not effect the functionality*/
/**
@defgroup fct_algocontrol AlgoControl
@ingroup frame_sen
@{
*/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
void FCTSenSetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)
static void FCTSenSetStates( FCTCompState_t StFCT);

#if 0//(FCT_CFG_INPUT_PREPROCESSSING)
#define FCT_SEN_STATE_PARAM(_FIPSTATE_, _FCTSENSTATE_) (_FIPSTATE_), (_FCTSENSTATE_)
#else
#define FCT_SEN_STATE_PARAM(_FIPSTATE_, _FCTSENSTATE_) (_FCTSENSTATE_)
#endif

/*! @endcond Doxygen_Suppress */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             setAlgoErrorBuffer */ /*! 

  @brief          Set the Algo Error Buffer

  @description    Set the Algo Error in priority
                  not possible to change to a lower priority than already set
                  @startuml 
                     Start 
                     Partition  setAlgoErrorBuffer
                       - Set the Algo Error Buffer
                         If (pointer to the buffered error not equal to NULL AND the Error to set not equal to ALGO_QUAL_OK ) then (true)
                           If (pointer to the buffered error equal to ALGO_QUAL_OK ) then (true)
                              - the Error to set is assigned to pointer to the buffered error
                           Else (false)
                             If (the Error to set less than pointer to the buffered error) then (true)
                                - the Error to set is assigned to pointer to the buffered error	
                            Endif
                           Endif
                         Endif
                      End 
                    @enduml

  @param[in]      ErrorQualifier : the Error to set
  @param[out]     pErrorBuffer   : pointer to the buffered error

  @pre            nothing

  @post           properly buffered Error

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author         Christian Obst
**************************************************************************** */
void FCTSenSetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
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
/*! @cond Doxygen_Suppress */

/*************************************************************************************************************************
  Functionname:    FCTSenSetStates                                                                                  */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       StFCT : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.01.2017
  @changed         27.01.2017

  @todo            Remove this entire line if not needed

  @author          Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void FCTSenSetStates(  FCTCompState_t StFCT)
{
  FCTSenFrame.eFCTState = StFCT;
}
/*! @endcond Doxygen_Suppress */
/*************************************************************************************************************************
  Functionname:    FCTSenProcessStates                                                                              */ /*!

  @brief           Set operation modes of all sub-components

  @description     Sets the states of the sub-components based on the global
                   FCT state passed.
                   @startuml 
                      Start
                        Partition  FCTSenProcessStates
                          Partition  FCT_State_Matrix
                              If(the operation mode of FCT to use is equal to FCT_MOD_STARTUP) then (true)
                                  If(SPMState is equal to 6 AND FCT current operation mode is equal to FCT_MOD_INIT) then (true)
                                      - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED parameter
                                  Else (false)
                                      - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED parameter	
                                  endif
                              Elseif(the operation mode of FCT to use is equal to FCT_MOD_RUNNING) then (true)
                                  - Function FCTSenSetStates  is called with COMP_STATE_RUNNING parameter
                              Elseif(the operation mode of FCT to use is equal to FCT_MOD_SHUTDOWN) then (true)
                                  - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED and COMP_STATE_TEMPORARY_ERROR parameter
                              Else
                                  - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED parameter
                          End 
                    @enduml

  @return          void

  @param[in]       eOpMode : the operation mode of FCT to use         [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         StateSPM : SPM sub-module state                    [StateSPM_t as in spm_ext.h]
  @glob_in         FCTSenFrame.eFCTState : FCT current operation mode [FCTSenState_t as in fct_sen-h]
  
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             ACTL has to set Opmode via FCTSetOpMode() before FCTProcess()
  @post            Changed OpModes for all (Sub-)Components.

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.11.2009
  @changed         21.10.2015

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
void FCTSenProcessStates (FCT_OP_MODE_t eOpMode)
{
  /*! ---  FCT State Matrix ---  */
  switch (eOpMode)
  {
  /*                                     FIP         FCT */
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
    {
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
      if ((SPMState == COMP_STATE_NOT_RUNNING) && (FCTSenFrame.eFCTState == COMP_STATE_NOT_RUNNING))
      {
        /**
         * check if BlockageInformation should be hold despite being in 'InitMode' which could be forced with FCTSenIsInitialized == FALSE.
         *         
         * last state of SPM is used for indication if BlockageInformation is to be hold.
         *    -> SPM_FREEZE.
         * to get some more safety, also the FCT state is used which is set to FCT_SEN_SHUTDOWN in this case because
         * EM is in 'InitMode' due to invalid inputs and does not provide a valid 'ObjectList'.
         * 
         */
        FCTSenSetStates(FCT_SEN_STATE_PARAM(  COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED    )); 
      }
      else
      {
        FCTSenSetStates(FCT_SEN_STATE_PARAM( COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED    )); 
      }
#else
      FCTSenSetStates(FCT_SEN_STATE_PARAM( COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED    )); 
#endif
      break;
    }
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
    FCTSenSetStates(FCT_SEN_STATE_PARAM(  COMP_STATE_RUNNING,     COMP_STATE_RUNNING     ));  
    break;
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
    FCTSenSetStates(FCT_SEN_STATE_PARAM(   COMP_STATE_NOT_INITIALIZED,   COMP_STATE_TEMPORARY_ERROR));  
    break;
  default:
    FCTSenSetStates(FCT_SEN_STATE_PARAM(  COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED    ));  
    break;
  }
}
/*************************************************************************************************************************
  Functionname:    FCTSenSignalErrorShutdown                                                                        */ /*!

  @brief           Set operation modes of all sub-components in case of Error

  @description     Set operation modes of all sub-components in case of Error
                    @startuml 
                        Start
                          Partition  FCTSenSignalErrorShutdown
                              -  Set operation modes of all sub-components in case of Error
                                  If(Status to inform whether the shutdown should takes place or not is  FALSE) then (true)
                                      - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED and COMP_STATE_TEMPORARY_ERROR parameter
                                  Else (False)
                                      If(eSigStatus is equal to AL_SIG_STATE_OK) then (true)
                                          - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED parameter
                                      Else (false)
                                          - Function FCTSenSetStates  is called with COMP_STATE_NOT_INITIALIZED parameter	
                                      Endif
                                  endif
                          End 
                      @enduml

  @return          void

  @param[in]       isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FASLE]

  @glob_in         GET_PERF_DEG_DATA_PTR->sSigHeader.eSigStatus :                                       [AlgoSignalState_t as in Rte_Type.h]

  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring switch
  @c_switch_full   None 

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         21.05.2013
  @changed         23.10.2015

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com
*************************************************************************************************************************/
void FCTSenSignalErrorShutdown(const boolean isRecoveryPossible )
{
  if (isRecoveryPossible != TRUE)//PRQA S 1863
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
  {
    FCTSenSetStates(FCT_SEN_STATE_PARAM(COMP_STATE_NOT_INITIALIZED, COMP_STATE_TEMPORARY_ERROR)); 
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
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    if (FCTSEN_pPerfDegrData->sSigHeader.eSigStatus == AL_SIG_STATE_OK /*&& GDB_CYCLE_MODE == EM_FCT_CYCLE_INIT*/)
    {
      FCTSenSetStates(FCT_SEN_STATE_PARAM(   COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED));
    }
    else
    {
      FCTSenSetStates(FCT_SEN_STATE_PARAM(    COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED));
    }
#else
    FCTSenSetStates(FCT_SEN_STATE_PARAM(    COMP_STATE_NOT_INITIALIZED,   COMP_STATE_NOT_INITIALIZED));
#endif
  }
}

#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

