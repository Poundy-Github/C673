/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_generic_sm.c

DESCRIPTION:               Implementation of the generic state machine of the HEAD module

AUTHOR:                    $Author: Sekar, Balaji02 (uids6618) $

CREATION DATE:             $Date: 2020/11/10 12:46:13CET $

VERSION:                   $Revision: 1.108 $

LEGACY VERSION:            1.70.1.5 (HEAD 2.0)
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_HEAD20)
#ifndef __PDO__
#include <string.h>
#endif /* ifndef __PDO__ */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head20/head20_int.h"
/* PRQA S 3415,3760 EOF */ /* date: 2019-09-24, reviewer: Sekar, Balaji, reason:If the function righ to && is not called also no side effects */
/*PRQA S 2995, 2996 EOF */ /*date: 2020-08-25, reviewer: Nalina M, reason: defensive programming with parameters*/
/*PRQA S 2985, 2982 EOF */ /*date: 2020-08-25, reviewer: Nalina M, reason: Suppressing because the value will be used in future.*/
/*PRQA S 1881, 4404 EOF */ /*date: 2020-10-21, reviewer: Siri Prakash, reason: Suppressing because Implementation is intended.*/
/*PRQA S 7013 EOF *//* Date: 2018-12-17, Reviewer: Pronnoy Chowdhury, Reason:  suppressed number of executable lines per file. */
/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
/*! @brief       HEAD_MAX_STATE_TIME 
    @general     Maximum SM time allowed in HEAD Module
    @conseq      @incp  [None]
                 @decp  [None]
    @attention   [None]
    @typical     99999.9f   
    @unit        SI-unit 
     
    
*/
#define HEAD_MAX_STATE_TIME           (99999.9f)

/*! @brief       HEAD_MAX_FUNCTION_ACTIVE_TIME 
    @general     Maximum time allowed for a function to be active in HEAD Module
    @conseq      @incp  [None]
                 @decp  [None]
    @attention   [None]
    @typical     9999.9f
    @unit        SI-unit 
     
    
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

    @general        HEAD Special Boolean 
    
    @conseq         Refer attention
    
    @attention      ordering is important!!! don't reorder this enum!!! The most relevant must be "false", the least relevant "not checked"
    
    */
typedef enum /* */
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

    @general        HEAD General State Machine Parameters Values

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  float32               fVal;           /*!< Value */
  float32               fFact;          /*!< Factorial value */
  float32               fDefVal;        /*!< Default value */
  eHEADParamOperator_t  eOperator;      /*!< Operator @ref eHEADParamOperator_t */
  uint16                uiBitPack;      /*!< uiBitPack */
  boolean               bUsed;          /*!< bUsed */
  boolean               bFound;         /*!< Is Value found */ 
} HEADGSMParamValues_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADOtherModuleInState_t
    **************************************************************** */
/*! @brief HEAD Other Module Rule Set Condition Information

    @general Structure to collect rule set conditions for other Modules per OR-Group

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  uint8                 uiNrOfChecksUsed;                   /*!< uiNrOfChecksUsed */
  uint16                uiBitPack[HEAD_AUTO_CFG_NO_OMIS];   /*!< uiBitPack  */
  eHEADParamOperator_t  eOperator[HEAD_AUTO_CFG_NO_OMIS];   /*!< eOperator */
  float32               fInTime[HEAD_AUTO_CFG_NO_OMIS];     /*!< fInTime*/
  float32               fFactor[HEAD_AUTO_CFG_NO_OMIS];     /*!< fFactor */
} HEADOtherModuleInState_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADThisModuleActive_t
    **************************************************************** */
/*! @brief HEAD our Module Rule Set Condition Information

    @general Structure to collect rule set conditions for this Modules per OR-Group

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  boolean               bUsed;          /*!< bUsed*/
  boolean               bUsedOverall;   /*!< bUsedOverall */
  eHEADParamOperator_t  eOperator;      /*!< eOperator*/
  float32               fInTime;        /*!< fInTime */
  float32               fFactor;        /*!< fFactor */
  float32               fThreshold;     /*!< fThreshold */
} HEADThisModuleActive_t;


#if (HEAD_AUTO_CFG_NO_OCG > 0)
/* ****************************************************************
    TYPEDEF STRUCT HEADOtherCondGrpsCheck_t
    **************************************************************** */
/*! @brief HEAD Other Condition Groups check Information

    @general Structure to collect rule set conditions which check Other Condition Groups logic
            SCG is referred to the special condition group having condition of OutType(HEADParamOutType_OtherCondGroups)  
            OCG is referred to the other condition groups used in the condition of OutType(HEADParamOutType_OtherCondGroups)

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  uint8                 uiNrOfChecksUsed;                   /*!< Number of checks(equal to number of SCGs as inside one SCG we consider only one of the special conditions) */
  uint16                uiBitPackOCG[HEAD_AUTO_CFG_NO_OCG]; /*!< OCG bits pack for each SCG  */
  uint8                 uiLinkedSCG[HEAD_AUTO_CFG_NO_OCG];  /*!< Linkedd SCG to each special condition */
  float32               fTime[HEAD_AUTO_CFG_NO_OCG];        /*!< the time threshold value for each SCG */
  float32               fFactor[HEAD_AUTO_CFG_NO_OCG];      /*!< factor value for the condition(OtherCondGroups) of each SCG*/
} HEADOtherCondGrpsCheck_t;
#endif


/*****************************************************************************
  CONSTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
#if ((HEAD_CFG_PRECONDITION == MEDIC_ON) && (MEDIC_ARCHITECTURE_VERSION >= 0x10))
static eGDBError_t HEADGSMCheckPreCond(eHEADSpecialBool_t *pIntermediateResult,  const struct HEADInputData_t *pInputData, uint16 bitpack, const uint8 ModuleNr, const uint8 uiHypNo);
#endif
static eGDBError_t HEADGenericStateMachine(uint8 uiModuleNr, 
                                           const struct HEADInputData_t *pInputData,
                                           boolean bInit);
static eGDBError_t HEADCopyString(uint8 strDestination[], const uint8 strSource[], uint8 strLength);

static HEADSPMQoSMap_t * HEADGetCurrQoSMap(HEADModule_t *pModule, HEADModuleState_t *pState, eGDBError_t *retValue);

static void HEADEvalStateTransitions(HEADModule_t *pModule, HEADModuleState_t *pState, const struct HEADInputData_t * pInputData, 
                                   eHEADSMState_t *eNewState,eGDBError_t *retValue ); 

static eGDBError_t HEADDGSMEvalTransition(HEADModule_t *pModule, HEADStateTransition_t *pTransition, 
                                          const struct HEADInputData_t *pInputData, boolean *pbActiveState, boolean *bConditionTrue);

static eGDBError_t HEADGSMConditionsGroup(HEADModule_t *pModule, 
                                           const HEADStateTransition_t *const pTransition, 
#if (HEAD_AUTO_CFG_NO_OCG > 0)
                                           HEADOtherCondGrpsCheck_t *sParamValOCG, 
#endif
                                           const struct HEADInputData_t *pInputData, boolean *pbCondGrpCheckAbrtRes,
                                           boolean *bGroupConditionTrue, uint16 *puHypInCondGroup);

static void HEADGSMResetParamValOMIS(HEADOtherModuleInState_t *sParamValOMIS);

#if HEAD_CFG_PRECONDITION == MEDIC_ON
static eGDBError_t  HEADGSMIterateHypotheses(const HEADStateTransition_t *const pTransition, HEADModule_t *pModule,
                                             const struct HEADInputData_t *pInputData, const HEADConditionGrp_t *pConditionGrp, eHEADSpecialBool_t* eHypothesisResult,
                                             eHEADSpecialBool_t* eOverallHypResult, HEADParameterHypothesisSub_t rgHypUsed, HEADParameterHypothesisSub_t rgInputHypTriggered,
                                             HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT], boolean bPreCondEval, uint8 PreCondNr);
#endif

#if (HEAD_AUTO_CFG_NO_OCG > 0)
static eGDBError_t HEADGSMResetParamValOCG(HEADOtherCondGrpsCheck_t *sParamValOCG);
#endif

static void HEADGSMInitActiveFunction(HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT], 
                                      boolean initAll);

static void HEADGSMGetParametersToRelevantHyps(const HEADConditionGrp_t *pConditionGrp,
                                               HEADParameterHypothesisSub_t *rgHypUsed,
                                               const struct HEADInputData_t *pInputData);

static void HEADDGSMNextSubGroup(const HEADParameterEmpty_t **pParamList );

static eGDBError_t HEADGSMCheckConditions(HEADModule_t *pModule, const struct HEADInputData_t *pInputData,
                                          const HEADConditionGrp_t *const pConditionGrp,
                                          eHEADSpecialBool_t *pIntermediateResult,
                                          HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                          HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
#if (HEAD_AUTO_CFG_NO_OCG > 0)
                                          HEADOtherCondGrpsCheck_t *sParamValOCG,
#endif
                                          HEADHypothesis_t const *pHyp, const uint8 uiHypNo, boolean bPreCondEval, uint8 PreCondNr, boolean *pbCheckAbrtRes);

static eGDBError_t HEADDGSMEvalParamSubGroup(HEADModule_t *pModule, const struct HEADInputData_t *pInputData, eHEADSpecialBool_t eParamExists, 
                                            eHEADParamOutType_t eOutType,
#if (HEAD_AUTO_CFG_NO_OCG > 0)
                                            const HEADOtherCondGrpsCheck_t *sParamValOCG, 
#endif
                                            const HEADGSMParamValues_t *sParamValGeneral, 
                                            HEADOtherModuleInState_t *sParamValOMIS, uint8 uiOperator, eHEADSpecialBool_t *pIntermediateResult, 
                                            HEADHypothesis_t const *pHyp, const uint8 uiHypNo, uint8 PreCondNr);

static void HEADGSMParamValidForEval( HEADParameterHypothesisSub_t hypSubType, 
                                      HEADParameterHypothesisSub_t bfParamHypSubType, 
                                      HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                      eHEADSpecialBool_t *eRetValue);

#if (HEAD_AUTO_CFG_NO_OCG > 0)
static void HEADGSMCheckParamOCGPresent( HEADOtherCondGrpsCheck_t *sParamValOCG, 
                                         uint8 uiCondGrpNr, 
                                         uint8 *pCondIndex);
#endif

static eGDBError_t HEADGSMPlaceCurrentInfoIntoParamStruct(
                                      HEADGSMParamValues_t *sParamValGeneral,
                                      HEADOtherModuleInState_t *sParamValOMIS,
#if (HEAD_AUTO_CFG_NO_OCG > 0)
                                      HEADOtherCondGrpsCheck_t *sParamValOCG,
                                      uint8 uiCondGrpNr,
#endif
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
                                                    const uint8 uiHypNo,
                                                    const eHEADParamOutType_t eOutType);

#if 0
static eGDBError_t HEADGSMCheckOtherOrGroup(eHEADSpecialBool_t *pIntermediateResult,
  const struct HEADModule_t *pModule,
  const HEADGSMParamValues_t *sParamValGeneral,
  const eHEADParameterState_t eState);
#endif

#if (HEAD_AUTO_CFG_NO_OCG > 0)
static eGDBError_t   HEADAllocateSCGTimer(HEADModule_t *pModule);

static eGDBError_t   HEADSetResetSCGTimer(HEADModule_t *pModule,
                                          const struct HEADInputData_t *pInputData,
                                          boolean bResetTimer);

static eGDBError_t   HEADGetSCGTimer(HEADModule_t *pModule,
                                     float32 *fTimerVal);

static eGDBError_t   HEADResetAllSCGTimers(HEADModule_t *pModule);

static eGDBError_t HEADDGSMOtherCondGrpsAllFalse(uint8 uiSelfCondGrpNr,
                                             const HEADStateTransition_t *const pTransition,
                                             const uint16 uiBitPackOCG,
                                             boolean *bCondGrpsAllFalse);

static eGDBError_t HEADDGSMCheckOtherCondGroups(eHEADSpecialBool_t *pIntermediateResult,
                                                const struct HEADInputData_t *pInputData,
                                                HEADModule_t *pModule,   
                                                const HEADOtherCondGrpsCheck_t *sParamValOCG);
#endif

static eGDBError_t HEADGSMEvaluateOtherModuleInState( eHEADSpecialBool_t *pIntermediateResult,
                                                      const struct HEADInputData_t *pInputData, 
                                                      const HEADOtherModuleInState_t *sParamValOMIS);

static void HEADGSMEvaluateActiveModuleTime(boolean *bConditionTrue,
                                      const HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                      float32 fConditionsOKTimer);

static eGDBError_t HEADGSMGetParamResult( float32 fValue, float32 fFact, 
                                          float32 fParamValue, uint8 uiOperator, 
                                          boolean *bTempCondition);


/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/****************************************************************************************************************************
  Functionname:         HEADGenericStateMachine                                                                         */ /*!

  @brief                run the Dynamic Generic State Machine

  @description          run the Dynamic Generic State Machine for the current module
                        Iterate through all the transitions of the current state of the module.
                        Then evaluate whether to go to the next state
                        @startuml
                        Start
                        :Set local error as None;
                        If ((Is pointer to Input data valid?)AND(Is module list pointer valid?)) then (yes)
                            #orange:Get Module information
                            <b>HEADGetModule</b> >
                            Note
                            Return a Module correspond to Module number 
                            from HEAD Module list.
                            Endnote
                            If ((Is module pointer not valid?)OR(Is module internal pointer not valid?)OR
                        (Is module internal type != generic state machine)OR(Is module state list pointer not valid?)) then (yes)
                            :Set Null Pointer Error;
                            If (Is Module pointer pointing to Null?) then (no)
                                :Set Module QoS to degradation Stop;
                            endif
                            Else (no)
                            :Fetch module internal information;
                            If ((check if re-initialization is ordered?)) then (yes)
                                :Reset Initialization;
                                Note 
                                Once you reset the initialization, 
                                ReInitialization will be done in the next call.
                                End note 
                            Else (no)
                                If ((check if module initialized?)) then (no)
                                :Initialize module state;
                                partition #LightBlue **((HEAD_AUTO_CFG_NO_OCG))** {
                                #orange: Reset all allocated timers to handle conditions
                                (HEADParamOutType_OtherCondGroups)
                                <b>HEADResetAllSCGTimers</b> >
                                }
                                :Set module initialized flag;
                                Endif
                                #orange:Get module state data
                                <b>HEADGetModuleState</b> >
                                If ((Is pointer to state valid?)) then (no)
                                :Set Null Pointer Error;
                                Else (yes)
                                #orange:Evaluate state transitions
                                <b>HEADEvalStateTransitions</b> >
                                Note:Evaluate if there is a state transition from the current state
                                If ((Is any error occurred during evaluate state transition?)) then (yes)
                                    :Set module QoS to degradation stop; 
                                    :Do State Transition corresponding to degradation Stop State;
                                Else (no)
                                    :Do State Transition;
                                    Note
                                    Do state transition based on the outcome of 
                                    Evaluate_State_Transition.
                                    End note
                                Endif
                                Endif 
                            Endif
                            Endif
                        Else (no)
                            :Set Null Pointer Error;
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned.

  @param[in]            uiModuleNr : Module Number 
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            bInit : Boolean indicates Re-Initialization initated or not

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                         @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1099-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADGenericStateMachine(uint8 uiModuleNr, const struct HEADInputData_t *pInputData, boolean bInit)
{
  eHEADSMState_t eNewState;  /* default initialisation */
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADModuleState_t * pState = NULL;

  if((pInputData != NULL)&&(pInputData->pModuleList != NULL))
  {
    HEADModule_t * pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);

    if (   (pModule == NULL)
        || (pModule->pInternal == NULL)
        || (pModule->pInternal->InternalHeader.eModuleInternalType != HEADModuleInternalType_GSM)
        || (pModule->pModuleStateList == NULL) )
    {
      retValue = GDB_ERROR_POINTER_NULL;

      if (pModule!= NULL) /* Save consistent QoS due to internal error */
      {
        pModule->eQoS = HEADModuleQoS_DegradationStop;
      }
    }
    else
    {
      /*PRQA S 0314 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/ 
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
          /* initialize module state */
          pModule->eDGSMState      = pModule->eNumModuleStateMin;

          #if (HEAD_AUTO_CFG_NO_OCG > 0)
          /* Reset all allocated timers to handle conditions(HEADParamOutType_OtherCondGroups) */
          (void)HEADResetAllSCGTimers(pModule);
          #endif

          pModuleInt->bInitialized = b_TRUE;
        }

        /* now it's initialized */

        /* Get corresponding state data   */
        pState = HEADGetModuleState(pModule, (((uint32)(HEADSMState_t)pModule->eDGSMState) - ((uint32)(HEADSMState_t)pModule->eNumModuleStateMin)));

        if(pState == NULL)
        {
            retValue = GDB_ERROR_POINTER_NULL;
        }
        else
        {
          /* Evaluate transitions */
          HEADEvalStateTransitions(pModule, pState, pInputData, &eNewState, &retValue);

          /* No error, either a transition is true or a default transition */
          if(retValue == GDB_ERROR_NONE)
          {
            HEADDoStateTransition(eNewState, pInputData, pModule, &retValue);
          }
          else /* Error Case */
          {
            pModule->eQoS = HEADModuleQoS_DegradationStop;
            HEADDoStateTransition(pModule->eNumModuleStateMin, pInputData, pModule, &retValue);
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

#if HEAD_CFG_PRECONDITION == MEDIC_ON
/****************************************************************************************************************************
  Functionname:         HEADEvaluatePreCond                                                                         */ /*!

  @brief                Evaluates the precondition

  @description          All the preconditions will be evaluated in this function
                        @startuml
                        Start
                        :Set triggered hypothesis to 0;
                        :Set local error as None;
                        #orange:Get Module information
                        <b>HEADGetModule</b> >
                        Note
                        Return a Module correspond to Module number from HEAD Module list.
                        Endnote
                        #orange:Get module state data
                        <b>HEADGetModuleState</b> >
                        #orange:Get the module current transition data
                        <b>HEADGetStateTransition</b> >
                        While ((Cycle_Through_All_Number_Of_preconditions)) is (valid precondition number index)
                        #orange:Get the precondition with current precondition number
                        <b>HEADGetPreCondition</b> >
                        :Set Over all hyp result and independent result to Not checked;
                        #orange:Preselection of Hypotheses which have to be checked
                        <b>HEADGSMGetParametersToRelevantHyps</b> >
                        Note
                        loops through the parameterlist(conditionlist) in the current
                        condition group and checks which hypotheses have the
                        potential to become relevant  and so should be checked later.
                        End note
                        #orange: Returns true if the preconditions are met for this ConditionGroup
                        <b>HEADGSMIterateHypotheses</b> >
                          If (local error as None) then (yes)
                          #orange:Initialize module active data
                          <b>HEADGSMInitActiveFunction</b> >
                          #orange:check conditions in this condition group with the current hyp
                          <b>HEADGSMCheckConditions</b> >
                          Note:checks the conditions in a ConditionGroup
                         EndIf
                         If (((Overall Hypothesis Result==True)AND((Independent Parameter Result==True)OR   (Independent Parmeter Result==Notchecked)))OR((Independent Parameter Result==True)AND(rgHypUsed==0))) then (yes)
                         :Set precondition status as True;
                         Else (no)
                         :Set precondition status as False;
                         Endif
                        EndWhile (precondition number index not valid)
                        : return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned

  @param[in]            pInputData : Pointer to HEAD Input data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  
  @pre                  None
  @post                 None

  @InOutCorrelation     Input is pInputData data  and output is PreCondStatus either TRUE/FALSE

  @testmethod           Test of output data (dynamic module test)
  
  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author               Raghavendra Nese | raghavendra.nese@continental-corporation.com
****************************************************************************************************************************/
eGDBError_t HEADEvaluatePreCond(const HEADInputData_t *pInputData)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  uint8 uiPreCondNr;
  eHEADSpecialBool_t eOverallHypResult;
  eHEADSpecialBool_t eHypothesisResult;
  eHEADSpecialBool_t eIndependentParResult;
  HEADParameterHypothesisSub_t rgHypUsed;
  HEADParameterHypothesisSub_t rgInputHypTriggered = 0;
  HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT];
  HEADModule_t *pModule = HEADGetModule(pInputData->pModuleList, 0u);
  HEADModuleState_t *pState = HEADGetModuleState(pModule, 2u);
  HEADStateTransition_t *pTransition = HEADGetStateTransition(pState, 0u);
  const HEADPreConditionList_t *const pPreCondList = pInputData->pPreCondList;
  for(uiPreCondNr = 0u; uiPreCondNr < pPreCondList->uiNrOfPreConds; uiPreCondNr++)
  {
    HEADPreCond_t *pPreCond = HEADGetPreCondition(pPreCondList, uiPreCondNr);
    eOverallHypResult = HEADSpecialBool_notchecked;
    eIndependentParResult = HEADSpecialBool_notchecked;
    HEADGSMGetParametersToRelevantHyps(&(pPreCond->rgPreCond),&rgHypUsed,pInputData);
    locError = HEADGSMIterateHypotheses(pTransition, pModule, pInputData, &(pPreCond->rgPreCond), &eHypothesisResult, &eOverallHypResult, rgHypUsed,
                                        rgInputHypTriggered, sParamValThisModuleActive, (boolean) TRUE, uiPreCondNr);
    if(locError == GDB_ERROR_NONE)
    {
      HEADGSMInitActiveFunction(sParamValThisModuleActive, b_FALSE);
      locError = HEADGSMCheckConditions(pModule,pInputData, &(pPreCond->rgPreCond), &eIndependentParResult, rgInputHypTriggered,
                                        sParamValThisModuleActive,
                                        #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                        sParamValOCG,
                                        #endif
                                        NULL,HEADNoHypothesis,b_TRUE,uiPreCondNr,NULL);
      if (eIndependentParResult == HEADSpecialBool_True)
      {
          pPreCond->uiHypInCondGroup |= (((uint16)1u << HEADHypothesisIndependent));
      }
    }
    if(((eOverallHypResult == HEADSpecialBool_True) && ((eIndependentParResult == HEADSpecialBool_True) 
         || (eIndependentParResult == HEADSpecialBool_notchecked)))
         ||((eIndependentParResult == HEADSpecialBool_True) && (rgHypUsed == 0u)))
    {
      pPreCond->PreCondStatus = b_TRUE;
    }
    else
    {
      pPreCond->PreCondStatus = b_FALSE;
    }
  }
  return locError;
}

