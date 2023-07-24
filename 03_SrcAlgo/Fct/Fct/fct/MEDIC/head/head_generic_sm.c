/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_generic_sm.c

DESCRIPTION:               Implementation of the generic state machine of the HEAD module

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/10/26 11:10:10CET $

VERSION:                   $Revision: 1.35 $

LEGACY VERSION:            1.70
 
**************************************************************************** */
/**
@defgroup head_generic_sm HEAD_GENERIC_SM 
@ingroup Medic_head
@{ **/

#include "frame_medic/medic_int.h"

#if !(MEDIC_CFG_HEAD20)

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */

#include "head/head_int.h"
/*PRQA S 4391 EOF #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
/*PRQA S 0314 EOF #date: 2020-06-02, reviewer: Nalina M, reason: Case to void intended as use of generic interface */
/*PRQA S 4399 EOF #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
/*PRQA S 2995 EOF #date: 2020-06-11, reviewer: Nalina M, reason: Supressing the message result of this logical operation is always true*/
/*PRQA S 1891 EOF #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
/*PRQA S 1863 EOF #date: 2020-08-31, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
/*! @brief          Maximum State Machine time allowed in HEAD Module. 
                    @typical 99999.9f   @unit [SI-unit] 
*/
#define HEAD_MAX_STATE_TIME (99999.9f)

/*! @brief          Maximum time allowed for a function to be active in HEAD Module. 
                    @typical 9999.9f    @unit [SI-unit] 
*/
#define HEAD_MAX_FUNCTION_ACTIVE_TIME (9999.9f)

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/* ****************************************************************
    TYPEDEF ENUM eHEADSpecialBool_t
   **************************************************************** */
/*! @brief          HEAD Special Boolean 
    
    @conseq         Refer attention
    
    @attention      ordering is important!!! don't reorder this enum!!! The most relevant must be "false", the least relevant "not checked"
    */
typedef enum
{
  HEADSpecialBool_False      = 0, /*!< the return value is FALSE*/
  HEADSpecialBool_True       = 1, /*!< the return value is TRUE*/
  HEADSpecialBool_checked    = 2, /*!< the return value is not defined but there where checks that didn't affect this bool*/
  HEADSpecialBool_notchecked = 3  /*!< the return value is not defined and there where NO checks that could affect this bool -> it can be overwritten*/
} eHEADSpecialBool_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADGSMParamValues_t
   **************************************************************** */
/*! @brief          HEAD General State Machine Parameters Values
    */
typedef struct 
{
  float32               fVal;       /*!< float Value */
  float32               fFact;      /*!< Factorial value */
  float32               fDefVal;    /*!< Default value */
  eHEADParamOperator_t  eOperator;  /*!< Operator @ref eHEADParamOperator_t */
  uint16                uiBitPack;  /*!< BitPack */
  boolean               bUsed;      /*!< is particular Operator Used */
} HEADGSMParamValues_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADOtherModuleInState_t
    **************************************************************** */
/*! @brief          HEAD Other Module Rule Set Condition Information

    @description    Structure to collect rule set conditions for other Modules per OR-Group
    */
typedef struct 
{
  uint8                 uiNrOfChecksUsed;                   /*!< uiNrOfChecksUsed */
  uint16                uiBitPack[HEAD_AUTO_CFG_NO_OMIS];   /*!< uiBitPack */
  eHEADParamOperator_t  eOperator[HEAD_AUTO_CFG_NO_OMIS];   /*!< eOperator */
  float32               fInTime[HEAD_AUTO_CFG_NO_OMIS];     /*!< fInTime */
  float32               fFactor[HEAD_AUTO_CFG_NO_OMIS];     /*!< fFactor */
} HEADOtherModuleInState_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADThisModuleActive_t
    **************************************************************** */
/*! @brief          HEAD our Module Rule Set Condition Information

    @description    Structure to collect rule set conditions for this Modules per OR-Group
    */
typedef struct 
{
  boolean               bUsed;          /*!< bUsed */
  boolean               bUsedOverall;   /*!< bUsedOverall */
  eHEADParamOperator_t  eOperator;      /*!< eOperator */
  float32               fInTime;        /*!< fInTime */
  float32               fFactor;        /*!< fFactor */
  float32               fThreshold;     /*!< fThreshold */
} HEADThisModuleActive_t;


/*****************************************************************************
  CONSTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static eGDBError_t HEADGenericStateMachine(uint8 uiModuleNr, 
                                           const struct HEADInputData_t *pInputData, 
                                           boolean bInit);
static void HEADEvalStateTransitionOFF( uint8 uiModuleNr, 
                                       const struct HEADInputData_t * pInputData, 
                                       eHEADSMState_t *eNewState, eGDBError_t *retValue );
static void HEADEvalStateTransitionPassive( uint8 uiModuleNr, 
                                       const struct HEADInputData_t * pInputData, 
                                       eHEADSMState_t *eNewState, eGDBError_t *retValue );
static void HEADEvalStateTransitionActive( uint8 uiModuleNr, 
                                       const struct HEADInputData_t * pInputData, 
                                       eHEADSMState_t *eNewState, eGDBError_t *retValue );
static void HEADEvalStateTransitionWait( uint8 uiModuleNr, 
                                       const struct HEADInputData_t * pInputData, 
                                       eHEADSMState_t *eNewState, eGDBError_t *retValue );
static eGDBError_t HEADGSMConditions(uint8 uiModuleNr, 
                                     const struct HEADInputData_t *pInputData, 
                                     boolean *bConditionTrue, 
                                     eHEADParameterState_t eState);
static eGDBError_t HEADGSMConditionsGroup(uint8 uiModuleNr, 
                                          const struct HEADInputData_t *pInputData, 
                                          boolean *bConditionTrue,
                                          eHEADParameterState_t eState, 
                                          HEADParameterOrGroup_t uiOrGroup);
static void HEADGSMResetParamValOMIS(HEADOtherModuleInState_t *sParamValOMIS);
static void HEADGSMInitActiveFunction(HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT], 
                                      boolean initAll);
static void HEADGSMGetParametersToRelevantHyps(const struct HEADModule_t *pModule,
                                               HEADParameterHypothesisSub_t *rgHypUsed,
                                               HEADParameterOrGroup_t uiOrGroup,
                                               HEADParameterState_t eStateBit,
                                               const struct HEADInputData_t *pInputData);
static eGDBError_t HEADGSMCheckConditions(const struct HEADInputData_t *pInputData,
                                          uint8 uiModuleNr,
                                          const eHEADParameterState_t eState,
                                          HEADParameterOrGroup_t uiOrGroup,
                                          eHEADSpecialBool_t *pIntermediateResult,
                                          HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                          HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                          HEADHypothesis_t const *pHyp);
static void HEADGSMParamValidForEval( HEADParameterHypothesisSub_t hypSubType, 
                                      HEADParameterHypothesisSub_t bfParamHypSubType, 
                                      HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                      eHEADSpecialBool_t *eRetValue);
static eGDBError_t HEADGSMPlaceCurrentInfoIntoParamStruct(
                                      HEADGSMParamValues_t *sParamValGeneral,
                                      HEADOtherModuleInState_t *sParamValOMIS,
                                      HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                      const HEADParameterEmpty_t *pParam,
                                      const eHEADParamOutType_t eOutType,
                                      const float32 fValue);
static void HEADGSMResetParamValGeneral(HEADGSMParamValues_t *sParamValGeneral);
static eGDBError_t HEADGSMEvaluateGeneralParameters(eHEADSpecialBool_t *pIntermediateResult,
                                                    const HEADGSMParamValues_t *sParamValGeneral,
                                                    const uint8 uiOperator,
                                                    const uint8 uiModuleNr, 
                                                    const struct HEADInputData_t *pInputData, 
                                                    const HEADHypothesis_t *pHyp,
                                                    const eHEADParamOutType_t eOutType);
static eGDBError_t HEADGSMCheckOtherOrGroup(eHEADSpecialBool_t *pIntermediateResult,
                                            const struct HEADModule_t *pModule,
                                            const HEADGSMParamValues_t *sParamValGeneral,
                                            const eHEADParameterState_t eState);
static eGDBError_t HEADGSMEvaluateOtherModuleInState( eHEADSpecialBool_t *pIntermediateResult,
                                                      const struct HEADInputData_t *pInputData, 
                                                      const HEADOtherModuleInState_t *sParamValOMIS);
static void HEADGSMEvaluateActiveModuleTime(boolean *bConditionTrue,
                                            const HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                            const HEADModule_t *pModule,
                                            HEADParameterOrGroup_t uiOrGroup,
                                            eHEADParameterState_t eState);
static eGDBError_t HEADGSMGetParamResult( float32 fValue, float32 fFact, 
                                          float32 fParamValue, uint8 uiOperator, 
                                          boolean *bTempCondition);


/*************************************************************************************************************************
  Functionname:         HEADGenericStateMachine                                                                     */ /*!

  @brief                Main state machine function

  @description          Main function to execute Generic state machine.
                        It Evaluates needed state transition and do the state transition.  
                        @if DONOTGENERATEDOT  
                            @code
                                        -------------------------------------------------------------------
                                        |                                         SPM=EMERGENCY_FALSE     |
                                        |                                                                 |
                                        |                                                             --------
                                        |                                                         -----| WAIT |<----
                                        |                                                        /    --------      \
                                        |                       LeaveWait=True || KeepWait=False/                    \KeepActive=False || LeaveActive=True || (SPM=KEEP && timers=False) || SPM=SHUTDOWN
                                        |                                                      /                      \
                                        v                                                     V                        \
                                True  -------  SPM=OK/KEEP && InitCond=False            -----------                   ----------
                               o----->| OFF |------------------------------------------>| PASSIVE |------------------>| ACTIVE |
                                      -------                                           ----------- KeepPassive=FALSE ----------
                                        ^ ^                                                   |   && EnableCond=True     |
                                        | |                               SPM=EMERGENCY_FALSE |                          |
                                        | -----------------------------------------------------                          |
                                        |                                                  SPM=EMERGENCY_FALSE           |
                                        ----------------------------------------------------------------------------------
                            @endcode
                        @else
                            @dot 
                            digraph main_state_machine {
                            node [shape=point fontsize=10];
                            start;
                            node [shape=box fontsize=10];
                            off [ label="OFF" URL="\ref HEADSMState_OFF"];
                            passive [ label="PASSIVE" URL="\ref HEADSMState_PASSIVE"];
                            active [ label="ACTIVE" URL="\ref HEADSMState_ACTIVE"];
                            wait [ label="WAIT" URL="\ref HEADSMState_WAIT"];
                            start -> off [ label = "on entry" fontsize=10];
                            off -> passive [ label = "SPM = (OK or KEEP) \nand InitCod = False" fontsize=10 URL="\ref HEADModuleQoS_NormalRunning"];                
                            passive -> active [ label = "EnableCond = true" fontsize=10 URL="\ref HEADGSMConditions"];
                            passive -> off [ label = "SPM = FailureStop" fontsize=10 URL="\ref HEADModuleQoS_DegradationStop"];
                            active -> off [ label = "SPM = FailureStop" fontsize=10 URL="\ref HEADModuleQoS_DegradationStop"];
                            active -> wait [ label = "(SPM = (OK or KEEP) \nand KeepCond = False) \nor SPM = SHUTDOWN" fontsize=10 URL="\ref HEADGSMConditions"];
                            wait -> passive [ label = "WaitCond = false" fontsize=10 URL="\ref HEADGSMConditions"];
                            wait -> off [ label = "SPM = FailureStop" fontsize=10 URL="\ref HEADModuleQoS_DegradationStop"];
                            }
                            @enddot
                        @endif
                        <a href="doors://lndp160a.cw01.contiwan.com:40000/?version=1,prodID=0,dbid=434fc2ac40537bd7,container=00009120,object=2536">link to doors requirement</a>

                        @startuml
                        Start
                        :Get Module Data;
                        Note: Get module Data for which the Generic\n State machine need to be executed.
                        If ((Check for valid module Data AND Input Data?)) then (not valid) 
                            If (Is Module pointing to Null?) then (no)
                                :Set Module QoS to Stop;
                            endif
                        else(valid)
                            :Fetch Module GSM Information;
                            If (check if re-initialization is ordered?) then (yes)
                                :Reset Initialization;
                                Note 
                                Once you reset the initialization, 
                                ReInitialization will be done in the next call.
                                End note 
                            Else
                                If (check if initialized?) then (no)
                                    :Do Initialize Module;
                                Endif
                                partition Evaluate_State_Transition {
                                Note
                                Evaluate if any state transition
                                is needed or not.
                                end note
                                if(CurrentState==State_Off)
                                    :Evaluate State Transition\n at Off State;
                                Elseif(CurrentState==State_Passive)
                                    :Evaluate State Transition\n at Passive State;
                                Elseif(CurrentState==State_Active)
                                    :Evaluate State Transition\n at Active State;
                                Elseif(CurrentState==State_Wait)
                                    :Evaluate State Transition\n at Wait State;
                                Else
                                    :Evaluate State Transition\n at Off state;
                                Endif
                                }
                                If (Check if any error?) then (no)
                                    :Save current state as last state;
                                    :Do State Transition;
                                    Note:Do state transition based on the outcome of\n Evaluate_State_Transition.
                                Else(yes)
                                    :Set module QoS to stop;
                                    :Do State Transition
                                    to Stop State;
                                endif
                            Endif
                        endif
                        Stop
                        @enduml
 
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned.

  @param[in]            uiModuleNr : Module Number 
  @param[in]            pInputData : Pointer to Input data
  @param[in]            bInit : Boolean indicates Re-Initialization initated or not
  
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
static eGDBError_t HEADGenericStateMachine(uint8 uiModuleNr, const struct HEADInputData_t *pInputData, boolean bInit)
{
  eHEADSMState_t eNewState;
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADModule_t * pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);/*PRQA S 2812 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Supressing for better code maintainability*/

  if (   (pModule == NULL) 
      || (pInputData == NULL)
      || (pModule->pInternal == NULL)
      || (pModule->pInternal->InternalHeader.eModuleInternalType != HEADModuleInternalType_GSM) 
      || (((HEADModuleInternalGSM_t *)(void*)(pModule->pInternal))->pParameterList == NULL) )
  {
    retValue = GDB_ERROR_POINTER_NULL;
    if (pModule!= NULL) /* Save consistent QoS due to internal error */
    {
      pModule->eQoS = HEADModuleQoS_DegradationStop;
    }
  }
  else
  { 
    HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

    /* check if re-init is ordered => reset, initialization will be done in the next call*/
    if (bInit == b_TRUE)
    {
      pModuleInt->bInitialized = b_FALSE;
      pModuleInt->sAdditionalTableInputs.fHostSpeedLastStateTransition = 0.0f;
      pModuleInt->sAdditionalTableInputs.bHostSpeedLastStateTransitionOK = b_FALSE;
    }
    else
    {
      /* no re-init is ordered => ensure initialization if not yet done*/
      if(pModuleInt->bInitialized == b_FALSE)
      {
        /* initialize */
        const uint16 uiMaxTimer = (uint16)(2u*(pModule->uiNumOrGroups));
        (void)MEDIC_MEMSET(pModuleInt->pfConditionsOKTimer,0, sizeof(float32)*uiMaxTimer);/*PRQA S 2869, 0315 2 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
        (void)MEDIC_MEMSET(pModule->fNotInStateTimer,      0, sizeof(pModule->fNotInStateTimer));
        pModule->eSMState = HEADSMState_OFF;
        pModuleInt->bInitialized = b_TRUE;
      }
      
      /* now it's initialized */
      /*=====================  state transitions ========================*/
      switch(pModule->eSMState)
      {
      case HEADSMState_OFF:
        {
          HEADEvalStateTransitionOFF(uiModuleNr, pInputData, &eNewState, &retValue);
          break;
        }
      case HEADSMState_PASSIVE:
        {
          HEADEvalStateTransitionPassive(uiModuleNr, pInputData, &eNewState, &retValue);
          break;
        }
      case HEADSMState_ACTIVE:
        {
          HEADEvalStateTransitionActive(uiModuleNr, pInputData, &eNewState, &retValue);
          break;
        }
      case HEADSMState_WAIT:
        {
          HEADEvalStateTransitionWait(uiModuleNr, pInputData, &eNewState, &retValue);
          break;
        }
      case HEADSMState_Max:
      default:
        {
          retValue = GDB_ERROR_UNKNOWN_TYPE;
          eNewState = HEADSMState_OFF;/*PRQA S 2983 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
          break;
        }
      }

      if (retValue == GDB_ERROR_NONE) 
      {
        pModule->eSMLastState = pModule->eSMState;
        HEADDoStateTransition(eNewState, pInputData, pModule, &retValue);
      }
      else
      {
        pModule->eQoS = HEADModuleQoS_DegradationStop;
        HEADDoStateTransition(HEADSMState_OFF, pInputData, pModule, &retValue);
      }
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADEvalStateTransitionOFF                                                                  */ /*!

  @brief                Evaluate if there is a state transition if in state OFF

  @description          Evaluate if there is a state transition if in state OFF
                        Module is assumed to be in State "Off" if this function is called.
                        
                        Method created in refactoring.
                        No Pointer checks are performed for pModule, pInputData, eNewState, retValue
                        => assert that all pointers are valid in calling functions.
                        @startuml
                        Start
                        :Get Module information;
                        If ((Module_Qos==NormalRunning) OR 
                        (Module_Qos==DegradationKeep)) then (yes)
                            :Check GSM Conditions;
                            Note left
                            ->check if the enable conditions are met.
                            ->Update Init Keep Condition. 
                        End note
                            If((Error==None) AND (InitKeep==False)) then (yes)
                                :Set New State as Passive;
                            Elseif ((Error==None)) then (yes)
                                :Set New State as OFF State;
                                Note: No error but Conditions not met.
                            Else (Error case)
                                :Set QoS of Module to Degradation stop;
                                :Set New State as OFF State;
                            endif
                        Else(no)
                            :Set New state as OFF State 
                            No change in QoS needed;
                            :Set Error as None;
                        endif
                        Stop
                        @enduml

  @return               void

  @param[in]            uiModuleNr : Module Number
  @param[in]            pInputData : Pointer to Input data
  @param[out]           eNewState : Pointer to New State 
  @param[in,out]        retValue : Pointer to GDB Error code
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Clemens Schnurr | clemens.schnurr@continental-corporation.com
*************************************************************************************************************************/
static void HEADEvalStateTransitionOFF( uint8 uiModuleNr, 
                                        const struct HEADInputData_t * pInputData, 
                                        eHEADSMState_t *eNewState, eGDBError_t *retValue ) 
{  
  boolean bModuleDoInit = b_FALSE;
  HEADModule_t * pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);

  if ((pModule->eQoS == HEADModuleQoS_NormalRunning) || (pModule->eQoS == HEADModuleQoS_DegradationKeep))
  {
    *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleDoInit, HEADParameterState_Init);
    /* go to passive if init keep condition is false*/
    if ((*retValue == GDB_ERROR_NONE) && (bModuleDoInit == b_FALSE))
    {
      /*go to PASSIVE*/
      *eNewState = HEADSMState_PASSIVE;
    }
    else if (*retValue == GDB_ERROR_NONE) /* No error but Conditions not met */
    {
      *eNewState = HEADSMState_OFF;
    }
    else /* Error case */
    {
      pModule->eQoS = HEADModuleQoS_DegradationStop;
      *eNewState = HEADSMState_OFF;
    }
  }
  else
  {
    /* Keep state in OFF no change in QoS needed */
    *eNewState = HEADSMState_OFF;
    *retValue = GDB_ERROR_NONE;
  }

}


/*************************************************************************************************************************
  Functionname:         HEADEvalStateTransitionPassive                                                              */ /*!

  @brief                Evaluate if there is a state transition if in state Passive

  @description          Evaluate if there is a state transition if in state Passive
                        Module is assumed to be in State "Passive" if this function is called.
                        
                        Method created in refactoring. 
                        No Pointer checks are performed for below pointers, assert that all pointers are 
                        valid in calling functions  
                        pModule, pInputData, eNewState, retValue
                        @startuml
                        Start
                        :Get Module information;
                        If (Check if Module Qos is Normal?) then (yes)
                            :Check GSM Conditions for Keep Passive State;
                            If ((No_Error) AND (Keep_Passive==False)) then (yes)
                                :Check GSM Conditions for Enable;
                                If ((No_Error) AND (Enable==True)) then (yes)
                                    :Set New State as Active;
                                Elseif ((No_Error)) then (yes)
                                    :Set New State as Passive;
                                    Note: No error but Conditions not met
                                Else
                                    :Set New State as OFF;
                                    note: Error Case
                                    :Set QoS of Module to Degradation stop;
                                Endif
                            Elseif((No_Error)) then (yes)
                                :Set New State as Passive;
                                Note: No error but Conditions not met
                            Else
                                :Set New State as OFF;
                            note: Error Case
                                :Set QoS of Module to Degradation stop;
                            Endif
                        Elseif ((Module_Qos==Degradation_Stop) OR
                        (Module_Qos==Degradation_ShutDown)) then (yes)
                            :Set New State as OFF;
                            Note: Module is already in Degradation Stop or ShutDown
                            :Return Error as None;
                        Else
                            :Set New State as Passive;
                            :Return Error as None;
                        Endif
                        Stop
                        @enduml
       
  @return               void 

  @param[in]            uiModuleNr : Module Number
  @param[in]            pInputData : Pointer to Input data
  @param[out]           eNewState : Pointer to New State
  @param[out]           retValue : Pointer to GDB Error code
  
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
static void HEADEvalStateTransitionPassive( uint8 uiModuleNr, 
                                           const struct HEADInputData_t * pInputData, 
                                           eHEADSMState_t *eNewState, eGDBError_t *retValue ) 
{

  boolean bModuleEnable = b_FALSE;
  boolean bModuleKeepPassive = b_TRUE;
  HEADModule_t * pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);
  /*check if qos is good enough*/
  if(pModule->eQoS == HEADModuleQoS_NormalRunning)
  {
    /*go to ACTIVE if KeepPassive is false and Enable is true*/
    
    /*keep in PASSIVE if KeepPassive conditions are true*/
    *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleKeepPassive, HEADParameterState_KeepPassive);
    if ((*retValue == GDB_ERROR_NONE) && (bModuleKeepPassive == b_FALSE))
    {
      /*go to ACTIVE if enable conditions are true*/
      *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleEnable, HEADParameterState_Enable);
      if ((*retValue == GDB_ERROR_NONE) && (bModuleEnable == b_TRUE))
      {
        /*go to ACTIVE*/
        *eNewState = HEADSMState_ACTIVE;
      }
      else if ((*retValue == GDB_ERROR_NONE))
      {
        /*keep in PASSIVE*/
        *eNewState = HEADSMState_PASSIVE;
      }
      else
      {
        *eNewState = HEADSMState_OFF;
        pModule->eQoS = HEADModuleQoS_DegradationStop;
      }
    }
    else if (*retValue == GDB_ERROR_NONE) /* No error but Conditions not met */
    {
      *eNewState = HEADSMState_PASSIVE;
    }
    else /* Error case */
    {
      *eNewState = HEADSMState_OFF;
      pModule->eQoS = HEADModuleQoS_DegradationStop;
    }
  }
  else if( (pModule->eQoS == HEADModuleQoS_DegradationStop) || (pModule->eQoS == HEADModuleQoS_DegradationShutDown) )
  {
    /*go to OFF*/
    *eNewState = HEADSMState_OFF;
    *retValue = GDB_ERROR_NONE;
  }
  else
  {
    /*keep in PASSIVE*/
    *eNewState = HEADSMState_PASSIVE;
    *retValue = GDB_ERROR_NONE;
  }
}


/************************************************************************************************************************
  Functionname:         HEADEvalStateTransitionActive                                                              */ /*!

  @brief                Evaluate if there is a state transition if in state Active

  @description          Evaluate if there is a state transition if in state Active
                        Module is assumed to be in State "Active" if this function is called.
                        
                        Method created in refactoring. 
                        No Pointer checks are performed for following pointers, assert that all pointers are 
                        valid in calling functions.
                        pModule, pInputData, eNewState, retValue
                        @startuml
                        Start
                        :Get Module information;
                        If (Check if Module QoS good enough for Active State?) then (yes)
                            :Check GSM Conditions for Leave Active State;
                            If ((No_Error) AND (Leave_Active==True)) then (yes)
                                :Set New State as Wait;
                            Elseif ((No_Error)) then (yes)
                                :Check GSM Conditions for Keep Active State;
                                If ((No_Error) AND (Keep_Active==False)) then (yes)
                                    :Set New State as Wait;
                                    Note:Go to wait if Keep Active is false
                                Elseif ((No_Error)) then (yes)
                                    :Set New State as Active;
                                Note:No error and Conditions met
                                Else
                                    :Set New State as OFF;
                                    Note: Error Case
                                    :Set QoS of Module to Degradation stop;
                                Endif
                            Else
                                :Set New State as OFF;
                                Note: Error Case
                                :Set QoS of Module to Degradation stop;
                            Endif
                        Else (no)
                            :Set New State as OFF;
                            :Return Error as None;
                        Endif
                        Stop
                        @enduml                       
       
  @return               void 

  @param[in]            uiModuleNr : Module Number
  @param[in]            pInputData : Pointer to Input data
  @param[out]           eNewState : Pointer to New State
  @param[out]           retValue : Pointer to GDB Error code
  
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
static void HEADEvalStateTransitionActive( uint8 uiModuleNr, 
                                          const struct HEADInputData_t * pInputData, 
                                          eHEADSMState_t *eNewState, eGDBError_t *retValue ) 
{

  boolean bModuleKeepActive= b_FALSE;
  boolean bModuleLeaveActive= b_TRUE;
  HEADModule_t * pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);
  /*check if qos is good enough*/
  if ( (pModule->eQoS == HEADModuleQoS_NormalRunning) 
    || (pModule->eQoS == HEADModuleQoS_DegradationKeep) 
    || (pModule->eQoS == HEADModuleQoS_DegradationShutDown))
  {
    /*go to wait if LeaveActive is true*/
    *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleLeaveActive, HEADParameterState_LeaveActive);
    if ((*retValue == GDB_ERROR_NONE) && (bModuleLeaveActive == b_TRUE))
    {
      /*go to WAIT*/
      *eNewState = HEADSMState_WAIT;
    }
    else if (*retValue == GDB_ERROR_NONE) /* No error but Conditions met */
    {
      /*go to wait if KeepActive is false or an error occurred*/
      *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleKeepActive, HEADParameterState_KeepActive);
      if ((*retValue == GDB_ERROR_NONE) && (bModuleKeepActive == b_FALSE))
      {
        /*go to WAIT*/
        *eNewState = HEADSMState_WAIT;
      }
      else if (*retValue == GDB_ERROR_NONE) /* No error but Conditions met */
      {
        /*keep in ACTIVE*/
        *eNewState = HEADSMState_ACTIVE;
      }
      else /* Error case */
      {
        *eNewState = HEADSMState_OFF;
        pModule->eQoS = HEADModuleQoS_DegradationStop;
      }
    }
    else /* Error case */
    {
      *eNewState = HEADSMState_OFF;
      pModule->eQoS = HEADModuleQoS_DegradationStop;
    }
  }
  else
  {
    /*go to OFF*/
    *eNewState = HEADSMState_OFF;
    *retValue = GDB_ERROR_NONE;
  }

}


/*************************************************************************************************************************
  Functionname:         HEADEvalStateTransitionWait                                                                 */ /*!

  @brief                Evaluate if there is a state transition if in state Wait

  @description          Evaluate if there is a state transition if in state Wait
                        Module is assumed to be in State "Wait" if this function is called.
                        
                        Method created in refactoring. 
                        No Pointer checks are performed for following pointers, assert that all pointers are 
                        valid in calling functions.
                        pModule, pInputData, eNewState, retValue
                        @startuml
                        Start
                        :Get Module information;
                        If (Check if Module QoS good enough for Wait State?) then (yes)
                            :Check GSM Conditions for Leave wait State;
                            If ((No_Error) AND (Leave_Wait==True)) then (yes)
                                :Set New State as Passive;
                            Elseif ((No_Error)) then (yes)
                                :Check GSM Conditions for Keep wait State;
                                If ((No_Error) AND (Keep_Wait==False)) then (yes)
                                    :Set New State as Passive;
                                Elseif ((No_Error)) then (yes)
                                    :Set New State as Wait;
                                    Note:No error but Conditions met
                                Else
                                    :Set New State as OFF;
                                    Note:Error case
                                    :Set QoS of Module to Degradation stop;
                                Endif
                            Else (no)
                            :Set New State as OFF;
                            Note:Error case
                            :Set QoS of Module to Degradation stop;
                            Endif
                        Else (no)
                            :Set New State as OFF;
                            Note: Module is already in Degradation Stop
                            :Return Error as None;
                        Endif
                        Stop
                        @enduml             
       
  @return               void 

  @param[in]            uiModuleNr : Module Number
  @param[in]            pInputData : Pointer to Input data
  @param[out]           eNewState : Pointer to New State
  @param[out]           retValue : Pointer to GDB Error code
  
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
static void HEADEvalStateTransitionWait( uint8 uiModuleNr, 
                                        const struct HEADInputData_t * pInputData, 
                                        eHEADSMState_t *eNewState, eGDBError_t *retValue ) 
{
  boolean bModuleKeepWait= b_FALSE;
  boolean bModuleLeaveWait= b_TRUE;
  HEADModule_t * pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);
  /*check if qos is good enough*/
  if ( (pModule->eQoS == HEADModuleQoS_NormalRunning) 
    || (pModule->eQoS == HEADModuleQoS_DegradationKeep) 
    || (pModule->eQoS == HEADModuleQoS_DegradationShutDown))
  {
    /*go to passive if LeaveWait condition is true*/
    *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleLeaveWait, HEADParameterState_LeaveWait);
    if ( (*retValue == GDB_ERROR_NONE) && (bModuleLeaveWait == b_TRUE))
    {
      /*go to PASSIVE*/
      *eNewState = HEADSMState_PASSIVE;
    }
    else if (*retValue == GDB_ERROR_NONE) /* No error but Conditions met */
    {
      /*go to passive if KeepWait condition is false*/
      *retValue = HEADGSMConditions(uiModuleNr, pInputData, &bModuleKeepWait, HEADParameterState_KeepWait);
      if ( (*retValue == GDB_ERROR_NONE) && (bModuleKeepWait == b_FALSE))
      {
        /*go to PASSIVE*/
        *eNewState = HEADSMState_PASSIVE;
      }
      else if (*retValue == GDB_ERROR_NONE) /* No error but Conditions met */
      {
        /*stay in WAIT*/
        *eNewState = HEADSMState_WAIT;
      }
      else /* Error case */
      {
        *eNewState = HEADSMState_OFF;
        pModule->eQoS = HEADModuleQoS_DegradationStop;
      }  
    }
    else /* Error case */
    {
      *eNewState = HEADSMState_OFF;
      pModule->eQoS = HEADModuleQoS_DegradationStop;
    }
  }
  else
  {
    /*go to OFF*/
    *eNewState = HEADSMState_OFF;
    *retValue = GDB_ERROR_NONE;
  }
}


/*************************************************************************************************************************
  Functionname:         HEADDoStateTransition                                                                       */ /*!

  @brief                Do the actual state transition

  @description          This function is invoked to do the state Transition of head module.
                        OFF -->Passive, Passive -->Active, Active-->Wait, Wait-->Passive Etc.
                        This function can be called by external functions (e.g. outputfunctions)
                        
                        Method created in refactoring. 
                        No Pointer checks are performed => assert that all pointers are 
                        valid in calling functions.                        
                        @startuml
                        Start
                            :Set Error as None;
                            :Read Module Internal Informatin;
                        Note 
                        General specific ModuleInternal information
                        Endnote
                         If(Need to undo the State-Transition?
                        ->In order to undo the state transition 
                        (next state and the last state should be equal) AND
                        (Make sure that last state and the current state is not same) AND
                        (Make sure that last state is not OFF State ))then (yes)
                            If (Is State Valid?) then (valid)
                                :undo last State-Transition;
                                Note left
                                Move to Passive, Active or Wait based on the Last state from 
                                Where it came to its current state.
                                End note
                            Else (Not valid)
                                :Set Error as Unknown Error;
                                :Reset Conditions OK Timer;
                            endif
                            Elseif (Is call for State transition?) then (yes)
                            if (Moving to New State?) then (yes)
                                : Initialize condition Ok timer;
                                Note right
                                The timer which counts the seconds how long the module would 
                                fulfill all parameter criteria
                                End note
                                : Save Ego velocity;
                                Note right
                                Save ego velocity and siganal state before moving to new state.
                                End note
                            Endif
                            If (Is State Valid?) then (valid)
                                : do the State-Transition;
                                Note left
                                It can be a self transition or moving to New state.
                                ->Transition to Passive state is possible only from Off or Wait state.
                                ->Transition to Active state is possible only from Passive state.
                                ->Transition to Wait state is possible only from Active state.
                                ->Transition to Off state is possible from any state.
                                End note
                            Else (Not valid)
                                :Set Error as Unknown Error;
                                :Reset Conditions OK Timer;
                            Endif
                        Endif
                        Stop
                        @enduml

  @return               void

  @param[in]            eNewState : Enum variable to hold State Machine New State 
  @param[in]            pInputData : Pointer to HEAD Input Data
  @param[in,out]        pModule : Pointer to a HEAD Module
  @param[in,out]        retValue : Pointer to GDB Error code

  @glob_in              None
  @glob_out             None

  @c_switch_part        
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Clemens Schnurr | clemens.schnurr@continental-corporation.com 
*************************************************************************************************************************/
void HEADDoStateTransition( eHEADSMState_t eNewState,
                            const struct HEADInputData_t * pInputData, 
                            HEADModule_t * pModule, 
                            eGDBError_t *retValue ) 
{
  eGDBError_t localError = GDB_ERROR_NONE;
  HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));
  const uint16 uiMaxTimer = (uint16)(2u*(pModule->uiNumOrGroups));


  /* calling of the output function for this module => undo the State-Transition of the GenericStateMachine */
  if ( (pModule->eSMState != pModule->eSMLastState)  &&  (eNewState == pModule->eSMLastState)  &&  (pModule->eSMLastState != HEADSMState_OFF) )
  {
    switch(eNewState)
    {
    case HEADSMState_PASSIVE:
      /* Note: Degradation Keep will not influence any Timer, as this is a temporary degradation only and 
      shall not influence the function timings/performance by any means. */
      pModule->eSMState = HEADSMState_PASSIVE;
      break;
    case HEADSMState_ACTIVE:
      pModule->eSMState = HEADSMState_ACTIVE;
      break;
    case HEADSMState_WAIT:
      pModule->eSMState = HEADSMState_WAIT;
      break;
    case HEADSMState_Max:
    default:
      *retValue = GDB_ERROR_UNKNOWN_TYPE;
      (void)MEDIC_MEMSET(pModuleInt->pfConditionsOKTimer,0, sizeof(float32)*uiMaxTimer);/*PRQA S 0315, 2869 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
      break;
    }
  }
  /* first calling of the GenericStateMachine or the output function for this module => do the State-Transition */
  else if( pModule->eSMState == pModule->eSMLastState )
  {
    /*Indicate that Condition OK Timer is not updated yet*/
    /*----------------------------  go to new state ---------------------------------------*/
    if(eNewState != pModule->eSMState)
    {
      /*state changed*/
      /*init timer*/
      (void)MEDIC_MEMSET(pModuleInt->pfConditionsOKTimer,0, sizeof(float32)*uiMaxTimer);/*PRQA S 0315, 2869 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
      /*set ego vehicle speed (at active entry) to the current vehicle speed in case of a state transition*/
      localError = HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity,HEAD_DEFAULT_LongVelocity,
                                            &(pModuleInt->sAdditionalTableInputs.fHostSpeedLastStateTransition));
      if ( (localError == GDB_ERROR_NONE) && (pInputData->pInputValueList->LongVelocity.eSignalQuality == HEADInputSignalState_OK))
      {
        pModuleInt->sAdditionalTableInputs.bHostSpeedLastStateTransitionOK = b_TRUE;
      }
      else
      {
        pModuleInt->sAdditionalTableInputs.bHostSpeedLastStateTransitionOK = b_FALSE;
      }
    }

    /*---------------------------------  state actions ------------------------------------*/
    switch(eNewState)
    {
    case HEADSMState_OFF:
      /* In case the Module is turned off, (either by Failure or by Driver) the OK-Timer will start counting again 
      only if the module leaves the degradation state.
      Note: State timers are not influenced by the degradation and will keep on counting */
      if ( (pModule->eQoS != HEADModuleQoS_NormalRunning) && (pModule->eQoS != HEADModuleQoS_DegradationKeep) )
      {
        (void)MEDIC_MEMSET(pModuleInt->pfConditionsOKTimer,0, sizeof(float32)*uiMaxTimer);/*PRQA S 0315, 2869 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
      }
      pModule->eSMState = HEADSMState_OFF;
      break;
    case HEADSMState_PASSIVE:
      /* Note: Degradation Keep will not influence any Timer, as this is a temporary degradation only and 
      shall not influence the function timings/performance by any means. */
      if( (pModule->eSMState == HEADSMState_OFF) || (pModule->eSMState == HEADSMState_WAIT) )
      {
        pModule->eSMState = HEADSMState_PASSIVE;
      }
      break;
    case HEADSMState_ACTIVE:
      if(pModule->eSMState == HEADSMState_PASSIVE)
      {
        pModule->eSMState = HEADSMState_ACTIVE;
      }
      break;
    case HEADSMState_WAIT:
      if(pModule->eSMState == HEADSMState_ACTIVE)
      {
        pModule->eSMState = HEADSMState_WAIT;
      }
      break;
    case HEADSMState_Max:
    default:
      *retValue = GDB_ERROR_UNKNOWN_TYPE;
      (void)MEDIC_MEMSET(pModuleInt->pfConditionsOKTimer,0, sizeof(float32)*uiMaxTimer);/*PRQA S 0315, 2869 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
      break;
    }
  }
  else
  {
    /* do nothing */
  }
}


/*************************************************************************************************************************
  Functionname:         HEADGSMConditions                                                                           */ /*!

  @brief                Check if the enable conditions are met.

  @description          Walks through the all or groups of a module and checks all enable conditions and returns the 
                        overall enable condition, there's a maximum of 8 or groups in the parameters, this function loops 
                        over all groups is at least one group returns True, the result is true as well.
                        Returns GDB_ERROR_NONE in case of no errorm, Returns forwarded Error else.
                        
                        No pointer checks are performed for the following pointers.
                        pModule, pInputData, bConditionTrue, pModule->pInternal
                        Calling function shall assert that the pointers are valid.
                        @startuml
                        Start 
                        :Get Module information;
                        :Fetch Module internal GSM Information;
                        While (GoThroughAllOrGroup)
                            :reset active Hypotheses;
                            Note right:reset active Hypotheses in corresponding orGroup.
                        Endwhile
                        :Get ParameterList;
                        If (PatameterList==NULL) then (yes)
                            :Set Module Enable Condition as False;
                            Note
                            No parameters defined => reset all neccessary outputs 
                            and evaluate condition to false
                            End note
                        Else (no)
                            While ((GoThroughAllOrGroup) AND (Error==None))
                                :Evaluate OrGroup conditions;
                                Note right
                                Return value of OrGroupCondition is expected to be false 
                                if no rule is applicable, and if or group does not exis
                                End note
                                If ((Error==None) AND (OrGroupCondition==True)) then (yes)
                                    :Set Module Enable Condition as True;
                                Elseif ((Error!=None)) then (error case)
                                    :Set Module Enable Condition as False;
                                    :Reset triggered hypotheses in orGroup;
                                Else 
                                    :Reset triggered hypotheses in orGroup;
                                Endif
                            Endwhile
                        endif
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE in case of no error, else returns forwarded Error

  @param[in]            uiModuleNr : Module Number
  @param[in]            pInputData : Pointer to Input data
  @param[out]           bConditionTrue : Boolean variable represent condtion True of false
  @param[in]            eNewState : Enum Value to New State 
  
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
static eGDBError_t HEADGSMConditions(uint8 uiModuleNr,
                                     const struct HEADInputData_t *pInputData, 
                                     boolean *bConditionTrue, 
                                     eHEADParameterState_t eState)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADModule_t            *pModule    = HEADGetModule(pInputData->pModuleList, uiModuleNr);
  HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));
  HEADParameterOrGroup_t uiOrGroup;
  const HEADParameterEmpty_t *pParam;
  uint8 uiICnt;
  *bConditionTrue = b_FALSE;

  /*reset/init active Hypotheses in corresponding orGroup*/
  for (uiICnt = 0u; uiICnt < pModule->uiNumOrGroups; uiICnt++)
  {
    pModule->uiHypInOrGroup[uiICnt] = 0;
  }

  pParam = pModuleInt->pParameterList;
  
  if (pParam == NULL)
  {
    /* No parameters defined => reset all neccessary outputs and evaluate condition to false */
    *bConditionTrue = b_FALSE;
  }
  else
  {
    for (uiOrGroup = 0u; (uiOrGroup < pModule->uiNumOrGroups) && (retValue == GDB_ERROR_NONE); uiOrGroup++)
    {
      boolean bOrGroupConditionTrue = b_FALSE;
      /* Check a certain Or-group. Return value of bOrGroupConditionTrue is expected to be false if no rule is 
         applicable, and if or group does not exist*/
      retValue = HEADGSMConditionsGroup(uiModuleNr, pInputData, &bOrGroupConditionTrue, eState, uiOrGroup);
      
      if ( (retValue == GDB_ERROR_NONE) && (bOrGroupConditionTrue != b_FALSE))
      {
        *bConditionTrue = b_TRUE;
      }
      else if(retValue != GDB_ERROR_NONE) 
      {
        /* error case*/
        *bConditionTrue = b_FALSE;
        pModule->uiHypInOrGroup[uiOrGroup] = 0;
      }
      else
      {
        /*if bConditionTrue is false, reset triggered hyps in orGroup*/
        pModule->uiHypInOrGroup[uiOrGroup] = 0;
      }
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMResetParamValGeneral                                                                 */ /*!

  @brief                Initialize function for general param value structure

  @description          Initialize function for general param value structure
                        No check on Validity of Input pointer is done,Calling Function needs to 
                        assert the validity of the pointer.
                        @startuml
                        Start
                        :Initialize general param value structure;
                        Stop
                        @enduml
                          
  @return               void

  @param[out]           sParamValGeneral : General Param value
  
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
static void HEADGSMResetParamValGeneral(HEADGSMParamValues_t *sParamValGeneral)
{
  sParamValGeneral->bUsed = b_FALSE;
  sParamValGeneral->fFact = 1.0f;
  sParamValGeneral->uiBitPack = 0;
  /*the variables fVal, fDefVal, eOperator and uiBitPack will be defined 
  in case of bUsed is set to true.*/
}


/*************************************************************************************************************************
  Functionname:         HEADGSMConditionsGroup                                                                      */ /*!

  @brief                Returns true if the enable conditions are met for this ORGroup

  @description          walks through the Hypotheses list and checks all enable conditions and returns 
                        the overall enable condition, for each hypothesis all parameters where checked.
                        if a parameter belongs to the current check hypothesis it'll be checked against the hyp values
                        there is an array of check information of the size of the hypothesis type count [kinematic/driver]
                        for each hypothesis type the result will be stored in array, also the information 
                        if a parameter requires a specific hypothesis.
                        At the end the information in array is merged to an overall output

                        No pointer checks are performed for the following pointers.Calling function shall assert 
                        that the pointers are valid.
                        pModule, pInputData, bConditionTrue, pModule->pInternal

                        The Output of the module shall be True if the Or group is evaluated as true.
                        In case the Or group is not applicable or false the result shall be false.
                        @startuml
                        Start
                        :Set Local_Error as none;
                        #Orange:Get Module information
                        <b>HEADGetModule</b> >
                        :Fetch Module internal GSM Information;
                        #Orange:Preselection of Hypotheses to be checked
                        <b>HEADGSMGetParametersToRelevantHyps</b> >
                        Note
                        Loops through the parameterlist in the current 
                        module and checks which hypotheses have the 
                        potential to become relevant.
                        End note
                        #Orange:Initialize GSM Active Function
                        <b>HEADGSMInitActiveFunction</b> >
                        Note left
                        Init all values in ParamVal This Module Active at 
                        the beginnig of orGroup check
                        End note
                        Partition CycleThroughMatchingHypothesesList {
                        While (check (CD_Hypothesis count < MaxNumberOf_CD_Hypothesis) AND (No Local Error)?)
                            #Orange:Get the hypothesis
                            <b>HEADGSMInitActiveFunction</b> >
                            Note:Get the hyptohesis of corresponding index from the hypotheses list
                            If (Check if Hypothesis available?) then (yes)
                            If (Is Hypothesis type Valid?) then (yes)
                                    : set IntermediateResult to not checked at the 
                                beginning of every hypothesis;
                                #Orange:Reset ParamValThisModuleActive for 
                                hyp dependent parameters
                                <b>HEADGSMInitActiveFunction</b> >
                                if (Is the kinematic Hypothesis is available
                                in the Preselecd list of hypothesis) then (yes)
                                    :store these hypothesis in triggerd Hypothesis;
                                    Note:store these hyps which are triggered regardless of true or false
                                    #Orange:check conditions
                                    <b>HEADGSMCheckConditions</b> >
                                    Note: check conditions in this module with the current hypothesis;
                                Endif
                                If ((hypothesis_Condition==True) AND (No_Error)) then (yes)
                                    :Store Triggered Hypothesis in Module 
                                    Hypothesis In orGroup array; 
                                Endif
                            Endif
                            Else
                                :Create an assertion failure;
                                Note
                                Here we are in the error path.
                                This should never happen, therefore create an assertion failure
                                End note
                                : Set the error value to allow an error handling;
                            Endif
                        Endwhile
                        }
                        Partition Evaluate_IndependentParameters {
                        #Orange:Reset ParamValThisModuleActive for 
                        independent parameters
                        <b>HEADGSMInitActiveFunction</b> >
                        #Orange:check conditions for independent parameters
                        <b>HEADGSMCheckConditions</b> >
                        note 
                        Eval independent parameters, therefore check all parameters which have no hyps
                        end note
                        }
                        Partition Merge_Results {
                        If ((No_Error) AND
                        (No_KIN_Hypothesis) AND
                        (All IndependentParameters are not checked))then (yes)
                            :Set Condition as False;
                            :reset Conditions Ok Timer;
                        elseIf ((No_Error) AND
                        ((AtLeastOne_KIN_Hypothesis is True) OR (NoHypothesisDependentParameter)) AND
                        (All IndependentParameters are true or not checked)) then (yes)
                            :Set Condition as True;
                            :increment Condition Ok Timer;
                            #Orange:Evaluate Active Module Time
                            <b>HEADGSMEvaluateActiveModuleTime</b> >
                            Note 
                            The parameter All Conditions are true for at least/most x s is used 
                            In this case the outcome "true" is delayed (at least) by that value or
                            (at most) limited in time.
                            End note
                            If ((IndependentParameterResult==True) AND (Condition==True)) then (yes)
                                :Set Independent result to Module 
                                Hypothesis In orGroup array;
                            endif
                        else
                            :Set Condition as False;
                            :reset Conditions Ok Timer;
                        Endif
                        }
                        :Return Local_Error;
                        Stop
                        @enduml
       
  @return               eGDBError_t : In case of no error GDB_ERROR_NONE shall be returned, all other return values 
                                      indicate an error

  @param[in]            uiModuleNr : Module Number
  @param[in]            pInputData : Pointer to Input Data
  @param[out]           bConditionTrue : Boolean variable represent condtion True of false
  @param[in]            eState : Module State
  @param[in]            uiOrGroup : orGroup Number
  
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
static eGDBError_t HEADGSMConditionsGroup(uint8 uiModuleNr, 
                                          const struct HEADInputData_t *pInputData, 
                                          boolean *bConditionTrue,
                                          eHEADParameterState_t eState, 
                                          HEADParameterOrGroup_t uiOrGroup)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  /* stores the hypotheses used in the parameters. This is used to reduce 
     processing power as unused Hypothesis need not to be checked thereafter*/
  HEADParameterHypothesisSub_t rgHypUsed;
  HEADParameterHypothesisSub_t rgInputHypTriggered = 0;
  /*this struct is filled for every hyp and the independent parameter check
    and evaluated at the end of the orGroup. Dependend on the operator the max and min time is used.*/
  HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT];
  /*holds the current hyp return result*/
  eHEADSpecialBool_t eHypothesisResult;
  /*holds the independent parameter return value*/
  eHEADSpecialBool_t eIndependentParResult = HEADSpecialBool_notchecked;
  uint8 uiCurrentHyp;
  const uint32 uiBitFlag = 1;
  const uint32 uiTimerIdx = (uiOrGroup*2u)+(((uint32)eState)%2u);
  /*pointer to the module*/
  HEADModule_t            *pModule    = HEADGetModule(pInputData->pModuleList, uiModuleNr);
  /*pointer to the internal module*/
  HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));
  /*Preselection of Hypotheses which have to be checked*/
  HEADGSMGetParametersToRelevantHyps(pModule, &rgHypUsed, uiOrGroup, HEADParameterStateBit(eState), pInputData);/*PRQA S 4491, 4499 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
  /*Init all values inParamValThisModuleActive at the beginning of orGroup check*/
  HEADGSMInitActiveFunction(sParamValThisModuleActive, b_TRUE);
  
  /*--------------------------------------*/  
  /*Cycle through matching hypotheses list*/
  /*--------------------------------------*/ 
  for(uiCurrentHyp = 0u; (uiCurrentHyp < (uint8)MAX_NUM_OF_HYPS) && (locError == GDB_ERROR_NONE); uiCurrentHyp++)
  {
    /*get the hypothesis with index uiCurrentHyp from the hypotheses list */
    const HEADHypothesis_t *const pHyp = HEADGetHypothesis(pInputData->rgHypothesisList, uiCurrentHyp);

    /* For safety sake check the resulting pointer */
    if (pHyp->pHypothesis != NULL)
    {
      if (pHyp->pHypothesis->eType != CDHypothesisType_No)
      {
        /*set IntermediateResult to not checked at the beginning of every hypothesis*/
        eHypothesisResult = HEADSpecialBool_notchecked;
        /*Reset/Init sParamValThisModuleActive for hyp dependent parameters*/
        HEADGSMInitActiveFunction(sParamValThisModuleActive, b_FALSE);
        /*is the kinematic Hypothesis-Subtype (e.g. RunupStationary) stored in rgHypUsed... */
        if( (rgHypUsed & (HEADParameterHypothesisBit(pHyp->pHypothesis->eType))) != 0u )
        {
          /*store these hyps which are triggered regardless of true or false*/
          rgInputHypTriggered |= (HEADParameterHypothesisBit(pHyp->pHypothesis->eType));
          /*check conditions in this module with the current hyp*/
          locError = HEADGSMCheckConditions(pInputData, uiModuleNr, eState, uiOrGroup, &eHypothesisResult,
                                            0, sParamValThisModuleActive, pHyp);
        }
        /*if the hypothesis is true it will be stored in pModule->uiHypInOrGroup[uiOrGroup] for further usage in the output functions*/
        if(    (locError          == GDB_ERROR_NONE      )
            && (eHypothesisResult == HEADSpecialBool_True) )
        {
          pModule->uiHypInOrGroup[uiOrGroup] = (uint16)((uiBitFlag<<uiCurrentHyp) | (uint32)(pModule->uiHypInOrGroup[uiOrGroup]));
        }
      }
    }
    else
    {
      /* Here we are in the error path. */
      /* This should never happen, therefore create an assertion failure */
      MEDIC_ASSERT(FALSE); /*PRQA S 3112, 3119 *//* date: 2019-1-21, reviewer: Sadhanashree Srinivasa, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
      /* Set the error value to allow an error handling */
      locError = GDB_ERROR_POINTER_NULL;
    }
  }

  /*-----------------------------------*/  
  /*Evaluate the independent parameters*/
  /*-----------------------------------*/
  if (locError == GDB_ERROR_NONE)
  {
    /*Reset/Init sParamValThisModuleActive for independent parameters*/
    HEADGSMInitActiveFunction(sParamValThisModuleActive, b_FALSE);
    /*eval independent parameters, therefore check all parameters which have no hyps*/
    locError = HEADGSMCheckConditions(pInputData, uiModuleNr, eState, uiOrGroup, &eIndependentParResult,
                                      rgInputHypTriggered, sParamValThisModuleActive, NULL);
  }
  
  /*-----------------------------*/  
  /*Merge Results and set OKTimer*/
  /*-----------------------------*/ 
  if( (locError == GDB_ERROR_NONE)
    /*there is no hyp*/
    &&(pModule->uiHypInOrGroup[uiOrGroup] == 0u)
    /*and all independent parameters are not checked*/
    &&(eIndependentParResult == HEADSpecialBool_notchecked)
    )
  {
    *bConditionTrue = b_FALSE;
    /*reset fConditionsOKTimer*/  /* QAC 0491: the pointer pfConditionsOKTimer is an array with known length */
    /*PRQA S 0491 1*/
    pModuleInt->pfConditionsOKTimer[uiTimerIdx] = 0.0f;
  }
  else if( (locError == GDB_ERROR_NONE)
         /*at least one KIN hyp 0-11 is true or there is no hyp dependent parameter:*/
         &&((pModule->uiHypInOrGroup[uiOrGroup] != 0u) || (rgHypUsed == 0u) )
         /*and all independent parameters are true or not checked (there are no independent params, otherwise set to false)*/
         &&((eIndependentParResult == HEADSpecialBool_True) || (eIndependentParResult == HEADSpecialBool_notchecked))
         )
  {
    *bConditionTrue = b_TRUE;
    /*increment fConditionsOKTimer if OrGroup is true so far*/   /* QAC 0491: the pointer pfConditionsOKTimer is an array with known length */
    /*PRQA S 0491 15*/
    pModuleInt->pfConditionsOKTimer[uiTimerIdx] += pInputData->fCycleTime;
    /*evaluate function active time - filled for every hyp and independent and stored max
      this function decides if an orGroup is TRUE od FALSE*/
    HEADGSMEvaluateActiveModuleTime(bConditionTrue, sParamValThisModuleActive, pModule, uiOrGroup, eState);
    /*set independent evaluatiuon result to uiHypInOrGroup*/
    if((eIndependentParResult == HEADSpecialBool_True) && ((*bConditionTrue) == b_TRUE))
    {
      pModule->uiHypInOrGroup[uiOrGroup] = (uint16)((uiBitFlag<<HEADHypothesisIndependent) | (uint32)(pModule->uiHypInOrGroup[uiOrGroup]));
    }
  }
  else
  {
    /*set explicitly to false*/
    *bConditionTrue = b_FALSE;
    /*reset fConditionsOKTimer for this orGroup*/
    /* QAC 0491: the pointer pfConditionsOKTimer is an array with known length */
    /*PRQA S 0491 1*/
    pModuleInt->pfConditionsOKTimer[uiTimerIdx] = 0.0f;
  }
  return locError;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMResetParamValOMIS                                                                    */ /*!

  @brief                Initialize function for OtherModulInState

  @description          Initialize function for OtherModulInState
                        Note that no Pointer checks are performed. Calling Function needs to assert that 
                        input pointers are valid.
                        @startuml
                        Start
                        :Initialize other module state time structure;
                        Stop
                        @enduml

                          
  @return               void

  @param[out]           sParamValOMIS : Pointer to Other Module in State Structure
  
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
static void HEADGSMResetParamValOMIS(HEADOtherModuleInState_t *sParamValOMIS)
{
  uint32 uiICnt;

  /*init other module state time structure*/
  sParamValOMIS->uiNrOfChecksUsed = 0u;
  for (uiICnt = 0u; uiICnt < HEAD_AUTO_CFG_NO_OMIS; uiICnt++)
  {
    sParamValOMIS->uiBitPack[uiICnt]=0u;
    sParamValOMIS->eOperator[uiICnt]=HEADParamOperator_DEFAULT;
    sParamValOMIS->fInTime[uiICnt]=0.0f;
    sParamValOMIS->fFactor[uiICnt]=0.0f;
  }
}


