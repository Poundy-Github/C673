/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_mts.h

DESCRIPTION:               header of the head mts output

AUTHOR:                    $Author: H U, Minuthi (uia80216) (uia80216) $

CREATION DATE:             $Date: 2020/04/23 13:46:22CEST $

VERSION:                   $Revision: 1.32 $

LEGACY VERSION:            1.21.2.2 (HEAD 2.0)

**************************************************************************** */

#ifndef HEAD20_MTS_H_INCLUDED
#define HEAD20_MTS_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/
/* Temporary workaround, MEAS ID shall be finnaly defined by RTE*/
#ifndef   FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
/*! @brief       FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
    @general     FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
    @typical     0x20282600
    @unit        SI-unit
    
       */
#define FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT       (0x20282600)
#endif
#ifndef   FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
/*! @brief       FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
    @general     FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
    @typical     0x20282E00
    @unit        SI-unit
    
       */
#define FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA  (0x20282E00)
#endif

/*for MTS output*/
/*! @brief       HEAD_MTS_MAX_MODULES
    @general     HEAD_MTS_MAX_MODULES
    @typical     HEADModules_Max
    @unit        SI-unit
    
       */
/*! @brief      HEAD_MTS_MAX_MODULES */
#define HEAD_MTS_MAX_MODULES                   (HEADModules_Max)
/*! @brief       HEAD_MTS_MAX_STATE_TIME
    @general     HEAD_MTS_MAX_STATE_TIME
    @typical     65535.0f
    @unit        SI-unit
    
       */
/*! @brief      HEAD_MTS_MAX_STATE_TIME */
#define HEAD_MTS_MAX_STATE_TIME                (65535.0f)

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/* ****************************************************************
    TYPEDEF STRUCT MTS information
    **************************************************************** */
/*! @brief HEAD MTS information.

    @general HEAD MTS information

    @conseq [None]

    @attention [None]

    */
typedef struct  
{
  HEADModuleInternalGSMMTS_t ModuleInternalData[HEAD_MTS_MAX_MODULES]; /*!< @name:GSMModuleInternalData*/
} HEADMTSSpecificData_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADMTSCodedInhibition_t
    **************************************************************** */
/*! @brief HEAD MTS Coded Inhibition

    @general HEAD MTS Coded Inhibition

    @conseq [None]

    @attention [None]

    */
typedef struct  
{
  HEADBitField_t CodedInhibitionMask[HEAD_MAX_NUMBER_OF_CD_HYPS]; /*!<MTS CodedInhibitionMask */
} HEADMTSCodedInhibition_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEADMTSModuleCommonInfo_t

    @general more description here if any,otherwise skip this

    @conseq [ None ]

    @attention [ None ]

    */
typedef struct  
{ 
  uint16                        f16RelStateTimer[HEAD_AUTO_CFG_MAX_STATES]; /*!< counts the seconds how long the module is in relevant state*/
  uint16                        uiHypInOrGroup;
  HEADModuleQoS_t               eQoS;                                       /*!< @unit:stop|shdn|keep|ok*/
  HEADSMState_t                 eState;                                     /*!< @unit:off|pass|act|wait|init*/
  uint8                         uiNumModuleStates;                          /*!< number of states in a module */ 
  uint8                         uiMinModuleState;                           /*!< minimum state number for the module */  
  HEADModuleRepError_t          eReportedError;                             /*!< @unit:critical|normal|silent|noError*/
  uint32                        uDummy;                                     /*!< Align for MTS */
} HEADMTSModuleCommonInfo_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEADMTSModuleCommonOut_t

    @general more description here if any,otherwise skip this

    @conseq [ None ]

    @attention [ None ]

    */
typedef struct  
{ 
  uint8                         uiNrOfModules;                                 /*!< uiNrOfModules*/
  HEADMTSModuleCommonInfo_t     sModuleInfo[HEAD_MTS_MAX_MODULES];             /*!< modules @name:ModuleGenericInfo*/
  #if (HEAD_CFG_PRECONDITION)
  HEADPreCond_t                 PreCondInfo[(uint8)HEAD_AUTO_CFG_NO_PRECONDS]; /*!< PreCondition Info>*/
  #endif
  uint32                        uDummy;                                        /*!< Align for MTS */
} HEADMTSModuleCommonOut_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEADMTSStaticData_t

    @general static data for internal mts sending process

    @conseq [ None ]

    @attention [ None ]

    */
