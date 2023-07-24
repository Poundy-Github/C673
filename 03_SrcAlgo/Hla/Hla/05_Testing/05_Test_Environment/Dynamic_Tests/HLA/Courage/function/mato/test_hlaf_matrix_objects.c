/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* include for hlaf matrix objects */
#include "hlaf_matrix_objects.h"

#include "../../mockup_services.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_HLAFMatrix_PrepareObjectList_001 COU_TEST
#define TEST_HLAFMatrix_PrepareObjectList_002 COU_TEST
#define test_HLAFMatrix_PrepareObjects_EMObjectsActivatedInCfg_FunctionGetsCalled COU_TEST
#define TEST_HLAFMatrix_SAEConformLight_001 COU_TEST
#define TEST_HLAFMatrix_SAEConformLight_002 COU_TEST
#define TEST_HLAFMatrix_SAEConformLight_003 COU_TEST
#define TEST_HLAFMatrix_SAEConformLight_004 COU_TEST
#define TEST_HLAFMatrix_SAEConformLight_005 COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OncomingProbabilityHigh_RelevantOncomingSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_PrecedingProbabilityHigh_RelevantPrecedingSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OncPrecProbabilityLow_NoFlagSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncStillAboveThreshold_OncomingFlagSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncBelowThreshold_OncomingFlagNotSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedProbTooLow_OncomingFlagNotSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecStillAboveThreshold_PrecedingFlagSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecNoLongerThreshold_PrecedingFlagNotSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedTraceTimeTooShort_PrecedingFlagNotSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedIDsDoNotMatch_PrecedingFlagNotSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_TruckLightStatusBit_RelevantOncomingSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_ObjectIsPaired_RelevantFlagSet COU_TEST
#define test_HLAFMatrix_CheckIfLightIsRelevant_StickyInRange_RelevantOncomingSet COU_TEST
#define TEST_HLAFMatrix_AddRelevantObjectToList_001 COU_TEST
#define TEST_HLAFMatrix_AddRelevantObjectToList_002 COU_TEST
#define TEST_HLAFMatrix_AddRelevantObjectToList_003 COU_TEST
#define TEST_HLAFMatrix_SetPairIndex_001 COU_TEST
#define TEST_HLAFMatrix_SetPairIndex_002 COU_TEST
#define TEST_HLAFMatrix_AddEMObjToIntObjList_001 COU_TEST
#define TEST_HLAFMatrix_SplitEMObj_001 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_001 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_002 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_003 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_004 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_005 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_006 COU_TEST
#define TEST_HLAFMatrix_PrepareIntEMObjectList_007 COU_TEST
#define test_HLAFMatrix_PrepareRadarObjectList_InputChecksArePerformed_FunctionGetsCalledIfChecksAreValid COU_TEST
#define test_HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFound_SplitFunctionIsCalled COU_TEST
#define test_HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFoundLifeCycleNotReached_SplitFunctionIsNotCalled COU_TEST
#define test_HLAFMatrix_CheckRadarObjectList_ObjectIsNotRelevant_SplitFunctionIsNotCalled COU_TEST
#define test_HLAFMatrix_SplitRadarObj_ObjectIsInRadarFusionRegion_ObjectIsSplit COU_TEST
#define test_HLAFMatrix_SplitRadarObj_ObjectIsInRadarOnlyRegion_ObjectIsSplit COU_TEST
#define test_HLAFMatrix_SplitRadarObj_ObjectIsNotRelevant_ObjectIsNotSplit COU_TEST
#define test_HLAFMatrix_MergeRadarObj_ObjectIsNotPreceding_AnglesAreNotUpdated COU_TEST
#define test_HLAFMatrix_MergeRadarObj_InternalObjectNotWithinRadarObject_AnglesAreNotUpdated COU_TEST
#define test_HLAFMatrix_MergeRadarObj_InternalObjectWithinRadarObject_AnglesAreUpdated COU_TEST
#define test_HLAFMatrix_CheckRadarObjRelevance_NoLightsInRadarAngles_CounterIsDecreased COU_TEST
#define test_HLAFMatrix_CheckRadarObjRelevance_LightsInRadarAngles_CounterIsIncreased COU_TEST

/* Declaration of static functions */
extern void HLAFMatrix_PrepareIntEMObjectList( const EM_t_GenObjectList*      const pEMObjectList,
                                               const t_MatrixParametersInput* const pInputPar,
                                                     HLAFMatrixData_t*        const pData
                                             );

extern void HLAFMatrix_SplitEMObj( const EM_t_GenObject*   const pEMObject,
                                         HLAFMatrixData_t* const pData
                                 );

extern void HLAFMatrix_AddEMObjToIntObjList( const EM_t_GenObject*   const pEMObject,
                                                   HLAFMatrixData_t* const pData,
                                             const float32                 angle,
                                             const uint8                   idx
                                           );

extern boolean HLAFMatrix_SAEConformLight( const reqHlaPrtList_t*       const pReqPorts,
                                           const LSD_LightObject_t*     const pLightObject,
                                           const t_MatrixParametersSAE* const pParameter
                                         );

extern void HLAFMatrix_CheckIfLightIsRelevant( const RTE_HLAF_ParameterVehicleProbability_t* const pVehProbPar,
                                               const LSD_LightObject_t*                      const pLightObject,
                                                     HLAObjectDataInt_t*                     const pInternalObject,
                                               const HLAFMatrixData_t*                       const pData,
                                               const t_MatrixParametersInput*                const pInputPar
                                             );

extern void HLAFMatrix_AddRelevantObjectToList( const LSD_LightObject_t*     const pLightObject,
                                                const LSD_LightObjectList_t* const pObjectList,
                                                const LSD_LightList_t*       const pLightList,
                                                      HLAObjectDataInt_t*    const pInternalObject,
                                                      uint8*                 const pIdxObjectList
                                              );

extern void HLAFMatrix_SetPairIndex( HLAFMatrixData_t* const pData );

extern  void HLAFMatrix_PrepareRadarObjectList( const HLA_RadarObjectList_t*   const pRadarObjectList,
                                                const LSD_LightObjectList_t*   const pLSDObjectList,
                                                const t_MatrixParametersInput* const pInputPar,
                                                      HLAFMatrixData_t*        const pData
                                              );

extern void HLAFMatrix_CheckRadarObjectList( const HLA_RadarObjectList_t*   const pRadarObjectList,
                                             const LSD_LightObjectList_t*   const pLSDObjectList,
                                             const t_MatrixParametersInput* const pInputPar,
                                                   HLAFMatrixData_t*        const pData
                                           );

extern void HLAFMatrix_SplitRadarObj( const HLA_RadarObject_t*       const pRadarObject,
                                      const LSD_LightObjectList_t*   const pLSDObjectList,
                                      const t_MatrixParametersInput* const pInputPar,
                                      const eHLARadarFusionRegion          FusionRegion,
                                            HLAFMatrixData_t*        const pData
                                    );

extern void HLAFMatrix_MergeRadarObj( const HLAFMatrixData_t*        const pData,
                                      const t_MatrixParametersInput* const pInputPar,
                                            float32*                 const pAngleLeft,
                                            float32*                 const pAngleRight,
                                            uint8*                   const pFusedIDLeft,
                                            uint8*                   const pFusedIDRight
                                    );

extern uint8 HLAFMatrix_CheckRadarObjRelevance( const HLA_RadarObject_t*       const pRadarObject,
                                                const HLAFMatrixData_t*        const pData,
                                                const LSD_LightObjectList_t*   const pLSDObjectList,
                                                const t_MatrixParametersInput* const pInputPar,
                                                const eHLARadarFusionRegion          FusionRegion,
                                                const float32*                 const pAngleLeft,
                                                const float32*                 const pAngleRight
                                              );


void InitData(void);
void SetDefaultParameter(void);

HLAFData_t              FData;
t_MatrixParameters      HlafMatrixParameter;
HLA_RadarObjectList_t   RadarObjectList;
LSD_LightObjectList_t   LsdLightObjectList;

void HLACamRotGetXb(       float32* const xb,
                           float32* const yb,
                     const float32        xw,
                     const float32        yw,
                     const float32        zw
                    )
{
  if(yw < 0.0f)
  {
    *xb = 0.0f;
    *yb = 0.0f;
  }
  else
  {
    *xb = 10.0f;
    *yb = 10.0f;
  }
}

/* Init function */
void InitData(void)
{
  Mockup_InitGlobVars();

  memset(&FData, 0, sizeof(FData));
  memset(&HlafMatrixParameter, 0, sizeof(HlafMatrixParameter));
  memset(&RadarObjectList, 0, sizeof(RadarObjectList));

  LsdLightObjectList.numObjects = 0;
  SetDefaultParameter();
}

