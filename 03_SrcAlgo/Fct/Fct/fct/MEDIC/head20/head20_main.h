/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_main.h

DESCRIPTION:               header of the head process

AUTHOR:                    $Author: Sekar, Balaji02 (uids6618) $

CREATION DATE:             $Date: 2020/11/13 05:23:55CET $

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            1.3.1.1 (HEAD 2.0)

**************************************************************************** */

#ifndef HEAD20_MAIN_H_INCLUDED
#define HEAD20_MAIN_H_INCLUDED

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

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/
/*!  @cond Doxygen_Suppress */
extern HEADHypothesisList_t HEADHypothesisList;
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
extern uint16 HypCheckEnableCondtions[HEAD_AUTO_CFG_NO_MODULES];
#endif
/*! @endcond */

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
#if HEAD_CFG_PRECONDITION == MEDIC_ON
extern eGDBError_t HEADInitialize(HEADMTSStaticData_t *pMTSStaticData, HEADModuleList_t *pModuleList, HEADPreConditionList_t* pPreCondList);
#else
extern eGDBError_t HEADInitialize(HEADMTSStaticData_t *pMTSStaticData, HEADModuleList_t *pModuleList);
#endif

extern eGDBError_t HEADRun(const float32 fCycleTime, const struct HEADInputData_t *pInputData,const void *pExtraInputValues, 
                           HEADMTSSendExtraInputSignals_ft *fpExtraValueFct,                           
                           HEADMTSData_t *pMTSData, 
                           HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleCommonOut_t *pHEADMTSModuleCommonOut,
                           uint32 *puiCurrCycleCnt);
extern eGDBError_t HEADUpdateHypothesisList(uint8 *pMaxHypoIndex, uint8 *pMaxHypKin);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
static void HEADCheckNewHypothesis(const struct HEADInputData_t *const pInputData);
#endif

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_MAIN_H_INCLUDED */

