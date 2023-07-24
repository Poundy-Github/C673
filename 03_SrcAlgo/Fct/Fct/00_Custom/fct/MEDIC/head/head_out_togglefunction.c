/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_togglefunction.c

DESCRIPTION:               Implementation of the head toggle function output

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:15:13CEST $

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            1.12

**************************************************************************** */

/**
@defgroup head_out_togglefunction HEAD_OUT_TOGGLEFUNCTION 
@ingroup Medic_head
@{ **/

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*************************************************************************************************************************
  Functionname:         HEADOutToggleFunction                                                                       */ /*!

  @brief                HEAD Out Toogle Functionality

  @description          HEAD Out Toogle Functionality
                        @startuml
                        Start
                        :Fetch the Module Output;
                            Note left:Fetch the Module Output for which the toggle function need to execute.
                        If (Is Output initialization needed?) then (yes)
                            :Do Initialization;
                                Note left:Initialize output type for the Module.
                        Else (no)
                            If (Is Module State Active?) then (yes)
                                :Get Active Hypothesis;
                                    Note left:Get all the Active Hypothesis \nfor the Module.
                                :Find Most Critical Hypothesis;
                                    Note left:Get the Most critical active \nHypothese for the Module.
                                :Set Module Output for the Most Critical active Hypothesis;
                                    Note left:Set Module Output based on the Most Critical \nactive Hypothesis for the Module.
                            Else (no)
                                :Reset Output to Default;
                                    Note right: Reset Output of the Module to Default Value.
                            Endif
                        Endif
                        Stop
                        @enduml
                                  
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise error code correspond to
                                      NULL Pointer is returned

  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            bInit : Boolean variable indicates initialization is needed or not

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADOutToggleFunction(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit)
{
  /*warning for pInputData - because in this implementation the pInputData isn't used*/
  eGDBError_t retValue = GDB_ERROR_NONE;

  if( (pModule != NULL) && (pModule->pOutput != NULL))
  {    
    void *pOutput = (void *) (pModule->pOutput); /*PRQA S 0314 #date: 2020-06-02, reviewer: Nalina M, reason: Case to void intended as use of generic interface */
    HEADModuleOutputToggleFunction_t *pToggleFunction = (HEADModuleOutputToggleFunction_t *)pOutput;
    
    if(bInit == b_TRUE)
    {
      /*do initialization for this output type*/
      pToggleFunction->bOutFunctionActive = b_FALSE;
      pToggleFunction->ActHypNr = HEADNoHypothesis;
    }
    else
    {
      if(pModule->eSMState == HEADSMState_ACTIVE)
      {
        uint16 uiModBitF = 0;
        const Hypothesis_t* pKinHyp = NULL;
        HEADHypothesisNr_t kinHypNr = HEADNoHypothesis;

        pToggleFunction->bOutFunctionActive = b_TRUE;
        
        uiModBitF = HEADGetActiveHypothesisForModule(pModule);
        kinHypNr = HEADGetMostCritHypOfBitfieldForModule(pInputData, uiModBitF, &pKinHyp, b_TRUE);

        pToggleFunction->ActHypNr        = kinHypNr;
        pToggleFunction->eEBAFctChannel  = HEADGetFctChannel(pKinHyp);
        pToggleFunction->eEBASignalState = HEADGetEBASignalState(pKinHyp);
      }
      else
      {
        pToggleFunction->bOutFunctionActive = b_FALSE;
        pToggleFunction->ActHypNr           = HEADNoHypothesis;
        pToggleFunction->eEBAFctChannel     = eEBAFctChan_Unknown;
        pToggleFunction->eEBASignalState    = eEBAOn_Inactive;
      }
    }
    
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }

  return retValue;
}

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/
