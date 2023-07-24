/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_generic_sm.h

DESCRIPTION:               Header for the generic state machine of the HEAD module

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/08/27 12:00:28CEST $

VERSION:                   $Revision: 1.16 $

LEGACY VERSION:            1.15.1.1 (HEAD 2.0)

**************************************************************************** */

#ifndef HEAD20_GENERIC_SM_H_INCLUDED
#define HEAD20_GENERIC_SM_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*****************************************************************************
  INCLUDES
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/
/*! @brief       Mask to extract the Sensor Source check type  */
#define HEADSensorCheckTypeMask         (0xC000)

/*! @brief       Mask to extract the Sensor Source Selected  */
#define HEADSensorSourceMask            (0x3FFFu)

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalGSM_t
    **************************************************************** */
/*! @brief HEAD Module Internal GSM Information

    @general specific ModuleInternal information (gsm) --> derived from HEADModuleInternalInterface_t
    
    @conseq [None]

    @attention [None]

    */
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
typedef struct /*PRQA S 0635 16*/ /*QAC message suppressed*/
{
  HEADModuleInternalHeader_t       InternalHeader;                /*!< type header - must be the first element in the struct*/  

  HEADParamCondGrpTimerList_t      ParamCondGrpTimerList;         /*!< timers list for a module to evaluate conditions with OutType(HEADParamOutType_OtherCondGroups)*/         

  /*GSM specific*/
  uint32                            bitOutTypeCheckOK;            /*!< stores a 0-bit for every @ref:eHEADParamOutType_t if the check was not ok*/
  boolean                           bInitialized;                 /*!< is module initialized*/
  HEADAdditionalTableInputValues_t  sAdditionalTableInputs;       /*!< additional inputs for table(x) values that are not provided as input data directly*/
  uint32                            ObjClassSelection   : 5;      /*!< modules can handle specified objects by coding */
  uint32                            DynamicProperty     : 3;      /*!< modules can handle specified dynproperty by coding*/
  uint32                            ObjMovDir           : 3;      /*!< modules can handle objects moving in specified direction by coding \n
                                                                       @range[EBAObjMovDir_DoT 0U, EBAObjMovDir_Cross 1U, EBAObjMovDir_Onco 2U] */
  uint32                            Pad1                : 5;
} HEADModuleInternalGSM_t;
#else
typedef struct /*PRQA S 0635 16*/ /*QAC message suppressed*/
{
  HEADModuleInternalHeader_t InternalHeader;                      /*!< type header - must be the first element in the struct*/

  HEADParamCondGrpTimerList_t      ParamCondGrpTimerList;        /*!< timers list for a module to evaluate conditions with OutType(HEADParamOutType_OtherCondGroups)*/

  /*GSM specific*/
  uint32                           bitOutTypeCheckOK;            /*!< stores a 0-bit for every @ref:eHEADParamOutType_t if the check was not ok*/
  boolean                          bInitialized;                 /*!< is module initialized*/
  HEADAdditionalTableInputValues_t sAdditionalTableInputs;       /*!< additional inputs for table(x) values that are not provided as input data directly*/
  uint8                            ObjClassSelection   : 5;      /*!< modules can handle specified objects by coding */
  uint8                            DynamicProperty     : 3;      /*!< modules can handle specified dynproperty by coding*/
  uint8                            ObjMovDir           : 3;                 /*!< modules can handle objects moving in specified direction by coding \n
                                                                                @range[EBAObjMovDir_DoT 0U, EBAObjMovDir_Cross 1U, EBAObjMovDir_Onco 2U] */
  uint8                            Pad1                : 5;
} HEADModuleInternalGSM_t;

#endif
/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalGSMMTS_t
    **************************************************************** */
/*! @brief HEAD Module Internal GSM Information for MTS

    @general HEAD Module Internal GSM Information for MTS

    @conseq [None]

    @attention [None]

    */
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
typedef struct 
{
  uint32                           uiModuleNr;                     /*!< refers to the modulenr*/
  uint32                           objClassSelection;              /*!< Object Class Selection */
  uint32                           DynamicProperty;                /*!< Dynamic Property */
  uint32                           objMovDir;                      /*!< Object Direction */
  boolean                          bInitialized;                   /*!< Initialized */
  uint32                           dummy1;                         /*!< dummy 1 */
  HEADAdditionalTableInputValues_t sAddInputs;                     /*!< additional inputs */
} HEADModuleInternalGSMMTS_t;
#else

typedef struct
{
  uint8                 uiModuleNr;                   /*!< refers to the modulenr*/
  uint8                 objClassSelection;              /*!< Object Class Selection */
  uint8                 DynamicProperty;                /*!< Dynamic Property */
  uint8                 objMovDir;                      /*!< Object Direction */
  boolean               bInitialized;                   /*!< Initialized */
  uint8                 dummy1;                       /*!< dummy 1 */
  HEADAdditionalTableInputValues_t sAddInputs;        /*!< additional inputs */
} HEADModuleInternalGSMMTS_t;

#endif
/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask);
eGDBError_t HEADEBAStateControlCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *EBAStatectr);
extern void HEADDoStateTransition( eHEADSMState_t eNewState,
                            const struct HEADInputData_t * pInputData, 
                            HEADModule_t * pModule, 
                            eGDBError_t *retValue );

extern eGDBError_t HEADDGSMCreateConditionGroup(HEADConditionGrp_t *pConditionGrp, HEADParameterEmpty_t *pTransitionParameters);

extern eGDBError_t HEADDGSMCreateStateTransition(eHEADSMState_t eNextState, HEADStateTransition_t *pTransition, HEADConditionGrp_t *pConditionGroupList,
                                         uint16 * puHypInCondGroup, const uint8 uiNumCondGroups, HEADCondGrpBitField_t uiCondGrpHypLogic);

extern eGDBError_t HEADDGSMCreateTypicalState(HEADModuleState_t *pState, HEADStateTransition_t *pStateTransitionList,
                                       uint8 uiNumTransitions, boolean bActiveState, HEADSPMQoSMap_t * pSPMQoSMap,
                                       const void* pStateOutputParams);

extern eGDBError_t HEADDGSMCreateTypicalModule(const uint8 *strModuleName, eHEADDGSM_Module_t eModuleNr, HEADModule_t *pModule, 
                                               HEADModuleInternalGSM_t *pModuleInt, HEADParamCondGrpTimer_t *pCondGrpTimer, uint8 uiNumCondGrpTimers,
                                               HEADModuleState_t *pModuleStateList, struct HEADModuleOutputInterface_t *pModuleOutput, uint8 uiNumQoSStates,
                                               uint8 uiNumModuleStates, eHEADSMState_t eModuleStateMin);

#if HEAD_CFG_PRECONDITION == MEDIC_ON
extern eGDBError_t HEADDGSMCreatePreCond(const uint8 *strModuleName, HEADPreCond_t *pPreCond);
extern eGDBError_t HEADEvaluatePreCond(const HEADInputData_t *pInputData);
#endif
#endif  /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_GENERIC_SM_H_INCLUDED */

