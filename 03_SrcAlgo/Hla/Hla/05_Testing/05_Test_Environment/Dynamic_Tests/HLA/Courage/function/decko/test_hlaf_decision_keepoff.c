/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>
/* inclue for error handling */
#include "hlaf_decision_keepoff.h"
#include "hla_errorhandling.h"

#include "../../mockup_services.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_SetKORTurnOnDelaySlowOvertaker_001 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_002 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_003 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_004 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_005 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_006 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_007 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_008 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_009 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_010 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_011 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_012 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_013 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_014 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_015 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_016 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_017 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_018 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_019 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_020 COU_TEST
#define TEST_SetKORTurnOnDelaySlowOvertaker_021 COU_TEST
#define TEST_SetKORSpeed_001 COU_TEST
#define TEST_SetKORSpeed_002 COU_TEST
#define TEST_SetKORMaybeCity_001 COU_TEST
#define TEST_SetKORMaybeCity_002 COU_TEST
#define TEST_SetKORMaybeCity_003 COU_TEST
#define TEST_SetKORMaybeCity_004 COU_TEST
#define TEST_SetKORMaybeCity_005 COU_TEST
#define TEST_SetKORMaybeCity_006 COU_TEST

#define TEST_SetKOR_SmallRadius_001 COU_TEST
#define TEST_SetKOR_SmallRadius_002 COU_TEST
#define TEST_SetKOR_MinTimeHBoff_001 COU_TEST
#define TEST_SetKOR_TurnOnDelay_001 COU_TEST
#define TEST_SetKOR_TurnOnDelay_002 COU_TEST
#define TEST_SetKOR_TurnOnDelay_003 COU_TEST
#define TEST_SetKOR_TurnOnDelay_004 COU_TEST
#define TEST_SetKOR_TurnOnDelay_005 COU_TEST
#define TEST_SetKOR_TurnOnDelay_006 COU_TEST
#define TEST_SetKOR_TurnOnDelayTruckLights_001 COU_TEST
#define TEST_SetKOR_TurnOnDelayTruckLights_002 COU_TEST
#define TEST_SetKOR_TurnOnDelayTruckLights_003 COU_TEST
#define TEST_SetKOR_TurnOnDelayTruckLights_004 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_001 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_002 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_003 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_004 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_005 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_006 COU_TEST
#define TEST_SetKOR_PrecedingVehLost_007 COU_TEST
#define TEST_SetKOR_PotentialVehicle_001 COU_TEST
#define TEST_SetKOR_PotentialVehicle_002 COU_TEST
#define TEST_SetKOR_PotentialVehicle_003 COU_TEST
#define TEST_SetKOR_PotentialVehicle_004 COU_TEST
#define TEST_SetKOR_PotentialVehicle_005 COU_TEST
#define TEST_SetKOR_PotentialVehicle_006 COU_TEST
#define TEST_SetKOR_PotentialVehicle_007 COU_TEST
#define TEST_SetKOR_PotentialVehicle_008 COU_TEST
#define TEST_SetKOR_PotentialVehicle_009 COU_TEST
#define TEST_SetKOR_PotentialVehicle_010 COU_TEST
#define TEST_SetKOR_PotentialVehicle_011 COU_TEST
#define TEST_SetKOR_PotentialVehicle_012 COU_TEST
#define TEST_SetKOR_PotentialVehicle_013 COU_TEST
#define TEST_SetKOR_PotentialVehicle_014 COU_TEST
#define TEST_SetKOR_PotentialVehicle_015 COU_TEST
#define TEST_SetKOR_PotentialVehicle_016 COU_TEST
#define TEST_SetKOR_PotentialVehicle_017 COU_TEST
#define TEST_SetKOR_PotentialVehicle_018 COU_TEST
#define TEST_SetKOR_PotentialVehicle_019 COU_TEST
#define TEST_SetKOR_PotentialVehicle_020 COU_TEST
#define test_HLAFDecision_SetKeepOffReason_KeepOffReasonsUnset_Success COU_TEST
#define test_HLAFDecision_SetKeepOffReason_KeepOffReasonsNotUnset_NoSuccess COU_TEST
#define test_HLAFDecision_SetKeepOffReason_TurnOffReasonFogIsSet_KeepOffReasonFogIsSet COU_TEST
#define test_HLAFDecision_SetKeepOffReason_TurnOffReasonBadWeatherIsSet_KeepOffReasonBadWeatherIsSet COU_TEST


void InitData(void);
void CreateValidEMOBject(void);
void SetDefaultParameter(void);


HLAFData_t                      FData;
t_DecisionParametersKeepOff     ParKeepOff;
t_DecisionParametersTurnOnDelay ParTurnOnDelay;
RTE_HLAF_HighBeamState          eHighBeamStatePrev;
HLAFRelevantVehicle_t           RelVeh;
HLAFTurnOffReason_t             TurnOffReason;
HLAFKeepOffReason_t             KeepOffReason;

/* Init function which memsets all of the input data and links the data buffer to the corresponding pointers */
void InitData(void)
{
  Mockup_InitGlobVars();

  memset(&FData, 0, sizeof(FData));
  memset(&ParKeepOff, 0, sizeof(ParKeepOff));
  memset(&ParTurnOnDelay, 0, sizeof(ParTurnOnDelay));
  memset(&eHighBeamStatePrev, 0, sizeof(eHighBeamStatePrev));
  memset(&RelVeh, 0, sizeof(RelVeh));
  memset(&TurnOffReason, 0, sizeof(TurnOffReason));
  memset(&KeepOffReason, 0, sizeof(KeepOffReason));

  LsdLightObjectList.numObjects = 0;
  
  HLA_ErrorHandling_Init();
}

/* Function to create a valid EM object to test slow overtaker delay */
void CreateValidEMOBject(void)
{
  /* create valid EM object */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 1;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 0;
  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_CAR;
  EMObjectsList.aObject[0].Attributes.uiClassConfidence = 100u;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_MOVING,
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 90u;
  EMObjectsList.aObject[0].Kinematic.fDistX = 2.0f;
  EMObjectsList.aObject[0].Kinematic.fDistY = 3.0f;
  EMObjectsList.aObject[0].Kinematic.fVrelX = -2.0f;
}

