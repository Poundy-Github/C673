/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* include for hlaf_matrix */
#include "hlaf_matrix.h"

#include "../../mockup_services.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_HLAFMatrix_Init_001 COU_TEST
#define TEST_HLAFMatrix_Main_001 COU_TEST
#define TEST_HLAFMatrix_InitOutput_001 COU_TEST
#define TEST_HLAFMatrix_InitObjectList_001 COU_TEST
#define TEST_HLAFMatrix_SetOutput_001 COU_TEST
#define TEST_HLAFMatrix_SetOutput_002 COU_TEST
#define test_HLAFMatrix_SetTurnOffReason_AllInternalReasonsAreSet_ReasonsAreCorrectlyMapped COU_TEST
#define test_HLAFMatrix_SetTurnOffReason_NoInternalTurnOffIsSet_NoTurnOffReasonsIsSet COU_TEST
#define test_HLAFMatrix_SetTurnOffReason_HBIsOffNoOtherTurnOffReasonSet_DelayTurnOffReasonIsSet COU_TEST
#define test_HLAFMatrix_SetTurnOffReason_InternalRadarObjectIsSet_TurnOffReasonIsCorrectlyMapped COU_TEST
#define test_HLAFMatrix_SetTurnOffReason_InternalMaxSpeedAndEMOBjectTurnOffIsSet_TurnOffReasonsAreCorrectlyMapped COU_TEST
#define TEST_HLAFMatrix_SetLowBeamDist_001 COU_TEST

/* mockup variables */
extern unsigned int HLAFMatrixGFA_Init__numOfCalls;
extern unsigned int HLAFMatrixGFA_Main__numOfCalls;

void InitData(void);
void SetDefaultParameter(void);

HLAFData_t                 FData;
t_MatrixParameters         HlafMatrixParameter;
HLAFMatrixOut_t            MatrixOut;
uint8                      calibrationConfidence;
RTE_HLAF_HighBeamState     HighBeamStateNext;
RTE_HLAF_Matrix_t          MatrixNext;

/* Init function which memsets all of the input data and links the data buffer to the corresponding pointers */
void InitData(void)
{
  Mockup_InitGlobVars();

  memset(&FData, 0, sizeof(FData));
  memset(&HlafMatrixParameter, 0, sizeof(HlafMatrixParameter));
  memset(&MatrixOut, 0, sizeof(MatrixOut));
  memset(&calibrationConfidence, 0, sizeof(calibrationConfidence));
  memset(&HighBeamStateNext, 0, sizeof(HighBeamStateNext));

  LsdLightObjectList.numObjects = 0;

  HLAFMatrixGFA_Init__numOfCalls = 0;
  HLAFMatrixGFA_Main__numOfCalls = 0;

  SetDefaultParameter();
}

/* Function to set default parameters */
void SetDefaultParameter(void)
{
  HlafMatrixParameter.Output.LowBeam_Dist_Max = 600.0f;
  HlafMatrixParameter.Output.LowBeam_Ang_Default = 0.0f;
  HlafMatrixParameter.Output.LowBeam_Dist_Max = 600.0f;
  HlafMatrixParameter.Output.LowBeam_Dist_Default = 65.0f;
}

/** \test
 *  \description
 *     Check that object data of hlaf matrix struct gets initialized. \n
 *     calls function HLAFMatrix_Init() \n
 *  \precondition
 *     None \n
 *  \result
 *     ObjNext, LiObjID, LiObjIDPair, GFA, EMObjID are set to UI8_T_MAX. \n */
TEST_HLAFMatrix_Init_001(HLAFMatrix_Init_001, "Test that initialization of object data is done")
{
  uint8 i = 0;

  /* Initialize Data */
  InitData();

  /* call function */
  COU_CALL(HLAFMatrix_Init(&FData), "function call");

  /* loop over all objects */
  for(i=0; i<LSD_LIGHT_OBJECT_LIST_LENGTH; i++)
  {
    /* check ouput */
    COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[i].ObjNext, UI8_T_MAX, "ObjNext is set to max value");
    COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[i].LiObjID, UI8_T_MAX, "LiObjID is set to max value");
    COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[i].LiObjIDPair, UI8_T_MAX, "LiObjIDPair is set to max value");
    COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[i].GFA, UI8_T_MAX, "GFA is set to max value");
    COU_ASSERT_EQUAL(FData.hlafMatrixData.Object[i].EMObjID, UI8_T_MAX, "EMObjID is set to max value");
  }
}

/** \test
 *  \description
 *     Test that the GFA data is reset in case day mode was detected. In night mode Matrix GFA main shall be called. In day mode with no GFA data nothing shall be done (since GFA data already is initialized). \n
 *     calls function HLAFMatrix_Main() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct functions were called. \n */
TEST_HLAFMatrix_Main_001(HLAFMatrix_Main_001, "Test correct functions are called, in case of day/night mode with and without GFA data")
{
  /* --- Init of matrix gfa data is called --- */
  /* Initialize Data */
  InitData();

  /* day is detected */
  FData.DecisionOut.eBrightnessState = RTE_HLAR_BRT_DAY;
  /* GFA data still exists */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 1;

  /* call function */
  COU_CALL(HLAFMatrix_Main(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLAFMatrixGFA_Init__numOfCalls, 1, "HLAFMatrixGFA_Init() function was called");

  /* --- day mode and no GFA data -> nothing to do --- */
  /* Initialize Data */
  InitData();

  /* day is detected */
  FData.DecisionOut.eBrightnessState = RTE_HLAR_BRT_DAY;
  /* GFA data still exists */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 0;

  /* call function */
  COU_CALL(HLAFMatrix_Main(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  /* else case nothing to check here */

  /* --- Night mode -> call matrix GFA main --- */
  /* Initialize Data */
  InitData();

  /* day is detected */
  FData.DecisionOut.eBrightnessState = RTE_HLAR_BRT_NIGHT;
  /* GFA data still exists */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 0;

  /* call function */
  COU_CALL(HLAFMatrix_Main(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLAFMatrixGFA_Main__numOfCalls, 1, "HLAFMatrixGFA_Main() function was called");

  /* --- Twilight mode & Calculation in Twilight is set -> call matrix GFA main --- */
  /* Initialize Data */
  InitData();

  /* twilight 3 is detected */
  FData.DecisionOut.eBrightnessState = RTE_HLAR_BRT_TWLGT_3;
  /* GFA data still exists */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 0;
  /* Calculation in twilight activated by coding */
  HlafMatrixParameter.Cfg.bGFACalculationInTwilight = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_Main(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLAFMatrixGFA_Main__numOfCalls, 1, "HLAFMatrixGFA_Main() function was called");

  /* --- Twilight 2 mode & Calculation in Twilight is set -> call matrix GFA main --- */
  /* Initialize Data */
  InitData();

  /* twilight 3 is detected */
  FData.DecisionOut.eBrightnessState = RTE_HLAR_BRT_TWLGT_2;
  /* GFA data still exists */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 4;
  /* Calculation in twilight activated by coding */
  HlafMatrixParameter.Cfg.bGFACalculationInTwilight = b_TRUE;

  /* call function */
  COU_CALL(HLAFMatrix_Main(&ReqPorts, &HlafMatrixParameter, &FData), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(HLAFMatrixGFA_Init__numOfCalls, 1, "HLAFMatrixGFA_Init() function was called");
}

/** \test
 *  \description
 *     Test that matrix out struct is set to zero. \n
 *     calls function HLAFMatrix_InitOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Matrix out struct is set to zero. \n */
TEST_HLAFMatrix_InitOutput_001(HLAFMatrix_InitOutput_001, "Test matrix out struct is correctly initialized")
{
  HLAFMatrixOut_t MatrixOutCompare;

  /* set struct to zero */
  memset(&MatrixOutCompare, 0, sizeof(&MatrixOutCompare));

  /* call function */
  COU_CALL(HLAFMatrix_InitOutput(&MatrixOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(memcmp(&MatrixOut, &MatrixOutCompare, sizeof(&MatrixOut)), 0, "matrix out struct was set to zero");
}

/** \test
 *  \description
 *     Test that every object is correctly initialized. \n
 *     calls function HLAFMatrix_InitObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     Every object is correctly initialized \n */
TEST_HLAFMatrix_InitObjectList_001(HLAFMatrix_InitObjectList_001, "Test that every object is correctly initialized")
{
  HLAObjectDataInt_t Obj;
  uint8 i = 0;

  /* set expected output data for object */
  memset(&Obj, 0, sizeof(&Obj));
  Obj.ObjNext     = UI8_T_MAX;
  Obj.LiObjID     = UI8_T_MAX;
  Obj.LiObjIDPair = UI8_T_MAX;
  Obj.GFA         = UI8_T_MAX;
  Obj.EMObjID     = UI8_T_MAX;

  /* Initialize Data */
  InitData();

  /* call function */
  COU_CALL(HLAFMatrix_InitObjectList(&FData.hlafMatrixData.Object[0]), "function call");

  /* check output */
  for(i=0; i<LSD_LIGHT_OBJECT_LIST_LENGTH; i++)
  {
    COU_ASSERT_EQUAL(memcmp(&FData.hlafMatrixData.Object[i], &Obj, sizeof(&Obj)), 0, "object data is correctly set");
  }
}

/** \test
 *  \description
 *     Test that GFA status is set depending on calibration and detected blockage. If the calibration confidence is not high enough or turn off reason blockage is set, the GFA status shall be set to invalid. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct GFA status is set \n */
TEST_HLAFMatrix_SetOutput_001(HLAFMatrix_SetOutput_001, "Test that GFA status is correctly set")
{
  /* --- calibration confidence is enough and no turn off reason --- */
  /* Initialize Data */
  InitData();

  calibrationConfidence = 100;
  MatrixOut.Matrix.TurnOffReason = 0;

  /* call function */
  COU_CALL(HLAFMatrix_SetOutput(&FData.hlafMatrixData, calibrationConfidence, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(MatrixOut.Matrix.GFAStatus, RTE_HLAF_SIGSTAT_DATA_VALID, "GFA status is set to valid");

  /* --- Calibration confidence not sufficient --- */
  /* Initialize Data */
  InitData();

  calibrationConfidence = 90;
  MatrixOut.Matrix.TurnOffReason = 0;

  /* call function */
  COU_CALL(HLAFMatrix_SetOutput(&FData.hlafMatrixData, calibrationConfidence, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(MatrixOut.Matrix.GFAStatus, RTE_HLAF_SIGSTAT_DATA_INVALID, "GFA status is set to valid");

  /* --- Turn off reason blockage is set --- */
  /* Initialize Data */
  InitData();

  calibrationConfidence = 100;
  MatrixOut.Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_BLOCKAGE;

  /* call function */
  COU_CALL(HLAFMatrix_SetOutput(&FData.hlafMatrixData, calibrationConfidence, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(MatrixOut.Matrix.GFAStatus, RTE_HLAF_SIGSTAT_DATA_INVALID, "GFA status is set to valid");
}

/** \test
 *  \description
 *     Test that GFA data is correctly copied to output. Data should only be copied if highbeam state is set to off and at least one GFA exists. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     GFA data is correctly copied to output \n */
TEST_HLAFMatrix_SetOutput_002(HLAFMatrix_SetOutput_002, "Test that GFA data is correctly copied to output")
{
  HLAFMatrixGFA_t         emptyGFA;
  memset(&emptyGFA, 0, sizeof(&emptyGFA));

  /* --- high beam off and GFA data exists -> copy GFAs to output */
  /* Initialize Data */
  InitData();

  /* copy GFAs */
  MatrixOut.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;
  FData.hlafMatrixData.Matrix.GFA.nGFA = 1;

  /* Set random GFA data */
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Ang = 0.1f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Ang = 0.2f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.ExistenceProb = 100;

  /* call function */
  COU_CALL(HLAFMatrix_SetOutput(&FData.hlafMatrixData, calibrationConfidence, &MatrixOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(memcmp(&MatrixOut.Matrix.GFA, &FData.hlafMatrixData.Matrix.GFA, sizeof(&MatrixOut.Matrix.GFA)), 0, "Matrix data was correctly set");

  /* --- nGFA is set to zero, data should not be copied to output struct --- */
  /* Initialize Data */
  InitData();

  /* copy GFAs */
  MatrixOut.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;
  FData.hlafMatrixData.Matrix.GFA.nGFA = 0;

  /* Set random GFA data */
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Ang = 0.1f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Ang = 0.2f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.ExistenceProb = 100;

  /* call function */
  COU_CALL(HLAFMatrix_SetOutput(&FData.hlafMatrixData, calibrationConfidence, &MatrixOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(memcmp(&MatrixOut.Matrix.GFA, &emptyGFA, sizeof(&MatrixOut.Matrix.GFA)), 0, "Matrix data was not set");

  /* --- highbeam is off, data should not be copied to output struct --- */
  /* Initialize Data */
  InitData();

  /* copy GFAs */
  MatrixOut.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  FData.hlafMatrixData.Matrix.GFA.nGFA = 1;

  /* Set random GFA data */
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Ang = 0.1f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Ang = 0.2f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.ExistenceProb = 100;

  /* call function */
  COU_CALL(HLAFMatrix_SetOutput(&FData.hlafMatrixData, calibrationConfidence, &MatrixOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(memcmp(&MatrixOut.Matrix.GFA, &emptyGFA, sizeof(&MatrixOut.Matrix.GFA)), 0, "Matrix data was not set");
}

/** \test
 *  \description
 *     Test that turn off reasons are correctly mapped to ouput. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct turn off reason is set \n */
test_HLAFMatrix_SetTurnOffReason_AllInternalReasonsAreSet_ReasonsAreCorrectlyMapped(HLAFMatrix_SetTurnOffReason_AllInternalReasonsAreSet_ReasonsAreCorrectlyMapped, "Test mapping of turn off reasons is working")
{
  /* Initialize Data */
  InitData();

  /* Set turn off reasons */
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_CITY);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_TUNNEL);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MIN_SPEED);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_ONCOMING);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_PRECEDING);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BLOCKAGE);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_FOG);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER);

  /* call function */
  COU_CALL(HLAFMatrix_SetTurnOffReason(&FData, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_CITY), b_TRUE, "Turn off reason city is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_TUNNEL), b_TRUE, "Turn off reason tunnel is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_BRIGHTNESS), b_TRUE, "Turn off reason brightness is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_SPEED), b_TRUE, "Turn off reason min speed is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_ONC), b_TRUE, "Turn off reason oncoming is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_PREC), b_TRUE, "Turn off reason preceding is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_BLOCKAGE), b_TRUE, "Turn off reason blockage is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_FOG), b_TRUE, "Turn off reason fog is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_WEATHER), b_TRUE, "Turn off reason weather is set");
}

/** \test
 *  \description
 *     Test that turn off reasons are correctly mapped to ouput in case of no turn off reason is set. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct turn off reason is set \n */
test_HLAFMatrix_SetTurnOffReason_NoInternalTurnOffIsSet_NoTurnOffReasonsIsSet(HLAFMatrix_SetTurnOffReason_NoInternalTurnOffIsSet_NoTurnOffReasonsIsSet, "Test mapping of turn off reasons is working in case no turn off reason is set")
{
  /* Initialize Data */
  InitData();

  /* call function */
  COU_CALL(HLAFMatrix_SetTurnOffReason(&FData, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_CITY), b_FALSE, "Turn off reason city is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_TUNNEL), b_FALSE, "Turn off reason tunnel is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_BRIGHTNESS), b_FALSE, "Turn off reason brightness is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_SPEED), b_FALSE, "Turn off reason min speed is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_ONC), b_FALSE, "Turn off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_PREC), b_FALSE, "Turn off reason preceding is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_BLOCKAGE), b_FALSE, "Turn off reason blockage is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_FOG), b_FALSE, "Turn off reason fog is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_WEATHER), b_FALSE, "Turn off reason weather is not set");
}

/** \test
 *  \description
 *     Test that turn off reason delay is set, when no other turn off reason is present and high beam state is off. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Turn off reason delay is set. \n */
test_HLAFMatrix_SetTurnOffReason_HBIsOffNoOtherTurnOffReasonSet_DelayTurnOffReasonIsSet(HLAFMatrix_SetTurnOffReason_HBIsOffNoOtherTurnOffReasonSet_DelayTurnOffReasonIsSet, "Test that turn off reason delay is set, when no other turn off reason is present and high beam state is off")
{
  /* Initialize Data */
  InitData();

  MatrixOut.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFMatrix_SetTurnOffReason(&FData, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_CITY), b_FALSE, "Turn off reason city is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_TUNNEL), b_FALSE, "Turn off reason tunnel is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_BRIGHTNESS), b_FALSE, "Turn off reason brightness is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_SPEED), b_FALSE, "Turn off reason min speed is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_ONC), b_FALSE, "Turn off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_PREC), b_FALSE, "Turn off reason preceding is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_BLOCKAGE), b_FALSE, "Turn off reason blockage is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_FOG), b_FALSE, "Turn off reason fog is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_WEATHER), b_FALSE, "Turn off reason weather is not set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_DELAY), b_TRUE, "Turn off reason delay is set");
}

/** \test
 *  \description
 *     Test mapping of turn off reasons max speed and EM object. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct turn off reason is set. \n */
test_HLAFMatrix_SetTurnOffReason_InternalMaxSpeedAndEMOBjectTurnOffIsSet_TurnOffReasonsAreCorrectlyMapped(HLAFMatrix_SetTurnOffReason_InternalMaxSpeedAndEMOBjectTurnOffIsSet_TurnOffReasonsAreCorrectlyMapped, "Test mapping of turn off reasons max speed and EM object")
{
  /* Initialize Data */
  InitData();

  /* Set turn off reasons */
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MAX_SPEED);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC);
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_PREC);

  /* call function */
  COU_CALL(HLAFMatrix_SetTurnOffReason(&FData, &MatrixOut), "function call");

  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_SPEED), b_TRUE, "Turn off reason min speed is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_PREC), b_TRUE, "Turn off reason preceding is set");
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_ONC), b_TRUE, "Turn off reason preceding is set");
}
/** \test
 *  \description
 *     Test mapping of turn off reason for radar object. \n
 *     calls function HLAFMatrix_SetOutput() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct turn off reason is set. \n */
test_HLAFMatrix_SetTurnOffReason_InternalRadarObjectIsSet_TurnOffReasonIsCorrectlyMapped(HLAFMatrix_SetTurnOffReason_InternalRadarObjectIsSet_TurnOffReasonIsCorrectlyMapped, "Test mapping of turn off reason for radar object")
{
  /* Initialize Data */
  InitData();

  /* Set turn off reasons */
  CML_SetBit(FData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_RADAR_OBJECT);

  /* call function */
  COU_CALL(HLAFMatrix_SetTurnOffReason(&FData, &MatrixOut), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(CML_GetBit(MatrixOut.Matrix.TurnOffReason, RTE_HLAF_TURNOFFREASON_PREC), b_TRUE, "Turn off reason preceding is set");
}
/** \test
 *  \description
 *     Test that correct low beam distance is set, depending on high beam state, number of GFAs or global turn off reasons. \n
 *     calls function HLAFMatrix_SetLowBeamDist() \n
 *  \precondition
 *     None \n
 *  \result
 *     Correct low beam distance is set. \n */
TEST_HLAFMatrix_SetLowBeamDist_001(HLAFMatrix_SetLowBeamDist_001, "Test that correct low beam distance is set")
{
  /* --- High beam will be turned on --- */
  /* Initialize Data */
  InitData();

  /* high beam will be turned on */
  HighBeamStateNext = RTE_HLAF_HB_STATE_FULL_ON;

  /* call function */
  COU_CALL(HLAFMatrix_SetLowBeamDist(&FData, &FData.hlafMatrixData, HighBeamStateNext, &HlafMatrixParameter, &MatrixNext), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Dist, HlafMatrixParameter.Output.LowBeam_Dist_Max, "Low Beam Distance is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Ang, HlafMatrixParameter.Output.LowBeam_Ang_Default, "Low Beam angle is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Status, RTE_HLAF_OBJSTA_NO_OBJ, "Low Beam status is correctly set");

  /* --- High beam will be turned off and GFAs are available --- */
  /* Initialize Data */
  InitData();

  /* high beam will be off */
  HighBeamStateNext = RTE_HLAF_HB_STATE_OFF;

  FData.hlafMatrixData.Matrix.GFA.nGFA = 2;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.MinLight_Dist = 1.0f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.MinLight_Ang = 0.5f;
  FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.MinLight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
  FData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.MinLight_Dist = 2.0f;

  /* call function */
  COU_CALL(HLAFMatrix_SetLowBeamDist(&FData, &FData.hlafMatrixData, HighBeamStateNext, &HlafMatrixParameter, &MatrixNext), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Dist, FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.MinLight_Dist, "Low Beam Distance is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Ang, FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.MinLight_Ang, "Low Beam angle is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Status, FData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.MinLight_Status, "Low Beam status is correctly set");

  /* --- No GFA, but global turn off reason --- */
  /* Initialize Data */
  InitData();

  /* high beam will be off */
  HighBeamStateNext = RTE_HLAF_HB_STATE_OFF;

  /* no GFA */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 0;

  /* Turn off reason is present */
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFMatrix_SetLowBeamDist(&FData, &FData.hlafMatrixData, HighBeamStateNext, &HlafMatrixParameter, &MatrixNext), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Dist, HlafMatrixParameter.Output.LowBeam_Dist_Default, "Low Beam Distance is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Ang, HlafMatrixParameter.Output.LowBeam_Ang_Default, "Low Beam angle is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Status, RTE_HLAF_OBJSTA_NO_OBJ, "Low Beam status is correctly set");

  /* --- keep old distances --- */
  /* Initialize Data */
  InitData();

  /* high beam will be off */
  HighBeamStateNext = RTE_HLAF_HB_STATE_OFF;

  /* no GFA */
  FData.hlafMatrixData.Matrix.GFA.nGFA = 0;

  /* Turn off reason is not present */
  FData.DecisionData.TurnOffReason.Reason = 0;

  /* set matrix data */
  FData.hlafMatrixData.Out.Matrix.LowBeam_Dist = 20.0f;
  FData.hlafMatrixData.Out.Matrix.LowBeam_Ang = 0.5f;
  FData.hlafMatrixData.Out.Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_PREC_OBJ;

  /* call function */
  COU_CALL(HLAFMatrix_SetLowBeamDist(&FData, &FData.hlafMatrixData, HighBeamStateNext, &HlafMatrixParameter, &MatrixNext), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Dist, FData.hlafMatrixData.Out.Matrix.LowBeam_Dist, "Low Beam Distance is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Ang, FData.hlafMatrixData.Out.Matrix.LowBeam_Ang, "Low Beam angle is correctly set");
  COU_ASSERT_EQUAL(MatrixNext.LowBeam_Status, FData.hlafMatrixData.Out.Matrix.LowBeam_Status, "Low Beam status is correctly set");
}


/** list of all test methods of the related suite. */
cou_test_t hla_Matrix[] = {
   COU_ADD_TEST(HLAFMatrix_Init_001),
   COU_ADD_TEST(HLAFMatrix_Main_001),
   COU_ADD_TEST(HLAFMatrix_InitOutput_001),
   COU_ADD_TEST(HLAFMatrix_InitObjectList_001),
   COU_ADD_TEST(HLAFMatrix_SetOutput_001),
   COU_ADD_TEST(HLAFMatrix_SetOutput_002),
   COU_ADD_TEST(HLAFMatrix_SetTurnOffReason_AllInternalReasonsAreSet_ReasonsAreCorrectlyMapped),
   COU_ADD_TEST(HLAFMatrix_SetTurnOffReason_NoInternalTurnOffIsSet_NoTurnOffReasonsIsSet),
   COU_ADD_TEST(HLAFMatrix_SetTurnOffReason_HBIsOffNoOtherTurnOffReasonSet_DelayTurnOffReasonIsSet),
   COU_ADD_TEST(HLAFMatrix_SetTurnOffReason_InternalRadarObjectIsSet_TurnOffReasonIsCorrectlyMapped),
   COU_ADD_TEST(HLAFMatrix_SetTurnOffReason_InternalMaxSpeedAndEMOBjectTurnOffIsSet_TurnOffReasonsAreCorrectlyMapped),
   COU_ADD_TEST(HLAFMatrix_SetLowBeamDist_001),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(HlafMatrixInit, "Initialize Hlaf Matrix")
{
  /* No Init */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Matrix, hla_Matrix, HlafMatrixInit, "Module test for hlaf_matrix.c"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */

