/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_spm.h

DESCRIPTION:               Header for the signal performance monitor of the HEAD module

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:48:23CEST $

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            1.25
  
**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_SPM_H_INCLUDED
#define HEAD_SPM_H_INCLUDED

/*! @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*! @endcond */

/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief          Maximum number of SPM rules for the MTS
    @description    This Macro defines the Maximum number of SPM rules for 
                    the MTS. \n
                    @typical 25u, @unit [-],  
	*/
#if HEAD_CFG_TURN_ASSIST
#define HEADMTSSPMRulesMax (31u)
#else
#define HEADMTSSPMRulesMax (25u)
#endif


/*****************************************************************************
  MACROS 
*****************************************************************************/
/*! @brief          Gives bit number for the corresponding HEAD module. \n
                    @range  [1,(1<<@ref HEAD_AUTO_CFG_NO_MODULES)]*/
#define HEADSPMGetModuleBit(modulenr) (1uL<<(modulenr))


/*! @brief          Gives the maximum bit number for the HEAD module. \n
                    @typical ((1<<@ref HEADModules_Max)-1)*/
#define HEADSPMGetAllModuleBits ((1<<HEADModules_Max)-1)


/*! @brief          Sets the bits to define the HEAD module signal for standard deviation
    @description    Based on the Enum value (@ref  eHEADSPMCheckBitsStdDeviation_t) passed to this Macro
                    the corresponding bit(s) for HEAD module signal for standard deviation will be Set.
*/
#define HEADSPMSetBitsStdDeviation(StdDev) ( ((uint32)(StdDev))   & 3u)


/*! @brief          Sets the bits to define how the HEAD module signal to be used by the function
    @description    Based on the Enum value (@ref  eHEADSPMCheckBitsFunction_t) passed to this Macro
                    the corresponding bit for how the HEAD module signal to be used by the function will be set.
*/
#define HEADSPMSetBitsFunction(Function)   ((((uint32)(Function)) & 3u) << 2u)


/*! @brief          Sets the bits to define which operator to use for the HEAD signal operation
    @description    Based on the Enum value (@ref  eHEADSPMCheckBitsOp_t) passed to this Macro
                    the bit(s) that defines which operator to use for the HEAD signal operation will be set.
*/
#define HEADSPMSetBitsOperator(Operator)   ((((uint32)(Operator)) & 7u) << 4u)


/*! @brief          Sets the bits to define whether the signal or its state needs to be checked    
    @description    Based on the Enum value (@ref  eHEADSPMCheckBitsSignal_t) passed to this Macro
                    the bit(s) which defines whetherthe signal or its state needs to be checked will be set.
*/
#define HEADSPMSetBitsSignal(Signal)       ((((uint32)(Signal))   & 1u) << 7u)


/*! @brief          Gets the bits which define the HEAD module signal for standard deviation
    @description    Based on the value(@ref HEADSPMCheck_t::bitCheckType) passed to this Macro,
                    gets the bits which define the HEAD module signal for standard deviation.
*/
#define HEADSPMGetBitsStdDeviation(bCheckType) ((HEADSPMCheckBitsStdDeviation_t)((bCheckType) & 3u))


/*! @brief          Gets the bits which define how the HEAD module signal to be used by the function
    @description    Based on the value(@ref HEADSPMCheck_t::bitCheckType) passed to this Macro,
                    gets the bits which defines how the HEAD module signal to be used by the function.
*/
#define HEADSPMGetBitsFunction(bCheckType)     ((HEADSPMCheckBitsFunction_t)(((bCheckType) & 12u)>>2u))


/*! @brief          Gets the bits to define which operator to use for the HEAD signal operation    
    @description    Based on the value(@ref HEADSPMCheck_t::bitCheckType) passed to this Macro,
                    gets the bits which defines which operator to use for the HEAD signal operation.
*/
#define HEADSPMGetBitsOperator(bCheckType)     ((HEADSPMCheckBitsOp_t)(((bCheckType) & 112u)>>4u))


/*! @brief          Gets the bits which define whether the signal or its state needs to be checked    
    @description    Based on the value(@ref HEADSPMCheck_t::bitCheckType) passed to this Macro,
                    gets the bits which defines whether the signal or its state needs to be checked.
*/
#define HEADSPMGetBitsSignal(bCheckType)       ((HEADSPMCheckBitsSignal_t)(((bCheckType) & 128u)>>7u))


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/



