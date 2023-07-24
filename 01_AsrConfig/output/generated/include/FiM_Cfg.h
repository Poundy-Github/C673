/**
 * \file
 *
 * \brief AUTOSAR FiM
 *
 * This file contains the implementation of the AUTOSAR
 * module FiM.
 *
 * \version 2.5.4
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef FIM_CFG_H
#define FIM_CFG_H

/* This file contains the generated FiM module configuration. */

                                    /*==================[includes]===============================================*/

#include <Std_Types.h>  /* AUTOSAR standard types */
#include <Dem_Types.h>

/*==================[macros]=================================================*/

#if (defined FIM_CFG_SIGNATURE)
#error FIM_CFG_SIGNATURE is already defined
#endif
/* !LINKSTO FIM.EB.Config.Id,1 */
/** \brief Sign a certain configuration with unique hash
 **/
#define FIM_CFG_SIGNATURE 975748054U

/*------------------[API configuration options]------------------------------*/

/* !LINKSTO FIM033,1 */
#if (defined FIM_VERSION_INFO_API)
#error FIM_VERSION_INFO_API already defined
#endif
/** \brief Switch, indicating if Version Info is activated for FiM */
#define FIM_VERSION_INFO_API         STD_OFF

#if (defined FIM_DEV_ERROR_DETECT)
#error FIM_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating if the detection of development errors is
 ** activated or deactivated for FiM */
#define FIM_DEV_ERROR_DETECT         STD_ON

#if (defined FIM_EVENT_UPDATE_TRIGGERED_BY_DEM)
#error FIM_EVENT_UPDATE_TRIGGERED_BY_DEM already defined
#endif
/** \brief Switch, indicating if the Event update triggered by Dem is activated or
 ** deactivated for FiM */
#define FIM_EVENT_UPDATE_TRIGGERED_BY_DEM   STD_OFF

#if (defined FIM_DATA_FIXED)
#error FIM_DATA_FIXED already defined
#endif
/* !LINKSTO dsn.FIM.Param.CalibrationSupport,1 */
/** \brief Switch, indicating if the data is fixed */
#define FIM_DATA_FIXED      STD_ON

#if (defined FIM_INCLUDE_RTE)
#error FIM_INCLUDE_RTE already defined
#endif
/** \brief Switch, indicating if RTE is activated or deactivated for FiM */
#define FIM_INCLUDE_RTE              STD_ON

#if (defined FIM_MEASURMENT_SUPPORT)
#error FIM_MEASURMENT_SUPPORT already defined
#endif
/** \brief Switch, indicating if Measurement Support is activated for FiM */
#define FIM_MEASURMENT_SUPPORT         STD_OFF

#if (defined FIM_EXTENDED_LEVEL)
#error FIM_EXTENDED_LEVEL already defined
#endif
/* !LINKSTO dsn.FIM.VCC.Param.ExtendedLevel,1 */
/** \brief Extended level can be FIM_NO_EXTENSION, FIM_EXTENSION_LVL1 or
           FIM_EXTENSION_LVL2 */
#define FIM_EXTENDED_LEVEL            FIM_NO_EXTENSION

#if (defined FIM_EXT_MAX_HIGH_PRIO_EVENT_TO_FID_LINKS)
#error FIM_EXT_MAX_HIGH_PRIO_EVENT_TO_FID_LINKS already defined
#endif
/* !LINKSTO dsn.FIM.VCC.Param.MaxHighPrioEventToFidLinks,1 */
/** \brief Defines the maximal priority for event to FID links */
#define FIM_EXT_MAX_HIGH_PRIO_EVENT_TO_FID_LINKS            0U

#if (defined FIM_EXT_MAX_HANDLED_FID_EVENT_LINKS_PER_SCHEDULING)
#error FIM_EXT_MAX_HANDLED_FID_EVENT_LINKS_PER_SCHEDULING already defined
#endif
/* !LINKSTO dsn.FIM.VCC.Param.MaxHandledFidEventLinksPerSchedule,1, dsn.FiM.VCC.Param.MaxHandledFidEventLinksPerSchedule.Value,1 */
/** \brief Defines the maximum FID event links handled per scheduling. */
#define FIM_EXT_MAX_HANDLED_FID_EVENT_LINKS_PER_SCHEDULING  0U


