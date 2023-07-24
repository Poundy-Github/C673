/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_attention.c

DESCRIPTION:               Implementation of the DIM driver attention

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:41:57CEST $

VERSION:                   $Revision: 1.23 $

LEGACY VERSION:            1.33

**************************************************************************** */
/**
@defgroup dim_mod_attention DIM_MOD_ATTENTION 
  
@ingroup Medic_dim
@{ **/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING == MEDIC_ON)
#include "dim/dim_int.h"

/*************************************************************************************************************************
  Functionname:    DIMAttentionEvalInputData                                                                        */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       pDIM_attention_par : 
  @param[in,out]   pInternalData : 
  @param[in]       bDriverBraking : 
  @param[in]       fGasPedalPosition : 
  @param[in]       fGasPedalGradient : 
  @param[in]       uiTurnIndicator : 
  @param[in]       fAbsSteeringWheelGrad : 
  @param[in]       fLongAccel : 
  @param[in]       fLongVelocity : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
static void DIMAttentionEvalInputData( const DIM_ATTENTION_PAR_struct_t * pDIM_attention_par, 
                                         DIMInternalDataModAttention_t * pInternalData, 
                                         boolean bDriverBraking, 
                                         float32 fGasPedalPosition, 
                                         float32 fGasPedalGradient, 
                                         uint8 uiTurnIndicator, 
                                         float32 fAbsSteeringWheelGrad, 
                                         float32 fLongAccel, 
                                         float32 fLongVelocity );


/*************************************************************************************************************************
  Functionname:    DIMAttentionGetInputValues                                                                       */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in,out]   pInternalData : 
  @param[in]       pInputData : 
  @param[in,out]   *bDriverBraking : 
  @param[in,out]   *fGasPedalPosition : 
  @param[in,out]   *fGasPedalGradient : 
  @param[in,out]   *uiTurnIndicator : 
  @param[in,out]   *fAbsSteeringWheelGrad : 
  @param[in,out]   *fLongAccel : 
  @param[in,out]   *fLongVelocity : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
static void DIMAttentionGetInputValues( DIMInternalDataModAttention_t * pInternalData, 
                                       const DIMInputDataGlobal_t * pInputData, 
                                       boolean *bDriverBraking, 
                                       float32 *fGasPedalPosition, 
                                       float32 *fGasPedalGradient, 
                                       uint8 *uiTurnIndicator, 
                                       float32 *fAbsSteeringWheelGrad, 
                                       float32 *fLongAccel, 
                                       float32 *fLongVelocity );

