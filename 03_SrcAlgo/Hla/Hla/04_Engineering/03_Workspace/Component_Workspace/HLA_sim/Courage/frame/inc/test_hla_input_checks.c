/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>

/* inclue for wrp output checks */
#include "hla_defs.h"
#include "hla_input_checks.h"
#include "hla_errorhandling.h"
#include "hla_cpar_init.h"
#include "../../mockup_services.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_InputCheck_001 COU_TEST
#define TEST_InputCheck_002 COU_TEST
#define TEST_InputCheck_003 COU_TEST
#define TEST_InputCheck_004 COU_TEST
#define TEST_InputCheck_005 COU_TEST
#define TEST_InputCheck_006 COU_TEST
#define TEST_InputCheck_007 COU_TEST
#define TEST_InputCheck_008 COU_TEST
#define TEST_InputCheck_009 COU_TEST
#define TEST_InputCheck_010 COU_TEST
#define test_HLA_InputChecks_HlaRadarObjectListIsNull_InformationIsSet COU_TEST
#define test_HLA_InputChecks_InputPointersAreZeroInIdleMode_InputChecksNotPerformed COU_TEST
#define test_HLA_InputChecks_ValidVersionNumber_NoErrorIsSet COU_TEST
#define TEST_InputCheck_013 COU_TEST
#define TEST_InputCheck_014 COU_TEST
#define TEST_InputCheck_015 COU_TEST
#define TEST_InputCheck_016 COU_TEST
#define test_HLA_InputChecks_InvalidSigState_ErrorIsSet COU_TEST
#define test_HLA_InputChecks_TimestampError_ErrorIsSet COU_TEST
#define test_HLA_InputChecks_NullPointerEMObjectListHLARadarObjectList_NoTimestampWarningIsSet COU_TEST
#define TEST_InputCheck_020 COU_TEST
#define TEST_InputCheck_021 COU_TEST
#define TEST_InputCheck_022 COU_TEST
#define TEST_InputCheck_023 COU_TEST
#define TEST_InputCheck_024 COU_TEST
#define TEST_InputCheck_025 COU_TEST
#define TEST_InputCheck_026 COU_TEST
#define TEST_InputCheck_027 COU_TEST
#define TEST_InputCheck_028 COU_TEST
#define TEST_InputCheck_029 COU_TEST
#define TEST_InputCheck_030 COU_TEST
#define TEST_InputCheck_031 COU_TEST
#define TEST_InputCheck_032 COU_TEST
#define TEST_InputCheck_033 COU_TEST
#define TEST_InputCheck_034 COU_TEST
#define TEST_InputCheck_035 COU_TEST
#define TEST_InputCheck_036 COU_TEST
#define TEST_InputCheck_037 COU_TEST
#define TEST_InputCheck_038 COU_TEST
#define TEST_InputCheck_039 COU_TEST
#define TEST_InputCheck_040 COU_TEST
#define TEST_InputCheck_041 COU_TEST
#define TEST_InputCheck_042 COU_TEST
#define TEST_InputCheck_043 COU_TEST
#define TEST_InputCheck_044 COU_TEST
#define TEST_InputCheck_045 COU_TEST
#define TEST_InputCheck_046 COU_TEST
#define TEST_InputCheck_047 COU_TEST
#define TEST_InputCheck_048 COU_TEST
#define TEST_InputCheck_049 COU_TEST
#define TEST_InputCheck_050 COU_TEST
#define TEST_InputCheck_051 COU_TEST
#define TEST_InputCheck_052 COU_TEST
#define TEST_InputCheck_053 COU_TEST
#define TEST_InputCheck_054 COU_TEST
#define TEST_InputCheck_055 COU_TEST
#define TEST_InputCheck_056 COU_TEST
#define TEST_InputCheck_057 COU_TEST
#define TEST_InputCheck_058 COU_TEST
#define TEST_InputCheck_059 COU_TEST
#define TEST_InputCheck_060 COU_TEST
#define TEST_InputCheck_061 COU_TEST
#define TEST_InputCheck_062 COU_TEST
#define TEST_InputCheck_063 COU_TEST


void InitDataInputCheck(void);
void SetMeasurementCounter(AlgoDataTimeStamp_t syncRefMeasurementCounter, AlgoDataTimeStamp_t inputMeasurementCounter);
void SetTimestamp(AlgoDataTimeStamp_t syncRefTimeStamp, AlgoDataTimeStamp_t inputTimeStamp);
void SetSigStatus(AlgoSignalState_t eSigStatus);
void SetValidVersionNumber(void);

/* function inputs */
BaseOpMode_t    eOpMode;
Hla_SyncRef_t   HlaSyncRefPrevCycle;


/* Function to initialize functional input data */
void InitDataInputCheck(void)
{
  /* Set input data to zero */
  Mockup_InitGlobVars();
  memset(&eOpMode, 0, sizeof(eOpMode));
  memset(&HlaSyncRefPrevCycle, 0, sizeof(HlaSyncRefPrevCycle));

  /* Init error handling */
  HLA_ErrorHandling_Init();
}

void SetMeasurementCounter(AlgoDataTimeStamp_t syncRefMeasurementCounter, AlgoDataTimeStamp_t inputMeasurementCounter)
{
  HlaSyncRefPrevCycle.sBaseCtrl.sSigHeader.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pMonoCalibration.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pHlaBusInputSignals.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pVehSig.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pVehDyn.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pCbOutputs.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pLsdEnvironmentData.uiMeasurementCounter= syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pLsdLightObjectList.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pLsdLightList.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pGenObjectList.uiMeasurementCounter = syncRefMeasurementCounter;
  HlaSyncRefPrevCycle.pHlaRadarObjectList.uiMeasurementCounter = syncRefMeasurementCounter;
  BaseCtrlData.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  MonoCalibration.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  HlaBusInputSignals.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  VehSig.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  VDYData.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  Blockage.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  LsdEnvironmentData.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  LsdLightObjectList.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  LsdLightList.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  EMObjectsList.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
  HlaRadarObjectList.sSigHeader.uiMeasurementCounter = inputMeasurementCounter;
}

