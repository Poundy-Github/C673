/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_swc_lcf_veh.cpp

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision
  
**************************************************************************** */

#include "stdafx.h"
#include "resource.h"
#include "sim_swc_lcf_veh.h"
#include "lcf_ver.h"

#include <sstream>


#define LCF_VEH_MEAS_ID_SIM_RTA_BUFFER_HIL    0x30523000  /*0x31677000*/ /* CCTEcuMonitor is working correctly only with this address */ //??
#define LCF_VEH_MEAS_ID_ALGO_COMP_STATE_HIL   LCF_VEH_MEAS_ID_ALGO_COMP_STATE  
#define LCF_MEAS_ID_VEH_OUTPUT_HIL            LCF_MEAS_ID_VEH_OUTPUT
#define LCF_MEAS_ID_SOC2IUC_HIL               LCF_MEAS_ID_SOC2IUC
#define LCF_MEAS_ID_VEH2SEN_HIL               LCF_MEAS_ID_VEH2SEN
#define LCF_MEAS_ID_LEARNDATA_HIL             LCF_MEAS_ID_LEARNDATA

// the client port names
const char* CSimLcfVeh::CP_CALCULATIONDONE_VEH      = "CalculationDoneVeh";
const char* CSimLcfVeh::CP_DISTRIBUTEOUTPUTDATA_VEH = "DistributeOutputDataVeh";

// the provide port names
const char* CSimLcfVeh::PP_LCF_VEH_OUTPUT            = "pLcfVehOutputData"; 
#if defined(LCF_VEH_PPORT_PLCFLADMCSOCTOIUC)
const char* CSimLcfVeh::PP_LCF_LADMOC_SOCTOIUC_OUTPUT = "pLcfLaDmcSocToIuc";
#endif
const char* CSimLcfVeh::PP_LCF_VEH_OUTPUT_TO_SEN     = "pLcfVehOutputToSenData";
#ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
const char* CSimLcfVeh::PP_LCF_VEH_NVMLEARN_DATA     = "pNvmLcfData";
#endif
const char* CSimLcfVeh::PP_LCF_VEH_ALGO_COMP_STATE   = "pAlgoCompState";

const char* CSimLcfVeh::PP_LCF_VEH_DEBUG_DATA   	 = "pLcfVehDebugData";

const DWORD CSimLcfVeh::CYCLE_INFO_ARR[1] = { COMP_ID_LCF_VEH };

// our own instance for static methods
CSimLcfVeh* CSimLcfVeh::s_pInstance = reinterpret_cast<CSimLcfVeh*>(0);

CSimLcfVeh::CSimLcfVeh()
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "../gia_sim/adapter.dll")
, CSimSwcCDL(this, IDR_CDL)
, CSimSwcMeas(this)
, CSimSwcDebugExc ()
, CSimSwcCycleInfo(this, CYCLE_INFO_ARR, sizeof(CYCLE_INFO_ARR)/sizeof(DWORD))
, CSimSwcSynchronization(this)

, m_algoServiceVeh(64*1024, 96*1024, this, COMP_ID_LCF_VEH) // assume cache L2: 64k, L3: 96k

