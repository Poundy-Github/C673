/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_par_fct.h

DESCRIPTION:               Header of the HEAD parameter functions

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 16:02:16CEST $

VERSION:                   $Revision: 1.16 $

LEGACY VERSION:            1.20.1.2 (HEAD 2.0)

**************************************************************************** */

#ifndef HEAD20_PAR_FCT_H_INCLUDED
#define HEAD20_PAR_FCT_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "head/head_float16_util.h"

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

extern eGDBError_t HEADDGSMParamSetScalarWithBitPack(HEADParameterScalar_t *pParam, HEADParameterEmpty_t *pRoot, 
                                                     eHEADParamOutType_t eOutputType, HEADParameterMode_t bfMode,
                                                     HEADParameterHypothesisSub_t bfHypothesis, 
                                                     eHEADParamMainValueType_t eMainValueType, 
                                                     float32 fValue, eHEADParamOperator_t eOperator, 
                                                     HEADEBAObjectClass_t bfObjectClass, 
                                                     HEADEBADynProp_t bfDnyamicProp, HEADEBAObjMovDir_t bfObjMovDir, HEADParameterSensorSourceSub_t bfSensorSource,
                                                     HEADBitPack_t bitPack);

extern eGDBError_t HEADDGSMParamSetTableWithBitPack(HEADParameterTable_t *pParam, HEADParameterEmpty_t *pRoot,
                                                    eHEADParamOutType_t eOutputType, HEADParamTableType_t eTableType, 
                                                    HEADParameterMode_t bfMode, HEADParameterHypothesisSub_t bfHypothesis,                                                  
                                                    eHEADParamMainValueType_t eMainValueType, uint8 uiNrOfRows, const void *pTable,
                                                    eHEADParamOperator_t eOperator, float32 fDefaultValue, 
                                                    eHEADParameterTableFloatType_t eFloatType, HEADEBAObjectClass_t bfObjectClass, 
                                                    HEADEBADynProp_t bfDnyamicProp, HEADEBAObjMovDir_t bfObjMovDir, HEADParameterSensorSourceSub_t bfSensorSource, 
                                                    HEADBitPack_t bitPack);

extern eGDBError_t HEADDGSMParamSet3dTableWithBitPack(HEADParameterTable3D_t *pParam, HEADParameterEmpty_t *pRoot,
                                                    eHEADParamOutType_t eOutputType, HEADParamTableType_t eTableType1,
                                                    HEADParamTableType_t eTableType2, HEADParameterMode_t bfMode, 
                                                    HEADParameterHypothesisSub_t bfHypothesis, eHEADParamMainValueType_t eMainValueType,
                                                    uint8 uiNrOfRows, uint8 uiNrOfCols, const void *pTable, eHEADParamOperator_t eOperator,
                                                    float32 fDefaultX1Val, float32 fDefaultX2Val, eHEADParam3DTableX2Type_t X2SignalType, 
                                                    boolean X2DefaultResult, eHEADParameterTableFloatType_t eFloatType, 
                                                    HEADEBAObjectClass_t bfObjectClass, HEADEBADynProp_t bfDnyamicProp, HEADEBAObjMovDir_t bfObjMovDir, 
                                                    HEADParameterSensorSourceSub_t bfSensorSource, HEADBitPack_t bitPack);


extern eGDBError_t HEADGetParam(const HEADParameterEmpty_t *pParam, const struct HEADInputData_t *pInputData, 
                                const HEADHypothesis_t *pHyp, const uint8 uiHypNo, uint8 uiModuleNr, float32 *pOutValue, 
                                const HEADAdditionalTableInputValues_t* pAddTableInputs, boolean *pbFound);
extern eGDBError_t HEADParamOutTypeToHypOutType(eHEADParamOutType_t eParamOutType, eHEADHypOutType_t *peHypOutType);

extern float32 HEADCalculatePolygonValuef16(uint8 uiNrOfTableRows, const f16_t pTable[], float32 fInputValue);
extern float32 HEADCalculatePolygon3DValuef16(uint8 uiNrOfTableRows, uint8 uiTableCol2Index, const f16_t pTable[], float32 fInputValue);
  /*! @endcond */
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS HEADCalculatePolygonValuef32
#endif
extern float32 HEADCalculatePolygonValuef32(uint8 uiNrOfTableRows, const float32 pTable[], float32 fInputValue);
extern float32 HEADCalculatePolygon3DValuef32(uint8 uiNrOfTableRows, uint8 uiTableCol2Index, const float32 pTable[], float32 fInputValue);
static float32 HEADInterpolation(const float32 fPoint1, const float32 fPoint2, const float32 fPoint2Weight);
static void HEADGet3dTableNearKnownValsAndWtg(const HEADParameterTable3D_t *pParamTable, float32 fInputValue, uint8 uiRelativeIndex[], 
                                              float32 *pWeightRight, boolean bIsInputValueForX1);
extern eGDBError_t HEADGetHypValue(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, const uint8 uiHypNo, eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, boolean * bFound, float32 *retValue, const uint16 uiCascadeNo);
extern eGDBError_t HEADGSMGetIndValue(const struct HEADInputData_t *pInputData, const eHEADParamOutType_t eOutType, const uint8 uiModuleNr, float32 *pfParamValue);

extern eGDBError_t HEADIsHypDependentParameter( eHEADParamOutType_t eOutType, boolean* bRetValue );

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_PAR_FCT_H_INCLUDED */

