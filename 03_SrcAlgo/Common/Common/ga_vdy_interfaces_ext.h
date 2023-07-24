#ifndef _GA_GLOBAL_H_INCLUDED
#error include setup error: forbidden inclusion of GA local-scope header file; only component *_main.h + *_wrapper.h, and ga_global.h (or ga_global_emlib.h on emlib dependancy) are allowed
#endif

#ifndef GA_VDY_INTERFACES_EXT_H_INCLUDED
#define GA_VDY_INTERFACES_EXT_H_INCLUDED

/*! @ingroup vdy_interfaces
@{
@file
External header of the VDY_INTERFACES component.    */


#if (GA_CFG_VDY_INTERFACES == 1)

#ifdef __cplusplus
extern "C" {
#endif

/* --- virtual addresses --------------------------------------------------- */
#define VDY_INTERFACES_VA_CONTROL_DATA       ()   /*!< virtual address of controlData (uL) */

/* ---- constants ---------------------------------------------------------- */
#define GA_P_BACKUP_SENSORS_AVAILABLE       (0)

/* ---- type InterfaceVersion ---------------------------------------------- */
#define VDY_INTERFACES_CONTROL_DATA_INTVER  (1)  /*!< version of VDY_INTERFACES_ControlData */
#define BSW_VDY_CTRL_DATA_INTFVER           (3)  /*!< version of VDY_INTERFACES_BSW_s_VDYCtrlData */
#define VDY_VEH_DYN_INTFVER                 (37)  /*!< version of VehDyn_t */
#define BSW_VEH_SIG_INTFVER                 (101)  /*!< version of VDY_INTERFACES_VehSig */
#define BSW_VEH_PAR_INTFVER                 (9)  /*!< version of VDY_INTERFACES_VehPar */
#define VDY_OFFSETS_INTFVER                 (2)  /*!< version of VDY_INTERFACES_VDYOffsets */
#define VDY_ERRORS_INTFVER                  (3)  /*!< version of VDY_INTERFACES_VDYErrors */
#define VDY_NVM_IO_DATA_INTFVER             (1)  /*!< version of VDY_INTERFACES_VDYNvIoData */
#define VDY_EST_CURVES_INTFVER              (1)  /*!< version of VDY_INTERFACES_VDYEstCurves */

/* ---- type definitions --------------------------------------------------- */
#define vdy_interfaces_VDY_CAL_INIT                            (0u)
#define vdy_interfaces_VDY_CAL_YWR_OFFS_STST                   (1u)
#define vdy_interfaces_VDY_CAL_YWR_OFFS_DYN                    (2u)
#define vdy_interfaces_VDY_CAL_WHS_OFFS                        (4u)
#define vdy_interfaces_VDY_CAL_SWA_OFFS                        (16u)
#define vdy_interfaces_VDY_CAL_LTA_OFFS                        (32u)
#define vdy_interfaces_VDY_CAL_SWA_GRAD                        (64u)
#define vdy_interfaces_VDY_CAL_WHS_LOAD                        (128u)

/*! @brief Calibration inhibition states */
typedef uint8 VDY_INTERFACES_VDYCaliState_t;

#define vdy_interfaces_VDY_CTRL_STATE_STARTUP                  (0u)
#define vdy_interfaces_VDY_CTRL_STATE_INIT                     (1u)
#define vdy_interfaces_VDY_CTRL_STATE_RUNNING                  (2u)

/*! @brief Operating modes of vdy component */
typedef uint8 VDY_INTERFACES_VDYCtrlState_t;

#define vdy_interfaces_VDY_IO_STATE_VALID                      (0u)
#define vdy_interfaces_VDY_IO_STATE_INVALID                    (1u)
#define vdy_interfaces_VDY_IO_STATE_NOTAVAIL                   (2u)
#define vdy_interfaces_VDY_IO_STATE_DECREASED                  (3u)
#define vdy_interfaces_VDY_IO_STATE_SUBSTITUE                  (4u)
#define vdy_interfaces_VDY_IO_STATE_INPLAUSIBLE                (5u)
#define vdy_interfaces_VDY_IO_STATE_CF_CALC                    (6u)
#define vdy_interfaces_VDY_IO_STATE_INIT                       (15u)
#define vdy_interfaces_VDY_IO_STATE_MAX                        (255u)

/*! @brief vdy io states */
typedef uint8 VDY_INTERFACES_VDYIoStateTypes_t;

#define vdy_interfaces_VDY_SOUT_POS_VELOCITY                   (0u)
#define vdy_interfaces_VDY_SOUT_POS_ACCEL                      (1u)
#define vdy_interfaces_VDY_SOUT_POS_YAWRATE                    (2u)
#define vdy_interfaces_VDY_SOUT_POS_CURVE                      (3u)
#define vdy_interfaces_VDY_SOUT_POS_DRVINTCURVE                (4u)
#define vdy_interfaces_VDY_SOUT_POS_LATERALACCEL               (5u)
#define vdy_interfaces_VDY_SOUT_POS_SLIPANGLE                  (6u)
#define vdy_interfaces_VDY_SOUT_POS_MOTIONSTATE                (7u)
#define vdy_interfaces_VDY_SOUT_POS_SELFSTEERING               (8u)
#define vdy_interfaces_VDY_SOUT_POS_RAW_YWR                    (10u)
#define vdy_interfaces_VDY_SOUT_POS_RAW_VEL                    (11u)
#define vdy_interfaces_VDY_SOUT_POS_MAX                        (12u)

/*! @brief Position in VehDyn State array */
typedef uint8 VDY_INTERFACES_VehDynStatePos_t;

#define vdy_interfaces_VDY_SIN_POS_YWR                         (0u)
#define vdy_interfaces_VDY_SIN_POS_YWR_TEMP                    (1u)
#define vdy_interfaces_VDY_SIN_POS_SWA                         (2u)
#define vdy_interfaces_VDY_SIN_POS_LATA                        (3u)
#define vdy_interfaces_VDY_SIN_POS_WVEL_FL                     (4u)
#define vdy_interfaces_VDY_SIN_POS_WVEL_FR                     (5u)
#define vdy_interfaces_VDY_SIN_POS_WVEL_RL                     (6u)
#define vdy_interfaces_VDY_SIN_POS_WVEL_RR                     (7u)
#define vdy_interfaces_VDY_SIN_POS_YWRINT                      (8u)
#define vdy_interfaces_VDY_SIN_POS_YWRINT_TEMP                 (9u)
#define vdy_interfaces_VDY_SIN_POS_LONGA                       (10u)
#define vdy_interfaces_VDY_SIN_POS_RSTA                        (11u)
#define vdy_interfaces_VDY_SIN_POS_VEHVEL_EXT                  (12u)
#define vdy_interfaces_VDY_SIN_POS_VEHACL_EXT                  (13u)
#define vdy_interfaces_VDY_SIN_POS_WDIR_FL                     (14u)
#define vdy_interfaces_VDY_SIN_POS_WDIR_FR                     (15u)
#define vdy_interfaces_VDY_SIN_POS_WDIR_RL                     (16u)
#define vdy_interfaces_VDY_SIN_POS_WDIR_RR                     (17u)
#define vdy_interfaces_VDY_SIN_POS_WTCKS_FL                    (18u)
#define vdy_interfaces_VDY_SIN_POS_WTCKS_FR                    (19u)
#define vdy_interfaces_VDY_SIN_POS_WTCKS_RL                    (20u)
#define vdy_interfaces_VDY_SIN_POS_WTCKS_RR                    (21u)
#define vdy_interfaces_VDY_SIN_POS_GEAR                        (22u)
#define vdy_interfaces_VDY_SIN_POS_BRAKE                       (23u)
#define vdy_interfaces_VDY_SIN_POS_PBRK                        (24u)
#define vdy_interfaces_VDY_SIN_POS_VDIR                        (25u)
#define vdy_interfaces_VDY_SIN_POS_VMOT                        (26u)
#define vdy_interfaces_VDY_SIN_POS_DUMMY                       (27u)
#define vdy_interfaces_VDY_SIN_POS_CRV                         (28u)
#define vdy_interfaces_VDY_SIN_POS_SSA                         (29u)
#define vdy_interfaces_VDY_SIN_POS_MAX                         (32u)

/*! @brief Position in VehSig.VehSigMain State array */
typedef uint8 VDY_INTERFACES_VehSigMainStatePos_t;

#define vdy_interfaces_VEH_SIG_ADD_ENV_TEMP                    (0u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_STATE                 (1u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_STAGE                 (2u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_OUT_PARK_POS          (3u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_WASHER_FRONT          (4u)
#define vdy_interfaces_VEH_SIG_ADD_RAIN_SENSOR                 (5u)
#define vdy_interfaces_VEH_SIG_ADD_TURN_SIGNAL                 (6u)
#define vdy_interfaces_VEH_SIG_ADD_FOG_LAMP_FRONT              (7u)
#define vdy_interfaces_VEH_SIG_ADD_FOG_LAMP_REAR               (8u)
#define vdy_interfaces_VEH_SIG_ADD_ROAD_WHL_ANG_FR             (9u)
#define vdy_interfaces_VEH_SIG_ADD_ROAD_WHL_ANG_RE             (10u)
#define vdy_interfaces_VEH_SIG_ADD_ODOMETER                    (11u)
#define vdy_interfaces_VEH_SIG_ADD_GAS_PEDAL_POS               (12u)
#define vdy_interfaces_VEH_SIG_ADD_KICK_DOWN                   (13u)
#define vdy_interfaces_VEH_SIG_ADD_BRAKE_PEDAL_PRESSED         (14u)
#define vdy_interfaces_VEH_SIG_ADD_DRIVER_TIRED                (15u)
#define vdy_interfaces_VEH_SIG_ADD_SPEED_UNIT                  (16u)
#define vdy_interfaces_VEH_SIG_ADD_SPEEDO_SPEED                (17u)
#define vdy_interfaces_VEH_SIG_ADD_TRAILER_CON                 (18u)
#define vdy_interfaces_VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN    (19u)
#define vdy_interfaces_VEH_SIG_ADD_TRAILER_LENGTH_INPUT        (20u)
#define vdy_interfaces_VEH_SIG_ADD_PARK_AID_DET_L              (21u)
#define vdy_interfaces_VEH_SIG_ADD_PARK_AID_DET_CL             (22u)
#define vdy_interfaces_VEH_SIG_ADD_PARK_AID_DET_CR             (23u)
#define vdy_interfaces_VEH_SIG_ADD_PARK_AID_DET_R              (24u)
#define vdy_interfaces_VEH_SIG_ADD_IGN_SWITCH                  (25u)
#define vdy_interfaces_VEH_SIG_ADD_HEIGHT_LEVEL                (26u)
#define vdy_interfaces_VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL          (27u)
#define vdy_interfaces_VEH_SIG_ADD_EXT_CAM_BLOCKAGE_DETECTION  (28u)
#define vdy_interfaces_VEH_SIG_ADD_MAX                         (32u)

/*! @brief Position in VehSig.VehSigAdd State array */
typedef uint8 VDY_INTERFACES_VehSigAddStatePos_t;

#define vdy_interfaces_VDY_PAR_POS_SSG                         (0u)
#define vdy_interfaces_VDY_PAR_POS_SWARAT                      (1u)
#define vdy_interfaces_VDY_PAR_POS_WBASE                       (2u)
#define vdy_interfaces_VDY_PAR_POS_TWDFR                       (3u)
#define vdy_interfaces_VDY_PAR_POS_TWDRE                       (4u)
#define vdy_interfaces_VDY_PAR_POS_VEHWGT                      (5u)
#define vdy_interfaces_VDY_PAR_POS_COGH                        (6u)
#define vdy_interfaces_VDY_PAR_POS_AXLD                        (7u)
#define vdy_interfaces_VDY_PAR_POS_WHLDFR                      (8u)
#define vdy_interfaces_VDY_PAR_POS_WHLDRE                      (9u)
#define vdy_interfaces_VDY_PAR_POS_WHLCIR                      (10u)
#define vdy_interfaces_VDY_PAR_POS_DRVAXL                      (11u)
#define vdy_interfaces_VDY_PAR_POS_WTCKSREV                    (12u)
#define vdy_interfaces_VDY_PAR_POS_CSFR                        (13u)
#define vdy_interfaces_VDY_PAR_POS_CSRE                        (14u)
#define vdy_interfaces_VDY_PAR_POS_MAX                         (16u)

/*! @brief Position in VehPar.VehParMain State array */
typedef uint8 VDY_INTERFACES_VehParMainStatePos_t;

#define vdy_interfaces_VEH_PAR_ADD_VEHICLE_WIDTH               (0u)
#define vdy_interfaces_VEH_PAR_ADD_VEHICLE_LENGTH              (1u)
#define vdy_interfaces_VEH_PAR_ADD_CURB_WEIGHT                 (2u)
#define vdy_interfaces_VEH_PAR_ADD_OVERHANG_FRONT              (3u)
#define vdy_interfaces_VEH_PAR_ADD_FRONT_AXLE_ROAD             (4u)
#define vdy_interfaces_VEH_PAR_ADD_WHEEL_WIDTH                 (5u)
#define vdy_interfaces_VEH_PAR_ADD_STEERING_VARIANT            (6u)
#define vdy_interfaces_VEH_PAR_ADD_PASSABLE_HEIGHT             (7u)
#define vdy_interfaces_VEH_PAR_ADD_DIST_CAMERA_HOOD_X          (8u)
#define vdy_interfaces_VEH_PAR_ADD_DIST_CAMERA_HOOD_Y          (9u)
#define vdy_interfaces_VEH_PAR_ADD_MAX                         (12u)

/*! @brief Position in VehPar.VehParAdd State array */
typedef uint8 VDY_INTERFACES_VehParAddStatePos_t;

#define vdy_interfaces_VEH_PAR_SEN_MOUNT_LAT_POS               (0u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_LONG_POS              (1u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_VERT_POS              (2u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG        (3u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_PITCH_ANGLE           (4u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_ORIENTATION           (5u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_ROLL_ANGLE            (6u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_YAW_ANGLE             (7u)
#define vdy_interfaces_VEH_PAR_SEN_MOUNT_MAX                   (8u)

/*! @brief Position in VehPar.SensorMounting State array */
typedef uint8 VDY_INTERFACES_VehParSenMountStatePos_t;

#define vdy_interfaces_VEH_PAR_SENSOR_COVER_DAMPING            (0u)
#define vdy_interfaces_VEH_PAR_SENSOR_COVERAGE_ANGLE           (1u)
#define vdy_interfaces_VEH_PAR_SENSOR_LOBE_ANGLE               (2u)
#define vdy_interfaces_VEH_PAR_SENSOR_CYCLE_TIME               (3u)
#define vdy_interfaces_VEH_PAR_SENSOR_NO_OF_SCANS              (4u)
#define vdy_interfaces_VEH_PAR_SENSOR_MAX                      (8u)

/*! @brief Position in VehPar.Sensor State array */
typedef uint8 VDY_INTERFACES_VehParSensorStatePos_t;

#define vdy_interfaces_VEH_SIG_BRAKE_ABS                       (0u)
#define vdy_interfaces_VEH_SIG_BRAKE_TSC                       (1u)
#define vdy_interfaces_VEH_SIG_BRAKE_MAX                       (2u)

/*! @brief Position in VehSig.Brake State array */
typedef uint8 VDY_INTERFACES_VehSigBrakeStatePos_t;

#define vdy_interfaces_VEH_SIG_POWERTRAIN_ACTUALGEAR           (0u)
#define vdy_interfaces_VEH_SIG_POWERTRAIN_TARGETGEAR           (1u)
#define vdy_interfaces_VEH_SIG_POWERTRAIN_ENGINE_RUNNING       (2u)
#define vdy_interfaces_VEH_SIG_POWERTRAIN_MAX                  (4u)

/*! @brief Position in VehSig.Powertrain State array */
typedef uint8 VDY_INTERFACES_VehSigPowertrainStatePos_t;

#define vdy_interfaces_VDY_NVM_POS_SWA                         (0u)
#define vdy_interfaces_VDY_NVM_POS_SSG                         (2u)
#define vdy_interfaces_VDY_NVM_POS_YWR                         (4u)
#define vdy_interfaces_VDY_NVM_POS_LATACC                      (6u)
#define vdy_interfaces_VDY_NVM_POS_VELCORR                     (8u)
#define vdy_interfaces_VDY_NVM_POS_WLD                         (10u)
#define vdy_interfaces_VDY_NVM_POS_MAX                         (125000u)

/*! @brief Position in NVM State array */
typedef uint32 VDY_INTERFACES_VDYNvmState_t;

#define vdy_interfaces_VDY_LONG_DIR_VOID                       (0u)
#define vdy_interfaces_VDY_LONG_DIR_FWD                        (1u)
#define vdy_interfaces_VDY_LONG_DIR_RWD                        (2u)

/*! @brief Direction of movement */
typedef uint8 VDY_INTERFACES_LongDirState_t;

#define vdy_interfaces_VDY_DRV_AXLE_UNKNOWN                    (0u)
#define vdy_interfaces_VDY_DRV_AXLE_FRONT                      (1u)
#define vdy_interfaces_VDY_DRV_AXLE_REAR                       (2u)
#define vdy_interfaces_VDY_DRV_AXLE_ALL                        (3u)

/*! @brief Direction of movement */
typedef uint8 VDY_INTERFACES_VDYDrvAxle_t;

#define vdy_interfaces_VEH_SIG_ADD_TRLR_NO_DETECT              (0u)
#define vdy_interfaces_VEH_SIG_ADD_TRLR_OK                     (1u)
#define vdy_interfaces_VEH_SIG_ADD_TRLR_NDEF2                  (2u)
#define vdy_interfaces_VEH_SIG_ADD_TRLR_SNA                    (3u)

typedef uint8 VDY_INTERFACES_VDYTrailerConnection_t;

#define vdy_interfaces_VEH_SIG_BELT_NOT_FASTENED               (0u)
#define vdy_interfaces_VEH_SIG_BELT_FASTENED                   (1u)
#define vdy_interfaces_VEH_SIG_BELT_UNKOWN                     (2u)

typedef uint8 VDY_INTERFACES_SeatBeltStatus_t;

#define vdy_interfaces_VEH_SIG_DOOR_OPEN                       (0u)
#define vdy_interfaces_VEH_SIG_DOOR_CLOSED                     (1u)
#define vdy_interfaces_VEH_SIG_DOOR_LOCKED                     (2u)
#define vdy_interfaces_VEH_SIG_DOOR_UNKOWN                     (3u)

typedef uint8 VDY_INTERFACES_DoorStatus_t;

#define vdy_interfaces_VDY_NO_VELO_CORR                        (0u)
#define vdy_interfaces_VDY_VELO_CORR_QUAL_EEPROM               (1u)
#define vdy_interfaces_VDY_VELO_CORR_QUAL_RANGE_NVERIFIED      (2u)
#define vdy_interfaces_VDY_VELO_CORR_QUAL_RANGE_VERIFIED       (3u)
#define vdy_interfaces_VDY_VELO_CORR_QUAL_SNA                  (4u)

/*! @brief Velocity correction quality flag */
typedef uint8 VDY_INTERFACES_VelocityCorrectionQuality;

#define vdy_interfaces_VDY_LONG_MOT_STATE_MOVE                 (0u)
#define vdy_interfaces_VDY_LONG_MOT_STATE_MOVE_FWD             (1u)
#define vdy_interfaces_VDY_LONG_MOT_STATE_MOVE_RWD             (2u)
#define vdy_interfaces_VDY_LONG_MOT_STATE_STDST                (3u)

/*! @brief Moving (forward or reverse) Moving forward Moving reverse Stand still */
typedef uint8 VDY_INTERFACES_MotState;

#define vdy_interfaces_ACT_GEAR_POS_NEUTRAL                    (0u)
#define vdy_interfaces_ACT_GEAR_POS_PARKING                    (1u)
#define vdy_interfaces_ACT_GEAR_POS_FORWARD                    (2u)
#define vdy_interfaces_ACT_GEAR_POS_REVERSE                    (3u)

/*! @brief VDY_SIN_POS_GEAR */
typedef uint8 VDY_INTERFACES_ActGearPos;

#define vdy_interfaces_STAT_INACTIVE                           (0u)
#define vdy_interfaces_STAT_ACTIVE                             (1u)

/*! @brief VDY_SIN_POS_PBRK */
typedef uint8 VDY_INTERFACES_ParkBrakeState;

#define vdy_interfaces_VDY_VEH_MOT_STATE_ROLLING               (0u)
#define vdy_interfaces_VDY_VEH_MOT_STATE_FAST_STST             (1u)
#define vdy_interfaces_VDY_VEH_MOT_STATE_SECURE_STST           (2u)

/*! @brief VDY_SIN_POS_VMOT */
typedef uint8 VDY_INTERFACES_VehLongMotStateExt;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_YawRateStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_LatAccelStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlVelFrLeftStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlVelFrRightStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlVelReLeftStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlVelReRightStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlTicksDevFrLeftStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlTicksDevFrRightStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlTicksDevReLeftStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_WhlTicksDevReRightStatus;

#define vdy_interfaces_SENSOR_SOURCE_UNKOWN                    (0u)
#define vdy_interfaces_SENSOR_SOURCE_PRIMARY                   (1u)
#define vdy_interfaces_SENSOR_SOURCE_BACKUP                    (2u)

/*! @brief sensor source state (primary, backup) */
typedef uint8 VDY_INTERFACES_StWheelAngleStatus;

#define vdy_interfaces_VEH_SIG_ADD_WIPER_STATE_INACTIVE        (0u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_STATE_ACTIVE          (1u)

/*! @brief Wiper blades activity */
typedef uint8 VDY_INTERFACES_WiperState;

#define vdy_interfaces_VEH_SIG_ADD_WIPER_OFF                   (0u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_INTERVAL1             (1u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_INTERVAL2             (2u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_INTERVAL3             (3u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_INTERVAL4             (4u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_STAGE1                (5u)
#define vdy_interfaces_VEH_SIG_ADD_WIPER_STAGE2                (6u)

/*! @brief Wiper switch position */
typedef uint8 VDY_INTERFACES_WiperStage;

#define vdy_interfaces_VEH_SIG_ADD_WWS_IDLE                    (0u)
#define vdy_interfaces_VEH_SIG_ADD_WWS_TIPWIPE                 (1u)
#define vdy_interfaces_VEH_SIG_ADD_WWS_WASH                    (2u)

/*! @brief Tip-wipe / washer state */
typedef uint8 VDY_INTERFACES_WiperWasherFrontState;

#define vdy_interfaces_VEH_SIG_ADD_TURN_SIG_UNKNOWN            (0u)
#define vdy_interfaces_VEH_SIG_ADD_TURN_SIG_LEFT               (1u)
#define vdy_interfaces_VEH_SIG_ADD_TURN_SIG_RIGHT              (2u)
#define vdy_interfaces_VEH_SIG_ADD_TURN_SIG_NEUTRAL            (3u)
#define vdy_interfaces_VEH_SIG_ADD_TURN_SIG_BOTH               (4u)

/*! @brief Turn signal switch state */
typedef uint8 VDY_INTERFACES_TurnSignal;

#define vdy_interfaces_VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN         (0u)
#define vdy_interfaces_VEH_SIG_ADD_SPEEDO_UNIT_KMH             (1u)
#define vdy_interfaces_VEH_SIG_ADD_SPEEDO_UNIT_MPH             (2u)

/*! @brief ENUM speedmeter speed unit */
typedef uint8 VDY_INTERFACES_SpeedUnit;

#define vdy_interfaces_VEH_SIG_ADD_IGN_LOCK                    (0u)
#define vdy_interfaces_VEH_SIG_ADD_IGN_OFF                     (1u)
#define vdy_interfaces_VEH_SIG_ADD_IGN_ACC                     (2u)
#define vdy_interfaces_VEH_SIG_ADD_IGN_ON                      (4u)
#define vdy_interfaces_VEH_SIG_ADD_IGN_START                   (5u)

/*! @brief Ignition lock, Ignition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) */
typedef uint8 VDY_INTERFACES_IgnitionSwitch;

#define vdy_interfaces_VEH_SIG_ADD_NO_ACTIVE_SUSPENSION        (0u)
#define vdy_interfaces_VEH_SIG_ADD_ACTIVE_SUSPENSION           (1u)

/*! @brief Availability of active suspension: 0: no active suspension available 1: active suspension available */
typedef uint8 VDY_INTERFACES_eSuspensionSystem;

#define vdy_interfaces_VEH_SIG_ADD_NO_HEIGHT_LVL               (0u)
#define vdy_interfaces_VEH_SIG_ADD_HEIGHT_LVL_NORMAL           (1u)
#define vdy_interfaces_VEH_SIG_ADD_HEIGHT_LVL_LOW              (2u)
#define vdy_interfaces_VEH_SIG_ADD_HEIGHT_LVL_HIGH             (4u)

/*! @brief Height adjustment value the car: 0: no height level available 1: height level normal 2: height level low 3: height level high */
typedef uint8 VDY_INTERFACES_eHeightLevel;

#define vdy_interfaces_EXT_CAM_BLOCKAGE_UNKOWN                 (0u)
#define vdy_interfaces_EXT_CAM_BLOCKAGE_DETECTED               (1u)
#define vdy_interfaces_EXT_CAM_BLOCKAGE_NOT_DETECTED           (2u)

/*! @brief result type for blockage detection from external camera, in case it is available */
typedef uint8 VDY_INTERFACES_ExternalCamBlockageDetection;

#define vdy_interfaces_DYN_GEAR_NEUTRAL_GEAR                   (0u)
#define vdy_interfaces_DYN_GEAR_FIRST_GEAR                     (1u)
#define vdy_interfaces_DYN_GEAR_SECOND_GEAR                    (2u)
#define vdy_interfaces_DYN_GEAR_THIRD_GEAR                     (3u)
#define vdy_interfaces_DYN_GEAR_FOURTH_GEAR                    (4u)
#define vdy_interfaces_DYN_GEAR_FIFTH_GEAR                     (5u)
#define vdy_interfaces_DYN_GEAR_SIXTH_GEAR                     (6u)
#define vdy_interfaces_DYN_GEAR_SEVENTH_GEAR                   (7u)
#define vdy_interfaces_DYN_GEAR_EIGHTH_GEAR                    (8u)
#define vdy_interfaces_DYN_GEAR_NINTH_GEAR                     (9u)
#define vdy_interfaces_DYN_GEAR_REVERSE_GEAR                   (10u)
#define vdy_interfaces_DYN_GEAR_PARK_GEAR                      (11u)
#define vdy_interfaces_DYN_GEAR_POWER_FREE                     (12u)
#define vdy_interfaces_DYN_GEAR_POWER_INVALID                  (255u)

/*! @brief Indicates current used gear position */
typedef uint8 TransmissionGear_t;

#define vdy_interfaces_VEH_PAR_ADD_STEERING_VAR_UNKNOWN        (0u)
#define vdy_interfaces_VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE      (1u)
#define vdy_interfaces_VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE     (2u)

/*! @brief Mounting position of steering wheel (in driving direction) */
typedef uint8 VDY_INTERFACES_SteeringVariant;

#define vdy_interfaces_SENSOR_OR_NORMAL                        (0u)
#define vdy_interfaces_SENSOR_OR_ROTATED                       (1u)

/*! @brief Angular displacement around sensor longitudinal axis */
typedef uint8 VDY_INTERFACES_Orientation;

#define vdy_interfaces_VDY_ERR_STATE_UNKNOWN                   (0u)
#define vdy_interfaces_VDY_ERR_STATE_ACTIVE                    (1u)
#define vdy_interfaces_VDY_ERR_STATE_INACTIVE                  (2u)

/*! @brief the vdy error state type */
typedef uint8 VDYErrState_t;

#define vdy_interfaces_opModeReset                             (0u)   /*!< Reset */
#define vdy_interfaces_opModePause                             (1u)   /*!< Pause */
#define vdy_interfaces_opModeNormal                            (2u)   /*!< Normal */

/*! @brief OpMode(VDY_INTERFACES) */
typedef uint8 VDY_INTERFACES_OpMode;

#define vdy_interfaces_opModeReset                             (0u)   /*!< Reset */
#define vdy_interfaces_opModePause                             (1u)   /*!< Pause */
#define vdy_interfaces_opModeNormal                            (2u)   /*!< Normal */

/*! @brief OpMode(VDY_INTERFACES) */
typedef uint8 VDY_INTERFACES_OpMode;


typedef uint32                                            VDYIoState_t;                  /*!< vdy io states type  */

/*! @brief BSW VDY Control Data */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< information for synchronisation of SIL simulation  */
    boolean                                           ProductionMode;                /*!< information (e.g. via diagnosis or bus signal), that sensor in in production mode (i.e. on an roller test bench),Accuracy: 1.0, Range:[0..1]  */
    uiTime_t                                          CycleTime;                     /*!< component cycle time  */
} VDY_INTERFACES_BSW_s_VDYCtrlData;           /* @versionstr: BSW_VDY_CTRL_DATA_INTFVER */