void SetTimestamp(AlgoDataTimeStamp_t syncRefTimeStamp, AlgoDataTimeStamp_t inputTimeStamp)
{
  HlaSyncRefPrevCycle.sBaseCtrl.sSigHeader.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pMonoCalibration.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pHlaBusInputSignals.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pVehSig.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pVehDyn.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pCbOutputs.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pLsdEnvironmentData.uiTimeStamp= syncRefTimeStamp;
  HlaSyncRefPrevCycle.pLsdLightObjectList.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pLsdLightList.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pGenObjectList.uiTimeStamp = syncRefTimeStamp;
  HlaSyncRefPrevCycle.pHlaRadarObjectList.uiTimeStamp = syncRefTimeStamp;
  BaseCtrlData.sSigHeader.uiTimeStamp = inputTimeStamp;
  MonoCalibration.sSigHeader.uiTimeStamp = inputTimeStamp;
  HlaBusInputSignals.sSigHeader.uiTimeStamp = inputTimeStamp;
  VehSig.sSigHeader.uiTimeStamp = inputTimeStamp;
  VDYData.sSigHeader.uiTimeStamp = inputTimeStamp;
  Blockage.sSigHeader.uiTimeStamp = inputTimeStamp;
  LsdEnvironmentData.sSigHeader.uiTimeStamp = inputTimeStamp;
  LsdLightObjectList.sSigHeader.uiTimeStamp = inputTimeStamp;
  LsdLightList.sSigHeader.uiTimeStamp = inputTimeStamp;
  EMObjectsList.sSigHeader.uiTimeStamp = inputTimeStamp;
  HlaRadarObjectList.sSigHeader.uiTimeStamp = inputTimeStamp;
}

void SetSigStatus(AlgoSignalState_t eSigStatus)
{
  CPar_HlafPar.sSigHeader.eSigStatus = eSigStatus;
  MonoCalibration.sSigHeader.eSigStatus = eSigStatus;
  HlaBusInputSignals.sSigHeader.eSigStatus = eSigStatus;
  VehSig.sSigHeader.eSigStatus = eSigStatus;
  VDYData.sSigHeader.eSigStatus = eSigStatus;
  Blockage.sSigHeader.eSigStatus = eSigStatus;
  LsdEnvironmentData.sSigHeader.eSigStatus = eSigStatus;
  LsdLightObjectList.sSigHeader.eSigStatus = eSigStatus;
  LsdLightList.sSigHeader.eSigStatus = eSigStatus;
  EMObjectsList.sSigHeader.eSigStatus = eSigStatus;
  HlaRadarObjectList.sSigHeader.eSigStatus = eSigStatus;
}

void SetValidVersionNumber(void)
{
  CPar_HlafPar.uiVersionNumber = CPAR_HLAF_PARAMETER_INTFVER;
  MonoCalibration.uiVersionNumber = MONO_CALIBRATION_INTFVER;
  HlaBusInputSignals.uiVersionNumber = HLA_BUS_INPUT_SIGNALS_INTFVER;
  VehSig.uiVersionNumber = BSW_VEH_SIG_INTFVER;
  VDYData.uiVersionNumber = VDY_VEH_DYN_INTFVER;
  Blockage.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
  LsdEnvironmentData.uiVersionNumber = LSD_ENVIRONMENT_DATA_INTFVER;
  LsdLightObjectList.uiVersionNumber = LSD_LIGHT_OBJECT_LIST_INTFVER;
  LsdLightList.uiVersionNumber = LSD_LIGHT_LIST_INTFVER;
  EMObjectsList.uiVersionNumber = (EM_GEN_OBJECT_LIST_INTFVER|EM_GEN_OBJECT_INTFVER);
  HlaRadarObjectList.uiVersionNumber = HLA_RADAR_OBJECT_LIST_INTFVER;
}

/** \test
 *  \description
 *     Test valid input for input pointers. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Error was not set. In case of EM objet list, no information was set. \n */
TEST_InputCheck_001(InputCheck_001, "Test valid input pointer inputs")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_CPAR_HLAF), b_FALSE, "Null pointer cpar error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_MONO_CALI), b_FALSE, "Null pointer mono cali error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE), b_FALSE, "Null pointer blockage error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Null pointer bus input signals error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VDY_DATA), b_FALSE, "Null pointer vdy data error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VEH_SIG), b_FALSE, "Null pointer veh sig error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA), b_FALSE, "Null pointer lsd environment data error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST), b_FALSE, "Null pointer lsd light object list error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST), b_FALSE, "Null pointer em object list information was not set");
}

/** \test
 *  \description
 *     Test null pointer input for pCPar_HlafPar. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_002(InputCheck_002, "Test input pointer pCPar_HlafPar is set to null")
{
  /* Initialize data */
  InitDataInputCheck();
  
  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set cpar pointer to NULL */
  ReqPorts.pCPar_HlafPar = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_CPAR_HLAF), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pMonoCalibration. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_003(InputCheck_003, "Test input pointer pMonoCalibration is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set mono calibration pointer to NULL */
  ReqPorts.pMonoCalibration = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_MONO_CALI), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pCbOutputs. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_004(InputCheck_004, "Test input pointer pCbOutputs is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set blockage pointer to NULL */
  ReqPorts.pCbOutputs = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pHlaBusInputSignals. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_005(InputCheck_005, "Test input pointer pHlaBusInputSignals is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set bus input signals pointer to NULL */
  ReqPorts.pHlaBusInputSignals = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pVehDyn. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_006(InputCheck_006, "Test input pointer pVehDyn is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set vdy data pointer to NULL */
  ReqPorts.pVehDyn = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VDY_DATA), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pVehSig. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_007(InputCheck_007, "Test input pointer pVehSig is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set veh sig pointer to NULL */
  ReqPorts.pVehSig = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VEH_SIG), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pLsdEnvironmentData. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_008(InputCheck_008, "Test input pointer pLsdEnvironmentData is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set lsd environment pointer to NULL */
  ReqPorts.pLsdEnvironmentData = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pLsdLightObjectList. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_009(InputCheck_009, "Test input pointer pLsdLightObjectList is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set lsd light objet list pointer to NULL */
  ReqPorts.pLsdLightObjectList = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test null pointer input for pGenObjectList. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_010(InputCheck_010, "Test input pointer pGenObjectList is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set em object list pointer to NULL */
  ReqPorts.pGenObjectList = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST), b_TRUE, "Information was set");
}

/** \test
 *  \description
 *     Test null pointer input for pHlaRadarObjectList. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
test_HLA_InputChecks_HlaRadarObjectListIsNull_InformationIsSet(HLA_InputChecks_HlaRadarObjectListIsNull_InformationIsSet, "Test input pointer pHlaRadarObjectList is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set em object list pointer to NULL */
  ReqPorts.pHlaRadarObjectList = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_HLA_RADAR_OBJECT_LIST), b_TRUE, "Information was set");
}

/** \test
 *  \description
 *     Test valid input for input pointers. OP Mode was set to idle, so no checks should be performed. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Error was not set. In case of EM objet list, no information was set. \n */
