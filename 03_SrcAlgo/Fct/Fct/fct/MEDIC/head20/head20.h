/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20.h

DESCRIPTION:               Internal Header of the HEAD component

AUTHOR:                    $Author: H U, Minuthi (uia80216) (uia80216) $

CREATION DATE:             $Date: 2020/08/27 09:06:37CEST $

VERSION:                   $Revision: 1.35 $

LEGACY VERSION:            1.56.1.1 (HEAD 2.0)

**************************************************************************** */

#ifndef HEAD20_H_INCLUDED
#define HEAD20_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief          OBJCLASS_INIT
    @description    This macro defines the init value for ObjClassSelection
                    @typical 0x1F, @unit [-]
 */
#define OBJCLASS_INIT         0x1F

/*! @brief          DYNAMICPROPERTY_INIT
    @description    This macro defines the init value for DynamicProperty
                    @typical 0x7, @unit [-]
 */
#define DYNAMICPROPERTY_INIT  0x7

/*! @brief          OBJDIR_INIT
    @description    This macro defines the init value for Object direction
                    @typical 0x7, @unit [-]
 */
#define OBJDIR_INIT           0x7

/*! @brief       HEADTimeScale
    @general     fixed point scaling for timers , 1000 means 1s is displayed as 1000s and maximum value is 65.5s
 */
#define HEADTimeScale        (1000u)                     

/*! @brief       Maximum value of Timer
    @general     Maximum value of Timer */
#define HEADTimeMax          (65000u)                   

/* Define signal input state values */

/*! @brief       HEAD Input Signal State - OK
    @general     HEAD Input Signal State OK */
#define HEADInputSignalState_OK           ((HEADInputSignalState_t) eHEADInputSignalState_OK)

/*! @brief       HEAD Input Signal State - Default */
#define HEADInputSignalState_Default      ((HEADInputSignalState_t) eHEADInputSignalState_Default)

/*! @brief       HEAD Input Signal State - Missing */
#define HEADInputSignalState_Missing      ((HEADInputSignalState_t) eHEADInputSignalState_Missing)

/*! @brief       HEAD Input Signal State - BadQuality */
#define HEADInputSignalState_BadQuality   ((HEADInputSignalState_t) eHEADInputSignalState_BadQuality)

/*! @brief       HEAD Input Signal State - Suspicious */
#define HEADInputSignalState_Suspicious   ((HEADInputSignalState_t) eHEADInputSignalState_Suspicious)

/*! @brief       HEAD Input Signal State - Max */
#define HEADInputSignalState_Max          ((HEADInputSignalState_t) eHEADInputSignalState_Max)

/* Define signal input type values */

/*! @brief       HEAD Input Signal Type - Float */
#define HEADInputSignalType_Float         ((HEADInputSignalType_t) eHEADInputSignalType_Float)

/*! @brief       HEAD Input Signal Type - SignedInt */
#define HEADInputSignalType_SignedInt     ((HEADInputSignalType_t) eHEADInputSignalType_SignedInt)

/*! @brief       HEAD Input Signal Type - UnsignedInt */
#define HEADInputSignalType_UnsignedInt   ((HEADInputSignalType_t) eHEADInputSignalType_UnsignedInt)

/*! @brief       HEAD Input Signal Type - Bool */
#define HEADInputSignalType_Bool          ((HEADInputSignalType_t) eHEADInputSignalType_Bool)

/*! @brief       HEAD Input Signal Type - Max */
#define HEADInputSignalType_Max           ((HEADInputSignalType_t) eHEADInputSignalType_Max)

/*! @brief       MAX NUMBER OF DIM Hypothesis
    @general     MAX NUMBER OF DIM Hypothesis */
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
#define HEAD_MAX_NUMBER_OF_DM_HYPS (DIM_NR_OF_EBA_HYPOTHESES)
#else
#define HEAD_MAX_NUMBER_OF_DM_HYPS (0u)
#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */


/*! Maximum time value as calculation result */

/*! @brief       HEAD TTX MAX Value
    @general     HEAD TTX MAX Value */
#define HEAD_TTX_MAX               (40.0f)

/*! @brief       BOOL FLOAT TRUE
    @general     BOOL FLOAT TRUE */
#define BOOL_FLOAT_TRUE            (1.0f)

/*! @brief       BOOL BORDER
    @general     BOOL BORDER */
#define BOOL_BORDER                (0.5f)

/*! @brief       BOOL FLOAT FALSE
    @general     BOOL FLOAT FALSE  */
#define BOOL_FLOAT_FALSE            (0.0f)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief       Get InputValue's Standard Deviation */
#define HEADGetInputStdDev(inputValue) ((inputValue).fStdDev)

#if (MEDIC_CFG_EBA_HEAD_IGNR_SFTY_CHECK)
/* Throw a warning message */
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning : Ignoring the safety distance check is enabled in code. Make sure this is only done for Test-Builds.")
/* Trigger a QAC critical warning DONT USE the Macro */
#define DUMMY_MACRO_WARNING_HEAD_IGNR_SFTY_CHECK_IS_ON(a,b)   #a #b
#endif
/* PRQA S 3480,3219 EOF */ /* date: 2019-09-24, reviewer: Sekar, Balaji, reason:If the function righ to && is not called also no side effects */
/* PRQA S 0616,1055,3238 EOF */ /* date: 20-11-2019, uic42639, cannot get rid of algo inlines and hence suppressed */
/* PRQA S 1891 EOF */ /* date: 2020-04-27, reviewer: Nalina M, reason: Suppressing, because of no side effects */
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ================ HEAD INPUT ========================*/