#if (defined FIM_MODE_POLLING_SYNC)
#error FIM_MODE_POLLING_SYNC already defined
#endif
/** \brief Define for synchronous polling mode  */
#define FIM_MODE_POLLING_SYNC       0U

#if (defined FIM_MODE_POLLING_ASYNC)
#error FIM_MODE_POLLING_ASYNC already defined
#endif
/** \brief Define for asynchronous polling mode  */
#define FIM_MODE_POLLING_ASYNC      1U

#if (defined FIM_MODE_TRIGGERED)
#error FIM_MODE_TRIGGERED already defined
#endif
/** \brief Define for triggerd mode  */
#define FIM_MODE_TRIGGERED          2U

#if (defined FIM_MODE)
#error FIM_MODE already defined
#endif
/** !LINKSTO dsn.FiM.FidCalculation.Mode,1 */
/** \brief Defines the mode how FIDs are calculated. */
#define FIM_MODE    FIM_MODE_POLLING_SYNC

#if (defined FIM_MAXIMUM_EVENT_FID_LINKS)
#error FIM_MAXIMUM_EVENT_FID_LINKS already defined
#endif
/** \brief This configuration parameter specifies the total maximum number of
 ** links between EventIds and FIDs. */
#define FIM_MAXIMUM_EVENT_FID_LINKS  65535U

#if (defined FIM_MAXIMUM_FIDS_PER_EVENT)
#error FIM_MAXIMUM_FIDS_PER_EVENT already defined
#endif
/** \brief This configuration parameter specifies the maximum number of FIDs
 ** that can be linked to a single event. */
#define FIM_MAXIMUM_FIDS_PER_EVENT   65535U

#if (defined FIM_MAXIMUM_EVENTS_PER_FID)
#error FIM_MAXIMUM_EVENTS_PER_FID already defined
#endif
/** \brief This configuration parameter specifies the maximum number of
 ** EventIds that can be linked to a single FID. */
#define FIM_MAXIMUM_EVENTS_PER_FID   255U

#if (defined FIM_MAXIMUM_SUMMARY_EVENTS)
#error FIM_MAXIMUM_SUMMARY_EVENTS already defined
#endif
/** \brief This configuration parameter specifies the maximum number of
 ** summarized events that can be configured. */
#define FIM_MAXIMUM_SUMMARY_EVENTS   65535U

#if (defined FIM_MAXIMUM_SUMMARY_LINKS)
#error FIM_MAXIMUM_SUMMARY_LINKS already defined
#endif
/** \brief This configuration parameter specifies the total maximum number of
 ** links between EventIds and summarized events. */
#define FIM_MAXIMUM_SUMMARY_LINKS    65535U

#if (defined FIM_MAXIMUM_TOTAL_LINKS)
#error FIM_MAXIMUM_TOTAL_LINKS already defined
#endif
/** \brief This configuration parameter specifies the total maximum number of
 ** links between EventIds and FIDs plus the number of links between EventIds
 ** and summarized events. */
#define FIM_MAXIMUM_TOTAL_LINKS      65535U

/*------------------[FIDs configuration]-------------------------------------*/

#if (defined FIM_FID_NUM)
#error FIM_FID_NUM already defined
#endif
/** \brief This configuration parameter specifies the total number of FIDs.
 **
 ** Calculated by number of configured FIDs including the invalid FID 0. */
#define FIM_FID_NUM    10U

#if (defined FIM_CONFIG_ACCESS)
#error FIM_CONFIG_ACCESS already defined
#endif
/** \brief This configuration parameter specifies the order of config data. */
#define FIM_CONFIG_ACCESS    FIM_CONFIG_ACCESS_FID

#if (defined FIM_FID_STARTINDEX_NUM)
#error FIM_FID_STARTINDEX_NUM already defined
#endif
/** \brief This configuration parameter specifies the total number of start indexes of FIDs.
**
** Calculated by number of configured FIDs including the invalid FID 0. */
#define FIM_FID_STARTINDEX_NUM    10U

#if (defined FIM_FID_CONFIGDATA_NUM)
#error FIM_FID_CONFIGDATA_NUM already defined
#endif
/** \brief This configuration parameter specifies the total number of FIDs.
**
** Calculated by number of configured FIDs including the invalid FID 0. */
#define FIM_FID_CONFIGDATA_NUM    301U

#if (defined FIM_EXT_CONFIG_NUM)
#error FIM_EXT_CONFIG_NUM already defined
#endif
/** \brief This configuration parameter specifies the total number of Messages.
**
** Calculated by number of configured FIDs. */
#define FIM_EXT_CONFIG_NUM        9U

#if (defined FIM_MESSAGE_MAX)
#error FIM_MESSAGE_MAX already defined
#endif
/** \brief Maximal number of messages */
#define FIM_MESSAGE_MAX   1U

/* Symbolic names of configured Function IDs */

#if (defined FiMConf_FiMFID_FID_AEB)
#error FiMConf_FiMFID_FID_AEB already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_AEB                          1U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_AEB)
#error FID_AEB already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_AEB                                         1U

#if (defined FiM_FID_AEB)
#error FiM_FID_AEB already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_AEB                                     1U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_ELK)
#error FiMConf_FiMFID_FID_ELK already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_ELK                          2U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_ELK)
#error FID_ELK already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_ELK                                         2U

#if (defined FiM_FID_ELK)
#error FiM_FID_ELK already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_ELK                                     2U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_FCW)
#error FiMConf_FiMFID_FID_FCW already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_FCW                          3U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_FCW)
#error FID_FCW already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_FCW                                         3U

#if (defined FiM_FID_FCW)
#error FiM_FID_FCW already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_FCW                                     3U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_HLA)
#error FiMConf_FiMFID_FID_HLA already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_HLA                          4U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_HLA)
#error FID_HLA already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_HLA                                         4U

#if (defined FiM_FID_HLA)
#error FiM_FID_HLA already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_HLA                                     4U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_LDW)
#error FiMConf_FiMFID_FID_LDW already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_LDW                          5U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_LDW)
#error FID_LDW already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_LDW                                         5U

#if (defined FiM_FID_LDW)
#error FiM_FID_LDW already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_LDW                                     5U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_LKA)
#error FiMConf_FiMFID_FID_LKA already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_LKA                          6U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_LKA)
#error FID_LKA already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_LKA                                         6U

#if (defined FiM_FID_LKA)
#error FiM_FID_LKA already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_LKA                                     6U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_TSA)
#error FiMConf_FiMFID_FID_TSA already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_TSA                          7U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_TSA)
#error FID_TSA already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_TSA                                         7U

#if (defined FiM_FID_TSA)
#error FiM_FID_TSA already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_TSA                                     7U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_FAB)
#error FiMConf_FiMFID_FID_FAB already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_FAB                          8U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_FAB)
#error FID_FAB already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_FAB                                         8U

#if (defined FiM_FID_FAB)
#error FiM_FID_FAB already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_FAB                                     8U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMFID_FID_U17A1F0)
#error FiMConf_FiMFID_FID_U17A1F0 already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMFID_FID_U17A1F0                      9U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined FID_U17A1F0)
#error FID_U17A1F0 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define FID_U17A1F0                                     9U

#if (defined FiM_FID_U17A1F0)
#error FiM_FID_U17A1F0 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_FID_U17A1F0                                 9U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FIM_MAX_DEM_EVENT_ID)
#error FIM_MAX_DEM_EVENT_ID already defined
#endif
/** \brief This configuration parameter specifies the largest event Id
 ** configured in Dem. */
#define FIM_MAX_DEM_EVENT_ID  139U

/*------------------[Event summaries configuration]----------------------------*/

/* Symbolic names of configured Event Summary IDs - not relevant to this implementation */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_AEB_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_AEB_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_AEB_Deactive       0U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_AEB_Deactive)
#error EVENT_SUMMARY_AEB_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_AEB_Deactive                                 0U

#if (defined FiM_EVENT_SUMMARY_AEB_Deactive)
#error FiM_EVENT_SUMMARY_AEB_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_AEB_Deactive                             0U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_ELK_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_ELK_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_ELK_Deactive       1U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_ELK_Deactive)
#error EVENT_SUMMARY_ELK_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_ELK_Deactive                                 1U

#if (defined FiM_EVENT_SUMMARY_ELK_Deactive)
#error FiM_EVENT_SUMMARY_ELK_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_ELK_Deactive                             1U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_FAB_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_FAB_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_FAB_Deactive       2U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_FAB_Deactive)
#error EVENT_SUMMARY_FAB_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_FAB_Deactive                                 2U

#if (defined FiM_EVENT_SUMMARY_FAB_Deactive)
#error FiM_EVENT_SUMMARY_FAB_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_FAB_Deactive                             2U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_FCW_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_FCW_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_FCW_Deactive       3U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_FCW_Deactive)
#error EVENT_SUMMARY_FCW_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_FCW_Deactive                                 3U

#if (defined FiM_EVENT_SUMMARY_FCW_Deactive)
#error FiM_EVENT_SUMMARY_FCW_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_FCW_Deactive                             3U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_HLA_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_HLA_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_HLA_Deactive       4U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_HLA_Deactive)
#error EVENT_SUMMARY_HLA_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_HLA_Deactive                                 4U

#if (defined FiM_EVENT_SUMMARY_HLA_Deactive)
#error FiM_EVENT_SUMMARY_HLA_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_HLA_Deactive                             4U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_LDW_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_LDW_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_LDW_Deactive       5U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_LDW_Deactive)
#error EVENT_SUMMARY_LDW_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_LDW_Deactive                                 5U

#if (defined FiM_EVENT_SUMMARY_LDW_Deactive)
#error FiM_EVENT_SUMMARY_LDW_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_LDW_Deactive                             5U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_LKA_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_LKA_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_LKA_Deactive       6U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_LKA_Deactive)
#error EVENT_SUMMARY_LKA_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_LKA_Deactive                                 6U

#if (defined FiM_EVENT_SUMMARY_LKA_Deactive)
#error FiM_EVENT_SUMMARY_LKA_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_LKA_Deactive                             6U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined FiMConf_FiMSummaryEventId_EVENT_SUMMARY_TSA_Deactive)
#error FiMConf_FiMSummaryEventId_EVENT_SUMMARY_TSA_Deactive already defined
#endif
/** \brief Export symbolic name value */
#define FiMConf_FiMSummaryEventId_EVENT_SUMMARY_TSA_Deactive       7U

#ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES
#if (defined EVENT_SUMMARY_TSA_Deactive)
#error EVENT_SUMMARY_TSA_Deactive already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EVENT_SUMMARY_TSA_Deactive                                 7U

#if (defined FiM_EVENT_SUMMARY_TSA_Deactive)
#error FiM_EVENT_SUMMARY_TSA_Deactive already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FiM_EVENT_SUMMARY_TSA_Deactive                             7U
#endif /* ifndef FIM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined FIM_FID_INVALID)
#error FIM_FID_INVALID already defined
#endif
/** \brief Invalid event symbolic name value */
#define FIM_FID_INVALID       0U

#if (defined FIM_EVENT_INVALID)
#error FIM_EVENT_INVALID already defined
#endif
/** \brief Invalid event symbolic name value */
#define FIM_EVENT_INVALID     0U

#if (defined FIM_MESSAGE_INVALID)
#error FIM_MESSAGE_INVALID already defined
#endif
/* !LINKSTO VCC-FIM-003:Req38v1,1 */
/** \brief Invalid message symbolic name value */
#define FIM_MESSAGE_INVALID   0U

/*==================[type definitions]=======================================*/

/*------------------[FiM_ConfigType]----------------------------------------*/

/** \brief This type defines a data structure for the post build
 ** parameters of the FiM
 **
 ** \note Type is unused, as only pre-compile time support is implemented. */
typedef uint8 FiM_ConfigType;

/** \brief Type of start index */
typedef uint16 FiM_IndexType;


/*--------------[ FiM 'polling mode' or 'calibration support' ]---------------*/
/* !LINKSTO dsn.FiM.StaticData,1 */

/** \brief Start index structure for FiM 'polling mode' or calibration mode */
typedef FiM_IndexType FiM_FidConfigStartIndexType;

/** \brief Config data structure for FiM 'polling mode' or calibration mode */
typedef uint16 FiM_FidConfigDataType;

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

#define FIM_START_SEC_CONST_UNSPECIFIED
#include <FiM_MemMap.h>

/** \brief Configuration structure */
extern CONST(FiM_ConfigType, FIM_CONST) FiM_Config_0;

#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include <FiM_MemMap.h>

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef FIM_CFG_H */
/*==================[end of file]============================================*/
