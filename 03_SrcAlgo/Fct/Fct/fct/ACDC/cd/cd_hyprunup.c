/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hyprunup.c

DESCRIPTION:               Implementation of the runup hypothesis

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/09/08 11:59:02CEST $

VERSION:                   $Revision: 1.38 $

LEGACY VERSION:            Revision: 2.8

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_RUN_UP_HYPOTHESIS)
/*****************************************************************************
  MODULE DESCRIPTION 
*****************************************************************************/
/**
@defgroup cd_hyprunup HypRunUp
@ingroup cd

@brief          The Run Up Hypothesis describes a scenario in which the ego vehicle closes up to a 
                moving object that is located inside of the predicted ego trajectory.\n\n

@description    The reason for a run up can be either a existing delta velocity (Run Up Hypothesis) 
                or a deceleration of the object (Run up Braking Hypothesis). \n
                The illustration "Example Scenario Run Up" shows a Run Up after a Cut In scenario.
                @image html RunUpHyp.jpg "Example Scenario Run Up" width=400cm
                The processing of the hypothesis follows the common hypothesis calculation steps and 
                is expanded by a differentiation between Run Up and Run Up Braking. It is executed \n
                by the main external function of the module: @ref CDHypoRunUpMain. Additionally the 
                module provides a function to reset all of its internal data: @ref CDHypoRunUpInitInternalData.
@{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
#if !defined(CD_COMMON_TRACK_WIDTH_FACT)
/*! @brief       Common Track width factor
    @general     Parameter to modify ego vehicle driving path width. Use default value if not defined 
                 If non-default value is required, please define in cd_par.h and make related parameters 
                 run up, cut-in and acc track width dependent on it 
*/
#define CD_COMMON_TRACK_WIDTH_FACT      (     1.0f)
#endif

/*! @brief Value by which the time based probability is increased given enough inlap
    @typical 5 @min 0  @max 20 */
#define CD_RUN_UP_TIME_BASED_HYP_PROB_INCR  (   5    )

/*! @brief Value by which the time based probability is decreased if there is not enough inlap
    @typical 15 @min 0  @max 100 */
#define CD_RUN_UP_TIME_BASED_HYP_PROB_DECR  (  15    )

/*! @brief Maximum value for the time based probability
    @typical 100 @min 0  @max 100 */
#define CD_RUN_UP_TIME_BASED_HYP_PROB_MAX   ( 100    )

/*! @brief Threshold for the time based probability that corresponds to @ref CD_RUN_UP_INLAP_MAX_HYST
    @typical 80 @min 0  @max 100 */
#define CD_RUN_UP_CORR_HYST_PROB_MAX        (  80.0f )

/*! @brief Threshold to increase the time based probability based on the inlap
    @typical 0.35 * @ref CD_RUN_UP_TRACK_WIDTH @unit m */
#define CD_RUN_UP_MIN_OVERLAP_HYSTERESIS    ( CD_RUN_UP_TRACK_WIDTH * 0.35f )

/*! @brief Inlap value corresponding to 0% quality
    @typical 0.01 * @ref CD_RUN_UP_TRACK_WIDTH @unit m */
#define CD_RUN_UP_INLAP_MIN                 ( CD_RUN_UP_TRACK_WIDTH * 0.01f )

/*! @brief Inlap value corresponding to 100% quality if the time based prob. is 0
    @typical 0.5 * @ref CD_RUN_UP_TRACK_WIDTH @unit m */
#define CD_RUN_UP_INLAP_MAX                 ( CD_RUN_UP_TRACK_WIDTH * 0.50f )

/*! @brief Inlap value corresponding to 100% quality if the time based prob. above @ref CD_RUN_UP_CORR_HYST_PROB_MAX
    @typical 0.35 * @ref CD_RUN_UP_TRACK_WIDTH @unit m */
#define CD_RUN_UP_INLAP_MAX_HYST            ( CD_RUN_UP_TRACK_WIDTH * 0.35f )

/*! @brief Low weight for the weighted sum of current and predicted qualities
    @typical 0.2 */
#define CD_RUN_UP_HYP_PROB_WEIGHT_LOW       ( 0.2f   )

/*! @brief High weight for the weighted sum of current and predicted qualities
    @typical 0.8 */
#define CD_RUN_UP_HYP_PROB_WEIGHT_HIGH      ( 0.8f   )


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CDHypoRunUpObjectFilter(ObjNumber_t       const         iObjectIndex);

