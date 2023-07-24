/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_types.h

DESCRIPTION:               MEDIC Component version header file

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/12/04 08:02:41CET $

VERSION:                   $Revision: 1.67 $

**************************************************************************** */

#ifndef MEDIC_TYPES_H_INCLUDED
#define MEDIC_TYPES_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#if(MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)

/* PRQA S 3332 EOF */ /* Reviewer: Rashmi Ramachandra, Reason:switches will be defined based on project needs and can take default values as zero*/
/*****************************************************************************
  MACROS
*****************************************************************************/
/* MACROS (GLOBAL) */
#ifndef SET_MEMSEC_VAR_A
#define SET_MEMSEC_VAR_A(v)
#endif
#ifndef SET_MEMSEC_VAR
#define SET_MEMSEC_VAR(v)
#endif
#ifndef SET_MEMSEC_CONST_A
#define SET_MEMSEC_CONST_A(v)
#endif
#ifndef SET_MEMSEC_CONST
#define SET_MEMSEC_CONST(v)
#endif
#ifndef MEMSEC_REF
#define MEMSEC_REF
#endif

#ifndef MAX_NUM_OF_HYPS
#define MAX_NUM_OF_HYPS ACDC2_MAX_NUM_OF_HYPS
#endif

#ifdef PRQA_SIZE_T
  /* date: 2019-05-23, reviewer: C. Schnurr, reason: Assert is assumed to be redundant in non-debug mode*/
  #pragma PRQA_MACRO_MESSAGES_OFF "MEDIC_ASSERT" 3112
#endif /* #if def PRQA_SIZE_T */

#define MEDIC_ASSERT(x) CML_ASSERT(x)

#define MEDIC_STATIC_ASSERT(x) GA_assert(x)


/*! Makros for declaration and definition of TP application parameters
    @description:

    TP_DECL_ADJ_PARAM : use in <sub-comp>_par.h file to DECLARE a     "adjustable" parameter in RAM
    TP_DECL_FIX_PARAM : use in <sub-comp>_par.h file to DECLARE a "NOT adjustable" parameter in ROM
      usage:
            \#define <sub-comp>_PARAM_NAME   <sub-comp>_PARAM_NAME_c      // ( \#define parameter name and map it to variable
                                                                         //   in code only name of parameter is used, NOT variable name (_c)
            TP_DECL_FIX_PARAM( [type],      <sub-comp>_PARAM_NAME_c )    // ( declaration of fix/adjustable parameter )

    TP_DEF_ADJ_PARAM : use in <sub-comp>_par.c file to DEFINE a     "adjustable" parameter in RAM
    TP_DEF_FIX_PARAM : use in <sub-comp>_par.c file to DEFINE a "NOT adjustable" parameter in ROM
      usage:
            TP_DEF_FIX_PARAM( [type] , <sub-comp>_PARAM_NAME_c , <value> )

     notice: declaration AND definition must be of same type (data type and FIX/ADJ)!!*/

/*PRQA S 3410, 3412 8*//* see description above */
#define MEDIC_DECL_ADJ_PARAM(type_, name_)       extern       type_ name_;
/*! alias for not changable parameters, see FCT_DECL_ADJ_PARAM */
#define MEDIC_DECL_FIX_PARAM(type_, name_)       extern const type_ name_;

/*! alias for changable parameters, see FCT_DECL_ADJ_PARAM */
#define MEDIC_DEF_ADJ_PARAM(type_, name_, value_)             type_ name_ = (value_);
/*! alias for not changable parameters, see FCT_DECL_ADJ_PARAM */
#define MEDIC_DEF_FIX_PARAM(type_, name_, value_)       const type_ name_ = (value_);

#if (defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor))
  #define MEDIC_MEAS_FUNC_ID        TASK_ID_ALGO_VEH_CYCLE
  #define MEDIC_MEAS_FUNC_CHAN_ID   20u
#else
  #define MEDIC_MEAS_FUNC_ID        TASK_ID_FCT
  #define MEDIC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT
#endif

#if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
#define MEDIC_FREEZE_DATA(pInfo, pData, Callback)        (MEDIC_p_GetServiceFuncts()->pfMeasFreeze)((pInfo), (pData), (Callback))
#else
#define MEDIC_FREEZE_DATA(pInfo, pData, Callback)         MEASFreezeDataMTS((pInfo), (pData), (Callback))
#endif

//
/*******************************/
/*! Component states           */
/*******************************/
#ifndef COMP_STATE_NOT_INITIALIZED
#define COMP_STATE_NOT_INITIALIZED          (0u)
#endif
#ifndef COMP_STATE_RUNNING
#define COMP_STATE_RUNNING                  (1u)
#endif
#ifndef COMP_STATE_TEMPORARY_ERROR
#define COMP_STATE_TEMPORARY_ERROR          (2u)
#endif
#ifndef COMP_STATE_PERMANENT_ERROR
#define COMP_STATE_PERMANENT_ERROR          (3u)
#endif
#ifndef COMP_STATE_SUCCESS
#define COMP_STATE_SUCCESS                  (4u)
#endif
#ifndef COMP_STATE_REDUCED_AVAILABILITY
#define COMP_STATE_REDUCED_AVAILABILITY     (5u)
#endif
#ifndef COMP_STATE_NOT_RUNNING
#define COMP_STATE_NOT_RUNNING              (6u)
#endif

#ifndef ALGO_INLINE
/* Defines for inlining functions*/
#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */
/*! microsoft compliler -> simulation*/
#define ALGO_INLINE  __inline
#elif (defined(__POWERPC__) && defined(__MWERKS__))               /* Freescale Metrowerks compiler for PowerPC-ECUs -> code only for ECU */
/*! Freescale compiler use inline*/
#define ALGO_INLINE  inline
#elif (defined(__ghs__))                                          /* Greenhills compiler */
/*! Greenhills compoiler use inline*/
#define ALGO_INLINE inline
#elif (defined(__ARP32__)) || (defined(__TI_ARM__)) || (defined(_TMS320C6X))
/*! TI compiler use inline*/
#define ALGO_INLINE inline
#elif (defined(__GNUC__))
/*! GNU compiler use inline*/
#define ALGO_INLINE inline
#elif (defined(__ARMCC_VERSION))                                  /* ARMCLANG Compiler */
/*! ARM compiler use static inline*/
#define ALGO_INLINE static inline
#elif (defined(__STDC_VERSION__))
#if (__STDC_VERSION__ >= 199901) /* C99 compatible compiler has to have inline keyword with proper non-extern linkage */
/*! C99 compiler use inline*/
#define ALGO_INLINE inline
#else
#define ALGO_INLINE static
#endif
#else  /* unknown compiler -> no INLINE */
/*! unknown compiler NO inlining*/
#define ALGO_INLINE static
#endif
#endif

