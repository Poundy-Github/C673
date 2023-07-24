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
 *          File:  Rte_Compiler_Cfg.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:52 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  RTE Compiler Abstraction header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMPILER_CFG_H
# define _RTE_COMPILER_CFG_H


/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODE
 *********************************************************************************************************************/

/* used for code */
# define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
# define RTE_VAR_NOINIT

/* used for global or static variables that are initialized with zero by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_ZERO_INIT

/* used for global or static constants */
# define RTE_CONST

/* used for references on application data (variables or constants */
# define RTE_APPL_DATA

/* used for references on application variables */
# define RTE_APPL_VAR

/* used for references on application functions */
# define RTE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CP_AP_DIAGNOSTICSAPPL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CP_AP_DIAGNOSTICSAPPL_APPL_DATA

/* used for references on application functions */
# define RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CP_AP_MODEMANAGER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CP_AP_MODEMANAGER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CP_AP_MODEMANAGER_APPL_DATA

/* used for references on application functions */
# define RTE_CP_AP_MODEMANAGER_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_ALDW_MPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_ALDW_MPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_ALDW_MPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_ALDW_MPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_ALDW_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_ALDW_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_ALDW_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_ALDW_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_BASERECEIVEFUNCTION_SMPC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_BLINDSPOTMONITORING_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_BLINDSPOTMONITORING_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_BLINDSPOTMONITORING_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_BLINDSPOTMONITORING_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_BRAKEASSYSTPLUSQ_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_COLLISIONMITIGATIONSYS_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_COLLISIONMITIGATIONSYS_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_COLLISIONMITIGATIONSYS_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_COLLISIONMITIGATIONSYS_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_DIAGNOSTICS_DEM_SC_XX_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_DISTRONICPLUSQ_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_HEADUNIT_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_HEADUNIT_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_INTELLIGENTLIGHTSYS_MPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_NIGHTVIEW_MPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_NIGHTVIEW_MPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_NIGHTVIEW_MPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_NIGHTVIEW_MPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_SUSPENSIONCTRL_PREVIEW_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_TRAFFICSIGNASSYST_SMPC_V1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_COMM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_COMM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_COMM_APPL_DATA

/* used for references on application functions */
# define RTE_COMM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DCM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DCM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DCM_APPL_DATA

/* used for references on application functions */
# define RTE_DCM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEM_APPL_DATA

/* used for references on application functions */
# define RTE_DEM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEMSC_LOCSTUB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEMSC_LOCSTUB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEMSC_LOCSTUB_APPL_DATA

/* used for references on application functions */
# define RTE_DEMSC_LOCSTUB_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SWCDEMSC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SWCDEMSC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SWCDEMSC_APPL_DATA

/* used for references on application functions */
# define RTE_SWCDEMSC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SWCROELITE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SWCROELITE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SWCROELITE_APPL_DATA

/* used for references on application functions */
# define RTE_SWCROELITE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Per-Instance Memory specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CT_SA_DIAGNOSTICS_ROELITE_XX_V1_APPL)  */

/* used for references on application variables */
# define RTE_CT_SA_DIAGNOSTICS_ROELITE_XX_V1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CT_SA_DIAGNOSTICS_ROELITE_XX_V1_APPL_DATA

/* used for references on application functions */
# define RTE_CT_SA_DIAGNOSTICS_ROELITE_XX_V1_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Rte_Compiler_Cfg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_COMPILER_CFG_H */