static void CDHypoRunUpCalculateProb (ObjNumber_t                      iObjectIndex, 
                                      CDIntHypothesis_t        * const pHypothesis);

static void CDHypoRunUpCalcInhibition(ObjNumber_t        const         iObjectIndex,
                                      CDIntHypothesis_t        * const pHypothesis);

#if (CD_RUN_UP_USE_NCURVE_KEEP)
static boolean CDHypRunUpDetectNarrowCurve(ObjNumber_t        const        iObjectIndex);
#endif /* #if (CD_RUN_UP_USE_NCURVE_KEEP) */


/*************************************************************************************************************************
  Functionname:         CDHypoRunUpInitInternalData                                                                  */ /*!

  @brief                Clears all data that is used for the calculation of the run up hypothesis.

  @description          Clears all data that is used for the calculation of the run up hypothesis by 
                        resetting the structure @ref CDInternalObjHypRunUpData_t.

  @return               void

  @param[in,out]        *pRunUpData : Pointer to the objects run up hypothesis internal information.
  @param[in]            bKeepIntercycleData: Flag indicating if all run up data shall be deleted (FALSE) or 
                                             only the data which is not kept over the cycles (TRUE).
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_HYPOTHESIS

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     see description

  @author               Robert Thiel | robert.thiel@continental-corporation.com

  @testmethod           @ref TEST_CDHYPORUNUPINITINTERNALDATA_001

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoRunUpInitInternalData(ObjNumber_t const iObjectIndex, 
                                 boolean     const bKeepIntercycleData)
{
  CDInternalObjHypRunUpData_t * const pRunUpData = &(ACDC_p_ModObjHypothesisData(iObjectIndex)->sHypRunUpData);

  pRunUpData->fInlapNow          = 0.f;
  pRunUpData->fInlapVarNow       = 0.f;
  pRunUpData->uInlapHypProbNow   = (percentage_t) 0uL;

  pRunUpData->fInlapTTC          = 0.f;
  pRunUpData->fInlapVarTTC       = 0.f;
  pRunUpData->uInlapHypProbTTC   = (percentage_t) 0uL;

  if(bKeepIntercycleData == b_FALSE)
  {
    pRunUpData->iTimeBasedProb   = 0;
  }
}

/*************************************************************************************************************************
  Functionname:         CDHypoRunUpObjectFilter                                                                      */ /*!

  @brief                Checks if the object is relevant for the run up hypothesis.

  @description          To pass the object filter for the Run Up Hypothesis, a object has to fulfill the 
                        following criteria:
                        - The Objects HypCat is Comoving
                        - The Object is not of class Cyclist or Pedestrian.
                        - The Objects distance to trajectory is below threshold (@ref CD_RUN_UP_MAX_LAT_DIST).
                        - The Objects dynamic property is moving or stopped and track assigned.
                        - The Objects TTC and TTB are below threshold.
                        - The Objects distance is above threshold or object was part of a RunUp or CutIn Hypothesis 
                          in the last cycle.
                        - The Objects dynamic is stationary or unknown, but it had a RunUp hypothesis calculated on 
                          it in the last cycle.

  @return               boolean: True if object is relevant for the hypothesis

  @param[in]            iObjectIndex :    Index of the considered object. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjTrajRelation\n
                        @ref ACDC_p_GetEMGenObj \n
                        @ref ACDC_p_GetObjPositions\n
                        @ref CD_f_GetTTC \n
                        @ref CD_f_GetTTBDynPre \n
                        @ref CD_f_GetTTBDynAcute \n
                        @ref CD_f_GetLongNecAccel\n
                        @ref ACDC_p_GetObjStaticEvasionData\n
                        @ref ACDC_p_GetObjHypothesisData\n
                        @ref ACDC_p_GetObjMovement
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_SENSOR_TYPE_CAMERA \n
                        @ref CD_SUPPRESS_CROSSING_STOPPED_OBJECTS \n
                        @ref FCT_CFG_SENSOR_TYPE_RADAR \n
                        @ref CD_USE_LONG_COLL_HYPOTHESIS \n
                        @ref EM_GEN_OBJECT_INTFVER
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDHYPORUNUPOBJECTFILTER_001 \n
                        @ref TEST_CDHYPORUNUPOBJECTFILTER_002 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_003 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_004 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_005 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_006 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_007 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_008 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_009 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_010 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_011 \n
						@ref TEST_CDHYPORUNUPOBJECTFILTER_012 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoRunUpObjectFilter(ObjNumber_t       const         iObjectIndex)
{
  boolean bReturn;
#if (CD_USE_LONG_COLL_HYPOTHESIS)
  boolean bObjFilter = b_TRUE;
#endif /* (CD_USE_LONG_COLL_HYPOTHESIS) */
  
  CDObj_EvasionStatic_t const * const pEvasion    = ACDC_p_GetObjStaticEvasionData(iObjectIndex);
  CDObj_Hypothesis_t    const * const pObjHypData = ACDC_p_GetObjHypothesisData(iObjectIndex);
  EM_t_GenObject        const * const pEmObj      = ACDC_p_GetEMGenObj(iObjectIndex);

  /* Allow hypothesis if
   * a) object has min. required quality and is in course
   * b) object is moving or stopped and seen for min. required cycles in track
   * c) object has min. required TTC and TTB
   * d) braking is required if object was moving before
   * e) previous run-up hypothesis is kept until long. deceleration is greater than threshold
   */ 
  const float32 fTTC          = CD_f_GetTTC(iObjectIndex);
  const float32 fTTBDynPre    = CD_f_GetTTBDynPre(iObjectIndex);
  const float32 fTTBDynAcute  = CD_f_GetTTBDynAcute(iObjectIndex);
  const float32 fLongNecAccel = CD_f_GetLongNecAccel(iObjectIndex);

 #if FCT_CFG_SENSOR_TYPE_CAMERA
  // Prevent Hypothesis drop in case of a mis-classification in OD. Note: If object stops the Hypothesis will be switched!
  const boolean bKeepHypForHypTransitionReason = (boolean)
    (    (    ( pEmObj->Attributes.eDynamicProperty             == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY )
           && ( pObjHypData->HypothesisHist.RunUpMoving         == 1u                                                                 )
           && ( pObjHypData->HypothesisHist.RunUpStationary     != 1u                                                                 ) )
      || (    ( pEmObj->Attributes.eDynamicProperty             == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN    )
           && ( pObjHypData->HypothesisHist.RunUpMoving         == 1u                                                                 ) ) );

