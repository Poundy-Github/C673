/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head.h

DESCRIPTION:               Internal Header of the HEAD component

AUTHOR:                    $Author: Nese, Raghavendra (uidp8028) $

CREATION DATE:             $Date: 2020/06/24 13:32:21CEST $

VERSION:                   $Revision: 1.23 $

LEGACY VERSION:            1.58 (+1.57.1.1)

**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

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
#define OBJCLASS_INIT  0x1F

/*! @brief          DYNAMICPROPERTY_INIT
    @description    This macro defines the init value for DynamicProperty
                    @typical 0x7, @unit [-]
 */
#define DYNAMICPROPERTY_INIT  0x7

/*! @brief          HEADTimeScale
    @description    Time factor to rescale from secound(s) to millisecond(ms)
                    @typical 1000u, @unit [ms]
 */
#define HEADTimeScale (1000u)                     

/*! @brief          Maximum value of Timer
    @description    Defines the max possible timer value for HEAD SPM Rule
                    in order to change the QoS/Error
                    @typical 65000u, @unit [ms]
    */
#define HEADTimeMax   (65000u)                   

/* Define signal input state values */

/*! @brief          HEAD Input Signal State - OK
    */
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

/*! @brief          MAX NUMBER OF DIM Hypothesis
    */
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
#define HEAD_MAX_NUMBER_OF_DM_HYPS (DIM_NR_OF_EBA_HYPOTHESES)
#else
#define HEAD_MAX_NUMBER_OF_DM_HYPS (0u)
#endif /* #if (MEDIC_CFG_DRIVER_INTENTION_MONITORING) */


/*! Maximum time value as calculation result */

/*! @brief          HEAD TTX MAX Value
    */
#define HEAD_TTX_MAX                                 (    40.0f)

/*! @brief          BOOL FLOAT TRUE
    */
#define BOOL_FLOAT_TRUE   (1.0f)

/*! @brief          BOOL BORDER
    */
#define BOOL_BORDER       (0.5f)

/*! @brief          BOOL FLOAT FALSE
    */
#define BOOL_FLOAT_FALSE  (0.0f)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief       Get InputValue's Standard Deviation */
#define HEADGetInputStdDev(inputValue) ((inputValue).fStdDev)

#if         (MEDIC_CFG_EBA_HEAD_IGNR_SFTY_CHECK)
/* Throw a warning message */
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning : Ignoring the safety distance check is enabled in code. Make sure this is only done for Test-Builds.")
/* Trigger a QAC critical warning DONT USE the Macro */
#define DUMMY_MACRO_WARNING_HEAD_IGNR_SFTY_CHECK_IS_ON(a,b)   #a #b
#endif

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
/*! @brief          Enum for HEAD Input Signal States
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

/*! @brief          The numeric type of the enum @ref eHEADInputSignalState_t
    */
typedef uint8 HEADInputSignalState_t;               /*!< @values:@ref eHEADInputSignalState_t */

/*! @brief          Enum for HEAD Input Signal Type
 */
typedef enum 
{
  eHEADInputSignalType_Float,                       /*!<value type is a float*/
  eHEADInputSignalType_SignedInt,                   /*!<value type is a signed int*/
  eHEADInputSignalType_UnsignedInt,                 /*!<value type is a unsigned int*/
  eHEADInputSignalType_Bool,                        /*!<value type is a bool*/
 
  eHEADInputSignalType_Max                          /*!<MAX input value*/
} eHEADInputSignalType_t;

/*! @brief          The numeric type of the enum @ref eHEADInputSignalType_t
    */
typedef uint8 HEADInputSignalType_t;                /*!< @values:@ref eHEADInputSignalType_t */


/* ****************************************************************
    TYPEDEF UNION
    **************************************************************** */
/*! @brief          Possible head input signal value storage
 */
typedef union
{
  float32 fValue;                               /*!< To store float value*/ /*PRQA S 3629*//*access with get and set functions*/
  sint32 iValue;                                /*!< To store int value*/ 
  uint32 uiValue;                               /*!< To store unsigned int value*/ 
  uint32 bValue;                                /*!< To store bool value*/
} uHEADInputValueUnion_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Standard type for HEAD input signals
    @description    Stores signal quality, it's type, quality and Standard Deviation 
 */
