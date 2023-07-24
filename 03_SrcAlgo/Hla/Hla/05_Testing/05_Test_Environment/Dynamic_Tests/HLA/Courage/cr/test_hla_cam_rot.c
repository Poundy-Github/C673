/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>

/* include FUT header */
#include <hla_cam_rot.h>

// over define COU_TEST to get a automatic link between each test case description
// and the detailed design of a function when adding the test_PkgName.c as input source
// for the detailed design doxygen generator
#define TEST_CamRotInit COU_TEST
#define TEST_CamRotSetData COU_TEST
#define TEST_CamRotSetDataNoUpdate COU_TEST
#define TEST_CamRotGetFocalX COU_TEST
#define TEST_CamRotGetUpdateNeeded COU_TEST
#define TEST_CamRotGetXb COU_TEST

// more defines
#define EMPTYNESS 0.0f

/* Gain access to HLACamRot_t HLACamRot; */
extern HLACamRot_t HLACamRot;

static void subTestsRotK(void);
static void subTestsRotKa(void);
static void subTestsRotKc(void);
static void subTestsRotKWa(void);
static void subTestsRotKWc(void);

/** \test
 *  \description
 *     Test the initialization function \n
 *     Calls function HLACamRotInit() \n
 *  \precondition
 *     No preconditions need to be met \n
 *  \result
 *     HLACamRot is set to 0 \n
 */
TEST_CamRotInit(CamRotInit, "Test Initialization of CamRot Module")
{
  unsigned int i = 0;
  /* Call CamRotInit */
  COU_CALL(HLACamRotInit(),"Initialize CamRot Module");

  /* Check content of HLACamRot -> everything should be 0 */
  for(i = 0; i < HLA_CAM_ROT_3X3_MATRIXSIZE; i++)
  {
    COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[i],    EMPTYNESS, "%.6f", "ROT_W[%i] is set correct", i);
    COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[i],    EMPTYNESS, "%.6f", "ROT_K[%i] is set correct", i);
    COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[i],  EMPTYNESS, "%.6f", "ROT_K_a[%i] is set correct", i);
    COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[i],  EMPTYNESS, "%.6f", "ROT_K_c[%i] is set correct", i);
    COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[i], EMPTYNESS, "%.6f", "ROT_KW_a[%i] is set correct", i);
    COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[i], EMPTYNESS, "%.6f", "ROT_KW_c[%i] is set correct", i);
    if (i < HLA_CAM_ROT_3X3_VECTORSIZE)
    {
      COU_ASSERT_EQUAL_FMT(HLACamRot.T[i], EMPTYNESS, "%.6f", "T[%i] is set correctly", i);
      COU_ASSERT_EQUAL_FMT(HLACamRot.A[i], EMPTYNESS, "%.6f", "A[%i] is set correctly", i);
    }
  }
  COU_ASSERT_EQUAL_FMT(HLACamRot.FX, EMPTYNESS, "%.6f", "FX is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.FY, EMPTYNESS, "%.6f", "FY is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.XO, EMPTYNESS, "%.6f", "XO is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.YO, EMPTYNESS, "%.6f", "YO is set correctly");
  COU_ASSERT_EQUAL(HLACamRot.bInternalDataUpdated, FALSE, "bInternalDataUpdated is set correctly");
}

/** \test
 *  \description
 *     Test the setting function \n
 *     Calls function HLACamRotSetData() \n
 *  \precondition
 *     HLACamRot data is initialized \n
 *  \result
 *     HLACamRot data is set according to input values \n
 */
