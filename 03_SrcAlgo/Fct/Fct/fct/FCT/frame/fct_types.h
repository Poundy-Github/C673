/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_types.h

DESCRIPTION:               FCT types

AUTHOR:                    Gergely Ungvary

CREATION DATE:             11.09.2007

VERSION:                   $Revision: 1.54 $

LEGACY VERSION:            Revision: 1.27

**************************************************************************** */
#ifndef FCT_TYPES_H
#define FCT_TYPES_H

#include "fct_config.h"
#include "fct_ver.h"

#ifndef FCT_MEAS_ID_SLATE_ERRORDATA
#define FCT_MEAS_ID_SLATE_ERRORDATA          (0x205400D8u)
#endif
/**
@addtogroup frame
@{ */

#ifndef GA_assert
/* Copy of GA assert from GA_common.h. To be removed when global architecture is used */

/* ---- macro definitions -------------------------------------------------- */

/* Deactivate QA-C warning 3412; Reviewer: A. Schlensag; 
   Date: 28.11.2016;
   Reason: This macro shall only avoid compilation when static mem is insufficient
*/
/* PRQA S 3412 MACRO */
#define GA_ASSERT_CONCAT_(a, b)     a##b
#define GA_ASSERT_CONCAT(a, b)      GA_ASSERT_CONCAT_(a, b)
#define GA_assert(e)                enum { GA_ASSERT_CONCAT(assert_line_, __LINE__) = 1/(sint32)(!!(e)) }
/* PRQA L:MACRO */
#endif

#if (FCT_CFG_SENSOR_TYPE_CAMERA)

typedef sint32  sbit32_t;
typedef sint16  sbit16_t;
typedef sint8   sbit8_t;
typedef ubit32  ubit32_t;
typedef uint16  ubit16_t;
typedef uint8   ubit8_t;

#endif /*(FCT_CFG_SENSOR_TYPE_CAMERA)*/


#ifndef ALGO_INLINE
/* Defines for inlining functions*/ 
#if defined(_MSC_VER) /* Microsoft compiler -> code only for simulation */
/*! microsoft compliler -> simulation*/
#define ALGO_INLINE  __inline
#elif (defined(__POWERPC__) && defined(__MWERKS__))               /* Freescale Metrowerks compiler for PowerPC-ECUs -> code only for ECU */
/*! Freescale compiler use inline*/
#define ALGO_INLINE  inline
#elif (defined(__ghs__))                                          /* Greenhills compiler */
/*! Greenhills compoiler use inline*/
#define ALGO_INLINE inline
#elif (defined(__ARP32__)) || (defined(__TI_ARM__)) || (defined(_TMS320C6X))
/*! TI compiler use inline*/
#define ALGO_INLINE inline
#elif (defined(__GNUC__))
/*! GNU compiler use inline*/
#define ALGO_INLINE inline
#elif (defined(__ARMCC_VERSION))                                  /* ARMCLANG Compiler */
/*! ARM compiler use static inline*/
#define ALGO_INLINE static inline
#elif (defined(__STDC_VERSION__))
#if (__STDC_VERSION__ >= 199901) /* C99 compatible compiler has to have inline keyword with proper non-extern linkage */
/*! C99 compiler use inline*/
#define ALGO_INLINE inline
#else
#define ALGO_INLINE static
#endif
#else  /* unknown compiler -> no INLINE */
/*! unknown compiler NO inlining*/
#define ALGO_INLINE static
#endif
#endif


/* *************************************************************************************************** */
/* *************************************************************************************************** */
/* TEVES TYPES                      */
/* The use of the following types are limited to    */
/* software components which have to run on A.D.C.      */
/* MCU's and TEVES MCU's                                */
/* DO NOT USE (MIX) BOTH STYLES IN ONE COMPONENT        */
/*! TEVES STYLE: Limited to components which have to run on A.D.C. MCU's and TEVES MCU's */
/* *************************************************************************************************** */
/*         define the FCT_OP_MODE_t and its relevant enum, if the FCTCtrlData_t is not defined Rte
   Reason: The BaseOpMode_t is mapped internally to FCT_OP_MODE_t, which is used inside FCT.
           Thus, the FCT_OP_MODE_t has to be available also in projects which use only BaseOpMode_t */
#ifndef FCT_CTRL_DATA_INTFVER 

/* typedef FCT_OP_MODE_t */
typedef uint8 FCT_OP_MODE_t;

#define FCT_CTRL_DATA_INTFVER (1)

#ifndef   FCT_MOD_STARTUP
#define FCT_MOD_STARTUP       (0)
#endif
#ifndef   FCT_MOD_INIT
#define FCT_MOD_INIT          (1)
#endif
#ifndef   FCT_MOD_RUNNING
#define FCT_MOD_RUNNING       (2)
#endif
#ifndef   FCT_MOD_SHUTDOWN
#define FCT_MOD_SHUTDOWN      (3)
#endif
#ifndef   FCT_MOD_PAUSE
#define FCT_MOD_PAUSE         (4)
#endif

#endif /* #ifndef FCT_CTRL_DATA_INTFVER  */

/* TYPEDEFS (GLOBAL) */
/* Old typedefs signed_char_t, unsigned_char_t, signed_int8_t, unsigned_int8_t etc.
have been removed as replaced by standard Autosar types */

/* DATA DICTIONARY */
/*! alias to scale 1e6*/
#define Scale_1000000 (1000000)
/*! alias to scale 1e5*/
#define Scale_100000  (100000)
/*! alias to scale 1e4*/
#define Scale_10000   (10000)
/*! alias to scale 1e3*/
#define Scale_1000    (1000)
/*! alias to scale 1e2*/
#define Scale_100     (100)
/*! alias to scale 1e1*/
#define Scale_10      (10)
/*! alias to scale 1e0*/
#define Scale_1       (1)


/*! Acceleration
@description   Acceleration, speed, increase left positive.
@resolution    0.001
@unit          [m/(s*s)]
@min           -32.767
@max           32.766    
@todo          20150615CO: is this still needed; no typedefinition where boundaries are defined*/
/*! scale for Acceleration_t */
#define Acceleration_s Scale_1000
/*! minimum for Acceleration_t */
#define Accel_min (-32767)
/*! maximum for Acceleration_t */
#define Accel_max ( 32766)

/*! Gradient
@description   Change rate (d/dt) of signal. Attention, gradient is scaled same as signal it is derived from:
@resolution    0.001  
@unit          [?/s]
@min           -2147483.648  
@max           +2147483.647 */
typedef sint32 gradient_t;     /*%scale:0.001 unit:x/s*/

