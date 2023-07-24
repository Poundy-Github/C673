/**
 * \file
 *
 * \brief AUTOSAR WdgM
 *
 * This file contains the implementation of the AUTOSAR
 * module WdgM.
 *
 * \version 6.2.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef WDGM_CFG_H
#define WDGM_CFG_H

/*==================[includes]===================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,3 */
#include <WdgM_Callouts.h>                                                /* WdgM's callout APIs */

/*==================[macros]=====================================================================*/

/* ***************** Symbolic name values ****************************************************** */

/* List of watchdog modes */

#if (defined WdgMConf_WdgMMode_WDGM_NORMAL_OPERATION)
#error WdgMConf_WdgMMode_WDGM_NORMAL_OPERATION is already defined
#endif
/** \brief Export symbolic name value for watchdog mode */
#define WdgMConf_WdgMMode_WDGM_NORMAL_OPERATION 0U

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WDGM_NORMAL_OPERATION)
#error WdgM_WDGM_NORMAL_OPERATION is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WDGM_NORMAL_OPERATION 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined WdgMConf_WdgMMode_WDGM_SLEEP)
#error WdgMConf_WdgMMode_WDGM_SLEEP is already defined
#endif
/** \brief Export symbolic name value for watchdog mode */
#define WdgMConf_WdgMMode_WDGM_SLEEP 1U

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WDGM_SLEEP)
#error WdgM_WDGM_SLEEP is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WDGM_SLEEP 1U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* List of supervised entities and its checkpoints*/

#if (defined WdgMConf_WdgMSupervisedEntity_WdgM_SE_AS_HM)
#error WdgMConf_WdgMSupervisedEntity_WdgM_SE_AS_HM is already defined
#endif
/** \brief Export symbolic name value for supervised entity with ID 0 */
#define WdgMConf_WdgMSupervisedEntity_WdgM_SE_AS_HM 0U
/* Checkpoints symbolic names are defined by RTE in Rte_WdgM_Type.h when ASR40 service is used */

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgM_SE_AS_HM)
#error WdgM_WdgM_SE_AS_HM is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgM_SE_AS_HM 0U
/* List of checkpoints of this supervised entities*/

#if (defined WdgM_WdgMCheckpoint_AS_HM)
#error WdgM_WdgMCheckpoint_AS_HM is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMCheckpoint_AS_HM 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined WdgMConf_WdgMSupervisedEntity_WdgM_SE_SWC_MONITOR)
#error WdgMConf_WdgMSupervisedEntity_WdgM_SE_SWC_MONITOR is already defined
#endif
/** \brief Export symbolic name value for supervised entity with ID 1 */
#define WdgMConf_WdgMSupervisedEntity_WdgM_SE_SWC_MONITOR 1U
/* Checkpoints symbolic names are defined by RTE in Rte_WdgM_Type.h when ASR40 service is used */

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgM_SE_SWC_MONITOR)
#error WdgM_WdgM_SE_SWC_MONITOR is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgM_SE_SWC_MONITOR 1U
/* List of checkpoints of this supervised entities*/

#if (defined WdgM_WdgMCheckpoint_SWC_MONITOR)
#error WdgM_WdgMCheckpoint_SWC_MONITOR is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMCheckpoint_SWC_MONITOR 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined WdgMConf_WdgMSupervisedEntity_WdgM_SE_CameraTemp)
#error WdgMConf_WdgMSupervisedEntity_WdgM_SE_CameraTemp is already defined
#endif
/** \brief Export symbolic name value for supervised entity with ID 2 */
#define WdgMConf_WdgMSupervisedEntity_WdgM_SE_CameraTemp 2U
/* Checkpoints symbolic names are defined by RTE in Rte_WdgM_Type.h when ASR40 service is used */

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgM_SE_CameraTemp)
#error WdgM_WdgM_SE_CameraTemp is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgM_SE_CameraTemp 2U
/* List of checkpoints of this supervised entities*/

#if (defined WdgM_WdgMCheckpoint_CameraTemp)
#error WdgM_WdgMCheckpoint_CameraTemp is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMCheckpoint_CameraTemp 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined WdgMConf_WdgMSupervisedEntity_WdgM_SE_ConfigReg)
#error WdgMConf_WdgMSupervisedEntity_WdgM_SE_ConfigReg is already defined
#endif
/** \brief Export symbolic name value for supervised entity with ID 3 */
#define WdgMConf_WdgMSupervisedEntity_WdgM_SE_ConfigReg 3U
/* Checkpoints symbolic names are defined by RTE in Rte_WdgM_Type.h when ASR40 service is used */

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgM_SE_ConfigReg)
#error WdgM_WdgM_SE_ConfigReg is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgM_SE_ConfigReg 3U
/* List of checkpoints of this supervised entities*/

#if (defined WdgM_WdgMCheckpoint_ConfigReg)
#error WdgM_WdgMCheckpoint_ConfigReg is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMCheckpoint_ConfigReg 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_MAIN)
#error WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_MAIN is already defined
#endif
/** \brief Export symbolic name value for supervised entity with ID 4 */
#define WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_MAIN 4U
/* Checkpoints symbolic names are defined by RTE in Rte_WdgM_Type.h when ASR40 service is used */

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgM_SE_FS_MAIN)
#error WdgM_WdgM_SE_FS_MAIN is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgM_SE_FS_MAIN 4U
/* List of checkpoints of this supervised entities*/

