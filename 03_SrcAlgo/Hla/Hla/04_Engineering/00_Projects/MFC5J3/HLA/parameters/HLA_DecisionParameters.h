/** \file ******************************************************************
COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

PROJECT:                MFC4xx

COMPONENT:              HLA

FILENAME:               HLA_DecisionParameters.h

DESCRIPTION:            Parameters of decision module

CREATION DATE:          2018-05-14

CPU:                    Independent

VERSION:                $Revision: 1.9 $
**************************************************************************** */
/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_DECISION_PARAMETERS_H
#define H_HLA_DECISION_PARAMETERS_H

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "hlaf_type.h"

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* TYPEDEFS
*****************************************************************************/
/// \brief City detection parameters
typedef struct
{
  float32 minCityDist_m;      ///< Stay in city state for min. distance \phys_unit m
  float32 minCityTime_s;      ///< Stay in city state for min time \phys_unit s
  float32 maxMayBeCityDist_m; ///< Stay only for maximal distance in MayBeCity \phys_unit m
  float32 minMayBeCityDist_m; ///< Stay minimal distance in MayBeCity \phys_unit m
  float32 minMayBeCityTime_s; ///< Stay minimal time in MayBeCity \phys_unit s
} t_DecisionParametersCity;

/// \brief Blockage detection parameters
typedef struct
{
  float32 ClearMeas2Blockage_DistThres;   ///< maximum distance after a valid blockage output should be available \phys_unit m
  float32 ClearMeas2Blockage_TimeThres;   ///< maximum time after a valid blockage output should be available \phys_unit s
  float32 ClearMeas2NoBlockage_DistThres; ///< distance that needs to be traveled before going from clear meas to blockage or condensation \phys_unit m
} t_DecisionParametersBlockage;

/// \brief Weather detection parameters
typedef struct
{
  float32 WiperTriggerEnterTime;    ///< time that wiper stage is needed to be in high for weather to be considered as turn off reason \phys_unit s
  float32 WiperTriggerLeaveTime;    ///< time that wiper stage is needed to be in low for weather to be removed as turn off reason \phys_unit s
  WiperStage_t WiperStageThreshold; ///< wiper speed that is needed to be surpassed to enable a decision
} t_DecisionParametersWeather;

/// \brief Turn on delay parameter set, based on time to border of the vehicle
typedef struct
{
  float32 initialTurnOnDelay;           ///< Initial turn on delay in HLA activation. \phys_unit s
  float32 OncomingMin_DistThreshold;    ///< Minimum distance to oncoming vehicle. \phys_unit m
  float32 OncomingMin_LatDistThreshold; ///< Minimum lateral distance to oncoming vehicle \phys_unit m
  float32 PrecedingTimeGap_Threshold;   ///< Time gap threshold for preceding vehicles \phys_unit s
  float32 PrecedingTimeGap;             ///< Maximum time gap = max turn on delay
} t_DecisionParametersTurnOnDelay;

/// \brief Keep high beam off when potential vehicle is detected
typedef struct
{
  float32 Delay_Onc;                ///< Maximum keep off delay after oncoming \phys_unit s
  float32 Delay_Prec;               ///< Maximum keep off delay after preceding \phys_unit s
  float32 Delay_Glob;               ///< Maximum keep off delay after global turn off \phys_unit s
  uint8   high_probability_vehicle; ///< needed probability for track to be a vehicle with high probability
  uint8   low_probability_vehicle;  ///< needed probability for track to be a vehicle with low probability
} t_DecisionParametersKeepOffPotVeh;

/// \brief Conditions for turning off HB
typedef struct
{
  float32 Delay_Onc;    ///< Maximal turn on delay after oncoming passed (matrix or plus: probably partial HB on) \phys_unit s
  float32 Delay_Prec;   ///< Maximal turn on delay after preceding vehicle gets lost (matrix or plus: probably partial HB on) \phys_unit s
  float32 Delay_Global; ///< Maximal turn on delay after global turn off reason (full HB off) \phys_unit s
} t_DecisionParametersKeepOffMayBeCity;

/// \brief Conditions for keeping HB off
typedef struct
{
  float32                              maxDist2Cover;                  ///< Maximum distance to keep high beam off when preceding car is lost.    
  float32                              minTimeHBOff_s;                 ///< Parameter for keep off HB for a minimal time                           
  t_DecisionParametersKeepOffPotVeh    KeepOffPotVeh;                  ///< Parameter for keep off HB when potential vehicle is detected           
  t_DecisionParametersKeepOffMayBeCity MayBeCity;                      ///< Parameter for keep off HB when may be city is detected                 
  uint16                               minTraceTimeSO;                 ///< Parameter for min trace time to keep HB off when overtaking car
  uint16                               minClassConfidenceSO;           ///< Parameter for min class confidence to keep HB off when overtaking car
  uint16                               minProbOfExSO;                  ///< Parameter for min probability of existence to keep HB off when overtaking car
  float32                              maxDeltaXSO;                    ///< Parameter for max delta x movement to keep HB off when overtaking car  
  float32                              maxLateralOffsetSO;             ///< Parameter for max lateral offset [m] to keep HB off when overtaking car
  float32                              minDistanceSO;                  ///< Parameter for min distance for overtaking car \phys_unit m
  float32                              maxDeltaSpeedSO;                ///< Parameter for max delta speed between ego vehicle and overtaking car \phys_unit m/s
  float32                              smallRadiusRadius2TurnsOnThres; ///< radius threshold for small radius keep off reason
  float32                              smallRadiusSwaThreshold;        ///< steering wheel angle threshold for small radius keep off reason
  float32                              smallRadiusYawrateThreshold;    ///< yaw rate threshold for small radius keep off reason
  float32                              smallRadiusLataccThreshold;     ///< lateral acceleration threshold for small radius keep off reason
  float32                              smallRadiusTurnOnDelay;         ///< turn on delay for small radius keep off reason
  boolean                              bUseMinimumKOR;                 ///< Reduce the keep off reasons to a minimum
} t_DecisionParametersKeepOff;

/// \brief Conditions for scene info
typedef struct
{
  float32 distanceOncoming;   ///< Oncoming vehicles are only relevant is below this threshold
  float32 distancePreceding;  ///< Preceding vehicles are only relevant is below this threshold
}t_DecisionParametersSceneInfo;

typedef struct
{
  float32 swaThreshold;       ///< steering wheel angle to decide a small radius
  float32 yawrateThreshold;   ///< yaw rate to decide a small radius
  float32 lataccThreshold;    ///< lateral acceleration to decide a small radius
}t_DecisionParametersSmallRadius;

/// \brief Decision parameters.
typedef struct
{
  t_DecisionParametersCity        City;                  ///< city detection parameters 
  t_DecisionParametersBlockage    Blockage;              ///< blockage detection parameters
  t_DecisionParametersWeather     Weather;               ///< weather detection parameters
  t_DecisionParametersTurnOnDelay TurnOnDelay;           ///< turn on delay based on TTB of the tracks
  t_DecisionParametersKeepOff     KeepOff;               ///< conditions for keeping HB off
  t_DecisionParametersSceneInfo   SceneInfo;             ///< scene info parameters
  float32                         LSDObjHorAngThreshold; ///< horizontal angle threshold for LSD objects \phys_unit deg \min -90 \max 90
} t_DecisionParameters;

/****************************************************************************
* GLOBAL FUNCTIONS DECLARATION
*****************************************************************************/

/** ************************************************************************************************ 
  \brief
    Return pointer to HLA decision parameters
  
  \pre
    none
  \post
    none
  
  \return
    pointer to analysis parameter
  
  \globals
   None
  
  \InOutCorrelation
   None
  
  \callsequence
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
const t_DecisionParameters* GetDecisionParameters(void);

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_DECISION_PARAMETERS_H */