/* Function to set default parameters */
void SetDefaultParameter(void)
{
    /* internal parameter */
  ParKeepOff.minDistanceSO = 10.0f;
  ParKeepOff.maxLateralOffsetSO = 10u;
  ParKeepOff.maxDeltaSpeedSO = -5.5f;
  ParKeepOff.minTraceTimeSO = 10;
  ParKeepOff.maxDeltaXSO = 10;
  ParKeepOff.MayBeCity.Delay_Onc = 1.0f;
  ParKeepOff.MayBeCity.Delay_Prec = 1.0f;
  ParKeepOff.MayBeCity.Delay_Global = 1.0f;
  ParKeepOff.smallRadiusRadius2TurnsOnThres = 10.0f;
  ParKeepOff.smallRadiusTurnOnDelay = 1.0f;
  ParKeepOff.minTimeHBOff_s = 5.0f;
  ParKeepOff.maxDist2Cover = 80.0f;
  ParKeepOff.KeepOffPotVeh.low_probability_vehicle = 5;
  ParKeepOff.KeepOffPotVeh.high_probability_vehicle = 50;
  ParKeepOff.KeepOffPotVeh.Delay_Glob = 1.0f;
  ParKeepOff.KeepOffPotVeh.Delay_Onc = 2.0f;
  ParKeepOff.KeepOffPotVeh.Delay_Prec = 3.0f;
  ParKeepOff.minClassConfidenceSO = 80u;
  ParKeepOff.minProbOfExSO = 75u;

  ParTurnOnDelay.initialTurnOnDelay = 1.0f;

  /* coding parameters */
  CPar_HlafPar.TurnOnDelay.SlowOvertaking = 8.0f;
  CPar_HlafPar.TurnOnDelay.OncomingMaxHighway = 5.0f;
  CPar_HlafPar.TurnOnDelay.Fog = 8.0f;
  
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. EM provides a relevant object, the high beam state is off. Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_001(SetKORTurnOnDelaySlowOvertakerTest_001, "Test of slow overtaker detection")
{

  /* Initialize Data*/
  InitData();
  
  /* Set parameters to default values */
  SetDefaultParameter();
  
  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;
  
  /* create valid EM object */
  CreateValidEMOBject();
  
  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, CPar_HlafPar.TurnOnDelay.SlowOvertaking, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_TRUE, "Keep off reason is set");

  /* --- Test for Truck --- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, CPar_HlafPar.TurnOnDelay.SlowOvertaking, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_TRUE, "Keep off reason is set");

}

/** \test
 *  \description
 *     Test that no delay is set when there no preceding delay active. Slow Overtaker delay shall only be set in case of a previously detected preceding car \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set. Keep off reason for slow overtaker is also not set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_002(SetKORTurnOnDelaySlowOvertakerTest_002, "Test that no slow overtaker delay is set when no preceding vehicle was present")
{
    /* Initialize Data*/
  InitData();
  /* Set parameters to default values */
  SetDefaultParameter();
  
  /* Delay time for preceding object is not active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 0.0f;
  
  /* create valid EM object */
  CreateValidEMOBject();
  
  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");

}

/** \test
 *  \description
 *     Test that no delay is set when the high beam is on. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set. Keep off reason for slow overtaker is also not set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_003(SetKORTurnOnDelaySlowOvertakerTest_003, "Test that no slow overtaker keep off delay is set when high beam is on")
{
  /* Initialize Data*/
  InitData();
  
  /* Set parameters to default values */
  SetDefaultParameter();
  
  /* reset delay timer */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s = 0.0f;
  
  /* high beam state is on */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;
  
  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
  
}

/** \test
 *  \description
 *     Test that invalid inputs from EM are caught in function. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. No exception/invalid access is happending \n */