/*************************************************************************************************************************
  Functionname:         HEADGSMInitActiveFunction                                                                   */ /*!

  @brief                Init function for ActiveFunction

  @description          Init function for ActiveFunction
                        Note that no Pointer checks are performed. Calling Function needs 
                        to assert that input pointers are valid.
                        @startuml
                        Start
                        Partition InitializeActiveFunction {
                        If (INIT_ALL == True) then (yes)
                            :Initialize UsedOverall and Threshold Value
                            of the Module orGroup;
                        Endif
                        :Initialize Used, Operator, InTime And 
                        Factor value of the Module OrGroup;
                        }
                        Stop
                        @enduml

  @return               void

  @param[out]           sParamValThisModuleActive : Module Active Param Value
  @param[in]            initAll : Boolean indicates Initialize All is needed or not
  
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
static void HEADGSMInitActiveFunction(HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT], 
                                      boolean initAll)
{
  /*if initAll is FALSE fThreshold and bUsedOverall isn't initialized here because 
    they should be available over the whole orGroup-check and evaluated in the end*/
  if(initAll == b_TRUE)
  {
    sParamValThisModuleActive[HEADParamOperator_LESSTHAN].bUsedOverall    = b_FALSE;
    sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold      = HEAD_MAX_FUNCTION_ACTIVE_TIME;
    sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].bUsedOverall = b_FALSE;
    sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold   = 0.0f;
  }
  /*init function active time structure*/
  sParamValThisModuleActive[HEADParamOperator_LESSTHAN].bUsed         = b_FALSE;
  sParamValThisModuleActive[HEADParamOperator_LESSTHAN].eOperator     = HEADParamOperator_LESSTHAN;
  sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fInTime       = HEAD_MAX_FUNCTION_ACTIVE_TIME;
  sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fFactor       = 1.0f;

  sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].bUsed      = b_FALSE;
  sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].eOperator  = HEADParamOperator_GREATERTHAN;
  sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fInTime    = 0.0f;
  sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fFactor    = 1.0f;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMGetParametersToRelevantHyps                                                          */ /*!

  @brief                Preselection of Hypotheses to be checked

  @description          This functions loops through the parameterlist in the current module and checks which
                        hypotheses have the potential to become relevant and so should be checked later. 
                        Bits will be set in the bitfield-array rgHypUsed
                        @startuml
                        Start
                        :Fetch Module Parameter List;
                        While (Loop through all parameters in current module)
                            :Get Parameter;
                            If( (Parameter orGroup == Current orGroup) AND
                                (Check Module's Current state with affect state) AND 
                                ((Check if Parameter is mode independent) OR 
                                (Paramtermode (early-middle-late-ACC) is used in this mode)) )
                                    :Update Used Hypotheses List;
                                    Note
                                    Relevant Hypotheses to be checked
                                    End note
                            Endif
                            :Go to next Parameter;
                        Endwhile
                        Stop
                        @enduml

  @return               void

  @param[in]            pModule : Pointer to a Module
  @param[out]           rgHypUsed : Bit field for head parameter hypothesis
  @param[in]            uiOrGroup : orGroup Number
  @param[in]            eStateBit : Module State Bit field
  @param[in]            pInputData : Pointer to Input data
  
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
static void HEADGSMGetParametersToRelevantHyps(const struct HEADModule_t *pModule,
                                               HEADParameterHypothesisSub_t *rgHypUsed,
                                               HEADParameterOrGroup_t uiOrGroup,
                                               HEADParameterState_t eStateBit,
                                               const struct HEADInputData_t *pInputData)
{
  const HEADParameterEmpty_t *pParam = ((const HEADModuleInternalGSM_t *)((const void *)pModule->pInternal))->pParameterList;
  *rgHypUsed = 0;
  /* Loop through all parameters in current module*/
  while(pParam != NULL)
  {
    const HEADParameterType_t *const locParameterType = &(pParam->ParameterType.sParameterType);

    if(  ( ((HEADParameterOrGroup_t)(locParameterType->ParameterOrGroup)) == uiOrGroup)
          /*affects state*/
       &&((eStateBit & ((HEADParameterState_t)(locParameterType->ParamState)) ) != 0u)
            /*either parametermode independent*/
       &&( (locParameterType->ParameterMode == 0)
            /*paramtermode (early-middle-late-ACC) is used in this mode*/
         ||((((uint32)(locParameterType->ParameterMode)) & HEADParameterModeBit(pInputData->eHEADMainMode)) != 0u)
         )
      )
    {
      *rgHypUsed |= (HEADParameterHypothesisSub_t)locParameterType->ParameterHypSubType;
    }
    /*set pParam to the next Parameter in the list*/
    pParam = pParam->ParameterType.pNextParam;
  }
}


