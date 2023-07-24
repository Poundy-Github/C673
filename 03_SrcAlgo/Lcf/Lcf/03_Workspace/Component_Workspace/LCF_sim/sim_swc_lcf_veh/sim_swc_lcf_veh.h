/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_swc_lcf_veh.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision
  
**************************************************************************** */

#ifndef sim_swc_lcf_veh_h__
#define sim_swc_lcf_veh_h__

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
#include "lcf_veh_ext.h"
#include "lcf_veh_main.h"
#include "sim_lcf_veh_types.h"
#include "algo_glob.h"

#include <map>

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimLcfVeh 
  : public CSimSwcDrawBase
  , public CSimSwcCDL
  , public CSimSwcMeas
  , public CSimSwcDebugExc
  , public CSimSwcCycleInfo
  , public CSimSwcSynchronization<LcfVeh_SyncRef_t>
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimLcfVeh();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimLcfVeh();

  /// @name Static server port methods
  /// @{

  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimLcfVeh*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void Init(void* PlgID, long, long) { reinterpret_cast<CSimLcfVeh*>(PlgID)->Init(); }

  /// Server port "Doit" class method stub, calls directly the instance method
  static void DoitVeh(void* PlgID, long, long) { reinterpret_cast<CSimLcfVeh*>(PlgID)->DoitVeh(); }
  
  // @}

private:
  static CSimLcfVeh* s_pInstance; ///< Plugin instance required by the static meas freeze methods
  
  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE_VEH;
  static const char* CP_DISTRIBUTEOUTPUTDATA_VEH;
  /// @}

  /// @name provide port names
  /// @{
  static const char* PP_LCF_VEH_ALGO_COMP_STATE;
  static const char* PP_LCF_VEH_OUTPUT;
  static const char* PP_LCF_LADMOC_SOCTOIUC_OUTPUT;
  static const char* PP_LCF_VEH_OUTPUT_TO_SEN;
  static const char* PP_LCF_VEH_DEBUG_DATA;
  #ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
  static const char* PP_LCF_VEH_NVMLEARN_DATA;
  #endif
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name provide ports
  /// @{
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name receive ports
  /// @{
  RteSimReceivePort       <BaseCtrlData_t,            simOPAQUE_t>    m_rpBaseCtrlData;
  SimReceivePortBuffered  <LCF_GenericInputs_t,       simOPAQUE_t>    m_rpLcfVehInputData;
#if defined(LCF_VEH_RPORT_PLCFLADMCIUCTOSOC)
  SimReceivePortBuffered  <LCF_LaDmcIucToSoc_t,       simOPAQUE_t>    m_rpLcfVehLaDmcIucToSoc;
#endif
  SimReceivePortBuffered  <LCF_SenToVeh_t,            simOPAQUE_t>    m_rpLcfVehInputFromSenData;
  SimReceivePortBuffered  <LCF_SenGenericOutputs_t,   simOPAQUE_t>    m_rpLcfSenOutputData;
  SimReceivePortBuffered  <VehPar_t,                  simOPAQUE_t>    m_rpVehParVeh;
  SimReceivePortBuffered  <VehSig_t,                  simOPAQUE_t>    m_rpVehSigVeh;
  SimReceivePortBuffered  <VehDyn_t,                  simOPAQUE_t>    m_rpVehDynVeh;
  SimReceivePortBuffered  <VDYOffsets_t,              simOPAQUE_t>    m_rpVdyOffsetsVeh;
  #ifdef ABD_OUTPUT_DATA_INTFVER
  SimReceivePortBuffered  <AbdOutputData_t,           simOPAQUE_t>    m_rpAbdOutputDataVeh;
  #endif
  SimReceivePortBuffered  <CPAR_LCF_TunParamsKMC_t,   simOPAQUE_t>    m_rpCParKmc;
  SimReceivePortBuffered  <CPAR_LCF_TunParamsDMC_t,   simOPAQUE_t>    m_rpCParDmc;
  #ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
  SimReceivePortBuffered  <NVM_LcfLearningData_t,     simOPAQUE_t>    m_rpNvmLcfDataVeh;
  #endif
  /// @name provide ports
  /// @{
  AlgoCompState_t                   m_ppLcfVehAlgoCompState;
  LCF_VehGenericOutputs_t           m_ppLcfVehOutputData;
  LCF_LaDmcSocToIuc_t               m_ppLcfLaDmcSocToIuc;
  LCF_VehToSen_t                    m_ppLcfVehOutputToSenData;
  #ifdef LCF_VEH_PPORT_PNVMLCFDATA  //TODO: delete this line in next release
  NVM_LcfLearningData_t             m_ppNvmLcfDataVeh;
  LCF_VehDebugData_t		   		m_ppLCF_VehDebugData;

  #endif
  /// @}
  
  /// @name algo frame simulation data
  /// @{
  sim::as::CServiceTypes m_algoServiceVeh;
  /// @}

  /// List of cycles, this plugin sends output to. 
  static const DWORD  CYCLE_INFO_ARR[1];
  
  /* the request port pointer struct */
  reqLcfVehPrtList_t m_reqVehPortList;

  /* the provide port pointer struct */
  proLcfVehPrtList_t m_proVehPortList;

  void Reset();
  void Init();
  void DoitVeh();
  void SetupPortsVeh();
  void MainCallVeh();
  
  void TriggerHIL(const reqLcfVehPrtList_t *reqPorts, const proLcfVehPrtList_t *proPorts);
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

#endif // sim_swc_lcf_veh_h__