/* ================== HYPOTHESIS =========================*/

/* ------------- ABSTRACT HYPOTHESIS definition --------- */
/*!
   HEAD_HYPOTHESIS_ARRAY               CD_HYPOTHESIS_ARRAY (from CD)
   -------------------------           ---------------------
   | TYPE KIN, POINTER   <-|-----------| KIN HYPO 1        |
   |-----------------------|           |-------------------|
   | TYPE KIN, POINTER   <-|-----------| KIN HYPO 2        |
   |-----------------------|           |-------------------|
   | TYPE KIN, POINTER   <-|-----------| KIN HYPO 3        |
   |-----------------------|           |-------------------|
   | TYPE KIN, POINTER   <-|-----------| KIN HYPO 4        |
   |-----------------------|           |-------------------|
   | TYPE KIN, POINTER   <-|-----------| KIN HYPO 5        |
   |-----------------------|           |-------------------|
   | TYPE KIN, POINTER   <-|-----------| KIN HYPO 6        |
   |-----------------------|           ---------------------



   | TYPE DRV, POINTER   <-|-----
   |-----------------------|     \     DRIVER_INTENTION_HYP_ARRAY (from DIM)
   | TYPE DRV, POINTER   <-|---   \    ---------------------
   |-----------------------|   \   ----| DRV HYPO 0        |
   | TYPE DRV, POINTER   <-|-   \      |-------------------|
   ------------------------- \   ------| DRV HYPO 1        |
                              \        |-------------------|
                               --------| DRV HYPO 2        |
                                       ---------------------

*/

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */

/* -------- main input data ----------*/

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Enum for HEAD Input Signal States
*/
typedef enum 
{
  eHEADInputSignalState_OK,                         /*!<input value is ok*/
  eHEADInputSignalState_Default,                    /*!<input value has a default value*/
  eHEADInputSignalState_Missing,                    /*!<input value is missing*/
  eHEADInputSignalState_BadQuality,                 /*!<input value has a bad quality*/
  eHEADInputSignalState_Suspicious,                 /*!<input value looks suspicious*/
  eHEADInputSignalState_Max                         /*!<MAX input value*/
} eHEADInputSignalState_t;
typedef uint8 HEADInputSignalState_t;               /*!< @values: eHEADInputSignalState_t */

/*! @brief Enum for HEAD Input Signal Type
 */
typedef enum 
{
  eHEADInputSignalType_Float,                       /*!<value type is a float*/
  eHEADInputSignalType_SignedInt,                   /*!<value type is a signed int*/
  eHEADInputSignalType_UnsignedInt,                 /*!<value type is a unsigned int*/
  eHEADInputSignalType_Bool,                        /*!<value type is a bool*/
  eHEADInputSignalType_Max                          /*!<MAX input value*/
} eHEADInputSignalType_t;
typedef uint8 HEADInputSignalType_t;                /*!< @values: eHEADInputSignalType_t */

/*! @brief Enum for HEAD Brake Cascade 
    */
typedef enum
{
  HEADBrakeCascade_1,
  HEADBrakeCascade_2,
  HEADBrakeCascade_3,
  HEADBrakeCascade_4,
  eHEADBrakeCascade_Max
} eHEADBrakeCascade_t;

/*! @brief Possible head input signal value storage
 */
typedef union
{
  float32 fValue; /*!< To store float value*/ /*PRQA S 3629*//*access with get and set functions*/
  sint32 iValue;  /*!< To store int value*/ 
  uint32 uiValue; /*!< To store unsigned int value*/ 
  uint32 bValue;  /*!< To store bool value*/
} uHEADInputValueUnion_t;


/*! @brief Standard type for HEAD input signals
    @general Stores signal quality, it's type, quality and Standard Deviation 
 */
typedef struct HEADInputValue_t
{
  HEADInputSignalState_t eSignalQuality;             /*!< signal quality */
  HEADInputSignalType_t  eSignalType;                /*!< signal type */ 
  uHEADInputValueUnion_t uValue;                     /*!< signal value */
  float32                fStdDev;                    /*!< Standard Deviation */
} HEADInputValue_t;


/*! @brief Main HEAD input scalar signal list
 */
