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
 *          File:  Rte_Cbk.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:52 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  COM callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CBK_H
# define _RTE_CBK_H

# include "Com.h"

/* Com.h Compatibility Check */
# ifndef RTE_COM_VERSION
#  if defined (IL_VECTOR_VERSION)
#   define RTE_COM_VERSION 20u
#  else
#   if defined (IL_ASRCOM_VERSION)
#    if (IL_ASRCOM_VERSION < 0x0201u)
#     define RTE_COM_VERSION 20u
#    endif
#   endif
#  endif
# endif
# ifndef RTE_COM_VERSION
#  if ( COM_AR_MAJOR_VERSION == 2u ) && ( COM_AR_MINOR_VERSION == 0u )
#   define RTE_COM_VERSION 20u
#  else
#   if ( COM_AR_MAJOR_VERSION == 2u )  && ( COM_AR_MINOR_VERSION == 1u )
#    define RTE_COM_VERSION 21u
#   else
#    if ( COM_AR_MAJOR_VERSION == 3u )  && ( COM_AR_MINOR_VERSION == 0u )
#     define RTE_COM_VERSION 30u
#    endif
#   endif
#  endif
# endif
# ifndef RTE_COM_VERSION
#  error "Incompatible AUTOSAR COM version in Com.h. The MICROSAR RTE requires AUTOSAR COM 2.0, 2.1 or 3.0!"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_Prediction_MsgTyp2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_Prediction_MsgTyp3(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_Prediction_MsgTyp6(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_Prediction_MsgTyp7(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfLong_ProfTyp1(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfLong_ProfTyp16(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfLong_ProfTyp17(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfLong_ProfTyp2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfLong_ProfTyp31(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp1(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp16(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp3(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp31(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp4(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp5(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp6(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp7(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ADAS_ProfShort_ProfTyp8(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ALDW_Md_Rq(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ALDW_Sw_Md(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ALDW_VibMot_Avl(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_ALDW_VibMot_Stat(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_AirTemp_Outsd_Disp(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_DidA_ExtTest_Pres(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_EngCoolTemp(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_FogLmp_Ft_On_Rq(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_CuA_4ot7gl1b2a8iv8d0ivlc04l1f(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Meta_xdfqbwvp7a06rtz91wzwxkpo_6(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Posn_6dl6mtlhqvooa5gm66wtvx0eg(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Long_Latit_dlkq2a2reckxnrilkmyozsps8_2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Long_Longit_33yvp1rnusfvarcv96n5c9a7x_1(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Long_NPSL1_2gvtb9rhgpu472w4tupkrfxl4_16(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Long_NPSL2_3ywykfpq2ptyfh4yqg0pri00_17(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_CurvLn_b6b6eeree9i21zbrrqlhejadk_1(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_HeadChSp_etz9dbqzzs9lgw96hcpeurybk_8(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_LocDest_5pu3uvm2y1drrhr4lkt99eets_16(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_RoadAcc_bdh2rytv7906dpk1dk8wex7tr_5(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_RoadCon_793nnryl9v0kayid47gogxpti_6(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_RoutNum_4qpxg4j5pc275ylic03hx6gwg_2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_SlopeLn_7kbw7enmwkd9keqkf8oebcpft_4(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_SlopeSt_bzlnt7owjhpjpyukp30i73lxu_3(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Profile_Short_VarSpSign_eewrlhboryq7coj7w7zm6lgo0_7(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Segment_dr7h6xzyfq47p0h3x63f57y2j_2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_ADAS_Stub_eblzr42on3a6ojjes1xk3bwgt_3(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_BrkSys_Stat_7rfceua7pbic62ra7pndtdkai(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_DTQ_Ctrl_btv10ucoeacn8tlua3fadtf6k(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_DTQ_Obj_Pres_alniy08vkfwuvi1wd34kt18c0(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_Eng_Rs3_2ojctigdae4v6n7c1ikq3csti(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_Eng_Rs_EngCtrl_68m2wuys9wr5zisvltljdkams(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_GPS_Pos_Stat_p7bz33t3sb0qqx2kqgytcn1n(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_HiBm_Stat_eo35ake3n9r3uaenn5ar5m20i(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_IHC_Lgt_Stat_HLI_70a29b9hfagufcw78o416wkkl(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_Ign_Stat_9q60tj4xuav66mp4vjkxlr6ka(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_LDC_Disp_Rq_ESP_9l1ikbp5zkfmpw3flt7ouxfj2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_LDC_Rq_SCCM_cjztr8oa8rxdi2hcl25v2stps(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_LgtSens_Stat_9jywru9jucm8tmbc8v3kg44yf(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_NVP_Stat1_4gl7u6gho9i99pa8q3nnwpgrf(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_PN14_SupBat_Stat_aleu8fy7bsux9kh42xfztkzmi(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_Preview_VehAccel_65ax1dif1ns0zzeiig394lcrx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SCCM_Lvr_Stat_9t2rc9h9ygyrawp8441drwydb(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_SLA_SpdOffset_Rq_D_6s2tgjinxlxb4rqe2z9uvurkp(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_StWhl_Angl_Stat_8zetjy0ggotvdcw6nsam6eyuh(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_TCM_Data2_921ik6uz0xhdvok7ofbaha3n9(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_VIN_401s6nk38eqdoqdeo893qnj2y(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_VehDyn_EPKB_Stat_30hj7c0ws8d04s9te74a5rl5(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_VehDyn_SPCR_Stat_40kmdvam1ay48fygnq7trepbb(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_VehLvl_Stat_6fomhvh515ozzarvdpql1vzcb(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_Whl_Lt_Stat_aj7lmb10womrh7hy0341kzy3s(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_Whl_Rt_Stat_3phiil1al2s12if3arrkarg28(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Grp_WprWashSw_Stat_1qo89ry9v31tg4wwj4wrnou4r(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_IHC_GlareRdc_Stat(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_IHC_HL_LgtOut(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_IHC_Md_Rq(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_IHC_Sys_Stat(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_IL_F_Actv(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_IL_R_Actv(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MirrAdjSw_Stat_LHD_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_MirrAdjSw_Stat_RHD_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Odo(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_PMA_Md_Rq(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_PN14_TransMd_Stat(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_RdLmp_FL_Actv(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_RdLmp_FR_Actv(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_RevGr_Engg(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SLA_Md_Rq(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SPC_Id(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Cond_ALDW_Sup(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Cond_Psd(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Lvr_Stat(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw00_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw01_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw02_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw03_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw04_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw05_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw06_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw07_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw08_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw09_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw10_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw11_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw12_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw13_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw14_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_StW_Sw15_Psd_V2(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_SuspLvlAdjSw_Psd(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_UnitVehSpd(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_VehDrvProgSw_Psd(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_VehLvl_Ft_HLM(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_VehLvl_R_HLM(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_VehSpd_Disp(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_WWA_Md_Rq(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_WprOutsdPkPosn(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Com_Wpr_Stat(void);

