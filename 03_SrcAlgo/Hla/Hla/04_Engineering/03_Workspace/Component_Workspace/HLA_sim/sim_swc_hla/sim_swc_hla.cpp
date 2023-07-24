/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla

MODULNAME:            sim_swc_hla.cpp

DESCRIPTION:          SWC plugin for Head Light Assist

AUTHOR:               Reik Müller

CREATION DATE:        23.02.2010

VERSION:              $Revision: 1.10.1.1 $
**************************************************************************** */

/* includes ---------------------------------------------------------------- */

#include "stdafx.h"
#include "resource.h"
#include "sim_swc_hla.h"
#include <atlstr.h>
#include <math.h>
#include "sim_versioninfo_impl.h"
#include "hla_ver.h"

#include "param.h"
#include "HLA_DB.h"

#define SIM_HLA_DATA_SIMULATE_FRAMELOSTS       SWITCH_OFF

/* Cycle number which can be used to trigger measfreeze exports via SIM Exporter, etc. */
static DWORD CYCLE_INFO_ARR[] = {TASK_ID_HLA};

// the client port names
const char* CSimSwcHLA::CP_CALCULATIONDONE      = "CalculationDone";
const char* CSimSwcHLA::CP_DISTRIBUTEOUTPUTDATA = "DistributeOutputData";

/* class methods ----------------------------------------------------------- */