#if (defined WdgM_WdgMCheckpoint_FS_MAIN)
#error WdgM_WdgMCheckpoint_FS_MAIN is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMCheckpoint_FS_MAIN 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_ADC)
#error WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_ADC is already defined
#endif
/** \brief Export symbolic name value for supervised entity with ID 5 */
#define WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_ADC 5U
/* Checkpoints symbolic names are defined by RTE in Rte_WdgM_Type.h when ASR40 service is used */

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgM_SE_FS_ADC)
#error WdgM_WdgM_SE_FS_ADC is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgM_SE_FS_ADC 5U
/* List of checkpoints of this supervised entities*/

#if (defined WdgM_WdgMCheckpoint_FS_ADC)
#error WdgM_WdgMCheckpoint_FS_ADC is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMCheckpoint_FS_ADC 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* List of watchdog devices */

#if (defined WdgMConf_WdgMWatchdog_WdgMWatchdog_0)
#error WdgMConf_WdgMWatchdog_WdgMWatchdog_0 is already defined
#endif
/** \brief Export symbolic name value for watchdog mode */
#define WdgMConf_WdgMWatchdog_WdgMWatchdog_0 0U

#if (defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined WdgM_WdgMWatchdog_0)
#error WdgM_WdgMWatchdog_0 is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 * (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define WdgM_WdgMWatchdog_0 0U
#endif /* defined WDGM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* !LINKSTO WDGM.ASR40.WDGM104,1 */
/* ***************** ASR specific macros ******************************************************* */

#if (defined WDGM_DEV_ERROR_DETECT)
#error WDGM_DEV_ERROR_DETECT already defined
#endif
/** \brief Macro for DET usage */
#define WDGM_DEV_ERROR_DETECT STD_ON

#if (defined WDGM_VERSION_INFO_API)
#error WDGM_VERSION_INFO_API already defined
#endif
/** \brief Macro for DET usage */
#define WDGM_VERSION_INFO_API STD_OFF

#if (defined WDGM_DEM_ALIVE_SUPERVISION_REPORT)
#error WDGM_DEM_ALIVE_SUPERVISION_REPORT already defined
#endif
/** \brief reporting to diagnostic event manager **/
#define WDGM_DEM_ALIVE_SUPERVISION_REPORT STD_OFF

#if (defined WDGM_IMMEDIATE_RESET)
#error WDGM_IMMEDIATE_RESET already defined
#endif
/** \brief immediate MCU reset in case of alive-supervision failure */
#define WDGM_IMMEDIATE_RESET STD_ON

#if (defined WDGM_OFF_MODE_ENABLED)
#error WDGM_OFF_MODE_ENABLED already defined
#endif
/** \brief "off mode" enabled/disabled */
#define WDGM_OFF_MODE_ENABLED STD_ON

#if (defined WDGM_DEFENSIVE_BEHAVIOR)
#error WDGM_DEFENSIVE_BEHAVIOR already defined
#endif
/** \brief availability of Rte */
#define WDGM_DEFENSIVE_BEHAVIOR STD_OFF

#if (defined WDGM_PARTITION_RESET)
#error WDGM_PARTITION_RESET already defined
#endif
/** \brief Partition reset in case of a supervision failure */
#define WDGM_PARTITION_RESET STD_OFF

/* ***************** General EB specific macros ************************************************ */

#if (defined WDGM_EB_WDG_INST_NUM)
#error WDGM_EB_WDG_INST_NUM already defined
#endif
/** \brief Number of watchdog drivers */
#define WDGM_EB_WDG_INST_NUM 1U

#if (defined WDGM_EB_CALLERIDS_NUM)
#error WDGM_EB_CALLERIDS_NUM already defined
#endif
/** \brief Number of caller IDs */
#define WDGM_EB_CALLERIDS_NUM 0U

#if (defined WDGM_EB_MODE_NUM)
#error WDGM_EB_MODE_NUM already defined
#endif
/** \brief Number of watchdog modes */
#define WDGM_EB_MODE_NUM 2U

#if (defined WDGM_EB_INTERNAL_GRAPH_NUM)
#error WDGM_EB_INTERNAL_GRAPH_NUM already defined
#endif

/** \brief Number of graphs is sum of configured internal graphs */
#define WDGM_EB_INTERNAL_GRAPH_NUM 0U

/** \brief Number of graphs is sum of configured external graphs */
#if (defined WDGM_EB_EXTERNAL_GRAPH_NUM)
#error WDGM_EB_EXTERNAL_GRAPH_NUM already defined
#endif

/** \brief Number of graphs is sum of configured external graphs */
#define WDGM_EB_EXTERNAL_GRAPH_NUM 0U

#if (defined WDGM_EB_DM_NUM)
#error WDGM_EB_DM_NUM already defined
#endif
/** \brief Number of deadline supervision configurations */
#define WDGM_EB_DM_NUM 0U

