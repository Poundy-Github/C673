#ifndef gia_measfreeze_data_h__
#define gia_measfreeze_data_h__

#include "common_include.h"

#ifndef   GIA_MEAS_ID_SIA
  #define GIA_MEAS_ID_SIA	(000000001)
#endif


#ifndef   CB_MEAS_ID_CPAR_GIA
  #define CB_MEAS_ID_CPAR_GIA  GIA_MEAS_ID_SIA
#endif

#ifndef   ECM_RTE_MEAS_ID_IN_CPAR_GIA
  #define ECM_RTE_MEAS_ID_IN_CPAR_GIA  CB_MEAS_ID_CPAR_GIA+sizeof(LCF_GenericInputs_t)
#endif

#ifndef   VDY_MEAS_ID_VEH_PAR_GIA
#define VDY_MEAS_ID_VEH_PAR_GIA  ECM_RTE_MEAS_ID_IN_CPAR_GIA+sizeof(CPAR_EcmRte_t)
#endif

#ifndef   LSD_MEAS_VADDR_REQ_PORT_CPAR_GIA
#define LSD_MEAS_VADDR_REQ_PORT_CPAR_GIA  VDY_MEAS_ID_VEH_PAR_GIA+sizeof(VehPar_t)
#endif

#ifndef   TLR_MEAS_ID_TLR_CPAR_GIA
#define TLR_MEAS_ID_TLR_CPAR_GIA  LSD_MEAS_VADDR_REQ_PORT_CPAR_GIA+sizeof(CPAR_LSD_t)
#endif

#ifndef   RTE_UDW_MEAS_VADDR_CPAR_GIA
#define RTE_UDW_MEAS_VADDR_CPAR_GIA  TLR_MEAS_ID_TLR_CPAR_GIA+sizeof(CPAR_TLR_Parameters_t)
#endif

#ifndef   LCF_MEAS_ID_INPUT_GIA
#define LCF_MEAS_ID_INPUT_GIA  RTE_UDW_MEAS_VADDR_CPAR_GIA+sizeof(CPAR_UDW_Parameters_t)
#endif

#ifndef LCF_MEAS_ID_IUC2SOC_GIA
#define LCF_MEAS_ID_IUC2SOC_GIA LCF_MEAS_ID_INPUT_GIA + sizeof(LCF_GenericInputs_t)
#endif

#ifndef VDY_MEAS_ID_VEH_SIG_GIA
#define VDY_MEAS_ID_VEH_SIG_GIA LCF_MEAS_ID_IUC2SOC_GIA + sizeof(LCF_LaDmcIucToSoc_t)
#endif

#ifndef HLA_MEAS_VADDR_REQ_PORT_CPAR_GIA
#define HLA_MEAS_VADDR_REQ_PORT_CPAR_GIA VDY_MEAS_ID_VEH_SIG_GIA + sizeof(VehSig_t)
#endif

#ifndef RTE_HLA_MEAS_VADDR_HLAR_PAR_GIA
#define RTE_HLA_MEAS_VADDR_HLAR_PAR_GIA HLA_MEAS_VADDR_REQ_PORT_CPAR_GIA + sizeof(CPAR_HLAF_Parameter_t)
#endif

#ifndef EMO_MEAS_ID_CPAR_GIA 
#define EMO_MEAS_ID_CPAR_GIA RTE_HLA_MEAS_VADDR_HLAR_PAR_GIA
#endif

#ifndef SR_RTE_MEAS_ID_CODING_PARAMS_GIA
#ifdef CPAR_EMO_INTFVER
#define SR_RTE_MEAS_ID_CODING_PARAMS_GIA EMO_MEAS_ID_CPAR_GIA + sizeof(CPAR_Emo_t)
#else
#define SR_RTE_MEAS_ID_CODING_PARAMS_GIA EMO_MEAS_ID_CPAR_GIA
#endif
#endif

#ifndef LCF_MEAS_ID_TUN_LDP_GIA
#ifdef SR_RTE_CODING_PARAMS_INTFVER
#define LCF_MEAS_ID_TUN_LDP_GIA SR_RTE_MEAS_ID_CODING_PARAMS_GIA + sizeof(CPAR_SR_RTE_parameters_t)
#else
#define LCF_MEAS_ID_TUN_LDP_GIA SR_RTE_MEAS_ID_CODING_PARAMS_GIA
#endif
#endif

