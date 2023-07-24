/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_par.h

DESCRIPTION:               Parameter Header File for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.74.15.1 $

LEGACY VERSION:            Revision: 1.9

**************************************************************************** */

#ifndef LA_PAR_H_INCLUDED
#define LA_PAR_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "la_cfg.h"
#include "slate_par.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup la_par Parameter
@ingroup la
@brief        Contains all parameters that are used in la and their values.\n\n
@description  This module does not contain any functions. It only contains defines as soon as variable initializations.
@{
*/
/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- la_acc_function_presel.c ---*/


/* Definitions for ACC range criteria for moving objects------------------------------------------*/
#define LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG        (4.0f)            /*! [s], default time-gap for moving objects at lower velocities [2.f ... 5.f] */
#define LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG       (3.0f)            /*! [s], default time-gap for moving objects at higher velocities [2.f ... 5.f] */

#if (SLATE_CFG_USE_DRIVE_MODE)
#define LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG_ECO    (5.0f)            /*! [s], default time-gap for moving objects at lower velocities in eco mode [2.f ... 5.f] */
#define LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG_ECO   (3.3f)            /*! [s], default time-gap for moving objects at higher velocities in eco mode [2.f ... 5.f] */
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */

#define LA_ACC_RANGE_DEFAULT_VEGO_LOW           (80.f/C_KMH_MS)   /*! [m/s], velocity at which lower time-gap sample point is set , [50.f/3.6f ... 120.f/3.6f] */
#define LA_ACC_RANGE_DEFAULT_VEGO_HIGH          (180.f/C_KMH_MS)  /*! [m/s], velocity at which lower time-gap sample point is set , [120.f/3.6f ... 250.f/3.6f] */
#define LA_ACC_RANGE_TIMEGAP_MIN_MOVING         (2.8f)            /*! [s], minimum default time-gap after range reduction [1.5f ... 3.5f] */
#define LA_ACC_RANGE_POS_VREL_THRES             (5.f/C_KMH_MS)    /*! [m/s], maximum vrel above which the minimum pick-up distance is used for objects [5.f/3.6f ... 10.f/3.6f] */

#define LA_ACC_RANGE_MAX_LOWER_MOVING           (100.F)           /*! [m], maximum ACC range for moving objects for low ego velocities [80.f ... 120.f] */
#define LA_ACC_RANGE_MAX_UPPER_MOVING           (200.f)           /*! [m], maximum ACC range for moving objects for high ego velocities [160.f ... 220.f] */
#define LA_ACC_RANGE_MAX_TIMEGAP_MAX_MOVING     (6.F)             /*! [s], maximum controller time-gap for moving objects [2.f ... 5.f] */
#define LA_ACC_RANGE_MIN_MOVING                 (80.F)            /*! [m], global minimum ACC range for moving objects [40.f ... 220.f] */

#define LA_ACC_RANGE_HYSTERESIS_HIGH_MOVING     (80.F)            /*! [m], maximum hysteresis of ACC range for moving objects with negative vrel [20.f ... 100.f] */
#define LA_ACC_RANGE_HYSTERESIS_MOVING          (30.F)            /*! [m], maximum hysteresis of ACC range for moving objects with positive vrel [10.f ... 60.f] */
#define LA_ACC_RANGE_HYSTERESIS_MIN_MOVING      (30.F)             /*! [m], minimum hysteresis of ACC range for moving objects with positive vrel [2.f ... 10.f] */

/* Definitions for Vrel dependent ACC range modification for moving objects-----------------------*/
#define LA_VREL_RANGE_EGO_ACCEL_MIN     (0.2f)                    /*! [m/s^2], minimum ego acceleration for consideration in pick-up range computation , [0.1f ... 1.f] */
#define LA_VREL_RANGE_OBJ_VREL_MAX      (-10.0f/C_KMH_MS)         /*! [m/s], maximum object relative velocity above which no vrel dependent pick-up range is computed , [-10.f ... -3.f] */

#define LA_VREL_RANGE_JERK_MAX          (-2.5f)                   /*! [m/s^3], maximum ego negative jerk, [-6.f ... -0.2f] */
#define LA_VREL_RANGE_DECEL_MAX         (-3.5f)                   /*! [m/s^2], maximum ego deceleration , [-4.f ... -0.5f] */
#define LA_VREL_RANGE_DELAY             (1.0f)                    /*! [s], approx. delay in ACC controller , [0.1f ... 2.f] */
#define LA_VREL_RANGE_TIMEGAP           (0.5f)                    /*! [s], final time-gap to object , [0.5f ... 2.8f] */

#define LA_VREL_RANGE_JERK_MAX_COMF     (-1.0f)                   /*! [m/s^3], maximum ego negative jerk, [-6.f ... -0.2f] */
#define LA_VREL_RANGE_DECEL_MAX_COMF    (-1.8f)                   /*! [m/s^2], maximum ego deceleration , [-4.f ... -0.5f] */
#define LA_VREL_RANGE_DELAY_COMF        (1.0f)                    /*! [s], approx. delay in ACC controller , [0.1f ... 2.f] */
#define LA_VREL_RANGE_TIMEGAP_COMF      (0.8f)                    /*! [s], final time-gap to object , [0.5f ... 2.8f] */

/*--------------- Definitions for ACC situation dependent range modification for moving objects---*/
#define LA_ACC_RANGE_EXT_RD_FUS_CRIT_VEGO_MAX (130.f/C_KMH_MS)    /*! [m/s], maximum ego velocity above which range extension criteria is independent of its fusion range , [120.f/C_KMH_MS ... 140.f/C_KMH_MS] */
#define LA_ACC_RANGE_RED_TUNNEL_CURVE_THRES   (1.f/2000.f)        /*! [m/s], VDY curvature above which range reduction in tunnels is applied , [1.f/2000.f ... 1.f/1000.f] */

/*--------------- Definitions for ACC range criteria for a priori stationary objects--------------*/
#define LA_ACC_RANGE_MIN_STATIONARY             (80.F)            /*! [m], minimum ACC range for stationary objects [40.f ... 120.f] */
#define LA_ACC_RANGE_MAX_STATIONARY             (100.F)           /*! [m], maximum ACC range for stationary objects [40.f ... 120.f] */
#define LA_ACC_RANGE_TIMEGAP_MAX_STATIONARY     (4.1F)            /*! [s], maximum controller time-gap for stationary objects [3.f ... 5.f] */
#define LA_ACC_RANGE_HYSTERESIS_STATIONARY      (20.F)            /*! [m], maximum hysteresis of ACC range for stationary objects [10.f ... 30.f] */
#define LA_ACC_RANGE_HYSTERESIS_MIN_STATIONARY  (3.F)             /*! [m], minimum hysteresis of ACC range for stationary objects [1.f ... 5.f] */

/*--------------- Definitions for ACC range criteria for oncoming objects-------------------------*/
#define LA_ACC_RANGE_TIMEGAP_ONCOMING           (2.0F)            /*! [s], time-gap threshold for oncoming traffic [1.f ... 5.f] */
#define LA_ACC_RANGE_MAX_ONCOMING               (180.F)           /*! [m], maximum ACC range for selecting oncoming objects [100.f ... 200.f] */
/*! Maximum lateral acceleration for range reduction of oncoming traffic in curve situation */ /*|*/
#define LA_ACC_RANGE_AY_MAX_ONCOMING            (4.0F)            /*! [m/s^2], maximum lateral acceleration for range reduction of oncoming traffic in curve situation , [3.f ... 5.f] */

/*--- la_corridor.c ---*/

#if LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM
/* Maximum lanewidth measured by cam indicating that ego-vehicle is on lane-class NARROW  */
#define LA_CAM_LANEWIDTH_NARROW_LANE_MAX       (3.35) 
/* Maximum lanewidth measured by cam indicating that ego-vehicle is on lane-class MORE_NARROW  */
#define LA_CAM_LANEWIDTH_MORE_NARROW_LANE_MAX  (2.85)
/* Maximum ego-speed, up to which the camera based reduction of seeklanewidth is applied */
#define LA_CAM_LANEWIDTH_MAX_SPEED             (140.0/C_KMH_MS)
#endif

/*! Factor used for scaling seek lane width if EO lane class is narrow 
@min: 0.5 @max: 1.0 */
#define LA_SEEK_LANE_WIDTH_FACTOR_NARROW_LANE     (0.9f)
/*! Factor used for scaling seek lane width if EO lane class is narrower 
@min: 0.5 @max: 1.0 */
#define LA_SEEK_LANE_WIDTH_FACTOR_NARROWER_LANE   (0.85f)

/*! Maximum tolerance factor from Road's estimated lane width to the seek
lane width. (E.g.: if set to 1.25f, that means the used seek lane width
may be maxmium 25% greater or 25% smaller than the lane width) @min:1 @max:2 */
#define LA_PAR_SEEK_WIDTH_TO_CAM_LANE_WIDTH_TOLERANCE   (1.25f)
#define LA_STANDARDLANEWIDTHTRCK        (LA_STANDARDLANEWIDTHSEEK + 0.5F)
#define LA_CITYLANEWIDTHTRCK            (LA_CITYLANEWIDTHSEEK + 0.75F)

#define LA_TUNNEL_LANEWIDTHSEEK         (2.7F)
#define LA_TUNNEL_LANEWIDTHTRCK         (LA_TUNNEL_LANEWIDTHSEEK + 0.5F)
#define LA_ROADWORKSLANEWIDTHTRCK       (LA_ROADWORKSLANEWIDTHSEEK + 0.2F)

/*! The seek lane width corresponding to the ego speed of #LA_MIN_SPEED_HIGWAYLANEWIDTH */
#define LA_MIN_ROAD_BORDER_STAT       (100u) /*!< Minimum road border status for considering the road boarder during trace bracket calculation */

/* Maximaler Abstand f?uer sichere Spurtrennung d.h. bis dorthin */
/* Spurverbreiterung möglich */
#define LA_MAX_VREL_REL_LANE_EXT_FACT     (-2.5f/C_KMH_MS)    /*!< Maximal relative velocity for applying relative lane extension factor */
#define LA_SPUR_SICHERHEIT      (100.F)  /* OLD */
/* Minimale Zeit fuer SpurZeitErweiterungsFaktor */
#define LA_SPURZEIT_MIN         (0.5F)  /* OLD */
/* Maximale Zeit fuer SpurZeitErweiterungsFaktor */
#define LA_SPURZEIT_MAX         (2.0F)  /* OLD */
/* Maximale Abstandsdifferenz fuer Spurverbreiterung */
#define LA_SPUR_ABSTANDDIFF_MAX (30.F)    /* OLD */
/* Minimale Abstandsdifferenz fuer Spurverbreiterung */
#define LA_SPUR_ABSTANDDIFF_MIN (10.F)  /* OLD */

/* Zeit in s um SpurZeitErweiterungsFaktor bei Spurwechsel des */
/* relevantes Obj abzubauen */
#define LA_SPURZEIT_DEC         (0.66F)  /* OLD */

/* Max. Zeit fuer Rel.Obj in s */
#define LA_RELEVANTZEIT_MAX     (20.F)  /* OLD */

/* ! Constant for object width */
#define LA_MIN_OBJ_WIDTH_CAR_STAT               (1.8f)
#define LA_MAX_OBJ_WIDTH_CAR_STAT               (3.0f)
#define LA_OBJ_WIDTH_CAR_MOVE                   (1.8f)
#define LA_OBJ_WIDTH_TRUCK                      (2.5f)
#define LA_MIN_OBJ_WIDTH_OTHER_CLASS_STAT       LA_MIN_OBJ_WIDTH_CAR_STAT
#define LA_MAX_OBJ_WIDTH_OTHER_CLASS_STAT       LA_MAX_OBJ_WIDTH_CAR_STAT
#define LA_OBJ_WIDTH_SMALL_OBJ                  (0.8f)
#define LA_OBJ_WIDTH_MOVE                       (2.f)
/* minimaler Abstand ab dem alle Objekte Minimumbreite annehmen */
#define LA_ACC_MIN_DIST_OBJ_WIDTH_DIST_ADAPTED  (110.f)
/* minimale Breite zur Overlapberechnung fuer Objekte in weitem Abstand */
#define LA_ACC_MIN_OBJ_WIDTH_FAR_DIST           (1.8f)
#define LA_MIN_OBJ_WIDTH_STAT                   (0.8f)
#define LA_MAX_OBJ_WIDTH_STAT                   (2.f)

#define LA_OBJ_WIDTH_VAR_MOVE_NEAR              (0.33f)
#define LA_OBJ_WIDTH_VAR_FACTOR                 (0.25f)


/*--- la_corridor_trackwidth.c ---*/

#define LA_ACC_TRAJECTORY_WIDTH_STAT       (2.6f)
#define LA_ACC_TRAJECTORY_NARROWWIDTH_STAT (2.0f)

#define LA_PAR_MAX_DISTX_STAT_POINT_SMALL_SEEK  (60.f)


/*--- la_corridor_radarroad.c ---*/

/*! Velocity threshold to ignore the roadtype Highway for the guardrail extension*/
#define LA_GUARDRAILEXT_V_THRES   (80.f/C_KMH_MS)

#if LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS
#define LA_RIGHT_TRAFFIC_ORIENT_DISTY_LIMIT  (-2.f)
#define LA_LEFT_TRAFFIC_ORIENT_DISTY_LIMIT   (2.f)
#define LA_ADAPT_RBEXT_LESSER_WIDTH_OBJS     (0.5f)
#endif /* end of LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS */

/* Konstanten fuer LA_SRandUnsicherAbstand */
#define LA_FSZ_SRAND_ABST_MIN    (30.F)
#define LA_FSZ_SRAND_ABST_MAX    (150.F)
#define LA_FSZ_SRANDUNSICHER_MIN (1.5F)
#define LA_FSZ_SRANDUNSICHER_MAX (4.0F)

/*--- la_predictions.c ---*/
/*! defines prediction time (of lateral displacement) for cut in potential estimation (s)*/
#define LA_CutInPotPredTime (1.0f)/*SiLatDisplPredictionTime*/
#define LA_CutInPotPredTimeLimited (0.5f)
#define LA_LaneAssPredTime (1.0f)

/*! defines the maximum and minimum prediction times for cut out potential */
#define LA_CUT_OUT_PRED_MAX (1.0f)
#define LA_CUT_OUT_PRED_MIN (0.5f)

/*! defines the maximum and minimum distances (in time!!!) for maximum and minimum prediction time for cut out potential */
#define LA_CUT_OUT_DIST_MAX (3.0f)
#define LA_CUT_OUT_DIST_MIN (2.0f)

#define LA_MAX_VEHICLE_SPEED_LIMIT_PREDICTION (60.f/C_KMH_MS)


/*--- la_pred_lane_assoc.c ---*/

/* PARAMETERS FOR PREDICTED LANE ASSOCIATION */

/* default high prediction time for initialisation */
#define LA_PRED_TIME_INIT_HIGH          (5.f)

/* default high prediction distance for initialisation */
#define LA_PRED_DIST_INIT_HIGH          (1.f)

/* general constraints */
#define LA_PRED_OBJ_LONG_VREL_MIN       (-100.f/C_KMH_MS)
#define LA_PRED_EGO_VEL_MIN             (80.f/C_KMH_MS)
#define LA_PRED_OBJ_DISTX_MIN           (5.f)
#define LA_PRED_CLOSE_OBJ_DISTX_MAX     (59.f)
#define LA_PRED_TIME_LOWCURVE_MAX       (1.f/500.f)
#define LA_PRED_TIME_LOWCURVE_MIN       (1.f/2000.f)

/* no prediction in close range when object has high lateral distance */
#define LA_PRED_CLOSE_OBJ_DISTY_ABS     (2.5f)
#define LA_PRED_CLOSE_OBJ_DISTX         (35.f)

/* limit prediction time for object high lateral velocities e.g. to avoid selection of mirrors and ghosts */
#define LA_PRED_OBJ_VRELY_MAX_ABS       (5.f)

/* general maximum prediction time */
#define LA_PRED_TIME_MAX                (1.f)

/* Calculation of prediction based on Time to collision */
#define LA_PRED_TIME_TTC_DEP_MIN   (0.f)
#define LA_PRED_TIME_TTC_DEP_UPPER (8.f)
#define LA_PRED_TIME_TTC_DEP_LOW   (4.f)
#define LA_PRED_TIME_TTC_DEP_MAX   (1.f) /* CM : TTC */

#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST))
/* give lower prediction time for objects which has longitudinal distance less than 30m to reduce DropIn and DropOut */
#define LA_LOW_PRED_CLOSE_OBJ_DIST      (30.f)

/* maximum prediction time for the fusion system in case there is no camera confirmation */
#define LA_PRED_TIME_MAX_NO_CAM_CONF    (0.4f)
#endif /* ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST)) */

/* time (s) for moving objects for being predicted in/out-lane */
/* time is a fuction of time-gap */
#define LA_PRED_TIME_TG_DEP_MIN      (0.f)
#define LA_PRED_TIME_TG_DEP_MAX      (LA_PRED_TIME_MAX)
#define LA_PRED_TIME_TG_DEP_LOW      (1.5f)
#define LA_PRED_TIME_TG_DEP_UPPER    (2.5f)

/* time is a function of object longitudinal distance */
#define LA_PRED_TIME_DISTX_DEP_MIN      (0.f)
#define LA_PRED_TIME_DISTX_DEP_MAX      (LA_PRED_TIME_MAX)
#define LA_PRED_TIME_DISTX_DEP_LOW      (60.0f)
#define LA_PRED_TIME_DISTX_DEP_UPPER    (120.0f)

/* time is a function of object longitudinal distance for close objects */
#define LA_PRED_TIME_DISTX_CLOSE_DEP_MIN      (LA_PRED_TIME_MAX)
#define LA_PRED_TIME_DISTX_CLOSE_DEP_MAX      (0.4f)
#define LA_PRED_TIME_DISTX_CLOSE_DEP_LOW      (30.0f)
#define LA_PRED_TIME_DISTX_CLOSE_DEP_UPPER    (75.0f)
#define LA_PRED_TIME_DISTX_LOWEGOVEL_LOW      (40.0f)

/* time is a function of object longitudinal distance for close objects*/
#define LA_PRED_TIME_DISTX_CLOSE_DEP_MIN_NO_CAM_CONF      (LA_PRED_TIME_MAX_NO_CAM_CONF)
#define LA_PRED_TIME_DISTX_CLOSE_DEP_MAX_NO_CAM_CONF      (0.2f)

/* time is a function of ego curve */
#define LA_PRED_TIME_CURVE_DEP_MIN      (0.f)
#define LA_PRED_TIME_CURVE_DEP_MAX      (LA_PRED_TIME_MAX)
#define LA_PRED_TIME_CURVE_DEP_LOW      (1.f/1500.0f)
#define LA_PRED_TIME_CURVE_DEP_UPPER    (1.f/500.0f)

/* time is a function of High ego Velocity */
#define LA_PRED_TIME_EGOVEL_DEP_MIN      (0.f)
#define LA_PRED_TIME_EGOVEL_DEP_MAX      (0.4f)
#define LA_PRED_TIME_EGOVEL_DEP_LOW      (160.f/C_KMH_MS)
#define LA_PRED_TIME_EGOVEL_DEP_UPPER    (200.f/C_KMH_MS)

/* In free-drive mode take lower prediction time to avoid drop-ins */
#define LA_PRED_TIME_FREEDRIVE              (0.25f)
#define LA_PRED_TIME_FREEDRIVE_NO_CAM_CONF  (0.35f)

/* Defining max and min boarders for Cutout weight calculation */
#define LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MIN (0.5f)
#define LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MAX (1.5f)
#define LA_PRED_POTENTIAL_MAX_OUTPUT (1.0f)
#define LA_PRED_POTENTIAL_MIN_OUTPUT (0.0f)

#if (LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD)
/*! time is a function of lateral postion and velocity standard deviation  */
/*! Minimum ego radius for calculation of predtime extension */
#define LA_PRED_TIME_EMINPUTSTD_CURVE_MIN   (1.f/1000.f)
/*! Minimum relative longitudinal distance for calculation of predtime extension */
#define LA_PRED_MIN_RELX_POS               (11.0f)
/*! Maximum allowed lateral position standard deviation for calculation of predtime extension */
#define LA_PRED_DISTYSTD_MAX               (0.4275f)
/*! Minimum lateral position standard deviation for calculation of predtime extension */
#define LA_PRED_DISTYSTD_MIN               (0.3f)
/*! Maximum allowed lateral velocity standard deviation for calculation of predtime extension */
#define LA_PRED_VRELYSTD_MAX                (0.6275f)
/*! Minimum lateral velocity standard deviation for calculation of predtime extension */
#define LA_PRED_VRELYSTD_MIN                (0.5f)
/*! Maximum predtime extension */
#define LA_PRED_TIME_MAX_EXT_LAT_STD                 (0.1275f)
#endif /* LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD */

#if (SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE)
/*! The camera confidence gate used to decide if a given object uses the turnindicator or not*/
#define LA_TURNIND_CONF_MIN      50u
/*! Threshold for relative velocity, if an object is performing a lanechange */
#define LA_TURNIND_VRELY_THRES 0.1f
/*! Value for predtime if a turnindicator scenario is detected */
#define LA_PRED_TIME_TURNIND 1.5f
#endif /* SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE */

#if ((SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) && (LA_CFG_EGO_TURNIND_BASED_PICKUP))
/*! Threshold for relative velocity, if ego is performing a lanechange */
#define LA_EGOTURNIND_VRELY_THRES (0.1f)
/*! Value for predtime if ego turn indicator scenario is detected */
#define LA_PRED_TIME_EGOTURNIND (1.5f)
/*! Minimum distance for calculation of predtime if ego turnindicator is detected */
#define LA_EGO_TURNIND_MIN_DISTX    (20.f)
/*! Maximum distance for calculation of predtime if ego turnindicator is detected */
#define LA_EGO_TURNIND_MAX_DISTX    (100.f)
/*! Maximum lateral distance for calculation of predtime if ego turnindicator is detected */
#define LA_EGOTURNIND_MAX_DISTY     (3.5f)
#endif /* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT && LA_CFG_EGO_TURNIND_BASED_PICKUP*/

/*! Distance based CutIn/Out potential */
#define LA_TIME_TO_DIST_TRANS_FACTOR (1.0f)

/*--- la_laneassociation.c ---*/

#define LA_STATIONARY_STRASSENBREITE (2.5f)

/*! definitions for  NEAR Range track width rise */
#define LA_EGO_SPEED_MAX_FOR_WIDE_NEAR_TRACK  (25.0f/C_KMH_MS)
#define LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK  (10.0f)
#define LA_MAX_DIST_FOR_FOR_WIDE__NEAR_TRACK  (15.0f)
#define LA_WIDE_NEAR_TRACK_WIDTH (3.75f)
#define LA_WIDE_NEAR_OBJECT_WIDTH (1.8f)
#define LA_EGO_SPEED_MIN_FOR_WIDE_NEAR_TRACK  (15.0f/C_KMH_MS)
#define LA_WIDE_NEAR_TRACK_FACTOR_MIN (0.0f)
#define LA_WIDE_NEAR_TRACK_FACTOR_MAX (1.0f)

/*--------------- Definitions for unlearned steering angle offset restrictions-----------------------*/
/*! max. distance for stationary objects, if sensor is unlearned (steering angle offset) */       /*|*/
#define LA_ACC_RANGE_MAX_UNLEARNED_SENSOR_STATIONARY (70.0F)                                      /*|*/
/*|*/
/*! Inlane time for stationary objects is rised by below factor in umlearned situation */         /*|*/
#define LA_UNLEARNED_SENSOR_INLANE_TIME_RISE_FACTOR (1.2F)                                        
/*! Below this distance objects are safe even if steering angle is unlearned */                   /*|*/
#define LA_SAFE_DIST_UNLEARNED             (30.0F)                                                
/* if varianvce value of steering angle is bigger than this value, sensor is unlearned !!! */     /*|*/
#define LA_VDY_YAWRATE_QUAL_SENSOR_UNLEARNED (0.55F)                                              

/*! maximum registered accumulated driven distance where an object was relevant */
#define LA_INLANE_DIST_MAXVALUE       (200.0f)

/*! Parameters used for disabling the orientation based width adaption for OOI-0 */
#if(LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0)
#define LA_OBJECT_ORIENTATION_NEAR_OBJECTS_FOR_OOI0_EGOVEL  (15.f/C_KMH_MS) /* Maximum ego velocity */
#define LA_OBJECT_ORIENTATION_NEAR_OBJECTS_FOR_OOI0_CURVE   (1.F/1000.F) /* Maximum curve */
#endif
/*--- la_laneassociation_stateflow.c ---*/

#if ((LA_CFG_NOLANE_BIKE_SELECTION) || (LA_CFG_NOLANE_VEHICLE_SELECTION))
/*! select bikes as neighbouring object even if there is no lane detected*/
#define LA_MOVING_CLIP_BIKE_ROAD_BORDER_ABSDIST (2.50f)  /*<! considered distance to roadborder if no roadborder estimation available*/ 
#define LA_MOVING_CLIP_BIKE_ROAD_BORDER_MAX   (2.0f * LA_MOVING_CLIP_BIKE_ROAD_BORDER_ABSDIST ) /*<! maximal considered distance to roadborder */
#if (LA_CFG_NOLANE_VEHICLE_SELECTION)
#define LA_MOVING_CLIP_VEH_DISTX_MIN          (5.0f)  /*<! for CAR & TRUCK do not consider obejcts in very close distances (avoid ghost objects) */
#endif
#endif

/*! in tunnels select oncoming objects on adjacent lanes up to this distance to trajectory */
#define LA_ONCOMMING_MIN_DIST2ROADBORDER_TUNNEL (2.F * STRASSENBREITE)

/*! parameter specifying minimum for road border stat left/right for discarding
oncomming objects that are outside of the road border estimation */
#define LA_ONCOMMING_ROAD_BORDER_CLIP_MIN_STAT  (100u)

#define LA_ONCOMING_CLIP_ABSDIST (9.0f)

/*--- la_corridor_scene.c ---*/

#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD)
/*! maximal extension in situations which are clear */
#define LA_MAX_LOW_SPEED_FUSEDBRD_EXTENSION        (3.5f)
/*! minimal extension in situations which are unclear, i.e. signals contradictory */
#define LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION        (2.5f)
/*! default extension */
#define LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION    (3.7f)
/*! maximum speed up to which extension is executed */
#define LA_MAX_SPEED_LOW_SPEED_FUSEDBRD_EXTENSION  (30.f/C_KMH_MS)
/*! maximum speed up to which default extension is executed */
#define LA_MAX_SPEED_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION  (5.f/C_KMH_MS)
/*! maximum distance of relevant object up to which extension is executed */
#define LA_MAX_DISTX_LOW_SPEED_FUSEDBRD_EXTENSION  (20.f)
/*! maximum distance for default extension */
#define LA_MAX_DISTX_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION (10.f)
/*! maximum gap between fused road border and relevant object */
#define LA_MAX_GAP_LOW_SPEED_FUSEDBRD_EXTENSION    (4.5f)
#define LA_MIN_GAP_LOW_SPEED_FUSEDBRD_EXTENSION    (2.5f)
/* maximum curve radius up to which extension is executed */
#define LA_MAX_CURVE_RADIUS_LOW_SPEED_FUSEDBRD_EXTENSION (0.1f)
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY || LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER)
/*Maximun lateral position of Object to apply extention */
#define LA_MAX_LATERAL_POS_DRIVER_STEER             (1.2f)
/* Sufficient distance from Ego to Road Border to drive */
#define LA_SUFFICIENT_DIST_TO_RB_TO_DRIVE                      (3.0f)
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)
/* low fused border extension high curve scenario check*/
#define LA_LFBE_HIGH_CURVE                 (1.F/500.F)
/* Minimum forientaion value check for low fused border  */
#define LA_FORIENTATION_BOUNDARY_VAL           (0.3f)
/*! forientation extension minimum boundary val*/
#define LA_FORIENTATION_LOW_SPEED_FUSEDBRD_EXTENSION    (2.64f)
#endif /* endof (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)*/

