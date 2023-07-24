/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_calculation.c

DESCRIPTION:               main calculations for the EMP module

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 07:16:15CEST $

VERSION:                   $Revision: 1.40 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* EMP Includes */
#include "emp_calculation.h"

#if ( ACDC_CFG_EMP )
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup emp_calculation
@{*/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*! @brief  Threshold to consider an object stopped. Given in terms of the square of the norm of a velocity vector @typical 0.1f */
#define ACDC_EMP_VSTOP_THRES_SQR (0.1f)

/*****************************************************************************
  LOCAL FUNCTIONS
*****************************************************************************/
static float32 EMPCalcTrajOrientationAtTime( float32 fTime, ACDCTrajPred_t const * const pInTraj );
static boolean EMPCalcVariance2D(float32 fTime, ACDCTrajPred_t const * const pInTraj, SFLVector2D_t * const pOut_Var2D );
static float32 EMPCalcStdGaussianCDF2D( float32 fValueX, float32 fValueY, float32 fAver, float32 fSigmaX, float32 fSigmaY );

/*************************************************************************************************************************
  Functionname:         EMPCalcMinDistTime                                                                           */ /*!

  @brief                Calculates the time of the minimal distance between two objects based on their given trajectories.

  @description          The MinDistTime denominates the time at which the position of an object and the position 
                        of the ego vehicle are at their closest point (see illustration below). The trajectories 
                        are predicted according to their current kinematics.
                        @image html EMP_MinDistTime.svg width=1200
                        @startuml EMPCalcMinDistTime_activity.png
                        start
                          :Calculate delta velocity, acceleration 
                          and speed between objects;

                          if(Relative acceleration is low?) then (Yes)
                            if(Relative velocity is low?) then (Yes)
                              :1}
                              :MinDistTime is 0;
                            else (No)
                              :2}
                              :MinDistTime calculated over equation 
                              of motion (1st degree polynomial);
                              note right: >see Formula 1
                            endif
                          else (No)
                            :3}
                            :MinDistTime calculated over equation 
                            of motion (2nd degree polynomial);
                            note right: >see Formula 2
                          endif
                        stop
                        @enduml

  @return               boolean: True if no error occurred.

  @param[in]            *pIn_Obj1 :         Pointer of first object's tragectory.
  @param[in]            *pIn_Obj2 :         Pointer of second object's tragectory.
  @param[in,out]        *pOut_MinDistTime : Time of minimal distance between the two objects. @phys_unit [s] @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     For the calculation relative position, velocity and acceleration are calculated. \n
                        Based on these values the time of minimum distance between the trajectories if calculated by differentiation.\n
                        - **Formula 1:** Solution for relative acceleration = 0
                          1. Equations of motion (relative velocities and positions): \n
                             \f$ V_x \cdot t + X\f$\n
                             \f$ V_y \cdot t + Y\f$
                          2. Formula for distance between objects:\n
                             \f$ \sqrt{(V_x \cdot t + X)^2 + (V_y \cdot t + Y)^2} \f$
                          3. Find distance minimum by differentiating term under the square root: \n
                             \f$ 2t \cdot (V_x^2+V_y^2) + 2 \cdot XV_x +2YV_y = 0\f$
                          4. Calculate time at distance minimum: \n
                             \f$ t=-\frac{XV_x+YV_y}{V_x^2+V_y^2}\f$
                          .
                        - **Formula 2:** Solution under consideration of all motion attributes
                          1. Equations of motion (relative accelerations, velocities and positions):\n
                            \f$ X + V_x \cdot t + 0.5A_x \cdot t^2\f$ \n
                            \f$ Y + V_y \cdot t + 0.5A_y \cdot t^2\f$
                          2. Formula for distance between objects:\n
                            \f$ \sqrt{(X + V_x \cdot t + \frac{1}{2}A_x \cdot t^2)^2 + (Y + V_y \cdot t + \frac{1}{2}A_y \cdot t^2)^2} \f$
                          3. Find distance minimum by differentiating term under the square root: \n
                            \f$(a:)\f$  \f$ t^3 \cdot 4 \cdot ((\frac{1}{2}A_x)^2+(\frac{1}{2}A_y)^2) +                      \f$ \n
                            \f$(b:)\f$  \f$ t^2 \cdot 6 \cdot (V_x \cdot \frac{1}{2}A_x + V_y \cdot \frac{1}{2}A_y) +        \f$ \n
                            \f$(c:)\f$  \f$ t   \cdot 2 \cdot (V_x^2+V_y^2+2X\cdot(\frac{1}{2}A_x)+2Y\cdot(\frac{1}{2}A_y) + \f$ \n
                            \f$(d:)\f$  \f$ 1   \cdot 2 \cdot (XV_x+YV_y)                                                    \f$
                          4. Solve the polynomial by applying the *Cardano Formula*:\n
                            Assume a polynomial of the form \f$ax^3 + bx^2 + cx + d = 0\f$, whereas in the current case \f$t = x\f$\n
                            \f$ Q = \frac{3ac-b^2}{9a^2}\f$             \n
                            \f$ R = \frac{9abc-27a^2d-2b^3}{54a^3}\f$   \n
                            Discriminant: \f$ D = Q^3 + R^2\f$ \n
                            - **Case 1: D > 0** => Only one root is real, two are complex conjugates: \n
                              \f$ S = \sqrt[3]{R + \sqrt{Q^3+R^2}} \f$ \n
                              \f$ T = \sqrt[3]{R - \sqrt{Q^3+R^2}} \f$ \n
                              \f$ t = S + T -\frac{b}{3a}\f$ \n
                            - **Case 2: D < 0** => All three roots are real: \n
                              \f$ t_1 = 2\cdot \sqrt{-Q}\cdot\cos{(\frac{R}{3\sqrt-Q^3})}-\frac{b}{3a}\f$ \n
                              \f$ t_2 = 2\cdot \sqrt{-Q}\cdot\cos{(\frac{R}{3\sqrt-Q^3}+\frac{2\pi}{3})}-\frac{b}{3a}\f$ \n
                              \f$ t_3 = 2\cdot \sqrt{-Q}\cdot\cos{(\frac{R}{3\sqrt-Q^3}+\frac{4\pi}{3})}-\frac{b}{3a}\f$ \n
                          5. If several solutions are found, discard all negative ones and choose the time for which the 
                             smallest distance is found.

  @testmethod           @ref TEST_EMPCALCMINDISTTIME_001 \n
                        @ref TEST_EMPCALCMINDISTTIME_002 \n
                        @ref TEST_EMPCALCMINDISTTIME_003 \n
						@ref TEST_EMPCALCMINDISTTIME_004 \n
                        @ref TEST_EMPCALCMINDISTTIME_005 \n
                        @ref TEST_EMPCALCMINDISTTIME_006 \n
						@ref TEST_EMPCALCMINDISTTIME_007

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
boolean EMPCalcMinDistTime(ACDCTrajPred_t const *const pIn_Obj1, 
                           ACDCTrajPred_t const *const pIn_Obj2, 
                           float32             *const pOut_MinDistTime )
{
  boolean bResultOK = b_FALSE;

  const float32 fC2Limit = 0.1f;
  const float32 fC1Limit = 0.1f;

  float32 fC2RelX = pIn_Obj1->XofT.fC2 - pIn_Obj2->XofT.fC2;
  float32 fC1RelX = pIn_Obj1->XofT.fC1 - pIn_Obj2->XofT.fC1;
  float32 fC0RelX = pIn_Obj1->XofT.fC0 - pIn_Obj2->XofT.fC0;
  
  float32 fC2RelY = pIn_Obj1->YofT.fC2 - pIn_Obj2->YofT.fC2;
  float32 fC1RelY = pIn_Obj1->YofT.fC1 - pIn_Obj2->YofT.fC1;
  float32 fC0RelY = pIn_Obj1->YofT.fC0 - pIn_Obj2->YofT.fC0;

  float32 fC2RelXSq = fC2RelX * fC2RelX;
  float32 fC2RelYSq = fC2RelY * fC2RelY;
  float32 fC1RelXSq = fC1RelX * fC1RelX;
  float32 fC1RelYSq = fC1RelY * fC1RelY;

  const float32 fAbsC2RelX = fABS(fC2RelX);
  const float32 fAbsC2RelY = fABS(fC2RelY);
  const float32 fAbsC1RelX = fABS(fC1RelX);
  const float32 fAbsC1RelY = fABS(fC1RelY);

  *pOut_MinDistTime = 0.0f;

  if (fAbsC2RelX < fC2Limit)
  {
    fC2RelX   = 0.0f;
    fC2RelXSq = 0.0f;
  }
  if (fAbsC1RelX < fC1Limit)
  {
    fC1RelX   = 0.0f;
    fC1RelXSq = 0.0f;
  }
  if (fAbsC2RelY < fC2Limit)
  {
    fC2RelY   = 0.0f;
    fC2RelYSq = 0.0f;
  }
  if (fAbsC1RelY < fC1Limit)
  {
    fC1RelY   = 0.0f;
    fC1RelYSq = 0.0f;
  }

  if ( (fAbsC2RelX < fC2Limit) && (fAbsC2RelY < fC2Limit) )
  {
    /* Both Object have the same Acceleration */
    if ( (fAbsC1RelX < fC1Limit) && (fAbsC1RelY < fC1Limit) )
    {
      /* Both Objects have the same Velocity */
      *pOut_MinDistTime = 0.0f;
      bResultOK         = b_TRUE;
    }
    else
    {
      const float32 fPC1 = 2.0f * (fC1RelXSq + fC1RelYSq);
      const float32 fPC0 = 2.0f * ((fC1RelX*fC0RelX) + (fC1RelY*fC0RelY));

      *pOut_MinDistTime = (-1.0f) * (fPC0 / fPC1);
      bResultOK         = b_TRUE;
    }
  } 
  else
  {
    const float32 fPC3 = 4.0f * (fC2RelXSq + fC2RelYSq);
    const float32 fPC2 = 6.0f * ((fC2RelX*fC1RelX) + (fC2RelY*fC1RelY));
    const float32 fPC1 = 2.0f * ((2.0f*fC2RelX*fC0RelX) + (2.0f*fC2RelY*fC0RelY) + fC1RelXSq + fC1RelYSq);
    const float32 fPC0 = 2.0f * ((fC1RelX*fC0RelX) + (fC1RelY*fC0RelY));

    const float32 fPC3Sq = fPC3 * fPC3;
    const float32 fPC2Sq = fPC2 * fPC2;
    const float32 fPC3Cu = fPC3Sq * fPC3;
    const float32 fPC2Cu = fPC2Sq * fPC2;

    const float32 fQ   = ((3.0f*fPC3*fPC1) - fPC2Sq)/(9.0f*fPC3Sq);
    const float32 fR   = ((9.0f*fPC3*fPC2*fPC1) - (27.0f*fPC3Sq*fPC0) - (2.0f*fPC2Cu))/(54.0f*fPC3Cu);
    const float32 fQCu = fQ * fQ * fQ;
    const float32 fRSQ = fR * fR;
    const float32 fD   = fQCu + fRSQ;

    if ( fD > CML_f_AlmostZero )
    {
      const float32 fSqrtD = SQRT(fD);
      const float32 fS  = SFL_f_CalcCubeRoot(fR + fSqrtD);
      const float32 fT  = SFL_f_CalcCubeRoot(fR - fSqrtD);
      *pOut_MinDistTime = (fS + fT) - (fPC2/(3.0f*fPC3));
      bResultOK         = b_TRUE;
    } 
    else if (   (fD < -CML_f_AlmostZero) 
             && (fABS(fQCu) > CML_f_AlmostZero) )  /* catch potential div/0 */
    {
      sint32  iCurrMinTimeID;
      sint32  iMinTimeGlobalID = -1;
      float32 fMinDistGlobal = 999.f;
      const float32 fSqrtQCuNeg = SQRT((-1.0f)*fQCu);
      const float32 fPhi = ACOS_(fR / fSqrtQCuNeg);

      float32 fMinTimes[3] = { 0.0f, 0.0f, 0.0f };
      const float32 fSqrtQNeg = SQRT((-1.0f)*fQ);

      fMinTimes[0] = (2.0f * fSqrtQNeg * COS_(fPhi/3.0f)) - ((fPC2)/(3.0f * fPC3));
      fMinTimes[1] = (2.0f * fSqrtQNeg * COS_((fPhi/3.0f) + ((2.0f*C_PI)/(3.0f)))) - ((fPC2)/(3.0f * fPC3));
      fMinTimes[2] = (2.0f * fSqrtQNeg * COS_((fPhi/3.0f) + ((4.0f*C_PI)/(3.0f)))) - ((fPC2)/(3.0f * fPC3));

      for(iCurrMinTimeID = 0; iCurrMinTimeID < 3; iCurrMinTimeID++)
      {
        if(fMinTimes[iCurrMinTimeID] > 0.f)
        {
          float32 fCurrDist = EMPCalcObjObjDistAtTime(fMinTimes[iCurrMinTimeID], pIn_Obj1, pIn_Obj2 );
          if(fCurrDist < fMinDistGlobal)
          {
            fMinDistGlobal = fCurrDist;
            iMinTimeGlobalID = iCurrMinTimeID;
          }
        } 
      }

      if (iMinTimeGlobalID >= 0)
      {
        *pOut_MinDistTime = fMinTimes[iMinTimeGlobalID];
        bResultOK         = b_TRUE;
      } 
      else
      {
        /* No Positive Number -> min dist lies in the past */
        *pOut_MinDistTime = 0.0f;
        bResultOK         = b_TRUE;
      }
    }
    else
    {
      /* This should not happen */
      bResultOK = b_FALSE;
    }
  }

  if(*pOut_MinDistTime < 0.0f)
  {
    /* Time of minimum distance lies in the past */
    *pOut_MinDistTime = 0.0f;
  }


  return bResultOK;
}/* PRQA S 7002,7004 # Date:2020-06-03, Reviewer: Praveen Annareddy , Reason: suppressing cyclomatic complexity for better code maintainability*/

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
/*******************************************************************************
  Functionname:         EMPCalcDynObjToEgoFrontRelation                   */ /*!

  @brief                Calculate the time, distance, and ego (front center)
                        position where target (closest in x) and ego (front
                        center) trajectories are closest.
  
  @description          Calculate the time, distance, and ego (front center)
                        position where target and ego (front center) trajectories
                        are closest. The calculation is done based upon dynamic
                        description of ego and target.
                        @attention: To approximate ego front position XofT.fC0 is
                         set to zero and acceleration adapted accordingly
                         (only valid for small prediction times).
                         Object position is set to closest in x.
                        @startuml EMPCalcDynObjToEgoFrontRelation_activity.png
                        start
                          #Orange: Get pointer to ego front trajectory:
                          <b>AIP_p_GetACDCEgoTraj</b> >
                          #Orange:Create target trajectory object:
                          <b>EMPPredictObjTraj</b> >
                          #Orange:Get time t_{minDist} of minimal distance:
                          <b>EMPCalcMinDistTime</b> >
                          #Orange:Calculate the ego (front center) and target 
                           position at t_{minDist}:
                          <b>EMPCalcPositionAtTime</b> >
                          #Orange:Calculate distance |target pos(now) - ego pos(t_{minDist})|:
                          <b>EMP_v_CalcDistToRefPoint</b> >
                          #Orange:Calculate distance |target pos(t_{minDist}) - ego pos(t_{minDist})|:
                          <b>EMP_v_CalcDistToRefPoint</b> >
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex       : Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pfMinDistTime      : Time until minimal distance is reached 
                                             (TTC if min dist == 0). @phys_unit [s] @range [0,+...[\n
                        pMinDistEgoPos     : Position of ego front at pfMinDistTime\n
                        pfTargetMinDist    : Distance of target to pMinDistEgoPos at pfMinDistTime\n
                        pfTargetCurDist    : Current distance of target to pMinDistEgoPos\n

  @glob_in              @ref AIP_p_GetACDCEgoTraj \n
                        @ref ACDC_p_GetObjPositions\n
                        @ref ACDC_p_GetObjDescMain
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP
  @c_switch_full        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description
  @testmethod           @Generic_Testmethods

  @traceability         Design Decision

  @author               Matthias Lorenzen | matthias.lorenzen@continental-corporation.com
*******************************************************************************/
void EMPCalcDynObjToEgoFrontRelation( ObjNumber_t   const         iObjectIndex, 
                                      float32             * const pfMinDistTime, 
                                      SFLVector2D_t       * const pMinDistEgoPos,
                                      float32             * const pfTargetMinDist,
                                      float32             * const pfTargetCurDist )
{
  float32                         fCurDistInXDirDummy; /* dummy variable for unused function input/output */
  float32                         fMinDistInXDirDummy; /* dummy variable for unused function input/output */
  ACDCTrajPred_t const * const    pEgoTrajectory = AIP_p_GetACDCEgoTraj(ACDC_MANEUVER_KinematicsWithoutAcceleration_Front);
  ACDCObjDescMain_t const * const pTargetObject = ACDC_p_GetObjDescMain(iObjectIndex);
  SFLVector2D_t const * const     pTargetPos      = &(ACDC_p_GetObjPositions(iObjectIndex)->GenObject);
  ACDCTrajPred_t                  TargetTrajectory;
  SFLVector2D_t                   MinDistTargetPos;

  /* Fill target position and velocity into an artificial trajectory structure */
  (void)EMPPredictObjTraj( pTargetObject, ACDC_MANEUVER_KinematicsUnchanged, &TargetTrajectory );

  /* Calculate time of minimal distance */ 
  (void)EMPCalcMinDistTime( pEgoTrajectory, &TargetTrajectory, pfMinDistTime );
 
  /* Calculate ego & target position at time of minimal distance */
  EMPCalcPositionAtTime(*pfMinDistTime, pEgoTrajectory, pMinDistEgoPos);
  EMPCalcPositionAtTime(*pfMinDistTime, &TargetTrajectory, &MinDistTargetPos);

  /* get object distances to the collision point (ego pos) now and at TTC */
  EMP_v_CalcDistToRefPoint(pTargetPos,        pMinDistEgoPos, pfTargetCurDist, &fCurDistInXDirDummy);
  EMP_v_CalcDistToRefPoint(&MinDistTargetPos, pMinDistEgoPos, pfTargetMinDist, &fMinDistInXDirDummy);
  *pfTargetCurDist = fABS(*pfTargetCurDist);
  *pfTargetMinDist = fABS(*pfTargetMinDist);
}
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */


/*************************************************************************************************************************
  Functionname:         EMPCalcObjExDesc                                                                             */ /*!

  @brief                Calculate objects existence description that is used to calculate the collision 
                        probability of two objects.

  @description          Fills the object data into the structure @ref EMPObjExDesc_t that is used to calculate
                        the collision probability between two objects. Therefore the position, geometry, \n
                        orientation and the variances are predicted and written into the structure.
                        @startuml EMPCalcObjExDesc_activity.png
                        start
                          #Orange:Calculate position at considered time:
                          <b>SFL_f_EvalPolyDeg2</b> >
                          note left: Based on Equation of motion\nin X and Y direction
                          #Orange:Calculate orientation at considered time:
                          <b>EMPCalcTrajOrientationAtTime</b> >
                          #Orange:Calculate variance at considered time:
                          <b>EMPCalcVariance2D</b> >
                        stop
                        @enduml
  
  @return               boolean: False if there were errors.

  @param[in]            fTime :               Time at which the existence description shall be calculated.
                                              @phys_unit [s] @range ]-...,+...[
  @param[in]            *pIn_Obj :            Object for which the existence description shall be calculated.
  @param[out]           *pOut_ExistenceDesc : Returned existence description.

  @glob_in              @ref SFL_f_EvalPolyDeg2 \n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPCALCOBJEXDESC_001\n

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
#pragma PRQA_NO_SIDE_EFFECTS EMPCalcVariance2D //function can be marked as being free from side effects(Needed for Helix QAC warning fix).
boolean EMPCalcObjExDesc(float32                     fTime, 
                         ACDCObjPred_t   const *const pIn_Obj, 
                         EMPObjExDesc_t       *const pOut_ExistenceDesc )
{
  boolean bResultOk = b_TRUE;

  pOut_ExistenceDesc->sCenter.fX   = SFL_f_EvalPolyDeg2( &pIn_Obj->pTrajPred->XofT, fTime );
  pOut_ExistenceDesc->sCenter.fY   = SFL_f_EvalPolyDeg2( &pIn_Obj->pTrajPred->YofT, fTime );
  pOut_ExistenceDesc->sGeometry    = *pIn_Obj->pGeometry;
  pOut_ExistenceDesc->fOrientation = EMPCalcTrajOrientationAtTime( fTime, pIn_Obj->pTrajPred );

  bResultOk =  (bResultOk) && (EMPCalcVariance2D( fTime, pIn_Obj->pTrajPred, &pOut_ExistenceDesc->sVar ));

  return bResultOk;
}

/*************************************************************************************************************************
  Functionname:         EMPCalcCollProbExDesc                                                                        */ /*!

  @brief                Calculate Collision Probability of two objects based on Existence Descriptions.
  
  @description          Create a virtual Scene in which Obj1 lies in the origin of the coordinate system.
                        All of the uncertainty is combined in the edges of object 2. The sizes of the two \n
                        Objects are combined in Obj2. For each edge, the collision probability is calculated
                        in X and in Y direction by calling the function @ref EMPCalcStdGaussianCDF2D. \n
                        
                        @image html EMP_CalcCollProbExDesc.svg width=1400
                        @startuml EMPCalcCollProbExDesc_activity.png
                        start
                          :Calculate relative position 
                          of object 2;
                          :Sum variances of both objects;
                          :Sum dimensions of both objects;

                          :Calculate the frame positions 
                          of one object;
                          note left
                            Edges Front Left, Front Right,
                            Rear Left, Rear Right
                          end note

                          #Orange:Calculate collision probability for each edge:
                          <b>EMPCalcStdGaussianCDF2D</b> >

                          :Calculate the overall collision probability;
                          note left: >see formula "Collision Probability"
                        stop
                        @enduml

  @return               boolean

  @param[in]            *pIn_ExDescObj1 :     Existence description of an object at a certain time.
  @param[in]            *pIn_ExDescObj2 :     Existence description of an object at a certain time.
  @param[in,out]        *pOut_CollisionProb : Collision probability at a certain time. @range [0,1]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     - **Formula Collision Probability:** \n
                        \f$ P = (P_{y,Left}-P_{y,Right})-(P_{X,Front}-P_{X,Back})\f$

  @testmethod           @ref TEST_EMPCALCCOLLPROBEXDESC_001

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
boolean EMPCalcCollProbExDesc(EMPObjExDesc_t const *const pIn_ExDescObj1, 
                              EMPObjExDesc_t const *const pIn_ExDescObj2, 
                              float32              *const pOut_CollisionProb )
{

  SFLVector2D_t  virtObj2Center;
  SFLVector2D_t  virtObjVar;
  ACDCGeometry_t virtObjSize;

  SFLVector2D_t  intAreaFL, intAreaFR, intAreaRL, intAreaRR;
  
  /* Obj1 is in the center. Create virtual Obj2 relative to new position */
  virtObj2Center.fX = pIn_ExDescObj2->sCenter.fX - pIn_ExDescObj1->sCenter.fX;
  virtObj2Center.fY = pIn_ExDescObj2->sCenter.fY - pIn_ExDescObj1->sCenter.fY;

  /* Combine variances */
  virtObjVar.fX = pIn_ExDescObj1->sVar.fX + pIn_ExDescObj2->sVar.fX;
  virtObjVar.fY = pIn_ExDescObj1->sVar.fY + pIn_ExDescObj2->sVar.fY;

  /* Combine vehicle sizes into one big integration size */
  virtObjSize.fLength      = pIn_ExDescObj1->sGeometry.fLength + pIn_ExDescObj2->sGeometry.fLength;
  virtObjSize.fWidth       = pIn_ExDescObj1->sGeometry.fWidth  + pIn_ExDescObj2->sGeometry.fWidth;

  /* Define Integration Area */
  intAreaFL.fX = virtObj2Center.fX + (virtObjSize.fLength / 2.0f);
  intAreaFL.fY = virtObj2Center.fY + (virtObjSize.fWidth  / 2.0f);

  intAreaFR.fX = virtObj2Center.fX + (virtObjSize.fLength / 2.0f);
  intAreaFR.fY = virtObj2Center.fY - (virtObjSize.fWidth  / 2.0f);

  intAreaRL.fX = virtObj2Center.fX - (virtObjSize.fLength / 2.0f);
  intAreaRL.fY = virtObj2Center.fY + (virtObjSize.fWidth  / 2.0f);

  intAreaRR.fX = virtObj2Center.fX - (virtObjSize.fLength / 2.0f);
  intAreaRR.fY = virtObj2Center.fY - (virtObjSize.fWidth  / 2.0f);

  /* Integrate using 2D CDF */
  {
    float32 cdfFL = EMPCalcStdGaussianCDF2D( intAreaFL.fX, intAreaFL.fY, 0.0f, virtObjVar.fX, virtObjVar.fY );
    float32 cdfFR = EMPCalcStdGaussianCDF2D( intAreaFR.fX, intAreaFR.fY, 0.0f, virtObjVar.fX, virtObjVar.fY );
    float32 cdfRL = EMPCalcStdGaussianCDF2D( intAreaRL.fX, intAreaRL.fY, 0.0f, virtObjVar.fX, virtObjVar.fY );
    float32 cdfRR = EMPCalcStdGaussianCDF2D( intAreaRR.fX, intAreaRR.fY, 0.0f, virtObjVar.fX, virtObjVar.fY );

    *pOut_CollisionProb = ((cdfFL - cdfFR) - cdfRL) + cdfRR;
  }

  return b_TRUE;
}