#if (defined WDGM_CONFIG_NAME)
#error WDGM_CONFIG_NAME already defined
#endif
/** \brief Name of the data structure storing configuration data
 * A pointer to this structure must be given to WdgM_Init(). */
#define WDGM_CONFIG_NAME WdgM_Config

#if (defined WDGM_EB_SUPERVISION_DEM_EVENT_ID)
#error WDGM_EB_SUPERVISION_DEM_EVENT_ID already defined
#endif
/** \brief Supervision failure Dem event Id **/
#define WDGM_EB_SUPERVISION_DEM_EVENT_ID 

#if (defined WDGM_EB_SET_MODE_DEM_EVENT_ID)
#error WDGM_EB_SET_MODE_DEM_EVENT_ID already defined
#endif
/** \brief Mode switch failure Dem event Id **/
#define WDGM_EB_SET_MODE_DEM_EVENT_ID 

#if (defined WDGM_EB_IMPROPER_CALLER_DEM_EVENT_ID)
#error WDGM_EB_IMPROPER_CALLER_DEM_EVENT_ID already defined
#endif
/** \brief Improper caller Dem event Id **/
#define WDGM_EB_IMPROPER_CALLER_DEM_EVENT_ID 

#if (defined WDGM_EB_MF_TIMINGVIOLATION_DEM_EVENT_ID)
#error WDGM_EB_MF_TIMINGVIOLATION_DEM_EVENT_ID already defined
#endif
/** \brief Mainfunction timing violation Dem event Id **/
#define WDGM_EB_MF_TIMINGVIOLATION_DEM_EVENT_ID 

#if (defined WDGM_EB_DATA_CORRUPTION_DEM_EVENT_ID)
#error WDGM_EB_DATA_CORRUPTION_DEM_EVENT_ID already defined
#endif
/** \brief Data corruption Dem event Id **/
#define WDGM_EB_DATA_CORRUPTION_DEM_EVENT_ID 
#if (defined WDGM_EB_ENABLE_SETMODE_SYNCHRON)
#error WDGM_EB_ENABLE_SETMODE_SYNCHRON already defined
#endif
/** \brief This macro enable WdgM_SetMode synchronously switch to the new mode. **/
#define WDGM_EB_ENABLE_SETMODE_SYNCHRON STD_OFF

#if (defined WDGM_EB_GET_ALL_EXPIRED_SE)
#error WDGM_EB_GET_ALL_EXPIRED_SE already defined
#endif
/** \brief This macro enables the possibility to retrieve all the expired supervised entities **/
#define WDGM_EB_GET_ALL_EXPIRED_SE STD_OFF

#if (defined WDGM_PROD_ERR_REP_TO_DEM)
#error WDGM_PROD_ERR_REP_TO_DEM already defined
#endif

/** \brief definition of production error reporting defines - report to Dem
 *
 * The production error reporting could be configured to Dem, Det and off.
 * WDGM_PROD_ERR_REP_TO_DEM is used if the production error is reported
 * towards the Dem.
 */
#define WDGM_PROD_ERR_REP_TO_DEM 0U

#if (defined WDGM_PROD_ERR_REP_TO_DET)
#error WDGM_PROD_ERR_REP_TO_DET already defined
#endif

/** \brief definition of production error reporting defines - report to Det
 *
 * The production error reporting could be configured to Dem, Det and off.
 * WDGM_PROD_ERR_REP_TO_DET is used if the production error is reported
 * towards the Det.
 */
#define WDGM_PROD_ERR_REP_TO_DET 1U

#if (defined WDGM_PROD_ERR_DISABLE)
#error WDGM_PROD_ERR_DISABLE already defined
#endif

/** \brief definition of production error reporting defines - off
 *
 * The production error reporting could be configured to Dem, Det and off.
 * WDGM_PROD_ERR_DISABLE is used if the production error reporting is
 * switched off.
 */
#define WDGM_PROD_ERR_DISABLE 2U

#if (defined WDGM_TRIGGER_WDG_DRIVER_MULTICORE_ENABLED)
#error WDGM_TRIGGER_WDG_DRIVER_MULTICORE_ENABLED already defined
#endif
/** \brief This macro enables the possibility to trigger Wdg driver from slave instance **/
#define WDGM_TRIGGER_WDG_DRIVER_MULTICORE_ENABLED STD_OFF

/* ***************** EB specific macros regarding enhancements ********************************* */




/*------------------[Defensive programming]---------------------------------*/

#if (defined WDGM_DEFENSIVE_PROGRAMMING_ENABLED)
#error WDGM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define WDGM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined WDGM_PRECONDITION_ASSERT_ENABLED)
#error WDGM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define WDGM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined WDGM_POSTCONDITION_ASSERT_ENABLED)
#error WDGM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define WDGM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined WDGM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error WDGM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define WDGM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined WDGM_INVARIANT_ASSERT_ENABLED)
#error WDGM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define WDGM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined WDGM_STATIC_ASSERT_ENABLED)
#error WDGM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define WDGM_STATIC_ASSERT_ENABLED           STD_OFF



/*------------------[ASR compatibility flags]----------------------------------------------------*/

