/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_custom_ext.h

DESCRIPTION:               External Header File for Custom specific information in ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             27.07.2016

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            Revision: 1.7

**************************************************************************** */

#ifndef SIT_CUSTOM_EXT_H_INCLUDED
#define SIT_CUSTOM_EXT_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_customfunctions
@{ */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/* nothing should be included in this file */

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/

/*--- sit_objscore.c ---*/

/*--- sit_traffic_estimation.c ---*/
/*! Configuration switch for enabling custom output of the
    collective velocity */
#define SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING   0

/*! Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c) */
#define SIT_CFG_TRAFFIC_DENSITY                       0


/*--- sit_objfeatures.c ---*/
/*! Configuration switch to enable occlusion calculation usage for inlane decision */
#define SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION      1

/*--- sit_calc_cutin_pot.c ---*/


/*--- sit_check_occupied_lane.c ---*/
#define SIT_HALF_LANEOCCUPATION_WIDTH (5.0f)/*! m*/
#define SIT_CORR_SEL_MOVING_AS_STAT_SPEED (15.0f/C_KMH_MS)
#define SIT_BLOCKED_PATH_DECISION_TIME 5u
#define SIT_BLOCKED_PATH_DECISION_TIME_THRESHOLD 9u
#define SIT_BLOCKED_PATH_HYSTERESIS_THRES 18u
/*! maximum curvature for active blocked path selection */
#define SIT_MAX_CURVE_FOR_BLOCKED_PATH_SELECTION (1.0f/80.0f)

/*****************************************************************************
  MACROS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/

///@}
/* End of conditional inclusion */
#endif  /*!< _SIT_CUSTOM_EXT_H_INCLUDED */