/****************************************************************************************************************************
  Functionname:         HEADGSMIterateHypotheses                                                                         */ /*!

  @brief                Returns true if the preconditions are met for this ConditionGroup

  @description          Returns true if the preconditions are met for this ConditionGroup
                        @startuml
                        Start
                        :Set local error as None;
                        :Set the bit flag to 1;
                         While ((Cycle_Through_All_Hypotheses?AND(No_error?)) is (valid hypothesis index)
                         #orange:get the hypothesis for current index from the hypotheses list
                         <b>HEADGetHypothesis</b> >
                            If ((Is pointer to hypothesis valid?)) then (yes)
                              If ((Is Hypothesis type Valid?)) then (yes)
                              :set IntermediateResult to not checked at the beginning of every hypothesis;
                              #Orange:Reset ParamValThisModuleActive for hyp dependent parameters
                              <b>HEADGSMInitActiveFunction</b> >
                                If ((Is the kinematic Hypothesis is available
                                in the Preselected list of hypothesis)) then (yes)
                                :store these hypothesis in triggerd Hypothesis;
                                Note:store these hyps which are triggered regardless of true or false
                                #orange:check conditions in this condition group with the current hyp
                                <b>HEADGSMCheckConditions</b> >
                                Note:checks the conditions in a ConditionGroup
                                Endif
                                If (PreCondion Evaluation is True) then (yes)
                                  If ((Local Err is None)AND(Hypo Result is True)) then (yes)
                                  #orange:Get the precondition with current precondition number
                                  <b>HEADGetPreCondition</b> >
                                  : Store the hypothesis in hypothesis triggered for ConditionGroup in transition data;
                                    If ((Over all Hypothesis Result==Not_Checked)) then (yes)
                                    :Set Over all Hypothesis Result as True;
                                    Endif
                                  Elseif (((Local_Error==None)AND(Hypothesis_ Result==False)AND(Over all  Hypothesis==False)) then (yes)
                                  :Set Over all Hypothesis Result as False;
                                  Else
                                  :Do nothing;
                                  Endif
                                  Else (no)
                                  If ((local error is None)AND(hypothesis result is True))then (yes)
                                  :Store the hypothesis in hypothesis triggered for ConditionGroup in transition data;
                                    If ((Over all Hypothesis Result==Not_Checked)) then (yes)
                                    :Set Over all Hypothesis Result as True;
                                    Endif
                                  Elseif ((local error is None)AND(hypothesis result is False)) then (yes)
                                  :Set Over all Hypothesis Result as False;
                                  Else
                                  :Do nothing;
                                  Endif
                                Endif 
                              Endif
                            Else (no)
                              : create an assertion failure;
                              : set local error as GDB_ERROR_POINTER_NULL;
                            Endif
                         End while (Invalid hypothesis index)
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned

  @param[in]            pTransition : pointer to state transition
  @param[in]            pModule : pointer to a HEAD Module
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            pConditionGrp : pointer to condition group
  @param[in]            rgHypUsed : Bit field for head parameter hypothesis
  @param[in]            rgInputHypTriggered
  @param[in]            sParamValThisModuleActive : Module Active Param Value
  @param[in]            bPreCondEval:precondition evaluation
  @param[in]            PreCondNr:precondition number

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1140-0007e0f8}

  @author               Raghavendra Nese | raghavendra.nese@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t  HEADGSMIterateHypotheses(const HEADStateTransition_t *const pTransition, HEADModule_t *pModule,
                                             const struct HEADInputData_t *pInputData, const HEADConditionGrp_t *pConditionGrp, eHEADSpecialBool_t* eHypothesisResult,
                                             eHEADSpecialBool_t* eOverallHypResult, HEADParameterHypothesisSub_t rgHypUsed, HEADParameterHypothesisSub_t rgInputHypTriggered,
                                             HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT], boolean bPreCondEval, uint8 PreCondNr)
{
  uint8 uiCurrentHyp;
  eGDBError_t locError = GDB_ERROR_NONE;
  const uint32 uiBitFlag = 1;
  for(uiCurrentHyp = 0u; (uiCurrentHyp < (uint8)MAX_NUM_OF_HYPS) && (locError == GDB_ERROR_NONE); uiCurrentHyp++)
  {
    const HEADHypothesis_t *const pHyp = HEADGetHypothesis(pInputData->rgHypothesisList, uiCurrentHyp);
    if (pHyp->pHypothesis != NULL)
    {
      if (MEDIC_e_GetHypType(pHyp) != CDHypothesisType_No)
      {
        *eHypothesisResult = HEADSpecialBool_notchecked;
        HEADGSMInitActiveFunction(sParamValThisModuleActive, b_FALSE);
        if( (rgHypUsed & (HEADParameterHypothesisBit(MEDIC_e_GetHypType(pHyp)))) != 0u )
        {
          rgInputHypTriggered |= (HEADParameterHypothesisBit(MEDIC_e_GetHypType(pHyp)));
          locError = HEADGSMCheckConditions(pModule,pInputData, pConditionGrp, eHypothesisResult,0, sParamValThisModuleActive, 
                                            #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                            sParamValOCG, 
                                            #endif
                                            pHyp,uiCurrentHyp,bPreCondEval,PreCondNr,NULL);
        }
        if (bPreCondEval == b_TRUE)
        {
          if((locError == GDB_ERROR_NONE) && (*eHypothesisResult == HEADSpecialBool_True))
          {
            HEADPreCond_t *pPreCond = HEADGetPreCondition(pInputData->pPreCondList, PreCondNr);
            pPreCond->uiHypInCondGroup |= (uint16)((uiBitFlag<<uiCurrentHyp));
            if((*eOverallHypResult == HEADSpecialBool_notchecked) || (*eOverallHypResult == HEADSpecialBool_False))
            {
              *eOverallHypResult = HEADSpecialBool_True;
            }
          }
          else if(    (locError == GDB_ERROR_NONE)
                   && (*eHypothesisResult == HEADSpecialBool_False) && (*eOverallHypResult != HEADSpecialBool_True))
          {
            *eOverallHypResult = HEADSpecialBool_False;
          }
          else
          {
            /* Do Nothing */
          }
        }
        else
        {
          if((locError == GDB_ERROR_NONE)
              && (*eHypothesisResult == HEADSpecialBool_True) )
          {
            pTransition->puHypInCondGroup[pModule->uiCurrentCondGrpNr] = (uint16)((uiBitFlag<<uiCurrentHyp) 
                                                                         |(uint32)(pTransition->puHypInCondGroup[pModule->uiCurrentCondGrpNr]));
            if(*eOverallHypResult == HEADSpecialBool_notchecked)
            {
              *eOverallHypResult = HEADSpecialBool_True;
            }
          }
          else if((locError == GDB_ERROR_NONE)
                   &&(*eHypothesisResult == HEADSpecialBool_False))
          {
            *eOverallHypResult = HEADSpecialBool_False;
          }
          else
          {
            /*Do Nothing*/
          }
        }
      }
    }
    else
    {
      MEDIC_ASSERT(FALSE);/*PRQA S 3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed */
      locError = GDB_ERROR_POINTER_NULL;
    }
  }
  return locError;
}/* PRQA S 7007 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing for better code maintainability*/ 

#endif
/****************************************************************************************************************************
  Functionname:         HEADEvalStateTransitions                                                                        */ /*!

  @brief                Evaluate if there is a state transition from the current state

  @description          Evaluate if there is a state transition from the current state
                        No Pointer checks are performed for pInputData, eNewState, retValue

                        => assert that all pointers are 
                        valid in calling functions.
                        Module is assumed to be in Current State if this function is called.

                        @startuml
                        Start
                        :Set local error as None;
                        #orange: Find Qos Transition Mapping table for the current QoS of the module
                        <b>HEADGetCurrQoSMap</b> >
                        If ((Is pointer to Qos transition mapping table valid?)AND
                        (No local error found in previous stages?)) then (yes)
                          While ((Iterate through transition list for current QoS of the module)) is (Transition index valid) 
                            #orange:Get the transition number from QoS transition list
                            <b>HEADSPMGetQoSTransNr</b> >
                            If ((current transition == last transition)AND
                        (current transition == default transition)) then (yes)
                              :Do nothing;
                              Note 
                              If the last transiton is default transition then 
                              no need to evaluate.
                              end note
                            else (no)
                              :update transition nr in the module structure;
                              #orange:Get the transition data
                              <b>HEADGetStateTransition</b> >
                              #orange:Evaluate the valid transition
                              <b>HEADDGSMEvalTransition</b> >
                              Note
                              Evaluate individual transition conditions and 
                              returns true if the enable conditions are met.
                              End note
                              If ((No error found in previous stages?)AND
                        (valid Transition with enable conditions are met?)) then (yes)
                                :save the next state;
                                Note
                                 Next state is the valid highest priority 
                                transition which is true;
                                End note
                               Endif
                            Endif
                          End while(Transition index not valid)
                          If ((No true transition found?)AND
                        ((No error found in previous stages?)) then (yes)
                            :Fetch default transition number;
                            #orange: Get the transition data for default transition
                            <b>HEADGetStateTransition</b> >
                            If ((Is pointer to default transition valid?)) then (yes)
                              :update default state as next state;
                            Else (no)
                              :Set NULL pointer error;
                            Endif
                          Endif
                          partition #LightBlue **((MEDIC_CFG_ABORT_REASON))** {
                          #orange: Get the Module new state
                          <b>HEADGetModuleState</b> >
                          If ((Current state is active)AND(New state is equal to Current state)AND (New state is active)) then (yes)
                          :reset ParamFailed and hypothesis lost information;
                          Endif
                          }
                        Endif
                        Stop
                        @enduml

  @return               void

  @param[in,out]        pModule : pointer to a HEAD Module 
  @param[in]            pState : pointer to a Module state
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[out]           eNewState : Pointer to New State
  @param[out]           retValue : Pointer to GDB Error code

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1174-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1109-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1138-0007e0f8}

  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADEvalStateTransitions(HEADModule_t *pModule, HEADModuleState_t *pState, const struct HEADInputData_t * pInputData,
                                     eHEADSMState_t *eNewState, eGDBError_t *retValue ) 
{
  uint8 uiQosTransIndex;
  uint8 uiQoSTransNr;
  boolean bTransitionTrue = b_FALSE;
  HEADStateTransition_t *pTransition = NULL;
  HEADSPMQoSMap_t *pSPMQoSMap = NULL;
  boolean bActiveState = pState->bActiveState;
  #if (MEDIC_CFG_ABORT_REASON)
  HEADModuleState_t *pNewState = NULL;
  #endif

  *retValue = GDB_ERROR_NONE;

  /* Find Qos Transition Mapping table for the current QoS of the module */
  pSPMQoSMap = HEADGetCurrQoSMap(pModule, pState, retValue);

  /* QoS table index found, evaluate transitions of current QoS */
  if((*retValue == GDB_ERROR_NONE) && (pSPMQoSMap != NULL))
  {
    /* Iterate through transition list for current QoS, starting with highest priority transition, 
        transition list is in "uiTransList" member of structure "HEADSPMQoSTransMap_t" with highest priority transition at LSB */
    for(uiQosTransIndex = 0; (uiQosTransIndex < pSPMQoSMap->uiNumQoSTrans)&&(uiQosTransIndex < pState->uiNumTransitions)
          &&(bTransitionTrue == b_FALSE); uiQosTransIndex++)
    {
      /* Get the transition number from QoS transition list */
      uiQoSTransNr = HEADSPMGetQoSTransNr(pSPMQoSMap->uiTransList, uiQosTransIndex);

      /* Check if default transition.If so Skip evaluation */
      if((uiQosTransIndex == (pSPMQoSMap->uiNumQoSTrans-1u)) /* last transition or only one transition */ 
        &&(uiQoSTransNr == pSPMQoSMap->uiDefaultTx)) /* default transition */
      {
        /* do nothing */
      }
      else
      {
        /* update transition nr in the module structure */
        pModule->uiCurrentTransNr  = uiQoSTransNr;

        /* Get the transition data */
        pTransition = HEADGetStateTransition(pState, uiQoSTransNr);
        #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
        MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_GSM_TRANSITION, uiQoSTransNr);
        #endif
        MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoStart, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_GSM_TRANSITION, uiQoSTransNr);
        #endif

        /* Evaluate the valid transition */
        *retValue   =  HEADDGSMEvalTransition(pModule, pTransition, pInputData, &bActiveState, &bTransitionTrue);
        #if ((MEDIC_CFG_RTA_PROFILING) && (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS))
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
        MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_GSM_TRANSITION, uiQoSTransNr);
        #endif   
        MEDIC_v_AlgoServiceAddEvent(MEDIC_p_GetServiceFuncts(), e_RTA_EVT_AlgoEnd, (uint8)MEDIC_GLOBAL_RTA_ID, (uint8)MEDIC_RTA_HEAD_GSM_TRANSITION, uiQoSTransNr);
        #endif 
        if((*retValue == GDB_ERROR_NONE) && (bTransitionTrue == b_TRUE))   /* Found a True Transition */
        {
          *eNewState  =   pTransition->eDGSMNextState;  // save the next state of the valid highest priority transition which is true
        }
      }
    }

    /* No true transition found, go for default transition */
    if((*retValue == GDB_ERROR_NONE) && (bTransitionTrue == b_FALSE))
    {
      uiQoSTransNr = (uint8)pSPMQoSMap->uiDefaultTx;

      /* Get the transition data */
      pTransition = HEADGetStateTransition(pState, uiQoSTransNr);

      if(pTransition != NULL)
      {
        *eNewState  = pTransition->eDGSMNextState; /* update default state as the next state*/
      }
      else
      {
        *retValue = GDB_ERROR_POINTER_NULL;
      }
    }
    #if ((MEDIC_ARCHITECTURE_VERSION >= 0x10) && (MEDIC_CFG_ABORT_REASON))
    pNewState = HEADGetModuleState(pModule, (((uint32)(*eNewState)) - ((uint32)pModule->eNumModuleStateMin)));
    if (((bActiveState == b_TRUE) && (*eNewState == pModule->eDGSMState)) || (pNewState->bActiveState == b_TRUE))
    {
      *MEDIC_p_ModFCTDataAbortReasonParamOutType((uint8)pModule->eModuleNr) = (uint8)HEADParamOutType_None;
      *MEDIC_p_ModFCTDataAbortReasonHypLost((uint8)pModule->eModuleNr)      = b_FALSE;
    }
    #endif
  }
}

/****************************************************************************************************************************
  Functionname:         HEADDGSMEvalTransition                                                                          */ /*!

  @brief                returns true if the enable conditions are met

  @description          valuate individual transition conditions and returns true if
                        the enable conditions are met
                        @startuml
                        Start
                        :Set local error as None;
                        If ((Is pointer to transition valid?)) then (no)
                          :Set NULL pointer error;
                        Else (yes)
                          If ((Is transition Initialized?)) then (no)
                            While ((loop through all condition groups)) is (condition group Number valid)
                              #orange:Get condition group
                              <b>HEADGetConditionGrp</b> >
                              Note:Return condition group correspond to condition group number
                              If ((Is Condition group pointer valid?)) then (yes)
                                : Reset timer values for the condition group;
                              Endif
                            End while (condition group number not valid)
                            :Set transition initialized flag as true;
                          Endif
                          If ((Is condition group avalilable for the transition?)) then (no)
                            :Set transition condition False; 
                          Else (yes)
                            If ((Is pointer to Hypothesis in condition group valid?)) then (yes)
                              partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                              #orange:reset/init other condition group values struct
                              <b>HEADGSMResetParamValOCG</b> >
                              }
                              While ((loop through all condition groups)AND(No Error?)) is (condition group Number valid)
                                :update module current condition group number;
                                If((current state is active)AND(currrent state(active) is equal to next state(active))&&(previous cycle hypothesis for perticular condition-group number is not equal to zero)) then (yes)
                                :set condition group check abort reason flag;
                                Endif
                                #orange:Check module's current Condition-group
                                <b>HEADGSMConditionsGroup</b> >
                                If ((No error found in previous stages?)AND(Is current Condition group true?)) then (yes)
                                  :set condition met flag as true;
                                  :set the triggered hypothesis for that perticular condition-group number;
                                  partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                                  :Update active condition group bits;
                                  }
                                Elseif ((local error != None))
                                  :set condition met flag as false;  
                                  Note:Error case
                                  :reset triggered hypothesis in ConditionGroup;
                                Else (current Condition group falied)
                                  :reset triggered hypothesis in ConditionGroup;
                                Endif
                              End while (condition group number not valid)
                              partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                              If (((No error found in previous stages?)AND(condition group containing condition with outType Other Condition Group check?)) then (yes)
                                If ((keep transition)) then (yes)
                                  :Do nothing;
                                  Note
                                  evaluate (OCG1+OCG2+...) + SCG5, atleast one condition group need to be true,
                                  which is already checked. So no further check needed 
                                  End note
                                Else if (leave transition)
                                  :Reset condition met flag;
                                  While ((Loop through all other condition group check)) is (valid condition)
                                    If ((Other condition group is true)AND(self condition is true )) then (yes)
                                      :set condition met flag as true;
                                    Endif
                                  End while(Invalid condition)
                                  Note:evaluate {(OCG1+OCG2+...)*SCG5} + {(OCG1+OCG3+...)*SCG6}
                                Endif
                              Endif
                              }
                            Else (no)
                              :Set NULL pointer error;
                            Endif
                          Endif
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an error code.

  @param[in,out]        pModule : pointer to a HEAD Module 
  @param[in,out]        pTransition : pointer to state transition data
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[out]           bConditionTrue : Boolean indicates True if all conditions in a condition group met, else False

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1137-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADDGSMEvalTransition(HEADModule_t *pModule, HEADStateTransition_t *pTransition, 
                                          const struct HEADInputData_t *pInputData, boolean *pbActiveState, boolean *bConditionTrue)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  uint8 uiCondGrpNr;
  HEADConditionGrp_t *pConditionGrp = NULL;
  boolean bCondGrpCheckAbrtRes = b_FALSE;

  *bConditionTrue = b_FALSE;

  if(pTransition == NULL)
  {
    retValue =  GDB_ERROR_POINTER_NULL;
  }
  else
  {
    if(pTransition->bInitialized == b_FALSE)
    {  
      /* Reset timer values for all the condition groups */
      for(uiCondGrpNr = 0; uiCondGrpNr < pTransition->uiNumConditionGroups; uiCondGrpNr++)
      {
        pConditionGrp = HEADGetConditionGrp(pTransition, uiCondGrpNr);
        if(pConditionGrp != NULL)
        {
          /*PRQA S 0315 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
          MEDIC_MEMSET(&(pConditionGrp->fConditionsOKTimer),0, sizeof(float32));
        }
      }
      pTransition->bInitialized = b_TRUE;
    }

    if(pTransition->pConditionGroupList == NULL)
    {
      /*  No condition group..transition condition is FALSE */
      *bConditionTrue      = b_FALSE;
    }
    else
    {
      if(pTransition->puHypInCondGroup != NULL)
      {
        #if (HEAD_AUTO_CFG_NO_OCG > 0)
        HEADOtherCondGrpsCheck_t sParamValOCG;
        HEADCondGrpBitField_t uiCondGrpBits = 0;

        /* reset/init other condition group values struct*/
        retValue = HEADGSMResetParamValOCG(&sParamValOCG);
        #endif

        for (uiCondGrpNr = 0u; (uiCondGrpNr < pTransition->uiNumConditionGroups)&&(retValue == GDB_ERROR_NONE) ; uiCondGrpNr++)
        {
          boolean bGroupConditionTrue = b_FALSE;
          uint16 HypInCondGroup = 0;

          /* update current condition group nr */
          pModule->uiCurrentCondGrpNr = uiCondGrpNr;

          #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
          if ((*pbActiveState == b_TRUE) && (pModule->eDGSMState == pTransition->eDGSMNextState) && (pTransition->puHypInCondGroup[uiCondGrpNr] != 0u))
          {
              bCondGrpCheckAbrtRes = b_TRUE;
          }
          #endif
          /* Check a certain Condition-group. Return value of bGroupConditionTrue is expected to be false if no rule is 
              applicable, and if Condition group does not exist*/
          retValue = HEADGSMConditionsGroup(pModule, pTransition, 
                                            #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                            &sParamValOCG, 
                                            #endif
                                            pInputData, &bCondGrpCheckAbrtRes, &bGroupConditionTrue, &HypInCondGroup);
      
          if ( (retValue == GDB_ERROR_NONE) && (bGroupConditionTrue != b_FALSE))
          {
            *bConditionTrue = b_TRUE;
            pTransition->puHypInCondGroup[uiCondGrpNr] = HypInCondGroup;
            #if (HEAD_AUTO_CFG_NO_OCG > 0)
            uiCondGrpBits  = uiCondGrpBits | (HEADCondGrpBitField_t)(1 << uiCondGrpNr); /* set the CondGrp bit */
            #endif
          }
          else if(retValue != GDB_ERROR_NONE) 
          {
            /* error case*/
            *bConditionTrue = b_FALSE;
            pTransition->puHypInCondGroup[uiCondGrpNr] = 0;
          }
          else
          {
            /*if bConditionTrue is false, reset triggered hyps in ConditionGroup*/
            pTransition->puHypInCondGroup[uiCondGrpNr] = 0;
          }
        }

        #if (HEAD_AUTO_CFG_NO_OCG > 0)
        /* Handle Special Groups(containing condition with OutType = HEADParamOutType_OtherCondGroups) Case(if any) */
        if((retValue == GDB_ERROR_NONE)&&(sParamValOCG.uiNrOfChecksUsed > 0)) /* Special Groups present */
        {
          // Case 1 : keep transition //
          /* evaluate (OCG1+OCG2+...) + SCG5, atleast one condition group need to be true,
              which is already checked. So no further check needed */

          // Case 2 : leave transition //
          /* evaluate {(OCG1+OCG2+...)*SCG5} + {(OCG1+OCG3+...)*SCG6} */
          if(pModule->eDGSMState != pTransition->eDGSMNextState)
          {
            uint32 uiICnt;

            /* Erase any old result */
            *bConditionTrue = FALSE;

            for(uiICnt = 0uL; (uiICnt < sParamValOCG.uiNrOfChecksUsed)&&(*bConditionTrue == FALSE); uiICnt++)
            {
              if((sParamValOCG.uiBitPackOCG[uiICnt] & uiCondGrpBits) /* atleast one other condition group is true */
                &&((uiCondGrpBits) & (HEADCondGrpBitField_t)(1 << sParamValOCG.uiLinkedSCG[uiICnt]))) /* self condition is true */
              {
                  *bConditionTrue = TRUE;
              }
            }
          }
        }
        #endif
      }
      else
      {
        retValue =  GDB_ERROR_POINTER_NULL;
      }          
    }
  }

  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  _PARAM_UNUSED(pbActiveState);
  #endif
  return retValue;
}

/****************************************************************************************************************************
  Functionname:         HEADDoStateTransition                                                                           */ /*!

  @brief                Do the actual state transition

  @description          Do the actual state transition
                        This function can be called by external functions (e.g. outputfunctions)

                        Method created in refactoring. 
                        No Pointer checks are performed => assert that all pointers are 
                        valid in calling functions.

                        @startuml
                        Start
                        :Set local error as None;
                        :Fetch module internal information;
                        :save the last cycle state;
                        If ((New State != module's current State)) then (yes)
                          partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                          #orange: Reset all allocated timers to handle conditions
                          (HEADParamOutType_OtherCondGroups)
                          <b>HEADResetAllSCGTimers</b> >
                          }
                          :save the last state of the module;
                          #orange:Get new state data
                          <b>HEADGetModuleState</b> >
                          If ((Is pointer to state valid?)) then (no)
                            :Set NULL pointer error;
                          Else (yes)
                            While ((loop through all the transition related to new state)) is (valid transition)
                              #orange:Get the transition data
                              <b>HEADGetStateTransition</b> >
                              If ((Is pointer to transition data valid?)) then (yes)
                                While ((loop through all conditon groups related to this transiton)) is (valid transition)
                                  #orange:Get condition group
                                  <b>HEADGetConditionGrp</b> >
                                  Note:Return condition group correspond to condition group number
                                  If ((Is pointer to condition group valid?)) then (yes)
                                    :Reset timer values for the condition group;
                                  Endif
                                End while (Invalid transition)
                              Else (no)
                                :Set NULL pointer error;
                              Endif
                            End while (Invalid transition)
                          Endif
                          :save current vehicle speed as Host speed during last state transition
                          Of the module;
                          If ((No local error)AND(Input signal quality of ego vehicle velocity == Ok)) then (yes)
                            :set host speed during last state transition oK flag true;
                          Else (no)
                            :set host speed during last state transition oK flag false;
                          Endif
                        Endif
                        :set the new module state;
                        Stop
                        @enduml

  @return               void

  @param[in]            eNewState : Enum variable to hold State Machine New State 
  @param[in]            pInputData : Pointer to HEAD Input Data
  @param[in,out]        pModule : Pointer to a HEAD Module
  @param[in,out]        retValue : Pointer to GDB Error code

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG
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
void HEADDoStateTransition( eHEADSMState_t eNewState,
                            const struct HEADInputData_t * pInputData, 
                            HEADModule_t * pModule, 
                            eGDBError_t *retValue ) 
{
  eGDBError_t localError = GDB_ERROR_NONE;
  uint8 uiTransitionNr;
  uint8 uiConditionGrpNr;
  /*PRQA S 0314 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));
  HEADModuleState_t *pState = NULL;
  HEADStateTransition_t *pTransition = NULL;
  HEADConditionGrp_t *pConditionGrp = NULL;

  *retValue = GDB_ERROR_NONE;

  /* save the last cycle state */
  pModule->eDGSMLastCycleState = pModule->eDGSMState;

  /* transiting to a new state, save/reset previous state data */
  if(eNewState != pModule->eDGSMState) 
  {

    #if (HEAD_AUTO_CFG_NO_OCG > 0)
    /* Reset all allocated timers to handle conditions(HEADParamOutType_OtherCondGroups) */
    (void)HEADResetAllSCGTimers(pModule);
    #endif

    /* save the last state if transiting to a new state*/
    pModule->eDGSMLastState = pModule->eDGSMState;

    pState = HEADGetModuleState(pModule, (((uint32)(HEADSMState_t)eNewState) - ((uint32)(HEADSMState_t)pModule->eNumModuleStateMin)));

    if(pState == NULL)
    {
      *retValue = GDB_ERROR_POINTER_NULL;
    }
    else
    {
      /*init(reset) timers for all condition groups of the current state if different from previous state*/
      for(uiTransitionNr = 0; uiTransitionNr < pState->uiNumTransitions; uiTransitionNr++)
      {
        pTransition = HEADGetStateTransition(pState, uiTransitionNr);
        if(pTransition != NULL)
        {
          for(uiConditionGrpNr = 0; uiConditionGrpNr < pTransition->uiNumConditionGroups; uiConditionGrpNr++)
          {
            pConditionGrp = HEADGetConditionGrp(pTransition, uiConditionGrpNr);
            if(pConditionGrp != NULL)
            {
              /*PRQA S 0315 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
              MEDIC_MEMSET(&(pConditionGrp->fConditionsOKTimer),0, sizeof(float32));
            }
          }
        }
        else
        {
          *retValue = GDB_ERROR_POINTER_NULL;
        }
      }
    }

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

  /*** set the new module state ****/
  pModule->eDGSMState = eNewState;
}


/****************************************************************************************************************************
  Functionname:         HEADGSMResetParamValGeneral                                                                     */ /*!

  @brief                initializes the general param values structure

  @description          initializes the general param values structure
                        No check on Validity of Input pointer is done.
                        Calling Function needs to assert the validity of the pointer.
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
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADGSMResetParamValGeneral(HEADGSMParamValues_t *sParamValGeneral)
{
  sParamValGeneral->bUsed = b_FALSE;
  sParamValGeneral->fFact = 1.0f;
  sParamValGeneral->uiBitPack = 0u;
  /*the variables fVal, fDefVal, eOperator and uiBitPack will be defined 
  in case of bUsed is set to true.*/
}


/****************************************************************************************************************************
  Functionname:         HEADGSMConditionsGroup                                                                          */ /*!

  @brief                Returns true if the enable conditions are met for this ConditionGroup

  @description          Walks through the list and checks all enable conditions and returns the overall enable condition
                        for each hypothesis all parameters were checked.
                        if a parameter belongs to the current check hypothesis it'll be checked against the hyp values
                        there is an array of check information of the size of the hypothesis type count [kinematic/driver]
                        for each hypothesis type the result will be stored in this array, also the information 
                        if a parameter requires a specific hypothesis
                        at the end the information in this array is merged to an overall output

                         No pointer checks are performed for the following pointers.
                        Calling function shall assert that the pointers are valid.

                        In case the Condition group is not applicable or false the result shall be false.
                        @startuml
                        Start
                        :Set Local_Error as none;
                        #orange:Get current condition group data
                        <b>HEADGetConditionGrp</b> >
                        Note
                        Return base address of condition group correspond 
                        to condition group number
                        End note
                        If ((Is pointer to Condition group valid?)) then (no)
                            :Set NULL pointer error;
                        Else (yes)
                            #orange:Get Hypothesis logic(AND/OR) for the condition group
                            <b>HEADParamHypLogic_MustBeAnd</b> >
                            #orange:Preselection of Hypotheses which have to be checked
                            <b>HEADGSMGetParametersToRelevantHyps</b> >
                            Note
                            loops through the parameterlist(conditionlist) in the current 
                            condition group and checks which hypotheses have the 
                            potential to become relevant  and so should be checked later.
                            End note
                            #orange:Initialize module active data
                            <b>HEADGSMInitActiveFunction</b> >
                        Partition CycleThroughMatchingHypothesesList {
                            While ((Cycle_Through_All_Hypotheses?AND(No_error?)) is (valid hypothesis index)
                            #orange:get the hypothesis for current index from the hypotheses list
                            <b>HEADGetHypothesis</b> >
                             If ((Is pointer to hypothesis valid?)) then (yes)
                                If (Condition-group check abort reason flag is TRUE) then (yes)
                                  If (Current hypothesis matches with previous cycle triggered hypothesis) then(yes)
                                   :set abort reason flag;
                                  Else (no)
                                   :reset abort reason flag;
                                  Endif
                                Endif
                                If ((Is Hypothesis type Valid?)) then (yes)
                                :set IntermediateResult to not checked at the 
                                beginning of every hypothesis;
                                #Orange:Reset ParamValThisModuleActive for 
                                hyp dependent parameters
                                <b>HEADGSMInitActiveFunction</b> >
                                If ((Is the kinematic Hypothesis is available
                        in the Preselected list of hypothesis)) then (yes)
                                    :store these hypothesis in triggerd Hypothesis;
                                    Note:store these hyps which are triggered regardless of true or false
                                    #orange:check conditions in this condition group with the current hyp
                                    <b>HEADGSMCheckConditions</b> >
                                    Note:checks the conditions in a ConditionGroup
                                Endif
                                If ((Local Err is None)AND(Hypo Result is True)) then (yes)
                                    : Store the hypothesis in hypothesis triggered for ConditionGroup in transition data;
                                    If ((Over all Hypothesis Result==Not_Checked)) then (yes)
                                    :Set Over all Hypothesis Result as True;
                                    Endif
                                Elseif (((Local_Error==None)AND(Hypothesis_ Result==False)) then (yes)
                                    :Set Over all Hypothesis Result as False;
                                Else
                                    :Do nothing;
                               Endif
                               Elseif(abort reason flag is True) then (yes)
                               partition #LightBlue **((MEDIC_CFG_ABORT_REASON))** {
                               :Set the Hypothesis lost flag;
                               }
                               Else (no)
                               : Do nothing;
                               Endif
                            Else (no)
                                : create an assertion failure;
                                Note
                                Here we are in the error path.
                                This should never happen, therefore create an assertion failure
                                End note
                                :Set NULL pointer error;
                                Note:Set the error value to allow an error handling
                            Endif
                            End while(Invalid hypothesis index)
                        }
                        Partition Evaluate_IndependentParameters {
                            If ((Local Err is None)) then (yes)
                            If (Condition-group check abort reason flag is TRUE) then (yes)
                            If (Current and previous cycle hypothesis are Hypothesis independent?) then(yes)
                            :set abort reason flag;
                            Else (no)
                            :reset abort reason flag;
                            Endif
                            Endif
                            #Orange:Reset ParamValThisModuleActive for 
                            hyp dependent parameters
                            <b>HEADGSMInitActiveFunction</b> >
                            #orange:Evaluate the independent parameters
                            <b>HEADGSMCheckConditions</b> >
                            Note:Eval independent parameters, therefore check all parameters which have no hyps
                            Endif
                        }
                        Partition Merge_Results {
                            If ((Local Error is None?)AND(NO Hypothesis Dependent condition True?)AND
                        (all independent parameters are not checked?)) then (yes)
                            :Set Group condition as failed;
                            Elseif ((Local Error is None?)AND
                        ((Hypothesis evaluation OR_logic is used)AND(atleast one hypothesis in condition group active))OR((Hypothesis evaluation AND_logic is used)AND(over all hypothesis in condition group active))AND
                        (all independent parameters are true or not checked)) then (yes)
                            :set condition Group flag as True;
                            :increment condition_Ok timer for the condition group; 
                            #orange:Evaluate active module time
                            <b>HEADGSMEvaluateActiveModuleTime</b> >
                            Note:evaluate function active time
                            If ((Independent parameter result==True)AND
                        (Hypothesis dependent conditions are satisfied?)) then (yes)
                                :set independent Hypothesis triggered bit in ConditionGroup 
                                Fot the corresponding transition data;
                            Endif
                            Else
                            :set Condtion Group flag as false;
                            :Reset condition_ok Timer;
                            Endif
                        }
                        Endif
                        :Return Local Error;
                        Stop
                        @enduml

  @return               eGDBError_t : In case of no error GDB_ERROR_NONE shall be returned, all other return values 
                                      indicate an error

  @param[in]            pModule : pointer to a HEAD Module 
  @param[in,out]        pTransition : pointer to state transition 
  @param[in]            sParamValOCG : pointer to Other Condition Groups check information
  @param[in]            pInputData : pointer to HEAD Input data
  @param[out]           bGroupConditionTrue : Boolean bit indicates condition group is active(True) or not active(False)

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1140-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author              Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADGSMConditionsGroup(HEADModule_t *pModule, 
                                           const HEADStateTransition_t *const pTransition, 
                                           #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                           HEADOtherCondGrpsCheck_t *sParamValOCG, 
                                           #endif
                                           const struct HEADInputData_t *pInputData, boolean *pbCondGrpCheckAbrtRes,
                                           boolean *bGroupConditionTrue, uint16 *puHypInCondGroup)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  /* stores the hypotheses used in the parameters. This is used to reduce 
     processing power as unused Hypothesis need not to be checked thereafter*/
  HEADParameterHypothesisSub_t rgHypUsed;
  HEADParameterHypothesisSub_t rgInputHypTriggered = 0;
  /*this struct is filled for every hyp and the independent parameter check
    and evaluated at the end of the ConditionGroup. Dependend on the operator the max and min time is used.*/
  HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT];
  /*holds the current hyp return result*/
  eHEADSpecialBool_t eHypothesisResult;
  /*holds the overall hypothesis result(whether all required hypothesis are true) */
  eHEADSpecialBool_t eOverallHypResult = HEADSpecialBool_notchecked;
  /*holds the independent parameter return value*/
  eHEADSpecialBool_t eIndependentParResult = HEADSpecialBool_notchecked;
  uint8 uiCurrentHyp;
  const uint32 uiBitFlag = 1u;
  boolean bCondGrpHypAndLogic = b_FALSE;
  boolean bCheckAbrtRes = b_FALSE;

  /* Get current condition group data */
  HEADConditionGrp_t *const pConditionGrp = HEADGetConditionGrp(pTransition,pModule->uiCurrentCondGrpNr);

  if(pConditionGrp == NULL)
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    /* Get Hypothesis logic(AND/OR) for the condition group */
    bCondGrpHypAndLogic = HEADParamHypLogic_MustBeAnd(pTransition->uiCondGrpHypLogic,pModule->uiCurrentCondGrpNr);

    /*Preselection of Hypotheses which have to be checked*/
    HEADGSMGetParametersToRelevantHyps(pConditionGrp,&rgHypUsed,pInputData);
    /*Init all values inParamValThisModuleActive at the beginning of ConditionGroup check*/
    HEADGSMInitActiveFunction(sParamValThisModuleActive, b_TRUE);   
  
    /*--------------------------------------*/  
    /*Cycle through matching Hypotheses list*/
    /*--------------------------------------*/ 
    for(uiCurrentHyp = 0u; (uiCurrentHyp < (uint8)MAX_NUM_OF_HYPS) && (locError == GDB_ERROR_NONE); uiCurrentHyp++)
    {
      /*get the hypothesis with index uiCurrentHyp from the hypotheses list */
      const HEADHypothesis_t *const pHyp = HEADGetHypothesis(pInputData->rgHypothesisList, uiCurrentHyp);
      /* For safety sake check the resulting pointer */
      if (pHyp->pHypothesis != NULL)
      {
        #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
        if (*pbCondGrpCheckAbrtRes == b_TRUE)
        {
            if (((uiBitFlag << uiCurrentHyp) & (uint32)(pTransition->puHypInCondGroup[pModule->uiCurrentCondGrpNr]))!= 0u)
            {
                bCheckAbrtRes = b_TRUE;
            }
            else
            {
                bCheckAbrtRes = b_FALSE;
            }
        }
        #endif
        if (MEDIC_e_GetHypType(pHyp) != CDHypothesisType_No)
        {
          /*set IntermediateResult to notchecked at the beginning of every hypothesis*/
          eHypothesisResult = HEADSpecialBool_notchecked;
          /*Reset/Init sParamValThisModuleActive for hyp dependent parameters*/
          HEADGSMInitActiveFunction(sParamValThisModuleActive, b_FALSE);
          /*is the kinematic Hypothesis-Subtype (e.g. RunupStationary) stored in rgHypUsed... */
          if( (rgHypUsed & (HEADParameterHypothesisBit(MEDIC_e_GetHypType(pHyp)))) != 0u )
          {
            /*store these hyps which are triggerd regardless of true or false*/
            rgInputHypTriggered |= (HEADParameterHypothesisBit(MEDIC_e_GetHypType(pHyp)));
            /*check conditions in this condition group with the current hyp*/
        
            locError = HEADGSMCheckConditions(pModule,pInputData, pConditionGrp, &eHypothesisResult,0, sParamValThisModuleActive, 
                                              #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                              sParamValOCG, 
                                              #endif
                                              pHyp, uiCurrentHyp,b_FALSE,0,&bCheckAbrtRes);
          }
          /*if the hypothesis is true it will be stored in pModule->uiHypInOrGroup[uiOrGroup] for further usage in the output functions*/
          if(    (locError          == GDB_ERROR_NONE      )
              && (eHypothesisResult == HEADSpecialBool_True) )
          {
            *puHypInCondGroup = (uint16)((uiBitFlag<<uiCurrentHyp) | (uint32)(*puHypInCondGroup));
            if(eOverallHypResult == HEADSpecialBool_notchecked)
            {
              eOverallHypResult = HEADSpecialBool_True;
            }
          }
          else if(    (locError          == GDB_ERROR_NONE       )
                   && (eHypothesisResult == HEADSpecialBool_False) )
          {
            eOverallHypResult = HEADSpecialBool_False;
          }
          else
          {
            /* no change */
          }
        }
        #if ((MEDIC_ARCHITECTURE_VERSION >= 0x10) && (MEDIC_CFG_ABORT_REASON))
        else if (bCheckAbrtRes == b_TRUE)
        {
          *MEDIC_p_ModFCTDataAbortReasonHypLost((uint8)pModule->eModuleNr) = b_TRUE;
        }
        #endif
        else
        {
          /* do nothing*/
        }
      }
      else
      {
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10) // TO DO this need to adopted for New Hypothesis structure FSF500 
        /* Here we are in the error path. */
        /* This should never happen, therefore create an assertion failure */
        MEDIC_ASSERT(FALSE); /*PRQA S 3112,3119 *//* Date: 2018-12-17, Reviewer: Pronnoy Chowdhury, Reason: This code is placed for assertive failure and hence cannot be removed */
        /* Set the error value to allow an error handling */
        locError = GDB_ERROR_POINTER_NULL;
        #endif 
      }
    }

    /*-----------------------------------*/  
    /*Evaluate the independent parameters*/
    /*-----------------------------------*/
    if (locError == GDB_ERROR_NONE)
    {
      /*Reset/Init sParamValThisModuleActive for independent parameters*/
      HEADGSMInitActiveFunction(sParamValThisModuleActive, b_FALSE);

      #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
      if (*pbCondGrpCheckAbrtRes == b_TRUE)
      {
          bCheckAbrtRes = (((uiBitFlag << HEADHypothesisIndependent) & (uint32)(pTransition->puHypInCondGroup[pModule->uiCurrentCondGrpNr]))!= 0u) ? b_TRUE : b_FALSE;
      }
      #endif

      /*eval independent parameters, therefore check all parameters which have no hyps*/
      locError = HEADGSMCheckConditions(pModule,pInputData, pConditionGrp, &eIndependentParResult,rgInputHypTriggered, 
                                        sParamValThisModuleActive, 
                                        #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                        sParamValOCG, 
                                        #endif
                                        NULL, HEADNoHypothesis,b_FALSE,0, &bCheckAbrtRes);
    }
  
    /*-----------------------------*/  
    /*Merge Results and set OKTimer*/
    /*-----------------------------*/ 
    if( (locError == GDB_ERROR_NONE)
      /*there is no hyp*/
      &&(*puHypInCondGroup == 0u)
      /*and all independent parameters are not checked*/
      &&(eIndependentParResult == HEADSpecialBool_notchecked)
      )
    {
      *bGroupConditionTrue = b_FALSE;
      /*reset fConditionsOKTimer*/ 
      /*PRQA S 0491 1*/
      pConditionGrp->fConditionsOKTimer = 0.0f;
    }
    else if((locError == GDB_ERROR_NONE)
           /*(at least one KIN hyp 0-11 is true when logic:0) or (all hypothesis are true when logic:1) or there is no hyp dependent parameter:*/
              /* OR logic for hypothesis */
           &&(  ((bCondGrpHypAndLogic == b_FALSE) && (*puHypInCondGroup != 0u)) 
              /* AND logic for hypothesis */
              ||((bCondGrpHypAndLogic == b_TRUE) && (eOverallHypResult == HEADSpecialBool_True)) 
              ||(rgHypUsed == 0u))
           /*and all independent parameters are true or not checked (there are no independent params, otherwise set to false)*/
           &&((eIndependentParResult == HEADSpecialBool_True) || (eIndependentParResult == HEADSpecialBool_notchecked))
           )
    {
      *bGroupConditionTrue = b_TRUE;
      /*increment fConditionsOKTimer if ConditionGroup is true so far*/  
      /*PRQA S 0491 15*/
      pConditionGrp->fConditionsOKTimer += pInputData->fCycleTime;

      /*evaluate function active time - filled for every hyp and independent and stored max
        this function decides if an ConditionGroup is TRUE or FALSE*/
      HEADGSMEvaluateActiveModuleTime(bGroupConditionTrue, sParamValThisModuleActive,pConditionGrp->fConditionsOKTimer);
      /*set independent evaluatiuon result to uiHypInOrGroup*/
      if((eIndependentParResult == HEADSpecialBool_True) && ((*bGroupConditionTrue) == b_TRUE))
      {
        *puHypInCondGroup = (uint16)((uiBitFlag<<HEADHypothesisIndependent) | (uint32)(*puHypInCondGroup));
      }
    }
    else
    {
      /*set explicitly to false*/
      *bGroupConditionTrue = b_FALSE;
      /*reset fConditionsOKTimer for this ConditionGroup*/
      /*PRQA S 0491 1*/
      pConditionGrp->fConditionsOKTimer = 0.0f;
    }
  }

  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  _PARAM_UNUSED(pbCondGrpCheckAbrtRes);
  #endif
  return locError;
} /*PRQA S 7002 */ /*date: 2020-10-21, Reviewer: Siri Prakash, Reason:suppressing cyclomatic complexity for better code maintainability*/  



