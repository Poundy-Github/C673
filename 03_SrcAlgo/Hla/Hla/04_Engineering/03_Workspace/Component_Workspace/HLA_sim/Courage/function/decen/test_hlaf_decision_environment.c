/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>

/* inclue for decision environment */
#include <hlaf_decision_environment.h>
#include <HLA_DecisionParameters.h>

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_HLAFDecisionEnv_Weather COU_TEST
#define TEST_HLAFDecisionEnv_City COU_TEST
#define TEST_HLAFDecisionEnv_Speed COU_TEST
#define test_HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoi_FlagIsSet COU_TEST
#define test_HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoi_FlagIsSet COU_TEST
#define test_HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTurnOffReasonIsSet_NoFlagIsSet COU_TEST
#define test_HLAFDecisionEnv_SceneInfo_OncomingInsideTheRoi_FlagIsNotSet COU_TEST
#define test_HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTooFarAway_FlagIsNotSet COU_TEST
#define test_HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoiTooFar_FlagIsNotSet COU_TEST

void InitDecisionWeatherInputs(void);
void InitCityInputs(void);

CB_t_ProvidedOutputs_t                sig_blockage;
WiperStage_t                          wiper_stage;
HLAFCameraData_t                      cam_data;
HLAWeatherData_t                      weather_data;
RTE_HLAR_WeatherState                 weather_state;
LSD_e_EnvironmentData_CityState       city_state;
LSD_e_EnvironmentData_BrightnessState brightness_state;
t_DecisionParametersCity              city_parameters;
HLAFData_t                            hlaf_data;
RTE_HLAR_CityState                    rte_city_state;
VehDyn_t                              veh_dyn_data;
VehSig_t                              veh_sig_data;
RTE_HLAF_ParameterSpeed_t             rte_hlaf_speed_parameter;
float32                               dT;
HLAFSpeed_t                           speed_data;
uint8                                 num_rel_obj;

t_DecisionParametersSceneInfo         SceneInfoParameters;
HLAFMatrixOut_t                       OutNext;
LSD_LightObjectList_t                 ObjectList;
RTE_HLA_SceneInfo                     SceneInfo;

void InitSceneInfoInputs(void)
{
  memset(&hlaf_data, 0, sizeof(hlaf_data));
  memset(&SceneInfoParameters, 0, sizeof(SceneInfoParameters));
  memset(&OutNext, 0, sizeof(OutNext));
  memset(&ObjectList, 0, sizeof(ObjectList));
  memset(&SceneInfo, 0, sizeof(SceneInfo));
}

void InitDecisionWeatherInputs(void)
{
  // init structures
  memset(&sig_blockage,   0, sizeof(sig_blockage));
  memset(&cam_data,       0, sizeof(cam_data));
  memset(&weather_data,   0, sizeof(weather_data));
  memset(&weather_state,  0, sizeof(weather_state));

  // init wiper stage
  wiper_stage = VEH_SIG_ADD_WIPER_OFF;

  // set usual dTime in cam_data
  cam_data.dtime_s = 0.06f;
}

/** \test
 *  \description
 *     Test that based on weather reported from camera blockage the visibility is reduced. \n
 *     calls no other functions \n
 *  \precondition
 *     CB_t_ProvidedOutputs_t initialized and set \n
 *  \result
 *     RTE_HLAR_WeatherState set. \n 
 */