#if (LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ)
/* Maximum threshold of distance to trajectory under which low speed fused road border will be applied */
#define LA_MAX_DIST2TRAJ                      (2.5f)
#endif /* (LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ) */

#endif /* endof (LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY || LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER)*/
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM )
/* Extend the trace bracket when the object is within the camera lane marker */
#define LA_LOWSPEEDFUSEDBRD_CAMLANE_WIDTH  (2.7f)
#define LA_LOWSPEEDFUSEDBRD_CAMLANE_HALF   (LA_LOWSPEEDFUSEDBRD_CAMLANE_WIDTH/ 2.f)
#endif /* (LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM ) */
#endif /* (LA_CFG_EXT_LOWSPEEDFUSEDBRD) */

/*--- la_customfunctions.c ---*/

//#define ABST_GRENZ_NAHBEREICH          (11.0F)
/* min. Objektlebensdauer f?uer Absenkung der Zielschwelle */
/* auf -ZIEL_SENK_MAX */
//#define OBJLEB_ZIEL_SENK     (CONV_CYCLES_TO_LIFETIME(20))  /* OLD */

/*-------------------------------------------------------------------------
| Constants for lane widths used in corridor criteria                     |
-------------------------------------------------------------------------*/

/*! The tracked objects maximum additional lane width */
#define LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MAX   (1.1f)