/****************************************************************************************************************************
  Functionname:         HEADGSMResetParamValOMIS                                                                        */ /*!

  @brief                Init function for OtherModulInState

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
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
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


#if (HEAD_AUTO_CFG_NO_OCG > 0)
/****************************************************************************************************************************
  Functionname:         HEADGSMResetParamValOCG                                                                         */ /*!

  @brief                Init function for OtherConditionGroups

  @description          Init function for OtherConditionGroups
                        Note that no Pointer checks are performed. Calling Function needs 
                        to assert that input pointers are valid.
                        @startuml
                        Start
                        :Set Local_Error as none;
                        If ((Is pointer to parameter value to evaluate other condition group valid?)) then (yes)
                          :Reset the count of other condition group check used;
                          While ((loop throuth all other condition group Parameter Value)) is (valid parameter)
                            :Initialize other condition group parameter values;
                          End while (Invalid parameter)
                        Else (no)
                          :set null pointer error;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[out]           sParamValOCG : Other Condition Groups paramter pointer
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADGSMResetParamValOCG(HEADOtherCondGrpsCheck_t *sParamValOCG)
{
  uint32 uiICnt;
  eGDBError_t locError = GDB_ERROR_NONE;

  /*init other condition groups structure*/
  if(sParamValOCG != NULL)
  {
    sParamValOCG->uiNrOfChecksUsed = 0u;
    for(uiICnt = 0uL; uiICnt < HEAD_AUTO_CFG_NO_OCG; uiICnt++)
    {
      sParamValOCG->fFactor[uiICnt]      = 1;
      sParamValOCG->fTime[uiICnt]        = 0;
      sParamValOCG->uiBitPackOCG[uiICnt] = 0;
      sParamValOCG->uiLinkedSCG[uiICnt]  = 255;
    }
  }
  else
  {
    locError = GDB_ERROR_POINTER_NULL;
  }

  return locError;
}
#endif

/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADGSMInitActiveFunction                                                                       */ /*!

  @brief                Init function for ActiveFunction

  @description          Init function for ActiveFunction
                        Note that no Pointer checks are performed. Calling Function needs 
                        to assert that input pointers are valid.
                        @startuml
                        Start
                        If ((Initialise ALL is True)) then (yes)
                            :Initialize UsedOverall and Threshold Value;
                        Note
                        if initAll is FALSE fThreshold and bUsedOverall isn't initialized here because 
                        they should be available over the whole orGroup-check and evaluated in the end
                        End note
                        Endif
                        :Initialize _Used, _Operator, _InTime And 
                         Factor values;
                        Stop
                        @enduml

  @return               void

  @param[out]           sParamValThisModuleActive : Module Active Param Value
  @param[in]            initAll : Boolean indicates Initialize All is needed or not
  
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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1106-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
/*PRQA L:DESIGN*/
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


/****************************************************************************************************************************
  Functionname:         HEADGSMGetParametersToRelevantHyps                                                              */ /*!

  @brief                Preselection of Hypotheses to be checked

  @description          This functions loops through the parameterlist(conditionlist) in the current 
                        condition group and checks which hypotheses have the potential to become 
                        relevant and so should be checked later. Bits will be set in the
                        bitfield-array rgHypUsed
                        @startuml
                        Start
                        :Fetch Parameter List for the 
                        corresponding condition group;
                        While ((Loop through all parameters)) is (valid parameter)
                          :Get Parameter;
                          if((Check if Parameter is mode independent) OR 
                        (Paramtermode (early-middle-late-ACC) is used in main mode))) then (yes)
                            :Update Used Hypotheses List;
                          Endif
                          :Go to next Relevent Parameter in the list;
                        Endwhile (invalid parameter)
                        Stop
                        @enduml

  @return               void

  @param[in]            pConditionGrp : pointer to condition group
  @param[out]           rgHypUsed : Bit field for head parameter hypothesis
  @param[in]            pInputData : Pointer to HEAD Input data
  
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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1137-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADGSMGetParametersToRelevantHyps(const HEADConditionGrp_t *pConditionGrp,
                                               HEADParameterHypothesisSub_t *rgHypUsed,
                                               const struct HEADInputData_t *pInputData)
{
  const HEADParameterEmpty_t *pParam = pConditionGrp->pParameterList;
  *rgHypUsed = 0;
  /* Loop through all parameters in current condition group */
  while(pParam != NULL)
  {
    const HEADParameterType_t *const locParameterType = &(pParam->ParameterType.sParameterType);

    if( (locParameterType->ParameterMode == 0u)    /*either parametermode independent*/
            /*paramtermode (early-middle-late-ACC) is used in this mode*/
         ||((((uint32)locParameterType->ParameterMode) & ((uint32)HEADParameterModeBit(pInputData->eHEADMainMode))) != 0u)
         )
    {
      *rgHypUsed |= (HEADParameterHypothesisSub_t)locParameterType->ParameterHypSubType;
    }

    /*set pParam to the next Relevent Parameter in the list(Using the sorted list)*/
    pParam = pParam->ParameterType.pNextRelevantParam;
  }
}

/****************************************************************************************************************************
  Functionname:         HEADDGSMNextSubGroup                                                                            */ /*!

  @brief                This function iterate through parameter group list and return the next 
                        subgroup pointer.If no subgroup left, pParamList will become NULL 

  @description          This function iterate through parameter group list and return the next 
                        subgroup pointer.If no subgroup left, pParamList will become NULL 
                        @startuml
                        Start
                        :Get Previous evaluated parameter out type
                        And operator type;
                        :set next_subgroup_found flag as false;
                        While ((Parameter list != NULL)AND(Next_subgroup_found flag is false?)) is (yes)
                          :get current parameter;
                          If ((Previous evaluated parameter out type != current parameter out type)OR
                        (Previous evaluated parameter operator type != current parameter operator type)) then (yes)
                            :set next_subgroup_found flag as True;
                          Else (no)
                            :Go to next Relevent Parameter in the list;
                          Endif
                        Endwhile (no)
                        Stop
                        @enduml

  @return               void

  @param[in]            pParamList : pointer to parameter list
  
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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADDGSMNextSubGroup(const HEADParameterEmpty_t ** pParamList )
{
  uint8 uiOperatorPrev = (uint8)(*pParamList)->ParameterType.sParameterType.ParamOperator;
  uint8 uiOutTypePrev = (uint8)(*pParamList)->ParameterType.sParameterType.ParamOutType;
  boolean bNextSubGrpFound = b_FALSE;

  while( (*pParamList != NULL)
        &&(bNextSubGrpFound == b_FALSE))
  {
    /*gets current parameter struct*/
    const HEADParameterType_t *const locParameterType = &((*pParamList)->ParameterType.sParameterType);

    if(  (uiOperatorPrev != (uint8)locParameterType->ParamOperator)
       ||(uiOutTypePrev != (uint8)locParameterType->ParamOutType)) 
    {
      bNextSubGrpFound = b_TRUE;
    }
    else
    {
      /*go to next list element in the sorted list*/
      *pParamList = (*pParamList)->ParameterType.pNextRelevantParam;
    }
  }
}


/****************************************************************************************************************************
  Functionname:         HEADGSMCheckConditions                                                                          */ /*!

  @brief               This function checks the conditions in a ConditionGroup

  @description          This function loops through the enum entries in HEADParamOutType_t
                        and evaluates the relevant parameters. Parameters can be Hypothesis
                        dependent or independent.
                        @startuml
                        Start
                        :Fetch Parameter list;
                        :set Local_Error as none;
                        :Fetch Module internal GSM Information;
                        If ((CDHypothesis available?)) then (yes)
                          If ((Valid Hypothesis Type) AND 
                            (Hypothesis Dynamic Property is valid) AND
                            (Hypothesis Object Class is valid)) then (yes)
                            :Get Hypothesis Dependent Values;
                            Note:Get Hypothesis type, Sensor Source, Dynamic Property and Object Class.
                          Else (no)
                            :set intermediate result false;
                          Endif
                        Endif
                          #orange:reset other module in state values struct
                          <b>HEADGSMResetParamValOMIS</b> >
                          :get parameter out type and operater type 
                          Of the first parameter in the list;
                          :Reset depending parameters for the first subgroup in the list;
                          :set param exist to not checked for every root parameter
                          element of the subgroup list;
                          #orange:init the values structures for this hypothesis
                          <b>HEADGSMResetParamValGeneral</b> >
                          While ((loop through the attached parameters)AND(No Local Error)AND(Intermediate Result!=False)) is (parameter valid)
                            : get current parameter;
                            :Get Used Hypothesis for the Parameter;
                            :Get sensor source for the Parameter;
                            If (((parameter is mode independent)OR(or parameter mode (early-middle-late-ACC) is used in main mode))AND
                        (whether sensor type match for hypothesis)AND
                        ((Object-class of hyp dependent parameter is allowed)OR(it's a hyp independent parameter))AND
                        ((dynamic property of hyp dependent parameter is allowed)OR(it's a hyp independent parameter))) then (yes)
                              #orange: check if this parameter is valid for evaluation
                              <b>HEADGSMParamValidForEval</b> >
                              If ((Is Parameter valid for evaluation?)) then (valid or checked)
                                #orange:Get value of the parameter
                                <b>HEADGetParam</b> >
                                If ((Is parameter value not found?)AND
                        (parameter main type is 3d table)) then (yes)
                                  :Get table parameter;
                                  If ((Table parameter's default X2 value == false))
                                    :set intermediate result false;
                                    :come out of the loop;
                                  Endif
                                Endif
                                If ((if locError == GDB_ERROR_NONE then the parameter is valid for this hyp and mode)) then (no local error)
                                  :Fetch parameter out type;
                                  #orange: place current info into parameter structures
                                  <b>HEADGSMPlaceCurrentInfoIntoParamStruct</b> >
                                Endif
                              Else (not_valid or not_checked)
                                :Do nothing;
                                Note
                                in both cases pParam will be set to the next parameter 
                                if HEADSpecialBool_False: skip current sub group evaluation
                                if HEADSpecialBool_notchecked: the loop will go on with the next
                                parameter
                                End note
                              Endif
                              :update param exist value;    
                            Endif
                            :Get evaluated parameter out type
                            And operator type;
                            If ((Param Exists == False)) then (yes)
                              #orange:skip current sub group evaluation as current 
                              parameter is not valid, go to next sub group
                              <b>HEADDGSMNextSubGroup</b> >
                            Else (no)
                              :Go to next relevant parameter;
                            Endif
                            If (((parameter list != NULL)AND
                        ((Previous evaluated parameter out type != current parameter out type)OR(Previous evaluated parameter operator type != current parameter operator type)))OR
                        (parameter list == NULL)) then (yes)
                              :get previoud parameter out type;
                              Note: evaluate previous sub group
                              #orange: Evaluate sub group conditions
                              <b>HEADDGSMEvalParamSubGroup</b> >
                              : reset depending parameters for the upcoming 
                              subgroup in the list;
                              note:Reset param valid and param exist information
                              :init the values structures for hypothesis
                              <b>HEADGSMResetParamValGeneral</b> >
                            Elseif ((value outside expected range error?)) then (yes)
                              :Reset local error;
                              :set intermediate result false;
                            Else 
                              :Do Nothing;
                              Note
                              For other error cases, module will get deactivate without 
                              checking other condition groups. Nothing to do here 
                              End note
                            Endif
                          Endwhile 
                          If (Param Exists != False)then (yes)
                                :will be evaluated at the end of each orGroup,
                                :Here just set thresholds only if relevant conditions of hypothesis are true;
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
                            Elseif((Abort reason is valid)AND(abort reason flag is true)AND(Param Exists is False)) then (yes)
                            partition #LightBlue **((MEDIC_CFG_ABORT_REASON))** {
                            :Capture Param output type information;
                            }
                            Else(no)
                            : Do nothing;
                          Endif
                          :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an error code.

  @param[in]            pModule : pointer to a HEAD Module 
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            pConditionGrp : pointer to condition group
  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            bfIgnoreHypSubTypes : Hypothesis Needed to be ignored for evaluation
  @param[in]            sParamValThisModuleActive : Module Active Param Value
  @param[in]            sParamValOCG : Other Condition Groups paramter pointer
  @param[in]            pHyp : Triggerd CD Hypothesis
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADGSMCheckConditions(HEADModule_t *pModule, const struct HEADInputData_t *pInputData,
                                          const HEADConditionGrp_t *const pConditionGrp,
                                          eHEADSpecialBool_t *pIntermediateResult,
                                          HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                          HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                          #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                          HEADOtherCondGrpsCheck_t *sParamValOCG,
                                          #endif
                                          HEADHypothesis_t const *pHyp, const uint8 uiHypNo, boolean bPreCondEval, uint8 PreCondNr, boolean *pbCheckAbrtRes)
{
  HEADGSMParamValues_t sParamValGeneral;
  HEADOtherModuleInState_t sParamValOMIS;
  uint8 uiOperatorPrev;
  uint8 uiOutTypePrev;
  eHEADParamOutType_t eOutType;
  eHEADParamOutType_t eOutTypePrev = HEADParamOutType_None;

  /* This list is the sorted list according to the operator and outType */
  const HEADParameterEmpty_t *pParamList = pConditionGrp->pParameterList;

  float32 fValue;
  HEADParameterHypothesisSub_t hypSubType = 0;
  HEADParameterSensorSourceSub_t SensorSubType = 0;
  HEADEBADynProp_t dynPropertyBit = 0;
  HEADEBAObjectClass_t objClassBit = 0;
  HEADEBAObjMovDir_t objMovDir = 0;
  eHEADSpecialBool_t eParamValid;
  eHEADSpecialBool_t eParamExists;
  eGDBError_t locError = GDB_ERROR_NONE;
  /*PRQA S 0314 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  HEADModuleInternalGSM_t *pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

  if(pHyp != NULL)
  {
    if( (MEDIC_e_GetHypType(pHyp) != CDHypothesisType_No) 
      &&(MEDIC_e_GetHypDynProp(pHyp) != EBADynProp_NotAvail) /*PRQA S 3415 */ /* reviewer: Sadhanashree Srinivasa, reason: expression with persistnt side effects */
      &&(MEDIC_e_GetHypObjClass(pHyp) != EBAObjectClass_NotAvail) /*PRQA S 3415 */ /* reviewer: Sadhanashree Srinivasa, reason: expression with persistnt side effects*/
      )
    {
      hypSubType     =  HEADParameterHypothesisBit(MEDIC_e_GetHypType(pHyp)); 
      #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
      SensorSubType  =  (HEADParameterSensorSourceSub_t) MEDIC_e_GetHypSensorSource(pHyp);
      #endif
      dynPropertyBit =  HEADDynPropBit(MEDIC_e_GetHypDynProp(pHyp)) 
                        & (HEADEBADynProp_t)pModuleInt->DynamicProperty;
      objMovDir      =  HEADObjMovDirBit(MEDIC_e_GetHypMovDir(pHyp))
                        & (HEADEBAObjMovDir_t)pModuleInt->ObjMovDir;
      
      objClassBit    =  HEADObjectClassBit(MEDIC_e_GetHypObjClass(pHyp)) 
                        & (HEADEBAObjectClass_t)pModuleInt->ObjClassSelection;
    }
    else
    {
      *pIntermediateResult = HEADSpecialBool_False;
    }
  }


  /* reset/init other module in state values struct*/
  HEADGSMResetParamValOMIS(&sParamValOMIS);

  uiOperatorPrev = (uint8)pParamList->ParameterType.sParameterType.ParamOperator;
  uiOutTypePrev  = (uint8)pParamList->ParameterType.sParameterType.ParamOutType;

  /***********  reset depending parameters for the first subgroup in the list *************/
  eParamValid = HEADSpecialBool_notchecked;

  /*set bParamExists to not checked for every root param element of the subgroup list*/
  eParamExists = HEADSpecialBool_notchecked;

  /*init the values structures for this hypothesis*/
  HEADGSMResetParamValGeneral(&sParamValGeneral);
  /****************************************************************************************/

  /* loop through the attached parameters to the element */
  /* Check points: The list with pNextRelevantParam iteration has NULL pointer for the last node.So loop will have an end*/
  while ( (pParamList != NULL)
        &&(locError == GDB_ERROR_NONE) 
        &&(*pIntermediateResult != HEADSpecialBool_False)
        )
  {
    /*gets current parameter struct*/
    const HEADParameterType_t *const locParameterType = &(pParamList->ParameterType.sParameterType);

    /*paramHypSubType is a bitfield with HypSubType(s) set in Autocoder for the current parameter*/
    const HEADParameterHypothesisSub_t bfParamHypSubType = (HEADParameterHypothesisSub_t)locParameterType->ParameterHypSubType;

    /*paramSensorSubType is a bitfield with SensorSubType(s) set in Autocoder for the current parameter*/
    const HEADParameterSensorSourceSub_t bfParamSensorSourceSubType = (HEADParameterSensorSourceSub_t)locParameterType->ParamSensorSource;

        /*either parametermode independent*/
    if( ( (locParameterType->ParameterMode == 0u)
          /*or parametermode (early-middle-late-ACC) is used in this mode*/
        ||((((uint32)locParameterType->ParameterMode) & ((uint32)HEADParameterModeBit(pInputData->eHEADMainMode))) != 0u)
        )
      /* whether sensor type match for hypothesis and  */
      && ( ( bfParamSensorSourceSubType == SensorSubType ) || (bfParamSensorSourceSubType == 0u) )
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
      &&((((HEADEBAObjMovDir_t)(locParameterType->ParamObjMovDir) & (objMovDir)) != 0u)
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
        /****  need to be modified for the customfilter function ******/
        locError = HEADGetParam(pParamList, pInputData, pHyp, uiHypNo, (uint8)pModule->eModuleNr, &fValue, &(pModuleInt->sAdditionalTableInputs), &sParamValGeneral.bFound);

        if ((sParamValGeneral.bFound == b_FALSE) && (((HEADParamMainType_t)pParamList->ParameterType.sParameterType.ParamMainType) == ((HEADParamMainType_t)HEADParamMainType_3dTable)))
        {
          /*PRQA S 0314 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
          const HEADParameterTable3D_t *pParamTable = (const HEADParameterTable3D_t *)((const void *)pParamList);
          if (pParamTable->X2DefaultResult == b_FALSE)
          {
            *pIntermediateResult = HEADSpecialBool_False;
            break;
          }
        }

        /* if locError == GDB_ERROR_NONE then the parameter is valid for this hyp and mode*/
        if(locError == GDB_ERROR_NONE) 
        {
          /* QAC 1482: dosen't matter here since ParamOutType is initialised in autocoder to one of enum types(eHEADParamOutType_t)*/
          /*PRQA S 1482 1*/
          eOutType = (eHEADParamOutType_t)locParameterType->ParamOutType;

          /*place current info into parameter structures*/
          locError = HEADGSMPlaceCurrentInfoIntoParamStruct( &sParamValGeneral, &sParamValOMIS, 
                                                             #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                                             sParamValOCG, 
                                                             pModule->uiCurrentCondGrpNr,
                                                             #endif
                                                             sParamValThisModuleActive, pParamList,
                                                             eOutType, 
                                                             fValue);
        }
      }
      else /*if( (eParamValid is same as HEADSpecialBool_notchecked) OR (eParamValid is same as HEADSpecialBool_False)  )*/
      {
        /*in both cases pParam will be set to the next parameter 
              if HEADSpecialBool_False:        skip current sub group evaluation
              if HEADSpecialBool_notchecked:   the loop will go on with the next parameter
        */
      }
      eParamExists = MIN(eParamExists, eParamValid);
    }

    uiOperatorPrev = (uint8)locParameterType->ParamOperator;
    uiOutTypePrev  = (uint8)locParameterType->ParamOutType;

    if(eParamExists == HEADSpecialBool_False) /* skip current sub group evaluation as current parameter is not valid */
    {
      HEADDGSMNextSubGroup(&pParamList);
    }
    else
    {
      /*go to next list element in the sorted list*/
      pParamList = pParamList->ParameterType.pNextRelevantParam;
    }

    if(locError == GDB_ERROR_NONE)
    {
      /* new subgroup list starts- evaluate previous sub group and reset depending parameters for the current subgroup*/
      if(((pParamList != NULL) &&  
        ((uiOperatorPrev != pParamList->ParameterType.sParameterType.ParamOperator) || 
        (uiOutTypePrev != pParamList->ParameterType.sParameterType.ParamOutType)))  ||
        (pParamList == NULL) /* Previous sub group was last sub group */
        #if HEAD_CFG_PRECONDITION == MEDIC_ON
        || (uiOutTypePrev == (uint8)HEADParamOutType_Precondition)
        #endif 
        )
      {
        /* QAC 1482: dosen't matter here since ParamOutType is initialised in autocoder to one of enum types(eHEADParamOutType_t)*/
        /*PRQA S 1482 1*/
        eOutTypePrev = (eHEADParamOutType_t)uiOutTypePrev;

        /***  Evaluate sub group conditions here - all parameters is assumed to be placed into the according structs  ***/  
        locError = HEADDGSMEvalParamSubGroup(pModule, pInputData, eParamExists, eOutTypePrev,
                                             #if (HEAD_AUTO_CFG_NO_OCG > 0)                            
                                             sParamValOCG, 
                                             #endif                                           
                                             &sParamValGeneral, &sParamValOMIS, uiOperatorPrev, pIntermediateResult, pHyp, uiHypNo, PreCondNr );


        /***********  reset depending parameters for the upcoming subgroup in the list *************/
        eParamValid = HEADSpecialBool_notchecked;

        /*set bParamExists to not checked for every root param element*/
        eParamExists = HEADSpecialBool_notchecked;

        /*init the values structures for this hypothesis*/
        HEADGSMResetParamValGeneral(&sParamValGeneral);
      }
    }
    else if(locError == GDB_ERROR_VALUE_RANGE) /* This case is included in 3D table parameter for handling the option 
                                                   when required value is not found in table*/  
    {
      /* Reset the error so as to continue evaluation of next condition group skipping current condition group(current group will become false) */
      locError = GDB_ERROR_NONE; 

      /* make the current condition group as False */
      *pIntermediateResult = HEADSpecialBool_False;
    }
    else
    {
      /* For other error cases, module will get deactivate without checking other condition groups. Nothing to do here */
    }

  } /*end-while*/
  if(*pIntermediateResult != HEADSpecialBool_False)
  {
    /* will be evaluated at the end of each orGroup, here: just set thresholds only if all the relevant conditions of hypothesis are true */
    float32 fOKTimerThreshold;
    /* there is a minTime Condition triggered by hyp or independent */
    if(sParamValThisModuleActive[HEADParamOperator_LESSTHAN].bUsed == b_TRUE)
    {
      /* transparent behavior is to handle negative timer thresholds as 0 */
      fOKTimerThreshold = MAX_FLOAT((sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fInTime * sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fFactor), 0.0f);
      /* is the threshold evaluated for this hyp or independent less than the overall threshold, so set it to overall */
      sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold = MIN_FLOAT(sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold, fOKTimerThreshold);
    }
    /* there is a maxTime Condition triggered by hyp or independent*/
    if(sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].bUsed == b_TRUE)
    {
      /* transparent behavior is to handle negative timer thresholds as 0 */
      fOKTimerThreshold = MAX_FLOAT((sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fInTime * sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fFactor ), 0.0f);
      /* is the threshold evaluated this hyp or independent greater than the overall threshold, so set it to overall */
      sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold = MAX_FLOAT(sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold, fOKTimerThreshold);
    }
    else
    {
        /* do nothing */
    }
  }
  #if ((MEDIC_ARCHITECTURE_VERSION >= 0x10) && (MEDIC_CFG_ABORT_REASON))
  else if((pbCheckAbrtRes != NULL) && (*pbCheckAbrtRes == b_TRUE) && (*pIntermediateResult == HEADSpecialBool_False))
  {
    *MEDIC_p_ModFCTDataAbortReasonParamOutType((uint8)pModule->eModuleNr) = (uint8)eOutTypePrev;
  }
  #endif
  else
  {
    /* do nothing */
  }
  
  #if ((MEDIC_ARCHITECTURE_VERSION < 0x10) || (!MEDIC_CFG_ABORT_REASON))
  _PARAM_UNUSED(pbCheckAbrtRes); /*PRQA S 3119,3201 */ /* date: 2020-07-06, reviewer: Nalina M, reason: This statement has no side effects*/
  #endif
  _PARAM_UNUSED(bPreCondEval); /*PRQA S 3119,3201 */ /* date: 2020-07-06, reviewer: Sadhanashree Srinivasa, reason: This statement has no side effects*/

  return locError;
}/* PRQA S 7002, 7007 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing cyclomatic complexity for better code maintainability */


