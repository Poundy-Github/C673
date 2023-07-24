/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculatetts.c

DESCRIPTION:               The calculation of TTSs for CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 09:58:40CEST $

VERSION:                   $Revision: 1.23 $
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
@defgroup cd_calculatetts Calculate TTS
@ingroup cd

@brief          The calculation of TTSPre, TTSPreLeft, TTSPreRight, TTSAcute, TTSAcuteLeft and TTSAcuteRight is done in this module \n\n

@description    Provides functions for the calculation of the different derivations of the TTS: \n
                  @ref CD_f_GetTTSPreLeft     \n
                  @ref CD_f_GetTTSPreRight    \n
                  @ref CD_f_GetTTSPre         \n
                  @ref CD_f_GetTTSAcuteLeft   \n
                  @ref CD_f_GetTTSAcuteRight  \n
                  @ref CD_f_GetTTSAcute
@{
*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static float32 CD_f_CalculateTTSDynCore( ObjNumber_t    const         iObjectIndex,
                                         float32        const         fEgoAccelAssumed,
                                         float32                      fLateralMinOffset,
                                         float32        const         fDistanceToPass,
                                         float32        const         fTime,
                                         boolean        const         bUseSteeringChange);

static float32 CD_f_CalculateTTS(ObjNumber_t const iObjectIndex, boolean const bRight, boolean const bAcute);

static float32 CDCalcALat(float32 const fNecLatOffset, float32 fEgoVel);


#if(CD_USE_DISTANCE_TO_PASS)
static float32 CD_f_CalculateDistYWhilePass(CDMovement_t const * const ObjMovement,
                                            CDMovement_t const * const predObjMovement,
                                            CDMovement_t const * const predEgoMovement,
                                            float32      const         fEgoAccelAssumed,
                                            float32      const         fDistanceToPass);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTSPreLeft                                                                           */ /*!

  @brief                Return the time that remains for the driver to react with a moderate lateral acceleration to the 
                        left to avoid a collision.

  @description          The function checks if the TTSPreLeft has been calculated for the current object,
                        if not, @ref CD_f_CalculateTTS is called. with the parameters **bRight = FALSE** and **bAcute = FALSE**
                        The function follows the common steps of a get function:
                        @image html CommonGetFunction_activity.png

  @return               float32 : TTSPreLeft of the considered object. @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_F_GETTTSPRELEFT_001 \n
                        @ref TEST_CD_F_GETTTSPRELEFT_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTSPreLeft( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTSPreLeft > CD_TTSPRE_CHECK)
  {
    ACDC_p_ModObjTTXData(iObjectIndex)->TTSPreLeft = CD_f_CalculateTTS(iObjectIndex, b_FALSE, b_FALSE);
  }
  return pTTX->TTSPreLeft;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTSPreRight                                                                           */ /*!

  @brief                Return the time that remains for the driver to react with a moderate lateral acceleration to the 
                        right to avoid a collision.

  @description          The function checks if the TTSPreRight has been calculated for the current object,
                        if not, @ref CD_f_CalculateTTS is called. with the parameters **bRight = TRUE** and **bAcute = FALSE**
                        The function follows the common steps of a get function:
                        @image html CommonGetFunction_activity.png

  @return               float32 : TTSPreRight of the considered object @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0, EM_N_OBJECTS]

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_F_GETTTSPRERIGHT_001 \n
                        @ref TEST_CD_F_GETTTSPRERIGHT_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTSPreRight( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTSPreRight > CD_TTSPRE_CHECK)
  {
    ACDC_p_ModObjTTXData(iObjectIndex)->TTSPreRight = CD_f_CalculateTTS(iObjectIndex, b_TRUE, b_FALSE);
  }
  return pTTX->TTSPreRight;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTSPre                                                                              */ /*!

  @brief                Return the time that remains for the driver to react with a moderate lateral acceleration
                        to avoid a collision.

  @description          The function checks if the TTSPre has been calculated for the current object,
                        if not, @ref CD_f_GetTTSPreLeft and @ref CD_f_GetTTSPreRight are called. 
                        Of the two resulting times, the higher one is set as TTSPre.\n
                        After the calculation the TTSPre is returned. The functions processing steps 
                        deviate slightly from the common steps of a 'Get Function' (see diagram below).
                        @startuml CD_f_GetTTSPre_activity.png 
                        start
                         if (TTS_(Pre) has been calculated before?) then (Yes)
                          :1}
                         else(No)
                          :2}
                          #Orange:Calculate TTS_(Pre,left)
                          (left evasion movement)
                          <b>CD_f_GetTTSPreLeft</b> >
                          #Orange:Calculate TTS_(Pre,right)
                          (right evasion movement)
                          <b>CD_f_GetTTSPreRight</b> >
                          :Set maximum of TTS_(Pre,left) and
                          TTS_(Pre,right) as TTS_(Pre);
                         endif
                         :Return TTS_(Pre);
                        stop
                        @enduml

  @return               float32: TTSPre of the considered object @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0, EM_N_OBJECTS]

  @glob_in              @ref CD_f_GetTTSPreLeft \n
                        @ref CD_f_GetTTSPreRight\n
                        @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTSPRE_001 \n
                        @ref TEST_CD_F_GETTTSPRE_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTSPre( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTSPre > CD_TTSPRE_CHECK)
  {
    /*Get the TTSpre left and right*/
    float32 fTTSPreLeft       = CD_f_GetTTSPreLeft(iObjectIndex);
    float32 fTTSPreRight      = CD_f_GetTTSPreRight(iObjectIndex);

    /*Select the direction, in which the Ego has more time to steer to avoid collision*/
    ACDC_p_ModObjTTXData(iObjectIndex)->TTSPre = MAX_FLOAT(fTTSPreLeft, fTTSPreRight);
  }
  return pTTX->TTSPre;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTSAcuteLeft                                                                        */ /*!

  @brief                Return the time that remains for the driver to react with a high lateral acceleration to the 
                        left to avoid a collision.

  @description          The function checks if the TTSAcuteLeft has been calculated for the current object,
                        if not, @ref CD_f_CalculateTTS is called with the parameters **bRight = FALSE** and **bAcute = TRUE**
                        The function follows the common steps of a get function:
                        @image html CommonGetFunction_activity.png

  @return               float32 : TTSAcuteLeft of the considered object. @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0, EM_N_OBJECTS]

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_F_GETTTSACUTELEFT_001 \n
                        @ref TEST_CD_F_GETTTSACUTELEFT_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTSAcuteLeft( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);
  
  if (pTTX->TTSAcuteLeft > CD_TTSACUTE_CHECK)
  {
    ACDC_p_ModObjTTXData(iObjectIndex)->TTSAcuteLeft = CD_f_CalculateTTS(iObjectIndex, b_FALSE, b_TRUE);
  }
  return pTTX->TTSAcuteLeft;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTSAcuteRight                                                                           */ /*!

  @brief                Return the time that remains for the driver to react with a high lateral acceleration to the 
                        right to avoid a collision.

  @description          The function checks if the TTSAcuteRight has been calculated for the current object,
                        if not, @ref CD_f_CalculateTTS is called. with the parameters **bRight = TRUE** and **bAcute = TRUE**
                        The function follows the common steps of a get function:
                        @image html CommonGetFunction_activity.png

  @return               float32 : TTSAcuteRight of the considered object. @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0, EM_N_OBJECTS]

  @glob_in              @ref ACDC_p_GetObjTTXData
  @glob_out             @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  
  @testmethod           @ref TEST_CD_F_GETTTSACUTERIGHT_001 \n
                        @ref TEST_CD_F_GETTTSACUTERIGHT_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTSAcuteRight( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTSAcuteRight > CD_TTSACUTE_CHECK)
  {
    ACDC_p_ModObjTTXData(iObjectIndex)->TTSAcuteRight = CD_f_CalculateTTS(iObjectIndex, b_TRUE, b_TRUE);
  }
  return pTTX->TTSAcuteRight;
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetTTSAcute                                                                              */ /*!

  @brief                Return the time that remains for the driver to react with a high lateral acceleration
                        to avoid a collision.

  @description          The function checks if the TTSAcute has been calculated for the current object,
                        if not, @ref CD_f_GetTTSAcuteLeft and @ref CD_f_GetTTSAcuteRight are called. \n
                        Of the two resulting times, the higher one is set as TTSAcute.
                        After the calculation the TTSAcute is returned. The functions processing steps \n
                        deviate slightly from the common steps of a 'Get Function' (see diagram below).
                        @startuml CD_f_GetTTSAcute_activity.png 
                        start
                         if (TTSAcute has been calculated before?) then (Yes)
                          :1}
                         else(No)
                          :2}
                          #Orange:Calculate TTS_(Acute,Right)
                          (Right evasion movement)
                          <b>CD_f_GetTTSAcuteRight</b> >
                          #Orange:Calculate TTS_(Acute,Left)
                          (Left evasion movement)
                          <b>CD_f_GetTTSAcuteLeft</b> >
                          :Set maximum of TTS_(Acute,left) and
                          TTS_(Acute,right) as TTS_(Acute);
                         endif
                         :Return TTS_(Acute);
                        stop
                        @enduml

  @return               float32 : TTSAcute of the considered object. @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0, EM_N_OBJECTS]

  @glob_in              @ref CD_f_GetTTSAcuteLeft \n
                        @ref CD_f_GetTTSAcuteRight\n
                        @ref ACDC_p_GetObjTTXData\n
  @glob_out             @ref ACDC_p_ModObjTTXData\n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETTTSACUTE_001 \n
                        @ref TEST_CD_F_GETTTSACUTE_002

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CD_f_GetTTSAcute( ObjNumber_t const iObjectIndex)
{
  CDObj_TTX_t const * const pTTX = ACDC_p_GetObjTTXData(iObjectIndex);

  if (pTTX->TTSAcute > CD_TTSACUTE_CHECK)
  {
    float32 fTTSAcuteLeft        = CD_f_GetTTSAcuteLeft(iObjectIndex);
    float32 fTTSAcuteRight       = CD_f_GetTTSAcuteRight(iObjectIndex);

    ACDC_p_ModObjTTXData(iObjectIndex)->TTSAcute = MAX_FLOAT(fTTSAcuteLeft, fTTSAcuteRight);
  }
  return pTTX->TTSAcute;
}

/*************************************************************************************************************************
  Functionname:         CD_f_CalculateTTS                                                                            */ /*!

  @brief                Calculates the time that remains for the ego vehicle to avoid a collision by steering (TTS) with a 
                        certain lateral acceleration to a certain side.

  @description          Calculates the TTS for a side and a lateral acceleration. By using the two input flags bRight and bAcute, 
                        the function can be configured for the following situations:
                        |bRight|bAcute|Meaning                                                                           |Return Value    |
                        |:-----|:-----|:---------------------------------------------------------------------------------|:---------------|
                        |TRUE  | TRUE | The ego vehicle tries to evade to the right with a high lateral acceleration.    |TTS_Acute_Right |
                        |TRUE  | FALSE| The ego vehicle tries to evade to the right with a moderate lateral acceleration.|TTS_Pre_Right   |
                        |FALSE | TRUE | The ego vehicle tries to evade to the left with a high lateral acceleration.     |TTS_Acute_Left  |
                        |FALSE | FALSE| The ego vehicle tries to evade to the left with a moderate lateral acceleration. |TTS_Pre_Left    |
                        .
                        @startuml CD_f_CalculateTTS_activity.png
                        start
                          if(TTC is below max value?) then (Yes)
                            :Calculate Distance To Pass;
                            note left:>see **Formula Distance To Pass**
                            :Calculate required lateral offset;
                            note left:>see **Formula Min Lateral Offset**

                            if(bAcute) Then (TRUE)
                              :1}
                              :Read the possible lateral acceleration 
                              on base of the ego velocity from the 
                              table CD_EMERGENCY_EGO_ACCEL_Y;
                              :Set the flag for **Use steering change** to FALSE;
                            else (FALSE)
                              :2}
                              :Calculate the Required Evasion Distance;
                              #Orange:Predict the objects position 
                              and calculate the possible 
                              lateral acceleration:
                              <b>CDCalcALat</b> >
                              :Set the flag for Use steering change to **TRUE**;
                            endif
                            if(bRight) Then (FALSE)
                              :3}
                              :Invert the sign of the Min Lateral Offset 
                              and the assumed ego acceleration if the 
                              calculation is done for the left side;
                            else (TRUE)
                              :4}
                            endif
                            #Orange:Calculate the **TTS**:
                            <b>CD_f_CalculateTTSDynCore</b> >
                          else (No)
                            :5}
                            :**TTS** = MAX;
                          endif
                        stop
                        @enduml

  @return               float32: calculated TTS. @phys_unit [s] @range [0, @ref CD_TIME_MAX]

  @param[in]            iObjectIndex :  Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in]            bRight :        Flag indicating for which side the TTS shall be calculated (TRUE = RIGHT, FALSE = LEFT)
  @param[in]            bAcute :        Flag indicating if the TTS shall be calculated for a high (acute) or a moderate (pre) lateral acceleration.
                                        (TRUE = ACUTE, FALSE = PRE)

  @glob_in              @ref ACDC_p_GetCDParameters\n
                        @ref CD_s_GetEgoMov\n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetEgoGeometry\n
                        @ref ACDC_p_GetObjGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n

  @pre                  Pointers returned by @ref GetCDParameters and @ref GetCDInputData have been set.
  @post                 None

  @InOutCorrelation     
                        - **Formula Distance To Pass:**\n
                          \f$D_{ToPass} = D_{LongNecSafety} + Length_{Ego} + Length_{Object}\f$
                        - **Formula Min Lateral Offset:**\n
                          \f$LateralOffsetMin = \frac{Width_{Ego} + Width_{Object}}{2}\f$

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_F_GETTTSPRERIGHT_001 \n
                        @ref TEST_CD_F_GETTTSPRERIGHT_002 \n
                        @ref TEST_CD_F_GETTTSPRELEFT_001 \n
                        @ref TEST_CD_F_GETTTSPRELEFT_002 \n
                        @ref TEST_CD_F_GETTTSACUTELEFT_001 \n
                        @ref TEST_CD_F_GETTTSACUTELEFT_002 \n
                        @ref TEST_CD_F_GETTTSACUTERIGHT_001 \n
                        @ref TEST_CD_F_GETTTSACUTERIGHT_002

  @traceability         Design Decision

*************************************************************************************************************************/
static float32 CD_f_CalculateTTS(ObjNumber_t const iObjectIndex, 
                                 boolean     const bRight, 
                                 boolean     const bAcute)
{
  float32 const fTTC = CD_f_GetTTC(iObjectIndex);
  float32       fTTS = CD_TIME_MAX;

  /* Check if a collision is avoided with the current kinematics */
  if(fTTC < CD_TIME_MAX)
  {
    /* Get necessary pointers and global variables */
    CDParameters_t const * const pParameters    = ACDC_p_GetCDParameters();
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t   const         CDEgoMovement  = CD_s_GetEgoMov();
    CDMovement_t   const         CDObjMovement  = CD_s_GetObjMov(iObjectIndex, POS_GEN_OBJECT, KIN_ABS);
    ACDCGeometry_t const * const pEgoGeometry   = ACDC_p_GetEgoGeometry();
    ACDCGeometry_t const * const fObjGeometry   = ACDC_p_GetObjGeometry(iObjectIndex);

    /* PRQA S 3121 4 *//* constants */
    /* calculate longitudinal distance to pass the object and the wanted lateral offset */
    float32        const         fDistanceToPass      = pParameters->AdjSafeDistance.fLongNecRemainDist + pEgoGeometry->fLength + fObjGeometry->fLength;
    float32                      fLateralOffsetMin    = (0.5f * pEgoGeometry->fWidth) + ( 0.5f * fObjGeometry->fWidth); /* Initially positive for the right side */
    float32                      fEgoAccelTTS         = 0.f;
    boolean                      bUseSteeringChange   = b_FALSE;

    if(bAcute == b_TRUE)
    {
      /* If the TTS Acute shall be calculated, read the assumed acceleration from a table. Initially negative for the right side. */
      fEgoAccelTTS        = -CML_f_CalculatePolygonValue(CD_NUMBER_OF_EMERGENCY_EGO_ACCEL_Y_VALUES, CD_EMERGENCY_EGO_ACCEL_Y, CDEgoMovement.fVx);
      bUseSteeringChange  = b_FALSE;
    }
    else
    {
      float32 const fObjPosY_Predicted   = CDObjMovement.fY + (( (CDObjMovement.fVy - CDEgoMovement.fVy) * (fTTC) ) - ( 0.5f * CDEgoMovement.fAy * SQR(fTTC) ));
      float32       fRequiredEvasionDist = 0.f;

      /* Calculate the required evasion distance */
      if(bRight == b_TRUE)
      {
        /* For the right side: The ego vehicle passes the object at its right side -> offset has to be negative and the result is maximum 0*/
        fRequiredEvasionDist  = MIN_FLOAT(fObjPosY_Predicted - fLateralOffsetMin, 0.f);
      }
      else
      {
        /* For the left side: The ego vehicle passes the object at its left side -> offset has to be positive and the result is minimum 0*/
        fRequiredEvasionDist  = MAX_FLOAT(fObjPosY_Predicted + fLateralOffsetMin, 0.f);
      }

      /* If the TTS Pre shall be calculated, use the function CDCalcALat to determine the assumed ego acceleration. Initially negative for the right side. */
      fEgoAccelTTS        = -CDCalcALat(fRequiredEvasionDist, CDEgoMovement.fVx);
      bUseSteeringChange  = b_TRUE;
    }

    if(bRight == b_FALSE)
    {
      /* Invert the sign of the required lateral offset and the assumed acceleration if the TTS shall be calculated for the left side.
      (Assumed is usually positive for left and negative for right, fLateralOffsetMin is negative for left and positive for right) */
      fEgoAccelTTS        *= -1.f;
      fLateralOffsetMin   *= -1.f;
    }

    /* Calculate the TTS */
    fTTS  =  CD_f_CalculateTTSDynCore(iObjectIndex, fEgoAccelTTS, fLateralOffsetMin, fDistanceToPass, fTTC, bUseSteeringChange);
  }

  return fTTS;
}