/*! @brief Longitudinal motion variables */
typedef struct
{
    fVelocity_t                                       Velocity;                      /*!< Based on wheel speeds, slip compensated, uncorrected and without sign DEM is sent if signal exceeds typical range range see base type definition  */
    AlgoDataTimeStamp_t                               VelocityTimestamp;             /*!< timestamp of 'Velocity'  */
    fVelocity_t                                       VelocityRaw;                   /*!< Corrected Velocity derived from Mean of four wheel speed  */
    fAccel_t                                          Accel;                         /*!< Longitudinal acceleration in travel direction (compensated for road gradients) DEM is sent if signal exceeds typical range range see base type definition  */
    AlgoDataTimeStamp_t                               AccelTimestamp;                /*!< timestamp of 'Accel'  */
    fVariance_t                                       varVelocity;                   /*!< Longitudinal velocity variance (includes all sources of errors and confidences including velocity correction from radar targets) DEM is sent if signal exceeds typical range range see base type definition  */
    fVariance_t                                       varAccel;                      /*!< Longitudinal acceleration variance  */
    VDY_INTERFACES_VelocityCorrectionQuality          VelocityCorrectionQuality;     /*!< Velocity correction quality flag,Accuracy: 1.0, Unit: [Enum],List:VDY_NO_VELO_CORR=0,VDY_VELO_CORR_QUAL_EEPROM=1,VDY_VELO_CORR_QUAL_RANGE_NVERIFIED=2,VDY_VELO_CORR_QUAL_RANGE_VERIFIED=3,VDY_VELO_CORR_QUAL_SNA=4  */
} VDY_INTERFACES_Longitudinal;
/*! @brief Vehicle yaw rate */
typedef struct
{
    fYawRate_t                                        YawRate;                       /*!< Estimated vehicle angular rate about vertical axis (offset compensated)  */
    AlgoDataTimeStamp_t                               YawRateTimestamp;              /*!< timestamp of 'YawRate'  */
    fYawRate_t                                        YawRateRaw;                    /*!< Offset Compensated Gier yaw rate  */
    fAngle_t                                          YawAngle;                      /*!< yaw angle - integrated/accumulated YawRate  */
    fVariance_t                                       Variance;                      /*!< Estimated vehicle yaw rate variance  */
} YawRateVehDyn_t;
/*! @brief Curve */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Driven vehicle curve as inverse radius (related to vehicle CoG)  */
    AlgoDataTimeStamp_t                               CurveTimestamp;                /*!< timestamp of 'Curve' => Driven vehicle curve as inverse radius (related to vehicle CoG)  */
    fVariance_t                                       VarCurve;                      /*!< Variance of course c0 curvature  */
    float32                                           CrvError;                      /*!< Lateral error of curvature, Range:[0.0..1.0]  */
    uint8                                             CrvConf;                       /*!< Confidence of curvature, Range:[0..6]  */
} CurveVehDyn_t;
/*! @brief Driver intended curvature */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Driver intended curvature (derived from steering wheel angle), related to vehicle CoG  */
    AlgoDataTimeStamp_t                               CurveTimestamp;                /*!< timestamp of 'Curve' => Driver intended curvature (derived from steering wheel angle), related to vehicle CoG  */
    fVariance_t                                       Variance;                      /*!< Driver intended curvature variance  */
    float32                                           Gradient;                      /*!< Time derivative of dirver intended curvature, Range:[-25..+25]  */
} DrvIntCurveVehDyn_t;
/*! @brief Lateral acceleration */
typedef struct
{
    float32                                           LatAccel;                      /*!< Acceleration perpendicular to travel direction (road bank angle compensated), related to vehicle CoG, Range:[-15..15]  */
    AlgoDataTimeStamp_t                               LatAccelTimestamp;             /*!< timestamp of 'LatAccel'  */
    fVariance_t                                       Variance;                      /*!< Lateral acceleration variance  */
} LatAccelVehDyn_t;
/*! @brief Vehice body side slip angle */
typedef struct
{
    float32                                           SideSlipAngle;                 /*!< Vehicle body side slip angle, related to CoG  */
    float32                                           Variance;                      /*!< Vehicle side slip angle variance  */
} SideSlipVehDyn_t;
/*! @brief Outputs associated to self steering properties. */
typedef struct
{
    fAngle_t                                          RoadBankAngle;                 /*!< Estimated banking angle of the road.  */
    fQuality_t                                        QuRoadBankAngle;               /*!< Quality of road bank angle estimation.  */
    float32                                           SelfSteerGradEst;              /*!< Estimated self steering gradient of the vehicle.  */
    fQuality_t                                        QuSelfSteerGradEst;            /*!< Quality of self steering gradient estimation.  */
} SelfSteerVehDyn_t;
/*! @brief Lateral motion variables */
typedef struct
{
    YawRateVehDyn_t                                   YawRate;                       /*!< Vehicle yaw rate  */
    CurveVehDyn_t                                     Curve;                         /*!< Curve  */
    DrvIntCurveVehDyn_t                               DrvIntCurve;                   /*!< Driver intended curvature  */
    LatAccelVehDyn_t                                  Accel;                         /*!< Lateral acceleration  */
    SideSlipVehDyn_t                                  SlipAngle;                     /*!< Vehice body side slip angle  */
    SelfSteerVehDyn_t                                 SelfSteering;                  /*!< Outputs associated to self steering properties.  */
} VDY_INTERFACES_Lateral;
/*! @brief Motion State */
typedef struct
{
    VDY_INTERFACES_MotState                           MotState;                      /*!< Moving (forward or reverse) Moving forward Moving reverse Stand still,Accuracy: 1.0, Unit: [Enum],List:VDY_LONG_MOT_STATE_MOVE=0,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3  */
    ucConfidence_t                                    Confidence;                    /*!< Confidence of motion state  */
    boolean                                           bRollerTestBench;              /*!< roller test bench velocity: the ego speed (VeloCorr.corrVelo and MotVar.Velocity) is given as a velocity of wheels. The velocity with respect to the environment is 0.,Accuracy: 1.0, Range:[0..1]  */
} MotionStateVehDyn_t;
/*! @brief Vehicle dynamic data (VDY output) */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Version of interface  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< - Contains time stamp, frame stamp, etc. - In addition to the eSigStatus each signal has its own state. Therefore, both the eSigStatus and the State has to be checked before a signal is used  */
    VDY_INTERFACES_Longitudinal                       Longitudinal;                  /*!< Longitudinal motion variables  */
    VDY_INTERFACES_Lateral                            Lateral;                       /*!< Lateral motion variables  */
    MotionStateVehDyn_t                               MotionState;                   /*!< Motion State  */
} VehDyn_t;           /* @versionstr: VDY_VEH_DYN_INTFVER */