/*! The tracked objects minimum additional lane width */
#define LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MIN   (0.7f)

/*! The seek lane width corresponding to the ego speed of #LA_MAX_SPEED_HIGWAYLANEWIDTH */
#define LA_HIGHWAYLANEWIDTHSEEK_MAX           (3.55f)
/*! The seek lane width corresponding to the ego speed of #LA_MIN_SPEED_HIGWAYLANEWIDTH */
/*! The ego speed for maximum seek lane width on highways */
#define LA_MAX_SPEED_HIGWAYLANEWIDTH          (160.0f/C_KMH_MS)
/*! The ego speed for minimum seek lane width on highways */
#define LA_MIN_SPEED_HIGWAYLANEWIDTH          (130.0f/C_KMH_MS)


/* Minimum confidence of road estimation (RE) */
#define LA_MIN_GUARDRAIL_ROAD_CONFIDENCE       (84.F)
/* RE range needs to reach at least x meter behind object */
#define LA_MIN_GUARDRAIL_ROAD_RANGE_OFFSET     (10.F)
/* OFfset of trace bracket behind RE */
#define LA_MAX_GUARDRAIL_ROAD_HALF_OBJ_WIDTH   (1.1F)
/* maximum offset of guardrail at ego vehicle on highway*/
#define LA_MAX_GUARDRAIL_OFFSET_HIGHWAY        (4.8F)
/* maximum offset of guardrail at ego vehicle on highway*/
#define LA_MAX_GUARDRAIL_OFFSET_ROADWORKS      (2.25F)

/* NBS Diagnose test setting, moved here from si.h / sa.h */
#if (LA_CFG_NBS_DIAGNOSE_TEST)
/* Maximaler Oeffnungswinkel fuer NBS Bandendetest */
#define LA_NBS_MAXWINKEL   (2.5F)
/* Minimale Ablage im NBS-Diagnosemode */
#define LA_NBS_BRACKET_POSITION_LEFT    (-1.50F)
#define LA_NBS_BRACKET_POSITION_RIGHT   ( 2.00F)
#endif


