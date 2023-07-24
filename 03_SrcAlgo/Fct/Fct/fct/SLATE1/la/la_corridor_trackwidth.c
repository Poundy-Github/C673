/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_trackwidth.c

DESCRIPTION:               This file implements calculation of final ACC object corridor brackets based 
                           on different trace bracket adaptations calculated in subsidiary files

AUTHOR:                    Norman Apel
                           Gergely Ungvary

CREATION DATE:             15.05.2014

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/



#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)

#include "la_corridor_crit.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_corridor_trackwidth LA Corridor trackwidth
@ingroup la_corridor
@brief          Provides calculation of final ACC object corridor brackets based on different trace bracket adaptations. \n\n

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

#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)
#endif

/*-------------------------------------------------------------------------
| Konstanten zur KA Spurbreiten-Bestimmung                                |
-------------------------------------------------------------------------*/
/* Maximale Reduzierung der Normalen Spurbreite am Kurvenaussenrand bei */
/* Radien kleiner diesem Wert                                           */
#define LA_SB_KA_RADIUS_MIN               (1000.F)
/* Beginnende Reduzierung ab diesem Radius                              */
#define LA_SB_KA_RADIUS_MAX               (2500.F)
/* Naeher diesem Abstand wird keine Reduzierung durchgefuehrt           */
#define LA_SB_KA_ABST_MIN                 (30.F)
/* Ab diesem Abstand volle Reduzierung                                  */
#define LA_SB_KA_ABST_MAX                 (50.F)
#define LA_SB_KA_RADIUS_BREITE            (0.5F)

#define LA_MIN_HALF_SEEK_LANE_WIDTH_STAT     (1.5f)     /*!< Minimum half seek lane width for stationary objects */
#define LA_SCALE_HALF_SEEK_LANE_WIDTH_STAT   (0.9f)     /*!< Scale factor for seek lane width of statinoary objects if stopped confidence low */


/*---------------------------------------------------------------------------
| Konstanten fuer Spurbreiten-Bestimmung aus der Approximation              |
---------------------------------------------------------------------------*/

#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
/* Minimaler Abstand eines Objekts  */
#define LA_SEEK_APPROX_ABSTAND_MIN           (25.F)
/* Erweiterung der Ablage links oder rechts bei         */
/* TrefferOrt 0 und bisheriger ObjektSpur +-1 in Meter  */
#define LA_SEEK_APPROX_ABLAGE_ERWEITERUNG    (1.0F)

/* Neue Approximation ueber Abrollfilter */
#define LA_GENERAL_UR_APPROX_VREL_MIN               (10.F/C_KMH_MS)
#define LA_GENERAL_UR_APPROX_DISTANCE_MAX           (105.F)
#define LA_GENERAL_UR_APPROX_DISTANCE_CRIT          (75.F)
#define LA_GENERAL_UR_APPROX_THRES_MIN              (1.25F)
#define LA_GENERAL_UR_APPROX_THRES_MAX              (1.75F)
#define LA_GENERAL_UR_APPROX_GRADIENT_MAX           (0.0005F)
#define LA_GENERAL_APPROX_MAX_YINTERSEC_GRADIENT    (0.035F)
#define LA_GENERAL_APPROX_PARALLELISM_STD           (0.5F)
#define LA_GENERAL_APPROX_MIN_LANE_EXTENSION_FAC    (0.75f)

/* Ab diesem Abstand ist die Ablage erweitert auf eingestellten */
/* Wert darunter proportional weniger                           */
#define LA_GENERAL_UR_APPROX_ABSTAND_ERW            (1.F/50.F)
#endif

/*-------------------------------------------------------------------------
| Konstanten zur Spurbreiten-Bestimmung aus Umfeld rel. Objekt            |
-------------------------------------------------------------------------*/
#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
/* Konstanten fuer AblageFaktorKruemmung */
/* groesste Erweiterung in m */
#define LA_GENERAL_UR_EXTENSION_MAX          (1.F)
/* kleinste Erweiterung in m */
#define LA_GENERAL_UR_EXTENSION_MIN          (0.4F)
/* Ablage-Schwelle fuer kleinste Erweiterung */
#define LA_GENERAL_UR_EXTENSION_OFFSET_MAX   (1.F)
/* Ablage-Schwelle fuer groesste Erweiterung */
#define LA_GENERAL_UR_EXTENSION_OFFSET_MIN   (0.5F)


/* Konstanten fuer AblageFaktorKruemmung */
#define LA_GENERAL_UR_APPROX_KRUEMMUNG_MAX   (1.0F/1150.F)
#define LA_GENERAL_UR_APPROX_KRUEMMUNG_MIN   (1.0F/1800.F)
#define LA_GENERAL_UR_APPROX_FAKTOR_MIN      (0.4F)
#define LA_GENERAL_UR_APPROX_FAKTOR_MAX      (1.F)
#endif

/*---------------------------------------------------------------------------
| Constants: trace brackets extension based on object scoring |
---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
| Constants: trace brackets extension for a highspeed approach |
---------------------------------------------------------------------------*/
#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
#define LA_TB_EXT_MIN_DIST      (90.0f)
#define LA_TB_EXT_MAX_DIST      (200.0f)
#define LA_TB_EXT_MIN_EXTENSION (1.8f)
#define LA_TB_EXT_MAX_EXTENSION (2.5f)

#define LA_TB_RB_EXT_MIN_NEAR_DIST      (70.0f)
#define LA_TB_RB_EXT_MAX_NEAR_DIST      (140.0f)
#define LA_TB_RB_EXT_MIN_NEAR_EXTENSION (0.0f)
#define LA_TB_RB_EXT_MAX_NEAR_EXTENSION (1.0f)

#define LA_TB_RB_EXT_MIN_DIST      (140.0f)
#define LA_TB_RB_EXT_MAX_DIST      (200.0f)
#define LA_TB_RB_EXT_MIN_EXTENSION (1.0f)
#define LA_TB_RB_EXT_MAX_EXTENSION (2.0f)

#define LA_TB_EXT_MIN_VREL      (1.0f/C_KMH_MS)
#define LA_TB_EXT_MAX_VREL      (-90.f/C_KMH_MS)
#define LA_TB_EXT_MAX_CURVATURE_INNER_LANE  (0.0015f)
/*#define SI_TB_EXT_MAX_GRADIENT  (0.000001f)*/
#endif

/*---------------------------------------------------------------------------
| Constants: trace brackets extension for high tunnel probability
---------------------------------------------------------------------------*/
#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
#define LA_ADD_EXT_TUNNEL_MIN_REL_TIME      (3.0f)
#define LA_ADD_EXT_TUNNEL_MAX_REL_TIME      (6.0f)
#define LA_TUNNEL_EXT_MIN_EXTENSION         (0.5f)
#define LA_TUNNEL_EXT_MAX_EXTENSION         (1.2f)

#define LA_TUNNEL_EXT_MIN_EGO_VELOCITY      (30.0f/C_KMH_MS)
#define LA_TUNNEL_EXT_MIN_OBJ_DIST          (25.0f)
#define LA_TUNNEL_EXT_MIN_VREL              (30.0f/C_KMH_MS)
#define LA_TUNNEL_EXT_MIN_XDIST             (50.f)
#endif


/*---------------------------------------------------------------------------
| Constants, Variables: Adaption of trace brackets based on camera information about ego-position in lane |
---------------------------------------------------------------------------*/

#ifndef LA_CFG_ADD_EXTENSION_OBJ_APPROX
#error The switch LA_CFG_ADD_EXTENSION_OBJ_APPROX has to be set to 1 to have unchanged behaviour with this version of la_corridor_crit.c!
#endif

#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
SET_MEMSEC_CONST(LA_AblageFaktorKruemmungUR)
static const GDBLFunction_t LA_AblageFaktorKruemmungUR = {
  LA_GENERAL_UR_APPROX_FAKTOR_MAX,   /*!< A1 */
  LA_GENERAL_UR_APPROX_FAKTOR_MIN,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_GENERAL_UR_APPROX_FAKTOR_MIN - LA_GENERAL_UR_APPROX_FAKTOR_MAX ) / ( LA_GENERAL_UR_APPROX_KRUEMMUNG_MAX - LA_GENERAL_UR_APPROX_KRUEMMUNG_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_GENERAL_UR_APPROX_FAKTOR_MAX
  -( (( LA_GENERAL_UR_APPROX_FAKTOR_MIN - LA_GENERAL_UR_APPROX_FAKTOR_MAX ) / ( LA_GENERAL_UR_APPROX_KRUEMMUNG_MAX - LA_GENERAL_UR_APPROX_KRUEMMUNG_MIN ))
  * LA_GENERAL_UR_APPROX_KRUEMMUNG_MIN )
};

SET_MEMSEC_CONST(LA_ExtensionOffsetUR)
static const GDBLFunction_t LA_ExtensionOffsetUR = {
  LA_GENERAL_UR_EXTENSION_MAX,   /*!< A1 */
  LA_GENERAL_UR_EXTENSION_MIN,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_GENERAL_UR_EXTENSION_MIN - LA_GENERAL_UR_EXTENSION_MAX ) / ( LA_GENERAL_UR_EXTENSION_OFFSET_MAX - LA_GENERAL_UR_EXTENSION_OFFSET_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_GENERAL_UR_EXTENSION_MAX
  -( (( LA_GENERAL_UR_EXTENSION_MIN - LA_GENERAL_UR_EXTENSION_MAX ) / ( LA_GENERAL_UR_EXTENSION_OFFSET_MAX - LA_GENERAL_UR_EXTENSION_OFFSET_MIN ))
  * LA_GENERAL_UR_EXTENSION_OFFSET_MIN )
};

#endif

/*! Trace bracket extension for a straight course and an highspeed
    approach. The extension is approximated by the deviation of the
    trajectory given a curvature of . The resulting offset at 200 m 
    is about 2.5m and at 120m about 0.75m. */
#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
SET_MEMSEC_CONST(LA_ExtensionHighspeedApproach)
static const GDBLFunction_t LA_ExtensionHighspeedApproach = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_TB_EXT_MIN_EXTENSION, 
  LA_TB_EXT_MAX_EXTENSION, 
  (LA_TB_EXT_MAX_EXTENSION - LA_TB_EXT_MIN_EXTENSION) /(LA_TB_EXT_MAX_DIST - LA_TB_EXT_MIN_DIST),
  LA_TB_EXT_MIN_EXTENSION - (((LA_TB_EXT_MAX_EXTENSION - LA_TB_EXT_MIN_EXTENSION)/(LA_TB_EXT_MAX_DIST - LA_TB_EXT_MIN_DIST))*LA_TB_EXT_MIN_DIST)
};

/*! If the highspeed approach extension is applied, we need to check whether
  adjacent lanes exist. In order to be able to detect a lane change maneouver early,
  the trace brackets should not be selected too wide. */
SET_MEMSEC_CONST(LA_ExtensionRoadBorderHighspeedApproach)
static const GDBLFunction_t LA_ExtensionRoadBorderHighspeedApproach = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_TB_RB_EXT_MIN_EXTENSION, 
  LA_TB_RB_EXT_MAX_EXTENSION, 
  (LA_TB_RB_EXT_MAX_EXTENSION - LA_TB_RB_EXT_MIN_EXTENSION) /(LA_TB_RB_EXT_MAX_DIST - LA_TB_RB_EXT_MIN_DIST),
  LA_TB_RB_EXT_MIN_EXTENSION - (((LA_TB_RB_EXT_MAX_EXTENSION - LA_TB_RB_EXT_MIN_EXTENSION)/(LA_TB_RB_EXT_MAX_DIST - LA_TB_RB_EXT_MIN_DIST))*LA_TB_RB_EXT_MIN_DIST)
};