#if (defined WDGM_EB_BSW_COMPATIBILITY_ASR32)
#error WDGM_EB_BSW_COMPATIBILITY_ASR32 already defined
#endif
/** \brief Definition that the syntax of the WdgM BSW APIs are AUTOSAR 3.2 compliant **/
#define WDGM_EB_BSW_COMPATIBILITY_ASR32 32U

#if (defined WDGM_EB_BSW_COMPATIBILITY_ASR40)
#error WDGM_EB_BSW_COMPATIBILITY_ASR40 already defined
#endif
/** \brief Definition that the syntax of the WdgM BSW APIs are AUTOSAR 4.0 compliant **/
#define WDGM_EB_BSW_COMPATIBILITY_ASR40 40U

#if (defined WDGM_EB_BSW_COMPATIBILITY_ASR43)
#error WDGM_EB_BSW_COMPATIBILITY_ASR43 already defined
#endif
/** \brief Definition that the syntax of the WdgM BSW APIs are AUTOSAR 4.3 compliant **/
#define WDGM_EB_BSW_COMPATIBILITY_ASR43 43U

#if (defined WDGM_EB_BSW_COMPATIBILITY)
#error WDGM_EB_BSW_COMPATIBILITY already defined
#endif
/** \brief Definition of WdgM BSW API Compatibility mode **/
#define WDGM_EB_BSW_COMPATIBILITY                          WDGM_EB_BSW_COMPATIBILITY_ASR40

#if (defined WDGM_EB_SERVICE_API_NONE)
#error WDGM_EB_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no default service API is set **/
#define WDGM_EB_SERVICE_API_NONE   0U

#if (defined WDGM_EB_SERVICE_API_ASR32)
#error WDGM_EB_SERVICE_API_ASR32 already defined
#endif
/** \brief Definition that AUTOSAR 3.2 service API is set as default **/
#define WDGM_EB_SERVICE_API_ASR32 32U

#if (defined WDGM_EB_SERVICE_API_ASR40)
#error WDGM_EB_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default **/
#define WDGM_EB_SERVICE_API_ASR40 40U

#if (defined WDGM_EB_SERVICE_API_ASR43)
#error WDGM_EB_SERVICE_API_ASR43 already defined
#endif
/** \brief Definition that AUTOSAR 4.3 service API is set as default **/
#define WDGM_EB_SERVICE_API_ASR43 43U

#if (defined WDGM_EB_ENABLE_ASR32_SERVICE_API)
#error WDGM_EB_ENABLE_ASR32_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 3.2 service API for WdgM is enabled **/
#define WDGM_EB_ENABLE_ASR32_SERVICE_API                   STD_OFF

#if (defined WDGM_EB_ENABLE_ASR40_SERVICE_API)
#error WDGM_EB_ENABLE_ASR40_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.0 service API for WdgM is enabled **/
#define WDGM_EB_ENABLE_ASR40_SERVICE_API                   STD_OFF

#if (defined WDGM_EB_ENABLE_ASR43_SERVICE_API)
#error WDGM_EB_ENABLE_ASR43_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.3 service API for WdgM is enabled **/
#define WDGM_EB_ENABLE_ASR43_SERVICE_API                   STD_OFF

#if (defined WDGM_EB_DEFAULT_ASR_SERVICE_API)
#error WDGM_EB_DEFAULT_ASR_SERVICE_API already defined
#endif
/** \brief Definition of default service API **/
#define WDGM_EB_DEFAULT_ASR_SERVICE_API                    WDGM_EB_SERVICE_API_ASR40

#if (defined WDGM_EB_ENABLE_ASR32_ACTALIVESUPERV_API)
#error WDGM_EB_ENABLE_ASR32_ACTALIVESUPERV_API already defined
#endif
/** \brief Definition whether AUTOSAR 3.2 service API ActivateAliveSupervision is provided **/
#define WDGM_EB_ENABLE_ASR32_ACTALIVESUPERV_API            STD_OFF

#if (defined WDGM_EB_ASR32_ACTALIVESUPERV_API)
#error WDGM_EB_ASR32_ACTALIVESUPERV_API already defined
#endif
/** \brief Definition of callout API for AUTOSAR 3.2 service API ActivateAliveSupervision **/
#define WDGM_EB_ASR32_ACTALIVESUPERV_API                   

#if (defined WDGM_EB_ENABLE_ASR32_DEACTALIVESUPERV_API)
#error WDGM_EB_ENABLE_ASR32_DEACTALIVESUPERV_API already defined
#endif
/** \brief Definition whether AUTOSAR 3.2 service API DeactivateAliveSupervision is provided **/
#define WDGM_EB_ENABLE_ASR32_DEACTALIVESUPERV_API          STD_OFF

#if (defined WDGM_EB_ASR32_DEACTALIVESUPERV_API)
#error WDGM_EB_ASR32_DEACTALIVESUPERV_API already defined
#endif
/** \brief Definition of callout API for AUTOSAR 3.2 service API ActivateAliveSupervision **/
#define WDGM_EB_ASR32_DEACTALIVESUPERV_API                 

/*------------------[Error reporting flags]------------------------------------------------------*/

#if (defined WDGM_EB_PROD_ERR_HANDLING_SUPERVISION)
#error WDGM_EB_PROD_ERR_HANDLING_SUPERVISION already defined
#endif
/** \brief Switch for DEM to DET reporting */
#define WDGM_EB_PROD_ERR_HANDLING_SUPERVISION WDGM_PROD_ERR_DISABLE


