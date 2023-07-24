/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_TCI (Traffic Continuation Indication)

PACKAGENAME:               tci_cfg.h

DESCRIPTION:               Configuration Header File for Traffic Continuation Indication function

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             12.02.2018

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */


#ifndef TCI_CFG_H_INCLUDED
#define TCI_CFG_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/*!
@defgroup   tci_custom TCI_Custom
@ingroup    lopc_custom_lopc
@brief      Module for TCI custom files
 */

/*!
@defgroup   tci_cfg Tci_cfg
@ingroup    tci_custom
@brief      TCI Config File
@description
This module covers the configuration switches for the Traffic Continuation Indication function.
@{ */ 

/*! Support for automatic generated code module (tci_autocode.c, tci_autocode.h) */
#ifdef TCI_CFG_ENABLE
#define TCI_CFG_AUTOCODE                               FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_TCI)), SWITCH_OFF)
#else
#define TCI_CFG_AUTOCODE                               SWITCH_OFF
#endif


#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
#define TCIACCCOORDINATION              (SWITCH_ON)
#define TCI_NONSTOPDRIVEOFFFEATURE      (SWITCH_OFF)
#define TCI_INTERRUPTEDDRIVEOFFFEATURE  (SWITCH_ON)
#define TCI_TARGETLEAVESSUBJLANE        (SWITCH_ON)
#define TCI_ACCOUSTICALNTIFICATION      (SWITCH_ON)
#define TCI_VISUALNOTIFICATION          (SWITCH_ON)


#if((TCI_ACCOUSTICALNTIFICATION==SWITCH_OFF)&&(TCI_VISUALNOTIFICATION==SWITCH_OFF))
#error Atleast TCI_ACCOUSTICALNTIFICATION or TCI_VISUALNOTIFICATION should be ON
#endif

#define TCI_CFG_DEPENDENT_SWITCH(bool_condition, switch_value) ((bool_condition) && (switch_value))

#define TCI_INTERRUPTEDDRIVEOFFFIXNOT(switch_value) (TCI_CFG_DEPENDENT_SWITCH((TCI_INTERRUPTEDDRIVEOFFFEATURE),(switch_value)))
#define TCI_INTERRUPTEDDRIVEOFFFIXNOTIFICATION TCI_INTERRUPTEDDRIVEOFFFIXNOT(SWITCH_ON)

#if((TCI_INTERRUPTEDDRIVEOFFFEATURE==SWITCH_ON)&&(TCI_NONSTOPDRIVEOFFFEATURE==SWITCH_ON))
#error TCI_INTERRUPTEDDRIVEOFFFEATURE and TCI_NONSTOPDRIVEOFFFEATURE cannot be enabled at the same time
#endif
#if((TCI_INTERRUPTEDDRIVEOFFFEATURE==SWITCH_OFF)&&(TCI_NONSTOPDRIVEOFFFEATURE==SWITCH_OFF)&&(TCI_TARGETLEAVESSUBJLANE == SWITCH_OFF))
#error FCT_CFG_TCI should be switched off
#endif
#endif

/** @} end defgroup*/
#endif