#if (MEDIC_CFG_SENSOR_TYPE_CAMERA)
/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
typedef sint32  sbit32_t;
typedef sint16  sbit16_t;
typedef sint8   sbit8_t;
typedef ubit32  ubit32_t;
typedef uint16  ubit16_t;
typedef uint8   ubit8_t;
#endif

#endif /*(FCT_CFG_SENSOR_TYPE_CAMERA)*/

#if ((!defined FCT_TYPES_H) || (MEDIC_ARCHITECTURE_VERSION >= 0x10))
/*! @brief    struct to store update information of one interface.*/
typedef struct
{
  AlgoDataTimeStamp_t uiTimeStamp;            /*!<Last time stamp */
  uint8               uiLastUpdateCounter;    /*!<number of calling cycles without updated timestamp in interface*/
} sMeasCycleMonitor;

/*! enum to define labels for driver monitoring Hypothesis types */
typedef enum
{
  DIMHypoType_No               = 0u,      /*!< empty hypothesis*/
  DIMHypoType_Feedback         = 1u,      /*!< driver feedback - value -100: strong negative feedback, +100 strong positive feedback*/
  DIMHypoType_Activity         = 2u,      /*!< driver activity - value 0: no activity, 100: high activity*/
  DIMHypoType_Attention        = 3u,      /*!< driver attention - value -100: distracted, +100: high attention*/
  DIMHypoType_Tiredness        = 4u,     /*!< driver tiredness value - value 100 - very tired, 0 - not tired*/
  DIMHypoType_LaneChangeLeft   = 5u,      /*!< driver wants to change the lane to the left - value 0: no lane change, 100: high probability*/
  DIMHypoType_LaneChangeRight  = 6u,      /*!< driver wants to change the lane to the right - value 0: no lane change, 100: high probability*/
  DIMHypoType_Drowsieness      = 7u,      /*!< driver is drowsy: 0: low probability, 100: high probability*/
  DIMHypoType_Overtake         = 8u,      /*!< driver plans to overtake: 0: driver will not overtake, driver will overtake*/
  DIMHypoType_Distraction      = 9u,      /*!< driver distraction - value 0: no distraction, 100: high distraction*/
  DIMHypoType_SportStyle       = 10u,      /*!< driver sportstyle - value 0: no sportstyle, 100: high sportstyle*/
  DIMHypoType_LaneChange       = 11u,     /*!< driver changes lane - value -100: langange left, 0: no lanechange, 100: langange right*/
  DIMHypoType_Max              = 12u      /*!< counter for the enum*/
} eDIMHypoType_t;

/*! Error type, currently only used by CD @todo: TBD if needed on global level */
typedef enum
{
  GDB_ERROR_NONE               = 0u,   /*!< no error*/
  GDB_ERROR_POINTER_NULL       = 1u,   /*!< null pointer error*/
  GDB_ERROR_FUNC_POINTER_NULL  = 2u,   /*!< null function pointer error*/
  GDB_ERROR_CAST_VALUE_TO_HIGH = 3u,   /*!< while casting a variable, the value would be truncated because it was to high (example (signed char)200)*/
  GDB_ERROR_CAST_VALUE_TO_LOW  = 4u,   /*!< while casting a variable, the value would be truncated because it was to low  (example (signed char)-200)*/
  GDB_ERROR_UNKNOWN_TYPE       = 5u,   /*!< enum type handling unknown*/
  GDB_ERROR_FILTER_DOESNT_MATCH= 6u,   /*!< a filter function doesn't match any result*/
  GDB_ERROR_LOW_QUALITY        = 7u,   /*!< at least one signal didn't have a sufficient quality*/
  GDB_ERROR_ARRAY_OVERFLOW     = 8u,   /*!< the array index is out of bounds*/
  GDB_ERROR_ZERO_DEVISION      = 9u,   /*!< Devision by Zero requested*/
  GDB_ERROR_VALUE_RANGE        = 10u,  /*!< a value is outside expeccted range */
  GDB_ERROR_ARRAY_SIZE_TOO_LOW = 11u   /*!< array size is too small */
} eGDBError_t;

/*! typedef for CD hypothesis data */
typedef struct
{
  sint8                      Probability;          /*!< -100 -> +100%*/
  percentage_t               Confidence;           /*!< hypothesis confidence*/
  eDIMHypoType_t             eType;                /*!< type of the hypothesis (see eDIMHypoType_t)*/
  eGDBError_t                eGDBError;            /*!< error type (GDB_ERROR_NONE if module processing was OK) */
} GDB_DMHypothesis_t;
#endif

typedef struct
{
  boolean bRequirePortsNull;         // The received pointer to MEDIC Request Ports is NULL
  boolean bProvidePortsNull;         // The received pointer to MEDIC Provide Ports is NULL
  boolean bProcMemNull;              // The received pointer to MEDIC Process Memory is NULL
  boolean bServicesNull;             // The received pointer to MEDIC Services is NULL
  boolean bControlDataNull;          // The received pointer to MEDIC_ControlData is NULL
  boolean bEgoMotionNull;            // The received pointer to CEM_EgoVehicleKinematics is NULL
  #if (MEDIC_CFG_USE_VDY)
  boolean bVehDyn_InNull;            // The received pointer to VehDyn_In is NULL
  #endif
  boolean bVehSigNull;               // The received pointer to VehSig_t is NULL
  boolean bHypothesisNull;           // The received pointer to ACDC2_HypothesisIntf is NULL
  boolean bEvasionTargetsNull;       // The received pointer to ACDC2_EvasionTargets is NULL
  boolean bBrakeTargetsNull;         // The received pointer to ACDC2_BrakeTargets is NULL
  boolean bDegradationNull;          // The received pointer to ACDC2_Degradation is NULL
  boolean bSwitchesNull;             // The received pointer to MEDIC_t_Switches is NULL
  boolean bVehicleNull;              // The received pointer to MEDIC_t_Vehicle is NULL
  boolean bDriverMonitorNull;        // The received pointer to MEDIC_t_DriverMonitor is NULL
  boolean bQualifiersNull;           // The received pointer to MEDIC_t_Qualifiers is NULL
  #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
  #if ((defined(CFG_MEDIC_IN_TOYOTA)) && (CFG_MEDIC_IN_TOYOTA == 1))
  boolean bCustomInputTMCNull;       // The received pointer to customInput_TMC is NULL
  #endif
  #if ((defined(CFG_MEDIC_IN_BMW)) && (CFG_MEDIC_IN_BMW == 1))
  boolean bCustomInputBMWNull;       // The received pointer to customInput_BMW is NULL
  #if(MEDIC_CFG_CAM_AEB == MEDIC_ON)
  boolean bCamAEBNull;               // The received pointer to camAEB is NULL
  #endif //MEDIC_CFG_CAM_AEB
  #endif
  #endif
  boolean bloggingInfoNull;              // The received pointer to bloggingInfoNull is NULL
  boolean bMedicParametersNull;          // The received pointer to Medic_t_Parameters is NULL
  boolean bEbaStateControlNull;          // The received pointer to MEDIC_t_EBAStateControl is NULL
  boolean bInterSizeTooSmall;            // The memory size for InterCycle     memory is too small
  boolean bInterMeasSizeTooSmall;        // The memory size for InterCycleMeas memory is too small
  boolean bIntraMeasSizeTooSmall;        // The memory size for IntraCycleMeas memory is too small
  boolean bInterCyleNull;                // Pointer to InterCycle memory is NULL
  boolean bInterCyleMeasNull;            // Pointer to InterCycleMeas memory is NULL
  boolean bIntraCyleMeasNull;            // Pointer to IntraCycleMeas memory is NULL
  boolean bStackDataNull;                // Pointer to Stack memory is NULL
  boolean bCodingParametersNotValid;     // Coding Parameters are not valid or have an invalid signal header
  boolean bAllCodingParameterValuesNull; // All Coding Parameter values are 0
  boolean bAllEBAStateControlValuesNull; // All EBAStateControl values are 0
  uint32  uiReqPortsNotInitialized;      // Request Ports that are currently in INIT  (BIT0 = Port0, BIT1 = Port1, etc ....)
  uint32  uiReqPortsError;               // Request Ports that are currently in ERROR (BIT0 = Port0, BIT1 = Port1, etc ....)
  sint32  iDataAge;                      // Age of Data compared to last algo call (should be the cycle time)
} MEDIC_Diagnostic_t;