#if (defined WDGM_EB_PROD_ERR_HANDLING_SET_MODE)
#error WDGM_EB_PROD_ERR_HANDLING_SET_MODE already defined
#endif
/** \brief Switch for DEM to DET reporting */
#define WDGM_EB_PROD_ERR_HANDLING_SET_MODE                 WDGM_PROD_ERR_DISABLE

#if (defined WDGM_EB_PROD_ERR_HANDLING_IMPROPER_CALLER)
#error WDGM_EB_PROD_ERR_HANDLING_IMPROPER_CALLER already defined
#endif
/** \brief Switch for DEM to DET reporting */
#define WDGM_EB_PROD_ERR_HANDLING_IMPROPER_CALLER          WDGM_PROD_ERR_DISABLE

#if (defined WDGM_EB_PROD_ERR_HANDLING_MF_TIMINGVIOLATION)
#error WDGM_EB_PROD_ERR_HANDLING_MF_TIMINGVIOLATION already defined
#endif
/** \brief Switch for DEM to DET reporting */
#define WDGM_EB_PROD_ERR_HANDLING_MF_TIMINGVIOLATION       WDGM_PROD_ERR_DISABLE

#if (defined WDGM_EB_PROD_ERR_HANDLING_DATA_CORRUPTION)
#error WDGM_EB_PROD_ERR_HANDLING_DATA_CORRUPTION already defined
#endif
/** \brief Switch for DEM to DET reporting */
#define WDGM_EB_PROD_ERR_HANDLING_DATA_CORRUPTION          WDGM_PROD_ERR_DISABLE


/*------------------[TimEPM specific flags]------------------------------------------------------*/

#if (defined WDGM_EB_ENABLE_SUPERVISOR_CALLOUTS)
#error WDGM_EB_ENABLE_SUPERVISOR_CALLOUTS already defined
#endif
/** \brief Definition whether WdgM shall poll information from the Supervisor. **/
#define WDGM_EB_ENABLE_SUPERVISOR_CALLOUTS                 STD_OFF

#if (defined WDGM_EB_EXT_GET_EXPECTED_INIT_STATE_ENABLED)
#error WDGM_EB_EXT_GET_EXPECTED_INIT_STATE_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_GET_EXPECTED_INIT_STATE_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_GET_EXPECTED_INIT_STATE)
#error WDGM_EB_EXT_GET_EXPECTED_INIT_STATE already defined
#endif
/** \brief Name of the external callout API for getting the expected (de-)init state */
#define WDGM_EB_EXT_GET_EXPECTED_INIT_STATE 

#if (defined WDGM_EB_EXT_INIT_REDIRCALLOUT_ENABLED)
#error WDGM_EB_EXT_INIT_REDIRCALLOUT_ENABLED already defined
#endif
/** \brief Defines whether a call to WdgM_Init shall be redirected to a different API. */
#define WDGM_EB_EXT_INIT_REDIRCALLOUT_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_INIT_REDIRCALLOUT)
#error WDGM_EB_EXT_INIT_REDIRCALLOUT already defined
#endif
/** \brief Name of the API used for redirecting a call to WdgM_Init */
#define WDGM_EB_EXT_INIT_REDIRCALLOUT 

#if (defined WDGM_EB_EXT_DEINIT_REDIRCALLOUT_ENABLED)
#error WDGM_EB_EXT_DEINIT_REDIRCALLOUT_ENABLED already defined
#endif
/** \brief Defines whether a call to WdgM_DeInit shall be redirected to a different API. */
#define WDGM_EB_EXT_DEINIT_REDIRCALLOUT_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_DEINIT_REDIRCALLOUT)
#error WDGM_EB_EXT_DEINIT_REDIRCALLOUT already defined
#endif
/** \brief Name of the API used for redirecting a call to WdgM_DeInit */
#define WDGM_EB_EXT_DEINIT_REDIRCALLOUT 

#if (defined WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE_ENABLED)
#error WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE)
#error WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE already defined
#endif
/** \brief Name of the external callout API for getting the expected WdgM mode */
#define WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE 

#if (defined WDGM_EB_EXT_SETMODE_REDIRCALLOUT_ENABLED)
#error WDGM_EB_EXT_SETMODE_REDIRCALLOUT_ENABLED already defined
#endif
/** \brief Defines whether a call to WdgM_SetMode shall be redirected to a different API. */
#define WDGM_EB_EXT_SETMODE_REDIRCALLOUT_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_SETMODE_REDIRCALLOUT)
#error WDGM_EB_EXT_SETMODE_REDIRCALLOUT already defined
#endif
/** \brief Name of the API used for redirecting a call to WdgM_SetMode */
#define WDGM_EB_EXT_SETMODE_REDIRCALLOUT 

#if (defined WDGM_EB_EXT_GET_TIME_ENABLED)
#error WDGM_EB_EXT_GET_TIME_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_GET_TIME_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_GET_TIME)
#error WDGM_EB_EXT_GET_TIME already defined
#endif
/** \brief Name of the external callout API for retrieving the actual timer ticks */
#define WDGM_EB_EXT_GET_TIME 

#if (defined WDGM_EB_EXT_MAINFUNCTION_VIOLATION_ENABLED)
#error WDGM_EB_EXT_MAINFUNCTION_VIOLATION_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_MAINFUNCTION_VIOLATION_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_MAINFUNCTION_VIOLATION)
#error WDGM_EB_EXT_MAINFUNCTION_VIOLATION already defined
#endif
/** \brief Name of the external callout API for indicating a violation of main function schedule time */
#define WDGM_EB_EXT_MAINFUNCTION_VIOLATION 

#if (defined WDGM_EB_EXT_IS_PERFORM_RESET_ENABLED)
#error WDGM_EB_EXT_IS_PERFORM_RESET_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_IS_PERFORM_RESET_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_IS_PERFORM_RESET)
#error WDGM_EB_EXT_IS_PERFORM_RESET already defined
#endif
/** \brief Name of the external callout API for retrieving the actual timer ticks */
#define WDGM_EB_EXT_IS_PERFORM_RESET 

#if (defined WDGM_EB_EXT_SUPERVISION_EXPIRED_ENABLED)
#error WDGM_EB_EXT_SUPERVISION_EXPIRED_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_SUPERVISION_EXPIRED_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_SUPERVISION_EXPIRED)
#error WDGM_EB_EXT_SUPERVISION_EXPIRED already defined
#endif
/** \brief Name of the external callout API for retrieving the actual timer ticks */
#define WDGM_EB_EXT_SUPERVISION_EXPIRED 

#if (defined WDGM_EB_EXT_INDIVIDUAL_MODE_SWITCH_ENABLED)
#error WDGM_EB_EXT_INDIVIDUAL_MODE_SWITCH_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_INDIVIDUAL_MODE_SWITCH_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_INDIVIDUAL_MODE_SWITCH)
#error WDGM_EB_EXT_INDIVIDUAL_MODE_SWITCH already defined
#endif
/** \brief Name of the external callout API for retrieving the actual timer ticks */
#define WDGM_EB_EXT_INDIVIDUAL_MODE_SWITCH 

#if (defined WDGM_EB_EXT_GLOBAL_MODE_SWITCH_ENABLED)
#error WDGM_EB_EXT_GLOBAL_MODE_SWITCH_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_GLOBAL_MODE_SWITCH_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_GLOBAL_MODE_SWITCH)
#error WDGM_EB_EXT_GLOBAL_MODE_SWITCH already defined
#endif
/** \brief Name of the external callout API for retrieving the actual timer ticks */
#define WDGM_EB_EXT_GLOBAL_MODE_SWITCH 

#if (defined WDGM_EB_EXT_DET_ENABLED)
#error WDGM_EB_EXT_DET_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_DET_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_DET)
#error WDGM_EB_EXT_DET already defined
#endif
/** \brief Name of the external callout API for retrieving the actual timer ticks */
#define WDGM_EB_EXT_DET 

#if (defined WDGM_EXT_GET_CORE_ID_ENABLED)
#error WDGM_EXT_GET_CORE_ID_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EXT_GET_CORE_ID_ENABLED STD_OFF

#if (defined WDGM_EXT_GET_CORE_ID)
#error WDGM_EXT_GET_CORE_ID already defined
#endif
/** \brief Name of the external callout API for retrieving the core Id */
#define WDGM_EXT_GET_CORE_ID() ((WdgM_EB_CoreIdType)GetCoreID())

#if (defined WDGM_EB_EXT_REQUEST_PARTITION_RESET_ENABLED)
#error WDGM_EB_EXT_REQUEST_PARTITION_RESET_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_REQUEST_PARTITION_RESET_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_REQUEST_PARTITION_RESET)
#error WDGM_EB_EXT_REQUEST_PARTITION_RESET already defined
#endif
/** \brief Name of the external callout API for requesting a partition reset */
#define WDGM_EB_EXT_REQUEST_PARTITION_RESET 

#if (defined WDGM_EB_EXT_GET_APPLICATION_STATE_ENABLED)
#error WDGM_EB_EXT_GET_APPLICATION_STATE_ENABLED already defined
#endif
/** \brief Defines whether an extern callout API shall be called. */
#define WDGM_EB_EXT_GET_APPLICATION_STATE_ENABLED STD_OFF

#if (defined WDGM_EB_EXT_GET_APPLICATION_STATE)
#error WDGM_EB_EXT_GET_APPLICATION_STATE already defined
#endif
/** \brief Name of the external callout API for retrieving the state of an Os application. */
#define WDGM_EB_EXT_GET_APPLICATION_STATE 

#if (defined WDGM_EB_PARTITIONING_ENABLED)
#error WDGM_EB_PARTITIONING_ENABLED already defined
#endif
/** \brief Definition whether memory partitioning is used or not **/
#define WDGM_EB_PARTITIONING_ENABLED STD_OFF

#if (defined WDGM_EB_DM_TIMEGRANULARITY)
#error WDGM_EB_DM_TIMEGRANULARITY already defined
#endif
/** \brief Real-time granularity in micro seconds for external GetElapsedTime API.
 * Equals 0 if Deadline Monitoring is not used. */
