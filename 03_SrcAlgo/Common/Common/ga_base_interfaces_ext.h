#ifndef _GA_GLOBAL_H_INCLUDED
#error include setup error: forbidden inclusion of GA local-scope header file; only component *_main.h + *_wrapper.h, and ga_global.h (or ga_global_emlib.h on emlib dependancy) are allowed
#endif

#ifndef GA_BASE_INTERFACES_EXT_H_INCLUDED
#define GA_BASE_INTERFACES_EXT_H_INCLUDED

/*! @ingroup base_interfaces
@{
@file
External header of the BASE_INTERFACES component.    */


#if (GA_CFG_BASE_INTERFACES == 1)

#ifdef __cplusplus
extern "C" {
#endif

/* --- virtual addresses --------------------------------------------------- */
#define BASE_INTERFACES_VA_CONTROL_DATA       ()   /*!< virtual address of controlData (uL) */

/* ---- constants ---------------------------------------------------------- */
#define ALGO_VERSION_INFO_LENGTH        (50)
#define VDY_SWA_RAT_NO_ANGL             (2)
#define VDY_SWA_RAT_NO_VELO             (2)
#define TRACE_NO_OF_TRACES              (10)
#define ALGO_FUSI_DEBOUNCE_TIME         (185000)
#define ALGO_FUSI_DEBOUNCE_CYCLES       (3)
/*! @brief RTE bitfield type is enabled */
#define RTE_BITFIELD_TYPE               (1)

/* ---- type InterfaceVersion ---------------------------------------------- */
#define BASE_INTERFACES_CONTROL_DATA_INTVER  (1)  /*!< version of BASE_INTERFACES_ControlData */
#define BASE_CTRL_DATA_INTFVER               (2)  /*!< version of BASE_INTERFACES_BaseCtrlData */
#define COMP_STATE_INTFVER                   (3)  /*!< version of BASE_INTERFACES_AlgoCompState */

/* ---- type definitions --------------------------------------------------- */
#define base_interfaces_AL_ERR_STATE_UNKNOWN                     (0u)
#define base_interfaces_AL_ERR_STATE_ACTIVE                      (1u)
#define base_interfaces_AL_ERR_STATE_INACTIVE                    (2u)

/*! @brief Algo error state enumeration */
typedef uint8 BASE_INTERFACES_AlgoErrorState_t;

#define base_interfaces_AL_SIG_STATE_INIT                        (0u)
#define base_interfaces_AL_SIG_STATE_OK                          (1u)
#define base_interfaces_AL_SIG_STATE_INVALID                     (2u)

/*! @brief Algo signal state enumeration */
typedef uint8 BASE_INTERFACES_AlgoSignalState_t;

#define base_interfaces_SIGNAL_INVALID                           (0u)
#define base_interfaces_SIGNAL_VALID                             (1u)

/*! @brief Signal status */
typedef uint8 BASE_INTERFACES_SigState_t;

#define base_interfaces_ALGO_QUAL_OK                             (0u)
#define base_interfaces_ALGO_QUAL_CRITICAL_INPUT_ERROR           (1u)
#define base_interfaces_ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR       (2u)
#define base_interfaces_ALGO_QUAL_BLOCKAGE                       (4u)
#define base_interfaces_ALGO_QUAL_PARTIAL_BLOCKAGE               (8u)
#define base_interfaces_ALGO_QUAL_CALIBRATION_ERROR_TOO_HIGH     (16u)
#define base_interfaces_ALGO_QUAL_GENERAL_FUNCTION_ERROR         (32u)
#define base_interfaces_ALGO_QUAL_NO_VISIBILITY                  (64u)
#define base_interfaces_ALGO_QUAL_LIMITED_VISIBILITY             (128u)
#define base_interfaces_ALGO_QUAL_CALIBRATION_RUNNING            (256u)
#define base_interfaces_ALGO_QUAL_MAX                            (4294967295u)

/*! @brief Generic algo qualifiers should be used on the algo component output. */
typedef uint32 BASE_INTERFACES_GenAlgoQualifiers_t;

#define base_interfaces_BASE_RETURN_OK                           (0u)
#define base_interfaces_BASE_RETURN_ERROR                        (4294967295u)

/*! @brief Return codes for algo exec function. */
typedef uint32 BASE_INTERFACES_BaseReturnCode_t;

#define base_interfaces_FUSI_ERROR_DIR_SNA                       (0u)
#define base_interfaces_FUSI_ERROR_DIR_INPUT                     (1u)
#define base_interfaces_FUSI_ERROR_DIR_OUTPUT                    (2u)

/*! @brief First byte of extended data for FUSI DEM event. Specifying if the DEM was due to failed input or output check. */
typedef uint8 BASE_INTERFACES_FusiErrorExtDirection_t;

#define base_interfaces_FUSI_ERROR_TYPE_SNA                      (0u)
#define base_interfaces_FUSI_ERROR_TYPE_NULLPOINTER              (1u)
#define base_interfaces_FUSI_ERROR_TYPE_VERSIONNUMBER            (2u)
#define base_interfaces_FUSI_ERROR_TYPE_SIGNALSTATE              (3u)
#define base_interfaces_FUSI_ERROR_TYPE_COUNTER                  (4u)
#define base_interfaces_FUSI_ERROR_TYPE_FINGERPRINT              (5u)
#define base_interfaces_FUSI_ERROR_TYPE_VERIFICATION             (6u)

/*! @brief Second byte of extended data for FUSI DEM event. Specifying what kind of check failed. */
typedef uint8 BASE_INTERFACES_FusiErrorExtType_t;

#define base_interfaces_Percentage_min                           (0u)
#define base_interfaces_Percentage_max                           (100u)

typedef uint8 BASE_INTERFACES_Percentage_s;

#define base_interfaces_RTE_False                                (0u)
#define base_interfaces_RTE_True                                 (1u)

typedef uint8 BASE_INTERFACES_True_False_s;

#define base_interfaces_BASE_OM_IDLE                             (0u)
#define base_interfaces_BASE_OM_RESET                            (1u)
#define base_interfaces_BASE_OM_MAX_RUNTIME                      (2u)
#define base_interfaces_BASE_OM_DEMO                             (3u)
#define base_interfaces_BASE_OM_RUN                              (4u)
#define base_interfaces_BASE_OM_RUN_ODD                          (5u)
#define base_interfaces_BASE_OM_RUN_EVEN                         (6u)
#define base_interfaces_BASE_OM_SYNC                             (7u)
#define base_interfaces_BASE_OM_MEAS_ONLY                        (8u)
#define base_interfaces_BASE_OM_INIT_LUT                         (9u)
#define base_interfaces_BASE_OM_AUTOCAL_COARSE                   (10u)
#define base_interfaces_BASE_OM_AUTOCAL_FINE                     (11u)
#define base_interfaces_BASE_OM_AUTO_CHOICE                      (12u)
#define base_interfaces_BASE_OM_EOL_UPDATE                       (13u)
#define base_interfaces_BASE_OM_SELF_EVAL                        (14u)
#define base_interfaces_BASE_OM_TEST                             (15u)
#define base_interfaces_BASE_OM_DISTANCE_TEST                    (16u)
#define base_interfaces_BASE_OM_ECM_RTE_TRANSMIT                 (17u)
#define base_interfaces_BASE_OM_ECM_RTE_DEV                      (18u)
#define base_interfaces_BASE_OM_ECM_RTE_EOL                      (19u)
#define base_interfaces_BASE_OM_FEX_RUN_INIT_FPGA                (20u)
#define base_interfaces_BASE_OM_FEX_RUN_STARTUP_TEST_FPGA        (21u)
#define base_interfaces_BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA         (22u)
#define base_interfaces_BASE_OM_FEX_RUN_SAC_DATA                 (23u)
#define base_interfaces_BASE_OM_FEX_RUN_PED_DATA                 (24u)
#define base_interfaces_BASE_OM_PED_RUN_HYPGEN                   (25u)
#define base_interfaces_BASE_OM_PED_RUN_IMAGE_TRACKING           (26u)
#define base_interfaces_BASE_OM_PED_RUN_CLUSTERING               (27u)
#define base_interfaces_BASE_OM_MEMO_SYNCVDY                     (28u)
#define base_interfaces_BASE_OM_VCL_ROIGEN                       (29u)
#define base_interfaces_BASE_OM_EM_PREDICT                       (30u)
#define base_interfaces_BASE_OM_EM_UPDATE_GEN                    (31u)
#define base_interfaces_BASE_OM_EM_UPDATE_PED                    (32u)
#define base_interfaces_BASE_OM_EM_UPDATE_VCL                    (33u)
#define base_interfaces_BASE_OM_EM_UPDATE_SPC                    (34u)
#define base_interfaces_BASE_OM_EM_MAINTENANCE                   (35u)
#define base_interfaces_BASE_OM_SIB_GEOMETRY                     (36u)
#define base_interfaces_BASE_OM_SIB_DYNAMIC                      (37u)
#define base_interfaces_BASE_OM_VODCA_PREPROCESS                 (38u)
#define base_interfaces_BASE_OM_VODCA_CLASSIFY                   (39u)
#define base_interfaces_BASE_OM_NVM_CALIB_RESET                  (40u)
#define base_interfaces_BASE_OM_NVM_RESET                        (41u)
#define base_interfaces_BASE_OM_VCL_TRACK                        (42u)
#define base_interfaces_BASE_OM_VCL_POSTPROC                     (43u)
#define base_interfaces_BASE_OM_HLA_SEG                          (44u)
#define base_interfaces_BASE_OM_EM_PROCESS_GSS                   (45u)
#define base_interfaces_BASE_OM_EM_PROCESS_OD                    (46u)
#define base_interfaces_BASE_OM_EM_PROCESS_ROAD                  (47u)
#define base_interfaces_BASE_OM_RUM_INITIAL_ROI_GEN              (48u)
#define base_interfaces_BASE_OM_RUM_TRACKING                     (49u)
#define base_interfaces_BASE_OM_RUM_POST_PROC                    (50u)
#define base_interfaces_BASE_OM_EM_PROCESS_FLOW                  (51u)
#define base_interfaces_BASE_OM_EM_PROCESS_LMD                   (52u)
#define base_interfaces_BASE_OM_ACAL_TRANSMIT                    (53u)
#define base_interfaces_BASE_OM_ACAL_CALIB                       (54u)
#define base_interfaces_BASE_OM_LD_TEXTURE_CLASSIFY              (55u)
#define base_interfaces_BASE_OM_MEMO_RUN_EGOMOTION               (56u)
#define base_interfaces_BASE_OM_MEMO_RUN_DEPTH                   (57u)
#define base_interfaces_BASE_OM_VODCA_PROCESS                    (58u)
#define base_interfaces_BASE_OM_VODCA_PROCESS_FINAL              (59u)
#define base_interfaces_BASE_OM_GEOS_PROCESS_FLOW                (60u)
#define base_interfaces_BASE_OM_GEOS_SEGMENTATION                (61u)
#define base_interfaces_BASE_OM_GEOS_PROCESS_EXTENDED_FLOW       (62u)
#define base_interfaces_BASE_OM_DAP01                            (1001u)
#define base_interfaces_BASE_OM_DAP02                            (1002u)
#define base_interfaces_BASE_OM_DAP03                            (1003u)
#define base_interfaces_BASE_OM_DAP04                            (1004u)
#define base_interfaces_BASE_OM_GP01                             (1010u)
#define base_interfaces_BASE_OM_GP02                             (1011u)
#define base_interfaces_BASE_OM_GP03                             (1012u)
#define base_interfaces_BASE_OM_GP04                             (1013u)
#define base_interfaces_BASE_OM_GP05                             (1014u)
#define base_interfaces_BASE_OM_GP06                             (1015u)
#define base_interfaces_BASE_OM_OD01                             (1021u)
#define base_interfaces_BASE_OM_OD02                             (1022u)
#define base_interfaces_BASE_OM_OD03                             (1023u)
#define base_interfaces_BASE_OM_OD04                             (1024u)
#define base_interfaces_BASE_OM_OD05                             (1025u)
#define base_interfaces_BASE_OM_OD06                             (1026u)
#define base_interfaces_BASE_OM_OD07                             (1027u)
#define base_interfaces_BASE_OM_PD01                             (1036u)
#define base_interfaces_BASE_OM_PD02                             (1037u)
#define base_interfaces_BASE_OM_PCC01                            (1044u)
#define base_interfaces_BASE_OM_PCC02                            (1045u)
#define base_interfaces_BASE_OM_RMHT01                           (1046u)
#define base_interfaces_BASE_OM_RMHT02                           (1047u)
#define base_interfaces_BASE_OM_RMHT03                           (1048u)
#define base_interfaces_BASE_OM_RMHT04                           (1049u)
#define base_interfaces_BASE_OM_RMHT05                           (1050u)
#define base_interfaces_BASE_OM_RDT01                            (1051u)
#define base_interfaces_BASE_OM_RDT02                            (1052u)
#define base_interfaces_BASE_OM_RDT03                            (1053u)
#define base_interfaces_BASE_OM_RDT04                            (1054u)
#define base_interfaces_BASE_OM_RDT05                            (1055u)
#define base_interfaces_BASE_OM_RDT06                            (1056u)
#define base_interfaces_BASE_OM_RADI                             (1057u)
#define base_interfaces_BASE_OM_RSP01                            (1058u)
#define base_interfaces_BASE_OM_SRP1_01                          (1059u)
#define base_interfaces_BASE_OM_SRP2_01                          (1060u)
#define base_interfaces_BASE_OM_SRP2_02                          (1061u)
#define base_interfaces_BASE_OM_SRP2_03                          (1062u)
#define base_interfaces_BASE_OM_SRP2_04                          (1063u)
#define base_interfaces_BASE_OM_RMP1_01                          (1064u)
#define base_interfaces_BASE_OM_RMP2_01                          (1065u)
#define base_interfaces_BASE_OM_RMP2_02                          (1066u)
#define base_interfaces_BASE_OM_SEP1_01                          (1067u)
#define base_interfaces_BASE_OM_SEP2_01                          (1068u)
#define base_interfaces_BASE_OM_SEP2_02                          (1069u)
#define base_interfaces_BASE_OM_SEP2_03                          (1070u)
#define base_interfaces_BASE_OM_OOC01                            (1071u)
#define base_interfaces_BASE_OM_RIC01                            (1072u)
#define base_interfaces_BASE_OM_RIC02                            (1073u)
#define base_interfaces_BASE_OM_CC01                             (1074u)
#define base_interfaces_BASE_OM_ACDC01                           (1075u)
#define base_interfaces_BASE_OM_LOCTR01                          (1076u)
#define base_interfaces_BASE_OM_MEDIC01                          (1077u)
#define base_interfaces_BASE_OM_LOPLN01                          (1078u)
#define base_interfaces_BASE_OM_RFCOM_Init                       (1079u)
#define base_interfaces_BASE_OM_RFCOM_ConfigFrame                (1080u)
#define base_interfaces_BASE_OM_RFCOM_TriggerFrame               (1081u)
#define base_interfaces_BASE_OM_RHC_PreSp1FRS                    (1082u)
#define base_interfaces_BASE_OM_RHC_PostSp1FRS                   (1083u)
#define base_interfaces_BASE_OM_RHC_PreSp1NRS                    (1084u)
#define base_interfaces_BASE_OM_RHC_PostSp1NRS                   (1085u)
#define base_interfaces_BASE_OM_RHC_PreLoopbackTest              (1086u)
#define base_interfaces_BASE_OM_RHC_PostLoopbackTest             (1087u)
#define base_interfaces_BASE_OM_RPM1_01                          (1088u)
#define base_interfaces_BASE_OM_RPM2_01                          (1089u)
#define base_interfaces_BASE_OM_RSP_INIT_CALC_AB_FRS             (1090u)
#define base_interfaces_BASE_OM_RSP_INIT_CALC_AB_NRS             (1091u)
#define base_interfaces_BASE_OM_RSP02                            (1092u)
#define base_interfaces_BASE_OM_ALN                              (1093u)
#define base_interfaces_BASE_OM_ALN_EOL                          (1094u)
#define base_interfaces_BASE_OM_ALN_SERVICE                      (1095u)
#define base_interfaces_BASE_OM_ALN_AUTOMATIC                    (1096u)
#define base_interfaces_BASE_OM_MOS01                            (1097u)
#define base_interfaces_BASE_OM_RPP01                            (1098u)
#define base_interfaces_BASE_OM_PCA_NORMAL                       (2000u)
#define base_interfaces_BASE_OM_PCA_NUC                          (2001u)
#define base_interfaces_BASE_OM_LIQOR_PIXEL_LABEL                (2016u)
#define base_interfaces_BASE_OM_LIQOR_OBJ_LABEL                  (2017u)
#define base_interfaces_BASE_OM_VDY                              (2018u)
#define base_interfaces_BASE_OM_RC1_01                           (2019u)
#define base_interfaces_BASE_OM_RC1_02                           (2020u)
#define base_interfaces_BASE_OM_RC2_01                           (2021u)
#define base_interfaces_BASE_OM_INVALID                          (65535u)

/*! @brief Required operation mode */
typedef uint16 BaseOpMode_t;

#define base_interfaces_BASE_SM_IDLE                             (0u)
#define base_interfaces_BASE_SM_RESET                            (1u)
#define base_interfaces_BASE_SM_DEMO                             (2u)
#define base_interfaces_BASE_SM_RUN                              (3u)
#define base_interfaces_BASE_SM_EOL                              (4u)
#define base_interfaces_BASE_SM_CALIB                            (5u)
#define base_interfaces_BASE_SM_DEGRADED                         (6u)

/*! @brief Current scheduling mode set by GlobalScheduler */
typedef uint8 BaseSchedulingMode_t;

#define base_interfaces_BASE_SSM_NONE                            (0u)
#define base_interfaces_BASE_SSM_BLOCKAGE                        (1u)
#define base_interfaces_BASE_SSM_DEGRADED                        (2u)
#define base_interfaces_BASE_SSM_STANDALONE                      (4u)
#define base_interfaces_BASE_SSM_PARALLEL                        (8u)
#define base_interfaces_BASE_SSM_NOT_CALIBRATED                  (16u)

/*! @brief Current scheduling sub-mode set by GlobalScheduler. Given as bitmask, multiple sub-modes might be active. */
typedef uint8 BaseSchedulingSubMode_t;

#define base_interfaces_COMP_STATE_NOT_INITIALIZED               (0u)
#define base_interfaces_COMP_STATE_RUNNING                       (1u)
#define base_interfaces_COMP_STATE_TEMPORARY_ERROR               (2u)
#define base_interfaces_COMP_STATE_PERMANENT_ERROR               (3u)
#define base_interfaces_COMP_STATE_SUCCESS                       (4u)
#define base_interfaces_COMP_STATE_REDUCED_AVAILABILITY          (5u)
#define base_interfaces_COMP_STATE_NOT_RUNNING                   (6u)
#define base_interfaces_COMP_STATE_INPUT_INTERFACE_INCONSISTANT  (7u)

/*! @brief The state of the algo after current processing step. Taken as a rough return code to indicate problems during the processing. */
typedef uint8 CompState_t;

#define base_interfaces_COMP_STATE_ERROR                         (2u)
#define base_interfaces_COMP_STATE_SUCCESS                       (4u)

typedef uint8 BASE_INTERFACES_eCompState;

#define base_interfaces_COMP_ERROR_NO_ERROR                      (0u)
#define base_interfaces_COMP_ERROR_UNKNOWN                       (4294967295u)

/*! @brief The error code if in an error state. Component specific value aside from the pre-defined values. Should be set to uniquely identify the error reason. */
typedef uint32 CompErrorCode_t;

#define base_interfaces_opModeReset                              (0u)   /*!< Reset */
#define base_interfaces_opModePause                              (1u)   /*!< Pause */
#define base_interfaces_opModeNormal                             (2u)   /*!< Normal */

/*! @brief OpMode(BASE_INTERFACES) */
typedef uint8 BASE_INTERFACES_OpMode;

#define base_interfaces_opModeReset                              (0u)   /*!< Reset */
#define base_interfaces_opModePause                              (1u)   /*!< Pause */
#define base_interfaces_opModeNormal                             (2u)   /*!< Normal */

/*! @brief OpMode(BASE_INTERFACES) */
typedef uint8 BASE_INTERFACES_OpMode;


typedef float32                              fDistance_t;              /*!< Straight stretch between points or objects, Unit: [m], Range:[-500..500]  */

typedef float32                              fAngle_t;                 /*!< Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise, Unit: [rad], Range:[-CML_f_two_Pi..+CML_f_two_Pi]  */

typedef float32                              fAngleDeg_t;              /*!< Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise, Unit: [deg], Range:[-360..+360]  */

typedef float32                              fYawRate_t;               /*!< Measure of yaw rate, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise, Unit: [rad/s], Range:[-8 * CML_f_Pi..+8 * CML_f_Pi]  */

typedef float32                              fVelocity_t;              /*!< Translatory velocity, time-derivative of distance with sign, forward direction positive, reverse direction negative, Unit: [m/s], Range:[-100..100]  */

typedef float32                              fAccel_t;                 /*!< Translatory acceleration, time-derivative of translatory velocity with sign, Range:[-18..18]  */

typedef float32                              fVelocityAbs_t;           /*!< Magnitude of translatory velocity, time-derivative of distance without sign, Unit: [m/s], Range:[0..100]  */

typedef float32                              fAccelAbs_t;              /*!< Magnitude of translatory acceleration, time-derivative of translatory velocity without sign, increase of velocity: positive, decrease of velocity: negative, Range:[-18..18]  */

typedef float32                              fCurve_t;                 /*!< Curvature (inverse radius) of trajectory, left direction: positive, right direction negative, Unit: [1/m], Range:[-1.0..+1.0]  */

typedef float32                              fRadius_t;                /*!< Radius of trajectory, left direction: positive, right direction negative, Unit: [m], Range:[-100000..+100000]  */

typedef float32                              fTime_t;                  /*!< Period of time, Unit: [s], Range:[0..+3.4E+38]  */

typedef uint16                               uiTime_t;                 /*!< Period of time in ms, Unit: [ms], Range:[0..62000]  */

typedef float32                              fQuality_t;               /*!< Characteristic of a variable, 0: worst quality, 1.0 best quality, Range:[0..1.0]  */

typedef float32                              fProbability_t;           /*!< Propbability of a hypothesis, 0: no probability, 1: full probability, Range:[0..1.0]  */

typedef uint8                                ucConfidence_t;           /*!< Trustiness of value, 0: no reliance, 100: full realiance, Range:[0..100.0]  */

typedef float32                              fConfidence_t;            /*!< Trustiness of value, 0.0: no reliance, 1.0: full realiance, Range:[0.0..1.0]  */

typedef float32                              fUncertainty_t;           /*!< Uncertainty of value, 0.0: no reliance, 1.0: full realiance, Range:[0.0..1.0]  */

typedef float32                              fTemperature_t;           /*!< Thermal state, Unit: [degC], Range:[-300..300]  */

typedef float32                              fVariance_t;              /*!< The variance of a value, Range:[-100000..+100000]  */

typedef float32                              fWeight_t;                /*!< Gravity load in unit of mass, Unit: [kg], Range:[0..50000]  */

typedef float32                              fRatio_t;                 /*!< Ratio of a value, Range:[0..10000]  */

typedef float32                              fStiffness_t;             /*!< Stiffness of a value, Range:[0..10000]  */

typedef float32                              fGradient_t;              /*!< Gradient of a value, Range:[-3.4E+38..+3.4E+38]  */

typedef sint8                                ObjNumber_t;              /*!< Object Number (Object ID), Range:[-1..127]  */

typedef uint8                                percentage_t;             /*!< percentage, Unit: [%], Range:[0..100]  */

typedef uint16                               t_bitfield16;             /*!< 16 bit bitfield, Range:[0..65535]  */

typedef uint32                               AlgoDataTimeStamp_t;      /*!< Algo data time-stamp type (32 bit variant), Unit: [us], Range:[0..4294967295]  */

typedef uint16                               AlgoCycleCounter_t;       /*!< Algo cycle counter, Range:[0..65535]  */

typedef uint32                               AlgoInterfaceVersionNumber_t;  /*!< Algo interface version nummbers, Range:[0..4294967295]  */

typedef uint32                               AlgoComponentVersionNumber_t;  /*!< Algo component version nummbers, Range:[0..4294967295]  */

typedef uint32                               AlgoApplicationNumber_t;  /*!< Algo application number (differentiation between customers, vehicle platforms and projects), Range:[0..4294967295]  */

typedef uint8                                quality_t;                /*!< quality 0 % ... 100 %, Unit: [%], Range:[0..100]  */

typedef uint16                               ParameterID_t;            /*!< Parameter Id used to sync/match interfaces, Range:[0..65535]  */

typedef uint8                                TraceID_t;                /*!< Trace index type, Range:[0..TRACE_NO_OF_TRACES]  */

/*! @brief Vector with x and y with i8 values */
typedef struct
{
    sint8                                nXDist;                   /*!< xDistance  */
    sint8                                nYDist;                   /*!< yDistance  */
} Vector2_i8_t;

/*! @brief Vector with x and y with i16 values */
typedef struct
{
    sint16                               nXDist;                   /*!< xDistance  */
    sint16                               nYDist;                   /*!< yDistance  */
} Vector2_i16_t;

/*! @brief Vector with x and y with i32 values */
typedef struct
{
    sint32                               nXDist;                   /*!< xDistance  */
    sint32                               nYDist;                   /*!< yDistance  */
} Vector2_i32_t;

/*! @brief Vector with x and y with f32 values */
typedef struct
{
    float32                              fXDist;                   /*!< xDistance  */
    float32                              fYDist;                   /*!< yDistance  */
} Vector2_f32_t;

/*! @brief signed 16 bit integer complex */
typedef struct
{
    sint16                               s_Real;
    sint16                               s_Imag;
} t_Complex16;

/*! @brief complex float in cartesian coordinates */
typedef struct
{
    float32                              f_Real;
    float32                              f_Imag;
} t_Complexf32;

/*! @brief complex float in polar coordinates */
typedef struct
{
    float32                              f_Amplitude;
    float32                              f_Phase;
} t_ComplexPolarf32;

typedef uint8                                u8q1_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 1  */

typedef uint8                                u8q2_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 2  */

typedef uint8                                u8q3_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 3  */

typedef uint8                                u8q4_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 4  */

typedef uint8                                u8q5_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 5  */

typedef uint8                                u8q6_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 6  */

typedef uint8                                u8q7_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 7  */

typedef uint8                                u8q8_t;                   /*!< unsigned 8-bit fixed-point type; number of fractional bits = 8  */

typedef sint16                               s16q3_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 3  */

typedef uint16                               u16q3_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 3  */

typedef sint16                               s16q4_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 4  */

typedef uint16                               u16q4_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 4  */

typedef sint16                               s16q5_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 5  */

typedef uint16                               u16q5_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 5  */

typedef sint16                               s16q6_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 6  */

typedef uint16                               u16q6_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 6  */

typedef sint16                               s16q7_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 7  */

typedef uint16                               u16q7_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 7  */

typedef sint16                               s16q8_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 8  */

typedef uint16                               u16q8_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 8  */

typedef sint16                               s16q9_t;                  /*!< signed 16-bit fixed-point type; number of fractional bits = 9  */

typedef uint16                               u16q9_t;                  /*!< unsigned 16-bit fixed-point type; number of fractional bits = 9  */

typedef sint32                               s32q3_t;                  /*!< signed 32-bit fixed-point type; number of fractional bits = 3  */

typedef uint32                               u32q3_t;                  /*!< unsigned 32-bit fixed-point type; number of fractional bits = 3  */

typedef sint32                               s32q4_t;                  /*!< signed 32-bit fixed-point type; number of fractional bits = 4  */

typedef uint32                               u32q4_t;                  /*!< unsigned 32-bit fixed-point type; number of fractional bits = 4  */

typedef sint32                               s32q7_t;                  /*!< signed 32-bit fixed-point type; number of fractional bits = 7  */

typedef uint32                               u32q7_t;                  /*!< unsigned 32-bit fixed-point type; number of fractional bits = 7  */

typedef sint32                               s32q18_t;                 /*!< signed 32-bit fixed-point type; number of fractional bits = 18  */

typedef uint32                               u32q18_t;                 /*!< unsigned 32-bit fixed-point type; number of fractional bits = 18  */

typedef sint32                               s32q24_t;                 /*!< signed 32-bit fixed-point type; number of fractional bits = 24  */

typedef uint32                               u32q24_t;                 /*!< unsigned 32-bit fixed-point type; number of fractional bits = 24  */

/*! @brief Control data giving information about the current mode */
typedef struct
{
    AlgoInterfaceVersionNumber_t         uiVersionNumber;          /*!< Interface version number (increased when changed)  */
    BASE_INTERFACES_SignalHeader_t       sSigHeader;               /*!< contains time stamp, frame stamp, etc.  */
    BaseOpMode_t                         eOpMode;                  /*!< Required operation mode,Accuracy: 1.0, Unit: [Enum],List:BASE_OM_IDLE=0,BASE_OM_RESET=1,BASE_OM_MAX_RUNTIME=2,BASE_OM_DEMO=3,BASE_OM_RUN=4,BASE_OM_RUN_ODD=5,BASE_OM_RUN_EVEN=6,BASE_OM_SYNC=7,BASE_OM_MEAS_ONLY=8,BASE_OM_INIT_LUT=9,BASE_OM_AUTOCAL_COARSE=10,BASE_OM_AUTOCAL_FINE=11,BASE_OM_AUTO_CHOICE=12,BASE_OM_EOL_UPDATE=13,BASE_OM_SELF_EVAL=14,BASE_OM_TEST=15,BASE_OM_DISTANCE_TEST=16,BASE_OM_ECM_RTE_TRANSMIT=17,BASE_OM_ECM_RTE_DEV=18,BASE_OM_ECM_RTE_EOL=19,BASE_OM_FEX_RUN_INIT_FPGA=20,BASE_OM_FEX_RUN_STARTUP_TEST_FPGA=21,BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA=22,BASE_OM_FEX_RUN_SAC_DATA=23,BASE_OM_FEX_RUN_PED_DATA=24,BASE_OM_PED_RUN_HYPGEN=25,BASE_OM_PED_RUN_IMAGE_TRACKING=26,BASE_OM_PED_RUN_CLUSTERING=27,BASE_OM_MEMO_SYNCVDY=28,BASE_OM_VCL_ROIGEN=29,BASE_OM_EM_PREDICT=30,BASE_OM_EM_UPDATE_GEN=31,BASE_OM_EM_UPDATE_PED=32,BASE_OM_EM_UPDATE_VCL=33,BASE_OM_EM_UPDATE_SPC=34,BASE_OM_EM_MAINTENANCE=35,BASE_OM_SIB_GEOMETRY=36,BASE_OM_SIB_DYNAMIC=37,BASE_OM_VODCA_PREPROCESS=38,BASE_OM_VODCA_CLASSIFY=39,BASE_OM_NVM_CALIB_RESET=40,BASE_OM_NVM_RESET=41,BASE_OM_VCL_TRACK=42,BASE_OM_VCL_POSTPROC=43,BASE_OM_HLA_SEG=44,BASE_OM_EM_PROCESS_GSS=45,BASE_OM_EM_PROCESS_OD=46,BASE_OM_EM_PROCESS_ROAD=47,BASE_OM_RUM_INITIAL_ROI_GEN=48,BASE_OM_RUM_TRACKING=49,BASE_OM_RUM_POST_PROC=50,BASE_OM_EM_PROCESS_FLOW=51,BASE_OM_EM_PROCESS_LMD=52,BASE_OM_ACAL_TRANSMIT=53,BASE_OM_ACAL_CALIB=54,BASE_OM_LD_TEXTURE_CLASSIFY=55,BASE_OM_MEMO_RUN_EGOMOTION=56,BASE_OM_MEMO_RUN_DEPTH=57,BASE_OM_VODCA_PROCESS=58,BASE_OM_VODCA_PROCESS_FINAL=59,BASE_OM_GEOS_PROCESS_FLOW=60,BASE_OM_GEOS_SEGMENTATION=61,BASE_OM_GEOS_PROCESS_EXTENDED_FLOW=62,BASE_OM_DAP01=1001,BASE_OM_DAP02=1002,BASE_OM_DAP03=1003,BASE_OM_DAP04=1004,BASE_OM_GP01=1010,BASE_OM_GP02=1011,BASE_OM_GP03=1012,BASE_OM_GP04=1013,BASE_OM_GP05=1014,BASE_OM_GP06=1015,BASE_OM_OD01=1021,BASE_OM_OD02=1022,BASE_OM_OD03=1023,BASE_OM_OD04=1024,BASE_OM_OD05=1025,BASE_OM_OD06=1026,BASE_OM_OD07=1027,BASE_OM_PD01=1036,BASE_OM_PD02=1037,BASE_OM_PCC01=1044,BASE_OM_PCC02=1045,BASE_OM_RMHT01=1046,BASE_OM_RMHT02=1047,BASE_OM_RMHT03=1048,BASE_OM_RMHT04=1049,BASE_OM_RMHT05=1050,BASE_OM_RDT01=1051,BASE_OM_RDT02=1052,BASE_OM_RDT03=1053,BASE_OM_RDT04=1054,BASE_OM_RDT05=1055,BASE_OM_RDT06=1056,BASE_OM_RADI=1057,BASE_OM_RSP01=1058,BASE_OM_SRP1_01=1059,BASE_OM_SRP2_01=1060,BASE_OM_SRP2_02=1061,BASE_OM_SRP2_03=1062,BASE_OM_SRP2_04=1063,BASE_OM_RMP1_01=1064,BASE_OM_RMP2_01=1065,BASE_OM_RMP2_02=1066,BASE_OM_SEP1_01=1067,BASE_OM_SEP2_01=1068,BASE_OM_SEP2_02=1069,BASE_OM_SEP2_03=1070,BASE_OM_OOC01=1071,BASE_OM_RIC01=1072,BASE_OM_RIC02=1073,BASE_OM_CC01=1074,BASE_OM_ACDC01=1075,BASE_OM_LOCTR01=1076,BASE_OM_MEDIC01=1077,BASE_OM_LOPLN01=1078,BASE_OM_RFCOM_Init=1079,BASE_OM_RFCOM_ConfigFrame=1080,BASE_OM_RFCOM_TriggerFrame=1081,BASE_OM_RHC_PreSp1FRS=1082,BASE_OM_RHC_PostSp1FRS=1083,BASE_OM_RHC_PreSp1NRS=1084,BASE_OM_RHC_PostSp1NRS=1085,BASE_OM_RHC_PreLoopbackTest=1086,BASE_OM_RHC_PostLoopbackTest=1087,BASE_OM_RPM1_01=1088,BASE_OM_RPM2_01=1089,BASE_OM_RSP_INIT_CALC_AB_FRS=1090,BASE_OM_RSP_INIT_CALC_AB_NRS=1091,BASE_OM_RSP02=1092,BASE_OM_ALN=1093,BASE_OM_ALN_EOL=1094,BASE_OM_ALN_SERVICE=1095,BASE_OM_ALN_AUTOMATIC=1096,BASE_OM_MOS01=1097,BASE_OM_RPP01=1098,BASE_OM_PCA_NORMAL=2000,BASE_OM_PCA_NUC=2001,BASE_OM_LIQOR_PIXEL_LABEL=2016,BASE_OM_LIQOR_OBJ_LABEL=2017,BASE_OM_VDY=2018,BASE_OM_RC1_01=2019,BASE_OM_RC1_02=2020,BASE_OM_RC2_01=2021,BASE_OM_INVALID=65535  */
    BaseSchedulingMode_t                 eSchedulingMode;          /*!< Current scheduling mode set by GlobalScheduler,Accuracy: 1.0, Unit: [Enum],List:BASE_SM_IDLE=0,BASE_SM_RESET=1,BASE_SM_DEMO=2,BASE_SM_RUN=3,BASE_SM_EOL=4,BASE_SM_CALIB=5,BASE_SM_DEGRADED=6  */
    BaseSchedulingSubMode_t              eSchedulingSubMode;       /*!< Current scheduling sub-mode set by GlobalScheduler. Given as bitmask, multiple sub-modes might be active.,Accuracy: 1.0, Unit: [Enum],List:BASE_SSM_NONE=0,BASE_SSM_BLOCKAGE=1,BASE_SSM_DEGRADED=2,BASE_SSM_STANDALONE=4,BASE_SSM_PARALLEL=8,BASE_SSM_NOT_CALIBRATED=16  */
} BASE_INTERFACES_BaseCtrlData;           /* @versionstr: BASE_CTRL_DATA_INTFVER */

/*! @brief State return values of the algo component */
typedef struct
{
    uint32                               versionNumber;            /*!< Version  */
    BASE_INTERFACES_SignalHeader_t       sigHeader;                /*!< Signal Header  */
    AlgoInterfaceVersionNumber_t         uiVersionNumber;          /*!< Interface version number (increased when changed)  */
    BASE_INTERFACES_SignalHeader_t       sSigHeader;               /*!< contains time stamp, frame stamp, etc.  */
    AlgoComponentVersionNumber_t         uiAlgoVersionNumber;      /*!< Algo component version number  */
    AlgoApplicationNumber_t              uiApplicationNumber;      /*!< Algo application number (differentiation between customers, vehicle platforms and projects).  Comment for radar projects:  most components do not know the application they are running on, not used for radar  */
    uint8                                AlgoVersionInfo[50];      /*!< Algo version Info string (human readable). Comment for radar projects: Human readable strings introduce an high overhead, error code should be used to gain information, therefore not used in radar  */
    CompState_t                          eCompState;               /*!< The state of the algo after current processing step. Taken as a rough return code to indicate problems during the processing.,Accuracy: 1.0, Unit: [Enum],List:COMP_STATE_NOT_INITIALIZED=0,COMP_STATE_RUNNING=1,COMP_STATE_TEMPORARY_ERROR=2,COMP_STATE_PERMANENT_ERROR=3,COMP_STATE_SUCCESS=4,COMP_STATE_REDUCED_AVAILABILITY=5,COMP_STATE_NOT_RUNNING=6,COMP_STATE_INPUT_INTERFACE_INCONSISTANT=7  */
    BaseSchedulingSubMode_t              eShedulerSubModeRequest;  /*!< Mode request to sheduler. Back channel to the global scheduler to request certain sub modes. Only used in case the component has a requirement to do so. Comment for radar projects: Scheduling is done top/down, therefore not used in radar  */
    CompErrorCode_t                      eErrorCode;               /*!< The error code if in an error state. Component specific value aside from the pre-defined values. Should be set to uniquely identify the error reason.,Accuracy: 1.0, Unit: [Enum],List:COMP_ERROR_NO_ERROR=0,COMP_ERROR_UNKNOWN=4294967295  */
} BASE_INTERFACES_AlgoCompState;           /* @versionstr: COMP_STATE_INTFVER */


#ifdef __cplusplus
}
#endif

#endif /* #if (GA_CFG_BASE_INTERFACES == 1) */

/*! @} end defgroup */

#endif /* #ifndef GA_BASE_INTERFACES_EXT_H_INCLUDED */
