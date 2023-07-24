
/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculatettanec.c

DESCRIPTION:               The calculation of necessary acceleration for CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 07:47:03CEST $

VERSION:                   $Revision: 1.21 $
*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"
#if (ACDC_CFG_CD)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_calculateanec Calculate Anec
@ingroup cd

@brief          The calculation of the necessary longitudinal and lateral acceleration to avoid a collision is done in this module \n\n

@description    Provides functions for the calculation of the different derivations of the Anec: \n
                  @ref CD_f_GetLongNecAccel      \n
                  @ref CD_f_GetLatNecAccel       \n
                  @ref CD_f_GetLatNecAccelLeft   \n
                  @ref CD_f_GetLatNecAccelRight
                Additionally provides the main AnecLong Calculation function to enable other modules to calculate the 
                Anec under different circumstances:
                  @ref CDCalculateAnecLongLatency\n
@{
*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/






/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static void    CDCalculateAnecLatCore ( fDistance_t                fRelPositionY,
                                        fDistance_t                fLateralOffset,
                                        fTime_t                    fTime,
                                        fAccel_t          *        pAnecLat );

static boolean CDCalculateAnecLat     ( ObjNumber_t                iObjectIndex,
                                        fDistance_t                fLateralOffset,
                                        fAccel_t           * const pfAnecLat );

static void CDCalculateAnecLong       ( CDMovement_t const * const pEgoMovement, 
                                        CDMovement_t const * const pObjMovement, 
                                        fAccel_t           * const pfAnecLong );

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CD_f_GetLongNecAccel                                                                                  */ /*!

  @brief                Returns the necessary longitudinal acceleration to avoid a collision.

  @description          The LongNecAccel describes the minimum brake acceleration that is required of the ego vehicle 
                        to avoid a collision. The calculation also considers latencies of the sensors and brakes.\n
                        The function checks if the LongNecAccel has been calculated for the current object,
                        if not, @ref CDCalculateAnecLongLatency is called. Afterwards the LongNecAccel is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        @image html CommonGetFunction_activity.png

  @return               fAccel_t : LongNecAccel of the considered object. @phys_unit [m/s^2] @range ]-...,+...[

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjEvasionData \n
                        @ref ACDC_p_GetCDParameters
  @glob_out             @ref ACDC_p_ModObjEvasionData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETLONGNECACCEL_001 \n
                        @ref TEST_CD_F_GETLONGNECACCEL_002 \n
						@ref TEST_CD_F_GETLONGNECACCEL_003 \n

  @traceability         Design Decision
*************************************************************************************************************************/
float32 CD_f_GetLongNecAccel( ObjNumber_t const iObjectIndex)
{
  CDObj_Evasion_t const * const pEvasion = ACDC_p_GetObjEvasionData(iObjectIndex);
 
  if (pEvasion->LongNecAccel > CD_LONGNECACCEL_CHECK)
  {
    /* Get pointer to CD input parameters */
    CDParameters_t const * pParameters    = ACDC_p_GetCDParameters();

    (void)CDCalculateAnecLongLatency( &(pParameters->AdjSafeDistance),
                                      iObjectIndex,
                                      &(ACDC_p_ModObjEvasionData(iObjectIndex)->LongNecAccel));
  }
  return pEvasion->LongNecAccel;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateAnecLongLatency                                                                   */ /*!

  @brief                Calculates the necessary longitudinal acceleration under consideration of the latencies.

  @description          Calculates the necessary longitudinal acceleration of the ego vehicle to avoid 
                        a collision with an object under consideration of latencies.\n
                        Two latencies are assumed: 
                        - Latency of the Ego vehicle data regarding the object data: @ref CD_LATENCY_OBJ_ACQUISITION
                        - Latency of signal onto the vehicle bus regarding the internal signal activation:
                          @ref CD_LATENCY_FCT2BRAKE
                        @startuml CDCalculateAnecLongLatency_activity.png
                        start
                          if(All Pointers are valid?) then (Yes)
                            #Orange:Calculate Ego And object movement 
                            at all interesting timestamps:
                            <b>CDPredictMovement</b> >
                            note left
                              t_hist = Object acquisition time
                              t_now = Current time
                              t_predicted = Time at which the information reaches the brake
                            end note  
                            if(Minimum relative distance is reached within predicted time?) then (Yes)
                              if(Objects touch at minimum distance?) then (Yes)
                                :1}
                                :AnecLong = **Maximum**;
                              else(No)
                                :2}
                                :AnecLong = 0;
                              endif
                            else (No)
                              :3}
partition #LightBlue **CD_USE_ANECLONG_PASS** {
                              if(Collision is possible?) then (Yes)
                                :Calculate distance to leave the 
                                corridor if velocity is kept;
                                if(Object has lateral velocity?) then (No)
                                  :4}
                                  :Set AnecLongCutOut to maximum;
                                  note left: Object will stay in ego corridor
                                else (Yes)
                                  :5}
                                  :Calculate time until object leaves corridor (time to leave);
                                  :Predict ego and object to time to leave;
                                  :Calculate necessary acceleration to let object 
                                  pass this point without collision;
                                  note left:>see formula AnecLongPass
                                endif
                              else (No)
                                :6}
                              endif
}
                              #Orange:Calculate AnecLong:
                              <b>CDCalculateAnecLong</b> >
                            endif
                          else (No)
                            :7}
                            :Return Error;
                          endif
                        stop
                        @enduml


  @return               boolean : False if Nullpointer is detected

  @param[in]            pCDAdjSafeDistance :  Assumed necessary safety distance. @phys_unit [m], @range [0,...]
  @param[in]            iObjectIndex :        Index of the object considered for the AnecLongPass. @range [0,+...[
  @param[out]           pfAnecLong :          Resulting necessary longitudinal acceleration. @phys_unit [m/s^2] @range ]-...,+...[

  @glob_in              @ref ACDC_p_GetObjEvasionData \n
                        @ref ACDC_p_GetEgoGeometry \n
                        @ref CD_s_GetEgoMov \n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetObjTrajRelation
  @glob_out             None

  @c_switch_part        @ref CD_USE_ANECLONG_PASS
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula AnecLongPass** : \n
                        \f$ \frac{2 \cdot (X_{Obj,Pred} - V_{x,Ego,Pred} \cdot t_{leave})}{t_{leave}^2}\f$

  @todo                 CD_LATENCY_OBJ_ACQUISITION is currently always 0, as object information is already 
                        synchronized to the VDY information. Therefore the "if" path can never be reached.

  @author               Clemens Schnurr

  @testmethod           @ref TEST_CDCALCULATEANECLONGLATENCY_001 \n
                        @ref TEST_CDCALCULATEANECLONGLATENCY_002 \n
                        @ref TEST_CDCALCULATEANECLONGLATENCY_003 \n
						@ref TEST_CDCALCULATEANECLONGLATENCY_004 \n
						@ref TEST_CDCALCULATEANECLONGLATENCY_005 \n

  @traceability         Design Decision
*************************************************************************************************************************/
boolean CDCalculateAnecLongLatency( CDAdjSafeDistance_t const * const pCDAdjSafeDistance,
                                    ObjNumber_t         const         iObjectIndex,
                                    fAccel_t                  * const pfAnecLong          )
{
  /* local variable(s) */
  boolean bReturn = b_TRUE;

  if (    (pCDAdjSafeDistance != NULL) 
       && (pfAnecLong         != NULL) )
  {
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const         EgoMovement                = CD_s_GetEgoMov();
    CDMovement_t const         AbsObjMovement             = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);
    CDMovement_t               egoMovementWoAcceleration;
    CDMovement_t               currObjMovement;
    CDMovement_t               predObjMovement;
    CDMovement_t               histEgoMovement;
    CDMovement_t               predEgoMovement;
    float32                    vRelHist;
    float32                    aRelHist;
    float32                    vRelCurr;
    float32                    vRelPred;

    /* don't consider ego acceleration */
    egoMovementWoAcceleration = EgoMovement;
    egoMovementWoAcceleration.fAx = 0.0f;

    /* calculate history values for Ego */
    CDPredictMovement(&egoMovementWoAcceleration, &histEgoMovement, -CD_LATENCY_OBJ_ACQUISITION, b_TRUE, b_FALSE);
    /* calculate predicted values for Ego */
    CDPredictMovement(&egoMovementWoAcceleration, &predEgoMovement, CD_LATENCY_FCT2BRAKE, b_TRUE, b_FALSE);
    /* calculate current values for Object */
    CDPredictMovement(&AbsObjMovement, &currObjMovement, CD_LATENCY_OBJ_ACQUISITION, b_TRUE, b_FALSE);
    /* calculate predicted values for Object */
    CDPredictMovement(&AbsObjMovement, &predObjMovement, CD_LATENCY_SYSTEM, b_TRUE, b_FALSE);

    vRelHist = AbsObjMovement.fVx - histEgoMovement.fVx;
    aRelHist = AbsObjMovement.fAx - histEgoMovement.fAx;
    vRelCurr = currObjMovement.fVx - egoMovementWoAcceleration.fVx;
    vRelPred = predObjMovement.fVx - predEgoMovement.fVx;

      /* Check for crash within prediction time */
    /* Assumption: as prediction time accounts for system latency we shall not check for 
    safety distance as this already would have been considered in the past. => Consistent mechanism is 
    to check only for crash and in all other cases use the predicted values */

    /* Check for minimum distance within CD_LATENCY_SYSTEM */
    if ( ( aRelHist > C_F32_DELTA) &&
         ( vRelHist <= 0.0f ) &&
         ( vRelPred > 0.0f ) &&
         ( vRelCurr > 0.0f) )
    {
      const float32 timeOfMinimum = (-vRelHist)/aRelHist;
      CDMovement_t objMovementMinimum;
      CDMovement_t egoMovementMinimum;
      float32 fMinDist;
      CDPredictMovement( &histEgoMovement, &egoMovementMinimum, timeOfMinimum, b_TRUE, b_FALSE );
      CDPredictMovement( &AbsObjMovement , &objMovementMinimum, timeOfMinimum, b_TRUE, b_FALSE );
      fMinDist = objMovementMinimum.fX - egoMovementMinimum.fX;
      if (    ( fMinDist <= 0.0f ) 
           || ( predObjMovement.fX <= (predEgoMovement.fX + pCDAdjSafeDistance->fLongNecRemainDist) ) )
      {
        /* Crash case 1: Within Prediction Time the Objects touched */
        /* Crash case 2: After Prediction X Distance is still less than safety distance */
        *pfAnecLong = CD_NEC_LONG_DECEL_MAX;
      }
      else
      {
        /* min dist was reached within Prediction time and min dist is Ok after Latency => situation is cleared */
        *pfAnecLong = 0.0f;
      }
    }
    else
    {

#if (CD_USE_ANECLONG_PASS)
      ACDCGeometry_t          const * const pEgoGeometry    = ACDC_p_GetEgoGeometry();
      ACDCObjToTrajRelation_t const * const pTrajRelation   = ACDC_p_GetObjTrajRelation(iObjectIndex);
      CDObj_Evasion_t               * const pEvasion        = ACDC_p_ModObjEvasionData(iObjectIndex);

      float32 const fHalfCorridorWidth = ( (pCDAdjSafeDistance->fLatNecRemainDist) + (  pEgoGeometry->fWidth  / 2.0f ) );
      float32 const fAbsVelocityToTraj = fABS(pTrajRelation->fVelocityToTraj);
      /*init AnecLong*/
      pEvasion->AnecLongCutOut = 0.f;

      /*check if object collision is possible*/
      if (    (    (     pTrajRelation->fDistToTrajMin  <=  fHalfCorridorWidth              )    /*object in corridor*/
                && (     pTrajRelation->fDistToTrajMax  >= -fHalfCorridorWidth            ) )
           || (    (     pTrajRelation->fVelocityToTraj <  -CD_ANECLONG_PASS_LATVEL_THRES )     /*object approach from left*/
                && (     pTrajRelation->fDistToTrajMin   >  fHalfCorridorWidth            ) )   /*&& on left side*/
           || (    (     pTrajRelation->fVelocityToTraj  >  CD_ANECLONG_PASS_LATVEL_THRES )     /*object approach from right*/
                && (     pTrajRelation->fDistToTrajMax  <  -fHalfCorridorWidth            ) ) ) /*&& on right side*/
      {
        float32       fDtCutOut          = CD_DIST_MAX;  /*Distance to Cut Out*/
        float32       fTtCutOut          = CD_TIME_MAX;  /*Time to Cut Out*/
        /*object is in corridor or will enter*/

        /*calculate distance to leave the corridor*/
        if ( pTrajRelation->fVelocityToTraj <= 0.f)
        {
          /*object speed to right ==> is in corridor or left*/
          fDtCutOut = pTrajRelation->fDistToTrajMax + fHalfCorridorWidth;
        }
        else
        {
          /*object speed to left ==> is in corridor or right*/
          fDtCutOut = fHalfCorridorWidth - pTrajRelation->fDistToTrajMin;
        }
        
        if (   ( fAbsVelocityToTraj > C_F32_DELTA                   )
            && ( fAbsVelocityToTraj > CD_ANECLONG_PASS_LATVEL_THRES ) )
        {
          CDMovement_t  predObjMovementCutOut;
          /*object has Velocity to Trajectory*/
        
          /*calculate time to leave corridor*/
          fTtCutOut = fDtCutOut / fABS(pTrajRelation->fVelocityToTraj);

          /*predict CutOut*/
          CDPredictMovement(&predObjMovement, &predObjMovementCutOut, fTtCutOut, b_FALSE, b_FALSE);
          
          /*apply safety distance*/
          predObjMovementCutOut.fX -= pCDAdjSafeDistance->fLongNecRemainDist;
          
          /*calculate needed deceleration to pass this point*/
          if (fTtCutOut > C_F32_DELTA)
          {
            /*PRQA S 3121 1*//*physical constant: s=1/2*a*t^2*/
            (pEvasion->AnecLongCutOut) = MINMAX_FLOAT(CD_NEC_LONG_DECEL_MAX, 0.f, (2.0f * ((predObjMovementCutOut.fX) - ((predEgoMovement.fVx) * fTtCutOut))) / (fTtCutOut * fTtCutOut));
          }
        }
        else
        {
          /*object has no Velocity to Trajectory ==> will stay in corridor*/
          pEvasion->AnecLongCutOut = CD_NEC_LONG_DECEL_MAX;
        }
      }
#endif /*CD_USE_ANECLONG_PASS*/

      /* consider distance ego has traveled between data acquisition and FCT call */
      predEgoMovement.fX -= histEgoMovement.fX;
      /* If no crash is found calculate plain Anec Long*/
      predObjMovement.fX -= pCDAdjSafeDistance->fLongNecRemainDist;
      CDCalculateAnecLong( &predEgoMovement, &predObjMovement, pfAnecLong );

    }
  }
  else
  {
    bReturn = b_FALSE;
  }
  /* return */
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetLatNecAccel                                                                      */ /*!

  @brief                Return the necessary lateral acceleration for a evasion movement.

  @description          The LatNecAccel describes the lateral acceleration that is required from the ego vehicle to \n
                        avoid a collision by a lateral evasion movement. The function checks if the LatNecAccel has
                        been calculated for the current object, if not, @ref CD_f_GetLatNecAccelRight and @ref CD_f_GetLatNecAccelLeft \n
                        are called. Of the two resulting accelerations, the smaller one is set as LatNecAccel.
                        After the calculation the LatNecAccel is returned. The functions processing steps deviate \n
                        slightly from the common steps of a 'Get Function' (see diagram below).
                        @startuml CD_f_GetLatNecAccel_activity.png 
                        start
                         if (LatNecAccel has been calculated before?) then (Yes)
                          :1}
                         else(No)
                          :2}
                          :Get LatNecAccelRight;
                          :Get LatNecAccelLeft;
                          :Set smaller Acceleration 
                          as LatNecAccel;
                         endif
                         :Return LatNecAccel;
                        stop
                        @enduml

  @return               float32 : LatNecAccel of the considered object. @phys_unit [m/s^2]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref CD_f_GetLatNecAccelRight \n
                        @ref CD_f_GetLatNecAccelLeft  \n
                        @ref ACDC_p_GetObjEvasionData
  @glob_out             @ref ACDC_p_ModObjEvasionData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETLATNECACCEL_001 \n
                        @ref TEST_CD_F_GETLATNECACCEL_002 \n
						@ref TEST_CD_F_GETLATNECACCEL_003 \n

  @traceability         Design Decision
*************************************************************************************************************************/
float32 CD_f_GetLatNecAccel( ObjNumber_t const iObjectIndex)
{
  CDObj_Evasion_t    const * const pEvasion = ACDC_p_GetObjEvasionData(iObjectIndex);

  if (pEvasion->LatNecAccel > CD_ANECLAT_CHECK)
  {
     float32 fLatNecAccelRight = CD_f_GetLatNecAccelRight(iObjectIndex);
     float32 fLatNecAccelLeft  = CD_f_GetLatNecAccelLeft(iObjectIndex);

     /* Select smallest necessary lateral acceleration to prevent collision and keep sign of acceleration */
     if (fABS(fLatNecAccelLeft) > fABS(fLatNecAccelRight))
     {
       ACDC_p_ModObjEvasionData(iObjectIndex)->LatNecAccel = fLatNecAccelRight;
     }
     else
     {
       ACDC_p_ModObjEvasionData(iObjectIndex)->LatNecAccel = fLatNecAccelLeft;
     }
  }
  return pEvasion->LatNecAccel;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetLatNecAccelLeft                                                                      */ /*!

  @brief                Return the necessary lateral acceleration for a left side evasion movement.

  @description          The LatNecAccelLeft describes the lateral acceleration that is required from the 
                        ego vehicle to avoid a collision by a lateral evasion movement to the left.\n
                        The function checks if the LatNecAccelLeft has been calculated for the current object,
                        if not, @ref CDCalculateAnecLat is called. After the calculation the LatNecAccelLeft is returned. \n
                        The functions processing steps deviate slightly from the common steps of a 'Get Function' (see diagram below).
                        @startuml CD_f_GetLatNecAccelLeft_activity.png 
                        start
                         if (ANecLatLeft has been calculated before?) then (Yes)
                          :1}
                         else(No)
                          :2}
                           :Calculate minimum required 
                           lateral offset;
                           note left: >see Formula "Required Lateral Offset"
                           #Orange:Calculate ANecLatLeft
                           <b>CDCalculateAnecLat</b> >
                         endif
                         :Return ANecLatLeft;
                        stop
                        @enduml

  @return               float32 : LatNecAccelLeft of the considered object. @phys_unit [m/s^2] @range ]-...,+...[

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjEvasionData \n
                        @ref ACDC_p_GetCDParameters\n
                        @ref ACDC_p_GetObjGeometry
  @glob_out             @ref ACDC_p_ModObjEvasionData

  @c_switch_part        @ref CD_LIMIT_RADAR_OBJECT_WIDTH
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Required Lateral Offset**:\n
                          \f$LatOffset_{Right} = \frac{Width_{Ego} + Width_{Obj}}{2} + SafetyOffset\f$ \n
                          \f$LatOffset_{Left}  = - LatOffset_{Right}\f$

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETLATNECACCELLEFT_001 \n
                        @ref TEST_CD_F_GETLATNECACCELLEFT_002

  @traceability         Design Decision
*************************************************************************************************************************/
float32 CD_f_GetLatNecAccelLeft( ObjNumber_t const iObjectIndex)
{
  CDObj_Evasion_t    const * const pEvasion = ACDC_p_GetObjEvasionData(iObjectIndex);
  

  if (pEvasion->LatNecAccelLeft > CD_ANECLAT_CHECK)
  {
    /* Get Ego width */
    float32                 const         fEgoVehicleWidth   = ACDC_p_GetEgoGeometry()->fWidth;
    CDParameters_t          const * const pParameters        = ACDC_p_GetCDParameters();
    ACDCGeometry_t          const * const pGeometry          = ACDC_p_GetObjGeometry(iObjectIndex);

    float32 const fLateralOffsetMinRight  = (0.5f * fEgoVehicleWidth) + ( 0.5f * pGeometry->fWidth);

    /*Calculate the offset value for the safety distance on right side,
      the offset on the left side mirrored from the right one with same value*/
    float32 const fLatOffsetRightWithSafetyDistance = pParameters->AdjSafeDistance.fLatNecRemainDist + fLateralOffsetMinRight;
    float32 const fLatOffsetLeftWithSafetyDistance  = - fLatOffsetRightWithSafetyDistance;

    (void)CDCalculateAnecLat( iObjectIndex, fLatOffsetLeftWithSafetyDistance, &(ACDC_p_ModObjEvasionData(iObjectIndex)->LatNecAccelLeft));
  }
  return pEvasion->LatNecAccelLeft;
}
  
/*************************************************************************************************************************
  Functionname:         CD_f_GetLatNecAccelRight                                                                      */ /*!

  @brief                Return the necessary lateral acceleration for a right side evasion movement.

  @description          The LatNecAccelRight describes the lateral acceleration that is required from the 
                        ego vehicle to avoid a collision by a lateral evasion movement to the right. \n
                        The function checks if the LatNecAccelRight has been calculated for the current object,
                        if not, @ref CDCalculateAnecLat is called. After the calculation the LatNecAccelRight is returned. \n
                        The functions processing steps deviate slightly from the common steps of a 'Get Function' (see diagram below).
                        @startuml CD_f_GetLatNecAccelRight_activity.png 
                        start
                         if (ANecLatRight has been calculated before?) then (Yes)
                           :1}
                         else(No)
                           :2}
                           :Calculate minimum required 
                           lateral offset;
                           note left:>see Formula "Lateral Offset"
                           #Orange:Calculate ANecLatRight
                           <b>CDCalculateAnecLat</b> >
                         endif
                         :Return ANecLatRight;
                        stop
                        @enduml

  @return               float32 : LatNecAccelRight of the considered object. @phys_unit [m/s^2] @range ]-...,+...[

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjEvasionData \n
                        @ref ACDC_p_GetCDParameters\n
                        @ref ACDC_p_GetObjGeometry
  @glob_out             @ref ACDC_p_ModObjEvasionData

  @c_switch_part        @ref CD_LIMIT_RADAR_OBJECT_WIDTH
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Lateral Offset:** \n
                          \f$LatOffset_{Right} = \frac{Width_{Ego} + Width_{Obj}}{2} + SafetyOffset\f$

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETLATNECACCELRIGHT_001 \n
                        @ref TEST_CD_F_GETLATNECACCELRIGHT_002

  @traceability         Design Decision
*************************************************************************************************************************/
float32 CD_f_GetLatNecAccelRight( ObjNumber_t const iObjectIndex)
{
  CDObj_Evasion_t    const * const pEvasion = ACDC_p_GetObjEvasionData(iObjectIndex);

  if (pEvasion->LatNecAccelRight > CD_ANECLAT_CHECK)
  {
    /* Get Ego width */
    float32        const   fEgoVehicleWidth         = ACDC_p_GetEgoGeometry()->fWidth;
    CDParameters_t const * pParameters              = ACDC_p_GetCDParameters();
    ACDCGeometry_t const * const pObjGeometry       = ACDC_p_GetObjGeometry(iObjectIndex);

    float32 const fLateralOffsetMinRight            = (0.5f * fEgoVehicleWidth) + ( 0.5f * pObjGeometry->fWidth);

    /*Calculate the offset value for the safety distance on right side*/
    float32 const fLatOffsetRightWithSafetyDistance = pParameters->AdjSafeDistance.fLatNecRemainDist + fLateralOffsetMinRight;

    (void)CDCalculateAnecLat( iObjectIndex, fLatOffsetRightWithSafetyDistance, &(ACDC_p_ModObjEvasionData(iObjectIndex)->LatNecAccelRight));
  }
  return pEvasion->LatNecAccelRight;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateAnecLatCore                                                                       */ /*!

  @brief                Calculates the necessary lateral acceleration to cover a given lateral distance within 
                        a given time.

  @description          Calculates the necessary lateral acceleration to get from the current lateral offset to the
                        required lateral offset within a given time.
                        @startuml CDCalculateAnecLatCore_activity.png
                        start
                          if (Current lateral distance is smaller\nthan the required offset?\nAND Time > 0?) then (Yes)
                            :1}
                            :Calculate AnecLat;
                            note left: >see formula\n"AnecLatCalculation"
                            :Limit AnecLat to a Min
                            and a Max value;
                          else(No)
                            :2}
                            :AnecLat = 0;
                          endif
                        stop
                        @enduml
                        
  @return               void

  @param[in]            fRelPositionY :  Relative lateral position. @phys_unit [m] @range ]-...,+...[
  @param[in]            fLateralOffset : Wanted lateral position offset. @phys_unit [m] @range ]-...,+...[
  @param[in]            fTime :          Time for calculation. @phys_unit [s] @range ]-...,+...[
  @param[in,out]        pAnecLat :       Calculated necessary lateral acceleration. @phys_unit [m/s^2] @range ]-@ref CD_NEC_LAT_DECEL_MAX,+@ref CD_NEC_LAT_DECEL_MAX[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **AnecLatCalculation**: \n
                          \f$A_{Nec,Lat} = \frac{2 \cdot (D_{Y,Curr} - D_{Y,Req})}{t^2} \f$ \n
                          with: \n
                          \f$D_{Y,Curr} = \f$ Current lateral distance \n
                          \f$D_{Y,Req} = \f$ Required lateral distance \n

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDCALCULATEANECLATCORE_001 \n
                        @ref TEST_CDCALCULATEANECLATCORE_002 \n
                        @ref TEST_CDCALCULATEANECLATCORE_003 \n
						@ref TEST_CDCALCULATEANECLATCORE_004 \n
						@ref TEST_CDCALCULATEANECLATCORE_005 \n

  @traceability         Design Decision
*************************************************************************************************************************/
static void CDCalculateAnecLatCore( fDistance_t   fRelPositionY,
                                    fDistance_t   fLateralOffset,
                                    fTime_t       fTime,
                                    fAccel_t    * pAnecLat )
{
  /* set default value */
  *pAnecLat = 0.0f;

  /* relative position is smaller than requested lateral offset */
  if ( fABS(fRelPositionY) < fABS(fLateralOffset) )
  {
    /* prevent division by zero and negative time values */
    if (fTime >= C_F32_DELTA)
    {
      *pAnecLat = (2.0f * (fRelPositionY - fLateralOffset)) / SQR(fTime);/*PRQA S 3121*//*physical constant: s=1/2*a*t^2*/

      /* limit value range */
      *pAnecLat = MINMAX_FLOAT(-CD_NEC_LAT_DECEL_MAX, CD_NEC_LAT_DECEL_MAX, *pAnecLat);
    }
  }
}

/*************************************************************************************************************************
  Functionname:         CDCalculateAnecLat                                                                           */ /*!

  @brief                Calculates necessary lateral acceleration to achieve a given lateral offset at TTC to 
                        a given object.

  @description          The calculation is executed in three steps:
                        @startuml CDCalculateAnecLat_activity.png
                        start
                          :Calculate objects TTC
                          <b>CDCalculateTTC</b> >

                          if(Check TTC) then (Valid)
                            :1}
                            #Orange:calculate lateral distance at TTC if 
                             object and ego keep their kinematics 
                             <b>CDCalculateDistance</b> >
                             note left: Assume lateral\nego acceleration = 0

                            #Orange:Calculate Necessary lateral ego 
                            acceleration to achieve required 
                            lateral offset at TTC = 0
                            <b>CDCalculateAnecLatCore</b> >
                          else (Invalid)
                            :2}
                            :AnecLat = 0;
                          endif
                        stop
                        @enduml

  @return               boolean : Always true.

  @param[in]            iObjectIndex :    Index of the object for which the value shall be returned.
  @param[in]            fLateralOffset :  Wanted lateral offset between ego and object at TTC. @phys_unit [m] @range ]-...,+...[
  @param[in,out]        pfAnecLat :       Necessary lateral acceleration to achieve lateral offset. @phys_unit [m/s^2] @range ]-...,+...[

  @glob_in              @ref CD_s_GetEgoMov \n
                        @ref CD_s_GetObjMov \n
                        @ref CD_f_GetTTC
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @todo                 consider vehicle stop times, perhaps in CDPredictMovement function

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDCALCULATEANECLAT_001 \n
                        @ref TEST_CDCALCULATEANECLAT_002

  @traceability         Design Decision
*************************************************************************************************************************/
static boolean CDCalculateAnecLat( ObjNumber_t                iObjectIndex,
                                   fDistance_t                fLateralOffset,
                                   fAccel_t           * const pfAnecLat )
{
  /* local variable(s) */
  boolean bReturn = b_TRUE;
  fTime_t fTTC;
  fDistance_t fRelDistanceTTCNoEgoAccel;

  fTTC = CD_f_GetTTC(iObjectIndex);

  /* set default value */
  *pfAnecLat = 0.0f;

  /* TTC is valid */
  if (fTTC < CD_TIME_MAX)
  {
    /*Get the movement properties of Ego and Obj*/
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const EgoMovement  = CD_s_GetEgoMov();
    CDMovement_t const ObjMovement  = CD_s_GetObjMov(iObjectIndex,POS_GEN_OBJECT,KIN_ABS);

    /* calculate relative distance when ego has no lateral acceleration at time of collision */
    fRelDistanceTTCNoEgoAccel = CDCalculateDistance( ObjMovement.fY  - EgoMovement.fY,
                                                     ObjMovement.fVy - EgoMovement.fVy,
                                                     ObjMovement.fAy,
                                                     fTTC );
  
    /* calculate AnecLat for passing the object */
    CDCalculateAnecLatCore( fRelDistanceTTCNoEgoAccel,  fLateralOffset, fTTC, pfAnecLat);
  }

  /* return */
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateAnecLong                                                                          */ /*!

  @brief                Calculates the necessary longitudinal acceleration of an object to avoid crash with safety margin distance

  @description          Calculates the necessary longitudinal acceleration to 
                        avoid a collision (NecLongAccel). The following is assumed:
                        - the host vehicle directly applies the necessary
                        acceleration; no brake response time is included
                        - the host will hit the vehicle (the object is inside the driving corridor or will enter the driving corridor).
                        All input objects are taken into account (oncoming traffic too)
                        .
                        @startuml CDCalculateAnecLong_activity.png
                        start
                          if (Current acceleration avoids collision?) then (No)
                            :Calculate current Ego-Object X-distance;
                            note left: >see formula "BrakeDist"
                            if(Object is oncoming?) then (Yes)
                              #Orange:Calculate Necessary acceleration 
                              to stop at collision point (=AnecColl)
                              <b>SFL_v_SolveQuadrEquation</b> >
                              if(Object is braking?) then (Yes)
                                :Calculate Distance to ego vehicle
                                at which the object stops;
                                if (Objects braking avoids collision?) then (Yes)
                                  :1}
                                  :Calculate necessary ego 
                                  acceleration to avoid collision;
                                  note left:>see formula "1.a"
                                else(No)
                                  :2}
                                  :Collision can't be avoided by ego 
                                  braking Anec = Maximum Deceleration;
                                  note left: >see formula "1.b"
                                endif
                              else(No)
                                :3}
                                :Anec = AnecColl;
                                note left:>see formula "1.c"
                              endif
                            else (No)
                              if (Object is braking?) then (No)
                                :4}
                              else(Yes)
                                :5}
                                :Calculate Anec for the 
                                objects stopping position;
                                note left: >see formula "2.a"
                              endif
                              if(Object is slower than ego vehicle?) then (No)
                                :6}
                              else(Yes)
                                :7}
                              :Calculate Anec to reach objects 
                                velocity before collison;
                                note left: >see formula "2.b"
                              endif
                            endif
                          else (Yes)
                            :8}
                            :Anec = 0;
                          endif
                          :Limit Anec to Min/Max values;
                        stop
                        @enduml

  @return               void

  @param[in]            pEgoMovement : Pointer to movement of the ego vehicle.
  @param[in]            pObjMovement : Pointer to movement of the object.
  @param[in,out]        pfAnecLong :   Pointer to AnecLong  @phys_unit [m/s^2], @range [@ref CD_NEC_LONG_DECEL_MAX,0]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 No changes

  @InOutCorrelation     \f$ BrakeDist = X_{Obj}-X_{Ego}\f$ \n
                        The following cases are distinguished:
                        1. **Object is oncoming**: \n
                        If an object is oncoming, three cases can be distinguished:
                          1. The object brakes and gets to stop before the current distance. The necessary acceleration is calculated as following: \n
                            \f$Dist_{Obj,Stop} = Dist_{Ego,Obj} - \frac{V_{Obj}^2}{2 \cdot A_{Obj}} \f$ \n
                            \f$A_{Nec} = -\frac{V_{Ego}^2}{2 \cdot Dist_{Obj,Stop}}\f$
                          2. The object brakes but does not stop before the current distance. In this case a collision can not be avoided.
                            The maximum possible deceleration is requested.
                          3. The object does not brake or accelerates towards the ego vehicle. In this case a collision can not be avoided.
                            Therefore the necessary acceleration is calculated so the ego vehicle stops at the collision point. \n
                            Assumptions:\n
                            \f$V_{x,Ego} + A_{x,Nec} \cdot t = 0\f$ => \f$t = -\frac{V_{x,Ego}}{A_{x,Nec}}\f$ \n
                            \f$X_{Ego} + V_{x,Ego} \cdot t + 0.5(A_{x,Nec})t^2 = X_{Obj} + V_{x,Obj} \cdot t + 0.5(A_{x,Obj})t^2 \f$ \n
                            Conversion: \n
                            \f$0 = (X_{Obj}-X_{Ego}) \cdot A_{x,Nec}^2-(V_{x,Obj}V_{x,Ego}-0.5\cdot V_{x,Ego}^2) \cdot A_{x,Nec}+0.5\cdot V_{x,Ego}^2A_{x,Obj} \f$\n
                            Of the results of this quadratic equation, the smaller one is considered as necessary acceleration.
                          .
                        2. **Object is comoving**:
                          1. *Object stops before ego vehicle due to negative acceleration*: \n
                            In a first step, the distance at which the object stops has to be calculated. \n
                            For this, the distance that is necessary for the velocity reduction is added to the BrakeDistance: \n
                            \f$ Dist_{Stop} = (X_{Obj}-X_{Ego}) - \frac{V_{x,Obj}^2}{2A_{x,Obj}}\f$ \n
                            After this the necessary ego acceleration is calculated in a way that the ego vehicle stops at the same position:\n
                            \f$ A_{x,Nec} = - \frac{(V_{x,Ego})^2}{2 \cdot Dist_{Stop}}   \f$ \n
                            In the end it has to be verified, that the object stops before the ego vehicle, otherwise there would be a collision 
                            despite the applied acceleration. This can only happen if the ego velocity is above the object velocity.
                          2. *Relative speed of object and ego is negative*: \n
                            In this case the necessary acceleration is the sum of the current object acceleration and the 
                            acceleration that is necessary to reach the objects velocity before a collision:\n
                            \f$ A_{x,Nec} = A_{x,Obj} - \frac{V_{x,rel}^2}{2 \cdot (X_{Obj}-X_{Ego})}\f$

  @author               Xavier Torras

  @testmethod           @ref TEST_CDCALCULATEANECLONG_001 \n
                        @ref TEST_CDCALCULATEANECLONG_002 \n
                        @ref TEST_CDCALCULATEANECLONG_003 \n
                        @ref TEST_CDCALCULATEANECLONG_004 \n
                        @ref TEST_CDCALCULATEANECLONG_005 \n
						@ref TEST_CDCALCULATEANECLONG_006 \n
						@ref TEST_CDCALCULATEANECLONG_007 \n
						@ref TEST_CDCALCULATEANECLONG_008 \n
						@ref TEST_CDCALCULATEANECLONG_009 \n
						@ref TEST_CDCALCULATEANECLONG_010 \n

  @traceability         Design Decision
*************************************************************************************************************************/
static void CDCalculateAnecLong( CDMovement_t const * const pEgoMovement, 
                                 CDMovement_t const * const pObjMovement, 
                                 fAccel_t           * const pfAnecLong ) 
{
  /* local variable(s) */
  /* Relative movement = object movement - ego movement */
  /* Note: object movement for stationary objects is assumed to be correctly set to 0 */
  const float32 fVRelX     = pObjMovement->fVx - pEgoMovement->fVx;

  /* ego vehicle is standing */
  if ( pEgoMovement->fVx < C_F32_DELTA )
  {
    (*pfAnecLong) = 0.0f;
  }
  else if((pObjMovement->fAx > -C_F32_DELTA) && ( fVRelX > 0.0f )) /* ego acceleration 0 sufficient to prevent a crash*/
  {
    (*pfAnecLong) = 0.0f;
  }
  else
  {
    const float32 fBrakeDist = MAX(pObjMovement->fX - pEgoMovement->fX, CD_NEC_LONG_VIRTUAL_OBJ_DIST); /* obj X might be reduced by "safety distance"; ego X might be non-zero due to prediction*/
    
    if (pObjMovement->fVx <= -C_F32_DELTA) /* oncoming traffic */
    {
      /* for oncoming traffic calculate time */

      if ( pObjMovement->fAx > C_F32_DELTA ) /* oncoming traffic is braking */
      {
        /* Available braking distance is*/
        /* current distance - Object way to stop */
        /*  pObjMovement->fAx > C_F32_DELTA is assured => second term > 0*/
        const float32 fStopObjDist = fBrakeDist - (SQR( pObjMovement->fVx ) / ( 2.0f * pObjMovement->fAx ));
        if (fStopObjDist < C_F32_DELTA)
        {
          (*pfAnecLong) = CD_NEC_LONG_DECEL_MAX;
        }
        else
        {
          /*insert t=-v_x_Ego/a_NecLong in StopObjDist=1/2*a_NecLong*t^2+v_x_Ego*t*/
          /*PRQA S 3121 1*/
          (*pfAnecLong) = -(SQR( pEgoMovement->fVx ) / (2.0f * fStopObjDist) );
        }
        
      }
      else /* object accelerates towards us or does not brake */
      {
        SFLPolynomialSolutions_t AnecLongSolutions;

        /* find neccessary a_Ego_brake = fAnecLongColl to stop ego just before the collsion; fBrakeDist > 0 is always true:
        x_Obj(t_brake) - x_Ego(t_brake) = 0 with t_brake = - v_Ego_0 / a_Ego_brake solved for a_Ego_brake */
        /*PRQA S 3121 3*/
        float32 const fA = fBrakeDist;
        float32 const fB = -((pObjMovement->fVx*pEgoMovement->fVx) - (0.5f * (pEgoMovement->fVx*pEgoMovement->fVx)));
        float32 const fC = (((0.5f * pObjMovement->fAx) * pEgoMovement->fVx) * pEgoMovement->fVx);

        SFL_v_SolveQuadrEquation( fA, fB, fC, &AnecLongSolutions);
        if(AnecLongSolutions.uNofSolutions == 0u)
        {
          *pfAnecLong = CD_NEC_LONG_DECEL_MAX;
        }
        else
        {
          *pfAnecLong = SFL_f_SelectMinValue(AnecLongSolutions.afSolutions, AnecLongSolutions.uNofSolutions, 0.f, b_FALSE);
        }
      }
    }
    else /* normal situation: follow and run-up; moving braking stationary */
    {
      float32 fANecLongStopped = CD_NEC_LONG_DECEL_MAX;
      float32 fANecLongMoving = CD_NEC_LONG_DECEL_MAX;
      /* Scenario 1: Car in Front stops and we stop with min distance behind the car */
      if ( pObjMovement->fAx <= -C_F32_DELTA )
      {
        /* Available braking distance is*/
        /* current distance + Object way to stop */
        /* fBrakeDist > C_F32_DELTA is already assured */
        /*  pObjMovement->fAx <= -C_F32_DELTA is assured => second term < 0*/
        const float32 fStopObjDist = fBrakeDist - (SQR( pObjMovement->fVx ) / ( 2.0f * pObjMovement->fAx ));
        /* Object assumed to be stationary*/
        const float32 fANecLongCandidateStopped = -(SQR( pEgoMovement->fVx ) / (2.0f * fStopObjDist) );
        /* verify that the candidate value is valid => Object needs to stop before Ego */
        const float32 fStopEgoTime = -(pEgoMovement->fVx)/ fANecLongCandidateStopped;
        const float32 fStopObjTime = -(pObjMovement->fVx)/(pObjMovement->fAx);
        if (fStopEgoTime >= fStopObjTime)
        {
          fANecLongStopped = fANecLongCandidateStopped;
        }
        /* By back-substitution the else case leads to vRel < 0 => its save to leave the value at max accel */
      }
      /* Scenario 2: Car in Front is currently slower => Brake such that we reach same speed at minimal distance */
      /* This case includes the special case of stationary target vehicles */
      /* If vRel < 0 the tangent point is in the past */
      if ( fVRelX <= 0.0f )
      {
        fANecLongMoving = pObjMovement->fAx - (SQR( fVRelX ) / ( 2.f * fBrakeDist ));/*PRQA S 3121*//* insert t=-v/a in s=1/2*a*t^2+v*t */
      }
      /* use the more relaxed of both to rule out the case that scenario 2 is in the area of negative velocity */
      (*pfAnecLong)= MAX(fANecLongStopped,fANecLongMoving);
    }
  }

  /* clip value to [Max-Decel, 0.0] */
  (*pfAnecLong) = MINMAX_FLOAT( CD_NEC_LONG_DECEL_MAX, 0.0f, (*pfAnecLong) );
}

#endif /* #if (ACDC_CFG_CD) */

//!@}
