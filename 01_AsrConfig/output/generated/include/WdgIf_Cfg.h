/**
 * \file
 *
 * \brief AUTOSAR WdgIf
 *
 * This file contains the implementation of the AUTOSAR
 * module WdgIf.
 *
 * \version 6.2.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H
/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

#ifdef WDGIF_DEV_ERROR_DETECT
#error WDGIF_DEV_ERROR_DETECT already defined!
#endif
/** \brief Macro for DET usage */
#define WDGIF_DEV_ERROR_DETECT  STD_ON

#ifdef WDGIF_VERSION_INFO_API
#error WDGIF_VERSION_INFO_API already defined!
#endif
/** \brief En-/disable API version information */
#define WDGIF_VERSION_INFO_API  STD_OFF

/* !LINKSTO WDGIF.EB.DesignDecision.PreCompileValue1,1 */
#ifdef WDGIF_EB_NUMBER_OF_DEVICES
#error WDGIF_EB_NUMBER_OF_DEVICES already defined!
#endif
/** \brief Number of configured watchdog devices */
#define WDGIF_EB_NUMBER_OF_DEVICES 1U

#if (defined WdgIfConf_WdgIfDevice_WdgIfDevice_InChipWdg)
#error WdgIfConf_WdgIfDevice_WdgIfDevice_InChipWdg is already defined
#endif
/** \brief Export symbolic name value */
#define WdgIfConf_WdgIfDevice_WdgIfDevice_InChipWdg  0U

#if (defined WdgIf_IntSetMode)
#error WdgIf_IntSetMode is already defined
#endif
/* Internal macro for mapping Wdg_SetMode() to the underlying watchdog device */
#define WdgIf_IntSetMode(DeviceIndex,WdgMode)     Wdg_17_Scu_SetMode(WdgMode)

#if (defined WdgIf_IntTrigger)
#error WdgIf_IntTrigger is already defined
#endif
/* Internal macro for mapping Wdg_SetTriggerCondition() to the underlying watchdog device */
#define WdgIf_IntTrigger(DeviceIndex,Timeout)     Wdg_17_Scu_SetTriggerCondition(Timeout)

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef WDGIF_CFG_H */
/*==================[end of file]============================================*/
