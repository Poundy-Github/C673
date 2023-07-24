
#include "gia_measfreeze_data.h"


#ifdef CB_CPAR_INTFVER
typedef CB_t_CPAR_Parameters_t        PDOCB_t_CPAR_Parameters_t; /*!< @vaddr:CB_MEAS_ID_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:pCB_t_CPAR_Parameters*/
#endif

#ifdef CPAR_ECM_RTE_INTFVER
typedef CPAR_EcmRte_t                 PDOCPAR_EcmRte_t; /*!< @vaddr:ECM_RTE_MEAS_ID_IN_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:pCparEcmRte*/
#endif

#ifdef BSW_VEH_PAR_INTFVER
typedef VehPar_t                      PDOVehPar_t;      /*!< @vaddr:VDY_MEAS_ID_VEH_PAR_GIA @cycleid:IPC_SIA_ENV @vname:VehPar*/
#endif

typedef VehSig_t                      PDOVehSig_t;      /*!< @vaddr:VDY_MEAS_ID_VEH_SIG_GIA @cycleid:IPC_SIA_ENV @vname:VehSig*/

#ifdef CPAR_HLAF_PARAMETER_INTFVER
typedef CPAR_HLAF_Parameter_t         PDOCPAR_HLAF_Parameter_t;  /*!< @vaddr:HLA_MEAS_VADDR_REQ_PORT_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:pCpar_HlafPar*/
#endif

#ifdef LSD_CPAR_INTFVER
typedef CPAR_LSD_t                    PDOCPAR_LSD_t;    /*!< @vaddr:LSD_MEAS_VADDR_REQ_PORT_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:pCParLsd*/
#endif

#ifdef CPAR_EMO_INTFVER
typedef CPAR_Emo_t                    PDOCPAR_Emo_t;    /*!< @vaddr:EMO_MEAS_ID_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:CPAR_Emo*/
#endif

#ifdef SR_RTE_CODING_PARAMS_INTFVER
typedef CPAR_SR_RTE_parameters_t      PDOCPAR_SR_RTE_parameters_t; /*!< @vaddr:SR_RTE_MEAS_ID_CODING_PARAMS_GIA @cycleid:IPC_SIA_ENV @vname:SrRteCodingParams*/
#endif

#ifdef CPAR_TLR_PARAMETERS_INTFVER
typedef CPAR_TLR_Parameters_t         PDOCPAR_TLR_Parameters_t;    /*!< @vaddr:TLR_MEAS_ID_TLR_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:pCParTlrParameters*/
#endif

#ifdef  CPAR_UDW_PARAMETERS_INTFVER
typedef CPAR_UDW_Parameters_t         PDOCPAR_UDW_Parameters_t;    /*!< @vaddr:RTE_UDW_MEAS_VADDR_CPAR_GIA @cycleid:IPC_SIA_ENV @vname:pCparUdwParameters*/
#endif

#ifdef LCF_TUN_PAR_LDP_INTFVER
typedef LCF_TunParamsLDP_t            PDOLCF_TunParamsLDP_t;      /*!< @vaddr:LCF_MEAS_ID_TUN_LDP_GIA @cycleid:IPC_SIA_ENV @vname:pCParLdp*/
#endif

#ifdef LCF_TUN_PAR_LKA_INTFVER
typedef LCF_TunParamsLKA_t            PDOLCF_TunParamsLKA_t;      /*!< @vaddr:LCF_MEAS_ID_TUN_LKA_GIA @cycleid:IPC_SIA_ENV @vname:pCParLka*/
#endif

#ifdef LCF_TUN_PAR_KMC_INTFVER
typedef LCF_TunParamsKMC_t            PDOLCF_TunParamsKMC_t;      /*!< @vaddr:LCF_MEAS_ID_TUN_KMC_GIA @cycleid:IPC_SIA_ENV @vname:pCParKmc*/
#endif

#ifdef LCF_TUN_PAR_DMC_INTFVER
typedef LCF_TunParamsDMC_t            PDOLCF_TunParamsDMC_t;      /*!< @vaddr:LCF_MEAS_ID_TUN_DMC_GIA @cycleid:IPC_SIA_ENV @vname:pCParDmc*/
#endif

#ifdef HLA_BUS_INPUT_SIGNALS_INTFVER
typedef HLA_BusInputSignals_t         PDOHLA_BusInputSignals_t;   /*!< @vaddr:HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS_GIA @cycleid:IPC_SIA_ENV @vname:pHlaBusInputSignals*/
#endif

#ifdef UDW_INPUT_GENERIC_INTFVER
typedef UDWInputGeneric_t             PDOUDWInputGeneric_t; /*!< @vaddr:RTE_UDW_MEAS_VADDR_INPUT_GENERIC_GIA @cycleid:IPC_SIA_ENV @vname:pUdwInputGeneric*/
#endif

// not in rte clarify with Abdullah
#ifdef RTE_HLA_SIGNALS_INTFVER
typedef RTE_HLA_Signals_t             PDORTE_HLA_Signals_t;
#endif

#ifdef UDW_INPUT_CUSTOM_INTFVER
typedef UDWInputCustom_t              PDOUDWInputCustom_t; /*!< @vaddr:RTE_UDW_MEAS_VADDR_INPUT_CUSTOM_GIA @cycleid:IPC_SIA_ENV @vname:pUdwInputCustom*/
#endif

#ifdef MAP_RTE_INPUT_INTFVER
typedef MapRteInput_t                 PDOMapRteInput_t; /*!< @vaddr:MAP_MEAS_ID_RTE_INPUT_DATA_GIA @cycleid:IPC_SIA_ENV @vname:pMapRteInput*/
#endif

#ifdef LD_ONLINE_CALI_DATA_INTFVER
typedef NVM_LdOnlineCaliData_t        PDONVM_LdOnlineCaliData_t; /*!< @vaddr:LD_MEAS_ID_ONLINE_CALI_DATA_GIA @cycleid:IPC_SIA_ENV @vname:pNvmLDOnlineCaliData*/ 
#endif

#ifdef LSD_NVM_INTFVER
typedef NVM_LSD_t PDONVM_LSD_t; /*!< @vaddr:LSD_MEAS_VADDR_PRO_PORT_NVM_GIA @cycleid:IPC_SIA_ENV @vname:pNvmLsd*/  
#endif

#ifdef TSA_RTE_NVM_STATE_INTFVER
typedef NvmTsaRteState_t PDONvmTsaRteState_t;  /*!< @vaddr:TSA_RTE_MEAS_ID_NVM_STATE_GIA @cycleid:IPC_SIA_ENV @vname:pNvmTsaRtePersState*/
#endif

#ifdef NVM_UDW_STATE_INTFVER
typedef NVM_UDW_State_t PDONVM_UDW_State_t;  /*!< @vaddr:RTE_UDW_MEAS_VADDR_NVM_O_GIA @cycleid:IPC_SIA_ENV @vname:pNvmUdwState*/ 
#endif

#ifdef MEMO_RTE_MEAS_ID_NVM_GIA
typedef NVM_Emo_t PDONVM_Emo_t; /*!< @vaddr:MEMO_RTE_MEAS_ID_NVM_GIA @cycleid:IPC_SIA_ENV @vname:pNvmEmo*/ 
#endif

#ifdef IC_ISP_CONTROL_INTFVER
typedef IcIspControl_t PDOIcIspControl_t; /*!< @vaddr:IC_MEAS_ID_ISP_CONTROL_GIA @cycleid:IPC_SIA_ENV @vname:IcIspControl*/ 
#endif

#ifdef IC_IMAGER_CONFIG_INTFVER
typedef IcImagerConfig_t PDOIcImagerConfig_t; /*!< @vaddr:IC_MEAS_ID_IMAGER_CONFIG_ODD_GIA @cycleid:IPC_SIA_ENV @vname:IcImagerConfigOdd*/ 
typedef IcImagerConfig_t PDOIcImagerConfig_tEven; /*!< @vaddr:IC_MEAS_ID_IMAGER_CONFIG_EVEN_GIA  @cycleid:IPC_SIA_ENV @vname:IcImagerConfigEven*/ 
#endif

#ifdef TSA_RTE_CODING_PARAMS_INTFVER
typedef CPAR_TSA_RTE_parameters_t PDOCPAR_TSA_RTE_parameters_t; /*!< @vaddr:TSA_RTE_MEAS_ID_CODING_PARAMS_GIA @cycleid:IPC_SIA_ENV @vname:TsaRteCodingParams*/ 
#endif

#ifdef TSA_RTE_INPUT_NAVIGATION_INTFVER
typedef TsaRteInputNavigation_t PDOTsaRteInputNavigation_t; /*!< @vaddr:TSA_RTE_MEAS_ID_INPUT_NAVIGATION_GIA @cycleid:IPC_SIA_ENV @vname:pTsaRteInputNavigation*/ 
#endif

#ifdef LCF_INPUT_INTFVER
typedef LCF_GenericInputs_t           PDOLCF_GenericInputs_t;    /*!< @vaddr:LCF_MEAS_ID_INPUT_GIA @cycleid:IPC_SIA_ENV @vname:LCF_GenericInputs*/
#endif

#ifdef LCF_IUC2SOC_INTFVER
typedef LCF_LaDmcIucToSoc_t           PDOLCF_LaDmcIucToSoc_t;    /*!< @vaddr:LCF_MEAS_ID_IUC2SOC_GIA @cycleid:IPC_SIA_ENV @vname:pLCFIuc2Soc*/
#endif

#ifdef CPAR_LD_INTFVER
typedef CPAR_Ld_t           PDOCPAR_Ld_t;    /*!< @vaddr:LD_MEAS_ID_CPAR_DATA_GIA @cycleid:IPC_SIA_ENV @vname:CParLD*/
#endif
void RumPDODummyForCompiler (void) {}