/* **************************************************************************** 
Functionname:    CSimSwcHLA                      */ /*!  
@brief           Constructor for CSimSwcHLA class

@author          Reik Müller
**************************************************************************** */
CSimSwcHLA::CSimSwcHLA              ()
:
CSimSwcDrawBase                     (10,"UnusedBufferDataID", simI64_t, "UnusedDoStorePortName", "..\\gia_sim\\adapter.dll"),
CSimHeadLightAssist                 (reinterpret_cast<CSimSwcBase*>(this), m_szRecFile , m_uiInputTimestamp),
CSimSwcCycleInfo                    (reinterpret_cast<CSimSwcBase*>(this), CYCLE_INFO_ARR, sizeof(CYCLE_INFO_ARR) / sizeof(DWORD)),
CSimSwcSynchronization              (this),
CSimHlaEthernet                     (reinterpret_cast<CSimSwcBase*>(this)),
CSimHlaCan                          (reinterpret_cast<CSimSwcBase*>(this)),
/* HLA input ports */
m_rpCtrlData                        (this, "pBaseCtrlData",           BaseCtrlData_t(),              BASE_CTRL_DATA_INTFVER),
m_rpCPAR_HLAF_Parameter             (this, "pCPar_HlafPar",           CPAR_HLAF_Parameter_t(),       CPAR_HLAF_PARAMETER_INTFVER),
m_rpCBProvidedOutputs               (this, "pCbOutputs",              CB_t_ProvidedOutputs_t(),      CB_PROVIDED_OUTPUTS_INTFVER),
m_rpEMObjectsList                   (this, "pGenObjectList",          EM_t_GenObjectList(),          EM_GEN_OBJECT_LIST_INTFVER|EM_GEN_OBJECT_INTFVER),
m_rpHlaBusInputSignals              (this, "pHlaBusInputSignals",     HLA_BusInputSignals_t(),       HLA_BUS_INPUT_SIGNALS_INTFVER),
m_rpHlaRadarObjectList              (this, "pHlaRadarObjectList",     HLA_RadarObjectList_t(),       HLA_RADAR_OBJECT_LIST_INTFVER),
m_rpMonoCalibration                 (this, "pMonoCalibration",        MonoCalibration_t(),           MONO_CALIBRATION_INTFVER),
m_rpVehDyn                          (this, "pVehDyn",                 VehDyn_t(),                    VDY_VEH_DYN_INTFVER),
m_rpVehSig                          (this, "pVehSig",                 VehSig_t(),                    BSW_VEH_SIG_INTFVER),
m_rpLsdEnvironment                  (this, "pLsdEnvironmentData",     LSD_EnvironmentData_t(),       LSD_ENVIRONMENT_DATA_INTFVER),
m_rpLsdLightObjectList              (this, "pLsdLightObjectList",     LSD_LightObjectList_t(),       LSD_LIGHT_OBJECT_LIST_INTFVER),
m_rpLsdLightList                    (this, "pLsdLightList",           LSD_LightList_t(),             LSD_LIGHT_LIST_INTFVER),
/* HLA output ports - needed for visualization of meas freeze data */
m_rpAlgoCompState                   (this, "pAlgoCompState",          AlgoCompState_t(),             COMP_STATE_INTFVER),
m_rpHLAF_HeadlightControl           (this, "pHlaf_HeadlightControl",  RTE_HLAF_HeadlightControl_t(), RTE_HLAF_HEADLIGHTCONTROL_INTFVER),
/* Internal Measfreeze */
m_rpHLA_ErrorStack                  (this, "HLA_ErrorStack",                t_ErrorHandling_ErrorStack()),
/* Parameter Ports */
m_rpOverwriteInputParameterPort     (this, "OverwriteRTEInput",       1),
m_bResetNeeded                      (true),
m_bInitNeeded                       (false)
{
  char versionNumberString[256];
  char versionInfoString[256];
  int swVerMajor, swVerMinor, swVerBugfix1, swVerBugfix2;


  swVerMajor   = (HLA_SW_VERSION_NUMBER & 0xFF000000) >> 24;
  swVerMinor   = (HLA_SW_VERSION_NUMBER & 0x00FF0000) >> 16;
  swVerBugfix1 = (HLA_SW_VERSION_NUMBER & 0x0000FF00) >>  8;
  swVerBugfix2 = (HLA_SW_VERSION_NUMBER & 0x000000FF);


  FormatString(versionNumberString, "\t%02d.%02d.%02d.%02d", swVerMajor, swVerMinor, swVerBugfix1, swVerBugfix2);
  FormatString(versionInfoString, "\t\t%s", HLA_SW_VERSION_INFO);
  AddInternalData("", "");
  AddInternalData("Description", "\t\tSWC plugin for Head Light Assist");
  AddInternalData("HLA Version Number", versionNumberString);
  AddInternalData("HLA Version Info", versionInfoString);
  AddInternalData("Developer(s)", "\t\tAlexander Fischer, Alexander Manz, Patrick Schillinger, Matthias Mutschler, Tobias Schwarz");
  

  AddServerPort("Reset", Reset, this);
  AddServerPort("Init", Init, this);
  AddServerPort("Doit", Doit, this);

  /* CLIENT PORTS */
  AddClientPort(CP_DISTRIBUTEOUTPUTDATA, NULL, 0);
  AddClientPort(CP_CALCULATIONDONE,      NULL, 0, PORT_WITH_AUTOCLONE);

  ::InitializeCriticalSection(&m_criticalSection);
  AddDrawServerPort("DrawFunction1", DrawFunction1, this);
  AddDrawServerPort("DrawFunction2", DrawFunction2, this);

  /* Add receive Ports */
  AddReceivePorts();

  ResetReceivePorts(true);

  m_hlaMeasdata[VISU_ENET] = CSimHlaEthernet::GetEthernetData();
  m_hlaMeasdata[VISU_CAN]  = CSimHlaCan::GetCanData();

  m_pOverwriteInputs = &m_rpOverwriteInputParameterPort.val();
}