/* Function to set default parameters */
void SetDefaultParameter(void)
{
  HlafMatrixParameter.SAE.minIntTurnOff = 2000;
  HlafMatrixParameter.SAE.minIntTurnOffRightOffset = 39000u;

  HlafMatrixParameter.Input.EMObjMaxDist = 100.0f;
  HlafMatrixParameter.Input.EMObjUpperProbabilityThresh = 75u;
  HlafMatrixParameter.Input.EMObjLowerProbabilityThresh = 25u;

  HlafMatrixParameter.Input.RadarObjMinDynConfidence  = 90u;
  HlafMatrixParameter.Input.RadarObjMinProbOfEx = 99u;
  HlafMatrixParameter.Input.RadarObjMinClassConfidence = 50u;
  HlafMatrixParameter.Input.RadarObjAngleFusionRegion = 0.33161255f;
  HlafMatrixParameter.Input.RadarObjDistFusionRegion = 100.0f;
  HlafMatrixParameter.Input.RadarObjAngleRadarOnlyRegion = 0.52359877f;
  HlafMatrixParameter.Input.RadarObjDistRadarOnlyRegion = 50.0f;
  HlafMatrixParameter.Input.RadarObjLatDistRadarOnlyRegion = 8.0f;
  HlafMatrixParameter.Input.RadarObjAssumedWidth = 3.0f;
  HlafMatrixParameter.Input.RadarFusionMaxAngleDiff = 0.02f;
  HlafMatrixParameter.Input.RadarObjCloseObjDist = 50.0f;
  HlafMatrixParameter.Input.RadarObjMinLifeCycles = 40u;

  HlafMatrixParameter.Input.RadarObjRelCountSmallStep = 1u;
  HlafMatrixParameter.Input.RadarObjRelCountBigStep = 6u;
  HlafMatrixParameter.Input.RadarObjSmallStepCounterThres = 2u;
  HlafMatrixParameter.Input.RadarObjRelevanceThres = 5u;
  HlafMatrixParameter.Input.RadarObjMinVehProb = 90u;

  CPar_HlafPar.VehicleProbabilities.thresholdUpperOncoming         = 90u;
  CPar_HlafPar.VehicleProbabilities.thresholdUpperPreceding        = 90u;
  CPar_HlafPar.VehicleProbabilities.thresholdUpperOncomingHighway  = 90u;
  CPar_HlafPar.VehicleProbabilities.thresholdUpperPrecedingHighway = 90u;
  CPar_HlafPar.VehicleProbabilities.thresholdUpperOncomingCity     = 90u;
  CPar_HlafPar.VehicleProbabilities.thresholdUpperPrecedingCity    = 90u;
  CPar_HlafPar.VehicleProbabilities.thresholdLowerOncoming         = 10u;
  CPar_HlafPar.VehicleProbabilities.thresholdLowerPreceding        = 10u;
  CPar_HlafPar.VehicleProbabilities.thresholdLowerOncomingHighway  = 10u;
  CPar_HlafPar.VehicleProbabilities.thresholdLowerPrecedingHighway = 10u;
  CPar_HlafPar.VehicleProbabilities.thresholdLowerOncomingCity     = 10u;
  CPar_HlafPar.VehicleProbabilities.thresholdLowerPrecedingCity    = 10u;

}

/** \test
 *  \description
 *     Check that object is added to internal list. \n
 *     calls function HLAFMatrix_PrepareObjects() \n
 *  \precondition
 *     None \n
 *  \result
 *     numRelObj is set to 1. \n */
TEST_HLAFMatrix_PrepareObjectList_001(HLAFMatrix_PrepareObjectList_001, "Test that object is added to internal list")
{
  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 100u;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareObjects(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRelObj, 1, "one object was added to internal list");
}

/** \test
 *  \description
 *     Check that object is not added to internal list if not SAE compliant. \n
 *     calls function HLAFMatrix_PrepareObjects() \n
 *  \precondition
 *     None \n
 *  \result
 *     numRelObj is set to zero. \n */
TEST_HLAFMatrix_PrepareObjectList_002(HLAFMatrix_PrepareObjectList_002, "Test that object is not added to internal list if not SAE compliant")
{
  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 100u;
  /* intensity is very low */
  LsdLightObjectList.lightObjects[0].attributes.intensity = 1u;
  /* SAE testmode is active */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_SAE;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareObjects(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRelObj, 0, "no object was added to internal list");
}

/** \test
 *  \description
 *     Test that EM object function is called when it is activated in config. \n
 *     calls function HLAFMatrix_PrepareObjects() \n
 *  \precondition
 *     None \n
 *  \result
 *     numRelObj is set to zero. \n */
test_HLAFMatrix_PrepareObjects_EMObjectsActivatedInCfg_FunctionGetsCalled(HLAFMatrix_PrepareObjects_EMObjectsActivatedInCfg_FunctionGetsCalled, "Test that EM object function is called when it is activated in config")
{

  /* EM objects activated via coding */
  HlafMatrixParameter.Cfg.bUseEMInputforMatrixFunction = b_TRUE;

  /* Use numEMObj parameter to see if function gets called, this parameter is set to zero in beginning of function */
  FData.hlafMatrixData.numEMObj = 2;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareObjects(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 0, "function was called");
}

/** \test
 *  \description
 *     Check that SAE conform status is correctly set. \n
 *     calls function HLAFMatrix_SAEConformLight() \n
 *  \precondition
 *     None \n
 *  \result
 *     Return value is set to false. \n */
