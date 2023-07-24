#ifndef BSWM_CFG_H
#define BSWM_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Cfg_h,1 */

/*==================[inclusions]============================================*/

#include <TSAutosar.h>        /* EB specific standard types*/
#include <Std_Types.h>        /* AUTOSAR standard types    */

#include <BswM_CfgTypes.h>

/*==================[type definitions]=======================================*/

/*==================[macros]=================================================*/

/* !LINKSTO BswM.Impl.BswMInstanceId,2 */
#if (defined BSWM_INSTANCE_ID)
#error BSWM_INSTANCE_ID already defined
#endif
/** \brief BswM Instance ID
 **
 ** Instance ID of the only BswM instance.
 */
#define BSWM_INSTANCE_ID 0U

/* !LINKSTO BswM.Impl.MultipleInstances.BswMInstanceId,1 */
#if (defined BSWM_OSAPPLICATION_C0_INSTANCE_ID)
#error BSWM_OSAPPLICATION_C0_INSTANCE_ID already defined
#endif
/** \brief BswM OsApplication_C0 Instance ID
 **
 ** Instance ID of the BswM instance associated with the OsApplication_C0 Os application.
 */
#define BSWM_OSAPPLICATION_C0_INSTANCE_ID 0U
#if (defined BSWM_OSAPPLICATION_C1_INSTANCE_ID)
#error BSWM_OSAPPLICATION_C1_INSTANCE_ID already defined
#endif
/** \brief BswM OsApplication_C1 Instance ID
 **
 ** Instance ID of the BswM instance associated with the OsApplication_C1 Os application.
 */
#define BSWM_OSAPPLICATION_C1_INSTANCE_ID 1U
#if (defined BSWM_OSAPPLICATION_C2_INSTANCE_ID)
#error BSWM_OSAPPLICATION_C2_INSTANCE_ID already defined
#endif
/** \brief BswM OsApplication_C2 Instance ID
 **
 ** Instance ID of the BswM instance associated with the OsApplication_C2 Os application.
 */
#define BSWM_OSAPPLICATION_C2_INSTANCE_ID 2U
#if (defined BSWM_OSAPPLICATION_C3_INSTANCE_ID)
#error BSWM_OSAPPLICATION_C3_INSTANCE_ID already defined
#endif
/** \brief BswM OsApplication_C3 Instance ID
 **
 ** Instance ID of the BswM instance associated with the OsApplication_C3 Os application.
 */
#define BSWM_OSAPPLICATION_C3_INSTANCE_ID 3U

#if (defined BSWM_DEV_ERROR_DETECT)
#error BSWM_DEV_ERROR_DETECT is already defined
#endif

#define BSWM_DEV_ERROR_DETECT STD_ON

#if (defined BSWM_VERSION_INFO_API)
#error BSWM_VERSION_INFO_API is already defined
#endif

#define BSWM_VERSION_INFO_API STD_OFF

#if (defined BSWM_QUEUED_ARBITRATION_ENABLED)
#error BSWM_QUEUED_ARBITRATION_ENABLED is already defined
#endif

#define BSWM_QUEUED_ARBITRATION_ENABLED STD_OFF

#if (defined BSWM_CANSM_API_ENABLED)
#error BSWM_CANSM_API_ENABLED is already defined
#endif

#define BSWM_CANSM_API_ENABLED STD_ON

#if (defined BSWM_COMM_API_ENABLED)
#error BSWM_COMM_API_ENABLED is already defined
#endif

#define BSWM_COMM_API_ENABLED STD_ON

#if (defined BSWM_DCM_API_ENABLED)
#error BSWM_DCM_API_ENABLED is already defined
#endif

#define BSWM_DCM_API_ENABLED STD_ON

#if (defined BSWM_ECUM_API_ENABLED)
#error BSWM_ECUM_API_ENABLED is already defined
#endif

#define BSWM_ECUM_API_ENABLED STD_ON

#if (defined BSWM_ETHIF_API_ENABLED)
#error BSWM_ETHIF_API_ENABLED is already defined
#endif

#define BSWM_ETHIF_API_ENABLED STD_OFF

#if (defined BSWM_ETHSM_API_ENABLED)
#error BSWM_ETHSM_API_ENABLED is already defined
#endif

#define BSWM_ETHSM_API_ENABLED STD_OFF

#if (defined BSWM_FRSM_API_ENABLED)
#error BSWM_FRSM_API_ENABLED is already defined
#endif

#define BSWM_FRSM_API_ENABLED STD_OFF

#if (defined BSWM_GENERIC_REQUEST_API_ENABLED)
#error BSWM_GENERIC_REQUEST_API_ENABLED is already defined
#endif

#define BSWM_GENERIC_REQUEST_API_ENABLED STD_ON

#if (defined BSWM_J1939DCM_API_ENABLED)
#error BSWM_J1939DCM_API_ENABLED is already defined
#endif

#define BSWM_J1939DCM_API_ENABLED STD_OFF

#if (defined BSWM_J1939NM_API_ENABLED)
#error BSWM_J1939NM_API_ENABLED is already defined
#endif

#define BSWM_J1939NM_API_ENABLED STD_OFF

#if (defined BSWM_LINSM_API_ENABLED)
#error BSWM_LINSM_API_ENABLED is already defined
#endif

#define BSWM_LINSM_API_ENABLED STD_OFF

#if (defined BSWM_LINTP_API_ENABLED)
#error BSWM_LINTP_API_ENABLED is already defined
#endif

#define BSWM_LINTP_API_ENABLED STD_OFF

#if (defined BSWM_NM_API_ENABLED)
#error BSWM_NM_API_ENABLED is already defined
#endif

#define BSWM_NM_API_ENABLED STD_ON

#if (defined BSWM_NVM_API_ENABLED)
#error BSWM_NVM_API_ENABLED is already defined
#endif

#define BSWM_NVM_API_ENABLED STD_OFF

#if (defined BSWM_SD_API_ENABLED)
#error BSWM_SD_API_ENABLED is already defined
#endif

#define BSWM_SD_API_ENABLED STD_OFF

#if (defined BSWM_WDGM_API_ENABLED)
#error BSWM_WDGM_API_ENABLED is already defined
#endif

#define BSWM_WDGM_API_ENABLED STD_OFF

#if (defined BSWM_DCM_LEGACY_API_ENABLED)
#error BSWM_DCM_LEGACY_API_ENABLED is already defined
#endif

#define BSWM_DCM_LEGACY_API_ENABLED STD_ON

#if (defined BSWM_IPDU_GROUP_VECTOR_SIZE)
#error BSWM_IPDU_GROUP_VECTOR_SIZE is already defined
#endif

#define BSWM_IPDU_GROUP_VECTOR_SIZE 4U

#if (defined BSWM_RTE_ENABLED)
#error BSWM_RTE_ENABLED is already defined
#endif

#define BSWM_RTE_ENABLED STD_ON

#if (defined BSWM_DEM_ENABLED)
#error BSWM_DEM_ENABLED is already defined
#endif

#define BSWM_DEM_ENABLED STD_OFF

/* Switches related to actions */

#if (defined BSWM_COM_ACTION_USED)
#error BSWM_COM_ACTION_USED is already defined
#endif

#define BSWM_COM_ACTION_USED STD_ON

#if (defined BSWM_NM_ACTION_USED)
#error BSWM_NM_ACTION_USED is already defined
#endif

#define BSWM_NM_ACTION_USED STD_ON

#if (defined BSWM_DEADLINE_MONITORING_CONTROL_ACTION_USED)
#error BSWM_DEADLINE_MONITORING_CONTROL_ACTION_USED is already defined
#endif

#define BSWM_DEADLINE_MONITORING_CONTROL_ACTION_USED STD_OFF

#if (defined BSWM_PDU_GROUP_SWITCH_ACTION_USED)
#error BSWM_PDU_GROUP_SWITCH_ACTION_USED is already defined
#endif

#define BSWM_PDU_GROUP_SWITCH_ACTION_USED STD_ON

#if (defined BSWM_SWITCH_IPDU_MODE_ACTION_USED)
#error BSWM_SWITCH_IPDU_MODE_ACTION_USED is already defined
#endif

#define BSWM_SWITCH_IPDU_MODE_ACTION_USED STD_OFF

#if (defined BSWM_TRIGGER_IPDU_SEND_ACTION_USED)
#error BSWM_TRIGGER_IPDU_SEND_ACTION_USED is already defined
#endif

#define BSWM_TRIGGER_IPDU_SEND_ACTION_USED STD_OFF

#if (defined BSWM_PDU_ROUTER_CONTROL_ACTION_USED)
#error BSWM_PDU_ROUTER_CONTROL_ACTION_USED is already defined
#endif

#define BSWM_PDU_ROUTER_CONTROL_ACTION_USED STD_OFF

#if (defined BSWM_LIN_SCHEDULE_SWITCH_ACTION_USED)
#error BSWM_LIN_SCHEDULE_SWITCH_ACTION_USED is already defined
#endif

#define BSWM_LIN_SCHEDULE_SWITCH_ACTION_USED STD_OFF

#if (defined BSWM_MAX_NUM_ACTION_LISTS)
#error BSWM_MAX_NUM_ACTION_LISTS is already defined
#endif
/** \brief The max number of action lists supported by this configuration. */
#define BSWM_MAX_NUM_ACTION_LISTS 80U

#if (defined BSWM_MAX_NUM_RULES)
#error BSWM_MAX_NUM_RULES is already defined
#endif
/** \brief The max number of rules supported by this configuration. */
#define BSWM_MAX_NUM_RULES 80U

#if (defined BSWM_RELOCATABLE_CFG_ENABLE)
#error BSWM_RELOCATABLE_CFG_ENABLE is already defined
#endif
/** \brief Determines if the post-build configuration is relocatable in memory. */
#define BSWM_RELOCATABLE_CFG_ENABLE STD_ON

#if (defined BSWM_PBCFGM_SUPPORT_ENABLED)
#error BSWM_PBCFGM_SUPPORT_ENABLED is already defined
#endif
/* !LINKSTO      BswM.Impl.PbCfgM,1 */
/* The PbcfgM support is only enabled only when the PbcfgM references the BswM. */
#define BSWM_PBCFGM_SUPPORT_ENABLED STD_ON

#if (defined BSWM_CFG_SIGNATURE)
#error BSWM_CFG_SIGNATURE is already defined
#endif

/** \brief PreCompile time verification value */
#define BSWM_CFG_SIGNATURE 662634896U

#if (defined BSWM_PUBLIC_INFO_SIGNATURE)
#error BSWM_PUBLIC_INFO_SIGNATURE is already defined
#endif

/** \brief PreCompile time Published information verification value */
#define BSWM_PUBLIC_INFO_SIGNATURE 3585052355U

#if (defined BSWM_LINIF_SCHEDULE_RANGE_CHECK)
#error BSWM_LINIF_SCHEDULE_RANGE_CHECK is already defined
#endif

#define BSWM_LINIF_SCHEDULE_RANGE_CHECK \
      (BSWM_FALSE)

#if (defined BSWM_IMPLEMENTATION_CONFIG_VARIANT)
#error BSWM_IMPLEMENTATION_CONFIG_VARIANT is already defined
#endif

/** \brief The configured implementation variant */
#define BSWM_IMPLEMENTATION_CONFIG_VARIANT BSWM_VARIANT_POST_BUILD

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_CFG_H */
/*==================[end of file]============================================*/

