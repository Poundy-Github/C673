/* includes --------------------------------------------------------------- */
#include <math.h>
#ifdef USE_24BIT_MANTISSA
#include <float.h>
#endif
#include "stdafx.h"
#include "resource.h"

#include "sim_versioninfo_impl.h"

#include <direct.h>
#define GetCurrentDir _getcwd

#ifdef __cplusplus
extern "C"
{
#endif
#include "hla_defs.h"
#include "hla_main.h"
#include "hla_outputs.h"
#include "hla_errorhandling.h"
#ifdef __cplusplus
}
#endif

#include "sim_headlightassist.h"
#include "sim_hla_measfreeze_data.h"
#include "HLA_DB.h"

#include "param.h"


#define CONV_I32VERSION_TO_TUPPLE(x)   (((x) >> 16) & 0xFF), (((x) >> 8) & 0xFF), ((x) & 0xFF)
#define HLA_ENABLE_HOT_PIXELS_SIMULATION   SWITCH_OFF

/* structs, enums and typedefs -------------------------------------------- */


#ifdef __cplusplus
extern "C"
{
#endif

extern int CParInitCPAR_HLAF_Parameter(CPAR_HLAF_Parameter_t* pCPar_HlafPar);

/* HLAF  */
extern HLAFData_t                 hlafData;

#ifdef __cplusplus
}
#endif

/* Frame Counter used in generate hot pixel function */
int debugViewFrameCounter;

static int HLA_ALWAYS_ENABLED = 1;

/* hot pixel simulation data  */
#if (HLA_ENABLE_HOT_PIXELS_SIMULATION == SWITCH_ON )
#define HLA_HOT_PIXELS_SIMULATION_NUM     98
HLA_t_ICDefectPixel ImagerDefectPix[HLA_HOT_PIXELS_SIMULATION_NUM];
uint16 HotPixelsImageOdd[IMAGE_MAX_NUM_PIXEL];
#endif

static Hla_SyncRef_t SyncRefDummy;

/* first pixel position of MTS ROI (transfered image) in absolute imager coordinates */
float32 simData_MTSRoiX1;
float32 simData_MTSRoiY1;
float32 simData_MTSRoiWidth;
float32 simData_MTSRoiHeight;

/* first pixel position of HLA ROI in MTS ROI coordinates (not absolute imager coordinates) */
float32 simData_HLARoiX1;
float32 simData_HLARoiY1;
float32 simData_HLARoiX2;
float32 simData_HLARoiY2;
float32 simData_HLARoiWidth;
float32 simData_HLARoiHeight;

