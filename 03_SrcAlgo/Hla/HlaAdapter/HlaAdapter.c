/* ==================[Includes]=============================================== */
#include <Rte_HlaAdapter.h>
#include "HlaAdapter.h"
#include "hla_ext.h"
#include "HLA_ProjectParameters.h"
#include "P_TrajPlanMathDefs.h"

/*****************************************************************************
  Meas Freeze Virtual Addr Define
*****************************************************************************/
#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
#define HLA_MEAS_ADDR_CPARHLA (0xA0040000u)
#define HLA_MEAS_ADDR_BUSINPUT (0xA0041000u)
#define HLA_MEAS_ADDR_RADAROBJ (0xA0042000u)
#define HLA_MEAS_ADDR_BASECTRL (0xA0043000u)
#define HLA_MEAS_ADDR_CBOUTPUT (0xA0044000u)
#define HLA_MEAS_ADDR_GENOBJEC (0xA0045000u)
#define HLA_MEAS_ADDR_LSDENVIR (0xA0047000u)
#define HLA_MEAS_ADDR_LSDLIGHTLIST (0xA0048000u)
#define HLA_MEAS_ADDR_LSTLIGHTOBJ (0xA0049000u)
#define HLA_MEAS_ADDR_MONOCALI (0xA004A000u)
#define HLA_MEAS_ADDR_HEADLIGHT (0xA004B000u)
#define HLA_MEAS_ADDR_ALGOCOMP (0xA004C000u)
#define HLA_MEAS_ADDR_VEHDYN (0xA004D000u)
#define HLA_MEAS_ADDR_VEHSIG (0xA004E000u)
#endif

/*****************************************************************************
  PDO
*****************************************************************************/
#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
#ifdef __PDO__
/****** Hla In ******/
/*! @VADDR: HLA_MEAS_ADDR_CPARHLA @CYCLEID: CycleId_65 */
typedef CPAR_HLAF_Parameter_t CPAR_HLAF_Parameter_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_BUSINPUT @CYCLEID: CycleId_65 */
typedef HLA_BusInputSignals_t HLA_BusInputSignals_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_RADAROBJ @CYCLEID: CycleId_65 */
typedef HLA_RadarObjectList_t HLA_RadarObjectList_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_BASECTRL @CYCLEID: CycleId_65 */
typedef BaseCtrlData_t BaseCtrlData_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_CBOUTPUT @CYCLEID: CycleId_65 */
typedef CB_t_ProvidedOutputs_t CB_t_ProvidedOutputs_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_GENOBJEC @CYCLEID: CycleId_65 */
typedef EM_t_GenObjectList EM_t_GenObjectLisMTS_T;
/*! @VADDR: HLA_MEAS_ADDR_LSDENVIR @CYCLEID: CycleId_65 */
typedef LSD_EnvironmentData_t LSD_EnvironmentData_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_LSDLIGHTLIST @CYCLEID: CycleId_65 */
typedef LSD_LightList_t LSD_LightList_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_LSTLIGHTOBJ @CYCLEID: CycleId_65 */
typedef LSD_LightObjectList_t LSD_LightObjectList_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_MONOCALI @CYCLEID: CycleId_65 */
typedef MonoCalibration_t MonoCalibration_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_VEHDYN @CYCLEID: CycleId_65 */
typedef VehDyn_t VehDyn_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_VEHSIG @CYCLEID: CycleId_65 */
typedef VehSig_t VehSig_Hla_MTS;

/****** Hla Out ******/
/*! @VADDR: HLA_MEAS_ADDR_HEADLIGHT @CYCLEID: CycleId_65 */
typedef RTE_HLAF_HeadlightControl_t RTE_HLAF_HeadlightControl_Hla_MTS;
/*! @VADDR: HLA_MEAS_ADDR_ALGOCOMP @CYCLEID: CycleId_65 */
typedef AlgoCompState_t AlgoCompState_Hla_MTS;
#endif /*__PDO__*/
#endif

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
static Hla_InputSignals_t HlaAdapter_HlaInputSignals;
static Hla_OutputSignals_t HlaAdapter_HlaOutputSignals;
static reqHlaPrtList_t HlaAdapter_reqHlaPrtData;
static proHlaPrtList_t HlaAdapter_proHlaPrtData;
static AS_t_ServiceFuncts HlaAdapter_ServiceFunctionTables;
/*TODO : The sub data element use for Algo in/out*/
static BaseCtrlData_t HlaAdapter_BaseCtrlData;
static CB_t_ProvidedOutputs_t HlaAdapter_CbOutputs;
//static CPAR_HLAF_Parameter_t HlaAdapter_CPar_HlafPar;
static EM_t_GenObjectList HlaAdapter_GenObjectList;
static HLA_BusInputSignals_t HlaAdapter_HlaBusInputSignals;
static HLA_RadarObjectList_t HlaAdapter_HlaRadarObjectList;
static LSD_EnvironmentData_t HlaAdapter_LsdEnvironmentData;
static LSD_LightList_t HlaAdapter_LsdLightList;
static LSD_LightObjectList_t HlaAdapter_LsdLightObjectList;
static MonoCalibration_t HlaAdapter_MonoCalibration;
static VehDyn_t HlaAdapter_VehDyn;
static VehSig_t HlaAdapter_VehSig;
static AlgoCompState_t HlaAdapter_AlgoCompState;
static RTE_HLAF_HeadlightControl_t HlaAdapter_Hlaf_HeadlightControl;
#endif

