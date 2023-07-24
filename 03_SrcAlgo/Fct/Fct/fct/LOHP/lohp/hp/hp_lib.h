/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_lib.h

DESCRIPTION:               This file contains all the definitions for hp lib function

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.8

**************************************************************************** */

#ifndef HP_LIB_H_INCLUDED
#define HP_LIB_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_lib_h Hp_lib_h
@ingroup    hp
@brief      Internal header file for HP library
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES 
*****************************************************************************/

extern distance_t HP_t_GetAlertDistance(const acc_object_t *object);
extern distance_t HP_t_DetermineMaxIntrusion(distance_t AlertDistance, distance_t RequestedDistance, velocity_t VehicleSpeed, percentage_t headway_setting, velocity_t Relative_Speed, factor_t modification_factor, acceleration_t Relative_Accel);

#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */

#endif /* HP_LIB_H_INCLUDED */