#if (LA_CFG_MANIPULATE_OCCUPANCY_AT_HIGH_ANGLES)
/*! The scaling factor used for the occupancy standard deviation value at LA_STDDEV_OBJ_OCC_ANGLE_MAX */
#define LA_STDDEV_OBJ_OCC_FAC_MAX     (1.0f)
/*! The scaling factor used for the occupancy standard deviation value at LA_STDDEV_OBJ_OCC_ANGLE_MIN */
#define LA_STDDEV_OBJ_OCC_FAC_MIN     (0.4f)
/*! The angle where the LA_STDDEV_OBJ_OCC_FAC_MAX scaling factor is used */
#define LA_STDDEV_OBJ_OCC_ANGLE_MAX   (8.0f)
/*! The angle where the LA_STDDEV_OBJ_OCC_FAC_MIN scaling factor is used */
#define LA_STDDEV_OBJ_OCC_ANGLE_MIN   (15.0f)
#endif


#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
#define LA_NAVI_COUNTRYROAD_EXT_MIN         (0.7f)     /*!< Minimal extension if trace brackets for countryroads */
#define LA_NAVI_COUNTRYROAD_EXT_MAX         (8.25f)     /*!< Maximal extension if trace brackets for countryroads */
#define LA_NAVI_COUNTRYROAD_EGO_SPEED_MAX   (75.f/C_KMH_MS) /*!< Maximal ego speed to apply CR-extension on slow objects*/   
#define LA_NAVI_COUNTRYROAD_VREL_MIN        (-50.f/C_KMH_MS) /*!< Minimal vrel of object to apply CR-extension on slow object*/
#define LA_DISTX_NAVI_COUNTRYROAD_EXT_MIN   (5.f)     /*!< Distance to object for minimal trace bracket extension */
#define LA_DISTX_NAVI_COUNTRYROAD_EXT_MAX   (35.f)    /*!< Distance to object for maximal trace bracket extension */
#define LA_MAX_DIFF_ORIENT_OBJ_NAVI_COUNTRYROAD_EXT       (0.15f) /*!< Maximal difference between object orientation and ACC-Trajectory for trace bracket extenstion */
#define LA_MAX_LC_PROB_NO_CAM_LANE_NAVI_COUNTRYROAD_EXT   (50u)   /*!< Maximal lane change probability for the trace bracket extension if no camera lane available */
#define LA_MIN_DIFF_ZO_OVERTAKE_NSO         (10.f)    /*! Minimal distance between ZO and next lane object for no overtake manoeuvre */
#define LA_NAVI_TRACE_YINTERSECT_DEFAULT_THRESHOLD (999.f) /*!< Default threshold for trace-y-intersection, indicating that trace has not yet reached ego-vehicle*/
#define LA_MAX_TRACE_Y_INTERSECT_NAVI_EXTENSION (2.0f) /*!< Maximal trace-y-intersection for usage of country road corridor extension*/
#define LA_MAX_COURSE_GRADIENT_TRACE_INTERSECT_NAVI_EXTENSION (0.003f) /*!< Maximal ego course gradiant for usage of trace-y-intersection-criterion*/
#define LA_MAX_EGO_CURVE_TRACE_INTERSECT_NAVI_EXTENSION (0.0015f) /*!< Maximal ego curvature for usage of trace-y-intersection-criterion*/
#if (SLATE_CFG_CAM_LANE_INTERFACE)
#define LA_NAVI_MIN_CAM_VISIBILITY          (10.f)    /*! Minimal camera lane visibility for trusting the info of the camera */
#if 0
#define LA_NAVI_MIN_CAM_LANE_WIDTH          (1.5f)    /*! Minimal camera lane width */
#define LA_NAVI_MAX_CAM_LANE_WIDTH          (5.f)     /*! Maximal camera lane width */
#endif
#define LA_MAX_LC_PROB_CAM_LANE_NAVI_COUNTRYROAD_EXT      (75u)   /*!< Maximal lane change probability for the trace bracket extension if camera lane available */
#endif
#endif


#if (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
#define LA_NAVI_EXIT_SCALE_RESTIC_MIN             (0.5f)  /*!< Minimal scale factor for reducing the trace bracket width */
#define LA_NAVI_EXIT_SCALE_RESTIC_MAX             (1.f)   /*!< Maximal scale factor for reducing the trace bracket width */
#define LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MIN       (0.f)   /*!< Longitudinal distance for minimal trace bracket scale factor */
#define LA_DISTX_NAVI_EXIT_SCALE_RESTIC_MAX       (30.f)  /*!< Longitudinal distance for maximal trace bracket scale factor */
#define LA_MIN_DIFF_ORIENT_OBJ_NAVI_EXIT_RESTIC   (0.2f)  /*!< Minimal difference between object orientation and ACC-Trajectory for trace bracket restriction */
#define LA_MAX_DISTX_NAVI_EXIT                    (30.f)  /*!< Maximal longitudinal distance to object for applying trace bracket restriction */
#define LA_MAX_VREL_NAVI_EXIT                     (-0.5f) /*!< Maximal relative velocity of object for applying trace bracket restriction */
#endif

#if( (LA_CFG_NAVI_COUNTRYROAD_EXTENSION) || (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION) )
#define LA_NAVI_MAX_EGO_DISTX_TO_EXIT             (230.f) /*!< Maximal ego distance to exit for considering the exit */
#define LA_NAVI_MAX_OBJ_DISTX_TO_EXIT             (200.f)  /*!< Maximal distance to exit for considering the object close to the exit */
#define LA_NAVI_MIN_OBJ_DISTX_TO_EXIT             (-20.f)  /*!< Minimal distance to exit for considering the object close to the exit */
#endif

#if(SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
#define LA_OCCLUSION_MAX_DIST                     (90.f)  /*!< Maximal distance for occlusion consideration */
#define LA_OCCLUSION_MIN_DIST_NO_HIGHWAY          (30.f)  /*!< Minimal distance for occlusion consideration on no highway*/
#define LA_OCCLUSION_MIN_VEL_NO_HIGHWAY           (20.f/C_KMH_MS)   /*!< Minimal velocity for occlusion consideration on no highway*/
#define LA_PAR_OCC_HIGHWAY_INLANE_TIME_FAC        (5.f)   /*!< In-lane threshold time factor when occlusion is detected on a highway */
#define LA_PAR_OCC_NO_HIGHWAY_INLANE_TIME_FAC     (2.f)   /*!< In-lane threshold time factor when occlusion is detected on no highway */
#endif

#define LA_MAX_OBJ_DEV_PRED_LA                    (12u) 	/*!< Maximum cluster spread of object to calculate predicted inlane criteria */
#define LA_MIN_DIST_OBJ_DEV_DISTX                 (50.f)	/*!< Minimum longitudinal distance to consider cluster spread for predicted inlane criteria */

/*****************************************************************************
  Tracebracket parameters (used in la_corridor_trackwidth.c)
*****************************************************************************/
#define LA_TB_EXT_MIN_VELOCITY  (110.0f/C_KMH_MS)
#define LA_TB_EXT_MAX_CURVATURE (0.001f)

/******************************************************************************
  la_laneassociation.c parameters
******************************************************************************/
/* Pickup and drop thresholds for lane selection of moving objects */
#define LA_OBJ_INLANE_PICKUP_THRES     1.0f
#define LA_OBJ_INLANE_DROP_THRES       0.66f

#define LA_OBJ_INLANE_ADJ_THRES  0.35f
#define LA_OBJ_DROP_ADJ_THRES 0.32f

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
/* Navi Trajectory Dist to Object lateral Distance Inlap Pick Up Threshold */
#define LA_CITY_MAX_SPEED            (65.f/C_KMH_MS)
#define LA_CITY_MIN_SPEED            (3.f/C_KMH_MS)
#define LA_ALLOWED_EGO_CURVE         (1.f/250.f)

#define LA_INLAP_PU_NAVI_NEAR_OBJ    (0.7f)
#define LA_INLAP_PU_NAVI_FAR_OBJ     (1.2f)
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
#endif  /* end of (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */

/*Max. Inlap variance for normal object occupancy drop border*/
#define LA_OBJ_INLANE_DROP_MAX_INLAP_VAR 0.45f
/*object occupancy drop border for insecure inlap values     */
#define LA_OBJ_INLANE_DROP_INSECURE_INLAP 0.40f

/* Pickup and drop thresholds for lane selection of stationary and oncoming objects */
#define LA_OBJ_INLANE_PICKUP_THRES_STAT 0.98f
#define LA_OBJ_INLANE_PICKUP_THRES_STAT_POINT 0.98f
#define LA_OBJ_INLANE_DROP_THRES_STAT   0.45f

#if (LA_CFG_ENABLE_PARKED_DETECTION)
#define MIN_NUM_OF_DETECTED_PARKING_CARS    (3u)      /*!< Minimum number of detected parking cars to reduce reaction. [has to be > 0 and < 40]*/
#define MAX_NUM_OF_PARKING_CARS             (5u)      /*!< Maximum number of detected parking cars to reduce reaction. [has to be >MIN_NUM_OF_DETECTED_PARKING_CARS and < 40] */
#define LA_MAX_LONG_RD_OBJ_GAP_SIZE         (20.f)    /*!< Maximum longitudinal distance between cars in parking row */
#define LA_MAX_LAT_RD_OBJ_GAP_SIZE          (2.f)     /*!< Maximum lateral distance between cars in parking row  */ 
#define LA_MAX_FACTOR_RD_TO_AVRG            (2.5f)    /*!< Dist2RoadBoarder-Average Dist 2 RoadBoarder  */ 
#define LA_PARKING_CORR_WIDTH_IN            (-1.8)    /*!< Parked Objects coridor width inside */
#define LA_PARKING_CORR_WIDTH_OUT           (1.8)     /*!< Parked Objects coridor width Outside */
#define PARKED_OBJ_DETECTION_RANGE          (70)      /*!< maximum Parked Object detection range */
#define LA_MIN_OBJ_DIST_PARKING_ROW_RB      (10.f)    /*!< Minimum longitudinal distance to identify parking cars */
#define MAX_CITY_SPEED_THRESH_RB            (65.f/C_KMH_MS)

#define LA_OBJ_INLANE_PICKUP_THRES_PARKED_OBJ 1.25f   /*!< Updated Inlap pickup threshold for Parked stationary Vehicles */

#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */
/* Pickup and drop thresholds for lane selection of stationary and oncoming objects in Road Works or unlearned sensor*/
#define LA_OBJ_INLANE_PICKUP_THRES_STAT_CONSERVATIVE   0.67f
#define LA_OBJ_INLANE_DROP_THRES_STAT_CONSERVATIVE     0.55f

/* Pickup and drop thresholds for predicted lane selection of moving objects */
#define LA_OBJ_INLAP_PRED_PICKUP_THRESH               (0.4f)
#define LA_TRUCK_OBJ_INLAP_PRED_PICKUP_THRESH         (0.7f)
#define LA_MAX_OBJ_INLAP_PRED_PICKUP_THRESH           (1.0f)
#define LA_LOW_NEAR_DIST_OBJ_INLAP_PRED_DROP_THRESH   (0.75f)