typedef struct  
{
  HEADInputValue_t LongVelocity;       /*!< Host vehicle velocity */
  HEADInputValue_t LongAcceleration;   /*!< Host vehicle acceleration */
  HEADInputValue_t YawRate;            /*!< Host vehicle yaw rate */
  HEADInputValue_t DrivingDirection;   /*!< Host vehicle motion direction */
  HEADInputValue_t EgoLatCurvature;    /*!< Host vehicle trajectory curvature */
  HEADInputValue_t CDHypotheses;       /*!< Number of kinematic hypotheses */
  HEADInputValue_t DIMHypotheses;      /*!< Number of DIM hypotheses */
  HEADInputValue_t SafeObjDistSfty;    /*!< Safe object distance safety functions */
  HEADInputValue_t SafeObjDistPerf;    /*!< Safe object distance performance functions */
  HEADInputValue_t StabCtrlState;      /*!< Status of stability control system */
  HEADInputValue_t BrakeChainState;    /*!< Status of brake system */
  HEADInputValue_t WarnChainState;     /*!< Status of warn system */
  HEADInputValue_t PrefillChainState;  /*!< Status of prefill  system */
  HEADInputValue_t HBAChainState;      /*!< Status of hba system */
  HEADInputValue_t DriverFeedback;     /*!< Driver Feedback */
  HEADInputValue_t DriverActivity;     /*!< Driver Activity */
  HEADInputValue_t DriverAttention;    /*!< Driver Attention */
  HEADInputValue_t ObjListSource;      /*!< sensors available */
  HEADInputValue_t ObjListDegraded;    /*!< sensors degraded */
  #if HEAD_CFG_TURN_ASSIST
  HEADInputValue_t SteeringAngle;                       /*!< Steering Angle */
  HEADInputValue_t TurnIndicatorInSteeringDirection;    /*!< Turn Indicator In Steering Direction */
  HEADInputValue_t GasPedal;                            /*!< Gas Pedal */
  #endif /* HEAD_CFG_TURN_ASSIST */
} HEADInputValueList_t;

/* forward declaration of the type...*/
/*!  @cond Doxygen_Suppress */
typedef struct HEADStateTransition_t HEADStateTransition_t;
typedef struct HEADModuleState_t HEADModuleState_t;
/*! @endcond */ 


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEAD condition group list
 */
typedef struct
{
  HEADParameterEmpty_t  *pParameterList;          /*!< pointer to parameter list */ 
  float32  fConditionsOKTimer;                    /*!< counts the seconds how long the condition group would fulfill all parameter criteria */                                                    
  uint32   uDummy1;                               /*!<  Alignment for MTS */
  uint64   uDummy2;                               /*!<  Alignment for MTS */
}HEADConditionGrp_t;

typedef uint8 HeadTransitionPriority_t;

/*Transition Cost Function*/
/*!Transition Cost Function - pTransition defines the corresponding transition */
typedef HeadTransitionPriority_t HEADTransitionCost_ft(const struct HEADStateTransition_t *pTransition);  

/*module output structure interface*/
SET_MEMSEC_VAR(HEADTransitionCostInterface_t)

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEAD transition cost interface structure
 */
struct HEADTransitionCostInterface_t
{
  HEADTransitionCost_ft *fpCustomCostFunction; 
};


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief state transition structure of a module for the dynamic state machine
 */
struct HEADStateTransition_t
{
  /* General Parameters */
  eHEADSMState_t              eDGSMNextState;                              /*!< Next state */ 
  boolean                     bInitialized;                                /*!< are transition variables initialized*/
  /* Parameters specific to a normal transition */
  HEADConditionGrp_t          *pConditionGroupList;                        /*!< List of condition groups for a particular transition */     
  uint8                       uiNumConditionGroups;                        /*!< defines the number of ConditionGroups for this transition*/
  uint16                      *puHypInCondGroup;                           /*!< Pointer to ConditionGroup array with corresponding hypotheses*/
  HEADCondGrpBitField_t       uiCondGrpHypLogic;                           /*!< Hypothesis evaluation logic bits for each condition group 
                                                                                bit = 0 => OR logic; bit = 1 => AND logic*/
  struct HEADTransitionCostInterface_t *pCostFunction;                     /*!< pointer to the custom Cost Function(callback)*/
};/* typedef already forward declared */


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEAD state structure of a module for the dynamic state machine
 */
struct HEADModuleState_t
{
  HEADStateTransition_t   *pStateTransitionList;        /*!< List of Normal transitions. Pointer to transitions array */
  uint8                   uiNumTransitions;             /*!< defines the number of transitions for the current state of the module */
  HEADSPMQoSMap_t         *pSPMQoSMap;                  /*!<  QoS Transition mapping list */ 
  const void              *pOutputParams;               /*!< List of output parameters */
                                                        /*!< pointer to a output parameter structure (is used by the function defined in pOutput) */
  boolean                 bActiveState;                 /*!< Is the module state an active state */
  /*  inState Timer */    
  float32                 fStateTimer;                  /*!< counts the seconds how long the module is in the current state*/
  float32                 fNotInStateTimer;             /*!< counts the seconds how long the module is not in the current state*/
};/* typedef already forward declared */


/*module output*/
/*!module output function - pModule defines the specific module, bInit defines if the output should be initialized or not...*/
typedef eGDBError_t HEADModuleCustomOutput_ft(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit);

/*module output structure interface*/
SET_MEMSEC_VAR(HEADModuleOutputInterface_t)
  /* ****************************************************************
    STRUCT HEADModuleOutputInterface_t
    **************************************************************** */
/*! @brief HEAD Module Output Interface

    @general HEAD Module Output Interface

    @conseq [None]

    @attention [None]

    */
struct HEADModuleOutputInterface_t
{
  HEADModuleCustomOutput_ft *fpCustomOutput; 
};


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEAD new module structure for the dynamic state machine
 */
