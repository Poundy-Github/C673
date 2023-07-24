/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_CT_SA_BaseReceiveFunction_SMPC.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:48 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_H
# define _RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  include "Com.h"

/* Com.h Compatibility Check */
#  ifndef RTE_COM_VERSION
#   if defined (IL_VECTOR_VERSION)
#    define RTE_COM_VERSION 20u
#   else
#    if defined (IL_ASRCOM_VERSION)
#     if (IL_ASRCOM_VERSION < 0x0201u)
#      define RTE_COM_VERSION 20u
#     endif
#    endif
#   endif
#  endif
#  ifndef RTE_COM_VERSION
#   if ( COM_AR_MAJOR_VERSION == 2u ) && ( COM_AR_MINOR_VERSION == 0u )
#    define RTE_COM_VERSION 20u
#   else
#    if ( COM_AR_MAJOR_VERSION == 2u )  && ( COM_AR_MINOR_VERSION == 1u )
#     define RTE_COM_VERSION 21u
#    else
#     if ( COM_AR_MAJOR_VERSION == 3u )  && ( COM_AR_MINOR_VERSION == 0u )
#      define RTE_COM_VERSION 30u
#     endif
#    endif
#   endif
#  endif
#  ifndef RTE_COM_VERSION
#   error "Incompatible AUTOSAR COM version in Com.h. The MICROSAR RTE requires AUTOSAR COM 2.0, 2.1 or 3.0!"
#  endif

#  if defined(IL_VECTOR_VERSION) || defined(IL_ASRCOM_VERSION)
#   define RTE_USE_COM_TXSIGNAL_RDACCESS
#  endif


