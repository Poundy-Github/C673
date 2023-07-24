/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#ifndef sim_swc_mfc_wrapper_h__
#define sim_swc_mfc_wrapper_h__

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

//#include "./Converter/HLA/hla_type.h"
#include "sim_hlar_input_data.h"
#include "sim_hla_mfc300rtewrp.h"
#include "sim_swc_MfcWrapper_algo_headers.h"

//#include "sim_algo_service_types.h"

#include "Rte_Ext_Type.h"
#include "Rte_type.h"
//#include "algo_glob.h"
//#include "glob_type.h"

// timestamp fix
#include "sim_swc_image_timestamp_fix.h"

// Remove disturbing macros from glob_type.h
#undef C_PI
#undef C_F32_DELTA
#undef DEG2RAD
#undef RAD2DEG
#undef SQR
#undef iABS
#undef fABS
#undef fSIGN
#undef GET_BIT
#undef SET_BIT
#undef CLEAR_BIT
#undef F32_IS_ZERO
#undef F32_IS_NZERO
#undef ROUND
#undef MIN
#undef MAX
#undef MINMAX
#include "cml_ext_cpp.h"

#include <map>

/// Class representing a SIM plugin to the SIM VFB MO in MTS
class CSimMfcWrapper 
  : public CSimSwcBase
  , public CSimSwcMeas
  , public CSimSwcCDL
  , public CSimSwcDebugExc
  , public CSimSwcCycleInfo
{
public:
  /// Constructor of the class.
  /// Gets called when the plugin is loaded.
  CSimMfcWrapper();

  /// Destructor of the class.
  /// Gets called when the plugin is unloaded.
  ~CSimMfcWrapper();

  /// @name Static server port methods
  /// @{

  /// Server port "Init" class method stub, calls directly the instance method
  static void Reset(void* PlgID, long, long) { reinterpret_cast<CSimMfcWrapper*>(PlgID)->Reset(); }

  /// Server port "Init" class method stub, calls directly the instance method
  static void Init(void* PlgID, long, long) { reinterpret_cast<CSimMfcWrapper*>(PlgID)->Init(); }

  /// Server port "Doit" class method stub, calls directly the instance method
  static void Doit(void* PlgID, long, long) { reinterpret_cast<CSimMfcWrapper*>(PlgID)->Doit(); }
  static void DoitImage(void* PlgID, long, long) { reinterpret_cast<CSimMfcWrapper*>(PlgID)->DoitImage(); }

  MEASReturn_t MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback);
  void MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size);
  
  // @}

  /// @name MFC4xx receive ports
  /// @{
  SimReceivePort<BaseCtrlData_t,                 simOPAQUE_t>      m_rpBaseCtrlData;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteCroiCal;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteSroiCal;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteCroiCalSemo;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteCroiCalEmo;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteRroiCalEmo;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteImagerCalEmo;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteCroiCalEol;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteIcIcOddRight;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteIcIcOddLeft;
  SimReceivePort<IcRect_t,                       simOPAQUE_t>      m_rpRteIcCommonCroiLeft;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteIcsr;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteFlspCalIntrDistRight;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteFlspProdData;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteFlspProdIntrRight;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteSacStereoCal;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteFexCtrlOutput;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteVehPar;
  SimReceivePort<void*,                          simREFERENCE_t>   m_rpRteVehSig;

  //neu von liste
  // NVM Signals
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmLd;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmSr;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmEcm;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmHla;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmTsa;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmSac;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteNvmEmo;

  // CPAR Signals
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparAldw;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparEcm;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparEmo;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparEmoOrigin;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparHlaF;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparHlaR;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparHla;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparSr;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparSac;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteCparTsa;

  //FLSP Signals
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFlspImagerCharRight;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFlspProductionIntrinsicLeft;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFlspStereoCallIntrinsicsLeft;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFlspStereoCallIntrinsicsRight;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFlspStereoCalTransRot;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFlspTemperatureCompensationList;
  
  //Dynamic signals
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteIcIcEvenRight;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteIcImageStatisticEven;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteFCTAldwInputGen;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteDIMInputCustom;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteDIMInputGeneric;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteHEADInputCustom;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteHEADInputGeneric;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteHMIInputData;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteTsaInputGPS;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteTsaCustomInput;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteEcuStateM3_0;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteSacStereoRoiM3_10;
                                                  
  //HLA
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteParPPAR_ImgCharRight;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteParPPAR_RespCurveRight;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteSig_HlaSig;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpRteSig_HeadlightState;
  SimReceivePort<void*,              simREFERENCE_t>    m_rpMonoCalibrationLaneImager;

  typedef struct
  {
    uint32    e_sigStat;
    float32   f32_X;
    float32   f32_Y;
    float32   f32_Z;
    uint32    ui32_Quality;
  } s_SensorSocket;

  typedef struct
  {
    uint32    e_sigStat;
    float32   f32_Pitch;
    float32   f32_Roll;
    float32   f32_Yaw;
    uint32    ui32_Quality;
  } s_SensorAngles;


  /// @name MFC310 data input
  /// @{
  SimReceivePort< mfc310::stereo::SACImageData_t,                    simOPAQUE_t > m_rp310CroiImageData;
  SimReceivePort< mfc310::stereo::SACMountingCalibrationData_t,      simOPAQUE_t > m_rp310SacMountingData;
  SimReceivePort< mfc310::stereo::SACMeasIntrinsicCalibrationData_t, simOPAQUE_t > m_rp310SacIntrinsicRight;
  SimReceivePort< mfc310::stereo::SACMeasIntrinsicCalibrationData_t, simOPAQUE_t > m_rp310SacIntrinsicLeft;
  SimReceivePort< mfc310::stereo::SACMeasRectCamPars_t,              simOPAQUE_t > m_rp310Sac;
  SimReceivePort< mfc310::ic::ICEXP_S_Output,                        simOPAQUE_t > m_rp310IcicOdd;
  SimReceivePort< mfc310::ic::ICEXP_S_Output,                        simOPAQUE_t > m_rp310IcicEven;
  SimReceivePort< mfc310::ic::IC_S_ResultsPart2,                     simOPAQUE_t > m_rp310Icop2;
  SimReceivePort< mfc310::ic::IC_S_EmbeddedStatData,                 simOPAQUE_t > m_rp310Icesd;
  SimReceivePort< uint16,                                            simUI16_t   > m_rp310SlopeRatioR1;
  SimReceivePort< float32,                                           simF32_t    > m_rp310Blacklevel;
  SimReceivePort< mfc310::stereo::SACMeasObjLUTLeft,                 simOPAQUE_t > m_rp310SacMeasObjLutLeft;
  SimReceivePort< mfc310::stereo::SACMeasObjLUTRight,                simOPAQUE_t > m_rp310SacMeasObjLutRight;
  SimReceivePort< mfc310::stereo::SACImageData_t,                    simOPAQUE_t > m_rp310SacSRoiImageDataLeft;
  SimReceivePort< mfc310::stereo::SACImageData_t,                    simOPAQUE_t > m_rp310SacSRoiImageDataRight;
  SimReceivePort< float32,                                           simF32_t    > m_rp310LdCamDistortionK1;
  SimReceivePort< float32,                                           simF32_t    > m_rp310LdCamDistortionK2;
  SimReceivePort< mfc310::sr::SRIFInputConfig_t,                     simOPAQUE_t > m_rp310SrInputConfig;
  SimReceivePort< mfc310::stereo::TempArray_t,                       simOPAQUE_t > m_rp310SacTemperatures;
  SimReceivePort< mfc310::ld::S_LDParameterInOut,                    simOPAQUE_t > m_rp310LdParameterInOut;
  SimReceivePort< mfc310::stereo::FromToNVM_t,                       simOPAQUE_t > m_rp310SacNvm;
  SimReceivePort< mfc310::stereo::SACStatistics_t,                   simOPAQUE_t > m_rp310SacStatistics;
  SimReceivePort< mfc310::stereo::SACNvAngleData_t,                  simOPAQUE_t > m_rp310SacAngleData;
  SimReceivePort< s_SensorSocket,                                    simOPAQUE_t > m_rp310EcmSensorSocket;
  SimReceivePort< s_SensorAngles,                                    simOPAQUE_t > m_rp310EcmSensorAngles;
  SimReceivePort< mfc310::stereo::SACExtrinsicCalibrationData_t,     simOPAQUE_t > m_rp310SacExtRightToLeft;

  SimReceivePort< uint16,                                            simUI16_t   > m_rp310SacParamIdLUTLeft;
  SimReceivePort< uint16,                                            simUI16_t   > m_rp310SacParamIdLUTRight;

  // Sac extrinsic left to right single signals
  SimReceivePort< float32,                                           simF32_t    > m_rp310SacExtRightToLeft_Baseline;
  SimReceivePort< float32,                                           simF32_t    > m_rp310SacExtRightToLeft_tx;
  SimReceivePort< float32,                                           simF32_t    > m_rp310SacExtRightToLeft_ty;
  SimReceivePort< float32,                                           simF32_t    > m_rp310SacExtRightToLeft_tz;
  SimReceivePort< float32[9],                                        simF32_t    > m_rp310SacExtRightToLeft_RotMat;

  // LKA
  SimReceivePort< float32,                                           simF32_t    > m_rp310VehSigVehVelocityExt;
  SimReceivePort< uint8,                                             simUI8_t    > m_rp310VehSigSpeedUnit;
  SimReceivePort< float32,                                           simF32_t    > m_rp310VehSigSpeedoSpeed;
  SimReceivePort< uint8,                                             simUI8_t    > m_rp310VehSigTurnSignal;
  SimReceivePort< float32,                                           simF32_t    > m_rp310VehSigStWheelAngle;
  SimReceivePort< float32,                                           simF32_t    > m_rp310VehSigBrakeActLevel;
  SimReceivePort< uint8,                                             simUI8_t    > m_rp310VehSigChassisControlEvent;

  // Converted by the GIA
  VehSig_t                        m_rp310VehSig;
  VehDyn_t                        m_rp310VehDyn;

  //Flag that defines which data to use
  bool m_b4xxData;

  // Flag that defines if VehParData is received
  bool m_bVehParReceived;

  int m_nCparEmoOriginVersionNumber;


  // manual calibration for mono recordings
  SimReceivePort<float32,          simF32_t       > m_rp310SensorPitch;
  SimReceivePort<float32,          simF32_t       > m_rp310SensorRoll;
  SimReceivePort<float32,          simF32_t       > m_rp310SensorYaw;
  SimReceivePort<float32,          simF32_t       > m_rp310SensorX;
  SimReceivePort<float32,          simF32_t       > m_rp310SensorY;
  SimReceivePort<float32,          simF32_t       > m_rp310SensorZ;
  SimReceivePort<float32,          simF32_t       > m_rp310CenterX;
  SimReceivePort<float32,          simF32_t       > m_rp310CenterY;
  SimReceivePort<float32,          simF32_t       > m_rp310FocalX;
  SimReceivePort<float32,          simF32_t       > m_rp310FocalY;
  SimReceivePort<uint32,           simUI32_t      > m_rp310ImageSizeX;
  SimReceivePort<uint32,           simUI32_t      > m_rp310ImageSizeY;
  SimReceivePort<uint32,           simUI32_t      > m_rp310CroppedRoiSizeX;
  SimReceivePort<uint32,           simUI32_t      > m_rp310CroppedRoiSizeY;
  SimReceivePort<uint32,           simUI32_t      > m_rp310CroppedRoiX;
  SimReceivePort<uint32,           simUI32_t      > m_rp310CroppedRoiY;
  /// @}

  /// @name MFC312 data input
  /// @{
  SimReceivePort< void*, simREFERENCE_t> m_rp310HLARInput;
