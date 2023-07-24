/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_par.h

DESCRIPTION:               Parameter Header File for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 1.6

**************************************************************************** */

#ifndef SIT_PAR_H_INCLUDED
#define SIT_PAR_H_INCLUDED

#include "sit_cfg.h"
#include "slate_par.h"
/*****************************************************************************
  INCLUDES
*****************************************************************************/
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup sit_par Parameter
@ingroup sit
@brief        Contains all parameters that are used in sit and their values.\n\n
@description  This module does not contain any functions. It only contains defines as soon as variable initializations.
@{
*/
/*nothing should be included in this file*/

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- sit_calc_cutout_pot.c ---*/
/*! maximum distance for cut out potential calculation */
#define SIT_MaxDistCutOut (70.f)
/*! filter constant used for cutout-potential lowpass filtering, 
    do not set to negative value, this might cause an div by 0 or underflow */
#define SIT_CUTOUTPOT_FILT_CONST (8.f)


/*--- sit_calc_cutin_pot.c ---*/

#define SIT_MaxDistPredictionTime (2.1f)

/*! Assumed car width for cut-in potential calculation */
#define SIT_CAR_WIDTH               (1.8f)
/*! Minimal prediction time used for cut-in potential calculation */
#define SIT_MIN_CUT_IN_PRED_TIME     (0.1f)
/*! Maximal prediction time used for cut-in potential calculation */
#define SIT_MAX_CUT_IN_PRED_TIME     (0.5f)
/*! Factor used to decrease prediction time depending on object distance */
#define SIT_PRED_TIME_TEST_FACTOR    (0.75f)
/*! Relative velocity variance maximum over which prediction time is set to SIT_MIN_CUT_IN_PRED_TIME */
#define SIT_REL_VEL_TRAJ_VAR_MAX     (5.f)

/*! In cut-in calculation : (Ego vehicle width + Object Width)/2 plus this value is taken to
be the 100% cut-in potential line. Note: due to issues with trucks, this value is not added
for trucks */
#define SIT_CUT_IN_MAX_POT_OFFSET          (0.25f)  /* Object widths plus this value are 100% potential in near range */
/*! In cut-in calculation : (Ego vehilce width + Object Width)/2 plus this value is the 0%
potential line. */
#define SIT_CUT_IN_MIN_POT_OFFSET          (1.5f)
/*! The cut-in ramp is modified depending on object distance (determined in time to reach
the given point). This define specifies the time from which the lines shall not be modified */
#define SIT_DIST_RAMP_FULL_PRED_TIME       (1.0f)

/*! The minimum ramping factor to use in cut-in calculation reducation based on object
distance @see also SIT_DIST_RAMP_FULL_PRED_TIME */
#define SIT_MIN_CUT_IN_POT_SCALE_FACTOR    (0.625f)
/*! The maximum ramping factor to use in cut-in calculation, always leave on 1.0! */
#define SIT_MAX_CUT_IN_POT_SCALE_FACTOR    (1.0f)

/*! The radius of the current course curve from where curvature has no influence on
cut-in potential (i.e: behaves as if road was straight). Below this curvature the
cut-in potential is reduced */
#define SIT_CUT_IN_CURV_RADIUS_MAX       (2000.f)
/*! The radius of the current course curve from where curvature has maximal influence
(factor of SIT_CUT_IN_CURV_SCALE_FACTOR_MIN) on cut-in potential. */
#define SIT_CUT_IN_CURV_RADIUS_MIN       (700.f)
/*! The maximum scaling factor the course curvature has on the cut-in potential */
#define SIT_CUT_IN_CURV_SCALE_FACTOR_MIN   (0.75f)

#define SIT_CUT_IN_CROSS_DIST_MAX  (50.f)
#define SIT_CUT_IN_CROSS_DIST_MIN  (15.f)
#define SIT_CUT_IN_CROSS_SCALE_MIN (0.77f)

/*! If an object is on the border of the far beam range, then aritifical decrease it's
cut-in potential. This decrease takes place if the object is between the distance
specified below, and the function OTGetObjFOVOverlapFar returns TRUE */
#define SIT_NEAR_FAR_LIMIT_MIN_DIST        (10.f)
#define SIT_NEAR_FAR_LIMIT_MAX_DIST        (75.f)
/*! The amount in meters the predicted position is shifted outwards for objects near beam border */
#define SIT_REFLECTION_SHIFT_WIDTH_FACTOR  (0.10f)

/*! filter constant used for cutout-potential lowpass filtering, 
    do not set to negative value, this might cause an div by 0 or underflow */
#define SIT_CUTINPOT_FILT_CONST (8.f)

/*--- Multi Object Observer parameters ---*/

/*! The minimum ego-speed to use the Multi Object Observer */
#define MOR_ACTIVE_MIN_SPEED  (16.6F)

/*! The maximal distance to the Object to use the Multi Object Observer */
#define MOR_ACTIVE_MAX_DIST  (100.F)

/*! The maximal distance between the Objects to use the Multi Object Observer 
(we can not give a reliable prediction for the curvature between both Objects) */
#define MOR_ACTIVE_MAX_REL_DIST  (75.F)

/*!  maximal timegap for selection of object ahead */
#define MOR_TIMEGAP_SELECTION_OBJ_AHEAD (2.0f)

/*! The maximal relative velocity to the Objects to use the Multi Object Observer 
(necessary to get a symmetrical Algorithm for left and right Lane)*/
#define MOR_ACTIVE_RAMP_REL_VEL_MIN     (-0.5F)
#define MOR_ACTIVE_RAMP_REL_VEL_MAX     (0.F)
#define MOR_ACTIVE_RAMP_REL_VEL_LENGTH  (MOR_ACTIVE_RAMP_REL_VEL_MAX - MOR_ACTIVE_RAMP_REL_VEL_MIN)

/*! The Offset for the lateral Distance of the Object within the lateral Displacement can be bigger than
the lateral Displacement of the Object ahead */
#define MOR_ACTIVE_RAMP_OFFSET_LAT_MIN    (0.25F)
#define MOR_ACTIVE_RAMP_OFFSET_LAT_MAX    (0.5F)
#define MOR_ACTIVE_RAMP_OFFSET_LAT_LENGTH (MOR_ACTIVE_RAMP_OFFSET_LAT_MAX - MOR_ACTIVE_RAMP_OFFSET_LAT_MIN)

/*! The minimum distance necessary between the Object and Object ahead to use the Multi Object Observer */
#define MOR_ACTIVE_MIN_REL_DIST (5.F)

/*! Estimated length of Cars and Trucks added to the distance to calculate the TTC more precisely */
#define MOR_OFFSET_LEN_CAR    (2.F)
#define MOR_OFFSET_LEN_TRUCK  (5.F)

/*! Withim this distance from a Truck we assume Objects except Cars and Trucks to be reflections of the drivers cab */
#define MOR_MAX_DIST_TRUCK_CAB  (20.F)

/*! The minimum relative distance between 2 Objects the Enhanced TTC is merged with the regular TTC */
#define MOR_ETTC_RAMP_MIN_DIST  (40.F)
#define MOR_ETTC_RAMP_MAX_DIST  (100.F)
#define MOR_ETTC_RAMP_LENGTH    (MOR_ETTC_RAMP_MAX_DIST - MOR_ETTC_RAMP_MIN_DIST)


/*! The minimum and maximum TTC/ETTC value to get a Cut-In Potential (MO_MIN_TTC_VALUE: 100%, MO_MAX_TTC_VALUE: 0%) */
#define MOR_MIN_TTC_VALUE  (1.F)
#define MOR_MAX_TTC_VALUE  (10.F)

/*! The minimum and maximum difference of the TTC to the Object and between the Object and Object ahead 
the potential is reduced linearly */
#define MOR_TTC_OBJ_RAMP_MIN       (4.F)
#define MOR_TTC_OBJ_RAMP_MAX       (6.F)
#define MOR_TTC_OBJ_RAMP_LENGTH    (MOR_TTC_OBJ_RAMP_MAX - MOR_TTC_OBJ_RAMP_MIN)

#define MOR_TTC_DIFF_RAMP_MIN       (3.F)
#define MOR_TTC_DIFF_RAMP_MAX       (4.F)
#define MOR_TTC_DIFF_RAMP_LENGTH    (MOR_TTC_DIFF_RAMP_MAX - MOR_TTC_DIFF_RAMP_MIN)

/*! The Value of cut_in_pot calculated by the MOR-Observer assumed as 100% and the start of the Ramp to this value */
#define MOR_FULL_POTENTIAL_RAMP_MAX     (0.7F)
#define MOR_FULL_POTENTIAL_RAMP_MIN     (0.5F)
#define MOR_FULL_POTENTIAL_RAMP_LENGTH  (MOR_FULL_POTENTIAL_RAMP_MAX - MOR_FULL_POTENTIAL_RAMP_MIN)

/*----sit_lanechange.c-----*/
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
/* Max time for Steerback Phase */
#define SIT_LC_STEERBACK_TIME           (2.5f)
/* lane change prob threshold used to determine steerback state */
#define SIT_LC_PROB_THRESHOLD_STEERBACK (25u)
/*check if right prob is high enough to consider a valid left/right state*/
#define SIT_LC_PROB_RIGHT_LOWTHRESHOLD  (0.26f)
/* check if left prob is high enough to consider a valid left/right state */
#define SIT_LC_PROB_LEFT_LOWTHRESHOLD   (0.26f)
/*! Minimal camera course distance (visibility range) for considering camera infos */
#define SIT_LC_PROB_MIN_CAM_DIST        (7.f)
/* Maximum possible value of lane change probability  */
#define SIT_LC_MAX_PROB                 (100u)
/* Minimum threshold of camera lane marker distance used to check camera marker crossed  */
#define SIT_LC_CAM_LM_MIN_DIST          (0.75f)
/* Maximum threshold of camera lane marker distance used to check camera marker crossed  */
#define SIT_LC_CAM_LM_MAX_DIST          (1.5f)
/*!< Timer value which leads to a lane change probability of 0 */
#define SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE (100.f)
/*! [m/s], Minimum ego speed for calculating lane change probability */
#define SIT_LC_PROB_MIN_EGO_SPEED       (3.6f/C_KMH_MS)
  /* minimum value threshold used to enter lane change or steer back state given high enough kinematic probabilities*/
#define SIT_LC_PROBMIN_LANECHANGE       (25u)
/* lane change prob threshold used to change state from LC to steerback*/
#define SIT_LC_PROB_MIN_THRESHOLD       (15u)
#endif /* SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */

/*----sit_lanechange_cam.c-----*/
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
#define SIT_LC_PROB_MIN_TIME_TURN_LIGHT_ON           (4.f)   /*!< Minimum time that a turn light is considered to be enabled */
#define SIT_LC_PROB_MAX_TIME_TURN_LIGHT_ON           (48.f)  /*!< Maximum time that a turn light is considered to be enabled */
#define SIT_LC_PROB_TURN_LIGHT_OFF                   (40.f)  /*!< Maximum time which is set when turn light is in ACTIVE state more than SIT_LC_PROB_MIN_TIME_TURN_LIGHT_ON */
#endif /* SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */

/*--- sit_check_occupied_lane.c ---*/

#define SIT_MIN_PATHWIDTH_PASSABLE_STAT (1.75f)
#define SIT_MIN_PATHWIDTH_PASSABLE_STAT_HYST (2.1f)
#define SIT_MIN_PATHWIDTH_PASSABLE_MOV_HYST_ADD (0.5f)

#define SIT_MIN_PATHWIDTH_PASSABLE_MOV_MIN  (2.0f)
#define SIT_MIN_PATHWIDTH_PASSABLE_MOV_MAX  (2.5f)
#define SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MIN  (5.0f)
#define SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MAX  (15.0f)
#define SIT_MAX_PATHWIDTH_PASSABLE_SCALE_DIST    (5.0f)
#define SIT_MIN_PATHWIDTH_PASSABLE_SCALE_FACTOR  (0.75f)

#define SIT_CORRIDOR_SEL_Y_OFFSET_MIN (0.0f)
#define SIT_CORRIDOR_SEL_Y_OFFSET_MAX (0.5f)

#define SIT_CORSELYOFF_Obj2ObjDistX_MIN (0.0f)
#define SIT_CORSELYOFF_Obj2ObjDistX_MAX (5.0f)

#define SIT_CORSELYOFF_TTCGAP_MIN (1.7f)
#define SIT_CORSELYOFF_TTCGAP_MAX (3.3f)

#define SIT_CORSEL_Y_HYST_MIN         (0.10f)
#define SIT_CORSEL_Y_HYST_MAX         (1.30f)
#define SIT_CORSEL_Y_HYST_TIMEGAP_MIN (1.0f)
#define SIT_CORSEL_Y_HYST_TIMEGAP_MAX (2.8f)


/*--- obj_features.c ---*/

/* Cut-In and Cut-Out potential parameters */
/*! lines for standard cut out potentials */
#define Y_DIST_MIN_CUT_OUT_POT (0.0f)
#define Y_DIST_MAX_CUT_OUT_POT HALBESTRASSENBREITE

/*! lines for cut out potentials in road works */
#define Y_DIST_MIN_CUT_OUT_POT_ROADWORKS (0.0f)
#define Y_DIST_MAX_CUT_OUT_POT_ROADWORKS HALBESTRASSENBREITE

/*! lines for cut out potentials in city traffic */
#define Y_DIST_MIN_CUT_OUT_POT_CITY (0.0f)
#define Y_DIST_MAX_CUT_OUT_POT_CITY HALBESTRASSENBREITE

#define SIT_TOLERABLE_STDDEV_CI_CO_POT    (0.20f)

/*! only calculate potential for object with absolute longitudinal velocity higher CUTINPOTENTIAL_MIN_OBJ_ABSVEL */
#define CUTINPOTENTIAL_MIN_OBJ_ABSVEL     (0.0f/C_KMH_MS)



/*! Calculation of lane change probability */
#define SIT_LC_PROB_POINTS_TURN_LIGHT_TABLE                  (3)   /*!< No. of elements in SIT_LC_PROB_TABLE_TURN_LIGHT */
#define SIT_LC_PROB_POINTS_LAT_VEL_CAM_LANE_MARKER_TABLE     (2)   /*!< No. of elements in SIT_LC_PROB_TABLE_LAT_VEL_CAM_LANE_MARKER */
#define SIT_LC_PROB_POINTS_LAT_DIST_TABLE                    (4)   /*!< No. of elements in SIT_LC_PROB_TABLE_LAT_DIST */
#define SIT_LC_PROB_POINTS_CURVE_TABLE                       (4)   /*!< No. of elements in SIT_LC_PROB_TABLE_CURVE */
#define SIT_LC_PROB_POINTS_DIFF_LAT_FILT_CURVES_TABLE        (4)   /*!< No. of elements in SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES */
#define SIT_LC_PROB_POINTS_DRIVER_INT_CURVE_FILTER_TABLE     (2)   /*!< No. of elements in SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST */
#define SIT_LC_PROB_POINTS_COMB_CAM_PROB_TABLE               (4u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_CAM_PROB */
#define SIT_LC_PROB_POINTS_COMB_ALL_LATDIFFCURVE_TURNLIGHT_TABLE       (8u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_ALL_LATDIFFCURVE_TURNLIGHT */
#define SIT_LC_PROB_POINTS_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE_TABLE   (8u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE */
#define SIT_LC_PROB_POINTS_COMB_LOWSPEED_TURNLIGHT_TABLE     (4u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_LOWSPEED_TURNLIGHT */
#define SIT_LC_PROB_POINTS_COMB_LATDIST_LATDIFFCURVE_TABLE   (8u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_LATDIST_LATDIFFCURVE */
#define SIT_LC_PROB_POINTS_COMB_MARKERCROSSING_TABLE         (4u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_MARKERCROSSING */
#define SIT_LC_PROB_POINTS_COMB_CURVE_TABLE                  (4u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_CURVE */
#define SIT_LC_PROB_POINTS_COMB_LATDIFFCURVE_TURNLIGHT_TABLE (4u)  /*!< No. of elements in SIT_LC_PROB_TABLE_COMB_LATDIFFCURVE_TURNLIGHT */


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*! Calculation of lane change probability */
typedef struct  
{
  /*! Convert time since last usage of turn light switch into probability that the driver changes the lane in this direction */
  GDBVector2_t SIT_LC_PROB_TABLE_TURN_LIGHT[SIT_LC_PROB_POINTS_TURN_LIGHT_TABLE];
  /*! Convert lateral velocity to lane markers into probability that the driver changes the lane in this direction */
  GDBVector2_t SIT_LC_PROB_TABLE_LAT_VEL_CAM_LANE_MARKER[SIT_LC_PROB_POINTS_LAT_VEL_CAM_LANE_MARKER_TABLE];
  /*! Combination of camera based lane change probabilities to a single probability */
  uint8 SIT_LC_PROB_TABLE_COMB_CAM_PROB[SIT_LC_PROB_POINTS_COMB_CAM_PROB_TABLE];
  /*! Combination of already accumulated LC probability (camera) with iLatDiffFilteredCurvesProb and turn light based probability */
  uint8 SIT_LC_PROB_TABLE_COMB_ALL_LATDIFFCURVE_TURNLIGHT[SIT_LC_PROB_POINTS_COMB_ALL_LATDIFFCURVE_TURNLIGHT_TABLE];
  /*! Combination of different LC probabilities (difference is lateral displacement based on filtered curves, turn light) to a single probability */
  uint8 SIT_LC_PROB_TABLE_COMB_LATDIFFCURVE_TURNLIGHT[SIT_LC_PROB_POINTS_COMB_LATDIFFCURVE_TURNLIGHT_TABLE];
  /*! Convert difference in lateral distance between curve (ego or camera) and filtered driver intended curve to probability */
  GDBVector2_t SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES[SIT_LC_PROB_POINTS_DIFF_LAT_FILT_CURVES_TABLE];
  /*! Filter constant for driver intended curve */
  GDBVector2_t SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[SIT_LC_PROB_POINTS_DRIVER_INT_CURVE_FILTER_TABLE];
  /*! Combination different LC probabilities (lateral displacement, difference is lateral displacement based on filtered curves, turn light) to one combined probability (low speed) */
  uint8 SIT_LC_PROB_TABLE_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE[SIT_LC_PROB_POINTS_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE_TABLE];
  /*! Combination already accumulated LC probability (camera) with the turn light based probability (low speed) */
  uint8 SIT_LC_PROB_TABLE_COMB_LOWSPEED_TURNLIGHT[SIT_LC_PROB_POINTS_COMB_LOWSPEED_TURNLIGHT_TABLE]; 
  /*! Combination already accumulated LC probability (camera) with iLatDiffFilteredCurvesProb and distance in lateral direction (low speed) */
  uint8 SIT_LC_PROB_TABLE_COMB_LATDIST_LATDIFFCURVE[SIT_LC_PROB_POINTS_COMB_LATDIST_LATDIFFCURVE_TABLE];
  /*! Combination already accumulated LC probability (camera) with detected crossing of lane markers */
  uint8 SIT_LC_PROB_TABLE_COMB_MARKERCROSSING[SIT_LC_PROB_POINTS_COMB_MARKERCROSSING_TABLE];
  /*! Convert driven distance in lateral direction into LC probability */
  GDBVector2_t SIT_LC_PROB_TABLE_LAT_DIST[SIT_LC_PROB_POINTS_LAT_DIST_TABLE];
  /*! Convert curve (driver intended curve) into LC probability */
  GDBVector2_t SIT_LC_PROB_TABLE_CURVE[SIT_LC_PROB_POINTS_CURVE_TABLE];
  /*! Combination already accumulated LC probability with curvature based probability (low speed) */
  uint8 SIT_LC_PROB_TABLE_COMB_CURVE[SIT_LC_PROB_POINTS_COMB_CURVE_TABLE];
} SITLaneChangeProbParameter_t;

/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

extern const SITLaneChangeProbParameter_t SITLCProbParData;

/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


///@}
/* End of conditional inclusion */
#endif /*!< _SIT_PAR_H_INCLUDED */
