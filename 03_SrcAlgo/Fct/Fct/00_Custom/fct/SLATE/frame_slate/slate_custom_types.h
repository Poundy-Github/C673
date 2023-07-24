/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 frame SLATE

PACKAGENAME:               slate_custom_types.h

DESCRIPTION:               Definition of data types and macros

AUTHOR:                    $Author: uia80245 $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.0


**************************************************************************** */

#ifndef SLATE_CUSTOM_TYPES_H_INCLUDED
#define SLATE_CUSTOM_TYPES_H_INCLUDED


#include "fct_types.h"
#include "slate_config.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup     slate_custom_types Custom Types
@ingroup      frame
@brief        Contains all customer specific type definitions. \n\n
@{
*/
/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/
/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

#if (!FCT_CFG_SENSOR_TYPE_RADAR)

/* ACC Quality related constants */
#define FUN_PRESEL_ACC_DROP_QUAL            (0u)  /*!< Object without ACC quality */
#define FUN_PRESEL_ACC_STAT_OBSTACLE        (30u) /*!< ACC quality of an "obstacle" which cannot be functionally assigned to a 
                                                       lane but cause a blocked path with another object */
#define FUN_PRESEL_ACC_MIN_KEEP_OBJ_QUAL    (40u)
#define FUN_PRESEL_ACC_MIN_OBJ_QUAL         (70u) /*!< Minimum ACC quality level. Moving object with this quality are assigned 
                                                       to the ego lane. Stationary objects are only assigned to a neighboring lane. */
#define FUN_PRESEL_ACC_OCCLUSION_OBJ_QUAL   (80u) /*!< ACC quality for occluded objects */
#define FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL  (85u) /*!< Inlane quality. All object with this quality level can be assigned to the ego lane. */

/* Road constants when EM Road is unavailable */
#define STRASSENBREITE       (3.75F)
/* half of standard road width */
#define HALBESTRASSENBREITE  (STRASSENBREITE/2.0F)
/* standard vehicle width */
#define FAHRZEUGBREITE       (2.2F)
/* half of standard vehicle width */
#define HALBEFAHRZEUGBREITE  (FAHRZEUGBREITE/2.F)

/* TASK_CYCLE_TIME definition assuming SLATE runs on 60ms Task */
#define TASK_CYCLE_TIME     (0.060F)      /* Unit: Seconds */

#endif /* END IF (!FCT_CFG_SENSOR_TYPE_RADAR) */

#ifndef FUN_PRESEL_ACC_HIGHEST_CLUST_VAR_OBJ_QUAL
#define FUN_PRESEL_ACC_HIGHEST_CLUST_VAR_OBJ_QUAL (74u) /*!< Moving object with highest cluster variance this quality is assigned */
#endif
#ifndef FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL
#define FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL    (75u) /*!< Moving object with high cluster variance this quality is assigned */
#endif
#ifndef FUN_PRESEL_ACC_LOW_CLUST_VAR_OBJ_QUAL
#define FUN_PRESEL_ACC_LOW_CLUST_VAR_OBJ_QUAL     (76u) /*!< Moving object with low  cluster variance this quality is assigned */
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/

#define FCT_SEN_BUMPER2COG_DIST_DEFAULT (2.5f)

#if (FCT_CFG_COLLISION_DETECTION)
#define DUMMY_INTERFACE_VERSION_CD    SLATE_SW_VERSION_NUMBER
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
#define DUMMY_INTERFACE_VERSION_SPM   SLATE_SW_VERSION_NUMBER
#endif

#if (FCT_CFG_LOHP_COMPONENT)
#define DUMMY_INTERFACE_VERSION_HC    SLATE_SW_VERSION_NUMBER
#endif

#ifndef OBJ_INDEX_NO_OBJECT
//TODO Clarify whether this is needed in camera 
#define OBJ_INDEX_NO_OBJECT     ((ObjNumber_t)-1)
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/// @}





#endif /* _SLATE_CUSTOM_TYPES_H_INCLUDED */ 