#endif

  /* Check if the object is stopped (=> HypCat Stationary and Comoving are set)*/
  const boolean bObjIsStopped = (boolean)
                                (    (CML_GetBit(pEmObj->Qualifiers.eEbaHypCat, FPS_EBA_HYP_CAT_STAT               ) )
                                  && (( pEvasion->TrackAssigned  & (uint8)CD_RUN_UP_MIN_TRACK_ASSIGNED ) != 0u ) );

  const float32 fTmpDistToTraj = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTraj;
  const float32 fObjDistX      = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;

#if(CD_USE_LONG_COLL_HYPOTHESIS)
  if (    (pEmObj->Qualifiers.eEbaObjClass == FPS_EBA_CLASS_CYCLIST   )
       || (pEmObj->Qualifiers.eEbaObjClass == FPS_EBA_CLASS_PEDESTRIAN) )
  {
    bObjFilter = b_FALSE;
  }
#endif /* (CD_USE_LONG_COLL_HYPOTHESIS) */

  if (
#if(CD_USE_LONG_COLL_HYPOTHESIS)
          (               bObjFilter                                      == b_TRUE                                                            ) &&
#endif /* (CD_USE_LONG_COLL_HYPOTHESIS) */
          (               fABS (fTmpDistToTraj)                           <  CD_RUN_UP_MAX_LAT_DIST                                          )
       && (    (          pEmObj->Attributes.eDynamicProperty             == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING )
            || (          bObjIsStopped                                   != b_FALSE                                                         )
#if FCT_CFG_SENSOR_TYPE_CAMERA
            || (          bKeepHypForHypTransitionReason                  != b_FALSE                                                         )
#endif
                                                                                                                                             )
       && (    (          fTTC                                            <  CD_COMMON_TTC_THRES                                           )
            || (          fTTBDynPre                                      <  CD_COMMON_TTB_THRES                                           )
            || (          fTTBDynAcute                                    <  CD_COMMON_TTB_THRES                                           )
            || (    (    (fLongNecAccel                                   <  CD_RUNUP_ANECLONG_THRES                                   )
                      || (ACDC_p_GetObjMovement(iObjectIndex)->Rel.Vel.fX <  CD_RUNUP_V_REL_X_THRES                                    ) )
                 && (     pObjHypData->HypothesisHist.RunUpMoving         == (ubit16_t)1u                                                           ) ) )
       && (    (          fObjDistX                                        > CD_COMMON_MIN_DISTX                                           )
            || (          pObjHypData->HypothesisHist.RunUpMoving         == (ubit16_t)1u                                                            )
            || (          pObjHypData->HypothesisHist.RunUpStationary     == (ubit16_t)1u                                                             )
            || (          pObjHypData->HypothesisHist.CutIn               == (ubit16_t)1u                                                             ) ) )
  {
    bReturn = b_TRUE;
  }
  else
  {
    bReturn = b_FALSE;
  }
  return bReturn;
}