test_HLA_InputChecks_InputPointersAreZeroInIdleMode_InputChecksNotPerformed(HLA_InputChecks_InputPointersAreZeroInIdleMode_InputChecksNotPerformed, "Test that checks were not performed when OP mode is not run")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_IDLE;

  /* Set cpar pointer to NULL */
  ReqPorts.pCPar_HlafPar = NULL;
  ReqPorts.pMonoCalibration = NULL;
  ReqPorts.pCbOutputs = NULL;
  ReqPorts.pHlaBusInputSignals = NULL;
  ReqPorts.pVehDyn = NULL;
  ReqPorts.pVehSig = NULL;
  ReqPorts.pLsdEnvironmentData = NULL;
  ReqPorts.pLsdLightObjectList = NULL;
  ReqPorts.pLsdLightList = NULL;
  ReqPorts.pGenObjectList = NULL;
  ReqPorts.pHlaRadarObjectList = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_CPAR_HLAF), b_FALSE, "Null pointer cpar error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_MONO_CALI), b_FALSE, "Null pointer mono cali error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE), b_FALSE, "Null pointer blockage error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Null pointer bus input signals error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VDY_DATA), b_FALSE, "Null pointer vdy data error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_VEH_SIG), b_FALSE, "Null pointer veh sig error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA), b_FALSE, "Null pointer lsd environment data error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST), b_FALSE, "Null pointer lsd light object list error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTLIST), b_FALSE, "Null pointer lsd light list error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST), b_TRUE, "Null pointer em object list information was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_NULL_POINTER_HLA_RADAR_OBJECT_LIST), b_TRUE, "Null pointer hla radar object list information was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. No Error/warning should be set. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error/Warning was not set. \n */
test_HLA_InputChecks_ValidVersionNumber_NoErrorIsSet(HLA_InputChecks_ValidVersionNumber_NoErrorIsSet, "Test that no error/warning is set in case of valid uiVersionNumber")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  SetValidVersionNumber();

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_CPAR_HLAF), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_EM_OBJECT_LIST), b_FALSE, "Information was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_HLA_RADAR_OBJECT_LIST), b_FALSE, "Information was not set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. No Error/warning should be set. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error/Warning was not set. Measurement counter was set in soft error state function. \n */
TEST_InputCheck_013(InputCheck_013, "Test that no error/warning is set in case of signal status is set to init")
{
  AlgoCycleCounter_t softErrorMeasCnt;

  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state of inputs to init */
  SetSigStatus(AL_SIG_STATE_INIT);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_MONO_CALI), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_VEH_SIG), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_VDY_DATA), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_BLOCKAGE), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTLIST), b_TRUE, "Warning was set");

  /* get soft error state and check output */
  softErrorMeasCnt = HLA_ErrorHandling_GetSoftErrorState();
  COU_ASSERT_EQUAL(softErrorMeasCnt, BaseCtrlData.sSigHeader.uiMeasurementCounter, "Soft error state was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to init. Measurement counter diff is too high, so that a function is too long in soft error state which triggers an error. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_014(InputCheck_014, "Test that error is set in case sig status is set to init and measurement counter difference is too high")
{
  AlgoCycleCounter_t softErrorMeasCnt;

  /* Initialize data */
  InitDataInputCheck();

  /* set soft error state */
  HLA_ErrorHandling_SetSoftErrorState(1u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter (higher than (ALGO_FUSI_DEBOUNCE_CYCLES * 2) to ensure that we enter the soft error state */
  /* BaseCtrlData.sSigHeader.uiMeasurementCounter = (ALGO_FUSI_DEBOUNCE_CYCLES * 3); */
  /* trigger wraparound of measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 0;

  /* set sig state of inputs to init */
  SetSigStatus(AL_SIG_STATE_INIT);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_CPAR_HLAF), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_MONO_CALI), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VEH_SIG), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VDY_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_BLOCKAGE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTLIST), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to init. Measurement counter difference is not too high, so that a function just triggers a warning. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. \n */
TEST_InputCheck_015(InputCheck_015, "Test that warning is set in case of sig status is set to init")
{
  AlgoCycleCounter_t softErrorMeasCnt;

  /* Initialize data */
  InitDataInputCheck();

  /* set soft error state */
  HLA_ErrorHandling_SetSoftErrorState(1u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter, so that error is not triggered (smaller than (ALGO_FUSI_DEBOUNCE_CYCLES * 2)) */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = (ALGO_FUSI_DEBOUNCE_CYCLES);

  /* set sig state of inputs to init */
  SetSigStatus(AL_SIG_STATE_INIT);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_MONO_CALI), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_VEH_SIG), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_VDY_DATA), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_BLOCKAGE), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTLIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to valid. No Error/warning should be set. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error/Warning was not set. Soft error state was set to zero. \n */
TEST_InputCheck_016(InputCheck_016, "Test that no error/warning is set in case of valid signal status")
{
  AlgoCycleCounter_t softErrorMeasCnt;

  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_MONO_CALI), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_VEH_SIG), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_VDY_DATA), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_BLOCKAGE), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTLIST), b_FALSE, "Warning was not set");

  /* get soft error state and check output */
  softErrorMeasCnt = HLA_ErrorHandling_GetSoftErrorState();
  COU_ASSERT_EQUAL(softErrorMeasCnt, 0u, "Soft error state was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to invalid. Error should be set. Set EM object signal status to invalid, which should trigger an information. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. Information regarding EM object list is set. \n */
test_HLA_InputChecks_InvalidSigState_ErrorIsSet(HLA_InputChecks_InvalidSigState_ErrorIsSet, "Test that error is set in case of invalid sigstatus")
{
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state of inputs to invalid */
  SetSigStatus(AL_SIG_STATE_INVALID);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_CPAR_HLAF), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_MONO_CALI), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VEH_SIG), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VDY_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_BLOCKAGE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_SIG_STATE_EM_OBJECT_LIST), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_SIG_STATE_HLA_RADAR_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to ok. Timestamp difference to previous frame is too small. Error should be set. In case of EM object list a warning shall be triggered. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. Information regarding EM object list is set. \n */
test_HLA_InputChecks_TimestampError_ErrorIsSet(HLA_InputChecks_TimestampError_ErrorIsSet, "Test that error is set in case of timestamp error")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetTimestamp((inputTimeStamp + 1), inputTimeStamp);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_HLA_RADAR_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Check that no timestamp warning for em and hla radar object list is set if pointer is not valid, but all other input pointers are ok. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was not set. \n */
test_HLA_InputChecks_NullPointerEMObjectListHLARadarObjectList_NoTimestampWarningIsSet(HLA_InputChecks_NullPointerEMObjectListHLARadarObjectList_NoTimestampWarningIsSet, "Test that no warning is set for em and hla radar object, if pointer is not valid")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  HlaSyncRefPrevCycle.pGenObjectList.uiTimeStamp = inputTimeStamp + 1;
  ReqPorts.pGenObjectList = NULL;

  HlaSyncRefPrevCycle.pHlaRadarObjectList.uiTimeStamp = inputTimeStamp + 1;
  ReqPorts.pHlaRadarObjectList = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_HLA_RADAR_OBJECT_LIST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Check that no error is set in case of timestamp error and op Mode is not run. Only BSW control data and em object list are checked. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was not set, except for BSW control data. Information regarding EM object list is set. \n */
