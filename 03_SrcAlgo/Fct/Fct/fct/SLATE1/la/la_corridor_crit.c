/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_crit.c

DESCRIPTION:               Calculation of final ACC object corridor brackets. Different kind of trace brackets 
                           are determined based on the objects' dynamic property and the driving situation. Afterwards, 
                           a final and individual trace bracket is calculated for each object. The single trace brackets 
                           can be absolute or additive. Additionally, trace brackets are differentiated into "default" and 
                           "priority" trace brackets. "Priority" trace brackets overrule "default" trace brackets 

AUTHOR:                    Norman Apel
                           Gergely Ungvary

CREATION DATE:             09.11.2009

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.0

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
@defgroup la_corridor_crit La final Corridor
@ingroup la_corridor
@brief          Calculation of final ACC object corridor brackets for each objects. \n\n

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

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/
#define LA_MIN_DIFF_LANEBORDER_LEFT_RIGHT           (0.1f)    /*!< Minimal difference between dAblage_SpurGrenze_L and dAblage_SpurGrenze_R */

#define INIT_BRACKET_POSITION_ZERO        (0.f)

/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void LA_v_InitBrackets(LA_t_BracketOutput* const pBrackets, const float32 InitValue);
static void LA_v_ExtendBrackets(LA_t_BracketOutput* const pBrackets, const LA_t_BracketOutput* const pExtension);
static void LA_v_RestrictBrackets(LA_t_BracketOutput* const pBrackets, const LA_t_BracketOutput* const pRestriction);
static void LA_v_AddBracketPositions(LA_t_BracketOutput* const pBrackets, const LA_t_BracketOutput* const pAdditiveBrackets);

static void LA_v_ExtendAndRestrictBrackets(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_CriteriaMatrix* const pBracketFuncResults);
static void LA_v_AdjustAndCorrectFinalBrackets(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_CriteriaMatrix* const pBracketFuncResults);

static void LA_v_UpdatePreliminaryLaneAssociation(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_BracketOutput* const pBrackets);

/*! Criterias which are equal for all Objects */
static void LA_v_SetCriteriaMatrixAllObj(LA_t_CriteriaMatrix * pCriteriaMatrix, LA_t_CriteriaMatrixAllObj const * pCriteriaMatrixAllObj, LA_t_RelTraObjInput const * pObj,
                                      LA_t_AssTraEnvironment const * pEnvironment );

#if (LA_CFG_NBS_DIAGNOSE_TEST)
static void LA_v_RelTraSetTrackWidthNBS(LA_t_RelTraObjInput const *pObjInput, float32 *pTrackWidthRight, float32 *pTrackWidthLeft );
#endif


/*************************************************************************************************************************
  Functionname:    LA_v_EvaluateBracketFunctions                                                                       */ /*!

  @brief           Calculation of priority and default bracket functions

  @description     Main function for the calculation of all bracket functions comprising extensions
                   and restrictions.

				   @startuml
				   Partition LA_v_EvaluateBracketFunctions{
				   Start
				   : Get Object Moving to Stationary Info;
				   : Get Corridor Base Brackets;
				   : Get Preliminary geometric lane association;
				   If (Dynamic property of object is Moving OR Stationary) then (TRUE)
				   : Execute radar related bracket positions;
				   Else (FALSE)
				   Endif
				   : Execute scene related bracket positions;
				   : Evaluate bracket functions for stationary and moving objects;
				   End
				   }
				   @enduml

  @return          -

  @param[in]       pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
                      ucDynamicProperty : Dynamic property of object [SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
                      iObjNr : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in,out]   pObjectVariables : Pointer to output object variables [LA_t_RelTraObjOutput as defined in la_corridor_crit.h]
                      dAblage_SpurGrenze_L : Temporary storage of trace-bracket position for left-hand side  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      dAblage_SpurGrenze_R : Temporary storage of trace-bracket position for right-hand side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pTrajectory : Pointer to trajectory parameters [LA_t_RelTraCurve as defined in la_corridor_crit.h]
  @param[in,out]   pEnvironment : Pointer to auxiliary environment variables [LA_t_AssTraEnvironment as defined in la_corridor_crit.h]
  @param[in,out]   pBracketFuncResults : Pointer to preliminary results of each bracket function [LA_t_CriteriaMatrix as defined in la_corridor_crit.h]
                      pBrackets->BracketPositionLeft : Resulting trace-bracket position for left-hand side    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBrackets->BracketPositionRight : Resulting trace-bracket position for right-hand side  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pBracketFuncEnableFlags : Pointer to switches to enable/disable bracket functions [LA_t_BracketFuncEnable as defined in la_corridor_crit.h]
  @param[in]       pCritMatrixAllObj : Pointer to bracket modifications equal for all objects [LA_t_CriteriaMatrixAllObj as defined in la_corridor_crit.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple Navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION :  Configuration switch, which enables corridor extension based on camera lane object association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         25.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_EvaluateBracketFunctions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_RelTraCurve* const pTrajectory,
                                LA_t_AssTraEnvironment* const pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, LA_t_BracketFuncEnable* const pBracketFuncEnableFlags,
                                const LA_t_CriteriaMatrixAllObj* const pCritMatrixAllObj)
{
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(pObjectProperties->iObjNr);
  /* Base brackets, Seek and Track case */
  /* This needs to be evaluated first, since the resulting corridor base brackets are used within some of the bracket functions following below */
  LA_v_CalculateCorridorBaseBrackets(pObjectProperties, pTrajectory, &pBracketFuncResults->BaseCorridor, pBracketFuncEnableFlags);

  /* Preliminary geometric lane association */
  LA_v_UpdatePreliminaryLaneAssociation(pObjectProperties, pObjectVariables, &pBracketFuncResults->BaseCorridor);

  /* temporarily store BaseBracketPositions in pObjectVariables->dAblage_SpurGrenze */
  pObjectVariables->dAblage_SpurGrenze_L = pBracketFuncResults->BaseCorridor.BracketPositionLeft;
  pObjectVariables->dAblage_SpurGrenze_R = pBracketFuncResults->BaseCorridor.BracketPositionRight;

  /* Evaluate (execute) bracket functions. Resulting bracket positions for each extension and restriction are stored
     in pBracketFuncResults */
  if( (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) || 
#if (FCT_CFG_SENSOR_TYPE_RADAR)
      ((pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) && (b_ObjIsMovingToStationary == TRUE)) 
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
      (b_ObjIsMovingToStationary == TRUE)
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
    )
  {
    LA_v_ExecuteRadarRoadBracketFunctions(pObjectProperties, pObjectVariables, pTrajectory, pEnvironment, pBracketFuncResults, pBracketFuncEnableFlags);

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
    LA_v_ExecuteNaviBracketFunctions(pObjectProperties, pBracketFuncResults, pBracketFuncEnableFlags);
#endif
  } /* ONLY for Moving or Stopped objects */

  LA_v_ExecuteAdditiveBracketFunctions(pObjectProperties, pObjectVariables, pTrajectory, pEnvironment, pBracketFuncResults, pBracketFuncEnableFlags);

  /* Execute scene related bracket positions */
  LA_v_ExecuteSceneBracketFuncstions(pObjectProperties, pEnvironment, pBracketFuncEnableFlags, pBracketFuncResults);

  /* Evaluate (execute) bracket functions for stationary and moving objects */
