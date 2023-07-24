/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            interfacedriverinput.h

  DESCRIPTION:          Define different version of DIM input interface

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interfacedriverinput.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:26CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:25CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.18 2016/11/15 15:13:58CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + DIMInputGeneric V5 (ARS430BW18)
  CHANGES:              Revision 1.17 2016/09/14 13:47:24CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V11 (Hyundayi)
  CHANGES:              Revision 1.16 2015/07/16 15:54:51CEST Heintz, Sebastian (uidu6467) 
  CHANGES:              Add new converter for Geely; Correct older header
  CHANGES:              - Added comments -  uidu6467 [Jul 16, 2015 3:54:52 PM CEST]
  CHANGES:              Change Package : 353230:2 http://mks-psad:7002/im/viewissue?selection=353230
  CHANGES:              Revision 1.15 2014/10/09 15:00:40CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Update for AL_ARS400EN_01.15.01
  CHANGES:              LongCtrlInputV10
  CHANGES:              DimInputCustomV6_2
  CHANGES:              update FCTVehCustomInput
  CHANGES:              --- Added comments ---  berndtt1 [Oct 10, 2014 7:43:23 AM CEST]
  CHANGES:              Change Package : 270187:1 http://mks-psad:7002/im/viewissue?selection=270187
  CHANGES:              Revision 1.14 2013/09/30 11:14:30CEST Obst, Christian02 (uidv8774) 
  CHANGES:              modified Input Version5
  CHANGES:              --- Added comments ---  uidv8774 [Sep 30, 2013 11:14:30 AM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.13 2013/09/20 14:01:30CEST Obst, Christian02 (uidv8774) 
  CHANGES:              Added Dim input custom v6 support and cleanup
  CHANGES:              --- Added comments ---  uidv8774 [Sep 20, 2013 2:01:30 PM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.12 2013/09/17 11:53:23CEST Obst, Christian02 (uidv8774) 
  CHANGES:              added namespace for DimInputGeneric v4
  CHANGES:              --- Added comments ---  uidv8774 [Sep 17, 2013 11:53:24 AM CEST]
  CHANGES:              Change Package : 194538:4 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.11 2013/05/15 10:45:35CEST Boll, Marie-Theres (uidu1091) 
  CHANGES:              Missing typedef for compilation of adapter
  CHANGES:              --- Added comments ---  uidu1091 [May 15, 2013 10:45:35 AM CEST]
  CHANGES:              Change Package : 179559:1 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.10 2013/02/15 10:40:13CET Diepolder, Thomas (diepoldert) 
  CHANGES:              Use effective front axle steer angle as addtional custom input for dim (degradation due to multiturn loss)
  CHANGES:              --- Added comments ---  diepoldert [Feb 15, 2013 10:40:14 AM CET]
  CHANGES:              Change Package : 175279:1 http://mks-psad:7002/im/viewissue?selection=175279
  CHANGES:              Revision 1.9 2011/11/03 14:26:07CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Remove dependency to algo_glob.h (add missing enumerators)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 3, 2011 2:26:07 PM CET]
  CHANGES:              Change Package : 86065:1 http://mks-psad:7002/im/viewissue?selection=86065
  CHANGES:              Revision 1.8 2011/10/17 18:27:26CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Update simulation adapters to handle new rte interfaces
  CHANGES:              --- Added comments ---  diepoldert [Oct 17, 2011 6:27:26 PM CEST]
  CHANGES:              Change Package : 84108:1 http://mks-psad:7002/im/viewissue?selection=84108
  CHANGES:              Revision 1.7 2011/09/14 15:13:19CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add work-around to allow compilation of adapter with old RTE
  CHANGES:              --- Added comments ---  ungvaryg [Sep 14, 2011 3:13:20 PM CEST]
  CHANGES:              Change Package : 74571:3 http://mks-psad:7002/im/viewissue?selection=74571
  CHANGES:              Revision 1.6 2011/09/14 12:42:00CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Fix misleading namespace names for DIMGenericInput structures (version1 was actually unversioned, version2 was actually version 1)
  CHANGES:              Add version 2 layout
  CHANGES:              --- Added comments ---  ungvaryg [Sep 14, 2011 12:42:01 PM CEST]
  CHANGES:              Change Package : 74571:3 http://mks-psad:7002/im/viewissue?selection=74571
  CHANGES:              Revision 1.5 2011/05/10 13:40:05CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              new signal speed limiter active introduced
  CHANGES:              --- Added comments ---  diepoldert [May 10, 2011 1:40:05 PM CEST]
  CHANGES:              Change Package : 65322:1 http://mks-psad:7002/im/viewissue?selection=65322
  CHANGES:              Revision 1.4 2011/03/02 13:44:15CET Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Tidied-up the dim input generic versions
  CHANGES:              Introcution of dim input custom interfaces
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 1:44:15 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660

**************************************************************************** */
#ifndef INTERFACE_DIM_INPUT_DATA_H
#define INTERFACE_DIM_INPUT_DATA_H

typedef unsigned char ui8_t;
typedef unsigned char bool_t;
typedef float         f32_t;


namespace DimInputNoVer1 {
  /* Old structure (ARS300) structure for driver inputs
   * The structure has been defined in module kcm_par.h with name MeasDrvInp_t and
   is used for measurement output */
  typedef struct
  {
    f32_t  AccelPedalPos;
    f32_t  AccelPedalGrad;
    f32_t  SteerWheelAngle;
    f32_t  SteerWheelGrad;
    f32_t  BrakePressureRequest;
    f32_t  FrontSteerAngle;
    ui8_t  DriverBraking;
    bool_t TurnIndicatorActive;
    ui8_t  Padding[2];
  } DIMInputGeneric_t;  /* 28 bytes */
}

namespace DimInputNoVer2 {
  typedef struct
  {
    f32_t  AccelPedalPos;
    f32_t  AccelPedalGrad;
    f32_t  SteerWheelAngle;
    f32_t  SteerWheelGrad;
    f32_t  BrakePressureRequest;
    ui8_t  DriverBraking;
    bool_t TurnIndicatorActive;
  } DIMInputGeneric_t;   /* 24 bytes */
}

typedef uint8 DIMInputSignalState_t;      /* status of the steering wheel angle / angle grad information @min: 0 @max:5 @values: enum { DIMInputSignalState_OK=0,DIMInputSignalState_Default=1,DIMInputSignalState_BadQuality=3,DIMInputSignalState_Missing=2,DIMInputSignalState_Max=5,DIMInputSignalState_Suspicious=4,} */

#ifndef DIMInputSignalState_OK
typedef enum DIMInputSignalStateEnum_t {
  DIMInputSignalState_OK          = (0U),
  DIMInputSignalState_Default     = (1U),
  DIMInputSignalState_Missing     = (2U),
  DIMInputSignalState_BadQuality  = (3U),
  DIMInputSignalState_Suspicious  = (4U),
  DIMInputSignalState_Max         = (5U)
} DIMInputSignalStateEnum_t;
#endif


typedef uint8 eTurnIndicator_t;           /* turn indicator information @min: 0 @max:4 @values: enum { eTurnIndicator_Right=2,eTurnIndicator_Invalid=4,eTurnIndicator_Left=1,eTurnIndicator_Off=0,eTurnIndicator_Both=3,} */
#ifndef eTurnIndicator_Off
typedef enum eTurnIndicatorEnum_t {
  eTurnIndicator_Off      = 0,
  eTurnIndicator_Left     = 1,
  eTurnIndicator_Right    = 2,
  eTurnIndicator_Both     = 3,
  eTurnIndicator_Invalid  = 4
} eTurnIndicatorEnum_t;
#endif

typedef uint8 eDriverSetting_t           /* @min: 0 @max:3 @values: enum { eDriverSetting_Invalid=3,eDriverSetting_Late=2,eDriverSetting_Early=0,eDriverSetting_Middle=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
#ifndef eDriverSetting_Early
typedef enum eDriverSettingEnum_t
{
  eDriverSetting_Early=0,
  eDriverSetting_Middle=1,
  eDriverSetting_Late=2,
  eDriverSetting_Invalid=3
} eDriverSettingEnum_t;
#endif

namespace DimInputNoVer3 {
typedef struct
{
    boolean bACCActive;
    eDriverSetting_t eDriverSetting;
    float32 fSteeringWheelAngle;
    float32 fSteeringWheelAngleGrad;
    DIMInputSignalState_t eSteeringWheelAngleStat;
    float32 fAccelPedalPos;
    float32 fAccelPedalGrad;
    DIMInputSignalState_t eAccelPadelStat;
    eTurnIndicator_t eTurnIndicator;
    boolean bDriverBraking;
  } DIMInputGeneric_t;  /* 28 bytes, FCT_MEAS_ID_DIM_INPUT_GENERIC, FCT_VEH, DIMInputGeneric */
}

namespace DimInputV1 {
  typedef struct
  {
    uint32 uiVersionNumber;
    boolean bACCActive;
    eDriverSetting_t eDriverSetting;
    float32 fSteeringWheelAngle;
    float32 fSteeringWheelAngleGrad;
    DIMInputSignalState_t eSteeringWheelAngleStat;
    float32 fAccelPedalPos;
    float32 fAccelPedalGrad;
    DIMInputSignalState_t eAccelPadelStat;
    eTurnIndicator_t eTurnIndicator;
    boolean bDriverBraking;
  } DIMInputGeneric_t;   /* Size: 32 Byte FCT_MEAS_ID_DIM_INPUT_GENERIC, FCT_VEH, DIMInputGeneric */
}

#ifndef eDriverBraking_Inactive
typedef uint8 eDriverBraking_t           /* Driver braking status @min: 0 @max:2 @values: enum { eDriverBraking_Inactive=1,eDriverBraking_Invalid=2,eDriverBraking_Active=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
#define eDriverBraking_Active   0
#define eDriverBraking_Inactive 1
#define eDriverBraking_Invalid  2
#endif

namespace DimInputV2 {
  typedef struct        /* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Version number of data @min:0.0 @max:999999.0 */
    boolean bACCActive;
    eDriverSetting_t eDriverSetting;
    float32 fSteeringWheelAngle;                 /* Steering angle driver @min:-720.0 @max:720.0 */
    float32 fSteeringWheelAngleGrad;             /* Steering angle velocity driver @min:-2800.0 @max:2800.0 */
    DIMInputSignalState_t eSteeringWheelAngleStat;             /* status of the steering wheel angle */
    DIMInputSignalState_t eSteeringWheelAngleGradStat;         /* status of the steering wheel angle gradint */
    float32 fAccelPedalPos;                      /* accelerator pedal position @min:0.0 @max:100.0 */
    float32 fAccelPedalGrad;                     /* Accelerator pedal gradient @min:-8000.0 @max:1000.0 */
    DIMInputSignalState_t eAccelPadelStat;                     /* status of the accel pedal position */
    DIMInputSignalState_t eAccelPadelGradStat;                 /* status of the accel pedal gradint */
    eTurnIndicator_t eTurnIndicator;                      /* turn indicator information */
    eDriverBraking_t eDriverBraking;                      /* Driver braking status */
  } DIMInputGeneric_t;      /* @vaddr:FCT_MEAS_ID_DIM_INPUT_GENERIC @cycleid:FCT_VEH @vname:DIMInputGeneric */
};


#ifndef eFCT_STATE_SIG_INACTIVE
typedef uint8 FCTStateSig_t;
#define eFCT_STATE_SIG_INACTIVE	 (0U)
#define eFCT_STATE_SIG_ACTIVE	   (1U)
#define eFCT_STATE_SIG_INVALID	 (2U)
#endif

namespace DimInputV3 {
  typedef struct
  {
    uint32 uiVersionNumber;                     /* Version number of data @min:0.0 @max:999999.0 */
    boolean bACCActive;
    eDriverSetting_t eDriverSetting;
    float32 fSteeringWheelAngle;                 /* Steering angle driver @min:-720.0 @max:720.0 */
    float32 fSteeringWheelAngleGrad;             /* Steering angle velocity driver @min:-2800.0 @max:2800.0 */
    DIMInputSignalState_t eSteeringWheelAngleStat;             /* status of the steering wheel angle */
    DIMInputSignalState_t eSteeringWheelAngleGradStat;         /* status of the steering wheel angle gradint */
    float32 fAccelPedalPos;                      /* accelerator pedal position @min:0.0 @max:100.0 */
    float32 fAccelPedalGrad;                     /* Accelerator pedal gradient @min:-8000.0 @max:1000.0 */
    DIMInputSignalState_t eAccelPadelStat;                     /* status of the accel pedal position */
    DIMInputSignalState_t eAccelPadelGradStat;                 /* status of the accel pedal gradint */
    eTurnIndicator_t eTurnIndicator;                      /* turn indicator information */
    FCTStateSig_t eDriverBraking;                      /* Driver braking status */
  } DIMInputGeneric_t;			/* 28 bytes, FCT_MEAS_ID_DIM_INPUT_GENERIC, FCT_VEH, DIMInputGeneric */
}


#ifndef AL_SIG_STATE_INIT
typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
#define AL_SIG_STATE_INIT     (0u)
#define AL_SIG_STATE_OK       (1u)
#define AL_SIG_STATE_INVALID  (2u)
#endif


namespace DimInputV4
{
  typedef uint16 AlgoCycleCounter_t;                                 /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */
  typedef uint32 AlgoDataTimeStamp_t;                                /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    bool_t bACCActive;
    eDriverSetting_t eDriverSetting;
    float32 fSteeringWheelAngle;
    float32 fSteeringWheelAngleGrad;
    DIMInputSignalState_t eSteeringWheelAngleStat;
    DIMInputSignalState_t eSteeringWheelAngleGradStat;
    float32 fAccelPedalPos;
    float32 fAccelPedalGrad;
    DIMInputSignalState_t eAccelPadelStat;
    DIMInputSignalState_t eAccelPadelGradStat;
    eTurnIndicator_t eTurnIndicator;
    FCTStateSig_t eDriverBraking;
  } DIMInputGeneric_t;                                               /* @vaddr:0x20230100 @vaddr_defs: FCT_MEAS_ID_DIM_INPUT_GENERIC @cycleid:FCT_VEH @vname:DIMInputGeneric */
}

namespace DimInputV5
{
  typedef unsigned char ePowerTrainEngaged_t                         /* Powertrain status @min: 0 @max:2 @values: enum { ePowerTrain_Disengaged=1,ePowerTrain_Invalid=2,ePowerTrain_Engaged=0,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;
    DimInputV4::SignalHeader_t sSigHeader;
    bool_t bACCActive;
    eDriverSetting_t eDriverSetting;
    float32 fSteeringWheelAngle;
    float32 fSteeringWheelAngleGrad;
    DIMInputSignalState_t eSteeringWheelAngleStat;
    DIMInputSignalState_t eSteeringWheelAngleGradStat;
    float32 fAccelPedalPos;
    float32 fAccelPedalGrad;
    DIMInputSignalState_t eAccelPadelStat;
    DIMInputSignalState_t eAccelPadelGradStat;
    eTurnIndicator_t eTurnIndicator;
    FCTStateSig_t eDriverBraking;
    ePowerTrainEngaged_t ePowerTrainEngaged;
  } DIMInputGeneric_t;                                               /* @vaddr:0x20230100 @vaddr_defs: FCT_MEAS_ID_DIM_INPUT_GENERIC @cycleid:FCT_VEH @vname:DIMInputGeneric */
}


#ifndef eDriverRecognition_Full
#define eDriverRecognition_Full	(0U)
#endif
#ifndef eDriverRecognition_SlightlyDec
#define eDriverRecognition_SlightlyDec	(1U)
#endif
#ifndef eDriverRecognition_StronglyDec
#define eDriverRecognition_StronglyDec	(2U)
#endif
#ifndef eDriverRecognition_Invalid
#define eDriverRecognition_Invalid	(3U)
#endif

typedef uint8 eDriverRecognition_t;       /* @min: 0 @max:3 @values: enum { eDriverRecognition_Invalid=3,eDriverRecognition_Full=0,eDriverRecognition_StronglyDec=2,eDriverRecognition_SlightlyDec=1,} */

namespace DimInputCustomV0 {
  typedef struct
  {
    eDriverRecognition_t eDriverRecognition;
  } DIMInputCustom_t; /* Size 1 Byte, FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH, DIMInputCustom */
 }

namespace DimInputCustomV2 {
  typedef struct
  {
    uint32 uiVersionNumber;
    eDriverRecognition_t eDriverRecognition;
  } DIMInputCustom_t;  /* Size 8 Bytes, FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH, DIMInputCustom */
}


namespace DimInputCustomV3 {
  typedef struct
  {
    uint32 uiVersionNumber;
    eDriverRecognition_t eDriverRecognition;
    boolean bSpeedLimitActive;                   /* Indicates active speed limiter */
  } DIMInputCustom_t;			/* Size 8 Bytes FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH, DIMInputCustom */
}

namespace DimInputCustomV4 {
  typedef struct
  {
    uint32 uiVersionNumber;                     /* @min:0.0 @max:16277215.0 */
    eDriverRecognition_t eDriverRecognition;
    FCTStateSig_t eSpeedLimitActive;                   /* Indicates active speed limiter */
  } DIMInputCustom_t;			/* Size 8 Bytes, FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH, DIMInputCustom */
}

namespace DimInputCustomV5 {
  //typedef struct
  //{
  //  uint32 uiVersionNumber;                     /* @min:0.0 @max:16277215.0 */
  //  float32 fSteerAngleFrontEffv;                /* Analogous steer angle related to front axle steering model */
  //  DIMInputSignalState_t eSteerAngleFrontEffvStat;            /* Status of effective front axle steer angle */
  //  FCTStateSig_t eSpeedLimitActive;                   /* Indicates active speed limiter */
  //} DIMInputCustom_t;			/*  FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH, DIMInputCustom */
  typedef uint16 AlgoCycleCounter_t;        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */
  typedef uint32 AlgoDataTimeStamp_t;       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    bool bSeatButtonPressed;
    bool bWindowButtonsPressed;
    bool bMirrorButtonsPressed;
    bool bIntLightsButtonsPressed;
    bool bExtLightsButtonsPressed;
    bool bSunRoofButtonsPressed;
    bool bStWhlButtonsPressed;
    bool bMidConsoleButtonsPressed;
    bool bRadioButtonsPressed;
    bool bStrColumnButtonsPressed;
    bool bOtherButtonsPressed;
  } sButtons_t;			

  typedef struct
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTStateSig_t eSpeedLimitActive;
    sButtons_t sButtons;
  } DIMInputCustom_t;			/*  FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH, DIMInputCustom */
}
  /* addiditional definition in RTE I310
  uint32 uiVersionNumber;
  SignalHeader_t sSigHeader;
  FCTStateSig_t eSpeedLimitActive;
  sButtons_t sButtons;
  */

namespace DimInputCustomV6
{
  typedef uint16 AlgoCycleCounter_t;        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */
  typedef uint32 AlgoDataTimeStamp_t;       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */
  
  typedef DimInputCustomV5::SignalHeader_t SignalHeader_t;

  typedef struct
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTStateSig_t eSpeedLimitActive;
  } DIMInputCustom_t;
}

namespace DimInputCustomV6_2
{
  typedef struct
  {
    float fBrakeTorque;
  } sDriverInput_t;

  typedef struct
  {
    uint32 uiVersionNumber;
    DimInputCustomV5::SignalHeader_t sSigHeader;
    FCTStateSig_t eSpeedLimitActive;
    sDriverInput_t sDriverInput;
  } DIMInputCustom_t;
}

namespace DimInputCustomV7_GY
{
  typedef struct 
  {
    boolean bDriverOverride;
  }sDriverInput_t;

  typedef struct
  {
    unsigned long uiVersionNumber;
    DimInputCustomV5::SignalHeader_t sSigHeader;
    FCTStateSig_t eSpeedLimitActive;
    sDriverInput_t sDriverInput;
   } DIMInputCustom_t;
}


namespace DimInputCustomV1 {
  typedef struct
  {
    uint32 uiVersionNumber;
    float32 fRequestedBrakeTorque;
    float32 fSteeringWheelCurvature;
    float32 fSteeringWheelCurvStdDev;
    float32 fOverallCurvature;
    float32 fCameraCurvature;
    float32 fPsi;
    float32 fLateralVelocity;
    float32 fLateralDistance;
    DIMInputSignalState_t eLateralDistanceStat;
    eDriverRecognition_t eDriverRecognition;
    boolean bLongCtrlSysActive;
    boolean bLRActive;
    boolean bLaneChangeActive;
    boolean bKickdown;
    boolean bGearShiftActive;
    boolean bSteeringWheelOffsetLearned;
    boolean bTurnLightLeft;
    boolean bTurnLightRight;
    boolean bLaneChangeLeft;
    boolean bLaneChangeRight;
    boolean RadioButtons;
    boolean SeatButtons;
    boolean WindowButtons;
    boolean MirrorButtons;
    boolean InteriorLightsButtons;
    boolean ExteriorLightsButtons;
    boolean SunRoofButtons;
    boolean SteeringWheelButtons;
    boolean TiredButtons;
    boolean StrColumnButtons;
    boolean MidConsoleButtons;
    boolean OtherButtons;
  } DIMInputCustom_t;  /* Size: 60 Bytes, FCT_MEAS_ID_DIM_INPUT_CUSTOM, FCT_VEH */
}

namespace DimInputCustomV11
{
  typedef uint8 eDriverOverride_t;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  float fBrakeTorque;
 	  eDriverOverride_t eDriverOverride;
   } sDriverInput_t;

  typedef struct
  {
    uint32 uiVersionNumber;
    DimInputCustomV5::SignalHeader_t sSigHeader;
    FCTStateSig_t eSpeedLimitActive;
    sDriverInput_t sDriverInput;
  } DIMInputCustom_t;
}


#endif /* INTERFACE_DIM_INPUT_DATA_H */