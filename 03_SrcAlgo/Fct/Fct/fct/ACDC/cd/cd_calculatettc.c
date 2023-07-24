/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculatettc.c

DESCRIPTION:               The calculation of TTCs for CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 09:56:22CEST $

VERSION:                   $Revision: 1.17 $
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
@defgroup cd_calculatettc Calculate TTC
@ingroup cd

@brief          The calculation of TTC, TTC2, TTC3, TTC4 is done in this module \n\n

@description    Provides functions for the calculation of the different derivations of the TTC: \n
                  @ref CD_f_GetTTC          \n
                  @ref CD_f_GetTTC2         \n
                  @ref CD_f_GetTTC3         \n
                  @ref CD_f_GetTTC4         \n
                  @ref CD_f_GetTTCBrakeJerk \n
                Additionally provides the main function of the TTC calculation to enable hypotheses 
                to recalculate the TTC under special circumstances: \n
                  @ref CDCalculateTTC
                \n

@{
*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static boolean CDCalculateTTCCore         ( CDMovement_t const * const pRelMovement,
                                            fTime_t            * const pfTTC );
static boolean CDCalculateTTC2            ( CDMovement_t const * const pEgoMovement,
                                            CDMovement_t const * const pObjMovement,
                                            fTime_t            * const pfTTC );

static boolean CDCalculateTTC3            ( CDMovement_t const * const pEgoMovement,
                                            CDMovement_t const * const pObjMovement,
                                            fTime_t            * const pfTTC );

static boolean CDCalculateTTC4            ( CDMovement_t const * const pEgoMovement,
                                            CDMovement_t const * const pObjMovement,
                                            fTime_t            * const pfTTC );

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
static boolean CDCalculateTTCBrakeJerk    ( ObjNumber_t                iObjectIndex,
                                            fTime_t                    fMinTime,
                                            fVelocity_t                fVelRed,
                                            fTime_t            * const pfTTCBrakeJerk );
static void CDCalculateBrakeJerkFactor    ( ObjNumber_t                iObjectIndex, 
                                            float32            * const pfTTCBrakeJerkFactor);
#endif /* #if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON) */

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTC                                                                                  */ /*!

  @brief                Returns the TTC of the considered object.

  @description          The TTC describes the time that remains until the ego vehicle collides with an object.
                        For the calculation of the TTC the following values are used:\n
                        - Ego Vehicle:
                           - Position
                           - Velocity
                           - Acceleration
                           .
                        - Object:
                          - Position
                          - Velocity
                          - Acceleration
                        .
                        The function checks if the TTC has been calculated for the current object,
                        if not, @ref CDCalculateTTC is called. Afterwards the TTC is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTC of the considered object. @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,.+...[

  @glob_in              @ref CD_s_GetEgoMov\n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com
 
  @testmethod           @ref TEST_CD_F_GETTTC_001 \n
                        @ref TEST_CD_F_GETTTC_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTC( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTC > CD_TTC_CHECK)
  {
    /*Get the movement properties of Ego and Obj*/
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const CDEgoMovement = CD_s_GetEgoMov();
    CDMovement_t const CDObjMovement = CD_s_GetObjMov(iObjectIndex,POS_CLOSEST_IN_X,KIN_ABS);

    (void)CDCalculateTTC( &CDEgoMovement, &CDObjMovement, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTC));
  }
  return pTTX->TTC;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTC2                                                                                  */ /*!

  @brief                Returns the TTC2 of the considered object.

  @description          The TTC2 describes the time that remains until the ego vehicle collides with an object.
                        For the calculation of the TTC2 the following values are used:\n
                        - Ego Vehicle:
                           - Position
                           - Velocity
                           - Acceleration
                           .
                        - Object:
                           - Position
                           - Velocity
                        . 
                        The function checks if the TTC2 has been calculated for the current object,
                        if not, @ref CDCalculateTTC2 is called. Afterwards the TTC2 is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTC2 of the considered object @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref CD_s_GetEgoMov\n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n


  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com
 
  @testmethod           @ref TEST_CD_F_GETTTC2_001 \n
                        @ref TEST_CD_F_GETTTC2_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTC2( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);
  
    if (pTTX->TTC2 > CD_TTC_CHECK)
  {
    /*Get the movement properties of Ego and Obj*/
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const CDEgoMovement = CD_s_GetEgoMov();
    CDMovement_t const CDObjMovement = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);

    (void)CDCalculateTTC2( &CDEgoMovement, &CDObjMovement, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTC2) );
  }
     return pTTX->TTC2;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTC3                                                                                  */ /*!

  @brief                Returns the TTC3 of the considered object.

  @description          The TTC3 describes the time that remains until the ego vehicle collides with an object.
                        For the calculation of the TTC3 the following values are used:\n
                        - Ego Vehicle:
                          - Position
                          - Velocity
                          .
                        - Object:
                          - Position
                          - Velocity
                        .
                        The function checks if the TTC3 has been calculated for the current object,
                        if not, @ref CDCalculateTTC3 is called. Afterwards the TTC3 is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTC3 of the considered object @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range[0,+...[

  @glob_in              @ref CD_s_GetEgoMov\n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n


  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTC3_001 \n
                        @ref TEST_CD_F_GETTTC3_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTC3( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTC3 > CD_TTC_CHECK)
  {
    /*Get the movement properties of Ego and Obj*/
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const CDEgoMovement = CD_s_GetEgoMov();
    CDMovement_t const CDObjMovement = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);

    (void)CDCalculateTTC3( &CDEgoMovement, &CDObjMovement, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTC3) );
  }
     return pTTX->TTC3;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTC4                                                                                  */ /*!

  @brief                Returns the TTC4 of the considered object.

  @description          The TTC4 describes the time that remains until the ego vehicle collides with an object.
                        For the calculation of the TTC4 the following values are used:\n
                        - Ego Vehicle:
                          - Position
                          - Velocity
                          .
                        - Object:
                          - Position
                        .
                        The function checks if the TTC4 has been calculated for the current object,
                        if not, @ref CDCalculateTTC4 is called. Afterwards the TTC4 is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : TTC4 of the considered object @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref CD_s_GetEgoMov\n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n


  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTC4_001 \n
                        @ref TEST_CD_F_GETTTC4_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTC4( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTC4 > CD_TTC_CHECK)
  {
    /*Get the movement properties of Ego and Obj*/
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const CDEgoMovement = CD_s_GetEgoMov();
    CDMovement_t const CDObjMovement = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);

    (void)CDCalculateTTC4(&CDEgoMovement, &CDObjMovement, &(ACDC_p_ModObjTTXData(iObjectIndex)->TTC4));
  }
  return pTTX->TTC4;
}

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
/*************************************************************************************************************************
  Functionname:         CD_f_GetTTCBrakeJerk                                                                         */ /*!

  @brief                Returns the TTC under consideration of a brake jerk.

  @description          Returns the TTC under consideration of a brake jerk. Therefore the duration and the velocity 
                        reduction during the brake jerk are read from the tables CD_BRAKE_JERK_TIME and CD_BRAKE_JERK_VEL.\n
                        The function checks if the TTCBrakeJerk has been calculated for the current object,
                        if not, @ref CDCalculateTTCBrakeJerk is called. Afterwards the TTCBrakeJerk is returned.\n
                        The function follows the common steps of a 'Get Function'(see diagram below).

                        \image html CommonGetFunction_activity.png
                        
  @return               float32 : TTCBrakeJerk of the considered object. @phys_unit [s] @range[0,\ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_BRAKE_JERK_TTC \n
                        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTCBRAKEJERK_001 \n
                        @ref TEST_CD_F_GETTTCBRAKEJERK_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTCBrakeJerk(ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->sBrakeJerk.fTTCBrakeJerk > CD_TTCBRAKEJERK_CHECK)
  {
    /*Get the movement properties the object*/
    /*PRQA S 1031 1*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const   CDObjMovement     = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);
    fTime_t              fBrakeJerkMinTime = CML_f_CalculatePolygonValue(CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES, CD_BRAKE_JERK_TIME, CDObjMovement.fX);
    fVelocity_t          fBrakeJerkVelRed  = CML_f_CalculatePolygonValue(CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES, CD_BRAKE_JERK_VEL , CDObjMovement.fX);

    (void)CDCalculateTTCBrakeJerk( iObjectIndex, fBrakeJerkMinTime, fBrakeJerkVelRed, &(ACDC_p_ModObjTTXData(iObjectIndex)->sBrakeJerk.fTTCBrakeJerk) );
  }
  return pTTX->sBrakeJerk.fTTCBrakeJerk;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTCBrakeJerkFactor                                                                         */ /*!

  @brief                returns the factor that is applied on the hypothesis probability on base of the difference  \n
                        between the TTC and the TTCBrakeJerk.

  @description          returns the factor that is applied on the hypothesis probability on base of the difference  \n
                        between the TTC and the TTCBrakeJerk. This factor is calculated by calling the function @ref CDCalculateBrakeJerkFactor \n
                        The function follows the common steps of a 'Get Function'(see diagram below).

                        \image html CommonGetFunction_activity.png
                        
  @return               float32 : fTTCBrakeJerkFactor of the considered object. @range [@ref BRAKE_JERK_FACTOR_VALUE_MAX_DELTA,1]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n


  @c_switch_part        None
  @c_switch_full        @ref CD_USE_BRAKE_JERK_TTC \n
                        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTCBRAKEJERKFACTOR_001 \n
                        @ref TEST_CD_F_GETTTCBRAKEJERKFACTOR_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTCBrakeJerkFactor(ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->sBrakeJerk.fTTCBrakeJerkFactor > CD_TTCBRAKEJERKFACTOR_CHECK)
  {
    CDCalculateBrakeJerkFactor( iObjectIndex, &(ACDC_p_ModObjTTXData(iObjectIndex)->sBrakeJerk.fTTCBrakeJerkFactor) );
  }
  
  return pTTX->sBrakeJerk.fTTCBrakeJerkFactor;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateBrakeJerkFactor                                                                   */ /*!

  @brief                Calculates a factor that is applied on the hypothesis probability on base of the difference  \n
                        between the TTC and the TTCBrakeJerk.

  @description          The factor is calculated based on x/(1+x) where x is the delta
                        between TTCBrakeJerk and TTC.
                        For more information about the TTC see @ref CD_f_GetTTC. \n
                        For more information about the TTCBrakeJerk see @ref CD_f_GetTTCBrakeJerk.
                        @startuml CDCalculateBrakeJerkFactor_activity.png
                        start
                          :Calculate Difference between 
                          TTCBrakeJerk and TTC;
                          if(Difference > Threshold)
                            :1}
                            :Calculate Factor;
                            note left: >see formula "Factor Calculation"
                            :Limit factor to maximum value;
                          else(No)
                            :2}
                            :Factor = 1;
                          endif
                          :Return Factor;
                        stop
                        @enduml

  @return               None

  @param[in]            iObjectIndex :         Index of the object for which the value shall be returned. @range [0,.+...[
  @param[in, out]       pfTTCBrakeJerkFactor : Pointer to the Probability factor for hypothesis probability. @range [@ref BRAKE_JERK_FACTOR_VALUE_MAX_DELTA,1]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_BRAKE_JERK_TTC \n
                        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Factor Calculation:**\n
  \f$ Fctr = Fctr_{Min}+\frac{((1-Fctr_{Min})\cdot\frac{1+Delta_{Max}}{Delta_{Max}}\cdot(Delta_{Min} + Delta_{Max}-Delta)}{(1+Delta_{Max} + Delta_{Min} - Delta} \f$

  @author               Christian Gutmann | christian.gutmann@conti-engineering.com

  @testmethod           @ref TEST_CDCALCULATEBRAKEJERKFACTOR_001 \n
                        @ref TEST_CDCALCULATEBRAKEJERKFACTOR_002

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDCalculateBrakeJerkFactor( ObjNumber_t         iObjectIndex, 
                                        float32     * const pfTTCBrakeJerkFactor )
{
  float32 fFactor = 1.0f;
  const fTime_t fDeltaTTC = CD_f_GetTTCBrakeJerk(iObjectIndex) - CD_f_GetTTC(iObjectIndex);
  const float32 fDivisor = ( (1.0f + BRAKE_JERK_FACTOR_MAX_TTC_DELTA + BRAKE_JERK_FACTOR_MIN_TTC_DELTA) - fDeltaTTC );

  /* check if TTC difference is higher than minimum value */
  if ( fDeltaTTC > BRAKE_JERK_FACTOR_MIN_TTC_DELTA)
  {
    /* check division by zero */
    if ( fABS(fDivisor) > C_F32_DELTA )
    {
      /* use function x/(1+x) to calculate factor */
      fFactor = BRAKE_JERK_FACTOR_VALUE_MAX_DELTA 
              + ( (1.0f - BRAKE_JERK_FACTOR_VALUE_MAX_DELTA) 
                * ( ( 1.0f + BRAKE_JERK_FACTOR_MAX_TTC_DELTA ) / BRAKE_JERK_FACTOR_MAX_TTC_DELTA ) 
                * ( ( (BRAKE_JERK_FACTOR_MAX_TTC_DELTA + BRAKE_JERK_FACTOR_MIN_TTC_DELTA) - fDeltaTTC ) / fDivisor ) 
                ); 

      /* limit float value between BRAKE_JERK_FACTOR_VALUE_MAX_DELTA and 1 */
      fFactor = MINMAX_FLOAT(BRAKE_JERK_FACTOR_VALUE_MAX_DELTA, 1.0f, fFactor);
    }
    else
    {
      fFactor = BRAKE_JERK_FACTOR_VALUE_MAX_DELTA;
    }
  }

  *pfTTCBrakeJerkFactor = fFactor;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTCBrakeJerk                                                                      */ /*!

  @brief                Calculates TTC assuming a brake jerk.

  @description          TTC is calculated considering a brake jerk with the current acceleration
                        to reduce the velocity by a certain value. The current acceleration is kept
                        at least for a minimum time. If object is not braking "normal" TTC is returned.
                        @startuml CDCalculateTTCBrakeJerk_activity.png
                        start
                        if(All Pointers are valid?) then (Yes)
                          #Orange: Calculate current **TTC**: 
                          <b>CDCalculateTTC</b> >
                          if(Current TTC is valid?\nAND Objects brake acceleration is below a brake jerk threshold?\nAND Objects is moving in the ego vehicles direction?) then (Yes)
                            :Calculate the **Brake Jerk Time**;
                            note left 
                            time the object has to brake with its current 
                            acceleration to reach the desired velocity
                            >see Formula **Brake Jerk Time**
                            end note 
                            if(Object does not stop before brake jerk ends?\nAND No collision before brake jerk ends?) then (Yes)
                               :1}
                               #Orange:Predict ego and object to the **Brake Jerk Time**:
                               <b>CDCalculateDistance</b>
                               <b>CDCalculateVelocity</b> >
                               :Set the objects longitudinal 
                               acceleration to 0;
                               #Orange:Calculate the **TTC_predicted** with the predicted situation:
                               <b>CDCalculateTTC</b> >
                               :**TTC_BrakeJerk** = **TTC_predicted** + **Brake Jerk Time**;
                            else(No)
                                :2}
                                :**TTC_BrakeJerk** = **TTC**;
                            endif
                          else (No)
                            :3}
                            :**TTC_BrakeJerk** = **TTC**;
                          endif
                        else(No)
                          :4}
                          :Return False;
                        endif

                        stop
                        @enduml

  @return               boolean bReturn: FALSE if pointers are invalid

  @param[in]            iObjectIndex :   Index of the object for which the value shall be returned. @range [0,.+...[
  @param[in]            fMinTime :       Minimum time to keep current acceleration. @phys_unit [s] @range [0,+...[
  @param[in]            fVelRed :        Reduction of current velocity during brake jerk. @phys_unit [m/s] @range ]-...,0[
  @param[in,out]        pfTTCBrakeJerk : Calculated TTC value with brake jerk. @phys_unit [s] @range [0,\ref CD_TIME_MAX]

  @glob_in              @ref CD_s_GetEgoMov \n
                        @ref CD_s_GetObjMov \n
                        @ref CD_f_GetTTC
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_BRAKE_JERK_TTC

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Brake Jerk Time:**\n
                        \f$T_{BrakeJerk} = \frac{V_{Reduction} }{A_{x,Obj}}\f$

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDCALCULATETTCBRAKEJERK_001 \n
                        @ref TEST_CDCALCULATETTCBRAKEJERK_002 \n
                        @ref TEST_CDCALCULATETTCBRAKEJERK_003 \n
                        @ref TEST_CDCALCULATETTCBRAKEJERK_004

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTCBrakeJerk( ObjNumber_t                iObjectIndex,
                                        fTime_t                    fMinTime,
                                        fVelocity_t                fVelRed,
                                        fTime_t            * const pfTTCBrakeJerk )
{
  /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  CDMovement_t const    CDEgoMovement    = CD_s_GetEgoMov();
  CDMovement_t const    CDAbsObjMovement = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);
  CDMovement_t          ObjMoveBrakeJerk;
  CDMovement_t          EgoMoveBrakeJerk;
  fTime_t               fBrakeJerkTime;
  boolean               bReturn           = b_TRUE;

  /* check pointers */
  if ( (pfTTCBrakeJerk != NULL) )
  {
    /* Get the current TTC */
    *pfTTCBrakeJerk = CD_f_GetTTC(iObjectIndex);

    /* - object is braking
       - object moves in same direction as ego */
    if ( (CDAbsObjMovement.fAx < ( -C_F32_DELTA )    ) &&
         (CDAbsObjMovement.fAx < MAX_BRAKE_JERK_ACCEL) &&
         (CDAbsObjMovement.fVx > 0.0f) )
    {
      /* there will be a collision with object */
      if ( (*pfTTCBrakeJerk+C_F32_DELTA) < CD_TIME_MAX )
      {
        /* calculate assumed time for brake jerk */
        const fTime_t fVelRedTime = fVelRed / CDAbsObjMovement.fAx;
        fBrakeJerkTime = MAX_FLOAT(fMinTime, fVelRedTime );
      
        /* - object does not stop before brake jerk ends 
           - object does not collide with ego before brake jerk ends */
        if ( (CDCalculateVelocity(CDAbsObjMovement.fVx, CDAbsObjMovement.fAx, fBrakeJerkTime) > 0.0f) &&
             (fBrakeJerkTime < *pfTTCBrakeJerk) )
        {
          /* calculate ego movement after brake jerk */
          EgoMoveBrakeJerk.fX  = CDCalculateDistance(CDEgoMovement.fX, CDEgoMovement.fVx, CDEgoMovement.fAx, fBrakeJerkTime);
          EgoMoveBrakeJerk.fY  = CDEgoMovement.fY;
          EgoMoveBrakeJerk.fVx = CDCalculateVelocity(CDEgoMovement.fVx, CDEgoMovement.fAx, fBrakeJerkTime);
          EgoMoveBrakeJerk.fVy = CDEgoMovement.fVy;
          EgoMoveBrakeJerk.fAx = CDEgoMovement.fAx;
          EgoMoveBrakeJerk.fAy = CDEgoMovement.fAy;

          /* calculate object movement after brake jerk */
          ObjMoveBrakeJerk.fX  = CDCalculateDistance(CDAbsObjMovement.fX, CDAbsObjMovement.fVx, CDAbsObjMovement.fAx, fBrakeJerkTime);
          ObjMoveBrakeJerk.fY  = CDAbsObjMovement.fY;
          ObjMoveBrakeJerk.fVx = CDCalculateVelocity(CDAbsObjMovement.fVx, CDAbsObjMovement.fAx, fBrakeJerkTime);
          ObjMoveBrakeJerk.fVy = CDAbsObjMovement.fVy;
          ObjMoveBrakeJerk.fAx = 0.0f;
          ObjMoveBrakeJerk.fAy = CDAbsObjMovement.fAy;

          /* calculate TTC starting after brake jerk */
          (void)CDCalculateTTC(&EgoMoveBrakeJerk, &ObjMoveBrakeJerk, pfTTCBrakeJerk );

          /* add brake jerk time to TTC after brake jerk */
          *pfTTCBrakeJerk += fBrakeJerkTime;

          /* limit TTC for brake jerk */
          *pfTTCBrakeJerk = MIN_FLOAT(*pfTTCBrakeJerk, CD_TIME_MAX);
        }
      }
    }
  }
  /* pointer error */
  else
  {
    bReturn = b_FALSE;
  }

  return bReturn;
}
#endif /* CD_USE_BRAKE_JERK_TTC */

/*************************************************************************************************************************
  Functionname:         CDCalculateTTCCore                                                                           */ /*!

  @brief                Calculates the time until two objects collide (=Time To Collision).

  @description          For the calculation of the TTC a stopping of one of the objects at velocity 0 is not considered.
                        The Equation of motion is solved by the formula \ref SFL_v_SolveQuadrEquation,
                        The calculation follows the subsequent steps:
                        @startuml CDCalculateTTCCore_activity.png
                        start
                          if (Vehicles have already collided?) then (Yes)
                            :1}
                            :**TTC** = 0\nSet Error flag;
                          else(No)
                            :2}
                            #Orange:Solve equation of motion on 
                            base of the relative movement
                            <b>SFL_v_SolveQuadrEquation</b> >
                            note right: >see formula\n"Equation of motion"
                            #Orange:**TTC** = Minimum positive solution
                            <b>SFL_f_SelectMinValue</b> >
                            if(Check TTC) then (Out of limits)
                              :2}
                              :**TTC** = Default value;
                            else (Inside Limits)
                              :3}
                            endif
                          endif
                        stop
                        @enduml

  @return               boolean : False if collision lies in the past.

  @param[in]            pRelMovement : Relative movement of the objects.
  @param[in,out]        pfTTC :         Calculated TTC value. @phys_unit [s] @range [0, @ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Equation of motion:** \n
                        \f$X_{Obj} - X_{Ego} + (V_{x,Obj} - V_{x,Ego}) \cdot t + 0.5 \cdot (A_{x,Obj} - A_{x,Ego}) \cdot t^2\f$

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDCALCULATETTCCORE_001 \n
                        @ref TEST_CDCALCULATETTCCORE_002

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTCCore( CDMovement_t const * const pRelMovement,
                                   fTime_t            * const pfTTC        )
{
  /* local variable(s) */
  boolean bReturn = b_TRUE;
  SFLPolynomialSolutions_t fTimeSol;

  /* set default value for TTC */
  *pfTTC      = CD_TIME_MAX;

  /* vehicles have already collided, this is not realistic */
  if (pRelMovement->fX < 0.0f)
  {
    *pfTTC   = 0.0f;
    bReturn  = b_FALSE;
  }
  /* calculate TTC values and select minimum positive value */
  else
  {
    /* Solve equation of motion: 1/2*a*t^2+v*t+s=0 */
    /*PRQA S 3121 1*/
    SFL_v_SolveQuadrEquation(0.5f * pRelMovement->fAx, pRelMovement->fVx, pRelMovement->fX, &fTimeSol);

    *pfTTC = SFL_f_SelectMinValue(fTimeSol.afSolutions, fTimeSol.uNofSolutions, CD_TIME_MAX, b_TRUE);
    /* limit TTC */
    if(    (*pfTTC <  0.f        )
        || (*pfTTC  > CD_TIME_MAX) )
    {
      *pfTTC = CD_TIME_MAX;
    }
  }
  /* return */
  return bReturn;
}
/*************************************************************************************************************************
  Functionname:         CDCalculateTTC                                                                               */ /*!

  @brief                Calculates the time until two objects collide (Time To Collision).

  @description          Calculates the Time To Collision (TTC) under the assumption that the current acceleration is
                        kept by both objects. Also it is assumed that an object stops when it reaches x velocity = 0. \n
                        Therefore the function \ref CDCalculateTTCCore is used to execute the core TTC calculation
                        for different situations: \n
                          - The Ego vehicle stops before a collision: \n
                            In this case a collision can only take place if the object is oncoming. \n
                            If this is the case, the TTC calculation can be simplified: As the ego vehicle stops 
                            before the collision, the stopping position will be the collision point. Therefore \n
                            this stopping position can be used for the TTC calculation.
                          - The Object stops before a collision: \n
                            As the object stops before the collision, the calculation can be simplified by assuming 
                            that the object is already standing at its stopping position.
                          - None of the two stops:
                            The TTC is calculated under consideration of all current object and ego kinematics.
                          .
                        Processing steps:
                        @startuml CDCalculateTTC_activity.png
                        start
                          #Orange:Calculate TTC based on 
                          current kinematics (=TTC_Curr)
                          <b>CDCalculateTTCCore</b> >
                          #Orange:Calculate stop time of 
                          object and ego vehicle
                          <b>CDCalculateVehStopTime </b> >
                          note right: Stop Time = Time at which\nan object stops if it keeps\nthe current kinematics
                          if(Ego vehicle stops before TTC_Curr\nAND Ego vehicle stops before object?) then (Yes)
                            if(Object is oncoming?) then (Yes)
                              :Set ego acceleration and velocity to zero and 
                              ego position to ego stopping position;
                              #Orange:Recalculate TTC (=TTC_EgoStop)
                              <b>CDCalculateTTCCore</b> >
                              if (Object stops before TTC_EgoStop?) then (Yes)
                                :1}
                                :No collision possible, 
                                **TTC** = default;
                              else(No)
                                :2}
                                :**TTC** = TTC_EgoStop;
                              endif
                            else(No)
                              :3}
                              :No collision possible, 
                               **TTC** = default;
                            endif
                          elseif(Object stops before TTC_Curr\nAND Object stops before ego vehicle?) then (Yes)
                            :Set object acceleration and velocity to zero and 
                            object position to object stopping position;
                            #Orange:Recalculate TTC (=TTC_ObjStop)
                            <b>CDCalculateTTCCore</b> >
                            if(Ego stops before TTC_ObjStop?) then (Yes)
                              :4}
                              :No collision possible, 
                               **TTC** = default;
                            else(No)
                              :5}
                              :**TTC** = **TTC_ObjStop**;
                            endif
                          else(No)
                            :6}
                            :**TTC** = **TTC_Curr**;
                          endif
                        stop
                        @enduml

  @return               boolean : Always true

  @param[in]            pEgoMovement :  Movement information of the ego vehicle.
  @param[in]            pObjMovement :  Movement information of the object.
  @param[in,out]        pfTTC :         Calculated time to collision. @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Christian Gutmann

  @testmethod           @ref TEST_CDCALCULATETTC_001 \n
                        @ref TEST_CDCALCULATETTC_002 \n
                        @ref TEST_CDCALCULATETTC_003 \n
                        @ref TEST_CDCALCULATETTC_004 \n
                        @ref TEST_CDCALCULATETTC_005 \n
                        @ref TEST_CDCALCULATETTC_006

  @traceability         Design Decision

*************************************************************************************************************************/
boolean CDCalculateTTC( CDMovement_t const * const pEgoMovement,
                        CDMovement_t const * const pObjMovement,
                        fTime_t            * const pfTTC )
{
  /* local variable(s) */
  boolean bReturn = b_TRUE;
  CDMovement_t RelMovement;
  fTime_t fTimeEgoStop;
  fTime_t fTimeObjStop;

  /* calculate relative movement of ego vehicle and object considering safety distance */
  RelMovement.fX  = pObjMovement->fX  - pEgoMovement->fX ;
  RelMovement.fVx = pObjMovement->fVx - pEgoMovement->fVx;
  RelMovement.fAx = pObjMovement->fAx - pEgoMovement->fAx;
  RelMovement.fY  = pObjMovement->fY  - pEgoMovement->fY ;
  RelMovement.fVy = pObjMovement->fVy - pEgoMovement->fVy;
  RelMovement.fAy = pObjMovement->fAy - pEgoMovement->fAy;
  /* calculate TTC */
  (void)CDCalculateTTCCore(&RelMovement, pfTTC);

  /* calculate stop time for vehicles */
  (void)CDCalculateVehStopTime(pEgoMovement->fVx, pEgoMovement->fAx, &fTimeEgoStop);
  (void)CDCalculateVehStopTime(pObjMovement->fVx, pObjMovement->fAx, &fTimeObjStop);

  /* ego vehicle stops before object and collision */
  if ( (fTimeEgoStop < fTimeObjStop) &&
       (fTimeEgoStop < *pfTTC) )
  {
    /* if v_obj < 0 - oncoming object */
    if (pObjMovement->fVx < 0.0f)
    {
      /* set relative movement as if ego has already been standing at final position */
      RelMovement.fX  = pObjMovement->fX - CDCalculateDistance(pEgoMovement->fX, pEgoMovement->fVx, pEgoMovement->fAx, fTimeEgoStop);
      RelMovement.fVx = pObjMovement->fVx;
      RelMovement.fAx = pObjMovement->fAx;

      (void)CDCalculateTTCCore(&RelMovement, pfTTC);

      /* object stops before collision with standing ego vehicle */
      if (fTimeObjStop < *pfTTC)
      {
        *pfTTC = CD_TIME_MAX;
      }
    }
    else
    /* object is moving same direction */
    {
      *pfTTC = CD_TIME_MAX;
    }
  }
  /* object stops before ego vehicle and collision */
  else if ( (fTimeObjStop < fTimeEgoStop) &&
            (fTimeObjStop < *pfTTC) )
  {
    /* set relative movement as if object has already been standing at final position */
    RelMovement.fX  = CDCalculateDistance(pObjMovement->fX, pObjMovement->fVx, pObjMovement->fAx, fTimeObjStop) - pEgoMovement->fX;
    RelMovement.fVx = -pEgoMovement->fVx;
    RelMovement.fAx = -pEgoMovement->fAx;

    (void)CDCalculateTTCCore(&RelMovement, pfTTC );

    /* ego vehicle stops before collision with standing object */
    if (fTimeEgoStop < *pfTTC)
    {
      *pfTTC = CD_TIME_MAX;
    }
  }
  else
  {
    /* collision happens first so calculated time is correct */
  }

  /* return */
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTC2                                                                              */ /*!

  @brief                Calculates the time until two objects collide (Time To Collision) under consideration 
                        of all kinematic attributes, except the objects acceleration.

  @description          Sets the objects acceleration to 0 and calls the function \ref CDCalculateTTC.
                        @startuml CDCalculateTTC2_activity.png
                        start
                          :Set object acceleration
                          to 0;
                          #Orange:Calculate Time to collision
                          <b>CDCalculateTTC</b> >
                        stop
                        @enduml

  @return               boolean : True if TTC calculation succeeded.

  @param[in]            pEgoMovement : Movement information of the ego vehicle.
  @param[in]            pObjMovement : Movement information of the object.
  @param[in,out]        pfTTC :        Calculated time to collision. @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               

  @testmethod           @ref TEST_CDCALCULATETTC2_001

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTC2( CDMovement_t  const * const pEgoMovement,
                                CDMovement_t  const * const pObjMovement,
                                fTime_t             * const pfTTC        )
{
  /* local variable(s) */
  boolean      bReturn = b_TRUE;
  CDMovement_t ObjMovementVariant;

  /* object movement without acceleration */
  ObjMovementVariant     = *pObjMovement;
  ObjMovementVariant.fAx = 0.0f;

  bReturn = CDCalculateTTC( pEgoMovement, &ObjMovementVariant, pfTTC );

  /* return */
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTC3                                                                              */ /*!

  @brief                Calculates the time until two objects collide (Time To Collision) under consideration 
                        of positions and velocities. Accelerations of ego vehicle and object are ignored.

  @description          Sets the objects and ego vehicles acceleration to 0 and calls the function \ref CDCalculateTTC.
                        @startuml CDCalculateTTC3_activity.png
                        start
                          :Set object acceleration to 0;
                          :Set ego vehicle acceleration to 0;
                          #Orange:Calculate Time to collision
                          <b>CDCalculateTTC</b> >
                        stop
                        @enduml

  @return               boolean : True if TTC calculation succeeded.

  @param[in]            pEgoMovement : Movement information of the ego vehicle.
  @param[in]            pObjMovement : Movement information of the object.
  @param[in,out]        pfTTC :        Calculated time to collision. @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               

  @testmethod           @ref TEST_CDCALCULATETTC3_001

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTC3( CDMovement_t const * const pEgoMovement,
                                CDMovement_t const * const pObjMovement,
                                fTime_t            * const pfTTC )
{
  /* local variable(s) */
  boolean      bReturn = b_TRUE;
  CDMovement_t EgoMovementVariant;
  CDMovement_t ObjMovementVariant;

  /* ego and object movement without acceleration */
  EgoMovementVariant     = *pEgoMovement;
  EgoMovementVariant.fAx = 0.0f;
  ObjMovementVariant     = *pObjMovement;
  ObjMovementVariant.fAx = 0.0f;
  
  bReturn = CDCalculateTTC( &EgoMovementVariant, &ObjMovementVariant, pfTTC );

  /* return */
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateTTC4                                                                              */ /*!

  @brief                Calculates the time until two objects collide (Time To Collision) under consideration 
                        of ego positions and velocity and object position. Acceleration of the ego vehicle and \n
                        velocity and acceleration of the object are ignored.

  @description          Sets the ego vehicles acceleration and the objects acceleration and velocity to 0 and 
                        calls the function \ref CDCalculateTTC.
                        @startuml CDCalculateTTC4_activity.png
                        start
                          :Set object acceleration to 0;
                          :Set object velocity to 0;
                          :Set ego vehicle acceleration to 0;
                          #Orange:Calculate Time to collision
                          <b>CDCalculateTTC</b> >
                        stop
                        @enduml

  @return               boolean : True if TTC calculation succeeded.

  @param[in]            pEgoMovement : Movement information of the ego vehicle.
  @param[in]            pObjMovement : Movement information of the object.
  @param[in,out]        pfTTC :        Calculated time to collision. @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               

  @testmethod           @ref TEST_CDCALCULATETTC4_001

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCalculateTTC4( CDMovement_t const * const pEgoMovement,
                                CDMovement_t const * const pObjMovement,
                                fTime_t            * const pfTTC )
{
  /* local variable(s) */
  boolean      bReturn = b_TRUE;
  CDMovement_t EgoMovementVariant;
  CDMovement_t ObjMovementVariant;

  /* ego and object movement without acceleration and object movement without velocity */
  EgoMovementVariant     = *pEgoMovement;
  EgoMovementVariant.fAx = 0.0f;
  ObjMovementVariant     = *pObjMovement;
  ObjMovementVariant.fVx = 0.0f;
  ObjMovementVariant.fAx = 0.0f;

  bReturn = CDCalculateTTC( &EgoMovementVariant, &ObjMovementVariant, pfTTC );

  /* return */
  return bReturn;
}

//!@}
#endif /* #if (ACDC_CFG_CD) */