/*==================[internal function declarations]========================*/
#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
static AS_t_MeasReturn HlaAdapter_Cot_MeasHdlr(const AS_t_MeasInfo *const meas_info, const void *data, AS_t_MeasCallback callback);
#endif
#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
static void HlaAdapter_Mtsi(uint32 VirtAdd, uint8 funcid, pvoid data_p, uint32 length);
static void HlaAdapter_MTSI_FreezeData_Proxy_65_In(void);
static void HlaAdapter_MTSI_FreezeData_Proxy_65_Out(void);
#endif

/*==================[external function definitions]=========================*/
/**
 * \functions HlaAdapter_HlaExec
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#define HlaAdapter_START_SEC_CODE
#include <HlaAdapter_MemMap.h>
FUNC(void, RTE_CODE) HlaAdapter_HlaExec(void)
{
	/*Do nothing*/
}
#define HlaAdapter_STOP_SEC_CODE
#include <HlaAdapter_MemMap.h>
/**
 * \functions HlaAdapter_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#define HlaAdapter_START_SEC_CODE
#include <HlaAdapter_MemMap.h>
FUNC(void, RTE_CODE) HlaAdapter_InitFunction(void)
{
#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
	/*TODO : Clean the variable*/
	(void)memset(&HlaAdapter_reqHlaPrtData, 0, sizeof(reqHlaPrtList_t));
	(void)memset(&HlaAdapter_proHlaPrtData, 0, sizeof(proHlaPrtList_t));
	(void)memset(&HlaAdapter_ServiceFunctionTables, 0, sizeof(AS_t_ServiceFuncts));

	/*TODO : Input variable*/
	HlaAdapter_reqHlaPrtData.pBaseCtrlData = &HlaAdapter_BaseCtrlData;
	HlaAdapter_reqHlaPrtData.pCbOutputs = &HlaAdapter_CbOutputs;
	HlaAdapter_reqHlaPrtData.pCPar_HlafPar = GetProjectParameters();
	HlaAdapter_reqHlaPrtData.pGenObjectList = &HlaAdapter_GenObjectList;
	HlaAdapter_reqHlaPrtData.pHlaBusInputSignals = &HlaAdapter_HlaBusInputSignals;
	HlaAdapter_reqHlaPrtData.pHlaRadarObjectList = &HlaAdapter_HlaRadarObjectList;
	HlaAdapter_reqHlaPrtData.pLsdEnvironmentData = &HlaAdapter_LsdEnvironmentData;
	HlaAdapter_reqHlaPrtData.pLsdLightList = &HlaAdapter_LsdLightList;
	HlaAdapter_reqHlaPrtData.pLsdLightObjectList = &HlaAdapter_LsdLightObjectList;
	HlaAdapter_reqHlaPrtData.pMonoCalibration = &HlaAdapter_MonoCalibration;
	HlaAdapter_reqHlaPrtData.pVehDyn = &HlaAdapter_VehDyn;
	HlaAdapter_reqHlaPrtData.pVehSig = &HlaAdapter_VehSig;

	/*TODO : Output variable*/
	HlaAdapter_proHlaPrtData.pAlgoCompState = &HlaAdapter_AlgoCompState;
	HlaAdapter_proHlaPrtData.pHlaf_HeadlightControl = &HlaAdapter_Hlaf_HeadlightControl;

	/*TODO : Service function*/
	HlaAdapter_ServiceFunctionTables.pfMeasFreeze = HlaAdapter_Cot_MeasHdlr;
#endif
}
#define HlaAdapter_STOP_SEC_CODE
#include <HlaAdapter_MemMap.h>
/**
 * \functions HlaAdapter_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#define HlaAdapter_START_SEC_CODE
#include <HlaAdapter_MemMap.h>
FUNC(void, RTE_CODE) HlaAdapter_MainFunction(void)
{
#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
	sint64 time_stamp = 0;

	(void)Time_GetTimeStampMs(&time_stamp);

	(void)Rte_Read_RP_Fcu_VehSig_VehSig(&HlaAdapter_VehSig);

	(void)Rte_Read_RP_Fcu_HlaInputData_Hla_InputSignals_t(&HlaAdapter_HlaInputSignals);

	HlaAdapter_BaseCtrlData.uiVersionNumber = BASE_CTRL_DATA_INTFVER;
	HlaAdapter_BaseCtrlData.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_BaseCtrlData.sSigHeader.uiCycleCounter++;
	HlaAdapter_BaseCtrlData.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_BaseCtrlData.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
	HlaAdapter_BaseCtrlData.eOpMode = 0X04; /*BASE_OM_RUN*/

	HlaAdapter_CbOutputs.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
	HlaAdapter_CbOutputs.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_CbOutputs.sSigHeader.uiCycleCounter++;
	HlaAdapter_CbOutputs.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_CbOutputs.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
	HlaAdapter_CbOutputs.ui8_WeatherCondition = HlaAdapter_HlaInputSignals.u8_WeatherCondition;

	HlaAdapter_GenObjectList.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
	HlaAdapter_GenObjectList.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_GenObjectList.sSigHeader.uiCycleCounter++;
	HlaAdapter_GenObjectList.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_GenObjectList.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

	HlaAdapter_HlaBusInputSignals.uiVersionNumber = HLA_BUS_INPUT_SIGNALS_INTFVER;
	HlaAdapter_HlaBusInputSignals.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_HlaBusInputSignals.sSigHeader.uiCycleCounter++;
	HlaAdapter_HlaBusInputSignals.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_HlaBusInputSignals.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
	HlaAdapter_HlaBusInputSignals.headLightState = HlaAdapter_HlaInputSignals.u8_headLightState;
	HlaAdapter_HlaBusInputSignals.hlaRequest = HlaAdapter_HlaInputSignals.u8_hlaRequest;

	HlaAdapter_HlaRadarObjectList.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
	HlaAdapter_HlaRadarObjectList.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_HlaRadarObjectList.sSigHeader.uiCycleCounter++;
	HlaAdapter_HlaRadarObjectList.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_HlaRadarObjectList.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

	HlaAdapter_LsdEnvironmentData.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
	HlaAdapter_LsdEnvironmentData.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_LsdEnvironmentData.sSigHeader.uiCycleCounter++;
	HlaAdapter_LsdEnvironmentData.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_LsdEnvironmentData.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
	HlaAdapter_LsdEnvironmentData.brightnessState = RTE_HLAR_BRT_NIGHT;

	HlaAdapter_LsdLightList.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
	HlaAdapter_LsdLightList.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_LsdLightList.sSigHeader.uiCycleCounter++;
	HlaAdapter_LsdLightList.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_LsdLightList.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

	HlaAdapter_LsdLightObjectList.uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
	HlaAdapter_LsdLightObjectList.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_LsdLightObjectList.sSigHeader.uiCycleCounter++;
	HlaAdapter_LsdLightObjectList.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_LsdLightObjectList.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

	HlaAdapter_MonoCalibration.uiVersionNumber = MONO_CALIBRATION_INTFVER;
	HlaAdapter_MonoCalibration.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_MonoCalibration.sSigHeader.uiCycleCounter++;
	HlaAdapter_MonoCalibration.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_MonoCalibration.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

	HlaAdapter_VehDyn.uiVersionNumber = BSW_VEH_SIG_INTFVER;
	HlaAdapter_VehDyn.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_VehDyn.sSigHeader.uiCycleCounter++;
	HlaAdapter_VehDyn.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_VehDyn.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

	HlaAdapter_VehSig.uiVersionNumber = BSW_VEH_SIG_INTFVER;
	HlaAdapter_VehSig.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	HlaAdapter_VehSig.sSigHeader.uiCycleCounter++;
	HlaAdapter_VehSig.sSigHeader.uiMeasurementCounter++;
	HlaAdapter_VehSig.sSigHeader.eSigStatus = AL_SIG_STATE_OK;

#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
	(void)MTSI_DriverStartTaskCycle(65);
	HlaAdapter_MTSI_FreezeData_Proxy_65_In();
#endif

	(void)HlaExec(&HlaAdapter_reqHlaPrtData, &HlaAdapter_proHlaPrtData, &HlaAdapter_ServiceFunctionTables);

#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
	HlaAdapter_MTSI_FreezeData_Proxy_65_Out();
#endif

	HlaAdapter_HlaOutputSignals.u16_HighBeamState = HlaAdapter_Hlaf_HeadlightControl.Matrix.HighBeamState;
	HlaAdapter_HlaOutputSignals.u16_TurnOffReason = HlaAdapter_Hlaf_HeadlightControl.Matrix.TurnOffReason;
	HlaAdapter_HlaOutputSignals.u8_hlaFunctionStatus = HlaAdapter_Hlaf_HeadlightControl.hlaFunctionStatus;

	(void)Rte_Write_PP_HlaAdapter_OutputData_Hla_OutputSignals_t(&HlaAdapter_HlaOutputSignals);

#endif
}
#define HlaAdapter_STOP_SEC_CODE
#include <HlaAdapter_MemMap.h>
/*==================[internal function definitions]=========================*/

/**
 * \functions HlaAdapter_Cot_MeasHdlr
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
static AS_t_MeasReturn HlaAdapter_Cot_MeasHdlr(const AS_t_MeasInfo *const meas_info, const void *data, AS_t_MeasCallback callback)
{
	(void)MEASFreezeDataMTS(meas_info, data, NULL_PTR);
	return 0;
}
#endif

/**
 * \functions HlaAdapter_Mtsi
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
static void HlaAdapter_Mtsi(uint32 VirtAdd, uint8 funcid, pvoid data_p, uint32 length)
{
	AS_t_MeasInfo meas_info;
	meas_info.VirtualAddress = VirtAdd;
	meas_info.Length = length;
	meas_info.FuncID = funcid;
	(void)MEASFreezeDataMTS(&meas_info, data_p, NULL_PTR);
}
#endif

/**
 * \functions HlaAdapter_MTSI_FreezeData_Proxy_65_In
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
static void HlaAdapter_MTSI_FreezeData_Proxy_65_In(void)
{
	/*TODO: Change API as RTE Port/Interface*/
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_CPARHLA, 65, &HlaAdapter_CPar_HlafPar, sizeof(HlaAdapter_CPar_HlafPar));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_BUSINPUT, 65, &HlaAdapter_HlaBusInputSignals, sizeof(HlaAdapter_HlaBusInputSignals));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_RADAROBJ, 65, &HlaAdapter_HlaRadarObjectList, sizeof(HlaAdapter_HlaRadarObjectList));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_BASECTRL, 65, &HlaAdapter_BaseCtrlData, sizeof(HlaAdapter_BaseCtrlData));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_CBOUTPUT, 65, &HlaAdapter_CbOutputs, sizeof(HlaAdapter_CbOutputs));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_GENOBJEC, 65, &HlaAdapter_GenObjectList, sizeof(HlaAdapter_GenObjectList));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_LSDENVIR, 65, &HlaAdapter_LsdEnvironmentData, sizeof(HlaAdapter_LsdEnvironmentData));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_LSDLIGHTLIST, 65, &HlaAdapter_LsdLightList, sizeof(HlaAdapter_LsdLightList));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_LSTLIGHTOBJ, 65, &HlaAdapter_LsdLightObjectList, sizeof(HlaAdapter_LsdLightObjectList));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_MONOCALI, 65, &HlaAdapter_MonoCalibration, sizeof(HlaAdapter_MonoCalibration));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_VEHDYN, 65, &HlaAdapter_VehDyn, sizeof(HlaAdapter_VehDyn));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_VEHSIG, 65, &HlaAdapter_VehSig, sizeof(HlaAdapter_VehSig));
}
#endif

/**
 * \functions HlaAdapter_MTSI_FreezeData_Proxy_65_Out
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
#if (DBG_HLAADAPTER_MEASFREEZE_ENABLE == STD_ON)
static void HlaAdapter_MTSI_FreezeData_Proxy_65_Out(void)
{
	/*TODO: Change API as RTE Port/Interface*/
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_HEADLIGHT, 65, &HlaAdapter_Hlaf_HeadlightControl, sizeof(HlaAdapter_Hlaf_HeadlightControl));
	HlaAdapter_Mtsi(HLA_MEAS_ADDR_ALGOCOMP, 65, &HlaAdapter_AlgoCompState, sizeof(HlaAdapter_AlgoCompState));
}
#endif
