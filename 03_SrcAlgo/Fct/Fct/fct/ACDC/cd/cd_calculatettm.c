/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculatettm.c

DESCRIPTION:               The calculation of TTM for CD

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:41:29CEST $

VERSION:                   $Revision: 1.18 $
*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"
#if (ACDC_CFG_CD)
#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_calculatettm Calculate TTM
@ingroup cd

@brief          The calculation of TTMLongPre and TTMLongAcute is done in this module \n\n

@description    Provides functions for the calculation of the different derivations of the TTM: \n
                  @ref CD_f_GetTTMLongPre\n
                  @ref CD_f_GetTTMLongAcute\n
                Additionally provides the TTM core calculation function: \n
                  @ref CDCalculateTTMLongCore\n
                \n
@{
*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Init distances from ego to obj resp. obj to ego*/
#define CD_CALCULATION_INIT_DISTANCE                  (         30.f)
/*! Init velocity ratio obj/ego*/
#define CD_CALCULATION_INIT_VEL_RATIO                 (          2.f)
/*Necessary to calculate ref point (1/4pi=45deg)*/
#define CD_CALCULATION_45DEG_IN_RAD                   (0.25f*CML_f_Pi)
/*Necessary to calculate ref point (3/4pi=135deg)*/
#define CD_CALCULATION_135DEG_IN_RAD                  (0.75f*CML_f_Pi)
/*Necessary to calculate ref point (5/4pi=225deg)*/
#define CD_CALCULATION_225DEG_IN_RAD                  (1.25f*CML_f_Pi)
/*Necessary to calculate ref point (7/4pi=315deg)*/
#define CD_CALCULATION_315DEG_IN_RAD                  (1.75f*CML_f_Pi)

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

static boolean CDCalculateTTMLong(ObjNumber_t         iObjectIndex,
                                  fTime_t     * const pfTTMLong,
                                  float32             fCDTTMAccelNeg,
                                  float32             fCDTTMAccelPos);

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:         CD_f_GetTTMLongPre                                                                                  */ /*!

  @brief                Returns the TTMLong of the considered object for moderate de-/accelerations of the ego vehicle.

  @description          The TTM describes the time that remains until the ego vehicle has to start de-/accelerating to avoid 
                        a collision with an object. In case of the TTMLongPre only moderate accelerations are assumed. \n
                        The function checks if the TTMLongPre has been calculated for the current object,
                        if not, @ref CDCalculateTTMLong is called. Afterwards the TTMLongPre is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTMLongPre of the considered object @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range[0,+...[

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTM_LONG

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com
*************************************************************************************************************************/
float32 CD_f_GetTTMLongPre( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTMLongPre > CD_TTM_CHECK)
  {
    (void)CDCalculateTTMLong( iObjectIndex, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTMLongPre), CD_TTM_ACCEL_PRE_NEG, CD_TTM_ACCEL_PRE_POS);
  }
  return pTTX->TTMLongPre;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTMLongAcute                                                                                  */ /*!

  @brief                Returns the TTMLong of the considered object for high de-/accelerations of the ego vehicle.

  @description          The TTM describes the time that remains until the ego vehicle has to start de-/accelerating to avoid 
                        a collision with an object. In case of the TTMLongAcute high accelerations are assumed. \n
                        The function checks if the TTMLongAcute has been calculated for the current object,
                        if not, @ref CDCalculateTTMLong is called. Afterwards the TTMLongAcute is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        @image html CommonGetFunction_activity.png

  @return               float32 : TTMLongAcute of the considered object @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTM_LONG

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com
*************************************************************************************************************************/
float32 CD_f_GetTTMLongAcute( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTMLongAcute > CD_TTM_CHECK)
  {
    (void)CDCalculateTTMLong( iObjectIndex, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTMLongAcute), CD_TTM_ACCEL_ACUTE_NEG, CD_TTM_ACCEL_ACUTE_POS);
  }
  return pTTX->TTMLongAcute;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTMLongCore                                                                       */ /*!

  @brief                Time until one of two objects has to react to avoid a collision.

  @description          Calculates the time until one of two objects that are on collision course has to react with a 
                        given de- or acceleration to avoid the collision. The result is called TTM (Time To Mitigate).
                        @startuml CDCalculateTTMLongCore_activity.png
                        start
                          if(Object1 is not stationary?\nAND Delta velocity between the objects is not 0?) then (Yes)
                            :Split up relevant acceleration 
                            into a X and a Y part;
                            note left: Split according to the\ncurrent X and Y Velocities\n>see Formula "Acceleration Split"
                            
                            #Orange:Calculate number of circles 
                            for both objects:
                            <b>EMP_v_CalcNumofCircles</b> >
                            note left
                              Objects shape is described by circles. The 
                              higher the factor between length and width, 
                              the more circles describe the object.
                            end note
                            
                            partition "Compare all circles of Obj1\nwith all circles of Obj2"{
                              #Orange:Calculate Circles
                              <b>EMP_v_CalculateCurrentCircle</b> >
                              #Orange:Calculate minimum distance of 
                              trajectories without accelerations
                              <b>EMPCalcMinDistTime</b>
                              <b>EMPCalcObjObjDistAtTime</b> >
                              note left: Accelerations left out due to runtime
                              
                              if(Minimum Distance < Safety Distance?) then (Yes)
                                #Orange:MinDist = Minimum distance of 
                                trajectories with accelerations
                                <b>EMPCalcMinDistTime</b>
                                <b>EMPCalcObjObjDistAtTime</b> >
                                :Calculate time of 0 velocity of 
                                Obj1 if it applies A_(Assumed);
                                note left: >see Formula "Time 0 Velocity"
                                if(Decelerating Object (Obj1) stops before\nminimum distance is reached?) then (Yes)
                                  #Orange:MinDist = Minimum distance of 
                                  Obj2 trajectory to stopping 
                                  point of Obj1
                                  <b>EMPCalcMinDistTime</b>
                                  <b>EMPCalcObjObjDistAtTime</b> >
                                  :1}
                                else(No)
                                  :2}
                                endif
                                if(Acceleration of Obj1 avoids crash?) then (Yes)
                                  :3}
                                  :Calculate **TTM**;
                                  note left
                                    Time until Obj1 has to start 
                                    with the acceleration to avoid collision:
                                    >see Formula "TTM"
                                  end note
                                  :Set collision avoidable flag;
                                else(No)
                                  :4}
                                  :**TTM** = TTM Standstill;
                                  note right
                                    Time until Obj1 has to start acceleration to 
                                    be at velocity 0 when collision occurs:
                                    >see Formula "TTM Standstill"
                                  end note
                                endif
                              else(No)
                                :5}
                                :**TTM** = Default;
                              endif
                              }
                            :Select and write the smallest found **TTM**;
                          else(No)
                            :6}
                            :Return Error;
                          endif
                        stop
                        @enduml

  @return               boolean :               true if calculation performed

  @param[in]            pttmRelObj1 :           Pointer to the first object. The one that can act with fRelevantAcceleration.
  @param[in]            pttmRelObj2 :           Pointer to the second object that keeps its trajectory.
  @param[in]            fRelevantAcceleration : Acceleration that the first object can use to prevent a crash (can be positive or negative). @phys_unit [m/s^2] @range ]-...,+...[
  @param[in]            fEgoVelocity :          Ego Velocity for Variable Safety Gap @phys_unit [m/s] @range ]0,+...[
  @param[in,out]        pfTTMLong :             Pointer to resulting TTM. The time the first object can wait until it must react. @phys_unit [s]
  @param[in,out]        bCollisionAvoidable :   Boolean indicating if collision is avoidable or not.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTM_LONG

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Acceleration Split:**\n
                          \f$A_X = A \cdot \frac{V_X}{|V_X|+|V_Y|}\f$\n
                          \f$A_Y = A \cdot \frac{V_Y}{|V_X|+|V_Y|}\f$
                        - **Formula Time 0 Velocity:**\n
                          \f$t_{V0} = \frac{V_{Abs,Obj1}}{A_{Assumed}}\f$
                        - **Formula TTM:**\n
                          \f$ t_{TTM} = \frac{D_{stop,Obj1,Obj2}}{V_{rel,Obj1,Obj2}}\f$
                        - **Formula TTM Standstill:**\n
                          \f$ D_{stop,Obj1} = (V_{Obj1} \cdot 0.5) \cdot t_{stop,Obj1} \f$ \n
                          \f$ D_{coll,Obj1,Obj2} = V_{rel,Obj1,Obj2} \cdot t_{coll} \f$ \n
                          \f$ t_{TTM} = \frac{D_{coll,Obj1,Obj2} - D_{stop,Obj1}}{V_{rel,Obj1,Obj2}} \f$

  @testmethod           @Generic_Testmethods

  @author               Torben Meier | torben.meier@continental-corporation.com
*************************************************************************************************************************/
boolean CDCalculateTTMLongCore( ACDCObjDesc_t const * const pttmRelObj1,
                                ACDCObjDesc_t const * const pttmRelObj2,
                                float32                     fRelevantAcceleration,
                                float32                     fEgoVelocity,
                                fTime_t             * const pfTTMLong,
                                boolean             * const bCollisionAvoidable)
{
  /* local variable(s) */
  boolean bReturn                  = TRUE;
  float32 fTTMLong                 = CD_TIME_MAX;
  float32 fObjAccelX               = 0.0f;
  float32 fObjAccelY               = 0.0f;
  float32 fDeltaAccelX             = 0.5f*fObjAccelX;
  float32 fDeltaAccelY             = 0.5f*fObjAccelY;
  float32 fDeltaVelX               = (pttmRelObj1->Movement.Vel.fX - pttmRelObj2->Movement.Vel.fX);
  float32 fDeltaVelY               = (pttmRelObj1->Movement.Vel.fY - pttmRelObj2->Movement.Vel.fY);
  float32 fDeltaDistX;
  float32 fDeltaDistY;
  float32 fObj1VelAbs              = SQRT(SQR(pttmRelObj1->Movement.Vel.fX) + SQR(pttmRelObj1->Movement.Vel.fY));
  float32 fMinDistBound            = CD_TTM_SAFETY_GAP_MIN;
  float32 fTimeMinDistNoAccel      = CD_TIME_MAX;
  float32 fMinDistNoAccel          = 0.0f;
  float32 fTimeZeroVelocity        = CD_TIME_MAX;
  float32 fTimeMinDistWithAccel    = CD_TIME_MAX;
  float32 fMinDistWithAccel        = 0.0f;
  float32 fVAngleObj1;
  float32 fVObj2toObj1;
  float32 fminTimeOfColl;
  float32 fVarSafetyGap;
  uint8   uiCurrCircleIDObj1;
  uint8   uiNumOfCirclesObj1 = 1u;
  uint8   uiCurrCircleIDObj2;
  uint8   uiNumOfCirclesObj2 = 1u;
  SFLCircle_t sRelCircleDataObj1;
  SFLCircle_t sRelCircleDataObj2;

  ACDCTrajPred_t sTrajPredEgo;
  ACDCTrajPred_t sTrajPredObj;

  sTrajPredEgo.XofT.fC0 = 0.f;
  sTrajPredEgo.XofT.fC1 = 0.f;
  sTrajPredEgo.XofT.fC2 = 0.f;
  sTrajPredEgo.YofT.fC0 = 0.f;
  sTrajPredEgo.YofT.fC1 = 0.f;
  sTrajPredEgo.YofT.fC2 = 0.f;

  *bCollisionAvoidable = TRUE;
  /*Object1 needs to have velocity and delta velocity*/
  if ((fObj1VelAbs >= C_F32_DELTA) && ( (2.f*(SQR(fDeltaVelX) + SQR(fDeltaVelY))) >= C_F32_DELTA ))
  {
    /*Calc Acceleration Direction*/
    if ((fABS(pttmRelObj1->Movement.Vel.fX)+fABS(pttmRelObj1->Movement.Vel.fY)) > C_F32_DELTA)
    {
      fObjAccelX      = fRelevantAcceleration * (pttmRelObj1->Movement.Vel.fX/(fABS(pttmRelObj1->Movement.Vel.fX)+fABS(pttmRelObj1->Movement.Vel.fY)));
      fObjAccelY      = fRelevantAcceleration * (pttmRelObj1->Movement.Vel.fY/(fABS(pttmRelObj1->Movement.Vel.fX)+fABS(pttmRelObj1->Movement.Vel.fY)));
    }
  
    /*Calc Number of Circles*/
    EMP_v_CalcNumofCircles(pttmRelObj1, &uiNumOfCirclesObj1);
    EMP_v_CalcNumofCircles(pttmRelObj2, &uiNumOfCirclesObj2);
    
    /*Calc Safety Distance*/
    fVarSafetyGap = CML_f_LinearInterpolation( CD_TTM_SAFETY_GAP_VELOCITY_THRSHLD_MIN, CD_TTM_SAFETY_GAP_MIN, 
                                               CD_TTM_SAFETY_GAP_VELOCITY_THRSHLD_MAX, CD_TTM_SAFETY_GAP_MAX, fABS(fEgoVelocity));
    fVarSafetyGap = MINMAX_FLOAT(CD_TTM_SAFETY_GAP_MIN, CD_TTM_SAFETY_GAP_MAX, fVarSafetyGap);

    /*Run over Circles*/
    for (uiCurrCircleIDObj1 = 0; uiCurrCircleIDObj1 < uiNumOfCirclesObj1; uiCurrCircleIDObj1++)
    {
      EMP_v_CalculateCurrentCircle(pttmRelObj1, uiCurrCircleIDObj1, uiNumOfCirclesObj1, &sRelCircleDataObj1);
      for (uiCurrCircleIDObj2 = 0; uiCurrCircleIDObj2 < uiNumOfCirclesObj2; uiCurrCircleIDObj2++)
      {
        EMP_v_CalculateCurrentCircle(pttmRelObj2, uiCurrCircleIDObj2, uiNumOfCirclesObj2, &sRelCircleDataObj2);

        fTTMLong        = CD_TIME_MAX;
        fDeltaDistX     = (sRelCircleDataObj1.fX - sRelCircleDataObj2.fX);
        fDeltaDistY     = (sRelCircleDataObj1.fY - sRelCircleDataObj2.fY);
        fMinDistBound   = (sRelCircleDataObj1.fRadius + sRelCircleDataObj2.fRadius + fVarSafetyGap);

        sTrajPredObj.XofT.fC0 = fDeltaDistX;
        sTrajPredObj.XofT.fC1 = fDeltaVelX;
        sTrajPredObj.XofT.fC2 = 0.0f;
        sTrajPredObj.YofT.fC0 = fDeltaDistY;
        sTrajPredObj.YofT.fC1 = fDeltaVelY;
        sTrajPredObj.YofT.fC2 = 0.0f;

        (void)EMPCalcMinDistTime(&sTrajPredEgo, &sTrajPredObj, &fTimeMinDistNoAccel);
        /*MinDist Time without accel needs to be greater than zero*/
        if (fTimeMinDistNoAccel >= 0.0f)
        {
          fMinDistNoAccel = EMPCalcObjObjDistAtTime(fTimeMinDistNoAccel, &sTrajPredEgo, &sTrajPredObj);
          
          /*Calc TTM only if vehicles will crash (fMinDistNoAccel < fMinDistBound)*/
          if (fMinDistNoAccel < fMinDistBound)
          {
            sTrajPredObj.XofT.fC0 = fDeltaDistX;
            sTrajPredObj.XofT.fC1 = fDeltaVelX;
            sTrajPredObj.XofT.fC2 = fDeltaAccelX;
            sTrajPredObj.YofT.fC0 = fDeltaDistY;
            sTrajPredObj.YofT.fC1 = fDeltaVelY;
            sTrajPredObj.YofT.fC2 = fDeltaAccelY;

            /*Calculate MinDistTime for Polynomial with power of 3*/
            (void)EMPCalcMinDistTime(&sTrajPredEgo, &sTrajPredObj, &fTimeMinDistWithAccel);
            /*If MinDist Time is smaller CD_TIME_MAX go on*/
            if (fTimeMinDistWithAccel <= CD_TIME_MAX)
            {
              fMinDistWithAccel = EMPCalcObjObjDistAtTime(fTimeMinDistWithAccel, &sTrajPredEgo, &sTrajPredObj);
          
              /*Zero velocity can only be reached if accel smaller zero*/
              if (fRelevantAcceleration <= -C_F32_DELTA)
              {
                fTimeZeroVelocity = (-fObj1VelAbs)/fRelevantAcceleration;
              }
              else
              {
                fTimeZeroVelocity = CD_TIME_MAX;
              }
              /*If minDist with accel is reached after Object 1 stopped, calculate special case*/
              if (fTimeMinDistWithAccel > fTimeZeroVelocity)
              {
                float32 Obj1PxStandStill         = (0.5f*fObjAccelX*SQR(fTimeZeroVelocity)) + (pttmRelObj1->Movement.Vel.fX*fTimeZeroVelocity) + sRelCircleDataObj1.fX;
                float32 Obj1PyStandStill         = (0.5f*fObjAccelY*SQR(fTimeZeroVelocity)) + (pttmRelObj1->Movement.Vel.fY*fTimeZeroVelocity) + sRelCircleDataObj1.fY;
                float32 Obj1VxStandStill         = (fObjAccelX*fTimeZeroVelocity) + pttmRelObj1->Movement.Vel.fX;
                float32 Obj1VyStandStill         = (fObjAccelY*fTimeZeroVelocity) + pttmRelObj1->Movement.Vel.fY;
                float32 Obj2PxStandStill         = (pttmRelObj2->Movement.Vel.fX*fTimeZeroVelocity) + sRelCircleDataObj2.fX;
                float32 Obj2PyStandStill         = (pttmRelObj2->Movement.Vel.fY*fTimeZeroVelocity) + sRelCircleDataObj2.fY;
                float32 fDeltaVxStandStill       = Obj1VxStandStill - pttmRelObj2->Movement.Vel.fX;
                float32 fDeltaVyStandStill       = Obj1VyStandStill - pttmRelObj2->Movement.Vel.fY;
                float32 fDeltaPxStandStill       = Obj1PxStandStill - Obj2PxStandStill;
                float32 fDeltaPyStandStill       = Obj1PyStandStill - Obj2PyStandStill;
                float32 ftimeMinDistAfterVelZero = 0.0f;

                sTrajPredObj.XofT.fC0 = fDeltaPxStandStill;
                sTrajPredObj.XofT.fC1 = fDeltaVxStandStill;
                sTrajPredObj.XofT.fC2 = 0.0f;
                sTrajPredObj.YofT.fC0 = fDeltaPyStandStill;
                sTrajPredObj.YofT.fC1 = fDeltaVyStandStill;
                sTrajPredObj.YofT.fC2 = 0.0f;

                (void)EMPCalcMinDistTime(&sTrajPredEgo, &sTrajPredObj, &ftimeMinDistAfterVelZero);

                fMinDistWithAccel = EMPCalcObjObjDistAtTime(ftimeMinDistAfterVelZero, &sTrajPredEgo, &sTrajPredObj);

                /*Only consider time until object2 crossed in case that crash can be avoided*/
                if ( (fMinDistWithAccel >= fMinDistBound) && 
                     (ftimeMinDistAfterVelZero > (fTimeMinDistNoAccel-fTimeZeroVelocity)))
                {/* PRQA S 0715 *//* date: 2019-05-28, reviewer:Huang Wenting, reason: suppressing nesting of control structures */
                  ftimeMinDistAfterVelZero = (fTimeMinDistNoAccel-fTimeZeroVelocity);
                  fMinDistWithAccel = EMPCalcObjObjDistAtTime(ftimeMinDistAfterVelZero, &sTrajPredEgo, &sTrajPredObj);
                }
              }
              fVAngleObj1 = ATAN2_(pttmRelObj1->Movement.Vel.fY, pttmRelObj1->Movement.Vel.fX);
              fVObj2toObj1 = (COS_(fVAngleObj1)*pttmRelObj2->Movement.Vel.fX) + (SIN_(fVAngleObj1)*pttmRelObj2->Movement.Vel.fY);
              /*Crash avoidable*/
              if (fMinDistWithAccel >= fMinDistBound)
              {
                  float32 fDeltaDist = fMinDistWithAccel - fMinDistBound;
                  if (fABS(fObj1VelAbs - fVObj2toObj1) > C_F32_DELTA)
                  {/* PRQA S 0715 *//* date: 2019-05-28, reviewer:Huang Wenting, reason: suppressing nesting of control structures */
                    fTTMLong = fDeltaDist/fABS(fObj1VelAbs - fVObj2toObj1);
                  }
              }
              /*Crash unavoidable*/
              else
              {
                *bCollisionAvoidable = FALSE;
                if (fRelevantAcceleration <= 0.0f)
                {/* PRQA S 0715 *//* date: 2019-05-28, reviewer:Huang Wenting, reason: suppressing nesting of control structures */
                  if (fABS(fObj1VelAbs - fVObj2toObj1) > C_F32_DELTA)
                  {
                    fminTimeOfColl = fTimeMinDistNoAccel - (fMinDistBound/fABS(fObj1VelAbs - fVObj2toObj1));
                    fTTMLong = (   (fABS(fObj1VelAbs - fVObj2toObj1)*fminTimeOfColl ) 
                                 - (fABS((fObj1VelAbs/2.f) - fVObj2toObj1)*fTimeZeroVelocity))
                                 /  fABS(fObj1VelAbs - fVObj2toObj1);
                  }
                }
                else
                {/* PRQA S 0715 *//* date: 2019-05-28, reviewer:Huang Wenting, reason: suppressing nesting of control structures */
                  fTTMLong = 0.0f;
                }
              }
            }
          }
        }
        fTTMLong = MINMAX_FLOAT(0.0f, CD_TIME_MAX, fTTMLong);
        *pfTTMLong = MIN(*pfTTMLong, fTTMLong);
      }
    }
  }
  else
  {
    bReturn = FALSE;
  }
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTMLong                                                                        */ /*!

  @brief                Calculates the TTM for longitudinal scenarios. 

  @description          The function determines the remaining time until the driver of the ego vehicle has to react 
                        with an (positive or negative) acceleration to avoid a collision with an object. \n
                        Therefore the objects center position is used. The TTM is calculated once for a positive and 
                        once for a negative acceleration (@ref CDCalculateTTMLongCore). Of the two results the higher \n
                        one is set as TTM.
                        @startuml CDCalculateTTMLong_activity.png
                        start
                          :Create a local copy of the object 
                          and an artificial ego object;
                          #Orange:Calculate the TTM for a positive 
                          and a negative assumed acceleration
                          <b>CDCalculateTTMLongCore</b> >
                          :Select the higher one of 
                          the found TTM values;
                        stop
                        @enduml

  @return               boolean : False if error occurred

  @param[in]            iObjectIndex :       Index of the object to calculate the TTM for. @range [0,+...[
  @param[in,out]        pfTTMLong :          Output Time To Mitigate . @phys_unit [s] @range [0,+...[  
  @param[in]            fCDTTMAccelNeg :     Assumed longitudinal negative acceleration that the first object can use to prevent a crash. @phys_unit [m/s^2] @range ]-...,+...[
  @param[in]            fCDTTMAccelPos :     Assumed longitudinal positive acceleration that the first object can use to prevent a crash. @phys_unit [m/s^2] @range ]-...,+...[

  @glob_in              @ref ACDC_p_GetEgoMovementRaw \n
                        @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetACDCObjectMain \n
                        @ref ACDC_p_GetEgoMovementRaw\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTM_LONG

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Torben Meier
*************************************************************************************************************************/
static boolean CDCalculateTTMLong(ObjNumber_t         iObjectIndex,
                                  fTime_t     * const pfTTMLong,
                                  float32             fCDTTMAccelNeg,
                                  float32             fCDTTMAccelPos)
{
  /* local variable(s) */
  ACDCObjDescMain_t const * const pObject = ACDC_p_GetObjDescMain(iObjectIndex);
  boolean       bDecelValid;
  boolean       bAccelValid;
  boolean       bRetVal;
  float32       fTTMLongDecel    = CD_TIME_MAX;
  float32       fTTMLongAccel    = CD_TIME_MAX;
  ACDCObjDesc_t EgoDesc          = {0};
  ACDCObjDesc_t ObjDesc          = {0};
  boolean       bCollisionAvoidable;


  ObjDesc.bExists                = TRUE;
  ObjDesc.Geometry               = pObject->Geometry;
  ObjDesc.ObjectPosCenter        = pObject->Positions.Center;
  ObjDesc.Movement               = pObject->Movement.Abs;

  EgoDesc.bExists                = TRUE;
  EgoDesc.Movement               = *ACDC_p_GetEgoMovementRaw();
  EgoDesc.Movement.Accel.fX       = 0.f;
  EgoDesc.Movement.Accel.fY       = 0.f;
  EgoDesc.Geometry               = *ACDC_p_GetEgoGeometry();
  
  EgoDesc.ObjectPosCenter.fX     = -EgoDesc.Geometry.fLength/2.f;
  EgoDesc.ObjectPosCenter.fY     = 0.f;

  ObjDesc.Movement.Vel.fX         = pObject->TrajRelation.fVelocityOnTraj;
  ObjDesc.Movement.Vel.fY         = pObject->TrajRelation.fVelocityToTraj;


  /*Calc all values, transform DistX and DistY*/
  bDecelValid = CDCalculateTTMLongCore(&EgoDesc, &ObjDesc, fCDTTMAccelNeg, EgoDesc.Movement.Vel.fX, &fTTMLongDecel, &bCollisionAvoidable);
  bAccelValid = CDCalculateTTMLongCore(&EgoDesc, &ObjDesc, fCDTTMAccelPos, EgoDesc.Movement.Vel.fX, &fTTMLongAccel, &bCollisionAvoidable);

  *pfTTMLong = MAX(fTTMLongDecel, fTTMLongAccel);
  
  bRetVal = (((bDecelValid==TRUE) && (bAccelValid==TRUE)))?TRUE:FALSE;
  
  return bRetVal;
}

//!@}
#endif /* #if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON) */
#endif /* #if (ACDC_CFG_CD) */