SET_MEMSEC_CONST(LA_ExtensionRoadBorderNearDistHighspeedApproach)
static const GDBLFunction_t LA_ExtensionRoadBorderNearDistHighspeedApproach = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_TB_RB_EXT_MIN_NEAR_EXTENSION, 
  LA_TB_RB_EXT_MAX_NEAR_EXTENSION, 
  (LA_TB_RB_EXT_MAX_NEAR_EXTENSION - LA_TB_RB_EXT_MIN_NEAR_EXTENSION) /(LA_TB_RB_EXT_MAX_NEAR_DIST - LA_TB_RB_EXT_MIN_NEAR_DIST),
  LA_TB_RB_EXT_MIN_NEAR_EXTENSION - (((LA_TB_RB_EXT_MAX_NEAR_EXTENSION - LA_TB_RB_EXT_MIN_NEAR_EXTENSION)/(LA_TB_RB_EXT_MAX_NEAR_DIST - LA_TB_RB_EXT_MIN_NEAR_DIST))*LA_TB_RB_EXT_MIN_NEAR_DIST)
};
#endif

/*! Trace bracket extension for high tunnel probability */
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) && (LA_CFG_ADD_EXT_TUNNEL_PROB))
static const GDBLFunction_t LA_ExtensionHighTunnelProb = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_TUNNEL_EXT_MIN_EXTENSION, 
  LA_TUNNEL_EXT_MAX_EXTENSION, 
  (LA_TUNNEL_EXT_MAX_EXTENSION - LA_TUNNEL_EXT_MIN_EXTENSION) /(LA_ADD_EXT_TUNNEL_MAX_REL_TIME - LA_ADD_EXT_TUNNEL_MIN_REL_TIME),
  LA_TUNNEL_EXT_MIN_EXTENSION - (((LA_TUNNEL_EXT_MAX_EXTENSION - LA_TUNNEL_EXT_MIN_EXTENSION)/(LA_ADD_EXT_TUNNEL_MAX_REL_TIME - LA_ADD_EXT_TUNNEL_MIN_REL_TIME))*LA_ADD_EXT_TUNNEL_MIN_REL_TIME)
};
#endif  /* END IF ((FCT_CFG_SIGNAL_PERF_MONITORING) && (LA_CFG_ADD_EXT_TUNNEL_PROB)) */
/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
OLD SA 
vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*-- SIRelTra.c --*/
/* Konstanten fuer SRandUnsicherAbstand */

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
OLD SA 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/* Symbolic constants used by function LA_v_RelTraAddExtensionRelevantObject */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
#define LA_ZVS_DETECT_VREL_DIFF_MAX          (3.F/C_KMH_MS)
#define LA_ZVS_DETECT_VEIGEN_MIN             (30.F/C_KMH_MS)
#define LA_ZVS_DETECT_VREL_MAX               (50.F/C_KMH_MS)
#define LA_ZVS_DETECT_RANGE_MAX              (90.F)
#define LA_ZVS_DETECT_RANGE_DIFF_MAX         (10.F)
#define LA_ZVS_DETECT_OBJ_LIFECYCLES_MIN       (2u)
#define LA_ZVS_DETECT_OBJ_LIFECYCLES_ACTIVATE  (20u)
#define LA_ZVS_DETECT_OBJ_RELTIME_MIN        (2.F)
#define LA_ZVS_DETECT_GRENZWINKEL_RELOBJ     (SLATE_f_GetLobeAngle() * 0.75F)
#define LA_ZVS_DETECT_GRENZWINKEL_NEIGHOBJ   (1.5F)
#define LA_VFR_LIFECYCLES_MIN                (10u)
/*! Konstanten fuer Spurerweiterung des rel. Obj. bei Vorbeifahrten */
#define LA_ABST_DIFF_VORBEIFAHRT_NAEHER      (-10.F)
#define LA_ABST_DIFF_VORBEIFAHRT_WEITER      (3.F)
#define LA_VREL_DIFF_VORBEIFAHRT             (15.F/C_KMH_MS)
#define LA_SEEKBREITE_VORBEIFAHRT            (0.5F)
#define LA_ZVS_HALTEZEIT_CRIT                (23.F)/* (1.5F) */
#define LA_ZVS_HALTEZEIT_MAX                 (38.F)/* (2.5F) */
#define LA_ZVS_HALTEZEIT_MIN                 (16.F)/* (1.F) */
#define LA_ZVS_VREL_MAX                      (20.F/C_KMH_MS)
#define LA_ZVS_VREL_MIN                      (5.F/C_KMH_MS)
#define LA_ZVS_CURVE_RAD_MIN                 (1.0F/2500.F)
#ifndef FUN_PRESEL_ACC_STAT_OBSTACLE
  #define FUN_PRESEL_ACC_STAT_OBSTACLE  (30u) /* To be removed here, if available in algo_constants.h */
#endif
#endif


/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/* Rampe zur Veraenderung der ZVS-Haltezeit in Abhaengigkeit der Vrel */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
SET_MEMSEC_CONST(LA_ZVSHaltezeitVrel)
static const GDBLFunction_t LA_ZVSHaltezeitVrel = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */
  LA_ZVS_HALTEZEIT_MAX,   /*!< A1 */
  LA_ZVS_HALTEZEIT_MIN,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_ZVS_HALTEZEIT_MIN - LA_ZVS_HALTEZEIT_MAX ) / ( LA_ZVS_VREL_MAX - LA_ZVS_VREL_MIN ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_ZVS_HALTEZEIT_MAX
  -( (( LA_ZVS_HALTEZEIT_MIN - LA_ZVS_HALTEZEIT_MAX ) / ( LA_ZVS_VREL_MAX - LA_ZVS_VREL_MIN ))
  * LA_ZVS_VREL_MIN )
};
#endif
/* PRQA L:MACRO_IDENTIFIER_LENGTH */
/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LA_v_RelTraAddRestrictionCurveOuterBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut );
#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
static void LA_v_RelTraAddRestrictionStatObjNextLane(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut);
#endif

#if (LA_CFG_EXT_RELEVANT_OBJECT)
static void LA_v_RelTraAddExtensionRelevantObject(LA_t_RelTraObjInput const *pObjInput , LA_t_RelTraObjOutput *pObjOutput , LA_t_BracketOutput *pBracketOut );
#endif

#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
static void LA_v_RelTraAddExtensionHighspeedApproach(LA_t_RelTraObjInput const *pObjInput, const LA_t_AssTraEnvironment *pEnvironment , LA_t_BracketOutput *pBracketOut, LA_t_RelTraCurve const *pRelTraCurve);
#endif

#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
static void LA_v_RelTraAddExtensionHighTunnelProb(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut, LA_t_RelTraCurve const *pRelTraCurve);
#endif

