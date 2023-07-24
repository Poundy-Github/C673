/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* inclue for utils */
#include <hla_utils.h>
#include <hla_rta_type.h>

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_AddDetailedRtaEvent_001 COU_TEST
#define TEST_AddDetailedRtaEvent_002 COU_TEST
#define TEST_IsNAN_001 COU_TEST
#define TEST_IsFinite_001 COU_TEST

static boolean serviceFunctionCalled = b_FALSE;

/* dummy function for the service add event */
sint32 dummyFunction(const AS_t_RtaEventType RtaEvtType, const uint8 u_IdGlobal, const uint8 u_IdLocal, const uint8 u_OptData)
{
  /* change variable to verfy that service function was called */
  serviceFunctionCalled = b_TRUE;
  /* output some random value */
  return 1234;
}

/** \test
 *  \description
 *     Test that no exception is happening, when pointer to service function is NULL. \n
 *     calls function HLAUtilsRegisterRtaService(), HLAUtilsAddDetailedRtaEvent() \n
 *  \precondition
 *     None \n
 *  \result
 *     No excpetion is happening. \n */
TEST_AddDetailedRtaEvent_001(AddDetailedRtaEvent_001, "Test add details rta event")
{
  /* set inputs */
  AS_t_RtaEventType RtaEvtType = e_RTA_EVT_AlgoStart;
  uint8             IdGlobal = RTA_GLOBALID_HLA;
  uint8             IdLocal = HLA_RTA_HLAF_INIT;
  uint8             OptData = 0u;
  
  COU_CALL(HLAUtilsRegisterRtaService(NULL), "Set pointer to service function to zero");
  COU_CALL(HLAUtilsAddDetailedRtaEvent(RtaEvtType, IdGlobal, IdLocal, OptData), "call of HLAUtilsAddDetailedRtaEvent()");
  COU_LOG("No exception should be happening");
}

/** \test
 *  \description
 *     Test that the service function is called in case of RTA event. \n
 *     calls function HLAUtilsRegisterRtaService(), HLAUtilsAddDetailedRtaEvent() \n
 *  \precondition
 *     None \n
 *  \result
 *     Service function was called. \n */
TEST_AddDetailedRtaEvent_002(AddDetailedRtaEvent_002, "Test add details rta event")
{
  /* set inputs */
  AS_t_RtaEventType           RtaEvtType = e_RTA_EVT_AlgoStart;
  uint8                       IdGlobal = RTA_GLOBALID_HLA;
  uint8                       IdLocal = HLA_RTA_HLAF_INIT;
  uint8                       OptData = 0u;
  AS_t_RTAAlgoServiceAddEvent fRTAAlgoServiceAddEvent = dummyFunction;
  
  /* set variable to false, to check if service function gets called */
  serviceFunctionCalled = b_FALSE;
  
  COU_CALL(HLAUtilsRegisterRtaService(fRTAAlgoServiceAddEvent), "set pointer of service function to valid address");
  COU_CALL(HLAUtilsAddDetailedRtaEvent(RtaEvtType, IdGlobal, IdLocal, OptData), "call of HLAUtilsAddDetailedRtaEvent()");
  COU_ASSERT_EQUAL(serviceFunctionCalled, b_TRUE, "Service function was called");

}


/** \test
 *  \description
 *     Test HLAUtilsIsNAN()
 *  \precondition
 *     None \n
 *  \result
 *     Whether incoming number is an NAN float
 */
TEST_IsNAN_001(IsNAN_001, "Test HLAUtilsIsNAN()")
{
  /* set inputs */
  const float32 number = 7.5f;
  boolean retVal;

  COU_CALL(retVal = HLAUtilsIsNAN(number), "call of function under test");

  /* Check results */
  COU_ASSERT_EQUAL(retVal, b_FALSE, "As number is not an NAN number return value should be b_FALSE");
}


/** \test
 *  \description
 *     Test HLAUtilsIsFinite()
 *  \precondition
 *     None \n
 *  \result
 *     Whether incoming number is finite
 */
TEST_IsFinite_001(IsFinite_001, "Test HLAUtilsIsFinite()")
{
  /* set inputs */
  const float32 number = 7.5f;
  boolean retVal;

  COU_CALL(retVal = HLAUtilsIsFinite(number), "call of function under test");

  /* Check results */
  COU_ASSERT_EQUAL(retVal, b_TRUE, "As number is finite return value should be b_TRUE");
}

/** list of all test methods of the related suite. */
cou_test_t hla_utils[] = {
   COU_ADD_TEST(AddDetailedRtaEvent_001),
   COU_ADD_TEST(AddDetailedRtaEvent_002),
   COU_ADD_TEST(IsNAN_001),
   COU_ADD_TEST(IsFinite_001),

   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(UtilsInit, "Initialize utils")
{
  /* Nothing to do here */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Utils, hla_utils, UtilsInit, "module test for utils"),
   COU_ADD_SUITE_END,
}; /* suites */

#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