#if(CD_USE_DISTANCE_TO_PASS)
/*************************************************************************************************************************
  Functionname:         CD_f_CalculateDistYWhilePass                                                                  */ /*!

  @brief                Calculates the lateral distance that is covered by the object while the ego vehicle passes it.

  @description          The DistYWhilePass is the distance the object covers while the ego vehicle passes it.
                        It is negative if the object drives to the right and positive if it drives to the left. \n
                        To prevent an over complex distinction of cases, the fTimeSavePassX is calculated without 
                        using the object acceleration.
                        @startuml CD_f_CalculateDistYWhilePass_activity.png
                        start
                          if(Object moves in the direction of\nthe evasion movement of the ego vehicle?) then (Yes)
                            if(Object velocity at TTC is higher\nthan the ego velocity?) then (Yes)
                              :1}
                              :The ego vehicle will not pass the object:
                               **TimeSavePass** = MAX;
                            else(No)
                             :2}
                              :Calculate **TimeSavePass**;
                              note right: >see formula **TimeSavePass**
                            endif
                            #Orange:Calculate **fDistYWhilePass** (=lateral distance 
                            the Object moves during TimeSavePass):
                            <b>CDCalculateDistance</b> >
                          else (No)
                            :3}
                            :**DistYWhilePass** = 0;
                          endif

                        stop
                        @enduml

  @return               float32 fDistYWhilePass: Lateral distance covered by the object while the ego vehicle passes by. 
                        @phys_unit [m] @range [0,+...[

  @param[in]            ObjMovement :      Kinematics structure of the current object.
  @param[in]            predObjMovement :  Kinematics structure of the current Object predicted to TTC.
  @param[in]            predEgoMovement :  Kinematics structure of the ego vehicle predicted to TTC.
  @param[in]            fEgoAccelAssumed : Assumed ego acceleration after the ego vehicle reaches TTS = 0. 
                                           @phys_unit[m/s^2] @range ]-...,0]
  @param[in]            fDistanceToPass :  Distance the ego vehicle has to cover to pass the current object completely.
                                           @phys_unit[m] @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_DISTANCE_TO_PASS\n

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Time Save Pass:**\n
                          \f$t_{SavePass, X} = \frac{- D_{Pass}}{V_{X,Obj,TTC} - V_{X,Ego,TTC}}\f$

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_F_CALCULATETTSDYNCORE_001 \n
                        @ref TEST_CD_F_CALCULATETTSDYNCORE_002 \n
                        @ref TEST_CD_F_CALCULATETTSDYNCORE_003

  @traceability         Design Decision

*************************************************************************************************************************/
static float32 CD_f_CalculateDistYWhilePass(CDMovement_t const * const ObjMovement,
                                            CDMovement_t const * const predObjMovement,
                                            CDMovement_t const * const predEgoMovement,
                                            float32      const         fEgoAccelAssumed,
                                            float32      const         fDistanceToPass)
{
  float32 fDistYWhilePass = 0.f;

  /* Check if the objects lateral movement has the same direction as the Ego evasion movement. */
  if (    (fABS(predObjMovement->fVy)             > CD_TTS_MAX_YVEL_FOR_PASSING)
       && ( (ObjMovement->fVy * fEgoAccelAssumed) >  0.f                       ) )
  {
    float32 fTimeSavePassX  = 0.f;
    float32 fVrelXPredicted = (predObjMovement->fVx - predEgoMovement->fVx);

    /* To prevent over complex distinction of cases, calculate time to pass without acceleration */
    if ( fVrelXPredicted > -C_F32_DELTA)
    {
      /* No Passing */
      fTimeSavePassX = CD_TTS_MAX_PASSING_TIME;
    }
    else
    {
      fTimeSavePassX = -fDistanceToPass/fVrelXPredicted;
      /*Safeguard against negative passing distances and threshold for max time*/
      fTimeSavePassX = MINMAX_FLOAT(0.f, CD_TTS_MAX_PASSING_TIME, fTimeSavePassX);
    }

    /* calculate distance in y-direction while passing object meaning ego- front same position as object tail up to
    ego tail same position as object front. Obj is driving to the right -> fDistYWhilePass is negative and vice versa */
    fDistYWhilePass = CDCalculateDistance( 0.f, ObjMovement->fVy, ObjMovement->fAy, fTimeSavePassX );

  }

  return fDistYWhilePass;
}
#endif

