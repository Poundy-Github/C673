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
 *          File:  Components/Rte_CT_SA_Headunit_SMPC_V1.h
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
#ifndef _RTE_CT_SA_HEADUNIT_SMPC_V1_H
# define _RTE_CT_SA_HEADUNIT_SMPC_V1_H

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
extern VAR(c03_MsgTyp_1_to_7, RTE_VAR_NOINIT) Rte_ADAS_Prediction_MsgTyp;
extern VAR(c05_ADAS_ProfLong_ProfTyp, RTE_VAR_NOINIT) Rte_ADAS_ProfLong_ProfTyp;
extern VAR(c05_ADAS_ProfShort_ProfTyp, RTE_VAR_NOINIT) Rte_ADAS_ProfShort_ProfTyp;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_R_ADAS_Prediction_MsgTyp_ADAS_Prediction_MsgTyp ((c03_MsgTyp_1_to_7)7u)
#  define Rte_InitValue_R_ADAS_ProfLong_ProfTyp_ADAS_ProfLong_ProfTyp ((c05_ADAS_ProfLong_ProfTyp)31u)
#  define Rte_InitValue_R_ADAS_ProfShort_ProfTyp_ADAS_ProfShort_ProfTyp ((c05_ADAS_ProfShort_ProfTyp)31u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_CuA_ADAS_CuA(P2VAR(REC_ADAS_CuA, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Meta_ADAS_Meta(P2VAR(REC_ADAS_Meta, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Posn_ADAS_Posn(P2VAR(REC_ADAS_Posn, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_Latit_ADAS_Profile_Long_Latit(P2VAR(REC_ADAS_Profile_Long_Latit, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_Longit_ADAS_Profile_Long_Longit(P2VAR(REC_ADAS_Profile_Long_Longit, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_NPSL1_ADAS_Profile_Long_NPSL1(P2VAR(REC_ADAS_Profile_Long_NPSL1, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_NPSL2_ADAS_Profile_Long_NPSL2(P2VAR(REC_ADAS_Profile_Long_NPSL2, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_CurvLn_ADAS_Profile_Short_CurvLn(P2VAR(REC_ADAS_Profile_Short_CurvLn, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_HeadChSp_ADAS_Profile_Short_HeadChSp(P2VAR(REC_ADAS_Profile_Short_HeadChSp, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_LocDest_ADAS_Profile_Short_LocDest(P2VAR(REC_ADAS_Profile_Short_LocDest, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_RoadAcc_ADAS_Profile_Short_RoadAcc(P2VAR(REC_ADAS_Profile_Short_RoadAcc, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_RoadCon_ADAS_Profile_Short_RoadCon(P2VAR(REC_ADAS_Profile_Short_RoadCon, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_RoutNum_ADAS_Profile_Short_RoutNum(P2VAR(REC_ADAS_Profile_Short_RoutNum, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_SlopeLn_ADAS_Profile_Short_SlopeLn(P2VAR(REC_ADAS_Profile_Short_SlopeLn, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_SlopeSt_ADAS_Profile_Short_SlopeSt(P2VAR(REC_ADAS_Profile_Short_SlopeSt, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_VarSpSign_ADAS_Profile_Short_VarSpSign(P2VAR(REC_ADAS_Profile_Short_VarSpSign, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Segment_ADAS_Segment(P2VAR(REC_ADAS_Segment, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Stub_ADAS_Stub(P2VAR(REC_ADAS_Stub, AUTOMATIC, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR) data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_ADAS_CuA_ADAS_CuA Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_CuA_ADAS_CuA
#  define Rte_Read_R_ADAS_Meta_ADAS_Meta Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Meta_ADAS_Meta
#  define Rte_Read_R_ADAS_Posn_ADAS_Posn Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Posn_ADAS_Posn
#  define Rte_Read_R_ADAS_Prediction_MsgTyp_ADAS_Prediction_MsgTyp Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Prediction_MsgTyp_ADAS_Prediction_MsgTyp
#  define Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Prediction_MsgTyp_ADAS_Prediction_MsgTyp(data) (*(data) = Rte_ADAS_Prediction_MsgTyp, RTE_E_OK)
#  define Rte_Read_R_ADAS_ProfLong_ProfTyp_ADAS_ProfLong_ProfTyp Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_ProfLong_ProfTyp_ADAS_ProfLong_ProfTyp
#  define Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_ProfLong_ProfTyp_ADAS_ProfLong_ProfTyp(data) (*(data) = Rte_ADAS_ProfLong_ProfTyp, RTE_E_OK)
#  define Rte_Read_R_ADAS_ProfShort_ProfTyp_ADAS_ProfShort_ProfTyp Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_ProfShort_ProfTyp_ADAS_ProfShort_ProfTyp
#  define Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_ProfShort_ProfTyp_ADAS_ProfShort_ProfTyp(data) (*(data) = Rte_ADAS_ProfShort_ProfTyp, RTE_E_OK)
#  define Rte_Read_R_ADAS_Profile_Long_Latit_ADAS_Profile_Long_Latit Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_Latit_ADAS_Profile_Long_Latit
#  define Rte_Read_R_ADAS_Profile_Long_Longit_ADAS_Profile_Long_Longit Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_Longit_ADAS_Profile_Long_Longit
#  define Rte_Read_R_ADAS_Profile_Long_NPSL1_ADAS_Profile_Long_NPSL1 Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_NPSL1_ADAS_Profile_Long_NPSL1
#  define Rte_Read_R_ADAS_Profile_Long_NPSL2_ADAS_Profile_Long_NPSL2 Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Long_NPSL2_ADAS_Profile_Long_NPSL2
#  define Rte_Read_R_ADAS_Profile_Short_CurvLn_ADAS_Profile_Short_CurvLn Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_CurvLn_ADAS_Profile_Short_CurvLn
#  define Rte_Read_R_ADAS_Profile_Short_HeadChSp_ADAS_Profile_Short_HeadChSp Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_HeadChSp_ADAS_Profile_Short_HeadChSp
#  define Rte_Read_R_ADAS_Profile_Short_LocDest_ADAS_Profile_Short_LocDest Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_LocDest_ADAS_Profile_Short_LocDest
#  define Rte_Read_R_ADAS_Profile_Short_RoadAcc_ADAS_Profile_Short_RoadAcc Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_RoadAcc_ADAS_Profile_Short_RoadAcc
#  define Rte_Read_R_ADAS_Profile_Short_RoadCon_ADAS_Profile_Short_RoadCon Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_RoadCon_ADAS_Profile_Short_RoadCon
#  define Rte_Read_R_ADAS_Profile_Short_RoutNum_ADAS_Profile_Short_RoutNum Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_RoutNum_ADAS_Profile_Short_RoutNum
#  define Rte_Read_R_ADAS_Profile_Short_SlopeLn_ADAS_Profile_Short_SlopeLn Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_SlopeLn_ADAS_Profile_Short_SlopeLn
#  define Rte_Read_R_ADAS_Profile_Short_SlopeSt_ADAS_Profile_Short_SlopeSt Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_SlopeSt_ADAS_Profile_Short_SlopeSt
#  define Rte_Read_R_ADAS_Profile_Short_VarSpSign_ADAS_Profile_Short_VarSpSign Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Profile_Short_VarSpSign_ADAS_Profile_Short_VarSpSign
#  define Rte_Read_R_ADAS_Segment_ADAS_Segment Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Segment_ADAS_Segment
#  define Rte_Read_R_ADAS_Stub_ADAS_Stub Rte_Read_CT_SA_Headunit_SMPC_V1_R_ADAS_Stub_ADAS_Stub


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_Head_RxFct(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_CuA(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Meta(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Posn(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Prediction_MsgTyp(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_ProfLong_ProfTyp(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_ProfShort_ProfTyp(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Long_Latit(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Long_Longit(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Long_NPSL1(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Long_NPSL2(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_CurvLn(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_HeadChSp(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_LocDest(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_RoadAcc(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_RoadCon(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_RoutNum(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_SlopeLn(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_SlopeSt(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Profile_Short_VarSpSign(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Segment(void);

FUNC(void, RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE) NORM_v_MAP_OnRx_ADAS_Stub(void);

# define RTE_STOP_SEC_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_CT_SA_Headunit_SMPC_V1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CT_SA_HEADUNIT_SMPC_V1_H */