TEST_InputCheck_020(InputCheck_020, "Test that only em object list and BSW control data is checked in case of timestamp error and op mode is not run")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_IDLE;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetTimestamp((inputTimeStamp + 1), inputTimeStamp);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of measurement counter error and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. Information regarding EM object list is set. \n */
TEST_InputCheck_021(InputCheck_021, "Test that error is set in case of measurement counter error")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* set measurement counter */
  SetMeasurementCounter((inputMeasurementCounter + 1), inputMeasurementCounter);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of measurement counter error and op Mode is not run. Only BSW control data and em object list are checked. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was not set, except for BSW control data. Information regarding EM object list is set. \n */
TEST_InputCheck_022(InputCheck_022, "Test that no error is set in case of measurement counter error, except BSW control data and EM object list")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_IDLE;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* set measurement counter */
  SetMeasurementCounter((inputMeasurementCounter + 1), inputMeasurementCounter);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of increasing measurement counter and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. Information regarding EM object list is set. \n */
TEST_InputCheck_023(InputCheck_023, "Test that no error is set in case of increasing measurement counter")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* set measurement counter */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Check that error is set in case of invalid bus signal states and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set for every bus signal state. \n */
TEST_InputCheck_024(InputCheck_024, "Test that error is set in case of invalid bus signal states")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* set measurement counter */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* Set vdy signals to invalid */
  VDYData.State[VDY_SOUT_POS_YAWRATE] = VDY_IO_STATE_INVALID;
  VDYData.State[VDY_SOUT_POS_CURVE] = VDY_IO_STATE_INVALID;
  VehSig.VehSigMain.State[VDY_SIN_POS_SWA] = VDY_IO_STATE_INVALID;
  VDYData.State[VDY_SOUT_POS_VELOCITY] = VDY_IO_STATE_INVALID;
  VDYData.State[VDY_SOUT_POS_ACCEL] = VDY_IO_STATE_INVALID;
  VDYData.State[VDY_SOUT_POS_MOTIONSTATE] = VDY_IO_STATE_INVALID;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_SPEEDO_SPEED] = VDY_IO_STATE_INVALID;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_INVALID;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_CURVE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_SWA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid bus signal states and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set for every bus signal state. \n */
