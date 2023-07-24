#ifndef _GA_GLOBAL_H_INCLUDED
#error include setup error: forbidden inclusion of GA local-scope header file; only component *_main.h + *_wrapper.h, and ga_global.h (or ga_global_emlib.h on emlib dependancy) are allowed
#endif

#ifndef GA_TSA_INTERFACES_EXT_H_INCLUDED
#define GA_TSA_INTERFACES_EXT_H_INCLUDED

/*! @ingroup tsa_interfaces
@{
@file
External header of the TSA_INTERFACES component.    */


#if (GA_CFG_TSA_INTERFACES == 1)

#ifdef __cplusplus
extern "C" {
#endif

/* --- virtual addresses --------------------------------------------------- */
#define TSA_INTERFACES_VA_CONTROL_DATA       ()   /*!< virtual address of controlData (uL) */

/* ---- constants ---------------------------------------------------------- */
#define TSA_RTE_CUSTOM_SIGN_RESULT_TRACKS_MAX                              (16)
#define TSA_RTE_CUSTOM_SIGN_RESULT_NUM_MAIN_CLASSES                        (5)
#define TSA_RTE_CUSTOM_SIGN_RESULT_NUM_SUPPL_CLASSES                       (5)
#define TSA_RTE_CUSTOM_SIGN_RESULT_INFO_LENGTH                             (2)
#define TSA_RTE_SLA_NUM_RESULTS                                            (3)
#define TSA_RTE_NVM_SLA_NUM_RESULTS                                        (2)
#define TSA_RTE_SLA_HEALTH_LEN                                             (16)
#define TSA_RTE_ROADFORSIGHT_CURVEFORESIGHT_LEN                            (15)
#define TSA_RTE_ROADFORSIGHT_ROADTOPOLOGY_LEN                              (10)
#define TSA_RTE_ROADCHARACTERISTICS_LEN                                    (10)
#define TSA_RTE_SPEEDFORESIGHTDATA_LEN                                     (10)
#define TSA_RTE_CUSTOM_INPUT_RESERVED_BYTES_NUM                            (8)
#define TSA_RTE_ISO3166_REGION_SHORT_NAME_LENGTH                           (8)
#define TSA_RTE_NVM_WWA_RESERVED_BYTES_NUM                                 (16)
#define TSA_RTE_NVM_GWW_RESERVED_BYTES_NUM                                 (16)
#define TSA_RTE_NVM_RESERVED_BYTES_NUM                                     (50)
#define TSA_RTE_CPAR_WWA_CC_LENGTH                                         (24)
#define TSA_RTE_ROADFORSIGHT_CROSSINGFORESIGHT_CROSSING_LEN                (3)
#define TSA_RTE_ROADFORSIGHT_CROSSINGFORESIGHT_CROSSING_BRANCHES_LEN       (8)
#define TSA_RTE_CPAR_EXP_TAB_SIZE                                          (5)
#define TSA_RTE_TA19_NAVI_EU_SPDLMT_NUM                                    (6)
#define TSA_RTE_TA19_NAVI_EU_NUM_OF_LINKS                                  (5)

/* ---- type InterfaceVersion ---------------------------------------------- */
#define TSA_INTERFACES_CONTROL_DATA_INTVER  (1)  /*!< version of TSA_INTERFACES_ControlData */
#define TSA_RTE_CODING_PARAMS_INTFVER       (132097)  /*!< version of TSA_INTERFACES_CPAR_TSA_RTE_parameters_t */
#define TSA_RTE_CUSTOM_INPUT_INTFVER        (327682)  /*!< version of TSA_INTERFACES_TsaRteCustomInput_t */
#define RTE_INPUT_GPS_INTFVER               (65793)  /*!< version of TSA_INTERFACES_RteInputGPS_t */
#define TSA_RTE_OUTPUT_RESULTS_INTFVER      (67584)  /*!< version of TSA_INTERFACES_TsaRteOutputResults_t */
#define TSA_RTE_NVM_STATE_INTFVER           (131076)  /*!< version of TSA_INTERFACES_NvmTsaRteState_t */
#define TSA_RTE_INPUT_NAVIGATION_INTFVER    (66048)  /*!< version of TSA_INTERFACES_TsaRteInputNavigation_t */

/* ---- type definitions --------------------------------------------------- */
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_UNKNOWN                                   (0u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_ECE                                       (1u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_GULF                                      (2u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_USA                                       (3u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_CANADA                                    (4u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_ROW                                       (5u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_JPCN                                      (6u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_ISRAEL                                    (7u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_CYPRUS                                    (8u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_CROATIA                                   (9u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_TURKEY                                    (10u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_BELARUS                                   (11u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_CHINA                                     (12u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_SAFRICA                                   (13u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_AUSTRALIA                                 (14u)
#define tsa_interfaces_TSA_RTE_COUNTRY_VARIATION_SKOREA                                    (15u)

/*! @brief market for which vehicle was produced */
typedef uint8 TSA_INTERFACES_TsaCountryVariationVehicle;

#define tsa_interfaces_TSA_RTE_NAV_IDENTIFIER_NO                                           (0u)
#define tsa_interfaces_TSA_RTE_NAV_IDENTIFIER_ONLY_CCO                                     (1u)
#define tsa_interfaces_TSA_RTE_NAV_IDENTIFIER_MAP                                          (2u)
#define tsa_interfaces_TSA_RTE_NAV_IDENTIFIER_HI17                                         (3u)
#define tsa_interfaces_TSA_RTE_NAV_IDENTIFIER_TA19                                         (4u)

/*! @brief Identifier, which indicated, what kind of Navigation Input Data TSA shall receive. */
typedef uint8 TSA_INTERFACES_TsaNavigationInputIdentifier;

#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_NAVTEQ                                       (0u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_TELEATLAS                                    (1u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_ZENRIN                                       (2u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_ADF                                          (3u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_NAVINFO                                      (4u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_RESERVED                                     (5u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_NOT_AVAILABLE                                (6u)
#define tsa_interfaces_INPUT_GPS_MAP_PROVIDER_INVALID                                      (7u)

/*! @brief Map Provider */
typedef uint8 TSA_INTERFACES_MapProvider;

#define tsa_interfaces_TSA_RTE_MOTORWAY_UNKNOWN                                            (0u)
#define tsa_interfaces_TSA_RTE_MOTORWAY_TRUE                                               (1u)
#define tsa_interfaces_TSA_RTE_MOTORWAY_FALSE                                              (2u)
#define tsa_interfaces_TSA_RTE_MOTORWAY_SNA                                                (3u)

typedef uint8 TsaRteCurrentMotorway_t;

#define tsa_interfaces_TSA_RTE_URBAN_AREA_UNKNOWN                                          (0u)
#define tsa_interfaces_TSA_RTE_URBAN_AREA_TRUE                                             (1u)
#define tsa_interfaces_TSA_RTE_URBAN_AREA_FALSE                                            (2u)
#define tsa_interfaces_TSA_RTE_URBAN_AREA_SNA                                              (3u)

typedef uint8 TsaRteCurrentUrbanArea_t;

#define tsa_interfaces_TSA_RTE_URBAN_AREA_CHANGE_UNKNOWN                                   (0u)
#define tsa_interfaces_TSA_RTE_URBAN_AREA_CHANGE_NO_CHANGE_AHEAD                           (1u)
#define tsa_interfaces_TSA_RTE_URBAN_AREA_CHANGE_OUTSIDE_TO_INSIDE                         (2u)
#define tsa_interfaces_TSA_RTE_URBAN_AREA_CHANGE_INSIDE_TO_OUTSIDE                         (3u)

typedef uint8 TsaRteUrbanAreaChange_t;

#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_NO                                          (0u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_SL                                          (1u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_SLE                                         (2u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_START                             (3u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_END                               (4u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_START                            (5u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_END                              (6u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_START                               (7u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_END                                 (8u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_START                              (9u)
#define tsa_interfaces_TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_END                                (10u)

/*! @brief type of sign */
typedef uint8 TSA_INTERFACES_signType;

#define tsa_interfaces_TSA_RTE_SLA_SUPPLVALSTAT_UNKNOWN                                    (0u)
#define tsa_interfaces_TSA_RTE_SLA_SUPPLVALSTAT_INVALID                                    (1u)
#define tsa_interfaces_TSA_RTE_SLA_SUPPLVALSTAT_VALID                                      (2u)
#define tsa_interfaces_TSA_RTE_SLA_SUPPLVALSTAT_EXTRAPOL                                   (3u)

/*! @brief validity of supplementary signs */
typedef uint8 TsaRteSlaSupSgnVal_t;

#define tsa_interfaces_TSA_RTE_NPA_PASSING_STATE_IDLE                                      (0u)
#define tsa_interfaces_TSA_RTE_NPA_PASSING_STATE_ALLOWED                                   (1u)
#define tsa_interfaces_TSA_RTE_NPA_PASSING_STATE_CANCEL                                    (2u)
#define tsa_interfaces_TSA_RTE_NPA_PASSING_STATE_FORBIDDEN                                 (3u)

/*! @brief current no-passing information */
typedef uint8 TsaRteNpaStatus_t;

#define tsa_interfaces_TSA_RTE_NPA_SUPPLVALSTAT_UNKNOWN                                    (0u)
#define tsa_interfaces_TSA_RTE_NPA_SUPPLVALSTAT_INVALID                                    (1u)
#define tsa_interfaces_TSA_RTE_NPA_SUPPLVALSTAT_VALID                                      (2u)
#define tsa_interfaces_TSA_RTE_NPA_SUPPLVALSTAT_EXTRAPOL                                   (3u)

/*! @brief current suppl sign validity */
typedef uint8 TsaRteNpaSupplSignValState_t;

#define tsa_interfaces_TSA_RTE_RWF_STATUS_UNKNOWN                                          (0u)
#define tsa_interfaces_TSA_RTE_RWF_STATUS_NO                                               (1u)
#define tsa_interfaces_TSA_RTE_RWF_STATUS_YES                                              (2u)

/*! @brief current road works information */
typedef uint8 TsaRteRwfStatus_t;

#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_SPD_LMT_CAM_VS_MAP                            (1u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_SPD_LMT_FUNNEL                                (2u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_SIGN_REPET_RATE                               (4u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_SIGN_BACK_COLOR                               (8u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_LANE_MARK_COLOR                               (16u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_SIGN_INVALIDATED                              (32u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_LANE_WIDTH                                    (64u)
#define tsa_interfaces_TSA_RTE_RWF_INDICATOR_RW_SIGN                                       (128u)

/*! @brief indicators for recognized road works */
typedef uint8 TsaRteRwfIndicators_t;

#define tsa_interfaces_TSA_RTE_WWA_WRONG_WAY_IDLE                                          (0u)
#define tsa_interfaces_TSA_RTE_WWA_NOT_DRIVING_WRONG_WAY                                   (1u)
#define tsa_interfaces_TSA_RTE_WWA_DRIVING_WRONG_WAY                                       (2u)

/*! @brief current wrong way status */
typedef uint8 TSARteWwaStatus_t;

#define tsa_interfaces_TSA_RTE_GWW_IDLE                                                    (0u)
#define tsa_interfaces_TSA_RTE_GWW_STOP_SIGN                                               (1u)
#define tsa_interfaces_TSA_RTE_GWW_GW_SIGN                                                 (2u)
#define tsa_interfaces_TSA_RTE_GWW_TRAFFIC_LIGHT                                           (3u)
#define tsa_interfaces_TSA_RTE_GWW_RES1                                                    (4u)
#define tsa_interfaces_TSA_RTE_GWW_RES2                                                    (5u)
#define tsa_interfaces_TSA_RTE_GWW_RES3                                                    (6u)

/*! @brief type of Give Way event */
typedef uint8 TSA_INTERFACES_eventType;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ACTIVE                       (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ENDED                        (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_PASSED                       (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_FINISHED                     (3u)

/*! @brief sign result track states */
typedef uint8 TSA_INTERFACES_TsaRteCustomSignResultTrackState_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NONE                        (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN               (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_VEHICLE                  (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_INFO_SIGN                (4u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NEVER_PASSED                (8u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_CLASS_SHAKY                 (16u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED        (32u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_RESERVED                    (64u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_PART_OF_GATE             (128u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_EMBEDDED                 (256u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED        (512u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND       (1024u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED            (2048u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DISABELED                   (4096u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT        (8192u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL  (16384u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_MODIFIED_CLASS              (32768u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HIGHWAY_EXIT                (65536u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_OTHER_LANE              (131072u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_PARALLEL_ROAD           (262144u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_DIVERTING_ROAD          (524288u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FAR_IRRELEVANT              (1048576u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_EGO_RELEVANCE_UNCLEAR       (2097152u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DURING_TURN                 (4194304u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTIVE                      (8388608u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ENDED_IN_ROI                (16777216u)

typedef uint32 TSA_INTERFACES_TsaRteCustomSignResultTrackCharacteristics_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_CIRCULAR                      (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_RECTANGULAR                   (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_TRIANGULAR                    (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_DIAMOND                       (3u)

/*! @brief sign geometry */
typedef uint8 TSA_INTERFACES_TsaRteCustomSignResultGeometry_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_UNKNOWN                             (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_KMH                                 (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_MPH                                 (2u)

/*! @brief sign unit */
typedef uint8 TSA_INTERFACES_TsaRteCustomSignResultUnit_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_BELOW                        (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_ABOVE                        (1u)

/*! @brief relative supplementary sign position */
typedef uint8 TSA_INTERFACES_TsaRteCustomSignSupplResultPosition_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_SIGN                                   (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_PASSING                           (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_NO_PASSING_SIGN           (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT               (3u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERAL_WITHDRAWAL                   (4u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_5                        (5u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_10                       (6u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_15                       (7u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_20                       (8u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_25                       (9u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_30                       (10u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_35                       (11u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_40                       (12u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_45                       (13u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_50                       (14u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_55                       (15u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_60                       (16u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_65                       (17u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_70                       (18u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_75                       (19u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_80                       (20u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_85                       (21u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_90                       (22u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_95                       (23u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_100                      (24u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_105                      (25u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_110                      (26u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_115                      (27u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_120                      (28u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_125                      (29u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_130                      (30u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_135                      (31u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_140                      (32u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_145                      (33u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RAIN                                (34u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_FOG                                 (35u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW                                (36u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW_RAIN                           (37u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TIME                                (38u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SCHOOL                              (39u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_WEIGHT                              (40u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_IN                         (41u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_FOR                        (42u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT                          (43u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT                         (44u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT_BEND                     (45u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT_BEND                    (46u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRUCK                               (47u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED              (48u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_HAZARDOUS                           (49u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRAILER                             (50u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_NIGHT                               (51u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ZONE                                (52u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_4WAY                           (53u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE                          (54u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_2_DIGITS      (55u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_3_DIGITS      (56u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_LEFT                         (75u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_RIGHT                        (76u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_STRAIGHT                     (77u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ROUNDABOUT_SIGN                      (78u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_ENTRY                             (79u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_VEHICLES_PROHIBITED                  (80u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_START                       (81u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_END                         (82u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_START                     (83u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_END                       (84u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_START           (85u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_END             (86u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_STOP_SIGN                            (87u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GIVE_WAY                             (88u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_START                  (89u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_END                    (90u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_LEFT                          (91u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_RIGHT                         (92u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT_FIR               (93u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT_FI               (94u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SID               (95u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SID               (96u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SI               (97u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD                         (98u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROA               (99u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_LEFT_45_DE               (100u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_RIGHT_45_D               (101u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ONE_BUMP                           (102u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_BUMP                           (103u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CONCAVE                            (104u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_JAM                        (105u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_WORKS                         (106u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_DOWNWARDS                    (107u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_UPWARDS                      (108u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_LIGHT                      (109u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ANIMAL_CROSSING                    (110u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CHILDREN                           (111u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SNOW                               (112u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SPLIPPERY_ROAD                     (113u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GIVE_WAY_ROUNDABOUT                (114u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_WIND_FROM_SIDE                     (115u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_PEDESTRIAN_CROSSING                (116u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BYCICLE_CROSSING                   (117u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITHOUT_               (118u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITH_BAR               (119u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GRAVEL                             (120u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC                    (121u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START                     (122u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_END                       (123u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START_END                 (124u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_START             (125u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END               (126u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERIC_SUPPLEMENTAL                 (127u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TEXT                                (128u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_PICTURE                             (129u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_IN                             (130u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE_ALLOWED                  (131u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_CAR                                 (132u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RESTRICTED                          (133u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_PASSING_TRUCK                     (134u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_NO_PASSING_TRUCK          (135u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_UNKNOWN                                   (254u)

/*! @brief sign class IDs (with meaning) only the classes actually output by SR are listed */
typedef uint8 TSA_INTERFACES_TsaRteCustomSignFunctionalSignClassId_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_INDICATION                             (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SPEED_LIMIT                               (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_SPEED_LIMIT_END                           (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_ALL_WITHDRAWAL                            (7u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_HIGHWAY_START                             (16u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_HIGHWAY_END                               (17u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MOTORWAY_START                            (18u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_MOTORWAY_END                              (19u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_AREA_START                        (20u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_AREA_END                          (21u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_HOME_ZONE_START                           (22u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_HOME_ZONE_END                             (23u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_ISRAEL_START                      (24u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_ISRAEL_END                        (25u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_RH                                (65u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_LH                                (66u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_END                               (67u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_JAPAN                             (70u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_JAPAN_END                         (71u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_US                                (72u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_US_END                            (73u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_CANADA                            (74u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_CANADA_END                        (75u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SIGN_CLASS_NO_ENTRY                                  (129u)

/*! @brief custom RTE Sign class definition */
typedef uint8 TSA_INTERFACES_TsaRteCustomSignClass_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_GRAY_LVL_NO_GRAYING                                  (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_GRAY_LVL_1                                           (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_GRAY_LVL_2                                           (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_GRAY_LVL_3                                           (3u)

/*! @brief custom RTE Gray Levels */
typedef uint8 TSA_INTERFACES_TsaRteCustomGrayLevel_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_HIGHLIGHT_OFF                                        (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_HIGHLIGHT_REVERSING                                  (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_HIGHLIGHT_BLINKING                                   (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_HIGHLIGHT_RESERVED                                   (3u)

/*! @brief custom RTE Highlight Status */
typedef uint8 TSA_INTERFACES_TsaRteCustomHighlightStatus_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_NO_INDICATION                       (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_APPLIED_TIME                        (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_EXIT_RAMP_RIGHT                     (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_EXIT_RAMP_LEFT                      (3u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_WET                            (4u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_RAIN                           (5u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_ICE                            (6u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_UNK                                 (15u)

/*! @brief custom supplementary sign class definition */
typedef uint8 TSA_INTERFACES_TsaRteCustomSupplSignClass_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_BUZZER_REQUEST_OFF                                   (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_BUZZER_REQUEST_ON                                    (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_BUZZER_REQUEST_RESERVED_1                            (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_BUZZER_REQUEST_RESERVED_2                            (3u)

/*! @brief custom buzzer request */
typedef uint8 TSA_INTERFACES_TsaRteCustomBzrReq_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_SPEED_UNIT_UNK                                       (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SPEED_UNIT_KHM                                       (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SPEED_UNIT_MPH                                       (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_SPEED_UNIT_RESERVED                                  (3u)

/*! @brief custom speed unit type */
typedef uint8 TSA_INTERFACES_TsaRteCustomSpeedUnit_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_NOTICE_METHOD_UNK                                    (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_NOTICE_METHOD_OFF                                    (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_NOTICE_METHOD_ONLY_VISIBLE                           (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_NOTICE_METHOD_VISIBLE_AND_AUDIBLE                    (3u)

/*! @brief custom notice method */
typedef uint8 TSA_INTERFACES_TsaRteCustomNoticeMethod_t;

#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_MINUS_5                                      (0u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_MINUS_4                                      (1u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_MINUS_3                                      (2u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_MINUS_2                                      (3u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_MINUS_1                                      (4u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_0                                            (5u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_1                                            (6u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_2                                            (7u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_3                                            (8u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_4                                            (9u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_5                                            (10u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_6                                            (11u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_7                                            (12u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_8                                            (13u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_9                                            (14u)
#define tsa_interfaces_TSA_RTE_CUSTOM_OVSPVAL_10                                           (15u)

/*! @brief custom definition for overspeed start values */
typedef uint8 TSA_INTERFACES_TsaRteCustomOvSpdStartVal_t;

#define tsa_interfaces_TSA_RTE_CONDITION_FLAG_DEACTIVATED                                  (0u)
#define tsa_interfaces_TSA_RTE_CONDITION_FLAG_RESERVED                                     (1u)
#define tsa_interfaces_TSA_RTE_CONDITION_FLAG_NOT_APPLICABLE                               (2u)
#define tsa_interfaces_TSA_RTE_CONDITION_FLAG_APPLICABLE                                   (3u)

/*! @brief condition flag for ice/rain/turn */
typedef uint8 TsaRteConditionFlag_t;

#define tsa_interfaces_TSA_RTE_EXIT_RAMP_DEACTIVATED                                       (0u)
#define tsa_interfaces_TSA_RTE_EXIT_RAMP_IDLE                                              (1u)
#define tsa_interfaces_TSA_RTE_EXIT_RAMP_RIGHT                                             (2u)
#define tsa_interfaces_TSA_RTE_EXIT_RAMP_LEFT                                              (3u)

/*! @brief flag for exit (not active, not detected, right, left) */
typedef uint8 TsaRteExitRampFlag_t;

#define tsa_interfaces_TSA_RTE_DRIVING_DISTANCE_INVALID                                    (0u)
#define tsa_interfaces_TSA_RTE_DRIVING_DISTANCE_VALID                                      (1u)

/*! @brief is the signal valid or not */
typedef uint8 TSA_INTERFACES_signalState;

#define tsa_interfaces_TSA_RTE_SGN_CLS_UNKNOWN                                             (0u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_RESTRICTED                                    (100000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_ARROW_LEFT                                    (100010u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_CURVED_ARROW_LEFT                             (100011u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_ARROW_RIGHT                                   (100020u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_CURVED_ARROW_RIGHT                            (100021u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_VALID_FOR_DISTANCE                            (100100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_VALID_IN_DISTANCE                             (100400u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_ONLY_INFORMATION_PICT                         (100600u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_ONLY_INFORMATION_TEXT_ONE_ROW                 (100601u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_ZONE                                          (100604u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_GARBAGE                                       (100990u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_EXCLAMATION_MARK                             (101000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_CROSS_ROAD                                   (102000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_BEND_LEFT                                    (103010u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_BEND_RIGHT                                   (103020u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_TIME_RESTRICTION                              (104030u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_NIGHT                                         (104040u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_WORKDAYS                                      (104230u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_WORKDAYS_AND_TIME                             (104231u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_MON2FRI_AND_TIME                              (104233u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_MOTORCYCLE                                    (104610u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_PASSENGER_CAR                                 (104810u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_PASSENGER_CAR_TRAILER                         (104811u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_TRUCK_BUS                                     (104812u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_TRACTORS_MAY_BE_PASSED                        (104911u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_TRUCK_BUS_CAR_TRAILER                         (104913u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_DOUBLE_BEND_LEFT                             (105010u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_DOUBLE_BEND_RIGHT                            (105020u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_WEIGHT                                        (105235u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_WET                                           (105236u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_FOGGY                                         (105237u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_ICY                                           (105238u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_SCHOOL                                        (105239u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_X_WAY                                         (105240u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_SNOW_RAIN                                     (105241u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_SUPPL_RAIN                                          (105242u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_STEEP_HILL_DOWNWARDS                         (108000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_STEEP_HILL_UPWARDS                           (110000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_BUMPS                                        (112000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_SNOW                                         (113000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_SLIPPERY_ROAD                                (114000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_GRAVEL                                       (116000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_WIND                                         (117000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_BOTH_SIDES                       (120000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_RIGHT_SIDE                       (121010u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_LEFT_SIDE                        (121020u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_ROAD_WORK                                    (123000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_TRAFFIC_JAM                                  (124000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_TWO_WAY_TRAFFIC                              (125000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_TRAFFIC_LIGHTS                               (131000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_PEDESTRIAN                                   (133000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_PEDESTRIAN_ZEBRA_CROSSING                    (134000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_DANGER_CHILDREN                              (136000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_CYCLIST_CROSSING                             (138000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_ANIMAL_CROSSING                              (142000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_TRAIN_CROSS                                  (151000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_GIVE_WAY                                     (205000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_STOP                                           (206000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_TURN_LEFT                            (209100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_TURN_RIGHT                           (209200u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT                             (209300u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GARBAGE_DIR_ARROW                              (209990u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_SIDE_LEFT                            (211100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_SIDE_RIGHT                           (211200u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_LEFT               (214100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_RIGHT              (214200u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_ROUNDABOUT                                     (215000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_PASS_LEFT                            (222100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_PASS_RIGHT                           (222200u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_PROHIB_ALL                                     (250000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GARBAGE_PROHIB                                 (250990u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_PROHIB_CAR                                     (251000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_PROHIB_MOTORBIKE_CAR                           (260000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_NO_ENTRY                                       (267000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE                             (270100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE_GREEN                       (270110u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE_END                         (270200u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_005                                         (274505u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_005_ACTIVE                                  (274506u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_010                                         (274510u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_010_ACTIVE                                  (274511u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_015                                         (274515u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_015_ACTIVE                                  (274516u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_020                                         (274520u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_020_ACTIVE                                  (274521u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_025                                         (274525u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_025_ACTIVE                                  (274526u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_030                                         (274530u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_030_ACTIVE                                  (274531u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_035                                         (274535u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_035_ACTIVE                                  (274536u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_040                                         (274540u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_040_ACTIVE                                  (274541u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_045                                         (274545u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_045_ACTIVE                                  (274546u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_050                                         (274550u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_050_ACTIVE                                  (274551u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_055                                         (274555u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_055_ACTIVE                                  (274556u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_060                                         (274560u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_060_ACTIVE                                  (274561u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_065                                         (274565u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_065_ACTIVE                                  (274566u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_070                                         (274570u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_070_ACTIVE                                  (274571u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_075                                         (274575u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_075_ACTIVE                                  (274576u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_080                                         (274580u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_080_ACTIVE                                  (274581u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_085                                         (274585u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_085_ACTIVE                                  (274586u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_090                                         (274590u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_090_ACTIVE                                  (274591u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_095                                         (274595u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_095_ACTIVE                                  (274596u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_100                                         (274600u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_100_ACTIVE                                  (274601u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_110                                         (274610u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_110_ACTIVE                                  (274611u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_120                                         (274620u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_120_ACTIVE                                  (274621u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_130                                         (274630u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_130_ACTIVE                                  (274631u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_140                                         (274640u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_140_ACTIVE                                  (274641u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_150                                         (274650u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_150_ACTIVE                                  (274651u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_160                                         (274660u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_160_ACTIVE                                  (274661u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_170                                         (274670u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_170_ACTIVE                                  (274671u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_180                                         (274680u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_180_ACTIVE                                  (274681u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_190                                         (274690u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_190_ACTIVE                                  (274691u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GARBAGE                                        (274990u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GARBAGE_ACTIVE                                 (274991u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING                                 (276000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_ACTIVE                          (276001u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING                               (277000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_ACTIVE                        (277001u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_BUNDLE_TWO_DIGIT_END                           (278200u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_BUNDLE_TWO_DIGIT_END_ACTIVE                    (278201u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_BUNDLE_THREE_DIGIT_END                         (278300u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_BUNDLE_THREE_DIGIT_END_ACTIVE                  (278301u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_005_END                                     (278505u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_010_END                                     (278510u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_015_END                                     (278515u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_020_END                                     (278520u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_025_END                                     (278525u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_030_END                                     (278530u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_035_END                                     (278535u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_040_END                                     (278540u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_045_END                                     (278545u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_050_END                                     (278550u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_055_END                                     (278555u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_060_END                                     (278560u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_065_END                                     (278565u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_070_END                                     (278570u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_075_END                                     (278575u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_080_END                                     (278580u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_085_END                                     (278585u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_090_END                                     (278590u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_095_END                                     (278595u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_100_END                                     (278600u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_110_END                                     (278610u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_120_END                                     (278620u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_130_END                                     (278630u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_140_END                                     (278640u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_150_END                                     (278650u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_160_END                                     (278660u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_170_END                                     (278670u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_180_END                                     (278680u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_SL_190_END                                     (278690u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GARBAGE_END                                    (278990u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GARBAGE_END_ACTIVE                             (278991u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_END                             (280000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_END_ACTIVE                      (280001u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_BUNDLE_NO_PASSING_END                          (280100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE                   (280101u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_END                           (281000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_END_ACTIVE                    (281001u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GENERAL_END                                    (282000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_GENERAL_END_ACTIVE                             (282001u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_HOUSE_BEGIN                         (290000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_HOUSE_END                           (290100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_DANGER_CROSS_ROAD_SMALL_ROAD                        (301000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_BEGIN                               (310000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_END                                 (311000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_PLAY_STREET_BEGIN                              (325000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_PLAY_STREET_END                                (326000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_HIGHWAY_BEGIN                                  (330000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_MOTORWAY                                       (330100u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_MOTORWAY_BEGIN                                 (331000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_HIGHWAY_END                                    (334000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_MAIN_MOTORWAY_END                                   (336000u)
#define tsa_interfaces_TSA_RTE_SGN_CLS_CLUSTER_GARBAGE                                     (999990u)

/*! @brief definition of tsa functional sign classes */
typedef uint32 TSA_INTERFACES_TsaRteSignClassId_t;

#define tsa_interfaces_TSA_RTE_SGN_DEC_BASE_UKN                                            (0u)
#define tsa_interfaces_TSA_RTE_SGN_DEC_BASE_MAP_RULE                                       (1u)
#define tsa_interfaces_TSA_RTE_SGN_DEC_BASE_MAP_IMPL                                       (2u)
#define tsa_interfaces_TSA_RTE_SGN_DEC_BASE_MAP_EXPL                                       (3u)
#define tsa_interfaces_TSA_RTE_SGN_DEC_BASE_CAM                                            (4u)
#define tsa_interfaces_TSA_RTE_SGN_DEC_BASE_MAP_CAM                                        (5u)

/*! @brief on which input is the sign based */
typedef uint8 TSA_INTERFACES_TsaRteSignDecisionBase_t;

#define tsa_interfaces_TSA_RTE_SPD_UNT_UNKNOWN                                             (0u)
#define tsa_interfaces_TSA_RTE_SPD_UNT_KMH                                                 (1u)
#define tsa_interfaces_TSA_RTE_SPD_UNT_MPH                                                 (2u)
#define tsa_interfaces_TSA_RTE_SPD_UNT_BOTH                                                (3u)
#define tsa_interfaces_TSA_RTE_SPD_UNT_SNA                                                 (4u)

/*! @brief definition for TSA speed unit type */
typedef uint8 TSA_INTERFACES_TsaRteSpeedUnit_t;

#define tsa_interfaces_TSA_RTE_TRF_STL_UNKNOWN                                             (0u)
#define tsa_interfaces_TSA_RTE_TRF_STL_RIGHTHAND                                           (1u)
#define tsa_interfaces_TSA_RTE_TRF_STL_LEFTHAND                                            (2u)
#define tsa_interfaces_TSA_RTE_TRF_STL_SNA                                                 (3u)

/*! @brief definition for TSA traffic style type */
typedef uint8 TSA_INTERFACES_TsaRteTrafficStyle_t;

#define tsa_interfaces_TSA_RTE_WARN_OFF                                                    (0u)
#define tsa_interfaces_TSA_RTE_WARN_ON                                                     (1u)
#define tsa_interfaces_TSA_RTE_WARN_SNA                                                    (2u)

/*! @brief definition for TSA warning type */
typedef uint8 TSA_INTERFACES_TsaRteWarning_t;

#define tsa_interfaces_TSA_RTE_ACTIVATION_STATUS_SNA                                       (0u)
#define tsa_interfaces_TSA_RTE_ACTIVATION_STATUS_ON                                        (1u)
#define tsa_interfaces_TSA_RTE_ACTIVATION_STATUS_OFF                                       (2u)

/*! @brief definition for TSA activaiton Status */
typedef uint8 TSA_INTERFACES_TsaRteActivationStatus_t;

#define tsa_interfaces_TSA_RTE_STREET_TYPE_SNA                                             (0u)
#define tsa_interfaces_TSA_RTE_STREET_TYPE_CITY                                            (1u)
#define tsa_interfaces_TSA_RTE_STREET_TYPE_OVERLAND                                        (2u)
#define tsa_interfaces_TSA_RTE_STREET_TYPE_MOTORWAY                                        (3u)
#define tsa_interfaces_TSA_RTE_STREET_TYPE_RES                                             (4u)

/*! @brief defintion for TSA street types */
typedef uint8 TSA_INTERFACES_TsaRteStreet_t;

#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_IDLE                                          (0u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_UNLIM                                         (1u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_ICY                                           (2u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_FOG                                           (3u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_WET                                           (4u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_TIME                                          (5u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_DARK                                          (6u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_EXT_LFT                                       (7u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_EXT_RGT                                       (8u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_TRAILER                                       (9u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_RESTRICTED                                    (10u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_RAIN                                          (11u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_TRUCK                                         (12u)
#define tsa_interfaces_TSA_RTE_SIGN_VALIDITY_CAR                                           (13u)

/*! @brief sign validity information */
typedef uint8 TSA_INTERFACES_TsaRteSignVal_t;

#define tsa_interfaces_TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_NONE                               (0u)
#define tsa_interfaces_TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_HI17                               (1u)
#define tsa_interfaces_TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_EU                            (2u)
#define tsa_interfaces_TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_JP                            (3u)

/*! @brief a flag, which indicates, which of the Navi substructures is usable */
typedef uint8 TSA_INTERFACES_e_subStructureFilled;

#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_NONE                                          (0u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_ENTRANCE                                      (1u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_EXIT                                          (2u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_BRANCH                                        (3u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_RESTAREA                                      (4u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_RES5                                          (5u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_RES6                                          (6u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_FRW_INVALID                                       (7u)

/*! @brief location information */
typedef uint8 TSA_INTERFACES_e_naviFrwInfo;

#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_UNKNOWN                                      (0u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_FREEWAY                                      (1u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_IC                                           (2u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_JC                                           (3u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_RESTAREA                                     (4u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_COUNTRY                                      (5u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_ROUNDABOUT                                   (6u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_LINK_INVALID                                      (7u)

/*! @brief link class from current segment */
typedef uint8 TSA_INTERFACES_e_naviLinkClass;

#define tsa_interfaces_TSA_RTE_NAVI_HI17_TOLL_NONE                                         (0u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TOLL_NORMAL                                       (1u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TOLL_ELECTRONIC                                   (2u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TOLL_INVALID                                      (3u)

/*! @brief Toll station status */
typedef uint8 TSA_INTERFACES_e_naviTollStation;

#define tsa_interfaces_TSA_RTE_NAVI_HI17_TIME_SPD_NONE                                     (0u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TIME_SPD_VALID                                    (1u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TIME_SPD_UNLIMITED                                (2u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TIME_SPD_INVALID                                  (3u)

/*! @brief Status of time conditional speed limit */
typedef uint8 TSA_INTERFACES_e_naviTimeSpdStatus;

#define tsa_interfaces_TSA_RTE_NAVI_HI17_TUNNEL_NONE                                       (0u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TUNNEL_ACTIVE                                     (1u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TUNNEL_RES                                        (2u)
#define tsa_interfaces_TSA_RTE_NAVI_HI17_TUNNEL_INVALID                                    (3u)

/*! @brief Tunnel status */
typedef uint8 TSA_INTERFACES_e_naviTunnel;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_UNKNOWN                            (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_IMPLICIT                           (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_ON_SIGN                   (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_PROVISIONAL               (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_VARIABLE                  (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_RESERVED                           (5u)

/*! @brief Speed Limit Type from Navigation data */
typedef uint8 TA19NSPDTYP_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPL_SIGN_UNKNOWN                               (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPL_SIGN_NONE                                  (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPL_SIGN_TIME_PROVISION                        (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_RAIN                             (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_ICY                              (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_SPL_SIGN_RESERVED                              (5u)

/*! @brief Supplementary sign from Navigation data */
typedef uint8 TA19NSPLSGN_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_UNKNOWN                                        (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_FC1                                            (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_FC2                                            (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_FC3                                            (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_FC4                                            (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_FC5                                            (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_reserved                                       (6u)

/*! @brief functional road class */
typedef uint8 TA19FCRDCLS_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_OFFROAD                             (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NONE                                (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_1                           (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_2                           (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_HIGHWAY                             (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_THROUGHWAY                          (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_LOCAL                               (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FRONTAGE                            (7u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_VERY_LOW_SPEED                      (8u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PRIVATE                             (9u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_WALKWAY                             (10u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NON_TSA_RTE_NAVI_TA19_EUGABLE       (11u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FERRY                               (12u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CAR_TRAIN                           (13u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PUBLIC_VEHICLE_ONLY                 (14u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CARPOOL_LANE                        (15u)

/*! @brief Road class */
typedef uint8 TA19_RDCLS_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_UNKNOWN                             (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_NONE                                (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITHOUT_MEDIAN_STRIP      (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITH_MEDIAN_STRIP         (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_CONNECT_ROAD_BETWEEN_MAIN_ROADS     (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_INTERSECTION                        (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_LEFT_SIDE                      (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_RIGHT_SIDE                     (7u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_OF_MAIN_LINE          (8u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_TO_THE_SA_ETC         (9u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_ROTARY                              (10u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED1                           (11u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED2                           (12u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED3                           (13u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED4                           (14u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED5                           (15u)

/*! @brief Link Class */
typedef uint8 TA19_LINKCLS_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_UNKNOWN                         (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_NONE                            (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_TUNNEL                          (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_BRIDGE                          (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED1                       (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED2                       (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED3                       (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED4                       (7u)

/*! @brief Road Structure */
typedef uint8 TA19_RDSTR_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_BUILTUP_UNKNOWN                                (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_BUILTUP_OUTSIDE                                (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_BUILTUP_INSIDE                                 (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_BUILTUP_RESERVED                               (3u)

/*! @brief Built-up area */
typedef uint8 TA19_BUILTUP_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_UNKNOWN                          (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_NONE                             (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_LEFT                             (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RIGHT                            (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_STRAIGHT                         (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED1                        (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED2                        (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED3                        (7u)

/*! @brief No-entry link  */
typedef uint8 TA19_NENTLNK_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_MATCH_CONF_UNKNOWN                             (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_MATCH_CONF_OFFROAD                             (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_MATCH_CONF_NOT_IDENTIFIED                      (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_MATCH_CONF_IDENTIFIED                          (3u)

/*! @brief matching confidence */
typedef uint8 TA19_MTCHCONF_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROUTSTS_UNKNOWN                                (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROUTSTS_NO_ROUTING                             (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_EU_ROUTSTS_ROUTING                                (2u)

/*! @brief routing status */
typedef uint8 TA19_ROUTSTS_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_1                                 (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_2                                 (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_HIGHWAY                                    (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_THOROUGHFARE                               (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_LOCAL_ROAD                                 (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_ROAD_1                                     (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_ROAD_2                                     (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_PRIVATE_ROAD                               (7u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_1                                (8u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_2                                (9u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_FERRY_ROUTE                                (10u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_PARKING_ROAD                               (11u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_3                                (12u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_1                                 (13u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_2                                 (14u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_RDC_INVALID                                    (15u)

/*! @brief actual road class */
typedef uint8 TA19_RDC_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_TRAFFIC_CIRCLE                             (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_1                                    (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_2                                    (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_JUNCTION                                   (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_INTERSECTION                               (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_RAMP                                       (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_SIDE                                 (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_SAPA                                       (7u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_1                                 (8u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_2                                 (9u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_ROTARY                                     (10u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_CIRCLE                                     (11u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_NO_DEFINITION_AREA                         (12u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_1                                 (13u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_2                                 (14u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_LYT_INVALID                                    (15u)

/*! @brief actual link type */
typedef uint8 TA19_LYT_t;

#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_NONE                                    (0u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_LEFT                                    (1u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT                                   (2u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT_AND_LEFT                          (3u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_1                              (4u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_2                              (5u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_3                              (6u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_4                              (7u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_5                              (8u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_6                              (9u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_7                              (10u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_8                              (11u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_9                              (12u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_10                             (13u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_11                             (14u)
#define tsa_interfaces_TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_12                             (15u)

/*! @brief actual branch */
typedef uint8 TA19_BRANCH_t;

#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_NOT_AVAILABLE                                 (0u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_NAVTEQ                                        (1u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_TOMTOM                                        (2u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_TELEATLAS                                     (3u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_ZENRIN                                        (4u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_ADF                                           (5u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_NAVINFO                                       (6u)
#define tsa_interfaces_TSA_RTE_NAVI_PROVIDER_INVALID                                       (7u)

typedef uint8 TsaRteNaviProvider_t;

#define tsa_interfaces_opModeReset                                                         (0u)   /*!< Reset */
#define tsa_interfaces_opModePause                                                         (1u)   /*!< Pause */
#define tsa_interfaces_opModeNormal                                                        (2u)   /*!< Normal */

/*! @brief OpMode(TSA_INTERFACES) */
typedef uint8 TSA_INTERFACES_OpMode;

#define tsa_interfaces_opModeReset                                                         (0u)   /*!< Reset */
#define tsa_interfaces_opModePause                                                         (1u)   /*!< Pause */
#define tsa_interfaces_opModeNormal                                                        (2u)   /*!< Normal */

/*! @brief OpMode(TSA_INTERFACES) */
typedef uint8 TSA_INTERFACES_OpMode;


/*! @brief coding parameter input */
typedef struct
{
    AlgoInterfaceVersionNumber_t                         uiVersionNumber;                     /*!< Interface version number, increased when changed  */
    BASE_INTERFACES_SignalHeader_t                       sSigHeader;                          /*!< Signal header with common signal information  */
    boolean                                              enable;                              /*!< on/off switch,Accuracy: 1.0, Range:[0..1]  */
    TSA_INTERFACES_TsaCountryVariationVehicle            TsaCountryVariationVehicle;          /*!< market for which vehicle was produced,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_COUNTRY_VARIATION_UNKNOWN=0,TSA_RTE_COUNTRY_VARIATION_ECE=1,TSA_RTE_COUNTRY_VARIATION_GULF=2,TSA_RTE_COUNTRY_VARIATION_USA=3,TSA_RTE_COUNTRY_VARIATION_CANADA=4,TSA_RTE_COUNTRY_VARIATION_ROW=5,TSA_RTE_COUNTRY_VARIATION_JPCN=6,TSA_RTE_COUNTRY_VARIATION_ISRAEL=7,TSA_RTE_COUNTRY_VARIATION_CYPRUS=8,TSA_RTE_COUNTRY_VARIATION_CROATIA=9,TSA_RTE_COUNTRY_VARIATION_TURKEY=10,TSA_RTE_COUNTRY_VARIATION_BELARUS=11,TSA_RTE_COUNTRY_VARIATION_CHINA=12,TSA_RTE_COUNTRY_VARIATION_SAFRICA=13,TSA_RTE_COUNTRY_VARIATION_AUSTRALIA=14,TSA_RTE_COUNTRY_VARIATION_SKOREA=15  */
    TSA_INTERFACES_TsaNavigationInputIdentifier          TsaNavigationInputIdentifier;        /*!< Identifier, which indicated, what kind of Navigation Input Data TSA shall receive.,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAV_IDENTIFIER_NO=0,TSA_RTE_NAV_IDENTIFIER_ONLY_CCO=1,TSA_RTE_NAV_IDENTIFIER_MAP=2,TSA_RTE_NAV_IDENTIFIER_HI17=3,TSA_RTE_NAV_IDENTIFIER_TA19=4  */
    boolean                                              wwaEnable;                           /*!< wwa on/off switch,Accuracy: 1.0, Range:[0..1]  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndSpeedLimit;                      /*!< speed limit end sign expiration values  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndHighway;                         /*!< highway end sign expiration values  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndMotorway;                        /*!< motorway end sign expiration values  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndCity;                            /*!< city end sign expiration values  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndPlaystreet;                      /*!< playstreet end sign expiration values  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndGeneral;                         /*!< general end sign expiration values  */
    TSA_INTERFACES_TsaRteEndSignDisplayCondition_t       sEndNoPassing;                       /*!< no passing end expiration values  */
    uint16                                               uNoPassingExpDistanceHw;             /*!< no passing expiration distancefor highway  */
    uint16                                               uNoPassingExpDistanceNhw;            /*!< no passing expiration distancefor non highway  */
    uint16                                               uSignExpirationDistanceFactor;       /*!< Factor to extend range of expiration distances  */
    TSA_INTERFACES_TsaRteExpirationDistance_t            aSlExpTabHwMph[5];                   /*!< speed limit expiration table for highway and mph  */
    TSA_INTERFACES_TsaRteExpirationDistance_t            aSlExpTabHwKmh[5];                   /*!< speed limit expiration table for highway and kmh  */
    TSA_INTERFACES_TsaRteExpirationDistance_t            aSlExpTabNhwMph[5];                  /*!< speed limit expiration table for non highway and mph  */
    TSA_INTERFACES_TsaRteExpirationDistance_t            aSlExpTabNhwKmh[5];                  /*!< speed limit expiration table for non highway and kmh  */
} TSA_INTERFACES_CPAR_TSA_RTE_parameters_t;           /* @versionstr: TSA_RTE_CODING_PARAMS_INTFVER */

/*! @brief contains driver warning switches */
typedef struct
{
    uint8                                                uOverSpeedHysteresisThresholdStart;
    uint8                                                uOverSpeedHysteresisThresholdEnd;
} TsaRteWarnCfg_t;
/*! @brief contains the restraint flags for TSA functions / features */
typedef struct
{
    boolean                                              bRestraint_IcyState;                 /*!< restraint condition for icy state. When true, the icy state calculation shall be deactivated,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              bRestraint_RainState;                /*!< restraint condition for rain state. When true, the rain state calculation shall be deactivated,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              bRestraint_ExitInUse;                /*!< restraint condition for exit in use. When true, the exit in use calculation shall be deactivated,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              bRestraint_SUEInitFromTachoUnit;     /*!< restraint condition for SUE initialization. When true, the initialization for SUE from the Tachometer speed unit shall be deactivated,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              bRestraint_drivingDistanceUsage;     /*!< restraint condition for usage of driving distance. When true, the driving distance value calculated in TSA shall not be used. In most cases there is an alternative specified in the requirements,Accuracy: 1.0, Range:[0..1]  */
} TsaRteFuncRestraint_t;
/*! @brief custom input data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                         uiVersionNumber;                     /*!< Interface version number, increased when changed  */
    BASE_INTERFACES_SignalHeader_t                       sSigHeader;                          /*!< Signal header with common signal information  */
    boolean                                              bTsaDeactivateCCELearning;           /*!< Deactivating TSA Country Information Estimation. When true, this will deactivate country code estimation, speed unit estimation, Traffic style estimation and set these to default values,Accuracy: 1.0, Range:[0..1]  */
    TsaRteWarnCfg_t                                      sWarnCfg;                            /*!< contains driver warning switches  */
    TsaRteFuncRestraint_t                                FunctionRestraintConditions;         /*!< contains the restraint flags for TSA functions / features  */
} TSA_INTERFACES_TsaRteCustomInput_t;           /* @versionstr: TSA_RTE_CUSTOM_INPUT_INTFVER */

/*! @brief date */
typedef struct
{
    BASE_INTERFACES_AlgoSignalState_t                    signalState;                         /*!< signal state  */
    uint8                                                day;                                 /*!< day  */
    uint8                                                month;                               /*!< month  */
    uint16                                               year;                                /*!< year  */
} RteDate_t;
/*! @brief time of day */
typedef struct
{
    BASE_INTERFACES_AlgoSignalState_t                    signalState;                         /*!< signal state  */
    uint8                                                hour;                                /*!< hour  */
    uint8                                                minute;                              /*!< minute  */
    uint8                                                second;                              /*!< second, Unit: [s]  */
} RteTimeOfDay_t;
/*! @brief GPS position */
typedef struct
{
    BASE_INTERFACES_AlgoSignalState_t                    signalState;                         /*!< signal state  */
    float32                                              latit;                               /*!< GPS latitude position, [rad], Unit: [rad]  */
    float32                                              longit;                              /*!< GPS longitude position, [rad], Unit: [rad]  */
} RteGpsPosition_t;
/*! @brief Map Information */
typedef struct
{
    BASE_INTERFACES_AlgoSignalState_t                    signalState;                         /*!< signal state  */
    uint8                                                MapAgeInYears;                       /*!< Map Age In Years  */
    TSA_INTERFACES_MapProvider                           MapProvider;                         /*!< Map Provider,Accuracy: 1.0, Unit: [Enum],List:INPUT_GPS_MAP_PROVIDER_NAVTEQ=0,INPUT_GPS_MAP_PROVIDER_TELEATLAS=1,INPUT_GPS_MAP_PROVIDER_ZENRIN=2,INPUT_GPS_MAP_PROVIDER_ADF=3,INPUT_GPS_MAP_PROVIDER_NAVINFO=4,INPUT_GPS_MAP_PROVIDER_RESERVED=5,INPUT_GPS_MAP_PROVIDER_NOT_AVAILABLE=6,INPUT_GPS_MAP_PROVIDER_INVALID=7  */
    uint16                                               CountryCode;                         /*!< country code (ISO3166-1)  */
    uint8                                                RegionCode[8];                       /*!< region code (ISO3166-2)  */
} RteMapInformation_t;
/*! @brief GPS input data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                         uiVersionNumber;                     /*!< Interface version number, increased when changed  */
    BASE_INTERFACES_SignalHeader_t                       sSigHeader;                          /*!< Signal header with common signal information  */
    RteDate_t                                            date;                                /*!< date  */
    RteTimeOfDay_t                                       timeOfDay;                           /*!< time of day  */
    RteGpsPosition_t                                     gpsPosition;                         /*!< GPS position  */
    RteMapInformation_t                                  mapInfo;                             /*!< Map Information  */
} TSA_INTERFACES_RteInputGPS_t;           /* @versionstr: RTE_INPUT_GPS_INTFVER */

/*! @brief results from estimation */
typedef struct
{
    sint32                                               countryCode;                         /*!< TSA output country code (ISO3166)
(can be result from GPS, Navi or Estimation, most reliable Country code)  */
    sint32                                               estCountryCode;                      /*!< the estimated country code (ISO3166)  */
    uint8                                                uSpeedUnitConfidence;                /*!< confidence value for speed unit signal (spdUnt), Unit: [%]  */
    uint8                                                uTrafficStyleConfidence;             /*!< confidence value for traffic style signal (trafficStyle), Unit: [%]  */
    uint8                                                uCountryCodeConfidence;              /*!< confidence value for country code signal (countryCode), Unit: [%]  */
} TsaRteEstimationResults_t;
/*! @brief information about current road position */
typedef struct
{
    TsaRteCurrentMotorway_t                              currentMotorway;
    TsaRteCurrentUrbanArea_t                             currentUrbanArea;
    TsaRteUrbanAreaChange_t                              urbanAreaChange;
    float32                                              distToUrbanAreaChange;
} TsaRteRoadInfo_t;
/*! @brief information about condition flags and other values, which can be used to analyze Algo behavior */
typedef struct
{
    uint16                                               uCounterSignsRight;                  /*!< counter for signs passed by the ego vehicle (signs on the right side)  */
    uint16                                               uCounterSignsLeft;                   /*!< counter for signs passed by the ego vehicle (signs on the left side)  */
    boolean                                              bOvertakingDetectedFlag;             /*!< flag, which indicates, wether the ego vehicle is driving an overtaking maneuver or not,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              TA19_JP_EXPYFLG;                     /*!< flag, that indicates expressway status for TA19 JP Navi Fusion,Accuracy: 1.0, Range:[0..1]  */
} TsaRteDebugInformation_t;
/*! @brief output results data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                         uiVersionNumber;                     /*!< Interface version number, increased when changed  */
    BASE_INTERFACES_SignalHeader_t                       sSigHeader;                          /*!< Signal header with common signal information  */
    uint32                                               rteWrpVersion;                       /*!< RTE wrapper version number  */
    TSA_INTERFACES_TsaRteOutputSlaResult_t               slaResults;                          /*!< SLA results  */
    TSA_INTERFACES_TsaRteOutputNpaResult_t               npaResults;                          /*!< NPA results  */
    TSA_INTERFACES_TsaRteOutputRwfResult_t               rwfResults;                          /*!< RWF results  */
    TSA_INTERFACES_TsaRteOutputWwaResult_t               wwaResults;                          /*!< WWA results  */
    TSA_INTERFACES_TsaRteOutputGwwResult_t               gwaResults;                          /*!< GWA results  */
    TsaRteEstimationResults_t                            countryResults;                      /*!< results from estimation  */
    TsaRteRoadInfo_t                                     roadInfo;                            /*!< information about current road position  */
    TsaRteDebugInformation_t                             debugInformation;                    /*!< information about condition flags and other values, which can be used to analyze Algo behavior  */
} TSA_INTERFACES_TsaRteOutputResults_t;           /* @versionstr: TSA_RTE_OUTPUT_RESULTS_INTFVER */

/*! @brief memory to save SLA relevant data for initialization phase */
typedef struct
{
    TSA_INTERFACES_TsaRteSignInfo_t                      slaSigns[2];                         /*!< signs which were active just before Igg Off  */
} TSA_INTERFACES_SlaNvmState;
/*! @brief memory to save NPA relevant data for initialization phase */
typedef struct
{
    TSA_INTERFACES_TsaRteSignInfo_t                      npaSign;                             /*!< last npa related sign just before Igg Off  */
} TSA_INTERFACES_NpaNvmState;
/*! @brief memory to save WWA relevant data for initialization phase */
typedef struct
{
    uint8                                                wwaReservedBytes[16];                /*!< currently it is not 100% clear, what to save, so reserve some bytes  */
} TSA_INTERFACES_WwaNvmState;
/*! @brief memory to save GWW relevant data for initialization phase */
typedef struct
{
    uint8                                                gwwReservedBytes[16];                /*!< currently it is not 100% clear, what to save, so reserve some bytes  */
} TSA_INTERFACES_GwwNvmState;
/*! @brief data from Country code estimation */
typedef struct
{
    uint16                                               u_countryCode;                       /*!< Estimated country code. ISO 3166-1  */
    uint8                                                cceConfidence;                       /*!< confidence value from Country Code Estimation, Unit: [%], Range:[0..100]  */
} TSA_INTERFACES_countryCodeEstimation;
/*! @brief data from traffic style estimation */
typedef struct
{
    sint8                                                tseIndicator;                        /*!< indicator for left/right handed traffic, Range:[-20..20]  */
} TSA_INTERFACES_trafficStyleEstimation;
/*! @brief data from speed unit estimation */
typedef struct
{
    uint8                                                sueScoreKmh;
    uint8                                                sueScoreMph;
    uint8                                                sueConfidence;                       /*!< confidence value from Speed Unit Estimation, Unit: [%], Range:[0..100]  */
} TSA_INTERFACES_speedUnitEstimation;
/*! @brief consistent country information (country code, speed unit, traffic style) */
typedef struct
{
    uint16                                               uCountryCode;                        /*!< country code from output  */
} TSA_INTERFACES_consistentCountryTuple;
/*! @brief data from map / navigation */
typedef struct
{
    boolean                                              TA19_JP_EXPYFLG;                     /*!< flag, that indicates expressway status for TA19 JP Navi Fusion,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              offRoad;                             /*!< navigation status,Accuracy: 1.0, Range:[0..1]  */
    float32                                              offRoadChangeDist;                   /*!< distance since last change in off Road status, Range:[0..1000000000]  */
} TSA_INTERFACES_mapData;
typedef struct
{
    TSA_INTERFACES_countryCodeEstimation                 countryCodeEstimation;               /*!< data from Country code estimation  */
    TSA_INTERFACES_trafficStyleEstimation                trafficStyleEstimation;              /*!< data from traffic style estimation  */
    TSA_INTERFACES_speedUnitEstimation                   speedUnitEstimation;                 /*!< data from speed unit estimation  */
    TSA_INTERFACES_consistentCountryTuple                consistentCountryTuple;              /*!< consistent country information (country code, speed unit, traffic style)  */
    TSA_INTERFACES_mapData                               mapData;                             /*!< data from map / navigation  */
} TSA_INTERFACES_TsaPreNvmState;
/*! @brief persitent state data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                         uiVersionNumber;                     /*!< Interface version number, increased when changed  */
    BASE_INTERFACES_SignalHeader_t                       sSigHeader;                          /*!< Signal header with common signal information  */
    TSA_INTERFACES_SlaNvmState                           SlaNvmState;                         /*!< memory to save SLA relevant data for initialization phase  */
    TSA_INTERFACES_NpaNvmState                           NpaNvmState;                         /*!< memory to save NPA relevant data for initialization phase  */
    TSA_INTERFACES_WwaNvmState                           WwaNvmState;                         /*!< memory to save WWA relevant data for initialization phase  */
    TSA_INTERFACES_GwwNvmState                           GwwNvmState;                         /*!< memory to save GWW relevant data for initialization phase  */
    TSA_INTERFACES_TsaPreNvmState                        TsaPreNvmState;
    uint8                                                tsaNvmReservedBytes[50];             /*!< bytes for currently not used data  */
} TSA_INTERFACES_NvmTsaRteState_t;           /* @versionstr: TSA_RTE_NVM_STATE_INTFVER */

/*! @brief SLA result */
typedef struct
{
    TSA_INTERFACES_TsaRteSlaSpdLmt_t                     spdLmt[3];                           /*!< speed limit  */
} TSA_INTERFACES_TsaRteOutputSlaResult_t;

/*! @brief speed limit */
typedef struct
{
    TSA_INTERFACES_signType                              signType;                            /*!< type of sign,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_SLA_OUTPUT_SIGN_NO=0,TSA_RTE_SLA_OUTPUT_SIGN_SL=1,TSA_RTE_SLA_OUTPUT_SIGN_SLE=2,TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_START=3,TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_END=4,TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_START=5,TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_END=6,TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_START=7,TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_END=8,TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_START=9,TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_END=10  */
    uint8                                                spdLmtValue;                         /*!< speed limit value, Range:[0..200]  */
    TsaRteSlaSupSgnVal_t                                 supplSignValidityState;              /*!< validity of supplementary signs,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_SLA_SUPPLVALSTAT_UNKNOWN=0,TSA_RTE_SLA_SUPPLVALSTAT_INVALID=1,TSA_RTE_SLA_SUPPLVALSTAT_VALID=2,TSA_RTE_SLA_SUPPLVALSTAT_EXTRAPOL=3  */
    uint8                                                uConfidence;                         /*!< confidence level for speed limit signs (e.g. graying), Unit: [%], Range:[0..100]  */
    TsaRteTrafficSignDebugInformation_t                  sTrafficSignDebugInfo;               /*!< debug information, which are related to traffic signs  */
} TSA_INTERFACES_TsaRteSlaSpdLmt_t;

/*! @brief NPA result */
typedef struct
{
    TsaRteNpaStatus_t                                    noPassingStatus;                     /*!< current no-passing information,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NPA_PASSING_STATE_IDLE=0,TSA_RTE_NPA_PASSING_STATE_ALLOWED=1,TSA_RTE_NPA_PASSING_STATE_CANCEL=2,TSA_RTE_NPA_PASSING_STATE_FORBIDDEN=3  */
    TsaRteNpaSupplSignValState_t                         noPassingSupplSignVal;               /*!< current suppl sign validity,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NPA_SUPPLVALSTAT_UNKNOWN=0,TSA_RTE_NPA_SUPPLVALSTAT_INVALID=1,TSA_RTE_NPA_SUPPLVALSTAT_VALID=2,TSA_RTE_NPA_SUPPLVALSTAT_EXTRAPOL=3  */
    TsaRteTrafficSignDebugInformation_t                  sTrafficSignDebugInfo;               /*!< debug information, which are related to traffic signs  */
} TSA_INTERFACES_TsaRteOutputNpaResult_t;

/*! @brief RWF result */
typedef struct
{
    TsaRteRwfStatus_t                                    roadWorksStatus;                     /*!< current road works information,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_RWF_STATUS_UNKNOWN=0,TSA_RTE_RWF_STATUS_NO=1,TSA_RTE_RWF_STATUS_YES=2  */
    TsaRteRwfIndicators_t                                roadWorksIndicators;                 /*!< indicators for recognized road works,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_RWF_INDICATOR_SPD_LMT_CAM_VS_MAP=1,TSA_RTE_RWF_INDICATOR_SPD_LMT_FUNNEL=2,TSA_RTE_RWF_INDICATOR_SIGN_REPET_RATE=4,TSA_RTE_RWF_INDICATOR_SIGN_BACK_COLOR=8,TSA_RTE_RWF_INDICATOR_LANE_MARK_COLOR=16,TSA_RTE_RWF_INDICATOR_SIGN_INVALIDATED=32,TSA_RTE_RWF_INDICATOR_LANE_WIDTH=64,TSA_RTE_RWF_INDICATOR_RW_SIGN=128  */
    sint32                                               roadWorkSpeedValue;                  /*!< value that contains the last speed limit in RW  */
    float32                                              roadWorkReActDist;                   /*!< distance timer to reactivate RW  */
    boolean                                              roadWorkEndFlag;                     /*!< flag that gets set in case the RW state changes to no RW,Accuracy: 1.0, Range:[0..1]  */
} TSA_INTERFACES_TsaRteOutputRwfResult_t;

/*! @brief WWA result */
typedef struct
{
    TSARteWwaStatus_t                                    wrongWayStatus;                      /*!< current wrong way status,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_WWA_WRONG_WAY_IDLE=0,TSA_RTE_WWA_NOT_DRIVING_WRONG_WAY=1,TSA_RTE_WWA_DRIVING_WRONG_WAY=2  */
    TSARteWwaStatus_t                                    wrongWayLastStatus;                  /*!< last wrong way status before change  */
    float32                                              wrongWayChangeDist;                  /*!< distance when status has changed  */
    TsaRteTrafficSignDebugInformation_t                  sTrafficSignDebugInfo;               /*!< debug information, which are related to traffic signs  */
    boolean                                              bNoEntryDetected;                    /*!< flag, which indicates if a no entry sign is detected,Accuracy: 1.0, Range:[0..1]  */
} TSA_INTERFACES_TsaRteOutputWwaResult_t;

/*! @brief GWW (Give way warner) result */
typedef struct
{
    float32                                              distance;                            /*!< distance to event, Unit: [m], Range:[0..100]  */
    float32                                              timeToCollision;                     /*!< time to event, Unit: [s], Range:[0..1000]  */
    TSA_INTERFACES_eventType                             eventType;                           /*!< type of Give Way event,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_GWW_IDLE=0,TSA_RTE_GWW_STOP_SIGN=1,TSA_RTE_GWW_GW_SIGN=2,TSA_RTE_GWW_TRAFFIC_LIGHT=3,TSA_RTE_GWW_RES1=4,TSA_RTE_GWW_RES2=5,TSA_RTE_GWW_RES3=6  */
    TsaRteTrafficSignDebugInformation_t                  sTrafficSignDebugInfo;               /*!< debug information, which are related to traffic signs  */
} TSA_INTERFACES_TsaRteOutputGwwResult_t;

/*! @brief struct for debug information, which are related to traffic signs */
typedef struct
{
    float32                                              fSignHeight;                         /*!< height of the traffic sign above ground, Unit: [m]  */
    float32                                              fSignLateralOffset;                  /*!< lateral offset of the traffic sign from the vehicle (left > 0), Unit: [m]  */
    float32                                              fSignDistanceClassified;             /*!< the (longitudinal) distance from the sign to the vehicle at the moment, where it was classified, Unit: [m]  */
    float32                                              fSignPassedDistance;                 /*!< distance traveled, since ego vehicle has passed the sign, Unit: [m]  */
    uint8                                                uSignRepostCounter;                  /*!< a counter which will be increased every time, the same sign is seen again. It will restarted (0) whenever a new / different sign is detected  */
} TsaRteTrafficSignDebugInformation_t;

/*! @brief definition of tsa Signs (Main sign, suppl sign, passed distance,) */
typedef struct
{
    float32                                              passedDist;                          /*!< distance, since sign is passed, Unit: [m], Range:[0..1000000000]  */
} TSA_INTERFACES_TsaRteSignInfo_t;

/*! @brief struct to handle expiration distances/times for different sign types */
typedef struct
{
    uint8                                                uDisplayTime;                        /*!< expiration time, Unit: [s]  */
    uint8                                                uDisplayDistance;                    /*!< expiration distance, Unit: [m]  */
} TSA_INTERFACES_TsaRteEndSignDisplayCondition_t;

typedef struct
{
    uint8                                                uMaxGroupSpeed;                      /*!< maximum speed limit for this group  */
    uint8                                                uExpirationDistance;                 /*!< expiration distance  */
} TSA_INTERFACES_TsaRteExpirationDistance_t;

/*! @brief custom Navigation input data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                         uiVersionNumber;                     /*!< Interface version number, increased when changed  */
    BASE_INTERFACES_SignalHeader_t                       sSigHeader;                          /*!< Signal header with common signal information  */
    uint16                                               u_countryCode;                       /*!< Country code defined as ISO 3166-1.
0 - UNKNOWN
0x3FF - INVALID  */
    TSA_INTERFACES_e_subStructureFilled                  e_subStructureFilled;                /*!< a flag, which indicates, which of the Navi substructures is usable,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_NONE=0,TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_HI17=1,TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_EU=2,TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_JP=3  */
    TsaRteInputNaviHI17_t                                InputNaviHI17;                       /*!< Navigation Input from MFC430HI17  */
    TsaRteInputNaviTA19EU_t                              InputNaviTA19EU;                     /*!< Navigation Input from MFC431TA19 EU variant  */
    TsaRteInputNaviTA19JP_t                              InputNaviTA19JP;                     /*!< Navigation Input from MFC431TA19 JP variant  */
} TSA_INTERFACES_TsaRteInputNavigation_t;           /* @versionstr: TSA_RTE_INPUT_NAVIGATION_INTFVER */

/*! @brief custom Navigation input for MFC430HI17 */
typedef struct
{
    boolean                                              b_naviFusionOK;                      /*!< True, if Navi data ok for Fusion,Accuracy: 1.0, Range:[0..1]  */
    uint8                                                u_naviSpeedLimit;                    /*!< speed limit indicated from Navigation system
0xFE: Unlimited
0xFF: Invalid  */
    TSA_INTERFACES_e_naviFrwInfo                         e_naviFrwInfo;                       /*!< location information,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_HI17_FRW_NONE=0,TSA_RTE_NAVI_HI17_FRW_ENTRANCE=1,TSA_RTE_NAVI_HI17_FRW_EXIT=2,TSA_RTE_NAVI_HI17_FRW_BRANCH=3,TSA_RTE_NAVI_HI17_FRW_RESTAREA=4,TSA_RTE_NAVI_HI17_FRW_RES5=5,TSA_RTE_NAVI_HI17_FRW_RES6=6,TSA_RTE_NAVI_HI17_FRW_INVALID=7  */
    TSA_INTERFACES_e_naviLinkClass                       e_naviLinkClass;                     /*!< link class from current segment,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_HI17_LINK_UNKNOWN=0,TSA_RTE_NAVI_HI17_LINK_FREEWAY=1,TSA_RTE_NAVI_HI17_LINK_IC=2,TSA_RTE_NAVI_HI17_LINK_JC=3,TSA_RTE_NAVI_HI17_LINK_RESTAREA=4,TSA_RTE_NAVI_HI17_LINK_COUNTRY=5,TSA_RTE_NAVI_HI17_LINK_ROUNDABOUT=6,TSA_RTE_NAVI_HI17_LINK_INVALID=7  */
    TSA_INTERFACES_e_naviTollStation                     e_naviTollStation;                   /*!< Toll station status,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_HI17_TOLL_NONE=0,TSA_RTE_NAVI_HI17_TOLL_NORMAL=1,TSA_RTE_NAVI_HI17_TOLL_ELECTRONIC=2,TSA_RTE_NAVI_HI17_TOLL_INVALID=3  */
    TSA_INTERFACES_e_naviTimeSpdStatus                   e_naviTimeSpdStatus;                 /*!< Status of time conditional speed limit,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_HI17_TIME_SPD_NONE=0,TSA_RTE_NAVI_HI17_TIME_SPD_VALID=1,TSA_RTE_NAVI_HI17_TIME_SPD_UNLIMITED=2,TSA_RTE_NAVI_HI17_TIME_SPD_INVALID=3  */
    uint8                                                u_naviTimeSpdVal;                    /*!< Value of time conditional speed limit  */
    TSA_INTERFACES_e_naviTunnel                          e_naviTunnel;                        /*!< Tunnel status,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_HI17_TUNNEL_NONE=0,TSA_RTE_NAVI_HI17_TUNNEL_ACTIVE=1,TSA_RTE_NAVI_HI17_TUNNEL_RES=2,TSA_RTE_NAVI_HI17_TUNNEL_INVALID=3  */
} TsaRteInputNaviHI17_t;

/*! @brief structure for Toyota Navi speed limit compound (EU Navi) */
typedef struct
{
    uint8                                                value;                               /*!< Value of the speed limit  */
    TA19NSPDTYP_t                                        type;                                /*!< Speed Limit Type from Navigation data,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_IMPLICIT=1,TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_ON_SIGN=2,TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_PROVISIONAL=3,TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_VARIABLE=4,TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_RESERVED=5  */
    TA19NSPLSGN_t                                        supplSign;                           /*!< Supplementary sign from Navigation data,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_SPL_SIGN_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_SPL_SIGN_NONE=1,TSA_RTE_NAVI_TA19_EU_SPL_SIGN_TIME_PROVISION=2,TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_RAIN=3,TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_ICY=4,TSA_RTE_NAVI_TA19_EU_SPL_SIGN_RESERVED=5  */
} naviSpeedLimitTA19EU_t;
/*! @brief custom Navigation input for MFC431TA19 EU Region */
typedef struct
{
    naviSpeedLimitTA19EU_t                               naviSpeedLimitTA19EU[6];             /*!< structure for Toyota Navi speed limit compound (EU Navi)  */
    boolean                                              TSR_Navifusion_ON_Flag_EU;           /*!< flag which indicates, wether EU Navi fusion shall be active or not,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              TSR_Restraint_Condition_Of_AVN;      /*!< flag which shall be set, when AVN (Navi) usage is restraint,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              TSR_Navifusion_Map_valid;            /*!< flag which indicates, wether map information is usable or not,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              TSR_Navifusion_Speed_valid;          /*!< flag which indicates, whether speed limit from map is valid or not,Accuracy: 1.0, Range:[0..1]  */
    TA19FCRDCLS_t                                        frc;                                 /*!< functional road class,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_FC1=1,TSA_RTE_NAVI_TA19_EU_FC2=2,TSA_RTE_NAVI_TA19_EU_FC3=3,TSA_RTE_NAVI_TA19_EU_FC4=4,TSA_RTE_NAVI_TA19_EU_FC5=5,TSA_RTE_NAVI_TA19_EU_reserved=6  */
    TA19_RDCLS_t                                         roadClass[5];                        /*!< Road class,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_OFFROAD=0,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NONE=1,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_1=2,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_2=3,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_HIGHWAY=4,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_THROUGHWAY=5,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_LOCAL=6,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FRONTAGE=7,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_VERY_LOW_SPEED=8,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PRIVATE=9,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_WALKWAY=10,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NON_TSA_RTE_NAVI_TA19_EUGABLE=11,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FERRY=12,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CAR_TRAIN=13,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PUBLIC_VEHICLE_ONLY=14,TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CARPOOL_LANE=15  */
    TA19_LINKCLS_t                                       linkClass[5];                        /*!< Link Class,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_LINK_CLASS_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_NONE=1,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITHOUT_MEDIAN_STRIP=2,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITH_MEDIAN_STRIP=3,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_CONNECT_ROAD_BETWEEN_MAIN_ROADS=4,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_INTERSECTION=5,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_LEFT_SIDE=6,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_RIGHT_SIDE=7,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_OF_MAIN_LINE=8,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_TO_THE_SA_ETC=9,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_ROTARY=10,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED1=11,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED2=12,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED3=13,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED4=14,TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED5=15  */
    TA19_RDSTR_t                                         roadStructure[5];                    /*!< Road Structure,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_NONE=1,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_TUNNEL=2,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_BRIDGE=3,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED1=4,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED2=5,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED3=6,TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED4=7  */
    TA19_BUILTUP_t                                       builtupFlag[5];                      /*!< Built-up area,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_BUILTUP_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_BUILTUP_OUTSIDE=1,TSA_RTE_NAVI_TA19_EU_BUILTUP_INSIDE=2,TSA_RTE_NAVI_TA19_EU_BUILTUP_RESERVED=3  */
    TA19_NENTLNK_t                                       noEntryLink[5];                      /*!< No-entry link ,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_NONE=1,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_LEFT=2,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RIGHT=3,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_STRAIGHT=4,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED1=5,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED2=6,TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED3=7  */
    uint16                                               remainDist;                          /*!< remaining distance  */
    TA19_MTCHCONF_t                                      matchingConf;                        /*!< matching confidence,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_MATCH_CONF_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_MATCH_CONF_OFFROAD=1,TSA_RTE_NAVI_TA19_EU_MATCH_CONF_NOT_IDENTIFIED=2,TSA_RTE_NAVI_TA19_EU_MATCH_CONF_IDENTIFIED=3  */
    TA19_ROUTSTS_t                                       routSts;                             /*!< routing status,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_EU_ROUTSTS_UNKNOWN=0,TSA_RTE_NAVI_TA19_EU_ROUTSTS_NO_ROUTING=1,TSA_RTE_NAVI_TA19_EU_ROUTSTS_ROUTING=2  */
    uint8                                                mapAge;                              /*!< map Version (Year) in ADASIS v2 protocol (Year - 2000)  */
    uint8                                                numOfLanes;                          /*!< number of lanes in sum of driving and opposite direction  */
} TsaRteInputNaviTA19EU_t;

/*! @brief custom Navigation input for MFC431TA19 JP Region */
typedef struct
{
    boolean                                              TSR_Navifusion_ON_Flag_JP;           /*!< flag which indicates, wether JP Navi fusion shall be active or not,Accuracy: 1.0, Range:[0..1]  */
    TA19_RDC_t                                           eRoadClass;                          /*!< actual road class,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_1=0,TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_2=1,TSA_RTE_NAVI_TA19_JP_RDC_HIGHWAY=2,TSA_RTE_NAVI_TA19_JP_RDC_THOROUGHFARE=3,TSA_RTE_NAVI_TA19_JP_RDC_LOCAL_ROAD=4,TSA_RTE_NAVI_TA19_JP_RDC_ROAD_1=5,TSA_RTE_NAVI_TA19_JP_RDC_ROAD_2=6,TSA_RTE_NAVI_TA19_JP_RDC_PRIVATE_ROAD=7,TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_1=8,TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_2=9,TSA_RTE_NAVI_TA19_JP_RDC_FERRY_ROUTE=10,TSA_RTE_NAVI_TA19_JP_RDC_PARKING_ROAD=11,TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_3=12,TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_1=13,TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_2=14,TSA_RTE_NAVI_TA19_JP_RDC_INVALID=15  */
    TA19_LYT_t                                           eLinkType;                           /*!< actual link type,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_JP_LYT_TRAFFIC_CIRCLE=0,TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_1=1,TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_2=2,TSA_RTE_NAVI_TA19_JP_LYT_JUNCTION=3,TSA_RTE_NAVI_TA19_JP_LYT_INTERSECTION=4,TSA_RTE_NAVI_TA19_JP_LYT_RAMP=5,TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_SIDE=6,TSA_RTE_NAVI_TA19_JP_LYT_SAPA=7,TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_1=8,TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_2=9,TSA_RTE_NAVI_TA19_JP_LYT_ROTARY=10,TSA_RTE_NAVI_TA19_JP_LYT_CIRCLE=11,TSA_RTE_NAVI_TA19_JP_LYT_NO_DEFINITION_AREA=12,TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_1=13,TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_2=14,TSA_RTE_NAVI_TA19_JP_LYT_INVALID=15  */
    boolean                                              bDriveWay;                           /*!< drive way on or off,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              bMotorwayMap;                        /*!< motorway map on or off,Accuracy: 1.0, Range:[0..1]  */
    boolean                                              bTunnel;                             /*!< in a tunnel or not,Accuracy: 1.0, Range:[0..1]  */
    TA19_BRANCH_t                                        eBranch;                             /*!< actual branch,Accuracy: 1.0, Unit: [Enum],List:TSA_RTE_NAVI_TA19_JP_BRANCH_NONE=0,TSA_RTE_NAVI_TA19_JP_BRANCH_LEFT=1,TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT=2,TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT_AND_LEFT=3,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_1=4,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_2=5,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_3=6,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_4=7,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_5=8,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_6=9,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_7=10,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_8=11,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_9=12,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_10=13,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_11=14,TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_12=15  */
    uint8                                                uConfidence;                         /*!< confidence Level  */
} TsaRteInputNaviTA19JP_t;


#ifdef __cplusplus
}
#endif

#endif /* #if (GA_CFG_TSA_INTERFACES == 1) */

/*! @} end defgroup */

#endif /* #ifndef GA_TSA_INTERFACES_EXT_H_INCLUDED */
