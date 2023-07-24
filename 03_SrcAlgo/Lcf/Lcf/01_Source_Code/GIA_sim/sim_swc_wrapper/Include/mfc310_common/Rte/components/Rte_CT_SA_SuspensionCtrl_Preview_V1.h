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
 *          File:  Components/Rte_CT_SA_SuspensionCtrl_Preview_V1.h
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
#ifndef _RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_H
# define _RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_H

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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_SuspensionCtrl_Preview_V1_R_Preview_VehAccel_Preview_VehAccel(P2VAR(REC_Preview_VehAccel, AUTOMATIC, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_Header1_Preview_Header1(P2CONST(REC_Preview_Header1_a2qglp2324znbwefnu92uartf, AUTOMATIC, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_Header2_Preview_Header2(P2CONST(REC_Preview_Header2_1ae8w4ccn5pv3jukyqv8emy5n, AUTOMATIC, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_ProfData1_Preview_ProfData1(P2CONST(REC_Preview_ProfData1, AUTOMATIC, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_ProfData2_Preview_ProfData2(P2CONST(REC_Preview_ProfData2, AUTOMATIC, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_DATA) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_Preview_VehAccel_Preview_VehAccel Rte_Read_CT_SA_SuspensionCtrl_Preview_V1_R_Preview_VehAccel_Preview_VehAccel


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_Preview_Header1_Preview_Header1 Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_Header1_Preview_Header1
#  define Rte_Write_P_Preview_Header2_Preview_Header2 Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_Header2_Preview_Header2
#  define Rte_Write_P_Preview_ProfData1_Preview_ProfData1 Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_ProfData1_Preview_ProfData1
#  define Rte_Write_P_Preview_ProfData2_Preview_ProfData2 Rte_Write_CT_SA_SuspensionCtrl_Preview_V1_P_Preview_ProfData2_Preview_ProfData2


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_CODE) NORM_v_PV_Header_finished(void);

FUNC(void, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_CODE) NORM_v_PV_RxFct(void);

FUNC(void, RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_CODE) NORM_v_PV_ProfData_finished(void);

# define RTE_STOP_SEC_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_SuspensionCtrl_Preview_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_H */
