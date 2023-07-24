/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>

#include "hlaf_decision.h"
#include "hla_errorhandling.h"
#include "../../mockup_services.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_DecisionSetTurnOffReasonGlob_001 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_002 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_003 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_004 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_005 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_006 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_007 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_008 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_009 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_010 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_011 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_012 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_013 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_014 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_015 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_016 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_017 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_018 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_019 COU_TEST
#define TEST_DecisionSetTurnOffReasonGlob_020 COU_TEST
#define test_HLAFDecision_SetTurnOffReasonGlob_HeavyFogDetected_BadWeatherTurnOffReasonIsSet COU_TEST
#define test_HLAFDecision_SetTurnOffReasonGlob_MediumFogDetected_BadWeatherTurnOffReasonIsSet COU_TEST
#define test_HLAFDecision_SetTurnOffReasonGlob_BadWeatherDetected_BadWeatherTurnOffReasonIsSet COU_TEST
#define test_HLAFDecision_SetTurnOffReasonGlob_GoodWeatherDetected_BadWeatherTurnOffReasonIsNotSet COU_TEST
#define test_HLAFDecision_CheckForRelevantEMObjects_EMObjDetected_RelVehFlagIsSet COU_TEST
#define test_HLAFDecision_CheckForRelevantEMObjects_EMObjNotDetected_RelVehFlagIsNotSet COU_TEST
#define test_HLAFDecision_CheckForRelevantRadarObjects_RadarObjDetected_RelVehFlagIsSet COU_TEST
#define test_HLAFDecision_CheckForRelevantRadarObjects_RadarObjNotDetected_RelVehFlagIsNotSet COU_TEST
#define TEST_DecisionSetTurnOffReason_001 COU_TEST
#define TEST_DecisionSetTurnOffReason_002 COU_TEST
#define TEST_DecisionSetTurnOffReason_003 COU_TEST
#define TEST_DecisionSetTurnOffReason_004 COU_TEST
#define TEST_DecisionSetTurnOffReason_005 COU_TEST
#define TEST_DecisionSetTurnOffReason_006 COU_TEST
#define test_HLAFDecision_SetTurnOffReason_RadarObjDetected_TurnOffReasonSet COU_TEST
#define test_HLAFDecision_SetTurnOffReason_RadarObjNotDetected_NoTurnOffReasonSet COU_TEST
#define TEST_DecisionSetHBState_001 COU_TEST
#define TEST_DecisionSetHBState_002 COU_TEST
#define TEST_DecisionSetHBState_003 COU_TEST
#define TEST_DecisionSetHBState_004 COU_TEST
#define TEST_DecisionFindRelevantVehicle_001 COU_TEST
#define TEST_DecisionFindRelevantVehicle_002 COU_TEST
#define TEST_DecisionFindRelevantVehicle_003 COU_TEST
#define TEST_DecisionFindRelevantVehicle_004 COU_TEST
#define TEST_DecisionFindRelevantVehicle_005 COU_TEST
#define TEST_DecisionFindRelevantVehicle_006 COU_TEST
#define TEST_DecisionFindRelevantVehicle_007 COU_TEST
#define TEST_DecisionFindRelevantVehicle_008 COU_TEST
#define TEST_DecisionFindRelevantVehicle_009 COU_TEST
#define TEST_DecisionFindRelevantVehicle_010 COU_TEST
#define TEST_DecisionFindRelevantVehicle_011 COU_TEST
#define TEST_DecisionFindRelevantVehicle_012 COU_TEST
#define TEST_DecisionFindRelevantVehicle_013 COU_TEST
#define TEST_DecisionFindRelevantVehicle_014 COU_TEST
#define TEST_DecisionFindRelevantVehicle_015 COU_TEST
#define TEST_HLAFDecision_FindRelevantVehicle_ObjectIsBehindCar_PrecDetected COU_TEST
#define TEST_DecisionFindRelevantVehicle_016 COU_TEST
#define TEST_DecisionFindRelevantVehicle_017 COU_TEST
#define TEST_DecisionFindRelevantVehicle_018 COU_TEST
#define TEST_DecisionFindRelevantVehicle_019 COU_TEST
#define TEST_DecisionFindRelevantVehicle_020 COU_TEST
#define TEST_DecisionFindRelevantVehicle_021 COU_TEST
#define TEST_DecisionFindRelevantVehicle_022 COU_TEST
#define TEST_DecisionFindRelevantVehicle_023 COU_TEST
#define TEST_DecisionFindRelevantVehicle_024 COU_TEST
#define TEST_DecisionFindRelevantVehicle_025 COU_TEST
#define TEST_DecisionFindRelevantVehicle_026 COU_TEST
#define TEST_DecisionFindRelevantVehicle_027 COU_TEST
#define TEST_DecisionFindRelevantVehicle_028 COU_TEST
#define TEST_DecisionFindRelevantVehicle_029 COU_TEST
#define TEST_DecisionFindRelevantVehicle_030 COU_TEST
#define TEST_DecisionFindRelevantVehicle_031 COU_TEST
#define TEST_DecisionFindRelevantVehicle_032 COU_TEST
#define TEST_DecisionFindRelevantVehicle_033 COU_TEST
#define TEST_DecisionFindRelevantVehicle_034 COU_TEST
#define TEST_DecisionFindRelevantVehicle_035 COU_TEST
#define TEST_DecisionFindRelevantVehicle_036 COU_TEST
#define TEST_DecisionFindRelevantVehicle_037 COU_TEST
#define TEST_DecisionFindRelevantVehicle_038 COU_TEST
#define TEST_DecisionFindRelevantVehicle_039 COU_TEST
#define TEST_DecisionFindRelevantVehicle_040 COU_TEST

void InitData(void);
void CreateRelevantIntObject(HLAFData_t* pFData, boolean isOncoming);
void SetLightObjectList(LSD_LightObjectList_t* pLsdLightObjectList);
void SetCpars(CPAR_HLAF_Parameter_t* pCPar_HlafPar);

RTE_HLAR_BrightnessState   e_Brightness;
HLAFData_t                 FData;
HLAFTurnOffReason_t        TurnOffReason;
HLAFKeepOffReason_t        KeepOffReason;
HLAFRelevantVehicle_t      RelVeh;
RTE_HLAF_HighBeamState     eHighBeamStatePrev;
RTE_HLAF_HighBeamState     eHighBeamStateOut;
t_DecisionParameters       DecisionParameters;
HLAFMatrixData_t           MatrixData;

LSD_LightObject_t          LightObject;

/* Init function which memsets all of the input data and links the data buffer to the corresponding pointers */
void InitData(void)
{
  Mockup_InitGlobVars();

  memset(&e_Brightness, 0, sizeof(e_Brightness));
  memset(&FData, 0, sizeof(FData));
  memset(&TurnOffReason, 0, sizeof(TurnOffReason));
  memset(&KeepOffReason, 0, sizeof(KeepOffReason));
  memset(&RelVeh, 0, sizeof(RelVeh));
  memset(&eHighBeamStatePrev, 0, sizeof(eHighBeamStatePrev));
  memset(&eHighBeamStateOut, 0, sizeof(eHighBeamStateOut));
  memset(&DecisionParameters, 0, sizeof(DecisionParameters));
  memset(&MatrixData, 0, sizeof(MatrixData));

  LsdLightObjectList.numObjects = 0;

  HLA_ErrorHandling_Init();
  SetCpars(&CPar_HlafPar);
}