/*************************************************************************************************************************
  Functionname:        DIMInitModuleAttention                                                                         */ /*!

  @brief               DIMInitModuleAttention 

  @description         Data Initialization of module Attention     
                       @startuml
                       Start
                       if(null ptr check for internal data ok?) then (yes)
                        :Initialization of DIM module\nattention hypothesis internal data parameters;
                        :return no errors for ptr;
                        else (no)
                        :return null ptr error;
                        endif
                       stop
                       @enduml
  @return              error

  @param[in,out]       pInternalData
  
  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
eGDBError_t DIMInitModuleAttention(DIMInternalDataModAttention_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  if(pInternalData != NULL)
  {
    pInternalData->fHighKeepTime        = 0.0f;
    pInternalData->fLowKeepTime         = 0.0f;
    pInternalData->fVeryHighKeepTime    = 0.0f;
    pInternalData->fHigherKeepTime      = 0.0f;
    pInternalData->fConstVelTime        = 0.0f;
    pInternalData->fNoGasPedalGradTime  = 0.0f;
    pInternalData->fConstVelocity       = 0.0f;
    pInternalData->iConfidence          = 0;
    pInternalData->iProbability         = 0;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return eRetValue;
}
/*************************************************************************************************************************
  Functionname:        DIMAttentionGetInputValues                                                                         */ /*!

  @brief               collects input values from pInputData and make error handling

  @description         Collects DriverBraking, TurnIndicator, SteeringWheelGrad, LongVelocity,
                       and LongAccel unconditionally.
                       Aditionally external SpeedLimiter and KickDown is used for conditionally setting
                       GasPedalPosition and GasPedalGradient. Briefly in SpeedLimiter mode GasPedal inputs
                       are ignored for keeping Attention low (unknown). If SpeedLimiter and KickDown is active
                       GasPedalPosition is overwritten with GasPedalPosition for KickDown to trigger
                       very high attention (even in SpeedLimiter mode).

                       @startuml
                       Start
                       :set confidence to maximum;
                       If (speedlimiter signal quality OK?) then (yes)
                       :get the speedlimiter status;
                       Endif
                       If (brake signal quality OK?) then (yes)
                       :get the brake signal status;
                       Else (no)
                       :decrease the confidence by predefined factor;
                       Endif
                       If (gaspedal position signal quality ok?) then (yes)
                       :get gas pedal position signal value;
                       Else (no)
                       :decrease the confidence by predefined factor;
                       Endif
                       If (gaspedal gradient signal quality ok?) then (yes)
                       :get gas pedal gradient signal value;
                       Else (no)
                       :decrease the confidence by predefined factor;
                       Endif
                       If (turn indicator signal quality is OK?) then (yes)
                       :get turn indicator signal value;
                       Else (no)
                       :decrease the confidence by predefined factor;
                       Endif
                       If (steerwheel grad signal quality OK?) then (yes)
                       :get steer wheel grad signal value;
                       Else if (steerwheel grad signal qquality bad?) then (yes)
                       :use default steer wheel grad value;
                       Elseif (steerwheel grad signal quality is bad?) then (yes)
                       :decrease confidence value by predefined factor;
                       Endif
                       If(ego vehicle acceleration signal quality OK?) then (yes)
                       :get ego vehicle acceleration value;
                       Else (no)
                       : decrease confidence value by predefined factor;
                       Endif
                       If(ego vehicle velocity signal quality OK?) then (yes)
                       :get ego vehicle velocity value;
                       Else (no)
                       : decrease confidence value by predefined factor;
                       Endif
                       Stop
                       @enduml

          
  @return              void

  @param[in,out]       pInternalData
  @param[in]           pInputData
  @param[out]          bDriverBraking 
  @param[out]          fGasPedalPosition 
  @param[out]          fGasPedalGradient 
  @param[out]          uiTurnIndicator 
  @param[out]          fAbsSteeringWheelGrad
  @param[out]          fLongAccel 
  @param[out]          fLongVelocity  

  @glob_in             None 
  @glob_out            None

  @c_switch_part       DIM_CFG_USE_KICKDOWN_INPUT 
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                 None
  @post                None

  @InOutCorrelation    Not defined
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_418}
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static void DIMAttentionGetInputValues( DIMInternalDataModAttention_t * pInternalData, 
                                       const DIMInputDataGlobal_t * pInputData, 
                                       boolean *bDriverBraking, 
                                       float32 *fGasPedalPosition, 
                                       float32 *fGasPedalGradient, 
                                       uint8   *uiTurnIndicator, 
                                       float32 *fAbsSteeringWheelGrad, 
                                       float32 *fLongAccel, 
                                       float32 *fLongVelocity ) 
{
  /*default supplementary signals*/
  boolean bSpeedLimiterActive = b_FALSE;
  #if (DIM_CFG_USE_KICKDOWN_INPUT == MEDIC_ON)
  boolean bKickDown           = TRUE;
  #endif

  pInternalData->iConfidence = DIM_ATTENTION_PAR_NormalConfidence;


  /*--- supplementary signals -> no Confidence degradation ---*/

  /*get SpeedLimiter signal, in case of NOK input keep NotActive (default) -> normal DirverMonitoring, no degradation*/
  if(pInputData->SpeedLimiter.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->SpeedLimiter, (bSpeedLimiterActive), b_FALSE, boolean);/*PRQA S 4350 18 #date: 2020-06-11, reviewer: Nalina M, reason: redundant casting needed for type safety*/
  }

  #if (DIM_CFG_USE_KICKDOWN_INPUT == MEDIC_ON)
  /*get speed KickDown signal, in case of NOK input keep Active -> normal DirverMonitoring*/
  if(pInputData->KickDown.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->KickDown, (bKickDown), TRUE, boolean);
  }
  #endif

  /*--- primary signals -> with Confidence degradation ---*/

  /*get DriverBraking signal, in case of NOK keep default FALSE -> normal DriverMonitoring "not braking"*/
  if(pInputData->DriverBraking.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->DriverBraking, (*bDriverBraking), DIM_ATTENTION_DEFAULT_DrvBraking, boolean);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }

  /*get GasPedalPosition signal, in case of NOK keep default 100% -> normal DriverMonitoring "full throttle"*/
  if(pInputData->GasPedalPosition.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->GasPedalPosition, (*fGasPedalPosition), DIM_ATTENTION_DEFAULT_GasPedalPos, float32);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }

  /*get GasPedalGradient signal, in case of NOK keep default 0 -> normal DriverMonitoring "no gradient"*/
  if(pInputData->GasPedalGradient.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->GasPedalGradient, (*fGasPedalGradient), DIM_ATTENTION_DEFAULT_GasPedalGrad, float32);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }

  /*in case of a valid turn indicator signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->TurnIndicator.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->TurnIndicator, (*uiTurnIndicator), DIM_ATTENTION_DEFAULT_TurnIndicator, uint8);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }

  /*in case of a valid steering wheel gradient signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->SteeringWheelGradient.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->SteeringWheelGradient, (*fAbsSteeringWheelGrad), DIM_ATTENTION_DEFAULT_SteeringWheelGrad, float32);
    (*fAbsSteeringWheelGrad) = fABS((*fAbsSteeringWheelGrad));
  }
  else if(pInputData->SteeringWheelGradient.eSignalQuality == (uint8)DIMInputSignalState_BadQuality)
  {
    (*fAbsSteeringWheelGrad) = 0.0f; /*Multi-Turn-Loss shall not influence attention-confidence*/
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }

  /*in case of a valid ego accel signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->VehicleAcceleration.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->VehicleAcceleration, (*fLongAccel), DIM_ATTENTION_DEFAULT_LongAccel, float32);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }
  
  /*in case of a valid ego velocity signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->VehicleVelocity.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->VehicleVelocity, (*fLongVelocity), DIM_ATTENTION_DEFAULT_LongVelocity, float32);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ATTENTION_PAR_MissingConfidenceDelta;
  }

  /*safeguarding Confidence degradation below 0%*/
   pInternalData->iConfidence = CML_Max (0, pInternalData->iConfidence);            /*parameters can change -> safeguarding*/

  /*--- further signal treatment ---*/

  /*ignore GasPedal inputs while SpeedLimiter is active and no KickDown detected*/
  if (b_TRUE == bSpeedLimiterActive)
  {
    #if (DIM_CFG_USE_KICKDOWN_INPUT == MEDIC_ON)
    /*use "external" KickDown input to force GasPedal KickDown values*/
    if (TRUE == bKickDown)
    {
      /* Set the pedal position at high value to enforce high attention */
      (*fGasPedalPosition) = DIM_ATTENTION_PAR_GasPedal_KickDown_Value;
    }
    else
    {
      /* Keep the pedal position at low value to avoid pedal-off recognition */
      (*fGasPedalPosition) = DIM_ATTENTION_PAR_GasPedal_Passive_Value;
      (*fGasPedalGradient) = 0;
    }
    #else
    if ((*fGasPedalPosition) <= DIM_ATTENTION_PAR_GasPedal_KickDown)
    {
      /*no KickDown detected*/
      /* Keep the pedal position at low value to avoid pedal-off recognition */
      (*fGasPedalPosition) = DIM_ATTENTION_PAR_GasPedal_Passive_Value;
      (*fGasPedalGradient) = 0.0f;
    }
    #endif /*DIM_CFG_USE_KICKDOWN_INPUT*/
  }
}/* PRQA S 7004, 7002 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/ 

/*************************************************************************************************************************
  Functionname:         DIMAttentionEvalInputData                                                                         */ /*!

  @brief                Evaluates the input values received for attention hypothesis
  
  @description          Determines the attention hypothesis parameter values by evaluation the driver information received
                        like turn indicators, gas peda and brake pedal information. With this the driver's attention is 
                        determined and the timer corresponding to attention hypothesis is set accordingly, like higher the 
                        attention, higer the time to activate the brake systems and viceversa. This also checks for the 
                        driving pattern to determine if the driver is a robot or not.

                        @startuml
                        Start
                        :get acceleration threshold for the ego velocity;
                        If(ego acceleration > expected acceleration?) then (yes)
                        if(accel override check enabled?) then (yes)
                        if(ego vel > threshold?) then (yes)
                        :update timers for very high attention;
                        Endif
                        Else (no)
                        :update timer for very high attention;
                        Endif
                        Else (no)
                        If(driver braking, but acc and vel not as expected?) then (yes)
                        :update the timer for higher attention;
                        Else (no)
                        :get expected gas pedal position for ego velocity;
                        If(driver braking or gaspedalpos>expected or indicators are on and vel>expected?) then (yes)
                        :update the timer for high attention;
                        Else (no)
                        If(gas pedal grad and steering wheel angle not as expected?) then (yes)
                        :update the timer for low attention;
                        Endif
                        Endif
                        Endif
                        Endif
                        If(high attention timers have no valid value, and if velocity is constant?) then (yes)
                        If(constant velocity not for a while?)then (yes)
                        :reset the timer for gas pedal grad;
                        Else (no)
                        If(gas pedal pos >0 and no gaspedal grad for a while?) then (yes)
                        :robot condition met, low attention timer updated;
                        Else (no)
                        :reset the gas pedal grad timer;
                        Endif
                        Endif
                        Else (no)
                        :velocity not constant enough, \nstore current velocity and reset timers;
                        endif
                        Stop
                        @enduml

  @return               void
  
  @param[in]            pDIM_attention_par 
  @param[in]            bDriverBraking
  @param[in]            fGasPedalPosition 
  @param[in]            fGasPedalGradient  
  @param[in]            uiTurnIndicator 
  @param[in]            fAbsSteeringWheelGrad  
  @param[in]            fLongAccel
  @param[in]            fLongVelocity  
  @param[in,out]        pInternalData  

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref DIM_CFG_CHECK_ACCELOVERRIDE \
                        @ref DIM_CFG_DISABLE_JUST_RELEASED_ACCL_PEDAL
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)  

  @traceability         
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_301}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_4789}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_883}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static void DIMAttentionEvalInputData( const DIM_ATTENTION_PAR_struct_t * pDIM_attention_par, 
                                         DIMInternalDataModAttention_t * pInternalData, 
                                         boolean bDriverBraking, 
                                         float32 fGasPedalPosition, 
                                         float32 fGasPedalGradient, 
                                         uint8 uiTurnIndicator, 
                                         float32 fAbsSteeringWheelGrad, 
                                         float32 fLongAccel, 
                                         float32 fLongVelocity )
{
  float32 fTemp = CML_f_CalculatePolygonValue(DIM_ATTENTION_PAR_AccelCurve_POINTS, pDIM_attention_par->fAccelCurve, fLongVelocity);
  if( fLongAccel > fTemp )
  {
    /* consider wrong acceleration override scenario in determining very high attention */
    #ifdef DIM_CFG_CHECK_ACCELOVERRIDE
    if( fLongVelocity > DIM_ATTENTION_ACCELOVERRIDE_PERF_LIMIT_SPEED ) 
    {
      pInternalData->fVeryHighKeepTime = pDIM_attention_par->fVeryHighTime;
      pInternalData->fHigherKeepTime   = pDIM_attention_par->fHigherTime;
    }
    #else
    pInternalData->fVeryHighKeepTime = pDIM_attention_par->fVeryHighTime;
    pInternalData->fHigherKeepTime   = pDIM_attention_par->fHigherTime;
    #endif 
    pInternalData->fHighKeepTime     = pDIM_attention_par->fHighTime;
    pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
  }
  else 
  {
    /* check for higher attention */
    if ( (bDriverBraking != b_FALSE)
    #if (DIM_CFG_ATTENTION_USE_VELOCITY)
      && (fLongVelocity < pDIM_attention_par->fBrakePedalMaxVelocity )
    #endif
      && (fLongAccel <= pDIM_attention_par->fDriverBrakingMaxAcceleration)
      )
    {
      pInternalData->fHigherKeepTime   = pDIM_attention_par->fHigherTime;
      pInternalData->fHighKeepTime     = pDIM_attention_par->fHighTime;
      pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
    }
    else
    {
      fTemp = CML_f_CalculatePolygonValue(DIM_ATTENTION_PAR_GasPedalPosCurve_POINTS, pDIM_attention_par->fGasPedalPosCurve, fLongVelocity);
      /* check for high attention */
      if ( ((bDriverBraking != b_FALSE )
      #ifdef DIM_CFG_INHIBIT_ATTN_FACTOR_AT_HIGHSPEED_BRAKE
            && (fLongVelocity < DIM_ATTENTION_PAR_VEL_THRES_FOR_DRVBRK)
      #endif 
           ) || (fGasPedalPosition > fTemp)
         || (  (( uiTurnIndicator == eTurnIndicator_Left ) || ( uiTurnIndicator == eTurnIndicator_Right ) )
             && (fLongVelocity >= pDIM_attention_par->fTurnIndicatorMinVelocity)) 
        )
      {
        pInternalData->fHighKeepTime     = pDIM_attention_par->fHighTime;
        pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
      }
      else 
      {
        /* check for low attention */
        if (   (fGasPedalGradient > pDIM_attention_par->fGasPedalGradLowPositive)
          || ( fGasPedalGradient < pDIM_attention_par->fGasPedalGradLowNegative)
          #ifndef DIM_CFG_DISABLE_JUST_RELEASED_ACCL_PEDAL
          || (   ( fGasPedalGradient < pDIM_attention_par->fGasPedalLowNegMeasured )
          && ( fGasPedalPosition < pDIM_attention_par->fGasPedalLowNegMeasuredPos )
          )
          #endif
          || ( fAbsSteeringWheelGrad > pDIM_attention_par->fSteeringGradLow ) 
          )
        {
          pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
        }
        else
        {
          /*nothing to do for unclear situations*/
        }
      }
    }
  }

  /* check for drive robot */

  /* check for low or unknown state and constant velocity */
  if ( (!( pInternalData->fHighKeepTime > 0.0f) )
    && (!( pInternalData->fHigherKeepTime > 0.0f) )
    && (!( pInternalData->fVeryHighKeepTime > 0.0f) )
    && ( fLongVelocity > 0.0f )
    && ( fLongVelocity > (pInternalData->fConstVelocity - pDIM_attention_par->fRobotControlledVelocityThresh ))
    && ( fLongVelocity < (pInternalData->fConstVelocity + pDIM_attention_par->fRobotControlledVelocityThresh ))
    )
  {
    /* velocity currently constant */
    if ( pInternalData->fConstVelTime > 0.0f )
    {
      /* velocity not constant for a certain time 
      reset timer for gas pedal gradient */
      pInternalData->fNoGasPedalGradTime = pDIM_attention_par->fNoGasPedalGradientTime;
    }
    else
    {
      /* velocity constant for a certain time
      check for test case conditions: gas pedal position > 0 && no gas pedal gradient */
      if (( fGasPedalPosition > 0.0f )
        && ( fGasPedalGradient < pDIM_attention_par->fNoGasPedalGradientThresh )
        && ( fGasPedalGradient > -pDIM_attention_par->fNoGasPedalGradientThresh )
        )
      {
        /* conditions for decreasing timer of gas pedal gradient met */
        if ( pInternalData->fNoGasPedalGradTime > 0.0f )
        {
          /* there was a gas pedal gradient within a certain time*/
        }
        else
        {
          /* now all conditions for robot detection are met */
          pInternalData->fLowKeepTime = MIN_FLOAT(pInternalData->fLowKeepTime,pDIM_attention_par->fLowKeepRobotTime);
        }
      }
      else
      {
        /* conditions for deccreasing timer of gas pedal gradient not met: reset timer */
        pInternalData->fNoGasPedalGradTime = pDIM_attention_par->fNoGasPedalGradientTime;
      }
    }
  }
  else
  {
    /* velocity not constant enough -> reset timer and store current velocity*/
    pInternalData->fConstVelTime       = pDIM_attention_par->fRobotControlledVelocityTime;
    pInternalData->fNoGasPedalGradTime = pDIM_attention_par->fNoGasPedalGradientTime;
    pInternalData->fConstVelocity      = fLongVelocity;
  }
}

/*************************************************************************************************************************
  Functionname:         DIMRunModuleAttention                                                                          */ /*!

  @brief                DIM run for attention 

  @description          This function triggers the evaluation of the input signals collected for checking the attention 
                        hypothesis, and takes the results of the evaluation for creating probability and confidence 
                        for attention hypothesis. The timers for attention are also updated accordingly based on the 
                        attention level.

                        @startuml
                        Start
                        :set default values to attention related signals;
                        If(null ptr check for input data and hypo ok?) then (yes)
                        :Get input signals;
                        Note left
                        Speed Limiter signal
                        Speed Kickdown signal
                        DriverBraking signal
                        GasPedalPosition signal
                        Turn indicator signal
                        Steering wheel gradient signal
                        Ego acceleration signal
                        Ego velocity signal
                        End note 
                        :Update the DIM timers;
                        Note left
                        Timers for very high,
                        Higher, high and low keep time, 
                        Const vel time, no gaspedal grad time
                        End note
                        :Evaluate input signals;
                        Note left :Check for higher, high, low attention
                        :Create probabilities with respect to the DIM timers;
                        Note left
                        If very high keep time is valid,
                        Probability is very high,
                        If high keep time is valid, 
                        Probability is high,
                        And so on
                        End note
                        :fill dim out for feedback hypo;
                        :return no ptr errors;
                        Else (no)
                        :return null ptr error;
                        endif
                        stop
                        @enduml

  @return               error
  
  @param[in]            fCycleTime 
  @param[in]            pInputData 
  @param[in]            pOutHypothesis 
  @param[in]            pInternalData 
  @param[in]            pDIM_attention_par   

  @glob_in              None  
  @glob_out             None  

  @c_switch_part        None  
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                  None  
  @post                 None  

  @InOutCorrelation     Not defined  
  
  @testmethod           Test of output data (dynamic module test)  

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
eGDBError_t DIMRunModuleAttention(const float32 fCycleTime, const DIMInputDataGlobal_t *pInputData, 
                                  GDB_DMHypothesis_t *pOutHypothesis, 
                                  DIMInternalDataModAttention_t *pInternalData, 
                                  const DIM_ATTENTION_PAR_struct_t *pDIM_attention_par)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  boolean bDriverBraking      = DIM_ATTENTION_DEFAULT_DrvBraking;        /*default value for driver braking*/
  float32 fGasPedalPosition   = DIM_ATTENTION_DEFAULT_GasPedalPos;       /*default value for gas pedal position*/
  float32 fGasPedalGradient   = DIM_ATTENTION_DEFAULT_GasPedalGrad;      /*default value for gas pedal gradient*/
  uint8   uiTurnIndicator     = DIM_ATTENTION_DEFAULT_TurnIndicator;     /*default value for turn indicator 0 - means off*/
  float32 fAbsSteeringWheelGrad  = DIM_ATTENTION_DEFAULT_SteeringWheelGrad; /*default value for steering wheel gradient*/
  float32 fLongAccel          = DIM_ATTENTION_DEFAULT_LongAccel;         /*default value for long accel*/
  float32 fLongVelocity       = DIM_ATTENTION_DEFAULT_LongVelocity;      /*default value for long velocity*/


  if( ( pInputData != NULL ) && ( pOutHypothesis != NULL ) && ( pInternalData != NULL ) )
  {
    /*-------- get input signals -----------*/
    DIMAttentionGetInputValues( pInternalData, pInputData, &bDriverBraking, &fGasPedalPosition, &fGasPedalGradient, &uiTurnIndicator, &fAbsSteeringWheelGrad, &fLongAccel, &fLongVelocity);


    /*------ decrease timers ---------*/
    pInternalData->fVeryHighKeepTime   = MAX_FLOAT(pInternalData->fVeryHighKeepTime   - fCycleTime, 0.0f);
    pInternalData->fHigherKeepTime     = MAX_FLOAT(pInternalData->fHigherKeepTime     - fCycleTime, 0.0f);
    pInternalData->fHighKeepTime       = MAX_FLOAT(pInternalData->fHighKeepTime       - fCycleTime, 0.0f);
    pInternalData->fLowKeepTime        = MAX_FLOAT(pInternalData->fLowKeepTime        - fCycleTime, 0.0f);
    pInternalData->fConstVelTime       = MAX_FLOAT(pInternalData->fConstVelTime       - fCycleTime, 0.0f);
    pInternalData->fNoGasPedalGradTime = MAX_FLOAT(pInternalData->fNoGasPedalGradTime - fCycleTime, 0.0f);

    /*------- evaluate input signals ---------*/
    /* check for very high attention */
    DIMAttentionEvalInputData(pDIM_attention_par, pInternalData, bDriverBraking, fGasPedalPosition, fGasPedalGradient, uiTurnIndicator, fAbsSteeringWheelGrad, fLongAccel, fLongVelocity );

    /*------ create probabilities ---------*/
    if (pInternalData->fVeryHighKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_VeryHighPercentage;
    }
    else if (pInternalData->fHigherKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_HigherPercentage;
    }
    else if (pInternalData->fHighKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_HighPercentage;
    }
    else if (pInternalData->fLowKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_LowPercentage;
    }
    else
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_UnknownPercentage;
    }

    pOutHypothesis->eType = DIMHypoType_Attention;
    pOutHypothesis->Confidence  = (percentage_t) pInternalData->iConfidence;
    pOutHypothesis->Probability = (sint8) pInternalData->iProbability;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

#endif /* end of check for MEDIC DIM switch */
#endif /* end of check for DIM2.0switch */

/**@}*/
