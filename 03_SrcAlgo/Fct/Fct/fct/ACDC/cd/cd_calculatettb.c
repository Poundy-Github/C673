/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculatettb.c

DESCRIPTION:               The calculation of TTBs for CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 09:53:43CEST $

VERSION:                   $Revision: 1.18 $
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
@defgroup cd_calculatettb Calculate TTB
@ingroup cd

@brief          The calculation of TTBPre and TTBAcute is done in this module \n\n

@description    Provides functions for the calculation of the different derivations of the TTB: \n
                @ref CD_f_GetTTBDynPre   \n
                @ref CD_f_GetTTBDynAcute
@{
*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static boolean CDCalculateTTBCore       ( CDMovement_t const * const pEgoMovement, 
                                          CDMovement_t const * const pObjMovement, 
                                          fAccel_t     const         fEgoAccelAssumed, 
                                          fTime_t            * const pTTCBrake,
                                          fTime_t            * const pTTB );

static boolean CDCalculateTTBStandstill ( CDMovement_t const * const pEgoMovement,
                                          CDMovement_t const * const pObjMovement, 
                                          fAccel_t                   fEgoAccelAssumed,
                                          fTime_t                    fTTC,
                                          fTime_t            * const pfTTB );

static boolean CDCalculateTTBDyn        ( ObjNumber_t                iObjectIndex,
                                          fAccel_t                   fEgoAccelAssumed,
                                          fTime_t            * const pfTTB );

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         CD_f_GetTTBDynPre                                                                            */ /*!

  @brief                Returns the TTBDyn for an assumed PreBrake deceleration.

  @description          The TTBDyn describes the time that remains until a driver has to brake with a certain 
                        deceleration to avoid a collision with an object. In case of the TTBBDyn Pre a moderate 
                        deceleration is assumed.\n
                        The function checks if the TTBDynPre has been calculated for the current object,
                        if not, @ref CDCalculateTTBDyn is called. The values for the assumed ego acceleration \n
                        depend on the velocity of the ego vehicle. They are stored in the matrix @ref CD_COMFORT_EGO_ACCEL_X.
                        After the calculation the TTBDynPre is returned. The function follows the common steps of a 
                        'Get Function' (see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTBDynPre of the considered object. @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref CD_s_GetEgoMov\n
                        @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTBDYNPRE_001 \n
                        @ref TEST_CD_F_GETTTBDYNPRE_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTBDynPre( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTBPre > CD_TTBDYN_CHECK)
  {
    /*Get the movement properties of Ego*/
    /*PRQA S 1031 1*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const CDEgoMovement   = CD_s_GetEgoMov();
    fAccel_t           fEgoAccelTTBPre = CML_f_CalculatePolygonValue(CD_NUMBER_OF_COMFORT_EGO_ACCEL_X_VALUES, CD_COMFORT_EGO_ACCEL_X, CDEgoMovement.fVx);

    (void)CDCalculateTTBDyn( iObjectIndex, fEgoAccelTTBPre, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTBPre) );
  }
  return pTTX->TTBPre;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTBDynAcute                                                                            */ /*!

  @brief                Returns the TTBDyn for an assumed AcuteBrake deceleration.

  @description          The TTBDyn describes the time that remains until a driver has to brake with a certain 
                        deceleration to avoid a collision with an object. In case of the TTBBDyn Acute an emergency
                        braking with maximum deceleration is assumed.\n
                        The function checks if the TTBDynAcute has been calculated for the current object,
                        if not, @ref CDCalculateTTBDyn is called. The value for the assumed ego acceleration \n
                        is set to @ref CD_EMERGENCY_BRAKE_ACCEL. After the calculation the TTBDynAcute is returned. 
                        The function follows the common steps of a 'Get Function' (see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTBDynAcute of the considered object. @phys_unit [s] @range[0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTBDYNACUTE_001 \n
                        @ref TEST_CD_F_GETTTBDYNACUTE_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTBDynAcute( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTBAcute > CD_TTBDYN_CHECK)
  {
    (void)CDCalculateTTBDyn( iObjectIndex, CD_EMERGENCY_BRAKE_ACCEL, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTBAcute) );
  }
  return pTTX->TTBAcute;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTBCore                                                                           */ /*!

  @brief                Calculates the time until the ego vehicle has to brake with EgoAccelAssumed to avoid a 
                        collision. The function does not consider a object standstill.

  @description          The Time to brake describes the time that remains for the driver to react with a certain brake 
                        acceleration to avoid a collision with an object. Therefore the TTC also has to be recalculated, \n
                        as it depends on the chosen TTB. 
                        The following scenarios are distinguished for the calculation:
                        1. **Ego vehicle already brakes with (at least) assumed acceleration** \n
                          As the brake acceleration will not be increased by the assumed acceleration, a collision 
                          is either avoided by the already applied acceleration or can not be avoided.\n
                          >see illustration "Derivation 1"
                        2. **Assumed brake acceleration is higher than the current Ego acceleration** \n
                          The ego vehicle keeps its current kinematics and applies the assumed brake acceleration 
                          (which is higher than the current one) after it reaches TTB.
                          1. **Object brakes exactly with the assumed acceleration** \n
                            If ego vehicle and object brake with the same acceleration after TTB, the time at 
                            which the ego vehicle has to start to decelerate is the time of equal velocity. \n
                            This assumption is valid as a possible stopping is not considered. \n
                            >see illustration "Derivation 2.1"
                          2. **Object does not brake with exactly the assumed acceleration** \n
                            This is the standard case. Neither the ego vehicle nor the object brake with the assumed 
                            acceleration at t=t0. After TTB the ego vehicle applies the assumed acceleration. 
                            (see illustration "Derivation 2.2")\n
                            The calculation follows the subsequent steps:
                            1. **Assumptions**: Formulas for velocity and position of the object and the ego vehicle. \n
                              - Ego Vehicle: \n
                                \f$X_{Ego}(t) = X_{Ego,TTB} + V_{x,Ego,TTB} \cdot (t-t_{TTB}) + 0.5 \cdot A_{x,Ego,Assu} \cdot (t-t_{TTB})^2\f$ \n
                                with \n
                                \f$V_{x,Ego,TTB} = V_{x,Ego,0} + A_{x,Ego,Assu}\cdot t_{TTB}\f$ \n
                              - Object: \n
                                \f$X_{Obj}(t) = X_{Obj,0} + V_{x,Obj,0} \cdot t + 0.5 A_{x,Obj,0}\cdot t^2\f$
                            2. **Collision conditions**: Positioning conditions that are fulfilled in case of a collision. \n
                              \f$X_{Obj}(t_{TTC}) = X_{Ego}(t_{TTC})\f$ \n
                              => \f$0 = \f$ \n
                              \f$[t_{TTC}^2 \cdot A_{TTC}:]\f$ \f$t_{TTC}^2 \cdot 0.5 A_{x,Rel,Obj}\f$                       \n
                              \f$[t_{TTC}   \cdot B_{TTC}:]\f$ \f$+ t_{TTC} \cdot V_{x,Rel,0}-A_{x,Rel,Ego}\cdot t_{TTB} \f$ \n
                              \f$[1         \cdot C_{TTC}:]\f$ \f$+ 1 \cdot X_{Rel,0} + 0.5 A_{x,Rel,Ego} \cdot t_{TTB}^2\f$ \n
                              with: \n
                              \f$ V_{x,Rel,0} = V_{x,Obj,0}-V_{x,Ego,0}      \f$ \n
                              \f$ A_{x,Rel,Obj} = A_{x,Obj,0}-A_{x,Ego,Assu} \f$ \n
                              \f$ A_{x,Rel,Ego} = A_{x,Ego,0}-A_{x,Ego,Assu} \f$ \n
                              This formula describes the Distance of object and ego vehicle in dependence of t and the TTB.
                              The idea is now to select the TTB in a way, that the result can never be below zero. \n
                              Therefore the equation must only have one TTC.
                            3. **Discriminant of the TTC equation**: The discriminant has to become zero to assure, that Xrel does not get negative. \n
                              \f$D_{TTC} = B_{TTC}^2-4 \cdot A_{TTC}\cdot C_{TTC}\f$ \n
                              => \f$D_{TTC} = \f$ \n
                              \f$[t_{TTB}^2 \cdot A_{TTB}:]\f$ \f$t_{TTB}^2 \cdot (A_{x,Rel,Ego}^2 - A_{x,Rel,Ego}-A_{x,Rel,Obj})   \f$\n
                              \f$[t_{TTB}   \cdot B_{TTB}:]\f$ \f$+ t_{TTB} \cdot (-2V_{x,Rel,0} \cdot A_{x,Rel,Ego})               \f$\n
                              \f$[1         \cdot C_{TTB}:]\f$ \f$+ 1       \cdot (V_{x,Rel,0}^2-2A_{x,Rel,Obj} \cdot X_{rel}       \f$\n
                            4. **Solve TTB equation**: Solve the discriminant of the distance equation to get the TTB. \n
                              Discriminant of TTB equation: \n
                              \f$D_{TTB} = B_{TTB}-4\cdot A_{TTB}\cdot C_{TTB}\f$
                              - Discriminant of TTB equation = 0: One solution.\n
                                \f$t_{TTB} = \frac{-B_{TTB}}{2 \cdot A_{TTB}} \f$
                              - Discriminant of TTB equation > 0: Two solutions. \n
                                \f$t_{TTB,1/2} = \frac{-B_{TTB} \pm D_{TTB}}{2 \cdot A_{TTB}} \f$ \n
                                \f$t_{TTB}\f$ is the result that is below its calculated \f$t_{TTC}\f$
                              - Discriminant of TTB equation < 0: No solution.\n
                                There is no TTB for which there is only one solution for the TTC equation.\n
                                \f$t_{TTB} = Default\f$
                              .
                              \f$t_{TTC} = -\frac{V_{x,Rel}-A_{x,Rel,Ego}\cdot t_{TTB}}{A_{x,Rel,Obj}} \f$
                            .
                          .
                        .
                        \section derivation1 Derivation 1
                        \image html CD_CalculateTTBCore_1.svg  width=1600
                        \section derivation21 Derivation 2.1
                        \image html CD_CalculateTTBCore_2_1.svg width=1600
                        \section derivation22 Derivation 2.2
                        \image html CD_CalculateTTBCore_2_2.svg width=1600
                        For more information see also: \n
                        [AL_FCT_CGEB_TTx_Calculation.mht](http://ims-adas:7001/si/viewrevision?projectName=%2FADAS%2FSW%2FComponents%2FACDC_CollisionDetectionAndClassification%2F03_Design
                        %2F01_Supporting_Documents%2Fproject.pj&selection=AL_FCT_CGEB_TTx_Calculation.mht)

  @return               boolean : Always true

  @param[in]            pEgoMovement :      Ego movement information.
  @param[in]            pObjMovement :      Object movement information.
  @param[in]            fEgoAccelAssumed :  Assumed ego acceleration when braking. @phys_unit [m/s] @range ]-...,0[
  @param[in,out]        pTTCBrake :         Time-To-Collision when braking. @phys_unit [s] @range[0, \ref CD_TIME_MAX]
  @param[in,out]        pTTB :              Time-To-Brake with assumed acceleration. @phys_unit [s] @range[0, \ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @todo                 In the current form the function seems to complex to be tested easily. 
                        It should therefore be split up in subfunctions.

  @author               Andreas Jakob

  @testmethod           @ref TEST_CDCALCULATETTBCORE_001 \n
                        @ref TEST_CDCALCULATETTBCORE_002 \n
                        @ref TEST_CDCALCULATETTBCORE_003 \n
                        @ref TEST_CDCALCULATETTBCORE_004 \n
                        @ref TEST_CDCALCULATETTBCORE_005 \n
                        @ref TEST_CDCALCULATETTBCORE_006 \n
                        @ref TEST_CDCALCULATETTBCORE_007 \n
                        @ref TEST_CDCALCULATETTBCORE_008 \n
                        @ref TEST_CDCALCULATETTBCORE_009 \n
                        @ref TEST_CDCALCULATETTBCORE_010 \n
						@ref TEST_CDCALCULATETTBCORE_011 \n
						@ref TEST_CDCALCULATETTBCORE_012 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTBCore( CDMovement_t const * const pEgoMovement,
                                   CDMovement_t const * const pObjMovement,
                                   fAccel_t             const fEgoAccelAssumed,
                                   fTime_t            * const pTTCBrake,
                                   fTime_t            * const pTTB)
{
  /* local variable(s) */
  boolean bReturn = b_TRUE;
  CDMovement_t RelMovementX;
  fAccel_t RelAccelBraking;
  fAccel_t EgoRelAccel;
  fTime_t TimeEqualVel;
  fDistance_t XRelEqualVel;
  float32 fA;
  float32 fB;
  float32 fC;
  float32 fDiscriminant;
  fTime_t fTTBtemp[SFL_QUAD_EQU_SOLUTION_ARRAY_SIZE];
  fTime_t fTTCBraketemp[SFL_QUAD_EQU_SOLUTION_ARRAY_SIZE];

  /* set default value for TTB and TTCBrake */
  *pTTB      = CD_TIME_MAX;
  *pTTCBrake = CD_TIME_MAX;

  RelMovementX.fX  = pObjMovement->fX  - pEgoMovement->fX ;
  RelMovementX.fVx = pObjMovement->fVx - pEgoMovement->fVx;
  RelAccelBraking  = pObjMovement->fAx - fEgoAccelAssumed;

  EgoRelAccel      = pEgoMovement->fAx - fEgoAccelAssumed;

  /* ego vehicle already stands and can't drive backwards */
  if (fABS(pEgoMovement->fVx) < C_F32_DELTA)
  {
    RelMovementX.fVx = pObjMovement->fVx;
    RelAccelBraking  = pObjMovement->fAx;
    EgoRelAccel      = 0.0f;
  }

  /* DERIVATION 1): ego already brakes with at least assumed acceleration */
  if ( EgoRelAccel < C_F32_DELTA )
  {
    (void)CDCalculateTTC( pEgoMovement, pObjMovement, pTTCBrake );
    if ((*pTTCBrake) < CD_TIME_MAX) /* We still have a collision */
    {
      *pTTB     = 0.0f;
    }
    else
    {
      *pTTB     = CD_TIME_MAX;
    }
  }
  /* DERIVATION 2): ego with assumed acceleration brakes stronger than before */
  else
  {
    /* DERIVATION 2.1): object brakes with assumed acceleration */
    if ( fABS(RelAccelBraking) < C_F32_DELTA )
    {
      /* time when velocities are equal */
      TimeEqualVel = RelMovementX.fVx / EgoRelAccel;

      /* relative position when velocities are equal */
      XRelEqualVel = CDCalculateDistance( RelMovementX.fX, 0.0f, EgoRelAccel, TimeEqualVel );
      /* DERIVATION 2.1.1): braking with assumed deceleration is not sufficient to prevent collision */
      if ( XRelEqualVel < C_F32_DELTA )
      {
        *pTTB = 0.0f;
        (void)CDCalculateTTC( pEgoMovement, pObjMovement, pTTCBrake );
      }
      /* DERIVATION 2.1.2): braking when velocity is equal prevents collision */
      else
      {
        *pTTB         = TimeEqualVel;
        *pTTCBrake    = CD_TIME_MAX;
      }
    }
    /* DERIVATION 2.2) */
    else
    {
      /*PRQA S 3121 3*/ /* Solutions according to derivation */
      fA = SQR(EgoRelAccel) - (RelAccelBraking * EgoRelAccel);
      fB = -2.0f * RelMovementX.fVx * EgoRelAccel;
      fC = SQR(RelMovementX.fVx) - (2.0f * RelAccelBraking * RelMovementX.fX);
      /* DERIVATION 2.2.1): fA == 0 */
      if (fABS(fA) < C_F32_DELTA)
      {
        /* DERIVATION 2.2.1.1): fB == 0 */
        if (fABS(fB) < C_F32_DELTA)
        {
          /* DERIVATION 2.2.1.1.2 and 2.2.1.1.3) */
          if (fC >= 0.0f)
          {
            /*the possibilities: Ego has either touched the object or braking cannot avoid the collision*/
            *pTTB         = 0.0f;
            (void)CDCalculateTTC( pEgoMovement, pObjMovement, pTTCBrake );
          }
          /* DERIVATION 2.2.1.1.1) */
          else
          {
            /* no collision */
            *pTTB      = CD_TIME_MAX;
            *pTTCBrake = CD_TIME_MAX;
          }
        }
        /* DERIVATION 2.2.1.2): fB != 0 */
        else
        {
          *pTTB      = - fC/fB;
          *pTTCBrake    = -(( RelMovementX.fVx - ( EgoRelAccel * ( *pTTB ))) / RelAccelBraking );
        }
      }
      /* DERIVATION 2.2.2): fA != 0 */
      else
      {
        /*general solution of the quadratic equation: sol_0,1=[-fB +- sqrt(fB^2-4*fA*fC)]/(2*fA)*/
        fDiscriminant = SQR(fB) - (4.0f * fA * fC);/*PRQA S 3121*//*see solution of quadratic equation*/
        /* DERIVATION 2.2.2.2): fDiscriminant == 0 */
        if (fABS(fDiscriminant) < C_F32_DELTA)
        {
          *pTTB       = -fB / (2.0f * fA);/*PRQA S 3121*//*see solution of quadratic equation*/

          *pTTCBrake   = -( RelMovementX.fVx - ( EgoRelAccel * ( *pTTB ))) / RelAccelBraking;
        }
        /* fDiscriminant != 0 */
        else
        {
          /* DERIVATION 2.2.2.3) */
          if (fDiscriminant > 0.0f)
          {
            const float32 fSQRTDiscriminant = SQRT(fDiscriminant);
            fTTBtemp[0]       = -(fB + fSQRTDiscriminant) / (2.0f * fA);/*PRQA S 3121*//*see solution of quadratic equation*/
            fTTBtemp[1]       = -(fB - fSQRTDiscriminant) / (2.0f * fA);/*PRQA S 3121*//*see solution of quadratic equation*/
            fTTCBraketemp[0]  = -((RelMovementX.fVx - (EgoRelAccel * fTTBtemp[0])) / RelAccelBraking);
            fTTCBraketemp[1]  = -((RelMovementX.fVx - (EgoRelAccel * fTTBtemp[1])) / RelAccelBraking);

            if ((fTTCBraketemp[0] < *pTTCBrake) && (fTTBtemp[0] < fTTCBraketemp[0] ))
            {
              *pTTB       = fTTBtemp[0];
              *pTTCBrake  = fTTCBraketemp[0];
            }
            if ((fTTCBraketemp[1] < *pTTCBrake) && (fTTBtemp[1] < fTTCBraketemp[1]))
            {
              *pTTB       = fTTBtemp[1];
              *pTTCBrake  = fTTCBraketemp[1];
            }
          }
          /* DERIVATION 2.2.2.1): fDiscriminant < 0 */
          else
          {
            if(fC < 0.0f)
            {
              *pTTB = CD_TIME_MAX;
              *pTTCBrake = CD_TIME_MAX;
            }
            /*fC can't be 0 as in this case fDiscriminant wouldn't be negative*/
            else
            {
              *pTTB = 0.0f;
            (void)CDCalculateTTC( pEgoMovement, pObjMovement, pTTCBrake );
            }
          }
        }
      }
    }
  }
  
  /* limit TTCBrake */
  if(*pTTCBrake < 0.0f)
  {
    *pTTCBrake = 0.0f;
  }
  if(*pTTCBrake > CD_TIME_MAX)
  {
    *pTTCBrake = CD_TIME_MAX;
  }

  /* limit TTB */
  if (*pTTB < 0.0f)
  {
    if ( (*pTTCBrake) < CD_TIME_MAX )
    {
      *pTTB = 0.0f;
    }
    else
    {
      *pTTB     = CD_TIME_MAX;
    }
  }
  else
  {
    if (*pTTB > CD_TIME_MAX)
    {
      *pTTB     = CD_TIME_MAX;
    }
  }

  /* return */
  return bReturn;
}/* PRQA S 7002,7004 # Date:2020-06-03, Reviewer: Praveen Annareddy , Reason: suppressing cyclomatic complexity for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         CDCalculateTTBStandstill                                                                     */ /*!

  @brief                Calculates the time that remains for the driver to react with an assumed brake acceleration to 
                        stop the vehicle at the time of collision.

  @description          The TTB Standstill is calculated for oncoming objects which do not stop before a collision with 
                        the ego vehicle. It is therefore impossible for the ego vehicle to avoid a collision by braking. \n
                        Nevertheless to minimize the damage, the ego vehicle should be stopped at the collision time. \n
                        Note that the default value for TTB is defined as \ref CD_TIME_MAX.
                        @startuml CDCalculateTTBStandstill_activity.png
                        start
                          :Calculate Coefficients for the TTBStandstill Equation;
                          note left: >see formula\n"TTBStandstill Equation"

                          #Orange: Resolve the TTBStandstill Equation
                          <b>SFL_v_SolveQuadrEquation</b> >
                          
                          if (Number of solutions == 2?) then (Yes)
                            if (Both solutions > CD_TIME_MAX?) then (Yes)
                              :1}
                              :**TTB** = default;
                              note left: Ego vehicle will stand without\nadditional braking before the collision
                            elseif (Both solutions > 0?) then (Yes)
                              :2}
                              :**TTB** = Minimum solution;
                            elseif (One solution > 0?) then (Yes)
                              :3}
                              :**TTB** = Maximum solution;
                            else (No)
                              :4}
                              :**TTB** = 0;
                            endif
                          elseif (Number of solutions == 1?) then (Yes)
                            :5}
                            :**TTB** = found solution;
                          else (No)
                            :6}
                            :**TTB** = default;
                          endif
                        stop
                        @enduml
                        The TTBStandstill Equation is derived by the following steps: \n
                        1. **Assumptions:**
                          - *Ego Vehicle:* \n
                            \f$X_{Ego}(t_{Ego,Stop}) = X_{Ego,TTB} + V_{Ego,TTB} \cdot (t_{Ego,Stop}-t_{TTB}) + 0.5 A_{Ego,Assu} \cdot (t_{Ego,Stop}-t_{TTB})^2 \f$ \n
                          - *Object:* \n
                            \f$X_{Obj}(t_{Ego,Stop}) = X_{Obj,0} + V_{Obj,0} \cdot t_{Ego,Stop} + 0.5A_{Obj,0}\cdot t_{Ego,Stop}^2\f$
                          .
                          with: \n
                          - \f$t_{Ego,Stop} = -\frac{V_{Ego,TTB,0}}{A_{Ego,Assu}}\f$ \n
                          - \f$X_{Ego,TTB} = V_{Ego,0} + A_{Ego,0} \cdot t_{TTB}\f$
                          .
                        2. **Conditions for a collision:**\n
                          If all variables are replaced by the given equalizations, the only remaining unknown variable is \f$t_{TTB}\f$. \n
                          It can be determined by equalizing the positions of the ego vehicle and the object:\n
                          \f$X_{Obj}(t_{TTB}) = X_{Ego}(t_{TTB})\f$
                        3. **Expand formula**:\n
                          The resulting formula is shown in the In-/Out- Correlation Tag

  @return               boolean retValue: Always true

  @param[in]            *pEgoMovement :     Movement information of the ego vehicle.
  @param[in]            *pObjMovement :     Movement information of the object.
  @param[in]            fEgoAccelAssumed :  Brake acceleration the ego vehicle can apply. @phys_unit [m/s^2] @range ]-...,0[
  @param[in]            fTTC :              Time to collision. @phys_unit [s] @range[0,+...[
  @param[in,out]        *pfTTB :            Calculated time to brake. @phys_unit [s] @range [0, \ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     - **TTBStandstill Equation**: \n
                        \f$0 = \f$ \n
                        \f$t_{TTB}^2 \cdot A_{Ego,Assu} A_{Ego,0} \cdot(0.5A_{Ego,0}-A_{Obj,0})+0.5A_{Ego,Assu}^2(A_{Obj,0}-A_{Ego,0})+0.5A_{Ego}^2A_{Obj,0}\f$ \n
                        \f$t_{TTB} \cdot A_{Ego,0}A_{Obj,0}V_{Ego,0}+A_{Ego,Assu}^2\cdot(A_{Obj,0}-A_{Ego,0})+A_{Ego,Assu}\cdot(A_{Ego,0}V_{Ego,0}-A_{Obj,0}V_{Ego,0}-A_{Ego,0}V{Obj,0}))\f$ \n
                        \f$1 \cdot 0.5 \cdot A_{Obj,0}V_{Ego,0}^2+A_{Ego,Assu}V_{ego,0}\cdot(0.5\cdot V_{Ego,0}-V_{Obj,0})+A_{Ego,Assu}^2X_{Obj,0}\f$ \n

  @author               Andreas Jakob

  @testmethod           @ref TEST_CDCALCULATETTBSTANDSTILL_001 \n
                        @ref TEST_CDCALCULATETTBSTANDSTILL_002 \n
                        @ref TEST_CDCALCULATETTBSTANDSTILL_003 \n
                        @ref TEST_CDCALCULATETTBSTANDSTILL_004 \n
                        @ref TEST_CDCALCULATETTBSTANDSTILL_005 \n
						@ref TEST_CDCALCULATETTBSTANDSTILL_006 \n
  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTBStandstill(CDMovement_t const * const pEgoMovement,
                                        CDMovement_t const * const pObjMovement, 
                                        fAccel_t                   fEgoAccelAssumed,
                                        fTime_t                    fTTC,
                                        fTime_t            * const pfTTB)
{
  boolean retValue = b_TRUE;
  CDMovement_t RelMovementX;
  SFLPolynomialSolutions_t TTBStandstillSol;
  float32 fA;
  float32 fB;
  float32 fC;

  RelMovementX.fX  = pObjMovement->fX  - pEgoMovement->fX ;
  RelMovementX.fVx = pObjMovement->fVx - pEgoMovement->fVx;
  RelMovementX.fAx = pObjMovement->fAx - pEgoMovement->fAx;
  
  /* equation: xObj - xEgo = fA * TTB^2 + fB *TTB + fC = 0
   * tBrake = -vEgoTTB/aBrake; vEgoTTB = vEgo0 + aEgo0*TTB; vObjTTB = vObj0 + aObj0*TTB;
   * xEgo   = xEgo0 + vEgo0*TTB + 0.5*aEgo0*TTB^2 + vEgoTTB*tBrake + 0.5*aBrake*tBrake^2;
   * xObj   = xObj0 + vObj0*TTB + 0.5*aObj0*TTB^2 + vObjTTB*tBrake + 0.5*aObj0*tBrake^2;  
  */
  /*PRQA S 3121 1*//*see equation of motion above*/
  fA = (fEgoAccelAssumed*(pEgoMovement->fAx)*((0.5f*(pEgoMovement->fAx))-(pObjMovement->fAx)))+(SQR(fEgoAccelAssumed)*(0.5f*RelMovementX.fAx))+(0.5f*SQR(pEgoMovement->fAx)*(pObjMovement->fAx));
  fB = ((pEgoMovement->fAx)*(pObjMovement->fAx)*(pEgoMovement->fVx))
       + (SQR(fEgoAccelAssumed)*(RelMovementX.fVx))
       + (fEgoAccelAssumed*(((pEgoMovement->fAx)*(pEgoMovement->fVx))-((pObjMovement->fAx)*(pEgoMovement->fVx))-((pEgoMovement->fAx)*(pObjMovement->fVx))));
  /*PRQA S 3121 1*//*see equation of motion above*/
  fC = (0.5f*(pObjMovement->fAx)*SQR(pEgoMovement->fVx))+(fEgoAccelAssumed*(pEgoMovement->fVx)*((0.5f*(pEgoMovement->fVx))-(pObjMovement->fVx)))+(SQR(fEgoAccelAssumed)*(RelMovementX.fX));
  
  SFL_v_SolveQuadrEquation( fA, fB, fC, &TTBStandstillSol);


  if (TTBStandstillSol.uNofSolutions == SFL_QUAD_EQU_SOLUTION_ARRAY_SIZE)
  {
    /* both solutions == CD_TIME_MAX -> there wouldn't be a collision when not considering the standstill cases
      set TTB to CD_TIME_MAX because Ego will stand without braking before the collision*/
    if((TTBStandstillSol.afSolutions[0] > (CD_TIME_MAX-C_F32_DELTA)) && (TTBStandstillSol.afSolutions[1] > (CD_TIME_MAX-C_F32_DELTA)))
    {
      *pfTTB = CD_TIME_MAX;
    }
    /* 0 <= TTB < CD_TIME_MAX*/
    else
    {
      /* is at least one TTB < 0 => choose max(TTB[1],TTB[2]); both TTB > 0 => choose min(TTB[1],TTB[2])*/
      (*pfTTB) = ((TTBStandstillSol.afSolutions[0] < 0.f) || (TTBStandstillSol.afSolutions[1] < 0.f)) ? 
                 (MAX_FLOAT(TTBStandstillSol.afSolutions[0], TTBStandstillSol.afSolutions[1])) : 
                 (MIN_FLOAT(TTBStandstillSol.afSolutions[0], TTBStandstillSol.afSolutions[1])) ;
      /* is TTB in interval[0 CD_TIME_MAX], else set TTB to threshold*/
      (*pfTTB) = MINMAX_FLOAT(0.0f, CD_TIME_MAX, *pfTTB);
      /* if TTB is greater than TTC, wrong value has been chosen; braking should have begun in past => set TTB to 0  */
      (*pfTTB) = (*pfTTB < fTTC)? (*pfTTB) : 0.f;
    }
  }
  else if (TTBStandstillSol.uNofSolutions == 1u)
  {
    (*pfTTB) = MINMAX_FLOAT(0.f, CD_TIME_MAX, TTBStandstillSol.afSolutions[0]);
  }
  /* If no solution is found set TTB to default maximum time value */
  else
  {
    *pfTTB = CD_TIME_MAX;
  }
  return retValue; 
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTBDyn                                                                            */ /*!

  @brief                Calculate the TTB of an object under consideration of stopping and oncoming scenarios.

  @description          The TTB describes the time the driver of the ego vehicle has to avoid a collision by reacting 
                        with a given brake acceleration. This function handles different driving situations and calls \n
                        the main functions for the TTB calculation: \ref CDCalculateTTBCore and \ref CDCalculateTTBStandstill.
                        The following situations are distinguished:
                        1. **Object is stationary or comoving**
                          1. **Object stops before TTC:** \n
                             Set Object V and A to 0 and predict position to stopping position. Execute standard TTB calculation.
                          2. **Object does not stop:** \n
                             Execute standard TTB calculation
                          .
                        2. **Object is oncoming**
                          1. **Object acceleration is positive**
                            1. **Ego stops before TTB:**\n
                               No additional brake acceleration necessary. Set TTB to default value \ref CD_TIME_MAX.
                            2. **Ego does not stop before TTB**
                              1. *Ego vehicle stops before the object if it applies the assumed acceleration:* \n
                                 Object does not stop before the collision. Execute TTB standstill calculation.
                              2. *Object stops before the ego vehicle:* \n
                                 Object stops before the collision. Execute standard TTB calculation.
                              .
                            .
                          2. **Object acceleration is zero or negative:**
                              1. **Ego-Vehicle stops before collision** \n
                                No additional brake acceleration necessary. Set TTB to default value \ref CD_TIME_MAX.
                              2. **Ego-Vehicle doesn't stop before collision** \n
                                Neither the object nor the Ego-Vehicle will top before collision. Execute TTB standstill calculation.
                          .
                        .
                        @startuml CDCalculateTTBDyn_activity.png
                        start
                          #Orange:Calculate TTC of the object
                          <b>CDCalculateTTC</b> >
                          if (TTC is valid? AND Ego vehicle is moving forward?) then (Yes)
                            #Orange:Calculate time until object stops
                            <b>CDCalculateVehStopTime</b> >
                            note left: Assuming a constant acceleration
                            if(Check Object movement) then (Comoving or stationary)
                              #Orange:Calculate TTC and TTB in case the ego
                              vehicle brakes at T=TTB
                              <b>CDCalculateTTBCore</b> >
                              if(Object stops before TTC?) then (Yes)
                                :1}
                                :Set objects acceleration and velocity to 0.
                                 Set objects position to stopping position;
                                #Orange:Recalculate **TTB** with the new kinematics
                                <b>CDCalculateTTBCore</b> >
                              else(No)
                                :2}
                                :**TTB** = previously calculated TTB;
                              endif
                            else (Oncoming)
                              if (Object accelerates significantly away from ego vehicle?) then (Yes)
                                :Set objects acceleration and velocity to 0.
                                Set objects position to stopping position;
                                #Orange:Calculate TTB with the new kinematics
                                <b>CDCalculateTTBCore</b> >
                                #Orange:Calculate Ego velocity at T = TTB
                                <b>CDCalculateVelocity</b> >
                                if(Ego velocity at T = TTB) then (< 0)
                                  :3}
                                  :Ego vehicle stops before collision 
                                  without the need of further braking
                                  **TTB** = default;
                                else(>= 0)
                                  #Orange:Calculate Time at which ego vehicle stops
                                  <b>CDCalculateVehStopTime</b> >
                                  if(Object stops before ego vehicle?) then (Yes)
                                    :4}
                                    :**TTB** = previously calculated TTB;
                                  else(No)
                                    :5}
                                    #Orange:Braking of ego vehicle can't avoid collision, 
                                    **TTB** = TTB Standstill
                                    <b>CDCalculateTTBStandstill</b> >
                                  endif
                                endif
                              else (No)
                                #Orange: Calculate time until ego vehicle stops
                                <b>CDCalculateVehStopTime</b> >
                                if(Ego vehicle stops before collision?) then (Yes)
                                  :6}
                                  :**TTB** = default;
                                else (No)
                                  :7}
                                  #Orange: Neither object nor Ego-Vehicle will stop before collision,
                                  **TTB** = TTB Standstill
                                  <b>CDCalculateTTBStandstill</b> >
                                  note right: Assuming a constant acceleration
                                endif
                              endif
                            endif
                          else (No)
                            :8}
                            :**TTB** = default;
                          endif

                          legend
                            TTB Standstill:
                            Time until ego vehicle has to brake
                            to be at velocity 0 at time of collision
                          end legend
                        stop
                        @enduml

  @return               boolean : False if error occurred.

  @param[in]            iObjectIndex :    Index of the object for which the value shall be returned.
  @param[in]            fEgoAccelAssumed :  Brake acceleration the ego vehicle can use. @phys_unit [m/s^2] @range ]-...,0[
  @param[in,out]        pfTTB :             Calculated Time to brake. @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @glob_in              @ref CD_s_GetEgoMov \n
                        @ref CD_s_GetObjMov \n
                        @ref CD_f_GetTTC
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Jakob

  @testmethod           @ref TEST_CDCALCULATETTBDYN_001 \n
                        @ref TEST_CDCALCULATETTBDYN_002 \n
                        @ref TEST_CDCALCULATETTBDYN_003 \n
                        @ref TEST_CDCALCULATETTBDYN_004 \n
						@ref TEST_CDCALCULATETTBDYN_005 \n
						@ref TEST_CDCALCULATETTBDYN_006 \n
						@ref TEST_CDCALCULATETTBDYN_007 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTBDyn( ObjNumber_t                iObjectIndex,
                                  fAccel_t                   fEgoAccelAssumed,
                                  fTime_t            * const pfTTB )
{
  /* local variable(s) */
  boolean bReturn = b_TRUE;
  fTime_t fTTC;
  fTime_t fTTCBrake;
  fTime_t fTimeObjStop;
  fTime_t fTimeEgoStop;

  /*Get the movement properties of Ego and Obj*/
  /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  CDMovement_t   const EgoMovement    = CD_s_GetEgoMov();
  CDMovement_t   const AbsObjMovement = CD_s_GetObjMov(iObjectIndex,POS_CLOSEST_IN_X,KIN_ABS);

  /* calculate TTC */
  fTTC = CD_f_GetTTC(iObjectIndex);

  /* TTC is valid and Ego is moving forward*/
  if ((fTTC < CD_TIME_MAX) && (EgoMovement.fVx > C_F32_DELTA))
  {
    /* calculate stop time for Obj */
    (void)CDCalculateVehStopTime(AbsObjMovement.fVx, AbsObjMovement.fAx, &fTimeObjStop);

    /*object is standing or departing*/
    if(AbsObjMovement.fVx >= 0.0f)
    {
      /* calculate TTB */
      (void)CDCalculateTTBCore(&EgoMovement, &AbsObjMovement, fEgoAccelAssumed, &fTTCBrake, pfTTB);
      if (fTimeObjStop < fTTCBrake)
      {
        CDMovement_t ObjMovementStopped;
        ObjMovementStopped     = AbsObjMovement;
        ObjMovementStopped.fX  = CDCalculateDistance(AbsObjMovement.fX,  AbsObjMovement.fVx, AbsObjMovement.fAx, fTimeObjStop);
        ObjMovementStopped.fVx = 0.0f;
        ObjMovementStopped.fAx = 0.0f;
        (void)CDCalculateTTBCore(&EgoMovement, &ObjMovementStopped, fEgoAccelAssumed, &fTTCBrake, pfTTB);
      }
      else
      {
        //calculated TTB is valid
      }
    }
    /* object is oncoming */
    else
    {    
      /* object stops before CD_TIME_MAX (pObjMovement->fAx > 0) */
      if(fTimeObjStop < CD_TIME_MAX)
      {
        fTime_t fTimeEgoStopBrake;
        fVelocity_t fVelTTB;
        CDMovement_t ObjMovementStopped;
        /* set Obj to stop position and calculate TTB */
        ObjMovementStopped     = AbsObjMovement;
        ObjMovementStopped.fX  = CDCalculateDistance(AbsObjMovement.fX,  AbsObjMovement.fVx, AbsObjMovement.fAx, fTimeObjStop);
        ObjMovementStopped.fVx = 0.0f;
        ObjMovementStopped.fAx = 0.0f;
        (void)CDCalculateTTBCore(&EgoMovement, &ObjMovementStopped, fEgoAccelAssumed, &fTTCBrake, pfTTB); 
        fVelTTB = CDCalculateVelocity(EgoMovement.fVx,EgoMovement.fAx,*pfTTB);
        /* Ego still moving forward at TTB? */
        if(fVelTTB >= 0.0f)
        {
          (void)CDCalculateVehStopTime(fVelTTB, fEgoAccelAssumed, &fTimeEgoStopBrake);
          /* will Ego(AccelAssumed) stop before Obj?*/
          if( (fTimeEgoStopBrake+(*pfTTB)) < fTimeObjStop )
          {
            /*Obj won't stop before collision -> Ego standing at collision*/
            (void)CDCalculateTTBStandstill(&EgoMovement, &AbsObjMovement,fEgoAccelAssumed, fTTC, pfTTB);
          }
          else
          {
            /*Obj stops before Ego(Assumed) -> set Obj to stop position ->calculated TTB is valid*/
          }
        }
        /* Ego can't move backwards => Ego standing before collision without braking*/
        else
        {
          *pfTTB = CD_TIME_MAX; 
        }
      }
      else
      {
        /* Calculate Stop time for Ego */
        (void)CDCalculateVehStopTime(EgoMovement.fVx, EgoMovement.fAx, &fTimeEgoStop);

        if (fTimeEgoStop > fTTC)
        {
          /*Obj and Ego won't stop before collision -> Ego standing at collision*/
          (void)CDCalculateTTBStandstill(&EgoMovement, &AbsObjMovement,fEgoAccelAssumed, fTTC, pfTTB);
        } 
        else
        {
          /* The Ego Vehicle stops before collision */
          *pfTTB = CD_TIME_MAX;
        }
      }  
    }
  }
  /* Ego standing at collision or TTC is invalid (==CD_TIME_MAX) */
  else
  {
    *pfTTB = CD_TIME_MAX;
  }

  /* return */
  return bReturn;
}

//!@}
#endif /* #if (ACDC_CFG_CD) */