#if (HEAD_AUTO_CFG_NO_OCG > 0)
/****************************************************************************************************************************
  Functionname:         HEADGSMCheckParamOCGPresent                                                                     */ /*!

  @brief                Checks if the current condition is already present in the list of 
                        conditions already processed based on CondGrpNr and uiSpecialParInfo parameters
                        Returns the condition index if present

  @description          Checks if the current condition is already present in the list of 
                        conditions already processed based on CondGrpNr and uiSpecialParInfo parameters
                        Returns the condition index if present
                        @startuml
                        Start
                        :Reset condition Index;
                        While ((Loop through all other_condition_check)) is (Other_condition index valid)
                          If ((check if the current condition is already present in the list of conditions already processed)) then (similar condition found)
                            :set current Index as condition Index;
                          Endif
                        Endwhile(Other_condition index invalid)
                        Stop
                        @enduml

  @return               void

  @param[in]            sParamValOCG : Other Condition Groups paramter pointer
  @param[in]            uiCondGrpNr : condition group number
  @param[out]           pCondIndex : pointer to condition index

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADGSMCheckParamOCGPresent( HEADOtherCondGrpsCheck_t *sParamValOCG, 
                                         uint8 uiCondGrpNr, 
                                         uint8 *pCondIndex)
{
  uint8 uiOtherCondCnt;

  /*Reset Condition Index */
  *pCondIndex = HEAD_AUTO_CFG_NO_OCG; 

  for(uiOtherCondCnt = 0u; (uiOtherCondCnt < sParamValOCG->uiNrOfChecksUsed) && (*pCondIndex == HEAD_AUTO_CFG_NO_OCG); uiOtherCondCnt++)
  {
    if(sParamValOCG->uiLinkedSCG[uiOtherCondCnt] == uiCondGrpNr)
    {
      *pCondIndex = uiOtherCondCnt; 
    }
  }
}
#endif

/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADGSMPlaceCurrentInfoIntoParamStruct                                                          */ /*!

  @brief                AutocoderInfo to ParamStruct

  @description          This function is called for every used parameter/condition
                        and puts the values set by the autocoder into the right 
                        ParamStruct which are evaluated later.
                        @startuml
                        Start
                        :Set Local_Error as none;
                        :get operator and parameter type;
                        If(check parameter out type is not Boolean) then (yes) 
                          :Set the operator;
                        Endif
                        If(check for Parameter is main value type) then (yes)
                          If(Is parameter out type is Bool) then (yes)
                            :update General State Machine Parameters Values;  
                          Else If((Is parameter out type is other module state Time?)) then (yes)  
                            :update other Module In State structure;
                          Else if ((Is parameter out type is Other condition Group)) then (yes)
                          partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                            If ((number of check used in other condition group is less than max?)) then (yes)
                              :check if condition with current condition group already present
                              <b>HEADGSMCheckParamOCGPresent</b> >
                              If ((no condition with current condition group?)) then (yes)
                                :Add new condition and intialize the value for other
                                Condition group check; 
                              Else if ((found similar condition)AND(value is stonger then previous)) then (yes)
                                : Replace all data with stronger except factor;
                              Else
                                :Do nothing;
                              Endif
                            Endif 
                          }
                          Else If(Is parameter out type is All conditions for Or group met) then (yes)
                            :Initialize param value this 
                            module Active structure;
                          Else
                            if ((Param general value found?)) then (yes)
                              :update general param value structure;
                              Note
                              In case of two values with same eOutType,OrGroup,mode,class etc 
                              the stronger condition will be checked
                              end note
                            endif  
                          Endif
                        Else If(check for Parameter is main factor type) then (yes)
                          If((Is parameter out type is OtherModuleStateTime?)) then (yes)
                            :update other module in state structure;
                            Note 
                            search for right rule with the same bitpack 
                            and operator to add factor there
                            end note
                          else if((Is parameter out type is OtherCondGroups)) then (yes)
                          partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                            :update other condition group structure;
                            Note
                            search for right rule with the 
                            same SCG to add factor there
                            End note
                          }
                          Else if ((Is parameter out type is AllConditionsForOrGroupMet)) then (yes)
                            :Update this module active structure
                             Factor value;
                          Else
                            :update general param value structure
                             Factor value;
                          Endif
                        Else (default)
                            :update locError with GDB_ERROR_UNKNOWN_TYPE;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error,  otherwise an error code is returned.

  @param[in,out]        sParamValGeneral : Pointer to General Param value
  @param[in,out]        sParamValOMIS : Pointer to Other Module in State Structure
  @param[in,out]        sParamValOCG : Other Condition Groups paramter pointer
  @param[in]            uiCondGrpNr : condition group number
  @param[in,out]        sParamValThisModuleActive : Module Active Param Value   
  @param[in]            pParam : pointer to a Parameter
  @param[in]            eOutType : Parameter Output Type
  @param[in]            fValue : Value to be evaluated
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision 

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/*PRQA L:DESIGN*/
static eGDBError_t HEADGSMPlaceCurrentInfoIntoParamStruct(
                                HEADGSMParamValues_t *sParamValGeneral,
                                HEADOtherModuleInState_t *sParamValOMIS,
                                #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                HEADOtherCondGrpsCheck_t *sParamValOCG,
                                uint8 uiCondGrpNr,
                                #endif
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
    eParOperator = (locParameterType->ParamOperator == 0u) ? HEADParamOperator_LESSTHAN: HEADParamOperator_GREATERTHAN; 
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
        #if (HEAD_AUTO_CFG_NO_OCG > 0)
        /*GUI: c-identifier == HEADParamOutType_OtherCondGroups? -> special for other condition groups check*/
        case HEADParamOutType_OtherCondGroups:
        {
          if(sParamValOCG->uiNrOfChecksUsed < HEAD_AUTO_CFG_NO_OCG)
          {
            uint8 uiCondIndex = HEAD_AUTO_CFG_NO_OCG;
            /* add the condition for different condition group, for same condition group replace with the stronger one */
            
            /* check if condition with current condition group already present */
            HEADGSMCheckParamOCGPresent( sParamValOCG, uiCondGrpNr, &uiCondIndex);

            if(uiCondIndex == HEAD_AUTO_CFG_NO_OCG)  /* Didn't found a similar condition, add as a new condition */
            {
              sParamValOCG->fTime[sParamValOCG->uiNrOfChecksUsed]        = fValue; 
              sParamValOCG->uiBitPackOCG[sParamValOCG->uiNrOfChecksUsed] = pParam->uiSpecialParInfo;
              sParamValOCG->fFactor[sParamValOCG->uiNrOfChecksUsed]      = 1;
              sParamValOCG->uiLinkedSCG[sParamValOCG->uiNrOfChecksUsed]  = uiCondGrpNr;
              sParamValOCG->uiNrOfChecksUsed++;
            }
            else if(  (uiCondIndex < HEAD_AUTO_CFG_NO_OCG)
                  &&(fValue > sParamValOCG->fTime[uiCondIndex])) /* Found condition is stronger, replace all data with stronger except factor */
            {
              sParamValOCG->fTime[uiCondIndex]        = fValue; 
              sParamValOCG->uiBitPackOCG[uiCondIndex] = pParam->uiSpecialParInfo;
              sParamValOCG->uiLinkedSCG[uiCondIndex]  = uiCondGrpNr;
            }
            else
            {
              /* found the weaker condition, ignore the weaker condition */
            }

          }
          else
          {
            locError = GDB_ERROR_ARRAY_OVERFLOW;
          } 
        }
        break;
        #endif
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
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
        case HEADParamOutType_TTB_PRE             :
        case HEADParamOutType_TTB_ACUTE           :
        #else
        case HEADParamOutType_TTB                 :
        #endif
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
        case HEADParamOutType_ObjListConfig       :
        case HEADParamOutType_CustomPar_00_HypIndependent   :
        case HEADParamOutType_CustomPar_01_HypIndependent   :
        case HEADParamOutType_CustomPar_02_HypIndependent   :
        case HEADParamOutType_CustomPar_03_HypIndependent   :
        case HEADParamOutType_CustomPar_04_HypIndependent   :
        case HEADParamOutType_CustomPar_05_HypIndependent   :
        case HEADParamOutType_CustomPar_06_HypIndependent   :
        case HEADParamOutType_CustomPar_07_HypIndependent   :
        case HEADParamOutType_CustomPar_08_HypIndependent   :
        case HEADParamOutType_CustomPar_09_HypIndependent   :
        case HEADParamOutType_CustomPar_10_HypIndependent   :
        case HEADParamOutType_CustomPar_11_HypIndependent   :
        case HEADParamOutType_CustomPar_00_HypDependent     :
        case HEADParamOutType_CustomPar_01_HypDependent     :
        case HEADParamOutType_CustomPar_02_HypDependent     :
        case HEADParamOutType_CustomPar_03_HypDependent     :
        case HEADParamOutType_CustomPar_04_HypDependent     :
        case HEADParamOutType_CustomPar_05_HypDependent     :
        case HEADParamOutType_CustomPar_06_HypDependent     :
        case HEADParamOutType_CustomPar_07_HypDependent     :
        case HEADParamOutType_CustomPar_08_HypDependent     :
        case HEADParamOutType_CustomPar_09_HypDependent     :
        case HEADParamOutType_CustomPar_10_HypDependent     :
        case HEADParamOutType_CustomPar_11_HypDependent     :
        #if HEAD_CFG_TURN_ASSIST
        case HEADParamOutType_SteeringAngle                   :
        case HEADParamOutType_TurnIndicatorInSteeringDirection:
        case HEADParamOutType_GasPedal                        :
        case HEADParamOutType_CorridorStopDistance            :
        #endif
        case HEADParamOutType_TargetVelocity                  :
        case HEADParamOutType_TargetAngle                     :
        case HEADParamOutType_ShortestDistance                :
        case HEADParamOutType_Precondition                    :
        case HEADParamOutType_ObjectSpeed                     :
        case HEADParamOutType_EBAStateControl                 :
        #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
        case HEADParamOutType_ItemConfidence                  :
        case HEADParamOutType_Inlap                           :
        case HEADParamOutType_ImpactVelEgo                    :
        case HEADParamOutType_ImpactVelRel                    :
        case HEADParamOutType_SafetyFunctionEnableFlag        :
        case HEADParamOutType_SafetyFunctionKeepFlag          :
        #endif
        {
          if (sParamValGeneral->bFound == b_TRUE)
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
              { 
                /*do nothing*/
              }
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
          for(uiOtherModCnt = 0u; (uiOtherModCnt < sParamValOMIS->uiNrOfChecksUsed) && (uiOtherModCnt < HEAD_AUTO_CFG_NO_OMIS) && (bModFound == b_FALSE); uiOtherModCnt++)
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
        #if (HEAD_AUTO_CFG_NO_OCG > 0)
        case HEADParamOutType_OtherCondGroups:
        {
          /*search for right rule with the same SCG to add factor there*/
          bModFound = FALSE;
          for(uiOtherModCnt = 0u; (uiOtherModCnt < sParamValOCG->uiNrOfChecksUsed) && (bModFound == FALSE); uiOtherModCnt++)
          {
            if(sParamValOCG->uiLinkedSCG[uiOtherModCnt] == uiCondGrpNr)
            {
              bModFound = TRUE;
              sParamValOCG->fFactor[uiOtherModCnt]*= fValue;  
            }
          }
          if(bModFound == FALSE)
          {
            locError = GDB_ERROR_UNKNOWN_TYPE;
          }
        }
        break;
        #endif
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
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
        case HEADParamOutType_TTB_PRE             :
        case HEADParamOutType_TTB_ACUTE           :
        #else
        case HEADParamOutType_TTB                 :
        #endif 
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
        case HEADParamOutType_ObjListConfig       :
        case HEADParamOutType_CustomPar_00_HypIndependent   :
        case HEADParamOutType_CustomPar_01_HypIndependent   :
        case HEADParamOutType_CustomPar_02_HypIndependent   :
        case HEADParamOutType_CustomPar_03_HypIndependent   :
        case HEADParamOutType_CustomPar_04_HypIndependent   :
        case HEADParamOutType_CustomPar_05_HypIndependent   :
        case HEADParamOutType_CustomPar_06_HypIndependent   :
        case HEADParamOutType_CustomPar_07_HypIndependent   :
        case HEADParamOutType_CustomPar_08_HypIndependent   :
        case HEADParamOutType_CustomPar_09_HypIndependent   :
        case HEADParamOutType_CustomPar_10_HypIndependent   :
        case HEADParamOutType_CustomPar_11_HypIndependent   :
        case HEADParamOutType_CustomPar_00_HypDependent     :
        case HEADParamOutType_CustomPar_01_HypDependent     :
        case HEADParamOutType_CustomPar_02_HypDependent     :
        case HEADParamOutType_CustomPar_03_HypDependent     :
        case HEADParamOutType_CustomPar_04_HypDependent     :
        case HEADParamOutType_CustomPar_05_HypDependent     :
        case HEADParamOutType_CustomPar_06_HypDependent     :
        case HEADParamOutType_CustomPar_07_HypDependent     :
        case HEADParamOutType_CustomPar_08_HypDependent     :
        case HEADParamOutType_CustomPar_09_HypDependent     :
        case HEADParamOutType_CustomPar_10_HypDependent     :
        case HEADParamOutType_CustomPar_11_HypDependent     :
        #if HEAD_CFG_TURN_ASSIST
        case HEADParamOutType_SteeringAngle                   :
        case HEADParamOutType_TurnIndicatorInSteeringDirection:
        case HEADParamOutType_GasPedal                        :
        case HEADParamOutType_CorridorStopDistance            :
        #endif
        case HEADParamOutType_TargetVelocity:
        case HEADParamOutType_TargetAngle:
        case HEADParamOutType_ShortestDistance:
        case HEADParamOutType_Precondition:
        case HEADParamOutType_ObjectSpeed:
        #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
        case HEADParamOutType_ItemConfidence                  :
        case HEADParamOutType_Inlap                           :
        case HEADParamOutType_ImpactVelEgo                    :
        case HEADParamOutType_ImpactVelRel                    :
        #endif
        {
            if (sParamValGeneral->bFound == b_TRUE)
            {
                sParamValGeneral->fFact *= fValue;
            }
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
} /*PRQA S 7004,7012 */ /*QAC message suppressed for Cyclomatic Complexity and for number of executable lines per function. */


/****************************************************************************************************************************
  Functionname:         HEADGSMParamValidForEval                                                                        */ /*!

  @brief                Check if parameter should be evaluated

  @description          This function checks if the parameter is valid for the evaluation.
                        There is a hypothesis/no hypothesis (hypSubType: !0 / 0)
                          The parameter can be...
                          -...hyp dependent or independent (bfParamhypSubType: !0 / 0)
                          -...hyp independent and become dependent by a hyp dependent factor.

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
  @param[out]           eRetValue : pointer to return value
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     
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
  
  @testmethod           Test of output data (dynamic module test)

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADGSMParamValidForEval( HEADParameterHypothesisSub_t hypSubType, 
                                      HEADParameterHypothesisSub_t bfParamHypSubType, 
                                      HEADParameterHypothesisSub_t bfIgnoreHypSubTypes,
                                      eHEADSpecialBool_t *eRetValue)
{
  /* Hypo-independent param evaluation and Param is flagged as Hypo independent */ 
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
       /* if( (   hypSubType is 0 ) AND (  bfParamHypSubType is not 0   ) && (  (bfIgnoreHypSubTypes & bfParamHypSubType) ia not 0) ) */  {
    /* parameter type was already evaluated in another step and must not be evaluated again*/
    *eRetValue = HEADSpecialBool_False;
  }
}


/****************************************************************************************************************************
  Functionname:         HEADGSMEvaluateGeneralParameters                                                                */ /*!

  @brief                Evaluates Values in ParamStruct

  @description          This function evaluates the values from ParamStruct (Endvalue = Value*Factor)
                        and returns the IntermediateResult.
                        As parameters can be either hyp dependent or independent, there are two separate evaluation processes.
                        @startuml
                        Start
                        :Set local error as None;
                        If ((is Patameter general Value used?)) then (yes)
                          #orange:Checks if the parameter is a hypothesis dependent or 
                          independent parameter
                          <b>HEADIsHypDependentParameter</b> >
                          if ((No_Error) AND (Hypotheis Dependent Parameter)) then (yes)
                            #orange:Get hypothesis output type
                            <b>HEADParamOutTypeToHypOutType</b> >
                            Note:Get hypothesis Output type based on param output type;
                            If ((No_Error))
                              #orange:Get Hypothesis Value
                              <b>HEADGetHypValue</b> >
                              If ((No_Error)AND(Value Not Found)) then (yes)
                                :Set Default value as Parameter value;
                              endif
                                endif
                          elseif ((No_Error)) then (yes)
                            #orange:Get hypothesis independent parameter value
                            <b>HEADGSMGetIndValue</b> >
                          Endif
                          If ((No_Error)) then (yes)
                            #orange:Get Parameter Result
                            <b>HEADGSMGetParamResult</b> >
                            Note:Return parameter result if the condition of the param type is met
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
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            sParamValGeneral : General Param value
  @param[in]            uiOperator : operator used in the Parameter
  @param[in]            uiModuleNr : Module Number 
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            pHyp : Triggerd CD Hypothesis
  @param[in]            eOutType : Parameter Output Type
  
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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADGSMEvaluateGeneralParameters(eHEADSpecialBool_t *pIntermediateResult,
                                                    const HEADGSMParamValues_t *sParamValGeneral,
                                                    const uint8 uiOperator,
                                                    const uint8 uiModuleNr, 
                                                    const struct HEADInputData_t *pInputData, 
                                                    const HEADHypothesis_t *pHyp,
                                                    const uint8 uiHypNo,
                                                    const eHEADParamOutType_t eOutType)
{
  boolean bTempCondition;
  float32 fParamValue = 0.0f;
  boolean bFound = b_FALSE;
  eGDBError_t locError = GDB_ERROR_NONE;
  uint16 cascade_Value = sParamValGeneral->uiBitPack;
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
        locError = HEADGetHypValue(pInputData, pHyp, uiHypNo, eHypOutType, uiModuleNr, &bFound, &fParamValue, cascade_Value);
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


/****************************************************************************************************************************
  Functionname:         HEADGSMGetParamResult                                                                           */ /*!

  @brief                get the result if the condition of the param type is met

  @description          If the condition for the parameter is met set result as True else false
                        @startuml
                        Start
                        :Set local error as None;
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
                        :Return local error;
                        stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise Error correspond to type Unknown.

  @param[in]            fValue : Value to be evaluated
  @param[in]            fFact : Factorial value to be evaluated
  @param[in]            fParamValue : Param Value
  @param[in]            uiOperator : operator Used in the Parameter
  @param[out]           bTempCondition : evaluation Result
  
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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
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


#if 0
/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADGSMCheckOtherOrGroup                                                                        */ /*!

  @brief                Check if other orGroup in the same module is true or not

  @description          This function checks if another orGroup in the same module is true or not for a specific time. 
                        Attention: timer are increades each orGroup after their own check
                        --> checking a smaller orGroup number will have updated timers
                        --> checking a higher orGroup number will be delayed by one cycle
                        @startuml
                        Start
                        :Set local error as None;
                        #orange:Fetch the orGroup
                        <b>HEADBitPackToOtherOrGroup_OrGroupNr</b> >
                        Note: Fetch the orGroup that Need to be checked. 
                        #orange:Fetch the needed Condition
                        <b>HEADBitPackToOtherOrGroup_MustBeTrueFalse</b> >
                        Note:Fetch the condition that either need to be True or False.
                        :Find Timer Index;
                        Note:Timer Index is based on orGroup and Module State
                        #orange:Evaluate the Condition
                        <b>HEADGSMGetParamResult</b> >
                        If ((No_Error)) then (yes)
                             If ((Condition_Needed==True) AND (Evaluated_Condition==True)) then (yes)
                            :Set Result as True;
                             Elseif ((Condition_Needed==False) AND (Evaluated_Condition== False)) then (yes)
                            :Set Result as True;
                            Else 
                            :Do Nothing;
                            Endif
                        Else
                            :Set Result as False;
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            sParamValGeneral : General Param value
  @param[in]            eState :  Module State
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/*PRQA L:DESIGN*/
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
#endif


#if (HEAD_AUTO_CFG_NO_OCG > 0)
/****************************************************************************************************************************
  Functionname:         HEADAllocateSCGTimer                                                                            */ /*!

  @brief                Allocates a new timer from the timer buffer(pCondGrpTimer)

  @description          Allocates a new timer from the timer buffer and reset the timer value.
                        If the timer buffer is already full, it returns error
                        @startuml
                        Start
                        :Set Local_Error as None;
                        :Fetch module internal sate information;
                        If ((Is pointer to module internal information valid?)AND
                        (Is pointer to condition group timer valid?)) then (yes)
                          :Fetch the index of next timer;
                          If ((Is used condition group timer cound < total number of condition group timer)) then (free timer available)
                            :Allocate a timer;
                            :initialise the timer Id for the next time access;
                            :initialise the timer value;
                            :increase the used timers count;
                          Else (Not enough timers available)
                            :set unknown type error;
                          Endif
                        Else
                          :Set null pointer error;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an Error code.

  @param[in,out]        pModule : Pointer to a HEAD Module

  @glob_in              None
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  Required condition group Nr and Transition Nr should be filled in pModule structure 
                        before calling this function
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t   HEADAllocateSCGTimer(HEADModule_t *pModule)
{

  eGDBError_t locError = GDB_ERROR_NONE;

  HEADModuleInternalGSM_t *const pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

  if((pModuleInt != NULL)
    &&(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer != NULL))
  {
    uint8 uiICnt = pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers;

    /* Allocate a timer from the free timer list(if any) */
    if(pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers < pModuleInt->ParamCondGrpTimerList.uiNumTotalCGTimers)
    {
      HEADParamCondGrpTimer_t *pTimer = &(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer[uiICnt]);

      /* save the timer Id for the next time access */
      pTimer->sTimerId.TransNr   = pModule->uiCurrentTransNr;
      pTimer->sTimerId.CondGrpNr = pModule->uiCurrentCondGrpNr;

      /* initialise the timer since first time access */
      pTimer->fTimerVal = 0;

      /* increase the used timers count */
      pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers++;

    }
    else /* ERROR: Not enough timers available */
    {
      locError = GDB_ERROR_UNKNOWN_TYPE;
    }
  }
  else
  {
    locError = GDB_ERROR_POINTER_NULL;
  }

  return locError;
}