void CreateRelevantIntObject(HLAFData_t* pFData, boolean isOncoming)
{
  /* reset light object */
  memset(&LightObject, 0, sizeof(LightObject));

  /* set light object data */
  LightObject.kinematic.camera.x = 250;
  LightObject.kinematic.camera.y = 250;
  LightObject.kinematic.world.x = 20.0f;
  LightObject.kinematic.world.y = 10.0f;
  LightObject.kinematic.world.horizontalAngle = 0.03f;
  LightObject.kinematic.timeToHlaBorder = 3.0f;
  LightObject.attributes.intensity = 60;

  /* Create one relevant object */
  pFData->hlafMatrixData.numRelObj = 1;
  if(isOncoming == b_TRUE)
  {
    pFData->hlafMatrixData.Object[0].bIsRelevantOnc = b_TRUE;
  }
  else
  {
    pFData->hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  }

  /* set pointer to light object */
  pFData->hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* Increase counter in light object list */
  LsdLightObjectList.numObjects++;
}

void SetLightObjectList(LSD_LightObjectList_t* pLsdLightObjectList)
{
  pLsdLightObjectList->roi.x1 = 140;
  pLsdLightObjectList->roi.x2 = 1000;
  pLsdLightObjectList->roi.yVehicleSplit = 200;
  pLsdLightObjectList->roi.y2 = 440;
}

void SetCpars(CPAR_HLAF_Parameter_t* pCPar_HlafPar)
{
  pCPar_HlafPar->KeepOnDelay.distancePrecedingVehicleMin = 3000;
  pCPar_HlafPar->KeepOnDelay.distancePrecedingVehicleMax = 4000;
  pCPar_HlafPar->KeepOnDelay.distanceOncomingVehicle = 4000;

  pCPar_HlafPar->TurnOnDelay.OncomingMax = 1.5f;
  pCPar_HlafPar->TurnOnDelay.OncomingMinHighway = 1.0f;
  pCPar_HlafPar->TurnOnDelay.OncomingMaxHighway = 1.5f;
  pCPar_HlafPar->TurnOnDelay.OncomingMin = 0.6f;
  pCPar_HlafPar->TurnOnDelay.PrecedingMaxLong = 3.0f;
  pCPar_HlafPar->TurnOnDelay.PrecedingMaxShort = 3.0f;
  pCPar_HlafPar->TurnOnDelay.PrecedingMinWiperOn = 3.0f;
  pCPar_HlafPar->TurnOnDelay.PrecedingMin = 3.0f;

  pCPar_HlafPar->TurnOffDelay.precedingVehicle = 0.0f;
  pCPar_HlafPar->TurnOffDelay.oncomingVehicle  = 0.0f;

  DecisionParameters.LSDObjHorAngThreshold = 16.0f;
}

/** \test
 *  \description
 *     Test that turn off reason min speed is set, when the disableHLABySpeed bit is set.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_MIN_SPEED is set \n */
TEST_DecisionSetTurnOffReasonGlob_001(DecisionSetTurnOffReasonGlob_001, "Test that disableHLABySpeed bit leads to min speed turn off reason")
{
  /* Initialize Data */
  InitData();

  /* Turn off by speed bit is set */
  FData.DecisionData.Speed.disableHLABySpeed = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MIN_SPEED), b_TRUE, "Min speed turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason min speed is not set, when the disableHLABySpeed bit is not set.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_MIN_SPEED is not set \n */
TEST_DecisionSetTurnOffReasonGlob_002(DecisionSetTurnOffReasonGlob_002, "Test that if disableHLABySpeed bit is not set, that min speed turn off reason is also not set")
{
  /* Initialize Data */
  InitData();

  /* Turn off by speed bit is not set */
  FData.DecisionData.Speed.disableHLABySpeed = 0;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MIN_SPEED), b_FALSE, "Min speed turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason max speed is set, when the disableHLAByHighSpeed bit is set.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_MAX_SPEED is set \n */
TEST_DecisionSetTurnOffReasonGlob_003(DecisionSetTurnOffReasonGlob_003, "Test that disableHLAByHighSpeed bit leads to max speed turn off reason")
{
  /* Initialize Data */
  InitData();

  /* Turn off by speed bit is set */
  FData.DecisionData.Speed.disableHLAByHighSpeed = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MAX_SPEED), b_TRUE, "Max speed turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason max speed is not set, when the disableHLAByHighSpeed bit is not set.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_MAX_SPEED is not set \n */
TEST_DecisionSetTurnOffReasonGlob_004(DecisionSetTurnOffReasonGlob_004, "Test that if disableHLAByHighSpeed bit is not set, that max speed turn off reason is also not set")
{
  /* Initialize Data */
  InitData();

  /* Turn off by speed bit is not set */
  FData.DecisionData.Speed.disableHLAByHighSpeed = 0;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MAX_SPEED), b_FALSE, "Max speed turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason city is set, if city state is set to city detected.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_CITY is set \n */
TEST_DecisionSetTurnOffReasonGlob_005(DecisionSetTurnOffReasonGlob_005, "Test that city state detected leads to turn off reason city")
{
  /* Initialize Data */
  InitData();

  /* City was detected */
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_DTCD;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_CITY), b_TRUE, "City turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason city is not set, if city state is not set to city detected.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_CITY is not set \n */
TEST_DecisionSetTurnOffReasonGlob_006(DecisionSetTurnOffReasonGlob_006, "Test that city state not detected does not lead to turn off reason city")
{
  /* Initialize Data */
  InitData();

  /* City was not detected */
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_NOT_DTCD;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_CITY), b_FALSE, "City turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason tunnel is set, if tunnel state is set to tunnel detected.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_TUNNEL is set \n */
TEST_DecisionSetTurnOffReasonGlob_007(DecisionSetTurnOffReasonGlob_007, "Test that tunnel state detected leads to turn off reason tunnel")
{
  /* Initialize Data */
  InitData();

  /* Tunnel was detected */
  FData.DecisionOut.eTunnelState = RTE_HLAR_TUNNEL_INSIDE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_TUNNEL), b_TRUE, "Tunnel turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason tunnel is not set, if tunnel state is not set to tunnel detected.\n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_TUNNEL is not set \n */
TEST_DecisionSetTurnOffReasonGlob_008(DecisionSetTurnOffReasonGlob_008, "Test that tunnel state not detected does not lead to turn off reason tunnel")
{
  /* Initialize Data */
  InitData();

  /* Tunnel was not detected */
  FData.DecisionOut.eCityState = RTE_HLAR_TUNNEL_NOT_DTCD;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_TUNNEL), b_FALSE, "Tunnel turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason brightness is set, if brightness state is set to day. Leb enhanced test mode is not set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BRIGHTNESS is set \n */
TEST_DecisionSetTurnOffReasonGlob_009(DecisionSetTurnOffReasonGlob_009, "Test that brightness state day leads to turn off reason brightness")
{
  /* Initialize Data */
  InitData();

  /* brightness was detected */
  e_Brightness = RTE_HLAR_BRT_DAY;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS), b_TRUE, "brightness turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason brightness is not set, if brightness state is set to night. Leb enhanced test mode is not set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BRIGHTNESS is not set \n */
TEST_DecisionSetTurnOffReasonGlob_010(DecisionSetTurnOffReasonGlob_010, "Test that brightness state night leads not to turn off reason brightness")
{
  /* Initialize Data */
  InitData();

  /* brightness was not detected */
  e_Brightness = RTE_HLAR_BRT_NIGHT;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS), b_FALSE, "brightness turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason not released is set, if blockage state is set to clearance measurement. No clearance measurement test mode is not set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_NOT_RELEASED is set \n */
TEST_DecisionSetTurnOffReasonGlob_011(DecisionSetTurnOffReasonGlob_011, "Test that clearnce measurement state leads to turn off reason not released")
{
  /* Initialize Data */
  InitData();

  /* blockage is in clearance measurement */
  FData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_NOT_RELEASED), b_TRUE, "not released turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason not released is not set, if blockage state is not set to clearance measurement. No clearance measurement test mode is not set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_NOT_RELEASED is not set \n */
TEST_DecisionSetTurnOffReasonGlob_012(DecisionSetTurnOffReasonGlob_012, "Test that no clearnce measurement state leads to no turn off reason not released")
{
  /* Initialize Data */
  InitData();

  /* blockage was not detected */
  FData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_NOT_RELEASED), b_FALSE, "not released turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason blockage is set, if blockage state is set to blockage. No clearance measurement test mode is not set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BLOCKAGE is set \n */
