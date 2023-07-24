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
 *          File:  Components/Rte_CT_SA_TrafficSignAssyst_SMPC_V1.h
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
#ifndef _RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_H
# define _RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_H

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

#  define Rte_InitValue_P_PMA_Pass_Warn_Rq_PMA_Pass_Warn_Rq ((c02_PMA_Pass_Warn_Rq)0u)
#  define Rte_InitValue_P_PMA_Warn_Rq_PMA_Warn_Rq ((c02_PMA_Warn_Rq)0u)
#  define Rte_InitValue_P_RoadWork_Warn_Rq_RoadWork_Warn_Rq ((c02_RoadWork_Warn_Rq)0u)
#  define Rte_InitValue_P_SLA_SpdWarn_DispType_SLA_SpdWarn_DispType ((c03_SLA_SpdWarn_DispType)0u)
#  define Rte_InitValue_P_SLA_SpdWarn_Rq_SLA_SpdWarn_Rq ((c02_SLA_SpdWarn_Rq)0u)
#  define Rte_InitValue_P_SLA_WarnSpd_Unit_SLA_WarnSpd_Unit ((c01_UnitVehSpd)0u)
#  define Rte_InitValue_P_SLA_WarnSpd_Val_SLA_WarnSpd_Val ((c08_0_254_1)0u)
#  define Rte_InitValue_P_SLA_Warn_Rq_SLA_Warn_Rq ((c02_SLA_Warn_Rq)0u)
#  define Rte_InitValue_P_TSA_Stat_TSA_Stat ((c03_TSA_Stat)0u)
#  define Rte_InitValue_P_WWA_Warn_Rq_WWA_Warn_Rq ((c02_WWA_Warn_Rq)0u)
#  define Rte_InitValue_R_PMA_Md_Rq_PMA_Md_Rq ((c02_Md_Rq)3u)
#  define Rte_InitValue_R_SLA_Md_Rq_SLA_Md_Rq ((c02_SLA_Md_Rq)3u)
#  define Rte_InitValue_R_Trlr_Stat_Trlr_Stat ((c02_Trl_Stat)3u)
#  define Rte_InitValue_R_WWA_Md_Rq_WWA_Md_Rq ((c02_Md_Rq)3u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_DateTm_DateTm(P2VAR(REC_DateTm, AUTOMATIC, RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_PMA_Pass_Warn_Rq_PMA_Pass_Warn_Rq(c02_PMA_Pass_Warn_Rq data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_PMA_Warn_Rq_PMA_Warn_Rq(c02_PMA_Warn_Rq data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_RoadWork_Warn_Rq_RoadWork_Warn_Rq(c02_RoadWork_Warn_Rq data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_SpdWarn_DispType_SLA_SpdWarn_DispType(c03_SLA_SpdWarn_DispType data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_SpdWarn_Rq_SLA_SpdWarn_Rq(c02_SLA_SpdWarn_Rq data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_WarnSpd_Unit_SLA_WarnSpd_Unit(c01_UnitVehSpd data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_WarnSpd_Val_SLA_WarnSpd_Val(c08_0_254_1 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_Warn_Rq_SLA_Warn_Rq(c02_SLA_Warn_Rq data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_TSA_Disp_Rq2_TSA_Disp_Rq2(P2CONST(REC_08_UInt_Record8, AUTOMATIC, RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_TSA_Stat_TSA_Stat(c03_TSA_Stat data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_WWA_Warn_Rq_WWA_Warn_Rq(c02_WWA_Warn_Rq data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_DateTm_DateTm Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_DateTm_DateTm
#  define Rte_Read_R_PMA_Md_Rq_PMA_Md_Rq Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_PMA_Md_Rq_PMA_Md_Rq
#  define Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_PMA_Md_Rq_PMA_Md_Rq(data) ((void)Com_ReceiveSignal(Com_PMA_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_SLA_Md_Rq_SLA_Md_Rq Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_SLA_Md_Rq_SLA_Md_Rq
#  define Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_SLA_Md_Rq_SLA_Md_Rq(data) ((void)Com_ReceiveSignal(Com_SLA_Md_Rq, (data)), RTE_E_OK)
#  define Rte_Read_R_Trlr_Stat_Trlr_Stat Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_Trlr_Stat_Trlr_Stat
#  define Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_Trlr_Stat_Trlr_Stat(data) ((void)Com_ReceiveSignal(Com_Trlr_Stat, (data)), RTE_E_OK)
#  define Rte_Read_R_WWA_Md_Rq_WWA_Md_Rq Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_WWA_Md_Rq_WWA_Md_Rq
#  define Rte_Read_CT_SA_TrafficSignAssyst_SMPC_V1_R_WWA_Md_Rq_WWA_Md_Rq(data) ((void)Com_ReceiveSignal(Com_WWA_Md_Rq, (data)), RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_PMA_Pass_Warn_Rq_PMA_Pass_Warn_Rq Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_PMA_Pass_Warn_Rq_PMA_Pass_Warn_Rq
#  define Rte_Write_P_PMA_Warn_Rq_PMA_Warn_Rq Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_PMA_Warn_Rq_PMA_Warn_Rq
#  define Rte_Write_P_RoadWork_Warn_Rq_RoadWork_Warn_Rq Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_RoadWork_Warn_Rq_RoadWork_Warn_Rq
#  define Rte_Write_P_SLA_SpdWarn_DispType_SLA_SpdWarn_DispType Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_SpdWarn_DispType_SLA_SpdWarn_DispType
#  define Rte_Write_P_SLA_SpdWarn_Rq_SLA_SpdWarn_Rq Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_SpdWarn_Rq_SLA_SpdWarn_Rq
#  define Rte_Write_P_SLA_WarnSpd_Unit_SLA_WarnSpd_Unit Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_WarnSpd_Unit_SLA_WarnSpd_Unit
#  define Rte_Write_P_SLA_WarnSpd_Val_SLA_WarnSpd_Val Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_WarnSpd_Val_SLA_WarnSpd_Val
#  define Rte_Write_P_SLA_Warn_Rq_SLA_Warn_Rq Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_SLA_Warn_Rq_SLA_Warn_Rq
#  define Rte_Write_P_TSA_Disp_Rq2_TSA_Disp_Rq2 Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_TSA_Disp_Rq2_TSA_Disp_Rq2
#  define Rte_Write_P_TSA_Stat_TSA_Stat Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_TSA_Stat_TSA_Stat
#  define Rte_Write_P_WWA_Warn_Rq_WWA_Warn_Rq Rte_Write_CT_SA_TrafficSignAssyst_SMPC_V1_P_WWA_Warn_Rq_WWA_Warn_Rq


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_CODE) NORM_v_TSA_RxFct(void);

FUNC(void, RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_CODE) NORM_v_TSA_finished(void);

# define RTE_STOP_SEC_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_TrafficSignAssyst_SMPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_H */
