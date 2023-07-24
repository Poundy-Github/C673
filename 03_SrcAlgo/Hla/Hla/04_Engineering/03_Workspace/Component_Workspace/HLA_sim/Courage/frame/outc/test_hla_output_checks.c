/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* inclued for wrp output checks */
#include "hla_defs.h"
#include "hla_errorhandling.h"
#include "hla_output_checks.h"

#include "../../mockup_services.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_OutputChecks_001 COU_TEST
#define TEST_OutputChecks_002 COU_TEST
#define TEST_OutputChecks_003 COU_TEST
#define TEST_OutputChecks_004 COU_TEST
#define TEST_OutputChecks_005 COU_TEST
#define TEST_OutputChecks_006 COU_TEST
#define TEST_OutputChecks_007 COU_TEST
#define TEST_OutputChecks_008 COU_TEST
#define TEST_OutputChecks_009 COU_TEST
#define TEST_OutputChecks_010 COU_TEST
#define TEST_OutputChecks_011 COU_TEST
#define TEST_OutputChecks_012 COU_TEST
#define TEST_OutputChecks_013 COU_TEST
#define TEST_OutputChecks_014 COU_TEST
#define TEST_OutputChecks_015 COU_TEST
#define TEST_OutputChecks_016 COU_TEST
#define TEST_OutputChecks_017 COU_TEST
#define TEST_OutputChecks_018 COU_TEST
#define TEST_OutputChecks_019 COU_TEST
#define TEST_OutputChecks_020 COU_TEST
#define TEST_OutputChecks_021 COU_TEST
#define TEST_OutputChecks_022 COU_TEST
#define TEST_OutputChecks_023 COU_TEST
#define TEST_OutputChecks_024 COU_TEST
#define TEST_OutputChecks_025 COU_TEST
#define TEST_OutputChecks_026 COU_TEST
#define TEST_OutputChecks_027 COU_TEST
#define TEST_OutputChecks_028 COU_TEST
#define TEST_OutputChecks_029 COU_TEST
#define TEST_OutputChecks_030 COU_TEST
#define TEST_OutputChecks_031 COU_TEST
#define TEST_OutputChecks_032 COU_TEST
#define TEST_OutputChecks_033 COU_TEST
#define TEST_OutputChecks_034 COU_TEST
#define TEST_OutputChecks_035 COU_TEST
#define TEST_OutputChecks_036 COU_TEST
#define TEST_OutputChecks_037 COU_TEST
#define TEST_OutputChecks_038 COU_TEST
#define TEST_OutputChecks_039 COU_TEST
#define TEST_OutputChecks_040 COU_TEST
#define TEST_OutputChecks_041 COU_TEST
#define TEST_OutputChecks_042 COU_TEST
#define TEST_OutputChecks_043 COU_TEST
#define TEST_OutputChecks_044 COU_TEST
#define TEST_OutputChecks_045 COU_TEST
#define TEST_OutputChecks_046 COU_TEST
#define TEST_OutputChecks_047 COU_TEST
#define TEST_OutputChecks_048 COU_TEST
#define TEST_OutputChecks_049 COU_TEST
#define TEST_OutputChecks_050 COU_TEST
#define TEST_OutputChecks_051 COU_TEST
#define TEST_OutputChecks_052 COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistState_ShouldStayAsPairlightWide COU_TEST
#define TEST_OutputChecks_053 COU_TEST
#define TEST_OutputChecks_054 COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsUnknown COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsLow COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsMid COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsHigh COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsInvalid COU_TEST
#define TEST_HLA_OutputChecks_BndryLeftDistReliability_SetToDefaultValue COU_TEST
#define TEST_OutputChecks_055 COU_TEST
#define TEST_OutputChecks_056 COU_TEST
#define TEST_OutputChecks_057 COU_TEST
#define TEST_OutputChecks_058 COU_TEST
#define TEST_OutputChecks_059 COU_TEST
#define TEST_OutputChecks_060 COU_TEST
#define TEST_OutputChecks_061 COU_TEST
#define TEST_OutputChecks_062 COU_TEST
#define TEST_OutputChecks_063 COU_TEST
#define TEST_OutputChecks_064 COU_TEST
#define TEST_OutputChecks_065 COU_TEST
#define TEST_OutputChecks_066 COU_TEST
#define TEST_OutputChecks_067 COU_TEST
#define TEST_OutputChecks_068 COU_TEST
#define TEST_OutputChecks_069 COU_TEST
#define TEST_OutputChecks_070 COU_TEST
#define TEST_OutputChecks_071 COU_TEST
#define TEST_OutputChecks_072 COU_TEST
#define TEST_OutputChecks_073 COU_TEST
#define TEST_OutputChecks_074 COU_TEST
#define TEST_OutputChecks_075 COU_TEST
#define TEST_OutputChecks_076 COU_TEST
#define TEST_OutputChecks_077 COU_TEST
#define TEST_OutputChecks_078 COU_TEST
#define TEST_OutputChecks_079 COU_TEST
#define TEST_OutputChecks_080 COU_TEST
#define TEST_OutputChecks_081 COU_TEST
#define TEST_OutputChecks_082 COU_TEST
#define TEST_OutputChecks_083 COU_TEST
#define TEST_OutputChecks_084 COU_TEST
#define TEST_OutputChecks_085 COU_TEST
#define TEST_OutputChecks_086 COU_TEST
#define TEST_OutputChecks_087 COU_TEST
#define TEST_OutputChecks_088 COU_TEST
#define test_HLA_OutputCheck_MatrixTurnOffReason_SetInvalidTurnOffReason_TurnOffReasonErrorAndWarningIsSet COU_TEST
#define TEST_OutputChecks_090 COU_TEST
#define TEST_OutputChecks_091 COU_TEST
#define TEST_OutputChecks_092 COU_TEST
#define TEST_OutputChecks_093 COU_TEST
#define TEST_OutputChecks_094 COU_TEST
#define TEST_OutputChecks_095 COU_TEST
#define TEST_OutputChecks_096 COU_TEST
#define TEST_OutputChecks_097 COU_TEST
#define TEST_OutputChecks_098 COU_TEST
#define TEST_OutputChecks_099 COU_TEST
#define TEST_OutputChecks_100 COU_TEST
#define TEST_OutputChecks_101 COU_TEST
#define TEST_OutputChecks_102 COU_TEST
#define TEST_OutputChecks_103 COU_TEST
#define TEST_OutputChecks_104 COU_TEST
#define TEST_OutputChecks_105 COU_TEST
#define TEST_OutputChecks_106 COU_TEST
#define TEST_OutputChecks_107 COU_TEST
#define TEST_OutputChecks_108 COU_TEST
#define TEST_OutputChecks_109 COU_TEST
#define TEST_OutputChecks_110 COU_TEST
#define TEST_OutputChecks_111 COU_TEST
#define TEST_OutputChecks_112 COU_TEST
#define TEST_OutputChecks_113 COU_TEST
#define TEST_OutputChecks_114 COU_TEST
#define TEST_OutputChecks_115 COU_TEST
#define TEST_OutputChecks_116 COU_TEST
#define TEST_OutputChecks_117 COU_TEST
#define TEST_OutputChecks_118 COU_TEST
#define TEST_OutputChecks_119 COU_TEST
#define TEST_OutputChecks_120 COU_TEST
#define TEST_OutputChecks_121 COU_TEST
#define TEST_OutputChecks_122 COU_TEST
#define TEST_OutputChecks_123 COU_TEST
#define TEST_OutputChecks_124 COU_TEST
#define TEST_OutputChecks_125 COU_TEST
#define TEST_OutputChecks_126 COU_TEST
#define TEST_OutputChecks_127 COU_TEST
#define TEST_OutputChecks_128 COU_TEST
#define TEST_OutputChecks_129 COU_TEST
#define TEST_OutputChecks_130 COU_TEST
#define TEST_OutputChecks_131 COU_TEST
#define TEST_OutputChecks_132 COU_TEST
#define TEST_OutputChecks_133 COU_TEST
#define TEST_OutputChecks_134 COU_TEST
#define TEST_OutputChecks_135 COU_TEST
#define TEST_OutputChecks_136 COU_TEST
#define TEST_OutputChecks_137 COU_TEST
#define TEST_OutputChecks_138 COU_TEST
#define TEST_OutputChecks_139 COU_TEST
#define TEST_OutputChecks_140 COU_TEST
#define TEST_OutputChecks_141 COU_TEST
#define TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsUnknown COU_TEST
#define TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsOncomingPassing COU_TEST
#define TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsPrecedingOvertaking COU_TEST
#define TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsInvalid COU_TEST
#define TEST_HLA_OutputChecks_SceneInfo_SetToDefaultValue COU_TEST



void InitDataOutputChecks(void);

/* Function to initialize functional input data */
void InitDataOutputChecks(void)
{
  Mockup_InitGlobVars();
  /* Set default output data, i.e. zeros */
  memset(&HeadlightControl, 0, sizeof(HeadlightControl));
  memset(&AlgoCompState, 0, sizeof(AlgoCompState));
  
  /* Init error handling */
  HLA_ErrorHandling_Init();
}


/** \test
 *  \description
 *     Test that the version number of the comp state gets fixed, when it was filled with an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Comp state version number was fixed. Correct warning was set. \n */
TEST_OutputChecks_001(OutputChecks_001, "Test that the version number of the comp state gets fixed")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set invalid version number */
  ProPorts.pAlgoCompState->uiVersionNumber = 1234;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->uiVersionNumber, COMP_STATE_INTFVER, "Comp state version number was fixed");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_INTERFACE_VERSION), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test that there is no warning set when the version number of the comp state is correct. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Comp state version number wasn't changed (since it is valid). No warning was set. \n */