TEST_DecisionSetTurnOffReasonGlob_013(DecisionSetTurnOffReasonGlob_013, "Test that blockage state leads to turn off reason blockage")
{
  /* Initialize Data */
  InitData();

  /* blockage was detected */
  FData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BLOCKAGE), b_TRUE, "blockage turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason not released is not set, if blockage state is not set to clearance measurement. No clearance measurement test mode is not set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BLOCKAGE is not set \n */
TEST_DecisionSetTurnOffReasonGlob_014(DecisionSetTurnOffReasonGlob_014, "Test that no blockage state leads to no turn off reason blockage")
{
  /* Initialize Data */
  InitData();

  /* blockage was not detected */
  FData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BLOCKAGE), b_FALSE, "blockage turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason fog is set, if weather state is set to fog. Fog detection is active. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_FOG is set \n */
TEST_DecisionSetTurnOffReasonGlob_015(DecisionSetTurnOffReasonGlob_015, "Test that weather state fog leads to turn off reason fog")
{
  /* Initialize Data */
  InitData();

  /* fog was detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_HEAVY_FOG;
  /* fog detection active */
  CPar_HlafPar.AlgoCfg.FogDetection = RTE_HLA_FOGDET_ACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_FOG), b_TRUE, "fog turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason fog is not set, if weather state is set to fog. Fog detection is not active. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_FOG is set \n */
TEST_DecisionSetTurnOffReasonGlob_016(DecisionSetTurnOffReasonGlob_016, "Test that weather state fog leads to no turn off reason fog if fog detection is set to inactive")
{
  /* Initialize Data */
  InitData();

  /* fog was detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_HEAVY_FOG;
  /* fog detection inactive */
  CPar_HlafPar.AlgoCfg.FogDetection = RTE_HLA_FOGDET_INACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_FOG), b_FALSE, "fog turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason fog is not set, if weather state is set to good weather. Fog detection is active. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_FOG is set \n */
TEST_DecisionSetTurnOffReasonGlob_017(DecisionSetTurnOffReasonGlob_017, "Test that weather state good weather leads to no turn off reason fog")
{
  /* Initialize Data */
  InitData();

  /* fog was not detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_GOOD;
  /* fog detection active */
  CPar_HlafPar.AlgoCfg.FogDetection = RTE_HLA_FOGDET_ACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_FOG), b_FALSE, "fog turn off reason is not set");
}

/** \test
 *  \description
 *     Test that heavy fog leads to turn off reason bad weather. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BAD_WEATHER is set \n */
test_HLAFDecision_SetTurnOffReasonGlob_HeavyFogDetected_BadWeatherTurnOffReasonIsSet(HLAFDecision_SetTurnOffReasonGlob_HeavyFogDetected_BadWeatherTurnOffReasonIsSet, "Test that heavy fog leads to turn off reason bad weather")
{
  /* Initialize Data */
  InitData();

  /* heavy fog was detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_HEAVY_FOG;
  /* bad weather detection active */
  CPar_HlafPar.AlgoCfg.BadWeatherDetection = RTE_HLA_BADWEATHER_DET_ACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER), b_TRUE, "bad weather turn off reason is set");
}

/** \test
 *  \description
 *     Test that medium fog leads to turn off reason bad weather. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BAD_WEATHER is set \n */
test_HLAFDecision_SetTurnOffReasonGlob_MediumFogDetected_BadWeatherTurnOffReasonIsSet(HLAFDecision_SetTurnOffReasonGlob_MediumFogDetected_BadWeatherTurnOffReasonIsSet, "Test that medium fog leads to turn off reason bad weather")
{
  /* Initialize Data */
  InitData();

  /* medium fog was detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_MEDIUM_FOG;
  /* bad weather detection active */
  CPar_HlafPar.AlgoCfg.BadWeatherDetection = RTE_HLA_BADWEATHER_DET_ACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER), b_TRUE, "bad weather turn off reason is set");
}

/** \test
 *  \description
 *     Test that bad weather leads to turn off reason bad weather. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BAD_WEATHER is set \n */
test_HLAFDecision_SetTurnOffReasonGlob_BadWeatherDetected_BadWeatherTurnOffReasonIsSet(HLAFDecision_SetTurnOffReasonGlob_BadWeatherDetected_BadWeatherTurnOffReasonIsSet, "Test that bad weather leads to turn off reason bad weather")
{
  /* Initialize Data */
  InitData();

  /* bad weather was detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_BAD;
  /* bad weather detection active */
  CPar_HlafPar.AlgoCfg.BadWeatherDetection = RTE_HLA_BADWEATHER_DET_ACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER), b_TRUE, "bad weather turn off reason is set");
}

/** \test
 *  \description
 *     Test that bad weather leads to turn off reason bad weather. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BAD_WEATHER is set \n */
test_HLAFDecision_SetTurnOffReasonGlob_GoodWeatherDetected_BadWeatherTurnOffReasonIsNotSet(HLAFDecision_SetTurnOffReasonGlob_GoodWeatherDetected_BadWeatherTurnOffReasonIsNotSet, "Test that bad weather leads to turn off reason bad weather")
{
  /* Initialize Data */
  InitData();

  /* good weather was detected */
  FData.DecisionOut.eWeatherState = RTE_HLAR_WEATHER_GOOD;
  /* bad weather detection active */
  CPar_HlafPar.AlgoCfg.BadWeatherDetection = RTE_HLA_BADWEATHER_DET_ACTIVE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER), b_FALSE, "bad weather turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason blockage is set, if blockage state is set to blockage. No clearance measurement test mode is set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BLOCKAGE is not set \n */
TEST_DecisionSetTurnOffReasonGlob_018(DecisionSetTurnOffReasonGlob_018, "Test that blockage state leads to no turn off reason blockage when test mode clearance measurement is set")
{
  /* Initialize Data */
  InitData();

  /* blockage was detected */
  FData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_NO_CLEARMEAS;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BLOCKAGE), b_FALSE, "blockage turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason not released is set, if blockage state is set to clearance measurement. No clearance measurement test mode is set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_NOT_RELEASED is not set \n */
TEST_DecisionSetTurnOffReasonGlob_019(DecisionSetTurnOffReasonGlob_019, "Test that clearance measurement state leads to no turn off reason not released when test mode clearance measurement is set")
{
  /* Initialize Data */
  InitData();

  /* blockage is in clearance measurement */
  FData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_NO_CLEARMEAS;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_NOT_RELEASED), b_FALSE, "not released turn off reason is ot set");
}

/** \test
 *  \description
 *     Test that turn off reason brightness is set, if brightness state is set to day. Leb enhanced test mode is set. \n
 *     calls function HLAFDecision_SetTurnOffReasonGlob() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_BRIGHTNESS is not set \n */
TEST_DecisionSetTurnOffReasonGlob_020(DecisionSetTurnOffReasonGlob_020, "Test that brightness state day leads to no turn off reason brightness when test mode lab enhanced is active")
{
  /* Initialize Data */
  InitData();

  /* brightness was detected */
  e_Brightness = RTE_HLAR_BRT_DAY;
  /* no test mode set */
  CPar_HlafPar.AlgoCfg.TestMode = RTE_HLA_TESTMODE_LAB_ENHANCED;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReasonGlob(e_Brightness, &ReqPorts, &FData, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS), b_FALSE, "brightness turn off reason is set");
}

/** \test
 *  \description
 *     Test that if relevant EM object is in list, the correct flag is set. \n
 *     calls function HLAFDecision_CheckEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     bEMObjDetected is set \n */
test_HLAFDecision_CheckForRelevantEMObjects_EMObjDetected_RelVehFlagIsSet(HLAFDecision_CheckForRelevantEMObjects_EMObjDetected_RelVehFlagIsSet, "Test that if relevant EM object is in list, the correct flag is set")
{
  /* Initialize Data */
  InitData();

  /* relevant oncoming EM objects are in the list */
  MatrixData.numRelObj = 2;
  MatrixData.numEMObj = 2;
  MatrixData.Object[0].bIsRelevantOnc = b_TRUE;
  MatrixData.Object[0].EMObjID = 1;
  MatrixData.Object[1].bIsRelevantOnc = b_TRUE;
  MatrixData.Object[1].EMObjID = 1;

  /* call function */
  COU_CALL(HLAFDecision_CheckEMObjectList(&MatrixData, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bEMObjOncDetected, b_TRUE, "oncoming EM object detected");

  MatrixData.Object[0].bIsRelevantOnc = b_FALSE;
  MatrixData.Object[1].bIsRelevantOnc = b_FALSE;
  MatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  MatrixData.Object[1].bIsRelevantPrec = b_TRUE;

  /* call function */
  COU_CALL(HLAFDecision_CheckEMObjectList(&MatrixData, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bEMObjPrecDetected, b_TRUE, "preceding EM object detected");
}
/** \test
 *  \description
 *     Test that if relevant EM object is not in list, the correct flag is not set. \n
 *     calls function HLAFDecision_CheckEMObjectList() \n
 *  \precondition
 *     None \n
 *  \result
 *     bEMObjOncDetected and bEMObjPrecDetected are not set \n */
test_HLAFDecision_CheckForRelevantEMObjects_EMObjNotDetected_RelVehFlagIsNotSet(HLAFDecision_CheckForRelevantEMObjects_EMObjNotDetected_RelVehFlagIsNotSet, "Test that if relevant EM object is in list, the correct flag is not set")
{
  /* Initialize Data */
  InitData();

  /* no relevant radar object is in the list */
  MatrixData.numEMObj = 0;

  /* call function */
  COU_CALL(HLAFDecision_CheckEMObjectList(&MatrixData, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bEMObjOncDetected, b_FALSE, "oncoming EM object not detected");
  COU_ASSERT_EQUAL(RelVeh.bEMObjPrecDetected, b_FALSE, "preceding EM object not detected");

  /* relevant oncoming EM objects are in the list */
  MatrixData.numRelObj = 2;
  MatrixData.numEMObj = 2;
  MatrixData.Object[0].bIsRelevantOnc = b_TRUE;
  MatrixData.Object[1].bIsRelevantOnc = b_TRUE;

  MatrixData.Object[0].EMObjID = UI8_T_MAX;
  MatrixData.Object[1].EMObjID = UI8_T_MAX;

  /* call function */
  COU_CALL(HLAFDecision_CheckEMObjectList(&MatrixData, &RelVeh), "function call");

  COU_ASSERT_EQUAL(RelVeh.bEMObjOncDetected, b_FALSE, "oncoming EM object not detected");
  COU_ASSERT_EQUAL(RelVeh.bEMObjPrecDetected, b_FALSE, "preceding EM object not detected");
}


/** \test
 *  \description
 *     Test that if relevant radar object is in list, the correct flag is set. \n
 *     calls function HLAFDecision_CheckForRelevantRadarObjects() \n
 *  \precondition
 *     None \n
 *  \result
 *     bRadarObjDetected is set \n */
test_HLAFDecision_CheckForRelevantRadarObjects_RadarObjDetected_RelVehFlagIsSet(HLAFDecision_CheckForRelevantRadarObjects_RadarObjDetected_RelVehFlagIsSet, "Test that if relevant radar object is in list, the correct flag is set")
{
  /* Initialize Data */
  InitData();

  /* relevant radar objects are in the list */
  MatrixData.numRadarObj = 2;

  /* call function */
  COU_CALL(HLAFDecision_CheckForRelevantRadarObjects(&MatrixData, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bRadarObjDetected, b_TRUE, "radar object detected");
}
/** \test
 *  \description
 *     Test that if relevant radar object is not in list, the correct flag is not set. \n
 *     calls function HLAFDecision_CheckForRelevantRadarObjects() \n
 *  \precondition
 *     None \n
 *  \result
 *     bRadarObjDetected is not set \n */
test_HLAFDecision_CheckForRelevantRadarObjects_RadarObjNotDetected_RelVehFlagIsNotSet(HLAFDecision_CheckForRelevantRadarObjects_RadarObjNotDetected_RelVehFlagIsNotSet, "Test that if relevant radar object is in list, the correct flag is not set")
{
  /* Initialize Data */
  InitData();

  /* no relevant radar object is in the list */
  MatrixData.numRadarObj = 0;

  /* call function */
  COU_CALL(HLAFDecision_CheckForRelevantRadarObjects(&MatrixData, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bRadarObjDetected, b_FALSE, "radar object not detected");
}
/** \test
 *  \description
 *     Test that turn off reason oncoming bit is set, when oncoming was detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_ONCOMING bit is set \n */
TEST_DecisionSetTurnOffReason_001(DecisionSetTurnOffReason_001, "Test that turn off reason oncoming bit is set, when oncoming was detected")
{
  /* Initialize Data */
  InitData();

  /* oncoming was detected */
  RelVeh.bOncDetected = b_TRUE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_ONCOMING), b_TRUE, "Oncoming turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason oncoming bit is not set, when oncoming was not detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_ONCOMING bit is set \n */
TEST_DecisionSetTurnOffReason_002(DecisionSetTurnOffReason_002, "Test that turn off reason oncoming bit is not set, when oncoming was not detected")
{
  /* Initialize Data */
  InitData();

  /* oncoming was not detected */
  RelVeh.bOncDetected = b_FALSE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_ONCOMING), b_FALSE, "Oncoming turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason preceding bit is set, when preceding was detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_PRECEDING bit is set \n */
TEST_DecisionSetTurnOffReason_003(DecisionSetTurnOffReason_003, "Test that turn off reason preceding bit is set, when preceding was detected")
{
  /* Initialize Data */
  InitData();

  /* preceding was detected */
  RelVeh.bPrecDetected = b_TRUE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_PRECEDING), b_TRUE, "Preceding turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason preceding bit is not set, when preceding was not detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_PRECEDING bit is set \n */
TEST_DecisionSetTurnOffReason_004(DecisionSetTurnOffReason_004, "Test that turn off reason preceding bit is not set, when preceding was not detected")
{
  /* Initialize Data */
  InitData();

  /* preceding was not detected */
  RelVeh.bPrecDetected = b_FALSE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_PRECEDING), b_FALSE, "Preceding turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason EM object bit is set, when EM object was detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_EM_OBJECT_ONC and HLAF_TURN_OFF_REASON_EM_OBJECT_PREC bits are set \n */
TEST_DecisionSetTurnOffReason_005(DecisionSetTurnOffReason_005, "Test that turn off reason EM object bit is set, when EM object was detected")
{
  /* Initialize Data */
  InitData();

  /* EM object was detected */
  RelVeh.bEMObjOncDetected = b_TRUE;
  RelVeh.bEMObjPrecDetected = b_TRUE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC), b_TRUE, "oncoming EM object turn off reason is set");
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_PREC), b_TRUE, "preceding EM object turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason EM object bit is not set, when EM object was not detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_EM_OBJECT_ONC and HLAF_TURN_OFF_REASON_EM_OBJECT_ONC bits are not set \n */
TEST_DecisionSetTurnOffReason_006(DecisionSetTurnOffReason_006, "Test that turn off reason EM object bit is not set, when EM object was not detected")
{
  /* Initialize Data */
  InitData();

  /* EM object was not detected */
  RelVeh.bEMObjOncDetected = b_FALSE;
  RelVeh.bEMObjPrecDetected = b_FALSE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC), b_FALSE, "oncoming EM object turn off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC), b_FALSE, "preceding EM object turn off reason is not set");
}

/** \test
 *  \description
 *     Test that turn off reason radar object bit is set, when radar object was detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_RADAR_OBJECT bit is set \n */
test_HLAFDecision_SetTurnOffReason_RadarObjDetected_TurnOffReasonSet(HLAFDecision_SetTurnOffReason_RadarObjDetected_TurnOffReasonSet, "Test that turn off reason radar object bit is set, when radar object was detected")
{
  /* Initialize Data */
  InitData();

  /* radar object was detected */
  RelVeh.bRadarObjDetected  = b_TRUE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_RADAR_OBJECT), b_TRUE, "radar object turn off reason is set");
}

