/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#pragma warning( disable : 4005)
#include "stdafx.h"
#include "resource.h"
#include <viscr_rotation.hpp> // access to viscr_XYZFixedAngles2RotationMatrix
#include "mfc_wrapper_ver.h"
#include "sim_swc_mfc_wrapper.h"
#include "sim_provideportcontainer.h"
#include "cct_camera.h"
#include "cml_misc.h"

// include cpars initializer
//#include "./Cpar/ALDW/lka_cpar_init.h"
#include "./Cpar/HLA/hla_cpar_init.h"
#include "./Cpar/ECM/ecm_cpar_init.h"
#include "./Cpar/SAC/sac_cpar_init.h"
#include "./Cpar/SR/sr_cpar_init.h"
#include "./Cpar/TSA/tsa_cpar_init.h"
#include "./Cpar/MEMO/memo_cpar_init.h"


#include <sstream>

// the client port names
const char* CSimMfcWrapper::CP_CALCULATIONDONE                                = "CalculationDone";
const char* CSimMfcWrapper::CP_CALCULATIONDONEIMAGE                           = "CalculationDoneImage";
const char* CSimMfcWrapper::CP_DISTRIBUTEOUTPUTDATA                           = "DistributeOutputData";
const char* CSimMfcWrapper::CP_DISTRIBUTEONLYDIRTYPORTS                       = "DistributeOnlyDirtyPorts";

// the provide port names
const char* CSimMfcWrapper::PP_ALGO_COMP_STATE                                = "AlgoCompState";
const char* CSimMfcWrapper::PP_RTE_CROI_CAL                                   = "CroiMonoCalibration";
const char* CSimMfcWrapper::PP_RTE_SROI_CAL                                   = "SroiMonoCalibration";
const char* CSimMfcWrapper::PP_RTE_EOL_CAL_RIGHT                              = "MonoCalibrationEolRight";
const char* CSimMfcWrapper::PP_RTE_STEREO_CAL                                 = "StereoCalibration";
const char* CSimMfcWrapper::PP_RTE_ICIC_ODD_RIGHT                             = "IcImageCharacteristicsOddRight";
const char* CSimMfcWrapper::PP_RTE_ICIC_ODD_LEFT                              = "IcImageCharacteristicsOddLeft";
const char* CSimMfcWrapper::PP_RTE_ICSR                                       = "IcStatisticalResults";
const char* CSimMfcWrapper::PP_RTE_FEX_CTRL_OUTPUT                            = "FexControlOutput";
const char* CSimMfcWrapper::PP_RTE_FLSP_CAL_INTR_DIST_RIGHT                   = "FlspCalIntrDistRight";
const char* CSimMfcWrapper::PP_RTE_FLSP_PROD_DATA                             = "FlspProdData";
const char* CSimMfcWrapper::PP_RTE_FLSP_PROD_INTR_RIGHT                       = "FlspProdIntrRight";
const char* CSimMfcWrapper::PP_RTE_CROI_CAL_SEMO                              = "CroiMonoCalibrationSemo";
const char* CSimMfcWrapper::PP_RTE_CROI_CAL_EMO                               = "MonoCalibrationEmoCRoi";
const char* CSimMfcWrapper::PP_RTE_RROI_CAL_EMO                               = "MonoCalibrationEmoRRoi";
const char* CSimMfcWrapper::PP_RTE_IMAGER_CAL_EMO                             = "MonoCalibrationEmoImager";
const char* CSimMfcWrapper::PP_RTE_FLSP_IMG_CHAR_RIGHT                        = "FlspImageCharacteristicRight";
const char* CSimMfcWrapper::PP_RTE_FLSP_RESPONSE_CURVE_RIGHT                  = "FlspResponseCurveRight";
const char* CSimMfcWrapper::PP_RTE_HLA_SIGNALS                                = "HlaSignals";
const char* CSimMfcWrapper::PP_RTE_HLA_HEADLIGHT_STATE                        = "HlaHeadlightState";
const char* CSimMfcWrapper::PP_RTE_VEH_PAR                                    = "pVehPar";
const char* CSimMfcWrapper::PP_RTE_VEH_SIG                                    = "pVehSig";

// NVM Signals
const char* CSimMfcWrapper::PP_RTE_NVM_LD                                     = "NVM_LdOnlineCaliData";
const char* CSimMfcWrapper::PP_RTE_NVM_SR                                     = "NVM_SR_RTE";
const char* CSimMfcWrapper::PP_RTE_NVM_ECM                                    = "pNvmEcmRteOut";
const char* CSimMfcWrapper::PP_RTE_NVM_HLA                                    = "NVM_HLA_Values";
const char* CSimMfcWrapper::PP_RTE_NVM_TSA                                    = "TsaRteNvmState";
const char* CSimMfcWrapper::PP_RTE_NVM_SAC                                    = "pNvmSacOut";
const char* CSimMfcWrapper::PP_RTE_NVM_EMO                                    = "NvmEmoM3_0";

// CPAR Signals
const char* CSimMfcWrapper::PP_RTE_CPAR_ALDW                                  = "pCPAR_ALDW_Parameters";
const char* CSimMfcWrapper::PP_RTE_CPAR_HLAF                                  = "HLAF_Parameter";
const char* CSimMfcWrapper::PP_RTE_CPAR_HLAR                                  = "HLAR_Parameter";
const char* CSimMfcWrapper::PP_RTE_CPAR_HLA                                   = "HLA_Parameter";
const char* CSimMfcWrapper::PP_RTE_CPAR_SR                                    = "SrRteCodingParams";
const char* CSimMfcWrapper::PP_RTE_CPAR_SAC                                   = "pCParSac";
const char* CSimMfcWrapper::PP_RTE_CPAR_TSA                                   = "TsaRteCodingParams";
const char* CSimMfcWrapper::PP_RTE_CPAR_ECM                                   = "CPAR_EcmRte_t";
const char* CSimMfcWrapper::PP_RTE_CPAR_EMO                                   = "CPAR_Emo";

// FLSP Signals
const char* CSimMfcWrapper::PP_RTE_FLSP_IMAGER_CHAR_LEFT                      = "pFlspImagerCharLeft";
const char* CSimMfcWrapper::PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT             = "pFlspProductionIntrinsicLeft";
const char* CSimMfcWrapper::PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT             = "pFlspStereoCalIntrinsicsLeft";
const char* CSimMfcWrapper::PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT            = "pFlspStereoCalIntrinsicsRight";
const char* CSimMfcWrapper::PP_RTE_FLSP_STEREO_CAL_TRANS_ROT                  = "pFLSPStereoCalTransRot";
const char* CSimMfcWrapper::PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST     = "pFlspTemperatureCompensationList";
                                                                              
// Dynamic Signals
const char* CSimMfcWrapper::PP_RTE_ICIC_EVEN_RIGHT                            = "IcImageCharacteristicsEvenRight";
const char* CSimMfcWrapper::PP_RTE_IC_IMAGE_STATISTIC_EVEN                    = "IcImageStatisticEvenRight";
const char* CSimMfcWrapper::PP_RTE_FCT_ALDW_INPUT_GEN                         = "FCTAldwInputGen";
const char* CSimMfcWrapper::PP_RTE_DIM_INPUT_CUSTOM                           = "DIMInputCustom";
const char* CSimMfcWrapper::PP_RTE_DIM_INPUT_GENERIC                          = "DIMInputGeneric";
const char* CSimMfcWrapper::PP_RTE_HEAD_INPUT_CUSTOM                          = "HEADInputCustom";
const char* CSimMfcWrapper::PP_RTE_HEAD_INPUT_GENERIC                         = "HEADInputGeneric";
const char* CSimMfcWrapper::PP_RTE_HMI_INPUT_DATA                             = "HMIInputData";
const char* CSimMfcWrapper::PP_RTE_TSA_GPS                                    = "TsaRteInputGPS";
const char* CSimMfcWrapper::PP_RTE_TSA_CUSTOM_INPUT                           = "TsaRteCustomInput";
const char* CSimMfcWrapper::PP_RTE_ECU_STATE_M3                               = "EcuStateM3_0";
const char* CSimMfcWrapper::PP_RTE_SAC_STEREO_ROI_M3                          = "SacRteStereoRoiM3_10";
const char* CSimMfcWrapper::PP_MONOCALIBRATION_LANE_IMAGER                    = "MonoCalibrationLaneImager";



/// List of cycles, this plugin sends output to. 
const DWORD CSimMfcWrapper::CYCLE_INFO_ARR[1] = {CYLCE_ID};


static void ConfigurePPort (const char* szPortName, const SimReceivePort<void*, simREFERENCE_t> &receivePort, void** providePortData, CSimMfcWrapper* wrapper, bool b4xxData = true, const uint32 vaddr = 0)
{
  unsigned long portSize  = unsigned long(receivePort.size());
  const uint32  uiVersionNumber = *static_cast<const uint32*>(receivePort.val());
  if(wrapper->GetPPortSize(szPortName) != long(portSize))
  {
    wrapper->UpdatePPortSize(szPortName, portSize, FALSE);
  }
  wrapper->ChangePPortVersion(szPortName, wrapper->CreateVersionInfoFromI32(uiVersionNumber));
  // ? receivePort.lock();
  *providePortData = const_cast<void*>(receivePort.val());
  // ? receivePort.unlock();
  // Special request ports can be compatible for both MFC3xx and MFC4xx
  // In case of one of these special ports we do not set the 4xx data flag back to false
  if(b4xxData)
  {
    wrapper->m_b4xxData = b4xxData; //in the case we receive MFC3xx and MFC4xx Data, MFC4xx Data with higher priority 
  }

  wrapper->SetPPortDirty(szPortName);
  if (wrapper->m_b4xxData)
  {
    wrapper->TriggerEvent(CSimMfcWrapper::CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);
    if(vaddr != 0)
    {
      //wrapper->MeasFreezeSim(vaddr, *providePortData, portSize);
    }
  }
}

static void ConfigurePPortCroiMonoCalibration (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CROI_CAL, simWrapper->m_rpRteCroiCal, &simWrapper->m_ppRteCroiCal, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONCROI);
}

static void ConfigurePPortSroiMonoCalibration (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_SROI_CAL, simWrapper->m_rpRteSroiCal, &simWrapper->m_ppRteSroiCal, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSROI);
}

static void ConfigurePPortCroiCalSemo (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CROI_CAL_SEMO, simWrapper->m_rpRteCroiCalSemo, &simWrapper->m_ppRteCroiCalSemo, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSEMOCROI);
}

static void ConfigurePPortCroiCalEmo (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CROI_CAL_EMO, simWrapper->m_rpRteCroiCalEmo, &simWrapper->m_ppRteCroiCalEmo, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOCROI);
}

static void ConfigurePPortRroiCalEmo (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_RROI_CAL_EMO, simWrapper->m_rpRteRroiCalEmo, &simWrapper->m_ppRteRroiCalEmo, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMORROI);
}

static void ConfigurePPortImagerCalEmo (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_IMAGER_CAL_EMO, simWrapper->m_rpRteImagerCalEmo, &simWrapper->m_ppRteImagerCalEmo, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOIMAGER);
}

static void ConfigurePPortCroiCalEol (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_EOL_CAL_RIGHT, simWrapper->m_rpRteCroiCalEol, &simWrapper->m_ppRteCroiCalEol, simWrapper, true, GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEOLRIGHT);
}

static void ConfigurePPortIcIcOddRight(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_ICIC_ODD_RIGHT, simWrapper->m_rpRteIcIcOddRight, &simWrapper->m_ppRteIcIcOddRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDRIGHT);
}

static void ConfigurePPortIcIcOddLeft(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_ICIC_ODD_LEFT, simWrapper->m_rpRteIcIcOddLeft, &simWrapper->m_ppRteIcIcOddLeft, simWrapper, true, GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDLEFT);
}

static void ConfigurePPortIcsr (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_ICSR, simWrapper->m_rpRteIcsr, &simWrapper->m_ppRteIcsr, simWrapper, true, GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSODD);
}

static void ConfigurePPortFlspCalIntrDistRight (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_CAL_INTR_DIST_RIGHT, simWrapper->m_rpRteFlspCalIntrDistRight, &simWrapper->m_ppRteFlspCalIntrDistRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPCALINTRDISTRIGHT);
}

static void ConfigurePPortFlspProdData (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_PROD_DATA, simWrapper->m_rpRteFlspProdData, &simWrapper->m_ppRteFlspProdData, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONDATA);
}

static void ConfigurePPortFlspProdIntrRight (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_PROD_INTR_RIGHT, simWrapper->m_rpRteFlspProdIntrRight, &simWrapper->m_ppRteFlspProdIntrRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICRIGHT);
}

static void ConfigurePPortSacStereoCal (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_STEREO_CAL, simWrapper->m_rpRteSacStereoCal, &simWrapper->m_ppRteSacStereoCal, simWrapper, true, GIA_MEAS_ID_WRAPPER_STEREOCALIBRATION);
}

static void ConfigurePPortFexCtrlOutput (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FEX_CTRL_OUTPUT, simWrapper->m_rpRteFexCtrlOutput, &simWrapper->m_ppRteFexCtrlOutput, simWrapper, true, GIA_MEAS_ID_WRAPPER_PSACFEXCONTROLOUTPUT);
}

static void ConfigurePPortFLSPImagerCharacteristicsRight (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_IMG_CHAR_RIGHT, simWrapper->m_rpRteParPPAR_ImgCharRight, &simWrapper->m_ppRteParPPAR_ImgCharRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSRIGHT);
}

static void ConfigurePPortFLSPResponseCurvePeriphery (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_RESPONSE_CURVE_RIGHT, simWrapper->m_rpRteParPPAR_RespCurveRight, &simWrapper->m_ppRteParPPAR_RespCurveRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPRESPONSECURVEPERIPHERY);
}

static void ConfigurePPortHLA_Signals (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_HLA_SIGNALS, simWrapper->m_rpRteSig_HlaSig, &simWrapper->m_ppRteSig_HlaSig, simWrapper, true, GIA_MEAS_ID_WRAPPER_PSIGHLASIG);
}

static void ConfigurePPortHLA_HeadlightStat (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_HLA_HEADLIGHT_STATE, simWrapper->m_rpRteSig_HeadlightState, &simWrapper->m_ppRteSig_HeadlightState, simWrapper, true, GIA_MEAS_ID_WRAPPER_PHLAHEADLIGHTSTATE);
}

static void ConfigurePPort_VehPar (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  simWrapper->m_bVehParReceived = true;

  // Overwriting of values not given in old recordings needed by LDW/LDP (issue 335963)
  VehPar_t* vehPar = reinterpret_cast<VehPar_t*>(simWrapper->m_ppRteVehPar);
  if (vehPar != NULL){
    vehPar->VehParMain.State[VDY_PAR_POS_SWARAT]  = VDY_IO_STATE_VALID;
    vehPar->VehParMain.State[VDY_PAR_POS_CSFR]    = VDY_IO_STATE_VALID;
    vehPar->VehParMain.State[VDY_PAR_POS_CSRE]    = VDY_IO_STATE_VALID;
    vehPar->VehParMain.FrCrnrStiff                = 91400;
    vehPar->VehParMain.ReCrnrStiff                = 91400;
  }

  ConfigurePPort(CSimMfcWrapper::PP_RTE_VEH_PAR, simWrapper->m_rpRteVehPar, &simWrapper->m_ppRteVehPar, simWrapper, false, GIA_MEAS_ID_WRAPPER_PVEHPAR);
}

static void ConfigurePPortVehSig (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);

  // VehSig overwriting of states needed by LDW/LDP (issue 335963)
  VehSig_t* vehSig = reinterpret_cast<VehSig_t*>(simWrapper->m_ppRteVehSig);
  if (vehSig != NULL){
    vehSig->VehSigMain.State[VDY_SIN_POS_SWA] = VDY_IO_STATE_VALID;
  }

  ConfigurePPort(CSimMfcWrapper::PP_RTE_VEH_SIG, simWrapper->m_rpRteVehSig, &simWrapper->m_ppRteVehSig, simWrapper, false, GIA_MEAS_ID_WRAPPER_PVEHSIG);
}

//NVM Signals
static void ConfigurePPortNvmLd (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_LD, simWrapper->m_rpRteNvmLd, &simWrapper->m_ppRteNvmLd, simWrapper, true, GIA_MEAS_ID_WRAPPER_PNVMLDONLINECALIDATA);
}

static void ConfigurePPortNvmSr (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_SR, simWrapper->m_rpRteNvmSr, &simWrapper->m_ppRteNvmSr, simWrapper, true, GIA_MEAS_ID_WRAPPER_PNVMSRRTE);
}

static void ConfigurePPortNvmEcm (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_ECM, simWrapper->m_rpRteNvmEcm, &simWrapper->m_ppRteNvmEcm, simWrapper, true, GIA_MEAS_ID_WRAPPER_PNVMECMRTEIN);
}

static void ConfigurePPortNvmHla (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_HLA, simWrapper->m_rpRteNvmHla, &simWrapper->m_ppRteNvmHla, simWrapper, true, GIA_MEAS_ID_WRAPPER_PNVMSIGLEARNINGVALUES);
}

static void ConfigurePPortNvmTsa (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_TSA, simWrapper->m_rpRteNvmTsa, &simWrapper->m_ppRteNvmTsa, simWrapper, true, GIA_MEAS_ID_WRAPPER_PNVMTSARTEPERSSTATE);
}

static void ConfigurePPortNvmSac (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_SAC, simWrapper->m_rpRteNvmSac, &simWrapper->m_ppRteNvmSac, simWrapper, true, GIA_MEAS_ID_WRAPPER_PNVMSAC);
}

static void ConfigurePPortNvmEmo (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_NVM_EMO, simWrapper->m_rpRteNvmEmo, &simWrapper->m_ppRteNvmEmo, simWrapper, false, GIA_MEAS_ID_WRAPPER_PNVMEMOREAD);
}


// CPAR Signals
static void ConfigurePPortCparAldw (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_ALDW, simWrapper->m_rpRteCparAldw, &simWrapper->m_ppRteCparAldw, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARFCTPARAMETERS);
}

static void ConfigurePPortCparHlaf (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_HLAF, simWrapper->m_rpRteCparHlaF, &simWrapper->m_ppRteCparHlaF, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARHLAFPAR);
}

static void ConfigurePPortCparHlar (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_HLAR, simWrapper->m_rpRteCparHlaR, &simWrapper->m_ppRteCparHlaR, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARHLARPAR);
}

static void ConfigurePPortCparHla (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_HLA, simWrapper->m_rpRteCparHla, &simWrapper->m_ppRteCparHla, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARHLAPAR);
}

static void ConfigurePPortCparSr (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_SR, simWrapper->m_rpRteCparSr, &simWrapper->m_ppRteCparSr, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARSRRTEPARAMETERS);
}

static void ConfigurePPortCparSac (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_SAC, simWrapper->m_rpRteCparSac, &simWrapper->m_ppRteCparSac, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARSAC);
}

static void ConfigurePPortCparTsa (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_TSA, simWrapper->m_rpRteCparTsa, &simWrapper->m_ppRteCparTsa, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARTSARTEPARAMETER);
}

static void ConfigurePPortCparEcm (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_ECM, simWrapper->m_rpRteCparEcm, &simWrapper->m_ppRteCparEcm, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPARECMRTE);
}

// In case of received VehPar we add the MountingPitch angle to the CParEmo,
// but only if the value is not already available from the struct itself
static void ConfigurePPortCparEmo (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);

  if (simWrapper->m_bVehParReceived  == true && simWrapper->m_ppRteVehPar != NULL && 
      simWrapper->m_nCparEmoOriginVersionNumber > -1 && // VersionNumber has to be greater than -1 => CparReceived
      simWrapper->m_nCparEmoOriginVersionNumber < 5)    // VersionNumber has to be smaller than 4 => Otherwise fCalibCamStartPitch is allready available from the udex and we don't need to take vehpars value
  {
    VehPar_t* vehPar = reinterpret_cast<VehPar_t*>(simWrapper->m_ppRteVehPar);
    CPAR_Emo_t* cparEmo = reinterpret_cast<CPAR_Emo_t*>(simWrapper->m_rpRteCparEmo.val());
    cparEmo->fCalibCamStartPitch = vehPar->SensorMounting.PitchAngle*180/C_PI; // Convert from rad to deg
    cparEmo->fCalibCamStartRoll  = vehPar->SensorMounting.RollAngle*180/C_PI; // Convert from rad to deg
    cparEmo->fCalibCamStartYaw   = vehPar->SensorMounting.YawAngle*180/C_PI; // Convert from rad to deg
  }
  // do the usual stuff
  ConfigurePPort(CSimMfcWrapper::PP_RTE_CPAR_EMO, simWrapper->m_rpRteCparEmo, &simWrapper->m_ppRteCparEmo, simWrapper, true, GIA_MEAS_ID_WRAPPER_PCPAREMO);
}

static void GetCparEmoVersionNumber(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  simWrapper->m_nCparEmoOriginVersionNumber = *(reinterpret_cast<uint32*>(simWrapper->m_rpRteCparEmoOrigin.val()));
}

// FLSP Signals
static void ConfigurePPortFlspImagerCharLeft (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_IMAGER_CHAR_LEFT, simWrapper->m_rpRteFlspImagerCharRight, &simWrapper->m_ppRteFlspImagerCharRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSRIGHT);
}

static void ConfigurePPortFlspProductionIntrinsicLeft(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT, simWrapper->m_rpRteFlspProductionIntrinsicLeft, &simWrapper->m_ppRteFlspProductionIntrinsicLeft, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICLEFT);
}

static void ConfigurePPortFlspStereoCalIntrinsicLeft (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT, simWrapper->m_rpRteFlspStereoCallIntrinsicsLeft, &simWrapper->m_ppRteFlspStereoCallIntrinsicsLeft, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSLEFT);
}

static void ConfigurePPortFlspStereoCalIntrinsicRight (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT, simWrapper->m_rpRteFlspStereoCallIntrinsicsRight, &simWrapper->m_ppRteFlspStereoCallIntrinsicsRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSRIGHT);
}

static void ConfigurePPortFlspStereoCalTransRot (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_STEREO_CAL_TRANS_ROT, simWrapper->m_rpRteFlspStereoCalTransRot, &simWrapper->m_ppRteFlspStereoCalTransRot, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALTRANSROT);
}

static void ConfigurePPortFlspCalTemperatureCompList (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST, simWrapper->m_rpRteFlspTemperatureCompensationList, &simWrapper->m_ppRteFlspTemperatureCompensationList, simWrapper, true, GIA_MEAS_ID_WRAPPER_PFLSPTEMPERATURECOMPENSATIONLIST);
}


// Dynamic Signals
static void ConfigurePPortIcIcEvenRight (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_ICIC_EVEN_RIGHT, simWrapper->m_rpRteIcIcEvenRight, &simWrapper->m_ppRteIcIcEvenRight, simWrapper, true, GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSEVENRIGHT);
}

static void ConfigurePPortIcImageStatisticEven (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_IC_IMAGE_STATISTIC_EVEN, simWrapper->m_rpRteIcImageStatisticEven, &simWrapper->m_ppRteIcImageStatisticEven, simWrapper, true, GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSEVEN);
}

static void ConfigurePPortFctAldwGen (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_FCT_ALDW_INPUT_GEN, simWrapper->m_rpRteFCTAldwInputGen, &simWrapper->m_ppRteFCTAldwInputGen, simWrapper, true, GIA_MEAS_ID_WRAPPER_FCTALDWINPUTGENERIC);
}

static void ConfigurePPortDimCustom (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_DIM_INPUT_CUSTOM, simWrapper->m_rpRteDIMInputCustom, &simWrapper->m_ppRteDIMInputCustom, simWrapper, true, GIA_MEAS_ID_WRAPPER_PDIMINPUTCUSTOM);
}

static void ConfigurePPortDimGeneric (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_DIM_INPUT_GENERIC, simWrapper->m_rpRteDIMInputGeneric, &simWrapper->m_ppRteDIMInputGeneric, simWrapper, true, GIA_MEAS_ID_WRAPPER_PDIMINPUTGENERIC);
}

static void ConfigurePPortHeadCustom (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_HEAD_INPUT_CUSTOM, simWrapper->m_rpRteHEADInputCustom, &simWrapper->m_ppRteHEADInputCustom, simWrapper, true, GIA_MEAS_ID_WRAPPER_PHEADINPUTCUSTOM);
}

static void ConfigurePPortHeadGeneric (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_HEAD_INPUT_GENERIC, simWrapper->m_rpRteHEADInputGeneric, &simWrapper->m_ppRteHEADInputGeneric, simWrapper, true, GIA_MEAS_ID_WRAPPER_PHEADINPUTGENERIC);
}

static void ConfigurePPortHmiData (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_HMI_INPUT_DATA, simWrapper->m_rpRteHMIInputData, &simWrapper->m_ppRteHMIInputData, simWrapper, true, GIA_MEAS_ID_WRAPPER_PHMIDATA);
}

static void ConfigurePPortTsaGps (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_TSA_GPS, simWrapper->m_rpRteTsaInputGPS, &simWrapper->m_ppRteTsaInputGPS, simWrapper, true, GIA_MEAS_ID_WRAPPER_PRTEINPUTGPS);
}

static void ConfigurePPortTsaCustom (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_TSA_CUSTOM_INPUT, simWrapper->m_rpRteTsaCustomInput, &simWrapper->m_ppRteTsaCustomInput, simWrapper, true, GIA_MEAS_ID_WRAPPER_PTSARTECUSTOMINPUT);
}

static void ConfigurePPortEcuStateM3 (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_ECU_STATE_M3, simWrapper->m_rpRteEcuStateM3_0, &simWrapper->m_ppRteEcuStateM3_0, simWrapper, true, GIA_MEAS_ID_WRAPPER_ECUSTATET);
}

static void ConfigurePPortSacStereoRoiM3(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_RTE_SAC_STEREO_ROI_M3, simWrapper->m_rpRteSacStereoRoiM3_10, &simWrapper->m_ppRteSacStereoRoiM3_10, simWrapper, true, GIA_MEAS_ID_WRAPPER_SACRTESTEREOROIINPUT);
}

static void ConfigurePPortMonoCalibrationLane(void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimMfcWrapper* simWrapper = reinterpret_cast<CSimMfcWrapper*>(PlgID);
  ConfigurePPort(CSimMfcWrapper::PP_MONOCALIBRATION_LANE_IMAGER, simWrapper->m_rpMonoCalibrationLaneImager, &simWrapper->m_ppMonoCalibrationLaneImager, simWrapper, true, GIA_MEAS_ID_WRAPPER_PSIGMONOCALIBRATIONLANEIMAGER);
}