struct HEADModule_t
{
  /*!@publicsection*/
  uint8                 strModuleName[HEAD_MODULENAME_LENGTH+1u];  /*!< module name*/
  eHEADDGSM_Module_t    eModuleNr;                                 /*!< module number*/
  eHEADModuleQoS_t      eQoS;                                      /*!< defines the QoS for a module*/
  eHEADModuleRepError_t eReportedError;                            /*!< defines the reported error for a module*/
  HEADModuleState_t     *pModuleStateList;                         /*!< module states list */  
  eHEADSMState_t        eDGSMState;                                /*!< global state machine state*/
  eHEADSMState_t        eDGSMLastState;                            /*!< global state machine last state-different from 'eDGSMState'*/
  eHEADSMState_t        eDGSMLastCycleState;                       /*!< global state machine last cycle state*/      
  eHEADSMState_t        eNumModuleStateMin;                        /*!< defines the minimum state number for the current module */ 
  uint8                 uiNumModuleStates;                         /*!< defines the number of states for the current module */
  uint8                 uiNumQoSStates;                            /*!< defines the number of QoS states assigned to the module*/ 
  /* used during GSM conditions evaluation */
  uint8                 uiCurrentTransNr;                          /*!< current transition nr when evaluating the Condition Grp */
  uint8                 uiCurrentCondGrpNr;                        /*!< current condition grp nr in which the Condition are evaluated */
  /*!@privatesection*/
  HEADModuleInternalInterface_t        *pInternal;                 /*!< pointer to internal state information*/
  struct HEADModuleOutputInterface_t   *pOutput;                   /*!< pointer to output interface */
};


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEAD module list for the dynamic state machine
 */
struct HEADModuleList_t  
{
  uint8                 uiNrOfModules;                  /*!< defines the nr of HEAD modules*/
  HEADModule_t          *rgModules;                     /*!< defines pointer to the array of head modules*/
};

#if HEAD_CFG_PRECONDITION == MEDIC_ON

struct HEADPreCond_t  
{
  uint8                 strPreCondName[HEAD_PRECONDNAME_LENGTH+1u];  /*!< PreCond name*/
  HEADConditionGrp_t    rgPreCond;                                   /*!< Precondition */
  uint16                uiHypInCondGroup;                                    /*  */
  boolean               PreCondStatus;                                    /*  */
  uint64                udummy;                                      /*!< 8 byte alignment for MTS */
};
typedef struct HEADPreCond_t HEADPreCond_t;

struct HEADPreConditionList_t  
{
  uint8                 uiNrOfPreConds;                  /*!< defines the nr of Preconditions */
  HEADPreCond_t    *rgPreCondList;               /*!< defines pointer to the array of Preconditions */
};

#endif

/* application callbacks structure */

/*! @brief Application callback for getting values of custom parameters
 */
typedef eGDBError_t HEADCustomGetHypValue_ft(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, float32 *retValue);

/*! @brief Application callback for filtering parameter values */
typedef eGDBError_t HEADCustomFilterHypValue_ft(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, float32 *pInOutValue );

/*! @brief Application callback for getting independent values of custom parameters */
typedef eGDBError_t HEADCustomGetIndValue_ft(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, float32 *pretValue);

/*! @brief Application callback for independent filtering parameter values */
typedef eGDBError_t HEADCustomFilterIndValue_ft(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, uint8 uiModuleNr, float32 *pInOutValue );

/*! @brief Application callback interface */
typedef struct 
{
  HEADCustomGetHypValue_ft * fpCustomGetHypValue;       /*!< Application callback for reading dependent custom parameters */
  HEADCustomFilterHypValue_ft * fpCustomFilterHypValue; /*!< Application callback for filtering parameters */
  HEADCustomGetIndValue_ft* fpCustomGetIndValue;        /*!< Application callback for reading independent custom parameters */
  HEADCustomFilterIndValue_ft* fpCustomFilterIndValue;        /*!< Application callback for filtering independent custom parameters */
} HEADCustomCallbacks_t;



/*! @brief Main HEAD input data structure */
struct HEADInputData_t
{
  uint8                 uiNumberOfHEADHypotheses;      /*!< Number of hypotheses in array*/
  HEADMainMode_t        eHEADMainMode;                 /*!< driver mode */
  eHEADOpMode_t         eOpMode;                       /*!< external operation mode*/ 
  uint32                uiCurrentCycle;                /*!< HEAD Cycle Count*/ 
  float32               fCycleTime;                    /*!< typical cycle time in s*/
  const HEADHypothesisList_t *rgHypothesisList;        /*!< pointer to hypothesis array*/
  HEADInputValueList_t *pInputValueList;               /*!< pointer to input values*/
  HEADModuleList_t     *pModuleList;                   /*!< HEAD module list*/
  #if HEAD_CFG_PRECONDITION == MEDIC_ON
  HEADPreConditionList_t *pPreCondList;
  #endif
  HEADSPMRules_t       *pSPMRules;                     /*!< SPM rules*/
  HEADCustomCallbacks_t CustCallbacks;                 /*!< Application callbacks */
} /* type is already forward declared in head_module_def.h */;


/*! @brief Main HEAD System Config data structure */
typedef struct 
{
  uint16                uiHEADRadCamFusOrRadOnly;      /*!< Radar only or Radar Camera Fusion */
}HEADSystemConfig_t;