/** \test
 *  \description
 *     Test that turn off reason radar object bit is not set, when radar object was not detected. \n
 *     calls function HLAFDecision_SetTurnOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_TURN_OFF_REASON_EM_OBJECT bit is set \n */
test_HLAFDecision_SetTurnOffReason_RadarObjNotDetected_NoTurnOffReasonSet(HLAFDecision_SetTurnOffReason_RadarObjNotDetected_NoTurnOffReasonSet, "Test that turn off reason radar object bit is not set, when radar object was not detected")
{
  /* Initialize Data */
  InitData();

  /* EM object was not detected */
  RelVeh.bRadarObjDetected = b_FALSE;

  /* call function */
  COU_CALL(HLAFDecision_SetTurnOffReason(&RelVeh, &TurnOffReason), "function call");

  /* check output */
  COU_ASSERT_EQUAL(CML_GetBit(TurnOffReason.Reason, HLAF_TURN_OFF_REASON_RADAR_OBJECT), b_FALSE, "radar object turn off reason is not set");
}

/** \test
 *  \description
 *     Test that when no turn off reason is set and the previous high beam state was on, high beam state out is also on. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     High beam state is on \n */
TEST_DecisionSetHBState_001(DecisionSetHBState_001, "Test that in case of no turn off reason and previous high beam state is on, high beam state will set to on")
{
  /* Initialize Data */
  InitData();

  /* No turn off reason */
  TurnOffReason.Reason = 0;
  /* previous high beam state is on */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;

  /* call function */
  COU_CALL(HLAFDecision_SetHBState(&TurnOffReason, &KeepOffReason, eHighBeamStatePrev, &eHighBeamStateOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(eHighBeamStateOut, RTE_HLAF_HB_STATE_FULL_ON, "High beam state is on");
}

/** \test
 *  \description
 *     Test that when no turn off reason is set and the previous high beam state was off and no keep off reason is set, high beam state out is also on. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     High beam state is on \n */
TEST_DecisionSetHBState_002(DecisionSetHBState_002, "Test that in case of no turn off and keep off reason and previous high beam state is off, high beam state will set to on")
{
  /* Initialize Data */
  InitData();

  /* No turn off reason */
  TurnOffReason.Reason = 0;
  /* previous high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  /* no keep off reason */
  KeepOffReason.Reason = 0;

  /* call function */
  COU_CALL(HLAFDecision_SetHBState(&TurnOffReason, &KeepOffReason, eHighBeamStatePrev, &eHighBeamStateOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(eHighBeamStateOut, RTE_HLAF_HB_STATE_FULL_ON, "High beam state is on");
}

/** \test
 *  \description
 *     Test that when no turn off reason is set and the previous high beam state was off and a keep off reason is set, high beam state out is set to off. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     High beam state is off \n */
TEST_DecisionSetHBState_003(DecisionSetHBState_003, "Test that in case of no turn off, but set keep off reason and previous high beam state is off, high beam state will set to off")
{
  /* Initialize Data */
  InitData();

  /* No turn off reason */
  TurnOffReason.Reason = 0;
  /* previous high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  /* keep off reason */
  KeepOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetHBState(&TurnOffReason, &KeepOffReason, eHighBeamStatePrev, &eHighBeamStateOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(eHighBeamStateOut, RTE_HLAF_HB_STATE_OFF, "High beam state is on");
}

/** \test
 *  \description
 *     Test that when a turn off reason is set, the high beam state will be set to off. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     High beam state is off \n */
TEST_DecisionSetHBState_004(DecisionSetHBState_004, "Test that in case of no turn off, but set keep off reason and previous high beam state is off, high beam state will set to off")
{
  /* Initialize Data */
  InitData();

  /* No turn off reason */
  TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetHBState(&TurnOffReason, &KeepOffReason, eHighBeamStatePrev, &eHighBeamStateOut), "function call");

  /* check output */
  COU_ASSERT_EQUAL(eHighBeamStateOut, RTE_HLAF_HB_STATE_OFF, "High beam state is on");
}

/** \test
 *  \description
 *     When a relevant oncoming object is in the internal object list, this shall be detected and bOncDetected shall be set. The highbeam state is off and the object is within the ROI. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_001(DecisionFindRelevantVehicle_001, "Test that relevant oncoming object sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant oncoming object is in the internal object list. The highbeam state is off and the object is outside the ROI. bOncDetected shall not be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_002(DecisionFindRelevantVehicle_002, "Test that relevant oncoming object sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Object is outside of ROI*/
  LightObject.kinematic.camera.x = 0;

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     A relevant oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was detected, traffic style is right hand traffic. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_003(DecisionFindRelevantVehicle_003, "Test that relevant oncoming object on highway in right hand traffic style sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED;
  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was detected, traffic style is left hand traffic. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_004(DecisionFindRelevantVehicle_004, "Test that relevant oncoming object on highway in left hand traffic style sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED;
  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was detected, traffic style is left hand traffic. Time to border is set to zero. bOncDetected shall not be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_005(DecisionFindRelevantVehicle_005, "Test that relevant oncoming object with a timer to border of zero on highway in left hand traffic style sets the bOncDetected to false")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED;
  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC;
  /* set time to border to zero */
  LightObject.kinematic.timeToHlaBorder = 0.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     A relevant oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was not detected. Small radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_006(DecisionFindRelevantVehicle_006, "Test that relevant oncoming object on contry road with a small radius sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* small radius */
  FData.CamData.radiusAbs_m = 100;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant fast moving oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was not detected. Big radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_007(DecisionFindRelevantVehicle_007, "Test that relevant fast moving oncoming object on country road with a big radius sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was not detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* big radius */
  FData.CamData.radiusAbs_m = 1000;
  /* moving fast */
  LightObject.kinematic.camera.deltaX = 5;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant normal moving oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was not detected. Big radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_008(DecisionFindRelevantVehicle_008, "Test that relevant normal moving oncoming object on country road with a big radius sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* big radius */
  FData.CamData.radiusAbs_m = 1000;
  /* moving normally */
  LightObject.kinematic.camera.deltaX = 2;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant normal moving oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was not detected. Big radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_009(DecisionFindRelevantVehicle_009, "Test that relevant normal moving oncoming object on country road with a big radius sets the bOncDetected to false, when time to border is too small")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* big radius */
  FData.CamData.radiusAbs_m = 1000;
  /* moving normally */
  LightObject.kinematic.camera.deltaX = 2;
  /* small time to border */
  LightObject.kinematic.timeToHlaBorder = 0.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     A relevant normal moving oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was not detected. Big radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_010(DecisionFindRelevantVehicle_010, "Test that relevant normal moving oncoming object on country road with a big radius sets the bOncDetected to false when cycles lost ist not zero")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* light reference missing */
  LightObject.general.cyclesLost = 3;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Highway was detected, so highway delay shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. Highway delay is set. \n */
TEST_DecisionFindRelevantVehicle_012(DecisionFindRelevantVehicle_012, "Test that highway delay is set")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_MOTORWAY;

  /* --- time to border below OncomingMinHighway --- */
  /* set time to border */
  LightObject.kinematic.timeToHlaBorder = CPar_HlafPar.TurnOnDelay.OncomingMinHighway - 0.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMinHighway, "Min Highway delay was set");

  /* --- time to border above OncomingMaxHighway --- */
  /* set time to border */
  LightObject.kinematic.timeToHlaBorder = CPar_HlafPar.TurnOnDelay.OncomingMaxHighway + 0.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMaxHighway, "Max Highway delay was set");

  /* --- time to border between OncomingMinHighway and OncomingMaxHighway --- */
  /* set time to border */
  LightObject.kinematic.timeToHlaBorder = (CPar_HlafPar.TurnOnDelay.OncomingMinHighway + CPar_HlafPar.TurnOnDelay.OncomingMaxHighway)/2;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, LightObject.kinematic.timeToHlaBorder, "Time to border highway delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Minimum delay shall be set, since object is leaving the ROI very fast. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. Minimum delay is set. \n */
TEST_DecisionFindRelevantVehicle_013(DecisionFindRelevantVehicle_013, "Test that minimum delay is set in case of fast leaving oncoming object")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_COUNTRY;

  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHT;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMin, "Minimum delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. No special case so the delay shall be set according to the time to border. The time to border is above the OncomingMax threshold so it shall be set to the OncomingMax value. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. Max delay is set. \n */
TEST_DecisionFindRelevantVehicle_014(DecisionFindRelevantVehicle_014, "Test that maximum delay is set, no special case")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_COUNTRY;

  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHT;

  /* object far away */
  LightObject.kinematic.world.x = 80.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMax, "Maximum delay was set");
}

/** \test
 *  \description
 *     When a relevant preceding object was detected. Timegap is below threshold, so the PrecedingTimeGap delay is set \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingTimeGap_Threshold delay is set. \n */
TEST_DecisionFindRelevantVehicle_015(DecisionFindRelevantVehicle_015, "Test that PrecedingTimeGap delay is set, when preceding is below threshold")
{
  float32 PrecedingTimeGap_Threshold = 3.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  VDYData.Longitudinal.Velocity = 12.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL_FMT(RelVeh.Prec_s, PrecedingTimeGap_Threshold, "%.1f", "PrecedingTimeGap_Threshold delay was set");
}

/** \test
 *  \description
 *     Special case for TA19, where PrecedingTimeGap_Threshold is set to zero, which basically disables a certain part of the logic by setting the PrecedingTimeGap_Threshold parameter to zero (this is wanted by Toyota).
 *     To reach a full coverage the x world coordinate was modified so that the object is behind the car.
 *     When a relevant preceding object was detected. Timegap is below threshold, so the PrecedingTimeGap delay is set \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingTimeGap_Threshold delay is set. \n */
TEST_HLAFDecision_FindRelevantVehicle_ObjectIsBehindCar_PrecDetected(HLAFDecision_FindRelevantVehicle_ObjectIsBehindCar_PrecDetected, "Test that PrecedingTimeGap delay is set, when preceding is below threshold")
{
  float32 PrecedingTimeGap_Threshold = 3.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  LightObject.kinematic.world.x = -2.0f;

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  VDYData.Longitudinal.Velocity = 12.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL_FMT(RelVeh.Prec_s, PrecedingTimeGap_Threshold, "%.1f", "PrecedingTimeGap_Threshold delay was set");
}

/** \test
 *  \description
 *     When a relevant preceding object was detected. Timegap is below threshold, so the PrecedingTimeGap delay is set \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingMaxLong delay is set. \n */
TEST_DecisionFindRelevantVehicle_016(DecisionFindRelevantVehicle_016, "Test that PrecedingMaxShort/PrecedingMaxLong delay is set, when preceding is above intensity threshold")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* driving not very fast */
  VDYData.Longitudinal.Velocity = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, CPar_HlafPar.TurnOnDelay.PrecedingMaxLong, "PrecedingMaxLong delay was set");
}

/** \test
 *  \description
 *     When a relevant preceding object was detected. Timegap is below threshold, so the PrecedingTimeGap delay is set \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingMaxShort delay is set. \n */
TEST_DecisionFindRelevantVehicle_017(DecisionFindRelevantVehicle_017, "Test that PrecedingMaxShort delay is set, when preceding is below intensity threshold")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* driving not very fast */
  VDYData.Longitudinal.Velocity = 2.0f;

  /* higher intensity */
  LightObject.attributes.intensity = 80;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, CPar_HlafPar.TurnOnDelay.PrecedingMaxShort, "PrecedingMaxShort delay was set");
}

/** \test
 *  \description
 *     When a relevant preceding object was detected. Turn off delay is active so no turn on delay is set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to false. No delay is set. \n */
TEST_DecisionFindRelevantVehicle_018(DecisionFindRelevantVehicle_018, "Test that no delay is set for oncoming, when turn off delay is active")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* driving not very fast */
  VDYData.Longitudinal.Velocity = 2.0f;

  /* higher intensity */
  LightObject.attributes.intensity = 80;

  /* wiper is active */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_VALID;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_ACTIVE;

  CPar_HlafPar.TurnOffDelay.oncomingVehicle = 2.0f;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 2.0f;

  FData.CamData.dtimeFwd_s = 0.4f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_FALSE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, 0.0f, "No delay was set");
}