#define WDGM_EB_DM_TIMEGRANULARITY 1000000UL

#if (defined WDGM_EB_DM_MAINFUNCTIONCYCLETIME)
#error WDGM_EB_DM_MAINFUNCTIONCYCLETIME already defined
#endif
/** \brief Time units between two Main Function calls in granularity stated in
 * macro WDGM_EB_DM_TIMEGRANULARITY.
 * Equals 0 if Deadline Monitoring is not used. */
#define WDGM_EB_DM_MAINFUNCTIONCYCLETIME 0U

#if (defined WDGM_EB_DM_MAINFUNCTIONTOLERANCETIME)
#error WDGM_EB_DM_MAINFUNCTIONTOLERANCETIME already defined
#endif
/** \brief Tolerance time which is allowed between two Main Function calls.
 * The time unit is with respect to the value of macro WDGM_EB_DM_TIMEGRANULARITY.
 * Equals 0 if Deadline Monitoring is not used. */
#define WDGM_EB_DM_MAINFUNCTIONTOLERANCETIME 0U

/*------------------[WdgM Multi-Core implementation macros]-----------------------*/

#if (defined WDGM_EB_MULTICORE_ENABLED)
#error WDGM_EB_MULTICORE_ENABLED already defined
#endif

/** \brief Preprocessor macro verifying if the multicore functionality is enabled. */
#define WDGM_EB_MULTICORE_ENABLED STD_ON

#if (defined WDGM_EB_NUMBER_OF_CORES)
#error WDGM_EB_NUMBER_OF_CORES  already defined
#endif
/* !LINKSTO WDGM.EB.TIMEPM.WDGM020111_Conf,1 */
/** \brief Preprocessor macro defining the number of cores configured. */
#define WDGM_EB_NUMBER_OF_CORES  2U

#if (defined WDGM_EB_MASTER_INSTANCE)
#error WDGM_EB_MASTER_INSTANCE already defined
#endif
/* !LINKSTO WDGM.EB.TIMEPM.WDGM020113_Conf,1 */
/** \brief Preprocessor macro defining the core configured as master core. */
#define WDGM_EB_MASTER_INSTANCE 0U

#if (defined WDGM_EB_MASTER_WAIT_SLAVE_MODE_SWITCH)
#error WDGM_EB_MASTER_WAIT_SLAVE_MODE_SWITCH already defined
#endif
/* !LINKSTO WDGM.EB.TIMEPM.WDGM020119_Conf,1 */
/** \brief   Preprocessor macro that defines the amount of time the WdgM Master Instance
* shall wait until WdgM Satellite Instances finish the mode switch or initialization.
* Unit: Number of master main function. */
#define WDGM_EB_MASTER_WAIT_SLAVE_MODE_SWITCH 0U

#if (defined WDGM_EB_SE_NUM)
#error WDGM_EB_SE_NUM already defined
#endif
/** \brief Overall number of supervised entities */
#define WDGM_EB_SE_NUM 6U

#if (defined WDGM_EB_SE_NUM_CORE0)
#error WDGM_EB_SE_NUM_CORE0 already defined
#endif
/** \brief Number of supervised entities per core */
#define WDGM_EB_SE_NUM_CORE0 5U

#if (defined WDGM_EB_SE_NUM_CORE1)
#error WDGM_EB_SE_NUM_CORE1 already defined
#endif
/** \brief Number of supervised entities per core */
#define WDGM_EB_SE_NUM_CORE1 1U

#if (defined WDGM_EB_CHECKPOINTS_NUM)
#error WDGM_EB_CHECKPOINTS_NUM already defined
#endif
/** \brief Overall number of configured checkpoints */
#define WDGM_EB_CHECKPOINTS_NUM 6U

#if (defined WDGM_EB_CHECKPOINTS_NUM_CORE0)
#error WDGM_EB_CHECKPOINTS_NUM_CORE0 already defined
#endif
/** \brief Number of configured checkpoints per core */
#define WDGM_EB_CHECKPOINTS_NUM_CORE0 5U

#if (defined WDGM_EB_CHECKPOINTS_NUM_CORE1)
#error WDGM_EB_CHECKPOINTS_NUM_CORE1 already defined
#endif
/** \brief Number of configured checkpoints per core */
#define WDGM_EB_CHECKPOINTS_NUM_CORE1 1U

#if (defined WDGM_EB_GET_MASTER_STATUS)
#error WDGM_EB_GET_MASTER_STATUS already defined
#endif
/** \brief WdgM master instance is initialized */
#define WDGM_EB_GET_MASTER_STATUS       WdgM_EB_GetMasterInitStatus()




#if (defined WDGM_EB_NUM_OS_PARTITIONS_CORE0)
#error WDGM_EB_NUM_OS_PARTITIONS_CORE0 already defined
#endif
/** \brief Number of Os partitions mapped to a WdgM Core ID. */
#define WDGM_EB_NUM_OS_PARTITIONS_CORE0 0U

#if (defined WDGM_EB_NUM_OS_PARTITIONS_CORE1)
#error WDGM_EB_NUM_OS_PARTITIONS_CORE1 already defined
#endif
/** \brief Number of Os partitions mapped to a WdgM Core ID. */
#define WDGM_EB_NUM_OS_PARTITIONS_CORE1 0U