TEST_HLAFMatrix_SAEConformLight_001(HLAFMatrix_SAEConformLight_001, "Test that SAE conform status is correctly set")
{
  boolean IsSAEConfromReturnValue;
  /* set inputs */
  /* SAE testmode is active */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_SAE;
  /* intensity if not high enough */
  LsdLightObjectList.lightObjects[0].attributes.intensity = 1u;

  /* call function */
  COU_CALL(IsSAEConfromReturnValue = HLAFMatrix_SAEConformLight(&ReqPorts, &LsdLightObjectList.lightObjects[0], &HlafMatrixParameter.SAE), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(IsSAEConfromReturnValue, b_FALSE, "light is not SAE conform");
}

/** \test
 *  \description
 *     Check that SAE conform status is correctly set. \n
 *     calls function HLAFMatrix_SAEConformLight() \n
 *  \precondition
 *     None \n
 *  \result
 *     Return value is set to false. \n */
TEST_HLAFMatrix_SAEConformLight_002(HLAFMatrix_SAEConformLight_002, "Test that SAE conform status is correctly set")
{
  boolean IsSAEConfromReturnValue;
  /* set inputs */
  /* US sensitivity mode is active */
  HlaBusInputSignals.sensitivityModeSignal = RTE_HLA_SENSMODE_US;
  CPar_HlafPar.AlgoCfg.sensitivityMode = RTE_HLA_CPAR_SENSITIVITY_MODE_US;
  /* intensity if not high enough */
  LsdLightObjectList.lightObjects[0].attributes.intensity = 3000u;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 12u;

  /* call function */
  COU_CALL(IsSAEConfromReturnValue = HLAFMatrix_SAEConformLight(&ReqPorts, &LsdLightObjectList.lightObjects[0], &HlafMatrixParameter.SAE), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(IsSAEConfromReturnValue, b_FALSE, "light is not SAE conform");
}

/** \test
 *  \description
 *     Check that SAE conform status is correctly set. \n
 *     calls function HLAFMatrix_SAEConformLight() \n
 *  \precondition
 *     None \n
 *  \result
 *     Return value is set to false. \n */
TEST_HLAFMatrix_SAEConformLight_003(HLAFMatrix_SAEConformLight_003, "Test that SAE conform status is correctly set")
{
  boolean IsSAEConfromReturnValue;
  /* set inputs */
  /* US sensitivity mode is active */
  HlaBusInputSignals.sensitivityModeSignal = RTE_HLA_SENSMODE_US;
  /* config is set to default -> no SAE check */
  CPar_HlafPar.AlgoCfg.sensitivityMode = RTE_HLA_CPAR_SENSITIVITY_MODE_DEFAULT;
  /* intensity is not high enough */
  LsdLightObjectList.lightObjects[0].attributes.intensity = 3000u;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 10u;

  /* call function */
  COU_CALL(IsSAEConfromReturnValue = HLAFMatrix_SAEConformLight(&ReqPorts, &LsdLightObjectList.lightObjects[0], &HlafMatrixParameter.SAE), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(IsSAEConfromReturnValue, b_TRUE, "light is SAE conform");
}

/** \test
 *  \description
 *     Check that SAE conform status is correctly set. \n
 *     calls function HLAFMatrix_SAEConformLight() \n
 *  \precondition
 *     None \n
 *  \result
 *     Return value is set to false. \n */
TEST_HLAFMatrix_SAEConformLight_004(HLAFMatrix_SAEConformLight_004, "Test that SAE conform status is correctly set")
{
  boolean IsSAEConfromReturnValue;
  /* set inputs */
  /* US sensitivity mode is active */
  HlaBusInputSignals.sensitivityModeSignal = RTE_HLA_SENSMODE_US;
  CPar_HlafPar.AlgoCfg.sensitivityMode = RTE_HLA_CPAR_SENSITIVITY_MODE_US;
  /* intensity if not high enough */
  LsdLightObjectList.lightObjects[0].attributes.intensity = 3000u;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 0u;

  /* call function */
  COU_CALL(IsSAEConfromReturnValue = HLAFMatrix_SAEConformLight(&ReqPorts, &LsdLightObjectList.lightObjects[0], &HlafMatrixParameter.SAE), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(IsSAEConfromReturnValue, b_TRUE, "light is SAE conform");
}

/** \test
 *  \description
 *     Check that SAE conform status is correctly set. \n
 *     calls function HLAFMatrix_SAEConformLight() \n
 *  \precondition
 *     None \n
 *  \result
 *     Return value is set to false. \n */
TEST_HLAFMatrix_SAEConformLight_005(HLAFMatrix_SAEConformLight_005, "Test that SAE conform status is correctly set")
{
  boolean IsSAEConfromReturnValue;
  /* set inputs */
  /* US sensitivity mode is active */
  HlaBusInputSignals.sensitivityModeSignal = RTE_HLA_SENSMODE_US;
  CPar_HlafPar.AlgoCfg.sensitivityMode = RTE_HLA_CPAR_SENSITIVITY_MODE_US;
  /* intensity if not high enough */
  LsdLightObjectList.lightObjects[0].attributes.intensity = 40000u;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 0u;

  /* call function */
  COU_CALL(IsSAEConfromReturnValue = HLAFMatrix_SAEConformLight(&ReqPorts, &LsdLightObjectList.lightObjects[0], &HlafMatrixParameter.SAE), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(IsSAEConfromReturnValue, b_TRUE, "light is SAE conform");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is set when oncoming probability is high enough. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to true. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OncomingProbabilityHigh_RelevantOncomingSet(HLAFMatrix_CheckIfLightIsRelevant_OncomingProbabilityHigh_RelevantOncomingSet, "Test that relevant oncoming flag is set when oncoming probability is high enough")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 100u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_TRUE, "relevant oncoming set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is set when truck light bit is set. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to true. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_TruckLightStatusBit_RelevantOncomingSet(HLAFMatrix_CheckIfLightIsRelevant_TruckLightStatusBit_RelevantOncomingSet, "Test that relevant oncoming flag is set when truck light bit is set")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_TRUE, "relevant oncoming set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is set when sticky conditions are met. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to true. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_StickyInRange_RelevantOncomingSet (HLAFMatrix_CheckIfLightIsRelevant_StickyInRange_RelevantOncomingSet, "Test that relevant oncoming flag is set when sticky conditions are met.")
{
   /* set inputs */
   LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 60u;
   LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 0u;
   LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
   LsdLightObjectList.lightObjects[0].general.cyclesTraced = 5;
   LsdLightObjectList.lightObjects[0].kinematic.camera.x = 5;

   FData.hlafMatrixData.numRelObjPrev = 1;
   /* same light objectID */
   FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
   /* was classified as a relative oncoming */
   FData.hlafMatrixData.ObjectPrev[0].bIsRelevantOnc = b_TRUE;
   /* Define ROI parameters to control camRot */
   HlafMatrixParameter.Input.LSDRoiRegionCenterLeftOffset = -1.0f;
   HlafMatrixParameter.Input.LSDRoiRegionCenterRightOffset = +1.0f;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_TRUE, "relevant oncoming set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
}

/** \test
 *  \description
 *     Check that relevant preceding flag is set when preeding probability is high enough. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantPrec is set to true. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_PrecedingProbabilityHigh_RelevantPrecedingSet(HLAFMatrix_CheckIfLightIsRelevant_PrecedingProbabilityHigh_RelevantPrecedingSet, "Test that relevant preceding flag is set when preceding probability is high enough")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 100u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_TRUE, "relevant preceding set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant preceding flag is set when preceding probability is high enough. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantPrec is set to true. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OncPrecProbabilityLow_NoFlagSet(HLAFMatrix_CheckIfLightIsRelevant_OncPrecProbabilityLow_NoFlagSet, "Test that no relevant preceding/oncoming flag is set when probabilities are not high enough")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 0u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is set, if light was once detected as oncoming is still above lower threshold. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to true. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncStillAboveThreshold_OncomingFlagSet(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncStillAboveThreshold_OncomingFlagSet, "Test that relevant oncoming flag is set, if light was once detected as oncoming is still above lower threshold")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 60u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 0u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 5;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantOnc = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_TRUE, "relevant oncoming set");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is not set, if light was once detected as oncoming, but is not above lower threshold. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncBelowThreshold_OncomingFlagNotSet(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncBelowThreshold_OncomingFlagNotSet, "Test that relevant oncoming flag is not set, if light was once detected as oncoming, but is not above lower threshold")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 5u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 0u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 5;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantOnc = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is not set, if light was once detected as oncoming, but is not above lower threshold. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedProbTooLow_OncomingFlagNotSet(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedProbTooLow_OncomingFlagNotSet, "Test that relevant oncoming flag is not set, if light was not detected as oncoming")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 50u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 0u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 5;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantOnc = b_FALSE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant oncoming flag is not set, if light was once detected as preceding, but is not above lower threshold. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecStillAboveThreshold_PrecedingFlagSet(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecStillAboveThreshold_PrecedingFlagSet, "Test that relevant preceding flag is set, if light was once detected as preceding and is still above lower threshold")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 50u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 5;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantPrec = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_TRUE, "relevant preceding set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant preceding flag is set, if light was once detected as preceding, but is not above lower threshold. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecNoLongerThreshold_PrecedingFlagNotSet(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecNoLongerThreshold_PrecedingFlagNotSet, "Test that relevant preceding flag is set, if light was once detected as preceding, but is not above lower threshold")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 5u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 5;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantPrec = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant preceding flag is not set, if light was not traced long enough. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedTraceTimeTooShort_PrecedingFlagNotSet(HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedTraceTimeTooShort_PrecedingFlagNotSet, "Test that relevant preceding flag is not set, if light was not traced long enough")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 50u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 1;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 10;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantPrec = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant preceding flag is not set, if light IDs do not match. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedIDsDoNotMatch_PrecedingFlagNotSet(HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedIDsDoNotMatch_PrecedingFlagNotSet, "Test that relevant preceding flag is not set, if light IDs do not match")
{
  /* set inputs */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0u;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 50u;
  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 1;

  FData.hlafMatrixData.numRelObjPrev = 1;
  /* same light objectID */
  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 11;
  /* was classified as a relative oncoming */
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantPrec = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}
/** \test
 *  \description
 *     Check that relevant preceding/oncoming flags are set, if light ID is paired. \n
 *     calls function HLAFMatrix_CheckIfLightIsRelevant() \n
 *  \precondition
 *     None \n
 *  \result
 *     bIsRelevantOnc is set to false. \n */
test_HLAFMatrix_CheckIfLightIsRelevant_ObjectIsPaired_RelevantFlagSet(HLAFMatrix_CheckIfLightIsRelevant_ObjectIsPaired_RelevantFlagSet, "Test that relevant oncoming/preceding flag are set, if light IDs are paired")
{
  LsdLightObjectList.lightObjects[0].general.lightObjectIDPaired = 1u;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 10u;
  FData.hlafMatrixData.numRelObjPrev = 1;

  FData.hlafMatrixData.ObjectPrev[0].LiObjID = 1u;
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantOnc = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_TRUE, "relevant oncoming set");

  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantOnc  = b_FALSE;
  FData.hlafMatrixData.ObjectPrev[0].bIsRelevantPrec = b_TRUE;

  /* reset */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = 0;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = 0;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_TRUE, "relevant preceding set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");

  /* no previous object */
  FData.hlafMatrixData.numRelObjPrev = 0;

  /* reset */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = 0;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = 0;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");

  /* previous object, but trace time is not long enough */
  FData.hlafMatrixData.numRelObjPrev = 1;
  LsdLightObjectList.lightObjects[0].general.cyclesTraced = 1u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckIfLightIsRelevant(&CPar_HlafPar.VehicleProbabilities, &LsdLightObjectList.lightObjects[0], &FData.hlafMatrixData.Object[0], &FData.hlafMatrixData, &HlafMatrixParameter.Input), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_FALSE, "relevant preceding not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_FALSE, "relevant oncoming not set");
}

/** \test
 *  \description
 *     Check that relevant data is copied from light object to internal object list. \n
 *     calls function HLAFMatrix_AddRelevantObjectToList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Relevant data is copied. \n */
TEST_HLAFMatrix_AddRelevantObjectToList_001(HLAFMatrix_AddRelevantObjectToList_001, "Test that relevant data is copied from light object to internal object list")
{
  uint8 IdxObjectList = 1;
  /* set inputs */
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.lightObjectIDPaired = 11;
  LsdLightObjectList.lightObjects[0].general.lightID = 15;

  /* call function */
  COU_CALL(HLAFMatrix_AddRelevantObjectToList(&LsdLightObjectList.lightObjects[0], &LsdLightObjectList, &LsdLightList, &FData.hlafMatrixData.Object[0], &IdxObjectList), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LiObjID, LsdLightObjectList.lightObjects[0].general.lightObjectID, "light object ID is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LiObjIDPair, LsdLightObjectList.lightObjects[0].general.lightObjectIDPaired, "light object ID is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject, &LsdLightObjectList.lightObjects[0], "pointer to light object is set");
  COU_ASSERT_EQUAL(IdxObjectList, 2, "counter was increased");
}

/** \test
 *  \description
 *     Check that relevant data is copied from light object to internal object list. \n
 *     calls function HLAFMatrix_AddRelevantObjectToList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Relevant data is copied. \n */
TEST_HLAFMatrix_AddRelevantObjectToList_002(HLAFMatrix_AddRelevantObjectToList_002, "Test that relevant data is copied from light object to internal object list")
{
  uint8 IdxObjectList = 1;
  /* set inputs */
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.lightObjectIDPaired = 11;
  LsdLightObjectList.lightObjects[0].general.lightID = LSD_LIGHT_LIST_LENGTH;

  /* call function */
  COU_CALL(HLAFMatrix_AddRelevantObjectToList(&LsdLightObjectList.lightObjects[0], &LsdLightObjectList, &LsdLightList, &FData.hlafMatrixData.Object[0], &IdxObjectList), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LiObjID, LsdLightObjectList.lightObjects[0].general.lightObjectID, "light object ID is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LiObjIDPair, LsdLightObjectList.lightObjects[0].general.lightObjectIDPaired, "light object ID is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject, &LsdLightObjectList.lightObjects[0], "pointer to light object is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].leftAng, LsdLightObjectList.lightObjects[0].kinematic.world.horizontalAngle, "left angle is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].rightAng, LsdLightObjectList.lightObjects[0].kinematic.world.horizontalAngle, "right angle is set");
  COU_ASSERT_EQUAL(IdxObjectList, 2, "counter was increased");
}

/** \test
 *  \description
 *     Check that relevant data is copied from light object to internal object list. \n
 *     calls function HLAFMatrix_AddRelevantObjectToList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Relevant data is copied. \n */
TEST_HLAFMatrix_AddRelevantObjectToList_003(HLAFMatrix_AddRelevantObjectToList_003, "Test that relevant data is copied from light object to internal object list")
{
  uint8 IdxObjectList = 1;
  /* set inputs */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = b_FALSE;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_FALSE;

  LsdLightObjectList.lightObjects[0].general.lightObjectID = 10;
  LsdLightObjectList.lightObjects[0].general.lightObjectIDPaired = 11;
  LsdLightObjectList.lightObjects[0].general.lightID = LSD_LIGHT_LIST_LENGTH;

  /* call function */
  COU_CALL(HLAFMatrix_AddRelevantObjectToList(&LsdLightObjectList.lightObjects[0], &LsdLightObjectList, &LsdLightList, &FData.hlafMatrixData.Object[0], &IdxObjectList), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LiObjID, 0, "light object ID is not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LiObjIDPair, 0, "light object ID is not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject, 0, "pointer to light object is not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].leftAng, 0, "left angle is not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].rightAng, 0, "right angle is not set");
  COU_ASSERT_EQUAL(IdxObjectList, 1, "counter was not increased");
}

/** \test
 *  \description
 *     Check that light object index in internal object list is correctly set. \n
 *     calls function HLAFMatrix_SetPairIndex() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct light index is set. \n */
TEST_HLAFMatrix_SetPairIndex_001(HLAFMatrix_SetPairIndex_001, "Test that light object index in internal object list is correctly set")
{
  FData.hlafMatrixData.numRelObj = 2;
  FData.hlafMatrixData.Object[0].LiObjIDPair = 1;
  FData.hlafMatrixData.Object[1].LiObjID = 1;
  /* call function */
  COU_CALL(HLAFMatrix_SetPairIndex(&FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].IntObjPairIdx, 1, "light object index is set");

}

/** \test
 *  \description
 *     Check that light object index in internal object list is correctly set. \n
 *     calls function HLAFMatrix_SetPairIndex() \n
 *  \precondition
 *     None \n
 *  \result
 *     light index is not set. \n */
TEST_HLAFMatrix_SetPairIndex_002(HLAFMatrix_SetPairIndex_002, "Test that light object index in internal object list is not set, when no pair exists")
{
  /* Set the status after initialisation */
  FData.hlafMatrixData.Object[0].IntObjPairIdx = UI8_T_MAX;
  FData.hlafMatrixData.Object[1].IntObjPairIdx = UI8_T_MAX;

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 2;
  FData.hlafMatrixData.Object[0].LiObjIDPair = 1;
  FData.hlafMatrixData.Object[1].LiObjIDPair = 8;
  FData.hlafMatrixData.Object[0].LiObjID = 0;
  FData.hlafMatrixData.Object[1].LiObjID = 2;

  /* call function */
  COU_CALL(HLAFMatrix_SetPairIndex(&FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].IntObjPairIdx, UI8_T_MAX, "light object index is not set");
}

/** \test
 *  \description
 *     Check that EM object is added to internal object list. \n
 *     calls function HLAFMatrix_AddEMObjToIntObjList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Data is correctly set. \n */
TEST_HLAFMatrix_AddEMObjToIntObjList_001(HLAFMatrix_AddEMObjToIntObjList_001, "Test that EM object is added to internal object list")
{
  float32 angle = 0.1234f;
  uint8 idx = 0;

  FData.hlafMatrixData.numEMObj = 0;
  FData.hlafMatrixData.numRelObj = 0;

  EMObjectsList.aObject[0].Kinematic.fDistX = 23.4f;
  EMObjectsList.aObject[0].General.uiID = 2;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING;

  /* call function */
  COU_CALL(HLAFMatrix_AddEMObjToIntObjList(&(EMObjectsList.aObject[0]), &FData.hlafMatrixData, angle, idx), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.EMToLSDObjList[0].kinematic.world.x, EMObjectsList.aObject[0].Kinematic.fDistX, "world x position was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.EMToLSDObjList[0].general.cyclesLost, 0, "cyclesLost was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.EMToLSDObjList[0].general.lightID, UI8_T_MAX, "lightID was set");
  COU_ASSERT_EQUAL_FMT(FData.hlafMatrixData.EMToLSDObjList[0].kinematic.world.horizontalAngle, angle, "%.2f", "horizontalAngle was set");
  COU_ASSERT_EQUAL_FMT(FData.hlafMatrixData.Object[0].leftAng, angle, "%.2f", "leftAng was set");
  COU_ASSERT_EQUAL_FMT(FData.hlafMatrixData.Object[0].rightAng, angle, "%.2f", "rightAng was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject, &FData.hlafMatrixData.EMToLSDObjList[0], "pointer to light object was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].EMObjID, EMObjectsList.aObject[0].General.uiID, "EMObjID was set");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantOnc, b_TRUE, "Oncoming was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.EMToLSDObjList[0].attributes.probabilityVehicleOncoming, 100, "Oncoming probability was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 1, "number of EM objects was increased");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRelObj, 1, "number of relevant objects was increased");


  /* --- test that correct flags are set for preceding --- */

  FData.hlafMatrixData.numEMObj = 0;
  FData.hlafMatrixData.numRelObj = 0;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING;

  /* call function */
  COU_CALL(HLAFMatrix_AddEMObjToIntObjList(&EMObjectsList.aObject[0], &FData.hlafMatrixData, angle, idx), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsRelevantPrec, b_TRUE, "Preceding was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.EMToLSDObjList[0].attributes.probabilityVehiclePreceding, 100, "Preceding probability was set");

}

