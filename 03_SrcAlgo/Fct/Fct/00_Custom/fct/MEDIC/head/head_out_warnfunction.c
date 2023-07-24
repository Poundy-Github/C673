/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_warnfunction.c

DESCRIPTION:               Implementation of the head generic warn function output

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/03/03 05:34:14CET $

VERSION:                   $Revision: 1.2.2.14 $

LEGACY VERSION:            1.15

**************************************************************************** */

/**
@defgroup  head_out_warnfunction HEAD_OUT_WARNFUNCTION
@ingroup Medic_head
@{ **/

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head/head_int.h"

/*****************************************************************************
SYMBOLIC CONSTANTS
*****************************************************************************/
/*! @brief       ONE_HALF
    @general     ONE_HALF
    @conseq      @incp   
                 @decp  ONE_HALF
    @attention   [None]
    @typical     0.5
    @unit        SI-unit
    
       */
#define ONE_HALF (0.5f) 

/*****************************************************************************
MACROS
*****************************************************************************/

/*****************************************************************************
TYPEDEFS
*****************************************************************************/


/*****************************************************************************
CONSTS
*****************************************************************************/

/*****************************************************************************
VARIABLES
*****************************************************************************/
/*!  @cond Doxygen_Suppress */
/*! @brief HEAD module output warning internal function structure for external warn function*/
SET_MEMSEC_VAR(extWarnFuncVal)
static HEADModuleOutputWarnFunctionInternal_t extWarnFuncVal;

/*! @brief HEAD Module output warning internal function structure for local warn function*/
SET_MEMSEC_VAR(locWarnFuncVal)
static HEADModuleOutputWarnFunctionInternal_t locWarnFuncVal;

/*! @brief Bool variable to indicate the dynamic acute warn module active or not.*/
SET_MEMSEC_VAR(bDynAcuteWarnModuleActive)
static boolean bDynAcuteWarnModuleActive;

/*! @brief head necessary acceleration .*/
SET_MEMSEC_VAR(HEADfAnec)
static float32 HEADfAnec;
/*! @endcond */
/*****************************************************************************
PROTOTYPES
*****************************************************************************/
static eGDBError_t HEADOutWarnFunctionInit(HEADModuleOutputWarnFunction_t *pWarnFunction);
static eGDBError_t HEADOutWarnArbitration(const struct HEADInputData_t *pInputData, 
                                          const struct HEADModule_t *pModule, 
                                          const HEADModOutWarnFunctionPar_t *pWarnFunctionPar);
/*****************************************************************************
DEFINES
*****************************************************************************/
#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)
#endif
/*****************************************************************************
FUNCTIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         HEADOutWarnFunctionInit                                                                     */ /*!

  @brief                custom output init function for Warn

  @description          custom output initialize function for Warn
                        
                        @startuml
                        Start
                           If(check pre warn function Availability ) then (Yes)
                           : initialize local and  external values;
                           Else (No)
                           :Return null pointer error;
                           Endif
                           :Return error type ;
                        Stop
                        @enduml

  @return               eGDBError_t    :GDB error type is returned

  @param[in,out]        pWarnFunction : pointer to output warning function

  @glob_in              None
  @glob_out             @ref extWarnFuncVal \n @ref locWarnFuncVal \n @ref bDynAcuteWarnModuleActive
                        @ref HEADfAnec \n @ref locHEADAcuteWarnSignal

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)
  
  @traceability         Design Decision

  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com 
*************************************************************************************************************************/
static eGDBError_t HEADOutWarnFunctionInit(/*Input*/ HEADModuleOutputWarnFunction_t *pWarnFunction) 
{
  eGDBError_t eError = GDB_ERROR_NONE;

  if(pWarnFunction != NULL)
  {
    /* Init local values */
    locWarnFuncVal.uActiveHyp                           = HEADNoHypothesis;
    locWarnFuncVal.eSignal                              = eEBAOn_Inactive;
    MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal = eEBAOn_Inactive;
    locWarnFuncVal.eFctChan                             = eEBAFctChan_Unknown;
    bDynAcuteWarnModuleActive                           = FALSE;
    HEADfAnec                                           = 1.0f;

    /* Init extern values */
    extWarnFuncVal.uActiveHyp                           = HEADNoHypothesis;
    extWarnFuncVal.eSignal                              = eEBAOn_Inactive;
    extWarnFuncVal.eFctChan                             = eEBAFctChan_Unknown;

    /* Connect extern values to interface */
    pWarnFunction->puActiveHyp                         = &(extWarnFuncVal.uActiveHyp);
    pWarnFunction->peSignal                            = &(extWarnFuncVal.eSignal);
    pWarnFunction->peFctChan                           = &(extWarnFuncVal.eFctChan);
  }
  else
  {
    eError = GDB_ERROR_POINTER_NULL;
  }
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADOutWarnFunction                                                                        */ /*!

  @brief                custom output function for Warn function

  @description          custom output function for a 3Level Warn output function (former iWarn5 and iWarn 6 functions)
                        @startuml
                        Start
                        :Fetch the Module Output;
                            Note left:Fetch the Module output for which the Warn function need to execute.
                        :Fetch the Module Output Parameter;
                        If (Is module already initialised?) then (No)
                            :Do Initialization;
                                Note left
                                    Initialize Warn Output for the Module.
                                End note
                        Else (no)
                            :Set Warn Output;
                                Note right:Set Warn Output based on Output Arbitration.
                        Endif
                        Stop
                        @enduml       

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            pInputData       : Ponter to input data
  @param[in]            pModule          : Pointer to head Module Structure
  @param[in]            bInit            : Find the flag status

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
eGDBError_t HEADOutWarnFunction( /*Input*/ const struct HEADInputData_t *pInputData,  
                                           const struct HEADModule_t *pModule, 
                                 /*Output*/ boolean bInit)
{
  //--------------------------------------------------------------------------------
  // Variable declaration -----------------------------------------------------------
  //---------------------------------------------------------------------------------
  eGDBError_t eError = GDB_ERROR_NONE;

  if ((pModule != NULL) && (pModule->pOutput != NULL) && (pModule->pOutputParams != NULL) )
  {
    HEADModuleOutputWarnFunction_t    *pWarnFunction    = (HEADModuleOutputWarnFunction_t *)((void *)pModule->pOutput);
    const HEADModOutWarnFunctionPar_t *pWarnFunctionPar = (const HEADModOutWarnFunctionPar_t *)(pModule->pOutputParams);

    if (bInit == TRUE)
    {
      // Do initialization for this output type
      eError = HEADOutWarnFunctionInit(pWarnFunction);
    }
    else
    {
      if( (pInputData != NULL) && (pWarnFunction != NULL) && (pWarnFunctionPar != NULL) )
      {
        // Run Warn State Machine 
        eError = HEADOutWarnArbitration(pInputData, pModule, pWarnFunctionPar);
      }
      else
      {
        eError = GDB_ERROR_POINTER_NULL;
      }
    }
  }
  else 
  {
    eError = GDB_ERROR_POINTER_NULL;
  }
  return eError;
}

/* ************************************************************************************************************************
  Functionname          HEADOutWarnArbitration                                                                      */ /*! 
  
  @brief                custom output function for Warn function
  
  @description          custom output function for Acute Warnings
                        
                        @startuml
                        Start
                            If (Check state machine state) then (Active)
                            If(Check pre warn availability) then (Yes)
                            if(Is necessary acceleration  stronger?) then (Yes)
                            :update current hypothesis information;
                            If( Is absolute velocity for signal state enable?) then (Enable)
                            If(Is pre warn hypothesis crossing type?) then (Yes)
                             :update absolute velocity with direction;
                            Note left
                            Input values are  vehicle velocity , acceleration etc 
                            and their signal type and quality
                            End note 
                            If(Is Velocity in Y direction > 0?) then (Yes)
                            :Cross Right direction to be updated; 
                            Else 
                            :Cross Left direction to be updated; 
                            Endif 
                            Endif
                            endif
                            If(check EBA Signal state is inactive) then (No)
                            :update eba signal to Internal structure of Output Warn Function; 
                            Else 
                            :update Lateral velocity with direction;
                            Endif
                            Else 
                            : Necessary acceleration of current hypothesis is not stronger;
                            endif
                            else
                            if(check active warn modules have hypothesis or not) then (Yes)
                            :Assign the external value to internal;
                            Endif
                            Endif
                            Endif
                            If(check last warn module status)then (Yes)
                            If(Is Dynamic Acute Warn Module Active? ) then (Yes)
                            :Assign to external variables;
                            Note right 
                            Set function channel when function channel is Unknown before
                            End note
                            Else 
                            :Reset external values;
                            Endif
                            Else
                            :Reset local values;
                            Endif
                            :return erroe type;
                        Stop
                        @enduml

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            pInputData       : Ponter to input data
  @param[in]            pModule          : Pointer to head Module Structure
  @param[in]            pWarnFunctionPar : Pointer to warning function parameter
  
  @pre                  None
  @post                 None

  @glob_in              None
  @glob_out             @ref HEADfAnec\n @ref extWarnFuncVal\n @ref locWarnFuncVal\n @ref bDynAcuteWarnModuleActive
                       

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision

  @author               Daniel Deitrich| Daniel.Deitrich@continental-corporation.com 

*************************************************************************************************************************/
static eGDBError_t HEADOutWarnArbitration(const struct HEADInputData_t *pInputData, 
                                           const struct HEADModule_t *pModule,
                                           const HEADModOutWarnFunctionPar_t *pWarnFunctionPar)
{
  eGDBError_t eError = GDB_ERROR_NONE;
  
  if((pModule->eSMState == HEADSMState_ACTIVE))
  {
    eEBASignalState_t prevlocHEADAcuteWarnSignal;
    const Hypothesis_t* pWarnHyp = NULL;
    uint16 uiModBitF             = HEADGetActiveHypothesisForModule(pModule);
    HEADHypothesisNr_t kinHypNr  = HEADGetMostCritHypOfBitfieldForModule(pInputData, uiModBitF, &pWarnHyp, TRUE);
    bDynAcuteWarnModuleActive    = TRUE;
    prevlocHEADAcuteWarnSignal   = MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal;

    if(pWarnHyp != NULL)
    {
      /*set values of current hyp to local values for this cycle if aNec is stronger*/
      if( pWarnHyp->fLongNecAccel <= HEADfAnec)
      {
        HEADfAnec                                              = pWarnHyp->fLongNecAccel;
        locWarnFuncVal.uActiveHyp                              = kinHypNr;
        locWarnFuncVal.eSignal                                 = HEADGetEBASignalState(pWarnHyp);
        MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal    = locWarnFuncVal.eSignal;
        locWarnFuncVal.eFctChan                                = HEADGetFctChannel(pWarnHyp);
        
        #if defined(HEAD_USE_ABSOLUTE_VEL_FOR_XING_SIGNAL) && (HEAD_USE_ABSOLUTE_VEL_FOR_XING_SIGNAL == MEDIC_ON)
        /*Calculate HEADAcuteWarnSignal with absolute velocity instead of relative velocity */
        /*PRQA S 2000 1*/
        if (pWarnHyp->eType == CDHypothesisType_Crossing)
        {
          HEADInputValueList_t* pInputValueList = pInputData->pInputValueList;
          float32 fVabsY = pWarnHyp->fVrelY + ((pWarnHyp->fDistX + HEAD_EGO_YAWRATE_COMPENSATION) * pInputValueList->YawRate.uValue.fValue);
          if (fVabsY > 0.f)
          {
            MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal = eEBAOn_CrossFrRight;
            locWarnFuncVal.eSignal = eEBAOn_CrossFrRight;
          }
          else
          {
            MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal = eEBAOn_CrossFrLeft;
            locWarnFuncVal.eSignal = eEBAOn_CrossFrLeft;
          }
        }
        #endif
        /*In case a cross warning has been triggered and the direction changes during one 
        Warning Event the previous Direction will be used*/
        if (  (prevlocHEADAcuteWarnSignal != MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal)
            &&(  (prevlocHEADAcuteWarnSignal == eEBAOn_CrossFrLeft)
               ||(prevlocHEADAcuteWarnSignal == eEBAOn_CrossFrRight))
            &&(  (MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal == eEBAOn_CrossFrLeft)
               ||(MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal == eEBAOn_CrossFrRight))
           )
        {
          MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal = prevlocHEADAcuteWarnSignal;
          locWarnFuncVal.eSignal                              = prevlocHEADAcuteWarnSignal;
        }
      }
      else
      {
        /* aNec of current hyp is not stronger than the one which is cached from another hyp*/
      }
    }
    else
    {
      /*Warnmodule is active without hyp*/
      if(locWarnFuncVal.uActiveHyp == HEADNoHypothesis)
      {
        /*No values have been set yet - set extern to intern values*/
        locWarnFuncVal.uActiveHyp    = HEADNoHypothesis;
        locWarnFuncVal.eSignal       = extWarnFuncVal.eSignal;
        locWarnFuncVal.eFctChan      = extWarnFuncVal.eFctChan;
      }
    }
  }
  else
  {
    MEDIC_p_GetEBASignalState()->locHEADAcuteWarnSignal = eEBAOn_Inactive;
  }

  if(pWarnFunctionPar->HEAD_LAST_WARN_MODULE == TRUE)
  {
    if(bDynAcuteWarnModuleActive == TRUE)
    {
      /* Set local values from warn-hyp to extern values */
      extWarnFuncVal.uActiveHyp    = locWarnFuncVal.uActiveHyp;
      extWarnFuncVal.eSignal       = locWarnFuncVal.eSignal;
      #if (HEAD_USE_CHANGE_FUNCTIONCHANNEL != MEDIC_ON)
      /*only set function channel when it's unknown before*/
      if(extWarnFuncVal.eFctChan == eEBAFctChan_Unknown)
      {
        extWarnFuncVal.eFctChan = locWarnFuncVal.eFctChan;
      }
      #else
      extWarnFuncVal.eFctChan      = locWarnFuncVal.eFctChan;
      #endif
    }
    else
    {
      /*Reset external values*/
      extWarnFuncVal.uActiveHyp    = HEADNoHypothesis;
      extWarnFuncVal.eSignal       = EBADynProp_NotAvail;
      extWarnFuncVal.eFctChan      = eEBAFctChan_Unknown;
    }

    /* Reset local values */
    locWarnFuncVal.uActiveHyp   = HEADNoHypothesis;
    locWarnFuncVal.eSignal      = EBADynProp_NotAvail;
    locWarnFuncVal.eFctChan     = eEBAFctChan_Unknown;
    bDynAcuteWarnModuleActive   = FALSE;
    HEADfAnec                   = 1.0f;
  }

  return eError;
}

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/ 