#if (CD_RUN_UP_USE_NCURVE_KEEP)
/*************************************************************************************************************************
  Functionname:         CDHypRunUpDetectNarrowCurve                                                                  */ /*!

  @brief                Detects whether the ego vehicle is currently driving in a narrow curve.

  @description          Prevent drop-outs during run-up hypothesis due to bad angle resolution.
                        The following criteria have to be fulfilled for a detection of a narrow curve:
                        - The TTC of the considered object is below threshold
                        - The object had a run up hypothesis in the last cycle
                        - The objects distance is below threshold
                        - The ego vehicle curvature and the objects orientation angle are above threshold.

  @return               static boolean : True if narrow curve is detected.

  @param[in]            iObjectIndex :    Pointer to CD input data. @range [0,+...[

  @glob_in              @ref ACDC_p_GetVDYDynObjSync \n
                        @ref CD_f_GetTTC \n
                        @ref ACDC_p_GetObjPositions\n
                        @ref ACDC_p_GetObjTrajRelation \n
                        @ref ACDC_p_GetObjGeometry\n
                        @ref ACDC_p_GetObjHypothesisData\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_HYPOTHESIS \n
                        @ref CD_RUN_UP_USE_NCURVE_KEEP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @todo                 Check if (pTrajRelation->fDistToTraj > CD_RUN_UP_NCURVE_DIST2TRAJ2) 
                        is correct for right and left curvature.

  @testmethod           @ref TEST_CDHYPRUNUPDETECTNARROWCURVE_001 \n
                        @ref TEST_CDHYPRUNUPDETECTNARROWCURVE_002 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_003 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_004 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_005 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_006 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_007 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_008 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_009 \n
						@ref TEST_CDHYPRUNUPDETECTNARROWCURVE_010 \n
						@

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypRunUpDetectNarrowCurve(ObjNumber_t        const        iObjectIndex)
{
  ACDCObjToTrajRelation_t const * const pTrajRelation = ACDC_p_GetObjTrajRelation(iObjectIndex);
  ACDCGeometry_t          const * const pGeometry     = ACDC_p_GetObjGeometry(iObjectIndex);
  CDObj_Hypothesis_t      const * const pObjHypData   = ACDC_p_GetObjHypothesisData(iObjectIndex);
  boolean bRet;
  const float32 fCurrentCurvature = ACDC_p_GetVDYDynObjSync()->Lateral.DrvIntCurve.Curve;
  const float32 fTTC              = CD_f_GetTTC(iObjectIndex);

  /* Optimize run-up in narrow curves, prevent drop-outs due to bad angle resolution */
  if (    (  ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX <  CD_RUN_UP_NCURVE_MAX_DIST      )
       && (                                                    fTTC <  CD_RUN_UP_NCURVE_MAX_TTC       )
       && (                 pObjHypData->HypothesisHist.RunUpMoving == 1                              )  /* only keep existing run-up hypothesis */
       && (    (    (                             fCurrentCurvature  > CD_RUN_UP_NCURVE_C0_MIN    )      /* left curve, object left */
                 && (                    pTrajRelation->fDistToTraj  > CD_RUN_UP_NCURVE_DIST2TRAJ2)
                 && (                       pGeometry->fOrientation  > CD_RUN_UP_NCURVE_ORIENT    ) )
            || (    (                             fCurrentCurvature < -CD_RUN_UP_NCURVE_C0_MIN    )      /* right curve, object right */
                 && (                    pTrajRelation->fDistToTraj  > CD_RUN_UP_NCURVE_DIST2TRAJ2)
                 && (                       pGeometry->fOrientation < -CD_RUN_UP_NCURVE_ORIENT    ) ) ) )
  {
    bRet = TRUE;
  }
  else
  {
    bRet = FALSE;
  }

  return bRet;
}
#endif


/*************************************************************************************************************************
  Functionname:         CDHypoRunUpCalculateProb                                                                     */ /*!

  @brief                Calculates the probability for the run up hypothesis

  @description          For the calculation of the hypothesis probability the current and predicted inlap of the
                        relevant object is taken into account. The prediction\ntime is given by the TTC for the
                        respective object, limited by a maximum prediction horizon @ref CD_RUN_UP_MAX_PRED_TIME.
                        
                        @startuml CDHypoRunUpCalculateProb_activity.png
                        start
                          if(Ego Vehicle is currently driving in a narrow curve \nAND Narrow Curve Feature is active?) then (Yes)
                            :1}
                            :Set prediction time to 0;
                            note left: Prevents drop out due to bad angle resolution
                          else(No)
                            :2}
                            :Limit prediciton time to a maximum 
                            of CD_RUN_UP_MAX_PRED_TIME;
                          endif
                          #Orange:Calculate the <b>current</b> inlap of 
                          the object into the ego corridor:
                          <b>CDCalculateInlapAtTime</b> >
                          note left: Based on ego corridor width,\nego curve and DistToTrajMin/Max
                          #Orange:Calculate the <b>predicted</b> inlap of 
                          the object into the ego corridor:
                          <b>CDCalculateInlapAtTime</b> >
                          note left: Based on ego corridor width,\nego curve and DistToTrajMin/Max
                          if (Are the current and predicted inlaps greater than\n the threshold value for the time based probability?) then (Yes)
                           :3}
                           :Increase time based probability;
                          else(No)
                           :4}
                           :Decrease time based probability;
                          endif
                          #Orange:Limit time based probability to a maximum of 
                          CD_RUN_UP_TIME_BASED_HYP_PROB_MAX:
                          <b>CML_MinMax</b> >
                          #Orange:Use time based probability to calculate the inlap value
                          corresponding to a hypothesis probability of 100%:
                          <b>CML_f_BoundedLinInterpol2</b> >
                          #Orange:Calculate hypothesis probability based on current inlap:
                          <b>CML_f_BoundedLinInterpol2</b> >
                          #Orange:Calculate hypothesis probability based on predicted inlap:
                          <b>CML_f_BoundedLinInterpol2</b> >
                          if (Probability for the current inlap is greater\nthan probability for the predicted inlap?) then(Yes)
                            :5} 
                            :Hypothesis probability is the weighted sum of the two probability values.
                            The higher weight is used for the probability of the predicted inlap.;
                          else (No)
                            :6} 
                            :Hypothesis probality is the weighted sum of the two probability values.
                            The higher weight is used for the probability of the current inlap.;
                          endif
                        stop
                        @enduml
                        
  @return               void

  @param[in]            iObjectIndex :            Index of the considered object. @range [0, EM_N_OBJECTS[
  @param[in,out]        pHypothesis :             Current hypothesis.  

  @glob_in              @ref ACDC_p_ModObjHypothesisData\n
                        @ref CD_f_GetTTC \n
                        @ref ACDC_p_GetVDYDynObjSync \n
                        @ref CD_f_GetTTCBrakeJerkFactor
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref CD_RUN_UP_USE_NCURVE_KEEP\n
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDHYPORUNUPCALCULATEPROB_001 \n
                        @ref TEST_CDHYPORUNUPCALCULATEPROB_002

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoRunUpCalculateProb (ObjNumber_t                      iObjectIndex,
                                      CDIntHypothesis_t        * const pHypothesis)
{
  CDObj_Hypothesis_t            * const pObjHypData   = ACDC_p_ModObjHypothesisData(iObjectIndex);
  float32 fInlapNow;
  float32 fInlapVarNow;
  float32 fInlapTTC;
  float32 fInlapVarTTC;
  float32 fCorridorWidthNow;
  float32 fCorridorWidthTTC;
  fTime_t fTTCPred               = CD_f_GetTTC(iObjectIndex);
  float32 fCurvatureAtEvalDist   = ACDC_p_GetVDYDynObjSync()->Lateral.DrvIntCurve.Curve;
  float32 fRunUpTTCCorridorWidth = CD_COMMON_TRACK_WIDTH_FACT * CML_f_CalculatePolygonValue(CD_RUN_UP_TTC_WIDTH_NO_POINTS, CD_RUN_UP_TTC_TRACK_WIDTH, fABS(fCurvatureAtEvalDist));
  float32 fReqInlapForMaxHypProb, fInlapHypProbNow, fInlapHypProbTTC;
  float32 fHypProb = 0.0f;
  sint8   iTimeBasedProb         = pObjHypData->sHypRunUpData.iTimeBasedProb;

#if (CD_RUN_UP_USE_NCURVE_KEEP)
  if (CDHypRunUpDetectNarrowCurve(iObjectIndex) != FALSE)
  {
    /* Disable predicted lane association to prevent drop-out */
    fTTCPred = 0.f;
  }
  else
#endif
  {
    fTTCPred = MIN_FLOAT(fTTCPred, CD_RUN_UP_MAX_PRED_TIME);
  }

  /* Calculate the current inlap based on standard corridor */
  fCorridorWidthNow = MAX(C_F32_DELTA,fABS(CD_RUN_UP_TRACK_WIDTH));
  CDCalculateInlapAtTime(iObjectIndex, 0.f, fCorridorWidthNow, &fInlapNow, &fInlapVarNow);

  /* Calculate the inlap at prediction time based on standard corridor */
  fCorridorWidthTTC = MAX(C_F32_DELTA,fABS(fRunUpTTCCorridorWidth));
  CDCalculateInlapAtTime(iObjectIndex, fTTCPred, fCorridorWidthTTC, &fInlapTTC, &fInlapVarTTC);

  /* Check for sufficient inlap to either increment or decrement the time based probability */
  if (    ( fInlapNow > CD_RUN_UP_MIN_OVERLAP_HYSTERESIS )
       && ( fInlapTTC > CD_RUN_UP_MIN_OVERLAP_HYSTERESIS ) )
  {
    iTimeBasedProb += CD_RUN_UP_TIME_BASED_HYP_PROB_INCR;
  }
  else
  {
    iTimeBasedProb -= CD_RUN_UP_TIME_BASED_HYP_PROB_DECR;
  }

  /* Save time based probability on object level */
  pObjHypData->sHypRunUpData.iTimeBasedProb = CML_MinMax(0, CD_RUN_UP_TIME_BASED_HYP_PROB_MAX, iTimeBasedProb);

  /************************************************************************/
  /*                Calculate hypothesis probability                      */
  /************************************************************************/
  /* Use time based probability to calculate the inlap value corresponding to a hypothesis probability of 100% */
  fReqInlapForMaxHypProb = CML_f_BoundedLinInterpol2((float32)pObjHypData->sHypRunUpData.iTimeBasedProb, 0.f, CD_RUN_UP_CORR_HYST_PROB_MAX, CD_RUN_UP_INLAP_MAX, CD_RUN_UP_INLAP_MAX_HYST);

  /* Calculate hypothesis probability at current time */
  fInlapHypProbNow = CML_f_BoundedLinInterpol2(fInlapNow, CD_RUN_UP_INLAP_MIN, fReqInlapForMaxHypProb, 0.f, 1.f);

  /* Calculate hypothesis probability at TTC */
  fInlapHypProbTTC = CML_f_BoundedLinInterpol2(fInlapTTC, CD_RUN_UP_INLAP_MIN, fReqInlapForMaxHypProb, 0.f, 1.f);

  /* Calculate overall hypothesis probability */
  if (fInlapHypProbNow > fInlapHypProbTTC)
  {
    /* Higher weighting for hypothesis probability at TTC */
    fHypProb = ((CD_RUN_UP_HYP_PROB_WEIGHT_LOW  * fInlapHypProbNow) + (CD_RUN_UP_HYP_PROB_WEIGHT_HIGH * fInlapHypProbTTC));
  }
  else
  {
    /* Higher weighting for hypothesis probability at current time */
    fHypProb = ((CD_RUN_UP_HYP_PROB_WEIGHT_HIGH * fInlapHypProbNow) + (CD_RUN_UP_HYP_PROB_WEIGHT_LOW  * fInlapHypProbTTC));
  }

  /* Enforce upper and lower bounds on the hypothesis probability */
  pHypothesis->fHypothesisProbability = CML_MinMax( 0.0f, 1.0f, fHypProb );

  /*store information in runup structure*/
  pObjHypData->sHypRunUpData.fInlapNow            = fInlapNow;
  pObjHypData->sHypRunUpData.fInlapTTC            = fInlapTTC;
  pObjHypData->sHypRunUpData.fInlapVarNow         = fInlapVarNow;
  pObjHypData->sHypRunUpData.fInlapVarTTC         = fInlapVarTTC;
  pObjHypData->sHypRunUpData.uInlapHypProbNow     = (percentage_t) ROUND_TO_UINT(fInlapHypProbNow * 100.0f);
  pObjHypData->sHypRunUpData.uInlapHypProbTTC     = (percentage_t) ROUND_TO_UINT(fInlapHypProbTTC * 100.0f);

}

/*************************************************************************************************************************
  Functionname:         CDHypoRunUpCalcInhibition                                                                  */ /*!

  @brief                Check the RunUp and RunUp-Braking inhibition conditions.

  @description          The inhibitions of diverse function reactions are determined based on the brake jerk factor.

  @return               void

  @param[in]            iObjectIndex :            Relevant object index. @range [0, @ref EM_N_OBJECTS[
  @param[in,out]        pHypothesis :             Current hypothesis.

  @glob_in              @ref CD_f_GetTTCBrakeJerkFactor \n
  @glob_out             None

  @c_switch_part        @ref CD_USE_BRAKE_JERK_TTC\n
  @c_switch_full        @ref ACDC_CFG_CD\n

  @pre                  Object index has to be valid (iObjectIndex). Object internal data needs to be valid\n
                        Hypothesis probability has to be previously calculated.
  @post                 None

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDHYPORUNUPCALCINHIBITION_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoRunUpCalcInhibition( ObjNumber_t       const         iObjectIndex,
                                       CDIntHypothesis_t       * const pHypothesis )
{
  /* Initialize inhibition mask*/
  EM_t_GenEbaInhibit  eEBAInhibitionMask   = FPS_EBA_INH_NONE;
#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
  /* Recalculate the hypothesis probability considering the brake jerk factor */
  float32 const       fBrakeJerkFactor     = CD_f_GetTTCBrakeJerkFactor(iObjectIndex);
  float32 const       fHypProbabilityJerk  = pHypothesis->fHypothesisProbability * fBrakeJerkFactor;

  /* Inhibition of PreWarn */
  if (fHypProbabilityJerk < CD_RUN_UP_INH_BRK_JRK_PREWARN_PROB_THRSHLD)
  {
    eEBAInhibitionMask |= FPS_EBA_INH_PRE_WARN;
  }
  /* Inhibition of PreFill */
  if (fHypProbabilityJerk < CD_RUN_UP_INH_BRK_JRK_PREFILL_PROB_THRSHLD)
  {
    eEBAInhibitionMask |= FPS_EBA_INH_PRE_FILL;
  }
  /* Inhibition of Acute-Warn */
  if (fHypProbabilityJerk < CD_RUN_UP_INH_BRK_JRK_ACUWARN_PROB_THRSHLD)
  {
    eEBAInhibitionMask |= FPS_EBA_INH_ACU_WARN;
  }
  /* Inhibition of Brake Level 1 */
  if (fHypProbabilityJerk < CD_RUN_UP_INH_BRK_JRK_BRK_L1_PROB_THRSHLD)
  {
    eEBAInhibitionMask |= FPS_EBA_INH_BRAKE_L1;
  }
#else
  _PARAM_UNUSED(iObjectIndex);
#endif /* CD_USE_BRAKE_JERK_TTC */

  /* Write the inhibition mask to the internal hypothesis*/
  pHypothesis->eEBAInhibitionMask = eEBAInhibitionMask;
}

#if (!CD_USE_CUSTOM_HYPOTHESIS_RUNUP)
/*************************************************************************************************************************
  Functionname:         CDHypoRunUpMain                                                                              */ /*!

  @brief                Handles the main processing steps of the run up hypothesis.

  @description          Handles the main processing steps of the run up hypothesis. As the run up hypothesis sets also 
                        the run up braking flag, these deviate from the common steps for a hypothesis generation.
                        1. Call of the Hypothesis object filter: @ref CDHypoRunUpObjectFilter
                        2. Call of the Hypothesis probability calculation: @ref CDHypoRunUpCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses
                        .
                        The following steps are executed:
                        @startuml CDHypoRunUpMain_activity.png
                        start
                          #Orange:Initialize Module data:
                          <b>CDHypoRunUpInitInternalData</b> >
                          #Orange:Check Hypothesis Object filter:
                          <b>CDHypoRunUpObjectFilter</b> >
                          if (Object Filter passed?) then (Yes)
                            #Orange:Map FPS object class to EBA Class:
                            <b>CDHypCommonMapFPSToEBAObjClass</b> >
                            #Orange:Calculate Hypothesis probability:
                            <b>CDHypoRunUpCalculateProb</b> >
                            if(Hypothesis probability > Threshold?) then (Yes)
                              if (Object is decelerating?) then (Yes)
                                :1}
                                :Set Hypothesis type to Run Up Braking;
                              else(No)
                                :2}
                                :Set Hypothesis type to Run Up;
                              endif
                              #Orange:Append hypothesis to existing ones:
                              <b>CDHypSelCreateInternalHypotheses</b> >
                            else(No)
                              :3}
                              :Reset the RunUp hypothesis history;
                              #Orange:Initialize Module data:
                              <b>CDHypoRunUpInitInternalData</b> >
                            endif
                          else(No)
                            :4}
                            :Reset the RunUp hypothesis history;
                            #Orange:Initialize Module data:
                            <b>CDHypoRunUpInitInternalData</b> >
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0,+...[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. 
                                            If FALSE reset history (if exists).
  
  @glob_in              @ref ACDC_p_GetObjMovement
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_CUSTOM_HYPOTHESIS_RUNUP \n
                        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPORUNUPMAIN_001 \n
                        @ref TEST_CDHYPORUNUPMAIN_002 \n
                        @ref TEST_CDHYPORUNUPMAIN_003 \n
                        @ref TEST_CDHYPORUNUPMAIN_004

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoRunUpMain(      ObjNumber_t  const  iObjectIndex,
                           boolean      const  bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;
  CDObj_Hypothesis_t * const pObjHypData  = ACDC_p_ModObjHypothesisData(iObjectIndex);
  /* initialize internal data */
  CDHypoRunUpInitInternalData(iObjectIndex, b_TRUE);
  /* <ln_offset:+1 PCLINT Error 778: reviewer name: Dominik Froehlich date: 15-03-2012 reason: Evaluates to zero because of hypothesis type enum. Keep for generality. */
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_RunUp);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_RunUpBraking);
  /* <ln_offset:+1 PCLINT Error 778: reviewer name: Dominik Froehlich date: 15-03-2012 reason: Evaluates to zero because of hypothesis type enum. Keep for generality. */
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_RunUp);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_RunUpBraking);
  
  /* handle only hypothesis relevant objects */
  if ( bObjFilterMatched != b_FALSE )
  { 
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart, ACDC_RTA_CD_HYP_RUNUP_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if ( CDHypoRunUpObjectFilter(iObjectIndex ) != b_FALSE)
    {
      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_No);

      /* check if object is braking and set hypothesis type accordingly */
      if ( ACDC_p_GetObjMovement(iObjectIndex)->Abs.Accel.fX < CD_RUN_UP_OBJ_DECEL_BRAKING )
      {
        Hypothesis.eType = CDHypothesisType_RunUpBraking;
        CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_RunUpBraking);
      }
      else
      {
        Hypothesis.eType = CDHypothesisType_RunUp;
        /* <ln_offset:+1 PCLINT Error 778: reviewer name: Dominik Froehlich date: 15-03-2012 reason: Evaluates to zero because of hypothesis type enum. Keep for generality. */
        CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_RunUp);
      }
      /* calculate Hypothesis probability */
      CDHypoRunUpCalculateProb(iObjectIndex, &Hypothesis);
      /* calculate Hypothesis inhibition mask */
      CDHypoRunUpCalcInhibition(iObjectIndex, &Hypothesis);
      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > CD_COMMON_MIN_HYP_PROB)
      {
        if (Hypothesis.eType == CDHypothesisType_RunUpBraking )
        {
          CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_RunUpBraking);
        }
        else
        {
          /* <ln_offset:+1 PCLINT Error 778: reviewer name: Dominik Froehlich date: 15-03-2012 reason: Evaluates to zero because of hypothesis type enum. Keep for generality. */
          CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_RunUp);
        }
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.RunUpMoving = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.RunUpMoving = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.RunUpMoving = 0u;
      CDHypoRunUpInitInternalData(iObjectIndex, b_FALSE);
    }
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_RUNUP_SINGLE, (uint8)(iObjectIndex));
  }
  else
  {
    pObjHypData->HypothesisHist.RunUpMoving = 0u;
    CDHypoRunUpInitInternalData(iObjectIndex, b_FALSE);
  }
}
#endif    /* #if (!CD_USE_CUSTOM_HYPOTHESIS_RUNUP) */
 /** \}*/
#endif    /* #if (CD_USE_RUN_UP_HYPOTHESIS) */
#endif    /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */
 