/** \test
 *  \description
 *     When a relevant preceding object was detected. Turn off delay is active. Passed time is high enough to reach threshold \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingMaxShort delay is set. \n */
TEST_DecisionFindRelevantVehicle_019(DecisionFindRelevantVehicle_019, "Test that delay is set for preceding, when turn off delay gets above threshold")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* driving not very fast */
  VDYData.Longitudinal.Velocity = 2.0f;

  /* higher intensity */
  LightObject.attributes.intensity = 80;

  /* wiper is active */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_VALID;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_ACTIVE;

  CPar_HlafPar.TurnOffDelay.oncomingVehicle = 2.0f;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 2.0f;

  FData.CamData.dtimeFwd_s = 3.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, CPar_HlafPar.TurnOnDelay.PrecedingMaxShort, "No delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Turn off delay is active so no turn on delay is set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false. No delay is set. \n */
TEST_DecisionFindRelevantVehicle_020(DecisionFindRelevantVehicle_020, "Test that no delay is set for oncoming, when turn off delay is active")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* driving not very fast */
  VDYData.Longitudinal.Velocity = 2.0f;

  /* higher intensity */
  LightObject.attributes.intensity = 80;

  /* wiper is active */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_VALID;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_ACTIVE;

  CPar_HlafPar.TurnOffDelay.oncomingVehicle = 2.0f;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 2.0f;

  FData.CamData.dtimeFwd_s = 0.4f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, 0.0f, "No delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Turn off delay is active. Passed time is high enough to reach threshold \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. OncomingMax delay is set. \n */
TEST_DecisionFindRelevantVehicle_021(DecisionFindRelevantVehicle_021, "Test that delay is set for oncoming, when turn off delay gets above threshold")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* driving not very fast */
  VDYData.Longitudinal.Velocity = 2.0f;

  /* higher intensity */
  LightObject.attributes.intensity = 80;

  /* wiper is active */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_VALID;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_ACTIVE;

  CPar_HlafPar.TurnOffDelay.oncomingVehicle = 2.0f;
  CPar_HlafPar.TurnOffDelay.precedingVehicle = 2.0f;

  FData.CamData.dtimeFwd_s = 3.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMax, "Delay was set");
}

/** \test
 *  \description
 *     Test that PrecedingMinWiperOn delay is set for preceding, when vdy wiper state is set to init. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingMinWiperOn delay is set. \n */
TEST_DecisionFindRelevantVehicle_022(DecisionFindRelevantVehicle_022, "Test that PrecedingMinWiperOn delay is set for preceding, when vdy wiper state is set to init")
{
  float32 PrecedingTimeGap_Threshold = 2.0f;

  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* wiper is set to init */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_INIT;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_ACTIVE;

  FData.CamData.dtimeFwd_s = 3.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, CPar_HlafPar.TurnOnDelay.PrecedingMinWiperOn, "Delay was set");
}

