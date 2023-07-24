/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>

#include <hlaf_decision_blockage.h>
#include <hla_errorhandling.h>

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_DecisionBlockage_TransitionNoBlockage COU_TEST
#define TEST_DecisionBlockage_TransitionsClearMeas COU_TEST
#define TEST_DecisionBlockage_TransitionsCondensation COU_TEST
#define TEST_DecisionBlockage_TransitionsBlockage COU_TEST
#define TEST_DecisionBlockage_InvalidState COU_TEST

void InitBlockageInputs(void);

CB_t_ProvidedOutputs_t           Sig_Blockage;
RTE_HLAF_ParameterTurnOnDelay_t  RTETurnOnDelayPar;
t_DecisionParametersBlockage     Params;
HLAFCameraData_t                 CamData;
HLAFBlockage_t                   Data;

void InitBlockageInputs(void)
{
  memset(&Sig_Blockage, 0, sizeof(Sig_Blockage));
  memset(&RTETurnOnDelayPar, 0, sizeof(RTETurnOnDelayPar));
  memset(&Params, 0, sizeof(Params));
  memset(&CamData, 0, sizeof(CamData));
  memset(&Data, 0, sizeof(Data));
}

/** \test
 *  \description
 *     Test the transition from no blockage to blockage or condensation. Data.eBlockageState is the current state,
 *     while in Sig_Blockage.ui8_BlockageStatus the new state is set as an input \n
 *     calls function HLAFDecisionBlockage_Main() \n
 *  \precondition
 *     All input structs are set to zero \n
 *  \result
 *     When blockage or condensation is reported by the CB algo, the internal state shall switch according to the new input.
 *     Otherwise the old state (no blockage) shall be kept \n */
TEST_DecisionBlockage_TransitionNoBlockage(DecisionBlockage_TransitionNoBlockage, "Test transition from no blockage")
{
  /* No Blockage was detected */
  Data.eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  /* New blockage state is blockage*/
  Sig_Blockage.ui8_BlockageStatus = GB_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  /* Internal state should switch to blockage */
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_BLOCKAGE, "State switches to blockage");
  
  /* No Blockage was detected */
  Data.eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  /* New blockage state is blockage*/
  Sig_Blockage.ui8_BlockageStatus = GB_CONDENSATION;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  /* Internal state should switch to condensation */
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CONDENSATION, "State switches to condenstaion");
  
  /* No Blockage was detected */
  Data.eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  /* New blockage state is blockage*/
  Sig_Blockage.ui8_BlockageStatus = GB_BOTTOM_PART_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  /* Internal state should stay in no blockage */
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_NO_BLOCKAGE, "State stays in no blockage");
  
}

/** \test
 *  \description
 *     Test the transition from condensation to blockage or no blockage. Data.eBlockageState is the current state,
 *     while in Sig_Blockage.ui8_BlockageStatus the new state is set as an input \n
 *     calls function HLAFDecisionBlockage_Main \n
 *  \precondition
 *     All input structs are set to zero \n
 *  \result
 *     When blockage or no blockage is reported by the CB algo, the internal state shall switch according to the new input.
 *     Otherwise the old state (condensation) shall be kept \n */
TEST_DecisionBlockage_TransitionsCondensation(DecisionBlockage_TransitionsCondensation, "Test transition from condensation")
{
  /* No Blockage was detected */
  Data.eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
  /* New blockage state is blockage*/
  Sig_Blockage.ui8_BlockageStatus = GB_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  /* Internal state should switch to blockage */
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_BLOCKAGE, "State switches to blockage");
  
  /* No Blockage was detected */
  Data.eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
  /* New blockage state is blockage*/
  Sig_Blockage.ui8_BlockageStatus = GB_NO_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  /* Internal state should switch to no blockage */
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_NO_BLOCKAGE, "State switches to no blockage");
  
  /* No Blockage was detected */
  Data.eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
  /* New blockage state is blockage*/
  Sig_Blockage.ui8_BlockageStatus = GB_BOTTOM_PART_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  /* Internal state should stay in condensation */
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CONDENSATION, "State stays in condensation");
  
}

/** \test
 *  \description
 *     Test the transition from clearance measurement to condensation, blockage or no blockage. Data.eBlockageState is the current state,
 *     while in Sig_Blockage.ui8_BlockageStatus the new state is set as an input \n
 *     There are multiple test performed in this function:\n
 *     - No Blockage was detected and driven distance is above threshold -> switch to no blockage \n
 *     - No Blockage was detected and driven distance is below threshold -> stay in clearance measurement and check if internal counters were updated \n
 *     - Blockage was detected -> switch to blockage \n
 *     - Condensation was detected and driven distance is above threshold -> switch to condensation \n
 *     - Condensation was detected and driven distance is below threshold -> stay in clearance measurement \n
 *     - Clearance measurement is finished and no valid input (traveled dist and time above threshold) -> stay in clearance measurement and check if error was set \n
 *     - Clearance measurement is finished and no valid input (traveled dist is above, while elapsed time is below threshold) -> stay in clearance measurement
 *     calls function HLAFDecisionBlockage_Main() \n
 *  \precondition
 *     All input structs are set to zero. \n
 *  \result
 *     Test results are described above. \n */
TEST_DecisionBlockage_TransitionsClearMeas(DecisionBlockage_TransitionsClearMeas, "Test transitions from clearance measurement")
{
  /* --- Test - No Blockage was detected and driven distance is above threshold --- */
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* No nlockage was detected */
  Sig_Blockage.ui8_BlockageStatus = GB_NO_BLOCKAGE;
  /* Set threshold */
  Params.ClearMeas2NoBlockage_DistThres = 10;
  /* dist traveled is above threshold */
  Data.DistTraveled = Params.ClearMeas2NoBlockage_DistThres+1;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_NO_BLOCKAGE, "State switches to no blockage");
  
  
  /* --- Test - No Blockage was detected and driven distance is below threshold --- */
  InitBlockageInputs();
  float32 driven_distance_time = 5.0f;
  
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* No blockage was detected */
  Sig_Blockage.ui8_BlockageStatus = GB_NO_BLOCKAGE;
  /* Set threshold */
  Params.ClearMeas2NoBlockage_DistThres = 10;
  /* dist traveled is not above threshold */
  Data.DistTraveled = Params.ClearMeas2NoBlockage_DistThres-1;
  
  /* set driven distance and time */
  CamData.dtimeFwd_s = driven_distance_time;
  CamData.ddistFwd_m = driven_distance_time;
  
  float32 old_distance = Data.DistTraveled;
  float32 old_time = Data.TimeElapsed;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CLEAR_MEAS, "Stay in clearance measurement");
  COU_ASSERT_EQUAL(Data.TimeElapsed, old_time+driven_distance_time, "time was updated");
  COU_ASSERT_EQUAL(Data.DistTraveled, old_distance+driven_distance_time, "distance was updated");
  
  
  /* --- Test - Blockage was detected --- */
  InitBlockageInputs();
  
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* Blockage was detected */
  Sig_Blockage.ui8_BlockageStatus = GB_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_BLOCKAGE, "Switch to blockage");
  
  
  /* --- Test - Condensation was detected and driven distance is above threshold --- */
  InitBlockageInputs();
  
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* Blockage was detected */
  Sig_Blockage.ui8_BlockageStatus = GB_CONDENSATION;
  /* set threshold */
  Params.ClearMeas2NoBlockage_DistThres = 10;
  /* traveled dist above threshold */
  Data.DistTraveled = Params.ClearMeas2NoBlockage_DistThres+1;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CONDENSATION, "Switch to condensation");
  
  
  /* --- Test - Condensation was detected and driven distance is below threshold --- */
  InitBlockageInputs();
  
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* Blockage was detected */
  Sig_Blockage.ui8_BlockageStatus = GB_CONDENSATION;
  /* set threshold */
  Params.ClearMeas2NoBlockage_DistThres = 10;
  /* traveled dist below threshold */
  Data.DistTraveled = Params.ClearMeas2NoBlockage_DistThres-1;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CLEAR_MEAS, "stay in clearance measurement");
  
  
  /* --- Test - Clearance measurement is finished and no valid input (traveled dist and time above threshold) --- */
  InitBlockageInputs();
  boolean errorSet = b_FALSE;
  
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* set threshold */
  Params.ClearMeas2Blockage_DistThres = 10;
  Params.ClearMeas2Blockage_TimeThres = 10;
  /* traveled dist above threshold -> error case */
  Data.DistTraveled = Params.ClearMeas2Blockage_DistThres+1;
  Data.TimeElapsed = Params.ClearMeas2Blockage_TimeThres+1;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CLEAR_MEAS, "stay in clearance measurement");
  COU_CALL(errorSet = HLA_ErrorHandling_GetError(HLA_ERROR_BLOCKAGE_NO_VALID_INPUT), "get error");
  COU_ASSERT_EQUAL(errorSet, b_TRUE, "error was set");
  
    /* --- Test - Clearance measurement is finished and no valid input (traveled dist is above, while elapsed time is below threshold) --- */
  InitBlockageInputs();
  errorSet = b_FALSE;
  
  /* Clearance measurement phase */
  Data.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* set threshold */
  Params.ClearMeas2Blockage_DistThres = 10;
  Params.ClearMeas2Blockage_TimeThres = 10;
  /* traveled dist above threshold -> error case */
  Data.DistTraveled = Params.ClearMeas2Blockage_DistThres-1;
  Data.TimeElapsed = Params.ClearMeas2Blockage_TimeThres+1;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CLEAR_MEAS, "stay in clearance measurement");
}

/** \test
 *  \description
 *     Test the transition from blockage to condensation or no blockage. Data.eBlockageState is the current state,
 *     while in Sig_Blockage.ui8_BlockageStatus the new state is set as an input \n
 *     There are multiple test performed in this function:\n
 *     - Switch from blockage to no blockage, threshold passed -> switch to no blockage \n
 *     - Switch from blockage to no blockage, threshold not passed -> stay in blockage and check if blockage time increased \n
 *     - Switch from blockage to condensation, threshold passed -> switch to condensation, blockage time shall be reset \n
 *     - Switch from blockage to condensation, threshold not passed -> stay in blockage, check if blockage time increased \n
 *     - Stay in blockage state -> don't leave blockage state
 *     calls function HLAFDecisionBlockage_Main() \n
 *  \precondition
 *     All input structs are set to zero. \n
 *  \result
 *     Test results are described above. \n */
TEST_DecisionBlockage_TransitionsBlockage(DecisionBlockage_TransitionsBlockage, "Test transitions from blockage")
{
  
  float32 driven_distance_time = 5.0f;
  float32 oldBlockageTime = 0.0f;
  
  /* --- Test - Switch from blockage to no blockage, threshold passed --- */
  /* Blockage state */
  Data.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* No blockage was not detected */
  Sig_Blockage.ui8_BlockageStatus = GB_NO_BLOCKAGE;
  RTETurnOnDelayPar.Blockage = 10.0f;
  Data.BlockageTime = RTETurnOnDelayPar.Blockage + 1.0f;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_NO_BLOCKAGE, "switch to no blockage");
  
  
  /* --- Test - Switch from blockage to no blockage, threshold not passed --- */
  InitBlockageInputs();
  
  /* Blockage state */
  Data.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* No blockage was not detected */
  Sig_Blockage.ui8_BlockageStatus = GB_NO_BLOCKAGE;
  RTETurnOnDelayPar.Blockage = 10.0f;
  Data.BlockageTime = RTETurnOnDelayPar.Blockage - 1.0f;
  CamData.dtimeFwd_s = driven_distance_time;
  
  /* save blockage time */
  oldBlockageTime = Data.BlockageTime;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_BLOCKAGE, "stay in blockage");
  COU_ASSERT_EQUAL(Data.BlockageTime, oldBlockageTime+driven_distance_time, "blockage time increased");
  
  
  /* --- Test - Switch from blockage to condensation, threshold passed --- */
  InitBlockageInputs();
  /* Blockage state */
  Data.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* Condensation was not detected */
  Sig_Blockage.ui8_BlockageStatus = GB_CONDENSATION;
  RTETurnOnDelayPar.Blockage = 10.0f;
  Data.BlockageTime = RTETurnOnDelayPar.Blockage + 1.0f;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_CONDENSATION, "switch to condensation");
  COU_ASSERT_EQUAL(Data.BlockageTime, 0.0f, "blockage time is reset");
  
  /* --- Test - Switch from blockage to condensation, threshold not passed --- */
  InitBlockageInputs();
  /* Blockage state */
  Data.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* Condensation was not detected */
  Sig_Blockage.ui8_BlockageStatus = GB_CONDENSATION;
  RTETurnOnDelayPar.Blockage = 10.0f;
  Data.BlockageTime = RTETurnOnDelayPar.Blockage - 1.0f;
  CamData.dtimeFwd_s = driven_distance_time;
  
  /* save blockage time */
  oldBlockageTime = Data.BlockageTime;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_BLOCKAGE, "stay in blockage");
  COU_ASSERT_EQUAL(Data.BlockageTime, oldBlockageTime+driven_distance_time, "blockage time increased");
  
  /* --- Test - Stay in blockage state --- */
  /* Blockage state */
  Data.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* Blockage was not detected */
  Sig_Blockage.ui8_BlockageStatus = GB_BLOCKAGE;
  
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_BLOCKAGE, "stay in blockage");
}

/** \test
 *  \description
 *     Test the transition in case of an invalid input state. 
 *     calls function HLAFDecisionBlockage_Main() \n
 *  \precondition
 *     All input structs are set to zero. \n
 *  \result
 *     Previous state shall be kept. \n */
TEST_DecisionBlockage_InvalidState(DecisionBlockage_InvalidState, "Test invalid states")
{
  /* blockage state is set to last*/
  Data.eBlockageState = HLAF_BLOCKAGE_LAST;
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, HLAF_BLOCKAGE_LAST, "keep state");
  
  /* blockage state is set to a random invalid value */
  Data.eBlockageState = 123;
  COU_CALL(HLAFDecisionBlockage_Main(&Sig_Blockage, &RTETurnOnDelayPar, &Params, &CamData, &Data), "call of function");
  COU_ASSERT_EQUAL(Data.eBlockageState, 123, "keep state");
}

/** list of all test methods of the related suite. */
cou_test_t hla_DecisionBlockage[] = {
   COU_ADD_TEST(DecisionBlockage_TransitionNoBlockage),
   COU_ADD_TEST(DecisionBlockage_TransitionsClearMeas),
   COU_ADD_TEST(DecisionBlockage_TransitionsCondensation),
   COU_ADD_TEST(DecisionBlockage_TransitionsBlockage),
   COU_ADD_TEST(DecisionBlockage_InvalidState),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(DecisionBlockageInit, "Initialize Decision Blockage Unit")
{
  COU_LOG("Set Inputs to zero");
  InitBlockageInputs();
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_DecisionBlockage, hla_DecisionBlockage, DecisionBlockageInit, "module test for decision blockage"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
