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
 *          File:  Components/Rte_CT_SA_DistronicPlusQ_SMPC_V1.h
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
#ifndef _RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_H
# define _RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_H

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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_BrkSys_Stat_BrkSys_Stat(P2VAR(REC_BrkSys_Stat_d7pccc3s00bjj322036sa5kif, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_DTQ_Ctrl_DTQ_Ctrl(P2VAR(REC_DTQ_Ctrl, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_DTQ_Disp_Rq_V2_DTQ_Disp_Rq_V2(P2VAR(REC_DTQ_Disp_Rq_V2_b0ko81o0x5jgvwtduf99gvzi0, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_DTQ_Obj_Pres_DTQ_Obj_Pres(P2VAR(REC_DTQ_Obj_Pres_4ahuc5cy8shtai9jzr7jgnsdp, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_RDU_GlobalAttr_RDU_GlobalAttr(P2VAR(REC_RDU_GlobalAttr_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_CamObj_1_DTQ_CamObj_1_DTQ(P2CONST(REC_CamObj_1_DTQ_d7pccc3s00bjj322036sa5kif, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_CamObj_2_DTQ_CamObj_2_DTQ(P2CONST(REC_CamObj_2_DTQ_d7pccc3s00bjj322036sa5kif, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_CamObj_3_DTQ_CamObj_3_DTQ(P2CONST(REC_CamObj_3_DTQ_d7pccc3s00bjj322036sa5kif, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_DTQ_DrawbarAngl_DTQ_DrawbarAngl(P2CONST(REC_DTQ_DrawbarAngl_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_DATA) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_BrkSys_Stat_BrkSys_Stat Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_BrkSys_Stat_BrkSys_Stat
#  define Rte_Read_R_DTQ_Ctrl_DTQ_Ctrl Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_DTQ_Ctrl_DTQ_Ctrl
#  define Rte_Read_R_DTQ_Disp_Rq_V2_DTQ_Disp_Rq_V2 Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_DTQ_Disp_Rq_V2_DTQ_Disp_Rq_V2
#  define Rte_Read_R_DTQ_Obj_Pres_DTQ_Obj_Pres Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_DTQ_Obj_Pres_DTQ_Obj_Pres
#  define Rte_Read_R_RDU_GlobalAttr_RDU_GlobalAttr Rte_Read_CT_SA_DistronicPlusQ_SMPC_V1_R_RDU_GlobalAttr_RDU_GlobalAttr


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_CamObj_1_DTQ_CamObj_1_DTQ Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_CamObj_1_DTQ_CamObj_1_DTQ
#  define Rte_Write_P_CamObj_2_DTQ_CamObj_2_DTQ Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_CamObj_2_DTQ_CamObj_2_DTQ
#  define Rte_Write_P_CamObj_3_DTQ_CamObj_3_DTQ Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_CamObj_3_DTQ_CamObj_3_DTQ
#  define Rte_Write_P_DTQ_DrawbarAngl_DTQ_DrawbarAngl Rte_Write_CT_SA_DistronicPlusQ_SMPC_V1_P_DTQ_DrawbarAngl_DTQ_DrawbarAngl


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_CODE) NORM_v_DTRpQ_RxFct(void);

FUNC(void, RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_CODE) NORM_v_DTRpQ_finished(void);

# define RTE_STOP_SEC_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_DistronicPlusQ_SMPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_H */