TEST_InputCheck_025(InputCheck_025, "Test that no error is set in case of valid (state valid) bus signal states")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* Set vdy signals to invalid */
  VDYData.State[VDY_SOUT_POS_YAWRATE] = VDY_IO_STATE_VALID;
  VDYData.State[VDY_SOUT_POS_CURVE] = VDY_IO_STATE_VALID;
  VehSig.VehSigMain.State[VDY_SIN_POS_SWA] = VDY_IO_STATE_VALID;
  VDYData.State[VDY_SOUT_POS_VELOCITY] = VDY_IO_STATE_VALID;
  VDYData.State[VDY_SOUT_POS_ACCEL] = VDY_IO_STATE_VALID;
  VDYData.State[VDY_SOUT_POS_MOTIONSTATE] = VDY_IO_STATE_VALID;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_SPEEDO_SPEED] = VDY_IO_STATE_VALID;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_VALID;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_CURVE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_SWA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Check that error is set in case of invalid inputs in critical input data check. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_026(InputCheck_026, "Test that error is set in case of invalid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* invalid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_CROI;
  MonoCalibration.sIntrinsic.fFocalX = 0.0f;
  MonoCalibration.sIntrinsic.fFocalY = 0.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid inputs in critical input data check. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_027(InputCheck_027, "Test that no error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 10.0f;
  MonoCalibration.sIntrinsic.fFocalY = 10.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid hlaf cpar inputs. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was not set. \n */
TEST_InputCheck_028(InputCheck_028, "Test that no error is set in case of valid hlaf cpar inputs")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  uint32 i;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  CPar_HlafPar.AlgoCfg.TestMode =  RTE_HLA_TESTMODE_2;
  CPar_HlafPar.AlgoCfg.FogDetection = RTE_HLA_FOGDET_ACTIVE;
  CPar_HlafPar.KeepOnDelay.distanceOncomingVehicle = 100u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMin = 100u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax = 100u;
  CPar_HlafPar.TurnOnDelay.OncomingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMax = 1.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxShort = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxLong = 1.0f;
  CPar_HlafPar.TurnOnDelay.SlowOvertaking = 1.0f;
  CPar_HlafPar.TurnOnDelay.Fog = 1.0f;
  CPar_HlafPar.TurnOnDelay.Blockage = 1.0f;
  CPar_HlafPar.TurnOffDelay.oncomingVehicle = 1.0f;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.ActivateSpeed = 1.0f;
  CPar_HlafPar.Speed.ActivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.AlwaysActiveSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_VeryLowSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_LowRadius = 1.0f;
  CPar_HlafPar.Speed.KeepOff_HighAcceleration = 1.0f;
  CPar_HlafPar.Speed.KeepOff_AccTime = 1.0f;
  CPar_HlafPar.Speed.KeepOff_Delay = 1.0f;
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = 5u;
  CPar_HlafPar.Dimming.DimmingDetection = RTE_HLA_DIMMDET_ACTIVE;
  CPar_HlafPar.Dimming.ReductThreshLevel1 = 1.0f;
  CPar_HlafPar.Dimming.ReductThreshLevel2 = 1.0f;
  CPar_HlafPar.Dimming.TurnOnDelay = 1.0f;
  for(i = 0u; i < RTE_HLA_NUM_DIMM_AREAS_BORDERS; i++)
  {
    CPar_HlafPar.Dimming.AreaRightBorderArray[i] = CML_Deg2Rad(i + 1.0f);
  }

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Check that error is set in case of invalid hlaf cpar inputs. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_029(InputCheck_029, "Test that error is set in case of invalid hlaf cpar inputs")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  CPar_HlafPar.AlgoCfg.TestMode =  123u;
  CPar_HlafPar.AlgoCfg.FogDetection = 123u;
  CPar_HlafPar.KeepOnDelay.distanceOncomingVehicle = 8000u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMin = 100u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax = 100u;
  CPar_HlafPar.TurnOnDelay.OncomingMin = 100.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMax = 1.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxShort = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxLong = 1.0f;
  CPar_HlafPar.TurnOnDelay.SlowOvertaking = 1.0f;
  CPar_HlafPar.TurnOnDelay.Fog = 1.0f;
  CPar_HlafPar.TurnOnDelay.Blockage = 1.0f;
  CPar_HlafPar.TurnOffDelay.oncomingVehicle = 100.0f;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = -1.0f;
  CPar_HlafPar.Speed.DeactivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.ActivateSpeed = 800.0f;
  CPar_HlafPar.Speed.ActivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.AlwaysActiveSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_VeryLowSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_LowRadius = 1.0f;
  CPar_HlafPar.Speed.KeepOff_HighAcceleration = 1.0f;
  CPar_HlafPar.Speed.KeepOff_AccTime = 1.0f;
  CPar_HlafPar.Speed.KeepOff_Delay = 1.0f;
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = 50u;
  CPar_HlafPar.Dimming.DimmingDetection = 123u;
  CPar_HlafPar.Dimming.ReductThreshLevel1 = 1.0f;
  CPar_HlafPar.Dimming.ReductThreshLevel2 = 1.0f;
  CPar_HlafPar.Dimming.TurnOnDelay = 1.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid hlaf cpar inputs, when checking the plausibility. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. \n */
TEST_InputCheck_030(InputCheck_030, "Test that no error is set in case of valid hlaf cpar inputs, when checking the plausibility")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid coding parameters */
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax  =  100u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMin  =  50u;
  CPar_HlafPar.TurnOnDelay.OncomingMax = 10.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 10.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxShort = 10.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxLong = 10.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn = 5.0f;
  CPar_HlafPar.Speed.DeactivateSpeedHigh = 20.0f;
  CPar_HlafPar.Speed.ActivateSpeedHigh = 10.0f;
  CPar_HlafPar.Speed.AlwaysActiveSpeed = 5.0f;
  CPar_HlafPar.Speed.ActivateSpeed = 3.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = 2.0f;
  CPar_HlafPar.Speed.KeepOff_VeryLowSpeed = 1.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_TURN_ON_PARAMETERS), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Check that error is set in case of invalid hlaf cpar inputs, when checking the plausibility. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_031(InputCheck_031, "Test that no error is set in case of invalid hlaf cpar inputs, when checking the plausibility")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid coding parameters */
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax  =  50u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMin  =  100u;
  CPar_HlafPar.TurnOnDelay.OncomingMax = 0.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 10.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxShort = 0.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxLong = 0.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn =05.0f;
  CPar_HlafPar.Speed.DeactivateSpeedHigh = 10.0f;
  CPar_HlafPar.Speed.ActivateSpeedHigh = 20.0f;
  CPar_HlafPar.Speed.AlwaysActiveSpeed = 5.0f;
  CPar_HlafPar.Speed.ActivateSpeed = 3.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = 2.0f;
  CPar_HlafPar.Speed.KeepOff_VeryLowSpeed = 1.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_TURN_ON_PARAMETERS), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that no warning is set in case of valid hlaf cpar inputs, when checking the difference to default parameters. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_032(InputCheck_032, "Test that no warning is set in case of valid hlaf cpar inputs, when checking the difference to default parameters")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* get valid cpars */
  CParInitCPAR_HLAF_Parameter(&CPar_HlafPar);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_ALGO_CONFIG_PARAMETERS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_KEEP_ON_DELAY_PARAMETERS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_ON_DELAY_PARAMETERS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_OFF_DELAY_PARAMETERS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_SPEED_PARAMETERS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_DIMMING_PARAMETERS), b_FALSE, "Warning was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_MATRIX_PARAMETERS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Check that warnings is set in case of invalid hlaf cpar inputs, when checking the difference to default parameters. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_033(InputCheck_033, "Test that warning is set in case of invalid hlaf cpar inputs, when checking the difference to default parameters")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* get valid cpars */
  CParInitCPAR_HLAF_Parameter(&CPar_HlafPar);

  /* change cpar values to trigger warning */
  CPar_HlafPar.AlgoCfg.TestMode = CPar_HlafPar.AlgoCfg.TestMode + 1;
  CPar_HlafPar.KeepOnDelay.distanceOncomingVehicle = CPar_HlafPar.KeepOnDelay.distanceOncomingVehicle + 1.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMin = CPar_HlafPar.TurnOnDelay.OncomingMin + 1.0f;
  CPar_HlafPar.TurnOffDelay.oncomingVehicle = CPar_HlafPar.TurnOffDelay.oncomingVehicle + 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = CPar_HlafPar.Speed.DeactivateSpeed + 1.0f;
  CPar_HlafPar.Dimming.AreaRightBorderArray[0] = CPar_HlafPar.Dimming.AreaRightBorderArray[0] + 1.0f;
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = CPar_HlafPar.Matrix.MaxNumGlarefreeArea + 1u;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_ALGO_CONFIG_PARAMETERS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_KEEP_ON_DELAY_PARAMETERS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_ON_DELAY_PARAMETERS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_OFF_DELAY_PARAMETERS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_SPEED_PARAMETERS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_DIMMING_PARAMETERS), b_TRUE, "Warning was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_MATRIX_PARAMETERS), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Check that error is set in case of ProPorts pointer is set to Null. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_034(InputCheck_034, "Test that error is set in case of ProPorts pointer is set to Null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, NULL, &Services), "function call");

  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_PRO_PORT_NULL_POINTER_LIST), b_TRUE, "Error was set");

}

/** \test
 *  \description
 *     Check that error is set in case of pointer in ProPorts struct are set to Null. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_035(InputCheck_035, "Test that error is set in case of pointer in ProPorts struct are set to Null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set pointer to null */
  ProPorts.pAlgoCompState = NULL;
  ProPorts.pHlaf_HeadlightControl = NULL;


  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_PRO_PORT_NULL_POINTER_COMP_STATE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_PRO_PORT_NULL_POINTER_HEADLIGHT_CONTROL), b_TRUE, "Error was set");

}

/** \test
 *  \description
 *     Check that no error is set in case of valid pointers in ProPorts struct. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_036(InputCheck_036, "Test that no error is set in case of valid pointers in ProPorts struct")
{
  /* Initialize data */
  InitDataInputCheck();

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_PRO_PORT_NULL_POINTER_COMP_STATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_PRO_PORT_NULL_POINTER_HEADLIGHT_CONTROL), b_FALSE, "Error was not set");

}

/** \test
 *  \description
 *     Check that error is set in case of NULL pointers for Services struct. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_037(InputCheck_037, "Test that error is set in case of NULL pointer for Services struct")
{
  /* Initialize data */
  InitDataInputCheck();

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, NULL), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_LIST), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that error is set in case of NULL pointers in Services struct. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_038(InputCheck_038, "Test that error is set in case of NULL pointers in Services struct")
{
  /* Initialize data */
  InitDataInputCheck();

  memset(&Services,           0, sizeof(Services));

  Services.pfRTAAlgoServiceAddEvent = NULL;
  Services.pfMeasStartFuncCycle = NULL;
  Services.pfMeasFreeze = NULL;
  Services.pfDem_SetEventStatus = NULL;
  Services.pfDem_SetEventStatusPreExtData = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_ADD_RTA_EVENT), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_MEAS_START_CYCLE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_MEAS_FREEZE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_DEM_SET_EVENT), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_DEM_EXT_DATA), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid pointers in Services struct. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. \n */
TEST_InputCheck_039(InputCheck_039, "Test that no error is set in case of valid pointers in Services struct")
{
  /* Initialize data */
  InitDataInputCheck();

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_ADD_RTA_EVENT), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_MEAS_START_CYCLE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_MEAS_FREEZE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_DEM_SET_EVENT), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_SERVICES_NULL_POINTER_DEM_EXT_DATA), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Check that error is set in case of Null pointer for ReqPorts. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_040(InputCheck_040, "Test that error is set in case of Null pointers for ReqPorts")
{
  /* Initialize data */
  InitDataInputCheck();

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(NULL, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LIST), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that error is set in case of Null pointer for BaseCtrlData in ReqPorts. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_041(InputCheck_041, "Test that error is set in case of Null pointers for BaseCtrlData in ReqPorts")
{
  /* Initialize data */
  InitDataInputCheck();

  ReqPorts.pBaseCtrlData = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_BASE_CONTROL_DATA), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that error is set in case of invlalid version number and sigstatus for BaseCtrlData in ReqPorts. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_042(InputCheck_042, "Test that error is set in case of invlalid version number and sigstatus for BaseCtrlData in ReqPorts")
{
  /* Initialize data */
  InitDataInputCheck();

  BaseCtrlData.uiVersionNumber = BASE_CTRL_DATA_INTFVER + 1u;
  BaseCtrlData.sSigHeader.eSigStatus =  AL_SIG_STATE_OK + 1u;

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid version number and sigstatus for BaseCtrlData in ReqPorts. \n
 *     calls function HLA_InputChecks_MinimumInputs() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. \n */
TEST_InputCheck_043(InputCheck_043, "Test that error is set in case of valid version number and sigstatus for BaseCtrlData in ReqPorts")
{
  /* Initialize data */
  InitDataInputCheck();

  BaseCtrlData.uiVersionNumber = BASE_CTRL_DATA_INTFVER ;
  BaseCtrlData.sSigHeader.eSigStatus =  AL_SIG_STATE_OK;

  /* function call */
  COU_CALL(HLA_InputChecks_MinimumInputs(&ReqPorts, &ProPorts, &Services), "function call");

  /* check output */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to ok. Wrap around of timestamp occured. No error should be set. In case of EM object list no warning shall be triggered. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. Information regarding EM object list is set. \n */
TEST_InputCheck_044(InputCheck_044, "Test that in case of warp around of uiTimeStamp no error is set")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  sint64 WraparoundTimestampDiff = (UI32_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_TIME));
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetTimestamp((inputTimeStamp + WraparoundTimestampDiff), inputTimeStamp);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to ok. Diff to base control data is too big. Error should be set. In case of EM object list a warning shall be triggered. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. Information regarding EM object list is set. \n */
TEST_InputCheck_045(InputCheck_045, "Test that diff to base control data leads to an error")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  sint64 WraparoundTimestampDiff = (UI32_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_TIME));
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetTimestamp((inputTimeStamp + WraparoundTimestampDiff), inputTimeStamp);
  /* diff to base control data leads to error */
  BaseCtrlData.sSigHeader.uiTimeStamp = inputTimeStamp + ALGO_FUSI_DEBOUNCE_TIME + 1;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to ok. Timestamp diff to sync ref is ok, but diff to base control data is too big. Error should be set. In case of EM object list a warning shall be triggered. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. Information regarding EM object list is set. \n */
TEST_InputCheck_046(InputCheck_046, "Test that diff to base control data leads to an error, even if timestamp diff to sync ref is ok")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  sint64 WraparoundTimestampDiff = (UI32_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_TIME));
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetTimestamp(inputTimeStamp, inputTimeStamp);

  /* diff to base control data leads to error */
  BaseCtrlData.sSigHeader.uiTimeStamp = inputTimeStamp + ALGO_FUSI_DEBOUNCE_TIME + 1;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test uiVersionNumber of inputs. Set signal status of inputs to ok. Timestamp diff to sync and base control data occurs. No error should be set. In case of EM object list no warning shall be triggered. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was not set. Information regarding EM object list is not set. \n */
TEST_InputCheck_047(InputCheck_047, "Test that warp around in timestamp diff to snyc ref and base control data occurs, but no error is set")
{
  AlgoDataTimeStamp_t inputTimeStamp = 1u;
  sint64 WraparoundTimestampDiff = (UI32_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_TIME));
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetTimestamp((inputTimeStamp + WraparoundTimestampDiff), inputTimeStamp);

  /* diff to base control data leads to error */
  BaseCtrlData.sSigHeader.uiTimeStamp = inputTimeStamp + WraparoundTimestampDiff + 1;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Check that no error is set in case of wrap around of measurement counter and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was not set. Information regarding EM object list is not set. \n */
TEST_InputCheck_048(InputCheck_048, "Test that wrap around of measurement counter leads to no error.")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  uint32 WraparoundMeasCounterDiff = (UI16_T_MAX - (10 * ALGO_FUSI_DEBOUNCE_CYCLES));
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state of inputs to init */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter((inputMeasurementCounter + WraparoundMeasCounterDiff), inputMeasurementCounter);

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetInformation(HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid bus signal states and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set for every bus signal state. \n */
TEST_InputCheck_049(InputCheck_049, "Test that no error is set in case of valid (state init) bus signal states")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state of inputs to init */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* Set vdy signals to invalid */
  VDYData.State[VDY_SOUT_POS_YAWRATE] = VDY_IO_STATE_INIT;
  VehSig.VehSigMain.State[VDY_SIN_POS_SWA] = VDY_IO_STATE_INIT;
  VDYData.State[VDY_SOUT_POS_VELOCITY] = VDY_IO_STATE_INIT;
  VDYData.State[VDY_SOUT_POS_ACCEL] = VDY_IO_STATE_INIT;
  VDYData.State[VDY_SOUT_POS_MOTIONSTATE] = VDY_IO_STATE_INIT;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_SPEEDO_SPEED] = VDY_IO_STATE_INIT;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_INIT;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_SWA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Check that no error is set in case of valid bus signal states and op Mode is set to run. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set for every bus signal state. \n */
TEST_InputCheck_050(InputCheck_050, "Test that no error is set in case of valid (wiper state not available) bus signal states")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter + 1));

  /* Set vdy signals to invalid */
  VDYData.State[VDY_SOUT_POS_YAWRATE] = VDY_IO_STATE_INIT;
  VehSig.VehSigMain.State[VDY_SIN_POS_SWA] = VDY_IO_STATE_INIT;
  VDYData.State[VDY_SOUT_POS_VELOCITY] = VDY_IO_STATE_INIT;
  VDYData.State[VDY_SOUT_POS_ACCEL] = VDY_IO_STATE_INIT;
  VDYData.State[VDY_SOUT_POS_MOTIONSTATE] = VDY_IO_STATE_INIT;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_SPEEDO_SPEED] = VDY_IO_STATE_INIT;
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_NOTAVAIL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_SWA), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED), b_FALSE, "Error was not set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Test null pointer input for pLsdLightObjectList. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_051(InputCheck_051, "Test input pointer pLsdLightObjectList is set to null")
{
  /* Initialize data */
  InitDataInputCheck();

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* Set lsd light objet list pointer to NULL */
  ReqPorts.pLsdLightList = NULL;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTLIST), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to FocalX as zero. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_052(InputCheck_052, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 0.0f;
  MonoCalibration.sIntrinsic.fFocalY = 0.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to FocalY as zero. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_053(InputCheck_053, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 10.0f;
  MonoCalibration.sIntrinsic.fFocalY = 0.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to FocalX as INF. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_054(InputCheck_054, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = f_INF;
  MonoCalibration.sIntrinsic.fFocalY = 10.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to FocalY as INF. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_055(InputCheck_055, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 10.0f;
  MonoCalibration.sIntrinsic.fFocalY = f_INF;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to FocalX as NAN. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_056(InputCheck_056, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = f_NAN;
  MonoCalibration.sIntrinsic.fFocalY = 10.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to FocalY as NAN. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_057(InputCheck_057, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 10.0f;
  MonoCalibration.sIntrinsic.fFocalY = f_NAN;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to fYaw as INF. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_058(InputCheck_058, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 10.0f;
  MonoCalibration.sIntrinsic.fFocalY = 10.0f;
  MonoCalibration.sPoseCalibration.fYaw = f_INF;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of valid inputs in critical input data check due to fYaw as NAN. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_059(InputCheck_059, "Test that error is set in case of valid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* valid input signals for critical input check */
  MonoCalibration.eCameraType = MC_CAMERA_TYPE_RROI;
  MonoCalibration.sIntrinsic.fFocalX = 10.0f;
  MonoCalibration.sIntrinsic.fFocalY = 0.0f;
  MonoCalibration.sPoseCalibration.fYaw = f_NAN;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_MONO_CALI), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Check that error is set in case of invalid hlaf cpar inputs, some floats are INF. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_060(InputCheck_060, "Test that error is set in case of invalid hlaf cpar inputs")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  CPar_HlafPar.AlgoCfg.TestMode =  123u;
  CPar_HlafPar.AlgoCfg.FogDetection = 123u;
  CPar_HlafPar.KeepOnDelay.distanceOncomingVehicle = 8000u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMin = 100u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax = 100u;
  CPar_HlafPar.TurnOnDelay.OncomingMin = f_INF;
  CPar_HlafPar.TurnOnDelay.OncomingMax = 1.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxShort = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxLong = 1.0f;
  CPar_HlafPar.TurnOnDelay.SlowOvertaking = 1.0f;
  CPar_HlafPar.TurnOnDelay.Fog = 1.0f;
  CPar_HlafPar.TurnOnDelay.Blockage = 1.0f;
  CPar_HlafPar.TurnOffDelay.oncomingVehicle = f_INF;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.ActivateSpeed = f_INF;
  CPar_HlafPar.Speed.ActivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.AlwaysActiveSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_VeryLowSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_LowRadius = 1.0f;
  CPar_HlafPar.Speed.KeepOff_HighAcceleration = 1.0f;
  CPar_HlafPar.Speed.KeepOff_AccTime = 1.0f;
  CPar_HlafPar.Speed.KeepOff_Delay = 1.0f;
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = 1u;
  CPar_HlafPar.Dimming.DimmingDetection = RTE_HLA_DIMMDET_ACTIVE;
  CPar_HlafPar.Dimming.ReductThreshLevel1 = f_INF;
  CPar_HlafPar.Dimming.ReductThreshLevel2 = 1.0f;
  CPar_HlafPar.Dimming.TurnOnDelay = 1.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS), b_TRUE, "Error was set");
}


/** \test
 *  \description
 *     Check that error is set in case of invalid hlaf cpar inputs, some floats are NAN. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_061(InputCheck_061, "Test that error is set in case of invalid hlaf cpar inputs")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RESET;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  CPar_HlafPar.AlgoCfg.TestMode =  123u;
  CPar_HlafPar.AlgoCfg.FogDetection = 123u;
  CPar_HlafPar.KeepOnDelay.distanceOncomingVehicle = 8000u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMin = 100u;
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax = 100u;
  CPar_HlafPar.TurnOnDelay.OncomingMin = f_NAN;
  CPar_HlafPar.TurnOnDelay.OncomingMax = 1.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMin = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxShort = 1.0f;
  CPar_HlafPar.TurnOnDelay.PrecedingMaxLong = 1.0f;
  CPar_HlafPar.TurnOnDelay.SlowOvertaking = 1.0f;
  CPar_HlafPar.TurnOnDelay.Fog = 1.0f;
  CPar_HlafPar.TurnOnDelay.Blockage = 1.0f;
  CPar_HlafPar.TurnOffDelay.oncomingVehicle = f_NAN;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeed = 1.0f;
  CPar_HlafPar.Speed.DeactivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.ActivateSpeed = f_NAN;
  CPar_HlafPar.Speed.ActivateSpeedHigh = 1.0f;
  CPar_HlafPar.Speed.AlwaysActiveSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_VeryLowSpeed = 1.0f;
  CPar_HlafPar.Speed.KeepOff_LowRadius = 1.0f;
  CPar_HlafPar.Speed.KeepOff_HighAcceleration = 1.0f;
  CPar_HlafPar.Speed.KeepOff_AccTime = 1.0f;
  CPar_HlafPar.Speed.KeepOff_Delay = 1.0f;
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = 1u;
  CPar_HlafPar.Dimming.DimmingDetection = RTE_HLA_DIMMDET_ACTIVE;
  CPar_HlafPar.Dimming.ReductThreshLevel1 = f_NAN;
  CPar_HlafPar.Dimming.ReductThreshLevel2 = 1.0f;
  CPar_HlafPar.Dimming.TurnOnDelay = 1.0f;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS), b_TRUE, "Error was set");
}



/** \test
 *  \description
 *     Check that error is set in case of invalid inputs in critical input data check by VDY data as INF. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_062(InputCheck_062, "Test that error is set in case of invalid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* invalid input signals for critical input check */
  VDYData.Longitudinal.Accel      = f_INF;
  VDYData.Longitudinal.Velocity   = f_INF;
  VDYData.Lateral.Curve.Curve     = f_INF;
  VDYData.Lateral.YawRate.YawRate = f_INF;
  VehSig.VehSigAdd.SpeedoSpeed    = f_INF;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_VDY), b_TRUE, "Error was set");
}



/** \test
 *  \description
 *     Check that error is set in case of invalid inputs in critical input data check by VDY data as NAN. \n
 *     calls function HLA_InputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Error was set. \n */
TEST_InputCheck_062(InputCheck_063, "Test that error is set in case of invalid inputs in critical input data check")
{
  AlgoDataTimeStamp_t inputMeasurementCounter = 1u;
  /* Initialize data */
  InitDataInputCheck();

  /* clear soft error state */
  HLA_ErrorHandling_SetSoftErrorState(0u);

  /* set OpMode to Run */
  eOpMode = BASE_OM_RUN;

  /* uiVersionNumber are set to valid values */
  SetValidVersionNumber();

  /* set measurement counter */
  BaseCtrlData.sSigHeader.uiMeasurementCounter = 123u;

  /* set sig state */
  SetSigStatus(AL_SIG_STATE_OK);

  /* create too small timestamp difference */
  SetMeasurementCounter(inputMeasurementCounter, (inputMeasurementCounter+1));

  /* invalid input signals for critical input check */
  VDYData.Longitudinal.Accel      = f_NAN;
  VDYData.Longitudinal.Velocity   = f_NAN;
  VDYData.Lateral.Curve.Curve     = f_NAN;
  VDYData.Lateral.YawRate.YawRate = f_NAN;
  VehSig.VehSigAdd.SpeedoSpeed    = f_NAN;

  /* function call */
  COU_CALL(HLA_InputChecks(eOpMode, &ReqPorts, &HlaSyncRefPrevCycle), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_CRITICAL_INPUTS_VDY), b_TRUE, "Error was set");
}