/** \test
 *  \description
 *     Check that angles are correctly calculated and outermost angles are used. \n
 *     calls function HLAFMatrix_SplitEMObj() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct angles are used, when EM object is split. \n */
TEST_HLAFMatrix_SplitEMObj_001(HLAFMatrix_SplitEMObj_001, "Test that angles are correctly calculated and outermost angles are used")
{

  float32 LeftAngle = 0;
  float32 RightAngle = 0;

  /* no object is in list */
  FData.hlafMatrixData.numEMObj = 0;
  FData.hlafMatrixData.numRelObj = 0;

  /* set EM object data */
  EMObjectsList.aObject[0].Kinematic.fDistX = 10.0f;
  EMObjectsList.aObject[0].Kinematic.fDistY = 5.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[0].fPosX = 1.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[1].fPosX = 4.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[2].fPosX = -10.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[3].fPosX = 2.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[0].fPosY = 5.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[1].fPosY = 5.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[2].fPosY = 6.0f;
  EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[3].fPosY = 7.0f;

  /* calculate outermost angles */
  LeftAngle = GDBatan_66((EMObjectsList.aObject[0].Kinematic.fDistY + EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[3].fPosY) / (EMObjectsList.aObject[0].Kinematic.fDistX + EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[3].fPosX));
  RightAngle = GDBatan_66((EMObjectsList.aObject[0].Kinematic.fDistY + EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[1].fPosY) / (EMObjectsList.aObject[0].Kinematic.fDistX + EMObjectsList.aObject[0].Geometry.aShapePointCoordinates[1].fPosX));

  /* call function */
  COU_CALL(HLAFMatrix_SplitEMObj(&EMObjectsList.aObject[0], &FData.hlafMatrixData), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 2, "number of EM objects was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRelObj, 2, "number of relevant objects was set");
  COU_ASSERT_EQUAL_FMT(LeftAngle, FData.hlafMatrixData.EMToLSDObjList[0].kinematic.world.horizontalAngle, "%.2f", "angle was correctly calculated");
  COU_ASSERT_EQUAL_FMT(RightAngle, FData.hlafMatrixData.EMToLSDObjList[1].kinematic.world.horizontalAngle, "%.2f", "angle was correctly calculated");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].IntObjPairIdx, 1, "pair index was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].IntObjPairIdx, 0, "pair index was set");
}

