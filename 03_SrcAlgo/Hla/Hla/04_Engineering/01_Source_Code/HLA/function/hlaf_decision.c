/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision.c

  DESCRIPTION:            HLA decision. This module makes some "pre" decisions.
                          The HLAR outputs will be analysed for the hla light,
                          standard and plus function.
                          e.g.:
                          - brightness analysis (dark enough for high beams ?)  
                          - state machine for highway, city, tunnel detection
                          ...

  CREATION DATE:          2011-02-23
  
  CPU:                    Independent

  VERSION:                $Revision: 1.22.1.3 $
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_decision.h"
#include "hla_errorhandling.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static void HLAFDecision_CheckTurnOffDelay( const HLAFData_t* const pFData,
                                            const boolean           bStartObjDelay,
                                            const float32           TurnOffDelayThresh,
                                                  float32*    const pTurnOffDelay,
                                                  float32*    const pTurnOnDelay,
                                                  boolean*    const pbObjDet
                                          );

static void HLAFDecision_TurnOnDelayTTB( const HLAObjectDataInt_t*                   const pIntObj,
                                         const float32                                     Speed,
                                         const LSD_e_EnvironmentData_HighwayState          eMotorwayState,
                                         const LSD_e_EnvironmentData_BrightnessState       eTrafficStyle,
                                         const reqHlaPrtList_t*                      const pReqPorts,
                                               float32*                              const pTurnOnDelayOut_s
                                       );


static boolean HLAFDecision_RelevantVehicle2TurnOff(  const RTE_HLAF_HighBeamState                  eHBState,
                                                      const HLAObjectDataInt_t*               const pIntObj,
                                                      const HLAFData_t*                       const pFData,
                                                      const LSD_LightObjectList_Roi_t*        const pROI,
                                                      const RTE_HLAF_ParameterKeepOnDelay_t*  const pKeepOnDelayParam,
                                                      const float32                                 TTBThreshold,
                                                      const float32                                 HorAngThreshold
                                                   );

static boolean HLAFDecision_CheckChinaMode( const RTE_HLAF_HighBeamState                  eHBState,
                                            const HLAObjectDataInt_t*               const pIntObj,
                                            const RTE_HLAF_ParameterKeepOnDelay_t*  const pKeepOnDelayParam
                                          );

/****************************************************************************
 * GLOBAL FUNCTION DEFINTIONS
*****************************************************************************/
/* *******************************************************************************
  Depending on lot of HLAF internal data the global turn off reasons are set. If
  no reason is present the timer will be reset otherwise the time will be increased
  by forward_time
******************************************************************************** */
void HLAFDecision_SetTurnOffReasonGlob( const RTE_HLAR_BrightnessState       e_Brightness,
                                        const reqHlaPrtList_t*         const pReqPorts,
                                        const HLAFData_t*              const pFData,
                                              HLAFTurnOffReason_t*     const pTurnOffReason
                                      )
{
  /* init turn off reason */
  pTurnOffReason->Reason = 0;

  /* turn off high beam due to min speed check for PASSIVE_BY_V_MIN */
  if(pFData->DecisionData.Speed.disableHLABySpeed > 0u)
  {
    /* min speed */
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_MIN_SPEED);
  }

  /* turn off high beam due to high speed check */
  if(pFData->DecisionData.Speed.disableHLAByHighSpeed > 0u)
  {
    /* high speed */
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_MAX_SPEED);
  }
    
  /* city detected ? */
  if(   (pFData->DecisionOut.eCityState == (RTE_HLAR_CityState)RTE_HLAR_CITY_DTCD)
     /* TODO: HLAR CPAR - Enable again? */
     //&& (pReqPorts->pCPar_HlarPar->AlgoCfg.CityDetection == RTE_HLA_CITYDET_ACTIVE)
    )
  {
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_CITY);
  }

  /* tunnel detected ? */
  if(   (pFData->DecisionOut.eTunnelState == (LSD_e_EnvironmentData_TunnelState)RTE_HLAR_TUNNEL_INSIDE)
     /* TODO: HLAR CPAR - Enable again? */
     //&& (pReqPorts->pCPar_HlarPar->AlgoCfg.TunnelDetection == RTE_HLA_TUNNELDET_ACTIVE)
    )
  {
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_TUNNEL);
  }

  /* too bright */
  if(   (e_Brightness < (RTE_HLAR_BrightnessState)RTE_HLAR_BRT_NIGHT)
     && (pReqPorts->pCPar_HlafPar->AlgoCfg.TestMode != (RTE_HLA_TestMode)RTE_HLA_TESTMODE_LAB_ENHANCED)
     )
  {
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS);
  }

  /* clearance measurement running ? */
  if(   (pFData->DecisionData.Blockage.eBlockageState == HLAF_BLOCKAGE_CLEAR_MEAS)
     && (pReqPorts->pCPar_HlafPar->AlgoCfg.TestMode != (RTE_HLA_TestMode)RTE_HLA_TESTMODE_NO_CLEARMEAS)
    )
  {
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_NOT_RELEASED);
  }

  /* blockage detected ? */
  if(   (pFData->DecisionData.Blockage.eBlockageState == HLAF_BLOCKAGE_BLOCKAGE)
     && (pReqPorts->pCPar_HlafPar->AlgoCfg.TestMode != (RTE_HLA_TestMode)RTE_HLA_TESTMODE_NO_CLEARMEAS)
    )
  {
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_BLOCKAGE);
  }

  /* Fog detected ? */
  if(   (pFData->DecisionOut.eWeatherState == (RTE_HLAR_WeatherState)RTE_HLAR_WEATHER_HEAVY_FOG)
     && (pReqPorts->pCPar_HlafPar->AlgoCfg.FogDetection == (RTE_HLA_FogDetection)RTE_HLA_FOGDET_ACTIVE)
    )
  {
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_FOG);
  }

  /* Bad Weather detected */
  if(pReqPorts->pCPar_HlafPar->AlgoCfg.BadWeatherDetection == (RTE_HLA_BadWeatherDetection)RTE_HLA_BADWEATHER_DET_ACTIVE)
  {
    if(    (pFData->DecisionOut.eWeatherState == (RTE_HLAR_WeatherState)RTE_HLAR_WEATHER_HEAVY_FOG)
        || (pFData->DecisionOut.eWeatherState == (RTE_HLAR_WeatherState)RTE_HLAR_WEATHER_MEDIUM_FOG)
        || (pFData->DecisionOut.eWeatherState == (RTE_HLAR_WeatherState)RTE_HLAR_WEATHER_BAD)
      )
    {
      CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER);
    }
  }
}


/* *******************************************************************************
  Loops over all given objects and decides if each could be a relevant vehicle.
  If the relevant vehicle fulfills the time-to-border constraints the output
  structure will be filled with its data.
******************************************************************************* */
void HLAFDecision_FindRelevantVehicle( const reqHlaPrtList_t*       const pReqPorts,
                                             HLAFRelevantVehicle_t* const pRelVeh
                                     )
{

  RTE_HLAF_HighBeamState horRotIhbcIndicator =  pReqPorts->pHlaBusInputSignals->headLightState;
  if (horRotIhbcIndicator == RTE_HLAF_HB_STATE_FULL_ON)
  {
    pRelVeh->bOncDetected   = b_TRUE;
    pRelVeh->bPrecDetected  = b_FALSE;
    pRelVeh->Onc_s          = 0.0F;
    pRelVeh->Prec_s         = 0.0F;
    pRelVeh->All_s          = 0.0F;
  }

}

/* *******************************************************************************
  Set turn off reason. e.g. relevant preceding or oncoming vehicles detected.
******************************************************************************** */
void HLAFDecision_SetTurnOffReason( const HLAFRelevantVehicle_t* const pRelVeh,
                                          HLAFTurnOffReason_t*   const pTurnOffReason
                                  )
{
  /* relevant oncoming vehicle detected ? */
  if(pRelVeh->bOncDetected == b_TRUE)
  {
    /* relevant oncoming vehicle detected */
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_ONCOMING);
  }

  /* relevant preceding vehicle detected ? */
  if(pRelVeh->bPrecDetected == b_TRUE)
  {
    /* relevant oncoming vehicle detected */
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_PRECEDING);
  }

  /* relevant oncoming object in EM object list detected ? */
  if (pRelVeh->bEMObjOncDetected == b_TRUE)
  {
    /* relevant object in EM object list detected */
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC);
  }

  /* relevant preceding object in EM object list detected ? */
  if (pRelVeh->bEMObjPrecDetected == b_TRUE)
  {
    /* relevant object in EM object list detected */
    CML_SetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_PREC);
  }

}


/* *******************************************************************************
  If any global reason is present, the high beam will turn off.
  If any vehicle based reason is present, the high beam will turn off.
  If the high beam was off and there is a keep off reason present, the high beam 
  will stay off.
******************************************************************************** */
void HLAFDecision_SetHBState(/* input */
#ifdef HLA_CHANGAN_CURVE_FEATURE
                              const HLAFVehData_t*          const pVehData,
#endif
                              const HLAFTurnOffReason_t*    const pTurnOffReason,
                              const HLAFKeepOffReason_t*    const pKeepOffReason,
                              const RTE_HLAF_HighBeamState        eHighBeamStatePrev,
                              /* output */
                                    RTE_HLAF_HighBeamState* const peHighBeamStateOut
                            )
{
#ifdef HLA_CHANGAN_CURVE_FEATURE
  if (   pVehData->ABSStatus == RTE_True
      || pVehData->ESPStatus == RTE_True )
  {              
    *peHighBeamStateOut = eHighBeamStatePrev;
  }
  else if (pTurnOffReason->Reason == 0u)
#else
  /* no turn off reason */
  if (pTurnOffReason->Reason == 0u)
#endif
  {

    /* HLA normal operating mode */
    if(eHighBeamStatePrev == (RTE_HLAF_HighBeamState)RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* keep enabled */
      *peHighBeamStateOut = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else if (pKeepOffReason->Reason == 0u)
    {
      /* no keep off -> enable high beam */
      *peHighBeamStateOut = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else
    {
      /* keep off reason set -> keep disabled */
      *peHighBeamStateOut = RTE_HLAF_HB_STATE_OFF;
    }
  }
  else
  {
#ifdef HLA_CHANGAN_CURVE_FEATURE
    // UDLC is active, don't sitch off high beam
    if (   (pVehData-> UDLCStatus == RTE_True)
        && (eHighBeamStatePrev == (RTE_HLAF_HighBeamState)RTE_HLAF_HB_STATE_FULL_ON) )
    {
      *peHighBeamStateOut = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else
    {
      /* global turn off reason */
      *peHighBeamStateOut = RTE_HLAF_HB_STATE_OFF;
    }
#else
    /* global turn off reason */
    *peHighBeamStateOut = RTE_HLAF_HB_STATE_OFF;
#endif
    
  }
}


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/

/** ************************************************************************************************
  \brief
    Check if oncoming/preceding object was detected and increase the delay counter. Compare the delay
    counter to the cpar threshold and set the detection status.

    When a relevant object was detected and the counter didn't reach the threshold value, the counter
    gets increased. When no object was detected, the counter is reset.\n
    When a relevant object was detected and the turn off delay timer is at least the threshold pbObjDet
    will be set to true, which means, that it is now relevant for the function part, which will deactivate
    the high beam. Otherwise the turn on delay will be set to zero. The turn on delay value was calculated
    before this function, and should only be != zero when the high beam is off. When setting the
    TurnOffDelayThresh to zero, this logic part will be deactivated.

    
    @startuml HLAFDecision_CheckTurnOffDelay.png
    title Check turn off delay
        
    start
    if(Object was found and\nTurn off delay time is below threshold) then (Yes)
    :Increase turn off delay time;
    elseif(Object was not found) then(Yes)
    :Set turn off delay time to zero;
    else (No)
    endif
    
    if(Object was found and\nTurn off delay time is at least or above threshold) then (Yes)
    :Set object detection status to true;
    else(No)
    :Set turn on delay to zero;
    endif
    end

    @enduml

  \pre
    Light object list was checked for relevant light objects

  \post
    None

  \param [in]      pFData             Pointer to HLA function data
  \param [in]      bStartObjDelay     Boolean which indicates that relevant vehicle was detected
  \param [in]      TurnOffDelayThresh Turn off delay threshold
  \param [in,out]  pTurnOffDelay      Pointer to counter for turn off delay
  \param [in,out]  pTurnOnDelay       Pointer to counter for turn on delay
  \param [out]     pbObjDet           Pointer to bool which is set when threshold was passed

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Based if a relevant light object was found a turn off delay counter is increased. It is above a
    threshold the object becomes active and the high beam will be turned off

  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLAFDecision_CheckTurnOffDelay( const HLAFData_t* const pFData,
                                            const boolean           bStartObjDelay,
                                            const float32           TurnOffDelayThresh,
                                                  float32*    const pTurnOffDelay,
                                                  float32*    const pTurnOnDelay,
                                                  boolean*    const pbObjDet
                                          )
{
  /* increase delay counter in case vehicle was detected 
     when no vehicle was detected counter is reset */
  if(    (bStartObjDelay == b_TRUE)
      && (*pTurnOffDelay < TurnOffDelayThresh)
     )
  {
    /* increase delay counter */
    *pTurnOffDelay += pFData->CamData.dtimeFwd_s;
  }
  else if(bStartObjDelay == b_FALSE)
  {
    /* reset delay counter */
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
    *pTurnOffDelay = 0.0f;
  }
  else
  {
    /* do nothing */
  }

  /* compare delay counter to cpar value */
  if(    (bStartObjDelay == b_TRUE)
      && (*pTurnOffDelay >= TurnOffDelayThresh)
     )
  {
    *pbObjDet = b_TRUE;
  }
  else
  {
    /* reset turn on delay */
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
    *pTurnOnDelay = 0.0f;
  }
}
/** ************************************************************************************************
  \brief
    Get turn on delay based on time-to-border of a relevant object
  
  \pre
    None

  \post
    None

  \param [in]      pIntObj            Pointer to the object to analyze
  \param [in]      Speed              Float that holds the current speed
  \param [in]      eMotorwayState     Enum that represents the motorway state
  \param [in]      eTrafficStyle      Enum that represents the traffic style
  \param [in]      pReqPorts          Pointer to request port list
  \param [in,out]  pTurnOnDelayOut_s  Pointer to float that stores the turn on delay

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Depending on the various scenarios the turn on delay will be set
     1) preceding vehicles
        a) time gap to preceding vehicle is smaller than a threshold
           that is set via parameter (currently 2 s), the timegap is
           used as delay
        b) time gap is larger and the vehicle had a low intensity,
           the delay is set resulting from the time-to-border capped
           by an upper and lower threshold defined by parameters
           (currently both thresholds are set to 3 s, so ttb is not
           relevant)
        c) time gap is larger and the vehicle has a high intensity,
           the delay is taken from a parameter (currently 3s)
        At the end, the calculated delay will checked to have a min
        delay, defined by a parameter (currently .1 s) and in case of
        running wipers to a larger min delay, also defined by a para-
        meter (currently 3 s)
     2) oncoming vehicles
        a) in a highway scenario, the delay is set to the time to border
           but limited to OncomingMinHighway and OncomingMaxHighway
           (currently 1.5 s for both)
        b) not a highway situation, depending on the detected traffic
           style, oncoming vehicle is within parameter controlled
           thresholds (dist < 30 m and lateral offset > 1.5 m), the
           delay is derived from parameter (currently 0.6 s)
        c) all other situations with oncoming vehicles, the delay is
           the minimum of time-to-border and parameter based upper
           limit (currently 1.5 s)
        At the end, derived delay will be checked against a minimum
        threshold (currently 0.6 s)

  \callsequence
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLAFDecision_TurnOnDelayTTB( const HLAObjectDataInt_t*                   const pIntObj,
                                         const float32                                     Speed,
                                         const LSD_e_EnvironmentData_HighwayState          eMotorwayState,
                                         const LSD_e_EnvironmentData_BrightnessState       eTrafficStyle,
                                         const reqHlaPrtList_t*                      const pReqPorts,
                                               float32*                              const pTurnOnDelayOut_s
                                       )
{
  const uint16 intThresholdLux = 75u; /* [lux] intensity that defines separation between low and high intensity */

  const VDYIoStateTypes_t WiperStateFlag = pReqPorts->pVehSig->VehSigAdd.State[VEH_SIG_ADD_WIPER_STATE];

  const t_DecisionParameters* pParameters = GetDecisionParameters();

  const LSD_LightObject_t* pObj = pIntObj->pLightObject;

  float32 xw = pObj->kinematic.world.x;

  /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
  float32 TurnOnDelay_s;
  float32 timegap;

  if(pIntObj->bIsRelevantPrec == b_TRUE)
  {
    /* traffic ahead */
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: magic number is justified in this context */
    timegap = xw / CML_f_Max(0.1f, Speed);

    if(timegap < pParameters->TurnOnDelay.PrecedingTimeGap_Threshold)
    {
      TurnOnDelay_s = CML_f_Max(timegap, pParameters->TurnOnDelay.PrecedingTimeGap);
    }
    else
    {
      /* timegap is larger than PrecedingTimeGap_Threshold (2.0 s) */

      /* preceding car with low intensity  (<  75 lx) -> long turn on delay, depending object ttb */
      /*               with high intensity (>= 75 lx) -> short turn on delay */
      if(pObj->attributes.intensity < intThresholdLux)
      {
        /* vehicle lost due to low intensity  */
        /* -> take ttb from Object            */
        TurnOnDelay_s = CML_f_MinMax(pReqPorts->pCPar_HlafPar->TurnOnDelay.PrecedingMaxShort, pReqPorts->pCPar_HlafPar->TurnOnDelay.PrecedingMaxLong, pObj->kinematic.timeToHlaBorder);
      }
      else
      {
        /* vehicle lost with high intensity (e.g. behind bush/ tree) */
        /* -> short turn on delay                                    */
        TurnOnDelay_s = pReqPorts->pCPar_HlafPar->TurnOnDelay.PrecedingMaxShort;
      }
    }

    /* Check if WiperState signal is available and if wiper is activated */
    if (    (    (WiperStateFlag == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
              || (WiperStateFlag == (VDYIoStateTypes_t)VDY_IO_STATE_INIT))
         && (pReqPorts->pVehSig->VehSigAdd.WiperState == (WiperState_t)VEH_SIG_ADD_WIPER_STATE_ACTIVE)
        )
    {
      /* Wiper activated -> Use at least wiper delay */
      TurnOnDelay_s = CML_f_Max(pReqPorts->pCPar_HlafPar->TurnOnDelay.PrecedingMinWiperOn, TurnOnDelay_s);
    }
    else
    {
      /* Use at least preceding min delay */
      TurnOnDelay_s = CML_f_Max(pReqPorts->pCPar_HlafPar->TurnOnDelay.PrecedingMin, TurnOnDelay_s);
    }

  }
  else
  {
    /* oncoming traffic */
    if(eMotorwayState == (LSD_e_EnvironmentData_HighwayState)RTE_HLAF_MTWY_MOTORWAY)
    {
      /* delay is set to time to border, but limited to OncomingMinHighway and OncomingMaxHighway */
      TurnOnDelay_s = CML_f_MinMax(pReqPorts->pCPar_HlafPar->TurnOnDelay.OncomingMinHighway, pReqPorts->pCPar_HlafPar->TurnOnDelay.OncomingMaxHighway, pObj->kinematic.timeToHlaBorder);
    }

    else
    {
      /* light belongs to oncoming vehicle or ego vehicle is not moving */
      TurnOnDelay_s = CML_f_Min(pObj->kinematic.timeToHlaBorder, pReqPorts->pCPar_HlafPar->TurnOnDelay.OncomingMax);
    }
    TurnOnDelay_s = CML_f_Max(pReqPorts->pCPar_HlafPar->TurnOnDelay.OncomingMin, TurnOnDelay_s);
  }

  *pTurnOnDelayOut_s = TurnOnDelay_s;
}


/** ************************************************************************************************
  \brief
    Checks if the interanl object is relevant for a high beam turn off
      

  \pre
    Function relevant vehicles are found

  \post
    None

  \param [in]  eHBState           Enum that holds the current high beam state
  \param [in]  pIntObj            Pointer to object that is analyzed
  \param [in]  pFData             Pointer to HLA function data
  \param [in]  pROI               Pointer to current ROI
  \param [in]  pKeepOnDelayParam  KeepOnDelay parameter
  \param [in]  TTBThreshold       Time to border threshold.
  \param [in]  HorAngThreshold    Threshold for absolute horizontal angle of a detected vehicle

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Per default the object is set to not relevant. Than further checks are performed.
    First there is the HLAFDecision_CheckChinaMode() function called to check if the object is compliant
    to the china mode.
    If the object is within the HLA ROI and it is compliant to the china mode the high beam state is checked.
    If the high beam is off, than the object is relevant.
    If the high beam is on and the cycles lost time is zero, it is checked whether we are on the highway or
    on a country road. In case of highway ObjectHorAng_norm is set. In case of right style traffic it is set
    to the horizontalAngle otherwise to -horizontalAngle. If the ObjectHorAng_norm is above zero, the object
    is relevant. If the timeToHlaBorder is above the TTBThreshold and the ObjectHorAng_norm is bigger than
    -HorAngThreshold is is also relevant.
    On a country road the object is relevant in the following cases:
    radiusAbs_m is below countryCurveRadius
    horizontalAngle is above zero and deltaX is above fastOvertakerDelta
    horizontalAngle is below zero and deltaX is below -fastOvertakerDelta
    abs of horizontalAngle is below HorAngThreshold and timeToHlaBorder is above TTBThreshold

    @startuml HlaDecisionRelevantVehicleToTurnOff.png
    title Find relevant object for turn off
              
    start
    :check if object is relevant according to china mode;
    if(object is within HLA ROI (x1,x2, yVehicleSplit and y2)\n and is relevant according to china mode) then (Yes)
      if(high beam state is off) then (Yes)
      :Vehicle is relevant;
      elseif(highbeam is on \n and cycles lost is zero) then (Yes)
        if(highway is detected) then (Yes)
          if(traffic style is righthand) then (Yes)
          :ObjectHorAng_norm is set to horizontalAngle;
          else(No)
          :ObjectHorAng_norm is set to -horizontalAngle;
          endif
          if(ObjectHorAng_norm is bigger than zero) then (Yes)
            :Object is relevant;
          else if(time to border is biger than TTBThreshold \n and ObjectHorAng_norm is bigger than -HorAngThreshold)
            :Object is relevant;
          else(No)
          endif
        else(No)
          if(radius is smaller than countryCurveRadius) then (Yes)
            :Object is relevant;
          elseif(horizontalAngle is bigger than zero \n and deltaX is bigger than fastOvertakerDelta)
            :Object is relevant;
          elseif(horizontalAngle is smaller than zero \n and deltaX is smaller than -fastOvertakerDelta)
            :Object is relevant;
          elseif(abs of horizontalAngle is smaller than HorAngThreshold \n and timeToHlaBorder is bigger than TTBThreshold)
            :Object is relevant;
          else(No)
          endif
        endif
      else(No)
      endif
    else(No)
    endif

    end
          
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static boolean HLAFDecision_RelevantVehicle2TurnOff( const RTE_HLAF_HighBeamState                  eHBState,
                                                     const HLAObjectDataInt_t*               const pIntObj,
                                                     const HLAFData_t*                       const pFData,
                                                     const LSD_LightObjectList_Roi_t*        const pROI,
                                                     const RTE_HLAF_ParameterKeepOnDelay_t*  const pKeepOnDelayParam,
                                                     const float32                                 TTBThreshold,
                                                     const float32                                 HorAngThreshold
                                                   )
{
  const float32 countryCurveRadius = 120.0f;  /* [m]   radius for a curve on a country road */
  const sint16  fastOvertakerDelta = 3;       /* [pix] delta pixels for fast moving objects */
  boolean bRelevantVeh = b_FALSE;
  boolean bRelevantChina;

  const LSD_LightObject_t* pObj = pIntObj->pLightObject;

  float32 ObjectHorAng_norm;

  /* check if object is relevant according to china mode */
  bRelevantChina = HLAFDecision_CheckChinaMode( eHBState,
                                                pIntObj,
                                                pKeepOnDelayParam
                                              );

  /* Assumption is that only real vehicles will be selected here */
  /* object within HLA ROI and relevant regarding china mode */

  if (bRelevantChina == b_TRUE)

  {
    /* relevant in case high beam is off*/
    if (eHBState == (RTE_HLAF_HighBeamState)RTE_HLAF_HB_STATE_OFF)
    {
      bRelevantVeh = b_TRUE;
    }
    /* high beam is full on -> do further checks */
    else if(    (eHBState == (RTE_HLAF_HighBeamState)RTE_HLAF_HB_STATE_FULL_ON)
             && (pObj->general.cyclesLost == 0u)
           )
    {
      if(pFData->DecisionOut.eHighwayState == (LSD_e_EnvironmentData_HighwayState)LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED)
      {
        /* highway */
        /* normalized object angle */  
        if (pFData->DecisionOut.eTrafficStyle == (LSD_e_EnvironmentData_BrightnessState)LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC)
        {
          ObjectHorAng_norm =  pObj->kinematic.world.horizontalAngle;
        }
        else
        {
          ObjectHorAng_norm = -pObj->kinematic.world.horizontalAngle;
        }
        /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
        if(ObjectHorAng_norm > 0.0f)
        {
          /* vehicle on the left side */
          bRelevantVeh = b_TRUE;
        }
        else if(   (pObj->kinematic.timeToHlaBorder > TTBThreshold)
                && (ObjectHorAng_norm > (-HorAngThreshold))
          )
        {
          /* vehicle on the right side */
          bRelevantVeh = b_TRUE;
        }
        else
        {
          /* do nothing */
        }
      }
      else
      {
        /* country road */
        if(pFData->CamData.radiusAbs_m < countryCurveRadius)
        {
          /* small radius */
          bRelevantVeh = b_TRUE;
        }
        /* vehicle moves fast into FOV            */
        /* overtaking car of oncoming in a curve  */
        /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
        else if(    (pObj->kinematic.world.horizontalAngle > 0.0f)
                 && (pObj->kinematic.camera.deltaX > fastOvertakerDelta)
               )
        {
          /* left side fast moving vehicle into FOV*/
          bRelevantVeh = b_TRUE;
        }
        /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
        else if(   (pObj->kinematic.world.horizontalAngle < 0.0f)
                && (pObj->kinematic.camera.deltaX < -(fastOvertakerDelta))
               )
        {
          /* right side fast moving vehicle into FOV */
          bRelevantVeh = b_TRUE;
        }
        else if(    (CML_f_Abs(pObj->kinematic.world.horizontalAngle) < HorAngThreshold)
                 && (pObj->kinematic.timeToHlaBorder > TTBThreshold)
               )
        {
          /* object within angle threshold and time to border is high enough */
          bRelevantVeh = b_TRUE;
        }
        else
        {
          /* do nothing */
        }
      }
    }
    else
    {
      /* do nothing */
    }
  }

  return(bRelevantVeh);
}

/** ************************************************************************************************
  \brief
    Checks if object is compliant to china mode

  \pre
    None

  \post
    None

  \param [in]  eHBState           Enum that holds the current high beam state
  \param [in]  pIntObj            Pointer to object that is analyzed
  \param [in]  pKeepOnDelayParam  KeepOnDelay parameter

  \return
    boolean if object is compliant to china mode

  \globals
    None

  \InOutCorrelation
    Depending on the high beam state it is checked if an object is compliant to the china mode.
    If the high beam is off, the oncoming vehicles are always considered as relevant. The preceding
    vehicles distance must be below the coding parameter distancePrecedingVehicleMax.
    If the high beam is on the oncoming vehicles distance must be below distanceOncomingVehicle.
    In case of a preceding object it must be closer than distancePrecedingVehicleMin to be compliant.

    This feature is normally deactivated via coding. The coding parameters are set to very high value so
    that all oncoming and preceding objects are relevant.

    @startuml
    title Check china mode

    start
    :Object is set to not relevant;
    if (highbeam state is off \nand (object is relevant oncoming or x world position is below distancePrecedingVehicleMax)) then (Yes)
      :Object is relevant;
    elseif(highbeam state is on) then (Yes)
      if(object is oncoming \n and x world position if below distanceOncomingVehicle) then (Yes)
        :Object is relevant;
      elseif(object is preceding \n and x world position if below distancePrecedingVehicleMin) then (Yes)
        :Object is relevant;
      else(No)
      endif
    endif
    :return relevant flag;
    end
    
    @enduml
    
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static boolean HLAFDecision_CheckChinaMode( const RTE_HLAF_HighBeamState                  eHBState,
                                            const HLAObjectDataInt_t*               const pIntObj,
                                            const RTE_HLAF_ParameterKeepOnDelay_t*  const pKeepOnDelayParam
                                          )
{
  const LSD_LightObject_t* pObj = pIntObj->pLightObject;
  float32 ObjPos_xw = pObj->kinematic.world.x;

  boolean IsRelevant = b_FALSE;

  if(     (eHBState == (RTE_HLAF_HighBeamState)RTE_HLAF_HB_STATE_OFF)
      && (    (pIntObj->bIsRelevantOnc == b_TRUE)
           || (ObjPos_xw < (float32)pKeepOnDelayParam->distancePrecedingVehicleMax)
         )
    )
  {
    IsRelevant = b_TRUE;
  }
  else if(eHBState == (RTE_HLAF_HighBeamState)RTE_HLAF_HB_STATE_FULL_ON)
  {
    /* HI17 logic for china mode, which can be disabled by coding */
    /* In case of a preceding and oncoming vehicle HB shall only be turned off if vehicle is close enough */
    if(    (pIntObj->bIsRelevantOnc == b_TRUE)
        && (ObjPos_xw < (float32)pKeepOnDelayParam->distanceOncomingVehicle)
      )
    {
      IsRelevant = b_TRUE;
    }
    else if(    (pIntObj->bIsRelevantPrec == b_TRUE)
             && (ObjPos_xw < (float32)pKeepOnDelayParam->distancePrecedingVehicleMin)
           )
    {
      IsRelevant = b_TRUE;
    }
    else
    {
      /* do nothing */
    }

  }
  else
  {
    /* do nothing */
  }

  return(IsRelevant);
}
