/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision_environment.c

  DESCRIPTION:            HLA decision on environment states.
                           - City
                           - Brightness
                           - ...

  CREATION DATE:          2014-11-03
    
  CPU:                    Independent

  VERSION:                $Revision: 1.13 $
**************************************************************************** */
/* PRQA S 3121 EOF # 2019-05-28 A.Fischer: 0.0f and 1.0f can not be considered a magic number */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_decision_environment.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/


/****************************************************************************
 * LOCAL FUNCTION DECLARATIONS
 *****************************************************************************/


/*****************************************************************************
  GLOBAL FUNCTIONS DEFINITION 
*****************************************************************************/

/* *******************************************************************************
  Based on weather reported from camera blockage the visibility is deduced.
******************************************************************************** */
void HLAFDecisionEnv_Weather( const CB_t_ProvidedOutputs_t* const pCbOutputs,
                              const WiperStage_t*           const pWiperStage,
                              const HLAFCameraData_t*       const pCamData,
                                    HLAWeatherData_t*       const pWeatherData,
                                    RTE_HLAR_WeatherState*  const peWeatherStateOut
                            )
{
  const t_DecisionParametersWeather* pWeatherParams = &(GetDecisionParameters()->Weather);

  /* Update decision data for wiper stage */
  if (   (*pWiperStage > pWeatherParams->WiperStageThreshold)
      && (pWeatherData->wiperStageUsed == b_FALSE)
     )
  {
    /* wiper stage is set to highest speed    */
    /* but wiper stage has not yet been used  */
    pWeatherData->wiperStageTime += pCamData->dtime_s;

    /* if passed time is above the enter time threshold, use wiper stage to enable weather turn off */
    if (pWeatherData->wiperStageTime >= pWeatherParams->WiperTriggerEnterTime)
    {
      pWeatherData->wiperStageUsed = b_TRUE;
      pWeatherData->wiperStageTime = 0.0f;
    }
  }
  else if (   (*pWiperStage <= pWeatherParams->WiperStageThreshold)
           && (pWeatherData->wiperStageUsed == b_TRUE)
          )
  {
    /* wiper stage is set to low speed  */
    /* and wiper stage has been used    */
    pWeatherData->wiperStageTime += pCamData->dtime_s;

    /* if passed time is above the leave time threshold, disable weather turn off */
    if (pWeatherData->wiperStageTime >= pWeatherParams->WiperTriggerLeaveTime)
    {
      pWeatherData->wiperStageUsed = b_FALSE;
      pWeatherData->wiperStageTime = 0.0f;
    }
  }
  else
  {
    /* in all other cases the time is reseted */
    pWeatherData->wiperStageTime = 0.0f;
  }

  /* set weather state accordingly */
  if (CML_GetBit(pCbOutputs->ui8_WeatherCondition, (uint8)GB_HEAVY_FOG) == b_TRUE)
  {
    *peWeatherStateOut = RTE_HLAR_WEATHER_HEAVY_FOG;
  }
  else if (   (CML_GetBit(pCbOutputs->ui8_WeatherCondition, (uint8)GB_HEAVY_RAIN_SNOW) == b_TRUE)
           || (pWeatherData->wiperStageUsed == b_TRUE)
          )
  {
    *peWeatherStateOut = RTE_HLAR_WEATHER_BAD;
  }
  else
  {
    *peWeatherStateOut = RTE_HLAR_WEATHER_GOOD;
  }
}
/* *******************************************************************************
   Set the scene info flag depending if an oncoming or preceding is leaving the ROI
******************************************************************************** */
void HLAFDecisionEnv_SceneInfo( const HLAFData_t*                     const pFData,
                                const t_DecisionParametersSceneInfo*  const pSceneInfoParameters,
                                const HLAFMatrixOut_t*                const pOutNext,
                                const LSD_LightObjectList_t*          const pObjectList,
                                      RTE_HLA_SceneInfo*              const pSceneInfo
                              )
{

  /* Set default value */
  *pSceneInfo = RTE_HLA_SCENEINFO_UNKNOWN;
  
}


/* *******************************************************************************
  Based on last state from city history the state machine kicks in
  a) CITY_IDLE, no city is present. If a city is reported and the
     ambient brightness is not NIGHT, city state changes to
     CITY_DETECTED. If a maybe_city is reported and the ambient
     brightness is not NIGHT, city state changes to CITY_MAYBE.
  b) CITY_MAYBE, a possible city is present, but not sure yet.
     If a city is reported and ambient brightness is not NIGHT,
     city state changes to CITY_DETECTED. If maybe_city is kept
     for more than a parameter based distance (currently 200 m),
     city state changes to CITY_MAYBE_WAIT4IDLE. If no city gets
     reported and thresholds for time and distance are met
     (currently 1 s and 50 m) and ambient brightness is not NIGHT
     or speed is high enough, city state changes to CITY_IDLE
  c) CITY_MAYBE_WAIT4IDLE, even though a city or no city gets
     reported, city state changes ot CITY_IDLE
  d) CITY_DETECTED, if no city is reported and time and distance
     are above the according parameter based thresholds
     (currently 6 s and 100 m), ambient brightness is not night
     or speed is no turn off reason, algo counts and waits until
     city is far enough away (provided by dTurnOnDelay)
******************************************************************************** */
void HLAFDecisionEnv_City(const LSD_e_EnvironmentData_CityState             eCity,
                          const LSD_e_EnvironmentData_BrightnessState       e_Brightness,
                          const t_DecisionParametersCity*             const pPar,
                                HLAFData_t*                           const pFData,
                                RTE_HLAR_CityState*                   const peCityOut
                         )
{
  switch(pFData->DecisionData.City.eCityState) /* internal city state */
  {
    case HLAF_CITY_IDLE:
      /* idle */

      /* reset city time and distance */
      pFData->DecisionData.City.timeInCity_s = 0.0f;
      pFData->DecisionData.City.distInCity_m = 0.0f;
      pFData->DecisionData.City.distOutCity_m = 0.0f;

      if(   (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED)
         && (e_Brightness >= (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3)
        )
      {
        /* city detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_DETECTED;
        *peCityOut = RTE_HLAR_CITY_DTCD;
      }
      else if(   (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE)
              && (e_Brightness >= (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3)
             )
      {
        /* maybe city detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_MAYBE;
        *peCityOut = RTE_HLAR_CITY_MAYBE;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLAF_CITY_MAYBE:
      /* increment time and distance */

      pFData->DecisionData.City.timeInCity_s += pFData->CamData.dtimeFwd_s;
      pFData->DecisionData.City.distInCity_m += pFData->CamData.ddistFwd_m;

      if(   (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED)
         && (e_Brightness >= (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3)
        )
      {
        /* city detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_DETECTED;
        *peCityOut = RTE_HLAR_CITY_DTCD;

        /* reset city time and distance */
        pFData->DecisionData.City.timeInCity_s = 0.0f;
        pFData->DecisionData.City.distInCity_m = 0.0f;
        pFData->DecisionData.City.distOutCity_m = 0.0f;
      }
      else if(eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE)
      {
        /* stay only for maxMayBeCityDist_m in MayBeCity        */
        if(pFData->DecisionData.City.distInCity_m > pPar->maxMayBeCityDist_m)
        {
          /* leave maybe city */
          pFData->DecisionData.City.eCityState = HLAF_CITY_MAYBE_WAIT4IDLE;
          *peCityOut = RTE_HLAR_CITY_NOT_DTCD;
        }
      }
      else if(   (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_NONE)
              && (pFData->DecisionData.City.timeInCity_s > pPar->minMayBeCityTime_s)
              && (pFData->DecisionData.City.distInCity_m > pPar->minMayBeCityDist_m)
              && (   (e_Brightness >= (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3)
                  || (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, (uint32)HLAF_TURN_OFF_REASON_MIN_SPEED) == b_FALSE)
                 )
             )
      {
        /* city not detected -> leave maybe city*/
        pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
        *peCityOut = RTE_HLAR_CITY_NOT_DTCD;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLAF_CITY_MAYBE_WAIT4IDLE:
      /* stayed too long in maybe city or HB switched on during maybe city -> wait for HLAR City idle */
      if(   (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_NONE)
         || (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED)
        )
      {
        pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
        *peCityOut = RTE_HLAR_CITY_NOT_DTCD;
      }
      break;

    case HLAF_CITY_DETECTED:
      /* city detected */

      /* leave city state ? */
      if(   (eCity == (uint8)LSD_ENVIRONMENT_DATA_CITY_STATE_NONE)
         && (pFData->DecisionData.City.timeInCity_s > pPar->minCityTime_s)
         && (pFData->DecisionData.City.distInCity_m > pPar->minCityDist_m)
         && (   (e_Brightness >= (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3)
             || (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, (uint32)HLAF_TURN_OFF_REASON_MIN_SPEED) == b_FALSE)
            )
        )
      {
        /* city not detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
        *peCityOut = RTE_HLAR_CITY_NOT_DTCD;
        pFData->DecisionData.City.distOutCity_m += pFData->CamData.ddistFwd_m;
      } 
      else
      {
        /* reset out_of_city_counter as we are back in city again */
        pFData->DecisionData.City.distOutCity_m = 0.0f;
      }

      /* increment time and distance for in_city_counters */
      pFData->DecisionData.City.timeInCity_s  += pFData->CamData.dtimeFwd_s;
      pFData->DecisionData.City.distInCity_m  += pFData->CamData.ddistFwd_m;
      break;

    case HLAF_CITY_LAST:
    default:
      pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
      *peCityOut = RTE_HLAR_CITY_NOT_DTCD;
      break;
  }
}


/* *******************************************************************************
  Tests the current speed and motion state against various parameter based
  thresholds to determine if HLA is allowed to operate.
******************************************************************************** */
void HLAFDecisionEnv_Speed( const VehDyn_t*                   const pVehDyn,
                            const VehSig_t*                   const pVehSig,
                            const RTE_HLAF_ParameterSpeed_t*  const pRTEPar,
                            const float32                           dT,
                                  HLAFSpeed_t*                const pDat
                          )
{
  const float32 deactivateSpeed         = pRTEPar->DeactivateSpeed;
  const float32 activateSpeed           = pRTEPar->ActivateSpeed;
  const float32 alwaysActiveSpeed       = pRTEPar->AlwaysActiveSpeed;
  const float32 displaySpeed            = pVehSig->VehSigAdd.SpeedoSpeed / CML_f_Kmh2Ms;
  const float32 keepOffVeryLowSpeed     = pRTEPar->KeepOff_VeryLowSpeed;
  const float32 keepOffLowRadius        = pRTEPar->KeepOff_LowRadius;
  const float32 keepOffHighAcceleration = pRTEPar->KeepOff_HighAcceleration;
  const float32 keepOffAccelTime        = pRTEPar->KeepOff_AccTime;
  const float32 keepOffDelay            = pRTEPar->KeepOff_Delay;

  /* update the speed state */
  if(   (displaySpeed >= alwaysActiveSpeed)
     && (pVehDyn->MotionState.MotState == (uint8)VDY_LONG_MOT_STATE_MOVE_FWD)
    )
  {
    pDat->state = SPEED_STATE_ALWAYSACTIVE;
  }
  else if (   (displaySpeed >= activateSpeed)
           && (pVehDyn->MotionState.MotState == (uint8)VDY_LONG_MOT_STATE_MOVE_FWD)
          )
  {
    if (pDat->state == SPEED_STATE_LOW)
    {
      /* state transition from state low to high. Set the activate penalty timer */
      if (pDat->keepOffEvents.u32 > 0u)
      {
        pDat->activatePenaltyTimer = keepOffDelay;
      }
      else
      {
        pDat->activatePenaltyTimer = 0.0f;
      }
    }
    pDat->state = SPEED_STATE_HIGH;
  }
  else if (   (displaySpeed <= deactivateSpeed)
           || (pVehDyn->MotionState.MotState != (uint8)VDY_LONG_MOT_STATE_MOVE_FWD)
          )
  {
    pDat->state = SPEED_STATE_LOW;
  }
  else
  {
    /* Do nothing */
  }

  /* trigger the actions depending on the state */
  if (pDat->state == SPEED_STATE_LOW)
  {
    /* set the low speed events */
    if (displaySpeed < keepOffVeryLowSpeed)
    {
      pDat->keepOffEvents.Bit.VerySlow = 1;
    }

    if(   (CML_f_IsNonZero(pVehDyn->Lateral.Curve.Curve) == b_TRUE)
       && ((1.0f / pVehDyn->Lateral.Curve.Curve) < keepOffLowRadius)
      )
    {
      pDat->keepOffEvents.Bit.HighCurvature = 1;
    }

    if(    (displaySpeed > 1.0f)
        && (pVehDyn->Longitudinal.Accel > keepOffHighAcceleration)
      )
    {
      pDat->keepOffEvents.Bit.HighAcceleration = 1;
    }

    pDat->disableHLABySpeed = 1;
  }
  else if (pDat->state == SPEED_STATE_HIGH)
  {
    /* decrease timer */
    pDat->activatePenaltyTimer -= dT;
    if (pDat->activatePenaltyTimer < 0.0f)
    {
      /* timer expired -> activate */
      pDat->disableHLABySpeed = 0;
      pDat->keepOffEvents.u32 = 0;
    }
    else
    {
      /* reset timer when acceleration indicates that velocity will fall below activation speed */
      if((displaySpeed + (keepOffAccelTime * pVehDyn->Longitudinal.Accel)) < activateSpeed)
      {
        pDat->activatePenaltyTimer = keepOffDelay;
      }
    }
  }
  else
  {
    /* always active state. Reset everything */
    pDat->disableHLABySpeed = 0;
    pDat->keepOffEvents.u32 = 0;
  }

  /* keep high beams off when acceleration indicates that velocity will fall below activation speed */
  if((displaySpeed + (keepOffAccelTime * pVehDyn->Longitudinal.Accel)) < activateSpeed)
  {
    pDat->keepOffHLABySpeed = 1;
  }
  else
  {
    pDat->keepOffHLABySpeed = 0;
  }

  /* nobody wants to disable HLA if the car goes too fast. who in their right mind would think this is a good idea? */
  pDat->disableHLAByHighSpeed = 0;

}