/*! @brief FCT sub-component version stucture */
typedef struct
{
  #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  uint32 uiHEAD;                   /*!< SW version of HEAD            @range:0 to 65535     */
  #endif
  #if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
  uint32 uiDIM;                    /*!< SW version of DIM             @range:0 to 65535     */
  #endif
  #ifdef __PDO__
  uint32 MEDIC_VERSION_AS_TEXT;
  #else
  uint32 MEDICSwVersionNumVar;     /*!< SW version of MEDIC as number @range:0 to 65535     */
  #endif
  uint8  uiMedicReleaseClient;     /*!< Release Client to identify intermediate checkpoints */
  uint32 uiMedic;                  /*!< SW version of MEDIC           @range:0 to 65535     */
  uint32 uiProjectID;              /*!< ID of the current project     @range:0 to 65535     */
} MEDICVersions_t;

/*! @brief       MAX NUMBER OF CD Hypothesis
    @general     MAX NUMBER OF CD Hypothesis
    @typical     MAX_NUM_OF_HYPS
 */
#define HEAD_MAX_NUMBER_OF_CD_HYPS ((uint32)MAX_NUM_OF_HYPS)


/*! @brief Data type to store HEAD Hypothesis
 */
typedef struct
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  const Hypothesis_t     *pHypothesis;               /*!< pointer to the hypothesis*/
  #else
  const ACDC2_Hypothesis *pHypothesis;               /*!< pointer to the hypothesis*/
  #endif
} HEADHypothesis_t;

/*! @brief Array of Head hypothesis, Size of array is HEAD_MAX_NUMBER_OF_CD_HYPS ( 12 )
*/
typedef HEADHypothesis_t HEADHypothesisList_t[HEAD_MAX_NUMBER_OF_CD_HYPS];

// -----------------------------------------------------------------------------
// Interface mapping between old and new architecture (before and after FSF.500)
// -----------------------------------------------------------------------------
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)

#ifndef t_EBACodingParamFctModsIdx
typedef uint8 t_EBACodingParamFctModsIdx;
#endif

#define eEBAFctChan_Pedestrian      medic_eEBAFctChan_Pedestrian
#define eEBAFctChan_Cyclist         medic_eEBAFctChan_Cyclist
#define eEBAFctChan_Vehicle         medic_eEBAFctChan_Vehicle
#define eEBAFctChan_Crossing        medic_eEBAFctChan_Crossing
#define eEBAFctChan_DrvIntoOncoming medic_eEBAFctChan_DrvIntoOncoming
#define eEBAFctChan_HeadOn          medic_eEBAFctChan_HeadOn
#define eEBAFctChan_Unclassified    medic_eEBAFctChan_Unclassified
#define eEBAFctChan_Unknown         medic_eEBAFctChan_Unknown

#ifndef HEADOutCustHypReactions_t
typedef MEDIC_aHyps HEADOutCustHypReactions_t;
#endif

#ifndef eFunctionSwitch_t
typedef MEDIC_eFunctionSwitch eFunctionSwitch_t;
#define eEBASwitch_LongVehDW    medic_eEBASwitch_LongVehDW
#define eEBASwitch_LongVehFCW1  medic_eEBASwitch_LongVehFCW1
#define eEBASwitch_LongVehFCW2  medic_eEBASwitch_LongVehFCW2
#define eEBASwitch_LongVehFCW3  medic_eEBASwitch_LongVehFCW3
#define eEBASwitch_LongVehBRK   medic_eEBASwitch_LongVehBRK
#define eEBASwitch_LongVruDW    medic_eEBASwitch_LongVruDW
#define eEBASwitch_LongVruFCW1  medic_eEBASwitch_LongVruFCW1
#define eEBASwitch_LongVruFCW2  medic_eEBASwitch_LongVruFCW2
#define eEBASwitch_LongVruFCW3  medic_eEBASwitch_LongVruFCW3
#define eEBASwitch_LongVruBRK   medic_eEBASwitch_LongVruBRK
#define eEBASwitch_CrossVehDW   medic_eEBASwitch_CrossVehDW
#define eEBASwitch_CrossVehFCW1 medic_eEBASwitch_CrossVehFCW1
#define eEBASwitch_CrossVehFCW2 medic_eEBASwitch_CrossVehFCW2
#define eEBASwitch_CrossVehFCW3 medic_eEBASwitch_CrossVehFCW3
#define eEBASwitch_CrossVehBRK  medic_eEBASwitch_CrossVehBRK
#define eEBASwitch_CrossVruDW   medic_eEBASwitch_CrossVruDW
#define eEBASwitch_CrossVruFCW1 medic_eEBASwitch_CrossVruFCW1
#define eEBASwitch_CrossVruFCW2 medic_eEBASwitch_CrossVruFCW2
#define eEBASwitch_CrossVruFCW3 medic_eEBASwitch_CrossVruFCW3
#define eEBASwitch_CrossVruBRK  medic_eEBASwitch_CrossVruBRK
#define eEBASwitch_OncVehDW     medic_eEBASwitch_OncVehDW
#define eEBASwitch_OncVehFCW1   medic_eEBASwitch_OncVehFCW1
#define eEBASwitch_OncVehFCW2   medic_eEBASwitch_OncVehFCW2
#define eEBASwitch_OncVehFCW3   medic_eEBASwitch_OncVehFCW3
#define eEBASwitch_OncVehBRK    medic_eEBASwitch_OncVehBRK
#define eEBASwitch_OncVruDW     medic_eEBASwitch_OncVruDW
#define eEBASwitch_OncVruFCW1   medic_eEBASwitch_OncVruFCW1
#define eEBASwitch_OncVruFCW2   medic_eEBASwitch_OncVruFCW2
#define eEBASwitch_OncVruFCW3   medic_eEBASwitch_OncVruFCW3
#define eEBASwitch_OncVruBRK    medic_eEBASwitch_OncVruBRK
#endif