static const AS_t_MeasInfo SilHlaReqPortCparHlafParMeasInfo        =  {SIL_HLA_MEAS_VADDR_REQ_PORT_CPAR_HLAF_PAR,         sizeof(CPAR_HLAF_Parameter_t),  TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortMonoCalibrationMeasInfo    =  {SIL_HLA_MEAS_VADDR_REQ_PORT_MONO_CALI,             sizeof(MonoCalibration_t),      TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortHlaBusInputSignalsMeasInfo =  {SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_BUS_INPUT_SIGNALS, sizeof(HLA_BusInputSignals_t),  TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortHlaRadarObjectListMeasInfo =  {SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_RADAR_OBJECT_LIST, sizeof(HLA_RadarObjectList_t),  TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortVehSigMeasInfo             =  {SIL_HLA_MEAS_VADDR_REQ_PORT_VEH_SIG,               sizeof(VehSig_t),               TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortVehDynMeasInfo             =  {SIL_HLA_MEAS_VADDR_REQ_PORT_VDY_DATA,              sizeof(VehDyn_t),               TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortBlockageOutputsMeasInfo    =  {SIL_HLA_MEAS_VADDR_REQ_PORT_BLOCKAGE_OUTPUTS,      sizeof(CB_t_ProvidedOutputs_t), TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortEMObjectListMeasInfo       =  {SIL_HLA_MEAS_VADDR_REQ_PORT_EM_OBJECT_LIST,        sizeof(EM_t_GenObjectList),     TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortLDOutputMeasInfo           =  {SIL_HLA_MEAS_VADDR_REQ_PORT_LD_OUT,                sizeof(LdOutputData_t),         TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortLsdEnvironmentMeasInfo     =  {SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_ENVIRONMENT_DATA,  sizeof(LSD_EnvironmentData_t),  TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortLsdLightOBjectListMeasInfo =  {SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_OBJECT_LIST, sizeof(LSD_LightObjectList_t),  TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo SilHlaReqPortLsdLightListMeasInfo       =  {SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_LIST,        sizeof(LSD_LightList_t),        TASK_ID_HLA, TASK_ID_HLA};


static const AS_t_MeasInfo HilHlaAlgoCompStateMeasInfo   = {HIL_HLA_MEAS_VADDR_ALGO_COMP_STATE,    sizeof(AlgoCompState_t), TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo HilHlaEvmRtaBufferMeasInfo    = {HIL_HLA_MEAS_VADDR_RTA_BUFFER,         sizeof(AS_t_RtaBuffer),  TASK_ID_HLA, TASK_ID_HLA};
static const AS_t_MeasInfo HilHlaEvmRtaBufferEveMeasInfo = {HIL_HLA_MEAS_VADDR_RTA_BUFFER_EVE,     sizeof(AS_t_RtaBuffer),  TASK_ID_HLA, TASK_ID_HLA};

CSimHeadLightAssist::CSimHeadLightAssist(CSimSwcBase* pSimPlgBase, const char* recFileName , const unsigned __int64& m_uiInputTimestamp)
: CSimHlaVisu(pSimPlgBase, recFileName, &m_hlaMeasdata[0], &m_uiInputTimestamp),
  CSimSwcMeas(pSimPlgBase),
  CSimHlaMeasData(),
  CSimSwcCDL(pSimPlgBase, IDR_CDL1),
  m_pSimPlgBase(pSimPlgBase),
  m_uiPrevTimestamp(0),
  m_uiInputTimestamp(0),
  m_recFileIndex(),
  m_algoServicesInstance(124 * 1024, 124 * 1024, this, COMP_ID_HLA),
  m_algoServices(m_algoServicesInstance.getServiceFuncts()),
  m_Hil2MtsPort(pSimPlgBase, "HIL_hil2mts", 0),
  m_Hil2Mts(*reinterpret_cast<Hil2Mts_t*>(m_Hil2MtsPort.val())),
  m_EnableHil(pSimPlgBase, "HIL_UseHil", 0),
  m_isHilInitNeeded(FALSE),
  m_maxNumMeasfreezedBytes(0u)
{
  memset(&m_hlaMeasdata, 0, sizeof(m_hlaMeasdata));
  memset(&m_hlaMeasdataBuffersSIL, 0, sizeof(m_hlaMeasdataBuffersSIL));

  /* add simulation provide ports */
  AddSimProvidePorts(pSimPlgBase);

  m_pSimPlgBase->AddReceivePort("InputTimestamp", simI64_t, (void*)&m_uiInputTimestamp, sizeof(m_uiInputTimestamp));

  /* HIL */
  m_pSimPlgBase->AddProvidePort("RtaBuffer",    simOPAQUE_t, &m_Hil2Mts.rtaBuffer,    sizeof(m_Hil2Mts.rtaBuffer));
  m_pSimPlgBase->AddProvidePort("RtaBufferEve", simOPAQUE_t, &m_Hil2Mts.rtaBufferEve, sizeof(m_Hil2Mts.rtaBufferEve));
  m_pSimPlgBase->AddProvidePort("HIL_mts2hil",  simUI8_t,    &m_Mts2Hil,              sizeof(m_Mts2Hil));
  m_pSimPlgBase->AddClientPort("TriggerHil",    NULL,        0,                       PORT_WITH_AUTOCLONE);
  m_pSimPlgBase->AddClientPort("Wait4Hil",      NULL,        0,                       PORT_WITH_AUTOCLONE);

  /* reset hil output struct */
  memset((void*)&m_Hil2Mts, 0, sizeof(m_Hil2Mts));

  /* reset RTA timing */
  m_algoServicesInstance.rtaNewCycle();

  /* DLL: Init pointer list for reqPorts, proPorts and interMeasData */
  LinkBuffers(m_hlaMeasdata[VISU_SIL], m_hlaMeasdataBuffersSIL);
  LinkBuffers2AlgoInterMeasData(m_hlaMeasdata[VISU_SIL].hlaInternMeasdata);

  /* ECU: Init pointer list for interMeasData only. ReqPorts and ProPorts are initialized in CSimSwcHLA::AddReceivePorts() */
  LinkBuffers2ECUInterMeasData(m_hlaMeasdata[VISU_ECU].hlaInternMeasdata);

  if(m_EnableHil.val() != 0)
  {
    /* EVM HIL: Init pointer list of EVM HIL for reqPorts, proPorts and interMeasData */
    memcpy((void*)&(m_hlaMeasdata[VISU_EVM].ReqPorts), (const void*)&(m_hlaMeasdata[VISU_SIL].ReqPorts), CML_Min(sizeof(m_hlaMeasdata[VISU_EVM].ReqPorts), sizeof(m_hlaMeasdata[VISU_SIL].ReqPorts)));
    LinkBuffersProPorts(m_hlaMeasdata[VISU_EVM].ProPorts, m_Hil2Mts.proPortBuffers);
    LinkBuffers2EVMInterMeasData(m_hlaMeasdata[VISU_EVM].hlaInternMeasdata);
  }
  else
  {
    memset((void*)&(m_hlaMeasdata[VISU_EVM]), 0, sizeof(m_hlaMeasdata[VISU_EVM]));
  }
}

CSimHeadLightAssist::~CSimHeadLightAssist(void)
{
}

void CSimHeadLightAssist::AddSimProvidePorts(CSimSwcBase* pSimPlgBase)
{
  /* CAM BMW  */
  pSimPlgBase->AddProvidePort("CAN_BMW",  simOPAQUE_t, &m_hlaMeasdata[VISU_CAN],  sizeof(SimHlaMeasdata_t));

  /* HLAR State output */
  pSimPlgBase->AddProvidePort("pAlgoCompState",  simOPAQUE_t, &m_hlaMeasdataBuffersSIL.ProPortsBuffers.AlgoCompState,  sizeof(m_hlaMeasdataBuffersSIL.ProPortsBuffers.AlgoCompState));
  static const CVersionInfoImpl CompStateVersion(CONV_I32VERSION_TO_TUPPLE(COMP_STATE_INTFVER));
  pSimPlgBase->SetPPortVersion("pAlgoCompState", "AlgoCompState_t", CompStateVersion);

  /* Hlaf_HeadlightControl State output */
  pSimPlgBase->AddProvidePort("pHlaf_HeadlightControl",  simOPAQUE_t, &m_hlaMeasdataBuffersSIL.ProPortsBuffers.Hlaf_HeadlightControl,  sizeof(m_hlaMeasdataBuffersSIL.ProPortsBuffers.Hlaf_HeadlightControl));
  static const CVersionInfoImpl HlaHeadlightControlVersion(CONV_I32VERSION_TO_TUPPLE(RTE_HLAF_HEADLIGHTCONTROL_INTFVER));
  pSimPlgBase->SetPPortVersion("pHlaf_HeadlightControl", "RTE_HLAF_HeadlightControl_t", HlaHeadlightControlVersion);
}

/* **************************************************************************** 
  Functionname:     InitGlobalVars()                                      */ /*!  
  Description:      Initializes all global variables of the HeadLightAssist. 
                    This enables the simulation framework to re-init the HLA
                    algo without reloading the DLL.
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Matthias Mutschler
**************************************************************************** */ 
void CSimHeadLightAssist::InitGlobalVars()
{
  HLA_ALWAYS_ENABLED = 1;
     
#if (HLA_ENABLE_HOT_PIXELS_SIMULATION == SWITCH_ON )
  memset(&ImagerDefectPix[0], 0, sizeof(ImagerDefectPix));
#endif

  memset(&m_hlaMeasdata[VISU_SIL], 0, sizeof(m_hlaMeasdata[VISU_SIL]));
  memset(&m_hlaMeasdataBuffersSIL, 0, sizeof(m_hlaMeasdataBuffersSIL));

  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.CPar_HlafPar.sSigHeader.eSigStatus           = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.Sig_MonoCalibration.sSigHeader.eSigStatus    = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.HlaBusInputSignals.sSigHeader.eSigStatus     = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.SigVeh_VehSig.sSigHeader.eSigStatus          = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.SigVeh_VDYData.sSigHeader.eSigStatus         = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.Sig_Blockage.sSigHeader.eSigStatus           = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.LsdEnvironmentData.sSigHeader.eSigStatus     = AL_SIG_STATE_INVALID;
  m_hlaMeasdataBuffersSIL.ReqPortsBuffers.LsdLightObjectList.sSigHeader.eSigStatus     = AL_SIG_STATE_INVALID;
   
  /* Init pointer list for reqPorts, proPorts and interMeasData */
  LinkBuffers(m_hlaMeasdata[VISU_SIL], m_hlaMeasdataBuffersSIL);
  LinkBuffers2AlgoInterMeasData(m_hlaMeasdata[VISU_SIL].hlaInternMeasdata);

  /* Clean EVM HIL data */
  if(m_EnableHil.val() != 0)
  {
    memset(&m_Hil2Mts, 0, sizeof(m_Hil2Mts));
    memset(&m_Mts2Hil, 0, sizeof(m_Mts2Hil));

    /* Trigger HIL to do a proper reset of algo */
    m_Mts2Hil.isHilResetNeeded = b_TRUE;

    m_maxNumMeasfreezedBytes = 0u;

    /* Init pointer list of EVM HIL for reqPorts, proPorts and interMeasData */
    memcpy((void*)&(m_hlaMeasdata[VISU_EVM].ReqPorts), (const void*)&(m_hlaMeasdata[VISU_SIL].ReqPorts), CML_Min(sizeof(m_hlaMeasdata[VISU_EVM].ReqPorts), sizeof(m_hlaMeasdata[VISU_SIL].ReqPorts)));
    LinkBuffersProPorts(m_hlaMeasdata[VISU_EVM].ProPorts, m_Hil2Mts.proPortBuffers);
    LinkBuffers2EVMInterMeasData(m_hlaMeasdata[VISU_EVM].hlaInternMeasdata);
  }

  /* Clean algo internal buffers */
  HLA_FirstStatupState();
  HLA_SetOutputDefaults( COMP_STATE_NOT_INITIALIZED,
                         COMP_ERROR_NO_ERROR,
                         ALGO_QUAL_OK,
                         AL_SIG_STATE_INIT,
                         m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData->sSigHeader.uiTimeStamp,
                         m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData->sSigHeader.uiMeasurementCounter,
                         0u,
                         &SyncRefDummy,
                         (proHlaPrtList_t *)&m_hlaMeasdata[VISU_SIL].ProPorts
                        );

  /* Overwrite output of HLAR_v_Init function */
  m_hlaMeasdataBuffersSIL.ProPortsBuffers.AlgoCompState.eErrorCode = COMP_ERROR_NO_ERROR;
}


void CSimHeadLightAssist::OverwriteRTEInput( boolean bResetNeeded )
{
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData == NULL)
  {
    /* not joint simu, and very old rec-file without BaseCtrlData */
    /* -> set op mode to run */
    m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData                               = &m_hlaMeasdataBuffersSIL.ReqPortsBuffers.BaseCtrlData;
    m_hlaMeasdataBuffersSIL.ReqPortsBuffers.BaseCtrlData.eOpMode               = BASE_OM_RUN;
    m_hlaMeasdataBuffersSIL.ReqPortsBuffers.BaseCtrlData.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }


  if((m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar != NULL))
  {
    /* overwrite HLAF Matrix Beam parameters with ini-file settings */
    if (GetParamInt("HLAF_ParameterMatrixBeam", "overwriteParameterMatrixBeam", 0) == 1)
    {
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->Matrix.MaxNumGlarefreeArea  = GetParamInt("HLAF_ParameterMatrixBeam", "MaxNumGlarefreeArea", 1);
    }

    /* overwrite incorrect coded dimming parameter*/
    if (m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->Dimming.AreaRightBorderArray[0] == (-7.0f))
    {
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->Dimming.AreaRightBorderArray[0] = CML_Deg2Rad(-7.0f);
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->Dimming.AreaRightBorderArray[1] = CML_Deg2Rad(-3.0f);
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->Dimming.AreaRightBorderArray[2] = CML_Deg2Rad( 3.0f);
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->Dimming.AreaRightBorderArray[3] = CML_Deg2Rad( 7.0f);
    }
  }


  if( (m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar != NULL))
  {
    /* overwrite TestMode */
    m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->AlgoCfg.TestMode = GetParamInt("param", "OVERWRITE_TEST_MODE", 1);
  }

  if((m_hlaMeasdata[VISU_SIL].ReqPorts.pCbOutputs != NULL))
  {
    if (GetParamInt("param", "OVERWRITE_BLOCKAGE", 0))
    {
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCbOutputs->ui8_BlockageStatus   = GB_NO_BLOCKAGE;
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCbOutputs->ui8_VisibilityRange  = GB_CLEAR_VISIBILITY_RANGE;
      m_hlaMeasdata[VISU_SIL].ReqPorts.pCbOutputs->ui8_WeatherCondition = GB_GLARING;
    }
  }

  /* overwrite measfreeze parameter */
  if (GetParamInt("param", "DO_NOT_OVERWRITE_MEASFREEZE_PARAMETER", 0) == 0)
  {
    m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar = &m_hlaMeasdataBuffersSIL.ReqPortsBuffers.CPar_HlafPar;

    CParInitCPAR_HLAF_Parameter(m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar);

    /* Set SigStatus */
    m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  }


  /* Overwrite OpMode */
  if(bResetNeeded == b_TRUE)
  {
    /* Set OpMode to reset in init phase */
    if (m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData != NULL)
    {
      m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData->eOpMode = BASE_OM_RESET;
    }
  }
  else
  {
    /* Run Mode */
    /* mfc3xx Recording -> Set OpMode to Run */
    if(m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData->eOpMode == BASE_OM_IDLE)
    {
      m_hlaMeasdataBuffersSIL.ReqPortsBuffers.BaseCtrlData.eOpMode               = BASE_OM_RUN;
      m_hlaMeasdataBuffersSIL.ReqPortsBuffers.BaseCtrlData.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    }
  }


  /* Fake speed for good old Darmstadt recording */
  if (   (m_recFileIndex.findRecFileName( "Good_Old_Recs", GetRecFile() ) == true)
      && (m_hlaMeasdata[VISU_SIL].ReqPorts.pVehDyn != NULL)
     )
  {
    m_hlaMeasdata[VISU_SIL].ReqPorts.pVehDyn->Longitudinal.Velocity = 1.0f;
    m_hlaMeasdata[VISU_SIL].ReqPorts.pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
  }

  // Check if current rec file is listed as TA19 special route rec file index
  if (m_recFileIndex.findRecFileName( "TA19_Special_Routes", GetRecFile()) == true)
  {
    // set state for SpeedoSpeed to valid
    if (m_hlaMeasdata[VISU_SIL].ReqPorts.pVehSig != NULL)
    {
      m_hlaMeasdata[VISU_SIL].ReqPorts.pVehSig->VehSigAdd.State[VEH_SIG_ADD_SPEEDO_SPEED] = VDY_IO_STATE_VALID;
    }
  }
}

void CSimHeadLightAssist::PrepareInputOutputSignals(boolean bResetNeeded)
{
  /* Re-create link to reqPorts as these ones can be overwritten in CopyRTEInputData */
  LinkBuffersReqPorts(m_hlaMeasdata[VISU_SIL].ReqPorts, m_hlaMeasdataBuffersSIL.ReqPortsBuffers);

  /* copy input/ output data from external memory to internal memory for simulation*/
  CopyRTEInputData( m_hlaMeasdata[VISU_SIL].ReqPorts, /* destination */
                    m_hlaMeasdata[VISU_ECU].ReqPorts /* source */
                   );

  if (*m_pOverwriteInputs == 1)
  {
    OverwriteRTEInput(bResetNeeded);
  }
}


long CSimHeadLightAssist::Reset(char* szDLLPath)
{
  /* local Variables */
  long Error = 0;
  char* c;
  
  std::string localRecFileIndex(szDLLPath);
  std::string recFileName(GetRecFile());

  m_uiPrevTimestamp = 0;


#ifdef USE_24BIT_MANTISSA
  /* read floating point control status */
  unsigned int fpControl = _controlfp( 0, 0 );
  /* set 24bit single precision */
  _controlfp( _PC_24, MCW_PC );
  /* read floating point control status */
  fpControl = _controlfp( 0, 0 );
#endif

  /* init visualization */
  //TODO: CSimHlaVisu::Init(CheckImageFingerPrintValidity_ui16, CheckImageFingerPrintValidity_ui8);


  /* ***** Initialize global variables ***** */

  /* init param module (.ini File)*/
  ClearParams();

  /* try to open INI-File, which is located with Algorithm-DLL */
  strcpy(strParamFileName, szDLLPath);
  c = strrchr(strParamFileName, '.');
  if (c != NULL)
  {
    *c = 0x00;
    strcat(strParamFileName, ".ini");
    LoadParams();
  }

  std::size_t found = localRecFileIndex.find_last_of("/");
  m_recFileIndex.importFile(localRecFileIndex.substr(0, found).append("/../../../../cfg/HLA/sim_hla_recfileindex.txt"));

  /* try to open INI-Files, which are located with Video-File */
  //char* szLogFilePath = const_cast<char*>(recFileName);

  HLA_ALWAYS_ENABLED  = GetParamInt("param", "HLA_ALWAYS_ENABLED", HLA_ALWAYS_ENABLED);

  return Error;
}

/*****************************************************************************/
void CSimHeadLightAssist::LinkBuffers2AlgoInterMeasData(SimHlaInternMeasdataList_t &hlaInternMeasdata)
{
  hlaInternMeasdata.pHlaErrorStack                  = HLA_ErrorHandling_GetErrorStack();
  hlaInternMeasdata.pHlafData                       = &hlafData;
}

void CSimHeadLightAssist::LinkBuffers2EVMInterMeasData(SimHlaInternMeasdataList_t &hlaInternMeasdata)
{
  hlaInternMeasdata.pHlaErrorStack           = &m_Hil2Mts.hlaErrorStack;
  hlaInternMeasdata.pRtaBuffer               = &m_Hil2Mts.rtaBuffer;
  hlaInternMeasdata.pRtaBufferEve            = &m_Hil2Mts.rtaBufferEve;
}

void CSimHeadLightAssist::LinkBuffers2ECUInterMeasData(SimHlaInternMeasdataList_t &hlaInternMeasdata)
{
  /* Delete links where we don't have a receive port yet */
  hlaInternMeasdata.pHlafData       = NULL;

  /* Set evm specialties to NULL by default */
  hlaInternMeasdata.pRtaBuffer      = NULL;
  hlaInternMeasdata.pRtaBufferEve   = NULL;
}

void CSimHeadLightAssist::CopyRTEData(void** pDest, const void* pSrc, const uint32 length)
{
  if(    (pSrc != NULL)
      && (*pDest != NULL)
    )
  {
    memcpy(*pDest, pSrc, length);
  }
  else
  {
    /* Algo input pointer must be set to NULL when simu port input pointer is NULL */
    /* simu port input pointer is NULL when port is not available                  */
    *pDest = NULL;
  }
}

void CSimHeadLightAssist::CopyRTEInputData( SimHlaReqPrtList_t& pDest,
                                            const SimHlaReqPrtList_t& pSrc
                                          )
{
  CopyRTEData((void**)&pDest.pBaseCtrlData,           (const void*)pSrc.pBaseCtrlData,           sizeof(BaseCtrlData_t));
  CopyRTEData((void**)&pDest.pCPar_HlafPar,           (const void*)pSrc.pCPar_HlafPar,           sizeof(CPAR_HLAF_Parameter_t));
  CopyRTEData((void**)&pDest.pMonoCalibration,        (const void*)pSrc.pMonoCalibration,    sizeof(MonoCalibration_t));
  CopyRTEData((void**)&pDest.pHlaBusInputSignals,     (const void*)pSrc.pHlaBusInputSignals,     sizeof(HLA_BusInputSignals_t));
  CopyRTEData((void**)&pDest.pHlaRadarObjectList,     (const void*)pSrc.pHlaRadarObjectList,     sizeof(HLA_RadarObjectList_t));
  CopyRTEData((void**)&pDest.pVehSig,                 (const void*)pSrc.pVehSig,          sizeof(VehSig_t));
  CopyRTEData((void**)&pDest.pVehDyn,                 (const void*)pSrc.pVehDyn,         sizeof(VehDyn_t));
  CopyRTEData((void**)&pDest.pCbOutputs,              (const void*)pSrc.pCbOutputs,           sizeof(CB_t_ProvidedOutputs_t));
  CopyRTEData((void**)&pDest.pGenObjectList,          (const void*)pSrc.pGenObjectList,      sizeof(EM_t_GenObjectList));
  CopyRTEData((void**)&pDest.pLsdEnvironmentData,     (const void*)pSrc.pLsdEnvironmentData,     sizeof(LSD_EnvironmentData_t));
  CopyRTEData((void**)&pDest.pLsdLightObjectList,     (const void*)pSrc.pLsdLightObjectList,     sizeof(LSD_LightObjectList_t));
  CopyRTEData((void**)&pDest.pLsdLightList,           (const void*)pSrc.pLsdLightList,           sizeof(LSD_LightList_t));
}

void CSimHeadLightAssist::CopyImageData( const void*              pSrc, 
                                         const uint32             imageSize,
                                               void*              pDest, 
                                               AlgoSignalState_t& destSigStatus
                                        )
{
  if(   (pSrc != NULL)
     && (pDest != NULL)
    )
  {
    memcpy(pDest, pSrc, imageSize);
  } 
  else
  {
    destSigStatus = AL_SIG_STATE_INVALID;
  }
}

long CSimHeadLightAssist::RunAlgo(boolean bResetNeeded)
{
  /* local Variables */
  long err = 0;
  ++debugViewFrameCounter;

  /* cyclic read of param-file */
  LoadParams();

  PrepareInputOutputSignals(bResetNeeded);
    
  /* reset RTA timing */
  m_algoServicesInstance.rtaNewCycle();

  /* Measfreeze request ports for KPI runs, possibility to check overwritten data in measfreeze, etc. */
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar)           {m_algoServices.pfMeasFreeze(&SilHlaReqPortCparHlafParMeasInfo,        m_hlaMeasdata[VISU_SIL].ReqPorts.pCPar_HlafPar,           NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pMonoCalibration)        {m_algoServices.pfMeasFreeze(&SilHlaReqPortMonoCalibrationMeasInfo,    m_hlaMeasdata[VISU_SIL].ReqPorts.pMonoCalibration,    NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pHlaBusInputSignals)     {m_algoServices.pfMeasFreeze(&SilHlaReqPortHlaBusInputSignalsMeasInfo, m_hlaMeasdata[VISU_SIL].ReqPorts.pHlaBusInputSignals,     NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pHlaRadarObjectList)     {m_algoServices.pfMeasFreeze(&SilHlaReqPortHlaRadarObjectListMeasInfo, m_hlaMeasdata[VISU_SIL].ReqPorts.pHlaRadarObjectList,     NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pVehSig)                 {m_algoServices.pfMeasFreeze(&SilHlaReqPortVehSigMeasInfo,             m_hlaMeasdata[VISU_SIL].ReqPorts.pVehSig,          NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pVehDyn)                 {m_algoServices.pfMeasFreeze(&SilHlaReqPortVehDynMeasInfo,             m_hlaMeasdata[VISU_SIL].ReqPorts.pVehDyn,         NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pCbOutputs)              {m_algoServices.pfMeasFreeze(&SilHlaReqPortBlockageOutputsMeasInfo,    m_hlaMeasdata[VISU_SIL].ReqPorts.pCbOutputs,           NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pGenObjectList)          {m_algoServices.pfMeasFreeze(&SilHlaReqPortEMObjectListMeasInfo,       m_hlaMeasdata[VISU_SIL].ReqPorts.pGenObjectList,      NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pLsdEnvironmentData)     {m_algoServices.pfMeasFreeze(&SilHlaReqPortLsdEnvironmentMeasInfo,     m_hlaMeasdata[VISU_SIL].ReqPorts.pLsdEnvironmentData,     NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pLsdLightObjectList)     {m_algoServices.pfMeasFreeze(&SilHlaReqPortLsdLightOBjectListMeasInfo, m_hlaMeasdata[VISU_SIL].ReqPorts.pLsdLightObjectList,     NULL);}
  if(m_hlaMeasdata[VISU_SIL].ReqPorts.pLsdLightList)           {m_algoServices.pfMeasFreeze(&SilHlaReqPortLsdLightListMeasInfo,       m_hlaMeasdata[VISU_SIL].ReqPorts.pLsdLightList,           NULL);}

  /* Run Algo */
  err = HlaExec((const reqHlaPrtList_t*)&m_hlaMeasdata[VISU_SIL].ReqPorts, (proHlaPrtList_t*)&m_hlaMeasdata[VISU_SIL].ProPorts, &m_algoServices);

  /* Clean-up DLL errors stack for the first 3 frames in run mode */
  if(   (m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData != NULL)
     && (m_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData->eOpMode == BASE_OM_RUN)
     //TODO: && (m_hlaMeasdata[VISU_SIL].ProPorts.pHlar_ObjList != NULL)
     //&& (m_hlaMeasdata[VISU_SIL].ProPorts.pHlar_ObjList->sSigHeader.uiCycleCounter < 4u)
    )
  {
    //TODO can be removed?
    //(void)memset((void*)m_hlaMeasdata[VISU_SIL].hlaInternMeasdata.pHlaErrorStack, 0, sizeof(*(m_hlaMeasdata[VISU_SIL].hlaInternMeasdata.pHlaErrorStack)));
  }

  /* Trigger HIL execution if corresponding configuration is loaded*/
  if (m_EnableHil.val() != 0)
  {
    TriggerHil();
  }

  return err;
}


void CSimHeadLightAssist::GenerateHotPixels(ImageU16_t* pImageOdd)
{
#if (HLA_ENABLE_HOT_PIXELS_SIMULATION == SWITCH_ON )
  int i;
  float32 f;
  uint32 w;
  uint32 h;
  uint32 x0;
  uint32 y0;
  uint32 step;
  uint32 offset;
  sint32 numProdHotPixel;

  /* copy odd raw image to separate buffer  */
  CopyRTEData( (void**)&HotPixelsImageOdd,
               (const void*)pImageOdd->aImageData,
               CML_Min(IMAGE_MAX_NUM_PIXEL, sizeof(uint16) * pImageOdd->sImgHeader.uiHeight * pImageOdd->sImgHeader.uiWidth)
              );
  /* connect separate buffer to RTE */
  pImageOdd->aImageData = HotPixelsImageOdd;
 

  /* init hot pixels */
  if(ImagerDefectPix[0].ui16_xPos==0)
  {
    /* dynamic hot pixels list inside HLA roi */
    f = 1.0f/6.0f;
    w = (uint32)(simData_MTSRoiWidth*(1-2*f));
    h = (uint32)(simData_MTSRoiHeight*(1-2*f));
    x0 = (uint32)(simData_MTSRoiX1 + simData_MTSRoiWidth*f);
    y0 = (uint32)(simData_MTSRoiY1 + simData_MTSRoiHeight*f);

    step = (w*h)/(HLA_HOT_PIXELS_SIMULATION_NUM);
    offset = 0;

    for(i=0;i<HLA_HOT_PIXELS_SIMULATION_NUM;i++)
    {
      /* absolute imager coordinate system on red pixel */
      ImagerDefectPix[i].ui16_xPos = ((x0 + offset%w)/2)*2-1;
      ImagerDefectPix[i].ui16_yPos = ((y0 + offset/w)/2)*2;
      ImagerDefectPix[i].ui16_Count = 0;
      ImagerDefectPix[i].e_DefectType = RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX;

      offset += step;
    }

    /* simulate some production red hot pixels inside cropped roi */
    numProdHotPixel = 10;
    f = 1.0f/6.0f;
    w = (uint32)(m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Width*(1-2*f));
    h = (uint32)(m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Height*(1-2*f));
    x0 = (uint32)(m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_X + m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Width*f);
    y0 = (uint32)(m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Y + m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Height*f);

    if(numProdHotPixel>0)
    {
      step = (w*h)/(numProdHotPixel);
      offset = 0;

      m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectsListLength = 0;
      for(i=0; i<numProdHotPixel ; i++)
      {
        /* absolute imager coordinate system on red pixel */
        m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].xPos = ((x0 + offset%w)/2)*2-1;
        m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].yPos = ((y0 + offset/w)/2)*2;
        m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].Count = 0;
        m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].DefectType = RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX;

        m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectsListLength++;

        offset += step;
      }
    }


  }

  /* incrust dynamic hot pixels inside image buffer */
  for(i=0;i<HLA_HOT_PIXELS_SIMULATION_NUM;i++)
  {
    if(ImagerDefectPix[i].ui16_xPos != 0)
    {
      switch(ImagerDefectPix[i].e_DefectType)
      {
      case RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX: /* red and hot pixels */
        HotPixelsImageOdd[(ImagerDefectPix[i].ui16_yPos - m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Y) * m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Width
          + (ImagerDefectPix[i].ui16_xPos - m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_X)] = 4000; 
        break;          
      }
    }
  }

  /* incrust red hot pixels from production inside image buffer */
  for(i=0; i<m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectsListLength ; i++)
  {
    if(m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].DefectType == RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX)
    {
      HotPixelsImageOdd[(m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].yPos - m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Y) * m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_Width
        + (m_hlaMeasdata[VISU_SIL].ReqPorts.pNvm_SigLearningValues->DefectPixel.DefectList[i].xPos - m_hlaMeasdata[VISU_SIL].ReqPorts.pSig_ImgCharOdd->s_ImagerCroi.ui16_X)] = 4000; 
    }
  }

  /* remove hot pixel after 1500 frames */
  if(debugViewFrameCounter > 1500)
  {
    ImagerDefectPix[5].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[10].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[20].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[30].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[45].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[60].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[78].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[83].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[85].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[89].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
  }

  if(debugViewFrameCounter > 3000)
  {
    ImagerDefectPix[0].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[1].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[2].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[15].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[25].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[35].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[42].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[52].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[55].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
    ImagerDefectPix[77].e_DefectType = RTE_HLAR_DEFECT_PIXEL_PIX_OK ;
  }
#endif
}

/* Init the simulation with data from recording */
void CSimHeadLightAssist::SimuInit(void)
{
  /* Make sure that HIL init gets triggered */
  m_isHilInitNeeded = TRUE;

}


void CSimHeadLightAssist::TriggerHil()
{
  /* Create reqPorts pointers that point to corresponding buffers in m_Mts2Hil */
  SimHlaReqPrtList_t pReqPorts_Mts2Hil;
  LinkBuffersReqPorts(pReqPorts_Mts2Hil, m_Mts2Hil.reqPortBuffers);

  /* Copy reqPorts data to EVM HIL transfer buffer */
  CopyRTEInputData(pReqPorts_Mts2Hil, m_hlaMeasdata[VISU_EVM].ReqPorts);

  /* Init data */
  /* Make sure that HIL init gets triggered */
  if(m_isHilInitNeeded)
  {
    m_Mts2Hil.isHilInitNeeded = b_TRUE;
  }
  else
  {
    m_Mts2Hil.isHilInitNeeded = b_FALSE;
  }
  m_isHilInitNeeded = b_FALSE;

  /* Trigger EVM HIL client in an nonblocking way */
  m_pSimPlgBase->TriggerEvent("TriggerHil", 0, 0);

  /* Wait for EVM HIL client. This is a blocking call */
  m_pSimPlgBase->TriggerEvent("Wait4Hil", 0, 0);

  /* Once HIL has finished receive port is dirty */
  if( m_Hil2MtsPort.isDirty() )
  {
    FILE* pFile;
    std::stringstream filePath;

    /* Set active flag for visu */
    m_Hil2Mts.bHilActive = b_TRUE;

    /* Freeze some data for creating MTS exports and performance reports */
    m_algoServices.pfMeasFreeze(&HilHlaAlgoCompStateMeasInfo,   m_hlaMeasdata[VISU_EVM].ProPorts.pAlgoCompState, NULL);
    m_algoServices.pfMeasFreeze(&HilHlaEvmRtaBufferMeasInfo,    &m_Hil2Mts.rtaBuffer,                            NULL);
    m_algoServices.pfMeasFreeze(&HilHlaEvmRtaBufferEveMeasInfo, &m_Hil2Mts.rtaBufferEve,                         NULL);

    if(m_maxNumMeasfreezedBytes < m_Hil2Mts.hlaErrorStack.measfreezeAmount)
    {
      m_maxNumMeasfreezedBytes = m_Hil2Mts.hlaErrorStack.measfreezeAmount;

      /* Store amount of measfreezed data */
      filePath << GetDllFilePath() << "/../../../../../05_Test_Environment/algo/inttests/MeasfreezeTests/hla/maxNumMeasfreezedBytes.log";
      pFile = fopen(filePath.str().c_str(), "w");
      if(pFile != NULL)
      {
        fprintf(pFile, "%u", m_maxNumMeasfreezedBytes);
        fclose(pFile);
      }
    }
  }
  m_Hil2MtsPort.setNotDirty();

  /* Make sure that reset on HIL algo is done only once */
  m_Mts2Hil.isHilResetNeeded = b_FALSE;
}