#ifndef LCF_MEAS_ID_TUN_LKA_GIA
#ifdef LCF_TUN_PAR_LDP_INTFVER
#define LCF_MEAS_ID_TUN_LKA_GIA LCF_MEAS_ID_TUN_LDP_GIA + sizeof(CPAR_LCF_TunParamsLDP_t) 
#else
#define LCF_MEAS_ID_TUN_LKA_GIA LCF_MEAS_ID_TUN_LDP_GIA
#endif
#endif

#ifndef LCF_MEAS_ID_TUN_KMC_GIA
#ifdef LCF_TUN_PAR_LKA_INTFVER
#define LCF_MEAS_ID_TUN_KMC_GIA LCF_MEAS_ID_TUN_LKA_GIA + sizeof(CPAR_LCF_TunParamsLKA_t) 
#else
#define LCF_MEAS_ID_TUN_KMC_GIA LCF_MEAS_ID_TUN_LKA_GIA
#endif
#endif

#ifndef LCF_MEAS_ID_TUN_DMC_GIA
#ifdef LCF_TUN_PAR_KMC_INTFVER
#define LCF_MEAS_ID_TUN_DMC_GIA LCF_MEAS_ID_TUN_KMC_GIA + sizeof(CPAR_LCF_TunParamsKMC_t) 
#else
#define LCF_MEAS_ID_TUN_DMC_GIA LCF_MEAS_ID_TUN_KMC_GIA
#endif
#endif

#ifndef HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS_GIA
#ifdef LCF_TUN_PAR_DMC_INTFVER
#define HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS_GIA LCF_MEAS_ID_TUN_DMC_GIA + sizeof(CPAR_LCF_TunParamsDMC_t)
#else
#define HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS_GIA LCF_MEAS_ID_TUN_DMC_GIA
#endif
#endif


#ifndef RTE_UDW_MEAS_VADDR_INPUT_GENERIC_GIA
#ifdef HLA_BUS_INPUT_SIGNALS_INTFVER
#define RTE_UDW_MEAS_VADDR_INPUT_GENERIC_GIA HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS_GIA + sizeof(HLA_BusInputSignals_t)
#else
#define RTE_UDW_MEAS_VADDR_INPUT_GENERIC_GIA HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS_GIA
#endif
#endif

#ifndef RTE_UDW_MEAS_VADDR_INPUT_CUSTOM_GIA
#ifdef UDW_INPUT_GENERIC_INTFVER
#define RTE_UDW_MEAS_VADDR_INPUT_CUSTOM_GIA RTE_UDW_MEAS_VADDR_INPUT_GENERIC_GIA + sizeof(UDWInputGeneric_t)
#else
#define RTE_UDW_MEAS_VADDR_INPUT_CUSTOM_GIA RTE_UDW_MEAS_VADDR_INPUT_GENERIC_GIA
#endif
#endif

#ifndef MAP_MEAS_ID_RTE_INPUT_DATA_GIA
#ifdef UDW_INPUT_CUSTOM_INTFVER
#define MAP_MEAS_ID_RTE_INPUT_DATA_GIA RTE_UDW_MEAS_VADDR_INPUT_CUSTOM_GIA + sizeof(UDWInputCustom_t)
#else
#define MAP_MEAS_ID_RTE_INPUT_DATA_GIA RTE_UDW_MEAS_VADDR_INPUT_CUSTOM_GIA
#endif
#endif


#ifndef LD_MEAS_ID_ONLINE_CALI_DATA_GIA
#ifdef MAP_RTE_INPUT_INTFVER
#define LD_MEAS_ID_ONLINE_CALI_DATA_GIA MAP_MEAS_ID_RTE_INPUT_DATA_GIA + sizeof(MapRteInput_t)
#else
#define LD_MEAS_ID_ONLINE_CALI_DATA_GIA MAP_MEAS_ID_RTE_INPUT_DATA_GIA
#endif
#endif


#ifndef LSD_MEAS_VADDR_PRO_PORT_NVM_GIA
#ifdef LD_ONLINE_CALI_DATA_INTFVER
#define LSD_MEAS_VADDR_PRO_PORT_NVM_GIA LD_MEAS_ID_ONLINE_CALI_DATA_GIA + sizeof(NVM_LdOnlineCaliData_t)
#else
#define LSD_MEAS_VADDR_PRO_PORT_NVM_GIA LD_MEAS_ID_ONLINE_CALI_DATA_GIA
#endif
#endif

