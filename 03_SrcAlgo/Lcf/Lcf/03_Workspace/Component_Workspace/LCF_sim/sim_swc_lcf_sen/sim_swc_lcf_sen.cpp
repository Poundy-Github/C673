/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_swc_lcf_sen.cpp

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision
  
**************************************************************************** */

#include "stdafx.h"
#include "resource.h"
#include "sim_swc_lcf_sen.h"
#include "lcf_ver.h"
#include "lcf_sen_cfg.h"

#include <sstream>


CVersionInfoImpl CreateVersionInfoFromI32(const long version)
{
  return CVersionInfoImpl(
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8) & 0xFF),
    static_cast<unsigned char>(version & 0xFF));
}


#define LCF_SEN_MEAS_ID_SIM_RTA_BUFFER_HIL    0x30523000  /*0x31677000*/ /* CCTEcuMonitor is working correctly only with this address */ //??
#define LCF_SEN_MEAS_ID_ALGO_COMP_STATE_HIL   LCF_SEN_MEAS_ID_ALGO_COMP_STATE   
#define LCF_MEAS_ID_SEN_OUTPUT_HIL            LCF_MEAS_ID_SEN_OUTPUT
#define LCF_MEAS_ID_SEN2VEH_HIL               LCF_MEAS_ID_SEN2VEH


// the client port names
const char* CSimLcfSen::CP_CALCULATIONDONE_SEN      = "CalculationDoneSen";
const char* CSimLcfSen::CP_DISTRIBUTEOUTPUTDATA_SEN = "DistributeOutputDataSen";

// the provide port names
const char* CSimLcfSen::PP_LCF_SEN_OUTPUT            = "pLcfSenOutputData";
const char* CSimLcfSen::PP_LCF_SEN_OUTPUT_TO_VEH     = "pLcfSenOutputToVehData";	
const char* CSimLcfSen::PP_LCF_SEN_ALGO_COMP_STATE   = "pAlgoCompState";
const char* CSimLcfSen::PP_LCF_SEN_DEBUG_DATA   	 = "pLcfSenDebugData";

const DWORD CSimLcfSen::CYCLE_INFO_ARR[1] = { COMP_ID_LCF_SEN };

// our own instance for static methods
CSimLcfSen* CSimLcfSen::s_pInstance = reinterpret_cast<CSimLcfSen*>(0);

CSimLcfSen::CSimLcfSen()
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "../gia_sim/adapter.dll")
, CSimSwcCDL(this, IDR_CDL)
, CSimSwcMeas(this)
, CSimSwcDebugExc ()
, CSimSwcCycleInfo(this, CYCLE_INFO_ARR, sizeof(CYCLE_INFO_ARR)/sizeof(DWORD))
, CSimSwcSynchronization(this)

, m_algoServiceSen(64*1024, 96*1024, this, COMP_ID_LCF_SEN) // assume cache L2: 64k, L3: 96k

