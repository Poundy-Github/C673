/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla

MODULNAME:            sim_swc_hla.h

DESCRIPTION:          SWC plugin for Head Light Assist

AUTHOR:               Mihai Anghel

CREATION DATE:        26.02.2009

VERSION:              $Revision: 1.8.1.1 $
**************************************************************************** */
#ifndef __SIM_SWC_HLA_H__
#define __SIM_SWC_HLA_H__

#define CONV_I32VERSION_TO_TUPPLE(x)   (((x) >> 16) & 0xFF), (((x) >> 8) & 0xFF), ((x) & 0xFF)

/* includes ---------------------------------------------------------------- */

#include "sim_headlightassist.h"
#include "sim_versioninfo_impl.h"
#include "sim_swc_cycleinfo.h"
#include "sim_swc_synchronization.h"
#include "sim_swc_draw_base.h"
#include "sim_swc_dbg_exc.h"
#include "sim_hla_ethernet.h"
#include "sim_hla_can.h"

/* main class -------------------------------------------------------------- */
class CSimSwcHLA : public CSimSwcDrawBase
  , public CSimSwcCycleInfo
  , public CSimHeadLightAssist
  , public CSimSwcDebugExc 
  , public CSimSwcSynchronization<Hla_SyncRef_t>
  , public CSimHlaEthernet
  , public CSimHlaCan
{
public:
  CSimSwcHLA();
  ~CSimSwcHLA();

  //This Functions are to connect to the Simulation MO (Virtual Function Bus)
  static void Init(void* plgID, long param1, long param2);
  static void Reset(void* plgID, long param1, long param2);
  static void CollectRecFileName(void* plgID, long param1, long param2);
  static void Doit(void* plgID, long param1, long param2);
  static void DrawFunction1(void* PlgID, long Param1, long /*Param2*/);
  static void DrawFunction2(void* PlgID, long Param1, long /*Param2*/);
  
private:
  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE;
  static const char* CP_DISTRIBUTEOUTPUTDATA;
  /// @}

  void Doit(void); //!This function is the local event function for image data
  void Init(void); //!This function is called by the MO to initialize the algorithm
  void Reset(void); //!This function is called by the MO to reset the algorithm

  void RunAlgo(void); //!This function is the event function for data ports
  void RunAlgoWithFPUExceptions(void);

  void DrawFunction1(const ISimRenderContext* pContext);
  void DrawFunction2(const ISimRenderContext* pContext);

  void AddReceivePorts(void);

  void FormatString(char* dstString, char* fmt, ...); 

  char m_szRecFile[512];     /* rec-file name incl. full path           */
  char m_szRecFileName[512]; /* rec-file name, without path and ".rec"  */
  char m_szRecFilePath[512]; /* rec-file path, without rec-file name    */
  char m_szDllFile[512];     /* dll file name incl. full path           */
  char m_szDllFilePath[512]; /* dll file path, without dll-file name    */

  bool m_bResetNeeded;
  bool m_bInitNeeded;
  AlgoDataTimeStamp_t old_uiTimeStamp_Image_us;
  AlgoCycleCounter_t  old_uiMeasurementCounter;

  std::string m_ssOldRecFile;

  /* RTE inputs, reqports */
  RteSimReceivePort<BaseCtrlData_t,                 simOPAQUE_t>    m_rpCtrlData;
  SimReceivePortBuffered<CPAR_HLAF_Parameter_t,     simOPAQUE_t>    m_rpCPAR_HLAF_Parameter;
  SimReceivePortBuffered<MonoCalibration_t,         simOPAQUE_t>    m_rpMonoCalibration;
  SimReceivePortBuffered<HLA_BusInputSignals_t,     simOPAQUE_t>    m_rpHlaBusInputSignals;
  SimReceivePortBuffered<HLA_RadarObjectList_t,     simOPAQUE_t>    m_rpHlaRadarObjectList;
  SimReceivePortBuffered<VehSig_t,                  simOPAQUE_t>    m_rpVehSig;
  SimReceivePortBuffered<VehDyn_t,                  simOPAQUE_t>    m_rpVehDyn;
  SimReceivePortBuffered<CB_t_ProvidedOutputs_t,    simOPAQUE_t>    m_rpCBProvidedOutputs;
  SimReceivePortBuffered<EM_t_GenObjectList,        simOPAQUE_t>    m_rpEMObjectsList;
  SimReceivePortBuffered<LSD_EnvironmentData_t,     simOPAQUE_t>    m_rpLsdEnvironment;
  SimReceivePortBuffered<LSD_LightObjectList_t,     simOPAQUE_t>    m_rpLsdLightObjectList;
  SimReceivePortBuffered<LSD_LightList_t,           simOPAQUE_t>    m_rpLsdLightList;

  /* RTE outputs, proports */
  SimReceivePortBuffered<AlgoCompState_t,             simOPAQUE_t> m_rpAlgoCompState;
  SimReceivePortBuffered<RTE_HLAF_HeadlightControl_t, simOPAQUE_t> m_rpHLAF_HeadlightControl;

  /* HLA internal meas freeze */
  SimReceivePort<t_ErrorHandling_ErrorStack, simOPAQUE_t> m_rpHLA_ErrorStack;

  /* Parameter Ports */
  SimReceivePort<sint8, simI8_t> m_rpOverwriteInputParameterPort;

  CRITICAL_SECTION m_criticalSection;

  bool OnMouseMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
  {
    return CSimHlaVisu::OnMouseMessage(context, windowMessage);
  }
  bool OnKeyboardMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
  {
    return CSimHlaVisu::OnKeyboardMessage(context, windowMessage);
  }
  bool OnWindowMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
  {
    return CSimHlaVisu::OnWindowMessage(context, windowMessage);
  }


  void CollectRecFileName(void);

  virtual const char* GetRecFile()
  {
    return m_szRecFile;/* rec-file name incl. full path */
  }
  virtual const char* GetRecFileName()
  {
    return m_szRecFileName;/* rec-file name, without path and ".rec" */
  }
  virtual const char* GetRecFilePath()
  {
    return m_szRecFilePath;/* rec-file path, without rec-file name */
  }
  virtual const char* GetDllFile()
  {
    return m_szDllFile;/* dll file name incl. full path           */
  }
  virtual const char* GetDllFilePath()
  {
    return m_szDllFilePath;/* dll file path, without dll-file name    */
  }
};
#endif
/* ------------------------------------------------------------------------ */
/* EoF */