/*************************************************************************************************************************
  Functionname:         HEADGSMCheckConditions                                                                      */ /*!

  @brief                This function checks the conditions in an orGroup

  @description          This function loops through the enum entries of HEADParamOperator and HEADParamOutType_t
                        and evaluates the relevant parameters. 
                        Parameters can be Hypothesis dependent or independent.
                        @startuml
                        Start
                        :Get Module information;
                        :Fetch Module internal GSM Information;
                        If (CDHypothesis available?) then (yes)
                            If ((Valid Hypothesis Type) AND 
                            (Hypothesis Dynamic Property is valid) AND
                            (Hypothesis Object Class is valid)) then (yes)
                            :Get Hypothesis Dependent Values from CD Hypothesis;
                            Note:Get Hypothesis type, Dynamic Property and Object Class.
                            Else
                            :Set Condition as False;
                            :Set Hypothesis dependent Values to zero;
                            endif
                        Else
                            :Set Hypothesis dependent Values to zero;
                        Endif
                        :Reset other module in state values;
                        While (Loop through Operators) 
                            While (Loop through Param Output type)
                                If (Output Type is Valid?) then (yes)
                                    :Initialize values structures for this hypothesis;
                                    Note:Initializes the general param values structure
                                    :Set pointer to the first element of 
                                    Relevant Parameter;
                                    While ((loop through the Relevent parameters)AND(Is Parameter is Valid?)AND(No_Error))
                                        :Get current parameter;
                                        :Get Used Hypothesis for that Parameter;
                                        If ((Check Condition in the right orGroup) AND 
                                        (check if the parameter is valid for this transition type) AND
                                        ((IS ParameterMode valid) OR (ParameterMode independent)) AND
                                        ((Is Object Class Valid) OR (Hyp Independent parameter)) AND
                                        ((Is Dynamic Property valid) OR (Hyp Independent parameter))) then (yes)
                                            :Chcek if the Parameter is valid for eveluation;
                                            If (Is Parameter valid?) then (yes)
                                                :Get Parameter value;
                                                If (No_Error) then (yes)
                                                    :Place current info into parameter structures;
                                                Note
                                                ->Puts the values set by the autocoder into the right 
                                                    ParamStruct which are evaluated later.
                                                ->Value which is stronger for that condition and output type is 
                                                Found and place it in the structure.
                                                END note
                                                Endif
                                            Else(Notvalid or NotChecked)
                                                :If the Parameter is Not checked the loop will go on
                                                If the Parameter is Not Valid the loop will break;
                                            Endif
                                        :Update Parameter is Exist or not;
                                        Endif
                                        :Go to next Relevent Parameter;
                                    Endwhile 
                                    If ((No_Error) AND (ParamExist)) then (yes)
                                        :Evaluate the condition based on the Output type 
                                        and update the result accordingly;
                                    Endif
                                Else
                                    :Set Error as Type Unknown;
                                Endif
                            Endwhile
                        Endwhile
                        If (Param Exists != False)then (yes)
                                :will be evaluated at the end of each orGroup,
                            here: just set thresholds;
                            if ((MinTime Condition triggered by 
                        hyp or independent parameter?)) then (yes)
                              :update threshold value;
                              Note
                              transparent behavior is to handle 
                              negative timer thresholds as zero
                              End note
                              :Is the threshold evaluated for this hyp or 
                              independent less than the overall threshold, 
                              then set it to overall;
                            Endif
                            If ((MaxTime Condition triggered by 
                        hyp or independent parameter?)) then (yes)
                              :update threshold value;
                              Note
                              transparent behavior is to handle 
                              negative timer thresholds as zero 
                              end note
                              :Is the threshold evaluated this hyp or 
                              independent greater than the overall threshold,
                              then set it to overall;
                            Endif
                          Endif
                        Stop
                        @enduml
                                  
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned.

  @param[in]            pInputData : Pointer to Input data
  @param[in]            uiModuleNr : Module Number
  @param[in]            eState : Enum Value Module State
  @param[in]            uiOrGroup : orGroup Number
  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            bfIgnoreHypSubTypes : Hypothesis Needed to be ignored for evaluation
  @param[out]           sParamValThisModuleActive : Module Active Param Value
  @param[in]            pHyp : Triggerd CD Hypothesis
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        @ref FCT_HYPOTHESIS_INTFVER
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADGSMCheckConditions(const struct HEADInputData_t *pInputData,
                                          uint8 uiModuleNr,
                                          const eHEADParameterState_t eState,
                                          HEADParameterOrGroup_t uiOrGroup,
                                          eHEADSpecialBool_t *pIntermediateResult,
                                          HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                          HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                          HEADHypothesis_t const *pHyp)
{
  HEADGSMParamValues_t sParamValGeneral;
  HEADOtherModuleInState_t sParamValOMIS;
  uint8 uiOperator, uiOutType;
  eHEADParamOutType_t eOutType;
  const HEADParameterEmpty_t *pParam;
  float32 fValue;
  HEADParameterHypothesisSub_t hypSubType;
  HEADEBADynProp_t dynPropertyBit;
  HEADEBAObjectClass_t objClassBit;
  eHEADSpecialBool_t eParamValid;
  eHEADSpecialBool_t eParamExists;
  eGDBError_t locError = GDB_ERROR_NONE;
  const HEADParameterState_t eStateBit = HEADParameterStateBit(eState);/*PRQA S 4491, 4499 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
  HEADModule_t            *pModule    = HEADGetModule(pInputData->pModuleList, uiModuleNr);
  HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

  if(pHyp != NULL)
  {
    if( (pHyp->pHypothesis->eType != CDHypothesisType_No) 
      &&(pHyp->pHypothesis->eEBADynProp != EBADynProp_NotAvail)
      &&(pHyp->pHypothesis->eEBAObjectClass != EBAObjectClass_NotAvail)
      )
    {
      hypSubType     =  HEADParameterHypothesisBit(pHyp->pHypothesis->eType);
      dynPropertyBit =  HEADDynPropBit(pHyp->pHypothesis->eEBADynProp) 
                      & (HEADEBADynProp_t)pModuleInt->DynamicProperty;
      objClassBit    =  HEADObjectClassBit(pHyp->pHypothesis->eEBAObjectClass) 
                      & (HEADEBAObjectClass_t)pModuleInt->ObjClassSelection;
    }
    else
    {
      *pIntermediateResult = HEADSpecialBool_False;
      /*set hyp-values explicit to 0 (is not accessed further)*/
      hypSubType = 0;
      dynPropertyBit = 0;
      objClassBit = 0;
    }
  }
  else
  {
    hypSubType = 0;
    dynPropertyBit = 0;
    objClassBit = 0;
  }

  /* reset/init other module in state values struct*/
  HEADGSMResetParamValOMIS(&sParamValOMIS);
  for(uiOperator = 0; (uiOperator < (uint8) HEADParamOperator_DEFAULT) && (*pIntermediateResult != HEADSpecialBool_False); uiOperator++)
  {
    /*Loop through the root-parameter array (affected eOutType)*/
    for(uiOutType = (uint8) HEADParamOutType_FirstValue; (uiOutType < (uint8) HEADParamOutType_Max) && (*pIntermediateResult != HEADSpecialBool_False); uiOutType++)
    {
      eParamValid = HEADSpecialBool_notchecked;
      switch (uiOutType)
      {
        /*here are all enum entries mentioned. 
          If you add a new one, it has also to be added here:*/
        case (uint8) HEADParamOutType_AllConditionsForOrGroupMet :
        case (uint8) HEADParamOutType_OtherOrGroupIsTrue         :
        case (uint8) HEADParamOutType_OrGroupInhibition          :
        case (uint8) HEADParamOutType_StateActiveTime            :
        case (uint8) HEADParamOutType_OtherModuleStateTime       :
        case (uint8) HEADParamOutType_Bool                       :
        case (uint8) HEADParamOutType_EgoVelocity                :
        case (uint8) HEADParamOutType_EgoAccel                   :
        case (uint8) HEADParamOutType_SafeObjDistSfty            :
        case (uint8) HEADParamOutType_SafeObjDistPerf            :
        case (uint8) HEADParamOutType_DriverFeedbackProb         :
        case (uint8) HEADParamOutType_DriverActivityProb         :
        case (uint8) HEADParamOutType_DriverAttentionProb        :
        case (uint8) HEADParamOutType_TTC                        :
        case (uint8) HEADParamOutType_TTB_PRE                    :
        case (uint8) HEADParamOutType_TTB_ACUTE                  :
        case (uint8) HEADParamOutType_TTS_PRE                    :
        case (uint8) HEADParamOutType_TTS_ACUTE                  :
        case (uint8) HEADParamOutType_ClosingVel                 :
        case (uint8) HEADParamOutType_ANecLong                   :
        case (uint8) HEADParamOutType_HypProb                    :
        case (uint8) HEADParamOutType_ObjectDist                 :
        case (uint8) HEADParamOutType_ObjectDistLat              :
        case (uint8) HEADParamOutType_ObjProb                    :
        case (uint8) HEADParamOutType_TTC2                       :
        case (uint8) HEADParamOutType_TTC3                       :
        case (uint8) HEADParamOutType_TTC4                       :
        case (uint8) HEADParamOutType_HypLifetime                :
        case (uint8) HEADParamOutType_ANecLatAbs                 :
        case (uint8) HEADParamOutType_VRelX                      :
        case (uint8) HEADParamOutType_TTMLongPre                 :
        case (uint8) HEADParamOutType_TTMLongAcute               : 
        case (uint8) HEADParamOutType_EgoLatCurvature            :
        case (uint8) HEADParamOutType_SensorSource               :
        case (uint8) HEADParamOutType_CustomPar_00_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_01_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_02_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_03_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_04_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_05_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_06_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_07_HypIndependent   :
        case (uint8) HEADParamOutType_CustomPar_00_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_01_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_02_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_03_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_04_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_05_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_06_HypDependent     :
        case (uint8) HEADParamOutType_CustomPar_07_HypDependent     :
			case (uint8)HEADParamOutType_CustomPar_08_HypDependent:
		case (uint8) HEADParamOutType_CustomPar_08_HypIndependent   :
		case (uint8) HEADParamOutType_CustomPar_09_HypIndependent   :
        #if HEAD_CFG_TURN_ASSIST
        case (uint8) HEADParamOutType_SteeringAngle                   :
        case (uint8) HEADParamOutType_TurnIndicatorInSteeringDirection:
        case (uint8) HEADParamOutType_GasPedal                        :
        case (uint8) HEADParamOutType_CorridorStopDistance            :
        #endif
        #if HEAD_CFG_CORRIDOROCCUPANCY
        case (uint8) HEADParamOutType_CorridorOccupancy             :
		case (uint8) HEADParamOutType_ObjMoveDir                    :
        #endif
        /* QAC 1482: dosen't matter here due to switch-case-default catch  */
        /*PRQA S 1482 1*/
        eOutType = (eHEADParamOutType_t)uiOutType;
        /*init the values structures for this hypothesis*/
        HEADGSMResetParamValGeneral(&sParamValGeneral);
        /*set pointer to the first element in the array*/
        pParam = pModuleInt->pRootPointerList[uiOperator][eOutType];
        /*set bParamExists to not checked for every root param element*/
        eParamExists = HEADSpecialBool_notchecked;
      
        /*loop through the attached parameters to this element*/
        while ( (pParam != NULL)
              &&(locError == GDB_ERROR_NONE) 
              &&(eParamValid != HEADSpecialBool_False)
              )
        {
          /*gets current parameter struct*/
          const HEADParameterType_t *const locParameterType = &(pParam->ParameterType.sParameterType);
          /*paramHypSubType is a bitfield with HypSubType(s) set in Autocoder for the current parameter*/
          const HEADParameterHypothesisSub_t bfParamHypSubType = (HEADParameterHypothesisSub_t)locParameterType->ParameterHypSubType;
                /*check if condition in the right or group*/
          if( ( (HEADParameterOrGroup_t)(locParameterType->ParameterOrGroup) == uiOrGroup)
                /*check if the parameter is valid for this transition type - affects state in AutoCoder*/
            &&( (eStateBit & (HEADParameterState_t)(locParameterType->ParamState)) != 0u)
                /*either parametermode independent*/
            &&( (locParameterType->ParameterMode == 0)
                /*or parametermode (early-middle-late-ACC) is used in this mode*/
              ||((((uint32)(locParameterType->ParameterMode)) & (HEADParameterModeBit(pInputData->eHEADMainMode))) != 0u)
              )
                /*Object-class of hyp dependent parameter is allowed*/
            &&( (((HEADEBAObjectClass_t)(locParameterType->ParamObjectClass) & (objClassBit)) != 0u)
                /*or it's a hyp independent parameter*/
              ||(bfParamHypSubType == 0u)
              )
               /*dynamic property of hypothesis and parameter*/
            &&((((HEADEBADynProp_t)(locParameterType->ParamDynProp) & (dynPropertyBit)) != 0u)
                /*or it's a hyp independent parameter*/
              ||(bfParamHypSubType == 0u)
              )
            )
          {
            /*check if this parameter is valid to be put into the right paramStruct and if it is valid to be evaluated*/
            HEADGSMParamValidForEval( hypSubType, bfParamHypSubType, bfIgnoreHypSubTypes, &eParamValid);
            if ( (eParamValid == HEADSpecialBool_True) || (eParamValid == HEADSpecialBool_checked) )
            {
              /*fvalue is assigned in HEADGetParam*/
              locError = HEADGetParam(pParam, pInputData, pHyp, uiModuleNr, &fValue, 
                                       &(pModuleInt->sAdditionalTableInputs) );
              /* if locError == GDB_ERROR_NONE then the parameter is valid for this hyp and mode*/
              if(locError == GDB_ERROR_NONE) 
              {
                /*place current info into parameter structures*/
                locError = HEADGSMPlaceCurrentInfoIntoParamStruct( &sParamValGeneral, &sParamValOMIS, sParamValThisModuleActive, 
                                                                    pParam, eOutType, fValue);
              }
            }
            else /*if( (eParamValid == HEADSpecialBool_notchecked) || (eParamValid == HEADSpecialBool_False)  )*/
            {
              /*in both cases pParam will be set to the next parameter 
                    if HEADSpecialBool_False:        the loop will break
                    if HEADSpecialBool_notchecked:   the loop will go on with the next parameter
              */
            }
            eParamExists = MIN(eParamExists, eParamValid);
          }
          /*go to next list element*/
          pParam = pParam->ParameterType.pNextRelevantParam;
        } /*end-while*/

        /*the evaluation starts here - all parameters have been placed into the according structs*/
        if( (locError == GDB_ERROR_NONE)
          &&(eParamExists == HEADSpecialBool_True)
          )
        {
          switch(eOutType)
          {
          case HEADParamOutType_OtherModuleStateTime:
            {
              /*go for timing parameters / conditions*/
              locError = HEADGSMEvaluateOtherModuleInState(pIntermediateResult, pInputData, &sParamValOMIS);
            }
            break;
          case HEADParamOutType_AllConditionsForOrGroupMet:
            {
              ///*will be evaluated at the end of each orGroup,
              
            }
            break;
          case HEADParamOutType_OtherOrGroupIsTrue  :
            locError = HEADGSMCheckOtherOrGroup(pIntermediateResult, pModule, &sParamValGeneral, eState);
            break;
          case HEADParamOutType_Bool                :
            if(sParamValGeneral.fVal > BOOL_BORDER)
            {
              *pIntermediateResult = HEADSpecialBool_True;
            }
            else
            {
              *pIntermediateResult = HEADSpecialBool_False;
            }
            break;
          case HEADParamOutType_OrGroupInhibition   :
            {              
              if(pHyp != NULL)
              {
                HEADBitField_t bfInhibition = 0u;
                locError = HEADInhibitionCheck(pHyp, &bfInhibition);
                if( (sParamValGeneral.uiBitPack & (pHyp->pHypothesis->eEBAInhibitionMask | bfInhibition) ) == 0u)
                {
                  *pIntermediateResult = HEADSpecialBool_True;
                }
                else
                {
                  *pIntermediateResult = HEADSpecialBool_False;
                }
              }
              else
              {
                /*OrGroupInhibition without hyp would be a wrong setting in Autocoder*/
                locError = GDB_ERROR_POINTER_NULL;  
              }
            }
            break;
          case HEADParamOutType_SensorSource:
            #if (FCT_HYPOTHESIS_INTFVER > 0x14)
            if(pHyp != NULL)
            {
              if(sParamValGeneral.uiBitPack == pHyp->pHypothesis->eSensorSource)
              //if(sParamValGeneral.uiBitPack == (pHyp->pHypothesis->eSensorSource & sParamValGeneral.uiBitPack))
              {
                *pIntermediateResult = HEADSpecialBool_True;
              }
              else
              {
                *pIntermediateResult = HEADSpecialBool_False;
              }
            }
            #else
            if(pHyp != NULL)
            {
              *pIntermediateResult = HEADSpecialBool_False;
            }
            #endif
            break;
          
          case HEADParamOutType_StateActiveTime     :
          case HEADParamOutType_EgoVelocity         :
          case HEADParamOutType_EgoAccel            :
          case HEADParamOutType_SafeObjDistSfty     :
          case HEADParamOutType_SafeObjDistPerf     :
          case HEADParamOutType_DriverFeedbackProb  :
          case HEADParamOutType_DriverActivityProb  :
          case HEADParamOutType_DriverAttentionProb :
          case HEADParamOutType_TTC                 :
          case HEADParamOutType_TTB_PRE             :
          case HEADParamOutType_TTB_ACUTE           :
          case HEADParamOutType_TTS_PRE             :
          case HEADParamOutType_TTS_ACUTE           :
          case HEADParamOutType_ClosingVel          :
          case HEADParamOutType_ANecLong            :
          case HEADParamOutType_HypProb             :
          case HEADParamOutType_ObjectDist          :
          case HEADParamOutType_ObjectDistLat       :
          case HEADParamOutType_ObjProb             :
          case HEADParamOutType_TTC2                :
          case HEADParamOutType_TTC3                :
          case HEADParamOutType_TTC4                :
          case HEADParamOutType_HypLifetime         :
          case HEADParamOutType_ANecLatAbs          :
          case HEADParamOutType_VRelX               :
          case HEADParamOutType_TTMLongPre          :
          case HEADParamOutType_TTMLongAcute        :
          case HEADParamOutType_EgoLatCurvature     :
          case HEADParamOutType_CustomPar_00_HypIndependent   :
          case HEADParamOutType_CustomPar_01_HypIndependent   :
          case HEADParamOutType_CustomPar_02_HypIndependent   :
          case HEADParamOutType_CustomPar_03_HypIndependent   :
          case HEADParamOutType_CustomPar_04_HypIndependent   :
          case HEADParamOutType_CustomPar_05_HypIndependent   :
          case HEADParamOutType_CustomPar_06_HypIndependent   :
          case HEADParamOutType_CustomPar_07_HypIndependent   :
          case HEADParamOutType_CustomPar_00_HypDependent     :
          case HEADParamOutType_CustomPar_01_HypDependent     :
          case HEADParamOutType_CustomPar_02_HypDependent     :
          case HEADParamOutType_CustomPar_03_HypDependent     :
          case HEADParamOutType_CustomPar_04_HypDependent     :
          case HEADParamOutType_CustomPar_05_HypDependent     :
          case HEADParamOutType_CustomPar_06_HypDependent     :
          case HEADParamOutType_CustomPar_07_HypDependent     :
					case HEADParamOutType_CustomPar_08_HypDependent:
		  case HEADParamOutType_CustomPar_08_HypIndependent   :
		  case HEADParamOutType_CustomPar_09_HypIndependent   :
          #if HEAD_CFG_TURN_ASSIST
          case HEADParamOutType_SteeringAngle                   :
          case HEADParamOutType_TurnIndicatorInSteeringDirection:
          case HEADParamOutType_GasPedal                        :
          case HEADParamOutType_CorridorStopDistance            :
          #endif 
          #if HEAD_CFG_CORRIDOROCCUPANCY
          case HEADParamOutType_CorridorOccupancy               :
		  case HEADParamOutType_ObjMoveDir                      :
          #endif
            {
              /*general parameters/conditions*/
              locError = HEADGSMEvaluateGeneralParameters( pIntermediateResult, &sParamValGeneral, uiOperator,
                                                           uiModuleNr, pInputData, pHyp, eOutType);
            }
            break;        
          default:
            /*type is not specified*/
            locError = GDB_ERROR_UNKNOWN_TYPE;
            break;
          }
        }
        break;
        default:
          /*type is not specified*/
          locError = GDB_ERROR_UNKNOWN_TYPE;
          break;
      }  /*end switch*/
    } /*end loop root-parameter array (affected eOutType)*/
  } /*end loop operator*/
  if(*pIntermediateResult != HEADSpecialBool_False)
  {
   /*will be evaluated at the end of each orGroup,
              here: just set thresholds only if all the relevant conditions of hypothesis are true*/
    float32 fOKTimerThreshold;
    /* there is a minTime Condition triggered by hyp or independent*/
    if(sParamValThisModuleActive[HEADParamOperator_LESSTHAN].bUsed == b_TRUE)
    {
      /* transparent behavior is to handle negative timer thresholds as 0 */
      fOKTimerThreshold = MAX_FLOAT(  ( sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fInTime * 
                                        sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fFactor    ), 0.0f);
      /*is the threshold evaluated for this hyp or independent less than the overall threshold, so set it to overall*/
      sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold = 
                        MIN_FLOAT(sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold, fOKTimerThreshold);
    }
    /* there is a maxTime Condition triggered by hyp or independent*/
    if(sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].bUsed == b_TRUE)
    {
      /* transparent behavior is to handle negative timer thresholds as 0 */
      fOKTimerThreshold = MAX_FLOAT(  ( sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fInTime * 
                                            sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fFactor    ), 0.0f);
      /*is the threshold evaluated this hyp or independent greater than the overall threshold, so set it to overall*/
      sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold = 
                            MAX_FLOAT(sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold, fOKTimerThreshold);
    }
  }
  return locError;
}/* PRQA S 7002,7004,7012 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability */


/*************************************************************************************************************************
  Functionname:         HEADGSMPlaceCurrentInfoIntoParamStruct                                                      */ /*!

  @brief                AutocoderInfo to ParamStruct

  @description          This function is called for every used parameter/condition
                        and puts the values set by the autocoder into the right 
                        ParamStruct which are evaluated later.
                        @startuml
                        Start
                        :get parameter type;
                        :Set Local_Error as none;
                        If((Is parameter out type is not Boolean?)) then (yes)
                          : get operator type;
                        Endif
                        If((Is Parameter main type value?)) then (yes)
                          If((Is parameter out type is Bool?)) then (yes)
                            :update General State Machine Parameter Values;    
                          Else If(((Is parameter out type is other module state Time?)) then (yes)
                            :update other Module In State structure;
                          Else If((Is parameter out type is All conditions for Or group met?)) then (yes)
                            :Update param value this module Active structure;
                          Else If ((All Other parameter out Type)) then (valid_parameter)
                            :update general param value structure;
                            Note
                            In case of two values with same eOutType,
                            OrGroup,mode,class etc the stronger 
                            condition will be checked
                            end note
                          else (parameter out type invalid)
                            :Set unknown type error;
                          Endif
                        Else If ((Is Parameter main type factor)) then (yes)
                          If((Is parameter out type is OtherModuleStateTime?)) then (yes)
                            :Update other module in state structure;
                            Note 
                            search for right rule with the same bitpack 
                            and operator to add factor there
                            End note   
                          Else if ((Is parameter out type is AllConditionsForOrGroupMet)) then (yes)
                            :Update this module active structure;
                          Else if ((All Other parameter out Type)) then (valid_parameter)
                            :update general param value structure;
                          Else if ((ParameterOutTypeBoolea)OR(ParameterOutTypeInvalid))
                            :Set unknown type Error;
                          Endif
                        Else (parameter main type invalid)
                          :Set unknown type Error;
                        Endif
                          :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error,  otherwise an error code is returned.

  @param[in,out]        sParamValGeneral : Pointer to General Param value
  @param[in,out]        sParamValOMIS : Pointer to Other Module in State Structure
  @param[in]            sParamValThisModuleActive : Module Active Param Value   
  @param[in]            pParam : pointer to a Parameter
  @param[in]            eOutType : Parameter Output Type
  @param[in]            fValue : Value need to be evaluate
  
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
static eGDBError_t HEADGSMPlaceCurrentInfoIntoParamStruct(
                                HEADGSMParamValues_t *sParamValGeneral,
                                HEADOtherModuleInState_t *sParamValOMIS,
                                HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                const HEADParameterEmpty_t *pParam,
                                const eHEADParamOutType_t eOutType,
                                const float32 fValue)
{
  uint8 uiOtherModCnt;
  boolean bModFound;
  eHEADParamOperator_t eParOperator = HEADParamOperator_LESSTHAN;
  const HEADParameterType_t *locParameterType = &(pParam->ParameterType.sParameterType);
  eGDBError_t locError = GDB_ERROR_NONE;

  /*Bool: always LESSTHAN; others: set Operator*/
  if (locParameterType->ParamOutType != (uint8)HEADParamOutType_Bool) 
  {
    eParOperator = (locParameterType->ParamOperator == 0) ? HEADParamOperator_LESSTHAN: HEADParamOperator_GREATERTHAN; 
  }

  /*GUI: value defines - switch: value|factor*/
  switch(locParameterType->ParamMainValueType)
  {
    case (HEADParamMainValueType_t)HEADParamMainValueType_Value:
    {
      switch (eOutType)
      {        
        case HEADParamOutType_Bool:
        {
          /*GUI: value == bool*/
          if(sParamValGeneral->bUsed == b_FALSE)
          {
            sParamValGeneral->fVal = (fValue > BOOL_BORDER) ? BOOL_FLOAT_TRUE : BOOL_FLOAT_FALSE;
            sParamValGeneral->bUsed = b_TRUE;
            sParamValGeneral->eOperator = eParOperator;
            sParamValGeneral->uiBitPack = pParam->uiSpecialParInfo; 
          }
          else
          {
            sParamValGeneral->fVal = ((fValue > BOOL_BORDER) && (sParamValGeneral->fVal > BOOL_BORDER) )? BOOL_FLOAT_TRUE : BOOL_FLOAT_FALSE;
          }              
        }
        break;
        /*GUI: c-identifier == HEADParamOutType_OtherModuleStateTime ? ->special for other module state time (over hyps)*/
        case HEADParamOutType_OtherModuleStateTime:
        {
          if(sParamValOMIS->uiNrOfChecksUsed < HEAD_AUTO_CFG_NO_OMIS)
          {
            sParamValOMIS->fInTime[sParamValOMIS->uiNrOfChecksUsed] = fValue;
            sParamValOMIS->uiBitPack[sParamValOMIS->uiNrOfChecksUsed] = pParam->uiSpecialParInfo;
            sParamValOMIS->eOperator[sParamValOMIS->uiNrOfChecksUsed] = eParOperator;
            sParamValOMIS->fFactor[sParamValOMIS->uiNrOfChecksUsed] = 1.0f;
            sParamValOMIS->uiNrOfChecksUsed++;
          }
          else
          {
            locError = GDB_ERROR_ARRAY_OVERFLOW;
          }              
        }
        break;
        /*GUI: c-identifier == HEADParamOutType_AllConditionsForOrGroupMet? -> special for function active time (over hyps)*/
        case HEADParamOutType_AllConditionsForOrGroupMet:
        {
          if(sParamValThisModuleActive[eParOperator].bUsed == b_FALSE)
          {
            sParamValThisModuleActive[eParOperator].fInTime = fValue;
            sParamValThisModuleActive[eParOperator].eOperator = eParOperator;
          }
          else if (eParOperator == HEADParamOperator_LESSTHAN)
          {
            /*Operator is already used and less than*/
            sParamValThisModuleActive[eParOperator].fInTime = MIN_FLOAT(fValue, sParamValThisModuleActive[eParOperator].fInTime);
          }
          else
          {
            /*Operator is already used and greater than*/
            sParamValThisModuleActive[eParOperator].fInTime = MAX_FLOAT(fValue, sParamValThisModuleActive[eParOperator].fInTime);
          }
          sParamValThisModuleActive[eParOperator].bUsed = b_TRUE;
          sParamValThisModuleActive[eParOperator].bUsedOverall = b_TRUE;
        }
        break;
        case HEADParamOutType_OtherOrGroupIsTrue  :
        case HEADParamOutType_StateActiveTime     :
        case HEADParamOutType_OrGroupInhibition   :
        case HEADParamOutType_EgoVelocity         :
        case HEADParamOutType_EgoAccel            :
        case HEADParamOutType_SafeObjDistSfty     :
        case HEADParamOutType_SafeObjDistPerf     :
        case HEADParamOutType_DriverFeedbackProb  :
        case HEADParamOutType_DriverActivityProb  :
        case HEADParamOutType_DriverAttentionProb :
        case HEADParamOutType_TTC                 :
        case HEADParamOutType_TTB_PRE             :
        case HEADParamOutType_TTB_ACUTE           :
        case HEADParamOutType_TTS_PRE             :
        case HEADParamOutType_TTS_ACUTE           :
        case HEADParamOutType_ClosingVel          :
        case HEADParamOutType_ANecLong            :
        case HEADParamOutType_HypProb             :
        case HEADParamOutType_ObjectDist          :
        case HEADParamOutType_ObjectDistLat       :
        case HEADParamOutType_ObjProb             :
        case HEADParamOutType_TTC2                :
        case HEADParamOutType_TTC3                :
        case HEADParamOutType_TTC4                :
        case HEADParamOutType_HypLifetime         :
        case HEADParamOutType_ANecLatAbs          :
        case HEADParamOutType_VRelX               :
        case HEADParamOutType_TTMLongPre          :
        case HEADParamOutType_TTMLongAcute        :
        case HEADParamOutType_EgoLatCurvature     :
        case HEADParamOutType_SensorSource        :
        case HEADParamOutType_CustomPar_00_HypIndependent   :
        case HEADParamOutType_CustomPar_01_HypIndependent   :
        case HEADParamOutType_CustomPar_02_HypIndependent   :
        case HEADParamOutType_CustomPar_03_HypIndependent   :
        case HEADParamOutType_CustomPar_04_HypIndependent   :
        case HEADParamOutType_CustomPar_05_HypIndependent   :
        case HEADParamOutType_CustomPar_06_HypIndependent   :
        case HEADParamOutType_CustomPar_07_HypIndependent   :
        case HEADParamOutType_CustomPar_00_HypDependent     :
        case HEADParamOutType_CustomPar_01_HypDependent     :
        case HEADParamOutType_CustomPar_02_HypDependent     :
        case HEADParamOutType_CustomPar_03_HypDependent     :
        case HEADParamOutType_CustomPar_04_HypDependent     :
        case HEADParamOutType_CustomPar_05_HypDependent     :
        case HEADParamOutType_CustomPar_06_HypDependent     :
        case HEADParamOutType_CustomPar_07_HypDependent     :
		case HEADParamOutType_CustomPar_08_HypDependent:
		case HEADParamOutType_CustomPar_08_HypIndependent   :
		case HEADParamOutType_CustomPar_09_HypIndependent   :
        #if HEAD_CFG_TURN_ASSIST
        case HEADParamOutType_SteeringAngle                   :
        case HEADParamOutType_TurnIndicatorInSteeringDirection:
        case HEADParamOutType_GasPedal                        :
        case HEADParamOutType_CorridorStopDistance            :
        #endif
        #if HEAD_CFG_CORRIDOROCCUPANCY
        case HEADParamOutType_CorridorOccupancy               :
		case HEADParamOutType_ObjMoveDir:
        #endif
        {
          /*in case of two values with same eOutType,OrGroup,mode,class etc
            the stronger condition will be checked*/
          if(sParamValGeneral->bUsed == b_TRUE)
          {
            if( (eParOperator == HEADParamOperator_LESSTHAN)
              &&(fValue < sParamValGeneral->fVal)
              )
            { 
              sParamValGeneral->fVal = fValue; 
            }
            else if(  (eParOperator == HEADParamOperator_GREATERTHAN)
                    &&(fValue > sParamValGeneral->fVal)
                   )
            {
              sParamValGeneral->fVal = fValue; 
            }
            else
            { /*do nothing*/}
          }
          else
          {
            sParamValGeneral->fVal = fValue;
            /*for these the special info is exactly the f16*/
            sParamValGeneral->uiBitPack = pParam->uiSpecialParInfo; 
            sParamValGeneral->fDefVal = 0.0f;
            sParamValGeneral->bUsed = b_TRUE;
            sParamValGeneral->eOperator = eParOperator;
          }
        }
        break;
        default:
          locError = GDB_ERROR_UNKNOWN_TYPE;
          break;

      } //end switch eOutType
    }
    break;  

    case (HEADParamMainValueType_t)HEADParamMainValueType_Factor:
    {
      switch (eOutType)
      {
        /*special for other module state time*/  
        case HEADParamOutType_OtherModuleStateTime:
        {
          /*search for right rule with the same bitpack and operator to add factor there*/
          bModFound = b_FALSE;
          for(uiOtherModCnt = 0u; (uiOtherModCnt < sParamValOMIS->uiNrOfChecksUsed) && (bModFound == b_FALSE); uiOtherModCnt++)
          {
            if( (sParamValOMIS->uiBitPack[uiOtherModCnt] == pParam->uiSpecialParInfo)
              &&(sParamValOMIS->eOperator[uiOtherModCnt] == eParOperator)
              )
            {
              bModFound = b_TRUE;
              sParamValOMIS->fFactor[uiOtherModCnt]*= fValue;
            }
          }
          if(bModFound == b_FALSE)
          {
            locError = GDB_ERROR_UNKNOWN_TYPE;
          }
        }
        break;
        /*special for function active time*/ 
        case HEADParamOutType_AllConditionsForOrGroupMet:
        {
          sParamValThisModuleActive[eParOperator].fFactor *= fValue;
        }
        break;
        /*all others*/
        case HEADParamOutType_OtherOrGroupIsTrue  :
        case HEADParamOutType_StateActiveTime     :
        case HEADParamOutType_EgoVelocity         :
        case HEADParamOutType_EgoAccel            :
        case HEADParamOutType_SafeObjDistSfty     :
        case HEADParamOutType_SafeObjDistPerf     :
        case HEADParamOutType_DriverFeedbackProb  :
        case HEADParamOutType_DriverActivityProb  :
        case HEADParamOutType_DriverAttentionProb :
        case HEADParamOutType_TTC                 :
        case HEADParamOutType_TTB_PRE             :
        case HEADParamOutType_TTB_ACUTE           :
        case HEADParamOutType_TTS_PRE             :
        case HEADParamOutType_TTS_ACUTE           :
        case HEADParamOutType_ClosingVel          :
        case HEADParamOutType_ANecLong            :
        case HEADParamOutType_HypProb             :
        case HEADParamOutType_ObjectDist          :
        case HEADParamOutType_ObjectDistLat       :
        case HEADParamOutType_ObjProb             :
        case HEADParamOutType_TTC2                :
        case HEADParamOutType_TTC3                :
        case HEADParamOutType_TTC4                :
        case HEADParamOutType_HypLifetime         :
        case HEADParamOutType_ANecLatAbs          :
        case HEADParamOutType_VRelX               :
        case HEADParamOutType_TTMLongPre          :
        case HEADParamOutType_TTMLongAcute        :
        case HEADParamOutType_EgoLatCurvature     :
        case HEADParamOutType_SensorSource        :
        case HEADParamOutType_CustomPar_00_HypIndependent   :
        case HEADParamOutType_CustomPar_01_HypIndependent   :
        case HEADParamOutType_CustomPar_02_HypIndependent   :
        case HEADParamOutType_CustomPar_03_HypIndependent   :
        case HEADParamOutType_CustomPar_04_HypIndependent   :
        case HEADParamOutType_CustomPar_05_HypIndependent   :
        case HEADParamOutType_CustomPar_06_HypIndependent   :
        case HEADParamOutType_CustomPar_07_HypIndependent   :
        case HEADParamOutType_CustomPar_00_HypDependent     :
        case HEADParamOutType_CustomPar_01_HypDependent     :
        case HEADParamOutType_CustomPar_02_HypDependent     :
        case HEADParamOutType_CustomPar_03_HypDependent     :
        case HEADParamOutType_CustomPar_04_HypDependent     :
        case HEADParamOutType_CustomPar_05_HypDependent     :
        case HEADParamOutType_CustomPar_06_HypDependent     :
        case HEADParamOutType_CustomPar_07_HypDependent     :
		case HEADParamOutType_CustomPar_08_HypDependent:
		case HEADParamOutType_CustomPar_08_HypIndependent   :
		case HEADParamOutType_CustomPar_09_HypIndependent   :
        #if HEAD_CFG_TURN_ASSIST
        case HEADParamOutType_SteeringAngle                   :
        case HEADParamOutType_TurnIndicatorInSteeringDirection:
        case HEADParamOutType_GasPedal                        :
        case HEADParamOutType_CorridorStopDistance            :
        #endif
        #if HEAD_CFG_CORRIDOROCCUPANCY
        case HEADParamOutType_CorridorOccupancy               :
		case HEADParamOutType_ObjMoveDir:
        #endif
        {
          sParamValGeneral->fFact *= fValue;
        }
        break;
        case HEADParamOutType_Bool                :
        default:
          locError = GDB_ERROR_UNKNOWN_TYPE;
        break;  
      }
    }
    break;
    default: 
      locError = GDB_ERROR_UNKNOWN_TYPE;
    break;  
  }
  return locError;
} /* PRQA S 7004 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing cyclomatic complexity for better code maintainability */