/*************************************************************************************************************************
  Functionname:         EMPCalcTrajOrientationAtTime                                                                 */ /*!

  @brief                Calculates the orientation of a given trajectory at a given time.

  @description          Calculates the orientation of an object at a given time if it follows the given trajectory.
                        The executed steps are:
                        @startuml EMPCalcTrajOrientationAtTime_activity.png
                          start
                            #Orange:Calculate position at the given time
                            <b>SFL_f_EvalPolyDeg2</b> >
                            :Calculate Atan2 of position at given time;
                            note left: >see formula "Orientation"
                          stop
                        @enduml

  @return               float32 : Orientation of the ego trajectory at given time. @phys_unit [rad] @range [-pi,pi]

  @param[in]            fTime :     Time at which the orientation shall be calculated. @phys_unit [s] @range ]-...,+...[
  @param[in]            *pInTraj :  Trajectory for which the orientation shall be determined.

  @glob_in              @ref SFL_f_EvalPolyDeg2\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     - **Formula Orientation:**\n
                        \f$Orientation = \arctan(Grad_Y,Grad_X)\f$ \n
                        with\n
                        \f$Grad_X = X(t)\f$ \n
                        \f$Grad_Y = Y(t)\f$

  @testmethod           @ref TEST_EMPCALCTRAJORIENTATIONATTIME_001 

  @traceability         Design Decision

  @todo                 Check what happens if x_gradient == 0.0f

  @author               Matthias Thomi
*************************************************************************************************************************/
static float32 EMPCalcTrajOrientationAtTime(float32                     fTime, 
                                            ACDCTrajPred_t const * const pInTraj )
{
  float32 fGradX = SFL_f_EvalPolyDeg2( &(pInTraj->XofT), fTime );
  float32 fGradY = SFL_f_EvalPolyDeg2( &(pInTraj->YofT), fTime );
  
  
  return ATAN2_( fGradY, fGradX );
}