/****************************************************************************************************************************
  Functionname:         HEADSetResetSCGTimer                                                                            */ /*!

  @brief                Set/Reset special condition group timer.

  @description          It finds the allocated timer for the current condition group and set/reset the timer.
                        If no required timer is found it allocates a new timer using HEADAllocateSCGTimer()
                        @startuml
                        Start
                        :Set Local_Error as None;
                        :Fetch module internal sate information;
                        If ((Is pointer to module internal information valid?)AND
                        (Is pointer to condition group timer valid?)) then (yes)
                          While (go through all condition group timer and find the required timer) is (valid timer index)
                            :Get timer from the timer buffer;
                            If ((Is timer transition ID == module transition number?)AND
                        (Is tiemr condition group ID == module condition group number))
                              If ((Is timer Reset initiated?)) then (no)
                                :Incerment the timer with one cycle time;
                              Else (yes)
                                : Reset the timer value;
                              Endif
                              :set timer found flag;
                            Endif
                          End while (timer found/timer index invalid)
                          If ((no matching timer found?)) then (yes)
                            #orange:Allocates a new Special condition group timer
                            <b>HEADAllocateSCGTimer</b> >
                            If ((Is timer allocated successfully)) then (yes)
                              If ((Is timer Reset initiated?)) then (no)
                                :Incerment the timer with one cycle time;
                                Note:latest allocated timer
                              Endif
                            Endif
                          Endif
                        Else (no)
                          :set NULL pointer error;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an Error code.

  @param[in,out]        pModule : Pointer to a HEAD Module
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            bResetTimer : Boolean variable indicates reset of timer is initated or not

  @glob_in              None
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  Required condition group Nr and Transition Nr should be filled in pModule structure 
                        before calling this function
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t   HEADSetResetSCGTimer(HEADModule_t *pModule,
                                     const struct HEADInputData_t *pInputData,
                                     boolean bResetTimer)
{
  eGDBError_t locError = GDB_ERROR_NONE;

  HEADModuleInternalGSM_t *const pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

  if((pModuleInt != NULL)
    &&(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer != NULL))
  {
    uint8 uiICnt;
    HEADParamCondGrpTimer_t *pTimer = NULL;
    boolean bTimerFound = b_FALSE;

    /* find the required timer from the used timers list */
    for(uiICnt = 0; (uiICnt < pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers)&&(bTimerFound == b_FALSE); uiICnt++)
    {
       /* Get timer from the timer buffer */
       pTimer = &(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer[uiICnt]);

      if((pTimer->sTimerId.TransNr == pModule->uiCurrentTransNr) 
        &&(pTimer->sTimerId.CondGrpNr == pModule->uiCurrentCondGrpNr)
        )
      {
        /* Increase the timer value if(bResetTimer == FALSE)*/
        if(bResetTimer == b_FALSE)
        {
          pTimer->fTimerVal += pInputData->fCycleTime;
        }
        else /* Reset the timer value if (bResetTimer == TRUE) */
        {
          pTimer->fTimerVal = 0;
        }

        bTimerFound = b_TRUE;
      }
    }

    if(bTimerFound == b_FALSE) /* required timer not found, allocate a new timer */
    {
      locError = HEADAllocateSCGTimer(pModule);

      /* If timer is allocated successfully, set/reset the timer accordingly */
      if(locError == GDB_ERROR_NONE)
      {
        /* Increase the timer value if(bResetTimer == FALSE)*/
        if(bResetTimer == b_FALSE)
        {
          /* the latest allocated timer will be at the last index of the timer buffer(pCondGrpTimer)*/
          uiICnt = pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers;
          pTimer = &(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer[uiICnt-1]);

          pTimer->fTimerVal += pInputData->fCycleTime;
        }
      }
    }
  }
  else
  {
    locError = GDB_ERROR_POINTER_NULL;
  }

  return locError;
}

/****************************************************************************************************************************
  Functionname:         HEADGetSCGTimer                                                                                 */ /*!

  @brief                Get the special condition group timer value.

  @description          It finds the allocated timer for the current condition group and read the timer value in "fTimerVal"
                        If no required timer is found it allocates a new timer using HEADAllocateSCGTimer()
                        @startuml
                        Start
                        :Set Local_Error as None;
                        :Fetch module internal sate information;
                        If ((Is pointer to module internal information valid?)AND
                        (Is pointer to condition group timer valid?)) then (yes)
                          While (go through all condition group timer and find the required timer) is (valid timer index)
                            :Get timer from the timer buffer;
                            If ((Is timer transition ID == module transition number?)AND
                        (Is tiemr condition group ID == module condition group number))
                              :read the timer value and 
                              Send it to calling function;
                              :set timer found flag;
                            Endif
                          End while (timer found/timer index invalid)
                          If ((required timer not found?)) then (yes)
                            #orange:Allocates a new Special condition group timer
                            <b>HEADAllocateSCGTimer</b> >
                            :Initial timer value with zero and
                            Send the value to calling function;
                          Endif
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an Error code.

  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            fTimerVal : pointer to timer value 

  @glob_in              None
  @glob_out             None

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  Required condition group Nr and Transition Nr should be filled in pModule structure 
                        before calling this function
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t   HEADGetSCGTimer(HEADModule_t *pModule,
                                     float32 *fTimerVal)
{
  eGDBError_t locError = GDB_ERROR_NONE;

  HEADModuleInternalGSM_t *const pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

  if((pModuleInt != NULL)
    &&(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer != NULL))
  {
    uint8 uiICnt;
    boolean bTimerFound = b_FALSE;

    /* find the required timer from the used timers list */
    for(uiICnt = 0; (uiICnt < pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers)&&(bTimerFound == b_FALSE); uiICnt++)
    {
      HEADParamCondGrpTimer_t *const pTimer = &(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer[uiICnt]);

      if((pTimer->sTimerId.TransNr == pModule->uiCurrentTransNr) 
        &&(pTimer->sTimerId.CondGrpNr == pModule->uiCurrentCondGrpNr)
        )
      {
        /*read the timer value */
        *fTimerVal = pTimer->fTimerVal;
        bTimerFound = b_TRUE;
      }
    }

    if(bTimerFound == b_FALSE) /* required timer not found, allocate a new timer */
    {
      locError   = HEADAllocateSCGTimer(pModule);

      /* Initial timer value will be zero */
      *fTimerVal = 0;
    }
  }

  return locError;
}

/****************************************************************************************************************************
  Functionname:         HEADResetAllSCGTimers                                                                           */ /*!

  @brief                Reset all allocated special condition group timers for a module.

  @description          Reset all allocated special condition group timers for a module. 
                        It is done before entering a new state of a module or at initialisation 
                        @startuml
                        Start
                        :Set Local_Error as None;
                        :Fetch module internal sate information;
                        If ((Is pointer to module internal information valid?)AND
                        (Is pointer to condition group timer valid?)) then (yes)
                          While ((iterate through the allocated timer list)) is (valid timer index)
                            :Get timer from the timer buffer;
                            :reset used timers count;
                            :reset the timer value;
                            :reset the time ID;
                          End while (timer index invalid)
                        Else (no)
                          :set NULL pointer error;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if pointers are okay, else return NULL pointer Error code.

  @param[in,out]        pModule : Pointer to a HEAD Module

  @glob_in              None
  @glob_out             None

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t   HEADResetAllSCGTimers(HEADModule_t *pModule)
{
  eGDBError_t locError = GDB_ERROR_NONE;

  HEADModuleInternalGSM_t *const pModuleInt = ((HEADModuleInternalGSM_t *)(void *)(pModule->pInternal));

  if((pModuleInt != NULL)
    &&(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer != NULL))
  {
    uint8 uiICnt;

    /* iterate through the allocated timer list */
    for(uiICnt = 0; (uiICnt < pModuleInt->ParamCondGrpTimerList.uiNumTotalCGTimers); uiICnt++)
    {
      HEADParamCondGrpTimer_t *const pTimer = &(pModuleInt->ParamCondGrpTimerList.pCondGrpTimer[uiICnt]);

      /* reset used timers count */
      pModuleInt->ParamCondGrpTimerList.uiNumUsedCGTimers = 0;

      /* reset the timer value */
      pTimer->fTimerVal = 0;

      /* reset the time ID*/
      pTimer->sTimerId.CondGrpNr = 255;
      pTimer->sTimerId.TransNr   = 255;
    }
  }
  else
  {
    locError = GDB_ERROR_POINTER_NULL;
  }

  return locError;
}

/****************************************************************************************************************************
  Functionname:         HEADDGSMOtherCondGrpsAllFalse                                                                   */ /*!

  @brief                Checks if all the other condition groups are False

  @description          Checks if all the other condition groups related to a special condition are False 
                        if all the other condition groups are False return True.
                        @startuml
                        Start
                        :Set Local_Error as None;
                        If ((Is any condition group linked with this special condition?)) then (yes)
                          While ((Iterate through all condition groups)) is (condition group index valid)
                            If ((Is current condition linked with this special condition?)) then (yes)
                              #orange:Get condition group data
                              <b>HEADGetConditionGrp</b> >
                              If ((Is pointer this condition group valid?)) then (yes)
                                If ((Is the Condition group is True?)) then (yes)
                                  :Reset falg indicating that all condition group Linked with 
                                  this special condition is false;
                                Endif
                              Else (no)
                                :set NULL pointer error;
                              Endif
                            Endif
                          End while (condition group linked with this special condition active\n or condition group index invalid)
                        Else (no)
                          :set unknown type error;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an Error code..

  @param[in]            uiSelfCondGrpNr : group number in which the special condition belongs
  @param[in]            pTransition : pointer to state transition data
  @param[in]            uiBitPackOCG : Bit Pack indicting the linked other condition group with the special condition
  @param[out]           bCondGrpsAllFalse : Boolean variable indicates True, if all the related Condition groups are flase, 

  @glob_in              None
  @glob_out             None

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADDGSMOtherCondGrpsAllFalse(uint8 uiSelfCondGrpNr, const HEADStateTransition_t *const pTransition,
                                            const uint16 uiBitPackOCG, boolean *bCondGrpsAllFalse)
{
  eGDBError_t locError = GDB_ERROR_NONE;

  if(uiBitPackOCG)
  {
    uint8 uiICnt;

    *bCondGrpsAllFalse = b_TRUE;

    for(uiICnt = 0; (uiICnt < HEAD_AUTO_CFG_MAX_CONDGROUPS)&&(*bCondGrpsAllFalse == b_TRUE)&&(locError == GDB_ERROR_NONE) ; uiICnt++)
    {
      if((uiICnt != uiSelfCondGrpNr) /* Discard self condition group(which is a special condition group) */
         &&((uiBitPackOCG >> uiICnt) & 0x01))
      {
        /* Get condition group data */
        const HEADConditionGrp_t *const pConditionGrp = HEADGetConditionGrp(pTransition, uiICnt);

        if(pConditionGrp != NULL)
        {
          if(pConditionGrp->fConditionsOKTimer > 0.0f) /* Condition group is True */
          {
            *bCondGrpsAllFalse = b_FALSE;
          }
        }
        else
        {
          /*ERROR*/
          locError = GDB_ERROR_POINTER_NULL;
        }
      }
    }
  }
  else
  {
    /*ERROR*/
    locError = GDB_ERROR_UNKNOWN_TYPE;
  }
  return locError;
}


/****************************************************************************************************************************
  Functionname:         HEADDGSMCheckOtherCondGroups                                                                    */ /*!

  @brief                Check if other Condition Group(s) in the same transition is(are) true or not

  @description          This function checks if other Condition Groups are all_false/atleast_one_true for 
                        specific time. 
                        Attention: fConditionsOKTimer is used to check other condition group logic(true or false)
                                   If fConditionsOKTimer = 0.0f, this means the corresponding Condition group is false
                                   If fConditionsOKTimer > 0, this means the corresponding Condition group is true
                            --> checking a smaller Condition Group number will have updated timer
                            --> checking a higher Condition Group number will be delayed by one cycle
                        @startuml
                        Start
                        :Set Local_Error as None;
                        #orange: Get the module current state data
                        <b>HEADGetConditionGrp</b> >
                        If ((Is pointer to state data valid?)) then (valid)
                            #orange:Get the module current transition data
                            <b>HEADGetStateTransition</b> >
                            If ((Is pointer to transition data valid?)) then (valid)
                            While ((Iterate through all other condition group check)) is (condition valid)
                                If ((Is special condition group == module current condition group number)) then (yes)
                                #orange:Find whether all related condtion group
                                With this special conditon is false
                                <b>HEADDGSMOtherCondGrpsAllFalse</b> >
                                If ((No_Error)) then (yes)
                                    If ((Is Keep transition?)AND
                        (All related other condition groups false)) then (yes)
                                    #orange:Read the timer value
                                    <b>HEADGetSCGTimer</b> >
                                    If ((No_error)) then (yes)
                                        #orange:check the condition
                                        <b>HEADGSMGetParamResult</b> >
                                        If ((Is condition check result is True?)) then (yes)
                                        :Set result as True;
                                        Endif
                                        #orange:increment special condition group timer
                                        <b>HEADSetResetSCGTimer</b> >
                                    Endif
                                    Else if ((Is leave transition?)AND
                        (All related other condition groups are not false)) then (yes)
                                    #orange:Read the timer value
                                    <b>HEADGetSCGTimer</b> >
                                    If ((No_error)) then (yes)
                                        #orange:check the condition
                                        <b>HEADGSMGetParamResult</b> >
                                        If ((Is condition check result is True?)) then (yes)
                                        :Set result as True;
                                        Endif
                                        #orange:increment special condition group timer
                                        <b>HEADSetResetSCGTimer</b> >
                                    Endif
                                    Else 
                                    #orange:reset special condition group timer
                                    <b>HEADSetResetSCGTimer</b> >
                                    :Set result as false;
                                    Endif
                                Else (no)
                                    #orange:reset special condition group timer
                                    <b>HEADSetResetSCGTimer</b> >
                                    :Set result as false;
                                Endif
                                Endif
                            End while (condition invalid)
                            Else (Error)
                            :set NULL pointer error;
                            :Set result as false;
                            Endif
                        Else (Error)
                            :set NULL pointer error;
                            :Set result as false;
                        Endif
                        :Return Local_Error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or NULL pointer error.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            pInputData : pointer to HEAD Input data
  @param[in]            pModule : pointer to a HEAD Module
  @param[in]            sParamValOCG : Other Condition Groups paramter pointer

  @glob_in              None
  @glob_out             None

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_AUTO_CFG_NO_OCG

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADDGSMCheckOtherCondGroups(eHEADSpecialBool_t *pIntermediateResult,
                                                const struct HEADInputData_t *pInputData,
                                                HEADModule_t *pModule,   
                                                const HEADOtherCondGrpsCheck_t *sParamValOCG)
{
  uint8 uiICnt;
  eGDBError_t locError = GDB_ERROR_NONE;
  #if (HEAD_AUTO_CFG_NO_OCG > 0)
  float32 fTimerVal;
  #endif

  /* Get the module current state data */
  const HEADModuleState_t *const pState = HEADGetModuleState(pModule, ((HEADSMState_t)pModule->eDGSMState - (HEADSMState_t)pModule->eNumModuleStateMin));

  if(pState != NULL)
  {
    /* Get the module current transition data */
    const HEADStateTransition_t *const pTransition = HEADGetStateTransition(pState, pModule->uiCurrentTransNr);

    if(pTransition != NULL)
    {
      for(uiICnt = 0u; (uiICnt < sParamValOCG->uiNrOfChecksUsed) && (uiICnt < HEAD_AUTO_CFG_NO_OCG) && (locError == GDB_ERROR_NONE); uiICnt++)
      {
        boolean bTempCondition = b_FALSE;
        boolean bOtherCondGrpsAllFalse = b_FALSE; 

        /* search the special condition group */
        if(sParamValOCG->uiLinkedSCG[uiICnt] == pModule->uiCurrentCondGrpNr)
        {
          /*evaluate the logic of the special condition group */

          /* Find whether all condition groups are FALSE*/
          locError = HEADDGSMOtherCondGrpsAllFalse(pModule->uiCurrentCondGrpNr, pTransition, sParamValOCG->uiBitPackOCG[uiICnt], &bOtherCondGrpsAllFalse);
          
          if(locError == GDB_ERROR_NONE)
          {
            /* Keep transition..check all_false condition */
            if((pModule->eDGSMState == pTransition->eDGSMNextState)&&(bOtherCondGrpsAllFalse == b_TRUE)) 
            {
              /* read the timer value */
              locError = HEADGetSCGTimer(pModule, &fTimerVal);

              if(locError == GDB_ERROR_NONE)
              {
                locError = HEADGSMGetParamResult( sParamValOCG->fTime[uiICnt] ,
                                                  sParamValOCG->fFactor[uiICnt],
                                                  fTimerVal,
                                                  (uint8)HEADParamOperator_LESSTHAN, &bTempCondition);
                if(bTempCondition == b_TRUE)
                {
                  *pIntermediateResult = HEADSpecialBool_True;
                }

                /* set timer */
                (void)HEADSetResetSCGTimer(pModule, pInputData, b_FALSE);
              }
            }

            /* leave transition..check atleast_one_true condition */
            else if((pModule->eDGSMState != pTransition->eDGSMNextState)&&(bOtherCondGrpsAllFalse == b_FALSE)) 
            {

              /* read the timer value */
              locError = HEADGetSCGTimer(pModule, &fTimerVal);

              if(locError == GDB_ERROR_NONE)
              {
                /* check the condition */
                locError = HEADGSMGetParamResult( sParamValOCG->fTime[uiICnt] ,
                                                  sParamValOCG->fFactor[uiICnt],
                                                  fTimerVal,
                                                  (uint8)HEADParamOperator_GREATERTHAN, &bTempCondition);

                if(bTempCondition == b_TRUE)
                {
                  *pIntermediateResult = HEADSpecialBool_True;
                }

                /* set timer */
                (void)HEADSetResetSCGTimer(pModule, pInputData, b_FALSE);
              }
            }

            /* rest cases */
            else
            {
              /* reset timer */
              locError = HEADSetResetSCGTimer(pModule, pInputData, b_TRUE);
              *pIntermediateResult = HEADSpecialBool_False;
            }
          }
          else /*ERROR*/
          {
            /* reset timer */
            locError = HEADSetResetSCGTimer(pModule, pInputData, b_TRUE);
           *pIntermediateResult = HEADSpecialBool_False;
          }
        }
      }
    }
    else
    {
      /*ERROR*/
      locError = GDB_ERROR_POINTER_NULL;
      *pIntermediateResult = HEADSpecialBool_False;
    }
  }
  else
  {
    /*ERROR*/
    locError = GDB_ERROR_POINTER_NULL;
    *pIntermediateResult = HEADSpecialBool_False;
  }

  return locError;
}
#endif

#if ((HEAD_CFG_PRECONDITION == MEDIC_ON) && (MEDIC_ARCHITECTURE_VERSION >= 0x10))
/****************************************************************************************************************************
  Functionname:         HEADGSMCheckPreCond                                                                            */ /*!

  @brief                Check if Precondditon Condition is Evaluated to true or false

  @description          Check if Precondditon Condition is Evaluated to true or false
                        @startuml
                        Start
                        #orange:Fetch the Preconditon to check
                        <b>HEADGetPreCondition</b> >
                        If (((Is Preconditon Status Bit)==(True))) then (yes)
                            :set result as True;
                        Else (no)
                            :set result as False;
                        Endif
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or NULL pointer error.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            bitpack : Holds Precondtion number

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_CFG_PRECONDITION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADGSMCheckPreCond(eHEADSpecialBool_t *pIntermediateResult, const struct HEADInputData_t *pInputData, uint16 bitpack, const uint8 ModuleNr,  const uint8 uiHypNo)
{
    eGDBError_t locError = GDB_ERROR_NONE;
    HEADPreCond_t *pPreCond = HEADGetPreCondition(pInputData->pPreCondList, (uint8)bitpack);
    uint16 HypBit = ((uint16)((1u << uiHypNo) & 0xFFFFu));
    boolean bNewHypKeepActiveEntryCheck = (CML_GetBit(bitpack, 0x8000u) != b_FALSE);

    if ((bNewHypKeepActiveEntryCheck == b_FALSE) ||
        ((bNewHypKeepActiveEntryCheck == b_TRUE) && (CML_GetBit(HypCheckEnableCondtions[ModuleNr], HypBit) != b_FALSE)))
    {
        if (uiHypNo < (uint8)MAX_NUM_OF_HYPS)
        {
            if ((pPreCond->PreCondStatus == b_TRUE) && ((pPreCond->uiHypInCondGroup & HypBit) != 0u))
            {
                *pIntermediateResult = HEADSpecialBool_True;
                if (bNewHypKeepActiveEntryCheck == b_TRUE)
                {
                    CML_ClearBit(HypCheckEnableCondtions[ModuleNr], HypBit);
                }
            }
            else
            {
                *pIntermediateResult = HEADSpecialBool_False;
            }
        }
        else
        {
            if (pPreCond->PreCondStatus == b_TRUE)
            {
                *pIntermediateResult = HEADSpecialBool_True;
            }
            else
            {
                *pIntermediateResult = HEADSpecialBool_False;
            }
        }
    }
    return locError;
}
#endif
/****************************************************************************************************************************
  Functionname:         HEADGSMEvaluateOtherModuleInState                                                               */ /*!

  @brief                Checks for OtherModuleInState

  @description          This function checks if another module is (not) in a specified state
                        for more/less than a defined time and returns the IntermediateResult.
                        @startuml
                        Start
                        :Set Local_Error as None;
                        While((Iterate through all other module in state check used)AND(No_error))is (True)
                          #orange:Fetch the module number to check
                          <b>HEADBitPackToOtherModuleStateTime_ModuleNr</b> >
                          #orange:Fetch the module state to check
                          <b>HEADBitPackToOtherModuleStateTime_ModuleState</b> >
                          If ((Is module number valid?)AND
                        (Is Module list pointer valid)) then (yes)
                            #orange:Get corresponding module data
                            <b>HEADGetModule</b> >
                            If ((Is pointer to current module valid?)) then (no)
                              :set null pointer error;
                            Else (yes)
                              If ((Is module state to check is valid?)) then (yes)
                                #orange:Get module state data
                                <b>HEADGetModuleState</b> >
                                If ((Is intermediate result till this stage is either True or not checked?)) then (yes)
                                  If ((Is the check is for module IN state?)) then (yes)
                                    If ((Is module current state == state to check)) then (yes)
                                      #orange:Evaluate the condition
                                      <b>HEADGSMGetParamResult</b> >
                                    Endif
                                  Endif
                                  If ((Is the check is for module NOT_IN state?)) then (yes)
                                    If ((Is module current state != state to check)) then (yes)
                                      #orange:Evaluate the condition
                                      <b>HEADGSMGetParamResult</b> >
                                    Endif
                                  Endif
                                  If ((Is evaluation result is True)AND(No_error)) then (yes)
                                    :set result as True;
                                  Else (no)
                                    :set result as False;
                                  Endif
                                Endif
                              Endif
                            Endif
                          Else (no)
                            :set array overflow error;
                            :set result as false;
                          Endif
                        endwhile (False)
                        :Return the local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an error code.

  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            pInputData : pointer to HEAD Input data
  @param[in]            sParamValOMIS : Pointer to Other Module in State Structure

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
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
  HEADModuleState_t const *pState;

  eGDBError_t locError = GDB_ERROR_NONE;

  /*go for timing parameters*/
  for(uiICnt = 0u; (uiICnt < sParamValOMIS->uiNrOfChecksUsed) && (uiICnt < HEAD_AUTO_CFG_NO_OMIS) && (locError == GDB_ERROR_NONE); uiICnt++)
  {
    boolean bTempCondition = b_FALSE;
    uiModNr = HEADBitPackToOtherModuleStateTime_ModuleNr(sParamValOMIS->uiBitPack[uiICnt]);
    /* QAC 1482: the States in Bitpack are always less then HEADSMState_Max */
    /*PRQA S 1482,4394 1*/
    eStateToCheck = HEADBitPackToOtherModuleStateTime_ModuleState(sParamValOMIS->uiBitPack[uiICnt]);

    /*check valid module nr ?*/
    if((uiModNr < pInputData->pModuleList->uiNrOfModules)
      &&(pInputData->pModuleList->rgModules != NULL)
      )
    {

      /* Get corresponding module data */
      pCurrModule = HEADGetModule(pInputData->pModuleList,(uint32)uiModNr);

      if(pCurrModule == NULL)
      {
        locError = GDB_ERROR_POINTER_NULL;
      }

      else
      {
        /* check valid state ? */
        if(((HEADSMState_t)eStateToCheck < (pCurrModule->uiNumModuleStates + (HEADSMState_t)pCurrModule->eNumModuleStateMin))
          &&((HEADSMState_t)eStateToCheck >= (HEADSMState_t)pCurrModule->eNumModuleStateMin))
        {
          pState = HEADGetModuleState(pCurrModule, (((uint32)(HEADSMState_t)eStateToCheck) - ((uint32)(HEADSMState_t)pCurrModule->eNumModuleStateMin)));
          /* do further checks only if this can change the output i. e. if already false or checked 
             (will be later interpreted as false) final state of "AND" can not be change to true any more */
          if( (*pIntermediateResult == HEADSpecialBool_True) 
              ||(*pIntermediateResult == HEADSpecialBool_notchecked)
              )
          {
        
            /*module should be IN state*/
            if (HEADBitPackToOtherModuleStateTime_MustBeInState(sParamValOMIS->uiBitPack[uiICnt]) != b_FALSE)
            {
              /*is the current STATE of the modul with Nr. uiICnt in the STATE that it should be according to the autocoder */
              if(pCurrModule->eDGSMState == eStateToCheck)
              {
                locError = HEADGSMGetParamResult( sParamValOMIS->fInTime[uiICnt],
                                                  sParamValOMIS->fFactor[uiICnt],
                                                  pState->fStateTimer,
                                                  (uint8)(sParamValOMIS->eOperator[uiICnt]), &bTempCondition);
              }
            }
            /*module should be NOT IN state*/
            else
            {
              /*is the the modul in any STATE but not in the STATE that it should be according to the autocoder */
              if (pCurrModule->eDGSMState != eStateToCheck)
              {
                locError = HEADGSMGetParamResult( sParamValOMIS->fInTime[uiICnt],
                                                  sParamValOMIS->fFactor[uiICnt],
                                                  pState->fNotInStateTimer,
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


/****************************************************************************************************************************
  Functionname:         HEADGSMEvaluateActiveModuleTime                                                                 */ /*!

  @brief                Evaluate Active Module Time

  @description          This function may manipulate the overall result of the parameter evaluation in case the parameter 
                        "All Conditions are true for at least/most x s" is used, In this case the outcome "true" is 
                        delayed (at least) by that value or (at most) limited in time.
                        No plausibility checks are performed! (Change in logic compared to previous version)

                        No pointer checks are performed for the following pointers. Calling function shall assert 
                        that the pointers are valid.
                        bConditionTrue, sParamValThisModuleActive

                        bConditionTrue is assumed to be either true or false at this point of calculation. Other values are 
                        assumed to be an error.
                        @startuml
                        Start
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
  @param[out]           fConditionsOKTimer : condition group Ok timer count

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1137-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static void HEADGSMEvaluateActiveModuleTime(boolean *bConditionTrue,
                                      const HEADThisModuleActive_t sParamValThisModuleActive[HEADParamOperator_DEFAULT],
                                      float32 fConditionsOKTimer)
{
  /* Timing Parameter LESSTHAN is used */
  if( ((sParamValThisModuleActive[HEADParamOperator_LESSTHAN].bUsedOverall) == b_TRUE) 
    /* Timer is greater than the threshold*/
    &&( fConditionsOKTimer > sParamValThisModuleActive[HEADParamOperator_LESSTHAN].fThreshold)
    )
  {
    *bConditionTrue = b_FALSE;
  }
  /* Timing Parameter GREATERTHAN is used */
  if(  ((sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].bUsedOverall) == b_TRUE)
  /* Timer is less than the threshold*/
     &&( fConditionsOKTimer < sParamValThisModuleActive[HEADParamOperator_GREATERTHAN].fThreshold)
    )
  {
    *bConditionTrue = b_FALSE;
  }
}


/****************************************************************************************************************************
  Functionname:         HEADDGSMCreateConditionGroup                                                                    */ /*!

  @brief                creates the dgsm module state transition condition group

  @description          initialise the state transition condition group structure 
                        @startuml 
                        Start
                        :Set local error as None;
                        If ((Is Condition Group parameter list pointer valid?)) then (no)
                          :Set Null Pointer Error;
                        Else (yes)
                          :Initialise state transition condition group parameter list pointer 
                          with corresponding condition group parameter list;
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[out]           pConditionGrp : pointer to condition group
  @param[in]            pTransitionParameters : pointer to transition parameter list for the condition group

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
eGDBError_t HEADDGSMCreateConditionGroup(HEADConditionGrp_t *pConditionGrp, HEADParameterEmpty_t *pTransitionParameters)
{
  
  eGDBError_t locError = GDB_ERROR_NONE;
  if (pConditionGrp == NULL)
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pConditionGrp->pParameterList =  pTransitionParameters;
  }

  return locError;
}


/****************************************************************************************************************************
  Functionname:         HEADDGSMCreateStateTransition                                                                   */ /*!

  @brief                creates the dgsm module state transition

  @description          initialise the state transition structure 
                        @startuml 
                        Start
                        :Set local error as None;
                        If ((Is state transition pointer valid?)) then (no)
                          :Set Null Pointer Error;
                        Else (yes)
                          :Initialise the state transition structure;
                          Note right
                          Initialise the state transition with appropriate
                          values such as next state, condition group list,
                          number of condition group, hypothesis in condition group
                          and Hypothesis evaluation logic for each condition group 
                          End note
                        endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            eNextState : next state
  @param[out]           pTransition : pointer to state transition
  @param[in]            pConditionGroupList : Pointer to condition group list
  @param[in]            puHypInCondGroup : pointer to Condition group hypothesis 
  @param[in]            uiNumCondGroups : Number of conditional groups
  @param[in]            uiCondGrpHypLogic : Condition group hypothesis evaluation logic bit

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1137-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
eGDBError_t HEADDGSMCreateStateTransition(eHEADSMState_t eNextState, HEADStateTransition_t *pTransition, HEADConditionGrp_t *pConditionGroupList,
                                         uint16 * puHypInCondGroup, const uint8 uiNumCondGroups, HEADCondGrpBitField_t uiCondGrpHypLogic)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  if (pTransition== NULL)
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pTransition->eDGSMNextState        =  eNextState;
    pTransition->bInitialized          =  b_FALSE;  
    pTransition->pConditionGroupList   =  pConditionGroupList;
    pTransition->uiNumConditionGroups  =  uiNumCondGroups;
    pTransition->puHypInCondGroup      =  puHypInCondGroup;
    pTransition->uiCondGrpHypLogic     =  uiCondGrpHypLogic;
  }

  return locError;
}


/*PRQA S 2053 DESIGN*/
/****************************************************************************************************************************
  Functionname:         HEADCopyString                                                                                  */ /*!

  @brief                Copy the source string to the destination

  @description          Copy the source string to the destination
                        @startuml 
                        Start
                        :Set local error as None;
                        If (Is Source string pointer valid?) then (yes)
                          While ((loop through string length?)AND(loop stop indication flag == FLASE?)) is (yes)
                            If ((Is source string pointer pointing valid character value?)) then (yes)
                              :copy the character value from source to 
                               _Destination pointer;
                            Else (no)
                              :set stop loop indication flag TRUE;
                            Endif
                            Floating note:Copy string, zero terminated string assumed
                          Endwhile (no)
                          :Terminate destination string pointer with zero value;
                        Else (no)
                          :No string passed, set empty string;
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an error code.

  @param[out]           strDestination : pointer to string destination 
  @param[in]            strSource : pointer to string source
  @param[in]            strLength : string length

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1099-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
/*PRQA L:DESIGN*/
static eGDBError_t HEADCopyString(uint8 strDestination[], const uint8 strSource[], uint8 strLength)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  if (strSource != NULL)
  {
    uint8 uiI;
    boolean bStop = b_FALSE;
      
    /* Copy string, zero terminated string assumed */
    for (uiI = 0u; (uiI < (strLength-1u)) && (bStop == b_FALSE); uiI++)
    {
      if (strSource[uiI] != 0u)
      {
        strDestination[uiI]   = strSource[uiI];
      }
      else
      {
        bStop = b_TRUE;
      }
    }  
    strDestination[uiI] = 0u;
  }
  else
  {
    /* No string passed, set empty string */
    strDestination[0] = 0u;
  }

  return retValue;
}


/****************************************************************************************************************************
  Functionname:         HEADDGSMCreateTypicalState                                                                      */ /*!

  @brief                creates the dgsm module state

  @description          creates the dgsm module state
                        @startuml 
                        Start
                        :Set local error as None;
                        If ((Is pointer to Module state valid?)AND(Is pointer to SPM Qos Transition 
                        priority Mapping valid?)AND(Is pointer to state transition list valid?)) then (no)
                            :Set Null Pointer Error;
                        Else (yes)
                          :create the dgsm module state;
                          Note right
                          Initialise dgsm module state with state transition list,
                          List of output parameters, number of possible transitions,
                          Active state flag and Qos Transition mapping list
                          End note
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[out]           pState : pointer to Module state
  @param[in]            pStateTransitionList : pointer to state transition list
  @param[in]            uiNumTransitions : Number of possible transition 
  @param[in]            bActiveState : flag indicates Active state(TRUE) or output reset(FALSE)
  @param[in]            pSPMQoSMap :  pointer to Qos transition priority mapping list
  @param[in]            pStateOutputParams : pointer to state's output parameter list

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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1107-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
eGDBError_t HEADDGSMCreateTypicalState(HEADModuleState_t *pState, HEADStateTransition_t *pStateTransitionList,
                                       uint8 uiNumTransitions, boolean bActiveState, HEADSPMQoSMap_t * pSPMQoSMap,
                                       const void* pStateOutputParams)
{
  eGDBError_t locError = GDB_ERROR_NONE;

  if ((pState == NULL) || (pSPMQoSMap == NULL) || (pStateTransitionList == NULL))
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pState->pStateTransitionList    =  pStateTransitionList;
    pState->pOutputParams           =  pStateOutputParams;
    pState->uiNumTransitions        =  uiNumTransitions;
    pState->bActiveState            =  bActiveState;
    pState->pSPMQoSMap              =  pSPMQoSMap;
  }
  return locError;
}

/****************************************************************************************************************************
  Functionname:         HEADDGSMCreateTypicalModule                                                                     */ /*!

  @brief                creates a dgsm module

  @          creates a dgsm module
                        @startuml 
                        Start
                        :Set local error as None;
                        If ((Is pointer to module valid?)AND
                      description  (Is pointer to module's internal information valid?)) then (no)
                          :Set Null Pointer Error;
                        Else (yes)
                          #orange:Initialise module name
                          <b>HEADCopyString</b> >
                          :Initialise module number;
                          :Initialise module internal information;
                          Note left
                          Initialise module internal function pointer to state machine handiling function
                          and module internal type
                          End note
                          :Initialise module timers;
                          :Initialise modue state machine data;
                          :Initiliase module output data;
                          :Initiliase modue default QoS and ReportedError;
                          If ((Is module output pointer valid?)And
                          (Is module output function pointer valid?)) then (yes)
                            #orange:Initialise Output function>
                            Note:module output function call through function pointer
                          Else (no)
                            :Set Null Pointer Error;
                          Endif
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or NULL pointer error.

  @param[out]           strModuleName : Pointer to Module Name 
  @param[in]            eModuleNr : enum variable holds Module id
  @param[in]            pModule : Pointer to a Module
  @param[in]            pModuleInt : Pointer to Module inetrnal information
  @param[in]            pCondGrpTimer : pointer to condition group timer for counting other condition groups TRUE/FALSE time
  @param[in]            uiNumCondGrpTimers : Total number of timers allocated to evaluate conditions of OutType
  @param[in]            pModuleStateList : pointer to module state list
  @param[in]            pModuleOutput : pointer to Module Output
  @param[in]            uiNumQoSStates : number of QoS states assigned to the module
  @param[in]            uiNumModuleStates : number of states for the current module
  @param[in]            eModuleStateMin : module min state 


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
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1106-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
eGDBError_t HEADDGSMCreateTypicalModule(const uint8 *strModuleName, eHEADDGSM_Module_t eModuleNr, HEADModule_t *pModule, 
                                               HEADModuleInternalGSM_t *pModuleInt, HEADParamCondGrpTimer_t *pCondGrpTimer, uint8 uiNumCondGrpTimers, 
                                               HEADModuleState_t *pModuleStateList, struct HEADModuleOutputInterface_t *pModuleOutput, uint8 uiNumQoSStates,  
                                               uint8 uiNumModuleStates, eHEADSMState_t eModuleStateMin)
{
  eGDBError_t locError;

  if ((pModule == NULL)|| (pModuleInt == NULL))
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    locError = HEADCopyString(pModule->strModuleName, strModuleName, HEAD_MODULENAME_LENGTH);

    pModule->eModuleNr                  =  eModuleNr;

    pModuleInt->bInitialized                              = b_FALSE;

    /* Initialise internal module information */
    pModuleInt->InternalHeader.fpCustom                   =  &HEADGenericStateMachine;   // callback to the Dynamic GSM function
    pModuleInt->InternalHeader.eModuleInternalType        =  HEADModuleInternalType_GSM;

    /* Initialise module timers */
    pModuleInt->ParamCondGrpTimerList.pCondGrpTimer       =  pCondGrpTimer;
    pModuleInt->ParamCondGrpTimerList.uiNumTotalCGTimers  =  uiNumCondGrpTimers;

    /*PRQA S 0314 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
    pModule->pInternal                                    =  (HEADModuleInternalInterface_t *)(void *)pModuleInt;

    /* Initialise modue state machine data */
    pModule->eDGSMState                 =  eModuleStateMin;
    pModule->eDGSMLastState             =  eModuleStateMin;
    pModule->eDGSMLastCycleState        =  eModuleStateMin;
    pModule->uiNumQoSStates             =  uiNumQoSStates;
    pModule->uiNumModuleStates          =  uiNumModuleStates;
    pModule->eNumModuleStateMin         =  eModuleStateMin;
    pModule->pModuleStateList           =  pModuleStateList;

    /* Initiliase module output data */ 
    pModule->pOutput                    =  pModuleOutput;

    /* Initiliase modue default QoS and ReportedError */
    pModule->eQoS                       =  HEADModuleQoS_NormalRunning;
    pModule->eReportedError             =  HEADModuleRepError_NoError;

    if ((pModule->pOutput != NULL) && (pModule->pOutput->fpCustomOutput != NULL) )
    {
      /*initialize this output function*/
      locError = (*(pModule->pOutput->fpCustomOutput))(NULL, pModule, b_TRUE);

    } /* if(pState->pOutput is not equal to NULL AND pState->pOutput->fpCustomOutput is not equal to NULL) */
    else
    {
      locError = GDB_ERROR_POINTER_NULL;
    }
  }
  return locError;
}/*PRQA S 7007 *//* Date: 2020-10-22, Reviewer: Siri Prakash, Reason: suppressing cyclomatic complexity for better code maintainability  */


#if HEAD_CFG_PRECONDITION == MEDIC_ON
/*****************************************************************************************************************************
  Functionname:         HEADDGSMCreatePreCond                                                                           */ /*!

  @brief                This function is used to copy Precondition name and set the preconditon Output date to Default value.

  @description          This function is used to copy Precondition name and set the preconditon Output date to Default value.
                        @startuml
                        Start
                        :Set local error as None;
                         If (Is precondition pointer valid?) then (yes)
                         #orange: copy Precondition name
                         <b> HEADCopyString </b> >
                         :set preconditon Output date to Default value;
                         Else (no)
                         :set the local error as GDB_ERROR_POINTER_NULL;
                         Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error or NULL pointer error.

  @param[in]            strModuleName : Pointer to Precondition name
  @param[out]           pPreCond : Pointer to Precondition output Data


  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n
                        @ref HEAD_CFG_PRECONDITION

  @pre                  [None]
  @post                 [None]

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*****************************************************************************************************************************/
eGDBError_t HEADDGSMCreatePreCond(const uint8 *strModuleName, HEADPreCond_t *pPreCond)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  if (pPreCond == NULL)
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
      locError = HEADCopyString(pPreCond->strPreCondName, strModuleName, HEAD_MODULENAME_LENGTH);
      pPreCond->uiHypInCondGroup = 0u;
      pPreCond->PreCondStatus = b_FALSE;
  }
  return locError;
}

#endif
/****************************************************************************************************************************
  Functionname:         HEADGetCurrQoSMap                                                                               */ /*!

  @brief                Find the suitable QoSMap table for the current QoS of the module 

  @description          Find the suitable QoSMap table for the current QoS of the module QoSMap table contains all the 
                        transitions in order based on priority with default transition 
                        Indicate error if the suitable QoSMap table is not found
                        @startuml
                        Start
                        :Set local error as None;
                        While ((Loop through all valid QoS states assigned to the module?)AND(QoS of the Module not found?)) is (QoS state valid)
                          If ((Is current iteration QoS state == Module Qos state)) then (yes)
                            :set Qos found flag as True;
                            :Fetch the corresponding QoS mapping table for current QoS; 
                          Endif
                        End while (QoS state not valid)
                        If ((Is Qos found flag == False)) then (yes)
                          :Set error of type unknown;
                          Note:QoS of the module is not found
                        Endif 
                        :return QoS mapping list;
                        Stop
                        @enduml

  @return               HEADSPMQoSMap_t : pointer to QoS mapping table for current QoS of the module

  @param[in]            pModule : Pointer to a Module
  @param[in]            pState : Pointer to a Module state
  @param[out]           retValue : pointer to GDBError (GDB_ERROR_NONE is returned if QoS of the module is found , 
                                   else return Error of type unknown)

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
static HEADSPMQoSMap_t * HEADGetCurrQoSMap(HEADModule_t *pModule, HEADModuleState_t *pState, eGDBError_t *retValue)
{
  uint8 uiIndex;
  HEADSPMQoSMap_t * pSPMQoSMap = NULL;
  boolean bQoSFound = b_FALSE;

  *retValue = GDB_ERROR_NONE;

  for(uiIndex = 0; (uiIndex < pModule->uiNumQoSStates)&&(bQoSFound == b_FALSE); uiIndex++)
  {   
    /* NULL pointer check is done in autocode function "HEADDGSMCreateTypicalState" for pSPMQoSMap */
    if(pState->pSPMQoSMap[uiIndex].uiQoSNr == (uint8)pModule->eQoS)   /*PRQA S 0491*//*array of known length*/
    {
      bQoSFound       = b_TRUE;
      pSPMQoSMap      = &pState->pSPMQoSMap[uiIndex];
    }
  }

  /* error */
  if(bQoSFound == b_FALSE)
  {
    *retValue = GDB_ERROR_UNKNOWN_TYPE;
  }
  
  return pSPMQoSMap;
}



