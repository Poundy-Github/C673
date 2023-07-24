/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_par.h

DESCRIPTION:               FCT parameters header

AUTHOR:                    $Author: Ramaiah, Shruthi (uidn2623) $

CREATION DATE:             09.11.2009

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.15

**************************************************************************** */
#ifndef FCT_PAR_H_INCLUDED
#define FCT_PAR_H_INCLUDED

#include "fct_types.h"

/*! @brief Maximale FCT Reichweite (der Antenne) */
#define RW_FCT_MAX               (200.F)         /* ARS2xx: (150.F) */

/*! @brief     Task cycle time of the FCT_SEN Cycle. 
               @typical 0.06f   @phys_unit [s]  @todo rename to FCT_SEN_CYCLE_TIME*/
#define  FCT_SEN_CYCLE_TIME       (0.06f)         
/*! @brief     Alias to FCTVeh calling cycle time in
               @typical 0.02f   @phys_unit [s]*/
#define  FCT_VEH_CYCLE_TIME      (0.020f)        

/*******************************/
/*! Component states           */
/*******************************/
#ifndef   COMP_STATE_NOT_INITIALIZED
#define COMP_STATE_NOT_INITIALIZED          (0u)
#endif
#ifndef   COMP_STATE_RUNNING
#define COMP_STATE_RUNNING                  (1u)
#endif
#ifndef   COMP_STATE_TEMPORARY_ERROR
#define COMP_STATE_TEMPORARY_ERROR          (2u)
#endif
#ifndef   COMP_STATE_PERMANENT_ERROR
#define COMP_STATE_PERMANENT_ERROR          (3u)
#endif
#ifndef   COMP_STATE_SUCCESS
#define COMP_STATE_SUCCESS                  (4u)
#endif
#ifndef   COMP_STATE_REDUCED_AVAILABILITY
#define COMP_STATE_REDUCED_AVAILABILITY     (5u)
#endif
#ifndef   COMP_STATE_NOT_RUNNING
#define COMP_STATE_NOT_RUNNING              (6u)
#endif 
/*******************************/
/* Vehicle related parameters  */
/*******************************/
/*! default value for vehicle width */  
//#define TRACKWIDTHFRONT_DEFAULT 2.00f    
/*! default value for sensor frontoverhang (dist. from front axle to sensor) */
//#define FRONTOVERHANG_DEFAULT 0.80f
/*! default value for wheelbase (dist. between front/rear axle) */
#define FCT_WHEELBASE_DEFAULT 2.85f   
/*! default value for axle load distribution */
//#define AXLELOADDISTRIBUTION_DEFAULT 0.5f        

/*! The stopped confidence threshold for ACC function */
#define FCT_ACC_PAR_OBJ_STOPPED_MIN_CONF    75u

/*! Delay time after all preconditions of sensor power reduction are satisfied
until power reduction is actually entered. Note: a setting of zero disables delay
timing, meaning if sensor power reduction conditions are satisifed, power is
reduced without delay @unit:ms */
#define FCT_PAR_SENSOR_POWER_REDUCTION_DELAY_MS 0


#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/******************************************************************************
  fct_io.c parameters
******************************************************************************/

/* Number of acceptable frame drops (1 means error flag if more than one frame drops) */
#define FCT_INPUT_ACCEPTABLE_DROPS 1u

#define FCT_SEN_TARGET_CYCLE_TIME   0.06f
#define FCT_VEH_TARGET_CYCLE_TIME   0.02f
#define FCT_NORM_TARGET_CYCLE_TIME  FCT_VEH_TARGET_CYCLE_TIME 
#define MILLION             1000000u

#endif

#endif
