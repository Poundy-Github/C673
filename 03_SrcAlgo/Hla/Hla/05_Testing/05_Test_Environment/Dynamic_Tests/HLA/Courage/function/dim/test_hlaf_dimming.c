/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
/* include the files that shall be tested */
#include <mockup.h>
#include <string.h>


// Needed header for FUT hlaf_dimming.c
#include "hla_defs.h"
#include "hla_ext.h"
#include "hlaf_type.h"
#include "hlaf_dimming.h"
#include "hla_cpar_init.h"

// over define COU_TEST to get a automatic link between each test case description 
// and the detailed design of a function when adding the test_PkgName.c as input source 
// for the detailed design doxygen generator
#define TEST_DimmingInitAreasBlank          COU_TEST
#define TEST_DimmingInitAreasAlreadyUsed    COU_TEST
#define TEST_DimmingInitAreasInvalidateData COU_TEST
#define TEST_DimmingInvalidateAreas         COU_TEST
#define TEST_DimmingFillOutput              COU_TEST
#define TEST_DimmingDecisions               COU_TEST

/* struct for easier function input */
typedef struct
{
  reqHlaPrtList_t*        pReqPorts;
  LSD_LightObjectList_t*  pObjectList;
  RTE_HLAR_CityState*     peCityOut;
  HLAFMatrixOut_t*        pMatrixOut;
  HLAFDimming_t*          pDimming;
} DimmingInputStructure;