/*************************************************************************************************************************
  Functionname:         HEADGSMParamValidForEval                                                                    */ /*!

  @brief                Check if parameter should be evaluated

  @description          This function checks if the parameter is valid for the evaluation.
                        There is a hypothesis/no hypothesis (hypSubType: !0 / 0)
                          The parameter can be...
                          -...hyp dependent or independent (bfParamhypSubType: !0 / 0)
                          -...hyp independent and become dependent by a hyp dependent factor.

                          +---------------------------------\------------------------------------------+
                          |                                  \  bfIgnoreHypSubTypes & bfParamHypSubType|
                          | hypSubType &/&& bfParamhypSubType \         0           |        1         |
                          +---------------+--------------------\--------------------+------------------+
                          |       0       |       0     =>  0  |         E          |       (B)        |
                          |       0       |      !0     =>  0  |         I          |        B         |
                          |      !0       |       0     =>  0  |        (E)         |       (E)        |
                          |      !0       |      !0     =>  0  |         I          |        I         |
                          |      !0       |      !0     =>  1  |         E          |       (B)        |
                          +---------------+--------------------+--------------------+------------------+
                             E = Evaluate
                             B = Break
                             I = Ignore (and go on)
                             ()= impossible case
                        @startuml
                        Start
                            If(check hypothesis and Parameter hypothesis Sub Type is 
                            equal to zero or check Current hypothesis 
                            Type matches parameter hypothesis Type) then (Yes)
                            : the values of this parameter can be assigned 
                              to the parameter structure;
                            elseif (check hypothesis is dependent or not and  
                            check parameter hypothesis is independent or not) Then (Yes)
                            : the values of this parameter can be assigned 
                              to the parameter structure;

                            elseif(Is hypothesis independent? && is parameter hypothesis dependent ? 
                            && check Current Ignore hypothesis Type matches parameter 
                            hypothesis Type || Ishypothesis and parameter hypothesis  dependent ? 
                            && check Current Ignore hypothesis Type matches parameter hypothesis Type) then (True)
                            : Not checked parameter value is updated;

                            else
                            : update parameter return value is FALSE;
                            endif
                        Stop
                        @enduml
                          
  @return               void

  @param[in]            hypSubType : Triggerd CD Hypothesis type
  @param[in]            bfParamHypSubType : Hypothesis Used in the Parameter
  @param[in]            bfIgnoreHypSubTypes : Hypothesis Needed to be ignored for evaluation
  @param[in,out]        eRetValue : pointer to return value
  
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
static void HEADGSMParamValidForEval( HEADParameterHypothesisSub_t hypSubType, 
                                      HEADParameterHypothesisSub_t bfParamHypSubType, 
                                      HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                      eHEADSpecialBool_t *eRetValue)
{
        /*Hypo-independent param evaluation and Param is flagged as Hypo independent */ 
  if(   ( ( hypSubType == 0u ) &&  ( bfParamHypSubType   == 0u )  )  
        /* Current Hypo-Type matches parameter Hypo-Type*/
    ||  ( ( hypSubType        &     bfParamHypSubType ) != 0u    )
    )
  {
    /*Param is flagged as "always" or Hypothesis matches Hypothesis selection in Param */
    /*the values of this parameter can be assgined to the param structs*/
    *eRetValue = HEADSpecialBool_True;  
  } 
          /* Hypo dependend evaluation but parameter is flagged as Hypo independent */
  else if( ( hypSubType != 0u ) &&  ( bfParamHypSubType   == 0u )  ) 
  {
    /*All parameters that are marked "always" are collected for "maybe" later use in hypothesis evaluation */
    /*the values of this parameter can be assgined to the param structs but only set it to checked. 
      This parameter type will only be evaluated with an hyp dependent factor*/  
    *eRetValue = HEADSpecialBool_checked; 
  } 
    /*Hypo-independent param evaluation && Parameter is flagged as Hypo-Dependend && None of the flagged Hypos in the param was already evaluated */
  else if ( ( ( hypSubType == 0u ) && (  bfParamHypSubType  != 0u  ) && ( (  bfIgnoreHypSubTypes  & bfParamHypSubType) == 0u) ) 
           /* Hypo dependend evaluation and at least one Hypo flag is set, but they do not match */ 
          ||( ((hypSubType != 0u ) && (  bfParamHypSubType  != 0u) ) && ( (  hypSubType           & bfParamHypSubType) == 0u) )
          )
  {
    /* the current parameter must not be used in current evaluation step */
    /*these cases can be ignored*/
    *eRetValue = HEADSpecialBool_notchecked;
  }
  else /* Hypo-independent param evaluation && Parameter is flagged as Hypo-Dependend && at least one of the flagged Hypos in the param was already evaluated */
    /*if( (   hypSubType == 0 ) && (  bfParamHypSubType  != 0   ) && (  (bfIgnoreHypSubTypes & bfParamHypSubType) != 0) )*/
  {
    /* parameter type was already evaluated in another step and must not be evaluated again*/
    *eRetValue = HEADSpecialBool_False;
  }
}