typedef struct  
{
  const HEADParameterEmpty_t *pParLastWrittenParameter;          /*!< pParLastWrittenParameter*/
  #if (HEAD_CFG_PRECONDITION)
  const HEADParameterEmpty_t *pParLastWrittenPreCondParameter;   /*!< pParLastWrittenParameter*/
  uint8 uiLastWrittenPreCondNameNr;                              /*!< uiModNamesLastWrittenPreCondNameNr*/
  uint8 uiParLastWrittenPreCondParNr;                            /*!< uiParLastWrittenPreCondParNr*/
  uint8 uiParLastWrittenPreCondTabPos;                           /*!< uiParLastWrittenPreCondTabPos*/
  uint8 uiParLastWrittenPreCondNr;                               /*!< uiParLastWrittenPreCondNr*/ /*Used for sending Param data */
  #endif /*End PreConditon*/
  uint8 uiParLastWrittenCondGrpNr;                               /*!< uiParLastWrittenCondGrpNr*/
  uint8 uiParLastWrittenTransNr;                                 /*!< uiParLastWrittenTransNr*/
  uint8 uiParLastWrittenStateNr;                                 /*!< uiParLastWrittenStateNr*/
  uint8 uiParLastWrittenModNr;                                   /*!< uiParLastWrittenModNr*/
  uint8 uiParLastWrittenTabPos;                                  /*!< uiParLastWrittenTabPos*/
  uint8 uiParLastWrittenParNr;                                   /*!< uiParLastWrittenParNr*/
  uint8 uiModNamesLastWritteModNameNr;                           /*!< uiModNamesLastWritteModNameNr*/
  uint8 uiModNamesLastWritteStateNameNr;                         /*!< uiModNamesLastWritteStateNameNr*/
  uint8 uiModNamesLastWritteQosNameNr;                           /*!< uiModNamesLastWritteQosNameNr*/
  uint8 uiModNamesLastWritteErrorNameNr;                         /*!< uiModNamesLastWritteErrorNameNr*/
  uint8 uiSPMRulesLastWrittenRuleNr;                             /*!< uiSPMRulesLastWrittenRuleNr*/
  uint8 uiModNamesLastWritteSpmNameNr;                           /*!< uiModNamesLastWritteSpmNameNr*/
  uint8 uiModNamesLastWritteModuleStateNameIndex;                /*!< uiModNamesLastWritteModuleStateNameIndex*/
  uint8 uiModLastWritModStateStyleName;                          /*!< uiModNamesLastWritteModuleStateStyleName*/
  uint8 uiModNamesLastWritteDGSMStateNameNr;                     /*!< uiModNamesLastWritteDGSMStateNameNr*/
  uint8 uiTransLastWrittenModNr;                                 /*!< uiTransLastWrittenModNr*/
  uint8 uiTransLastWrittenStateNr;                               /*!< uiTransLastWrittenStateNr*/
  uint8 uiTransLastWrittenTransNr;                               /*!< uiTransLastWrittenTransNr*/
  uint32 uiCfgPartPos;                                           /*!< position of the current config part in bytes @unit:bytes*/
} HEADMTSStaticData_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief HEADMTSConditionsOKTimer_t

    @general 

    @conseq [ None ]

    @attention [ None ]

    */
typedef struct  
{
  f16_t fConditionsOKTimer[HEAD_AUTO_CFG_NO_MODULES][HEAD_AUTO_CFG_MAX_TRANSITIONS * HEAD_AUTO_CFG_MAX_CONDGROUPS];     /*!< counts the seconds how long the module would fulfill all parameter criteria @unit:s*/  
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
extern eGDBError_t HEADMTSSendStateName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSStateName_t *pMTSStateData);
extern eGDBError_t HEADMTSSendQosName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSQosName_t *pMTSQosData);
extern eGDBError_t HEADMTSSendErrorName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSErrorName_t *pMTSErrorData);
extern eGDBError_t HEADMTSSendModuleStateNameIndex(HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleStateNameIndex_t *pMTSModuleStateIndexData);
extern eGDBError_t HEADMTSSendStateStyleName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleStateStyleName_t *pMTSModuleStateStyleName);
#if (HEAD_CFG_PRECONDITION)
extern eGDBError_t HEADMTSSendPreConditionName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSPreCondName_t *pMTSPreConditionName);
extern eGDBError_t HEADMTSSendPreConditionData(const HEADInputData_t *pInputData, HEADMTSPreConditionData *pMTSPreConditionData);
extern eGDBError_t HEADMTSSendPreCondParam(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pStaticData, HEADMTSPreCondParameterData_t *pMTSPreCondParamData);
#endif
extern eGDBError_t HEADMTSSendModuleCommonData(const HEADInputData_t *pInputData, HEADMTSModuleCommonOut_t *pMTSModuleCommonData);
extern eGDBError_t HEADMTSSendSPMRule(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pMTSStaticData, HEADMTSSPMRule_t *pMTSSPMModule);
extern eGDBError_t HEADMTSSendInputData(const HEADInputData_t *pInputData, HEADMTSInputData_t *pMTSInputData);
extern eGDBError_t HEADMTSSendSPMRuleTimes(const HEADInputData_t *pInputData, HEADMTSSPMTimers_t *pMTSSPMTimers);
extern eGDBError_t HEADMTSSendInputSignal(const struct HEADInputValue_t *pInputSignal, HEADMTSInputSignalList_t *pMTSInputSignalList, uint8 uiMTSInputSigNr, HEADMTSInSigIdent_t eHEADMTSInSigIdent);
extern eGDBError_t HEADMTSSendInputSignals(const HEADInputData_t *pInputData,const void *pExtraValueList, 
                                           HEADMTSSendExtraInputSignals_ft *fpExtraValueFct, 
                                           HEADMTSInputSignalList_t *pMTSInputSignalList);
extern eGDBError_t HEADMTSSendHeaderData(HEADMTSHeaderData_t *sMTSHeaderData);
extern eGDBError_t HEADMTSSendConfigData(HEADMTSStaticData_t *pStaticData, HEADMTSCfgData_t *pMTSConfigData, const uint8 pCfg[], uint32 uiCfgLen);
extern eGDBError_t HEADMTSSendSpmName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSSpmName_t *pMTSSpmData);
extern eGDBError_t HEADMTSSendDGSMStateName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSDGSMStateName_t *pMTSStateData);
extern eGDBError_t HEADMTSSendTransitions(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pStaticData, HEADMTSTransitionData_t *pMTSTransitionData);
#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_MTS_H_INCLUDED */

