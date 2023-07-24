/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* inclue for wrpoutputs */
#include <hla_outputs.h>
#include <hlaf_ext.h>
#include <hla_ver.h>
#include <hla_project_defs.h>

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_SetOutputDefaults COU_TEST
#define TEST_SetOutputDemo COU_TEST

/** \test
 *  \description
 *     Test that outputs are set to default values. \n
 *     calls function HLA_SetOutputDefaults() \n
 *  \precondition
 *     None. \n
 *  \result
 *     CompState, Headlight control and sync ref structs are filled with default values. \n */
TEST_SetOutputDefaults(SetOutputDefaults, "Test set outputs to default")
{
  CompState_t         compState = COMP_STATE_RUNNING;
  CompErrorCode_t     errorCode = 1111;
  GenAlgoQualifiers_t algoQualifier = 2222;
  AlgoSignalState_t   sigState = AL_SIG_STATE_OK;
  AlgoDataTimeStamp_t timeStamp = 90123;
  AlgoCycleCounter_t  measurementCounter = 5678;
  AlgoCycleCounter_t  cycleCounter = 1234;
  Hla_SyncRef_t       HlaSyncRef;
  proHlaPrtList_t     ProPorts;
  
  AlgoCompState_t             AlgoCompState;        
  RTE_HLAF_HeadlightControl_t Hlaf_HeadlightControl;
  
  ProPorts.pAlgoCompState = &AlgoCompState;
  ProPorts.pHlaf_HeadlightControl = &Hlaf_HeadlightControl;
  
  AlgoComponentVersionNumber_t algoVersionNumber = HLA_SW_VERSION_NUMBER;
  static const uint8 versionInfo[ALGO_VERSION_INFO_LENGTH] = HLA_SW_VERSION_INFO;
  int i = 0;
  
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  
  /* Checks for component state */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->uiVersionNumber, COMP_STATE_INTFVER, "Check version number");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus, AL_SIG_STATE_OK, "Check sig status");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.uiCycleCounter, cycleCounter, "Check cycle counter");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.uiMeasurementCounter, measurementCounter, "Check measurementCounter");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.uiTimeStamp, timeStamp, "Check timestamp");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->uiAlgoVersionNumber, algoVersionNumber, "Check uiAlgoVersionNumber");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->uiApplicationNumber, HLA_PROJECT, "Check uiApplicationNumber");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode, errorCode, "Check eErrorCode");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_NONE, "Check eShedulerSubModeRequest");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier, algoQualifier, "Check eGenAlgoQualifier");
  
  /* check algo version info array */
  for(i = 0; i<ALGO_VERSION_INFO_LENGTH; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->AlgoVersionInfo[i], versionInfo[i], "Check AlgoVersionInfo");
  }
  
  /* Checks for Headlight Control Data */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->uiVersionNumber, RTE_HLAF_HEADLIGHTCONTROL_INTFVER, "Check uiVersionNumber");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus, sigState, "Check eSigStatus");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.uiCycleCounter, cycleCounter, "Check uiCycleCounter");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.uiMeasurementCounter, measurementCounter, "Check uiMeasurementCounter");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.uiTimeStamp, timeStamp, "Check uiTimeStamp");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_RUNNING, "Check hlaFunctionStatus");
  
  /* Checks for sync ref */
  COU_ASSERT_EQUAL(HlaSyncRef.sSigHeader.eSigStatus, sigState, "Check sigstate");
  COU_ASSERT_EQUAL(HlaSyncRef.sSigHeader.uiCycleCounter, cycleCounter, "Check uiCycleCounter");
  COU_ASSERT_EQUAL(HlaSyncRef.sSigHeader.uiMeasurementCounter, measurementCounter, "Check uiMeasurementCounter");
  COU_ASSERT_EQUAL(HlaSyncRef.sSigHeader.uiTimeStamp, timeStamp, "Check uiTimeStamp");
  
  
  /* Test mapping of comp states  */
  
  /* COMP_STATE_NOT_INITIALIZED -> RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF */
  COU_SET(compState, COMP_STATE_NOT_INITIALIZED, "Set comp state to COMP_STATE_NOT_INITIALIZED");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF, "Check hlaFunctionStatus");
  
  /* COMP_STATE_TEMPORARY_ERROR -> RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF */
  COU_SET(compState, COMP_STATE_TEMPORARY_ERROR, "Set comp state to COMP_STATE_TEMPORARY_ERROR");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF, "Check hlaFunctionStatus");
  
  /* COMP_STATE_PERMANENT_ERROR -> RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF */
  COU_SET(compState, COMP_STATE_PERMANENT_ERROR, "Set comp state to COMP_STATE_PERMANENT_ERROR");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF, "Check hlaFunctionStatus");
  
  /* COMP_STATE_SUCCESS -> RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF */
  COU_SET(compState, COMP_STATE_SUCCESS, "Set comp state to COMP_STATE_SUCCESS");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF, "Check hlaFunctionStatus");
  
  /* COMP_STATE_REDUCED_AVAILABILITY -> RTE_HLAF_FUNCTION_STATUS_RUNNING */
  COU_SET(compState, COMP_STATE_REDUCED_AVAILABILITY, "Set comp state to COMP_STATE_REDUCED_AVAILABILITY");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_RUNNING, "Check hlaFunctionStatus");
  
  /* COMP_STATE_NOT_RUNNING -> RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF */
  COU_SET(compState, COMP_STATE_NOT_RUNNING, "Set comp state to COMP_STATE_NOT_RUNNING");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF, "Check hlaFunctionStatus");
  
  /* Invalid value -> RTE_HLAF_FUNCTION_STATUS_INVALID */
  COU_SET(compState, 123, "Set comp state to invalid value");
  COU_CALL(HLA_SetOutputDefaults(compState, errorCode, algoQualifier, sigState, timeStamp, measurementCounter, cycleCounter, &HlaSyncRef, &ProPorts), "Call HLA_SetOutputDefaults()");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_INVALID, "Check hlaFunctionStatus");
  
}