#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
  LA_v_ExecuteCameraCorrFuntions(pObjectProperties, pBracketFuncResults, pBracketFuncEnableFlags);
#endif

  /* General corridor properties are applied to local pBracketFuncResults (adjusted to specific object) */
  LA_v_SetCriteriaMatrixAllObj(pBracketFuncResults, pCritMatrixAllObj, pObjectProperties, pEnvironment);
}


/*************************************************************************************************************************
  Functionname:    LA_v_DetermineFinalBracketPositions                                                                 */ /*!

  @brief           Determine final bracket positions

  @description     The solutions of the previously called bracket functions
                   are used to determine the final bracket position.

				   @startuml
				   Partition LA_v_DetermineFinalBracketPositions{
				   Start
				   : Determination of final bracket positions taking all (active)\n bracket functions into account;
				   : Adjustment and correction of the final bracket functions;
				   : Store FinalBracketPositions;
				   : Update preliminary lane association for the current object;
				   End
				   }
				   @enduml

  @return          void

  @param[in]       pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
  @param[in,out]   pObjectVariables : Pointer to output object variables [LA_t_RelTraObjOutput as defined in la_corridor_crit.h]
                      dAblage_SpurGrenze_L : Temporary storage of trace-bracket position for left-hand side  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      dAblage_SpurGrenze_R : Temporary storage of trace-bracket position for right-hand side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pBracketFuncResults : Pointer to bracket positions of all available bracket functions [LA_t_CriteriaMatrix as defined in la_corridor_crit.h]
                      FinalBracketPositions : Structure definition of final bracket positions [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      FinalBracketPositions.BracketPositionLeft : Resulting trace-bracket position for left-hand side    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      FinalBracketPositions.BracketPositionRight : Resulting trace-bracket position for right-hand side  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
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

  @created         25.02.2016
  @changed         25.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_DetermineFinalBracketPositions(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, LA_t_CriteriaMatrix* const pBracketFuncResults)
{
  /* Determination of final bracket positions taking all (active) bracket functions into account */
  LA_v_ExtendAndRestrictBrackets(pObjectProperties, pBracketFuncResults);

  /* Adjustment and correction of the final bracket functions for e.g. camera input or EOL test */
  LA_v_AdjustAndCorrectFinalBrackets(pObjectProperties, pBracketFuncResults);

    /* Store FinalBracketPositions in pObjectVariables->dAblage_SpurGrenze */
  pObjectVariables->dAblage_SpurGrenze_L = pBracketFuncResults->FinalBracketPositions.BracketPositionLeft;
  pObjectVariables->dAblage_SpurGrenze_R = pBracketFuncResults->FinalBracketPositions.BracketPositionRight;

  /* Update preliminary lane association for the current object.
     The lane association is now based on the resulting final brackets, contrary to relying on base brackets only. */
  LA_v_UpdatePreliminaryLaneAssociation(pObjectProperties, pObjectVariables, &pBracketFuncResults->FinalBracketPositions);
}


/*************************************************************************************************************************
  Functionname:    LA_v_ExtendAndRestrictBrackets                                                                      */ /*!

  @brief           Extend and/or Restrict the position of the final trace brackets based on certain observers.

  @description     Determine final bracket position as a function of the results of
                   the previously calculated bracket functions. These functions can extend and/or restrict
				   the position of the final trace brackets based on certain observers.
				   An extension can be additive, which means an additional offset is given to the default trace
				   bracket position. Alternatively, absolute trace bracket extensions/restrictions place the
				   trace bracket positions with respect to, for example, the roadborder or field-of-view.
				   In general, extensions and restrictions are separated into default extensions/restrictions and
				   primary extensions/restrictions. Default restrictions can only restrict default extensions. 
				   Similarly, primary extensions can only be restricted by primary restrictions and overrule the default
				   extensions/restrictions.

                   @startuml
                   Partition ExtendAndRestrictBrackets{
                   Start 
                   : Get Object is Moving to Stationary info;
                   : Get corridor base brackets;
                   If (Dynamic property of object is\n Moving OR Stationary OR Is Object Moving to Stationary) then (TRUE)
                   : Fill corridor brackets;
                   : Apply extension to bracket position;
                   If (bracket position for left is less than\n Initial value of Bracket position) then (TRUE)
                   : Get bracket position for left;
                   Else (FALSE)
                   Endif 
                   If (bracket position for right is less than\n Initial value of Bracket position) then (TRUE)
                   : Get bracket position for right;
                   Else (FALSE)
                   Endif
                   : Restricting the bracket corridor while ego lane changes;
                   : Extend and restrict bracket positions according to the results\n obtained from bracket functions;
                   Else (FALSE)
                   Endif 
                   : Execute lowspeed fused border extension;
                   If (Object is Moving to Stationary and Dynamic property is Stationary OR\n Object is Moving to Stationary and Dynamic property is Moving) then (TRUE)
                   : Restriction to bracket position considering result narrow corridor;
                   : Restriction to bracket position considering result wider corridor;
                   Else (FALSE)
                   Endif 
                   : Trace brackets for moving and stationary objects;
                   : Store final brackets;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
                      ucDynamicProperty : Dynamic property of object [SLATE_t_Obj_DynamicProperty as defined in Rte_Type.h]
  @param[in,out]   pBracketFuncResults : Pointer to preliminary results of each bracket function [LA_t_CriteriaMatrix as defined in la_corridor_crit.h]
                      BaseCorridor : Structure definition of final bracket positions [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      BaseCorridor->BracketPositionLeft : Resulting trace-bracket position for left-hand side    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      BaseCorridor->BracketPositionRight : Resulting trace-bracket position for right-hand side  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      AddExtensionRelevantObject : Trace bracket extension for the relevant object               [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      AddExtensionHighspeedApproach : Trace bracket extension for highspeed approaches           [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      AddExtensionHighTunnelProb : Trace bracket extension within tunnels                        [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      AddExtensionObjectApproximation : [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      AddRestrictionStatObjNextLane.BracketPositionLeft : Trace bracket position for left-hand side restricting the max width for 
                                                                          stat objects  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      AddRestrictionStatObjNextLane.BracketPositionRight : Trace bracket position for right-hand side restricting the max width for 
                                                                          stat objects  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      AddRestrictionCurveOuterBorder : Trace bracket restriction for the outer border in narrow curves  [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionGuardRailRoadBorder : Trace bracket extension using the guardrail                        [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionCurveInnerBorder : Trace bracket extension of the inner border in narrow curves          [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionRoadBorderCI : Trace bracket extension of the inner border using roadborder              [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionFollowObjectIntoCurve : Trace bracket extension to follow object into curve              [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionRoadBorder : Trace bracket extension using roadborder                                    [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionObjScoring : Trace bracket extension using the results of the object scoring module      [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionNeighbourhoodRelObj : Trace bracket extension for the relevant object with surrounding objects [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      AddExtensionLowSpeedFusedBrd : Trace bracket extension in low speed stop and go situations        [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      RestrictionAnalogRoadBorder : Trace bracket restriction using the roadborder                      [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      RestrictionNeighbourhoodRelObj : Trace bracket restriction for objects close to relevant object   [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      RestrictionTargetOutsideBrackets : Trace bracket restriction for a target outside currentbrackets [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      RestrictionObjectTrace : Trace bracket restriction based on the object trace for better cutouts   [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      RestrictionCityNearRange : Trace bracket restriction for near range in cities                     [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionNaviCountryroad : Trace bracket extension for navi input on countryroads                 [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      RestrictionNaviObjCloseToExit : Trace bracket restriction for navi input on countryroads          [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionCamLaneObjAssoc : Trace bracket extension based on camera lane object association        [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      ExtensionBlockedObstacleCorridor : Trace bracket extension based on a blocked path                [LA_t_BracketOutput as defined in la_corridor_crit.h]
					  FinalBracketPositions : Final corridor brackets													[LA_t_BracketOutput as defined in la_corridor_crit.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : Config switch for the relevant object trace bracket extension
  @c_switch_part   LA_CFG_EXT_HIGHSPEED_APPROACH : Config switch to enable a bracket extension used for highspeed approaches
  @c_switch_part   LA_CFG_ADD_EXT_TUNNEL_PROB : Config switch to enable a bracket extension used for improved robustness against drop-outs in tunnels
  @c_switch_part   LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE : Switch to enable restriction based on stationary objects in next lane
  @c_switch_part   LA_CFG_RESTRICTION_EGO_LANE_CHANGE : Switch to eneble restriction for ego lane change.
  @c_switch_part   LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA : Config switch for enabling road border criteria
  @c_switch_part   SIT_CFG_OBJECT_SCORING :  Configuration switch to enable object scoring module
  @c_switch_part   LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : Configuration switch to enable bracket extension used for situations in 
                                                     which the relevant object moves in the direction of a near neighboring object
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD : Extend trace brackets for low ego velocities and missing adjacent lanes
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : Configuration switch to enable restriction based on relevant object trace
  @c_switch_part   LA_CFG_RESTRICTION_CITY_NEAR_RANGE : Configuration switch to enable a restriction in the near range for country road /city scenarios 
                                                        to improve the release of objects that take a turn
  @c_switch_part   LA_CFG_NAVI_COUNTRYROAD_EXTENSION : Configuration switch enabling the trace bracket extension on country roads (based on navi information)
  @c_switch_part   LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION : Configuration switch enabling the trace bracket restriction close to an exit (based on navi information)
  @c_switch_part   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : Configuration switch, which enables corridor extension based on camera lane object association
  @c_switch_part   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : Only if FCT_CFG_COURSE_PREDICTION is ON will the blocked obstacle extension be usable
  @c_switch_part   LA_CFG_USE_ADDITIVE_CURVE_INNER_ROAD_BORDER_EXTENSION : Configuration switch to enable/disable additive Curve Road Border Extension (default mode)
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         25.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ExtendAndRestrictBrackets(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_CriteriaMatrix* const pBracketFuncResults)
{
  LA_t_BracketOutput intermediateBrackets;
  LA_t_BracketOutput AdditiveExtension;
  LA_t_BracketOutput AdditiveRestriction;
  boolean b_ObjIsMovingToStationary  = SLATE_b_GetObjIsMovingToStationary(pObjectProperties->iObjNr);

  /* Obtain corridor base brackets. These will be used in case no extensions or restrictions take effect. */
  /* This is especially the case for stationary objects. */
  intermediateBrackets = pBracketFuncResults->BaseCorridor;

  if( (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) || (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) || (b_ObjIsMovingToStationary == TRUE))
  {
    /* Superimpose the results of additive bracket functions to the base corridor brackets.
       The largest extension among all additive extensions is selected first and then added to the corridor base brackets subsequently.
       Additive restrictions are handled accordingly. */
    LA_v_InitBrackets(&AdditiveExtension, INIT_BRACKET_POSITION_ZERO);
    LA_v_InitBrackets(&AdditiveRestriction, INIT_BRACKET_POSITION_ZERO);

    /***************** RELATIVE EXTENSIONS **************************/
#if (LA_CFG_EXT_RELEVANT_OBJECT)
    LA_v_ExtendBrackets(&AdditiveExtension, &pBracketFuncResults->AddExtensionRelevantObject);
#endif
#if (LA_CFG_EXT_HIGHSPEED_APPROACH) || (LA_CFG_O2O_EGO_LANE_ASSOC_BRACKET_EXTENSION)
    LA_v_ExtendBrackets(&AdditiveExtension, &pBracketFuncResults->AddExtensionHighspeedApproach);
#endif
#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
    LA_v_ExtendBrackets(&AdditiveExtension, &pBracketFuncResults->AddExtensionHighTunnelProb);
#endif
    LA_v_ExtendBrackets(&AdditiveExtension, &pBracketFuncResults->AddExtensionObjectApproximation);
#if (LA_CFG_USE_ADDITIVE_CURVE_INNER_ROAD_BORDER_EXTENSION)
    LA_v_ExtendBrackets(&AdditiveExtension, &pBracketFuncResults->ExtensionCurveInnerBorder);
#endif /* (LA_CFG_USE_ADDITIVE_CURVE_INNER_ROAD_BORDER_EXTENSION) */
    LA_v_AddBracketPositions(&intermediateBrackets, &AdditiveExtension);

    /***************** RELATIVE DISPLACEMENT **************************/
    /* Although this is defined as a restriction, it basically shifts the corridor to one side by a predefined value in SI_LB_STATOBJ_NEXTLANE_SHIFT */
#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
    if (fABS(pBracketFuncResults->AddRestrictionStatObjNextLane.BracketPositionLeft) < INITVALUE_BRACKETPOSITION)
    {
      AdditiveRestriction.BracketPositionLeft = pBracketFuncResults->AddRestrictionStatObjNextLane.BracketPositionLeft;
    }
    if (fABS(pBracketFuncResults->AddRestrictionStatObjNextLane.BracketPositionRight) < INITVALUE_BRACKETPOSITION)
    {
      AdditiveRestriction.BracketPositionRight = pBracketFuncResults->AddRestrictionStatObjNextLane.BracketPositionRight;
    }
#endif
    /***************** RELATIVE REDUCTIONS **************************/
    /* Restricting the bracket corridor while ego lane changes */
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
    LA_v_RestrictBrackets(&AdditiveRestriction, &pBracketFuncResults->AddRestrictionEgoLaneChange);
#endif
    LA_v_RestrictBrackets(&AdditiveRestriction, &pBracketFuncResults->AddRestrictionCurveOuterBorder);
    LA_v_AddBracketPositions(&intermediateBrackets, &AdditiveRestriction);

    /* Extend and restrict bracket positions according to the results obtained from bracket functions */
    /* The priorities of extensions and restrictions are handled by the order in which they are applied. */
    /***************************************************************************************************
      The order of the functions is IMPORTANT. Take care when adding or changing the order of functions
    ****************************************************************************************************/

    /***************** DEFAULT EXTENSIONS **************************/
#if (FCT_CFG_SENSOR_TYPE_RADAR)/* Not properly filled in Video-ACC case */
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionGuardRailRoadBorder);
#endif /* FCT_CFG_SENSOR_TYPE_RADAR */
#if (LA_CFG_USE_ADDITIVE_CURVE_INNER_ROAD_BORDER_EXTENSION == SWITCH_OFF)
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionCurveInnerBorder);
#endif /* (LA_CFG_USE_ADDITIVE_CURVE_INNER_ROAD_BORDER_EXTENSION) */
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionRoadBorderCI);
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionFollowObjectIntoCurve);
#if (LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA)
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionRoadBorder);
#endif
#if (SIT_CFG_OBJECT_SCORING)
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionObjScoring);
#endif
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionNeighbourhoodRelObj);
#endif
#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionParallelLaneChange);
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD)
  }
  /* Always execute lowspeed fused border extension, also for stationary objects */
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->AddExtensionLowSpeedFusedBrd);
    if(
#if (FCT_CFG_SENSOR_TYPE_RADAR)
      ((b_ObjIsMovingToStationary) && (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY)) || 
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
      (b_ObjIsMovingToStationary) ||
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
      (pObjectProperties->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) )
  {
#endif

    /***************** DEFAULT RESTRICTIONS ************************/
    LA_v_RestrictBrackets(&intermediateBrackets, &pBracketFuncResults->RestrictionAnalogRoadBorder);
    LA_v_RestrictBrackets(&intermediateBrackets, &pBracketFuncResults->RestrictionNeighbourhoodRelObj);
    LA_v_RestrictBrackets(&intermediateBrackets, &pBracketFuncResults->RestrictionTargetOutsideBrackets);
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
    LA_v_RestrictBrackets(&intermediateBrackets, &pBracketFuncResults->RestrictionObjectTrace);
#endif
#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
    LA_v_RestrictBrackets(&intermediateBrackets, &pBracketFuncResults->RestrictionCityNearRange);
#endif

    /***************** PRIORITY EXTENSIONS *************************/
#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
    LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionNaviCountryroad);