/*! velocity
@description   velocity, forward / left positive
@resolution:   0.01    @unit: [m/s]
@min           -327.67
@max           327.66
@todo          20150615CO: is this still needed; no typedefinition where boundaries are defined*/
/*! scale for velocity_t */
#define Velocity_s Scale_100
/*! minimum for velocity_t */
#define Velocity_min (-32767)
/*! maximum for velocity_t */
#define Velocity_max ( 32766)

/*! speed
@description   number of revolutions per time unit, forward / left positive
@resolution    0.01
@unit          [1/s]
@min           -327.67
@max           327.66    */
typedef sint16 speed_t; /*%scale:0.01 unit:1/s*/
/*! scale for speed_t */
#define Speed_s Scale_100
/*! minimum for speed_t */
#define Speed_min (-32767)
/*! maximum for speed_t */
#define Speed_max ( 32766)

/*! SpeedometerSpeed
@description    Vehicle speed displayed by speedometer
@resolution    0.01
@unit          [Km/h | Mph]
@min           -327.67
@max           32.766    */
typedef sint16 speedometer_speed_t; /*%scale:0.01 unit:km/h|mph*/
/*! scale for speedometer_speed_t */
#define Speedo_speed_s Scale_100
/*! minimum for speedometer_speed_t */
#define Speedo_speed_min (-32767)
/*! maximum for speedometer_speed_t */
#define Speedo_speed_max (32766)

/*! Factor
@description    Factor
@resolution    0.001
@unit          [-]
@min           -32.767
@max           32.766
@todo          20150615CO: is this still needed; no typedefinition where boundaries are defined*/
//typedef sint16         factor_t;    /*%scale:0.001*/
/*! scale for factor_t */
#define Factor_s Scale_1000
/*! minimum for factor_t */
/*! Speed_conv_factor_xxx as opposed to what one would assume, these are not
scaled by the factor of 'Speed_s', but rather based on code make the assumption
that it is scaled by 'Factor_s'. Highly misleading, but as this seems to have
been always this way, left as is */
/*! @brief      Speed_conv_factor_kmh  */
#ifndef Speed_conv_factor_mph
#define Speed_conv_factor_mph ((factor_t)2237)
#endif
#ifndef Speed_conv_factor_kmh
/*! @brief      Speed_conv_factor_kmh  */
#define Speed_conv_factor_kmh ((factor_t)3600)
#endif

/*! Time
@description   Time
@resolution    0.001
@unit          [s]
@min           0
@max           65.534
@todo          20150615CO: times_t is definded in RTE, how to make sure boundaries are defined properly*/
/*! scale for times_t */
#define Time_s Scale_1000
/*! minimum for times_t */
#define Time_min (0u)
/*! maximum for times_t */
#define Time_max (65535u)

/*! SetSpeed
@description    Driver selected speed
@resolution    1
@unit          [Km/h | Mph]
@min           0
@max           255
@todo          20150615CO: is this still needed, no code impact*/
typedef uint8 setspeed_t;  /*%unit:km/h|mph*/
/*! scale for setspeed_t */
#define Setspeed_s Scale_1

/*! SetSpeed16
@description    Driver selected speed
@resolution    0.01
@unit          [Km/h | Mph]
@min           0
@max           65534 */
typedef uint16 cc_setspeed16_t;
/*! scale for setspeed16_t */
#define Setspeed16_s Scale_100

/*! WheelImpulseCounter
@description    Number of impulses from wheel speed sensor since last overflow
@resolution    1
@unit          [-]
@min           0
@max           255
@todo          20150615CO: is this still needed, no code impact*/
typedef uint8 wheel_impulse_counter_t;
/*! scale for wheel_impulse_counter_t */
#define Wheel_impulse_s Scale_1

/*! Length
@description   length
@resolution    0.001    @unit: [m]
@min           0
@max           65.534
@todo          20150615CO: is this still needed, no code impact*/
typedef uint16 length_t;  /*%scale:0.001 unit:m*/
/*! scale for length_t */
#define Length_s Scale_1000

/*! Radius
@description   radius
@resolution    1
@unit          [m]
@min           -32767
@max           +32766
@todo          20150615CO: is this still needed, no code impact*/
typedef sint16 curve_radius_t;  /*%unit:m*/
/*! scale for curve_radius_t */
#define Curve_radius_s Scale_1

/*! Distance
@description    Distance, left / forward positive
@resolution    0.01
@unit          [m]
@min           -327.67
@max           327.66
@todo          20150615CO: is this still needed, no code impact*/
//typedef sint16 distance_t;    /*%scale:0.01 unit:m*/
/*! scale for distance_t */
#define Distance_s Scale_100
/*! minimum for distance_t */
#define Distance_min (-32767)
/*! maximum for distance_t */
#define Distance_max (32766)

/*! Torque
@description   Torque
@resolution    1
@unit          [Nm]
@min           -32767
@max           +32766
@todo          20150615CO: is this still needed, no code impact*/
/*PRQA S 0631 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
typedef sint16 torque_t;       /*%unit:Nm*/ 
/*! scale for torque_t */ 
#define Torque_s Scale_1

/*! Ratio
@description   Ratio, relation between two values
@resolution    0.01
@unit          [-]
@min           0
@max           65.534
@todo          20150615CO: is this still needed, no code impact*/
typedef uint16 ratio_t;         /*%scale:0.01*/
/*! scale for ratio_t */
#define Ratio_s Scale_100

/*! Weight
@description   Weight
@resolution    0.1
@unit          [Kg]
@min           0
@max           6553.4
@todo          20150615CO: is this still needed, no code impact*/
typedef uint16 weight_t;         /*%scale:0.1 unit:kg*/
/*! scale for weight_t */
#define Weight_s Scale_10
/*! minimum for weight_t */
#define Weight_min (0)
/*! maximum for weight_t */
#define Weight_max (65535)

/*! Energy
@description   Energy
@resolution    1
@unit          [Nms]
@min           -32767
@max           +32766
@todo          20150615CO: is this still needed, no code impact*/
typedef sint16 energy_t;           /*%unit:Nms*/
/*! scale for energy_t */
#define Energy_s Scale_1

/*! Confidence
@description   Confidence
@resolution    100.0/255.0
@unit          [%]
@min           0
@max           100
@todo          20150615CO: is this still needed, no code impact*/
//typedef uint8 confidence_t;      /*%scale:0.392156862745 unit:%*/
/*! scale for confidence_t */
#define Confidence_s   (255)
/*! minimum for confidence_t */
#define Confidence_min (0)
/*! maximum for confidence_t */
#define Confidence_max (255)

/*! Angle
@description   Angle, positive counter clockwise / left
@resolution    0.0001
@unit          [rad]
@min           -31.4160
@max           +31.4160
@todo          20150615CO: is this still needed, no code impact*/
typedef sint32 angle_t;            /*%scale:0.0001 unit:rad*/
/*! scale for angle_t */
#define Angle_s Scale_10000 
/*! minimum for angle_t */
#define Angle_min (-314160)
/*! maximum for angle_t */
#define Angle_max (314160)

/*! Former 'Pi' define renamed so that it is properly visible that this is the fixed-point PI
used in 'mat' and 'phys' sub-components */
#define Pi_fixpoint_angle   ((angle_t)31416)

/*! Curvature
@description   Curvature, positive counter clockwise / left
@resolution    0.00001
@unit          [1/m]
@min           -0.32767
@max           +0.32766
@todo          20150615CO: is this still needed, no code impact*/
typedef sint16 curvature_t;       /*%scale:0.00001 unit:1/m*/
/*! scale for curvature_t */
#define Curvature_s Scale_100000
/*! minimum for curvature_t */
#define Curvature_min (-32767)
/*! maximum for curvature_t */
#define Curvature_max (+32766)

/* quality_t now generated in RTE NOTE: clarify if defines still needed by some branch */
#if 0
/*! Quality
@description   Quality
@resolution    1
@unit          [%]
@min           0
@max           100    */
typedef uint8 quality_t;        /*%unit:%*/
/*! scale for quality_t */
#define Qual_s Scale_1
/*! minimum for quality_t */
#define Qual_min (0)
/*! maximum for quality_t */
#define Qual_max (100)
#endif

#ifndef Percentage_s
/*! Percentage
@description   Percentage
@resolution    1
@unit          [%]
@min           0
@max           100
@todo          20150615CO percentage_t is definded in RTE, how to make sure boundaries are defined properly*/
//typedef uint8 percentage_t;     /*%unit:%*/
/*! scale for percentage_t */
#define Percentage_s Scale_1
#endif
#ifndef Percentage_min
/*! minimum for percentage_t */
#define Percentage_min (0)
#endif
#ifndef Percentage_max
/*! maximum for percentage_t */
#define Percentage_max (100)
#endif

/* ----------- dm hypothesis type --------------------*/
/*! enum to define labels for driver monitoring Hypothesis types */
typedef enum
{
  DIMHypoType_No               = 0u,      /*!< empty hypothesis*/
  DIMHypoType_Feedback         = 1u,      /*!< driver feedback - value -100: strong negative feedback, +100 strong positive feedback*/
  DIMHypoType_Activity         = 2u,      /*!< driver activity - value 0: no activity, 100: high activity*/
  DIMHypoType_Attention        = 3u,      /*!< driver attention - value -100: distracted, +100: high attention*/
  DIMHypoType_LaneChangeLeft   = 4u,      /*!< driver wants to change the lane to the left - value 0: no lane change, 100: high probability*/
  DIMHypoType_LaneChangeRight  = 5u,      /*!< driver wants to change the lane to the right - value 0: no lane change, 100: high probability*/
  DIMHypoType_Drowsieness      = 6u,      /*!< driver is drowsy: 0: low probability, 100: high probability*/
  DIMHypoType_Overtake         = 7u,      /*!< driver plans to overtake: 0: driver will not overtake, driver will overtake*/
  DIMHypoType_Distraction      = 8u,      /*!< driver distraction - value 0: no distraction, 100: high distraction*/
  DIMHypoType_SportStyle       = 9u,      /*!< driver sportstyle - value 0: no sportstyle, 100: high sportstyle*/
  DIMHypoType_LaneChange       = 10u,     /*!< driver changes lane - value -100: langange left, 0: no lanechange, 100: langange right*/
  DIMHypoType_Max              = 11u      /*!< counter for the enum*/
} eDIMHypoType_t;

/* ----------- cd hypothesis type --------------------*/

/*! Error type, currently only used by CD @todo: TBD if needed on global level */
typedef enum
{
  GDB_ERROR_NONE               = 0u,   /*!< no error*/
  GDB_ERROR_POINTER_NULL       = 1u,   /*!< null pointer error*/
  GDB_ERROR_FUNC_POINTER_NULL  = 2u,   /*!< null function pointer error*/
  GDB_ERROR_CAST_VALUE_TO_HIGH = 3u,   /*!< while casting a variable, the value would be truncated because it was to high (example (signed char)200)*/
  GDB_ERROR_CAST_VALUE_TO_LOW  = 4u,   /*!< while casting a variable, the value would be truncated because it was to low  (example (signed char)-200)*/
  GDB_ERROR_UNKNOWN_TYPE       = 5u,   /*!< enum type handling unknown*/
  GDB_ERROR_FILTER_DOESNT_MATCH= 6u,   /*!< a filter function doesn't match any result*/
  GDB_ERROR_LOW_QUALITY        = 7u,   /*!< at least one signal didn't have a sufficient quality*/
  GDB_ERROR_ARRAY_OVERFLOW     = 8u,   /*!< the array index is out of bounds*/
  GDB_ERROR_ZERO_DEVISION      = 9u,   /*!< Devision by Zero requested*/
  GDB_ERROR_VALUE_RANGE        = 10u   /*!< a value is outside expeccted range */
} eGDBError_t;

/*! typedef for CD hypothesis data */
typedef struct 
{     
  sint8                      Probability;          /*!< -100 -> +100%*/
  percentage_t               Confidence;           /*!< hypothesis confidence*/  
  eDIMHypoType_t             eType;                /*!< type of the hypothesis (see eDIMHypoType_t)*/
  eGDBError_t                eGDBError;            /*!< error type (GDB_ERROR_NONE if module processing was OK) */
} GDB_DMHypothesis_t;


#if (defined(FCT_SENSOR_CTRL_INTFVER))
/*! Add alias to RHCInputFct_t type for FCT component (FCTSensorControl_t would be needed,
but RHCInputFct_t was already present in ARS3xx. To minimize impact, the name was kept for
that project) */
typedef RHCInputFct_t FCTSensorControl_t;
#endif

/*! @brief    struct to store update information of one interface.*/
typedef struct
{
  AlgoDataTimeStamp_t uiTimeStamp;            /*!<Last time stamp */
  uint8               uiLastUpdateCounter;    /*!<number of calling cycles without updated timestamp in interface*/
} sMeasCycleMonitor;

#if (FCT_CFG_ACDC_COMPONENT)
#define ACDC_ERROR_OUT_INTFVER 2
/*! @brief    ACDC Error provide ports output structure*/
typedef struct ACDCErrorOutProPort{
  uint32            uiVersionNumber;          /*!< Current version number*/
  SignalHeader_t    sSigHeader;               /*!< Signal header of the error provide port*/
  fDistance_t       fSafetyDistanceEBA;       /*!< Current required safety distance*/
  AlgoSignalState_t eSafetyDistanceEBAState;  /*!< State of the safety distance calculation */
  boolean           bCollisionAvoidActive;    /*!< Boolean indicating if the collision avoidance module is active */
}ACDCErrorOutProPort_t;
#endif

/*! SPM error provide ports: pointer to FCT_SEN provide port */
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) && (FCT_CFG_ERROR_OUTPUT_SEN))
typedef struct FctSenSPMErrorOutProPort{
  uint32           uiVersionNumber;
  SignalHeader_t   sSigHeader;
  AlgoErrorState_t t_ObjectNotMeasured;
  AlgoErrorState_t t_ObjectNotMeasTmp;
  AlgoErrorState_t t_Blockage;
  AlgoErrorState_t t_IncreaseBlockage;
  AlgoErrorState_t t_DecreaseBlockage;
  AlgoErrorState_t t_PartialBlockageObserver;
  AlgoErrorState_t t_ObjectLossObserver;
  AlgoErrorState_t t_RangeObserver;
  AlgoErrorState_t t_TimeoutObserver;
  uint8            u_NoOfObjLosses;
  AlgoErrorState_t t_InterferenceRange;
  AlgoErrorState_t t_SRDDampingState;
#if((FCT_SEN_ERROR_OUT_INTFVER >= 20U) && (ALGO_ARS500Sensor))
  BlockageType_t   t_BlockageType;
  BlockageCategory_t t_BlockageCategory;
  PartialBlockageLevel_t t_PartialBlockageLevel;
#endif
  boolean b_RequestRoadBeam;
}SPMErrorOutProPort_t;
#endif

#if (FCT_CFG_ACT_CODE_VERSION)
/* New Types - Begin */

/* FCU (FCT) <-> ISC */

/*! Typedef of <ISC_InformationPort> input port to ISC component */
typedef enum
{
  ACT_ISC_DRIVE_POS_NEUTRAL,
  ACT_ISC_DRIVE_POS_PARKING,
  ACT_ISC_DRIVE_POS_FORWARD,
  ACT_ISC_DRIVE_POS_BACKWARD
}
ACT_ISC_DRIVE_POS_t;
typedef struct
{
  ACT_ISC_DRIVE_POS_t t_DrivePos;
  uint8 u_SpeedDisplay;
  boolean b_AccelPedal;
  boolean b_BrakePedal;
  boolean b_ParkBrake;
  boolean b_DoorOpen;
  boolean b_DriverBeltUnlocked;
  boolean b_ABS_Active;
  boolean b_TCS_Active;
  boolean b_ESC_Active;
  boolean b_ABS_Failure;
  boolean b_TCS_Failure;
  boolean b_ESC_Failure;
}
ACT_ISC_Information_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_ISC_Information_t t_ISCI;
}
ACT_ISC_InformationPort_t;


/*! Typedef of <ISC_CommandPort> input port to ISC component */
typedef struct
{
  boolean b_Main;                 /* (OFF) System On | (READY|ACTIVE|OVERRIDE) System Not Off */
  boolean b_Set;                  /* (READY)  Activate Function & Set Actual Speed | (ACTIVE) Speed - 1kmh */
  boolean b_Resume;               /* (READY)  Activate Function                    | (ACTIVE) Speed + 1kmh */
  boolean b_Cancel;               /* (ACTIVE) Deactivate Function */
  boolean b_SpeedDec;             /* (ACTIVE) Speed - 10kmh */
  boolean b_SpeedInc;             /* (ACTIVE) Speed + 10kmh */

  boolean b_HeadwayInc;           /* (ACTIVE) Headway Timegap [0% -> 25% -> 50% -> 75% -> 100% -> 0%] */
}
ACT_ISC_Command_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_ISC_Command_t t_ISCC;
}
ACT_ISC_CommandPort_t;

/*! Typedef of <ISC_StatusPort> output port from ISC component */
typedef enum
{
  ACT_ISC_STATE_OFF,
  ACT_ISC_STATE_READY,
  ACT_ISC_STATE_ACTIVE,
  ACT_ISC_STATE_OVERRIDE
}
ACT_ISC_STATE_t;
typedef struct
{
  ACT_ISC_Command_t t_ISCC;       /* Command Confirmation (Asynchronous Operation) */
  ACT_ISC_STATE_t t_STATE;        /* System State */

  setspeed_t u_SetSpeed;          /* SetSpeed [kmh|mph] (CC) */

  uint8 u_TargetSpeed;            /* Measured Speed of the main control target [kmh] (ACC) */
  uint8 u_TargetDistance;         /* Measured Distance of the main control target [m] (ACC) */
  uint8 u_RequestDistance;        /* Requested Distance at current target speed [m] (ACC) */
  percentage_t u_HeadwaySetting;  /* Requested Headway Setting [0..100]% (ACC) */
  boolean b_TargetControl;        /* At least one target is being controlled on (possibly not with major decel) (ACC) */
  boolean b_TakeOverRequest;      /* Driver has to take over control - Target distance probably will fall below the alert distance (ACC) */
}
ACT_ISC_Status_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_ISC_Status_t t_ISCS;
}
ACT_ISC_StatusPort_t;



/* ISC <-> FUNCTION COMPONENTS (LOCC, LOHP, LOSLA, ...) */

/*! Typedef of <FunctionDegradation> substructure for all Function Components */
#if 0
typedef struct
{
  boolean b_NoEngagement;       /* Inhibition of Function Engagement */
  boolean b_Disengagement;      /* Forced Disengagement of Function */
  boolean b_Deceleration;       /* Forced Disengagement after Deceleration */
}
ACT_FunctionDegradation_t;
#endif

/*! Typedef of <CruiseControlCommandPort> input port to LOCC component */
typedef enum
{
  ACT_CC_FUN_CC,                /* Cruise Control Function */
  ACT_CC_FUN_LIM                /* Speed Limiter Function */
}
ACT_CC_FUN_t;
typedef enum
{
  ACT_CC_OP_NOP,                /* No Operation */
  ACT_CC_OP_SPEED_SET_ACT,      /* Set actual Display Speed */
  ACT_CC_OP_SPEED_SET_EXT,      /* Set external Speed */
  ACT_CC_OP_SPEED_CLEAR,        /* Clear SetSpeed */
  ACT_CC_OP_SPEED_INC_1,        /* Increment SetSpeed by minor Step */
  ACT_CC_OP_SPEED_INC_2,        /* Increment SetSpeed by major Step */
  ACT_CC_OP_SPEED_DEC_1,        /* Decrement SetSpeed by minor Step */
  ACT_CC_OP_SPEED_DEC_2         /* Decrement SetSpeed by major Step */
}
ACT_CC_OP_t;
typedef struct
{
  boolean b_Enable;             /* Enable CC */
  setspeed_t u_SetSpeedExt;     /* External Setspeed [kmh | mph] (for SLA Function...) */
  ACT_CC_FUN_t t_Function;      /* CC Function (CC <-> LIM) */
  ACT_CC_OP_t t_Operation;      /* CC Operation (SetSpeed Modification) */
}
ACT_CruiseControlCommand_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_CruiseControlCommand_t t_Command;
  FunctionDegradation_t t_Degrade;
}
ACT_CruiseControlCommandPort_t;


