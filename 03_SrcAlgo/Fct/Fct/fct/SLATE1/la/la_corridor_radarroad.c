/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_radarroad.c

DESCRIPTION:               ACC object corridor brackets' adaptation implementation based on Radar Road Information

AUTHOR:                    Norman Apel
                           Gergely Ungvary

CREATION DATE:             15.05.2014

VERSION:                   $Revision: 1.61 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

// PRQA S 7013 STTLN_EXCEEDED
/* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: Number of lines exceeded per file, not safety critical */


#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)

#include "la_corridor_crit.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_corridor_radarroad LA Corridor radar road
@ingroup la_corridor
@brief          Provides ACC object corridor brackets' adaptation implementation based on Radar Road Information. \n\n

@{

*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/
//PRQA S 0791 MACRO_IDENTIFIER_LENGTH
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Macro identifier does not differ from other macro identifier within the specified number of significant characters,Does not affect functionality*/

#if ( (FCT_CFG_ROAD_INPUT) && (LA_CFG_GUARDRAILROADBORDER_HIGHWAY) )
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_VEGO_MIN      (110.f/C_KMH_MS)    /* Minimum ego velocity in guardrail border extension for non-relevant objects */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DISTY_MAX     (6.f)               /* Maximum lateral object distance in guardrail border extension for non-relevant objects */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DISTX_MIN     (105.f)             /* Minimum longitudinal object distance in guardrail border extension for non-relevant objects */
#define LA_GUARDRAIL_BORDER_EXT_MAX_BORDER_DIST        (3.8f)              /* Maxiumum distance to road border in guardrail border extension */

#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAX_LOWER      (-10.F)         /* Lower threshold for longitudinal distance delta for mirror check of non-relevant objects in guardrail border extension */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAX_UPPER      (10.F)          /* Upper threshold for longitudinal distance delta for mirror check of non-relevant objects in guardrail border extension */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAY_LOWER      (-5.5F)         /* Lower threshold for lateral distance delta for mirror check of non-relevant objects in guardrail border extension */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAY_UPPER      (5.5F)          /* Upper threshold for lateral distance delta for mirror check of non-relevant objects in guardrail border extension */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAV_LOWER      (-2.F)          /* Lower threshold for velocity delta for mirror check of non-relevant objects in guardrail border extension */
#define LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAV_UPPER      (2.F)           /* Upper threshold for velocity delta for mirror check of non-relevant objects in guardrail border extension */

static const LA_t_FindObjInAreaArgs LATraExtensionGuardRailMirrorArgs = // PRQA S 3218
/* date: 2015-12-04, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAX_LOWER,
  LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAX_UPPER,
  LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAY_LOWER,
  LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAY_UPPER,
  LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAV_LOWER,
  LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DELTAV_UPPER
};
#endif /* END IF ( (FCT_CFG_ROAD_INPUT) && (LA_CFG_GUARDRAILROADBORDER_HIGHWAY) ) */

#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)
#endif

#define LA_TRACE_INLAP_PICKUP_THRES                 (1.0f)         /* Pick up threshold of an Object for Ego lane selection */

#define LA_PERC_LENGTH_REFLECTION_INNER_CURVE_EXT   (0.45f)        /* Factor to multiply for calculating how far the reflection point moves due to the refection from the side */
#define LA_MIN_CURVE_INNER_CURVE_EXT                (1.f/250.f)    /* Maximum Radius above which the Trace Bracket Extension (Right/Left) does not apply */
#define LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MIN         (0.f)          /* Distance to Trajectory value */
#define LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MAX_RIGHT   (-3.f)         /* Max Distance to Trajectory value on right side above which the TB extension to right does not apply */
#define LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MAX_LEFT    (3.f)          /* Max Distance to Trajectory value on left side above which the TB extension to left does not apply */ 
#define LA_CURVE_INNER_EXT_LONG_DIST_MIN            (30.f)         /* Min Long Disp of the object below which the TB extension (Right/Left) does not apply */
#define LA_TIMECONST_INNER_CURVE_EXT                (0.3f)
#define LA_FSZ_A2_RICHTUNGSFAHRSPUREN_KI            (1.0F/1000.F)   /* Maximum Radius above which the Trace Bracket Extension (Right/Left) does not apply */

#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
#define LA_PARALLEL_MAX_DISTX                       (40.0f)        /* Max Long Disp of the object above which the TB extension (Right/Left) does not apply */
#define LA_PARALLEL_MAX_VELOCITY                    (80.0f/C_KMH_MS)  /* Max Velocity of the Ego vehicle above which the TB extension (Right/Left) does not apply */
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */

#if (LA_EXTENDED_CURVEINNERBORDER_CRITERION == 1)
/* for stronger version of Extension CurveInnerBorder */
/* helps in narrow curves or roundabouds */
#define LA_ECIBO_MAX_CURVE                   (1.0f/175.0f)     /*!< maximal curve radius for activation of extended curveinnerborder criterion */   
#define LA_ECIBO_MAX_DISTX                   (40.0f)           /*!< maximal object distance for activation of extended curveinnerborder criterion */   
#define LA_ECIBO_MAX_VELOCITY                (60.0f/C_KMH_MS)  /*!< maximal velocity for activation of extended curveinnerborder criterion */   
#define LA_ECIBO_MAX_EXTENTIONANGLE_TAN      (39.0f)           /*!< maximal extention of trace bracket (tangens(39 degree)) */
#if (LA_EXTENDED_CURVEINNERBORDER_CRITERION_WEAKER == 1)
#define LA_ECIBO_MAX_CURVE_GRADIENT          (0.0025f)   /*!< curve gradient thereshold */
#define LA_ECIBO_MAX_NB_LANES                (0L)        /*!< number of lanes threshold */
#endif
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
#define LA_GUARDRAIL_CAMCONF_MAX_DISTX            (60.0f)        /*!< maximal object distance for consideration of camera confirmation for Gaurd rail border extention.*/
#endif

/*--------------------------------------------------------------------------
| Konstanten zur Zielablagepruefung                                        |
--------------------------------------------------------------------------*/

#define LA_FSZ_ZIELABLAGE_ABSTAND         (50.F)          /* Min Long Disp of the object below which the TB extension (Right/Left) does not apply */
#define LA_FSZ_ZIELABLAGE_KRUEMMUNG       (1.0F/3000.F)   /* Maximum Radius above which the Trace Bracket Extension (Right/Left) does not apply */

#if LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT
#define LA_FSZ_ZIELABLAGE_ABLAGEDIFF      (1.0F)
#else
#define LA_FSZ_Y_STDDEV_WEIGHT_FACTOR     (0.125f)
#endif

/*--------------------------------------------------------------------------
| Konstanten zur Spurbreiten-Bestimmung bei anliegenden Richtungsfahrspuren|
--------------------------------------------------------------------------*/
/* Wenn keine Fahrspur anliegend und Objekt weiterentfernt */
/* dann Öffnung bis zum Strassenrand*/
#if (FCT_CFG_RSP_CONTEXT_INPUT)
#define LA_RANGE_NEAR     (60.f)
#endif

#if (LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA)

/* Im Seekzustand wird maximal auf den enger am Radius liegenden Wert */
/* erweitert, welcher aus dem Winkel oder aus Radius + Ablage         */
/* bestimmt wird.                                                     */
#define LA_SEEK_RFS_ABLAGE_NARROWCURV_MAX  (7.0F)
/* Filterzeit in sec. der Wirkung eines Schaltvorgangs bei anliegendem */
/* Strassenrand.                                                       */
#define LA_FSZ_RFS_FILTER_ZEIT            (0.3F)

#define LA_ABST_KEINESPUR_MIN           (15.F)
#define LA_ABST_KEINESPUR_RELOBJ        (25.F)
#define LA_ABST_KEINESPUR_MAX           (130.F)

/* Winkel fuer Definition Objekte sind am Keulenrand */
#define LA_FSZ_WINKEL_RICHTUNGSFAHRSPUREN (SLATE_f_GetLobeAngle()*0.8F)
/* Kruemmung ab der am Kurvenaussenrand keine Erweiterung fuer am Kurveninneren */
/* Keulenrand befindeliche Objekte mehr stattfindet.                            */
#define LA_FSZ_A2_RICHTUNGSFAHRSPUREN     (1.0F/1000.F)

#define LA_FSZ_RFS_NARROW_CURVE           (1.0F/900.F)
#define LA_FSZ_RFS_NARROW_CURVE_REL       (1.0F/700.F)
#define LA_FSZ_RFS_NARROW_CURVE_GRADIENT  (0.001F)
#if (!LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
/* Mindest probability fuer keine fahrspur links/rechts erkannt */
#define LA_FSZ_RFS_NO_LANE_PROB_MIN       (0.85F)
#endif
#endif

/*---------------------------------------------------------------------------
| Konstanten zur Spurbreiten-Bestimmung aus ObjektwinkelVerfolgung          |
---------------------------------------------------------------------------*/
#define LA_OWV_SPURGRAD_MIN_HALTEN_MAXWINKEL        (0.00002F)
/* ARS2xx: #define LA_OWV_SPURGRAD_WINKEL_MAX       (float32)(3.35F) */
#define LA_OWV_SPURGRAD_WINKEL_MAX                  (SLATE_f_GetLobeAngle()-0.5f)
/* Spurkruemmung fuer Abfrage GERADEAUS*/
#define LA_SPURKRUEMMUNG_MIN_GERADEAUS              (1.0F/20000.F)

/* Mindestobjektlebensdauer fuer das OWV-Kriterium */
#define LA_OWV_OBJLEB                               (50u)
/* max. Abstand in dem die Spurnachfuehrung funktioniert */
#define LA_MAX_ABSTSTEIG                            (120.F)
/* min. Abstand in dem die Spurnachfuehrung funktioniert */
#define LA_MIN_ABSTSTEIG                            (30.F)
/* min. Abstand, Vrel und Veigen fuer Spurerweiterung RFS, RFSKI, OWV */
#define LA_MIN_ABST_VREL                            (60.F)
#define LA_MIN_OWV_VREL                             (25.F/C_KMH_MS)
#define LA_MIN_OWV_VEIGEN                           (25.F/C_KMH_MS)
/* max. relative speed for trace criterion for OWV */
#define LA_MAX_OWV_VREL_TRACE_CRIT                   (15.F / C_KMH_MS)
/* min. Spurvektorsteigung abgestimmt auf mehr als 1 Digit LW */
#define LA_MIN_SPURSTEIG                            (0.0004F)
/* max. Haltezeit der Erweit., wenn Steigung im Haltezustand */
#define LA_MAX_HALTEZEIT                            (5L)
/* Unterhalb dieser Spurabweichung keine Erweiterung mehr */
#define LA_MIN_SPURABWEICH                          (0.5F)
/* Oberhalb dieser Spurabweichung keine Erweiterung mehr */
#define LA_MAX_SPURABWEICH                          (2.F)
/*! Minimum lane change probability */
#define LA_MIN_LC_PROB_FOLLOW_OBJ_INTO_CURVE     (65u)

/* Konstanten fuer LA_SpurGradHaltenKruemmung */
#define LA_OWV_SPURGRAD_MIN_HALTEN        (0.00002F)
#define LA_OWV_SPURGRAD_MAX_HALTEN        (0.0004F)
#define LA_OWV_SPURGRAD_KRUEMMUNG_MIN     (1.0F/5000.F)
#define LA_OWV_SPURGRAD_KRUEMMUNG_MAX     (1.0F/2500.F)

/*---------------------------------------------------------------------------
| Constants: trace brackets extension based on object scoring |
---------------------------------------------------------------------------*/
#if (SIT_CFG_OBJECT_SCORING)
#define LA_TB_EXTENSION_DIST_X_MIN_OBJSCORING_NEARRANGE   (8.f)
#define LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE    (10.f)
#endif

#ifndef LA_CFG_ADD_EXTENSION_OBJ_APPROX
#error The switch LA_CFG_ADD_EXTENSION_OBJ_APPROX has to be set to 1 to have unchanged behaviour with this version of la_corridor_crit.c!
#endif

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
OLD SA 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

#if (LA_CFG_CALIBRATE_SEEK_LANE_WIDTH)
#define LA_CALIB_LANE_WIDTH_MIN     1.2f
#define LA_CALIB_LANE_WIDTH_MAX     5.0f
#endif

/*! Minimum road border status for use in road border extension function */
#define LA_GUARDRAIL_ROAD_BORDER_EXT_MIN_TRK_STATUS    4u

/*! Maximal lateral displacement to predicted ACC course for road border
criteria @unit:m */
#define LA_MAX_ROAD_BORD_LAT_NO_TRACE     5.0f
/*! Maximum lateral displacement to predicted ACC course for a given relevant
object to be able to activate OWV criteria over it's trace @unit:m */
#define LA_MAX_TRACE_LAT_DISPLACEMENT     5.0f

/*! Maximum lateral displacement of trace bracket due to OWV criteria */
#define LA_MAX_OVW_ABLAGE                 5.0f

#if LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA
#define LA_TB_EXTENSION_ROADBORDER_MIN         (1.5f)                 /*!< Minimal extension of trace brackets for Road Border */
#define LA_TB_EXTENSION_ROADBORDER_MAX         (3.5f)                 /*!< Maximal extension of trace brackets for Road Border */
#define LA_DISTX_TB_EXTENSION_ROADBORDER_MIN   LA_ABST_KEINESPUR_MIN     /*!< Distance to object for minimal trace bracket extension */
#define LA_DISTX_TB_EXTENSION_ROADBORDER_MAX   (50.f)                 /*!< Distance to object for maximal trace bracket extension */
#endif


#define LA_DISTX_FAR_RANGE_ANGLE_TB_EXT         (70.f)                /*!< If longitudinal distance if higher, the far range angle 
                                                                           is considered for the trace bracket extension */
#define LA_ANGLE_NEAR_RANGE_TB_EXT              (25.f)                /*!< Angle that is used in the near range for the 
                                                                           trace bracket extension, Remark: ARS301 = 25Grad */
/*! Restricting the bracket corridor while ego lane changes */
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)   
#define LA_EGO_LANE_CHANGE_DISTANCE           (120.0f)                 /*!< Distance required for ego lane change */
#define LA_REST_EGO_LC_TRACE_MIN_RESTICT      (0.4f)                 /*!< Minimum trace restriction factor */
#define LA_REST_EGO_LC_TRACE_MAX_RESTICT      (0.54f)                /*!< Maximim trace restriction factor */
#define LA_REST_EGO_CURVE_HIGH                (0.002f)               /*!< Ego curve high value for maximum trace restriction */
#define LA_REST_EGO_CURVE_LOW                 (0.00015f)             /*!< Ego curve low value for minimum trace restriction */
#define LA_EGO_LANE_CHANGE_IND_TIMER_LIM      (4.5f)                 /*!< Index timer limit for ego lane change */
#define LA_EGO_LANE_CHANGE_IND_TIMER_MIN      (0.0f)                 /*!< Minimum index timer while ego lane change */
#define LA_EGO_LANE_RELEV_TIME                (5.0f)                 /*!< Relev time for ego lane change */
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE */ 
/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/
/*! Enum to describe which FOV to consider for a specific corridor function */
typedef enum LACorrFOVTypeExtension
{
  LA_FAR_RANGE_ONLY_LEFT,        /*!< Consider far range only on the left FOV side */
  LA_FAR_AND_NEAR_RANGE_LEFT,    /*!< Consider far and near range on the left FOV side */
  LA_FAR_RANGE_ONLY_RIGHT,       /*!< Consider far range only on the right FOV side */
  LA_FAR_AND_NEAR_RANGE_RIGHT    /*!< Consider far and near range on the right FOV side */
} LA_t_CorrFOVTypeExtension;

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/
/*-- SIRelTra.c --*/
/* Rampe zur Veraenderung der SpurGradienten-Schwelle in Abh. der Spurkruemmung */
SET_MEMSEC_CONST(LA_SpurGradHaltenKruemmung)
static const GDBLFunction_t LA_SpurGradHaltenKruemmung = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_OWV_SPURGRAD_MIN_HALTEN,   /*!< A1 */
  LA_OWV_SPURGRAD_MAX_HALTEN,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_OWV_SPURGRAD_MAX_HALTEN - LA_OWV_SPURGRAD_MIN_HALTEN ) / ( LA_OWV_SPURGRAD_KRUEMMUNG_MAX - LA_OWV_SPURGRAD_KRUEMMUNG_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_OWV_SPURGRAD_MIN_HALTEN
  -( (( LA_OWV_SPURGRAD_MAX_HALTEN - LA_OWV_SPURGRAD_MIN_HALTEN ) / ( LA_OWV_SPURGRAD_KRUEMMUNG_MAX - LA_OWV_SPURGRAD_KRUEMMUNG_MIN ))
  * LA_OWV_SPURGRAD_KRUEMMUNG_MIN )
};

#if LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA
/*! Extension of Road Border relative to distance between ZO and EGO */
SET_MEMSEC_CONST(LA_TB_EXTENSION_ROADBORDER)
static const GDBLFunction_t LA_TB_EXTENSION_ROADBORDER = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_TB_EXTENSION_ROADBORDER_MIN,   /*!< A1 */
  LA_TB_EXTENSION_ROADBORDER_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_TB_EXTENSION_ROADBORDER_MAX - LA_TB_EXTENSION_ROADBORDER_MIN ) / ( LA_DISTX_TB_EXTENSION_ROADBORDER_MAX - LA_DISTX_TB_EXTENSION_ROADBORDER_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_TB_EXTENSION_ROADBORDER_MIN
  -( (( LA_TB_EXTENSION_ROADBORDER_MAX - LA_TB_EXTENSION_ROADBORDER_MIN ) / ( LA_DISTX_TB_EXTENSION_ROADBORDER_MAX - LA_DISTX_TB_EXTENSION_ROADBORDER_MIN ))
  * LA_DISTX_TB_EXTENSION_ROADBORDER_MIN )
};
#endif

#if LA_CFG_ADD_RESTRICTION_OBJ_TRACE
/*! Threshold for restriction based on object trace */
SET_MEMSEC_CONST(LA_LB_RESTRICTION_OBJTrace_Threshold)
static const GDBLFunction_t LA_LB_RESTRICTION_OBJTrace_Threshold = { // PRQA S 3218
/* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_LB_RESTRICTION_OBJTRACE_TH_MIN,   /*!< A1 */
  LA_LB_RESTRICTION_OBJTRACE_TH_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_LB_RESTRICTION_OBJTRACE_TH_MAX - LA_LB_RESTRICTION_OBJTRACE_TH_MIN ) / ( LA_AREA_LB_RESTRICTION_OBJTRACE_MAX - LA_AREA_LB_RESTRICTION_OBJTRACE_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_LB_RESTRICTION_OBJTRACE_TH_MIN
  -( (( LA_LB_RESTRICTION_OBJTRACE_TH_MAX - LA_LB_RESTRICTION_OBJTRACE_TH_MIN ) / ( LA_AREA_LB_RESTRICTION_OBJTRACE_MAX - LA_AREA_LB_RESTRICTION_OBJTRACE_MIN ))
  * LA_AREA_LB_RESTRICTION_OBJTRACE_MIN )
};

/*! Scaling factor for threshold based on curvature */
SET_MEMSEC_CONST(LA_SCALINGFACTOR_CURVATURE)
static const GDBLFunction_t LA_SCALINGFACTOR_CURVATURE = { // PRQA S 3218
/* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_SF_RESTRICTION_OBJTRACE_TH_MIN,   /*!< A1 */
  LA_SF_RESTRICTION_OBJTRACE_TH_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_SF_RESTRICTION_OBJTRACE_TH_MAX - LA_SF_RESTRICTION_OBJTRACE_TH_MIN ) / ( LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MAX - LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_SF_RESTRICTION_OBJTRACE_TH_MIN
  -( (( LA_SF_RESTRICTION_OBJTRACE_TH_MAX - LA_SF_RESTRICTION_OBJTRACE_TH_MIN ) / ( LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MAX - LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MIN ))
  * LA_CURVATURE_SF_RESTRICTION_OBJTRACE_MIN )
};

/*! Threshold ramp for computing minimum lateral displacement of Object before applying object trace based restriction */
SET_MEMSEC_CONST(LA_ObjDist2TrajThreshold_CURVATURE)
static const GDBLFunction_t LA_ObjDist2TrajThreshold_CURVATURE = { // PRQA S 3218
/* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_LB_RESTRICTION_LATDISP_TH_MIN,   /*!< A1 */
  LA_LB_RESTRICTION_LATDISP_TH_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_LB_RESTRICTION_LATDISP_TH_MAX - LA_LB_RESTRICTION_LATDISP_TH_MIN ) / ( LA_CURVATURE_LB_RESTRICTION_LATDISP_MAX - LA_CURVATURE_LB_RESTRICTION_LATDISP_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_LB_RESTRICTION_LATDISP_TH_MIN
  -( (( LA_LB_RESTRICTION_LATDISP_TH_MAX - LA_LB_RESTRICTION_LATDISP_TH_MIN ) / ( LA_CURVATURE_LB_RESTRICTION_LATDISP_MAX - LA_CURVATURE_LB_RESTRICTION_LATDISP_MIN ))
  * LA_CURVATURE_LB_RESTRICTION_LATDISP_MIN )
};

/*! Scale based on longitudinal distance */
SET_MEMSEC_CONST(LA_t_RestTraceDistSclaeThreshold)
static const GDBLFunction_t LA_t_RestTraceDistSclaeThreshold = { // PRQA S 3218
    /* date: 2015-08-04, reviewer: Boll (uidu1091), reason: static local for saving data across function calls */
    LA_REST_TRACE_SCALE_THRES_MIN,   /*!< A1 */
    LA_REST_TRACE_SCALE_THRES_MAX,   /*!< A2 */
    /*! (A2-A1)/(E2-E1) */
    ( LA_REST_TRACE_SCALE_THRES_MAX - LA_REST_TRACE_SCALE_THRES_MIN ) / ( LA_REST_TRACE_SCALE_THRES_DIST_MAX - LA_REST_TRACE_SCALE_THRES_DIST_MIN ),
    /*! A1 - (A2-A1)/(E2-E1) * E1 */
    LA_REST_TRACE_SCALE_THRES_MIN
    -( (( LA_REST_TRACE_SCALE_THRES_MAX - LA_REST_TRACE_SCALE_THRES_MIN ) / ( LA_REST_TRACE_SCALE_THRES_DIST_MAX - LA_REST_TRACE_SCALE_THRES_DIST_MIN ))
    * LA_REST_TRACE_SCALE_THRES_DIST_MIN )
};

#endif