TEST_SetKORTurnOnDelaySlowOvertaker_004(SetKORTurnOnDelaySlowOvertakerTest_004, "Test that invalid inputs from EM are caught")
{
  /* Initialize Data*/
  InitData();
  
  /* Set parameters to default values */
  SetDefaultParameter();
  
  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;
  
  /* create valid EM object */
  CreateValidEMOBject();
  
  /* invalid input */
  EMObjectsList.HeaderObjList.iNumOfUsedObjects = 100;
  EMObjectsList.HeaderObjList.iSortedObjectList[0] = 100;
  EMObjectsList.HeaderObjList.iSortedObjectList[1] = -100;
  
  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  
  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, CPar_HlafPar.TurnOnDelay.SlowOvertaking, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_TRUE, "Keep off reason is set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object so that a slow overtaker gets detected. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_005(SetKORTurnOnDelaySlowOvertakerTest_005, "Test of fallback solution with relevant light object")
{
  LSD_LightObject_t LiObj;
  
  /* Initialize Data*/
  InitData();
  
  /* Set parameters to default values */
  SetDefaultParameter();
  
  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;
  
  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;
  
  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  
  /* create valid/relevant light object */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 40;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;
  
  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, CPar_HlafPar.TurnOnDelay.SlowOvertaking, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_TRUE, "Keep off reason is set");
  
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but don't set the preceding flag. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_006(SetKORTurnOnDelaySlowOvertakerTest_006, "Test of fallback solution with valid light object, but object is not a preceding")
{
  /* create light object */
  LSD_LightObject_t LiObj;
  
  /* Initialize Data */
  InitData();
  
  /* Set parameters to default values */
  SetDefaultParameter();
  
  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;
  
  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;
  
  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  
  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_FALSE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 40;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;
  
  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");
  
  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. Relativ speed is not valid. Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_007(SetKORTurnOnDelaySlowOvertakerTest_007, "Test of slow overtaker detection, fVrelX is not valid")
{

  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Kinematic.fVrelX = 2.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Kinematic.fVrelX = 2.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. fDistY is not valid. Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_008(SetKORTurnOnDelaySlowOvertakerTest_008, "Test of slow overtaker detection, fDistY is not valid")
{

  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Kinematic.fDistY = 12.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Kinematic.fDistY = 12.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. fDistX is not valid. Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_009(SetKORTurnOnDelaySlowOvertakerTest_009, "Test of slow overtaker detection, fDistX is not valid")
{

  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Kinematic.fDistX = 12.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Kinematic.fDistX = 12.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. uiProbabilityOfExistence is too low. Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_010(SetKORTurnOnDelaySlowOvertakerTest_010, "Test of slow overtaker detection, uiProbabilityOfExistence is too low")
{
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 50;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Qualifiers.uiProbabilityOfExistence = 50;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. eDynamicProperty is invalid (oncoming). Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_011(SetKORTurnOnDelaySlowOvertakerTest_011, "Test of slow overtaker detection, eDynamicProperty is invalid (oncoming)")
{
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. eDynamicProperty is invalid (stationary). Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_012(SetKORTurnOnDelaySlowOvertakerTest_012, "Test of slow overtaker detection, eDynamicProperty is invalid (stationary)")
{
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Attributes.eDynamicProperty = EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     Test of Slow Overtaker detection.
 *     Preceding delay timer is active, which means that a preceding was detected. The high beam state is off. uiClassConfidence is too low. Test for car and truck. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is set and keep off reason for slow overtaker is also set. \n */
TEST_SetKORTurnOnDelaySlowOvertaker_013(SetKORTurnOnDelaySlowOvertakerTest_013, "Test of slow overtaker detection, uiClassConfidence is too low")
{
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.uiClassConfidence = 50u;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");

  /* -- Test for Truck -- */
  /* Initialize Data*/
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* create valid EM object */
  CreateValidEMOBject();

  EMObjectsList.aObject[0].Attributes.eClassification = EM_GEN_OBJECT_CLASS_TRUCK;
  EMObjectsList.aObject[0].Attributes.uiClassConfidence = 50u;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was set correctly");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but light is above ROI. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_014(SetKORTurnOnDelaySlowOvertakerTest_014, "Test of fallback solution with valid light object, but light is above ROI")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 5;
  LiObj.kinematic.camera.y = 40;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but light is below ROI. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_015(SetKORTurnOnDelaySlowOvertakerTest_015, "Test of fallback solution with valid light object, but light is below ROI")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 110;
  LiObj.kinematic.camera.y = 40;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but light is too much on the left of the ROI. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_016(SetKORTurnOnDelaySlowOvertakerTest_016, "Test of fallback solution with valid light object, but light is too much on the left of the ROI")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 10;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but light is too much on the right of the ROI. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_017(SetKORTurnOnDelaySlowOvertakerTest_017, "Test of fallback solution with valid light object, but light is too much on the right of the ROI")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 210;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but time to border of light is not zero. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_018(SetKORTurnOnDelaySlowOvertakerTest_018, "Test of fallback solution with valid light object, but time to border is not zero")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 50;
  LiObj.kinematic.timeToHlaBorder = 10.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but cycles traced is too small. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_019(SetKORTurnOnDelaySlowOvertakerTest_019, "Test of fallback solution with valid light object, but cycles traced is too small")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 50;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 2;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but deltaXFiltered is too big. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_020(SetKORTurnOnDelaySlowOvertakerTest_020, "Test of fallback solution with valid light object, but deltaXFiltered is too big")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 50;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 100;
  LiObj.kinematic.world.y = 5.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     EM object list is not availble. Use fallback solution. Create valid light object, but lateral offset is too big. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Slow Overtaker delay timer is not set and keep off reason for slow overtaker is also not set.\n */
TEST_SetKORTurnOnDelaySlowOvertaker_021(SetKORTurnOnDelaySlowOvertakerTest_021, "Test of fallback solution with valid light object, but lateral offset is too big")
{
  /* create light object */
  LSD_LightObject_t LiObj;

  /* Initialize Data */
  InitData();

  /* Set parameters to default values */
  SetDefaultParameter();

  /* EM object list is not available */
  ReqPorts.pGenObjectList = NULL;

  /* Delay time for preceding object is active */
  KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s = 5.0f;

  /* high beam state is off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* create valid light object*/
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].pLightObject = &LiObj;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.ySplit = 20;
  LsdLightObjectList.roi.y2 = 200;
  LiObj.kinematic.camera.x = 20;
  LiObj.kinematic.camera.y = 50;
  LiObj.kinematic.timeToHlaBorder = 0.0f;
  LiObj.general.cyclesTraced = 20;
  LiObj.kinematic.camera.deltaXFiltered = 1;
  LiObj.kinematic.world.y = 50.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_SO_s, 0.0f, "Slow Overtaking delay was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER), b_FALSE, "Keep off reason is not set");
}

/** \test
 *  \description
 *     When the keepOffHLABySpeed bit is set, this should trigger the speed keep off reason. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_KEEP_OFF_REASON_SPEED_ACC bit is set in keep off reasons.\n */
TEST_SetKORSpeed_001(SetKORSpeed_001, "Test that keepOffHLABySpeed bit triggers the speed keep off reason")
{
  /* Initialize Data */
  InitData();

  /* Bit is set */
  FData.DecisionData.Speed.keepOffHLABySpeed = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC), b_TRUE, "Speed Keep off reason is set");
}

/** \test
 *  \description
 *     When the keepOffHLABySpeed bit is not set, this should not trigger the speed keep off reason. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     HLAF_KEEP_OFF_REASON_SPEED_ACC bit is not set in keep off reasons.\n */
TEST_SetKORSpeed_002(SetKORSpeed_002, "Test that keepOffHLABySpeed bit doesn't trigger the speed keep off reason")
{
  /* Initialize Data */
  InitData();

  /* Bit is not set */
  FData.DecisionData.Speed.keepOffHLABySpeed = 0;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC), b_FALSE, "Speed Keep off reason is set");
}

/** \test
 *  \description
 *     When an oncoming was detected and the previous high beam state was off and the city state is set to maybe, the TurnOnTimer_Onc shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off maybe city delay oncoming was set. City maybe keep off reason is set. \n */
TEST_SetKORMaybeCity_001(SetKORMaybeCity_001, "Test that maybe city keep off reason an delay is set in case of oncoming vehicle")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs for the maybe city delay */
  RelVeh.bOncDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Onc, ParKeepOff.MayBeCity.Delay_Onc, "Keep off maybe city delay oncoming was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC), b_TRUE, "City maybe keep off reason oncoming is set");
}

/** \test
 *  \description
 *     When an preceding was detected and the previous high beam state was off and the city state is set to maybe, the TurnOnTimer_Prec shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off maybe city delay preceding was set. City maybe keep off reason is set. \n */
TEST_SetKORMaybeCity_002(SetKORMaybeCity_002, "Test that maybe city keep off reason an delay is set in case of preceding vehicle")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs for the maybe city delay */
  RelVeh.bPrecDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Prec, ParKeepOff.MayBeCity.Delay_Prec, "Keep off maybe city delay preceding was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC), b_TRUE, "City maybe keep off reason preceding is set");
}

/** \test
 *  \description
 *     When a turn off reason is set and the previous high beam state was off and the city state is set to maybe, the TurnOnTimer_Prec shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off maybe city delay preceding was set. City maybe keep off reason is set. \n */
TEST_SetKORMaybeCity_003(SetKORMaybeCity_003, "Test that maybe city keep off reason an delay is set in case of global turn off reason")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  TurnOffReason.Reason = 1;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Glob, ParKeepOff.MayBeCity.Delay_Global, "Keep off maybe city delay global was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB), b_TRUE, "City maybe keep off reason global is set");
}

/** \test
 *  \description
 *     When a turn off reason is set and the previous high beam state was off and the city state is set to maybe, the TurnOnTimer_Prec shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off maybe city delay preceding was set. City maybe keep off reason is set. \n */
TEST_SetKORMaybeCity_004(SetKORMaybeCity_004, "Test that maybe city keep off reason an delay is set in case of global turn off reason")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_FALSE;
  RelVeh.bPrecDetected = b_FALSE;
  TurnOffReason.Reason = 0;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Onc, 0.0f, "Keep off maybe city delay oncoming was not set");
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Prec, 0.0f, "Keep off maybe city delay preceding was not set");
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Glob, 0.0f, "Keep off maybe city delay global was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC), b_FALSE, "City maybe keep off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC), b_FALSE, "City maybe keep off reason preceding is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB), b_FALSE, "City maybe keep off reason global is not set");
}

/** \test
 *  \description
 *     When a turn off reason is set and the previous high beam state was off and the city state is not set to maybe, the TurnOnTimer_Prec shall not be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off maybe city delay preceding was set. City maybe keep off reason is set. \n */
TEST_SetKORMaybeCity_005(SetKORMaybeCity_005, "Test that maybe city keep off reason an delay is not set in case of global turn off reason, but city state is not set to maybe")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  TurnOffReason.Reason = 1;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_NOT_DTCD;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Glob, 0.0f, "Keep off maybe city delay global was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB), b_FALSE, "City maybe keep off reason global is not set");
}

/** \test
 *  \description
 *     When a turn off reason is set and the previous high beam state was full on and the city state is not set to maybe, the TurnOnTimer_Prec shall not be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off maybe city delay preceding was set. City maybe keep off reason is set. \n */
TEST_SetKORMaybeCity_006(SetKORMaybeCity_006, "Test that maybe city keep off reason an delay is not set in case of global turn off reason, but high beam state is not off")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  TurnOffReason.Reason = 1;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_NOT_DTCD;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MayBeCity.TurnOnTimer_Glob, 0.0f, "Keep off maybe city delay global was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB), b_FALSE, "City maybe keep off reason global is not set");
}

/** \test
 *  \description
 *     When radius is small enough and previous high beam state was off, then the small radius keep off reason shall be set and the delay timer set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off delay for small radius was set. Small radius keep off reason is set. \n */
TEST_SetKOR_SmallRadius_001(SetKOR_SmallRadius_001, "Test that small radius keep off reason and delay is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.CamData.radiusAbs_m = 1.0f;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.SmallRadius.DelayTimer_s, ParKeepOff.smallRadiusTurnOnDelay, "Small radius delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS), b_TRUE, "Small radius keep off reason global is set");
}

/** \test
 *  \description
 *     When radius is not small enough and previous high beam state was off, then the small radius keep off reason shall be not set and the delay timer not set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off delay for small radius was not set. Small radius keep off reason is not set. \n */
TEST_SetKOR_SmallRadius_002(SetKOR_SmallRadius_002, "Test that small radius keep off reason and delay is not set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* radius is not small enough */
  FData.CamData.radiusAbs_m = 100.0f;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.SmallRadius.DelayTimer_s, 0.0f, "Small radius delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS), b_FALSE, "Small radius keep off reason global is not set");
}

/** \test
 *  \description
 *     Check that delay timer is set when the high beam state is on, then check that the delay is reduced and the turn off reason hb off set in case high beam state switches to off. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Delay timer was set. When high beam state switches to off delay is reduced and keep off reason min time hb off is set. \n */
TEST_SetKOR_MinTimeHBoff_001(SetKOR_MinTimeHBoff_001, "Test min time hb keep off reason is correctly set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* highbeams was on */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MinTimeHBoff.HBOffTimer_s, ParKeepOff.minTimeHBOff_s, "Delay timer was set");

  /* highbeams was off */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.CamData.dtimeFwd_s = 1.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.MinTimeHBoff.HBOffTimer_s, (ParKeepOff.minTimeHBOff_s - FData.CamData.dtimeFwd_s), "Delay timer was reduced");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MIN_TIME_HB_OFF), b_TRUE, "Min time HB off keep off reason is set");
}

/** \test
 *  \description
 *     When the not available turn off reason is set an init timer shall be active and the init delay keep off reason set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Init delay timer was set. Init delay keep off reason is set. \n */
TEST_SetKOR_TurnOnDelay_001(SetKOR_TurnOnDelay_001, "Test that small radius keep off reason and delay is not set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.DecisionData.TurnOffReason.Reason = HLAF_TURN_OFF_REASON_NOT_AVL;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.InitTimer_s, ParTurnOnDelay.initialTurnOnDelay, "Init delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT), b_TRUE, "Init delay keep off reason is set");
}

/** \test
 *  \description
 *     When an oncoming vehicle was detected and the previous high beam state was off, the turn on timer for oncoming shall be set and the corresponding keep off reason. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Oncoming turn on timer was set. Turn on delay oncoming keep off reason is set. \n */
TEST_SetKOR_TurnOnDelay_002(SetKOR_TurnOnDelay_002, "Test that oncoming keep off reason and delay is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  RelVeh.Onc_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_s, RelVeh.Onc_s, "Oncoming turn on timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC), b_TRUE, "Turn on delay oncoming keep off reason is set");
}



/** \test
 *  \description
 *     When an preceding vehicle was detected and the previous high beam state was off, the turn on timer for preceding shall be set and the corresponding keep off reason. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Preceding turn on timer was set. Turn on delay preceding keep off reason is set. \n */
TEST_SetKOR_TurnOnDelay_003(SetKOR_TurnOnDelay_003, "Test that preceding keep off reason and delay is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bPrecDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s, RelVeh.Prec_s, "Preceding turn on timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC), b_TRUE, "Turn on delay preceding keep off reason is set");
}

/** \test
 *  \description
 *     Test that no delay timer and keep off reason for turn on delay is set when no vehicle was detected, but the high beam state is off. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Turn on timer was not set. Turn on delay keep off reason is not set. \n */
TEST_SetKOR_TurnOnDelay_004(SetKOR_TurnOnDelay_004, "Test that preceding keep off reason and delay is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  RelVeh.Onc_s = 2.0f;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.InitTimer_s, 0.0f, "Init delay timer was not set");
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_s, 0.0f, "Oncoming turn on timer was not set");
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s, 0.0f, "Preceding turn on timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT), b_FALSE, "Turn on delay init keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC), b_FALSE, "Turn on delay oncoming keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC), b_FALSE, "Turn on delay preceding keep off reason is not set");
}

/** \test
 *  \description
 *     When an oncoming vehicle was detected and the previous high beam state was not off, the turn on timer for oncoming shall not be set and the keep off reason also not be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Oncoming turn on timer was set. Turn on delay oncoming keep off reason is set. \n */
TEST_SetKOR_TurnOnDelay_005(SetKOR_TurnOnDelay_005, "Test that oncoming keep off reason and delay is not set, when previous high beam state was full on")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;
  RelVeh.Onc_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_s, 0.0f, "Oncoming turn on timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC), b_FALSE, "Turn on delay oncoming keep off reason is not set");
}

/** \test
 *  \description
 *     When an preceding vehicle was detected and the previous high beam state was on, the turn on timer for preceding shall be not set and also no keep off reason shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Preceding turn on timer was set. Turn on delay preceding keep off reason is set. \n */
TEST_SetKOR_TurnOnDelay_006(SetKOR_TurnOnDelay_006, "Test that preceding keep off reason and delay is not set, when previous high beam state was on")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bPrecDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Prec_s,0.0f, "Preceding turn on timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC), b_FALSE, "Turn on delay preceding keep off reason is not set");
}

/** \test
 *  \description
 *     When oncoming delay is active and there is at least on truck light bit set in the light object list, the delay shall be set when the previous high beam state was off. Then also the keep off reason shall be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Oncoming truck lights delay timer was set. Oncoming truck lights keep off reason is set. \n */
TEST_SetKOR_TurnOnDelayTruckLights_001(SetKOR_TurnOnDelayTruckLights_001, "Test that oncoming truck light delay and keep off reason is set")
{
  /* Initialize Data */
  InitData();

  /* Set parameter */
  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, CPar_HlafPar.TurnOnDelay.OncomingMaxHighway, "Oncoming truck lights delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS), b_TRUE, "Oncoming truck lights keep off reason is set");
}

/** \test
 *  \description
 *     When oncoming delay is active and there is no truck light bit set in the light object list, the delay shall not be set when the previous high beam state was off. Then also the keep off reason shall not be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Oncoming truck lights delay timer was not set. Oncoming truck lights keep off reason is not set. \n */
TEST_SetKOR_TurnOnDelayTruckLights_002(SetKOR_TurnOnDelayTruckLights_002, "Test that oncoming truck light delay and keep off reason is not set, when no status bit is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;
  LsdLightObjectList.numObjects = 1;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS), b_FALSE, "Oncoming truck lights keep off reason is not set");
}

/** \test
 *  \description
 *     When oncoming delay is not active and there is at least on truck light bit set in the light object list, the delay shall not be set when the previous high beam state was off. Then also the keep off reason shall not be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Oncoming truck lights delay timer was not set. Oncoming truck lights keep off reason is not set. \n */
TEST_SetKOR_TurnOnDelayTruckLights_003(SetKOR_TurnOnDelayTruckLights_003, "Test that oncoming truck light delay and keep off reason is not set, when no oncoming delay is active")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_FALSE;
  RelVeh.Onc_s = 2.0f;
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS), b_FALSE, "Oncoming truck lights keep off reason is not set");
}

/** \test
 *  \description
 *     When oncoming delay is active and there is at least on truck light bit set in the light object list, the delay shall not be set when the previous high beam state is on. Then also the keep off reason shall not be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Oncoming truck lights delay timer was not set. Oncoming truck lights keep off reason is not set. \n */
TEST_SetKOR_TurnOnDelayTruckLights_004(SetKOR_TurnOnDelayTruckLights_004, "Test that oncoming truck light delay and keep off reason is not set, when previous high beam state is on")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  RelVeh.bOncDetected = b_FALSE;
  RelVeh.Onc_s = 2.0f;
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_FULL_ON;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS), b_FALSE, "Oncoming truck lights keep off reason is not set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PrecedingVehLost_001(SetKOR_PrecedingVehLost_001, "Test that preceding vehicle lost keep off reason is set")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 1.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 2.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PrecedingVehLost_002(SetKOR_PrecedingVehLost_002, "Test that preceding vehicle lost keep off reason is set, with small y distance")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 1.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 2.0f;
  LightObject.kinematic.world.y = 0.01f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall not be set, when rMax is too big \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is not set. \n */
TEST_SetKOR_PrecedingVehLost_003(SetKOR_PrecedingVehLost_003, "Test that preceding vehicle lost keep off reason is not set, rMax is too big")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 260.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 0.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 500.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_FALSE, "Vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall not be set, when timegap is not reached. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is not set. \n */
TEST_SetKOR_PrecedingVehLost_004(SetKOR_PrecedingVehLost_004, "Test that preceding vehicle lost keep off reason is not set, timegap is not reached")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 0.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 500.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_FALSE, "Vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall be set, when the vehicle is in a curve. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PrecedingVehLost_005(SetKOR_PrecedingVehLost_005, "Test that preceding vehicle lost keep off reason is set, in case vehicle is in curve")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  FData.CamData.radiusAbs_m = 2.0f;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 0.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 2.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall be set, if distance to cover is active, but status bit of light object is set to none. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PrecedingVehLost_006(SetKOR_PrecedingVehLost_006, "Test that preceding vehicle lost keep off reason is set, when distance2cover is active, but status bit of light object is set to none")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 1.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_NONE;
  LightObject.kinematic.world.x = 2.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When the loss of a preceding vehicle gets detected the keep off reason shall be set, if distance to cover is active, but world distance of object is too close. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PrecedingVehLost_007(SetKOR_PrecedingVehLost_007, "Test that preceding vehicle lost keep off reason is set, when distance2cover is active, but world distance of object is too close")
{
  LSD_LightObject_t LightObject;
  /* Initialize Data */
  InitData();

  SetDefaultParameter();

  /* set inputs */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 1.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 0.5f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  //COU_ASSERT_EQUAL(KeepOffReason.TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f, "Oncoming truck lights delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential oncoming vehicle is in the HLA ROI and another turn off reason is preset a delay shall be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_001(SetKOR_PotentialVehicle_001, "Test that in case of potential oncoming vehicle a delay and keep off reason is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 20;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , ParKeepOff.KeepOffPotVeh.Delay_Glob, "Global delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle is in the HLA ROI and another turn off reason is preset a delay shall be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_002(SetKOR_PotentialVehicle_002, "Test that in case of potential preceding vehicle a delay and keep off reason is set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 20;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , ParKeepOff.KeepOffPotVeh.Delay_Glob, "Global delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle with high probability is in the HLA ROI and another turn off reason is preset a delay shall be set when oncoming delay is active. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_003(SetKOR_PotentialVehicle_003, "Test that in case of potential preceding vehicle high probability a delay and keep off reason is set when oncoming delay is active")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 80;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for oncoming */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , ParKeepOff.KeepOffPotVeh.Delay_Glob, "Global delay timer was set");
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Onc , ParKeepOff.KeepOffPotVeh.Delay_Onc, "Oncoming delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "GLobal vehicle lost keep off reason is set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_ONC), b_TRUE, "Oncoming vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle with high probability is in the HLA ROI and another turn off reason is preset a delay shall be set when preceding delay is active. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_004(SetKOR_PotentialVehicle_004, "Test that in case of potential preceding vehicle high probability a delay and keep off reason is set when preceding delay is active")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 80;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for preceding */
  RelVeh.bPrecDetected = b_TRUE;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , ParKeepOff.KeepOffPotVeh.Delay_Glob, "Global delay timer was set");
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Prec , ParKeepOff.KeepOffPotVeh.Delay_Prec, "Preceding delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "GLobal vehicle lost keep off reason is set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC), b_TRUE, "Preceding vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle with high probability is in the HLA ROI and another turn off reason is preset a delay shall not be set when time to HLA border is too small. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_005(SetKOR_PotentialVehicle_005, "Test that in case of potential preceding vehicle high probability a delay and keep off reason is not set when time to HLA border is too small")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 1.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 80;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for preceding */
  RelVeh.bPrecDetected = b_TRUE;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , 0.0f, "Global delay timer was not set");
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Prec , 0.0f, "Preceding delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "GLobal vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC), b_FALSE, "Preceding vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     When a potential oncoming vehicle is too far on the left of the HLA ROI no delay shall be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_006(SetKOR_PotentialVehicle_006, "Test that light is too far to the left and keep off reason is not set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 3;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 20;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , 0.0f, "Global delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential oncoming vehicle is too far on the right of the HLA ROI no delay shall be set.. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_007(SetKOR_PotentialVehicle_007, "Test that light is too far to the right and keep off reason is not set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 300;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 20;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , 0.0f, "Global delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential oncoming vehicle is below of the HLA ROI no delay shall be set. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_008(SetKOR_PotentialVehicle_008, "Test that light is too far below of the ROI and keep off reason is not set")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 300;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 20;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , 0.0f, "Global delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "Vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle is in the HLA ROI and another turn off reason is preset a delay shall not be set, when highReflectorDensityState is not set to none. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_009(SetKOR_PotentialVehicle_009, "Test that in case of potential preceding vehicle a delay and keep off reason is not set, when highReflectorDensityState is not set to none")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 20;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_UNKNOWN;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(KeepOffReason.PotVeh.DelayTimer_Glob, 0.0f, "%.1f", "Global delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "Vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     When a potential oncoming vehicle with high probability is in the HLA ROI and another turn off reason is preset a delay shall not be set when time to HLA border is too small. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_010(SetKOR_PotentialVehicle_010, "Test that in case of potential oncoming vehicle high probability a delay and keep off reason is not set when time to HLA border is too small")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 1.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 80;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for preceding */
  RelVeh.bPrecDetected = b_TRUE;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Glob , 0.0f, "Global delay timer was not set");
  COU_ASSERT_EQUAL(KeepOffReason.PotVeh.DelayTimer_Prec , 0.0f, "Preceding delay timer was not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "GLobal vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC), b_FALSE, "Preceding vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle with medium probability is in the HLA ROI and another turn off reason is preset only global delay shall be set when oncoming delay is active. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_011(SetKOR_PotentialVehicle_011, "Test that in case of potential preceding vehicle medium probability only global delay and keep off reason is set when oncoming delay is active")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 40;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for oncoming */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(KeepOffReason.PotVeh.DelayTimer_Glob, ParKeepOff.KeepOffPotVeh.Delay_Glob, "%.1f", "Global delay timer was set");
  COU_ASSERT_EQUAL_FMT(KeepOffReason.PotVeh.DelayTimer_Onc, 0.0f, "%.1f", "Oncoming delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "GLobal vehicle lost keep off reason is set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_ONC), b_FALSE, "Oncoming vehicle lost keep off reason is set");
}

/** \test
 *  \description
 *     When a potential preceding vehicle with medium probability is in the HLA ROI and another turn off reason is preset only global delay shall be set when preceding delay is active. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Global delay timer was set. Vehicle lost keep off reason is set. \n */
TEST_SetKOR_PotentialVehicle_012(SetKOR_PotentialVehicle_012, "Test that in case of potential preceding vehicle medium probability only global delay and keep off reason is set when preceding delay is active")
{
  /* Initialize Data */
  InitData();

  SetDefaultParameter();
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehicleOncoming = 0;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 40;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for oncoming */
  RelVeh.bPrecDetected = b_TRUE;
  RelVeh.Prec_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(KeepOffReason.PotVeh.DelayTimer_Glob, ParKeepOff.KeepOffPotVeh.Delay_Glob, "%.1f", "Global delay timer was set");
  COU_ASSERT_EQUAL_FMT(KeepOffReason.PotVeh.DelayTimer_Prec, 0.0f, "%.1f", "Preceding delay timer was set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "GLobal vehicle lost keep off reason is set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC), b_FALSE, "Preceding vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     Test that keep off reasons are reset. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Certain keep off reasons are no longer set.\n */
test_HLAFDecision_SetKeepOffReason_KeepOffReasonsUnset_Success(HLAFDecision_SetKeepOffReason_KeepOffReasonsUnset_Success, "Test unsetting of keep off reasons")
{
  LSD_LightObject_t LightObject;

  /* Initialize Data */
  InitData();

  /* Set default parameter */
  SetDefaultParameter();

  /* Set data so that keep off reasons will be removed */
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = 2;
  ParKeepOff.bUseMinimumKOR = b_TRUE;

  /* Bit is set for keep off reason speed acc */
  FData.DecisionData.Speed.keepOffHLABySpeed = 1;

  /* set inputs for the maybe city delay */
  RelVeh.bOncDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* set inputs small radius */
  FData.CamData.radiusAbs_m = 1.0f;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* set inputs for turn on delay init */
  FData.DecisionData.TurnOffReason.Reason = HLAF_TURN_OFF_REASON_NOT_AVL;

  /* set inputs for truck lights */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* set inputs for preceding vehicle lost */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 1.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 2.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* set inputs for the maybe city delay */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.bPrecDetected = b_TRUE;
  TurnOffReason.Reason = 1;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* set inputs for potential vehicle oncoming */
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 80;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for oncoming/preceding */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.bPrecDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC), b_FALSE, "Speed Keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC), b_FALSE, "City maybe keep off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS), b_FALSE, "Small radius keep off reason global is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT), b_FALSE, "Init delay keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS), b_FALSE, "Oncoming truck lights keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_FALSE, "Vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC), b_FALSE, "City maybe keep off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC), b_FALSE, "City maybe keep off reason preceding is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB), b_FALSE, "City maybe keep off reason global is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_FALSE, "GLobal vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_ONC), b_FALSE, "Oncoming vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC), b_FALSE, "Preceding vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     Test that keep off reasons are not unset max number of GFAs is zero. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     keep off reasons are set.\n */
test_HLAFDecision_SetKeepOffReason_KeepOffReasonsNotUnset_NoSuccess(HLAFDecision_SetKeepOffReason_KeepOffReasonsNotUnset_NoSuccess, "Test that keep off reasons are not unset max number of GFAs is zero")
{
  LSD_LightObject_t LightObject;

  /* Initialize Data */
  InitData();

  /* Set default parameter */
  SetDefaultParameter();

  /* Set data so that keep off reasons will not be removed */
  CPar_HlafPar.Matrix.MaxNumGlarefreeArea = 0;
  ParKeepOff.bUseMinimumKOR = b_TRUE;

  /* Bit is set for keep off reason speed acc */
  FData.DecisionData.Speed.keepOffHLABySpeed = 1;

  /* set inputs for the maybe city delay */
  RelVeh.bOncDetected = b_TRUE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* set inputs small radius */
  FData.CamData.radiusAbs_m = 1.0f;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* set inputs for turn on delay init */
  FData.DecisionData.TurnOffReason.Reason = HLAF_TURN_OFF_REASON_NOT_AVL;

  /* set inputs for truck lights */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.lightObjects[0].attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;

  /* set inputs for preceding vehicle lost */
  FData.hlafMatrixData.numRelObj = 1;
  FData.hlafMatrixData.Object[0].bIsRelevantPrec = b_TRUE;
  VDYData.Longitudinal.Velocity = 15.0f;
  KeepOffReason.PrecedingVehLost.distance2cover = 1.0f;

  LightObject.attributes.statusBits = LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED;
  LightObject.kinematic.world.x = 2.0f;
  LightObject.kinematic.world.y = 0.0f;

  FData.hlafMatrixData.Object[0].pLightObject = &LightObject;

  /* set inputs for the maybe city delay */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.bPrecDetected = b_TRUE;
  TurnOffReason.Reason = 1;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionOut.eCityState = RTE_HLAR_CITY_MAYBE;

  /* set inputs for potential vehicle oncoming */
  ParKeepOff.maxDist2Cover = 0.0f;

  /* set inputs */
  LsdLightObjectList.numObjects = 1;
  LsdLightObjectList.roi.x1 = 10;
  LsdLightObjectList.roi.x2 = 100;
  LsdLightObjectList.roi.y1 = 10;
  LsdLightObjectList.roi.y2 = 100;
  LsdLightObjectList.lightObjects[0].kinematic.camera.x = 30;
  LsdLightObjectList.lightObjects[0].kinematic.camera.y = 30;
  LsdLightObjectList.lightObjects[0].kinematic.timeToHlaBorder = 5.0f;
  LsdLightObjectList.lightObjects[0].attributes.probabilityVehiclePreceding = 80;
  LsdEnvironmentData.highReflectorDensityState = LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE;
  eHighBeamStatePrev = RTE_HLAF_HB_STATE_OFF;
  FData.DecisionData.TurnOffReason.Reason = 1;

  /* leads to turn off reason for oncoming/preceding */
  RelVeh.bOncDetected = b_TRUE;
  RelVeh.bPrecDetected = b_TRUE;
  RelVeh.Onc_s = 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  /* check outputs */
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC), b_TRUE, "Speed Keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC), b_TRUE, "City maybe keep off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS), b_TRUE, "Small radius keep off reason global is not set");
  /* init delay not set at the moment */
  //COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT), b_TRUE, "Init delay keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS), b_TRUE, "Oncoming truck lights keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST), b_TRUE, "Vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC), b_TRUE, "City maybe keep off reason oncoming is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC), b_TRUE, "City maybe keep off reason preceding is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB), b_TRUE, "City maybe keep off reason global is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB), b_TRUE, "GLobal vehicle lost keep off reason is not set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_ONC), b_TRUE, "Oncoming vehicle lost keep off reason is not set");
  //COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC), b_TRUE, "Preceding vehicle lost keep off reason is not set");
}

/** \test
 *  \description
 *     Test that keep off reason fog is set in case of turn off reason fog is active. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off reason fog is set.\n */
test_HLAFDecision_SetKeepOffReason_TurnOffReasonFogIsSet_KeepOffReasonFogIsSet(HLAFDecision_SetKeepOffReason_TurnOffReasonFogIsSet_KeepOffReasonFogIsSet, "Test that keep off reason fog is set in case of turn off reason fog is active")
{
  /* Initialize Data */
  InitData();

  /* Set default parameter */
  SetDefaultParameter();

  /* fog turn off reason is active */
  FData.DecisionData.TurnOffReason.Reason = HLAF_TURN_OFF_REASON_FOG;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  COU_ASSERT_EQUAL_FMT(KeepOffReason.FogBadWeather.DelayTimer_Fog, CPar_HlafPar.TurnOnDelay.Fog, "%.1f", "fog turn off delay is set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_FOG), b_TRUE, "fog keep off reason is set");

  /* fog turn off reason is no longer active */
  FData.DecisionData.TurnOffReason.Reason = 0;

  /* time has passed */
  FData.CamData.dtimeFwd_s = CPar_HlafPar.TurnOnDelay.Fog / 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  COU_ASSERT_EQUAL_FMT(KeepOffReason.FogBadWeather.DelayTimer_Fog, CPar_HlafPar.TurnOnDelay.Fog / 2.0f, "%.1f", "fog turn off delay is reduced");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_FOG), b_TRUE, "fog keep off reason is set");

  /* more time has passed */
  FData.CamData.dtimeFwd_s = CPar_HlafPar.TurnOnDelay.Fog / 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  COU_ASSERT_EQUAL_FMT(KeepOffReason.FogBadWeather.DelayTimer_Fog, 0.0f, "%.1f", "fog turn off delay is reduced");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_FOG), b_FALSE, "fog keep off reason is not set");
}

/** \test
 *  \description
 *     Test that keep off reason bad weather is set in case of turn off reason bad weather is active. \n
 *     calls function HLAFDecision_SetKeepOffReason() \n
 *  \precondition
 *     None \n
 *  \result
 *     Keep off reason bad weather is set.\n */
test_HLAFDecision_SetKeepOffReason_TurnOffReasonBadWeatherIsSet_KeepOffReasonBadWeatherIsSet(HLAFDecision_SetKeepOffReason_TurnOffReasonBadWeatherIsSet_KeepOffReasonBadWeatherIsSet, "Test that keep off reason bad weather is set in case of turn off reason bad weather is active")
{
  /* Initialize Data */
  InitData();

  /* Set default parameter */
  SetDefaultParameter();

  /* fog turn off reason is active */
  FData.DecisionData.TurnOffReason.Reason = HLAF_TURN_OFF_REASON_BAD_WEATHER;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  COU_ASSERT_EQUAL_FMT(KeepOffReason.FogBadWeather.DelayTimer_BadWeather, CPar_HlafPar.TurnOnDelay.Fog, "%.1f", "fog turn off delay is set");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_BAD_WEATHER), b_TRUE, "bad weather keep off reason is set");

  /* fog turn off reason is no longer active */
  FData.DecisionData.TurnOffReason.Reason = 0;

  /* time has passed */
  FData.CamData.dtimeFwd_s = CPar_HlafPar.TurnOnDelay.Fog / 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  COU_ASSERT_EQUAL_FMT(KeepOffReason.FogBadWeather.DelayTimer_BadWeather, CPar_HlafPar.TurnOnDelay.Fog / 2.0f, "%.1f", "fog turn off delay is reduced");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_BAD_WEATHER), b_TRUE, "bad weather keep off reason is set");

  /* more time has passed */
  FData.CamData.dtimeFwd_s = CPar_HlafPar.TurnOnDelay.Fog / 2.0f;

  /* call function */
  COU_CALL(HLAFDecision_SetKeepOffReason(&ReqPorts, &FData, &ParKeepOff, &ParTurnOnDelay, eHighBeamStatePrev, &RelVeh, &TurnOffReason, &KeepOffReason), "function call");

  COU_ASSERT_EQUAL_FMT(KeepOffReason.FogBadWeather.DelayTimer_BadWeather, 0.0f, "%.1f", "fog turn off delay is reduced");
  COU_ASSERT_EQUAL(CML_GetBit(KeepOffReason.Reason, HLAF_KEEP_OFF_REASON_BAD_WEATHER), b_FALSE, "bad weather keep off reason is not set");
}

/** list of all test methods of the related suite. */
cou_test_t hla_DecisionKeepOff[] = {
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_001),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_002),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_003),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_004),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_005),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_006),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_007),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_008),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_009),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_010),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_011),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_012),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_013),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_014),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_015),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_016),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_017),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_018),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_019),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_020),
   COU_ADD_TEST(SetKORTurnOnDelaySlowOvertakerTest_021),
   COU_ADD_TEST(SetKORSpeed_001),
   COU_ADD_TEST(SetKORSpeed_002),
   COU_ADD_TEST(SetKORMaybeCity_001),
   COU_ADD_TEST(SetKORMaybeCity_002),
   COU_ADD_TEST(SetKORMaybeCity_003),
   COU_ADD_TEST(SetKORMaybeCity_004),
   COU_ADD_TEST(SetKORMaybeCity_005),
   COU_ADD_TEST(SetKORMaybeCity_006),
   COU_ADD_TEST(SetKOR_SmallRadius_001),
   COU_ADD_TEST(SetKOR_SmallRadius_002),
   COU_ADD_TEST(SetKOR_MinTimeHBoff_001),
   COU_ADD_TEST(SetKOR_TurnOnDelay_001),
   COU_ADD_TEST(SetKOR_TurnOnDelay_002),
   COU_ADD_TEST(SetKOR_TurnOnDelay_003),
   COU_ADD_TEST(SetKOR_TurnOnDelay_004),
   COU_ADD_TEST(SetKOR_TurnOnDelay_005),
   COU_ADD_TEST(SetKOR_TurnOnDelay_006),
   COU_ADD_TEST(SetKOR_TurnOnDelayTruckLights_001),
   COU_ADD_TEST(SetKOR_TurnOnDelayTruckLights_002),
   COU_ADD_TEST(SetKOR_TurnOnDelayTruckLights_003),
   COU_ADD_TEST(SetKOR_TurnOnDelayTruckLights_004),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_001),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_002),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_003),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_004),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_005),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_006),
   COU_ADD_TEST(SetKOR_PrecedingVehLost_007),
   COU_ADD_TEST(SetKOR_PotentialVehicle_001),
   COU_ADD_TEST(SetKOR_PotentialVehicle_002),
   COU_ADD_TEST(SetKOR_PotentialVehicle_003),
   COU_ADD_TEST(SetKOR_PotentialVehicle_004),
   COU_ADD_TEST(SetKOR_PotentialVehicle_005),
   COU_ADD_TEST(SetKOR_PotentialVehicle_006),
   COU_ADD_TEST(SetKOR_PotentialVehicle_007),
   COU_ADD_TEST(SetKOR_PotentialVehicle_008),
   COU_ADD_TEST(SetKOR_PotentialVehicle_009),
   COU_ADD_TEST(SetKOR_PotentialVehicle_010),
   COU_ADD_TEST(SetKOR_PotentialVehicle_011),
   COU_ADD_TEST(SetKOR_PotentialVehicle_012),
   COU_ADD_TEST(HLAFDecision_SetKeepOffReason_KeepOffReasonsUnset_Success),
   COU_ADD_TEST(HLAFDecision_SetKeepOffReason_KeepOffReasonsNotUnset_NoSuccess),
   COU_ADD_TEST(HLAFDecision_SetKeepOffReason_TurnOffReasonFogIsSet_KeepOffReasonFogIsSet),
   COU_ADD_TEST(HLAFDecision_SetKeepOffReason_TurnOffReasonBadWeatherIsSet_KeepOffReasonBadWeatherIsSet),
   COU_ADD_TEST_END
}; /* somehla */
/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(HlafDecisionKeepOffInit, "Initialize Hlaf Decision Keep Off")
{
  /* No Init */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_DecisionKeepOff, hla_DecisionKeepOff, HlafDecisionKeepOffInit, "Module test for hlaf_decision_keepoff.c"),
   COU_ADD_SUITE_END,
}; /* suites */


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