#define LA_INLAP_MOVE_OBJ_IN_LANE_MIN    (1.7f)

#define LA_MINFAC_MOVE_OBJ_IN_LANE_MAX   (0.1f)
#define LA_MINFAC_MOVE_OBJ_IN_LANE_MIN_X   (0.01f)

/*Maximum and minimum distances in which the slope of the ramp function which reduces PICKUP threshold w.r.t distance is defined*/
#define LA_DISTX_PICKUP_REDUCTION_MAX   (73.0f)
#define LA_DISTX_PICKUP_REDUCTION_MIN   (1.0f)

/* Curve Parameter for situative increase of Pick-up and Drop threshold of Inlap */
#define LA_INLANE_CURVE_MIN                         (0.001f)
#define LA_OUTLANE_INLAP_MUL_FACT                   (0.80f)
#define LA_INLANE_INLAP_MUL_FACT                    (1.3f)

/* Parameter for situative decrease of Pickup threshold of Inlap */
#define LA_GEO_EGO_VEL_MIN  (79.2f/C_KMH_MS)
#define LA_GEO_REL_X_VEL_MIN  (0.0f)
#define LA_GEO_REL_X_MIN  (10.0f)

/* Parameter for situative increase of Drop threshold of Inlap */
#define LA_ADAPT_OUTLANE_INLAP_MUL_FACT               (1.4f)
#define LA_MIN_DIFF_OF_ABS_VEL_IN_X                   (0.2227f)
#define LA_MIN_ABS_VEL_OF_HID_OOI_IN_X                (0.2227f)
#define LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_EGO         (10.0f)
#define LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_HIDOOI      (5.0f)

/* Parameter for Indicator timer Maximum and Minimum */
#if (LA_CFG_TURN_INDICATOR_COUNTER)
#define LA_EGO_LANE_CHANGE_IND_TIMER_MAX              (5.5f)                 /*!< Maximum indicator timer while ego lane change */
#define LA_EGO_LANE_CHANGE_IND_TIMER_ZERO             (0.f)                  /*!< Threshold check for Timer expire */
#endif /*end of LA_CFG_TURN_INDICATOR_COUNTER*/

/* Parameter for setting timer for restriction ego lane change*/
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
#define LA_EGO_LC_RESTRICT_TIMER_MAX          (1.5f)                 /*!< Timer for Ego lane change restriction */
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */

/* Cycle time threshold for considering the Outlane: If the object is atlease this much cycle should be there outlane. This is for improving the Drop-outs due to the trajectory shift */
#define LA_OUTLANE_CYCLE_MIN                        (2u) 
#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
#define LA_OUTLANE_CYCLE_REL_VEL_MAX                (20.F/C_KMH_MS) 
#define LA_OUTLANE_CYCLE_SMALL_CURVE                (1.F/1000.F) 
#define LA_OUTLANE_CYCLE_HIGH_CURVE                 (1.F/1600.F) 
#define LA_OUTLANE_OBJ_DISPL_CLOSE                  (60.0F) 
#define LA_OUTLANE_OBJ_RELEV_TIME                   (5.0F) 
#define LA_OUTLANE_LANE_CHNG_PROB                   (45u)
#define LA_OUTLANE_EGO_SPEED_LOW                    (70.F/C_KMH_MS)
#define LA_OUTLANE_ZERO_THRESHOLD                   (0.f) 
#define LA_OUTLANE_CYCLE_TURN_IND                   (1u)
#define LA_OUTLANE_CYCLE_LANE_CHANGE                (2u)
#define LA_OUTLANE_CYCLE_CUTOUT                     (2u) 
#define LA_OUTLANE_CYCLE_HIGH_REL_VEL               (2u)
#define LA_OUTLANE_CYCLE_STRAIGHT                   (3u) 
#define LA_OUTLANE_CYCLE_DIST_HIGH_CURV             (4u) 
#define LA_OUTLANE_CYCLE_DIST_NARROW_HIGH           (4u) 
#define LA_OUTLANE_CYCLE_PICKUP                     (4u)
#define LA_OUTLANE_CYCLE_MOVING_OBJ                 (4u)
#define LA_OUTLANE_CYCLE_CLOSE_CURVE                (5u)
#define LA_OUTLANE_COUNT_STRONG_CURVE               (8u)
#if (LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC)
#define LA_OUTLANE_COUNT_CAM_LANE_EGO               (15u)           /* Outlane counter value if associated to ego lane by camera trajectory lane association*/
#define LA_OUTLANE_COUNT_CAM_LANE_OBJ_DIST          (10.F)          /* Maximum object distance */
#define LA_OUTLANE_COUNT_CAM_LANE_EGO_VEL           (15.f/C_KMH_MS) /* Maximum ego velocity */
#define LA_OUTLANE_COUNT_CAM_LANE_EGO_CURVE         (1.F/1000.F)    /* curve to check ego intends to follow the object */
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC) */
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */

/* Parameters for Camera Lane Existance probability to use in Camera Trajectory Lane Association */
#if(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
#define LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB        (50u)  /* Initial existance probability Threshold */
#define LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB_MAX    (70u)  /* Maximum existance probability Threshold */
#define LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB_MIN    (10u)  /* Minimum existance probability Threshold */
#define LA_CAM_TRAJ_PROB_PERCENT_UCONVERT            (100u)
#define LA_OBJ_LANE_ASSOC_CAM_TRAJ_LANEWIDTH_OFFSET  (1.F)  /* Maximum possible offset in the lane width */
#define LA_CAM_TRAJ_LA_PROB_DIST_FACTOR_MAX          (1.F)  /* Maximum possible Probability distance factor */
#define LA_CAM_TRAJ_LA_PROB_DIV                      (2.F)  /* Divide  to get half value*/
#define LA_CAM_TRAJ_LA_PROB_HALF                     (0.5F) /* Multiplication factor to get half value*/
#define LA_CAM_TRAJ_LA_PROB_LC_THD                   (25u)  /* Lane change probability threshold */
#define LA_CAM_TRAJ_LA_PROB_CURVE_THRES              (1.F/100.F) /* Curve threshold */
#define LA_CAM_TRAJ_LA_PROB_ZERO                     (0.F)  /* Zero Threshold */
#define LA_CAM_TRAJ_LA_PROB_LANE_WIDTH               (40.F) /* Fixed probability if lane marker distance is higher than a maximum threshold */
#define LA_CAM_TRAJ_LA_PROB_OPPOSITE_CURVE           (35.F) /* Fixed probability if both curves are in opposite direction */
#define LA_CAM_TRAJ_LA_PROB_LANE_CHANGE              (30.F) /* Fixed probability during lane change */
#define LA_CAM_TRAJ_LA_PROB_HIGH_CURVE               (20.F) /* Fixed probability during high curve */
#endif /* (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */

/* Parameters for tuning pickup threshold based on Camera Trajectory Lane Association */
#if (LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA)
#define LA_CAM_TRAJ_LA_PICKUP_PROB                   (70.F) /* Minumum probability of camera trajectory lane association*/
#define LA_CAM_TRAJ_LA_PICKUP_THRES                  (0.4F) /* Minumum probability of camera trajectory lane association*/
#endif /* (LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA) */

/* Parameters for applying City Near Restriction using Camera Trajectory Lane Association */
#if(LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ)
#define LA_RESTRICTION_CITY_NEAR_CAM_TRAJ_OBJ_DIST   (20.F)          /* Object Distance Threshold */
#define LA_RESTRICTION_CITY_NEAR_CAM_TRAJ_VREL       (0.F)           /* Object relative velocity threshold */
#define LA_RESTRICTION_CITY_NEAR_CAM_TRAJ_EGOVEL     (15.F/C_KMH_MS) /* Ego velocity Threshold */
#endif

/* For outlane->inlane transition object inlap is corrected by substraction of standard deviation from inlap. Tuning by weight factor */
#define LA_INLAP_CORR_STD_DEV_WEIGHT_FACTOR (0.7f)

/* Required Distance in lane for a stationary obstacle to become relevant

                                  x[m] ^
                                       |
             LA_STATXXX_INLANE_DISTMAX_|_                      ______________
                                       |                      /|
                                       |                     /
                                       |                    /
                                       |                   /
                                       |                  /
                                       |                 /
                                       |                /
                                       |               /
                                       |              /
                                       |             /
             LA_STATOBJ_INLANE_DISTMIN_|_    _______/
                                       |    /|     |
                                       |  /
                                       |/
                                       0-----|-----|-----------|---------------> V [m/s]
                                       |     |     |           |
                                       v0    v1    v2          v3
v0:LA_STATXXX_INLANE_NOSPEED
v1:LA_STATXXX_INLANE_PARKSPEED
v2:LA_STATXXX_INLANE_LOWSPEED
v3:LA_STATOBJ_INLANE_HIGHSPEED

*/

/* time (s) for stationary objects for being accepted in lane */
#define LA_STATOBJ_INLANE_HIGHSPEED       (100.0f/C_KMH_MS) /* [m/s] */
#define LA_STATOBJ_INLANE_LOWSPEED        (25.0f/C_KMH_MS) /* [m/s] */
#define LA_STATOBJ_INLANE_PARKSPEED       ( 5.0f/C_KMH_MS) /* [m/s] */
#define LA_STATOBJ_INLANE_NOSPEED         (   C_F32_DELTA) /* [m/s] */

#define LA_STATOBJ_INLANE_DISTMAX         (20.0f) /* [m] */
#define LA_STATOBJ_INLANE_DISTMIN         ( 5.0f) /* [m] */
#define LA_STATOBJ_INLANE_DISTSLOPE       ((LA_STATOBJ_INLANE_DISTMAX - LA_STATOBJ_INLANE_DISTMIN)/(LA_STATOBJ_INLANE_HIGHSPEED - LA_STATOBJ_INLANE_LOWSPEED)) /* [s] */
#define LA_STATOBJ_INLANE_DISTOFFSET      (LA_STATOBJ_INLANE_DISTMAX - (LA_STATOBJ_INLANE_DISTSLOPE * LA_STATOBJ_INLANE_HIGHSPEED)) /* [m] */

#define LA_STATOBJ_INLANE_TIME_PARKSPEED  (LA_STATOBJ_INLANE_DISTMIN/LA_STATOBJ_INLANE_PARKSPEED) /* [s] */
#define LA_STATOBJ_INLANE_TIME_NOSPEED    (0.72f) /* [s] */


/* time (s) for stationary vehicles(Truck, Car, Motorcycle) for being accepted in lane */
#define LA_STATVEH_INLANE_HIGHSPEED       (100.0f/C_KMH_MS) /* [m/s] */
#define LA_STATVEH_INLANE_LOWSPEED        ( 25.0f/C_KMH_MS) /* [m/s] */
#define LA_STATVEH_INLANE_PARKSPEED       (  5.0f/C_KMH_MS) /* [m/s] */
#define LA_STATVEH_INLANE_NOSPEED         (    C_F32_DELTA) /* [m/s] */

#define LA_STATVEH_INLANE_DISTMAX         (20.0f) /* [m] */
#define LA_STATVEH_INLANE_DISTMIN         ( 5.0f) /* [m] */
#define LA_STATVEH_INLANE_DISTSLOPE       ((LA_STATVEH_INLANE_DISTMAX - LA_STATVEH_INLANE_DISTMIN)/(LA_STATVEH_INLANE_HIGHSPEED - LA_STATVEH_INLANE_LOWSPEED)) /* [s] */
#define LA_STATVEH_INLANE_DISTOFFSET      (LA_STATVEH_INLANE_DISTMAX - (LA_STATVEH_INLANE_DISTSLOPE * LA_STATVEH_INLANE_HIGHSPEED)) /* [m] */

#define LA_STATVEH_INLANE_TIME_PARKSPEED  (LA_STATVEH_INLANE_DISTMIN/LA_STATVEH_INLANE_PARKSPEED) /* [s] */
#define LA_STATVEH_INLANE_TIME_NOSPEED    (0.72f) /* [s] */

#if (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA)
#define LA_CFG_ADAPT_IN_LANE_TIME_CAM_TRAJ_LA_EGOSPEED   (65.f/C_KMH_MS)  /*Ego Speed Threshold to reduce in-lane time threshold based on Camera Trajectory LA */
#define LA_CFG_ADAPT_IN_LANE_DIST_CAM_TRAJ_LA_EGOSPEED   (65.f/C_KMH_MS)  /*Ego Speed Threshold to reduce in-lane distance threshold based on Camera Trajectory LA */
#endif /* (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA) */

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*! Maximum inlane time threshold for stationary objects seen by camera to be in-lane */
#define LA_CAM_INLANE_STAT_INLANETIME           (0.1f)
/*! Maximum inlane time threshold for stationary objects seen by camera to be out-lane */
#define LA_CAM_OUTLANE_STAT_INLANETIME          (1.0f)
/*! Maximum inlane time threshold for stationary objects assigned to ego lane by scoring */
#define LA_CAM_SCORING_STAT_INLANETIME          (0.2f)
/*! Maximum inlane time threshold for stationary objects confirmed by camera */
#define LA_CAM_DEFAULT_STAT_INLANETIME          (0.2f)
/*! Minimum longitudinal distance for increased inlane time threshold (stationary objects) */
#define LA_CAM_OUTLANE_STAT_DIST_MIN            (40.0f)
/*! Maximum lanechange probability for increased inlane time threshold */
#define LA_CAM_OUTLANE_MAX_LC_PROB              (45u)
#endif

/* time (s) for moving objects for being accepted in lane */
/* time is a fuction of distance */
#define LA_MINTIME_MOVE_OBJ_IN_LANE_MIN   (0.025f) 
#define LA_MINTIME_MOVE_OBJ_IN_LANE_MAX   (0.28f)  

#define LA_DISTX_MOVE_OBJ_IN_LANE_MIN    (60.0f)
#define LA_DISTX_MOVE_OBJ_IN_LANE_MAX   (120.0f)


/* Parameters for situative increase of inlane timer as a function */
/* of relative velocity, curvature, and distance */
#if (LA_SIT_VREL_INLANE_TIME_INC)
#define LA_SIT_VREL_INLANE_TIME_INC_MIN_VREL        (-10.0f)
#define LA_SIT_VREL_INLANE_TIME_INC_MAX_VREL        (-0.5f)
#define LA_SIT_VREL_INLANE_TIME_INC_MIN_EGO_VEL     (70.0f/C_KMH_MS)
#define LA_SIT_VREL_INLANE_TIME_INC_MIN_EGO_DISTX   (40.0f)
#define LA_SIT_VREL_INLANE_TIME_INC_MAX_CURVE       (0.001f)

#define LA_SIT_VREL_INLANE_TIME_INC_MAX_TIME_TRUCKS (1.0f)
#define LA_SIT_VREL_INLANE_TIME_INC_MAX_TIME_STRAIGHT_CAR (0.5f)

#define LA_SIT_VREL_INLANE_TIME_INC_MAX_INCR        (0.5f)
#define LA_SIT_VREL_INLANE_TIME_INC_MED_INCR        (0.4f)
#define LA_SIT_VREL_INLANE_TIME_INC_MIN_INCR        (0.2f)
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
/* Parameters used to detect a likely false positive event on a narrow highway and to tighten the ego-lane association criteria */
#define LA_NARROW_HIGHWAY_CRIT_VEGO_MIN             (65.0F/C_KMH_MS)  /* [m/s], minimum ego velocity for consideration of narrow highway criteria */
#define LA_NARROW_HIGHWAY_CRIT_VEGO_MAX             (140.0F/C_KMH_MS) /* [m/s], maximum ego velocity for consideration of narrow highway criteria*/
#define LA_NARROW_HIGHWAY_CRIT_VOBJ_MIN             (50.0F/C_KMH_MS)  /* [m/s], minimum absolute object velocity for consideration of narrow highway criteria */
#define LA_NARROW_HIGHWAY_CRIT_VOBJ_MAX             (115.0F/C_KMH_MS) /* [m/s], maximum absolute object velocity for consideration of narrow highway criteria */
#define LA_NARROW_HIGHWAY_CRIT_RANGE_FAC_WEIGHT     (0.35F)           /* no dimension, percentage up to which the time-gap can be reduced */
#define LA_NARROW_HIGHWAY_CRIT_DIST_TO_ROAD_BORDER  (2.8f)            /* [m], maximum absolute distance to the road border up to which narrow highway criteria is applied */
#define LA_NARROW_HIGHWAY_CRIT_INLANE_TIME          (1.5f)            /* [s], in-lane time threshold for objects above distance threshold on narrow highway */
#define LA_NARROW_HIGHWAY_AREL_MIN                  (-3.F)            /* [m/s^2], no object suppression for high velocities if object braking is strong */

#define LA_NARROW_HIGHWAY_VREL_MIN_DISTX            (130.0f)          /* [m], lower x-distance sample point of ramp for relative velocity dependent distance criteria */
#define LA_NARROW_HIGHWAY_VREL_MAX_DISTX            (60.f)            /* [m], upper x-distance sample point of ramp for relative velocity dependent distance criteria */
#define LA_NARROW_HIGHWAY_VREL_MIN                  (-80.0f/C_KMH_MS) /* [m/s], lower vrel sample point of ramp for relative velocity dependent distance criteria */
#define LA_NARROW_HIGHWAY_VREL_MAX                  (-35.0f/C_KMH_MS) /* [m/s], upper vrel sample point of ramp for relative velocity dependent distance criteria */
#endif
#if (LA_HIGH_VEGO_INLANE_TIME)
/* Velocity and distance thresholds for object suppression at high velocities */
#define LA_HIGH_VEGO_INLANE_TIME_VEGO_MIN             (140.F/C_KMH_MS)                              /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_VEGO_MIN_UNKNOWN_TO  (140.F/C_KMH_MS)                              /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_VOBJ_MIN             (70.F/C_KMH_MS)                               /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_VREL_MAX             (-60.F/C_KMH_MS)                              /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_XDIST_MIN            (100.F)                                       /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_STRONG_CURVE         (1.F/1600.F)                                  /*|*/
/* Increased in-lane time threshold values */
#define LA_HIGH_VEGO_INLANE_TIME_TRUCK                (1.5F)                                        /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_OCCLUDED             (0.6F)                                        /*|*/
#define LA_HIGH_VEGO_INLANE_TIME_CAR                  (0.4F)                                        /*|*/

/* No object suppression for high velocities if object is braking intensly                           */
#define LA_HIGH_DIST_OBJ_SUPPRESS_AREL_MIN             (-3.F)                                     /*|*/

#if (FCT_CFG_ROAD_INPUT)
/* Distance to road border dependent thresholds for object suppression at high velocities            */
#define LA_HIGH_VEGO_OBJ_SUPPRESS_BORDER_DIST_FAR         (8.F)                                      /*|*/
#define LA_HIGH_VEGO_OBJ_SUPPRESS_BORDER_DIST_NEAR        (3.3F)                                     /*|*/
#endif /* (FCT_CFG_ROAD_INPUT) */
#endif /* (LA_HIGH_VEGO_INLANE_TIME) */

/* Length of array of return objects of function SIFindObjInArea                                     */
/* e.g. maximal number of objects to consider as possibly overtaken or passed by reference object    */
#define LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX                     (5u)                                  /*|*/

#if (LA_TTC_DEPENDANT_INLANE_TIME)
/* Velocity and distance thresholds for object suppression dependant on relative velocity and distance */
#define LA_TTC_DEPENDANT_INLANE_TIME_VEGO_MIN             (70.F/C_KMH_MS)                           /*|*/
#define LA_TTC_DEPENDANT_INLANE_TIME_VEGO_MAX             (140.F/C_KMH_MS)                          /*|*/
#define LA_TTC_DEPENDANT_INLANE_TIME_VREL_MIN             (-55.F/C_KMH_MS)                          /*|*/
#define LA_TTC_DEPENDANT_INLANE_TIME_XDIST_MIN            (40.F)                                    /*|*/
#define LA_TTC_DEPENDANT_INLANE_TIME_MAX                  (1.5F)                                    /*|*/
#define LA_TTC_DEPENDANT_INLANE_TIME_FACTOR               (0.05F)                                   /*|*/
#define LA_TTC_DEPENDANT_INLANE_TIME_VREL_MAX             (-2.F/C_KMH_MS)                           /*|*/
#endif /* LA_TTC_DEPENDANT_INLANE_TIME */

#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
/* Thresholds for suppression of in-lane assignment of objects with high cluster variance               */
#define LA_CLUST_VAR_VEGO_MAX                         (125.F/C_KMH_MS)                              /*|*/
#define LA_CLUST_VAR_VEGO_MIN                         (60.F/C_KMH_MS)                               /*|*/
#define LA_CLUST_VAR_XDIST_MIN                        (50.F)                                        /*|*/
#define LA_CLUST_VAR_TTC_MAX                          (14.F)                                        /*|*/
#define LA_CLUST_VAR_LEVEL_LOW                        (0u)                                          /*|*/
#define LA_CLUST_VAR_LEVEL_DIFFICULT                  (2u)                                          /*|*/
#define LA_CLUST_VAR_OBJ_OCCU_PICKUP_THRES_DIFFICULT  (1.5F)                                       /*|*/
#define LA_CLUST_VAR_OBJ_OCCU_DROP_THRES_DIFFICULT    (1.3F) 
#define LA_CLUST_VAR_INLANE_TIME_THRES                (1.0F)                                        /*|*/

#define LA_CLUST_VAR_ROAD_BORDER_DIST_MAX         (3.3F)                                        /*|*/
#define LA_CLUST_VAR_ROAD_BORDER_DIST_DELTA_THRES (1.7F)                                        /*|*/
#endif /* LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION */

#if ( (LA_CFG_NARROW_HIGHWAY_CRITERIA) || (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) )
/* Defines area and velocity delta in which possible mirror causing object can be located in relation */
/* to the possible mirror object                                                                      */
#define LA_MIRROR_OBJ_DELTAX_LOWER          (-10.F) /*! [m], Maximum distance delta in negative X direction */
#define LA_MIRROR_OBJ_DELTAX_UPPER          (10.F)  /*! [m], Maximum distance delta in positive X direction */
#define LA_MIRROR_OBJ_DELTAY_LOWER          (-6.F)  /*! [m], Maximum distance delta in negative Y direction */
#define LA_MIRROR_OBJ_DELTAY_UPPER          (6.F)   /*! [m], Maximum distance delta in positive Y direction */
#define LA_MIRROR_OBJ_DELTAV_LOWER          (-2.F)  /*! [m/s], Velocity delta lower threshold */
#define LA_MIRROR_OBJ_DELTAV_UPPER          (2.F)   /*! [m/s], Velocity delta upper threshold */
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
/* Defines area and velocity delta in which possible overtaken object can be located in relation */
/* to the overtaking object                                                                      */
#define LA_OVERTAKING_OBJ_DELTAX_LOWER  (-20.F)     /*! [m], Maximum distance delta in negative X direction */
#define LA_OVERTAKING_OBJ_DELTAX_UPPER  (30.F)      /*! [m], Maximum distance delta in positive X direction */
#define LA_OVERTAKING_OBJ_DELTAY_LOWER  (-6.F)      /*! [m], Maximum distance delta in negative Y direction */
#define LA_OVERTAKING_OBJ_DELTAY_UPPER  (-1.5F)     /*! [m], Maximum distance delta in positive Y direction */
#define LA_OVERTAKING_OBJ_DELTAV_LOWER  (-999.F)    /*! [m/s], Velocity delta lower threshold */
#define LA_OVERTAKING_OBJ_DELTAV_UPPER  (999.F)     /*! [m/s], Velocity delta upper threshold */
#endif

#if (LA_HIGH_VEGO_INLANE_TIME)
/* Defines area and velocity delta in which possible overtaken object can be located in relation */
/* to the overtaking object                                                                      */
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAX_LOWER          (-20.F)     /*! [m], Maximum distance delta in negative X direction */
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAX_UPPER          (40.F)      /*! [m], Maximum distance delta in positive X direction */
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_LOWER          (-6.F)      /*! [m], Maximum distance delta in negative Y direction */
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_UPPER          (0.F)       /*! [m], Maximum distance delta in positive Y direction */
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_LOWER_LEFT_TO  (0.F)       /*! [m], Maximum distance delta in negative Y direction for left traffic orientation*/
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_UPPER_LFET_TO  (6.F)      /*! [m], Maximum distance delta in positive Y direction for left traffic orientation*/
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAV_LOWER          (-999.F)    /*! [m/s], Velocity delta lower threshold */
#define LA_OVERTAKING_OBJ_HIGHSPEED_DELTAV_UPPER          (999.F)     /*! [m/s], Velocity delta upper threshold */
#endif

#if (LA_CFG_AVOID_SPILT_OBJ)
/* Relative velocity for Trucks */
#define LA_FAR_TRUCK_VEL_REL             (-10.0F)
/* Distance for Split Objects */
#define LA_SPLIT_OBJ_DIST                (100.0F)
/* Lateral distance difference for split objects */
#define LA_LAT_DIFF_SPLIT_OBJ            (1.5F)
/* Defines area and velocity delta in which possible Split object can be located */
#define LA_SPLIT_OBJ_DELTAX_LOWER  (-15.F)     /*! [m], Maximum distance delta in negative X direction */
#define LA_SPLIT_OBJ_DELTAX_UPPER  (15.F)      /*! [m], Maximum distance delta in positive X direction */
#define LA_SPLIT_OBJ_DELTAY_LOWER  (-6.F)      /*! [m], Maximum distance delta in negative Y direction */
#define LA_SPLIT_OBJ_DELTAY_UPPER  (0.F)       /*! [m], Maximum distance delta in positive Y direction */
#define LA_SPLIT_OBJ_DELTAV_LOWER  (-1.0F)     /*! [m/s], Velocity delta lower threshold */
#define LA_SPLIT_OBJ_DELTAV_UPPER  (1.0F)      /*! [m/s], Velocity delta upper threshold */
#endif /*LA_CFG_AVOID_SPILT_OBJ*/

#if (LA_HIGH_VEGO_INLANE_TIME && LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
#define LA_CLUST_VAR_HIGH_VEGO_INLANE_TIME       (1.0F)                                             /*|*/
#endif /* LA_HIGH_VEGO_INLANE_TIME && LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION */

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
#if (ALGO_SensorType == ALGO_CFG_ARS400Entry)
#define LA_DIST_TO_HIGH_CC_CRIT_TG_MIN           (4.0f) /* [s], minimum time-gap above which distance to curvature change will be considered in LA */
#else
#define LA_DIST_TO_HIGH_CC_CRIT_TG_MIN           (2.3f) /* [s], minimum time-gap above which distance to curvature change will be considered in LA */
#endif
#define LA_CURVE_CHANGE_CRIT_INLANE_TIME         (1.1f) /* [s], in-lane time threshold for objects above distance to curvature change */
#endif

/*! The in-lane threshold time factor when roadworks is detected */
#define LA_PAR_ROADWORKS_INLANE_TIME_FACTOR   (3.f)

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*! If the camera object lane assignment assigns given object to the ego lane,
then the following parameter specifies the minimal ego lane assignment confidence
from where the pickup threshold is modified */
#define LA_PAR_CAM_LANE_ASSIGN_GATE_PICKUP          70u

/*! If the camera object lane assignment assigns given object to the ego lane,
then the following parameter specifies the minimal ego lane assignment confidence 
for right and left object when ego is doing lane change,
from where the pickup threshold is modified */
#if (LA_CFG_LIMIT_CAM_LANE_GATE_PICKUP)
#define LA_PAR_CAM_LANE_ASSIGN_MIN_GATE_PICKUP          60u
#endif/* LA_CFG_LIMIT_CAM_LANE_GATE_PICKUP */

/*! The pickup theshold multiplier when the ego lane assignment gate is satisifed */
#define LA_PAR_CAM_LANE_ASSIGN_PICKUP_THRES_FACTOR  (0.75f)
#define LA_PAR_CAM_LANE_ASSIGN_PICKUP_THRES_FACTOR_INLAP  (0.85f)
#define LA_PAR_CAM_ASSIGN_IN_LANE_PICKUP_THRES_STAT        (0.85f)
#define LA_PAR_CAM_ASSIGN_OUT_LANE_PICKUP_THRES_STAT       (1.0f) /* Pick-Up Threshold if camera assigned object to neighbour lane */

#endif /* END IF (FCT_CFG_CAMERA_OBJECT_DETECTION)*/


#define LA_SCALE_LANE_WIDTH_LANE_ASSOC              (1.5f)  /*!< Scale lane width by this factor for lane association */
#define LA_SCALE_RESET_INLANE_TIMER_STAT            (2.f)   /*!< Scale cycle time by this factor to reset inlane timer for stationary objects */
#define LA_MAX_REL_TIMER_DROP_OCC_THRES             (1.f)   /*!< Maximum relevant time for spetial handling of occupancy theshold (not statinonary objects) */
#define LA_SUM_NONSTAT_DROP_OCC_THRES               (0.1f)  /*!< Summand for spetial handling of occupancy theshold (not statinonary objects) */
#define LA_MAX_CORR_REL_TIME_NONSTAT                (1.f)   /*!< Maximum value of fCorridorRelevantTime for moving objects */

/******************************************************************************
  la_laneassociation.c parameters end
******************************************************************************/

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*! The camera confirmation gate used to decide if a given object is
camera confirmed or not */
#define LA_PAR_CAM_CONF_MIN      10u  /* Remark: formally identical to OUT_PAR_CAM_CONF_X_RELEVANCE_GATE */
#endif /* FCT_CFG_CAMERA_OBJECT_DETECTION */

/*! Parameter of how many poles to use to filter VDY course for stationary objects.
Set to zero or 1 to disable filtering completely */
#define LA_PAR_STAT_COURSE_FIR_POLES      8u

#if (SIT_CFG_OBJECT_SCORING)
/*! Maximum trace bracket extension relative to seek bracket for objects assigned inlane by scoring @unit:m */
#define LA_PAR_MAX_SCORE_BRACKET_EXT    (0.5f)
/*! Minimum trace bracket extension relative to seek bracket for objects assigned inlane by scoring @unit:m */
#define LA_PAR_MIN_SCORE_BRACKET_EXT    (0.0f)
/*! Maximum trace bracket extension (LA_PAR_MAX_SCORE_BRACKET_EXT) speed @unit: m/s */
#define LA_PAR_MAX_SCORE_BRACKET_SPEED  (50.f / C_KMH_MS)
/*! Minimum trace bracket extension (LA_PAR_MIN_SCORE_BRACKET_EXT) speed @unit: m/s */
#define LA_PAR_MIN_SCORE_BRACKET_SPEED  (70.f / C_KMH_MS)
#endif

/*--------------------------------------------------------------------------
| Constants for restriction based on object trace                          |
--------------------------------------------------------------------------*/
#if LA_CFG_ADD_RESTRICTION_OBJ_TRACE

/* Area and relative velocity interval where we check if reference object is very close to another object */
#define LA_RES_OBJ_TRACE_DELTAX_LOWER (-15.F)  /* Maximum distance delta in negative X direction e.g. (-15.f) */
#define LA_RES_OBJ_TRACE_DELTAX_UPPER (15.F)   /* Maximum distance delta in negative X direction e.g. (15.f)  */
#define LA_RES_OBJ_TRACE_DELTAY_LOWER (-6.F)   /* Maximum distance delta in negative Y direction e.g. (-6.f)  */
#define LA_RES_OBJ_TRACE_DELTAY_UPPER (6.F)    /* Maximum distance delta in positive Y direction e.g. (6.f)   */
#define LA_RES_OBJ_TRACE_DELTAV_LOWER (-999.F) /* Velocity delta lower threshold e.g. (-999.f)                */
#define LA_RES_OBJ_TRACE_DELTAV_UPPER (999.F)  /* Velocity delta lower threshold e.g. (999.f)                 */

#define LA_MIN_TRACE_LENGTH                       (10.f)    /*! Minimum trace length above which traces are considered for restriction computation */

#define LA_LB_RES_OBJTRACE_SPEED_MIN              (90.f/C_KMH_MS)   /*!< Minimum speed, above which restriction based on traces can be applied */
#define LA_LB_RES_OBJTRACE_DISTX_MAX              (150.f)   /*!< Maximum object distance, above which this restriction does not make sense! */
#define LA_LB_RES_OBJTRACE_LANE_MATRIX_DISTX_MIN  (80.F)    /*!< Minimum object distance, above which lane matrix is considered! */

#define LA_LB_RES_OBJTRACE_EGO_OFFSET             (0.45f)   /*!< Offset for EGO lane OOI */
#define LA_LB_RES_OBJTRACE_NL_OFFSET              (0.75F)   /*!< Offset for neighboring lane OOI */
#define LA_LB_RES_OBJTRACE_OTHER_OFFSET           (0.45f)   /*!< Offset for objects other than OOI */

#define LA_SF_RES_OBJTRACE_EGOLANE_TH             (1.0f)    /*!< Scaling factor for threshold computation for objects EGO lane OOIs */
#define LA_SF_RES_OBJTRACE_NL_TH                  (0.6f)    /*!< Scaling factor for threshold computation for neighboring lane OOIs */
#define LA_SF_RES_OBJTRACE_OTHER_TH               (0.5f)    /*!< Scaling factor for threshold computation for objects other than OOIs */

/* Threshold for minimum lateral displacement of the object for restriction based on object trace */
#define LA_LB_RESTRICTION_LATDISP_TH_MIN          (2.0f)       /*!< Minimum lateral displacement of object for restriction based on object trace */
#define LA_LB_RESTRICTION_LATDISP_TH_MAX          (3.5f)       /*!< Maximum lateral displacement of object for restriction based on object trace */
#define LA_CURVATURE_LB_RESTRICTION_LATDISP_MIN   (1.f/3000.f) /*!< Minimum curvature used in computation of threshold for lateral displacement of object */
#define LA_CURVATURE_LB_RESTRICTION_LATDISP_MAX   (1.f/400.f)  /*!< Maximum curvature used in computation of threshold for lateral displacement of object */

/* Scaling thresholds based on longitudinal distance */  
#define LA_REST_TRACE_SCALE_THRES_MIN           (1.f)       /*!< Minimum factor for scaling thresholds based on longitudinal distance */
#define LA_REST_TRACE_SCALE_THRES_MAX           (1.2f)      /*!< Maximum factor for scaling thresholds based on longitudinal distance */
#define LA_REST_TRACE_SCALE_THRES_DIST_MIN      (100.f)     /*!< Minimum longitudinal distance for scaling thresholds based on longitudinal distance */
#define LA_REST_TRACE_SCALE_THRES_DIST_MAX      (LA_LB_RES_OBJTRACE_DISTX_MAX)  /*!< Maximal longitudinal distance for scaling thresholds based on longitudinal distance */
/* Threshold computation for restriction based on object trace */
#define LA_LB_RESTRICTION_OBJTRACE_TH_MIN         (0.35f)   /*!< Minimum threshold for restriction based on object trace */
#define LA_LB_RESTRICTION_OBJTRACE_TH_MAX         (1.1f)     /*!< Maximum threshold for restriction based on object trace */
#define LA_AREA_LB_RESTRICTION_OBJTRACE_MIN       (35.f)    /*!< Minimum difference between EGO/ACC-trajectory and object trace for restriction based on object trace */
#define LA_AREA_LB_RESTRICTION_OBJTRACE_MAX       (80.f)    /*!< Maximum difference between EGO/ACC-trajectory and object trace for restriction based on object trace */

/* Scaling factor computation for threshold to be used in restriction based on object trace */
#define LA_SF_RESTRICTION_OBJTRACE_TH_MIN         (0.5f)    /*!< Minimum scaling factor for threshold, dependent on curvature */
#define LA_SF_RESTRICTION_OBJTRACE_TH_MAX         (1.f)     /*!< Maximum scaling factor for threshold, dependent on curvature */
#define LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MIN  (1.f/750.f)   /*!< Minimum curvature used in computation of scaling factor for threshold */
#define LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MAX  (1.f/950.f)   /*!< Maximum curvature used in computation of scaling factor for threshold */
#endif

/* Parameters for restriction in the near range for country road /city scenarios to improve the release 
of objects that take a turn */
#if(LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
#define LA_REST_CITY_NEAR_RANGE_MIN_RESTICT       (0.35f * LA_CITYLANEWIDTHTRCK) /*!< Minimal restriction */
#define LA_REST_CITY_NEAR_RANGE_MAX_RESTICT       (0.5f * LA_CITYLANEWIDTHTRCK)  /*!< Maximal restriction */
#define LA_REST_CITY_NEAR_RANGE_MIN_DIST_X        (10.f)  /*!< Longitudinal distance for minimal restriction */
#define LA_REST_CITY_NEAR_RANGE_MAX_DIST_X        (12.f)  /*!< Longitudinal distance for maximal restriction */

#define LA_REST_CITY_NEAR_RANGE_MAX_VREL          (-1.f)  /*!< Maximal relative velocity */
#define LA_REST_CITY_NEAR_RANGE_MAX_VELOCITY      (70.f/C_KMH_MS)   /*!< Maximal ego velocity */
#define LA_REST_CITY_NEAR_RANGE_MAX_CURVE         (0.004f) /*!< Maximal ego curve; radius = 250m */
#endif

#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
#define LA_LB_STATOBJ_NEXTLANE_SHIFT              (0.3F)    /*!< Shift the lane brackets by this quantity, when the situation qualifies for LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE */
#endif

/* Parameters defined for increasing the in-lane time threshold for objects detected out of Ego Lane using the Camera Trajectory  */
#if (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA)
#define LA_CFG_INLANE_TIME_CAM_TRAJ_LA_OBJ_DISTX     (80.f)           /*!< Object Longitudinal Distance Threshold */
#define LA_CFG_INLANE_TIME_CAM_TRAJ_LA_EGO_SPEED     (80.f/C_KMH_MS)  /*!< Ego Speed Threshold */
#define LA_CFG_INLANE_TIME_CAM_TRAJ_LA_LC_PROB       (20u)            /*!< Ego Lane Change Probabiltiy Threshold */
#define LA_CFG_INLANE_TIME_CAM_TRAJ_LA_ACC_CURVE     (1.f/250.f)      /*!< Final ACC Curve Threshold */

#define LA_CFG_INLANE_TIME_CAM_TRAJ_LA_THRESHOLD     (2.f)            /*!< In-Lane Time Threshold if Camera Trajectory Based LA detects outside Ego Lane */
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA) */

/* Parameters defined to not extend Extension Highway GuardRail RoadBorder depending on Camera Trajectory based Lane Association */
#if (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA)
#define LA_DISABLE_EXTENSION_CAM_TRAJ_LA_EGO_SPEED   (80.F/C_KMH_MS)  /*!< Ego Speed Threshold */
#define LA_DISABLE_EXTENSION_CAM_TRAJ_LA_OBJ_DISTX   (35.f)           /*!< Object Longitudinal Distance Threshold */
#endif /* (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA) */

/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/* Pickup and drop thresholds for lane selection of moving objects */
#define LA_ObjectOccupancyPickupThreshOutlane LAOccupancyParams.ObjOccPickupThreshOutlane /*0.55f*/
#define LA_ObjectOccupancyPickupThreshInlane  LAOccupancyParams.ObjOccPickupThreshInlane  /*0.50f*/
#define LA_ObjectOccupancyDropThresh          LAOccupancyParams.ObjOccDropTresh           /*0.30f*/
#define LA_LaneOccupancyPickupThresh          LAOccupancyParams.LaneOccPickupThresh       /*0.50f*/
#define LA_LaneOccupancyDropThresh            LAOccupancyParams.LaneOccDropTresh          /*0.30f*/

#if (SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN)
#pragma COMPILEMSG("Clarify where these parameters could be placed! Used in EM & FCT!")
/* max. speed [km/h] to select stationary pedestrians as OOI */
#define LA_MAX_SPEED_STAT_PED_SELECTION (LALowSpeedStatPedesParams.Max_Speed/C_KMH_MS)
/* max. distance [m] to select stationary pedestrians as OOI */
#define LA_MAX_DIST_STAT_PED_SELECTION   LALowSpeedStatPedesParams.Max_Dist
/* Time [s] in Lane to select stationary pedestrians as OOI */
#define LA_MINTIME_STAT_PED_IN_LANE      LALowSpeedStatPedesParams.MinTime_In_Lane
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
typedef struct LAOccupancyParams {
  float32 ObjOccPickupThreshOutlane;    /*!< Pickup threshold object occupancy when outlane @min:1e-8 @max: 1 */
  float32 ObjOccPickupThreshInlane;     /*!< Pickup threshold object occupancy when inlane  @min:1e-8 @max: 1 */
  float32 ObjOccDropTresh;              /*!< Drop threshold object occupancy   @min:1e-8 @max: 1 */
  float32 LaneOccPickupThresh;          /*!< Pickup threshold lane occupancy   @min:1e-8 @max: 1 */
  float32 LaneOccDropTresh;             /*!< Drop threshold lane occupancy     @min:1e-8 @max: 1 */
} LA_t_OccupancyParams; /*!< @allow: all_cust */

typedef struct LALowSpeedStatPedesParams {
  float32 Max_Speed;   /*!< max. speed [km/h] to select stationary pedestrians as OOI.       @min:1e-8 @max: 10 */
  float32 Max_Dist;    /*!< max. distance [m] to select stationary pedestrians as OOI.       @min:1e-8 @max: 10 */
  float32 Min_LTime;   /*!< min Lifetime [cycles] to select stationary pedestrians as OOI.   @min:1e-8 @max: 10 */
  float32 MinTime_In_Lane;       /*!< Time [s] in Lane to select stationary pedestrians as OOI.        @min:1e-8 @max: 1 */
  float32 RCS_Add;               /*!< RCS Offset [dB] to be added to the detection threshold.          @min:1e-8 @max: 1 */
} LA_t_LowSpeedStatPedesParams; /*!< @allow: all_cust */

/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

extern const LA_t_OccupancyParams LAOccupancyParams;
extern const LA_t_LowSpeedStatPedesParams LALowSpeedStatPedesParams;

/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/



/* End of conditional inclusion */
/** @} end defgroup */
#endif  /*!< _LA_PAR_H_INCLUDED */

