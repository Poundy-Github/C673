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
 *          File:  Components/Rte_CP_AP_DiagnosticsAppl.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:49 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CP_AP_DIAGNOSTICSAPPL_H
# define _RTE_CP_AP_DIAGNOSTICSAPPL_H

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
#  define Rte_InitValue_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat ((c03_ALDW_VibMot_Stat)7u)
#  define Rte_InitValue_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp ((c08_degC_m40_85_0k5)255u)
#  define Rte_InitValue_R_EngCoolTemp_EngCoolTemp ((c08_degC_m40_214_1)255u)
#  define Rte_InitValue_R_IHC_Md_Rq_IHC_Md_Rq ((c02_Off_On)3u)
#  define Rte_InitValue_R_Odo_Odo ((c24_km_0_999999k9_0k1)16777215u)
#  define Rte_InitValue_R_PMA_Md_Rq_PMA_Md_Rq ((c02_Md_Rq)3u)
#  define Rte_InitValue_R_RevGr_Engg_RevGr_Engg ((c02_Disengg_Engg)3u)
#  define Rte_InitValue_R_SLA_Md_Rq_SLA_Md_Rq ((c02_SLA_Md_Rq)3u)
#  define Rte_InitValue_R_SPC_Id_SPC_Id ((c03_SPC_Id)0u)
#  define Rte_InitValue_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM ((c08_mm_m127_127_1)255u)
#  define Rte_InitValue_R_VehLvl_R_HLM_VehLvl_R_HLM ((c08_mm_m127_127_1)255u)
#  define Rte_InitValue_R_WWA_Md_Rq_WWA_Md_Rq ((c02_Md_Rq)3u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_ALDW_Md_Rq_ALDW_Md_Rq(P2VAR(c03_ALDW_Md_Rq, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl(P2VAR(DC_BOOL, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat(P2VAR(c03_ALDW_VibMot_Stat, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp(P2VAR(c08_degC_m40_85_0k5, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96(P2VAR(REC_EVC_CfgBit_65_96_580uwq34s0n14g39jbrwwepfe, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_EngCoolTemp_EngCoolTemp(P2VAR(c08_degC_m40_214_1, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl(P2VAR(REC_Eng_Rs_EngCtrl_14lojwgkcazelrb438elf5h0j, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_HiBm_Stat_HiBm_Stat(P2VAR(REC_HiBm_Stat_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_Ign_Stat_Ign_Stat(P2VAR(REC_Ign_Stat_b0ko81o0x5jgvwtduf99gvzi0, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_LDP_Warn_Rq_LDP_Warn_Rq(P2VAR(REC_LDP_Warn_Rq, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_PN14_SupBat_Stat_PN14_SupBat_Stat(P2VAR(REC_PN14_SupBat_Stat_icptf500osz37cvz00rql74g, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_RevGr_Engg_RevGr_Engg(P2VAR(c02_Disengg_Engg, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_SCCM_Lvr_Stat_SCCM_Lvr_Stat(P2VAR(REC_SCCM_Lvr_Stat_6v3sj55wsjghho72slblc9pby, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_SPC_Id_SPC_Id(P2VAR(c03_SPC_Id, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_TCM_Data2_TCM_Data2(P2VAR(REC_TCM_Data2_b8u1rtjk1lcjd0w2lyxoy9rn2, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_VIN_VIN(P2VAR(REC_VIN, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM(P2VAR(c08_mm_m127_127_1, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_VehLvl_R_HLM_VehLvl_R_HLM(P2VAR(c08_mm_m127_127_1, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_VehLvl_Stat_VehLvl_Stat(P2VAR(REC_VehLvl_Stat, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_Whl_Lt_Stat_Whl_Lt_Stat(P2VAR(REC_Whl_Lt_Stat, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_DiagnosticsAppl_R_Whl_Rt_Stat_Whl_Rt_Stat(P2VAR(REC_Whl_Rt_Stat_b8u1rtjk1lcjd0w2lyxoy9rn2, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_ALDW_Md_Rq_ALDW_Md_Rq Rte_Read_CP_AP_DiagnosticsAppl_R_ALDW_Md_Rq_ALDW_Md_Rq
#  define Rte_Read_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl Rte_Read_CP_AP_DiagnosticsAppl_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl
#  define Rte_Read_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat
#  define Rte_Read_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp Rte_Read_CP_AP_DiagnosticsAppl_R_AirTemp_Outsd_Disp_AirTemp_Outsd_Disp
#  define Rte_Read_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96 Rte_Read_CP_AP_DiagnosticsAppl_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96
#  define Rte_Read_R_EngCoolTemp_EngCoolTemp Rte_Read_CP_AP_DiagnosticsAppl_R_EngCoolTemp_EngCoolTemp
#  define Rte_Read_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl Rte_Read_CP_AP_DiagnosticsAppl_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl
#  define Rte_Read_R_HiBm_Stat_HiBm_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_HiBm_Stat_HiBm_Stat
#  define Rte_Read_R_IHC_Md_Rq_IHC_Md_Rq Rte_Read_CP_AP_DiagnosticsAppl_R_IHC_Md_Rq_IHC_Md_Rq
#  define Rte_Read_CP_AP_DiagnosticsAppl_R_IHC_Md_Rq_IHC_Md_Rq(data) ((void)Com_ReceiveSignal(Com_IHC_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_Ign_Stat_Ign_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_Ign_Stat_Ign_Stat
#  define Rte_Read_R_LDP_Warn_Rq_LDP_Warn_Rq Rte_Read_CP_AP_DiagnosticsAppl_R_LDP_Warn_Rq_LDP_Warn_Rq
#  define Rte_Read_R_Odo_Odo Rte_Read_CP_AP_DiagnosticsAppl_R_Odo_Odo
#  define Rte_Read_CP_AP_DiagnosticsAppl_R_Odo_Odo(data) ((void)Com_ReceiveSignal(Com_Odo, (data)), RTE_E_OK)
#  define Rte_Read_R_PMA_Md_Rq_PMA_Md_Rq Rte_Read_CP_AP_DiagnosticsAppl_R_PMA_Md_Rq_PMA_Md_Rq
#  define Rte_Read_CP_AP_DiagnosticsAppl_R_PMA_Md_Rq_PMA_Md_Rq(data) ((void)Com_ReceiveSignal(Com_PMA_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_PN14_SupBat_Stat_PN14_SupBat_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_PN14_SupBat_Stat_PN14_SupBat_Stat
#  define Rte_Read_R_RevGr_Engg_RevGr_Engg Rte_Read_CP_AP_DiagnosticsAppl_R_RevGr_Engg_RevGr_Engg
#  define Rte_Read_R_SCCM_Lvr_Stat_SCCM_Lvr_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_SCCM_Lvr_Stat_SCCM_Lvr_Stat
#  define Rte_Read_R_SLA_Md_Rq_SLA_Md_Rq Rte_Read_CP_AP_DiagnosticsAppl_R_SLA_Md_Rq_SLA_Md_Rq
#  define Rte_Read_CP_AP_DiagnosticsAppl_R_SLA_Md_Rq_SLA_Md_Rq(data) ((void)Com_ReceiveSignal(Com_SLA_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_SPC_Id_SPC_Id Rte_Read_CP_AP_DiagnosticsAppl_R_SPC_Id_SPC_Id
#  define Rte_Read_R_TCM_Data2_TCM_Data2 Rte_Read_CP_AP_DiagnosticsAppl_R_TCM_Data2_TCM_Data2
#  define Rte_Read_R_VIN_VIN Rte_Read_CP_AP_DiagnosticsAppl_R_VIN_VIN
#  define Rte_Read_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM Rte_Read_CP_AP_DiagnosticsAppl_R_VehLvl_Ft_HLM_VehLvl_Ft_HLM
#  define Rte_Read_R_VehLvl_R_HLM_VehLvl_R_HLM Rte_Read_CP_AP_DiagnosticsAppl_R_VehLvl_R_HLM_VehLvl_R_HLM
#  define Rte_Read_R_VehLvl_Stat_VehLvl_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_VehLvl_Stat_VehLvl_Stat
#  define Rte_Read_R_WWA_Md_Rq_WWA_Md_Rq Rte_Read_CP_AP_DiagnosticsAppl_R_WWA_Md_Rq_WWA_Md_Rq
#  define Rte_Read_CP_AP_DiagnosticsAppl_R_WWA_Md_Rq_WWA_Md_Rq(data) ((void)Com_ReceiveSignal(Com_WWA_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_Whl_Lt_Stat_Whl_Lt_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_Whl_Lt_Stat_Whl_Lt_Stat
#  define Rte_Read_R_Whl_Rt_Stat_Whl_Rt_Stat Rte_Read_CP_AP_DiagnosticsAppl_R_Whl_Rt_Stat_Whl_Rt_Stat


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SessionCtrlType);
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DCMServices_GetSesCtrlType Dcm_GetSesCtrlType


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplComControlService_CheckCondition(UInt8 subNetId, UInt8 msgType, Boolean rxState, Boolean txState);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_WriteData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010c_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010c_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010c_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010d_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010d_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010d_ReadData(P2VAR(Dcm_33Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0210_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0210_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0210_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0212_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0212_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0212_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0213_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0213_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0213_ReadData(P2VAR(Dcm_62Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ReadData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_WriteData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0215_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0215_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0215_ReadData(P2VAR(Dcm_6Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ReadData(P2VAR(Dcm_15Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_WriteData(P2VAR(Dcm_15Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_WriteData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

//REMARK Andreas Gilch: Add manually
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ReadData(P2VAR(Dcm_42Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_WriteData(P2VAR(Dcm_42Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ReadData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_WriteData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_WriteData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_WriteData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ReadData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_WriteData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ReadData(P2VAR(Dcm_34Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_WriteData(P2VAR(Dcm_34Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0234_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0234_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0234_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ReadData(P2VAR(Dcm_76Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_WriteData(P2VAR(Dcm_76Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0290_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0290_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0290_ReadData(P2VAR(Dcm_11Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif


FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0291_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0291_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0291_ReadData(P2VAR(Dcm_11Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif



//REMARK Andreas Gilch: END of "Add manually"

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0236_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0236_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0236_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0238_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0238_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0238_ReadData(P2VAR(Dcm_38Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

/*Start of 0x240*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0240_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0240_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0240_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
/*End of 0x240*/

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0242_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0242_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0242_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

/* START manual code */
/* DID 0x0243 */

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ReadData(P2VAR(Dcm_67Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_WriteData(P2VAR(Dcm_67Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

/* DID 0x0244 */

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


/* END manual code */

/*Start of 0x245*/

/* DID 0x0245 */

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ReadData(P2VAR(Dcm_452Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_WriteData(P2VAR(Dcm_452Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

/*End of 0x245*/


/*Start of 0x246*/

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0246_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0246_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0246_ReadData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

/*End of 0x246*/


/* DID 0x0247 */

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

/*END DID 0x0247*/

/* DID 0x0248 */

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_WriteData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

/*END DID 0x0248*/

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ReadData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_WriteData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ReadData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_WriteData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ReadData(P2VAR(Dcm_57Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_WriteData(P2VAR(Dcm_57Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ReadData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_WriteData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ReadData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_WriteData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0280_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0280_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0280_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0281_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0281_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0281_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0282_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0282_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0282_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0283_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0283_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0283_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0284_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0284_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0284_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a0_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a0_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a0_ReadData(P2VAR(Dcm_26Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02b0_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02b0_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02b0_ReadData(P2VAR(Dcm_90Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ReadData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_WriteData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


/*Start of 0x02a2*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ReadData(P2VAR(Dcm_5Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_WriteData(P2VAR(Dcm_5Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02a2*/


/*Start of 0x02a3*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_WriteData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02a3*/


/*Start of 0x02a4*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a4_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a4_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a4_ReadData(P2VAR(Dcm_632Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
/*End of 0x02a4*/


/*Start of 0x02a5*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ReadData(P2VAR(Dcm_172Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_WriteData(P2VAR(Dcm_172Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02a5*/


/*Start of 0x02a6*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_WriteData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02a6*/


/*Start of 0x02a7*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a7_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a7_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a7_ReadData(P2VAR(Dcm_100Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
/*End of 0x02a7*/


/*Start of 0x02a8*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a8_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a8_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a8_ReadData(P2VAR(Dcm_100Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
/*End of 0x02a8*/

/*Start of 0x02a9*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02a9*/

/*Start of 0x02aa*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ReadData(P2VAR(Dcm_460Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_WriteData(P2VAR(Dcm_460Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02aa*/

/*Start of 0x02ab*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ab_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ab_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ab_ReadData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
/*End of 0x02a8*/

/*Start of 0x02ac*/
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
/*End of 0x02aa*/

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ReadData(P2VAR(Dcm_53Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_WriteData(P2VAR(Dcm_53Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ReadData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_WriteData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ReadData(P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_WriteData(P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ReadData(P2VAR(Dcm_26Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_WriteData(P2VAR(Dcm_26Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ReadData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_WriteData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ReturnControlToECU(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ReturnControlToECU(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ShortTermAdjustment(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ShortTermAdjustment(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

/* Andreas Gilch: Removed from cdd.
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef02_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef02_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef02_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
*/

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef03_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef03_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef03_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf100_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf100_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf100_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf10d_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf10d_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf10d_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf170_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf170_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf170_ReadData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf18c_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf18c_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf18c_ReadData(P2VAR(Dcm_13Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf195_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf195_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf195_ReadData(P2VAR(Dcm_60Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a2_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a2_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a2_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a3_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a3_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a3_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a5_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a5_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a5_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplPassiveModeService_CheckCondition(void);

FUNC(void, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplPassiveModeService_OnChange(Boolean passiveState);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplResetService_EcuReset(UInt8 resetType, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0201_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0201_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_62Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_Start(P2VAR(Dcm_13Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_62Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_Start(P2VAR(Dcm_21Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_110Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_Start(P2VAR(Dcm_21Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_42Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0305_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0305_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_60Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_Start(P2VAR(Dcm_36Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif


# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0310_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0310_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0312_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0312_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0320_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0320_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Stop(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0325_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0325_Start(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Stop(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Stop(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0333_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0333_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0334_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0334_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0340_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0340_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0341_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0341_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0342_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0342_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0350_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0350_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0352_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0352_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0354_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0354_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0355_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0355_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0356_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0356_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0357_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0357_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0360_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0360_Start(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_23Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0361_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0361_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0362_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0362_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0363_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0363_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0364_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0364_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0365_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0365_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0366_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0366_Start(P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_512Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0xff03_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0xff03_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_CompareKey(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Key);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_CompareKey(P2VAR(Dcm_SecAccess_1_KeyType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Key);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_GetSeed(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) securityAccessDataRecord, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_GetSeed(P2VAR(Dcm_SecAccess_1_DataRecType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) securityAccessDataRecord, P2VAR(Dcm_SecAccess_1_SeedType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSessionControl_ChangeIndication(Dcm_SesCtrlType SesCtrlTypeOld, Dcm_SesCtrlType SesCtrlTypeNew);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSessionControl_ConfirmationRespPending(Dcm_ConfirmationStatusType status);

FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSessionControl_GetSesChgPermission(Dcm_SesCtrlType SesCtrlTypeActive, Dcm_SesCtrlType SesCtrlTypeNew);

FUNC(void, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsAppl_VINassembler(void);

FUNC(void, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsAppl_CheckCaliEnvDataRange(void);

# define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComControlService_E_COM_CTRL_NOT_ACCEPTED (40u)

#  define RTE_E_ComControlService_E_PENDING (10u)

#  define RTE_E_DCMServices_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0102_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0102_E_PENDING (10u)

#  define RTE_E_DidServices_0x010c_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x010c_E_PENDING (10u)

#  define RTE_E_DidServices_0x010d_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x010d_E_PENDING (10u)

#  define RTE_E_DidServices_0x0210_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0210_E_PENDING (10u)

#  define RTE_E_DidServices_0x0212_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0212_E_PENDING (10u)

#  define RTE_E_DidServices_0x0213_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0213_E_PENDING (10u)

#  define RTE_E_DidServices_0x0214_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0214_E_PENDING (10u)

#  define RTE_E_DidServices_0x0215_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0215_E_PENDING (10u)

#  define RTE_E_DidServices_0x0216_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0216_E_PENDING (10u)

#  define RTE_E_DidServices_0x0217_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0217_E_PENDING (10u)

#  define RTE_E_DidServices_0x0236_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0236_E_PENDING (10u)

#  define RTE_E_DidServices_0x0238_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0238_E_PENDING (10u)

#  define RTE_E_DidServices_0x0242_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0242_E_PENDING (10u)

#  define RTE_E_DidServices_0x0260_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0260_E_PENDING (10u)

#  define RTE_E_DidServices_0x0261_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0261_E_PENDING (10u)

#  define RTE_E_DidServices_0x0262_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0262_E_PENDING (10u)

#  define RTE_E_DidServices_0x0263_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0263_E_PENDING (10u)

#  define RTE_E_DidServices_0x0266_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0266_E_PENDING (10u)

#  define RTE_E_DidServices_0x0271_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0271_E_PENDING (10u)

#  define RTE_E_DidServices_0x0272_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0272_E_PENDING (10u)

#  define RTE_E_DidServices_0x0273_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0273_E_PENDING (10u)

#  define RTE_E_DidServices_0x0280_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0280_E_PENDING (10u)

#  define RTE_E_DidServices_0x0281_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0281_E_PENDING (10u)

#  define RTE_E_DidServices_0x0282_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0282_E_PENDING (10u)

#  define RTE_E_DidServices_0x0283_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0283_E_PENDING (10u)

#  define RTE_E_DidServices_0x0284_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0284_E_PENDING (10u)

#  define RTE_E_DidServices_0x02a0_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x02a0_E_PENDING (10u)

#  define RTE_E_DidServices_0x02a1_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x02a1_E_PENDING (10u)

#  define RTE_E_DidServices_0x0380_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0380_E_PENDING (10u)

#  define RTE_E_DidServices_0x0381_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0381_E_PENDING (10u)

#  define RTE_E_DidServices_0x0382_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0382_E_PENDING (10u)

#  define RTE_E_DidServices_0x0383_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0383_E_PENDING (10u)

#  define RTE_E_DidServices_0x0384_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0384_E_PENDING (10u)

#  define RTE_E_DidServices_0xd000_E_PENDING (10u)

#  define RTE_E_DidServices_0xef02_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xef02_E_PENDING (10u)

#  define RTE_E_DidServices_0xef03_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xef03_E_PENDING (10u)

#  define RTE_E_DidServices_0xf100_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf100_E_PENDING (10u)

#  define RTE_E_DidServices_0xf10d_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf10d_E_PENDING (10u)

#  define RTE_E_DidServices_0xf170_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf170_E_PENDING (10u)

#  define RTE_E_DidServices_0xf18c_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf18c_E_PENDING (10u)

#  define RTE_E_DidServices_0xf195_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf195_E_PENDING (10u)

#  define RTE_E_DidServices_0xf1a2_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf1a2_E_PENDING (10u)

#  define RTE_E_DidServices_0xf1a3_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf1a3_E_PENDING (10u)

#  define RTE_E_DidServices_0xf1a5_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf1a5_E_PENDING (10u)

#  define RTE_E_PassiveMode_E_NOT_OK (1u)

#  define RTE_E_PassiveMode_E_PENDING (10u)

#  define RTE_E_ResetService_E_NOT_OK (1u)

#  define RTE_E_ResetService_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0201_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0300_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0301_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0303_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0304_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0310_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0321_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0325_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0330_E_PENDING (10u)

#  define RTE_E_RoutineServices_0xff03_E_PENDING (10u)

#  define RTE_E_SecurityAccess_1_E_COMPARE_KEY_FAILED (11u)

#  define RTE_E_SecurityAccess_1_E_NOT_OK (1u)

#  define RTE_E_SecurityAccess_1_E_PENDING (10u)

#  define RTE_E_SessionControl_E_FORCE_RCRRP (12u)

#  define RTE_E_SessionControl_E_NOT_OK (1u)

#  define RTE_E_SessionControl_E_PENDING (10u)

#  define RTE_E_SessionControl_E_SESSION_NOT_ALLOWED (4u)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CP_AP_DiagnosticsAppl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CP_AP_DIAGNOSTICSAPPL_H */