typedef struct HEADInputValue_t
{
  HEADInputSignalState_t eSignalQuality;             /*!< signal quality */
  HEADInputSignalType_t  eSignalType;                /*!< signal type */ 
  uHEADInputValueUnion_t uValue;                     /*!< signal value */
  float32                fStdDev;                    /*!< Standard Deviation */
} HEADInputValue_t;


/*! @brief          Main HEAD input scalar signal list
 */
typedef struct  
{
  HEADInputValue_t LongVelocity;                    /*!< Host vehicle velocity */
  HEADInputValue_t LongAcceleration;                /*!< Host vehicle acceleration */
  HEADInputValue_t YawRate;                         /*!< Host vehicle yaw rate */
  HEADInputValue_t DrivingDirection;                /*!< Host vehicle motion direction */
  HEADInputValue_t EgoLatCurvature;                 /*!< Host vehicle trajectory curvature */
  HEADInputValue_t CDHypotheses;                    /*!< Number of kinematic hypotheses */
  HEADInputValue_t DIMHypotheses;                   /*!< Number of DIM hypotheses */
  HEADInputValue_t SafeObjDistSfty;                 /*!< Safe object distance safety functions */
  HEADInputValue_t SafeObjDistPerf;                 /*!< Safe object distance performance functions */
  HEADInputValue_t StabCtrlState;                   /*!< Status of stability control system */
  HEADInputValue_t BrakeChainState;                 /*!< Status of brake system */
  HEADInputValue_t WarnChainState;                  /*!< Status of warn system */
  HEADInputValue_t PrefillChainState;               /*!< Status of prefill  system */
  HEADInputValue_t HBAChainState;                   /*!< Status of hba system */
  HEADInputValue_t DriverFeedback;                  /*!< Driver Feedback */
  HEADInputValue_t DriverActivity;                  /*!< Driver Activity */
  HEADInputValue_t DriverAttention;                 /*!< Driver Attention */
#if HEAD_CFG_TURN_ASSIST
  HEADInputValue_t SteeringAngle;                       /*!< Steering Angle */
  HEADInputValue_t TurnIndicatorInSteeringDirection;    /*!< Turn Indicator In Steering Direction */
  HEADInputValue_t GasPedal;                            /*!< Gas Pedal */
#endif
} HEADInputValueList_t;

/* application callbacks structure */

/*! @brief Application callback for getting values of custom parameters
 */
typedef eGDBError_t HEADCustomGetHypValue_ft(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, float32 *retValue);

/*! @brief Application callback for filtering parameter values */
typedef eGDBError_t HEADCustomFilterHypValue_ft(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, float32 *pInOutValue );

/*! @brief Application callback for getting independent values of custom parameters */
typedef eGDBError_t HEADCustomGetIndValue_ft(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, float32 *pretValue, uint8 uiModuleNr);

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



/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Main HEAD input data structure */
struct HEADInputData_t
{
  uint8                 uiNumberOfHEADHypotheses;      /*!< Number of hypotheses in array*/
  HEADMainMode_t        eHEADMainMode;                 /*!< driver mode @ref eHEADMainMode_t*/
  eHEADOpMode_t         eOpMode;                       /*!< external operation mode @ref eHEADOpMode_t*/ 

  uint32                uiCurrentCycle;                /*!< HEAD Cycle Count */ 
  float32               fCycleTime;                    /*!< typical cycle time @unit [s]*/

  const HEADHypothesisList_t *rgHypothesisList;        /*!< pointer to hypothesis array*/
  HEADInputValueList_t *pInputValueList;               /*!< pointer to input values*/
  HEADModuleList_t     *pModuleList;                   /*!< HEAD module list*/
  HEADSPMRules_t       *pSPMRules;                     /*!< SPM rules*/

  HEADCustomCallbacks_t CustCallbacks;                 /*!< Application callbacks */
} /* type is already forward declared in head_module_def.h */;


/* ****************************************************************
    TYPEDEF 
    **************************************************************** */
/*! @brief logical operation ( OR ) Group Bit Field */
typedef uint8 HEADORGroupBitField_t;


/*****************************************************************************
  MACROS 
*****************************************************************************/
/*! @brief  logical operation ( OR ) Group Bit Field is assigned to all ones*/
#define HEADOrGroupBitField_ALL  ((HEADORGroupBitField_t)255u)

/*! @brief Get OR group bit field of the given number */
#define HEADOrGroupBitField(Number) ((HEADORGroupBitField_t)(1u<<(Number)& 0xFFu))


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief structure to store active and current hypthesis */
typedef struct 
{
  uint16 uiActiveHypos;                                   /*!< Active hypothesis */
  HEADHypothesisNr_t currentHypo;                         /*!< Current hypothesis */
} HEADActiveHypIterator_t;




/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


extern eGDBError_t HEADInititalize(struct HEADInputData_t *pInputData, float32 fCycleTime);
extern eGDBError_t HEADRun(const struct HEADInputData_t *pInputData,const void *pExtraInputValues, 
                           HEADMTSSendExtraInputSignals_ft *fpExtraValueFct, HEADMTSData_t *pMTSData, 
                           HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleCommonOut_t *pHEADMTSModuleCommonOut,
                           uint32 *puiCurrCycleCnt);
extern eGDBError_t HEADReInit(const struct HEADInputData_t *pInputData, const HEADModuleList_t *pModuleList);
extern eGDBError_t HEADCreateModule(const uint8 strModuleName[], struct HEADModule_t *pModule);

/*!  @cond Doxygen_Suppress */

/* Deactivate QA-C warning 3406; Reviewer: Veerashettappa.Nagaraja; Date: 06.07.2018; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */

ALGO_INLINE void HEADInitActiveHypoIterator(const HEADModule_t * const pModule, const HEADORGroupBitField_t uiValidForOrGroups, HEADActiveHypIterator_t *pIterator);
ALGO_INLINE boolean HEADActiveHypoIteratorGetNext(HEADActiveHypIterator_t *pIterator, HEADHypothesisNr_t *nextActiveHypo);
ALGO_INLINE boolean HEADIsHypoActiveForModule(const HEADModule_t * const pModule, const HEADHypothesisNr_t uiHypNo);
ALGO_INLINE boolean HEADIsHypoActiveForOrGroup(const HEADModule_t * const pModule, const HEADHypothesisNr_t uiHypNo, const uint8 uiOrGoupNo);
ALGO_INLINE uint16 HEADGetActiveHypothesisForModule(const HEADModule_t * const pModule);
ALGO_INLINE uint16 HEADGetActiveHyposForORGroupBitField(const HEADModule_t * const pModule, const HEADORGroupBitField_t uiValidForOrGroup);
ALGO_INLINE uint16 HEADGetActiveHypothesisForORGroup(const HEADModule_t * const pModule, const uint8 uiOrGoupNo);
ALGO_INLINE uint32 HEADGetHypothesisTypesOfBitfield( const struct HEADInputData_t * pInputData, 
                                                     const uint16 uiActHypField);
ALGO_INLINE HEADHypothesisNr_t HEADGetMostCritHypOfBitfieldForModule( const struct HEADInputData_t * pInputData, const uint16 uiActHypField, 
                                                                     const Hypothesis_t** ppCurrCDHypo, const boolean bUseDecel);

ALGO_INLINE const HEADHypothesis_t *HEADGetHypothesis(const HEADHypothesisList_t *const pHypList, const HEADHypothesisNr_t uiHypNo);
ALGO_INLINE HEADModule_t *HEADGetModule(const HEADModuleList_t *const pModulelist, const uint32 uiModuleNo);


ALGO_INLINE eGDBError_t HEADGetInputValue_float32(const HEADInputValue_t headInputValue, float32 defaultValue, float32 *outvalue);
ALGO_INLINE eGDBError_t HEADGetInputValue_sint32(const HEADInputValue_t headInputValue, sint32 defaultValue, sint32 *outvalue);
ALGO_INLINE eGDBError_t HEADGetInputValue_uint32(const HEADInputValue_t headInputValue, uint32 defaultValue, uint32 *outvalue);
ALGO_INLINE eGDBError_t HEADGetInputValue_boolean(const HEADInputValue_t headInputValue, boolean defaultValue, boolean *outvalue);

ALGO_INLINE void HEADSetInputValueFloat(HEADInputValue_t *inputValueStruct, float32 FloatValue, HEADInputSignalState_t SignalQuality, float32 StdDev);
ALGO_INLINE void HEADSetInputValueUInt(HEADInputValue_t *inputValueStruct, uint32 UIntValue, HEADInputSignalState_t SignalQuality);
ALGO_INLINE void HEADSetInputValueSInt(HEADInputValue_t *inputValueStruct, sint32 SIntValue, HEADInputSignalState_t SignalQuality);
ALGO_INLINE void HEADSetInputValueBool(HEADInputValue_t *inputValueStruct, boolean BoolValue, HEADInputSignalState_t SignalQuality);
ALGO_INLINE void HEADSetInputValueUIntTest(HEADInputValue_t *inputValueStruct, uint32 UIntValue, HEADInputSignalState_t SignalQuality);
ALGO_INLINE void HEADSetInputValueBoolTest(HEADInputValue_t *inputValueStruct, boolean BoolValue, HEADInputSignalState_t SignalQuality);




/*****************************************************************************
  INLINE FUNCTION
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:         HEADInitActiveHypoIterator                                                                  */ /*!

  @brief                Initialize Active hypothesis iterator

  @description          Initialize Active hypothesis iterator 

  @return               void

  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            uiValidForOrGroups : valid OR_Group Indicator
  @param[in]            pIterator : pointer to Active Hypothesis Iterator (Holds Active and Current Hypotesis)
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADInitActiveHypoIterator(const HEADModule_t * const pModule, const HEADORGroupBitField_t uiValidForOrGroups, 
                                               HEADActiveHypIterator_t *pIterator)
{
  pIterator->currentHypo = HEADNoHypothesis;
  pIterator->uiActiveHypos = HEADGetActiveHyposForORGroupBitField(pModule,uiValidForOrGroups);
}



/*************************************************************************************************************************
  Functionname:         HEADActiveHypoIteratorGetNext                                                                  */ /*!

  @brief                Get Next Active Hypothesis from Active Hypothesis list

  @description          Get Next Active Hypothesis from Active Hypothesis list

  @return               void

  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            uiValidForOrGroups : valid OR_Group Indicator
  @param[in]            pIterator : Pointer to Active Hypothesis Iterator (Holds Active and Current Hypotesis )
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE boolean HEADActiveHypoIteratorGetNext(HEADActiveHypIterator_t *pIterator, HEADHypothesisNr_t *nextActiveHypo)
{
  boolean retValue = b_FALSE; /* Return Value indicates whether or not a next hypothesis was found*/
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
    uiHypoCounter = 0u; /* Start at the begin */
  }
  for (;(uiHypoCounter < HEAD_MAX_NUMBER_OF_CD_HYPS) && (retValue == b_FALSE);uiHypoCounter++)
  {
    retValue = ( ( pIterator->uiActiveHypos & ( 1u << uiHypoCounter ) ) == 0u) ? b_FALSE : b_TRUE;/*PRQA S 1891 #date: 2020-06-02, reviewer: Nalina M, reason: Supressing while casting variable value would be trucated*/
  }
  if(retValue != b_FALSE)
  {
    pIterator->currentHypo = uiHypoCounter - 1u; /* set to last checked hypo */
    (*nextActiveHypo) = uiHypoCounter - 1u;
  }
  else if (uiHypoCounter <= HEADHypothesisIndependent)/* check for Hypo independent Bit */
  {
    retValue =( ( pIterator->uiActiveHypos & ( 1u << HEADHypothesisIndependent ) ) == 0u) ? b_FALSE : b_TRUE;/*PRQA S 0499 #date: 2020-06-02, reviewer: Nalina M, reason: Supressing because of no side effect */
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



/*************************************************************************************************************************
  Functionname:         HEADIsHypoActiveForModule                                                                   */ /*!

  @brief                Checks if any particular Hypothesis is Active for the Module

  @description          Checks if any particular Hypothesis is Active for the Module

  @return               boolean : Return True if the Hypothesis is Active for the Module, else return false

  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            uiHypNo : 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE boolean HEADIsHypoActiveForModule(const HEADModule_t * const pModule, const HEADHypothesisNr_t uiHypNo)
{
  boolean retValue = b_FALSE;
  uint8 uiOrGoupNo;
  /* Module != NULL is checked inside HEADGetActiveHypothesisForORGroup */
  for (uiOrGoupNo=0; (uiOrGoupNo < pModule->uiNumOrGroups) && (retValue == b_FALSE); uiOrGoupNo++)
  {
    retValue = HEADIsHypoActiveForOrGroup(pModule,uiHypNo,uiOrGoupNo);
  }
  return retValue;
}

ALGO_INLINE boolean HEADIsHypoActiveForOrGroup(const HEADModule_t * const pModule, const HEADHypothesisNr_t uiHypNo, const uint8 uiOrGoupNo)
{
  boolean retValue = b_FALSE;
   /* Module != NULL and uiOrGoupNo < pModule->uiNumOrGroups is checked inside HEADGetActiveHypothesisForORGroup */
  if ((uiHypNo < HEAD_MAX_NUMBER_OF_CD_HYPS) || (uiHypNo == HEADHypothesisIndependent))
  {
    const uint16 uiActiveHyposOrGroup = HEADGetActiveHypothesisForORGroup(pModule, uiOrGoupNo);
    retValue = ( ( uiActiveHyposOrGroup & ( 1u << uiHypNo ) ) == 0u) ? b_FALSE : b_TRUE;/*PRQA S 1891 #date: 2020-06-02, reviewer: Nalina M, reason: Supressing while casting variable value would be trucated*/
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADGetActiveHypothesisForModule                                                            */ /*!

  @brief                Return Cumulative Active Hypothesis list out of all OR_Group 

  @description          Return Cumulative Active Hypothesis list out of all OR_Group 

  @return               uint16 : Active Hypothesis out of all OR_Group

  @param[in]            pModule : Pointer to a HEAD Module

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE uint16 HEADGetActiveHypothesisForModule(const HEADModule_t * const pModule)
{
  uint16 retValue = 0;
  uint8 uiOrGoupNo;
  if (pModule != NULL) 
  {
    for (uiOrGoupNo=0; uiOrGoupNo < pModule->uiNumOrGroups; uiOrGoupNo++)
    {
      retValue |= HEADGetActiveHypothesisForORGroup(pModule,uiOrGoupNo);
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADGetActiveHyposForORGroupBitField                                                        */ /*!

  @brief                Return Cumulative Active Hypothesis out of all valid OR_Group 

  @description          Return Cumulative Active Hypothesis out of all valid OR_Group 

  @return               uint16 : Active Hypothesis out of all valid OR_Group

  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            uiValidForOrGroup : Defines valid OR_Group 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE uint16 HEADGetActiveHyposForORGroupBitField(const HEADModule_t * const pModule, const HEADORGroupBitField_t uiValidForOrGroup)
{
  uint16 retValue = 0;
  uint8 uiOrGoupNo;
  if (pModule != NULL) 
  {
    for (uiOrGoupNo=0; uiOrGoupNo < pModule->uiNumOrGroups; uiOrGoupNo++)
    {
      if ((uiValidForOrGroup & (1u << uiOrGoupNo)) != 0u )
      {
        retValue |= HEADGetActiveHypothesisForORGroup(pModule,uiOrGoupNo);
      }
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADGetActiveHypothesisForORGroup                                                           */ /*!

  @brief                Return Active Hypothesis in a OR_Group 

  @description          Return Active Hypothesis in a OR_Group 
  
  @return               uint16 : Active Hypothesis in a OR_Group

  @param[in]            pModule : Pointer to a HEAD Module
  @param[in]            uiOrGoupNo : OR Group Number
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE uint16 HEADGetActiveHypothesisForORGroup(const HEADModule_t * const pModule, const uint8 uiOrGoupNo)
{
  uint16 retValue = 0;
  if ((pModule != NULL) && (uiOrGoupNo < pModule->uiNumOrGroups))
  {
    retValue = pModule->uiHypInOrGroup[uiOrGoupNo];
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADGetHypothesisTypesOfBitfield                                                            */ /*!

  @brief                Return Active Hypothesis types in Bit Field 

  @description          Return Active Hypothesis types in Bit Field 
                        CDHypothesisType_No=0, CDHypothesisType_RunUp=1, CDHypothesisType_RunUpBraking=2,
                        CDHypothesisType_RunUpStationary=3, CDHypothesisType_Static=4, CDHypothesisType_ACC=5,
                        CDHypothesisType_Pass=6, CDHypothesisType_CutIn=7, CDHypothesisType_Collision=8,
                        CDHypothesisType_CollisionUnavoidable=9, CDHypothesisType_PedCollision=10,
                        CDHypothesisType_PedPass=11, CDHypothesisType_Crossing=12, CDHypothesisType_CyclColl=13  

  @return               uint32 : Active Hypothesis types

  @param[in]            pInputData : Pointer to a HEAD Input Data
  @param[in]            uiActHypField : Active hypothesis in Bit field
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE uint32 HEADGetHypothesisTypesOfBitfield( const struct HEADInputData_t * pInputData, 
                                                                 const uint16 uiActHypField)
{
  HEADActiveHypIterator_t pIterator;
  HEADHypothesisNr_t ActiveHypoNr = HEADNoHypothesis;
  uint32 retValue = 0;

  pIterator.currentHypo = HEADNoHypothesis;
  pIterator.uiActiveHypos = uiActHypField;

  while(b_FALSE != HEADActiveHypoIteratorGetNext(&pIterator,&ActiveHypoNr))
  {
    const HEADHypothesis_t * const pTmpHeadHypo = HEADGetHypothesis(pInputData->rgHypothesisList, ActiveHypoNr);
    if (pTmpHeadHypo != NULL)
    {
      const Hypothesis_t * const pActiveHyp = pTmpHeadHypo->pHypothesis;
      if (pActiveHyp != NULL)
      {
        if (pActiveHyp->eType != CDHypothesisType_No)
        {
          retValue = (retValue | ((uint32)1u << (pActiveHyp->eType - 1u)));
        }
      }
    }
    else
    {
      /* Hypo independent => No Change of Values*/
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADGetMostCritHypOfBitfieldForModule                                                       */ /*!

  @brief                Return the Most Critical Active Hypothesis

  @description          Return the Most Critical Active Hypothesis based on Deceleration value or TTC value

  @return               HEADHypothesisNr_t : Most Critical Active hypothesis Number

  @param[in]            pInputData : Pointer to a HEAD Input Data
  @param[in]            uiActHypField : Active hypothesis in Bit field
  @param[in]            ppCurrCDHypo : Most Critical CD Hypothesis
  @param[in]            bUseDecel : Bit Indictes whether to use Deceleration value (bUseDecel : True)
                        or TTC value(bUseDecel : false) to find the most critical active hypothesis
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE HEADHypothesisNr_t HEADGetMostCritHypOfBitfieldForModule( const struct HEADInputData_t * pInputData, 
                                                                            const uint16 uiActHypField,
                                                                            const Hypothesis_t** ppCurrCDHypo,
                                                                            const boolean bUseDecel)
{
  /* Get Most critical activating Hypotheses number */
  HEADActiveHypIterator_t Iterator;
  HEADHypothesisNr_t ActiveHypoNr = HEADNoHypothesis;
  HEADHypothesisNr_t retVal = HEADNoHypothesis;
  float32 fDecelerationCurrent = 0.0f;
  float32 fTTCCurrent = HEAD_TTX_MAX;

  Iterator.currentHypo = HEADNoHypothesis;
  Iterator.uiActiveHypos = uiActHypField;

  while(b_FALSE != HEADActiveHypoIteratorGetNext(&Iterator,&ActiveHypoNr))
  {
    const HEADHypothesis_t * const pTmpHeadHypo = HEADGetHypothesis(pInputData->rgHypothesisList, ActiveHypoNr);
    if (pTmpHeadHypo != NULL)
    {
      const Hypothesis_t * const pActiveHyp = pTmpHeadHypo->pHypothesis;
      if (pActiveHyp != NULL)
      {
        if ( (bUseDecel == b_TRUE) &&
             ((fDecelerationCurrent > pActiveHyp->fLongNecAccel) || (retVal == HEADNoHypothesis)))
        {
          retVal = ActiveHypoNr;
          *ppCurrCDHypo = pTmpHeadHypo->pHypothesis;
          fDecelerationCurrent = pActiveHyp->fLongNecAccel;
        }
        else if ((bUseDecel == b_FALSE) &&
                 ((fTTCCurrent > pActiveHyp->fTTC)|| (retVal == HEADNoHypothesis)))
        {
          retVal = ActiveHypoNr;
          *ppCurrCDHypo = pTmpHeadHypo->pHypothesis;
          fTTCCurrent = pActiveHyp->fTTC;
        }
        else
        {
          /* not relevant */
        }
      }
    }
    else
    {
      /* Hypo independent => No Change of Values*/
    }
  }
  return retVal;
}

/*************************************************************************************************************************
  Functionname:         HEADGetHypothesis                                                                           */ /*!

  @brief                Return a Hypothesis correspond to hypothesis number from hypothesis list

  @description          Return a Hypothesis correspond to hypothesis number from hypothesis list

  @return               HEADHypothesis_t : Pointer to a hypothesis 

  @param[in]            pHypList : Pointer to HEAD Hypothesis List
  @param[in]            uiHypNo :  hypothesis Number
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE const HEADHypothesis_t *HEADGetHypothesis(const HEADHypothesisList_t *const pHypList, const HEADHypothesisNr_t uiHypNo)
{
  const HEADHypothesis_t *retPointer = NULL;
  if (uiHypNo < HEAD_MAX_NUMBER_OF_CD_HYPS)
  {
    retPointer =  &((*pHypList)[uiHypNo]);
  }
  return retPointer;
}


/*************************************************************************************************************************
  Functionname:         HEADGetModule                                                                               */ /*!

  @brief                Return a Module correspond to Module number from HEAD Module list

  @description          Return a Module correspond to Module number from HEAD Module list

  @return               HEADModule_t : Pointer to a HEAD Module 

  @param[in]            pModulelist : Pointer to HEAD Module List
  @param[in]            uiHypNo :  Module Number
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE HEADModule_t *HEADGetModule(const HEADModuleList_t *const pModulelist, const uint32 uiModuleNo)
{
  HEADModule_t *retPointer = NULL;
  if (uiModuleNo < pModulelist->uiNrOfModules)
  {
    retPointer =  &(pModulelist->rgModules[uiModuleNo]); /*PRQA S 0491*//*array of known length*/
  }
  return retPointer;
}


/*************************************************************************************************************************
  Functionname:         HEADGetInputValue_float32                                                                   */ /*!

  @brief                Get Input Signal Value of type float32

  @description          Get Input Signal Value of type float32

  @return               eGDBError_t : GDB Error None if the signal type is float, else return error @ref GDB_ERROR_UNKNOWN_TYPE

  @param[in]            headInputValue : input signal (contains signal quality, signal type, signal value and Standard Deviation)
  @param[in]            defaultValue : Default value to the signal
  @param[out]           outvalue : output Signal Value 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE eGDBError_t HEADGetInputValue_float32(const HEADInputValue_t headInputValue, float32 defaultValue, float32 *outvalue)
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

/*************************************************************************************************************************
  Functionname:         HEADGetInputValue_sint32                                                                    */ /*!

  @brief                Get Input Signal Value of type sint32

  @description          Get Input Signal Value of type sint32

  @return               eGDBError_t : GDB Error None if the signal type is SignedInt, else return error @ref GDB_ERROR_UNKNOWN_TYPE

  @param[in]            headInputValue : input signal (contains signal quality, signal type, signal value and Standard Deviation)
  @param[in]            defaultValue : Default value to the signal
  @param[out]           outvalue : output Signal Value 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE eGDBError_t HEADGetInputValue_sint32(const HEADInputValue_t headInputValue, sint32 defaultValue, sint32 *outvalue)
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

/*************************************************************************************************************************
  Functionname:         HEADGetInputValue_uint32                                                                    */ /*!

  @brief                Get Input Signal Value of type uint32

  @description          Get Input Signal Value of type uint32

  @return               eGDBError_t : GDB Error None if the signal type is UnsignedInt, else return error @ref GDB_ERROR_UNKNOWN_TYPE

  @param[in]            headInputValue : input signal (contains signal quality, signal type, signal value and Standard Deviation)
  @param[in]            defaultValue : Default value to the signal
  @param[out]           outvalue : output Signal Value 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE eGDBError_t HEADGetInputValue_uint32(const HEADInputValue_t headInputValue, uint32 defaultValue, uint32 *outvalue)
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

/*************************************************************************************************************************
  Functionname:         HEADGetInputValue_boolean                                                                   */ /*!

  @brief                Get Input Signal Value of type boolean

  @description          Get Input Signal Value of type boolean

  @return               eGDBError_t : GDB Error None if the signal type is Bool, else return error @ref GDB_ERROR_UNKNOWN_TYPE

  @param[in]            headInputValue : input signal (contains signal quality, signal type, signal value and Standard Deviation)
  @param[in]            defaultValue : Default value to the signal
  @param[out]           outvalue : output Signal Value 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE eGDBError_t HEADGetInputValue_boolean(const HEADInputValue_t headInputValue, boolean defaultValue, boolean *outvalue)
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
/*************************************************************************************************************************
  Functionname:         HEADSetInputValueFloat                                                                      */ /*!

  @brief                Set head input Signal for type Float

  @description          Set HEAD Input signal quality, type, value and Standard Deviation for type Float. 

  @return               void 

  @param[out]           inputValueStruct : Pointer to HEAD input signal 
  @param[in]            FloatValue : Float Value
  @param[in]            SignalQuality : signal quality
  @param[in]            StdDev : Standard Deviation
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADSetInputValueFloat(HEADInputValue_t *inputValueStruct, float32 FloatValue, HEADInputSignalState_t SignalQuality, float32 StdDev)
{
  inputValueStruct->eSignalType = HEADInputSignalType_Float;
  inputValueStruct->uValue.fValue = FloatValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = StdDev;
}

/*************************************************************************************************************************
  Functionname:         HEADSetInputValueUInt                                                                       */ /*!

  @brief                Set head input Signal for type Unsigned integer

  @description          Set HEAD Input signal quality, type, value and Standard Deviation for type Unsigned integer. 

  @return               void 

  @param[out]           inputValueStruct : Pointer to HEAD input signal 
  @param[in]            UIntValue : Unsigned integer Value
  @param[in]            SignalQuality : signal quality
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADSetInputValueUInt(HEADInputValue_t *inputValueStruct, uint32 UIntValue, HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_UnsignedInt;
  inputValueStruct->uValue.uiValue = UIntValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/*************************************************************************************************************************
  Functionname:         HEADSetInputValueSInt                                                                       */ /*!

  @brief                Set head input Signal for type signed integer

  @description          Set HEAD Input signal quality, type, value and Standard Deviation for type signed integer. 

  @return               void 

  @param[out]           inputValueStruct : Pointer to HEAD input signal 
  @param[in]            SIntValue : Signed integer Value
  @param[in]            SignalQuality : signal quality
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADSetInputValueSInt(HEADInputValue_t *inputValueStruct, sint32 SIntValue, HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_SignedInt;
  inputValueStruct->uValue.iValue = SIntValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/*************************************************************************************************************************
  Functionname:         HEADSetInputValueBool                                                                       */ /*!

  @brief                Set head input Signal for type Bool

  @description          Set HEAD Input signal quality, type, value and Standard Deviation for type Bool. 

  @return               void 

  @param[out]           inputValueStruct : Pointer to HEAD input signal 
  @param[in]            BoolValue : Boolean Value
  @param[in]            SignalQuality : signal quality
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADSetInputValueBool(HEADInputValue_t *inputValueStruct, boolean BoolValue, HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_Bool;
  inputValueStruct->uValue.bValue = (BoolValue != b_FALSE) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/* Set head input values for logical (C internal boolean) input expression */
/*************************************************************************************************************************
  Functionname:         HEADSetInputValueUIntTest                                                                   */ /*!

  @brief                Set head input Signal for logical input expression based on Unsigned integer Test

  @description          Set HEAD Input signal quality, type, value and Standard Deviation for logical input expression based on Unsigned integer Test. 

  @return               void 

  @param[out]           inputValueStruct : Pointer to HEAD input signal 
  @param[in]            UIntValue : Unsigned Integer Value
  @param[in]            SignalQuality : signal quality
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADSetInputValueUIntTest(HEADInputValue_t *inputValueStruct, uint32 UIntValue, HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_UnsignedInt;
  inputValueStruct->uValue.uiValue = (UIntValue!= 0u) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/*************************************************************************************************************************
  Functionname:         HEADSetInputValueBoolTest                                                                   */ /*!

  @brief                Set head input Signal for logical input expression based on Bool Test

  @description          Set HEAD Input signal quality, type, value and Standard Deviation for logical input expression based on Bool Test. 

  @return               void 

  @param[out]           inputValueStruct : Pointer to HEAD input signal 
  @param[in]            UIntValue : Unsigned Integer Value
  @param[in]            SignalQuality : signal quality
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE void HEADSetInputValueBoolTest(HEADInputValue_t *inputValueStruct, boolean BoolValue, HEADInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType = HEADInputSignalType_Bool;
  inputValueStruct->uValue.bValue = (BoolValue != b_FALSE) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev = 0.0f;
}

/*! @endcond */

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
/* PRQA L:ALGO_INLINES */
#endif /* HEAD_H_INCLUDED */
/**@}*/