TEST_HLAFDecisionEnv_Weather(WeatherTest, "Test that the weather dependent visibility calculation is correct")
{
  //Init inputs needed for weather decisison
  InitDecisionWeatherInputs();

  // ------------------------------------------------------------------
  // case 1.01: weather is heavy fog, wiper is not to be considered
  // expected output: weather heavy fog
  // modify input
  sig_blockage.ui8_WeatherCondition = GB_HEAVY_FOG;
  // reset output
  weather_state = RTE_HLAR_WEATHER_INVALID;

  // call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_HEAVY_FOG, "Weather switches to heavy fog");


  // ------------------------------------------------------------------
  // case 1.02: weather is fog, wiper is not to be considered
  // expected output: weather good
  // modify input
  sig_blockage.ui8_WeatherCondition = GB_FOG;
  // reset output
  weather_state = RTE_HLAR_WEATHER_INVALID;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_GOOD, "Weather switches to good");


  // ------------------------------------------------------------------
  // case 1.03: weather is heavy snow, wiper is not to be considered
  // expected output: weather good
  // modify input
  sig_blockage.ui8_WeatherCondition = GB_HEAVY_RAIN_SNOW;
  // reset output
  weather_state = RTE_HLAR_WEATHER_INVALID;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_BAD, "Weather switches to bad");


  // ------------------------------------------------------------------
  // case 1.04: weather is rain, wiper is not to be considered
  // expected output: weather good
  // modify input
  sig_blockage.ui8_WeatherCondition = GB_RAIN;
  // reset output
  weather_state = RTE_HLAR_WEATHER_INVALID;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_GOOD, "Weather switches to good");


  // ------------------------------------------------------------------
  // case 2.01: weather is unknown, wiper is set to high for first time
  // expected output: weather good
  //                  increment of wiper time (in weather data)
  // reset weather condition
  sig_blockage.ui8_WeatherCondition = 0;
  // modify input
  weather_data.wiperStageTime = 0.0f;
  wiper_stage = VEH_SIG_ADD_WIPER_STAGE2;
  // reset output
  weather_state = RTE_HLAR_WEATHER_INVALID;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_GOOD, "Weather switches to good");
  COU_ASSERT_EQUAL_FMT(weather_data.wiperStageTime, 0.06f, "%.4f", "Wiper time has been increased");
  COU_ASSERT_EQUAL(weather_data.wiperStageUsed, FALSE, "Wiper indicator has not been set");


  // ------------------------------------------------------------------
  // case 2.02: weather is unknown, wiper is set to high for 9.95 s
  // expected output: weather bad
  //                  increment of wiper time (in weather data)
  //                  wiper indicator set (in weather data)
  // modify input
  weather_data.wiperStageTime = 9.95f;
  // reset output
  weather_state = RTE_HLAR_WEATHER_INVALID;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_BAD, "Weather switches to bad");
  COU_ASSERT_EQUAL_FMT(weather_data.wiperStageTime, 0.0f, "%.4f", "Wiper time has been increased");
  COU_ASSERT_EQUAL(weather_data.wiperStageUsed, TRUE, "Wiper indicator has been set");


  // ------------------------------------------------------------------
  // case 2.03: weather is bad, wiper setting has not been changed
  // expected output: weather bad
  //                  wiper time reset (in weather data)
  //                  wiper indicator still set (in weather data)
  // modification of input not needed

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_BAD, "Weather is set to bad");
  COU_ASSERT_EQUAL_FMT(weather_data.wiperStageTime, 0.0f, "%.4f", "Wiper time has been reset");
  COU_ASSERT_EQUAL(weather_data.wiperStageUsed, TRUE, "Wiper indicator is still set");


  // ------------------------------------------------------------------
  // case 2.04: weather is bad, wiper is set to low for first time
  // expected output: weather bad
  //                  increment of wiper time (in weather data)
  //                  wiper indicator still set (in weather data)
  // modify input
  wiper_stage = VEH_SIG_ADD_WIPER_INTERVAL2;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_BAD, "Weather is set to bad");
  COU_ASSERT_EQUAL_FMT(weather_data.wiperStageTime, 0.06f, "%.4f", "Wiper time has been increased");
  COU_ASSERT_EQUAL(weather_data.wiperStageUsed, TRUE, "Wiper indicator is still set");


  // ------------------------------------------------------------------
  // case 2.05: weather is bad, wiper is set to low for 59.95 s
  // expected output: weather good
  //                  increment of wiper time (in weather data)
  //                  wiper indicator reset (in weather data)
  // modify input
  weather_data.wiperStageTime = 59.95f;

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_GOOD, "Weather is set to bad");
  COU_ASSERT_EQUAL_FMT(weather_data.wiperStageTime, 0.0f, "%.4f", "Wiper time has been increased");
  COU_ASSERT_EQUAL(weather_data.wiperStageUsed, FALSE, "Wiper indicator is reset");


  // ------------------------------------------------------------------
  // case 2.06: weather is good, wiper setting has not been changed
  // expected output: weather good
  //                  reset of wiper time (in weather data)
  //                  wiper indicator not set (in weather data)
  // modification of input not neede

  //call test
  COU_CALL(HLAFDecisionEnv_Weather(&sig_blockage, &wiper_stage, &cam_data, &weather_data, &weather_state), "call of function");
  COU_ASSERT_EQUAL(weather_state, RTE_HLAR_WEATHER_GOOD, "Weather is set to bad");
  COU_ASSERT_EQUAL_FMT(weather_data.wiperStageTime, 0.00f, "%.4f", "Wiper time has been increased");
  COU_ASSERT_EQUAL(weather_data.wiperStageUsed, FALSE, "Wiper indicator is reset");
}