/*! Parameters for restriction in the near range for country road /city 
scenarios to improve the release of objects that take a turn */
#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
/* Parameter to describe the restriction based on the longitudinal distance to the object */
SET_MEMSEC_CONST(LA_t_RestictCityNearRange)
static const GDBLFunction_t LA_t_RestictCityNearRange = { // PRQA S 3218
    /* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
    LA_REST_CITY_NEAR_RANGE_MIN_RESTICT,   /*!< A1 */
    LA_REST_CITY_NEAR_RANGE_MAX_RESTICT,   /*!< A2 */
    /*! (A2-A1)/(E2-E1) */
    ( LA_REST_CITY_NEAR_RANGE_MAX_RESTICT - LA_REST_CITY_NEAR_RANGE_MIN_RESTICT ) / ( LA_REST_CITY_NEAR_RANGE_MAX_DIST_X - LA_REST_CITY_NEAR_RANGE_MIN_DIST_X ),
    /*! A1 - (A2-A1)/(E2-E1) * E1 */
    LA_REST_CITY_NEAR_RANGE_MIN_RESTICT
    -( (( LA_REST_CITY_NEAR_RANGE_MAX_RESTICT - LA_REST_CITY_NEAR_RANGE_MIN_RESTICT ) / ( LA_REST_CITY_NEAR_RANGE_MAX_DIST_X - LA_REST_CITY_NEAR_RANGE_MIN_DIST_X ))
    * LA_REST_CITY_NEAR_RANGE_MIN_DIST_X )
};
#endif

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
/* Parameter to describe the restriction based on Ego Lane change */
SET_MEMSEC_CONST(LA_t_RestictEgoLaneChange)
static const GDBLFunction_t LA_t_RestictEgoLaneChange = {// PRQA S 3218
   /* date: 2020-2-12, reviewer: Timken George, reason: static local for saving data across function calls */
  LA_REST_EGO_LC_TRACE_MIN_RESTICT,
  LA_REST_EGO_LC_TRACE_MAX_RESTICT,
  ( ( LA_REST_EGO_LC_TRACE_MAX_RESTICT - LA_REST_EGO_LC_TRACE_MIN_RESTICT ) / ( LA_REST_EGO_CURVE_HIGH - LA_REST_EGO_CURVE_LOW ) ),
  LA_REST_EGO_LC_TRACE_MIN_RESTICT - ( (( LA_REST_EGO_LC_TRACE_MAX_RESTICT - LA_REST_EGO_LC_TRACE_MIN_RESTICT ) / ( LA_REST_EGO_CURVE_HIGH - LA_REST_EGO_CURVE_LOW ) ) * LA_REST_EGO_CURVE_LOW)
};
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE */

#if (SIT_CFG_OBJECT_SCORING)
/*! Scaling factor for trace bracket extention based on object scoring */
SET_MEMSEC_CONST(ScoringExtensionSize)
static const GDBLFunction_t ScoringExtensionSize =
{
  LA_PAR_MAX_SCORE_BRACKET_EXT,
  LA_PAR_MIN_SCORE_BRACKET_EXT,
  ((LA_PAR_MIN_SCORE_BRACKET_EXT - LA_PAR_MAX_SCORE_BRACKET_EXT)/(LA_PAR_MIN_SCORE_BRACKET_SPEED - LA_PAR_MAX_SCORE_BRACKET_SPEED)),
  LA_PAR_MAX_SCORE_BRACKET_EXT - (((LA_PAR_MIN_SCORE_BRACKET_EXT - LA_PAR_MAX_SCORE_BRACKET_EXT)/(LA_PAR_MIN_SCORE_BRACKET_SPEED - LA_PAR_MAX_SCORE_BRACKET_SPEED))*LA_PAR_MAX_SCORE_BRACKET_SPEED)
};
#endif

/* PRQA L:MACRO_IDENTIFIER_LENGTH*/
/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*! Global seek lane width variable. Cached here to avoid recalculating linear
interpolation ramp over and over again */
/*! Global track lane width variable. Cached here to avoid recalculation */

#if (LA_CFG_CALIBRATE_SEEK_LANE_WIDTH)
/*! Structure used to calibrate lane widths over CANAPE */
SET_MEMSEC_VAR(LACalibLaneWidth)
static struct {
  boolean bOverride;          /*!< Boolean flag. Set to 1 if override of lane width requested @min: FALSE @max: TRUE */
  float32 fSeekLaneWidth;     /*!< The seek lane width to use @min: LA_CALIB_LANE_WIDTH_MIN @max: LA_CALIB_LANE_WIDTH_MAX */
  float32 fAutoSeekLaneWidth; /*!< The seek lane width which would be used if override is not active @min: LA_CALIB_LANE_WIDTH_MIN @max: LA_CALIB_LANE_WIDTH_MAX @unit: m @addinfo: nocalib */
} LACalibLaneWidth;
#endif

SET_MEMSEC_CONST(LA_SRandUnsicherAbstand)
static const GDBLFunction_t LA_SRandUnsicherAbstand = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_FSZ_SRANDUNSICHER_MIN,   /*!< A1 */
  LA_FSZ_SRANDUNSICHER_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_FSZ_SRANDUNSICHER_MAX - LA_FSZ_SRANDUNSICHER_MIN ) / ( LA_FSZ_SRAND_ABST_MAX - LA_FSZ_SRAND_ABST_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_FSZ_SRANDUNSICHER_MIN
  -( (( LA_FSZ_SRANDUNSICHER_MAX - LA_FSZ_SRANDUNSICHER_MIN ) / ( LA_FSZ_SRAND_ABST_MAX - LA_FSZ_SRAND_ABST_MIN ))
  * LA_FSZ_SRAND_ABST_MIN )
};

#if (LA_CFG_AVOID_SPILT_OBJ)
/* Factor used to calculate split objects */
static const LA_t_FindObjInAreaArgs LA_SplitObjectCheckArgs = // PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (LA_SPLIT_OBJ_DELTAX_LOWER),
  (LA_SPLIT_OBJ_DELTAX_UPPER),
  (LA_SPLIT_OBJ_DELTAY_LOWER),
  (LA_SPLIT_OBJ_DELTAY_UPPER),
  (LA_SPLIT_OBJ_DELTAV_LOWER),
  (LA_SPLIT_OBJ_DELTAV_UPPER)
};
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LA_v_RelTraExtensionRoadBorderCI(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut );

static float32 LA_f_RelTraGetYDistFOVAtXDist(float32 f_DistX, LA_t_CorrFOVTypeExtension t_FOVType);

/* Bracket functions */
#if (SIT_CFG_OBJECT_SCORING)
static void LA_v_RelTraExtensionObjectScoring(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput * pBracketOut);
#endif

static void LA_v_RelTraRestrictionTargetOutsideBrackets(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraObjOutput const *pObjOutput, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut );
static void LA_v_RelTraRestrictionAnalogRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_BracketOutput *pBracketOut );
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
static void LA_v_RelTraRestrictObjTrace(LA_t_RelTraObjInput const *pObjInput , LA_t_AssTraEnvironment *pEnvironment , LA_t_BracketOutput *pBracketOut );
#endif
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
static void LA_v_RelTraRestictEgoLaneChange(LA_t_RelTraObjInput const * p_ObjInput, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput * p_BracketOut);
#endif
#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
static void LA_v_RelTraRestictCityNearRange(LA_t_RelTraObjInput const * p_ObjInput, LA_t_BracketOutput * p_BracketOut);
#endif
#if (LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA)
static void LA_v_RelTraExtensionRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut );
#endif
static void LA_v_RelTraExtensionCurveInnerBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut );
#if (FCT_CFG_ROAD_INPUT)
static void LA_v_RelTraExtensionGuardRailRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment,LA_t_BracketOutput *pBracketOut );
#if ((LA_CFG_GUARDRAILROADBORDER_HIGHWAY) && (FCT_CFG_ROAD_INPUT))
static void LA_v_RelTraExtensionHighwayGuardRailRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment,LA_t_BracketOutput *pBracketOut );
#endif /* END IF ((LA_CFG_GUARDRAILROADBORDER_HIGHWAY) && (FCT_CFG_ROAD_INPUT)) */
#endif /* FCT_CFG_ROAD_INPUT */
#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
static void LA_v_RelTraExtensionParallelLaneChange(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut );
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */
static void LA_v_RelCheckOWV(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraObjOutput *pObjOutput, LA_t_AssTraEnvironment const * pEnvironment, LA_t_RelTraCurve const *pRelTraCurve );
static void LA_v_RelTraExtensionFollowObjectIntoCurve(LA_t_RelTraObjInput const *pObjInput, const LA_t_RelTraObjOutput *pObjOutput, LA_t_BracketOutput *pBracketOut, LA_t_RelTraCurve const *pRelTraCurve );
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
static boolean LA_b_CheckTraceCriterion(const ObjNumber_t iObj);
static void LA_v_CalculateTraceBorders(const ObjNumber_t iObj , LADistanceWidth_t * pDistanceWidth);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

/*************************************************************************************************************************
  Functionname:    LA_v_ExecuteRadarRoadBracketFunctions                                                               */ /*!

  @brief           Compute radar related bracket functions comprising extensions and
                   restrictions

  @description     Radar related corridor bracket functions are computed (Extensions and Restrictions). 
                   Different kinds of extensions/Restrictions are computed based on the status of 'pBracketFuncEnableFlags' for the particular scenario.
                   The following scenarios are considered.
                   For Restriction,
                    AnalogRoadBorder
                    TargetOutsideBrackets
                    Based on object traces
                    In the near range for country road /city scenarios
                   For Extension,
                    GuardRailRoadBorder
                    CurveInnerBorder
                    RoadBorderCI
                    FollowObjectIntoCurve
                    RoadBorder

					@startuml
                    Partition LA_v_ExecuteRadarRoadBracketFunctions{
                    Start
                    If (Restriction Analog Road Border is not Disabled) then (TRUE)
                    : Restrict road border based on analog road border criteria;
                    Else (FALSE)
                    Endif 
                    If (Restriction Target Outside Brackets is not Disabled) then (TRUE)
                    : Restriction by turning outer edge;
                    Else (FALSE)
                    Endif
                    If (Restriction for Ego Lane Change is not Disabled) then (TRUE)
                    : Restriction of Trace brackets during ego lane change;
                    Else (FALSE)
                    Endif
                    If (Restriction near range for country road or city scenarios is not Disabled) then (TRUE)
                    : Restriction in the near range for country road /city scenarios;
                    Else (FALSE)
                    Endif
                    If (Extension Guard Rail road Border is not Disabled) then (TRUE)
                    : Extend trajectory if guardrail close to ego;
                    Else (FALSE)
                    Endif
                    If (Extension Curve Inner Border is not Disabled) then (TRUE)
                    : Extension of Trace brackets;
                    Else (FALSE)
                    Endif
                    If (Extension Road Border CI is not Disabled) then (TRUE)
                    : Extension of road border on left or right;
                    Else (FALSE)
                    Endif
                    If (Extension Follow Object Into Curve is not Disabled) then (TRUE)
                    : extend the trace brackets if object followed;
                    Else (FALSE)
                    Endif
                    If (Extension Road Border is not Disabled) then (TRUE)
                    : Extension of Trace brackets based on the Road border;
                    Else (FALSE)
                    Endif
                    If (Extension Object Scoring is not Disabled) then (TRUE)
                    : Extension of Trace brackets from object scoring;
                    Else (FALSE)
                    Endif
                    If (Extension Parallel Lane Change is not Disabled) then (TRUE)
                    : Extension of Trace brackets from object scoring;
                    Else (FALSE)
                    Endif
                    End 
                    }
                    @enduml


  @return          void

  @param[in]       pObjectProperties : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction/Extension. Defined in la_corridor_crit.h
  @param[in,out]   pObjectVariables : Pointer to an LA_t_RelTraObjOutput type structure. Defined in la_corridor_crit.h
  @param[in]       pTrajectory : Pointer to an LA_t_RelTraCurve type structure, which describes the trajectory. Defined in la_corridor_crit.h
  @param[in,out]   pEnvironment : pointer to structure LA_t_AssTraEnvironment, containing lane matrix information.  Defined in la_corridor_crit.h
  @param[in,out]   pBracketFuncResults : pointer to structure LA_t_CriteriaMatrix, contains the information about the corridor of the object (Left and Right bracket Information).
                       RestrictionAnalogRoadBorder : Analog border based Restriction.                                 [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       RestrictionTargetOutsideBrackets : Restriction based on target outside brackets.               [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       RestrictionObjectTrace : Object trace based Restriction.                                       [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       RestrictionCityNearRange : Restriction based on cut-out in near range.                         [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       ExtensionGuardRailRoadBorder : Extension based on GuardRailRoadBorder.                         [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       ExtensionCurveInnerBorder : Extensions for Curve Inner Border.                                 [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       ExtensionRoadBorderCI : Extension for direction Lanes CI.                                      [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       ExtensionFollowObjectIntoCurve : Extension for Following object into curve.                    [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       ExtensionRoadBorder : Road border based extension.                                             [LA_t_BracketOutput as defined in la_corridor_crit.h]
  @param[in]       pBracketFuncEnableFlags : Pointer to structure LA_t_BracketFuncEnable, Decides wheather the particular extension/restriction to be executed or not.
                       pBracketFuncEnableFlags->bEnableRestrictionAnalogRoadBorder : Flag for enabling analog road border restriction             [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableRestrictionTargetOutsideBrackets : Flag for enabling Target Outside Brackets restriction   [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableRestrictionObjTrace : Flag for enabling Object Trace based restriction                     [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableRestrictionCityNearRange : Flag for enabling City Near Range restriction                   [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableExtensionGuardRailRoadBorder : Flag for enabling GuardRail Road Border extension           [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableExtensionCurveInnerBorder : Flag for enabling Curve Inner Border extension                 [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableExtensionRoadBorderCI : Flag for enabling Road Border CI extension                         [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableExtensionFollowObjectIntoCurve : Flag for enabling Follow Object Into Curve Extension      [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                       pBracketFuncEnableFlags->bEnableExtensionRoadBorder : Flag for enabling road border extension.                             [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : To enable restriction based on relevant object trace.
                   LA_CFG_RESTRICTION_EGO_LANE_CHANGE : To eneble restriction for ego lane change.
                   LA_CFG_RESTRICTION_CITY_NEAR_RANGE : To enable a restriction in the near range for country road /city scenarios.
                   FCT_CFG_ROAD_INPUT : Road estimation input to FCT.
                   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
                   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/2/2016
  @changed         2/2/2016

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
                   Fabian Killus
*************************************************************************************************************************/
void LA_v_ExecuteRadarRoadBracketFunctions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_RelTraCurve* const pTrajectory,
                                        LA_t_AssTraEnvironment* const pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, const LA_t_BracketFuncEnable* const pBracketFuncEnableFlags)
{
  /*********************** RESTRICTIONS ******************************/
  
  /* RestrictionAnalogRoadBorder */
  if (pBracketFuncEnableFlags->bEnableRestrictionAnalogRoadBorder != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraRestrictionAnalogRoadBorder(pObjectProperties, pEnvironment, &pBracketFuncResults->RestrictionAnalogRoadBorder);
  }

  /* RestrictionTargetOutsideBrackets */
  if (pBracketFuncEnableFlags->bEnableRestrictionTargetOutsideBrackets != LA_CORR_BRACKET_FUNC_DISABLED)
  {
      LA_v_RelTraRestrictionTargetOutsideBrackets(pObjectProperties, pObjectVariables, pTrajectory, &pBracketFuncResults->RestrictionTargetOutsideBrackets );
  }

#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  /* Restriction based on object traces */
  if (pBracketFuncEnableFlags->bEnableRestrictionObjTrace != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraRestrictObjTrace(pObjectProperties, pEnvironment, &pBracketFuncResults->RestrictionObjectTrace);
  }
#endif

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
  /* Restriction for Ego Lane Change */
  if (pBracketFuncEnableFlags->bEnableRestrictionEgoLaneChange != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraRestictEgoLaneChange(pObjectProperties, pTrajectory, &pBracketFuncResults->AddRestrictionEgoLaneChange);
  }
#endif

#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
  /*! Restriction in the near range for country road /city scenarios */
  if (pBracketFuncEnableFlags->bEnableRestrictionCityNearRange != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraRestictCityNearRange(pObjectProperties, &pBracketFuncResults->RestrictionCityNearRange);
  }
#endif

  /*********************** EXTENSIONS ******************************/

#if (FCT_CFG_ROAD_INPUT)
  /* ExtensionGuardRailRoadBorder */
  if (pBracketFuncEnableFlags->bEnableExtensionGuardRailRoadBorder != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionGuardRailRoadBorder(pObjectProperties, pEnvironment, &pBracketFuncResults->ExtensionGuardRailRoadBorder);
  }
#endif /* FCT_CFG_ROAD_INPUT */

  /* ExtensionCurveInnerBorder */
  if (pBracketFuncEnableFlags->bEnableExtensionCurveInnerBorder != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionCurveInnerBorder(pObjectProperties, pEnvironment, pTrajectory, &pBracketFuncResults->ExtensionCurveInnerBorder);
  }

  /* ExtensionRoadBorderCI */
  if (pBracketFuncEnableFlags->bEnableExtensionRoadBorderCI != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionRoadBorderCI(pObjectProperties, pEnvironment, pTrajectory, &pBracketFuncResults->ExtensionRoadBorderCI);
  }

  /* ExtensionFollowObjectIntoCurve */
  if (pBracketFuncEnableFlags->bEnableExtensionFollowObjectIntoCurve != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    /* Check first if the object should be further followed */
    LA_v_RelCheckOWV(pObjectProperties, pObjectVariables, pEnvironment, pTrajectory);
    /* In case the check was successful, extend the trace brackets accordingly */
    LA_v_RelTraExtensionFollowObjectIntoCurve(pObjectProperties, pObjectVariables, &pBracketFuncResults->ExtensionFollowObjectIntoCurve, pTrajectory);
  }

#if (LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA)
  /* ExtensionRoadBorder */
  if (pBracketFuncEnableFlags->bEnableExtensionRoadBorder != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionRoadBorder(pObjectProperties, pEnvironment, pTrajectory, &pBracketFuncResults->ExtensionRoadBorder);
  }
#endif

#if (SIT_CFG_OBJECT_SCORING)
  /* ExtensionObjectScoring */
  if (pBracketFuncEnableFlags->bEnableExtensionObjScoring != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionObjectScoring(pObjectProperties, &pBracketFuncResults->ExtensionObjScoring);
  }
#endif

#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
  /* ExtensionParallelLaneChange */
  if (pBracketFuncEnableFlags->bEnableExtensionParallelLaneChange != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionParallelLaneChange(pObjectProperties, pEnvironment, pTrajectory, &pBracketFuncResults->ExtensionParallelLaneChange);
  }
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */

}


