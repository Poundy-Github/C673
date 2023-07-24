/* Ensure that this file is only used by Courage */
#ifdef __COURAGE_TEST_SWITCH__

#include "mockup_services.h"

// Define global variables
reqHlaPrtList_t              ReqPorts;
proHlaPrtList_t              ProPorts;
AS_t_ServiceFuncts           Services;

BaseCtrlData_t               BaseCtrlData;
AbdOutputData_t              AbdOutputData;
CPAR_HLAF_Parameter_t        CPar_HlafPar;
HLA_BusInputSignals_t        HlaBusInputSignals;
HLA_RadarObjectList_t        HlaRadarObjectList;
LSD_EnvironmentData_t        LsdEnvironmentData;
LSD_LightList_t              LsdLightList;
LSD_LightObjectList_t        LsdLightObjectList;
CB_t_ProvidedOutputs_t       Blockage;
EM_t_GenObjectList           EMObjectsList;
LdOutputData_t               LDOut;
MonoCalibration_t            MonoCalibration;
VehDyn_t                     VDYData;
VehSig_t                     VehSig;

AlgoCompState_t              AlgoCompState;
RTE_HLAF_HeadlightControl_t  HeadlightControl;

t_MockupDemStack             DemStack;
uint8                        DemStackFreeIndex;

// Unusual floats
const float32 f_NAN = 0.0f/0.0f;
const float32 f_INF = 1.0f/0.0f;
// Mockup functions for algo services
static sint32 Mockup_RTAAlgoServiceAddEvent(const AS_t_RtaEventType RtaEvtType, const uint8 u_IdGlobal, const uint8 u_IdLocal, const uint8 u_OptData);
static AS_t_MeasErrors Mockup_MeasStartFuncCycle(const AS_t_MeasFuncID ID);
static AS_t_MeasReturn Mockup_MeasHdlr(const AS_t_MeasInfo * const MeasInf, const void * In, AS_t_MeasCallback MeasIn);
static AS_t_Dem_ReturnType Mockup_Dem_SetEventStatus(const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus);
static AS_t_Dem_ReturnType Mockup_Dem_SetEventStatusPreExtData (const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus,  const uint8* const p_Dem_pui8_PreExtData, uint8 u_Dem_PreExtDataSize);