/** \test
 *  \description
 *     Check that no exception is happening in case of EM null pointer input. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct angles are used, when EM object is split. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_001(HLAFMatrix_PrepareIntEMObjectList_001, "Test that no exception is happening in case of EM null pointer input")
{
  FData.hlafMatrixData.numRelObj = 2;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(NULL, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  //COU_ASSERT_EQUAL(FData.hlafMatrixData.numRelObjPrev, FData.hlafMatrixData.numRelObj, "objects were copied for next run");
}

/** \test
 *  \description
 *     Check that relevant EM object gets added to the internal object list. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     EM object was added to internal list. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_002(HLAFMatrix_PrepareIntEMObjectList_002, "Test that relevant EM object gets added to the internal object list")
{
  /* set inputs */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 0;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING;
  EMObjectsList.aObject[0].Kinematic.fDistX = 50.0f;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 100;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 2, "EM objects was added to the list");
}

/** \test
 *  \description
 *     Check that only relevant EM objects gets added to the internal object list. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     EM object was not added to internal list. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_003(HLAFMatrix_PrepareIntEMObjectList_003, "Test that only relevant EM objects gets added to the internal object list")
{
  /* set inputs */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 0;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
  EMObjectsList.aObject[0].Kinematic.fDistX = 50.0f;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 100;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 0, "EM objects was not added to the list");

  /* stationary objects are not relevant */
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 0, "EM objects was not added to the list");

  /* pedestrians are not relevant*/
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_PEDESTRIAN;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_CLASS_CAR;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 0, "EM objects was not added to the list");
}

/** \test
 *  \description
 *     Check that relevant EM object with a too low probability of existence gets added to the internal object list if it was in once above upper probability threshold. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     EM object was added to internal list. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_004(HLAFMatrix_PrepareIntEMObjectList_004, "Test that relevant EM object with a too low probability of existence gets added to the internal object list if it was in once above upper probability threshold")
{
  /* set inputs */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 0;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING;
  EMObjectsList.aObject[0].Kinematic.fDistX = 50.0f;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 60;
  EMObjectsList.aObject[0].General.uiID = 10;
  EMObjectsList.aObject[0].General.uiLifeCycles = 5;

  /* only one EM object was added in the previous run */
  FData.hlafMatrixData.numEMObjPrev= 2;
  FData.hlafMatrixData.numRelObjPrev= 2;

  FData.hlafMatrixData.ObjectPrev[0].EMObjID = 10;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 2, "EM objects was added to the list");
}

/** \test
 *  \description
 *     Check that relevant EM object with a too low probability of existence gets not added to the internal object list if probability is too low. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     EM object was not added to internal list. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_005(HLAFMatrix_PrepareIntEMObjectList_005, "Test that relevant EM object with a too low probability of existence gets not added to the internal object list if probability is too low")
{
  /* set inputs */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 0;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING;
  EMObjectsList.aObject[0].Kinematic.fDistX = 50.0f;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 10;
  EMObjectsList.aObject[0].General.uiID = 10;
  EMObjectsList.aObject[0].General.uiLifeCycles = 5;

  /* only one EM object was added in the previous run */
  FData.hlafMatrixData.numEMObjPrev= 2;
  FData.hlafMatrixData.numRelObjPrev= 2;

  FData.hlafMatrixData.ObjectPrev[0].EMObjID = 10;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 0, "EM objects was added to the list");
}

/** \test
 *  \description
 *     Check that relevant EM object with a too low probability of existence gets not added to the internal object list if it was newly created. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     EM object was not added to internal list. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_006(HLAFMatrix_PrepareIntEMObjectList_006, "Test that relevant EM object with a too low probability of existence gets not added to the internal object list if it was newly created")
{
  /* set inputs */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 0;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING;
  EMObjectsList.aObject[0].Kinematic.fDistX = 50.0f;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 60;
  EMObjectsList.aObject[0].General.uiID = 10;
  EMObjectsList.aObject[0].General.uiLifeCycles = 1;

  /* only one EM object was added in the previous run */
  FData.hlafMatrixData.numEMObjPrev= 2;
  FData.hlafMatrixData.numRelObjPrev= 2;

  FData.hlafMatrixData.ObjectPrev[0].EMObjID = 10;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 0, "EM objects was added to the list");
}

/** \test
 *  \description
 *     Check that object index can not exceed maximum number of EM objects. \n
 *     calls function HLAFMatrix_PrepareIntEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     EM object was added to internal list. \n */