/** list of all test methods of the related suite. */
cou_test_t hla_InputCheck[] = {
   COU_ADD_TEST(InputCheck_001),
   COU_ADD_TEST(InputCheck_002),
   COU_ADD_TEST(InputCheck_003),
   COU_ADD_TEST(InputCheck_004),
   COU_ADD_TEST(InputCheck_005),
   COU_ADD_TEST(InputCheck_006),
   COU_ADD_TEST(InputCheck_007),
   COU_ADD_TEST(InputCheck_008),
   COU_ADD_TEST(InputCheck_009),
   COU_ADD_TEST(InputCheck_010),
   COU_ADD_TEST(HLA_InputChecks_HlaRadarObjectListIsNull_InformationIsSet),
   COU_ADD_TEST(HLA_InputChecks_InputPointersAreZeroInIdleMode_InputChecksNotPerformed),
   COU_ADD_TEST(HLA_InputChecks_ValidVersionNumber_NoErrorIsSet),
   COU_ADD_TEST(InputCheck_013),
   COU_ADD_TEST(InputCheck_014),
   COU_ADD_TEST(InputCheck_015),
   COU_ADD_TEST(InputCheck_016),
   COU_ADD_TEST(HLA_InputChecks_InvalidSigState_ErrorIsSet),
   COU_ADD_TEST(HLA_InputChecks_TimestampError_ErrorIsSet),
   COU_ADD_TEST(HLA_InputChecks_NullPointerEMObjectListHLARadarObjectList_NoTimestampWarningIsSet),
   COU_ADD_TEST(InputCheck_020),
   COU_ADD_TEST(InputCheck_021),
   COU_ADD_TEST(InputCheck_022),
   COU_ADD_TEST(InputCheck_023),
   COU_ADD_TEST(InputCheck_024),
   COU_ADD_TEST(InputCheck_025),
   COU_ADD_TEST(InputCheck_026),
   COU_ADD_TEST(InputCheck_027),
   COU_ADD_TEST(InputCheck_028),
   COU_ADD_TEST(InputCheck_029),
   COU_ADD_TEST(InputCheck_030),
   COU_ADD_TEST(InputCheck_031),
   COU_ADD_TEST(InputCheck_032),
   COU_ADD_TEST(InputCheck_033),
   COU_ADD_TEST(InputCheck_034),
   COU_ADD_TEST(InputCheck_035),
   COU_ADD_TEST(InputCheck_036),
   COU_ADD_TEST(InputCheck_037),
   COU_ADD_TEST(InputCheck_038),
   COU_ADD_TEST(InputCheck_039),
   COU_ADD_TEST(InputCheck_040),
   COU_ADD_TEST(InputCheck_041),
   COU_ADD_TEST(InputCheck_042),
   COU_ADD_TEST(InputCheck_043),
   COU_ADD_TEST(InputCheck_044),
   COU_ADD_TEST(InputCheck_045),
   COU_ADD_TEST(InputCheck_046),
   COU_ADD_TEST(InputCheck_047),
   COU_ADD_TEST(InputCheck_048),
   COU_ADD_TEST(InputCheck_049),
   COU_ADD_TEST(InputCheck_050),
   COU_ADD_TEST(InputCheck_051),
   COU_ADD_TEST(InputCheck_052),
   COU_ADD_TEST(InputCheck_053),
   COU_ADD_TEST(InputCheck_054),
   COU_ADD_TEST(InputCheck_055),
   COU_ADD_TEST(InputCheck_056),
   COU_ADD_TEST(InputCheck_057),
   COU_ADD_TEST(InputCheck_058),
   COU_ADD_TEST(InputCheck_059),
   COU_ADD_TEST(InputCheck_060),
   COU_ADD_TEST(InputCheck_061),
   COU_ADD_TEST(InputCheck_062),
   COU_ADD_TEST(InputCheck_063),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(InputCheckInit, "Initialize input check")
{
  /* Nothing to do here */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_InputCheck, hla_InputCheck, InputCheckInit, "Module test for hla_input_check.c"),
   COU_ADD_SUITE_END,
}; /* suites */

#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