/*************************************************************************************************************************
  Functionname:         EMPCalcVariance2D                                                                            */ /*!

  @brief                Calculates 2-Dimensional Variance based on Trajectory Prediction

  @description          Calculates position variance in X and in Y direction at a given time for a given trajectory by
                        calling the function @ref SFL_f_EvalPolyDeg2 once for X and once for Y direction.

  @return               boolean : True

  @param[in]            fTime :       Time at which the variance shall be calculated. @phys_unit [s] @range ]-...,+...[
  @param[in]            *pInTraj :    Trajectory for which the variance shall be calculated.
  @param[in,out]        *pOut_Var2D : Calculated variance.

  @glob_in              @ref SFL_f_EvalPolyDeg2\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPCALCVARIANCE2D_001

  @traceability         Design Decision

  @author               Matthias Thomi
*************************************************************************************************************************/
static boolean EMPCalcVariance2D(float32                    fTime, 
                                 ACDCTrajPred_t const *const pInTraj, 
                                 SFLVector2D_t        *const pOut_Var2D )
{
   pOut_Var2D->fX = SFL_f_EvalPolyDeg2(&pInTraj->VarXofT, fTime);
   pOut_Var2D->fY = SFL_f_EvalPolyDeg2(&pInTraj->VarYofT, fTime);

  return b_TRUE;
}