TEST_OutputChecks_002(OutputChecks_002, "Test that there is no warning set when the version number of the comp state is correct")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set invalid version number */
  ProPorts.pAlgoCompState->uiVersionNumber = COMP_STATE_INTFVER;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->uiVersionNumber, COMP_STATE_INTFVER, "Comp state version stays the same fixed");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_INTERFACE_VERSION), b_FALSE, "Warning was not set");
  
}

/** \test
 *  \description
 *     Test that eSigStatus is set to init. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. SigStatus is still set to init. \n */
TEST_OutputChecks_003(OutputChecks_003, "Test that there is no warning set when the version number of the comp state is to init")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to init */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus, AL_SIG_STATE_INIT, "Sig status is still set to init");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SIG_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eSigStatus is set to ok. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. SigStatus is still set to ok. \n */
TEST_OutputChecks_004(OutputChecks_004, "Test that there is no warning set when the version number of the comp state is set to ok")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus, AL_SIG_STATE_OK, "Sig status is still set to ok");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SIG_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that a warning is set when the version number of the comp state is not correct. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. SigStatus is set to ok. \n */
TEST_OutputChecks_005(OutputChecks_005, "Test that a warning is set when the version number of the comp state is not correct")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to an invalid value */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = 123u;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus, AL_SIG_STATE_OK, "Sig status is set to ok");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SIG_STATE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_NOT_INITIALIZED. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays on COMP_STATE_NOT_INITIALIZED. \n */
TEST_OutputChecks_006(OutputChecks_006, "Test that eCompState is set to COMP_STATE_NOT_INITIALIZED")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to not initialized */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_NOT_INITIALIZED;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_NOT_INITIALIZED, "Comp state is set to COMP_STATE_NOT_INITIALIZED");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_RUNNING. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays on COMP_STATE_RUNNING. \n */
TEST_OutputChecks_007(OutputChecks_007, "Test that eCompState is set to COMP_STATE_RUNNING")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to running */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_RUNNING;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_RUNNING, "Comp state is set to COMP_STATE_RUNNING");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_TEMPORARY_ERROR. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays COMP_STATE_TEMPORARY_ERROR. \n */
TEST_OutputChecks_008(OutputChecks_008, "Test that eCompState is set to COMP_STATE_TEMPORARY_ERROR")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to temp error */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_TEMPORARY_ERROR, "Comp state is set to COMP_STATE_TEMPORARY_ERROR");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_PERMANENT_ERROR. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays COMP_STATE_PERMANENT_ERROR. \n */
TEST_OutputChecks_009(OutputChecks_009, "Test that eCompState is set to COMP_STATE_PERMANENT_ERROR")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to permanent error */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_PERMANENT_ERROR;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_PERMANENT_ERROR, "Comp state is set to COMP_STATE_PERMANENT_ERROR");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_SUCCESS. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays COMP_STATE_SUCCESS. \n */
TEST_OutputChecks_010(OutputChecks_010, "Test that eCompState is set to COMP_STATE_SUCCESS")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to success */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_SUCCESS;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_SUCCESS, "Comp state is set to COMP_STATE_SUCCESS");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_REDUCED_AVAILABILITY. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays COMP_STATE_REDUCED_AVAILABILITY. \n */
TEST_OutputChecks_011(OutputChecks_011, "Test that eCompState is set to COMP_STATE_REDUCED_AVAILABILITY")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to reduced availability */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_REDUCED_AVAILABILITY;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_REDUCED_AVAILABILITY, "Comp state is set to COMP_STATE_REDUCED_AVAILABILITY");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to COMP_STATE_NOT_RUNNING. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eCompState stays COMP_STATE_NOT_RUNNING. \n */
TEST_OutputChecks_012(OutputChecks_012, "Test that eCompState is set to COMP_STATE_NOT_RUNNING")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to not running */
  ProPorts.pAlgoCompState->eCompState = COMP_STATE_NOT_RUNNING;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_NOT_RUNNING, "Comp state is set to COMP_STATE_NOT_RUNNING");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eCompState is set to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. eCompState is set to COMP_STATE_TEMPORARY_ERROR. \n */
TEST_OutputChecks_013(OutputChecks_013, "Test that eCompState is set to an invalid value")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to invalid value */
  ProPorts.pAlgoCompState->eCompState = 123;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eCompState, COMP_STATE_TEMPORARY_ERROR, "Comp state is set to COMP_STATE_TEMPORARY_ERROR");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to BASE_SSM_NONE. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eShedulerSubModeRequest stays BASE_SSM_NONE. \n */
TEST_OutputChecks_014(OutputChecks_014, "Test that eShedulerSubModeRequest is set to BASE_SSM_NONE")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to BASE_SSM_NONE */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_NONE, "eShedulerSubModeRequest is set to BASE_SSM_NONE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to BASE_SSM_BLOCKAGE. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eShedulerSubModeRequest stays BASE_SSM_BLOCKAGE. \n */
TEST_OutputChecks_015(OutputChecks_015, "Test that eShedulerSubModeRequest is set to BASE_SSM_BLOCKAGE")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to BASE_SSM_BLOCKAGE */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = BASE_SSM_BLOCKAGE;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_BLOCKAGE, "eShedulerSubModeRequest is set to BASE_SSM_BLOCKAGE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to BASE_SSM_DEGRADED. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eShedulerSubModeRequest stays BASE_SSM_DEGRADED. \n */
TEST_OutputChecks_016(OutputChecks_016, "Test that eShedulerSubModeRequest is set to BASE_SSM_DEGRADED")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to BASE_SSM_DEGRADED */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = BASE_SSM_DEGRADED;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_DEGRADED, "eShedulerSubModeRequest is set to BASE_SSM_DEGRADED");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to BASE_SSM_STANDALONE. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eShedulerSubModeRequest stays BASE_SSM_STANDALONE. \n */
TEST_OutputChecks_017(OutputChecks_017, "Test that eShedulerSubModeRequest is set to BASE_SSM_STANDALONE")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to BASE_SSM_STANDALONE */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = BASE_SSM_STANDALONE;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_STANDALONE, "eShedulerSubModeRequest is set to BASE_SSM_STANDALONE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to BASE_SSM_PARALLEL. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eShedulerSubModeRequest stays BASE_SSM_PARALLEL. \n */
TEST_OutputChecks_018(OutputChecks_018, "Test that eShedulerSubModeRequest is set to BASE_SSM_PARALLEL")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to BASE_SSM_PARALLEL */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = BASE_SSM_PARALLEL;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_PARALLEL, "eShedulerSubModeRequest is set to BASE_SSM_PARALLEL");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to BASE_SSM_NOT_CALIBRATED. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. eShedulerSubModeRequest stays BASE_SSM_NOT_CALIBRATED. \n */
TEST_OutputChecks_019(OutputChecks_019, "Test that eShedulerSubModeRequest is set to BASE_SSM_NOT_CALIBRATED")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to BASE_SSM_NOT_CALIBRATED */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = BASE_SSM_NOT_CALIBRATED;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_NOT_CALIBRATED, "eShedulerSubModeRequest is set to BASE_SSM_NOT_CALIBRATED");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test that eShedulerSubModeRequest is set to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. eShedulerSubModeRequest is set to BASE_SSM_NONE. \n */
TEST_OutputChecks_020(OutputChecks_020, "Test that eShedulerSubModeRequest is set to an invalid value")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set comp state to invalid value */
  ProPorts.pAlgoCompState->eShedulerSubModeRequest = 123;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->eShedulerSubModeRequest, BASE_SSM_NONE, "eShedulerSubModeRequest is set to BASE_SSM_NONE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test that eGenAlgoQualifier  is set to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. eGenAlgoQualifier is set to ALGO_QUAL_GENERAL_FUNCTION_ERROR. \n */
TEST_OutputChecks_021(OutputChecks_021, "Test that eGenAlgoQualifier  is set to an invalid value")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* Set gen algo qualifier to invalid value */
  ProPorts.pAlgoCompState->eGenAlgoQualifier  = (ALGO_QUAL_CALIBRATION_RUNNING * 2u);
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(CML_GetBit(ProPorts.pAlgoCompState->eGenAlgoQualifier, ALGO_QUAL_GENERAL_FUNCTION_ERROR), b_TRUE, "set gen qualifier to function error");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_ALGO_QUALIFIER), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control signal header. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. eSigStatus is set to AL_SIG_STATE_INIT. \n */
TEST_OutputChecks_022(OutputChecks_022, "Test headlight control signal header is set to AL_SIG_STATE_INIT")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* set sigstatus to init */
  ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus, AL_SIG_STATE_INIT, "sig status stays on AL_SIG_STATE_INIT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_SIG_STATE), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Test headlight control signal header. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. eSigStatus is set to AL_SIG_STATE_OK. \n */
TEST_OutputChecks_023(OutputChecks_023, "Test headlight control signal header is set to AL_SIG_STATE_OK")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* set sigstatus to ok */
  ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus, AL_SIG_STATE_OK, "sig status stays on AL_SIG_STATE_OK");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_SIG_STATE), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Test headlight control signal header. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No error was set. eSigStatus is set to AL_SIG_STATE_INVALID. \n */
TEST_OutputChecks_024(OutputChecks_024, "Test headlight control signal header is set to AL_SIG_STATE_INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* set sigstatus to invalid */
  ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus, AL_SIG_STATE_INVALID, "sig status stays on AL_SIG_STATE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_SIG_STATE), b_FALSE, "Error was not set");
}