void InitCityInputs(void)
{
   memset(&city_state, 0, sizeof(city_state));
   memset(&brightness_state, 0, sizeof(brightness_state));
   memset(&city_parameters, 0, sizeof(city_parameters));
   memset(&hlaf_data, 0, sizeof(hlaf_data));
   memset(&rte_city_state, 0, sizeof(rte_city_state));
}

/** \test
  * \description
  *    Decision of the internal city state. \n
  *    Calls no other functions. \n
  * \precondition
  *    City detection was executed \n
  * \result
  *    RTE_HLAR_CityState and HLAFData_t updated. \n 
  */
 TEST_HLAFDecisionEnv_City(DecisionEnv_City_Test, "Tests that the city state is set correctly")
 {
   // init city inputs
   InitCityInputs();

   // current state: city idle

   // expected output: city switches to city detected
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_DTCD, "output switches to city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_DETECTED, "city state switches to city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 0, "dist in city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 0, "time in city reset");

   // expected output: city stays at city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "stays at city idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 0, "dist in city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 0, "time in city reset");

   // expected output: city switches to city maybe
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_MAYBE, "output switches to city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE, "city state switches to city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 0, "dist in city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 0, "time in city reset");

   // expected output: city stays at idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 0, "dist in city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 0, "time in city reset");

   // expected output: city stays at idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 0, "dist in city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 0, "time in city reset");

   // current state: city maybe

   // expected output: city switches to city detected
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_DTCD, "output switches to city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_DETECTED, "city state switches to city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 0, "dist in city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 0, "time in city reset");

   // expected output: city switches to city detected
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_MAYBE, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE, "city state stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city stays at city maybe
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.maxMayBeCityDist_m = 6;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_MAYBE, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE, "city state stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city switches to city maybe wait for idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.maxMayBeCityDist_m = 3;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE_WAIT4IDLE, "city state switches to city maybe wait for idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minMayBeCityDist_m = 3;
      city_parameters.minMayBeCityTime_s = 3;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 0;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minMayBeCityDist_m = 3;
      city_parameters.minMayBeCityTime_s = 3;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city stays at city maybe
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 256;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minMayBeCityDist_m = 3;
      city_parameters.minMayBeCityTime_s = 3;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_MAYBE, "output stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE, "city state stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city stays at city maybe
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 256;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minMayBeCityDist_m = 3;
      city_parameters.minMayBeCityTime_s = 6;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_MAYBE, "output stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE, "city state stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city stays at city maybe
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 256;
      //init output
      rte_city_state = RTE_HLAR_CITY_MAYBE;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minMayBeCityDist_m = 6;
      city_parameters.minMayBeCityTime_s = 3;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_MAYBE, "output stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE, "city state stays at city maybe");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // current state: city maybe wait for idle

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE_WAIT4IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE_WAIT4IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // expected output: city stays in city maybe wait for idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_MAYBE_WAIT4IDLE;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_NOT_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output stays at city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_MAYBE_WAIT4IDLE, "city state stays at city maybe wait for idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 5, "dist in city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 5, "dist outside city not touched");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 5, "time in city not touched");

   // current state: city detected

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_DETECTED;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minCityDist_m = 3;
      city_parameters.minCityTime_s = 3;
      hlaf_data.CamData.ddistFwd_m = 1;
      hlaf_data.CamData.dtimeFwd_s = 1;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output switches to city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 6, "dist in city increased");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 6, "dist outside city increased");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 6, "time in city increased");

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_DETECTED;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 0;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minCityDist_m = 3;
      city_parameters.minCityTime_s = 3;
      hlaf_data.CamData.ddistFwd_m = 1;
      hlaf_data.CamData.dtimeFwd_s = 1;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output switches to city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 6, "dist in city increased");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 6, "dist outside city increased");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 6, "time in city increased");

   // expected output: city stays at city detected, time and distance counters increased, dist outside city reset
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_DETECTED;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minCityDist_m = 7;
      city_parameters.minCityTime_s = 7;
      hlaf_data.CamData.ddistFwd_m = 1;
      hlaf_data.CamData.dtimeFwd_s = 1;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_DTCD, "output stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_DETECTED, "city state stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 6, "dist in city incremented");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 6, "time in city incremented");

   // expected output: city stays at city detected, time and distance counters increased, dist outside city reset
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_DETECTED;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 256;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minCityDist_m = 3;
      city_parameters.minCityTime_s = 3;
      hlaf_data.CamData.ddistFwd_m = 1;
      hlaf_data.CamData.dtimeFwd_s = 1;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_DTCD, "output stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_DETECTED, "city state stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 6, "dist in city incremented");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 6, "time in city incremented");

   // expected output: city stays at city detected, time and distance counters increased, dist outside city reset
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_DETECTED;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 0;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minCityDist_m = 7;
      city_parameters.minCityTime_s = 3;
      hlaf_data.CamData.ddistFwd_m = 1;
      hlaf_data.CamData.dtimeFwd_s = 1;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_DTCD, "output stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_DETECTED, "city state stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 6, "dist in city incremented");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 6, "time in city incremented");

   // expected output: city stays at city detected, time and distance counters increased, dist outside city reset
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_DETECTED;
      city_state = LSD_ENVIRONMENT_DATA_CITY_STATE_NONE;
      brightness_state = LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY;
      hlaf_data.DecisionData.TurnOffReason.Reason = 0;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;
      hlaf_data.DecisionData.City.distInCity_m = 5;
      hlaf_data.DecisionData.City.distOutCity_m = 5;
      hlaf_data.DecisionData.City.timeInCity_s = 5;
      city_parameters.minCityDist_m = 3;
      city_parameters.minCityTime_s = 7;
      hlaf_data.CamData.ddistFwd_m = 1;
      hlaf_data.CamData.dtimeFwd_s = 1;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_DTCD, "output stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_DETECTED, "city state stays at city detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distInCity_m, 6, "dist in city incremented");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.distOutCity_m, 0, "dist outside city reset");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.timeInCity_s, 6, "time in city incremented");

   // current state: city last

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = HLAF_CITY_LAST;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output switches to city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");

   // expected output: city switches to city idle
      //init input
      hlaf_data.DecisionData.City.eCityState = 30;
      //init output
      rte_city_state = RTE_HLAR_CITY_DTCD;

      //call test
      COU_CALL(HLAFDecisionEnv_City(city_state, brightness_state, &city_parameters, &hlaf_data, &rte_city_state), "call of function");
      COU_ASSERT_EQUAL(rte_city_state, RTE_HLAR_CITY_NOT_DTCD, "output switches to city not detected");
      COU_ASSERT_EQUAL(hlaf_data.DecisionData.City.eCityState, HLAF_CITY_IDLE, "city state switches to idle");
 }


 void InitSpeedInputs(void)
 {
    memset(&veh_dyn_data, 0, sizeof(veh_dyn_data));
    memset(&veh_sig_data, 0, sizeof(veh_sig_data));
    memset(&rte_hlaf_speed_parameter, 0, sizeof(rte_hlaf_speed_parameter));
    memset(&speed_data, 0, sizeof(speed_data));
    dT = 0;
    num_rel_obj = 0;
 }

