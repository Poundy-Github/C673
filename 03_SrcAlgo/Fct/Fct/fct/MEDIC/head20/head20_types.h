/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_types.h

DESCRIPTION:               Definition of HEAD20 datatypes

AUTHOR:                    $Author: H U, Minuthi (uia80216) (uia80216) $

CREATION DATE:             $Date: 2020/04/23 13:51:17CEST $

VERSION:                   $Revision: 1.25 $

**************************************************************************** */
#ifndef HEAD20_TYPES_INCLUDED
#define HEAD20_TYPES_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "head20/head20_autocode_sm_par.h"
#include "head20/head20_module_def.h"
#include "head20/head20_parameter_def.h"


/* PRQA S 2053 EOF */ /* date: 20-11-2019, uic42639, warning is due to commenting source code which is not the case (not true) hence masking the warning */


/*****************************************************************************
(SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! 
@brief       HEADMTSMaxInputSignals
@general     HEAD MTS Maximum Input Signals
@conseq      @incp  
@decp  
@attention   [None]
@typical     20u
@unit        SI-unit
*/
#define HEADMTSMaxInputSignals     (22u)

/*! 
@brief       maximum nr of SPM rules for the MTS
@general     maximum nr of SPM rules for the MTS
@conseq      [None]
@attention   [None]   
*/
#define HEADMTSSPMRulesMax         (31u)


/*! @brief   HEAD_CFG_PART_MAX_LENGTH  */
#define HEAD_CFG_PART_MAX_LENGTH   (16u)                   /*!< 16 bytes per part*/



/* ****************************************************************
TYPEDEF ENUM
**************************************************************** */
/*! @brief eHEADOpMode_t
@general Operations modes for external framework control
@conseq [ None ]
@attention [ None ]
*/
typedef enum 
{
  HEADOpMode_Running,     /*!< normal operation */
  HEADOpMode_ShutDown,    /*!< normal deactivation */
  HEADOpMode_Stop         /*!< severe deactivation */
} eHEADOpMode_t;

/*!
@brief Data type to store Input Signals for MTS
*/
typedef struct  
{ 
  float32 fValue;           /*!< Value*/
  float32 fStdDev;          /*!< StdDev*/
  uint8   eSigStat;         /*!< ok|default|missing|badqual|susp*/
  uint8   eSigType;         /*!< float|sint|uint|bool*/
  uint8   HEADMTSInSigIdent;/*!< HEADMTSInSigIdent*/
  boolean isValid;          /*!< isValid*/
} HEADMTSInputSignal_t;

/*! @brief this typedef is used to create correct MTS data definition 
           for the Inputdata structure that consists HEADMTSInputSignalList_t and custom input data
 */
typedef struct
{
  HEADMTSInputSignal_t LongVelocity;     /*!< Longitudinal Velocity */
  HEADMTSInputSignal_t LongAcceleration; /*!< Longitudinal Acceleration */
  HEADMTSInputSignal_t YawRate;          /*!< YawRate */
  HEADMTSInputSignal_t DrivingDirection; /*!< Driving Direction */
  HEADMTSInputSignal_t EgoLatCurvature;  /*!< Host vehicle trajectory curvature */
  HEADMTSInputSignal_t CDHypotheses;     /*!< CD hypotheses */
  HEADMTSInputSignal_t DIMHypotheses;    /*!< DIM hypotheses */   //fixxme andreas.jakob-ext@conti-engineering.com
  HEADMTSInputSignal_t SafeObjDistSfty;  /*!< Safe Object Distance for Safety functions */
  HEADMTSInputSignal_t SafeObjDistPerf;  /*!< Safe Object Distance for Performance functions */
  HEADMTSInputSignal_t StabCtrlState;    /*!< Status of stability control system */
  HEADMTSInputSignal_t BrakeChainState;  /*!< Status of brake system */
  HEADMTSInputSignal_t WarnChainState;   /*!< Status of warning chain systems */
  HEADMTSInputSignal_t DriverFeedback;   /*!< Driver Feedback */
  HEADMTSInputSignal_t DriverActivity;   /*!< Driver Activity */
  HEADMTSInputSignal_t DriverAttention;  /*!< Driver Attention */

  /*this is custom data...*/
  HEADMTSInputSignal_t ExtPreBrakeSetting; /*!< External Pre Brake Settings */
  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  HEADMTSInputSignal_t CameraReady;
  #endif
  HEADMTSInputSignal_t DIMInputsValid; /*!< DIM Inputs */
} HEADMTSInputSignalListDef_t;

