/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision_keepoff.c

  DESCRIPTION:            HLAF decision for KeepOffReasons.

  CREATION DATE:          2014-11-03
    
  CPU:                    Independent

  VERSION:                $Revision: 1.13.1.1 $
**************************************************************************** */
/* PRQA S 3121 EOF # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_decision_keepoff.h"
#include "hla_errorhandling.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_STD_RMAX 10000.0f ///< maximum radius threshold in case preceding vehicle was lost

/*****************************************************************************
  LOCAL TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS 
*****************************************************************************/

static void HLAFDecSetKOR_SmallRadius( 
#ifdef HLA_CHANGAN_CURVE_FEATURE
                                       const HLAFVehData_t*               const pVehData,
#endif
                                       const HLAFCameraData_t*            const pCamData,
                                       const RTE_HLAF_HighBeamState             eHighBeamStatePrev,
                                       const t_DecisionParametersKeepOff* const pPar,
                                             HLAFKeepOffSmallRadius_t*    const pSmallRadius,
                                             HLAFKeepOffReason_t*         const pKeepOffReason
                                     );

static void HLAFDecSetKOR_MinTimeHBoff( const HLAFCameraData_t*            const pCamData,
                                        const RTE_HLAF_HighBeamState             eHighBeamStatePrev,
                                        const t_DecisionParametersKeepOff* const pParKeepOff,
                                              HLAFKeepOffMinTimeHBOff_t*   const pMinTimeOff,
                                              HLAFKeepOffReason_t*         const pKeepOffReason
                                      );

static void HLAFDecSetKOR_TurnOnDelay( const HLAFData_t*                      const pFData,
                                       const RTE_HLAF_HighBeamState                 eHighBeamStatePrev,
                                       const HLAFRelevantVehicle_t*           const pRelVeh,
                                       const t_DecisionParametersTurnOnDelay* const pPar,
                                             HLAFKeepOffReason_t*             const pKeepOffReason
                                     );

static void HLAFDecSetKOR_FogBadWeather( const reqHlaPrtList_t*      const pReqPorts,
                                         const HLAFData_t*           const pFData,
                                               HLAFKeepOffReason_t*  const pKeepOffReason
                                       );

static void HLAFDecSetKOR_MayBeCity( const HLAFData_t*                  const pFData,
                                     const RTE_HLAF_HighBeamState             eHighBeamStatePrev,
                                     const HLAFTurnOffReason_t*         const pTurnOffReason,
                                     const HLAFRelevantVehicle_t*       const pRelVeh,
                                     const t_DecisionParametersKeepOff* const pParKeepOff,
                                           HLAFKeepOffReason_t*         const pKeepOffReason
                                   );


/*****************************************************************************
  GLOBAL FUNCTIONs DEFINITION
*****************************************************************************/

/* *******************************************************************************
  Function controls the flow to set all keep off reasons according to the current
  situation.
******************************************************************************** */
void HLAFDecision_SetKeepOffReason( const reqHlaPrtList_t*                 const pReqPorts,
                                    const HLAFData_t*                      const pFData,
                                    const t_DecisionParametersKeepOff*     const pParKeepOff,
                                    const t_DecisionParametersTurnOnDelay* const pParTurnOnDelay,
                                    const RTE_HLAF_HighBeamState                 eHighBeamStatePrev,
                                    const HLAFRelevantVehicle_t*           const pRelVeh,
                                    const HLAFTurnOffReason_t*             const pTurnOffReason,
                                          HLAFKeepOffReason_t*             const pKeepOffReason
                                   )
{
  /* Init Keep Off Reason */
  pKeepOffReason->Reason = 0;

  /* velocity will fall below activation speed in some seconds */
  /* -> keep full HB off                                       */
  if(pFData->DecisionData.Speed.keepOffHLABySpeed > 0u)
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC);
  }

  /* may be city detected                                           */
  /* keep full HB off because city will be detected in same Frames  */
  HLAFDecSetKOR_MayBeCity(pFData,
                          eHighBeamStatePrev,
                          pTurnOffReason,
                          pRelVeh,
                          pParKeepOff,
                          pKeepOffReason
                         );

  /* small radius -> keep HB off */
  HLAFDecSetKOR_SmallRadius(
#ifdef HLA_CHANGAN_CURVE_FEATURE
                            &pFData->VehData,
#endif
                            &pFData->CamData,
                            eHighBeamStatePrev,
                            pParKeepOff,
                            &pKeepOffReason->SmallRadius, 
                            pKeepOffReason
                           );

  /* keep HB off for a minimal time */
  HLAFDecSetKOR_MinTimeHBoff( &pFData->CamData,
                              eHighBeamStatePrev,
                              pParKeepOff,
                              &pKeepOffReason->MinTimeHBoff,
                              pKeepOffReason
                            );

  /* keep HB off depending on the TTB of the target vehicle */
  HLAFDecSetKOR_TurnOnDelay(pFData,
                            eHighBeamStatePrev,
                            pRelVeh,
                            pParTurnOnDelay,
                            pKeepOffReason
                           );

  /* fog and bad weather */
  HLAFDecSetKOR_FogBadWeather( pReqPorts,
                               pFData,
                               pKeepOffReason
                             );
  /* Reduce keep off reasons to a minimum if activated by parameters/coding */
  /* This is a special feature for Toyota AHS */
  if (    (pParKeepOff->bUseMinimumKOR == b_TRUE)
       && (pReqPorts->pCPar_HlafPar->Matrix.MaxNumGlarefreeArea != 0u)
      )
  {
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_POT_VEH_ONC);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC);
    CML_ClearBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB);
  }
}


/****************************************************************************
 * LOCAL FUNCTION DEFINTIONS
 *****************************************************************************/


/* *******************************************************************************
  @fn             HLAFDecSetKOR_SmallRadius                                   */ /*!

  @brief          Keeps high beam off as long as curvature is very small.

  @description    Decrements the small radius keep off delay and in case the curve
                  has still a too small radius it will be reset to the parameter
                  based delay (currently 0 s)

  @param[in]      pCamData            Pointer to camera data
  @param[in]      eHighBeamStatePrev  Enum that holds the previous high beam state
  @param[in]      pPar                Pointer to function parameters
  @param[in,out]  pSmallRadius        Pointer to small radius keep off history
  @param[in,out]  pKeepOffReason      Pointer to keep off reasons

  @return         void
******************************************************************************** */
static void HLAFDecSetKOR_SmallRadius( 
#ifdef HLA_CHANGAN_CURVE_FEATURE
                                       const HLAFVehData_t*               const pVehData,
#endif
                                       const HLAFCameraData_t*            const pCamData,
                                       const RTE_HLAF_HighBeamState             eHighBeamStatePrev,
                                       const t_DecisionParametersKeepOff* const pPar,
                                             HLAFKeepOffSmallRadius_t*    const pSmallRadius,
                                             HLAFKeepOffReason_t*         const pKeepOffReason
                                     )
{
  /* decrement delay timer */
  pSmallRadius->DelayTimer_s -= pCamData->dtimeFwd_s;
  pSmallRadius->DelayTimer_s = CML_f_Max(pSmallRadius->DelayTimer_s, 0.0f);
  
#ifdef HLA_CHANGAN_CURVE_FEATURE
  if (   (pVehData->swaAbs_deg      > pPar->smallRadiusSwaThreshold)
      || (pVehData->lataccAbs_ms2   > pPar->smallRadiusLataccThreshold)
      || (pVehData->yawrateAbs_rads > pPar->smallRadiusYawrateThreshold) 
      && (eHighBeamStatePrev     == (uint8)RTE_HLAF_HB_STATE_OFF) )
#else
  if(   (pCamData->radiusAbs_m < pPar->smallRadiusRadius2TurnsOnThres)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
    )
#endif
  {
    pSmallRadius->DelayTimer_s = pPar->smallRadiusTurnOnDelay;
  }
  /* smallRadius in hold ? */
  /* wait some cycles after curve with small radius due to s-curves */
  if(pSmallRadius->DelayTimer_s > 0.0f)
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS);
  }
}


/* *******************************************************************************
  @fn             HLAFDecSetKOR_MinTimeHBoff                                  */ /*!

  @brief          Keeps high beam off for a minimal time.

  @description    The high beam will stay off for a short delay in all situations.
                  The minimum delay is provided via parameter (currently 2 s) and
                  gets adjusted according to the last valid turn off reason by a
                  penalty timer (preceding, oncoming, etc.).

  @param[in]      pCamData            Pointer to camera data
  @param[in]      eHighBeamStatePrev  Enum that holds the previous high beam state
  @param[in]      pParKeepOff         Pointer to function parameters
  @param[in,out]  pMinTimeOff         Pointer to min time keep off history
  @param[in,out]  pKeepOffReason      Pointer to keep off reasons

  @return         void
******************************************************************************** */
static void HLAFDecSetKOR_MinTimeHBoff( /* input */
                                       const HLAFCameraData_t*            const pCamData,
                                       const RTE_HLAF_HighBeamState             eHighBeamStatePrev,
                                       const t_DecisionParametersKeepOff* const pParKeepOff,
                                       /* history */
                                             HLAFKeepOffMinTimeHBOff_t*   const pMinTimeOff,
                                       /* output */
                                             HLAFKeepOffReason_t*         const pKeepOffReason
                                      )
{
  /* refuse turning high beams on for a certain time after turning high beams off */
  if(eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
  {
    /* previous state = HB off*/
    pMinTimeOff->HBOffTimer_s -= pCamData->dtimeFwd_s;
    pMinTimeOff->HBOffTimer_s = CML_f_Max(pMinTimeOff->HBOffTimer_s, 0.0f);
  }
  else
  {
    /* previous state = HB on */
    /* set minimum number of cycles high beams has to be turned off */
    pMinTimeOff->HBOffTimer_s = pParKeepOff->minTimeHBOff_s;
  }
  if(   (pMinTimeOff->HBOffTimer_s > 0.0f)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
    )
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MIN_TIME_HB_OFF);
  }
}

/* *******************************************************************************
  @fn             HLAFDecSetKOR_TurnOnDelay                                   */ /*!

  @brief          Keeps high beam off after vehicle is lost.

  @description    Depending on the type of the present vehicle the turn on delay
                  will be set accordingly.

  @param[in]      pFData              Pointer to HLA function data
  @param[in]      eHighBeamStatePrev  Enum that holds the previous high beam state
  @param[in]      pRelVeh             Pointer to relevant vehicle
  @param[in]      pPar                Pointer to function parameters
  @param[in,out]  pKeepOffReason      Pointer to keep off reasons

  @return         void
******************************************************************************** */
static void HLAFDecSetKOR_TurnOnDelay( /* input */
                                       const HLAFData_t*                      const pFData,
                                       const RTE_HLAF_HighBeamState                 eHighBeamStatePrev,
                                       const HLAFRelevantVehicle_t*           const pRelVeh,
                                       const t_DecisionParametersTurnOnDelay* const pPar,
                                       /* history and output */
                                             HLAFKeepOffReason_t*             const pKeepOffReason
                                     )
{
  /* decrement turn on/ init timer */
  pKeepOffReason->TurnOnDelay.InitTimer_s   -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.InitTimer_s    = CML_f_Max(pKeepOffReason->TurnOnDelay.InitTimer_s, 0.0f);
  
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s  = CML_f_Max(pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s, 0.0f);

  pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s  = CML_f_Max(pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s, 0.0f);

  /* load init timer */
  if( (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_NOT_AVL) == b_TRUE)
    )
  {
    pKeepOffReason->TurnOnDelay.InitTimer_s = pPar->initialTurnOnDelay;
  }  
  
  if(   (pRelVeh->bOncDetected == b_TRUE)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
    )
  {
    pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s = pRelVeh->Onc_s;
  }
  
  if(   (pRelVeh->bPrecDetected == b_TRUE)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
    )
  {
    pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s = pRelVeh->Prec_s;
  }

  if(pKeepOffReason->TurnOnDelay.InitTimer_s > 0.0f)
  {
    /* keep HB off */
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT);
  }

  if(pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s > 0.0f)
  {
    /* keep HB off */
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC);
  }

  if(pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s > 0.0f)
  {
    /* keep HB off */
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC);
  }
}


/** ************************************************************************************************
  \brief  
    Keep high beam off after fog and/or bad weather was detected
  
  \pre
    None

  \post
    None

  \param[in]       pReqPorts       request port pointer list
  \param[in]       pFData          pointer to hlaf data
  \param[in, out]  pKeepOffReason  pointer to keep off reason data

  \return
    None

  \globals
    None

  \InOutCorrelation
    The delay timers are reduced by the passed time since the last call.

    Then it is checked if the fog or bad weather turn off reason is set. If this is the case the
    apropriate delay timers are set to the coding values (currently the Fog turn on delay is used
    for both of them).

    As long as the delay timers are not set the keep off reason is set in the keep off reason bitfield.
    
  \callsequence
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void HLAFDecSetKOR_FogBadWeather( const reqHlaPrtList_t*      const pReqPorts,
                                         const HLAFData_t*           const pFData,
                                               HLAFKeepOffReason_t*  const pKeepOffReason
                                       )
{
  /* decrement delay timer */
  pKeepOffReason->FogBadWeather.DelayTimer_Fog -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->FogBadWeather.DelayTimer_Fog = CML_f_Max(pKeepOffReason->FogBadWeather.DelayTimer_Fog, 0.0f);

  pKeepOffReason->FogBadWeather.DelayTimer_BadWeather -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->FogBadWeather.DelayTimer_BadWeather = CML_f_Max(pKeepOffReason->FogBadWeather.DelayTimer_BadWeather, 0.0f);

  /* load init timer */
  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_FOG) == b_TRUE)
  {
    pKeepOffReason->FogBadWeather.DelayTimer_Fog = pReqPorts->pCPar_HlafPar->TurnOnDelay.Fog;
  }

  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER) == b_TRUE)
  {
    /* use same delay for bad weather and fog */
    pKeepOffReason->FogBadWeather.DelayTimer_BadWeather = pReqPorts->pCPar_HlafPar->TurnOnDelay.Fog;
  }

  /* set keep off reasons for fog and bead weather */
  if(pKeepOffReason->FogBadWeather.DelayTimer_Fog > 0.0f)
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_FOG);
  }

  if(pKeepOffReason->FogBadWeather.DelayTimer_BadWeather > 0.0f)
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_BAD_WEATHER);
  }
}


/* *******************************************************************************
  @fn             HLAFDecSetKOR_MayBeCity                                     */ /*!

  @brief          Sets the keep off reason if a potential city is detected.

  @description    Sets the keep off reason in case of a potential city is detected
                  and also sets a delay if a relevant vehicle is present but the
                  appropriate delay timer is not yet set.

  @param[in]      pFData              Pointer to HLA function data
  @param[in]      eHighBeamStatePrev  Enum that holds the previous high beam state
  @param[in]      pTurnOffReason      Pointer to turn off reasons
  @param[in]      pRelVeh             Pointer to relevant vehicle
  @param[in]      pParKeepOff         Pointer to function parameters
  @param[in,out]  pKeepOffReason      Pointer to keep off reasons

  @return         void
******************************************************************************** */
static void HLAFDecSetKOR_MayBeCity(  /* input */
                                     const HLAFData_t*                  const pFData,
                                     const RTE_HLAF_HighBeamState             eHighBeamStatePrev,
                                     const HLAFTurnOffReason_t*         const pTurnOffReason,
                                     const HLAFRelevantVehicle_t*       const pRelVeh,
                                     const t_DecisionParametersKeepOff* const pParKeepOff,
                                     /* history and output */
                                           HLAFKeepOffReason_t*         const pKeepOffReason
                                   )
{
  /* decrement delay timer */
  pKeepOffReason->MayBeCity.TurnOnTimer_Onc -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->MayBeCity.TurnOnTimer_Onc  = CML_f_Max(pKeepOffReason->MayBeCity.TurnOnTimer_Onc, 0.0f);

  pKeepOffReason->MayBeCity.TurnOnTimer_Prec -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->MayBeCity.TurnOnTimer_Prec  = CML_f_Max(pKeepOffReason->MayBeCity.TurnOnTimer_Prec, 0.0f);

  pKeepOffReason->MayBeCity.TurnOnTimer_Glob -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->MayBeCity.TurnOnTimer_Glob  = CML_f_Max(pKeepOffReason->MayBeCity.TurnOnTimer_Glob, 0.0f);


  /* load TurnOnTimer_Onc */
  if(   (pRelVeh->bOncDetected == b_TRUE)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
     && (pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_MAYBE)
    )
  {
    /* load delay */
    pKeepOffReason->MayBeCity.TurnOnTimer_Onc = pParKeepOff->MayBeCity.Delay_Onc;
  }

  /* load TurnOnTimer_Prec */
  if(   (pRelVeh->bPrecDetected == b_TRUE)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
     && (pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_MAYBE)
    )
  {
    /* load delay */
    pKeepOffReason->MayBeCity.TurnOnTimer_Prec = pParKeepOff->MayBeCity.Delay_Prec;
  }

  /* load TurnOnTimer_Glob */
  if(   (pTurnOffReason->Reason > 0u)
     && (eHighBeamStatePrev == (uint8)RTE_HLAF_HB_STATE_OFF)
     && (pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_MAYBE)
    )
  {
    /* load delay */
    pKeepOffReason->MayBeCity.TurnOnTimer_Glob = pParKeepOff->MayBeCity.Delay_Global;
  }

  /* MaybeCity_Onc */
  if(   (pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_MAYBE)
     && (pKeepOffReason->MayBeCity.TurnOnTimer_Onc  > 0.0f)
    )
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC);
  }

  /* MaybeCity_Prec */
  if(   (pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_MAYBE)
     && (pKeepOffReason->MayBeCity.TurnOnTimer_Prec  > 0.0f)
    )
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC);
  }

  /* MaybeCity_Glob */
  if(   (pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_MAYBE)
     && (pKeepOffReason->MayBeCity.TurnOnTimer_Glob  > 0.0f)
    )
  {
    CML_SetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB);
  }
}