/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_Md_Rq(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_Md_Rq(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_Sw_Md(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_Sw_Md(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_VibMot_Avl(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_VibMot_Avl(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_VibMot_Stat(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_ALDW_VibMot_Stat(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_AirTemp_Outsd_Disp(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_AirTemp_Outsd_Disp(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_DidA_ExtTest_Pres(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_DidA_ExtTest_Pres(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_EngCoolTemp(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_EngCoolTemp(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_FogLmp_Ft_On_Rq(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_FogLmp_Ft_On_Rq(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_BrkSys_Stat_7rfceua7pbic62ra7pndtdkai(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_BrkSys_Stat_7rfceua7pbic62ra7pndtdkai(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_DTQ_Ctrl_btv10ucoeacn8tlua3fadtf6k(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_DTQ_Ctrl_btv10ucoeacn8tlua3fadtf6k(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_DTQ_Obj_Pres_alniy08vkfwuvi1wd34kt18c0(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_DTQ_Obj_Pres_alniy08vkfwuvi1wd34kt18c0(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Eng_Rs3_2ojctigdae4v6n7c1ikq3csti(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Eng_Rs3_2ojctigdae4v6n7c1ikq3csti(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Eng_Rs_EngCtrl_68m2wuys9wr5zisvltljdkams(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Eng_Rs_EngCtrl_68m2wuys9wr5zisvltljdkams(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_GPS_Pos_Stat_p7bz33t3sb0qqx2kqgytcn1n(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_GPS_Pos_Stat_p7bz33t3sb0qqx2kqgytcn1n(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_HiBm_Stat_eo35ake3n9r3uaenn5ar5m20i(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_HiBm_Stat_eo35ake3n9r3uaenn5ar5m20i(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_IHC_Lgt_Stat_HLI_70a29b9hfagufcw78o416wkkl(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_IHC_Lgt_Stat_HLI_70a29b9hfagufcw78o416wkkl(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Ign_Stat_9q60tj4xuav66mp4vjkxlr6ka(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Ign_Stat_9q60tj4xuav66mp4vjkxlr6ka(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_LDC_Disp_Rq_ESP_9l1ikbp5zkfmpw3flt7ouxfj2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_LDC_Disp_Rq_ESP_9l1ikbp5zkfmpw3flt7ouxfj2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_LDC_Rq_SCCM_cjztr8oa8rxdi2hcl25v2stps(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_LDC_Rq_SCCM_cjztr8oa8rxdi2hcl25v2stps(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_LgtSens_Stat_9jywru9jucm8tmbc8v3kg44yf(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_LgtSens_Stat_9jywru9jucm8tmbc8v3kg44yf(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_NVP_Stat1_4gl7u6gho9i99pa8q3nnwpgrf(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_NVP_Stat1_4gl7u6gho9i99pa8q3nnwpgrf(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_PN14_SupBat_Stat_aleu8fy7bsux9kh42xfztkzmi(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_PN14_SupBat_Stat_aleu8fy7bsux9kh42xfztkzmi(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Preview_VehAccel_65ax1dif1ns0zzeiig394lcrx(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Preview_VehAccel_65ax1dif1ns0zzeiig394lcrx(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SCCM_Lvr_Stat_9t2rc9h9ygyrawp8441drwydb(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SCCM_Lvr_Stat_9t2rc9h9ygyrawp8441drwydb(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SLA_SpdOffset_Rq_D_6s2tgjinxlxb4rqe2z9uvurkp(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_SLA_SpdOffset_Rq_D_6s2tgjinxlxb4rqe2z9uvurkp(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_StWhl_Angl_Stat_8zetjy0ggotvdcw6nsam6eyuh(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_StWhl_Angl_Stat_8zetjy0ggotvdcw6nsam6eyuh(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_TCM_Data2_921ik6uz0xhdvok7ofbaha3n9(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_TCM_Data2_921ik6uz0xhdvok7ofbaha3n9(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_VehDyn_EPKB_Stat_30hj7c0ws8d04s9te74a5rl5(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_VehDyn_EPKB_Stat_30hj7c0ws8d04s9te74a5rl5(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_VehDyn_SPCR_Stat_40kmdvam1ay48fygnq7trepbb(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_VehDyn_SPCR_Stat_40kmdvam1ay48fygnq7trepbb(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_VehLvl_Stat_6fomhvh515ozzarvdpql1vzcb(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_VehLvl_Stat_6fomhvh515ozzarvdpql1vzcb(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Whl_Lt_Stat_aj7lmb10womrh7hy0341kzy3s(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Whl_Lt_Stat_aj7lmb10womrh7hy0341kzy3s(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Whl_Rt_Stat_3phiil1al2s12if3arrkarg28(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_Whl_Rt_Stat_3phiil1al2s12if3arrkarg28(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_WprWashSw_Stat_1qo89ry9v31tg4wwj4wrnou4r(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Grp_WprWashSw_Stat_1qo89ry9v31tg4wwj4wrnou4r(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_GlareRdc_Stat(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_GlareRdc_Stat(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_HL_LgtOut(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_HL_LgtOut(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_Md_Rq(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_Md_Rq(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_Sys_Stat(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IHC_Sys_Stat(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IL_F_Actv(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IL_F_Actv(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IL_R_Actv(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_IL_R_Actv(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MirrAdjSw_Stat_LHD_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MirrAdjSw_Stat_LHD_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MirrAdjSw_Stat_RHD_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_MirrAdjSw_Stat_RHD_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Odo(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Odo(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_PMA_Md_Rq(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_PMA_Md_Rq(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_PN14_TransMd_Stat(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_PN14_TransMd_Stat(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_RdLmp_FL_Actv(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_RdLmp_FL_Actv(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_RdLmp_FR_Actv(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_RdLmp_FR_Actv(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_RevGr_Engg(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_RevGr_Engg(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SLA_Md_Rq(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SLA_Md_Rq(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SPC_Id(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SPC_Id(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Cond_ALDW_Sup(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Cond_ALDW_Sup(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Cond_Psd(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Cond_Psd(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Lvr_Stat(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Lvr_Stat(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw00_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw00_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw01_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw01_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw02_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw02_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw03_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw03_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw04_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw04_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw05_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw05_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw06_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw06_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw07_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw07_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw08_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw08_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw09_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw09_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw10_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw10_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw11_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw11_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw12_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw12_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw13_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw13_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw14_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw14_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw15_Psd_V2(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_StW_Sw15_Psd_V2(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SuspLvlAdjSw_Psd(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_SuspLvlAdjSw_Psd(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_UnitVehSpd(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_UnitVehSpd(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehDrvProgSw_Psd(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehDrvProgSw_Psd(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehLvl_Ft_HLM(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehLvl_Ft_HLM(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehLvl_R_HLM(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehLvl_R_HLM(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehSpd_Disp(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_VehSpd_Disp(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_WWA_Md_Rq(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_WWA_Md_Rq(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_WprOutsdPkPosn(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_WprOutsdPkPosn(void);
# endif
# if RTE_COM_VERSION == 21u
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Wpr_Stat(uint8 error);
# else
FUNC(void, RTE_CODE) Rte_COMCbkTOut_Com_Wpr_Stat(void);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Rte_Cbk.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CBK_H */