CSimMfcWrapper::CSimMfcWrapper()
: CSimSwcBase("..\\gia_sim\\adapter.dll")
, CSimSwcCDL      (this, IDR_CDL)
, CSimSwcMeas     (this)
, CSimSwcDebugExc ()
, CSimSwcCycleInfo(this, CYCLE_INFO_ARR, sizeof(CYCLE_INFO_ARR)/sizeof(DWORD))
// timestamp fix
, m_TimstampFixer(static_cast<CSimSwcBase*>(this))
//Mfc4xx Input Signals
, m_rpBaseCtrlData                        (this, "BaseCtrlData",                                  BaseCtrlData_t())
, m_rpRteCroiCal                          (this, PP_RTE_CROI_CAL,                                 NULL, 0, 0, ConfigurePPortCroiMonoCalibration, this)
, m_rpRteSroiCal                          (this, PP_RTE_SROI_CAL,                                 NULL, 0, 0, ConfigurePPortSroiMonoCalibration, this)
, m_rpRteCroiCalSemo                      (this, PP_RTE_CROI_CAL_SEMO,                            NULL, 0, 0, ConfigurePPortCroiCalSemo, this)
, m_rpRteCroiCalEmo                       (this, PP_RTE_CROI_CAL_EMO,                             NULL, 0, 0, ConfigurePPortCroiCalEmo, this)
, m_rpRteRroiCalEmo                       (this, PP_RTE_RROI_CAL_EMO,                             NULL, 0, 0, ConfigurePPortRroiCalEmo, this)
, m_rpRteImagerCalEmo                     (this, PP_RTE_IMAGER_CAL_EMO,                           NULL, 0, 0, ConfigurePPortImagerCalEmo, this)
, m_rpRteCroiCalEol                       (this, PP_RTE_EOL_CAL_RIGHT,                            NULL, 0, 0, ConfigurePPortCroiCalEol, this)
, m_rpRteIcIcOddRight                     (this, PP_RTE_ICIC_ODD_RIGHT,                           NULL, 0, 0, ConfigurePPortIcIcOddRight, this)
, m_rpRteIcIcOddLeft                      (this, PP_RTE_ICIC_ODD_LEFT,                            NULL, 0, 0, ConfigurePPortIcIcOddLeft, this)
, m_rpRteIcCommonCroiLeft                 (this, "IcCommonCroiLeft",                              IcRect_t())
, m_rpRteIcsr                             (this, PP_RTE_ICSR ,                                    NULL, 0, 0, ConfigurePPortIcsr, this)
, m_rpRteFlspCalIntrDistRight             (this, PP_RTE_FLSP_CAL_INTR_DIST_RIGHT,                 NULL, 0, 0, ConfigurePPortFlspCalIntrDistRight, this)
, m_rpRteFlspProdData                     (this, PP_RTE_FLSP_PROD_DATA,                           NULL, 0, 0, ConfigurePPortFlspProdData, this)
, m_rpRteFlspProdIntrRight                (this, PP_RTE_FLSP_PROD_INTR_RIGHT,                     NULL, 0, 0, ConfigurePPortFlspProdIntrRight, this)
, m_rpRteSacStereoCal                     (this, PP_RTE_STEREO_CAL,                               NULL, 0, 0, ConfigurePPortSacStereoCal, this)
, m_rpRteFexCtrlOutput                    (this, PP_RTE_FEX_CTRL_OUTPUT,                          NULL, 0, 0, ConfigurePPortFexCtrlOutput, this)
, m_rpRteVehPar                           (this, PP_RTE_VEH_PAR,                                  NULL, sizeof(VehPar_t), 0, ConfigurePPort_VehPar, this)
, m_rpRteVehSig                           (this, PP_RTE_VEH_SIG,                                  NULL, sizeof(VehSig_t), 0, ConfigurePPortVehSig, this)

//NVM Signals
, m_rpRteNvmLd                            (this, PP_RTE_NVM_LD,                                   NULL, 0, 0, ConfigurePPortNvmLd, this)
, m_rpRteNvmSr                            (this, PP_RTE_NVM_SR,                                   NULL, 0, 0, ConfigurePPortNvmSr, this)
, m_rpRteNvmEcm                           (this, PP_RTE_NVM_ECM,                                  NULL, 0, 0, ConfigurePPortNvmEcm, this)
, m_rpRteNvmHla                           (this, PP_RTE_NVM_HLA,                                  NULL, 0, 0, ConfigurePPortNvmHla, this)
, m_rpRteNvmTsa                           (this, PP_RTE_NVM_TSA,                                  NULL, 0, 0, ConfigurePPortNvmTsa, this)
, m_rpRteNvmSac                           (this, PP_RTE_NVM_SAC,                                  NULL, 0, 0, ConfigurePPortNvmSac, this)
, m_rpRteNvmEmo                           (this, PP_RTE_NVM_EMO,                                  NULL, 0, 0, ConfigurePPortNvmEmo, this)

//CPAR Signals
, m_rpRteCparAldw                         (this, PP_RTE_CPAR_ALDW,                                NULL, 0, 0, ConfigurePPortCparAldw, this)
, m_rpRteCparHlaF                         (this, PP_RTE_CPAR_HLAF,                                NULL, 0, 0, ConfigurePPortCparHlaf, this)
, m_rpRteCparHlaR                         (this, PP_RTE_CPAR_HLAR,                                NULL, 0, 0, ConfigurePPortCparHlar, this)
, m_rpRteCparHla                          (this, PP_RTE_CPAR_HLA,                                 NULL, 0, 0, ConfigurePPortCparHla, this)
, m_rpRteCparSr                           (this, PP_RTE_CPAR_SR,                                  NULL, 0, 0, ConfigurePPortCparSr, this)
, m_rpRteCparSac                          (this, PP_RTE_CPAR_SAC,                                 NULL, 0, 0, ConfigurePPortCparSac, this)
, m_rpRteCparTsa                          (this, PP_RTE_CPAR_TSA,                                 NULL, 0, 0, ConfigurePPortCparTsa, this)
, m_rpRteCparEcm                          (this, PP_RTE_CPAR_ECM,                                 NULL, 0, 0, ConfigurePPortCparEcm, this)
, m_rpRteCparEmo                          (this, PP_RTE_CPAR_EMO,                                 NULL, sizeof(CPAR_Emo_t), 0, ConfigurePPortCparEmo, this)
, m_rpRteCparEmoOrigin                    (this, "CPAR_Emo_origin",                               NULL, 0, 0, GetCparEmoVersionNumber, this)

//FLSP Signals
, m_rpRteFlspImagerCharRight              (this, PP_RTE_FLSP_IMAGER_CHAR_LEFT,                    NULL, 0, 0, ConfigurePPortFlspImagerCharLeft, this)
, m_rpRteFlspProductionIntrinsicLeft      (this, PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT,           NULL, 0, 0, ConfigurePPortFlspProductionIntrinsicLeft, this)
, m_rpRteFlspStereoCallIntrinsicsLeft     (this, PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT,           NULL, 0, 0, ConfigurePPortFlspStereoCalIntrinsicLeft, this)
, m_rpRteFlspStereoCallIntrinsicsRight    (this, PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT,          NULL, 0, 0, ConfigurePPortFlspStereoCalIntrinsicRight, this)
, m_rpRteFlspStereoCalTransRot            (this, PP_RTE_FLSP_STEREO_CAL_TRANS_ROT,                NULL, 0, 0, ConfigurePPortFlspStereoCalTransRot, this)
, m_rpRteFlspTemperatureCompensationList  (this, PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST,   NULL, 0, 0, ConfigurePPortFlspCalTemperatureCompList, this)

//Dynamic Signals
, m_rpRteIcIcEvenRight                    (this, PP_RTE_ICIC_EVEN_RIGHT,                          NULL, 0, 0, ConfigurePPortIcIcEvenRight, this)
, m_rpRteIcImageStatisticEven             (this, PP_RTE_IC_IMAGE_STATISTIC_EVEN,                  NULL, 0, 0, ConfigurePPortIcImageStatisticEven, this)
, m_rpRteFCTAldwInputGen                  (this, PP_RTE_FCT_ALDW_INPUT_GEN,                       NULL, 0, 0, ConfigurePPortFctAldwGen, this)
, m_rpRteDIMInputCustom                   (this, PP_RTE_DIM_INPUT_CUSTOM,                         NULL, 0, 0, ConfigurePPortDimCustom, this)
, m_rpRteDIMInputGeneric                  (this, PP_RTE_DIM_INPUT_GENERIC,                        NULL, 0, 0, ConfigurePPortDimGeneric, this)
, m_rpRteHEADInputCustom                  (this, PP_RTE_HEAD_INPUT_CUSTOM,                        NULL, 0, 0, ConfigurePPortHeadCustom, this)
, m_rpRteHEADInputGeneric                 (this, PP_RTE_HEAD_INPUT_GENERIC,                       NULL, 0, 0, ConfigurePPortHeadGeneric, this)
, m_rpRteHMIInputData                     (this, PP_RTE_HMI_INPUT_DATA,                           NULL, 0, 0, ConfigurePPortHmiData, this)
, m_rpRteTsaInputGPS                      (this, PP_RTE_TSA_GPS ,                                 NULL, 0, 0, ConfigurePPortTsaGps, this)
, m_rpRteTsaCustomInput                   (this, PP_RTE_TSA_CUSTOM_INPUT,                         NULL, 0, 0, ConfigurePPortTsaCustom, this)
, m_rpRteEcuStateM3_0                     (this, PP_RTE_ECU_STATE_M3,                             NULL, 0, 0, ConfigurePPortEcuStateM3, this)
, m_rpRteSacStereoRoiM3_10                (this, PP_RTE_SAC_STEREO_ROI_M3,                        NULL, 0, 0, ConfigurePPortSacStereoRoiM3, this)

//Hla
, m_rpRteParPPAR_ImgCharRight             (this, PP_RTE_FLSP_IMG_CHAR_RIGHT,                      NULL, 0, 0, ConfigurePPortFLSPImagerCharacteristicsRight, this)
, m_rpRteParPPAR_RespCurveRight           (this, PP_RTE_FLSP_RESPONSE_CURVE_RIGHT,                NULL, 0, 0, ConfigurePPortFLSPResponseCurvePeriphery, this)
, m_rpRteSig_HlaSig                       (this, PP_RTE_HLA_SIGNALS,                              NULL, 0, 0, ConfigurePPortHLA_Signals, this)
, m_rpRteSig_HeadlightState               (this, PP_RTE_HLA_HEADLIGHT_STATE,                      NULL, 0, 0, ConfigurePPortHLA_HeadlightStat, this)
, m_rpMonoCalibrationLaneImager           (this, PP_MONOCALIBRATION_LANE_IMAGER,                  NULL, 0, 0, ConfigurePPortMonoCalibrationLane, this)

//Mfc310 Input Signals
, m_rp310CroiImageData        ( this, "CroiImageData",                mfc310::stereo::SACImageData_t()                   )
, m_rp310SacMountingData      ( this, "SacMountingCalibrationData",   mfc310::stereo::SACMountingCalibrationData_t()     )
, m_rp310SacIntrinsicRight    ( this, "SacIntrinsicDataRight",        mfc310::stereo::SACMeasIntrinsicCalibrationData_t())
, m_rp310SacIntrinsicLeft     ( this, "SacIntrinsicDataLeft",         mfc310::stereo::SACMeasIntrinsicCalibrationData_t())
, m_rp310Sac                  ( this, "SacRectCamPars",               mfc310::stereo::SACMeasRectCamPars_t()             )
, m_rp310IcicOdd              ( this, "IC_OddFrame_SOutput",          mfc310::ic::ICEXP_S_Output()                       )
, m_rp310IcicEven             ( this, "IC_EvenFrame_SOutput",         mfc310::ic::ICEXP_S_Output()                       )
, m_rp310Icop2                ( this, "IC_Common_OutputPart2",        mfc310::ic::IC_S_ResultsPart2()                    )
, m_rp310Icesd                ( this, "IC_Common_EmbeddedStatData",   mfc310::ic::IC_S_EmbeddedStatData()                )
, m_rp310SlopeRatioR1         ( this, "IC_SlopeRatioR1",              uint16()                                           )
, m_rp310Blacklevel           ( this, "IC_Blacklevel",                float32()                                          )
, m_rp310SacMeasObjLutLeft    ( this, "SacMeasObjLutLeft",            mfc310::stereo::sac_lut_fixedpoint_t()             )
, m_rp310SacMeasObjLutRight   ( this, "SacMeasObjLutRight",           mfc310::stereo::sac_lut_fixedpoint_t()             )
, m_rp310SacSRoiImageDataLeft ( this, "SacImageDataLeft",             mfc310::stereo::SACImageData_t()                   )
, m_rp310SacSRoiImageDataRight( this, "SacImageDataRight",            mfc310::stereo::SACImageData_t()                   )
, m_rp310SacParamIdLUTLeft    ( this, "SacParamIdLUTLeft",            uint16()                                           )
, m_rp310SacParamIdLUTRight   ( this, "SacParamIdLUTRight",           uint16()                                           )
, m_rp310LdCamDistortionK1    ( this, "LdCamDistortionK1",            float32()                                          )
, m_rp310LdCamDistortionK2    ( this, "LdCamDistortionK2",            float32()                                          )
, m_rp310SrInputConfig        ( this, "SrInputConfig",                mfc310::sr::SRIFInputConfig_t()                    )
, m_rp310SacTemperatures      ( this, "SacTemperatures",              mfc310::stereo::TempArray_t()                      )
, m_rp310SacNvm               ( this, "SacFromNvm",                   mfc310::stereo::FromToNVM_t()                      )
, m_rp310SacStatistics        ( this, "SacStatistics",                mfc310::stereo::SACStatistics_t()                  )
, m_rp310SacAngleData         ( this, "SacNvAngleData",               mfc310::stereo::SACNvAngleData_t()                 )
, m_rp310EcmSensorSocket      ( this, "EcmSensorSocket",              s_SensorSocket()                                   )
, m_rp310EcmSensorAngles      ( this, "EcmSensorAngles",              s_SensorAngles()                                   )
, m_rp310SacExtRightToLeft    ( this, "SacExtrinsicLeftToRight",      mfc310::stereo::SACExtrinsicCalibrationData_t()    )

// Sac extrinsic left to right single signals
, m_rp310SacExtRightToLeft_Baseline ( this, "SacExtRightToLeft_Baseline", float32() )
, m_rp310SacExtRightToLeft_tx       ( this, "SacExtRightToLeft_tx",       float32() )
, m_rp310SacExtRightToLeft_ty       ( this, "SacExtRightToLeft_ty",       float32() )
, m_rp310SacExtRightToLeft_tz       ( this, "SacExtRightToLeft_tz",       float32() )
, m_rp310SacExtRightToLeft_RotMat   ( this, "SacExtRightToLeft_RotMat",   float32() )

// LKA

, m_rp310VehSigVehVelocityExt       ( this, "VehSigVehVelocityExt",       float32() )
, m_rp310VehSigSpeedUnit            ( this, "VehSigSpeedUnit",            uint8()   )
, m_rp310VehSigSpeedoSpeed          ( this, "VehSigSpeedoSpeed",          float32() )
, m_rp310VehSigTurnSignal           ( this, "VehSigTurnSignal",           uint8()   )
, m_rp310VehSigStWheelAngle         ( this, "VehSigStWheelAngle",         float32() )
, m_rp310VehSigBrakeActLevel        ( this, "VehSigBrakeActLevel",        float32() )
, m_rp310VehSigChassisControlEvent  ( this, "VehSigChassisControlEvent",  uint8()   )

, m_rp310LdParameterInOut     ( this, "LdParameterInOut",             mfc310::ld::S_LDParameterInOut()                   )

, m_rp310HLARInput        ( this, "Adapter.HLAR_In", NULL, 0)

// manual calibration for mono recordings
, m_rp310SensorPitch      ( this, "SensorPitch"    , 0.0F )
, m_rp310SensorRoll       ( this, "SensorRoll"     , 0.0F )
, m_rp310SensorYaw        ( this, "SensorYaw"      , 0.0F )
, m_rp310SensorX          ( this, "SensorX"        , 0.0F )
, m_rp310SensorY          ( this, "SensorY"        , 0.0F )
, m_rp310SensorZ          ( this, "SensorZ"        , 0.0F )
, m_rp310CenterX          ( this, "CenterX"        , 0.0F )
, m_rp310CenterY          ( this, "CenterY"        , 0.0F )
, m_rp310FocalX           ( this, "FocalX"         , 0.0F )
, m_rp310FocalY           ( this, "FocalY"         , 0.0F )
, m_rp310ImageSizeX       ( this, "ImageSizeX"     , 0U   )
, m_rp310ImageSizeY       ( this, "ImageSizeY"     , 0U   )
, m_rp310CroppedRoiSizeX  ( this, "CroppedRoiSizeX", 0U   )
, m_rp310CroppedRoiSizeY  ( this, "CroppedRoiSizeY", 0U   )
, m_rp310CroppedRoiX      ( this, "CroppedRoiX"    , 0U   )
, m_rp310CroppedRoiY      ( this, "CroppedRoiY"    , 0U   )

// Converted by the GIA
, m_rp310VehSig           (VehSig_t())
, m_rp310VehDyn           (VehDyn_t())

, m_fPitchOffset        (0.0F)
, m_fRollOffset         (0.0F)
, m_fYawOffset          (0.0F)
, m_uSacMissingCnt      (0U)
, m_uAngOffsetMissingCnt(0U)
, m_b4xxData (false)
, m_bVehParReceived(false)
, m_nCparEmoOriginVersionNumber(-1)
, m_bMfc3xxUpdatePortSize(true)
//, m_algoServices        (64 * 1024, 96 * 1024, this, COMP_ID)
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "MfcWrapper version " << MFCWRAPPER_ALL_SW_MAIN_VER_NO << "." << MFCWRAPPER_ALL_SW_SUB_VER_NO << "." << MFCWRAPPER_ALL_SW_BUG_FIX_LEV << "." << MFCWRAPPER_ALL_SW_BUG_FIX_LEV2;
  dataTxt   << "MfcWrapper (MfcWrapper Simulation Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

  memset(&m_HlarRequiredInputs, 0, sizeof(m_HlarRequiredInputs));

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
  AddServerPort("Doit",  Doit,  this);
  AddServerPort("DoitImage",  DoitImage,  this);

  // Create client ports
  AddClientPort(CP_DISTRIBUTEOUTPUTDATA,      NULL, 0);
  AddClientPort(CP_DISTRIBUTEONLYDIRTYPORTS,  NULL, 0);
  AddClientPort(CP_CALCULATIONDONE,           NULL, 0, PORT_WITH_AUTOCLONE);
  AddClientPort(CP_CALCULATIONDONEIMAGE,      NULL, 0, PORT_WITH_AUTOCLONE);

  // Create algorithm ports
  SetupPorts();

  // reset "received" flags and error counters
  ResetReceivePorts();
}

CSimMfcWrapper::~CSimMfcWrapper()
{
  try
  {
    //
    m_ppRteCroiCal                = static_cast<void*>(NULL);
    m_ppRteSroiCal                = static_cast<void*>(NULL);
    m_ppRteCroiCalEol             = static_cast<void*>(NULL);
    m_ppRteCroiCalEmo             = static_cast<void*>(NULL);
    m_ppRteRroiCalEmo             = static_cast<void*>(NULL);
    m_ppRteCroiCalSemo            = static_cast<void*>(NULL);
    m_ppRteImagerCalEmo           = static_cast<void*>(NULL);
    m_ppRteFlspCalIntrDistRight   = static_cast<void*>(NULL);
    m_ppRteFlspProdData           = static_cast<void*>(NULL);
    m_ppRteFlspProdIntrRight      = static_cast<void*>(NULL);
    m_ppRteVehPar                 = static_cast<void*>(NULL);
    m_ppRteVehSig                 = static_cast<void*>(NULL);
    m_ppRteSacStereoCal           = static_cast<void*>(NULL);
    m_ppRteIcIcOddRight           = static_cast<void*>(NULL);
    m_ppRteIcIcOddLeft            = static_cast<void*>(NULL);
    m_ppRteIcsr                   = static_cast<void*>(NULL);
    m_ppRteFexCtrlOutput          = static_cast<void*>(NULL);

    //Hla
    m_ppRteParPPAR_ImgCharRight   = static_cast<void*>(NULL);
    m_ppRteParPPAR_RespCurveRight = static_cast<void*>(NULL);
    m_ppRteSig_HlaSig             = static_cast<void*>(NULL);
    m_ppRteSig_HeadlightState     = static_cast<void*>(NULL);
    m_ppMonoCalibrationLaneImager = static_cast<void*>(NULL); 

    //NVM Signals
    m_ppRteNvmLd                  = static_cast<void*>(NULL);
    m_ppRteNvmSr                  = static_cast<void*>(NULL);
    m_ppRteNvmEcm                 = static_cast<void*>(NULL);
    m_ppRteNvmHla                 = static_cast<void*>(NULL);
    m_ppRteNvmTsa                 = static_cast<void*>(NULL);
    m_ppRteNvmSac                 = static_cast<void*>(NULL);
    m_ppRteNvmEmo                 = static_cast<void*>(NULL);

    //CPAR Signals
    m_ppRteCparAldw               = static_cast<void*>(NULL);
    m_ppRteCparHlaF               = static_cast<void*>(NULL);
    m_ppRteCparHlaR               = static_cast<void*>(NULL);
    m_ppRteCparHla                = static_cast<void*>(NULL);
    m_ppRteCparSr                 = static_cast<void*>(NULL);
    m_ppRteCparSac                = static_cast<void*>(NULL);
    m_ppRteCparTsa                = static_cast<void*>(NULL);
    m_ppRteCparEcm                = static_cast<void*>(NULL);
    m_ppRteCparEmo                = static_cast<void*>(NULL);

    //FLSP Signals
    m_ppRteFlspImagerCharRight                = static_cast<void*>(NULL);
    m_ppRteFlspProductionIntrinsicLeft        = static_cast<void*>(NULL);
    m_ppRteFlspStereoCallIntrinsicsLeft       = static_cast<void*>(NULL);
    m_ppRteFlspStereoCallIntrinsicsRight      = static_cast<void*>(NULL);
    m_ppRteFlspStereoCalTransRot              = static_cast<void*>(NULL);
    m_ppRteFlspTemperatureCompensationList    = static_cast<void*>(NULL);

    //Dynamic Signals
    m_ppRteIcIcEvenRight                      = static_cast<void*>(NULL);
    m_ppRteIcImageStatisticEven               = static_cast<void*>(NULL);
    m_ppRteFCTAldwInputGen                    = static_cast<void*>(NULL);
    m_ppRteDIMInputCustom                     = static_cast<void*>(NULL);
    m_ppRteDIMInputGeneric                    = static_cast<void*>(NULL);
    m_ppRteHEADInputCustom                    = static_cast<void*>(NULL);
    m_ppRteHEADInputGeneric                   = static_cast<void*>(NULL);
    m_ppRteHMIInputData                       = static_cast<void*>(NULL);
    m_ppRteTsaInputGPS                        = static_cast<void*>(NULL);
    m_ppRteTsaCustomInput                     = static_cast<void*>(NULL);
    m_ppRteEcuStateM3_0                       = static_cast<void*>(NULL);
    m_ppRteSacStereoRoiM3_10                  = static_cast<void*>(NULL);

  }
  catch(...)
  {
  }
}