#ifndef eMainSwitch_t
typedef MEDIC_eMainSwitch eMainSwitch_t;
#define eMainSwitch_Inactive    medic_eMainSwitch_Inactive
#define eMainSwitch_Active      medic_eMainSwitch_Active
#define eMainSwitch_NotUsed     medic_eMainSwitch_NotUsed
#define eMainSwitch_Invalid     medic_eMainSwitch_Invalid
#endif

#ifndef eEBADynProp_t
typedef t_DynProp eEBADynProp_t;
#define EBADynProp_NotAvail             acdc2_DynPropNotAvail
#define EBADynProp_Mov                  acdc2_DynPropMov
#define EBADynProp_Stat                 acdc2_DynPropStat
#define EBADynProp_Stop                 acdc2_DynPropStop
#endif

#ifndef eEBAObjMovDir_t
typedef t_MovDir eEBAObjMovDir_t;
#define EBAObjMovDir_DoT                acdc2_MovDir_DoT 
#define EBAObjMovDir_Cross              acdc2_MovDir_Cross
#define EBAObjMovDir_Onco               acdc2_MovDir_Onco
#define EBAObjMovDir_CrossToLeft        acdc2_MovDir_CrossToLeft 
#define EBAObjMovDir_CrossToRight       acdc2_MovDir_CrossToRight 
#endif

#ifndef eEBAObjectClass_t
typedef t_ItemClass eEBAObjectClass_t;
#define EBAObjectClass_NotAvail         acdc2_ClassNotAvail
#define EBAObjectClass_Pedestrian       acdc2_ClassPedestrian
#define EBAObjectClass_Vehicle          acdc2_ClassVehicle
#define EBAObjectClass_Obstacle         acdc2_ClassObstacle
#define EBAObjectClass_Cyclist          acdc2_ClassCyclist
#endif

#define eFCT_STATE_SIG_INACTIVE         medic_eFCT_STATE_SIG_INACTIVE
#define eFCT_STATE_SIG_ACTIVE           medic_eFCT_STATE_SIG_ACTIVE
#define eFCT_STATE_SIG_INVALID          medic_eFCT_STATE_SIG_INVALID

#define DIMInputSignalState_OK          medic_DIMInputSignalState_OK
#define DIMInputSignalState_Default     medic_DIMInputSignalState_Default
#define DIMInputSignalState_Missing     medic_DIMInputSignalState_Missing
#define DIMInputSignalState_BadQuality  medic_DIMInputSignalState_BadQuality
#define DIMInputSignalState_Suspicious  medic_DIMInputSignalState_Suspicious

#define eStatus_FCW_Coded               medic_eStatus_FCW_Coded
#define eStatus_FCW_Switched            medic_eStatus_FCW_Switched
#define eStatus_FCW_NoError             medic_eStatus_FCW_NoError
#define eStatus_FCW_NoDegraded          medic_eStatus_FCW_NoDegraded
#define eStatus_AutoBrk_Coded           medic_eStatus_AutoBrk_Coded
#define eStatus_AutoBrk_Switched        medic_eStatus_AutoBrk_Switched
#define eStatus_AutoBrk_NoError         medic_eStatus_AutoBrk_NoError
#define eStatus_AutoBrk_NoDegraded      medic_eStatus_AutoBrk_NoDegraded
#define eStatus_DistWarn_Coded          medic_eStatus_DistWarn_Coded
#define eStatus_DistWarn_Switched       medic_eStatus_DistWarn_Switched
#define eStatus_DistWarn_NoError        medic_eStatus_DistWarn_NoError
#define eStatus_DistWarn_NoDegraded     medic_eStatus_DistWarn_NoDegraded
#define eStatus_BrakeAssist_Coded       medic_eStatus_BrakeAssist_Coded
#define eStatus_BrakeAssist_Switched    medic_eStatus_BrakeAssist_Switched
#define eStatus_BrakeAssist_NoError     medic_eStatus_BrakeAssist_NoError
#define eStatus_BrakeAssist_NoDegraded  medic_eStatus_BrakeAssist_NoDegraded
#define eStatus_BrakePreCond_Coded      medic_eStatus_BrakePreCond_Coded
#define eStatus_BrakePreCond_Switched   medic_eStatus_BrakePreCond_Switched
#define eStatus_BrakePreCond_NoError    medic_eStatus_BrakePreCond_NoError
#define eStatus_BrakePreCond_NoDegraded medic_eStatus_BrakePreCond_NoDegraded
#define eStatus_OccSafety_Coded         medic_eStatus_OccSafety_Coded
#define eStatus_OccSafety_Switched      medic_eStatus_OccSafety_Switched
#define eStatus_OccSafety_NoError       medic_eStatus_OccSafety_NoError
#define eStatus_OccSafety_NoDegraded    medic_eStatus_OccSafety_NoDegraded
#define eStatus_Spare1_Coded            medic_eStatus_Spare1_Coded
#define eStatus_Spare1_Switched         medic_eStatus_Spare1_Switched
#define eStatus_Spare1_NoErro           medic_eStatus_Spare1_NoError
#define eStatus_Spare1_NoDegraded       medic_eStatus_Spare1_NoDegraded
#define eStatus_Spare2_Coded            medic_eStatus_Spare2_Coded
#define eStatus_Spare2_Switched         medic_eStatus_Spare2_Switched
#define eStatus_Spare2_NoError          medic_eStatus_Spare2_NoError
#define eStatus_Spare2_NoDegraded       medic_eStatus_Spare2_NoDegraded

#ifndef CDHypothesisType_No
typedef t_HypothesisType eCDHypothesisType_t;
#define CDHypothesisType_No                   acdc2_HypTypeNone
#define CDHypothesisType_RunUp                acdc2_HypTypeLong
#define CDHypothesisType_RunUpBraking         acdc2_HypTypeLongBraking
#define CDHypothesisType_Crossing             acdc2_HypTypeCrossing
#define CDHypothesisType_Collision            acdc2_HypTypeCollision
#define CDHypothesisType_Turning              acdc2_HypTypeEgoTurnInto
#define CDHypothesisType_DriveOff             acdc2_HypTypeEgoAccelInto
#define acdc_HypTypeCrossing                  acdc2_HypTypeCrossing
#define acdc_HypTypeLong                      acdc2_HypTypeLong 
#define acdc_HypTypeLongBraking               acdc2_HypTypeLongBraking
#define acdc_HypTypeEgoTurnInto               acdc2_HypTypeEgoTurnInto
#define acdc_HypTypeOnc                       acdc2_HypTypeOnc
#endif