/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestrictionTargetOutsideBrackets                                                         */ /*!

  @brief           Restriction if target is outside brackets

  @description     Restriction by turning outer edge if target storage
                   is not within the limits

                   @startuml
                   Partition LA_v_RelTraRestrictionTargetOutsideBrackets{
                   Start 
                   If (Object Relevant is False) then (TRUE)
                   If (Preliminary lane association is Ego lane) then (TRUE)
                   If (Object is currently within the lane boundaries) then (TRUE)
                   If (Distance of the current object greater than delta) then (TRUE)
                   If (Object is not relevant) then (TRUE)
                   If (storage difference between object current\n destination greater than 2m) then (TRUE)
                   If (Current destination on the left outside the left lane boundary) then (TRUE)
                   : Move the left lane boundary to the middle of the relevant radius;
                   Elseif (Current destination on the right outside the right lane boundary) then (TRUE)
                   : Move the right lane boundary to the middle of the relevant radius;
                   Else (FALSE)
                   : Current destination within both lane boundaries,\n no action required;
                   Endif 
                   Endif 
                   Endif 
                   Endif 
                   Endif 
                   Endif 
                   If (Preliminary lane association is Ego lane) then (TRUE)
                   If (Object is currently within the lane boundaries) then (TRUE)
                   If (Distance of the current object greater than delta) then (TRUE)
                   If (Object is not relevant) then (TRUE)
                   If (Only on the outside edge of the right-hand bend) then (TRUE)
                   : Move the left lane boundary to the middle of the relevant radius;
                   Else (FALSE)
                   Endif 
                   Elseif (Curvature is greater than Maximum Radius) then (TRUE)
                   : Move the right track boundary to the middle of the relevant radius;
                   Else (FALSE)
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif 
                   End 
                   }
                   @enduml


  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->iRelevant    : [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dAbst_mittel : [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track lane width depending on time and distance : [0.0f ... 1.0f]
                      pObjInput->dAblage_m :      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dAblage_Radius : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->fYPosStdDev : Standard deviation of lateral displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pObjOutput : Pointer to an LA_t_RelTraObjOutput type structure.  Output information about the object. Defined in la_corridor_crit.h
                      pObjOutput->dAblage_SpurGrenze_L : Maximal allowed deviation to left from ideal trajectory,  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjOutput->dAblage_SpurGrenze_R : Maximal allowed deviation to right from ideal trajectory, [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve : Curvature of considered trajectory [-1 … +1] m^-1.
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT : To remove the test removability
                   of FCT dependence on current target information
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             Module global variable 'fLASeekLaneWidth' filled with current seek lane width.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/2/2016
  @changed         2/2/2016

  @author          R. Ehrhardt 
*************************************************************************************************************************/
 static void LA_v_RelTraRestrictionTargetOutsideBrackets(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraObjOutput const *pObjOutput, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut )
{
#if (LA_CFG_AVOID_SPILT_OBJ)
  const SLATE_t_TrafficOrientation  t_TrafficOrientation = pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation;   /* Get traffic-orientation */
  SLATE_t_Obj_CLassification t_ObjClassification = *pt_LAInput->t_RTE.pt_ObjClassification(pObjInput->iObjNr);
  float32 f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(pObjInput->iObjNr);
  ObjNumber_t a_OvertakenObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX]; /* Array of objects possibly overtaken by t_Obj */
  sint8 s_NumOfLaneRight = pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight;
  float32 f_ObjDist2Traj_Obj = 0.0f;
  float32 f_ObjDist2Traj_occ = 0.0f;
  float32 f_Dist2traj_diff = 0.0f;
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
  /* Currently function internal implementation removed to test removability
  of FCT dependence on current target information */
  if (pObjInput->iRelevant == FALSE)
  {
#if LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT  
    /* Objekte bei denen die Ablage des aktuellen Ziels ausserhalb der Spur liegen, werden ausgeblendet */
    if( pObjOutput->iObjektSpur_Zyklus == ASSOC_LANE_EGO )
    { /* Objekt ist aktuell innerhalb der Spurgrenzen */
      if( ( pObjInput->dAbst_mittel > LA_FSZ_ZIELABLAGE_ABSTAND )
        &&( pObjInput->LetztZielEntfernung > 0.F ))
      { /* Abstand des aktuellen Objekts groesser ca. 50m und vorhergehendes Ziel vorhanden */
        if( pObjInput->dRelSpurErweiterungsFaktor < C_F32_DELTA )
        { /* Objekt war in letzter Zeit nicht relevant */
          if( fABS( pObjInput->AktZielHorizontaleAblage - pObjInput->dAblage_m ) > LA_FSZ_ZIELABLAGE_ABLAGEDIFF )
          { /* Ablagedifferenz zwischen Objekt und aktuellem Ziel muss groesser ca. 2m sein */
            if( ( pObjInput->AktZielHorizontaleAblage > pObjOutput->dAblage_SpurGrenze_L )
              &&( pObjInput->LetztZielHorizontaleAblage > pObjOutput->dAblage_SpurGrenze_L ))
            { /* Aktuelles Ziel links ausserhalb der linken Spurgrenze */
              if( pRelTraCurve->dCurve < -LA_FSZ_ZIELABLAGE_KRUEMMUNG )
              {
                /* Nur am Kurvenaussenrand der Rechtskurve */
                /* Linke Spurgrenze bis auf Mitte des relevanten Radius verschieben */
                pBracketOut->BracketPositionLeft = pObjInput->dAblage_Radius;
              }
            }
            else if( ( pObjInput->AktZielHorizontaleAblage < pObjOutput->dAblage_SpurGrenze_R )
                   &&( pObjInput->LetztZielHorizontaleAblage < pObjOutput->dAblage_SpurGrenze_R ))
            { /* Aktuelles Ziel rechts ausserhalb der rechten Spurgrenze */
              if( pRelTraCurve->dCurve > LA_FSZ_ZIELABLAGE_KRUEMMUNG )
              {
                /* Nur am Kurvenaussenrand der Linkskurve */
                /* Rechte Spurgrenze bis auf Mitte des relevanten Radius verschieben */
                pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius;
              }
            }
            else
            {
              /* Aktuelles Ziel innerhalb beider Spurgrenzen, keine Massnahmen erforderlich */
            }
          }
        }
      }
    }
#else
    if( pObjOutput->iObjektSpur_Zyklus == ASSOC_LANE_EGO )
    { /* Objekt ist aktuell innerhalb der Spurgrenzen */
      if( pObjInput->dAbst_mittel > LA_FSZ_ZIELABLAGE_ABSTAND )
      { /* Abstand des Objekts groesser ca. 50m */
        if( pObjInput->dRelSpurErweiterungsFaktor < C_F32_DELTA )
        { /* Objekt war in letzter Zeit nicht relevant */
          if( pRelTraCurve->dCurve < -LA_FSZ_ZIELABLAGE_KRUEMMUNG )
          {
            /* Nur am Kurvenaussenrand der Rechtskurve */
            if ((pObjInput->dAblage_m + (pObjInput->fYPosStdDev * LA_FSZ_Y_STDDEV_WEIGHT_FACTOR)) > pObjOutput->dAblage_SpurGrenze_L)
            {
              /* Linke Spurgrenze bis auf Mitte des relevanten Radius verschieben */
              pBracketOut->BracketPositionLeft = pObjInput->dAblage_Radius;
            }
          }
          else if( pRelTraCurve->dCurve > LA_FSZ_ZIELABLAGE_KRUEMMUNG )
          {
            /* Nur am Kurvenaussenrand der Linkskurve */
            if ((pObjInput->dAblage_m - (pObjInput->fYPosStdDev * LA_FSZ_Y_STDDEV_WEIGHT_FACTOR)) < pObjOutput->dAblage_SpurGrenze_R)
            {
              /* Rechte Spurgrenze bis auf Mitte des relevanten Radius verschieben */
              pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius;
            }
          }
          else
          {
            /*! Nothing */
          }
        }
      }
#if (LA_CFG_AVOID_SPILT_OBJ)
      if(t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT)
      {
        if(pObjInput->dAbst_mittel > LA_SPLIT_OBJ_DIST )
        {
          if(pRelTraCurve->dCurve > C_F32_DELTA)
          {
            LA_v_FindObjInArea(a_OvertakenObjID, pObjInput->iObjNr, &LA_SplitObjectCheckArgs, TRUE);

            if(((t_ObjClassification == SLATE_OBJCLASS_TRUCK) || (t_ObjClassification == SLATE_OBJCLASS_CAR)) &&
               (a_OvertakenObjID[0] >= 0) &&
               (f_ObjVrelX < LA_FAR_TRUCK_VEL_REL) &&
               (s_NumOfLaneRight > 0))
            {
              f_ObjDist2Traj_Obj = pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
              f_ObjDist2Traj_occ = pt_LAOutput->t_LAObjOutputList[a_OvertakenObjID[0]].TrajDist.TrajDistMeas.Y.f0;
              f_Dist2traj_diff = fABS(f_ObjDist2Traj_Obj - f_ObjDist2Traj_occ);
              
              if(f_Dist2traj_diff > LA_LAT_DIFF_SPLIT_OBJ)
              {
                if(t_ObjClassification == SLATE_OBJCLASS_CAR)
                { /* PRQA S 0715 */
                  /* date: 2020-07-10, reviewer:Madhusudhanan (uic10266), reason: suppressing nesting of control structures   */
                  SLATE_t_Obj_CLassification t_SplitObject = *pt_LAInput->t_RTE.pt_ObjClassification(a_OvertakenObjID[0]);
                  
                  if(t_SplitObject == SLATE_OBJCLASS_TRUCK)
                  {
                    pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius;
                  }
                }
                else
                { /* PRQA S 0715 */
                  /* date: 2020-07-10, reviewer:Madhusudhanan (uic10266), reason: suppressing nesting of control structures   */
                  SLATE_t_Obj_CLassification t_SplitObject = *pt_LAInput->t_RTE.pt_ObjClassification(a_OvertakenObjID[0]);
                  
                  if(t_SplitObject != SLATE_OBJCLASS_TRUCK)
                  {
                    pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius;
                  }
                }
              }
            }
          }
          else
          {
            /* Do nothing */
          }
        }
      }
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
    }
#endif
  }
}

#if ( (FCT_CFG_ROAD_INPUT) && (LA_CFG_GUARDRAILROADBORDER_HIGHWAY) )
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionHighwayGuardRailRoadBorder                                                   */ /*!

  @brief           Extend trajectory if guardrail close to ego on highway

  @description     Extend left or right corridor in case of guardrail being close at ego vehicle in case of highway.
                   First, this feature avoids dropouts due to mirror effects which move object position to guardrail.
                   Secondly, it enables a better pick-up range in highway approach scenarios for non-relevant objects.

                   @startuml
                   Partition LA_v_RelTraExtensionHighwayGuardRailRoadBorder{
                   Start
                     : Initialize flag, Object distance, Lateral displacement;
                   If (Object is non-relevant) then (TRUE)
                   If (Object Associated Lane is Unknown OR\n Far Right OR Far Left) then (TRUE)
                     : Do not extend brackets for objects which\n are not close to ego lane;
                   Elseif (Ego velocity is less than Minimum ego velocity in\n guardrail border extension for non-relevant objects OR\n Tunnel Probability is more than Threshold) then (TRUE)
                     : Do not extend brackets for non-relevant\n objects in case of low ego velocity;
                   Else (FALSE)
                     : Check mirror criteria for non-relevant objects;
                   Endif
                   Else (FALSE)
                   Endif
                     : Enable GuardRail Extension only for non camera\n confirmed objects below 60 mtrs;
                     : Get Road Estimation for Right side;
                   If (Ego driving on the outer right lane) then (TRUE)
                   If (Camera Trajectory Based Lane Association says Object is Right Lane \n Road type is City \n Ego Speed below 80KPH \n Object Longitudinal Distance \n is below 35m)
                     : Do not extend the Trace Brackets;
                   Elseif (Tracking Status Right is more than Minimum track status AND\n Right side Road Estimation is less than\n maximum offset of guardrail on highway AND\n Confidence of Right Side is more than\n minimum guardrail road Confidence) then (TRUE)
                     : Compute right road border in autosar coordinates;
                     : If object not inside then Write extended right bracket\n position based on road estimation;
                   Elseif (Tunnel Probability is less than Threshold AND\n Right Distance is more than lowest border distance) then (TRUE)
                     : Write extended right bracket position based on distance to road border;
                   Else (FALSE)
                     : no bracket extension;
                   Endif
                   Else (FALSE)
                   Endif
                     : Get Road Estimation for Left side;
                   If (Ego driving on the outer left lane) then (TRUE)
                   If (Camera Trajectory Based Lane Association says Object is Left Lane \n Road type is City \n Ego Speed below 80KPH \n Object Longitudinal Distance is below 35m)
                     : Do not extend the Trace Brackets;
                   Elseif (Tracking Status Left is more than Minimum track status AND\n Left side Road Estimation is less than\n maximum offset of guardrail on highway AND\n Confidence of Left Side is more than\n minimum guardrail road Confidence) then (TRUE)
                     : Compute Left road border in autosar coordinates;
                     : If object not inside then Write extended Left bracket\n position based on road estimation;
                   Elseif (Tunnel Probability is less than Threshold AND\n Left Distance is more than lowest border distance) then (TRUE)
                     : Write extended Left bracket position based on distance to road border;
                   Else (FALSE)
                     : no bracket extension;
                   Endif
                   Else (FALSE)
                   Endif
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : pointer to an LA_t_RelTraObjInput type structure
  @param[in]       pEnvironment : pointer to structure containing lane matrix information
  @param[in,out]   pBracketOut : pointer to structure containing trace bracket position information
                         BracketPositionRight : Extension of right bracket  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         BracketPositionLeft : Extension of left bracket    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjAssociatedLane : associated lane information of an object i [0u ... 5u]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s 
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel [0.0f ... 1.0f]
  @glob_in         ROAD_GET_BORDER_LEFT : Lateral ego distance to left road border [0.f ... 30.f]
  @glob_in         ROAD_GET_BORDER_RIGHT : Lateral ego distance to right road border [-30.f ... 0.f]
  @glob_in         GET_ROAD_ESTIMATION : Pointer to the estimated road properties
                                 GET_ROAD_ESTIMATION->Legacy.uiTrackingStatusLeft  [0u ... 7u]
                                 GET_ROAD_ESTIMATION->Legacy.uiTrackingStatusRight [0u ... 7u]
                                 GET_ROAD_ESTIMATION->p_RoadEst->fYawAngle         [-PI … +PI] rad
                                 GET_ROAD_ESTIMATION->fC0                          [-1 … +1] m^-1
                                 GET_ROAD_ESTIMATION->fC1                          [-1 … +1] m^-2
                                 GET_ROAD_ESTIMATION->Legacy.fYLeft                [full range of data type float32 >= 0]
                                 GET_ROAD_ESTIMATION->Legacy.fYRight               [full range of data type float32 <= 0]
  @glob_in         ROAD_GET_CONFIDENCE_LEFT : Confidence of road estimation on left side [0.f ... 100.f]
  @glob_in         ROAD_GET_RANGE_LEFT : Distance up to which road estimation on left side is available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         ROAD_GET_CONFIDENCE_RIGHT : Confidence of road estimation on right side [0.f ... 100.f]
  @glob_in         ROAD_GET_RANGE_RIGHT :  Distance up to which road estimation on right side is available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc : Camera trajectory based lane association of an object i    [0      3]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type                           [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY                                  [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : use cam lane change information
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : use cam lane change information
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : use cam lane change information
  @c_switch_part   LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA : Configuration switch to not extend Guard Rail Border Extension depending on Camera Trajectory based Lane Association
  @c_switch_full   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   LA_CFG_GUARDRAILROADBORDER_HIGHWAY : Allow track lane width extension based on road border estimation
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         15.12.2015
  @changed         15.12.2015

  @todo            Decide if pObjInput->dAblage_m/dAbst_mittel or macros should be used. Translate german input signals.
  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static void LA_v_RelTraExtensionHighwayGuardRailRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment,LA_t_BracketOutput *pBracketOut )/* PRQA S 2200 *//* date: 2020-04-02, reviewer: Tejaswini M, reason: Indentation does not have impact on functionality */
{
  ObjNumber_t a_CloseObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX]; /* Array of objects close to ObjNr. Used for mirror check. */
  boolean b_ObjValid = TRUE; /* Flag indicating applicability of extension to non-relevant objects */
  float32 f_ObjDist2Traj; /* Object distance to trajectory */
  float32 f_RoadBorderDisplacement; /* Lateral displacement of extended trace brackets */
  float32 fABS_dAblage_m, fABS_FIPRoadEstimation_Right, fABS_FIPRoadEstimation_Left;	/* For calculating ABS value */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  LA_t_ScaleBracketState LA_LCScaleBracketState = pt_LAOutput->f_LA_StateScaleBracket;
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  boolean      b_CamValid = FALSE;
  percentage_t t_camConfirmationProb = pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].t_CamObjectData.t_CamConfirmationProb;
#endif /* FCT_CFG_CAMERA_OBJECT_DETECTION */

#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA))
  /* Get the object distance */
  float32 fObjDist = *pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr);
#endif /* ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA)) */

#if (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA)
  LA_t_ObjCamTrajLanAssocEnum t_ObjCamTrajLaneAssoc = pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].t_ObjCamTrajLaneAssoc;
  FIP_t_FusedRoadType t_FIPFusedRoadType = pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType;
  float32 f_EgoSpeed = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
#endif /* (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA) */

  /* Extension shall also be possible for non-relevant objects to have better pick-up performance */
  if ( (pObjInput->iRelevant != TRUE) )
  {
	fABS_dAblage_m = fABS(pObjInput->dAblage_m);
    if ( (pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].ObjAssociatedLane == ASSOC_LANE_UNKNOWN)
      || (pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].ObjAssociatedLane == ASSOC_LANE_FAR_RIGHT)
      || (pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].ObjAssociatedLane == ASSOC_LANE_FAR_LEFT))
    {
      /* Do not extend brackets for objects which are not close to ego lane */
      b_ObjValid = FALSE;
    }
    else if ( (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_VEGO_MIN)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
           || (*pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES)
#endif
           || (fABS_dAblage_m  > LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DISTY_MAX)
           || (pObjInput->dAbst_mittel < LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DISTX_MIN)
            )
    {
      /* Do not extend brackets for non-relevant objects in case of low ego velocity, */
      /* in a tunnel, at high lateral distances or low longitudinal distances.        */
      /* In these situations mirrors occur more often */
      b_ObjValid = FALSE;
    }
    else
    {
      /* Check mirror criteria for non-relevant objects: if object is mirror, a second object with same velocity will be close to it */
#if (LA_CFG_AVOID_SPILT_OBJ)
      LA_v_FindObjInArea(a_CloseObjID, pObjInput->iObjNr, &LATraExtensionGuardRailMirrorArgs, FALSE);
#else
      LA_v_FindObjInArea(a_CloseObjID, pObjInput->iObjNr, &LATraExtensionGuardRailMirrorArgs);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/

      /* If a second object has been found, object under consideration is probably a mirror and brackets should not be extended */
      if ( a_CloseObjID[0] != (ObjNumber_t)-1 )
      {
        b_ObjValid = FALSE;
      }
    }
  }

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/* Enable GuardRail Extension only for non camera confirmed objects below 60 mtrs */
    if (fObjDist < LA_GUARDRAIL_CAMCONF_MAX_DISTX)
    {
        if(t_camConfirmationProb > LA_PAR_CAM_CONF_MIN) 
        {
            b_CamValid = TRUE;
        }
    }
#endif
  fABS_FIPRoadEstimation_Right = fABS(pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight);
  /* Ego driving on the outer right lane */
  if ( (pEnvironment->iNumberLanesRight == 0L)
    && (b_ObjValid == TRUE)
    && (pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].ObjAssociatedLane != ASSOC_LANE_LEFT)
#if LA_CFG_ENABLE_CAM_VALIDITY
      && ( b_CamValid == FALSE )
#endif /*end of LA_CFG_ENABLE_CAM_VALIDITY*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
    && ( (LA_LCScaleBracketState == SLATE_NO_LANE_CHANGE) || (LA_LCScaleBracketState == SLATE_LANE_CHANGE_UNKNOWN) )
#endif
     )
  {
#if (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA)
    /* Do not extend the Trace Brackets if 
       Camera Trajectory Based Lane Association says Object is Right Lane
       Road type is City
       Ego Speed below 80KPH
       Object Longitudinal Distance is below 35m */
    if (   (t_ObjCamTrajLaneAssoc == LA_OBJ_CAM_LANE_RIGHT)
        && (t_FIPFusedRoadType == FIP_ROAD_TYPE_CITY)
        && (f_EgoSpeed < LA_DISABLE_EXTENSION_CAM_TRAJ_LA_EGO_SPEED)
        && (fObjDist < LA_DISABLE_EXTENSION_CAM_TRAJ_LA_OBJ_DISTX)
       )
    {
      /* Do not extend the Trace Brackets */
    }
    else 
#endif /* (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA) */
    if (   ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight) > LA_GUARDRAIL_ROAD_BORDER_EXT_MIN_TRK_STATUS )
        && (fABS_FIPRoadEstimation_Right < LA_MAX_GUARDRAIL_OFFSET_HIGHWAY)
        && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight) > LA_MIN_GUARDRAIL_ROAD_CONFIDENCE) 
        && (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated) + LA_MIN_GUARDRAIL_ROAD_RANGE_OFFSET) > pObjInput->dAbst_mittel )       /* Objekt shall not be further away than road estimation range + offset */
       )
    {
      /* Compute right road border in autosar coordinates */
      f_RoadBorderDisplacement = (GDBRoadClothoid (pObjInput->dAbst_mittel, (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle)) + (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight)) - LA_MAX_GUARDRAIL_ROAD_HALF_OBJ_WIDTH;
      /* Objekt has to be inside RoadworksLanewidthSEEK close to the guardrail */
      if ((pObjInput->dAblage_m - f_RoadBorderDisplacement) < LA_MAX_GUARDRAIL_OFFSET_HIGHWAY)
      {
        /* Write extended right bracket position based on road estimation */
        pBracketOut->BracketPositionRight = f_RoadBorderDisplacement;
      }
    }
    else if ( 
#if (FCT_CFG_SIGNAL_PERF_MONITORING)          
          (*pt_LAInput->t_RTE.pf_TunnelProbability < LA_TUNNEL_PROB_THRES) &&
#endif
           ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)  > -LA_GUARDRAIL_BORDER_EXT_MAX_BORDER_DIST)
           && (pObjInput->dAbst_mittel > LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DISTX_MIN)
            )
    {
      /* Write extended right bracket position based on distance to road border */
      f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
      pBracketOut->BracketPositionRight = pObjInput->dAblage_m - f_ObjDist2Traj + (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight);
    }
    else
    {
      /* no bracket extension */
    }
  }
  fABS_FIPRoadEstimation_Left = fABS(pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft);
  /* Ego driving on the outer left lane */
  if (   (pEnvironment->iNumberLanesLeft == 0L)
      && (b_ObjValid == TRUE)
      && (pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].ObjAssociatedLane != ASSOC_LANE_RIGHT)
#if LA_CFG_ENABLE_CAM_VALIDITY
      && ( b_CamValid == FALSE )
#endif /*end of LA_CFG_ENABLE_CAM_VALIDITY*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
      && ( (LA_LCScaleBracketState == SLATE_NO_LANE_CHANGE) || (LA_LCScaleBracketState == SLATE_LANE_CHANGE_UNKNOWN) )
#endif
     )
  {
#if (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA)
    /* Do not extend the Trace Brackets if 
       Camera Trajectory Based Lane Association says Object is Left Lane
       Road type is City
       Ego Speed below 80KPH
       Object Longitudinal Distance is below 35m */
    if (   (t_ObjCamTrajLaneAssoc == LA_OBJ_CAM_LANE_LEFT)
        && (t_FIPFusedRoadType == FIP_ROAD_TYPE_CITY)
        && (f_EgoSpeed < LA_DISABLE_EXTENSION_CAM_TRAJ_LA_EGO_SPEED)
        && (fObjDist < LA_DISABLE_EXTENSION_CAM_TRAJ_LA_OBJ_DISTX)
       )
    {
      /* Do not extend the Trace Brackets */
    }
    else 
#endif /* (LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA) */
    if (   ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft) > LA_GUARDRAIL_ROAD_BORDER_EXT_MIN_TRK_STATUS )
        && (fABS_FIPRoadEstimation_Left < LA_MAX_GUARDRAIL_OFFSET_HIGHWAY) 
        && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft) > LA_MIN_GUARDRAIL_ROAD_CONFIDENCE) 
        && ( ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated) + LA_MIN_GUARDRAIL_ROAD_RANGE_OFFSET) > pObjInput->dAbst_mittel )       /* Objekt shall not be further away than road estimation range + offset */
       )
    {
      /* Compute left road border in autosar coordinates */
      f_RoadBorderDisplacement = (GDBRoadClothoid (pObjInput->dAbst_mittel, (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle)) + (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft)) + LA_MAX_GUARDRAIL_ROAD_HALF_OBJ_WIDTH;
      /* Objekt has to be inside RoadworksLanewidthSEEK close to the guardrail */
      if ((pObjInput->dAblage_m - f_RoadBorderDisplacement) > -LA_MAX_GUARDRAIL_OFFSET_HIGHWAY)
      {
        /* Write extended left bracket position based on road estimation */
        pBracketOut->BracketPositionLeft = f_RoadBorderDisplacement;
      }
    }
    else if (
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
            (*pt_LAInput->t_RTE.pf_TunnelProbability    < LA_TUNNEL_PROB_THRES) &&
#endif
            ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)  < LA_GUARDRAIL_BORDER_EXT_MAX_BORDER_DIST)
           && (pObjInput->dAbst_mittel > LA_GUARDRAIL_BORDER_EXT_VALIDOBJ_DISTX_MIN)
            )
    {
      /* Write extended left bracket position based on distance to road border */
      f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
      pBracketOut->BracketPositionLeft = pObjInput->dAblage_m - f_ObjDist2Traj  + (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft);
    }
    else
    {
        /* no bracket extension */
    }
  }
}
#endif /* ( (FCT_CFG_ROAD_INPUT) && (LA_CFG_GUARDRAILROADBORDER_HIGHWAY) ) */