/*! 
@brief HEADMTSStateName_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint8                         uiStateNr;                                  /*!< @name:uiStateNr*/
  uint8                         strStateName[HEAD_STATENAME_LENGTH+1u];     /*!< state name @name:StateName*/  
} HEADMTSStateName_t;

/*!
@brief HEADMTSModuleStateNameIndex_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct
{
  uint8                         uiModuleNr;                                    /*!< @name:uiModuleNr*/
  uint8                         ModuleStateNameIndex[HEAD_AUTO_CFG_MAX_STATES];/*!< module name index @ui_strModuleStateName*/
  uint32                        uDummy;                                        /*!<Align for MTS */
} HEADMTSModuleStateNameIndex_t;

/*!
@brief HEADMTSModuleStateStyleName_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct
{
  uint8                         uiModuleNr;                                       /*!< @name:uiModuleNr*/
  uint8                         ModuleStateStyleName[HEAD_AUTO_CFG_MAX_STATES];   /*!< module name index @ui_strModuleStateName*/
} HEADMTSModuleStateStyleName_t;


/*! @brief head MTS transition data  */
typedef struct
{
  uint8 uiModuleNr;    /*!< defines which module the transition belongs to                          */
  uint8 uiStateNr;     /*!< defines which state of a module the transition belongs to               */
  uint8 uiTransNr;     /*!< defines which transition of a particular state the parameter belongs to */
  uint8 uiTargetState; /*!< defines the target state of the transition                              */
} HEADMTSTransitionData_t;

/*! 
@brief HEADMTSDGSMStateName_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint8                         uiStateNr;                                      /*!< @name:uiStateNr*/
  uint8                         strDGSMStateName[HEAD_DGSMSTATENAME_LENGTH+1u]; /*!< state name @name:StateName*/  
  uint32                        uDummy;                                         /*!<Align for MTS */
} HEADMTSDGSMStateName_t;

/*! 
@brief HEADMTSHeaderData_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint32 uiBaseVersion; /*!<uiBaseVersion*/
  uint32 uiStructSize;  /*!<uiStructSize @unit:bytes*/
} HEADMTSHeaderData_t;

/*! 
@brief HEADMTSModuleName_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint8                         uiModNr;                                    /*!< @name:uiModuleNr*/
  uint8                         strModuleName[HEAD_MODULENAME_LENGTH+1u];   /*!< module name @name:ModuleName*/  
  HEADModuleInternalType_t      eInternalType;                              /*!< stores the internal type (GSM/custom) @unit:GSM|custom*/
  uint32                        uDummy;                                     /*!< Align for MTS */
} HEADMTSModuleName_t;

/*! 
@brief HEADMTSErrorName_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint8  uiErrorNr;                                   /*!< @name:uiErrorNr*/
  uint8  strErrorName[HEAD_REPERRNAME_LENGTH+1u];     /*!< state name @name:ErrorName*/  
  uint32 uDummy;                                      /*!< Align for MTS */
} HEADMTSErrorName_t;

#if (HEAD_CFG_PRECONDITION)
/*!
@brief HEADMTSPreCondName_t
@general Output precondition names
@conseq [ None ]
@attention [ None ]
*/
typedef struct
{
  uint8  uiPreCondNr;                                   /*!< @name:uiPreCondNr                   */
  uint8  strPreCondName[HEAD_PRECONDNAME_LENGTH + 1u];  /*!< precond name @name:PreConditionName */
  uint32 uDummy;                                        /*!< Align for MTS                       */
} HEADMTSPreCondName_t;


/*!
@brief HEADMTSPreCondStatus_t
@general Output precondition status
@conseq [ None ]
@attention [ None ]
*/
typedef struct
{
  uint16  uiHypInCondGroup;  /*!< uiHypInCondGroup @name:uiHypInCondGroup */
  boolean PreCondStatus;     /*!< precond status @name:PreConditionStatus */
  uint32  uDummy;            /*!< Align for MTS                           */
} HEADMTSPreCondStatus_t;