//ports
, m_rpBaseCtrlData           (this, "pBaseCtrlData", BaseCtrlData_t(),     BASE_CTRL_DATA_INTFVER)
//, m_rpCamObjectList          (this, "pCamObjectList", EM_t_CamObjectList(), EM_CAM_OBJECT_LIST_INTFVER | EM_CAM_OBJECT_INTFVER)
, m_rpCamObjectList          (this, "pCamObjectList", EM_t_CamObjectList())
//, m_rpGenObjectList          (this, "pGenObjectList", EM_t_GenObjectList(), EM_GEN_OBJECT_LIST_INTFVER | EM_GEN_OBJECT_INTFVER)
, m_rpGenObjectList          (this, "pGenObjectList", EM_t_GenObjectList())
, m_rpLcfSenInputData        (this, "pLcfInputData",  LCF_GenericInputs_t(), LCF_INPUT_INTFVER)
#if defined(LCF_SEN_RPORT_PLCFLADMCIUCTOSOC)
//, m_rpLcfSenLaDmcIucToSoc    (this, "pLcfLaDmcIucToSoc",  LCF_LaDmcIucToSoc_t(), LCF_IUC2SOC_INTFVER)
, m_rpLcfSenLaDmcIucToSoc    (this, "pLcfLaDmcIucToSoc",  LCF_LaDmcIucToSoc_t())
#endif
, m_rpLcfSenInputFromVehData (this, "pLcfSenInputFromVehData", LCF_VehToSen_t(), LCF_VEH2SEN_INTFVER)
, m_rpLcfVehOutputData       (this, "pLcfVehOutputData", LCF_VehGenericOutputs_t(), LCF_VEH_OUTPUT_INTFVER)
, m_rpVehParSen              (this, "pVehPar", VehPar_t(), BSW_VEH_PAR_INTFVER)
, m_rpVehSigSen              (this, "pVehSig", VehSig_t(), BSW_VEH_SIG_INTFVER)
, m_rpVehDynSen              (this, "pVehDyn", VehDyn_t(), VDY_VEH_DYN_INTFVER)
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
//, m_rpHlaRadarObjectList     (this, "pHlaRadarObjectList", HLA_RadarObjectList_t(), HLA_RADAR_OBJECT_LIST_INTFVER)
, m_rpHlaRadarObjectList     (this, "pHlaRadarObjectList", HLA_RadarObjectList_t())
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
//, m_rpCbOutputs              (this, "pCbOutputs", CB_t_ProvidedOutputs_t(), CB_PROVIDED_OUTPUTS_INTFVER)
, m_rpCbOutputs              (this, "pCbOutputs", CB_t_ProvidedOutputs_t())
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
//, m_rpLsdEnvironmentData     (this, "pLsdEnvironmentData", LSD_EnvironmentData_t(), LSD_ENVIRONMENT_DATA_INTFVER)
, m_rpLsdEnvironmentData     (this, "pLsdEnvironmentData", LSD_EnvironmentData_t())
#endif
#ifdef ABD_OUTPUT_DATA_INTFVER
, m_rpAbdOutputDataSen       (this, "pAbdOutputData", AbdOutputData_t(), ABD_OUTPUT_DATA_INTFVER)
#endif
#if (USE_IPC_PARAMS_SIM != 0)//GeGr: Not enough memory on IuC
//, m_rpCParLdp		         (this, "pCParLdp", CPAR_LCF_TunParamsLDP_t(), LCF_TUN_PAR_LDP_INTFVER)
, m_rpCParLdp		         (this, "pCParLdp", CPAR_LCF_TunParamsLDP_t())
//, m_rpCParLka		         (this, "pCParLka", CPAR_LCF_TunParamsLKA_t(), LCF_TUN_PAR_LKA_INTFVER)
, m_rpCParLka		         (this, "pCParLka", CPAR_LCF_TunParamsLKA_t())
#endif
  
{
  // static instance
  s_pInstance = this;
  
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "LcfSen version " << LCFALL_SW_MAIN_VER_NO << "." << LCFALL_SW_SUB_VER_NO << "." << LCFALL_SW_BUG_FIX_LEV << "." << LCFALL_SW_BUG_FIX_LEV2;
  dataTxt   << "LcfSen (LcfSen Simulation Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

#ifdef _DEBUG
  dataTxt.str("Debug ");
#else
  dataTxt.str("Release ");
#endif
  dataTxt << "build at " << __DATE__ << " " << __TIME__;
  AddInternalData("Compiling Info", dataTxt.str().c_str());

  // Create server Ports
  AddServerPort("Reset", Reset, this);
  AddServerPort("Init",  Init,  this);
  AddServerPort("DoitSen",  DoitSen,  this);

  // Create client ports
  AddClientPort(CP_DISTRIBUTEOUTPUTDATA_SEN, NULL, 0);
  AddClientPort(CP_CALCULATIONDONE_SEN,      NULL, 0, PORT_WITH_AUTOCLONE);

  // Create algorithm ports
  SetupPortsSen();

  // reset "received" flags and error counters
  ResetReceivePorts(true);
  
  // HIL-port-buffer:
  memset(&m_hil, 0, sizeof(m_hil));
}

CSimLcfSen::~CSimLcfSen()
{
}

void CSimLcfSen::Reset()
{
  // reset algo to "uninitialized" memory
  // via setting special memory pattern
  //unsigned short* memPtr16 = reinterpret_cast<unsigned short*>(FAMO_GetInstance());
  //for (size_t i = sizeof(FamoInstance_t) / sizeof(unsigned short); i > 0; --i)
  //{
  //  *memPtr16 = 0xCAFE;
  //  ++memPtr16;
  //}
  // reset received flags
  ResetReceivePorts(true);

  // TODO: Place reset stuff
}

void CSimLcfSen::Init()
{ 
  // TODO: Place initialization stuff
}

void CSimLcfSen::SetupPortsSen()
{
  // input ports
  // initialize input port map
  m_receivePortMap.clear();
  
  m_rpBaseCtrlData.setRtePointer(&m_reqSenPortList.pBaseCtrlData);
  m_receivePortMap.push_back(&m_rpBaseCtrlData);
  
  //m_rpCamObjectList.setRtePointer(&m_reqSenPortList.pCamObjectList);
  //m_rpCamObjectList.setupSyncData(&m_rpSyncRefHeader.val().pCamObjectList, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpCamObjectList);
   m_rpCamObjectList.setVersion("EM_t_CamObjectList", CreateVersionInfoFromI32(EM_CAM_OBJECT_LIST_INTFVER));
  
  //m_rpGenObjectList.setRtePointer(&m_reqSenPortList.pGenObjectList);
  //m_rpGenObjectList.setupSyncData(&m_rpSyncRefHeader.val().pGenObjectList, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpGenObjectList);
   m_rpGenObjectList.setVersion("EM_t_GenObjectList", CreateVersionInfoFromI32(EM_GEN_OBJECT_LIST_INTFVER_LCF));
  
  m_rpLcfSenInputData.setRtePointer(&m_reqSenPortList.pLcfInputData);
  m_rpLcfSenInputData.getDefaultValues(true);
  m_rpLcfSenInputData.setupSyncData(&m_rpSyncRefHeader.val().pLcfInputData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfSenInputData);

#if defined(LCF_SEN_RPORT_PLCFLADMCIUCTOSOC)
  //m_rpLcfSenLaDmcIucToSoc.setRtePointer(&m_reqSenPortList.pLcfLaDmcIucToSoc);
  //m_rpLcfSenLaDmcIucToSoc.getDefaultValues(true);
  //m_rpLcfSenLaDmcIucToSoc.setupSyncData(&m_rpSyncRefHeader.val().pLcfLaDmcIucToSoc, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpLcfSenLaDmcIucToSoc);
  m_rpLcfSenLaDmcIucToSoc.setVersion("LCF_LaDmcIucToSoc_t", CreateVersionInfoFromI32(LCF_IUC2SOC_INTFVER));
#endif 
  m_rpLcfSenInputFromVehData.setRtePointer(&m_reqSenPortList.pLcfSenInputFromVehData);
  m_rpLcfSenInputFromVehData.setupSyncData(&m_rpSyncRefHeader.val().pLcfSenInputFromVehData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfSenInputFromVehData);
  
  m_rpLcfVehOutputData.setRtePointer(&m_reqSenPortList.pLcfVehOutputData);
  m_rpLcfVehOutputData.setupSyncData(&m_rpSyncRefHeader.val().pLcfVehOutputData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfVehOutputData);
  
  m_rpVehParSen.setRtePointer(&m_reqSenPortList.pVehPar);
  m_rpVehParSen.setupSyncData(&m_rpSyncRefHeader.val().pVehPar, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVehParSen);
  
  m_rpVehSigSen.setRtePointer(&m_reqSenPortList.pVehSig);
  m_rpVehSigSen.setupSyncData(&m_rpSyncRefHeader.val().pVehSig, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVehSigSen);
  
  m_rpVehDynSen.setRtePointer(&m_reqSenPortList.pVehDyn);
  m_rpVehDynSen.setupSyncData(&m_rpSyncRefHeader.val().pVehDyn, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVehDynSen);  
  
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
  //m_rpHlaRadarObjectList.setRtePointer(&m_reqSenPortList.pHlaRadarObjectList);
  //m_rpHlaRadarObjectList.setupSyncData(&m_rpSyncRefHeader.val().pHlaRadarObjectList, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpHlaRadarObjectList);
   m_rpHlaRadarObjectList.setVersion("HLA_RadarObjectList_t", CreateVersionInfoFromI32(HLA_RADAR_OBJECT_LIST_INTFVER));
#endif

#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
  //m_rpCbOutputs.setRtePointer(&m_reqSenPortList.pCbOutputs);
  //m_rpCbOutputs.setupSyncData(&m_rpSyncRefHeader.val().pCbOutputs, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpCbOutputs); 
   m_rpCbOutputs.setVersion("CB_t_ProvidedOutputs_t", CreateVersionInfoFromI32(CB_PROVIDED_OUTPUTS_INTFVER));
#endif

#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)  
  //m_rpLsdEnvironmentData.setRtePointer(&m_reqSenPortList.pLsdEnvironmentData);
  //m_rpLsdEnvironmentData.setupSyncData(&m_rpSyncRefHeader.val().pLsdEnvironmentData, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpLsdEnvironmentData);
   m_rpLsdEnvironmentData.setVersion("LSD_EnvironmentData_t", CreateVersionInfoFromI32(LSD_ENVIRONMENT_DATA_INTFVER));
#endif 
  
#ifdef ABD_OUTPUT_DATA_INTFVER
  m_rpAbdOutputDataSen.setRtePointer(&m_reqSenPortList.pAbdOutputData);
  m_rpAbdOutputDataSen.setupSyncData(&m_rpSyncRefHeader.val().pAbdOutputData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpAbdOutputDataSen);
#endif
#if (USE_IPC_PARAMS_SIM != 0)//GeGr: Not enough memory on IuC
  //m_rpCParLdp.setRtePointer(&m_reqSenPortList.pCParLdp);
  //m_rpCParLdp.setupSyncData(&m_rpSyncRefHeader.val().pCParLdp, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpCParLdp);
  m_rpCParLdp.setVersion("CPAR_LCF_TunParamsLDP_t", CreateVersionInfoFromI32(LCF_TUN_PAR_LDP_INTFVER));

  //m_rpCParLka.setRtePointer(&m_reqSenPortList.pCParLka);
  //m_rpCParLka.setupSyncData(&m_rpSyncRefHeader.val().pCParLka, &m_rpBaseCtrlData.val().sSigHeader);
  //m_receivePortMap.push_back(&m_rpCParLka);
  m_rpCParLka.setVersion("CPAR_LCF_TunParamsLKA_t", CreateVersionInfoFromI32(LCF_TUN_PAR_LKA_INTFVER));
#endif  
  // output ports
  memset(&m_ppLcfSenAlgoCompState, 0, sizeof(m_ppLcfSenAlgoCompState));
  AddProvidePort (PP_LCF_SEN_ALGO_COMP_STATE, simOPAQUE_t, &m_ppLcfSenAlgoCompState, sizeof(m_ppLcfSenAlgoCompState));
  SetPPortVersion(PP_LCF_SEN_ALGO_COMP_STATE, "AlgoCompState_t", CreateVersionInfoFromI32(COMP_STATE_INTFVER));
  m_proSenPortList.pAlgoCompState  = &m_ppLcfSenAlgoCompState;
  
  memset(&m_ppLcfSenOutputData, 0, sizeof(m_ppLcfSenOutputData));
  AddProvidePort(PP_LCF_SEN_OUTPUT, simOPAQUE_t, &m_ppLcfSenOutputData, sizeof(m_ppLcfSenOutputData));
  SetPPortVersion(PP_LCF_SEN_OUTPUT, "LCF_SenGenericOutputs_t", CreateVersionInfoFromI32(LCF_SEN_OUTPUT_INTFVER));
  m_proSenPortList.pLcfSenOutputData  = &m_ppLcfSenOutputData;

  memset(&m_ppLcfSenOutputToVehData, 0, sizeof(m_ppLcfSenOutputToVehData));
  AddProvidePort(PP_LCF_SEN_OUTPUT_TO_VEH, simOPAQUE_t, &m_ppLcfSenOutputToVehData, sizeof(m_ppLcfSenOutputToVehData));
  SetPPortVersion(PP_LCF_SEN_OUTPUT_TO_VEH, "LCF_SenToVeh_t", CreateVersionInfoFromI32(LCF_SEN2VEH_INTFVER));
  m_proSenPortList.pLcfSenOutputToVehData  = &m_ppLcfSenOutputToVehData;  
  
  memset(&m_ppLCF_SenDebugData, 0, sizeof(m_ppLCF_SenDebugData));
  AddProvidePort(PP_LCF_SEN_DEBUG_DATA, simOPAQUE_t, &m_ppLCF_SenDebugData, sizeof(m_ppLCF_SenDebugData));
  //m_proSenPortList.pLcfSenDebugData  = &m_ppLCF_SenDebugData;
  //////////////////////////
  // Begin: HIL support
  //////////////////////////
  AddReceivePort("HIL_UseHIL"             ,  simI32_t, &m_hil.iUseHil,             sizeof(m_hil.iUseHil), 0, NULL, this);
  AddReceivePort("HIL_ProvideHILResults"  ,  simI32_t, &m_hil.iProvideHilResults,  sizeof(m_hil.iProvideHilResults), 0, NULL, this);
  
  // mts2hil:
  AddProvidePort("HIL_mts2hil", simUI8_t, &m_hil.PortBuffer_mts2hil,  sizeof(m_hil.PortBuffer_mts2hil));
  
  // hil2mts:
  AddReceivePort("HIL_hil2mts", simUI8_t, &m_hil.PortBuffer_hil2mts,  sizeof(m_hil.PortBuffer_hil2mts), 0, NULL, this);
  //AddReceivePort("HIL_SyncRef", simUI8_t, &m_hil.PortBuffer_hil_SyncRef,  sizeof(m_hil.PortBuffer_hil_SyncRef), 0, NULL, this);
  //AddReceivePort("HIL_Tlr_SystemInfo", simUI8_t, &m_hil.PortBuffer_hil_SystemInfo,  sizeof(m_hil.PortBuffer_hil_SystemInfo), 0, NULL, this);

  // Client port for HIL:
  AddClientPort("TriggerHIL"                        , NULL      , 0, PORT_WITH_AUTOCLONE);
  //////////////////////////
  // End: HIL support
  //////////////////////////

}

void CSimLcfSen::DoitSen()
{
  // Update uiVersionNumber, eSigStatus and uiTimeStamp with default values 
  // for all const signals in MFC5J3 project

  m_rpCamObjectList.val().uiVersionNumber = EM_CAM_OBJECT_LIST_INTFVER;
  m_rpCamObjectList.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpCamObjectList.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpGenObjectList.val().uiVersionNumber = EM_GEN_OBJECT_LIST_INTFVER_LCF;
  m_rpGenObjectList.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpGenObjectList.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpLcfSenLaDmcIucToSoc.val().uiVersionNumber = LCF_IUC2SOC_INTFVER;
  m_rpLcfSenLaDmcIucToSoc.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpLcfSenLaDmcIucToSoc.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpHlaRadarObjectList.val().uiVersionNumber = HLA_RADAR_OBJECT_LIST_INTFVER;
  m_rpHlaRadarObjectList.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpHlaRadarObjectList.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpCbOutputs.val().uiVersionNumber = CB_PROVIDED_OUTPUTS_INTFVER;
  m_rpCbOutputs.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpCbOutputs.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpLsdEnvironmentData.val().uiVersionNumber = LSD_ENVIRONMENT_DATA_INTFVER;
  m_rpLsdEnvironmentData.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpLsdEnvironmentData.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpCParLdp.val().uiVersionNumber = LCF_TUN_PAR_LDP_INTFVER;
  m_rpCParLdp.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpCParLdp.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;

  m_rpCParLka.val().uiVersionNumber = LCF_TUN_PAR_LKA_INTFVER;
  m_rpCParLka.val().sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_rpCParLka.val().sSigHeader.uiTimeStamp = m_rpBaseCtrlData.val().sSigHeader.uiTimeStamp;


  m_reqSenPortList.pCamObjectList         = &m_rpCamObjectList.val();
  m_reqSenPortList.pGenObjectList         = &m_rpGenObjectList.val();
  m_reqSenPortList.pLcfLaDmcIucToSoc      = &m_rpLcfSenLaDmcIucToSoc.val();
  m_reqSenPortList.pHlaRadarObjectList    = &m_rpHlaRadarObjectList.val();
  m_reqSenPortList.pCbOutputs             = &m_rpCbOutputs.val();
  m_reqSenPortList.pLsdEnvironmentData    = &m_rpLsdEnvironmentData.val();
  m_reqSenPortList.pCParLdp               = &m_rpCParLdp.val();
  m_reqSenPortList.pCParLka               = &m_rpCParLka.val();

  //If more than one call per cycle ensure, that this is called on cycle start
  // Reset RTA buffer
  m_algoServiceSen.rtaNewCycle();
  
  CheckPortsDataReceived();
  
  //If more than one call per cycle ensure, that this is called on cycle start
  //! send cycle start
  MEASSendCycleStartMTS (TASK_ID_LCF_SEN);
  
  /* call algo */
  MainCallSen();
  
  //If more than one call per cycle ensure, that this is really called on cycle end
  //! send cycle end
  MEASSendCycleEndMTS (TASK_ID_LCF_SEN);

  // trigger done port
  TriggerEvent(CP_DISTRIBUTEOUTPUTDATA_SEN, 0, 0);

  // trigger done port
  TriggerEvent(CP_CALCULATIONDONE_SEN, 0, 0);
}

void CSimLcfSen::MainCallSen()
{
  // Pre Process NVM Data

  // Freeze Input - Optional
  
  // Setup FPU
  SimDbgSetupFPU();

  __try
  {

    // Start execution of LcfSen component
	if (0 == m_hil.iUseHil)
    {
		LcfSenExec(&m_reqSenPortList, &m_proSenPortList, &m_algoServiceSen.getServiceFuncts()); //??
	}
	
	TriggerHIL(&m_reqSenPortList, &m_proSenPortList); // EVM-HIL: m_reqSenPortList contains inputs for EVM-HIL,
                                                //          m_proSenPortList contains outputs of simulation (when iProvideHilResults == 0)
                                                //          m_proSenPortList contains outputs of HIL (when iProvideHilResults == 1)
    
  }
  __except (SimDbgEvaluateException(GetExceptionCode(), GetExceptionInformation(), this ))
  {
   	 	// code execution had to be abborted due to unhandled exception 
  }

  // Restore FPU
  SimDbgRestoreFPU();

  /* Post Process NVM Data */
}

CVersionInfoImpl CSimLcfSen::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

void CSimLcfSen::TriggerHIL(const reqLcfSenPrtList_t *reqPorts, const proLcfSenPrtList_t *proPorts)
{
  errno_t ErrorRet = 0;
  if (0 != m_hil.iUseHil)
  {
    if ((0 != reqPorts->pLcfInputData))
    {
      m_hil.PortBuffer_mts2hil.SenIn_LcfInputData = *reqPorts->pLcfInputData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pLcfInputData input port is a zero pointer!");
    }
	
#if defined(LCF_SEN_RPORT_PLCFLADMCIUCTOSOC)
	if ((0 != reqPorts->pLcfLaDmcIucToSoc))
    {
      m_hil.PortBuffer_mts2hil.SenIn_LcfLaDmcIucToSoc = *reqPorts->pLcfLaDmcIucToSoc;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pLcfLaDmcIucToSoc input port is a zero pointer!");
    }
#endif
	if ((0 != reqPorts->pLcfSenInputFromVehData))
    {
      m_hil.PortBuffer_mts2hil.SenIn_LcfSenInputFromVehData = *reqPorts->pLcfSenInputFromVehData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pLcfSenInputFromVehData input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pLcfVehOutputData))
    {
      m_hil.PortBuffer_mts2hil.SenIn_LcfVehOutputData = *reqPorts->pLcfVehOutputData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pLcfVehOutputData input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pCamObjectList))
    {
      m_hil.PortBuffer_mts2hil.SenIn_CamObjectList = *reqPorts->pCamObjectList;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pCamObjectList input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pGenObjectList))
    {
      m_hil.PortBuffer_mts2hil.SenIn_GenObjectList = *reqPorts->pGenObjectList;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pGenObjectList input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVehPar))
    {
      m_hil.PortBuffer_mts2hil.SenIn_VehPar = *reqPorts->pVehPar;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pVehPar input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVehSig))
    {
      m_hil.PortBuffer_mts2hil.SenIn_VehSig = *reqPorts->pVehSig;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pVehSig input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVehDyn))
    {
      m_hil.PortBuffer_mts2hil.SenIn_VehDyn = *reqPorts->pVehDyn;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pVehDyn input port is a zero pointer!");
    }
	
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
	if ((0 != reqPorts->pHlaRadarObjectList))
    {
      m_hil.PortBuffer_mts2hil.SenIn_HlaRadarObjectList = *reqPorts->pHlaRadarObjectList;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pHlaRadarObjectList input port is a zero pointer!");
    }
#endif

#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
	if ((0 != reqPorts->pCbOutputs))
    {
      m_hil.PortBuffer_mts2hil.SenIn_CbOutputs = *reqPorts->pCbOutputs;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pCbOutputs input port is a zero pointer!");
    }
#endif
	
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)	
	if ((0 != reqPorts->pLsdEnvironmentData))
    {
      m_hil.PortBuffer_mts2hil.SenIn_LsdEnvironmentData = *reqPorts->pLsdEnvironmentData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pLsdEnvironmentData input port is a zero pointer!");
    }
#endif
	
#ifdef ABD_OUTPUT_DATA_INTFVER	
	if ((0 != reqPorts->pAbdOutputData))
    {
      m_hil.PortBuffer_mts2hil.SenIn_ABDOutputData = *reqPorts->pAbdOutputData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pAbdOutputData input port is a zero pointer!");
    }
#endif	
#if (USE_IPC_PARAMS_SIM != 0)//GeGr: Not enough memory on IuC
	if ((0 != reqPorts->pCParLdp))
    {
      m_hil.PortBuffer_mts2hil.SenIn_CParLdp = *reqPorts->pCParLdp;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pCParLdp input port is a zero pointer!");
    }
	
	
	if ((0 != reqPorts->pCParLka))
    {
      m_hil.PortBuffer_mts2hil.SenIn_CParLka = *reqPorts->pCParLka;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! ** pCParLka input port is a zero pointer!");
    }
#endif	
	
	
	if (0 != ErrorRet)
    {
      ReportError(err_sev_error, -1, "LCF_SEN: Error copying input data for EVM-HIL! At least one input port has a zero pointer!");
    }

    if (0 != reqPorts->pBaseCtrlData)
    {
      // we need at least the control port...
      m_hil.PortBuffer_mts2hil.SenIn_LcfSenCtrlData = *reqPorts->pBaseCtrlData;

      // Run HIL, only in case of no error:
      TriggerEvent("TriggerHIL",0,0);
    }

    if (0 != m_hil.iProvideHilResults)
    {
      m_hil.PortBuffer_hil2mts.SenOut_LcfAlgoCompState.uiVersionNumber = 123456789;
      *(proPorts->pAlgoCompState)       = m_hil.PortBuffer_hil2mts.SenOut_LcfAlgoCompState;
      *(proPorts->pLcfSenOutputData)       = m_hil.PortBuffer_hil2mts.SenOut_LcfSenOutputData;
	  *(proPorts->pLcfSenOutputToVehData)  = m_hil.PortBuffer_hil2mts.SenOut_LcfSenOutputToVehData;

      // Do hil measfreeze
      MeasFreezeSim( LCF_SEN_MEAS_ID_SIM_RTA_BUFFER_HIL,  (void *)&m_hil.PortBuffer_hil2mts.RtaBuffer,                    sizeof(m_hil.PortBuffer_hil2mts.RtaBuffer));
      MeasFreezeSim( LCF_SEN_MEAS_ID_ALGO_COMP_STATE_HIL, (void *)&m_hil.PortBuffer_hil2mts.SenOut_LcfAlgoCompState,      sizeof(m_hil.PortBuffer_hil2mts.SenOut_LcfAlgoCompState));
      MeasFreezeSim( LCF_MEAS_ID_SEN_OUTPUT_HIL,          (void *)&m_hil.PortBuffer_hil2mts.SenOut_LcfSenOutputData,      sizeof(m_hil.PortBuffer_hil2mts.SenOut_LcfSenOutputData));
      MeasFreezeSim( LCF_MEAS_ID_SEN2VEH_HIL,             (void *)&m_hil.PortBuffer_hil2mts.SenOut_LcfSenOutputToVehData, sizeof(m_hil.PortBuffer_hil2mts.SenOut_LcfSenOutputToVehData));

    }
  }
}

// Meas freeze method for sim data
void CSimLcfSen::MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size)
{
  MEASInfo_t desc;

  desc.VirtualAddress = _vaddr;
  desc.Length         = _size;
  desc.FuncID         = TASK_ID_LCF_SEN;
  desc.FuncChannelID  = static_cast<uint8>(TASK_ID_LCF_SEN);

  (void) MTSMeas(&desc, (void *)_addr, NULL);
}

MEASReturn_t CSimLcfSen::MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback)
{
  if (NULL != s_pInstance)
  {
    // Algorithm specific parameter translation
    SIMMEASInfo_t SimInfo;

    SimInfo.VirtualAddress = pInfo->VirtualAddress;
    SimInfo.Length         = pInfo->Length;
    SimInfo.FuncID         = pInfo->FuncID;
    SimInfo.FuncChannelID  = pInfo->FuncChannelID;
    // pass on to CPP code:
    return static_cast<MEASReturn_t>(s_pInstance->MEASFreezeDataMTS (&SimInfo, pData, Callback));
  }
  return MEAS_OK;
}