void CSimSwcHLA::AddReceivePorts()
{
  memset(m_szRecFile, 0, sizeof(m_szRecFile));
  AddReceivePort("RecFileName", simI8_t, m_szRecFile, sizeof(m_szRecFile), 0, CollectRecFileName,  this);

  /* initialize input port map */
  m_receivePortMap.clear();

  /*--- HLA input ports ---*/

  /* HlaBSWCtrlData_In */
  m_rpCtrlData.setRtePointer((const BaseCtrlData_t**)&m_hlaMeasdata[VISU_ECU].ReqPorts.pBaseCtrlData);
  m_rpCtrlData.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpCtrlData);

  /* CPAR_HLAF_Parameter_t */
  m_rpCPAR_HLAF_Parameter.setupSyncData(&m_rpSyncRefHeader.val().pCPar_HlafPar, &m_rpCtrlData.val().sSigHeader);
  m_rpCPAR_HLAF_Parameter.setRtePointer((const CPAR_HLAF_Parameter_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pCPar_HlafPar);
  m_rpCPAR_HLAF_Parameter.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpCPAR_HLAF_Parameter);

  /* MonoCalibration_t */
  m_rpMonoCalibration.setupSyncData(&m_rpSyncRefHeader.val().pMonoCalibration, &m_rpCtrlData.val().sSigHeader);
  m_rpMonoCalibration.setRtePointer((const MonoCalibration_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pMonoCalibration);
  m_rpMonoCalibration.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpMonoCalibration);

  /* HLA_BusInputSignals_t */
  m_rpHlaBusInputSignals.setupSyncData(&m_rpSyncRefHeader.val().pHlaBusInputSignals, &m_rpCtrlData.val().sSigHeader);
  m_rpHlaBusInputSignals.setRtePointer((const HLA_BusInputSignals_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pHlaBusInputSignals);
  m_rpHlaBusInputSignals.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpHlaBusInputSignals);

  /* HLA_RadarObjectList_t */
  m_rpHlaRadarObjectList.setupSyncData(&m_rpSyncRefHeader.val().pHlaRadarObjectList, &m_rpCtrlData.val().sSigHeader);
  m_rpHlaRadarObjectList.setRtePointer((const HLA_RadarObjectList_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pHlaRadarObjectList);
  m_rpHlaRadarObjectList.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpHlaRadarObjectList);

  /* VehSig_t */
  m_rpVehSig.setupSyncData(&m_rpSyncRefHeader.val().pVehSig, &m_rpCtrlData.val().sSigHeader);
  m_rpVehSig.setRtePointer((const VehSig_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pVehSig);
  m_rpVehSig.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpVehSig);

  /* VehDyn_t */
  m_rpVehDyn.setupSyncData(&m_rpSyncRefHeader.val().pVehDyn, &m_rpCtrlData.val().sSigHeader);
  m_rpVehDyn.setRtePointer((const VehDyn_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pVehDyn);
  m_rpVehDyn.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpVehDyn);

  /* CB_t_ProvidedOutputs_t */
  m_rpCBProvidedOutputs.setupSyncData(&m_rpSyncRefHeader.val().pCbOutputs, &m_rpCtrlData.val().sSigHeader);
  m_rpCBProvidedOutputs.setRtePointer((const CB_t_ProvidedOutputs_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pCbOutputs);
  m_rpCBProvidedOutputs.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpCBProvidedOutputs);

  /* EM_t_GenObjectList */
  m_rpEMObjectsList.setupSyncData(&m_rpSyncRefHeader.val().pGenObjectList, &m_rpCtrlData.val().sSigHeader);
  m_rpEMObjectsList.setRtePointer((const EM_t_GenObjectList **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pGenObjectList);
  m_rpEMObjectsList.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpEMObjectsList);

  /* LSD Environment Data */
  m_rpLsdEnvironment.setupSyncData(&m_rpSyncRefHeader.val().pLsdEnvironmentData, &m_rpCtrlData.val().sSigHeader);
  m_rpLsdEnvironment.setRtePointer((const LSD_EnvironmentData_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pLsdEnvironmentData);
  m_rpLsdEnvironment.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpLsdEnvironment);

  /* LSD Light Object List */
  m_rpLsdLightObjectList.setupSyncData(&m_rpSyncRefHeader.val().pLsdLightObjectList, &m_rpCtrlData.val().sSigHeader);
  m_rpLsdLightObjectList.setRtePointer((const LSD_LightObjectList_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList);
  m_rpLsdLightObjectList.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpLsdLightObjectList);

  /* LSD Light List */
  m_rpLsdLightList.setupSyncData(&m_rpSyncRefHeader.val().pLsdLightList, &m_rpCtrlData.val().sSigHeader);
  m_rpLsdLightList.setRtePointer((const LSD_LightList_t **)&m_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightList);
  m_rpLsdLightList.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpLsdLightList);

  /*--- HLA output ports ---*/

  /* AlgoCompState */
  m_rpAlgoCompState.setupSyncData(&m_rpSyncRefHeader.val().sSigHeader, &m_rpCtrlData.val().sSigHeader);
  m_rpAlgoCompState.setRtePointer((const AlgoCompState_t **)&m_hlaMeasdata[VISU_ECU].ProPorts.pAlgoCompState);
  m_rpAlgoCompState.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpAlgoCompState);

  /* HLAF_HeadlightControl */
  m_rpHLAF_HeadlightControl.setupSyncData(&m_rpSyncRefHeader.val().sSigHeader, &m_rpCtrlData.val().sSigHeader);
  m_rpHLAF_HeadlightControl.setRtePointer((const RTE_HLAF_HeadlightControl_t **)&m_hlaMeasdata[VISU_ECU].ProPorts.pHlaf_HeadlightControl);
  m_rpHLAF_HeadlightControl.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpHLAF_HeadlightControl);

  /* Internal meas freeze */
  m_hlaMeasdata[VISU_ECU].hlaInternMeasdata.pHlaErrorStack = &m_rpHLA_ErrorStack.val();
}