void CSimMfcWrapper::SetupPorts()
{
  // input ports
  m_rpBaseCtrlData.setVersion   ("BaseCtrlData_t",       CreateVersionInfoFromI32(BASE_CTRL_DATA_INTFVER));

  EnablePPortDirtyFlagUsage();

  // initialize input port map
  m_receivePortMap.clear();

  InitializeProvidePorts();

  //m_ppRteCroiCal              = NULL;
  //m_ppRteSroiCal              = NULL;
  //m_ppRteCroiCalEol           = NULL;
  //m_ppRteCroiCalEmo           = NULL;
  //m_ppRteRroiCalEmo           = NULL;
  //m_ppRteCroiCalSemo          = NULL;
  //m_ppRteImagerCalEmo         = NULL;
  //m_ppRteFlspCalIntrDistRight = NULL;
  //m_ppRteFlspProdData         = NULL;
  //m_ppRteFlspProdIntrRight    = NULL;
  //m_ppRteSacStereoCal         = NULL;
  //m_ppRteIcic                 = NULL;
  //m_ppRteIcsr                 = NULL;
  //m_ppRteFexCtrlOutput        = NULL;

  // Request ports pushed to the map so that they are reset correctly
  // Specially needed for dirty checks on the reference ports
  m_receivePortMap.push_back(&m_rp310HLARInput);
  m_receivePortMap.push_back(&m_rpRteNvmEmo);

  // Ports to be adapted by GIA
  AddReceivePort("VehSig310", simOPAQUE_t, &m_rp310VehSig, sizeof(m_rp310VehSig));
  SetRPortVersion("VehSig310", "VehSig_t", CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));
  AddReceivePort("VehDyn310", simOPAQUE_t, &m_rp310VehDyn, sizeof(m_rp310VehDyn));
  SetRPortVersion("VehDyn310", "VehDyn_t", CreateVersionInfoFromI32(VDY_VEH_DYN_INTFVER));

  SetRPortVersion(PP_RTE_CPAR_EMO, "CPAR_Emo_t", CreateVersionInfoFromI32(CPAR_EMO_INTFVER));
  SetRPortVersion(PP_RTE_VEH_PAR, "VehPar_t", CreateVersionInfoFromI32(BSW_VEH_PAR_INTFVER));
  SetRPortVersion(PP_RTE_VEH_SIG, "VehSig_t", CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));

  // output ports
  m_providePortMap.push_back(AddProvidePort (PP_ALGO_COMP_STATE, simOPAQUE_t, &m_ppAlgoCompState, sizeof(m_ppAlgoCompState)));
  SetPPortVersion(PP_ALGO_COMP_STATE, "AlgoCompState_t", CreateVersionInfoFromI32(COMP_STATE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CROI_CAL, simREFERENCE_t, &m_ppRteCroiCal, 0));
  SetPPortVersion(PP_RTE_CROI_CAL, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_SROI_CAL, simREFERENCE_t, &m_ppRteSroiCal, sizeof(MonoCalibration_t)));
  SetPPortVersion(PP_RTE_SROI_CAL, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_EOL_CAL_RIGHT, simREFERENCE_t, &m_ppRteCroiCalEol, sizeof(MonoCalibrationEol_t)));
  SetPPortVersion(PP_RTE_EOL_CAL_RIGHT, "MonoCalibrationEol_t", CreateVersionInfoFromI32(MONO_CALIBRATION_EOL_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CROI_CAL_EMO, simREFERENCE_t, &m_ppRteCroiCalEmo, sizeof(MonoCalibration_t)));
  SetPPortVersion(PP_RTE_CROI_CAL_EMO, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_RROI_CAL_EMO, simREFERENCE_t, &m_ppRteRroiCalEmo, sizeof(MonoCalibration_t)));
  SetPPortVersion(PP_RTE_RROI_CAL_EMO, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CROI_CAL_SEMO, simREFERENCE_t, &m_ppRteCroiCalSemo, sizeof(MonoCalibration_t)));
  SetPPortVersion(PP_RTE_CROI_CAL_SEMO, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_IMAGER_CAL_EMO, simREFERENCE_t, &m_ppRteImagerCalEmo, sizeof(MonoCalibration_t)));
  SetPPortVersion(PP_RTE_IMAGER_CAL_EMO, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_CAL_INTR_DIST_RIGHT, simREFERENCE_t, &m_ppRteFlspCalIntrDistRight, sizeof(FLSPCalIntrDistRight_t)));
  SetPPortVersion(PP_RTE_FLSP_CAL_INTR_DIST_RIGHT, "FLSPCalIntrDistRight_t", CreateVersionInfoFromI32(FLSP_CALL_INTR_DIST_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_PROD_DATA, simREFERENCE_t, &m_ppRteFlspProdData, sizeof(FLSPProductionData_t)));
  SetPPortVersion(PP_RTE_FLSP_PROD_DATA, "FLSPProductionData_t", CreateVersionInfoFromI32(FLSP_PROD_DATA_INTFVER));
  // fill FLSPProductionData_t with null
  memset(&m_ppRteFlspProdData, 0, sizeof(FLSPProductionData_t));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_PROD_INTR_RIGHT, simREFERENCE_t, &m_ppRteFlspProdIntrRight, sizeof(FLSPProductionIntrinsic_t)));
  SetPPortVersion(PP_RTE_FLSP_PROD_INTR_RIGHT, "FLSPProductionIntrinsic_t", CreateVersionInfoFromI32(FLSP_PROD_INTR_INTFVER));
  // fill FLSPProductionIntrinsic_t with null
  memset(&m_ppRteFlspProdIntrRight, 0, sizeof(FLSPProductionIntrinsic_t));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_VEH_PAR, simREFERENCE_t, &m_ppRteVehPar, sizeof(VehPar_t)));
  SetPPortVersion(PP_RTE_VEH_PAR, "VehPar_t", CreateVersionInfoFromI32(BSW_VEH_PAR_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_VEH_SIG, simREFERENCE_t, &m_ppRteVehSig, sizeof(VehSig_t)));
  SetPPortVersion(PP_RTE_VEH_SIG, "VehSig_t", CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_STEREO_CAL, simREFERENCE_t, &m_ppRteSacStereoCal, sizeof(SacRteStereoCalibrationOutput_t)));
  SetPPortVersion(PP_RTE_STEREO_CAL, "SacRteStereoCalibrationOutput_t", CreateVersionInfoFromI32(SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_ICIC_ODD_RIGHT, simREFERENCE_t, &m_ppRteIcIcOddRight, sizeof(IcImageCharacteristics_t)));
  SetPPortVersion(PP_RTE_ICIC_ODD_RIGHT, "IcImageCharacteristics_t", CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));

  m_nIcIcIddLeftPortIndex = AddProvidePort (PP_RTE_ICIC_ODD_LEFT, simREFERENCE_t, &m_ppRteIcIcOddLeft, sizeof(IcImageCharacteristics_t));
  m_providePortMap.push_back(m_nIcIcIddLeftPortIndex);
  SetPPortVersion(PP_RTE_ICIC_ODD_LEFT, "IcImageCharacteristics_t", CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_ICSR, simREFERENCE_t, &m_ppRteIcsr, sizeof(IcStatisticalResults_t)));
  SetPPortVersion(PP_RTE_ICSR, "IcStatisticalResults_t", CreateVersionInfoFromI32(IC_IMAGE_STATISTIC_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FEX_CTRL_OUTPUT, simREFERENCE_t, &m_ppRteFexCtrlOutput, sizeof(SacRteFexControlOutput_t)));
  SetPPortVersion(PP_RTE_FEX_CTRL_OUTPUT, "SacRteFexControlOutput_t", CreateVersionInfoFromI32(SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_IMG_CHAR_RIGHT, simREFERENCE_t, &m_ppRteParPPAR_ImgCharRight, sizeof(FLSPImagerCharacteristicsRight_t)));
  SetPPortVersion(PP_RTE_FLSP_IMG_CHAR_RIGHT, "FLSPImagerCharacteristicsRight_t", CreateVersionInfoFromI32(FLSP_IMAGER_CHAR_RIGHT_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_RESPONSE_CURVE_RIGHT, simREFERENCE_t, &m_ppRteParPPAR_RespCurveRight, sizeof(FLSPResponseCurvePeriphery_t)));
  SetPPortVersion(PP_RTE_FLSP_RESPONSE_CURVE_RIGHT, "FLSPResponseCurvePeriphery_t", CreateVersionInfoFromI32(FLSP_RESPONSE_CURVES_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_HLA_SIGNALS, simREFERENCE_t, &m_ppRteSig_HlaSig, sizeof(RTE_HLA_Signals_t)));
  SetPPortVersion(PP_RTE_HLA_SIGNALS, "RTE_HLA_Signals_t", CreateVersionInfoFromI32(RTE_HLA_SIGNALS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_HLA_HEADLIGHT_STATE, simREFERENCE_t, &m_ppRteSig_HeadlightState, sizeof(RTE_HLA_HeadlightState_t)));
  SetPPortVersion(PP_RTE_HLA_HEADLIGHT_STATE, "RTE_HLA_HeadlightState_t", CreateVersionInfoFromI32(RTE_HLA_HEADLIGHT_STATE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_MONOCALIBRATION_LANE_IMAGER, simREFERENCE_t, &m_ppMonoCalibrationLaneImager, sizeof(MonoCalibration_t)));
  SetPPortVersion(PP_MONOCALIBRATION_LANE_IMAGER, "MonoCalibration_t", CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

  //NVM Signals
  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_LD, simREFERENCE_t, &m_ppRteNvmLd, 0));
  SetPPortVersion(PP_RTE_NVM_LD, "NVM_LdOnlineCaliData_t", CreateVersionInfoFromI32(LD_ONLINE_CALI_DATA_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_SR, simREFERENCE_t, &m_ppRteNvmSr, 0));
  SetPPortVersion(PP_RTE_NVM_SR, "NVM_SR_RTE_t", CreateVersionInfoFromI32(NVM_SR_RTE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_ECM, simREFERENCE_t, &m_ppRteNvmEcm, 0));
  SetPPortVersion(PP_RTE_NVM_ECM, "NVM_EcmRte_t", CreateVersionInfoFromI32(NVM_ECM_RTE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_HLA, simREFERENCE_t, &m_ppRteNvmHla, 0));
  SetPPortVersion(PP_RTE_NVM_HLA, "NVM_HLAR_LearningValues_t", CreateVersionInfoFromI32(NVM_HLAR_LEARNING_VALUES_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_TSA, simREFERENCE_t, &m_ppRteNvmTsa, 0));
  SetPPortVersion(PP_RTE_NVM_TSA, "NvmTsaRteState_t", CreateVersionInfoFromI32(TSA_RTE_NVM_STATE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_SAC, simREFERENCE_t, &m_ppRteNvmSac, 0));
  SetPPortVersion(PP_RTE_NVM_SAC, "NVM_SacRte_t", CreateVersionInfoFromI32(NVM_SAC_RTE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_NVM_EMO, simREFERENCE_t, &m_ppRteNvmEmo, 0));
  SetPPortVersion(PP_RTE_NVM_EMO, "NVM_Emo_t", CreateVersionInfoFromI32(NVM_EMO_INTFVER));

  //CPAR Signals
  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_ALDW, simREFERENCE_t, &m_ppRteCparAldw, 0));
  SetPPortVersion(PP_RTE_CPAR_ALDW, "CPAR_ALDW_Parameters_t", CreateVersionInfoFromI32(CPAR_FCT_PARAMETERS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_HLAF, simREFERENCE_t, &m_ppRteCparHlaF, 0));
  SetPPortVersion(PP_RTE_CPAR_HLAF, "CPAR_HLAF_Parameter_t", CreateVersionInfoFromI32(CPAR_HLAF_PARAMETER_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_HLAR, simREFERENCE_t, &m_ppRteCparHlaR, 0));
  SetPPortVersion(PP_RTE_CPAR_HLAR, "CPAR_HLAR_Parameter_t", CreateVersionInfoFromI32(CPAR_HLAR_PARAMETER_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_HLA, simREFERENCE_t, &m_ppRteCparHla, 0));
  SetPPortVersion(PP_RTE_CPAR_HLA, "CPAR_HLA_Parameter_t", CreateVersionInfoFromI32(CPAR_HLA_PARAMETER_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_SR, simREFERENCE_t, &m_ppRteCparSr, 0));
  SetPPortVersion(PP_RTE_CPAR_SR, "CPAR_SR_RTE_parameters_t", CreateVersionInfoFromI32(SR_RTE_CODING_PARAMS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_SAC, simREFERENCE_t, &m_ppRteCparSac, 0));
  SetPPortVersion(PP_RTE_CPAR_SAC, "CPAR_SacRte_t", CreateVersionInfoFromI32(CPAR_SAC_RTE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_TSA, simREFERENCE_t, &m_ppRteCparTsa, 0));
  SetPPortVersion(PP_RTE_CPAR_TSA, "CPAR_TSA_RTE_parameters_t", CreateVersionInfoFromI32(TSA_RTE_CODING_PARAMS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_ECM, simREFERENCE_t, &m_ppRteCparEcm, 0));
  SetPPortVersion(PP_RTE_CPAR_ECM, "CPAR_EcmRte_t", CreateVersionInfoFromI32(CPAR_ECM_RTE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_CPAR_EMO, simREFERENCE_t, &m_ppRteCparEmo, 0));
  SetPPortVersion(PP_RTE_CPAR_EMO, "CPAR_Emo_t", CreateVersionInfoFromI32(CPAR_EMO_INTFVER));

  //FLSP Signals
  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_IMAGER_CHAR_LEFT, simREFERENCE_t, &m_ppRteFlspImagerCharRight, 0));
  SetPPortVersion(PP_RTE_FLSP_IMAGER_CHAR_LEFT, "FLSPImagerCharacteristicsLeft_t", CreateVersionInfoFromI32(FLSP_IMAGER_CHAR_LEFT_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT, simREFERENCE_t, &m_ppRteFlspProductionIntrinsicLeft, 0));
  SetPPortVersion(PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT, "FLSPProductionIntrinsic_t", CreateVersionInfoFromI32(FLSP_PROD_INTR_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT, simREFERENCE_t, &m_ppRteFlspStereoCallIntrinsicsLeft, 0));
  SetPPortVersion(PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT, "FLSPStereoCalIntrinsics_t", CreateVersionInfoFromI32(FLSP_STEREO_CAL_INTR_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT, simREFERENCE_t, &m_ppRteFlspStereoCallIntrinsicsRight, 0));
  SetPPortVersion(PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT, "FLSPStereoCalIntrinsics_t", CreateVersionInfoFromI32(FLSP_STEREO_CAL_INTR_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_STEREO_CAL_TRANS_ROT, simREFERENCE_t, &m_ppRteFlspStereoCalTransRot, 0));
  SetPPortVersion(PP_RTE_FLSP_STEREO_CAL_TRANS_ROT, "FLSPStereoCalTransRot_t", CreateVersionInfoFromI32(FLSP_STEREO_CAL_TRAN_ROT_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST, simREFERENCE_t, &m_ppRteFlspTemperatureCompensationList, 0));
  SetPPortVersion(PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST, "FLSPTemperatureCompensationList_t", CreateVersionInfoFromI32(FLSP_TEMP_COMP_INTFVER));

  //Dynamic Signals
  m_providePortMap.push_back(AddProvidePort (PP_RTE_ICIC_EVEN_RIGHT, simREFERENCE_t, &m_ppRteIcIcEvenRight, 0));
  SetPPortVersion(PP_RTE_ICIC_EVEN_RIGHT, "IcImageCharacteristics_t", CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_IC_IMAGE_STATISTIC_EVEN, simREFERENCE_t, &m_ppRteIcImageStatisticEven, 0));
  SetPPortVersion(PP_RTE_IC_IMAGE_STATISTIC_EVEN, "IcStatisticalResults_t", CreateVersionInfoFromI32(IC_IMAGE_STATISTIC_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_FCT_ALDW_INPUT_GEN, simREFERENCE_t, &m_ppRteFCTAldwInputGen, 0));
  SetPPortVersion(PP_RTE_FCT_ALDW_INPUT_GEN, "FCTALDWInputGeneric_t", CreateVersionInfoFromI32(FCT_LKA_INPUT_GENERIC_INTFVER)); /// ????? Correct InterfaceVersion

  m_providePortMap.push_back(AddProvidePort (PP_RTE_DIM_INPUT_CUSTOM, simREFERENCE_t, &m_ppRteDIMInputCustom, 0));
  SetPPortVersion(PP_RTE_DIM_INPUT_CUSTOM, "DIMInputCustom_t", CreateVersionInfoFromI32(FCT_DIM_INPUT_CUSTOM_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_DIM_INPUT_GENERIC, simREFERENCE_t, &m_ppRteDIMInputGeneric, 0));
  SetPPortVersion(PP_RTE_DIM_INPUT_GENERIC, "DIMInputGeneric_t", CreateVersionInfoFromI32(FCT_DIM_INPUT_GENERIC_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_HEAD_INPUT_CUSTOM, simREFERENCE_t, &m_ppRteHEADInputCustom, 0));
  SetPPortVersion(PP_RTE_HEAD_INPUT_CUSTOM, "HEADInputCustom_t", CreateVersionInfoFromI32(FCT_HEAD_INPUT_CUSTOM_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_HEAD_INPUT_GENERIC, simREFERENCE_t, &m_ppRteHEADInputGeneric, 0));
  SetPPortVersion(PP_RTE_HEAD_INPUT_GENERIC, "HEADInputGeneric_t", CreateVersionInfoFromI32(FCT_HEAD_INPUT_GENERIC_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_HMI_INPUT_DATA, simREFERENCE_t, &m_ppRteHMIInputData, 0));
  SetPPortVersion(PP_RTE_HMI_INPUT_DATA, "t_HMI_Data_t", CreateVersionInfoFromI32(HMI_INPUT_DATA));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_TSA_GPS, simREFERENCE_t, &m_ppRteTsaInputGPS, 0));
  SetPPortVersion(PP_RTE_TSA_GPS, "RteInputGPS_t", CreateVersionInfoFromI32(RTE_INPUT_GPS_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_TSA_CUSTOM_INPUT, simREFERENCE_t, &m_ppRteTsaCustomInput, 0));
  SetPPortVersion(PP_RTE_TSA_CUSTOM_INPUT, "TsaRteCustomInput_t", CreateVersionInfoFromI32(TSA_RTE_CUSTOM_INPUT_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_ECU_STATE_M3, simREFERENCE_t, &m_ppRteEcuStateM3_0, 0));
  SetPPortVersion(PP_RTE_ECU_STATE_M3, "EcuState_t", CreateVersionInfoFromI32(ECU_STATE_INTFVER));

  m_providePortMap.push_back(AddProvidePort (PP_RTE_SAC_STEREO_ROI_M3, simREFERENCE_t, &m_ppRteSacStereoRoiM3_10, 0));
  SetPPortVersion(PP_RTE_SAC_STEREO_ROI_M3, "SacRteStereoRoiInput_t", CreateVersionInfoFromI32(SAC_RTE_STEREO_ROI_INPUT_INTFVER));
}

void CSimMfcWrapper::ResetReceivePorts()
{
  for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
  {
    SimReceivePortBase& port = **i;
    port.setNotDirty();
  }
}

void CSimMfcWrapper::Reset()
{
  // reset received flags
  ResetReceivePorts();

  // reset portsize and versionnumber
  ResetProvidePortSizeAndVersionnumber();

  // setting for default values is only done if adapter is available
  FillRPortDefaultValues(Doit, this);

  // mark RPorts as not dirty
  ResetRPortDirtyFlags(Doit, this);

  m_b4xxData = false;
  m_bVehParReceived = false;
  m_bMfc3xxUpdatePortSize = true;
  m_nCparEmoOriginVersionNumber = -1;

  InitializeProvidePorts();

  m_TimstampFixer.Reset();

  // TODO: Place reset stuff
}

void CSimMfcWrapper::Init()
{
  m_TimstampFixer.Init();
  // TODO: Place initialization stuff
}

void CSimMfcWrapper::Doit()
{
  // check if all ports receive data
  if(m_bCheckInput)
  {
    CheckPortsDataReceived();
  }

  // execute the algo calculation
  FillRPortDefaultValues(Doit, this);

  //! send cycle start
  MEASSendCycleStartMTS (CYLCE_ID);

  MainCall();

  //! send cycle end
  MEASSendCycleEndMTS (CYLCE_ID);

  if (!m_b4xxData && ReceivedAnyMFC3xxData() )
  {

    //Meas Freeze MFC3xx Data
    MeasFreezeMFC3xxData();

    //trigger distribute data (only distribute the ports which are not related to the image)
    ProvidePortMap_t::iterator it = m_providePortMap.begin();
    while (it != m_providePortMap.end())
    {
      SetPPortDirty(*it);
      it++;
    }
  }

  TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);

  // trigger done port
  TriggerEvent(CP_CALCULATIONDONE, 0, 0);
}

void CSimMfcWrapper::DoitImage()
{
  if (m_TimstampFixer.Doit(m_b4xxData) == SIM_ERR_OK)
  {
    //trigger distribute data
    TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);

    // trigger done port
    TriggerEvent(CP_CALCULATIONDONEIMAGE, 0, 0);
  }
}

void CSimMfcWrapper::CheckPortsDataReceived()
{
  m_bCheckInput = false;
  // general data loss handling
  for (ReceivePortMap_t::iterator i = m_receivePortMap.begin(); i != m_receivePortMap.end(); ++i)
  {
    SimReceivePortBase& port = **i;
    //missing input handling
    if(!port.isDirty())
    {
      m_bCheckInput = true; 
    }
  }
}

void CSimMfcWrapper::MainCall()
{
  if(!m_b4xxData)
  {
    InitializeCparsDefault();

    // Copy the signal contained in the request port
    memcpy(&m_oRteVehSig, &m_rp310VehSig, sizeof(m_oRteVehSig));

    // EMO NVM Handling
    // Do only something, if data is not recived
    if (!m_rpRteNvmEmo.isDirty())
    {
      memset(&m_oRteNvmEmo, 0, sizeof(m_oRteNvmEmo));
      m_oRteNvmEmo.uiVersionNumber = 0xFFFFFFFF;
      m_oRteNvmEmo.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
      m_ppRteNvmEmo = &m_oRteNvmEmo;
    }

    // camera mono calibration based on sac data (stereo video)
    if ( m_rp310CroiImageData.isDirty()
      && m_rp310SacIntrinsicRight.isDirty()
      && m_rp310SacMountingData.isDirty() )
    {
      m_uSacMissingCnt = 0;

      wrapCroiCalibration(
        m_rp310CroiImageData.val(),
        m_rp310SacMountingData.val(),
        m_rp310SacIntrinsicRight.val(),
        m_oRteCroiCal );
      m_ppRteCroiCal = &m_oRteCroiCal;

      wrapCroiCalibrationEol(
        m_rp310CroiImageData.val(),
        m_rp310SacMountingData.val(),
        m_rp310SacIntrinsicRight.val(),
        m_oRteCroiCalEol );
      m_ppRteCroiCalEol = &m_oRteCroiCalEol;

      // wrap  m_oRteFexCtrlOutput data
      if ( m_rp310SacMeasObjLutLeft.isDirty()
        && m_rp310SacMeasObjLutRight.isDirty()
        && m_rp310SacSRoiImageDataLeft.isDirty()
        && m_rp310SacSRoiImageDataRight.isDirty())
      {
        uint16 uParameterIdLUTLeft = 0U;
        uint16 uParameterIdLUTRight = 0U;

        if(m_rp310SacParamIdLUTLeft.isDirty())
        {
          uParameterIdLUTLeft = m_rp310SacParamIdLUTLeft.val();
        }
        if(m_rp310SacParamIdLUTRight.isDirty())
        {
          uParameterIdLUTRight = m_rp310SacParamIdLUTRight.val();
        }

  #ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
        wrapFexControlOutput(
          m_rp310SacMeasObjLutLeft.val(), 
          m_rp310SacMeasObjLutRight.val(), 
          m_rp310SacSRoiImageDataLeft.val(),
          m_rp310SacSRoiImageDataRight.val(),
          uParameterIdLUTLeft,
          uParameterIdLUTRight,
          m_oRteFexCtrlOutput);
        m_ppRteFexCtrlOutput = &m_oRteFexCtrlOutput;
  #endif
      }

      // fill MonoCailbrationEmoCRoi
      m_ppRteCroiCalEmo = &m_oRteCroiCal;
      
      // fill MonoCailbrationEmoRRoi
      memcpy(&m_oRteRroiCalEmo, &m_oRteCroiCal, sizeof(MonoCalibration_t));
      m_oRteRroiCalEmo.sIntrinsic.fCenterX -= m_oRteCroiCalEol.sReducedRoi.uiX;
      m_oRteRroiCalEmo.sIntrinsic.fCenterY -= m_oRteCroiCalEol.sReducedRoi.uiY;
      m_ppRteRroiCalEmo = &m_oRteRroiCalEmo;

      // fill MonoCalibrationImagerEmo
      memcpy(&m_oRteImagerCalEmo, &m_oRteCroiCal, sizeof(MonoCalibration_t));
      m_oRteImagerCalEmo.sIntrinsic.fCenterX = m_rp310SacIntrinsicRight.val().CenterX;
      m_oRteImagerCalEmo.sIntrinsic.fCenterY = m_rp310SacIntrinsicRight.val().CenterY;
      m_ppRteImagerCalEmo = &m_oRteImagerCalEmo;
    }

    // camera mono calibration based on custom calibration data
    else if(m_rp310SensorPitch.isDirty() && m_rp310SensorX.isDirty() && m_rp310CroppedRoiSizeX.isDirty()  && (m_uSacMissingCnt > 3U))
    {
      // wrapper for mfc312 mono camera
      mfc310::stereo::SACImageData_t sacImageData;
      mfc310::stereo::SACMountingCalibrationData_t sacMountingCalibData;
      mfc310::stereo::SACMeasIntrinsicCalibrationData_t sacIntrinisicCalibData;

      sacImageData.ImgHeight = static_cast<uint16>(m_rp310ImageSizeY.val());
      sacImageData.ImgWidth = static_cast<uint16>(m_rp310ImageSizeX.val());
      sacImageData.ROIHeight = static_cast<uint16>(m_rp310CroppedRoiSizeY.val());
      sacImageData.ROIStartRelCroiX = 0U;
      sacImageData.ROIStartRelCroiY = 0U;
      sacImageData.ROIStartX = static_cast<uint16>(m_rp310CroppedRoiX.val());
      sacImageData.ROIStartY = static_cast<uint16>(m_rp310CroppedRoiY.val());
      sacImageData.ROIWidth = static_cast<uint16>(m_rp310CroppedRoiSizeX.val());
      sacImageData.VersionNumber = 0U;

      sacMountingCalibData.DeltaPitch = 0.0F;
      sacMountingCalibData.DeltaRoll = 0.0F;
      sacMountingCalibData.DeltaYaw = 0.0F;
      sacMountingCalibData.Pitch = static_cast<float32>(m_rp310SensorPitch.val());
      sacMountingCalibData.PositionX = static_cast<float32>(m_rp310SensorX.val());
      sacMountingCalibData.PositionY = static_cast<float32>(m_rp310SensorY.val());
      sacMountingCalibData.PositionZ = static_cast<float32>(m_rp310SensorZ.val());
      sacMountingCalibData.Quality = 0.0F;
      sacMountingCalibData.Roll = static_cast<float32>(m_rp310SensorRoll.val());
      sacMountingCalibData.VersionNumber = 0U;
      sacMountingCalibData.Yaw = static_cast<float32>(m_rp310SensorYaw.val());

      sacIntrinisicCalibData.CenterX = static_cast<float32>(m_rp310CenterX.val());
      sacIntrinisicCalibData.CenterY = static_cast<float32>(m_rp310CenterY.val());
      sacIntrinisicCalibData.FocalX = static_cast<float32>(m_rp310FocalX.val());
      sacIntrinisicCalibData.FocalY = static_cast<float32>(m_rp310FocalY.val());

      if(m_uAngOffsetMissingCnt < 10U)
      {
        sacMountingCalibData.DeltaPitch = m_fPitchOffset;
        sacMountingCalibData.DeltaRoll = m_fRollOffset;
        sacMountingCalibData.DeltaYaw = m_fYawOffset;
      }

      for(uint32 uDistNr = 0; uDistNr < SAC_MEAS_NumRadDistCoeff; uDistNr++)
      {
        sacIntrinisicCalibData.RadialDistortion[uDistNr] = 0.0F;
      }
      
      wrapCroiCalibration(
        sacImageData,
        sacMountingCalibData,
        sacIntrinisicCalibData,
        m_oRteCroiCal );
      m_ppRteCroiCal = &m_oRteCroiCal;

      wrapCroiCalibrationEol(
        sacImageData,
        sacMountingCalibData,
        sacIntrinisicCalibData,
        m_oRteCroiCalEol );
      m_ppRteCroiCalEol = &m_oRteCroiCalEol;
      

  #ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
      // fill m_oRteFexCtrlOutput with null
      memset(&m_oRteFexCtrlOutput, 0x0, sizeof(SacRteFexControlOutput_t));
      m_ppRteFexCtrlOutput = &m_oRteFexCtrlOutput;
  #endif

      // fill MonoCailbrationEmoCRoi
      m_ppRteCroiCalEmo = &m_oRteCroiCal;

      // fill MonoCailbrationEmoRRoi
      memcpy(&m_oRteRroiCalEmo, &m_oRteCroiCal, sizeof(MonoCalibration_t));
      m_oRteRroiCalEmo.sIntrinsic.fCenterX -= 80.0F;
      m_oRteRroiCalEmo.sIntrinsic.fCenterY -= 0.0F;
      m_ppRteRroiCalEmo = &m_oRteRroiCalEmo;

      // fill MonoCalibrationImagerEmo
      memcpy(&m_oRteImagerCalEmo, &m_oRteCroiCal, sizeof(MonoCalibration_t));
      m_oRteImagerCalEmo.sIntrinsic.fCenterX = sacIntrinisicCalibData.CenterX;
      m_oRteImagerCalEmo.sIntrinsic.fCenterY = sacIntrinisicCalibData.CenterY;
      m_ppRteImagerCalEmo = &m_oRteImagerCalEmo;
      
    }

    else
    {
      // increase sac missing counter
      m_uSacMissingCnt++;
    }

    if(m_rp310HLARInput.isDirty() && m_rp310HLARInput.val())
    {
      WrapHlaData();

      // The existence of the wrapped HLA data is a mandatory condition for WrapVehSig to be adapted
      // Modify it if possible
      if ( m_rp310VehSigSpeedoSpeed.isDirty()
        && m_rp310VehSigSpeedUnit.isDirty()
        && m_rp310VehSigVehVelocityExt.isDirty()
        && m_rp310VehSigSpeedUnit.isDirty()
        && m_rp310VehSigSpeedoSpeed.isDirty()
        && m_rp310VehSigTurnSignal.isDirty()
        && m_rp310VehSigStWheelAngle.isDirty()
        && m_rp310VehSigBrakeActLevel.isDirty()
        && m_rp310VehSigChassisControlEvent.isDirty() )
      {
        WrapVehSig( m_oRteVehSig,
          m_rp310VehSigVehVelocityExt.val(),
          m_rp310VehSigSpeedUnit.val(),
          m_rp310VehSigSpeedoSpeed.val(),
          m_rp310VehSigTurnSignal.val(),
          m_rp310VehSigStWheelAngle.val(),
          m_rp310VehSigBrakeActLevel.val(),
          m_rp310VehSigChassisControlEvent.val()
          );
      }

      // Bring the modifications to the provide port
      m_ppRteVehSig = &m_oRteVehSig;

      WrapFCT();
    }
    


  #ifdef SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER
    // camera stereo calibration...
    if ( m_rp310Sac.isDirty() )
    {
      wrapStereoCalibration( m_rp310Sac.val(), m_oRteSroiCal, m_oRteSacStereoCal);
      m_ppRteSroiCal      = &m_oRteSroiCal;
      m_ppRteSacStereoCal = &m_oRteSacStereoCal;
    }
  #endif

    // wrap FLSPCalIntrDistRight_t
    if( m_rp310LdCamDistortionK1.isDirty() && m_rp310LdCamDistortionK2.isDirty() )
    {
      m_oRteFlspCalIntrDistRight.f32_InR_DistMonoK1 = m_rp310LdCamDistortionK1.val();
      m_oRteFlspCalIntrDistRight.f32_InR_DistMonoK2 = m_rp310LdCamDistortionK2.val();
      m_oRteFlspCalIntrDistRight.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
      m_oRteFlspCalIntrDistRight.sSignalHeader.uiCycleCounter = 0U;
      m_oRteFlspCalIntrDistRight.sSignalHeader.uiMeasurementCounter = 0U;
      m_oRteFlspCalIntrDistRight.sSignalHeader.uiTimeStamp = 0U;
      m_oRteFlspCalIntrDistRight.uiVersionNumber = FLSP_CALL_INTR_DIST_INTFVER;
    }
    else
    {
      // fill FLSPCalIntrDistRight_t with null
      memset(&m_oRteFlspCalIntrDistRight, 0x0, sizeof(FLSPCalIntrDistRight_t));

    }
    m_ppRteFlspCalIntrDistRight = &m_oRteFlspCalIntrDistRight;

    // wrap FLSPProductionData_t
    if( m_rp310SrInputConfig.isDirty() )
    {
      m_oRteFlspProdData.uiVersionNumber = FLSP_PROD_DATA_INTFVER;
      m_oRteFlspProdData.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
      m_oRteFlspProdData.sSignalHeader.uiCycleCounter = 0U;
      m_oRteFlspProdData.sSignalHeader.uiMeasurementCounter = 0U;
      m_oRteFlspProdData.sSignalHeader.uiTimeStamp = 0U;

      // currently wrapping implemented for SR only
      memcpy(&m_oRteFlspProdData.uSerialNumber, &m_rp310SrInputConfig.val().ECUConfig.ECUSerialNumber, sizeof(m_oRteFlspProdData.uSerialNumber));
      m_ppRteFlspProdData = &m_oRteFlspProdData;
    }
    
    // ECU State
    if( m_rp310SacTemperatures.isDirty())
    {
      mfc310::stereo::TempArray_t temperature = m_rp310SacTemperatures.val();
      // SigHeader
      m_oRteEcuStateM3_0.uiVersionNumber                 = ECU_STATE_INTFVER;
      m_oRteEcuStateM3_0.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteEcuStateM3_0.sSigHeader.uiCycleCounter       = (AlgoCycleCounter_t) temperature.TFStamp.FrameCount;
      m_oRteEcuStateM3_0.sSigHeader.uiMeasurementCounter = (AlgoCycleCounter_t) temperature.TFStamp.FrameCount;
      m_oRteEcuStateM3_0.sSigHeader.uiTimeStamp          = (AlgoDataTimeStamp_t)(temperature.TFStamp.Timestamp & 0xFFFFFFFF);

      m_oRteEcuStateM3_0.uiTemperatureValidEntryCount = temperature.noOfEntries;

     	// aTemperature_array_t aTemperature
      memset(&(m_oRteEcuStateM3_0.aTemperature[0]), 0, sizeof(float32) * 10);
      for (uint16 i = 0; i < temperature.noOfEntries; i++)
      {
        m_oRteEcuStateM3_0.aTemperature[i] = temperature.temperat[i];
      }

      m_ppRteEcuStateM3_0      = &m_oRteEcuStateM3_0;
    }
    else
    {
      // No Signal Available --> Set Signals to Invalid
      memset(&m_oRteEcuStateM3_0, 0, sizeof(m_oRteEcuStateM3_0));
      m_oRteEcuStateM3_0.uiVersionNumber                               = ECU_STATE_INTFVER;
      m_oRteEcuStateM3_0.sSigHeader.eSigStatus                         = AL_SIG_STATE_INVALID;

      m_ppRteEcuStateM3_0      = &m_oRteEcuStateM3_0;
    }

    // Stereo Roi
    if( m_rp310SacSRoiImageDataLeft.isDirty() && m_rp310SacSRoiImageDataRight.isDirty())
    {
      mfc310::stereo::SACImageData_t imageDataLeft  = m_rp310SacSRoiImageDataLeft.val();
      mfc310::stereo::SACImageData_t imageDataRight = m_rp310SacSRoiImageDataRight.val();

      // SignalHeader
      m_oRteSacStereoRoiM3_10.uiVersionNumber                    = SAC_RTE_STEREO_ROI_INPUT_INTFVER;
      m_oRteSacStereoRoiM3_10.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteSacStereoRoiM3_10.sSignalHeader.uiCycleCounter       = 0; // NOT AVAILABLE
      m_oRteSacStereoRoiM3_10.sSignalHeader.uiMeasurementCounter = 0; // NOT AVAILABLE
      m_oRteSacStereoRoiM3_10.sSignalHeader.uiTimeStamp          = 0; // NOT AVAILABLE

      // SacRteImageAndRoiParameters_t sStereoRoiCurrentRight
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.uiVersionNumber = 1;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.sSignalHeader.uiCycleCounter       = (AlgoCycleCounter_t)imageDataRight.TFStamp.FrameCount;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.sSignalHeader.uiMeasurementCounter = (AlgoCycleCounter_t)imageDataRight.TFStamp.FrameCount; // NOT AVAILABLE
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.sSignalHeader.uiTimeStamp          = (AlgoDataTimeStamp_t)(imageDataRight.TFStamp.Timestamp & 0xFFFFFFFF);
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ROIStartX                          = imageDataRight.ROIStartX;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ROIStartY                          = imageDataRight.ROIStartY;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ROIStartRelCroiX                   = imageDataRight.ROIStartRelCroiX;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ROIStartRelCroiY                   = imageDataRight.ROIStartRelCroiY;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ROIWidth                           = imageDataRight.ROIWidth;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ROIHeight                          = imageDataRight.ROIHeight;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ImgWidth                           = imageDataRight.ImgWidth;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentRight.ImgHeight                          = imageDataRight.ImgHeight;

      // SacRteImageAndRoiParameters_t sStereoRoiCurrentLeft
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.uiVersionNumber = 1;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.sSignalHeader.uiCycleCounter       = (AlgoCycleCounter_t)imageDataLeft.TFStamp.FrameCount;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.sSignalHeader.uiMeasurementCounter = (AlgoCycleCounter_t)imageDataLeft.TFStamp.FrameCount; // NOT AVAILABLE
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.sSignalHeader.uiTimeStamp          = (AlgoDataTimeStamp_t)(imageDataLeft.TFStamp.Timestamp & 0xFFFFFFFF);
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ROIStartX                          = imageDataLeft.ROIStartX;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ROIStartY                          = imageDataLeft.ROIStartY;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ROIStartRelCroiX                   = imageDataLeft.ROIStartRelCroiX;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ROIStartRelCroiY                   = imageDataLeft.ROIStartRelCroiY;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ROIWidth                           = imageDataLeft.ROIWidth;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ROIHeight                          = imageDataLeft.ROIHeight;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ImgWidth                           = imageDataLeft.ImgWidth;
      m_oRteSacStereoRoiM3_10.sStereoRoiCurrentLeft.ImgHeight                          = imageDataLeft.ImgHeight;
      
      m_ppRteSacStereoRoiM3_10 = &m_oRteSacStereoRoiM3_10;
    }
    else
    {
      // No Signal Available --> Set Signals to Invalid
      memset(&m_oRteSacStereoRoiM3_10, 0, sizeof(m_oRteSacStereoRoiM3_10));
      m_oRteSacStereoRoiM3_10.uiVersionNumber                          = SAC_RTE_STEREO_ROI_INPUT_INTFVER;
      m_oRteSacStereoRoiM3_10.sSignalHeader.eSigStatus                 = AL_SIG_STATE_INVALID;

      // Set Output Pointer
      m_ppRteSacStereoRoiM3_10 = &m_oRteSacStereoRoiM3_10;
    }

    // Wrap ECM_NVM
    if( m_rp310EcmSensorSocket.isDirty() && m_rp310EcmSensorAngles.isDirty() /*m_rp310SacMountingData.isDirty()*/ )
    {
      m_oRteNvmEcm.uiVersionNumber                              = NVM_ECM_RTE_INTFVER;

      // SignalHeader_t sSignalHeader
      m_oRteNvmEcm.sSignalHeader.eSigStatus                     = AL_SIG_STATE_OK;
      m_oRteNvmEcm.sSignalHeader.uiCycleCounter                 = 0; // NOT AVAILABLE
      m_oRteNvmEcm.sSignalHeader.uiMeasurementCounter           = 0; // NOT AVAILABLE
      m_oRteNvmEcm.sSignalHeader.uiTimeStamp                    = 0; // NOT AVAILABLE

      // PoseParameters_t sPoseCalibration
      // RIGHT
      m_oRteNvmEcm.sPoseCalibration.fPitch      = m_rp310EcmSensorAngles.val().f32_Pitch;
      m_oRteNvmEcm.sPoseCalibration.fPitchSigma = 0;
      m_oRteNvmEcm.sPoseCalibration.fRoll       = m_rp310EcmSensorAngles.val().f32_Roll;
      m_oRteNvmEcm.sPoseCalibration.fRollSigma  = 0;
      m_oRteNvmEcm.sPoseCalibration.fYaw        = m_rp310EcmSensorAngles.val().f32_Yaw;
      m_oRteNvmEcm.sPoseCalibration.fYawSigma   = 0;
      m_oRteNvmEcm.sPoseCalibration.fTx         = m_rp310EcmSensorSocket.val().f32_X;
      m_oRteNvmEcm.sPoseCalibration.fTxSigma    = 0;
      m_oRteNvmEcm.sPoseCalibration.fTy         = m_rp310EcmSensorSocket.val().f32_Y;
      m_oRteNvmEcm.sPoseCalibration.fTySigma    = 0;
      m_oRteNvmEcm.sPoseCalibration.fTz         = m_rp310EcmSensorSocket.val().f32_Z;
      m_oRteNvmEcm.sPoseCalibration.fTzSigma    = 0;
      // calc 3x4 transformation matrix...
      viscr_mat33 rotmat;
      viscr_XYZFixedAngles2RotationMatrix(rotmat, m_oRteNvmEcm.sPoseCalibration.fPitch, m_oRteNvmEcm.sPoseCalibration.fYaw, m_oRteNvmEcm.sPoseCalibration.fRoll);
      // [A00 A01 A02 A03]   [R00 R01 R02 Tx]
      // [A10 A11 A12 A13] = [R10 R11 R12 Ty]
      // [A20 A21 A22 A23]   [R20 R21 R22 Tz]
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA00       = - rotmat.m(2, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA01       = - rotmat.m(0, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA02       = - rotmat.m(1, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA10       = - rotmat.m(2, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA11       = - rotmat.m(0, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA12       = - rotmat.m(1, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA20       = rotmat.m(2, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA21       = rotmat.m(0, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA22       = rotmat.m(1, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA03       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA00 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA01 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA02;
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA13       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA10 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA11 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA12;
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA23       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA20 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA21 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA22;

      //m_oRteNvmEcm.sPoseCalibration.fTy;
      //m_oRteNvmEcm.sPoseCalibration.fTz;
      
      m_oRteNvmEcm.sPoseCalibration.uiPitchQuality        = 100;
      m_oRteNvmEcm.sPoseCalibration.uiRollQuality         = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTotalAngleQuality   = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTotalTranslQuality  = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTxQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTyQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTzQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiYawQuality          = 100;

      m_oRteNvmEcm.sEcmRteSensorSocketEol.fX              = m_oRteNvmEcm.sPoseCalibration.fTx;
      m_oRteNvmEcm.sEcmRteSensorSocketEol.fY              = m_oRteNvmEcm.sPoseCalibration.fTy;
      m_oRteNvmEcm.sEcmRteSensorSocketEol.fZ              = m_oRteNvmEcm.sPoseCalibration.fTz; 
      
      m_oRteNvmEcm.sSensorAnglesEol.f32_Pitch             = m_oRteNvmEcm.sPoseCalibration.fPitch;
      m_oRteNvmEcm.sSensorAnglesEol.f32_Roll              = m_oRteNvmEcm.sPoseCalibration.fRoll;
      m_oRteNvmEcm.sSensorAnglesEol.f32_Yaw               = m_oRteNvmEcm.sPoseCalibration.fYaw;
      m_oRteNvmEcm.sSensorAnglesEol.ui32_Quality          = 100;

      memset(&m_oRteNvmEcm.sCompState, 0, sizeof(m_oRteNvmEcm.sCompState)); 
      m_oRteNvmEcm.sCompState.eCompState = COMP_STATE_SUCCESS;

      m_ppRteNvmEcm                                       = &m_oRteNvmEcm;

    }
    else if(m_rp310SacMountingData.isDirty())
    {
      m_oRteNvmEcm.uiVersionNumber                              = NVM_ECM_RTE_INTFVER;

      // SignalHeader_t sSignalHeader
      m_oRteNvmEcm.sSignalHeader.eSigStatus                     = AL_SIG_STATE_OK;
      m_oRteNvmEcm.sSignalHeader.uiCycleCounter                 = 0; // NOT AVAILABLE
      m_oRteNvmEcm.sSignalHeader.uiMeasurementCounter           = 0; // NOT AVAILABLE
      m_oRteNvmEcm.sSignalHeader.uiTimeStamp                    = 0; // NOT AVAILABLE

      // PoseParameters_t sPoseCalibration
      // RIGHT
      m_oRteNvmEcm.sPoseCalibration.fPitch      = m_rp310SacMountingData.val().Pitch;
      m_oRteNvmEcm.sPoseCalibration.fPitchSigma = 0;
      m_oRteNvmEcm.sPoseCalibration.fRoll       = m_rp310SacMountingData.val().Roll;
      m_oRteNvmEcm.sPoseCalibration.fRollSigma  = 0;
      m_oRteNvmEcm.sPoseCalibration.fYaw        = m_rp310SacMountingData.val().Yaw;
      m_oRteNvmEcm.sPoseCalibration.fYawSigma   = 0;
      m_oRteNvmEcm.sPoseCalibration.fTx         = m_rp310SacMountingData.val().PositionX;
      m_oRteNvmEcm.sPoseCalibration.fTxSigma    = 0;
      m_oRteNvmEcm.sPoseCalibration.fTy         = m_rp310SacMountingData.val().PositionY;
      m_oRteNvmEcm.sPoseCalibration.fTySigma    = 0;
      m_oRteNvmEcm.sPoseCalibration.fTz         = m_rp310SacMountingData.val().PositionZ;
      m_oRteNvmEcm.sPoseCalibration.fTzSigma    = 0;
      // calc 3x4 transformation matrix...
      viscr_mat33 rotmat;
      viscr_XYZFixedAngles2RotationMatrix(rotmat, m_oRteNvmEcm.sPoseCalibration.fPitch, m_oRteNvmEcm.sPoseCalibration.fYaw, m_oRteNvmEcm.sPoseCalibration.fRoll);
      // [A00 A01 A02 A03]   [R00 R01 R02 Tx]
      // [A10 A11 A12 A13] = [R10 R11 R12 Ty]
      // [A20 A21 A22 A23]   [R20 R21 R22 Tz]
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA00       = - rotmat.m(2, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA01       = - rotmat.m(0, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA02       = - rotmat.m(1, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA10       = - rotmat.m(2, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA11       = - rotmat.m(0, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA12       = - rotmat.m(1, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA20       = rotmat.m(2, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA21       = rotmat.m(0, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA22       = rotmat.m(1, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA03       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA00 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA01 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA02;
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA13       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA10 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA11 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA12;
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA23       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA20 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA21 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA22;

      //m_oRteNvmEcm.sPoseCalibration.fTy;
      //m_oRteNvmEcm.sPoseCalibration.fTz;
      
      m_oRteNvmEcm.sPoseCalibration.uiPitchQuality        = 100;
      m_oRteNvmEcm.sPoseCalibration.uiRollQuality         = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTotalAngleQuality   = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTotalTranslQuality  = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTxQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTyQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTzQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiYawQuality          = 100;

      m_oRteNvmEcm.sEcmRteSensorSocketEol.fX              = m_oRteNvmEcm.sPoseCalibration.fTx;
      m_oRteNvmEcm.sEcmRteSensorSocketEol.fY              = m_oRteNvmEcm.sPoseCalibration.fTy;
      m_oRteNvmEcm.sEcmRteSensorSocketEol.fZ              = m_oRteNvmEcm.sPoseCalibration.fTz; 
      
      m_oRteNvmEcm.sSensorAnglesEol.f32_Pitch             = m_oRteNvmEcm.sPoseCalibration.fPitch;
      m_oRteNvmEcm.sSensorAnglesEol.f32_Roll              = m_oRteNvmEcm.sPoseCalibration.fRoll;
      m_oRteNvmEcm.sSensorAnglesEol.f32_Yaw               = m_oRteNvmEcm.sPoseCalibration.fYaw;
      m_oRteNvmEcm.sSensorAnglesEol.ui32_Quality          = 100;

      memset(&m_oRteNvmEcm.sCompState, 0, sizeof(m_oRteNvmEcm.sCompState)); 
      m_oRteNvmEcm.sCompState.eCompState = COMP_STATE_SUCCESS;

      m_ppRteNvmEcm                                       = &m_oRteNvmEcm;

    }
    else if( m_rp310HLARInput.isDirty() && m_rp310HLARInput.val() != 0)
    {
      m_oRteNvmEcm.uiVersionNumber                              = NVM_ECM_RTE_INTFVER;

      // SignalHeader_t sSignalHeader
      m_oRteNvmEcm.sSignalHeader.eSigStatus                     = AL_SIG_STATE_OK;
      m_oRteNvmEcm.sSignalHeader.uiCycleCounter                 = 0; // NOT AVAILABLE
      m_oRteNvmEcm.sSignalHeader.uiMeasurementCounter           = 0; // NOT AVAILABLE
      m_oRteNvmEcm.sSignalHeader.uiTimeStamp                    = 0; // NOT AVAILABLE

      // PoseParameters_t sPoseCalibration
      // RIGHT
      m_oRteNvmEcm.sPoseCalibration.fPitch      = m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Pitch;
      m_oRteNvmEcm.sPoseCalibration.fPitchSigma = 0;
      m_oRteNvmEcm.sPoseCalibration.fRoll       = m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Roll;
      m_oRteNvmEcm.sPoseCalibration.fRollSigma  = 0;
      m_oRteNvmEcm.sPoseCalibration.fYaw        = m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Yaw;
      m_oRteNvmEcm.sPoseCalibration.fYawSigma   = 0;
      m_oRteNvmEcm.sPoseCalibration.fTx         = m_HlarRequiredInputs.s_Par.s_SensorSocket.f32_X;
      m_oRteNvmEcm.sPoseCalibration.fTxSigma    = 0;
      m_oRteNvmEcm.sPoseCalibration.fTy         = m_HlarRequiredInputs.s_Par.s_SensorSocket.f32_Y;
      m_oRteNvmEcm.sPoseCalibration.fTySigma    = 0;
      m_oRteNvmEcm.sPoseCalibration.fTz         = m_HlarRequiredInputs.s_Par.s_SensorSocket.f32_Z;
      m_oRteNvmEcm.sPoseCalibration.fTzSigma    = 0;
      // calc 3x4 transformation matrix...
      viscr_mat33 rotmat;
      viscr_XYZFixedAngles2RotationMatrix(rotmat, m_oRteNvmEcm.sPoseCalibration.fPitch, m_oRteNvmEcm.sPoseCalibration.fYaw, m_oRteNvmEcm.sPoseCalibration.fRoll);
      // [A00 A01 A02 A03]   [R00 R01 R02 Tx]
      // [A10 A11 A12 A13] = [R10 R11 R12 Ty]
      // [A20 A21 A22 A23]   [R20 R21 R22 Tz]
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA00       = - rotmat.m(2, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA01       = - rotmat.m(0, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA02       = - rotmat.m(1, 0);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA10       = - rotmat.m(2, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA11       = - rotmat.m(0, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA12       = - rotmat.m(1, 1);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA20       = rotmat.m(2, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA21       = rotmat.m(0, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA22       = rotmat.m(1, 2);
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA03       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA00 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA01 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA02;
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA13       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA10 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA11 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA12;
      m_oRteNvmEcm.sPoseCalibration.sTransform.fA23       = - m_oRteNvmEcm.sPoseCalibration.fTx * m_oRteNvmEcm.sPoseCalibration.sTransform.fA20 - m_oRteNvmEcm.sPoseCalibration.fTy * m_oRteNvmEcm.sPoseCalibration.sTransform.fA21 - m_oRteNvmEcm.sPoseCalibration.fTz * m_oRteNvmEcm.sPoseCalibration.sTransform.fA22;

      //m_oRteNvmEcm.sPoseCalibration.fTy;
      //m_oRteNvmEcm.sPoseCalibration.fTz;

      // valid EOL means qulaities to be set to '100'
      m_oRteNvmEcm.sPoseCalibration.uiPitchQuality        = 100;
      m_oRteNvmEcm.sPoseCalibration.uiRollQuality         = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTotalAngleQuality   = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTotalTranslQuality  = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTxQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTyQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiTzQuality           = 100;
      m_oRteNvmEcm.sPoseCalibration.uiYawQuality          = 100;

      m_oRteNvmEcm.sEcmRteSensorSocketEol.fX              = m_oRteNvmEcm.sPoseCalibration.fTx;
      m_oRteNvmEcm.sEcmRteSensorSocketEol.fY              = m_oRteNvmEcm.sPoseCalibration.fTy;
      m_oRteNvmEcm.sEcmRteSensorSocketEol.fZ              = m_oRteNvmEcm.sPoseCalibration.fTz; 

      m_oRteNvmEcm.sSensorAnglesEol.f32_Pitch             = m_oRteNvmEcm.sPoseCalibration.fPitch;
      m_oRteNvmEcm.sSensorAnglesEol.f32_Roll              = m_oRteNvmEcm.sPoseCalibration.fRoll;
      m_oRteNvmEcm.sSensorAnglesEol.f32_Yaw               = m_oRteNvmEcm.sPoseCalibration.fYaw;
      m_oRteNvmEcm.sSensorAnglesEol.ui32_Quality          = 100;

      memset(&m_oRteNvmEcm.sCompState, 0, sizeof(m_oRteNvmEcm.sCompState)); 
      m_oRteNvmEcm.sCompState.eCompState = COMP_STATE_SUCCESS;

      m_ppRteNvmEcm                                       = &m_oRteNvmEcm;
    }
    else
    {
      // No Signal Available --> Set Signals to Invalid
      memset(&m_oRteNvmEcm, 0, sizeof(m_oRteNvmEcm));
      m_oRteNvmEcm.uiVersionNumber                                     = NVM_ECM_RTE_INTFVER;
      m_oRteNvmEcm.sSignalHeader.eSigStatus                            = AL_SIG_STATE_INVALID;

      m_ppRteNvmEcm                                       = &m_oRteNvmEcm;
    }

    // Wrap SAC_NVM (sim_conv_sac_nvm only sets default values)
    {
      m_oRteNvmSac.uiVersionNumber                    = NVM_SAC_RTE_INTFVER;

      // SignalHeader_t sSignalHeader
      m_oRteNvmSac.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteNvmSac.sSignalHeader.uiCycleCounter       = 0; // NOT AVAILABLE
      m_oRteNvmSac.sSignalHeader.uiMeasurementCounter = 0; // NOT AVAILABLE
      m_oRteNvmSac.sSignalHeader.uiTimeStamp          = 0; // NOT AVAILABLE
      
      if(m_rp310SacNvm.isDirty())
      {
        // float32 fTemperature
        m_oRteNvmSac.fTemperature = m_rp310SacNvm.val().temperature;

        /////////////////////////////////////////////////////////////
        // SacRteNvmStereoCalibrationState_t sStereoCalibrationState
        /////////////////////////////////////////////////////////////
        memset(&(m_oRteNvmSac.sStereoCalibrationState), 0, sizeof(m_oRteNvmSac.sStereoCalibrationState));
        m_oRteNvmSac.sStereoCalibrationState.fTx = m_rp310SacNvm.val().tx;
        m_oRteNvmSac.sStereoCalibrationState.fTy = m_rp310SacNvm.val().ty;
        m_oRteNvmSac.sStereoCalibrationState.fTz = m_rp310SacNvm.val().tz;
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA00 = m_rp310SacNvm.val().RotMatRL[0];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA10 = m_rp310SacNvm.val().RotMatRL[1];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA20 = m_rp310SacNvm.val().RotMatRL[2];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA01 = m_rp310SacNvm.val().RotMatRL[3];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA11 = m_rp310SacNvm.val().RotMatRL[4];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA21 = m_rp310SacNvm.val().RotMatRL[5];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA02 = m_rp310SacNvm.val().RotMatRL[6];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA12 = m_rp310SacNvm.val().RotMatRL[7];
        m_oRteNvmSac.sStereoCalibrationState.sR_left_right.fA22 = m_rp310SacNvm.val().RotMatRL[8];
      }
      else
      {
        m_oRteNvmSac.fTemperature = 0      ; // NOT AVAILABLE
        // SacRteNvmStereoCalibrationState_t sStereoCalibrationState
        memset(&(m_oRteNvmSac.sStereoCalibrationState), 0, sizeof(m_oRteNvmSac.sStereoCalibrationState));
      }

      if(m_rp310SacStatistics.isDirty())
      {
        //////////////////////////////////
        // SacRteStatistics_t sStatistics
        //////////////////////////////////
        memset(&(m_oRteNvmSac.sStatistics), 0, sizeof(m_oRteNvmSac.sStatistics));
        m_oRteNvmSac.sStatistics.uiVersionNumber = 1;
        m_oRteNvmSac.sStatistics.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;

        for (int i = 0; i < 6; i++)
        {
          m_oRteNvmSac.sStatistics.aNumberUsedFramesHistogramBin[i] = m_rp310SacStatistics.val().NoUsedFramesHistBin[i];
        }
        for (int i = 0; i < 12; i++)
        {
          m_oRteNvmSac.sStatistics.aRectificationErrorHistogramBin[i] = m_rp310SacStatistics.val().RectErrHistBin[i];
        }
        m_oRteNvmSac.sStatistics.BinFill = 0; // NOT AVAILABLE
        switch (m_rp310SacStatistics.val().source)
        {
        case mfc310::stereo::SAC_SRC_Invalid:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_Invalid;
            break;
          case mfc310::stereo::SAC_SRC_NVM:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_NVM;
            break;
          case mfc310::stereo::SAC_SRC_EOL:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_EOL;
            break;
          case mfc310::stereo::SAC_SRC_AutoCalCoarse:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_AutoCalCoarse;
            break;
          case mfc310::stereo::SAC_SRC_AutoCalFine:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_AutoCalFine;
            break;
          case mfc310::stereo::SAC_SRC_EOLUpdate:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_EOLUpdate;
            break;
          case mfc310::stereo::SAC_SRC_SelfEval:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_SelfEval;
            break;
          case mfc310::stereo::SAC_SRC_TempModel:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_TempModel;
            break;
          default:
            m_oRteNvmSac.sStatistics.eSource = SAC_RTE_SRC_Invalid;
            break;
        }
        m_oRteNvmSac.sStatistics.eStatisticsState = (m_rp310SacStatistics.val().state == 1) ? AL_SIG_STATE_OK : ((m_rp310SacStatistics.val().state > 1) ? AL_SIG_STATE_INVALID : AL_SIG_STATE_INIT);
        m_oRteNvmSac.sStatistics.fCurrPitch = m_rp310SacStatistics.val().CurrPitch;
        m_oRteNvmSac.sStatistics.fCurrRecterror = m_rp310SacStatistics.val().CurrRecterror;
        m_oRteNvmSac.sStatistics.fCurrRoll = m_rp310SacStatistics.val().CurrRoll;
        m_oRteNvmSac.sStatistics.fCurrYaw = m_rp310SacStatistics.val().CurrYaw;
        m_oRteNvmSac.sStatistics.fKmetersCurrent = 0; // NOT AVAILABLE
        m_oRteNvmSac.sStatistics.fKmetersLastCoarseCalib = m_rp310SacStatistics.val().KmetersLastCoarseCalib;
        m_oRteNvmSac.sStatistics.aKmetersLastError[0] = 0; // NOT AVAILABLE
        m_oRteNvmSac.sStatistics.fKmetersLastFineCalib = m_rp310SacStatistics.val().KmetersLastFineCalib;
        m_oRteNvmSac.sStatistics.fKmetersLastYawCalib = m_rp310SacStatistics.val().KmetersLastYawCalib;
        m_oRteNvmSac.sStatistics.fKmetersStartOfStatistic = 0; // NOT AVAILABLE
        m_oRteNvmSac.sStatistics.fMaxDistCalib = m_rp310SacStatistics.val().MaxDistCalib;
        m_oRteNvmSac.sStatistics.fMaxPitch = m_rp310SacStatistics.val().MaxPitch;
        m_oRteNvmSac.sStatistics.fMaxRoll = m_rp310SacStatistics.val().MaxRoll;
        m_oRteNvmSac.sStatistics.fMaxYaw = m_rp310SacStatistics.val().MaxYaw;
        m_oRteNvmSac.sStatistics.fMinPitch = m_rp310SacStatistics.val().MinPitch;
        m_oRteNvmSac.sStatistics.fMinRoll = m_rp310SacStatistics.val().MinRoll;
        m_oRteNvmSac.sStatistics.fMinYaw = m_rp310SacStatistics.val().MinYaw;
        m_oRteNvmSac.sStatistics.FrameCnt = 0; // NOT AVAILABLE
        m_oRteNvmSac.sStatistics.RadarCal = 0; // NOT AVAILABLE
        m_oRteNvmSac.sStatistics.uiFlexrayBitfieldPartA = (uint32)(((uint64)m_rp310SacStatistics.val().FlexrayBitfield) & 0xFFFFFFFF);
        m_oRteNvmSac.sStatistics.uiFlexrayBitfieldPartB = (uint32)((((uint64)m_rp310SacStatistics.val().FlexrayBitfield) >> 32) & 0xFFFFFFFF);
        m_oRteNvmSac.sStatistics.aLastError[0] = 0; // NOT AVAILABLE
        m_oRteNvmSac.sStatistics.uiCurrNoUsedFrames = (uint32)m_rp310SacStatistics.val().CurrNoUsedFrames;
        m_oRteNvmSac.sStatistics.uiMaxNoUsedFramesCoarse = (uint32)m_rp310SacStatistics.val().MaxNoUsedFramesCoarse;
        m_oRteNvmSac.sStatistics.uiMaxNoUsedFramesFine = (uint32)m_rp310SacStatistics.val().MaxNoUsedFramesFine;
      }
      else
      {
        // SacRteStatistics_t sStatistics
        memset(&(m_oRteNvmSac.sStatistics), 0, sizeof(m_oRteNvmSac.sStatistics));
        m_oRteNvmSac.sStatistics.uiVersionNumber = 1;
        m_oRteNvmSac.sStatistics.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
      }

      if(m_rp310SacAngleData.isDirty())
      {
        ///////////////////////////////////////
        // SacRteNvmNvAngleData_t sNvAngleData
        ///////////////////////////////////////
        
        memset(&(m_oRteNvmSac.sNvAngleData), 0, sizeof(m_oRteNvmSac.sNvAngleData));
        m_oRteNvmSac.sNvAngleData.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
        for (int i = 0; i < 16; i++)
        {
          m_oRteNvmSac.sNvAngleData.sPitchAngleNvData.aNode[i].siAngle      = m_rp310SacAngleData.val().PitchAngleNvData.Node[i].Angle;
          m_oRteNvmSac.sNvAngleData.sPitchAngleNvData.aNode[i].uiConfidence = m_rp310SacAngleData.val().PitchAngleNvData.Node[i].Conf;
          m_oRteNvmSac.sNvAngleData.sRollAngleNvData.aNode[i].siAngle      = m_rp310SacAngleData.val().RollAngleNvData.Node[i].Angle;
          m_oRteNvmSac.sNvAngleData.sRollAngleNvData.aNode[i].uiConfidence = m_rp310SacAngleData.val().RollAngleNvData.Node[i].Conf;
          m_oRteNvmSac.sNvAngleData.sYawAngleNvData.aNode[i].siAngle      = m_rp310SacAngleData.val().YawAngleNvData.Node[i].Angle;
          m_oRteNvmSac.sNvAngleData.sYawAngleNvData.aNode[i].uiConfidence = m_rp310SacAngleData.val().YawAngleNvData.Node[i].Conf;
        }
        m_oRteNvmSac.sNvAngleData.sPitchAngleNvData.siProductionAngle    = m_rp310SacAngleData.val().PitchAngleNvData.prodAngle;
        m_oRteNvmSac.sNvAngleData.sPitchAngleNvData.uiStatusRead         = m_rp310SacAngleData.val().PitchAngleNvData.statRd;
        m_oRteNvmSac.sNvAngleData.sPitchAngleNvData.uiStatusWrite        = m_rp310SacAngleData.val().PitchAngleNvData.statWr;
        m_oRteNvmSac.sNvAngleData.sPitchAngleNvData.uiStatusWritePending = m_rp310SacAngleData.val().PitchAngleNvData.statWrpd;
        m_oRteNvmSac.sNvAngleData.sRollAngleNvData.siProductionAngle    = m_rp310SacAngleData.val().RollAngleNvData.prodAngle;
        m_oRteNvmSac.sNvAngleData.sRollAngleNvData.uiStatusRead         = m_rp310SacAngleData.val().RollAngleNvData.statRd;
        m_oRteNvmSac.sNvAngleData.sRollAngleNvData.uiStatusWrite        = m_rp310SacAngleData.val().RollAngleNvData.statWr;
        m_oRteNvmSac.sNvAngleData.sRollAngleNvData.uiStatusWritePending = m_rp310SacAngleData.val().RollAngleNvData.statWrpd;
        m_oRteNvmSac.sNvAngleData.sYawAngleNvData.siProductionAngle    = m_rp310SacAngleData.val().YawAngleNvData.prodAngle;
        m_oRteNvmSac.sNvAngleData.sYawAngleNvData.uiStatusRead         = m_rp310SacAngleData.val().YawAngleNvData.statRd;
        m_oRteNvmSac.sNvAngleData.sYawAngleNvData.uiStatusWrite        = m_rp310SacAngleData.val().YawAngleNvData.statWr;
        m_oRteNvmSac.sNvAngleData.sYawAngleNvData.uiStatusWritePending = m_rp310SacAngleData.val().YawAngleNvData.statWrpd;
      }
      else
      {
        // SacRteNvmNvAngleData_t sNvAngleData
        memset(&(m_oRteNvmSac.sNvAngleData), 0, sizeof(m_oRteNvmSac.sNvAngleData));
        m_oRteNvmSac.sNvAngleData.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
      }

      // SacRteNvmExtrinsicCalibrationLastResult_t sExtrinsicCalibrationLastResult
      memset(&(m_oRteNvmSac.sExtrinsicCalibrationLastResult), 0, sizeof(m_oRteNvmSac.sExtrinsicCalibrationLastResult));

      //DstNvm.sStatistics.VersBugfx = SrcSAC.bugfix;
      //DstNvm.sStatistics.VersMajor = SrcSAC.major;
      //DstNvm.sStatistics.VersMinor = SrcSAC.minor;

      m_ppRteNvmSac = &m_oRteNvmSac;
    }

    //Wrap FLSP Temperature Compensation List
    if(m_rp310SacAngleData.isDirty())
    {
      m_oRteFlspTemperatureCompensationList.uiVersionNumber                    = FLSP_TEMP_COMP_INTFVER;

      // SignalHeader_t sSignalHeader
      m_oRteFlspTemperatureCompensationList.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteFlspTemperatureCompensationList.sSignalHeader.uiCycleCounter       = 0; // NOT AVAILABLE
      m_oRteFlspTemperatureCompensationList.sSignalHeader.uiMeasurementCounter = 0; // NOT AVAILABLE
      m_oRteFlspTemperatureCompensationList.sSignalHeader.uiTimeStamp          = 0; // NOT AVAILABLE

      //AlgoApplicationNumber_t uiCurveVersion
      m_oRteFlspTemperatureCompensationList.uiCurveVersion = 1; // NOT AVAILABLE

      //float32 fCurveCalibTemp
      m_oRteFlspTemperatureCompensationList.fCurveCalibTemp = 42.0F; // NOT AVAILABLE

      for (int i = 0; i < 16; i++)
      {
        //FLSPTempCompAngle_array_t FLSPTempCompAngle
        m_oRteFlspTemperatureCompensationList.FLSPTempCompAngle[i].siPitch = m_rp310SacAngleData.val().PitchAngleNvData.Node[i].Angle;
        m_oRteFlspTemperatureCompensationList.FLSPTempCompAngle[i].siRoll  = m_rp310SacAngleData.val().RollAngleNvData.Node[i].Angle;
        m_oRteFlspTemperatureCompensationList.FLSPTempCompAngle[i].siYaw   = m_rp310SacAngleData.val().YawAngleNvData.Node[i].Angle;

        //FLSPTempCompConfidence_array_t FLSPTempCompConfidence
        m_oRteFlspTemperatureCompensationList.FLSPTempCompConfidence[i].uiConfidencePitch = m_rp310SacAngleData.val().PitchAngleNvData.Node[i].Conf;
        m_oRteFlspTemperatureCompensationList.FLSPTempCompConfidence[i].uiConfidenceRoll  = m_rp310SacAngleData.val().RollAngleNvData.Node[i].Conf;
        m_oRteFlspTemperatureCompensationList.FLSPTempCompConfidence[i].uiConfidenceYaw   = m_rp310SacAngleData.val().YawAngleNvData.Node[i].Conf;
        m_oRteFlspTemperatureCompensationList.FLSPTempCompConfidence[i].uiPaddingByte     = 0;
      }
      m_ppRteFlspTemperatureCompensationList = &m_oRteFlspTemperatureCompensationList; 
    }
    else
    {
      memset(&m_oRteFlspTemperatureCompensationList, 0, sizeof(m_oRteFlspTemperatureCompensationList));
      m_oRteFlspTemperatureCompensationList.uiVersionNumber                    = FLSP_TEMP_COMP_INTFVER;
      m_oRteFlspTemperatureCompensationList.sSignalHeader.eSigStatus           = AL_SIG_STATE_INVALID;
      m_ppRteFlspTemperatureCompensationList                                   = &m_oRteFlspTemperatureCompensationList;
    }

    //Wrap FLSP Temperature Compensation List
    if(m_rp310SacExtRightToLeft.isDirty() || (
      m_rp310SacExtRightToLeft_Baseline.isDirty() && 
      m_rp310SacExtRightToLeft_tx.isDirty() &&
      m_rp310SacExtRightToLeft_ty.isDirty() &&
      m_rp310SacExtRightToLeft_tz.isDirty() &&
      m_rp310SacExtRightToLeft_RotMat.isDirty()
      )
    )
    {
      m_oRteFlspStereoCalTransRot.uiVersionNumber                    = FLSP_STEREO_CAL_TRAN_ROT_INTFVER;

      // SignalHeader_t sSignalHeader
      m_oRteFlspStereoCalTransRot.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
      m_oRteFlspStereoCalTransRot.sSignalHeader.uiCycleCounter       = 0; // NOT AVAILABLE
      m_oRteFlspStereoCalTransRot.sSignalHeader.uiMeasurementCounter = 0; // NOT AVAILABLE
      m_oRteFlspStereoCalTransRot.sSignalHeader.uiTimeStamp          = 0; // NOT AVAILABLE

      if(m_rp310SacExtRightToLeft.isDirty())
      {
        //	float32 f32_Baseline
        m_oRteFlspStereoCalTransRot.f32_Baseline = m_rp310SacExtRightToLeft.val().Baseline;

        //	float32 f32_TranslationX
        //	float32 f32_TranslationY
        //	float32 f32_TranslationZ
        m_oRteFlspStereoCalTransRot.f32_TranslationX = m_rp310SacExtRightToLeft.val().tx;
        m_oRteFlspStereoCalTransRot.f32_TranslationY = m_rp310SacExtRightToLeft.val().ty;
        m_oRteFlspStereoCalTransRot.f32_TranslationZ = m_rp310SacExtRightToLeft.val().tz;

        //	float32 f32_RotMatrixR11
        //	float32 f32_RotMatrixR21
        //	float32 f32_RotMatrixR31
        //	float32 f32_RotMatrixR12
        //	float32 f32_RotMatrixR22
        //	float32 f32_RotMatrixR32
        //	float32 f32_RotMatrixR13
        //	float32 f32_RotMatrixR23
        //	float32 f32_RotMatrixR33
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR11 = m_rp310SacExtRightToLeft.val().RotMat[0];// row 1, col 1
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR21 = m_rp310SacExtRightToLeft.val().RotMat[1];// row 2, col 1
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR31 = m_rp310SacExtRightToLeft.val().RotMat[2];// row 3, col 1
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR12 = m_rp310SacExtRightToLeft.val().RotMat[3];// row 1, col 2
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR22 = m_rp310SacExtRightToLeft.val().RotMat[4];// row 2, col 2
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR32 = m_rp310SacExtRightToLeft.val().RotMat[5];// row 3, col 2
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR13 = m_rp310SacExtRightToLeft.val().RotMat[6];// row 1, col 3
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR23 = m_rp310SacExtRightToLeft.val().RotMat[7];// row 2, col 3
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR33 = m_rp310SacExtRightToLeft.val().RotMat[8];// row 3, col 3
      }
      else
      {
        //	float32 f32_Baseline
        m_oRteFlspStereoCalTransRot.f32_Baseline = m_rp310SacExtRightToLeft_Baseline.val();

        //	float32 f32_TranslationX
        //	float32 f32_TranslationY
        //	float32 f32_TranslationZ
        m_oRteFlspStereoCalTransRot.f32_TranslationX = m_rp310SacExtRightToLeft_tx.val();
        m_oRteFlspStereoCalTransRot.f32_TranslationY = m_rp310SacExtRightToLeft_ty.val();
        m_oRteFlspStereoCalTransRot.f32_TranslationZ = m_rp310SacExtRightToLeft_tz.val();

        //	float32 f32_RotMatrixR11
        //	float32 f32_RotMatrixR21
        //	float32 f32_RotMatrixR31
        //	float32 f32_RotMatrixR12
        //	float32 f32_RotMatrixR22
        //	float32 f32_RotMatrixR32
        //	float32 f32_RotMatrixR13
        //	float32 f32_RotMatrixR23
        //	float32 f32_RotMatrixR33
        float32* rot_mat = reinterpret_cast<float32*>(m_rp310SacExtRightToLeft_RotMat.val());
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR11 = rot_mat[0];// row 1, col 1
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR21 = rot_mat[1];// row 2, col 1
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR31 = rot_mat[2];// row 3, col 1
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR12 = rot_mat[3];// row 1, col 2
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR22 = rot_mat[4];// row 2, col 2
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR32 = rot_mat[5];// row 3, col 2
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR13 = rot_mat[6];// row 1, col 3
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR23 = rot_mat[7];// row 2, col 3
        m_oRteFlspStereoCalTransRot.f32_RotMatrixR33 = rot_mat[8];// row 3, col 3
      }

      //	float32 f32_ROIVShiftLeft
      m_oRteFlspStereoCalTransRot.f32_ROIVShiftLeft = 0; // ??? TODO: see PPar Measfreeze

      m_ppRteFlspStereoCalTransRot                                   = &m_oRteFlspStereoCalTransRot;
    }
    else
    {
      memset(&m_oRteFlspStereoCalTransRot, 0, sizeof(m_oRteFlspStereoCalTransRot));
      m_oRteFlspStereoCalTransRot.uiVersionNumber                    = FLSP_STEREO_CAL_TRAN_ROT_INTFVER;
      m_oRteFlspStereoCalTransRot.sSignalHeader.eSigStatus           = AL_SIG_STATE_INVALID;
      m_ppRteFlspStereoCalTransRot                                   = &m_oRteFlspStereoCalTransRot;
    }

    if(m_rp310LdParameterInOut.isDirty())
    { 
      mfc310::ld::S_LDParameterInOut ldSrc            = m_rp310LdParameterInOut.val();
  
      m_oRteNvmLd.uVersionNumber = LD_ONLINE_CALI_DATA_INTFVER;
      m_oRteNvmLd.sSignalHeader.uiTimeStamp           = 0U; // NOT AVAILABLE
      m_oRteNvmLd.sSignalHeader.uiMeasurementCounter  = 0U; // NOT AVAILABLE
      m_oRteNvmLd.sSignalHeader.uiCycleCounter        = 0U; // NOT AVAILABLE
      m_oRteNvmLd.sSignalHeader.eSigStatus            = AL_SIG_STATE_OK;

      m_oRteNvmLd.fCamYawAngleAC                      = ldSrc.m_f32_CamYawAngleAC;
      m_oRteNvmLd.fPitchAngleAC                       = ldSrc.m_f32_PitchAngleAC;
      m_oRteNvmLd.fRollAngleAC                        = ldSrc.m_f32_RollAngleAC;
      m_oRteNvmLd.iCamYawACStage                      = ldSrc.m_i32_CamYawACStage;
      m_oRteNvmLd.iPitchACStage                       = ldSrc.m_i32_PitchACStage;
      m_oRteNvmLd.iRollACStage                        = ldSrc.m_i32_RollACStage;

      m_ppRteNvmLd                                    = &m_oRteNvmLd;
    }
    else
    {
      // No Signal Available --> Set Signals to Invalid
      memset(&m_oRteNvmLd, 0, sizeof(m_oRteNvmLd));
      m_oRteNvmLd.uVersionNumber                      = LD_ONLINE_CALI_DATA_INTFVER;
      m_oRteNvmLd.sSignalHeader.eSigStatus            = AL_SIG_STATE_INVALID;

      m_ppRteNvmLd                                    = &m_oRteNvmLd;

    }
    
    // FLSP Stereo Calibration Intrinsics Right
    if(m_rp310SacIntrinsicRight.isDirty())
    {
      mfc310::stereo::SACMeasIntrinsicCalibrationData_t stereoCaliIntRight = m_rp310SacIntrinsicRight.val();
      i16_t NumRadDistCoeff = (i16_t)stereoCaliIntRight.NumRadDistCoeff;
      
      m_oRteFlspStereoCallIntrinsicsRight.uiVersionNumber                     = FLSP_STEREO_CAL_INTR_INTFVER;
      m_oRteFlspStereoCallIntrinsicsRight.sSignalHeader.eSigStatus            = AL_SIG_STATE_OK;
      m_oRteFlspStereoCallIntrinsicsRight.sSignalHeader.uiTimeStamp           = 0U; // NOT AVAILABLE
      m_oRteFlspStereoCallIntrinsicsRight.sSignalHeader.uiMeasurementCounter  = 0U; // NOT AVAILABLE
      m_oRteFlspStereoCallIntrinsicsRight.sSignalHeader.uiCycleCounter        = 0U; // NOT AVAILABLE

      m_oRteFlspStereoCallIntrinsicsRight.f32_InFocusX                        = stereoCaliIntRight.FocalX;
      m_oRteFlspStereoCallIntrinsicsRight.f32_InFocusY                        = stereoCaliIntRight.FocalY;
      m_oRteFlspStereoCallIntrinsicsRight.f32_InPrincipalPointXCoordinate     = stereoCaliIntRight.CenterX;
      m_oRteFlspStereoCallIntrinsicsRight.f32_InPrincipalPointYCoordinate     = stereoCaliIntRight.CenterY; 
      m_oRteFlspStereoCallIntrinsicsRight.ui32_ActualNumberOfCoeffients       = stereoCaliIntRight.NumRadDistCoeff;

      // Only the indexes lower than NumRadDistCoeff are valid. Force every other one to 0.      
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff1          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[0]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff2          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[1]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff3          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[2]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff4          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[3]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff5          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[4]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff6          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[5]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff7          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[6]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff8          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[7]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff9          = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[8]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsRight.f32_RadialDistortionCoeff10         = NumRadDistCoeff-- > 0 ? stereoCaliIntRight.RadialDistortion[9]: 0.0f;

      m_ppRteFlspStereoCallIntrinsicsRight                          = &m_oRteFlspStereoCallIntrinsicsRight;
    }
    else
    {
      memset(&m_oRteFlspStereoCallIntrinsicsRight, 0, sizeof(m_oRteFlspStereoCallIntrinsicsRight));
      m_oRteFlspStereoCallIntrinsicsRight.uiVersionNumber           = FLSP_STEREO_CAL_INTR_INTFVER;

      if (m_rp310FocalX.isDirty() && m_rp310FocalY.isDirty())
      {
        m_oRteFlspStereoCallIntrinsicsRight.f32_InFocusX = m_rp310FocalX.val();
        m_oRteFlspStereoCallIntrinsicsRight.f32_InFocusY = m_rp310FocalY.val();
        m_oRteFlspStereoCallIntrinsicsRight.f32_InPrincipalPointXCoordinate = m_rp310CenterX.val();
        m_oRteFlspStereoCallIntrinsicsRight.f32_InPrincipalPointYCoordinate = m_rp310CenterY.val();
        m_oRteFlspStereoCallIntrinsicsRight.sSignalHeader.eSigStatus  = AL_SIG_STATE_OK;
      }
      else
      {
        // No Signal Available --> Set Signals to Invalid
        m_oRteFlspStereoCallIntrinsicsRight.sSignalHeader.eSigStatus  = AL_SIG_STATE_INVALID;
      }
      m_ppRteFlspStereoCallIntrinsicsRight                          = &m_oRteFlspStereoCallIntrinsicsRight;
    }

    // FLSP Stereo Calibration Intrinsics Left
    if(m_rp310SacIntrinsicLeft.isDirty())
    {
      mfc310::stereo::SACMeasIntrinsicCalibrationData_t stereoCaliIntLeft   = m_rp310SacIntrinsicLeft.val();
      i16_t NumRadDistCoeff = (i16_t)stereoCaliIntLeft.NumRadDistCoeff;
      
      m_oRteFlspStereoCallIntrinsicsLeft.uiVersionNumber                     = FLSP_STEREO_CAL_INTR_INTFVER;
      m_oRteFlspStereoCallIntrinsicsLeft.sSignalHeader.eSigStatus            = AL_SIG_STATE_OK;
      m_oRteFlspStereoCallIntrinsicsLeft.sSignalHeader.uiTimeStamp           = 0U; // NOT AVAILABLE
      m_oRteFlspStereoCallIntrinsicsLeft.sSignalHeader.uiMeasurementCounter  = 0U; // NOT AVAILABLE
      m_oRteFlspStereoCallIntrinsicsLeft.sSignalHeader.uiCycleCounter        = 0U; // NOT AVAILABLE

      m_oRteFlspStereoCallIntrinsicsLeft.f32_InFocusX                        = stereoCaliIntLeft.FocalX;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_InFocusY                        = stereoCaliIntLeft.FocalY;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_InPrincipalPointXCoordinate     = stereoCaliIntLeft.CenterX;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_InPrincipalPointYCoordinate     = stereoCaliIntLeft.CenterY; 
      m_oRteFlspStereoCallIntrinsicsLeft.ui32_ActualNumberOfCoeffients       = stereoCaliIntLeft.NumRadDistCoeff;
      
      // Only the indexes lower than NumRadDistCoeff are valid. Force every other one to 0.
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff1          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[0]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff2          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[1]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff3          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[2]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff4          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[3]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff5          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[4]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff6          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[5]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff7          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[6]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff8          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[7]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff9          = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[8]: 0.0f;
      m_oRteFlspStereoCallIntrinsicsLeft.f32_RadialDistortionCoeff10         = NumRadDistCoeff-- > 0 ? stereoCaliIntLeft.RadialDistortion[9]: 0.0f;

      m_ppRteFlspStereoCallIntrinsicsLeft                                   = &m_oRteFlspStereoCallIntrinsicsLeft;
    }
    else
    {
      // No Signal Available --> Set Signals to Invalid
      memset(&m_oRteFlspStereoCallIntrinsicsLeft, 0, sizeof(m_oRteFlspStereoCallIntrinsicsLeft));
      m_oRteFlspStereoCallIntrinsicsLeft.uiVersionNumber            = FLSP_STEREO_CAL_INTR_INTFVER;
      m_oRteFlspStereoCallIntrinsicsLeft.sSignalHeader.eSigStatus   = AL_SIG_STATE_INVALID;

      m_ppRteFlspStereoCallIntrinsicsLeft                           = &m_oRteFlspStereoCallIntrinsicsLeft;
    }

    // wrap FLSPProductionIntrinsic_t
    if( m_rp310SrInputConfig.isDirty() )
    {
      m_oRteFlspProductionIntrinsicLeft.uiVersionNumber = FLSP_PROD_INTR_INTFVER;
      m_oRteFlspProductionIntrinsicLeft.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
      m_oRteFlspProductionIntrinsicLeft.sSignalHeader.uiCycleCounter = 0U;
      m_oRteFlspProductionIntrinsicLeft.sSignalHeader.uiMeasurementCounter = 0U;
      m_oRteFlspProductionIntrinsicLeft.sSignalHeader.uiTimeStamp = 0U;

      // currently wrapping implemented for SR only
      m_oRteFlspProductionIntrinsicLeft.f32_BlueGreenRatio = m_rp310SrInputConfig.val().imagerConfig.cfaTransmittance.blue;
      m_oRteFlspProductionIntrinsicLeft.f32_RedGreenRatio  = m_rp310SrInputConfig.val().imagerConfig.cfaTransmittance.red;
      m_oRteFlspProductionIntrinsicLeft.f32_GreenRefRatio  = m_rp310SrInputConfig.val().imagerConfig.cfaTransmittance.green;
      m_ppRteFlspProductionIntrinsicLeft = &m_oRteFlspProductionIntrinsicLeft;
    }
    else
    {
      memset(&m_oRteFlspProductionIntrinsicLeft, 0, sizeof(m_oRteFlspProductionIntrinsicLeft));
      m_oRteFlspProductionIntrinsicLeft.uiVersionNumber = FLSP_PROD_INTR_INTFVER;
      m_oRteFlspProductionIntrinsicLeft.sSignalHeader.eSigStatus = AL_SIG_STATE_INVALID;
      m_ppRteFlspProductionIntrinsicLeft = &m_oRteFlspProductionIntrinsicLeft;
    }

    // image control odd...
    if ( m_rp310IcicOdd.isDirty() ) 
    {
      if ( m_rp310IcicOdd.size() == sizeof(mfc310::ic::ICEXP_S_Output) )
      {
        // Odd right
        wrapICICData( m_rp310IcicOdd.val(), m_rp310SlopeRatioR1.val(), m_rp310Blacklevel.val(), m_oRteIcIcOddRight );
        m_oRteIcIcOddRight.sSignalHeader.uiMeasurementCounter = (AlgoCycleCounter_t)m_TimstampFixer.m_rpImageFramecounterRight.val();
        m_oRteIcIcOddRight.sSignalHeader.uiTimeStamp = (AlgoDataTimeStamp_t)m_TimstampFixer.m_rpImageTimestampRight.val();
        m_ppRteIcIcOddRight = &m_oRteIcIcOddRight;
        // Odd left
        wrapICICData( m_rp310IcicOdd.val(), m_rp310SlopeRatioR1.val(), m_rp310Blacklevel.val(), m_oRteIcIcOddLeft );
        m_oRteIcIcOddLeft.sSignalHeader.uiMeasurementCounter = (AlgoCycleCounter_t)m_TimstampFixer.m_rpImageFramecounterLeft.val();
        m_oRteIcIcOddLeft.sSignalHeader.uiTimeStamp = (AlgoDataTimeStamp_t)m_TimstampFixer.m_rpImageTimestampLeft.val();
        m_ppRteIcIcOddLeft = &m_oRteIcIcOddLeft;
      }
      else
      {
        std::stringstream err;
        err << "Receive port '" << m_rp310IcicOdd.name() << "' is not a ICEXP_S_Output. Can't adapt.";
        ReportError(err_sev_error, 0, err.str().c_str());
      }
    }
    if ( m_rp310Icop2.isDirty() && m_rp310Icesd.isDirty() )
    {
      if ( m_rp310Icop2.size() == sizeof(mfc310::ic::IC_S_ResultsPart2) && m_rp310Icesd.size() == sizeof(mfc310::ic::IC_S_EmbeddedStatData) )
      {
        wrapICSRData( m_rp310Icop2.val(), m_rp310Icesd.val(), m_oRteIcsr );
        m_ppRteIcsr = &m_oRteIcsr;
      }
      else
      {
        std::stringstream err;
        err << "Receive port '" << m_rp310Icop2.name() << "' or '" << m_rp310Icesd.name() << "' has wrong size. Can't adapt.";
        ReportError(err_sev_error, 0, err.str().c_str());
      }
    }

    // image control even...
    if ( m_rp310IcicEven.isDirty() )
    {
      if ( m_rp310IcicEven.size() == sizeof(mfc310::ic::ICEXP_S_Output) && m_rp310SrInputConfig.isDirty() )
      {
        m_oRteIcIcEvenRight = m_oRteIcIcOddRight;
        m_oRteIcIcEvenRight.s_ImagerCroi.ui16_Height = (uint16)m_rp310SrInputConfig.val().imagerConfig.imageHeight;
        m_oRteIcIcEvenRight.s_ImagerCroi.ui16_Width  = (uint16)m_rp310SrInputConfig.val().imagerConfig.imageWidth;
        m_oRteIcIcEvenRight.s_ImagerCroi.ui16_X      = (uint16)(m_oRteIcIcEvenRight.s_ImagerSize.ui16_Width - m_rp310SrInputConfig.val().imagerConfig.imageWidth) / 2;
        m_oRteIcIcEvenRight.s_ImagerCroi.ui16_Y      = 222;
        wrapICICData( m_rp310IcicEven.val(), m_rp310SlopeRatioR1.val(), m_rp310Blacklevel.val(), m_oRteIcIcEvenRight );
        m_ppRteIcIcEvenRight = &m_oRteIcIcEvenRight;
      }
      else if (!m_rp310SrInputConfig.isDirty())
      {
        std::stringstream err;
        err << "Receive port '" << m_rp310SrInputConfig.name() << "' hasn't been received. Therefore the IcImageCharacteristicsEven won't be adapted.";
        ReportError(err_sev_error, 0, err.str().c_str());
      }
      else
      {
        std::stringstream err;
        err << "Receive port '" << m_rp310IcicOdd.name() << "' is not a ICEXP_S_Output. Can't adapt.";
        ReportError(err_sev_error, 0, err.str().c_str());
      }
    }
    if ( m_rp310Icop2.isDirty() && m_rp310Icesd.isDirty() )
    {
      if ( m_rp310Icop2.size() == sizeof(mfc310::ic::IC_S_ResultsPart2) && m_rp310Icesd.size() == sizeof(mfc310::ic::IC_S_EmbeddedStatData) )
      {
        m_oRteIcImageStatisticEven = m_oRteIcsr;
        wrapICSRData( m_rp310Icop2.val(), m_rp310Icesd.val(), m_oRteIcImageStatisticEven );
        m_ppRteIcImageStatisticEven = &m_oRteIcImageStatisticEven;
      }
      else
      {
        std::stringstream err;
        err << "Receive port '" << m_rp310Icop2.name() << "' or '" << m_rp310Icesd.name() << "' has wrong size. Can't adapt.";
        ReportError(err_sev_error, 0, err.str().c_str());
      }
    }
  }
}

void CSimMfcWrapper::WrapVehSig(VehSig_t& vehSig,
                                float32   fVehSigVehVelocityExt,
                                uint8     eVehSigSpeedUnit,
                                float32   fVehSigSpeedoSpeed,
                                uint8     eVehSigTurnSignal,
                                float32   fVehSigStWheelAngle,
                                float32   fVehSigBrakeActLevel,
                                uint8     eVehSigChassisControlEvent
                                )
{
  
  // Give an actual timestamp to the VehSig
  // LDW needs the timestamp to refresh in order to use the SpeedoSpeed contained
  // Note: In case m_rp310VehDyn is not connected the copied timestamp will be 0

  vehSig.sSigHeader.uiTimeStamp = (AlgoDataTimeStamp_t)m_TimstampFixer.m_rpImageTimestampLeft.val(); 
  // Actual wrapping from FCT measfreezes
  vehSig.VehSigMain.VehVelocityExt  = fVehSigVehVelocityExt;
  vehSig.VehSigMain.StWheelAngle    = -CML_Deg2Rad(fVehSigStWheelAngle);
  vehSig.VehSigMain.BrakeActLevel   = (uint16)fVehSigBrakeActLevel;
  vehSig.VehSigAdd.SpeedoSpeed      = fVehSigSpeedoSpeed;

  vehSig.VehSigMain.State[VDY_SIN_POS_SWA]                = VDY_IO_STATE_VALID;

  // RO: 1171495 - [MFC431LO19] 3xx recording not simulated
  // VDY_SIN_POS_VEHVEL_EXT=12  
  if((vehSig.VehSigMain.State[VDY_SIN_POS_VEHVEL_EXT]==VDY_IO_STATE_INVALID)
	  ||(vehSig.VehSigMain.State[VDY_SIN_POS_VEHVEL_EXT]==VDY_IO_STATE_NOTAVAIL))
  {
    vehSig.VehSigMain.VehVelocityExt = (vehSig.VehSigMain.WhlVelFrLeft
											+ vehSig.VehSigMain.WhlVelFrRight
											+ vehSig.VehSigMain.WhlVelReLeft
											+ vehSig.VehSigMain.WhlVelReRight)/4;
    vehSig.VehSigMain.State[VDY_SIN_POS_VEHVEL_EXT] = VDY_IO_STATE_VALID;
  }

  vehSig.VehSigAdd.State[VEH_SIG_ADD_TURN_SIGNAL]         = VDY_IO_STATE_VALID;
  vehSig.VehSigAdd.TurnSignal                             = VEH_SIG_ADD_TURN_SIG_NEUTRAL;
  vehSig.VehSigAdd.State[VEH_SIG_ADD_GAS_PEDAL_POS]       = VDY_IO_STATE_VALID;
  vehSig.VehSigAdd.GasPedalPos                            = 0;
  vehSig.VehSigAdd.State[VEH_SIG_ADD_BRAKE_PEDAL_PRESSED] = VDY_IO_STATE_VALID;
  vehSig.VehSigAdd.BrakePedalPressed                      = 0;

  switch (eVehSigSpeedUnit)
  {
  case 0:
    vehSig.VehSigAdd.SpeedUnit = 1u;
    break;
  case 1:
    vehSig.VehSigAdd.SpeedUnit = 2u;
    break;
  default:
    vehSig.VehSigAdd.SpeedUnit = 0u;
    break;
  }

  switch (eVehSigTurnSignal)
  {
  case 0:
    vehSig.VehSigAdd.TurnSignal = 1u;
    break;
  case 1:
    vehSig.VehSigAdd.TurnSignal = 2u;
    break;
  case 2:
    vehSig.VehSigAdd.TurnSignal = 3u;
    break;
  case 3:
    vehSig.VehSigAdd.TurnSignal = 0u;
    break;
  }

  if (eVehSigChassisControlEvent == 1)
  {
    vehSig.Brake.ABSCtrl = 1u;
    vehSig.Brake.TCSCtrl = 1u;
  }
  else
  {
    vehSig.Brake.ABSCtrl              = 0u;
    vehSig.Brake.TCSCtrl              = 0u;
  }

  
  // VehPar

  if(m_ppRteVehPar)
  {
    // Overwriting of values not given in old recordings needed by LDW/LDP (issue 335963)
    VehPar_t *vehPar = reinterpret_cast<VehPar_t*>(m_ppRteVehPar);
    if (vehPar != NULL){
      vehPar->VehParMain.State[VDY_PAR_POS_SWARAT]  = VDY_IO_STATE_VALID;
      vehPar->VehParMain.State[VDY_PAR_POS_CSFR]    = VDY_IO_STATE_VALID;
      vehPar->VehParMain.State[VDY_PAR_POS_CSRE]    = VDY_IO_STATE_VALID;
      vehPar->VehParMain.FrCrnrStiff                = 91400;
      vehPar->VehParMain.ReCrnrStiff                = 91400;
    }
  }
}

void CSimMfcWrapper::WrapFCT()
{
  m_oRteDIMInputGeneric.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  m_oRteFCTAldwInputGen.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;

  m_ppRteDIMInputGeneric = &m_oRteDIMInputGeneric;
  m_ppRteFCTAldwInputGen = &m_oRteDIMInputGeneric;
}

void CSimMfcWrapper::wrapCroiCalibration( const mfc310::stereo::SACImageData_t& CroiImageData310,
                                      const mfc310::stereo::SACMountingCalibrationData_t& CroiExt310,
                                      const mfc310::stereo::SACMeasIntrinsicCalibrationData_t& CroiInt310,
                                      MonoCalibration_t& Croi400 )
{
  // version number
  Croi400.uiVersionNumber   = MONO_CALIBRATION_INTFVER;

  // signal header info
  SignalHeader_t& MonoHeader = Croi400.sSignalHeader;
  MonoHeader.eSigStatus           = AL_SIG_STATE_OK;
  MonoHeader.uiCycleCounter       = 0U;//static_cast<AlgoCycleCounter_t> (SAC310.parameterIdRectPars);
  MonoHeader.uiMeasurementCounter = 0U;//static_cast<AlgoCycleCounter_t> (SAC310.dynamicInputData.RectImgRightCurrent.TFStamp.FrameCount);
  MonoHeader.uiTimeStamp          = 0U;//static_cast<AlgoDataTimeStamp_t>(SAC310.dynamicInputData.RectImgRightCurrent.TFStamp.Timestamp);

  Croi400.uiParameterId    = 0U;
  Croi400.eSide            = MC_CAMERA_RIGHT;
  Croi400.eCameraType      = MC_CAMERA_TYPE_CROI;

  // SacIntrinsicCalibrationData (rectified camera)
  MonoCalibrationIntrinsic_t& IntCal400 = Croi400.sIntrinsic;
  IntCal400.fFocalX  = CroiInt310.FocalX;
  IntCal400.fFocalY  = CroiInt310.FocalY;
  IntCal400.fCenterX = CroiInt310.CenterX - ( CroiImageData310.ROIStartX - CroiImageData310.ROIStartRelCroiX );
  IntCal400.fCenterY = CroiInt310.CenterY - ( CroiImageData310.ROIStartY - CroiImageData310.ROIStartRelCroiY );

  ConstDistCoeffArray_t DistCoeffArray300( CroiInt310.RadialDistortion );
  DistCoeffArray_t DistCoeffArray400( IntCal400.fDistortionCoefficients );
  DistCoeffArray400 = DistCoeffArray300;

  PoseParameters_t& ExtCal400 = Croi400.sPoseCalibration;

  ExtCal400.fTx         = CroiExt310.PositionX;
  ExtCal400.fTy         = CroiExt310.PositionY;
  ExtCal400.fTz         = CroiExt310.PositionZ;

  ExtCal400.fPitch      = CroiExt310.Pitch + CroiExt310.DeltaPitch;
  ExtCal400.fYaw        = CroiExt310.Yaw   + CroiExt310.DeltaYaw;
  ExtCal400.fRoll       = CroiExt310.Roll  + CroiExt310.DeltaRoll;

  ExtCal400.fTxSigma    = 0.0F;
  ExtCal400.fTySigma    = 0.0F;
  ExtCal400.fTzSigma    = 0.0F;

  ExtCal400.fPitchSigma = 0.0F;
  ExtCal400.fYawSigma   = 0.0F;
  ExtCal400.fRollSigma  = 0.0F;
  
  cct::CMonoCamera camera;
  camera.setParams(ExtCal400.fRoll, ExtCal400.fPitch, ExtCal400.fYaw,
                   ExtCal400.fTx, ExtCal400.fTy, ExtCal400.fTz,
                   IntCal400.fFocalX, IntCal400.fFocalY, IntCal400.fCenterX, IntCal400.fCenterY);
  ExtCal400.sTransform = camera.getExtrinsicTransformationMatrix();

  Croi400.sPoseDynamic = Croi400.sPoseCalibration;
}

void CSimMfcWrapper::wrapCroiCalibrationEol( const mfc310::stereo::SACImageData_t&                    CroiImageData310,
                                         const mfc310::stereo::SACMountingCalibrationData_t&      CroiExt310,
                                         const mfc310::stereo::SACMeasIntrinsicCalibrationData_t& CroiInt310,
                                         MonoCalibrationEol_t& CroiEol400)
{
  // version number
  CroiEol400.uiVersionNumber   = MONO_CALIBRATION_EOL_INTFVER;

  // signal header info
  SignalHeader_t& MonoHeader = CroiEol400.sSignalHeader;
  MonoHeader.eSigStatus           = AL_SIG_STATE_OK;
  MonoHeader.uiCycleCounter       = 0U;//static_cast<AlgoCycleCounter_t> (SAC310.parameterIdRectPars);
  MonoHeader.uiMeasurementCounter = 0U;//static_cast<AlgoCycleCounter_t> (SAC310.dynamicInputData.RectImgRightCurrent.TFStamp.FrameCount);
  MonoHeader.uiTimeStamp          = 0U;//static_cast<AlgoDataTimeStamp_t>(SAC310.dynamicInputData.RectImgRightCurrent.TFStamp.Timestamp);

  CroiEol400.uiParameterId    = 0U;

  // SacIntrinsicCalibrationData (rectified camera)
  MonoCalibrationIntrinsic_t& IntCalEol400 = CroiEol400.IntrinsicPhysical;
  IntCalEol400.fFocalX  = CroiInt310.FocalX;
  IntCalEol400.fFocalY  = CroiInt310.FocalY;
  IntCalEol400.fCenterX = CroiInt310.CenterX - ( CroiImageData310.ROIStartX - CroiImageData310.ROIStartRelCroiX );
  IntCalEol400.fCenterY = CroiInt310.CenterY - ( CroiImageData310.ROIStartY - CroiImageData310.ROIStartRelCroiY );

  ConstDistCoeffArray_t DistCoeffArray300( CroiInt310.RadialDistortion );
  DistCoeffArray_t DistCoeffArray400( IntCalEol400.fDistortionCoefficients );
  DistCoeffArray400 = DistCoeffArray300;

  PoseParameters_t& ExtCal400 = CroiEol400.sPoseEcm;

  ExtCal400.fTx         = CroiExt310.PositionX;
  ExtCal400.fTy         = CroiExt310.PositionY;
  ExtCal400.fTz         = CroiExt310.PositionZ;

  ExtCal400.fPitch      = CroiExt310.Pitch;
  ExtCal400.fYaw        = CroiExt310.Yaw;
  ExtCal400.fRoll       = CroiExt310.Roll;

  ExtCal400.fTxSigma    = 0.0F;
  ExtCal400.fTySigma    = 0.0F;
  ExtCal400.fTzSigma    = 0.0F;

  ExtCal400.fPitchSigma = 0.0F;
  ExtCal400.fYawSigma   = 0.0F;
  ExtCal400.fRollSigma  = 0.0F;

  cct::CMonoCamera camera;
  camera.setParams(ExtCal400.fRoll, ExtCal400.fPitch, ExtCal400.fYaw,
                   ExtCal400.fTx, ExtCal400.fTy, ExtCal400.fTz,
                   IntCalEol400.fFocalX, IntCalEol400.fFocalY, IntCalEol400.fCenterX, IntCalEol400.fCenterY);
  ExtCal400.sTransform = camera.getExtrinsicTransformationMatrix();

  // camera reduced roi calibration
  CroiEol400.sReducedRoi.uiHeight = 640U;
  CroiEol400.sReducedRoi.uiWidth = 1024U;
  CroiEol400.sReducedRoi.uiX = 80U;
  CroiEol400.sReducedRoi.uiY = 0U;
}

#ifdef SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER
void CSimMfcWrapper::wrapStereoCalibration(const mfc310::stereo::SACMeasRectCamPars_t& SAC310,
                                       MonoCalibration_t& RectMono400,
                                       SacRteStereoCalibrationOutput_t& RectStereo400)
{
  // version number
  RectMono400.uiVersionNumber   = MONO_CALIBRATION_INTFVER;

  // signal header info
  SignalHeader_t& MonoHeader = RectMono400.sSignalHeader;
  MonoHeader.eSigStatus           = AL_SIG_STATE_OK;
  MonoHeader.uiCycleCounter       = 0U;//static_cast<AlgoCycleCounter_t> (SAC310.parameterIdRectPars);
  MonoHeader.uiMeasurementCounter = 0U;//static_cast<AlgoCycleCounter_t> (SAC310.dynamicInputData.RectImgRightCurrent.TFStamp.FrameCount);
  MonoHeader.uiTimeStamp          = 0U;//static_cast<AlgoDataTimeStamp_t>(SAC310.dynamicInputData.RectImgRightCurrent.TFStamp.Timestamp);

  RectMono400.uiParameterId    = 0U;
  RectMono400.eSide            = MC_CAMERA_RIGHT;
  RectMono400.eCameraType      = MC_CAMERA_TYPE_RECTIFIED;

  // SacIntrinsicCalibrationData (rectified camera)
  const mfc310::stereo::SACMeasIntrinsicCalibrationDataRect_t& IntCal310 = SAC310.IntrinsicRight;  
  MonoCalibrationIntrinsic_t& IntCal400 = RectMono400.sIntrinsic;
  IntCal400.fFocalX  = IntCal310.FocalX;
  IntCal400.fFocalY  = IntCal310.FocalY;
  IntCal400.fCenterX = IntCal310.CenterX;
  IntCal400.fCenterY = IntCal310.CenterY;
  std::memset( &IntCal400.fDistortionCoefficients[0], 0, sizeof(IntCal400.fDistortionCoefficients) );

  const mfc310::stereo::SACMountingCalibrationData_t& ExtCal310 = SAC310.MountRightRect;
  PoseParameters_t& ExtCal400 = RectMono400.sPoseCalibration;

  ExtCal400.fTx         = ExtCal310.PositionX;
  ExtCal400.fTy         = ExtCal310.PositionY;
  ExtCal400.fTz         = ExtCal310.PositionZ;

  ExtCal400.fPitch      = ExtCal310.Pitch;
  ExtCal400.fYaw        = ExtCal310.Yaw;
  ExtCal400.fRoll       = ExtCal310.Roll;

  ExtCal400.fTxSigma    = 0.0F;
  ExtCal400.fTySigma    = 0.0F;
  ExtCal400.fTzSigma    = 0.0F;

  ExtCal400.fPitchSigma = 0.0F;
  ExtCal400.fYawSigma   = 0.0F;
  ExtCal400.fRollSigma  = 0.0F;

  cct::CMonoCamera camera;
  camera.setParams(ExtCal400.fRoll, ExtCal400.fPitch, ExtCal400.fYaw,
                   ExtCal400.fTx, ExtCal400.fTy, ExtCal400.fTz,
                   IntCal400.fFocalX, IntCal400.fFocalY, IntCal400.fCenterX, IntCal400.fCenterY);
  ExtCal400.sTransform = camera.getExtrinsicTransformationMatrix();

  RectMono400.sPoseDynamic = RectMono400.sPoseCalibration;

  // Stereo...  
  RectStereo400.uiVersionNumber = SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER;
  RectStereo400.sSignalHeader = MonoHeader;

  // identifiers  
  RectStereo400.sStereoCalibration.uiParameterId = 0U;//static_cast<ParameterID_t>(SAC310.parameterIdRectPars);

  RectStereo400.sStereoCalibration.fBaseline = SAC310.BaselineRect / 1000.0F; // baseline is stored in mm 310

  // TODO
  //RectStereo400.fTx = 0.0F;
  //RectStereo400.fTy = RectStereo400.fBaseline;
  //RectStereo400.fTz = 0.0F;

  // TODO: Check this, was RectStereo400.sR_left_right.fA00 = calibMatrix(0,0);
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA00 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA01 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA02 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA03 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA10 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA11 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA12 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA13 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA20 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA21 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA22 = std::numeric_limits<float>::quiet_NaN();
  RectStereo400.sStereoCalibration.sT_left_right.sTransform.fA23 = std::numeric_limits<float>::quiet_NaN();

  std::memset( &RectStereo400.sStereoCalibration.aWindshieldModelCoefficients[0], 0, sizeof(RectStereo400.sStereoCalibration.aWindshieldModelCoefficients) );

  const mfc310::stereo::SACBBox_t& BBLeft310 = SAC310.BBoxLeft;
  SacRteBoundingBox_t& BBLeft400 = RectStereo400.sStereoCalibration.sBoundingBoxLeft;
  BBLeft400.uiBoundingBoxStartX = BBLeft310.BBoxStartX;
  BBLeft400.uiBoundingBoxStartY = BBLeft310.BBoxStartY;
  BBLeft400.uiBoundingBoxHeight = BBLeft310.BBoxHeight;
  BBLeft400.uiBoundingBoxWidth  = BBLeft310.BBoxWidth;



  // Provided SAC values in MFC300 define an unreasonable small box.
  //const mfc310::stereo::SACBBox_t& BBRight310 = SAC310.BBoxRight;
  SacRteBoundingBox_t& BBRight400 = RectStereo400.sStereoCalibration.sBoundingBoxRight;
  BBRight400.uiBoundingBoxStartX = 30;
  BBRight400.uiBoundingBoxStartY = 10;
  BBRight400.uiBoundingBoxHeight = 400;
  BBRight400.uiBoundingBoxWidth  = 964;
}
#endif

void CSimMfcWrapper::wrapICICData(const mfc310::ic::ICEXP_S_Output& ICIC310, const uint16& uSlopeRatioR1, const float32& fBlacklevel, IcImageCharacteristics_t& ICIC400 )
{
  // version number
  ICIC400.uiVersionNumber = IC_IMAGE_CHARACTERISTICS_INTFVER;
  
  if(ICIC400.sSignalHeader.eSigStatus != AL_SIG_STATE_OK)
  {
    ICIC400.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
    ICIC400.sSignalHeader.uiCycleCounter       = 0;
    ICIC400.sSignalHeader.uiMeasurementCounter = 0;
    ICIC400.sSignalHeader.uiTimeStamp          = 0;
  }

  ICIC400.ui16_RequestedSlopeR1 = uSlopeRatioR1;
  ICIC400.e_IntradayState       = (uSlopeRatioR1 == 4) ? IC_INTRADAY_STATE_DAY : IC_INTRADAY_STATE_NIGHT;
  if ((fBlacklevel > 100.0f) && (fBlacklevel < 250.0f))
  {
    ICIC400.ui16_BlackLevel = static_cast<uint16>(fBlacklevel);
  }
  else
  {
    ICIC400.ui16_BlackLevel = 167u;
  }

  // the following signals are only mapped correctly in recent recordings (due to missing IC adapter)
  ICIC400.f32_ExpTimeT1     = 1e-06f * ICIC310.ui16_ExposureTimeUs;
  ICIC400.f32_ExpTimeT2     = 1e-06f * ICIC310.ui16_ExposureTimeUs;
  ICIC400.f32_ExpTimeT3     = 1e-06f * ICIC310.ui16_ExposureTimeUs;
  ICIC400.f32_ExpTimeTotal  = 1e-06f * ICIC310.ui16_ExposureTimeUs;

  ICIC400.e_DcgState            = static_cast<e_DcgState_t>(ICIC310.e_DCGState);
  ICIC400.ui16_RequestedSlopeR2 = ICIC310.ui16_SlopeRatioR2;
  ICIC400.f32_ImagerGainTotal   = ICIC310.f32_DigitalGain;

}

void CSimMfcWrapper::wrapICSRData( const mfc310::ic::IC_S_ResultsPart2& ICRP2310, const mfc310::ic::IC_S_EmbeddedStatData& ICESP310, IcStatisticalResults_t& ICSR400 )
{
  // version number
  ICSR400.uiVersionNumber = IC_IMAGE_STATISTIC_INTFVER;

  ICSR400.sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
  ICSR400.sSignalHeader.uiCycleCounter       = 0;
  ICSR400.sSignalHeader.uiMeasurementCounter = 0;
  ICSR400.sSignalHeader.uiTimeStamp          = 0;
  
  ICSR400.f32_Brightness          = ICRP2310.f32_BrightnessCdqm;
  ICSR400.f32_BrightnessWeighted  = ICRP2310.f32_BrightnessCdqm;
  ICSR400.ui32_MeanGvLin          = ICESP310.ui32_LumaMean;
  ICSR400.ui32_MeanGvLinWeighted  = ICRP2310.ui32_LumaMeanWeighted;
  ICSR400.ui16_MeanGvComp         = ICRP2310.ui16_LumaMeanCompanded;
  ICSR400.ui16_MeanGvWeightedComp = ICRP2310.ui16_LumaMeanCompanded;
}

#ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
void CSimMfcWrapper::wrapFexControlOutput( const mfc310::stereo::SACMeasObjLUTLeft& sacMeasObjLutLeft, 
                                      const mfc310::stereo::SACMeasObjLUTRight& sacMeasObjLutRight,
                                      const mfc310::stereo::SACImageData_t& sacSRoiImageDataLeft,
                                      const mfc310::stereo::SACImageData_t& sacSRoiImageDataRight,
                                      uint16 uParameterIdLUTLeft,
                                      uint16 uParameterIdLUTRight,
                                      SacRteFexControlOutput_t& fexControlOutput )
{
  // Coresspondence Mode
  fexControlOutput.eCorrespondenceMode = SAC_RTE_CM_DEFAULT;

  // Lut Left / Right
  fexControlOutput.sLutLeft.eValid = AL_SIG_STATE_OK;
  fexControlOutput.sLutRight.eValid = AL_SIG_STATE_OK;

  fexControlOutput.sLutLeft.uiParameterId = uParameterIdLUTLeft;
  fexControlOutput.sLutRight.uiParameterId = uParameterIdLUTRight;

  // loop over the 1056 elements
  for(int i = 0; i < SAC_RTE_LUT_ENTRY_COUNT; i++)
  {
    fexControlOutput.sLutLeft.aLutData[i] = sacMeasObjLutLeft[i];
    fexControlOutput.sLutRight.aLutData[i] = sacMeasObjLutRight[i];
  }

  fexControlOutput.sLutLeft.sImgHeader.eDataFormat = ICF_2DVECTORFIELD;
  fexControlOutput.sLutLeft.sImgHeader.iOffsetX = 0;
  fexControlOutput.sLutLeft.sImgHeader.iOffsetY = 0;
  fexControlOutput.sLutLeft.sImgHeader.iPixelBytes = 2;
  fexControlOutput.sLutLeft.sImgHeader.iRowBytes = 2 * 33;
  fexControlOutput.sLutLeft.sImgHeader.iScaleX = 32;
  fexControlOutput.sLutLeft.sImgHeader.iScaleY = 32;
  fexControlOutput.sLutLeft.sImgHeader.iSizeBytes = 2 * 33 * 17;
  fexControlOutput.sLutLeft.sImgHeader.uiBitsPerChannel = 8;
  fexControlOutput.sLutLeft.sImgHeader.uiHeight = 17U;
  fexControlOutput.sLutLeft.sImgHeader.uiParameterId = 0U;
  fexControlOutput.sLutLeft.sImgHeader.uiWidth = 33U;

  fexControlOutput.sLutLeft.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
  fexControlOutput.sLutLeft.sSignalHeader.uiCycleCounter = 0U;
  fexControlOutput.sLutLeft.sSignalHeader.uiMeasurementCounter = 0U;
  fexControlOutput.sLutLeft.sSignalHeader.uiTimeStamp = 0U;

  fexControlOutput.sLutRight.sImgHeader.eDataFormat = ICF_2DVECTORFIELD;
  fexControlOutput.sLutRight.sImgHeader.iOffsetX = 0;
  fexControlOutput.sLutRight.sImgHeader.iOffsetY = 0;
  fexControlOutput.sLutRight.sImgHeader.iPixelBytes = 2;
  fexControlOutput.sLutRight.sImgHeader.iRowBytes = 2 * 33;
  fexControlOutput.sLutRight.sImgHeader.iScaleX = 32;
  fexControlOutput.sLutRight.sImgHeader.iScaleY = 32;
  fexControlOutput.sLutRight.sImgHeader.iSizeBytes = 2 * 33 * 17;
  fexControlOutput.sLutRight.sImgHeader.uiBitsPerChannel = 8;
  fexControlOutput.sLutRight.sImgHeader.uiHeight = 17U;
  fexControlOutput.sLutRight.sImgHeader.uiParameterId = 0U;
  fexControlOutput.sLutRight.sImgHeader.uiWidth = 33U;

  fexControlOutput.sLutRight.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
  fexControlOutput.sLutRight.sSignalHeader.uiCycleCounter = 0U;
  fexControlOutput.sLutRight.sSignalHeader.uiMeasurementCounter = 0U;
  fexControlOutput.sLutRight.sSignalHeader.uiTimeStamp = 0U;  

  // Shifted SRoi Left
  fexControlOutput.sShiftedSRoiLeft.ImgHeight = sacSRoiImageDataLeft.ImgHeight;
  fexControlOutput.sShiftedSRoiLeft.ImgWidth = sacSRoiImageDataLeft.ImgWidth;
  fexControlOutput.sShiftedSRoiLeft.ROIHeight = sacSRoiImageDataLeft.ROIHeight;
  fexControlOutput.sShiftedSRoiLeft.ROIStartRelCroiX = sacSRoiImageDataLeft.ROIStartRelCroiX;
  fexControlOutput.sShiftedSRoiLeft.ROIStartRelCroiY = sacSRoiImageDataLeft.ROIStartRelCroiY;
  fexControlOutput.sShiftedSRoiLeft.ROIStartX = sacSRoiImageDataLeft.ROIStartX;
  fexControlOutput.sShiftedSRoiLeft.ROIStartY = sacSRoiImageDataLeft.ROIStartY;
  fexControlOutput.sShiftedSRoiLeft.ROIWidth = sacSRoiImageDataLeft.ROIWidth;
  fexControlOutput.sShiftedSRoiLeft.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
  fexControlOutput.sShiftedSRoiLeft.sSignalHeader.uiCycleCounter = 0U;
  fexControlOutput.sShiftedSRoiLeft.sSignalHeader.uiMeasurementCounter = 0U;
  fexControlOutput.sShiftedSRoiLeft.sSignalHeader.uiTimeStamp = 0U;

  // Shifted SRoi Right
  fexControlOutput.sShiftedSRoiRight.ImgHeight = sacSRoiImageDataRight.ImgHeight;
  fexControlOutput.sShiftedSRoiRight.ImgWidth = sacSRoiImageDataRight.ImgWidth;
  fexControlOutput.sShiftedSRoiRight.ROIHeight = sacSRoiImageDataRight.ROIHeight;
  fexControlOutput.sShiftedSRoiRight.ROIStartRelCroiX = sacSRoiImageDataRight.ROIStartRelCroiX;
  fexControlOutput.sShiftedSRoiRight.ROIStartRelCroiY = sacSRoiImageDataRight.ROIStartRelCroiY;
  fexControlOutput.sShiftedSRoiRight.ROIStartX = sacSRoiImageDataRight.ROIStartX;
  fexControlOutput.sShiftedSRoiRight.ROIStartY = sacSRoiImageDataRight.ROIStartY;
  fexControlOutput.sShiftedSRoiRight.ROIWidth = sacSRoiImageDataRight.ROIWidth;
  fexControlOutput.sShiftedSRoiRight.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
  fexControlOutput.sShiftedSRoiRight.sSignalHeader.uiCycleCounter = 0U;
  fexControlOutput.sShiftedSRoiRight.sSignalHeader.uiMeasurementCounter = 0U;
  fexControlOutput.sShiftedSRoiRight.sSignalHeader.uiTimeStamp = 0U;

  // Signal Header
  fexControlOutput.sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
  fexControlOutput.sSignalHeader.uiCycleCounter = 0U;
  fexControlOutput.sSignalHeader.uiMeasurementCounter = 0U;
  fexControlOutput.sSignalHeader.uiTimeStamp = 0U;

  // Version Number
  fexControlOutput.uiVersionNumber = SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER;
}
#endif

float32 CSimMfcWrapper::calculateRelativeVY( const mfc310::stereo::SFODObjectList_t& obj, const PoseParameters_t& poseParams )
{
  // the delta time per frame
  static const float32 DT = 0.0603F;

  const float32 objDX = obj.RelativeVelocityX_ms * DT;

  const float32 camX = poseParams.fTx;
  const float32 camY = poseParams.fTy;

  const float32 objXLeftCam  = obj.XLeft_m  - camX;
  const float32 objYLeftCam  = obj.YLeft_m  - camY;
  const float32 objXRightCam = obj.XRight_m - camX;
  const float32 objYRightCam = obj.YRight_m - camY;

  const float32 objXLeftCamLast  = objXLeftCam  - objDX;
  const float32 objXRightCamLast = objXRightCam - objDX;

  float32 objVYLeftCompensated  = 0.0F;
  float32 objVYRightCompensated = 0.0F;

  /* <ln_offset:+1 COVERAGE reviewer name: Martin Warnecke date: 04.07.2012 reason: sanity check */
  if ( std::fabs(objXLeftCamLast) > std::numeric_limits<float32>::epsilon() )
  {
    objVYLeftCompensated   = obj.RelativeVelocityYLeft_ms  + ( obj.RelativeVelocityX_ms * ( objYLeftCam / objXLeftCamLast ) );
  }

  /* <ln_offset:+1 COVERAGE reviewer name: Martin Warnecke date: 04.07.2012 reason: sanity check */
  if ( std::fabs(objXRightCamLast) > std::numeric_limits<float32>::epsilon() )
  {
    objVYRightCompensated  = obj.RelativeVelocityYRight_ms + ( obj.RelativeVelocityX_ms * ( objYRightCam / objXRightCamLast ) );
  }

  // Average compensated relative lateral velocity
  return ( 0.5F * ( objVYLeftCompensated + objVYRightCompensated ) );
}

void CSimMfcWrapper::WrapHlaData()
{
  unsigned long hlarInputPortSize = (unsigned long) m_rp310HLARInput.size();
  if(hlarInputPortSize > 0)
  {
    //HLAR_t_RequiredInputs hlarRequiredInputs;
    ConvertHlarInData(hlarInputPortSize, m_rp310HLARInput.val());

    reqHlaPrtList_t pReqPorts;
    
    //pReqPorts.pCPar_HlaPar                    = &m_oRteCparHla;
    //pReqPorts.pCPar_HlarPar                   = &m_oRteCparHlaR;
    pReqPorts.pParPPAR_ImgCharRight           = &m_oRteParPPAR_ImgCharRight;
    pReqPorts.pParPPAR_RespCurveRight         = &m_oRteParPPAR_RespCurveRight;
    pReqPorts.pParPPAR_ProdIntrinsicRight     = &m_oRteFlspProdIntrRight;
    pReqPorts.pNvm_SigLearningValues          = &m_oRteNvmHla;
    pReqPorts.pSig_HlaSig                     = &m_oRteSig_HlaSig;
    pReqPorts.pSig_HeadlightState             = &m_oRteSig_HeadlightState;
    pReqPorts.pSig_ImgCharOdd                 = &m_oRteIcIcOddRight;
    pReqPorts.pSig_ImgStatResOdd              = &m_oRteIcsr;
    pReqPorts.pSig_MonoCalibrationLaneImager  = &m_oMonoCalibrationLaneImager;

    HLA_SetReqPorts_frm_HLAR(&pReqPorts, &m_HlarRequiredInputs);  // set Reqports from HLAR

    // Copy odd right to odd left after all the wrapping has been done on the right
    m_oRteIcIcOddLeft = m_oRteIcIcOddRight;

    // Set PPortPointer
    m_ppRteParPPAR_ImgCharRight   = &m_oRteParPPAR_ImgCharRight;
    m_ppRteParPPAR_RespCurveRight = &m_oRteParPPAR_RespCurveRight;
    m_ppRteSig_HlaSig             = &m_oRteSig_HlaSig;
    m_ppRteSig_HeadlightState     = &m_oRteSig_HeadlightState;
    m_ppRteFlspProdIntrRight      = &m_oRteFlspProdIntrRight;
    //m_ppRteCparHla                = &m_oRteCparHla;
    //m_ppRteCparHlaR               = &m_oRteCparHlaR;
    m_ppRteNvmHla                 = &m_oRteNvmHla;
    m_ppRteIcIcOddRight           = &m_oRteIcIcOddRight;
    m_ppRteIcIcOddLeft            = &m_oRteIcIcOddLeft;
    m_ppRteIcsr                   = &m_oRteIcsr;
    m_ppMonoCalibrationLaneImager = &m_oMonoCalibrationLaneImager;

    FillSensorAngles();

    // camera mono calibration based on hla data (mono video)
    if((m_uSacMissingCnt > 3U))
    {
      // wrapper for mfc312 mono camera
      mfc310::stereo::SACImageData_t sacImageData;
      mfc310::stereo::SACMountingCalibrationData_t sacMountingCalibData;
      mfc310::stereo::SACMeasIntrinsicCalibrationData_t sacIntrinisicCalibData;

      sacImageData.ImgHeight = static_cast<uint16>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_ImageSize.ui32_y);
      sacImageData.ImgWidth = static_cast<uint16>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_ImageSize.ui32_x);
      sacImageData.ROIHeight = static_cast<uint16>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y);
      sacImageData.ROIStartRelCroiX = 0U;
      sacImageData.ROIStartRelCroiY = 0U;
      sacImageData.ROIStartX = static_cast<uint16>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x);
      sacImageData.ROIStartY = static_cast<uint16>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y);
      sacImageData.ROIWidth = static_cast<uint16>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x);
      sacImageData.VersionNumber = 0U;

      sacMountingCalibData.DeltaPitch = 0.0F;
      sacMountingCalibData.DeltaRoll = 0.0F;
      sacMountingCalibData.DeltaYaw = 0.0F;
      sacMountingCalibData.Pitch = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Pitch);
      sacMountingCalibData.PositionX = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_SensorSocket.f32_X);
      sacMountingCalibData.PositionY = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_SensorSocket.f32_Y);
      sacMountingCalibData.PositionZ = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_SensorSocket.f32_Z);
      sacMountingCalibData.Quality = 0.0F;
      sacMountingCalibData.Roll = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Roll);
      sacMountingCalibData.VersionNumber = 0U;
      sacMountingCalibData.Yaw = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Yaw);

      sacIntrinisicCalibData.CenterX = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_LensCenter.f32_x);
      sacIntrinisicCalibData.CenterY = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_LensCenter.f32_y);
      sacIntrinisicCalibData.FocalX = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_FocalLength.f32_x);
      sacIntrinisicCalibData.FocalY = static_cast<float32>(m_HlarRequiredInputs.s_Par.s_CameraParameter.s_FocalLength.f32_y);

      if(m_uAngOffsetMissingCnt < 10U)
      {
        sacMountingCalibData.DeltaPitch = m_fPitchOffset;
        sacMountingCalibData.DeltaRoll = m_fRollOffset;
        sacMountingCalibData.DeltaYaw = m_fYawOffset;
      }

      for(uint32 uDistNr = 0; uDistNr < SAC_MEAS_NumRadDistCoeff; uDistNr++)
      {
        sacIntrinisicCalibData.RadialDistortion[uDistNr] = 0.0F;
      }
      
      wrapCroiCalibration(
        sacImageData,
        sacMountingCalibData,
        sacIntrinisicCalibData,
        m_oRteCroiCal );
      m_ppRteCroiCal = &m_oRteCroiCal;

      wrapCroiCalibrationEol(
        sacImageData,
        sacMountingCalibData,
        sacIntrinisicCalibData,
        m_oRteCroiCalEol );
      m_ppRteCroiCalEol = &m_oRteCroiCalEol;

  #ifdef SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
      // fill m_oRteFexCtrlOutput with null
      memset(&m_oRteFexCtrlOutput, 0x0, sizeof(SacRteFexControlOutput_t));
      m_ppRteFexCtrlOutput = &m_oRteFexCtrlOutput;
  #endif

      // fill MonoCailbrationEmoCRoi
      m_ppRteCroiCalEmo = &m_oRteCroiCal;

      // fill MonoCailbrationEmoRRoi
      memcpy(&m_oRteRroiCalEmo, &m_oRteCroiCal, sizeof(MonoCalibration_t));
      m_oRteRroiCalEmo.sIntrinsic.fCenterX -= 80.0F;
      m_oRteRroiCalEmo.sIntrinsic.fCenterY -= 0.0F;
      m_ppRteRroiCalEmo = &m_oRteRroiCalEmo;

      // fill MonoCalibrationImagerEmo
      memcpy(&m_oRteImagerCalEmo, &m_oRteCroiCal, sizeof(MonoCalibration_t));
      m_oRteImagerCalEmo.sIntrinsic.fCenterX = sacIntrinisicCalibData.CenterX;
      m_oRteImagerCalEmo.sIntrinsic.fCenterY = sacIntrinisicCalibData.CenterY;
      m_ppRteImagerCalEmo = &m_oRteImagerCalEmo;
    }
  }

}

bool CSimMfcWrapper::ReceivedAnyMFC3xxData()
{
  if( m_rp310VehSigSpeedoSpeed.isDirty()
    || m_rp310VehSigSpeedUnit.isDirty()
    || m_rp310VehSigVehVelocityExt.isDirty()
    || m_rp310VehSigSpeedUnit.isDirty()
    || m_rp310VehSigSpeedoSpeed.isDirty()
    || m_rp310VehSigTurnSignal.isDirty()
    || m_rp310VehSigStWheelAngle.isDirty()
    || m_rp310VehSigBrakeActLevel.isDirty()
    || m_rp310VehSigChassisControlEvent.isDirty()
    || m_rp310CroiImageData.isDirty()
    || m_rp310SacIntrinsicRight.isDirty()
    || m_rp310SacMountingData.isDirty()
    || m_rp310SacSRoiImageDataLeft.isDirty() 
    || m_rp310SacSRoiImageDataRight.isDirty()
    || m_rp310SrInputConfig.isDirty()
    || m_rp310EcmSensorSocket.isDirty() 
    || m_rp310EcmSensorAngles.isDirty()
    || m_rp310LdParameterInOut.isDirty()
    || m_rp310IcicOdd.isDirty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

void CSimMfcWrapper::MeasFreezeMFC3xxData()
{
  __try
  {
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMLDONLINECALIDATA, m_ppRteNvmLd, sizeof(NVM_LdOnlineCaliData_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMSRRTE, m_ppRteNvmSr, sizeof(NVM_SR_RTE_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMECMRTEIN, m_ppRteNvmEcm, sizeof(NVM_EcmRte_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMSIGLEARNINGVALUES, m_ppRteNvmHla, sizeof(NVM_HLAR_LearningValues_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMTSARTEPERSSTATE, m_ppRteNvmTsa, sizeof(NvmTsaRteState_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMSAC, m_ppRteNvmSac, sizeof(NVM_SacRte_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PNVMEMOREAD, m_ppRteNvmEmo, sizeof(NVM_Emo_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARFCTPARAMETERS, m_ppRteCparAldw, sizeof(CPAR_ALDW_Parameters_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARECMRTE, m_ppRteCparEcm, sizeof(CPAR_EcmRte_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPAREMO, m_ppRteCparEmo, sizeof(CPAR_Emo_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARHLAFPAR, m_ppRteCparHlaF, sizeof(CPAR_HLAF_Parameter_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARHLARPAR, m_ppRteCparHlaR, sizeof(CPAR_HLAR_Parameter_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARHLAPAR, m_ppRteCparHla, sizeof(CPAR_HLA_Parameter_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARSRRTEPARAMETERS, m_ppRteCparSr, sizeof(CPAR_SR_RTE_parameters_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARSAC, m_ppRteCparSac, sizeof(CPAR_SacRte_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PCPARTSARTEPARAMETER, m_ppRteCparTsa, sizeof(CPAR_TSA_RTE_parameters_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONCROI, m_ppRteCroiCal, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSROI, m_ppRteSroiCal, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSEMOCROI, m_ppRteCroiCalSemo, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOCROI, m_ppRteCroiCalEmo, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMORROI, m_ppRteRroiCalEmo, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOIMAGER, m_ppRteImagerCalEmo, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEOLRIGHT, m_ppRteCroiCalEol, sizeof(MonoCalibrationEol_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_STEREOCALIBRATION, m_ppRteSacStereoCal, sizeof(SacRteStereoCalibrationOutput_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSLEFT, m_ppRteFlspImagerCharRight, sizeof(FLSPImagerCharacteristicsLeft_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICLEFT, m_ppRteFlspProductionIntrinsicLeft, sizeof(FLSPProductionIntrinsic_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICRIGHT, m_ppRteFlspProdIntrRight, sizeof(FLSPProductionIntrinsic_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSLEFT, m_ppRteFlspStereoCallIntrinsicsLeft, sizeof(FLSPStereoCalIntrinsics_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSRIGHT, m_ppRteFlspStereoCallIntrinsicsRight, sizeof(FLSPStereoCalIntrinsics_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALTRANSROT, m_ppRteFlspStereoCalTransRot, sizeof(FLSPStereoCalTransRot_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPTEMPERATURECOMPENSATIONLIST, m_ppRteFlspTemperatureCompensationList, sizeof(FLSPTemperatureCompensationList_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPCALINTRDISTRIGHT, m_ppRteFlspCalIntrDistRight, sizeof(FLSPCalIntrDistRight_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONDATA, m_ppRteFlspProdData, sizeof(FLSPProductionData_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSRIGHT, m_ppRteParPPAR_ImgCharRight, sizeof(FLSPImagerCharacteristicsRight_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PFLSPRESPONSECURVEPERIPHERY, m_ppRteParPPAR_RespCurveRight, sizeof(FLSPResponseCurvePeriphery_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_ALGOCOMPSTATE, &m_ppAlgoCompState, sizeof(AlgoCompState_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PSIGHLASIG, m_ppRteSig_HlaSig, sizeof(RTE_HLA_Signals_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PHLAHEADLIGHTSTATE, m_ppRteSig_HeadlightState, sizeof(RTE_HLA_HeadlightState_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PSIGMONOCALIBRATIONLANEIMAGER, m_ppMonoCalibrationLaneImager, sizeof(MonoCalibration_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSEVENRIGHT, m_ppRteIcIcEvenRight, sizeof(IcImageCharacteristics_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSEVEN, m_ppRteIcImageStatisticEven, sizeof(IcStatisticalResults_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_FCTALDWINPUTGENERIC, m_ppRteFCTAldwInputGen, sizeof(FCTALDWInputGeneric_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PDIMINPUTCUSTOM, m_ppRteDIMInputCustom, sizeof(DIMInputCustom_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PDIMINPUTGENERIC, m_ppRteDIMInputGeneric, sizeof(DIMInputGeneric_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PHEADINPUTCUSTOM, m_ppRteHEADInputCustom, sizeof(HEADInputCustom_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PHEADINPUTGENERIC, m_ppRteHEADInputGeneric, sizeof(HEADInputGeneric_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PHMIDATA, m_ppRteHMIInputData, sizeof(t_HMI_Data_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PRTEINPUTGPS, m_ppRteTsaInputGPS, sizeof(RteInputGPS_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PTSARTECUSTOMINPUT, m_ppRteTsaCustomInput, sizeof(TsaRteCustomInput_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_ECUSTATET, m_ppRteEcuStateM3_0, sizeof(EcuState_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_SACRTESTEREOROIINPUT, m_ppRteSacStereoRoiM3_10, sizeof(SacRteStereoRoiInput_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDRIGHT, m_ppRteIcIcOddRight, sizeof(IcImageCharacteristics_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDLEFT, m_ppRteIcIcOddLeft, sizeof(IcImageCharacteristics_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSODD, m_ppRteIcsr, sizeof(IcStatisticalResults_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PSACFEXCONTROLOUTPUT, m_ppRteFexCtrlOutput, sizeof(SacRteFexControlOutput_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PVEHPAR, m_ppRteVehPar, sizeof(VehPar_t));
    MeasFreezeSim(GIA_MEAS_ID_WRAPPER_PVEHSIG, m_ppRteVehSig, sizeof(VehSig_t));
  }
  __except (SimDbgEvaluateException(GetExceptionCode(), GetExceptionInformation(), reinterpret_cast<CSimSwcBase*>(this) ) )
  {
  }
}

void CSimMfcWrapper::FillSensorAngles()
{
  if(!m_ppRteVehPar) return;

  // VehPar sensor mounting angles wrapping from HLA inputs
  // VehPar is adapted on the request port by the GIA adapter to the configured RTE
  VehPar_t *vehPar = reinterpret_cast<VehPar_t*>(m_ppRteVehPar);

  vehPar->SensorMounting.Orientation = (Orientation_t)m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Roll;
  vehPar->SensorMounting.PitchAngle  = m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Pitch;
  vehPar->SensorMounting.YawAngle    = m_HlarRequiredInputs.s_Par.s_SensorAngles.f32_Yaw; 
  vehPar->SensorMounting.LongPos = static_cast<float32>(m_rp310SensorX.val());
  vehPar->SensorMounting.LatPos = static_cast<float32>(m_rp310SensorY.val());
  vehPar->SensorMounting.VertPos = static_cast<float32>(m_rp310SensorZ.val());
}

long CSimMfcWrapper::ConvertHlarInData(unsigned long ulPPortSize,  void* pPPortData)
{
  uint32 Error = SIM_ERR_OK;
  CHlarInputData inputDataConverter;
  

  if(    ((ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V1_1]) || (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V1_2])) &&
         ((reinterpret_cast<HLAR_t_RequiredInputs_v1 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V1_1]) ||(reinterpret_cast<HLAR_t_RequiredInputs_v1 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V1_2]))
    )
  {
    inputDataConverter.SetHlarInputData_v1(reinterpret_cast<HLAR_t_RequiredInputs_v1 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V2] &&
           reinterpret_cast<HLAR_t_RequiredInputs_v2 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V2])
  {
    inputDataConverter.SetHlarInputData_v2(reinterpret_cast<HLAR_t_RequiredInputs_v2 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V3] &&
           reinterpret_cast<HLAR_t_RequiredInputs_v3 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V3])
  {
    Error = inputDataConverter.SetHlarInputData_v3(reinterpret_cast<HLAR_t_RequiredInputs_v3 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V3] &&
           reinterpret_cast<HLAR_t_RequiredInputs_v3 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V4])
  {
    Error = inputDataConverter.SetHlarInputData_v4(reinterpret_cast<HLAR_t_RequiredInputs_v3 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V5] &&
           reinterpret_cast<HLAR_t_RequiredInputs_v4 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V5])
  {
    assert(sizeof(HLAR_t_RequiredInputs_v4)<=sizeof(m_HlarRequiredInputs));
    Error = inputDataConverter.SetHlarInputData_v5(reinterpret_cast<HLAR_t_RequiredInputs_v4 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V6] &&
           reinterpret_cast<HLAR_t_RequiredInputs_v5 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V6])
  {
    Error = inputDataConverter.SetHlarInputData_v6(reinterpret_cast<HLAR_t_RequiredInputs_v5 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V7] &&
           reinterpret_cast<HLAR_t_RequiredInputs_v6 *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V7])
  {
    Error = inputDataConverter.SetHlarInputData_v7(reinterpret_cast<HLAR_t_RequiredInputs_v6 *>(pPPortData), &m_HlarRequiredInputs);
    //HLAR_t_RequiredInputs_v6* pIn = reinterpret_cast<HLAR_t_RequiredInputs_v6 *>(pPPortData);
    //AdaptDefectPixelList(pIn);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V8] &&
    (0xFFFFFF & reinterpret_cast<HLAR_t_RequiredInputs_v7 *>(pPPortData)->ui32_InterfaceVersionNumber) == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V8])
  {
    Error = inputDataConverter.SetHlarInputData_v8(reinterpret_cast<HLAR_t_RequiredInputs_v7 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V9] &&
    (0xFFFFFF & reinterpret_cast<HLAR_t_RequiredInputs_v8 *>(pPPortData)->ui32_InterfaceVersionNumber) == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V9])
  {
    Error = inputDataConverter.SetHlarInputData_v9(reinterpret_cast<HLAR_t_RequiredInputs_v8 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V10] &&
    (0xFFFFFF & reinterpret_cast<HLAR_t_RequiredInputs_v9 *>(pPPortData)->ui32_InterfaceVersionNumber) == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V10])
  {
    Error = inputDataConverter.SetHlarInputData_v10(reinterpret_cast<HLAR_t_RequiredInputs_v9 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V11] &&
    (0xFFFFFF & reinterpret_cast<HLAR_t_RequiredInputs_v10 *>(pPPortData)->ui32_InterfaceVersionNumber) == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V11])
  {
    Error = inputDataConverter.SetHlarInputData_v11(reinterpret_cast<HLAR_t_RequiredInputs_v10 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_V12] &&
    (0xFFFFFF & reinterpret_cast<HLAR_t_RequiredInputs_v11 *>(pPPortData)->ui32_InterfaceVersionNumber) == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_V12])
  {
    Error = inputDataConverter.SetHlarInputData_v12(reinterpret_cast<HLAR_t_RequiredInputs_v11 *>(pPPortData), &m_HlarRequiredInputs);
  }
  else if (ulPPortSize == CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_ORIG] && pPPortData && 
    reinterpret_cast<HLAR_t_RequiredInputs *>(pPPortData)->ui32_InterfaceVersionNumber == CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_ORIG])
  {
    /* No conversion needed in this case */
    memcpy(&m_HlarRequiredInputs, pPPortData, sizeof(HLAR_t_RequiredInputs));
  }
  else
  {
    return SIM_ERR_NO_CONVERTER_FOR_PORT;
  }

  return Error;
}

//void CSimMfcWrapper::AdaptDefectPixelListV1(HLAR_t_RequiredInputs_v1 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV2(HLAR_t_RequiredInputs_v2 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV3(HLAR_t_RequiredInputs_v3 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV4(HLAR_t_RequiredInputs_v4 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV5(HLAR_t_RequiredInputs_v5 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV6(HLAR_t_RequiredInputs_v6 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV7(HLAR_t_RequiredInputs_v7 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV8(HLAR_t_RequiredInputs_v8 *pIn)
//{
//    for(int i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV9(HLAR_t_RequiredInputs_v9 *pIn)
//{
//    for(int i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV10(HLAR_t_RequiredInputs_v10 *pIn)
//{
//    for(int i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV11(HLAR_t_RequiredInputs_v11 *pIn)
//{
//    for(int i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV12(HLAR_t_RequiredInputs_v12 *pIn)
//{
//    for(int i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}
//
//void CSimMfcWrapper::AdaptDefectPixelListV13(HLAR_t_RequiredInputs_v13 *pIn)
//{
//    for(int i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
//    {
//      Set_ICDefectPixel( m_HlarRequiredInputs.s_Sig.s_DefectPixelList.as_DefectList[i],
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
//                                        pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
//                                      );
//    }
//}

void CSimMfcWrapper::InitializeCparsDefault()
{
  InitHlaCparDefault();
  InitAldwCparDefault();
  InitSrCparDefault();
  InitSacCparDefault();
  InitEcmCparDefault();
  InitTsaCparDefault();
  InitEmoCparDefault();
}

void CSimMfcWrapper::InitHlaCparDefault()
{
  if(0 == CParInit_HlaPar(&m_oRteCparHla))
  {
    m_ppRteCparHla = &m_oRteCparHla;
  }
  if(0 == CParInit_HlarPar(&m_oRteCparHlaR))
  {
    m_ppRteCparHlaR = &m_oRteCparHlaR;
  }
  if(0 == CParInit_HlafPar(&m_oRteCparHlaF))
  {
    m_ppRteCparHlaF = &m_oRteCparHlaF;
  }
}

void CSimMfcWrapper::InitAldwCparDefault()
{
}

void CSimMfcWrapper::InitEmoCparDefault()
{
  if(0 == CParInitEmo(&m_oRteCparEmo))
  {
    m_ppRteCparEmo = &m_oRteCparEmo;
  }
}

void CSimMfcWrapper::InitSrCparDefault()
{
  if(0 == CParInitSrRteParameters(&m_oRteCparSr))
  {
    m_ppRteCparSr = &m_oRteCparSr;
  }
}

void CSimMfcWrapper::InitSacCparDefault()
{
  if(0 == CParInitSac(&m_oRteCparSac))
  {
    m_ppRteCparSac = &m_oRteCparSac;
  }
}

void CSimMfcWrapper::InitEcmCparDefault()
{
  if(0 == CParInitEcm(&m_oRteCparEcm))
  {
    m_ppRteCparEcm = &m_oRteCparEcm;
  }
}

void CSimMfcWrapper::InitTsaCparDefault()
{
  if(0 == CParInitTsaRteParameters(&m_oRteCparTsa))
  {
    m_ppRteCparTsa = &m_oRteCparTsa;
  }
}

void CSimMfcWrapper::InitializeProvidePorts()
{
  memset(&m_oRteCroiCal, 0, sizeof(m_oRteCroiCal));
  m_ppRteCroiCal = &m_oRteCroiCal;

  memset(&m_oRteCroiCalEol, 0, sizeof(m_oRteCroiCalEol));
  m_ppRteCroiCalEol = &m_oRteCroiCalEol;

  memset(&m_oRteFexCtrlOutput, 0, sizeof(m_oRteFexCtrlOutput));
  m_ppRteFexCtrlOutput = &m_oRteFexCtrlOutput;

  memset(&m_oRteRroiCalEmo, 0, sizeof(m_oRteRroiCalEmo));
  m_ppRteRroiCalEmo = &m_oRteRroiCalEmo;

  memset(&m_oRteImagerCalEmo, 0, sizeof(m_oRteImagerCalEmo));
  m_ppRteImagerCalEmo = &m_oRteImagerCalEmo;

  memset(&m_oRteSacStereoCal, 0, sizeof(m_oRteSacStereoCal));
  m_ppRteSacStereoCal = &m_oRteSacStereoCal;

  memset(&m_oRteSroiCal, 0, sizeof(m_oRteSroiCal));
  m_ppRteSroiCal = &m_oRteSroiCal;

  memset(&m_oRteFlspCalIntrDistRight, 0, sizeof(m_oRteFlspCalIntrDistRight));
  m_ppRteFlspCalIntrDistRight = &m_oRteFlspCalIntrDistRight;

  memset(&m_oRteFlspProdData, 0, sizeof(m_oRteFlspProdData));
  m_ppRteFlspProdData = &m_oRteFlspProdData;

  memset(&m_oRteFlspProdIntrRight, 0, sizeof(m_oRteFlspProdIntrRight));
  m_ppRteFlspProdIntrRight = &m_oRteFlspProdIntrRight;

  memset(&m_oRteVehSig, 0, sizeof(m_oRteVehSig));
  m_ppRteVehSig = &m_oRteVehSig;

  memset(&m_oRteVehPar, 0, sizeof(m_oRteVehPar));
  m_ppRteVehPar = &m_oRteVehPar;

  memset(&m_oRteIcIcOddRight, 0, sizeof(m_oRteIcIcOddRight));
  m_ppRteIcIcOddRight = &m_oRteIcIcOddRight;

  memset(&m_oRteIcIcOddLeft, 0, sizeof(m_oRteIcIcOddLeft));
  m_ppRteIcIcOddLeft = &m_oRteIcIcOddLeft;

  memset(&m_oRteIcsr, 0, sizeof(m_oRteIcsr));
  m_ppRteIcsr = &m_oRteIcsr;

  memset(&m_oRteNvmLd, 0, sizeof(m_oRteNvmLd));
  m_ppRteNvmLd = &m_oRteNvmLd;

  memset(&m_oRteNvmSr, 0, sizeof(m_oRteNvmSr));
  m_ppRteNvmSr = &m_oRteNvmSr;

  memset(&m_oRteNvmEcm, 0, sizeof(m_oRteNvmEcm));
  m_ppRteNvmEcm = &m_oRteNvmEcm;

  memset(&m_oRteNvmHla, 0, sizeof(m_oRteNvmHla));
  m_ppRteNvmHla = &m_oRteNvmHla;

  memset(&m_oRteNvmTsa, 0, sizeof(m_oRteNvmTsa));
  m_ppRteNvmTsa = &m_oRteNvmTsa;

  memset(&m_oRteNvmSac, 0, sizeof(m_oRteNvmSac));
  m_ppRteNvmSac = &m_oRteNvmSac;

  memset(&m_oRteNvmEmo, 0, sizeof(m_oRteNvmEmo));
  m_ppRteNvmEmo = &m_oRteNvmEmo;

  memset(&m_oRteCparAldw, 0, sizeof(m_oRteCparAldw));
  m_ppRteCparAldw = &m_oRteCparAldw;

  memset(&m_oRteCparEcm, 0, sizeof(m_oRteCparEcm));
  m_ppRteCparEcm = &m_oRteCparEcm;

  memset(&m_oRteCparHlaF, 0, sizeof(m_oRteCparHlaF));
  m_ppRteCparHlaF = &m_oRteCparHlaF;

  memset(&m_oRteCparHlaR, 0, sizeof(m_oRteCparHlaR));
  m_ppRteCparHlaR = &m_oRteCparHlaR;

  memset(&m_oRteCparHla, 0, sizeof(m_oRteCparHla));
  m_ppRteCparHla = &m_oRteCparHla;

  memset(&m_oRteCparSr, 0, sizeof(m_oRteCparSr));
  m_ppRteCparSr = &m_oRteCparSr;

  memset(&m_oRteCparTsa, 0, sizeof(m_oRteCparTsa));
  m_ppRteCparTsa = &m_oRteCparTsa;

  memset(&m_oRteCparSac, 0, sizeof(m_oRteCparSac));
  m_ppRteCparSac = &m_oRteCparSac;

  memset(&m_oRteCparEmo, 0, sizeof(m_oRteCparEmo));
  memset(&m_ppRteCparEmo, 0, sizeof(m_oRteCparEmo));
  m_ppRteCparEmo = &m_oRteCparEmo;

  memset(&m_oRteFlspImagerCharRight, 0, sizeof(m_oRteFlspImagerCharRight));
  m_ppRteFlspImagerCharRight = &m_oRteFlspImagerCharRight;

  memset(&m_oRteFlspProductionIntrinsicLeft, 0, sizeof(m_oRteFlspProductionIntrinsicLeft));
  m_ppRteFlspProductionIntrinsicLeft = &m_oRteFlspProductionIntrinsicLeft;

  memset(&m_oRteFlspStereoCallIntrinsicsLeft, 0, sizeof(m_oRteFlspStereoCallIntrinsicsLeft));
  m_ppRteFlspStereoCallIntrinsicsLeft = &m_oRteFlspStereoCallIntrinsicsLeft;

  memset(&m_oRteFlspStereoCallIntrinsicsRight, 0, sizeof(m_oRteFlspStereoCallIntrinsicsRight));
  m_ppRteFlspStereoCallIntrinsicsRight = &m_oRteFlspStereoCallIntrinsicsRight;

  memset(&m_oRteFlspStereoCalTransRot, 0, sizeof(m_oRteFlspStereoCalTransRot));
  m_ppRteFlspStereoCalTransRot = &m_oRteFlspStereoCalTransRot;

  memset(&m_oRteFlspTemperatureCompensationList, 0, sizeof(m_oRteFlspTemperatureCompensationList));
  m_ppRteFlspTemperatureCompensationList = &m_oRteFlspTemperatureCompensationList;

  memset(&m_oRteIcIcEvenRight, 0, sizeof(m_oRteIcIcEvenRight));
  m_ppRteIcIcEvenRight = &m_oRteIcIcEvenRight;

  memset(&m_oRteIcImageStatisticEven, 0, sizeof(m_oRteIcImageStatisticEven));
  m_ppRteIcImageStatisticEven = &m_oRteIcImageStatisticEven;

  memset(&m_oRteFCTAldwInputGen, 0, sizeof(m_oRteFCTAldwInputGen));
  m_ppRteFCTAldwInputGen = &m_oRteFCTAldwInputGen;

  memset(&m_oRteDIMInputCustom, 0, sizeof(m_oRteDIMInputCustom));
  m_ppRteDIMInputCustom = &m_oRteDIMInputCustom;

  memset(&m_oRteDIMInputGeneric, 0, sizeof(m_oRteDIMInputGeneric));
  m_ppRteDIMInputGeneric = &m_oRteDIMInputGeneric;

  memset(&m_oRteHEADInputCustom, 0, sizeof(m_oRteHEADInputCustom));
  m_ppRteHEADInputCustom = &m_oRteHEADInputCustom;

  memset(&m_oRteHEADInputGeneric, 0, sizeof(m_oRteHEADInputGeneric));
  m_ppRteHEADInputGeneric = &m_oRteHEADInputGeneric;

  memset(&m_oRteHMIInputData, 0, sizeof(m_oRteHMIInputData));
  m_ppRteHMIInputData = &m_oRteHMIInputData;

  memset(&m_oRteTsaInputGPS, 0, sizeof(m_oRteTsaInputGPS));
  m_ppRteTsaInputGPS = &m_oRteTsaInputGPS;

  memset(&m_oRteTsaCustomInput, 0, sizeof(m_oRteTsaCustomInput));
  m_ppRteTsaCustomInput = &m_oRteTsaCustomInput;

  memset(&m_oRteEcuStateM3_0, 0, sizeof(m_oRteEcuStateM3_0));
  m_ppRteEcuStateM3_0 = &m_oRteEcuStateM3_0;

  memset(&m_oRteSacStereoRoiM3_10, 0, sizeof(m_oRteSacStereoRoiM3_10));
  m_ppRteSacStereoRoiM3_10 = &m_oRteSacStereoRoiM3_10;

  memset(&m_oRteParPPAR_ImgCharRight, 0, sizeof(m_oRteParPPAR_ImgCharRight));
  m_ppRteParPPAR_ImgCharRight = &m_oRteParPPAR_ImgCharRight;

  memset(&m_oRteParPPAR_RespCurveRight, 0, sizeof(m_oRteParPPAR_RespCurveRight));
  m_ppRteParPPAR_RespCurveRight = &m_oRteParPPAR_RespCurveRight;

  memset(&m_oRteSig_HlaSig, 0, sizeof(m_oRteSig_HlaSig));
  m_ppRteSig_HlaSig = &m_oRteSig_HlaSig;

  memset(&m_oRteSig_HeadlightState, 0, sizeof(m_oRteSig_HeadlightState));
  m_ppRteSig_HeadlightState = &m_oRteSig_HeadlightState;

  memset(&m_oMonoCalibrationLaneImager, 0, sizeof(m_oMonoCalibrationLaneImager));
  m_ppMonoCalibrationLaneImager = &m_oMonoCalibrationLaneImager;

  memset(&m_oRteCroiCal, 0, sizeof(m_oRteCroiCal));
  // Two ports sharing the same member
  m_ppRteCroiCalEmo = &m_oRteCroiCal;
  m_ppRteCroiCalSemo = &m_oRteCroiCal;
}

void CSimMfcWrapper::ResetProvidePortSizeAndVersionnumber()
{
    UpdatePPortSize   (PP_ALGO_COMP_STATE,              sizeof(AlgoCompState_t),             FALSE);
    ChangePPortVersion(PP_ALGO_COMP_STATE, CreateVersionInfoFromI32(COMP_STATE_INTFVER));

    UpdatePPortSize   (PP_RTE_CROI_CAL,                 sizeof(m_oRteCroiCal),                FALSE);
    ChangePPortVersion(PP_RTE_CROI_CAL, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_SROI_CAL,                 sizeof(m_oRteSroiCal),                FALSE);
    ChangePPortVersion(PP_RTE_SROI_CAL, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_EOL_CAL_RIGHT,            sizeof(m_oRteCroiCalEol),             FALSE);
    ChangePPortVersion(PP_RTE_EOL_CAL_RIGHT, CreateVersionInfoFromI32(MONO_CALIBRATION_EOL_INTFVER));

    UpdatePPortSize   (PP_RTE_CROI_CAL_EMO,             sizeof(m_oRteCroiCal),                FALSE);
    ChangePPortVersion(PP_RTE_CROI_CAL_EMO, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_RROI_CAL_EMO,             sizeof(m_oRteRroiCalEmo),             FALSE);
    ChangePPortVersion(PP_RTE_RROI_CAL_EMO, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_CROI_CAL_SEMO,            sizeof(m_oRteCroiCal),                FALSE);
    ChangePPortVersion(PP_RTE_CROI_CAL_SEMO, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_IMAGER_CAL_EMO,           sizeof(m_oRteImagerCalEmo),           FALSE);
    ChangePPortVersion(PP_RTE_IMAGER_CAL_EMO, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_CAL_INTR_DIST_RIGHT, sizeof(m_oRteFlspCalIntrDistRight),   FALSE);
    ChangePPortVersion(PP_RTE_FLSP_CAL_INTR_DIST_RIGHT, CreateVersionInfoFromI32(FLSP_CALL_INTR_DIST_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_PROD_DATA,           sizeof(m_oRteFlspProdData),           FALSE);
    ChangePPortVersion(PP_RTE_FLSP_PROD_DATA, CreateVersionInfoFromI32(FLSP_PROD_DATA_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_PROD_INTR_RIGHT,     sizeof(m_oRteFlspProdIntrRight),      FALSE);
    ChangePPortVersion(PP_RTE_FLSP_PROD_INTR_RIGHT, CreateVersionInfoFromI32(FLSP_PROD_INTR_INTFVER));

    UpdatePPortSize   (PP_RTE_STEREO_CAL,               sizeof(m_oRteSacStereoCal),           FALSE);
    ChangePPortVersion(PP_RTE_STEREO_CAL, CreateVersionInfoFromI32(SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER));

    UpdatePPortSize   (PP_RTE_ICIC_ODD_RIGHT,                     sizeof(m_oRteIcIcOddRight), FALSE);
    ChangePPortVersion(PP_RTE_ICIC_ODD_RIGHT, CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));

    UpdatePPortSize   (PP_RTE_ICIC_ODD_LEFT,                     sizeof(m_oRteIcIcOddLeft),   FALSE);
    ChangePPortVersion(PP_RTE_ICIC_ODD_LEFT, CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));

    UpdatePPortSize   (PP_RTE_ICSR,                     sizeof(m_oRteIcsr),                   FALSE);
    ChangePPortVersion(PP_RTE_ICSR, CreateVersionInfoFromI32(IC_IMAGE_STATISTIC_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_IMG_CHAR_RIGHT,      sizeof(m_oRteParPPAR_ImgCharRight),   FALSE);
    ChangePPortVersion(PP_RTE_FLSP_IMG_CHAR_RIGHT, CreateVersionInfoFromI32(FLSP_IMAGER_CHAR_RIGHT_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_RESPONSE_CURVE_RIGHT,sizeof(m_oRteParPPAR_RespCurveRight), FALSE);
    ChangePPortVersion(PP_RTE_FLSP_RESPONSE_CURVE_RIGHT, CreateVersionInfoFromI32(FLSP_RESPONSE_CURVES_INTFVER));

    UpdatePPortSize   (PP_RTE_HLA_SIGNALS,              sizeof(m_oRteSig_HlaSig),             FALSE);
    ChangePPortVersion(PP_RTE_HLA_SIGNALS, CreateVersionInfoFromI32(RTE_HLA_SIGNALS_INTFVER));

    UpdatePPortSize   (PP_RTE_HLA_HEADLIGHT_STATE,      sizeof(m_oRteSig_HeadlightState),     FALSE);
    ChangePPortVersion(PP_RTE_HLA_HEADLIGHT_STATE, CreateVersionInfoFromI32(RTE_HLA_HEADLIGHT_STATE_INTFVER));

    UpdatePPortSize   (PP_MONOCALIBRATION_LANE_IMAGER,  sizeof(m_oMonoCalibrationLaneImager), FALSE);
    ChangePPortVersion(PP_MONOCALIBRATION_LANE_IMAGER, CreateVersionInfoFromI32(MONO_CALIBRATION_INTFVER));

    UpdatePPortSize   (PP_RTE_FEX_CTRL_OUTPUT,          sizeof(m_oRteFexCtrlOutput),          FALSE);
    ChangePPortVersion(PP_RTE_FEX_CTRL_OUTPUT, CreateVersionInfoFromI32(SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER));

    UpdatePPortSize   (PP_RTE_VEH_PAR,                  sizeof(VehPar_t),                     FALSE);
    ChangePPortVersion(PP_RTE_VEH_PAR, CreateVersionInfoFromI32(BSW_VEH_PAR_INTFVER));

    UpdatePPortSize   (PP_RTE_VEH_SIG,                  sizeof(m_oRteVehSig),                 FALSE);
    ChangePPortVersion(PP_RTE_VEH_SIG, CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));

    //NVM Signals
    UpdatePPortSize   (PP_RTE_NVM_LD,                                  sizeof(m_oRteNvmLd),                            FALSE);
    ChangePPortVersion(PP_RTE_NVM_LD, CreateVersionInfoFromI32(LD_ONLINE_CALI_DATA_INTFVER));

    UpdatePPortSize   (PP_RTE_NVM_SR,                                  sizeof(m_oRteNvmSr),                            FALSE);
    ChangePPortVersion(PP_RTE_NVM_SR, CreateVersionInfoFromI32(NVM_SR_RTE_INTFVER));

    UpdatePPortSize   (PP_RTE_NVM_ECM,                                 sizeof(m_oRteNvmEcm),                           FALSE);
    ChangePPortVersion(PP_RTE_NVM_ECM, CreateVersionInfoFromI32(NVM_ECM_RTE_INTFVER));

    UpdatePPortSize   (PP_RTE_NVM_HLA,                                 sizeof(m_oRteNvmHla),                           FALSE);
    ChangePPortVersion(PP_RTE_NVM_HLA, CreateVersionInfoFromI32(NVM_HLAR_LEARNING_VALUES_INTFVER));

    UpdatePPortSize   (PP_RTE_NVM_TSA,                                 sizeof(m_oRteNvmTsa),                           FALSE);
    ChangePPortVersion(PP_RTE_NVM_TSA, CreateVersionInfoFromI32(TSA_RTE_NVM_STATE_INTFVER));

    UpdatePPortSize   (PP_RTE_NVM_SAC,                                 sizeof(m_oRteNvmSac),                           FALSE);
    ChangePPortVersion(PP_RTE_NVM_SAC, CreateVersionInfoFromI32(NVM_SAC_RTE_INTFVER));

    UpdatePPortSize   (PP_RTE_NVM_EMO,                                 sizeof(m_oRteNvmEmo),                           FALSE);
    ChangePPortVersion(PP_RTE_NVM_EMO, CreateVersionInfoFromI32(NVM_EMO_INTFVER));

    //CPAR Signals
    UpdatePPortSize   (PP_RTE_CPAR_ALDW,                               sizeof(m_oRteCparAldw),                         FALSE);
    ChangePPortVersion(PP_RTE_CPAR_ALDW, CreateVersionInfoFromI32(CPAR_FCT_PARAMETERS_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_HLAF,                               sizeof(m_oRteCparHlaF),                         FALSE);
    ChangePPortVersion(PP_RTE_CPAR_HLAF, CreateVersionInfoFromI32(CPAR_HLAF_PARAMETER_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_HLAR,                               sizeof(m_oRteCparHlaR),                         FALSE);
    ChangePPortVersion(PP_RTE_CPAR_HLAR, CreateVersionInfoFromI32(CPAR_HLAR_PARAMETER_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_HLA,                                sizeof(m_oRteCparHla),                          FALSE);
    ChangePPortVersion(PP_RTE_CPAR_HLA, CreateVersionInfoFromI32(CPAR_HLA_PARAMETER_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_SR,                                 sizeof(m_oRteCparSr),                           FALSE);
    ChangePPortVersion(PP_RTE_CPAR_SR, CreateVersionInfoFromI32(SR_RTE_CODING_PARAMS_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_SAC,                                sizeof(m_oRteCparSac),                          FALSE);
    ChangePPortVersion(PP_RTE_CPAR_SAC, CreateVersionInfoFromI32(CPAR_SAC_RTE_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_TSA,                                sizeof(m_oRteCparTsa),                          FALSE);
    ChangePPortVersion(PP_RTE_CPAR_TSA, CreateVersionInfoFromI32(TSA_RTE_CODING_PARAMS_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_ECM,                                sizeof(m_oRteCparEcm),                          FALSE);
    ChangePPortVersion(PP_RTE_CPAR_ECM, CreateVersionInfoFromI32(CPAR_ECM_RTE_INTFVER));

    UpdatePPortSize   (PP_RTE_CPAR_EMO,                                sizeof(m_oRteCparEmo),                          FALSE);
    ChangePPortVersion(PP_RTE_CPAR_EMO, CreateVersionInfoFromI32(CPAR_EMO_INTFVER));

    //FLSP Signals
    UpdatePPortSize   (PP_RTE_FLSP_IMAGER_CHAR_LEFT,                   sizeof(m_oRteFlspImagerCharRight),              FALSE);
    ChangePPortVersion(PP_RTE_FLSP_IMAGER_CHAR_LEFT, CreateVersionInfoFromI32(FLSP_IMAGER_CHAR_LEFT_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT,          sizeof(m_oRteFlspProductionIntrinsicLeft),      FALSE);
    ChangePPortVersion(PP_RTE_FLSP_PRODUCTION_INTRINSIC_LEFT, CreateVersionInfoFromI32(FLSP_PROD_INTR_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT,          sizeof(m_oRteFlspStereoCallIntrinsicsLeft),     FALSE);
    ChangePPortVersion(PP_RTE_FLSP_STEREO_CAL_INTRINSIC_LEFT, CreateVersionInfoFromI32(FLSP_STEREO_CAL_INTR_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT,         sizeof(m_oRteFlspStereoCallIntrinsicsRight),    FALSE);
    ChangePPortVersion(PP_RTE_FLSP_STEREO_CAL_INTRINSIC_RIGHT, CreateVersionInfoFromI32(FLSP_STEREO_CAL_INTR_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_STEREO_CAL_TRANS_ROT,               sizeof(m_oRteFlspStereoCalTransRot),            FALSE);
    ChangePPortVersion(PP_RTE_FLSP_STEREO_CAL_TRANS_ROT, CreateVersionInfoFromI32(FLSP_STEREO_CAL_TRAN_ROT_INTFVER));

    UpdatePPortSize   (PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST,  sizeof(m_oRteFlspTemperatureCompensationList),  FALSE);
    ChangePPortVersion(PP_RTE_FLSP_CAL_TEMPERATURE_COMPENSATION_LIST, CreateVersionInfoFromI32(FLSP_TEMP_COMP_INTFVER));

    //Dynamic Signals
    UpdatePPortSize   (PP_RTE_ICIC_EVEN_RIGHT,           sizeof(m_oRteIcIcEvenRight),       FALSE);
    ChangePPortVersion(PP_RTE_ICIC_EVEN_RIGHT, CreateVersionInfoFromI32(IC_IMAGE_CHARACTERISTICS_INTFVER));

    UpdatePPortSize   (PP_RTE_IC_IMAGE_STATISTIC_EVEN,                 sizeof(m_oRteIcImageStatisticEven),             FALSE);
    ChangePPortVersion(PP_RTE_IC_IMAGE_STATISTIC_EVEN, CreateVersionInfoFromI32(IC_IMAGE_STATISTIC_INTFVER));

    UpdatePPortSize   (PP_RTE_FCT_ALDW_INPUT_GEN,                      sizeof(m_oRteFCTAldwInputGen),                  FALSE);
    ChangePPortVersion(PP_RTE_FCT_ALDW_INPUT_GEN, CreateVersionInfoFromI32(FCT_LKA_INPUT_GENERIC_INTFVER)); /// ????? Correct InterfaceVersion

    UpdatePPortSize   (PP_RTE_DIM_INPUT_CUSTOM,                        sizeof(m_oRteDIMInputCustom),                   FALSE);
    ChangePPortVersion(PP_RTE_DIM_INPUT_CUSTOM, CreateVersionInfoFromI32(FCT_DIM_INPUT_CUSTOM_INTFVER));

    UpdatePPortSize   (PP_RTE_DIM_INPUT_GENERIC,                       sizeof(m_oRteDIMInputGeneric),                  FALSE);
    ChangePPortVersion(PP_RTE_DIM_INPUT_GENERIC, CreateVersionInfoFromI32(FCT_DIM_INPUT_GENERIC_INTFVER));

    UpdatePPortSize   (PP_RTE_HEAD_INPUT_CUSTOM,                       sizeof(m_oRteHEADInputCustom),                  FALSE);
    ChangePPortVersion(PP_RTE_HEAD_INPUT_CUSTOM, CreateVersionInfoFromI32(FCT_HEAD_INPUT_CUSTOM_INTFVER));

    UpdatePPortSize   (PP_RTE_HEAD_INPUT_GENERIC,                      sizeof(m_oRteHEADInputGeneric),                 FALSE);
    ChangePPortVersion(PP_RTE_HEAD_INPUT_GENERIC, CreateVersionInfoFromI32(FCT_HEAD_INPUT_GENERIC_INTFVER));

    UpdatePPortSize   (PP_RTE_HMI_INPUT_DATA,                          sizeof(m_oRteHMIInputData),                     FALSE);
    ChangePPortVersion(PP_RTE_HMI_INPUT_DATA, CreateVersionInfoFromI32(HMI_INPUT_DATA));

    UpdatePPortSize   (PP_RTE_TSA_GPS,                                 sizeof(m_oRteTsaInputGPS),                      FALSE);
    ChangePPortVersion(PP_RTE_TSA_GPS, CreateVersionInfoFromI32(RTE_INPUT_GPS_INTFVER));

    UpdatePPortSize   (PP_RTE_TSA_CUSTOM_INPUT,                        sizeof(m_oRteTsaCustomInput),                   FALSE);
    ChangePPortVersion(PP_RTE_TSA_CUSTOM_INPUT, CreateVersionInfoFromI32(TSA_RTE_CUSTOM_INPUT_INTFVER));

    UpdatePPortSize   (PP_RTE_ECU_STATE_M3,                            sizeof(m_oRteEcuStateM3_0),                     FALSE);
    ChangePPortVersion(PP_RTE_ECU_STATE_M3, CreateVersionInfoFromI32(ECU_STATE_INTFVER));

    UpdatePPortSize   (PP_RTE_SAC_STEREO_ROI_M3,                       sizeof(m_oRteSacStereoRoiM3_10),                FALSE);
    ChangePPortVersion(PP_RTE_SAC_STEREO_ROI_M3, CreateVersionInfoFromI32(SAC_RTE_STEREO_ROI_INPUT_INTFVER));
}

template <typename T>
void CSimMfcWrapper::CopyDataToProvidePort(std::vector<uint8> &providePort, const T &data)
{
  size_t dataSize = sizeof(data);
  if(providePort.size() != dataSize)
  {
    providePort.resize(dataSize);
  }
  memcpy(&providePort[0], &data, dataSize);
}

CVersionInfoImpl CSimMfcWrapper::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

// Meas freeze method for sim data
void CSimMfcWrapper::MeasFreezeSim (const uint32 _vaddr, const void* _addr, const uint32 _size)
{
  if(_addr != NULL)
  {
    MEASInfo_t desc;

    desc.VirtualAddress = _vaddr;
    desc.Length         = _size;
    desc.FuncID         = 0;
    desc.FuncChannelID  = static_cast<uint8>(TASK_ID_GIA);

    (void) MTSMeas(&desc, (void *)_addr, NULL);
  }
}

MEASReturn_t CSimMfcWrapper::MTSMeas(const MEASInfo_t *pInfo, void *pData, MEAS_Callback_t Callback)
{
  // Algorithm specific parameter translation
  SIMMEASInfo_t SimInfo;

  SimInfo.VirtualAddress = pInfo->VirtualAddress;
  SimInfo.Length         = pInfo->Length;
  SimInfo.FuncID         = pInfo->FuncID;
  SimInfo.FuncChannelID  = pInfo->FuncChannelID;
  // pass on to CPP code:
  return static_cast<MEASReturn_t>( MEASFreezeDataMTS (&SimInfo, pData, Callback));
  return MEAS_OK;
}