/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include <courage.h>
#include <mockup.h>
#include <string.h>
#include <glob_type.h>
#include <rte_type.h>

/* include FUT header */
#include <hlaf_matrixgfa.h>
#include <HLA_MatrixParameters.h>
#include <hla_cam_rot.h>
#include <hla_cpar_init.h>

// over define COU_TEST to get a automatic link between each test case description
// and the detailed design of a function when adding the test_PkgName.c as input source
// for the detailed design doxygen generator
#define TEST_MatrixGFA_Init                     COU_TEST
#define TEST_MatrixGFA_Main                     COU_TEST
#define TEST_MatrixGFA_Main_PreviousGFA         COU_TEST
#define TEST_MatrixGFA_AddObj2VC                COU_TEST
#define TEST_MatrixGFA_MergeVC                  COU_TEST
#define TEST_MatrixGFA_GetOverlapVC2VC          COU_TEST
#define TEST_MatrixGFA_ReduceVC2MaxNumGFA       COU_TEST
#define TEST_MatrixGFA_AssignVC2GFA             COU_TEST
#define TEST_MatrixGFA_AssignUnusedVC2FreeGFA   COU_TEST
#define TEST_MatrixGFA_AssignUnusedVC2LostGFA   COU_TEST
#define TEST_MatrixGFA_UpdateGFAData            COU_TEST
#define TEST_MatrixGFA_DeleteGFA                COU_TEST
#define test_HLAFMatrixGFA_MergeOverlappingVC_VCsOverlapp_VCAreMerged COU_TEST

/* more local defines */
#define EMPTYNESS 0.0f

/* location to hold GFA data */
static HLAFMatrixInt_t storageMatrix;

/* external functions */
extern void HLAFMatrix_PrepareObjectList( const reqHlaPrtList_t*                        const pReqPorts,
                                          const LSD_LightObjectList_t*                  const pObjectList,
                                          const LSD_LightList_t*                        const pLightList,
                                                HLAFMatrixData_t*                       const pData,
                                          const RTE_HLAF_ParameterVehicleProbability_t* const pVehProbPar,
                                          const t_MatrixParametersSAE*                  const pSAEPar
                                        );

extern void HLAFMatrixGFA_AddObj2VC( const HLAObjectDataInt_t*             const pIntObj,
                                           HLAFMatrixGFA_VehClusterData_t* const pVC
                                   );

extern void HLAFMatrixGFA_MergeVC( const HLAFMatrixGFA_VehClusterData_t* const pVC,
                                         HLAFMatrixGFA_VehClusterData_t* const pVCmerged
                                 );

extern float32 HLAFMatrixGFA_GetOverlapVC2VC(const t_MatrixParametersClusterVeh2GFA* const pPar,
                                             const HLAFMatrixGFA_VehClusterData_t*   const pVC0,
                                             const HLAFMatrixGFA_VehClusterData_t*   const pVC1
                                            );

extern void HLAFMatrixGFA_ReduceVC2MaxNumGFA(const t_MatrixParameters*         const pPar,
                                             const uint32                            MaxNumGFA,
                                             const uint32                            numRelVehicles,
                                                   HLAFMatrixData_t*           const pData,
                                                   HLAFMatrixGFA_VehCluster_t* const pVC
                                            );

extern void HLAFMatrixGFA_AssignVC2GFA(const t_MatrixParameters*         const pPar,
                                       const HLAFMatrixData_t*           const pData,
                                             HLAFMatrixGFA_VehCluster_t* const pVC
                                      );

extern void HLAFMatrixGFA_AssignUnusedVC2FreeGFA(      HLAFMatrixData_t*           const pData,
                                                 const uint32                            MaxNumGFA,
                                                       HLAFMatrixGFA_VehCluster_t* const pVC
                                                );

extern void HLAFMatrixGFA_AssignUnusedVC2LostGFA(const HLAFMatrixData_t*           const pData,
                                                       HLAFMatrixGFA_VehCluster_t* const pVC
                                                );

extern void HLAFMatrixGFA_UpdateGFAData( const LSD_LightObjectList_t* const pObjectList,
                                         const LSD_LightList_t*       const pLightList,
                                         const t_MatrixParameters*    const pPar,
                                         const float32                      focalLenghtY,
                                               HLAFMatrixData_t*      const pData
                                       );

extern void HLAFMatrixGFA_DeleteGFA( const t_MatrixParameters*    const pPar,
                                     const HLAFData_t*            const pFData,
                                           HLAFMatrixData_t*      const pData
                                   );

extern void HLAFMatrixGFA_MergeOverlappingVC( const t_MatrixParameters*         const pPar,
                                              const uint32                            numRelVehicles,
                                                    HLAFMatrixData_t*           const pData,
                                                    HLAFMatrixGFA_VehCluster_t* const pVC
                                            );

extern HLACamRot_t HLACamRot;

/* ----------------------------------- */
/* --- Local function declarations --- */
/* ----------------------------------- */
static void SetupLightObjectList( LSD_LightObjectList_t*  pObjectList,
                                  LSD_LightList_t*        pLightList,
                                  HLAFMatrixData_t*       pHlafMatrixDatas,
                                  uint8                   numObjects
                                );
/* ------------------------------------------ */
/* --- End of local function declarations --- */
/* ------------------------------------------ */

/** \test
 *  \description
 *     Test the initialization function \n
 *     Calls function HLAFMatrixGFA_Init() \n
 *  \precondition
 *     Memory to store the HLAFMatrixGFA test structure must be available \n
 *  \result
 *     HLAFMatrixGFA structure is initialized according to design specs. \n
 *     Exact results are not mentioned here due to prevent redundancy \n
 */
TEST_MatrixGFA_Init(MatrixGFA_Init, "Test the Init function for GFA calculations")
{
  /* Testing data */
  HLAFMatrixGFA_t TestGFA;

  uint8 i;

  /* Call function under test: Initialization of HLAFMatrixGFA */
  COU_CALL(HLAFMatrixGFA_Init(&TestGFA), "Calling FOT");

  /* Test if HLAFMatrixGFA has been initialized correctly */
  COU_ASSERT_EQUAL(TestGFA.nGFA, 0u, "Number of GFA should be equal to 0");
  COU_ASSERT_EQUAL(TestGFA.GFAStatus, RTE_HLAF_SIGSTAT_INIT, "GFA Status should be set to INIT");

  for(i = 0u; i < RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    /* All object states are set to 1 */
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_NO_OBJ, "GFA[%i]: Status of left boundary should be set to RTE_HLAF_OBJSTA_NO_OBJ"          , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_NO_OBJ, "GFA[%i]: Status of lower boundary should be set to RTE_HLAF_OBJSTA_NO_OBJ"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_NO_OBJ, "GFA[%i]: Status of right boundary should be set to RTE_HLAF_OBJSTA_NO_OBJ"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_NO_OBJ, "GFA[%i]: Status of upper boundary should be set to RTE_HLAF_OBJSTA_NO_OBJ"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ClosestObj_Status, RTE_HLAF_OBJSTA_NO_OBJ, "GFA[%i]: Status of closest object should be set to RTE_HLAF_OBJSTA_NO_OBJ"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.MinLight_Status,   RTE_HLAF_OBJSTA_NO_OBJ, "GFA[%i]: Status of minimum lighting object should be set to RTE_HLAF_OBJSTA_NO_OBJ", i);

    /* All object IDs are set to 255 */
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLeft_ObjId,  UI8_T_MAX, "GFA[%i]: ID of left boundary should be set to UI8_T_MAX"          , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLower_ObjId, UI8_T_MAX, "GFA[%i]: ID of lower boundary should be set to UI8_T_MAX"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryRight_ObjId, UI8_T_MAX, "GFA[%i]: ID of right boundary should be set to UI8_T_MAX"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryUpper_ObjId, UI8_T_MAX, "GFA[%i]: ID of upper boundary should be set to UI8_T_MAX"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ClosestObj_ObjId, UI8_T_MAX, "GFA[%i]: ID of closest object should be set to UI8_T_MAX"         , i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.MinLight_ObjId,   UI8_T_MAX, "GFA[%i]: ID of minimum lighting object should be set to UI8_T_MAX", i);

    /* Everything else is set to 0u/0.0f/UNKNOWN */
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLeft_Ang,        EMPTYNESS,                  "GFA[%i]: Angle of left boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLeft_Ang_Cam,    EMPTYNESS,                  "GFA[%i]: Camera angle of left boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLeft_Dist,       EMPTYNESS,                  "GFA[%i]: Distance of left boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLeft_DistState,  RTE_HLAF_DISTSTATE_UNKNOWN, "GFA[%i]: Distance state of left boundary should be set to RTE_HLAF_DISTSTATE_UNKNOWN", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLower_Ang_Cam,   EMPTYNESS,                  "GFA[%i]: Camera angle of lower boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryLower_DistState, RTE_HLAF_DISTSTATE_UNKNOWN, "GFA[%i]: Distance state of lower boundary should be set to RTE_HLAF_DISTSTATE_UNKNOWN", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryRight_Ang,       EMPTYNESS,                  "GFA[%i]: Angle of right boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryRight_Ang_Cam,   EMPTYNESS,                  "GFA[%i]: Camera angle of right boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryRight_Dist,      EMPTYNESS,                  "GFA[%i]: Distance of right boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryRight_DistState, RTE_HLAF_DISTSTATE_UNKNOWN, "GFA[%i]: Distance state of right boundary should be set to RTE_HLAF_DISTSTATE_UNKNOWN", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryUpper_Ang_Cam,   EMPTYNESS,                  "GFA[%i]: Camera angle of upper boundary should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.BndryUpper_DistState, RTE_HLAF_DISTSTATE_UNKNOWN, "GFA[%i]: Distance state of upper boundary should be set to RTE_HLAF_DISTSTATE_UNKNOWN", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ClosestObj_Ang,       EMPTYNESS,                  "GFA[%i]: Angle of closest object should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ClosestObj_Dist,      EMPTYNESS,                  "GFA[%i]: Distance of closest object should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ClosestObj_DistState, RTE_HLAF_DISTSTATE_UNKNOWN, "GFA[%i]: Distance state of closest object should be set to RTE_HLAF_DISTSTATE_UNKNOWN", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ExistenceProb,        EMPTYNESS,                  "GFA[%i]: Existence probability should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.MinLight_Ang,         EMPTYNESS,                  "GFA[%i]: Angle of minimum lighting should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.MinLight_Dist,        EMPTYNESS,                  "GFA[%i]: Distance of minimum lighting should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.MinLight_DistState,   RTE_HLAF_DISTSTATE_UNKNOWN, "GFA[%i]: Distance state of minimum lighting should be set to RTE_HLAF_DISTSTATE_UNKNOWN", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ttb18Left,            EMPTYNESS,                  "GFA[%i]: Left time to border should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ttb18Left_Status,     RTE_HLAF_TTBSTA_NO_OBJ,     "GFA[%i]: Left time to border status should be set to RTE_HLAF_TTBSTA_NO_OBJ", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ttb18Right,           EMPTYNESS,                  "GFA[%i]: Right time to border should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Ext.ttb18Right_Status,    RTE_HLAF_TTBSTA_NO_OBJ,     "GFA[%i]: Right time to border status should be set to RTE_HLAF_TTBSTA_NO_OBJ", i);

    COU_ASSERT_EQUAL(TestGFA.GFA[i].Int.ObjID,          LSD_LIGHT_OBJECT_LIST_LENGTH, "GFA[%i]: Internal Object should be set to LSD_LIGHT_OBJECT_LIST_LENGTH", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Int.TTB18Left_max,  EMPTYNESS, "GFA[%i]: Internal Object left time to border maximum should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Int.TTB18Left_min,  EMPTYNESS, "GFA[%i]: Internal Object left time to border minimum should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Int.TTB18Right_max, EMPTYNESS, "GFA[%i]: Internal Object right time to border maximum should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Int.TTB18Right_min, EMPTYNESS, "GFA[%i]: Internal Object right time to border minimum should be set to zero", i);
    COU_ASSERT_EQUAL(TestGFA.GFA[i].Int.TimerNoVeh_s,   EMPTYNESS, "GFA[%i]: Internal Object no vehicle timer  should be set to zero", i);
  }
}

/** \test
 *  \description
 *     Test the main function \n
 *     Calls function CParInitCPAR_HLAF_Parameter() to initialize the HLA CPARs, \n
 *     the function GetMatrixParameters() to get the internal parameters \n
 *     the function HLAFMatrix_PrepareObjectList() to prepare the object list \n
 *     and finally the function under test HLAFMatrixGFA_Main(). \n
 *  \precondition
 *      There are five light objects with associated lights available, these also have been converted
 *      to the internal hla objects, parameters and internal data have been initialized. \n
 *  \result
 *      There are two GFAs created with the correct border attributes. \n
 */
TEST_MatrixGFA_Main(MatrixGFA_Main, "Test the function with four objects and no previous GFA data")
{
  /* input data structures */
  reqHlaPrtList_t               requestPorts;
  const t_MatrixParameters*     pParameter;
  t_MatrixParameters            ParameterIn;
  HLAFData_t                    functionData;

  /* helper data structures */
  MonoCalibration_t     monoCaliHelper;
  LSD_LightList_t       lightListHelper;
  LSD_LightObjectList_t lightObjectListHelper;
  CPAR_HLAF_Parameter_t hlafCPars;
  HLA_BusInputSignals_t HlaBusInputSignals;
  HLAObjectDataInt_t    helperObject;

  /* initialize input data */
  memset(&requestPorts, 0u, sizeof(requestPorts));
  memset(&functionData, 0u, sizeof(functionData));

  /* initialize helper data */
  memset(&monoCaliHelper, 0u, sizeof(monoCaliHelper));
  memset(&lightListHelper, 0u, sizeof(lightListHelper));
  memset(&lightObjectListHelper, 0u, sizeof(lightObjectListHelper));
  memset(&HlaBusInputSignals, 0u, sizeof(HlaBusInputSignals));
  memset(&hlafCPars, 0u, sizeof(hlafCPars));

  /* fill helper data */
  COU_SET_FMT(monoCaliHelper.sIntrinsic.fCenterX, 1235.1f, "%.1f", "Set x dimension of focal length in calibration");
  COU_SET_FMT(monoCaliHelper.sIntrinsic.fCenterY, 1235.1f, "%.1f", "Set y dimension of focal length in calibration");
  COU_SET_FMT(HLACamRot.FX, 1235.1f, "%.1f", "Set x dimension of focal length in cam_rot");

  /* set up objects to use */
  COU_SET_BY_CALL(SetupLightObjectList(&lightObjectListHelper, &lightListHelper, &functionData.hlafMatrixData, 5u), "Initialize light objects and light");

  /* create pairs of lights */
  COU_SET_FMT(lightObjectListHelper.lightObjects[0].general.lightObjectIDPaired, 1u, COU_FMT_UINT, "Link light object 0 to light object 1");
  COU_SET_FMT(lightObjectListHelper.lightObjects[1].general.lightObjectIDPaired, 0u, COU_FMT_UINT, "Link light object 1 to light object 0");
  COU_SET_FMT(lightObjectListHelper.lightObjects[2].general.lightObjectIDPaired, 3u, COU_FMT_UINT, "Link light object 2 to light object 3");
  COU_SET_FMT(lightObjectListHelper.lightObjects[3].general.lightObjectIDPaired, 2u, COU_FMT_UINT, "Link light object 3 to light object 2");

  /* set up request ports */
  COU_SET_BY_CALL(CParInitCPAR_HLAF_Parameter(&hlafCPars), "Set CPAR pointer in request ports");
  COU_SET_FMT(requestPorts.pMonoCalibration, &monoCaliHelper, COU_FMT_PTR, "Set calibration pointer in request ports");
  COU_SET_FMT(requestPorts.pCPar_HlafPar, &hlafCPars, COU_FMT_PTR, "Set CPAR pointer in request ports");
  COU_SET_FMT(requestPorts.pLsdLightList, &lightListHelper, COU_FMT_PTR, "Set light list pointer in request ports");
  COU_SET_FMT(requestPorts.pHlaBusInputSignals, &HlaBusInputSignals, COU_FMT_PTR, "Set bus input signals pointer in request ports");
  COU_SET_FMT(requestPorts.pLsdLightObjectList, &lightObjectListHelper, COU_FMT_PTR, "Set light object list pointer in request ports");

  /* create simulation data */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");

  /* copy Parameter */
  (void)memcpy(&ParameterIn, pParameter, sizeof(pParameter));

  /* use default parameter */
  ParameterIn.ClusterVeh2GFA.dAngPrec = 0.05235988f;
  ParameterIn.ClusterVeh2GFA.dAngOnc = 0.05235988f;
  ParameterIn.ClusterVeh2GFA.dAng = 0.01745329f;

  /* initialize internal objects */

  /* convert to internal objects */
  COU_CALL(HLAFMatrix_PrepareObjectList(&requestPorts, requestPorts.pLsdLightObjectList, requestPorts.pLsdLightList, &(functionData.hlafMatrixData), &(requestPorts.pCPar_HlafPar->VehicleProbabilities), &(pParameter->SAE)), "Convert light objects into internal objects");

  /* set CPAR */
  COU_SET_FMT(hlafCPars.Matrix.MaxNumGlarefreeArea, 4u, COU_FMT_UINT, "Set number of GFAs in CPAR");

  /* call function under test with prepared data */
  COU_CALL(HLAFMatrixGFA_Main(&requestPorts, &ParameterIn, &functionData, &(functionData.hlafMatrixData)), "Calling FUT");

  /* check output */
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.nGFA, 2u, COU_FMT_UINT, "There are two GFAs now");

  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA left boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA right boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA upper boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA lower boundary status is oncoming");

  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA left boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA right boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA upper boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA lower boundary status is oncoming");

  /* save output for next test */
  storageMatrix = functionData.hlafMatrixData.Matrix;
}

/** \test
 *  \description
 *     Test the main function \n
 *     Calls function CParInitCPAR_HLAF_Parameter() to initialize the HLA CPARs, \n
 *     the function GetMatrixParameters() to get the internal parameters \n
 *     the function HLAFMatrix_PrepareObjectList() to prepare the object list \n
 *     and finally the function under test HLAFMatrixGFA_Main(). \n
 *  \precondition
 *      There are five light objects with associated lights available, these also have been converted
 *      to the internal hla objects, parameters and internal data have been initialized. \n
 *      After running the FUT the first time, two objects will be switched and the according GFA will be invalidated. \n
 *      The FUT will then run again. \n
 *  \result
 *      First there are two GFAs created with the correct border attributes. \n
 *      Second one GFA will be deleted, only one GFA is left with correct border attributes. \n
 */
TEST_MatrixGFA_Main_PreviousGFA(MatrixGFA_Main_PreviousGFA, "Test the function with four objects and no previous GFA data")
{
  /* input data structures */
  reqHlaPrtList_t               requestPorts;
  const t_MatrixParameters*     pParameter;
  t_MatrixParameters            ParameterIn;
  HLAFData_t                    functionData;

  /* helper data structures */
  MonoCalibration_t     monoCaliHelper;
  LSD_LightList_t       lightListHelper;
  LSD_LightObjectList_t lightObjectListHelper;
  CPAR_HLAF_Parameter_t hlafCPars;
  HLA_BusInputSignals_t HlaBusInputSignals;
  HLAObjectDataInt_t    helperObject;

  /* initialize input data */
  memset(&requestPorts, 0u, sizeof(requestPorts));
  memset(&functionData, 0u, sizeof(functionData));

  /* initialize helper data */
  memset(&monoCaliHelper, 0u, sizeof(monoCaliHelper));
  memset(&lightListHelper, 0u, sizeof(lightListHelper));
  memset(&lightObjectListHelper, 0u, sizeof(lightObjectListHelper));
  memset(&HlaBusInputSignals, 0u, sizeof(HlaBusInputSignals));
  memset(&hlafCPars, 0u, sizeof(hlafCPars));

  /* fill helper data */
  COU_SET_FMT(monoCaliHelper.sIntrinsic.fCenterX, 1235.1f, "%.1f", "Set x dimension of focal length in calibration");
  COU_SET_FMT(monoCaliHelper.sIntrinsic.fCenterY, 1235.1f, "%.1f", "Set y dimension of focal length in calibration");
  COU_SET_FMT(HLACamRot.FX, 1235.1f, "%.1f", "Set x dimension of focal length in cam_rot");

  /* set up objects to use */
  COU_SET_BY_CALL(SetupLightObjectList(&lightObjectListHelper, &lightListHelper, &functionData.hlafMatrixData, 5u), "Initialize light objects and light");

  /* create pairs of lights */
  COU_SET_FMT(lightObjectListHelper.lightObjects[0].general.lightObjectIDPaired, 1u, COU_FMT_UINT, "Link light object 0 to light object 1");
  COU_SET_FMT(lightObjectListHelper.lightObjects[1].general.lightObjectIDPaired, 0u, COU_FMT_UINT, "Link light object 1 to light object 0");

  /* set up request ports */
  COU_SET_BY_CALL(CParInitCPAR_HLAF_Parameter(&hlafCPars), "Set CPAR pointer in request ports");
  COU_SET_FMT(requestPorts.pMonoCalibration, &monoCaliHelper, COU_FMT_PTR, "Set calibration pointer in request ports");
  COU_SET_FMT(requestPorts.pCPar_HlafPar, &hlafCPars, COU_FMT_PTR, "Set CPAR pointer in request ports");
  COU_SET_FMT(requestPorts.pLsdLightList, &lightListHelper, COU_FMT_PTR, "Set light list pointer in request ports");
  COU_SET_FMT(requestPorts.pHlaBusInputSignals, &HlaBusInputSignals, COU_FMT_PTR, "Set bus input signals pointer in request ports");
  COU_SET_FMT(requestPorts.pLsdLightObjectList, &lightObjectListHelper, COU_FMT_PTR, "Set light object list pointer in request ports");

  /* create simulation data */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");

  /* copy Parameter */
  (void)memcpy(&ParameterIn, pParameter, sizeof(pParameter));

  /* use default parameter */
  ParameterIn.ClusterVeh2GFA.dAngPrec = 0.05235988f;
  ParameterIn.ClusterVeh2GFA.dAngOnc = 0.05235988f;
  ParameterIn.ClusterVeh2GFA.dAng = 0.01745329f;

  /* initialize internal objects */

  /* convert to internal objects */
  COU_CALL(HLAFMatrix_PrepareObjectList(&requestPorts, requestPorts.pLsdLightObjectList, requestPorts.pLsdLightList, &(functionData.hlafMatrixData), &(requestPorts.pCPar_HlafPar->VehicleProbabilities), &(pParameter->SAE)), "Convert light objects into internal objects");

  /* switch two objects */
                           helperObject = functionData.hlafMatrixData.Object[2];
  functionData.hlafMatrixData.Object[2] = functionData.hlafMatrixData.Object[3];
  functionData.hlafMatrixData.Object[3] = helperObject;

  /* reset associated light on fourth object */
  lightObjectListHelper.lightObjects[3].general.lightID = UI8_T_MAX;

  /* get old data */
  functionData.hlafMatrixData.Matrix = storageMatrix;

  functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLeft_Ang      = 0.001f;
  functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLower_Ang_Cam = 0.001f;
  functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryUpper_Ang_Cam = 1.000f;
  functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.ClosestObj_Dist    = 1.000f;
  functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.MinLight_Dist      = 1.000f;

  /* set CPAR */
  COU_SET_FMT(hlafCPars.Matrix.MaxNumGlarefreeArea, 10u, COU_FMT_UINT, "Set number of GFAs in CPAR");

  /* call function under test with prepared data */
  COU_CALL(HLAFMatrixGFA_Main(&requestPorts, &ParameterIn, &functionData, &(functionData.hlafMatrixData)), "Calling FUT");

  /* check output */
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.nGFA, 2u, COU_FMT_UINT, "There are two GFAs now");

  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA left boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA right boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA upper boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA lower boundary status is oncoming");

  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA left boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA right boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA upper boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Second GFA lower boundary status is oncoming");

  /* set CPAR */
  COU_SET_FMT(hlafCPars.Matrix.MaxNumGlarefreeArea, 0u, COU_FMT_UINT, "Set number of GFAs in CPAR");

  /* modify light objects a little bit */
  COU_SET_FMT(lightObjectListHelper.lightObjects[2].general.lightObjectIDPaired,            UI8_T_MAX, COU_FMT_UINT, "Unlink light object 2");
  COU_SET_FMT(lightObjectListHelper.lightObjects[2].attributes.probabilityVehicleOncoming,  50u,       COU_FMT_UINT, "Light object 2 is not so likely oncoming");
  COU_SET_FMT(lightObjectListHelper.lightObjects[2].attributes.probabilityVehiclePreceding, 75u,       COU_FMT_UINT, "Light object 2 is more likely preceding");

  COU_SET_FMT(lightObjectListHelper.lightObjects[3].general.lightObjectIDPaired, UI8_T_MAX, COU_FMT_UINT, "Unlink light object 3");
  COU_SET_FMT(lightObjectListHelper.lightObjects[3].general.lightID,             UI8_T_MAX, COU_FMT_UINT, "Light object 3 has no light associated");
  COU_SET_FMT(lightObjectListHelper.lightObjects[3].general.cyclesLost,          1u,        COU_FMT_UINT, "Light object 3 is losing tracking");

  COU_SET_FMT(functionData.hlafMatrixData.Object[3].bIsRelevantOnc,  0u, COU_FMT_UINT, "Unset relevant oncoming object indicator for object 3");
  COU_SET_FMT(functionData.hlafMatrixData.Object[3].bIsRelevantPrec, 0u, COU_FMT_UINT, "Unset relevant preceding object indicator for object 3");
  COU_SET_FMT(functionData.hlafMatrixData.Object[2].IntObjPairIdx,   UI8_T_MAX, COU_FMT_UINT, "Unset pair");
  COU_SET_FMT(functionData.hlafMatrixData.Object[3].IntObjPairIdx,   UI8_T_MAX, COU_FMT_UINT, "Unset pair");
  COU_SET_FMT(functionData.hlafMatrixData.Object[2].LiObjIDPair,     UI8_T_MAX, COU_FMT_UINT, "Unset pair");
  COU_SET_FMT(functionData.hlafMatrixData.Object[3].LiObjIDPair,     UI8_T_MAX, COU_FMT_UINT, "Unset pair");

  COU_SET_FMT(functionData.hlafMatrixData.Object[0].ObjNext, UI8_T_MAX, COU_FMT_UINT, "Reset next object");
  COU_SET_FMT(functionData.hlafMatrixData.Object[1].ObjNext, UI8_T_MAX, COU_FMT_UINT, "Reset next object");
  COU_SET_FMT(functionData.hlafMatrixData.Object[2].ObjNext, UI8_T_MAX, COU_FMT_UINT, "Reset next object");
  COU_SET_FMT(functionData.hlafMatrixData.Object[3].ObjNext, UI8_T_MAX, COU_FMT_UINT, "Reset next object");
  COU_SET_FMT(functionData.hlafMatrixData.Object[4].ObjNext, UI8_T_MAX, COU_FMT_UINT, "Reset next object");

  /* call FUT again */
  COU_CALL(HLAFMatrixGFA_Main(&requestPorts, pParameter, &functionData, &(functionData.hlafMatrixData)), "Calling FUT");

  /* check output */
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.nGFA, 1u, COU_FMT_UINT, "There is only one GFA left");

  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA left boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA right boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA upper boundary status is oncoming");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[0].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "First GFA lower boundary status is oncoming");

  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_NO_OBJ, COU_FMT_UINT, "Second GFA left boundary status is unknown");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_NO_OBJ, COU_FMT_UINT, "Second GFA right boundary status is unknown");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryUpper_Status, RTE_HLAF_OBJSTA_NO_OBJ, COU_FMT_UINT, "Second GFA upper boundary status is unknown");
  COU_ASSERT_EQUAL_FMT(functionData.hlafMatrixData.Matrix.GFA.GFA[1].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_NO_OBJ, COU_FMT_UINT, "Second GFA lower boundary status is unknown");

}

/** \test
 *  \description
 *     Test the function to add an object to a vehicle cluster \n
 *     Calls function HLAFMatrixGFA_AddObj2VC() \n
 *  \b Preconditions: \n
 *     case01: null pointer as light object given \n
 *     case02: null pointer as VC given \n
 *     case03: empty VC, irregular object given (not preceding, not oncoming) \n
 *     case04: empty VC, oncoming object given \n
 *     case05: empty VC, preceding object given \n
 *     case06: preceding VC, object oncoming, angles within and not nearer \n
 *     case07: preceding VC, object oncoming, angles outside and nearer \n
 *     case08: oncoming VC, object preceding, angles within and not nearer \n
 *     case09: oncoming VC, object preceding, angles outside and nearer \n
 *     case10: impossible object, not oncoming, not preceding, angles would indicate better fit \n
 *  \result
 *     case01: no vehicle cluster will be set up \n
 *     case02: function will not crash \n
 *     case03: no vehicle cluster will be set up \n
 *     case04: vehicle cluster set up as oncoming cluster \n
 *     case05: vehicle cluster set up as preceding cluster \n
 *     case06: vehicle cluster stays as it is \n
 *     case07: vehicle cluster changed to oncoming and angles have changed \n
 *     case08: vehicle cluster stays as it is \n
 *     case09: vehicle cluster changed to preceding and angles have changed \n
 *     case10: vehicle cluster stays as it is \n
 */