/* **************************************************************************** 
Functionname:    ~CSimSwcHLA                      */ /*!  
@brief           Destructor for CSimSwcHLA class

@author          Reik Müller
**************************************************************************** */
CSimSwcHLA::~CSimSwcHLA()
{
  if(pLabelDB != NULL)
  {
    pLabelDB->closeDBSession();
    delete pLabelDB;
    pLabelDB = NULL;
  }

  if(pLabelDB_LDSS != NULL)
  {
    pLabelDB_LDSS->closeDBSession();
    delete pLabelDB_LDSS;
    pLabelDB_LDSS = NULL;
  }

  ::DeleteCriticalSection(&m_criticalSection);
}
/* **************************************************************************** 
Functionname:    Init                      */ /*!  
@brief           The Init Function which is called by the MO before calling
                 the Doit Function.
                 This Function calls the Init-Function of the Object.

@param[in]       plgID
@param[in]       param1
@param[in]       param2

@return          -

@pre             -
@post            -

@author          Reik Müller
**************************************************************************** */
void CSimSwcHLA::Init(void* plgID, long param1, long param2)
{
  CSimSwcHLA* pThis = reinterpret_cast<CSimSwcHLA*>(plgID);

  pThis->Init();
}
/* **************************************************************************** 
Functionname:    Reset                      */ /*!  
@brief           Reset Function

@param[in]       plgID
@param[in]       param1
@param[in]       param2

@return          -

@pre             -
@post            -

@author          Alexander Fischer
**************************************************************************** */
void CSimSwcHLA::Reset(void* plgID, long param1, long param2)
{
  CSimSwcHLA* pThis = reinterpret_cast<CSimSwcHLA*>(plgID);

  pThis->Reset();
}

