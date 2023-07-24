/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_cfg.h

DESCRIPTION:               Configuration Header File for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.23 $

LEGACY VERSION:            Revision: 1.8

**************************************************************************** */
#ifndef SIT_CFG_H_INCLUDED
#define SIT_CFG_H_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup sit_cfg Configuration
@ingroup sit
@brief    Contains all configuration switches related to the SIT subcomponent.\n\n
@{
*/
#include "slate_config.h"
#if (FCT_CFG_ACC_SITUATION)
/*--- sit_traffic_estimation.c ---*/

/*! Calculation of the traffic jam probability given only the velocity of the 
    object-of-interest OOI-0 */
#define SIT_TE_CALC_TJP_OOI_ONLY                   1

/*! Calculation of the traffic jam probability given the velocity of the
    object-of-interest OOI-0 as well as the averaged velocity of the 
    surrounding objects */
#define SIT_TE_CALC_TJP_COLLECTIVE                 1


/*--- sit_objfeatures.c ---*/

/* calculate CutinPotential for all neighbor objects, not only for the OOI selected neighbor objects */
/* (default value for unchanged behavior 0) */
#define SIT_CUTINPOTENTIAL_CALC_FOR_ALL_OBJECTS      0

/*--- sit_calc_cutin_pot.c ---*/
/*! Configuration switch to improve Cutin potential calculation. Currently enabled only for ARS410VA10 */
#define SIT_CUTIN_POT_LIMIT SWITCH_ON

/*--- sit_calc_cutout_pot.c ---*/

/*! since CutOutPotential shows lots of false positive events in follow mode on country road
and in cities, suppress CutOutpotential in these scenarios 
(quick solution, long term solution could be general optimization of calculation of CutOutPotential */
#define SIT_CUTOUTPOT_SUPRESS_ON_COUNTRYRAD_CITY   0


/*--- sit_lanechange.c ---*/

/*! Configuration switch enabling lane change probability calculation */
#define SIT_CFG_LC_PROB_CALC                       1

/*! Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input */
#define SIT_LC_CFG_USE_TURNIND_CAMERA_PROB        SWITCH_OFF

/*Switch to disable selection of stationary objects - only disabled for ARS510RT10 project*/
#define SIT_CFG_FILL_STAT_PATH			SWITCH_ON

/*! Configuration switch for enabling camera support in lane-change , for current time switch is always on till camera observer is fully independent */
#define SIT_LC_CFG_USE_CAMERA                       SWITCH_ON//FCT_CFG_DEPENDENT_SWITCH( (FCT_CFG_FIP_LANE_MATRIX_FUSION && FCT_CFG_SEN_CAM_LANE_INTERFACE), SWITCH_ON)

/*! Configuration switch for enabling multi object fusion in lane-change */
#define SIT_LC_CFG_ENABLE_MULTIOBJECTFUSION         SWITCH_OFF

/*! Configuration switch for enabling multi object fusion in lane-change (To be disabled only for ARS510VW19 and ARS510TA19) */ 
#define SIT_LC_CFG_ENABLE_MULTIOBJFUSION         SWITCH_ON

/*! Configuration switch for enabling lane matrix support in lane-change */
#define SIT_LC_CFG_LANEMATRIX_FUSION                FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING, SWITCH_OFF)

/*! Configuration switch for enabling Filter peak probability calculation */
#define SIT_LC_USE_FILTER_PEAK_PROB                 SWITCH_OFF

/* ---sit_o2o.c--- */
/*! Configuration switch for enabling curvature calculation based on left road polynomial */
#define SIT_CFG_O2O_USE_ROAD_LEFT               0

/*! Configuration switch for enabling curvature calculation based on right road polynomial */
#define SIT_CFG_O2O_USE_ROAD_RIGHT               0

/* Ignore Lane Validation Overtake support feature activation */
#define SIT_CFG_IGNORE_LANE_VALADITY             1
#endif
///@}
#endif