/*! Typedef of <CruiseControlStatePort> output port from LOCC component */
typedef struct
{
  boolean b_Ready;                /* CC is ready for activation */
  boolean b_Active;               /* CC is active */
  boolean b_Override_Accel;       /* Driver overrides CC by Accelerator Pedal */
  boolean b_Override_Decel;       /* Driver overrides CC by Decelerator Pedal */
  boolean b_SpeedStored;          /* CC SetSpeed is stored */
  setspeed_t u_SetSpeed;          /* Actual CC SetSpeed [kph | mph] */
  ACT_CC_OP_t t_Operation;        /* Actual CC Operation */
}
ACT_CruiseControlState_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_CruiseControlState_t t_State;
}
ACT_CruiseControlStatePort_t;

#if 0
/*! Typedef of <TargetControlCommandPort> input port to LOHP component */
typedef struct
{
  boolean b_Enable;               /* Enable TC */
  boolean b_Disable;              /* Disable TC (priority) */
  percentage_t u_HeadwaySetting;  /* Requested Headway Setting [0..100]% */
}
ACT_TargetControlCommand_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_TargetControlCommand_t t_Command;
  ACT_FunctionDegradation_t t_Degrade;
}
ACT_TargetControlCommandPort_t;


/*! Typedef of <TargetControlStatePort> output port from LOHP component */
typedef struct
{
  boolean b_Ready;                /* TC is ready for activation */
  boolean b_Active;               /* TC is active */
  boolean b_TargetDetected;       /* At least one target is being controlled on (possibly not with major decel) */
  boolean b_ControlAlert;         /* Target distance probably will fall below the alert distance */
  uint8 u_DistanceRequested;      /* Reference distance at current target speed for steady state [m] */
  uint8 u_DistanceTarget;         /* Measured distance of the control target [m] */
  uint8 u_SpeedTarget;            /* Measured speed of the control target [kmh] */
}
ACT_TargetControlState_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_TargetControlState_t t_State;
}
ACT_TargetControlStatePort_t;
#endif

/* ISC <-> LOPC */

/*! Typedef of <LogicVehicleCommandPort> port from ISC component to LOPC */
typedef struct
{
  boolean b_StartConfirmation;      /* Confirmation (by Driver) to Start Vehicle */
}
ACT_LogicVehicleCommand_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_LogicVehicleCommand_t t_LVC;
}
ACT_LogicVehicleCommandPort_t;

/*! Typedef of <LogicVehicleStatePort> port from LOPC component to ISC */
typedef struct
{
  boolean b_StandStill;             /* Vehicle is in Physical Standstill (Safe by Brake) */
  boolean b_HoldState;              /* Vehicle is in Logical Hold State (Standstill for longer than 3s) */
  boolean b_StartRequest;           /* Start of Vehicle is requested by Controller */
}
ACT_LogicVehicleState_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_LogicVehicleState_t t_LVS;
}
ACT_LogicVehicleStatePort_t;

/* FUNCTION COMPONENTS (LOCC, LOHP, LOSLA, ...) <-> LOPC */

/*! Typedef of <ControlLimitations> struct */
#if 0
typedef struct
{
  float32 f_LongAccelMax;           /* Maximum acceleration of ego vehicle (pos) [m/s^2] */
  float32 f_LongDecelMax;           /* Maximum deceleration of ego vehicle (neg) [m/s^2] */
  float32 f_LongAccGradMax;         /* Maximum acceleration gradient of ego vehicle (pos) [m/s^3] */
  float32 f_LongDecGradMax;         /* Maximum deceleration gradient of ego vehicle (neg) [m/s^3] */
}
ACT_ControlLimitations_t;
#endif

/*! Typedef of <CurvePreferences> struct */
typedef struct
{
  float32 f_AccelLatLim;            /* Lateral acceleration limit for all segments [m/s^2] */
}
ACT_CurvePreferences_t;

/*! Typedef of <VelocitySegment> struct */
typedef struct
{
  float32 f_LongDistance;           /* Longitudinal distance to segment begin (zero for actual) [m] */
  float32 f_LongExtension;          /* Longitudinal extension of segment (residual extension for actual) [m] */
  float32 f_LongVeloLimit;          /* Longitudinal velocity limit inside segment [m/s] */
  boolean b_Enable;                 /* Enable Control on Segment */
}
ACT_VelocitySegment_t;

/*! Typedef of <CurveSegment> struct */
typedef struct
{
  float32 f_LongDistance;           /* Longitudinal distance to road segment begin (zero for actual) [m] */
  float32 f_LongExtension;          /* Longitudinal extension of segment (residual extension for actual) [m] */
  float32 f_Curvature;              /* Curvature at segment begin (C0) [1/m] */
  float32 f_CurveGrad;              /* Curvature gradient over distance of segment (C1) [1/m^2] */
  boolean b_Enable;                 /* Enable Control on Segment */
}
ACT_CurveSegment_t;

/*! Typedef of <TargetPreferences> struct */
#if 0
typedef struct
{
  float32 f_RelLongDistReference;                     /* Relative longitudinal reference distance to target vehicle */
  float32 f_RelLongDistIntrusion;                     /* Relative longitudinal intrusion distance from reference distance */
  float32 f_RelLongDistAlert;                         /* Relative longitudinal alert distance from reference distance */
  float32 af_RelLongDistErr[ACT_CFG_TP_ACC_CRV_SIZE]; /* Relative longitudinal distance error curve (-|0|+) [m] */
  float32 af_RelLongPrefAcc[ACT_CFG_TP_ACC_CRV_SIZE]; /* Relative longitudinal preferred acceleration curve (-|0|+) [m/s^2] */
  uint8   u_RelLongDistErrorDynSize;                  /* Dynamic Size of distance error and acceleration curve */
  uint8   u_RelLongDistErrZeroIndex;                  /* Index of zero distance error and acceleration */
}
ACT_TargetPreferences_t;
#endif

/*! Typedef of <TargetVehicle> struct */
#if 0
typedef struct
{
  float32 f_RelLongAccel;                 /* Relative longitudinal acceleration of target vehicle [m/s^2] */
  float32 f_RelLongVelo;                  /* Relative longitudinal velocity of target vehicle [m/s] */
  float32 f_RelLongDist;                  /* Relative longitudinal distance to target vehicle [m] */
}
ACT_TargetVehicle_t;
#endif

