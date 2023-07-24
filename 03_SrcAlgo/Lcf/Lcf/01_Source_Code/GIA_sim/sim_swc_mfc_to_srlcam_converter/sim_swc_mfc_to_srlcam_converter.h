/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#ifndef sim_swc_mfc_to_srlcam_converter_h__
#define sim_swc_mfc_to_srlcam_converter_h__

#include "sim_swc_base.h"
#include "sim_swc_draw_base.h"
#include "sim_swc_meas.h"
#include "sim_swc_cdl.h"
#include "sim_swc_cycleinfo.h"
#include "sim_swc_dbg_exc.h"
#include "sim_versioninfo_impl.h"
#include "simReceivePort.h"
#include "sim_algo_service_types.h"
#include "gia_measfreeze_data.h"

//#include "sim_swc_MfcToSrlcamConverter_algo_headers.h"
#include "Rte_Ext_Type.h"
#include "Rte_type.h"

#include <map>

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimMfcToSrlcamConverter 
  : public CSimSwcDrawBase
  , public CSimSwcMeas
  , public CSimSwcCDL
  , public CSimSwcDebugExc
  , public CSimSwcCycleInfo
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimMfcToSrlcamConverter();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimMfcToSrlcamConverter();

  /// @name Static server port methods
  /// @{

  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimMfcToSrlcamConverter*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void Init(void* PlgID, long, long) { reinterpret_cast<CSimMfcToSrlcamConverter*>(PlgID)->Init(); }

  /// Server port "Doit" class method stub, calls directly the instance method
  static void Doit(void* PlgID, long, long) { reinterpret_cast<CSimMfcToSrlcamConverter*>(PlgID)->Doit(); }
  
  // @}

  void ReplaceImagerCroiOdd();
  void ReplaceImagerCroiEven();

private:

  static const long          CYLCE_ID                 = TASK_ID_GIA;//TASK_ID_MfcToSrlcamConverter;

  /// List of cycles, this plugin sends output to. 
  static const DWORD CYCLE_INFO_ARR[1];

  /// Flag that defines whether the Input Check will be run in current cycle
  bool m_bCheckInput;  

  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE;
  static const char* CP_DISTRIBUTEONLYDIRTYPORTS;
  /// @}

  /// @name provide port names
  /// @{
  static const char* PP_IC_IMG_CHAR_ODD;
  static const char* PP_IC_IMG_CHAR_EVEN;
  static const char* PP_IMAGE_ODD;
  static const char* PP_IMAGE_EVEN;
  static const char* PP_ALGO_COMP_STATE;
  /// @}

  /// @name provide ports
  /// @{
  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name receive ports
  /// @{
  SimReceivePort<BaseCtrlData_t,                simOPAQUE_t>       m_rpBaseCtrlData;
  SimReceivePort<IcImageCharacteristics_t,      simOPAQUE_t>       m_rpIcImgCharOdd;
  SimReceivePort<IcImageCharacteristics_t,      simOPAQUE_t>       m_rpIcImgCharEven;
  SimReceivePort<ImageU16_t*,                   simREFERENCE_t>    m_rpImageOdd;
  SimReceivePort<ImageU16_t*,                   simREFERENCE_t>    m_rpImageEven;

  /// Map type representing additional data per port
  typedef std::vector<SimReceivePortBase*> ReceivePortMap_t;

  /// Available receive ports with additional data
  ReceivePortMap_t m_receivePortMap;
  /// @}


  /// @name provide ports
  /// @{
  AlgoCompState_t                 m_ppAlgoCompState;
  IcImageCharacteristics_t        m_ppIcImgCharOdd;
  IcImageCharacteristics_t        m_ppIcImgCharEven;
  ImageU16_t*                     m_ppImageOdd;
  ImageU16_t*                     m_ppImageEven;
  IcRect_t                        m_CropResultOdd;
  IcRect_t                        m_CropResultEven;
  /// @}

  void Reset();
  void Init();
  void Doit();
  void MainCall();
  void CheckPortsDataReceived();
  void SetupPorts();
  void ResetReceivePorts();

  IcRect_t CropOddImage();
  IcRect_t CropEvenImage();

  MEASReturn_t MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback);
  void MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size);

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);
};

#endif // sim_swc_mfc_to_srlcam_converter_h__