/*! @brief logical operation ( Condition ) Group Bit Field */
typedef uint8 HEADConditionGroupBitField_t;

/*! @brief  logical operation ( Condition ) Group Bit Field is assigned to all ones*/
#define HEADConditionGroupBitField_ALL  ((HEADConditionGroupBitField_t)255u)

/*! @brief Get Condition group bit field of the given number */
#define HEADConditionGroupBitField(Number) ((HEADConditionGroupBitField_t)(1u<<(Number)& 0xFFu))

/*! @brief structure to store active and current hypthesis */
typedef struct 
{
  uint16 uiActiveHypos;                                   /*!< Active hypothesis */
  HEADHypothesisNr_t currentHypo;                         /*!< Current hypothesis */
} HEADActiveHypIterator_t;




/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/
extern HEADSystemConfig_t HEADSystemConfig;


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


extern eGDBError_t HEADInititalize(struct HEADInputData_t *pInputData, float32 fCycleTime);
extern eGDBError_t HEADReInit(const struct HEADInputData_t *pInputData, const HEADModuleList_t *pModuleList);

/*!  @cond Doxygen_Suppress */

/* Deactivate QA-C warning 3406; Reviewer: Veerashettappa.Nagaraja; Date: 24.08.2018; 
  ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
  Review-ID: */
  /* PRQA S 3406 ALGO_INLINES */
static ALGO_INLINE boolean HEADActiveHypoIteratorGetNext(HEADActiveHypIterator_t *const pIterator, HEADHypothesisNr_t *const nextActiveHypo);

static ALGO_INLINE void HEADInitActiveHypoIterator(const struct HEADStateTransition_t * const pTransition, const HEADConditionGroupBitField_t uiValidForConditionGroups,
                                                   HEADActiveHypIterator_t *const pIterator);

static ALGO_INLINE boolean HEADIsHypoActiveForModule(const HEADModule_t * const pModule, const HEADHypothesisNr_t uiHypNo);
static ALGO_INLINE boolean HEADIsHypoActiveForCondGroup(const HEADStateTransition_t * const pLastTransition, const HEADHypothesisNr_t uiHypNo, const uint8 uiCondGrpNo);

static ALGO_INLINE HEADStateTransition_t *HEADGetLastTransitionForState(const HEADModuleState_t * const pState, const eHEADSMState_t eCurrentState);

static ALGO_INLINE uint16 HEADGetActiveHypothesisForTransition(const HEADStateTransition_t * const pTransition);
static ALGO_INLINE uint16 HEADGetActiveHypothesisForConditionGroup(const HEADStateTransition_t * const pTransition ,const uint8 uiConditionGroupNo);
static ALGO_INLINE HEADHypothesisNr_t HEADGetMostCritHypOfBitfieldForState( const struct HEADInputData_t * const pInputData, const uint16 uiActHypField, 
                                                                     const HEADHypothesis_t** const ppCurrCDHypo, const boolean bUseDecel);
static ALGO_INLINE uint16 HEADGetActiveHyposForConditionGroupBitField(const HEADStateTransition_t * const pTransition, const HEADConditionGroupBitField_t uiValidForConditionGroup);

static ALGO_INLINE const HEADHypothesis_t *HEADGetHypothesis(const HEADHypothesisList_t *const pHypList, const HEADHypothesisNr_t uiHypNo);

static ALGO_INLINE HEADModule_t *HEADGetModule(const HEADModuleList_t *const pModulelist, const uint32 uiModuleNo);
static ALGO_INLINE HEADModuleState_t *HEADGetModuleState(const HEADModule_t *const pModule, const uint32 uiStateNo);
static ALGO_INLINE HEADModuleState_t *HEADGetActiveModuleState(const HEADModule_t *const pModule);
static ALGO_INLINE HEADStateTransition_t *HEADGetStateTransition(const HEADModuleState_t *const pState, const uint32 uiTransitionNo);
static ALGO_INLINE HEADConditionGrp_t *HEADGetConditionGrp(const HEADStateTransition_t *const pTransition, const uint8 uiConditionGrpNo);
#if HEAD_CFG_PRECONDITION == MEDIC_ON
static ALGO_INLINE HEADPreCond_t *HEADGetPreCondition(const HEADPreConditionList_t* const pPreCondList, const uint8 uiPreCondNo);
#endif
static ALGO_INLINE eGDBError_t HEADGetInputValue_float32(const HEADInputValue_t headInputValue, const float32 defaultValue, float32 *const outvalue);
static ALGO_INLINE eGDBError_t HEADGetInputValue_sint32(const HEADInputValue_t headInputValue, const sint32 defaultValue, sint32 *const outvalue);
static ALGO_INLINE eGDBError_t HEADGetInputValue_uint32(const HEADInputValue_t headInputValue, const uint32 defaultValue, uint32 *const outvalue);
static ALGO_INLINE eGDBError_t HEADGetInputValue_boolean(const HEADInputValue_t headInputValue, const boolean defaultValue, boolean *const outvalue);

