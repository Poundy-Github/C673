/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>

#include "hla_defs.h"
#include "hla_ext.h"
#include "hlaf_ext.h"
#include "HLA_MatrixParameters.h"
#include "hlaf_type.h"
#include "hla_ver.h"
#include "../../mockup_services.h"


// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_Hlaf_Init                      COU_TEST
#define TEST_Hlaf_Exec                      COU_TEST
#define TEST_Hlaf_FillData                  COU_TEST
#define TEST_Hlaf_SaeVehiclesData           COU_TEST
#define TEST_Hlaf_FillOutputData            COU_TEST
#define TEST_Hlaf_FillOutputDataMatrixBeam  COU_TEST
#define TEST_Hlaf_CopySortedMatrixData      COU_TEST

// Define external global variables of file under test
extern HLAFData_t hlafData;
extern AlgoDataTimeStamp_t timeStampPrevCycle;

// Define external global variables of mock-ups
extern unsigned int HLACamRotInit__numOfCalls;
extern unsigned int HLACamRotSetData__numOfCalls;
extern unsigned int HLAFMatrix_Init__numOfCalls;
extern unsigned int HLAFMatrix_InitObjectList__numOfCalls;
extern unsigned int HLAFMatrix_Main__numOfCalls;
extern unsigned int HLAFMatrix_InitOutput__numOfCalls;
extern unsigned int HLAFMatrix_SetLowBeamDist__numOfCalls;
extern unsigned int HLAFMatrix_SetTurnOffReason__numOfCalls;
extern unsigned int HLAFMatrix_SetOutput__numOfCalls;
extern unsigned int HLAFMatrix_Main__numOfCalls;
extern unsigned int HLAFDecisionBlockage_Main__numOfCalls;
extern unsigned int HLAFDecisionEnv_Speed__numOfCalls;
extern unsigned int HLAFDecisionEnv_City__numOfCalls;
extern unsigned int HLAFDecisionEnv_Weather__numOfCalls;
extern unsigned int HLAFDecision_SetTurnOffReasonGlob__numOfCalls;
extern unsigned int HLAFDecision_FindRelevantVehicle__numOfCalls;
extern unsigned int HLAFDecision_CheckEMObjectList__numOfCalls;
extern unsigned int HLAFDecision_SetTurnOffReason__numOfCalls;
extern unsigned int HLAFDecision_SetKeepOffReason__numOfCalls;
extern unsigned int HLAFDecision_SetHBState__numOfCalls;
extern unsigned int HLAFDimming_InitAreas__numOfCalls;
extern unsigned int HLAFDimming_DecisionAreas__numOfCalls;
extern unsigned int HLAFDimming_InvalidateAreas__numOfCalls;
extern unsigned int HLAFDimming_FillAreas__numOfCalls;

// Declaration of static functions
extern void HLAF_FillData( const reqHlaPrtList_t* pReqPorts,
                                 HLAFData_t*      pFData
                          );
extern void HLAF_FillOutputData( const reqHlaPrtList_t*     pReqPorts,
                                 const HLAFData_t*          pFData,
                                 const t_MatrixParameters*  pMatrixParameters,
                                       proHlaPrtList_t*     pProPorts
                                );
extern void HLAF_FillOutputDataMatrixBeam( const reqHlaPrtList_t*    pReqPorts,
                                           const HLAFData_t*         pFData,
                                           const t_MatrixParameters* pMatrixParameters,
                                                 RTE_HLAF_Matrix_t*  pMatrixOut
                                          );

extern void HLAF_CopySortedMatrixData( const RTE_HLAF_Matrix_t*    pMatrixIn,
                                             RTE_HLAF_Matrix_t*    pMatrixOut
                                     );

// Local functions
static void InitHlafInputs(void)
{
  /* Init generic stuff */
  Mockup_InitGlobVars();
}

// TEST CASES
/** \test
 *  \description
 *     Test whether HLAF was initialized as designed. \n
 *  \precondition
 *     Valid measurement counter and timestamp in base control data. \n
 *  \result
 *     Initialized internal data and called initialization functions of modules. \n
 */
TEST_Hlaf_Init(Hlaf_Init, "Call of HLAF_v_Init")
{
  /* Define test data */
  const uint8 timeStamp = 44u;
  const uint8 meascount = 55u;

  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(BaseCtrlData.sSigHeader.uiTimeStamp,          timeStamp, "Set timestamp value to input data.");
  COU_SET(BaseCtrlData.sSigHeader.uiMeasurementCounter, meascount, "Set meascount value to input data.");

  /* Call function under test */
  COU_CALL(HLAF_v_Init(&ReqPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(timeStampPrevCycle,                            timeStamp,                "Timestamp should match.");
  COU_ASSERT_EQUAL(hlafData.TimeStamp_HLA_ms,                     timeStamp,                "Timestamp should match.");
  COU_ASSERT_EQUAL(hlafData.FrameCnt,                             meascount,                "Frame counter should match.");
  COU_ASSERT_EQUAL(hlafData.DecisionData.Blockage.eBlockageState, HLAF_BLOCKAGE_CLEAR_MEAS, "Correct blockage state should be set.");
  COU_ASSERT_EQUAL(hlafData.CamData.ddist_m,                      0,                        "Driven Distance should stay zero.");
  COU_ASSERT_EQUAL(hlafData.HLAMatrixOut.Matrix.TurnOffReason,    0,                        "Last element of structure should stay zero.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLACamRotInit__numOfCalls,         1, "HLACamRotInit() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_Init__numOfCalls,       1, "HLAFMatrix_Init() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDimming_InitAreas__numOfCalls, 1, "HLAFDimming_InitAreas() should have been called only once.");
}

/** \test
 *  \description
 *     Test whether HLAF main function was executed as designed. In this test case
 *     focus is on whether all modules are correctly called including the ones in local
 *     functions HLAF_EnvironmentDecisions() and HLAF_SetLightStates(). \n
 *  \precondition
 *     Valid pointers in Services and request and provide port lists. \n
 *  \result
 *     Called functions of modules. \n
 */
TEST_Hlaf_Exec(Hlaf_Exec, "Call of HLAF_v_Exec")
{
  /* Define test                              data */
  const uint8 brightnessState   = 4u;
  const uint8 tunnelState       = 5u;
  const uint8 highwayState      = 6u;
  const uint8 trafficStyleState = 7u;

  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(CPar_HlafPar.Dimming.DimmingDetection, RTE_HLA_DIMMDET_INACTIVE, "Set dimming detection coding parameter to inactive.");
  COU_SET(LsdEnvironmentData.brightnessState,    brightnessState,          "Set brightnessState value to input data.");
  COU_SET(LsdEnvironmentData.tunnelState,        tunnelState,              "Set tunnelState value to input data.");
  COU_SET(LsdEnvironmentData.trafficStyleState,  trafficStyleState,        "Set trafficStyleState value to input data.");
  COU_SET(LsdEnvironmentData.highwayState,       highwayState,             "Set highwayState value to input data.");

  /* Call function under test */
  COU_CALL(HLAF_v_Exec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(hlafData.DecisionOut.eBrightnessState, brightnessState,   "Correct brightness state should be set.");
  COU_ASSERT_EQUAL(hlafData.DecisionOut.eTunnelState,     tunnelState,       "Correct tunnel state should be set.");
  COU_ASSERT_EQUAL(hlafData.DecisionOut.eTrafficStyle,    trafficStyleState,      "Correct highway state should be set.");
  COU_ASSERT_EQUAL(hlafData.DecisionOut.eHighwayState,    highwayState,      "Correct highway state should be set.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLACamRotSetData__numOfCalls,                  1, "HLACamRotSetData() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_InitOutput__numOfCalls,             1, "HLAFMatrix_InitOutput() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_InitObjectList__numOfCalls,         1, "HLAFMatrix_InitObjectList() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_SetLowBeamDist__numOfCalls,         1, "HLAFMatrix_SetLowBeamDist() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_SetTurnOffReason__numOfCalls,       1, "HLAFMatrix_SetTurnOffReason() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_SetOutput__numOfCalls,              1, "HLAFMatrix_SetOutput() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFMatrix_Main__numOfCalls,                   1, "HLAFMatrix_Main() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecisionBlockage_Main__numOfCalls,         1, "HLAFDecisionBlockage_Main() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecisionEnv_Speed__numOfCalls,             1, "HLAFDecisionEnv_Speed() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecisionEnv_City__numOfCalls,              1, "HLAFDecisionEnv_City() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecisionEnv_Weather__numOfCalls,           1, "HLAFDecisionEnv_Weather() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecision_SetTurnOffReasonGlob__numOfCalls, 1, "HLAFDecision_SetTurnOffReasonGlob() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecision_FindRelevantVehicle__numOfCalls,  1, "HLAFDecision_FindRelevantVehicle() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecision_CheckEMObjectList__numOfCalls,    1, "HLAFDecision_CheckEMObjectList() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecision_SetTurnOffReason__numOfCalls,     1, "HLAFDecision_SetTurnOffReason() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecision_SetKeepOffReason__numOfCalls,     1, "HLAFDecision_SetKeepOffReason() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDecision_SetHBState__numOfCalls,           1, "HLAFDecision_SetHBState() should have been called only once.");
  COU_ASSERT_EQUAL(HLAFDimming_InvalidateAreas__numOfCalls,       1, "HLAFDimming_InvalidateAreas() should have been called only once.");

  /* Set input data so that missing external functions gets called. */
  COU_SET(CPar_HlafPar.Dimming.DimmingDetection, RTE_HLA_DIMMDET_ACTIVE,   "Set dimming detection coding parameter to active.");

  /* Call function under test */
  COU_CALL(HLAF_v_Exec(&ReqPorts, &ProPorts, &Services), "call of function");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAFDimming_DecisionAreas__numOfCalls, 1, "HLAFDimming_DecisionAreas() should have been called only once.");
}

/** \test
 *  \description
 *     Test of static Hlaf_FillData(). A separate test case is needed due to many boolean expressions. \n
 *  \precondition
 *     Valid pointers in request port lists as well as proper VDY data. \n
 *  \result
 *     Valid hlafData.CamData based on VDY data. \n
 */
TEST_Hlaf_FillData(Hlaf_FillData, "Call of Hlaf_FillData")
{
  /****************************************
   * Straight forward case
   ****************************************/
  /* Define test data */
       uint64 timeStamp        = 4500000u;
  const uint8  meascount       = 55u;

  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(timeStampPrevCycle,                           4400000u,                            "Set timestamp value of previous cycle.");
  COU_SET(BaseCtrlData.sSigHeader.uiTimeStamp,          timeStamp,                           "Set timestamp value to input data.");
  COU_SET(BaseCtrlData.sSigHeader.uiMeasurementCounter, meascount,                           "Set meascount value to input data.");
  COU_SET(VDYData.Longitudinal.Velocity,                66u,                                 "Set velocity value to input data.");
  COU_SET(VDYData.MotionState.MotState ,                VDY_LONG_MOT_STATE_MOVE_FWD,         "Set motionState value to input data.");
  COU_SET_FMT(VDYData.Lateral.Curve.Curve,              -2.0f,                       "%.1f", "Set curve value to input data.");

  /* Call function under test */
  COU_CALL(HLAF_FillData(&ReqPorts, &hlafData), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(hlafData.FrameCnt,                meascount,         "Frame counter should match.");
  COU_ASSERT_EQUAL(hlafData.TimeStamp_HLA_ms,        timeStamp,         "Timestamp should match.");
  COU_ASSERT_EQUAL(timeStampPrevCycle,               timeStamp,         "Timestamp should match.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.dtime_s,     0.1f,      "%.1f", "dtime_s = timeStamp - timeStampPrevCycle.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.ddist_m,     6.6f,      "%.1f", "Driven Distance = time * velocity.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.dtimeFwd_s,  0.1f,      "%.1f", "As we are driving forward it's the same time as dtime_s.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.ddistFwd_m,  6.6f,      "%.1f", "As we are driving forward it's the same distance as ddist_m.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.radius_m,    -0.5f,     "%.1f", "Inverse of curve");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.radiusAbs_m, 0.5f,      "%.1f", "Absolute value of radius");

  /****************************************
   * Test case for ...
   * ... timestamp wrap around
   * ... not driving forward case
   * ... curve of zero
   ****************************************/
  /* Define test data */
  timeStamp   = 0;

  /* Set input data */
  COU_SET(timeStampPrevCycle,                  4294867295u,                         "Set timestamp value of previous cycle to check 32-bit wrap around.");
  COU_SET(BaseCtrlData.sSigHeader.uiTimeStamp, timeStamp,                           "Set timestamp value to input data.");
  COU_SET(VDYData.MotionState.MotState ,       VDY_LONG_MOT_STATE_MOVE_RWD,         "Set motionState value to input data.");
  COU_SET_FMT(VDYData.Lateral.Curve.Curve,     0.0f,                        "%.1f", "Set curve value to input data.");

  /* Call function under test */
  COU_CALL(HLAF_FillData(&ReqPorts, &hlafData), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(hlafData.TimeStamp_HLA_ms,        timeStamp,         "Timestamp should match.");
  COU_ASSERT_EQUAL(timeStampPrevCycle,               timeStamp,         "Timestamp should match.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.dtime_s,     0.1f,      "%.1f", "dtime_s = timeStamp - timeStampPrevCycle.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.ddist_m,     6.6f,      "%.1f", "Driven Distance = time * velocity.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.dtimeFwd_s,  0.0f,      "%.1f", "As we are not driving forward it's simply zero.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.ddistFwd_m,  0.0f,      "%.1f", "As we are not driving forward it's simply zero.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.radius_m,    100000.0f, "%.1f", "Maximum radius");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.radiusAbs_m, 100000.0f, "%.1f", "Absolute value of radius");

  /****************************************
   * Test case for too many consecutive
   * frame drops case.
   ****************************************/
  /* Define test data */
  timeStamp = 4800000u;

  /* Set input data */
  COU_SET(timeStampPrevCycle,                  4400000u,  "Set timestamp value of previous cycle so that last call was more than 6 frames before.");
  COU_SET(BaseCtrlData.sSigHeader.uiTimeStamp, timeStamp, "Set timestamp value to input data.");

  /* Call function under test */
  COU_CALL(HLAF_FillData(&ReqPorts, &hlafData), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(hlafData.TimeStamp_HLA_ms,        timeStamp,         "Timestamp should match.");
  COU_ASSERT_EQUAL(timeStampPrevCycle,               timeStamp,         "Timestamp should match.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.dtime_s,     0.0f,      "%.1f", "Forced to be zero");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.ddist_m,     0.0f,      "%.1f", "Driven Distance = time * velocity.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.dtimeFwd_s,  0.0f,      "%.1f", "As we are not driving forward it's simply zero.");
  COU_ASSERT_EQUAL_FMT(hlafData.CamData.ddistFwd_m,  0.0f,      "%.1f", "As we are not driving forward it's simply zero.");
}

/** \test
 *  \description
 *     Test of static HLAF_FillOutputData(). A separate test case is needed due to many boolean expressions. \n
 *  \precondition
 *     Valid pointers in request port lists. \n
 *  \result
 *     Valid data in common part of headlight control provide port. \n
 */
TEST_Hlaf_FillOutputData(Hlaf_FillOutputData, "Call of HLAF_FillOutputData")
{
  const t_MatrixParameters* pHlafMatrixParameter = GetMatrixParameters();

  /****************************************
   * Test case where all if-conditions are made TRUE
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(HLAFDimming_FillAreas__numOfCalls,          0,                                           "Reset counter for function calls.");
  COU_SET(CPar_HlafPar.AlgoCfg.TestMode,              RTE_HLA_TESTMODE_SAE,                        "Set test mode to be \"SAE ON\".");
  COU_SET(CPar_HlafPar.AlgoCfg.sensitivityMode,       RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN,       "Set SAE mode to be \"OFF\".");
  COU_SET(hlafData.DecisionOut.eTrafficStyle,         LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC,        "Set traffic style decision to right hand mode.");
  COU_SET(hlafData.DecisionOut.eCityState,            RTE_HLAR_CITY_DTCD,                          "Set city state decision to detected city.");
  COU_SET(hlafData.DecisionOut.eTunnelState,          LSD_ENVIRONMENT_DATA_TUNNEL_STATE_INSIDE,    "Set tunnel state decision to be inside a tunnel.");
  COU_SET(hlafData.DecisionOut.eHighwayState,         LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED, "Set highway state decision to be on one.");
  COU_SET(hlafData.DecisionOut.eBrightnessState,      LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY,   "Set brightness state decision to day mode.");
  COU_SET(hlafData.DecisionOut.eWeatherState,         RTE_HLAR_WEATHER_BAD,                        "Set weather state decision to bad weather.");
  COU_SET(hlafData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MIN_SPEED,              "Set turnoff reason decision for lower speed boundary.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputData(&ReqPorts, &hlafData, pHlafMatrixParameter, &ProPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,        RTE_HLA_SENSMODE_US,         "SAE mode should be \"US\"");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle,    RTE_HLA_TRAFFIC_STYLE_RHT,   "Traffic style should be right hand.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState,       RTE_HLAR_CITY_DTCD,          "City should have been detected.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState,     RTE_HLAR_TUNNEL_INSIDE,      "We should be inside a tunnel.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState,   RTE_HLAF_MTWY_MOTORWAY,      "We should be on a motorway.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_DAY,            "It should be day light outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState,    RTE_HLAR_WEATHER_BAD,        "There should be bad weather outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState,      RTE_HLAF_SPEEDSTATE_TOO_LOW, "Speed state should be below range.");

  /* Check called functions */
  COU_ASSERT_EQUAL(HLAFDimming_FillAreas__numOfCalls, 1, "HLAFDimming_FillAreas() should have been called only once.");

  /****************************************
   * Test case where all second conditions are made TRUE
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(CPar_HlafPar.AlgoCfg.TestMode,              RTE_HLA_TESTMODE_UNKNOWN,                         "Set test mode to be \"OFF\".");
  COU_SET(CPar_HlafPar.AlgoCfg.sensitivityMode,       RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN,            "Set SAE mode to be \"OFF\".");
  COU_SET(hlafData.DecisionOut.eTrafficStyle,         LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC,              "Set traffic style decision to left hand mode.");
  COU_SET(hlafData.DecisionOut.eCityState,            RTE_HLAR_CITY_NOT_DTCD,                           "Set city state decision to detected city.");
  COU_SET(hlafData.DecisionOut.eTunnelState,          LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UPFRONT,        "Set tunnel state decision to be inside a tunnel.");
  COU_SET(hlafData.DecisionOut.eHighwayState,         LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE,          "Set highway state decision to be on one.");
  COU_SET(hlafData.DecisionOut.eBrightnessState,      LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1, "Set brightness state decision to twilight_1 mode.");
  COU_SET(hlafData.DecisionOut.eWeatherState,         RTE_HLAR_WEATHER_GOOD,                            "Set weather state decision to good weather.");
  COU_SET(hlafData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MAX_SPEED,                   "Set turnoff reason decision for upper speed boundary.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputData(&ReqPorts, &hlafData, pHlafMatrixParameter, &ProPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,        RTE_HLA_SENSMODE_NORMAL,      "SAE mode should be \"normal\"");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle,    RTE_HLA_TRAFFIC_STYLE_LHT,    "Traffic style should be left hand.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState,       RTE_HLAR_CITY_NOT_DTCD,       "City should not have been detected.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState,     RTE_HLAR_TUNNEL_NOT_DTCD,     "We should not be inside a tunnel.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState,   RTE_HLAF_MTWY_COUNTRY,        "We should be on a country road.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_TWLGT_1,         "It should be twilight_1 light outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState,    RTE_HLAR_WEATHER_GOOD,        "There should be good weather outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState,      RTE_HLAF_SPEEDSTATE_TOO_HIGH, "Speed state should be above range.");

  /****************************************
   * Test case where all third conditions are made TRUE
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(CPar_HlafPar.AlgoCfg.TestMode,              RTE_HLA_TESTMODE_UNKNOWN,                         "Set test mode to be \"OFF\".");
  COU_SET(HlaBusInputSignals.sensitivityModeSignal,   RTE_HLA_SENSMODE_US,                              "Set SAE mode to be \"ON\".");
  COU_SET(CPar_HlafPar.AlgoCfg.sensitivityMode,       RTE_HLA_CPAR_SENSITIVITY_MODE_US,                 "Set SAE mode to be \"ON\".");
  COU_SET(hlafData.DecisionOut.eTrafficStyle,         LSD_TRAFFIC_STYLE_UNKNOWN,                        "Set traffic style decision to left hand mode.");
  COU_SET(hlafData.DecisionOut.eCityState,            RTE_HLAR_CITY_UNKNOWN,                            "Set city state decision to unknown.");
  COU_SET(hlafData.DecisionOut.eTunnelState,          LSD_ENVIRONMENT_DATA_TUNNEL_STATE_NONE,           "Set tunnel state decision to be outside a tunnel.");
  COU_SET(hlafData.DecisionOut.eHighwayState,         LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_UNKNOWN,       "Set highway state decision to be unknown.");
  COU_SET(hlafData.DecisionOut.eBrightnessState,      LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2, "Set brightness state decision to twilight_2 mode.");
  COU_SET(hlafData.DecisionOut.eWeatherState,         RTE_HLAR_WEATHER_UNKNOWN,                         "Set weather state to be unknown.");
  COU_SET(hlafData.DecisionData.TurnOffReason.Reason, 0,                                                "Set no turnoff reason.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputData(&ReqPorts, &hlafData, pHlafMatrixParameter, &ProPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,        RTE_HLA_SENSMODE_US,           "SAE mode should be \"US\"");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TrafficStyle,    RTE_HLA_TRAFFIC_STYLE_UNKNOWN, "Traffic style should be unknown.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState,       RTE_HLAR_CITY_NOT_DTCD,        "City should not have been detected.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState,     RTE_HLAR_TUNNEL_NOT_DTCD,      "We should not be inside a tunnel.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.MotorwayState,   RTE_HLAF_MTWY_COUNTRY,         "We should be on a country road.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_TWLGT_2,          "It should be twilight_2 light outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState,    RTE_HLAR_WEATHER_UNKNOWN,      "Weather state is unknown.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState,      RTE_HLAF_SPEEDSTATE_IN_RANGE,  "Speed state should be in range.");


  /****************************************
   * Test case where all fourth conditions are made TRUE
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(CPar_HlafPar.AlgoCfg.TestMode,              RTE_HLA_TESTMODE_UNKNOWN,                         "Set test mode to be \"OFF\".");
  COU_SET(HlaBusInputSignals.sensitivityModeSignal,   RTE_HLA_SENSMODE_US,                              "Set SAE mode to be \"ON\".");
  COU_SET(CPar_HlafPar.AlgoCfg.sensitivityMode,       RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN,            "Set SAE mode to be \"OFF\".");
  COU_SET(hlafData.DecisionOut.eCityState,            RTE_HLAR_CITY_MAYBE,                              "Set city state decision to maybe.");
  COU_SET(hlafData.DecisionOut.eTunnelState,          LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UNKNOWN,        "Set tunnel state decision to be unknown.");
  COU_SET(hlafData.DecisionOut.eBrightnessState,      LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3, "Set brightness state decision to twilight_3 mode.");
  COU_SET(hlafData.DecisionOut.eWeatherState,         RTE_HLAR_WEATHER_LIGHT_FOG,                       "Set weather state to light fog.");
  COU_SET(hlafData.DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_PRECEDING,                   "Set non-speed relevant turnoff reason.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputData(&ReqPorts, &hlafData, pHlafMatrixParameter, &ProPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SensMode,        RTE_HLA_SENSMODE_NORMAL,       "SAE mode should be \"normal\"");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.CityState,       RTE_HLAR_CITY_NOT_DTCD,        "City should not have been detected.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.TunnelState,     RTE_HLAR_TUNNEL_NOT_DTCD,      "We should not be inside a tunnel.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_TWLGT_3,          "It should be twilight_3 light outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState,    RTE_HLAR_WEATHER_LIGHT_FOG,    "Weather state should be light fog.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.SpeedState,      RTE_HLAF_SPEEDSTATE_IN_RANGE,  "Speed state should be in range.");


  /****************************************
   * Test case where all fifth conditions are made TRUE
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(hlafData.DecisionOut.eBrightnessState,      LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT, "Set brightness state decision to night mode.");
  COU_SET(hlafData.DecisionOut.eWeatherState,         RTE_HLAR_WEATHER_MEDIUM_FOG,                 "Set weather state to medium fog.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputData(&ReqPorts, &hlafData, pHlafMatrixParameter, &ProPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_NIGHT,            "It should be night outside.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState,    RTE_HLAR_WEATHER_MEDIUM_FOG,   "Weather state should be medium fog.");

  /****************************************
   * Test case where all sixth conditions are made TRUE
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();

  /* Set input data */
  COU_SET(hlafData.DecisionOut.eBrightnessState,      LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN, "Set brightness state decision to unknown.");
  COU_SET(hlafData.DecisionOut.eWeatherState,         RTE_HLAR_WEATHER_HEAVY_FOG,                    "Set weather state to heavy fog.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputData(&ReqPorts, &hlafData, pHlafMatrixParameter, &ProPorts), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.BrightnessState, RTE_HLAR_BRT_INVALID,          "Brightness state should be invalid.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Common.WeatherState,    RTE_HLAR_WEATHER_HEAVY_FOG,    "Weather state should be heavy fog.");
}

/** \test
 *  \description
 *     Test of static HLAF_FillOutputDataMatrixBeam(). A separate test case is needed due to many boolean expressions. \n
 *  \precondition
 *     Valid pointers in request port lists. \n
 *  \result
 *     Valid data in matrix part of headlight control provide port. \n
 */
TEST_Hlaf_FillOutputDataMatrixBeam(Hlaf_FillOutputDataMatrixBeam, "Call of HLAF_FillOutputDataMatrixBeam")
{
  const t_MatrixParameters* pHlafMatrixParameter = GetMatrixParameters();
  t_MatrixParameters HlafMatrixParameter;

  /* copy parameter to local struct */
  memcpy(&HlafMatrixParameter, pHlafMatrixParameter, CML_Min(sizeof(*pHlafMatrixParameter), sizeof(HlafMatrixParameter)));

  /****************************************
   * Test case where we are not moving forward
   ****************************************/
  /* Define test data */
  const uint8 turnOffReason = 44u;
  const uint8 highbeamState = 55u;

  /* Initialize inputs */
  InitHlafInputs();
  memset(&(ProPorts.pHlaf_HeadlightControl->Matrix), 33, sizeof(ProPorts.pHlaf_HeadlightControl->Matrix));

  /* Set input data */
  COU_SET(VDYData.MotionState.MotState,                      VDY_LONG_MOT_STATE_MOVE_RWD,  "Let's drive backwards.");
  COU_SET(HlafMatrixParameter.Cfg.bMotionIndOutputGFAData,   b_FALSE,                      "GFA data output shall not be done all the time");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.TurnOffReason,  turnOffReason,                "Dummy turnOffReason.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.HighBeamState,  highbeamState,                "Dummy highbeamState.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputDataMatrixBeam(&ReqPorts, &hlafData, &HlafMatrixParameter, &(ProPorts.pHlaf_HeadlightControl->Matrix)), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA,              0u,                                                "No GFAs should be set.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFAStatus,         RTE_HLAF_SIGSTAT_DATA_INVALID,                     "No GFAs should be set.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist,      pHlafMatrixParameter->Output.LowBeam_Dist_Default, "Default low beam distance should be set.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason,     turnOffReason,                                     "TurnOffReason should be copied from internal buffer.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState,     highbeamState,                                     "HighbeamState should be copied from internal buffer.");


  /****************************************
   * Test case where we are moving forward
   ****************************************/
  /* Define test data */
        uint8   numGFAs      = 1u;
  const float32 dummyFloat   = -99.99f;

  /* Initialize inputs */
  InitHlafInputs();
  memset(&(ProPorts.pHlaf_HeadlightControl->Matrix), 33u, sizeof(ProPorts.pHlaf_HeadlightControl->Matrix));
  memset(&(hlafData.hlafMatrixData.Out.Matrix), 33u, sizeof(hlafData.hlafMatrixData.Out.Matrix));

  /* Set input data */
  COU_SET(VDYData.MotionState.MotState,                                 VDY_LONG_MOT_STATE_MOVE_FWD,                               "Let's drive forward.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.nGFA,                      numGFAs,                                                   "Let's set only one GFA.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.LowBeam_Dist,              pHlafMatrixParameter->Output.LowBeam_Dist_Max + 1.0f,      "Let's set low beam distance above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.LowBeam_Ang,               pHlafMatrixParameter->Output.LowBeam_Ang_Min - 1.0f,       "Let's set low beam angle below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLeft_Ang,      pHlafMatrixParameter->Output.BndryLeft_Ang_Max + 1.0f,     "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLeft_Ang_Cam,  pHlafMatrixParameter->Output.BndryLeft_Ang_Min - 1.0f,     "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryRight_Ang,     pHlafMatrixParameter->Output.BndryRight_Ang_Max + 1.0f,    "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryRight_Ang_Cam, pHlafMatrixParameter->Output.BndryRight_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLower_Ang_Cam, pHlafMatrixParameter->Output.BndryLower_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryUpper_Ang_Cam, pHlafMatrixParameter->Output.BndryUpper_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].ClosestObj_Dist,    pHlafMatrixParameter->Output.ClosestObj_Dist_Max + 1.0f,   "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].ClosestObj_Ang,     pHlafMatrixParameter->Output.ClosestObj_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].MinLight_Dist,      pHlafMatrixParameter->Output.MinLight_Dist_Max + 1.0f,     "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].MinLight_Ang,       pHlafMatrixParameter->Output.MinLight_Ang_Min - 1.0f,      "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryLeft_Ang,      dummyFloat,                                                "Let's set first element of second GFA.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].ttb18Left,          dummyFloat,                                                "Let's set first element of second GFA.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputDataMatrixBeam(&ReqPorts, &hlafData, pHlafMatrixParameter, &(ProPorts.pHlaf_HeadlightControl->Matrix)), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA,                          numGFAs,                                                  "Only one GFA should have been set.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist,              pHlafMatrixParameter->Output.LowBeam_Dist_Max,    "%.3f", "Low beam distance should be limited to upper border.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,               pHlafMatrixParameter->Output.LowBeam_Ang_Min,     "%.3f", "Low beam angle should be limited to lower border.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang,      pHlafMatrixParameter->Output.BndryLeft_Ang_Max,   "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang_Cam,  pHlafMatrixParameter->Output.BndryLeft_Ang_Min,   "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang,     pHlafMatrixParameter->Output.BndryRight_Ang_Max,  "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang_Cam, pHlafMatrixParameter->Output.BndryRight_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Ang_Cam, pHlafMatrixParameter->Output.BndryLower_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryUpper_Ang_Cam, pHlafMatrixParameter->Output.BndryUpper_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Dist,    pHlafMatrixParameter->Output.ClosestObj_Dist_Max, "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Ang,     pHlafMatrixParameter->Output.ClosestObj_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Dist,      pHlafMatrixParameter->Output.MinLight_Dist_Max,   "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Ang,       pHlafMatrixParameter->Output.MinLight_Ang_Min,    "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left,              0.0f,                                                     "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ,                                   "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right,             0.0f,                                                     "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ,                                   "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ExistenceProb,          100u,                                                     "Existence probability should be 100 percent.");

  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Ang,      dummyFloat,                                       "%.3f", "First element of second GFA Second GFA should not have been touched.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Left,          dummyFloat,                                       "%.3f", "Second GFA should not have been touched.");

  /****************************************
   * Test case where we are moving forward, 2nd conditions are TRUE
   ****************************************/
  /* Define test data */
  numGFAs = RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS + 1;

  /* Initialize inputs */
  InitHlafInputs();
  memset(&(ProPorts.pHlaf_HeadlightControl->Matrix), 33u, sizeof(ProPorts.pHlaf_HeadlightControl->Matrix));
  memset(&(hlafData.hlafMatrixData.Out.Matrix), 33u, sizeof(hlafData.hlafMatrixData.Out.Matrix));

  /* Set input data */
  COU_SET(VDYData.MotionState.MotState,                                 VDY_LONG_MOT_STATE_MOVE_FWD,                               "Let's drive forward.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.nGFA,                      numGFAs,                                                   "Let's set only one GFA.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.LowBeam_Dist,              pHlafMatrixParameter->Output.LowBeam_Dist_Max + 1.0f,      "Let's set low beam distance above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.LowBeam_Ang,               pHlafMatrixParameter->Output.LowBeam_Ang_Min - 1.0f,       "Let's set low beam angle below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLeft_Ang,      0.001f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLeft_Ang_Cam,  0.002f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryRight_Ang,     0.003f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryRight_Ang_Cam, 0.004f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLower_Ang_Cam, 0.005f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryUpper_Ang_Cam, 0.006f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].ClosestObj_Dist,    0.007f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].ClosestObj_Ang,     0.008f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].MinLight_Dist,      0.009f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].MinLight_Ang,       0.010f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryLeft_Ang,      0.011f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryLeft_Ang_Cam,  0.012f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryRight_Ang,     0.013f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryRight_Ang_Cam, 0.014f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryLower_Ang_Cam, 0.015f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryUpper_Ang_Cam, 0.016f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].ClosestObj_Dist,    0.017f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].ClosestObj_Ang,     0.018f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].MinLight_Dist,      0.019f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].MinLight_Ang,       0.020f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].BndryLeft_Ang,      0.021f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].BndryLeft_Ang_Cam,  0.022f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].BndryRight_Ang,     0.023f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].BndryRight_Ang_Cam, 0.024f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].BndryLower_Ang_Cam, 0.025f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].BndryUpper_Ang_Cam, 0.026f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].ClosestObj_Dist,    0.027f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].ClosestObj_Ang,     0.028f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].MinLight_Dist,      0.029f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[2].MinLight_Ang,       0.030f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].BndryLeft_Ang,      0.031f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].BndryLeft_Ang_Cam,  0.032f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].BndryRight_Ang,     0.033f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].BndryRight_Ang_Cam, 0.034f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].BndryLower_Ang_Cam, 0.035f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].BndryUpper_Ang_Cam, 0.036f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].ClosestObj_Dist,    0.037f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].ClosestObj_Ang,     0.038f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].MinLight_Dist,      0.039f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[3].MinLight_Ang,       0.040f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].BndryLeft_Ang,      0.041f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].BndryLeft_Ang_Cam,  0.042f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].BndryRight_Ang,     0.043f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].BndryRight_Ang_Cam, 0.044f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].BndryLower_Ang_Cam, 0.045f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].BndryUpper_Ang_Cam, 0.046f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].ClosestObj_Dist,    0.047f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].ClosestObj_Ang,     0.048f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].MinLight_Dist,      0.049f,   "Let's set it to an increasing number.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[4].MinLight_Ang,       0.050f,   "Let's set it to an increasing number.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputDataMatrixBeam(&ReqPorts, &hlafData, pHlafMatrixParameter, &(ProPorts.pHlaf_HeadlightControl->Matrix)), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA,                          numGFAs,                                                  "Only one GFA should have been set.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist,              pHlafMatrixParameter->Output.LowBeam_Dist_Max,    "%.3f", "Low beam distance should be limited to upper border.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,               pHlafMatrixParameter->Output.LowBeam_Ang_Min,     "%.3f", "Low beam angle should be limited to lower border.");

  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].BndryLeft_Ang,      0.001f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].BndryLeft_Ang_Cam,  0.002f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].BndryRight_Ang,     0.003f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].BndryRight_Ang_Cam, 0.004f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].BndryLower_Ang_Cam, 0.005f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].BndryUpper_Ang_Cam, 0.006f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ClosestObj_Dist,    0.007f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ClosestObj_Ang,     0.008f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].MinLight_Dist,      0.009f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].MinLight_Ang,       0.010f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].BndryLeft_Ang,      0.011f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].BndryLeft_Ang_Cam,  0.012f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].BndryRight_Ang,     0.013f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].BndryRight_Ang_Cam, 0.014f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].BndryLower_Ang_Cam, 0.015f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].BndryUpper_Ang_Cam, 0.016f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ClosestObj_Dist,    0.017f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ClosestObj_Ang,     0.018f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].MinLight_Dist,      0.019f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].MinLight_Ang,       0.020f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLeft_Ang,      0.021f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLeft_Ang_Cam,  0.022f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryRight_Ang,     0.023f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryRight_Ang_Cam, 0.024f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryLower_Ang_Cam, 0.025f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].BndryUpper_Ang_Cam, 0.026f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ClosestObj_Dist,    0.027f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ClosestObj_Ang,     0.028f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].MinLight_Dist,      0.029f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].MinLight_Ang,       0.030f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Ang,      0.031f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Ang_Cam,  0.032f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryRight_Ang,     0.033f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryRight_Ang_Cam, 0.034f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLower_Ang_Cam, 0.035f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryUpper_Ang_Cam, 0.036f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ClosestObj_Dist,    0.037f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ClosestObj_Ang,     0.038f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].MinLight_Dist,      0.039f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].MinLight_Ang,       0.040f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang,      0.041f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang_Cam,  0.042f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang,     0.043f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang_Cam, 0.044f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Ang_Cam, 0.045f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryUpper_Ang_Cam, 0.046f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Dist,    0.047f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Ang,     0.048f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Dist,      0.049f, "%.3f", "It should be same as input value.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Ang,       0.050f, "%.3f", "It should be same as input value.");

  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left,              0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right,             0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ExistenceProb,          100u,                   "Existence probability should be 100 percent.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Left,              0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Right,             0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ExistenceProb,          100u,                   "Existence probability should be 100 percent.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ttb18Left,              0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ttb18Right,             0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[2].ExistenceProb,          100u,                   "Existence probability should be 100 percent.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ttb18Left,              0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ttb18Right,             0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[3].ExistenceProb,          100u,                   "Existence probability should be 100 percent.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ttb18Left,              0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ttb18Right,             0.0f,                   "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ, "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[4].ExistenceProb,          100u,                   "Existence probability should be 100 percent.");

  /****************************************
   * Test case where we are not moving forward, but output is activated
   ****************************************/
  /* Initialize inputs */
  InitHlafInputs();
  memset(&(ProPorts.pHlaf_HeadlightControl->Matrix), 33u, sizeof(ProPorts.pHlaf_HeadlightControl->Matrix));
  memset(&(hlafData.hlafMatrixData.Out.Matrix), 33u, sizeof(hlafData.hlafMatrixData.Out.Matrix));

  /* Set input data */
  numGFAs      = 1u;
  COU_SET(VDYData.MotionState.MotState,                                 VDY_LONG_MOT_STATE_MOVE_RWD,                               "Let's drive backwards.");
  COU_SET(HlafMatrixParameter.Cfg.bMotionIndOutputGFAData,              b_TRUE,                                                    "GFA data output shall be done all the time");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.nGFA,                      numGFAs,                                                   "Let's set only one GFA.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.LowBeam_Dist,              pHlafMatrixParameter->Output.LowBeam_Dist_Max + 1.0f,      "Let's set low beam distance above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.LowBeam_Ang,               pHlafMatrixParameter->Output.LowBeam_Ang_Min - 1.0f,       "Let's set low beam angle below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLeft_Ang,      pHlafMatrixParameter->Output.BndryLeft_Ang_Max + 1.0f,     "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLeft_Ang_Cam,  pHlafMatrixParameter->Output.BndryLeft_Ang_Min - 1.0f,     "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryRight_Ang,     pHlafMatrixParameter->Output.BndryRight_Ang_Max + 1.0f,    "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryRight_Ang_Cam, pHlafMatrixParameter->Output.BndryRight_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryLower_Ang_Cam, pHlafMatrixParameter->Output.BndryLower_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].BndryUpper_Ang_Cam, pHlafMatrixParameter->Output.BndryUpper_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].ClosestObj_Dist,    pHlafMatrixParameter->Output.ClosestObj_Dist_Max + 1.0f,   "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].ClosestObj_Ang,     pHlafMatrixParameter->Output.ClosestObj_Ang_Min - 1.0f,    "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].MinLight_Dist,      pHlafMatrixParameter->Output.MinLight_Dist_Max + 1.0f,     "Let's set it above allowed maximum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[0].MinLight_Ang,       pHlafMatrixParameter->Output.MinLight_Ang_Min - 1.0f,      "Let's set it below allowed minimum.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].BndryLeft_Ang,      dummyFloat,                                                "Let's set first element of second GFA.");
  COU_SET(hlafData.hlafMatrixData.Out.Matrix.GFA[1].ttb18Left,          dummyFloat,                                                "Let's set first element of second GFA.");

  /* Call function under test */
  COU_CALL(HLAF_FillOutputDataMatrixBeam(&ReqPorts, &hlafData, &HlafMatrixParameter, &(ProPorts.pHlaf_HeadlightControl->Matrix)), "call of function");

  /* Check internally set data. */
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.nGFA,                          numGFAs,                                                  "Only one GFA should have been set.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Dist,              pHlafMatrixParameter->Output.LowBeam_Dist_Max,    "%.3f", "Low beam distance should be limited to upper border.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.LowBeam_Ang,               pHlafMatrixParameter->Output.LowBeam_Ang_Min,     "%.3f", "Low beam angle should be limited to lower border.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang,      pHlafMatrixParameter->Output.BndryLeft_Ang_Max,   "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang_Cam,  pHlafMatrixParameter->Output.BndryLeft_Ang_Min,   "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang,     pHlafMatrixParameter->Output.BndryRight_Ang_Max,  "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang_Cam, pHlafMatrixParameter->Output.BndryRight_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Ang_Cam, pHlafMatrixParameter->Output.BndryLower_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].BndryUpper_Ang_Cam, pHlafMatrixParameter->Output.BndryUpper_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Dist,    pHlafMatrixParameter->Output.ClosestObj_Dist_Max, "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Ang,     pHlafMatrixParameter->Output.ClosestObj_Ang_Min,  "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Dist,      pHlafMatrixParameter->Output.MinLight_Dist_Max,   "%.3f", "It should be at allowed maximum.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Ang,       pHlafMatrixParameter->Output.MinLight_Ang_Min,    "%.3f", "It should be at allowed minimum.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left,              0.0f,                                                     "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left_Status,       RTE_HLAF_TTBSTA_NO_OBJ,                                   "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right,             0.0f,                                                     "TTB should be zero.");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right_Status,      RTE_HLAF_TTBSTA_NO_OBJ,                                   "TTB status should be \"off\".");
  COU_ASSERT_EQUAL(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[0].ExistenceProb,          100u,                                                     "Existence probability should be 100 percent.");

  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].BndryLeft_Ang,      dummyFloat,                                       "%.3f", "First element of second GFA Second GFA should not have been touched.");
  COU_ASSERT_EQUAL_FMT(ProPorts.pHlaf_HeadlightControl->Matrix.GFA[1].ttb18Left,          dummyFloat,                                       "%.3f", "Second GFA should not have been touched.");

}

