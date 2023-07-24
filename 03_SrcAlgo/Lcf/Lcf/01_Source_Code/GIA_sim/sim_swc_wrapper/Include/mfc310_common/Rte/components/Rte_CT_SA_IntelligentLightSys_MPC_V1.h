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
 *          File:  Components/Rte_CT_SA_IntelligentLightSys_MPC_V1.h
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
#ifndef _RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_H
# define _RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_H

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

#  define Rte_InitValue_R_IHC_GlareRdc_Stat_IHC_GlareRdc_Stat ((c02_Inact_Act)3u)
#  define Rte_InitValue_R_IHC_HL_LgtOut_IHC_HL_LgtOut ((c04_W_32_38_0k5)15u)
#  define Rte_InitValue_R_IHC_Md_Rq_IHC_Md_Rq ((c02_Off_On)3u)
#  define Rte_InitValue_R_IHC_Sys_Stat_IHC_Sys_Stat ((c02_IHC_Sys_Stat)3u)
#  define Rte_InitValue_R_IL_F_Actv_IL_F_Actv ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_IL_R_Actv_IL_R_Actv ((DC_BOOL)FALSE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96(P2VAR(REC_EVC_CfgBit_65_96_93cqdgh4hhn5xns1hoko7garz, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_GlareRdc_Stat_IHC_GlareRdc_Stat(P2VAR(c02_Inact_Act, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_HL_LgtOut_IHC_HL_LgtOut(P2VAR(c04_W_32_38_0k5, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_Lgt_Stat_HLI_IHC_Lgt_Stat_HLI(P2VAR(REC_IHC_Lgt_Stat_HLI_2ahxpf4cam3pi2le1l2woky78, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IL_F_Actv_IL_F_Actv(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IL_R_Actv_IL_R_Actv(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_MirrAdj_Lt_Rq_MirrAdj_XX_Rq(P2VAR(REC_MirrAdj_XX_Rq_dv7hr5qpr6sv4leh8gdnnmvy2, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_MirrAdj_Rt_Rq_MirrAdj_XX_Rq(P2VAR(REC_MirrAdj_XX_Rq_dv7hr5qpr6sv4leh8gdnnmvy2, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_IHC_Lgt_Stat_MPC_IHC_Lgt_Stat_MPC(P2CONST(REC_IHC_Lgt_Stat_MPC_515fv9hxb5jrzmunrr9r72aqj, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_IHC_Plus_HL_Stat_IHC_Plus_HL_Stat(P2CONST(REC_IHC_Plus_HL_Stat_a2qglp2324znbwefnu92uartf, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA) data);
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_Meas_MPC_1_Meas_XX(P2CONST(c08_UInt_SNA_na, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_Meas_MPC_1_Meas_XX(P2CONST(ARR_08_UInt_noSNA_8, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA) data);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_Meas_MPC_2_Meas_XX(P2CONST(c08_UInt_SNA_na, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA) data);
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_Meas_MPC_2_Meas_XX(P2CONST(ARR_08_UInt_noSNA_8, AUTOMATIC, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA) data);
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96 Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_EVC_CfgBit_65_96_EVC_CfgBit_65_96
#  define Rte_Read_R_IHC_GlareRdc_Stat_IHC_GlareRdc_Stat Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_GlareRdc_Stat_IHC_GlareRdc_Stat
#  define Rte_Read_R_IHC_HL_LgtOut_IHC_HL_LgtOut Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_HL_LgtOut_IHC_HL_LgtOut
#  define Rte_Read_R_IHC_Lgt_Stat_HLI_IHC_Lgt_Stat_HLI Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_Lgt_Stat_HLI_IHC_Lgt_Stat_HLI
#  define Rte_Read_R_IHC_Md_Rq_IHC_Md_Rq Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_Md_Rq_IHC_Md_Rq
#  define Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_Md_Rq_IHC_Md_Rq(data) ((void)Com_ReceiveSignal(Com_IHC_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_IHC_Sys_Stat_IHC_Sys_Stat Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_Sys_Stat_IHC_Sys_Stat
#  define Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IHC_Sys_Stat_IHC_Sys_Stat(data) ((void)Com_ReceiveSignal(Com_IHC_Sys_Stat, (data)), RTE_E_OK)
#  define Rte_Read_R_IL_F_Actv_IL_F_Actv Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IL_F_Actv_IL_F_Actv
#  define Rte_Read_R_IL_R_Actv_IL_R_Actv Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_IL_R_Actv_IL_R_Actv
#  define Rte_Read_R_MirrAdj_Lt_Rq_MirrAdj_XX_Rq Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_MirrAdj_Lt_Rq_MirrAdj_XX_Rq
#  define Rte_Read_R_MirrAdj_Rt_Rq_MirrAdj_XX_Rq Rte_Read_CT_SA_IntelligentLightSys_MPC_V1_R_MirrAdj_Rt_Rq_MirrAdj_XX_Rq


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_IHC_Lgt_Stat_MPC_IHC_Lgt_Stat_MPC Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_IHC_Lgt_Stat_MPC_IHC_Lgt_Stat_MPC
#  define Rte_Write_P_IHC_Plus_HL_Stat_IHC_Plus_HL_Stat Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_IHC_Plus_HL_Stat_IHC_Plus_HL_Stat
#  define Rte_Write_P_Meas_MPC_1_Meas_XX Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_Meas_MPC_1_Meas_XX
#  define Rte_Write_P_Meas_MPC_2_Meas_XX Rte_Write_CT_SA_IntelligentLightSys_MPC_V1_P_Meas_MPC_2_Meas_XX


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_CODE) NORM_v_HLA_RxFct(void);

FUNC(void, RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_CODE) NORM_v_HLA_finished(void);

# define RTE_STOP_SEC_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_IntelligentLightSys_MPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_H */