#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
static void LA_v_RelTraAddExtensionObjectApproximation(LA_t_RelTraObjInput const *pObjInput, const LA_t_RelTraObjOutput *pObjOutput , LA_t_RelTraCurve const *pRelTraCurve , LA_t_BracketOutput *pBracketOut );
static void LA_v_RelTraExtensionObjApproxRight(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraCurve const *pRelTraCurve , LA_t_BracketOutput *pBracketOut );
static void LA_v_RelTraExtensionObjApproxLeft(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraCurve const *pRelTraCurve , LA_t_BracketOutput *pBracketOut );
#endif
/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
/*************************************************************************************************************************
  Functionname:    LA_v_CalculateCorridorBaseBrackets                                                                  */ /*!

  @brief           Calculation corridor base brackets

  @description     Calculation of corridor base brackets. The actual position is between SeekLaneWidth and TrackLaneWidth.
                   @startuml
                   Partition LA_v_CalculateCorridorBaseBrackets {
                   Start
                     If(Object is moving)then (yes)
                       -Use the larger extension factor of seek lane width to relevant object track lane width depending on distance difference
                        If(Check if object is relevant or has been relevant recently) then (yes)
                           -Calculate Base Half Lane Width with Seek Half Lane Width and Track Half Lane Width
                        Else
                           -Object is not relevant or has not been recently
                        endif
                     Elseif(Object is stationary or stopped)then (Yes)
                        If(trajectory hypothesis is considered)then(yes)
                           If(object Stopped Confidence is greater than or equal to 75)then (yes)
                              -Set base half lane width to seek half lane width
                           Elseif(object classification is point or absolute distance is below sixty)then (yes)
                              -Limit the seek lane width to 'la acc trajectory width stationary' at most
                           Else
                              -Limit the seek lane width to ' la acc trajectory narrow width stationary ' at most
                           endif
                   
                        Elseif(trajectory hypothesis is not considered)then (yes)
                           If(object Stopped Confidence is greater than or equal to 75)then (yes)
                              -Set base half lane width to maximum of seek lane width and Minimum half seek lane width for stationary objects
                           Else
                              -Set base half lane width to Scale factor for seek lane width of stationary objects times seek half lane width
                           endif
                        
                        Else
                        Endif
                   
                     Else
                     endif
                     
                     -set Bracket Position Left to sum of dAblage Radius and Base Half Lane Width
                     -set Bracket Position Right to sum of dAblage Radius and Base Half Lane Width
                     
                   
                   end
                   }
                   @enduml

  @return          void

  @param[in]       pObjectProperties : Pointer to an LA_t_RelTraObjInput type structure.Defined in la_corridor_crit.h
                      pObjectProperties->iObjNr                                                                                                                                [0 ... EM_N_OBJECTS-1]
                      pObjectProperties->dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track lane width depending on time and distance      [0.0f ... 1.0f]
                      pObjectProperties->dRelSpurAbstandErweitFaktor :Factor for widening seek lane width to relevant object track lane width depending on distance difference [0.0f ... 1.0f]
                      pObjectProperties->ucDynamicProperty                                                                                                                     [SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
                      pObjectProperties->uiStoppedConfidence                                                                                                                   [0 ... 100]
                      pObjectProperties->dAbst_mittel                                                                                                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjectProperties->dAblage_Radius                                                                                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pTrajectory : Pointer to an LA_t_RelTraCurve type structure, which describes the trajectory. Defined in la_corridor_crit.h
                      pTrajectory->iOWVflag : Flag describing which trajectory hypothesis is considered                                                                        [ 0 or 1]
  @param[in,out]   pBaseBrackets : Pointer to structure of type LA_t_BracketOutput, defined in la_corridor_crit.h
                      pBaseBrackets->BracketPositionLeft : Factor to scale the left trace bracket.                                                                             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBaseBrackets->BracketPositionRight : Factor to scale the right trace bracket.                                                                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pBracketFuncEnableFlags : Pointer to structure LA_t_BracketFuncEnable, Decides wheather the particular extension/restriction to be executed or not.
                       pBracketFuncEnableFlags->bUseSeekLaneWidthOnly                                                                                                          [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                   
  @glob_in         *SLATE_pt_GetObjClassification : object class                                                                                                                           [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         pt_LAOutput->f_LA_SeekLaneWidth : global seek lane width variable                                                                                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAOutput->f_LA_TrackLaneWidth : global track lane width variable                                                                                         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             LA_v_CalculateBaseLaneWidths has to be calculated for pt_LAOutput->f_LA_SeekLaneWidth and pt_LAOutput->f_LA_TrackLaneWidth values
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016
  @changed         2/17/2016

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
void LA_v_CalculateCorridorBaseBrackets(const LA_t_RelTraObjInput* const pObjectProperties, const LA_t_RelTraCurve* const pTrajectory, LA_t_BracketOutput* const pBaseBrackets, 
                                      const LA_t_BracketFuncEnable * const pBracketFuncEnableFlags)
{
  /* Lanewidth as a function of road type and ego velocity */
  float32 fLASeekLaneWidth    = pt_LAOutput->f_LA_SeekLaneWidth;
  float32 fSeekHalfLaneWidth  = fLASeekLaneWidth * 0.5f;
  float32 fTrackHalfLaneWidth = pt_LAOutput->f_LA_TrackLaneWidth * 0.5f;
  float32 fBaseHalfLaneWidth  = fSeekHalfLaneWidth;  
  SLATE_t_Obj_CLassification t_ObjClassification  = *SLATE_pt_GetObjClassification(pObjectProperties->iObjNr);

  /* Moving objects */
  if (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
  {
    /* Use the larger extension factor of the two */
    float32 ExtensionFactor = MAX_FLOAT(pObjectProperties->dRelSpurErweiterungsFaktor, pObjectProperties->dRelSpurAbstandErweitFaktor);

    /* Check if object is relevant or has been relevant recently */
    if ( (ExtensionFactor > C_F32_DELTA) &&
        (pBracketFuncEnableFlags->bUseSeekLaneWidthOnly == FALSE))
    {
      /* Linear interpolation between TrackLaneWidth and SeekLaneWidth */
      fBaseHalfLaneWidth = fSeekHalfLaneWidth + (ExtensionFactor * (fTrackHalfLaneWidth - fSeekHalfLaneWidth));
    }
    else
    {
      /* Object is not relevant or has not been recently */
      fBaseHalfLaneWidth = fSeekHalfLaneWidth;
    }
  }
  /* Stationary objects */
  else if ( (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
         || (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
    )
  {

    /* Slightly different calculation whether default trajectory of alternative trajectory is used */
    if (pTrajectory->iOWVflag == LA_OWVKRIT_AKTIV)
    {
      if (pObjectProperties->uiStoppedConfidence >= FCT_ACC_PAR_OBJ_STOPPED_MIN_CONF)
      {
        fBaseHalfLaneWidth = fSeekHalfLaneWidth;
      } else if ((t_ObjClassification != SLATE_OBJCLASS_POINT) || (pObjectProperties->dAbst_mittel < LA_PAR_MAX_DISTX_STAT_POINT_SMALL_SEEK))
      {
        /* For stationary objects limit the seek lane width. As most roadside stationaries are seen
        as 'point' class objects in large distances, limit lane width more for far away points.
        Note: in tight turns valid in-lane objects also tend to be points, thus do not limit near
        range objects that much */
        /* Limit the seek lane width to 'LA_ACC_TRAJECTORY_WIDTH_STAT' at most */
        fBaseHalfLaneWidth = MIN_FLOAT(fLASeekLaneWidth, LA_ACC_TRAJECTORY_WIDTH_STAT) * 0.5F;
      }
      else
      {
        /* Limit the seek lane width to 'LA_ACC_TRAJECTORY_NARROWWIDTH_STAT' at most */
        fBaseHalfLaneWidth = MIN_FLOAT(fLASeekLaneWidth, LA_ACC_TRAJECTORY_NARROWWIDTH_STAT) * 0.5F;
      }
    }
    else if (pTrajectory->iOWVflag == LA_OWVKRIT_INAKTIV)
    {
      if(pObjectProperties->uiStoppedConfidence  >= FCT_ACC_PAR_OBJ_STOPPED_MIN_CONF)
      {
        fBaseHalfLaneWidth = MAX_FLOAT(fSeekHalfLaneWidth, LA_MIN_HALF_SEEK_LANE_WIDTH_STAT);
      }
      else
      {
        fBaseHalfLaneWidth = LA_SCALE_HALF_SEEK_LANE_WIDTH_STAT * fSeekHalfLaneWidth;
      }
    }
    else
    {
    }
  }
  else
  {
   
  }

  pBaseBrackets->BracketPositionLeft  = pObjectProperties->dAblage_Radius + fBaseHalfLaneWidth;
  pBaseBrackets->BracketPositionRight = pObjectProperties->dAblage_Radius - fBaseHalfLaneWidth;  

}


/*************************************************************************************************************************
  Functionname:    LA_v_ExecuteAdditiveBracketFunctions                                                                  */ /*!

  @brief           Compute additive bracket functions.

  @description     Compute additive bracket functions comprising extensions and restrictions
                   @startuml
                   Partition LA_v_ExecuteAdditiveBracketFunctions {
                   Start
                     If(object is Stationary or Stopped) then (yes)
                       If(restriction of brackets for stationary objects in next lane is enabled)then (yes)
                          Partition #lightblue **LA_v_RelTraAddRestrictionStatObjNextLane** {
                            -Compute restrictions for stationary objects on neighboring lanes
                          }
                       endif
                     endif
                     if(Object is Moving or Stopped)then (yes)
                       if(Restriction Curve Outer Border is enabled)then (yes)
                          Partition #lightblue **LA_v_RelTraAddRestrictionCurveOuterBorder** {
                            - Restriction of the curve outer edge for objects depending on the track radius and the distance       
                          }
                       Endif
                       If(Extension Object Approximation is Enable)then (yes)
                          Partition #lightblue **LA_v_RelTraAddExtensionObjectApproximation** {
                            - Add approximation for object extension
                          }
                       Endif
                       If(extension of brackets for relevant object is Enable)then (yes)
                          Partition #lightblue **LA_v_RelTraAddExtensionRelevantObject** {
                            - Add relative trajectory extension for relevant object
                          }
                       Endif
                   	If(extension of brackets for relevant object which we approach very fast without        reliable road estimation is Enable)then (yes)
                          Partition #lightblue **LA_v_RelTraAddExtensionHighspeedApproach** {
                            - When approaching an already relevent object extend brackets
                          }
                       Endif
                       If(extension of brackets for improved robustness against drop-outs in tunnels is                 Enable)then (yes)
                          Partition #lightblue **LA_v_RelTraAddExtensionHighTunnelProb** {
                            - Extend trace brackets in tunnels
                          }
                       Endif
                     endif
                   end
                   }
                   @enduml

  @return          void

  @param[in]       pObjectProperties : Pointer to an LA_t_RelTraObjInput type structure.Defined in la_corridor_crit.h
                      pObjectProperties->iObjNr                                                                                                                                [ 0 ... EM_N_OBJECTS-1]
                      pObjectProperties->ucDynamicProperty                                                                                                                     [SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
  @param[in]       pTrajectory : Pointer to an LA_t_RelTraCurve type structure, which describes the trajectory. Defined in la_corridor_crit.h
  @param[in,out]   pObjectVariables : Pointer to an LA_t_RelTraObjOutput type structure. Defined in la_corridor_crit.h
  @param[in,out]   pEnvironment : pointer to structure LA_t_AssTraEnvironment, containing lane matrix information.  Defined in la_corridor_crit.h
  @param[in,out]   pBracketFuncResults : pointer to structure LA_t_CriteriaMatrix, contains the information about the corridor of the object (Left and Right bracket Information).
                      pBracketFuncResults->AddRestrictionStatObjNextLane                                                                                                       [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBracketFuncResults->AddRestrictionCurveOuterBorder                                                                                                      [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBracketFuncResults->AddExtensionObjectApproximation                                                                                                     [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBracketFuncResults->AddExtensionRelevantObject                                                                                                          [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBracketFuncResults->AddExtensionHighspeedApproach                                                                                                       [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBracketFuncResults->AddExtensionHighTunnelProb                                                                                                          [LA_t_BracketOutput as defined in la_corridor_crit.h]
  @param[in]       pBracketFuncEnableFlags : Pointer to structure LA_t_BracketFuncEnable, Decides wheather the particular extension/restriction to be executed or not.
                      pBracketFuncEnableFlags->bEnableAddRestrictionStatObjNextLane                                                                                            [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                      pBracketFuncEnableFlags->bEnableAddRestrictionCurveOuterBorder                                                                                           [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                      pBracketFuncEnableFlags->bEnableAddExtensionObjectApproximation                                                                                          [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                      pBracketFuncEnableFlags->bEnableAddExtensionRelevantObject                                                                                               [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                      pBracketFuncEnableFlags->bEnableExtensionHighspeedApproach                                                                                               [type boolean defined in Platform_Types.h] [TRUE,FALSE]
                      pBracketFuncEnableFlags->bEnableAddExtensionHighTunnelProb                                                                                               [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(pObjectProperties->iObjNr) : Boolean if an stationary object was seen moving                                                    [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_out        -

  @c_switch_part   LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE : Switch to enable restriction based on stationary objects in next lane.
  @c_switch_part   LA_CFG_ADD_EXTENSION_OBJ_APPROX : Configuration switch to enable/disable extension object approximation.
  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : Configuration switch to enable/disable relevant object extension.
  @c_switch_part   LA_CFG_EXT_HIGHSPEED_APPROACH : Configuration switch to enable a bracket extension used for highspeed approaches.
  @c_switch_part   LA_CFG_ADD_EXT_TUNNEL_PROB : Configuration switch to enable a bracket extension used for improved robustness against drop-outs in tunnels.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016  
  @changed         2/17/2016

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/

void LA_v_ExecuteAdditiveBracketFunctions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_RelTraCurve* const pTrajectory,
                                       const LA_t_AssTraEnvironment *pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, const LA_t_BracketFuncEnable* const pBracketFuncEnableFlags)
{
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(pObjectProperties->iObjNr);
  /*********************** RESTRICTIONS ****************************/
  /* Calculate relative restrictions */
  if ((pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) || (b_ObjIsMovingToStationary == TRUE))
  {
#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
      if (pBracketFuncEnableFlags->bEnableAddRestrictionStatObjNextLane != LA_CORR_BRACKET_FUNC_DISABLED)
      {
        /* This restriction will be applied only for stationary or stopped objects, check is done within function */
        LA_v_RelTraAddRestrictionStatObjNextLane(pObjectProperties, &pBracketFuncResults->AddRestrictionStatObjNextLane);
      }
#endif
  } /* ONLY for Stationary or Stopped objects */

  /* ONLY for Moving or Stopped Objects */
  if( (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) || 
#if (FCT_CFG_SENSOR_TYPE_RADAR)
    ((pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) && (b_ObjIsMovingToStationary == TRUE)) )
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
    (b_ObjIsMovingToStationary == TRUE) )
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
  {
    /* Calculate relative restrictions */
    if(pBracketFuncEnableFlags->bEnableAddRestrictionCurveOuterBorder != LA_CORR_BRACKET_FUNC_DISABLED)
    {
      LA_v_RelTraAddRestrictionCurveOuterBorder(pObjectProperties, pTrajectory, &pBracketFuncResults->AddRestrictionCurveOuterBorder);
    }

    /*********************** EXTENSIONS ******************************/
    /* Calculate relative extensions */
#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX)
    if(pBracketFuncEnableFlags->bEnableAddExtensionObjectApproximation != LA_CORR_BRACKET_FUNC_DISABLED)
    {
      LA_v_RelTraAddExtensionObjectApproximation(pObjectProperties, pObjectVariables, pTrajectory, &pBracketFuncResults->AddExtensionObjectApproximation);
    }
#endif

#if (LA_CFG_EXT_RELEVANT_OBJECT)
    if(pBracketFuncEnableFlags->bEnableAddExtensionRelevantObject != LA_CORR_BRACKET_FUNC_DISABLED)
    {
      LA_v_RelTraAddExtensionRelevantObject(pObjectProperties, pObjectVariables, &pBracketFuncResults->AddExtensionRelevantObject);
    }
#endif

#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
    if(pBracketFuncEnableFlags->bEnableExtensionHighspeedApproach != LA_CORR_BRACKET_FUNC_DISABLED)
    {
      LA_v_RelTraAddExtensionHighspeedApproach(pObjectProperties, pEnvironment, &pBracketFuncResults->AddExtensionHighspeedApproach,pTrajectory);
    }
#else
    _PARAM_UNUSED(pEnvironment);
#endif

#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
    if(pBracketFuncEnableFlags->bEnableAddExtensionHighTunnelProb != LA_CORR_BRACKET_FUNC_DISABLED)
    {
      LA_v_RelTraAddExtensionHighTunnelProb(pObjectProperties, &pBracketFuncResults->AddExtensionHighTunnelProb,pTrajectory);
    }
#endif
  } /* ONLY for Moving or Stopped objects */

}



