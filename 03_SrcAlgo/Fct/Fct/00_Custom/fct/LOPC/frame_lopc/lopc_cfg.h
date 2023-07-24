/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               lopc_cfg.h

DESCRIPTION:               Configuration file for LOPC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.11.1.4

**************************************************************************** */

#ifndef LOPC_CFG_H_INCLUDED
#define LOPC_CFG_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lopc_custom_frame LOPC_Custom_Frame
@ingroup    lopc_custom
@brief      Module for custom LOPC frame files
 */

/*!
@defgroup   lopc_custom_lopc LOPC_Custom_Module
@ingroup    lopc_custom
@brief      Module for custom LOPC files
 */

/*!
@defgroup   lopc_cfg Lopc_cfg
@ingroup    lopc_custom_frame
@brief      LOPC Config File
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_config.h"

/*****************************************************************************
  Config: Functionalities and Features
*****************************************************************************/
/*! Configuration switch enabeling Cruise Control functionality (no object evaluation) */
#define FCT_CFG_CC                              (1)


/* Switch for LOC sub-component */
#define LOPC_CFG_LOC                            FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACT_CODE_VERSION,SWITCH_ON)
/* Switch for LOP sub-component */
#define LOPC_CFG_LOP                            FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACT_CODE_VERSION,SWITCH_ON)
/* Switch for KMC sub-component */
#define LOPC_CFG_KMC                            FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_ACT_CODE_VERSION==SWITCH_OFF),SWITCH_ON) 


/*****************************************************************************
  Config: Long (Longitudinal functions)
*****************************************************************************/

/*! Configuration switch to use external ACC state machine (other ECU manages
driver input switches and state handling (Currently ARS4T0 specific) */
#define LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE               (!CFG_ACC_LEVER_INPUT)


/*****************************************************************************
  Config: LOP (Longitudinal Planner)
*****************************************************************************/

/*! Number of <VehicleSpeedControl> Ports */
#define LOP_CFG_VSC_PORT_CNT                                            (2u)

/*! Number of <DistanceSpeedControl> Ports */
#define LOP_CFG_DSC_PORT_CNT                                            (0u)

/*! Number of <DistanceCurveControl> Ports */
#define LOP_CFG_DCC_PORT_CNT                                            (0u)

/*! Number of <TargetFollowControl> Ports */
#define LOP_CFG_TFC_PORT_CNT                                            (6u)

/** @} end defgroup */

#endif /* ifndef LOPC_CFG_H_INCLUDED */

