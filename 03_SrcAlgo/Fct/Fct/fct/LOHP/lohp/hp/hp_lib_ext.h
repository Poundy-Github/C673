/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_lib_ext.h

DESCRIPTION:               This file contains all definitions for hp lib function required externally

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.5.1.3

**************************************************************************** */

#ifndef HP_LIB_EXT_H_INCLUDED
#define HP_LIB_EXT_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_lib_ext_h Hp_lib_ext_h
@ingroup    hp
@brief      External header file for HP library
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

extern acceleration_t HP_t_DetermineDistControlAccel(acc_object_t * const Object, percentage_t headway_setting, acceleration_t a_own);
extern times_t HP_t_DetermineTimeToStop(const acceleration_t acceleration, const velocity_t velocity);

#if ( HP_CFG_OVERTAKE_SUPPORT_FEATURE )
extern distance_t HP_t_DetermineMinDecelDistance( acceleration_t s16_a_host, velocity_t s16_v_host, const acc_object_t *pt_object, const acc_output_data_t* pt_output );
#endif  /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */

#endif  /* HP_LIB_EXT_H_INCLUDED */