/** \test
 *  \description
 *     Test that PrecedingMinWiperOn delay is set for preceding, when vdy wiper state is set to init, wiper state is not active. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingMaxShort delay is set. \n */
TEST_DecisionFindRelevantVehicle_023(DecisionFindRelevantVehicle_023, "Test that PrecedingMinWiperOn delay is set for preceding, when vdy wiper state is set to init, wiper state is not active")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* wiper is set to init */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_INIT;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_INACTIVE;

  FData.CamData.dtimeFwd_s = 3.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, CPar_HlafPar.TurnOnDelay.PrecedingMaxShort, "Delay was set");
}

/** \test
 *  \description
 *     Test that PrecedingMinWiperOn delay is set for preceding, when vdy wiper state is set to init, wiper state is not active. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true. PrecedingMaxShort delay is set. \n */
TEST_DecisionFindRelevantVehicle_024(DecisionFindRelevantVehicle_024, "Test that PrecedingMinWiperOn delay is set for preceding, when vdy wiper state is set to init, wiper state is not active")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* wiper is set to init */
  VehSig.VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE] = VDY_IO_STATE_INVALID;
  VehSig.VehSigAdd.WiperState = VEH_SIG_ADD_WIPER_STATE_INACTIVE;

  FData.CamData.dtimeFwd_s = 3.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "Preceding was detected");
  COU_ASSERT_EQUAL(RelVeh.Prec_s, CPar_HlafPar.TurnOnDelay.PrecedingMaxShort, "Delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Lateral offset of object is too small, so OncomingMax is set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. OncomingMax delay is set. \n */
TEST_DecisionFindRelevantVehicle_025(DecisionFindRelevantVehicle_025, "Test that minimum delay is set in case of fast leaving oncoming object")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_COUNTRY;

  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHT;

  /* lateral offset too small */
  LightObject.kinematic.world.y = 1.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMax, "OncomingMax delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Lateral offset of object is too small, so OncomingMin is set in LHT traffic style. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. OncomingMin delay is set. \n */
TEST_DecisionFindRelevantVehicle_026(DecisionFindRelevantVehicle_026, "Test that minimum delay is set in case of fast leaving oncoming object with LHT traffic style")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_COUNTRY;

  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHT;

  /* lateral offset */
  LightObject.kinematic.world.y = -10.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMin, "OncomingMin delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Lateral offset of object is too small, so OncomingMax is set in LHT traffic style. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. OncomingMin delay is set. \n */
TEST_DecisionFindRelevantVehicle_027(DecisionFindRelevantVehicle_027, "Test that maximum delay is set in case of fast leaving oncoming object with LHT traffic style, which has a too small lateral offset")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_COUNTRY;

  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHT;

  /* lateral offset too small */
  LightObject.kinematic.world.y = -1.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMax, "OncomingMax delay was set");
}

/** \test
 *  \description
 *     When a relevant oncoming object is in the internal object list, it is not considered due to the china mode logic. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_028(DecisionFindRelevantVehicle_028, "Test that relevant preceding object is not detected due to china mode logic")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* set parameter so that preceding test will fail */
  CPar_HlafPar.KeepOnDelay.distancePrecedingVehicleMax = 10;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_FALSE, "Preceding was not detected");
}

/** \test
 *  \description
 *     When a relevant oncoming object is in the internal object list, it is not considered because the light is above the vehicle ROI. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_029(DecisionFindRelevantVehicle_029, "Test that relevant preceding object is not detected because light is above vehicle ROI")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* ligt is outside of vehicle roi */
  LightObject.kinematic.camera.y = LsdLightObjectList.roi.yVehicleSplit - 1;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_FALSE, "Preceding was not detected");
}

/** \test
 *  \description
 *     When a relevant oncoming object is in the internal object list, it is not considered because the light is below the vehicle ROI. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_030(DecisionFindRelevantVehicle_030, "Test that relevant preceding object is not detected because light is below vehicle ROI")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* ligt is outside of vehicle roi */
  LightObject.kinematic.camera.y = LsdLightObjectList.roi.y2 + 1;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_FALSE, "Preceding was not detected");
}

/** \test
 *  \description
 *     When a relevant oncoming object is in the internal object list, it is not considered because the light is outside (right) of the vehicle ROI. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_031(DecisionFindRelevantVehicle_031, "Test that relevant preceding object is not detected because light is outside (right) of the vehicle ROI")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* ligt is outside of vehicle roi */
  LightObject.kinematic.camera.x = LsdLightObjectList.roi.x2 + 1;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_FALSE, "Preceding was not detected");
}

/** \test
 *  \description
 *     A relevant oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was detected, traffic style is left hand traffic. Angle is too big. bOncDetected shall not be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_032(DecisionFindRelevantVehicle_032, "Test that relevant oncoming object on highway in left hand traffic style sets the bOncDetected to false, since angle is too big")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED;
  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC;

  /* angle is too big */
  LightObject.kinematic.world.horizontalAngle = 0.3f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     A relevant fast moving oncoming object is in the internal object list. The highbeam state is on and the object is inside the ROI. Highway was not detected. Big radius. Angle is too big bOncDetected shall not be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_033(DecisionFindRelevantVehicle_033, "Test that relevant oncoming object on country road with a big radius sets the bOncDetected to false, since angle is too big")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* big radius */
  FData.CamData.radiusAbs_m = 1000;
  /* moving fast */
  LightObject.kinematic.camera.deltaX = 2;

  /* angle is too big */
  LightObject.kinematic.world.horizontalAngle = 0.3f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");

  /* Disable coverage counting where not possible */
  COU_PROPERTY("hlaf_decision.c:HLAFDecision_TurnOnDelayTTB:74-84", "Refactoring possible but to reach MC/DC but in this way it's easier to read.");
}

/** \test
 *  \description
 *     Test that object is not relevant if high beam is not in a valid state. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_034(DecisionFindRelevantVehicle_034, "Test that object is not relevant if high beam is not in a valid state")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is set to unkown */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     Test that object is not relevant if distance is above china mode distance. \n
 *     calls function HLAFDecision_FindRelevantVehicle() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_035(DecisionFindRelevantVehicle_035, "Test that object is not relevant if distance is above china mode distance")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is set to unkown */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;

  LightObject.kinematic.world.x = 4001;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_FALSE, "Oncoming was not detected");
}

/** \test
 *  \description
 *     Test that object is not relevant if high beam is not in a valid state. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bPrecDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_036(DecisionFindRelevantVehicle_036, "Test that preceding object is relevant if distance is below china mode distance")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is set to unkown */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;

  LightObject.kinematic.world.x = 400;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_TRUE, "preceding was detected");
}

/** \test
 *  \description
 *     Test that object is not relevant if high beam is not in a valid state. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to false \n */
TEST_DecisionFindRelevantVehicle_037(DecisionFindRelevantVehicle_037, "Test that preceding object is not relevant if distance is above china mode distance")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_FALSE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is set to unkown */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;

  LightObject.kinematic.world.x = 4001;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bPrecDetected, b_FALSE, "preceding was not detected");
}

/** \test
 *  \description
 *     A relevant fast moving oncoming object is in the internal object list. The high beam state is on and the object is inside the ROI. Highway was not detected. Big radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_038(DecisionFindRelevantVehicle_038, "Test that relevant fast moving oncoming object on country road with a big radius sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was not detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* big radius */
  FData.CamData.radiusAbs_m = 1000;
  /* right side fast moving vehicle into FOV */
  LightObject.kinematic.camera.deltaX = -5;
  LightObject.kinematic.world.horizontalAngle = -0.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     A relevant fast moving oncoming object is in the internal object list. The high beam state is on and the object is inside the ROI. Highway was not detected. Big radius. bOncDetected shall be set. \n
 *     calls function HLAFDecision_SetHBState() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true \n */
TEST_DecisionFindRelevantVehicle_039(DecisionFindRelevantVehicle_039, "Test that relevant fast moving oncoming object on country road with a big radius sets the bOncDetected to true")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
  /* highway was not detected */
  FData.DecisionOut.eHighwayState = LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE;
  /* big radius */
  FData.CamData.radiusAbs_m = 1000;
  /* right side fast moving vehicle into FOV */
  LightObject.kinematic.camera.deltaX = 5;
  LightObject.kinematic.world.horizontalAngle = -0.1f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
}

/** \test
 *  \description
 *     When a relevant oncoming object was detected. Distance to object is too big, so OncomingMax is set in LHT traffic style. \n
 *     calls function HLAFDecision_FindRelevantVehicle() \n
 *  \precondition
 *     None \n
 *  \result
 *     bOncDetected is set to true. OncomingMax delay is set. \n */
TEST_DecisionFindRelevantVehicle_040(DecisionFindRelevantVehicle_040, "Test that maximum delay is set in case of fast leaving oncoming object with LHT traffic style, which has a too big distance")
{
  /* Initialize Data */
  InitData();

  /* create relevant int object */
  CreateRelevantIntObject(&FData, b_TRUE);

  /* Set light object list */
  SetLightObjectList(&LsdLightObjectList);

  /* high beam sate is off */
  FData.hlafMatrixData.Out.Matrix.HighBeamState = RTE_HLAF_HB_STATE_OFF;

  /* highway was detected */
  FData.DecisionOut.eHighwayState = RTE_HLAF_MTWY_COUNTRY;

  /* right hand traffic */
  FData.DecisionOut.eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHT;

  /* distance is too big */
  LightObject.kinematic.world.x = 40.0f;

  /* call function */
  COU_CALL(HLAFDecision_FindRelevantVehicle(&ReqPorts, &FData, &DecisionParameters, &LsdLightObjectList, &RelVeh), "function call");

  /* check output */
  COU_ASSERT_EQUAL(RelVeh.bOncDetected, b_TRUE, "Oncoming was detected");
  COU_ASSERT_EQUAL(RelVeh.Onc_s, CPar_HlafPar.TurnOnDelay.OncomingMax, "OncomingMax delay was set");
}



/** list of all test methods of the related suite. */
cou_test_t hla_Decision[] = {
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_001),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_002),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_003),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_004),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_005),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_006),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_007),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_008),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_009),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_010),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_011),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_012),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_013),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_014),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_015),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_016),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_017),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_018),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_019),
   COU_ADD_TEST(DecisionSetTurnOffReasonGlob_020),
   COU_ADD_TEST(HLAFDecision_SetTurnOffReasonGlob_HeavyFogDetected_BadWeatherTurnOffReasonIsSet),
   COU_ADD_TEST(HLAFDecision_SetTurnOffReasonGlob_MediumFogDetected_BadWeatherTurnOffReasonIsSet),
   COU_ADD_TEST(HLAFDecision_SetTurnOffReasonGlob_BadWeatherDetected_BadWeatherTurnOffReasonIsSet),
   COU_ADD_TEST(HLAFDecision_SetTurnOffReasonGlob_GoodWeatherDetected_BadWeatherTurnOffReasonIsNotSet),
   COU_ADD_TEST(HLAFDecision_CheckForRelevantEMObjects_EMObjDetected_RelVehFlagIsSet),
   COU_ADD_TEST(HLAFDecision_CheckForRelevantEMObjects_EMObjNotDetected_RelVehFlagIsNotSet),
   COU_ADD_TEST(HLAFDecision_CheckForRelevantRadarObjects_RadarObjDetected_RelVehFlagIsSet),
   COU_ADD_TEST(HLAFDecision_CheckForRelevantRadarObjects_RadarObjNotDetected_RelVehFlagIsNotSet),
   COU_ADD_TEST(DecisionSetTurnOffReason_001),
   COU_ADD_TEST(DecisionSetTurnOffReason_002),
   COU_ADD_TEST(DecisionSetTurnOffReason_003),
   COU_ADD_TEST(DecisionSetTurnOffReason_004),
   COU_ADD_TEST(DecisionSetTurnOffReason_005),
   COU_ADD_TEST(DecisionSetTurnOffReason_006),
   COU_ADD_TEST(HLAFDecision_SetTurnOffReason_RadarObjDetected_TurnOffReasonSet),
   COU_ADD_TEST(HLAFDecision_SetTurnOffReason_RadarObjNotDetected_NoTurnOffReasonSet),
   COU_ADD_TEST(DecisionSetHBState_001),
   COU_ADD_TEST(DecisionSetHBState_002),
   COU_ADD_TEST(DecisionSetHBState_003),
   COU_ADD_TEST(DecisionSetHBState_004),
   COU_ADD_TEST(DecisionFindRelevantVehicle_001),
   COU_ADD_TEST(DecisionFindRelevantVehicle_002),
   COU_ADD_TEST(DecisionFindRelevantVehicle_003),
   COU_ADD_TEST(DecisionFindRelevantVehicle_004),
   COU_ADD_TEST(DecisionFindRelevantVehicle_005),
   COU_ADD_TEST(DecisionFindRelevantVehicle_006),
   COU_ADD_TEST(DecisionFindRelevantVehicle_007),
   COU_ADD_TEST(DecisionFindRelevantVehicle_008),
   COU_ADD_TEST(DecisionFindRelevantVehicle_009),
   COU_ADD_TEST(DecisionFindRelevantVehicle_010),
   COU_ADD_TEST(DecisionFindRelevantVehicle_012),
   COU_ADD_TEST(DecisionFindRelevantVehicle_013),
   COU_ADD_TEST(DecisionFindRelevantVehicle_014),
   COU_ADD_TEST(DecisionFindRelevantVehicle_015),
   COU_ADD_TEST(HLAFDecision_FindRelevantVehicle_ObjectIsBehindCar_PrecDetected),
   COU_ADD_TEST(DecisionFindRelevantVehicle_016),
   COU_ADD_TEST(DecisionFindRelevantVehicle_017),
   COU_ADD_TEST(DecisionFindRelevantVehicle_018),
   COU_ADD_TEST(DecisionFindRelevantVehicle_019),
   COU_ADD_TEST(DecisionFindRelevantVehicle_020),
   COU_ADD_TEST(DecisionFindRelevantVehicle_021),
   COU_ADD_TEST(DecisionFindRelevantVehicle_022),
   COU_ADD_TEST(DecisionFindRelevantVehicle_023),
   COU_ADD_TEST(DecisionFindRelevantVehicle_024),
   COU_ADD_TEST(DecisionFindRelevantVehicle_025),
   COU_ADD_TEST(DecisionFindRelevantVehicle_026),
   COU_ADD_TEST(DecisionFindRelevantVehicle_027),
   COU_ADD_TEST(DecisionFindRelevantVehicle_028),
   COU_ADD_TEST(DecisionFindRelevantVehicle_029),
   COU_ADD_TEST(DecisionFindRelevantVehicle_030),
   COU_ADD_TEST(DecisionFindRelevantVehicle_031),
   COU_ADD_TEST(DecisionFindRelevantVehicle_032),
   COU_ADD_TEST(DecisionFindRelevantVehicle_033),
   COU_ADD_TEST(DecisionFindRelevantVehicle_034),
   COU_ADD_TEST(DecisionFindRelevantVehicle_035),
   COU_ADD_TEST(DecisionFindRelevantVehicle_036),
   COU_ADD_TEST(DecisionFindRelevantVehicle_037),
   COU_ADD_TEST(DecisionFindRelevantVehicle_038),
   COU_ADD_TEST(DecisionFindRelevantVehicle_039),
   COU_ADD_TEST(DecisionFindRelevantVehicle_040),
   COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(DecisionInit, "Initialize hlaf decision")
{
  //COU_LOG("Set Inputs to zero");
  //InitBlockageInputs();
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Decision, hla_Decision, DecisionInit, "module test for hlaf decision"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */

