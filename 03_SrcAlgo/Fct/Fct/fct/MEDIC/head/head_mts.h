/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_mts.h

DESCRIPTION:               header of the head mts output

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:48:20CEST $

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            1.23

**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_MTS_H_INCLUDED
#define HEAD_MTS_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*! @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*! @endcond */

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief          HEADMTSMaxInputSignals
    @description    HEAD MTS Maximum Input Signals
    @typical        20u
    @unit           SI-unit
       */
#define HEADMTSMaxInputSignals (20u)

/* Temporary workaround, MEAS ID shall be finnaly defined by RTE*/
#ifndef   FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
/*! @brief          FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
    @description    FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
    @typical        0x20282600
    @unit           SI-unit
       */
#define FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT	(0x20282600)
#endif
#ifndef   FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
/*! @brief          FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
    @description    FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
    @typical        0x20282E00
    @unit           SI-unit
       */
#define FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA	(0x20282E00)
#endif


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
struct HEADInputValue_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEADMTSInputSignalList_t

    @description    HEAD Input Signal for MTS
    */
typedef struct 
{
  HEADMTSInputSignal_t rgInputSignal[HEADMTSMaxInputSignals];   /*!<store Input Signals for MTS rgInputSignal[HEADMTSMaxInputSignals]*/
} HEADMTSInputSignalList_t; /*!< @values:HEADMTSInputSignalListDef_t*/

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEAD MTS Header Data
    */
typedef struct  
{
  uint32 uiBaseVersion; /*!<uiBaseVersion*/
  uint32 uiStructSize;  /*!<uiStructSize @unit:bytes*/
} HEADMTSHeaderData_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief      HEAD MTS Input Data
    */
typedef struct  
{
  float32               fCycleTime;                    /*!< typical cycle time in s @unit:s*/
  uint32                uiCurrentCycle;                /*!< current HEAD cycle*/
  uint8                 uiNumberOfHEADHypotheses;      /*!< nr of hypothesis in array*/
  HEADMainMode_t        eHEADMainMode;                 /*!< driver mode @values @ref eHEADMainMode_t @unit:[early, middle, late, acc]*/
  uint8                 eExternalOpMode;               /*!< external operation mode @values @ref eHEADOpMode_t @unit:[running, shutdown, stop]*/   
} HEADMTSInputData_t;


/*for MTS output*/
/*! @brief      HEAD_MTS_MAX_MODULES */
#define HEAD_MTS_MAX_MODULES (HEADModules_Max)
/*! @brief      HEAD_MTS_MAX_STATE_TIME */
#define HEAD_MTS_MAX_STATE_TIME (65535.0f)

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEAD MTS Module Name
    */
typedef struct  
{
  uint8                         uiModNr;                                    /*!< ModuleNr @name:uiModuleNr*/
  uint8                         strModuleName[HEAD_MODULENAME_LENGTH+1u];   /*!< module name @name:ModuleName*/  
  HEADModuleInternalType_t      eInternalType;                              /*!< stores the internal type (GSM/custom) @unit:GSM|custom*/
} HEADMTSModuleName_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEAD MTS Module Common Info

    */
typedef struct  
{  
  uint16                        f16RelStateTimer[HEADSMState_Max];  /*!< counts the seconds how long the module is in relevant state*/
  uint16                        uiHypInOrGroup[HEAD_MAX_OR_GROUPS]; /*!< orGroup array with corresponding hypotheses*/
  HEADModuleQoS_t               eQoS;                               /*!< states of Module QoS @ref eHEADModuleQoS_t @unit:stop|shdn|keep|ok*/
  HEADSMState_t                 eState;                             /*!< Module SM State @ref eHEADSMState_t @unit:off|pass|act|wait|init*/
  HEADModuleRepError_t          eReportedError;                     /*!< Module SPM reported error type @ref eHEADModuleRepError_t @unit:critical|normal|silent|noError*/
} HEADMTSModuleCommonInfo_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEAD MTS Module CommonOut

    */
typedef struct  
{ 
  uint8                         uiNrOfModules;                                 /*!< uiNrOfModules*/
  HEADMTSModuleCommonInfo_t     sModuleInfo[HEAD_MTS_MAX_MODULES];             /*!< modules Common Info @name:ModuleGenericInfo*/
  float32                       fdummyvar;                                     /*!<dummy variable to fix the aligment issue*/
} HEADMTSModuleCommonOut_t;


/*! @brief          HEAD_CFG_PART_MAX_LENGTH*/
#define HEAD_CFG_PART_MAX_LENGTH (16u)                   /*!< 16 bytes per part*/

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEAD MTS Cfg Data
    */
typedef struct  
{
  uint32                uiCfgLen;                             /*!< config length in bytes @unit:bytes*/
  uint32                uiCfgPartPos;                         /*!< position of the current config part in bytes @unit:bytes*/
  uint32                uiCfgPartLen;                         /*!< length of the current config part in bytes @unit:bytes*/
  uint8                 uiCfgData[HEAD_CFG_PART_MAX_LENGTH];  /*!< part of the HEAD config data @unit:bytes*/
} HEADMTSCfgData_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEADMTSData_t

    @description    head mts output data

    */
typedef struct
{
  HEADMTSHeaderData_t      sMTSHeaderData;      /*!< MTS header data - head version, size of data @name:Header*/
  HEADMTSParameterData_t   sMTSParamData;       /*!< MTS parameter data (static) @name:Parameter*/
  HEADMTSModuleName_t      sMTSModuleName;      /*!< MTS module names (static) @name:ModuleName*/
  HEADMTSInputSignalList_t sMTSInputSignalList; /*!< MTS input signals @name:InputSignalList*/
  HEADMTSSPMRule_t         sMTSSPMRule;         /*!< MTS SPM rules (static) @name:SPMRule*/
  HEADMTSSPMTimers_t       sMTSSPPMTimers;      /*!< MTS dynamic SPM timings @name:SPMRuleTimers*/
  HEADMTSInputData_t       sMTSInputData;       /*!< MTS overall input data @name:InputData*/
  HEADMTSCfgData_t         sMTSCfgData;         /*!< MTS HEAD configuration raw data @name:ConfigData*/
} HEADMTSData_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEADMTSStaticData_t

    @description    static data for internal mts sending process

    */
typedef struct  
{
  const HEADParameterEmpty_t *pParLastWrittenParameter;   /*!< Last Written Parameter*/
  uint8 uiParLastWrittenParNr;                            /*!< Last Written ParNr*/
  uint8 uiParLastWrittenModNr;                            /*!< Last Written ModNr*/
  uint8 uiParLastWrittenTabPos;                           /*!< Last Written TabPos*/
  HEADParamOperator_t eParLastWrittenOperator;            /*!< Last Written Operator*/
  uint8 uiParLastWrittenOutType;                          /*!< Last Written OutType*/
  uint8 uiModNamesLastWritteModNameNr;                    /*!< Last Written ModNameNr*/
  uint8 uiSPMRulesLastWrittenRuleNr;                      /*!< Last Written RuleNr(SPM Rules)*/
  uint32 uiCfgPartPos;                                    /*!< position of the current config part in bytes @unit:bytes*/
} HEADMTSStaticData_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          HEADMTSConditionsOKTimer_t

    */
typedef struct  
{
  f16_t fConditionsOKTimer[HEAD_MTS_MAX_MODULES][HEAD_MAX_OR_GROUPS*2u];     /*!< counts the seconds how long the module would fulfill all parameter criteria @unit [s]*/  
} HEADMTSConditionsOKTimer_t;

/*! @brief typedef eGDBError_t HEADMTSSendExtraInputSignals_ft (const void *pExtraValueList, HEADMTSInputSignalList_t *pMTSInputSignalList, uint8 uiStartNr);*/
typedef eGDBError_t HEADMTSSendExtraInputSignals_ft(const void *pExtraValueList, HEADMTSInputSignalList_t *pMTSInputSignalList, uint8 uiStartNr);

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADMTSInit(HEADMTSStaticData_t *pMTSStaticData);

extern eGDBError_t HEADMTSSendParameters(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pStaticData, HEADMTSParameterData_t *pMTSParamData);
extern eGDBError_t HEADMTSSendModuleName(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleName_t *pMTSModuleData);
extern eGDBError_t HEADMTSSendModuleCommonData(const HEADInputData_t *pInputData, HEADMTSModuleCommonOut_t *pMTSModuleCommonData);
extern eGDBError_t HEADMTSSendSPMRule(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pMTSStaticData, HEADMTSSPMRule_t *pMTSSPMModule);
extern eGDBError_t HEADMTSSendInputData(const HEADInputData_t *pInputData, HEADMTSInputData_t *pMTSInputData);
extern eGDBError_t HEADMTSSendSPMRuleTimes(const HEADInputData_t *pInputData, HEADMTSSPMTimers_t *pMTSSPMTimers);
extern void        HEADMTSSendInputSignal(const struct HEADInputValue_t *pInputSignal, HEADMTSInputSignalList_t *pMTSInputSignalList, 
                                          uint8 uiMTSInputSigNr, HEADMTSInSigIdent_t eHEADMTSInSigIdent, eGDBError_t* retErrorValue);
extern eGDBError_t HEADMTSSendInputSignals(const HEADInputData_t *pInputData,const void *pExtraValueList, 
                                           HEADMTSSendExtraInputSignals_ft *fpExtraValueFct, 
                                           HEADMTSInputSignalList_t *pMTSInputSignalList);
extern eGDBError_t HEADMTSSendHeaderData(HEADMTSHeaderData_t *sMTSHeaderData);
extern eGDBError_t HEADMTSSendConfigData(HEADMTSStaticData_t *pStaticData, HEADMTSCfgData_t *pMTSConfigData, const uint8 pCfg[], uint32 uiCfgLen);

/*** END OF SINLGE INCLUDE SECTION ******************************************/

/*! @cond */
#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
/*! @endcond */

#endif /* HEAD_MTS_H_INCLUDED */
/**@}*/

