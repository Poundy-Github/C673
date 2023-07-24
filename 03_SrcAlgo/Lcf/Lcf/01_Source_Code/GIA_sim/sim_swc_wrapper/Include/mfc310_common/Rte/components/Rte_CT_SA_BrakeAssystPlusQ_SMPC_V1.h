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
 *          File:  Components/Rte_CT_SA_BrakeAssystPlusQ_SMPC_V1.h
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
#ifndef _RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_H
# define _RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_CamObj_AB_BPQ_CamObj_AB_BPQ(P2CONST(REC_CamObj_AB_BPQ_7e63hifz077cq0l1to4chei0g, AUTOMATIC, RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_CamObj_A_BPQ_Posn_CamObj_A_BPQ_Posn(P2CONST(REC_CamObj_A_BPQ_Posn, AUTOMATIC, RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_CamObj_B_BPQ_Posn_CamObj_B_BPQ_Posn(P2CONST(REC_CamObj_B_BPQ_Posn, AUTOMATIC, RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_Cam_Stat_Cam_Stat(P2CONST(REC_Cam_Stat_1lbtoaaebi5n2qvdq20f1phhd, AUTOMATIC, RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_DATA) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_CamObj_AB_BPQ_CamObj_AB_BPQ Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_CamObj_AB_BPQ_CamObj_AB_BPQ
#  define Rte_Write_P_CamObj_A_BPQ_Posn_CamObj_A_BPQ_Posn Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_CamObj_A_BPQ_Posn_CamObj_A_BPQ_Posn
#  define Rte_Write_P_CamObj_B_BPQ_Posn_CamObj_B_BPQ_Posn Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_CamObj_B_BPQ_Posn_CamObj_B_BPQ_Posn
#  define Rte_Write_P_Cam_Stat_Cam_Stat Rte_Write_CT_SA_BrakeAssystPlusQ_SMPC_V1_P_Cam_Stat_Cam_Stat


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_CODE) NORM_v_BApQ_finished(void);

# define RTE_STOP_SEC_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_BrakeAssystPlusQ_SMPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_H */