/*************************************************************************************************************************
  Functionname:         EMPCalcStdGaussianCDF2D                                                                      */ /*!

  @brief                Calculates a 2-dimensional cumulative distribution function with rho = 0

  @description          Calculates a 2-dimensional cumulative distribution function with correlation coefficient rho = 0.
                        Therefore first the cumulative distribution for each of the values is calculated 
                        (@ref CML_f_CalcStdGaussianCDF). Subsequently the two results are multiplied.

  @return               float32 : result of the 2-dimensional distribution.

  @param[in]            fValueX : Input to the CDF in X-Direction.
  @param[in]            fValueY : Input to the CDF in Y-Direction.
  @param[in]            fAver :   Mean of the Gaussian distribution.
  @param[in]            fSigmaX : Standard deviation of the Gaussian distribution in X-direction.
  @param[in]            fSigmaY : Standard deviation of the Gaussian distribution in Y-direction.

  @glob_in              @ref CML_f_CalcStdGaussianCDF\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPCALCSTDGAUSSIANCDF2D_001 \n

  @traceability         Design Decision

  @author               Matthias Thomi
*************************************************************************************************************************/
static float32 EMPCalcStdGaussianCDF2D( float32 fValueX, float32 fValueY, float32 fAver, float32 fSigmaX, float32 fSigmaY )
{
  
  return CML_f_CalcStdGaussianCDF ( fValueX, fAver, fSigmaX ) * CML_f_CalcStdGaussianCDF ( fValueY, fAver, fSigmaY );
}