#if (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionGuardRailRoadBorder                                                             */ /*!

  @brief           Extend trajectory if guardrail close to ego.

  @description     Extend left or right corridor in case of guardrail
                   being close at ego vehicle and relevant target vehicle
                   in case of highway and roadwork scenarios.
                   This feature avoids dropouts due to mirror effects 
                   that falsely move object position to guardrail.

				   @startuml
				   Partition LA_v_RelTraExtensionGuardRailRoadBorder{
				   Start
				   : Get Road Type;
				   If (Road Type is Highway OR\n Ego Velocity is more than Threshold) then (TRUE)
				   : Extend Trajectory;
				   Else (FALSE)
				   Endif
				   : Enable GuardRail Extension only for non camera confirmed objects below 60 mtrs;
				   If (ROADWORKS DETECTED) then (TRUE)
				   : Get Road estimation for right side;
				   If (Tracking Status Right is more than Minimum track status AND\n Right side Road Estimation is less than\n maximum offset of guardrail on highway AND\n Confidence of Right Side is more than\n minimum guardrail road Confidence) then (TRUE)
				   : Get Road Border;
				   : Get Bracket Position for Right side;
				   Else (FALSE)
				   Endif
				   If (Tracking Status Left is more than Minimum track status AND\n Right side Road Estimation is less than\n maximum offset of guardrail on highway AND\n Confidence of Left Side is more than\n minimum guardrail road Confidence) then (TRUE)
				   : Get Road Border;
				   : Get Bracket Position for Left side;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dAbst_mittel : [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dAblage_m :    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_RoadWorks : Reference to FIP road works type [full range of FIP_t_RoadWorks as in fip_ext.h]
  @glob_in         GET_ROAD_ESTIMATION: : Pointer to the estimated road properties of type RoadEstimation_t. Defined in Rte_Type.h
                       pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft  [0u ... 7u]
                       pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight [0u ... 7u]
                       pt_FIPRoad->t_FIPRoadEstimation.fYLeft                [full range of data type float32 >= 0]
                       pt_FIPRoad->t_FIPRoadEstimation.fYRight               [full range of data type float32 <= 0]
                       pt_FIPRoad->t_FIPRoadEstimation.fYawAngle             [-PI … +PI] rad
                       pt_FIPRoad->t_FIPRoadEstimation.fC0                   [-1 … +1] m^-1
                       pt_FIPRoad->t_FIPRoadEstimation.fC1                   [-1 … +1] m^-2
  @glob_in         pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft : Confidence of road estimation on left side                    [0.f ... 100.f]
  @glob_in         pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight : Confidence of road estimation on right side                  [0.f ... 100.f]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity                                                      [-330.f ... 330.f] m/s 
  @glob_out        -

  @c_switch_part   LA_CFG_GUARDRAILROADBORDER_HIGHWAY : Allow track lane width extension based on road border estimation.
  @c_switch_full   FCT_CFG_ROAD_INPUT : To enable Road estimation input to FCT.
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/4/2016
  @changed         2/4/2016

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Norman Apel | norman.apel@continental-corporation.com | +49 (8382) 9699-365
*************************************************************************************************************************/
static void LA_v_RelTraExtensionGuardRailRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment,LA_t_BracketOutput *pBracketOut )
{
  FIP_t_FusedRoadType iRoadTypeLevel1;
  FIP_t_RoadWorks iRoadTypeLevel2;

  float32 dAblage_RoadBorder;
  float32 fABS_pRoadEst_Legacy_fYRight;
  float32 fABS_pRoadEst_Legacy_fYLeft;

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  boolean      b_CamValid = FALSE;
  percentage_t t_camConfirmationProb = pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].t_CamObjectData.t_CamConfirmationProb;
  float32 fObjDist = *pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr);
#endif /* FCT_CFG_CAMERA_OBJECT_DETECTION */



#if (FCT_CFG_INPUT_PREPROCESSSING)
  iRoadTypeLevel1 = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
  iRoadTypeLevel2 = (pt_LAInput->pt_FIPRoadType->t_FIPRoadWorks);
#else
  iRoadTypeLevel1 = FIP_ROAD_TYPE_UNKNOWN;
  iRoadTypeLevel2 = FIP_NOINFO_ROADWORKS;
#endif

#if (LA_CFG_GUARDRAILROADBORDER_HIGHWAY)
  if( (( iRoadTypeLevel1 == FIP_ROAD_TYPE_HIGHWAY ) || (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_GUARDRAILEXT_V_THRES)) )
  {
    LA_v_RelTraExtensionHighwayGuardRailRoadBorder(pObjInput, pEnvironment, pBracketOut);
  }
#else
_PARAM_UNUSED(pEnvironment);
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/* Enable GuardRail Extension only for non camera confirmed objects below 60 mtrs */
    if (fObjDist < LA_GUARDRAIL_CAMCONF_MAX_DISTX)
    {
        if(t_camConfirmationProb > LA_PAR_CAM_CONF_MIN) 
        {
            b_CamValid = TRUE;
        }
    }
#endif

  if(iRoadTypeLevel2 == FIP_ROADWORKS_DETECTED)
  {
    /* Rechts */
    fABS_pRoadEst_Legacy_fYRight = fABS((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight));
    if(  ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight) > LA_GUARDRAIL_ROAD_BORDER_EXT_MIN_TRK_STATUS )
      && (fABS_pRoadEst_Legacy_fYRight < LA_MAX_GUARDRAIL_OFFSET_ROADWORKS)
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight) > LA_MIN_GUARDRAIL_ROAD_CONFIDENCE)
#if LA_CFG_ENABLE_CAM_VALIDITY
      && ( b_CamValid == FALSE )
#endif /*end of LA_CFG_ENABLE_CAM_VALIDITY*/      
      )
    {
      /* Objekt darf nicht weiter als RE Reichweite + Offset entfernt sein */
      if( ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated) + LA_MIN_GUARDRAIL_ROAD_RANGE_OFFSET) > pObjInput->dAbst_mittel )
      {
        /* Berechne rechte Roadboarder in Autosarkoordinaten */
        dAblage_RoadBorder = (GDBRoadClothoid (pObjInput->dAbst_mittel, (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle)) + (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight)) - LA_MAX_GUARDRAIL_ROAD_HALF_OBJ_WIDTH;
        /* Objekt muss innerhalb einer RoadworksLanewidthSEEK neben der Leitplanke sein*/
        if((pObjInput->dAblage_m - dAblage_RoadBorder) < LA_MAX_GUARDRAIL_OFFSET_ROADWORKS)
        {
          /* Spurklammerposition schreiben */
          pBracketOut->BracketPositionRight = dAblage_RoadBorder;
        }
      }
    }

    /* dito Links */      
    fABS_pRoadEst_Legacy_fYLeft = fABS(pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft);
    if(  ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft) > LA_GUARDRAIL_ROAD_BORDER_EXT_MIN_TRK_STATUS )
      && (fABS_pRoadEst_Legacy_fYLeft < LA_MAX_GUARDRAIL_OFFSET_ROADWORKS) 
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft) > LA_MIN_GUARDRAIL_ROAD_CONFIDENCE)
#if (LA_CFG_ENABLE_CAM_VALIDITY)
      && ( b_CamValid == FALSE )
#endif /*end of LA_CFG_ENABLE_CAM_VALIDITY*/    
      )
    {
      /* Objekt darf nicht weiter als RE Reichweite + Offset entfernt sein */
      if( ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated)+LA_MIN_GUARDRAIL_ROAD_RANGE_OFFSET) > pObjInput->dAbst_mittel )
      {
        /* Berechne linke Roadboarder in Autosarkoordinaten */
        dAblage_RoadBorder = (GDBRoadClothoid (pObjInput->dAbst_mittel, (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1), (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle)) + (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft)) + LA_MAX_GUARDRAIL_ROAD_HALF_OBJ_WIDTH;
        /* Objekt muss innerhalb einer RoadworksLanewidthSEEK neben der Leitplanke sein*/
        if((pObjInput->dAblage_m - dAblage_RoadBorder) > -LA_MAX_GUARDRAIL_OFFSET_ROADWORKS)
        {
          /* Spurklammerposition schreiben */
          pBracketOut->BracketPositionLeft = dAblage_RoadBorder;
        }
      }
    }
  }
}
#endif  /* #if (FCT_CFG_ROAD_INPUT) */


#if (SIT_CFG_OBJECT_SCORING)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionObjectScoring                                                                   */ /*!

  @brief           Set trace brackets extension from object scoring

  @description     Set extended trace brackets based on lane assignment from
                   object scoring. If object scoring reports object to be
                   in ego lane, then extend base seek brackets to allow object
                   to become in-lane easier.

				   @startuml
				   Partition LA_v_RelTraExtensionObjectScoring{
				   Start
				   : Get the lane assigned to the object by the scoring module;
				   If (assigned to ego lane and not close to field of\n view border in the near range) then (TRUE)
				   : extend base brackets;
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp                                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SLATE_f_GetObjectAngle                                                                       [-PI … +PI] rad
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync                                                            [-330.f ... 330.f]
  @glob_in         pt_LAOutput->f_LA_SeekLaneWidth : global seek lane width variable                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT.
  @c_switch_full   SIT_CFG_OBJECT_SCORING     : Configuration switch to enable new object scoring module.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             SI object scoring already done (SIT_t_GetScoringAssocLane callable)
                   LA_v_CalculateBaseLaneWidths has to be calculated for pt_LAOutput->f_LA_SeekLaneWidth
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/23/2016
  @changed         2/23/2016

  @author          Lonard | lonard.manohar@continental-corporation.com | +91 (80) 6679-6053
*************************************************************************************************************************/
static void LA_v_RelTraExtensionObjectScoring(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput * pBracketOut)
{
  
  /* Get the lane assigned to the object by the scoring module */
  const eAssociatedLane_t eScoreLane = *(pt_LAInput->t_SIT.pt_ScoringAssocLane(pObjInput->iObjNr));
  const float32 fLASeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;

  /* If assigned to ego lane and not close to field of view border in the near range, then extend base brackets */
  if( (eScoreLane == ASSOC_LANE_EGO) &&     /*< assigned to ego lane */
      ( (*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr) > LA_TB_EXTENSION_DIST_X_MIN_OBJSCORING_NEARRANGE) ||  /*< not close to field of view border in the near range */
        ( ( (SLATE_f_GetObjectAngle(pObjInput->iObjNr) >= 0.f) && 
#if (FCT_CFG_RSP_CONTEXT_INPUT)
            (SLATE_f_GetObjectAngle(pObjInput->iObjNr) < MIN_FLOAT(LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE, GET_AZ_FOF_LEFT(RSP_ANT_NEAR))) 
#else
/* <ln_offset:+1 PCLINT Error 975: reviewer name: Boll date: 05-10-2012 reason: #pragma */
#if (defined(_MSC_VER))
#pragma COMPILEMSG("Verify that limiting angle to LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE is OK!")
#endif
            (SLATE_f_GetObjectAngle(pObjInput->iObjNr) < LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE) 
#endif
          ) ||
          ( (SLATE_f_GetObjectAngle(pObjInput->iObjNr) < 0.f) && 
#if (FCT_CFG_RSP_CONTEXT_INPUT)
            (SLATE_f_GetObjectAngle(pObjInput->iObjNr) > MAX_FLOAT(-LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE, GET_AZ_FOF_RIGHT(RSP_ANT_NEAR))) 
#else
/* <ln_offset:+1 PCLINT Error 975: reviewer name: Boll date: 05-10-2012 reason: #pragma */
#if (defined(_MSC_VER))
#pragma COMPILEMSG("Verify that limiting angle to LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE is OK!")
#endif
            (SLATE_f_GetObjectAngle(pObjInput->iObjNr) > -LA_TB_EXTENSION_ANGLE_MAX_OBJSCORING_NEARRANGE) 
#endif
          )
        )
      )
    )
  {
    const float32 fMaxScoreExt = dGDBmathLineareFunktion(&ScoringExtensionSize, *pt_LAInput->t_RTE.pf_EgoVelObjSync);
    const float32 fExtHalfWidth = fMaxScoreExt + (fLASeekLaneWidth * 0.5F);
    pBracketOut->BracketPositionLeft  = pObjInput->dAblage_Radius + fExtHalfWidth;
    pBracketOut->BracketPositionRight = pObjInput->dAblage_Radius - fExtHalfWidth;
  }
}
#endif

#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
/*************************************************************************************************************************
  Functionname:         LA_v_RelTraExtensionParallelLaneChange                                                       */ /*!

  @brief                Extension of Trace brackets based on the Parallel Lane Change Detection.

  @description          Extension of trace brackets based on the Parallel Lane Change Detection.
                          - Only for relevant objects.
                          - Extension depends on the direction of the Lane Change.
                          - For  curves with larger radius, limit maximum lateral deviation from predicted course
                            to a maximum
                          - In tight curves extend trace brackets up to a given maximal lateral distance
                            from the predicted course

							@startuml
							Partition LA_v_RelTraExtensionParallelLaneChange{
							Start
							: Initialize Object number, Distance to Trajectory, Trace ID;
							If (Rel Object number is object number AND\n Trace ID less than trace valid no object ID) then (TRUE)
							: Extension based on right and left curve;
							If (curvature higher than a threshold) then (TRUE)
							: Open trace bracket to the border of the FoV;
							If (Distance to Trajectory is higher) then (TRUE)
							: Set left trace bracket;
							Elseif (Distance to Trajectory is low) then (TRUE)
							: Set right trace bracket;
							Else (FALSE)
							Endif
							Else (FALSE)
							: Set Trace Parallel LC Info;
							Endif
							Else (FALSE)
							Endif
							End
							}
							@enduml

  @return               -

  @param[in]            pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. [as defined in la_corridor_crit.h]
                           pObjInput->dAbst_mittel                                           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                           pObjInput->dAblageSpurGrenzeL                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                           pObjInput->dAblageSpurGrenzeR                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                           pObjInput->iObjNr : ObjNumber_t as defined in Rte_type.h,            [ 0 ... EM_N_OBJECTS-1s]
  @param[in]            pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. [as defined in la_corridor_crit.h]
                           pEnvironment->iRelObjNr : ObjNumber_t defined in Rte_type.h,      [ 0 ... EM_N_OBJECTS-1s]
  @param[in]            pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                           pRelTraCurve->dCurve : curvature value of considered trajectory   [-1 … +1] m^-1
  @param[in,out]        pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. [as defined in la_corridor_crit.h]
                           pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                           pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in              pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity                               [-330.f ... 330.f] m/s
                        pt_LAInput->t_SIT.pt_GetLaneChangeInfo
                          t_LCPhase : Ego Lane Change stage indicator                                   [Pre lanechange , mid lanechange, post lanechange]
                          t_LCPhaseState : Ego Lane change state                                        [LC_RIGHT ... LC_LEFT]

  @c_switch_part        LA_EXTENDED_CURVEINNERBORDER_CRITERION : Configuration switch to enable extended CurveInnerBorder criterion
  @c_switch_full        FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full        FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full        LA_CFG_EXT_PARALLEL_LANE_CHANGE : Configuration switch for enabling Parallel lane change extension

  @pre                  -
  @post                 -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author               Rahul Raj | Rahul.Raj@continental-corporation.com | +91 (80) 6679-7305
*************************************************************************************************************************/
static void LA_v_RelTraExtensionParallelLaneChange(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut )
{
  /*--- VARIABLES ---*/
  float32 fExtensionFoV = 0.f;
  ObjNumber_t iObjNr = pObjInput->iObjNr;
  static boolean bTraceParallelLCInfo[EM_N_OBJECTS];
  float32 fDistToTraj = pt_LAOutput->t_LAObjOutputList[iObjNr].TrajDist.TrajDistMeas.Y.f0;
  TraceID_t iTraceID = *pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID(iObjNr);

  if( (pEnvironment->iRelObjNr == pObjInput->iObjNr) &&
      (iTraceID < FIP_u_TRACE_VALID_NO_OBJ_ID)) 
  {
    if(  (pObjInput->dAbst_mittel < LA_PARALLEL_MAX_DISTX) 
       &&(*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_PARALLEL_MAX_VELOCITY) ) 
    {
      if (pRelTraCurve->dCurve < 0.f )
      {
        /*! In case of a right curve */
        fExtensionFoV = ((pObjInput->dAbst_mittel * TAN_(DEG2RAD(LA_ECIBO_MAX_EXTENTIONANGLE_TAN))) + SLATE_f_GetSensorYPosition());
      }
      else
      {
        /*! In case of a left curve */
        fExtensionFoV = ((pObjInput->dAbst_mittel * TAN_(DEG2RAD(-LA_ECIBO_MAX_EXTENTIONANGLE_TAN))) + SLATE_f_GetSensorYPosition());
      }
    }

    /*! Right curve: If curvature higher than a threshold */
    if( pRelTraCurve->dCurve < -0.f )
    {
      /*! Open trace bracket to the border of the FoV (with filter) */
      if( fExtensionFoV < pObjInput->dAblageSpurGrenzeR )
      {
        float32 fFilterTimeConst = 0.0f;
        if( SLATE_f_GetSITCycleTime() > C_F32_DELTA )
        {
          fFilterTimeConst = (LA_TIMECONST_INNER_CURVE_EXT /SLATE_f_GetSITCycleTime());
        }
        fExtensionFoV = GDB_FILTER (fExtensionFoV, pObjInput->dAblageSpurGrenzeR, fFilterTimeConst);
      }

      if ( (    (pObjInput->dAbst_mittel < LA_PARALLEL_MAX_DISTX) 
             && (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_PARALLEL_MAX_VELOCITY)
             && ((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_PRELANECHANGE) || (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_LANECHANGE))
             && ( pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState == LC_RIGHT)
             && ( pt_LAInput->t_CP.pt_TrajectoryData->t_TraceLaneChangeInfo[iTraceID].t_TraceLaneChange == SLATE_LC_RIGHT)
           )
         ||(    (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase != LC_NO_LANECHANGE)
             && ( pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState == LC_RIGHT)
             && ( bTraceParallelLCInfo[iObjNr] == TRUE)
           )
         )
      {
        if (fDistToTraj > 0.f)
        {
          bTraceParallelLCInfo[iObjNr] = TRUE;

          /*! Set left trace bracket */
          pBracketOut->BracketPositionLeft = fExtensionFoV;
        }
        else if (fDistToTraj < 0.f)
        {
          bTraceParallelLCInfo[iObjNr] = TRUE;

          /*! Set right trace bracket */
          pBracketOut->BracketPositionRight = -fExtensionFoV;
        }
		else
		{
      		/* dummy else to keep QAC happy */
		}
        
      }
      else
      {
        bTraceParallelLCInfo[iObjNr] = FALSE;
      }
    }

     /*! Left curve: If curvature higher than a threshold */
    if( pRelTraCurve->dCurve > 0.f )
    {
      /*! Open trace bracket to the border of the FoV (with filter) */
      if( fExtensionFoV > pObjInput->dAblageSpurGrenzeL )
      {
        float32 fFilterTimeConst = 0.0f;
        if( SLATE_f_GetSITCycleTime() > C_F32_DELTA )
        {
          fFilterTimeConst = (LA_TIMECONST_INNER_CURVE_EXT /SLATE_f_GetSITCycleTime());
        }
        fExtensionFoV = GDB_FILTER (fExtensionFoV, pObjInput->dAblageSpurGrenzeL, fFilterTimeConst);
      }

      if ( (    (pObjInput->dAbst_mittel < LA_PARALLEL_MAX_DISTX) 
             && (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_PARALLEL_MAX_VELOCITY)
             && ((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_PRELANECHANGE) || (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_LANECHANGE))
             && ( pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState == LC_LEFT)
             && ( pt_LAInput->t_CP.pt_TrajectoryData->t_TraceLaneChangeInfo[iTraceID].t_TraceLaneChange == SLATE_LC_LEFT)
           )
         ||(    (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase != LC_NO_LANECHANGE)
             && ( pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState == LC_LEFT)
             && ( bTraceParallelLCInfo[iObjNr] == TRUE)
           )
         )
      {
        if (fDistToTraj < 0.f)
        {
          bTraceParallelLCInfo[iObjNr] = TRUE;
        
          /*! Set right trace bracket */
          pBracketOut->BracketPositionRight = fExtensionFoV;
        }
        else if (fDistToTraj > 0.f)
        {
          bTraceParallelLCInfo[iObjNr] = TRUE;
        
          /*! Set left trace bracket */
          pBracketOut->BracketPositionLeft = -fExtensionFoV;
        }
		else
		{
      		/* dummy else to keep QAC happy */
		}
        
      }
      else
      {
        bTraceParallelLCInfo[iObjNr] = FALSE;
      }
    }
  }
}
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestrictionAnalogRoadBorder                                                              */ /*!

  @brief           Restrict road border based on analog road border criteria.

  @description     Objects beyond the road border (+ uncertainty) are discard.
					
					@startuml
					Partition LA_v_RelTraRestrictionAnalogRoadBorder{
					Start
					If (End of road border Right is higher) then (TRUE)
					: Get Factor to scale the right trace bracket;
					Else (FALSE)
					Endif
					If (End of road border Left is higher) then (TRUE)
					: Get Factor to scale the left trace bracket;
					Else (FALSE)
					Endif
					End
					}
					@enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                        pObjInput->dAbst_mittel :   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        pObjInput->dAblage_Radius : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                        pEnvironment->dEOBorderLeft : End of road border, When positive, the distance to the road border left      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pEnvironment->dEOBorderRight : End of road border, When positive, the distance to the road border right    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                        pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pBracketOut->BracketPositionRight : Factor to scale the right trace bracket.    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
 
  @created         2/5/2016
  @changed         2/5/2016

  @author          R.Ehrhardt 
*************************************************************************************************************************/
static void LA_v_RelTraRestrictionAnalogRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_BracketOutput *pBracketOut )
{
  /* Objekte die ausserhalb des Strassenrands liegen abschneiden */

  if( pEnvironment->dEOBorderRight >= 0.f )
  {
    /* Spurklammerposition schreiben */
    pBracketOut->BracketPositionRight = (pObjInput->dAblage_Radius - pEnvironment->dEOBorderRight) - dGDBmathLineareFunktion( &LA_SRandUnsicherAbstand, pObjInput->dAbst_mittel );

  }

  if (pEnvironment->dEOBorderLeft >= 0.f)
  {
    /* Spurklammerposition schreiben */
    pBracketOut->BracketPositionLeft = pObjInput->dAblage_Radius + pEnvironment->dEOBorderLeft + dGDBmathLineareFunktion( &LA_SRandUnsicherAbstand, pObjInput->dAbst_mittel );

  }
}

