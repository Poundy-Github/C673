/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* inclue for error handling */
#include <hla_errorhandling.h>

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_SetError COU_TEST
#define TEST_SetErrorTwice COU_TEST
#define TEST_SetWarning COU_TEST
#define TEST_SetInformation COU_TEST
#define TEST_GetNumberErrors COU_TEST
#define TEST_GetNumberWarnings COU_TEST
#define TEST_GetNumberInformations COU_TEST
#define TEST_TestSetGetSoftErrorStack COU_TEST
#define TEST_TestSetGetServicesReturnValue COU_TEST
#define TEST_TestSetGetBusSigStateFlag COU_TEST
#define TEST_TestGetErrorStack COU_TEST
#define TEST_TestAddMeasfreezeAmount COU_TEST

//extern t_ErrorHandling_ErrorStack errorStack;

/** \test
 *  \description
 *     Test that the correct error is set. Every error in the error list is set, then it is checked that only this error was set. \n
 *     calls function HLA_ErrorHandling_SetError(), HLA_ErrorHandling_GetError() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called \n
 *  \result
 *     Only the error that was set, should be returned by the get function. No other error shall be set. \n */
TEST_SetError(ErrorSetTest, "Test that the correct error is set")
{
  boolean errorSet;
  boolean errorWasSet = b_FALSE;
  boolean correctErrorSet = b_FALSE;
  uint8 i, j;
  
  uint8 first_error = HLA_ERROR_PRO_PORT_NULL_POINTER_LIST;
  uint8 last_error  = HLA_ERROR_LAST_ENUM_ENTRY;
  
  /* first loop, set one error */
  for(j = first_error; j < last_error; j++)
  {
    /* Init error handling */
    HLA_ErrorHandling_Init();
    errorWasSet = b_FALSE;
    correctErrorSet = b_FALSE;
  
    /* Set one error */
    HLA_ErrorHandling_SetError(j);
  
    /* loop over alle error and check if no other error was set */
    for(i = first_error; i<last_error; i++)
    {
      /* get error */
      errorSet = HLA_ErrorHandling_GetError(i);
        
      /* ignore the error, which was set */
      if(i != j)
      {
        
        /* Set flag in case error was set */
        if(errorSet == b_TRUE)
        {
          errorWasSet = b_TRUE;
        }
      }
      else
      {
        /* correct error was set */
        if(errorSet == b_TRUE)
        {
          correctErrorSet = b_TRUE;
        }
        
      }
    }
  /* Check if correct error was set and no other error */
  COU_ASSERT_EQUAL(errorWasSet, b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(correctErrorSet, b_TRUE, "Correct Error was set");
  }

}

/** \test
 *  \description
 *     The same error is set twice. The error shall still be set. \n
 *     calls function HLA_ErrorHandling_SetError(), HLA_ErrorHandling_GetError() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called \n
 *  \result
 *     The error that was set twice shall still be set. \n */
TEST_SetErrorTwice(ErrorSetTwiceTest, "Test setting the error twice")
{
  boolean errorSet = b_FALSE;
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_PRO_PORT_NULL_POINTER_LIST), "Set error");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_PRO_PORT_NULL_POINTER_LIST), "Set same error again");
  COU_CALL(errorSet = HLA_ErrorHandling_GetError(HLA_ERROR_PRO_PORT_NULL_POINTER_LIST), "Get error");
  COU_ASSERT_EQUAL(errorSet, b_TRUE, "Error is still set");
}

/** \test
 *  \description
 *     Test that the correct warning is set. Every warning in the warning list is set, then it is checked that only this warning was set. \n
 *     calls function HLA_ErrorHandling_SetWarning(), HLA_ErrorHandling_GetWarning() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called \n
 *  \result
 *     Only the warning that was set, should be returned by the get function. No other warning shall be set. \n */
TEST_SetWarning(WarningSetTest, "Test that the correct warning is set")
{
  boolean warningSet;
  boolean warningWasSet = b_FALSE;
  boolean correctWarningSet = b_FALSE;
  uint8 i, j;
  
  uint8 first_error = HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF;
  uint8 last_error  = HLA_WARNING_LAST_ENUM_ENTRY;
  
  /* first loop, set one warning */
  for(j = first_error; j < last_error; j++)
  {
    /* Init warning handling */
    HLA_ErrorHandling_Init();
    warningWasSet = b_FALSE;
    correctWarningSet = b_FALSE;
  
    /* Set one warning */
    HLA_ErrorHandling_SetWarning(j);
  
  /* loop over alle warning and check if no other warning was set */
  for(i = first_error; i<last_error; i++)
  {
    /* get warning */
    warningSet = HLA_ErrorHandling_GetWarning(i);
      
    /* ignore the warning, which was set */
    if(i != j)
    {
      
      /* Set flag in case warning was set */
      if(warningSet == b_TRUE)
      {
        warningWasSet = b_TRUE;
      }
    }
    else
    {
      /* correct warning was set */
      if(warningSet == b_TRUE)
      {
        correctWarningSet = b_TRUE;
      }
      
    }
  }
  /* Check if correct warning was set and no other warning */
  COU_ASSERT_EQUAL(warningWasSet, b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(correctWarningSet, b_TRUE, "Correct Warning was set");
  }

}

/** \test
 *  \description
 *     Test that the correct information is set. Every information in the information list is set, then it is checked that only this information was set. \n
 *     calls function HLA_ErrorHandling_SetInformation(), HLA_ErrorHandling_GetInformation() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called \n
 *  \result
 *     Only the information that was set, should be returned by the get function. No other information shall be set. \n */
TEST_SetInformation(InformationSetTest, "Test that the correct information is set")
{
  boolean informationSet;
  boolean informationWasSet = b_FALSE;
  boolean correctInformationSet = b_FALSE;
  uint8 i, j;
  
  uint8 first_error = HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST;
  uint8 last_error  = HLA_INFORMATION_LAST_ENUM_ENTRY;
  
  /* first loop, set one information */
  for(j = first_error; j < last_error; j++)
  {
    /* Init information handling */
    HLA_ErrorHandling_Init();
    informationWasSet = b_FALSE;
    correctInformationSet = b_FALSE;
  
    /* Set one information */
    HLA_ErrorHandling_SetInformation(j);
  
  /* loop over alle information and check if no other information was set */
  for(i = first_error; i<last_error; i++)
  {
    /* get information */
    informationSet = HLA_ErrorHandling_GetInformation(i);
      
    /* ignore the information, which was set */
    if(i != j)
    {
      
      /* Set flag in case information was set */
      if(informationSet == b_TRUE)
      {
        informationWasSet = b_TRUE;
      }
    }
    else
    {
      /* correct information was set */
      if(informationSet == b_TRUE)
      {
        correctInformationSet = b_TRUE;
      }
      
    }
  }
  /* Check if correct information was set and no other information */
  COU_ASSERT_EQUAL(informationWasSet, b_FALSE, "Information was not set");
  COU_ASSERT_EQUAL(correctInformationSet, b_TRUE, "Correct information was set");
  }

}

/** \test
 *  \description
 *     Test that the correct number of errors is returned. In a for loop the number of errors set gets increased by one. Then it is checked that the correct numbers of errors is set. \n
 *     calls function HLA_ErrorHandling_SetError(), HLA_ErrorHandling_GetNumErrors() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called \n
 *  \result
 *     Correct number of errors is set. \n */
TEST_GetNumberErrors(CorrectNumberOfErrorsSetTest, "test that correct number of errors is returned")
{
  uint8 numberOfErrors = 0;
  uint8 j;
  uint8 first_error = HLA_ERROR_PRO_PORT_NULL_POINTER_LIST;
  uint8 last_error  = HLA_ERROR_LAST_ENUM_ENTRY;
  
  for(j = first_error; j < last_error; j++)
  {
    /* Set one error */
    HLA_ErrorHandling_SetError(j);
    numberOfErrors = HLA_ErrorHandling_GetNumErrors();
    COU_ASSERT_EQUAL(numberOfErrors, j+1, "Number of set errors is correct");
  }
}

/** \test
 *  \description
 *     Test that the correct number of warnings is returned. In a for loop the number of warnings set gets increased by one. Then it is checked that the correct numbers of warnings is set. \n
 *     calls function HLA_ErrorHandling_SetError(), HLA_ErrorHandling_GetNumErrors() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called \n
 *  \result
 *     Correct number of warnings is set. \n */
TEST_GetNumberWarnings(CorrectNumberOfWarningsSetTest, "test that correct numbers of warnings is returned")
{
  uint8 numberOfWarnings = 0;
  uint8 j;
  uint8 first_error = HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF;
  uint8 last_error  = HLA_WARNING_LAST_ENUM_ENTRY;
  
  for(j = first_error; j < last_error; j++)
  {
    /* Set one error */
    HLA_ErrorHandling_SetWarning(j);
    numberOfWarnings = HLA_ErrorHandling_GetNumWarnings();
    COU_ASSERT_EQUAL(numberOfWarnings, j+1, "Number of set warnings is correct");
  }
}

/** \test
 *  \description
 *     Test that the correct number of informations is returned. In a for loop the number of informations set gets increased by one. Then it is checked that the correct numbers of informations is set. \n
 *     calls function HLA_ErrorHandling_SetError(), HLA_ErrorHandling_GetNumErrors() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called. \n
 *  \result
 *     Correct number of informations is set. \n */
TEST_GetNumberInformations(CorrectNumberOfInformationsSetTest, "test that correct numbers of informations is returned")
{
  uint8 numberOfInformations = 0;
  uint8 j;
  uint8 first_error = HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST;
  uint8 last_error  = HLA_INFORMATION_LAST_ENUM_ENTRY;
  
  for(j = first_error; j < last_error; j++)
  {
    /* Set one error */
    HLA_ErrorHandling_SetInformation(j);
    numberOfInformations = HLA_ErrorHandling_GetNumInformation();
    COU_ASSERT_EQUAL(numberOfInformations, j+1, "Number of set informations is correct");
  }
}

/** \test
 *  \description
 *     Test set and get functions for soft error state. The number is given to the HLA_ErrorHandling_SetSoftErrorState(), which should be returned by the HLA_ErrorHandling_GetSoftErrorState() function. \n
 *     calls function HLA_ErrorHandling_SetSoftErrorState(), HLA_ErrorHandling_GetSoftErrorState() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called. \n
 *  \result
 *     The set number is returned by the get function. \n */
TEST_TestSetGetSoftErrorStack(TestSetGetSoftErrorStack, "test set and get functions for soft error state")
{
  AlgoCycleCounter_t measCntIn = 12345;
  AlgoCycleCounter_t measCntOut = 0;
  COU_CALL(HLA_ErrorHandling_SetSoftErrorState(measCntIn), "Set Soft Error State");
  COU_CALL(measCntOut = HLA_ErrorHandling_GetSoftErrorState(), "Get Soft Error State");
  COU_ASSERT_EQUAL(measCntIn, measCntOut, "Soft error state correctly set");
}

/** \test
 *  \description
 *     Test set and get functions for service return state. The number is given to the HLA_ErrorHandling_SetServicesReturnValue(), which should be returned by the HLA_ErrorHandling_GetServicesReturnValue() function. \n
 *     calls function HLA_ErrorHandling_SetServicesReturnValue(), HLA_ErrorHandling_GetServicesReturnValue\n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called. \n
 *  \result
 *     The set number is returned by the get function. \n */
TEST_TestSetGetServicesReturnValue(TestSetGetServicesReturnValue, "test set and get functions for service return value")
{
  uint32 servicesReturnValueIn = 12345;
  uint32 servicesReturnValueOut = 0;
  COU_CALL(HLA_ErrorHandling_SetServicesReturnValue(servicesReturnValueIn), "Set service return value");
  COU_CALL(servicesReturnValueOut = HLA_ErrorHandling_GetServicesReturnValue(), "Get service return value");
  COU_ASSERT_EQUAL(servicesReturnValueIn, servicesReturnValueOut, "Service return value correctly set");
}


/** \test
 *  \description
 *     Test set and get functions for bus sig state flag. The flag and offset is given to the HLA_ErrorHandling_SetBusSigState(),
 *     which should be returned by the HLA_ErrorHandling_GetBusSigStateFlag() and HLA_ErrorHandling_GetBusSigStateOffset() function. \n
 *     calls function HLA_ErrorHandling_SetBusSigState(), HLA_ErrorHandling_GetBusSigStateFlag(), HLA_ErrorHandling_GetBusSigStateOffset()\n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called. \n
 *  \result
 *     The set flag and offset is returned by the get functions. \n */
TEST_TestSetGetBusSigStateFlag(TestSetGetBusSigStateFlag, "test set and get bus sig state flag")
{
  uint8  stateFlagIn = 123;
  uint16 structOffsetIn = 4567;
  uint8  stateFlagOut = 0;
  ptrdiff_t structOffsetOut = 0;
  
  COU_CALL(HLA_ErrorHandling_SetBusSigState(stateFlagIn, structOffsetIn), "Set bus sig state flag");
  COU_CALL(stateFlagOut = HLA_ErrorHandling_GetBusSigStateFlag(), "Get bus sig state flag");
  COU_CALL(structOffsetOut = HLA_ErrorHandling_GetBusSigStateOffset(), "Get bus sig state offset");
  COU_ASSERT_EQUAL(stateFlagIn, stateFlagOut, "Bus sig state flag correctly set");
  COU_ASSERT_EQUAL(structOffsetIn, structOffsetOut, "Bus sig state offset correctly set");
}

/** \test
 *  \description
 *     Test the get function for the error stack. \n
 *     calls function HLA_ErrorHandling_GetErrorStack() \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called. \n
 *  \result
 *     Pointer to error stack should be set. \n */
TEST_TestGetErrorStack(TestGetErrorStack, "test of get error stack")
{
  const t_ErrorHandling_ErrorStack* pErrorhandling = NULL;
  COU_CALL(pErrorhandling = HLA_ErrorHandling_GetErrorStack(), "Call of GetErrorStack function");
  COU_ASSERT(pErrorhandling != NULL, "Pointer was set");
}

/** \test
 *  \description
 *     Test set and get functions for meas freeze amout. The number is given to the HLA_ErrorHandling_AddMeasfreezeAmount(), which should be stored in the error stack. \n
 *     calls function HLA_ErrorHandling_AddMeasfreezeAmount(), HLA_ErrorHandling_GetErrorStack \n
 *  \precondition
 *     HLA_ErrorHandling_Init() should have been called. \n
 *  \result
 *     The set number is stored in the error stack. \n */
TEST_TestAddMeasfreezeAmount(TestAddMeasfreezeAmount, "test of get meas freeze amount")
{
  const t_ErrorHandling_ErrorStack* pErrorhandling = NULL;
  uint32 numBytes = 1234;
  COU_CALL(HLA_ErrorHandling_AddMeasfreezeAmount(numBytes), "Call of AddMeasfreezeAmount");
  COU_CALL(pErrorhandling = HLA_ErrorHandling_GetErrorStack(), "Call of GetErrorStack function");
  COU_ASSERT_EQUAL(pErrorhandling->measfreezeAmount, numBytes, "Correct number was set");
}

/** list of all test methods of the related suite. */
cou_test_t hla_ErrorHandling[] = {
   COU_ADD_TEST(ErrorSetTest),
   COU_ADD_TEST(ErrorSetTwiceTest),
   COU_ADD_TEST(WarningSetTest),
   COU_ADD_TEST(InformationSetTest),
   COU_ADD_TEST(CorrectNumberOfErrorsSetTest),
   COU_ADD_TEST(CorrectNumberOfWarningsSetTest),
   COU_ADD_TEST(CorrectNumberOfInformationsSetTest),
   COU_ADD_TEST(TestSetGetSoftErrorStack),
   COU_ADD_TEST(TestSetGetServicesReturnValue),
   COU_ADD_TEST(TestSetGetBusSigStateFlag),
   COU_ADD_TEST(TestGetErrorStack),
   COU_ADD_TEST(TestAddMeasfreezeAmount),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(ErrorHandlingInit, "Initialize Error Handling")
{
  COU_CALL(HLA_ErrorHandling_Init(),"Initialize Error Handling");
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_ErrorHandling, hla_ErrorHandling, ErrorHandlingInit, "module test for error handling"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
