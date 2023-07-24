/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculateoverlap.c

DESCRIPTION:               Functions for overlap calculation purpose

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 09:48:48CEST $

VERSION:                   $Revision: 1.26 $

LEGACY VERSION:            Revision: 2.6

**************************************************************************** */

#include "cd_int.h"

#if (ACDC_CFG_CD)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup cd_calculateoverlap CalculateOverlap
\ingroup cd

\brief Calculates the overlap probability of ego and object trajectory based on the Overlap now and Overlap at TTC.\n\n

The module Calculate Overlap determines the probability that the ego trajectory overlaps with the trajectory of an object.
More details can be found in the description of the only external function of the module: \ref CDCalculateProbOverlap

\{
*/

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:         CD_f_CalcEgoCorridorOccupancy                                                                */ /*!

  @brief                Calculates the current occupancy ratio of the object in relation to the ego corridor.

  @description          Calculates the current inlap of the object by calling the function @ref CDCalculateInlapAtTime 
                        for t = 0. Afterwards calculate the factor of Inlap and ego width. (see formula **Occupancy**).

  @return               float32 : Factor of the objects inlap in respect to the ego vehicle width.

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS]

  @glob_in              @ref ACDC_p_GetEgoGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n

  @pre                  None
  @post                 None

  @InOutCorrelation     - ** Occupancy:**\n
                        \f$Occupancy = \frac{Inlap}{Width_{Ego}}\f$

  @todo                 Add a get function for this value in case it is used more than once in the code.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_F_CALCEGOCORRIDOROCCUPANCY_001  COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_CalcEgoCorridorOccupancy(ObjNumber_t const iObjectIndex)
{
  float32 const fEgoWidth = ACDC_p_GetEgoGeometry()->fWidth;
  float32       fInlap;
  float32       fInlapVar;
  float32       fOccupancy;

  CDCalculateInlapAtTime(iObjectIndex, 0.f,fEgoWidth,&fInlap,&fInlapVar);

  fOccupancy = SFL_f_SafeDiv(fInlap,fEgoWidth);

  return fOccupancy;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateProbOverlap                                                                       */ /*!

  @brief                Calculates the overlap (inlap) Probability based on the Overlap now and Overlap at TTC. 
                        Both overlaps are mapped to a probability and are fused together.

  @description          The overlap probability is determined by calculating two overlap probabilities: one for 
                        the current Overlap and one for the predicted one. The probabilities are fused afterwards. \n
                        The overlap calculation is executed before the call of this function by the function @ref CDCalculateInlap.
                        @startuml CDCalculateProbOverlap_activity.png
                        start

                        :Convert Overlap at TTC
                        in a probability;
                        note left: Linear relations between\noverlap and probability

                        :Convert current Overlap
                        in a probability;
                        note left: Linear relations between\noverlap and probability

                        :Calculate Overall probability;
                        note left: > see formula "Fused Probability"
                        stop
                        @enduml

  @return               float32

  @param[in]            fTrajOverlapNow : Current overlap. @range ]-...,+...[ @phys_unit [m]
  @param[in]            fTrajOverlapTTC : Overlap at TTC.  @range ]-...,+...[ @phys_unit [m]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Fused Probability:** \n
                          \f$P_{Overlap,Fused} = 0.5 \cdot (P_{Overlap,Now} + P_{Overlap,TTC})\f$

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490

  @testmethod           @ref TEST_CDCALCULATEPROBOVERLAP_001

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CDCalculateProbOverlap( float32 fTrajOverlapNow, float32 fTrajOverlapTTC )
{
  float32 fOverlapProbNow;
  float32 fOverlapProbTTC;
  float32 fOverlapProbFused;


  /* Calculate overlap probability now based on linear function and weighting factor */
  fOverlapProbNow = CML_f_BoundedLinInterpol2(fTrajOverlapNow, 0.f, (CD_OVERLAP_WEIGHT_FAC_PROB_NOW * CD_RUN_UP_TRACK_WIDTH), 0.f, 1.f);
  /* Calculate overlap probability TTC based on linear function and weighting factor */
  fOverlapProbTTC = CML_f_BoundedLinInterpol2(fTrajOverlapTTC, 0.f, (CD_OVERLAP_WEIGHT_FAC_PROB_TTC * CD_RUN_UP_TRACK_WIDTH), 0.f, 1.f);

  /* Combine probabilities for overlap now and overlap TTC */
  fOverlapProbFused = 0.5f * (fOverlapProbNow + fOverlapProbTTC);

  return fOverlapProbFused; 
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTrajectoryOverlapNowAndPred                                                       */ /*!

  @brief                Calculates the inlap now and at a predicted time.

  @description          Calculates the current inlap and the inlap at TTC.
                        @startuml CDCalculateTrajectoryOverlapNowAndPred_activity.png
                        start
                          #Orange:Calculate the current Overlap:
                          <b>CDCalculateInlapAtTime</b> >
                        
                          :Calculate the prediction time, 
                          (limited to CD_RUN_UP_MAX_PRED_TIME);

                          #Orange:Calculate Overlap at the prediction time:
                          <b>CDCalculateInlapAtTime</b> >

                          :Subtract variance from overlaps;
                          note left: >see formula "Overlaps"
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex    : Index of the considered object. @range [0,EM_N_OBJECTS]
  @param[in,out]        pfTrajOverlapNow: Current overlap of the object and the trajectory. @phys_unit[m], @range[0,+...[
  @param[in,out]        pfTrajOverlapTTC: Overlap of the object and the trajectory at t = TTC. @phys_unit[m], @range[0,+...[

  @glob_in              @ref CD_f_GetTTC \n
                        @ref ACDC_p_GetObjMovement
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n

  @pre                  None
  @post                 None

  @InOutCorrelation    - **Overlaps:** \n
                        \f$Overlap_{Now/TTC} = Overlap_{Now/TTC} - (Variance_{Now/TTC})^2\f$


  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490

  @testmethod           @ref TEST_CDCALCULATETRAJECTORYOVERLAPNOWANDPRED_001    COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
void CDCalculateTrajectoryOverlapNowAndPred( ObjNumber_t          const           iObjectIndex,
                                             float32                    * const   pfTrajOverlapNow,
                                             float32                    * const   pfTrajOverlapTTC )
{
  SFLMovement_t const * const pObjMovementAbs = &(ACDC_p_GetObjMovement(iObjectIndex)->Abs);
  float32       fInlapNow;
  float32       fInlapVarNow;
  float32       fInlapTTC;
  float32       fInlapVarTTC;
  float32       fTTCPred        = CD_f_GetTTC(iObjectIndex);
  const float32 fTrajWidthNow   = CD_RUN_UP_TRACK_WIDTH;
  const float32 fTrajWidthTTC   = fTrajWidthNow * CML_f_CalculatePolygonValue( CD_RUN_UP_TTC_WIDTH_FAC_NO_POINTS, CD_RUN_UP_TTC_TRACK_WIDTH_WIDE, fTTCPred );
  const float32 fAbsObjVelSqr   = SQR(pObjMovementAbs->Vel.fX) + SQR(pObjMovementAbs->Vel.fY);

  CDCalculateInlapAtTime(iObjectIndex, 0.f, fTrajWidthNow, &fInlapNow, &fInlapVarNow);

  /* Limit prediction time for very slow moving objects. For objects faster than CD_RUN_UP_PRED_TIME_LIMIT_VABS_THRESH no limitation is done. */
  fTTCPred       = MIN_FLOAT(fTTCPred, CD_RUN_UP_MAX_PRED_TIME);
  fTTCPred      *= CML_f_BoundedLinInterpol2(fAbsObjVelSqr, 0.f, SQR(CD_RUN_UP_PRED_TIME_LIMIT_VABS_THRESH), CD_RUN_UP_PRED_TIME_LOW_VABS_FACT, 1.f);

  CDCalculateInlapAtTime(iObjectIndex, fTTCPred, fTrajWidthTTC, &fInlapTTC, &fInlapVarTTC);

  /* Calculate trajectory overlap now including variance */
  (*pfTrajOverlapNow) = MAX(fInlapNow - SQRT(fInlapVarNow), 0.f);
  /* Calculate trajectory overlap TTC including variance */
  (*pfTrajOverlapTTC) = MAX(fInlapTTC - SQRT(fInlapVarTTC), 0.f);
}



/*************************************************************************************************************************
  Functionname:         CDCalculateInlapAtTime                                                                       */ /*!

  @brief                Calculates the inlap of a given object into the ego trajectory at a given time.

  @description          Predicts the objects distance to the ego trajectory at a given time.
                        Afterwards calls a function to calculate the inlap at that time.
                        @startuml CDCalculateInlapAtTime_activity.png
                        start
                          #Orange:Predict the Objects Trajectory relation 
                          values to the prediciton time:
                          <b>EMPPredictTrajRelation</b> >
                          :Set the Distance, the ObjectWidth 
                          and the DistanceVar according to 
                          the predicted TrajRelation;
                          note left
                            >see Formula "Distance Pred"
                            >see Formula "ObjectWidth Pred"
                          end note
                          #Orange:Calculate the Inlap:
                          <b>CDCalculateInlap</b> >

                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex  :   Index of the considered object.
  @param[in]            fPredTime :       Prediction time at which the inlap shall be calculated. @phys_unit [s], @range ]-...,+...[
  @param[in]            fCorridorWidth :  Width of the ego corridor at the prediction time. @phys_unit [m], @range [0,+...[
  @param[in,out]        pfInlap :         Calculated Inlap. @phys_unit [m], @range [0,+...[
  @param[in,out]        pfInlapVar :      Calculated Inlap Variance. @phys_unit [m], @range [0,+...[

  @glob_in              @ref ACDC_p_GetACDCObjectMain
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Distance Pred:** \n
                          \f$D_{Pred} = 0.5 \cdot (D_{ToTrajMax, Pred} + D_{ToTrajMin, Pred})\f$
                        - **Formula ObjectWidth Pred:** \n
                          \f$ObjWidth_{Pred} = MAX(C_F32_DELTA,(D_{ToTrajMax, Pred} - D_{ToTrajMin, Pred}))\f$


  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CDCALCULATEINLAPATTIME_001 COU_TEST


  @traceability         Design Decision

*************************************************************************************************************************/
void CDCalculateInlapAtTime(ObjNumber_t  const         iObjectIndex,
                            float32                    fPredTime,
                            float32                    fCorridorWidth,
                            float32            * const pfInlap,
                            float32            * const pfInlapVar)
{
  ACDCObjDescMain_t const * const pCurrObject = ACDC_p_GetObjDescMain(iObjectIndex);
  ACDCObjToTrajRelation_t TrajRelPred;


  float32 fDistance;
  float32 fDistanceVar;
  float32 fTrajWidth      = fCorridorWidth;
  float32 fTrajWidthVar   = 0.f;
  float32 fObjectWidth;
  /* The function CDCalcGeometryVarianceFromShapePoints can be used instead of CD_CONST_OBJ_WIDTH_VAR but requires more runtime */
  float32 fObjectWidthVar = CD_CONST_OBJ_WIDTH_VAR;

  EMPPredictTrajRelation(&(pCurrObject->TrajRelation), fPredTime, &TrajRelPred);

  fDistance           = (TrajRelPred.fDistToTrajMax + TrajRelPred.fDistToTrajMin) * 0.5f;
  fObjectWidth        = MAX(C_F32_DELTA,(TrajRelPred.fDistToTrajMax - TrajRelPred.fDistToTrajMin));
  fDistanceVar        = TrajRelPred.fDistToTrajVar;

  CDCalculateInlap(fDistance,    fDistanceVar,
                   fTrajWidth,   fTrajWidthVar,
                   fObjectWidth, fObjectWidthVar,
                   pfInlap,      pfInlapVar);
}



/*************************************************************************************************************************
  Functionname:         CDCalculateInlap                                                                             */ /*!

  @brief                Calculates the Inlap value, Inlap variance, Inlap Probability of the object. 
                        These parameters are used for the Lane association. 

  @description          Calculates the Inlap value of the object with respect to the ego lane. 
                        Inlap is the distance between border of the ego corridor to the inner edge of the object. \n
                        Attention:  This function will not work for an asymmetric ego trajectory.\n
                        @startuml CDCalculateInlap_activity.png
                        start
                          :Calculate the objects Inlap;
                          note left: >see formula "Inlap"
                          :Limit the calculated Inlap to 0
                          and the ego trajectory width;
                          :Calculate the Inlap variance;
                          note left: >see formula "Inlap Variance"
                        stop
                        @enduml

  @return               void

  @param[in]            fDistance :           Distance of the trajectory and the object. @phys_unit [m], @range [0,+...[, 
  @param[in]            fDistanceVar :        Variance of the distance of the trajectory and the object. @phys_unit [m], @range [0,+...[, 
  @param[in]            fTrajectoryWidth :    Width of the trajectory. @phys_unit [m], @range ]0,+...[
  @param[in]            fTrajectoryWidthVar : Variance of the width of the trajectory. @phys_unit [m], @range ]0,+...[
  @param[in]            fObjectWidth :        Width of the object. @phys_unit [m], @range ]0,+...[
  @param[in]            fObjectWidthVar :     Variance of the width of the object. @phys_unit [m], @range ]0,+...[
  @param[in,out]        fInlap :              Inlap of the object into the trajectory. @phys_unit [m], @range [0,+...[
  @param[in,out]        fInlapVar :           Variance of the inlap of the object into the trajectory. @phys_unit [m], @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Inlap:**\n
                          \f$Inlap = \frac{|Width_{Obj}|}{2} + \frac{|Width_{Traj}|}{2} - (|Y_{ToTraj,Obj}|) \f$
                        - **Formula Inlap Variance:**\n
                          \f$Inlap_{Var} = 0.25 \cdot (Width_{Var,Obj} + Width_{Var,Traj}) + Y_{ToTraj,Var,Obj}\f$

  @author               David Stenmanns | David Stenmanns@continental-corporation.com | +49-(8382)-9699-553

  @testmethod           @ref TEST_CDCALCULATEINLAP_001 COU_TEST


  @traceability         Design Decision

*************************************************************************************************************************/
extern void CDCalculateInlap(float32 const        fDistance,
                             float32 const        fDistanceVar,
                             float32 const        fTrajectoryWidth,
                             float32 const        fTrajectoryWidthVar,
                             float32 const        fObjectWidth,
                             float32 const        fObjectWidthVar,
                             float32      * const fInlap,
                             float32      * const fInlapVar)
{
  /* take absolute value of fObjectWidth, fTrajectoryWidth and fDistance to be able to work for left and right */
  const float32 fAbsObjectWidth = CML_f_Max(fABS(fObjectWidth),     CD_MIN_OBJECT_WIDTH    );
  const float32 fAbsTrajWidth   = CML_f_Max(fABS(fTrajectoryWidth), CD_MIN_TRAJECTORY_WIDTH);
  const float32 fABSDistance    = fABS(fDistance);

  /* calculate Inlap */
  *fInlap          = ((0.5f * fAbsObjectWidth) + (0.5f * fAbsTrajWidth)) - fABSDistance;

  /* limitation of Inlap*/
  *fInlap          = CML_f_MinMax(0.f, fAbsTrajWidth, (*fInlap));

  /* calculate Inlap variance */
  *fInlapVar       = ((0.25f * fObjectWidthVar) + (0.25f * (fTrajectoryWidthVar))) + fDistanceVar;
}

///\}
#endif