/*! @brief Main Vehicle dynacmis sensor signals */
typedef struct
{
    float32                                           YawRate;                       /*!< VDY_SIN_POS_YWR, Unit: [rad/s], Range:[-150*pi/180..150*pi/180]  */
    AlgoDataTimeStamp_t                               YawRateTimeStamp;              /*!< Time stamp for YawRate  */
    float32                                           YawRateTemp;                   /*!< VDY_SIN_POS_YWR_TEMP, Unit: [degC]  */
    float32                                           StWheelAngle;                  /*!< VDY_SIN_POS_SWA, Unit: [rad], Range:[-90*pi/180*SWRatio..90*pi/180*SWRatio]  */
    AlgoDataTimeStamp_t                               StWheelAngleTimeStamp;         /*!< Time stamp for StWheelAngle  */
    float32                                           LatAccel;                      /*!< VDY_SIN_POS_LATA, Unit: [m/s^2], Range:[-15..15]  */
    AlgoDataTimeStamp_t                               LatAccelTimeStamp;             /*!< Time Stamp for LatAccel  */
    float32                                           WhlVelFrLeft;                  /*!< VDY_SIN_POS_WVEL_FL, Unit: [m/s], Range:[0..115]  */
    AlgoDataTimeStamp_t                               WhlVelFrLeftTimeStamp;         /*!< Time Stamp for WhlVelFrLeft  */
    float32                                           WhlVelFrRight;                 /*!< VDY_SIN_POS_WVEL_FR, Unit: [m/s], Range:[0..115]  */
    AlgoDataTimeStamp_t                               WhlVelFrRightTimeStamp;        /*!< Time Stamp for WhlVelFrRight  */
    float32                                           WhlVelReLeft;                  /*!< VDY_SIN_POS_WVEL_RL, Unit: [m/s], Range:[0..115]  */
    AlgoDataTimeStamp_t                               WhlVelReLeftTimeStamp;         /*!< Time Stamp for WhlVelReLeft  */
    float32                                           WhlVelReRight;                 /*!< VDY_SIN_POS_WVEL_RR, Unit: [m/s], Range:[0..115]  */
    AlgoDataTimeStamp_t                               WhlVelReRightTimeStamp;        /*!< Time Stamp for WhlVelReRight  */
    float32                                           YawRateInt;                    /*!< VDY_SIN_POS_YWRINT, Unit: [rad/s], Range:[-2.86..+2.86]  */
    float32                                           YawRateIntTemp;                /*!< VDY_SIN_POS_YWRINT_TEMP, Unit: [degC], Range:[-2.86..+2.86]  */
    float32                                           LongAccel;                     /*!< VDY_SIN_POS_LONGA, Unit: [m/s^2], Range:[-15..15]  */
    float32                                           RearWhlAngle;                  /*!< VDY_SIN_POS_RSTA: - Rear-wheel-angle coded and OK: Value = <value from bus> VDY-state = VALID;  - Rear-wheel-angle coded and not OK (out of range…): value = 0 VDY-state = INVALID; -	Rear-wheel-angle not coded and not available at all: value = 0 VDY-state = INIT, Unit: [rad]  */
    float32                                           VehVelocityExt;                /*!< VDY_SIN_POS_VEHVEL_EXT, Unit: [m/s], Range:[0..115]  */
    AlgoDataTimeStamp_t                               VehVelocityExtTimeStamp;       /*!< Time Stamp for VehVelocityExt  */
    float32                                           VehLongAccelExt;               /*!< VDY_SIN_POS_VEHACL_EXT, Unit: [m/s^2], Range:[-15..15]  */
    AlgoDataTimeStamp_t                               VehLongAccelExtTimeStamp;      /*!< Time Stamp for VehLongAccelExt  */
    uint8                                             WhlTicksDevFrLeft;             /*!< VDY_SIN_POS_WTCKS_FL number of pulses after last VDY call  */
    AlgoDataTimeStamp_t                               WhlTicksDevFrLeftTimeStamp;    /*!< Time Stamp for WhlTicksDevFrLeft  */
    uint8                                             WhlTicksDevFrRight;            /*!< VDY_SIN_POS_WTCKS_FR number of pulses after last VDY call  */
    AlgoDataTimeStamp_t                               WhlTicksDevFrRightTimeStamp;   /*!< Time Stamp for WhlTicksDevFrRight  */
    uint8                                             WhlTicksDevReLeft;             /*!< VDY_SIN_POS_WTCKS_RL number of pulses after last VDY call  */
    AlgoDataTimeStamp_t                               WhlTicksDevReLeftTimeStamp;    /*!< Time Stamp for WhlTicksDevReLeft  */
    uint8                                             WhlTicksDevReRight;            /*!< VDY_SIN_POS_WTCKS_RR number of pulses after last VDY call  */
    AlgoDataTimeStamp_t                               WhlTicksDevReRightTimeStamp;   /*!< Time Stamp for WhlTicksDevReRight  */
    VDY_INTERFACES_ActGearPos                         ActGearPos;                    /*!< VDY_SIN_POS_GEAR,Accuracy: 1.0, Unit: [Enum],List:ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_REVERSE=3  */
    uint16                                            BrakeActLevel;                 /*!< VDY_SIN_POS_BRAKE, Unit: [Nm]  */
    VDY_INTERFACES_ParkBrakeState                     ParkBrakeState;                /*!< VDY_SIN_POS_PBRK,Accuracy: 1.0, Unit: [Enum],List:STAT_INACTIVE=0,STAT_ACTIVE=1  */
    VDY_INTERFACES_VehLongMotStateExt                 VehLongMotStateExt;            /*!< VDY_SIN_POS_VMOT,Accuracy: 1.0, Unit: [Enum],List:VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_FAST_STST=1,VDY_VEH_MOT_STATE_SECURE_STST=2  */
    float32                                           CurveC0Ext;                    /*!< VDY_SIN_POS_CRV, Unit: [1/m]  */
    float32                                           CurveC1Ext;                    /*!< VDY_SIN_POS_SSA  */
    float32                                           SideSlipAngleExt;              /*!< VDY_SIN_SIZE_DW, Unit: [rad]  */
} VDY_INTERFACES_VehSigMain;
/*! @brief Height level of each wheel */
typedef struct
{
    sint16                                            FrontLeft;                     /*!< Height adjustment value for front left wheel  */
    sint16                                            FrontRight;                    /*!< Height adjustment value for front right wheel  */
    sint16                                            RearLeft;                      /*!< Height adjustment value for rear left wheel  */
    sint16                                            RearRight;                     /*!< Height adjustment value for rear right wheel  */
} VDY_INTERFACES_WheelHeightLevel;
/*! @brief Additional Vehicle dynacmis sensor signals */
typedef struct
{
    float32                                           EnvTemp;                       /*!< Ambient environmental temperature, Unit: [degC]  */
    VDY_INTERFACES_WiperState                         WiperState;                    /*!< Wiper blades activity,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,VEH_SIG_ADD_WIPER_STATE_ACTIVE=1  */
    VDY_INTERFACES_WiperStage                         WiperStage;                    /*!< Wiper switch position,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6  */
    boolean                                           WiperOutParkPos;               /*!< Wiper outside park position,Accuracy: 1.0, Range:[0..1]  */
    VDY_INTERFACES_WiperWasherFrontState              WiperWasherFrontState;         /*!< Tip-wipe / washer state,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_WWS_IDLE=0,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_WASH=2  */
    boolean                                           RainSensor;                    /*!< True if rain sensor reports rain,Accuracy: 1.0, Range:[0..1]  */
    VDY_INTERFACES_TurnSignal                         TurnSignal;                    /*!< Turn signal switch state,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_BOTH=4  */
    boolean                                           FogLampFront;                  /*!< Fog lamps front active,Accuracy: 1.0, Range:[0..1]  */
    boolean                                           FogLampRear;                   /*!< Fog lamps rear active,Accuracy: 1.0, Range:[0..1]  */
    float32                                           RoadWhlAngFr;                  /*!< Steering angle (road wheel) at front axle, Unit: [rad], Range:[-25..+25]  */
    float32                                           RoadWhlAngRe;                  /*!< Steering angle (road wheel) at rear axle, Unit: [rad], Range:[-25..+25]  */
    float32                                           Odometer;                      /*!< Total driven distance, Unit: [m]  */
    float32                                           GasPedalPos;                   /*!< gas pedal position percentage, Unit: [%], Range:[0..100]  */
    boolean                                           KickDown;                      /*!< BOOL Kick Down information,Accuracy: 1.0, Range:[0..1]  */
    boolean                                           BrakePedalPressed;             /*!< BOOL brake pedal pressed,Accuracy: 1.0, Range:[0..1]  */
    boolean                                           DriverTired;                   /*!< BOOL Driver Tired Active,Accuracy: 1.0, Range:[0..1]  */
    VDY_INTERFACES_SpeedUnit                          SpeedUnit;                     /*!< ENUM speedmeter speed unit,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,VEH_SIG_ADD_SPEEDO_UNIT_MPH=2  */
    float32                                           SpeedoSpeed;                   /*!< ego velocity speedo speed, Unit: [km/h]  */
    uint8                                             TrailerLengthInput;            /*!< Length of attached trailer, received from driver input, Range:[0..+255]  */
    uint8                                             ParkAidDet_L;                  /*!< Detection Distance of Rear Left Park Aid Sensor (US), Unit: [m], Range:[0..+15]  */
    uint8                                             ParkAidDet_CL;                 /*!< Detection Distance of Rear Center Left Park Aid Sensor (US), Unit: [m], Range:[0..+15]  */
    uint8                                             ParkAidDet_CR;                 /*!< Detection Distance of Rear Center Right Park Aid Sensor (US), Unit: [m], Range:[0..+15]  */
    uint8                                             ParkAidDet_R;                  /*!< Detection Distance of Rear Right Park Aid Sensor (US), Unit: [m], Range:[0..+15]  */
    VDY_INTERFACES_IgnitionSwitch                     IgnitionSwitch;                /*!< Ignition lock, Ignition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50),Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5  */
    VDY_INTERFACES_eSuspensionSystem                  eSuspensionSystem;             /*!< Availability of active suspension: 0: no active suspension available 1: active suspension available,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_NO_ACTIVE_SUSPENSION=0,VEH_SIG_ADD_ACTIVE_SUSPENSION=1  */
    VDY_INTERFACES_eHeightLevel                       eHeightLevel;                  /*!< Height adjustment value the car: 0: no height level available 1: height level normal 2: height level low 3: height level high,Accuracy: 1.0, Unit: [Enum],List:VEH_SIG_ADD_NO_HEIGHT_LVL=0,VEH_SIG_ADD_HEIGHT_LVL_NORMAL=1,VEH_SIG_ADD_HEIGHT_LVL_LOW=2,VEH_SIG_ADD_HEIGHT_LVL_HIGH=4  */
    boolean                                           seatBeltReminderActive;        /*!< Status of the seat belt reminder,Accuracy: 1.0, Range:[0..1]  */
    VDY_INTERFACES_WheelHeightLevel                   WheelHeightLevel;              /*!< Height level of each wheel  */
    VDY_INTERFACES_ExternalCamBlockageDetection       ExternalCamBlockageDetection;  /*!< result type for blockage detection from external camera, in case it is available,Accuracy: 1.0, Unit: [Enum],List:EXT_CAM_BLOCKAGE_UNKOWN=0,EXT_CAM_BLOCKAGE_DETECTED=1,EXT_CAM_BLOCKAGE_NOT_DETECTED=2  */
    uint8                                             AlignmentByte1;                /*!< Force alignment of PowerTrain to 4 Byte adress  */
    sint16                                            AlignmentByte2;                /*!< Force alignment of PowerTrain to 4 Byte adress  */
} VDY_INTERFACES_VehSigAdd;
typedef struct
{
    TransmissionGear_t                                ActualGear;                    /*!< Indicates current used gear position,Accuracy: 1.0, Unit: [Enum],List:DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_FOURTH_GEAR=4,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_PARK_GEAR=11,DYN_GEAR_POWER_FREE=12,DYN_GEAR_POWER_INVALID=255  */
    TransmissionGear_t                                TargetGear;                    /*!< When a gear shift is in progress, this shows the targeted gear, otherwise it is equal to the Actual Gear  */
    boolean                                           EngineRunning;                 /*!< Indicates if engine running, needed for activation of ACC,Accuracy: 1.0, Range:[0..1]  */
    uint8                                             FillByte;                      /*!< Byte to align VehSig.Powertrain structure  */
} VDY_INTERFACES_PowerTrain;
/*! @brief Sensor specific parameters */
typedef struct
{
    boolean                                           ABSCtrl;                       /*!< Attenuation of secondary surface (two-way) (0: inactive, 1: active),Accuracy: 1.0, Range:[0..1]  */
    boolean                                           TCSCtrl;                       /*!< Traction Control Activity (0: inactive, 1: active),Accuracy: 1.0, Range:[0..1]  */
} VDY_INTERFACES_Brake;
/*! @brief Main Vehicle dynacmis sensor signals */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Number of used Version  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< Contains time stamp, frame stamp, etc.  */
    VDY_INTERFACES_VehSigMain                         VehSigMain;                    /*!< Main Vehicle dynacmis sensor signals  */
    VDY_INTERFACES_VehSigAdd                          VehSigAdd;                     /*!< Additional Vehicle dynacmis sensor signals  */
    VDY_INTERFACES_PowerTrain                         PowerTrain;
    VDY_INTERFACES_Brake                              Brake;                         /*!< Sensor specific parameters  */
} VDY_INTERFACES_VehSig;           /* @versionstr: BSW_VEH_SIG_INTFVER */

/*! @brief Vehicle main parameters */
typedef struct
{
    float32                                           SelfSteerGrad;                 /*!< Rate of change in steering wheel angle with respect to change in steady-state lateral acceleration., Range:[-128..+128]  */
    StRatio_t                                         SteeringRatio;                 /*!< Rate of change of steering wheel angle at given steering wheel trim position, with respect to change in average steer angel of a pair of steered wheels. In case of active steering systems this parameter is dependent additional vehicle states  */
    float32                                           WheelBase;                     /*!< Longitudinal distance between the center of tire contact of pair of wheels on same vehicle side, Unit: [m], Range:[0..+10]  */
    float32                                           TrackWidthFront;               /*!< Lateral distance between the center of tire contact of pair of wheels on front vehicle axle, Unit: [m], Range:[+1.0..+5.0]  */
    float32                                           TrackWidthRear;                /*!< Lateral distance between the center of tire contact of pair of wheels on rear vehicle axle, Unit: [m], Range:[+1.0..+5.0]  */
    float32                                           VehWeight;                     /*!< Vehicle weight, Unit: [kg], Range:[+1.0..60000.0]  */
} VDY_INTERFACES_VehParMain;
/*! @brief Static Vehicle parameters all values are vehicle dependent, therefore no default values are given */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Number of used Version  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< - Contains time stamp, frame stamp, etc. - In addition to the eSigStatus each signal has its own state. Therefore, both the eSigStatus and the State has to be checked before a signal is used  */
    VDY_INTERFACES_VehParMain                         VehParMain;                    /*!< Vehicle main parameters  */
} VDY_INTERFACES_VehPar;           /* @versionstr: BSW_VEH_PAR_INTFVER */

