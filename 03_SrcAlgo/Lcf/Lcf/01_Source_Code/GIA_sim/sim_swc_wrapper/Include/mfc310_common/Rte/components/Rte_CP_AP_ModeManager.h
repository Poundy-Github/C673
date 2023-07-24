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
 *          File:  Components/Rte_CP_AP_ModeManager.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:49 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CP_AP_MODEMANAGER_H
# define _RTE_CP_AP_MODEMANAGER_H
#ifndef FR_BUS_ARCHT_STAR_1
# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif
#endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */
#ifndef FR_BUS_ARCHT_STAR_1
# include "Rte_Type.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_P_Awake_Diag_Actv_Awake_Diag_Actv ((DC_BOOL)FALSE)
#  define Rte_InitValue_P_Awake_Ignition_On_Awake_Ignition_On ((DC_BOOL)FALSE)
#  define Rte_InitValue_P_WakeupRsn_MPC_WakeupRsn_MPC ((c08_WakeupRsn_MPC)255u)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CP_AP_ModeManager_R_Ign_Stat_Ign_Stat(P2VAR(REC_Ign_Stat_b0ko81o0x5jgvwtduf99gvzi0, AUTOMATIC, RTE_CP_AP_MODEMANAGER_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CP_AP_ModeManager_P_Awake_Diag_Actv_Awake_Diag_Actv(DC_BOOL data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CP_AP_ModeManager_P_Awake_Ignition_On_Awake_Ignition_On(DC_BOOL data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CP_AP_ModeManager_P_WakeupRsn_MPC_WakeupRsn_MPC(c08_WakeupRsn_MPC data);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_Ign_Stat_Ign_Stat Rte_Read_CP_AP_ModeManager_R_Ign_Stat_Ign_Stat


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_Awake_Diag_Actv_Awake_Diag_Actv Rte_Write_CP_AP_ModeManager_P_Awake_Diag_Actv_Awake_Diag_Actv
#  define Rte_Write_P_Awake_Ignition_On_Awake_Ignition_On Rte_Write_CP_AP_ModeManager_P_Awake_Ignition_On_Awake_Ignition_On
#  define Rte_Write_P_WakeupRsn_MPC_WakeupRsn_MPC Rte_Write_CP_AP_ModeManager_P_WakeupRsn_MPC_WakeupRsn_MPC


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SessionCtrlType);
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DCMServices_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetRequestedComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode);
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_UR_ComMUser_CHASSIS_GetRequestedComMode(arg1) (ComM_GetRequestedComMode((ComM_UserHandleType)0, arg1))
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode);
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_UR_ComMUser_CHASSIS_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1))


# endif /* !defined(RTE_CORE) */
#endif

# define RTE_START_SEC_CP_AP_MODEMANAGER_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_CP_AP_MODEMANAGER_APPL_CODE) RE_CT_ModeManager_MainFct(void);

# define RTE_STOP_SEC_CP_AP_MODEMANAGER_APPL_CODE
# include "MemMap.h"

#ifndef FR_BUS_ARCHT_STAR_1

# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION (2u)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1u)

#  define RTE_E_DCMServices_E_NOT_OK (1u)
# endif /* !defined(RTE_CORE) */
#endif
# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_CP_AP_MODEMANAGER_H */
