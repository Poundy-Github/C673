#ifndef _GA_GLOBAL_H_INCLUDED
#error include setup error: forbidden inclusion of GA local-scope header file; only component *_main.h + *_wrapper.h, and ga_global.h (or ga_global_emlib.h on emlib dependancy) are allowed
#endif

#ifndef GA_HLA_INTERFACES_EXT_H_INCLUDED
#define GA_HLA_INTERFACES_EXT_H_INCLUDED

/*! @ingroup hla_interfaces
@{
@file
External header of the HLA_INTERFACES component.    */


#if (GA_CFG_HLA_INTERFACES == 1)

#ifdef __cplusplus
extern "C" {
#endif

/* --- virtual addresses --------------------------------------------------- */
#define HLA_INTERFACES_VA_CONTROL_DATA       ()   /*!< virtual address of controlData (uL) */

/* ---- constants ---------------------------------------------------------- */
#define RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS       (5)
#define RTE_HLA_NUM_DIMM_AREAS                         (5)
#define RTE_HLA_NUM_DIMM_AREAS_BORDERS                 (4)
#define HLA_NUM_RADAR_OBJECTS                          (2)

/* ---- type InterfaceVersion ---------------------------------------------- */
#define HLA_INTERFACES_CONTROL_DATA_INTVER  (1)  /*!< version of HLA_INTERFACES_ControlData */
#define CPAR_HLAF_PARAMETER_INTFVER         (10)  /*!< version of HLA_INTERFACES_CPAR_HLAF_Parameter */
#define HLA_BUS_INPUT_SIGNALS_INTFVER       (1)  /*!< version of HLA_INTERFACES_HLA_BusInputSignals */
#define RTE_HLAF_HEADLIGHTCONTROL_INTFVER   (12)  /*!< version of HLA_INTERFACES_RTE_HLAF_HeadlightControl */

/* ---- type definitions --------------------------------------------------- */
#define hla_interfaces_RTE_HLA_TESTMODE_UNKNOWN                         (0u)
#define hla_interfaces_RTE_HLA_TESTMODE_INACTIVE                        (1u)
#define hla_interfaces_RTE_HLA_TESTMODE_SAE                             (2u)
#define hla_interfaces_RTE_HLA_TESTMODE_ECE                             (3u)
#define hla_interfaces_RTE_HLA_TESTMODE_SEG_ALWAYS_ON                   (4u)
#define hla_interfaces_RTE_HLA_TESTMODE_NO_CLEARMEAS                    (5u)
#define hla_interfaces_RTE_HLA_TESTMODE_LAB                             (6u)
#define hla_interfaces_RTE_HLA_TESTMODE_FOV                             (7u)
#define hla_interfaces_RTE_HLA_TESTMODE_LAB_ENHANCED                    (8u)
#define hla_interfaces_RTE_HLA_TESTMODE_1                               (9u)
#define hla_interfaces_RTE_HLA_TESTMODE_2                               (10u)

/*! @brief When active (value=RTE_HLA_TESTMODE_SAE), some special Algos (Blockage detection, clearance measurement, Bad Pixel detection) will be switched off which interfere the Test, especially when the SAE test is done in lab. (default value = */
typedef uint8 RTE_HLA_TestMode;

#define hla_interfaces_RTE_HLA_FOGDET_UNKNOWN                           (0u)
#define hla_interfaces_RTE_HLA_FOGDET_INACTIVE                          (1u)
#define hla_interfaces_RTE_HLA_FOGDET_ACTIVE                            (2u)
#define hla_interfaces_RTE_HLA_FOGDET_INVALID                           (255u)

/*! @brief When active (value */
typedef uint8 RTE_HLA_FogDetection;

#define hla_interfaces_RTE_HLA_BADWEATHER_DET_UNKNOWN                   (0u)
#define hla_interfaces_RTE_HLA_BADWEATHER_DET_INACTIVE                  (1u)
#define hla_interfaces_RTE_HLA_BADWEATHER_DET_ACTIVE                    (2u)
#define hla_interfaces_RTE_HLA_BADWEATHER_DET_INVALID                   (255u)

/*! @brief When active (value */
typedef uint8 RTE_HLA_BadWeatherDetection;

#define hla_interfaces_RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN            (0u)
#define hla_interfaces_RTE_HLA_CPAR_SENSITIVITY_MODE_DEFAULT            (1u)
#define hla_interfaces_RTE_HLA_CPAR_SENSITIVITY_MODE_US                 (2u)

/*! @brief When active (value=RTE_HLA_FOGDET_ACTIVE), HLA will listen to blockage output and switch high beam off in case fog. (default value = RTE_HLA_FOGDET_ACTIVE) */
typedef uint8 RTE_HLA_CparSensityMode;

#define hla_interfaces_RTE_HLA_DIMMDET_UNKNOWN                          (0u)
#define hla_interfaces_RTE_HLA_DIMMDET_INACTIVE                         (1u)
#define hla_interfaces_RTE_HLA_DIMMDET_ACTIVE                           (2u)
#define hla_interfaces_RTE_HLA_DIMMDET_INVALID                          (255u)

/*! @brief When active (value */
typedef uint8 HLA_INTERFACES_DimmingDetection;

#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNOWN        (0u)
#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_OFF            (1u)
#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON             (2u)

/*! @brief Driver can request HLA to be on/off. Default behavior is that HLA returns only low beam recommendation (no GFAs either). (default: HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNWON) */
typedef uint8 HLA_BusInputSignals_HlaRequest;

#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_UNKNOWN  (0u)
#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_OFF      (1u)
#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_GREEN    (2u)
#define hla_interfaces_HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_BLUE     (3u)

/*! @brief Status of high beam indicator lamp (green/blue) in HMI. (default: */
typedef uint8 HLA_BusInputSignals_HBIndicatorLamp;

#define hla_interfaces_RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF           (0u)
#define hla_interfaces_RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF           (1u)
#define hla_interfaces_RTE_HLAF_FUNCTION_STATUS_RUNNING                 (2u)
#define hla_interfaces_RTE_HLAF_FUNCTION_STATUS_INVALID                 (3u)

/*! @brief Status of HLA chain, mainly mapping of HLA component state */
typedef uint8 RTE_HLAF_FunctionStatus;

#define hla_interfaces_RTE_HLA_TRAFFIC_STYLE_UNKNOWN                    (0u)
#define hla_interfaces_RTE_HLA_TRAFFIC_STYLE_RHT                        (1u)
#define hla_interfaces_RTE_HLA_TRAFFIC_STYLE_LHT                        (2u)
#define hla_interfaces_RTE_HLA_TRAFFIC_STYLE_INVALID                    (255u)

/*! @brief HLA right/left hand traffic style */
typedef uint8 RTE_HLA_TrafficStyle;

#define hla_interfaces_RTE_HLAR_CITY_UNKNOWN                            (0u)
#define hla_interfaces_RTE_HLAR_CITY_NOT_DTCD                           (1u)
#define hla_interfaces_RTE_HLAR_CITY_DTCD                               (2u)
#define hla_interfaces_RTE_HLAR_CITY_MAYBE                              (3u)
#define hla_interfaces_RTE_HLAR_CITY_INVALID                            (255u)

/*! @brief HLA city detection */
typedef uint8 RTE_HLAR_CityState;

#define hla_interfaces_RTE_HLAR_WEATHER_UNKNOWN                         (0u)
#define hla_interfaces_RTE_HLAR_WEATHER_GOOD                            (1u)
#define hla_interfaces_RTE_HLAR_WEATHER_BAD                             (2u)
#define hla_interfaces_RTE_HLAR_WEATHER_LIGHT_FOG                       (3u)
#define hla_interfaces_RTE_HLAR_WEATHER_MEDIUM_FOG                      (4u)
#define hla_interfaces_RTE_HLAR_WEATHER_HEAVY_FOG                       (5u)
#define hla_interfaces_RTE_HLAR_WEATHER_INVALID                         (255u)

/*! @brief HLA weather detection */
typedef uint8 RTE_HLAR_WeatherState;

#define hla_interfaces_RTE_HLAR_TUNNEL_UNKNOWN                          (0u)
#define hla_interfaces_RTE_HLAR_TUNNEL_NOT_DTCD                         (1u)
#define hla_interfaces_RTE_HLAR_TUNNEL_UPFRONT                          (2u)
#define hla_interfaces_RTE_HLAR_TUNNEL_INSIDE                           (3u)
#define hla_interfaces_RTE_HLAR_TUNNEL_INVALID                          (255u)

/*! @brief HLA tunnel detection */
typedef uint8 RTE_HLAR_Tunnel;

#define hla_interfaces_RTE_HLAF_MTWY_UNKNOWN                            (0u)
#define hla_interfaces_RTE_HLAF_MTWY_COUNTRY                            (1u)
#define hla_interfaces_RTE_HLAF_MTWY_MOTORWAY                           (2u)
#define hla_interfaces_RTE_HLAF_MTWY_INVALID                            (255u)

/*! @brief HLA motorway detection */
typedef uint8 RTE_HLAF_MotorwayState;

#define hla_interfaces_RTE_HLAR_BRT_UNKNOWN                             (0u)
#define hla_interfaces_RTE_HLAR_BRT_DAY                                 (1u)
#define hla_interfaces_RTE_HLAR_BRT_TWLGT_1                             (2u)
#define hla_interfaces_RTE_HLAR_BRT_TWLGT_2                             (3u)
#define hla_interfaces_RTE_HLAR_BRT_TWLGT_3                             (4u)
#define hla_interfaces_RTE_HLAR_BRT_NIGHT                               (5u)
#define hla_interfaces_RTE_HLAR_BRT_INVALID                             (255u)

/*! @brief HLA brightness detection */
typedef uint8 RTE_HLAR_BrightnessState;

#define hla_interfaces_RTE_HLA_SENSMODE_UNKNOWN                         (0u)
#define hla_interfaces_RTE_HLA_SENSMODE_NORMAL                          (1u)
#define hla_interfaces_RTE_HLA_SENSMODE_US                              (2u)
#define hla_interfaces_RTE_HLA_SENSMODE_INVALID                         (255u)

/*! @brief Sensitivity modes normal or e.g. for US */
typedef uint8 RTE_HLA_SensMode;

#define hla_interfaces_RTE_HLAF_SPEEDSTATE_UNKNOWN                      (0u)
#define hla_interfaces_RTE_HLAF_SPEEDSTATE_TOO_LOW                      (1u)
#define hla_interfaces_RTE_HLAF_SPEEDSTATE_IN_RANGE                     (2u)
#define hla_interfaces_RTE_HLAF_SPEEDSTATE_TOO_HIGH                     (3u)
#define hla_interfaces_RTE_HLAF_SPEEDSTATE_INVALID                      (255u)

/*! @brief If speed is higher/lower than (De)ActivateSpeed (CPAR) which defines when to turn on/off high beam */
typedef uint8 RTE_HLAF_SpeedState;

#define hla_interfaces_RTE_HLA_SCENEINFO_UNKNOWN                        (0u)
#define hla_interfaces_RTE_HLA_SCENEINFO_ONCOMING_PASSING               (1u)
#define hla_interfaces_RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING           (2u)
#define hla_interfaces_RTE_HLA_SCENEINFO_INVALID                        (255u)

/*! @brief If oncoming vehicle is directly passing or preceding vehicle is overtaken directly this output is used to trigger very fast highbeam turn on */
typedef uint8 RTE_HLA_SceneInfo;

#define hla_interfaces_RTE_HLAF_SIGSTAT_UNKNOWN                         (0u)
#define hla_interfaces_RTE_HLAF_SIGSTAT_INIT                            (1u)
#define hla_interfaces_RTE_HLAF_SIGSTAT_DATA_VALID                      (2u)
#define hla_interfaces_RTE_HLAF_SIGSTAT_DATA_INVALID                    (3u)
#define hla_interfaces_RTE_HLAF_SIGSTAT_INVALID                         (255u)

/*! @brief glare free area status */
typedef uint8 RTE_HLAF_SignalStatus;

#define hla_interfaces_RTE_HLAF_HB_STATE_UNKNOWN                        (0u)
#define hla_interfaces_RTE_HLAF_HB_STATE_OFF                            (1u)
#define hla_interfaces_RTE_HLAF_HB_STATE_FULL_ON                        (2u)
#define hla_interfaces_RTE_HLAF_HB_STATE_PARTIAL                        (3u)
#define hla_interfaces_RTE_HLAF_HB_STATE_SPOT                           (4u)
#define hla_interfaces_RTE_HLAF_HB_STATE_INVALID                        (255u)

/*! @brief high beam state recommendation */
typedef uint8 RTE_HLAF_HighBeamState;

#define hla_interfaces_RTE_HLAF_OBJSTA_UNKNOWN                          (0u)
#define hla_interfaces_RTE_HLAF_OBJSTA_NO_OBJ                           (1u)
#define hla_interfaces_RTE_HLAF_OBJSTA_UNKNOWN_OBJ                      (2u)
#define hla_interfaces_RTE_HLAF_OBJSTA_PREC_OBJ                         (3u)
#define hla_interfaces_RTE_HLAF_OBJSTA_ONC_OBJ                          (4u)
#define hla_interfaces_RTE_HLAF_OBJSTA_INVALID                          (255u)

/*! @brief object status of the vehicle which defines the low beam distance (preceding oncoming car) */
typedef uint8 RTE_HLAF_ObjStatus;

#define hla_interfaces_RTE_HLAF_TURNOFFREASON_UNKNOWN                   (0u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_ONC                       (1u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_PREC                      (2u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_SPEED                     (4u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_BRIGHTNESS                (8u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_CITY                      (16u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_FOG                       (32u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_BLOCKAGE                  (64u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_DELAY                     (128u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_ERROR                     (256u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_TUNNEL                    (512u)
#define hla_interfaces_RTE_HLAF_TURNOFFREASON_WEATHER                   (1024u)

/*! @brief HLA turn off reason */
typedef uint16 RTE_HLAF_MatrixTurnOffReason;

#define hla_interfaces_RTE_HLAF_DISTSTATE_UNKNOWN                       (0u)
#define hla_interfaces_RTE_HLAF_DISTSTATE_SINGLELIGHT                   (1u)
#define hla_interfaces_RTE_HLAF_DISTSTATE_PAIRLIGHT                     (2u)
#define hla_interfaces_RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE                (3u)
#define hla_interfaces_RTE_HLAF_DISTSTATE_INVALID                       (255u)

/*! @brief specifies whether distance is measured from single or pair light */
typedef uint8 RTE_HLAF_DistState;

#define hla_interfaces_RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN             (0u)
#define hla_interfaces_RTE_HLA_DISTANCE_RELIABILITY_LOW                 (1u)
#define hla_interfaces_RTE_HLA_DISTANCE_RELIABILITY_MID                 (2u)
#define hla_interfaces_RTE_HLA_DISTANCE_RELIABILITY_HIGH                (3u)
#define hla_interfaces_RTE_HLA_DISTANCE_RELIABILITY_INVALID             (255u)

/*! @brief Reliability of the distance estimation for the object which defines the left border */
typedef uint8 RTE_HLA_DistReliability;

#define hla_interfaces_RTE_HLAF_TTBSTA_UNKNOWN                          (0u)
#define hla_interfaces_RTE_HLAF_TTBSTA_NO_OBJ                           (1u)
#define hla_interfaces_RTE_HLAF_TTBSTA_DIR_UNKNOWN                      (2u)
#define hla_interfaces_RTE_HLAF_TTBSTA_DIR_LEFT                         (3u)
#define hla_interfaces_RTE_HLAF_TTBSTA_DIR_RIGHT                        (4u)
#define hla_interfaces_RTE_HLAF_TTBSTA_INVALID                          (255u)

/*! @brief Status of ttb18Left (moving direction) */
typedef uint8 RTE_HLAF_TTBStatus;

#define hla_interfaces_RTE_HLAF_DIMM_STATE_UNKNOWN                      (0u)
#define hla_interfaces_RTE_HLAF_DIMM_STATE_AVL                          (1u)
#define hla_interfaces_RTE_HLAF_DIMM_STATE_LIMITED                      (2u)
#define hla_interfaces_RTE_HLAF_DIMM_STATE_NAVL                         (3u)
#define hla_interfaces_RTE_HLAF_DIMM_STATE_ERROR                        (4u)
#define hla_interfaces_RTE_HLAF_DIMM_STATE_INVALID                      (255u)

/*! @brief Status of the dimming function */
typedef uint8 RTE_HLAF_DimmingStatus;

#define hla_interfaces_RTE_HLAF_DIMM_LEVEL_UNKNOWN                      (0u)
#define hla_interfaces_RTE_HLAF_DIMM_LEVEL_NO_REDUCT                    (1u)
#define hla_interfaces_RTE_HLAF_DIMM_LEVEL_REDUCT_1                     (2u)
#define hla_interfaces_RTE_HLAF_DIMM_LEVEL_REDUCT_2                     (3u)
#define hla_interfaces_RTE_HLAF_DIMM_LEVEL_INVALID                      (255u)

/*! @brief List which holds the dimming areas */
typedef uint8 RTE_HLAF_DimmingLevel;

#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_MOVING             (0u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_STATIONARY         (1u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_ONCOMING           (2u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_CROSSING_LEFT      (3u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_CROSSING_RIGHT     (4u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_UNKNOWN            (5u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_STOPPED            (6u)
#define hla_interfaces_HLA_RADAR_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES     (7u)

/*! @brief This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. */
typedef uint8 HLA_RadarObjDynamicProperty;

#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_POINT                     (0u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_CAR                       (1u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_TRUCK                     (2u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_PEDESTRIAN                (3u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_MOTORCYCLE                (4u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_BICYCLE                   (5u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_WIDE                      (6u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_UNCLASSIFIED              (7u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_OTHER_VEHICLE             (8u)
#define hla_interfaces_HLA_RADAR_OBJECT_CLASS_MAX_DIFF_TYPES            (9u)

/*! @brief This signal indicates the class of the object. */
typedef uint8 HLA_RadarObjClassification;

#define hla_interfaces_opModeReset                                      (0u)   /*!< Reset */
#define hla_interfaces_opModePause                                      (1u)   /*!< Pause */
#define hla_interfaces_opModeNormal                                     (2u)   /*!< Normal */

/*! @brief OpMode(HLA_INTERFACES) */
typedef uint8 HLA_INTERFACES_OpMode;

#define hla_interfaces_opModeReset                                      (0u)   /*!< Reset */
#define hla_interfaces_opModePause                                      (1u)   /*!< Pause */
#define hla_interfaces_opModeNormal                                     (2u)   /*!< Normal */

/*! @brief OpMode(HLA_INTERFACES) */
typedef uint8 HLA_INTERFACES_OpMode;


/*! @brief HLAF parameter */
typedef struct
{
    AlgoInterfaceVersionNumber_t                              uiVersionNumber;                 /*!< Interface version number (increased when changed)  */
    BASE_INTERFACES_SignalHeader_t                            sSigHeader;                      /*!< Signal header (Timestamp, ImageCnt, MeasurementCnt,...)  */
    HLA_INTERFACES_RTE_HLAF_ParameterAlgoCfg                  AlgoCfg;                         /*!< Algo configuration  */
    HLA_INTERFACES_RTE_HLAF_ParameterVehicleProbability       VehicleProbabilities;            /*!< Thresholds for different scenarios above which HLA treats LSD light objects as relevant vehicle.  */
    HLA_INTERFACES_RTE_HLAF_ParameterKeepOnDelay              KeepOnDelay;                     /*!< High beam keep on delay parameters.  */
    HLA_INTERFACES_RTE_HLAF_ParameterTurnOnDelay              TurnOnDelay;                     /*!< High beam turn on delay parameters.  */
    HLA_INTERFACES_RTE_HLAF_ParameterTurnOffDelay             TurnOffDelay;                    /*!< High beam turn off delay.  */
    HLA_INTERFACES_RTE_HLAF_ParameterSpeed                    Speed;                           /*!< Speed threshold for high beam activation/ deactivation.  */
} HLA_INTERFACES_CPAR_HLAF_Parameter;           /* @versionstr: CPAR_HLAF_PARAMETER_INTFVER */

/*! @brief Algo configuration */
typedef struct
{
    RTE_HLA_TestMode                                          TestMode;                        /*!< When active (value=RTE_HLA_TESTMODE_SAE), some special Algos (Blockage detection, clearance measurement, Bad Pixel detection) will be switched off which interfere the Test, especially when the SAE test is done in lab. (default value = RTE_HLA_TESTMODE_INACTIVE),Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_TESTMODE_UNKNOWN=0,RTE_HLA_TESTMODE_INACTIVE=1,RTE_HLA_TESTMODE_SAE=2,RTE_HLA_TESTMODE_ECE=3,RTE_HLA_TESTMODE_SEG_ALWAYS_ON=4,RTE_HLA_TESTMODE_NO_CLEARMEAS=5,RTE_HLA_TESTMODE_LAB=6,RTE_HLA_TESTMODE_FOV=7,RTE_HLA_TESTMODE_LAB_ENHANCED=8,RTE_HLA_TESTMODE_1=9,RTE_HLA_TESTMODE_2=10  */
    RTE_HLA_FogDetection                                      FogDetection;                    /*!< When active (value=RTE_HLA_FOGDET_ACTIVE), HLA will listen to blockage output and switch high beam off in case fog. (default value = RTE_HLA_FOGDET_ACTIVE),Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_FOGDET_UNKNOWN=0,RTE_HLA_FOGDET_INACTIVE=1,RTE_HLA_FOGDET_ACTIVE=2,RTE_HLA_FOGDET_INVALID=255  */
    RTE_HLA_BadWeatherDetection                               BadWeatherDetection;             /*!< When active (value=RTE_HLA_BADWEATHER_DET_ACTIVE), HLA will listen to blockage output and switch high beam off in case of bad weather. (default value = RTE_HLA_BADWEATHER_DET_ACTIVE),Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_BADWEATHER_DET_UNKNOWN=0,RTE_HLA_BADWEATHER_DET_INACTIVE=1,RTE_HLA_BADWEATHER_DET_ACTIVE=2,RTE_HLA_BADWEATHER_DET_INVALID=255  */
    RTE_HLA_CparSensityMode                                   sensitivityMode;                 /*!< When active (value=RTE_HLA_FOGDET_ACTIVE), HLA will listen to blockage output and switch high beam off in case fog. (default value = RTE_HLA_FOGDET_ACTIVE),Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN=0,RTE_HLA_CPAR_SENSITIVITY_MODE_DEFAULT=1,RTE_HLA_CPAR_SENSITIVITY_MODE_US=2  */
} HLA_INTERFACES_RTE_HLAF_ParameterAlgoCfg;

/*! @brief Thresholds for different scenarios above which HLA treats LSD light objects as relevant vehicle. */
typedef struct
{
    uint8                                                     thresholdUpperOncoming;          /*!< Threshold for default scenario. If oncoming vehicle probability of LSD light object is above this threshold HLA treats this light object as oncoming car. (Default value = 90%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdUpperPreceding;         /*!< Threshold for default scenario. If preceding vehicle probability of LSD light object is above this threshold HLA treats this light object as preceding car. (Default value = 90%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdUpperOncomingHighway;   /*!< Threshold for highway scenario. If oncoming vehicle probability of LSD light object is above this threshold HLA treats this light object as oncoming car. (Default value = 90%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdUpperPrecedingHighway;  /*!< Threshold for highway scenario. If preceding vehicle probability of LSD light object is above this threshold HLA treats this light object as preceding car. (Default value = 90%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdUpperOncomingCity;      /*!< Threshold for city scenario. If oncoming vehicle probability of LSD light object is above this threshold HLA treats this light object as oncoming car. (Default value = 90%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdUpperPrecedingCity;     /*!< Threshold for city scenario. If preceding vehicle probability of LSD light object is above this threshold HLA treats this light object as preceding car. (Default value = 90%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdLowerOncoming;          /*!< Threshold for default scenario. If oncoming vehicle probability of LSD light object is below this threshold HLA doesn't treat this light object as oncoming car any longer. (Default value = 10%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdLowerPreceding;         /*!< Threshold for default scenario. If preceding vehicle probability of LSD light object is below this threshold HLA doesn't treat this light object as preceding car any longer. (Default value = 10%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdLowerOncomingHighway;   /*!< Threshold for highway scenario. If oncoming vehicle probability of LSD light object is below this threshold HLA doesn't treat this light object as oncoming car any longer. (Default value = 10%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdLowerPrecedingHighway;  /*!< Threshold for highway scenario. If preceding vehicle probability of LSD light object is below this threshold HLA doesn't treat this light object as preceding car any longer. (Default value = 10%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdLowerOncomingCity;      /*!< Threshold for city scenario. If oncoming vehicle probability of LSD light object is below this threshold HLA doesn't treat this light object as oncoming car any longer. (Default value = 10%), Unit: [%], Range:[0u..100u]  */
    uint8                                                     thresholdLowerPrecedingCity;     /*!< Threshold for city scenario. If preceding vehicle probability of LSD light object is below this threshold HLA doesn't treat this light object as preceding car any longer. (Default value = 10%), Unit: [%], Range:[0u..100u]  */
} HLA_INTERFACES_RTE_HLAF_ParameterVehicleProbability;

/*! @brief High beam keep on delay parameters. */
typedef struct
{
    uint16                                                    distanceOncomingVehicle;         /*!< HB keeps on if oncoming vehicle is beyond this distance. (Default value = 4000m), Unit: [m], Range:[0u..5000u]  */
    uint16                                                    distancePrecedingVehicleMin;     /*!< HB keeps on if preceding vehicle is beyond this distance. (Default value = 3000m), Unit: [m], Range:[0u..5000u]  */
    uint16                                                    distancePrecedingVehicleMax;     /*!< HB is switched on again if preceding vehicle moves beyond this distance after being closer than distancePrecedingVehicleMin. (Default value = 4000m), Unit: [m], Range:[0u..5000u]  */
} HLA_INTERFACES_RTE_HLAF_ParameterKeepOnDelay;

/*! @brief High beam turn on delay parameters. */
typedef struct
{
    float32                                                   OncomingMin;                     /*!< Determines the minimal delay time [s] that should be waited between an oncoming vehicle and a high-beam activation recommendation when oncoming vehicles gets lost at distance below OncomingMin_DistThreshold and lateral distance above OncomingMin_LatDistThreshold . (default value = 0.6s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   OncomingMax;                     /*!< Determines the maximum delay time [s] that should be waited between an oncoming vehicle and a high-beam activation recommendation. Delay = MINMAX(OncomingMin, OncomingMax, TTB18) (default value = 1.5s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   OncomingMinHighway;              /*!< Determines the minimum delay time [s] that should be waited between an oncoming vehicle and a high-beam activation recommendation. (Default value = 1.5s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   OncomingMaxHighway;              /*!< Determines the maximum delay time [s] that should be waited between an oncoming vehicle and a high-beam activation recommendation. (Default value = 1.5s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   PrecedingMin;                    /*!< Determines the minimal delay time [s] that should be waited between an preceding vehicle and a high-beam activation recommendation. (Default value = 0.06s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   PrecedingMinWiperOn;             /*!< Determines the minimal delay time [s] that should be waited between an preceding vehicle and a high-beam activation recommendation when the wiper are switched on. (Default value = 3.0s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   PrecedingMaxShort;               /*!< Determines the maximum delay time [s] that should be waited between an preceding vehicle and a high-beam activation recommendation when vehicle gets lost at "high" taillamp intensity. (Default value = 3.0s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   PrecedingMaxLong;                /*!< Determines the maximum delay time [s] that should be waited between an preceding vehicle and a high-beam activation recommendation when vehicle gets lost at "low" taillamp intensity (depending on TTB18). (Default value = 3.0s), Unit: [s], Range:[0.0f.. 20.0f]  */
    float32                                                   SlowOvertaking;                  /*!< Determines the delay time [s] that should be waited (in slow overtaking situations) between an preceding vehicle and a high-beam activation recommendation. (Default value = 8.0s), Unit: [s], Range:[0.0f.. 30.0f]  */
    float32                                                   Fog;                             /*!< Determines the delay time (in seconds) that should be waited between a "fog detection" event and a high-beam activation recommendation. (Default value = 10.0s), Unit: [s], Range:[0.0f.. 30.0f]  */
    float32                                                   Blockage;                        /*!< Determines the delay time (in seconds) that should be waited between a blockage-to-NoBlockage transition and a high-beam activation recommendation. (Default value = 2.0s), Unit: [s], Range:[0.0f.. 30.0f]  */
} HLA_INTERFACES_RTE_HLAF_ParameterTurnOnDelay;

/*! @brief High beam turn off delay. */
typedef struct
{
    float32                                                   oncomingVehicle;                 /*!< Determines the minimal delay time [s] that should be waited before switching off high beam in case of a relevant oncoming vehicle.. (Default value = 0.0s), Unit: [s], Range:[0.0f..30.0f]  */
    float32                                                   precedingVehicle;                /*!< Determines the minimal delay time [s] that should be waited before switching off high beam in case of a relevant preceding vehicle.. (Default value = 0.0s), Unit: [s], Range:[0.0f..30.0f]  */
} HLA_INTERFACES_RTE_HLAF_ParameterTurnOffDelay;

/*! @brief Speed threshold for high beam activation/ deactivation. */
typedef struct
{
    float32                                                   DeactivateSpeed;                 /*!< Determines the speed threshold below which HLA will send a high beam OFF recommendation. (default value = 30.0km/h), Unit: [m/s], Range:[0 .. 100.0f]  */
    float32                                                   DeactivateSpeedHigh;             /*!< Determines the speed threshold beyond which HLA will send a high beam OFF recommendation. (default value = 280.0km/h), Unit: [m/s], Range:[0 .. 300.0f]  */
    float32                                                   ActivateSpeed;                   /*!< Determines the speed threshold above which the HLA is allowed to send a high beam ON recommendation, depending on keep criteria. (default value = 40.0km/h), Unit: [m/s], Range:[0 .. 100.0f]  */
    float32                                                   ActivateSpeedHigh;               /*!< Determines the speed threshold below which the HLA is allowed to send a high beam ON recommendation, depending on keep criteria. (default value = 270.0km/h), Unit: [m/s], Range:[0 .. 300.0f]  */
    float32                                                   AlwaysActiveSpeed;               /*!< Determines the speed threshold above which the HLA will always send a high beam ON recommendation. (default value = 50.0km/h), Unit: [m/s], Range:[0 .. 100.0f]  */
    float32                                                   KeepOff_VeryLowSpeed;            /*!< When speed is below KeepOff_VeryLowSpeed the Delay will be set to KeepOff_Delay. When speed is above ActivateSpeed the timer will start. (default value = 12.6km/h), Unit: [m/s], Range:[0 .. 100.0f]  */
    float32                                                   KeepOff_LowRadius;               /*!< When the curve radius is below KeepOff_MaxRadius the Delay will be set to KeepOff_Delay. When speed is above ActivateSpeed the timer will start. (default value = 150.0m), Unit: [m], Range:[0 .. 500.0f]  */
    float32                                                   KeepOff_HighAcceleration;        /*!< When the vehicle acceleration is above KeepOff_Max Acceleration the Delay will be set to KeepOff_Delay. When speed is above ActivateSpeed the timer will start. (default value = 2.5m/s²), Unit: [m/s^2], Range:[0 .. 20.0f]  */
    float32                                                   KeepOff_AccTime;                 /*!< When the acceleration indicates that velocity will fall below activation speed (Spd + AccTime * Acc < ActivateSpeed) the Delay will be set to KeepOff_Delay . When speed is above ActivateSpeed the timer will start. (default value = 2.5s), Unit: [s], Range:[0 .. 20.0f]  */
    float32                                                   KeepOff_Delay;                   /*!< Determines the high beam turn on delay [s] when speed is above ActivateSpeed and below AlwaysActiveSpeed when one of the keep of reason was active before. (default value = 2.0s), Unit: [s], Range:[0 .. 20.0f]  */
} HLA_INTERFACES_RTE_HLAF_ParameterSpeed;

/*! @brief Matrix beam parameters */
typedef struct
{
    uint16                                                    MaxNumGlarefreeArea;             /*!< Determines the maximum number of glarefree areas that the ECU is allowed to send. (default value = 1), Range:[0..RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS]  */
} HLA_INTERFACES_RTE_HLAF_ParameterMatrixBeam;

/*! @brief Dimming relevant parameters */
typedef struct
{
    HLA_INTERFACES_DimmingDetection                           DimmingDetection;                /*!< When active (value=RTE_HLA_DIMMDET_ACTIVE), enables the dimming algorithm due to bright objects and enables the ECU to send a request for reducing brightness of high beam (default value = RTE_HLA_DIMMDET_ACTIVE),Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_DIMMDET_UNKNOWN=0,RTE_HLA_DIMMDET_INACTIVE=1,RTE_HLA_DIMMDET_ACTIVE=2,RTE_HLA_DIMMDET_INVALID=255  */
    float32                                                   AreaRightBorderArray[4];         /*!< Right border of dimming areas, i.e. (left Roi border, AreaRightBorderArray[0] ], (AreaRightBorderArray[0], AreaRightBorderArray[1] ] (AreaRightBorderArray[1], AreaRightBorderArray[2] ] (AreaRightBorderArray[2], AreaRightBorderArray[3] ] (default value: -7°, -3°, 3°, 7°), Unit: [rad], Range:[-19°..19°]  */
    float32                                                   ReductThreshLevel1;              /*!< Brightness threshold level 1 to reduce high beam (default value: 80%), Unit: [%], Range:[0.0f .. 100.0f]  */
    float32                                                   ReductThreshLevel2;              /*!< Brightness threshold level 2 to reduce high beam (default value: 80%), Unit: [%], Range:[0.0f .. 100.0f]  */
    float32                                                   TurnOnDelay;                     /*!< After this delay ECU can send request for full high beam brightness once no bright object has been detected anymore. (default value: 0.3s), Unit: [s], Range:[0.0.. 10.0f]  */
} HLA_INTERFACES_RTE_HLAF_ParameterDimming;

/*! @brief All kind of bus signals relevant for HLA, e.g. headlight state (feedback from headlight control unit), driver requests like US sensitivity mode or HLA on/off */
typedef struct
{
    AlgoInterfaceVersionNumber_t                              uiVersionNumber;                 /*!< Interface version number (increased when changed)  */
    BASE_INTERFACES_SignalHeader_t                            sSigHeader;                      /*!< Signal header (Timestamp, ImageCnt, MeasurementCnt,...)  */
    HLA_BusInputSignals_HlaRequest                            hlaRequest;                      /*!< Driver can request HLA to be on/off. Default behavior is that HLA returns only low beam recommendation (no GFAs either). (default: HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNWON),Accuracy: 1.0, Unit: [Enum],List:HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNOWN=0,HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_OFF=1,HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON=2  */
    HLA_BusInputSignals_HBIndicatorLamp                       highBeamIndicatorLamp;           /*!< Status of high beam indicator lamp (green/blue) in HMI. (default: HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_UNKNOWN),Accuracy: 1.0, Unit: [Enum],List:HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_UNKNOWN=0,HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_OFF=1,HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_GREEN=2,HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_BLUE=3  */
    RTE_HLA_SensMode                                          sensitivityModeSignal;           /*!< US sensitivity mode signal from user triggered by control stalk, for instance. (default: RTE_HLA_SENSMODE_UNKNOWN)  */
    RTE_HLAF_HighBeamState                                    headLightState;                  /*!< Current state of head lights to better understand current lighting situation: high beams off, high beam full on, high beam in partial mode (matrix), high beam in spot light mode (default: RTE_HLAF_HB_STATE_UNKNOWN)  */
    float32                                                   lightDistance;                   /*!< estimated forward lightning range of the headlamps if no glare free areas are available with respect to AUTOSAR (default: 0.0f), Unit: [m], Range:[0.0f.. 2000.0f]  */
} HLA_INTERFACES_HLA_BusInputSignals;           /* @versionstr: HLA_BUS_INPUT_SIGNALS_INTFVER */

/*! @brief glare free area state, reported from headlamps */
typedef struct
{
    float32                                                   cutOffAngleLeft;                 /*!< current position of the vertical cut off line for the left high beam with respect to AUTOSAR (default: 0.0°), Unit: [rad], Range:[-20° .. 20°]  */
    float32                                                   cutOffAngleRight;                /*!< current position of the vertical cut off line for the right high beam with respect to AUTOSAR (default: 0.0°), Unit: [rad], Range:[-20° .. 20°]  */
    float32                                                   cutOffAngleUpper;                /*!< current position of the horizontal cut off line for upper GFA border with respect to AUTOSAR (default: 0.0°), Unit: [rad], Range:[-10° .. 10°]  */
    float32                                                   cutOffAngleLower;                /*!< current position of the horizontal cut off line for lower GFA border with respect to AUTOSAR (default: 0.0°), Unit: [rad], Range:[-5° .. 15°]  */
} HLA_INTERFACES_HLA_BusInputSignals_GlareFreeArea;

/*! @brief Headlight Control data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                              uiVersionNumber;                 /*!< Interface version number (increased when changed)  */
    BASE_INTERFACES_SignalHeader_t                            sSigHeader;                      /*!< Signal header (Timestamp, ImageCnt, MeasurementCnt,...)  */
    RTE_HLAF_FunctionStatus                                   hlaFunctionStatus;               /*!< Status of HLA chain, mainly mapping of HLA component state,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF=0,RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF=1,RTE_HLAF_FUNCTION_STATUS_RUNNING=2,RTE_HLAF_FUNCTION_STATUS_INVALID=3  */
    HLA_INTERFACES_RTE_HLAF_HeadlightControl_Common           Common;                          /*!< common hlaf output signals like: city detection, highway detection, brightness detection, traffic style detection, ...  */
} HLA_INTERFACES_RTE_HLAF_HeadlightControl;           /* @versionstr: RTE_HLAF_HEADLIGHTCONTROL_INTFVER */

/*! @brief Common HLA output signals */
typedef struct
{
    RTE_HLA_TrafficStyle                                      TrafficStyle;                    /*!< HLA right/left hand traffic style,Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_TRAFFIC_STYLE_UNKNOWN=0,RTE_HLA_TRAFFIC_STYLE_RHT=1,RTE_HLA_TRAFFIC_STYLE_LHT=2,RTE_HLA_TRAFFIC_STYLE_INVALID=255  */
    RTE_HLAR_CityState                                        CityState;                       /*!< HLA city detection,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAR_CITY_UNKNOWN=0,RTE_HLAR_CITY_NOT_DTCD=1,RTE_HLAR_CITY_DTCD=2,RTE_HLAR_CITY_MAYBE=3,RTE_HLAR_CITY_INVALID=255  */
    RTE_HLAR_WeatherState                                     WeatherState;                    /*!< HLA weather detection,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAR_WEATHER_UNKNOWN=0,RTE_HLAR_WEATHER_GOOD=1,RTE_HLAR_WEATHER_BAD=2,RTE_HLAR_WEATHER_LIGHT_FOG=3,RTE_HLAR_WEATHER_MEDIUM_FOG=4,RTE_HLAR_WEATHER_HEAVY_FOG=5,RTE_HLAR_WEATHER_INVALID=255  */
    RTE_HLAR_Tunnel                                           TunnelState;                     /*!< HLA tunnel detection,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAR_TUNNEL_UNKNOWN=0,RTE_HLAR_TUNNEL_NOT_DTCD=1,RTE_HLAR_TUNNEL_UPFRONT=2,RTE_HLAR_TUNNEL_INSIDE=3,RTE_HLAR_TUNNEL_INVALID=255  */
    RTE_HLAF_MotorwayState                                    MotorwayState;                   /*!< HLA motorway detection,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_MTWY_UNKNOWN=0,RTE_HLAF_MTWY_COUNTRY=1,RTE_HLAF_MTWY_MOTORWAY=2,RTE_HLAF_MTWY_INVALID=255  */
    RTE_HLAR_BrightnessState                                  BrightnessState;                 /*!< HLA brightness detection,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAR_BRT_UNKNOWN=0,RTE_HLAR_BRT_DAY=1,RTE_HLAR_BRT_TWLGT_1=2,RTE_HLAR_BRT_TWLGT_2=3,RTE_HLAR_BRT_TWLGT_3=4,RTE_HLAR_BRT_NIGHT=5,RTE_HLAR_BRT_INVALID=255  */
    RTE_HLA_SensMode                                          SensMode;                        /*!< Sensitivity modes normal or e.g. for US,Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_SENSMODE_UNKNOWN=0,RTE_HLA_SENSMODE_NORMAL=1,RTE_HLA_SENSMODE_US=2,RTE_HLA_SENSMODE_INVALID=255  */
    RTE_HLAF_SpeedState                                       SpeedState;                      /*!< If speed is higher/lower than (De)ActivateSpeed (CPAR) which defines when to turn on/off high beam,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_SPEEDSTATE_UNKNOWN=0,RTE_HLAF_SPEEDSTATE_TOO_LOW=1,RTE_HLAF_SPEEDSTATE_IN_RANGE=2,RTE_HLAF_SPEEDSTATE_TOO_HIGH=3,RTE_HLAF_SPEEDSTATE_INVALID=255  */
    RTE_HLA_SceneInfo                                         SceneInfo;                       /*!< If oncoming vehicle is directly passing or preceding vehicle is overtaken directly this output is used to trigger very fast highbeam turn on,Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_SCENEINFO_UNKNOWN=0,RTE_HLA_SCENEINFO_ONCOMING_PASSING=1,RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING=2,RTE_HLA_SCENEINFO_INVALID=255  */
} HLA_INTERFACES_RTE_HLAF_HeadlightControl_Common;

/*! @brief HLA Matrix beam signals (glare free areas (GFA)) */
typedef struct
{
    HLA_INTERFACES_RTE_HLAF_MatrixGFA                         GFA[5];                          /*!< glare free area list  */
    uint8                                                     nGFA;                            /*!< number of Glare free areas, Range:[0u..(uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS]  */
    RTE_HLAF_SignalStatus                                     GFAStatus;                       /*!< glare free area status,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_SIGSTAT_UNKNOWN=0,RTE_HLAF_SIGSTAT_INIT=1,RTE_HLAF_SIGSTAT_DATA_VALID=2,RTE_HLAF_SIGSTAT_DATA_INVALID=3,RTE_HLAF_SIGSTAT_INVALID=255  */
    RTE_HLAF_HighBeamState                                    HighBeamState;                   /*!< high beam state recommendation,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_HB_STATE_UNKNOWN=0,RTE_HLAF_HB_STATE_OFF=1,RTE_HLAF_HB_STATE_FULL_ON=2,RTE_HLAF_HB_STATE_PARTIAL=3,RTE_HLAF_HB_STATE_SPOT=4,RTE_HLAF_HB_STATE_INVALID=255  */
    float32                                                   LowBeam_Dist;                    /*!< low beam distance recommendation with respect to Autosar limited by internal parameters LowBeam_Dist_Min and LowBeam_Dist_Max, Range:[0.0f .. 600.0f]  */
    float32                                                   LowBeam_Ang;                     /*!< object angle of the vehicle which defines the low beam distance with respect to Autosar limited by internal parameters LowBeamAng_Onc_Min and LowBeamAng_Onc_Max, Unit: [rad], Range:[-20° .. 20°]  */
    RTE_HLAF_ObjStatus                                        LowBeam_Status;                  /*!< object status of the vehicle which defines the low beam distance (preceding oncoming car),Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_OBJSTA_UNKNOWN=0,RTE_HLAF_OBJSTA_NO_OBJ=1,RTE_HLAF_OBJSTA_UNKNOWN_OBJ=2,RTE_HLAF_OBJSTA_PREC_OBJ=3,RTE_HLAF_OBJSTA_ONC_OBJ=4,RTE_HLAF_OBJSTA_INVALID=255  */
    RTE_HLAF_MatrixTurnOffReason                              TurnOffReason;                   /*!< HLA turn off reason,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_TURNOFFREASON_UNKNOWN=0,RTE_HLAF_TURNOFFREASON_ONC=1,RTE_HLAF_TURNOFFREASON_PREC=2,RTE_HLAF_TURNOFFREASON_SPEED=4,RTE_HLAF_TURNOFFREASON_BRIGHTNESS=8,RTE_HLAF_TURNOFFREASON_CITY=16,RTE_HLAF_TURNOFFREASON_FOG=32,RTE_HLAF_TURNOFFREASON_BLOCKAGE=64,RTE_HLAF_TURNOFFREASON_DELAY=128,RTE_HLAF_TURNOFFREASON_ERROR=256,RTE_HLAF_TURNOFFREASON_TUNNEL=512,RTE_HLAF_TURNOFFREASON_WEATHER=1024  */
} HLA_INTERFACES_RTE_HLAF_Matrix;

/*! @brief HLA Glare Free Area definition */
typedef struct
{
    float32                                                   BndryLeft_Ang;                   /*!< left boundary of GFA with respect to Autosar coordinate system limited by internal parameters BndryLeft_Ang_Min and BndryLeft_Ang_Max, Unit: [rad], Range:[-25° .. 25°]  */
    float32                                                   BndryLeft_Dist;                  /*!< distance of the object which defines the left boundary of GFA with respect to Autosar coordinate system limited by object distance, Unit: [m], Range:[0.0f .. 655.35f]  */
    float32                                                   BndryLeft_Ang_Cam;               /*!< left boundary of GFA with respect to camera coordinate system limited by internal parameters BndryLeft_Ang_Min and BndryLeft_Ang_Max, Unit: [rad], Range:[-25° .. 25°]  */
    RTE_HLAF_ObjStatus                                        BndryLeft_Status;                /*!< object status of left boundary (preceding oncoming car)  */
    uint8                                                     BndryLeft_ObjId;                 /*!< object ID that defines left boundary of GFA, Range:[0u..(LSD_LIGHT_OBJECT_LIST_LENGTH - 1u)]  */
    RTE_HLAF_DistState                                        BndryLeft_DistState;             /*!< specifies whether distance is measured from single or pair light,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_DISTSTATE_UNKNOWN=0,RTE_HLAF_DISTSTATE_SINGLELIGHT=1,RTE_HLAF_DISTSTATE_PAIRLIGHT=2,RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE=3,RTE_HLAF_DISTSTATE_INVALID=255  */
    RTE_HLA_DistReliability                                   BndryLeft_DistReliability;       /*!< Reliability of the distance estimation for the object which defines the left border,Accuracy: 1.0, Unit: [Enum],List:RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN=0,RTE_HLA_DISTANCE_RELIABILITY_LOW=1,RTE_HLA_DISTANCE_RELIABILITY_MID=2,RTE_HLA_DISTANCE_RELIABILITY_HIGH=3,RTE_HLA_DISTANCE_RELIABILITY_INVALID=255  */
    float32                                                   BndryRight_Ang;                  /*!< right boundary of GFA with respect to Autosar coordinate system limited by internal parameters BndryRight_Ang_Min and BndryRight_Ang_Max, Unit: [rad], Range:[-25° .. 25°]  */
    float32                                                   BndryRight_Dist;                 /*!< distance of the object which defines the right boundary of GFA with respect to Autosar coordinate system limited by object distance, Unit: [m], Range:[0.0f .. 655.35f]  */
    float32                                                   BndryRight_Ang_Cam;              /*!< right boundary of GFA with respect to camera coordinate system limited by internal parameters BndryRight_Ang_Min and BndryRight_Ang_Max, Unit: [rad], Range:[-25° .. 25°]  */
    RTE_HLAF_ObjStatus                                        BndryRight_Status;               /*!< object status of right boundary (preceding oncoming car)  */
    uint8                                                     BndryRight_ObjId;                /*!< object ID that defines left boundary of GFA, Range:[0u..(LSD_LIGHT_OBJECT_LIST_LENGTH - 1u)]  */
    RTE_HLAF_DistState                                        BndryRight_DistState;            /*!< specifies whether distance is measured from single or pair light  */
    RTE_HLA_DistReliability                                   BndryRight_DistReliability;      /*!< Reliability of the distance estimation for the object which defines the right border  */
    float32                                                   BndryLower_Ang_Cam;              /*!< lower boundary of GFA with respect to camera coordinate system limited by internal parameters BndryLower_Ang_Min and BndryLower_Ang_Max, Unit: [rad], Range:[-5° .. 5°]  */
    RTE_HLAF_ObjStatus                                        BndryLower_Status;               /*!< object status of lower boundary (preceding oncoming car)  */
    uint8                                                     BndryLower_ObjId;                /*!< object ID that defines lower boundary of GFA, Range:[0u..(LSD_LIGHT_OBJECT_LIST_LENGTH - 1u)]  */
    RTE_HLAF_DistState                                        BndryLower_DistState;            /*!< specifies whether distance is measured from single or pair light  */
    RTE_HLA_DistReliability                                   BndryLower_DistReliability;      /*!< Reliability of the distance estimation for the object which defines the lower border  */
    float32                                                   BndryUpper_Ang_Cam;              /*!< upper boundary of GFA with respect to camera coordinate system limited by internal parameters BndryUpper_Ang_Min and BndryUpper_Ang_Max, Unit: [rad], Range:[-10° .. 5°]  */
    RTE_HLAF_ObjStatus                                        BndryUpper_Status;               /*!< object status of upper boundary (preceding oncoming car)  */
    uint8                                                     BndryUpper_ObjId;                /*!< object ID that defines left boundary of GFA, Range:[0u..(LSD_LIGHT_OBJECT_LIST_LENGTH - 1u)]  */
    RTE_HLAF_DistState                                        BndryUpper_DistState;            /*!< specifies whether distance is measured from single or pair light  */
    RTE_HLA_DistReliability                                   BndryUpper_DistReliability;      /*!< Reliability of the distance estimation for the object which defines the upper border  */
    float32                                                   ClosestObj_Dist;                 /*!< distance of closest object (real world distance of object AUTOSAR) limited by internal parameters ClosestObj_Dist_Min and ClosestObj_Dist_Max, Unit: [m], Range:[0.0f .. 655.35f]  */
    float32                                                   ClosestObj_Ang;                  /*!< horizontal angle of closest object (AUTOSAR) limited by internal parameters ClostestObj_Ang_Min and ClostestObj_Ang_Max, Unit: [rad], Range:[-20° .. 20°]  */
    RTE_HLAF_ObjStatus                                        ClosestObj_Status;               /*!< object status of closest object (preceding oncoming car)  */
    uint8                                                     ClosestObj_ObjId;                /*!< object ID that defines left boundary of GFA, Range:[0u..(LSD_LIGHT_OBJECT_LIST_LENGTH - 1u)]  */
    RTE_HLAF_DistState                                        ClosestObj_DistState;            /*!< specifies whether distance is measured from single or pair light  */
    RTE_HLA_DistReliability                                   ClosestObj_DistReliability;      /*!< Reliability of the distance estimation for the object which defines the upper border  */
    float32                                                   MinLight_Dist;                   /*!< light distance where the oncoming/ preceding vehicle will not be blinded limited by internal parameters MinLight_Dist_Min and MinLight_Dist_Max, Unit: [m], Range:[0.0f .. 655.35f]  */
    float32                                                   MinLight_Ang;                    /*!< horizontal angle of "MinLight vehicle" (AUTOSAR) limited by internal parameters MinLight_Ang_Min and MinLight_Ang_Max, Unit: [rad], Range:[-20° .. 20°]  */
    RTE_HLAF_ObjStatus                                        MinLight_Status;                 /*!< object status of min. light distance (preceding oncoming car)  */
    uint8                                                     MinLight_ObjId;                  /*!< object ID that defines left boundary of GFA, Range:[0u..(LSD_LIGHT_OBJECT_LIST_LENGTH - 1u)]  */
    RTE_HLAF_DistState                                        MinLight_DistState;              /*!< specifies whether distance is measured from single or pair light  */
    float32                                                   ttb18Left;                       /*!< left boundary: time to border (+/-18°: depending on status/ moving direction) limited by ttb18Left of object, Unit: [s], Range:[0.0f..10.0f]  */
    RTE_HLAF_TTBStatus                                        ttb18Left_Status;                /*!< Status of ttb18Left (moving direction),Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_TTBSTA_UNKNOWN=0,RTE_HLAF_TTBSTA_NO_OBJ=1,RTE_HLAF_TTBSTA_DIR_UNKNOWN=2,RTE_HLAF_TTBSTA_DIR_LEFT=3,RTE_HLAF_TTBSTA_DIR_RIGHT=4,RTE_HLAF_TTBSTA_INVALID=255  */
    float32                                                   ttb18Right;                      /*!< right boundary: time to border (+/-18°: depending on status/ moving direction), Unit: [s], Range:[0.0f..10.0f]  */
    RTE_HLAF_TTBStatus                                        ttb18Right_Status;               /*!< Status of ttb18Right (moving direction)  */
    uint8                                                     ExistenceProb;                   /*!< existence probability of vehicle(s) in the GFA, Unit: [%], Range:[0u.. 100u]  */
} HLA_INTERFACES_RTE_HLAF_MatrixGFA;

/*! @brief HLA light dim down area signals (for bright reflecting areas) */
typedef struct
{
    RTE_HLAF_DimmingStatus                                    DimmingStatus;                   /*!< Status of the dimming function,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_DIMM_STATE_UNKNOWN=0,RTE_HLAF_DIMM_STATE_AVL=1,RTE_HLAF_DIMM_STATE_LIMITED=2,RTE_HLAF_DIMM_STATE_NAVL=3,RTE_HLAF_DIMM_STATE_ERROR=4,RTE_HLAF_DIMM_STATE_INVALID=255  */
    uint8                                                     Padding;                         /*!< Padding byte for alignment  */
    RTE_HLAF_DimmingLevel                                     DimmingArea[5];                  /*!< List which holds the dimming areas,Accuracy: 1.0, Unit: [Enum],List:RTE_HLAF_DIMM_LEVEL_UNKNOWN=0,RTE_HLAF_DIMM_LEVEL_NO_REDUCT=1,RTE_HLAF_DIMM_LEVEL_REDUCT_1=2,RTE_HLAF_DIMM_LEVEL_REDUCT_2=3,RTE_HLAF_DIMM_LEVEL_INVALID=255  */
} HLA_INTERFACES_RTE_HLAF_LightDimming;


#ifdef __cplusplus
}
#endif

#endif /* #if (GA_CFG_HLA_INTERFACES == 1) */

/*! @} end defgroup */

#endif /* #ifndef GA_HLA_INTERFACES_EXT_H_INCLUDED */