/*! @brief Table for base steering ratio in dependence of steering wheel angle */
typedef struct
{
    float32                                           ang[2];                        /*!< Abscissa: Steering wheel angle sample points, Unit: [rad]  */
    float32                                           rat[2];                        /*!< Ordinate: Base ratio sample points, Range:[+1.0..+30.0]  */
} VDY_INTERFACES_swa;
/*! @brief Table for additional steering ratio part in dependence of velocity */
typedef struct
{
    float32                                           vel[2];                        /*!< Ordinate: Additional ratio by super-imposed steering, Unit: [m/s]  */
    float32                                           rat[2];                        /*!< Abscissa: Vehicle velocity sample points  */
    float32                                           FrCrnrStiff;                   /*!< The rate of change of lateral force with respect to change in side slip angle at front axle, Range:[-25..+25]  */
} VDY_INTERFACES_vel;
/*! @brief Steering ratio */
typedef struct
{
    VDY_INTERFACES_swa                                swa;                           /*!< Table for base steering ratio in dependence of steering wheel angle  */
    VDY_INTERFACES_vel                                vel;                           /*!< Table for additional steering ratio part in dependence of velocity  */
    float32                                           ReCrnrStiff;                   /*!< The rate of change of lateral force with respect to change in side slip angle at rear axle, Range:[-25..+25]  */
} StRatio_t;

/*! @brief Vehicle additional parameters */
typedef struct
{
    float32                                           VehicleWidth;                  /*!< Vehicle width, Unit: [m]  */
    float32                                           VehicleLength;                 /*!< Vehicle length, Unit: [m]  */
    float32                                           CurbWeight;                    /*!< The weight of a fueled automobile with standard equipment but without cargo or passengers, Unit: [kg], Range:[+100..+65000]  */
    float32                                           OverhangFront;                 /*!< Longitudinal distance from the center of front axle group to the front most point, Unit: [m], Range:[0.0..+5.0]  */
    float32                                           FrontAxleRoadDist;             /*!< Distance from front Axle to Road, Unit: [m], Range:[0.0..+5.0]  */
    float32                                           WheelWidth;                    /*!< Width of the Wheel, Unit: [m], Range:[0.0..+5.0]  */
    float32                                           PassableHeight;                /*!< Minimum height be passable by the vehicle. Example: 1.5m means that only underpassings of less than 1.5m are declared to be a freespace limit., Unit: [m]  */
    float32                                           DistCameraToHoodX;             /*!< Longitudinal distance from camera to highest point of the hood that is visible from the camera point of view. Value is used to mask out measurements coming from the ego car hood., Unit: [m]  */
    float32                                           DistCameraToHoodY;             /*!< Vertical distance from camera to highest point of the hood that is visible from the camera point of view. Value is used to mask out measurements coming from the ego car hood., Unit: [m]  */
    VDY_INTERFACES_SteeringVariant                    SteeringVariant;               /*!< Mounting position of steering wheel (in driving direction),Accuracy: 1.0, Unit: [Enum],List:VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2  */
} VDY_INTERFACES_VehParAdd;