#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestrictObjTrace                                                                         */ /*!

  @brief           Evaluates conditions for restriction based on object trace

  @description     This function imposes restrictions based on difference between 
                   EGO/ACC-trajectory and the object trace. It is intended to allow 
                   faster recognition of cut-outs
                   Restriction applied only:
                      if EGO is traveling above a certain speed
                      if road type is highway 
                      if the longitudinal distance in within limits
                      if the number of lanes in the direction of the object is above zero 
                      if the object is not overtaking another object (cut-out not possible)

					  @startuml
					  Partition LA_v_RelTraRestrictObjTrace{
					  Start
					  : Initialize Longitudinal distance of the object, Difference between\n EGO path and relevant object trace, Difference between ACC trajectory\n and relevant object trace, Object trace offset, road type;
					  : Get lane matrix information;
					  : Get object distance to trajectory;
					  : Get information if object is overtaking another object;
					  If (object has a valid trace ID) then (Invalid ID)
					  : No valid trace ID means that there\n can be no polynomial approximation;
					  Else (Valid ID)
					  : Get the object distance;
					  : Store polynomial trace parameters;
					  : Get road type information;
					  Endif
					  If (valid trace and EGO is traveling above a certain speed\n and road type is highway and longitudinal distance\n in within limits number of lanes in the direction of object\n is above zero object is not overtaking another object) then (TRUE)
					  : Get the intersection between object trace and EGO/ACC-trajectory;
					  If (Cross Distance is more than Delta and\n Cross distance is less than object distance) then (TRUE)
					  : Get the path difference threshold based on object distance;
					  : Get difference between EGO course and object trace as an area integral\n between intersection to longitudinal distance of the object from EGO;
					  : Get difference between the ACC-Trajectory and object trace as an area integral\n between intersection to longitudinal distance of the object from EGO;
					  Else (FALSE)
					  : Get the path difference threshold based on object distance;
					  : Get difference between EGO course and object trace as an area integral\n between EGO Position to longitudinal distance of the object from EGO;
					  : Get difference between the ACC-Trajectory and object trace as an area integral\n between EGO Position to longitudinal distance of the object from EGO;
					  Endif
					  : Get Average Path difference;
					  : Get the scaling factor for threshold based on curvature;
					  If (object is in OOI list) then (TRUE)
					  If (Average Path difference is less than delta negative) then (TRUE)
					  : Object moving to right, use hard limits;
					  Else (FALSE)
					  : Object moving to left;
					  Endif
					  Elseif (object is in Right or Left OOI list) then (TRUE)
					  : Objects on neighboring lanes;
					  Else (FALSE)
					  : Get Path difference threshold, Object Trace Offset;
					  Endif
					  : Get the threshold for object distance to trajectory - based on curvature;
					  : Factor to scale threshold based on longitudinal distance;
					  If (conditions are fulfilled for application of\n restriction based on object trace) then (TRUE)
					  If (Average Path difference is less than delta negative and\n Object Lateral Val is less than delta negative and\n Object distance to trajectory is less than delta negative) then (TRUE)
					  : Object moving to right, adapt right lane bracket;
					  Elseif (Average Path difference is more than delta and\n Object Lateral Val is more than delta and\n Object distance to trajectory is more than delta) then (TRUE)
					  : Object moving to left, adapt left lane bracket;
					  Else (FALSE)
					  Endif
					  Else (FALSE)
					  Endif
					  Else (FALSE)
					  Endif
					  End
					  }
					  @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                     pObjInput->iObjNr : ObjNumber_t defined in Rte_type.h, [ 0 ... 39] 
  @param[in,out]   pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                     pEnvironment->dEOBorderLeft : End of road border, When positive, the distance to the road border left                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pEnvironment->dEOBorderRight : End of road border, When positive, the distance to the road border right                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pEnvironment->f_EgoObjPathDiffAvg : Difference between EGO path and relevant object trace. Defined in la_corridor_crit.h          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pEnvironment->f_SATrajObjPathDiffAvg : Difference between ACC trajectory and relevant object trace. Defined in la_corridor_crit.h [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                     pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : longitudinal distance                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_TRACE_ID : The trace ID of the object.                        [Datatype of unsigned char] [0 ... 10]
  @glob_in         OBJ_GET_CP : Predicted course information per object of type FCTCoursePred_t. Defined in cp_ext.h
                      OBJ_GET_CP(iObj) : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : ego speed                                  [-330.f ... 330.f] m/s
  @glob_in         CP_TrajectoryData.Current.fTrajC1 : Trajectory clothoid parameter  [-1 … +1] m^-2
  @glob_in         CP_TrajectoryData.Current.fTrajC0 : Trajectory clothoid parameter  [-1 … +1] m^-1
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : ego curve                                    [-1 … +1] m^-1
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX : Macro for accessing ACC Assessed Object List object of interest array (based on GET_FCT_PUB_OBJ_DATA_PTR) [ 0 ... 39] 
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral displacement of an object i     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : To enable restriction based on relevant object trace.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/5/2016
  @changed         2/5/2016

  @todo            Remove this entire line if not needed

  @author          Harsha Umesh Babu | Harsha.Umesh.Babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_RelTraRestrictObjTrace(LA_t_RelTraObjInput const *pObjInput , LA_t_AssTraEnvironment *pEnvironment , LA_t_BracketOutput *pBracketOut )
{
  float32 fTemp1, fTemp2, fCrossDist, f_AveragePathDifference, f_PathDiffThreshold, f_SFThreshold, f_ObjDist2TrajThreshold, f_DistScaleThreshold;
  float32 fObjDist = 0.f;               /* Longitudinal distance of the object */
  float32 f_EgoObjPathDiffAvg = 0.f;    /* Difference between EGO path and relevant object trace, normalized to distance between EGO and relevant object */
  float32 f_SATrajObjPathDiffAvg = 0.f; /* Difference between ACC trajectory and relevant object trace, normalized to distance between EGO and relevant object */
  float32 f_Restriction_ObjTrace_Offset = 0.f;
  float32 fABS_AveragePathDifference, fABS_ObjDist2Traj;	/* For calculating ABS value */
  CAL_t_TracePolyL2 pTracePoly; // PRQA S 3203
  /* date: 2017-01-09, reviewer: Chintan Raval, reason: pTracePoly.fC0 variable is a member of structure and can not be removed */
  ObjNumber_t iObj = pObjInput->iObjNr;
  float32 f_ObjLatVel = *pt_LAInput->t_RTE.pf_ObjVrelY(iObj);

  FIP_t_FusedRoadType iRoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN; /* HIGHWAY=3, NOINFO=0, CITY=1, COUNTYROAD=2 */
  const TraceID_t iObjTrace = *(pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID(iObj));   /* Get the trace ID of the object */

  /* Get lane matrix information */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const sint8 s_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 s_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#endif

  /* Get object distance to trajectory */
  const float32 f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[iObj].TrajDist.TrajDistMeas.Y.f0;

  /* Get information if object is overtaking another object ->  */
  ObjNumber_t t_ObjNrNeighbor = pt_LAOutput->t_NearNeighboringObj[iObj];
  boolean b_ObjIsOvertaking = FALSE;
  if (t_ObjNrNeighbor != OBJ_INDEX_NO_OBJECT)
  {
    b_ObjIsOvertaking = TRUE;
  }
  
  /* Check if object has a valid trace ID */
  if (iObjTrace == FIP_u_TRACE_INVALID_ID)
  {
    /* No valid trace ID means that there can be no polynomial approximation */
    pTracePoly.fC0 = 0.f; // PRQA S 3203, 3199
    /* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: variable is a member of structure, so initialized with others */
    pTracePoly.fC1 = 0.f;
    pTracePoly.fC2 = 0.f;
    pTracePoly.isValid = FALSE;
    iRoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
  } 
  else /* The object has a valid trace ID, further information related to object traces can now be compiled */
  { 
    /* Get the object distance */
    fObjDist = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);

    /* Store polynomial trace parameters of trace iObjTrace*/
    pTracePoly = *pt_LAInput->t_CP.pt_TracePoly(iObjTrace);
    
    /* Get road type information */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  iRoadTypeLevel_1 = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
#else
  iRoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
#endif
    /* date: 2015-07-01, reviewer: Rachit Sharma (uidr5426), reason: variable declared and used in getter function which accepts two arguments */
  } /* END IF Object has a valid trace ID */

  /* This restriction is based on object trace, so first check if we have a valid trace. 
    Apply restriction only:
      if EGO is traveling above a certain speed
      if road type is highway 
      if the longitudinal distance in within limits
      if the number of lanes in the direction of the object is above zero 
      if the object is not overtaking another object (cut-out not possible)
      */
  if ((pTracePoly.isValid == TRUE) && 
      (*pt_LAInput->t_RTE.pf_EgoVelObjSync >= LA_LB_RES_OBJTRACE_SPEED_MIN) &&
      (iRoadTypeLevel_1 == FIP_ROAD_TYPE_HIGHWAY) &&
      (fObjDist >= LA_MIN_TRACE_LENGTH) &&
      (fObjDist < LA_LB_RES_OBJTRACE_DISTX_MAX) &&
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
      ( ((f_ObjDist2Traj >= 0.f) && (s_NumberOfLeftLanes > 0)) ||
        ((f_ObjDist2Traj <= 0.f) && (s_NumberOfRightLanes > 0))
      ) &&
#endif
      (b_ObjIsOvertaking == FALSE) &&
      (t_OOI_ObjectList[iObj].t_Bool.AlreadyOOI == (ubit16_t)1)
     )
  {
    /* Get the intersection between object trace and EGO/ACC-trajectory */
    fCrossDist = *(pt_LAInput->t_SIT.pf_CrossingDistTrace(iObj));

    if ((fCrossDist > C_F32_DELTA) && (fCrossDist < fObjDist))
    {
      /* The trace intersects the EGO/ACC-trajectory between the EGO position and Object */
      /* Get the path difference threshold based on object distance */
      f_PathDiffThreshold = dGDBmathLineareFunktion(&LA_LB_RESTRICTION_OBJTrace_Threshold, (fObjDist - fCrossDist));

      /* Computation of the difference between EGO course and object trace as an area integral between intersection to longitudinal distance of the object from EGO, normalized to x */
      f_EgoObjPathDiffAvg = (((((pTracePoly.fC2 - (0.5f * (*pt_LAInput->t_RTE.pf_EgoCurve))) * fObjDist * (2.f/3.f)) + pTracePoly.fC1) * fObjDist * 0.5f) -
                             ((((pTracePoly.fC2 - (0.5f * (*pt_LAInput->t_RTE.pf_EgoCurve))) * fCrossDist * (2.f/3.f)) + pTracePoly.fC1) * fCrossDist * 0.5f));

      /* Computation of the difference between the ACC-Trajectory and object trace as an area integral between intersection to longitudinal distance of the object from EGO, normalized to x */
      fTemp1 = -0.25f * pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1 * fObjDist;
      fTemp2 = (2.f * pTracePoly.fC2) - pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0;
      f_SATrajObjPathDiffAvg = (((fTemp1 + fTemp2) * (fObjDist/3.f) ) + pTracePoly.fC1) * fObjDist * 0.5f;

      fTemp1 = -0.25f * pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1 * fCrossDist;
      fTemp2 = (2.f * pTracePoly.fC2) - pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0;
      f_SATrajObjPathDiffAvg = f_SATrajObjPathDiffAvg - ((((fTemp1 + fTemp2) * (fCrossDist/3.f) ) + pTracePoly.fC1) * fCrossDist * 0.5f);
    } 
    else
    {
      /* The trace intersection to the EGO/ACC-trajectory is NOT in between the EGO position and Object */
      /* Get the path difference threshold based on object distance */
      f_PathDiffThreshold = dGDBmathLineareFunktion(&LA_LB_RESTRICTION_OBJTrace_Threshold, fObjDist);

      /* Computation of the difference between EGO course and object trace as an area integral between EGO Position to longitudinal distance of the object from EGO, normalized to x */
      f_EgoObjPathDiffAvg = (((pTracePoly.fC2 - (0.5f * (*pt_LAInput->t_RTE.pf_EgoCurve))) * fObjDist * (2.f/3.f)) + pTracePoly.fC1) * fObjDist * 0.5f;

      /* Computation of the difference between the ACC-Trajectory and object trace as an area integral between EGO Position to longitudinal distance of the object from EGO, normalized to x */
      fTemp1 = -0.25f * pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1 * fObjDist;
      fTemp2 = (2.f * pTracePoly.fC2) - pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0;
      f_SATrajObjPathDiffAvg = (((fTemp1 + fTemp2) * (fObjDist/3.f) ) + pTracePoly.fC1) * fObjDist * 0.5f;

    } /* Check if Object trace intersects the EGO/ACC-Trajectory */    

    /* Either of the computation or the average of the two computations can be used to evaluate the restriction, here the average is computed */
    f_AveragePathDifference = (f_EgoObjPathDiffAvg + f_SATrajObjPathDiffAvg)/2.f;

    /* Get the scaling factor for threshold based on curvature. Currently pt_LAInput->t_RTE.pf_EgoCurve is used but it might be better to use pTracePoly.fC1 instead */
    f_SFThreshold = dGDBmathLineareFunktion(&LA_SCALINGFACTOR_CURVATURE, fABS(*pt_LAInput->t_RTE.pf_EgoCurve));

    f_PathDiffThreshold = f_PathDiffThreshold/f_SFThreshold;

    /* Check if an object is in OOI list */
    if ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_HIDDEN_NEXT_OOI) == iObj) || (OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI) == iObj))
    {
      /* Relevant object or next hidden object */
      f_PathDiffThreshold = f_PathDiffThreshold * LA_SF_RES_OBJTRACE_EGOLANE_TH;
      if (f_AveragePathDifference < -C_F32_DELTA)
      {
        /* Object moving to right, use hard limits */
        f_Restriction_ObjTrace_Offset = MIN_FLOAT(*pt_LAInput->t_RTE.pf_ObjLatDisp(iObj), LA_LB_RES_OBJTRACE_EGO_OFFSET) + (LA_LB_RES_OBJTRACE_EGO_OFFSET);
#if (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
        pt_LAOutput->b_EgoObjTracCutOut[iObj]  = TRUE; 
#endif /* end of LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD */
      } 
      else
      {
        /* Object moving to left */
        f_Restriction_ObjTrace_Offset = MIN_FLOAT(*pt_LAInput->t_RTE.pf_ObjLatDisp(iObj), LA_LB_RES_OBJTRACE_EGO_OFFSET) + (LA_LB_RES_OBJTRACE_EGO_OFFSET);
#if (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
        pt_LAOutput->b_EgoObjTracCutOut[iObj]  = TRUE; 
#endif /* end of LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD */
      } /*END IF f_AveragePathDifference < -C_F32_DELTA */
      

    } else if ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_RIGHT_OOI) == iObj) || (OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_RIGHT_OOI) == iObj) ||
             (OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_LEFT_OOI)  == iObj) || (OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_LEFT_OOI)  == iObj) )
    {
      /* Objects on neighboring lanes */
      f_PathDiffThreshold = f_PathDiffThreshold * LA_SF_RES_OBJTRACE_NL_TH;
      f_Restriction_ObjTrace_Offset = LA_LB_RES_OBJTRACE_NL_OFFSET;
    } else 
    {
      /* Other objects - NOT OOI */
      f_PathDiffThreshold = f_PathDiffThreshold * LA_SF_RES_OBJTRACE_OTHER_TH;
      f_Restriction_ObjTrace_Offset = LA_LB_RES_OBJTRACE_OTHER_OFFSET;
    } /* Check for OOI */

    /* Get the threshold for object distance to trajectory - based on curvature */
    f_ObjDist2TrajThreshold = dGDBmathLineareFunktion(&LA_ObjDist2TrajThreshold_CURVATURE, fABS(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0));

    /* Factor to scale threshold based on longitudinal distance */
    f_DistScaleThreshold = dGDBmathLineareFunktion(&LA_t_RestTraceDistSclaeThreshold, fObjDist);
     
	fABS_AveragePathDifference = fABS(f_AveragePathDifference);
	fABS_ObjDist2Traj = fABS(f_ObjDist2Traj);
    /* Check if conditions are fulfilled for application of restriction based on object trace */
    if((fABS_AveragePathDifference > (f_PathDiffThreshold * f_DistScaleThreshold)) && (fABS_ObjDist2Traj > (f_ObjDist2TrajThreshold * f_DistScaleThreshold)))
    {
      if( (f_AveragePathDifference < -C_F32_DELTA ) && (f_ObjLatVel < -C_F32_DELTA) && (f_ObjDist2Traj < -C_F32_DELTA) )
      {
        /* Object moving to right, adapt right lane bracket */
        pBracketOut->BracketPositionRight = (pObjInput->dAblage_Radius + f_Restriction_ObjTrace_Offset);

      } else if ((f_AveragePathDifference > C_F32_DELTA ) && (f_ObjLatVel > C_F32_DELTA) && (f_ObjDist2Traj > C_F32_DELTA) )
      {
        /* Object moving to left, adapt left lane bracket */
        pBracketOut->BracketPositionLeft = (pObjInput->dAblage_Radius - f_Restriction_ObjTrace_Offset);

      } else
      {
        /* DO NOTHING */
      } /*END IF right or left lane brackets */
    } /* if(f_AveragePathDifference > f_PathDiffThreshold) */

  } /* IF valid trace is present and EGO is traveling above certain speed with road type indicating Highway */
  /* Save data for DEBUG */
  pEnvironment->f_EgoObjPathDiffAvg = f_EgoObjPathDiffAvg;
  pEnvironment->f_SATrajObjPathDiffAvg = f_SATrajObjPathDiffAvg;
}
#endif  /*#END IF LA_CFG_ADD_RESTRICTION_OBJ_TRACE */


