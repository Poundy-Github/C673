/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculation.c

DESCRIPTION:               handles all CD global calculation 

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 14:19:40CEST $

VERSION:                   $Revision: 1.58 $

LEGACY VERSION:            Revision: 2.14

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"


#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_calculation Calculation
@ingroup cd

@brief          The general calculation functions that are called from different modules are located in this module.\n\n

@description    This module provides generic calculation functions that are used by several other modules.
                Additionally it contains functions for which no specific module was created yet.
                The following functions are provided:
                - Functions for common mathematical operations:\n
                  @ref CDCalculateVehStopTime       \n
                  @ref CDCalculateDistance          \n
                  @ref CDCalculateVelocity          \n
                  @ref CDPredictMovement            \n
                - Additionally the following specific functions are provided:\n
                  @ref CD_f_GetCorridorStopDistance  \n
                  @ref CDCalcGeometryVarianceFromShapePoints \n
                  @ref CDCalculateObjectsCenterOfFront \n

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

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
 /* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS CDCalculateVelocity
#endif

#if (ACDC_CFG_TURN_ASSIST)

static void                     CDCalculateCorridorStopDistance(ObjNumber_t const           iObjectIndex         ,
                                                                fDistance_t       *  const  pCorridorStopDistance );

static float32                  CDCalculateSteeringAngle       (float32               const fWheelBase           ,
                                                                float32               const fCurvature            );


#endif /* #if (ACDC_CFG_TURN_ASSIST) */
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDCalculateVehStopTime                                                                       */ /*!

  @brief                Calculates the time at which a given velocity becomes 0 if a given brake acceleration is applied.

  @description          Calculates the time at which a given velocity becomes 0 if a given brake acceleration is applied.
                        If the given brake acceleration is negative (=> vehicle is accelerating), the time in the past at \n
                        which the vehicle was stopped is returned.
                        @startuml CDCalculateVehStopTime_activity.png
                        start
                          if(Pointer is valid?) then (Yes)
                            if(Acceleration is 0?) then (Yes)
                              if(Velocity is 0?) then (Yes)
                                :1}
                                :Vehicle has stopped already
                                **Stop Time** = 0;
                              else (No)
                                :2}
                                :Due to missing acceleration
                                vehicle will never stop
                                **Stop Time** = default;
                              endif
                            else (No)
                              :3}
                              :Vehicle has already stopped or will stopp,
                              Calculate **Stop Time**;
                              note left: >see formula\n"Stop Time"
                            endif
                            if(Stop time exceeds limit 0 or max?) then (Yes)
                              :4}
                              :**Stop Time** = default;
                            else(No)
                              :5}
                            endif
                          else (No)
                            :6}
                            :Return Error;
                          endif
                        stop
                        @enduml

  @return               boolean : False if pointer error detected

  @param[in]            fVelocity :     The current vehicle velocity     @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fAcceleration : The current vehicle acceleration @phys_unit [m/s^2] @range ]-...,+...[
  @param[in,out]        pfStopTime :    The calculated vehicle stop time @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Stop Time**:\n 
                          \f$ \frac{- V}{A}\f$

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDCALCULATEVEHSTOPTIME_001 \n
                        @ref TEST_CDCALCULATEVEHSTOPTIME_002 \n
                        @ref TEST_CDCALCULATEVEHSTOPTIME_003 \n
						@ref TEST_CDCALCULATEVEHSTOPTIME_004 \n
						@ref TEST_CDCALCULATEVEHSTOPTIME_005 \n
						@ref TEST_CDCALCULATEVEHSTOPTIME_006 \n


  @traceability         Design Decision

*************************************************************************************************************************/
boolean CDCalculateVehStopTime( fVelocity_t   fVelocity,
                                fAccel_t      fAcceleration,
                                fTime_t     * pfStopTime )
{
  /* local variable */
  boolean bReturn = b_TRUE;

  /* check pointer */
  if (pfStopTime != NULL)
  {
    *pfStopTime = CD_TIME_MAX;

    /* no acceleration */
    if (fABS(fAcceleration) < C_F32_DELTA)
    {
      /* no velocity so vehicle already has stopped */
      if (fABS(fVelocity) < C_F32_DELTA)
      {
        *pfStopTime = 0.0f;
      }
      /* velocity exists but no acceleration so vehicle will never stop */
      else
      {
        *pfStopTime = CD_TIME_MAX;
      }
    }
    /* acceleration and velocity exist so either vehicle has stopped or will stop */
    else
    {
      *pfStopTime = -fVelocity / fAcceleration;
    }

    /* if vehicle already stops/has stopped or if value is too high stop time is maximum value */
    if ( (*pfStopTime < 0.0f) || 
         (*pfStopTime > CD_TIME_MAX) )
    {
      *pfStopTime = CD_TIME_MAX;
    }
  }
  /* pointer error */
  else
  {
    bReturn = b_FALSE;
  }

  /* return */
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateDistance                                                                          */ /*!

  @brief                Calculates the distance an object has covered at a certain time.

  @description          Calculates the covered distance after a time with a given initial distance, velocity and acceleration.
                        A constant acceleration is assumed.\n
                        The applied formula is the equation of motion.

  @return               fDistance_t : Calculated distance at the given time. @phys_unit [m] @range ]-...,+...[

  @param[in]            fDistance :     Initial (offset) distance. @phys_unit [m] @range ]-...,+...[
  @param[in]            fVelocity :     Initial velocity. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fAcceleration : Initial acceleration. @phys_unit [m/s^2] @range ]-...,+...[
  @param[in]            fTime :         Time at which the covered distance shall be calculated. @phys_unit [s] @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Equation of motion:** \n
                          \f$D(t) = D_0 + V_0\cdot t + 0.5 \cdot A_0 \cdot t^2\f$

  @author               Dominik Froehlich

  @testmethod           @ref TEST_CDCALCULATEDISTANCE_001

  @traceability         Design Decision

*************************************************************************************************************************/
fDistance_t  CDCalculateDistance( fDistance_t fDistance, fVelocity_t fVelocity, fAccel_t fAcceleration, fTime_t fTime )
{
  const fDistance_t fDist = fDistance + (fVelocity * fTime) + (0.5f * fAcceleration * SQR( fTime ));

  return fDist;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateVelocity                                                                          */ /*!

  @brief                Calculates the velocity at a given time.

  @description          Calculates the velocity that is reached after a given time with a given initial velocity 
                        and initial acceleration. The acceleration is assumed to be constant.

  @return               fVelocity_t : Velocity at the given time. @phys_unit [m/s] @range ]-...,+...[

  @param[in]            fVelocity :     Initial Velocity. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fAcceleration : Initial Acceleration. @phys_unit [m/s^2] @range ]-...,+...[
  @param[in]            fTime :         Time at which the velocity shall be calculated. @phys_unit [s] @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$V(t) = V_0 + A_0 \cdot t\f$

  @author               Dominik Froehlich

  @testmethod           @ref TEST_CDCALCULATEVELOCITY_001

  @traceability         Design Decision

*************************************************************************************************************************/
fVelocity_t CDCalculateVelocity( fVelocity_t fVelocity, fAccel_t fAcceleration, fTime_t fTime )
{
  const fVelocity_t fSpeed = fVelocity + (fAcceleration * fTime);

  return fSpeed;
}

/*************************************************************************************************************************
  Functionname:         CDPredictMovement                                                                            */ /*!

  @brief                Predicts a given movement up to a certain time. and return the new position and kinematics.

  @description          Predicts movement to a certain time. If speed 0 is reached in one direction the Object is 
                        assumed to completely stop if corresponding parameter has been set:
                        - **bStopXDir**:\n
                        If this parameter is set on true, it is assumed, that the considered object moves in a longitudinal direction. 
                        This means it usually stops if it reaches velocity 0 in X direction.
                        - **bStopYDir**:\n
                        If this parameter is set on true, it is assumed, that the considered object moves in a lateral direction. 
                        This means it usually stops if it reaches velocity 0 in Y direction.
                        .
                        @startuml CDPredictMovement_activity.png
                        start
                          #Orange:Calculate x- and y-velocity at 
                          the given prediction time
                          <b>CDCalculateVelocity</b> >

                          if(Stopping in X-direction possible?\nAND predicted X-velocity changed sign?) then (Yes)
                            :1}
                            :Calculate **time to stop in X** direction;
                            note left
                              Object stops in X-direction
                              >see formula "Time to stop X"
                            end note
                          else (No)
                            :2}
                          endif
                          
                          if(Stopping in Y-direction possible?\nAND predicted Y-velocity changed sign?) then (Yes)
                            :3}
                            :Calculate **time to stop in Y** direction;
                            note left
                            Object stops in Y-direction
                            >see formula "Time to stop Y"
                            end note
                          else (No)
                            :4}
                          endif

                          :**Time to stop** = MIN(**Time to stop X** , **Time to stop Y**);

                          if(Object stops in any direction?) then (Yes)
                            :5}
                            #Orange:Calculate position at stop time
                            <b>CDCalculateDistance</b> >
                            :Set velocity and acceleration
                            at prediction time to 0;
                          else(No)
                            :6}
                            #Orange:Calculate position at prediction time
                            <b>CDCalculateDistance</b> >
                            note right: Velocity has been calculated before
                            :Set acceleration at prediction 
                            time to current acceleration;
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            pMovement :           The current movement info.
  @param[in,out]        pPredictedMovement :  The predicted movement info.
  @param[in]            fPredictTime :        The prediction time. @phys_unit [s] @range ]-...,+...[
  @param[in]            bStopXDir :           Vehicle stops when reaching speed 0 in X direction.
  @param[in]            bStopYDir :           Vehicle stops when reaching speed 0 in Y direction.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Time to stop X:** \n
                          \f$ t_{stop,x} = \frac{-V_{x}}{A_{x}}\f$
                        - **Time to stop Y:** \n
                          \f$ t_{stop,y} = \frac{-V_{y}}{A_{y}}\f$

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDPREDICTMOVEMENT_001 \n
                        @ref TEST_CDPREDICTMOVEMENT_002 \n
                        @ref TEST_CDPREDICTMOVEMENT_003 \n
                        @ref TEST_CDPREDICTMOVEMENT_004 \n
                        @ref TEST_CDPREDICTMOVEMENT_005 \n
                        @ref TEST_CDPREDICTMOVEMENT_006 \n
						@ref TEST_CDPREDICTMOVEMENT_007 \n
						@ref TEST_CDPREDICTMOVEMENT_008 \n

  @traceability         Design Decision

*************************************************************************************************************************/
void CDPredictMovement( CDMovement_t const * const pMovement, 
                        CDMovement_t       * const pPredictedMovement,
                        float32                    fPredictTime,
                        boolean                    bStopXDir, 
                        boolean                    bStopYDir ) 
{
  float32 fTime2Stop = CD_TIME_MAX;

  /* predict velocities */
  pPredictedMovement->fVx = CDCalculateVelocity(pMovement->fVx, pMovement->fAx, fPredictTime);
  pPredictedMovement->fVy = CDCalculateVelocity(pMovement->fVy, pMovement->fAy, fPredictTime);

  /* stopping possible in x direction */
  if (   ( bStopXDir == b_TRUE )  
      && (  ((pPredictedMovement->fVx <= 0.0f) && (pMovement->fVx > 0.0f))        /* change from moving to oncoming */
          ||((pPredictedMovement->fVx >= 0.0f) && (pMovement->fVx < 0.0f)) )      /* change from oncoming to moving */
      && ( fABS( pMovement->fAx)      >   C_F32_DELTA                ) )    /* Condition above implies a != 0 but it is checked explicite here because of more safeguarding */
  {
    /* Calc time to stop; negative fTime2Stop means stop in the past */
    fTime2Stop = -pMovement->fVx / pMovement->fAx; /* fTime2Stop has same sign as fPredictTime due to conditions */
  }
  else
  {
    bStopXDir = b_FALSE;
  }

  /* stopping possible in y direction */
  if (  ( bStopYDir                     == b_TRUE                       ) 
      && (   ((pPredictedMovement->fVy   <= 0.0f) && (pMovement->fVy > 0.0f ))         /* change from moving right to left */
          || ((pPredictedMovement->fVy   >= 0.0f) && (pMovement->fVy < 0.0f )) )      /* change from moving left to right */
      && (fABS( pMovement->fAy)          >   C_F32_DELTA                 ) )    /* Condition above implies a != 0 but it is checked explicite here because of more safeguarding */
  {
    /* Calc time to stop; negative fTime2Stop means stop in the past */
    const float32 fTime2StopY = -pMovement->fVy / pMovement->fAy; /* fTime2Stop has same sign as fPredictTime due to conditions */

    /* select minimum stop time */
    if ( bStopXDir == b_TRUE )
    {
      fTime2Stop = MIN_FLOAT( fTime2Stop, fTime2StopY );
    }
    else
    {
      fTime2Stop = fTime2StopY;
    }
  }
  else
  {
    bStopYDir = b_FALSE;
  }

  /* predict movement with stop */
  if ( ( bStopXDir == b_TRUE ) ||
       ( bStopYDir == b_TRUE ) )
  {
    pPredictedMovement->fX  = CDCalculateDistance(pMovement->fX, pMovement->fVx, pMovement->fAx, fTime2Stop);
    pPredictedMovement->fVx = 0.0f;
    pPredictedMovement->fAx = 0.0f;
    pPredictedMovement->fY  = CDCalculateDistance(pMovement->fY, pMovement->fVy, pMovement->fAy, fTime2Stop);
    pPredictedMovement->fVy = 0.0f;
    pPredictedMovement->fAy = 0.0f;
  }
  /* predict movement without stop */
  else 
  {
    pPredictedMovement->fX  = CDCalculateDistance(pMovement->fX, pMovement->fVx, pMovement->fAx, fPredictTime);
    /* pPredictedMovement->fVx has already been set before condition */
    pPredictedMovement->fAx = pMovement->fAx;
    pPredictedMovement->fY  = CDCalculateDistance(pMovement->fY, pMovement->fVy, pMovement->fAy, fPredictTime);
    /* pPredictedMovement->fVy has already been set before condition */
    pPredictedMovement->fAy = pMovement->fAy;
  }
}



#if (ACDC_CFG_TURN_ASSIST)
/*************************************************************************************************************************
  Functionname:         CDCalculateCorridorStopDistance                                                              */ /*!

  @brief                Calculates the depth in meters at which the target-vehicle's corridor gets penetrated by the
                        ego-vehicle assuming ego-vehicle starts decelerating immediately.

  @description          Calculates the depth at which the target-vehicle's corridor gets penetrated by the ego-vehicle
                        assuming ego-vehicle starts decelerating immediately with @ref DECELERATION_METER_PER_SECOND_SQUARED \n
                        (see function's body). Ego-vehicle's as well as target-vehicle's corridor are assumed to be straight
                        (not curved) and are approximated from the respective velocities. The calculated corridor stop \n
                        distance (CSD) (in meters) is measured along the shortest normal spanning from the ego-vehicle's
                        body to the nearest edge of the target-vehicles' corridor and are to be interpreted as follows: \n
                        .
                        |CSD [m]| meaning                                                                                             |
                        |:------|-----------------------------------------------------------------------------------------------------|
                        | >  0  | ego-vehicle comes IN FRONT of the target-vehicle's corridor to a standstill (does not penetrate it) |
                        | == 0  | ego-vehicle comes AT the target-vehicle's corridor to a standstill (touches it)                     |
                        | <  0  | ego-vehicle comes BEHIND (the edge) of the target-vehicle's corridor to a standstill (penetrates it)|

  @return               void

  @param[in]            iObjectIndex :          Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pCorridorStopDistance : Pointer to the variable the result should be written to

  @glob_in              @ref ACDC_p_GetEgoData         \n
                        @ref ACDC_p_GetVehPar          \n
                        @ref ACDC_p_GetACDCObjMovement \n
                        @ref ACDC_p_GetVDYDynObjSync   \n
                        @ref ACDC_p_GetVDYDynRaw       \n
                        @ref ACDC_p_ModObjHypothesisData
  @glob_out             None

  @c_switch_part        @ref CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_TURN_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
static void CDCalculateCorridorStopDistance(ObjNumber_t   const         iObjectIndex,
                                            fDistance_t         * const pCorridorStopDistance)
{
  /* constants */
  static const float32 DECELERATION_METER_PER_SECOND_SQUARED              = -6.0f;

  /* ego' data */
  ACDCEgoData_t const * const pEgoData                          = ACDC_p_GetEgoData();
  float32       const         fEgoLength                        = pEgoData->Geometry.fLength;
  float32       const         fEgoVelocityX                     = pEgoData->MovementRaw.Vel.fX; // velocity may also be negative
  float32       const         fAbsoluteEgoVelocity              = CML_f_Abs(fEgoVelocityX);
  float32       const         fEgoTimeToStandstill              = CML_f_Abs(fEgoVelocityX/DECELERATION_METER_PER_SECOND_SQUARED);
  float32       const         fWheelBase                        = ACDC_p_GetVehPar()->VehParMain.WheelBase;

  float32 const fEgoSteeringAngleRadians =
    CDCalculateSteeringAngle( fWheelBase,
      ACDC_p_GetVDYDynRaw()->Lateral.DrvIntCurve.Curve +
      (0.75f * ( (fEgoTimeToStandstill*ACDC_p_GetVDYDynRaw()->Lateral.DrvIntCurve.Gradient)) ) );

  float32       const         fTargetVelocityAbsX            = ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel.fX;
  float32       const         fTargetVelocityAbsY            = ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel.fY;

  float32       const         fPhi = // orientation of target's corridor
#if CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
    ACDC_p_ModObjHypothesisData(iObjectIndex)->
    sHypDrvIntoOncomingInternals.fSmObjectOrientationRad;
#else
  ATAN2_(fTargetVelocityAbsY, fTargetVelocityAbsX);
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */

  float32                     fDistanceToStopX;
  float32                     fDistanceToStopY;
  float32                     fDistanceToStopMagnitude;
  float32                     fResult                           = CD_DIST_MAX;

  /* target's data */
        CDObjectsCenterOfFront_t tCalculatedTargetParams;
        float32                  fTargetHalfWidth;
        float32                  fCosinePhi;

  tCalculatedTargetParams = CDCalculateObjectsCenterOfFront(iObjectIndex);
  fTargetHalfWidth        = tCalculatedTargetParams.fWidth * 0.5f;

  // calculate distanceToStop depending on whether the ego is moving forwards or backwards
  fDistanceToStopMagnitude = (fAbsoluteEgoVelocity + ((0.5f * DECELERATION_METER_PER_SECOND_SQUARED) * fEgoTimeToStandstill))*fEgoTimeToStandstill; // s = v*t + 0.5*a*t^2

  // For reverse driving ensure positive distance to stop magnitude
  if(fEgoVelocityX < 0.f)
  {
    fDistanceToStopMagnitude = -fDistanceToStopMagnitude;
  }

  fDistanceToStopX = fDistanceToStopMagnitude * COS_(fEgoSteeringAngleRadians); // ego's distance to stop in the x-direction
  fDistanceToStopY = fDistanceToStopMagnitude * SIN_(fEgoSteeringAngleRadians); // ego's distance to stop in the y-direction
  fCosinePhi       = COS_(fPhi);

  if(    (CML_f_IsZero(fTargetVelocityAbsX) == TRUE)
      || (CML_f_IsZero(fCosinePhi)                 == TRUE) )
  {
    /* assume target's corridor is orthonormal to ego's x-axis*/
    fResult = (tCalculatedTargetParams.centerOfFront.fX - fTargetHalfWidth) - fDistanceToStopX; // s = s_0 + v_0*t + 0.5at^2
  }
  else if(CML_f_IsZero(fTargetVelocityAbsY) == TRUE)
  {
    /* target's corridor is parallel with the ego's x-axis, overlapping distance is the CSD */
    fResult = ((CML_f_Abs(tCalculatedTargetParams.centerOfFront.fY) - CD_COLL_EGO_COLL_WIDTH) - fDistanceToStopY) - fTargetHalfWidth;
  }
  else
  {
    /* target's corridor is not normal to that of the ego nor parallel - general case */

    /* calculate the line running through the middle of the target's corridor y=kx+n where k-gradient and n-section on the y-axis */
    const float32 fK = TAN_(fPhi);
    const float32 fN = tCalculatedTargetParams.centerOfFront.fY - (fK*tCalculatedTargetParams.centerOfFront.fX);

    const float32 fTargetHalfWidthProjection = fTargetHalfWidth/CML_f_Abs(fCosinePhi); // projection of the half of the target's corridor onto y-axis

    /* correct n - translate target's beam to the left by the ego's stopping distance */
    const float32 fNTranslated = (fN + (fK*fDistanceToStopX)) - fDistanceToStopY;

    const float32 fK2 = -1.f/fK; // gradient of the line normal to target's corridor y_2 = k_2*x + n_2

    const boolean bIsEgoMovingTowardsCorridor = (boolean) ((-fN/fK) > 0.f); // corridor's intersection with the x-axis

    float32 fN2; // y-section of the line normal to target's corridor

    float32 fCX;
    float32 fCY;

    float32 fDX;
    float32 fDY;

    float32 fDistanceEgoToTargetCorridorMiddle;

    /* Do the chewing gum calculation:
    * As soon es the ego enters target's corridor the CSD becomes negative and remains negative while a part of ego's body is in target's corridor (chewing gum sticks).
    * The CSD however becomes positive as soon as the ego's body completely leaves the target's corridor (chewing gum snaps). The chewing gum effect can be summed up with the following two rules:
    * 1) Ego is currently in the target's corridor and ego is moving away from the corridor -> CSD is negative
    * 2) Ego is currently not in the target's corridor and is moving away from the corridor -> CSD is positive
    */
    float32 fUpperBeamLimit;
    float32 fLowerBeamLimit;
    boolean bTargetCorridorAlreadyPenetrated;
    boolean bIsChewingGumSnapped;
    // target's lower beam above upperBeamLimit or target's upper beam below lowerBeamLimit -> corridor not penetrated
    // use n = y-kx to determine the limits
    if(fK >= 0.f)
    {
      fUpperBeamLimit = CD_COLL_EGO_COLL_WIDTH - (fK*(-fEgoLength));
      fLowerBeamLimit = -CD_COLL_EGO_COLL_WIDTH;
    }
    else
    {
      fUpperBeamLimit = CD_COLL_EGO_COLL_WIDTH;
      fLowerBeamLimit = -CD_COLL_EGO_COLL_WIDTH - (fK*(-fEgoLength));
    }

    // ==> Bad code style
    bTargetCorridorAlreadyPenetrated = (boolean) (((fN - fTargetHalfWidthProjection) <= fUpperBeamLimit) && ((fN+fTargetHalfWidthProjection) >= fLowerBeamLimit));
    // ==> Really bad code style
    bIsChewingGumSnapped = (((bTargetCorridorAlreadyPenetrated == TRUE) || (bIsEgoMovingTowardsCorridor == TRUE)))?FALSE:TRUE;

    /* calculate the penetration normal to target's beam by taking ego's and target's width into account */
    if(fK < 0.0f)
    {
      if((bTargetCorridorAlreadyPenetrated == TRUE) || (bIsEgoMovingTowardsCorridor == TRUE))
      {
        fN2 = CD_COLL_EGO_COLL_WIDTH; // ego penetrates with the FL corner
      }
      else
      {
        fN2 = -CD_COLL_EGO_COLL_WIDTH; // ego penetrates with the FR corner - chewing gum snapped
      }
    }
    else
    {
      if((bTargetCorridorAlreadyPenetrated == TRUE) || (bIsEgoMovingTowardsCorridor == TRUE))
      {
        fN2 = -CD_COLL_EGO_COLL_WIDTH; // ego penetrates with the FR corner
      }
      else
      {
        fN2 = CD_COLL_EGO_COLL_WIDTH; // ego penetrates with the FL corner - chewing gum snapped
      }
    }

    /*
    * calculate the crossing point C = (x, y) of the normal y_2 = k_2*x + n_2 to the target's corridor y_1 = k_1*x + n_1 running through
    * the ego's penetrating front corner
    */
    // fK2 = 1/-fK therefore division by zero is not possible
    fCX = (fN2 - fNTranslated) / (fK - fK2);
    fCY = (fK*fCX) + fNTranslated;

    /*
    * Calculate the vector D of the ego's closer corner to the point C: D=C-Corner.
    *
    */
    fDX = fCX;
    fDY = fCY-fN2;

    /*
    * The length of D is the CorridorStopDistance without taking the target's width into account.
    */
    fDistanceEgoToTargetCorridorMiddle = SQRT(SQR(fDX) + SQR(fDY));
    if((fDX < 0.0f) && (bIsChewingGumSnapped == FALSE))
    {
      fDistanceEgoToTargetCorridorMiddle = - fDistanceEgoToTargetCorridorMiddle; // ego has penetrated the target's corridor
    }

    // lastly, take target's width into account
    fResult = fDistanceEgoToTargetCorridorMiddle - fTargetHalfWidth;
  }
  *pCorridorStopDistance = fResult;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateSteeringAngle                                                                     */ /*!

  @brief                Calculates the steering angle. Caution: not to be confused with a steering wheel angle.

  @description          Calculates the steering angle based on the given parameters. The function assumes a single-track
                        model of the vehicle.

  @return               float32 : steering angle: positive for a left-turn, negative for a right-turn. @phys_unit [rad]

  @param[in]            fWheelBase : Distance between the vehicle's axles. @range [0,+...[, @phys_unit [m]
  @param[in]            fCurvature : The curvature of the vehicle (multiplicative inverse of the rotation radius), may be zero.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_TURN_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     **Steering Angle:** \f$\arcsin(MinMax(-1,1,WheelBase \cdot Curve))\f$

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
static float32 CDCalculateSteeringAngle(float32 const fWheelBase,
                                        float32 const fCurvature)
{
  float32 fResult;

  if(CML_f_IsZero(fCurvature))
  {
    fResult = 0.0f;
  }
  else
  {
    const float32 fSineSteeringAngle = CML_f_MinMax(-1.0f, 1.0f, fWheelBase*fCurvature);
    fResult = ASIN_(fSineSteeringAngle);
  }

  return fResult;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateObjectsCenterOfFront                                                              */ /*!

  @brief                Calculates the object's Center Of Front (COF), width, length and orientation.

  @description          Calculates the COF (relative to ego), width and length of the specified object.

  @return               CDObjectsCenterOfFront_t: Struct containing results: COFx, COFy, width, length, orientation[radians] and index of the front edge}.

  @param[in]            iObjectIndex : Index of the object. @range [0,EM_N_OBJECTS]

  @glob_in              @ref ACDC_p_GetObjPositions     \n
                        @ref ACDC_p_GetEMGenObjGeometry \n
                        @ref AIP_i_GetShapePointIdx
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_TURN_ASSIST\n

  @pre                  None
  @post                 None

  @InOutCorrelation     not defined

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
CDObjectsCenterOfFront_t CDCalculateObjectsCenterOfFront(const ObjNumber_t iObjectIndex)
{

  CDObjectsCenterOfFront_t tResult;

  static const uint8 MAX_SHAPE_POINT_INDEX     = ACDC_NOF_SP_POSITIONS - 1u;
  SFLVector2D_t const * const pTargetPosition  = &(ACDC_p_GetObjPositions(iObjectIndex)->GenObject);
  const sint8 sFrontLeftIndex   = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_LEFT);
  const sint8 sFrontRightIndex  = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_RIGHT);

  const sint8 sRearLeftIndex    = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_LEFT);
  const sint8 sRearRightIndex   = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_RIGHT);

  const float32 fTargetPositionX = pTargetPosition->fX;
  const float32 fTargetPositionY = pTargetPosition->fY;

  SFLVector2D_t aShapePoints[CD_NUMBER_OF_EDGES_IN_A_RECTANGLE];
  SFLVector2D_t aEdges      [CD_NUMBER_OF_EDGES_IN_A_RECTANGLE];
  float32       aEdgeLengths[CD_NUMBER_OF_EDGES_IN_A_RECTANGLE];
  sint8         sDominantShapePointOrder = 0; // used to determine the order in which the shape points describe the object relative to Z-Axis (positive or negative)
  uint8         uIndex;

  /* Assure that the number of shape points of the object equals to that of a rectangle because the function expect that */
  ACDC_ASSERT( ACDC_NOF_SP_POSITIONS == CD_NUMBER_OF_EDGES_IN_A_RECTANGLE);

  /* 1) calculate the object's (target's) shape points relative to ego */
  for(uIndex = 0u; uIndex < CD_NUMBER_OF_EDGES_IN_A_RECTANGLE; ++uIndex)
  {
    aShapePoints[uIndex] = SFL_s_SetupVector2(
    fTargetPositionX + ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates[uIndex].fPosX,
    fTargetPositionY + ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates[uIndex].fPosY);
  }

  /* 2) calculate object's edges */
  for(uIndex = 0u; uIndex < CD_NUMBER_OF_EDGES_IN_A_RECTANGLE; ++uIndex)
  {
    aEdges[uIndex]       = SFL_s_SubVector2(aShapePoints[(uIndex+1u)%CD_NUMBER_OF_EDGES_IN_A_RECTANGLE], aShapePoints[uIndex]); // e_i = p_i+1 - p_i
    aEdgeLengths[uIndex] = SFL_f_GetVector2Length(aEdges[uIndex]);
  }

  /* 3) determine the index of the object's front edge */
  /* in most cases, index of an an edge is the smaller of the two adjacent shape point indices,
   * the only exception is when the adjacent shape points have indices 0 and ACDC_NOF_SP_POSITIONS-1 in which case an edge has the maximal possible index ACDC_NOF_SP_POSITIONS-1 */
  if(((sFrontLeftIndex==0) && (sFrontRightIndex==(sint8)MAX_SHAPE_POINT_INDEX)) || ((sFrontLeftIndex==(sint8)MAX_SHAPE_POINT_INDEX) && (sFrontRightIndex== 0)))
  {
    tResult.uFrontEdgeIndex = MAX_SHAPE_POINT_INDEX;
  }else
  {
    tResult.uFrontEdgeIndex = MIN((uint8)sFrontLeftIndex, (uint8)sFrontRightIndex);
  }

  /* 4) calculate COF */
  tResult.centerOfFront = SFL_s_AddVector2(aShapePoints[tResult.uFrontEdgeIndex], SFL_s_MultiplyScalarVector(0.5f, aEdges[tResult.uFrontEdgeIndex])); // corner where the edge starts + 0.5*edge

  /* 5) determine width: front and back edge, longer of the two is assumed to be the object's width */
  tResult.fWidth  = CML_f_Max(aEdgeLengths[tResult.uFrontEdgeIndex],
    aEdgeLengths[(tResult.uFrontEdgeIndex+CD_INDEX_OFFSET_OF_AN_OPPOSITE_EDGE_IN_A_RECTANGLE)%CD_NUMBER_OF_EDGES_IN_A_RECTANGLE]);

  /* 6) determine length: fronts neighboring edges, longer of the two assumed to be the object's length */
  tResult.fLength = CML_f_Max(aEdgeLengths[(tResult.uFrontEdgeIndex+1u)%CD_NUMBER_OF_EDGES_IN_A_RECTANGLE],
    aEdgeLengths[(tResult.uFrontEdgeIndex+CD_INDEX_OFFSET_OF_A_PREVIOUS_EDGE_IN_A_RECTANGLE)%CD_NUMBER_OF_EDGES_IN_A_RECTANGLE]);

  /* 7) determine the order in which the shape points describe the object */
  sDominantShapePointOrder += CML_Sign(sFrontLeftIndex - sFrontRightIndex);
  sDominantShapePointOrder += CML_Sign(sRearLeftIndex  - sFrontLeftIndex);
  sDominantShapePointOrder += CML_Sign(sRearRightIndex - sRearLeftIndex);

  /* 8) calculate a normalized normal to the object's front pointing away from its body */
  if(sDominantShapePointOrder > 0) // sign of the value is the sign of the shape point order relative to the Z-Axis
  {
    // normal to the edge pointing away from the object: (x_normal, y_normal) = (y_edge, -x_edge) === edge +90°
    tResult.normalizedNormalToFrontEdge = SFL_s_SetupVector2(aEdges[tResult.uFrontEdgeIndex].fY, -aEdges[tResult.uFrontEdgeIndex].fX);
  }
  else
  {
    // normal to the edge pointing away from the object: (x_normal, y_normal) = (-y_edge, x_edge) === edge -90°
    tResult.normalizedNormalToFrontEdge = SFL_s_SetupVector2(-aEdges[tResult.uFrontEdgeIndex].fY, aEdges[tResult.uFrontEdgeIndex].fX);
  }
  tResult.normalizedNormalToFrontEdge = SFL_s_CalculateNormalizedVector(tResult.normalizedNormalToFrontEdge);

  return tResult;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetCorridorStopDistance                                                                */ /*!

  @brief                Returns the corridor stop distance

  @description          Returns the corridor stop distance

  @return               float32 : fCorridorStopDistance of the considered object @phys_unit [m] @range [0,\ref TBD]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjEvasionData
  @glob_out             @ref ACDC_p_ModObjEvasionData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref ACDC_CFG_TURN_ASSIST

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com
*************************************************************************************************************************/
float32 CD_f_GetCorridorStopDistance( ObjNumber_t const iObjectIndex)
{

  CDObj_Evasion_t const * const pEvasion = ACDC_p_GetObjEvasionData(iObjectIndex);

  if (pEvasion->fCorridorStopDistance > CD_CORRIDORSTOPDIST_CHECK)
  {
    float32 * const pCorridorStopDistance =
      &(ACDC_p_ModObjEvasionData(iObjectIndex)->fCorridorStopDistance);

    CDCalculateCorridorStopDistance(iObjectIndex, pCorridorStopDistance);
  }
  return pEvasion->fCorridorStopDistance;
}
#endif /* #if (ACDC_CFG_TURN_ASSIST) */

#if(!CD_USE_CONST_OBJ_GEOMETRY_VAR)
/*************************************************************************************************************************
  Functionname:         CDCalcGeometryVarianceFromShapePoints                                                        */ /*!

  @brief                Calculates the variance of the objects geometry (Width/Length).

  @description          The geometrical variance of an object shall be defined as the variance of an object extension 
                        in longitudinal or lateral direction. Assuming e.g. an object of the orientation 0°, the variance \n
                        of the objects length corresponds to the variance of the longitudinal extension.\n
                        The variance of the extension is determined by the medium variance of the objects vectors that point 
                        into the considered direction. E.g. Longitudinal variance: \n
                        \f$XVar_{Left} = XVar_{Left,Front} + XVar_{Left,Rear}\f$ \n
                        \f$XVar_{Right} = XVar_{Right,Front} + XVar_{Right,Rear}\f$ \n
                        \f$XVar = \frac{XVar_{Left} + XVar_{Right}}{2}\f$  \n
                        @startuml CDCalcGeometryVarianceFromShapePoints_activity.png
                          start
                            :Sum Up the X Variances of all ShapePoints;
                            :Sum Up the Y Variances of all ShapePoints;
                            :Divide the Lateral and the 
                            Longitudinal Sum by 2 to get 
                            the overall **Lateral Variance** 
                            and **Longitudinal Variance**;
                            note left: >see Formula **Geometry Variance**
                            :Project the Variances onto the current 
                            Object Orientation to get the **WidthVar** 
                            and **LengthVar**;
                            note left: see Formula: **Project Variances**

                          stop
                        @enduml

  @return               float32: Geometrical variance in X / in Y Direction. @range[0,+...[, @phys_unit[div]

  @param[in]            aShapePoints :  Data regarding the shape points.
  @param[in]            bLongitudinal : Flag indicating of which direction the variance shall be returned (TRUE for longitudinal).

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_CONST_OBJ_GEOMETRY_VAR

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Geometry Variance:**\n
                        \f$Var_{X/Y} = \sum{(X/Y_{ShapePoint,StdDev})^2}\f$
                        - **Formula Project Variances:** \n
                        \f$Var_{Width}  = |\cos(Orientation) \cdot Var_{Lateral}| + |\sin(Orientation) \cdot Var_{Longitudinal}|\f$ \n
                        \f$Var_{Length} = |\sin(Orientation) \cdot Var_{Lateral}| + |\cos(Orientation) \cdot Var_{Longitudinal}|\f$

  @testmethod           @Generic_Testmethods

  @remark               As the shape point standard deviations are currently always 0, this function has not been tested yet!
                        Test it before deactivating the switch @ref CD_USE_CONST_OBJ_GEOMETRY_VAR.
                        Works only for 4 Shapepoints.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void CDCalcGeometryVarianceFromShapePoints(ObjNumber_t iObjectIndex, ACDCGeometry_t * const GeometryVar)
{
  uint32  uShapePointNo;
  float32 fSinOrientation;
  float32 fCosOrientation;
  float32 fVarLateral;
  float32 fVarLongitudinal;
  float32 fVarWidth;
  float32 fVarLength;
  float32 fSumVarLongitudinal = 0.f;
  float32 fSumVarLateral      = 0.f;
  const float32 fOrientation  = ACDC_p_GetEMARSObjGeometry(iObjectIndex)->fOrientation;

  for (uShapePointNo = 0u; uShapePointNo < EM_GEN_OBJ_N_SHAPE_POINTS; ++uShapePointNo)
  {
    /* Sum up all variances of one direction (X: Longitudinal, Y: Lateral; Variance = StdDev^2)*/
      const float32 fCurrXStd  = (float32)(ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates[uShapePointNo].uiPosXStd);
      const float32 fCurrYStd  = (float32)(ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates[uShapePointNo].uiPosYStd);
      fSumVarLongitudinal     += SQR(fCurrXStd);
      fSumVarLateral          += SQR(fCurrYStd);
  }
  /* Divide the Sum by 2 to get the overall variance > more details: see description*/
  fVarLateral      = 0.5f * fSumVarLateral;
  fVarLongitudinal = 0.5f * fSumVarLongitudinal; 

  /* Project the longitudinal / lateral variances onto the current orientation */
  GDBsincos(fOrientation,&fSinOrientation, &fCosOrientation);
  fVarWidth  = fABS(fCosOrientation * fVarLateral) + fABS(fSinOrientation *fVarLongitudinal);
  fVarLength = fABS(fSinOrientation * fVarLateral) + fABS(fCosOrientation *fVarLongitudinal);

  GeometryVar->fLength      = fVarLength;
  GeometryVar->fWidth       = fVarWidth;
  GeometryVar->fOrientation = 0.f;
}
#endif /* CD_USE_CONST_OBJ_GEOMETRY_VAR */
//!@}

#endif /* #if (ACDC_CFG_CD) */