/** \test
 *  \description
 *     Test headlight control signal header, which is set to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Sig status and headlight control errors were set. eSigStatus is set to AL_SIG_STATE_INVALID. \n */
TEST_OutputChecks_025(OutputChecks_025, "Test headlight control signal header is set to an invalid value")
{
  /* define invalid value */
  uint8 invalidValue = 123u;
  
  /* Initialize data */
  InitDataOutputChecks();
  
  /* set sigstatus to invalid value */
  ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus = invalidValue;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus, AL_SIG_STATE_INVALID, "sig status is set to AL_SIG_STATE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_SIG_STATE), b_TRUE, "Error was set");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test headlight control traffic style. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. traffic style is set to _STYLE_UNKNOWN. \n */
TEST_OutputChecks_026(OutputChecks_026, "Test headlight control traffic style is set to _STYLE_UNKNOWN")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set traffic style to unknown*/
  ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle, RTE_HLA_TRAFFIC_STYLE_UNKNOWN, "traffic style stays on _STYLE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control traffic style. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. traffic style is set to _STYLE_RHT. \n */
TEST_OutputChecks_027(OutputChecks_027, "Test headlight control traffic style is set to _STYLE_RHT")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set traffic style to rht*/
  ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHT;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle, RTE_HLA_TRAFFIC_STYLE_RHT, "traffic style stays on _STYLE_RHT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control traffic style. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. traffic style is set to _STYLE_LHT. \n */
TEST_OutputChecks_028(OutputChecks_028, "Test headlight control traffic style is set to _STYLE_LHT")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set traffic style to lht*/
  ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHT;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle, RTE_HLA_TRAFFIC_STYLE_LHT, "traffic style stays on _STYLE_LHT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control traffic style. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. traffic style is set to _STYLE_INVALID. \n */
TEST_OutputChecks_029(OutputChecks_029, "Test headlight control traffic style is set to _STYLE_INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set traffic style to invalid*/
  ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_INVALID;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle, RTE_HLA_TRAFFIC_STYLE_INVALID, "traffic style stays on _STYLE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control traffic style. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. traffic style is set to 0. \n */
TEST_OutputChecks_030(OutputChecks_030, "Test headlight control traffic style is set to invalid value")
{
  /* define invalid value */
  uint8 invalidValue = 123u;
  
  /* Initialize data */
  InitDataOutputChecks();
  
  /* Set traffic style to invalid value*/
  ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle = invalidValue;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle, RTE_HLA_TRAFFIC_STYLE_UNKNOWN, "traffic style is set to zero");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control sense mode. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Sens mode is set to RTE_HLA_SENSMODE_UNKNOWN. \n */
TEST_OutputChecks_031(OutputChecks_031, "Test headlight control sens mode is set to RTE_HLA_SENSMODE_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set sens mode to unknown*/
  ProPorts.pHlaf_HeadlightControl->Common.SensMode = RTE_HLA_SENSMODE_UNKNOWN;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode, RTE_HLA_SENSMODE_UNKNOWN, "sens mode is set to RTE_HLA_SENSMODE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control sense mode. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Sens mode is set to RTE_HLA_SENSMODE_NORMAL. \n */
TEST_OutputChecks_032(OutputChecks_032, "Test headlight control sens mode is set to RTE_HLA_SENSMODE_NORMAL")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set sens mode to normal*/
  ProPorts.pHlaf_HeadlightControl->Common.SensMode = RTE_HLA_SENSMODE_NORMAL;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode, RTE_HLA_SENSMODE_NORMAL, "sens mode is set to RTE_HLA_SENSMODE_NORMAL");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control sense mode. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Sens mode is set to RTE_HLA_SENSMODE_US. \n */
TEST_OutputChecks_033(OutputChecks_033, "Test headlight control sens mode is set to RTE_HLA_SENSMODE_US")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set sens mode to us*/
  ProPorts.pHlaf_HeadlightControl->Common.SensMode = RTE_HLA_SENSMODE_US;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode, RTE_HLA_SENSMODE_US, "sens mode is set to RTE_HLA_SENSMODE_US");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control sense mode. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Sens mode is set to RTE_HLA_SENSMODE_INVALID. \n */
TEST_OutputChecks_034(OutputChecks_034, "Test headlight control sens mode is set to RTE_HLA_SENSMODE_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set sens mode to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.SensMode = RTE_HLA_SENSMODE_INVALID;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode, RTE_HLA_SENSMODE_INVALID, "sens mode is set to RTE_HLA_SENSMODE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control sense mode. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. Sens mode is set to zero. \n */
TEST_OutputChecks_035(OutputChecks_035, "Test headlight control sens mode is set to RTE_HLA_SENSMODE_INVALID")
{
  /* define invalid value */
  uint8 invalidValue = 123u;
  
  /* initialize data */
  InitDataOutputChecks();
  
  /* set sens mode to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.SensMode = invalidValue;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode, 0, "sens mode is set to zero");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control speed state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Speed state is set to RTE_HLAF_SPEEDSTATE_UNKNOWN. \n */
TEST_OutputChecks_036(OutputChecks_036, "Test headlight control speed state is set to RTE_HLAF_SPEEDSTATE_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set speed state to unknown */
  ProPorts.pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_UNKNOWN;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState, RTE_HLAF_SPEEDSTATE_UNKNOWN, "sens mode is set to RTE_HLAF_SPEEDSTATE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control speed state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Speed state is set to RTE_HLAF_SPEEDSTATE_TOO_LOW. \n */
TEST_OutputChecks_037(OutputChecks_037, "Test headlight control speed state is set to RTE_HLAF_SPEEDSTATE_TOO_LOW")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set speed state to too low */
  ProPorts.pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_TOO_LOW;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState, RTE_HLAF_SPEEDSTATE_TOO_LOW, "sens mode is set to RTE_HLAF_SPEEDSTATE_TOO_LOW");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control speed state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Speed state is set to RTE_HLAF_SPEEDSTATE_IN_RANGE. \n */
TEST_OutputChecks_038(OutputChecks_038, "Test headlight control speed state is set to RTE_HLAF_SPEEDSTATE_IN_RANGE")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set speed state to in range */
  ProPorts.pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_IN_RANGE;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState, RTE_HLAF_SPEEDSTATE_IN_RANGE, "sens mode is set to RTE_HLAF_SPEEDSTATE_IN_RANGE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control speed state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Speed state is set to RTE_HLAF_SPEEDSTATE_TOO_HIGH. \n */
TEST_OutputChecks_039(OutputChecks_039, "Test headlight control speed state is set to RTE_HLAF_SPEEDSTATE_TOO_HIGH")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set speed state to too high */
  ProPorts.pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_TOO_HIGH;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState, RTE_HLAF_SPEEDSTATE_TOO_HIGH, "sens mode is set to RTE_HLAF_SPEEDSTATE_TOO_HIGH");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control speed state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Speed state is set to RTE_HLAF_SPEEDSTATE_INVALID. \n */
TEST_OutputChecks_040(OutputChecks_040, "Test headlight control speed state is set to RTE_HLAF_SPEEDSTATE_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();
  
  /* set speed state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_INVALID;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState, RTE_HLAF_SPEEDSTATE_INVALID, "sens mode is set to RTE_HLAF_SPEEDSTATE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control speed state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. Speed state is set to RTE_HLAF_SPEEDSTATE_UNKNOWN. \n */
TEST_OutputChecks_041(OutputChecks_041, "Test headlight control speed state is set to an invalid value")
{
  /* define invalid value */
  uint8 invalidValue = 123;
  
  /* initialize data */
  InitDataOutputChecks();
  
  /* set speed state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.SpeedState = invalidValue;
  
  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState, RTE_HLAF_SPEEDSTATE_UNKNOWN, "sens mode is set to RTE_HLAF_SPEEDSTATE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. gfa data is filled with invalid values. Depending of the signal either the value get's fixed and a warning is set or in more severe cases a error is set. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Signals are fixed. Warnings or Errors are set. Signal status is set to invalid. Headlight control error was set. \n */
TEST_OutputChecks_042(OutputChecks_042, "Test headlight control gfa data")
{

  float32 invalidDistance = 1234.56f;
  float32 invalidAng =  CML_Deg2Rad(27.0f);
  float32 invalidAngCam =  CML_Deg2Rad(5.1f);
  float32 invalidObjID = LSD_LIGHT_OBJECT_LIST_LENGTH;
  float32 invalidTTB = 20.0f;
  uint8 invalidExProb = 120u;
  uint8 i = 0;

	/* initialize data */
  InitDataOutputChecks();

  /* create invalid gfa data */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    /* left border */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Ang = invalidAng;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Dist = invalidDistance;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Ang_Cam = invalidAng;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_ObjId = invalidObjID;

    /* right border */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_Ang = invalidAng;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_Dist = invalidDistance;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_Ang_Cam = invalidAng;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_ObjId = invalidObjID;

    /* lower border */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLower_Ang_Cam = invalidAngCam;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLower_ObjId = invalidObjID;

    /* upper border */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryUpper_Ang_Cam = invalidAngCam;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryUpper_ObjId = invalidObjID;

    /* closest object */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ClosestObj_Dist = invalidDistance;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ClosestObj_Ang = invalidAng;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ClosestObj_ObjId = invalidObjID;

    /* min light */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].MinLight_Dist = invalidDistance;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].MinLight_Ang = invalidAng;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].MinLight_ObjId = invalidObjID;

    /* ttb */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left = invalidTTB;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right = invalidTTB;

    /* existence prob */
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ExistenceProb = invalidExProb;
  }

  /* Add INF and NAN as well */
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Ang      = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Dist     = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Ang_Cam  = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryRight_Ang     = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryRight_Dist    = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryRight_Ang_Cam = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLower_Ang_Cam = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryUpper_Ang_Cam = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ClosestObj_Dist    = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ClosestObj_Ang     = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].MinLight_Dist      = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].MinLight_Ang       = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Left          = f_INF;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Right         = f_INF;

  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLeft_Ang      = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLeft_Dist     = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLeft_Ang_Cam  = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryRight_Ang     = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryRight_Dist    = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryRight_Ang_Cam = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLower_Ang_Cam = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryUpper_Ang_Cam = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ClosestObj_Dist    = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ClosestObj_Ang     = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].MinLight_Dist      = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].MinLight_Ang       = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ttb18Left          = f_NAN;
  ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ttb18Right         = f_NAN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    /* left border */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Ang, CML_Deg2Rad(25.0f), "%.6f", "BndryLeft_Ang was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Dist, 655.35f,  "%.6f","BndryLeft_Dist was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DIST), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Ang_Cam, CML_Deg2Rad(25.0f), "%.6f", "BndryLeft_Ang_Cam was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG_CAM), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID), b_TRUE, "Error was set for iteration %i", i);

    /* right border */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_Ang, CML_Deg2Rad(25.0f), "%.6f", "BndryRight_Ang was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_Dist, 655.35f,  "%.6f","BndryRight_Dist was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_DIST), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryRight_Ang_Cam, CML_Deg2Rad(25.0f), "%.6f", "BndryRight_Ang_Cam was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG_CAM), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_OBJID), b_TRUE, "Error was set for iteration %i", i);

    /* Lower border */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLower_Ang_Cam, CML_Deg2Rad(5.0f),  "%.6f","BndryLower_Ang_Cam was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_ANG_CAM), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_OBJID), b_TRUE, "Error was set for iteration %i", i);

    /* Upper border */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryUpper_Ang_Cam, CML_Deg2Rad(5.0f), "%.6f", "BndryUpper_Ang_Cam was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_ANG_CAM), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_OBJID), b_TRUE, "Error was set for iteration %i", i);

    /* closest object */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ClosestObj_Dist, 655.35f, "%.6f", "ClosestObj_Dist was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_DIST), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ClosestObj_Ang, CML_Deg2Rad(20.0f), "%.6f", "ClosestObj_Ang was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_ANG), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_OBJID), b_TRUE, "Error was set for iteration %i", i);

    /* min light */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].MinLight_Dist, 655.35f, "%.6f", "MinLight_Dist was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_DIST), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].MinLight_Ang, CML_Deg2Rad(20.0f), "%.6f", "MinLight_Ang was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_ANG), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_OBJID), b_TRUE, "Error was set for iteration %i", i);

    /* ttb */
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left, 10.0f, "%.6f", "ttb18Left was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT), b_TRUE, "Warning was set for iteration %i", i);
    COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right, 10.0f, "%.6f", "ttb18Left was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18RIGHT), b_TRUE, "Warning was set for iteration %i", i);

    /* existence prob */
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ExistenceProb, 100u, "ExistenceProb was set to maximum value for iteration %i", i);
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_EXISTENCEPROB), b_TRUE, "Warning was set for iteration %i", i);
  }

  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->sSigHeader.eSigStatus, AL_SIG_STATE_INVALID, "sig status is set to AL_SIG_STATE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetError(HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL), b_TRUE, "Error was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_043(OutputChecks_043, "Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = RTE_HLAF_OBJSTA_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_UNKNOWN, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_NO_OBJ. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_044(OutputChecks_044, "Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_NO_OBJ")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = RTE_HLAF_OBJSTA_NO_OBJ;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_NO_OBJ, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_NO_OBJ");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_UNKNOWN_OBJ. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_045(OutputChecks_045, "Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_UNKNOWN_OBJ")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_PREC_OBJ. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_046(OutputChecks_046, "Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_PREC_OBJ")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_PREC_OBJ, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_PREC_OBJ");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_ONC_OBJ. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_047(OutputChecks_047, "Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_ONC_OBJ")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = RTE_HLAF_OBJSTA_ONC_OBJ;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_ONC_OBJ, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_ONC_OBJ");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_INVALID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_048(OutputChecks_048, "Test headlight control matrix gfa data. Set BndryLeft_Status to RTE_HLAF_OBJSTA_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = RTE_HLAF_OBJSTA_INVALID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_INVALID, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_INVALID");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_Status to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_Status is set to RTE_HLAF_OBJSTA_UNKNOWN. Warnings is set. \n */