#define eEBAOn_Inactive                       medic_eEBAOn_Inactive
#define eEBAOn_Moving                         medic_eEBAOn_Moving
#define eEBAOn_Standing                       medic_eEBAOn_Standing
#define eEBAOn_Halted                         medic_eEBAOn_Halted
#define eEBAOn_CrossFrLeft                    medic_eEBAOn_CrossFrLeft
#define eEBAOn_CrossFrRight                   medic_eEBAOn_CrossFrRight
#define eEBAOn_Oncoming                       medic_eEBAOn_Oncoming

#ifndef EBACodingParamGen_t
typedef MEDIC_CodingParamGen EBACodingParamGen_t;
#endif

#ifndef EBACodingParamCustom_t
typedef MEDIC_CodingParamCustom EBACodingParamCustom_t;
#endif

#define EBA_CODING_GEN_LOW_SPEED          medic_CODING_GEN_LOW_SPEED
#define EBA_CODING_GEN_COUNTRY_A          medic_CODING_GEN_COUNTRY_A
#define EBA_CODING_GEN_COUNTRY_B          medic_CODING_GEN_COUNTRY_B
#define EBA_CODING_GEN_IGNR_SFTY_CHCKS    medic_CODING_GEN_IGNR_SFTY_CHCKS
#define EBA_CODING_GEN_DEBUGMESSAGES      medic_CODING_GEN_DEBUGMESSAGES
#define EBA_CODING_GEN_DISTANCELIMIT      medic_CODING_GEN_DISTANCELIMIT
#define EBA_CODING_GEN_DRIVER_SET_CODING  medic_CODING_GEN_DRIVER_SET_CODING
#define EBA_CODING_GEN_IGNORE_ACT_SWITCH  medic_CODING_GEN_IGNORE_ACT_SWITCH

#define EBA_CODING_BIT_PRECRASH   medic_CODING_BIT_PRECRASH
#define EBA_CODING_BIT_PREFILL1   medic_CODING_BIT_PREFILL1
#define EBA_CODING_BIT_PREFILL2   medic_CODING_BIT_PREFILL2
#define EBA_CODING_BIT_HBA1       medic_CODING_BIT_HBA1
#define EBA_CODING_BIT_HBA2       medic_CODING_BIT_HBA2
#define EBA_CODING_BIT_AUTOBRK1   medic_CODING_BIT_AUTOBRK1
#define EBA_CODING_BIT_AUTOBRK2   medic_CODING_BIT_AUTOBRK2
#define EBA_CODING_BIT_AUTOBRK3   medic_CODING_BIT_AUTOBRK3
#define EBA_CODING_BIT_DYN_WARN1  medic_CODING_BIT_DYN_WARN1
#define EBA_CODING_BIT_DYN_WARN2  medic_CODING_BIT_DYN_WARN2
#define EBA_CODING_BIT_DYN_WARN3  medic_CODING_BIT_DYN_WARN3
#define EBA_CODING_BIT_DIST_WARN1 medic_CODING_BIT_DIST_WARN1
#define EBA_CODING_BIT_DIST_WARN2 medic_CODING_BIT_DIST_WARN2
#define EBA_CODING_BIT_SPARE1     medic_CODING_BIT_SPARE1
#define EBA_CODING_BIT_SPARE2     medic_CODING_BIT_SPARE2
#define EBA_CODING_BIT_SPARE3     medic_CODING_BIT_SPARE3

#define EBA_STATE_BIT_PRECRASH     medic_CODING_BIT_PRECRASH
#define EBA_STATE_BIT_PREFILL1     medic_CODING_BIT_PREFILL1
#define EBA_STATE_BIT_PREFILL2     medic_CODING_BIT_PREFILL2
#define EBA_STATE_BIT_HBA1         medic_CODING_BIT_HBA1
#define EBA_STATE_BIT_HBA2         medic_CODING_BIT_HBA2
#define EBA_STATE_BIT_AUTOBRK1     medic_CODING_BIT_AUTOBRK1
#define EBA_STATE_BIT_AUTOBRK2     medic_CODING_BIT_AUTOBRK2
#define EBA_STATE_BIT_AUTOBRK3     medic_CODING_BIT_AUTOBRK3
#define EBA_STATE_BIT_DYN_WARN1    medic_CODING_BIT_DYN_WARN1
#define EBA_STATE_BIT_DYN_WARN2    medic_CODING_BIT_DYN_WARN2
#define EBA_STATE_BIT_DYN_WARN3    medic_CODING_BIT_DYN_WARN3
#define EBA_STATE_BIT_DIST_WARN1   medic_CODING_BIT_DIST_WARN1
#define EBA_STATE_BIT_DIST_WARN2   medic_CODING_BIT_DIST_WARN2

#define eEBAGenerator_No           medic_eEBAGenerator_No
#define eEBAGenerator_KeepVoltage  medic_eEBAGenerator_KeepVoltage
#define eEBAGenerator_BoostVoltage medic_eEBAGenerator_BoostVoltage

#define eEBAObjRelNo               medic_eEBAObjRelNo
#define eEBAObjRelHyp              medic_eEBAObjRelHyp
#define eEBAObjRelFctMod           medic_eEBAObjRelFctMod

#define eDriverSetting_Early       medic_eDriverSetting_Early
#define eDriverSetting_Middle      medic_eDriverSetting_Middle
#define eDriverSetting_Late        medic_eDriverSetting_Late
#define eDriverSetting_Invalid     medic_eDriverSetting_Invalid

#ifndef eTurnIndicator_t
typedef MEDIC_eTurnIndicator eTurnIndicator_t;
#define eTurnIndicator_Off         medic_eTurnIndicator_Off
#define eTurnIndicator_Left        medic_eTurnIndicator_Left
#define eTurnIndicator_Right       medic_eTurnIndicator_Right
#define eTurnIndicator_Both        medic_eTurnIndicator_Both
#define eTurnIndicator_Invalid     medic_eTurnIndicator_Invalid
#endif

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
#define eEBACodingIdx_LongVehMov     (0u)
#define eEBACodingIdx_LongVehStat    (1u)
#define eEBACodingIdx_LongPedMov     (2u)
#define eEBACodingIdx_LongPedStat    (3u)
#define eEBACodingIdx_LongCyclMov    (4u)
#define eEBACodingIdx_LongCyclStat   (5u)
#define eEBACodingIdx_LongObsMov     (6u)
#define eEBACodingIdx_LongObsStat    (7u)
#define eEBACodingIdx_CrossVehMov    (8u)
#define eEBACodingIdx_CrossVehStat   (9u)
#define eEBACodingIdx_CrossPedMov   (10u)
#define eEBACodingIdx_CrossPedStat  (11u)
#define eEBACodingIdx_CrossCyclMov  (12u)
#define eEBACodingIdx_CrossCyclStat (13u)
#define eEBACodingIdx_CrossObsMov   (14u)
#define eEBACodingIdx_CrossObsStat  (15u)
#define eEBACodingIdx_OncVehMov     (16u)
#define eEBACodingIdx_OncVehStat    (17u)
#define eEBACodingIdx_OncPedMov     (18u)
#define eEBACodingIdx_OncPedStat    (19u)
#define eEBACodingIdx_OncCyclMov    (20u)
#define eEBACodingIdx_OncCyclStat   (21u)
#define eEBACodingIdx_OncObsMov     (22u)
#define eEBACodingIdx_OncObsStat    (23u)