/// @}

  /// @name provide ports
  /// @{
  AlgoCompState_t     m_ppAlgoCompState;
  void* m_ppRteCroiCal;
  void* m_ppRteSroiCal;
  void* m_ppRteCroiCalSemo;
  void* m_ppRteCroiCalEmo;
  void* m_ppRteRroiCalEmo;
  void* m_ppRteImagerCalEmo;
  void* m_ppRteCroiCalEol;
  void* m_ppRteSacStereoCal;
  void* m_ppRteIcIcOddRight;
  void* m_ppRteIcIcOddLeft;
  void* m_ppRteIcsr;
  void* m_ppRteFexCtrlOutput;
  void* m_ppRteFlspCalIntrDistRight;
  void* m_ppRteFlspProdData;
  void* m_ppRteFlspProdIntrRight;
  void* m_ppRteVehPar;
  void* m_ppRteVehSig;

  //neu von liste
  // NVM Signals
  void* m_ppRteNvmLd;
  void* m_ppRteNvmSr;
  void* m_ppRteNvmEcm;
  void* m_ppRteNvmHla;
  void* m_ppRteNvmTsa;
  void* m_ppRteNvmSac;
  void* m_ppRteNvmEmo;

  // CPAR Signals
  void* m_ppRteCparAldw;
  void* m_ppRteCparEcm;
  void* m_ppRteCparEmo;
  void* m_ppRteCparHlaF;
  void* m_ppRteCparHlaR;
  void* m_ppRteCparHla;
  void* m_ppRteCparSr;
  void* m_ppRteCparSac;
  void* m_ppRteCparTsa;

  // FLSP Signals
  void* m_ppRteFlspImagerCharRight;
  void* m_ppRteFlspProductionIntrinsicLeft;
  void* m_ppRteFlspStereoCallIntrinsicsLeft;
  void* m_ppRteFlspStereoCallIntrinsicsRight;
  void* m_ppRteFlspStereoCalTransRot;
  void* m_ppRteFlspTemperatureCompensationList;
  
  // Dynamic Signals
  void* m_ppRteIcIcEvenRight;
  void* m_ppRteIcImageStatisticEven;
  void* m_ppRteFCTAldwInputGen;
  void* m_ppRteDIMInputCustom;
  void* m_ppRteDIMInputGeneric;
  void* m_ppRteHEADInputCustom;
  void* m_ppRteHEADInputGeneric;
  void* m_ppRteHMIInputData;
  void* m_ppRteTsaInputGPS;
  void* m_ppRteTsaCustomInput;
  void* m_ppRteEcuStateM3_0;
  void* m_ppRteSacStereoRoiM3_10;
  

  //HLA
  void*    m_ppRteParPPAR_ImgCharRight;
  void*    m_ppRteParPPAR_RespCurveRight;
  void*    m_ppRteSig_HlaSig;
  void*    m_ppRteSig_HeadlightState;
  void*    m_ppMonoCalibrationLaneImager;
  /// @}

  /// @name client port names, for reuse
  /// @{
  static const char* CP_CALCULATIONDONE;
  static const char* CP_CALCULATIONDONEIMAGE;
  static const char* CP_DISTRIBUTEOUTPUTDATA;
  static const char* CP_DISTRIBUTEONLYDIRTYPORTS;
  /// @}

  /// @name provide port names
  /// @{
  static const char* PP_ALGO_COMP_STATE;
  static const char* PP_RTE_CROI_CAL;
  static const char* PP_RTE_SROI_CAL;
  static const char* PP_RTE_EOL_CAL_RIGHT;
  static const char* PP_RTE_STEREO_CAL;
  static const char* PP_RTE_ICIC_ODD_RIGHT;
  static const char* PP_RTE_ICIC_ODD_LEFT;
  static const char* PP_RTE_ICSR;
  static const char* PP_RTE_FEX_CTRL_OUTPUT;
  static const char* PP_RTE_FLSP_CAL_INTR_DIST_RIGHT;
  static const char* PP_RTE_FLSP_PROD_DATA;
  static const char* PP_RTE_FLSP_PROD_INTR_RIGHT;
  static const char* PP_RTE_CROI_CAL_SEMO;
  static const char* PP_RTE_CROI_CAL_EMO;
  static const char* PP_RTE_RROI_CAL_EMO;
  static const char* PP_RTE_IMAGER_CAL_EMO;
  static const char* PP_RTE_VEH_PAR;
  static const char* PP_RTE_VEH_SIG;

  // NVM Signals
  static const char* PP_RTE_NVM_LD;
  static const char* PP_RTE_NVM_SR;
  static const char* PP_RTE_NVM_ECM;
  static const char* PP_RTE_NVM_HLA;
  static const char* PP_RTE_NVM_TSA;
  static const char* PP_RTE_NVM_SAC;
  static const char* PP_RTE_NVM_EMO;

  // Cpar Signals
  static const char* PP_RTE_CPAR_ALDW;
  static const char* PP_RTE_CPAR_HLAF;
  static const char* PP_RTE_CPAR_HLAR;
  static const char* PP_RTE_CPAR_HLA;
  static const char* PP_RTE_CPAR_SR;
  static const char* PP_RTE_CPAR_SAC;
  static const char* PP_RTE_CPAR_TSA;
  static const char* PP_RTE_CPAR_ECM;
  static const char* PP_RTE_CPAR_EMO;

  // FLSP Signals
  static const char* PP_RTE_FLSP_IMAGER_CHAR_LEFT;
  static const char* PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT;
  static const char* PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT;
  static const char* PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT;
  static const char* PP_RTE_FLSP_STEREO_CAL_TRANS_ROT;
  static const char* PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST;

  // Dynamic Signals
  static const char* PP_RTE_ICIC_EVEN_RIGHT;
  static const char* PP_RTE_IC_IMAGE_STATISTIC_EVEN;
  static const char* PP_RTE_FCT_ALDW_INPUT_GEN;
  static const char* PP_RTE_DIM_INPUT_CUSTOM;
  static const char* PP_RTE_DIM_INPUT_GENERIC;
  static const char* PP_RTE_HEAD_INPUT_CUSTOM;
  static const char* PP_RTE_HEAD_INPUT_GENERIC;
  static const char* PP_RTE_HMI_INPUT_DATA;
  static const char* PP_RTE_TSA_GPS;
  static const char* PP_RTE_TSA_CUSTOM_INPUT;
  static const char* PP_RTE_ECU_STATE_M3;
  static const char* PP_RTE_SAC_STEREO_ROI_M3;

  //HLA
  static const char* PP_RTE_FLSP_IMG_CHAR_RIGHT;
  static const char* PP_RTE_FLSP_RESPONSE_CURVE_RIGHT;
  static const char* PP_RTE_HLA_SIGNALS;   
  static const char* PP_RTE_HLA_HEADLIGHT_STATE;
  static const char* PP_MONOCALIBRATION_LANE_IMAGER;

  // TODO: place static const char* PP_<NAME> members
  /// @}

  /// @name provide ports
  /// @{
  // TODO: place static const char* PP_<NAME> members
  /// @}

  static CVersionInfoImpl CreateVersionInfoFromI32 (const long version);

