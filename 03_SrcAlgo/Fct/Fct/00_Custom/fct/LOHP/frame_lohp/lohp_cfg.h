/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               lohp_cfg.h

DESCRIPTION:               Configuration file for LOHP

AUTHOR:                    $Author: Schnellbach, Hans-Juergen (uidg5946) $

CREATION DATE:             26.03.2010

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */

#ifndef LOHP_CFG_INCLUDED
#define LOHP_CFG_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lohp_custom_frame LOHP_Custom_Frame
@ingroup    lohp_custom
@brief      Module for custom LOHP frame files
 */

/*!
@defgroup   lohp_custom_lohp LOHP_Custom_Module
@ingroup    lohp_custom
@brief      Module for custom LOHP files
 */

/*!
@defgroup   lohp_cfg Lohp_cfg
@ingroup    lohp_custom_frame
@brief      LOHP config File
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_config.h"

/*****************************************************************************
  Config: Subcomponents
*****************************************************************************/

/* Switch for TC sub-component */
#define LOHP_CFG_TC                            FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACT_CODE_VERSION,SWITCH_ON)

/* Switch for PRED sub-component */
#define LOHP_CFG_PRED                          FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LOHP_COMPONENT,SWITCH_OFF)

/*****************************************************************************
  Config: Functionalities and Features
  Note: Copied from lopc_cfg.h for separate HP module.these were formerly in fct_config.h
*****************************************************************************/

/*! Configuration switch enabeling Cruise Control functionality (no object evaluation) */
#define FCT_CFG_CC                              (1)
/*! Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation) */
//#define FCT_CFG_ACC                             (1) /* Replaced by FCT_CFG_ACC_HEADWAY_PLANNER */
/*! Configuration switch enabeling Full Speed Range Adaptive Cruise Control functionality 
    (with object evaluation and stop and go capability) */
#define FCT_CFG_FSRACC                          (1)
#define FCT_CFG_DM                              (0)
#define FCT_CFG_FCA                             (0) /* @todo: currently disabled since access to VehSig needed, see FCT_SEN_CFG_VEH_SIG_INPUT */
/*! Configuration switch to use external ACC state machine (other ECU manages
driver input switches and state handling (Currently ARS510TA19 specific) */
#define LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE               (!CFG_ACC_LEVER_INPUT)

/*****************************************************************************
  Configurations : Functions
*****************************************************************************/

/*! Only accept confirmation to drive off in standstill if driver as pressed Resume twice */
#define CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF        (0)

/*! Use host accel from VDY, otherwise aInit will be used for velocity prediction */
/*! Value is duplicated in lopc_cfg.h as well */
#define CFG_FCT_USE_VDY_HOST_ACCEL                          (0)

/*! use velocity of VDY component */
#define CFG_FCT_USE_VDY_HOST_VELOCITY                       (1)

/** @} end defgroup */

#endif /* ifndef LOHP_CFG_INCLUDED */