/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          HEAD output signal identifiers

    @description    These Identifiers are used to identify the HEAD output signals in the visualization
    
    @conseq         Only add new signals
    
    @attention      Deleting signals or changing IDs will brake compatibility to former projects
    */
typedef enum 
{
  eHEADMTSInSigIdent_NoSignal                         = 0,  /*!< Entry to define that no signal is attached yet */
  eHEADMTSInSigIdent_Velocity                         = 1,  /*!< Velocity identifier */
  eHEADMTSInSigIdent_Acceleration                     = 2,  /*!< Acceleration identifier */
  eHEADMTSInSigIdent_YawRate                          = 3,  /*!< Yaw Rate identifier */
  eHEADMTSInSigIdent_DrivinDirection                  = 4,  /*!< Identifier for Driving Direction */
  eHEADMTSInSigIdent_CDHypotheses                     = 5,  /*!< Identifier for the signal which defines number of CD Hypothesis */
  eHEADMTSInSigIdent_DMHypotheses                     = 6,  /*!< Identifier for the signal which defines number of DIM Hypothesis */
  eHEADMTSInSigIdent_SafeObjDistSfty                  = 7,  /*!< Safe Object Distance Safety */
  eHEADMTSInSigIdent_SafeObjDistPerf                  = 8,  /*!< Safe Object Distance Performance */
  eHEADMTSInSigIdent_StabCtrlState                    = 9,  /*!< State of the Stabilization Control */
  eHEADMTSInSigIdent_BrakeChainState                  = 10, /*!< State of the Brake System */
  eHEADMTSInSigIdent_WarnChainState                   = 11, /*!< State of the Warn System */
  eHEADMTSInSigIdent_DriverFeedback                   = 12, /*!< Identifier for Driver Feedback */
  eHEADMTSInSigIdent_DriverActivity                   = 13, /*!< Identifier for Driver Activity */
  eHEADMTSInSigIdent_DriverAttention                  = 14, /*!< Identifier for Driver Attention */
  eHEADMTSInSigIdent_DIMInputsValid                   = 15, /*!< Valid DIM Input signals */
  eHEADMTSInSigIdent_CameraReady                      = 16, /*!< Camera Ready identifier */
  eHEADMTSInSigIdent_ExtPreBrakeSetting               = 17, /*!< ExtPreBrakeSetting identifier */
  eHEADMTSInSigIdent_EgoLatCurvature                  = 18, /*!< Curvature of ego trajectory */  
  #if HEAD_CFG_TURN_ASSIST
  eHEADMTSInSigIdent_SteeringAngle                    = 19, /*!< Steering Angle */
  eHEADMTSInSigIdent_TurnIndicatorInSteeringDirection = 20, /*!< Turn Indicator In Steering Direction */
  eHEADMTSInSigIdent_GasPedal                         = 21, /*!< Gas Pedal */
  #endif
  eHEADMTSInSigIdent_Max                              = 255 /*!< Maximum number of HEAD signal identifiers */
} HEADMTSInSigIdent_t;



/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Enum to identify HEAD SPM signal or its state needs to be checked 

    @description    Enumerations used for setting/getting the bits which define whether
                    the signal or its state needs to be checked 
    */
typedef enum 
{
  HEADSPMCheckBitsSignal_SigState            = 0, /*!< defines that the SignalState needs to be checked*/
  HEADSPMCheckBitsSignal_Signal              = 1, /*!< defines that the Signal itself needs to be checked*/

  HEADSPMCheckBitsSignal_Max                 = 2  /*!< maximum number of enumerations for HEAD signal checking */ 
} eHEADSPMCheckBitsSignal_t;



/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          The numeric type of the enum @ref eHEADSPMCheckBitsSignal_t

    */
typedef uint8 HEADSPMCheckBitsSignal_t; /*!< @values: eHEADSPMCheckBitsSignal_t */



/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Enum to identify which operator to use for the HEAD SPM signal operation 

    @description    Enumerations used for setting/getting the bits which defines which operator 
                    to use for the HEAD signal operation.
    */
typedef enum 
{
  HEADSPMCheckBitsOp_Equals            = 0, /*!< defines that the Signal needs to be equal */
  HEADSPMCheckBitsOp_EqualsNot         = 1, /*!< defines that the Signal needs to be NOT equal */
  HEADSPMCheckBitsOp_Smaller           = 2, /*!< defines that the Signal needs to be smaller */
  HEADSPMCheckBitsOp_SmallerOrEqual    = 3, /*!< defines that the Signal needs to be smaller or equal */
  HEADSPMCheckBitsOp_Greater           = 4, /*!< defines that the Signal needs to be greater */
  HEADSPMCheckBitsOp_GreaterOrEqual    = 5, /*!< defines that the Signal needs to be greater or equal */

  HEADSPMCheckBitsOp_Max               = 6 /*!< maximum number of enumerations for the HEAD signal operator defination */ 
} eHEADSPMCheckBitsOp_t; 


/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          The numeric type of the enum @ref eHEADSPMCheckBitsOp_t

    */
typedef uint8 HEADSPMCheckBitsOp_t;         /*!< @values: eHEADSPMCheckBitsOp_t */


/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Enum to identify how the HEAD module signal to be used by the function

    @description    Enumerations used for setting/getting the bits which defines 
                    how the HEAD module signal to be used by the function.
    */
typedef enum
{
  HEADSPMCheckBitsFunction_No                = 0, /*!< defines that the Signal is not modified by a function */
  HEADSPMCheckBitsFunction_ABS               = 1, /*!< defines that the absolute value of the Signal is used */
 
  HEADSPMCheckBitsFunction_Max               = 2  /*!< maximum number of enumerations for the defination of HEAD signal usage by function */
} eHEADSPMCheckBitsFunction_t;


/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          The numeric type of the enum @ref eHEADSPMCheckBitsFunction_t
    */
typedef uint8 HEADSPMCheckBitsFunction_t;         /*!< @values: eHEADSPMCheckBitsFunction_t */


/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Enum to identify HEAD module signal for standard deviation

    @description    Enumerations used for setting/getting the bits which define 
                    the HEAD module signal for standard deviation    
    */
typedef enum
{
  HEADSPMCheckBitsStdDeviation_No            = 0, /*!< defines that the Signal is not modified by the standard deviation */
  HEADSPMCheckBitsStdDeviation_Plus          = 1, /*!< defines that the Signal plus the standard deviation is checked against the threshold */
  HEADSPMCheckBitsStdDeviation_Minus         = 2, /*!< defines that the Signal minus the standard deviation is checked against the threshold */
 
  HEADSPMCheckBitsStdDeviation_Max           = 3  /*!< maximum number of enumerations for the defination of HEAD signal for standard deviation */
} eHEADSPMCheckBitsStdDeviation_t; 


/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          The numeric type of the enum @ref eHEADSPMCheckBitsStdDeviation_t
    */
typedef uint8 HEADSPMCheckBitsStdDeviation_t;     /*!< @values: eHEADSPMCheckBitsStdDeviation_t */


struct HEADInputValue_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Structure to store HEAD SPM check rules 

    @description    Describes the type of HEAD SPM check rules and how to handle them.
    */
typedef struct 
{
  struct HEADInputValue_t   *pInputSignal;   /*!< pointer to a input signal */
  HEADMTSInSigIdent_t  eHEADMTSInSigIdent;   /*!< HEAD MTS signal identifier    @range @ref HEADMTSInSigIdent_t */
  uint32               bitModules;           /*!< bits that defines which modules are affected by this rule */
  f16_t                f16Value;             /*!< 16bit float that defines the parameter value */
  uint16               uiNeededTime;         /*!< defines how long (scaled by HEADSpmTimeScale) the condition need to be true to change the QoS/Error   @unit [ms], @range [0,@ref HEADTimeMax]*/ 
  uint16               uiCurrentTimer;       /*!< internal timer (scaled by HEADSpmTimeScale) that counts the time      @unit [ms], @range [0,@ref HEADTimeMax]*/  
  uint8                bitCheckType;         /*!< type of the rule (defined by the following bits: 
                                             SOOOFFDD where S is eHEADSPMCheckBitsSignal_t, o is eHEADSPMCheckBitsOp_t, F is eHEADSPMCheckBitsFunction_t, D is eHEADSPMCheckBitsStdDeviation_t */
  HEADModuleQoS_t      eQOS;                 /*!< target QoS value @range @ref eHEADModuleQoS_t*/
  HEADModuleRepError_t eReportedError;       /*!< defines the error that should be reported     @range @ref eHEADModuleRepError_t*/
} HEADSPMCheck_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Stores all the HEAD SPM check rules
    */
typedef struct 
{
  uint32           uiNrOfSPMRules;            /*!< total number of HEAD SPM rules */
  HEADSPMCheck_t  *rgSPMRules;                /*!< pointer to the HEAD SPM rules */
} HEADSPMRules_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Structure to Define a particular HEAD SPM rule to MTS
    */
typedef struct  
{
  uint32                         bitModules;            /*!< bits that defines which modules are affected by this rule @unit:bits*/
  float32                        fValue;                /*!< parameter value */ 
  uint32                         uiNrOfRules;           /*!< number of SPM rules */
  uint16                         uiNeededTime;          /*!< Defines how long the condition need to be true to change the QoS/Error. @unit[ms], @range [0,@ref HEADTimeMax]*/
  HEADSPMCheckBitsSignal_t       eSignalOrSigStat;      /*!< Define whether the signal or its state needs to be checke @unit:sigstate|sig */
  HEADSPMCheckBitsOp_t           eOperator;             /*!< Define which operator to use for the HEAD signal operation (eq | !eq | sm | smeq | gr | greq)  @unit:eq|!eq|sm|smeq|gr|greq*/
  HEADSPMCheckBitsFunction_t     eFunction;             /*!< Define how the HEAD module signal to be used by the function (no | abs) @unit:no|abs */
  HEADSPMCheckBitsStdDeviation_t eStdDevType;           /*!< Define the HEAD module signal for standard deviation (no | plus | minus) @unit:no|plus|minus */
  HEADModuleQoS_t                eQOS;                  /*!< target QoS value (stop | shutdown | keep | running) @unit:stop|shutdown|keep|running */
  HEADModuleRepError_t           eReportedError;        /*!< defines the error that should be reported (crit | norm | silent | no) @unit:crit|norm|silent|no */
  uint8                          uiRuleNr;              /*!< HEAD SPM rule number */
  uint8                          uiInSigIdent;          /*!< Identity of the input signal */
} HEADMTSSPMRule_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEAD SPM Timer

    @description    Structure to Holds the current timer of each HEAD SPM rule
    */
typedef struct  
{
  uint16 rguiTime[HEADMTSSPMRulesMax];  /*!< holds the current timer of each SPM rule -> index is the same as SPM rule index @unit [ms]*/
} HEADMTSSPMTimers_t;


/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
extern eGDBError_t HEADSPMAddSigCheck(const HEADSPMRules_t *pRules, uint32 uiRuleNr, struct HEADInputValue_t *pSignal,
                                      HEADMTSInSigIdent_t eHEADMTSInSigIdent, eHEADSPMCheckBitsSignal_t eCheckSignal,
                                      eHEADSPMCheckBitsOp_t eCheckOperator, eHEADSPMCheckBitsFunction_t eCheckFunction,
                                      eHEADSPMCheckBitsStdDeviation_t eCheckStdDev, float32 fValue, float32 fNeededTime,
                                      uint32 bitModules, eHEADModuleQoS_t eDesiredQoS, eHEADModuleRepError_t eReportedError);
extern eGDBError_t HEADSPMRunCheck(const HEADSPMRules_t *pRules, const HEADModuleList_t *pModuleList, float32 fCycleTime);

/* Deactivate QA-C warning 3406; Reviewer: Veerashettappa.Nagaraja; Date: 06.07.2018;  
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/*!  @cond Doxygen_Suppress */
ALGO_INLINE HEADSPMCheck_t *HEADSPMGetRule(HEADSPMCheck_t rgSPMRules[], uint32 no);
/*! @endcond */

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/*!  @cond Doxygen_Suppress */
/*************************************************************************************************************************
  Functionname:         HEADSPMGetRule                                                                              */ /*!

  @brief                Return a SPM Rule 

  @description          Return a SPM Rule correspond to the Rule number passed as an Input.

  @return               HEADSPMCheck_t :  pointer to a SPM Rule 

  @param[in]            rgSPMRules : HEAD SPM rules array
  @param[in]            no : SPM Rule number
  
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
ALGO_INLINE HEADSPMCheck_t *HEADSPMGetRule(HEADSPMCheck_t rgSPMRules[], uint32 no)
{
  return &(rgSPMRules[no]); 
}
/*! @endcond */

/*** END OF SINLGE INCLUDE SECTION ******************************************/

/*! @cond */
#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
/*! @endcond */
/* PRQA L:ALGO_INLINES */

#endif /* HEAD_SPM_H_INCLUDED */
/**@}*/