/** \test
 *  \description
 *     Test that outputs which are set in the Demo mode. Matrix and dimming data are set to fixed values defined in the detailed design. \n
 *     calls function HLA_SetOutputDemo() \n
 *  \precondition
 *     None. \n
 *  \result
 *     Specific Headlight control is set to defined values from detailed design. \n */
TEST_SetOutputDemo(SetOutputDemo, "Test set output demo")
{
  /* Inputs */
  proHlaPrtList_t ProPorts;
  RTE_HLAF_HeadlightControl_t Hlaf_HeadlightControl;
  
  /* Link pointer to buffer */
  ProPorts.pHlaf_HeadlightControl = &Hlaf_HeadlightControl;
  
  uint8 i = 0;
  
  COU_CALL(HLA_SetOutputDemo(&ProPorts), "Call HLA_SetOutputDemo()");
  /* check matrix data */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_DATA_VALID, "Check GFAStatus");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_PARTIAL, "Check HighBeamState");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang, C_HALFPI, "Check LowBeam_Ang");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist, 42.0f, "Check LowBeam_Dist");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "Check LowBeam_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA, 1u, "Check nGFA");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason, 1u, "Check TurnOffReason");
  
  /* check gfa data */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang, C_HALFPI, "Check BndryLeft_Ang");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang_Cam, CML_f_Pi / 4.0f, "Check BndryLeft_Ang_Cam");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Dist, 42.0f, "Check BndryLeft_Dist");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "Check BndryLeft_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_ObjId, 0u, "Check BndryLeft_ObjId");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_DistState, RTE_HLAF_DISTSTATE_PAIRLIGHT, "Check BndryLeft_DistState");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Ang_Cam, 1.3f, "Check BndryLower_Ang_Cam");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "Check BndryLower_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_ObjId, 1u, "Check BndryLower_ObjId");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_DistState, RTE_HLAF_DISTSTATE_SINGLELIGHT, "Check BndryLower_DistState");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang, -(C_HALFPI), "Check BndryRight_Ang");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang_Cam, -(CML_f_Pi / 4.0f), "Check BndryRight_Ang_Cam");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Dist, 42.0f, "Check BndryRight_Dist");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "Check BndryRight_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_ObjId, 2u, "Check BndryRight_ObjId");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_DistState, RTE_HLAF_DISTSTATE_PAIRLIGHT, "Check BndryRight_DistState");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Ang, 1.5f, "Check ClosestObj_Ang");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Dist, 42.0f, "Check ClosestObj_Dist");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "Check ClosestObj_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_ObjId, 3u, "Check ClosestObj_ObjId");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_DistState, RTE_HLAF_DISTSTATE_PAIRLIGHT, "Check ClosestObj_DistState");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ExistenceProb, 21, "Check ExistenceProb");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Ang, 1.25f, "Check MinLight_Ang");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Dist, 42.0f, "Check MinLight_Dist");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "Check MinLight_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left, 1.0f, "Check ttb18Left");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left_Status, RTE_HLAF_TTBSTA_DIR_LEFT, "Check ttb18Left_Status");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right, 1.0f, "Check ttb18Right");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right_Status, RTE_HLAF_TTBSTA_DIR_RIGHT, "Check ttb18Right_Status");
  
  /* check dimming data */
  for(i = 0; i<RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Check DimmingAreas");
  }
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Check DimmingStatus");
  
}

/** list of all test methods of the related suite. */
cou_test_t hla_Outputs[] = {
   COU_ADD_TEST(SetOutputDefaults),
   COU_ADD_TEST(SetOutputDemo),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(OutputsInit, "Initialize Outputs")
{
  /* Nothing to do here */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Outputs, hla_Outputs, OutputsInit, "Module test for hla_outputs.c"),
   COU_ADD_SUITE_END,
}; /* suites */

#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