/*************************************************************************************************************************
  Functionname:         CD_f_CalculateTTSDynCore                                                                        */ /*!

  @brief                Calculates TTS without considering object standstill but considering lateral movement.

  @description          Calculates the time that remains for the driver of the ego vehicle to avoid a collision 
                        with an object by executing a lateral evasion movement.\n
                        The calculation follows the subsequent steps:
                        @startuml CD_f_CalculateTTSDynCore_activity.png
                        start
                          #Orange:Predict ego and object 
                          movement up to given time
                          <b>CDPredictMovement</b> >
                          note left
                            Lateral object acceleration is not 
                            considered. Possible stopping of 
                            ego or object is considered
                          end note
partition #LightBlue **CD_USE_DISTANCE_TO_PASS** {
                          #Orange:Correct the lateral Min Offset with the **DistWhilePass**:
                          <b>CD_f_CalculateDistYWhilePass</b> >
                          note left: DistYWhilePass = Lateral distance the object\ncovers during the passing procedure
}
                          if(Predicted Y-Distance is enough for collision avoidance?) then (Yes)
                            :1}
                            :No additional steering required
                            **TTS** = MAX;
                          else(No)
                            if (Check Steering Change Flag) then (True)
                              note right
                                Changes the meaning of the assumed acceleration.
                                True:  A(y,applied) = A(y,assu) + A(y,ego)
                                False: A(y,applied) = A(y,assu)
                              end note
                              :2}
                              :Add current lateral acceleration to 
                              assumed one and limit to min/max values;
                            else(False)
                              :3}
                            endif
                            :Set up quadratic equation 
                            for the TTS calculation;
                            note right: >see formula **Formula TTS**
                            #Orange:Solve Quadratic equation and select 
                            the minimum solution as TTS:
                             <b>SFL_v_SolveQuadrEquation</b> 
                             <b>SFL_f_SelectMinValue</b> >
                          endif
                        stop
                        @enduml
                        Calculation steps of the TTS:
                        1. **Assumed formulas**: \n
                          - Y-Position of the Object (lateral acceleration and velocity are 0): \n
                            \f$Y_{Obj}(t) = Y_{Obj,t0}\f$
                          - Y-Position of the Ego Vehicle: \n
                            For \f$t=t_{TTS}\f$: \f$Y_{Ego,TTS} = V_{y,Ego,t0} \cdot t_{TTS} + 0.5 \cdot A_{y,Ego,t0} \cdot t_{TTS}^2\f$ \n
                            For \f$t>t_{TTS}\f$: \f$Y_{Ego}(t) = Y_{Ego,TTS}+V_{y,Ego,TTS} \cdot (t-t_{TTS}) + 0.5 \cdot A_{y,Ego,assumed} \cdot (t-t_{TTS})^2\f$
                          - Velocity of the Ego vehicle at \f$t=t_{TTS}\f$:
                            \f$V_{y,Ego,TTS} = V_{y,Ego,t0} + A_{y,Ego,t0} \cdot t_{TTS}\f$
                          .
                        2. **Define required positions at** \f$t_{TTC}\f$ : \n
                          \f$Y_{Ego}(t_{TTC}) = Y_{Obj}(t_{TTC}) \pm D \f$
                        3. **Fill in equations from 1.**:\n
                          \f$ t_{TTS}^2 \cdot -0.5 \cdot (A_{y,Ego,assumed}-A_{y,Ego,t0})\f$ \n
                          \f$ t_{TTS} \cdot t_{TTC} \cdot (A_{y,Ego,assumed}-A_{y,Ego,t0})\f$ \n
                          \f$ 1 \cdot 0.5 \cdot -A_{y,Ego,assumed} \cdot t_{TTC}^2 - V_{y,Ego,t0}\cdot t_{TTC} + Y_{Obj,t0} \pm D \f$
                        4. **Solve Quadratic equation**:\n
                          Applying the function @ref SFL_v_SolveQuadrEquation.
                        5. **Select the smallest solution**: \n
                          Applying the function @ref SFL_f_SelectMinValue.

  @return               float32 pTTS : Calculated Time To Steer. @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @param[in]            iObjectIndex :      Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in]            fEgoAccelAssumed :  Assumed lateral acceleration the ego vehicle can use to avoid a collision. 
                                            @phys_unit [m/s^2] @range ]-...,+...[
  @param[in]            fLateralMinOffset : Minimum lateral offset between the object and the ego vehicle after the evasion.
                                            @phys_unit [m] @range ]-...,+...[
  @param[in]            fDistanceToPass :   X-Distance the ego vehicle has to cover to pass the object. @phys_unit [m] @range ]0,+...[
  @param[in]            fTime :             Time until the evasion movement has to be finished (Usually TTC). @phys_unit [s] @range [0,+...[
  @param[in]            bUseSteeringChange :Flag indicating whether the assumed acceleration is added to the current lateral 
                                            acceleration (True) or is assumed without considering the current lateral acceleration (False).

  @glob_in              @ref CD_s_GetObjMov \n
                        @ref CD_s_GetEgoMov
  @glob_out             None

  @c_switch_part        @ref CD_USE_DISTANCE_TO_PASS
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula TTS:** \n
                        \f$ t_{TTS}^2 \cdot 0.5 \cdot (A_{y,Ego,t0} - A_{y,Ego,assumed})\f$ \n
                        \f$ t_{TTS}   \cdot t_{TTC} \cdot -(A_{y,Ego,t0} - A_{y,Ego,assumed})\f$ \n
                        \f$ 1         \cdot -0.5 \cdot A_{y,Ego,assumed} \cdot t_{TTC}^2 - V_{y,Ego,t0}\cdot t_{TTC} + Y_{Obj,t0} - D \f$

  @author               Christian Gutmann

  @testmethod           @ref TEST_CD_F_CALCULATETTSDYNCORE_001 \n
                        @ref TEST_CD_F_CALCULATETTSDYNCORE_002 \n
                        @ref TEST_CD_F_CALCULATETTSDYNCORE_003

  @traceability         Design Decision

*************************************************************************************************************************/
static float32 CD_f_CalculateTTSDynCore( ObjNumber_t    const         iObjectIndex,
                                         float32        const         fEgoAccelAssumed,
                                         float32                      fLateralMinOffset,
                                         float32        const         fDistanceToPass,
                                         float32        const         fTime,
                                         boolean        const         bUseSteeringChange)
{
  /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  CDMovement_t       CDObjMovement  = CD_s_GetObjMov(iObjectIndex, POS_GEN_OBJECT, KIN_ABS);
  CDMovement_t const EgoMovement    = CD_s_GetEgoMov();
  CDMovement_t       predObjMovement;
  CDMovement_t       predEgoMovement;
  float32            fTTS           = CD_TIME_MAX;

  /* Check if the Objects main moving direction is lateral or longitudinal. It it moves lateral it can only 
     stop in lateral direction, if it moves longitudinal it can only stop in longitudinal direction*/
  boolean            bStopX         = (boolean)(fABS(CDObjMovement.fVx) > fABS(CDObjMovement.fVy));
  boolean            bStopY         = (boolean)(bStopX == b_FALSE);

  /*Copy object movement to local struct. set acceleration to 0 for following calculations*/
  CDObjMovement.fAy = 0.f;

  /* Predict the ego and object movement up to TTC. Use abs movement as no relative movement in 
     x direction does not mean standstill... */
  CDPredictMovement( &CDObjMovement, &predObjMovement, fTime, bStopX, bStopY );
  CDPredictMovement( &EgoMovement,   &predEgoMovement, fTime, b_TRUE,   b_FALSE  );

#if(CD_USE_DISTANCE_TO_PASS)
  /* Calculate the lateral distance the object covers during the ego vehicle passes by. This distance 
     can diminish the required lateral offset if it moves into the direction into which the ego vehicle 
     tries to evade.*/
  fLateralMinOffset -= CD_f_CalculateDistYWhilePass(&CDObjMovement, &predObjMovement, &predEgoMovement, fEgoAccelAssumed, fDistanceToPass);
#else
  _PARAM_UNUSED(fDistanceToPass);
#endif

  /* Only calculate TTS if the predicted distance between ego vehicle and object is smaller than the needed 
     lateral offset, otherwise there is no need for (further) steering*/
  if (    (    ( fLateralMinOffset  > 0.f                                       )
            && ( fLateralMinOffset  > (predObjMovement.fY - predEgoMovement.fY) ) ) 
       || (    ( fLateralMinOffset <  0.f                                       ) 
            && ( fLateralMinOffset <  (predObjMovement.fY - predEgoMovement.fY) ) ) )
  {
    float32 fA;
    float32 fB;
    float32 fC;
    float32 fTotalEgoAccelAssumed = fEgoAccelAssumed;
    SFLPolynomialSolutions_t TTSSolutions;

    /* Add the ego acceleration to the assumed acceleration*/
    if (bUseSteeringChange != b_FALSE)
    {
      float32 fAccelYMax    = CML_f_CalculatePolygonValue(CD_NUMBER_OF_EMERGENCY_EGO_ACCEL_Y_VALUES, CD_EMERGENCY_EGO_ACCEL_Y, EgoMovement.fVx);
      
      fTotalEgoAccelAssumed += EgoMovement.fAy;
      /* limit to physical boundaries */
      fTotalEgoAccelAssumed = MINMAX_FLOAT(-fAccelYMax, fAccelYMax, fTotalEgoAccelAssumed);
    }

    /* equation of motion: 1/2*fA*t^2+fB*t+fC=0 */
    /*PRQA S 3121 3*/
    fA = 0.5f * (EgoMovement.fAy - fTotalEgoAccelAssumed);
    fB = - (EgoMovement.fAy - fTotalEgoAccelAssumed) * fTime;
    fC = predObjMovement.fY - (EgoMovement.fVy * fTime) - ((0.5f * fTotalEgoAccelAssumed) * SQR(fTime) ) - fLateralMinOffset;
    
    SFL_v_SolveQuadrEquation( fA, fB, fC, &TTSSolutions);
    fTTS = SFL_f_SelectMinValue( TTSSolutions.afSolutions, TTSSolutions.uNofSolutions, CD_TIME_MAX, b_FALSE );

    /* limit TTS value */
    fTTS = MINMAX_FLOAT(0.f, CD_TIME_MAX, fTTS);
  }
  else
  {
    /* The current kinematics are sufficient to reach the minimum lateral offset. */
    fTTS = CD_TIME_MAX;
  }

  return fTTS;
}

/*************************************************************************************************************************
  Functionname:         CDCalcALat                                                                                   */ /*!

  @brief                Calculates necessary lateral acceleration for TTSPre

  @description          Calculates necessary lateral acceleration for TTSPre
                        depending on lateral offset and provided lateral velocity: \n
                        \f$A_y = \frac{(V_y)^2}{2\cdot Dist_y}\f$

  @return               float32 Possible lateral acceleration. @phys_unit [m/s^2]

  @param[in]            fNecLatOffset : Required lateral offset. @phys_unit [m] @range ]-...,+...[
  @param[in]            fEgoVel :       X-Velocity of the ego vehicle. @phys_unit [m/s] @range [0,+...[

  @glob_in              @ref CD_COMFORT_EGO_VEL_FACTOR_Y
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @todo                 CDCalcALat is not necessary anymore, as the issue why it was inserted is now solved by a new activity level in DIM,
                        see issue 442567.

  @author               Andreas Jakob

  @testmethod           @ref TEST_CDCALCALAT_001 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static float32 CDCalcALat(float32 const fNecLatOffset, float32 fEgoVel)
{
  float32 fAy;
  const float32 fOVerlapThreshold = SQR(CD_V_LAT_PRE_LIMIT)/(2.0f*CD_A_LAT_PRE_LIMIT);

  if(fABS(fNecLatOffset) > fOVerlapThreshold)
  {
    float32 fVelFactor = CML_f_CalculatePolygonValue(CD_NUMBER_OF_COMFORT_EGO_VEL_FACTOR_Y_VALUES, CD_COMFORT_EGO_VEL_FACTOR_Y, fEgoVel);
    /*calculate necessary lateral acceleration by characteristic*/
    fAy = (SQR(CD_V_LAT_PRE_LIMIT)/(2.0f*fABS(fNecLatOffset))) * fVelFactor;/*PRQA S 3121*//*equations of motion: a= v^2 / (2*s) */
    /*set at least to lower acceleration threshold*/
    if( fABS(fAy) < CD_A_LAT_PRE_MIN )
    {
      fAy = CD_A_LAT_PRE_MIN;
    }
  }
  else
  {
    /*take max lateral acceleration when overlap is smaller than fOVerlapThreshold*/
    fAy = CD_A_LAT_PRE_LIMIT;
  }
  return fAy;
}

//!@}
#endif /* #if (ACDC_CFG_CD) */
