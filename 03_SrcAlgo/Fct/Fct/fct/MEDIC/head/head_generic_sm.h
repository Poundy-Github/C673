/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_generic_sm.h

DESCRIPTION:               Header for the generic state machine of the HEAD module

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/07/03 14:58:38CEST $

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            1.17

**************************************************************************** */
/**
@ingroup head_generic_sm
@{ **/
#ifndef HEAD_GENERIC_SM_H_INCLUDED
#define HEAD_GENERIC_SM_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalGSM_t
    **************************************************************** */
/*! @brief          HEAD Module Internal GSM Information

    @description    specific ModuleInternal information (gsm) --> derived from HEADModuleInternalInterface_t
    */
/*PRQA S 0635 16 *//*(Reviewer Nalina M : Supressing QAC Helix message)*/
typedef struct /*PRQA S 0635 15 #date: 2020-06-02, reviewer: Nalina M, reason: Supressing QAC Helix message*/
{
  HEADModuleInternalHeader_t InternalHeader;                                /*!< HEAD Module Internal State Machine Type and Function Handler - must be the first element in the struct*/  
  /*GSM specific*/
  HEADParameterEmpty_t             *pParameterList;                         /*!< defines the module parameter list (can be NULL)*/
  float32                          *pfConditionsOKTimer;                    /*!< counts the seconds how long the module would fulfill all parameter criteria*/
  uint32                           bitOutTypeCheckOK;                       /*!< stores a 0-bit for every @ref:eHEADParamOutType_t if the check was not ok*/
  boolean                          bInitialized;                            /*!< is module initialized*/
  HEADAdditionalTableInputValues_t sAdditionalTableInputs;                  /*!< additional inputs for table(x) values that are not provided as input data directly*/
  const HEADParameterEmpty_t       *pRootPointerList[HEADParamOperator_DEFAULT][HEADParamOutType_Max];  /*!< HEAD Module Pointer List */
  uint8                            ObjClassSelection   : 5;                 /*!< modules can handle specified objects by coding \n
                                                                                @range[EBAObjectClass_NotAvail 0U, EBAObjectClass_Pedestrian 1U, EBAObjectClass_Vehicle 2U, EBAObjectClass_Obstacle 3U, EBAObjectClass_Cyclist 4U */
  uint8                            DynamicProperty     : 3;                 /*!< modules can handle specified dynproperty by coding \n
                                                                                @range[EBADynProp_NotAvail 0U, EBADynProp_Mov 1U, EBADynProp_Stat 2U] */
} HEADModuleInternalGSM_t;


/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalGSMMTS_t
    **************************************************************** */
/*! @brief          HEAD Module Internal GSM Information for MTS
    */
typedef struct 
{
  uint8                 uiModuleNr;                     /*!< refers to the modulenr */
  uint8                 objClassSelection;              /*!< Object Class Selection */
  uint8                 DynamicProperty;                /*!< Dynamic Property */
  boolean               bInitialized;                   /*!< is module initialized */
  uint8                 dummy1;                         /*!< dummy 1 */
  HEADAdditionalTableInputValues_t sAddInputs;          /*!< additional inputs for table(x) values that are not provided as input data directly */
} HEADModuleInternalGSMMTS_t;


/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADGSMCreateTypicalModule(const uint8 *strModuleName, struct HEADModule_t *pModule, 
                                              HEADModuleInternalGSM_t *pModuleInt, 
                                              HEADParameterEmpty_t *pModuleParameters, 
                                              struct HEADModuleOutputInterface_t *pModuleOutput, 
                                              const void* pModuleOutputParams,
                                              float32 *pfConditionsOKTimer, const uint8 uiNumOrGroups);
extern eGDBError_t HEADInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask);
extern void HEADDoStateTransition( eHEADSMState_t eNewState,
                                  const struct HEADInputData_t * pInputData, 
                                  HEADModule_t * pModule, 
                                  eGDBError_t *retValue );

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* HEAD_GENERIC_SM_H_INCLUDED */
/**@}*/