/* **************************************************************************** 
Functionname:    Reset                      */ /*!  
@brief           This Function can be used to reset the algo
variables

@return          -

@pre             -
@post            -

@author          Reik Müller
**************************************************************************** */
void CSimSwcHLA::Reset(void)
{ 
  char path[257] = "";
  char* c;
  extern HANDLE g_hModule;

  /* To make sure that buffers are not initialized while visu is drawing some data out of it */
  ::EnterCriticalSection(&m_criticalSection);

  ResetReceivePorts(true);
  
  m_bResetNeeded = true;

  /* Reset eth ports */
  CSimHlaEthernet::ResetEthReceivePorts();
  /* Reset can ports */
  CSimHlaCan::ResetCanReceivePorts();

  /* ***** Initialize global variables ***** */
  /* head light assist */
  /* Important to do it here as we have provide ports like dllHlarReqIn */
  CSimHeadLightAssist::InitGlobalVars();

  /* Reset sim image */
  m_uiInputTimestamp = 0;

  /* Init new Simulation */
  {
    char path[257] = "";
    extern HANDLE g_hModule;
    GetModuleFileName((HMODULE) g_hModule, path, 256);
    CString strDllPath = path;
    strDllPath.Replace('\\', '/');
    
    (void)CSimHeadLightAssist::Reset(const_cast<char*>((LPCSTR) strDllPath));
  }

  ::LeaveCriticalSection(&m_criticalSection);

  
  /* init param module */
  ClearParams();
  /* load parameters from ini file */
  GetModuleFileName((HMODULE) g_hModule, path, 256);
  CString strDllPath = path;
  strDllPath.Replace('\\', '/');
  strcpy(strParamFileName, const_cast<char*>((LPCSTR) strDllPath));
  strcpy(m_szDllFile, strParamFileName);
  c = strrchr(strParamFileName, '.');
  if (c != NULL)
  {
    *c = 0x00;
    strcat(strParamFileName, ".ini");

    LoadParams();
  }
  
  /* get dll path */
  {
    strcpy(m_szDllFilePath, m_szDllFile);
    c = strrchr(m_szDllFilePath, '/');
    if (c != NULL)
    {
      *c = 0x00;
    } 
  }


  /* Set up connection to Label DB */
  if(GetParamInt("Label_Database", "labelDB_overlay", 0) )
  {
    if(pLabelDB == NULL) 
    {
      pLabelDB = new LabelDB<Buffer_MFC300_HLA_LDROI>;
      HRESULT hr = pLabelDB->openDBSession();
      if(FAILED(hr))
      {
        pLabelDB->closeDBSession();
        delete pLabelDB;
        pLabelDB = NULL;
      }
    }
  }

  if(GetParamInt("Label_Database_LDSS", "labelDB_overlay_LDSS", 0))
  {
    if(pLabelDB_LDSS == NULL)
    {
      pLabelDB_LDSS = new LabelDB_LDSS<Buffer_MFC300_HLA_LDSS>;
      pLabelDB_LDSS->NbOfRecFile = 0;
      HRESULT hr_ldss = pLabelDB_LDSS->openDBSession();
      if(FAILED(hr_ldss))
      {
        pLabelDB_LDSS->closeDBSession();
        delete pLabelDB_LDSS;
        pLabelDB_LDSS = NULL;
      }
    }
  }
}

/* **************************************************************************** 
Functionname:    Init                      */ /*!  
@brief           This Function can be used to init the algo variables

@return          -

@pre             -
@post            -

@author          Reik Müller
**************************************************************************** */
void CSimSwcHLA::Init(void)
{ 
  /* set ini flag -> evaluated in Doit function */
  m_bInitNeeded = true;

  /* Clean open GL canvas */

}