TEST_HLAFMatrix_PrepareIntEMObjectList_007(HLAFMatrix_PrepareIntEMObjectList_007, "Test that object index can not exceed maximum number of EM objects")
{
  /* set inputs */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = -2;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING;
  EMObjectsList.aObject[0].Kinematic.fDistX = 50.0f;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 100;

  /* call function */
  COU_CALL(HLAFMatrix_PrepareIntEMObjectList(&EMObjectsList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  COU_ASSERT_EQUAL(FData.hlafMatrixData.numEMObj, 2, "EM objects was added to the list");
}

/** \test
 *  \description
 *     Check that that the HLAFMatrix_CheckRadarObjectList function only gets called if the input checks are valid . \n
 *     calls function HLAFMatrix_PrepareRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Function gets called if input checks are valid. \n */
test_HLAFMatrix_PrepareRadarObjectList_InputChecksArePerformed_FunctionGetsCalledIfChecksAreValid(HLAFMatrix_PrepareRadarObjectList_InputChecksArePerformed_FunctionGetsCalledIfChecksAreValid, "Check that that the HLAFMatrix_CheckRadarObjectList function only gets called if the input checks are valid")
{
  /* set NULL pointer */
  /* call function */
   COU_CALL(HLAFMatrix_PrepareRadarObjectList(NULL, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

   /* no exception is happening */

}
/** \test
 *  \description
 *     Test that relevant object in radar list is found. \n
 *     calls function HLAFMatrix_CheckRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Split function gets called. \n */
test_HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFound_SplitFunctionIsCalled(HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFound_SplitFunctionIsCalled, "Test that relevant object in radar list is found")
{
  /* one radar object is in list */
  RadarObjectList.NumOfUsedObjects = 1u;
  /* object is moving */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynamicProperty = HLA_RADAR_OBJECT_DYN_PROPERTY_MOVING;
  /* min confidence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynConfidence = HlafMatrixParameter.Input.RadarObjMinDynConfidence + 1u;
  /* probability of existence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ProbabilityOfExistence = HlafMatrixParameter.Input.RadarObjMinProbOfEx + 1u;
  /* class confidence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ClassConfidence = HlafMatrixParameter.Input.RadarObjMinClassConfidence + 1u;
  /* object is car */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.Classification = HLA_RADAR_OBJECT_CLASS_CAR;

  /* Set world coordinates*/
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = 7.0f;
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 25.0f;

  /* relevance counter is big enough */
  RadarObjectList.Object[0].HLA_RadarObjGenerals.ID = 10;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarID = 10;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = 200;
  FData.hlafMatrixData.numIntRadarPrev = 1;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 2, "object was added");

  /* object is truck */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.Classification = HLA_RADAR_OBJECT_CLASS_TRUCK;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 2, "object was added");

  /* change lateral position of object */
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = -7.0f;
  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 2, "object was added");

  /* Set object to radar-only region, i.e. closer to ego-vehicle */
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 18.0f;
  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 2, "object was added");


  /* object is too far away */
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 400.0f;
  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "no object was added");

  /* lateral offset is too big */
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = 500.0f;
  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "no object was added");
}
/** \test
 *  \description
 *     Test that relevant object in radar list is found, but not added to too low life cycle \n
 *     calls function HLAFMatrix_CheckRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Split function gets not called. \n */
test_HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFoundLifeCycleNotReached_SplitFunctionIsNotCalled(HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFoundLifeCycleNotReached_SplitFunctionIsNotCalled, "Test that relevant object in radar list is found, but not added to list due to life cycles too low")
{
  /* one radar object is in list */
  RadarObjectList.NumOfUsedObjects = 1u;
  /* object is moving */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynamicProperty = HLA_RADAR_OBJECT_DYN_PROPERTY_MOVING;
  /* min confidence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynConfidence = HlafMatrixParameter.Input.RadarObjMinDynConfidence +1u;
  /* probability of existence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ProbabilityOfExistence = HlafMatrixParameter.Input.RadarObjMinProbOfEx + 1u;
  /* class confidence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ClassConfidence = HlafMatrixParameter.Input.RadarObjMinClassConfidence + 1u;
  /* object is car */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.Classification = HLA_RADAR_OBJECT_CLASS_CAR;

  /* life cycles not high enough */
  RadarObjectList.Object[0].HLA_RadarObjGenerals.LifeCycles = 10u;

  /* Set world coordinates*/
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = 1.0f;
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 90.0f;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "object was not added");
}
/** \test
 *  \description
 *     Test that radar object is split if in radar fusion region. \n
 *     calls function HLAFMatrix_SplitRadarObj() \n
 *  \precondition
 *     None \n
 *  \result
 *     Split function gets called. \n */
test_HLAFMatrix_SplitRadarObj_ObjectIsInRadarFusionRegion_ObjectIsSplit(HLAFMatrix_SplitRadarObj_ObjectIsInRadarFusionRegion_ObjectIsSplit, "Test that radar object is split if in radar fusion region")
{
  float32 angleLeft,angleRight;
  float32 DistToBorder = (RadarObjectList.Object[0].HLA_RadarObjKinematics.Width * 1.33f) / 2.0f;

  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = 1.0f;
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 20.0f;
  RadarObjectList.Object[0].HLA_RadarObjAttributes.Classification = HLA_RADAR_OBJECT_CLASS_TRUCK;

  /* relevance counter is big enough */
  RadarObjectList.Object[0].HLA_RadarObjGenerals.ID = 10;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarID = 10;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = 200;
  FData.hlafMatrixData.numIntRadarPrev = 1;

  angleLeft = GDBatan_66((RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY + DistToBorder) / RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX);
  angleRight = GDBatan_66((RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY - DistToBorder) / RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX);

  /* call function */
  COU_CALL(HLAFMatrix_SplitRadarObj(&RadarObjectList.Object[0], &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject->kinematic.world.horizontalAngle, angleLeft, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].pLightObject->kinematic.world.horizontalAngle, angleRight, "right angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].leftAng, angleLeft, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].rightAng, angleLeft, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].leftAng, angleRight, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].rightAng, angleRight, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].LightSource, HLA_LIGHT_SOURCE_RADAR, "light source radar");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].LightSource, HLA_LIGHT_SOURCE_RADAR, "light source radar");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].bIsWideVehicle, b_TRUE, "wide vehicle is set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].bIsWideVehicle, b_TRUE, "wide vehicle is set");
}

/** \test
 *  \description
 *     Test that radar object is not split if it is not relevant. \n
 *     calls function HLAFMatrix_SplitRadarObj() \n
 *  \precondition
 *     None \n
 *  \result
 *     Split function gets not called. \n */
test_HLAFMatrix_SplitRadarObj_ObjectIsNotRelevant_ObjectIsNotSplit(HLAFMatrix_SplitRadarObj_ObjectIsNotRelevant_ObjectIsNotSplit, "Test that radar object is not split if it is not relevant")
{
  float32 angleLeft,angleRight;
  float32 DistToBorder = (RadarObjectList.Object[0].HLA_RadarObjKinematics.Width * 1.33f) / 2.0f;

  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = 1.0f;
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 20.0f;
  RadarObjectList.Object[0].HLA_RadarObjAttributes.Classification = HLA_RADAR_OBJECT_CLASS_TRUCK;

  /* relevance counter is not big enough */
  RadarObjectList.Object[0].HLA_RadarObjGenerals.ID = 10u;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarID = 10u;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = 1u;
  FData.hlafMatrixData.numIntRadarPrev = 1u;

  angleLeft = GDBatan_66((RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY + DistToBorder) / RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX);
  angleRight = GDBatan_66((RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY - DistToBorder) / RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX);

  /* call function */
  COU_CALL(HLAFMatrix_SplitRadarObj(&RadarObjectList.Object[0], &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].leftAng, 0.0f, "left angle was not set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].rightAng, 0.0f, "left angle was not set");
}

/** \test
 *  \description
 *     Test that radar object is split if in radar only region. \n
 *     calls function HLAFMatrix_SplitRadarObj() \n
 *  \precondition
 *     None \n
 *  \result
 *     Split function gets called. \n */
test_HLAFMatrix_SplitRadarObj_ObjectIsInRadarOnlyRegion_ObjectIsSplit(HLAFMatrix_SplitRadarObj_ObjectIsInRadarOnlyRegion_ObjectIsSplit, "Test that radar object is split if in radar fusion region")
{
  float32 angleLeft,angleRight;
  float32 DistToBorder = HlafMatrixParameter.Input.RadarObjAssumedWidth / 2;

  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = 1.0f;
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistX = 20.0f;

  /* calculate angles */
  angleLeft = HlafMatrixParameter.Input.RadarOnlyRegionOuterAngle;
  angleRight = HlafMatrixParameter.Input.RadarOnlyRegionInnerAngle;

  /* call function */
  COU_CALL(HLAFMatrix_SplitRadarObj(&RadarObjectList.Object[0], &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_ONLY_REGION, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject->kinematic.world.horizontalAngle, angleLeft, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].pLightObject->kinematic.world.horizontalAngle, angleRight, "right angle was set");

  /* object is on right side*/
  RadarObjectList.Object[0].HLA_RadarObjKinematics.DistY = -1.0f;

  angleLeft = -HlafMatrixParameter.Input.RadarOnlyRegionInnerAngle;
  angleRight = -HlafMatrixParameter.Input.RadarOnlyRegionOuterAngle;

  /* call function */
  COU_CALL(HLAFMatrix_SplitRadarObj(&RadarObjectList.Object[0], &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_ONLY_REGION, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[0].pLightObject->kinematic.world.horizontalAngle, angleLeft, "left angle was set");
  COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[1].pLightObject->kinematic.world.horizontalAngle, angleRight, "right angle was set");
}
/** \test
 *  \description
 *     Test that not relevant object in radar list is not found. \n
 *     calls function HLAFMatrix_CheckRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Split function gets not called. \n */
test_HLAFMatrix_CheckRadarObjectList_ObjectIsNotRelevant_SplitFunctionIsNotCalled(HLAFMatrix_CheckRadarObjectList_ObjectIsNotRelevant_SplitFunctionIsNotCalled, "Test that relevant object in radar list is found")
{
  /* one radar object is in list */
  RadarObjectList.NumOfUsedObjects = 1u;
  /* object is moving */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynamicProperty = HLA_RADAR_OBJECT_DYN_PROPERTY_MOVING;
  /* min confidence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynConfidence = HlafMatrixParameter.Input.RadarObjMinDynConfidence + 1u;
  /* probability of existence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ProbabilityOfExistence = HlafMatrixParameter.Input.RadarObjMinProbOfEx + 1u;
  /* class confidence is reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ClassConfidence = HlafMatrixParameter.Input.RadarObjMinClassConfidence + 1u;
  /* object is pedestrian */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.Classification = HLA_RADAR_OBJECT_CLASS_PEDESTRIAN;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "object was not added");

  /* class confidence is not reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ClassConfidence = HlafMatrixParameter.Input.RadarObjMinClassConfidence - 1u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "object was not added");

  /* probability of existence is not reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.ProbabilityOfExistence = HlafMatrixParameter.Input.RadarObjMinProbOfEx - 1u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "object was not added");

  /* min confidence is not reached */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynConfidence = HlafMatrixParameter.Input.RadarObjMinDynConfidence - 1u;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "object was not added");

  /* object is oncoming */
  RadarObjectList.Object[0].HLA_RadarObjAttributes.DynamicProperty = HLA_RADAR_OBJECT_DYN_PROPERTY_ONCOMING;

  /* call function */
  COU_CALL(HLAFMatrix_CheckRadarObjectList(&RadarObjectList, &LsdLightObjectList, &HlafMatrixParameter.Input, &FData.hlafMatrixData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(FData.hlafMatrixData.numRadarObj, 0, "object was not added");
}

/** \test
 *  \description
 *     Test that angles are not updated if object is not preceding. \n
 *     calls function HLAFMatrix_CheckRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Angles are not updated. \n */
test_HLAFMatrix_MergeRadarObj_ObjectIsNotPreceding_AnglesAreNotUpdated(HLAFMatrix_MergeRadarObj_ObjectIsNotPreceding_AnglesAreNotUpdated, "Test that angles are not updated if object is not preceding")
{
  float32 AngleLeft, AngleRight, InitAngleLeft, InitAngleRight;
  uint8 FusedIDLeft, FusedIDRight;

  InitAngleLeft = 0.01f;
  InitAngleRight = -0.02f;

  /* Input angles */
  AngleLeft =InitAngleLeft;
  AngleRight = InitAngleRight;

  /* two relevant object is in the internal object list */
  FData.hlafMatrixData.numRelObj = 2;

  /* object is paired */
  FData.hlafMatrixData.Object[0].IntObjPairIdx = 1;

  /* Object is not a preceding */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = b_TRUE;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_FALSE;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* set output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, InitAngleLeft, "%6f", "Left Angle was not updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, InitAngleRight, "%6f", "Right Angle was not updated");

  /* object is not paired */
  FData.hlafMatrixData.Object[0].IntObjPairIdx = UI8_T_MAX;

  /* Object is a preceding */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = b_FALSE;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* set output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, InitAngleLeft, "%6f", "Left Angle was not updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, InitAngleRight, "%6f", "Right Angle was not updated");
}

/** \test
 *  \description
 *     Test that angles are not updated if object is not within radar object. \n
 *     calls function HLAFMatrix_CheckRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Angles are not updated. \n */
test_HLAFMatrix_MergeRadarObj_InternalObjectNotWithinRadarObject_AnglesAreNotUpdated(HLAFMatrix_MergeRadarObj_InternalObjectNotWithinRadarObject_AnglesAreNotUpdated, "Test that angles are not updated if object is not within radar object")
{
  float32 AngleLeft, AngleRight, InitAngleLeft, InitAngleRight;
  uint8 FusedIDLeft, FusedIDRight;

  LSD_LightObject_t LightObjectLeft, LightObjectRight;

  InitAngleLeft = 0.08f;
  InitAngleRight = -0.09f;

  /* Input angles */
  AngleLeft =InitAngleLeft;
  AngleRight = InitAngleRight;

  /* set faulty input that will be caught in function -> too many relevant objects are in the internal object list */
  FData.hlafMatrixData.numRelObj = HLA_INTERNAL_OBJECT_LIST_LENGTH+1;

  /* object is paired */
  FData.hlafMatrixData.Object[0].IntObjPairIdx = 1;

  /* Object is a preceding */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = b_FALSE;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObjectLeft;
  FData.hlafMatrixData.Object[1].pLightObject = &LightObjectRight;

  /* left angle is within */
  LightObjectLeft.kinematic.world.horizontalAngle = 0.0f;

  /* right angle is outside of borders */
  LightObjectRight.kinematic.world.horizontalAngle = -0.1f;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* set output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, InitAngleLeft, "%6f", "Left Angle was not updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, InitAngleRight, "%6f", "Right Angle was not updated");

  /* left angle is outside of borders */
  LightObjectLeft.kinematic.world.horizontalAngle = -0.1f;

  /* right angle is inside of borders */
  LightObjectRight.kinematic.world.horizontalAngle = 0.00f;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* set output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, InitAngleLeft, "%6f", "Left Angle was not updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, InitAngleRight, "%6f", "Right Angle was not updated");

  /* left angle is inside of borders */
  LightObjectLeft.kinematic.world.horizontalAngle = 0.01f;

  /* right angle is inside of borders */
  LightObjectRight.kinematic.world.horizontalAngle = -0.01f;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* check output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, InitAngleLeft, "%6f", "Left Angle was not updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, InitAngleRight, "%6f", "Right Angle was not updated");
}

/** \test
 *  \description
 *     Test that angles are not updated if object is not within radar object. \n
 *     calls function HLAFMatrix_CheckRadarObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Angles are not updated. \n */
test_HLAFMatrix_MergeRadarObj_InternalObjectWithinRadarObject_AnglesAreUpdated(HLAFMatrix_MergeRadarObj_InternalObjectWithinRadarObject_AnglesAreUpdated, "Test that angles are not updated if object is not within radar object")
{
  float32 AngleLeft, AngleRight, InitAngleLeft, InitAngleRight;
  uint8 FusedIDLeft, FusedIDRight;

  LSD_LightObject_t LightObjectLeft, LightObjectRight;

  InitAngleLeft = 0.08f;
  InitAngleRight = -0.09f;

  /* Input angles */
  AngleLeft =InitAngleLeft;
  AngleRight = InitAngleRight;

  /* two relevant object is in the internal object list */
  FData.hlafMatrixData.numRelObj = 2;

  /* object is paired */
  FData.hlafMatrixData.Object[0].IntObjPairIdx = 1;

  /* Object is a preceding */
  FData.hlafMatrixData.Object[0].bIsRelevantOnc = b_FALSE;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObjectLeft;
  FData.hlafMatrixData.Object[1].pLightObject = &LightObjectRight;

  /* left angle is within */
  LightObjectLeft.kinematic.world.horizontalAngle = 0.08f;

  /* right angle is outside of borders */
  LightObjectRight.kinematic.world.horizontalAngle = -0.08f;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* check output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, LightObjectLeft.kinematic.world.horizontalAngle, "%6f", "Left Angle was updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, LightObjectRight.kinematic.world.horizontalAngle, "%6f", "Right Angle was updated");

  /* -- change the angles -- */
  /* left angle is within */
  LightObjectLeft.kinematic.world.horizontalAngle = -0.08f;

  /* right angle is outside of borders */
  LightObjectRight.kinematic.world.horizontalAngle = 0.08f;

  /* call function */
  COU_CALL(HLAFMatrix_MergeRadarObj(&FData.hlafMatrixData, &HlafMatrixParameter.Input, &AngleLeft, &AngleRight, &FusedIDLeft, &FusedIDRight), "function call");

  /* check output */
  COU_ASSERT_EQUAL_FMT(AngleLeft, LightObjectRight.kinematic.world.horizontalAngle, "%6f", "Left Angle was updated");
  COU_ASSERT_EQUAL_FMT(AngleRight, LightObjectLeft.kinematic.world.horizontalAngle, "%6f", "Right Angle was updated");
}

/** \test
 *  \description
 *     Test that counter is decreased if no light objects are within camera angles. \n
 *     calls function HLAFMatrix_CheckRadarObjRelevance() \n
 *  \precondition
 *     None \n
 *  \result
 *     Counter is decreased. \n */
test_HLAFMatrix_CheckRadarObjRelevance_NoLightsInRadarAngles_CounterIsDecreased(HLAFMatrix_CheckRadarObjRelevance_NoLightsInRadarAngles_CounterIsDecreased, "Test that counter is decreased if no light objects are within camera angles")
{
  float32 AngleLeft, AngleRight;
  uint8 relevanceCounter = 0;

  /* radar object was detected in previous frame */
  FData.hlafMatrixData.numIntRadarPrev = 2u;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarID = 10u;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = 50u;
  RadarObjectList.Object[0].HLA_RadarObjGenerals.ID = 10u;

  /* no lights are detected */
  LsdLightObjectList.numObjects = 0u;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, (FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter - HlafMatrixParameter.Input.RadarObjRelCountSmallStep), "counter was reduced");

  /* --- counter stays on zero */

  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = 0u;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, 0u, "counter stays on zero");

  /* --- there is one light but not within the radar angles --- */

  /* no lights are detected */
  LsdLightObjectList.numObjects = 1u;

  AngleRight= 1.0f;
  AngleLeft = 2.0f;

  LsdLightObjectList.lightObjects[0].kinematic.world.horizontalAngle = AngleRight + AngleLeft;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, 0u, "counter stays on zero");

  /* --- invalid input numObjects of lsd light list is too high --- */

  /* no lights are detected */
  LsdLightObjectList.numObjects = LSD_LIGHT_OBJECT_LIST_LENGTH+ 1u;

  AngleRight= 1.0f;
  AngleLeft = 2.0f;

  LsdLightObjectList.lightObjects[0].kinematic.world.horizontalAngle = AngleRight + AngleLeft;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, 0u, "counter stays on zero");
}

/** \test
 *  \description
 *     Test that counter is increased if light objects are within camera angles. \n
 *     calls function HLAFMatrix_CheckRadarObjRelevance() \n
 *  \precondition
 *     None \n
 *  \result
 *     Counter is decreased. \n */
test_HLAFMatrix_CheckRadarObjRelevance_LightsInRadarAngles_CounterIsIncreased(HLAFMatrix_CheckRadarObjRelevance_LightsInRadarAngles_CounterIsIncreased, "Test that counter is increased if light objects are within camera angles")
{
  float32 AngleLeft, AngleRight;
  uint8 relevanceCounter = 0;

  /* radar object was detected in previous frame */
  FData.hlafMatrixData.numIntRadarPrev = 1;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarID = 10;
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = 50;
  RadarObjectList.Object[0].HLA_RadarObjGenerals.ID = 10;

  AngleRight= 1.0f;
  AngleLeft = 2.0f;

  /* one light is detected */
  LsdLightObjectList.numObjects = 2;

  /* light is between borders of radar object */
  LsdLightObjectList.lightObjects[0].kinematic.world.horizontalAngle = (AngleRight + AngleLeft)/2;
  LsdLightObjectList.lightObjects[1].kinematic.world.horizontalAngle = (AngleRight + AngleLeft)/2;

  /* preceding object */
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 100u;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, (FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter + HlafMatrixParameter.Input.RadarObjRelCountSmallStep + HlafMatrixParameter.Input.RadarObjRelCountBigStep), "counter was increased");


  /* --- radar object is in radar only region --- */

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_ONLY_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, (FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter + HlafMatrixParameter.Input.RadarObjRelCountBigStep), "counter was increased");

  /* --- counter is limited to max value --- */

  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = UI8_T_MAX;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_ONLY_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, UI8_T_MAX, "counter stays on max value");

  /* --- counter is limited to max value --- */
  FData.hlafMatrixData.RadarObjectsDataPrev[0].RadarCounter = UI8_T_MAX;

  /* call function */
  COU_CALL(relevanceCounter = HLAFMatrix_CheckRadarObjRelevance(&RadarObjectList.Object[0], &FData.hlafMatrixData, &LsdLightObjectList, &HlafMatrixParameter.Input, HLA_RADAR_FUSION_REGION, &AngleLeft, &AngleRight), "function call");

  COU_ASSERT_EQUAL(relevanceCounter, UI8_T_MAX, "counter stays on max value");
}

/** list of all test methods of the related suite. */
cou_test_t hla_MatrixObjects[] = {
   COU_ADD_TEST(HLAFMatrix_PrepareObjectList_001),
   COU_ADD_TEST(HLAFMatrix_PrepareObjectList_002),
   COU_ADD_TEST(HLAFMatrix_PrepareObjects_EMObjectsActivatedInCfg_FunctionGetsCalled),
   COU_ADD_TEST(HLAFMatrix_SAEConformLight_001),
   COU_ADD_TEST(HLAFMatrix_SAEConformLight_002),
   COU_ADD_TEST(HLAFMatrix_SAEConformLight_003),
   COU_ADD_TEST(HLAFMatrix_SAEConformLight_004),
   COU_ADD_TEST(HLAFMatrix_SAEConformLight_005),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OncomingProbabilityHigh_RelevantOncomingSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_PrecedingProbabilityHigh_RelevantPrecedingSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OncPrecProbabilityLow_NoFlagSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncStillAboveThreshold_OncomingFlagSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsOncBelowThreshold_OncomingFlagNotSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedProbTooLow_OncomingFlagNotSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecStillAboveThreshold_PrecedingFlagSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_OnceDetectedAsPrecNoLongerThreshold_PrecedingFlagNotSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedTraceTimeTooShort_PrecedingFlagNotSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_PrecDetectedIDsDoNotMatch_PrecedingFlagNotSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_TruckLightStatusBit_RelevantOncomingSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_ObjectIsPaired_RelevantFlagSet),
   COU_ADD_TEST(HLAFMatrix_CheckIfLightIsRelevant_StickyInRange_RelevantOncomingSet),
   COU_ADD_TEST(HLAFMatrix_AddRelevantObjectToList_001),
   COU_ADD_TEST(HLAFMatrix_AddRelevantObjectToList_002),
   COU_ADD_TEST(HLAFMatrix_AddRelevantObjectToList_003),
   COU_ADD_TEST(HLAFMatrix_SetPairIndex_001),
   COU_ADD_TEST(HLAFMatrix_SetPairIndex_002),
   COU_ADD_TEST(HLAFMatrix_AddEMObjToIntObjList_001),
   COU_ADD_TEST(HLAFMatrix_SplitEMObj_001),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_001),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_002),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_003),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_004),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_005),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_006),
   COU_ADD_TEST(HLAFMatrix_PrepareIntEMObjectList_007),
   COU_ADD_TEST(HLAFMatrix_PrepareRadarObjectList_InputChecksArePerformed_FunctionGetsCalledIfChecksAreValid),
   COU_ADD_TEST(HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFound_SplitFunctionIsCalled),
   COU_ADD_TEST(HLAFMatrix_CheckRadarObjectList_ObjectIsNotRelevant_SplitFunctionIsNotCalled),
   COU_ADD_TEST(HLAFMatrix_CheckRadarObjectList_RelevantRadarObjectIsFoundLifeCycleNotReached_SplitFunctionIsNotCalled),
   COU_ADD_TEST(HLAFMatrix_SplitRadarObj_ObjectIsInRadarFusionRegion_ObjectIsSplit),
   COU_ADD_TEST(HLAFMatrix_SplitRadarObj_ObjectIsInRadarOnlyRegion_ObjectIsSplit),
   COU_ADD_TEST(HLAFMatrix_SplitRadarObj_ObjectIsNotRelevant_ObjectIsNotSplit),
   COU_ADD_TEST(HLAFMatrix_MergeRadarObj_ObjectIsNotPreceding_AnglesAreNotUpdated),
   COU_ADD_TEST(HLAFMatrix_MergeRadarObj_InternalObjectNotWithinRadarObject_AnglesAreNotUpdated),
   COU_ADD_TEST(HLAFMatrix_MergeRadarObj_InternalObjectWithinRadarObject_AnglesAreUpdated),
   COU_ADD_TEST(HLAFMatrix_CheckRadarObjRelevance_NoLightsInRadarAngles_CounterIsDecreased),
   COU_ADD_TEST(HLAFMatrix_CheckRadarObjRelevance_LightsInRadarAngles_CounterIsIncreased),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(HlafMatrixObjectsInit, "Initialize Hlaf Matrix Objects")
{
  InitData();
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE_WITH_INIT(TestSuite_MatrixObjects, hla_MatrixObjects, HlafMatrixObjectsInit, HlafMatrixObjectsInit, "Module test for hlaf_matrix_objects.c"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */

