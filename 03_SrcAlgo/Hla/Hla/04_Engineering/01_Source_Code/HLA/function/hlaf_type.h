/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_type.h

  DESCRIPTION:            HLAF global type definitions.

  CREATION DATE:          2011-02-23
  
  CPU:                    Independent

  VERSION:                $Revision: 1.22.2.3 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_TYPE_H
#define H_HLAF_TYPE_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_defs.h"
#include "hla_rta_type.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLAF_TURN_OFF_REASON_MAX_CNT 255  ///< Maximum number of turn off reason counter

#define HLAF_TURN_OFF_REASON_NOT_RELEASED                      ((uint32)1u <<  0u)  ///< turn off reason bit for not released
#define HLAF_TURN_OFF_REASON_NOT_ACTIVE                        ((uint32)1u <<  1u)  ///< turn off reason bit for not active
#define HLAF_TURN_OFF_REASON_NOT_AVL                           ((uint32)1u <<  2u)  ///< turn off reason bit for not available
#define HLAF_TURN_OFF_REASON_BLOCKAGE                          ((uint32)1u <<  3u)  ///< turn off reason bit for blockage
#define HLAF_TURN_OFF_REASON_FOG                               ((uint32)1u <<  4u)  ///< turn off reason bit for fog
#define HLAF_TURN_OFF_REASON_BRIGHTNESS                        ((uint32)1u <<  5u)  ///< turn off reason bit for brightness
#define HLAF_TURN_OFF_REASON_CITY                              ((uint32)1u <<  6u)  ///< turn off reason bit for city
#define HLAF_TURN_OFF_REASON_TUNNEL                            ((uint32)1u <<  7u)  ///< turn off reason bit for tunnel
#define HLAF_TURN_OFF_REASON_MIN_SPEED                         ((uint32)1u <<  8u)  ///< turn off reason bit for min speed
#define HLAF_TURN_OFF_REASON_MAX_SPEED                         ((uint32)1u <<  9u)  ///< turn off reason bit for max speed
#define HLAF_TURN_OFF_REASON_ONCOMING                          ((uint32)1u << 10u)  ///< turn off reason bit for oncoming
#define HLAF_TURN_OFF_REASON_PRECEDING                         ((uint32)1u << 11u)  ///< turn off reason bit for preceding
#define HLAF_TURN_OFF_REASON_EM_OBJECT_ONC                     ((uint32)1u << 12u)  ///< turn off reason bit for oncoming em object
#define HLAF_TURN_OFF_REASON_EM_OBJECT_PREC                    ((uint32)1u << 13u)  ///< turn off reason bit for preceding em object
#define HLAF_TURN_OFF_REASON_BAD_WEATHER                       ((uint32)1u << 14u)  ///< turn off reason bit for bad weather
#define HLAF_TURN_OFF_REASON_RADAR_OBJECT                      ((uint32)1u << 15u)  ///< turn off reason bit for radar object

#define HLAF_KEEP_OFF_REASON_SPEED_ACC                         ((uint32)1u <<   0u) ///< keep off reason bit for speed acceleration
#define HLAF_KEEP_OFF_REASON_SMALL_RADIUS                      ((uint32)1u <<   1u) ///< keep off reason bit for small radius
#define HLAF_KEEP_OFF_REASON_MIN_TIME_HB_OFF                   ((uint32)1u <<   2u) ///< keep off reason bit for min time high beam off
#define HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT                ((uint32)1u <<   3u) ///< keep off reason bit for turn on delay init
#define HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC                 ((uint32)1u <<   4u) ///< keep off reason bit for turn on delay oncoming
#define HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS    ((uint32)1u <<   5u) ///< keep off reason bit for turn on delay oncoming truck lights
#define HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC                ((uint32)1u <<   6u) ///< keep off reason bit for turn on delay preceding
#define HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER ((uint32)1u <<   7u) ///< keep off reason bit for turn on delay preceding slow overtaker
#define HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST                 ((uint32)1u <<   8u) ///< keep off reason bit for preceding vehicle lost
#define HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC                    ((uint32)1u <<   9u) ///< keep off reason bit for maybe city oncoming
#define HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC                   ((uint32)1u <<  10u) ///< keep off reason bit for maybe city preceding
#define HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB                   ((uint32)1u <<  11u) ///< keep off reason bit for maybe city glob
#define HLAF_KEEP_OFF_REASON_POT_VEH_ONC                       ((uint32)1u <<  12u) ///< keep off reason bit for potential vehicle oncoming
#define HLAF_KEEP_OFF_REASON_POT_VEH_PREC                      ((uint32)1u <<  13u) ///< keep off reason bit for potential vehicle preceding
#define HLAF_KEEP_OFF_REASON_POT_VEH_GLOB                      ((uint32)1u <<  14u) ///< keep off reason bit for potential vehicle glob
#define HLAF_KEEP_OFF_REASON_FOG                               ((uint32)1u <<  15u) ///< keep off reason bit for fog
#define HLAF_KEEP_OFF_REASON_BAD_WEATHER                       ((uint32)1u <<  16u) ///< keep off reason bit for bad weather

#define HLA_EM_TO_LSD_LIST_LENGTH        (EM_N_OBJECTS + EM_N_OBJECTS)                                                             ///< length of the EM object to LSD list length, one EM object is split into two lights
#define HLA_RADAR_TO_LSD_LIST_LENGTH     (HLA_NUM_RADAR_OBJECTS + HLA_NUM_RADAR_OBJECTS)                                           ///< length of the hla radar object to LSD list length, one radar object is split into two lights
#define HLA_INTERNAL_OBJECT_LIST_LENGTH  (LSD_LIGHT_OBJECT_LIST_LENGTH + HLA_EM_TO_LSD_LIST_LENGTH + HLA_RADAR_TO_LSD_LIST_LENGTH) ///< length of the internal object list (EM and radar objects are split into two lights)
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/// \brief enum definition for speed state
typedef enum
{
  SPEED_STATE_LOW          = 0,        ///< Low speed state
  SPEED_STATE_HIGH         = 1,        ///< High speed state
  SPEED_STATE_ALWAYSACTIVE = 2,        ///< Always active speed state
  SPEED_STATE_LAST         = SI32_T_MAX ///< Speed state cap
} SpeedState_t;

/// \brief enum definition for the fusion region
typedef enum
{
  HLA_RADAR_REGION_UNKOWN = 0,        ///< Unknown region
  HLA_RADAR_FUSION_REGION = 1,        ///< Fusion region
  HLA_RADAR_ONLY_REGION   = 2,        ///< Radar only region
  HLA_RADAR_STATE_LAST    = SI32_T_MAX ///< Region state cap
} eHLARadarFusionRegion;

/// \brief enum definition for light source
typedef enum
{
  HLA_LIGHT_SOURCE_UNKOWN = 0,        ///< Unknown light source
  HLA_LIGHT_SOURCE_LSD    = 1,        ///< Internal object is coming from lsd
  HLA_LIGHT_SOURCE_EM     = 2,        ///< Internal object is coming from em
  HLA_LIGHT_SOURCE_RADAR  = 3,        ///< Internal object is coming from radar
  HLA_LIGHT_SOURCE_LAST   = SI32_T_MAX ///< light source state cap
}eHLALightSource;

/// \brief Keep off reasons due to current speed
typedef union
{
  uint32 u32; ///< Union member for uint32 representation
  struct {
    uint32  VerySlow                  : 1;  ///< Vehicle Motion speed was very low
    uint32  RecentVehicleDetection    : 1;  ///< Recently a vehicle has been detected
    uint32  HighCurvature             : 1;  ///< Vehicle Motion curvature was high
    uint32  HighAcceleration          : 1;  ///< Vehicle Motion acceleration was high
    uint32  Bit_04                    : 1;  ///< Bit_04 unused
    uint32  Bit_05                    : 1;  ///< Bit_05 unused
    uint32  Bit_06                    : 1;  ///< Bit_06 unused
    uint32  Bit_07                    : 1;  ///< Bit_07 unused
    uint32  dummy                     :24;  ///< Dummy bits 08-32
  } Bit;  ///< Union member for bit representation
} SpeedKeepOffEvents_t;


/// \brief Speed analysis decision
typedef struct
{
  uint8                     disableHLABySpeed;     ///< HLA shall be disabled due to speed criterion
  uint8                     disableHLAByHighSpeed; ///< HLA shall be disabled due to high speed criterion
  uint8                     keepOffHLABySpeed;     ///< HLA shall be kept off due to speed criterion
  SpeedState_t              state;                 ///< Current speed state
  SpeedKeepOffEvents_t      keepOffEvents;         ///< Speed based keep off decision
  float32                   activatePenaltyTimer;  ///< Penalty timer from speed decision
} HLAFSpeed_t;

/// \brief maximum turn on delay structure from relevant vehicles
typedef struct
{
  boolean bPrecDetected;        ///< relevant preceding vehicle detected
  boolean bOncDetected;         ///< relevant oncoming vehicle detected
  boolean bEMObjOncDetected;    ///< relevant oncoming EM object detected
  boolean bEMObjPrecDetected;   ///< relevant preceding EM object detected
  boolean bRadarObjDetected;    ///< relevant radar object detected
  float32 All_s;                ///< all vehicles:       turn on delay \phys_unit s
  float32 Onc_s;                ///< oncoming vehicle:   turn on delay \phys_unit s
  float32 Prec_s;               ///< preceding vehicles: turn on delay \phys_unit s
  float32 TurnOffDelay_Onc_s;   ///< oncoming vehicle:   turn off delay \phys_unit s
  float32 TurnOffDelay_Prec_s;  ///< preceding vehicles: turn off delay \phys_unit s
} HLAFRelevantVehicle_t;


///< \brief enum definition for city state
typedef enum
{
  HLAF_CITY_IDLE             = 0,  ///< No city detected
  HLAF_CITY_DETECTED         = 1,  ///< City detected
  HLAF_CITY_MAYBE            = 2,  ///< Maybe city detected
  HLAF_CITY_MAYBE_WAIT4IDLE  = 3,  ///< Maybe city detected, but max time / distance reached
                                    /*     -> wait for HLAR city idle                          */
                                    /*     -> HLAF DecisionOut will report City idle           */
  HLAF_CITY_LAST             = SI32_T_MAX ///< City state cap
} eHLAFCityState;


/// \brief City detection structure
typedef struct
{
  eHLAFCityState        eCityState;       ///< Internal city state
  float32               distInCity_m;     ///< Distance in city \phys_unit m
  float32               timeInCity_s;     ///< Time in city \phys_unit s
  float32               distOutCity_m;    ///< Distance outside of city \phys_unit m
} HLAFCity_t;

///< \brief Enum definition for blockage states (do NOT change order -> only append!!!)
typedef enum
{
  HLAF_BLOCKAGE_CLEAR_MEAS    = 0,        ///< Clearance measurement is performed
  HLAF_BLOCKAGE_NO_BLOCKAGE   = 1,        ///< No blockage has been reported
  HLAF_BLOCKAGE_BLOCKAGE      = 2,        ///< Blockage has been reported
  HLAF_BLOCKAGE_CONDENSATION  = 3,        ///< Condensation has been reported
  HLAF_BLOCKAGE_LAST          = SI32_T_MAX ///< Blockage state cap
}eHLAFBlockageState_t;


/// \brief Blockage detection structure
typedef struct
{
  eHLAFBlockageState_t  eBlockageState;   ///< internal blockage state
  float32               TimeElapsed;      ///< elapsed time for state transition \phys_unit s
  float32               DistTraveled;     ///< covered distance for state transition \phys_unit m
  float32               BlockageTime;     ///< Time in blockage state \phys_unit s
} HLAFBlockage_t;


/// \brief HLA dimming area signals (for bright reflecting areas)
typedef struct
{
  RTE_HLAF_DimmingLevel DimmingArea[RTE_HLA_NUM_DIMM_AREAS]; ///< Status of each available dimming area
  uint32 DimmAreaHyst[RTE_HLA_NUM_DIMM_AREAS];               ///< Buffer to hold dimming area for a certain frame number
  RTE_HLAF_DimmingStatus  eDimmingStatus;                    ///< Status of dimming feature
  uint32  nDimmingArea;                                      ///< Number of used dimming areas
} HLAFDimming_t;


/// \brief HLA weather decision data structure
typedef struct
{
  float32 wiperStageTime; ///< Time elapsed while being in a defined wiper state. \phys_unit s
  boolean wiperStageUsed; ///< Indicator if wiper has been used as decision element.
} HLAWeatherData_t;

/// \brief Camera data structure
typedef struct
{
  float32 dtime_s;     ///< time since last segmentation (always > 0) \phys_unit s
  float32 dtimeFwd_s;  ///< forward driving time since last segmentation (driving forwards > 0, backwards = 0) \phys_unit s
  float32 ddist_m;     ///< distance since last segmentation (driving forwards > 0, backwards = 0) \phys_unit m
  float32 ddistFwd_m;  ///< forward driving distance since last segmentation (driving forwards > 0, backwards = 0) \phys_unit m
  float32 radius_m;    ///< radius of curvature \phys_unit m
  float32 radiusAbs_m; ///< (> 0) absolute radius of curvature \phys_unit m
} HLAFCameraData_t;

#ifdef HLA_CHANGAN_CURVE_FEATURE
typedef struct
{
  boolean ABSStatus;
  boolean ESPStatus;
  boolean UDLCStatus;
  float32 swaAbs_deg;
  float32 lataccAbs_ms2;
  float32 yawrateAbs_rads;
}HLAFVehData_t;
#endif

/// \brief Keep off reason detailed data
typedef struct
{
  float32  DelayTimer_s; ///< Delay timer \phys_unit s
} HLAFKeepOffSmallRadius_t;


/// \brief Minimum high beam off timer
typedef struct
{
  float32 HBOffTimer_s; ///< High beam off timer \phys_unit s
} HLAFKeepOffMinTimeHBOff_t;


/// \brief Turn on delay structure
typedef struct
{
  float32 InitTimer_s;           ///< Initial timer \phys_unit s
  float32 TurnOnTimer_Onc_s;     ///< Oncoming  vehicle \phys_unit s
  float32 TurnOnTimer_Prec_s;    ///< Preceding vehicle \phys_unit s
  float32 TurnOnTimer_Onc_TL_s;  ///< Oncoming potential truck light \phys_unit s
  float32 TurnOnTimer_Prec_SO_s; ///< Oncoming slow overtaker \phys_unit s
} HLAFKeepOffTurnOnDelay_t;


/// \brief Keep off delay for potential vehicles
typedef struct
{
  float32 DelayTimer_Onc;   ///< Potential oncoming delay
  float32 DelayTimer_Prec;  ///< Potential preceding delay
  float32 DelayTimer_Glob;  ///< Global delay
  uint32  Cnt;              ///< Counts how often a potential vehicle was detected
} HLAFKeepOffPotVeh_t;

/// \brief Keep off delay for fog and bad weather
typedef struct
{
  float32 DelayTimer_Fog;        ///< Delay timer for fog
  float32 DelayTimer_BadWeather; ///< Delay timer for bad weather
}HLAFKeepOffFogBadWeather_t;


/// \brief Keep off delays for maybe city situations
typedef struct
{
  float32 TurnOnTimer_Onc;   ///< Maybe city delay after oncoming vehicle passed
  float32 TurnOnTimer_Prec;  ///< Maybe city delay after preceding vehicle gets lost
  float32 TurnOnTimer_Glob;  ///< Maybe city delay after global turn off reason
} HLAFKeepOffMayBeCity_t;


/// \brief Keep off reason for lost preceding vehicles
typedef struct
{
  float32  distance2cover;  ///< Distance to be covered until position is reached where preceding was when lost \phys_unit m
  float32  rMax;            ///< Radius of curve in which preceding was lost \phys_unit rad
} HLAFKeepOffPrecedingVehicleLost;

/// \brief Turn off reason struct
typedef struct  
{
  uint32  Reason; ///< Stored turn off reason bit field
} HLAFTurnOffReason_t;

/// Keep off reason struct
typedef struct
{
  uint32                           Reason;           ///< Stored keep off reason bit field
  HLAFKeepOffPrecedingVehicleLost  PrecedingVehLost; ///< Preceding vehicle lost keep off data
  HLAFKeepOffSmallRadius_t         SmallRadius;      ///< Small curve radius keep off data
  HLAFKeepOffMinTimeHBOff_t        MinTimeHBoff;     ///< Minimum high beam off keep off data
  HLAFKeepOffTurnOnDelay_t         TurnOnDelay;      ///< Turn on delay keep off data
  HLAFKeepOffPotVeh_t              PotVeh;           ///< Potential vehicle keep off data
  HLAFKeepOffFogBadWeather_t       FogBadWeather;    ///< fog and bad weather keep off data
  HLAFKeepOffMayBeCity_t           MayBeCity;        ///< Maybe city keep off data
} HLAFKeepOffReason_t;


/// \brief HLA function decision data.
typedef struct
{
  HLAFTurnOffReason_t       TurnOffReason;      ///< Turn off reason for full high beam
  HLAFKeepOffReason_t       KeepOffReason;      ///< Keep off reason for full high beam
  HLAFSpeed_t               Speed;              ///< Speed decision state
  HLAFCity_t                City;               ///< City decision state
  HLAFBlockage_t            Blockage;           ///< Blockage decision state
  HLAFDimming_t             DimmingAreas;       ///< Dimming areas decision state
  HLAWeatherData_t          WeatherData;        ///< Weather decision data
} HLAFDecisionData_t;

/// \brief Internal glare free data
typedef struct
{
  uint8   ObjID;          ///< Object ID of the first vehicle in this glare free area
  float32 TTB18Left_min;  ///< Min time to border to left side
  float32 TTB18Left_max;  ///< Max time to border to left side
  float32 TTB18Right_min; ///< Min time to border to right side
  float32 TTB18Right_max; ///< Max time to border to right side
  float32 TimerNoVeh_s;   ///< Elapsed time since last vehicle in GFA
} HLAFMatrixGFADataInt_t;

/// \brief Internal glare free area mapping data
typedef struct
{
  RTE_HLAF_MatrixGFA_t    Ext; ///< [RTE] External glare free areas
  HLAFMatrixGFADataInt_t  Int; ///< [HLA] Internal glare free areas
} HLAFMatrixGFAData_t;

/// \brief Internal glare free areas storage structure
typedef struct
{
  HLAFMatrixGFAData_t   GFA[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS]; ///< Glare free areas array
  uint8                 nGFA;                                          ///< Number of glare free areas
  RTE_HLAF_SignalStatus GFAStatus;                                     ///< Glare free area status (GFA valid, GFA invalid, signal invalid)
} HLAFMatrixGFA_t;

/// \brief Internal matrix data
typedef struct
{
  HLAFMatrixGFA_t         GFA;            ///< Internal GFAs  
  RTE_HLAF_HighBeamState  HighBeamState;  ///< High beam state
  uint32                  TurnOffReason;  ///< Turn off reason
} HLAFMatrixInt_t;

/// \brief Internal object data
typedef struct
{
  uint8 LiObjID;                          ///< Light object ID
  uint8 LiObjIDPair;                      ///< Light object ID of paired light
  uint8 EMObjID;                          ///< EM object ID (from EM object list)
  uint8 ObjNext;                          ///< next object in this glare free area
  uint8 GFA;                              ///< best matching GFA
  uint8 IntObjPairIdx;                    ///< index of paired light in int object list
  uint8 FusedObjID;                       ///< ID of LSD object which was used for radar fusion
  boolean bIsRelevantOnc;                 ///< oncoming object is relevant for hlaf
  boolean bIsRelevantPrec;                ///< preceding object is relevant for hlaf
  const LSD_LightObject_t* pLightObject;  ///< pointer to corresponding light object
  float32 leftAng;                        ///< left angle of internal object
  float32 rightAng;                       ///< right angle of internal object
  boolean bIsWideVehicle;                 ///< object belongs to a wide vehicle
  eHLALightSource LightSource;            ///< light source of object
} HLAObjectDataInt_t;

/// \brief Internal radar data
typedef struct
{
  uint8 RadarID;       ///< radar object ID
  uint8 RadarCounter;  ///< relevance counter of radar object
}HLARadarDataInt_t;


/// \brief HLA matrix beam output data
typedef struct
{
  RTE_HLAF_Matrix_t Matrix; ///< RTE matrix structure
} HLAFMatrixOut_t;


/// \brief HLA matrix beam data
typedef struct
{
  HLAObjectDataInt_t    Object[HLA_INTERNAL_OBJECT_LIST_LENGTH];         ///< object list (EM objects are split into two lights)
  HLAObjectDataInt_t    ObjectPrev[HLA_INTERNAL_OBJECT_LIST_LENGTH];     ///< object list from previous cycle (EM objects are split into two lights)
  uint8                 numRelObj;                                       ///< Number of relevant objects
  uint8                 numRelObjPrev;                                   ///< Number of relevant objects from previous cycle
  uint8                 numEMObj;                                        ///< number of em objects
  uint8                 numEMObjPrev;                                    ///< number of em objects from previous cycle
  uint8                 numRadarObj;                                     ///< number of radar objects
  HLAFMatrixInt_t       Matrix;                                          ///< Internal matrix data 
  HLAFRelevantVehicle_t RelevantVehicle;                                 ///< Relevant vehicle turn on delays
  HLAFMatrixOut_t       Out;                                             ///< Matrix output data
  LSD_LightObject_t     EMToLSDObjList[HLA_EM_TO_LSD_LIST_LENGTH];       ///< light object list for EM objects (to create pseudo light objects out of EM objects)
  LSD_LightObject_t     RadarToLSDObjList[HLA_RADAR_TO_LSD_LIST_LENGTH]; ///< light object list for radar objects (to create pseudo light objects out of radar objects)
  HLARadarDataInt_t     RadarObjectsData[HLA_NUM_RADAR_OBJECTS];         ///< relevant radar object data
  HLARadarDataInt_t     RadarObjectsDataPrev[HLA_NUM_RADAR_OBJECTS];     ///< relevant radar object data from previous cycle
  uint8                 numIntRadar;                                     ///< number of elements in radar objects data list
  uint8                 numIntRadarPrev;                                 ///< number of elements in previous radar objects data list
} HLAFMatrixData_t;

/// \brief Combined headlight decision structure
typedef struct
{
  RTE_HLAR_CityState                      eCityState;       ///< Enum that holds the city state
  LSD_e_EnvironmentData_TunnelState       eTunnelState;     ///< Enum that holds tunnel state
  LSD_e_EnvironmentData_HighwayState      eHighwayState;    ///< Structure that represents the highway state
  LSD_e_EnvironmentData_BrightnessState   eBrightnessState; ///< Enum that holds brightness state
  LSD_e_TrafficStyle                      eTrafficStyle;    ///< Structure that holds the traffic style
  RTE_HLAR_WeatherState                   eWeatherState;    ///< Enum that holds weather state
  RTE_HLA_SceneInfo                       eSceneInfo;       ///< Enum that holds scene info state
} HLAFDecisionOut_t;


/// \brief HLA Function data
typedef struct
{
  AlgoCycleCounter_t  FrameCnt;           ///< \brief frame counter \phys_unit 1
  AlgoDataTimeStamp_t TimeStamp_HLA_ms;   ///< \brief HLA Timestamp \phys_unit us

  HLAFCameraData_t    CamData;            ///< Camera data

#ifdef HLA_CHANGAN_CURVE_FEATURE
  HLAFVehData_t       VehData;            ///< Vehicle data
#endif

  HLAFDecisionData_t  DecisionData;       ///< Internal decision data
  HLAFDecisionOut_t   DecisionOut;        ///< Decision output data

  HLAFMatrixData_t    hlafMatrixData;     ///< HLA Matrix decision data
  HLAFMatrixOut_t     HLAMatrixOut;       ///< HLA Matrix Output data
} HLAFData_t;


/*****************************************************************************
  FUNCTION 
*****************************************************************************/


/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_TYPE_H */ 