/*!
@brief HEADMTSPreCondStatus_t
@general All precondition data
@conseq [ None ]
@attention [ None ]
*/
typedef struct
{
  HEADMTSPreCondStatus_t  HEADMTSPreCond[(uint8)HEAD_AUTO_CFG_NO_PRECONDS];
} HEADMTSPreConditionData;
#endif /*PreConditon*/

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief    eHEADSPMCheckBitsSignal_t

    @general  Enumerations used for setting/getting the bits which define whether
              the signal or its state needs to be checked 
    */
typedef enum 
{
  HEADSPMCheckBitsSignal_SigState            = 0, /*!< defines that the SignalState needs to be checked*/
  HEADSPMCheckBitsSignal_Signal              = 1, /*!< defines that the Signal itself needs to be checked*/

  HEADSPMCheckBitsSignal_Max                 = 2  /*!< maximum number of enumerations for HEAD signal checking */ 
} eHEADSPMCheckBitsSignal_t;

/*! @brief       Definition for Head SPM QoS Transition mapping bit
@general     This Macro will set the bits to define the transition list for a particular QoS in priority order 
It will shift the transition number in multiple of 3 as 3bits are assigned for each transition number
@conseq      [none] */
#if(MEDIC_ARCHITECTURE_VERSION < 0x10)
#define HEADSPMQoSTransBit(transNr,index)  ((HEADBitField_t)((uint32)(transNr)<<((uint32)((index) * 3))))
#else
#define HEADSPMQoSTransBit(transNr,index)  (((uint64)(transNr)<<((uint64)((index) * 4))))
#endif

/*! @brief       Gets the bits from Head SPM QoS Transition mapping bit which indicate transition number

@general     Gets the bits from Head SPM QoS Transition mapping bit which indicate transition number 
*/
#if(MEDIC_ARCHITECTURE_VERSION < 0x10)
#define HEADSPMGetQoSTransNr(TransBitMap,index)  ((uint8)(((TransBitMap)>>((uint8)((index) * 3u))) & 7u))
#else
#define HEADSPMGetQoSTransNr(TransBitMap,index)  ((uint8)(((TransBitMap)>>((uint8)((index) * 4u))) & 15u))
#endif

/* ****************************************************************
    TYPEDEF struct HEADQoSTransitionMap_t
    **************************************************************** */
/*! @brief HEAD QoS Mapping structure

    @general HEAD QoS Mapping structure
            
             This mapping is used to find the corresponding transitions in a state for each QoS.
              |<-----8bits----->|<--5/4bits-->|<------3/4bits----->|<----------24/64bits-------->|   
                 uiNumQoSTrans  |    QoSNr    | Default Transition |                             |
                                                                  /                               \
                                                                 /                                 \     
                                                                /                                   \
                                                               /                                     \
                                                              |---Tx Indices in increasing priority-->|
                                                               least                           highest   
                                                               priority                        priority
                                                               tx(0)                           tx(7/15)

            Each transition(tx) index takes 3/4bits

            @attention Changing the order of the group of bits will create wrong mapping from Autocode
            @conseq [none]
            @attention [none]

    */
#if(MEDIC_ARCHITECTURE_VERSION < 0x10)
typedef struct
{
  HEADBitField_t  uiNumQoSTrans : 8;                       /*!< number of transitions associated with the current QoS */
  HEADBitField_t  uiQoSNr : 5;
  HEADBitField_t  uiDefaultTx : 3;
  HEADBitField_t  uiTransList: 24;                        /*!< QoS Mapping table for current QoS */ 
}HEADSPMQoSMap_t;
#else
typedef struct
{
  HEADBitField_t  uiNumQoSTrans : 8;                       /*!< number of transitions associated with the current QoS */
  HEADBitField_t  uiQoSNr : 4;
  HEADBitField_t  uiDefaultTx : 4;
  uint64          uiTransList;                             /*!< QoS Mapping table for current QoS */ 
}HEADSPMQoSMap_t;
#endif

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief    eHEADSPMCheckBitsOp_t

    @general  Enumerations used for setting/getting the bits which defines which operator 
              to use for the HEAD signal operation 
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

/*! 
@brief HEADMTSQosName_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint8                         uiQosNr;                                  /*!< @name:uiQosNr*/
  uint8                         strQosName[HEAD_QOSNAME_LENGTH+1u];     /*!< qos name @name:QosName*/  
} HEADMTSQosName_t;


/*! 
@brief HEADMTSSpmName_t
@general Names of SPM Conditions as described in auto coder
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint8                         uiSpmNr;                                /*!< @name:uiSpmNr*/
  uint8                         strSpmName[HEAD_SPMNAME_LENGTH+1u];     /*!< spm name @name:SpmName*/  
} HEADMTSSpmName_t;

/*! @brief    eHEADSPMCheckBitsFunction_t
    @general  Enumerations used for setting/getting the bits which defines 
              how the HEAD module signal to be used by the function   
    */
typedef enum
{
  HEADSPMCheckBitsFunction_No                = 0, /*!< defines that the Signal is not modified by a function */
  HEADSPMCheckBitsFunction_ABS               = 1, /*!< defines that the absolute value of the Signal is used */
 
  HEADSPMCheckBitsFunction_Max               = 2  /*!< maximum number of enumerations for the defination of HEAD signal usage by function */
} eHEADSPMCheckBitsFunction_t;

/*! @brief    eHEADSPMCheckBitsStdDeviation_t
    @general  Enumerations used for setting/getting the bits which define 
              the HEAD module signal for standard deviation    
    */
typedef enum
{
  HEADSPMCheckBitsStdDeviation_No            = 0, /*!< defines that the Signal is not modified by the standard deviation */
  HEADSPMCheckBitsStdDeviation_Plus          = 1, /*!< defines that the Signal plus the standard deviation is checked against the threshold */
  HEADSPMCheckBitsStdDeviation_Minus         = 2, /*!< defines that the Signal minus the standard deviation is checked against the threshold */
 
  HEADSPMCheckBitsStdDeviation_Max           = 3  /*!< maximum number of enumerations for the defination of HEAD signal for standard deviation */
} eHEADSPMCheckBitsStdDeviation_t; 

/*! @brief Describe the type of the enum HEADSPMCheckBitsSignal_t                            */
typedef uint8 HEADSPMCheckBitsSignal_t;        /*!< @values: eHEADSPMCheckBitsSignal_t       */

/*! @brief Describe the type of the enum HEADSPMCheckBitsOp_t                                */
typedef uint8 HEADSPMCheckBitsOp_t;            /*!< @values: eHEADSPMCheckBitsOp_t           */

/*! @brief Describe the type of the enum HEADSPMCheckBitsFunction_t                          */
typedef uint8 HEADSPMCheckBitsFunction_t;      /*!< @values: eHEADSPMCheckBitsFunction_t     */

/*! @brief Describe the type of the enum HEADSPMCheckBitsStdDeviation_t                      */
typedef uint8 HEADSPMCheckBitsStdDeviation_t;  /*!< @values: eHEADSPMCheckBitsStdDeviation_t */

/*! 
@brief    HEAD SPM Timer
@general  Holds the current timer of each HEAD SPM rule
*/
typedef struct  
{
  uint16 rguiTime[HEADMTSSPMRulesMax];  /*!< holds the current timer of each SPM rule -> index is the same as SPM rule index @unit:ms*/
} HEADMTSSPMTimers_t;

/*! 
@brief HEADMTSInputSignalList_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct 
{
  HEADMTSInputSignal_t rgInputSignal[HEADMTSMaxInputSignals];   /*!< rgInputSignal[HEADMTSMaxInputSignals]*/
} HEADMTSInputSignalList_t; /*!< @values:HEADMTSInputSignalListDef_t*/

/*! 
@brief    Defines a particular HEAD SPM rule
@general  Defines a particular HEAD SPM rule
*/
typedef struct  
{
  uint32                         bitModules;            /*!< @unit:bits */
  uint8                          uiNumQoSModules;       /*!< number of modules affected by this rule */
  float32                        fValue;                /*!< value */ 
  uint32                         uiNrOfRules;           /*!< nr of SPM rules */
  uint16                         uiNeededTime;          /*!< @unit:ms */
  HEADSPMCheckBitsSignal_t       eSignalOrSigStat;      /*!< @unit:sigstate|sig */
  HEADSPMCheckBitsOp_t           eOperator;             /*!< @unit:eq|!eq|sm|smeq|gr|greq */
  HEADSPMCheckBitsFunction_t     eFunction;             /*!< @unit:no|abs */
  HEADSPMCheckBitsStdDeviation_t eStdDevType;           /*!< @unit:no|plus|minus */
  uint8                          uiRuleNr;              /*!< HEAD SPM rule number */
  uint8                          uiInSigIdent;          /*!< Identity of the input signal */
} HEADMTSSPMRule_t;


/*! 
@brief HEADMTSInputData_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  float32               fCycleTime;                    /*!< typical cycle time in s @unit:s*/
  uint32                uiCurrentCycle;                /*!< current HEAD cycle*/
  uint8                 uiNumberOfHEADHypotheses;      /*!< nr of hypothesis in array*/
  HEADMainMode_t        eHEADMainMode;                 /*!< driver mode @values:eHEADMainMode_t @unit:[early, middle, late, acc]*/
  uint8                 eExternalOpMode;               /*!< external operation mode @values:eHEADOpMode_t @unit:[running, shutdown, stop]*/   
} HEADMTSInputData_t;


/*! 
@brief HEADMTSCfgData_t
@general more description here if any,otherwise skip this
@conseq [ None ]
@attention [ None ]
*/
typedef struct  
{
  uint32                uiCfgLen;                             /*!< config length in bytes @unit:bytes*/
  uint32                uiCfgPartPos;                         /*!< position of the current config part in bytes @unit:bytes*/
  uint32                uiCfgPartLen;                         /*!< length of the current config part in bytes @unit:bytes*/
  uint8                 uiCfgData[HEAD_CFG_PART_MAX_LENGTH];  /*!< part of the HEAD config data @unit:bytes*/
} HEADMTSCfgData_t;

/*! 
@brief HEADMTSData_t
@general head mts output data
@conseq [ None ]
@attention [ None ]
*/
typedef struct
{
  HEADMTSHeaderData_t           sMTSHeaderData;             /*!< MTS header data - head version, size of data @name:Header*/
  HEADMTSParameterData_t        sMTSParamData;              /*!< MTS parameter data (static) @name:Parameter*/
  HEADMTSModuleName_t           sMTSModuleName;             /*!< MTS module names (static) @name:ModuleName*/
  HEADMTSStateName_t            sMTSStateName;              /*!< MTS state names (static) @name:StateName*/
  HEADMTSErrorName_t            sMTSErrorName;              /*!< MTS Error names (static) @name:ErrorName*/
  HEADMTSQosName_t              sMTSQosName;                /*!< MTS Qos names (static) @name:QosName*/
  HEADMTSInputSignalList_t      sMTSInputSignalList;        /*!< MTS input signals @name:InputSignalList*/
  HEADMTSSPMRule_t              sMTSSPMRule;                /*!< MTS SPM rules (static) @name:SPMRule*/
  HEADMTSSPMTimers_t            sMTSSPPMTimers;             /*!< MTS dynamic SPM timings @name:SPMRuleTimers*/
  HEADMTSInputData_t            sMTSInputData;              /*!< MTS overall input data @name:InputData*/
  HEADMTSCfgData_t              sMTSCfgData;                /*!< MTS HEAD configuration raw data @name:ConfigData*/
  HEADMTSSpmName_t              sMTSSpmName;                /*!< MTS Spm names (static) @name:SpmName */
  HEADMTSModuleStateNameIndex_t sMTSModStateNameIndex;      /*!< MTS StateModule Index (static) @name:ModStateNameIndex */
  HEADMTSModuleStateStyleName_t sMTSModuleStateStyleName;   /*!< MTS StateStyleName (static) @name:StateStyleName */
  HEADMTSDGSMStateName_t        sMTSDGSMStateName;          /*!< MTS DGSM-State names (static) @name:DGSMStateName */
  #if (HEAD_CFG_PRECONDITION)
  HEADMTSPreCondName_t          sMTSPreCondName;            /*!< MTS precond names (static) @name:PreConditionName */
  HEADMTSPreConditionData       sMTSPreCondData;            /*!< MTS precond data @name:PreConditionData */
  HEADMTSPreCondParameterData_t sMTSPreCondParam;           /*!< MTS precond parameter data (static) @name:PreCondParameter */
  #endif
  HEADMTSTransitionData_t       sMTSTransition;             /*!< MTS Transition data @name:Transition */
} HEADMTSData_t;


/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief HEAD output signal identifiers

    @general These Identifiers are used to identify the HEAD output signals in the visualization
    
    @conseq Only add new signals
    
    @attention Deleting signals or changing IDs will brake compatibility to former projects
        
    */
typedef  enum 
{
  eHEADMTSInSigIdent_NoSignal            = 0,  /*!< Entry to define that no signal is attached yet */
  eHEADMTSInSigIdent_Velocity            = 1,  /*!< Velocity identifier */
  eHEADMTSInSigIdent_Acceleration        = 2,  /*!< Acceleration identifier */
  eHEADMTSInSigIdent_YawRate             = 3,  /*!< Yaw Rate identifier */
  eHEADMTSInSigIdent_DrivinDirection     = 4,  /*!< Identifier for Driving Direction */
  eHEADMTSInSigIdent_CDHypotheses        = 5,  /*!< Identifier for the signal which defines number of CD Hypothesis */
  eHEADMTSInSigIdent_DMHypotheses        = 6,  /*!< Identifier for the signal which defines number of DIM Hypothesis */
  eHEADMTSInSigIdent_SafeObjDistSfty     = 7,  /*!< Safe Object Distance Safety */
  eHEADMTSInSigIdent_SafeObjDistPerf     = 8,  /*!< Safe Object Distance Performance */
  eHEADMTSInSigIdent_StabCtrlState       = 9,  /*!< State of the Stabilization Control */
  eHEADMTSInSigIdent_BrakeChainState     = 10, /*!< State of the Brake System */
  eHEADMTSInSigIdent_WarnChainState      = 11, /*!< State of the Warn System */
  eHEADMTSInSigIdent_DriverFeedback      = 12, /*!< Identifier for Driver Feedback */
  eHEADMTSInSigIdent_DriverActivity      = 13, /*!< Identifier for Driver Activity */
  eHEADMTSInSigIdent_DriverAttention     = 14, /*!< Identifier for Driver Attention */

  eHEADMTSInSigIdent_DIMInputsValid      = 15, /*!< Valid DIM Input signals */
  eHEADMTSInSigIdent_CameraReady         = 16, /*!< Camera Ready identifier */
  eHEADMTSInSigIdent_ExtPreBrakeSetting  = 17, /*!< ExtPreBrakeSetting identifier */
  eHEADMTSInSigIdent_EgoLatCurvature     = 18, /*!< Curvature of ego trajectory */
  #if HEAD_CFG_TURN_ASSIST
  eHEADMTSInSigIdent_SteeringAngle                    = 19, /*!< Steering Angle */
  eHEADMTSInSigIdent_TurnIndicatorInSteeringDirection = 20, /*!< Turn Indicator In Steering Direction */
  eHEADMTSInSigIdent_GasPedal                         = 21, /*!< Gas Pedal */
  #endif /* HEAD_CFG_TURN_ASSIST */
  eHEADMTSInSigIdent_ObjListSource       = 22, /*!< Identifier for sensors available */
  eHEADMTSInSigIdent_ObjListDegraded     = 23, /*!< Identifier for sensors degraded */
  eHEADMTSInSigIdent_Max                 = 255 /*!< Maximum number of HEAD signal identifiers */
} HEADMTSInSigIdent_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Describes the type of HEAD SPM check rules and how to handle them

    @general Describes the type of HEAD SPM check rules and how to handle them

    */
typedef struct 
{
  struct HEADInputValue_t    *pInputSignal;        /*!< pointer to a input signal */
  HEADMTSInSigIdent_t        eHEADMTSInSigIdent;   /*!< HEAD MTS signal identifier */
  uint32                     bitModules;           /*!< bits which modules are affected by this rule */
  f16_t                      f16Value;             /*!< 16bit float that defines the parameter value */
  uint16                     uiNeededTime;         /*!< defines how long (scaled by HEADSpmTimeScale) the condition need to be true to change the QoS/Error */ 
  uint16                     uiCurrentTimer;       /*!< internal timer (scaled by HEADSpmTimeScale) that counts the time */  
  uint8                      bitCheckType;         /*!< type of the rule (defined by the following bits: 
                                             SOOOFFDD where S is eHEADSPMCheckBitsSignal_t, o is eHEADSPMCheckBitsOp_t, F is eHEADSPMCheckBitsFunction_t, D is eHEADSPMCheckBitsStdDeviation_t */

  const HEADModuleQoSRel_t   *pModuleQoSRel; /*!< pointer to the modules affected by this rule and corresponding QoS and error */
  uint8                      uiNumQoSModules;      /*!< number of modules affected by this rule */
} HEADSPMCheck_t;

#endif
