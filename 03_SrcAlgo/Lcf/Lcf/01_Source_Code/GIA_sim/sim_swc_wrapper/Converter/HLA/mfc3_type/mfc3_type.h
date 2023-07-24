/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_adapter

MODULNAME:            mfc3_type.h

DESCRIPTION:          

AUTHOR:               Marcus Brunn

CREATION DATE:        28.01.2014

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: mfc3_type.h  $
CHANGES:              Revision 1.1 2021/12/13 17:23:37CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/mfc3_type/project.pj
CHANGES:              Revision 1.0 2017/03/03 10:35:05CET Sorge, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/mfc3_type/project.pj
CHANGES:              Revision 1.2 2014/03/19 16:30:35CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replace macros from glob_defs.h by the ones defined in cml_ext.h
CHANGES:              Fixed hlar input adapter for old recordings (headlamp type)
CHANGES:              Clean-up of no longer needed files in simulation
CHANGES:              - Added comments -  uidv7867 [Mar 19, 2014 4:30:36 PM CET]
CHANGES:              Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
CHANGES:              Revision 1.1 2014/03/18 16:59:24CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/hla_adapter/mfc3_type/project.pj
CHANGES:              Revision 1.2 2014/03/10 17:13:12CET Brunn, Marcus (brunnm) 
CHANGES:              support hlar_in interface  version 2.4.0
CHANGES:              --- Added comments ---  brunnm [Mar 10, 2014 5:13:13 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.1 2014/01/30 16:15:42CET Brunn, Marcus (brunnm) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla_adapter/src/mfc3_type/project.pj
CHANGES:              
**************************************************************************** */
#pragma once
#include "glob_type.h"

#ifdef ARRAY_BOUNDARY_CHECK
#include <boost/array.hpp>
#define ARRAY(dataType, numElements, variableName) boost::array<dataType, numElements> variableName
#define ARRAY2D(dataType, numElements1, numElements2, variableName) boost::array<boost::array<dataType, numElements2>, numElements1> variableName
#else
#define ARRAY(dataType, numElements, variableName) dataType variableName[numElements]
#define ARRAY2D(dataType, numElements1, numElements2, variableName) dataType variableName[numElements1][numElements2]
#endif


#define HLAR_MAX_NUM_DEFECT_PIXEL_V1           (90)
#define HLAF_NIGHTVIEW_OBJECTS_V1               (2)
#define RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS_V1 (5)
#define RTE_HLAF_MATRIX_MAX_DIMMING_AREAS_V1	  (5)
#define HLA_ui8_MAX_RGBL_ELEM_V1                (16)

typedef uint8  HLA_t_enum8;
typedef uint16 HLA_t_enum16;
typedef uint32 HLA_t_enum32;

typedef float32 HLA_t_fLightAngle;
typedef float32 HLA_t_fLightDistance;
typedef float32 HLA_t_f32LightOutput;



typedef struct
{
  float32   f32_Pitch;     /* [rad] pitch angle of online calibration  */
  float32   f32_Yaw;       /* [rad] yaw   angle of online calibration  */
  float32   f32_Roll;      /* [rad] roll  angle of online calibration  */
  float32   f32_OdoCali_m; /* [m]   calibration odometer               */
} HLA_t_CaliOnline_v1;


/*! Type definition for HLA availability signal */
typedef struct
{
  HLA_t_enum8             e_Type;                                     /*!< Access to signal HLA availability. */
  HLA_t_enum8             e_State;                                    /*!< Access to HLA State */
} HLA_t_Availability_v1;

typedef struct
{
  HLA_t_enum8           e_Type;                                     /*!< Access to signal HLA availability. */
  HLA_t_enum8           e_State;                                    /*!< Access to HLA State */
  HLA_t_enum8           e_USSens;                                   /*!< Access to US sensitivity mode */
} HLA_t_Availability_v2;

typedef struct
{
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Lt;                 /*!< Access to left rotation angle vertical cutoff  */
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Rt;                 /*!< Access to right rotation angle vertical cutoff */
  HLA_t_fLightAngle           f32_HorCutOffAng;                       /*!< Access to signal HLA horizontal cutoff angle   */
  HLA_t_fLightDistance        f32_LightDistance;                      /*!< Access to signal HLA lighting distance         */
  HLA_t_enum8                 e_HorCutOffAngState;                    /*!< Access to state of horizontal cutoff angle     */
  HLA_t_enum8                 e_LightDistanceState;                   /*!< Access to state of light distance              */
  HLA_t_enum8                 e_LightStyle_Lt;                        /*!< Access to signal HLA light style left          */
  HLA_t_enum8                 e_LightStyle_Rt;                        /*!< Access to signal HLA light style right         */
} HLA_t_MatrixGFAState_v1;

/*! Type definition for HLA input signal */
typedef struct
{
  HLA_t_enum8                 e_LightStyle_Lt;                        /*!< Access to signal HLA light style left          */
  HLA_t_enum8                 e_LightStyle_Rt;                        /*!< Access to signal HLA light style right         */

  HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt;              /*!< Access to left curve light rotation angle      */
  HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt;              /*!< Access to right curve light rotation angle     */
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Lt;                 /*!< Access to left rotation angle vertical cutoff  */
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Rt;                 /*!< Access to right rotation angle vertical cutoff */
   
  HLA_t_enum8                 e_HighBeamState;                        /*!< Access to signal HLA high beam state           */
  HLA_t_enum8                 e_LightModuleState;                     /*!< Access to signal HLA state HLM_LT              */
  HLA_t_fLightDistance        f32_LightDistance;                      /*!< Access to signal HLA lighting distance         */
  HLA_t_f32LightOutput        f32_LightOutput;                        /*!< Access to signal HLA headlamp light output     */
  HLA_t_enum8                 e_GlareReductionState;                  /*!< Access to signal glare reduction state         */
} HLA_t_HeadlightState_v1;

typedef struct
{
  HLA_t_enum8                 e_LightStyle_Lt;                       /*!< Access to signal HLA light style left          */
  HLA_t_enum8                 e_LightStyle_Rt;                       /*!< Access to signal HLA light style right         */

  HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt;             /*!< Access to left curve light rotation angle      */
  HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt;             /*!< Access to right curve light rotation angle     */
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Lt;                /*!< Access to left rotation angle vertical cutoff  */
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Rt;                /*!< Access to right rotation angle vertical cutoff */

  HLA_t_enum8                 e_HighBeamState;                       /*!< Access to signal HLA high beam state           */
  HLA_t_enum8                 e_LightModuleState;                    /*!< Access to signal HLA state HLM_LT              */
  HLA_t_fLightDistance        f32_LightDistance;                     /*!< Access to signal HLA lighting distance         */
  HLA_t_f32LightOutput        f32_LightOutput;                       /*!< Access to signal HLA headlamp light output     */
  HLA_t_enum8                 e_GlareReductionState;                 /*!< Access to signal glare reduction state         */
} HLA_t_HeadlightState_v2;

typedef struct
{
  HLA_t_enum8                 e_LightModuleState;                     /*!< Access to signal HLA state HLM_LT              */
  ARRAY(HLA_t_MatrixGFAState_v1, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS_V1, GFA);  /*!< Access to glare free areas         */
  uint32                      nGFA;                                   /*!< Access to number of used GFAs                  */
  HLA_t_enum8                 e_HighBeamState;                        /*!< Access to signal HLA high beam state           */
  HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt;              /*!< Access to left curve light rotation angle      */
  HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt;              /*!< Access to right curve light rotation angle     */
  HLA_t_enum8                 e_GlareReductionState;                  /*!< Access to signal glare reduction state         */
  HLA_t_f32LightOutput        f32_LightOutput;                        /*!< Access to signal HLA headlamp light output     */
} HLA_t_HeadlightState_v3;

/*! Type definition for current imager characteristic */
typedef struct
{
  /* blacklevel (0 lux) */
  float32 f32_Blacklevel_R_Greyvalue;                                 /*!< [12bit greyvalue] red pixel   */
  float32 f32_Blacklevel_G_Greyvalue;                                 /*!< [12bit greyvalue] green pixel */
  float32 f32_Blacklevel_B_Greyvalue;                                 /*!< [12bit greyvalue] blue pixel  */
  /* 1. kneepoint */
  float32 f32_Kneepoint1_Greyvalue;                                   /*!< [12bit greyvalue]             */
  float32 f32_Kneepoint1_R_Lux;                                       /*!< [lux] red pixel               */
  float32 f32_Kneepoint1_G_Lux;                                       /*!< [lux] green pixel             */
  float32 f32_Kneepoint1_B_Lux;                                       /*!< [lux] blue pixel              */
  /* 2. kneepoint */
  float32 f32_Kneepoint2_Greyvalue;                                   /*!< [12bit greyvalue]             */
  float32 f32_Kneepoint2_R_Lux;                                       /*!< [lux] red pixel               */
  float32 f32_Kneepoint2_G_Lux;                                       /*!< [lux] green pixel             */
  float32 f32_Kneepoint2_B_Lux;                                       /*!< [lux] blue pixel              */
  /* saturation */
  float32 f32_Saturation_Greyvalue;                                   /*!< [12bit greyvalue]             */
  float32 f32_Saturation_R_Lux;                                       /*!< [lux] red pixel               */
  float32 f32_Saturation_G_Lux;                                       /*!< [lux] green pixel             */
  float32 f32_Saturation_B_Lux;                                       /*!< [lux] blue pixel              */
}HLA_t_ImagerResponseCurve_v1;


typedef struct
{
  /* blacklevel (0 lux) */
  uint16 ui16_Blacklevel_R_Greyvalue; /* [12bit greyvalue] red pixel   */
  uint16 ui16_Blacklevel_G_Greyvalue; /* [12bit greyvalue] green pixel */
  uint16 ui16_Blacklevel_B_Greyvalue; /* [12bit greyvalue] blue pixel  */
  /* 1. kneepoint */
  uint16  ui16_Kneepoint1_Greyvalue; /* [12bit greyvalue]   */
  float32 f32_Kneepoint1_R_Lux;      /* [lux] red pixel     */
  float32 f32_Kneepoint1_G_Lux;      /* [lux] green pixel   */
  float32 f32_Kneepoint1_B_Lux;      /* [lux] blue pixel    */
  /* 2. kneepoint */
  uint16  ui16_Kneepoint2_Greyvalue; /* [12bit greyvalue]   */
  float32 f32_Kneepoint2_R_Lux;      /* [lux] red pixel     */
  float32 f32_Kneepoint2_G_Lux;      /* [lux] green pixel   */
  float32 f32_Kneepoint2_B_Lux;      /* [lux] blue pixel    */
  /* saturation */
  uint16  ui16_Saturation_Greyvalue; /* [12bit greyvalue]   */
  float32 f32_Saturation_R_Lux;      /* [lux] red pixel     */
  float32 f32_Saturation_G_Lux;      /* [lux] green pixel   */
  float32 f32_Saturation_B_Lux;      /* [lux] blue pixel    */
} HLA_t_ImagerResponseCurve_v2;


/*! Type definition for current imager characteristic */
typedef struct
{
  uint32  ui32_R1;                                                    /*!< requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;                                                    /*!< requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;                                                  /*!< [us] current integration time T1     */
  float32 f32_T2_us;                                                  /*!< [us] current integration time T2     */
  float32 f32_T3_us;                                                  /*!< [us] current integration time T3     */
  float32 f32_Gain;                                                   /*!< [1]  total gain, depending on temperature */

  /* imager response curve (lux to 12bit greyvalues) */
  HLA_t_ImagerResponseCurve_v1 s_ResponseCurve; 
}HLA_t_ImagerCharacteristic_v1;

typedef struct
{
  uint32  ui32_R1;                                                    /*!< requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;                                                    /*!< requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;                                                  /*!< [us] current integration time T1     */
  float32 f32_T2_us;                                                  /*!< [us] current integration time T2     */
  float32 f32_T3_us;                                                  /*!< [us] current integration time T3     */
  float32 f32_Gain;                                                   /*!< [1]  total gain, depending on temperature */

  /* imager response curve (lux to 12bit greyvalues) */
  HLA_t_ImagerResponseCurve_v2 s_ResponseCurve; 
}HLA_t_ImagerCharacteristic_v2;


/*! Type definition for imager state */
typedef struct
{
  HLA_t_enum8               e_ExposureState;                          /*!< Access to current illumination control state */
  HLA_t_enum8               e_ActiveChar;                             /*!< Access to active characteristic of illumination control */
  uint32                    ui32_Brightness_mLux;                     /*!< Access to current brightness in mLux */
  float32                   f32_MeanInt;                              /*!< current mean intensity of IC Roi */
  uint32                    ui32_ExposureTime_us;                     /*!< Access to current exposure time in us */
  uint32                    ui32_FrameNumber;                         /*!< Access to the current frame number */
  float32                   f32_BlackLevel;                           /*!< current blacklevel */
  float32                   f32_Noise;                                /*!< current imager noise, standard deviation of black pixels */ 
} HLA_t_ImagerState_v1;

/*! Type definition for imager state */
typedef struct
{
  HLA_t_enum8               e_ExposureState;                          /*!< Access to current illumination control state */
  HLA_t_enum8               e_ActiveChar;                             /*!< Access to active characteristic of illumination control */
  float32                   f32_Brightness_Lux;                       /*!< current mean brightness in Lux of IC Roi */
  
  uint32                    ui32_ExposureTime_us;                     /*!< Access to current exposure time in us (= T1+T2+T3) */
  uint32                    ui32_FrameNumber;                         /*!< Access to the current frame number */
  
  float32                   f32_Noise;                                /*!< current imager noise, standard deviation of black pixels */

  HLA_t_ImagerCharacteristic_v1 s_ImagerCharacteristic;               /*!< imager characteristic  */
} HLA_t_ImagerState_v2;

typedef struct
{
  HLA_t_enum8               e_ActiveChar;                             /*!< Access to active characteristic of illumination control */
  float32                   f32_Brightness_Lux;                       /*!< current mean brightness in Lux of IC Roi */
  uint32                    ui32_ExposureTime_us;                     /*!< Access to current exposure time in us (= T1+T2+T3) */
  uint32                    ui32_FrameNumber;                         /*!< Access to the current frame number */
  float32                   f32_Noise;                                /*!< current imager noise, standard deviation of black pixels */ 

  HLA_t_ImagerCharacteristic_v1 s_ImagerCharacteristic;               /*!< imager characteristic  */
} HLA_t_ImagerState_v3;

typedef struct
{
  HLA_t_enum8               e_ActiveChar;                             /*!< Access to active characteristic of illumination control */
  float32                   f32_Brightness_Lux;                       /*!< current mean brightness in Lux of IC Roi */
  uint32                    ui32_ExposureTime_us;                     /*!< Access to current exposure time in us (= T1+T2+T3) */
  uint32                    ui32_FrameNumber;                         /*!< Access to the current frame number */
  float32                   f32_Noise;                                /*!< current imager noise, standard deviation of black pixels */ 

  HLA_t_ImagerCharacteristic_v2 s_ImagerCharacteristic;               /*!< imager characteristic  */
} HLA_t_ImagerState_v4;


/*! Type definition for the motion state.*/
typedef struct 
{
  float32               f32_Speed;                                    /*!< [m/s] current vehicle state. */
  float32               f32_Acceleration;                             /*!< [m/s²] longitudinal acceleration */
  float32               f32_YawRateRaw;                               /*!< [rad/s] raw yaw rate (from CAN) */
  float32               f32_YawRate;                                  /*!< [rad/s] estimated vehicle yaw rate (from vdy) */
  float32               f32_YawRateQuality;                           /*!< signal state of current vehicle yaw rate. */
  float32               f32_SteeringAngle;                            /*!< [rad] current steering wheel angle. */
  HLA_t_enum8           e_MoveState;                                  /*!< vehicle motion state e.g. DYN_VHEMOT_STAND_STILL, DYN_VHEMOT_ROLL_FWD,... */
  float32               f32_MoveStateConfidence;                      /*!< confidence of vehicle motion state   */
} HLA_t_MotionState_v1;

typedef struct 
{
  float32               f32_Speed;                                    /*!< [m/s] current vehicle state. */
  float32               f32_Acceleration;                             /*!< [m/s²] longitudinal acceleration */
  float32               f32_YawRateRaw;                               /*!< [rad/s] raw yaw rate (from CAN/ FR), offset compensated */
  float32               f32_YawRate;                                  /*!< [rad/s] estimated vehicle yaw rate (from vdy)  */
  float32               f32_YawRateVariance;                          /*!< Estimated vehicle yaw rate variance (from vdy) */
  float32               f32_YawRateQuality;                           /*!< Estimated vehicle yaw rate quality (from vdy)  */
  float32               f32_SteeringWheelAngle;                       /*!< [rad] current steering wheel angle. */
  float32               f32_SteeringAngle;                            /*!< [rad] current steering angle = steering wheel/ steering ratio */
  HLA_t_enum8           e_MoveState;                                  /*!< vehicle motion state e.g. DYN_VHEMOT_STAND_STILL, DYN_VHEMOT_ROLL_FWD,... */
  float32               f32_MoveStateConfidence;                      /*!< confidence of vehicle motion state   */
} HLA_t_MotionState_v2;

typedef struct 
{
  float32               f32_SpeedDisplay;                             /*!< [m/s] displayed speed (HMI)  */
  float32               f32_Speed;                                    /*!< [m/s] longitudinal velocity. */
  float32               f32_Acceleration;                             /*!< [m/s²] longitudinal acceleration */
  float32               f32_YawRateRaw;                               /*!< [rad/s] raw yaw rate (from CAN/ FR), offset compensated */
  float32               f32_YawRate;                                  /*!< [rad/s] estimated vehicle yaw rate (from vdy)  */
  float32               f32_YawRateVariance;                          /*!< Estimated vehicle yaw rate variance (from vdy) */
  float32               f32_YawRateQuality;                           /*!< Estimated vehicle yaw rate quality (from vdy)  */
  float32               f32_SteeringWheelAngle;                       /*!< [rad] current steering wheel angle. */
  float32               f32_SteeringAngle;                            /*!< [rad] current steering angle = steering wheel/ steering ratio */
  HLA_t_enum8           e_MoveState;                                  /*!< vehicle motion state e.g. DYN_VHEMOT_STAND_STILL, DYN_VHEMOT_ROLL_FWD,... */
  float32               f32_MoveStateConfidence;                      /*!< confidence of vehicle motion state   */
} HLA_t_MotionState_v3;

typedef struct 
{
  float32               f32_SpeedDisplay;                             /*!< [m/s] displayed speed (HMI)  */
  /*!< driving forwards  (e_MoveState == HLA_MOVE_STATE_FWD) -> speed > 0 */
  /*!< driving backwards (e_MoveState == HLA_MOVE_STATE_REV) -> speed < 0 */
  float32               f32_Speed;                                    /*!< [m/s] longitudinal velocity. */
  /*!< driving forwards  (e_MoveState == HLA_MOVE_STATE_FWD) -> speed > 0 */
  /*!< driving backwards (e_MoveState == HLA_MOVE_STATE_REV) -> speed < 0 */
  float32               f32_Acceleration;                             /*!< [m/s²] longitudinal acceleration */
  float32               f32_YawRateRaw;                               /*!< [rad/s] raw yaw rate (from CAN/ FR), offset compensated */
  float32               f32_YawRate;                                  /*!< [rad/s] estimated vehicle yaw rate (from vdy)  */
  float32               f32_YawRateVariance;                          /*!< Estimated vehicle yaw rate variance (from vdy) */
  float32               f32_YawRateQuality;                           /*!< Estimated vehicle yaw rate quality (from vdy)  */
  float32               f32_SteeringWheelAngle;                       /*!< [rad] current steering wheel angle. */
  float32               f32_SteeringAngle;                            /*!< [rad] current steering angle = steering wheel/ steering ratio */
  HLA_t_enum8           e_MoveState;                                  /*!< vehicle motion state e.g. DYN_VHEMOT_STAND_STILL, DYN_VHEMOT_ROLL_FWD,... */
  float32               f32_MoveStateConfidence;                      /*!< confidence of vehicle motion state   */
} HLA_t_MotionState_v4;

/*! Type definition for vehicle level */
typedef struct 
{
  float32 f32_FrontLeft;  /* [m] */
  float32 f32_FrontRight; /* [m] */
  float32 f32_RearLeft;   /* [m] */
  float32 f32_RearRight;  /* [m] */
} HLA_t_VehLevel_v1;

/* Type definition for vehicle data */
typedef struct 
{
  HLA_t_enum8               e_TrafficStyle;                           /*!< local traffic style */
  HLA_t_enum8               e_HeadLightType;                          /*!< head light type */
  HLA_t_enum8               e_WindshieldType;                         /*!< wind shield type */
  boolean                   b_FogLampFront;                           /*!< fog lamps front active*/
  boolean                   b_FogLampRear;                            /*!< fog lamps rear active*/
  boolean                   b_RainSensor;                             /*!< rain sensor state */
  uint8                     ui8_WiperState;                           /*!< wiper state, reported from wiper */
  HLA_t_enum8               e_WiperWasherFrontState;                  /*!< tip-wipe / washer state */
  HLA_t_enum8               e_WiperStage;                             /*!< wiper switch position */
  HLA_t_VehLevel_v1         s_VehicleLevel;                           /*!< current vehcile level */ 
} HLA_t_VehicleState_v1;

/* Type definition for vehicle data */
typedef struct 
{
  boolean                   b_FogLampFront;                           /*!< fog lamps front active*/
  boolean                   b_FogLampRear;                            /*!< fog lamps rear active*/
  boolean                   b_RainSensor;                             /*!< rain sensor state */
  uint8                     ui8_WiperState;                           /*!< wiper state, reported from wiper */
  HLA_t_enum8               e_WiperWasherFrontState;                  /*!< tip-wipe / washer state */
  HLA_t_enum8               e_WiperStage;                             /*!< wiper switch position */
  HLA_t_VehLevel_v1         s_VehicleLevel;                           /*!< current vehcile level */ 
} HLA_t_VehicleState_v2;

typedef struct 
{
  boolean                   b_FogLampFront;                           /*!< fog lamps front active*/
  boolean                   b_FogLampRear;                            /*!< fog lamps rear active*/
  boolean                   b_RainSensor;                             /*!< rain sensor state */
  uint8                     ui8_WiperState;                           /*!< current wiper state, reported from wiper */
  HLA_t_enum8               e_WiperWasherFrontState;                  /*!< tip-wipe / washer state */
  HLA_t_enum8               e_WiperStage;                             /*!< wiper switch position */
  HLA_t_VehLevel_v1         s_VehicleLevel;                           /*!< current vehicle level */
} HLA_t_VehicleState_v3;

/* Type definition for RGB-Lux elements */
typedef struct
{
  float32                     f32_lux;                                  /*!< Access to the lux value. */
  float32                     f32_avgR;                                 /*!< Access to the average red value. */
  float32                     f32_avgG;                                 /*!< Access to the average green value. */
  float32                     f32_avgB;                                 /*!< Access to the average blue value. */
} HLA_t_RGBLuxElement_v1;


/* Type definition for RGB-Lux table */
typedef struct
{
  uint32                    ui32_tableLength;                         /*!< number of valid RGB-Lux elements in the table. */
  HLA_t_RGBLuxElement_v1    as_table[HLA_ui8_MAX_RGBL_ELEM_V1];          /*!< the table with the RGB-Lux elements. */
} HLA_t_CalibratedRGBLuxTable_v1;

typedef struct
{
  uint32  ui32_R1;                                                    /*!< requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;                                                    /*!< requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;                                                  /*!< [us] current integration time T1     */
  float32 f32_T2_us;                                                  /*!< [us] current integration time T2     */
  float32 f32_T3_us;                                                  /*!< [us] current integration time T3     */
  float32 f32_Gain;                                                   /*!< [1]  total gain, depending on temperature */

  uint32                    ui32_tableLength;                         /*!< number of valid RGB-Lux elements in the table. */
  HLA_t_RGBLuxElement_v1    as_table[HLA_ui8_MAX_RGBL_ELEM_V1];          /*!< the table with the RGB-Lux elements. */
} HLA_t_CalibratedRGBLuxTable_v2;

typedef struct
{
  uint32  ui32_R1;                                                    /*!< requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;                                                    /*!< requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;                                                  /*!< [us] current integration time T1     */
  float32 f32_T2_us;                                                  /*!< [us] current integration time T2     */
  float32 f32_T3_us;                                                  /*!< [us] current integration time T3     */
  float32 f32_Gain;                                                   /*!< [1]  total gain, depending on temperature */
  float32 f32_RatioRedGreen;                                          /*!< [1]  Red/ Green ratio      */
  float32 f32_RatioBlueGreen;                                         /*!< [1]  Blue/ Green ratio     */
  float32 f32_RatioGreenRef;                                          /*!< [1]  Green reference ratio */
  
  uint32                    ui32_tableLength;                         /*!< number of valid RGB-Lux elements in the table. */
  HLA_t_RGBLuxElement_v1    as_table[HLA_ui8_MAX_RGBL_ELEM_V1];          /*!< the table with the RGB-Lux elements. */
} HLA_t_CalibratedRGBLuxTable_v3;


/* Type definition for image size */
typedef struct
{
  uint32    ui32_x; /* [pix] image width  */
  uint32    ui32_y; /* [pix] image height */
} HLA_t_ImageSize_v1;

typedef struct
{
  uint32    ui32_x; /* [pix] x position of first cropped Roi pixel (X1) */
  uint32    ui32_y; /* [pix] y position of first cropped Roi pixel (X1) */
} HLA_t_CroppedRoiX_v1;

typedef struct
{
  float32   f32_x;  /* [pix] x-position of the lens center */
  float32   f32_y;  /* [pix] y-position of the lens center */
} HLA_t_LensCenter_v1;


typedef struct
{
  float32   f32_x;  /* [pix] focal length in x-direction */
  float32   f32_y;  /* [pix] focal length in y-direction */
} HLA_t_FocalLength_v1;

/* Type definition for camera distortion parameter */
typedef struct
{
  float32 f32_K1;
  float32 f32_K2;
  float32 f32_K3;
  float32 f32_K4;
  float32 f32_K5; 
} HLA_t_CameraDistortion_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint16 uiBitsPerChannel;
  sint16 iPixelBytes;
  sint32 iRowBytes;
  sint32 iSizeBytes;
  uint16 uiWidth;
  uint16 uiHeight;
  sint8 iScaleX;
  sint8 iScaleY;
  sint16 iOffsetX;
  sint16 iOffsetY;
  uint8 eDataFormat;
  uint16 uiParameterId;
} ImageHeader_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint16 uiBitsPerChannel;
  sint16 iPixelBytes;
  sint32 iRowBytes;
  sint32 iSizeBytes;
  uint16 uiWidth;
  uint16 uiHeight;
  sint8 iScaleX;
  sint8 iScaleY;
  sint16 iOffsetX;
  sint16 iOffsetY;
  uint8 eDataFormat;
  uint16 uiParameterId;
  uint32 uiFingerprint;
} ImageHeader_t_v2;

/* Type definition for camera parameter */
typedef struct
{
  HLA_t_enum8                     e_bayerPattern;                     /*!< Bayer Pattern type */ 
  float32                         f32_cycleTime;                      /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength_v1            s_FocalLength;                      /*!< focal length */ 
  HLA_t_ImageSize_v1              s_ImageSize;                        /*!< total image size */
  HLA_t_ImageSize_v1              s_CroppedRoiSize;                   /*!< cropped roi size */
  HLA_t_CroppedRoiX_v1            s_CroppedRoiX1;                     /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter_v1             s_LensCenter;                       /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable_v1  s_RGBLuxTable;                      /*!< calibrated RGB-Lux table */
  float32                         f32_BlackLevelCalib;                /*!< calibrated blacklevel */
  uint32                          ui32_BitsPerPixel;                  /*!< bits per pixel of imager */  
} HLA_t_CameraParameter_v1;
 
typedef struct
{
  HLA_t_enum8                     e_bayerPattern;                     /*!< Bayer Pattern type */ 
  float32                         f32_cycleTime;                      /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength_v1            s_FocalLength;                      /*!< focal length */ 
  HLA_t_ImageSize_v1              s_ImageSize;                        /*!< total image size */
  HLA_t_ImageSize_v1              s_CroppedRoiSize;                   /*!< cropped roi size */
  HLA_t_CroppedRoiX_v1            s_CroppedRoiX1;                     /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter_v1             s_LensCenter;                       /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable_v2  s_RGBLuxTable;                      /*!< calibrated RGB-Lux table from EOL in Ingolstadt */
  HLA_t_CameraDistortion_v1       s_Distortion;                       /*!< camera distortion parameter */
  uint32                          ui32_BitsPerPixel;                  /*!< bits per pixel of imager */    
} HLA_t_CameraParameter_v2;

typedef struct
{
  HLA_t_enum8                     e_bayerPattern;                     /*!< Bayer Pattern type */ 
  float32                         f32_cycleTime;                      /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength_v1            s_FocalLength;                      /*!< focal length */ 
  HLA_t_ImageSize_v1              s_ImageSize;                        /*!< total image size */
  HLA_t_ImageSize_v1              s_CroppedRoiSize;                   /*!< cropped roi size */
  HLA_t_CroppedRoiX_v1            s_CroppedRoiX1;                     /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter_v1             s_LensCenter;                       /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable_v3  s_RGBLuxTable;                      /*!< calibrated RGB-Lux table from EOL in Ingolstadt */
  HLA_t_CameraDistortion_v1       s_Distortion;                       /*!< camera distortion parameter */
  uint32                          ui32_BitsPerPixel;                  /*!< bits per pixel of imager */    
} HLA_t_CameraParameter_v3;

typedef struct
{
  HLA_t_enum8                     e_bayerPattern;                     /*!< Bayer Pattern type */ 
  float32                         f32_cycleTime;                      /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength_v1            s_FocalLength;                      /*!< focal length */ 
  HLA_t_ImageSize_v1              s_ImageSize;                        /*!< total image size */
  HLA_t_ImageSize_v1              s_CroppedRoiSize;                   /*!< cropped roi size */
  HLA_t_CroppedRoiX_v1            s_CroppedRoiX1;                     /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter_v1             s_LensCenter;                       /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable_v3  s_RGBLuxTable;                      /*!< calibrated RGB-Lux table from EOL in Ingolstadt */
  HLA_t_CameraDistortion_v1       s_Distortion;                       /*!< camera distortion parameter */
  uint32                          ui32_BitsPerPixel;                  /*!< bits per pixel of imager */    
} HLA_t_CameraParameter_v4;

typedef struct
{
  HLA_t_enum8                     e_bayerPattern;                     /*!< Bayer Pattern type */ 
  float32                         f32_cycleTime;                      /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength_v1            s_FocalLength;                      /*!< focal length */ 
  HLA_t_ImageSize_v1              s_ImageSize;                        /*!< total image size */
  HLA_t_ImageSize_v1              s_CroppedRoiSize;                   /*!< cropped roi size */
  HLA_t_CroppedRoiX_v1            s_CroppedRoiX1;                     /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter_v1             s_LensCenter;                       /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable_v3  s_RGBLuxTable;                      /*!< calibrated RGB-Lux table from EOL in Ingolstadt */
  HLA_t_CameraDistortion_v1       s_Distortion;                       /*!< camera distortion parameter */
  ImageHeader_t_v1                s_ImageHeader;                      /*!< BitsPerPixel, BytesPerRow, ... */
} HLA_t_CameraParameter_v5;

typedef struct
{
  HLA_t_enum8                     e_bayerPattern;                     /*!< Bayer Pattern type */ 
  float32                         f32_cycleTime;                      /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength_v1            s_FocalLength;                      /*!< focal length */ 
  HLA_t_ImageSize_v1              s_ImageSize;                        /*!< total image size */
  HLA_t_ImageSize_v1              s_CroppedRoiSize;                   /*!< cropped roi size */
  HLA_t_CroppedRoiX_v1            s_CroppedRoiX1;                     /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter_v1             s_LensCenter;                       /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable_v3  s_RGBLuxTable;                      /*!< calibrated RGB-Lux table from EOL in Ingolstadt */
  HLA_t_CameraDistortion_v1       s_Distortion;                       /*!< camera distortion parameter */
  ImageHeader_t_v2                s_ImageHeader;                      /*!< BitsPerPixel, BytesPerRow, ... */
} HLA_t_CameraParameter_v6;

/*! Type definition for vehicle parameters */
typedef struct 
{
  float32               f32_TrackWidthFront_m;                        /*!< [m] track width front */
  float32               f32_TrackWidthRear_m;                         /*!< [m] track width rear  */
  float32               f32_WheelBase_m;                              /*!< [m] wheel base        */
  HLA_t_VehLevel_v1     s_VehLevEOLCali;                              /*!< vehicle level at EOL/ service calibration */
} HLA_t_VehicleParameter_v1;

/*! Type definition for vehicle parameters (variant coding (scn)) */
typedef struct 
{
  float32                   f32_TrackWidthFront_m;                    /*!< [m] track width front */
  float32                   f32_TrackWidthRear_m;                     /*!< [m] track width rear  */
  float32                   f32_WheelBase_m;                          /*!< [m] wheel base        */
  HLA_t_VehLevel_v1         s_VehLevEOLCali;                          /*!< vehicle level at EOL/ service calibration */

  HLA_t_enum8               e_TrafficStyle;                           /*!< local traffic style (left/ right hand traffic)               */
  HLA_t_enum8               e_HeadLightType;                          /*!< head light type (Xeneon, halogene, LED, Pixel)               */
  HLA_t_enum8               e_HeadLightMechanics;                     /*!< head light mechanics (roller, aperture, none = pixel light)  */
  HLA_t_enum8               e_HeadLightMode;                          /*!< head light mode (light, standard, plus, standard and plus)   */
  HLA_t_enum8               e_SpotLight;                              /*!< spot light installed (avl, not avl)                          */
  HLA_t_enum8               e_WindshieldType;                         /*!< wind shield type (clear , green , blue)                      */

  float32                   f32_SpotLightWidth_rad;                   /*!< [rad] spot light width                 */
  float32                   f32_FullHBDefaultPos_Left_rad;            /*!< [rad] full high beam default position, related to part HB cut off angle */
  float32                   f32_FullHBDefaultPos_Right_rad;           /*!< [rad] full high beam default position, related to part HB cut off angle */
} HLA_t_VehicleParameter_v2;

typedef struct 
{
  float32                   f32_TrackWidthFront_m;                    /*!< [m] track width front */
  float32                   f32_TrackWidthRear_m;                     /*!< [m] track width rear  */
  float32                   f32_WheelBase_m;                          /*!< [m] wheel base        */
  HLA_t_VehLevel_v1         s_VehLevEOLCali;                          /*!< vehicle level at EOL/ service calibration */

  HLA_t_enum8               e_TrafficStyle;                           /*!< local traffic style (left/ right hand traffic)               */
  HLA_t_enum8               e_HeadLightType;                          /*!< head light type (Xeneon, halogene, LED, Pixel)               */
  HLA_t_enum8               e_HeadLightMechanics;                     /*!< head light mechanics (roller, aperture, none = pixel light)  */
  HLA_t_enum8               e_HeadLightMode;                          /*!< head light mode (light, standard, plus, standard and plus)   */
  HLA_t_enum8               e_SpotLight;                              /*!< spot light installed (avl, not avl)                          */
  HLA_t_enum8               e_WindshieldType;                         /*!< wind shield type (clear , green , blue)                      */

  float32                   f32_SpotLightWidth_rad;                   /*!< [rad] spot light width                 */
  float32                   f32_FullHBDefaultPos_Left_rad;            /*!< [rad] full high beam default position, related to part HB cut off angle */
  float32                   f32_FullHBDefaultPos_Right_rad;           /*!< [rad] full high beam default position, related to part HB cut off angle */
  float32                   f32_HeadLampLatency_s;                    /*!< latency (seconds) which consists of CAN/Flexray signaling runtime and 
                                                                           processing time of the head lamp controller */
  float32                   f32_SpotLightTolerance_rad;               /*!< [rad] additional tolerance to the spot light width which defines the 
                                                                           safety area for the night view blinking spot light */
} HLA_t_VehicleParameter_v3;

typedef struct 
{
  float32                    f32_TrackWidthFront_m;                   /*!< [m] track width front */
  float32                    f32_TrackWidthRear_m;                    /*!< [m] track width rear  */
  float32                    f32_WheelBase_m;                         /*!< [m] wheel base        */
} HLA_t_VehicleParameter_v4;

/*! Type definition for calibration data */
typedef struct  
{
  float32                               f32_Pitch;                    /*!< Pitch angle */
  float32                               f32_Roll;                     /*!< Roll angle */
  float32                               f32_Yaw;                      /*!< Yaw angle */
  float32                               f32_Quality;                  /*!< calibration quality: <2.55°: OK, =2.55°: NOK */
} HLA_t_SensorAngles_v1;

typedef struct  
{
  float32                               f32_Pitch;                    /*!< Pitch angle */
  float32                               f32_Roll;                     /*!< Roll angle */
  float32                               f32_Yaw;                      /*!< Yaw angle */
  float32                               f32_Quality;                  /*!< calibration quality: <2.55°: OK, =2.55°: NOK */
  HLA_t_enum8                           e_caliState;                  /*!< degree of absolute deviation of calibration */
} HLA_t_SensorAngles_v2;

/*! Type definition for sensor socket data */
typedef struct
{
  float32           f32_Z;         /*! Height over ground */
  float32           f32_Y;         /*! Offset lateral */
  float32           f32_X;         /*! Offset longitudinal */
} HLA_t_SensorSocket_v1;

/*! Type definition for sensor angles */
typedef struct
{
  /* definition of the function roi: */
  /* only in the function ROI HLA detects vehicles and the high beam will be swichted off */
  /* lights above the function roi could be streetlamps but no relevant vehicle */
  
  float32   f32_FOV_Horizontal_rad;                                   /*!< [rad] horizontal field of view (+/-18° = 36°) */
  
  float32   f32_FOV_FunctionRoiAboveHorizon_rad;                      /*!< [rad] Field of view for the function roi above the horizon (atan(0.95/(1.16+13) = 3.83° -> 4.0°)) */  
  float32   f32_FOV_MinBelowHorizon_rad;                              /*!< [rad] minimum field of view below the horizon (= FOV_FunctionRoiAboveHorizon_rad) */
  float32   f32_FOV_MinAboveHorizon_rad;                              /*!< [rad] minimum field of view above the horizon (= FOV_FunctionRoiAboveHorizon_rad + 3° = 6.83°) */
  
  /* point on the road defines the FOV below the horizon */
  float32   f32_minDistance_m;                                        /*!< [m] minimum distance on the road (measured from front axis) which could be seen in the HLA ROI */
  
  /* leaving street lamps defines the FOV above the horizon */
  float32   f32_StreetLamp_Distance_m;                                /*!< [m] leaving streep lamp distance from front axis (= 60m) */
  float32   f32_StreetLamp_Height_m;                                  /*!< [m] leaving streep lamp height over ground (= 6m) */
} HLA_t_RoiParameter_v1;

/*! Type definition for sensor angles */
typedef struct
{
  /* definition of the function roi: */
  /* only in the function ROI HLA detects vehicles and the high beam will be swichted off */
  /* lights above the function roi could be streetlamps but no relevant vehicle */
  
  float32   f32_FOV_Horizontal_rad;                                   /*!< [rad] horizontal field of view (+/-18° = 36°) */
  
  float32   f32_FOV_FunctionRoiAboveHorizon_rad;                      /*!< [rad] Field of view for the function roi above the horizon (atan(0.95/(1.16+13) = 3.83° -> 4.0°)) */  
  float32   f32_FOV_MinBelowHorizon_rad;                              /*!< [rad] minimum field of view below the horizon (= FOV_FunctionRoiAboveHorizon_rad) */
  float32   f32_FOV_MinAboveHorizon_rad;                              /*!< [rad] minimum field of view above the horizon (= FOV_FunctionRoiAboveHorizon_rad + 3° = 6.83°) */
  
  /* rear light position (minDistance, minHeight) of a preceding car defines the lower boundary of the ROI */
  float32   f32_minDistance_m;                                        /*!< [m] minDistance to the rear lights is measured from the bumper (not according to AUTOSAR),
                                                                               default value = 4.1m for E-Class, 2.9m for Sprinter */
  float32   f32_minHeight_m;                                          /*!< [m] minHeight of the rear lights is measured from the ground,
                                                                               default value = 0.7m (typical car) */
  
  /* leaving street lamps defines the FOV above the horizon */
  float32   f32_StreetLamp_Distance_m;                                /*!< [m] leaving streep lamp distance from front axis (= 30m)             */
  float32   f32_StreetLamp_Height_m;                                  /*!< [m] leaving streep lamp height over ground (= 6m)                    */
} HLA_t_RoiParameter_v2;

typedef struct  
{
  float32              f32_Distance;                                  /*!< [m] object distance, measured from front axis                          */
  float32              f32_HorAngle;                                  /*!< [rad] horizontal object angle in world (Autosar)                       */
  float32              f32_HorAngle_Cam;                              /*!< [rad] horizontal object angle with respect to camera coordinate system */
  float32              f32_VerAngle_Cam;                              /*!< [rad] vertical   object angle with respect to camera coordinate system */

  uint8                ui8_ExistenceProb;                             /*!< [%] existence probability of vehicle(s) in the GFA */

  HLA_t_enum8         e_Status;                                      /*!< object status (no object detected, unknown driving direction, oncoming veh., preceding veh.) */
  HLA_t_enum8         e_Type;                                        /*!< object type (no object detected, unknown type, car, truck or motorcycle */
}HLAF_t_ClosestVeh_t_v1;

/*! Type definition for HLA plus output data */
typedef struct
{
  /* environment data */
  HLA_t_enum8               e_TrafficStyle;                           /*!< HLA right/left hand traffic style */
  HLA_t_enum8               e_CityState;                              /*!< HLA city detection */
  HLA_t_enum8               e_WeatherState;                           /*!< HLA weather detection */
  HLA_t_enum8               e_TunnelState;                            /*!< HLA tunnel detection */
  HLA_t_enum8               e_MotorwayState;                          /*!< HLA motorway detection */
  HLA_t_enum8               e_BrightnessState;                        /*!< HLA signal "Outside Brightness State" */

  /* closest vehicle data (on own lane) */
  HLAF_t_ClosestVeh_t_v1    s_ClosestVeh;                             /*!< HLA data of closest vehicle, independent of lane */
  HLAF_t_ClosestVeh_t_v1    s_ClosestVehOwnLane;                      /*!< HLA data of closest vehicle on own lane */

  HLA_t_enum8               e_SpeedState;                             /*!< HLA Speed state */
} HLAF_t_HeadlightControl_Common_v1;

/*! Type definition for HLA plus output data */
typedef struct
{
  /* environment data */
  HLA_t_enum8     e_TrafficStyle;                           /*!< HLA right/left hand traffic style */
  HLA_t_enum8     e_CityState;                              /*!< HLA city detection */
  HLA_t_enum8     e_WeatherState;                           /*!< HLA weather detection */
  HLA_t_enum8     e_TunnelState;                            /*!< HLA tunnel detection */
  HLA_t_enum8     e_MotorwayState;                          /*!< HLA motorway detection */
  HLA_t_enum8     e_BrightnessState;                        /*!< HLA signal "Outside Brightness State" */

  /* closest vehicle data (on own lane) */
  HLAF_t_ClosestVeh_t_v1    s_ClosestVeh;                             /*!< HLA data of closest vehicle, independent of lane */
  HLAF_t_ClosestVeh_t_v1    s_ClosestVehOwnLane;                      /*!< HLA data of closest vehicle on own lane */

  HLA_t_enum8       e_SpeedState;                             /*!< HLA Speed state */
} HLAF_t_HeadlightControl_Common_v2;

/*! Type definition for HLA plus output data */
typedef struct
{
  /* environment data */
  HLA_t_enum8    e_TrafficStyle;                           /*!< HLA right/left hand traffic style */
  HLA_t_enum8    e_CityState;                              /*!< HLA city detection */
  HLA_t_enum8    e_WeatherState;                           /*!< HLA weather detection */
  HLA_t_enum8    e_TunnelState;                            /*!< HLA tunnel detection */
  HLA_t_enum8    e_MotorwayState;                          /*!< HLA motorway detection */
  HLA_t_enum8    e_BrightnessState;                        /*!< HLA signal "Outside Brightness State" */

  /* closest vehicle data (on own lane) */
  HLAF_t_ClosestVeh_t_v1    s_ClosestVeh;                             /*!< HLA data of closest vehicle, independent of lane */
  HLAF_t_ClosestVeh_t_v1    s_ClosestVehOwnLane;                      /*!< HLA data of closest vehicle on own lane */

  HLA_t_enum8       e_SpeedState;                             /*!< HLA Speed state */
  HLA_t_enum8       e_RuntimeState;                           /*!< HLA runtime time, e.g. reached runtime limit */
} HLAF_t_HeadlightControl_Common_v3;

/*! Type definition for HLA plus, standard and light output data */
typedef struct
{
  /* HLA Light, Standard, Plus (Common outputs) */
  HLA_t_enum8               e_LevelState;                             /*!< HLA optical headlight leveling state (on: hla active, off: hla not avl, too bright, not calibrated) */
  HLA_t_enum8               e_HighBeamState;                          /*!< HLA high beam state */
  HLA_t_fLightDistance      f32_LowBeamDist;                          /*!< HLA low beam distance, autosar coordinate system */
  HLA_t_fLightAngle         f32_LowBeamAngle;                         /*!< HLA low beam object angle, autosar coordinate system */
  HLA_t_enum8               LowBeam_Status;
  /* change over speed from HB off to full HB or full HB to off */
  uint8                     ui8_ChangeoverLevel;                      /*!< [0..15] HLA changeover level */
  HLA_t_enum8               e_LightOutput_Lt;                         /*!< HLA plus signal "headlamp left light output" */
  HLA_t_enum8               e_LightOutput_Rt;                         /*!< HLA plus signal "headlamp right light output" */

  /* HLA Plus */
  float32                   f32_RotAngleMin_Lt;                       /*!< HLA plus signal "headlamp left rotation angle min" [°], autosar coordinate system  */
  float32                   f32_RotAngleMin_Rt;                       /*!< HLA plus signal "headlamp right rotation angle min" [°], autosar coordinate system */
  HLA_t_enum8               e_HighBeamState_Lt;                       /*!< HLA plus signal "high beam left state" */
  HLA_t_enum8               e_HighBeamState_Rt;                       /*!< HLA plus signal "high beam right state" */
  /* change over speed from partial HB to full HB, off to full, full to partial, ... */
  uint8  ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< [0..7] HLA plus changeover level for left partial HB  */
  uint8  ui8_HLAPlus_ChangeoverLevel_Rt;           /*!< [0..7] HLA plus changeover level for right partial HB */
} HLA_t_HeadlightControl_PlusStdLight_v1;

/*! Type definition for HLA plus, standard and light output data */
typedef struct
{
  /* HLA Light, Standard, Plus (Common outputs) */
  HLA_t_enum8       e_LevelState;                             /*!< HLA optical headlight leveling state (on: hla active, off: hla not avl, too bright, not calibrated) */
  HLA_t_enum8     e_HighBeamState;                          /*!< HLA high beam state */
  HLA_t_fLightDistance      f32_LowBeamDist;                          /*!< HLA low beam distance, autosar coordinate system */
  HLA_t_fLightAngle         f32_LowBeamAngle;                         /*!< HLA low beam object angle, autosar coordinate system */
  HLA_t_enum8        LowBeam_Status;
  /* change over speed from HB off to full HB or full HB to off */
  uint8                     ui8_ChangeoverLevel;                      /*!< [0..15] HLA changeover level */
  HLA_t_enum8      e_LightOutput_Lt;                         /*!< HLA plus signal "headlamp left light output" */
  HLA_t_enum8      e_LightOutput_Rt;                         /*!< HLA plus signal "headlamp right light output" */

  /* HLA Plus */
  float32                   f32_RotAngleMin_Lt;                       /*!< HLA plus signal "headlamp left rotation angle min" [°], autosar coordinate system  */
  float32                   f32_RotAngleMin_Rt;                       /*!< HLA plus signal "headlamp right rotation angle min" [°], autosar coordinate system */
  HLA_t_enum8     e_HighBeamState_Lt;                       /*!< HLA plus signal "high beam left state" */
  HLA_t_enum8     e_HighBeamState_Rt;                       /*!< HLA plus signal "high beam right state" */
  /* change over speed from partial HB to full HB, off to full, full to partial, ... */
  uint8                   ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< [0..7] HLA plus changeover level for left partial HB  */
  uint8                   ui8_HLAPlus_ChangeoverLevel_Rt;           /*!< [0..7] HLA plus changeover level for right partial HB */
} HLA_t_HeadlightControl_PlusStdLight_v2;

typedef struct
{
  float32 BndryLeft_Ang;
  float32 BndryRight_Ang;
  float32 BndryLeft_Ang_Cam;
  float32 BndryRight_Ang_Cam;
  float32 BndryLower_Ang_Cam;
  float32 ClosestObj_Dist;
  float32 ClosestObj_Ang;
  float32 MinLight_Dist;
  float32 MinLight_Ang;
  float32 ttb18Left;
  float32 ttb18Right;
  HLA_t_enum8 BndryLeft_Status;
  HLA_t_enum8 BndryRight_Status;
  HLA_t_enum8 BndryLower_Status;
  HLA_t_enum8 ClosestObj_Status;
  HLA_t_enum8 MinLight_Status;
  HLA_t_enum8 ttb18Left_Status;
  HLA_t_enum8 ttb18Right_Status;
  uint8 ExistenceProb;
} HLAF_t_MatrixGFA_v1;

typedef struct
{
  float32 BndryLeft_Ang;
  float32 BndryRight_Ang;
  float32 BndryLeft_Ang_Cam;
  float32 BndryRight_Ang_Cam;
  float32 BndryLower_Ang_Cam;
  float32 ClosestObj_Dist;
  float32 ClosestObj_Ang;
  float32 MinLight_Dist;
  float32 MinLight_Ang;
  float32 ttb18Left;
  float32 ttb18Right;
  HLA_t_enum8 BndryLeft_Status;
  HLA_t_enum8 BndryRight_Status;
  HLA_t_enum8 BndryLower_Status;
  HLA_t_enum8 ClosestObj_Status;
  HLA_t_enum8 MinLight_Status;
  HLA_t_enum8 ttb18Left_Status;
  HLA_t_enum8 ttb18Right_Status;
  uint8 ExistenceProb;
} HLAF_t_MatrixGFA_v2;

typedef struct
{
  float32 BndryLeft_Ang;
  float32 BndryLeft_Dist;
  float32 BndryLeft_Ang_Cam;
  
  float32 BndryRight_Ang;
  float32 BndryRight_Dist;
  float32 BndryRight_Ang_Cam;
  
  float32 BndryLower_Ang_Cam;
  float32 ClosestObj_Dist;
  float32 ClosestObj_Ang;

  float32 MinLight_Dist;
  float32 MinLight_Ang;
  float32 ttb18Left;
  float32 ttb18Right;
  HLA_t_enum8 BndryLeft_Status;
  HLA_t_enum8 BndryRight_Status;
  HLA_t_enum8 BndryLower_Status;
  HLA_t_enum8 ClosestObj_Status;
  HLA_t_enum8 MinLight_Status;
  HLA_t_enum8 ttb18Left_Status;
  HLA_t_enum8 ttb18Right_Status;
  uint8 ExistenceProb;
} HLAF_t_MatrixGFA_v3;

typedef struct
{
  ARRAY(HLAF_t_MatrixGFA_v1, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS_V1, GFA);
  uint32                nGFA;
  HLA_t_enum8           GFAStatus;
  HLA_t_enum8           HighBeamState;
  float32               LowBeam_Dist;
  float32               LowBeam_Ang;
  HLA_t_enum8           LowBeam_Status;
  HLA_t_enum32          TurnOffReason;
} HLAF_t_Matrix_v1;

typedef struct
{
  ARRAY(HLAF_t_MatrixGFA_v2, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS_V1, GFA);
  uint32                nGFA;
  HLA_t_enum8           GFAStatus;
  HLA_t_enum8           HighBeamState;
  float32               LowBeam_Dist;
  float32               LowBeam_Ang;
  HLA_t_enum8           LowBeam_Status;
  HLA_t_enum32          TurnOffReason;
} HLAF_t_Matrix_v2;

typedef struct
{
  ARRAY(HLAF_t_MatrixGFA_v3, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS_V1, GFA);
  uint32                       nGFA;
  HLA_t_enum8        GFAStatus;
  HLA_t_enum8        HighBeamState;
  float32                      LowBeam_Dist;
  float32                      LowBeam_Ang;
  HLA_t_enum8           LowBeam_Status;
  HLA_t_enum32 TurnOffReason;
} HLAF_t_Matrix_v3;

typedef struct  
{
  HLA_t_enum8 AvailabilityState;
  HLA_t_enum8    DetectionState;
  float32                              ObjectDist;
  HLA_t_enum8       ObjectType;
  HLA_t_enum8      ObjectLightState;
} HLAF_EcoLight_RTE_v1;

typedef struct 
{
  float32              BndryLeft_Ang_Cam;
  float32              BndryRight_Ang_Cam;
  float32              BndryLower_Ang_Cam;
  HLA_t_enum8          LightOutput;
} HLAF_DimmingArea_RTE_v1;

typedef struct
{
  ARRAY(HLAF_DimmingArea_RTE_v1, RTE_HLAF_MATRIX_MAX_DIMMING_AREAS_V1, DimmingArea);
  HLA_t_enum8 DimmingStatus;
  uint32                 nDimmingArea;
} HLAF_LightDimming_RTE_v1;

/*! Type definition for HLA output data */
typedef struct
{
  /* HLA/ HLA plus signals */
  HLA_t_enum8               e_State;                                  /*!< Access to HLA control state */
  uint8                    ui8_EnvironmentBrightness;                 /*!< Access to HLA outside brightness */
  HLA_t_enum8               e_TrafficStyle;                           /*!< Access to HLA right/left hand traffic style */
  HLA_t_enum8               e_LevelState;                             /*!< Access to HLA optical headlight leveling state */
  HLA_t_enum8               e_HighBeamState;                          /*!< Access to HLA high beam state */
  HLA_t_fLightDistance      f32_LowBeamDist;                          /*!< Access to HLA low beam distance */
  HLA_t_fLightAngle         f32_LowBeamAngle;                         /*!< Access to HLA low beam object angle */
  uint8  ui8_ChangeoverLevel;                      /*!< Access to HLA changeover level */
  HLA_t_enum8               e_TargetDrivingDirection;                 /*!< Access to HLA driving direction */
  HLA_t_enum8               e_CityState;                              /*!< Access to HLA city detection */
  HLA_t_enum8               e_WeatherState;                           /*!< Access to HLA weather detection */
  HLA_t_enum8               e_TunnelState;                            /*!< Access to HLA tunnel detection */
  HLA_t_enum8               e_MotorwayState;                          /*!< Access to HLA motorway detection */
  HLA_t_enum8               e_BrightnessState;                        /*!< Access to HLA signal "Outside Brightness State" */
  /* HLA plus signals */
  float32                   f32_RotAngleMin_Lt;                       /*!< Access to HLA plus signal "headlamp left rotation angle min" [°] */
  float32                   f32_RotAngleMin_Rt;                       /*!< Access to HLA plus signal "headlamp right rotation angle min" [°] */
  HLA_t_enum8               e_LightOutput_Lt;                         /*!< Access to HLA plus signal "headlamp left light output" */
  HLA_t_enum8               e_LightOutput_Rt;                         /*!< Access to HLA plus signal "headlamp right light output" */
  HLA_t_enum8               e_HighBeamState_Lt;                       /*!< Access to HLA plus signal "high beam left state" */
  HLA_t_enum8               e_HighBeamState_Rt;                       /*!< Access to HLA plus signal "high beam right state" */
  uint8  ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< Access to HLA plus changeover level left  */
  uint8  ui8_HLAPlus_ChangeoverLevel_Rt;           /*!< Access to HLA plus changeover level right */
} HLA_t_HeadlightControl_v1;

typedef struct
{
  /* HLA/ HLA plus signals */
  HLA_t_enum8               e_State;                                  /*!< Access to HLA control state */
  HLA_t_enum8               e_TrafficStyle;                           /*!< Access to HLA right/left hand traffic style */
  HLA_t_enum8               e_LevelState;                             /*!< Access to HLA optical headlight leveling state */
  HLA_t_enum8               e_HighBeamState;                          /*!< Access to HLA high beam state */
  HLA_t_fLightDistance      f32_LowBeamDist;                          /*!< Access to HLA low beam distance */
  HLA_t_fLightAngle         f32_LowBeamAngle;                         /*!< Access to HLA low beam object angle */
  uint8  ui8_ChangeoverLevel;                      /*!< Access to HLA changeover level */
  HLA_t_enum8               e_TargetDrivingDirection;                 /*!< Access to HLA driving direction */
  HLA_t_enum8               e_CityState;                              /*!< Access to HLA city detection */
  HLA_t_enum8               e_WeatherState;                           /*!< Access to HLA weather detection */
  HLA_t_enum8               e_TunnelState;                            /*!< Access to HLA tunnel detection */
  HLA_t_enum8               e_MotorwayState;                          /*!< Access to HLA motorway detection */
  HLA_t_enum8               e_BrightnessState;                        /*!< Access to HLA signal "Outside Brightness State" */
  /* HLA plus signals */
  float32                   f32_RotAngleMin_Lt;                       /*!< Access to HLA plus signal "headlamp left rotation angle min" [°] */
  float32                   f32_RotAngleMin_Rt;                       /*!< Access to HLA plus signal "headlamp right rotation angle min" [°] */
  HLA_t_enum8               e_LightOutput_Lt;                         /*!< Access to HLA plus signal "headlamp left light output" */
  HLA_t_enum8               e_LightOutput_Rt;                         /*!< Access to HLA plus signal "headlamp right light output" */
  HLA_t_enum8               e_HighBeamState_Lt;                       /*!< Access to HLA plus signal "high beam left state" */
  HLA_t_enum8               e_HighBeamState_Rt;                       /*!< Access to HLA plus signal "high beam right state" */
  uint8  ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< Access to HLA plus changeover level left  */
  uint8  ui8_HLAPlus_ChangeoverLevel_Rt;           /*!< Access to HLA plus changeover level right */
} HLA_t_HeadlightControl_v2;

typedef struct
{
  /* HLA/ HLA plus signals */
  HLA_t_enum8               e_State;                                  /*!< Access to HLA control state */
  HLA_t_enum8               e_Type;                                   /*!< Access to HLA type e.g. Standard, Plus, Light, not available */
  HLA_t_enum8               e_TrafficStyle;                           /*!< Access to HLA right/left hand traffic style */
  HLA_t_enum8               e_LevelState;                             /*!< Access to HLA optical headlight leveling state */
  HLA_t_enum8               e_HighBeamState;                          /*!< Access to HLA high beam state */
  HLA_t_fLightDistance      f32_LowBeamDist;                          /*!< Access to HLA low beam distance */
  HLA_t_fLightAngle         f32_LowBeamAngle;                         /*!< Access to HLA low beam object angle */
  uint8  ui8_ChangeoverLevel;                      /*!< Access to HLA changeover level */
  HLA_t_enum8               e_TargetDrivingDirection;                 /*!< Access to HLA driving direction */
  HLA_t_enum8               e_CityState;                              /*!< Access to HLA city detection */
  HLA_t_enum8               e_WeatherState;                           /*!< Access to HLA weather detection */
  HLA_t_enum8               e_TunnelState;                            /*!< Access to HLA tunnel detection */
  HLA_t_enum8               e_MotorwayState;                          /*!< Access to HLA motorway detection */
  HLA_t_enum8               e_BrightnessState;                        /*!< Access to HLA signal "Outside Brightness State" */
  /* HLA plus signals */
  float32                   f32_RotAngleMin_Lt;                       /*!< Access to HLA plus signal "headlamp left rotation angle min" [°] */
  float32                   f32_RotAngleMin_Rt;                       /*!< Access to HLA plus signal "headlamp right rotation angle min" [°] */
  HLA_t_enum8               e_LightOutput_Lt;                         /*!< Access to HLA plus signal "headlamp left light output" */
  HLA_t_enum8               e_LightOutput_Rt;                         /*!< Access to HLA plus signal "headlamp right light output" */
  HLA_t_enum8               e_HighBeamState_Lt;                       /*!< Access to HLA plus signal "high beam left state" */
  HLA_t_enum8               e_HighBeamState_Rt;                       /*!< Access to HLA plus signal "high beam right state" */
  uint8  ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< Access to HLA plus changeover level left  */
  uint8  ui8_HLAPlus_ChangeoverLevel_Rt;           /*!< Access to HLA plus changeover level right */
} HLA_t_HeadlightControl_v3;

typedef struct
{
  /* HLA State and Type */
  HLA_t_enum8              e_State;                                   /*!< Access to HLA control state */
  HLA_t_enum8              e_Type;                                    /*!< Access to HLA type e.g. Standard, Plus, Light, not available */

  /* common signals */
  HLA_t_enum8         e_TrafficStyle;                                 /*!< Access to HLA right/left hand traffic style */
  HLA_t_enum8         e_CityState;                                    /*!< Access to HLA city detection */
  HLA_t_enum8         e_WeatherState;                                 /*!< Access to HLA weather detection */
  HLA_t_enum8         e_TunnelState;                                  /*!< Access to HLA tunnel detection */
  HLA_t_enum8         e_MotorwayState;                                /*!< Access to HLA motorway detection */
  HLA_t_enum8         e_BrightnessState;                              /*!< Access to HLA signal "Outside Brightness State" */
  HLA_t_enum8 e_SpeedState;                                   /*!< HLA Speed state */


  /* HLA plus, standard and light signals */
  HLA_t_enum8               e_LevelState;                             /*!< Access to HLA optical headlight leveling state */
  HLA_t_enum8               e_HighBeamState;                          /*!< Access to HLA high beam state */
  HLA_t_fLightDistance      f32_LowBeamDist;                          /*!< Access to HLA low beam distance */
  HLA_t_fLightAngle         f32_LowBeamAngle;                         /*!< Access to HLA low beam object angle */    
  HLA_t_enum8               e_TargetDrivingDirection;                 /*!< Access to HLA driving direction */
  uint8  ui8_ChangeoverLevel;                      /*!< Access to HLA changeover level */
  HLA_t_enum8               e_LightOutput_Lt;                         /*!< Access to HLA plus signal "headlamp left light output" */
  HLA_t_enum8               e_LightOutput_Rt;                         /*!< Access to HLA plus signal "headlamp right light output" */
  float32                   f32_RotAngleMin_Lt;                       /*!< Access to HLA plus signal "headlamp left rotation angle min" [°] */
  float32                   f32_RotAngleMin_Rt;                       /*!< Access to HLA plus signal "headlamp right rotation angle min" [°] */
  HLA_t_enum8               e_HighBeamState_Lt;                       /*!< Access to HLA plus signal "high beam left state" */
  HLA_t_enum8               e_HighBeamState_Rt;                       /*!< Access to HLA plus signal "high beam right state" */
  uint8  ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< Access to HLA plus changeover level left  */
  uint8  ui8_HLAPlus_ChangeoverLevel_Rt;           /*!< Access to HLA plus changeover level right */

  /* HLA matrix beam */
  HLAF_t_Matrix_v1 Matrix;
} HLA_t_HeadlightControl_v4;

typedef struct
{
  /* hla state and type */
  HLA_t_enum8                             e_State;                    /*!< HLA control state e.g. not available, idle, activated, temporarily not available */
  HLA_t_enum8                             e_Type;                     /*!< HLA type e.g. Standard, Plus, Light, not available */
  HLAF_t_HeadlightControl_Common_v1       s_Common;                   /*!< common hlaf output signals like: city, highway, brightness, traffic style or tunnel detection*/
  HLA_t_HeadlightControl_PlusStdLight_v1  s_PlusStdLight;             /*!< HLA Plus, Standard, Light output data */
  HLAF_t_Matrix_v2                        Matrix;                     /*!< HLA Matrix beam signals (glare free areas (GFA)) */
} HLA_t_HeadlightControl_v5;

typedef struct
{
  /* hla state and type */
  HLA_t_enum8                           e_State;                    /*!< HLA control state e.g. not available, idle, activated, temporarily not available */
  HLA_t_enum8                            e_Type;                     /*!< HLA type e.g. Standard, Plus, Light, not available */
  HLAF_t_HeadlightControl_Common_v2       s_Common;                   /*!< common hlaf output signals like: city, highway, brightness, traffic style or tunnel detection*/
  HLA_t_HeadlightControl_PlusStdLight_v2  s_PlusStdLight;             /*!< HLA Plus, Standard, Light output data */
  HLAF_t_Matrix_v3                        Matrix;                     /*!< HLA Matrix beam signals (glare free areas (GFA)) */
} HLA_t_HeadlightControl_v6;

typedef struct
{
  /* hla state and type */
  HLA_t_enum8                           e_State;                    /*!< HLA control state e.g. not available, idle, activated, temporarily not available */
  HLA_t_enum8                            e_Type;                     /*!< HLA type e.g. Standard, Plus, Light, not available */
  HLAF_t_HeadlightControl_Common_v3       s_Common;                   /*!< common hlaf output signals like: city, highway, brightness, traffic style or tunnel detection*/
  HLA_t_HeadlightControl_PlusStdLight_v2  s_PlusStdLight;             /*!< HLA Plus, Standard, Light output data */
  HLAF_t_Matrix_v3                        Matrix;                     /*!< HLA Matrix beam signals (glare free areas (GFA)) */
  HLAF_EcoLight_RTE_v1                    s_EcoLight;                 /*!< Eco light signals */
  HLAF_LightDimming_RTE_v1                s_Dimming;                  /*!< Light Dimming Area signals */
} HLA_t_HeadlightControl_v7;


/*! Type definition for the last exit/reset reason. */
typedef struct 
{
  HLA_t_enum8               e_LastExitReason;
  uint32                    ui32_iSamplingAborted;
  uint32                    ui32_iMainTimeout;
  uint32                    ui32_hlaTmpNavlCount;
  uint32                    ui32_ExitReasonActive;
  uint32                    ui32_iTimeOutSerial;
  float32                   f32_dTimeInit_ms;
  float32                   f32_dTimeMain_ms;
  float32                   f32_dTimeMainMax_ms;
  float32                   f32_dTimeSegDoIt_ms;
  float32                   f32_dTimeSegDoItMax_ms;
  float32                   f32_dTimeSegExit_ms;
  float32                   f32_dTimeSegExitMax_ms;
  sint32                    si32_FrameNumber;
  sint32                    si32_FrameNumberMax;
  sint32                    si32_dFrameNumber;
  sint32                    si32_dFrameNumberMax;
} HLA_t_ExitReason_v1;


/*! Type definition for HLA blockage output */
typedef struct
{
  boolean           b_ClearanceMeasurement;                           /*!< TRUE: clearance measurement done; FALSE: clearance measurement not done */
  boolean           b_Condensation;
  boolean           b_Blockage;
  HLA_t_enum8       e_SigStatus;
} HLA_t_Blockage_v1;

/*! Type definition for HLA blockage output */
typedef struct
{
  boolean           b_ClearanceMeasurement;                           /*!< TRUE: clearance measurement done; FALSE: clearance measurement not done */
  boolean           b_Condensation;
  boolean           b_Blockage;
  boolean           b_ManualOverride;
  HLA_t_enum8       e_SigStatus;
} HLA_t_Blockage_v2;

typedef struct
{
  boolean           b_ClearanceMeasurement;                           /*!< TRUE: clearance measurement done; FALSE: clearance measurement not done */
  boolean           b_Condensation;
  boolean           b_Blockage;
  boolean           b_ManualOverride;
  HLA_t_enum8 e_SigStatus;
} HLA_t_Blockage_v3;

/*! Type definition for one defect pixel.  */
typedef struct
{
  uint16                        ui16_xPos;                            /*!< Access to x-position of the defect pixel. */
  uint16                        ui16_yPos;                            /*!< Access to y-position of the defect pixel. */
  HLA_t_enum8                   e_DefectType;                         /*!< Access to defect type of the pixel. */
  uint16                        ui16_Count;                           /*!< Access to counter for defect pixel existence check */
} HLA_t_ICDefectPixel_v1;

typedef struct
{
  uint16                        ui16_xPos;                            /*!< Access to x-position of the defect pixel. */
  uint16                        ui16_yPos;                            /*!< Access to y-position of the defect pixel. */
  HLA_t_enum8      e_DefectType;                         /*!< Access to defect type of the pixel. */
  uint16                        ui16_Count;                           /*!< Access to counter for defect pixel existence check */
} HLA_t_ICDefectPixel_v2;

/*! Type definition for the defect pixels list  */
typedef struct
{
  uint8                       ui8_DefectsListLength;                  /*!< Access to the length of the defects list. */
  HLA_t_enum8                 e_DefectsListLengthSigStat;             /*!< Access to signal quality of DefectsListLength. */
  HLA_t_ICDefectPixel_v1      as_DefectList[HLAR_MAX_NUM_DEFECT_PIXEL_V1]; /*!< Access to defect pixel length. */
} HLA_t_DefectPixelList_v1;

typedef struct
{
  uint8                       ui8_DefectsListLength;                  /*!< Access to the length of the defects list. */
  HLA_t_enum8                 e_DefectsListLengthSigStat;             /*!< Access to signal quality of DefectsListLength. */
  ARRAY(HLA_t_ICDefectPixel_v1, HLAR_MAX_NUM_DEFECT_PIXEL_V1, as_DefectList); /*!< Access to defect pixel length. */
} HLA_t_DefectPixelList_v2;

typedef struct
{
  uint8                       ui8_DefectsListLength;                  /*!< Access to the length of the defects list. */
  HLA_t_enum8           e_DefectsListLengthSigStat;             /*!< Access to signal quality of DefectsListLength. */
  ARRAY(HLA_t_ICDefectPixel_v2, HLAR_MAX_NUM_DEFECT_PIXEL_V1, as_DefectList); /*!< Access to defect pixel length. */
} HLA_t_DefectPixelList_v3;


/* traffic style */
typedef struct
{
  HLA_t_enum8 e_TrafficStyleLastLearned;
  HLA_t_enum8 e_TrafficStyleLearningState;
} HLA_t_TrafficStyle_v1;

typedef struct
{
  HLA_t_enum8               e_TrafficStyleLastLearned;
  HLA_t_enum8 e_TrafficStyleLearningState;
} HLA_t_TrafficStyle_v2;

/*! night view object definition */
typedef struct
{
  uint8                       ui8_ID;                                 /*!< object identification number             */
  HLA_t_enum8                 e_ObjType;                              /*!< object type                              */
  HLA_t_enum8                 e_Spot;                                 /*!< spot light request                       */
  float32                     f32_Distance_m;                         /*!< [m]object distance                       */
  float32                     f32_HorAng_rad;                         /*!< [rad] horizontal object angle (autosar)  */
} HLAF_t_NightViewObject_v1;

typedef struct
{
  uint8                        ui8_ID;                                /*!< object identification number             */
  HLA_t_enum8 e_ObjType;                             /*!< object type                              */
  HLA_t_enum8       e_Spot;                                /*!< spot light request                       */
  float32                      f32_Distance_m;                        /*!< [m]object distance                       */
  float32                      f32_HorAng_rad;                        /*!< [rad] horizontal object angle (autosar)  */
} HLAF_t_NightViewObject_v2;

typedef struct
{
  HLAF_t_NightViewObject_v1  as_Obj[HLAF_NIGHTVIEW_OBJECTS_V1];       /*!< night view object */
} HLAF_t_NightView_v1;

typedef struct
{
  ARRAY(HLAF_t_NightViewObject_v1, HLAF_NIGHTVIEW_OBJECTS_V1, as_Obj); /*!< night view object */
} HLAF_t_NightView_v2;

typedef struct
{
  ARRAY(HLAF_t_NightViewObject_v2, HLAF_NIGHTVIEW_OBJECTS_V1, as_Obj); /*!< night view object */
} HLAF_t_NightView_v3;

/*! region levels for the HlaRoi = FunctionRoi + AboveRoi */
typedef struct
{
  /* lux level which defines the 3 regions */
  float32      f32_Level1_lux;
  float32      f32_Level2_lux;
  float32      f32_Level3_lux;
} HLA_t_ObjectRegionLevel_v1;

typedef struct
{
  /* lux level which defines the 3 regions */
  float32      f32_Level1_lux;
  float32      f32_Maxima_lux;
  float32      f32_Level2_lux;
  float32      f32_Level3_lux;
} HLA_t_ObjectRegionLevel_v2;


/*!< Diagnosis message for HLA debugging purposes */
/* diagnosis debug message state: */
typedef enum
{
  DDM_STATE__HB_ON_V1 = 0,                                            /*!< high beam on */
  DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON_V1,
  DDM_STATE__HLAF_TURN_OFF_REASON_V1,
  DDM_STATE__HLAF_KEEP_OFF_REASON_V1,
  DDM_STATE__HLA_VERSION_V1,
  DDM_STATE__5_V1,
  DDM_STATE__6_V1,
  DDM_STATE__7_V1
}HLA_t_eDiagnosisDebugMsgState_v1;

/* Diagnosis Debug Message */
typedef union
{
  uint64  ui64_DiagnosisDebugMsg;

  struct {
    uint32 Low;
    uint32 High;
  } Long;

  /******************************/
  /* HLA_DDM_STATE__HB_ON       */
  /* state = 0                  */
  /******************************/
  /* simulation: Little endian */
  struct {
    /* 1. icon */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon1_Oncom_TooBright                  : 1;
    uint32 Icon1_Oncom_ContraMotionWhite          : 1;
    uint32 Icon1_Oncom_OncomingPair               : 1;
    uint32 Icon1_Oncom_CenterBright               : 1;
    uint32 Icon1_Oncom_ExtremeBright              : 1;
    uint32 Icon1_Oncom_LateralBright              : 1;
    uint32 Icon1_Oncom_Other                      : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon1_Ahead_RedLight                   : 1;
    uint32 Icon1_Ahead_RedLight2                  : 1;
    uint32 Icon1_Ahead_PulsedLight                : 1;
    uint32 Icon1_Ahead_ContraMotionNonWhite       : 1;
    uint32 Icon1_Ahead_Other                      : 1;

    /* icon result info */
    uint32 Icon1_result                           : 2;                /*!< icon classification result */
    uint32 Icon1_result_Unused                    : 1;

    /* icon status */
    uint32 Icon1_Status_ledDetectionCalled        : 1;                /*!< icon led detection has been applied */
    uint32 Icon1_Status_streetLampDetectionCalled : 1;                /*!< icon street lamp classifier has been applied */
    uint32 Icon1_Status_redLightDetectionCalled   : 1;                /*!< icon red light classifier has been applied */

    uint32 Icon1_classResult_Vehicle              : 1;                /*!< 0: no vehicle, 1: vehicle */
    uint32 Icon1_classResult_Sum                  : 7;                /*!< summed up classification result */

    /* 2. icon */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon2_Oncom_TooBright                  : 1;
    uint32 Icon2_Oncom_ContraMotionWhite          : 1;
    uint32 Icon2_Oncom_OncomingPair               : 1;
    uint32 Icon2_Oncom_CenterBright               : 1;
    uint32 Icon2_Oncom_ExtremeBright              : 1;
    uint32 Icon2_Oncom_LateralBright              : 1;

    /* 32 Bit alignment */

    uint32 Icon2_Oncom_Other                      : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon2_Ahead_RedLight                   : 1;
    uint32 Icon2_Ahead_RedLight2                  : 1;
    uint32 Icon2_Ahead_PulsedLight                : 1;
    uint32 Icon2_Ahead_ContraMotionNonWhite       : 1;
    uint32 Icon2_Ahead_Other                      : 1;

    /* icon result info */
    uint32 Icon2_result                           : 2;                /*!< icon classification result */
    uint32 Icon2_result_Unused                    : 1;


    /* icon status */
    uint32 Icon2_Status_ledDetectionCalled        : 1;                /*!< icon led detection has been applied */
    uint32 Icon2_Status_streetLampDetectionCalled : 1;                /*!< icon street lamp classifier has been applied */
    uint32 Icon2_Status_redLightDetectionCalled   : 1;                /*!< icon red light classifier has been applied */
    uint32 Icon2_classResult_Vehicle              : 1;                /*!< 0: no vehicle, 1: vehicle */
    uint32 Icon2_classResult_Sum                  : 7;                /*!< summed up classification result */
    uint32 Dummy1                                 : 2;                /*!< due to 4 bit alignment */

    uint32 RedReflectorArea                       : 1;                /*!< 0: no red reflector area, 1: red reflector area */
    uint32 SamplingAborted                        : 1;                /*!< 0: no sampling aborted, 1: sampling aborted */
    uint32 FrameDrop                              : 1;                /*!< 0: no frame drop, 1: one or more HLA frames droped */  
    uint32 eState                                 : 3;                /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4: HLA Version, 5-7: Brunn */
    uint32 NextState                              : 3;                /*!< next state     */
    uint32 Dummy0                                 : 1;
  } HBon;

  /***********************************************/
  /* HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON */
  /* state = 1                                   */
  /***********************************************/
  /* simulation: Little endian */
  struct {
    /* initial turn off reason */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Oncom_TooBright                : 1;
    uint32 Oncom_ContraMotionWhite        : 1;
    uint32 Oncom_OncomingPair             : 1;
    uint32 Oncom_CenterBright             : 1;
    uint32 Oncom_ExtremeBright            : 1;
    uint32 Oncom_LateralBright            : 1;
    uint32 Oncom_Unused                   : 8;
    /* 2nd level turn offs */
    uint32 Oncom_SuddenlyAppearingVehicle : 1;
    uint32 Oncom_ClassResultReached       : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Ahead_RedLight                 : 1;
    uint32 Ahead_RedLight2                : 1;
    uint32 Ahead_PulsedLight              : 1;
    uint32 Ahead_ContraMotionNonWhite     : 1;
    uint32 Ahead_Unused                   : 6;
    /* 2nd level turn offs */
    uint32 Ahead_Overtaker                : 1;
    uint32 Ahead_DriveDistReached         : 1;
    uint32 Ahead_DriveDistDynamicReached  : 1;
    uint32 Ahead_DriveDistPairReached     : 1;
    uint32 Ahead_SuddenlyAppearingVehicle : 1;
    uint32 Ahead_ClassResultReached       : 1;

    /* 32 Bit alignment */

    uint32 Dummy2                         : 16;
    uint32 FrameCnt                       : 4;                        /*!< lower 4 Bits of (FrameCnt/2) */
    uint32 Dummy1                         : 2;                        /*!< due to 4 bit alignment */
    uint32 RedReflectorArea               : 1;                        /*!< 0: no red reflector area, 1: red reflector area */
    uint32 SamplingAborted                : 1;                        /*!< 0: no sampling aborted, 1: sampling aborted */
    uint32 FrameDrop                      : 1;                        /*!< 0: no frame drop, 1: one or more HLA frames droped */  
    uint32 eState                         : 3;                        /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */
    uint32 NextState                      : 3;                        /*!< next state     */
    uint32 Dummy0                         : 1;
  } HLARInitialTurnOffReason;


  /*******************************************/
  /* HLA_DDM_STATE__HLAF_TURN_OFF_REASON     */
  /* state = 2                               */
  /*******************************************/
  /* simulation: Little endian */
  struct {
    /* global turn off reason */
    uint32 Global_NotReleased             : 1;
    uint32 Global_NotReleasedRedPerf      : 1;
    uint32 Global_NotReleasedBlockage     : 1;
    uint32 Global_RedPerformance          : 1;
    uint32 Global_Blockage                : 1;
    uint32 Global_Brightness              : 1;
    uint32 Global_Maxima                  : 1;
    uint32 Global_Lights                  : 1;
    uint32 Global_City                    : 1;
    uint32 Global_Tunnel                  : 1;
    uint32 Global_MinSpeed                : 1;
    uint32 Global_NotActive               : 1;
    uint32 Global_NotAvl                  : 1;
    uint32 Global_NotCalibrated           : 1;
    uint32 Global_Error                   : 1;
    uint32 Global_Unused                  : 3;

    /* HLA Light turn off reason */
    uint32 Light_OncDetected              : 1;
    uint32 Light_PrecDetected             : 1;
    uint32 Light_Unused                   : 1;

    /* HLA Standard turn off reason */
    uint32 Std_OncDetected                : 1;
    uint32 Std_PrecDetected               : 1;
    uint32 Std_Unused                     : 1;

    /* HLA plus full HB turn off reason */
    uint32 Plus_OncDetected               : 1;                        /*!< oncoming  traffic which deactivates full HB */
    uint32 Plus_PrecDetected              : 1;                        /*!< preceding traffic which deactivates full HB */
    uint32 Plus_Unused                    : 1;

    /* HLA Plus partial HB turn off reason */
    uint32 PlusLeft_OncomingOnly          : 1;                        /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */
    uint32 PlusRight_OncomingOnly         : 1;                        /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */

    uint32 PlusLeft_AngOutermost2Large    : 1;                        /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   
    uint32 PlusRight_AngOutermost2Large   : 1;                        /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   

    uint32 PlusLeft_OncomingDeactRegion   : 1;                        /*!< oncoming traffic in right deactivation region -> left partial HB off   */

    /* 32 Bit alignment */    

    uint32 PlusRight_OncomingDeactRegion  : 1;                        /*!< oncoming traffic in right deactivation region -> left partial HB off   */

    uint32 PlusLeft_OncLeftPrec           : 1;                        /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */
    uint32 PlusRight_OncLeftPrec          : 1;                        /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */

    uint32 PlusLeft_TTD                   : 1;                        /*!< deactivate partial HB in advance when TTD is small */
    uint32 PlusRight_TTD                  : 1;                        /*!< deactivate partial HB in advance when TTD is small */

    uint32 PlusLeft_RightOff              : 1;                        /*!< right hand traffic: deactivate left HB when right HB will be deactivated */
    uint32 PlusRight_RightOff             : 1;                        /*!< right hand traffic: deactivate left HB when right HB will be deactivated */

    uint32 PlusLeft_dAng2Large            : 1;                        /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */
    uint32 PlusRight_dAng2Large           : 1;                        /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */

    uint32 PlusLeft_Oncoming              : 1;                        /*!< oncoming  traffic which deactivates full/ partial HB */
    uint32 PlusRight_Oncoming             : 1;                        /*!< oncoming  traffic which deactivates full/ partial HB */    

    uint32 PlusLeft_Preceding             : 1;                        /*!< preceding traffic which deactivates full/ partial HB */
    uint32 PlusRight_Preceding            : 1;                        /*!< preceding traffic which deactivates full/ partial HB */    

    uint32 PlusLeft_MinSpeed              : 1;                        /*!< min activation speed */
    uint32 PlusRight_MinSpeed             : 1;                        /*!< min activation speed */

    uint32 PlusLeft_MayBeCity             : 1;                        /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */
    uint32 PlusRight_MayBeCity            : 1;                        /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */

    uint32 PlusLeft_Motorway              : 1;                        /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */
    uint32 PlusRight_Motorway             : 1;                        /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */

    uint32 PlusLeft_Unused                : 3;
    uint32 PlusRight_Unused               : 3;

    uint32 eState                         : 3;                        /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                      : 3;                        /*!< next state     */
    uint32 Dummy0                         : 1;
  } HLAFTurnOffReason;


  /*******************************************/
  /* HLA_DDM_STATE__HLAF_KEEP_OFF_REASON     */
  /* state = 3                               */
  /*******************************************/
  /* simulation: Little endian */
  struct {
    /* HLA Standard keep off reason*/
    uint32 Std_SpdAcc                       : 1;                      /*!< velocity will fall below activation speed in less than 2.5 seconds */
    uint32 Std_SmallRadius                  : 1;                      /*!< small radius */
    uint32 Std_MinTimeHBOff                 : 1;                      /*!< keep HB off for a minimal time */
    uint32 Std_TurnOnDelay                  : 1;                      /*!< turn on delay */
    uint32 Std_PrecedingVehLost             : 1;                      /*!< preceding vehicle lost in curve -> keep HB off until we reached the position and we are at the end of the curve */
    uint32 Std_MaybeCity                    : 1;                      /*!< may be city detected keep full HB off because city will be detected in same frames */
    uint32 Std_PotVeh                       : 1;                      /*!< potential vehcile   */
    uint32 Std_Unused                       : 3;

    /* HLA Plus full HB keep off reason */
    uint32 Plus_HB_Off                      : 1;                      /*!< HB off from old decision */
    uint32 Plus_minTimeOff                  : 1;                      /*!< minimum time low beam on before switching to full HB   */
    uint32 Plus_minTimePartOn               : 1;                      /*!< minimum time partial HB on before switching to full HB */   
    uint32 Plus_Unused                      : 2;

    /* HLA Plus partial HB keep off reason */
    uint32 PlusLeft_TimeToDeact             : 1;                      /*!< Object is moving from ACT/HOLD to DEACT soon */
    uint32 PlusRight_TimeToDeact            : 1;                      /*!< Object is moving from ACT/HOLD to DEACT soon */

    uint32 PlusLeft_TimeToBorder            : 1;                      /*!< Object in DEACT is lost */   
    uint32 PlusRight_TimeToBorder           : 1;                      /*!< Object in DEACT is lost */      

    uint32 PlusLeft_NoOncomingMinTime       : 1;                      /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */
    uint32 PlusRight_NoOncomingMinTime      : 1;                      /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */    

    uint32 PlusLeft_NoOncoming              : 1;                      /*!< keep off HB until no oncoming traffic is detected anymore */
    uint32 PlusRight_NoOncoming             : 1;                      /*!< keep off HB until no oncoming traffic is detected anymore */

    uint32 PlusLeft_OutermostLost           : 1;                      /*!< outermost vehicle lost -> keep HB off */
    uint32 PlusRight_OutermostLost          : 1;                      /*!< outermost vehicle lost -> keep HB off */

    uint32 PlusLeft_SyncSinglePrecCar       : 1;                      /*!< synchronously partial HB on when only 1 or 2 preceding lights detected  */
    uint32 PlusRight_SyncSinglePrecCar      : 1;                      /*!< synchronously partial HB on when only 1 or 2 preceding lights detected */

    uint32 PlusLeft_NoVeh                   : 1;                      /*!< no vehicles detected at all -> full HB will be switched on soon    */
    uint32 PlusRight_NoVeh                  : 1;                      /*!< no vehicles detected at all -> full HB will be switched on soon    */

    uint32 PlusLeft_SpdAcc                  : 1;                      /*!< velocity will fall below activation speed in less than 2 to 3 seconds */
    uint32 PlusRight_SpdAcc                 : 1;                      /*!< velocity will fall below activation speed in less than 2 to 3 seconds */

    uint32 PlusLeft_MaybeCity               : 1;                      /*!< "maybe" city detected */

    /* 32 Bit alignment */

    uint32 PlusRight_MaybeCity              : 1;                      /*!< "maybe" city detected */

    uint32 PlusLeft_minTimeOff              : 1;                      /*!< keep partial HB off for a minimum time */
    uint32 PlusRight_minTimeOff             : 1;                      /*!< keep partial HB off for a minimum time */

    uint32 PlusLeft_Gap2Large               : 1;                      /*!< gap between left and right partial HB is too large */
    uint32 PlusRight_Gap2Large              : 1;                      /*!< gap between left and right partial HB is too large */

    uint32 PlusLeft_TimeToDeactOther        : 1;                      /*!< keep partial HB off if opposite partial HB will switch off in a certain time */
    uint32 PlusRight_TimeToDeactOther       : 1;                      /*!< keep partial HB off if opposite partial HB will switch off in a certain time */

    uint32 PlusLeft_OncCoveredByPrec        : 1;                      /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */
    uint32 PlusRight_OncCoveredByPrec       : 1;                      /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */

    uint32 PlusLeft_OncWillLeaveFOV         : 1;                      /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */
    uint32 PlusRight_OncWillLeaveFOV        : 1;                      /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */

    uint32 PlusLeft_PotentialOncomingDeact  : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ hold region) */
    uint32 PlusRight_PotentialOncomingDeact : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ hold region) */

    uint32 PlusLeft_PotentialOncoming       : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */
    uint32 PlusRight_PotentialOncoming      : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */

    uint32 PlusLeft_Wait4OtherPHB           : 1;                      /*!< keep left partial HB off until right part.HB will be switched on */   
    uint32 PlusRight_Wait4OtherPHB          : 1;                      /*!< keep left partial HB off until right part.HB will be switched on */   

    uint32 PlusLeft_Sync                    : 1;                      /*!< synchronize the partial high beams (left <-> right) */
    uint32 PlusRight_Sync                   : 1;                      /*!< synchronize the partial high beams (left <-> right) */

    uint32 PlusLeft_PrecMinTimeInActRegion  : 1;                      /*!< preceding car stays for minimal time in activation region */
    uint32 PlusRight_PrecMinTimeInActRegion : 1;                      /*!< preceding car stays for minimal time in activation region */

    uint32 PlusLeft_OncMinTimeInActRegion   : 1;                      /*!< oncoming car stays for minimal time in activation region */
    uint32 PlusRight_OncMinTimeInActRegion  : 1;                      /*!< oncoming car stays for minimal time in activation region */

    uint32 PlusLeft_Unused                  : 1;
    uint32 PlusRight_Unused                 : 1;

    uint32 eState                           : 3;                      /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                        : 3;                      /*!< next state     */
    uint32 Dummy0                           : 1;
  } HLAFKeepOffReason;


  /******************************/
  /* HLA_DDM_STATE__HLA_VERSION */
  /* state = 4                  */
  /******************************/
  /* simulation: Little endian */
  struct {
    uint32 HLAVersion       : 24;                                     /*!< HLA version number: 3 Bytes BCD coded: 1 Byte Mainversion, 1Byte Subversion, 1Byte Bugfixlevel */ 

    uint32 Dummy3           : 8;
    /* 32 Bit */

    uint32 Dummy2           : 16;

    uint32 FrameCnt         : 4;                                      /*!< lower 4 Bits of (FrameCnt/2) */

    uint32 Dummy1           : 2;                                      /*!< due to 4 bit alignment */

    uint32 RedReflectorArea : 1;                                      /*!< 0: no red reflector area, 1: red reflector area */

    uint32 SamplingAborted  : 1;                                      /*!< 0: no sampling aborted, 1: sampling aborted */

    uint32 FrameDrop        : 1;                                      /*!< 0: no frame drop, 1: one or more HLA frames droped */  

    uint32 eState           : 3;                                      /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState        : 3;                                      /*!< next state     */
    uint32 Dummy0           : 1; 
  } HLAVersion;
} HLA_t_DiagnosisDebugMsg_v1;


/*!< Diagnosis message for HLA debugging purposes */
/* diagnosis debug message state: */
typedef enum
{
  DDM_STATE__INIT_V2 = 0,                                             /*!< do not use */
  DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON_V2,
  DDM_STATE__HLAF_TURN_OFF_REASON_V2,
  DDM_STATE__HLAF_KEEP_OFF_REASON_V2,
  DDM_STATE__HLA_VERSION_V2,
  DDM_STATE__HB_ON_V2,                                                /*!< high beam on */
  DDM_STATE__6_V2,
  DDM_STATE__7_V2
}HLA_t_eDiagnosisDebugMsgState_v2;

/* Diagnosis Debug Message */
typedef union
{
  uint64  ui64_DiagnosisDebugMsg;

  struct {
    uint32 High;
    uint32 Low;
  } Long;

  /******************************/
  /* HLA_DDM_STATE__HB_ON       */
  /* state = 5                  */
  /******************************/
  /* simulation: Little endian */
  struct {
    uint32 Icon2_Oncom_Other                      : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon2_Ahead_RedLight                   : 1;
    uint32 Icon2_Ahead_RedLight2                  : 1;
    uint32 Icon2_Ahead_PulsedLight                : 1;
    uint32 Icon2_Ahead_ContraMotionNonWhite       : 1;
    uint32 Icon2_Ahead_Other                      : 1;

    /* icon result info */
    uint32 Icon2_result                           : 2;                /*!< icon classification result */
    uint32 Icon2_result_Unused                    : 1;


    /* icon status */
    uint32 Icon2_Status_ledDetectionCalled        : 1;                /*!< icon led detection has been applied */
    uint32 Icon2_Status_streetLampDetectionCalled : 1;                /*!< icon street lamp classifier has been applied */
    uint32 Icon2_Status_redLightDetectionCalled   : 1;                /*!< icon red light classifier has been applied */

    uint32 Icon2_classResult_Vehicle              : 1;                /*!< 0: no vehicle, 1: vehicle */
    uint32 Icon2_classResult_Sum                  : 7;                /*!< summed up classification result */


    uint32 Dummy1                                 : 2;                /*!< due to 4 bit alignment */

    uint32 RedReflectorArea                       : 1;                /*!< 0: no red reflector area, 1: red reflector area */

    uint32 SamplingAborted                        : 1;                /*!< 0: no sampling aborted, 1: sampling aborted */

    uint32 FrameDrop                              : 1;                /*!< 0: no frame drop, 1: one or more HLA frames droped */  

    uint32 eState                                 : 3;                /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4: HLA Version, 5-7: Brunn */

    uint32 NextState                              : 3;                /*!< next state     */
    uint32 Dummy0                                 : 1;


    /* 32 Bit alignment */


    /* 1. icon */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon1_Oncom_TooBright                  : 1;
    uint32 Icon1_Oncom_ContraMotionWhite          : 1;
    uint32 Icon1_Oncom_OncomingPair               : 1;
    uint32 Icon1_Oncom_CenterBright               : 1;
    uint32 Icon1_Oncom_ExtremeBright              : 1;
    uint32 Icon1_Oncom_LateralBright              : 1;
    uint32 Icon1_Oncom_Other                      : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon1_Ahead_RedLight                   : 1;
    uint32 Icon1_Ahead_RedLight2                  : 1;
    uint32 Icon1_Ahead_PulsedLight                : 1;
    uint32 Icon1_Ahead_ContraMotionNonWhite       : 1;
    uint32 Icon1_Ahead_Other                      : 1;

    /* icon result info */
    uint32 Icon1_result                           : 2;                /*!< icon classification result */
    uint32 Icon1_result_Unused                    : 1;

    /* icon status */
    uint32 Icon1_Status_ledDetectionCalled        : 1;                /*!< icon led detection has been applied */
    uint32 Icon1_Status_streetLampDetectionCalled : 1;                /*!< icon street lamp classifier has been applied */
    uint32 Icon1_Status_redLightDetectionCalled   : 1;                /*!< icon red light classifier has been applied */

    uint32 Icon1_classResult_Vehicle              : 1;                /*!< 0: no vehicle, 1: vehicle */
    uint32 Icon1_classResult_Sum                  : 7;                /*!< summed up classification result */

    /* 2. icon */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon2_Oncom_TooBright                  : 1;
    uint32 Icon2_Oncom_ContraMotionWhite          : 1;
    uint32 Icon2_Oncom_OncomingPair               : 1;
    uint32 Icon2_Oncom_CenterBright               : 1;
    uint32 Icon2_Oncom_ExtremeBright              : 1;
    uint32 Icon2_Oncom_LateralBright              : 1;

    
  } HBon;


  /***********************************************/
  /* HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON */
  /* state = 1                                   */
  /***********************************************/
  /* simulation: Little endian */
  struct {
    uint32 Dummy2                         : 16;

    uint32 FrameCnt                       : 4;                        /*!< lower 4 Bits of (FrameCnt/2) */

    uint32 Dummy1                         : 2;                        /*!< due to 4 bit alignment */

    uint32 RedReflectorArea               : 1;                        /*!< 0: no red reflector area, 1: red reflector area */

    uint32 SamplingAborted                : 1;                        /*!< 0: no sampling aborted, 1: sampling aborted */

    uint32 FrameDrop                      : 1;                        /*!< 0: no frame drop, 1: one or more HLA frames droped */  

    uint32 eState                         : 3;                        /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                      : 3;                        /*!< next state     */
    uint32 Dummy0                         : 1;


    /* 32 Bit alignment */


    /* initial turn off reason */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Oncom_TooBright                : 1;
    uint32 Oncom_ContraMotionWhite        : 1;
    uint32 Oncom_OncomingPair             : 1;
    uint32 Oncom_CenterBright             : 1;
    uint32 Oncom_ExtremeBright            : 1;
    uint32 Oncom_LateralBright            : 1;
    uint32 Oncom_Unused                   : 8;
    /* 2nd level turn offs */
    uint32 Oncom_SuddenlyAppearingVehicle : 1;
    uint32 Oncom_ClassResultReached       : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Ahead_RedLight                 : 1;
    uint32 Ahead_RedLight2                : 1;
    uint32 Ahead_PulsedLight              : 1;
    uint32 Ahead_ContraMotionNonWhite     : 1;
    uint32 Ahead_Unused                   : 6;
    /* 2nd level turn offs */
    uint32 Ahead_Overtaker                : 1;
    uint32 Ahead_DriveDistReached         : 1;
    uint32 Ahead_DriveDistDynamicReached  : 1;
    uint32 Ahead_DriveDistPairReached     : 1;
    uint32 Ahead_SuddenlyAppearingVehicle : 1;
    uint32 Ahead_ClassResultReached       : 1;
  } HLARInitialTurnOffReason;


  /*******************************************/
  /* HLA_DDM_STATE__HLAF_TURN_OFF_REASON     */
  /* state = 2                               */
  /*******************************************/
  /* simulation: Little endian */
  struct {
    uint32 PlusRight_OncomingDeactRegion  : 1;                        /*!< oncoming traffic in right deactivation region -> left partial HB off   */

    uint32 PlusLeft_OncLeftPrec           : 1;                        /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */
    uint32 PlusRight_OncLeftPrec          : 1;                        /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */

    uint32 PlusLeft_TTD                   : 1;                        /*!< deactivate partial HB in advance when TTD is small */
    uint32 PlusRight_TTD                  : 1;                        /*!< deactivate partial HB in advance when TTD is small */

    uint32 PlusLeft_RightOff              : 1;                        /*!< right hand traffic: deactivate left HB when right HB will be deactivated */
    uint32 PlusRight_RightOff             : 1;                        /*!< right hand traffic: deactivate left HB when right HB will be deactivated */

    uint32 PlusLeft_dAng2Large            : 1;                        /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */
    uint32 PlusRight_dAng2Large           : 1;                        /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */

    uint32 PlusLeft_Oncoming              : 1;                        /*!< oncoming  traffic which deactivates full/ partial HB */
    uint32 PlusRight_Oncoming             : 1;                        /*!< oncoming  traffic which deactivates full/ partial HB */    

    uint32 PlusLeft_Preceding             : 1;                        /*!< preceding traffic which deactivates full/ partial HB */
    uint32 PlusRight_Preceding            : 1;                        /*!< preceding traffic which deactivates full/ partial HB */    

    uint32 PlusLeft_MinSpeed              : 1;                        /*!< min activation speed */
    uint32 PlusRight_MinSpeed             : 1;                        /*!< min activation speed */

    uint32 PlusLeft_MayBeCity             : 1;                        /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */
    uint32 PlusRight_MayBeCity            : 1;                        /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */

    uint32 PlusLeft_Motorway              : 1;                        /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */
    uint32 PlusRight_Motorway             : 1;                        /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */

    uint32 PlusLeft_Unused                : 3;
    uint32 PlusRight_Unused               : 3;

    uint32 eState                         : 3;                        /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                      : 3;                        /*!< next state     */
    uint32 Dummy0                         : 1;     


    /* 32 Bit alignment */    


    /* global turn off reason */
    uint32 Global_NotReleased             : 1;
    uint32 Global_NotReleasedRedPerf      : 1;
    uint32 Global_NotReleasedBlockage     : 1;
    uint32 Global_RedPerformance          : 1;
    uint32 Global_Blockage                : 1;
    uint32 Global_Brightness              : 1;
    uint32 Global_Maxima                  : 1;
    uint32 Global_Lights                  : 1;
    uint32 Global_City                    : 1;
    uint32 Global_Tunnel                  : 1;
    uint32 Global_MinSpeed                : 1;
    uint32 Global_NotActive               : 1;
    uint32 Global_NotAvl                  : 1;
    uint32 Global_NotCalibrated           : 1;
    uint32 Global_Error                   : 1;
    uint32 Global_Unused                  : 3;

    /* HLA Light turn off reason */
    uint32 Light_OncDetected              : 1;
    uint32 Light_PrecDetected             : 1;
    uint32 Light_Unused                   : 1;

    /* HLA Standard turn off reason */
    uint32 Std_OncDetected                : 1;
    uint32 Std_PrecDetected               : 1;
    uint32 Std_Unused                     : 1;

    /* HLA plus full HB turn off reason */
    uint32 Plus_OncDetected               : 1;                        /*!< oncoming  traffic which deactivates full HB */
    uint32 Plus_PrecDetected              : 1;                        /*!< preceding traffic which deactivates full HB */
    uint32 Plus_Unused                    : 1;

    /* HLA Plus partial HB turn off reason */
    uint32 PlusLeft_OncomingOnly          : 1;                        /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */
    uint32 PlusRight_OncomingOnly         : 1;                        /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */

    uint32 PlusLeft_AngOutermost2Large    : 1;                        /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   
    uint32 PlusRight_AngOutermost2Large   : 1;                        /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   

    uint32 PlusLeft_OncomingDeactRegion   : 1;                        /*!< oncoming traffic in right deactivation region -> left partial HB off   */
  } HLAFTurnOffReason;


  /*******************************************/
  /* HLA_DDM_STATE__HLAF_KEEP_OFF_REASON     */
  /* state = 3                               */
  /*******************************************/
  /* simulation: Little endian */
  struct {
    uint32 PlusRight_MaybeCity              : 1;                      /*!< "maybe" city detected */

    uint32 PlusLeft_minTimeOff              : 1;                      /*!< keep partial HB off for a minimum time */
    uint32 PlusRight_minTimeOff             : 1;                      /*!< keep partial HB off for a minimum time */

    uint32 PlusLeft_Gap2Large               : 1;                      /*!< gap between left and right partial HB is too large */
    uint32 PlusRight_Gap2Large              : 1;                      /*!< gap between left and right partial HB is too large */

    uint32 PlusLeft_TimeToDeactOther        : 1;                      /*!< keep partial HB off if opposite partial HB will switch off in a certain time */
    uint32 PlusRight_TimeToDeactOther       : 1;                      /*!< keep partial HB off if opposite partial HB will switch off in a certain time */

    uint32 PlusLeft_OncCoveredByPrec        : 1;                      /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */
    uint32 PlusRight_OncCoveredByPrec       : 1;                      /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */

    uint32 PlusLeft_OncWillLeaveFOV         : 1;                      /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */
    uint32 PlusRight_OncWillLeaveFOV        : 1;                      /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */

    uint32 PlusLeft_PotentialOncomingDeact  : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ hold region) */
    uint32 PlusRight_PotentialOncomingDeact : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ hold region) */

    uint32 PlusLeft_PotentialOncoming       : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */
    uint32 PlusRight_PotentialOncoming      : 1;                      /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */

    uint32 PlusLeft_Wait4OtherPHB           : 1;                      /*!< keep left partial HB off until right part.HB will be switched on */   
    uint32 PlusRight_Wait4OtherPHB          : 1;                      /*!< keep left partial HB off until right part.HB will be switched on */   

    uint32 PlusLeft_Sync                    : 1;                      /*!< synchronize the partial high beams (left <-> right) */
    uint32 PlusRight_Sync                   : 1;                      /*!< synchronize the partial high beams (left <-> right) */

    uint32 PlusLeft_PrecMinTimeInActRegion  : 1;                      /*!< preceding car stays for minimal time in activation region */
    uint32 PlusRight_PrecMinTimeInActRegion : 1;                      /*!< preceding car stays for minimal time in activation region */

    uint32 PlusLeft_OncMinTimeInActRegion   : 1;                      /*!< oncoming car stays for minimal time in activation region */
    uint32 PlusRight_OncMinTimeInActRegion  : 1;                      /*!< oncoming car stays for minimal time in activation region */

    uint32 PlusLeft_Unused                  : 1;
    uint32 PlusRight_Unused                 : 1;

    uint32 eState                           : 3;                      /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                        : 3;                      /*!< next state     */
    uint32 Dummy0                           : 1;


    /* 32 Bit alignment */


    /* HLA Standard keep off reason*/
    uint32 Std_SpdAcc                       : 1;                      /*!< velocity will fall below activation speed in less than 2.5 seconds */
    uint32 Std_SmallRadius                  : 1;                      /*!< small radius */
    uint32 Std_MinTimeHBOff                 : 1;                      /*!< keep HB off for a minimal time */
    uint32 Std_TurnOnDelay                  : 1;                      /*!< turn on delay */
    uint32 Std_PrecedingVehLost             : 1;                      /*!< preceding vehicle lost in curve -> keep HB off until we reached the position and we are at the end of the curve */
    uint32 Std_MaybeCity                    : 1;                      /*!< may be city detected keep full HB off because city will be detected in same frames */
    uint32 Std_PotVeh                       : 1;                      /*!< potential vehcile   */
    uint32 Std_Unused                       : 3;

    /* HLA Plus full HB keep off reason */
    uint32 Plus_HB_Off                      : 1;                      /*!< HB off from old decision */
    uint32 Plus_minTimeOff                  : 1;                      /*!< minimum time low beam on before switching to full HB   */
    uint32 Plus_minTimePartOn               : 1;                      /*!< minimum time partial HB on before switching to full HB */   
    uint32 Plus_Unused                      : 2;

    /* HLA Plus partial HB keep off reason */
    uint32 PlusLeft_TimeToDeact             : 1;                      /*!< Object is moving from ACT/HOLD to DEACT soon */
    uint32 PlusRight_TimeToDeact            : 1;                      /*!< Object is moving from ACT/HOLD to DEACT soon */

    uint32 PlusLeft_TimeToBorder            : 1;                      /*!< Object in DEACT is lost */   
    uint32 PlusRight_TimeToBorder           : 1;                      /*!< Object in DEACT is lost */      

    uint32 PlusLeft_NoOncomingMinTime       : 1;                      /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */
    uint32 PlusRight_NoOncomingMinTime      : 1;                      /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */    

    uint32 PlusLeft_NoOncoming              : 1;                      /*!< keep off HB until no oncoming traffic is detected anymore */
    uint32 PlusRight_NoOncoming             : 1;                      /*!< keep off HB until no oncoming traffic is detected anymore */

    uint32 PlusLeft_OutermostLost           : 1;                      /*!< outermost vehicle lost -> keep HB off */
    uint32 PlusRight_OutermostLost          : 1;                      /*!< outermost vehicle lost -> keep HB off */

    uint32 PlusLeft_SyncSinglePrecCar       : 1;                      /*!< synchronously partial HB on when only 1 or 2 preceding lights detected  */
    uint32 PlusRight_SyncSinglePrecCar      : 1;                      /*!<  synchronously partial HB on when only 1 or 2 preceding lights detected */

    uint32 PlusLeft_NoVeh                   : 1;                      /*!< no vehicles detected at all -> full HB will be switched on soon    */
    uint32 PlusRight_NoVeh                  : 1;                      /*!< no vehicles detected at all -> full HB will be switched on soon    */

    uint32 PlusLeft_SpdAcc                  : 1;                      /*!< velocity will fall below activation speed in less than 2 to 3 seconds */
    uint32 PlusRight_SpdAcc                 : 1;                      /*!< velocity will fall below activation speed in less than 2 to 3 seconds */

    uint32 PlusLeft_MaybeCity               : 1;                      /*!< "maybe" city detected */
  } HLAFKeepOffReason;


  /**************************/
  /* HLA_DDM_STATE__HLA_VERSION */
  /* state = 4              */
  /**************************/
  /* simulation: Little endian */
  struct {
    uint32 Dummy2           : 16;

    uint32 FrameCnt         : 4;                                      /*!< lower 4 Bits of (FrameCnt/2) */

    uint32 Dummy1           : 2;                                      /*!< due to 4 bit alignment */

    uint32 RedReflectorArea : 1;                                      /*!< 0: no red reflector area, 1: red reflector area */

    uint32 SamplingAborted  : 1;                                      /*!< 0: no sampling aborted, 1: sampling aborted */

    uint32 FrameDrop        : 1;                                      /*!< 0: no frame drop, 1: one or more HLA frames droped */  

    uint32 eState           : 3;                                      /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState        : 3;                                      /*!< next state     */
    uint32 Dummy0           : 1; 

    /* 32 Bit */

    uint32 HLAVersion       : 24;                                     /*!< HLA version number: 3 Bytes BCD coded: 1 Byte Mainversion, 1Byte Subversion, 1Byte Bugfixlevel */ 

    uint32 Dummy3           : 8;
    
  } HLAVersion;
} HLA_t_DiagnosisDebugMsg_v2;


typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint32 uiTimeStamp;
  uint16 uiMeasurementCounter;
  uint16 uiCycleCounter;
  uint8 eSigStatus;
} SignalHeader_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint8 TestMode;
  uint8 CityDetection;
  uint8 TunnelDetection;
  uint8 BadPixelDetection;
  uint8 FogDetection;
  uint8 BlockageDetection;
} RTE_HLA_ParameterAlgoCfg_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint8 HeadLightType;
  uint8 HeadLightMechanics;
  uint8 SpotLight;
  float32 SpotLightWidth;
  float32 FullHBDefaultPos_Left;
  float32 FullHBDefaultPos_Right;
  float32 HeadLampLatency;
  float32 SpotLightTolerance;
} RTE_HLA_ParameterHeadlight_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint8 WindshieldType;
} RTE_HLA_ParameterVehicle_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint8 TrafficStyle;
  uint8 SensitivityMode;
  uint8 CountryWithMultipleReflectors;
} RTE_HLA_ParameterCountry_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint32 VersionNumber;
  SignalHeader_t_v1 Header;
  uint8 HLAType;
  RTE_HLA_ParameterAlgoCfg_t_v1 AlgoCfg;
  RTE_HLA_ParameterHeadlight_t_v1 Headlight;
  RTE_HLA_ParameterVehicle_t_v1 Vehicle;
  RTE_HLA_ParameterCountry_t_v1 Country;
} CPAR_HLA_Parameter_t_v1;


typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 FOV_Horizontal;
  float32 FOV_FunctionRoiAboveHorizon;
  float32 FOV_MinBelowHorizon;
  float32 FOV_MinAboveHorizon;
  float32 PrecVehLight_minDistance;
  float32 PrecVehLight_minHeight;
  float32 StreetLamp_Distance;
  float32 StreetLamp_Height;
} RTE_HLAR_ParameterRoi_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 SpeedThresholdLow;
  float32 SpeedThresholdHigh;
  uint16 NumLeavingStreetlamp_LowSpeed;
  uint16 NumLeavingStreetlamp_HighSpeed;
  uint16 NumSceneStreetlamp_LowSpeed;
  uint16 NumSceneStreetlamp_HighSpeed;
  uint16 AmbientLevel_LowSpeed;
  uint16 AmbientLevel_HighSpeed;
  float32 StreetLampMaxInterDist_LowSpeed;
  float32 StreetLampMaxInterDist_HighSpeed;
  float32 StreetLampMaxDist_LowSpeed;
  float32 StreetLampMaxDist_HighSpeed;
  float32 LeavingCityDelay_LowSpeed;
  float32 LeavingCityDelay_HighSpeed;
  float32 LeavingCityDelaySceneStreetlamp_LowInt;
  float32 LeavingCityDelaySceneStreetlamp_HighInt;
  uint16 NumTunnelStreetlamp;
} RTE_HLAR_ParameterCity_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 SpeedDetThreshold_Fast;
  float32 SpeedDetThreshold;
  float32 SpeedDetThresholdDistance;
  float32 EgoMotionDetThresholdHigh;
  float32 EgoMotionDetThresholdLow;
  uint16 LateralPositionUsedTracks;
  float32 LateralPositionConfidenceThreshHigh;
  float32 LateralPositionConfidenceThreshLow;
  uint16 OcclusionOncomingLeavingLightsThresh;
  float32 OcclusionConfidenceStep;
} RTE_HLAR_ParameterHighway_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 EntryThreshHigh;
  float32 EntryThreshLow;
  float32 EntryDistanceMin;
  float32 EntryDistanceMax;
  float32 ExitThreshHigh;
  float32 ExitThreshLow;
  float32 ExitDistanceMin;
  float32 DetectionTypeDistance;
} RTE_HLAR_ParameterTunnel_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint16 NumOncLightsThres;
  uint16 NumOncLightsLock;
} RTE_HLAR_ParameterTrafficStyle_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 SpeedThreshold;
  uint16 AmbientLevel_LowSpeed;
  uint16 AmbientLevel_HighSpeed;
  float32 Day2NightTimeThres_LowSpeed;
  float32 Day2NightTimeThres_HighSpeed;
  float32 Day2NightDistThres_LowSpeed;
  float32 Day2NightDistThres_HighSpeed;
  float32 Night2DayTimeThres_LowSpeed;
  float32 Night2DayTimeThres_HighSpeed;
  float32 Night2DayDistThres_LowSpeed;
  float32 Night2DayDistThres_HighSpeed;
} RTE_HLAR_ParameterAmbient_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint16 OncSensitivity;
  uint16 PrecSensitivity;
} RTE_HLAR_ParameterVehDet_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 TaillightWidth_Min;
  float32 TaillightWidth_Max;
  float32 HeadlightWidth_Min;
  float32 HeadlightWidth_Max;
  float32 TaillightHeight_Min;
  float32 TaillightHeight_Max;
  float32 HeadlightHeight_Min;
  float32 HeadlightHeight_Max;
} RTE_HLAR_ParameterLightPair_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 LightHeight_Min;
  float32 LightHeight_Max;
  float32 DistFilterConst;
} RTE_HLAR_ParameterDistEst_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 ttbAngle;
} RTE_HLAR_ParameterTTBEst_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint32 VersionNumber;
  SignalHeader_t_v1 Header;
  RTE_HLAR_ParameterRoi_t_v1 Roi;
  RTE_HLAR_ParameterCity_t_v1 City;
  RTE_HLAR_ParameterHighway_t_v1 Highway;
  RTE_HLAR_ParameterTunnel_t_v1 Tunnel;
  RTE_HLAR_ParameterTrafficStyle_t_v1 TrafficStyle;
  RTE_HLAR_ParameterAmbient_t_v1 Ambient;
  RTE_HLAR_ParameterVehDet_t_v1 Vehicle;
  RTE_HLAR_ParameterLightPair_t_v1 LightPair;
  RTE_HLAR_ParameterDistEst_t_v1 DistEst;
  RTE_HLAR_ParameterTTBEst_t_v1 TTBEst;
} CPAR_HLAR_Parameter_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 TTBThreshold;
  float32 HorAngThreshold;
} RTE_HLAF_ParameterTurnOff_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 Radius2TurnsOnThres;
  float32 TurnOnDelay;
} RTE_HLAF_ParameterKeepOffSmallRadius_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  RTE_HLAF_ParameterKeepOffSmallRadius_t_v1 SmallRadius;
} RTE_HLAF_ParameterKeepOff_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 OncomingMin_DistThreshold;
  float32 OncomingMin_LatDistThreshold;
  float32 OncomingMin;
  float32 OncomingMax;
  float32 OncomingMaxHighway;
  float32 PrecedingMin;
  float32 PrecedingTimeGap_Threshold;
  float32 PrecedingTimeGap;
  float32 PrecedingMinWiperOn;
  float32 PrecedingMaxShort;
  float32 PrecedingMaxLong;
  float32 SlowOvertaking;
  float32 Fog;
  float32 City;
  float32 Tunnel;
} RTE_HLAF_ParameterTurnOnDelay_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 DeactivateSpeed;
  float32 ActivateSpeed;
  float32 AlwaysActiveSpeed;
  float32 KeepOff_VeryLowSpeed;
  float32 KeepOff_LowRadius;
  float32 KeepOff_HighAcceleration;
  float32 KeepOff_AccTime;
  float32 KeepOff_Delay;
} RTE_HLAF_ParameterSpeed_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  float32 ConfidenceThreshold;
  float32 ClearMeas2Blockage_DistThres;
  float32 ClearMeas2Blockage_TimeThres;
  float32 ClearMeas2NoBlockage_DistThres;
  float32 NoBlockage2Blockage_DistThres;
  float32 NoBlockage2Blockage_TimeThres;
  float32 Blockage2NoBlockage_TimeThres;
  uint8 ManualOverwrite;
} RTE_HLAF_ParameterBlockage_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint16 ConfidenceThreshold;
  uint16 Sensitivity;
} RTE_HLAF_ParameterFog_t_v1;	

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint16 MaxNumGlarefreeArea;
} RTE_HLAF_ParameterMatrixBeam_t_v1;

typedef struct 			/* [Satisfies_rte sws 1191] */
{
  uint32 VersionNumber;
  SignalHeader_t_v1 Header;
  RTE_HLAF_ParameterTurnOff_t_v1 TurnOff;
  RTE_HLAF_ParameterKeepOff_t_v1 KeepOff;
  RTE_HLAF_ParameterTurnOnDelay_t_v1 TurnOnDelay;
  RTE_HLAF_ParameterSpeed_t_v1 Speed;
  RTE_HLAF_ParameterBlockage_t_v1 Blockage;
  RTE_HLAF_ParameterFog_t_v1 Fog;
  RTE_HLAF_ParameterMatrixBeam_t_v1 Matrix;
} CPAR_HLAF_Parameter_t_v1;