TEST_OutputChecks_049(OutputChecks_049, "Test headlight control matrix gfa data. Set BndryLeft_Status to an invalid value")
{
  uint8 i = 0;
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status = invalidValue;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_Status, RTE_HLAF_OBJSTA_UNKNOWN, "BndryLeft_Status is set to RTE_HLAF_OBJSTA_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_TRUE, "Warning was set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState stays the same. No Warnings is set. \n */
TEST_OutputChecks_050(OutputChecks_050, "Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_OBJSTA_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState = RTE_HLAF_DISTSTATE_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState, RTE_HLAF_DISTSTATE_UNKNOWN, "BndryLeft_DistState is set to RTE_HLAF_DISTSTATE_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_SINGLELIGHT. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState stays the same. No Warnings is set. \n */
TEST_OutputChecks_051(OutputChecks_051, "Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_SINGLELIGHT")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState = RTE_HLAF_DISTSTATE_SINGLELIGHT;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState, RTE_HLAF_DISTSTATE_SINGLELIGHT, "BndryLeft_DistState is set to RTE_HLAF_DISTSTATE_SINGLELIGHT");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_PAIRLIGHT. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState stays the same. No Warnings is set. \n */
TEST_OutputChecks_052(OutputChecks_052, "Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_PAIRLIGHT")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState = RTE_HLAF_DISTSTATE_PAIRLIGHT;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState, RTE_HLAF_DISTSTATE_PAIRLIGHT, "BndryLeft_DistState is set to RTE_HLAF_DISTSTATE_PAIRLIGHT");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistState_ShouldStayAsPairlightWide(HLA_OutputChecks_BndryLeftDistState_ShouldStayAsPairlightWide, "Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState = RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState, RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE, "BndryLeft_DistState is set to RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE), b_FALSE, "Warning was not set");
  }
}