#ifndef TSA_RTE_MEAS_ID_NVM_STATE_GIA
#ifdef LSD_NVM_INTFVER
#define TSA_RTE_MEAS_ID_NVM_STATE_GIA LSD_MEAS_VADDR_PRO_PORT_NVM_GIA + sizeof(NVM_LSD_t)
#else
#define TSA_RTE_MEAS_ID_NVM_STATE_GIA LSD_MEAS_VADDR_PRO_PORT_NVM_GIA
#endif
#endif

#ifndef RTE_UDW_MEAS_VADDR_NVM_O_GIA
#ifdef TSA_RTE_NVM_STATE_INTFVER
#define RTE_UDW_MEAS_VADDR_NVM_O_GIA TSA_RTE_MEAS_ID_NVM_STATE_GIA + sizeof(NvmTsaRteState_t)
#else
#define RTE_UDW_MEAS_VADDR_NVM_O_GIA TSA_RTE_MEAS_ID_NVM_STATE_GIA
#endif
#endif


#ifndef MEMO_RTE_MEAS_ID_NVM_GIA
#ifdef NVM_UDW_STATE_INTFVER
#define MEMO_RTE_MEAS_ID_NVM_GIA RTE_UDW_MEAS_VADDR_NVM_O_GIA + sizeof(NVM_UDW_State_t)
#else
#define MEMO_RTE_MEAS_ID_NVM_GIA RTE_UDW_MEAS_VADDR_NVM_O_GIA
#endif
#endif

#ifndef IC_MEAS_ID_ISP_CONTROL_GIA
#define IC_MEAS_ID_ISP_CONTROL_GIA MEMO_RTE_MEAS_ID_NVM_GIA + sizeof(NVM_Emo_t)
#endif


#ifndef TSA_RTE_MEAS_ID_INPUT_NAVIGATION_GIA
#ifdef IC_ISP_CONTROL_INTFVER
#define TSA_RTE_MEAS_ID_INPUT_NAVIGATION_GIA IC_MEAS_ID_ISP_CONTROL_GIA + sizeof(IcIspControl_t)
#else 
#define TSA_RTE_MEAS_ID_INPUT_NAVIGATION_GIA IC_MEAS_ID_ISP_CONTROL_GIA
#endif
#endif

#ifndef TSA_RTE_MEAS_ID_CODING_PARAMS_GIA
#ifdef TSA_RTE_INPUT_NAVIGATION_INTFVER
#define TSA_RTE_MEAS_ID_CODING_PARAMS_GIA TSA_RTE_MEAS_ID_INPUT_NAVIGATION_GIA + sizeof(TsaRteInputNavigation_t)
#else
#define TSA_RTE_MEAS_ID_CODING_PARAMS_GIA TSA_RTE_MEAS_ID_INPUT_NAVIGATION_GIA
#endif
#endif

#ifndef IC_MEAS_ID_IMAGER_CONFIG_ODD_GIA
#ifdef TSA_RTE_CODING_PARAMS_INTFVER
#define IC_MEAS_ID_IMAGER_CONFIG_ODD_GIA TSA_RTE_MEAS_ID_CODING_PARAMS_GIA +  sizeof(CPAR_TSA_RTE_parameters_t)
#else
#define IC_MEAS_ID_IMAGER_CONFIG_ODD_GIA TSA_RTE_MEAS_ID_CODING_PARAMS_GIA
#endif
#endif

#ifndef IC_MEAS_ID_IMAGER_CONFIG_EVEN_GIA
#ifdef IC_IMAGER_CONFIG_INTFVER
#define IC_MEAS_ID_IMAGER_CONFIG_EVEN_GIA IC_MEAS_ID_IMAGER_CONFIG_ODD_GIA + sizeof(IcImagerConfig_t)
#else
#define IC_MEAS_ID_IMAGER_CONFIG_EVEN_GIA IC_MEAS_ID_IMAGER_CONFIG_ODD_GIA
#endif
#endif

#ifndef LD_MEAS_ID_CPAR_DATA_GIA
#ifdef IC_IMAGER_CONFIG_INTFVER
#define LD_MEAS_ID_CPAR_DATA_GIA IC_MEAS_ID_IMAGER_CONFIG_EVEN_GIA + sizeof(IcImagerConfig_t)
#else
#define LD_MEAS_ID_CPAR_DATA_GIA IC_MEAS_ID_IMAGER_CONFIG_EVEN_GIA
#endif
#endif

#ifndef GIA_MEAS_ID_CROPPER
  #define GIA_MEAS_ID_CROPPER 809500704
#endif

#ifndef GIA_MEAS_ID_CROPPER_COMP_STATE
  #define GIA_MEAS_ID_CROPPER_COMP_STATE GIA_MEAS_ID_CROPPER
#endif

#ifndef GIA_MEAS_ID_CROPPER_IMAGE_ODD
  #define GIA_MEAS_ID_CROPPER_IMAGE_ODD GIA_MEAS_ID_CROPPER_COMP_STATE+sizeof(AlgoCompState_t)
#endif

#ifndef GIA_MEAS_ID_CROPPER_IMAGE_EVEN
  #define GIA_MEAS_ID_CROPPER_IMAGE_EVEN GIA_MEAS_ID_CROPPER_IMAGE_ODD+sizeof(ImageU16_t)
#endif

#ifndef GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_ODD
  #define GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_ODD GIA_MEAS_ID_CROPPER_IMAGE_EVEN+sizeof(ImageU16_t)
#endif

#ifndef GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_EVEN
  #define GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_EVEN GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_ODD+sizeof(IcImageCharacteristics_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER
  #define GIA_MEAS_ID_WRAPPER GIA_MEAS_ID_CROPPER_IMAGE_CHARACTERISTIC_EVEN+sizeof(IcImageCharacteristics_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMLDONLINECALIDATA
  #define GIA_MEAS_ID_WRAPPER_PNVMLDONLINECALIDATA GIA_MEAS_ID_WRAPPER
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMSRRTE
  #define GIA_MEAS_ID_WRAPPER_PNVMSRRTE 0
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMECMRTEIN
  #define GIA_MEAS_ID_WRAPPER_PNVMECMRTEIN GIA_MEAS_ID_WRAPPER_PNVMLDONLINECALIDATA+sizeof(NVM_LdOnlineCaliData_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMSIGLEARNINGVALUES
  #define GIA_MEAS_ID_WRAPPER_PNVMSIGLEARNINGVALUES GIA_MEAS_ID_WRAPPER_PNVMECMRTEIN+sizeof(NVM_EcmRte_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMTSARTEPERSSTATE
  #define GIA_MEAS_ID_WRAPPER_PNVMTSARTEPERSSTATE GIA_MEAS_ID_WRAPPER_PNVMSIGLEARNINGVALUES+sizeof(NVM_HLAR_LearningValues_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMSAC
  #define GIA_MEAS_ID_WRAPPER_PNVMSAC 0
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PNVMEMOREAD
  #define GIA_MEAS_ID_WRAPPER_PNVMEMOREAD GIA_MEAS_ID_WRAPPER_PNVMTSARTEPERSSTATE+sizeof(NvmTsaRteState_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARFCTPARAMETERS
  #define GIA_MEAS_ID_WRAPPER_PCPARFCTPARAMETERS GIA_MEAS_ID_WRAPPER_PNVMEMOREAD+sizeof(NVM_Emo_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARECMRTE
  #define GIA_MEAS_ID_WRAPPER_PCPARECMRTE GIA_MEAS_ID_WRAPPER_PCPARFCTPARAMETERS+sizeof(CPAR_ALDW_Parameters_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPAREMO
  #define GIA_MEAS_ID_WRAPPER_PCPAREMO GIA_MEAS_ID_WRAPPER_PCPARECMRTE+sizeof(CPAR_EcmRte_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARHLAFPAR
  #define GIA_MEAS_ID_WRAPPER_PCPARHLAFPAR GIA_MEAS_ID_WRAPPER_PCPAREMO+sizeof(CPAR_Emo_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARHLARPAR
  #define GIA_MEAS_ID_WRAPPER_PCPARHLARPAR GIA_MEAS_ID_WRAPPER_PCPARHLAFPAR+sizeof(CPAR_HLAF_Parameter_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARHLAPAR
  #define GIA_MEAS_ID_WRAPPER_PCPARHLAPAR GIA_MEAS_ID_WRAPPER_PCPARHLARPAR+sizeof(CPAR_HLAR_Parameter_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARSRRTEPARAMETERS
  #define GIA_MEAS_ID_WRAPPER_PCPARSRRTEPARAMETERS GIA_MEAS_ID_WRAPPER_PCPARHLAPAR+sizeof(CPAR_HLA_Parameter_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARSAC
  #define GIA_MEAS_ID_WRAPPER_PCPARSAC 0
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PCPARTSARTEPARAMETER
  #define GIA_MEAS_ID_WRAPPER_PCPARTSARTEPARAMETER GIA_MEAS_ID_WRAPPER_PCPARSRRTEPARAMETERS+sizeof(CPAR_SR_RTE_parameters_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONCROI
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONCROI GIA_MEAS_ID_WRAPPER_PCPARTSARTEPARAMETER+sizeof(CPAR_TSA_RTE_parameters_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSROI
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSROI GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONCROI+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSEMOCROI
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSEMOCROI GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSROI+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOCROI
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOCROI GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONSEMOCROI+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMORROI
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMORROI GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOCROI+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOIMAGER
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOIMAGER GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMORROI+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEOLRIGHT
  #define GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEOLRIGHT GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEMOIMAGER+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_STEREOCALIBRATION
  #define GIA_MEAS_ID_WRAPPER_STEREOCALIBRATION 0
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSLEFT
  #define GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSLEFT GIA_MEAS_ID_WRAPPER_MONOCALIBRATIONEOLRIGHT+sizeof(MonoCalibrationEol_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICLEFT
  #define GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICLEFT GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSLEFT+sizeof(FLSPImagerCharacteristicsLeft_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICRIGHT
  #define GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICRIGHT GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICLEFT+sizeof(FLSPProductionIntrinsic_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSLEFT
  #define GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSLEFT GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONINTRINSICRIGHT+sizeof(FLSPProductionIntrinsic_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSRIGHT
  #define GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSRIGHT GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSLEFT+sizeof(FLSPProductionIntrinsic_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALTRANSROT
  #define GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALTRANSROT GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALINTRINSICSRIGHT+sizeof(FLSPProductionIntrinsic_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPTEMPERATURECOMPENSATIONLIST
  #define GIA_MEAS_ID_WRAPPER_PFLSPTEMPERATURECOMPENSATIONLIST GIA_MEAS_ID_WRAPPER_PFLSPSTEREOCALTRANSROT+sizeof(FLSPStereoCalTransRot_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPCALINTRDISTRIGHT
  #define GIA_MEAS_ID_WRAPPER_PFLSPCALINTRDISTRIGHT GIA_MEAS_ID_WRAPPER_PFLSPTEMPERATURECOMPENSATIONLIST+sizeof(FLSPTemperatureCompensationList_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONDATA
  #define GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONDATA GIA_MEAS_ID_WRAPPER_PFLSPCALINTRDISTRIGHT+sizeof(FLSPCalIntrDistRight_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSRIGHT
  #define GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSRIGHT GIA_MEAS_ID_WRAPPER_PFLSPPRODUCTIONDATA+sizeof(FLSPProductionData_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PFLSPRESPONSECURVEPERIPHERY
  #define GIA_MEAS_ID_WRAPPER_PFLSPRESPONSECURVEPERIPHERY GIA_MEAS_ID_WRAPPER_PFLSPIMAGERCHARACTERISTICSRIGHT+sizeof(FLSPImagerCharacteristicsRight_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_ALGOCOMPSTATE
  #define GIA_MEAS_ID_WRAPPER_ALGOCOMPSTATE GIA_MEAS_ID_WRAPPER_PFLSPRESPONSECURVEPERIPHERY+sizeof(FLSPResponseCurvePeriphery_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PSIGHLASIG
  #define GIA_MEAS_ID_WRAPPER_PSIGHLASIG GIA_MEAS_ID_WRAPPER_ALGOCOMPSTATE+sizeof(AlgoCompState_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PHLAHEADLIGHTSTATE
  #define GIA_MEAS_ID_WRAPPER_PHLAHEADLIGHTSTATE GIA_MEAS_ID_WRAPPER_PSIGHLASIG+sizeof(RTE_HLA_Signals_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PSIGMONOCALIBRATIONLANEIMAGER
  #define GIA_MEAS_ID_WRAPPER_PSIGMONOCALIBRATIONLANEIMAGER GIA_MEAS_ID_WRAPPER_PHLAHEADLIGHTSTATE+sizeof(RTE_HLA_HeadlightState_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSEVENRIGHT
  #define GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSEVENRIGHT GIA_MEAS_ID_WRAPPER_PSIGMONOCALIBRATIONLANEIMAGER+sizeof(MonoCalibration_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSEVEN
  #define GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSEVEN GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSEVENRIGHT+sizeof(IcImageCharacteristics_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_FCTALDWINPUTGENERIC
  #define GIA_MEAS_ID_WRAPPER_FCTALDWINPUTGENERIC GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSEVEN+sizeof(IcStatisticalResults_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PDIMINPUTCUSTOM
  #define GIA_MEAS_ID_WRAPPER_PDIMINPUTCUSTOM GIA_MEAS_ID_WRAPPER_FCTALDWINPUTGENERIC+sizeof(FCTALDWInputGeneric_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PDIMINPUTGENERIC
  #define GIA_MEAS_ID_WRAPPER_PDIMINPUTGENERIC GIA_MEAS_ID_WRAPPER_PDIMINPUTCUSTOM+sizeof(DIMInputCustom_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PHEADINPUTCUSTOM
  #define GIA_MEAS_ID_WRAPPER_PHEADINPUTCUSTOM GIA_MEAS_ID_WRAPPER_PDIMINPUTGENERIC+sizeof(DIMInputGeneric_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PHEADINPUTGENERIC
  #define GIA_MEAS_ID_WRAPPER_PHEADINPUTGENERIC GIA_MEAS_ID_WRAPPER_PHEADINPUTCUSTOM+sizeof(HEADInputCustom_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PHMIDATA
  #define GIA_MEAS_ID_WRAPPER_PHMIDATA GIA_MEAS_ID_WRAPPER_PHEADINPUTGENERIC+sizeof(HEADInputGeneric_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PRTEINPUTGPS
  #define GIA_MEAS_ID_WRAPPER_PRTEINPUTGPS GIA_MEAS_ID_WRAPPER_PHMIDATA+sizeof(t_HMI_Data_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PTSARTECUSTOMINPUT
  #define GIA_MEAS_ID_WRAPPER_PTSARTECUSTOMINPUT GIA_MEAS_ID_WRAPPER_PRTEINPUTGPS+sizeof(RteInputGPS_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_ECUSTATET
  #define GIA_MEAS_ID_WRAPPER_ECUSTATET GIA_MEAS_ID_WRAPPER_PTSARTECUSTOMINPUT+sizeof(TsaRteCustomInput_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_SACRTESTEREOROIINPUT
  #define GIA_MEAS_ID_WRAPPER_SACRTESTEREOROIINPUT 0
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDRIGHT
  #define GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDRIGHT GIA_MEAS_ID_WRAPPER_ECUSTATET+sizeof(EcuState_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDLEFT
  #define GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDLEFT GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDRIGHT+sizeof(IcImageCharacteristics_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSODD
  #define GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSODD GIA_MEAS_ID_WRAPPER_PICIMAGECHARACTERISTICSODDLEFT+sizeof(IcImageCharacteristics_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PSACFEXCONTROLOUTPUT
  #define GIA_MEAS_ID_WRAPPER_PSACFEXCONTROLOUTPUT 0
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PVEHPAR
  #define GIA_MEAS_ID_WRAPPER_PVEHPAR GIA_MEAS_ID_WRAPPER_PICSTATISTICALRESULTSODD+sizeof(IcStatisticalResults_t)
#endif

#ifndef GIA_MEAS_ID_WRAPPER_PVEHSIG
  #define GIA_MEAS_ID_WRAPPER_PVEHSIG GIA_MEAS_ID_WRAPPER_PVEHPAR+sizeof(VehPar_t)
#endif

#ifndef TASK_ID_GIA
    #define TASK_ID_GIA        250U
#endif
#define GIA
#endif // gia_measfreeze_data_h__