/** \test
 *  \description
 *     Test of static HLAF_CopySortedMatrixData(). . \n
 *  \precondition
 *     Valid pointers in request port lists. \n
 *  \result
 *     Valid data in matrix part of headlight control provide port. \n
 */
TEST_Hlaf_CopySortedMatrixData(Hlaf_CopySortedMatrixData, "Call of HLAF_CopySortedMatrixData")
{
  /* Define test data */
  RTE_HLAF_Matrix_t    MatrixIn;
  RTE_HLA_TrafficStyle TrafficStyle;
  RTE_HLAF_Matrix_t    MatrixOut;

  /* Initialize input data */
  memset(&MatrixIn, 0, sizeof(MatrixIn));
  memset(&MatrixOut, 0, sizeof(MatrixOut));

  /* Set input data */
  COU_SET(MatrixIn.nGFA,  5, "5 GFA areas");
  COU_SET(MatrixIn.GFA[0].BndryLeft_Ang, 0.2f, "Set angle");
  COU_SET(MatrixIn.GFA[1].BndryLeft_Ang, -0.2f, "Set angle");
  COU_SET(MatrixIn.GFA[2].BndryLeft_Ang, 0.1f, "Set angle");
  COU_SET(MatrixIn.GFA[3].BndryLeft_Ang, 0.5f, "Set angle");
  COU_SET(MatrixIn.GFA[4].BndryLeft_Ang, -0.1f, "Set angle");

  /****************************************
   * Test case when GFA shall be sorted from left to right
   ****************************************/
  /* Call function under test */
  COU_CALL(HLAF_CopySortedMatrixData(&MatrixIn, &MatrixOut), "call of function");

  /* GFA from left to right -> 3, 0, 2, 4, 1 */
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[0].BndryLeft_Ang, MatrixIn.GFA[3].BndryLeft_Ang, "%.2f", "GFAs are correctly sorted");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[1].BndryLeft_Ang, MatrixIn.GFA[0].BndryLeft_Ang, "%.2f", "GFAs are correctly sorted");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[2].BndryLeft_Ang, MatrixIn.GFA[2].BndryLeft_Ang, "%.2f", "GFAs are correctly sorted");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[3].BndryLeft_Ang, MatrixIn.GFA[4].BndryLeft_Ang, "%.2f", "GFAs are correctly sorted");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[4].BndryLeft_Ang, MatrixIn.GFA[1].BndryLeft_Ang, "%.2f", "GFAs are correctly sorted");

  /****************************************
   * Test case that no GFA data is copied in case of nGFA is zero
   ****************************************/
  COU_SET(MatrixIn.nGFA,  0, "no GFA areas");
  memset(&MatrixOut, 0, sizeof(MatrixOut));
  /* Call function under test */
  COU_CALL(HLAF_CopySortedMatrixData(&MatrixIn, &MatrixOut), "call of function");

  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[0].BndryLeft_Ang, 0.0f, "%.2f", "No GFA data copied");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[1].BndryLeft_Ang, 0.0f, "%.2f", "No GFA data copied");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[2].BndryLeft_Ang, 0.0f, "%.2f", "No GFA data copied");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[3].BndryLeft_Ang, 0.0f, "%.2f", "No GFA data copied");
  COU_ASSERT_EQUAL_FMT(MatrixOut.GFA[4].BndryLeft_Ang, 0.0f, "%.2f", "No GFA data copied");
}

/** list of all test methods of the related suite. */
cou_test_t hlaf[] = {
   COU_ADD_TEST(Hlaf_Init),
   COU_ADD_TEST(Hlaf_Exec),
   COU_ADD_TEST(Hlaf_FillData),
   COU_ADD_TEST(Hlaf_FillOutputData),
   COU_ADD_TEST(Hlaf_FillOutputDataMatrixBeam),
   COU_ADD_TEST(Hlaf_CopySortedMatrixData),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(HlafInit, "Initialize Hlaf Unit")
{
  COU_LOG("Set Inputs to zero");
  InitHlafInputs();
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Hlaf, hlaf, HlafInit, "Module tests for hlaf main functions."),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
