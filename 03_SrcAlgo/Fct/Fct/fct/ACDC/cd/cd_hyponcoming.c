/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hyponcoming.c

DESCRIPTION:               Implementation of the oncoming hypothesis

AUTHOR:                    $Author: Maksuti, Zijad (uid32055) $

CREATION DATE:             $Date: 2020/01/10 14:56:49CET $

VERSION:                   $Revision: 1.28 $

**************************************************************************** */

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
/*****************************************************************************
  MODULE DESCRIPTION 
*****************************************************************************/
/**
@defgroup cd_hyponcoming HypOncoming
@ingroup cd

@brief          The Oncoming Hypothesis describes a scenario in which the ego vehicle turns into a lane with oncoming traffic.

@description    The processing of the hypothesis follows the common hypothesis calculation steps. It is executed \n
                by the main external function of the module: @ref CD_v_HypoOncomingMain.
@{
*/
/*****************************************************************************
TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
(SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief 1m of longitudinal object's distance results in rise (or fall) of CD_HYPONCOMING_LONG_PROB_SLOPE of longitudinal probability.
 *! @see CD_v_HypOncomingCalcProb for more detail
    @typical -0.00878f @max -C_F32_DELTA */
#define CD_HYPONCOMING_LONG_PROB_SLOPE          (-0.00878f)

/*! @brief Longitudinal probability at object's dLong=0m @see CD_v_HypOncomingCalcProb for more detail
    @typical -0.00878f @max -C_F32_DELTA */
#define CD_HYPONCOMING_LONG_PROB_AT_DLONG_ZERO  ( 0.9f    )

/*! @brief 1m of lateral object's distance results in rise (or fall) of CD_HYPONCOMING_LAT_PROB_SLOPE of lateral probability.
 *! @see CD_v_HypOncomingCalcProb for more detail
    @typical -0.01018f @max -C_F32_DELTA */
#define CD_HYPONCOMING_LAT_PROB_SLOPE          (-0.01018f )

/*! @brief Lateral probability at object's dLat=0m @see CD_v_HypOncomingCalcProb for more detail
    @typical -0.00878f @max -C_F32_DELTA */
#define CD_HYPONCOMING_LAT_PROB_AT_DLAT_ZERO   ( 0.9f     )

/*****************************************************************************
VARIABLES 
*****************************************************************************/

/*****************************************************************************
LOCAL FUNCTIONS
*****************************************************************************/
static boolean CD_b_ObjectStandingOrMovingTowardsStraightCorridor                   (ObjNumber_t const iObjectIndex);
static boolean CD_b_HypOncomingObjectFilter                                         (ObjNumber_t const iObjectIndex);
static boolean CD_b_IsObjRelevByEMDynPropEMClass(const ObjNumber_t iObjectIndex);
static void    CD_v_HypOncomingCalcProb                                             (ObjNumber_t const iObjectIndex, float32 *const pfHypOncomingProb );

#if (CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION)

static void CD_v_UpdateHypOncomingInternalData(ObjNumber_t const iObjectIndex);

/*************************************************************************************************************************
  Functionname:         CDHypoDrvIntOncInitInternalData                                                                */ /*!

  @brief                Initializes the internal data of an object for
                        hypothesis of type
                        \ref CDHypothesisType_DriveIntoOncoming.

  @description          Initializes the internal data of an object for
                        hypothesis of type
                        \ref CDHypothesisType_DriveIntoOncoming by filling it
                        with default values.
                        Currently this internal data consists only of one value
                        per object:
                        CDInternalObjHypDrvIntoOncoming_t.fSmObjectOrientationRad
                        which initialized with -CML_f_two_Pi.

  @return               void

  @param[in]            iObjectIndex : Index of the object whose internal data
                        shall be initialized. @range [0, EM_N_OBJECTS[

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref ACDC_CFG_TURN_ASSIST \n
                        @ref CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
void CDHypoDrvIntOncInitInternalData(ObjNumber_t const iObjectIndex)
{
  /*! @brief  Value to which
   *! \ref CDInternalObjHypDrvIntoOncoming_t.fSmObjectOrientationRad is
   *! initialized. @range N/A @typical -2*Pi
   *! The value of -2*Pi is chosen because it differs from a "real" value which
   *! the smoothened oriantation can have: [0; 2*pi[. It can be easily tested
   *! with fObjectSmOrientationInitVal < -Pi without worrying about the
   *! numerical stability: for example you don't have to use CML_f_Delta */
  static const float32 fObjectSmOrientationInitVal = (-CML_f_two_Pi);

  CDInternalObjHypDrvIntoOncoming_t * const sInternalData =
    &(ACDC_p_ModObjHypothesisData(iObjectIndex)->sHypDrvIntoOncomingInternals);

  sInternalData->fSmObjectOrientationRad = fObjectSmOrientationInitVal;
}

/*************************************************************************************************************************
  Functionname:         CD_v_UpdateHypOncomingInternalData                                                                */ /*!

  @brief                Initializes the internal data of an object for
                        hypothesis of type
                        \ref CDHypothesisType_DriveIntoOncoming.

  @description          Updates the internal data of an object for hypothesis
                        of type \ref CDHypothesisType_DriveIntoOncoming.
                        Currently this internal data consists only of one value
                        per object:
                        CDInternalObjHypDrvIntoOncoming_t.fSmObjectOrientationRad
                        which is the smoothened orientation of object's velocity
                        vector.
                        If the smoothened orientation contains a default value
                        after initialization (see
                        \ref CDHypoDrvIntOncInitInternalData) this function will
                        fill it with the measured value.
                        Else the function will
                        fill the new smoothened value after applying a low
                        pass filter (see \ref CML_f_LowPassFilter2) on previous
                        smoothened value and the (current) measured value. The
                        filter is applied so that the measured value is weighted
                        with the coefficient
                        \ref CD_HYP_ONCOMING_FLTR_COEF_ORIENT_SMOOTHING and the
                        previous value is weighted with the coefficient 1 -
                        \ref CD_HYP_ONCOMING_FLTR_COEF_ORIENT_SMOOTHING.

  @return               void

  @param[in]            iObjectIndex : Index of the object whose internal data
                        shall be updated. @range [0, EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_ModObjHypothesisData
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref ACDC_CFG_TURN_ASSIST \n
                        @ref CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
static void CD_v_UpdateHypOncomingInternalData(ObjNumber_t const iObjectIndex)
{
  float32 const fObjectVelocityX =
    ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel.fX;
  float32 const fObjectVelocityY =
    ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel.fY;

  float32 const fRawObjectOrientation =
    (ATAN2_(fObjectVelocityY, fObjectVelocityX));

  /* Normalize the value returned by ATAN2_() to [0, 2*pi[ */
  float32 const fRawObjectOrientationNormalized =
    SFL_f_NormalizeRadiansToTwoPi(fRawObjectOrientation);

  CDInternalObjHypDrvIntoOncoming_t * const sInternalData =
    &(ACDC_p_ModObjHypothesisData(iObjectIndex)->sHypDrvIntoOncomingInternals);

  if( sInternalData->fSmObjectOrientationRad < (-CML_f_Pi) )
  {
    /* sInternalData->fSmObjectOrientationRad currently contains the init-value,
     * fill it with current object's orientation as smoothened orientation.
     * If the hypothesis continues to live, real smoothened value will be filled
     * in the next cycle.
     * */
    sInternalData->fSmObjectOrientationRad = fRawObjectOrientationNormalized;
  }
  else
  {
    /* we have a value from previous cycle, use that and the current value
     * to calculate the smoothened one */
    (CML_f_LowPassFilter2(
      &sInternalData->fSmObjectOrientationRad, fRawObjectOrientationNormalized,
      CD_HYP_ONCOMING_FLTR_COEF_ORIENT_SMOOTHING));

    /* for numerical stability and fail safety, perform an additional
     * normalization after filter application */
    sInternalData->fSmObjectOrientationRad =
      SFL_f_NormalizeRadiansToTwoPi(sInternalData->fSmObjectOrientationRad);
  }
}

#endif /*CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION*/



/*************************************************************************************************************************
  Functionname:         CD_b_ObjectStandingOrMovingTowardsStraightCorridor                                            */ /*!

  @brief                Checks if the object is standing or moving towards the ego vehicles corridor.

  @description          Returns true when an object is standing or moving towards ego's straight corridor.
                        This function assumes that the ego's corridor is a straight line parallel to ego's
                        orientation, running trough its center of front.

  @return               boolean: >see InOutCorrelation

  @param[in]            iObjectIndex : Index of the considered object. @range [0,EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetObjMovement \n
                        @ref ACDC_p_GetObjPositions
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS\n

  @pre                  None
  @post                 None

  @InOutCorrelation
                        | Target                          | Return |
                        |:--------------------------------|:-------|
                        |Moving towards ego's corridor    |  TRUE  |
                        |Moving away from ego's corridor  |  FALSE |
                        |Moving parallel to ego's corridor|  TRUE  |
                        |Not moving                       |  TRUE  |

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
static boolean CD_b_ObjectStandingOrMovingTowardsStraightCorridor(ObjNumber_t const iObjectIndex)
{
  SFLVector2D_t const * const pObjVelAbs = &(ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel);
  const float32 fDistYTarget             = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fY;
  const float32 fAbsoluteVelocityTargetX = pObjVelAbs->fX;
  const float32 fAbsoluteVelocityTargetY = pObjVelAbs->fY;
        boolean bResult;

  if(CML_f_IsZero(fAbsoluteVelocityTargetY) == FALSE)
  {
    if(    ((fDistYTarget  > CD_COLL_EGO_COLL_WIDTH) && (fAbsoluteVelocityTargetY  > CML_f_AlmostZero)   )
        || ((fDistYTarget <  CD_COLL_EGO_COLL_WIDTH) && (fAbsoluteVelocityTargetY <  CML_f_AlmostNegZero)) )
    {
      /* target is left of ego's corridor and is moving left or target is right of ego's corridor and moving right ==> target moving away from corridor */
      bResult = FALSE;
    }
    else
    {
      /* target moving towards corridor */
      bResult = TRUE;
    }
  }
  else if(CML_f_IsZero(fAbsoluteVelocityTargetX) == FALSE)
  {
    /* target moving parallel to ego's corridor ==> function returns true */
    bResult = TRUE;
  }
  else
  {
    /* target is not moving */
    bResult = TRUE;
  }

  return bResult;
}

/*************************************************************************************************************************
  Functionname:         CD_b_HypOncomingObjectFilter                                                                    */ /*!

  @brief                Checks whether an object is relevant for the oncoming hypothesis.

  @description          The function first assumes that an object with the specified index is relevant. It than performers a
                        series of examinations and declares the object as irrelevant when at least one of the following applies:
                         1. Object is not relevant by its EM dynamic property or EM class. See @ref CD_b_IsObjRelevByEMDynPropEMClass
                         2. Ego's velocity exceeds a specified value. See @ref TURN_ASSIST_MAX_VELOCITY.
                         3. Object is not getting closer.
                         4. Object is moving in the same direction.
                         5. Object is not in front of the Center of Front.
                         6. Object is not within the specified aperture angle specified from the ego's Center of Front. See @ref APERTURE_ANGLE_DEGREES.
                         7. Object is not encircled by ego's corridor and its distance to the corridor is increasing.
                         8. Object's trajectory does not cross nor touches that of the ego.

  @return               boolean : True if the object is relevant for the oncoming hypothesis

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetObjPositions \n
                        @ref ACDC_p_GetObjMovement  \n
                        @ref ACDC_p_GetVDYDynRaw    \n
                        @ref ACDC_f_GetEgoVelObjSync\n
                        @ref ACDC_p_GetEgoGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti  | Zijad.Maksuti@continental-corporation.com
  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com
*************************************************************************************************************************/
static boolean CD_b_HypOncomingObjectFilter(ObjNumber_t const iObjectIndex)
{
  static const float32 TURN_ASSIST_MAX_VELOCITY = 8.89f; /* 32/3.6 = 8.89m/s all objects ignored if ego exceeds this velocity */
  static const float32 APERTURE_ANGLE_DEGREES = 180.f; /* all objects not within this angle are irrelevant, >>see illustration below<<< */
         const float32 HALF_APERTURE_ANGLE    = CML_Deg2Rad(APERTURE_ANGLE_DEGREES) * 0.5f; /* a helper-variable for easier calculation */
  SFLVector2D_t     const * const  pACDCObjPos              = &(ACDC_p_GetObjPositions(iObjectIndex)->GenObject);
  ACDCObjMovement_t const * const  pACDObjMovement          = ACDC_p_GetObjMovement(iObjectIndex);
  const float32                    fRelativeVelocityTargetX = pACDObjMovement->Rel.Vel.fX;
  const float32                    fDistXTarget             = pACDCObjPos->fX;
  const float32                    fDistYTarget             = pACDCObjPos->fY;

  const float32                    fAbsoluteVelocityTargetX = pACDObjMovement->Abs.Vel.fX;

        boolean                    bAcceptObj               = CD_b_IsObjRelevByEMDynPropEMClass(iObjectIndex);

  const float32                    fDriverIntededCurve      = ACDC_p_GetVDYDynRaw()->Lateral.DrvIntCurve.Curve;

  const float32 fEgoXVelocity = ACDC_f_GetEgoVelObjSync();

  if (fEgoXVelocity > TURN_ASSIST_MAX_VELOCITY)
  {
    bAcceptObj = FALSE;
  }

  /*
  * ######## DIRECTION OF MOVEMENT FILTERING ########
  *
  * If an object is not moving towards the ego-vehicle (relative to ego) it is not relevant.
  */
  if(fRelativeVelocityTargetX >= CML_f_AlmostZero)
  {
    bAcceptObj = FALSE;
  }

  /*
  * If an object is moving in the same direction as we are it is not relevant
  */
  if(fAbsoluteVelocityTargetX >= CML_f_AlmostZero)
  {
    bAcceptObj = FALSE;
  }

  /*
  * ######## APERTURE FILTERING ########
  *
  * All objects not within the APERTURE_ANGLE phi are irrelevant.
  *
  * \          /
  *  \  phi   /
  *   \      /
  *    \    /
  *     \  /
  *      \/
  *    ------
  *    | /\ |
  *    |/  \|
  *    |----|
  *    |    |
  *    ------
  *
  */
  if(fDistXTarget < CML_f_AlmostZero)
  {
    // must be in front of the ego-vehicle
    bAcceptObj = FALSE;
  }
  if(CML_f_Abs(ATAN2_(fDistYTarget, fDistXTarget)) > HALF_APERTURE_ANGLE)
  {
    // check if within aperture
    bAcceptObj = FALSE;
  }

  /*
  * ######## TRAJECTORY BASED FILTERING ########
  * A target is irrelevant when one of the following applies:
  * The target is not encircled by ego's corridor AND its distance to ego's corridor is increasing (the target is moving away).
  * The target's trajectory does not cross that of the ego.
  */
  /* calculate ego's center of rotation */
  if(((-(CML_f_Delta)) < fDriverIntededCurve) && (fDriverIntededCurve < CML_f_Delta))
  {
    /* case 1 - ego's corridor is straight */
    const boolean bIsObjectStandingOrMoving = CD_b_ObjectStandingOrMovingTowardsStraightCorridor(iObjectIndex);
    bAcceptObj = ((bAcceptObj == TRUE) && (bIsObjectStandingOrMoving == TRUE))? TRUE : FALSE;
  }
  else
  {
    /* case 2 - ego's corridor is a curve */
    const float32 fCenterOfRotationX                = (-(ACDC_p_GetEgoGeometry()->fLength)) * 0.75f; // three quarters of ego's length
    const float32 fCenterOfRotationY                = 1.f / fDriverIntededCurve;
    const float32 fTargetToCenterOfRotationX        = fDistXTarget - fCenterOfRotationX;
    const float32 fTargetToCenterOfRotationY        = fDistYTarget - fCenterOfRotationY;
    const float32 fDistanceTargetToCenterOfRotation = SQRT(SQR(fTargetToCenterOfRotationX) + SQR(fTargetToCenterOfRotationY));
    const float32 fEgosOuterCurveRadius             = CML_f_Abs(fCenterOfRotationY) + CD_COLL_EGO_COLL_WIDTH;

    if(fDistanceTargetToCenterOfRotation > fEgosOuterCurveRadius)
    {
      /* target is outside of the ego's curve */
      const float32 fAbsoluteVelocityTargetY = pACDObjMovement->Abs.Vel.fY;

      if(CML_f_IsNonZero(fAbsoluteVelocityTargetX) || CML_f_IsNonZero(fAbsoluteVelocityTargetY))
      {
        /* target is moving */
        /*
        * Distance of the target to the center of rotation d = ((x_0+v_x*t)^2 + (y_0+v_y*t)^2)^0.5
        * First derivative for t=0 is d' = ((x_0^2+y_0^2)^(-0.5)) * (x_0*v_x + y_0*v_y)
        * Target is moving away from ego's corridor if and only if d' > 0
        * Since the divisor is always positive, the divisor can be omitted in the calculation because
        * : d'>0 <=> x_0*v_x + y_0*v_y > 0
        */
        const float32 fTargetToCenterOfRotationDerivative =
          (fTargetToCenterOfRotationX * fAbsoluteVelocityTargetX) + (fTargetToCenterOfRotationY * fAbsoluteVelocityTargetY);

        if(fTargetToCenterOfRotationDerivative > CML_f_AlmostZero)
        {
          /* target is moving away from the corridor */
          bAcceptObj = FALSE;
        }
        else
        {
          /* check whether target's corridor touches or cuts ego's curve */
          if(CML_f_IsZero(fAbsoluteVelocityTargetX))
          {
            /* target's corridor is normal to the x-axis  */
            if(CML_f_Abs(fTargetToCenterOfRotationX) > fEgosOuterCurveRadius)
            {
              /* target's and ego's corridor do not cross nor touch */
              bAcceptObj = FALSE;
            }
          }
          else if(CML_f_IsZero(fAbsoluteVelocityTargetY))
          {
            /* target's corridor is normal to the y-axis */
            if(CML_f_Abs(fTargetToCenterOfRotationY) > fEgosOuterCurveRadius)
            {
              /* target's and ego's corridor do not cross nor touch */
              bAcceptObj = FALSE;
            }
          }
          else
          {
            const float32 fK       = fAbsoluteVelocityTargetY / fAbsoluteVelocityTargetX; // gradient of target's corridor
            const float32 fN       = fTargetToCenterOfRotationY - (fK*fTargetToCenterOfRotationX); // y-section of target's corridor
            const float32 fKNormal = - (fAbsoluteVelocityTargetX / fAbsoluteVelocityTargetY); // -1/k gradient of the line normal to target's corridor running through ego's center of rotation
            // nNormal = 0 because n is set relative to ego's center of rotation
            const float32 fTemp    = fKNormal-fK;

            if(CML_f_IsZero(fTemp))
            {
              /* target's corridor has a very large distance to ego's center of rotation which may lead to numerical instability */
              /* target's and ego's corridor do not cross nor touch */
              bAcceptObj = FALSE;
            }
            else
            {
              const float32 fCenterOfRotToTargetsCorridorX                 = fN / fTemp;
              const float32 fCenterOfRotToTargetsCorridorY                 = fKNormal * fCenterOfRotToTargetsCorridorX;
              const float32 fDistanceEgosCenterOfRotationToTargetsCorridor =
                SQRT(SQR(fCenterOfRotToTargetsCorridorX) + SQR(fCenterOfRotToTargetsCorridorY));

              if(fDistanceEgosCenterOfRotationToTargetsCorridor > fEgosOuterCurveRadius)
              {
                /* target's and ego's corridor do not cross nor touch */
                bAcceptObj = FALSE;
              }
            }
          }
        }
      }
    }
  }

  return bAcceptObj;

}

/*************************************************************************************************************************
  Functionname:         CD_b_IsObjRelevByEMDynPropEMClass                                                                    */ /*!

  @brief                Checks whether an object with the specified index is relevant for the oncoming hypothesis 
                        by its EM property and EM class.

  @description          The function first assumes that an object with the specified index is relevant. It than performers a 
                        series of examinations and declares the object as irrelevant when at least one of the following applies:
                         1. Object is stationary. See @ref EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY.
                         2. Object is crossing left or crossing right. See @ref EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT 
                            and @ref EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT.
                         3. Object has stopped (but was moving before). See @ref EM_GEN_OBJECT_DYN_PROPERTY_STOPPED.
                         4. Object is not a car, truck nor motorcycle. See @ref EM_GEN_OBJECT_CLASS_CAR and @ref EM_GEN_OBJECT_CLASS_MOTORCYCLE.
                         5. Confidence in object's class is lower than @ref fMinObjClassConfidencePercent

  @return               boolean : True if the object is relevant for the oncoming hypothesis

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetEMGenObj
  @
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti  | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
static boolean CD_b_IsObjRelevByEMDynPropEMClass(const ObjNumber_t iObjectIndex)
{
  const float32 fMinObjClassConfidencePercent  = 78.f; /* confidence in object's class must has to be higher than this value */

  EM_t_GenObject const * const     pEMObject                = ACDC_p_GetEMGenObj(iObjectIndex);
  const EM_t_GenObjDynamicProperty eDynProp                 = pEMObject->Attributes.eDynamicProperty;
  const EM_t_GenObjClassification  eObjClass                = pEMObject->Attributes.eClassification;

  boolean bResult = TRUE;

  if (eDynProp == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
  {
    bResult = FALSE;
  }

  if ((eDynProp == EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT) || (eDynProp == EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT))
  {
    bResult = FALSE;
  }

  if (eDynProp == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)
  {
    bResult = FALSE;
  }

  if ((eObjClass != EM_GEN_OBJECT_CLASS_CAR) && (eObjClass != EM_GEN_OBJECT_CLASS_MOTORCYCLE)
#if (CD_HYP_ONCOMING_USE_TRUCK_OBJECT == SWITCH_ON)
      && (eObjClass != EM_GEN_OBJECT_CLASS_TRUCK))
#else
    )
#endif /*CD_HYP_ONCOMING_USE_TRUCK_OBJECT*/
  {
    bResult = FALSE;
  }

  if((float32)pEMObject->Attributes.uiClassConfidence < fMinObjClassConfidencePercent)
  {
    // confidence in object's class is not high enough
    bResult = FALSE;
  }

  return bResult;
}
/*************************************************************************************************************************
Functionname:         CD_v_HypOncomingCalcProb                                                                        */ /*!

@brief                Calculates the Oncoming Hypothesis Probability for an object with the given index.

@description          The probability is calculated as follows pfHypOncomingProb = p_long * p_lat where:
                        p_long = CD_HYPONCOMING_LONG_PROB_SLOPE*dLong + CD_HYPONCOMING_LONG_PROB_AT_DLONG_ZERO with dLong being longitudinal distance of object's Center of Front
                        p_lat  = CD_HYPONCOMING_LAT_PROB_SLOPE*dLat  + CD_HYPONCOMING_LAT_PROB_AT_DLAT_ZERO with dLat being lateral distance of object's Center of Front

                      The resulting distribution of the calculated probability is given in the following heatmap:
                      please insert heatmap



@return               void

@param[in]            iObjectIndex :      Index of the considered object. @range [0, EM_N_OBJECTS[
@param[in,out]        pfHypOncomingProb : Probability of the oncoming hypothesis. @range [0,1]

@glob_in              @ref CDCalculateObjectsCenterOfFront
@glob_out             None

@c_switch_part        None
@c_switch_full        @ref ACDC_CFG_CD\n
@ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS\n

@pre                  None
@post                 None

@InOutCorrelation     Not defined

@testmethod           @Generic_Testmethods

@author               Zijad Maksuti  | Zijad.Maksuti@continental-corporation.com
*************************************************************************************************************************/
static void CD_v_HypOncomingCalcProb(ObjNumber_t const iObjectIndex, float32 * const pfHypOncomingProb)
{
  CDObjectsCenterOfFront_t cof;
  float32 fAbsDistX;
  float32 fLongProb;
  float32 fAbsDistY;
  float32 fLatProb;
  float32 fResultingProbability;

  cof = CDCalculateObjectsCenterOfFront(iObjectIndex);

  fAbsDistX = CML_f_Abs(cof.centerOfFront.fX);
  fLongProb = (CD_HYPONCOMING_LONG_PROB_SLOPE * fAbsDistX) + CD_HYPONCOMING_LONG_PROB_AT_DLONG_ZERO; // pLong = -0.00878*dLong + 0.9

  fAbsDistY = CML_f_Abs(cof.centerOfFront.fY);
  fLatProb  = (CD_HYPONCOMING_LAT_PROB_SLOPE * fAbsDistY) + CD_HYPONCOMING_LAT_PROB_AT_DLAT_ZERO; // pLat  = -0.01018*dLat  + 0.9

  fResultingProbability = fLongProb * fLatProb;

  *pfHypOncomingProb = MINMAX(0.f, 1.f, fResultingProbability); // MINMAX for fail-safety
}

/*************************************************************************************************************************
  Functionname:         CD_v_HypoOncomingMain                                                                           */ /*!

  @brief                Handles the main processing steps of the oncoming hypothesis. \n\n

  @description          Handles the oncoming hypothesis by executing the three common steps for a hypothesis
                        generation (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CD_b_HypOncomingObjectFilter
                        2. Call of the Hypothesis probability calculation: @ref CD_v_HypOncomingCalcProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the three main steps that are described in the diagram
                        can be found in the description of the @ref cd_hyphandler.
                        @image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"
                        \n\n


                        If the switch
                        \ref CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
                        is turned on, this function additionally initializes
                        and updates object's internal data for the hypothesis of
                        type \ref CDHypothesisType_DriveIntoOncoming as
                        follows:\n\n

                        An object with the specified index has passed all
                        filters and the internal hypothesis has been created
                        through invocation of
                        \ref CDHypSelCreateInternalHypotheses &rarr;
                        Subsequently update the internal data of the object by
                        invoking \ref CD_v_UpdateHypOncomingInternalData. \n

                        All other cases &rarr; Initialize internal data of the
                        object by invoking \ref CDHypoDrvIntOncInitInternalData.


  @return               void

  @param[in]            iObjectIndex :      Index of the considered object. @range [0, EM_N_OBJECTS[
  @param[in]            bObjFilterMatched : Boolean indicating whether the object object matched the filter.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS\n

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Zijad Maksuti  | Zijad.Maksuti@continental-corporation.com
  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com
*************************************************************************************************************************/
void CD_v_HypoOncomingMain( ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched)
{
  CDObj_Hypothesis_t * const pObjHypData   = ACDC_p_ModObjHypothesisData(iObjectIndex);
  CDIntHypothesis_t Hypothesis;

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), CDHypothesisType_DriveIntoOncoming);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), CDHypothesisType_DriveIntoOncoming);

  /* Default Hypothesis Prob Calculation calling */
  if( bObjFilterMatched != FALSE )
  {
    if( CD_b_HypOncomingObjectFilter(iObjectIndex) != FALSE )
    {
      /* Default Hypothesis handling */
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), CDHypothesisType_DriveIntoOncoming);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_DriveIntoOncoming);

      CD_v_HypOncomingCalcProb( iObjectIndex, &(Hypothesis.fHypothesisProbability) );

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > CD_HYP_ONCOMING_ACTIVE_THRESHOLD)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), CDHypothesisType_DriveIntoOncoming);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
#if CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
        // Internal data can be updated, hypothesis is being created here
        // or lives on, update values for this iObjectIndex
        CD_v_UpdateHypOncomingInternalData(iObjectIndex);
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */
      }
#if CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
      else
      {
        // hypothesis for this object is maybe being destroyed here
        // initialize values to defaults for this iObjectIndex
        CDHypoDrvIntOncInitInternalData(iObjectIndex);
      }
#endif
    }
#if CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
    else
    {
      // hypothesis for this object is maybe being destroyed here
      // initialize values to defaults for this iObjectIndex
      CDHypoDrvIntOncInitInternalData(iObjectIndex);
    }
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */
  }
#if CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
  else
  {
    // hypothesis for this object is maybe being destroyed here
    // initialize values to defaults for this iObjectIndex
    CDHypoDrvIntOncInitInternalData(iObjectIndex);
  }
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */
}


/*!@}*/
#endif  /* #if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */
/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */
