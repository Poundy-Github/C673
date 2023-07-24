/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_main.c

DESCRIPTION:               Implementation of the head process

AUTHOR:                    $Author: Sekar, Balaji02 (uids6618) $

CREATION DATE:             $Date: 2020/11/10 12:50:20CET $

VERSION:                   $Revision: 1.56 $

LEGACY VERSION:            1.23.2.2 (HEAD 2.0)
  
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_HEAD20)
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head20/head20_int.h"
/*PRQA S 2982 EOF */ /*date: 2020-08-25, reviewer: Nalina M, reason: Suppressing because the value will be used in future.*/
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
/*!  @cond Doxygen_Suppress */
HEADHypothesisList_t HEADHypothesisList;
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
uint16 HypCheckEnableCondtions[HEAD_AUTO_CFG_NO_MODULES];
#endif

/*! @endcond */
/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void HEADDGSMSetStateTimer(struct HEADModule_t *pModule,const struct HEADInputData_t *pInputData);
static eGDBError_t HEADEvalOpModeForDegradationOverwrite( eHEADOpMode_t eOpMode, const HEADModuleList_t *const pModuleList);
static eGDBError_t HEADTransIteratorForConditions(const HEADModuleState_t * const pState);
static boolean HEADFindNextOutType(const HEADParameterEmpty_t *pParamListOriginal, HEADParamOutType_t eOutTypePrev,
                                   HEADParamOutType_t * eOutTypeNew, boolean bOutTypeFoundPrev);
static eGDBError_t HEADDGSMSortConditions(HEADConditionGrp_t *pConditionGrp);

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/****************************************************************************************************************************
  Functionname:         HEADRun                                                                                         */ /*!

  @brief                runs one HEAD loop for all modules

  @description          - check the SPM rules first and set the opmodes for the modules accordingly
                        - use external opmode to override the module opmodes
                        - for each module call the main handler function (from function pointer @ref HEADModuleCustomFunction_ft) 
                          and the output function (from function pointer @ref HEADModuleCustomOutput_ft)
                        - in case of a valid mts pointer, put internal data to mts structure
                        @startuml
                        Start
                        If ((Is InputData Pointer pointing NULL?) OR (Is ModuleList Pointer pointing  NULL?)OR
                        (Is Current Cycle count pointer pointing NULL?)) then (yes)
                          :Set Null Pointer Error;
                        Else (no)
                          :Fetch Module list from Input Data;
                          :Increase input cycle count;
                          #orange:collect Input Date
                          <b>HEADGetInputData</b> >
                          Note:gets data from VDATA
                          #orange:Run SPM Rules check
                          <b>HEADSPMRunCheck</b> >
                          Note: check all SPM rules and update state of modules
                          #orange:Run Custom Coding
                          <b>HEADCustomCoding</b> >
                          Note
                          check all custom coding conditions and decide whether any
                          module need to be degraded.
                          End note
                          #orange:Update Auto Code parameters
                          <b>HEADAutoCodeUpdateParams</b> >
                          Note:update Auto code parameters during runtime.
                          #orange:Evaluate Operating mode for Degradation
                          <b>HEADEvalOpModeForDegradationOverwrite</b> >
                          Note
                          Evaluate HEAD Operating mode and decide whether 
                          Degradation of modules needed or not.
                          End note 
                          while(LoopThroughAllModules to run their state machine function?)
                            #orange:Get Module information
                            <b>HEADGetModule</b> >
                            Note
                            Return a Module correspond to Module number 
                            from HEAD Module list.
                            Endnote
                            partition #LightBlue **((MEDIC_CFG_RTA_PROFILING)AND(MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))** {
                            #orange:set RTA event via service function
                            <b>VehAlgoServiceAddEvent</b> >
                            Note: RTA Event Algo start
                            }
                            If ((Is CurrentModule pointer valid?)) then (no)
                                :Set Null pointer Error;
                            Else (yes)
                              If ((Is CurrentModule internal Pointer Valid?) AND 
                        (Is CurrentModule internal Function Pointer Valid?)) then (yes)
                                #orange:call state machine function
                                <b>HEADGenericStateMachine</b> >
                                Note:Call to generic state machine through callback function 
                              Else (no)
                                :Set Null pointer Error;
                              EndIf
                            Endif
                          End while
                          partition #LightBlue **((MEDIC_CFG_RTA_PROFILING)AND(MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))** {
                          #orange:set RTA event via service function
                          <b>VehAlgoServiceAddEvent</b> >
                          Note: RTA Event Algo end
                          }
                          while(LoopThroughAllModules to run their output function?)
                            #orange:Get Module information
                            <b>HEADGetModule</b> >
                            Note
                            Return a Module correspond to Module number 
                            from HEAD Module list.
                            Endnote
                            partition #LightBlue **((MEDIC_CFG_RTA_PROFILING)AND(MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))** {
                            #orange:set RTA event via service function
                            <b>VehAlgoServiceAddEvent</b> >
                            Note: RTA Event Algo start
                            }
                            If ((Is CurrentModule pointer valid?)) then (no)
                                :Set Null pointer Error;
                            Else (yes)
                              If ((Is CurrentModule Output pointer valid?) AND (Is CurrentModule Output Function pointer valid?)) then (yes)
                                #orange:Call Output function connected to the Module >
                                Note:Call to output function through callback function
                              Else (no)
                                :Do nothing;
                                Note: No Output Function connected currently OK by specification
                              Endif
                              #orange:Increment/Reser state Timer for the module that has been evaluated
                              <b>HEADDGSMSetStateTimer </b> >
                            Endif      
                            partition #LightBlue **((MEDIC_CFG_RTA_PROFILING)AND(MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))** {
                            #orange:set RTA event via service function
                            <b>VehAlgoServiceAddEvent</b> >
                            Note: RTA Event Algo end
                            }
                          End while
                          If ((Is MTS Data pointer valid?) AND (Is Pointer to extra input value list valid?) AND 
                        (Is function pointer to function that writes the extra Input value valid?) AND 
                        (Is MTS static data pointer valid?) AND (Is MTS module common out data pointer valid?)) then (yes)
                            #orange:writes static header information to mts struct
                            <b>HEADMTSSendHeaderData</b> >
                            Note:Send HEAD Auto Version Number and HEAD MTS Output Data size to MTS
                            #orange:writes head parameter to head MTS output
                            <b>HEADMTSSendParameters</b> >
                            #orange:writes Module Number, Name and Type to MTS
                            <b>HEADMTSSendModuleName</b> >
                            #orange:writes State name to MTS
                            <b>HEADMTSSendStateName</b> >
                            #orange:writes Qos name to MTS
                            <b>HEADMTSSendQosName</b> >
                            #orange:writes reported error name to MTS
                            <b>HEADMTSSendErrorName</b> >
                            #orange:writes Module StateNameIndex to MTS
                            <b>HEADMTSSendModuleStateNameIndex</b> >
                            #orange:writes Module State Style Name to MTS
                            <b>HEADMTSSendStateStyleName</b> >
                            #orange:writes Precondition Name to MTS
                            <b>HEADMTSSendPreConditionName</b> >
                            #orange:writes Precondition Data to MTS
                            <b>HEADMTSSendPreConditionData</b> >
                            #orange:writes Precondition Parameter data to MTS
                            <b>HEADMTSSendPreCondParam</b> >
                            #orange:writes Module Common Data to MTS
                            <b>HEADMTSSendModuleCommonData</b> >
                            #orange:writes dynamic information from input signals to MTS
                            <b>HEADMTSSendInputSignals</b> >
                            #orange:writes SPM Rule to MTS(one SPM Rule per cycle)
                            <b>HEADMTSSendSPMRule</b> >
                            #orange:Writes dynamic information SPM Rule Time Count to MTS
                            <b>HEADMTSSendSPMRuleTimes</b> >
                            #orange:writes HEAD input data to MTS
                            <b>HEADMTSSendInputData</b> >
                            #orange:writes SPM Name to MTS
                            <b>HEADMTSSendSpmName</b> >
                            #orange:writes DGSM StateName to MTS
                            <b>HEADMTSSendDGSMStateName</b> >
                            #orange:writes HEAD transition data to MTS
                            <b>HEADMTSSendTransiitons</b> >
                            #orange:writes HEAD cfg to MTS
                            <b>HEADSendCfgToMTS</b> >
                          Endif
                        Endif
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or Null pointer Error

  @param[in]            fCycleTime : The function cycle time
  @param[in]            pInputData : pointer to all internal input data for HEAD module
  @param[in]            pExtraInputValues : pointer to extra input value list, that is not in the default pInputData.pInputValueList
  @param[in]            fpExtraValueFct : function pointer to a function that writes the pExtraInputValues to the mts output
  @param[in]            pMTSData : pointer to the mts data structure
  @param[in]            pMTSStaticData : pointer to the mts static data
  @param[in]            pHEADMTSModuleCommonOut : pointer to MTS Module Common Out data
  @param[out]           puiCurrCycleCnt : pointer to current cycle counter

  @glob_in              @ref HEADInputData
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_RTA_PROFILING \n
                        @ref MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  pInputData must be set, pModuleList must be set

  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1101-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
eGDBError_t HEADRun(const float32 fCycleTime, const struct HEADInputData_t *pInputData, const void *pExtraInputValues, 
                    HEADMTSSendExtraInputSignals_ft *fpExtraValueFct,                 
                    HEADMTSData_t *pMTSData, 
                    HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleCommonOut_t *pHEADMTSModuleCommonOut,
                    uint32 *puiCurrCycleCnt)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  eGDBError_t locError = GDB_ERROR_NONE;


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

    /*collect input data*/
    HEADGetInputData(fCycleTime);

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    /*collect input data*/
    HEADCheckNewHypothesis(pInputData);
#endif

    /* ------ run SPM ----- */
    locError = HEADSPMRunCheck(MEDIC_p_GetHEADInputData()->pSPMRules, pModuleList, MEDIC_p_GetHEADInputData()->fCycleTime);
    HEAD_UPDATE_ERROR(&retValue, locError);
    /* set custom coding information (after SPM, because it'll overwrite some information from SPM)*/
    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_CODING, 0);
    #endif 
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_CODING, 0);
    #endif
    locError = HEADCustomCoding(pModuleList->rgModules);
    HEAD_UPDATE_ERROR(&retValue, locError);
   
    /* ------ update parameters ------ */
    locError = HEADAutoCodeUpdateParams();
    HEAD_UPDATE_ERROR(&retValue, locError);
    
    locError = HEADEvalOpModeForDegradationOverwrite(pInputData->eOpMode, pModuleList);
    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_CODING, 0);
    #endif 
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_CODING, 0);
    #endif 
    HEAD_UPDATE_ERROR(&retValue, locError);
    #if HEAD_CFG_PRECONDITION == MEDIC_ON
    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_PRECONDITION, 0);
    #endif 
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_PRECONDITION, 0);
    #endif
    locError = HEADEvaluatePreCond(pInputData);
    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_PRECONDITION, 0);
    #endif 
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_PRECONDITION, 0);
    #endif 
    HEAD_UPDATE_ERROR(&retValue, locError);
    #endif 

    /* loop through all modules to run their state machines */
    for(uiModuleNr = 0u; (uiModuleNr < pModuleList->uiNrOfModules) ; uiModuleNr++)
    {
      HEADModule_t *pCurrModule = HEADGetModule(pModuleList, (uint32)uiModuleNr);

      #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
      #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)COMP_ID_FCT, (uint8)MEDIC_RTA_HEAD_MODULE, uiModuleNr);
      #else
      MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_GSM, uiModuleNr);
      #endif
      #endif

      if(pCurrModule == NULL)
      {
        locError = GDB_ERROR_POINTER_NULL;
      }
      else
      {
        /*work with this module*/
        /*****  only callback to generic state machine, no output callback, it will be done in individual state *****/
        if((pCurrModule->pInternal != NULL) && (pCurrModule->pInternal->InternalHeader.fpCustom != NULL))
        {
          /*! call state machine function @ref HEADDynamicGSM*/   
          locError =  (*(pCurrModule->pInternal->InternalHeader.fpCustom))(uiModuleNr, pInputData, b_FALSE);
        }
        else
        {
          /* Internal Module info not there => probably a problem in init */
          locError = GDB_ERROR_POINTER_NULL;
        }
      } 
    }

    #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)COMP_ID_FCT, (uint8)MEDIC_RTA_HEAD_MODULE, uiModuleNr);
    #else
    MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_GSM, uiModuleNr);
    #endif
    #endif
    HEAD_UPDATE_ERROR(&retValue, locError);
    /* loop through all modules to run their outputfunctions */
    for(uiModuleNr = 0u; (uiModuleNr < pModuleList->uiNrOfModules) ; uiModuleNr++)
    {
      HEADModule_t *pCurrModule = HEADGetModule(pModuleList, (uint32)uiModuleNr);
      if(pCurrModule == NULL)
      {
        locError = GDB_ERROR_POINTER_NULL;
      }
      else
      {
        /* Call Output Modules connected to the Module */
        if ((pCurrModule->pOutput != NULL) && (pCurrModule->pOutput->fpCustomOutput != NULL))
        {
          /*call custom output function for this module*/
          locError = (*(pCurrModule->pOutput->fpCustomOutput))(pInputData, pCurrModule, b_FALSE);
        }
        else
        {
          /* No Output Function connected => currently OK by specification */
        }
        /*Increment Timer for the module that has been evaluated*/
        HEADDGSMSetStateTimer(pCurrModule,pInputData);
      }
    } 
    HEAD_UPDATE_ERROR(&retValue, locError);

    if((pMTSData != NULL) && (pExtraInputValues != NULL) && (fpExtraValueFct != NULL) && (pMTSStaticData != NULL) && (pHEADMTSModuleCommonOut != NULL))
    {
      /*write parameter data to MTS*/
      locError = HEADMTSSendHeaderData(&(pMTSData->sMTSHeaderData));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendParameters(pInputData, pMTSStaticData, &(pMTSData->sMTSParamData));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendModuleName(pInputData, pMTSStaticData, &(pMTSData->sMTSModuleName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendStateName(pMTSStaticData, &(pMTSData->sMTSStateName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendQosName(pMTSStaticData, &(pMTSData->sMTSQosName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendErrorName(pMTSStaticData, &(pMTSData->sMTSErrorName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendModuleStateNameIndex(pMTSStaticData, &(pMTSData->sMTSModStateNameIndex));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendStateStyleName(pMTSStaticData, &(pMTSData->sMTSModuleStateStyleName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      #if (HEAD_CFG_PRECONDITION)
      locError = HEADMTSSendPreConditionName(pMTSStaticData, &(pMTSData->sMTSPreCondName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendPreConditionData(pInputData, &(pMTSData->sMTSPreCondData));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendPreCondParam(pInputData, pMTSStaticData, &(pMTSData->sMTSPreCondParam));
      HEAD_UPDATE_ERROR(&retValue, locError);
      #endif /*PreCondition*/

      locError = HEADMTSSendModuleCommonData(pInputData, pHEADMTSModuleCommonOut);
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendInputSignals(pInputData, pExtraInputValues, fpExtraValueFct, &(pMTSData->sMTSInputSignalList));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendSPMRule(pInputData, pMTSStaticData, &(pMTSData->sMTSSPMRule));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendSPMRuleTimes(pInputData, &(pMTSData->sMTSSPPMTimers));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendInputData(pInputData, &(pMTSData->sMTSInputData));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendSpmName(pMTSStaticData, &(pMTSData->sMTSSpmName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendDGSMStateName(pMTSStaticData, &(pMTSData->sMTSDGSMStateName));
      HEAD_UPDATE_ERROR(&retValue, locError);

      locError = HEADMTSSendTransitions(pInputData, pMTSStaticData, &(pMTSData->sMTSTransition));
      HEAD_UPDATE_ERROR(&retValue, locError);

      /*write head config to MTS*/
      (void) HEADSendCfgToMTS(pMTSStaticData, &(pMTSData->sMTSCfgData));
    }
  }

  return retValue;
}

/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADEvalOpModeForDegradationOverwrite                                                          */ /*!

  @brief                Evaluate HEAD operating Mode for module Degradation

  @description          Evaluate HEAD operating Mode state (Running, Shutdown or Stop) and acts accordingly on head module state
                        @startuml
                        Start
                        If ((HEAD_Operating Mode == Normal running)) then (yes)
                          :Do nothing;
                        Elseif ((HEAD_Operating Mode == ShutDown)) then (yes)
                          While(LoopThroughAllModules)
                            #orange:Get Module information
                            <b>HEADGetModule</b> >
                                Note
                                Return pointer to a Module correspond to Module number 
                                from HEAD Module list.
                                Endnote
                            If ((Is CurrentModule pointer valid?) AND 
                        (CurrentMod_QoS != Degradation_Stop)) then (yes)
                              :Set current Module QoS as Degradation ShutDown;
                            Else (no)
                              :Set NULL pointer error;
                            Endif
                          End while
                        Elseif ((HEAD_Operating Mode == stop)) then (yes)
                          While(LoopThroughAllModules)
                            #orange:Get Module information
                            <b>HEADGetModule</b> >
                            Note
                                Return pointer to a Module correspond to Module number 
                                from HEAD Module list.
                                Endnote
                            If ((Is CurrentModule pointer valid?)) then (yes)
                              :Set current Module QoS as Degradation stop;
                            Else (no)
                              :Set NULL pointer error;
                            Endif
                          End while
                        Endif
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            eOpMode : HEAD Operating mode
  @param[in]            pModuleList : pointer to Module list 

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  pInputData must be set, pModuleList must be set
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1109-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
/*PRQA L:DESIGN*/
static eGDBError_t HEADEvalOpModeForDegradationOverwrite( eHEADOpMode_t eOpMode, const HEADModuleList_t *const pModuleList) 
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADModule_t *pCurrModule= NULL;
  /* override SPM values with the operation mode */
  switch(eOpMode)
  {
  case HEADOpMode_Running:
    /*leave as it is*/
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


/****************************************************************************************************************************
  Functionname:         HEADReInit                                                                                      */ /*!

  @brief                re-initializes the modules

  @description          re-initializes the modules - Loop though all modules and initialize state machine and custom output 
                        function for all the modules.
                        @startuml
                        Start
                        :Set Local Error as none;
                        If ((Is InputData Pointer pointing NULL?) OR (Is ModuleList Pointer pointing  NULL?)) then (yes)
                            :Set Null pointer Error;
                        Else
                        while (LoopThroughAllModules?)
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
                        Endwhile
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
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1101-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
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
          retValue = (*(pCurrModule->pInternal->InternalHeader.fpCustom))(uiModuleNr, pInputData, b_TRUE);
        }
        else
        {
          /* Internal Module info not there => probably a problem in init */
          retValue = GDB_ERROR_POINTER_NULL;
        }

        /*init module outputs*/
        if ( (pCurrModule->pOutput != NULL) && (pCurrModule->pOutput->fpCustomOutput != NULL) )
        {
          retValue = (*(pCurrModule->pOutput->fpCustomOutput))(NULL, pCurrModule, b_TRUE);
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


/****************************************************************************************************************************
  Functionname:         HEADInititalize                                                                                  */ /*!

  @brief                Initializes the HEAD component

  @description          This function initializes HEAD cycle time and HEAD cycle count for the first time.
                        @startuml
                        Start
                        :Set localError as none;
                        If (Is Input Data Pointer pointing to NULL?) then (yes)
                          :Set Null Pointer Error;
                        Else (no)
                          :Initialize: \nHEAD cycle time and \nHEAD cycle count;
                        Endif
                        :Return localError;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if Input Data Pointer is valid, else return Null pointer Error

  @param[out]           pInputData  : Pointer to HEAD Input Data
  @param[in]            fCycleTime : The function cycle time

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1194-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
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


/****************************************************************************************************************************
  Functionname:         HEADInitialize                                                                                  */ /*!

  @brief                Initializes the HEAD component

  @description          The function initializes the HEAD component for the first time.
                        @startuml
                        Start
                        :Set localError as none;
                        #orange:Initialize MTS Static Date
                        <b>HEADMTSInit</b> >
                        :Clear HEAD Hypothesis List array;
                        If (Is ModuleList pointer valid?) then (yes)
                            #orange:Read Auto code
                            <b>HEADAutoCodeCreate</b> >
                            note:Set Module configurations and SPM Rules
                            if (Is any LocalError Detected?) then (no)
                                while ((LoopThroughAllModules and there should be No_Error)) is (Module_Index is valid)
                                #orange:Get Module information
                                <b>HEADGetModule</b> >
                                Note
                                Return a Module correspond to Module number 
                                from HEAD Module list.
                                Endnote
                                If (Is Module pointer valid?) then (yes)
                                    :Fetch Module internal state information;
                                Endif
                                If ((Is Module pointer valid?) AND (Is Module internal state information pointer valid?)) then (yes)
                                    :Initialize objectclass and DynamicProperty
                                    Of the module;
                                While ((LoopThroughAllStates of the Module and there should be No_Error)) is (State_Index is valid)
                                #orange:Get State information
                                <b>HEADGetModuleState</b> >
                                Note
                                Return Module State information correspond to 
                                State Index.
                                Endnote
                                #orange:Iterate through transitions of the state
                                to shot conditions
                                <b>HEADTransIteratorForConditions</b> >
                                Endwhile(State_Index not valid)
                                Else (no)
                                    :Set Null Pointer Error;
                                Endif
                                endwhile (Module_Index not valid)
                            Endif
                        Else (no)
                            :Set Null Pointer Error;
                        Endif
                        :Return localError;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or Null pointer Error

  @param[in]            pMTSStaticData  : Pointer to MTS static data
  @param[in]            pModuleList : Pointer to head module list

  @glob_in              @ref HEADInputData \n
                        @ref HEADExtraInputValueList
  @glob_out             @ref HEADHypothesisList

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1194-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
#if HEAD_CFG_PRECONDITION == MEDIC_ON
eGDBError_t HEADInitialize(HEADMTSStaticData_t *pMTSStaticData,
                          HEADModuleList_t *pModuleList, HEADPreConditionList_t* pPreCondList)
#else
eGDBError_t HEADInitialize(HEADMTSStaticData_t *pMTSStaticData,
                          HEADModuleList_t *pModuleList)
#endif
{
  uint8 uiHypoIndex;
  uint8 uiModuleIndex;
  HEADSMState_t uiStateIndex;
  eGDBError_t retValue = GDB_ERROR_NONE;

  /* MTSData */
  retValue = HEADMTSInit(pMTSStaticData);

  for(uiHypoIndex = 0u; uiHypoIndex < HEAD_MAX_NUMBER_OF_CD_HYPS; uiHypoIndex++)
  {
    HEADHypothesisList[uiHypoIndex].pHypothesis = NULL;
  }

  if(pModuleList != NULL)
  {
    /* --- parameters --- */

    /* modules */
    #if (HEAD_CFG_PRECONDITION == MEDIC_ON)
    retValue = HEADAutoCodeCreate(pModuleList, pPreCondList, MEDIC_p_ModHEADInputData(), &HEADExtraInputValueList);/*PRQA S 0315 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
    #else
    retValue = HEADAutoCodeCreate(pModuleList, MEDIC_p_ModHEADInputData(), &HEADExtraInputValueList); /*PRQA S 0315*//* uic42639, 19/11/2019, as per the QAC support document a 'pointer-to-object' can always be converted safely to a 'pointer-to-void'*/
    #endif
    if (retValue == GDB_ERROR_NONE)
    {
      HEADModule_t *pModule = NULL;
      HEADModuleInternalGSM_t *pInternalModule = NULL;
      HEADModuleState_t *pState;

      #if HEAD_CFG_PRECONDITION == MEDIC_ON
      uint8 uiPreCondIndex;
      for (uiPreCondIndex = 0; (uiPreCondIndex < HEAD_AUTO_CFG_NO_PRECONDS) && (retValue == GDB_ERROR_NONE); uiPreCondIndex++)
      {
          HEADPreCond_t *pPreCond = HEADGetPreCondition(pPreCondList,uiPreCondIndex);
          retValue = HEADDGSMSortConditions(&(pPreCond->rgPreCond));
      }
      #endif
      /*Reorganize parameter-pointer-list with HEADParamOutType_t-root and depending parameters
        and init values in the module-structure*/
      /*Loop Modules*/
      for(uiModuleIndex = 0; (uiModuleIndex < pModuleList->uiNrOfModules)&&(retValue == GDB_ERROR_NONE); uiModuleIndex++)
      {
        /*Pointer to the modules*/
        pModule = HEADGetModule(pModuleList, uiModuleIndex);
      
        if(pModule != NULL)
        { 
          /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
          pInternalModule = (HEADModuleInternalGSM_t *)((void *)pModule->pInternal);
        }

        if((pModule != NULL) && (pInternalModule != NULL))
        {
          /*Init values in the module-structure*/
          pInternalModule->ObjClassSelection =  OBJCLASS_INIT ; 
          pInternalModule->DynamicProperty   =  DYNAMICPROPERTY_INIT ;
          pInternalModule->ObjMovDir         =  OBJDIR_INIT;

          /*Loop States of the corresponding module*/
          for(uiStateIndex = 0; (uiStateIndex < pModule->uiNumModuleStates)&&(retValue == GDB_ERROR_NONE); uiStateIndex++)
          {
            /*Pointer to the states*/
            pState = HEADGetModuleState(pModule, uiStateIndex);   

            /* Iterate through each state for sorting conditions */
            retValue = HEADTransIteratorForConditions(pState);
          }
        }
        else
        {
          retValue = GDB_ERROR_POINTER_NULL;
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


/****************************************************************************************************************************
  Functionname:         HEADTransIteratorForConditions                                                                  */ /*!

  @brief                Iterate through transitions for a given state

  @description          Iterate through transitions for a given state to finally sort conditions.
                        @startuml 
                        Start
                        :Set localError as none;
                        If (Is State pointer valid?) then (valid)
                        While(LoopThroughTransition Of Corresponding State and there should be No_Error) is (TransitionIndex valid)
                          #orange:Get Corresponding Transition Information
                          <b>HEADGetStateTransition</b> >
                          Note
                          Return pointer to a Transition correspond to Transition Index 
                          from state's Transition list.
                          Endnote
                          If (Is Transition pointer valid?) then (valid)
                            While(LoopThroughConditionGroups) is (ConditionGrpIndex valid)
                              #orange:Get Condition Group 
                              <b>HEADGetConditionGrp</b> >
                              Note
                               Return pointer to a Condition Group correspond to Condition Group Index 
                               for corresponding Transition.
                              Endnote
                              If ((Is Condition Group Pointer vaild?) AND (Is Condition Group parameterList pointer valid?)) then (yes)
                                #orange:Sort conditions based on operator and outType
                                <b>HEADDGSMSortConditions</b> >
                                Note
                                Reorganize parameter-pointer-list with HEADParamOutType_t-root and 
                                Depending parameters
                                End note
                              Endif
                            End while (ConditionGrpIndex not valid) 
                          Else (Not valid)
                            :Set Null Pointer Error;
                          Endif         
                        End while (TransitionIndex not valid)
                        Else(Not valid)
                          :Set Null Pointer Error;
                        Endif
                        :Return localError;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or Null pointer Error

  @param[in]            pState : Pointer to Module State

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1137-0007e0f8}\n
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1110-0007e0f8}\n
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADTransIteratorForConditions(const HEADModuleState_t * const pState)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  uint8 uiTransitionIndex;
  uint8 uiConditionGrpIndex;
  HEADStateTransition_t *pTransition;
  HEADConditionGrp_t *pConditionGrp;

  if(pState != NULL)
  {
    /*Loop Transition of the corresponding state*/
    for(uiTransitionIndex = 0; (uiTransitionIndex < pState->uiNumTransitions)&&(retValue == GDB_ERROR_NONE); uiTransitionIndex++)
    {
      /*Pointer to the transitions*/
      pTransition = HEADGetStateTransition(pState, uiTransitionIndex);

      if(pTransition != NULL)
      {
        /*Loop Condition Groups of the corresponding state*/       
        for(uiConditionGrpIndex = 0; uiConditionGrpIndex < pTransition->uiNumConditionGroups; uiConditionGrpIndex++)
        {
          /*Pointer to the condition groups*/
          pConditionGrp = HEADGetConditionGrp(pTransition, uiConditionGrpIndex);

          if((pConditionGrp != NULL) && (pConditionGrp->pParameterList != NULL))  
          {
            /*Reorganize parameter-pointer-list with HEADParamOutType_t-root and depending parameters*/
            retValue = HEADDGSMSortConditions(pConditionGrp);
          }
        }
      }
      else
      {
        retValue = GDB_ERROR_POINTER_NULL;
      }
    }
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }

  return retValue;
}

/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADFindNextOutType                                                                             */ /*!

  @brief                Search the next suitable OutType from the condition list

  @description          Iterate through the condition list and try to find the OutType which is 
                        greater than eOutTypePrev but minimum from the rest.
                        @startuml
                        Start
                        :Set OutType to value ParameterOutTypeMax;
                        Note:Initial value
                        :Set OutType_found_flag as false;
                        While (Iterate Through Condition parameter list) is (condition available)
                          :Fetch the Parameter;
                          If (((Is current Parameter OutType > Previous OutType used for sorting) AND (Is any OutType Found Previously for the same conditional Group for sorting)) OR 
                        (No OutType Found Previously for the same conditional Group for sorting)) then (yes)
                            If ((current Parameter OutType < Last selected OutType)) then (yes)
                              :Set current Parameter OutType
                             as Out_Type;
                            Endif     
                          Endif
                          :Goto Next Parameter in the parameter list;
                        End while (No more condition)
                        If (((final_OutType > Previous OutType used for sorting) AND (final_OutType != ParameterOutTypeMax?)) OR
                        (No OutType Found Previously for the same conditional Group for sorting)) then (yes)
                          :Set OutType_found_flag as True;
                          :Set final_OutType as OutType for sorting;
                        Endif
                        :Return OutType_found_flag;
                        Stop
                        @enduml

  @return               boolean : Flag indicating if any new OutType found for sorting

  @param[in,out]        pParamListOriginal : Pointer to Parameter list
  @param[in]            eOutTypePrev : Previous OutType used for sorting
  @param[out]           eOutTypeNew : Next OutType for sorting
  @param[in]            bOutTypeFoundPrev : Flag indicating if any OutType found Previously for same conditional Group for sorting

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1109-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
/*PRQA L:DESIGN*/
static boolean HEADFindNextOutType(const HEADParameterEmpty_t *pParamListOriginal, HEADParamOutType_t eOutTypePrev,
                                    HEADParamOutType_t * eOutTypeNew, boolean bOutTypeFoundPrev)
{
  HEADParamOutType_t eOutType = (HEADParamOutType_t)HEADParamOutType_Max;
  boolean bOutTypeFound       = b_FALSE;

  /* iterate through the condition list and try to find the OutType which is 
     greater than eOutTypePrev but minimum from the rest */
  while(pParamListOriginal != NULL)
  {
    const HEADParameterType_t *const locParameterType = &(pParamListOriginal->ParameterType.sParameterType);

    if(((locParameterType->ParamOutType > (uint8)eOutTypePrev)&&(bOutTypeFoundPrev == b_TRUE))
       || (bOutTypeFoundPrev == b_FALSE))
    {
      if(locParameterType->ParamOutType < (uint8)eOutType)
      {
        eOutType = locParameterType->ParamOutType;
      }
    }
    pParamListOriginal = pParamListOriginal->ParameterType.pNextParam;
  }

  if(((eOutType > eOutTypePrev)&&(eOutType != (uint32)(HEADParamOutType_Max)))  /* found a new valid OutType greater than previous one */
     ||(bOutTypeFoundPrev == b_FALSE)) /* found a OutType for the first time */
  {
    bOutTypeFound    = b_TRUE;
    *eOutTypeNew     = eOutType;
  }
  return bOutTypeFound;
}



/****************************************************************************************************************************
  Functionname:         HEADDGSMSortConditions                                                                          */ /*!

  @brief                Rearrange the conditions list according to the operator and outType

  @description          This function loops through the parameterlist(conditionlist) in the current 
                        condition group and rearrange the list according to the operator and outType
                        operator: O , outType : T
                        Sorting is done by keeping OutType and Operator in increasing order.
                        Sorted list elements are linked using "pNextRelevantParam" pointer with no extra
                        memory elements used
                        Original list can be iterated using "pNextParam" pointer
                        @startuml 
                        Start
                        :Set localError as none;
                        #orange:While (Iterate the condition list in the increasing order of the OutType \n <b>HEADFindNextOutType</b>(Find the next OutType present in the list which is greater than previous OutType)) is (Parameter with OutType found)
                          :Update Parameter OutType and parameter
                         Found_flag;
                          While (Iterate through condition list with all possible Operator for the found OutType) is (OperatorIndex valid)
                            :Update condition list pointer for iteration 
                            with current Operator;
                            while (IterateThrough condition list) is (Condition available in the list)
                              if (Condition found with required OutType and Operator?) then (yes)
                                if (Is new Rootpointer pointing to Null?) then (yes)
                                  :Assign the current condition Pointer to RootPointer;
                                  Note:RootPointer is used to point the root condition for the corresponding OutType and Operator
                                Endif
                                If (Is pointer point the last condition parameter with same OutType and operator != Null?) then (yes)
                                  :Attach the current condition Parameter as 
                                  Relevant Parameter to Previous condition Parametr
                                  With same OutType and operator;
                                Endif
                                :Make the current condition Parameter as last condition Parameter
                                With same OutType and operator;
                              Endif
                              :Goto Next Parameter in the parameter list;  
                            End while (No Condition available in the list)
                          End while(OperatorIndex not valid) 
                        End while (Parameter OutType loop completed)
                        :update the tail of the new sorted list with NULL value;
                        :update the condition list root pointer to the sorted list root pointer;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns an error code.

  @param[in,out]        pConditionGrp : Pointer to HEAD Condition Group

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Input List:  [{O1,T1},{O2,T2},{O3,T3},{O2,T2},{O3,T3},{O1,T1},{O2,T2},{O1,T1}]\n
                        Output List: [{O1,T1},{O1,T1},{O1,T1},{O2,T2},{O2,T2},{O2,T2},{O3,T3},{O3,T3}].\n
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1140-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADDGSMSortConditions(HEADConditionGrp_t *pConditionGrp)
{
  eGDBError_t eError                   = GDB_ERROR_NONE;  
  HEADParameterEmpty_t *pParamRootList = pConditionGrp->pParameterList;
  HEADParameterEmpty_t *pRootPtrNew    = NULL; /* pointer to hold address of sorted list */
  HEADParameterEmpty_t *pIteratorOld   = NULL; /* iterator to iterate the old list */
  HEADParameterEmpty_t *pIteratorNew   = NULL; /* iterator to iterate the new sorted list */
  uint8 uiOperator = 0;
  uint8 uiOutType = 0;
  HEADParamOutType_t eOutValNew = 0;
  boolean bPrevOutValFound = b_FALSE;

  /* Find the next OutType present in the list which is greater than previous OutType
     and iterate the condition list in the increasing order of the OutType and Operator */
  while(b_FALSE != HEADFindNextOutType(pParamRootList,(HEADParamOutType_t)uiOutType,&eOutValNew,bPrevOutValFound))
  {
    /* update parameters for the next cycle */
    uiOutType = (uint8)eOutValNew;
    bPrevOutValFound = b_TRUE;

    /* Iterate through condition list with all possible Operator for the found OutType */
    for(uiOperator = 0; uiOperator < (uint8) HEADParamOperator_DEFAULT; uiOperator++)
    {
      /* Update condition list pointer for iteration with current Operator*/
      pIteratorOld = pParamRootList;

      /* Condition list iteration */
      while(pIteratorOld != NULL)
      {
        const HEADParameterType_t *const locParameterType = &(pIteratorOld->ParameterType.sParameterType);

        /*Found a condition in the list with required OutType and Operator */
        if((locParameterType->ParamOutType == uiOutType)
          &&(locParameterType->ParamOperator == uiOperator))
        {
          /* update the new sorted list base pointer */
          if(pRootPtrNew == NULL)
          {
            pRootPtrNew = pIteratorOld;
          }

          /* attach the found condition to the new list */
          if(pIteratorNew != NULL)
          {
            pIteratorNew->ParameterType.pNextRelevantParam = pIteratorOld;
          }
            
          pIteratorNew = pIteratorOld;
        }

        pIteratorOld = pIteratorOld->ParameterType.pNextParam;
      }
    }
  }

  /* update the tail of the new sorted list with NULL value */
  if(pIteratorNew != NULL)
  {
    pIteratorNew->ParameterType.pNextRelevantParam = NULL;
  }

  /* update the condition list root pointer to the sorted list root pointer */
  pConditionGrp->pParameterList = pRootPtrNew;

  return eError;
}

/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADUpdateHypothesisList                                                                         */ /*!

  @brief                Update head hypothesis list

  @description          Update HEAD hypothesis list and find the Number of Kinetic Hypothesis and 
                        the total number of CD Hypothesis.
                        @startuml
                        Start
                        :Set LocalError as None;
                        If ((CDHypothesis pointer != NULL) AND (Number of CDHypothesis > 0)) then (yes)
                        while (LoopThrough_CD_Hypo) is (Hypo_Index valid)
                            if ((Current_Hypo_Index < MAX_Number_CD_Hypo)) then (yes)
                              :Get Hypothesis corresponding to the 
                              index from CD Interface;
                              :copy the Hypothesis to corresponding index of 
                              HEAD Hypothesis list array;
                            If ((Is Hypothesis valid?) AND (Hypothesis Type != No_CD_Hypothesis)) then (yes)
                              :Increment kinematic hypotheses count;
                            Endif
                            Endif
                            :Increment total Hypothesis count;
                            :Set HEAD initialized flag as True;
                          End while (HypothesisIndex not valid)
                        Else (no)
                          If ((CDHypothesis pointer == NULL)) then (yes)
                            :Set Null pointer error;
                          Else (no)
                            :Set value outside range error;
                          Endif
                        Endif
                        :Return LocalError; 
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[out]           pMaxHypoIndex : Pointer to total CD Hypothsis Count
  @param[out]           pMaxHypKin : Pointer to Kinetic Hypothesis Count
 
  @glob_in              @ref MEDIC_p_GetHypothesisIntf() 
  @glob_out             @ref HEADHypothesisList \n
                        @ref bHEADInitialized

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1197-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/*PRQA L:DESIGN*/
eGDBError_t HEADUpdateHypothesisList(uint8 *pMaxHypoIndex, uint8 *pMaxHypKin)
{
  eGDBError_t eError = GDB_ERROR_NONE;  
  uint8 uiHypoIndex;

  /* make sure CD output hypothesis will be put into common hypothesis struct*/
  if ( (MEDIC_p_GetHypothesisIntf() != NULL) && (MEDIC_p_GetNumOfHyp() > 0u) )  /*PRQA S 3415*/
  {
    for (uiHypoIndex = 0u; uiHypoIndex < MEDIC_p_GetNumOfHyp(); uiHypoIndex++)
    {
      if (uiHypoIndex < HEAD_MAX_NUMBER_OF_CD_HYPS)
      {
        HEADHypothesisList[uiHypoIndex].pHypothesis = MEDIC_p_GetHypothesis(uiHypoIndex);
        if((HEADHypothesisList[uiHypoIndex].pHypothesis != NULL) && (MEDIC_e_GetHypType(&(HEADHypothesisList[uiHypoIndex])) != CDHypothesisType_No))
        {
          (*pMaxHypKin)++;
        }
      } /* else some error occured */
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

/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADDGSMSetStateTimer                                                                           */ /*!

  @brief                Increment Timer for States

  @description          Depending on Module GSM state the timers will be 
                        incremented or reset
                        Each module counts the seconds how long in the
                        current state and not in the current state.
                        @startuml
                        Start
                          While ((Loop Through All States of the module))
                          If (CurrentLoop_State == ModuleCurrent_State) then (yes)
                              :Increment Current state timer of the module;
                              :Reset module not in current state timer;
                            Else (no)
                              :Reset Current state timer of the module;
                              :Increment module not in current state timer;
                            Endif 
                          End while
                        Stop
                        @enduml

  @return               void

  @param[in,out]        pModule : pointer to HEAD Module
  @param[in]            pInputData : pointer to HEAD input data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1110-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/*PRQA L:DESIGN*/
static void HEADDGSMSetStateTimer(struct HEADModule_t *pModule,const struct HEADInputData_t *pInputData)
{
  HEADSMState_t      uiState;
  HEADModuleState_t *pState;
  HEADSMState_t      uiActualState;
  for (uiState=0; uiState < pModule->uiNumModuleStates; uiState++)
  {
    uiActualState = uiState + (HEADSMState_t)pModule->eNumModuleStateMin;
    pState = HEADGetModuleState(pModule, uiState);
    if (uiActualState == (HEADSMState_t) pModule->eDGSMState)
    {
      pState->fStateTimer              += pInputData->fCycleTime;   //inState
      pState->fNotInStateTimer          = 0.0f;                     //notInState
    }
    else
    {
      pState->fStateTimer               = 0.0f;                     //inState
      pState->fNotInStateTimer         += pInputData->fCycleTime;   //notInState
    }
  }
}

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
/****************************************************************************************************************************
  Functionname:         HEADCheckNewHypothesis                                                                         */ /*!

  @brief                Check for new Hypothesis

  @description          Check for new Hypothesis
                        @startuml
                        Start
                        While (Loop through all the Hypothesis)
                         :fetch Current Hypothesis data;
                         :fetch Current Hyp Type value;
                         :fetch Current Item ID value;
                         :Set BitMask;
                         If (Current Hyp Type != CDHypothesisType_No) then (yes)
                          If ((Current Hyp Type != Last Cycle Hyp Type) || (Current Item ID != Last Cycle Item ID)) then (yes)
                           While (Loop through all Modules)
                            :Set the corresponding Hypothesis bit as new Hypothesis;
                           End While
                          Endif
                         Else (no)
                          While (Loop through all Modules)
                           :Reset the corresponding Hypothesis bit;
                          End While
                         Endif
                         :Set Last Cycle HypType to Current HypType;
                         :Set Last Cycle ItemID to Current ItemID;
                        End While
                        Stop
                        @enduml

  @return               void

  @param[in,out]        None
  @param[in]            pInputData : pointer to HEAD input data

  @glob_in              @ref MEDIC_e_GetHypType() \n
                        @ref MEDIC_i_GetHypObjID()
  @glob_out             @ref HypCheckEnableCondtions

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @author               Balaji Sekar | balaji.2.sekar@continental-corporation.com
*************************************************************************************************************************/
static void HEADCheckNewHypothesis(const struct HEADInputData_t *const pInputData)
{
    uint8 uiCurrentHyp, uiModuleNr;
    uint16 BitMask;
    sint16 ItemID;
    t_HypothesisType HypType;
    const HEADHypothesis_t *pHyp = NULL;
    static t_HypothesisType LastCycleHypType[MAX_NUM_OF_HYPS];
    static sint16 LsatCycleItemID[MAX_NUM_OF_HYPS];

    for (uiCurrentHyp = 0u; (uiCurrentHyp < (uint8)MAX_NUM_OF_HYPS); uiCurrentHyp++)
    {
        pHyp = HEADGetHypothesis(pInputData->rgHypothesisList, uiCurrentHyp);
        HypType = MEDIC_e_GetHypType(pHyp);
        ItemID = MEDIC_i_GetHypObjID(pHyp);
        BitMask = (((uint16)1u << uiCurrentHyp));
        if (HypType != CDHypothesisType_No)
        {
            if ((HypType != LastCycleHypType[uiCurrentHyp]) || (ItemID != LsatCycleItemID[uiCurrentHyp]))
            {
                for (uiModuleNr = 0u; (uiModuleNr < HEAD_AUTO_CFG_NO_MODULES); uiModuleNr++)
                {
                    CML_SetBit(HypCheckEnableCondtions[uiModuleNr], BitMask);
                }
            }
        }
        else
        {
            for (uiModuleNr = 0u; (uiModuleNr < HEAD_AUTO_CFG_NO_MODULES); uiModuleNr++)
            {
                CML_ClearBit(HypCheckEnableCondtions[uiModuleNr], BitMask);
            }
        }
        LastCycleHypType[uiCurrentHyp] = HypType;
        LsatCycleItemID[uiCurrentHyp] = ItemID;
    }
}
#endif /*MEDIC_ARCHITECTURE_VERSION*/

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* MEDIC_CFG_HEAD20 */

