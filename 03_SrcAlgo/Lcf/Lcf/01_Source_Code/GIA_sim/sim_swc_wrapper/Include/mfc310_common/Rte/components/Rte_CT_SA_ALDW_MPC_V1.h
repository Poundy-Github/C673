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
 *          File:  Components/Rte_CT_SA_ALDW_MPC_V1.h
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
#ifndef _RTE_CT_SA_ALDW_MPC_V1_H
# define _RTE_CT_SA_ALDW_MPC_V1_H

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
#  define Rte_InitValue_R_ALDW_Sw_Md_ALDW_Sw_Md ((c02_Off_On_Fail_SNA)3u)
#  define Rte_InitValue_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat ((c03_ALDW_VibMot_Stat)7u)
#  define Rte_InitValue_R_FogLmp_R_On_Rq_MPM_FogLmp_R_On_Rq_MPM ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_IL_On_Rq_IL_On_Rq ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup ((c01_Off_On)0u)
#  define Rte_InitValue_R_TurnLvr_Psd_MPM_TurnLvr_Psd_MPM ((c02_TurnIndLvr_Stat)0u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_Md_Rq_ALDW_Md_Rq(P2VAR(c03_ALDW_Md_Rq, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_Sw_Md_ALDW_Sw_Md(P2VAR(c02_Off_On_Fail_SNA, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl(P2VAR(DC_BOOL, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat(P2VAR(c03_ALDW_VibMot_Stat, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_LDP_Warn_Rq_LDP_Warn_Rq(P2VAR(REC_LDP_Warn_Rq, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_MirrAdj_Lt_Rq_MPM_MirrAdj_XX_Rq_MPM(P2VAR(REC_MirrAdj_XX_Rq_MPM, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_MirrAdj_Rt_Rq_MPM_MirrAdj_XX_Rq_MPM(P2VAR(REC_MirrAdj_XX_Rq_MPM, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_MPC_V1_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup(P2VAR(c01_Off_On, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_Disp_Warn_Rq_ALDW_Disp_Warn_Rq(P2CONST(REC_ALDW_Disp_Warn_Rq_515fv9hxb5jrzmunrr9r72aqj, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_LaneAttr1_ALDW_LaneAttr1(P2CONST(REC_ALDW_LaneAttr1_evn08d6126fkfaksv87161o1j, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_LaneAttr2_ALDW_LaneAttr2(P2CONST(REC_ALDW_LaneAttr2, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_LaneAttr3_ALDW_LaneAttr3(P2CONST(REC_ALDW_LaneAttr3, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_DATA) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_ALDW_Md_Rq_ALDW_Md_Rq Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_Md_Rq_ALDW_Md_Rq
#  define Rte_Read_R_ALDW_Sw_Md_ALDW_Sw_Md Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_Sw_Md_ALDW_Sw_Md
#  define Rte_Read_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_VibMot_Avl_ALDW_VibMot_Avl
#  define Rte_Read_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat Rte_Read_CT_SA_ALDW_MPC_V1_R_ALDW_VibMot_Stat_ALDW_VibMot_Stat
#  define Rte_Read_R_FogLmp_R_On_Rq_MPM_FogLmp_R_On_Rq_MPM Rte_Read_CT_SA_ALDW_MPC_V1_R_FogLmp_R_On_Rq_MPM_FogLmp_R_On_Rq_MPM
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_ALDW_MPC_V1_R_FogLmp_R_On_Rq_MPM_FogLmp_R_On_Rq_MPM(data) \
    ((void)Com_ReceiveSignal(Com_FogLmp_R_On_Rq_MPM, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_ALDW_MPC_V1_R_FogLmp_R_On_Rq_MPM_FogLmp_R_On_Rq_MPM(data) ((void)Com_ReceiveSignal(Com_FogLmp_R_On_Rq_MPM, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_IL_On_Rq_IL_On_Rq Rte_Read_CT_SA_ALDW_MPC_V1_R_IL_On_Rq_IL_On_Rq
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_ALDW_MPC_V1_R_IL_On_Rq_IL_On_Rq(data) \
    ((void)Com_ReceiveSignal(Com_IL_On_Rq, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_ALDW_MPC_V1_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_ALDW_MPC_V1_R_IL_On_Rq_IL_On_Rq(data) ((void)Com_ReceiveSignal(Com_IL_On_Rq, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_LDP_Warn_Rq_LDP_Warn_Rq Rte_Read_CT_SA_ALDW_MPC_V1_R_LDP_Warn_Rq_LDP_Warn_Rq
#  define Rte_Read_R_MirrAdj_Lt_Rq_MPM_MirrAdj_XX_Rq_MPM Rte_Read_CT_SA_ALDW_MPC_V1_R_MirrAdj_Lt_Rq_MPM_MirrAdj_XX_Rq_MPM
#  define Rte_Read_R_MirrAdj_Rt_Rq_MPM_MirrAdj_XX_Rq_MPM Rte_Read_CT_SA_ALDW_MPC_V1_R_MirrAdj_Rt_Rq_MPM_MirrAdj_XX_Rq_MPM
#  define Rte_Read_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup Rte_Read_CT_SA_ALDW_MPC_V1_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup
#  define Rte_Read_R_TurnLvr_Psd_MPM_TurnLvr_Psd_MPM Rte_Read_CT_SA_ALDW_MPC_V1_R_TurnLvr_Psd_MPM_TurnLvr_Psd_MPM
#  define Rte_Read_CT_SA_ALDW_MPC_V1_R_TurnLvr_Psd_MPM_TurnLvr_Psd_MPM(data) ((void)Com_ReceiveSignal(Com_TurnLvr_Psd_MPM, (data)), RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_ALDW_Disp_Warn_Rq_ALDW_Disp_Warn_Rq Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_Disp_Warn_Rq_ALDW_Disp_Warn_Rq
#  define Rte_Write_P_ALDW_LaneAttr1_ALDW_LaneAttr1 Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_LaneAttr1_ALDW_LaneAttr1
#  define Rte_Write_P_ALDW_LaneAttr2_ALDW_LaneAttr2 Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_LaneAttr2_ALDW_LaneAttr2
#  define Rte_Write_P_ALDW_LaneAttr3_ALDW_LaneAttr3 Rte_Write_CT_SA_ALDW_MPC_V1_P_ALDW_LaneAttr3_ALDW_LaneAttr3


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_ALDW_MPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_ALDW_MPC_V1_APPL_CODE) NORM_v_ALDW_M_RxFct(void);

FUNC(void, RTE_CT_SA_ALDW_MPC_V1_APPL_CODE) NORM_v_ALDW_M_finished(void);

# define RTE_STOP_SEC_CT_SA_ALDW_MPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_ALDW_MPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_ALDW_MPC_V1_H */
