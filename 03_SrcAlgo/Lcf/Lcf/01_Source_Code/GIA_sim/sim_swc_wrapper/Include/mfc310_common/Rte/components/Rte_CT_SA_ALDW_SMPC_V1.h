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
 *          File:  Components/Rte_CT_SA_ALDW_SMPC_V1.h
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
#ifndef _RTE_CT_SA_ALDW_SMPC_V1_H
# define _RTE_CT_SA_ALDW_SMPC_V1_H

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

#  define Rte_InitValue_R_IL_On_Rq_IL_On_Rq ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup ((c01_Off_On)0u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_ALDW_SMPC_V1_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup(P2VAR(c01_Off_On, AUTOMATIC, RTE_CT_SA_ALDW_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_SMPC_V1_P_ALDW_LaneAttr4_ALDW_LaneAttr4(P2CONST(REC_ALDW_LaneAttr4_2ahxpf4cam3pi2le1l2woky78, AUTOMATIC, RTE_CT_SA_ALDW_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_SMPC_V1_P_ALDW_Polyg_ALDW_Polyg(P2CONST(REC_ALDW_Polyg_eymr1ts77ut9vrrgvrho4m92e, AUTOMATIC, RTE_CT_SA_ALDW_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_SMPC_V1_P_ALDW_VLN_ALDW_VLN(P2CONST(REC_ALDW_VLN_a2qglp2324znbwefnu92uartf, AUTOMATIC, RTE_CT_SA_ALDW_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_ALDW_SMPC_V1_P_Cam_Polyg_Cam_Polyg(P2CONST(REC_Cam_Polyg_4hl0f8uklena7h1l78vguqx2i, AUTOMATIC, RTE_CT_SA_ALDW_SMPC_V1_APPL_DATA) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_IL_On_Rq_IL_On_Rq Rte_Read_CT_SA_ALDW_SMPC_V1_R_IL_On_Rq_IL_On_Rq
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_ALDW_SMPC_V1_R_IL_On_Rq_IL_On_Rq(data) \
    ((void)Com_ReceiveSignal(Com_IL_On_Rq, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_ALDW_SMPC_V1_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_ALDW_SMPC_V1_R_IL_On_Rq_IL_On_Rq(data) ((void)Com_ReceiveSignal(Com_IL_On_Rq, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup Rte_Read_CT_SA_ALDW_SMPC_V1_R_StW_Cond_ALDW_Sup_StW_Cond_ALDW_Sup


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_ALDW_LaneAttr4_ALDW_LaneAttr4 Rte_Write_CT_SA_ALDW_SMPC_V1_P_ALDW_LaneAttr4_ALDW_LaneAttr4
#  define Rte_Write_P_ALDW_Polyg_ALDW_Polyg Rte_Write_CT_SA_ALDW_SMPC_V1_P_ALDW_Polyg_ALDW_Polyg
#  define Rte_Write_P_ALDW_VLN_ALDW_VLN Rte_Write_CT_SA_ALDW_SMPC_V1_P_ALDW_VLN_ALDW_VLN
#  define Rte_Write_P_Cam_Polyg_Cam_Polyg Rte_Write_CT_SA_ALDW_SMPC_V1_P_Cam_Polyg_Cam_Polyg


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_ALDW_SMPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_ALDW_SMPC_V1_APPL_CODE) NORM_v_ALDW_S_RxFct(void);

FUNC(void, RTE_CT_SA_ALDW_SMPC_V1_APPL_CODE) NORM_v_ALDW_S_finished(void);

# define RTE_STOP_SEC_CT_SA_ALDW_SMPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_ALDW_SMPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_ALDW_SMPC_V1_H */