private:

  static const long          CYLCE_ID                 = TASK_ID_GIA;//TASK_ID_MfcWrapper;
  static const long          COMP_ID                  = TASK_ID_GIA;//COMP_ID_MfcWrapper

  /// List of cycles, this plugin sends output to. 
  static const DWORD CYCLE_INFO_ARR[1];

  /// Flag that defines whether the Input Check will be run in current cycle
  bool m_bCheckInput; 

  bool m_bMfc3xxUpdatePortSize;

  /// Map type representing additional data per port
  typedef std::vector<SimReceivePortBase*> ReceivePortMap_t;
  typedef std::vector<long>                ProvidePortMap_t;

  int m_nIcIcIddLeftPortIndex;

  /// Available receive ports with additional data
  ReceivePortMap_t m_receivePortMap;
  ProvidePortMap_t m_providePortMap;
  /// @}

  // timestamp fix class
  CSimImageTimestampFix m_TimstampFixer;

  float32                           m_fPitchOffset;
  float32                           m_fRollOffset;
  float32                           m_fYawOffset;
  uint32                            m_uSacMissingCnt;
  uint32                            m_uAngOffsetMissingCnt;

  MonoCalibration_t                 m_oRteCroiCal;
  MonoCalibrationEol_t              m_oRteCroiCalEol;
  SacRteFexControlOutput_t          m_oRteFexCtrlOutput;
  MonoCalibration_t                 m_oRteRroiCalEmo;
  MonoCalibration_t                 m_oRteImagerCalEmo;
  SacRteStereoCalibrationOutput_t   m_oRteSacStereoCal;
  MonoCalibration_t                 m_oRteSroiCal;
  FLSPCalIntrDistRight_t            m_oRteFlspCalIntrDistRight;
  FLSPProductionData_t              m_oRteFlspProdData;
  FLSPProductionIntrinsic_t         m_oRteFlspProdIntrRight;
  IcImageCharacteristics_t          m_oRteIcIcOddRight;
  IcImageCharacteristics_t          m_oRteIcIcOddLeft;
  IcStatisticalResults_t            m_oRteIcsr;
  VehSig_t                          m_oRteVehSig;
  VehPar_t                          m_oRteVehPar;

  //NVM Signals
  NVM_LdOnlineCaliData_t            m_oRteNvmLd;
  NVM_SR_RTE_t                      m_oRteNvmSr;
  NVM_EcmRte_t                      m_oRteNvmEcm;
  NVM_HLAR_LearningValues_t         m_oRteNvmHla;
  NvmTsaRteState_t                  m_oRteNvmTsa;
  NVM_SacRte_t                      m_oRteNvmSac;
  NVM_Emo_t                         m_oRteNvmEmo;

  //CPAR Signals
  CPAR_ALDW_Parameters_t            m_oRteCparAldw;
  CPAR_EcmRte_t                     m_oRteCparEcm;
  CPAR_HLAF_Parameter_t             m_oRteCparHlaF;
  CPAR_HLAR_Parameter_t             m_oRteCparHlaR;
  CPAR_HLA_Parameter_t              m_oRteCparHla;
  CPAR_SR_RTE_parameters_t          m_oRteCparSr;
  CPAR_TSA_RTE_parameters_t         m_oRteCparTsa;
  CPAR_SacRte_t                     m_oRteCparSac;
  CPAR_Emo_t                        m_oRteCparEmo;

  //FLSP Singals
  FLSPImagerCharacteristicsLeft_t   m_oRteFlspImagerCharRight;
  FLSPProductionIntrinsic_t         m_oRteFlspProductionIntrinsicLeft;
  FLSPStereoCalIntrinsics_t         m_oRteFlspStereoCallIntrinsicsLeft;
  FLSPStereoCalIntrinsics_t         m_oRteFlspStereoCallIntrinsicsRight;
  FLSPStereoCalTransRot_t           m_oRteFlspStereoCalTransRot;
  FLSPTemperatureCompensationList_t m_oRteFlspTemperatureCompensationList;
  
  //Dynamic Signals
  IcImageCharacteristics_t          m_oRteIcIcEvenRight;
  IcStatisticalResults_t            m_oRteIcImageStatisticEven;
  FCTALDWInputGeneric_t             m_oRteFCTAldwInputGen;
  DIMInputCustom_t                  m_oRteDIMInputCustom;
  DIMInputGeneric_t                 m_oRteDIMInputGeneric;
  HEADInputCustom_t                 m_oRteHEADInputCustom;
  HEADInputGeneric_t                m_oRteHEADInputGeneric;
  t_HMI_Data_t                      m_oRteHMIInputData;
  RteInputGPS_t                     m_oRteTsaInputGPS;
  TsaRteCustomInput_t               m_oRteTsaCustomInput;
  EcuState_t                        m_oRteEcuStateM3_0;
  SacRteStereoRoiInput_t            m_oRteSacStereoRoiM3_10;
                                  
  // HLA
  FLSPImagerCharacteristicsRight_t  m_oRteParPPAR_ImgCharRight;           /* Production parameter (PPAR) from ICU (Only needed for HLA simulation): imager characteristic of right imager (T1_Production, Actual_T2, Actual_T3, ...) */  
  FLSPResponseCurvePeriphery_t      m_oRteParPPAR_RespCurveRight;         /* Production parameter (PPAR) from ICU (Only needed for HLA simulation): response curve measured during production 12 values */
  RTE_HLA_Signals_t                 m_oRteSig_HlaSig;                     /* Bus signals from ICU: Hla specific ones */
  RTE_HLA_HeadlightState_t          m_oRteSig_HeadlightState;             /* Bus signals from ICU: feedback from head lamps (only used in simulation right now) */
  MonoCalibration_t                 m_oMonoCalibrationLaneImager;
  
  HLAR_t_RequiredInputs             m_HlarRequiredInputs;

  // Callback used callback handlers for Template component
  AS_t_ServiceFuncts m_ServiceHandler;

  void Reset();
  void Init();
  void Doit();
  void DoitImage();
  void MainCall();
  void CheckPortsDataReceived();
  void SetupPorts();
  void ResetReceivePorts();
  void ResetProvidePortSizeAndVersionnumber();
  bool ReceivedAnyMFC3xxData();
  void MeasFreezeMFC3xxData();

  typedef cml::CArray<float                                 , SAC_MEAS_NumRadDistCoeff, true> DistCoeffArray_t;
  typedef cml::CArray<const float                           , SAC_MEAS_NumRadDistCoeff, true> ConstDistCoeffArray_t;

  /// SAC wrapper
  void wrapCroiCalibration(
    const mfc310::stereo::SACImageData_t&                    CroiImageData310,
    const mfc310::stereo::SACMountingCalibrationData_t&      CroiExt310,
    const mfc310::stereo::SACMeasIntrinsicCalibrationData_t& CroiInt310,
    MonoCalibration_t& Croi400 );

  void wrapCroiCalibrationEol(
    const mfc310::stereo::SACImageData_t&                    CroiImageData310,
    const mfc310::stereo::SACMountingCalibrationData_t&      CroiExt310,
    const mfc310::stereo::SACMeasIntrinsicCalibrationData_t& CroiInt310,
    MonoCalibrationEol_t& CroiEol400 );

#ifdef SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER
  void wrapStereoCalibration(
    const mfc310::stereo::SACMeasRectCamPars_t& SAC310,
    MonoCalibration_t& RectMono400,
    SacRteStereoCalibrationOutput_t& RectStereo400);
#endif

  void wrapICICData(
    const mfc310::ic::ICEXP_S_Output& ICIC310,
    const uint16& uSlopeRatioR1, 
    const float32& fBlacklevel,
    IcImageCharacteristics_t& ICIC400 );

  void wrapICSRData(
    const mfc310::ic::IC_S_ResultsPart2& ICRP2310,
    const mfc310::ic::IC_S_EmbeddedStatData& ICESP310,
    IcStatisticalResults_t& ICSR400 );

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
  void wrapFexControlOutput(
    const mfc310::stereo::SACMeasObjLUTLeft& sacMeasObjLutLeft, 
    const mfc310::stereo::SACMeasObjLUTRight& sacMeasObjLutRight, 
    const mfc310::stereo::SACImageData_t& sacSRoiImageDataLeft,
    const mfc310::stereo::SACImageData_t& sacSRoiImageDataRight,
    uint16 uParameterIdLUTLeft,
    uint16 uParameterIdLUTRight,
    SacRteFexControlOutput_t& fexControlOutput);
#endif

  void WrapVehSig(
    VehSig_t& vehSig,
    float32   fVehSigVehVelocityExt,
    uint8     eVehSigSpeedUnit,
    float32   fVehSigSpeedoSpeed,
    uint8     eVehSigTurnSignal,
    float32   fVehSigStWheelAngle,
    float32   fVehSigBrakeActLevel,
    uint8     eVehSigChassisControlEvent
    );

  void WrapFCT();

  void InitializeProvidePorts();
  void WrapHlaData();
  void FillSensorAngles();
  void InitializeCparsDefault();
  void InitHlaCparDefault();
  void InitAldwCparDefault();
  void InitSrCparDefault();
  void InitSacCparDefault();
  void InitEcmCparDefault();
  void InitTsaCparDefault();
  void InitEmoCparDefault();

  long ConvertHlarInData(unsigned long ulPPortSize,  void* pPPortData);

  static float32 calculateRelativeVY( const mfc310::stereo::SFODObjectList_t& obj, const PoseParameters_t& poseParams );

  template <typename T>
  void CopyDataToProvidePort(std::vector<uint8> &providePort, const T &data);
};

#endif // sim_swc___template_h__