#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestictCityNearRange                                                                  */ /*!

  @brief           Restriction in the near range for country road /city scenarios to improve the release 
                    of objects that take a turn

  @description     Restriction in the near range for country road /city scenarios to improve the release 
                    of objects that take a turn

					@startuml
					Partition LA_v_RelTraRestictCityNearRange{
					Start
					: Initialize ego speed, ego curve, object class,\n relative velocity, Restriction value;
					: Get distance of object to ACC trajectory;
					: Get EM road type;
					If (driving on a highway or country road AND\n ego speed lower than threshold AND\n object is no truck or point AND\n object is moving AND\n object is near AND\n object's relative velocity is lower than a threshold AND\n ego curve is lower than a threshold) then (TRUE)
					: Get the restriction value based on the longitudinal distance;
					: Apply the restriction on the corresponding side;
					Else (FALSE)
					Endif
					End
					}
					@enduml

  @return          void

  @param[in]       p_ObjInput : Object information
                      p_ObjInput->iObjNr                  [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
                      p_ObjInput->ucDynamicProperty       [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                      p_ObjInput->dAblage_Radius          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   p_BracketOut : 
                      p_BracketOut->BracketPositionLeft   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      p_BracketOut->BracketPositionRight  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : ego speed               [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : ego curve                 [-1 … +1] m^-1
  @glob_in         *SLATE_pt_GetObjClassification : object class              [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : longitudinal distance  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX : relative velocity              [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_FIPRoadType.pt_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_out        -

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ : Switch to restrict bracket for relevant object if associated to left or right lane based on Camera Trajectory Lane Association
  @c_switch_part   LA_CFG_TURN_INDICATOR_COUNTER    : Switch to access the Indicator Timer
  @c_switch_full   LA_CFG_RESTRICTION_CITY_NEAR_RANGE : Restriction in the near range for country road /city scenarios 
                        to improve the release of objects that take a turn
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.09.2015
  @changed         29.09.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void LA_v_RelTraRestictCityNearRange(LA_t_RelTraObjInput const * p_ObjInput, LA_t_BracketOutput * p_BracketOut)
{
  float32 f_RestrictionCityNearRange, f_ObjDist2Traj;
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  float32 f_ObjDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(p_ObjInput->iObjNr);
  float32 f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(p_ObjInput->iObjNr);
  float32 f_EgoCurve = *pt_LAInput->t_RTE.pf_EgoCurve;
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(p_ObjInput->iObjNr);

#if(LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ)
  LA_t_ObjCamTrajLanAssocEnum t_ObjCamTrajLaneAssoc;
#if(LA_CFG_TURN_INDICATOR_COUNTER)
  float32 f_IndTimeLeft, f_IndTimeRight;
#endif /*LA_CFG_TURN_INDICATOR_COUNTER */
  boolean b_ObjisRel;
  boolean bSelectedObjectCamOutlane;
#endif /*LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ */

#if (FCT_CFG_ROAD_INPUT)
  FIP_t_FusedRoadType t_RoadTypeLevel_1;

#endif /* FCT_CFG_ROAD_INPUT */
  /* Initialization of local variable */
  f_RestrictionCityNearRange = 0.f;           /*!< Restriction value */
  /* Get distance of object to ACC trajectory */
  f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
  /* Get EM road type */
#if (FCT_CFG_ROAD_INPUT)
#if (FCT_CFG_INPUT_PREPROCESSSING)
  t_RoadTypeLevel_1 = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
#else
  t_RoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
#endif
#endif /* (FCT_CFG_ROAD_INPUT) */

#if(LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ)
  t_ObjCamTrajLaneAssoc = pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].t_ObjCamTrajLaneAssoc ;
  b_ObjisRel = SLATE_b_GetObjIsRelevant(p_ObjInput->iObjNr);
#if(LA_CFG_TURN_INDICATOR_COUNTER)
  f_IndTimeLeft = pt_LAOutput->f_TurnIndLeftTime; /*Left Indicator timer  */
  f_IndTimeRight= pt_LAOutput->f_TurnIndRightTime;/*Right Indicator timer  */
#endif /*LA_CFG_TURN_INDICATOR_COUNTER */
  bSelectedObjectCamOutlane = FALSE;
#endif /*LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ */

#if(LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ)
  /*! Apply restriction if: 
      -driving on a City road
      -object is relevant
      -object's relative velocity is lower than a threshold
      -ego speed lower than threshold
      -object is associated to left or right lane based on Camera Trajectory Lane Association
      -Ego Indicator should be off in the direction towards the object
  */
  if (  (t_RoadTypeLevel_1 == FIP_ROAD_TYPE_CITY) 
        && (b_ObjisRel == TRUE)
        && (f_ObjDistX < LA_RESTRICTION_CITY_NEAR_CAM_TRAJ_OBJ_DIST)
        && (f_ObjVrelX < LA_RESTRICTION_CITY_NEAR_CAM_TRAJ_VREL)
        && (f_EgoVelObjSync < LA_RESTRICTION_CITY_NEAR_CAM_TRAJ_EGOVEL)
        && ( ((t_ObjCamTrajLaneAssoc == LA_OBJ_CAM_LANE_LEFT) || (t_ObjCamTrajLaneAssoc == LA_OBJ_CAM_LANE_RIGHT)) ) 
#if(LA_CFG_TURN_INDICATOR_COUNTER)
        && ( ((f_ObjDist2Traj < 0.f) && (f_IndTimeRight <= LA_EGO_LANE_CHANGE_IND_TIMER_ZERO) ) || ((f_ObjDist2Traj > 0.f) && (f_IndTimeLeft <= LA_EGO_LANE_CHANGE_IND_TIMER_ZERO)) )
#endif /*LA_CFG_TURN_INDICATOR_COUNTER */
     )
    {
      bSelectedObjectCamOutlane = TRUE;
    }
#endif /*LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ */

  /*! Apply restriction if: 
      -driving on a highway / country road
      -ego speed lower than threshold
      -object is no truck or point (position of these objects are more often wrong due to tracking issues (reflexion point instable))
      -object is moving
      -object is near (longitudinal distance lower 15m)
      -object's relative velocity is lower than a threshold (object is driving slower than ego vehicle to 
                prevent late cut-ins and to get the situation that the object is taking a turn)
      -ego curve is lower than a threshold (if following object in a curve, no restriction should be applied)
  */
  if( 
    (
 #if (FCT_CFG_ROAD_INPUT)
      ( (t_RoadTypeLevel_1 == FIP_ROAD_TYPE_CITY) ||
        (t_RoadTypeLevel_1 == FIP_ROAD_TYPE_COUNTRY)
      ) && 
#endif /* (FCT_CFG_ROAD_INPUT) */
      (f_EgoVelObjSync < LA_REST_CITY_NEAR_RANGE_MAX_VELOCITY) &&
      (t_ObjClassification != SLATE_OBJCLASS_TRUCK) && 
      (t_ObjClassification != SLATE_OBJCLASS_POINT) &&
      (p_ObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) &&
      (f_ObjDistX < LA_REST_CITY_NEAR_RANGE_MAX_DIST_X) &&
      (f_ObjVrelX < LA_REST_CITY_NEAR_RANGE_MAX_VREL) &&
      ( ( (f_ObjDist2Traj > 0.f) && (f_EgoCurve < LA_REST_CITY_NEAR_RANGE_MAX_CURVE) ) ||
        ( (f_ObjDist2Traj < 0.f) && (f_EgoCurve > -LA_REST_CITY_NEAR_RANGE_MAX_CURVE) )   )
#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
      && ((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_NO_LANECHANGE) || (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_LANECHANGE))
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */
    )
#if(LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ)
    || (bSelectedObjectCamOutlane == TRUE)
#endif/*LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ */
    )
  {
    /* Get the restriction value based on the longitudinal distance */
    f_RestrictionCityNearRange = dGDBmathLineareFunktion(&LA_t_RestictCityNearRange, f_ObjDistX);
    /* Apply the restriction on the corresponding side */
    if (f_ObjDist2Traj > 0.f)
    {
      p_BracketOut->BracketPositionLeft = (p_ObjInput->dAblage_Radius + f_RestrictionCityNearRange);
    }
    else
    {
      p_BracketOut->BracketPositionRight = (p_ObjInput->dAblage_Radius - f_RestrictionCityNearRange);
    }
  }
  
}
#endif

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestictEgoLaneChange                                                                      */ /*!

  @brief           Restriction of Trace brackets during ego lane change.

  @description     Restriction of trace brackets  during ego lane change to avoid late releases.
                    - Only for near objects.
                    - Only in road type other than city.
                    - When Ego changes lane towards left, the right bracket of the object will be reduced
                      When Ego changes lane towards Right, the left bracket of the object will be reduced
                    - Only when Indicator was active and Indicator timer is running.
                    - Only for Relevant Object.
                    - Only if the object was relevant for 5s.
                  
                   @startuml
                   start
                   Partition LA_v_LA_v_RelTraRestictEgoLaneChange {
                   if ((road type is highway and object is moving and 
                   object longitudinal displacement is less than a threshold and ego indicator timer is active 
                   and object relevant time is above a threshold and object is relevant) or 
                   (timer for restriction ego lane change is running and object is last OOI0 which is released)) then (Yes) 
                   if (right indicator timer is active) then (yes)
                   : scale the left trace bracket by a factor depending on ego curve;
                   : store the OOI0 object ID;
                   : set timer for restriction ego lane change to maximum time threshold;
                   Elseif (left indicator timer is active) then (yes)
                   : scale the rigt trace bracket by a factor depending on ego curve;
                   : store the OOI0 object ID;
                   : set timer for restriction ego lane change to maximum time threshold;
                   Else(false)
                   : reset timer for restriction ego lane change;
                   Endif
                   Else(false)
                   : reset timer for restriction ego lane change when timer is finished;
                   endif
                   if (timer for restriction ego lane change is running and object is last OOI0 which is released)then (Yes) 
                   : decrement the timer for restriction ego lane change by the cycle time;
                   }
                   stop
                   @enduml

  @return          static void

  @param[in]       p_ObjInput : Object information
                   p_ObjInput->iObjNr                  [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
                   p_ObjInput->ucDynamicProperty       [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                   p_ObjInput->t_FIPFusedRoadType          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                   *pt_LAInput->t_RTE.pf_EgoCurve : Ego curve value [-1 ... +1] m^-1
  @param[in]       pRelTraCurve : Trajectory information
                   pRelTraCurve->iOWVflag              [[full range sint32]]
  @param[in,out]   *p_BracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                   p_BracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                   p_BracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                   p_ObjInput->iObjNr :                [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
  @glob_in         pt_LAOutput->f_TurnIndLeftTime : Left Indicator timer [-5.f ... 0.f] s
  @glob_in         pt_LAOutput->f_TurnIndRightTime : Right Indicator timer [-5.f ... 0.f] s
  @glob_out        pt_LAOutput->f_EgoLCRestrictTimer : Timer for restriction ego lane change [0.f ...1.f]s
  @glob_out        pt_LAOutput->iLastRelObjNr : [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]

  @c_switch_part   LA_CFG_RESTRICTION_EGO_LANE_CHANGE  : Configuration Switch for Improving releases during Ego lane change
  @c_switch_part   LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER : Configuration Switch to enable timer for ego lane change restriction
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         17/10/2019
  @changed         31/03/2019

  @author          Anand Jose
*************************************************************************************************************************/

static void LA_v_RelTraRestictEgoLaneChange(LA_t_RelTraObjInput const * p_ObjInput, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput * p_BracketOut)
{
  float32 f_ObjDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(p_ObjInput->iObjNr);
  FIP_t_FusedRoadType f_RoadType = pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType;
  SLATE_t_Obj_DynamicProperty f_DynamicProperty = p_ObjInput->ucDynamicProperty;
  float32 f_IndTimeLeft ; 
  float32 f_IndTimeRight ;
  float32 f_RelevTime = pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].ObjCor.dRelevantZeit;
  const fCurve_t pf_EgoCurve = *pt_LAInput->t_RTE.pf_EgoCurve;

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
  ObjNumber_t iObjId = p_ObjInput->iObjNr;
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */

  f_IndTimeLeft = pt_LAOutput->f_TurnIndLeftTime;
  f_IndTimeRight= pt_LAOutput->f_TurnIndRightTime;
  
    /*! Apply restriction if: 
      -driving in road type other than city
      -object is moving
      -object distance is less than 120m
      -Ego Indicator was active and Indicator timer is running
      -Object was relevant for at least last 5 seconds
      -Object is relevant
       OR
      -Timer for this restriction is more than 0s
      -Last OOI0 which is released during ego lane change
    */
  if( (  (f_RoadType != FIP_ROAD_TYPE_CITY)
       &&(f_DynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
       &&(f_ObjDistX < LA_EGO_LANE_CHANGE_DISTANCE)
       &&(  (f_IndTimeLeft > LA_EGO_LANE_CHANGE_IND_TIMER_MIN)
          ||(f_IndTimeRight > LA_EGO_LANE_CHANGE_IND_TIMER_MIN))
       &&(f_RelevTime > LA_EGO_LANE_RELEV_TIME)
       &&(p_ObjInput->iRelevant == TRUE))
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
   || (   (pt_LAOutput->f_EgoLCRestrictTimer > C_F32_DELTA)
       && (pt_LAOutput->iLastRelObjNr == iObjId))
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */
    )
  {

    /* Reduce the left trace bracket by a factor if ego right Indicator timer is on and Ego makes a lane change towards right */
    if((f_IndTimeRight < LA_EGO_LANE_CHANGE_IND_TIMER_LIM) && (f_IndTimeRight > LA_EGO_LANE_CHANGE_IND_TIMER_MIN))
    {
      /* Reduction factor is based on linear function of Ego Curve change */
      p_BracketOut->BracketPositionLeft = -dGDBmathLineareFunktion(&LA_t_RestictEgoLaneChange, fABS(pf_EgoCurve));

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
      /* Store the OOI0 object for which this restriction is applied */
      pt_LAOutput->iLastRelObjNr = iObjId;

      if(pt_LAOutput->f_EgoLCRestrictTimer <= C_F32_DELTA)
      {
        pt_LAOutput->f_EgoLCRestrictTimer = LA_EGO_LC_RESTRICT_TIMER_MAX;
      }
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */

    }
    /* Reduce the right trace bracket by a factor if ego left Indicator timer is on and Ego makes a lane change towards left */
    else if((f_IndTimeLeft < LA_EGO_LANE_CHANGE_IND_TIMER_LIM) && (f_IndTimeLeft > LA_EGO_LANE_CHANGE_IND_TIMER_MIN))
    {
      /* Reduction factor is based on linear function of Ego Curve change */
      p_BracketOut->BracketPositionRight = dGDBmathLineareFunktion(&LA_t_RestictEgoLaneChange, fABS(pf_EgoCurve));

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
      /* Store the OOI0 object for which this restriction is applied */
      pt_LAOutput->iLastRelObjNr = iObjId;

      if(pt_LAOutput->f_EgoLCRestrictTimer <= C_F32_DELTA)
      {
        pt_LAOutput->f_EgoLCRestrictTimer = LA_EGO_LC_RESTRICT_TIMER_MAX;
      }
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */

    }
    else
    {
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
      pt_LAOutput->f_EgoLCRestrictTimer = 0.0f;
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */
    }
  }
  else
  {
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
    if (pt_LAOutput->iLastRelObjNr == iObjId)
    {
      pt_LAOutput->f_EgoLCRestrictTimer = 0.0f;
    }
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */
  }

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
  /* Reduce the timer for this restriction till timer reaches 0s for the OOI0 which will be released */
  if (   (pt_LAOutput->f_EgoLCRestrictTimer > C_F32_DELTA)
      && (pt_LAOutput->iLastRelObjNr == iObjId)
#if (LA_CFG_USE_TURNIND_LASTSTATUS)
      && (pRelTraCurve->iOWVflag == LA_OWVKRIT_AKTIV)
#endif /* LA_CFG_USE_TURNIND_LASTSTATUS */
     )
  {
    pt_LAOutput->f_EgoLCRestrictTimer-= SLATE_f_GetSITCycleTime();
  }
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */

#if ((LA_CFG_USE_TURNIND_LASTSTATUS == SWITCH_OFF)|| (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER == SWITCH_OFF))
  _PARAM_UNUSED(pRelTraCurve);
#endif /* (!LA_CFG_USE_TURNIND_LASTSTATUS) && (!LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER) */
}
#endif /*(LA_CFG_RESTRICTION_EGO_LANE_CHANGE) */

#if LA_CFG_TURN_INDICATOR_COUNTER
/* ***********************************************************************
  @fn             LA_v__FilterTurnIndicator                           */ /*!

  @brief          Filter the turn indicator signal

  @description    Filter the turn indicator signal. Prolongs the signal
                  for a given time.

				  @startuml
				  Partition LA_v__FilterTurnIndicator{
				  Start
				  If (turn indicator is switched ON) then (TRUE)
				  If (turn indicator is Left indicator) then (TRUE)
				  : Get turn indicator left time;
				  If (Right time is High) then (TRUE)
				  : Initialize right time;
				  Else (FALSE)
				  Endif
				  Elseif (turn indicator is Right indicator) then (TRUE)
				  : Get turn indicator right time;
				  If (Left time is High) then (TRUE)
				  : Initialize Left time;
				  Else (FALSE)
				  Endif
				  Else (FALSE)
				  : both indicators are ON,Do Nothing;
				  Endif
				  Else (no indicator is switched ON)
				  : hysteresis time is reduced till zero, then the turn indicator\n is assumed to have always been OFF;
				  Endif
				  End
				  }
				  @enduml

  @param          -

  @return         -

  @param[in]       -

  @glob_in         pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft
  @glob_in         pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight
  @glob_out        -

  @c_switch_part   LA_CFG_TURN_INDICATOR_COUNTER :Configuration Switch Enable Counter for Ego lane change indicator 
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         17/10/2019
  @changed         17/10/2019

  @author          Anand Jose

**************************************************************************** */
void LA_v__FilterTurnIndicator(eTurnIndicator_t t_TurnIndicator)
{
  /* eTurnIndicator_Right=2,eTurnIndicator_Invalid=4,eTurnIndicator_Left=1,eTurnIndicator_Off=0,eTurnIndicator_Both=3, */

  /*check if the turn indicator is switched ON or not*/
  if (   (t_TurnIndicator != eTurnIndicator_Off) 
#if (LA_CFG_USE_TURNIND_LASTSTATUS)
      && (pt_LAOutput->TurnIndLastState !=t_TurnIndicator)
#endif /* LA_CFG_USE_TURNIND_LASTSTATUS */
     )
  {
    /* Case: Left indicator, set hysteresis countdown time to the left time filter variable */
    if (t_TurnIndicator == eTurnIndicator_Left)
    {
      pt_LAOutput->f_TurnIndLeftTime = LA_EGO_LANE_CHANGE_IND_TIMER_MAX;
      if(pt_LAOutput->f_TurnIndRightTime > 0.0f )
      {
        /* Left indicator is ON in current cycle but check for Right indicator hysteresis and reduce filter time */
        pt_LAOutput->f_TurnIndRightTime = 0.0f;
      }
    }
    /* Case: Right indicator, set hysteresis countdown time  to the right time filter variable */
    else if (t_TurnIndicator == eTurnIndicator_Right)
    {
      pt_LAOutput->f_TurnIndRightTime = LA_EGO_LANE_CHANGE_IND_TIMER_MAX;
      if(pt_LAOutput->f_TurnIndLeftTime > 0.0f )
      {
        /* Right indicator is ON in current cycle but check for Left indicator hysteresis and reduce filter time */
        pt_LAOutput->f_TurnIndLeftTime = 0.0f;
      }
    }
    else
    {
      /* Case where both indicators are ON, DO NOTHING */
    }
  }
  else /*if no indicator is switched ON then hysteresis time is reduced till zero, then the turn indicator is assumed to have always been OFF*/
  {
    if(pt_LAOutput->f_TurnIndLeftTime > 0.0f )
    {
      pt_LAOutput->f_TurnIndLeftTime-= SLATE_f_GetSITCycleTime();
    }
    if(pt_LAOutput->f_TurnIndRightTime > 0.0f )
    {
      pt_LAOutput->f_TurnIndRightTime-= SLATE_f_GetSITCycleTime();
    }
  } /* Check if Turn indicator is ON (t_TurnIndicator != eTurnIndicator_Off) */
#if (LA_CFG_USE_TURNIND_LASTSTATUS)
  pt_LAOutput->TurnIndLastState = t_TurnIndicator;
#endif /* LA_CFG_USE_TURNIND_LASTSTATUS */
}
#endif /* end of LA_CFG_TURN_INDICATOR_COUNTER */

#if (LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionRoadBorder                                                                      */ /*!

  @brief           Extension of Trace brackets based on the Road border.

  @description     Extension of trace brackets based on the Direction of Curvature.
                       - Only for relevant objects.
                       - Different extension depends on the Curvature.
                       - For  curves with larger radius, limit maximum lateral deviation from predicted course
                         to a maximum
                       - In tight curves extend trace brackets up to a given maximal lateral distance
                         from the predicted course

						 @startuml
						 Partition LA_v_RelTraExtensionRoadBorder{
						 Start
						 : Calculate distance to estimated ego course;
						 : Get Ego velocity, relevant object, Curvature;
						 If (Flag is Active) then (TRUE)
						 If (Object is Relevent) then (TRUE)
						 : Get field of view information for object;
						 : Depending on driven curvature use different extensions;
						 : In tight curves extend trace brackets up to a given maximal\n lateral distance from the predicted course;
						 : Adapt trace bracket extension for Objects having smaller Object width;
						 : Deactivate left road border extension when lane to opposite side is detected;
						 : Adapt trace bracket extension for Objects having smaller Object width;
						 Else (FALSE)
						 Endif
						 Else (FALSE)
						 Endif
						 End
						 }
						 @enduml

  @return          static void

  @param[in]       *pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->iRelevant             [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dAbst_mittel          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dWinkel_mittel        [-PI … +PI] rad
                      pObjInput->dAblageSpurGrenzeL    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dAblageSpurGrenzeR    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dAblage_m             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dAblage_Radius        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dVrel_mittel          [-330.f ... 330.f] m/s
  @param[in]       *pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesRight  [-1 ... 20]
                      pEnvironment->iNumberLanesLeft   [-1 ... 20]
  @param[in]       *pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve : curvature value of considered trajectory              [-1 … +1] m^-1
                      pRelTraCurve->dCurve_abs : Absolute curvature value of considered trajectory [-1 … +1] m^-1
  @param[in,out]   *pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in          pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s 
  @glob_out        -

  @c_switch_part   LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES : Configuration switch for enabling optimized country road hold performance
                       for preventing drop-outs on country roads
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/10/2016
  @changed         2/10/2016

  @author          R. Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraExtensionRoadBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut )
{
  /*--- VARIABLES ---*/

  float32 dAblage_rechts,dAblage_links;
  float32 dAblageSeek;
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
  float32 fABS_pObjInput_dVrel_mittel;
  /* Calculate distance to estimated ego course */
  const float32 fLatDisplToCourse = (pObjInput->dAblage_m - pObjInput->dAblage_Radius);
#endif
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
#if (LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS)
  float32 f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(pObjInput->iObjNr);
  SLATE_t_Obj_CLassification t_ObjClassification = *pt_LAInput->t_RTE.pt_ObjClassification(pObjInput->iObjNr);
#endif /*end of LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS */

  if (pRelTraCurve->iOWVflag == LA_OWVKRIT_AKTIV)
  {

    /* Die maximale Spurklammererweiterung wird in Abhaengigkeit der RELEVANZ der Objekte entschieden */

    /* Ist Objekt relevant und besitzt eine gewisse Spursicherheit? */
    if (pObjInput->iRelevant == (ubit8_t)TRUE)
    {
      float32 fLatDisplFovLeft, fLatDisplFovRight;
      /* Get field of view information for object */
      fLatDisplFovLeft = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel, LA_FAR_AND_NEAR_RANGE_LEFT);
      fLatDisplFovRight = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_AND_NEAR_RANGE_RIGHT);

      /* Depending on driven curvature use different extensions */
      if (pRelTraCurve->dCurve_abs < LA_FSZ_RFS_NARROW_CURVE_REL)
      {
        /* When driving curves with larger radius, limit maximum lateral deviation from predicted course
        to a maximum (SEEK_RFS_ABLAGE_MAX) */
        dAblageSeek = dGDBmathLineareFunktion(&LA_TB_EXTENSION_ROADBORDER, pObjInput->dAbst_mittel);

        /*! Calculate right trace bracket by subtracting the given maximum lateral deviation, 
            Remark: the value can be either negative or positive */
        dAblage_rechts  = pObjInput->dAblage_Radius - dAblageSeek;
        /* Take the larger of the two = take the one closer to zero */
        dAblage_rechts  = MAX_FLOAT( dAblage_rechts, fLatDisplFovRight );

        /*! Calculate the left trace bracket by adding the given maximum lateral deviation, 
            Remark: the value can be either positive or negative */
        dAblage_links   = pObjInput->dAblage_Radius + dAblageSeek;
        /* Take the smaller of the two = take the one closer to zero */
        dAblage_links   = MIN_FLOAT( dAblage_links, fLatDisplFovLeft );
      }
      else
      {
  #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
        /* In tight curves extend trace brackets up to a given maximal lateral distance
        from the predicted course */
        dAblage_rechts = pObjInput->dAblage_Radius - LA_SEEK_RFS_ABLAGE_NARROWCURV_MAX;
        dAblage_rechts = MAX_FLOAT( dAblage_rechts, fLatDisplFovRight);

        dAblage_links  = pObjInput->dAblage_Radius + LA_SEEK_RFS_ABLAGE_NARROWCURV_MAX;
        dAblage_links  = MIN_FLOAT( dAblage_links, fLatDisplFovLeft);
  #else
        /* In tight curves extend the trace brackets to the complete field of view */
        dAblage_rechts = fLatDisplFovRight;
        dAblage_links  = fLatDisplFovLeft;
  #endif
      }

      /* Nutzen der Richtungsfahrspuren Information keine Spur links oder rechts */

  #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
      /* 1.) Objektabstand muss groesser als LA_ABST_KEINESPUR_MIN (ca. 30 m) sein ! */
      /* 2.) Objektabstand muss kleiner als LA_ABST_KEINESPUR_MAX (ca. 130 m) sein ! */
      /* 3.) Eigengeschwindigkeit muss groesser sein als LA_MIN_OWV_VEIGEN (ca. 25 kph)! */
      /* 4.) Objektabstand muss groesser als ca. 63 m oder absolut Wert von Relativgeschwindigkeit */
      /*     kleiner als LA_MIN_OWV_VREL (ca. 25 kph) */
      fABS_pObjInput_dVrel_mittel = fABS(pObjInput->dVrel_mittel);
      if(  (pObjInput->dAbst_mittel > LA_ABST_KEINESPUR_MIN)
        && (pObjInput->dAbst_mittel < LA_ABST_KEINESPUR_MAX)
        && (f_EgoVelObjSync > LA_MIN_OWV_VEIGEN)
        && (  (fABS_pObjInput_dVrel_mittel < LA_MIN_OWV_VREL)
           || (pObjInput->dAbst_mittel > LA_MIN_ABST_VREL )
           )
        )
  #else
      /* 1.) Objektabstand muss groesser als ca. 30 m sein ! */
      /* 2.) Objektabstand muss kleiner als ca. 100 m sein ! */
      /* 3.) Objektabstand muss groesser als ca. 50 m oder Spurkruemmung groesser als 0.5/500m */
      /*     oder Spurgradient muss groesser als 0.0005 sein ! */
      /* 4.) Objektabstand muss groesser als ca. 63 m oder Spurkruemmung groesser als 0.5/3500m */
      /*     oder Spurgradient muss groesser als 0.00035 sein ! */
      /* 5.) bei Abbiegern keine Erweiterung */
      if(  (pObjInput->dAbst_mittel > LA_ABST_KEINESPUR_MIN)
        && (pObjInput->dAbst_mittel < LA_ABST_KEINESPUR_MAX)
        && (  (fABS(pObjInput->dVrel_mittel) < LA_MIN_OWV_VREL)
           || (pObjInput->dAbst_mittel > LA_MIN_ABST_VREL )
           || ((f_EgoVelObjSync + pObjInput->dVrel_mittel) > LA_MIN_OWV_VEIGEN)
           )
        )
  #endif
      {
          if(  ( pEnvironment->iNumberLanesRight == 0L )
  #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
            && (fLatDisplToCourse > -LA_MAX_ROAD_BORD_LAT_NO_TRACE)
  #else
            && ( pEnvironment->dNoLaneProbR > LA_FSZ_RFS_NO_LANE_PROB_MIN)
  #endif
      /*Deactivate right road border extension when lane to opposite side is detected */
            && (((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_NO_LANECHANGE) || (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_STEERBACK))
                ||
                ((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase != LC_NO_LANECHANGE) && (pEnvironment->iNumberLanesLeft <= 0L)))
            )
          {
            if( dAblage_rechts < pObjInput->dAblageSpurGrenzeR )
            {
              float32 fFilterTimeConst = 0.0f;
              float32 fSITCycleTime = SLATE_f_GetSITCycleTime();
              if( fSITCycleTime > C_F32_DELTA )
              {
                fFilterTimeConst = (LA_FSZ_RFS_FILTER_ZEIT / SLATE_f_GetSITCycleTime());
              }
              dAblage_rechts = GDB_FILTER (dAblage_rechts, pObjInput->dAblageSpurGrenzeR, fFilterTimeConst);
            }
#if LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS
            if(   (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE) 
                || (t_ObjClassification == SLATE_OBJCLASS_BICYCLE)
                || (t_ObjClassification == SLATE_OBJCLASS_PEDESTRIAN) 
              )
            {
              /* Adapt trace bracket extension for Objects having smaller Object width*/
              if(pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT)
              {
                if( (f_DistY > (LA_RIGHT_TRAFFIC_ORIENT_DISTY_LIMIT)) && (f_DistY < C_F32_DELTA) )
                {
                  dAblage_rechts *= LA_ADAPT_RBEXT_LESSER_WIDTH_OBJS;
                }
              }
              else if (pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT)
              {
                if( (f_DistY < (LA_LEFT_TRAFFIC_ORIENT_DISTY_LIMIT)) && (f_DistY > C_F32_DELTA) )
                {
                  dAblage_rechts *= LA_ADAPT_RBEXT_LESSER_WIDTH_OBJS;
                }
              }
              else
              {
                /*do nothing*/
              }
            }
#endif /*end of LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS */
            /* Spurklammerposition schreiben */
            pBracketOut->BracketPositionRight = dAblage_rechts;
          }

          if(  (pEnvironment->iNumberLanesLeft == 0L )
  #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
            && (fLatDisplToCourse < LA_MAX_ROAD_BORD_LAT_NO_TRACE)
  #else
            && (pEnvironment->dNoLaneProbL > LA_FSZ_RFS_NO_LANE_PROB_MIN)
  #endif
     /*Deactivate left road border extension when lane to opposite side is detected */
            && (((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_NO_LANECHANGE) || (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_STEERBACK))
                || 
                ((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase != LC_NO_LANECHANGE) && (pEnvironment->iNumberLanesRight <= 0L) ))
            )
          {
            if( dAblage_links > pObjInput->dAblageSpurGrenzeL )
            {
              float32 fFilterTimeConst = 0.0f;
              float32 f_SITCycleTime = SLATE_f_GetSITCycleTime();
              if( f_SITCycleTime > C_F32_DELTA )
              {
                fFilterTimeConst = (LA_FSZ_RFS_FILTER_ZEIT / SLATE_f_GetSITCycleTime());
              }
              dAblage_links = GDB_FILTER (dAblage_links, pObjInput->dAblageSpurGrenzeL, fFilterTimeConst);
            }
#if LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS
            if( (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE) 
                  ||(t_ObjClassification == SLATE_OBJCLASS_BICYCLE)
                  ||(t_ObjClassification == SLATE_OBJCLASS_PEDESTRIAN) 
              )
            {
              /* Adapt trace bracket extension for Objects having smaller Object width*/
              if(pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT)
              {
                if( (f_DistY > LA_RIGHT_TRAFFIC_ORIENT_DISTY_LIMIT) && (f_DistY < C_F32_DELTA) )
                {
                  dAblage_links *= LA_ADAPT_RBEXT_LESSER_WIDTH_OBJS;
                }
              }
              else if (pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT)
              {
                if( (f_DistY < LA_LEFT_TRAFFIC_ORIENT_DISTY_LIMIT) && (f_DistY > C_F32_DELTA) )
                {
                  dAblage_links *= LA_ADAPT_RBEXT_LESSER_WIDTH_OBJS;
                }
              }
              else
              {
                /*do nothing*/
              }
            }
#endif /*end of LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS */
            /* Spurklammerposition schreiben */
            pBracketOut->BracketPositionLeft = dAblage_links;
          }
      }
    }
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionCurveInnerBorder                                                                */ /*!

  @brief           Extension of Trace brackets, for the inner curve..

  @description     Open trace bracket to inner curve based on FoV border or 
                   moved reflection point due to curve.

				   @startuml
				   Partition LA_v_RelTraExtensionCurveInnerBorder{
				   Start
				   : Get Distance to trajectory, Logitudinal Displacement;
				   If (Relevent Object number equals to object number) then (TRUE)
				   : Get Angle between the slope at the curve;
				   : Get Length of object;
				   : Estimation of how far the reflection point moves\n due to the refection from the side;
				   If (right curve) then (TRUE)
				   : Use a wider angle;
				   Else (FALSE)
				   : Use the far range angle only;
				   Endif
				   If (right curvature higher than a threshold) then (TRUE)
				   : Open trace bracket to the border of the FoV (with filter);
				   : Set right trace bracket;
				   Else (FALSE)
				   Endif
				   If (left curve) then (TRUE)
				   : Use a wider angle;
				   Else (FALSE)
				   : Use the far range angle only;
				   Endif
				   If (left curvature higher than a threshold) then (TRUE)
				   : Open trace bracket to the border of the FoV (with filter);
				   : Set left trace bracket;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dAbst_mittel                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dAblageSpurGrenzeL                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dAblageSpurGrenzeR                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->iObjNr : ObjNumber_t defined in Rte_type.h, [ 0 ... EM_N_OBJECTS-1s]
  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                      pEnvironment->iRelObjNr : ObjNumber_t defined in Rte_type.h,      [ 0 ... EM_N_OBJECTS-1s]
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve : curvature value of considered trajectory   [-1 … +1] m^-1
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity                  [-330.f ... 330.f] m/s
  @glob_in         SLATE_f_GetSensorYPosition() : Sensor mounting lateral position.[-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         SLATE_f_GetSITCycleTime() : Task cycle time.                     [0.f ... 1.f] s
  @glob_out        -

  @c_switch_part   LA_CFG_LIMIT_CURVE_INNER_BORDER_EXT : Limit the inner curve border extension based on the curvature of the course and the position of the object
  @c_switch_part   LA_EXTENDED_CURVEINNERBORDER_CRITERION : Configuration switch to enable extended CurveInnerBorder criterion
  @c_switch_part   LA_EXTENDED_CURVEINNERBORDER_CRITERION_WEAKER : Configuration switch for not applying wide bracket criteria in case of steering gradient is leading out of curve and there is another lane available
                   
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/10/2016
  @changed         2/10/2016

  @author          R.Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraExtensionCurveInnerBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut )
{
  /*--- VARIABLES ---*/
#if (LA_CFG_LIMIT_CURVE_INNER_BORDER_EXT)
  float32 fAngleCurve2Y;
  float32 fLengthObj;
  float32 fDistReflectionMoveDueToCurve;
#endif
  float32 fExtensionFoV;
  #if(LA_CFG_CURVE_INNER_BORDER_EXT_DIST_TO_TRAJ)
    float32 fDistToTraj_loc;
    float32 f_ObjLongDisp ;
    fDistToTraj_loc = pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
    f_ObjLongDisp      = *(pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr));
  #endif
  if( pEnvironment->iRelObjNr == pObjInput->iObjNr ) 
  {
#if (LA_CFG_LIMIT_CURVE_INNER_BORDER_EXT)
    /*! Angle between the slope at the curve (at the position of the object) and the y-axis */
    fAngleCurve2Y = ATAN2_((pRelTraCurve->dCurve * pObjInput->dAbst_mittel), 1.f);
    /*! Length of object (depending on the object class) */
    fLengthObj = (pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].fObjectLength);
    /*! Estimation of how far the reflection point moves due to the refection from the side */
    fDistReflectionMoveDueToCurve = LA_PERC_LENGTH_REFLECTION_INNER_CURVE_EXT * COS_(fAngleCurve2Y) * fLengthObj;
#endif

    /*! In case of a right curve */
#if (LA_EXTENDED_CURVEINNERBORDER_CRITERION == 1)
    if(  (pRelTraCurve->dCurve < -LA_ECIBO_MAX_CURVE )
#if (LA_EXTENDED_CURVEINNERBORDER_CRITERION_WEAKER)
       &&( (EGO_CURVE_GRAD_OBJ_SYNC < LA_ECIBO_MAX_CURVE_GRADIENT ) || (pEnvironment->iNumberLanesRight <= LA_ECIBO_MAX_NB_LANES) )
#endif
       &&(pObjInput->dAbst_mittel < LA_ECIBO_MAX_DISTX) 
       &&(*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_ECIBO_MAX_VELOCITY) ) 
    {
      /*! Use a wider angle */
      fExtensionFoV = ((pObjInput->dAbst_mittel * TAN_(DEG2RAD(-LA_ECIBO_MAX_EXTENTIONANGLE_TAN))) + SLATE_f_GetSensorYPosition());
    }
    else
    {
      /*! Use the far range angle only */
      fExtensionFoV = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_RANGE_ONLY_RIGHT);
    }
#else
    /*! Right border of the FoV */
    fExtensionFoV = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_AND_NEAR_RANGE_RIGHT);
#endif

    /*! Right curve: If curvature higher than a threshold */
    if( pRelTraCurve->dCurve < - LA_MIN_CURVE_INNER_CURVE_EXT )
    {
      /*! Open trace bracket to the border of the FoV (with filter) */
      if( fExtensionFoV < pObjInput->dAblageSpurGrenzeR )
      {
        float32 fFilterTimeConst = 0.0f;
        float32 f_SIT_CycleTime = SLATE_f_GetSITCycleTime();
        if( f_SIT_CycleTime > C_F32_DELTA )
        {
          fFilterTimeConst = (LA_TIMECONST_INNER_CURVE_EXT /SLATE_f_GetSITCycleTime());
        }
        fExtensionFoV = GDB_FILTER (fExtensionFoV, pObjInput->dAblageSpurGrenzeR, fFilterTimeConst);
      }

#if (LA_CFG_LIMIT_CURVE_INNER_BORDER_EXT)
      /*! If not steering (EGO_DRV_INT_CURVE_GRAD_RAW) clearly in the other direction of the curvature, 
          apply trace bracket extension */
      if (EGO_DRV_INT_CURVE_GRAD_RAW < - EGO_DRV_INT_CURVE_RAW)
      {
        /*! Set right trace bracket: Minimum of border to FoV and estimation of moved reflection point due to curve */
        pBracketOut->BracketPositionRight = MAX_FLOAT((pObjInput->dAblage_m - fDistReflectionMoveDueToCurve), fExtensionFoV);
      }
#else
      /*! Set right trace bracket */
  #if(LA_CFG_CURVE_INNER_BORDER_EXT_DIST_TO_TRAJ)
      if (((fDistToTraj_loc > LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MIN) 
        && (fDistToTraj_loc < LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MAX_LEFT))
        && (f_ObjLongDisp > LA_CURVE_INNER_EXT_LONG_DIST_MIN))
      {
        pBracketOut->BracketPositionLeft = -fExtensionFoV;
      }
      else
      {
  #endif
        pBracketOut->BracketPositionRight = fExtensionFoV;
  #if(LA_CFG_CURVE_INNER_BORDER_EXT_DIST_TO_TRAJ)
      }
  #endif

#endif
    }

    /*! In case of a left curve */
#if (LA_EXTENDED_CURVEINNERBORDER_CRITERION == 1)
    if(  (pRelTraCurve->dCurve > LA_ECIBO_MAX_CURVE )
#if (LA_EXTENDED_CURVEINNERBORDER_CRITERION_WEAKER)
       &&( (EGO_CURVE_GRAD_OBJ_SYNC >  (- LA_ECIBO_MAX_CURVE_GRADIENT) ) || (pEnvironment->iNumberLanesLeft <= LA_ECIBO_MAX_NB_LANES) )
#endif
       &&(pObjInput->dAbst_mittel < LA_ECIBO_MAX_DISTX) 
       &&(*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_ECIBO_MAX_VELOCITY) ) 
    {
      /*! Use a wider angle */
      fExtensionFoV = ((pObjInput->dAbst_mittel * TAN_(DEG2RAD(LA_ECIBO_MAX_EXTENTIONANGLE_TAN))) + SLATE_f_GetSensorYPosition());
    }
    else
    {
      /*! Use the far range angle only */
      fExtensionFoV = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_RANGE_ONLY_LEFT);
    }
#else
    /*! Left border of the FoV */
    fExtensionFoV = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_AND_NEAR_RANGE_LEFT);
#endif

     /*! Left curve: If curvature higher than a threshold */
    if( pRelTraCurve->dCurve > LA_MIN_CURVE_INNER_CURVE_EXT )
    {
      /*! Open trace bracket to the border of the FoV (with filter) */
      if( fExtensionFoV > pObjInput->dAblageSpurGrenzeL )
      {
        float32 fFilterTimeConst = 0.0f;
        float32 fSITCyclTime = SLATE_f_GetSITCycleTime();
        if( fSITCyclTime > C_F32_DELTA )
        {
          fFilterTimeConst = (LA_TIMECONST_INNER_CURVE_EXT /SLATE_f_GetSITCycleTime());
        }
        fExtensionFoV = GDB_FILTER (fExtensionFoV, pObjInput->dAblageSpurGrenzeL, fFilterTimeConst);
      }
      
#if (LA_CFG_LIMIT_CURVE_INNER_BORDER_EXT)
      /*! If not steering (EGO_DRV_INT_CURVE_GRAD_RAW) clearly in the other direction of the curvature, 
          apply trace bracket extension */
      if (EGO_DRV_INT_CURVE_GRAD_RAW > - EGO_DRV_INT_CURVE_RAW)
      {
        /*! Set left trace bracket: Minimum of border to FoV and estimation of moved reflection point due to curve */
        pBracketOut->BracketPositionLeft = MIN_FLOAT((pObjInput->dAblage_m + fDistReflectionMoveDueToCurve), fExtensionFoV);
      }
#else
  #if(LA_CFG_CURVE_INNER_BORDER_EXT_DIST_TO_TRAJ)
      if (((fDistToTraj_loc < LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MIN) 
        && (fDistToTraj_loc > LA_CURVE_INNER_EXT_DIST_TO_TRAJ_MAX_RIGHT)) 
        && (f_ObjLongDisp > LA_CURVE_INNER_EXT_LONG_DIST_MIN))
      {
        pBracketOut->BracketPositionRight = -fExtensionFoV;
      }
      else 
      {
  #endif
        pBracketOut->BracketPositionLeft = fExtensionFoV;
  #if(LA_CFG_CURVE_INNER_BORDER_EXT_DIST_TO_TRAJ)
      }
  #endif

#endif
    }
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionRoadBorderCI                                                                    */ /*!

  @brief           Extension of road border on left or right

  @description     Opening the right lane edge for maximum coverage for right and ditto on left curve
                   left margin, depending on the existing lanes,camera outlane condition and lane change Phase state.

				   @startuml
				   Partition LA_v_RelTraExtensionRoadBorderCI{
				   Start
				   If (Object is Relevant) then (TRUE)
				   If (Curvature is low) then (TRUE)
				   : Get Bracket position for right;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dAbst_mittel           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dVrel_mittel           [-330.f ... 330.f] m/s
                      pObjInput->iRelevant              [ubit8_t defined in algo_type.h] [TRUE,FALSE]
  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesRight   [-1 ... 20]
                      pEnvironment->iNumberLanesLeft    [-1 ... 20]
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve : curvature value of considered trajectory              [-1 … +1] m^-1
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity   [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState : Ego Lane change phase [0 .. 2]
  @glob_out        -

  @c_switch_part   -                   
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE : Configuration switch to check camera outlane and lane change
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT switch for camera object/lane detection inputs
  @c_switch_part   FCT_CFG_ACC_SITUATION : FCT switch for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/10/2016
  @changed         2/10/2016

  @author          R.Ehrhardt 
*************************************************************************************************************************/
static void LA_v_RelTraExtensionRoadBorderCI(LA_t_RelTraObjInput const *pObjInput, LA_t_AssTraEnvironment const *pEnvironment, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut )
{
#if (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  boolean b_CheckCameraObjAssoToOutLane = FALSE;
#endif /* (FCT_CFG_CAMERA_OBJECT_DETECTION) */ 
#endif /* (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE) */
  if( pObjInput->iRelevant == (ubit8_t)TRUE )
  {
    const float32 f_ABS_dVrel_mittel = fABS(pObjInput->dVrel_mittel);
    if(  (f_ABS_dVrel_mittel < LA_MIN_OWV_VREL)
      || (pObjInput->dAbst_mittel > LA_MIN_ABST_VREL )
      || ((*pt_LAInput->t_RTE.pf_EgoVelObjSync + pObjInput->dVrel_mittel) > LA_MIN_OWV_VEIGEN)
      )
    {
#if (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
      b_CheckCameraObjAssoToOutLane = LA_b_CheckCameraObjAssoToOutLane(pObjInput->iObjNr);
#endif /* (FCT_CFG_CAMERA_OBJECT_DETECTION) */
#endif /* (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE) */	  
      /* Oeffnen des rechten Spurrandes zum max. Erfassungsbereichs bei */
      /* Rechtskurve */

      if( pRelTraCurve->dCurve < -LA_FSZ_A2_RICHTUNGSFAHRSPUREN_KI )
      {
        if(   ( pEnvironment->iNumberLanesRight == 0L )
#if (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
           && (b_CheckCameraObjAssoToOutLane == FALSE)
#endif /* (FCT_CFG_CAMERA_OBJECT_DETECTION) */
#if (FCT_CFG_ACC_SITUATION)
           && (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState != LC_LEFT)
#endif /* (FCT_CFG_ACC_SITUATION) */
#endif /* (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE) */
          )
        {
          /* Spurklammerposition schreiben !!! - TPGetSensorYPosition because we are not autosar here !!! */
          /*! Right border of the FoV */
          pBracketOut->BracketPositionRight = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_AND_NEAR_RANGE_RIGHT);
        }
      }

      /* dito bei Linkskurve */

      if( pRelTraCurve->dCurve > LA_FSZ_A2_RICHTUNGSFAHRSPUREN_KI )
      {
        if(   ( pEnvironment->iNumberLanesLeft == 0L ) 
#if (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
           && (b_CheckCameraObjAssoToOutLane == FALSE)
#endif /* (FCT_CFG_CAMERA_OBJECT_DETECTION) */
#if (FCT_CFG_ACC_SITUATION)
           && (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState != LC_RIGHT)
#endif /* (FCT_CFG_ACC_SITUATION) */
#endif /* (LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE) */
          )
        {
          /* Spurklammerposition schreiben */
          /*! Left border of the FoV */
          pBracketOut->BracketPositionLeft = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_AND_NEAR_RANGE_LEFT);
        }
      }
    }
    else
    {
      /* keine Aktion */
    }
  }
}

// PRQA S 7004 CYCLOMETRIC_COMPLEXITY

/*************************************************************************************************************************
  Functionname:    LA_v_RelCheckOWV                                                                                    */ /*!

  @brief           Checks if an object should be further followed

  @description     Checks if an object should be further followed. This depends on
                   the object angle and the trace movement. Essentially, a lane
                   departure is estimated and a counter is set.

				   @startuml
				   Partition LA_v_RelCheckOWV{
				   Start
				   : Initialize lanes, Trace, Curvature gradient, Angle, Probability;
				   If (Flag is Active) then (TRUE)
				   If (Object is not relevant)
				   : Set Folge;
				   Else (FALSE)
				   : Check trace criterion;
				   If (Trace crit is valid) then (TRUE)
				   : Movement to the right;
				   Else (FALSE)
				   : Movement to the left;
				   Endif
				   : if ego lane change based on lane change probability or\n lane change direction in FIP lane matrix;
				   Endif
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dAbst_mittel         [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dVrel_mittel         [-330.f ... 330.f] m/s
                      pObjInput->iRelevant            [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track lane width depending on time and distance [0.0f ... 1.0f]
                      pObjInput->iObjectLifeCycles    [AlgoCycleCounter_t (unsigned short) defined in Rte_type.h]
                      pObjInput->dAblage_m            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dAblage_Radius       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->iObjNr               [ObjNumber_t defined in Rte_type.h][ 0 ... EM_N_OBJECTS-1s]
                      pObjInput->dWinkel_mittel       [-PI … +PI] rad
                      pObjInput->dWinkel_m_abs        [-PI … +PI] rad

  @param[in,out]   pObjOutput : Pointer to an LA_t_RelTraObjOutput type structure.  Output information about the object. Defined in la_corridor_crit.h
                      pObjOutput->dAblage_SpurGrenze_L : Maximal allowed deviation to left from ideal trajectory,    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjOutput->dAblage_SpurGrenze_R : Maximal allowed deviation to right from ideal trajectory,   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjOutput->iLwFolge                                                                           [full range sint32]
  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesRight  [-1 ... 20]
                      pEnvironment->iNumberLanesLeft   [-1 ... 20]
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, describes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve : Curvature of considered trajectory                           [-1 … +1] m^-1
                      pRelTraCurve->iOWVflag : Flag describing which trajectory hypothesis is considered  [ 0 or 1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity  [-330.f ... 330.f] m/s
  @glob_in         CP_CourseData : structure of type CPCourseData_t, describes the Course.Defined in si_main.c.
                      CP_CourseData.fCurveGradient       [-1 … +1] m^-2
  @glob_in         SLATE_f_GetLobeAngle() :                         [-PI … +PI] rad
  @glob_out        -

  @c_switch_part   LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES : Configuration switch for enabling optimized country road hold performance for preventing drop-outs on country roads
  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/10/2016
  @changed         2/10/2016

  @author          R.Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelCheckOWV(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraObjOutput *pObjOutput, LA_t_AssTraEnvironment const * pEnvironment, LA_t_RelTraCurve const *pRelTraCurve )
{
  /*--- VARIABLES ---*/  
  float32 dSpurGradHalten;
  float32 dAbweichung = 0.f;
  float32 f_OWV_SPURGRAD_WINKEL_MAX;
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
  sint32 iNumLanes;