/* **************************************************************************** 
Functionname:    RunAlgo                      */ /*!  
@brief           Main processing loop for simulation.

@return          -

@pre             -
@post            -

@author          Reik Müller
**************************************************************************** */
void CSimSwcHLA::RunAlgo()
{
  if(m_bResetNeeded)
  {
    char path[257] = "";
    extern HANDLE g_hModule;
    GetModuleFileName((HMODULE) g_hModule, path, 256);
    CString strDllPath = path;
    strDllPath.Replace('\\', '/');

    /* Reset sim image */ 
    m_uiInputTimestamp = 0;
      
    /* Init new Simulation */
    (void)CSimHeadLightAssist::Reset(const_cast<char*>((LPCSTR) strDllPath));
  }

  if(m_bInitNeeded)
  {
    CSimHeadLightAssist::SimuInit();
    m_bInitNeeded = false;
  }

  /* run Algo */
  RunAlgoWithFPUExceptions();
}

/* **************************************************************************** 
Functionname:    RunAlgoWithFPUExceptions                      */ /*!  
@brief           Main processing loop catching and reporting the exceptions from
                 Floating Point Unit

@return          -

@pre             -
@post            -

@author          Stefan Zechner
**************************************************************************** */
void CSimSwcHLA::RunAlgoWithFPUExceptions()
{
  long err = 0;
  /* Setup FPU */
  CSimSwcDebugExc::SimDbgSetupFPU();

  __try
  {
    /* run HLA with new simu */
    if(CSimHeadLightAssist::RunAlgo(m_bResetNeeded) == 0)
    {
      m_bResetNeeded = false;
    }
    else
    {
      ReportError(err_sev_error, -1, "Error during RunAlgo().");
    }
  }
  __except (CSimSwcDebugExc::SimDbgEvaluateException(GetExceptionCode(), GetExceptionInformation(), this) )
  {
    /* Error reporting is done in CSimSwcDebugExc class*/
  }

  /* Restore FPU */
  CSimSwcDebugExc::SimDbgRestoreFPU();
}

void CSimSwcHLA::CollectRecFileName(void* plgID, long param1, long param2)
{
  CSimSwcHLA *pThis = reinterpret_cast<CSimSwcHLA*>(plgID);
  pThis->CollectRecFileName();
}

void CSimSwcHLA::CollectRecFileName(void)
{
  if (m_ssOldRecFile != m_szRecFile)
  {
    /* rec-file changed */

    /* call CSimSwcHLA::Init */
    Init();    
    
    /* offline mode and database request wanted ? */
    if(    (pLabelDB != NULL)
        && (strcmp(m_szRecFile, "Online") != 0)
        &&  GetParamInt("Label_Database", "labelDB_overlay", 0) 
       )
    {
      /* send database request for new rec-file */
      HRESULT hr = pLabelDB->createRowset(GetRecFile(), SelectString_MFC300_HLA_LDROI);
    }
    
    /* offline mode and database request wanted ? */
    if(     (pLabelDB_LDSS != NULL)
        &&  (strcmp(m_szRecFile, "Online") != 0)
        &&  (     ( GetParamInt("Label_Database_LDSS", "labelDB_overlay_LDSS", 0) )
            )        
       )
    {
      /* send database request for new rec-file */
      HRESULT hr_ldss = pLabelDB_LDSS->createRowset(GetRecFile(), SelectString_MFC300_HLA_LDSS);
    }


    /* get rec-file path and name (without ".rec") */
    {
      char* c;
            
      /* get rec-file path */
      CString strPath = m_szRecFile;
      strPath.Replace('\\', '/');
      strcpy(m_szRecFilePath, strPath);
      c = strrchr(m_szRecFilePath, '/');
      if (c != NULL)
      {
        *c = 0x00;

        /* get rec-file name */
        strcpy(m_szRecFileName, c+1);
      }
      else
      {
        /* no "/" found in string */
        /* copy complete string   */
        strcpy(m_szRecFileName, strPath);
      }
      
      /* remove .rec */
      c = strrchr(m_szRecFileName, '.');
      if (c != NULL)
      {
        *c = 0x00;
      } 
    }

    m_ssOldRecFile = m_szRecFile;
  }
  
}

/* **************************************************************************** 
Functionname:    Doit                                                     */ /*!  
@brief           The Doit Function is called each time image data 
                 is received.
                 This Function calls the Doit Function of the Object.

@param[in]       plgID
@param[in]       param1
@param[in]       param2

@return          -

@pre             -
@post            -

@author          Reik Müller
**************************************************************************** */
void CSimSwcHLA::Doit(void* plgID, long param1, long param2)
{
  CSimSwcHLA *pThis = reinterpret_cast<CSimSwcHLA*>(plgID);

#if (SIM_HLA_DATA_SIMULATE_FRAMELOSTS == SWITCH_ON)
  uint32 a = rand();
  uint32 numFrameLost;
  static uint32 prevframe = 0;
  static uint32 currentframe = 0;

  numFrameLost = (uint32)(((float32)a/RAND_MAX)*6.0f);
  
  currentframe++;

  if( (currentframe - prevframe) >= numFrameLost)
  {
    prevframe = currentframe;
    pThis->Doit();
  }

#else
   
  pThis->Doit();

#endif
}

/* **************************************************************************** 
Functionname:    Doit                                                     */ /*!  
@brief           Process Image, run HLA Algo 

@return          -

@pre             -
@post            -

@author          Reik Müller
**************************************************************************** */
void CSimSwcHLA::Doit(void)
{

  /* send cycle start */
  MEASSendCycleStartMTS((unsigned char)GetCycleIdArray()[0]);

  /* Check RTE Ports */
  CheckPortsDataReceived();

  /* Check Ethernet input & copy to RTE structs */
  CSimHlaEthernet::CollectKAFASInputs();
   
  ::EnterCriticalSection(&m_criticalSection);
  {
    /* call hla algo */
    RunAlgo();
   
    ResetReceivePorts(false);
  }
  ::LeaveCriticalSection(&m_criticalSection);
   
  /* trigger done port */
  TriggerEvent(CP_DISTRIBUTEOUTPUTDATA, 0, 0);

  /* trigger done port */
  TriggerEvent(CP_CALCULATIONDONE, 0, 0);
   
  /* send cycle end */
  MEASSendCycleEndMTS((unsigned char)GetCycleIdArray()[0]);
}

void CSimSwcHLA::DrawFunction1(void* PlgID, long Param1, long /*Param2*/)
{
  CSimSwcHLA *pThis = reinterpret_cast<CSimSwcHLA*>(PlgID);
  const ISimRenderContext* pContext = reinterpret_cast<const ISimRenderContext*>(LongToPtr(Param1));

  pThis->DrawFunction1(pContext);
}

void CSimSwcHLA::DrawFunction1(const ISimRenderContext* pContext)
{
  ::EnterCriticalSection(&m_criticalSection);
  CSimHlaVisu::DrawFunction1(pContext);
  ::LeaveCriticalSection(&m_criticalSection);
}

void CSimSwcHLA::DrawFunction2(void* PlgID, long Param1, long /*Param2*/)
{
  CSimSwcHLA *pThis = reinterpret_cast<CSimSwcHLA*>(PlgID);
  const ISimRenderContext* pContext = reinterpret_cast<const ISimRenderContext*>(LongToPtr(Param1));

  pThis->DrawFunction2(pContext);
}

void CSimSwcHLA::DrawFunction2(const ISimRenderContext* pContext)
{
  ::EnterCriticalSection(&m_criticalSection);
  CSimHlaVisu::DrawFunction2(pContext);
  ::LeaveCriticalSection(&m_criticalSection);
}

void CSimSwcHLA::FormatString(char* dstString, char* fmt, ...)
{
  int cbSize = 0;
  va_list ap;                              // pointer to list of arguments

  va_start(ap, fmt);                       // Parses The String For Variables
  cbSize = vsprintf(dstString, fmt, ap);   // And Converts Symbols To Actual Numbers
  va_end(ap);                              // Results Are Stored In Text
}

/* ------------------------------------------------------------------------ */
/* EoF */
