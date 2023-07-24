/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_crit.h

DESCRIPTION:               This file includes all types/declarations related to use in corridor calculation
                           and adaption implementation module.

AUTHOR:                    Fridolin Kolb
                           Gergely Ungvary

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */

#ifndef SI_CORRIDOR_CRIT_EXT_INCLUDED
#define SI_CORRIDOR_CRIT_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "la.h"
#ifdef __cplusplus
extern "C" {
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup la_corridor_crit
@{ */
/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  Schnittstellen defines
*****************************************************************************/

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
OLD SA 
vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*-- SIAdReOb.c --*/

/*-- SIRelTra.c --*/
#define LA_OWVKRIT_AKTIV                            (1L)
#define LA_OWVKRIT_INAKTIV                          (0L)

/*! Flag to disable specific corridor bracket functions */
#define LA_CORR_BRACKET_FUNC_ENABLED              (TRUE)
#define LA_CORR_BRACKET_FUNC_DISABLED             (FALSE)

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
OLD SA 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*****************************************************************************
  MACROS (KOMPONENTENEXTERN)
*****************************************************************************/



/*****************************************************************************
  TYPEDEFS (KOMPONENTENEXTERN)
*****************************************************************************/
#ifndef INITVALUE_BRACKETPOSITION
#define INITVALUE_BRACKETPOSITION         (999.F)
#endif
#define LA_BRACKETPOS_VALID_VAL_COMPARE   (0.5f * INITVALUE_BRACKETPOSITION)

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
OLD SA 
vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*----------------------------------------------------------------------------
  Objekt-Strukturen Situationanalysis
----------------------------------------------------------------------------*/

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*! State to describe the lane change for the trace bracket adaptio based on the ego position in lane */
typedef enum LALaneChangeTraceBracketState
{
  LA_NO_TB_LANE_CHANGE,    /*! No lane change */
  LA_TB_LANE_CHANGE_LEFT,  /*! Lane change left */
  LA_TB_LANE_CHANGE_RIGHT  /*! Lane change right */
} LA_t_LaneChangeTraceBracketState;

#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */

typedef struct
{
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM ||\
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  LA_t_ScaleBracketOutput  RatioEgoPositionInLaneCam;            /*!< RatioEgoPositionInLaneCam */
#else
  boolean bDummy; /*!< Remove this variable if LA_t_CriteriaMatrixAllObj has more variables: struct needs at least one variable */
#endif
} LA_t_CriteriaMatrixAllObj;

typedef struct {

  /* EOBorder */
  float32 dEOBorderLeft;    /*!< When positive, the distance to the road border left */
  float32 dEOBorderRight;   /*!< When positive, the distance to the road border right*/

  /* Lane Matrix */
  sint32 iNumberLanesLeft;
  sint32 iNumberLanesRight;

  float32 dNoLaneProbL;
  float32 dNoLaneProbR;

  ObjNumber_t iRelObjNr;
  SLATE_t_Obj_DynamicProperty ucRelObjDynamicProperty;
  float32 fRelObjDistX;
  float32 fRelObjDistY;
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  float32 fRelObjTargetFusionHoldTime;
#endif
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  float32                   f_EgoObjPathDiffAvg; // is this necessary, for debug??
  float32                   f_SATrajObjPathDiffAvg; // is this necessary, for debug??
#endif
} LA_t_AssTraEnvironment;

#define LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT (!FCT_USE_EM_GENERIC_OBJECT_LIST)

typedef struct // PRQA S 635
  /* date: 2015-07-06, reviewer: Rachit Sharma, reason: Project specific type definition */
{
  ObjNumber_t               iObjNr;
  SLATE_t_Obj_DynamicProperty  ucDynamicProperty;
  uint8                     uiStoppedConfidence;
  TraceID_t                 iTracingID;
  ubit8_t                   iTraceReachedEgoVeh : 1;
  ubit8_t                   iRelevant           : 1;
  AlgoCycleCounter_t        iObjectLifeCycles;
#if LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT
  float32                   LetztZielEntfernung;
  float32                   AktZielHorizontaleAblage;
  float32                   LetztZielHorizontaleAblage;
#else
  float32                   fYPosStdDev;
#endif
  float32                   dAblage_m;
  float32                   dAbst_mittel;
  float32                   dVrel_mittel;
  float32                   dWinkel_mittel;
  float32                   dWinkel_m_abs;
  float32                   dAblageSpurGrenzeR;
  float32                   dAblageSpurGrenzeL;
  float32                   dAblage_Radius;
  float32                   dRelevantZeit;
  float32                   dNichtRelevantZeit;
  float32                   dRelSpurErweiterungsFaktor;
  float32                   dRelSpurAbstandErweitFaktor;
  float32                   dYIntersec;
  float32                   dYIntersecGradFilt;

} LA_t_RelTraObjInput;


typedef struct {

  eAssociatedLane_t iObjektSpur_Zyklus;

  sint32 iLwFolge;

  float32 dAblage_SpurGrenze_L;
  float32 dAblage_SpurGrenze_R;
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  float32 fTargetFusionHoldTime;
#endif

} LA_t_RelTraObjOutput;

/*! Structure describing the trajectory which is considered for trace bracket calculation */
typedef struct {
  float32 dCurve;       /*!< Curvature of considered trajectory for trace bracket calculation */
  float32 dCurve_abs;   /*!< Absolute curvature value of considered trajectory for trace bracket calculation */
  sint32 iOWVflag;      /*!< Flag describing which trajectory hypothesis is considered */
} LA_t_RelTraCurve;

/*! Debug structure */
#ifdef FCT_SIMU
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM ||\
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
typedef struct LADebugCriteriaMatrixAllObj
{
  boolean                           b_LaneChangeIsActive;       /*!< Info if a lane change was detected (with hysteresis) */
  LA_t_CriteriaMatrixAllObj          CriteriaMatrixAllObj;     /*!< LA_t_CriteriaMatrixAllObj -> RatioEgoPositionInLaneCam */
  LA_t_LaneChangeTraceBracketState   LaneChgTBState;           /*!< LA_t_LaneChangeTraceBracketState -> lane change state for trace bracket adaption */
} LA_t_DebugCriteriaMatrixAllObj;
#endif  /* ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM ) */
#endif /* FCT_SIMU */

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
OLD SA 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*****************************************************************************
  KONSTANTEN (KOMPONENTENEXTERN)
*****************************************************************************/
#ifdef FCT_SIMU 
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
#ifndef FCT_MEAS_ID_LA_CRITERIA_MATRIX_ALL_OBJ
#define FCT_MEAS_ID_LA_CRITERIA_MATRIX_ALL_OBJ          (0x202B3000)
#endif
#endif  /* ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM ) */
#endif /* FCT_SIMU */

#ifdef FCT_SIMU
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
#ifndef LA_CORR_NEIGHBOUR_EXT_DEBUG_VADDR
#define LA_CORR_NEIGHBOUR_EXT_DEBUG_VADDR               (0x202B3100)
#endif
#endif  /* (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ) */
#endif /* FCT_SIMU */


/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*----------------------------------------------------------------------------
  si_corridor.c
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  si_corridor_crit.c
----------------------------------------------------------------------------*/
extern void LA_v_RelTraCheckCriteriaAllObj(LA_t_CriteriaMatrixAllObj * pCriteriaMatrixAllObj);
extern void LA_v_InitCriteriaMatrixAllObj(LA_t_CriteriaMatrixAllObj * pCriteriaMatrixAllObj);

extern void LA_v_EvaluateBracketFunctions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_RelTraCurve* const pTrajectory,
                                       LA_t_AssTraEnvironment* const pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, LA_t_BracketFuncEnable* const pBracketFuncEnableFlags,
                                       const LA_t_CriteriaMatrixAllObj* const pCritMatrixAllObj);
extern void LA_v_DetermineFinalBracketPositions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, LA_t_CriteriaMatrix* const pBracketFuncResults);

/*--- si_corridor_radarroad.c ------*/
extern void LA_v_ExecuteRadarRoadBracketFunctions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_RelTraCurve* const pTrajectory,
                                               LA_t_AssTraEnvironment* const pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, const LA_t_BracketFuncEnable* const pBracketFuncEnableFlags);

/*--- si_corridor_trackwidth.c ------*/
extern void LA_v_CalculateCorridorBaseBrackets(const LA_t_RelTraObjInput* const pObjectProperties, const LA_t_RelTraCurve* const pTrajectory, LA_t_BracketOutput* const pBaseBrackets,
                                            const LA_t_BracketFuncEnable* const pBracketFuncEnableFlags);
extern void LA_v_ExecuteAdditiveBracketFunctions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_RelTraCurve* const pTrajectory,
                                              const LA_t_AssTraEnvironment *pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, const LA_t_BracketFuncEnable* const pBracketFuncEnableFlags);

/*--- si_corridor_navi.c ------*/
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
extern void LA_v_ExecuteNaviBracketFunctions(const LA_t_RelTraObjInput * pObjectProperties, LA_t_CriteriaMatrix * pBracketFuncResults, const LA_t_BracketFuncEnable * pBracketFuncEnableFlags);
#endif

#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
extern void LA_v_ExecuteCameraCorrFuntions(LA_t_RelTraObjInput const * pObjectProperties, LA_t_CriteriaMatrix * pBracketFuncResults, LA_t_BracketFuncEnable const * pBracketFuncEnableFlags);
#endif

/*--- si_corridor_scene.c ----*/
extern void LA_v_ExecuteSceneBracketFuncstions(LA_t_RelTraObjInput const * p_ObjectProperties, LA_t_AssTraEnvironment const * const p_Environment, 
  LA_t_BracketFuncEnable const * p_BracketFuncEnableFlags, LA_t_CriteriaMatrix * p_BracketFuncResults);

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
extern void LA_v_GetBlockedObstacleCorridor(void);
#endif

/*! Functions related to trace bracket adaption based on the ego position in lane */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*--- si_corridor.c ------*/
#ifdef FCT_SIMU
extern void LA_v_InitDebugStruct(void);
#endif

/*--- si_corridor_cam.c ------*/
/* Init function */
extern void LA_v_RelTraInitCriteriaOutputScale(LA_t_ScaleBracketOutput *const pOutput);

extern void LA_v_RelTraRatioEgoPositionInLaneCam(LA_t_ScaleBracketOutput *const pScaleBracketOut);
extern void LA_v_InitCorridorCamParameter(void);
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
#endif

/*--- si_corridor_cam_adapt.c ------*/
extern boolean LA_b_FindObjRelevantForTraceBracketAdaptPosInLaneCam(LA_t_RelTraObjInput const * pObj, LA_t_AssTraEnvironment const * pEnvironment, const LA_t_ScaleBracketOutput * pRatioEgoPosInLine);
extern LA_t_ScaleBracketOutput LA_t_AdaptRatioEgoPosInLaneCamToObj(LA_t_RelTraObjInput const *pObjInput, LA_t_ScaleBracketOutput const ScaleBracketIn, LA_t_AssTraEnvironment const * pEnvironment);
extern void LA_v_RelTraSetTrackWidthScale(const float32 fYPosCenterBracket, float32 *pTrackWidthLeft, float32 *pTrackWidthRight, const LA_t_ScaleBracketOutput *pScaleBracket);

#endif  /*!< ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || 
               LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || 
               LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) */

#endif /* FCT_CFG_ACC_LANE_ASSOCIATION */
/** @} end defgroup */
#endif /* END IF FCT_CFG_ACC_LANE_ASSOCIATION */

#ifdef __cplusplus
};
#endif

#endif