static ALGO_INLINE void HEADSetInputValueFloat(HEADInputValue_t *const inputValueStruct, const float32 FloatValue, const HEADInputSignalState_t SignalQuality, const float32 StdDev);
static ALGO_INLINE void HEADSetInputValueUInt(HEADInputValue_t *const inputValueStruct, const uint32 UIntValue, const HEADInputSignalState_t SignalQuality);
static ALGO_INLINE void HEADSetInputValueSInt(HEADInputValue_t *const inputValueStruct, const sint32 SIntValue, const HEADInputSignalState_t SignalQuality);
static ALGO_INLINE void HEADSetInputValueBool(HEADInputValue_t *const inputValueStruct, const boolean BoolValue, const HEADInputSignalState_t SignalQuality);
static ALGO_INLINE void HEADSetInputValueUIntTest(HEADInputValue_t *const inputValueStruct, const uint32 UIntValue, const HEADInputSignalState_t SignalQuality);
static ALGO_INLINE void HEADSetInputValueBoolTest(HEADInputValue_t *const inputValueStruct, const boolean BoolValue, const HEADInputSignalState_t SignalQuality);




/*****************************************************************************
  INLINE FUNCTION
*****************************************************************************/

static ALGO_INLINE void HEADInitActiveHypoIterator(const struct HEADStateTransition_t * const pTransition, const HEADConditionGroupBitField_t uiValidForConditionGroups, 
                                               HEADActiveHypIterator_t *const pIterator)
{
  pIterator->currentHypo = HEADNoHypothesis;
  pIterator->uiActiveHypos = HEADGetActiveHyposForConditionGroupBitField(pTransition,uiValidForConditionGroups);
}


static ALGO_INLINE boolean HEADActiveHypoIteratorGetNext(HEADActiveHypIterator_t *const pIterator, HEADHypothesisNr_t *const nextActiveHypo)
{
  boolean            retValue = b_FALSE; /* Return Value indicates whether or not a next hypothesis was found*/
  HEADHypothesisNr_t uiHypoCounter;

  if (pIterator->currentHypo == HEADHypothesisIndependent)
  {
    /* no more Hypos to check*/
    uiHypoCounter = HEADNoHypothesis;
  }
  else if (pIterator->currentHypo != HEADNoHypothesis)
  {
    uiHypoCounter = pIterator->currentHypo + 1u; /* start with the next Hypo */
  }
  else 
  {
    uiHypoCounter = 0; /* Start at the begin */
  }
  for (;(uiHypoCounter < HEAD_MAX_NUMBER_OF_CD_HYPS) && (retValue == b_FALSE);uiHypoCounter++)
  {
    retValue = (((((uint32)(pIterator->uiActiveHypos)) & (1u << uiHypoCounter))) == 0u) ? b_FALSE : b_TRUE;
  }
  if(retValue != b_FALSE)
  {
    pIterator->currentHypo = uiHypoCounter - 1u; /* set to last checked hypo */
    (*nextActiveHypo) = uiHypoCounter - 1u;
  }
  else if (uiHypoCounter <= HEADHypothesisIndependent)/* check for Hypo independent Bit */
  {
    retValue =( ( pIterator->uiActiveHypos & ( (uint16)1u << HEADHypothesisIndependent ) ) == 0u) ? b_FALSE : b_TRUE;
    if (retValue == b_FALSE)
    {
      pIterator->currentHypo = HEADNoHypothesis;
      (*nextActiveHypo) = HEADNoHypothesis;
    }
    else
    {
      pIterator->currentHypo = HEADHypothesisIndependent;
      (*nextActiveHypo) = HEADHypothesisIndependent;
    }
  }
  else
  {
    pIterator->currentHypo = HEADNoHypothesis;
    (*nextActiveHypo) = HEADNoHypothesis;
  }
  return retValue;
}


static ALGO_INLINE boolean HEADIsHypoActiveForModule(const HEADModule_t * const pModule, const HEADHypothesisNr_t uiHypNo)
{
  boolean retValue = b_FALSE;
  uint8   uiCondGrpNo;

  if(pModule != NULL)
  {
    const HEADModuleState_t     * const pLastState = HEADGetModuleState(pModule, ((uint32)pModule->eDGSMLastCycleState - (uint32)pModule->eNumModuleStateMin));
    const HEADStateTransition_t * const pLastTransition = HEADGetLastTransitionForState(pLastState, pModule->eDGSMState);
    
    if(pLastTransition != NULL)
    {
      for (uiCondGrpNo=0; (uiCondGrpNo < pLastTransition->uiNumConditionGroups) && (retValue == b_FALSE); uiCondGrpNo++)
      {
        retValue = HEADIsHypoActiveForCondGroup(pLastTransition,uiHypNo,uiCondGrpNo);
      }
    }
  }
  return retValue;
}

static ALGO_INLINE boolean HEADIsHypoActiveForCondGroup(const HEADStateTransition_t * const pLastTransition, const HEADHypothesisNr_t uiHypNo, const uint8 uiCondGrpNo)
{
  boolean retValue = b_FALSE;
   /* uiOrGoupNo < pModule->uiNumOrGroups is checked inside HEADGetActiveHypothesisForConditionGroup */
  if ((uiHypNo < HEAD_MAX_NUMBER_OF_CD_HYPS) || (uiHypNo == HEADHypothesisIndependent))
  {
    const uint16 uiActiveHyposOrGroup = HEADGetActiveHypothesisForConditionGroup(pLastTransition, uiCondGrpNo);
    retValue = ((((uint32)uiActiveHyposOrGroup) & ((1u << uiHypNo))) == 0u) ? b_FALSE : b_TRUE;
  }
  return retValue;
}

