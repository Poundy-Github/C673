/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_par_fct.h

DESCRIPTION:               Header of the HEAD parameter functions

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:48:21CEST $

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            1.21

**************************************************************************** */
/**
@ingroup head_par_fct
@{ **/
#ifndef HEAD_PAR_FCT_H_INCLUDED
#define HEAD_PAR_FCT_H_INCLUDED
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

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
  /*!  @cond Doxygen_Suppress */

extern eGDBError_t HEADParamSetScalar(HEADParameterScalar_t *pParam, HEADParameterEmpty_t *pRoot, 
                                      eHEADParamOutType_t eOutputType, HEADParameterMode_t bfMode, 
                                      HEADParameterHypothesisSub_t bfHypothesis, 
                                      eHEADParamMainValueType_t eMainValueType, HEADParameterState_t bfParamState, 
                                      float32 fValue, eHEADParamOperator_t eOperator, HEADParameterOrGroup_t uiOrGroup);

extern eGDBError_t HEADParamSetScalarWithBitPack(HEADParameterScalar_t *pParam, HEADParameterEmpty_t *pRoot, 
                                                 eHEADParamOutType_t eOutputType, HEADParameterMode_t bfMode,
                                                 HEADParameterHypothesisSub_t bfHypothesis, 
                                                 eHEADParamMainValueType_t eMainValueType, HEADParameterState_t bfParamState, 
                                                 float32 fValue, eHEADParamOperator_t eOperator, 
                                                 HEADParameterOrGroup_t uiOrGroup, HEADEBAObjectClass_t bfObjectClass, 
                                                 HEADEBADynProp_t bfDnyamicProp, HEADBitPack_t bitPack);
extern eGDBError_t HEADParamSetTable(HEADParameterTable_t *pParam, HEADParameterEmpty_t *pRoot, eHEADParamOutType_t eOutputType, 
                                     HEADParamTableType_t eTableType, HEADParameterMode_t bfMode, 
                                     HEADParameterHypothesisSub_t bfHypothesis, eHEADParamMainValueType_t eMainValueType, 
                                     HEADParameterState_t bfParamState, uint8 uiNrOfRows, const void *pTable, 
                                     eHEADParamOperator_t eOperator, HEADParameterOrGroup_t uiOrGroup, 
                                     float32 fDefaultValue, eHEADParameterTableFloatType_t eFloatType);
extern eGDBError_t HEADParamSetTableWithBitPack(HEADParameterTable_t *pParam, HEADParameterEmpty_t *pRoot, 
                                                eHEADParamOutType_t eOutputType, HEADParamTableType_t eTableType, 
                                                HEADParameterMode_t bfMode, HEADParameterHypothesisSub_t bfHypothesis, 
                                                eHEADParamMainValueType_t eMainValueType, HEADParameterState_t bfParamState, 
                                                uint8 uiNrOfRows, const void *pTable, eHEADParamOperator_t eOperator,
                                                HEADParameterOrGroup_t uiOrGroup, float32 fDefaultValue, eHEADParameterTableFloatType_t eFloatType,
                                                HEADEBAObjectClass_t bfObjectClass, HEADEBADynProp_t bfDnyamicProp, HEADBitPack_t bitPack);
extern eGDBError_t HEADGetParam(const HEADParameterEmpty_t *pParam, const struct HEADInputData_t *pInputData, 
                                const HEADHypothesis_t *pHyp, uint8 uiModuleNr, float32 *pOutValue, 
                                const HEADAdditionalTableInputValues_t* pAddTableInputs);
extern eGDBError_t HEADParamOutTypeToHypOutType(eHEADParamOutType_t eParamOutType, eHEADHypOutType_t *peHypOutType);

extern float32 HEADCalculatePolygonValuef16(uint8 uiNrOfTableRows, const f16_t pTable[], float32 fInputValue);
  /*! @endcond */
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS HEADCalculatePolygonValuef32
#endif
extern float32 HEADCalculatePolygonValuef32(uint8 uiNrOfTableRows, const float32 pTable[], float32 fInputValue);
extern eGDBError_t HEADGetHypValue(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, boolean * bFound, float32 *retValue);
extern eGDBError_t HEADGSMGetIndValue(const struct HEADInputData_t *pInputData, const eHEADParamOutType_t eOutType, const uint8 uiModuleNr, float32 *pfParamValue);
extern eGDBError_t HEADIsHypDependentParameter( eHEADParamOutType_t eOutType, boolean* bRetValue );

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* HEAD_PAR_FCT_H_INCLUDED */
/**@}*/