TEST_MatrixGFA_AddObj2VC(MatrixGFA_AddObj2VC, "Test the functionality to add an object to a vehicle cluster")
{
  const float32 leftAngle    = 0.1745f;
  const float32 leftAngleIn  = 0.1735f;
  const float32 rightAngleIn = 0.1725f;
  const float32 rightAngle   = 0.1715f;

  const float32 distance     = 150.00f;
  const float32 distanceNear = 100.00f;

  HLAObjectDataInt_t              testObj;
  HLAFMatrixGFA_VehClusterData_t  testVC;
  LSD_LightObject_t               testLightObj;

  /* init test data */
  memset(&testObj, 0u, sizeof(testObj));
  memset(&testVC, 0u, sizeof(testVC));
  memset(&testLightObj, 0u, sizeof(testLightObj));

  /* case 01: no object given */
  {
    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with no LightObject associated");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     0.0f,                    "%.4f",       "No change in VC.BndryLeft_Ang");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "No change in VC.BndryLeft_Status");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    0.0f,                    "%.4f",       "No change in VC.BndryRight_Ang");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "No change in VC.BndryRight_Status");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   0.0f,                    "%.4f",       "No change in VC.ClosestObj_Dist");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "No change in VC.ClosestObj_Status");
  }

  /* case 02: no VC given */
  {
    /* set associated light object */
    COU_SET_FMT(testObj.pLightObject, &testLightObj, COU_FMT_PTR, "Link LightObject");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, NULL), "Test AddObj2VC with no VC provided");

    COU_ASSERT_EQUAL_FATAL_FMT(NULL, NULL, COU_FMT_PTR, "Function is still running");
  }

  /* case03: VC not used, illegal object */
  {
    COU_SET_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's left boundary to unused");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's right boundary to unused");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's closest object to unused");

    COU_SET_FMT(testLightObj.kinematic.world.x, distanceNear, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngle, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngle, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, FALSE, COU_FMT_UINT, "Set object to irregular state");
    COU_SET_FMT(testObj.bIsRelevantPrec, FALSE, COU_FMT_UINT, "Set object to irregular state");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     0.0f,                    "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    0.0f,                    "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   0.0f,                    "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case 04: VC not used, object oncoming  */
  {
    COU_SET_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's left boundary to unused");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's right boundary to unused");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's closest object to unused");

    COU_SET_FMT(testLightObj.kinematic.world.x, distance, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngle, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngle, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, TRUE, COU_FMT_UINT, "Set object to oncoming");
    COU_SET_FMT(testObj.bIsRelevantPrec, FALSE, COU_FMT_UINT, "Set object to oncoming");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngle,               "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngle,              "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distance,                "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case05: VC not used, object preceding */
  {
    COU_SET_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's left boundary to unused");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's right boundary to unused");

    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set VC's closest object to unused");

    COU_SET_FMT(testLightObj.kinematic.world.x, distanceNear, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngle, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngle, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, FALSE, COU_FMT_UINT, "Set object to preceding");
    COU_SET_FMT(testObj.bIsRelevantPrec, TRUE, COU_FMT_UINT, "Set object to preceding");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngle,                "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngle,               "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distanceNear,             "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case 06: VC already used - preceding, object oncoming, angles within and not nearer */
  {
    COU_SET_FMT(testVC.BndryLeft_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's left boundary to set to preceding");
    COU_SET_FMT(testVC.BndryLeft_Ang, leftAngle, "%.4f", "Set VC's left angle");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's right boundary to set to preceding");
    COU_SET_FMT(testVC.BndryRight_Ang, rightAngle, "%.4f", "Set VC's right angle");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's closest object to set to preceding");
    COU_SET_FMT(testVC.ClosestObj_Dist, distance, "%.4f", "Set VC's distance");

    COU_SET_FMT(testLightObj.kinematic.world.x, distance, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngleIn, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngleIn, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, TRUE, COU_FMT_UINT, "Set object to oncoming");
    COU_SET_FMT(testObj.bIsRelevantPrec, FALSE, COU_FMT_UINT, "Set object to oncoming");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngle,                "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngle,               "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distance,                 "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case07: VC already used - preceding, object oncoming, angles outside and nearer */
  {
    COU_SET_FMT(testVC.BndryLeft_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's left boundary to set to preceding");
    COU_SET_FMT(testVC.BndryLeft_Ang, leftAngleIn, "%.4f", "Set VC's left angle");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's right boundary to set to preceding");
    COU_SET_FMT(testVC.BndryRight_Ang, rightAngleIn, "%.4f", "Set VC's right angle");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's closest object to set to preceding");
    COU_SET_FMT(testVC.ClosestObj_Dist, distance, "%.4f", "Set VC's distance");

    COU_SET_FMT(testLightObj.kinematic.world.x, distanceNear, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngle, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngle, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, TRUE, COU_FMT_UINT, "Set object to oncoming");
    COU_SET_FMT(testObj.bIsRelevantPrec, FALSE, COU_FMT_UINT, "Set object to oncoming");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngle,               "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngle,              "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distanceNear,            "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case08: VC already used - preceding, object preceding, angles within and not nearer */
  {
    COU_SET_FMT(testVC.BndryLeft_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's left boundary to set to preceding");
    COU_SET_FMT(testVC.BndryLeft_Ang, leftAngle, "%.4f", "Set VC's left angle");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's right boundary to set to preceding");
    COU_SET_FMT(testVC.BndryRight_Ang, rightAngle, "%.4f", "Set VC's right angle");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's closest object to set to preceding");
    COU_SET_FMT(testVC.ClosestObj_Dist, distance, "%.4f", "Set VC's distance");

    COU_SET_FMT(testLightObj.kinematic.world.x, distance, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngleIn, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngleIn, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, FALSE, COU_FMT_UINT, "Set object to preceding");
    COU_SET_FMT(testObj.bIsRelevantPrec, TRUE, COU_FMT_UINT, "Set object to preceding");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngle,               "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngle,              "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distance,                "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case09: VC already used - preceding, object preceding, angles outside and nearer */
  {
    COU_SET_FMT(testVC.BndryLeft_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's left boundary to set to preceding");
    COU_SET_FMT(testVC.BndryLeft_Ang, leftAngleIn, "%.4f", "Set VC's left angle");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's right boundary to set to preceding");
    COU_SET_FMT(testVC.BndryRight_Ang, rightAngleIn, "%.4f", "Set VC's right angle");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's closest object to set to preceding");
    COU_SET_FMT(testVC.ClosestObj_Dist, distance, "%.4f", "Set VC's distance");

    COU_SET_FMT(testLightObj.kinematic.world.x, distanceNear, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngle, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngle, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, FALSE, COU_FMT_UINT, "Set object to preceding");
    COU_SET_FMT(testObj.bIsRelevantPrec, TRUE, COU_FMT_UINT, "Set object to preceding");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngle,               "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngle,              "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distanceNear,            "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }

  /* case10: impossible object, not oncoming, not preceding, angles would indicate better fit */
  {
    COU_SET_FMT(testVC.BndryLeft_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's left boundary to set to preceding");
    COU_SET_FMT(testVC.BndryLeft_Ang, leftAngleIn, "%.4f", "Set VC's left angle");
    COU_SET_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's right boundary to set to preceding");
    COU_SET_FMT(testVC.BndryRight_Ang, rightAngleIn, "%.4f", "Set VC's right angle");
    COU_SET_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set VC's closest object to set to preceding");
    COU_SET_FMT(testVC.ClosestObj_Dist, distance, "%.4f", "Set VC's distance");

    COU_SET_FMT(testLightObj.kinematic.world.x, distanceNear, "%.4f", "Set light object's distance");
    COU_SET_FMT(testObj.leftAng, leftAngle, "%.4f", "Set object's left angle");
    COU_SET_FMT(testObj.rightAng, rightAngle, "%.4f", "Set object's right angle");
    COU_SET_FMT(testObj.bIsRelevantOnc, FALSE, COU_FMT_UINT, "Set object to irregular state");
    COU_SET_FMT(testObj.bIsRelevantPrec, FALSE, COU_FMT_UINT, "Set object to irregular state");

    /* call FUT */
    COU_CALL( HLAFMatrixGFA_AddObj2VC(&testObj, &testVC), "Test AddObj2VC with an associated LightObject");

    /* check output */
    COU_ASSERT_EQUAL_FMT(testVC.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "No change in VC.Assignment_VC2GFA");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Ang,     leftAngleIn,              "%.4f",       "VC.BndryLeft_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryLeft_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Ang,    rightAngleIn,             "%.4f",       "VC.BndryRight_Ang has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.BndryRight_Status has correct state");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Dist,   distance,                 "%.4f",       "VC.ClosestObj_Dist has correct value");
    COU_ASSERT_EQUAL_FMT(testVC.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "VC.ClosestObj_Status has correct state");
  }
}

/** \test
 *  \description
 *     Test the function to merge two vehicle clusters \n
 *     Calls function HLAFMatrixGFA_MergeVC() \n
 *  \precondition
 *     case 01: first cluster is not a valid pointer \n
 *     case 02: second cluster is not a valid pointer \n
 *     case 03: first cluster is not a valid cluster \n
 *     case 04: first cluster is farther to the left \n
 *     case 05: first cluster is farther to the right \n
 *     case 06: first cluster is nearer \n
 *     case 07: first cluster is within second cluster \n
 *  \result
 *     case 01: function is not crashing \n
 *     case 02: function is not crashing\n
 *     case 03: second cluster has not changed \n
 *     case 04: second cluster has been expanded to the left \n
 *     case 05: second cluster has been expanded to the right \n
 *     case 06: second cluster has been expanded to the front \n
 *     case 07: second cluster has not changed \n
 */
TEST_MatrixGFA_MergeVC(MatrixGFA_MergeVC, "Test the functionality to merge vehicle clusters")
{
  const float32 leftAngle    = 0.1745f;
  const float32 leftAngleIn  = 0.1735f;
  const float32 rightAngleIn = 0.1725f;
  const float32 rightAngle   = 0.1715f;

  const float32 distance     = 150.00f;
  const float32 distanceNear = 100.00f;

  HLAFMatrixGFA_VehClusterData_t firstCluster, secondCluster;

  /* initialize clusters */
  memset(&firstCluster, 0u, sizeof(firstCluster));
  memset(&secondCluster, 0u, sizeof(secondCluster));

  /* case 01: first cluster is not a valid pointer */
  COU_CALL(HLAFMatrixGFA_MergeVC(NULL, &secondCluster), "Call of function under test");
  COU_ASSERT_EQUAL_FATAL_FMT(secondCluster.BndryLeft_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Function has not crashed everything.");

  /* case 02: second cluster is not a valid pointer */
  COU_CALL(HLAFMatrixGFA_MergeVC(&firstCluster, NULL), "Call of function under test");
  COU_ASSERT_EQUAL_FATAL_FMT(firstCluster.BndryLeft_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Function has not crashed everything.");

  /* case 03: first cluster is not a valid cluster */
  /* Setup first cluster */
  COU_SET_FMT(firstCluster.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "Set first cluster's assignment");
  COU_SET_FMT(firstCluster.BndryLeft_Ang,     leftAngle,               "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(firstCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(firstCluster.BndryRight_Ang,    rightAngle,              "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(firstCluster.BndryRight_Status, RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(firstCluster.ClosestObj_Dist,   distanceNear,            "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(firstCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  /* Setup second cluster */
  COU_SET_FMT(secondCluster.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "Set second cluster's assignment");
  COU_SET_FMT(secondCluster.BndryLeft_Ang,     leftAngleIn,              "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(secondCluster.BndryRight_Ang,    rightAngleIn,             "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(secondCluster.ClosestObj_Dist,   distance,                 "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  /* Call FUT */
  COU_CALL(HLAFMatrixGFA_MergeVC(&firstCluster, &secondCluster), "Call of function under test");

  /* Check outcome */
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Ang,     leftAngleIn,              "%.4f",       "Check second cluster's left angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's left angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Ang,    rightAngleIn,             "%.4f",       "Check second cluster's right angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's right angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Dist,   distance,                 "%.4f",       "Check second cluster's distance");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's distance status");


  /* case 04: first cluster is farther to the left */
  /* Setup first cluster */
  COU_SET_FMT(firstCluster.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "Set first cluster's assignment");
  COU_SET_FMT(firstCluster.BndryLeft_Ang,     leftAngle,               "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(firstCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(firstCluster.BndryRight_Ang,    rightAngleIn,            "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(firstCluster.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(firstCluster.ClosestObj_Dist,   distance,                "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(firstCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  /* Setup second cluster */
  COU_SET_FMT(secondCluster.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "Set second cluster's assignment");
  COU_SET_FMT(secondCluster.BndryLeft_Ang,     leftAngleIn,              "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  /* Call FUT */
  COU_CALL(HLAFMatrixGFA_MergeVC(&firstCluster, &secondCluster), "Call of function under test");

  /* Check outcome */
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Check second cluster's left angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ,  COU_FMT_UINT, "Check second cluster's left angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Check second cluster's right angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's right angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Check second cluster's distance");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's distance status");


  /* case 05: first cluster is farther to the right */
  /* Setup first cluster */
  COU_SET_FMT(firstCluster.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "Set first cluster's assignment");
  COU_SET_FMT(firstCluster.BndryLeft_Ang,     leftAngleIn,             "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(firstCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(firstCluster.BndryRight_Ang,    rightAngle,              "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(firstCluster.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(firstCluster.ClosestObj_Dist,   distance,                "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(firstCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  /* Setup second cluster */
  COU_SET_FMT(secondCluster.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "Set second cluster's assignment");
  COU_SET_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(secondCluster.BndryRight_Ang,    rightAngleIn,             "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  /* Call FUT */
  COU_CALL(HLAFMatrixGFA_MergeVC(&firstCluster, &secondCluster), "Call of function under test");

  /* Check outcome */
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Check second cluster's left angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's left angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Check second cluster's right angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ,  COU_FMT_UINT, "Check second cluster's right angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Check second cluster's distance");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's distance status");


  /* case 06: first cluster is nearer */
  /* Setup first cluster */
  COU_SET_FMT(firstCluster.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "Set first cluster's assignment");
  COU_SET_FMT(firstCluster.BndryLeft_Ang,     leftAngleIn,             "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(firstCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(firstCluster.BndryRight_Ang,    rightAngleIn,            "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(firstCluster.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(firstCluster.ClosestObj_Dist,   distanceNear,            "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(firstCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  /* Setup second cluster */
  COU_SET_FMT(secondCluster.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "Set second cluster's assignment");
  COU_SET_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(secondCluster.ClosestObj_Dist,   distance,                 "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  /* Call FUT */
  COU_CALL(HLAFMatrixGFA_MergeVC(&firstCluster, &secondCluster), "Call of function under test");

  /* Check outcome */
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Check second cluster's left angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's left angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Check second cluster's right angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's right angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Check second cluster's distance");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ,  COU_FMT_UINT, "Check second cluster's distance status");


  /* case 07: first cluster is within second cluster */
  /* Setup first cluster */
  COU_SET_FMT(firstCluster.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "Set first cluster's assignment");
  COU_SET_FMT(firstCluster.BndryLeft_Ang,     leftAngleIn,             "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(firstCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(firstCluster.BndryRight_Ang,    rightAngleIn,            "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(firstCluster.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(firstCluster.ClosestObj_Dist,   distance,                "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(firstCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  /* Setup second cluster */
  COU_SET_FMT(secondCluster.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "Set second cluster's assignment");
  COU_SET_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  /* Call FUT */
  COU_CALL(HLAFMatrixGFA_MergeVC(&firstCluster, &secondCluster), "Call of function under test");

  /* Check outcome */
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Ang,     leftAngle,                "%.4f",       "Check second cluster's left angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's left angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Check second cluster's right angle");
  COU_ASSERT_EQUAL_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's right angle status");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Dist,   distanceNear,             "%.4f",       "Check second cluster's distance");
  COU_ASSERT_EQUAL_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check second cluster's distance status");
}

/** \test
 *  \description
 *     Test the function to calculate a possible overlap between two vehicle clusters \n
 *     Only test cases where no overlap can be calculated.
 *     Calls function HLAFMatrixGFA_GetOverlapVC2VC() \n
 *  \precondition
 *     case 01: two irregular vehicle clusters \n
 *     case 02: two valid vehicle clusters are checked, no overlap possible \n
 *     case 03: like case two but switched \n
 *  \result
 *     case 01: indicator that no overlap can be determined is returned \n
 *     case 02: a valid angle is returned \n
 *     case 03: a valid angle is returned \n
 */
TEST_MatrixGFA_GetOverlapVC2VC(MatrixGFA_GetOverlapVC2VC, "Test the functionality to calculate the overlap of two vehicle clusters")
{
  const float32 leftAngle    = 0.1745f;
  const float32 leftAngleIn  = 0.1735f;
  const float32 rightAngleIn = 0.1725f;
  const float32 rightAngle   = 0.1715f;

  const float32 distance     = 150.00f;
  const float32 distanceNear = 100.00f;

  const t_MatrixParameters*  pParameter;
  const t_MatrixParametersClusterVeh2GFA* pClusterPar;
  HLAFMatrixGFA_VehClusterData_t firstCluster, secondCluster;

  float32 resultAngle;

  /* initialize clusters */
  memset(&firstCluster, 0u, sizeof(firstCluster));
  memset(&secondCluster, 0u, sizeof(secondCluster));

  /* create simulation data */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");
  COU_SET_FMT(pClusterPar, &(pParameter->ClusterVeh2GFA), COU_FMT_PTR, "Get pointer to vehicle cluster parameter");

  /* case 01: two irregular vehicle clusters */
  COU_SET_FMT(resultAngle, HLAFMatrixGFA_GetOverlapVC2VC(pClusterPar, &firstCluster, &secondCluster), "%.4f", "Get resulting angle");

  /* check result */
  COU_ASSERT_EQUAL_FMT(resultAngle, CML_Deg2Rad(90.0f), "%.4f", "No overlap is possible to be calculated");


  /* case 02: two valid vehicle clusters are checked, no overlap possible */
  /* Setup first cluster */
  COU_SET_FMT(firstCluster.Assignment_VC2GFA, 0u,                      COU_FMT_UINT, "Set first cluster's assignment");
  COU_SET_FMT(firstCluster.BndryLeft_Ang,     leftAngle,               "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(firstCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(firstCluster.BndryRight_Ang,    leftAngleIn,             "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(firstCluster.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(firstCluster.ClosestObj_Dist,   distanceNear,            "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(firstCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  /* Setup second cluster */
  COU_SET_FMT(secondCluster.Assignment_VC2GFA, 0u,                       COU_FMT_UINT, "Set second cluster's assignment");
  COU_SET_FMT(secondCluster.BndryLeft_Ang,     rightAngleIn,             "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(secondCluster.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(secondCluster.BndryRight_Ang,    rightAngle,               "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(secondCluster.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(secondCluster.ClosestObj_Dist,   distance,                 "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(secondCluster.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  COU_SET_FMT(resultAngle, HLAFMatrixGFA_GetOverlapVC2VC(pClusterPar, &firstCluster, &secondCluster), "%.4f", "Get resulting angle");

  /* check result */
  COU_ASSERT_NOT_EQUAL_FMT(resultAngle, CML_Deg2Rad(90.0f), "%.4f", "No overlap is indicated");

  /* case 03: check other way around */
  COU_SET_FMT(resultAngle, HLAFMatrixGFA_GetOverlapVC2VC(pClusterPar, &secondCluster, &firstCluster), "%.4f", "Get resulting angle");

  /* check result */
  COU_ASSERT_NOT_EQUAL_FMT(resultAngle, CML_Deg2Rad(90.0f), "%.4f", "No overlap is indicated");
}

/** \test
 *  \description
 *     Test the function to reduce all vehicle clusters to the max number of GFAs \n
 *     Only check the reduction functionality with the example from three to two GFAs \n
 *     \n
 *     Calls the function GetMatrixParameters() to get the internal parameters \n
 *     and the function under test HLAFMatrixGFA_ReduceVC2MaxNumGFA() \n
 *  \precondition
 *     Three vehicle clusters each with two valid objects, associated to three GFAs \n
 *  \result
 *     The vehicle clusters will be sorted into two GFAs. \n
 */
TEST_MatrixGFA_ReduceVC2MaxNumGFA(MatrixGFA_ReduceVC2MaxNumGFA, "Test the functionality to reduce all vehicle clusters to the max number of GFAs")
{
  const float32 leftAngle    = 0.1745f;
  const float32 leftAngleDel = 0.1740f;
  const float32 leftAngleIn  = 0.1735f;
  const float32 rightAngleIn = 0.1725f;
  const float32 rightAngle   = 0.1715f;

  const float32 distance     = 150.00f;
  const float32 distanceNear = 100.00f;

  const uint32 desiredNumber = 2u;

  const t_MatrixParameters*  pParameter;

  HLAFMatrixGFA_VehCluster_t testClusters;
  HLAFMatrixData_t  testData;

  uint8 objCnt;

  /* initialize test cluster and data */
  memset(&testClusters, 0u, sizeof(testClusters));
  memset(&testData, 0u, sizeof(testData));

  /* create simulation data */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");

  /* set up three vehicle clusters */
  COU_SET_FMT(testClusters.nVC_Max, desiredNumber + 1u, COU_FMT_UINT, "Set up number of vehicle clusters");

  /* first vehicle cluster with two objects */
  COU_SET_FMT(testClusters.VC[0].BndryLeft_Ang,     leftAngle,               "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(testClusters.VC[0].BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(testClusters.VC[0].BndryRight_Ang,    leftAngle,               "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(testClusters.VC[0].BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(testClusters.VC[0].ClosestObj_Dist,   distanceNear,            "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(testClusters.VC[0].ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  COU_SET_FMT(testData.Object[0].GFA, 0u, COU_FMT_UINT, "Set first object to be in first GFA/VC");
  COU_SET_FMT(testData.Object[1].GFA, 0u, COU_FMT_UINT, "Set second object to be in first GFA/VC");

  /* second vehicle cluster with two objects */
  COU_SET_FMT(testClusters.VC[1].BndryLeft_Ang,     leftAngleDel,            "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(testClusters.VC[1].BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(testClusters.VC[1].BndryRight_Ang,    leftAngleIn,             "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(testClusters.VC[1].BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(testClusters.VC[1].ClosestObj_Dist,   distance,                "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(testClusters.VC[1].ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  COU_SET_FMT(testData.Object[2].GFA, 1u, COU_FMT_UINT, "Set third object to be in second GFA/VC");
  COU_SET_FMT(testData.Object[3].GFA, 1u, COU_FMT_UINT, "Set fourth object to be in second GFA/VC");

  /* third vehicle cluster with two objects */
  COU_SET_FMT(testClusters.VC[2].BndryLeft_Ang,     rightAngleIn,             "%.4f",       "Set third cluster's left angle");
  COU_SET_FMT(testClusters.VC[2].BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set third cluster's left angle status");
  COU_SET_FMT(testClusters.VC[2].BndryRight_Ang,    rightAngle,               "%.4f",       "Set third cluster's right angle");
  COU_SET_FMT(testClusters.VC[2].BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set third cluster's right angle status");
  COU_SET_FMT(testClusters.VC[2].ClosestObj_Dist,   distanceNear,             "%.4f",       "Set third cluster's distance");
  COU_SET_FMT(testClusters.VC[2].ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set third cluster's distance status");

  COU_SET_FMT(testData.Object[4].GFA, 2u, COU_FMT_UINT, "Set fifth object to be in third GFA/VC");
  COU_SET_FMT(testData.Object[5].GFA, 2u, COU_FMT_UINT, "Set sixth object to be in third GFA/VC");

  /* call FUT */
  COU_CALL(HLAFMatrixGFA_ReduceVC2MaxNumGFA(pParameter, desiredNumber, 6u, &testData, &testClusters), "Call function under test and only allow two vehicle clusters");

  /* check output */
  COU_ASSERT_EQUAL_FMT(testClusters.nVC, desiredNumber, COU_FMT_UINT, "Number of vehicle clusters has been reduced");
}

/** \test
 *  \description
 *     Test the function to assign vehicle clusters to GFAs \n
 *     Calls the function GetMatrixParameters() to get the internal parameters \n
 *     and the function under test HLAFMatrixGFA_AssignVC2GFA() \n
 *  \precondition
 *     Two not associated vehicle clusters, two GFA\n
 *  \result
 *     The two GFAs will each get a vehicle cluster assigned \n
 */
TEST_MatrixGFA_AssignVC2GFA(MatrixGFA_AssignVC2GFA, "Test the functionality to assign vehicle clusters to GFAs")
{
  const float32 leftAngle    = 0.1745f;
  const float32 leftAngleDel = 0.1740f;
  const float32 leftAngleIn  = 0.1735f;
  const float32 rightAngleIn = 0.1725f;
  const float32 rightAngle   = 0.1715f;

  const float32 distance     = 150.00f;
  const float32 distanceNear = 100.00f;

  const t_MatrixParameters*  pParameter;

  HLAFMatrixGFA_VehCluster_t testClusters;
  HLAFMatrixData_t  testData;

  /* initialize test cluster and data */
  memset(&testClusters, 0u, sizeof(testClusters));
  memset(&testData, 0u, sizeof(testData));

  /* create simulation data */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");

  /* set up two vehicle clusters */
  COU_SET_FMT(testClusters.nVC_Max, 2u, COU_FMT_UINT, "Set up number of vehicle clusters");
  COU_SET_FMT(testClusters.Assignment_GFA2VC[0], UI8_T_MAX, COU_FMT_UINT, "Set first cluster's association");
  COU_SET_FMT(testClusters.Assignment_GFA2VC[1], UI8_T_MAX, COU_FMT_UINT, "Set second cluster's association");

  COU_SET_FMT(testData.Matrix.GFA.nGFA, 2u, COU_FMT_UINT, "Set up number of GFAs");
  /* first vehicle cluster and GFA */
  COU_SET_FMT(testClusters.VC[0].BndryLeft_Ang,     leftAngle,               "%.4f",       "Set first cluster's left angle");
  COU_SET_FMT(testClusters.VC[0].BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's left angle status");
  COU_SET_FMT(testClusters.VC[0].BndryRight_Ang,    leftAngle,               "%.4f",       "Set first cluster's right angle");
  COU_SET_FMT(testClusters.VC[0].BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's right angle status");
  COU_SET_FMT(testClusters.VC[0].ClosestObj_Dist,   distanceNear,            "%.4f",       "Set first cluster's distance");
  COU_SET_FMT(testClusters.VC[0].ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first cluster's distance status");

  COU_SET_FMT(testData.Matrix.GFA.GFA[0].Ext.BndryLeft_Ang,     leftAngle,               "%.4f",       "Set first GFA's left angle");
  COU_SET_FMT(testData.Matrix.GFA.GFA[0].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first GFA's left angle status");
  COU_SET_FMT(testData.Matrix.GFA.GFA[0].Ext.BndryRight_Ang,    leftAngle,               "%.4f",       "Set first GFA's right angle");
  COU_SET_FMT(testData.Matrix.GFA.GFA[0].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first GFA's right angle status");
  COU_SET_FMT(testData.Matrix.GFA.GFA[0].Ext.ClosestObj_Dist,   distanceNear,            "%.4f",       "Set first GFA's distance");
  COU_SET_FMT(testData.Matrix.GFA.GFA[0].Ext.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first GFA's distance status");

  /* second vehicle cluster and GFA */
  COU_SET_FMT(testClusters.VC[1].BndryLeft_Ang,     leftAngleDel,             "%.4f",       "Set second cluster's left angle");
  COU_SET_FMT(testClusters.VC[1].BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's left angle status");
  COU_SET_FMT(testClusters.VC[1].BndryRight_Ang,    leftAngleIn,              "%.4f",       "Set second cluster's right angle");
  COU_SET_FMT(testClusters.VC[1].BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's right angle status");
  COU_SET_FMT(testClusters.VC[1].ClosestObj_Dist,   distance,                 "%.4f",       "Set second cluster's distance");
  COU_SET_FMT(testClusters.VC[1].ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second cluster's distance status");

  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Ext.BndryLeft_Ang,     leftAngleDel,             "%.4f",       "Set second GFA's left angle");
  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second GFA's left angle status");
  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Ext.BndryRight_Ang,    leftAngleIn,              "%.4f",       "Set second GFA's right angle");
  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second GFA's right angle status");
  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Ext.ClosestObj_Dist,   distance,                 "%.4f",       "Set second GFA's distance");
  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Ext.ClosestObj_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set second GFA's distance status");

  /* call FUT */
  COU_CALL(HLAFMatrixGFA_AssignVC2GFA(pParameter, &testData, &testClusters), "Call function under test");
  /* check output */

  COU_ASSERT_EQUAL_FMT(testClusters.VC[0].Assignment_VC2GFA, 0u, COU_FMT_UINT, "First VC is associated with first GFA");
  COU_ASSERT_EQUAL_FMT(testClusters.VC[1].Assignment_VC2GFA, 1u, COU_FMT_UINT, "Second VC is associated with second GFA");
}

/** \test
 *  \description
 *     Test the function to assign unused vehicle clusters to free GFAs \n
 *     Only to check missing functionality that has not been covered by earlier tests \n
 *     Calls function HLAFMatrixGFA_AssignUnusedVC2FreeGFA() \n
 *  \precondition
 *     One GFA and one cluster available \n
 *  \result
 *     Call will not change the number of GFAs \n
 */
TEST_MatrixGFA_AssignUnusedVC2FreeGFA(MatrixGFA_AssignUnusedVC2FreeGFA, "Test the functionality to assign unused vehicle clusters to free GFAs")
{
  HLAFMatrixGFA_VehCluster_t testClusters;
  HLAFMatrixData_t  testData;

  /* initialize test cluster and data */
  memset(&testClusters, 0u, sizeof(testClusters));
  memset(&testData, 0u, sizeof(testData));

  COU_SET_FMT(testData.Matrix.GFA.nGFA, 1u, COU_FMT_UINT, "Set up one GFA");
  COU_SET_FMT(testClusters.nVC_Max, 1u, COU_FMT_UINT, "Set up one cluster");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_AssignUnusedVC2FreeGFA(&testData, 1u, &testClusters), "Call function under test");

  /* check output */
  COU_ASSERT_EQUAL_FMT(testData.Matrix.GFA.nGFA, 1u, COU_FMT_UINT, "Number of GFAs has not changed");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_AssignUnusedVC2FreeGFA(&testData, 2u, &testClusters), "Call function under test");

  /* check output */
  COU_ASSERT_EQUAL_FMT(testData.Matrix.GFA.nGFA, 1u, COU_FMT_UINT, "Number of GFAs has not changed");
}

/** \test
 *  \description
 *     Test the function to assign unused vehicle clusters to lost GFAs \n
 *     Calls function HLAFMatrixGFA_AssignUnusedVC2LostGFA() \n
 *  \precondition
 *     One cluster with no association to any GFA \n
 *     Three GFAs with at least two in state "lost" \n
 *  \result
 *     Cluster will be assigned to first available GFA \n
 *     In case all GFAs are not lost, VC will not get assigned to any of them.
 */
TEST_MatrixGFA_AssignUnusedVC2LostGFA(MatrixGFA_AssignUnusedVC2LostGFA, "Test the functionality to assign unused vehicle clusters to lost GFAs")
{
  HLAFMatrixGFA_VehCluster_t testClusters;
  HLAFMatrixData_t  testData;

  /* initialize test cluster and data */
  memset(&testClusters, 0u, sizeof(testClusters));
  memset(&testData, 0u, sizeof(testData));

  /* setup of initial data*/
  COU_SET_FMT(testClusters.nVC_Max,                 1u,                       COU_FMT_UINT, "Set up one cluster");
  COU_SET_FMT(testClusters.VC[0].BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Set up cluster's left boundary state");
  COU_SET_FMT(testClusters.VC[0].Assignment_VC2GFA, UI8_T_MAX,                COU_FMT_UINT, "Set up cluster's GFA assignment");
  COU_SET_FMT(testClusters.Assignment_GFA2VC[0],    0u,                       COU_FMT_UINT, "Set up first GFA2VS assignment");
  COU_SET_FMT(testClusters.Assignment_GFA2VC[1],    UI8_T_MAX,                COU_FMT_UINT, "Set up second GFA2VS assignment");
  COU_SET_FMT(testClusters.Assignment_GFA2VC[2],    UI8_T_MAX,                COU_FMT_UINT, "Set up third GFA2VS assignment");

  COU_SET_FMT(testData.Matrix.GFA.nGFA, 3u, COU_FMT_UINT, "Set up three fake GFAs");
  COU_SET_FMT(testData.Matrix.GFA.GFA[1].Int.TimerNoVeh_s, 1.0f, "%.1f", "Set up third GFA' timerNoVeh");
  COU_SET_FMT(testData.Matrix.GFA.GFA[2].Int.TimerNoVeh_s, 0.1f, "%.1f", "Set up second GFA's timerNoVeh");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_AssignUnusedVC2LostGFA(&testData, &testClusters), "Call function under test");

  /* check output */
  COU_ASSERT_EQUAL_FMT(testClusters.VC[0].Assignment_VC2GFA, 1u, COU_FMT_UINT, "Assignment has been made");
  COU_ASSERT_EQUAL_FMT(testClusters.Assignment_GFA2VC[1], 0u, COU_FMT_UINT, "Assignment has been made");

  /* reset test data set */
  COU_SET_FMT(testClusters.VC[0].Assignment_VC2GFA, UI8_T_MAX, COU_FMT_UINT, "Set up cluster's GFA assignment");
  COU_SET_FMT(testData.Matrix.GFA.nGFA,             0u,        COU_FMT_UINT, "Set up three fake GFAs");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_AssignUnusedVC2LostGFA(&testData, &testClusters), "Call function under test");

  /* check output */
  COU_ASSERT_EQUAL_FMT(testClusters.VC[0].Assignment_VC2GFA, UI8_T_MAX, COU_FMT_UINT, "Assignment has not been changed");
}

/** \test
 *  \description
 *     Test the function to update GFA data\n
 *     Calls function HLAFMatrixGFA_UpdateGFAData() \n
 *  \precondition
 *     case 01: only GFAs with no associations \n
 *     case 02: three objects, first has lower probabilities, second is valid and usable, third has lost cycles \n
 *  \result
 *     case 01: no changes in GFA have happened \n
 *     case 02: GFA one has a left border with unknown object, and a lower and right border with an oncoming object \n
 *     case 03: GFA one has a left border with unknown object, and a lower and right border with a fused object \n
 */
TEST_MatrixGFA_UpdateGFAData(MatrixGFA_UpdateGFAData, "Test the functionality to update GFA data")
{
  const float32 focalLengthY = 1235.1f;
  const t_MatrixParameters*  pParameter;

  /* input data structures */
  HLAFMatrixData_t      matrixDataHelper;
  LSD_LightList_t       lightListHelper;
  LSD_LightObjectList_t lightObjectListHelper;
  /* helper data structures */

  /* initialize input data */
  memset(&matrixDataHelper, 0u, sizeof(matrixDataHelper));

  /* initialize parameter */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");
  COU_CALL(HLACamRotSetData( 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f), "initialize cam rot");

  /* initialize helper data */
  memset(&lightListHelper, 0u, sizeof(lightListHelper));
  memset(&lightObjectListHelper, 0u, sizeof(lightObjectListHelper));

  /* case 01: only GFAs with no associations */
  /* set all GFAs to have no object associated */
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Set invalid light object ID");
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[1].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Set invalid light object ID");
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[2].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Set invalid light object ID");
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[3].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Set invalid light object ID");
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[4].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Set invalid light object ID");

  /* set invalid count of GFAs to test internal limitations */
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.nGFA, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS + 1u, COU_FMT_UINT, "Set invalid count of GFAs");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_UpdateGFAData(&lightObjectListHelper, &lightListHelper, pParameter, focalLengthY, &matrixDataHelper), "Call function under test");

  /* nothing has changed for the GFAs */
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Invalid light object ID still set");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[1].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Invalid light object ID still set");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[2].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Invalid light object ID still set");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[3].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Invalid light object ID still set");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[4].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Invalid light object ID still set");

  /* case 02: three objects, first has lower probabilities, third has lost cycles */
  /* reinitialize input data */
  memset(&matrixDataHelper, 0u, sizeof(matrixDataHelper));

  /* fill external data */
  COU_SET_FMT(HLACamRot.FX, 1235.1f, "%.1f", "Set x dimension of focal length in cam_rot");

  /* set up three objects to use */
  COU_SET_BY_CALL(SetupLightObjectList(&lightObjectListHelper, &lightListHelper, &matrixDataHelper, 3u), "Initialize light objects and light");

  /* radar object */
  lightObjectListHelper.lightObjects[1].general.lightID = 255;

  /* create pairs of lights */

  /* setup one GFA */
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.nGFA, 1u, COU_FMT_UINT, "Set up one GFA");
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Int.ObjID, 1u, COU_FMT_UINT, "Link first object to this GFA");


  /* link the three objects in order 2-1-3 */
  COU_SET_FMT(matrixDataHelper.Object[0].ObjNext,         2u,                                     COU_FMT_UINT, "Link first object to third object");
  COU_SET_FMT(matrixDataHelper.Object[0].LiObjID,         0u,                                     COU_FMT_UINT, "Link first object to first light object via index");
  COU_SET_FMT(matrixDataHelper.Object[0].pLightObject,    &lightObjectListHelper.lightObjects[0], COU_FMT_PTR,  "Link first object to first light object via pointer");
  COU_SET_FMT(matrixDataHelper.Object[0].bIsRelevantOnc,  FALSE,                                  COU_FMT_UINT, "Set first object to be unknown");
  COU_SET_FMT(matrixDataHelper.Object[0].bIsRelevantPrec, FALSE,                                  COU_FMT_UINT, "Set first object to be unknown");
  COU_SET_FMT(matrixDataHelper.Object[0].IntObjPairIdx,   1,                                      COU_FMT_UINT, "Set pair index to second object");

  COU_SET_FMT(matrixDataHelper.Object[1].ObjNext,         0u,                                     COU_FMT_UINT, "Link second object to first object");
  COU_SET_FMT(matrixDataHelper.Object[1].LiObjID,         1u,                                     COU_FMT_UINT, "Link second object to second light object via index");
  COU_SET_FMT(matrixDataHelper.Object[1].pLightObject,    &lightObjectListHelper.lightObjects[1], COU_FMT_PTR,  "Link second object to second light object via pointer");
  COU_SET_FMT(matrixDataHelper.Object[1].bIsRelevantPrec, TRUE,                                   COU_FMT_UINT, "Set second object to be preceding");
  COU_SET_FMT(matrixDataHelper.Object[1].IntObjPairIdx,   0,                                      COU_FMT_UINT, "Set pair index to first object");
  COU_SET_FMT(matrixDataHelper.Object[1].LightSource,     HLA_LIGHT_SOURCE_RADAR,                 COU_FMT_UINT, "Set light source to radar");
  COU_SET_FMT(matrixDataHelper.Object[1].bIsWideVehicle,  TRUE,                                   COU_FMT_UINT, "Object belongs to wide vehicle");

  COU_SET_FMT(matrixDataHelper.Object[2].LiObjID,        1u,                                     COU_FMT_UINT, "Link third object to third light object via index");
  COU_SET_FMT(matrixDataHelper.Object[2].pLightObject,   &lightObjectListHelper.lightObjects[2], COU_FMT_PTR,  "Link third object to third light object via pointer");
  COU_SET_FMT(matrixDataHelper.Object[2].bIsRelevantOnc, TRUE,                                   COU_FMT_UINT, "Set third object to be oncoming");

  /* set up probabilities and lost cycles for the light objects */
  COU_SET_FMT(lightObjectListHelper.lightObjects[0].attributes.probabilityVehicleOncoming,  70u,                                                 COU_FMT_UINT, "Set first light object's oncoming probability");
  COU_SET_FMT(lightObjectListHelper.lightObjects[0].attributes.probabilityVehiclePreceding, 75u,                                                 COU_FMT_UINT, "Set first light object's preceding probability");
  COU_SET_FMT(lightObjectListHelper.lightObjects[2].general.cyclesLost,                     1u,                                                  COU_FMT_UINT, "Set third light object's lost cycles");
  COU_SET_FMT(lightObjectListHelper.lightObjects[2].attributes.statusBits,                  LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT,  COU_FMT_UINT, "Set truck light status bit");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_UpdateGFAData(&lightObjectListHelper, &lightListHelper, pParameter, focalLengthY, &matrixDataHelper), "Call function under test");

  /* check output */
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_UNKNOWN, COU_FMT_UINT, "Check object status of left boundary");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "Check object status of right boundary");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryLower_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Check object status of lower boundary");
  /* light of left border is paired -> mid reliability */
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_MID, COU_FMT_UINT, "Check left dist reliability");
  /* light of right border is not paired -> low reliability */
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryRight_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_LOW, COU_FMT_UINT, "Check right dist reliability");

  /* case 03: three objects, first has lower probabilities, third has lost cycles */
  /* reinitialize input data */
  memset(&matrixDataHelper, 0u, sizeof(matrixDataHelper));

  /* fill external data */
  COU_SET_FMT(HLACamRot.FX, 1235.1f, "%.1f", "Set x dimension of focal length in cam_rot");

  /* set up three objects to use */
  COU_SET_BY_CALL(SetupLightObjectList(&lightObjectListHelper, &lightListHelper, &matrixDataHelper, 3u), "Initialize light objects and light");

  /* radar object */
  lightObjectListHelper.lightObjects[1].general.lightID = 255;

  /* create pairs of lights */

  /* setup one GFA */
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.nGFA, 1u, COU_FMT_UINT, "Set up one GFA");
  COU_SET_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Int.ObjID, 1u, COU_FMT_UINT, "Link first object to this GFA");


  /* link the three objects in order 2-1-3 */
  COU_SET_FMT(matrixDataHelper.Object[0].ObjNext,         2u,                                     COU_FMT_UINT, "Link first object to third object");
  COU_SET_FMT(matrixDataHelper.Object[0].LiObjID,         0u,                                     COU_FMT_UINT, "Link first object to first light object via index");
  COU_SET_FMT(matrixDataHelper.Object[0].pLightObject,    &lightObjectListHelper.lightObjects[0], COU_FMT_PTR,  "Link first object to first light object via pointer");
  COU_SET_FMT(matrixDataHelper.Object[0].bIsRelevantOnc,  FALSE,                                  COU_FMT_UINT, "Set first object to be unknown");
  COU_SET_FMT(matrixDataHelper.Object[0].bIsRelevantPrec, FALSE,                                  COU_FMT_UINT, "Set first object to be unknown");
  COU_SET_FMT(matrixDataHelper.Object[0].IntObjPairIdx,   1,                                      COU_FMT_UINT, "Set pair index to second object");
  COU_SET_FMT(matrixDataHelper.Object[0].FusedObjID,      1,                                      COU_FMT_UINT, "Set FusedObjID");

  COU_SET_FMT(matrixDataHelper.Object[1].ObjNext,         0u,                                     COU_FMT_UINT, "Link second object to first object");
  COU_SET_FMT(matrixDataHelper.Object[1].LiObjID,         1u,                                     COU_FMT_UINT, "Link second object to second light object via index");
  COU_SET_FMT(matrixDataHelper.Object[1].pLightObject,    &lightObjectListHelper.lightObjects[1], COU_FMT_PTR,  "Link second object to second light object via pointer");
  COU_SET_FMT(matrixDataHelper.Object[1].bIsRelevantPrec, TRUE,                                   COU_FMT_UINT, "Set second object to be preceding");
  COU_SET_FMT(matrixDataHelper.Object[1].IntObjPairIdx,   0,                                      COU_FMT_UINT, "Set pair index to first object");
  COU_SET_FMT(matrixDataHelper.Object[1].LightSource,     HLA_LIGHT_SOURCE_RADAR,                 COU_FMT_UINT, "Set light source to radar");
  COU_SET_FMT(matrixDataHelper.Object[1].bIsWideVehicle,  TRUE,                                   COU_FMT_UINT, "Object belongs to wide vehicle");
  COU_SET_FMT(matrixDataHelper.Object[1].FusedObjID,      0u,                                     COU_FMT_UINT, "Set FusedObjID");

  COU_SET_FMT(matrixDataHelper.Object[2].LiObjID,        1u,                                     COU_FMT_UINT, "Link third object to third light object via index");
  COU_SET_FMT(matrixDataHelper.Object[2].pLightObject,   &lightObjectListHelper.lightObjects[2], COU_FMT_PTR,  "Link third object to third light object via pointer");
  COU_SET_FMT(matrixDataHelper.Object[2].bIsRelevantOnc, TRUE,                                   COU_FMT_UINT, "Set third object to be oncoming");
  COU_SET_FMT(matrixDataHelper.Object[2].FusedObjID,     0u,                                     COU_FMT_UINT, "Set FusedObjID");

  /* call function under test */
  COU_CALL(HLAFMatrixGFA_UpdateGFAData(&lightObjectListHelper, &lightListHelper, pParameter, focalLengthY, &matrixDataHelper), "Call function under test");

  /* light of left border is single light -> low reliability */
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryLeft_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_LOW, COU_FMT_UINT, "Check left dist reliability");
  /* light of right border from fused object -> high reliability */
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryRight_DistReliability, RTE_HLA_DISTANCE_RELIABILITY_HIGH, COU_FMT_UINT, "Check right dist reliability");
  COU_ASSERT_EQUAL_FMT(matrixDataHelper.Matrix.GFA.GFA[0].Ext.BndryRight_Dist, matrixDataHelper.Object[0].pLightObject->kinematic.world.x, COU_FMT_UINT, "Check right dist");
}

/** \test
 *  \description
 *     Test the function to delete GFAs \n
 *     Calls the function GetMatrixParameters() to get the internal parameters \n
 *     and the function under test HLAFMatrixGFA_DeleteGFA() \n
 *  \precondition
 *     case 01: two GFAs, first has a time to border and a small lost time not enough to be lost \n
 *     case 02: first GFA has high enough lost time to be deleted \n
 *  \result
 *     case 01: first GFA's existence probability has been reset \n
 *     case 02: first GFA is deleted, second GFA is shifted to first \n
 */
TEST_MatrixGFA_DeleteGFA(MatrixGFA_DeleteGFA, "Test the functionality to delete GFAs")
{
  const t_MatrixParameters*     pParameter;
  HLAFData_t                    functionData;
  HLAFMatrixData_t              matrixData;

  /* initialize input data */
  memset(&functionData, 0u, sizeof(functionData));
  memset(&matrixData, 0u, sizeof(matrixData));

  /* create simulation data */
  /* initialize parameter */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");

  /* set up function data */
  COU_SET_FMT(functionData.DecisionData.TurnOffReason.Reason, 1u, COU_FMT_UINT, "Set active global turn off reason");

  /* case 01: two GFAs, first has a time to border and a small lost time not enough to be lost */
  /* set up matrix data */
  COU_SET_FMT(matrixData.Matrix.GFA.nGFA,             2u,        COU_FMT_UINT, "Set existence of two GFAs");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Int.ObjID, UI8_T_MAX, COU_FMT_UINT, "Set second GFA to be deleted");

  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Ang,     0.14f,                   "%.4f",       "Set first GFA left boundary");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first GFA left boundary status");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Ang,    0.13f,                   "%.4f",       "Set first GFA right boundary");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first GFA right boundary status");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.ClosestObj_Dist,   40.0f,                   "%.4f",       "Set first GFA closest object");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set first GFA closest object status");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Ext.ExistenceProb,     100u,                    COU_FMT_UINT, "Set first GFA existence probability");

  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.BndryLeft_Ang,     0.010f,                  "%.4f",       "Set second GFA left boundary");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.BndryLeft_Status,  RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set second GFA left boundary status");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.BndryRight_Ang,    0.009f,                  "%.4f",       "Set second GFA right boundary");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.BndryRight_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set second GFA right boundary status");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.ClosestObj_Dist,   30.0f,                   "%.4f",       "Set second GFA closest object");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.ClosestObj_Status, RTE_HLAF_OBJSTA_ONC_OBJ, COU_FMT_UINT, "Set second GFA closest object status");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[1].Ext.ExistenceProb,     100u,                    COU_FMT_UINT, "Set second GFA existence probability");

  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Int.TTB18Left_max, 0.3f, "%.4f", "Set first GFA time to border");
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Int.TimerNoVeh_s,  0.1f, "%.4f", "Set first GFA lost time");

  COU_CALL(HLAFMatrixGFA_DeleteGFA(pParameter, &functionData, &matrixData), "Call function under test");

  COU_ASSERT_EQUAL_FMT(matrixData.Matrix.GFA.GFA[0].Ext.ExistenceProb, 0u,   COU_FMT_UINT, "Existence probability of first GFA has been reset");
  COU_ASSERT_EQUAL_FMT(matrixData.Matrix.GFA.GFA[1].Ext.ExistenceProb, 100u, COU_FMT_UINT, "Existence probability of second GFA has not been reset");

  /* case 02: first GFA has high enough lost time to be deleted */
  COU_SET_FMT(matrixData.Matrix.GFA.GFA[0].Int.TimerNoVeh_s,  0.5f, "%.4f", "Set first GFA lost time");

  COU_CALL(HLAFMatrixGFA_DeleteGFA(pParameter, &functionData, &matrixData), "Call function under test");

  COU_ASSERT_EQUAL_FMT(matrixData.Matrix.GFA.nGFA,                     1u,   COU_FMT_UINT, "One GFA has been removed");
  COU_ASSERT_EQUAL_FMT(matrixData.Matrix.GFA.GFA[0].Ext.ExistenceProb, 100u, COU_FMT_UINT, "Existence probability of first GFA is the one of second GFA");
}

/** \test
 *  \description
 *     Test that overlapping VCs are merged
 *     Calls the function HLAFMatrixGFA_MergeOverlappingVC()
 *  \precondition
 *     None
 *  \result
 *     VCs are merged
 */
test_HLAFMatrixGFA_MergeOverlappingVC_VCsOverlapp_VCAreMerged(HLAFMatrixGFA_MergeOverlappingVC_VCsOverlapp_VCAreMerged, "Test that overlapping VCs are merged")
{
  const t_MatrixParameters*     pParameter;
  HLAFMatrixGFA_VehCluster_t    VC;
  HLAFMatrixData_t              matrixData;
  uint8                         numRelObj = 2;

  memset(&matrixData, 0u, sizeof(matrixData));
  memset(&VC, 0u, sizeof(VC));

  /* initialize parameter */
  COU_SET_FMT(pParameter, GetMatrixParameters(), COU_FMT_PTR, "Get pointer to internal matrix parameter");

  /* create two overlapping VC */
  VC.nVC_Max = 2;
  VC.nVC = 2;

  VC.VC[0].BndryLeft_Ang = 0.18f;
  VC.VC[0].BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
  VC.VC[0].BndryRight_Ang = -0.18f;
  VC.VC[0].BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
  VC.VC[0].ClosestObj_Dist = 50.0f;
  VC.VC[0].ClosestObj_Status = RTE_HLAF_OBJSTA_PREC_OBJ;

  VC.VC[1].BndryLeft_Ang = 0.08f;
  VC.VC[1].BndryLeft_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
  VC.VC[1].BndryRight_Ang = -0.28f;
  VC.VC[1].BndryRight_Status = RTE_HLAF_OBJSTA_PREC_OBJ;
  VC.VC[1].ClosestObj_Dist = 60.0f;
  VC.VC[1].ClosestObj_Status = RTE_HLAF_OBJSTA_PREC_OBJ;

  matrixData.Object[0].GFA = 0;
  matrixData.Object[1].GFA = 1;

  /* function call */
  COU_CALL(HLAFMatrixGFA_MergeOverlappingVC(pParameter, numRelObj, &matrixData, &VC), "Call function under test");

  /* check outputs */
  COU_ASSERT_EQUAL_FMT(VC.nVC,                      1u,                      COU_FMT_UINT, "VC were merged");
  COU_ASSERT_EQUAL_FMT(VC.VC[0].BndryLeft_Ang,      0.18f,                   "%.4f",       "correct angle is set");
  COU_ASSERT_EQUAL_FMT(VC.VC[0].BndryRight_Ang,    -0.28f,                   "%.4f",       "correct angle is set");
  COU_ASSERT_EQUAL_FMT(VC.VC[0].BndryLeft_Status,  RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "correct object status is set");
  COU_ASSERT_EQUAL_FMT(VC.VC[0].BndryRight_Status, RTE_HLAF_OBJSTA_PREC_OBJ, COU_FMT_UINT, "correct object status is set");

}


/* --- Local function definitions --- */
static void SetupLightObjectList( LSD_LightObjectList_t*  pObjectList,
                                  LSD_LightList_t*        pLightList,
                                  HLAFMatrixData_t*       pHlafMatrixData,
                                  uint8                   numObjects
                                )
{
  const uint32  xStart          = 120u;
  const uint32  yStart          = 270u;
  const uint32  lightRadius     = 1u;
  const uint32  lightDeltaX     = 20u;
  const uint32  lightDeltaY     = 2u;
  const float32 pixelPerDegree  = 22.0f;
  const float32 startDist       = 100.0f;
  const float32 deltaDist       = 10.0f;
  const uint16  xFOE            = 320u;
  const uint16  yFOE            = 240u;
  const uint16  upperBorder     = 20u;
  const uint8   fullySure       = 100u;
  const float32 timeToBorderOnc = 0.5f;
  const float32 timeToBorderPre = 8.5f;
        uint8   objCnt;
        float32 helperAngle;
        uint16  deltaX;

  /* Set up light object list  */
  COU_SET_FMT(pObjectList->roi.xFOE,    xFOE,         COU_FMT_UINT, "Set x coordinate of FOE");
  COU_SET_FMT(pObjectList->roi.yFOE,    yFOE,         COU_FMT_UINT, "Set y coordinate of FOE");
  COU_SET_FMT(pObjectList->roi.y1,      upperBorder,  COU_FMT_UINT, "Set upper y coordinate of ROI");
  COU_SET_FMT(pObjectList->numObjects,  numObjects,   COU_FMT_UINT, "Set number of objects to %i", numObjects);
  COU_SET_FMT(pLightList->numLights,    numObjects,   COU_FMT_UINT, "Set number of lights to %i", numObjects);

  /* Set up light objects and their lights */
  for (objCnt = 0; objCnt < numObjects; objCnt++)
  {
    deltaX = xStart + (objCnt * lightDeltaX);

    if(   (objCnt > 0)
       && ( (objCnt % 2) == 0)
      )
    {
      deltaX += 20;
    }

    COU_SET_FMT(pLightList->lights[objCnt].x1, deltaX - lightRadius, COU_FMT_UINT, "Set light[%i]'s x1 coordinate", objCnt);
    COU_SET_FMT(pLightList->lights[objCnt].x2, deltaX + lightRadius, COU_FMT_UINT, "Set light[%i]'s x2 coordinate", objCnt);

    /* set general information */
    COU_SET_FMT(pObjectList->lightObjects[objCnt].general.lightObjectID,        objCnt,     COU_FMT_UINT, "Set object[%i]'s ID", objCnt);
    COU_SET_FMT(pObjectList->lightObjects[objCnt].general.lightID,              objCnt,     COU_FMT_UINT, "Set object[%i]'s light ID", objCnt);
    COU_SET_FMT(pObjectList->lightObjects[objCnt].general.lightObjectIDPaired,  UI8_T_MAX,  COU_FMT_UINT, "Set object[%i]'s paired ID", objCnt);
    COU_SET_FMT(pObjectList->lightObjects[objCnt].general.cyclesTraced,         2u,         COU_FMT_UINT, "Set object[%i]'s traced cycles", objCnt);
    COU_SET_FMT(pObjectList->lightObjects[objCnt].general.cyclesLost,           0u,         COU_FMT_UINT, "Set object[%i]'s lost cycles", objCnt);

    /* set camera kinematic information */
    COU_SET_FMT(pObjectList->lightObjects[objCnt].kinematic.camera.x, deltaX, COU_FMT_UINT, "Set object[%i]'s x coordinate in image", objCnt);
    COU_SET_FMT(pObjectList->lightObjects[objCnt].kinematic.camera.y, yStart + (objCnt * lightDeltaY), COU_FMT_UINT, "Set object[%i]'s y coordinate in image", objCnt);

    /* set world kinematic information */
    COU_SET_FMT(pObjectList->lightObjects[objCnt].kinematic.world.x, startDist - (objCnt * deltaDist), "%.6f", "Set object[%i]'s estimated world distance", objCnt);

    /* calculate horizontal angle */
    helperAngle = (float32)(deltaX - xFOE) / pixelPerDegree;
    COU_SET_FMT(pObjectList->lightObjects[objCnt].kinematic.world.horizontalAngle,  CML_Deg2Rad(helperAngle),  "%.6f", "Set object[%i]'s horizontal angle", objCnt);

    /* set direction-depending attributes */
    if( (objCnt % 2) == 0 )
    {
      COU_SET_FMT(pObjectList->lightObjects[objCnt].attributes.probabilityVehicleOncoming,  fullySure,        COU_FMT_UINT, "Set object[%i]'s oncoming probability", objCnt);
      COU_SET_FMT(pObjectList->lightObjects[objCnt].kinematic.timeToHlaBorder,              timeToBorderOnc,  "%.6f",       "Set object[%i]'s time to border", objCnt);
    }
    else
    {
      COU_SET_FMT(pObjectList->lightObjects[objCnt].attributes.probabilityVehiclePreceding, fullySure,        COU_FMT_UINT, "Set object[%i]'s preceding probability", objCnt);
      COU_SET_FMT(pObjectList->lightObjects[objCnt].kinematic.timeToHlaBorder,              timeToBorderPre,  "%.6f",       "Set object[%i]'s time to border", objCnt);
    }
  }

  for (objCnt = 0; objCnt < LSD_LIGHT_OBJECT_LIST_LENGTH; objCnt++)
  {
    pHlafMatrixData->Object[objCnt].ObjNext       = UI8_T_MAX;
    pHlafMatrixData->Object[objCnt].LiObjID       = UI8_T_MAX;
    pHlafMatrixData->Object[objCnt].LiObjIDPair   = UI8_T_MAX;
    pHlafMatrixData->Object[objCnt].IntObjPairIdx = UI8_T_MAX;
    pHlafMatrixData->Object[objCnt].GFA           = UI8_T_MAX;
    pHlafMatrixData->Object[objCnt].EMObjID       = UI8_T_MAX;
    pHlafMatrixData->Object[objCnt].FusedObjID    = UI8_T_MAX;
  }
}

/* list of all test methods of the related suite. */
cou_test_t hlaf_matrixgfa_tests[] = {
  COU_ADD_TEST(MatrixGFA_Init),
  COU_ADD_TEST(MatrixGFA_Main),
  COU_ADD_TEST(MatrixGFA_Main_PreviousGFA),
  COU_ADD_TEST(MatrixGFA_AddObj2VC),
  COU_ADD_TEST(MatrixGFA_MergeVC),
  COU_ADD_TEST(MatrixGFA_GetOverlapVC2VC),
  COU_ADD_TEST(MatrixGFA_ReduceVC2MaxNumGFA),
  COU_ADD_TEST(MatrixGFA_AssignVC2GFA),
  COU_ADD_TEST(MatrixGFA_AssignUnusedVC2FreeGFA),
  COU_ADD_TEST(MatrixGFA_AssignUnusedVC2LostGFA),
  COU_ADD_TEST(MatrixGFA_UpdateGFAData),
  COU_ADD_TEST(MatrixGFA_DeleteGFA),
  COU_ADD_TEST(HLAFMatrixGFA_MergeOverlappingVC_VCsOverlapp_VCAreMerged),
  COU_ADD_TEST_END
};

/**
 * Called by testrunner directly before each of all tests of the suite.
 * When called before the very first test, it will be called after suite_SomeComposite_suiteIdHere_SuiteInitFunc.
 * See http://eportx.auto.contiwan.com/ebswiki/index.php/Courage/HowtoWriteUnitTest for further documentation on test execution sequence.
 */

COU_INIT(HLAFMatrixGFAInit, "Initialize CamRot Module")
{
  //COU_CALL(HLAFMatrixGFA_Init(),"Initialize CamRot Module");
}

cou_suite_t suites[] =
{
   COU_ADD_SUITE(TestSuite_MatrixGFA, hlaf_matrixgfa_tests, HLAFMatrixGFAInit, "Module test for hlaf_matrixgfa.c"),
   COU_ADD_SUITE_END,
};

/* Ensure that this file is only used by Courage */
#endif //__COURAGE_TEST_SWITCH__