#endif
  boolean bTraceCrit = FALSE;
  float32 fABS_pObjInput_dVrel_mittel;
  const float32 f_CourseCurveGradient = *(pt_LAInput->t_CP.pf_CourseCurveGradient);
  const float32 f_LobeAngle = SLATE_f_GetLobeAngle();
  const uint8 u_LCProb = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb; /*!< Lane change probability */

  /* LA_OWVKRIT_AKTIV is only set for the trajectory calculation with */
  /* CP_TrajectoryData. It is not recalculated for the VDY-only trajectory. */
  if (pRelTraCurve->iOWVflag == LA_OWVKRIT_AKTIV)
  {
    if( pObjInput->iRelevant != (ubit8_t)TRUE )
    {
      /* Ruecksetzen der iLwFolge */
      pObjOutput->iLwFolge = 0;      
    }
    else
    {

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
      const SITLaneChangeCamPreMove_t t_LaneChangeMovePreState = *(pt_LAInput->t_SIT.pt_SITLaneChangeCamPreMoveState); /*!< Lane change direction based on FIP lane matrix */
#endif

      /* Objektwinkel und Spurvektor haben gleiche Bewegungsrichtung */
      /* Erweitern der Spurbreite in Bewegungsrichtung bis zum max. Erfassungsbereich */
      fABS_pObjInput_dVrel_mittel = fABS(pObjInput->dVrel_mittel);
      if( ( pObjInput->dRelSpurErweiterungsFaktor >= (1.F - C_F32_DELTA) )
        ||( pObjInput->iObjectLifeCycles          >= LA_OWV_OBJLEB ))
      {
        if( ( pObjInput->dAbst_mittel < LA_MAX_ABSTSTEIG )
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
          && (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_MIN_OWV_VEIGEN)
#else
          &&( pObjInput->dAbst_mittel > LA_MIN_ABSTSTEIG )
#endif
          &&(  (fABS_pObjInput_dVrel_mittel < LA_MIN_OWV_VREL)
          || (pObjInput->dAbst_mittel > LA_MIN_ABST_VREL )
#if (!LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
          || ((*pt_LAInput->t_RTE.pf_EgoVelObjSync + pObjInput->dVrel_mittel) > LA_MIN_OWV_VEIGEN)
#endif
          )
          )
        {
          dAbweichung = (pObjInput->dAblage_m - pObjInput->dAblage_Radius);

          /* Check trace criterion */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
          bTraceCrit = LA_b_CheckTraceCriterion(pObjInput->iObjNr);
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
          if (bTraceCrit != FALSE)
          {
            if( dAbweichung < 0.F )
            {
              /* Movement to the right */
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
              iNumLanes = pEnvironment->iNumberLanesRight;  /* Eqvivalent to EOGetLaneMatrixLaneNumberRight(&iNumLanes); */
#endif
              /* Check the OWV (follow object into curve/objekt weiter verfolgen) for following the object into right curve */
              if( (  ( f_CourseCurveGradient < -LA_MIN_SPURSTEIG )
                && ( pObjInput->dWinkel_mittel  > -( f_LobeAngle - C_F32_DELTA ) )
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
                && ( pObjInput->dAbst_mittel > LA_MIN_ABSTSTEIG ) )
                || ( ( (iNumLanes <= 0) || (pObjOutput->iLwFolge > 0))                                            /*!< No lane, or unknown number of lanes on the given side */
                && (f_CourseCurveGradient < 0.f)                              /*!< Driver steering towards object */
                && (fABS_pObjInput_dVrel_mittel < (LA_MAX_OWV_VREL_TRACE_CRIT))  /*!< Object's relative speed not too large */
                && (dAbweichung > -LA_MAX_TRACE_LAT_DISPLACEMENT) )             /*!< Object not too far away from predicted course */
#else
                )
#endif
                )
              {

                /* Objekt und Kruemmung wandern nach rechts */
                pObjOutput->iLwFolge = LA_MAX_HALTEZEIT;
              }
            }
            else
            {
              /* Movement to the left */
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
              iNumLanes = pEnvironment->iNumberLanesLeft; /* Eqvivalent of EOGetLaneMatrixLaneNumberLeft(&iNumLanes); */
#endif
              /* Ueberpruefung der OWV-Kriterien fuer Halten eines Objekts bei Bewegung nach nach links */
              if( (  ( f_CourseCurveGradient > LA_MIN_SPURSTEIG )
                && ( pObjInput->dWinkel_mittel  < ( f_LobeAngle - C_F32_DELTA ) )
#if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
                && ( pObjInput->dAbst_mittel > LA_MIN_ABSTSTEIG ) )
                || ( ( (iNumLanes <= 0) || (pObjOutput->iLwFolge < 0))                                            /*!< No lane, or unknown number of lanes on the given side */
                && (f_CourseCurveGradient > 0.f)                              /*!< Driver steering towards object */
                && (fABS_pObjInput_dVrel_mittel < (LA_MAX_OWV_VREL_TRACE_CRIT))  /*!< Object's relative speed not too large */
                && (dAbweichung < LA_MAX_TRACE_LAT_DISPLACEMENT) )              /*!< Object not too far away from predicted course */
#else
                )
#endif
                )
              {

                /* Objekt und Kruemmung wandern nach links */
                pObjOutput->iLwFolge = -LA_MAX_HALTEZEIT;
              }
            }
          }

          /* Check if ego lane change based on lane change probability or lane change direction in FIP lane matrix */
          if((((u_LCProb) > (LA_MIN_LC_PROB_FOLLOW_OBJ_INTO_CURVE))
            &&((pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase) != (LC_STEERBACK)))
              
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
            || (t_LaneChangeMovePreState != LANE_CHANGE_CAM_PRE_MOVE_NO)
#endif
            )
          {
            /* Bei Fahrspurwechsel kein OWV ausloesen */
            pObjOutput->iLwFolge = 0L;
          }

          /* Schwellwert fuer SpurGradienten festlegen */
          f_OWV_SPURGRAD_WINKEL_MAX = LA_OWV_SPURGRAD_WINKEL_MAX;

          if (pObjInput->dWinkel_m_abs > f_OWV_SPURGRAD_WINKEL_MAX)
          {
            dSpurGradHalten = LA_OWV_SPURGRAD_MIN_HALTEN_MAXWINKEL;
          }
          else
          {
            dSpurGradHalten = dGDBmathLineareFunktion(&LA_SpurGradHaltenKruemmung, fABS(*(pt_LAInput->t_CP.pf_CourseCurve)));
          }

          /* Objektverfolgung nach rechts, iLwFolge verarbeiten */

          if( pObjOutput->iLwFolge > 0L )
          {
            /* unter folgenden Bedingungen wird heruntergezaehlt */
            if(  ( *(pt_LAInput->t_CP.pf_CourseCurveGradient) > dSpurGradHalten )
              || ( dAbweichung       > -LA_MIN_SPURABWEICH )
              || ( dAbweichung       < -LA_MAX_SPURABWEICH )
              )
            {
              pObjOutput->iLwFolge--;
            }
          }

          /* Objektverfolgung nach links, iLwFolge verarbeiten */

          if( pObjOutput->iLwFolge < 0L )
          {
            /* unter folgenden Bedingungen wird heruntergezaehlt */
            if(  ( *(pt_LAInput->t_CP.pf_CourseCurveGradient) < -dSpurGradHalten )
              || ( dAbweichung       < LA_MIN_SPURABWEICH )
              || ( dAbweichung       > LA_MAX_SPURABWEICH )
              )
            {
              pObjOutput->iLwFolge++;
            }
          }

        }
        else
        {
          pObjOutput->iLwFolge = 0;
        }
      }
    }
  }
  else
  {
    _PARAM_UNUSED(pEnvironment);
    _PARAM_UNUSED(pRelTraCurve);
    _PARAM_UNUSED(dAbweichung);
  }
}
// PRQA L:CYCLOMETRIC_COMPLEXITY 

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionFollowObjectIntoCurve                                                           */ /*!

  @brief           Extend trace brackets to follow object into a curve

  @description     Object angle and trace vector have the same direction
                   of movement. Thus, extend the trace brackets to the direction
                   of movement to the maximum field-of-view.

				   @startuml
				   Partition LA_v_RelTraExtensionFollowObjectIntoCurve{
				   Start
				   If (Flag is Active) then (TRUE)
				   If (Object is relevant)
				   : Get Vrel mittel;
				   If (Extension factor OR ObjectLife Cycle is high) then (TRUE)
				   If (Object tracking to right) then (TRUE)
				   : Use the far range angle only;
				   : Get Brachet Position for right;
				   Else (FALSE)
				   Endif
				   If (Object tracking to left) then (TRUE)
				   : Use the far range angle only;
				   : Get Brachet Position for left;
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   Else (FALSE)
				   Endif
				   End
				   }
				   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->iRelevant             [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dAbst_mittel          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dVrel_mittel          [-330.f ... 330.f] m/s
                      pObjInput->dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track lane width depending on time and distance : [0.0f ... 1.0f]
                      pObjInput->dAblage_Radius        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->iObjectLifeCycles     [AlgoCycleCounter_t (unsigned short) defined in Rte_type.h]
  @param[in]       pObjOutput : Pointer to an LA_t_RelTraObjOutput type structure.  Output information about the object. Defined in la_corridor_crit.h
                      pObjOutput->iLwFolge             [full range sint32]
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, describes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->iOWVflag : Flag describing which trajectory hypothesis is considered [ 0 or 1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES : Configuration switch for enabling optimized country road hold performance
                   for preventing drop-outs on country roads
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/11/2016
  @changed         2/11/2016

  @author          R.Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraExtensionFollowObjectIntoCurve(LA_t_RelTraObjInput const *pObjInput, const LA_t_RelTraObjOutput *pObjOutput, LA_t_BracketOutput *pBracketOut, LA_t_RelTraCurve const *pRelTraCurve )
{
  /*--- VARIABLES ---*/
  float32 dAblage_MaxWinkel;
  float32 fABS_pObjInput_dVrel_mittel;

  if (pRelTraCurve->iOWVflag == LA_OWVKRIT_AKTIV)
  {
    if( pObjInput->iRelevant == (ubit8_t)TRUE )
    {    

      /* Objektwinkel und Spurvektor haben gleiche Bewegungsrichtung */
      /* Erweitern der Spurbreite in Bewegungsrichtung bis zum max. Erfassungsbereich */
      fABS_pObjInput_dVrel_mittel = fABS(pObjInput->dVrel_mittel);

      if( ( pObjInput->dRelSpurErweiterungsFaktor >= (1.F - C_F32_DELTA) )
        ||( pObjInput->iObjectLifeCycles          >= LA_OWV_OBJLEB ))
      {
        if( ( pObjInput->dAbst_mittel < LA_MAX_ABSTSTEIG )
    #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
          && (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_MIN_OWV_VEIGEN)
    #else
          &&( pObjInput->dAbst_mittel > LA_MIN_ABSTSTEIG )
    #endif
          &&(  (fABS_pObjInput_dVrel_mittel < LA_MIN_OWV_VREL)
            || (pObjInput->dAbst_mittel > LA_MIN_ABST_VREL )
    #if (!LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
            || ((*pt_LAInput->t_RTE.pf_EgoVelObjSync + pObjInput->dVrel_mittel) > LA_MIN_OWV_VEIGEN)
    #endif
            )
          )
        {

          /* Objektverfolgung nach rechts, iLwFolge verarbeiten */
          if( pObjOutput->iLwFolge > 0L )
          {

            /* Max. Oeffnungsbreiten links und rechts bei analoger Winkelmessung */
            /* Use the far range anlge only */
            dAblage_MaxWinkel = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_RANGE_ONLY_RIGHT);

            /* Spurklammerposition schreiben */
            #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
                pBracketOut->BracketPositionRight = MAX_FLOAT((pObjInput->dAblage_Radius - LA_MAX_OVW_ABLAGE), dAblage_MaxWinkel);
            #else
                pBracketOut->BracketPositionRight = dAblage_MaxWinkel;
            #endif
          }

          /* Objektverfolgung nach links, iLwFolge verarbeiten */
          if( pObjOutput->iLwFolge < 0L )
          {

            /* Max. Oeffnungsbreiten links und rechts bei analoger Winkelmessung */
            /* Use the far range anlge only */
            dAblage_MaxWinkel = LA_f_RelTraGetYDistFOVAtXDist(pObjInput->dAbst_mittel,LA_FAR_RANGE_ONLY_LEFT);
            /* Spurklammerposition schreiben */
            #if (LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES)
                pBracketOut->BracketPositionLeft = MIN_FLOAT((pObjInput->dAblage_Radius + LA_MAX_OVW_ABLAGE), dAblage_MaxWinkel);
            #else
                pBracketOut->BracketPositionLeft = dAblage_MaxWinkel;
            #endif

          }

        }
      }
    }
  }
}
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    LA_b_CheckTraceCriterion                                                                            */ /*!

  @brief           Check object's trace

  @description     Check object's trace's predicted Y axis intersection to see if
                   it is deemed in-lane by normal inlap logic. If it is, then
                   the function returns true.

				   @startuml
				   Partition LA_b_CheckTraceCriterion{
				   Start
				   : Initialize Bracket Intersection Offset;
				   : Get Trace Borders;
				   : calculate offset for trace bracket;
				   : Offset the base trace bracket;
				   If (Inlap is more than Threshold) then (TRUE)
				   : object has a trace;
				   Else (FALSE)
				   : object has a no trace;
				   Endif
				   End
				   }
				   @enduml

  @return          static boolean : TRUE if object has a trace and the predicted Y intersection and
                   it's variance is small enough for inlap values calculated to deem this point 'in-lane'.

  @param[in]       iObj : index of the object of type signed char  [ 0 ... EM_N_OBJECTS-1s]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity             [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/15/2016
  @changed         2/15/2016

  @author          Norman Apel | norman.apel@continental-corporation.com | +49-(8382)-9699-365
*************************************************************************************************************************/
static boolean LA_b_CheckTraceCriterion(const ObjNumber_t iObj)
{
  LADistanceWidth_t DistWidth;
  LA_t_TrajInlap TrajInlap;
  LA_t_BracketOutput BracketPosition;
  float32 f_BracketYIntersectionOffset = 0.0f;
  boolean ret;

  LA_v_CalculateTraceBorders( iObj , &DistWidth);

/* For shapepoint based calculation, calculate offset for trace bracket, which is difference between Y coordinate of Object's rear edge 
   and predicted y intersection of traces. Use this offset to adjust trace bracket while calculating Inlap using shapepoints */ 
  f_BracketYIntersectionOffset = *SLATE_pf_GetObjLatDisp(iObj) - fABS(DistWidth.fDistance);

 /* Offset the base trace bracket */
  BracketPosition.BracketPositionLeft  = DistWidth.fTrajectoryWidth * 0.5f + f_BracketYIntersectionOffset;
  BracketPosition.BracketPositionRight = DistWidth.fTrajectoryWidth * (-0.5f) + f_BracketYIntersectionOffset;
  LA_v_CalculateInlap(iObj, &DistWidth, BracketPosition.BracketPositionLeft, BracketPosition.BracketPositionRight, &TrajInlap);

  if( TrajInlap.fInlap > LA_TRACE_INLAP_PICKUP_THRES )
  {
    ret = TRUE;
  }
  else
  {
    ret = FALSE;
  }
  return ret;
}


/*************************************************************************************************************************
  Functionname:    LA_v_CalculateTraceBorders                                                                          */ /*!

  @brief           Calculate trace borders and lane seek width for given object

  @description     Using the predicted Y axis intersection point of the object's
                   trace (if it has one), and it's variance fill the struct
                   pointed to by pDistanceWidth.

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

					  @startuml
					  Partition LA_v_CalculateTraceBorders{
					  Start
					  : Get Object trace, width of the object,\n variance width of the object;
					  If (Object trace is less than Number of traces) then (TRUE)
					  : Get Distance between center of the corridor and\n the center of the object and its variance;
					  Else (FALSE)
					  : Initialization Distance between center of the corridor and\n the center of the object and its variance;
					  Endif
					  : Get Trajectory Width and Trajectory Width variance;
					  End
					  }
					  @enduml

  @return          static void

  @param[in]       iObj : index of the object of type signed char [0....39]
  @param[in,out]   pDistanceWidth : Pointer to the structure of type "LADistanceWidth_t", Distance and Width information of the object of type. Defined in cp_ext.h  
                     pDistanceWidth->fObjectWidth : width of the object based on the object classification.           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     For Example,  Car    : SI_OBJ_WIDTH_CAR_MOVE [ Defined in la_par.h]
                                   truck  : SI_OBJ_WIDTH_TRUCK    [ Defined in la_par.h]
                     pDistanceWidth->fObjectWidthVar : variance of fObjectWidth.                                      [full range of data type float32]
                     pDistanceWidth->fDistance : Distance between center of the corridor and the center of the object.[-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pDistanceWidth->fDistanceVar : Variance of fDistance.                                            [full range of data type float32]
                     pDistanceWidth->fTrajectoryWidth : width of the object's Corridor.                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pDistanceWidth->fTrajectoryWidthVar : Variance of fTrajectoryWidth.                              [full range of data type float32]

  @glob_in         SLATE_f_GetEGOVehicleWidth() : Width of Ego vehicle                                                           [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(iObjTrace)->Legacy.YPredictedIntersec(iObjTrace) :    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(iObjTrace)->Legacy.YPredictedIntersecVar :            [full range of data type float32]
  @glob_in         ptLAOutput->f_LA_SeekLaneWidth : global seek lane width variable                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             LA_v_CalculateBaseLaneWidths has to be calculated for pt_LAOutput->f_LA_SeekLaneWidth
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/15/2016
  @changed         2/15/2016
  
  @todo            Replace FIP direct access function through LA Input

  @author          Norman Apel | norman.apel@continental-corporation.com | +49-(8382)-9699-365
*************************************************************************************************************************/
static void LA_v_CalculateTraceBorders(const ObjNumber_t iObj , LADistanceWidth_t * pDistanceWidth)
{
  const TraceID_t iObjTrace = *(pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID(iObj));

  pDistanceWidth->fObjectWidth       = (pt_LAInput->pt_FIPOA->t_ObjList[iObj].f_ObjectWidthCorridor);
  pDistanceWidth->fObjectWidthVar    = 0.0f;

  if (iObjTrace < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES)
  {
    pDistanceWidth->fDistance     = pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[iObjTrace].Legacy.YPredictedIntersec;
    pDistanceWidth->fDistanceVar  = pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[iObjTrace].Legacy.YPredictedIntersecVar;
  }
  else
  {
    pDistanceWidth->fDistance     = INITVALUE_BRACKETPOSITION;
    pDistanceWidth->fDistanceVar  = INITVALUE_BRACKETPOSITION;
  }
  pDistanceWidth->fTrajectoryWidth    = pt_LAOutput->f_LA_SeekLaneWidth;
  pDistanceWidth->fTrajectoryWidthVar = 0.0f;
}
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
/*************************************************************************************************************************
  Functionname:    LA_f_RelTraGetYDistFOVAtXDist                                                                       */ /*!

  @brief           Get field of view lateral position at a given X distance

  @description     Get field of view lateral position at a given X distance. 
                   If only the far scan or if the near scan and the far scan in considered, 
                   can be set via an input variable.
                   Note: uses corresponding near/far scan tangents, depending on the X distance.

				   @startuml
				   Partition LA_f_RelTraGetYDistFOVAtXDist{
				   Start
				   : Initialize FOV angle;
				   If (FOV type is only left side OR far range left) then (TRUE)
				   If (FOV type is only left side OR Distance is more than\n trace bracket extension angle) then (TRUE)
				   : Get FOV angle;
				   Else (FALSE)
				   : Use near range angle;
				   Endif
				   Else (FALSE)
				   If (FOV type is only right side OR Distance is more than\n trace bracket extension angle) then (TRUE)
				   : Get FOV angle;
				   Else (FALSE)
				   : Use near range angle;
				   Endif
				   Endif
				   : Calculate tangents of FOV angle;
				   End
				   }
				   @enduml

  @return          static float32

  @param[in]       f_DistX : The positive X distance to get the field of view left lateral position     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       t_FOVType : Enum type to describe which FOV to use.                                  [of type LA_t_CorrFOVTypeExtension, defined in si_corridor_radarroad.c]

  @glob_in         SLATE_f_GetSensorYPosition() : Sensor mounting lateral position.                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : configuration switch for enabling road border criteria.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/15/2016
  @changed         2/15/2016

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
static float32 LA_f_RelTraGetYDistFOVAtXDist(float32 f_DistX, LA_t_CorrFOVTypeExtension t_FOVType)
{
  float32 f_BeamTan;
  float32 f_AngleFOV = 0.f; /* Initialize FOV angle */

  /* Set FOV angle based on FOV type input parameter and given x-distance */
  /* Fist, consider left side of FOV */
  if( (t_FOVType == LA_FAR_RANGE_ONLY_LEFT) || (t_FOVType == LA_FAR_AND_NEAR_RANGE_LEFT) )
  {
    /* If only the far range should be considered or if the x distance is higher than a threshold,
      consider the far range FOV angle */
    if((t_FOVType == LA_FAR_RANGE_ONLY_LEFT) || (f_DistX > LA_DISTX_FAR_RANGE_ANGLE_TB_EXT))
    {
      f_AngleFOV = SLATE_f_GetMaxCoverageAngle();
    }
    else
    {
      /* Use near range angle */
      f_AngleFOV = LA_ANGLE_NEAR_RANGE_TB_EXT;
    }
  } /* Then consider right side of FOV */
  else /* if( (t_FOVType == LA_FAR_RANGE_ONLY_RIGHT) || (t_FOVType == LA_FAR_AND_NEAR_RANGE_RIGHT) ) */
  {
    /* If only the far range should be considered or if the x distance is higher than a threshold,
      consider the far range FOV angle */
    if((t_FOVType == LA_FAR_RANGE_ONLY_RIGHT) || (f_DistX > LA_DISTX_FAR_RANGE_ANGLE_TB_EXT))
    {
      f_AngleFOV = -SLATE_f_GetMaxCoverageAngle();
    }
    else
    {
      /* Use near range angle */
      f_AngleFOV = -LA_ANGLE_NEAR_RANGE_TB_EXT;
    }
  }
  
  /* Calculate tangents of FOV angle */
  f_BeamTan = TAN_(DEG2RAD(f_AngleFOV));

  return ((f_DistX * f_BeamTan) + SLATE_f_GetSensorYPosition());
}



/** @} end defgroup */
#endif /* END IF (FCT_CFG_ACC_LANE_ASSOCIATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED
