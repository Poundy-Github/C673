/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>

#include "hla_defs.h"
#include "hla_ext.h"
#include "hla_main.h"
#include "hla_errorhandling.h"

#include "../../mockup_services.h"


// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_FirstStartUp              COU_TEST
#define TEST_Exec_000                  COU_TEST
#define TEST_Exec_001                  COU_TEST
#define TEST_Exec_002                  COU_TEST
#define TEST_Exec_003                  COU_TEST
#define TEST_Exec_004                  COU_TEST
#define TEST_Exec_005                  COU_TEST
#define TEST_Exec_006                  COU_TEST
#define TEST_OpMode_Run_000            COU_TEST
#define TEST_OpMode_Run_001            COU_TEST
#define TEST_OpMode_Run_002            COU_TEST
#define TEST_OpMode_Run_003            COU_TEST
#define TEST_OpMode_Run_004            COU_TEST
#define TEST_OpMode_Run_005            COU_TEST
#define TEST_DemEvents_000             COU_TEST
#define TEST_DemEvents_001             COU_TEST
#define TEST_DemEvents_002             COU_TEST
#define TEST_DemEvents_003             COU_TEST

// Define external global variables of mock-ups
extern unsigned int HLAF_v_Init__numOfCalls;
extern unsigned int HLAF_v_Exec__numOfCalls;
extern unsigned int HLA_OutputChecks__numOfCalls;

// Generic defines
#define TEST_ERROR_CHECK_SET_ERROR                        1
#define TEST_ERROR_CHECK_SET_SOFT_ERROR                   2
#define TEST_ERROR_CHECK_SET_INFORMATION_EM_OBJECT_LIST   3

// Define global variables
static uint32 i;

// Define external global variables of file under test
extern boolean bGlobVarsInitialized;
extern Hla_SyncRef_t HLA_SyncRef;
extern Hla_SyncRef_t HLA_SyncRef_PrevCycle;
extern AlgoCycleCounter_t HLA_CycleCounter;

// Define external global variables of mock-ups

// Declaration of static functions
extern void HLA_OpModeRun( const reqHlaPrtList_t*    pReqPorts,
                           const AS_t_ServiceFuncts* Services,
                                 proHlaPrtList_t*    pProPorts
                           );
extern void HLA_MapErrors2DemEvents( const reqHlaPrtList_t*    pReqPorts,
                                     const AS_t_ServiceFuncts* Services
                                    );

// Local functions
static void InitInputs(void)
{
  /* Init generic stuff */
  Mockup_InitGlobVars();
  HLA_ErrorHandling_Init();

  /* Clear memory */
  memset(&bGlobVarsInitialized,  TEST_MOCKUP_INIT_BYTE, sizeof(bGlobVarsInitialized));
  memset(&HLA_SyncRef,           TEST_MOCKUP_INIT_BYTE, sizeof(HLA_SyncRef));
  memset(&HLA_SyncRef_PrevCycle, TEST_MOCKUP_INIT_BYTE, sizeof(HLA_SyncRef_PrevCycle));
  memset(&HLA_CycleCounter,      TEST_MOCKUP_INIT_BYTE, sizeof(HLA_CycleCounter));

  /* Initialize called function counters */
  HLAF_v_Init__numOfCalls      = 0;
  HLAF_v_Exec__numOfCalls      = 0;
  HLA_OutputChecks__numOfCalls = 0;
}

// Local mockups
boolean HLA_InputChecks_MinimumInputs( const reqHlaPrtList_t*    pReqPorts,
                                       const proHlaPrtList_t*    pProPorts,
                                       const AS_t_ServiceFuncts* pServices
                                      )
{
  boolean retVal = b_TRUE;

  /* Use Services pointer as switch */
  if(pServices == NULL)
  {
    retVal = b_FALSE;
  }

  return retVal;
}

void HLA_InputChecks( const BaseOpMode_t     eOpMode,
                      const reqHlaPrtList_t* pReqPorts,
                      const Hla_SyncRef_t*   pHlaSyncRefPrevCycle
                     )
{
  /* Switch off soft error state in any case */
  COU_CALL(HLA_ErrorHandling_SetSoftErrorState(0), "Simulate switch off of soft error state.");

  /* Use eSource of calibration port as switch */
  switch(pReqPorts->pMonoCalibration->eSource)
  {
  case TEST_ERROR_CHECK_SET_ERROR:
    COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE), "Simulate failed input check by setting corresponding error in error stack");
    break;
  case TEST_ERROR_CHECK_SET_SOFT_ERROR:
    COU_CALL(HLA_ErrorHandling_SetSoftErrorState(1234), "Simulate soft error state.");
    break;
  case TEST_ERROR_CHECK_SET_INFORMATION_EM_OBJECT_LIST:
    COU_CALL(HLA_ErrorHandling_SetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST), "Simulate missing optional input check by setting corresponding information message in error stack");
    break;
  default:
    break;
  }
}

// TEST CASES
/** \test
 *  \description
 *     Test whether initialization flag was reset. \n
 *  \precondition
 *     bGlobVarsInitialized is TRUE. \n
 *  \result
 *     Initialization flag shall be set to false. \n
 */
TEST_FirstStartUp(FirstStartUp, "Call of HLA_FirstStatupState")
{
  /* Initialize inputs */
  InitInputs();
  bGlobVarsInitialized = b_TRUE;

  /* Call function under test */
  COU_CALL(HLA_FirstStatupState(), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(bGlobVarsInitialized, b_FALSE, "Global variable should be false");
}

// TEST CASES
/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were not yet initialized
 *     - Minimum inputs were not available
 *  \precondition
 *     Set Services to NULL in order to return FALSE from minimum input checks mockup. \n
 *  \result
 *     - NULL pointers for provide ports
 *     - Initialized global variables
 *     - Returns an error
 */
TEST_Exec_000(Exec_000, "Call of HlaExec #000")
{
  /* Define test data */
  const uint8 cycleCounter = 7u;
  BaseReturnCode_t retVal;

  /* Initialize inputs */
  InitInputs();
  COU_SET(bGlobVarsInitialized, b_FALSE, "Set global variables to not initialized.");
  COU_SET(HLA_CycleCounter, cycleCounter, "Set cycle counter.");
  (void)memset((void*)&HLA_SyncRef, 0x44, sizeof(HLA_SyncRef));
  (void)memset((void*)&HLA_SyncRef_PrevCycle, 0x55, sizeof(HLA_SyncRef_PrevCycle));

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, NULL), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(retVal, BASE_RETURN_ERROR, "HlaExec should return an error.");
  COU_ASSERT_EQUAL(bGlobVarsInitialized, b_TRUE, "Global variables should be initialized.");
  COU_ASSERT_EQUAL(HLA_SyncRef.uiVersionNumber, 0, "Whole SyncRef should be zero now.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.uiVersionNumber, 0, "Whole SyncRef should be zero now.");
  COU_ASSERT_EQUAL(HLA_CycleCounter, cycleCounter + 1, "Cycle counter should be incremented by one.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState, NULL, "Provide port should be reset.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl, NULL, "Provide port should be reset.");
}

/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were initialized
 *     - SyncRef shall not be filled since all input pointers will be NULL
 *     - Opmode set to an unknown value
 *  \precondition
 *     Valid input pointers for base ctrl data and Services. \n
 *  \result
 *     - all outputs to zero
 *     - signal state to invalid
 *     - comp state permanent error
 *     - SyncRef shall be empty besides base ctrl data
 *     - SyncRef_PrevCycle shall contain previous SyncRef data
 *     - Returns no error
 */
TEST_Exec_001(Exec_001, "Call of HlaExec #001")
{
  /* Define test data */
  BaseReturnCode_t retVal;
  SignalHeader_t dummySignalHeader;
  const BaseOpMode_t opMode = BASE_OM_INVALID;

  /* Initialize inputs */
  InitInputs();
  memset(&ReqPorts, 0, sizeof(ReqPorts));
  ReqPorts.pBaseCtrlData = &BaseCtrlData;

  dummySignalHeader.eSigStatus           = 1u;
  dummySignalHeader.uiCycleCounter       = 2u;
  dummySignalHeader.uiMeasurementCounter = 3u;
  dummySignalHeader.uiTimeStamp          = 4u;

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set invalid opmode.");
  COU_SET(HLA_SyncRef.pLsdLightObjectList, dummySignalHeader, "Set dummy signal header for light object list signal header.");

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(retVal,                                                         BASE_RETURN_OK,                         "HlaExec should not return an error.");
  COU_ASSERT_EQUAL(HLA_SyncRef.uiVersionNumber,                                    3u,                                     "SyncRef should contain correct interface version.");
  COU_ASSERT_EQUAL(HLA_SyncRef.sBaseCtrl.eOpMode,                                  opMode,                                 "SyncRef should contain base ctrl data now.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.eSigStatus,           dummySignalHeader.eSigStatus,           "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiCycleCounter,       dummySignalHeader.uiCycleCounter,       "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiMeasurementCounter, dummySignalHeader.uiMeasurementCounter, "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiTimeStamp,          dummySignalHeader.uiTimeStamp,          "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_PERMANENT_ERROR,             "Component state should be: permanent error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_UNKNOWN,                     "Error code should be: Unknown.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_CRITICAL_INPUT_ERROR,         "Algo qualifier should be: critical input.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_INVALID,                   "Provide port signal state should be: invalid.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                                      "All data shall be zero.");

  /* Check internally stored DEM events. */
  for(i = 0; i < CML_Min(TEST_MOCKUP_DEM_STACK_SIZE, DemStackFreeIndex); i++)
  {
    COU_ASSERT_EQUAL(DemStack.eventStatus[i], DEM_EVENT_STATUS_PASSED, "DEM event 0x%x should have status PASSED.", DemStack.eventIds[i]);
  }
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}

/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were initialized
 *     - SyncRef shall be filled correctly
 *     - Opmode set to DEMO mode
 *  \precondition
 *     Valid input pointers for base ctrl data and Services. \n
 *  \result
 *     - all outputs to demo values
 *     - signal state to OK
 *     - comp state success
 *     - SyncRef shall contain valid data
 *     - Returns no error
 */
TEST_Exec_002(Exec_002, "Call of HlaExec #002")
{
  /* Define test data */
  BaseReturnCode_t retVal;
  SignalHeader_t dummySignalHeader;
  const BaseOpMode_t opMode = BASE_OM_DEMO;

  /* Initialize inputs */
  InitInputs();

  dummySignalHeader.eSigStatus           = 1u;
  dummySignalHeader.uiCycleCounter       = 2u;
  dummySignalHeader.uiMeasurementCounter = 3u;
  dummySignalHeader.uiTimeStamp          = 4u;

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set demo opmode.");
  COU_SET(HLA_SyncRef.pLsdLightObjectList, dummySignalHeader, "Set dummy signal header for light object list signal header.");

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(retVal,                                                         BASE_RETURN_OK,                         "HlaExec should not return an error.");
  COU_ASSERT_EQUAL(HLA_SyncRef.uiVersionNumber,                                    3u,                                     "SyncRef should contain correct interface version.");
  COU_ASSERT_EQUAL(HLA_SyncRef.sBaseCtrl.eOpMode,                                  opMode,                                 "SyncRef should contain base ctrl data now.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.eSigStatus,           dummySignalHeader.eSigStatus,           "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiCycleCounter,       dummySignalHeader.uiCycleCounter,       "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiMeasurementCounter, dummySignalHeader.uiMeasurementCounter, "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiTimeStamp,          dummySignalHeader.uiTimeStamp,          "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_SUCCESS,                     "Component state should be: Success.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,                    "Error code should be: None.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                           "Algo qualifier should be: OK.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_OK,                        "Provide port signal state should be: OK.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Dist,  42.0f,                                  "Demo value.");

  /* Check internally stored DEM events. */
  for(i = 0; i < CML_Min(TEST_MOCKUP_DEM_STACK_SIZE, DemStackFreeIndex); i++)
  {
    COU_ASSERT_EQUAL(DemStack.eventStatus[i], DEM_EVENT_STATUS_PASSED, "DEM event 0x%x should have status PASSED.", DemStack.eventIds[i]);
  }
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}

/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were initialized
 *     - SyncRef shall be filled correctly
 *     - Opmode set to IDLE mode
 *  \precondition
 *     Valid input pointers for base ctrl data and Services. \n
 *  \result
 *     - all outputs to zero
 *     - signal state to invalid
 *     - comp state: not running
 *     - SyncRef shall contain valid data
 *     - Returns no error
 */
TEST_Exec_003(Exec_003, "Call of HlaExec #003")
{
  /* Define test data */
  BaseReturnCode_t retVal;
  SignalHeader_t dummySignalHeader;
  const BaseOpMode_t opMode = BASE_OM_IDLE;

  /* Initialize inputs */
  InitInputs();

  dummySignalHeader.eSigStatus           = 1u;
  dummySignalHeader.uiCycleCounter       = 2u;
  dummySignalHeader.uiMeasurementCounter = 3u;
  dummySignalHeader.uiTimeStamp          = 4u;

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set idle opmode.");
  COU_SET(HLA_SyncRef.pLsdLightObjectList, dummySignalHeader, "Set dummy signal header for light object list signal header.");

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(retVal,                                                         BASE_RETURN_OK,                         "HlaExec should not return an error.");
  COU_ASSERT_EQUAL(HLA_SyncRef.uiVersionNumber,                                    3u,                                     "SyncRef should contain correct interface version.");
  COU_ASSERT_EQUAL(HLA_SyncRef.sBaseCtrl.eOpMode,                                  opMode,                                 "SyncRef should contain base ctrl data now.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.eSigStatus,           dummySignalHeader.eSigStatus,           "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiCycleCounter,       dummySignalHeader.uiCycleCounter,       "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiMeasurementCounter, dummySignalHeader.uiMeasurementCounter, "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiTimeStamp,          dummySignalHeader.uiTimeStamp,          "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_NOT_RUNNING,                 "Component state should be: Not running.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,                    "Error code should be: None.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                           "Algo qualifier should be: OK.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_INVALID,                   "Provide port signal state should be: Invalid.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                                      "All data shall be zero.");

  /* Check internally stored DEM events. */
  for(i = 0; i < CML_Min(TEST_MOCKUP_DEM_STACK_SIZE, DemStackFreeIndex); i++)
  {
    COU_ASSERT_EQUAL(DemStack.eventStatus[i], DEM_EVENT_STATUS_PASSED, "DEM event 0x%x should have status PASSED.", DemStack.eventIds[i]);
  }
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}

/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were initialized
 *     - SyncRef shall be filled correctly
 *     - Opmode set to RESET mode
 *  \precondition
 *     Valid input pointers for base ctrl data and Services but not more, i.e. failing input check. \n
 *  \result
 *     - all outputs to zero
 *     - signal state to init
 *     - comp state: not initialized
 *     - SyncRef shall contain valid data
 *     - Returns no error
 */
TEST_Exec_004(Exec_004, "Call of HlaExec #004")
{
  /* Define test data */
  BaseReturnCode_t retVal;
  SignalHeader_t dummySignalHeader;
  const BaseOpMode_t opMode = BASE_OM_RESET;

  /* Initialize inputs */
  InitInputs();

  dummySignalHeader.eSigStatus           = 1u;
  dummySignalHeader.uiCycleCounter       = 2u;
  dummySignalHeader.uiMeasurementCounter = 3u;
  dummySignalHeader.uiTimeStamp          = 4u;

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set reset opmode.");
  COU_SET(HLA_SyncRef.pLsdLightObjectList, dummySignalHeader, "Set dummy signal header for light object list signal header.");
  COU_SET(MonoCalibration.eSource, TEST_ERROR_CHECK_SET_ERROR, "Set eSource of calibration data to trigger ErrorCheck mockup to issue an error.");

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(retVal,                                                         BASE_RETURN_OK,                         "HlaExec should not return an error.");
  COU_ASSERT_EQUAL(HLA_SyncRef.uiVersionNumber,                                    3u,                                     "SyncRef should contain correct interface version.");
  COU_ASSERT_EQUAL(HLA_SyncRef.sBaseCtrl.eOpMode,                                  opMode,                                 "SyncRef should contain base ctrl data now.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.eSigStatus,           dummySignalHeader.eSigStatus,           "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiCycleCounter,       dummySignalHeader.uiCycleCounter,       "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiMeasurementCounter, dummySignalHeader.uiMeasurementCounter, "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiTimeStamp,          dummySignalHeader.uiTimeStamp,          "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_NOT_INITIALIZED,             "Component state should be: Not initialized.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_UNKNOWN,                     "Error code should be: Unknown.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_CRITICAL_INPUT_ERROR,         "Algo qualifier should be: critical input.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_INIT,                      "Provide port signal state should be: init.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                                      "All data shall be zero.");

  /* Check internally stored DEM events. */
  for(i = 0; i < CML_Min(TEST_MOCKUP_DEM_STACK_SIZE, DemStackFreeIndex); i++)
  {
    COU_ASSERT_EQUAL(DemStack.eventStatus[i], DEM_EVENT_STATUS_PASSED, "DEM event 0x%x should have status PASSED.", DemStack.eventIds[i]);
  }
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}

/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were initialized
 *     - SyncRef shall be filled correctly
 *     - Opmode set to RESET mode
 *  \precondition
 *     Valid input pointers to satisfy input check.\n
 *  \result
 *     - all outputs to zero
 *     - signal state to init
 *     - comp state: success
 *     - SyncRef shall contain valid data
 *     - Returns no error
 */
TEST_Exec_005(Exec_005, "Call of HlaExec #005")
{
  /* Define test data */
  BaseReturnCode_t retVal;
  SignalHeader_t dummySignalHeader;
  const BaseOpMode_t opMode = BASE_OM_RESET;

  /* Initialize inputs */
  InitInputs();

  dummySignalHeader.eSigStatus           = 1u;
  dummySignalHeader.uiCycleCounter       = 2u;
  dummySignalHeader.uiMeasurementCounter = 3u;
  dummySignalHeader.uiTimeStamp          = 4u;

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set reset opmode.");
  COU_SET(HLA_SyncRef.pLsdLightObjectList, dummySignalHeader, "Set dummy signal header for light object list signal header.");

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(retVal,                                                         BASE_RETURN_OK,                         "HlaExec should not return an error.");
  COU_ASSERT_EQUAL(HLA_SyncRef.uiVersionNumber,                                    3u,                                     "SyncRef should contain correct interface version.");
  COU_ASSERT_EQUAL(HLA_SyncRef.sBaseCtrl.eOpMode,                                  opMode,                                 "SyncRef should contain base ctrl data now.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.eSigStatus,           dummySignalHeader.eSigStatus,           "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiCycleCounter,       dummySignalHeader.uiCycleCounter,       "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiMeasurementCounter, dummySignalHeader.uiMeasurementCounter, "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(HLA_SyncRef_PrevCycle.pLsdLightObjectList.uiTimeStamp,          dummySignalHeader.uiTimeStamp,          "SyncRef of previous cycle should contain dummy signal header.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_SUCCESS,                     "Component state should be: Success.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,                    "Error code should be: No error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                           "Algo qualifier should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_INIT,                      "Provide port signal state should be: init.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                                      "All data shall be zero.");

  /* Check internally stored DEM events. */
  for(i = 0; i < CML_Min(TEST_MOCKUP_DEM_STACK_SIZE, DemStackFreeIndex); i++)
  {
    COU_ASSERT_EQUAL(DemStack.eventStatus[i], DEM_EVENT_STATUS_PASSED, "DEM event 0x%x should have status PASSED.", DemStack.eventIds[i]);
  }
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAF_v_Init__numOfCalls, 1, "HLAF_v_Init() should have been called only once.");
}

/** \test
 *  \description
 *     Test of HlaExec() where ...
 *     - Glob vars were initialized
 *     - SyncRef shall be filled correctly
 *     - Opmode set to RUN mode
 *  \precondition
 *     Valid input pointers to satisfy minimum input check.\n
 *  \result
 *     - None since this part of the code will be tested separately.
 */
TEST_Exec_006(Exec_006, "Call of HlaExec #006")
{
  /* Define test data */
  BaseReturnCode_t retVal;
  SignalHeader_t dummySignalHeader;
  const BaseOpMode_t opMode = BASE_OM_RUN;

  /* Initialize inputs */
  InitInputs();

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set run opmode.");

  /* Call function under test */
  COU_CALL(retVal = HlaExec(&ReqPorts, &ProPorts, &Services), "call of function");
}

/** \test
 *  \description
 *     Test of HLA_OpModeRun() where ...
 *     - Input data check failed and we end up in soft error state
 *  \precondition
 *     Valid input pointers to satisfy minimum input check.\n
 *  \result
 *     - all outputs to zero
 *     - Comp state: "running"
 *     - sig state: "init"
 *     - algo qualifier: "OK"
 */
TEST_OpMode_Run_000(OpMode_Run_000, "Call of HLA_OpModeRun #000")
{
  /* Define test data */
  SignalHeader_t dummySignalHeader;

  /* Initialize inputs */
  InitInputs();

  COU_SET(MonoCalibration.eSource, TEST_ERROR_CHECK_SET_SOFT_ERROR, "Set eSource of calibration data to trigger ErrorCheck mockup to go to soft error state.");

  /* Call function under test */
  COU_CALL(HLA_OpModeRun(&ReqPorts, &Services, &ProPorts), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_RUNNING,                     "Component state should be: Running.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,                    "Error code should be: No error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                           "Algo qualifier should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_INIT,                      "Provide port signal state should be: init.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                                      "All data shall be zero.");
}

/** \test
 *  \description
 *     Test of HLA_OpModeRun() where ...
 *     - Input data check failed and we end up in normal error state
 *  \precondition
 *     Valid input pointers to satisfy minimum input check.\n
 *  \result
 *     - all outputs to zero
 *     - Comp state: "temporary error"
 *     - sig state: "invalid"
 *     - algo qualifier: "critical input error"
 */
TEST_OpMode_Run_001(OpMode_Run_001, "Call of HLA_OpModeRun #001")
{
  /* Define test data */
  SignalHeader_t dummySignalHeader;

  /* Initialize inputs */
  InitInputs();

  COU_SET(MonoCalibration.eSource, TEST_ERROR_CHECK_SET_ERROR, "Set eSource of calibration data to trigger ErrorCheck mockup to issue an error.");

  /* Call function under test */
  COU_CALL(HLA_OpModeRun(&ReqPorts, &Services, &ProPorts), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_TEMPORARY_ERROR,             "Component state should be: temporary error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_UNKNOWN,                     "Error code should be: Unknown error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_CRITICAL_INPUT_ERROR,         "Algo qualifier should be: critical input error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_INVALID,                   "Provide port signal state should be: invalid.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                                      "All data shall be zero.");
}

/** \test
 *  \description
 *     Test of HLA_OpModeRun() where ...
 *     - Input data check passed
 *     - EM data available -> no reduced availability
 *     - No test mode set
 *  \precondition
 *     Valid input pointers to satisfy input check.\n
 *  \result
 *     - all outputs to zero since they are set to default and main function is just a mockup
 *     - Comp state: "running"
 *     - sig state: "ok"
 *     - algo qualifier: "ok"
 */
TEST_OpMode_Run_002(OpMode_Run_002, "Call of HLA_OpModeRun #002")
{
  /* Define test data */
  SignalHeader_t dummySignalHeader;

  /* Initialize inputs */
  InitInputs();

  /* Call function under test */
  COU_CALL(HLA_OpModeRun(&ReqPorts, &Services, &ProPorts), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_RUNNING,     "Component state should be: running.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,    "Error code should be: No error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,           "Algo qualifier should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,        "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_OK,        "Provide port signal state should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                      "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                      "All data shall be zero.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAF_v_Exec__numOfCalls, 1, "HLAF_v_Exec() should have been called only once.");
  COU_ASSERT_EQUAL(HLA_OutputChecks__numOfCalls, 1, "HLA_OutputChecks() should have been called only once.");
}

/** \test
 *  \description
 *     Test of HLA_OpModeRun() where ...
 *     - Input data check passed
 *     - EM data not available
 *     - test mode set to SAE
 *  \precondition
 *     Valid input pointers to satisfy input check.\n
 *  \result
 *     - all outputs to zero since they are set to default and main function is just a mockup
 *     - Comp state: "reduced availability"
 *     - sig state: "ok"
 *     - algo qualifier: "ok"
 */
TEST_OpMode_Run_003(OpMode_Run_003, "Call of HLA_OpModeRun #003")
{
  /* Define test data */
  SignalHeader_t dummySignalHeader;

  /* Initialize inputs */
  InitInputs();

  COU_SET(CPar_HlafPar.AlgoCfg.TestMode, RTE_HLA_TESTMODE_SAE, "Set SAE test mode in coding parameter struct.");
  COU_SET(MonoCalibration.eSource, TEST_ERROR_CHECK_SET_INFORMATION_EM_OBJECT_LIST, "Set eSource of calibration data to trigger ErrorCheck mockup to issue corresponding information.");

  /* Call function under test */
  COU_CALL(HLA_OpModeRun(&ReqPorts, &Services, &ProPorts), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_REDUCED_AVAILABILITY, "Component state should be: reduced availability.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,             "Error code should be: No error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                    "Algo qualifier should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                 "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_OK,                 "Provide port signal state should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                               "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                               "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                               "All data shall be zero.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAF_v_Exec__numOfCalls, 1, "HLAF_v_Exec() should have been called only once.");
  COU_ASSERT_EQUAL(HLA_OutputChecks__numOfCalls, 1, "HLA_OutputChecks() should have been called only once.");
}

/** \test
 *  \description
 *     Test of HLA_OpModeRun() where ...
 *     - Input data check passed
 *     - EM data not available
 *     - test mode set to LAB_ENHANCED
 *  \precondition
 *     Valid input pointers to satisfy input check.\n
 *  \result
 *     - all outputs to zero since they are set to default and main function is just a mockup
 *     - Comp state: "reduced availability"
 *     - sig state: "ok"
 *     - algo qualifier: "ok"
 */
TEST_OpMode_Run_004(OpMode_Run_004, "Call of HLA_OpModeRun #004")
{
  /* Define test data */
  SignalHeader_t dummySignalHeader;

  /* Initialize inputs */
  InitInputs();

  COU_SET(CPar_HlafPar.AlgoCfg.TestMode, RTE_HLA_TESTMODE_LAB_ENHANCED, "Set LAB_ENHANCED test mode in coding parameter struct.");
  COU_SET(MonoCalibration.eSource, TEST_ERROR_CHECK_SET_INFORMATION_EM_OBJECT_LIST, "Set eSource of calibration data to trigger ErrorCheck mockup to issue corresponding information.");

  /* Call function under test */
  COU_CALL(HLA_OpModeRun(&ReqPorts, &Services, &ProPorts), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_REDUCED_AVAILABILITY, "Component state should be: reduced availability.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,             "Error code should be: No error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                    "Algo qualifier should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                 "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_OK,                 "Provide port signal state should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                               "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                               "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                               "All data shall be zero.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAF_v_Exec__numOfCalls, 1, "HLAF_v_Exec() should have been called only once.");
  COU_ASSERT_EQUAL(HLA_OutputChecks__numOfCalls, 1, "HLA_OutputChecks() should have been called only once.");
}
/** \test
 *  \description
 *     Test of HLA_OpModeRun() where ...
 *     - Input data check passed
 *     - EM data not available
 *     - test mode set to LAB
 *  \precondition
 *     Valid input pointers to satisfy input check.\n
 *  \result
 *     - all outputs to zero since they are set to default and main function is just a mockup
 *     - Comp state: "reduced availability"
 *     - sig state: "ok"
 *     - algo qualifier: "ok"
 */
TEST_OpMode_Run_005(OpMode_Run_005, "Call of HLA_OpModeRun #005")
{
  /* Define test data */
  SignalHeader_t dummySignalHeader;

  /* Initialize inputs */
  InitInputs();

  COU_SET(CPar_HlafPar.AlgoCfg.TestMode, RTE_HLA_TESTMODE_LAB, "Set LAB test mode in coding parameter struct.");
  COU_SET(MonoCalibration.eSource, TEST_ERROR_CHECK_SET_INFORMATION_EM_OBJECT_LIST, "Set eSource of calibration data to trigger ErrorCheck mockup to issue corresponding information.");

  /* Call function under test */
  COU_CALL(HLA_OpModeRun(&ReqPorts, &Services, &ProPorts), "call of function");

  /* Check internally set data.                                                    */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState,                            COMP_STATE_REDUCED_AVAILABILITY, "Component state should be: reduced availability.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eErrorCode,                            COMP_ERROR_NO_ERROR,             "Error code should be: No error.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eGenAlgoQualifier,                     ALGO_QUAL_OK,                    "Algo qualifier should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus,                 AL_SIG_STATE_OK,                 "Provide port signal state should always be OK for component state..");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus,         AL_SIG_STATE_OK,                 "Provide port signal state should be: ok.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus,         0,                               "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,            0,                               "All data shall be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,               0,                               "All data shall be zero.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAF_v_Exec__numOfCalls, 1, "HLAF_v_Exec() should have been called only once.");
  COU_ASSERT_EQUAL(HLA_OutputChecks__numOfCalls, 1, "HLA_OutputChecks() should have been called only once.");
}


/** \test
 *  \description
 *     Test of HLA_MapErrors2DemEvents() where ...
 *     - Opmode set to Reset mode
 *     - No errors are set
 *  \precondition
 *     Empty error stack\n
 *  \result
 *     - All DEM Events in mockup DEM stack have to have status PASSED
 */
TEST_DemEvents_000(DemEvents_000, "Call of DemEvents #000")
{
  /* Define test data */
  const BaseOpMode_t opMode = BASE_OM_RESET;

  /* Initialize inputs */
  InitInputs();

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set reset opmode.");

  /* Call function under test */
  COU_CALL(HLA_MapErrors2DemEvents(&ReqPorts, &Services), "call of function");

  /* Check internally stored DEM events. */
  for(i = 0; i < CML_Min(TEST_MOCKUP_DEM_STACK_SIZE, DemStackFreeIndex); i++)
  {
    COU_ASSERT_EQUAL(DemStack.eventStatus[i], DEM_EVENT_STATUS_PASSED, "DEM event 0x%x should have status PASSED.", DemStack.eventIds[i]);
  }
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}



/** \test
 *  \description
 *     Test of HLA_MapErrors2DemEvents() where ...
 *     - Opmode set to RUN mode
 *     - No errors are set
 *  \precondition
 *     Empty error stack\n
 *  \result
 *     - All DEM Events in mockup DEM stack have to have status PASSED
 */
TEST_DemEvents_001(DemEvents_001, "Call of DemEvents #001")
{
  /* Define test data */
  const BaseOpMode_t opMode = BASE_OM_RUN;

  /* Initialize inputs */
  InitInputs();

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set reset opmode.");

  /* Call function under test */
  COU_CALL(HLA_MapErrors2DemEvents(&ReqPorts, &Services), "call of function");

  /* Check internally stored DEM events. */
  // FUSI DEM
  COU_ASSERT_EQUAL(DemStack.eventIds[0], HLA_FUSI_ERROR, "Fusi DEM event should not be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[0], DEM_EVENT_STATUS_PASSED, "Fusi DEM event should not be issued");
  COU_ASSERT_EQUAL(DemStack.eventData[0][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Fusi DEM Event.");

  COU_ASSERT_EQUAL(DemStack.eventIds[1], HLA_SERVICE_ERROR, "Service DEM event should not be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[1], DEM_EVENT_STATUS_PASSED, "Service DEM event should not be issued");
  COU_ASSERT_EQUAL(DemStack.eventData[1][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Service DEM Event.");

  COU_ASSERT_EQUAL(DemStack.eventIds[2], HLA_BUS_DATA_ERROR, "Bus Data DEM event should not be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[2], DEM_EVENT_STATUS_PASSED, "Bus Data DEM event should not be issued");
  COU_ASSERT_EQUAL(DemStack.eventData[2][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Bus Data DEM Event.");

  COU_ASSERT_EQUAL(DemStack.eventIds[3], HLA_INTERNAL_ERROR, "Internal DEM event should not be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[3], DEM_EVENT_STATUS_PASSED, "Internal DEM event should not be issued");
  COU_ASSERT_EQUAL(DemStack.eventData[3][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Internal DEM Event.");
}

/** \test
 *  \description
 *     Test of HLA_MapErrors2DemEvents() where ...
 *     - Opmode set to RUN mode
 *     - Some errors are set so that all possible DEM events are issued
 *  \precondition
 *     None \n
 *  \result
 *     - All DEM Events in mockup DEM stack that are triggered by HLA should have status FAILED
 */
TEST_DemEvents_002(DemEvents_002, "Call of DemEvents #002")
{
  /* Define test data */
  const BaseOpMode_t opMode = BASE_OM_RUN;

  /* Initialize inputs */
  InitInputs();

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set reset opmode.");

  /* Simulate internal errors on error stack in order to issue DEM events. */
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE), "Simulate error in error stack for BusData DEM II");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_BLOCKAGE_NO_VALID_INPUT), "Simulate error in error stack for Internal DEM");
  COU_CALL(HLA_ErrorHandling_SetBusSigState(0x44, 0x5555), "Store bus signal state so that DEM event data can be filled.");

  /* Call function under test */
  COU_CALL(HLA_MapErrors2DemEvents(&ReqPorts, &Services), "call of function");

  /* Check internally stored DEM events. */
  // FUSI DEM
  COU_ASSERT_EQUAL(DemStack.eventIds[0], HLA_FUSI_ERROR, "Fusi DEM event should be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[0], DEM_EVENT_STATUS_FAILED, "Fusi DEM event should be issued");
  for(i = 0; i < 3; i++)
  {
    COU_ASSERT_NOT_EQUAL(DemStack.eventData[0][i], 0u, "Additional data should be filled. For Fusi DEM event first 3 bytes are used.");
  }
  COU_ASSERT_EQUAL(DemStack.eventData[0][3], 0u, "For Fusi DEM event first 3 bytes are used, hence fourth byte should not be touched.");
  COU_ASSERT_EQUAL(DemStack.eventIds[1], HLA_SERVICE_ERROR, "Service DEM event should be passed.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[1], DEM_EVENT_STATUS_PASSED, "Services DEM event should be passed");
  COU_ASSERT_EQUAL(DemStack.eventData[1][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Service DEM Event.");
  COU_ASSERT_EQUAL(DemStack.eventIds[2], HLA_BUS_DATA_ERROR, "Bus Data DEM event should be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[2], DEM_EVENT_STATUS_FAILED, "Bus Data DEM event should be issued");
  for(i = 2; i < 8; i++) // skip first two bytes since vdy const contains here zeros
  {
    COU_ASSERT_NOT_EQUAL(DemStack.eventData[2][i], 0u, "Additional data #%d should be filled. For Bus Data DEM event all 8 bytes are filled.", i);
  }
  COU_ASSERT_EQUAL(DemStack.eventIds[3], HLA_INTERNAL_ERROR, "Internal DEM event should be issued.");
  COU_ASSERT_EQUAL(DemStack.eventData[3][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Internal DEM Event.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[3], DEM_EVENT_STATUS_FAILED, "Internal DEM event should be issued");
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}


/** \test
 *  \description
 *     Test of HLA_MapErrors2DemEvents() where ...
 *     - Opmode set to RUN mode
 *     - Some errors are set so that all possible DEM events are issued
 *     - Ensure that more errors are set than could be stored in additional data
 *  \precondition
 *     None \n
 *  \result
 *     - All DEM Events in mockup DEM stack that are triggered by HLA should have status FAILED
 */
TEST_DemEvents_003(DemEvents_003, "Call of DemEvents #003")
{
  /* Define test data */
  const BaseOpMode_t opMode = BASE_OM_RUN;

  /* Initialize inputs */
  InitInputs();

  COU_SET(BaseCtrlData.eOpMode, opMode, "Set reset opmode.");

  /* Simulate internal errors on error stack in order to issue DEM events. */
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL), "Simulate error in error stack for FUSI DEM");

  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_OBJID), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_OBJID), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_OBJID), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_OBJID), "Simulate error in error stack for FUSI DEM");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_OBJID), "Simulate error in error stack for FUSI DEM");

  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_CRITICAL_INPUTS_VDY), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS), "Simulate error in error stack for BusData DEM I");

  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE), "Simulate error in error stack for BusData DEM I");
  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE), "Simulate error in error stack for BusData DEM II");

  COU_CALL(HLA_ErrorHandling_SetError(HLA_ERROR_BLOCKAGE_NO_VALID_INPUT), "Simulate error in error stack for Internal DEM");
  COU_CALL(HLA_ErrorHandling_SetBusSigState(0x44, 0x5555), "Store bus signal state so that DEM event data can be filled.");

  /* Call function under test */
  COU_CALL(HLA_MapErrors2DemEvents(&ReqPorts, &Services), "call of function");

  /* Check internally stored DEM events. */
  // FUSI DEM
  COU_ASSERT_EQUAL(DemStack.eventIds[0], HLA_FUSI_ERROR, "Fusi DEM event should be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[0], DEM_EVENT_STATUS_FAILED, "Fusi DEM event should be issued");
  for(i = 0; i < 8; i++)
  {
    COU_ASSERT_NOT_EQUAL(DemStack.eventData[0][i], 0u, "Additional data should be filled at index %d.", i);
  }
  COU_ASSERT_EQUAL(DemStack.eventIds[1], HLA_SERVICE_ERROR, "Service DEM event should be passed.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[1], DEM_EVENT_STATUS_PASSED, "Services DEM event should be passed");
  COU_ASSERT_EQUAL(DemStack.eventData[1][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Service DEM Event.");
  COU_ASSERT_EQUAL(DemStack.eventIds[2], HLA_BUS_DATA_ERROR, "Bus Data DEM event should be issued.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[2], DEM_EVENT_STATUS_FAILED, "Bus Data DEM event should be issued");
  for(i = 2; i < 8; i++) // skip first two bytes since vdy const contains here zeros
  {
    COU_ASSERT_NOT_EQUAL(DemStack.eventData[2][i], 0u, "Additional data #%d should be filled. For Bus Data DEM event all 8 bytes are filled.", i);
  }
  COU_ASSERT_EQUAL(DemStack.eventIds[3], HLA_INTERNAL_ERROR, "Internal DEM event should be issued.");
  COU_ASSERT_EQUAL(DemStack.eventData[3][0], TEST_MOCKUP_INIT_BYTE, "Additional data should not be touched for Internal DEM Event.");
  COU_ASSERT_EQUAL(DemStack.eventStatus[3], DEM_EVENT_STATUS_FAILED, "Internal DEM event should be issued");
  COU_ASSERT_EQUAL(DemStackFreeIndex, 4, "As four DEM Events were created by HLA, next free index should be 4.");
}



/** list of all test methods of the related suite. */
cou_test_t main[] = {
   COU_ADD_TEST(FirstStartUp),
   COU_ADD_TEST(Exec_000),
   COU_ADD_TEST(Exec_001),
   COU_ADD_TEST(Exec_002),
   COU_ADD_TEST(Exec_003),
   COU_ADD_TEST(Exec_004),
   COU_ADD_TEST(Exec_005),
   COU_ADD_TEST(Exec_006),
   COU_ADD_TEST(OpMode_Run_000),
   COU_ADD_TEST(OpMode_Run_001),
   COU_ADD_TEST(OpMode_Run_002),
   COU_ADD_TEST(OpMode_Run_003),
   COU_ADD_TEST(OpMode_Run_004),
   COU_ADD_TEST(OpMode_Run_005),
   COU_ADD_TEST(DemEvents_000),
   COU_ADD_TEST(DemEvents_001),
   COU_ADD_TEST(DemEvents_002),
   COU_ADD_TEST(DemEvents_003),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(MainInit, "Initialize main unit")
{
  COU_LOG("Set Inputs to zero");
  InitInputs();
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Main, main, MainInit, "Module tests for main functions."),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
