/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_swc_lcf_sen.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision
  
**************************************************************************** */

#ifndef sim_swc_lcf_sen_h__
#define sim_swc_lcf_sen_h__

#include "sim_swc_base.h"
#include "sim_swc_meas.h"
#include "sim_swc_cdl.h"
#include "sim_swc_draw_base.h"
#include "sim_versioninfo_impl.h"
#include "sim_swc_cycleinfo.h"
#include "sim_swc_dbg_exc.h"
#include "sim_swc_synchronization.h"
#include "simReceivePort.h"
#include "sim_algo_service_types.h"
#include "lcf_sen_ext.h"
#include "lcf_sen_main.h"
#include "sim_lcf_sen_types.h"
#include "algo_glob.h"

#include <map>

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimLcfSen 
  : public CSimSwcDrawBase
  , public CSimSwcCDL
  , public CSimSwcMeas
  , public CSimSwcDebugExc
  , public CSimSwcCycleInfo
  , public CSimSwcSynchronization<LcfSen_SyncRef_t>
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimLcfSen();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimLcfSen();

  /// @name Static server port methods
  /// @{

  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimLcfSen*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void Init(void* PlgID, long, long) { reinterpret_cast<CSimLcfSen*>(PlgID)->Init(); }

  /// Server port "Doit" class method stub, calls directly the instance method
  static void DoitSen(void* PlgID, long, long) { reinterpret_cast<CSimLcfSen*>(PlgID)->DoitSen(); }
  
  // @}

private:
  static CSimLcfSen* s_pInstance; ///< Plugin instance required by the static meas freeze methods
  
  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE_SEN;
  static const char* CP_DISTRIBUTEOUTPUTDATA_SEN;
  /// @}

  /// @name provide port names
  /// @{
  static const char* PP_LCF_SEN_ALGO_COMP_STATE;
  static const char* PP_LCF_SEN_OUTPUT;
  static const char* PP_LCF_SEN_OUTPUT_TO_VEH;
  static const char* PP_LCF_SEN_DEBUG_DATA;
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name provide ports
  /// @{
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name receive ports
  /// @{
  RteSimReceivePort       <BaseCtrlData_t,           simOPAQUE_t>    m_rpBaseCtrlData;
  /*SimReceivePortBuffered  <EM_t_CamObjectList,       simOPAQUE_t>    m_rpCamObjectList;*/
  SimReceivePort           <EM_t_CamObjectList,      simOPAQUE_t>    m_rpCamObjectList;
  /*SimReceivePortBuffered  <EM_t_GenObjectList,       simOPAQUE_t>    m_rpGenObjectList;*/
  SimReceivePort           <EM_t_GenObjectList,      simOPAQUE_t>    m_rpGenObjectList;
  SimReceivePortBuffered  <LCF_GenericInputs_t,      simOPAQUE_t>    m_rpLcfSenInputData;
#if defined(LCF_SEN_RPORT_PLCFLADMCIUCTOSOC)
  /*SimReceivePortBuffered  <LCF_LaDmcIucToSoc_t,      simOPAQUE_t>    m_rpLcfSenLaDmcIucToSoc;*/
  SimReceivePort           <LCF_LaDmcIucToSoc_t,      simOPAQUE_t>    m_rpLcfSenLaDmcIucToSoc;
#endif
  SimReceivePortBuffered  <LCF_VehToSen_t,           simOPAQUE_t>    m_rpLcfSenInputFromVehData;
  SimReceivePortBuffered  <LCF_VehGenericOutputs_t,  simOPAQUE_t>    m_rpLcfVehOutputData;
  SimReceivePortBuffered  <VehPar_t,                 simOPAQUE_t>    m_rpVehParSen;
  SimReceivePortBuffered  <VehSig_t,                 simOPAQUE_t>    m_rpVehSigSen;
  SimReceivePortBuffered  <VehDyn_t,                 simOPAQUE_t>    m_rpVehDynSen;
#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
  /*SimReceivePortBuffered  <HLA_RadarObjectList_t,    simOPAQUE_t>    m_rpHlaRadarObjectList;*/
  SimReceivePort          <HLA_RadarObjectList_t,    simOPAQUE_t>    m_rpHlaRadarObjectList;
#endif
#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
  /*SimReceivePortBuffered  <CB_t_ProvidedOutputs_t,   simOPAQUE_t>    m_rpCbOutputs;*/
  SimReceivePort          <CB_t_ProvidedOutputs_t,    simOPAQUE_t>    m_rpCbOutputs;
#endif
#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
  /*SimReceivePortBuffered  <LSD_EnvironmentData_t,    simOPAQUE_t>    m_rpLsdEnvironmentData;*/
  SimReceivePort          <LSD_EnvironmentData_t,    simOPAQUE_t>    m_rpLsdEnvironmentData;
#endif
  SimReceivePortBuffered  <AbdOutputData_t,          simOPAQUE_t>    m_rpAbdOutputDataSen;
  /*SimReceivePortBuffered  <CPAR_LCF_TunParamsLDP_t,  simOPAQUE_t>    m_rpCParLdp;*/
  SimReceivePort          <CPAR_LCF_TunParamsLDP_t,  simOPAQUE_t>    m_rpCParLdp;
  /*SimReceivePortBuffered  <CPAR_LCF_TunParamsLKA_t,  simOPAQUE_t>    m_rpCParLka;*/
  SimReceivePort          <CPAR_LCF_TunParamsLKA_t,  simOPAQUE_t>    m_rpCParLka;

  /// @name provide ports
  /// @{
  AlgoCompState_t                   m_ppLcfSenAlgoCompState;
  LCF_SenGenericOutputs_t           m_ppLcfSenOutputData;
  LCF_SenToVeh_t                    m_ppLcfSenOutputToVehData;
  LCF_SenDebugData_t		   		m_ppLCF_SenDebugData;
  /// @}
  
  /// @name algo frame simulation data
  /// @{
  sim::as::CServiceTypes m_algoServiceSen;
  
  /// @}

  /// List of cycles, this plugin sends output to. 
  static const DWORD  CYCLE_INFO_ARR[1];
  
  /* the request port pointer struct */
  reqLcfSenPrtList_t m_reqSenPortList;

  /* the provide port pointer struct */
  proLcfSenPrtList_t m_proSenPortList;

  void Reset();
  void Init();
  void DoitSen();
  void SetupPortsSen();
  void MainCallSen();
  
  void TriggerHIL(const reqLcfSenPrtList_t *reqPorts, const proLcfSenPrtList_t *proPorts);
  MEASReturn_t MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback);
  void MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size);

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);
  
  struct
  {
    sint32                   iUseHil;
    sint32                   iProvideHilResults; /* iProvideHilResults == 0, so m_proPortList contains outputs of simulation and iProvideHilResults == 1, then m_proPortList contains outputs of HIL*/
    hil_PortBuffer_mts2hil_t PortBuffer_mts2hil;
    hil_PortBuffer_hil2mts_t PortBuffer_hil2mts;
  } m_hil;
  
};

#endif // sim_swc_lcf_sen_h__