#endif

    /***************** PRIORITY RESTRICTIONS ***********************/
#if(LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
   LA_v_RestrictBrackets(&intermediateBrackets, &pBracketFuncResults->RestrictionNaviObjCloseToExit);
#endif
  }

  /* Trace brackets for moving and stationary objects */
#if(LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
  LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionCamLaneObjAssoc);
#endif

#if(LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  LA_v_ExtendBrackets(&intermediateBrackets, &pBracketFuncResults->ExtensionBlockedObstacleCorridor);
#endif

  /* Store final brackets */
  pBracketFuncResults->FinalBracketPositions = intermediateBrackets;
}


/*************************************************************************************************************************
  Functionname:    LA_v_AdjustAndCorrectFinalBrackets                                                                  */ /*!

  @brief           Adjustment and correction of final bracket positions

  @description     Adjustment and correction of final bracket positions. During end-of-line testing, the track-width
                   is fixed in order to ensure a common behavior and prevent initialization issues. Also, camera-input
                   can be used to shift the center of the trace brackets as a function of the ego-position in lane

				   @startuml
				   Partition LA_v_AdjustAndCorrectFinalBrackets{
				   Start
				   : Get Final Brackets position;
				   : Moving the center of the Trace Brackets;
				   : Set extending trace brackets in NBS diagnosis mode;
                   If(bracket remains located to the left of the right bracket) then (TRUE)
                   : Get final brackets position for left side with\n considering right position;
                   Else (FALSE)
                   Endif 
				   End
				   }
				   @enduml

  @return          -

  @param[in]       pObjectProperties : Pointer to object properties [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
                      dAblage_Radius : Orthogonal distance of the object to the trajectory  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pBracketFuncResults : Pointer to criteria matrix [LA_t_CriteriaMatrix as defined in la_corridor_crit.h]
                      pBracketFuncResults->RatioEgoPositionInLaneCam : Struct to describe the lane change for the trace bracket adaption based on the ego position in lane
                           [SIScaleBracketOutput_t as defined in sit_criteria_crit.h]
                      pBracketFuncResults->FinalBracketPositions : Pointer to final bracket positions [LA_t_BracketOutput as defined in la_corridor_crit.h]
                          pFinalBrackets->BracketPositionLeft :  Resulting trace-bracket position for left-hand side      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          pFinalBrackets->BracketPositionRight :  Resulting trace-bracket position for right-hand side    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          
  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Adapt trace brackets in case of lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Adapt trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_part   LA_CFG_NBS_DIAGNOSE_TEST : Configuration switch for enabling NBS Diagnose Test

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.02.2016
  @changed         24.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_AdjustAndCorrectFinalBrackets(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_CriteriaMatrix* const pBracketFuncResults)
{
  LA_t_BracketOutput* const pFinalBrackets = &pBracketFuncResults->FinalBracketPositions;

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  /* Moving the center of the Trace Brackets (based on camera information of ego-position in lane) */
  LA_v_RelTraSetTrackWidthScale(pObjectProperties->dAblage_Radius, &pFinalBrackets->BracketPositionLeft, &pFinalBrackets->BracketPositionRight, &pBracketFuncResults->RatioEgoPositionInLaneCam);
#else
  _PARAM_UNUSED(pObjectProperties);
#endif

#if (LA_CFG_NBS_DIAGNOSE_TEST)
  /* NBS Spurerweiterung */
  LA_v_RelTraSetTrackWidthNBS( pObjectProperties, &pFinalBrackets->BracketPositionRight, &pFinalBrackets->BracketPositionLeft );
#endif

  /* Ensure that the left bracket remains located to the left of the right bracket */
  if( pFinalBrackets->BracketPositionLeft < pFinalBrackets->BracketPositionRight )
  {
    pFinalBrackets->BracketPositionLeft = pFinalBrackets->BracketPositionRight + LA_MIN_DIFF_LANEBORDER_LEFT_RIGHT;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_InitBrackets                                                                                   */ /*!

  @brief           Fill corridor brackets with initial values

  @description     Fill corridor brackets with initial values

                   @startuml
                   Partition LA_v_InitBrackets{
                   Start 
                   : Innitialize trace-bracket position for left-hand side\n and right-hand side;
                   End 
                   }
                   @enduml

  @return          -

  @param[in,out]   pBrackets : Pointer to bracket variable [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBrackets->BracketPositionLeft :  Resulting trace-bracket position for left-hand side       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBrackets->BracketPositionRight :  Resulting trace-bracket position for right-hand side     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       InitValue : Initial bracket position                                                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
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

  @created         25.02.2016
  @changed         25.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_InitBrackets(LA_t_BracketOutput* const pBrackets, const float32 InitValue)
{
  pBrackets->BracketPositionLeft  = - InitValue;
  pBrackets->BracketPositionRight =   InitValue;
}


/*************************************************************************************************************************
  Functionname:    LA_v_UpdatePreliminaryLaneAssociation                                                               */ /*!

  @brief           Preliminary geometric lane association

  @description     Preliminary geometric lane association to left,right, and ego lane used to decide whether 
             to calculate the trace bracket functions with an alternative trajectory hypothesis.


			 @startuml
			 Partition LA_v_UpdatePreliminaryLaneAssociation{
			 Start
			 : Initialize Preliminary lane association;
			 If (Orthogonal distance of Object to trajectory is more than\n trace-bracket position for left-hand side) then (TRUE)
			 : Update Preliminary lane association with Left Lane Association;
			 Elseif (Orthogonal distance of Object to trajectory is less than\n trace-bracket position for right-hand side) then (TRUE)
			 : Update Preliminary lane association with Right Lane Association;
			 Else (FALSE)
			 Endif
			 End
			 }
			 @enduml

  @return          -

  @param[in]       pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
                       dAblage_m : Orthogonal distance of the object to the trajectory  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pObjectVariables : Pointer to output object variables [LA_t_RelTraObjOutput as defined in la_corridor_crit.h]
                    pObjectVariables->iObjektSpur_Zyklus : Preliminary lane association [eAssociatedLane_t as defined in la_corridor_crit.h]
  @param[in]       pBrackets : Pointer to trace bracket extension [LA_t_BracketOutput as defined in la_corridor_crit.h]
                       pBrackets->BracketPositionLeft : Resulting trace-bracket position for left-hand side       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       pBrackets->BracketPositionRight : Resulting trace-bracket position for right-hand side     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
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

  @created         26.02.2016
  @changed         26.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_UpdatePreliminaryLaneAssociation(const LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables, const LA_t_BracketOutput* const pBrackets)
{
  /*! Set default */
  pObjectVariables->iObjektSpur_Zyklus = ASSOC_LANE_EGO;

  if( pObjectProperties->dAblage_m > pBrackets->BracketPositionLeft )
  {
    pObjectVariables->iObjektSpur_Zyklus = ASSOC_LANE_LEFT;
  }
  else if( pObjectProperties->dAblage_m < pBrackets->BracketPositionRight )
  {
    pObjectVariables->iObjektSpur_Zyklus = ASSOC_LANE_RIGHT;
  }
  else
  {
    /*! Else branch due to MISRA/LINT, default define before if-statement */
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_RestrictBrackets                                                                                 */ /*!

  @brief           Apply restriction to bracket position

  @description     Apply restriction to bracket position if the extension results into a more narrow corridor
 

                   @startuml
                   Partition LA_v_RestrictBrackets{
                   Start 
                   : Get trace-bracket position for left-hand side from\n minimum of left and right position;
                   : Get trace-bracket position for right-hand side from\n maximum of left and right position;
                   End 
                   }
                   @enduml

  @return          -

  @param[in,out]   pBrackets : Pointer to current bracket position [LA_t_BracketOutput as defined in la_corridor_crit.h]
                    pBrackets->BracketPositionLeft : final bracket position for left-hand side     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pBrackets->BracketPositionRight : final bracket position for right-hand side   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pRestriction : Pointer to restricted bracket position [LA_t_BracketOutput as defined in la_corridor_crit.h]
                    BracketPositionLeft : Restricted bracket position for left-hand side           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    BracketPositionRight : Restricted bracket position for right-hand side         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         -
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

  @created         25.02.2016
  @changed         25.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_RestrictBrackets(LA_t_BracketOutput* const pBrackets, const LA_t_BracketOutput* const pRestriction)
{
  pBrackets->BracketPositionLeft  = MIN_FLOAT(pBrackets->BracketPositionLeft, pRestriction->BracketPositionLeft);
  pBrackets->BracketPositionRight = MAX_FLOAT(pBrackets->BracketPositionRight, pRestriction->BracketPositionRight);
}


/*************************************************************************************************************************
  Functionname:    LA_v_ExtendBrackets                                                                                 */ /*!

  @brief           Apply extension to bracket position

  @description     Apply extension to bracket position if the extension results into a wider corridor
  

			       @startuml
                   Partition LA_v_ExtendBrackets{
                   Start 
				   : Get trace-bracket position for left-hand side from\n maximum of left and right position;
                   : Get trace-bracket position for right-hand side from\n minimum of left and right position;
				   End 
                   }
                   @enduml

  @return          -

  @param[in,out]   pBrackets : Pointer to current bracket position [LA_t_BracketOutput as defined in la_corridor_crit.h]
                    pBrackets->BracketPositionLeft : final bracket position for left-hand side     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pBrackets->BracketPositionRight : final bracket position for right-hand side   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pExtension : Pointer to extended bracket position [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      BracketPositionLeft : Extended bracket position for left-hand side           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      BracketPositionRight : Extended bracket position for right-hand side         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
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

  @created         25.02.2016
  @changed         25.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ExtendBrackets(LA_t_BracketOutput* const pBrackets, const LA_t_BracketOutput* const pExtension)
{
  pBrackets->BracketPositionLeft  = MAX_FLOAT(pBrackets->BracketPositionLeft, pExtension->BracketPositionLeft);
  pBrackets->BracketPositionRight = MIN_FLOAT(pBrackets->BracketPositionRight, pExtension->BracketPositionRight);
}

/*************************************************************************************************************************
  Functionname:    LA_v_AddBracketPositions                                                                            */ /*!

  @brief           Apply additive bracket function

  @description     The additive bracket position is added to the current position, while
                   the additive bracket position can be either positive or negative

				   @startuml
				   Partition LA_v_AddBracketPositions{
				   Start
				   : Get trace-bracket position for left-hand side\n and right-hand side;
				   End
				   }
				   @enduml

  @return          -

  @param[in,out]   pBrackets : Pointer to trace bracket extension [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pBrackets->BracketPositionLeft : Resulting trace-bracket position for left-hand side   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pBrackets->BracketPositionRight : Resulting trace-bracket position for right-hand side  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       pAdditiveBrackets : Pointer to additive trace bracket extension [LA_t_BracketOutput as defined in la_corridor_crit.h]
                      pAdditiveBrackets->BracketPositionLeft : Additive extension for left-hand side     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pAdditiveBrackets->BracketPositionRight : Additive extension for right-hand side   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
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

  @created         24.02.2016
  @changed         24.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_AddBracketPositions(LA_t_BracketOutput* const pBrackets, const LA_t_BracketOutput* const pAdditiveBrackets)
{
  pBrackets->BracketPositionLeft  = pBrackets->BracketPositionLeft  + pAdditiveBrackets->BracketPositionLeft;
  pBrackets->BracketPositionRight = pBrackets->BracketPositionRight + pAdditiveBrackets->BracketPositionRight;
}

#if (LA_CFG_NBS_DIAGNOSE_TEST)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraSetTrackWidthNBS                                                                         */ /*!

  @brief           Set extending trace brackets in NBS diagnosis mode

  @description     Set extending trace brackets in NBS diagnosis mode

                   @startuml
                   Partition LA_v_RelTraSetTrackWidthNBS{
                   Start
                   If (Function Switch Bits is Test Mode) then (TRUE)
                   : Set maximum allowed view-angle left and right for ABA EOL Test;
                   : Set right track width;
                   : Set left track width;
                   Else (FALSE)
                   : No extension of the track widths;
                   Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       *pObjInput : Pointer to input object parameters [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
                      dAbst_mittel : Longitudinal displacement of object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in,out]   *pTrackWidthRight : Right track width                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   *pTrackWidthLeft : Left track width                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         FCT_BSW_ALGO_PARAM_PTR->Fct.General.FnSwitchBits : General function switch bits [FnSwitchBits_t as defined in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_NBS_DIAGNOSE_TEST : Configuration switch for enabling NBS Diagnose Test
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.02.2016
  @changed         25.02.2016

  @author          E.Poesch, 18.07.05
*************************************************************************************************************************/
static void LA_v_RelTraSetTrackWidthNBS(LA_t_RelTraObjInput const *pObjInput, float32 *pTrackWidthRight, float32 *pTrackWidthLeft )
{
  /*--- VARIABLES ---*/
  float32 dAblage_MaxWinkel;

  /* Apply defined limits to the track widths when in ABA EOL test */
  if (FCT_BSW_ALGO_PARAM_PTR->Fct.General.FnSwitchBits == FN_AP_BIT_ABA_TEST_MODE)
  {
    /* Set maximum allowed view-angle left and right for ABA EOL Test */
    dAblage_MaxWinkel = pObjInput->dAbst_mittel * SIN_HD_(DEG2RAD(LA_NBS_MAXWINKEL));

    /* Set right track width */
    *pTrackWidthRight = MAX_FLOAT(-dAblage_MaxWinkel, LA_NBS_BRACKET_POSITION_RIGHT);

    /* Set left track width */
    *pTrackWidthLeft = MIN_FLOAT(dAblage_MaxWinkel, LA_NBS_BRACKET_POSITION_LEFT);
  }
  else
  {
    /* No extension of the track widths */
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    LA_v_RelTraCheckCriteriaAllObj                                                                      */ /*!

  @brief           Calculate the trace brackets independent of a specific object

  @description     Calculate the trace brackets independent of a specific object


                   @startuml
                   Partition LA_v_RelTraCheckCriteriaAllObj{
                   Start
                   : Adaption of trace brackets based on inlane position of ego-vehicle;
				   : Fusion with detected camera lane active;
                   End
                   }
                   @enduml

  @return          -

  @param[in,out]   pCriteriaMatrixAllObj : Pointer to a struct which aggregates all trace brackets criteria 
                   which are independent of a specific object [LA_t_CriteriaMatrixAllObj as defined in la_corridor_crit.h]
                   pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam : Struct to describe the lane change for the trace bracket adaption based on the ego position in lane
                              [SIScaleBracketOutput_t as defined in la_corridor_crit.h]
  @glob_in         CP_TrajectoryData.State.CamLaneFusion : Bit when camera lane fusion is active [0,1]
  @glob_in         CP_TrajectoryData.State.EgoCourseOnly : Bit indicating that only ego course used for trajectory (fusion off) [0,1]
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Adapt trace brackets in case of lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Adapt trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_part   CP_CFG_LANE_CHG_CAM_FUSION : Switch to enable support for camera lane fusion features  when changing lanes
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.02.2016
  @changed         25.02.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void LA_v_RelTraCheckCriteriaAllObj(LA_t_CriteriaMatrixAllObj * pCriteriaMatrixAllObj)
{
/* Adaption of trace brackets based on inlane position of ego-vehicle (camera information)
  -> active only if visibility of camera is higher than 7m (SI_MIN_CAM_COURSE_DIST) */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)

#if (CP_CFG_LANE_CHG_CAM_FUSION)
  if ((pt_LAInput->t_CP.pt_TrajectoryData->State.CamLaneFusion) && (!pt_LAInput->t_CP.pt_TrajectoryData->State.EgoCourseOnly))
  {
    /* Fusion with detected camera lane active, i.e. trace bracket adaption only if CamLaneFusion is off (reason: combination of both changes leads to a worse performance).
    As a result, CamLaneFusion is active mainly during city traffic and trace bracket adaption is active mainly on highways */
  }
  else
#endif
  {
    LA_v_RelTraRatioEgoPositionInLaneCam( &(pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam) );
  }
#else
  _PARAM_UNUSED(pCriteriaMatrixAllObj);
#endif
/* <ln_offset:+1 MISRA Rule 16.7: reviewer name: Apel date: 14-09-2012 reason: pCriteriaMatrixAllObj cannot be defined as const due to possible conflicts with implementations in other projects */
}


/*************************************************************************************************************************
  Functionname:    LA_v_InitCriteriaMatrixAllObj                                                                       */ /*!

  @brief           Initialization of pCriteriaMatrixAllObj

  @description     Initialization of the criteria (trace brackets) which are independent of a specific object


                   @startuml
                   Partition LA_v_InitCriteriaMatrixAllObj{
                   Start 
                   : Initialize Factor to scale the left trace bracket\n and right trace bracket;
                   End 
                   }
                   @enduml

  @return          void

  @param[in,out]   pCriteriaMatrixAllObj : Pointer to a struct which aggregates all trace brackets criteria 
                    which are independent of a specific object [LA_t_CriteriaMatrixAllObj as defined in sit_criteria_crit.h]
                    pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam.fScaleBracketLeft : Factor to scale the left trace bracket   
                            [INITVALUE_BRACKETPOSITION as defined in la_corridor_crit.h]
                    pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam.fScaleBracketRight : Factor to scale the right trace bracket 
                            [INITVALUE_BRACKETPOSITION as defined in la_corridor_crit.h]
  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Adapt trace brackets in case of lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Adapt trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.02.2016
  @changed         25.02.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void LA_v_InitCriteriaMatrixAllObj(LA_t_CriteriaMatrixAllObj * pCriteriaMatrixAllObj)
{
  /*! Initialization: Adaption trace brackets based on inlane position of ego-vehicle (camera information) */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
        LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
        LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam.fScaleBracketLeft = INITVALUE_BRACKETPOSITION;
  pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam.fScaleBracketRight = INITVALUE_BRACKETPOSITION;
  pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam.StateScaleBracket = SLATE_LANE_CHANGE_UNKNOWN;
#else
    _PARAM_UNUSED(pCriteriaMatrixAllObj);
#endif
  /* <ln_offset:+1 MISRA Rule 16.7: reviewer name: Apel date: 14-09-2012 reason: pCriteriaMatrixAllObj cannot be defined as const due to possible conflicts with implementations in other projects */
}


/*************************************************************************************************************************
  Functionname:    LA_v_SetCriteriaMatrixAllObj                                                                        */ /*!

  @brief           Set the trace bracket criteria which are independent for a specific object (calculated once in advance)
                   to the trace bracket criteria of each object

  @description     Set the trace bracket criteria which are independent for a specific object (calculated once in advance)
                   to the trace bracket criteria of each object

				   @startuml
				   Partition LA_v_SetCriteriaMatrixAllObj{
				   Start
				   : Adaption of trace brackets based on inlane position of ego-vehicle;
				   : Adapt the factors for the trace bracket adaption for each specific object;
				   End
				   }
				   @enduml

  @return          -

  @param[in,out]   pCriteriaMatrix : Pointer to trace bracket criteria which are dependent of a specific object [LA_t_CriteriaMatrix as defined in la_corridor_crit.h]
                      pCriteriaMatrix->RatioEgoPositionInLaneCam : Struct to describe the lane change for the trace bracket adaption based on the ego position in lane
                              [SIScaleBracketOutput_t as defined in la_corridor_crit.h]
  @param[in]       pCriteriaMatrixAllObj : Pointer to trace bracket criteria which are independent of a specific object [pCriteriaMatrixAllObj as defined in la_corridor_crit.h]
  @param[in]       pObj : Pointer to information about the specific object [LA_t_RelTraObjInput as defined in la_corridor_crit.h]
  @param[in]       pEnvironment : Pointer to information about environment (as number of lanes) [LA_t_AssTraEnvironment as defined in la_corridor_crit.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.02.2016
  @changed         26.02.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void LA_v_SetCriteriaMatrixAllObj(LA_t_CriteriaMatrix * pCriteriaMatrix, LA_t_CriteriaMatrixAllObj const * pCriteriaMatrixAllObj, LA_t_RelTraObjInput const * pObj,
                                      LA_t_AssTraEnvironment const * pEnvironment )
{
  /*! Adaption trace brackets based on inlane position of ego-vehicle (camera information) */
  #if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
        LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
        LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  /*! Test if the trace bracket adaption should be performed for the specific object */
  const boolean b_ObjRelevantForTraceBracketAdaptPosInLaneCam = LA_b_FindObjRelevantForTraceBracketAdaptPosInLaneCam(pObj, pEnvironment, &pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam);
  if( b_ObjRelevantForTraceBracketAdaptPosInLaneCam )
  {
    /*! Adapt the factors for the trace bracket adaption for each specific object */
    pCriteriaMatrix->RatioEgoPositionInLaneCam = LA_t_AdaptRatioEgoPosInLaneCamToObj(pObj, pCriteriaMatrixAllObj->RatioEgoPositionInLaneCam, pEnvironment);
  }
  else
  {
  /* no adaption*/
  }
  #else
  _PARAM_UNUSED(pCriteriaMatrixAllObj);
  _PARAM_UNUSED(pCriteriaMatrix);
  _PARAM_UNUSED(pObj);
  _PARAM_UNUSED(pEnvironment);
  #endif
  /* <ln_offset:+1 MISRA Rule 16.7: reviewer name: Apel date: 14-09-2012 reason: pCriteriaMatrixAllObj cannot be defined as const due to possible conflicts with implementations in otehr projects */
}
/** @} end defgroup */
#endif /*!< (FCT_CFG_ACC_LANE_ASSOCIATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