/** \test
  *  \description
  *    Tests the current speed and motion state against various parameter based thresholds to determine if HLA is allowed to operate.  \n
  *     Calls no other functions. \n
  *  \precondition
  *     - \n
  *  \result
  *     RTE_HLAR_CityState and HLAFData_t updated. \n
  */
TEST_HLAFDecisionEnv_Speed(DecisionEnv_Speed_Test, "Tests if HLA is allowed to operate depending on speed, motion state and parameters")
{
    // init city inputs
    InitSpeedInputs();

    // expected output: internal speed state always active
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.AlwaysActiveSpeed = 10;

       //init output
       speed_data.state = SPEED_STATE_LOW;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_ALWAYSACTIVE, "output switches to speed state always active");

    // expected output: internal speed state always active
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
       rte_hlaf_speed_parameter.AlwaysActiveSpeed = 10;

       //init output
       speed_data.state = SPEED_STATE_LOW;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_LOW, "output switches to speed state always active");

       //init input global for next tests
       rte_hlaf_speed_parameter.AlwaysActiveSpeed = 100;

       // expected output: internal speed state high, penalty timer set
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.ActivateSpeed = 10;
       speed_data.state = SPEED_STATE_LOW;
       speed_data.keepOffEvents.u32 = 5;

       //init output
       speed_data.activatePenaltyTimer = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_HIGH, "output switches to speed state high");
       COU_ASSERT_EQUAL(speed_data.activatePenaltyTimer, rte_hlaf_speed_parameter.KeepOff_Delay, "penalty timer set to keep off delay");

    // expected output: internal speed state high, penalty timer reset
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.ActivateSpeed = 10;
       speed_data.state = SPEED_STATE_LOW;
       speed_data.keepOffEvents.u32 = 0;

       //init output
       speed_data.activatePenaltyTimer = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_HIGH, "output switches to speed state high");
       COU_ASSERT_EQUAL(speed_data.activatePenaltyTimer, 0, "penalty timer reset");

    // expected output: internal speed state high, penalty timer untouched
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.ActivateSpeed = 10;
       speed_data.state = SPEED_STATE_ALWAYSACTIVE;

       //init output
       speed_data.activatePenaltyTimer = 5;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_HIGH, "output switches to speed state high");
       COU_ASSERT_EQUAL(speed_data.activatePenaltyTimer, 5, "penaltiy timer untouched");

    // expected output: internal speed state low, penalty timer not touched
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 20;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.DeactivateSpeed = 10;

       //init output
       speed_data.state = SPEED_STATE_HIGH;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_LOW, "output switches to speed state low");

    // expected output: internal speed state high, penalty timer not touched
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.DeactivateSpeed = 10;
       rte_hlaf_speed_parameter.ActivateSpeed = 20;

       //init output
       speed_data.state = SPEED_STATE_HIGH;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_HIGH, "output stays at state high");

       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
       rte_hlaf_speed_parameter.DeactivateSpeed = 10;

       //init output
       speed_data.state = SPEED_STATE_HIGH;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_LOW, "output switches to speed state low");

       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.DeactivateSpeed = 10;

       //init output
       speed_data.state = SPEED_STATE_HIGH;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.state, SPEED_STATE_HIGH, "output stays at high");

       //init input once for the next tests
       speed_data.state = SPEED_STATE_LOW;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD; // to keep speed state low

    //expected output: very slow keep off bit set
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       rte_hlaf_speed_parameter.KeepOff_VeryLowSpeed = 20;

       //init output
       speed_data.keepOffEvents.Bit.VerySlow = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.VerySlow, 1, "output bit is set");

    //expected output: very slow keep off bit not set
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       rte_hlaf_speed_parameter.KeepOff_VeryLowSpeed = 10;

       //init output
       speed_data.keepOffEvents.Bit.VerySlow = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.VerySlow, 0, "output bit is not set");

    //expected output: recent vehicle detection bit set
       //init input
       num_rel_obj = 1;

       //init output
       speed_data.keepOffEvents.Bit.RecentVehicleDetection = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.RecentVehicleDetection, 1, "output bit is set");

    //expected output: recent vehicle detection bit not set
       //init input
       num_rel_obj = 0;

       //init output
       speed_data.keepOffEvents.Bit.RecentVehicleDetection = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.RecentVehicleDetection, 0, "output bit is not set");

    //expected output: high curvature bit set
       //init input
       rte_hlaf_speed_parameter.KeepOff_LowRadius = 1;
       veh_dyn_data.Lateral.Curve.Curve = 5; //radius = 1/5


       //init output
       speed_data.keepOffEvents.Bit.HighCurvature = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighCurvature, 1, "output bit is set");

    //expected output: high curvature bit not set
       //init input
       rte_hlaf_speed_parameter.KeepOff_LowRadius = 1;
       veh_dyn_data.Lateral.Curve.Curve = 1; //radius = 1


       //init output
       speed_data.keepOffEvents.Bit.HighCurvature = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighCurvature, 0, "output bit is not set");

    //expected output: high acceleration keep off bit set
       //init input
       rte_hlaf_speed_parameter.KeepOff_HighAcceleration = 10;
       veh_dyn_data.Longitudinal.Accel = 15;
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;

       //init output
       speed_data.keepOffEvents.Bit.HighAcceleration = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighAcceleration, 1, "output bit is set");

    //expected output: high acceleration keep off bit not set
       //init input
       rte_hlaf_speed_parameter.KeepOff_HighAcceleration = 10;
       veh_dyn_data.Longitudinal.Accel = 5;
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;

       //init output
       speed_data.keepOffEvents.Bit.HighAcceleration = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighAcceleration, 0, "output bit is not set");

    //expected output: high acceleration keep off bit not set
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 1;

       //init output
       speed_data.keepOffEvents.Bit.HighAcceleration = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighAcceleration, 0, "output bit is not set");

    //expected output: disable hla by speed flag set
       //init input

       //init output
       speed_data.disableHLABySpeed = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.disableHLABySpeed, 1, "output bit is set");

    //init input once for the next tests
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       veh_dyn_data.MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
       rte_hlaf_speed_parameter.ActivateSpeed = 10;
       speed_data.state = SPEED_STATE_ALWAYSACTIVE;

    //expected output: penalty timer decreased
       //init input
       dT = 1;

       //init output
       speed_data.activatePenaltyTimer = 10;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.activatePenaltyTimer, 9, "penalty timer decreased");

    //expected output: penalty timer decreased
       //init input
       speed_data.activatePenaltyTimer = -1;

       //init output
       speed_data.keepOffHLABySpeed = 1;
       speed_data.keepOffEvents.Bit.HighAcceleration = 1;
       speed_data.keepOffEvents.Bit.HighCurvature = 1;
       speed_data.keepOffEvents.Bit.RecentVehicleDetection = 1;
       speed_data.keepOffEvents.Bit.VerySlow = 1;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighAcceleration, 0, "high acceleration bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighCurvature, 0, "high curvature bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.RecentVehicleDetection, 0, "recent vehicle detection bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.VerySlow, 0, "very slow bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffHLABySpeed, 0, "keep off HLA by speed reset");

    //expected output: penalty timer reset
       //init input
       veh_dyn_data.Longitudinal.Accel = -5;
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       rte_hlaf_speed_parameter.ActivateSpeed = 12;

       //init output
       speed_data.activatePenaltyTimer = 1;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.activatePenaltyTimer, 0, "penalty timer reset");

    //expected output: disable hla by speed flag unset, keep off events removed
       //init input
       speed_data.state = SPEED_STATE_ALWAYSACTIVE;

       //init output
       speed_data.keepOffHLABySpeed = 1;
       speed_data.keepOffEvents.Bit.HighAcceleration = 1;
       speed_data.keepOffEvents.Bit.HighCurvature = 1;
       speed_data.keepOffEvents.Bit.RecentVehicleDetection = 1;
       speed_data.keepOffEvents.Bit.VerySlow = 1;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighAcceleration, 0, "high acceleration bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.HighCurvature, 0, "high curvature bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.RecentVehicleDetection, 0, "recent vehicle detection bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffEvents.Bit.VerySlow, 0, "very slow bit reset");
       COU_ASSERT_EQUAL(speed_data.keepOffHLABySpeed, 0, "keep off HLA by speed reset");

    //expected output: keep off HLA by speed flag set
       //init input
       veh_dyn_data.Longitudinal.Accel = -5;
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       rte_hlaf_speed_parameter.ActivateSpeed = 12;
       rte_hlaf_speed_parameter.KeepOff_AccTime = 10;

       //init output
       speed_data.keepOffHLABySpeed = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffHLABySpeed, 1, "disable HLA by speed flag set");

    //expected output: keep off HLA by speed flag unset
       //init input
       veh_dyn_data.Longitudinal.Accel = 10;
       veh_sig_data.VehSigAdd.SpeedoSpeed = 50;
       rte_hlaf_speed_parameter.ActivateSpeed = 12;

       //init output
       speed_data.keepOffHLABySpeed = 0;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.keepOffHLABySpeed, 0, "disable HLA by speed flag not set");

     //expected output: disable HLA by high speed flag set
       //init input
       veh_sig_data.VehSigAdd.SpeedoSpeed = 30;
       rte_hlaf_speed_parameter.ActivateSpeedHigh = 20;

       //init output
       speed_data.disableHLAByHighSpeed = 1;

       //call test
       COU_CALL(HLAFDecisionEnv_Speed(&veh_dyn_data, &veh_sig_data, &rte_hlaf_speed_parameter, dT, &speed_data, num_rel_obj), "call of function");
       COU_ASSERT_EQUAL(speed_data.disableHLAByHighSpeed, 0, "disable HLA by high speed flag unset");
}