static ALGO_INLINE HEADStateTransition_t *HEADGetLastTransitionForState(const HEADModuleState_t * const pState, const eHEADSMState_t eCurrentState)
{
  HEADStateTransition_t *pTransition = NULL;
  uint8                  uiTransitionNo;
  boolean                bTransitionFound = b_FALSE;

  if((pState != NULL)&&(pState->pStateTransitionList != NULL))
  {
    for(uiTransitionNo = 0; (uiTransitionNo < pState->uiNumTransitions) && (bTransitionFound == b_FALSE); uiTransitionNo++)
    {
      pTransition = &(pState->pStateTransitionList[uiTransitionNo]); /*PRQA S 0491*//*array of known length*/
      if((pTransition != NULL) && (pTransition->eDGSMNextState == eCurrentState)) /* Last Transition found */
      {
        bTransitionFound = b_TRUE;
      }
    }
  }
  return pTransition;
}


static ALGO_INLINE uint16 HEADGetActiveHypothesisForTransition(const HEADStateTransition_t * const pTransition)
{
  uint16 retValue = 0;
  uint8  uiConditionsGoupNo;

  if (pTransition != NULL)
  {
    for(uiConditionsGoupNo=0; uiConditionsGoupNo < pTransition->uiNumConditionGroups; uiConditionsGoupNo++)
    {
        retValue |= HEADGetActiveHypothesisForConditionGroup(pTransition, uiConditionsGoupNo);
    }
  }
  return retValue;
}

static ALGO_INLINE uint16 HEADGetActiveHyposForConditionGroupBitField(const HEADStateTransition_t * const pTransition, const HEADConditionGroupBitField_t uiValidForConditionGroup)
{
  uint16 retValue = 0;
  uint8  uiConditionGroupNo;
  if (pTransition != NULL) 
  {
    for (uiConditionGroupNo=0; uiConditionGroupNo < pTransition->uiNumConditionGroups; uiConditionGroupNo++)
    {
      if ((uiValidForConditionGroup & (1u << uiConditionGroupNo)) !=0u )
      {
        retValue |= HEADGetActiveHypothesisForConditionGroup(pTransition,uiConditionGroupNo);
      }
    }
  }
  return retValue;
}

static ALGO_INLINE uint16 HEADGetActiveHypothesisForConditionGroup(const HEADStateTransition_t * const pTransition, const uint8 uiConditionGroupNo)
{
    uint16 retValue = 0;
    if (uiConditionGroupNo < pTransition->uiNumConditionGroups)
    {
        if (pTransition->puHypInCondGroup != NULL)
        {
            retValue = pTransition->puHypInCondGroup[uiConditionGroupNo];
        }
    }
    return retValue;
}

static ALGO_INLINE const HEADHypothesis_t *HEADGetHypothesis(const HEADHypothesisList_t *const pHypList, const HEADHypothesisNr_t uiHypNo)
{
  const HEADHypothesis_t *retPointer = NULL;
  if (uiHypNo < HEAD_MAX_NUMBER_OF_CD_HYPS)
  {
    retPointer =  &((*pHypList)[uiHypNo]);
  }
  return retPointer;
}


static ALGO_INLINE HEADModule_t *HEADGetModule(const HEADModuleList_t *const pModulelist, const uint32 uiModuleNo)
{
  HEADModule_t *retPointer = NULL;

  if(pModulelist->rgModules != NULL)
  {
    if (uiModuleNo < pModulelist->uiNrOfModules)
    {
      retPointer =  &(pModulelist->rgModules[uiModuleNo]); /*PRQA S 0491*//*array of known length*/
    }
  }
  return retPointer;
}

static ALGO_INLINE HEADModuleState_t *HEADGetModuleState(const HEADModule_t *const pModule, const uint32 uiStateNo)
{
  HEADModuleState_t *retPointer = NULL;

  if(pModule->pModuleStateList != NULL)
  {
    if (uiStateNo < pModule->uiNumModuleStates)
    {
      retPointer =  &(pModule->pModuleStateList[uiStateNo]); /*PRQA S 0491*//*array of known length*/
    }
  }
  return retPointer;
}

static ALGO_INLINE HEADModuleState_t *HEADGetActiveModuleState(const HEADModule_t *const pModule)
{
  HEADModuleState_t *retPointer = NULL;
  uint32             uiStateIndex = 0u;
  boolean            bActiveStateFound = b_FALSE;

  if(pModule->pModuleStateList != NULL)
  {
    for(uiStateIndex = 0u; (uiStateIndex < pModule->uiNumModuleStates) && (bActiveStateFound == b_FALSE); uiStateIndex++)
    {
      retPointer =  &(pModule->pModuleStateList[uiStateIndex]); /*PRQA S 0491*//*array of known length*/
      if((retPointer != NULL)&&(retPointer->bActiveState == b_TRUE))
      {
        bActiveStateFound = b_TRUE;  
      }
    }
  }
  return retPointer;
}


static ALGO_INLINE HEADStateTransition_t *HEADGetStateTransition(const HEADModuleState_t *const pState, const uint32 uiTransitionNo)
{
  HEADStateTransition_t *retPointer = NULL;
  if(pState->pStateTransitionList != NULL)
  {
    if (uiTransitionNo < pState->uiNumTransitions)
    {
      retPointer =  &(pState->pStateTransitionList[uiTransitionNo]); /*PRQA S 0491*//*array of known length*/
    }
  }
  return retPointer;
}


static ALGO_INLINE HEADConditionGrp_t *HEADGetConditionGrp(const HEADStateTransition_t *const pTransition, const uint8 uiConditionGrpNo)
{
  HEADConditionGrp_t *retPointer = NULL;
  if(pTransition->pConditionGroupList != NULL)
  {
    if (uiConditionGrpNo < pTransition->uiNumConditionGroups)
    {
      retPointer =  &(pTransition->pConditionGroupList[uiConditionGrpNo]); /*PRQA S 0491*//*array of known length*/
    }
  }
  return retPointer;
}

#if HEAD_CFG_PRECONDITION == MEDIC_ON
static ALGO_INLINE HEADPreCond_t *HEADGetPreCondition(const HEADPreConditionList_t *const pPreCondList, const uint8 uiPreCondNo)
{
  HEADPreCond_t *retPointer = NULL;
  if(uiPreCondNo < HEAD_AUTO_CFG_NO_PRECONDS)
  {
    retPointer =  &(pPreCondList->rgPreCondList[uiPreCondNo]);
  }
  return retPointer;
}
#endif

static ALGO_INLINE eGDBError_t HEADGetInputValue_float32(const HEADInputValue_t headInputValue, const float32 defaultValue, float32 *const outvalue)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  (*outvalue) = defaultValue;
  if(headInputValue.eSignalType == HEADInputSignalType_Float)
  { 
    (*outvalue) = headInputValue.uValue.fValue;
  }
  else
  {
    retValue= GDB_ERROR_UNKNOWN_TYPE;
  }
  return retValue;
}

static ALGO_INLINE eGDBError_t HEADGetInputValue_sint32(const HEADInputValue_t headInputValue, const sint32 defaultValue, sint32 *const outvalue)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  (*outvalue) = defaultValue;
  if(headInputValue.eSignalType == HEADInputSignalType_SignedInt)
  { 
    (*outvalue) = headInputValue.uValue.iValue;
  }
  else
  {
    retValue= GDB_ERROR_UNKNOWN_TYPE;
  }
  return retValue;
}

static ALGO_INLINE eGDBError_t HEADGetInputValue_uint32(const HEADInputValue_t headInputValue, const uint32 defaultValue, uint32 *const outvalue)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  (*outvalue) = defaultValue;
  if(headInputValue.eSignalType == HEADInputSignalType_UnsignedInt)
  { 
    (*outvalue) = headInputValue.uValue.uiValue;
  }
  else
  {
    retValue= GDB_ERROR_UNKNOWN_TYPE;
  }
  return retValue;
}

static ALGO_INLINE eGDBError_t HEADGetInputValue_boolean(const HEADInputValue_t headInputValue, const boolean defaultValue, boolean *const outvalue)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  (*outvalue) = defaultValue;
  if(headInputValue.eSignalType == HEADInputSignalType_Bool)
  { 
    (*outvalue) = ((headInputValue.uValue.bValue > 0u) ? b_TRUE : b_FALSE);
  }
  else
  {
    retValue= GDB_ERROR_UNKNOWN_TYPE;
  }
  return retValue;
}


/* Set head input values for different types */
static ALGO_INLINE void HEADSetInputValueFloat(HEADInputValue_t *const inputValueStruct, const float32 FloatValue, const HEADInputSignalState_t SignalQuality, const float32 StdDev)
{
  inputValueStruct->eSignalType = HEADInputSignalType_Float;
  inputValueStruct->uValue.fValue = FloatValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = StdDev;
}

static ALGO_INLINE void HEADSetInputValueUInt(HEADInputValue_t *const inputValueStruct, const uint32 UIntValue, const HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_UnsignedInt;
  inputValueStruct->uValue.uiValue = UIntValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

static ALGO_INLINE void HEADSetInputValueSInt(HEADInputValue_t *const inputValueStruct, const sint32 SIntValue, const HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_SignedInt;
  inputValueStruct->uValue.iValue = SIntValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

static ALGO_INLINE void HEADSetInputValueBool(HEADInputValue_t *const inputValueStruct, const boolean BoolValue, const HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_Bool;
  inputValueStruct->uValue.bValue = (BoolValue == b_TRUE) ? 1u: 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/* Set head input values for logical (C internal boolean) input expression */
static ALGO_INLINE void HEADSetInputValueUIntTest(HEADInputValue_t *const inputValueStruct, const uint32 UIntValue, const HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_UnsignedInt;
  inputValueStruct->uValue.uiValue = (UIntValue!= 0u) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

static ALGO_INLINE void HEADSetInputValueBoolTest(HEADInputValue_t *const inputValueStruct, const boolean BoolValue, const HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_Bool;
  inputValueStruct->uValue.bValue = (BoolValue != b_FALSE) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/*! @endcond */

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
/* PRQA L:ALGO_INLINES */
#endif /* HEAD20_H_INCLUDED */