/*------------------[Optional internal mode switch during de-initialization]---------------------*/

#if (defined WDGM_EB_DEINIT_MODE_ENABLED)
#error WDGM_EB_DEINIT_MODE_ENABLED already defined
#endif
/** \brief DeInit mode */
#define WDGM_EB_DEINIT_MODE_ENABLED STD_OFF

/*------------------[WdgM Interface version check]-----------------------------------------------*/

#if (defined WDGM_EB_STATICIF_VERSION) /* to prevent double declaration */
#error WDGM_EB_STATICIF_VERSION already defined
#endif
/* !LINKSTO WDGM.EB.TIMEPM.WDGM020202,1 */
/** \brief WdgM Static interface version */
#define WDGM_EB_STATICIF_VERSION          1

#if (defined WDGM_EB_GENIF_VERSION_REQ) /* to prevent double declaration */
#error WDGM_EB_GENIF_VERSION_REQ already defined
#endif
/* !LINKSTO WDGM.EB.TIMEPM.WDGM020203,1 */
/** \brief WdgM Generated interface version required by component WdgM Static */
#define WDGM_EB_GENIF_VERSION_REQ         1

#if (defined WDGM_EB_GENIF_VERSION_CHECK) /* to prevent double declaration */
#error WDGM_EB_GENIF_VERSION_CHECK already defined
#endif

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020204,1 */
/** \brief Interface compatibility check macro for component WdgM Generated
 *
 * \param[in] staticif_req the required interface version of WdgM Static
 * \param[in] generatedif the interface version of WdgM Generated
 *
 * \retval TRUE The two components WdgM Static and WdgM Generated are compatible
 * \retval FALSE The two components WdgM Static and WdgM Generated are not compatible
 */
#define WDGM_EB_GENIF_VERSION_CHECK(staticif_req, generatedif)   \
    ((WDGM_EB_STATICIF_VERSION >= (staticif_req)) &&             \
     (WDGM_EB_GENIF_VERSION_REQ <= (generatedif)))

/* ***************** EB specific macros regarding optimizations ******************************** */

#if (defined WDGM_EB_INCLUDE_RTE)
#error WDGM_EB_INCLUDE_RTE already defined
#endif
/** \brief availability of Rte */
#define WDGM_EB_INCLUDE_RTE STD_ON

#if (defined WDGM_EB_CALLERIDS_ENABLED)
#error WDGM_EB_CALLERIDS_ENABLED already defined
#endif
/** \brief Number of supervised entities */
#define WDGM_EB_CALLERIDS_ENABLED STD_OFF

#if (defined WDGM_EB_LOGICAL_SUPERVISION_ENABLED)
#error WDGM_EB_LOGICAL_SUPERVISION_ENABLED already defined
#endif
/** \brief Usage of logical supervision */
#if (WDGM_EB_INTERNAL_GRAPH_NUM > 0U) || (WDGM_EB_EXTERNAL_GRAPH_NUM > 0U)
#define WDGM_EB_LOGICAL_SUPERVISION_ENABLED STD_ON
#else
#define WDGM_EB_LOGICAL_SUPERVISION_ENABLED STD_OFF
#endif

#if (defined WDGM_EB_DEADLINE_SUPERVISION_ENABLED)
#error WDGM_EB_DEADLINE_SUPERVISION_ENABLED already defined
#endif
/** \brief Usage of deadline supervision */
#if (WDGM_EB_DM_NUM > 0U)
#define WDGM_EB_DEADLINE_SUPERVISION_ENABLED STD_ON
#else
#define WDGM_EB_DEADLINE_SUPERVISION_ENABLED STD_OFF
#endif

#if ((WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON) && \
     ((WDGM_EB_PROD_ERR_HANDLING_MF_TIMINGVIOLATION == WDGM_PROD_ERR_REP_TO_DEM) || \
      ((WDGM_EB_PROD_ERR_HANDLING_MF_TIMINGVIOLATION == WDGM_PROD_ERR_REP_TO_DET) && \
       (WDGM_DEV_ERROR_DETECT == STD_ON))))
/** \brief Check if MainFunction timing violations shall be detected */
#define WDGM_EB_CHECK_MAINFUNCTION_TIMING STD_ON
#else
#define WDGM_EB_CHECK_MAINFUNCTION_TIMING STD_OFF
#endif

/* ***************** EB specific macros regarding inter-core communication ******************************** */

#if (defined WDGM_EB_GET_CORE_ID)
#error WDGM_EB_GET_CORE_ID already defined
#endif
/* Internal macro for link external callout API for retrieving the core Id */
#define WDGM_EB_GET_CORE_ID() WDGM_EXT_GET_CORE_ID()

#define WDGM_INSTANCE_ID (WDGM_EB_GET_CORE_ID())

#if (defined WDGM_SID_MAIN_FUNCTION)
#error WDGM_SID_MAIN_FUNCTION already defined
#endif
/** \brief Service id of WdgM_MainFunction() */
#define WDGM_SID_MAIN_FUNCTION          0x08U

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/


/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

#endif /* ifndef WDGM_CFG_H */
/*==================[end of file]================================================================*/
