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
 *          File:  Components/Rte_CT_SA_Diagnostics_DEM_SC_XX_V1.h
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
#ifndef _RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_H
# define _RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_H

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

#  define Rte_InitValue_R_DidA_ExtTest_Pres_DidA_ExtTest_Pres ((DC_BOOL)FALSE)
#  define Rte_InitValue_R_Odo_Odo ((c24_km_0_999999k9_0k1)16777215u)
#  define Rte_InitValue_R_PN14_TransMd_Stat_PN14_TransMd_Stat ((c02_TransMd_Stat)3u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl(P2VAR(REC_Eng_Rs_EngCtrl_1j00gxu3p5exa8awg915k1zy, AUTOMATIC, RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_Ign_Stat_Ign_Stat(P2VAR(REC_Ign_Stat_b0ko81o0x5jgvwtduf99gvzi0, AUTOMATIC, RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_PN14_SupBat_Stat_PN14_SupBat_Stat(P2VAR(REC_PN14_SupBat_Stat_2is6fi0meeac78nkn35zc5ui3, AUTOMATIC, RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_VAR) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_DidA_ExtTest_Pres_DidA_ExtTest_Pres Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_DidA_ExtTest_Pres_DidA_ExtTest_Pres
#  if defined(IL_VECTOR_VERSION)
#   define Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_DidA_ExtTest_Pres_DidA_ExtTest_Pres(data) \
    ((void)Com_ReceiveSignal(Com_DidA_ExtTest_Pres, (P2VAR(uint8, AUTOMATIC, RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_VAR))(data)), \
    RTE_E_OK)
#  else
#   define Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_DidA_ExtTest_Pres_DidA_ExtTest_Pres(data) ((void)Com_ReceiveSignal(Com_DidA_ExtTest_Pres, (data)), RTE_E_OK)
#  endif
#  define Rte_Read_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_Eng_Rs_EngCtrl_Eng_Rs_EngCtrl
#  define Rte_Read_R_Ign_Stat_Ign_Stat Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_Ign_Stat_Ign_Stat
#  define Rte_Read_R_Odo_Odo Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_Odo_Odo
#  define Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_Odo_Odo(data) ((void)Com_ReceiveSignal(Com_Odo, (data)), RTE_E_OK)
#  define Rte_Read_R_PN14_SupBat_Stat_PN14_SupBat_Stat Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_PN14_SupBat_Stat_PN14_SupBat_Stat
#  define Rte_Read_R_PN14_TransMd_Stat_PN14_TransMd_Stat Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_PN14_TransMd_Stat_PN14_TransMd_Stat
#  define Rte_Read_CT_SA_Diagnostics_DEM_SC_XX_V1_R_PN14_TransMd_Stat_PN14_TransMd_Stat(data) ((void)Com_ReceiveSignal(Com_PN14_TransMd_Stat, (data)), RTE_E_OK)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE) RE_CP_SA_NormDemSc(void);

# define RTE_STOP_SEC_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_Diagnostics_DEM_SC_XX_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_H */