/*! @brief Sensor mounting geometry */
typedef struct
{
    float32                                           LatPos;                        /*!< Lateral displacment related to middle of vehicle (+ left), Unit: [m], Range:[-25..+25]  */
    float32                                           LongPos;                       /*!< Longitudinal displacment related to front axle (+ fwd), Unit: [m], Range:[-25..+25]  */
    float32                                           VertPos;                       /*!< Vertical displacemnt (height) over ground. Accuracy of input value must be +-0.03m (including all sources of error, e.g. adaptive suspension), Unit: [m], Range:[-25..+25]  */
    float32                                           LongPosToCoG;                  /*!< Longitudinal displacment related to vehicle center of gravity (+ fwd), Unit: [m], Range:[1..4]  */
    float32                                           PitchAngle;                    /*!< Angular displacement around vehicle lateral axis (+ down) (second rotation), Unit: [rad], Range:[-3.14..3.14]  */
    VDY_INTERFACES_Orientation                        Orientation;                   /*!< Angular displacement around sensor longitudinal axis,Accuracy: 1.0, Unit: [Enum],List:SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1  */
    float32                                           RollAngle;                     /*!< Angular displacement around sensor longitudinal axis (first rotation), Unit: [rad], Range:[-3.14..3.14]  */
    float32                                           YawAngle;                      /*!< Angular displacemnt around vehicle vertical axis (last rotation), Unit: [rad], Range:[-3.14..3.15]  */
} VDY_INTERFACES_SensorMounting;

/*! @brief Sensor specific parameters */
typedef struct
{
    float32                                           CoverDamping;                  /*!< Attenuation of secondary surface (two-way) in dB, Unit: [dB], Range:[0..+3]  */
    float32                                           fCoverageAngle;                /*!< shall not be used any longer, coverage angle has to be taken from the PPARs, Range:[-25..+25]  */
    float32                                           fLobeAngle;                    /*!< shall not be used any longer, lobe angle has to be taken from the PPARs, Range:[-25..+25]  */
    float32                                           fCycleTime;                    /*!< shall not be used any longer, differences of time stamps in the corresponding ports shall be used instead, Unit: [s], Range:[0.0..100.0]  */
    uint8                                             uNoOfScans;                    /*!< shall not be used any longer, the RTE define SYS_NOF_SCANS shall be used instead, Range:[1..2]  */
} VDY_INTERFACES_Sensor;

/*! @brief Yaw rate offset result */
typedef struct
{
    fYawRate_t                                        StandStillOffset;              /*!< Stand still Yaw rate offset  */
    sint32                                            StandStillState;               /*!< Stand still Yaw rate offset state  */
    fYawRate_t                                        DynOffset;                     /*!< Dynamic Yaw rate offset  */
    fVariance_t                                       DynVariance;                   /*!< Dynamic Yaw rate offset Variance  */
} VDY_INTERFACES_Ywr;
/*! @brief Steering wheel angle offset result */
typedef struct
{
    fAngle_t                                          Offset;                        /*!< Steering wheel angle offset  */
    fVariance_t                                       Variance;                      /*!< Steering wheel angle offset variance  */
    sint32                                            State;                         /*!< Steering wheel angle offset state  */
} VDY_INTERFACES_Swa;
/*! @brief Lat accel offset result */
typedef struct
{
    fAngle_t                                          Offset;                        /*!< Steering wheel angle offset  */
    fVariance_t                                       Variance;                      /*!< Steering wheel angle offset variance  */
    sint32                                            State;                         /*!< Steering wheel angle offset state  */
} VDY_INTERFACES_Ay;
/*! @brief The offsets of the vdy input signals like yaw rate */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Number of used Version  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< Contains time stamp, frame stamp, etc.  */
    VDY_INTERFACES_Ywr                                Ywr;                           /*!< Yaw rate offset result  */
    VDY_INTERFACES_Swa                                Swa;                           /*!< Steering wheel angle offset result  */
    VDY_INTERFACES_Ay                                 Ay;                            /*!< Lat accel offset result  */
} VDY_INTERFACES_VDYOffsets;           /* @versionstr: VDY_OFFSETS_INTFVER */

/*! @brief Signal input errors */
typedef struct
{
} VDY_INTERFACES_SignalInputErrors;
/*! @brief Parameter input errors */
typedef struct
{
} VDY_INTERFACES_ParInputErrors;
/*! @brief Output values and internalal errors */
typedef struct
{
} VDY_INTERFACES_OutPutErrors;
/*! @brief The vdy errors input signals/parameters Output errors, internal errors, */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Number of used Version  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< information for synchronisation of SIL simulation  */
    VDY_INTERFACES_SignalInputErrors                  SignalInputErrors;             /*!< Signal input errors  */
    VDY_INTERFACES_ParInputErrors                     ParInputErrors;                /*!< Parameter input errors  */
    VDY_INTERFACES_OutPutErrors                       OutPutErrors;                  /*!< Output values and internalal errors  */
} VDY_INTERFACES_VDYErrors;           /* @versionstr: VDY_ERRORS_INTFVER */

/*! @brief Steering wheel angle zero point offset estimation */
typedef struct
{
    fAngle_t                                          ZeroAngle;                     /*!< Steering wheel angle zero point offset value  */
    uint32                                            CalStatus;                     /*!< Steering wheel angle zero point offset status  */
} VDYNvStWhlAngCal_t;
/*! @brief Understeer / Oversteer gradient estimation */
typedef struct
{
    float32                                           SlfStGrad;                     /*!< Understeer / Oversteer gradient value  */
    uint8                                             SlfStGradMax;                  /*!< Understeer / Oversteer gradient max value  */
    uint8                                             SlfStGradMin;                  /*!< Understeer / Oversteer gradient min value  */
    sint8                                             CalStatus;                     /*!< Understeer / Oversteer gradient status  */
    uint8                                             Dummy;                         /*!< Understeer / Oversteer gradient Dummy  */
} VDYNvSlfStGradCal_t;
/*! @brief Yaw rate zero point offset value */
typedef struct
{
    fYawRate_t                                        ZeroRate;                      /*!< Yaw rate zero point offset value  */
    fYawRate_t                                        ZeroRateMin;                   /*!< Yaw rate zero point for minimum detection  */
    fYawRate_t                                        ZeroRateMax;                   /*!< Yaw rate zero point for maximum detection  */
    uint32                                            CalStatus;                     /*!< Yaw rate zero point offset status  */
} VDY_INTERFACES_YwRate;
/*! @brief Lateral accleration zero point offset estimation */
typedef struct
{
    fAccel_t                                          ZeroAccel;                     /*!< Lateral accleration zero point offset value  */
    uint32                                            CalStatus;                     /*!< Lateral accleration zero point offset status  */
} VDY_INTERFACES_LatAcc;
/*! @brief Longitudinal velocity correction */
typedef struct
{
    fRatio_t                                          CorrFact;                      /*!< Corrections factors  */
    fVelocity_t                                       Velo;                          /*!< Velocity of this hist  */
    float32                                           Dev;                           /*!< Confidence of correction factors  */
} VDY_INTERFACES_VelCorr;
/*! @brief Wheel load dependency */
typedef struct
{
    float32                                           Wld_front;                     /*!< Wheel load dependency front axis  */
    float32                                           Wld_rear;                      /*!< Wheel load dependency rear axis  */
    uint8                                             Wld_front_quality;             /*!< Wheel load dependency quality front axis  */
    uint8                                             Wld_rear_quality;              /*!< Wheel load dependency quality rear axis  */
} VDYNvWldCal_t;
/*! @brief The vdy nvm input and output data stuct */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Number of used Version  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< information for synchronisation of SIL simulation  */
    VDYNvStWhlAngCal_t                                StWhlAng;                      /*!< Steering wheel angle zero point offset estimation  */
    VDYNvSlfStGradCal_t                               SlfstGrad;                     /*!< Understeer / Oversteer gradient estimation  */
    VDY_INTERFACES_YwRate                             YwRate;                        /*!< Yaw rate zero point offset value  */
    VDY_INTERFACES_LatAcc                             LatAcc;                        /*!< Lateral accleration zero point offset estimation  */
    VDY_INTERFACES_VelCorr                            VelCorr[3];                    /*!< Longitudinal velocity correction  */
    VDYNvWldCal_t                                     Wld;                           /*!< Wheel load dependency  */
} VDY_INTERFACES_VDYNvIoData;           /* @versionstr: VDY_NVM_IO_DATA_INTFVER */

/*! @brief Wheel speed curve all axles */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} WhlCurve_t;
/*! @brief Wheel speed curve front axle */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} WhlFrCurve_t;
/*! @brief Wheel speed curve rear axle */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} WhlReCurve_t;
/*! @brief Yaw rate sensor curve */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} YwRateCurve_t;
/*! @brief Lateral acceleration curve */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} AyCurve_t;
/*! @brief Steering angle yaw rate curve */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} SwaCurve_t;
/*! @brief Steering wheel angle curve */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} DrvIntCurve_t;
/*! @brief Vehicle yaw rate curve */
typedef struct
{
    fCurve_t                                          Curve;                         /*!< Curve  */
} VehYawCurve_t;
/*! @brief The vdy estimated curves */
typedef struct
{
    AlgoInterfaceVersionNumber_t                      uiVersionNumber;               /*!< Number of used Version  */
    BASE_INTERFACES_SignalHeader_t                    sSigHeader;                    /*!< information for synchronisation of SIL simulation  */
    WhlCurve_t                                        Whl;                           /*!< Wheel speed curve all axles  */
    WhlFrCurve_t                                      WhlFr;                         /*!< Wheel speed curve front axle  */
    WhlReCurve_t                                      WhlRe;                         /*!< Wheel speed curve rear axle  */
    YwRateCurve_t                                     YwRate;                        /*!< Yaw rate sensor curve  */
    AyCurve_t                                         Ay;                            /*!< Lateral acceleration curve  */
    SwaCurve_t                                        Swa;                           /*!< Steering angle yaw rate curve  */
    DrvIntCurve_t                                     DrvInt;                        /*!< Steering wheel angle curve  */
    VehYawCurve_t                                     VehYaw;                        /*!< Vehicle yaw rate curve  */
} VDY_INTERFACES_VDYEstCurves;           /* @versionstr: VDY_EST_CURVES_INTFVER */


#ifdef __cplusplus
}
#endif

#endif /* #if (GA_CFG_VDY_INTERFACES == 1) */

/*! @} end defgroup */

#endif /* #ifndef GA_VDY_INTERFACES_EXT_H_INCLUDED */