/*************************************************************************************************************************
  Functionname:         HEADGSMEvaluateGeneralParameters                                                            */ /*!

  @brief                Evaluates Values in ParamStruct

  @description          This function evaluates the values from ParamStruct (Endvalue = Value*Factor)
                        and returns the IntermediateResult.
                        As parameters can be either hyp dependent or independent, there are two separate evaluation processes.
                        @startuml
                        Start
                        If ((is Patameter Value used)) then (yes)
                            : Checks if the parameter is a hypothesis dependent or 
                            independent parameter;
                            if ((No_Error) AND (Hypotheis Dependent Parameter)) then (yes)
                                :Get hypothesis output type; 
                                Note:Get hypothesis Output type based on param output type;
                                If ((No_Error))
                                :Get Hypothesis Value;
                                    If ((Value Not Found) AND (No_Error)) then (yes)
                                    :Set Default value as Parameter value;
                                    endif
                                endif
                            elseif ((No_Error)) then (yes)
                                :Get Parameter Value from Input Date;
                                Note: hypothesis independent parameter
                            Endif
                            If ((No_Error)) then (yes)
                                :Get Parameter Result;
                                Note:Get the result if the condition of the param type is met
                                If ((Is Condition met?)) then (yes)
                                    :Set Result as True;
                                Else
                                    :Set Result as False;
                                Endif
                            Else 
                            :Set Result as False;
                            Note:Error happend
                            Endif
                        Endif
                        Stop
                        @enduml      
                                  
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            sParamValGeneral : General Param value
  @param[in]            uiOperator : Used operator in the Parameter
  @param[in]            uiModuleNr : Module Number 
  @param[in]            pInputData : Pointer to Input data
  @param[in]            pHyp : Triggerd CD Hypothesis
  @param[in]            eOutType : Parameter Output Type
  
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
static eGDBError_t HEADGSMEvaluateGeneralParameters(eHEADSpecialBool_t *pIntermediateResult,
                                                    const HEADGSMParamValues_t *sParamValGeneral,
                                                    const uint8 uiOperator,
                                                    const uint8 uiModuleNr, 
                                                    const struct HEADInputData_t *pInputData, 
                                                    const HEADHypothesis_t *pHyp,
                                                    const eHEADParamOutType_t eOutType)
{
  boolean bTempCondition;
  float32 fParamValue = 0.0f;
  boolean bFound = b_FALSE;
  eGDBError_t locError = GDB_ERROR_NONE;

  if(sParamValGeneral->bUsed == b_TRUE)
  { 
    boolean bIsHypDependent = b_FALSE;
    /*Initialize tempCondition to FALSE*/
    bTempCondition = b_FALSE;
    
    locError = HEADIsHypDependentParameter(eOutType, &bIsHypDependent);
    if( (locError == GDB_ERROR_NONE) && (bIsHypDependent == b_TRUE) )
    {
      /*get hyp dependent parameters*/
      eHEADHypOutType_t eHypOutType;
      locError = HEADParamOutTypeToHypOutType(eOutType, &eHypOutType);
      if (locError == GDB_ERROR_NONE)
      {
        /*set fParamValue*/
        locError = HEADGetHypValue( pInputData, pHyp, eHypOutType, uiModuleNr, &bFound, &fParamValue);
        /*set default value if no error but ParmamValue not found*/
        if( (locError == GDB_ERROR_NONE)
          &&(bFound == b_FALSE)
          )
        {
          fParamValue = sParamValGeneral->fDefVal;
        }
      }
    }
    else if(locError == GDB_ERROR_NONE)
    {
      /*get hyp independent parameters*/
      locError = HEADGSMGetIndValue(pInputData, eOutType, uiModuleNr, &fParamValue);
    }
    else
    {
      /*Error*/
    }
    /*evaluate the result for this parametertype if no error happend during evaluation of getfunctions*/
    if(locError == GDB_ERROR_NONE)
    {
      locError = HEADGSMGetParamResult( sParamValGeneral->fVal, sParamValGeneral->fFact,
                                        fParamValue, uiOperator, &bTempCondition); 

      /*merge the condition to the temporary condition*/
      if(bTempCondition == b_TRUE)
      {
        /*the intermediateResult is set to true here. Possible values before: true/notchecked*/
        *pIntermediateResult = MIN(*pIntermediateResult, HEADSpecialBool_True);
      }
      else
      {
        /*if a relevant condition is evaluated to false, then the intermediateResult is false*/
        *pIntermediateResult = HEADSpecialBool_False;
      }
    }
    else
    {
      /*Error happend*/
      *pIntermediateResult = HEADSpecialBool_False;
    }
  }/*end: bUsed*/
  return locError;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMGetParamResult                                                                       */ /*!

  @brief                get the result if the condition of the param type is met

  @description          If the condition for the parameter is met set result as True else false
                        @startuml
                        Start
                        :Find the End Value;
                        Note: End Value is the product of the settings in Autocoder
                        If ((Is LESSTHAN Operator used in the parameter?)) then (yes)
                            If ((Parameter value is less than End Value?)) then (yes)
                            :Set Condition as True;
                            Else
                            :Set Condition as False;
                            Endif
                        Elseif ((Is GREATERTHAN Operator used in the parameter?)) then (yes)
                            If ((Parameter value is greater than End Value?)) then (yes)
                            :Set Condition as True;
                            Else
                            :Set Condition as False;
                            Endif
                        Else
                            :Set Condition as False;
                            :Set Error as Unknown;
                        Endif
                        stop
                        @enduml
                          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise Error correspond to type Unknown.

  @param[in]            fValue : Value need to be evaluate
  @param[in]            fFact : Factorial value
  @param[in]            fParamValue : Param Value
  @param[in]            uiOperator :  operator Used in the Parameter
  @param[out]           bTempCondition : evaluation Result
  
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
static eGDBError_t HEADGSMGetParamResult( float32 fValue, float32 fFact, 
                                          float32 fParamValue, uint8 uiOperator, 
                                          boolean *bTempCondition)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  float32 fEndValue;
  /*fEndValue is the product of the settings in Autocoder*/
  fEndValue = fValue * fFact;
  switch(uiOperator)
  {
  case (uint8) HEADParamOperator_LESSTHAN:
    *bTempCondition = (fParamValue <= fEndValue)? b_TRUE : b_FALSE;
    break;

  case (uint8) HEADParamOperator_GREATERTHAN: 
    *bTempCondition = (fParamValue >= fEndValue)? b_TRUE : b_FALSE;
    break;

  case (uint8) HEADParamOperator_DEFAULT:
  default:
    /* this case may not happen, but should be an error*/
    *bTempCondition = b_FALSE;
    locError = GDB_ERROR_UNKNOWN_TYPE;
    break;
  }
  return locError;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMCheckOtherOrGroup                                                                    */ /*!

  @brief                Check if other orGroup in the same module is true or not

  @description          This function checks if another orGroup in the same module is true or not for a specific time. 
                        Attention: timer are increades each orGroup after their own check
                        --> checking a smaller orGroup number will have updated timers
                        --> checking a higher orGroup number will be delayed by one cycle
                        @startuml
                        Start
                        :Fetch the orGroup; 
                        Note: Fetch the orGroup that Need to be checked. 
                        :Fetch the needed Condition;
                        Note:Fetch the condition that either need to be True or False.
                        :Find Timer Index;
                        Note:Timer Index is based on orGroup and Module State
                        :Evaluate the Condition;
                        If ((No_Error)) then (yes)
                            If ((ConditionNeeded==True) AND (EvaluatedCondition==True)) then (yes)
                            :Set Result as True;
                            Elseif ((ConditionNeeded==False) AND (EvaluatedCondition== False)) then (yes)
                            :Set Result as True;
                            Else 
                            :Do Nothing;
                            Endif
                        Else
                            :Set Result as False;
                        Endif
                        Stop
                        @enduml
                          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            pModule : Pointer to a Module
  @param[in]            sParamValGeneral : General Param value
  @param[in]            eState :  Module State
  
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
static eGDBError_t HEADGSMCheckOtherOrGroup(eHEADSpecialBool_t *pIntermediateResult,
                                            const struct HEADModule_t *pModule,
                                            const HEADGSMParamValues_t *sParamValGeneral,
                                            const eHEADParameterState_t eState)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  boolean bTempCondition = b_FALSE;
  uint8 uiOrGroup    = HEADBitPackToOtherOrGroup_OrGroupNr(sParamValGeneral->uiBitPack);
  boolean bTrueFalse = HEADBitPackToOtherOrGroup_MustBeTrueFalse(sParamValGeneral->uiBitPack);
  const uint32 uiTimerIdx = (uiOrGroup*2u)+(((uint32)eState)%2u);

  /* QAC 0491: the pointer pfConditionsOKTimer is an array with known length */
  /*PRQA S 0491 3*/
  locError = HEADGSMGetParamResult( sParamValGeneral->fVal,
                                    sParamValGeneral->fFact,
                                    ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal))->pfConditionsOKTimer[uiTimerIdx],
                                    (uint8)(sParamValGeneral->eOperator),
                                    &bTempCondition);

  /*bTempCondition is initialized with FALSE and can only be set to true*/
  if (locError == GDB_ERROR_NONE)
  {
    if( (bTrueFalse == b_TRUE) && (bTempCondition == b_TRUE) )
    {
      *pIntermediateResult = HEADSpecialBool_True;
    }
    else if ( (bTrueFalse == b_FALSE) && (bTempCondition == b_FALSE) )
    {
      *pIntermediateResult = HEADSpecialBool_True;
    }
    else
    {
      /*nothing to do*/
    }
  }
  else
  {
    *pIntermediateResult = HEADSpecialBool_False;
  }
  return locError;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMEvaluateOtherModuleInState                                                           */ /*!

  @brief                Checks for OtherModuleInState

  @description          This function checks if another module is (not) in a specified state
                        for more/less than a defined time and returns the IntermediateResult.
                        @startuml
                        Start
                        While(Is maximum  number of other Module InState values and number checks used greater than count?)is (True)
                            : Get current state;
                            If(Is module state and module numbers valid?) then (Yes)
                                If(check intermediate result is true or not checked) then (Yes)
                                    :update current module;
                                    If(check for module IN state) then (Yes)
                                        If(check for state of the module) then (True)
                                            :update local parameter result;
                                        Endif
                                    Else 
                                        If(check for module not in state) then (Yes)
                                            :update local parameter result;
                                        Endif
                                    Endif
                                    If(Is temp condition true? And check local is no error ) then (Yes)
                                        Note right 
                                        Temp Condition is initialized with FALSE
                                        End note
                                        : update intermediate result is true;
                                    Else
                                        : update intermediate result is false;
                                    Endif
                                endif
                            else
                                : update intermediate result and local Error
                                is false and out of bounds;
                            endif
                        endwhile (false)
                        :Return the local error;
                        Stop
                        @enduml
                          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[in,out]        pIntermediateResult : pointer to intermediate result 
  @param[in]            pInputData : pointer to input data
  @param[in]            sParamValOMIS : pointer to other Module in State Structure
  
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
static eGDBError_t HEADGSMEvaluateOtherModuleInState( eHEADSpecialBool_t *pIntermediateResult,
                                                      const struct HEADInputData_t *pInputData, 
                                                      const HEADOtherModuleInState_t *sParamValOMIS)
{
  uint8 uiICnt;
  uint8 uiModNr;
  eHEADSMState_t eStateToCheck;
  HEADModule_t const *pCurrModule;
  eGDBError_t locError = GDB_ERROR_NONE;

  /*go for timing parameters*/
  for(uiICnt = 0u; (uiICnt < sParamValOMIS->uiNrOfChecksUsed) && (uiICnt < HEAD_AUTO_CFG_NO_OMIS) && (locError == GDB_ERROR_NONE); uiICnt++)
  {
    boolean bTempCondition = b_FALSE;
    uiModNr = HEADBitPackToOtherModuleStateTime_ModuleNr(sParamValOMIS->uiBitPack[uiICnt]);
    /* QAC 1482: the States in Bitpack are always less then HEADSMState_Max */
    /*PRQA S 4394, 1482 1*/
    eStateToCheck = HEADBitPackToOtherModuleStateTime_ModuleState(sParamValOMIS->uiBitPack[uiICnt]);

    /*module nr and state valid ?*/
    if( (uiModNr < pInputData->pModuleList->uiNrOfModules) 
      &&(pInputData->pModuleList->rgModules != NULL)
      &&(eStateToCheck < HEADSMState_Max)
      )
    {
      /* do further checks only if this can change the output i. e. if already false or checked 
         (will be later interpreted as false) final state of "AND" can not be change to true any more */
      if( (*pIntermediateResult == HEADSpecialBool_True) 
          ||(*pIntermediateResult == HEADSpecialBool_notchecked)
          )
      {
        
        pCurrModule = HEADGetModule(pInputData->pModuleList,(uint32)uiModNr);
        /*module should be IN state*/
        if (HEADBitPackToOtherModuleStateTime_MustBeInState(sParamValOMIS->uiBitPack[uiICnt]) != b_FALSE)
        {
          /*is the current STATE of the modul with Nr. uiICnt in the STATE that it should be according to the autocoder */
          if(pCurrModule->eSMState == eStateToCheck)
          {
            locError = HEADGSMGetParamResult( sParamValOMIS->fInTime[uiICnt],
                                              sParamValOMIS->fFactor[uiICnt],
                                              pCurrModule->fStateTimer[(uint8) eStateToCheck],
                                              (uint8)(sParamValOMIS->eOperator[uiICnt]), &bTempCondition);
          }
        }
        /*module should be NOT IN state*/
        else
        {
          /*is the the modul in any STATE but not in the STATE that it should be according to the autocoder */
          if (pCurrModule->eSMState != eStateToCheck)
          {
            locError = HEADGSMGetParamResult( sParamValOMIS->fInTime[uiICnt],
                                              sParamValOMIS->fFactor[uiICnt],
                                              pCurrModule->fNotInStateTimer[(uint8) eStateToCheck],
                                              (uint8)(sParamValOMIS->eOperator[uiICnt]), &bTempCondition);
          }   
        }

        /*bTempCondition is initialized with FALSE and can only be set to true*/
        if (  (bTempCondition == b_TRUE) && (locError == GDB_ERROR_NONE) )
        {
          *pIntermediateResult = HEADSpecialBool_True;
        }
        else
        {
          *pIntermediateResult = HEADSpecialBool_False;
        }
      }
    }
    else
    {
      /*ERROR*/
      locError = GDB_ERROR_ARRAY_OVERFLOW;
      *pIntermediateResult = HEADSpecialBool_False;
    }
  }
  return locError;
}


/*************************************************************************************************************************
  Functionname:         HEADGSMEvaluateActiveModuleTime                                                             */ /*!

  @brief                General State Machine to evaluate Active Module Time

  @description          This function may manipulate the overall result of the parameter evaluation in case the parameter 
                        "All Conditions are true for at least/most x s" is used In this case the outcome "true" is 
                        delayed (at least) by that value or (at most) limited in time.
                        No plausibility checks are performed! (Change in logic compared to previous version)

                        No pointer checks are performed for the following pointers. Calling function shall assert 
                        that the pointers are valid.
                        bConditionTrue, sParamValThisModuleActive, pModule
                        @startuml
                        Start
                        :Find Timer Index;
                        Note:Timer Index is based on orGroup and Module State
                        If ((Timing Parameter LESSTHAN is used) AND
                        (Timer is greater than the threshold)) then (yes)
                            :Set condition False;
                        Endif
                        If ((Timing Parameter GREATERTHAN is used) AND
                        (Timer is less than the threshold)) then (yes)
                            :Set condition False;
                        Endif
                        Stop
                        @enduml

  @return               void 

  @param[out]           bConditionTrue : Boolean variable represent condtion True of false
  @param[in]            sParamValThisModuleActive : Module Active Param Value
  @param[out]           pModule : Pointer to a Module
  @param[in]            uiOrGroup : orGroup Number
  @param[in]            eState : Enum Value Module State
  
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
static void HEADGSMEvaluateActiveModuleTime(boolean *bConditionTrue,
                                            const HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                            const HEADModule_t *pModule,
                                            HEADParameterOrGroup_t uiOrGroup,
                                            eHEADParameterState_t eState)
{
  const uint32 uiTimerIdx = (uiOrGroup*2u)+(((uint32)eState)%2u);
  /* QAC 0491: the pointer pfConditionsOKTimer is an array with known length */
  /*PRQA S 0491 15*/
  /* Timing Parameter LESSTHAN is used */
  if( ((sParamValThisModuleActive[HEADParamOperator_LESSTHAN].bUsedOverall) == b_TRUE) 
    /* Timer is greater than the threshold*/
    &&( ((((HEADModuleInternalGSM_t *)((void *)(pModule->pInternal)))->pfConditionsOKTimer)[uiTimerIdx]) >
              sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold)
    )
  {
    *bConditionTrue = b_FALSE;
  }
    /* Timing Parameter GREATERTHAN is used */
  if( ((sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].bUsedOverall) == b_TRUE)
    /* Timer is less than the threshold*/
    &&( ((((HEADModuleInternalGSM_t *)((void *)(pModule->pInternal)))->pfConditionsOKTimer)[uiTimerIdx]) <
              sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold)
    )
  {
    *bConditionTrue = b_FALSE;
  }
}

/*************************************************************************************************************************
  Functionname:         HEADGSMCreateTypicalModule                                                                  */ /*!

  @brief                creates a gsm module

  @description          creates a gsm module
                        @startuml
                        Start
                            :create a gsm module;
                        Note right
                        ->Constructs and initialize a generic 
                        state machine module.
                        End note
                            :Update internal GSM informaton and 
                            Module Specific Values;
                        Note right
                        Defined by autocode generated settings.
                        End note
                        Stop
                        @enduml
          
  @return               eGDBError_t

  @param[in]            strModuleName : Pointer to Module Name
  @param[in,out]        pModule : Pointer to a Module
  @param[in,out]        pModuleInt : Pointer to Module inetrnal GSM Information
  @param[in]            pModuleParameters : Pointer to Module Parameters
  @param[in,out]        pModuleOutput : Pointer to Module Output
  @param[in]            pModuleOutputParams : Pointer to Module Output Parameters
  @param[in,out]        pfConditionsOKTimer : Pointer to Condition Ok Timer
  @param[in]            uiNumOrGroups : Number of OrGroups in the Module

  @glob_in              None
  @glob_out             None

  @c_switch_part        
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
eGDBError_t HEADGSMCreateTypicalModule(const uint8 *strModuleName, struct HEADModule_t *pModule, 
                                       HEADModuleInternalGSM_t *pModuleInt, HEADParameterEmpty_t *pModuleParameters, 
                                       struct HEADModuleOutputInterface_t *pModuleOutput, const void* pModuleOutputParams,
                                       float32 *pfConditionsOKTimer, const uint8 uiNumOrGroups)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  if ((pModule == NULL) || (pModuleInt == NULL))
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    locError = HEADCreateModule(strModuleName, pModule); /*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
    
    pModuleInt->bInitialized = b_FALSE;
    pModuleInt->pParameterList = pModuleParameters;
    pModuleInt->InternalHeader.fpCustom = &HEADGenericStateMachine;
    pModuleInt->InternalHeader.eModuleInternalType = HEADModuleInternalType_GSM;
    pModuleInt->pfConditionsOKTimer = pfConditionsOKTimer;
    (void)MEDIC_MEMSET(pModuleInt->pfConditionsOKTimer, 0, sizeof(float32)*uiNumOrGroups);/*PRQA S 2869, 0315 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
    pModule->uiNumOrGroups = uiNumOrGroups;
    pModule->pInternal = (HEADModuleInternalInterface_t *)(void *)pModuleInt;
    pModule->pOutput = pModuleOutput;
    pModule->pOutputParams = pModuleOutputParams;
    if ((pModule->pOutput != NULL) && (pModule->pOutput->fpCustomOutput != NULL) )
    {
      /*initialize this output function*/
      locError = (*(pModule->pOutput->fpCustomOutput))(NULL, pModule, b_TRUE);
    } /* if(pModule->pOutput != NULL && pModule->pOutput->fpCustomOutput != NULL) */
    else
    {
      locError = GDB_ERROR_POINTER_NULL;
    }
  }

  return locError;
}

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */
/**@}*//* PRQA S 7013 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/