static void subTestStep_DimmingDecision_Test01(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test02(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test03(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test04(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test05(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test06(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test07(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test08(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test09(DimmingInputStructure* pDimmingInput);
static void subTestStep_DimmingDecision_Test10(DimmingInputStructure* pDimmingInput);

/** \test
 *  \description
 *     Test the initialization of dimming areas, starting with uninitialized memory. \n
 *     Calls function HLAFDimming_InitAreas() \n
 *  \precondition
 *     Structure for dimming areas is provided, filled with fresh nonsense, just like after startup. \n
 *  \result
 *     Dimming area structure is correctly initalized, meaning: \n 
 *      - All DimmingArea[0..RTE_HLA_NUM_DIMM_AREAS] fields are set to RTE_HLAF_DIMM_LEVEL_NO_REDUCT \n
 *      - All DimmingAreaHyst[0..RTE_HLA_NUM_DIMM_AREAS] fields are set to 0 \n
 *      - Dimming availability eDimmingStatus is set to RTE_HLAF_DIMM_STATE_AVL\n
 *      - Number of Dimming areas nDimmingArea is set to 0 \n
 */
TEST_DimmingInitAreasBlank(DimmingInitAreasBlank, "Test that dimming areas are correctly initialized, starting with uninitialized memory")
{
  /* variable to hold data for testing */
  HLAFDimming_t dimmingData_underTest;
  /* variable for for loop */
  uint32 counter;
  
  /* CALL FUT */
  COU_CALL( HLAFDimming_InitAreas(&dimmingData_underTest), "Call of HLAF_DimmingInitAreas function with uninitialized memory");
  
  /* CHECK OUTPUTS */
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS; counter++)
  {
    /* check all dimming area stati for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
    COU_ASSERT_EQUAL(dimmingData_underTest.DimmingArea[counter], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area %i: setting of reduction level is correct", counter);
    
    /* check all dimming area hysteresis counters for 0 */
    COU_ASSERT_EQUAL(dimmingData_underTest.DimmAreaHyst[counter], 0, "Area %i: setting of hysteresis counter is correct", counter);
  }
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(dimmingData_underTest.eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(dimmingData_underTest.nDimmingArea, 0, "Setting dimming area counter");
}

/** \test
 *  \description
 *     Test the initialization of dimming areas, starting with used memory. \n
 *     Calls function HLAFDimming_InitAreas()  \n
 *  \precondition
 *     Structure for dimming areas is provided, filled with valid data different than initial state. \n
 *  \result
 *     Dimming area structure is correctly initalized, meaning: \n 
 *      - All DimmingArea[0..RTE_HLA_NUM_DIMM_AREAS] fields are set to RTE_HLAF_DIMM_LEVEL_NO_REDUCT \n
 *      - All DimmingAreaHyst[0..RTE_HLA_NUM_DIMM_AREAS] fields are set to 0 \n
 *      - Dimming availability eDimmingStatus is set to RTE_HLAF_DIMM_STATE_AVL\n
 *      - Number of Dimming areas nDimmingArea is set to 0 \n
 */
TEST_DimmingInitAreasAlreadyUsed(DimmingInitAreasAlreadyUsed, "Test that dimming areas are correctly initialized, starting with used memory")
{
  /* variable to hold data for testing */
  HLAFDimming_t dimmingData_underTest;
  /* variable for for loop */
  uint32 counter;
  
  /* Set some arbitrary values into dimming structure */
  COU_SET(dimmingData_underTest.DimmingArea[0], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "Set reduction of area 0 to level 1");
  COU_SET(dimmingData_underTest.DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Set reduction of area 1 to level 2");
  COU_SET(dimmingData_underTest.DimmAreaHyst[0], 1u, "Set hysteresis value of area 0 to 1");
  COU_SET(dimmingData_underTest.DimmAreaHyst[1], 2u, "Set hysteresis value if area 1 to 2");
  COU_SET(dimmingData_underTest.eDimmingStatus, RTE_HLAF_DIMM_STATE_LIMITED, "Set dimming availability to limited");
  COU_SET(dimmingData_underTest.nDimmingArea, 2, "Setting dimming area counter to 2");
  
  /* CALL FUT */
  COU_CALL( HLAFDimming_InitAreas(&dimmingData_underTest), "Call of HLAF_DimmingInitAreas function with uninitialized memory");
  
  /* Check if correct error was set and no other error */
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS; counter++)
  {
    /* check all dimming area stati for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
    COU_ASSERT_EQUAL(dimmingData_underTest.DimmingArea[counter], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area %i: setting of reduction level is correct", counter);
    
    /* check all dimming area hysteresis counters for 0 */
    COU_ASSERT_EQUAL(dimmingData_underTest.DimmAreaHyst[counter], 0, "Area %i: setting of hysteresis counter is correct", counter);
  }
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(dimmingData_underTest.eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(dimmingData_underTest.nDimmingArea, 0, "Setting dimming area counter");
}

/** \test
 *  \description
 *     Test the invalidation of dimming areas if feature is switched off. \n
 *     Calls function HLAFDimming_InvalidateAreas() \n
 *  \precondition
 *     Structure for dimming areas is provided, filled with valid data. \n
 *     Mostly important eDimmingStatus is RTE_HLAF_DIMM_STATE_AVL and RTE_HLA_NUM_DIMM_AREAS is RTE_HLA_NUM_DIMM_AREAS. \n
 *  \result
 *     Dimming area structure is correctly invalidated, meaning: \n 
 *      - All DimmingArea[0..RTE_HLA_NUM_DIMM_AREAS] fields are set to RTE_HLAF_DIMM_LEVEL_NO_REDUCT \n
 *      - All DimmingAreaHyst[0..RTE_HLA_NUM_DIMM_AREAS] are within [0..HLA_DIMMING_REDUCT_MAX] \n
 *      - Dimming availability eDimmingStatus is set to RTE_HLAF_DIMM_STATE_NAVL\n
 *      - Number of Dimming areas nDimmingArea is set to 0 \n 
 */
TEST_DimmingInvalidateAreas(DimmingInvalidateAreas, "Test that dimming areas are correctly invalidated in case of switching off dimming feature")
{
  /* variable to hold data for testing */
  HLAFDimming_t dimmingData_underTest;
  /* variable for for loop */
  uint32 counter;
  
  memset(&dimmingData_underTest, 0u, sizeof(dimmingData_underTest));
  
  /* Set some arbitrary values into dimming structure */
  COU_SET(dimmingData_underTest.DimmingArea[0], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "Set reduction of area 0 to level 1");
  COU_SET(dimmingData_underTest.DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Set reduction of area 1 to level 2");
  COU_SET(dimmingData_underTest.DimmAreaHyst[0], 1u, "Set hysteresis value of area 0 to 1");
  COU_SET(dimmingData_underTest.DimmAreaHyst[1], 2u, "Set hysteresis value if area 1 to 2");
  COU_SET(dimmingData_underTest.eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Set dimming availability to available");
  COU_SET(dimmingData_underTest.nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter to RTE_HLA_NUM_DIMM_AREAS");
  
  /* CALL FUT */
  COU_CALL( HLAFDimming_InvalidateAreas(&dimmingData_underTest), "Call of HLAFDimming_InvalidateAreas function to invalidate dimming data");
  
  /* Check if correct error was set and no other error */
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS; counter++)
  {
    /* check all dimming area stati for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
    COU_ASSERT_EQUAL(dimmingData_underTest.DimmingArea[counter], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area %i: setting of reduction level is correct", counter);
    
    /* check all dimming area hysteresis counters for 0 */
    COU_ASSERT_RANGE_INSIDE(dimmingData_underTest.DimmAreaHyst[counter], 0, __HLA_DIMMING_REDUCT_MAX, "Area %i: setting of hysteresis counter is reasonable", counter);
  }
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(dimmingData_underTest.eDimmingStatus, RTE_HLAF_DIMM_STATE_NAVL, "Setting of dimming availability is correct");
  
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(dimmingData_underTest.nDimmingArea, 0, "Setting dimming area counter is correct");
}

/** \test
 *  \description
 *     Test if RTE output structure is filled correctly based on internal data. \n
 *     Calls function HLAFDimming_FillAreas() \n
 *  \precondition
 *     Internal dimming data has meaningful values \n
 *  \result
 *     RTE output data has same values as related input structure fields. \n
 */
TEST_DimmingFillOutput(DimmingFillOutput, "Test that dimming areas are correctly invalidated in case of switching off dimming feature")
{
  /* variable to hold data for testing */
  HLAFDimming_t dimmingData_underTest;
  RTE_HLAF_LightDimming_t dimmingRTEData_underTest;
  
  /* variable for for loop */
  uint32 counter;
  
  /* Initialize data to base test on */
  memset(&dimmingData_underTest, 0u, sizeof(dimmingData_underTest));
  
  /* Set some arbitrary values into dimming structure */
  COU_SET(dimmingData_underTest.DimmingArea[0], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "Set reduction of area 0 to level 1");
  COU_SET(dimmingData_underTest.DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Set reduction of area 1 to level 2");
  COU_SET(dimmingData_underTest.DimmAreaHyst[0], 1u, "Set hysteresis value of area 0 to 1");
  COU_SET(dimmingData_underTest.DimmAreaHyst[1], 2u, "Set hysteresis value if area 1 to 2");
  COU_SET(dimmingData_underTest.eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Set dimming availability to available");
  COU_SET(dimmingData_underTest.nDimmingArea, 2, "Setting dimming area counter to 2");
  
  /* CALL FUT */
  COU_CALL( HLAFDimming_FillAreas(&dimmingData_underTest, &dimmingRTEData_underTest), "Call of HLAF_FillOutputData function to fill RTE dimming data");
  
  /* Check if correct error was set and no other error */
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS; counter++)
  {
    /* check all dimming area stati for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
    COU_ASSERT_EQUAL(dimmingRTEData_underTest.DimmingArea[counter], dimmingData_underTest.DimmingArea[counter], "Area %i: setting of reduction level is correct", counter);
  }
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(dimmingRTEData_underTest.DimmingStatus, dimmingData_underTest.eDimmingStatus, "Setting of dimming availability is correct");
}

/** \test
 *  \description
 *     Test all dimming decisions. Basically goes through the following scenarios: \n
 *     Calls function CParInitCPAR_HLAF_Parameter() to get correct dimming parameters. \n
 *     Calls function HLAFDimming_InitAreas() to get correctly initialize dimming structure prior to each subtest step. \n
 *     Calls sub test steps subTestStep_DimmingDecision_Test01() to subTestStep_DimmingDecision_Test10 \n
 *  \precondition
 *     For each step: dimming area structure is freshly initialized, then prepared.
 *     Step 01. no object is present, no hysteresis before \n
 *     Step 02. no object is present, hysteresis before \n
 *     Step 03. two objects are present but not bright enough, no hysteresis before \n
 *     Step 04. two objects are present but not bright enough, hysteresis before \n
 *     Step 05. two objects are present, bright enough and not cars, no hysteresis before \n
 *     Step 06. two objects are present, bright enough and not cars, hysteresis before \n
 *     Step 07. two objects are present, bright enough and not cars, but there is a GFA, no hysteresis before \n
 *     Step 08. two objects are present, bright enough and not cars, but there is an GFA, hysteresis before \n
 *     Step 09. two objects are present, bright enough and not cars, but some lost cycles, no hysteresis before \n
 *     Step 10. one object is bright enough and no car, but city is also detected \n
 *  \result
 *     Test result 01. \n
 *      - No reduction in any dimming area \n
 *      - All hysteresis fields are zero \n
 *     Test result 02. \n
 *      - Existing recommendations are kept if hystersis counter is valid \n
 *      - All hysteresis fields are decreased by one \n
 *     Test result 03. \n
 *      - No reduction in any dimming area \n
 *      - All hysteresis fields are zero \n
 *     Test result 04. \n
 *      - No reduction in any dimming area \n
 *      - All hysteresis fields are zero \n
 *     Test result 05. \n
 *      - No reduction in any dimming area \n
 *      - Hysteresis fields for two dimming areas updated \n
 *     Test result 06. \n
 *      - Reduction in first dimming area \n
 *      - Hysteresis fields for two dimming areas are incremented \n
 *     Test result 07. \n
 *      - No reduction in any dimming area \n
 *      - Hysteresis field for one dimming area is updated \n
 *     Test result 08. \n
 *      - No reduction in any dimming area \n
 *      - All hysteresis fields are zero \n
 *     Test result 09. \n
 *      - No reduction in any dimming area \n
 *      - All hysteresis fields are zero \n
 *     Test result 10. \n
 *      - No reduction in any dimming area \n
 *      - All hysteresis fields are zero \n
 */
TEST_DimmingDecisions(DimmingDecisions, "Test that dimming areas are working correctly")
{

/* Decisions, decisions */
  DimmingInputStructure DimmingInputs;
  
  /* Data needed as first level input */
  reqHlaPrtList_t       ReqPorts_Input;
  LSD_LightObjectList_t ObjectList_Input;
  RTE_HLAR_CityState    eCityOut_Input;
  HLAFMatrixOut_t       MatrixOut_Input;
  HLAFDimming_t         Dimming_Output;
  /* Data needed as second level input */
  CPAR_HLAF_Parameter_t cparHlafParameter;
  MonoCalibration_t     monoCaliData;
  
  
  /* Initialize data */
  memset(&DimmingInputs,      0, sizeof(DimmingInputs)    );
  memset(&ReqPorts_Input,     0, sizeof(ReqPorts_Input)   );
  memset(&ObjectList_Input,   0, sizeof(ObjectList_Input) );
  memset(&eCityOut_Input,     0, sizeof(eCityOut_Input)   );
  memset(&MatrixOut_Input,    0, sizeof(MatrixOut_Input)  );
  memset(&Dimming_Output,     0, sizeof(Dimming_Output)   );
  memset(&cparHlafParameter,  0, sizeof(cparHlafParameter));
  memset(&monoCaliData,       0, sizeof(monoCaliData)     );
  
  /* Initialize function parameters */
  COU_SET_BY_CALL( CParInitCPAR_HLAF_Parameter(&cparHlafParameter), "Initialize dimming parameters");
  
  /* Link parameters */
  ReqPorts_Input.pCPar_HlafPar = &cparHlafParameter;
  
  /* Set focal length to acceptable standard value */
  monoCaliData.sIntrinsic.fFocalY = 1240.0f;
  
  /* Link MonoCalibration data */
  ReqPorts_Input.pMonoCalibration = &monoCaliData;
  
  /* Link input structure */
  DimmingInputs.pReqPorts   = &ReqPorts_Input;
  DimmingInputs.pObjectList = &ObjectList_Input;
  DimmingInputs.peCityOut   = &eCityOut_Input;
  DimmingInputs.pMatrixOut  = &MatrixOut_Input;
  DimmingInputs.pDimming    = &Dimming_Output;
  
  /* ------------------------------------------------------------------------------------------ */
  /*                                       Test Execution                                       */
  /* ------------------------------------------------------------------------------------------ */
  
  /* Set city to not present */
  *DimmingInputs.peCityOut = RTE_HLAR_CITY_NOT_DTCD;
  
/* Call Test Step 01 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test01(&DimmingInputs);
  
  /* Call Test Step 02 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test02(&DimmingInputs);
  
  /* Call Test Step 03 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test03(&DimmingInputs);
  
  /* Call Test Step 04 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test04(&DimmingInputs);
  
  /* Call Test Step 05 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test05(&DimmingInputs);
  
  /* Call Test Step 06 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test06(&DimmingInputs);
  
  /* Call Test Step 07 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test07(&DimmingInputs);
  
  /* Call Test Step 08 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test08(&DimmingInputs);
  
  /* Call Test Step 09 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test09(&DimmingInputs);
  
  /* Call Test Step 10 */
  /* Initialize dimming output structure */
  COU_SET_BY_CALL( HLAFDimming_InitAreas(DimmingInputs.pDimming), "Initialize dimming output structure");
  subTestStep_DimmingDecision_Test10(&DimmingInputs);
}

static void subTestStep_DimmingDecision_Test01(DimmingInputStructure* pDimmingInput)
{
  /* 1. no object is present, no hysteresis before */
  /* Expected result:                    */
  /*  - No reduction in any dimming area */
  /*  - All hysteresis fields are zero   */
  uint32 counter;

  /* No manipulations to be done in this case */
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with no objects present."
          );
  
  /* CHECK OUTPUTS */
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS; counter++)
  {
    /* check all dimming area stati for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
    COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[counter], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area %i: setting of reduction level is correct", counter);
    
    /* check all dimming area hysteresis counters for 0 */
    COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[counter], 0, "Area %i: setting of hysteresis counter is correct", counter);
  }
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test02(DimmingInputStructure* pDimmingInput)
{
  /* 2. no object is present, hysteresis before                         */
  /* Expected result:                                                   */
  /*  - Existing recommendations are kept if hystersis counter is valid */
  /*  - All hysteresis fields are decreased by one                      */

  /* Manipulate dimming recommendations */
  pDimmingInput->pDimming->DimmingArea[0] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
  pDimmingInput->pDimming->DimmingArea[1] = RTE_HLAF_DIMM_LEVEL_REDUCT_1;
  pDimmingInput->pDimming->DimmingArea[2] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
  pDimmingInput->pDimming->DimmingArea[3] = RTE_HLAF_DIMM_LEVEL_NO_REDUCT;
  
  /* Manipulate hysteresis counters */
  pDimmingInput->pDimming->DimmAreaHyst[0] = 3;
  pDimmingInput->pDimming->DimmAreaHyst[1] = 2;
  pDimmingInput->pDimming->DimmAreaHyst[2] = 1;
  pDimmingInput->pDimming->DimmAreaHyst[3] = 0;
  
  pDimmingInput->pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with no objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status is not kept -> RTE_HLAF_DIMM_LEVEL_REDUCT_2 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters is reduced */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], 2, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status is not kept -> RTE_HLAF_DIMM_LEVEL_REDUCT_1 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters is reduced */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], 1, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status is changed -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters is reduced */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test03(DimmingInputStructure* pDimmingInput)
{
  /* 3. two objects are present but not bright enough, no hysteresis before */
  /* Expected result:                    */
  /*  - No reduction in any dimming area */
  /*  - All hysteresis fields are zero   */
  
  uint32 counter;

  /* Manipulate object list */
  /* Two object are present, but both are not bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set first object to be a bright object, but with not enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = 1.0f;
  /* Set second object to not be a bright object, but with enough luminous flux */
  COU_SET_BY_CALL( CML_ClearBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = 1.0f;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with objects present."
          );
  
  /* CHECK OUTPUTS */
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS; counter++)
  {
    /* check all dimming area stati for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
    COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[counter], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area %i: setting of reduction level is correct", counter);
    
    /* check all dimming area hysteresis counters for 0 */
    COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[counter], 0, "Area %i: setting of hysteresis counter is correct", counter);
  }
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test04(DimmingInputStructure* pDimmingInput)
{
  /* 4. two objects are present but not bright enough, hysteresis before */
  /* Expected result:                    */
  /*  - No reduction in any dimming area */
  /*  - All hysteresis fields are zero   */

  /* Manipulate object list */
  /* Two object are present, but both are not bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set first object to be a bright object, but with not enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = 1.0f;
  /* Set second object to not be a bright object, but with enough luminous flux */
  COU_SET_BY_CALL( CML_ClearBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = 1.0f;
  
  /* Manipulate reduction recommendations */
  pDimmingInput->pDimming->DimmingArea[0] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
  pDimmingInput->pDimming->DimmingArea[1] = RTE_HLAF_DIMM_LEVEL_REDUCT_1;
  pDimmingInput->pDimming->DimmingArea[2] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
  pDimmingInput->pDimming->DimmingArea[3] = RTE_HLAF_DIMM_LEVEL_NO_REDUCT;
  
  /* Manipulate hysteresis counters */
  pDimmingInput->pDimming->DimmAreaHyst[0] = 3;
  pDimmingInput->pDimming->DimmAreaHyst[1] = 2;
  pDimmingInput->pDimming->DimmAreaHyst[2] = 1;
  pDimmingInput->pDimming->DimmAreaHyst[3] = 0;
  
  pDimmingInput->pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for no change -> RTE_HLAF_DIMM_LEVEL_REDUCT_2 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters decrement */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], 2, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for no change -> RTE_HLAF_DIMM_LEVEL_REDUCT_1 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters decrement */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], 1, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for change -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters decrement */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test05(DimmingInputStructure* pDimmingInput)
{
  /* 5. two objects are present, bright enough and not cars, no hysteresis before */
  /* Expected result:                                   */
  /*  - No reduction in any dimming area                */
  /*  - Hysteresis fields for two dimming areas updated */

  /* Manipulate object list */
  /* Two object are present, and both are bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set FOE value */
  pDimmingInput->pObjectList->roi.yFOE = 340u;
  /* Set first object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.horizontalAngle = 0.123f;
  
  /* Set second object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.horizontalAngle = 0.121f;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], 0, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], 0, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 1 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 1, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 1 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 1, "Area 4: setting of hysteresis counter is correct");
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test06(DimmingInputStructure* pDimmingInput)
{
  /* 6. two objects are present, bright enough and not cars, hysteresis before  */
  /* Expected result:                                                           */
  /*  - Reduction in first dimming area                                         */
  /*  - Hysteresis fields for two dimming areas are incremented                 */

  /* Manipulate object list */
  /* Two object are present, and both are bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set FOE value */
  pDimmingInput->pObjectList->roi.yFOE = 340u;
  /* Set first object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.horizontalAngle = -0.123f;
  
  /* Set second object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.horizontalAngle = -0.121f;
  
  /* Set first dimming area to max dimming already */
  pDimmingInput->pDimming->DimmingArea[0] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
  
  /* Manipulate hysteresis counters */
  pDimmingInput->pDimming->DimmAreaHyst[0] = __HLA_DIMMING_REDUCT_MAX;
  pDimmingInput->pDimming->DimmAreaHyst[1] = __HLA_DIMMING_HYSTERESIS;
  pDimmingInput->pDimming->DimmAreaHyst[2] = 1;
  pDimmingInput->pDimming->DimmAreaHyst[3] = 0;
  
  pDimmingInput->pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for reduction recommendation -> RTE_HLAF_DIMM_LEVEL_REDUCT_1 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters for increment */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], __HLA_DIMMING_REDUCT_MAX, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_1, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters for increment */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], __HLA_DIMMING_HYSTERESIS + 1, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters for decrement */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test07(DimmingInputStructure* pDimmingInput)
{
  /* 7. two objects are present, bright enough and not cars, but there is a GFA, no hysteresis before */
  /* Expected result:                                     */
  /*  - No reduction in any dimming area                  */
  /*  - Hysteresis field for one dimming area is updated  */

  /* Manipulate object list */
  /* Two object are present, and both are bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set FOE value */
  pDimmingInput->pObjectList->roi.yFOE = 340u;
  
  /* Set first object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.horizontalAngle = -0.123f;
  
  /* Set second object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.camera.y = 296u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.horizontalAngle = -0.121f;
  
  /* Set a GFA so that object 1 is included but not object 2 */
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryLeft_Ang      = -0.122f;
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryRight_Ang     = -0.124f;
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryLower_Ang_Cam = -0.015f;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with no objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], 0, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters for increment */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], 1, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test08(DimmingInputStructure* pDimmingInput)
{
  /* 8. two objects are present, bright enough and not cars, but there is an GFA, hysteresis before */
  /* Expected result:                    */
  /*  - No reduction in any dimming area */
  /*  - All hysteresis fields are zero   */

  /* Manipulate object list */
  /* Two object are present, and both are bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set FOE value */
  pDimmingInput->pObjectList->roi.yFOE = 340u;
  /* Set first object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.horizontalAngle = -0.123f;
  
  /* Set second object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  /* Set luminous flux to be at 95% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.95f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.horizontalAngle = -0.121f;
  
  /* Set a GFA so that object 1 is included but not object 2 */
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryLeft_Ang      = -0.122f;
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryRight_Ang     = -0.124f;
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryLower_Ang_Cam = -0.015f;
  
  /* Manipulate hysteresis counters */
  pDimmingInput->pDimming->DimmAreaHyst[0] = __HLA_DIMMING_HYSTERESIS;
  pDimmingInput->pDimming->DimmAreaHyst[1] = __HLA_DIMMING_HYSTERESIS;
  pDimmingInput->pDimming->DimmAreaHyst[2] = 1;
  pDimmingInput->pDimming->DimmAreaHyst[3] = 0;
  
  pDimmingInput->pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with no objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters for decrement */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], __HLA_DIMMING_HYSTERESIS - 1, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for reduction recommendation-> RTE_HLAF_DIMM_LEVEL_REDUCT_2 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_REDUCT_2, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters for increment */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], __HLA_DIMMING_HYSTERESIS + 1, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test09(DimmingInputStructure* pDimmingInput)
{
  /* 9. two objects are present, bright enough and not cars, but some lost cycles, no hysteresis before */
  /* Expected result:                    */
  /*  - No reduction in any dimming area */
  /*  - All hysteresis fields are zero   */
  
  /* Manipulate object list */
  /* Two object are present, and both are bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set FOE value */
  pDimmingInput->pObjectList->roi.yFOE = 340u;
  /* Set first object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.horizontalAngle = -0.123f;
  /* Set cycles lost  */
  pDimmingInput->pObjectList->lightObjects[0].general.cyclesLost = 2u;
  
  /* Set second object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.x = 0.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.horizontalAngle = -0.121f;
  
  pDimmingInput->pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
    
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with no objects present."
          );
  
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 0: setting of reduction level is correct");
  /* check dimming area 0 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], 0, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 1: setting of reduction level is correct");
  /* check dimming area 1 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], 1, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check dimming area 2 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}

static void subTestStep_DimmingDecision_Test10(DimmingInputStructure* pDimmingInput)
{
  /* 10. one object is bright enough and no car, but city is also detected */
  /* Expected result:                    */
  /*  - No reduction in any dimming area */
  /*  - All hysteresis fields are zero   */

  /* Manipulate city state */
  *(pDimmingInput->peCityOut) = RTE_HLAR_CITY_DTCD;
  
  /* Manipulate object list */
  /* Two object are present, and both are bright enough */
  pDimmingInput->pObjectList->numObjects = 2;
  /* Set FOE value */
  pDimmingInput->pObjectList->roi.yFOE = 340u;
  /* Set first object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[0].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[0].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[0].kinematic.world.horizontalAngle = -0.123f;
  /* Set cycles lost  */
  pDimmingInput->pObjectList->lightObjects[0].general.cyclesLost = 2u;
  
  /* Set second object to be a bright object, with enough luminous flux */
  COU_SET_BY_CALL( CML_SetBit(pDimmingInput->pObjectList->lightObjects[1].attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE), "Set status bit to not indicate bright object");
  /* Set luminous flux to be at 85% of max luminous flux */
  pDimmingInput->pObjectList->lightObjects[1].attributes.luminousFlux = (float32) __HLA_DIMMING_MAX_LUX * 0.85f;
  /* Set world x coordinate of object to enable angle calculation */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.x = 100.0f;
  /* Set camera y coordinate */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.camera.y = 320u;
  /* Set horizontal angle */
  pDimmingInput->pObjectList->lightObjects[1].kinematic.world.horizontalAngle = -0.121f;
  
  pDimmingInput->pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
  
  /* Set a GFA so that object 1 is not included also not object 2 */
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryLeft_Ang      = -0.122f;
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryRight_Ang     = -0.124f;
  pDimmingInput->pMatrixOut->Matrix.GFA[0].BndryLower_Ang_Cam = -0.019f;
  
  /* CALL FUT HLAFDimming_DecisionAreas */
  COU_CALL( HLAFDimming_DecisionAreas(pDimmingInput->pReqPorts,
                                      pDimmingInput->pObjectList,
                                      pDimmingInput->peCityOut,
                                      pDimmingInput->pMatrixOut,
                                      pDimmingInput->pDimming
                                     ),
            "Call of function HLAFDimming_DecisionAreas with no objects present."
          );
          
  /* CHECK OUTPUTS */
  /* check dimming area 0 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[0], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 0: setting of reduction level is correct");
  /* check all dimming area 0 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[0], 0, "Area 0: setting of hysteresis counter is correct");
  
  /* check dimming area 1 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[1], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 1: setting of reduction level is correct");
  /* check all dimming area 1 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[1], 0, "Area 1: setting of hysteresis counter is correct");
  
  /* check dimming area 2 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[2], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 2: setting of reduction level is correct");
  /* check all dimming area 2 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[2], 0, "Area 2: setting of hysteresis counter is correct");
  
  /* check dimming area 3 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[3], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 3: setting of reduction level is correct");
  /* check all dimming area 3 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[3], 0, "Area 3: setting of hysteresis counter is correct");
  
  /* check dimming area 4 status for no reduction -> RTE_HLAF_DIMM_LEVEL_NO_REDUCT */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmingArea[4], RTE_HLAF_DIMM_LEVEL_NO_REDUCT, "Area 4: setting of reduction level is correct");
  /* check all dimming area 4 hysteresis counters for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->DimmAreaHyst[4], 0, "Area 4: setting of hysteresis counter is correct");
  
  
  /* check dimming status for available -> RTE_HLAF_DIMM_STATE_AVL */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->eDimmingStatus, RTE_HLAF_DIMM_STATE_AVL, "Setting dimming availability");
  /* check dimming area counter for 0 */
  COU_ASSERT_EQUAL(pDimmingInput->pDimming->nDimmingArea, RTE_HLA_NUM_DIMM_AREAS, "Setting dimming area counter");
}


/** list of all test methods of the related suite. */
cou_test_t hlaf_dimming[] = {
  COU_ADD_TEST(DimmingInitAreasBlank),
  COU_ADD_TEST(DimmingInitAreasAlreadyUsed),
  COU_ADD_TEST(DimmingInvalidateAreas),
  COU_ADD_TEST(DimmingFillOutput),
  COU_ADD_TEST(DimmingDecisions),
  COU_ADD_TEST_END
}; /* somehla */

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(Dimming_Init, "Initialize Dimming")
{
  /* Do nothing as of now */
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Dimming, hlaf_dimming, Dimming_Init, "Module test for hlaf_dimming.c"),
   COU_ADD_SUITE_END,
}; /* suites */

#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
