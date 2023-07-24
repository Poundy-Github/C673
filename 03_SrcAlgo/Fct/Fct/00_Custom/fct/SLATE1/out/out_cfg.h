/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_cfg.h

DESCRIPTION:               Configuration Header File for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            Revision: 1.3

**************************************************************************** */
#ifndef OUT_CFG_H_INCLUDED
#define OUT_CFG_H_INCLUDED

#include "slate_config.h"
#if (FCT_CFG_ACC_OUTPUT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup out_cfg Configuration
@ingroup out
@brief    Contains all configuration switches related to the out subcomponent.\n\n
@{
*/
/*! Configuration switch for activating the calculation of the object meas status mapping of an object */
#define OUT_CFG_CUSTOM_MEAS_STATUS_MAPPING              (SWITCH_OFF)

/*! Configuration switch enabling the drive off monitor */
#define OUT_CFG_DRIVE_OFF_MONITOR                       (SWITCH_OFF)

/*! Configuration switch enabling the activation prevention */
#define OUT_CFG_ACTIVATION_PREVENTION                   (SWITCH_OFF)

/*! Configuration switch for activating the calculation of the engine trigger (based on start of OOI0 or OOI1) */
#define OUT_CFG_CUSTOM_ENGINE_TRIGGER                   (SWITCH_OFF)

/*! Activation of Overtake Prevention feature */
#define OUT_CFG_OVERTAKE_PREVENTION_FEATURE             (SWITCH_OFF)

/*! Configuration switch for custom provide port signal Traffic Orientation */
#define OUT_CFG_CUSTOM_TO_OUTPUT                        (SWITCH_OFF)

 /* configure the switch for ACC DriveOffMonitor (Anfahrüberwachung) radar only when Switched Off */
#define OUT_CFG_DRIVE_OFF_MONITOR_FUSED_CAM_US          (SWITCH_OFF)

 /* configure the switch for ACC column object  */
#define OUT_CFG_CUSTOM_COLUMN_OBJECT                    (SWITCH_OFF)

 /* configure the switch for ACC  object object classification type   */
#define OUT_CFG_CUSTOM_SORTED_OBJECTS                    (SWITCH_OFF)

 /* Configuration switch to activate multi object display output list  */
#define OUT_CFG_CUSTOM_HMI_OBJECTS                       FCT_CFG_DEPENDENT_SWITCH((FCT_CUSTOM_OUTPUT_INTFVER >= 54u),SWITCH_OFF)
#endif
///@}
#endif
