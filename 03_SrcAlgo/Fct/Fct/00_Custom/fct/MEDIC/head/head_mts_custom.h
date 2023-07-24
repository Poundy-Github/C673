/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_mts_custom.h

DESCRIPTION:               Implementation of the head mts output

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/06/24 08:34:01CEST $

VERSION:                   $Revision: 1.3.9.1 $  

LEGACY VERSION:            1.2.1.4            

**************************************************************************** */
/**
@ingroup head_mts_custom
@{ **/
#ifndef _HEAD_MTS_CUSTOM_H_INCLUDED
#define _HEAD_MTS_CUSTOM_H_INCLUDED

/** @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/** @endcond */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief  Custom parameter for PreBrake Active Time 2 
    @typical 20   -       */
//#define HEAD_CUST_PAR_BRK_ACT2   HEADHypOutType_CustomPar_01

///*! @brief  Custom parameter for table distance over vrelX 
//    @typical 21   -       */
//#define HEAD__OBJ_LT_HQ      HEADHypOutType_CustomPar_02

///*! @brief  Custom parameter for table distance over vrelX
//    @typical 22   -       */
//#define HEAD_CUST_PAR_DRV_FDBCK  HEADHypOutType_CustomPar_03

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ****************************************************************
    TYPEDEF STRUCT HEADMTSCustParSignal_t
    **************************************************************** */
/*! @brief HEAD MTS Customer paramter hypthesis signal
    @general HEAD MTS Customer Paramter Signal
    @conseq [None]
    @attention [None] */
typedef struct 
{
  float32 Values[ HEAD_MAX_NUMBER_OF_CD_HYPS ];  /*!<Values */
  uint8   uiCustParIdx;/*!< Customer Paramter ID*/
  uint8   uiDummy1;/*!< Dummy 1*/
  uint8   uiDummy2;/*!< Dummy 2*/
  uint8   uiDummy3;/*!< Dummy 3*/
} HEADMTSCustParHypSignal_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADMTSCustParIndSignal_t
    **************************************************************** */
/*! @brief HEAD MTS Customer Hypothesis independent Parameter Signal
    @general HEAD MTS Customer Hypothesis independent Parameter Signal
    @conseq [None]
    @attention [None] */
typedef struct 
{
  float32 Value;  /*!<Values */
  uint8   uiCustParIdx;/*!< Customer Paramter ID*/
  uint8   uiDummy1;/*!< Dummy 1*/
  uint8   uiDummy2;/*!< Dummy 2*/
  uint8   uiDummy3;/*!< Dummy 3*/
} HEADMTSCustParIndSignal_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADMTSCustHypData_t
    **************************************************************** */
/*! @brief HEAD MTS Customer Hypthesis Data
    @general Additional block for customer specific hypothesis parameters
    @conseq [None]
    @attention [None] */
typedef struct 
{
  HEADMTSCustParHypSignal_t PreBrkActTime2;     /*!< Pre Brake Active Time2*/
  HEADMTSCustParHypSignal_t ObjLifeTimeHiQual;  /*!< Object Life Time High Quality */
  HEADMTSCustParHypSignal_t DrvFeedBack;        /*!< Driver Feed Back*/
  HEADMTSCustParIndSignal_t StillStandExtDeact; /*!< StillStandExtDeact*/
} HEADMTSCustHypData_t;

/* ****************************************************************
    TYPEDEF STRUCT MTS information
    **************************************************************** */
/*! @brief HEAD MTS information.
    @general HEAD MTS information
    @conseq [None]
    @attention [None] */
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
    @attention [None] */
typedef struct  
{
  HEADBitField_t CodedInhibitionMask[HEAD_MAX_NUMBER_OF_CD_HYPS]; /*!<MTS CodedInhibitionMask */
} HEADMTSCodedInhibition_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern void HEADMTSSetDrvFeedBack(float32 fValue);
extern void HEADMTSCustomInit(void);

extern eGDBError_t HEADCustomMTSFreezeData(HEADMTSSpecificData_t *pHEADMTSExtData, 
                                    HEADMTSCodedInhibition_t *pHEADMTSCodedInhibition, 
                                    HEADMTSConditionsOKTimer_t *pHEADMTSConditionsOKTimer,
                                    HEADMTSModuleCommonOut_t *pHEADMTSModuleCommonOut,
                                    HEADMTSData_t *pHEADMTSData, 
                                    const struct HEADInputData_t *pInputData);

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif /*_HEAD_MTS_CUSTOM_H_INCLUDED*/

/**@}*/ 