/*************************************************************************************************************************
  Functionname:    LA_v_RelTraAddRestrictionCurveOuterBorder                                                                  */ /*!

  @brief           Restriction of the curve outer edge for objects depending on the track radius and the distance.

  @description     Restriction of the curve outer edge for objects depending on the track radius and the distance
                   GERMAN:
                   Beschneidung des Kurvenaussenrandes bei Objekten in Abhängigkeit vom Spurradius und der Entfernung
                   @startuml
                   Partition LA_v_RelTraAddRestrictionCurveOuterBorder {
                   Start
                     If(Check if object is not relevant and the absolute angle  w.r.t. the object is beyond the field of view of one sidelobe) then (yes)
                       - Influence of the outer edge of the curve by the lane radius in the Seek case
                       - Distance factor for distance less than 30m is set to 0
                       - Distance factor for Distance greater than or equal to 30m & distance less than or equal to 50m is set to 0.0 to 1.0 
                       -Distance factor for Distance greater than 50m is set to 1.0
                       - Radius factor at absolute Radius is less than 1000m is set to 1.0 
                       - Radius factor at absolute Radius greater than or equal to 1000m & absolute Radius less than or equal to 2500m is set to 1.0 to 0.0 
                       - Radius factor at absolute Radius greater than 2500m is set to 0.0
                       - The minimum factor of radius and distance the multiplier for reducing the outside of the curve Edge of the road
                       - Multiply the factor by the actual width in m
                       if(Radius KA is greater than C F32 DELTA ) then (yes)
                          if(Radius is greater than C F32 DELTA )
                            - Left turn, right KA must be influenced, Write track bracket position
                          elseif(Radius is less than minus C F32 DELTA ) then (yes)
                            - Right turn, left KA must be influenced, Write track bracket position
                          Else
                             - do nothing 
                          endif
                   
                       else
                         -Do nothing
                       endif
                   
                     endif
                   
                   end
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dRelSpurErweiterungsFaktor                                          [0.0f ... 1.0f]
                      pObjInput->dRelSpurAbstandErweitFaktor                                         [0.0f ... 1.0f]
                      pObjInput->dWinkel_m_abs                                                       [-PI … +PI] rad
                      pObjInput->dAbst_mittel                                                        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve : curvature value of considered trajectory                [-1 … +1] m^-1
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         SLATE_f_GetLobeAngle()                                                                        [-PI ... +PI] rad
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016  
  @changed         2/17/2016

  @author          R. Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraAddRestrictionCurveOuterBorder(LA_t_RelTraObjInput const *pObjInput, LA_t_RelTraCurve const *pRelTraCurve, LA_t_BracketOutput *pBracketOut )
{
  /*--- VARIABLES ---*/
  float32 dRadiusKA;
  float32 dRadius;
  float32 dRadiusFaktor,dAbstFaktor;

  float32 ExtensionFactor = MAX_FLOAT(pObjInput->dRelSpurErweiterungsFaktor, pObjInput->dRelSpurAbstandErweitFaktor);
  float32 f_LobeAngle = SLATE_f_GetLobeAngle();

  /* Check if object is not relevant (ExtensionFactor < C_F32_Delta) and
     the absolute angle w.r.t. the object is beyond the field of view of one sidelobe (SLATE_f_GetLobeAngle())
  */
  if ( (ExtensionFactor < C_F32_DELTA) &&
       (pObjInput->dWinkel_m_abs > (f_LobeAngle - C_F32_DELTA)))
  {

    /* Beeinflussung des Kurvenaeusseren-Fahrbahnrandes durch den Spurradius im Seek-Fall     */

    /* Abstandsfaktor bei Abstand < LA_SB_KA_ABST_MIN (30m) = 0.0                                */
    /*                    Abstand >= LA_SB_KA_ABST_MIN & Abstand <= LA_SB_KA_ABST_MAX = 0.0 bis 1.0 */
    /*                    Abstand > LA_SB_KA_ABST_MAX (50m) = 1.0                                */

    dAbstFaktor = ( ( pObjInput->dAbst_mittel - LA_SB_KA_ABST_MIN ) * (1.F / ( LA_SB_KA_ABST_MAX - LA_SB_KA_ABST_MIN ) ) );
    dAbstFaktor = MINMAX_FLOAT( 0.F , 1.F , dAbstFaktor );

    /* Radiusfaktor bei Radius_abs < LA_SB_KA_RADIUS_MIN (1000m) = 1.0                                   */
    /*                  Radius_abs >= LA_SB_KA_RADIUS_MIN & Radius_abs <= LA_SB_KA_RADIUS_MAX = 1.0 bis 0.0 */
    /*                  Radius_abs > LA_SB_KA_RADIUS_MAX = 0.0                                           */

    dRadius = A2_TO_RAD(pRelTraCurve->dCurve);/* PRQA S 3416 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as it does not have any critical impact on the functionality. */ 

    dRadiusFaktor = 1.F - (( fABS(dRadius) - LA_SB_KA_RADIUS_MIN ) * (1.F / ( LA_SB_KA_RADIUS_MAX - LA_SB_KA_RADIUS_MIN ) ) );
    dRadiusFaktor = MINMAX_FLOAT( 0.F , 1.F , dRadiusFaktor );

    /* Der minimale Faktor aus Radius und Abstand den Multiplikator zur Verkleinerung des Kurvenaussen- */
    /* Fahrbahnrandes                                                                                   */

    dRadiusKA = MIN_FLOAT( dRadiusFaktor , dAbstFaktor );

    /* Faktor mit tatsaechlicher Breite in m multiplizieren */

    dRadiusKA *= LA_SB_KA_RADIUS_BREITE;

    /* Faktor mit groesserer Auswirkung auf Fahrbahnbreite aus Drift und Spurradius ist am Kurvenaussenrand wirksam */
    /* Kurvenaussenrand-Seite wird in Abhaengigkeit vom Radius bestimmt. Beschraenkung ist nur dort wirksam         */

    if( dRadiusKA > C_F32_DELTA )
    {
      if( dRadius > C_F32_DELTA )
      {
        /* Linkskurve, rechter KA muss beeinflusst werden */
        /* Spurklammerposition schreiben */
        pBracketOut->BracketPositionRight = dRadiusKA;

      }
      else if( dRadius < -C_F32_DELTA )
      {
        /* Rechtskurve, linker KA muss beeinflusst werden */
        /* Spurklammerposition schreiben */
        pBracketOut->BracketPositionLeft = -dRadiusKA;

      }
      else
      {
        /* Radius = 0 (gesetzt) bedeutet Geradeaus, hier wird der Kurvenaussenrand nicht bearbeitet. */
      }
    } else
    {
      /* Keine Begrenzung notwenig */
    }
  }
}


#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraAddExtensionObjectApproximation                                                                  */ /*!

  @brief           Add approximation for object extension.

  @description     Add approximation for object extension (for moving objects).
                   @startuml
                   Partition LA_v_RelTraAddExtensionObjectApproximation {
                   Start
                     If(object is moving) then (yes)
                        If(object is associtate to ego lane) then (yes)
                          Partition #lightblue **LA_v_RelTraExtensionObjApproxLeft** {
                             -Add approximation for object extension for left associated line
                           }
                          Partition #lightblue **LA_v_RelTraExtensionObjApproxRight** {
                             -Add approximation for object extension for Right associated line
                           }
                        Elseif(object is associate to right lane) then (yes)
                           Partition #lightblue **LA_v_RelTraExtensionObjApproxRight** {
                             -Add approximation for object extension for Right associated line
                           }
                        Elseif(object is associate to left lane) then (yes)
                           Partition #lightblue **LA_v_RelTraExtensionObjApproxLeft** {
                             -Add approximation for object extension for Left associated line
                           }
                        endif
                             
                   
                     endif
                   end
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->ucDynamicProperty    [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @param[in]       pRelTraCurve : Pointer to LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
  @param[in]       pObjOutput : Pointer to LA_t_RelTraObjOutput type structure.  Output information about the object. Defined in la_corridor_crit.h
                      pObjOutput->iObjektSpur_Zyklus  [enum type eAssociatedLane_t, defined in Rte_Type.h]
  @param[in]       pTrajectoryData : Pointer to CP_t_TrajectoryData. Defined in cp_ext.h
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_ADD_EXTENSION_OBJ_APPROX : Configuration switch to enable/disable extension object approximation.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016  
  @changed         2/17/2016

  @author          R. Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraAddExtensionObjectApproximation(LA_t_RelTraObjInput const *pObjInput, const LA_t_RelTraObjOutput *pObjOutput , LA_t_RelTraCurve const *pRelTraCurve , LA_t_BracketOutput *pBracketOut )
{
  if(pObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
  {
    switch(pObjOutput->iObjektSpur_Zyklus)
    {
      case ASSOC_LANE_EGO:
        LA_v_RelTraExtensionObjApproxLeft( pObjInput , pRelTraCurve , pBracketOut );

        LA_v_RelTraExtensionObjApproxRight( pObjInput , pRelTraCurve , pBracketOut );
        break;

      case ASSOC_LANE_RIGHT:
        LA_v_RelTraExtensionObjApproxRight( pObjInput , pRelTraCurve , pBracketOut );
        break;

      case ASSOC_LANE_LEFT:
        LA_v_RelTraExtensionObjApproxLeft( pObjInput , pRelTraCurve , pBracketOut );
        break;
      default:
        break;
    }
  }
}
#endif


#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionObjApproxRight                                                                  */ /*!

  @brief           Add approximation for object extension for right associated line.

  @description     Add approximation for object extension for right associated line.
                   @startuml
                   Partition LA_v_RelTraExtensionObjApproxRight {
                   Start
                      If(object longitudinal displacement is less than LA SEEK APPROX ABSTAND MINIMUM)then (yes)
                         - Query the criteria for expanding the track brackets due to the hit location of the trace 
                          If(Trace Reached Ego Vehical is true and
                   Y Intersec  is less than 1.25 and greater than -1.25 and
                   Y Intersec Grad Filter is less thab LA GENERAL APPROXIMATION MAX YINTERSEC GRADIENT and
                   object longitudinal diplacement is less LA_GENERAL UPPER APPROXIMATION DISTANCE MAX and
                   object relative velocity is less than LA_GENERAL UPPER APPROXIMATION VREL MIN and
                   object angle is less than Lobe Angle)) then (yes)
                            - Calculate parallelism of SA trajectory to trace
                              If(TraceParallelism.relevantTrace is TRUE and
                                 Mean distance is less than LA GENERAL UPPER APPROX THRES MIN and
                                 Distance slandered deviation is less than LA GENERAL APPROXIMATION PARALLELISM STD    ) then (yes)
                                 If(object is relavent )
                                   - Reduction of the track bracket extension depending on the relevant time
                                 Else
                                   - Calculate distance factor
                                 Endif
                                  - Reduction of the widening of the track brackets depending on the track curvature
                                  - determine minimum expansion
                                  - Reduction of the track bracket expansion depending on the hit location of the trace
                                  - Determination of the minimum expansion
                              endif
                          endif
                   
                      endif
                     
                      -set Offset Result to minimum of dAblageApp ans dAblageAppUR
                      If(Offset Result is less than INIT VALUE BRACKET POSITION) then (yes)
                        - Write track bracket position
                      endif
                       
                   end
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dAbst_mittel                                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->iTraceReachedEgoVeh                                               [TRUE or FALSE]
                      pObjInput->dYIntersec                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dYIntersecGradFilt                                                [-1 … +1]
                      pObjInput->dVrel_mittel                                                      [-330.f ... 330.f] m/s
                      pObjInput->dWinkel_m_abs                                                     [-PI … +PI] rad
                      pObjInput->iTracingID                                                        [Datatype of unsigned char] [0 ... 10]
                      pObjInput->iRelevant                                                         [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dRelSpurErweiterungsFaktor                                        [0.0f ... 1.0f]
                      pObjInput->dNichtRelevantZeit                                                [0 .. RELEVANTZEIT_MAX]
  @param[in]       pRelTraCurve : Pointer to LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve_abs                                                     [0 … +1] m-1
  @param[in]       pTrajectoryData : Pointer to CP_t_TrajectoryData. Defined in cp_ext.h
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_ADD_EXTENSION_OBJ_APPROX : Configuration switch to enable/disable extension object approximation.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016  
  @changed         2/17/2016

  @author          R. Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraExtensionObjApproxRight(LA_t_RelTraObjInput const *pObjInput , LA_t_RelTraCurve const *pRelTraCurve , LA_t_BracketOutput *pBracketOut )
{
  /*--- VARIABLES ---*/
  float32 dAblageAbstandFaktor;
  float32 dAblageKruemmungFaktor;
  float32 dAblageApp = INITVALUE_BRACKETPOSITION;
  float32 dAblageAppUR = INITVALUE_BRACKETPOSITION;
  float32 dOffsetReduced;
  float32 dOffsetResult;
  float32 fABS_YIntersecGradFilt, fABS_SADistMean, fABS_SADistStdDev;	/* For calculating ABS value */
  
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CP_t_Traj2MOTraceParallelism TraceParallelism;
  float32 f_LobeAngle = SLATE_f_GetLobeAngle();

  if( pObjInput->dAbst_mittel > LA_SEEK_APPROX_ABSTAND_MIN )
  {
    /* Abfrage der Kriterien fuer Erweiterung der Spurklammern aufgrund */
    /* des Trefferorts des Traces */
	fABS_YIntersecGradFilt = fABS(pObjInput->dYIntersecGradFilt); 
	
    if(  (pObjInput->iTraceReachedEgoVeh == (ubit8_t)TRUE)
      && (pObjInput->dYIntersec < LA_GENERAL_UR_APPROX_THRES_MIN)
      && (pObjInput->dYIntersec > -LA_GENERAL_UR_APPROX_THRES_MAX)
      && (fABS_YIntersecGradFilt < LA_GENERAL_APPROX_MAX_YINTERSEC_GRADIENT)
      && (pObjInput->dAbst_mittel < LA_GENERAL_UR_APPROX_DISTANCE_MAX)
      && (pObjInput->dVrel_mittel < LA_GENERAL_UR_APPROX_VREL_MIN)
      && (pObjInput->dWinkel_m_abs < f_LobeAngle)
      )
    {
      /* Calculate parallelism of SA trajectory to trace */
      TraceParallelism  = CP_t_Traj2MOTraceParallelismCheck(pObjInput->iTracingID);
	  fABS_SADistMean   = fABS(TraceParallelism.fSADistMean);
	  fABS_SADistStdDev = fABS(TraceParallelism.fSADistStdDev);
	  
      if(  (TraceParallelism.relevantTrace == TRUE)
        && (fABS_SADistMean   < LA_GENERAL_UR_APPROX_THRES_MIN)
        && (fABS_SADistStdDev < LA_GENERAL_APPROX_PARALLELISM_STD)
        )
      {

        /* Reduzierung der Spurklammererweiterung abhaengig von Relevantzeit */
        if(  (  (pObjInput->iRelevant == (ubit8_t)TRUE )
          && (pObjInput->dRelSpurErweiterungsFaktor >= (LA_GENERAL_APPROX_MIN_LANE_EXTENSION_FAC - C_F32_DELTA))
          )
          || (  (pObjInput->dNichtRelevantZeit > C_F32_DELTA)
          && (pObjInput->dAbst_mittel > LA_GENERAL_UR_APPROX_DISTANCE_CRIT)
          )
          )
        {
          dAblageAbstandFaktor = LA_GENERAL_UR_APPROX_FAKTOR_MIN;
        }
        else
        {
          /* Abstandsfaktor berechnen */
          dAblageAbstandFaktor = MIN_FLOAT( 1.F , pObjInput->dAbst_mittel * LA_GENERAL_UR_APPROX_ABSTAND_ERW );
        }

        /* Reduzierung der Spurklammererweiterung abhaengig von Spurkruemmung */
        dAblageKruemmungFaktor = dGDBmathLineareFunktion( &LA_AblageFaktorKruemmungUR ,  pRelTraCurve->dCurve_abs );

        /* minimale Erweiterung ermitteln */
        dOffsetReduced = -LA_SEEK_APPROX_ABLAGE_ERWEITERUNG * MIN_FLOAT(dAblageKruemmungFaktor, dAblageAbstandFaktor);

        /* Reduzierung der Spurklammererweiterung abhaengig vom Trefferort des Traces */
        dAblageAppUR = -dGDBmathLineareFunktion( &LA_ExtensionOffsetUR ,  fABS(pObjInput->dYIntersec) );

        /* Ermittelung der minimalen Erweiterung */
        dAblageAppUR = MAX_FLOAT( dAblageAppUR, dOffsetReduced);
      }
    }
  }
#else
  _PARAM_UNUSED(pRelTraCurve);
  _PARAM_UNUSED(pObjInput);
  _PARAM_UNUSED(dAblageAbstandFaktor);
  _PARAM_UNUSED(dOffsetReduced);
  _PARAM_UNUSED(dAblageKruemmungFaktor);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

  dOffsetResult = MIN_FLOAT(dAblageApp, dAblageAppUR);

  if (dOffsetResult < INITVALUE_BRACKETPOSITION)
  {
    /* Spurklammerposition schreiben */
    pBracketOut->BracketPositionRight = dOffsetResult;
  }

}
#endif



#if (LA_CFG_ADD_EXTENSION_OBJ_APPROX == 1)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionObjApproxLeft                                                                  */ /*!

  @brief           Add approximation for object extension for left associated line

  @description     Add approximation for object extension for left associated line
                   @startuml
                   Partition LA_v_RelTraExtensionObjApproxLeft {
                   Start
                      If(object longitudinal displacement is greater than LA SEEK APPROX ABSTAND MINIMUM)then (yes)
                         - Query the criteria for expanding the track brackets due to the hit location of the trace 
                          If(Trace Reached Ego Vehical is true and
                   Y Intersec  is greater than -1.25 and less than 1.25 and
                   Y Intersec Grad Filter is less thab LA GENERAL APPROXIMATION MAX YINTERSEC GRADIENT and
                   object longitudinal diplacement is less LA_GENERAL_UR_APPROX_DISTANCE_MAX and
                   object relative velocity is less than LA_GENERAL_UR_APPROX_VREL_MIN and
                   object angle is less than Lobe Angle)) then (yes)
                            - Calculate parallelism of SA trajectory to trace
                              If(TraceParallelism.relevantTrace is TRUE and
                                 Mean distance is less than LA GENERAL UPPER APPROX THRES MIN and
                                 Distance slandered deviation is less than LA GENERAL APPROXIMATION PARALLELISM STD    ) then (yes)
                                 If(object is relavent )
                                   - Reduction of the track bracket extension depending on the relevant time
                                 Else
                                   - Calculate distance factor
                                 Endif
                                  - Reduction of the widening of the track brackets depending on the track curvature
                                  - determine minimum expansion
                                  - Reduction of the track bracket expansion depending on the hit location of the trace
                                  - Determination of the minimum expansion
                              endif
                          endif
                   
                      endif
                     
                      -set Offset Result to minimum of dAblageApp ans dAblageAppUR
                      If(Offset Result is less than INIT VALUE BRACKET POSITION) then (yes)
                        - Write track bracket position
                      endif
                       
                   end
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dAbst_mittel                                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->iTraceReachedEgoVeh                                               [TRUE or FALSE]
                      pObjInput->dYIntersec                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pObjInput->dYIntersecGradFilt                                                [-1 … +1]
                      pObjInput->dVrel_mittel                                                      [-330.f ... 330.f] m/s
                      pObjInput->dWinkel_m_abs                                                     [-PI … +PI] rad
                      pObjInput->iTracingID                                                        [Datatype of unsigned char] [0 ... 10]
                      pObjInput->iRelevant                                                         [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dRelSpurErweiterungsFaktor                                        [0.0f ... 1.0f]
                      pObjInput->dNichtRelevantZeit                                                [0 .. RELEVANTZEIT_MAX]
  @param[in]       pRelTraCurve : Pointer to LA_t_RelTraCurve type structure, describes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve_abs                                                     [0 … +1] m-1
  @param[in]       pTrajectoryData : Pointer to CP_t_TrajectoryData. Defined in cp_ext.h
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_ADD_EXTENSION_OBJ_APPROX : Configuration switch to enable/disable extension object approximation.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016  
  @changed         2/17/2016

  @author          R. Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraExtensionObjApproxLeft(LA_t_RelTraObjInput const *pObjInput , LA_t_RelTraCurve const *pRelTraCurve , LA_t_BracketOutput *pBracketOut )
{
  /*--- VARIABLES ---*/
  float32 dAblageAbstandFaktor;
  float32 dAblageKruemmungFaktor;
  float32 dAblageApp = -INITVALUE_BRACKETPOSITION;
  float32 dAblageAppUR = -INITVALUE_BRACKETPOSITION;
  float32 dOffsetReduced;
  float32 dOffsetResult;
  float32 fABS_YIntersecGradFilt, fABS_SADistMean, fABS_SADistStdDev;	/* For calculating ABS value */
  
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CP_t_Traj2MOTraceParallelism TraceParallelism;
  float32 f_LobeAngle = SLATE_f_GetLobeAngle();

  if( pObjInput->dAbst_mittel > LA_SEEK_APPROX_ABSTAND_MIN )
  {
    /* Abfrage der Kriterien fuer Erweiterung der Spurklammern aufgrund */
    /* des Trefferorts des Traces */
	fABS_YIntersecGradFilt = fABS(pObjInput->dYIntersecGradFilt);
	
    if(  (pObjInput->iTraceReachedEgoVeh == (ubit8_t)TRUE)
      && (pObjInput->dYIntersec > -LA_GENERAL_UR_APPROX_THRES_MIN)
      && (pObjInput->dYIntersec < LA_GENERAL_UR_APPROX_THRES_MAX)
      && (fABS_YIntersecGradFilt < LA_GENERAL_APPROX_MAX_YINTERSEC_GRADIENT)
      && (pObjInput->dAbst_mittel < LA_GENERAL_UR_APPROX_DISTANCE_MAX)
      && (pObjInput->dVrel_mittel < LA_GENERAL_UR_APPROX_VREL_MIN)
      && (pObjInput->dWinkel_m_abs < f_LobeAngle)
      )
    {
      /* Calculate parallelism of SA trajectory to trace */
      TraceParallelism  = CP_t_Traj2MOTraceParallelismCheck(pObjInput->iTracingID);
	  fABS_SADistMean   = fABS(TraceParallelism.fSADistMean);
	  fABS_SADistStdDev = fABS(TraceParallelism.fSADistStdDev);
	  
      if(  (TraceParallelism.relevantTrace == TRUE)
        && (fABS_SADistMean  < LA_GENERAL_UR_APPROX_THRES_MIN)
        && (fABS_SADistStdDev < LA_GENERAL_APPROX_PARALLELISM_STD)
        )
      {
        /* Reduzierung der Spurklammererweiterung abhaengig von Relevantzeit */
        if( (    (pObjInput->iRelevant == (ubit8_t)TRUE )
              && (pObjInput->dRelSpurErweiterungsFaktor >= (LA_GENERAL_APPROX_MIN_LANE_EXTENSION_FAC - C_F32_DELTA))
            )
            || 
            (    (pObjInput->dNichtRelevantZeit > C_F32_DELTA)
              && (pObjInput->dAbst_mittel > LA_GENERAL_UR_APPROX_DISTANCE_CRIT)
            )
          )
        {
          dAblageAbstandFaktor = LA_GENERAL_UR_APPROX_FAKTOR_MIN;
        }
        else
        {
          /* Abstandsfaktor berechnen */
          dAblageAbstandFaktor = MIN_FLOAT( 1.F , pObjInput->dAbst_mittel * LA_GENERAL_UR_APPROX_ABSTAND_ERW );
        }

        /* Reduzierung der Spurklammererweiterung abhaengig von Spurkruemmung */
        dAblageKruemmungFaktor = dGDBmathLineareFunktion( &LA_AblageFaktorKruemmungUR ,  pRelTraCurve->dCurve_abs );

        /* minimale Erweiterung ermitteln */
        dOffsetReduced = LA_SEEK_APPROX_ABLAGE_ERWEITERUNG * MIN_FLOAT(dAblageKruemmungFaktor, dAblageAbstandFaktor);

        /* Reduzierung der Spurklammererweiterung abhaengig vom Trefferort des Traces */
        dAblageAppUR = dGDBmathLineareFunktion( &LA_ExtensionOffsetUR ,  fABS(pObjInput->dYIntersec) );

        /* Ermittelung der minimalen Erweiterung */
        dAblageAppUR = MIN_FLOAT( dAblageAppUR, dOffsetReduced);
      }
    }
  }
#else
  _PARAM_UNUSED(pRelTraCurve);
  _PARAM_UNUSED(pObjInput);
  _PARAM_UNUSED(dAblageAbstandFaktor);
  _PARAM_UNUSED(dOffsetReduced);
  _PARAM_UNUSED(dAblageKruemmungFaktor);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
  dOffsetResult = MAX_FLOAT(dAblageApp, dAblageAppUR);

  if (dOffsetResult > -INITVALUE_BRACKETPOSITION)
  {
    /* Spurklammerposition schreiben */
    pBracketOut->BracketPositionLeft = dOffsetResult;
  }

}
#endif


#if (LA_CFG_EXT_RELEVANT_OBJECT)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraAddExtensionRelevantObject                                                                  */ /*!

  @brief           Add relative trajectory extension for relevant object

  @description     If an object is within certain Vrel-
                   and distance limits for rel. object are the
                   expanded track boundaries towards the neighboring object
                   GERMAN:
                   Befindet sich ein Objekt innerhalb bestimmter Vrel-
                   und Abstandsgrenzen zum rel. Objekt werden die
                   Spurgrenzen in Richtung des Nachbarobjekts erweitert
                   @startuml
                    Partition LA_v_RelTraAddExtensionRelevantObject {
                    Start
                      -Get Number of left and right lanes
                       If(d Relavent track expansion factor is greater than C F32 DELTA) then (yes)
                             Repeat
                                 If(object is not neighbor object and object is moving) then (yes)
                                       If(relative velocity difference is less than or equal to LA VREL DIFF VORBEIFAHRT)
                                          -get standered difference in logitudinal displacement,object angle, life cycle t,quality and classification
                                          - Recognize the ZVS situation
                                           If(object vicinity is relavent)then (yes)
                                                 - Determine the holding time as a function of the Vrel
                                                 - For detected neighboring objects with a very short lifespan select shorter hold time
                                                 -get object life cycle
                                                                                        If(Object Life Cycles is greater than LA ZVS DETECT OBJECT LIFECYCLES MIN) then (yes)
                                                           - Take over hold time if the hold time determined is longer than the previous one
                                                     Else
                                                           - Limit the Vrel-dependent holding time to LA_ZVS_HALTEZEIT_CRIT
                                                           - Take over hold time if the hold time determined is longer than the previous one
                                                      Endif       
                                           Else
                                                -Do nothing
                                          Endif
                    
                                                                  If(ACC Quality of the object is in between 30 and 74) then (yes)
                                                                                 -Get angle difference
                                                 If(angel difference is less than or equal to 0 and passing is false)
                                                    - Passing object is to the right of the relavent  Obj
                                                    - Write track bracket position
                                                  Elseif(angel difference is greater than or equal to 0 and passing is false) then (yes)
                                                    - The passing object is to the left of the rel. Obj
                                                    - Write track bracket position
                    
                                                 Else
                                                  -do nothing
                                                 endif
                                          endif
                                       endif
                                 endif
                             Repeat while (for all valid Em objects)
                      endif
                    end
                    }
                    @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->dRelSpurErweiterungsFaktor                                        [0.0f ... 1.0f]                      
                      pObjInput->iObjNr                                                            [0 ... EM_N_OBJECTS-1]
                      pObjInput->dVrel_mittel                                                      [-330.f ... 330.f] m/s
                      pObjInput->dAbst_mittel                                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->iRelevant                                                         [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dRelevantZeit                                                     [0 .. RELEVANTZEIT_MAX]
                      pObjInput->dWinkel_m_abs                                                     [-PI … +PI] rad
                      pObjInput->dWinkel_mittel                                                    [-PI … +PI] rad
  @param[in,out]   pObjOutput : Pointer to LA_t_RelTraObjOutput. Defined in la_corridor_crit.h
                      pObjOutput->fTargetFusionHoldTime                                            [Full range of float32]
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync  : Ego velocity                                            [-330.f ... 330.f] m/s 
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i                       [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         OBJ_LONG_VREL(i) : relative velocity                                            [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : longitudinal distance                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SLATE_u_GetObjLifeCycles(i) :                                                             [AlgoCycleCounter_t as defined in Rte_Type.h]
  @glob_in         pt_LAInput->t_RTE.pb_ObjIsShadow(i):                                                               [TRUE,FALSE]      
  @glob_in         SLATE_f_GetObjectAngle(i)                                                                    [-PI … +PI] rad
  @glob_out        -

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_EXT_RELEVANT_OBJECT : Configuration switch to enable/disable relevant object extension.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/17/2016  
  @changed         2/17/2016

  @author          R. Ehrhardt
*************************************************************************************************************************/
static void LA_v_RelTraAddExtensionRelevantObject(LA_t_RelTraObjInput const *pObjInput , LA_t_RelTraObjOutput *pObjOutput , LA_t_BracketOutput *pBracketOut )
{
  boolean bVorbeifahrtLinks, bVorbeifahrtRechts; 
  float32 dAbstandDifferenz;
  float32 dWinkelDifferenz;
  float32 dVrelDifferenz;
  float32 dHaltezeitTemp;
  float32 dHaltezeit;
  AlgoCycleCounter_t u_ObjLifeCycles;
  float32 f_ObjectAngle, fEgoVelObjSync;
  float32 f_EgoCurve = fABS(*pt_LAInput->t_RTE.pf_EgoCurve);
  uint8 u_ObjBQuality; 
  ObjNumber_t i;
  boolean b_ObjIsShadow;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  AlgoCycleCounter_t t_ObjLifeCycles;
  const float32 f_dVrelMittel = pObjInput->dVrel_mittel;
  const float32 f_dAbstMittel = pObjInput->dAbst_mittel;
  const float32 f_dRelevantZeit = pObjInput->dRelevantZeit;
  float32 f_d_Winkel_m_abs = 0.0f;
  const ubit8_t b_iRelevant = pObjInput->iRelevant;
  SLATE_t_Obj_CLassification t_ObjClassification;
  float32 f_DETECT_GRENZWINKEL_RELOBJ;

  /*! Number of lanes left/right*/
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const sint8 s_NumLaneLeft = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 s_NumLaneRight = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#endif

  bVorbeifahrtLinks = FALSE;
  bVorbeifahrtRechts = FALSE;
  fEgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;

  if(pObjInput->dRelSpurErweiterungsFaktor > C_F32_DELTA)
  {
    /* Befinden sich Nachbarobjekte im Umfeld dieses Objekts */
    for (i=(EM_N_OBJECTS-1); i>=0L; i--)
    {
      t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(i);
      if( (i != pObjInput->iObjNr) && (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING))
      {
        dVrelDifferenz = fABS(*pt_LAInput->t_RTE.pf_ObjVrelX(i) - f_dVrelMittel);

        if(dVrelDifferenz <= LA_VREL_DIFF_VORBEIFAHRT)
        {
          dAbstandDifferenz = *pt_LAInput->t_RTE.pf_ObjLongDisp(i) - f_dAbstMittel;
          b_ObjIsShadow = pt_LAInput->t_RTE.pb_ObjIsShadow(i);
          t_ObjLifeCycles = SLATE_u_GetObjLifeCycles(i);
          f_ObjectAngle = SLATE_f_GetObjectAngle(i);
          f_d_Winkel_m_abs = pObjInput->dWinkel_m_abs; 
          u_ObjBQuality = SLATE_u_GetAccQuality(i);
          t_ObjClassification = *SLATE_pt_GetObjClassification(pObjInput->iObjNr);

          /* ZVS-Situation erkennen */
          f_DETECT_GRENZWINKEL_RELOBJ = LA_ZVS_DETECT_GRENZWINKEL_RELOBJ;
          if(  (f_d_Winkel_m_abs < f_DETECT_GRENZWINKEL_RELOBJ)
            && (b_iRelevant == (ubit8_t)TRUE)
            && (fEgoVelObjSync > LA_ZVS_DETECT_VEIGEN_MIN)
            && (f_dVrelMittel < LA_ZVS_DETECT_VREL_MAX)
            && (f_dVrelMittel > (-LA_ZVS_DETECT_VREL_MAX))
            && (f_dAbstMittel < LA_ZVS_DETECT_RANGE_MAX)
            && (dVrelDifferenz < LA_ZVS_DETECT_VREL_DIFF_MAX)
            && (dAbstandDifferenz < LA_ZVS_DETECT_RANGE_DIFF_MAX)
            && (dAbstandDifferenz > (-LA_ZVS_DETECT_RANGE_DIFF_MAX))
            && (b_ObjIsShadow == FALSE)
            && (f_dRelevantZeit > LA_ZVS_DETECT_OBJ_RELTIME_MIN)
            && (  (  (t_ObjLifeCycles > LA_ZVS_DETECT_OBJ_LIFECYCLES_ACTIVATE)
                  && (  (  (f_ObjectAngle <= LA_ZVS_DETECT_GRENZWINKEL_NEIGHOBJ)
                        && (f_ObjectAngle >= (-LA_ZVS_DETECT_GRENZWINKEL_NEIGHOBJ)))
                     || (  (f_ObjectAngle < -LA_ZVS_DETECT_GRENZWINKEL_NEIGHOBJ)
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
                        && (s_NumLaneRight != 0L)
#endif
                        )
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
                     || (  (f_ObjectAngle > LA_ZVS_DETECT_GRENZWINKEL_NEIGHOBJ)
#else
                     || ( (TRUE)  /* In VACC no object angle at the moment, hard driven to TRUE. TODO - Remove and replace after object angle is computed */
#endif /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
                        && (s_NumLaneLeft != 0L)
#endif
                        )
                     )
                  )
               || (pObjOutput->fTargetFusionHoldTime > C_F32_DELTA)
               )
            )
          {
            /* Haltezeit in Abhaengigkeit der Vrel ermitteln */
            dHaltezeitTemp = dGDBmathLineareFunktion(&LA_ZVSHaltezeitVrel, fABS(f_dVrelMittel));

            dHaltezeit = (float32) ROUND_TO_INT(dHaltezeitTemp); /*ROUND not needed here?!*/

            /* Bei detektierten Nachbarobjekten mit sehr geringer Lebensdauer */
            /* kuerzere Haltezeit auswaehlen */
            u_ObjLifeCycles = SLATE_u_GetObjLifeCycles(i);
            if(u_ObjLifeCycles > LA_ZVS_DETECT_OBJ_LIFECYCLES_MIN)
            {
              /* Haltezeit uebernehmen, wenn ermittelte Haltezeit groesser als bisherige */
              pObjOutput->fTargetFusionHoldTime = MAX_FLOAT(pObjOutput->fTargetFusionHoldTime, dHaltezeit);
            }
            else
            {
              /* Vrel-abhaengige Haltezeit auf LA_ZVS_HALTEZEIT_CRIT begrenzen */
              dHaltezeit = MIN_FLOAT(LA_ZVS_HALTEZEIT_CRIT, dHaltezeit);

              /* Haltezeit uebernehmen, wenn ermittelte Haltezeit groesser als bisherige */
              pObjOutput->fTargetFusionHoldTime = MAX_FLOAT(pObjOutput->fTargetFusionHoldTime, dHaltezeit);
            }
          }
          else
          {
            /* keine ZVS-Situation */
          }

          /* Extension is applied when merge and deletion of object is possible.
             Extension is likely applied in the scenarios when the below conditions are met :
             When ACC Quality of the object is <74 (likely a stable object) and >30 (likely not stable)
             For the object which is classified as truck , so that we prevent false positives
             When curve radius of the ego vehicle  is <2500 m */

          if(  (dAbstandDifferenz >= LA_ABST_DIFF_VORBEIFAHRT_NAEHER)
            && (dAbstandDifferenz <= LA_ABST_DIFF_VORBEIFAHRT_WEITER)
            && (t_ObjLifeCycles > LA_VFR_LIFECYCLES_MIN)
			      && (((u_ObjBQuality < FUN_PRESEL_ACC_HIGHEST_CLUST_VAR_OBJ_QUAL) && (u_ObjBQuality > FUN_PRESEL_ACC_STAT_OBSTACLE))
            || (t_ObjClassification == SLATE_OBJCLASS_TRUCK) || (f_EgoCurve > LA_ZVS_CURVE_RAD_MIN))
            )
          {
            dWinkelDifferenz  = SLATE_f_GetObjectAngle(i) - pObjInput->dWinkel_mittel;

            if ( (dWinkelDifferenz <= 0.F) && (bVorbeifahrtRechts == FALSE) )
            {
              /* Vorbeifahrendes Objekt liegt rechts vom rel. Obj */
              /* Rechte Begrenzung */
              /* Spurklammerposition schreiben */
              pBracketOut->BracketPositionRight = - LA_SEEKBREITE_VORBEIFAHRT;

              bVorbeifahrtRechts = TRUE;

            }
            else if( (dWinkelDifferenz >= 0.F) && (bVorbeifahrtLinks == FALSE))
            {
              /* Vorbeifahrendes Objekt liegt links vom rel. Obj */
              /* Linke Begrenzung */
              /* Spurklammerposition schreiben */
              pBracketOut->BracketPositionLeft = + LA_SEEKBREITE_VORBEIFAHRT;

              bVorbeifahrtLinks = TRUE;
            }
            else {}
          }
        }
      }
    }
  }
}
#endif


#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraAddExtensionHighspeedApproach                                                            */ /*!

  @brief           When approaching an already relevent object extend brackets.

  @description     When approaching an already relevent object extend brackets in case the trajectory is based on VDY-only (without traces/road/etc.). 
                   In this case,the trajectory shifts often and tends to loose the current relevant object.
                   @startuml
                   Partition LA_v_RelTraAddExtensionHighspeedApproach{
                   Start
                      if( relevant object and 
                        objects approaching (vrel < 1 km/h) and
                        straight curse (radius < 2000m) and
                        no lane change is detected and
                        velocity  greater than 145 km/h and
                        object is more than 90m away) then (yes)
                        - Default trace bracket extension
                            If(absolute Curve is less than MAXIMUM CURVATURE) then (yes)
                               If(number of lanes left is greater than 0)
                                   -There is a left lane, thus restrict the left trace bracket
                                   -two-segmented approach. The corridor extension is larger for objects which have a larger distance
                   
                               Endif
                           
                               if(number of lanes Right is greater than 0)
                                   -There is a left lane, thus restrict the left trace bracket
                                   -two-segmented approach. The corridor extension is larger for objects which have a larger distance
                   
                               endif
                   
                            Elseif(Curve is greater than -MAXIMUM CURVATURE INNER LANE and less than 0 and Number of Lanes Right is 0) then (yes)
                              - Stronger right curve, but we are on the right outer lane. Therefore, extend only the right trace bracket
                   
                            Elseif(Curve is greater than MAXIMUM CURVATURE INNER LANE and less than 0 and Number of Lanes Left is 0) then (yes)
                               - Stronger left curve, but we are on the left outer lane. Therefore, extend only the left trace bracket
                   
                            Else
                                - Curvature not fulfilled. Set extension to zero
                            Endif
                         
                       endif
                       -set Bracket Position Left to Extend Brackets Left
                       -set Bracket Position Right to Extend Brackets Right
                   
                    
                   end
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h 
                      pObjInput->iRelevant                                                         [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dVrel_mittel                                                      [-330.f ... 330.f] m/s
                      pObjInput->dAbst_mittel                                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesRight                                              [-1 ... 20]
                      pEnvironment->iNumberLanesLeft                                               [-1 ... 20]
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft : Factor to scale the left trace bracket.   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight : Factor to scale the right trace bracket. [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->dCurve_abs                                                     [0 … +1] m-1
                      pRelTraCurve->dCurve                                                         [-1 … +1] m^-1

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync  : Ego velocity                                            [-330.f ... 330.f] m/s 
  @glob_out        -

  @c_switch_part   Configuration switch, which moves the trace brackets based on the ego position in lane; Only active in cmbination with the camera lane interface
                      LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : In case of a lane change.
                      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : In case of no lane change
                      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : In case of the blinker feature (FCT_CFG_CUSTOM_IO_INTERFACE need to be switched on).
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_EXT_HIGHSPEED_APPROACH :Configuration switch to enable a bracket extension used for highspeed approaches.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
 
  @created         2/22/2016
  @changed         2/22/2016

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
static void LA_v_RelTraAddExtensionHighspeedApproach(LA_t_RelTraObjInput const *pObjInput, const LA_t_AssTraEnvironment *pEnvironment , LA_t_BracketOutput *pBracketOut, LA_t_RelTraCurve const *pRelTraCurve)
{
  float32 fExtendBrackets = 0.0f;
  float32 fExtendBracketsLeft, fExtendBracketsRight;
#if (!LA_CFG_USE_SIT_LANECHANGE_INFO)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  const LA_t_ScaleBracketState LC_State = pt_LAOutput->f_LA_StateScaleBracket;
#endif  /* END IF (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) */
#endif  /* END IF (!LA_CFG_USE_SIT_LANECHANGE_INFO) */
  /* only for the relevant object   */
  /* only for objects which we are (almost) approaching (vrel < 1 km/h) */
  /* only for an almost straight curse (radius < 2000m) */
  /* no lane change is detected    */
  /* only for a velocity > 145 km/h */ 
  /* object is more than 90m away   */
  if(    (pObjInput->iRelevant      == (ubit8_t)TRUE)
      && (pObjInput->dVrel_mittel   < LA_TB_EXT_MIN_VREL)
      && (pObjInput->dVrel_mittel   > LA_TB_EXT_MAX_VREL)
   /* && (pRelTraCurve->dCurve_abs  < SI_TB_EXT_MAX_CURVATURE )*/
#if (!LA_CFG_USE_SIT_LANECHANGE_INFO)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
      && ( (LC_State == SLATE_NO_LANE_CHANGE) || (LC_State == SLATE_LANE_CHANGE_UNKNOWN) )
#endif  /* END IF (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) */
#else
      && (pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_NO_LANECHANGE)
#endif  /* END IF (!LA_CFG_USE_SIT_LANECHANGE_INFO) */
      && (*pt_LAInput->t_RTE.pf_EgoVelObjSync      > LA_TB_EXT_MIN_VELOCITY)
      && (pObjInput->dAbst_mittel   > LA_TB_EXT_MIN_DIST))
  {
    
    // Default trace bracket extension
    fExtendBrackets      = dGDBmathLineareFunktion(&LA_ExtensionHighspeedApproach,pObjInput->dAbst_mittel);
    fExtendBracketsLeft  = fExtendBrackets;
    fExtendBracketsRight = -fExtendBrackets;

    if (pRelTraCurve->dCurve_abs  < LA_TB_EXT_MAX_CURVATURE )
    {
    
      // Set full extension first and then check whether we are on an outer lane
      // If neighboring lanes exist, we want to be able to detect a lane change of the
      // object earlier.
      if(pEnvironment->iNumberLanesLeft > 0 )
      {
        // There is a left lane, thus restrict the left tracebracket
        // Two-segmented approach. The corridor extension is larger for objects which have a larger distance
        if(pObjInput->dAbst_mittel > LA_TB_RB_EXT_MAX_NEAR_DIST)
        {
          fExtendBracketsLeft  =  dGDBmathLineareFunktion(&LA_ExtensionRoadBorderHighspeedApproach,pObjInput->dAbst_mittel);
        }
        else
        {
          fExtendBracketsLeft  =  dGDBmathLineareFunktion(&LA_ExtensionRoadBorderNearDistHighspeedApproach,pObjInput->dAbst_mittel);
        }
      }

      if(pEnvironment->iNumberLanesRight > 0 )
      {
        // There is a right lane, thus restrict the right tracebracket
        // Two-segmented approach. The corridor extension is larger for objects which have a larger distance
        if(pObjInput->dAbst_mittel > LA_TB_RB_EXT_MAX_NEAR_DIST)
        {
          fExtendBracketsRight = -dGDBmathLineareFunktion(&LA_ExtensionRoadBorderHighspeedApproach,pObjInput->dAbst_mittel);
        }
        else
        {
          fExtendBracketsRight = -dGDBmathLineareFunktion(&LA_ExtensionRoadBorderNearDistHighspeedApproach,pObjInput->dAbst_mittel);
        }
      }
    }
    else if(   (pRelTraCurve->dCurve > -LA_TB_EXT_MAX_CURVATURE_INNER_LANE)
            && (pRelTraCurve->dCurve < 0.0f)
            && (pEnvironment->iNumberLanesRight == 0))
    {
      /* Stronger right curve, but we are on the right outer lane. Therefore, extend only the right trace bracket */
      fExtendBracketsLeft = 0.0f;
    }
    else if(  (pRelTraCurve->dCurve < LA_TB_EXT_MAX_CURVATURE_INNER_LANE)
           && (pRelTraCurve->dCurve > 0.0f)
           && (pEnvironment->iNumberLanesLeft == 0))
    {
      /* Stronger left curve, but we are on the left outer lane. Therefore, extend only the left trace bracket */
      fExtendBracketsRight = 0.0f;
    }
    else
    {
      /* Curvature not fulfilled. Set extension to zero. */
      fExtendBracketsLeft  = 0.0f;
      fExtendBracketsRight = 0.0f;
    }

    pBracketOut->BracketPositionLeft  = fExtendBracketsLeft;
    pBracketOut->BracketPositionRight = fExtendBracketsRight;
  }
}
#endif


#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraAddExtensionHighTunnelProb                                                               */ /*!

  @brief           Extend trace brackets in tunnels

  @description     Extension used for improved robustness against drop-outs in tunnels,since trajectory fusion inputs may be not available or less stable in this environment. 
                   For a relevant object which is already held for a long time the brackets are extended.
                   @startuml
                   Partition LA_v_RelTraAddExtensionHighTunnelProb {
                   Start
                      If((tunnel probability is greater than 0.5 and trajectory hypothesis is considered and
                   object is relevant and object velocity is less than 15 km/h 
                   distance is high and no lane change is detected and velocity greater than 30 km/h and
                   object is more than 45m away)
                       -set Bracket Position Left to Extend Brackets Left
                       -set Bracket Position Right to Extend Brackets Right
                      endif
                   end
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->iRelevant                                                                [ubit8_t defined in algo_type.h] [TRUE,FALSE]
                      pObjInput->dVrel_mittel                                                             [-330.f ... 330.f] m/s
                      pObjInput->dAbst_mittel                                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pObjInput->dRelevantZeit                                                            [0 .. RELEVANTZEIT_MAX]
  @param[in,out]   pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft :                                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight                                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pRelTraCurve : Pointer to an LA_t_RelTraCurve type structure, descibes the trajectory. Defined in la_corridor_crit.h
                      pRelTraCurve->iOWVflag : Flag describing which trajectory hypothesis is considered  [ 0 or 1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync  : Ego velocity                                                   [-330.f ... 330.f] m/s 
  @glob_in         *pt_LAInput->t_RTE.pf_TunnelProbability    :Probability for a tunnel                                        [0.0f ... 1.0f]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  () : longitudinal distance                                        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   Configuration switch, which moves the trace brackets based on the ego position in lane; Only active in cmbination with the camera lane interface
                      LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : In case of a lane change.
                      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : In case of no lane change
                      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : In case of the blinker feature (FCT_CFG_CUSTOM_IO_INTERFACE need to be switched on).
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_ADD_EXT_TUNNEL_PROB : Configuration switch to enable a bracket extension used for improved robustness against drop-outs in tunnels.

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/22/2016
  @changed         2/22/2016

  @todo            Remove this entire line if not needed

  @author          Thomas Bock | Thomas.2.Bock@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
static void LA_v_RelTraAddExtensionHighTunnelProb(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut, LA_t_RelTraCurve const *pRelTraCurve)
{
  float32 fExtendBrackets = 0.0f;
  float32 fExtendBracketsLeft, fExtendBracketsRight;
  const sint32 s_iOWVflag = pRelTraCurve->iOWVflag;
  const ubit8_t b_iRelevant = pObjInput->iRelevant;
  const float32 f_dVrel_mittel = pObjInput->dVrel_mittel;
  const float32 f_objLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr);
  const float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  const float32 f_dAbst_mittel = pObjInput->dAbst_mittel;

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  const LA_t_ScaleBracketState LC_State = pt_LAOutput->f_LA_StateScaleBracket;
#endif
  
  /* only at high tunnel probability*/
  /* only for the ACC trajectory    */
  /* only for the relevant object   */
  /* only for objects with low vrel (vrel < 15 km/h) */
  /* only in high distances */
  /* no lane change is detected    */
  /* only for a velocity > 30 km/h */ 
  /* object is more than 45m away   */
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  if(    (*pt_LAInput->t_RTE.pf_TunnelProbability >= 0.5f)
      && (s_iOWVflag       == LA_OWVKRIT_AKTIV)
      && (b_iRelevant      == (ubit8_t)TRUE)
      && (f_dVrel_mittel   < LA_TUNNEL_EXT_MIN_VREL)
      && (f_objLongDisp    > LA_TUNNEL_EXT_MIN_XDIST)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
      && ( (LC_State == SLATE_NO_LANE_CHANGE) || (LC_State == SLATE_LANE_CHANGE_UNKNOWN) )
#endif
      && (f_EgoVelObjSync      > LA_TUNNEL_EXT_MIN_EGO_VELOCITY)
      && (f_dAbst_mittel       > LA_TUNNEL_EXT_MIN_OBJ_DIST))
  {
    
    /* trace bracket extension */
    fExtendBrackets      = dGDBmathLineareFunktion(&LA_ExtensionHighTunnelProb,pObjInput->dRelevantZeit);
    fExtendBracketsLeft  = fExtendBrackets;
    fExtendBracketsRight = -fExtendBrackets;

    pBracketOut->BracketPositionLeft  = fExtendBracketsLeft;
    pBracketOut->BracketPositionRight = fExtendBracketsRight;
  }
#else
  _PARAM_UNUSED(s_iOWVflag);
  _PARAM_UNUSED(b_iRelevant);
  _PARAM_UNUSED(pObjInput);
  _PARAM_UNUSED(f_dVrel_mittel);
  _PARAM_UNUSED(f_objLongDisp);
  _PARAM_UNUSED(f_EgoVelObjSync);
  _PARAM_UNUSED(f_dAbst_mittel);
  _PARAM_UNUSED(pBracketOut);
  _PARAM_UNUSED(pRelTraCurve);
  _PARAM_UNUSED(fExtendBrackets);
  _PARAM_UNUSED(fExtendBracketsLeft);
  _PARAM_UNUSED(fExtendBracketsRight);
#endif  /* END IF (FCT_CFG_SIGNAL_PERF_MONITORING) */
}
#endif

#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraAddRestrictionStatObjNextLane                                                            */ /*!

  @brief           Compute restrictions for stationary objects on neighboring lanes

  @description     Compute restrictions for stationary objects on neighboring lanes. To avoid stationary objects on next lanes
                   getting OOI status, additive restrictions are put in place. This function evaluates the criteria and computes
                   the additive restrictions where applicable
                   @startuml
                   Partition LA_v_RelTraAddRestrictionStatObjNextLane {
                   
                   Start
                        -Get lane matrix information
                        -Get Object distance to trajectory
                        If(Objects on neighboring lane but NOT oncoming and Stationary objects and Objects which STOPPED)then (yes)
                              If(Object Distance to Trajectory  is less than 0 and Number Of Right Lanes is 0)
                                - shift brackets to left
                              Elseif(Object Distance to Trajectory  is greater than 0 and Number Of Left Lanes is 0)
                                   - shift brackets to Right
                             Else
                                    -do nothing
                             endif
                        endif
                   End  
                   }
                   @enduml

  @return          static void

  @param[in]       pObjInput : Pointer to an LA_t_RelTraObjInput type structure. Updated properties of the given object, used to calculate the restriction. Defined in la_corridor_crit.h
                      pObjInput->iObjNr                                                                             [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
                      pObjInput->ucDynamicProperty                                                                  [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]

  @param[out]      pBracketOut : Pointer to an LA_t_BracketOutput type structure, describes the trace bracket adaption. Defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft :                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBracketOut->BracketPositionRight                                                             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX : Macro for accessing ACC Assessed Object List object of interest array [based on GET_FCT_PUB_OBJ_DATA_PTR]
  @glob_in         SLATE_b_GetObjIsMovingToStationary : Boolean if an stationary object was seen moving                    [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_out        None : 

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix
  @c_switch_full   LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE : Switch to enable restriction based on stationary objects in next lane
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         08.09.2015
  @changed         13.10.2015

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_RelTraAddRestrictionStatObjNextLane(LA_t_RelTraObjInput const *pObjInput, LA_t_BracketOutput *pBracketOut)
{
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(pObjInput->iObjNr);
  /* This restriction is only applied when there is no neighboring lane. Since FIP lane matrix is the default source for lanes in FCT, 
     the restriction needs FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING  */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Get lane matrix information */
  const sint8 s_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 s_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
  /* Get Object distance to trajectory */
  const float32 f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[pObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
  /*
    Apply the restriction only for 
    1. Objects on neighboring lane but NOT oncoming
    2. Stationary objects 
    3. Objects which STOPPED
  */
  if ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI) != pObjInput->iObjNr) &&
      (pObjInput->ucDynamicProperty != SLATE_OBJECT_PROPERTY_ONCOMING) && 
      ((pObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) || (b_ObjIsMovingToStationary == TRUE))
     )
  {
    if((f_ObjDist2Traj < 0.F) && (s_NumberOfRightLanes == 0)) 
    {
      /* Object on right lane, shift brackets to left */
      pBracketOut->BracketPositionRight = LA_LB_STATOBJ_NEXTLANE_SHIFT;
      pBracketOut->BracketPositionLeft = LA_LB_STATOBJ_NEXTLANE_SHIFT;
    } 
    else if ((f_ObjDist2Traj > 0.F) && (s_NumberOfLeftLanes == 0))
    {
      /* Object on left lane, shift brackets to right */
      pBracketOut->BracketPositionRight = -LA_LB_STATOBJ_NEXTLANE_SHIFT;
      pBracketOut->BracketPositionLeft = -LA_LB_STATOBJ_NEXTLANE_SHIFT;
    }
    else
    {
      /* Empty ELSE for suppressing QAC warning */
    } /* IF_ELSE_IF_ELSE to determine if the object is on right side or left side of the ACC trajectory */
  }
#endif
}
#endif  /*LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE*/
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup */
#endif
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