TEST_CamRotSetData(CamRotSetData, "Test setting of CamRot Data")
{
  /* define input values */
  float32 xRot, yRot, zRot;
  float32 xTrans, yTrans, zTrans;
  float32 xFocalLength, yFocalLength;
  float32 xLensCenter, yLensCenter;

  /* define output check helper values */
  float32 sin_x, cos_x, sin_y, cos_y, sin_z, cos_z;
  float32 testResult;

  /* Set input values */
  COU_SET_FMT(xRot        ,   -1.6247891, "%.6f", "Set xRot");
  COU_SET_FMT(yRot        ,    0.0225971, "%.6f", "Set yRot");
  COU_SET_FMT(zRot        ,   -1.5672151, "%.6f", "Set zRot");
  COU_SET_FMT(xTrans      ,   -1.504    , "%.6f", "Set xTrans");
  COU_SET_FMT(yTrans      ,   -0.08     , "%.6f", "Set yTrans");
  COU_SET_FMT(zTrans      ,    1.20358  , "%.6f", "Set zTrans");
  COU_SET_FMT(xFocalLength, 1235.2f     , "%.6f", "Set xFocalLength");
  COU_SET_FMT(yFocalLength, 1235.1f     , "%.6f", "Set yFocalLength");
  COU_SET_FMT(xLensCenter ,  594.132f   , "%.6f", "Set xLensCenter");
  COU_SET_FMT(yLensCenter ,  314.886f   , "%.6f", "Set yLensCenter");

  /* Set helper values */
  COU_SET_FMT(sin_x, CML_sin66(xRot), "%.6f", "Set sin_x");
  COU_SET_FMT(cos_x, CML_cos66(xRot), "%.6f", "Set cos_x");
  COU_SET_FMT(sin_y, CML_sin66(yRot), "%.6f", "Set sin_y");
  COU_SET_FMT(cos_y, CML_cos66(yRot), "%.6f", "Set cos_y");
  COU_SET_FMT(sin_z, CML_sin66(zRot), "%.6f", "Set sin_z");
  COU_SET_FMT(cos_z, CML_cos66(zRot), "%.6f", "Set cos_z");

  /* Initialize CamRot Data */
  COU_CALL(HLACamRotInit(), "Initialize CamRot Data");

  /* Call FUT */
  COU_CALL(HLACamRotSetData(xRot, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  /* Control output values */
  /* Check focal length */
  COU_ASSERT_EQUAL_FMT(HLACamRot.FX, xFocalLength, "%.6f", "Focal length in x direction is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.FY, yFocalLength, "%.6f", "Focal length in y direction is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.XO, xLensCenter, "%.6f", "Lens center x direction is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.YO, yLensCenter, "%.6f", "Lens center y direction is set correctly");

  /* Check translation vector */
  COU_ASSERT_EQUAL_FMT(HLACamRot.T[0], xTrans, "%.6f", "T[0] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.T[1], yTrans, "%.6f", "T[1] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.T[2], zTrans, "%.6f", "T[2] is set correctly");

  /* Check rotation vector */
  COU_ASSERT_EQUAL_FMT(HLACamRot.A[0], xRot, "%.6f", "A[0] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.A[1], yRot, "%.6f", "A[1] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.A[2], zRot, "%.6f", "A[2] is set correctly");

  /* Check ROT_W */
  /* Calculate output values */
  testResult = ( cos_z * cos_y);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[0], testResult, "%.6f", "ROT_W[0] is set correctly");
  testResult = ((-sin_z * cos_x) + (cos_z * sin_y * sin_x));
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[1], testResult, "%.6f", "ROT_W[1] is set correctly");
  testResult = (( sin_z * sin_x) + (cos_z * sin_y * cos_x));
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[2], testResult, "%.6f", "ROT_W[2] is set correctly");


  testResult = ( sin_z * cos_y);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[3], testResult, "%.6f", "ROT_W[3] is set correctly");
  testResult = (( cos_z * cos_x) + (sin_z * sin_y * sin_x));
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[4], testResult, "%.6f", "ROT_W[4] is set correctly");
  testResult = ((-cos_z * sin_x) + (sin_z * sin_y * cos_x));
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[5], testResult, "%.6f", "ROT_W[5] is set correctly");

  testResult = (-sin_y);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[6], testResult, "%.6f", "ROT_W[6] is set correctly");
  testResult = (cos_y * sin_x);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[7], testResult, "%.6f", "ROT_W[7] is set correctly");
  testResult = (cos_y * cos_x);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_W[8], testResult, "%.6f", "ROT_W[8] is set correctly");

  subTestsRotK();

  subTestsRotKa();

  subTestsRotKc();

  subTestsRotKWa();

  subTestsRotKWc();
}

/** \test
 *  \description
 *     Test the setting function \n
 *     Calls function HLACamRotSetData() \n
 *  \precondition
 *     HLACamRot data is already set \n
 *  \result
 *     HLACamRot data is not changed \n
 */
TEST_CamRotSetDataNoUpdate(CamRotSetDataNoUpdate, "Test setting of CamRot Data but no update needed")
{
  /* define input values */
    float32 xRot, yRot, zRot;
    float32 xTrans, yTrans, zTrans;
    float32 xFocalLength, yFocalLength;
    float32 xLensCenter, yLensCenter;

    /* Set input values */
    COU_SET_FMT(xRot        ,   -1.6247891, "%.6f", "Set xRot");
    COU_SET_FMT(yRot        ,    0.0225971, "%.6f", "Set yRot");
    COU_SET_FMT(zRot        ,   -1.5672151, "%.6f", "Set zRot");
    COU_SET_FMT(xTrans      ,   -1.504    , "%.6f", "Set xTrans");
    COU_SET_FMT(yTrans      ,   -0.08     , "%.6f", "Set yTrans");
    COU_SET_FMT(zTrans      ,    1.20358  , "%.6f", "Set zTrans");
    COU_SET_FMT(xFocalLength, 1235.2f     , "%.6f", "Set xFocalLength");
    COU_SET_FMT(yFocalLength, 1235.1f     , "%.6f", "Set yFocalLength");
    COU_SET_FMT(xLensCenter ,  594.132f   , "%.6f", "Set xLensCenter");
    COU_SET_FMT(yLensCenter ,  314.886f   , "%.6f", "Set yLensCenter");

  /* Initialize CamRot Data */
  COU_CALL(HLACamRotInit(), "Initialize CamRot Data");

  /* Call FUT */
  COU_CALL(HLACamRotSetData(xRot, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  COU_ASSERT_EQUAL(HLACamRot.bInternalDataUpdated, TRUE, "Update of data is indicated");

  /* Call FUT the second time */
  COU_CALL(HLACamRotSetData(xRot, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  COU_ASSERT_EQUAL(HLACamRot.bInternalDataUpdated, FALSE, "No update of data is indicated");
}

/** \test
 *  \description
 *     Test the get function for bInternalDataUpdated \n
 *     Calls functions HLACamRotSetData() \n
 *                     HLACamRotGetWasInternalDataUpdated() \n
 *  \precondition
 *     HLACamRot data is set and an update has happened. \n
 *  \result
 *     bInternalDataUpdated is set to TRUE and HLACamRotGetWasInternalDataUpdated returns TRUE. \n
 */
TEST_CamRotGetUpdateNeeded(CamRotGetUpdateNeeded, "Test get function for bInternalDataUpdated")
{
  /* define input values */
  float32 xRot, yRot, zRot;
  float32 xTrans, yTrans, zTrans;
  float32 xFocalLength, yFocalLength;
  float32 xLensCenter, yLensCenter;

  /* Set input values */
  COU_SET_FMT(xRot        ,   -1.6247891, "%.6f", "Set xRot");
  COU_SET_FMT(yRot        ,    0.0225971, "%.6f", "Set yRot");
  COU_SET_FMT(zRot        ,   -1.5672151, "%.6f", "Set zRot");
  COU_SET_FMT(xTrans      ,   -1.504    , "%.6f", "Set xTrans");
  COU_SET_FMT(yTrans      ,   -0.08     , "%.6f", "Set yTrans");
  COU_SET_FMT(zTrans      ,    1.20358  , "%.6f", "Set zTrans");
  COU_SET_FMT(xFocalLength, 1235.2f     , "%.6f", "Set xFocalLength");
  COU_SET_FMT(yFocalLength, 1235.1f     , "%.6f", "Set yFocalLength");
  COU_SET_FMT(xLensCenter ,  594.132f   , "%.6f", "Set xLensCenter");
  COU_SET_FMT(yLensCenter ,  314.886f   , "%.6f", "Set yLensCenter");

  boolean returnValue;

  /* Initialize CamRot Data */
  COU_CALL(HLACamRotInit(), "Initialize CamRot Data");

  /* Call set function for CamRot data */
  COU_CALL(HLACamRotSetData(xRot, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  /* Set returnValue by call */
  COU_SET(returnValue, HLACamRotGetWasInternalDataUpdated(), "Check if there has been an update of CamRot data");

  COU_ASSERT_EQUAL(returnValue, HLACamRot.bInternalDataUpdated, "Return value of HLACamRotGetWasInternalDataUpdated is correct");

  COU_CALL(HLACamRotSetData(xRot + 1.0f, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  COU_ASSERT_EQUAL(returnValue, HLACamRot.bInternalDataUpdated, "Return value of HLACamRotGetWasInternalDataUpdated is correct");

  COU_CALL(HLACamRotSetData(xRot + 1.0f, yRot + 1.0f, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  COU_ASSERT_EQUAL(returnValue, HLACamRot.bInternalDataUpdated, "Return value of HLACamRotGetWasInternalDataUpdated is correct");

  COU_CALL(HLACamRotSetData(xRot + 1.0f, yRot + 1.0f, zRot + 1.0f, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  COU_ASSERT_EQUAL(returnValue, HLACamRot.bInternalDataUpdated, "Return value of HLACamRotGetWasInternalDataUpdated is correct");
}

/** \test
 *  \description
 *     Test the get function for bInternalDataUpdated \n
 *     Calls functions HLACamRotSetData() \n
 *                     HLACamRotGetFocalX() \n
 *  \precondition
 *     HLACamRot data is set. \n
 *  \result
 *     Call returns the value of the focal length in x-direction. \n
 */
TEST_CamRotGetFocalX(CamRotGetFocalX, "Test get function for bInternalDataUpdated")
{
  /* define input values */
  float32 xRot, yRot, zRot;
  float32 xTrans, yTrans, zTrans;
  float32 xFocalLength, yFocalLength;
  float32 xLensCenter, yLensCenter;

  /* define output variable */
  float32 returnValue;

  /* Set input values */
  COU_SET_FMT(xRot        ,   -1.6247891, "%.6f", "Set xRot");
  COU_SET_FMT(yRot        ,    0.0225971, "%.6f", "Set yRot");
  COU_SET_FMT(zRot        ,   -1.5672151, "%.6f", "Set zRot");
  COU_SET_FMT(xTrans      ,   -1.504    , "%.6f", "Set xTrans");
  COU_SET_FMT(yTrans      ,   -0.08     , "%.6f", "Set yTrans");
  COU_SET_FMT(zTrans      ,    1.20358  , "%.6f", "Set zTrans");
  COU_SET_FMT(xFocalLength, 1235.2f     , "%.6f", "Set xFocalLength");
  COU_SET_FMT(yFocalLength, 1235.1f     , "%.6f", "Set yFocalLength");
  COU_SET_FMT(xLensCenter ,  594.132f   , "%.6f", "Set xLensCenter");
  COU_SET_FMT(yLensCenter ,  314.886f   , "%.6f", "Set yLensCenter");



  /* Initialize CamRot Data */
  COU_CALL(HLACamRotInit(), "Initialize CamRot Data");

  /* Call set function for CamRot data */
  COU_CALL(HLACamRotSetData(xRot, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  /* Set returnValue by call */
  COU_SET(returnValue, HLACamRotGetFocalX(), "Call get function for Focal length in x direction");

  COU_ASSERT_EQUAL_FMT(returnValue, HLACamRot.FX, "%.6f", "Return value of HLACamRotGetFocalX is correct");
}


/** \test
 *  \description
 *     Test the get function for bInternalDataUpdated \n
 *     Calls functions HLACamRotSetData() \n
 *                     HLACamRotGetWasInternalDataUpdated() \n
 *  \precondition
 *     HLACamRot data is set and an update has happened. \n
 *  \result
 *     bInternalDataUpdated is set to TRUE and HLACamRotGetWasInternalDataUpdated returns TRUE. \n
 */
TEST_CamRotGetXb(CamRotGetXb, "Test get function for image coordinates")
{
  /* define input values */
  float32 xRot, yRot, zRot;
  float32 xTrans, yTrans, zTrans;
  float32 xFocalLength, yFocalLength;
  float32 xLensCenter, yLensCenter;
  float32 x_world, y_world, z_world;

  /* define output storage values */
  float32 x_image, y_image;

  /* define expected output values */
  float32 x_image_expectation, y_image_expectation;

  /*define helper variables*/
  float32 xk, yk, zk;
  float32 xwt, ywt, zwt;

  /* Set input values */
  COU_SET_FMT(xRot        ,   -1.6247891, "%.6f", "Set xRot");
  COU_SET_FMT(yRot        ,    0.0225971, "%.6f", "Set yRot");
  COU_SET_FMT(zRot        ,   -1.5672151, "%.6f", "Set zRot");
  COU_SET_FMT(xTrans      ,   -1.504    , "%.6f", "Set xTrans");
  COU_SET_FMT(yTrans      ,   -0.08     , "%.6f", "Set yTrans");
  COU_SET_FMT(zTrans      ,    1.20358  , "%.6f", "Set zTrans");
  COU_SET_FMT(xFocalLength, 1235.2f     , "%.6f", "Set xFocalLength");
  COU_SET_FMT(yFocalLength, 1235.1f     , "%.6f", "Set yFocalLength");
  COU_SET_FMT(xLensCenter ,  594.132f   , "%.6f", "Set xLensCenter");
  COU_SET_FMT(yLensCenter ,  314.886f   , "%.6f", "Set yLensCenter");

  /* Set world coordinates to our beloved street lamp constraints */
  COU_SET_FMT(x_world, 30.0f, "%.6f", "Set world x-value");
  COU_SET_FMT(y_world,  0.0f, "%.6f", "Set world y-value");
  COU_SET_FMT(z_world,  6.0f, "%.6f", "Set world z-value");

  /* Initialize CamRot Data */
  COU_CALL(HLACamRotInit(), "Initialize CamRot Data");

  /* Call set function for CamRot data */
  COU_CALL(HLACamRotSetData(xRot, yRot, zRot, xTrans, yTrans, zTrans, xFocalLength, yFocalLength, xLensCenter, yLensCenter), "Set CamRot Data");

  /* Calculate expected image coordinates */
  xwt = x_world - HLACamRot.T[0];
  ywt = y_world - HLACamRot.T[1];
  zwt = z_world - HLACamRot.T[2];

  xk = HLACamRot.ROT_K[0] * xwt + HLACamRot.ROT_K[1] * ywt + HLACamRot.ROT_K[2] * zwt;
  yk = HLACamRot.ROT_K[3] * xwt + HLACamRot.ROT_K[4] * ywt + HLACamRot.ROT_K[5] * zwt;
  zk = HLACamRot.ROT_K[6] * xwt + HLACamRot.ROT_K[7] * ywt + HLACamRot.ROT_K[8] * zwt;

  x_image_expectation = HLACamRot.FX / zk * xk + HLACamRot.XO;
  y_image_expectation = HLACamRot.FY / zk * yk + HLACamRot.YO;

  /* Call FUT */
  COU_CALL(HLACamRotGetXb(&x_image, &y_image, x_world, y_world, z_world), "Call HLACamRotGetXb");

  /* Check output */
  COU_ASSERT_EQUAL_FMT(x_image, x_image_expectation, "%.6f", "Image x-coordinate is correct");
  COU_ASSERT_EQUAL_FMT(y_image, y_image_expectation, "%.6f", "Image y-coordinate is correct");
}


/* Helper function to test ROT_K = ROT_W' */
static void subTestsRotK(void)
{
  /* Check ROT_K */
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[0], HLACamRot.ROT_W[0], "%.6f", "ROT_K[0] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[1], HLACamRot.ROT_W[3], "%.6f", "ROT_K[1] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[2], HLACamRot.ROT_W[6], "%.6f", "ROT_K[2] is set correctly");

  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[3], HLACamRot.ROT_W[1], "%.6f", "ROT_K[3] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[4], HLACamRot.ROT_W[4], "%.6f", "ROT_K[4] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[5], HLACamRot.ROT_W[7], "%.6f", "ROT_K[5] is set correctly");

  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[6], HLACamRot.ROT_W[2], "%.6f", "ROT_K[6] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[7], HLACamRot.ROT_W[5], "%.6f", "ROT_K[7] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K[8], HLACamRot.ROT_W[8], "%.6f", "ROT_K[8] is set correctly");
}

/* Helper function to test ROT_K_a = d(ROT_K)/d(a) */
static void subTestsRotKa(void)
{
  /* Check ROT_K_a */
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[0],  EMPTYNESS,          "%.6f", "ROT_K_a[0] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[1],  EMPTYNESS,          "%.6f", "ROT_K_a[1] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[2],  EMPTYNESS,          "%.6f", "ROT_K_a[2] is set correctly");

  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[3],  HLACamRot.ROT_W[2], "%.6f", "ROT_K_a[3] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[4],  HLACamRot.ROT_W[5], "%.6f", "ROT_K_a[4] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[5],  HLACamRot.ROT_W[8], "%.6f", "ROT_K_a[5] is set correctly");

  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[6], -HLACamRot.ROT_W[1], "%.6f", "ROT_K_a[6] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[7], -HLACamRot.ROT_W[4], "%.6f", "ROT_K_a[7] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_a[8], -HLACamRot.ROT_W[7], "%.6f", "ROT_K_a[8] is set correctly");
}

/* Helper function to test ROT_K_c = d(ROT_K)/d(c) */
static void subTestsRotKc(void)
{
  /* Check ROT_K_c */
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[0], -HLACamRot.ROT_W[3], "%.6f", "ROT_K_c[0] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[1],  HLACamRot.ROT_W[0], "%.6f", "ROT_K_c[1] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[2],  EMPTYNESS         , "%.6f", "ROT_K_c[2] is set correctly");

  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[3], -HLACamRot.ROT_W[4], "%.6f", "ROT_K_c[3] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[4],  HLACamRot.ROT_W[1], "%.6f", "ROT_K_c[4] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[5],  EMPTYNESS         , "%.6f", "ROT_K_c[5] is set correctly");

  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[6], -HLACamRot.ROT_W[5], "%.6f", "ROT_K_c[6] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[7],  HLACamRot.ROT_W[2], "%.6f", "ROT_K_c[7] is set correctly");
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_K_c[8],  EMPTYNESS         , "%.6f", "ROT_K_c[8] is set correctly");
}

/* Helper function to test ROT_KW_a = ROT_K_a * ROT_W */
static void subTestsRotKWa(void)
{
  float32 testResult;

  /* Check ROT_KW_a */
  testResult = (HLACamRot.ROT_K_a[0] * HLACamRot.ROT_W[0]) + (HLACamRot.ROT_K_a[1] * HLACamRot.ROT_W[3]) + (HLACamRot.ROT_K_a[2] * HLACamRot.ROT_W[6]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[0], testResult, "%.6f", "ROT_KW_a[0] is set correctly");
  testResult = (HLACamRot.ROT_K_a[0] * HLACamRot.ROT_W[1]) + (HLACamRot.ROT_K_a[1] * HLACamRot.ROT_W[4]) + (HLACamRot.ROT_K_a[2] * HLACamRot.ROT_W[7]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[1], testResult, "%.6f", "ROT_KW_a[1] is set correctly");
  testResult = (HLACamRot.ROT_K_a[0] * HLACamRot.ROT_W[2]) + (HLACamRot.ROT_K_a[1] * HLACamRot.ROT_W[5]) + (HLACamRot.ROT_K_a[2] * HLACamRot.ROT_W[8]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[2], testResult, "%.6f", "ROT_KW_a[2] is set correctly");

  testResult = (HLACamRot.ROT_K_a[3] * HLACamRot.ROT_W[0]) + (HLACamRot.ROT_K_a[4] * HLACamRot.ROT_W[3]) + (HLACamRot.ROT_K_a[5] * HLACamRot.ROT_W[6]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[3], testResult, "%.6f", "ROT_KW_a[3] is set correctly");
  testResult = (HLACamRot.ROT_K_a[3] * HLACamRot.ROT_W[1]) + (HLACamRot.ROT_K_a[4] * HLACamRot.ROT_W[4]) + (HLACamRot.ROT_K_a[5] * HLACamRot.ROT_W[7]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[4], testResult, "%.6f", "ROT_KW_a[4] is set correctly");
  testResult = (HLACamRot.ROT_K_a[3] * HLACamRot.ROT_W[2]) + (HLACamRot.ROT_K_a[4] * HLACamRot.ROT_W[5]) + (HLACamRot.ROT_K_a[5] * HLACamRot.ROT_W[8]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[5], testResult, "%.6f", "ROT_KW_a[5] is set correctly");

  testResult = (HLACamRot.ROT_K_a[6] * HLACamRot.ROT_W[0]) + (HLACamRot.ROT_K_a[7] * HLACamRot.ROT_W[3]) + (HLACamRot.ROT_K_a[8] * HLACamRot.ROT_W[6]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[6], testResult, "%.6f", "ROT_KW_a[6] is set correctly");
  testResult = (HLACamRot.ROT_K_a[6] * HLACamRot.ROT_W[1]) + (HLACamRot.ROT_K_a[7] * HLACamRot.ROT_W[4]) + (HLACamRot.ROT_K_a[8] * HLACamRot.ROT_W[7]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[7], testResult, "%.6f", "ROT_KW_a[7] is set correctly");
  testResult = (HLACamRot.ROT_K_a[6] * HLACamRot.ROT_W[2]) + (HLACamRot.ROT_K_a[7] * HLACamRot.ROT_W[5]) + (HLACamRot.ROT_K_a[8] * HLACamRot.ROT_W[8]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_a[8], testResult, "%.6f", "ROT_KW_a[8] is set correctly");
}

/* Helper function to test ROT_KW_c = ROT_K_c * ROT_W */
static void subTestsRotKWc(void)
{
  float32 testResult;
  /* Check ROT_KW_c */
  testResult = (HLACamRot.ROT_K_c[0] * HLACamRot.ROT_W[0]) + (HLACamRot.ROT_K_c[1] * HLACamRot.ROT_W[3]) + (HLACamRot.ROT_K_c[2] * HLACamRot.ROT_W[6]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[0], testResult, "%.6f", "ROT_KW_c[0] is set correctly");
  testResult = (HLACamRot.ROT_K_c[0] * HLACamRot.ROT_W[1]) + (HLACamRot.ROT_K_c[1] * HLACamRot.ROT_W[4]) + (HLACamRot.ROT_K_c[2] * HLACamRot.ROT_W[7]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[1], testResult, "%.6f", "ROT_KW_c[1] is set correctly");
  testResult = (HLACamRot.ROT_K_c[0] * HLACamRot.ROT_W[2]) + (HLACamRot.ROT_K_c[1] * HLACamRot.ROT_W[5]) + (HLACamRot.ROT_K_c[2] * HLACamRot.ROT_W[8]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[2], testResult, "%.6f", "ROT_KW_c[2] is set correctly");

  testResult = (HLACamRot.ROT_K_c[3] * HLACamRot.ROT_W[0]) + (HLACamRot.ROT_K_c[4] * HLACamRot.ROT_W[3]) + (HLACamRot.ROT_K_c[5] * HLACamRot.ROT_W[6]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[3], testResult, "%.6f", "ROT_KW_c[3] is set correctly");
  testResult = (HLACamRot.ROT_K_c[3] * HLACamRot.ROT_W[1]) + (HLACamRot.ROT_K_c[4] * HLACamRot.ROT_W[4]) + (HLACamRot.ROT_K_c[5] * HLACamRot.ROT_W[7]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[4], testResult, "%.6f", "ROT_KW_c[4] is set correctly");
  testResult = (HLACamRot.ROT_K_c[3] * HLACamRot.ROT_W[2]) + (HLACamRot.ROT_K_c[4] * HLACamRot.ROT_W[5]) + (HLACamRot.ROT_K_c[5] * HLACamRot.ROT_W[8]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[5], testResult, "%.6f", "ROT_KW_c[5] is set correctly");

  testResult = (HLACamRot.ROT_K_c[6] * HLACamRot.ROT_W[0]) + (HLACamRot.ROT_K_c[7] * HLACamRot.ROT_W[3]) + (HLACamRot.ROT_K_c[8] * HLACamRot.ROT_W[6]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[6], testResult, "%.6f", "ROT_KW_c[6] is set correctly");
  testResult = (HLACamRot.ROT_K_c[6] * HLACamRot.ROT_W[1]) + (HLACamRot.ROT_K_c[7] * HLACamRot.ROT_W[4]) + (HLACamRot.ROT_K_c[8] * HLACamRot.ROT_W[7]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[7], testResult, "%.6f", "ROT_KW_c[7] is set correctly");
  testResult = (HLACamRot.ROT_K_c[6] * HLACamRot.ROT_W[2]) + (HLACamRot.ROT_K_c[7] * HLACamRot.ROT_W[5]) + (HLACamRot.ROT_K_c[8] * HLACamRot.ROT_W[8]);
  COU_ASSERT_EQUAL_FMT(HLACamRot.ROT_KW_c[8], testResult, "%.6f", "ROT_KW_c[8] is set correctly");
}


/* list of all test methods of the related suite. */
cou_test_t hla_cam_rot_tests[] = {
  COU_ADD_TEST(CamRotInit),
  COU_ADD_TEST(CamRotSetData),
  COU_ADD_TEST(CamRotSetDataNoUpdate),
  COU_ADD_TEST(CamRotGetFocalX),
  COU_ADD_TEST(CamRotGetUpdateNeeded),
  COU_ADD_TEST(CamRotGetXb),
  //COU_ADD_TEST(/**/),
  COU_ADD_TEST_END
};

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(Cam_Rot_Init, "Initialize CamRot Module")
{
  COU_CALL(HLACamRotInit(),"Initialize CamRot Module");
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_Cam_Rot, hla_cam_rot_tests, Cam_Rot_Init, "Module test for hla_cam_rot.c"),
   COU_ADD_SUITE_END,
};

#endif /* #ifdef __COURAGE_TEST_SWITCH__ */