#else

#define eEBACodingIdx_MovVehStat     (0u)
#define eEBACodingIdx_MovVehCMov     (1u)
#define eEBACodingIdx_MovVehOnc      (2u)
#define eEBACodingIdx_MovVehCross    (3u)
#define eEBACodingIdx_MovPedStat     (4u)
#define eEBACodingIdx_MovPedCMov     (5u)
#define eEBACodingIdx_MovPedOnc      (6u)
#define eEBACodingIdx_MovPedCross    (7u)
#define eEBACodingIdx_MovBicStat     (8u)
#define eEBACodingIdx_MovBicCMov     (9u)
#define eEBACodingIdx_MovBicOnc      (10u)
#define eEBACodingIdx_MovBicCross    (11u)
#define eEBACodingIdx_MovPTWStat     (12u)
#define eEBACodingIdx_MovPTWCMov     (13u)
#define eEBACodingIdx_MovPTWOnc      (14u)
#define eEBACodingIdx_MovPTWCross    (15u)
#define eEBACodingIdx_MovUncStat     (16u)
#define eEBACodingIdx_MovUncCMov     (17u)
#define eEBACodingIdx_MovUncOnc      (18u)
#define eEBACodingIdx_MovUncCross    (19u)
#define eEBACodingIdx_TrngVehStat    (20u)
#define eEBACodingIdx_TrngVehCMov    (21u)
#define eEBACodingIdx_TrngVehOnc     (22u)
#define eEBACodingIdx_TrngVehCross   (23u)
#define eEBACodingIdx_TrngPedStat    (24u)
#define eEBACodingIdx_TrngPedCMov    (25u)
#define eEBACodingIdx_TrngPedOnc     (26u)
#define eEBACodingIdx_TrngPedCross   (27u)
#define eEBACodingIdx_TrngBicStat    (28u)
#define eEBACodingIdx_TrngBicCMov    (29u)
#define eEBACodingIdx_TrngBicOnc     (30u)
#define eEBACodingIdx_TrngBicCross   (31u)
#define eEBACodingIdx_TrngPTWStat    (32u)
#define eEBACodingIdx_TrngPTWCMov    (33u)
#define eEBACodingIdx_TrngPTWOnc     (34u)
#define eEBACodingIdx_TrngPTWCross   (35u)
#define eEBACodingIdx_TrngUncStat    (36u)
#define eEBACodingIdx_TrngUncCMov    (37u)
#define eEBACodingIdx_TrngUncOnc     (38u)
#define eEBACodingIdx_TrngUncCross   (39u)
#define eEBACodingIdx_DOffVehStat    (40u)
#define eEBACodingIdx_DOffVehCMov    (41u)
#define eEBACodingIdx_DOffVehOnc     (42u)
#define eEBACodingIdx_DOffVehCross   (43u)
#define eEBACodingIdx_DOffPedStat    (44u)
#define eEBACodingIdx_DOffPedCMov    (45u)
#define eEBACodingIdx_DOffPedOnc     (46u)
#define eEBACodingIdx_DOffPedCross   (47u)
#define eEBACodingIdx_DOffBicStat    (48u)
#define eEBACodingIdx_DOffBicCMov    (49u)
#define eEBACodingIdx_DOffBicOnc     (50u)
#define eEBACodingIdx_DOffBicCross   (51u)
#define eEBACodingIdx_DOffPTWStat    (52u)
#define eEBACodingIdx_DOffPTWCMov    (53u)
#define eEBACodingIdx_DOffPTWOnc     (54u)
#define eEBACodingIdx_DOffPTWCross   (55u)
#define eEBACodingIdx_DOffUncStat    (56u)
#define eEBACodingIdx_DOffUncCMov    (57u)
#define eEBACodingIdx_DOffUncOnc     (58u)
#define eEBACodingIdx_DOffUncCross   (59u)

#endif
/*! Set get macros for the vdy states */
#ifndef VDY_GET_IO_STATE
#ifdef __PDO__
#define VDY_GET_IO_STATE(pos_,val_)             0
#else
#define VDY_GET_IO_STATE(pos_,val_)            ((val_)[(pos_)])
#endif
#endif

#endif // (MEDIC ARCHITECTURE_VERSION >= 0x10)

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
typedef FCT_OP_MODE_t MEDICOpMode_t;
#define MEDIC_MOD_STARTUP  FCT_MOD_STARTUP
#define MEDIC_MOD_INIT     FCT_MOD_INIT
#define MEDIC_MOD_RUNNING  FCT_MOD_RUNNING
#define MEDIC_MOD_SHUTDOWN FCT_MOD_SHUTDOWN
#define MEDIC_MOD_PAUSE    FCT_MOD_PAUSE
#else
typedef MEDIC_OpMode MEDICOpMode_t;
#define MEDIC_MOD_STARTUP  medic_opModeReset
#define MEDIC_MOD_INIT     medic_opModeReset
#define MEDIC_MOD_RUNNING  medic_opModeNormal
#define MEDIC_MOD_SHUTDOWN medic_opModePause
#define MEDIC_MOD_PAUSE    medic_opModePause
#endif
#define MEDIC_MOD_UNDEFINED    (255u)

#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
#ifndef FPS_EBA_INH_NONE
#define FPS_EBA_INH_NONE       (0u)
#define FPS_EBA_INH_LAT_WARN   (1u)
#define FPS_EBA_INH_PRE_WARN   (2u)
#define FPS_EBA_INH_ACU_WARN   (4u)
#define FPS_EBA_INH_PRE_FILL   (8u)
#define FPS_EBA_INH_HBA_THRD   (16u)
#define FPS_EBA_INH_HBA_TBRK   (32u)
#define FPS_EBA_INH_PRECRASH   (64u)
#define FPS_EBA_INH_BRAKE_L1   (128u)
#define FPS_EBA_INH_BRAKE_L2   (256u)
#define FPS_EBA_INH_BRAKE_L3   (512u)
#define FPS_EBA_INH_HAPT_WARN  (1024u)
#define FPS_EBA_INH_ALL        (65535u)


#define HEAD_SafetyFunction_None           FPS_EBA_INH_NONE
#define HEAD_SafetyFunction_LatWarn        FPS_EBA_INH_LAT_WARN
#define HEAD_SafetyFunction_PreDynWarn     FPS_EBA_INH_PRE_WARN
#define HEAD_SafetyFunction_AcuteDynWarn   FPS_EBA_INH_ACU_WARN
#define HEAD_SafetyFunction_Prefill        FPS_EBA_INH_PRE_FILL
#define HEAD_SafetyFunction_HBATHRD        FPS_EBA_INH_HBA_THRD
#define HEAD_SafetyFunction_HBATBRK        FPS_EBA_INH_HBA_TBRK
#define HEAD_SafetyFunction_Precrash       FPS_EBA_INH_PRECRASH
#define HEAD_SafetyFunction_Brake1         FPS_EBA_INH_BRAKE_L1
#define HEAD_SafetyFunction_Brake2         FPS_EBA_INH_BRAKE_L2
#define HEAD_SafetyFunction_Brake3         FPS_EBA_INH_BRAKE_L3
#define HEAD_SafetyFunction_HaptWarn       FPS_EBA_INH_HAPT_WARN
#define HEAD_SafetyFunction_All            FPS_EBA_INH_ALL

#endif // ndef FPS_EBA_INH_NONE
#endif // MEDIC_ARCHITECTURE_VERSION >= 0x10

#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)  /* PRQA S 0603,0602 *//*Reviewer : Nagaraja Veerashettappa : Macro to avoid the parameter (not used interface solution)*/
#endif /* #if ndef _PARAM_UNUSED */

/*! @brief MEDIC sync ref structure */
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
typedef struct
{
  SignalHeader_t sSigHeader;                          /*!< Signal Header of Veh_SyncRef        */
  SignalHeader_t VehCtrlData;                         /*!< FCT_VEH operation mode control data */
  SignalHeader_t EgoDynRaw;                           /*!< The dynamic vehicle ego data raw    */
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t DIMInputGeneric;                     /*!< Generic DIM input                   */
  SignalHeader_t DIMInputCustom;                      /*!< Custom DIM input                    */
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t FCTCDHypotheses;                     /*!< CD hypotheses                       */
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t HEADInputGeneric;                    /*!< Generic HEAD input                  */
  SignalHeader_t HEADInputCustom;                     /*!< Custom HEAD input                   */
  #endif
  #if ((MEDIC_CFG_CPAR_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CPAR_FCT_Parameters;                 /*!< FCT Coding Parameters               */
  #endif
  #if ((MEDIC_CFG_VEH_SIG_INPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t  VehSig;                             /*!< Direct access to vehicle signals    */
  #endif
  #if ((MEDIC_CFG_BSW_ALGO_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t  BswAlgoParameters;                  /*!<                                     */
  #endif
  #if ((MEDIC_CFG_CUSTOMINPUT) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t  FctVehCustInput;                    /*!<                                     */
  #endif
} MEDICSyncRef_t;
#else
typedef struct
{
  SignalHeader_t sSigHeader;               /*!< Signal Header of MEDIC_SyncRef      */
  SignalHeader_t MedicControlData;         /*!< Control Data */
  SignalHeader_t MedicEgoMotion;           /*!< Ego Motion and Localization (EML). */
  SignalHeader_t pMedicVehSig;             /*!< Dummy Port.Vehicle Signal Information from BSW */
  SignalHeader_t MedicHypotheses;          /*!< Hypothesis Interface for Medic */
  SignalHeader_t MedicEvasionTargets;      /*!< Data to feed the lateral kinematic target to the long controller if the corresponding hypotheses is activated for Medic */
  SignalHeader_t MedicBrakeTargets;        /*!< Data to feed the lateral kinematic target to the long controller if the corresponding hypotheses is activated for Medic */
  SignalHeader_t MedicDegradation;         /*!< Contains information which dynamically degrades the functionality based on information about the sensors and their outputs for medic */
  SignalHeader_t MedicSwitches;            /*!< sSwitches to MEDIC */
  SignalHeader_t MedicVehicle;             /*!< Vehicle To MEDIC */
  SignalHeader_t MedicDriverMonitor;       /*!< DriverMonitor To MEDIC */
  #if (CFG_MEDIC_IN_TOYOTA == 1)
  SignalHeader_t MedicCustomInput_TMC;     /*!< CustomInput_TMC Toyota motor corporation To MEDIC */
  #endif
  SignalHeader_t MedicParameters;          /*!< MEDIC_Parameters */
  SignalHeader_t MedicStateControl;        /*!< EBA state control */
  #if (MEDIC_CFG_USE_VDY)
  SignalHeader_t MedicVDY_In;              /*!< Vehicle Dynamics to MEDIC */
  #endif
  #if (CFG_MEDIC_IN_BMW == 1)
  SignalHeader_t MedicCustomInput_BMW;     /*!< MedicCustomInput_BMW motor corporation To MEDIC  */
  #if(MEDIC_CFG_CAM_AEB == MEDIC_ON)
  SignalHeader_t MedicCamAEB;             /*!< MEDIC_DataAEB */
  #endif //MEDIC_CFG_CAM_AEB
  #endif 
  SignalHeader_t MedicloggingInfo;         /*!< MEDIC_Parameters */
} MEDICSyncRef_t;
#endif
#endif

#if (MEDIC_CFG_AUTOSAR_WRAPPER)
/*! @brief MEDIC_ProcMem */
typedef struct MEDIC_ProcMem
{
  GA_MEDIC_ASILBSlowInter_Mem_Data     * memASILBSlowInter;
  GA_MEDIC_ASILBSlowInterMeas_Mem_Data * memASILBSlowInterMeas;
  GA_MEDIC_ASILBSlowIntraMeas_Mem_Data * memASILBSlowIntraMeas;
} MEDIC_ProcMem;

