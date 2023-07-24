/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_cfg.h

DESCRIPTION:               Configuration file for HP

AUTHOR:                    $Author: Talakadu, Ajay (uid22849) $

CREATION DATE:             26.03.2010

VERSION:                   $Revision: 1.15.5.1 $

LEGACY VERSION:            Revision: 1.10

**************************************************************************** */
#ifndef HP_CFG_H_INCLUDED
#define HP_CFG_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/*!
@defgroup   hp_custom HP_Custom
@ingroup    lohp_custom_lohp
@brief      Module for HP custom files
 */

/*!
@defgroup   hp_cfg Hp_cfg
@ingroup    hp_custom
@brief      HP config File
@{ */ 

/*****************************************************************************
  Config: ACC (Adaptive Cruise Control) Features 
*****************************************************************************/

/*! use driver mode to adapt ACC Parameter */
#define CFG_FCT_ACC_USE_DRIVE_MODE                  (0)

/*! Activation of Overtake support feature */
#define HP_CFG_OVERTAKE_SUPPORT_FEATURE             (0)

/*! Activation of Overtake prevention feature */
#define HP_CFG_OVERTAKE_PREVENTION_FEATURE          (0)

/*****************************************************************************
  Config: ACC (Adaptive Cruise Control) Switches  
*****************************************************************************/

/* ACC alert also for (stationary) objects (alert will always sent for stopped objects!)*/
#define CFG_FCT_ACC_ALERT_STATIONARY_OBJ         (1) 

/* ACC alert only for first object in current lane*/
#define CFG_FCT_USE_ONLY_FIRST_OBJECT_FOR_ALERT  (1) 

/*! use only next object for control */
#define CFG_FCT_ACC_USE_ONLY_FIRST_OBJECT         (0)

/*! use only objects in vehicles lane for control*/
#define CFG_FCT_ACC_USE_ONLY_OBJECTS_IN_LANE      (0)

/*! objects in the adjacent lanes are always used for control, else: they are only used if no moving object is present in the host lane */
#define CFG_FCT_ACC_USE_OBJECTS_IN_ALL_LANES      (1)

/*! use driver intention for host lane objects requested distance modification */
#define CFG_FCT_ACC_USE_DRVINT_FOR_HOSTLANE_OBJ   (1)

/*! use cut out potential for host lane objects requested distance modification */
#define CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ   (1)

/*! modify requested distanc to current distance and ramp it up to requested distance (e.g. in standstill) */
#define CFG_FCT_ACC_MODIFY_REQ_DIST_TO_CURR_DIST  (1)

/*! Switch On reaction on stationary Objects */
#define CFG_FCT_ACC_REACT_ON_STANDING_OBJECTS     (1)

/*! display only the next object if available, do not display objects on adjacent lanes */
#define CFG_FCT_ACC_DISPLAY_ONLY_FIRST_OBJECT     (1)

/*! ACC paramereters are frozen for debugging */
#define CFG_FCT_ACC_PARAMS_DEBUG                  (0)

/*! Selection of controller used for stationary/slow moving objects (TTS)  */
#define CFG_FCT_ACC_TTS_CONTROLLER                (0) /* 0=Legacy TTS, 1 = New concept */

/*! Optimize Controller Output during Overtake Support */
#define CFG_FCT_ACC_APPROACH_SUPPRESSION          (0)

/*! OOI's lanechange information is available and active */
#define HP_CFG_PARALLEL_LANE_CHANGE               FCT_CFG_DEPENDENT_SWITCH( SLATE_CFG_PARALLEL_LANE_CHANGE, SWITCH_OFF )

/*! OOI's Lane assosiation information from SLATE during Pre Lane Change Starts */
#define HP_CFG_PRE_LC_OBJ_LA                      FCT_CFG_DEPENDENT_SWITCH(OUT_CFG_FUNC_LANEASSOC_LA, SWITCH_OFF)

/** @} end defgroup */

#endif /* ifndef HP_CFG_H_INCLUDED */