//ports
, m_rpBaseCtrlData           (this, "pBaseCtrlData", BaseCtrlData_t(),     BASE_CTRL_DATA_INTFVER)
, m_rpLcfVehInputData        (this, "pLcfInputData",  LCF_GenericInputs_t(), LCF_INPUT_INTFVER)
#if defined(LCF_VEH_RPORT_PLCFLADMCIUCTOSOC)
, m_rpLcfVehLaDmcIucToSoc    (this, "pLcfLaDmcIucToSoc",  LCF_LaDmcIucToSoc_t(), LCF_IUC2SOC_INTFVER)
#endif
, m_rpLcfVehInputFromSenData (this, "pLcfVehInputFromSenData", LCF_SenToVeh_t(), LCF_SEN2VEH_INTFVER)
, m_rpLcfSenOutputData       (this, "pLcfSenOutputData", LCF_SenGenericOutputs_t(), LCF_SEN_OUTPUT_INTFVER)
, m_rpVehParVeh              (this, "pVehPar", VehPar_t(), BSW_VEH_PAR_INTFVER)   
, m_rpVehSigVeh              (this, "pVehSig", VehSig_t(), BSW_VEH_SIG_INTFVER)
, m_rpVehDynVeh              (this, "pVehDyn", VehDyn_t(), VDY_VEH_DYN_INTFVER) 
, m_rpVdyOffsetsVeh          (this, "pVdyOffsets", VDYOffsets_t(), VDY_OFFSETS_INTFVER)
#ifdef ABD_OUTPUT_DATA_INTFVER
, m_rpAbdOutputDataVeh        (this, "pAbdOutputData", AbdOutputData_t(), ABD_OUTPUT_DATA_INTFVER) 
#endif
, m_rpCParKmc                (this, "pCParKmc", CPAR_LCF_TunParamsKMC_t(), LCF_TUN_PAR_KMC_INTFVER)
, m_rpCParDmc                (this, "pCParDmc", CPAR_LCF_TunParamsDMC_t(), LCF_TUN_PAR_DMC_INTFVER)
#ifdef LCF_VEH_PPORT_PNVMLCFDATA	//TODO: delete this line in next release
, m_rpNvmLcfDataVeh        (this, "pNvmLcfData", NVM_LcfLearningData_t(), LCF_LEARNDATA_INTFVER) 
#endif
  
{
  // static instance
  s_pInstance = this;
  
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "LcfVeh version " << LCFALL_SW_MAIN_VER_NO << "." << LCFALL_SW_SUB_VER_NO << "." << LCFALL_SW_BUG_FIX_LEV << "." << LCFALL_SW_BUG_FIX_LEV2;
  dataTxt   << "LcfVeh (LcfVeh Simulation Module)";
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
  AddServerPort("DoitVeh",  DoitVeh,  this);

  // Create client ports
  AddClientPort(CP_DISTRIBUTEOUTPUTDATA_VEH, NULL, 0);
  AddClientPort(CP_CALCULATIONDONE_VEH,      NULL, 0, PORT_WITH_AUTOCLONE);

  // Create algorithm ports
  SetupPortsVeh();

  // reset "received" flags and error counters
  ResetReceivePorts(true);
  
  // HIL-port-buffer:
  memset(&m_hil, 0, sizeof(m_hil));
}

CSimLcfVeh::~CSimLcfVeh()
{
}

void CSimLcfVeh::Reset()
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

void CSimLcfVeh::Init()
{ 
  // TODO: Place initialization stuff
}

void CSimLcfVeh::SetupPortsVeh()
{
  // input ports
  // initialize input port map
  m_receivePortMap.clear();
  
  m_rpBaseCtrlData.setRtePointer(&m_reqVehPortList.pBaseCtrlData);
  m_receivePortMap.push_back(&m_rpBaseCtrlData);
  
  m_rpLcfVehInputData.setRtePointer(&m_reqVehPortList.pLcfInputData);
  m_rpLcfVehInputData.getDefaultValues(true);
  m_rpLcfVehInputData.setupSyncData(&m_rpSyncRefHeader.val().pLcfInputData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfVehInputData);
 
#if defined(LCF_VEH_RPORT_PLCFLADMCIUCTOSOC)
  m_rpLcfVehLaDmcIucToSoc.setRtePointer(&m_reqVehPortList.pLcfLaDmcIucToSoc);
  m_rpLcfVehLaDmcIucToSoc.getDefaultValues(true);
  m_rpLcfVehLaDmcIucToSoc.setupSyncData(&m_rpSyncRefHeader.val().pLcfLaDmcIucToSoc, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfVehLaDmcIucToSoc);  
#endif
  
  m_rpLcfVehInputFromSenData.setRtePointer(&m_reqVehPortList.pLcfVehInputFromSenData);
  m_rpLcfVehInputFromSenData.setupSyncData(&m_rpSyncRefHeader.val().pLcfVehInputFromSenData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfVehInputFromSenData);
  
  m_rpLcfSenOutputData.setRtePointer(&m_reqVehPortList.pLcfSenOutputData);
  m_rpLcfSenOutputData.setupSyncData(&m_rpSyncRefHeader.val().pLcfSenOutputData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpLcfSenOutputData);
  
  m_rpVehParVeh.setRtePointer(&m_reqVehPortList.pVehPar);
  m_rpVehParVeh.setupSyncData(&m_rpSyncRefHeader.val().pVehPar, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVehParVeh);
  
  m_rpVehSigVeh.setRtePointer(&m_reqVehPortList.pVehSig);
  m_rpVehSigVeh.setupSyncData(&m_rpSyncRefHeader.val().pVehSig, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVehSigVeh);
  
  m_rpVehDynVeh.setRtePointer(&m_reqVehPortList.pVehDyn);
  m_rpVehDynVeh.setupSyncData(&m_rpSyncRefHeader.val().pVehDyn, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVehDynVeh);  
  
  m_rpVdyOffsetsVeh.setRtePointer(&m_reqVehPortList.pVdyOffsets);
  m_rpVdyOffsetsVeh.setupSyncData(&m_rpSyncRefHeader.val().pVdyOffsets, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpVdyOffsetsVeh);

#ifdef ABD_OUTPUT_DATA_INTFVER
  m_rpAbdOutputDataVeh.setRtePointer(&m_reqVehPortList.pAbdOutputData);
  m_rpAbdOutputDataVeh.setupSyncData(&m_rpSyncRefHeader.val().pAbdOutputData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpAbdOutputDataVeh); 
#endif
  m_rpCParKmc.setRtePointer(&m_reqVehPortList.pCParKmc);
  m_rpCParKmc.setupSyncData(&m_rpSyncRefHeader.val().pCParKmc, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpCParKmc);
  
  m_rpCParDmc.setRtePointer(&m_reqVehPortList.pCParDmc);
  m_rpCParDmc.setupSyncData(&m_rpSyncRefHeader.val().pCParDmc, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpCParDmc);
  
#ifdef LCF_VEH_PPORT_PNVMLCFDATA	//TODO: delete this line in next release
  m_rpNvmLcfDataVeh.setRtePointer(&m_reqVehPortList.pNvmLcfData);
  m_rpNvmLcfDataVeh.setupSyncData(&m_rpSyncRefHeader.val().pNvmLcfData, &m_rpBaseCtrlData.val().sSigHeader);
  m_receivePortMap.push_back(&m_rpNvmLcfDataVeh); 
#endif
  
  
  // output ports
  memset(&m_ppLcfVehAlgoCompState, 0, sizeof(m_ppLcfVehAlgoCompState));
  AddProvidePort (PP_LCF_VEH_ALGO_COMP_STATE, simOPAQUE_t, &m_ppLcfVehAlgoCompState, sizeof(m_ppLcfVehAlgoCompState));
  SetPPortVersion(PP_LCF_VEH_ALGO_COMP_STATE, "AlgoCompState_t", CreateVersionInfoFromI32(COMP_STATE_INTFVER));
  m_proVehPortList.pAlgoCompState  = &m_ppLcfVehAlgoCompState;
  
  memset(&m_ppLcfVehOutputData, 0, sizeof(m_ppLcfVehOutputData));
  AddProvidePort(PP_LCF_VEH_OUTPUT, simOPAQUE_t, &m_ppLcfVehOutputData, sizeof(m_ppLcfVehOutputData));
  SetPPortVersion(PP_LCF_VEH_OUTPUT, "LCF_VehGenericOutputs_t", CreateVersionInfoFromI32(LCF_VEH_OUTPUT_INTFVER));
  m_proVehPortList.pLcfVehOutputData  = &m_ppLcfVehOutputData;

#if defined(LCF_VEH_PPORT_PLCFLADMCSOCTOIUC)
  memset(&m_ppLcfLaDmcSocToIuc, 0, sizeof(m_ppLcfLaDmcSocToIuc));
  AddProvidePort(PP_LCF_LADMOC_SOCTOIUC_OUTPUT, simOPAQUE_t, &m_ppLcfLaDmcSocToIuc, sizeof(m_ppLcfLaDmcSocToIuc));
  SetPPortVersion(PP_LCF_LADMOC_SOCTOIUC_OUTPUT, "LCF_LaDmcSocToIuc_t", CreateVersionInfoFromI32(LCF_SOC2IUC_INTFVER));
  m_proVehPortList.pLcfLaDmcSocToIuc  = &m_ppLcfLaDmcSocToIuc;
#endif

  memset(&m_ppLcfVehOutputToSenData, 0, sizeof(m_ppLcfVehOutputToSenData));
  AddProvidePort(PP_LCF_VEH_OUTPUT_TO_SEN, simOPAQUE_t, &m_ppLcfVehOutputToSenData, sizeof(m_ppLcfVehOutputToSenData));
  SetPPortVersion(PP_LCF_VEH_OUTPUT_TO_SEN, "LCF_VehToSen_t", CreateVersionInfoFromI32(LCF_VEH2SEN_INTFVER));
  m_proVehPortList.pLcfVehOutputToSenData  = &m_ppLcfVehOutputToSenData; 
  
  memset(&m_ppLCF_VehDebugData, 0, sizeof(m_ppLCF_VehDebugData));
  AddProvidePort(PP_LCF_VEH_DEBUG_DATA, simOPAQUE_t, &m_ppLCF_VehDebugData, sizeof(m_ppLCF_VehDebugData));
  //m_proVehPortList.pLcfVehDebugData  = &m_ppLCF_VehDebugData;
  
#ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
  memset(&m_ppNvmLcfDataVeh, 0, sizeof(m_ppNvmLcfDataVeh));
  AddProvidePort(PP_LCF_VEH_NVMLEARN_DATA, simOPAQUE_t, &m_ppNvmLcfDataVeh, sizeof(m_ppNvmLcfDataVeh));
  SetPPortVersion(PP_LCF_VEH_NVMLEARN_DATA, "NVM_LcfLearningData_t", CreateVersionInfoFromI32(LCF_LEARNDATA_INTFVER));
  m_proVehPortList.pNvmLcfData  = &m_ppNvmLcfDataVeh;
#endif
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
 
void CSimLcfVeh::DoitVeh()
{
  // TODO: place your plugin stuff here

  //If more than one call per cycle ensure, that this is called on cycle start
  // Reset RTA buffer
  m_algoServiceVeh.rtaNewCycle();
  
  CheckPortsDataReceived();
  
  //If more than one call per cycle ensure, that this is called on cycle start
  //! send cycle start
  MEASSendCycleStartMTS (TASK_ID_LCF_VEH);
  
  /* call algo */
  MainCallVeh();
  
  //If more than one call per cycle ensure, that this is really called on cycle end
  //! send cycle end
  MEASSendCycleEndMTS (TASK_ID_LCF_VEH);

  // trigger done port
  TriggerEvent(CP_DISTRIBUTEOUTPUTDATA_VEH, 0, 0);

  // trigger done port
  TriggerEvent(CP_CALCULATIONDONE_VEH, 0, 0);
}

void CSimLcfVeh::MainCallVeh()
{
  // Pre Process NVM Data

  // Freeze Input - Optional
  
  // Setup FPU
  SimDbgSetupFPU();

  __try
  {

    // Start execution of LcfVeh component
	if (0 == m_hil.iUseHil)
    {
		LcfVehExec(&m_reqVehPortList, &m_proVehPortList, &m_algoServiceVeh.getServiceFuncts());
	}	
	
	TriggerHIL(&m_reqVehPortList, &m_proVehPortList); // EVM-HIL: m_reqVehPortList contains inputs for EVM-HIL,
                                                //          m_proVehPortList contains outputs of simulation (when iProvideHilResults == 0)
                                                //          m_proVehPortList contains outputs of HIL (when iProvideHilResults == 1)
    
  }
  __except (SimDbgEvaluateException(GetExceptionCode(), GetExceptionInformation(), this ))
  {
   	 	// code execution had to be abborted due to unhandled exception 
  }

  // Restore FPU
  SimDbgRestoreFPU();

  /* Post Process NVM Data */
}

CVersionInfoImpl CSimLcfVeh::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

void CSimLcfVeh::TriggerHIL(const reqLcfVehPrtList_t *reqPorts, const proLcfVehPrtList_t *proPorts)
{
  errno_t ErrorRet = 0;
  if (0 != m_hil.iUseHil)
  {
    if ((0 != reqPorts->pLcfInputData))
    {
      m_hil.PortBuffer_mts2hil.VehIn_LcfInputData = *reqPorts->pLcfInputData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pLcfInputData input port is a zero pointer!");
    }
#if defined(LCF_VEH_RPORT_PLCFLADMCIUCTOSOC)
	if ((0 != reqPorts->pLcfLaDmcIucToSoc))
    {
      m_hil.PortBuffer_mts2hil.VehIn_LcfLaDmcIucToSoc = *reqPorts->pLcfLaDmcIucToSoc;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pLcfLaDmcIucToSoc input port is a zero pointer!");
    }
#endif	
	if ((0 != reqPorts->pLcfVehInputFromSenData))
    {
      m_hil.PortBuffer_mts2hil.VehIn_LcfVehInputFromSenData = *reqPorts->pLcfVehInputFromSenData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pLcfVehInputFromSenData input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pLcfSenOutputData))
    {
      m_hil.PortBuffer_mts2hil.VehIn_LcfSenOutputData = *reqPorts->pLcfSenOutputData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pLcfSenOutputData input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVehPar))
    {
      m_hil.PortBuffer_mts2hil.VehIn_VehPar = *reqPorts->pVehPar;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pVehPar input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVehSig))
    {
      m_hil.PortBuffer_mts2hil.VehIn_VehSig = *reqPorts->pVehSig;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pVehSig input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVehDyn))
    {
      m_hil.PortBuffer_mts2hil.VehIn_VehDyn = *reqPorts->pVehDyn;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pVehDyn input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pVdyOffsets))
    {
      m_hil.PortBuffer_mts2hil.VehIn_VdyOffsets = *reqPorts->pVdyOffsets;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pVdyOffsets input port is a zero pointer!");
    }
	
	
#ifdef ABD_OUTPUT_DATA_INTFVER	
	if ((0 != reqPorts->pAbdOutputData))
    {
      m_hil.PortBuffer_mts2hil.VehIn_ABDOutputData = *reqPorts->pAbdOutputData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pAbdOutputData input port is a zero pointer!");
    }
#endif

	if ((0 != reqPorts->pCParKmc))
    {
      m_hil.PortBuffer_mts2hil.VehIn_CParKmc = *reqPorts->pCParKmc;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pCParKmc input port is a zero pointer!");
    }
	
	if ((0 != reqPorts->pCParDmc))
    {
      m_hil.PortBuffer_mts2hil.VehIn_CParDmc = *reqPorts->pCParDmc;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pCParDmc input port is a zero pointer!");
    }
	
#ifdef LCF_VEH_PPORT_PNVMLCFDATA	//TODO: delete this line in next release
    if ((0 != reqPorts->pNvmLcfData))
    {
      m_hil.PortBuffer_mts2hil.VehIn_NvmLcfData = *reqPorts->pNvmLcfData;
    }
    else
    {
      ErrorRet = -1;
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! ** pNvmLcfData input port is a zero pointer!");
    }
#endif    
    
	
	if (0 != ErrorRet)
    {
      ReportError(err_sev_error, -1, "LCF_VEH: Error copying input data for EVM-HIL! At least one input port has a zero pointer!");
    }

    if (0 != reqPorts->pBaseCtrlData)
    {
      // we need at least the control port...
      m_hil.PortBuffer_mts2hil.VehIn_LcfVehCtrlData = *reqPorts->pBaseCtrlData;

      // Run HIL, only in case of no error:
      TriggerEvent("TriggerHIL",0,0);
    }

    if (0 != m_hil.iProvideHilResults)
    {
      m_hil.PortBuffer_hil2mts.VehOut_LcfAlgoCompState.uiVersionNumber = 123456789;
      *(proPorts->pAlgoCompState)          = m_hil.PortBuffer_hil2mts.VehOut_LcfAlgoCompState;
      *(proPorts->pLcfVehOutputData)       = m_hil.PortBuffer_hil2mts.VehOut_LcfVehOutputData;
	  #if defined(LCF_VEH_PPORT_PLCFLADMCSOCTOIUC)
	  *(proPorts->pLcfLaDmcSocToIuc)       = m_hil.PortBuffer_hil2mts.VehOut_LcfLaDmcSocToIuc;
	  #endif
	  *(proPorts->pLcfVehOutputToSenData)  = m_hil.PortBuffer_hil2mts.VehOut_LcfVehOutputToSenData;
      #ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
      *(proPorts->pNvmLcfData)             = m_hil.PortBuffer_hil2mts.VehOut_NvmLcfData;
      #endif

      // Do hil measfreeze
      MeasFreezeSim( LCF_VEH_MEAS_ID_SIM_RTA_BUFFER_HIL,  (void *)&m_hil.PortBuffer_hil2mts.RtaBuffer,                    sizeof(m_hil.PortBuffer_hil2mts.RtaBuffer));
      MeasFreezeSim( LCF_VEH_MEAS_ID_ALGO_COMP_STATE_HIL, (void *)&m_hil.PortBuffer_hil2mts.VehOut_LcfAlgoCompState,      sizeof(m_hil.PortBuffer_hil2mts.VehOut_LcfAlgoCompState));
      MeasFreezeSim( LCF_MEAS_ID_VEH_OUTPUT_HIL,          (void *)&m_hil.PortBuffer_hil2mts.VehOut_LcfVehOutputData,      sizeof(m_hil.PortBuffer_hil2mts.VehOut_LcfVehOutputData));
	  MeasFreezeSim( LCF_MEAS_ID_SOC2IUC_HIL,             (void *)&m_hil.PortBuffer_hil2mts.VehOut_LcfLaDmcSocToIuc,      sizeof(m_hil.PortBuffer_hil2mts.VehOut_LcfLaDmcSocToIuc));
      MeasFreezeSim( LCF_MEAS_ID_VEH2SEN_HIL,             (void *)&m_hil.PortBuffer_hil2mts.VehOut_LcfVehOutputToSenData, sizeof(m_hil.PortBuffer_hil2mts.VehOut_LcfVehOutputToSenData));
      #ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
      MeasFreezeSim( LCF_MEAS_ID_LEARNDATA_HIL,           (void *)&m_hil.PortBuffer_hil2mts.VehOut_NvmLcfData,            sizeof(m_hil.PortBuffer_hil2mts.VehOut_NvmLcfData));
      #endif
    }
  }
}

// Meas freeze method for sim data
void CSimLcfVeh::MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size)
{
  MEASInfo_t desc;

  desc.VirtualAddress = _vaddr;
  desc.Length         = _size;
  desc.FuncID         = TASK_ID_LCF_VEH;
  desc.FuncChannelID  = static_cast<uint8>(TASK_ID_LCF_VEH);

  (void) MTSMeas(&desc, (void *)_addr, NULL);
}

MEASReturn_t CSimLcfVeh::MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback)
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