/** \test
 *  \description
 *     Test that the oncoming passing flag is set when an oncoming has left the ROI. \n
 *     calls function HLAFDecisionEnv_SceneInfo() \n
 *  \precondition
 *     None \n
 *  \result
 *     RTE_HLA_SCENEINFO_ONCOMING_PASSING is set. \n 
 */
test_HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoi_FlagIsSet(HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoi_FlagIsSet, "Tests if leaving oncoming leads to correct scene info flag")
{
  /* Init inputs */
  InitSceneInfoInputs();
  SceneInfoParameters.distanceOncoming = 100.0f;
  SceneInfoParameters.distancePreceding = 50.0f;

  LSD_LightObject_t LightObject;
  memset(&LightObject, 0, sizeof(LightObject));

  hlaf_data.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Set ROI data */
  ObjectList.roi.x1 = 40;
  ObjectList.roi.x2 = 400;

  /* No turn off reason is set */
  OutNext.Matrix.TurnOffReason = 0;

  /* one relevant object */
  hlaf_data.hlafMatrixData.numRelObj = 1;

  /* light is outside of ROI */
  LightObject.kinematic.camera.x = 5;
  /* object is close */
  LightObject.kinematic.world.x = 5.0f;

  /* relevant oncoming */
  hlaf_data.hlafMatrixData.Object[0].bIsRelevantOnc = b_TRUE;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_ONCOMING_PASSING, "oncoming passing was detected");
}

/** \test
 *  \description
 *     Tests if leaving oncoming too far away leads to flag not set. \n
 *     calls function HLAFDecisionEnv_SceneInfo() \n
 *  \precondition
 *     None \n
 *  \result
 *     RTE_HLA_SCENEINFO_UNKNOWN is set. \n
 */
test_HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoiTooFar_FlagIsNotSet(HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoiTooFar_FlagIsNotSet, "Tests if leaving oncoming too far away leads to flag not set")
{
  /* Init inputs */
  InitSceneInfoInputs();
  SceneInfoParameters.distanceOncoming = 100.0f;
  SceneInfoParameters.distancePreceding = 50.0f;

  LSD_LightObject_t LightObject;
  memset(&LightObject, 0, sizeof(LightObject));

  hlaf_data.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Set ROI data */
  ObjectList.roi.x1 = 40;
  ObjectList.roi.x2 = 400;

  /* No turn off reason is set */
  OutNext.Matrix.TurnOffReason = 0;

  /* one relevant object */
  hlaf_data.hlafMatrixData.numRelObj = 1;

  /* light is outside of ROI */
  LightObject.kinematic.camera.x = 5;
  /* object too far away */
  LightObject.kinematic.world.x = SceneInfoParameters.distanceOncoming + 5.0f;

  /* relevant oncoming */
  hlaf_data.hlafMatrixData.Object[0].bIsRelevantOnc = b_TRUE;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "oncoming passing was not detected");
}

/** \test
 *  \description
 *     Test tif leaving preceding leads to correct scene info flag. \n
 *     calls function HLAFDecisionEnv_SceneInfo() \n
 *  \precondition
 *     None \n
 *  \result
 *     RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING is set. \n 
 */
test_HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoi_FlagIsSet(HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoi_FlagIsSet, "Tests if leaving preceding leads to correct scene info flag")
{
  /* Init inputs */
  InitSceneInfoInputs();
  SceneInfoParameters.distanceOncoming = 100.0f;
  SceneInfoParameters.distancePreceding = 50.0f;

  LSD_LightObject_t LightObject;
  memset(&LightObject, 0, sizeof(LightObject));

  hlaf_data.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Set ROI data */
  ObjectList.roi.x1 = 40;
  ObjectList.roi.x2 = 400;

  /* No turn off reason is set */
  OutNext.Matrix.TurnOffReason = 0;

  /* one relevant object */
  hlaf_data.hlafMatrixData.numRelObj = 1;

  /* light is outside of ROI */
  LightObject.kinematic.camera.x = 5;
  /* object is close */
  LightObject.kinematic.world.x = 5.0f;

  /* relevant preceding */
  hlaf_data.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING, "preceding overtaking was detected");
}

/** \test
 *  \description
 *     Tests that nothing is set in case of active preceding turn off reason. \n
 *     calls function HLAFDecisionEnv_SceneInfo() \n
 *  \precondition
 *     None \n
 *  \result
 *     RTE_HLA_SCENEINFO_UNKNOWN is set. \n 
 */
test_HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTurnOffReasonIsSet_NoFlagIsSet(HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTurnOffReasonIsSet_NoFlagIsSet, "Tests that nothing is set in case of active preceding turn off reason")
{
  /* Init inputs */
  InitSceneInfoInputs();
  SceneInfoParameters.distanceOncoming = 100.0f;
  SceneInfoParameters.distancePreceding = 50.0f;

  LSD_LightObject_t LightObject;
  memset(&LightObject, 0, sizeof(LightObject));

  hlaf_data.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Set ROI data */
  ObjectList.roi.x1 = 40;
  ObjectList.roi.x2 = 400;

  /* Preceding turn off reason is set */
  OutNext.Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_PREC;

  /* one relevant object */
  hlaf_data.hlafMatrixData.numRelObj = 1;

  /* light is inside of ROI */
  LightObject.kinematic.camera.x = 5;
  /* object is close */
  LightObject.kinematic.world.x = 5.0f;

  /* relevant oncoming */
  hlaf_data.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "nothing was set");

  /* -- Second test with oncoming as turn off reason */

  /* Oncoming turn off reason is set */
  OutNext.Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_ONC;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "nothing was set");


}

/** \test
 *  \description
 *     Test that the oncoming passing flag is not set when still inside the ROI. \n
 *     calls function HLAFDecisionEnv_SceneInfo() \n
 *  \precondition
 *     None \n
 *  \result
 *     RTE_HLA_SCENEINFO_UNKNOWN is set. \n
 */
test_HLAFDecisionEnv_SceneInfo_OncomingInsideTheRoi_FlagIsNotSet(HLAFDecisionEnv_SceneInfo_OncomingInsideTheRoi_FlagIsNotSet, "Test that the oncoming passing flag is not set when still inside the ROI")
{
  /* Init inputs */
  InitSceneInfoInputs();
  SceneInfoParameters.distanceOncoming = 100.0f;
  SceneInfoParameters.distancePreceding = 50.0f;

  LSD_LightObject_t LightObject;
  memset(&LightObject, 0, sizeof(LightObject));

  hlaf_data.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Set ROI data */
  ObjectList.roi.x1 = 40;
  ObjectList.roi.x2 = 400;

  /* No turn off reason is set */
  OutNext.Matrix.TurnOffReason = 0;

  /* one relevant object */
  hlaf_data.hlafMatrixData.numRelObj = 1;

  /* light is outside of ROI */
  LightObject.kinematic.camera.x = 50;
  /* object is close */
  LightObject.kinematic.world.x = 5.0f;

  /* relevant oncoming */
  hlaf_data.hlafMatrixData.Object[0].bIsRelevantOnc = b_TRUE;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "default value is set");
}

/** \test
 *  \description
 *     Test that the preceding passing flag is not set when an preceding has left the ROI, but is too far away. \n
 *     calls function HLAFDecisionEnv_SceneInfo() \n
 *  \precondition
 *     None \n
 *  \result
 *     RTE_HLA_SCENEINFO_UNKNOWN is set. \n
 */
test_HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTooFarAway_FlagIsNotSet(HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTooFarAway_FlagIsNotSet, "Tests  that the preceding passing flag is not set when an preceding has left the ROI, but is too far away")
{
  /* Init inputs */
  InitSceneInfoInputs();
  SceneInfoParameters.distanceOncoming = 100.0f;
  SceneInfoParameters.distancePreceding = 50.0f;

  LSD_LightObject_t LightObject;
  memset(&LightObject, 0, sizeof(LightObject));

  hlaf_data.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Set ROI data */
  ObjectList.roi.x1 = 40;
  ObjectList.roi.x2 = 400;

  /* No turn off reason is set */
  OutNext.Matrix.TurnOffReason = 0;

  /* one relevant object */
  hlaf_data.hlafMatrixData.numRelObj = 1;

  /* light is outside of ROI */
  LightObject.kinematic.camera.x = 5;
  /* object is too far away */
  LightObject.kinematic.world.x = SceneInfoParameters.distancePreceding + 10.0f;

  /* relevant preceding */
  hlaf_data.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;

  /* function call */
  COU_CALL(HLAFDecisionEnv_SceneInfo(&hlaf_data, &SceneInfoParameters, &OutNext, &ObjectList, &SceneInfo), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(SceneInfo, RTE_HLA_SCENEINFO_UNKNOWN, "default value is set");
}

// /** list of all test methods of the related suite. */
 cou_test_t hlaf_decisionEnvironment[] = {
    COU_ADD_TEST(WeatherTest),
    COU_ADD_TEST(DecisionEnv_City_Test),
    COU_ADD_TEST(DecisionEnv_Speed_Test),
    COU_ADD_TEST(HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoi_FlagIsSet),
    COU_ADD_TEST(HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoi_FlagIsSet),
    COU_ADD_TEST(HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTurnOffReasonIsSet_NoFlagIsSet),
    COU_ADD_TEST(HLAFDecisionEnv_SceneInfo_OncomingInsideTheRoi_FlagIsNotSet),
    COU_ADD_TEST(HLAFDecisionEnv_SceneInfo_PrecedingLeftTheRoiTooFarAway_FlagIsNotSet),
    COU_ADD_TEST(HLAFDecisionEnv_SceneInfo_OncomingLeftTheRoiTooFar_FlagIsNotSet),
    COU_ADD_TEST_END
 }; /* somehla */

// /**
 // * Called by testrunner directly before each of all tests of the suite.
 // * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 // * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 // */

 COU_INIT(DecisionEnvironmentInit, "Initialize Decision Environment")
 {
   //COU_CALL(HLA_ErrorHandling_Init(),"Initialize Error Handling");
 }

 cou_suite_t suites[] =
 {
    COU_ADD_SUITE(TestSuite_DecisionEnvironment, hlaf_decisionEnvironment, DecisionEnvironmentInit, "module test for decision environment"),
    COU_ADD_SUITE_END,
 }; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