/*************************************************************************************************************************
  Functionname:         EMPCalcObjObjDistAtTime                                                                      */ /*!

  @brief                Calculates the distance between two objects at a given time

  @description          Predicts two objects to a given time by calling he function @ref EMPCalcPositionAtTime. 
                        Calculates the distance between the resulting positions.
                        @startuml EMPCalcObjObjDistAtTime_activity.png
                        start
                          #Orange:Calculate predicted position of object 1:
                          <b>EMPCalcPositionAtTime</b> >
                          
                          #Orange:Calculate predicted position of object 2
                          <b>EMPCalcPositionAtTime</b> >

                          :Calculate distance between the resulting positions;
                          note left: >see Formula "Distance"
                        stop
                        @enduml

  @return               float32: Distance at the given time. @phys_unit [m] @range [0,+...[

  @param[in]            fTime :     Time at which distance shall be calculated. @phys_unit [s] @range ]-...,+...[
  @param[in]            *pIn_Obj1 : Pointer to the trajectory of first object.
  @param[in]            *pIn_Obj2 : Pointer to the trajectory of second object.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     - **Formula Distance:** \n
                        \f$ Distance = \sqrt{(X_{Obj1} - X_{Obj2})^2+(Y_{Obj1}-Y_{Obj2})^2}\f$

  @testmethod           @ref TEST_EMPCALCOBJOBJDISTATTIME_001\n

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
float32 EMPCalcObjObjDistAtTime(float32                    fTime,
                                ACDCTrajPred_t const *const pIn_Obj1,
                                ACDCTrajPred_t const *const pIn_Obj2 )
{
  SFLVector2D_t PosObj1;
  SFLVector2D_t PosObj2;
  float32       fOutDist = 0.f;

  EMPCalcPositionAtTime( fTime, pIn_Obj1, &PosObj1 );
  EMPCalcPositionAtTime( fTime, pIn_Obj2, &PosObj2 );

  fOutDist = SQRT( SQR(PosObj1.fX - PosObj2.fX) + SQR(PosObj1.fY - PosObj2.fY) );

  return fOutDist;
}

/*************************************************************************************************************************
  Functionname:         EMPCalcPositionAtTime                                                                        */ /*!

  @brief                Calculates the position of an object with a given trajectory at a given time.

  @description          Calculates the position of a object if it follows its trajectory for a certain time by 
                        calculating a 2nd degree polynomial via the function @ref SFL_f_EvalPolyDeg2.
                        If the velocity is below @ref ACDC_EMP_VSTOP_THRES_SQR the object is assumed to stop.
                        This assumption is relevant if ego acceleration is considered by using any ACDC_MANEUVER_xxx
                        but "ACDC_MANEUVER_KinematicsWithoutAcceleration" or object acceleration through using
                        "ACDC_MANEUVER_xxxBreaking"
                        @startuml EMPCalcPositionAtTime_activity.png
                        start
                         #Orange: Get stopping time t_{stop} of object:
                         <b>EMPGetStopTime</b> >
                         :if t_{stop}> 0 set t = min(t,t_{stop});
                         #Orange:Calculate X position at time t
                         <b>SFL_f_EvalPolyDeg2</b> >
                         #Orange:Calculate Y position at time t
                         <b>SFL_f_EvalPolyDeg2</b> >
                        stop
                        @enduml
                        @attention Toggling of stopTime can occur due to limitations in @ref EMPGetStopTime.
                        See respective comment.

  @return               void

  @param[in]            fTime :         Time at which position shall be calculated. @phys_unit [s] @range ]-...,+...[
  @param[in]            pIn_Obj :       Pointer to the trajectory of the object.
  @param[in,out]        pOut_Position : Position of the object.

  @glob_in              @ref SFL_f_EvalPolyDeg2\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPCALCPOSITIONATTIME_001\n
                        @ref TEST_EMPCALCPOSITIONATTIME_002

  @traceability         Design Decision

  @author               Matthias Thomi | Matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
void EMPCalcPositionAtTime(float32                      fTime,
                           ACDCTrajPred_t const * const pIn_Obj,
                           SFLVector2D_t        * const pOut_Position )
{
  const float32 stopTime = EMPGetStopTime (pIn_Obj);

  if (stopTime > 0.0f)
  {
    fTime = MIN(stopTime,fTime);
  }
  pOut_Position->fX = SFL_f_EvalPolyDeg2( &(pIn_Obj->XofT), fTime );
  pOut_Position->fY = SFL_f_EvalPolyDeg2( &(pIn_Obj->YofT), fTime );
}

/*************************************************************************************************************************
  Functionname:         EMPCalcVelocityAtTime                                                                       */ /*!

  @brief                Calculates the velocity of an object with a given trajectory at a given time.

  @description          Calculates the velocity of a object if it follows its trajectory for a certain time by 
                        calculating a 2nd degree polynomial via the function @ref SFL_f_EvalPolyDeg2.
                        If the velocity is below @ref ACDC_EMP_VSTOP_THRES_SQR the object is assumed to stop.
                        This assumption is relevant if ego acceleration is considered by using any ACDC_MANEUVER_xxx
                        but "ACDC_MANEUVER_KinematicsWithoutAcceleration" or object acceleration through using
                        "ACDC_MANEUVER_xxxBreaking"
                        @startuml EMPCalcVelocityAtTime_activity.png
                        start
                         #Orange: Get stopping time t_{stop} of object:
                         <b>EMPGetStopTime</b> >
                         :if t_{stop}> 0 set t = min(t,t_{stop});
                         :Calculate X and Y velocity at time t;
                        stop
                        @enduml
                        @attention Toggling of stopTime can occur due to limitations in @ref EMPGetStopTime.
                        See respective comment.

  @return               void

  @param[in]            fTime :         Time at which velocity shall be calculated. @phys_unit [m/s] @range [0,+...[
  @param[in]            pIn_Obj :       Pointer to the trajectory of the object.
  @param[in,out]        pOut_Position : Position of the object.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPCALCVELOCITYATTIME_001 \n
                        @ref TEST_EMPCALCVELOCITYATTIME_002 \n
						@ref TEST_EMPCALCVELOCITYATTIME_003

  @traceability         Design Decision

  @author               Matthias Thomi | Matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
void EMPCalcVelocityAtTime(float32                      fTime,
                           ACDCTrajPred_t const * const pIn_Obj,
                           SFLVector2D_t        * const pOut_Velocity )
{
  const float32 stopTime = EMPGetStopTime(pIn_Obj);

  if (stopTime > 0.0f)
  {
    fTime = MIN(stopTime,fTime);
  }
  pOut_Velocity->fX = pIn_Obj->XofT.fC1 + ((2.0f * pIn_Obj->XofT.fC2) * fTime);
  pOut_Velocity->fY = pIn_Obj->YofT.fC1 + ((2.0f * pIn_Obj->YofT.fC2) * fTime);
}


/*************************************************************************************************************************
  Functionname:         EMPGetStopTime                                                                            */ /*!

  @brief                Returns the time when the object stops. The time is negative if the object is not
                        stopping in the future.

  @description          Given the trajectory over time of an object in terms of second degree polynomials for
                        the \f$x\f$ and \f$y\f$ position \n
                        \f$p(t) = \left( \begin{array} \ x(t) \\ y(t) \end{array} \right) = 
                        \left( \begin{array} \ c_{0,x} + c_{1,x} t+ c_{2,x} t^2\\ c_{0,y} + c_{1,y} t+ c_{2,y} t^2 \end{array} \right)\f$\n
                        respectively, the velocity is given by \n
                        \f$v(t) = v(0) + a(0)\cdot t\f$
                        with
                        \f$v(0) =: v_0 = \left( \begin{array} \ v_{0,x} \\ v_{0,y} \end{array} \right) = 
                        \left( \begin{array} \ c_{1,x} \\ c_{1,y} \end{array} \right)\f$
                        and
                        \f$a(0) =: a_0 = \left( \begin{array} \ a_{0,x} \\ a_{0,y} \end{array} \right) = 
                        \left( \begin{array} \ 2c_{2,x} \\ 2c_{2,y} \end{array} \right)\f$.\n
                        In case the object is accelerating (\f$ \|a_0\|_2^2 >\f$C_F32_DELTA), this function checks if the minimizer \f$t^\star\f$
                        of the function \f$ \| v(t) \|_2^2\f$ is positive and the function value at this minimizer is
                        smaller than @ref ACDC_EMP_VSTOP_THRES_SQR. If that is the case, the value of \f$t^\star\f$ is returned. Otherwise
                        the return value is negative (-1).\n
                        The function \f$\| v(t) \|_2^2\f$ is differentiable and strictly convex for \f$a_0^Ta_0>0\f$. Thus a necessary and suffictient
                        condition for a unique global minimum is \f$\frac{d\| v(t^\star) \|_2^2}{dt} = 0\f$ which yields\n
                        \f$ t^\star = - \frac{a_0^Tv_0}{a_0^Ta_0}\f$.\n
                        This function is relevant if ego acceleration is considered by using any ACDC_MANEUVER_xxx
                        but "ACDC_MANEUVER_KinematicsWithoutAcceleration" or object acceleration through using
                        "ACDC_MANEUVER_xxxBreaking"
                        @startuml EMPGetStopTime.png
                        start
                          if (Is the minimizer positive
                              AND
                              the acceleration greater than C_F32_DELTA
                              AND
                              the squared norm of the velocity vector at the minimizer
                              smaller than ACDC_EMP_VSTOP_THRES_SQR?) then (yes)
                            :1}
                              :return the minimizer;
                          else (No)
                            :2}
                              :return -1;
                          endif
                        stop
                        @enduml
                        @attention: Since in EMP x and y velocity are considered independent,
                        toggling can occur eg. for velocities around sqrt(ACDC_EMP_VSTOP_THRES_SQR)
                        in one component and deceleration which leads to a stop in the other.
                        (Example: A comoving vehicle with y-velocity component of magnitude around
                        sqrt(ACDC_EMP_VSTOP_THRES_SQR) which is tested with ACDC_MANEUVER_xxx
                        would stop if v_y < sqrt(ACDC_EMP_VSTOP_THRES_SQR) and drive backwards
                        otherwise)

  @return               float32: stop time, negative if the object is not stopping in the future

  @param[in]            p_traj : object trajectory prediction structure

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPGETSTOPTIME_001 \n
                        @ref TEST_EMPGETSTOPTIME_002 \n
                        @ref TEST_EMPGETSTOPTIME_003 \n
                        @ref TEST_EMPGETSTOPTIME_004 \n
						@ref TEST_EMPGETSTOPTIME_005 \n
                        @ref TEST_EMPGETSTOPTIME_006

  @traceability         Design Decision

  @author               Matthias Lorenzen | matthias.lorenzen@continental-corporation.com | +49 (8382) 9699-664
*************************************************************************************************************************/
float32 EMPGetStopTime(ACDCTrajPred_t const * const p_traj)
{
  float32 f_tStop = -1.0f;
  float32 f_tMin = 0.0f;
  float32 f_aNormSqr;
  float32 f_vNormSqr;
  // dot product of the velocity and acceleration vectors (for t=0)
  float32 f_vDotA0 = ((p_traj->XofT.fC2*p_traj->XofT.fC1) + (p_traj->YofT.fC2*p_traj->YofT.fC1)) * 2.0f;

  if (f_vDotA0 < - C_F32_DELTA) // check for -C_F32_DELTA to avoid floating point error for
  {                             // <a,v> which is zero in the EMP model without acceleration
    // minimum velocity is reached for positive t

    // 2-norm of the acceleration vector squared
    f_aNormSqr = (SQR(p_traj->XofT.fC2) + SQR(p_traj->YofT.fC2))*4.0f;
    if (f_aNormSqr > C_F32_DELTA)
    {
      // object is decelerating or accelerating
      f_tMin = - f_vDotA0/f_aNormSqr;
      // 2-norm of the velocity vector squared at t=f_tMin
      f_vNormSqr = (f_aNormSqr*SQR(f_tMin)) + ((2.0f)*f_vDotA0*f_tMin) + SQR(p_traj->XofT.fC1) + SQR(p_traj->YofT.fC1);
      if (f_vNormSqr < ACDC_EMP_VSTOP_THRES_SQR)
      {
        // object is considered to be stopped at f_tMin
        f_tStop = f_tMin;
      }
    }
  }
  return f_tStop;
}

/*************************************************************************************************************************
  Functionname:         EMPCalcVariance                                                                              */ /*!

  @brief                Calculates the variance of an array.

  @description          Function follows the subsequent steps:
                        @startuml EMPCalcVariance_activity.png
                        start
                          :Calculate average of all values;
                           note left: >see Formula "Average"
                          :Calculate the squared difference 
                          between each value and the average;
                          note left: >see Formula "Squared difference"
                          :Calculate the variance;
                          note left: >see Formula "Variance"
                        stop
                        @enduml

  @return               float32: Variance of the given values.

  @param[in]            afValues :    Array of values of which a variance shall be calculated
  @param[in]            uiArraySize : Size of the Array that contains the values.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$k = \f$ Number of values in the array
                        - **Formula Average:** \n
                          \f$Avg = \frac{\sum_{0-k}(Value_{0-k})}{k}\f$\n
                        - **Formula squared difference:** \n
                          \f$ VarianceSum = \sum_{0-k}(Value_{0-k}-Avg)^2 \f$\n
                        - **Formula Variance:** \n
                          \f$ Variance = \frac{VarianceSum }{k} \f$\n

  @testmethod           @ref TEST_EMPCALCVARIANCE_001 \n
                        @ref TEST_EMPCALCVARIANCE_002

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
float32 EMPCalcVariance( const float32 afValues[], uint16 uiArraySize )
{
  float32 fSumforAverage  = 0.f;
  float32 fAverage        = 0.f;
  float32 fSumforVariance = 0.f;
  float32 fVariance       = 0.f;
  uint16  uiCurrID        = 0u;

  /* Assure that the size of the array is greater than 1 because function expects that */
  ACDC_ASSERT(uiArraySize > 1u);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */

  for ( uiCurrID = 0u; uiCurrID < uiArraySize; ++uiCurrID )
  {
    fSumforAverage += afValues[uiCurrID];
  }

  fAverage = fSumforAverage/(float32)uiArraySize;

  for ( uiCurrID = 0u; uiCurrID < uiArraySize; ++uiCurrID )
  {
    fSumforVariance += SQR(afValues[uiCurrID]-fAverage);
  }
  /*PRQA S 4394 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Cast to float intended as implemented*/
  fVariance = fSumforVariance/((float32)(uiArraySize-1u));

  return fVariance;
} 

//!@}
#endif /* ACDC_CFG_EMP */


