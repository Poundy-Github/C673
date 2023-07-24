/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_main.c

DESCRIPTION:               Implementation of the head process

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:57:10CEST $

VERSION:                   $Revision: 1.27 $

LEGACY VERSION:            1.25.1.2
  
**************************************************************************** */

/**
@defgroup head_main HEAD_MAIN
@ingroup Medic_head
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if !(MEDIC_CFG_HEAD20)

#include "head/head_int.h"

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

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
/*! @cond Doxygen_Suppress */
/*! @brief      Array of Head hypothesis, Size of array is @ref HEAD_MAX_NUMBER_OF_CD_HYPS */
HEADHypothesisList_t HEADHypothesisList;
/*! @endcond */
/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static eGDBError_t HEADEvalOpModeForDegradationOverwrite( eHEADOpMode_t eOpMode, const HEADModuleList_t *const pModuleList);
static void HEADGSMSetStateTimer(struct HEADModule_t *pModule, const struct HEADInputData_t *pInputData);

/*************************************************************************************************************************
  Functionname:         HEADRun                                                                                      *//*!

  @brief                runs one HEAD loop for all modules

  @description          use external opmode to override the module opmodes
                        For each module call the main handler function (from function pointer ref HEADModuleCustomFunction_ft) 
                        and the output function (from function pointer @ref HEADModuleCustomOutput_ft)
                        In case of a valid mts pointer, put internal data to mts structure
                        @startuml
                        Start
                            : Increase input cycle count;
                            : Degradation Overwrite;
                                Note right
                                Depends on external Operation mode, overwrite the 
                                SPM(signal performance monitor) values with the operation mode.
                                End note
                            : run state machines;
                                Note left
                                loop though all modules to run their state machines.
                                If RTA Events are needed, switch on the "MEDIC_CFG_RTA_PROFILING" and 
                                "MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS"
                                End note
                            : call custom output function;
                                Note right
                                loop though all modules to run their output functions.
                                If RTA Events are needed, switch on the "MEDIC_CFG_RTA_PROFILING" and 
                                "MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS"
                                End note
                            : write parameter data to MTS;
                                Note right
                                In case of a valid mts pointer, put internal data to mts structure  
                                End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[in]            pInputData              : pointer to all internal input data for HEAD module
  @param[in]            pExtraInputValues       : pointer to extra input value list, that is not in the default pInputData.pInputValueList
  @param[in]            fpExtraValueFct         : function pointer to a function that writes the pExtraInputValues to the mts output
  @param[in,out]        pMTSData                : pointer to the mts data structure
  @param[in,out]        pMTSStaticData          : pointer to the mts static data
  @param[in,out]        pHEADMTSModuleCommonOut : pointer to MTS Module Common Out data
  @param[in,out]        puiCurrCycleCnt         : pointer to current cycle counter

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_RTA_PROFILING \n 
                        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS \n
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pInputData must be set, pModuleList must be set
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADRun(const struct HEADInputData_t *pInputData, const void *pExtraInputValues, 
                    HEADMTSSendExtraInputSignals_ft *fpExtraValueFct, HEADMTSData_t *pMTSData, 
                    HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleCommonOut_t *pHEADMTSModuleCommonOut,
                    uint32 *puiCurrCycleCnt)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  if ( (pInputData == NULL) || (pInputData->pModuleList == NULL) || (puiCurrCycleCnt == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    uint8 uiModuleNr;
    const HEADModuleList_t *const pModuleList = pInputData->pModuleList;
    
    /* Increase input cycle count */
    (*puiCurrCycleCnt)++;

    retValue = HEADEvalOpModeForDegradationOverwrite(pInputData->eOpMode, pModuleList);


    /* loop though all modules to run their state machines */
    for(uiModuleNr = 0u; (uiModuleNr < pModuleList->uiNrOfModules); uiModuleNr++)
    {
      HEADModule_t *pCurrModule = HEADGetModule(pModuleList, (uint32)uiModuleNr);
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      MEDIC_v_AlgoServiceAddEvent(pFCTVehServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_HEAD_MODULE, uiModuleNr);
      #endif
      
      if(pCurrModule == NULL)
      {
        retValue = GDB_ERROR_POINTER_NULL;
      }
      else
      {
        /*work with this module*/
        if ((pCurrModule->pInternal != NULL) && (pCurrModule->pInternal->InternalHeader.fpCustom != NULL))
        {
          /*! call state machine function @ref HEADGenericStateMachine*/
          retValue = (*(pCurrModule->pInternal->InternalHeader.fpCustom))(uiModuleNr, pInputData, b_FALSE);
        }
        else
        {
          /* Internal Module info not there => probably a problem in init */
          retValue = GDB_ERROR_POINTER_NULL;
        }
      }
    }
    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    MEDIC_v_AlgoServiceAddEvent(pFCTVehServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_HEAD_MODULE, uiModuleNr);
    #endif

    /* loop though all modules to run their outputfunctions */
    for(uiModuleNr = 0u; (uiModuleNr < pModuleList->uiNrOfModules); uiModuleNr++)
    {
      HEADModule_t *pCurrModule = HEADGetModule(pModuleList, (uint32)uiModuleNr);
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      MEDIC_v_AlgoServiceAddEvent(pFCTVehServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, MEDIC_RTA_HEAD_MODULE, uiModuleNr);
      #endif
      if(pCurrModule == NULL)
      {
        retValue = GDB_ERROR_POINTER_NULL;
      }
      else
      {
        /* Call Output Modules connected to the Module */
        if ((pCurrModule->pOutput != NULL) && (pCurrModule->pOutput->fpCustomOutput != NULL))
        {
          /*call custom output function for this module*/
          retValue = (*(pCurrModule->pOutput->fpCustomOutput))(pInputData, pCurrModule, b_FALSE);
        }
        else
        {
          /* No Output Function connected => currently OK by specification */
        }
        /*Increment Timer for the module that has been evaluated*/
        HEADGSMSetStateTimer(pCurrModule, pInputData);
      }
      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      MEDIC_v_AlgoServiceAddEvent(pFCTVehServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, MEDIC_RTA_HEAD_MODULE, uiModuleNr);
      #endif
    }

    if((pMTSData != NULL) && (pExtraInputValues != NULL) && (fpExtraValueFct != NULL) && (pMTSStaticData != NULL) && (pHEADMTSModuleCommonOut != NULL))
    {
      /*write parameter data to MTS*/
      retValue = HEADMTSSendHeaderData(&(pMTSData->sMTSHeaderData));/*PRQA S 2982 8 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
      retValue = HEADMTSSendParameters(pInputData, pMTSStaticData, &(pMTSData->sMTSParamData));
      retValue = HEADMTSSendModuleName(pInputData, pMTSStaticData, &(pMTSData->sMTSModuleName));
      retValue = HEADMTSSendModuleCommonData(pInputData, pHEADMTSModuleCommonOut);
      retValue = HEADMTSSendInputSignals(pInputData, pExtraInputValues, fpExtraValueFct, &(pMTSData->sMTSInputSignalList));
      retValue = HEADMTSSendSPMRule(pInputData, pMTSStaticData, &(pMTSData->sMTSSPMRule));
      retValue = HEADMTSSendSPMRuleTimes(pInputData, &(pMTSData->sMTSSPPMTimers));
      retValue = HEADMTSSendInputData(pInputData, &(pMTSData->sMTSInputData));
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:          HEADEvalOpModeForDegradationOverwrite                                                       */ /*! 
  @brief                 HEAD Operation Mode examination and activities

  @description           Acts on the basis of the state (Running, Shutdown or Stop) of head module
                
                         @startuml
                         Start
                             If (check Operations mode type) then (yes) 
                             Note right
                             Operations modes are normal operation, normal deactivation and severe deactivation
                             End note
                             If(check operation mode is running in normal mode) then (Yes)
                             :keep it in same mode;
                             Else If(check operation mode is running in normal deactivation mode)  then (Yes)
                             while (check all modules) is (true)
                             :get current module;
                             If(check current module information availability)  then (Available)
                             : Update normal failure mode in the Qos state ;
                             Else
                             : update null pointer error;
                             endif
                             endwhile (false)
                             else (operation mode is running in severe failure mode)
                             while (check all modules) is (true)
                             :get current module;
                             If(check current module information availability)  then (Available)
                             : Update normal failure mode in the Qos state;
                             Else
                             : update null pointer error;
                             endif
                             endwhile (false)
                             endif
                             endif
                             :return the error type;
                         stop
                         @enduml

  @return                eGDBError_t  :GDB error type is returned

  @param[in]             eOpMode       : Operation mode
  @param[in]             pModuleList   : pointer to head module list
 
  @glob_in               None
  @glob_out              None 

  @c_switch_part         None
  @c_switch_full         @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                   pInputData must be set, pModuleList must be set

 @post                   None
 
  @InOutCorrelation      Not defined
  
  @testmethod            Test of output data (dynamic module test)

  @traceability          Design Decision
   
  @author                Robert Thiel | robert.thiel@contiautomotive.com

*************************************************************************************************************************/
/*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
static eGDBError_t HEADEvalOpModeForDegradationOverwrite( eHEADOpMode_t eOpMode, const HEADModuleList_t *const pModuleList) 
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADModule_t *pCurrModule= NULL;
  /* override SPM values with the operation mode */
  switch(eOpMode)
  {
  case HEADOpMode_Running:
    /*leave at it is*/
    break;

  case HEADOpMode_ShutDown:
    /*override with failure shutdown in case the module is not in "stop"*/
    {            
      uint8 uiModule;
      for(uiModule = 0u; uiModule < pModuleList->uiNrOfModules; uiModule++)
      {
        pCurrModule = HEADGetModule(pModuleList, (uint32)uiModule);
        if ((pCurrModule != NULL) && (pCurrModule->eQoS != HEADModuleQoS_DegradationStop)) /* Only escalate */
        {
          pCurrModule->eQoS = HEADModuleQoS_DegradationShutDown;
        }
        else
        {
          retValue = GDB_ERROR_POINTER_NULL;
        }
      }
    }
    break;

  case HEADOpMode_Stop:
  default: /* non defined state */
    /* override with failure stop */
    {
      uint8 uiModule;
      for(uiModule = 0u; uiModule < pModuleList->uiNrOfModules; uiModule++)
      {
        pCurrModule = HEADGetModule(pModuleList, (uint32)uiModule);
        if (pCurrModule != NULL)
        {
          pCurrModule->eQoS = HEADModuleQoS_DegradationStop;
        }
        else
        {
          retValue = GDB_ERROR_POINTER_NULL;
        }
      }
    }
    break;

  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADReInit                                                                                  */ /*!

  @brief                re-initializes the modules

  @description          re-initializes the modules - Loop though all modules and initialize state machine and custom output 
                        function for all the modules.
                        @startuml
                        Start
                        :Set Local Error as none;
                        If ((Is InputData NULL?) OR (Is ModuleList NULL?)) then (yes)
                            :Set Null pointer Error;
                        Else
                        partition LoopThoughAllModules {
                        while (LoopThoughAllModules?)
                        #orange:Get Module information
                        <b>HEADGetModule</b> >
                        Note
                        Return a Module correspond to Module number 
                        from HEAD Module list.
                        Endnote
                        If ((Is CurrentModule Valid?)) then (no)
                            :Set Null pointer Error;
                        Else (yes)
                            If ((Is CurrentModule internal Pointer Valid?) AND
                            (Is CurrentModule internal Function Pointer Valid?)) then (yes)
                            #orange:Init State Machine Function >
                            Note:CurrentModule internal Function call through Function Pointer
                            Else (no)
                            :Set Null pointer Error;
                            Note right: Internal Module info not there => probably a problem in init.
                            Endif
                            If ((Is CurrentModule Output pointer valid?) AND
                            (Is CurrentModule Output Function pointer valid?)) then (yes)
                            #orange:init Module Output Function >
                            Note:CurrentModule Output Function call through Function Pointer.
                            Else (no)
                            :Do nothing;
                            Note right: No Output Function connected => currently OK by specification
                            Endif
                        Endif
                        endwhile
                        }
                        Endif
                        :Return Local Error;
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or Null pointer Error

  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            pModuleList : pointer to Module list 
 
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
eGDBError_t HEADReInit(const struct HEADInputData_t *pInputData, const HEADModuleList_t *pModuleList)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pModuleList == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    uint8 uiModuleNr;
    for(uiModuleNr = 0u; uiModuleNr < pModuleList->uiNrOfModules; uiModuleNr++)
    {
      HEADModule_t *pCurrModule = HEADGetModule(pModuleList, (uint32) uiModuleNr);
      
      if(pCurrModule == NULL)
      {
        retValue = GDB_ERROR_POINTER_NULL;
      }
      else
      {
        /*init module vars...*/
        if((pCurrModule->pInternal != NULL) && (pCurrModule->pInternal->InternalHeader.fpCustom != NULL))
        {
          /*init state machine function*/
          retValue = (*(pCurrModule->pInternal->InternalHeader.fpCustom))(uiModuleNr,pInputData,b_TRUE);
        }
        else
        {
          /* Internal Module info not there => probably a problem in init */
          retValue = GDB_ERROR_POINTER_NULL;
        }

        /*init module outputs*/
        if ( (pCurrModule->pOutput != NULL) && (pCurrModule->pOutput->fpCustomOutput != NULL) )
        {
          retValue = (*(pCurrModule->pOutput->fpCustomOutput))(NULL, pCurrModule,b_TRUE);
        }
        else
        {
          /* No Output Function connected => currently OK by specification */
        }
      }
    }  
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADInititalize                                                                             */ /*!

  @brief                Initialize HEAD cycle time and HEAD cycle count

  @description          The function initializes HEAD cycle time and HEAD cycle count for the first time

                        @startuml
                        Start
                            :Initialize: \nHEAD cycle time and \nHEAD cycle count;
                        Stop
                        @enduml

  @return               eGDBError_t   :GDB error type is returned

  @param[in,out]        pInputData    : pointer to all internal input data for HEAD module
  @param[in]            fCycleTime    : The function cycle time
 
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
eGDBError_t HEADInititalize(struct HEADInputData_t *pInputData, float32 fCycleTime)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(pInputData == NULL)
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pInputData->fCycleTime = fCycleTime;
    pInputData->uiCurrentCycle = 0u;
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADInitialize                                                                               *//*!

  @brief                Initializes the HEAD component

  @description          The function initializes the HEAD component for the first time.
                        @startuml
                        Start
                            :Initialize MTS Date;
                            :Clear Hypothesis List;
                            :Copy Auto Code;
                                Note right: Copy the Auto generated code \n to internal structure
                            partition LoopThroughAllModules {
                            while (is the Module Number valid?) is (yes)
                            :Fetch the module;
                                Note left:Fetch a module from the list of modules.
                            :Fetch Internal GSM Information \n corresponding to the module;
                                Note right:Each module have corresponding pointer \n to an internal state information.
                            :Initialize GSM Information;
                                Note right:Initialize object class and Dynamic property to be considered, \n by default select all the object class and dynamic properties.
                                partition LoopThroughAllParameterOutType {
                                while (is the parameter Out type valid?) is (yes)
                                :Fetch the parameter list;
                                    Note left:Fetch the parameter list \n correspond to the module. 
                                    partition LoopThroughAllParameterInTheModule {
                                    while (is the parameter valid?) is (yes)
                                    :Fetch the Parameter;
                                        Note left:Parameter contains all the information corresponding \n to conditions related to the module.
                                    :Fetch Parameter Out Type and 
                                    Parameter Operator;
                                    :Group Relevant Parameters based on the parameter out Type
                                    and operation;
                                        Note right:parameters are grouped using linked list.
                                    endwhile(no)
                                    }
                                endwhile(no)
                                }
                            endwhile(no)
                            }
                        Stop
                        @enduml
          
  @return               eGDBError_t     :GDB error type is returned

  @param[out]           pMTSStaticData  : Pointer to MTS static data
  @param[out]           pModuleList     : Pointer to head module list

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
eGDBError_t HEADInitialize(HEADMTSStaticData_t *pMTSStaticData,
                          HEADModuleList_t *pModuleList)
{
  uint8 uiHypoIndex;
  uint8 uiModuleIndex;
  uint8 uiParameterIndex;
  eGDBError_t retValue = GDB_ERROR_NONE;

  /* MTSData */
  retValue = HEADMTSInit(pMTSStaticData);/*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */

  for(uiHypoIndex = 0u; uiHypoIndex < HEAD_MAX_NUMBER_OF_CD_HYPS; uiHypoIndex++)
  {
    HEADHypothesisList[uiHypoIndex].pHypothesis = NULL;
  }

  if(pModuleList != NULL)
  {
    /* --- parameters --- */

    /* modules */
    retValue = HEADAutoCodeCreate(pModuleList, MEDIC_p_ModHEADInputData(), &HEADExtraInputValueList);/*PRQA S 0315 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */

    if (retValue == GDB_ERROR_NONE)
    {
      HEADModule_t *pModule;
      HEADModuleInternalGSM_t *pInternalModule;
      HEADParamOutType_t eOutType;
      HEADParamOperator_t eOperator;
    
      /*Reorganize parameter-pointer-list with HEADParamOutType_t-root and depending parameters
        and init values in the module-structure*/
      /*Loop Modules*/
      for(uiModuleIndex = 0; uiModuleIndex < pModuleList->uiNrOfModules; uiModuleIndex++)
      {
        /*Pointer to the modules*/
        pModule = HEADGetModule(pModuleList, uiModuleIndex);
      
        if (pModule != NULL)
        {
          pInternalModule = (HEADModuleInternalGSM_t *)((void *)pModule->pInternal);/*PRQA S 0314 #date: 2020-06-02, reviewer: Nalina M, reason: Case to void intended as use of generic interface */
        }
        else
        {
          pInternalModule = NULL; /*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
        }
      
        if((pModule != NULL) && (pInternalModule != NULL))
        {    
          /*Init values in the module-structure*/
          pInternalModule->ObjClassSelection = OBJCLASS_INIT;
          pInternalModule->DynamicProperty   = DYNAMICPROPERTY_INIT;

          /*Reorganize parameter-pointer-list with HEADParamOutType_t-root and depending parameters*/
          /*Loop output Parameters*/
          for(uiParameterIndex = 0; uiParameterIndex < (uint8)HEADParamOutType_Max; uiParameterIndex++)
          {
            HEADParameterEmpty_t *pParam = pInternalModule->pParameterList;
            HEADParameterEmpty_t *pRootParam[HEADParamOperator_DEFAULT];
            pInternalModule->pRootPointerList[HEADParamOperator_LESSTHAN][uiParameterIndex]    = NULL;
            pInternalModule->pRootPointerList[HEADParamOperator_GREATERTHAN][uiParameterIndex] = NULL;
            pRootParam[HEADParamOperator_LESSTHAN] = NULL;
            pRootParam[HEADParamOperator_GREATERTHAN] = NULL;
            /*Loop input parameters*/
            while(pParam != NULL)
            {
              const HEADParameterType_t *const locParameterType = &(pParam->ParameterType.sParameterType);
              eOutType = locParameterType->ParamOutType;
              eOperator = locParameterType->ParamOperator;
              /*Parameter from enmum (root) == Parameter from List*/
              if(eOutType == (HEADParamOutType_t) uiParameterIndex)
              {           
                if(pInternalModule->pRootPointerList[eOperator][uiParameterIndex] == NULL)
                {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structures */

                  /*put first parameter pointer into the array*/
                  pInternalModule->pRootPointerList[eOperator][uiParameterIndex] = pParam;
                }
                else
                {/* PRQA S 0715 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing nesting of control structures */

                  /*attach pointers of depending outType-parameters to the last parameter in the list*/
                  pRootParam[eOperator]->ParameterType.pNextRelevantParam = pParam; 
                }
                /*new root parameter is the last one attached*/
                pRootParam[eOperator] = pParam;
              }
              /*set pParam to the next parameter in the input list*/
              pParam = ((const HEADParameterEmpty_t *)pParam)->ParameterType.pNextParam;
            }
          }
        }
      }
    }
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }

  return retValue;
}

/*************************************************************************************************************************
 Functionname:         HEADCreateModule                                                                              */ /*!

  @brief                Constructs and initialize a generic state machine module

  @description          Initialize basic module structure value, specific values 
                        are defined by autocode generated settings
                        @startuml
                        Start
                        :Set Error as None;
                        If (Is Module Pointer Valid?) then (no)
                            :Set NULL Pointer Error;
                        Else (yes)
                            If (ModuleNameString != NULL) then (yes)
                                : Copy module name;
                                Note right 
                                HEAD module name should be less than thirteen characters,  
                                and the strings are zero terminated.
                                End note
                            Else (no)
                                :No module name passed, set empty name;
                            Endif
                            : Initialize module data;
                            Note right
                            Initialize Module data such as Internal State Information, SMState, Qos, 
                            ReportedError, Moduele Output, and  Output Parameter.

                            Initialise head Internal State information as NULL,
                            currenr state as HEADSMState_OFF,
                            QOS to QoS_NormalRunning,
                            Errorstatus to NoError,
                            Module Output and Output parameter to NULL.
                            End note
                        Endif
                        :Return Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise error code correspond to
                                      NULL Pointer is returned

  @param[in]            strModuleName  : Module Name 
  @param[in,out]        pModule        : Pointer to a HEAD Module

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
eGDBError_t HEADCreateModule(const uint8 strModuleName[], struct HEADModule_t *pModule)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(pModule == NULL)
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    if (strModuleName != NULL)
    {
      uint8 uiI, uiLast = 0u;
      boolean bStop = b_FALSE;
      
      /* Copy module name, zero terminated string assumed */
      for (uiI = 0u; (uiI < (HEAD_MODULENAME_LENGTH-1u)) && (bStop == b_FALSE); uiI++)
      {
        if (strModuleName[uiI] != 0u)
        {
          pModule->strModuleName[uiI] = strModuleName[uiI];
          uiLast = uiI;
        }
        else
        {
          bStop = b_TRUE;
        }
      }  
      pModule->strModuleName[uiLast+1u] = 0u;
    }
    else
    {
      /* No module name passed, set empty name */
      pModule->strModuleName[0] = 0u;
    }

    /* Initialize module data */
    pModule->pInternal = NULL;
    pModule->eSMState = HEADSMState_OFF;
    pModule->eQoS = HEADModuleQoS_NormalRunning;
    pModule->eReportedError = HEADModuleRepError_NoError;
    pModule->pOutput = NULL;
    pModule->pOutputParams = NULL;
  }

  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADUpdateHypothesisList                                                                    */ /*!

  @brief                Update head hypothesis list

  @description          Update HEAD hypothesis list and find the Number of Kinetic Hypothesis and 
                        the total number of CD Hypothesis .
                        @startuml
                        Start
                        :Set Error as None;
                        If ((CDHypothesis != NULL) AND (Number of Hypothesis > 0)) then (yes)
                        partition LoopThrough_CD_Hypothesis {
                            if ((Current_HypothesisIndex < MAX_Number_CD_Hypothesis)) then (yes)
                                :Copy the list of Hypothesis from CD Module to\n HEAD internal Structure;
                                Note: Update Hypothesis List.
                                :Update the total Number of kinematic hypotheses;
                            Endif
                            :Update total number of Hypothesis from the CD Module;
                            :Set HEAD initialized flag as True;
                        }
                        Else (no)
                            If ((CDHypothesis == NULL)) then (yes)
                                :Set Null pointer error;
                            Else (no)
                                :Set Value range error;
                            Endif
                        Endif
                        :Return Error; 
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[in,out]        pMaxHypoIndex : Pointer to total CD Hypothsis Count
  @param[in,out]        pMaxHypKin : Pointer to Kinetic Hypothesis Count
 
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
eGDBError_t HEADUpdateHypothesisList(uint8 *pMaxHypoIndex, uint8 *pMaxHypKin)
{
  eGDBError_t eError = GDB_ERROR_NONE;  
  uint8 uiHypoIndex;

  /* make sure CD output hypothesis will be put into common hypothesis struct*/
  if ( (MEDIC_p_GetHypothesisIntf() != NULL) && (MEDIC_p_GetHypothesisIntf()->Header.uiNumOfHypotheses > 0u) )
  {
    for (uiHypoIndex = 0u; uiHypoIndex < MEDIC_p_GetHypothesisIntf()->Header.uiNumOfHypotheses; uiHypoIndex++)
    {
      if (uiHypoIndex < HEAD_MAX_NUMBER_OF_CD_HYPS)
      {
        const Hypothesis_t *pHyp = (&(MEDIC_p_GetHypothesisIntf()->Hypothesis[uiHypoIndex]));
        HEADHypothesisList[uiHypoIndex].pHypothesis = pHyp;
        if((pHyp != NULL) && (pHyp->eType != CDHypothesisType_No))/*PRQA S 2995 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
        {
          (*pMaxHypKin)++;
        }
      }/*else some error occured*/
      (*pMaxHypoIndex)++;
      bHEADInitialized = b_TRUE;
    }  
  }
  else
  {
    if(MEDIC_p_GetHypothesisIntf() == NULL)
    {
      eError = GDB_ERROR_POINTER_NULL;  
    }
    else
    {
      eError = GDB_ERROR_VALUE_RANGE;  
    }
  }

  return (eError);
}


/*************************************************************************************************************************
  Functionname:         HEADGSMSetStateTimer                                                                        */ /*!
  @brief                Increment Timer for States

  @description          Depending on actual Module and GSM state the     
                        timers will be incremented or reset.
                        Each module counts the seconds how long in the   
                        current state and not in the current state.
                        
                        @startuml
                        Start
                            while (check all modules state) is (true)
                            If(check global state machine state == current state)  then (Yes)
                            : update timer value in corresponding state timer 
                            and reset the notInState timer;
                            Else 
                            : update timer value in corresponding notInState timer
                            and reset the State timer;
                            endif
                            endwhile (false)
                        stop
                        @enduml

  @return               void

  @param[in,out]        pModule    : pointer to HEAD Module
  @param[in]            pInputData : pointer to HEAD input data
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  none
  @post                 none

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
static void HEADGSMSetStateTimer(struct HEADModule_t *pModule,
                                       const struct HEADInputData_t *pInputData)
{
  uint8 iState;

  for (iState=0; iState < (uint8)HEADSMState_Max; iState++)
  {
    if (iState == (uint8) pModule->eSMState)
    {
      pModule->fStateTimer[iState]     += pInputData->fCycleTime;   //inState
      pModule->fNotInStateTimer[iState] = 0.0f;                        //notInState
    }
    else
    {
      pModule->fStateTimer[iState]       = 0.0f;                       //inState
      pModule->fNotInStateTimer[iState] += pInputData->fCycleTime;  //notInState
    }
  }
}

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/