/****************************************************************************************************************************
  Functionname:         HEADDGSMEvalParamSubGroup                                                                       */ /*!

  @brief                This function evaluates the sub group conditions here

  @description          This function evaluates the sub group conditions here
                        @startuml 
                        Start
                        :Set local error as None;
                        If ((Is parameter exist?)) then (yes)
                          If ((Is parameter out type is 
                        other module state time?)) then (yes)
                            #orange:Evaluate other module in state
                            <b>HEADGSMEvaluateOtherModuleInState</b> >
                          Else if ((Is parameter out type is
                        All Conditions For OrGroup met?)) then (yes)
                            : Set local error as None;
                            Note
                          Do Nothing,Update the threshold only if all relevant conditions of hypothesis are true
                          End note

                          Else if ((Is parameter out type is
                        Other Condition Groups?)) then (yes)
                            partition #LightBlue **(HEAD_AUTO_CFG_NO_OCG>0)** {
                              #orange:Evaluate other condition groups check
                              <b>HEADDGSMCheckOtherCondGroups</b> >
                            }
                          Else if ((Is parameter out type is
                        Other orGroup is True?)) then (yes)
                            partition #LightBlue **(0)** {
                              #orange:Evaluate other orGroup check
                              <b>HEADGSMCheckOtherOrGroup</b> >
                            }
                          Else if ((Is parameter out type is Bool?)) then (yes)
                            If ((Is value is greater then bool border?)) then (yes)
                              :set result as True;
                            Else (no)
                              :set result as False;
                            Endif
                          Endif
                          If ((Is parameter out type is
                        OrGroup Inhibition?)) then (yes)
                            If ((Is pointer to hypothesis valid?)) then (yes)
                              #orange:Get InhibitionMask according to the Coding
                              <b>HEADInhibitionCheck</b> >
                              If (((Is param value)AND(Inhibition Mask)== 0)) then (yes)
                                :set result as True;
                              Else (no)
                                :set result as False;
                              Endif
                            Else (no)
                              :set NULL pointer error;
                            Endif
                            Else if ((Is parameter out type is
                        EBAStateControl)) then (yes)
                            If ((Is pointer to hypothesis valid?)) then (yes)
                              #orange:Check the EBA State control according to the coding
                              <b>HEADEBAStateControlCheck</b> >
                              If (((Is parameter Value)AND(EBA State Control))!=0) then (yes)
                                :set result as False;
                              Else (no)
                                :set result as True;
                              Endif
                          Else if ((Is parameter out type is
                        Sensor Source)) then (yes)
                            If ((Is pointer to hypothesis valid?)) then (yes)
                              partition #LightBlue **(FCT_HYPOTHESIS_INTFVER>0x14)** {
                              If (((Is parameter sensor source)==(hypothesis sensor source))) then (yes)
                                :set result as True;
                              Else (no)
                                :set result as False;
                              Endif
                              }
                            Endif
                            If ((Is pointer to hypothesis valid?)) then (yes)
                              partition #LightBlue **(NOT(FCT_HYPOTHESIS_INTFVER>0x14))** {
                              :set result as True;
                              }
                            Endif 
                          Else if ((other parameter out type)) then (yes)
                            #orange:Evaluate general parameter conditions
                            <b>HEADGSMEvaluateGeneralParameters</b> >
                          Else (type is not specified)
                            :set error type unknown;
                          Endif
                        Endif
                        :Return local error;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else return an error code.

  @param[in]            pModule : pointer to a HEAD Module
  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            eParamExists : Boolean indicates parameter exist(True) or not(False)
  @param[in]            eOutType : Parameter Output Type
  @param[in,out]        sParamValThisModuleActive : Module Active Param Value
  @param[in]            sParamValOCG : Other Condition Groups paramter pointer
  @param[in]            sParamValGeneral : Pointer to General Param value
  @param[in]            sParamValOMIS : Pointer to Other Module in State param value
  @param[in]            uiOperator : operator Used in the Parameter
  @param[out]           pIntermediateResult : Parameter evaluation Result
  @param[in]            pHyp : Pointer to CD Hypothesis

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref HEAD_AUTO_CFG_NO_OCG \n
                        @ref FCT_HYPOTHESIS_INTFVER
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                         @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1137-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
****************************************************************************************************************************/
static eGDBError_t HEADDGSMEvalParamSubGroup(HEADModule_t *pModule, const struct HEADInputData_t *pInputData, eHEADSpecialBool_t eParamExists, 
                                            eHEADParamOutType_t eOutType,
                                            #if (HEAD_AUTO_CFG_NO_OCG > 0)
                                            const HEADOtherCondGrpsCheck_t *sParamValOCG, 
                                            #endif
                                            const HEADGSMParamValues_t *sParamValGeneral, 
                                            HEADOtherModuleInState_t *sParamValOMIS, uint8 uiOperator, eHEADSpecialBool_t *pIntermediateResult,
                                            HEADHypothesis_t const *pHyp, const uint8 uiHypNo, uint8 PreCondNr)
{
  eGDBError_t locError = GDB_ERROR_NONE;

  if(eParamExists == HEADSpecialBool_True)
  {
    switch(eOutType)
    {
    case HEADParamOutType_OtherModuleStateTime:
      {
        /*go for timing parameters / conditions*/
        locError = HEADGSMEvaluateOtherModuleInState(pIntermediateResult, pInputData, sParamValOMIS);
      }
      break;

    case HEADParamOutType_AllConditionsForOrGroupMet:
      {
        /*Update the threshold only if all revelevant conditions are true*/
        locError = GDB_ERROR_NONE;
      }
      break;
    #if (HEAD_AUTO_CFG_NO_OCG > 0)
    case HEADParamOutType_OtherCondGroups:
      {
        locError = HEADDGSMCheckOtherCondGroups(pIntermediateResult, pInputData, pModule, sParamValOCG);
      }
      break;
    #endif
    #if 0
    case HEADParamOutType_OtherOrGroupIsTrue  :
      locError = HEADGSMCheckOtherOrGroup(pIntermediateResult, pModule, &sParamValGeneral, eState);
      break;
    #endif
    case HEADParamOutType_Bool                :
      if(sParamValGeneral->fVal> BOOL_BORDER)
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
          if( (sParamValGeneral->uiBitPack & (MEDIC_e_GetHypInhibitionMask(pHyp) | bfInhibition) ) == 0u)
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
    #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    case HEADParamOutType_EBAStateControl   :
    {
      if (pHyp != NULL)
      {
        HEADBitField_t EBAStatectr = 0u;
        locError = HEADEBAStateControlCheck(pHyp,&EBAStatectr);
        if ((sParamValGeneral->uiBitPack & EBAStatectr) != 0u)
        {
          *pIntermediateResult = HEADSpecialBool_False;
        }
        else
        {
          *pIntermediateResult = HEADSpecialBool_True;
        }
      }
      else
      {
        locError = GDB_ERROR_POINTER_NULL;
      }
    }
    break;
    #endif
    
    #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    case HEADParamOutType_SafetyFunctionEnableFlag:
    {
      if (pHyp != NULL)
      {
        if (((sParamValGeneral->uiBitPack) & (uint16)(MEDIC_u_GetSafteyFunctionEnableFlag(pHyp))) != 0u)
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
        locError = GDB_ERROR_POINTER_NULL;
      }
    }
    break;
    #endif

    #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    case HEADParamOutType_SafetyFunctionKeepFlag:
    {
      if (pHyp != NULL)
      {
        if (((sParamValGeneral->uiBitPack) & (uint16)(MEDIC_u_GetSafteyFunctionKeepFlag(pHyp))) != 0u)
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
        locError = GDB_ERROR_POINTER_NULL;
      }
    }
    break;
    #endif

    case HEADParamOutType_SensorSource:
      #if ((FCT_HYPOTHESIS_INTFVER > 0x14) || (MEDIC_ARCHITECTURE_VERSION >= 0x10))
      if (pHyp != NULL)
      {
        uint16 ParamSelecedSensors = (sParamValGeneral->uiBitPack & HEADSensorSourceMask);
        uint16 SensorCheckType = HEADGetBitsSensorCheckType((sParamValGeneral->uiBitPack));

        switch (SensorCheckType)
        {
        case (uint16)(HEADSensorCheckType_Exact):
          *pIntermediateResult = ((ParamSelecedSensors == MEDIC_e_GetHypSensorSource(pHyp)) ? HEADSpecialBool_True : HEADSpecialBool_False);               //Exact to the selected
          break;
        case (uint16)HEADSensorCheckType_AtLeast:
          *pIntermediateResult = ((ParamSelecedSensors == (ParamSelecedSensors & MEDIC_e_GetHypSensorSource(pHyp))) ? HEADSpecialBool_True : HEADSpecialBool_False);   //At least selected
          break;
        case (uint16)HEADSensorCheckType_OR:
          *pIntermediateResult = (((ParamSelecedSensors & MEDIC_e_GetHypSensorSource(pHyp)) != 0u) ? HEADSpecialBool_True : HEADSpecialBool_False);                 // Any of the selected
          break;
        default:
          *pIntermediateResult = HEADSpecialBool_False;
          break;
        }
      }
      #else
      if(pHyp != NULL)
      {
        *pIntermediateResult = HEADSpecialBool_False;
      }
      #endif
      break;
    #if HEAD_CFG_PRECONDITION == MEDIC_ON
    case HEADParamOutType_Precondition:
        locError = HEADGSMCheckPreCond(pIntermediateResult, pInputData, sParamValGeneral->uiBitPack, (uint8)pModule->eModuleNr, uiHypNo);
        break;
    #endif
    case HEADParamOutType_ObjListConfig:
      {
        if(sParamValGeneral->uiBitPack == HEADSystemConfig.uiHEADRadCamFusOrRadOnly)
        {
          *pIntermediateResult = HEADSpecialBool_True;
        }
        else
        {
          *pIntermediateResult = HEADSpecialBool_False;
        }
      }
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
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    case HEADParamOutType_TTB_PRE             :
    case HEADParamOutType_TTB_ACUTE           :
    #else
    case HEADParamOutType_TTB                 :
    #endif
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
    case HEADParamOutType_CustomPar_08_HypIndependent   :
    case HEADParamOutType_CustomPar_09_HypIndependent   :
    case HEADParamOutType_CustomPar_10_HypIndependent   :
    case HEADParamOutType_CustomPar_11_HypIndependent   :
    case HEADParamOutType_CustomPar_00_HypDependent     :
    case HEADParamOutType_CustomPar_01_HypDependent     :
    case HEADParamOutType_CustomPar_02_HypDependent     :
    case HEADParamOutType_CustomPar_03_HypDependent     :
    case HEADParamOutType_CustomPar_04_HypDependent     :
    case HEADParamOutType_CustomPar_05_HypDependent     :
    case HEADParamOutType_CustomPar_06_HypDependent     :
    case HEADParamOutType_CustomPar_07_HypDependent     :
    case HEADParamOutType_CustomPar_08_HypDependent     :
    case HEADParamOutType_CustomPar_09_HypDependent     :
    case HEADParamOutType_CustomPar_10_HypDependent     :
    case HEADParamOutType_CustomPar_11_HypDependent     :
    #if HEAD_CFG_TURN_ASSIST
    case HEADParamOutType_SteeringAngle                   :
    case HEADParamOutType_TurnIndicatorInSteeringDirection:
    case HEADParamOutType_GasPedal                        :
    case HEADParamOutType_CorridorStopDistance            :
    #endif
    case HEADParamOutType_TargetVelocity:
    case HEADParamOutType_TargetAngle:
    case HEADParamOutType_ShortestDistance:
    case HEADParamOutType_ObjectSpeed:
    #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    case HEADParamOutType_ItemConfidence                  :
    case HEADParamOutType_Inlap                           :
    case HEADParamOutType_ImpactVelEgo                    :
    case HEADParamOutType_ImpactVelRel                    :
    #endif
      {
        /*general parameters/conditions*/
        locError = HEADGSMEvaluateGeneralParameters( pIntermediateResult, sParamValGeneral, uiOperator, (uint8)pModule->eModuleNr, pInputData, pHyp, uiHypNo, eOutType);
      }
      break;        
    default:
      /*type is not specified*/
      locError = GDB_ERROR_UNKNOWN_TYPE;
      break;
    }
  } 
  _PARAM_UNUSED(PreCondNr);/*PRQA S 3119 *//* Date: 2018-12-17, Reviewer: Sadhanashree Srinivasa, Reason:  This statement has no side-effect */
  return locError;
} /* PRQA S 7004, 7007 *//* date: 2020-10-21, reviewer:Siri Prakash, reason: suppressing cyclomatic complexity for better code maintainability */

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* MEDIC_CFG_HEAD20 */ 

/*PRQA S 7013 *//* Date: 2018-12-17, Reviewer: Pronnoy Chowdhury, Reason:  suppressed number of executable lines per file. */