/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_INVALID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState stays the same. No Warnings is set. \n */
TEST_OutputChecks_053(OutputChecks_053, "Test headlight control matrix gfa data. Set BndryLeft_DistState to RTE_HLAF_DISTSTATE_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState = RTE_HLAF_DISTSTATE_INVALID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState, RTE_HLAF_DISTSTATE_INVALID, "BndryLeft_DistState is set to RTE_HLAF_DISTSTATE_INVALID");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistState to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState is set to RTE_HLAF_OBJSTA_UNKNOWN. Warnings is set. \n */
TEST_OutputChecks_054(OutputChecks_054, "Test headlight control matrix gfa data. Set BndryLeft_DistState to an invalid value")
{
  uint8 i = 0;
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState = invalidValue;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistState, RTE_HLAF_DISTSTATE_UNKNOWN, "BndryLeft_DistState is set to RTE_HLAF_OBJSTA_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE), b_TRUE, "Warning was set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistReliability stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsUnknown(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsUnknown, "Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability = RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN, "BndryLeft_DistReliability is set to RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_LOW. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistReliability stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsLow(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsLow, "Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_LOW")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability = RTE_HLA_DISTANCE_RELIABILITY_LOW;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_LOW, "BndryLeft_DistReliability is set to RTE_HLA_DISTANCE_RELIABILITY_LOW");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_MID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistReliability stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsMid(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsMid, "Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_MID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability = RTE_HLA_DISTANCE_RELIABILITY_MID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_MID, "BndryLeft_DistReliability is set to RTE_HLA_DISTANCE_RELIABILITY_MID");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_HIGH. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistReliability stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsHigh(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsHigh, "Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_HIGH")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability = RTE_HLA_DISTANCE_RELIABILITY_HIGH;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_HIGH, "BndryLeft_DistReliability is set to RTE_HLA_DISTANCE_RELIABILITY_HIGH");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_INVALID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistReliability stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsInvalid(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsInvalid, "Test headlight control matrix gfa data. Set BndryLeft_DistReliability to RTE_HLA_DISTANCE_RELIABILITY_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability = RTE_HLA_DISTANCE_RELIABILITY_INVALID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_INVALID, "BndryLeft_DistReliability is set to RTE_HLA_DISTANCE_RELIABILITY_INVALID");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set BndryLeft_DistReliability to a not defined value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState is set to RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN. Warnings is set. \n */
TEST_HLA_OutputChecks_BndryLeftDistReliability_SetToDefaultValue(HLA_OutputChecks_BndryLeftDistReliability_SetToDefaultValue, "Test headlight control matrix gfa data. Set BndryLeft_DistState to an invalid value")
{
  uint8 i = 0;
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability = invalidValue;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN, "BndryLeft_DistReliability is set to RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY), b_TRUE, "Warning was set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status and ttb18Right_Status stay on the same. No Warnings is set. \n */
TEST_OutputChecks_055(OutputChecks_055, "Test headlight control matrix gfa data. Set ttb18Left_Status to RTE_HLAF_TTBSTA_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = RTE_HLAF_TTBSTA_UNKNOWN;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = RTE_HLAF_TTBSTA_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_UNKNOWN, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_UNKNOWN");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_UNKNOWN, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_NO_OBJ. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status and ttb18Right_Status stay the same. No Warnings is set. \n */
TEST_OutputChecks_056(OutputChecks_056, "Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_NO_OBJ")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = RTE_HLAF_TTBSTA_NO_OBJ;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = RTE_HLAF_TTBSTA_NO_OBJ;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_NO_OBJ, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_NO_OBJ");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_NO_OBJ, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_NO_OBJ");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_DIR_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status and ttb18Right_Status stay the same. No Warnings is set. \n */
TEST_OutputChecks_057(OutputChecks_057, "Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_DIR_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = RTE_HLAF_TTBSTA_DIR_UNKNOWN;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = RTE_HLAF_TTBSTA_DIR_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_DIR_UNKNOWN, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_DIR_UNKNOWN");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_DIR_UNKNOWN, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_DIR_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_DIR_LEFT. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status and ttb18Right_Status stay the same. No Warnings is set. \n */
TEST_OutputChecks_058(OutputChecks_058, "Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_DIR_LEFT")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = RTE_HLAF_TTBSTA_DIR_LEFT;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = RTE_HLAF_TTBSTA_DIR_LEFT;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_DIR_LEFT, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_DIR_LEFT");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_DIR_LEFT, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_DIR_LEFT");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_DIR_RIGHT. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_059(OutputChecks_059, "Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_DIR_RIGHT")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = RTE_HLAF_TTBSTA_DIR_RIGHT;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = RTE_HLAF_TTBSTA_DIR_RIGHT;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_DIR_RIGHT, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_DIR_RIGHT");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_DIR_RIGHT, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_DIR_RIGHT");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_INVALID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status and ttb18Right_Status stay the same. No Warnings is set. \n */
TEST_OutputChecks_060(OutputChecks_060, "Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to RTE_HLAF_TTBSTA_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = RTE_HLAF_TTBSTA_INVALID;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = RTE_HLAF_TTBSTA_INVALID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_INVALID, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_INVALID");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_INVALID, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_INVALID");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to an invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     ttb18Left_Status and ttb18Right_Status are set to RTE_HLAF_TTBSTA_UNKNOWN. No Warnings is set. \n */
TEST_OutputChecks_061(OutputChecks_061, "Test headlight control matrix gfa data. Set ttb18Left_Status and ttb18Right_Status to an invalid value")
{
  uint8 i = 0;
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status = invalidValue;
    ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status = invalidValue;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Left_Status, RTE_HLAF_TTBSTA_UNKNOWN, "ttb18Left_Status is set to RTE_HLAF_TTBSTA_UNKNOWN");
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[i].ttb18Right_Status, RTE_HLAF_TTBSTA_UNKNOWN, "ttb18Right_Status is set to RTE_HLAF_TTBSTA_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS), b_TRUE, "Warning was set");
  }
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set nGFA to 2. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     nGFA stays the same. No Warnings is set. \n */
TEST_OutputChecks_062(OutputChecks_062, "Test headlight control matrix gfa data. Set nGFA to 2")
{
  uint8 validnGFA = 2u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.nGFA = validnGFA;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA, validnGFA, "nGFA is set to 2");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_NGFA), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set nGFA to invalid value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     nGFA is set to zero. Warning is set. \n */
TEST_OutputChecks_063(OutputChecks_063, "Test headlight control matrix gfa data. Set nGFA to invalid value")
{
  uint8 invalidnGFA = RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS + 1u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.nGFA = invalidnGFA;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA, 0u, "nGFA is set to zero");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_NGFA), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFAStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_064(OutputChecks_064, "Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_UNKNOWN, "GFAStatus is set to RTE_HLAF_SIGSTAT_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_INIT. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFAStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_065(OutputChecks_065, "Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_INIT")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_INIT;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_INIT, "GFAStatus is set to RTE_HLAF_SIGSTAT_INIT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_DATA_VALID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFAStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_066(OutputChecks_066, "Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_DATA_VALID")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_DATA_VALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_DATA_VALID, "GFAStatus is set to RTE_HLAF_SIGSTAT_DATA_VALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_DATA_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFAStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_067(OutputChecks_067, "Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_DATA_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_DATA_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_DATA_INVALID, "GFAStatus is set to RTE_HLAF_SIGSTAT_DATA_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFAStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_068(OutputChecks_068, "Test headlight control matrix gfa data. Set GFAStatus to RTE_HLAF_SIGSTAT_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_INVALID, "GFAStatus is set to RTE_HLAF_SIGSTAT_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set GFAStatus to an invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFAStatus is set to RTE_HLAF_SIGSTAT_UNKNOWN. Warnings is set. \n */
TEST_OutputChecks_069(OutputChecks_069, "Test headlight control matrix gfa data. Set GFAStatus to an invalid value")
{
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus, RTE_HLAF_SIGSTAT_UNKNOWN, "GFAStatus is set to RTE_HLAF_SIGSTAT_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_UNKNOWN . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_070(OutputChecks_070, "Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_UNKNOWN, "GFAStatus is set to RTE_HLAF_HB_STATE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_OFF . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_071(OutputChecks_071, "Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_OFF")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_OFF, "GFAStatus is set to RTE_HLAF_HB_STATE_OFF");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_FULL_ON . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_072(OutputChecks_072, "Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_FULL_ON")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_FULL_ON, "GFAStatus is set to RTE_HLAF_HB_STATE_FULL_ON");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_PARTIAL . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_073(OutputChecks_073, "Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_PARTIAL")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = RTE_HLAF_HB_STATE_PARTIAL;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_PARTIAL, "GFAStatus is set to RTE_HLAF_HB_STATE_PARTIAL");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_SPOT . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_074(OutputChecks_074, "Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_SPOT")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = RTE_HLAF_HB_STATE_SPOT;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_SPOT, "GFAStatus is set to RTE_HLAF_HB_STATE_SPOT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_075(OutputChecks_075, "Test headlight control matrix gfa data. Set HighBeamState to RTE_HLAF_HB_STATE_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = RTE_HLAF_HB_STATE_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_INVALID, "GFAStatus is set to RTE_HLAF_HB_STATE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set HighBeamState to an invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     HighBeamState stays the same. No Warnings is set. \n */
TEST_OutputChecks_076(OutputChecks_076, "Test headlight control matrix gfa data. Set HighBeamState to an invalid value")
{
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState, RTE_HLAF_HB_STATE_UNKNOWN, "GFAStatus is set to RTE_HLAF_HB_STATE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE), b_TRUE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Dist to valid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Dist stays the same. No Warnings is set. \n */
TEST_OutputChecks_077(OutputChecks_077, "Test headlight control matrix gfa data. Set LowBeam_Dist to valid value")
{
  float32 validValue = 100.0f;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist = validValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist, validValue, "LowBeam_Dist is set to 100.0f");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_DIST), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Dist to invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Dist is set to 600.0f. Warnings is set. \n */
TEST_OutputChecks_078(OutputChecks_078, "Test headlight control matrix gfa data. Set LowBeam_Dist to invalid value")
{
  float32 invalidValue = 1000.0f;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist, 600.0f, "LowBeam_Dist is set to 600.0f");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_DIST), b_TRUE, "Warning was set");

  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist = f_INF;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist, 600.0f, "LowBeam_Dist is set to 600.0f");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_DIST), b_TRUE, "Warning was set");

  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist = f_NAN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist, 600.0f, "LowBeam_Dist is set to 600.0f");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_DIST), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Ang to valid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Ang stays the same. No Warnings is set. \n */
TEST_OutputChecks_079(OutputChecks_079, "Test headlight control matrix gfa data. Set LowBeam_Ang to valid value")
{
  float32 validValue = CML_Deg2Rad(10.0f);
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang = validValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang, validValue, "LowBeam_Ang is set to 10 deg");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_ANG), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Ang to invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Ang is set to 20 deg. Warnings is set. \n */
TEST_OutputChecks_080(OutputChecks_080, "Test headlight control matrix gfa data. Set LowBeam_Ang to invalid value")
{
  float32 invalidValue = CML_Deg2Rad(22.0f);
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang, CML_Deg2Rad(20.0f), "%.6f", "LowBeam_Ang is set to 20 deg");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_ANG), b_TRUE, "Warning was set");

  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang = f_INF;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang, CML_Deg2Rad(20.0f), "%.6f", "LowBeam_Ang is set to 20 deg");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_ANG), b_TRUE, "Warning was set");

  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang = f_NAN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang, CML_Deg2Rad(20.0f), "%.6f", "LowBeam_Ang is set to 20 deg");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_ANG), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_UNKNOWN . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_081(OutputChecks_081, "Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_UNKNOWN, "LowBeam_Status is set to RTE_HLAF_OBJSTA_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_NO_OBJ . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_082(OutputChecks_082, "Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_NO_OBJ")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_NO_OBJ;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_NO_OBJ, "LowBeam_Status is set to RTE_HLAF_OBJSTA_NO_OBJ");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_UNKNOWN_OBJ . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_083(OutputChecks_083, "Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_UNKNOWN_OBJ")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_UNKNOWN_OBJ, "LowBeam_Status is set to RTE_HLAF_OBJSTA_UNKNOWN_OBJ");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_PREC_OBJ . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_084(OutputChecks_084, "Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_PREC_OBJ")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_PREC_OBJ;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_PREC_OBJ, "LowBeam_Status is set to RTE_HLAF_OBJSTA_PREC_OBJ");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_ONC_OBJ . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_085(OutputChecks_085, "Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_ONC_OBJ")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_ONC_OBJ;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_ONC_OBJ, "LowBeam_Status is set to RTE_HLAF_OBJSTA_ONC_OBJ");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_086(OutputChecks_086, "Test headlight control matrix gfa data. Set LowBeam_Status to RTE_HLAF_OBJSTA_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_INVALID, "LowBeam_Status is set to RTE_HLAF_OBJSTA_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set LowBeam_Status to an invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status is set to RTE_HLAF_OBJSTA_UNKNOWN. Warning is set. \n */
TEST_OutputChecks_087(OutputChecks_087, "Test headlight control matrix gfa data. Set LowBeam_Status to an invalid value")
{
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Status, RTE_HLAF_OBJSTA_UNKNOWN, "LowBeam_Status is set to RTE_HLAF_OBJSTA_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set TurnOffReason to RTE_HLAF_TURNOFFREASON_UNKNOWN . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     LowBeam_Status stays the same. No Warnings is set. \n */
TEST_OutputChecks_088(OutputChecks_088, "Test headlight control matrix gfa data. Set TurnOffReason to RTE_HLAF_TURNOFFREASON_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_UNKNOWN, "TurnOffReason is set to RTE_HLAF_TURNOFFREASON_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_TURNOFFREASON), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control matrix gfa data. Set TurnOffReason to an invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     TurnOffReason is set to RTE_HLAF_TURNOFFREASON_ERROR. Warning is set. \n */
test_HLA_OutputCheck_MatrixTurnOffReason_SetInvalidTurnOffReason_TurnOffReasonErrorAndWarningIsSet(HLA_OutputCheck_MatrixTurnOffReason_SetInvalidTurnOffReason_TurnOffReasonErrorAndWarningIsSet, "Test headlight control matrix gfa data. Set TurnOffReason to an invalid value")
{
  uint32 invalidValue = 3000u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_ERROR, "TurnOffReason is set to RTE_HLAF_TURNOFFREASON_ERROR");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_MATRIX_TURNOFFREASON), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_UNKNOWN . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_090(OutputChecks_090, "Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_TURNOFFREASON_UNKNOWN")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_UNKNOWN, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_AVL . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_091(OutputChecks_091, "Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_AVL")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_AVL;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_AVL");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_LIMITED . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_092(OutputChecks_092, "Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_LIMITED")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_LIMITED;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_LIMITED, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_LIMITED");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_NAVL . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_093(OutputChecks_093, "Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_NAVL")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_NAVL;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_NAVL, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_NAVL");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_ERROR . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_094(OutputChecks_094, "Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_ERROR")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_ERROR;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_ERROR, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_ERROR");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus stays the same. No Warnings is set. \n */
TEST_OutputChecks_095(OutputChecks_095, "Test headlight control dimming data. Set DimmingStatus to RTE_HLAF_DIMM_STATE_INVALID")
{
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_INVALID, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set DimmingStatus to an invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingStatus is set to RTE_HLAF_DIMM_STATE_UNKNOWN. No Warnings is set. \n */
TEST_OutputChecks_096(OutputChecks_096, "Test headlight control dimming data. Set DimmingStatus to an invalid value")
{
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus = invalidValue;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingStatus, RTE_HLAF_DIMM_STATE_UNKNOWN, "DimmingStatus is set to RTE_HLAF_DIMM_STATE_UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_STATE_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingArea stays the same. No Warnings is set. \n */
TEST_OutputChecks_097(OutputChecks_097, "Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i] = RTE_HLAF_DIMM_LEVEL_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_UNKNOWN, "DimmingStatus is set to RTE_HLAF_DIMM_LEVEL_UNKNOWN");
  }
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_NO_REDUCT . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingArea stays the same. No Warnings is set. \n */
TEST_OutputChecks_098(OutputChecks_098, "Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i] = RTE_HLAF_DIMM_LEVEL_NO_REDUCT;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "DimmingStatus is set to RTE_HLAF_DIMM_LEVEL_NO_REDUCT");
  }
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_REDUCT_1 . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingArea stays the same. No Warnings is set. \n */
TEST_OutputChecks_099(OutputChecks_099, "Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_REDUCT_1")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i] = RTE_HLAF_DIMM_LEVEL_REDUCT_1;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "DimmingStatus is set to RTE_HLAF_DIMM_LEVEL_REDUCT_1");
  }
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_REDUCT_2 . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingArea stays the same. No Warnings is set. \n */
TEST_OutputChecks_100(OutputChecks_100, "Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_REDUCT_2")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "DimmingStatus is set to RTE_HLAF_DIMM_LEVEL_REDUCT_2");
  }
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_INVALID . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingArea stays the same. No Warnings is set. \n */
TEST_OutputChecks_101(OutputChecks_101, "Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i] = RTE_HLAF_DIMM_LEVEL_INVALID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_INVALID, "DimmingStatus is set to RTE_HLAF_DIMM_LEVEL_INVALID");
  }
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control dimming data. Set all DimmingArea to an invalid value . \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     DimmingArea is set to RTE_HLAF_DIMM_LEVEL_UNKNOWN. Warnings is set. \n */
TEST_OutputChecks_102(OutputChecks_102, "Test headlight control dimming data. Set all DimmingArea to RTE_HLAF_DIMM_LEVEL_INVALID")
{
  uint8 i = 0;
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i] = invalidValue;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLA_NUM_DIMM_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Dimming.DimmingArea[i], RTE_HLAF_DIMM_LEVEL_UNKNOWN, "DimmingStatus is set to RTE_HLAF_DIMM_LEVEL_UNKNOWN");
  }
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test that eSigStatus is set to invalid. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No Warning was set. SigStatus is still set to invalid. \n */
TEST_OutputChecks_103(OutputChecks_103, "Test that eSigStatus is set to invalid")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set sigStatus of comp state to ok */
  ProPorts.pAlgoCompState->sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pAlgoCompState->sSigHeader.eSigStatus, AL_SIG_STATE_INVALID, "Sig status is still set to invalid");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SIG_STATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control function state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Function state is set to _TEMPORARY_OFF. \n */
TEST_OutputChecks_104(OutputChecks_104, "Test headlight control function state is set to _TEMPORARY_OFF")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set function state to invalid */
  ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus = RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF, "function state stays on _TEMPORARY_OFF");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control function state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Function state is set to _PERMANENT_OFF. \n */
TEST_OutputChecks_105(OutputChecks_105, "Test headlight control function state is set to _PERMANENT_OFF")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set function state to invalid */
  ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus = RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF, "function state stays on _PERMANENT_OFF");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control function state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Function state is set to _RUNNING. \n */
TEST_OutputChecks_106(OutputChecks_106, "Test headlight control function state is set to _RUNNING")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set function state to invalid */
  ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus = RTE_HLAF_FUNCTION_STATUS_RUNNING;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_RUNNING, "function state stays on _RUNNING");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control function state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Function state is set to _INVALID. \n */
TEST_OutputChecks_107(OutputChecks_107, "Test headlight control function state is set to _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set function state to invalid */
  ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus = RTE_HLAF_FUNCTION_STATUS_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_INVALID, "function state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control function state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. Function state is set to _INVALID. \n */
TEST_OutputChecks_108(OutputChecks_108, "Test headlight control function state to an invalid value")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set function state to an invalid value. */
  ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus = RTE_HLAF_FUNCTION_STATUS_INVALID + 1u;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->hlaFunctionStatus, RTE_HLAF_FUNCTION_STATUS_INVALID, "function state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS), b_TRUE, "Warning was set");
}


/** \test
 *  \description
 *     Test headlight control city state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. City state is set to _UNKNOWN. \n */
TEST_OutputChecks_109(OutputChecks_109, "Test headlight control city state is set to _UNKNOWN")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set city state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState, RTE_HLAR_CITY_UNKNOWN, "City state stays on _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control city state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. City state is set to _INVALID. \n */
TEST_OutputChecks_110(OutputChecks_110, "Test headlight control city state is set to _NOT_DTCD")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set city state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_NOT_DTCD;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState, RTE_HLAR_CITY_NOT_DTCD, "City state stays on _NOT_DTCD");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control city state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. City state is set to _NOT_DTCD. \n */
TEST_OutputChecks_111(OutputChecks_111, "Test headlight control city state is set to _DTCD")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set city state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_DTCD;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState, RTE_HLAR_CITY_DTCD, "City state stays on _DTCD");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control city state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. City state is set to _MAYBE. \n */
TEST_OutputChecks_112(OutputChecks_112, "Test headlight control city state is set to _MAYBE")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set city state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_MAYBE;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState, RTE_HLAR_CITY_MAYBE, "City state stays on _MAYBE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control city state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. City state is set to _INVALID. \n */
TEST_OutputChecks_113(OutputChecks_113, "Test headlight control city state is set to _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set city state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState, RTE_HLAR_CITY_INVALID, "City state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control city state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. City state is set to _INVALID. \n */
TEST_OutputChecks_114(OutputChecks_114, "Test invalid headlight control city state.")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set city state to an invalid value */
  ProPorts.pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_INVALID - 1;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState, RTE_HLAR_CITY_UNKNOWN, "City state corrected to _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE), b_TRUE, "Warning was set");
}


/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is set to _INVALID. \n */
TEST_OutputChecks_115(OutputChecks_115, "Test headlight control weather state is set to _UNKNOWN")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_UNKNOWN, "Weather state stays on _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is se_UNKNOWNVALID. \n */
TEST_OutputChecks_116(OutputChecks_116, "Test headlight control weather state is set to _GOOD")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_GOOD;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_GOOD, "Weather state stays on _GOOD");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is set to _BAD. \n */
TEST_OutputChecks_117(OutputChecks_117, "Test headlight control weather state is set to _BAD")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_BAD;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_BAD, "Weather state stays on _BAD");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is set to _LIGHT_FOG. \n */
TEST_OutputChecks_118(OutputChecks_118, "Test headlight control weather state is set to _LIGHT_FOG")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_LIGHT_FOG;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_LIGHT_FOG, "Weather state stays on _LIGHT_FOG");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is set to _MEDIUM_FOG. \n */
TEST_OutputChecks_119(OutputChecks_119, "Test headlight control weather state is set to _MEDIUM_FOG")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_MEDIUM_FOG;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_MEDIUM_FOG, "Weather state stays on _MEDIUM_FOG");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is set to _HEAVY_FOG. \n */
TEST_OutputChecks_120(OutputChecks_120, "Test headlight control weather state is set to _HEAVY_FOG")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_HEAVY_FOG;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_HEAVY_FOG, "Weather state stays on _HEAVY_FOG");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Weather state is set to _INVALID. \n */
TEST_OutputChecks_121(OutputChecks_121, "Test headlight control weather state is set to _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_INVALID, "Weather state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control weather state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. Weather state is set to _INVALID. \n */
TEST_OutputChecks_122(OutputChecks_122, "Test invalid headlight control weather state")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set weather state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.WeatherState = RTE_HLAR_WEATHER_INVALID - 1;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState, RTE_HLAR_WEATHER_UNKNOWN, "Weather state corrected to _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control tunnel state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Tunnel state is set to _UNKNOWN. \n */
TEST_OutputChecks_123(OutputChecks_123, "Test headlight control tunnel state is set to _UNKNOWN")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set tunnel state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState, RTE_HLAR_TUNNEL_UNKNOWN, "Tunnel state stays on _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control tunnel state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Tunnel state is set to _NOT_DTCD. \n */
TEST_OutputChecks_124(OutputChecks_124, "Test headlight control tunnel state is set to _NOT_DTCD")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set tunnel state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_NOT_DTCD;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState, RTE_HLAR_TUNNEL_NOT_DTCD, "Tunnel state stays on _NOT_DTCD");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control tunnel state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Tunnel state is set to _UPFRONT. \n */
TEST_OutputChecks_125(OutputChecks_125, "Test headlight control tunnel state is set to _UPFRONT")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set tunnel state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_UPFRONT;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState, RTE_HLAR_TUNNEL_UPFRONT, "Tunnel state stays on _UPFRONT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control tunnel state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Tunnel state is set to _INSIDE. \n */
TEST_OutputChecks_126(OutputChecks_126, "Test headlight control tunnel state is set to _INSIDE")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set tunnel state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_INSIDE;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState, RTE_HLAR_TUNNEL_INSIDE, "Tunnel state stays on _INSIDE");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control tunnel state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Tunnel state is set to _INVALID. \n */
TEST_OutputChecks_127(OutputChecks_127, "Test headlight control tunnel state is set to _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set tunnel state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState, RTE_HLAR_TUNNEL_INVALID, "Tunnel state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control tunnel state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     Warning was set. Tunnel state is set to _UNKNOWN. \n */
TEST_OutputChecks_128(OutputChecks_128, "Test invalid headlight control tunnel state.")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set tunnel state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_INVALID - 1;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState, RTE_HLAR_TUNNEL_UNKNOWN, "Tunnel state stays on _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test headlight control motorway state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Motorway state is set to _INVALID. \n */
TEST_OutputChecks_129(OutputChecks_129, "Test headlight control motorway state is set to _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set motorway state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState, RTE_HLAF_MTWY_INVALID, "Motorway state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE), b_FALSE, "Warning was not set");
}


/** \test
 *  \description
 *     Test headlight control motorway state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Motorway state is set to _COUNTRY. \n */
TEST_OutputChecks_130(OutputChecks_130, "Test headlight control motorway state is set to _COUNTRY")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set motorway state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_COUNTRY;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState, RTE_HLAF_MTWY_COUNTRY, "Motorway state stays on _COUNTRY");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE), b_FALSE, "Warning was not set");
}


/** \test
 *  \description
 *     Test headlight control motorway state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Motorway state is set to _MOTORWAY. \n */
TEST_OutputChecks_131(OutputChecks_131, "Test headlight control motorway state is set to _MOTORWAY")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set motorway state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_MOTORWAY;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState, RTE_HLAF_MTWY_MOTORWAY, "Motorway state stays on _MOTORWAY");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE), b_FALSE, "Warning was not set");
}


/** \test
 *  \description
 *     Test headlight control motorway state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Motorway state is set to _INVALID. \n */
TEST_OutputChecks_132(OutputChecks_132, "Test headlight control motorway state is set to _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set motorway state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState, RTE_HLAF_MTWY_INVALID, "Motorway state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE), b_FALSE, "Warning was not set");
}


/** \test
 *  \description
 *     Test headlight control motorway state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Motorway state is set to an invalid value. \n */
TEST_OutputChecks_133(OutputChecks_133, "Test invalid headlight control motorway state")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set motorway state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_INVALID - 1;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState, RTE_HLAF_MTWY_UNKNOWN, "Motorway state stays on  _UNKNWOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE), b_TRUE, "Warning was set");
}


/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _UNKNOWN. \n */
TEST_OutputChecks_134(OutputChecks_134, "Test headlight control brightness state is set to _UNKNOWN")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_UNKNOWN;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_UNKNOWN, "Brightness state stays on _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _DAY. \n */
TEST_OutputChecks_135(OutputChecks_135, "Test headlight control brightness state is set to _DAY")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_DAY;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_DAY, "Motorway state stays on _DAY");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _DAY. \n */
TEST_OutputChecks_136(OutputChecks_136, "Test headlight control brightness state is set to _TWLGT_1")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_TWLGT_1;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_TWLGT_1, "Brightness state stays on _TWLGT_1");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _TWLGT_2. \n */
TEST_OutputChecks_137(OutputChecks_137, "Test headlight control brightness state is set to _TWLGT_2")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_TWLGT_2;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_TWLGT_2, "Brightness state stays on _TWLGT_2");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _TWLGT_3. \n */
TEST_OutputChecks_138(OutputChecks_138, "Test headlight control brightness state is set to _TWLGT_3")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_TWLGT_3;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_TWLGT_3, "Brightness state stays on _TWLGT_3");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _NIGHT. \n */
TEST_OutputChecks_139(OutputChecks_139, "Test headlight control brightness state is set to _NIGHT")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_NIGHT;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_NIGHT, "Brightness state stays on _NIGHT");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_FALSE, "Warning was not set");
}


/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to _INVALID. \n */
TEST_OutputChecks_140(OutputChecks_140, "Test headlight control brightness state an _INVALID")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_INVALID;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_INVALID, "Motorway state stays on _INVALID");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_FALSE, "Warning was not set");
}

/** \test
 *  \description
 *     Test headlight control brightness state. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     No warning was set. Brightness state is set to an invalid value. \n */
TEST_OutputChecks_141(OutputChecks_141, "Test invalid headlight control brightness state")
{
  /* Initialize data */
  InitDataOutputChecks();

  /* Set brightness state to invalid */
  ProPorts.pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_INVALID - 1;

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_UNKNOWN, "Brightness state corrected to _UNKNOWN");
  COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE), b_TRUE, "Warning was set");
}

/** \test
 *  \description
 *     Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_UNKNOWN. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     SceneInfo stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsUnknown(HLA_OutputChecks_SceneInfo_ShouldStayAsUnknown, "Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_UNKNOWN")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Common.SceneInfo = RTE_HLA_SCENEINFO_UNKNOWN;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "SceneInfo is set to RTE_HLA_SCENEINFO_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_ONCOMING_PASSING. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     SceneInfo stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsOncomingPassing(HLA_OutputChecks_SceneInfo_ShouldStayAsOncomingPassing, "Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_ONCOMING_PASSING")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Common.SceneInfo = RTE_HLA_SCENEINFO_ONCOMING_PASSING;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SceneInfo, RTE_HLA_SCENEINFO_ONCOMING_PASSING, "SceneInfo is set to RTE_HLA_SCENEINFO_ONCOMING_PASSING");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     SceneInfo stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsPrecedingOvertaking(HLA_OutputChecks_SceneInfo_ShouldStayAsPrecedingOvertaking, "Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Common.SceneInfo = RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SceneInfo, RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING, "SceneInfo is set to RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_INVALID. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     SceneInfo stays the same. No Warnings is set. \n */
TEST_HLA_OutputChecks_SceneInfo_ShouldStayAsInvalid(HLA_OutputChecks_SceneInfo_ShouldStayAsInvalid, "Test whether SceneInfo is set  to RTE_HLA_SCENEINFO_INVALID")
{
  uint8 i = 0;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Common.SceneInfo = RTE_HLA_SCENEINFO_INVALID;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SceneInfo, RTE_HLA_SCENEINFO_INVALID, "SceneInfo is set to RTE_HLA_SCENEINFO_INVALID");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO), b_FALSE, "Warning was not set");
  }
}

/** \test
 *  \description
 *     Test whether SceneInfo is set  to a not defined value. \n
 *     calls function HLA_OutputChecks() \n
 *  \precondition
 *     None \n
 *  \result
 *     BndryLeft_DistState is set to RTE_HLA_SCENEINFO_UNKNOWN. Warnings is set. \n */
TEST_HLA_OutputChecks_SceneInfo_SetToDefaultValue(HLA_OutputChecks_SceneInfo_SetToDefaultValue, "Test headlight control matrix gfa data. Set BndryLeft_DistState to an invalid value")
{
  uint8 i = 0;
  uint8 invalidValue = 123u;
  /* initialize data */
  InitDataOutputChecks();

  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    ProPorts.pHlaf_HeadlightControl->Common.SceneInfo = invalidValue;
  }

  /* call function */
  COU_CALL(HLA_OutputChecks(&ProPorts), "function call");

  /* check outputs */
  for(i = 0; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "SceneInfo is set to RTE_HLA_SCENEINFO_UNKNOWN");
    COU_ASSERT_EQUAL(HLA_ErrorHandling_GetWarning(HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO), b_TRUE, "Warning was set");
  }
}

/** list of all test methods of the related suite. */
cou_test_t hla_OutputChecks[] = {
   COU_ADD_TEST(OutputChecks_001),
   COU_ADD_TEST(OutputChecks_002),
   COU_ADD_TEST(OutputChecks_003),
   COU_ADD_TEST(OutputChecks_004),
   COU_ADD_TEST(OutputChecks_005),
   COU_ADD_TEST(OutputChecks_006),
   COU_ADD_TEST(OutputChecks_007),
   COU_ADD_TEST(OutputChecks_008),
   COU_ADD_TEST(OutputChecks_009),
   COU_ADD_TEST(OutputChecks_010),
   COU_ADD_TEST(OutputChecks_011),
   COU_ADD_TEST(OutputChecks_012),
   COU_ADD_TEST(OutputChecks_013),
   COU_ADD_TEST(OutputChecks_014),
   COU_ADD_TEST(OutputChecks_015),
   COU_ADD_TEST(OutputChecks_016),
   COU_ADD_TEST(OutputChecks_017),
   COU_ADD_TEST(OutputChecks_018),
   COU_ADD_TEST(OutputChecks_019),
   COU_ADD_TEST(OutputChecks_020),
   COU_ADD_TEST(OutputChecks_021),
   COU_ADD_TEST(OutputChecks_022),
   COU_ADD_TEST(OutputChecks_023),
   COU_ADD_TEST(OutputChecks_024),
   COU_ADD_TEST(OutputChecks_025),
   COU_ADD_TEST(OutputChecks_026),
   COU_ADD_TEST(OutputChecks_027),
   COU_ADD_TEST(OutputChecks_028),
   COU_ADD_TEST(OutputChecks_029),
   COU_ADD_TEST(OutputChecks_030),
   COU_ADD_TEST(OutputChecks_031),
   COU_ADD_TEST(OutputChecks_032),
   COU_ADD_TEST(OutputChecks_033),
   COU_ADD_TEST(OutputChecks_034),
   COU_ADD_TEST(OutputChecks_035),
   COU_ADD_TEST(OutputChecks_036),
   COU_ADD_TEST(OutputChecks_037),
   COU_ADD_TEST(OutputChecks_038),
   COU_ADD_TEST(OutputChecks_039),
   COU_ADD_TEST(OutputChecks_040),
   COU_ADD_TEST(OutputChecks_041),
   COU_ADD_TEST(OutputChecks_042),
   COU_ADD_TEST(OutputChecks_043),
   COU_ADD_TEST(OutputChecks_044),
   COU_ADD_TEST(OutputChecks_045),
   COU_ADD_TEST(OutputChecks_046),
   COU_ADD_TEST(OutputChecks_047),
   COU_ADD_TEST(OutputChecks_048),
   COU_ADD_TEST(OutputChecks_049),
   COU_ADD_TEST(OutputChecks_050),
   COU_ADD_TEST(OutputChecks_051),
   COU_ADD_TEST(OutputChecks_052),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistState_ShouldStayAsPairlightWide),
   COU_ADD_TEST(OutputChecks_053),
   COU_ADD_TEST(OutputChecks_054),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsUnknown),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsLow),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsMid),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsHigh),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistReliability_ShouldStayAsInvalid),
   COU_ADD_TEST(HLA_OutputChecks_BndryLeftDistReliability_SetToDefaultValue),
   COU_ADD_TEST(OutputChecks_055),
   COU_ADD_TEST(OutputChecks_056),
   COU_ADD_TEST(OutputChecks_057),
   COU_ADD_TEST(OutputChecks_058),
   COU_ADD_TEST(OutputChecks_059),
   COU_ADD_TEST(OutputChecks_060),
   COU_ADD_TEST(OutputChecks_061),
   COU_ADD_TEST(OutputChecks_062),
   COU_ADD_TEST(OutputChecks_063),
   COU_ADD_TEST(OutputChecks_064),
   COU_ADD_TEST(OutputChecks_065),
   COU_ADD_TEST(OutputChecks_066),
   COU_ADD_TEST(OutputChecks_067),
   COU_ADD_TEST(OutputChecks_068),
   COU_ADD_TEST(OutputChecks_069),
   COU_ADD_TEST(OutputChecks_070),
   COU_ADD_TEST(OutputChecks_071),
   COU_ADD_TEST(OutputChecks_072),
   COU_ADD_TEST(OutputChecks_073),
   COU_ADD_TEST(OutputChecks_074),
   COU_ADD_TEST(OutputChecks_075),
   COU_ADD_TEST(OutputChecks_076),
   COU_ADD_TEST(OutputChecks_077),
   COU_ADD_TEST(OutputChecks_078),
   COU_ADD_TEST(OutputChecks_079),
   COU_ADD_TEST(OutputChecks_080),
   COU_ADD_TEST(OutputChecks_081),
   COU_ADD_TEST(OutputChecks_082),
   COU_ADD_TEST(OutputChecks_083),
   COU_ADD_TEST(OutputChecks_084),
   COU_ADD_TEST(OutputChecks_085),
   COU_ADD_TEST(OutputChecks_086),
   COU_ADD_TEST(OutputChecks_087),
   COU_ADD_TEST(OutputChecks_088),
   COU_ADD_TEST(HLA_OutputCheck_MatrixTurnOffReason_SetInvalidTurnOffReason_TurnOffReasonErrorAndWarningIsSet),
   COU_ADD_TEST(OutputChecks_090),
   COU_ADD_TEST(OutputChecks_091),
   COU_ADD_TEST(OutputChecks_092),
   COU_ADD_TEST(OutputChecks_093),
   COU_ADD_TEST(OutputChecks_094),
   COU_ADD_TEST(OutputChecks_095),
   COU_ADD_TEST(OutputChecks_096),
   COU_ADD_TEST(OutputChecks_097),
   COU_ADD_TEST(OutputChecks_098),
   COU_ADD_TEST(OutputChecks_099),
   COU_ADD_TEST(OutputChecks_100),
   COU_ADD_TEST(OutputChecks_101),
   COU_ADD_TEST(OutputChecks_102),
   COU_ADD_TEST(OutputChecks_103),
   COU_ADD_TEST(OutputChecks_104),
   COU_ADD_TEST(OutputChecks_105),
   COU_ADD_TEST(OutputChecks_106),
   COU_ADD_TEST(OutputChecks_107),
   COU_ADD_TEST(OutputChecks_108),
   COU_ADD_TEST(OutputChecks_109),
   COU_ADD_TEST(OutputChecks_110),
   COU_ADD_TEST(OutputChecks_111),
   COU_ADD_TEST(OutputChecks_112),
   COU_ADD_TEST(OutputChecks_113),
   COU_ADD_TEST(OutputChecks_114),
   COU_ADD_TEST(OutputChecks_115),
   COU_ADD_TEST(OutputChecks_116),
   COU_ADD_TEST(OutputChecks_117),
   COU_ADD_TEST(OutputChecks_118),
   COU_ADD_TEST(OutputChecks_119),
   COU_ADD_TEST(OutputChecks_120),
   COU_ADD_TEST(OutputChecks_121),
   COU_ADD_TEST(OutputChecks_122),
   COU_ADD_TEST(OutputChecks_123),
   COU_ADD_TEST(OutputChecks_124),
   COU_ADD_TEST(OutputChecks_125),
   COU_ADD_TEST(OutputChecks_126),
   COU_ADD_TEST(OutputChecks_127),
   COU_ADD_TEST(OutputChecks_128),
   COU_ADD_TEST(OutputChecks_129),
   COU_ADD_TEST(OutputChecks_130),
   COU_ADD_TEST(OutputChecks_131),
   COU_ADD_TEST(OutputChecks_132),
   COU_ADD_TEST(OutputChecks_133),
   COU_ADD_TEST(OutputChecks_134),
   COU_ADD_TEST(OutputChecks_135),
   COU_ADD_TEST(OutputChecks_136),
   COU_ADD_TEST(OutputChecks_137),
   COU_ADD_TEST(OutputChecks_138),
   COU_ADD_TEST(OutputChecks_139),
   COU_ADD_TEST(OutputChecks_140),
   COU_ADD_TEST(OutputChecks_141),
   COU_ADD_TEST(HLA_OutputChecks_SceneInfo_ShouldStayAsUnknown),
   COU_ADD_TEST(HLA_OutputChecks_SceneInfo_ShouldStayAsOncomingPassing),
   COU_ADD_TEST(HLA_OutputChecks_SceneInfo_ShouldStayAsPrecedingOvertaking),
   COU_ADD_TEST(HLA_OutputChecks_SceneInfo_ShouldStayAsInvalid),
   COU_ADD_TEST(HLA_OutputChecks_SceneInfo_SetToDefaultValue),


   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(OutputChecksInit, "Initialize output checks")
{
  /* Nothing to do here */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_OutputChecks, hla_OutputChecks, OutputChecksInit, "Module test for hla_output_checks.c"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