// Functions definition
void Mockup_InitGlobVars(void)
{
  /* Clear memory */
  memset(&ReqPorts,           TEST_MOCKUP_INIT_BYTE, sizeof(ReqPorts));
  memset(&BaseCtrlData,       TEST_MOCKUP_INIT_BYTE, sizeof(BaseCtrlData));
  memset(&CPar_HlafPar,       TEST_MOCKUP_INIT_BYTE, sizeof(CPar_HlafPar));
  memset(&HlaBusInputSignals, TEST_MOCKUP_INIT_BYTE, sizeof(HlaBusInputSignals));
  memset(&HlaRadarObjectList, TEST_MOCKUP_INIT_BYTE, sizeof(HlaRadarObjectList));
  memset(&LsdEnvironmentData, TEST_MOCKUP_INIT_BYTE, sizeof(LsdEnvironmentData));
  memset(&LsdLightList,       TEST_MOCKUP_INIT_BYTE, sizeof(LsdLightList));
  memset(&LsdLightObjectList, TEST_MOCKUP_INIT_BYTE, sizeof(LsdLightObjectList));
  memset(&Blockage,           TEST_MOCKUP_INIT_BYTE, sizeof(Blockage));
  memset(&EMObjectsList,      TEST_MOCKUP_INIT_BYTE, sizeof(EMObjectsList));
  memset(&MonoCalibration,    TEST_MOCKUP_INIT_BYTE, sizeof(MonoCalibration));
  memset(&VDYData,            TEST_MOCKUP_INIT_BYTE, sizeof(VDYData));
  memset(&VehSig,             TEST_MOCKUP_INIT_BYTE, sizeof(VehSig));

  memset(&ProPorts,           TEST_MOCKUP_INIT_BYTE, sizeof(ProPorts));
  memset(&AlgoCompState,      TEST_MOCKUP_INIT_BYTE, sizeof(AlgoCompState));
  memset(&HeadlightControl,   TEST_MOCKUP_INIT_BYTE, sizeof(HeadlightControl));

  memset(&Services,           TEST_MOCKUP_INIT_BYTE, sizeof(Services));
  memset(&DemStack,           TEST_MOCKUP_INIT_BYTE, sizeof(DemStack));
  DemStackFreeIndex = 0u;

  /* Link buffers */
  ReqPorts.pBaseCtrlData        = &BaseCtrlData;
  ReqPorts.pCPar_HlafPar        = &CPar_HlafPar;
  ReqPorts.pHlaBusInputSignals  = &HlaBusInputSignals;
  ReqPorts.pHlaRadarObjectList  = &HlaRadarObjectList;
  ReqPorts.pLsdEnvironmentData  = &LsdEnvironmentData;
  ReqPorts.pLsdLightList        = &LsdLightList;
  ReqPorts.pLsdLightObjectList  = &LsdLightObjectList;
  ReqPorts.pCbOutputs           = &Blockage;
  ReqPorts.pGenObjectList       = &EMObjectsList;
  ReqPorts.pMonoCalibration     = &MonoCalibration;
  ReqPorts.pVehDyn              = &VDYData;
  ReqPorts.pVehSig              = &VehSig;

  ProPorts.pAlgoCompState         = &AlgoCompState;
  ProPorts.pHlaf_HeadlightControl = &HeadlightControl;

  Services.pfRTAAlgoServiceAddEvent       = Mockup_RTAAlgoServiceAddEvent;
  Services.pfMeasStartFuncCycle           = Mockup_MeasStartFuncCycle;
  Services.pfMeasFreeze                   = Mockup_MeasHdlr;
  Services.pfDem_SetEventStatus           = Mockup_Dem_SetEventStatus;
  Services.pfDem_SetEventStatusPreExtData = Mockup_Dem_SetEventStatusPreExtData;
}

// Mockup functions for algo services
static sint32 Mockup_RTAAlgoServiceAddEvent(const AS_t_RtaEventType RtaEvtType, const uint8 u_IdGlobal, const uint8 u_IdLocal, const uint8 u_OptData)
{
  return 0;
}

static AS_t_MeasErrors Mockup_MeasStartFuncCycle(const AS_t_MeasFuncID ID)
{
  return e_MEAS_OK;
}

static AS_t_MeasReturn Mockup_MeasHdlr(const AS_t_MeasInfo * const MeasInf, const void * In, AS_t_MeasCallback MeasIn)
{
  return MEAS_OK;
}

static AS_t_Dem_ReturnType Mockup_Dem_SetEventStatus(const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus)
{
  /* Store event data */
  DemStack.eventIds[DemStackFreeIndex]    = u_Dem_EventIdRaw;
  DemStack.eventStatus[DemStackFreeIndex] = u_Dem_EventStatus;

  /* Increase index */
  DemStackFreeIndex = CML_Min(DemStackFreeIndex + 1, TEST_MOCKUP_DEM_STACK_SIZE - 1);

  return 0u;
}

static AS_t_Dem_ReturnType Mockup_Dem_SetEventStatusPreExtData (const AS_t_Dem_EventIDType u_Dem_EventIdRaw, const AS_t_Dem_EventStatusType u_Dem_EventStatus,  const uint8* const p_Dem_pui8_PreExtData, uint8 u_Dem_PreExtDataSize)
{
  /* Store event data */
  DemStack.eventIds[DemStackFreeIndex]    = u_Dem_EventIdRaw;
  DemStack.eventStatus[DemStackFreeIndex] = u_Dem_EventStatus;
  memcpy(DemStack.eventData[DemStackFreeIndex], p_Dem_pui8_PreExtData, CML_Min(u_Dem_PreExtDataSize, TEST_MOCKUP_DEM_DATA_SIZE));

  /* Increase index */
  DemStackFreeIndex = CML_Min(DemStackFreeIndex + 1, TEST_MOCKUP_DEM_STACK_SIZE - 1);

  return 0u;
}


#endif /* #ifdef __COURAGE_TEST_SWITCH__ */