/*! Typedef of <VehicleSpeedCommandPort> input port to LOP component */
typedef struct
{
  ControlLimitations_t t_CtrLim;      /* Limitations for control */
  float32 f_EgoLongVeloCmd;               /* Commanded longitudinal velocity of ego vehicle [m/s] */
  boolean b_ArbitDriverMin;               /* Minimum arbitration against driver request (speed limiter function) */
  boolean b_Enable;                       /* Enable Control */
}
ACT_VehicleSpeedCommand_t;
#if (ACT_CFG_CC_VSC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_VehicleSpeedCommand_t at_VSC[ACT_CFG_CC_VSC_PORT_CNT];
}
ACT_CC_VehicleSpeedCommandPort_t;
#endif
#if (ACT_CFG_SLA_VSC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_VehicleSpeedCommand_t at_VSC[ACT_CFG_SLA_VSC_PORT_CNT];
}
ACT_SLA_VehicleSpeedCommandPort_t;
#endif

/*! Typedef of <VehicleSpeedStatePort> output port from LOP component */
typedef struct
{
  float32 f_LongDecelMax;             /* External deceleration limit */
  boolean b_Active;                 /* Controller is active */
  boolean b_Limited;                /* Controller is limited by external limit */
  boolean b_StartTrial;             /* Target Follow Control tries to start vehicle */
}
ACT_VehicleSpeedState_t;
#if (ACT_CFG_CC_VSC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_VehicleSpeedState_t at_VSS[ACT_CFG_CC_VSC_PORT_CNT];
}
ACT_CC_VehicleSpeedStatePort_t;
#endif
#if (ACT_CFG_SLA_VSC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_VehicleSpeedState_t at_VSS[ACT_CFG_SLA_VSC_PORT_CNT];
}
ACT_SLA_VehicleSpeedStatePort_t;
#endif


/*! Typedef of <DistanceSpeedCommandPort> input port to LOP component */
#if (ACT_CFG_DSC_PORT_SEG_CNT)
typedef struct
{
  ControlLimitations_t  t_CtrLim;                               /* Limitations for control */
  ACT_VelocitySegment_t t_VeloSeg[ACT_CFG_DSC_PORT_SEG_CNT];    /* Segment array */
}
ACT_DistanceSpeedCommand_t;
#endif
#if (ACT_CFG_SLA_DSC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_DistanceSpeedCommand_t at_DSC[ACT_CFG_SLA_DSC_PORT_CNT];
}
ACT_SLA_DistanceSpeedCommandPort_t;
#endif

/*! Typedef of <DistanceSpeedStatePort> output port from LOP component */
typedef struct
{
  boolean b_Active;                 /* Controller is active */
  boolean b_Limited;                /* Controller is limited by external limit */
}
ACT_DistanceSpeedState_t;
#if (ACT_CFG_SLA_DSC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_DistanceSpeedState_t at_DSS[ACT_CFG_SLA_DSC_PORT_CNT];
}
ACT_SLA_DistanceSpeedStatePort_t;
#endif


/*! Typedef of <DistanceCurveCommandPort> input port to LOP component */
#if (ACT_CFG_DCC_PORT_SEG_CNT)
typedef struct
{
  ControlLimitations_t   t_CtrLim;                               /* Limitations for control */
  ACT_CurvePreferences_t t_CrvPref;                              /* Preferences for curves */
  ACT_CurveSegment_t     t_CurveSeg[ACT_CFG_DCC_PORT_SEG_CNT];   /* Segment array */
}
ACT_DistanceCurveCommand_t;
#endif
#if (ACT_CFG_CP_DCC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_DistanceCurveCommand_t at_DCC[ACT_CFG_CP_DCC_PORT_CNT];
}
ACT_CP_DistanceCurveCommandPort_t;
#endif

/*! Typedef of <DistanceCurveStatePort> output port from LOP component */
typedef struct
{
  boolean b_Active;                 /* Controller is active */
  boolean b_Limited;                /* Controller is limited by external limit */
}
ACT_DistanceCurveState_t;
#if (ACT_CFG_CP_DCC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_DistanceCurveState_t at_DCS[ACT_CFG_CP_DCC_PORT_CNT];
}
ACT_CP_DistanceCurveStatePort_t;
#endif

#if 0
/*! Typedef of <TargetFollowCommandPort> input port to LOP component */
#if (ACT_CFG_TP_ACC_CRV_SIZE)
typedef struct
{
  ACT_ControlLimitations_t  t_CtrLimit;   /* Limitations for Control */
  ACT_TargetPreferences_t   t_TarPref;    /* Preferences for Target Follow Planning */
  ACT_TargetVehicle_t       t_TarVeh;     /* Target Vehicle */
  boolean                   b_Enable;     /* Enable Control on Target */
}
ACT_TargetFollowCommand_t;
#endif
#if (ACT_CFG_TP_ACC_CRV_SIZE) && (ACT_CFG_HP_TFC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_TargetFollowCommand_t at_TFC[ACT_CFG_HP_TFC_PORT_CNT];
}
ACT_HP_TargetFollowCommandPort_t;
#endif

/*! Typedef of <TargetFollowStatePort> output port from LOP component */
typedef struct
{
  boolean b_Active;                 /* Controller is active */
  boolean b_Limited;                /* Controller is limited by external limit */
  boolean b_ControlAlert;           /* Target distance probably will fall below the alert distance */
}
ACT_TargetFollowState_t;
#if (ACT_CFG_HP_TFC_PORT_CNT)
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_TargetFollowState_t at_TFS[ACT_CFG_HP_TFC_PORT_CNT];
}
ACT_HP_TargetFollowStatePort_t;
#endif
#endif

/* LOPC -> LODMC */

/*! Typedef of <EgoVehicleCommandPort> port from LOPC component to LODMC */
typedef struct
{
  float32 f_LongAcceleration;       /* Longitudinal acceleration command to ego vehicle */
  boolean b_ArbitDriverMin;         /* Minimum arbitration against driver request (speed limiter function) */
  boolean b_Standstill;             /* Standstill request to ego vehicle */
  boolean b_Enabled;                /* Control is enabled */
}
ACT_EgoVehicleCommand_t;
typedef struct
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
  ACT_EgoVehicleCommand_t t_EVC;
}
ACT_EgoVehicleCommandPort_t;

/* New Types - End */
#endif /* FCT_CFG_ACT_CODE_VERSION */

/*! SLATE error provide ports: pointer to FCT_SEN provide port */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ERROR_OUTPUT_SEN))
typedef struct SLATEErrorOutProPort{
  uint32           uiVersionNumber;
  SignalHeader_t   sSigHeader;
  boolean          b_ObjSelectionActive;
  AlgoErrorState_t t_BelowMinPerfDist_AZ;
  AlgoErrorState_t t_BelowMinPerfDist_VDY;
  AlgoErrorState_t t_BelowMinPerfDist_EL;
}SLATEErrorOutProPort_t; 
#endif

/* These CAL datatypes are used in both CAL and SLATE; hence moved here */
/*! @brief Structure storing the second degree polynomial approximation of a trace,
using y = f(x) = fC0 + fC1 * x + fC2 * x^2 */
typedef struct CALTracePolyL2 {
  float32 fC0;/*!<fC0 */
  float32 fC1;/*!<fC1 */
  float32 fC2;/*!<fC2 */
  boolean isValid;/*!<isValid */
} CAL_t_TracePolyL2;

/*! @brief CAL_t_TrajRefPoint */
typedef struct
{
  float32 fX;           /*!< Trajectory reference point X coordinate */
  float32 fY;           /*!< Trajectory reference point Y coordinate */
  float32 fDistToTraj;  /*!< Distance to trajectory @unit:m */
  float32 fDistOnTraj;  /*!< Distance from vehicle center of gravity to object on trajectory @unit:m */
} CAL_t_TrajRefPoint;


#if (FCT_CFG_COLLISION_DETECTION)
typedef struct SLATE_CD_Data{
  uint32         uiVersionNumber;
  SignalHeader_t sSigHeader;
  ObjNumber_t    t_ACCRelObjID;
}SLATE_CD_Data_t;
#endif
/************************************************************************/
/*                          FCT_VER types                               */
/************************************************************************/

/*! @brief Type used for describing an FCT sub-component version */
typedef uint32 FCTSwVersion_t;

/************************************************************************/
/*                          FCT_SEN types                               */
/************************************************************************/

/* date: 2015-06-17, reviewer: Lonard jaison manohar(uidj2547), reason: Simulation specific macro */
typedef enum {
  FCTSEN_RTA_PROCESS,                           /*!< Whole procedure runtime */
  FCTSEN_RTA_PREPRE_PROCESS,                    /*!< data preparation runtime */
  FCTSEN_RTA_PRE_PROCESS,                       /*!< data preprocessing runtime */
  FCTSEN_RTA_POST_PROCESS,                      /*!< Post processing runtime */
  FCTSEN_RTA_PROCESSFREEZE,                     /*!< Process Measfreeze runtime */
  FCTSEN_RTA_FRAMEFREEZE,                       /*!< Frame Measfreeze runtime */
  FCTSEN_RTA_FRAME_SEN,                         /*!< Runtime for FRAME_SEN */
  FCTSEN_RTA_NOF_CHECKPOINTS                    /*!< This line has to be the last to determine the size of the structure */
} FCTSenRtaMapping_t;                             

#if FCT_CFG_RUNTIME_MEAS
/* Virtual address for FCT  runtime measurement freeze in the device (to be moved to rte) */

#ifndef FCT_MEAS_ID_RUNTIME_DEBUG
#define FCT_MEAS_ID_RUNTIME_DEBUG 0x20273600
#endif
 
typedef struct
{
  uint32 uRuntime[FCTSEN_RTA_NOF_CHECKPOINTS];
}FCT_t_RuntimeInfo;
#endif

/*! @brief          Define FCT Comp state if it is not available already. This improves consistency, as all components work with the same states.
    @description    FCT component state. Describes the state in which the FCT component is currently. 
                      @range[0,6], @values: enum { COMP_STATE_NOT_INITIALIZED=0,
                                                   COMP_STATE_RUNNING=1,
                                                   COMP_STATE_TEMPORARY_ERROR=2,
                                                   COMP_STATE_PERMANENT_ERROR=3,
                                                   COMP_STATE_SUCCESS=4,
                                                   COMP_STATE_REDUCEDAVAILABILITY=5,
                                                   COMP_STATE_NOT_RUNNING=6} */
typedef uint8 FCTCompState_t;


/*! operating modes of sub-component */
typedef enum {
  FCT_SEN_INIT,       /*!< initialize all    */
  FCT_SEN_RUN,        /*!< normal processing */
  FCT_SEN_RG_HIGH,    /*!< normal processing, but set RGLength to HIGH Resolution */
  FCT_SEN_SHUTDOWN,   /*!< shutdown (system in error, but recovery possible) */
  FCT_SEN_ERROR       /*!< fatal error, no recovery*/
} FCTSenState_t;

/*! FCT sub-component version structure */
typedef struct 
{
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  FCTSwVersion_t  uiSPM;
#endif
  uint32          uProjectID;
  FCTSwVersion_t  FCT_VERSION_AS_TEXT;
  FCTSwVersion_t  uiFCTSEN;
} FCTSenVersions_t;

/*! @brief    The Frame data type of FCTSen */
typedef struct FCTSenFrame_t {
  AlgoCycleCounter_t  uiCycleCounter;   /*!< The FCT_SEN cycle counter */
  FCT_OP_MODE_t       eFCTOpMode;       /*!< FCT requested operation mode */
  FCTCompState_t      eFCTState;        /*!< FCT current operation mode */
  FCTSenVersions_t    Versions;         /*!< FCT versions */
} FCTSenFrame_t;

/*! @brief    Aggregation struct of all input port measurement timestamps */
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
typedef struct
{
  sMeasCycleMonitor pSenCtrlData;
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  sMeasCycleMonitor pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
  sMeasCycleMonitor pEmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  sMeasCycleMonitor pEmCustObjList;   /*!< EM customer specific object list */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  sMeasCycleMonitor pEmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  sMeasCycleMonitor pEmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
  sMeasCycleMonitor pMovObjTraces;    /*!< Moving object traces */
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
  sMeasCycleMonitor pObjectTraces;    /*!< New object traces */
#endif
#endif
  sMeasCycleMonitor pEgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
  sMeasCycleMonitor pEgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  sMeasCycleMonitor pEgoStaticData;   /*!< the static vehicle ego data */
#if (FCT_CFG_RSP_OUTPUT_PD)
  sMeasCycleMonitor pRSPOutputPD;     /*!< RSP roadbeam information */
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  sMeasCycleMonitor pPerfDegrData;    /*!< Performance degradation input data */
#endif
#if (FCT_CFG_ROAD_INPUT)
  sMeasCycleMonitor pRoadData;        /*!< Road/lane information */
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
  sMeasCycleMonitor pRSPContextData;  /*!< RSP Kontext data */
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  sMeasCycleMonitor pFctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* customer specific input/output */
  sMeasCycleMonitor pFCTCustomInput;  /*!< Custom input */
#endif
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Fusion output information from camera */
  sMeasCycleMonitor pCameraObjData;   /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Mobil-eye raw input for debugging */
  sMeasCycleMonitor pME_in;             /*!< Input from mobil-eye directly for debugging */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  sMeasCycleMonitor pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Macom SRD blockage info for SPM */
  sMeasCycleMonitor pPerfDegrExtInput;   /*!< Performance degradation external input (short range sensor info) */
#endif
#if ((FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pDIMOutputCustom;   /*!< DIM output custom from FCT_VEH */
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pNaviData;          /*!< Simple navi input data */
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pCamLaneData;       /*!< Camera lane input data */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  sMeasCycleMonitor pEmFusionObjList;       /*!< EM Fusion Object List */
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    sMeasCycleMonitor pTSAInputData;       /*!< SLA input data from camera */
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pCamSLAInputData;       /*!< SLA input data from camera */
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
  sMeasCycleMonitor pLongCtrlResp;         /* Dynamic controller response, in SLATE currently used to get drivemode input */
#endif /* ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)) */
} FCTSen_InputMeasCounter_t;
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )

#define Acc_total_fuzzy_rules (47)

typedef struct
{
  sint32 area;
  sint32 fuzzyval;
  sint32 mid;
} FuzzyRuleData_t;

typedef struct
{
  sint32 REL_DISTANCE;
  sint32 SPEED_REL;
  sint32 A_OBJECT;
  sint32 DISTANCE_SET_ERROR;
  sint32 DISTANCE_MIN_ERROR;
  sint32 SOFTNESS;
  sint32 V_OWN;
  sint32 V_OBJ;
  sint32 DISTANCE;
} FuzzyInputData_t;

typedef struct
{
  FuzzyRuleData_t FUZZY_RULE_DATA[Acc_total_fuzzy_rules + 1];
  FuzzyInputData_t FUZZY_INPUT_DATA;
} FuzzyDebugData_t;

#endif /* FCT_CFG_DEBUG_FUZZY_CONTROLLER */

/************************************************************************/
/*                     FCT_VEH types                                    */
/************************************************************************/
/*! @brief    Aggregation struct of all input port data update information*/
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
typedef struct
{
  sMeasCycleMonitor pVehCtrlData;       /*!< Vehicle Control Data input */
  sMeasCycleMonitor pEgoDynRaw;         /*!< EgoDynRaw*/
  sMeasCycleMonitor pEgoStaticData;     /*!< vehicle parameter*/
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  sMeasCycleMonitor pAccLever;          /*!< ACC lever information (input from driver) */
  sMeasCycleMonitor pLongCtrlResp;      /*!< Dynamic controller response */
  sMeasCycleMonitor pAccDisplayObj;     /*!< Display object data output by FCT_SEN */
  sMeasCycleMonitor pAccOutput;         /*!< ACC output data by FCT_SEN */
#if (FCT_CFG_TCI)
  sMeasCycleMonitor pTCIInput;          /*!< TCI Input Interface */
#endif
#if (FCT_CFG_SLA_FEATURE)
  sMeasCycleMonitor pSLAData;           /*!< SLA speed limit data from FCT_SEN */
#endif
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pDIMInputGeneric;   /*!< Generic DIM input */
  sMeasCycleMonitor pDIMInputCustom;    /*!< Custom DIM input */
#endif 
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pHMIData;           /*!< HMI data output */
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Hypothesis interface */
  sMeasCycleMonitor pFCTCDHypotheses;   /*!< CD hypotheses */
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pHEADInputGeneric;  /*!< Generic HEAD input */
  sMeasCycleMonitor pHEADInputCustom;   /*!< Custom HEAD input */
#endif
#if ((FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_VEH_CFG_EM_CLD_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pEM_CLD_Output;     /*!< EM camera lane detection output */
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  sMeasCycleMonitor pFctVehCustInput;   /*!< Custom input for FCT_VEH */
#endif
} FCTVeh_InputMeasCounter;
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

/*! @brief    Operating modes of sub-component */
typedef enum {
  FCT_VEH_INIT,     /*!< initialize all    */
  FCT_VEH_RUN,      /*!< normal processing */
  FCT_VEH_SHUTDOWN  /*!< shutdown (system failure) */
} FCTVehState_t;

/*! @brief    FCT sub-component version stucture */
typedef struct 
{
  FCTSwVersion_t  FCT_VERSION_AS_TEXT;
  FCTSwVersion_t  uiFCTVEH;                 /*!< SW verion of FCTVeh*/
} FCTVersions_t;

/*! @brief    The function frame */
typedef struct FCTVehFrame_t {
  AlgoCycleCounter_t  uiCycleCounter;   /*!< The FCT_VEH cycle counter */
  boolean             bFirstCycleDone;  /*!< Boolean flag used for first cycle check */
  FCT_OP_MODE_t       eFCTOpMode;       /*!< FCT operation mode */
  FCTVehState_t       eFCTState;        /*!< FCT current operation mode */
  FCTVersions_t       Versions;         /*!< FCT versions */
} FCTVehFrame_t;


#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*! @brief        FCT_Veh Soft error counter.
    @description  This structure is currently not used. It was implemented due to the Issue 496115*/
typedef struct {

  AlgoCycleCounter_t uiVehCtrlData;
  AlgoCycleCounter_t uiEgoDynRaw;
  AlgoCycleCounter_t uiEgoStaticData;
#if (FCT_CFG_LOPC_COMPONENT)
#if (CFG_ACC_LEVER_INPUT)
  AlgoCycleCounter_t uiAccLever;
#endif
  AlgoCycleCounter_t uiLongCtrlResp;
  AlgoCycleCounter_t uiAccDisplayObj;
  AlgoCycleCounter_t uiAccOutput;
#if (FCT_CFG_TCI)
  AlgoCycleCounter_t uiTCIInput;
#endif
#if (FCT_CFG_SLA_FEATURE)
  AlgoCycleCounter_t uiSLAData;
#endif
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  AlgoCycleCounter_t uiFCTAccOOIData;
#endif
#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
  AlgoCycleCounter_t uiDIMInputCustom;
  AlgoCycleCounter_t uiDIMInputGeneric;
#endif
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if (HMI_INPUT_DATA < FCT_HMI_INTFVER_MIN_G30_I390)
  AlgoCycleCounter_t uiHMIData;
#else
  AlgoCycleCounter_t uiHMIData;
#endif
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  AlgoCycleCounter_t uiFCTCDHypotheses;
#endif
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  AlgoCycleCounter_t uiHEADInputGeneric;
  AlgoCycleCounter_t uiHEADInputCustom;  
#endif
#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT)
  AlgoCycleCounter_t uiAlignmentMonInput;
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
    /*no signal header*/
#endif
#if (FCT_CFG_CPAR_PARAMS)
  AlgoCycleCounter_t uiCPAR_FCT_Parameters;
#endif
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
  AlgoCycleCounter_t uiVehSig;
#endif
#if (FCT_VEH_CFG_EM_CLD_INPUT)
  AlgoCycleCounter_t uiEM_CLD_Output;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  AlgoCycleCounter_t uiFctVehCustInput;
#endif

} FCTVehSoftErrorCounter_t;

#endif /* FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK */




#endif