/*********************/
/* request port list */
/*********************/
/*! @brief MedicReqPortsMEDIC01 */
typedef struct MedicReqPortsMEDIC01
{
  MEDIC_ControlData                const* controlData;           /*!< Control Data */
  CEM_EgoVehicleKinematics         const* egoMotion;             /*!< Ego Motion and Localization (EML). */
  VehSig_t                         const* vehSig;                /*!< Dummy Port.Vehicle Signal Information from BSW */
  ACDC2_HypothesisIntf             const* hypothesis;            /*!< Hypothesis Interface for Medic */
  ACDC2_EvasionTargets             const* evasionTargets;        /*!< Data to feed the lateral kinematic target to the long controller if the corresponding hypotheses is activated for Medic */
  ACDC2_BrakeTargets               const* brakeTargets;          /*!< Data to feed the long kinematic target to the long controller if the corresponding hypotheses is activated for Medic */
  ACDC2_Degradation                const* degradation;           /*!< Contains information which dynamically degrades the functionality based on information about the sensors and their outputs for medic */
  MEDIC_t_Switches                 const* switches;              /*!< sSwitches to MEDIC */
  MEDIC_t_Vehicle                  const* vehicle;               /*!< Vehicle To MEDIC */
  MEDIC_t_DriverMonitor            const* driverMonitor;         /*!< DriverMonitor To MEDIC */
  MEDIC_t_Qualifiers               const* qualifiers;            /*!< Qualifiers To MEDIC */
  #ifdef CFG_MEDIC_IN_TOYOTA
  #if (CFG_MEDIC_IN_TOYOTA == 1)
  MEDIC_t_TMC                      const* customInput_TMC;       /*!< CustomInput_TMC Toyota motor corporation To MEDIC */
  #endif
  #else
  #error "undefined CFG_MEDIC_IN_TOYOTA"
  #endif
  Medic_t_Parameters               const* medicParameters;       /*!< MEDIC_Parameters */
  #ifdef CFG_MEDIC_IN_BMW
  #if (CFG_MEDIC_IN_BMW == 1)
  MEDIC_CustomInput_BMW            const* customInput_BMW;       /*!< customInput BMW */
  #endif
  #else
  #error "undefined CFG_MEDIC_IN_BMW"
  #endif
  MEDIC_t_EBAStateControl           const* ebaStateControl;       /*!< EBA state control */
} MedicReqPortsMEDIC01;

// for compatibility ... old name is deprecated
typedef MedicReqPortsMEDIC01 MEDIC01_ReqPorts;

/*********************/
/* provide port list */
/*********************/
/*! @brief MedicProPortsMEDIC01 */
typedef struct MedicProPortsMEDIC01
{
  AlgoCompState_t                  * algoCompState;              /*!< Component state interface */
  MEDIC_t_BrakeCascades            * brakeCascades;              /*!< BrakeCascade to ACDC */
  MEDIC_TargetRequest_t            * trajPlanerCtrlLimits;  /*!< EBACtrlLimIntf to LOPLN and LOCTR */
  #ifdef CFG_MEDIC_OUT_HBA
  #if (CFG_MEDIC_OUT_HBA == 1)
  MEDIC_t_HBA                      * hbaHydrBrkAss;              /*!< Output for HBA Hydraulic Brake Assist */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_HBA"
  #endif
  #ifdef CFG_MEDIC_OUT_PREFILL
  #if (CFG_MEDIC_OUT_PREFILL == 1)
  MEDIC_t_Prefill                  * prefill;                    /*!< Output of Prefill */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_PREFILL"
  #endif
  #ifdef CFG_MEDIC_OUT_PREBRAKE
  #if (CFG_MEDIC_OUT_PREBRAKE == 1)
  MEDIC_t_PreBrake                 * preBrake;                   /*!< Output of PreBrake */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_PREBRAKE"
  #endif
  #ifdef CFG_MEDIC_OUT_WARNINGS
  #if (CFG_MEDIC_OUT_WARNINGS == 1)
  MEDIC_t_Warnings                 * warnings;                   /*!< output of Warnings */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_WARNINGS"
  #endif
  #ifdef CFG_MEDIC_OUT_PRECRASH
  #if (CFG_MEDIC_OUT_PRECRASH == 1)
  MEDIC_t_PreCrash                 * preCrash;                   /*!< output of PreCrash */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_PRECRASH"
  #endif
  #ifdef CFG_MEDIC_OUT_DRIVEROFFPREV
  #if (CFG_MEDIC_OUT_DRIVEROFFPREV == 1)
  MEDIC_t_DriveOffPrev             * driveOffPrev;               /*!< Output for Drive Off Prevention */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_DRIVEROFFPREV"
  #endif
  #ifdef CFG_MEDIC_OUT_ESA
  #if (CFG_MEDIC_OUT_ESA == 1)
  MEDIC_t_SteerAssist              * steerAssist;                /*!< Output for Evasion Steer Assist */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_ESA"
  #endif
  #ifdef CFG_MEDIC_OUT_HYPREACTIONS
  #if (CFG_MEDIC_OUT_HYPREACTIONS == 1)
  MEDIC_t_HypReactions_Interf      * hypReactions;               /*!< Output of HypReactions */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_HYPREACTIONS"
  #endif
  #ifdef CFG_MEDIC_OUT_FCTQUALIFIERS
  #if (CFG_MEDIC_OUT_FCTQUALIFIERS == 1)
  MEDIC_t_FCTQualifiers_Interf     * fctQualifiers;              /*!< output of FCT Qualifiers */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_FCTQUALIFIERS"
  #endif
  #ifdef CFG_MEDIC_OUT_FCTDATA
  #if (CFG_MEDIC_OUT_FCTDATA == 1)
  MEDIC_t_FCTData_Interf           * fctData;                    /*!< output of FCTData */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_FCTDATA"
  #endif
  #ifdef CFG_MEDIC_OUT_TOYOTA
  #if (CFG_MEDIC_OUT_TOYOTA == 1)
  MEDIC_t_TMCOutput_Interf         * tmcOutput;                  /*!< output of TMC Toyota Motor Corporation */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_TOYOTA"
  #endif
  #ifdef CFG_MEDIC_OUT_DIMOUTPUT
  #if (CFG_MEDIC_OUT_DIMOUTPUT == 1)
  MEDIC_t_DIMOutput_Interf         * dimOutput;                  /*!< Output of DIM Driver Intenion Monitor */
  #endif
  #else
  #error "undefined CFG_MEDIC_OUT_DIMOUTPUT"
  #endif
} MedicProPortsMEDIC01;

// for compatibility ... old name is deprecated
typedef MedicProPortsMEDIC01 MEDIC01_ProPorts;

/*! @brief MEDIC_Services_MEDIC01 services */
typedef struct MEDIC_Services_MEDIC01
{
  AS_t_RTAAlgoServiceAddEvent   pfRTAAlgoServiceAddEvent; /*!< RTA Algo Service Add Event function */
} MEDIC_Services_MEDIC01;

typedef MEDIC_Services_MEDIC01 MEDIC_Services;

/*< runnables MEDIC01 */
void  MedicExecMEDIC01 (MedicReqPortsMEDIC01 const*const reqPorts, MedicProPortsMEDIC01 const*const proPorts,MEDIC_ProcMem const*const  procMem, MEDIC_Services_MEDIC01 const*const  services);

// for compatibility ... old name is deprecated
#define MEDIC01_Exec MedicExecMEDIC01

#endif /* MEDIC_CFG_AUTOSAR_WRAPPER */

#ifdef __cplusplus
}
#endif
#endif // MEDIC_TYPES_H_INCLUDED