#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_R_ALDW_Md_Rq_ALDW_Md_Rq ((c03_ALDW_Md_Rq)7u)
#  define Rte_InitValue_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp ((c08_degC_m40_85_0k5)255u)
#  define Rte_InitValue_R_EBL_Stat_EBL_Stat ((c02_EBL_Stat)0u)
#  define Rte_InitValue_R_EBL_Sw_Psd_EBL_Sw_Psd ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_EngCoolTemp_EngCoolTemp ((c08_degC_m40_214_1)255u)
#  define Rte_InitValue_R_FogLmp_Ft_On_Rq_FogLmp_Ft_On_Rq ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_FogLmp_R_On_Rq_FogLmp_R_On_Rq ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_HVAC_Dfrst_Z1Z2_Actv_HVAC_Dfrst_Z1Z2_Actv ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_IHC_Md_Rq_IHC_Md_Rq ((c02_Off_On)3u)
#  define Rte_InitValue_R_IHC_Sys_Stat_IHC_Sys_Stat ((c02_IHC_Sys_Stat)3u)
#  define Rte_InitValue_R_MirrAdjSw_Lt_Psd_MirrAdjSw_xx_Psd ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_MirrAdjSw_Rt_Psd_MirrAdjSw_xx_Psd ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_MirrAdjSw_Stat_LHD_V2_MirrAdjSw_Stat_xxHD_V2 ((c02_MirrAdjSw_Stat)0u)
#  define Rte_InitValue_R_MirrAdjSw_Stat_RHD_V2_MirrAdjSw_Stat_xxHD_V2 ((c02_MirrAdjSw_Stat)0u)
#  define Rte_InitValue_R_Odo_Odo ((c24_km_0_999999k9_0k1)16777215u)
#  define Rte_InitValue_R_PMA_Md_Rq_PMA_Md_Rq ((c02_Md_Rq)3u)
#  define Rte_InitValue_R_RdLmp_FL_Actv_RdLmp_FL_Actv ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_RdLmp_FR_Actv_RdLmp_FR_Actv ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_RevGr_Engg_RevGr_Engg ((c02_Disengg_Engg)3u)
#  define Rte_InitValue_R_SLA_Md_Rq_SLA_Md_Rq ((c02_SLA_Md_Rq)3u)
#  define Rte_InitValue_R_SPC_Id_SPC_Id ((c03_SPC_Id)0u)
#  define Rte_InitValue_R_StW_Cond_Psd_StW_Cond_Psd ((c02_NPsd_Up_Down)0u)
#  define Rte_InitValue_R_StW_Lvr_Stat_StW_Lvr_Stat ((c03_StW_Lvr_Stat)0u)
#  define Rte_InitValue_R_StW_Sw00_Psd_V2_StW_Sw00_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw01_Psd_V2_StW_Sw01_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw02_Psd_V2_StW_Sw02_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw03_Psd_V2_StW_Sw03_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw04_Psd_V2_StW_Sw04_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw05_Psd_V2_StW_Sw05_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw06_Psd_V2_StW_Sw06_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw07_Psd_V2_StW_Sw07_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw08_Psd_V2_StW_Sw08_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw09_Psd_V2_StW_Sw09_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw10_Psd_V2_StW_Sw10_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw11_Psd_V2_StW_Sw11_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw12_Psd_V2_StW_Sw12_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw13_Psd_V2_StW_Sw13_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw14_Psd_V2_StW_Sw14_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_StW_Sw15_Psd_V2_StW_Sw15_Psd_V2 ((c02_NPsd_Psd_NDef)0u)
#  define Rte_InitValue_R_SuspLvlAdjSw_Psd_SuspLvlAdjSw_Psd ((c02_SuspLvlAdjSw_Psd)3u)
#  define Rte_InitValue_R_UnitVehSpd_UnitVehSpd ((c01_UnitVehSpd_IC)0u)
#  define Rte_InitValue_R_VehDrvProgSw_Psd_VehDrvProgSw_Psd ((c02_NPsd_NDefORDown_PsdORUp)3u)
#  define Rte_InitValue_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM ((c08_mm_m127_127_1)255u)
#  define Rte_InitValue_R_VehLvl_R_HLM_VehLvl_R_HLM ((c08_mm_m127_127_1)255u)
#  define Rte_InitValue_R_VehSpd_Disp_VehSpd_Disp ((c12_km_p_h_0_409k4_0k1)4095u)
#  define Rte_InitValue_R_WWA_Md_Rq_WWA_Md_Rq ((c02_Md_Rq)3u)
#  define Rte_InitValue_R_WprOutsdPkPosn_WprOutsdPkPosn ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_WprSw6Posn_MPM_WprSw6Posn_MPM ((c03_WprSw6Posn)0u)
#  define Rte_InitValue_R_WprWashSw_Psd_MPM_WprWashSw_Psd_MPM ((c02_WprSw_Stat)0u)
#  define Rte_InitValue_R_Wpr_Stat_Wpr_Stat ((c04_Steps_0_15_1_SNA_na)0u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_ALDW_Md_Rq_ALDW_Md_Rq(P2VAR(c03_ALDW_Md_Rq, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp(P2VAR(c08_degC_m40_85_0k5, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_BrkSys_Stat_BrkSys_Stat(P2VAR(REC_BrkSys_Stat_d7pccc3s00bjj322036sa5kif, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EVC_CfgBit_01_32_EVC_CfgBit_01_32(P2VAR(REC_EVC_CfgBit_01_32_580uwq34s0n14g39jbrwwepfe, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96(P2VAR(REC_EVC_CfgBit_65_96_580uwq34s0n14g39jbrwwepfe, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EVC_CfgList_01_0C_EVC_CfgList_01_0C(P2VAR(REC_EVC_CfgList_01_0C_evn08d6126fkfaksv87161o1j, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EngCoolTemp_EngCoolTemp(P2VAR(c08_degC_m40_214_1, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Eng_Rs3_Eng_Rs3(P2VAR(REC_Eng_Rs3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl(P2VAR(REC_Eng_Rs_EngCtrl_14lojwgkcazelrb438elf5h0j, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_FogLmp_Ft_On_Rq_FogLmp_Ft_On_Rq(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_GPS_Pos_Stat_GPS_Pos_Stat(P2VAR(REC_GPS_Pos_Stat_1wd2axd8vhko9tuswwmd68tp0, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_HiBm_Stat_HiBm_Stat(P2VAR(REC_HiBm_Stat_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_IHC_Md_Rq_IHC_Md_Rq(P2VAR(c02_Off_On, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_IHC_Sys_Stat_IHC_Sys_Stat(P2VAR(c02_IHC_Sys_Stat, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Ign_Stat_Ign_Stat(P2VAR(REC_Ign_Stat_5wz7lvfuvag9tw5a51baqfzdd, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Impact_Impact(P2VAR(REC_Impact_aa136in54vwmtfkfrrvvjwue, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDC_Disp_Rq_ESP_LDC_Disp_Rq_ESP(P2VAR(REC_LDC_Disp_Rq_ESP_1j00gxu3p5exa8awg915k1zy, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDC_Disp_Rq_RDU_LDC_Disp_Rq_RDU(P2VAR(REC_LDC_Disp_Rq_RDU_1j00gxu3p5exa8awg915k1zy, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDC_Rq_SCCM_LDC_Rq_SCCM(P2VAR(REC_LDC_Rq_SCCM_5ella88r9jsc72fnnq5iugtsl, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDP_Warn_Rq_LDP_Warn_Rq(P2VAR(REC_LDP_Warn_Rq_2is6fi0meeac78nkn35zc5ui3, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LgtSens_Stat_LgtSens_Stat(P2VAR(REC_LgtSens_Stat_9in9byg63c2fufil0n24ot5bf, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Stat_LHD_V2_MirrAdjSw_Stat_xxHD_V2(P2VAR(c02_MirrAdjSw_Stat, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Stat_RHD_V2_MirrAdjSw_Stat_xxHD_V2(P2VAR(c02_MirrAdjSw_Stat, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdj_Lt_Rq_MirrAdj_XX_Rq(P2VAR(REC_MirrAdj_XX_Rq_dv7hr5qpr6sv4leh8gdnnmvy2, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdj_Rt_Rq_MirrAdj_XX_Rq(P2VAR(REC_MirrAdj_XX_Rq_dv7hr5qpr6sv4leh8gdnnmvy2, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_NVP_Stat1_NVP_Stat1(P2VAR(REC_NVP_Stat1_18cj3r9lb95cc7w4q3mwqkn86, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Odo_Odo(P2VAR(c24_km_0_999999k9_0k1, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_PMA_Md_Rq_PMA_Md_Rq(P2VAR(c02_Md_Rq, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_PN14_SupBat_Stat_PN14_SupBat_Stat(P2VAR(REC_PN14_SupBat_Stat_icptf500osz37cvz00rql74g, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RDU_Gnrl_Stat_RDU_Gnrl_Stat(P2VAR(REC_RDU_Gnrl_Stat_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RdLmp_FL_Actv_RdLmp_FL_Actv(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RdLmp_FR_Actv_RdLmp_FR_Actv(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RevGr_Engg_RevGr_Engg(P2VAR(c02_Disengg_Engg, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SCCM_Lvr_Stat_SCCM_Lvr_Stat(P2VAR(REC_SCCM_Lvr_Stat_6v3sj55wsjghho72slblc9pby, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SLA_Md_Rq_SLA_Md_Rq(P2VAR(c02_SLA_Md_Rq, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SLA_SpdOffset_Rq_D_SLA_SpdOffset_Rq_D(P2VAR(REC_SLA_SpdOffset_Rq_D, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SPC_Id_SPC_Id(P2VAR(c03_SPC_Id, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_STA_Rs1_STA_Rs1(P2VAR(REC_STA_Rs1_b8u1rtjk1lcjd0w2lyxoy9rn2, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Cond_Psd_StW_Cond_Psd(P2VAR(c02_NPsd_Up_Down, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Lvr_Stat_StW_Lvr_Stat(P2VAR(c03_StW_Lvr_Stat, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw00_Psd_V2_StW_Sw00_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw01_Psd_V2_StW_Sw01_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw02_Psd_V2_StW_Sw02_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw03_Psd_V2_StW_Sw03_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw04_Psd_V2_StW_Sw04_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw05_Psd_V2_StW_Sw05_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw06_Psd_V2_StW_Sw06_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw07_Psd_V2_StW_Sw07_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw08_Psd_V2_StW_Sw08_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw09_Psd_V2_StW_Sw09_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw10_Psd_V2_StW_Sw10_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw11_Psd_V2_StW_Sw11_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw12_Psd_V2_StW_Sw12_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw13_Psd_V2_StW_Sw13_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw14_Psd_V2_StW_Sw14_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw15_Psd_V2_StW_Sw15_Psd_V2(P2VAR(c02_NPsd_Psd_NDef, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StWhl_Angl_Stat_StWhl_Angl_Stat(P2VAR(REC_StWhl_Angl_Stat_1lbtoaaebi5n2qvdq20f1phhd, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SuspLvlAdjSw_Psd_SuspLvlAdjSw_Psd(P2VAR(c02_SuspLvlAdjSw_Psd, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_TCM_Data2_TCM_Data2(P2VAR(REC_TCM_Data2_b8u1rtjk1lcjd0w2lyxoy9rn2, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_UnitVehSpd_UnitVehSpd(P2VAR(c01_UnitVehSpd_IC, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VIN_VIN(P2VAR(REC_VIN, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehDrvProgSw_Psd_VehDrvProgSw_Psd(P2VAR(c02_NPsd_NDefORDown_PsdORUp, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehDyn_EPKB_Stat_VehDyn_EPKB_Stat(P2VAR(REC_VehDyn_EPKB_Stat_1ae8w4ccn5pv3jukyqv8emy5n, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehDyn_SPCR_Stat_VehDyn_SPCR_Stat(P2VAR(REC_VehDyn_SPCR_Stat_5wz7lvfuvag9tw5a51baqfzdd, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM(P2VAR(c08_mm_m127_127_1, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehLvl_R_HLM_VehLvl_R_HLM(P2VAR(c08_mm_m127_127_1, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehLvl_Stat_VehLvl_Stat(P2VAR(REC_VehLvl_Stat, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehSpd_Disp_VehSpd_Disp(P2VAR(c12_km_p_h_0_409k4_0k1, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WWA_Md_Rq_WWA_Md_Rq(P2VAR(c02_Md_Rq, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Whl_Lt_Stat_Whl_Lt_Stat(P2VAR(REC_Whl_Lt_Stat, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Whl_Rt_Stat_Whl_Rt_Stat(P2VAR(REC_Whl_Rt_Stat_b8u1rtjk1lcjd0w2lyxoy9rn2, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprOutsdPkPosn_WprOutsdPkPosn(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprWashSw_Stat_WprWashSw_Stat(P2VAR(REC_WprWashSw_Stat_9t6sxiiysej7o2144of8lwc05, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Wpr_Stat_Wpr_Stat(P2VAR(c04_Steps_0_15_1_SNA_na, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_ALDW_Md_Rq_ALDW_Md_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_ALDW_Md_Rq_ALDW_Md_Rq
#  define Rte_Read_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp
#  define Rte_Read_R_BrkSys_Stat_BrkSys_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_BrkSys_Stat_BrkSys_Stat
#  define Rte_Read_R_EBL_Stat_EBL_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EBL_Stat_EBL_Stat
#  define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EBL_Stat_EBL_Stat(data) ((void)Com_ReceiveSignal(Com_EBL_Stat, (data)), RTE_E_OK)
#  define Rte_Read_R_EBL_Sw_Psd_EBL_Sw_Psd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EBL_Sw_Psd_EBL_Sw_Psd
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EBL_Sw_Psd_EBL_Sw_Psd(data) \
    ((void)Com_ReceiveSignal(Com_EBL_Sw_Psd, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EBL_Sw_Psd_EBL_Sw_Psd(data) ((void)Com_ReceiveSignal(Com_EBL_Sw_Psd, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_EVC_CfgBit_01_32_EVC_CfgBit_01_32 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EVC_CfgBit_01_32_EVC_CfgBit_01_32
#  define Rte_Read_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96
#  define Rte_Read_R_EVC_CfgList_01_0C_EVC_CfgList_01_0C Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EVC_CfgList_01_0C_EVC_CfgList_01_0C
#  define Rte_Read_R_EngCoolTemp_EngCoolTemp Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_EngCoolTemp_EngCoolTemp
#  define Rte_Read_R_Eng_Rs3_Eng_Rs3 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Eng_Rs3_Eng_Rs3
#  define Rte_Read_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl
#  define Rte_Read_R_FogLmp_Ft_On_Rq_FogLmp_Ft_On_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_FogLmp_Ft_On_Rq_FogLmp_Ft_On_Rq
#  define Rte_Read_R_FogLmp_R_On_Rq_FogLmp_R_On_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_FogLmp_R_On_Rq_FogLmp_R_On_Rq
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_FogLmp_R_On_Rq_FogLmp_R_On_Rq(data) \
    ((void)Com_ReceiveSignal(Com_FogLmp_R_On_Rq, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_FogLmp_R_On_Rq_FogLmp_R_On_Rq(data) ((void)Com_ReceiveSignal(Com_FogLmp_R_On_Rq, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_GPS_Pos_Stat_GPS_Pos_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_GPS_Pos_Stat_GPS_Pos_Stat
#  define Rte_Read_R_HVAC_Dfrst_Z1Z2_Actv_HVAC_Dfrst_Z1Z2_Actv Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_HVAC_Dfrst_Z1Z2_Actv_HVAC_Dfrst_Z1Z2_Actv
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_HVAC_Dfrst_Z1Z2_Actv_HVAC_Dfrst_Z1Z2_Actv(data) \
    ((void)Com_ReceiveSignal(Com_HVAC_Dfrst_Z1Z2_Actv, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_HVAC_Dfrst_Z1Z2_Actv_HVAC_Dfrst_Z1Z2_Actv(data) ((void)Com_ReceiveSignal(Com_HVAC_Dfrst_Z1Z2_Actv, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_HiBm_Stat_HiBm_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_HiBm_Stat_HiBm_Stat
#  define Rte_Read_R_IHC_Md_Rq_IHC_Md_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_IHC_Md_Rq_IHC_Md_Rq
#  define Rte_Read_R_IHC_Sys_Stat_IHC_Sys_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_IHC_Sys_Stat_IHC_Sys_Stat
#  define Rte_Read_R_Ign_Stat_Ign_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Ign_Stat_Ign_Stat
#  define Rte_Read_R_Impact_Impact Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Impact_Impact
#  define Rte_Read_R_LDC_Disp_Rq_ESP_LDC_Disp_Rq_ESP Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDC_Disp_Rq_ESP_LDC_Disp_Rq_ESP
#  define Rte_Read_R_LDC_Disp_Rq_RDU_LDC_Disp_Rq_RDU Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDC_Disp_Rq_RDU_LDC_Disp_Rq_RDU
#  define Rte_Read_R_LDC_Rq_SCCM_LDC_Rq_SCCM Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDC_Rq_SCCM_LDC_Rq_SCCM
#  define Rte_Read_R_LDP_Warn_Rq_LDP_Warn_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LDP_Warn_Rq_LDP_Warn_Rq
#  define Rte_Read_R_LgtSens_Stat_LgtSens_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_LgtSens_Stat_LgtSens_Stat
#  define Rte_Read_R_MirrAdjSw_Lt_Psd_MirrAdjSw_xx_Psd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Lt_Psd_MirrAdjSw_xx_Psd
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Lt_Psd_MirrAdjSw_xx_Psd(data) \
    ((void)Com_ReceiveSignal(Com_MirrAdjSw_Lt_Psd, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Lt_Psd_MirrAdjSw_xx_Psd(data) ((void)Com_ReceiveSignal(Com_MirrAdjSw_Lt_Psd, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_MirrAdjSw_Rt_Psd_MirrAdjSw_xx_Psd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Rt_Psd_MirrAdjSw_xx_Psd
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Rt_Psd_MirrAdjSw_xx_Psd(data) \
    ((void)Com_ReceiveSignal(Com_MirrAdjSw_Rt_Psd, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Rt_Psd_MirrAdjSw_xx_Psd(data) ((void)Com_ReceiveSignal(Com_MirrAdjSw_Rt_Psd, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_MirrAdjSw_Stat_LHD_V2_MirrAdjSw_Stat_xxHD_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Stat_LHD_V2_MirrAdjSw_Stat_xxHD_V2
#  define Rte_Read_R_MirrAdjSw_Stat_RHD_V2_MirrAdjSw_Stat_xxHD_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdjSw_Stat_RHD_V2_MirrAdjSw_Stat_xxHD_V2
#  define Rte_Read_R_MirrAdj_Lt_Rq_MirrAdj_XX_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdj_Lt_Rq_MirrAdj_XX_Rq
#  define Rte_Read_R_MirrAdj_Rt_Rq_MirrAdj_XX_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_MirrAdj_Rt_Rq_MirrAdj_XX_Rq
#  define Rte_Read_R_NVP_Stat1_NVP_Stat1 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_NVP_Stat1_NVP_Stat1
#  define Rte_Read_R_Odo_Odo Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Odo_Odo
#  define Rte_Read_R_PMA_Md_Rq_PMA_Md_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_PMA_Md_Rq_PMA_Md_Rq
#  define Rte_Read_R_PN14_SupBat_Stat_PN14_SupBat_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_PN14_SupBat_Stat_PN14_SupBat_Stat
#  define Rte_Read_R_RDU_Gnrl_Stat_RDU_Gnrl_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RDU_Gnrl_Stat_RDU_Gnrl_Stat
#  define Rte_Read_R_RdLmp_FL_Actv_RdLmp_FL_Actv Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RdLmp_FL_Actv_RdLmp_FL_Actv
#  define Rte_Read_R_RdLmp_FR_Actv_RdLmp_FR_Actv Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RdLmp_FR_Actv_RdLmp_FR_Actv
#  define Rte_Read_R_RevGr_Engg_RevGr_Engg Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_RevGr_Engg_RevGr_Engg
#  define Rte_Read_R_SCCM_Lvr_Stat_SCCM_Lvr_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SCCM_Lvr_Stat_SCCM_Lvr_Stat
#  define Rte_Read_R_SLA_Md_Rq_SLA_Md_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SLA_Md_Rq_SLA_Md_Rq
#  define Rte_Read_R_SLA_SpdOffset_Rq_D_SLA_SpdOffset_Rq_D Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SLA_SpdOffset_Rq_D_SLA_SpdOffset_Rq_D
#  define Rte_Read_R_SPC_Id_SPC_Id Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SPC_Id_SPC_Id
#  define Rte_Read_R_STA_Rs1_STA_Rs1 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_STA_Rs1_STA_Rs1
#  define Rte_Read_R_StW_Cond_Psd_StW_Cond_Psd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Cond_Psd_StW_Cond_Psd
#  define Rte_Read_R_StW_Lvr_Stat_StW_Lvr_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Lvr_Stat_StW_Lvr_Stat
#  define Rte_Read_R_StW_Sw00_Psd_V2_StW_Sw00_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw00_Psd_V2_StW_Sw00_Psd_V2
#  define Rte_Read_R_StW_Sw01_Psd_V2_StW_Sw01_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw01_Psd_V2_StW_Sw01_Psd_V2
#  define Rte_Read_R_StW_Sw02_Psd_V2_StW_Sw02_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw02_Psd_V2_StW_Sw02_Psd_V2
#  define Rte_Read_R_StW_Sw03_Psd_V2_StW_Sw03_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw03_Psd_V2_StW_Sw03_Psd_V2
#  define Rte_Read_R_StW_Sw04_Psd_V2_StW_Sw04_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw04_Psd_V2_StW_Sw04_Psd_V2
#  define Rte_Read_R_StW_Sw05_Psd_V2_StW_Sw05_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw05_Psd_V2_StW_Sw05_Psd_V2
#  define Rte_Read_R_StW_Sw06_Psd_V2_StW_Sw06_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw06_Psd_V2_StW_Sw06_Psd_V2
#  define Rte_Read_R_StW_Sw07_Psd_V2_StW_Sw07_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw07_Psd_V2_StW_Sw07_Psd_V2
#  define Rte_Read_R_StW_Sw08_Psd_V2_StW_Sw08_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw08_Psd_V2_StW_Sw08_Psd_V2
#  define Rte_Read_R_StW_Sw09_Psd_V2_StW_Sw09_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw09_Psd_V2_StW_Sw09_Psd_V2
#  define Rte_Read_R_StW_Sw10_Psd_V2_StW_Sw10_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw10_Psd_V2_StW_Sw10_Psd_V2
#  define Rte_Read_R_StW_Sw11_Psd_V2_StW_Sw11_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw11_Psd_V2_StW_Sw11_Psd_V2
#  define Rte_Read_R_StW_Sw12_Psd_V2_StW_Sw12_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw12_Psd_V2_StW_Sw12_Psd_V2
#  define Rte_Read_R_StW_Sw13_Psd_V2_StW_Sw13_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw13_Psd_V2_StW_Sw13_Psd_V2
#  define Rte_Read_R_StW_Sw14_Psd_V2_StW_Sw14_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw14_Psd_V2_StW_Sw14_Psd_V2
#  define Rte_Read_R_StW_Sw15_Psd_V2_StW_Sw15_Psd_V2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StW_Sw15_Psd_V2_StW_Sw15_Psd_V2
#  define Rte_Read_R_StWhl_Angl_Stat_StWhl_Angl_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_StWhl_Angl_Stat_StWhl_Angl_Stat
#  define Rte_Read_R_SuspLvlAdjSw_Psd_SuspLvlAdjSw_Psd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_SuspLvlAdjSw_Psd_SuspLvlAdjSw_Psd
#  define Rte_Read_R_TCM_Data2_TCM_Data2 Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_TCM_Data2_TCM_Data2
#  define Rte_Read_R_UnitVehSpd_UnitVehSpd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_UnitVehSpd_UnitVehSpd
#  define Rte_Read_R_VIN_VIN Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VIN_VIN
#  define Rte_Read_R_VehDrvProgSw_Psd_VehDrvProgSw_Psd Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehDrvProgSw_Psd_VehDrvProgSw_Psd
#  define Rte_Read_R_VehDyn_EPKB_Stat_VehDyn_EPKB_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehDyn_EPKB_Stat_VehDyn_EPKB_Stat
#  define Rte_Read_R_VehDyn_SPCR_Stat_VehDyn_SPCR_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehDyn_SPCR_Stat_VehDyn_SPCR_Stat
#  define Rte_Read_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM
#  define Rte_Read_R_VehLvl_R_HLM_VehLvl_R_HLM Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehLvl_R_HLM_VehLvl_R_HLM
#  define Rte_Read_R_VehLvl_Stat_VehLvl_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehLvl_Stat_VehLvl_Stat
#  define Rte_Read_R_VehSpd_Disp_VehSpd_Disp Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_VehSpd_Disp_VehSpd_Disp
#  define Rte_Read_R_WWA_Md_Rq_WWA_Md_Rq Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WWA_Md_Rq_WWA_Md_Rq
#  define Rte_Read_R_Whl_Lt_Stat_Whl_Lt_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Whl_Lt_Stat_Whl_Lt_Stat
#  define Rte_Read_R_Whl_Rt_Stat_Whl_Rt_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Whl_Rt_Stat_Whl_Rt_Stat
#  define Rte_Read_R_WprOutsdPkPosn_WprOutsdPkPosn Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprOutsdPkPosn_WprOutsdPkPosn
#  define Rte_Read_R_WprSw6Posn_MPM_WprSw6Posn_MPM Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprSw6Posn_MPM_WprSw6Posn_MPM
#  define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprSw6Posn_MPM_WprSw6Posn_MPM(data) ((void)Com_ReceiveSignal(Com_WprSw6Posn_MPM, (data)), RTE_E_OK)
#  define Rte_Read_R_WprWashSw_Psd_MPM_WprWashSw_Psd_MPM Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprWashSw_Psd_MPM_WprWashSw_Psd_MPM
#  define Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprWashSw_Psd_MPM_WprWashSw_Psd_MPM(data) ((void)Com_ReceiveSignal(Com_WprWashSw_Psd_MPM, (data)), RTE_E_OK)
#  define Rte_Read_R_WprWashSw_Stat_WprWashSw_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_WprWashSw_Stat_WprWashSw_Stat
#  define Rte_Read_R_Wpr_Stat_Wpr_Stat Rte_Read_CT_SA_BaseReceiveFunction_SMPC_R_Wpr_Stat_Wpr_Stat


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_CODE) NORM_v_CommonRxFct(void);

# define RTE_STOP_SEC_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_BaseReceiveFunction_SMPC.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_H */
