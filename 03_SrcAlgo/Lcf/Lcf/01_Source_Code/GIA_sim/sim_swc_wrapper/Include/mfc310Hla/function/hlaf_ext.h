/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_ext.h

  DESCRIPTION:            Head light assist function interfaces.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-01-07

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hlaf_ext.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:05CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:50CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:36CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.77 2014/03/27 14:32:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.2 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 27, 2014 2:32:05 PM CET]
  CHANGE:                 Change Package : 207432:48 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.76 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_ext.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_ext.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGE:                 Revision 1.75 2014/03/22 10:28:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added project specific defines
  CHANGE:                 Replaced defines for CORE by predefined ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:24 AM CET]
  CHANGE:                 Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.74 2014/03/12 18:07:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:24 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.73 2014/03/11 11:43:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Flagged out dimming for SRLCAM
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2014 11:43:11 AM CET]
  CHANGE:                 Change Package : 207432:37 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.72 2014/03/10 13:05:25CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - changed DimmingAreas to match the specs of BMW
  CHANGE:                  - implemented visualization
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 10, 2014 1:05:26 PM CET]
  CHANGE:                 Change Package : 224162:1 http://mks-psad:7002/im/viewissue?selection=224162
  CHANGE:                 Revision 1.71 2014/03/04 16:52:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:22 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.70 2014/03/04 14:03:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for latest R2.1 RTE
  CHANGE:                 Undid I390 RTE specific things
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 2:03:04 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.69 2014/03/04 12:58:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for I390 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:57 PM CET]
  CHANGE:                 Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.68 2014/01/22 14:01:50CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 22, 2014 2:01:50 PM CET]
  CHANGE:                 Change Package : 193435:6 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.67 2014/01/21 09:12:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:56 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.66 2014/01/08 17:10:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:24 PM CET]
  CHANGE:                 Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.65 2013/12/13 16:45:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:03 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.64 2013/09/26 11:21:28CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced specific HLA opmodes by TestMode CPar
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:28 AM CEST]
  CHANGE:                 Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.63 2013/09/18 17:41:55CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Hla sens mode
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 18, 2013 5:41:55 PM CEST]
  CHANGE:                 Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_EXT_INCLUDED
#define HLAF_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/* 3 Bytes BCD coded: 1 Byte Mainversion, 1Byte Subversion, 1Byte Bugfixlevel */
#define HLAF_SW_VERSION_NUMBER              0x020200

/* HLAF interface version numbers */
#define HLAF_IN_INTERFACE_VERSION_NUMBER_MAIN    2
#define HLAF_IN_INTERFACE_VERSION_NUMBER_SUB     2
#define HLAF_IN_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define HLAF_IN_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN   << 24) \
                                          | (HLAF_IN_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                          | (HLAF_IN_INTERFACE_VERSION_NUMBER_SUB  << 8) \
                                          | (HLAF_IN_INTERFACE_VERSION_NUMBER_BUGFIX))

#define HLAF_OUT_INTERFACE_VERSION_NUMBER_MAIN    2
#define HLAF_OUT_INTERFACE_VERSION_NUMBER_SUB     2
#define HLAF_OUT_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define HLAF_OUT_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN    << 24) \
                                           | (HLAF_OUT_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                           | (HLAF_OUT_INTERFACE_VERSION_NUMBER_SUB  << 8) \
                                           | (HLAF_OUT_INTERFACE_VERSION_NUMBER_BUGFIX))

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* typedefs only relevant for HLAF plus/standard/light */
typedef uint8 HLAF_t_LevelState;
  #ifndef   HLAF_LEVELSTATE_UNKNOWN
    #define HLAF_LEVELSTATE_UNKNOWN	(0)
  #endif
  #ifndef   HLAF_LEVELSTATE_OFF
    #define HLAF_LEVELSTATE_OFF	(1)
  #endif
  #ifndef   HLAF_LEVELSTATE_ON
    #define HLAF_LEVELSTATE_ON	(2)
  #endif
  #ifndef   HLAF_LEVELSTATE_INVALID
    #define HLAF_LEVELSTATE_INVALID	(255)
  #endif

typedef uint8 HLAF_t_RuntimeState;
#define HLAF_RUNTIMESTATE_UNKNOWN     0u
#define HLAF_RUNTIMESTATE_NORMAL      1u
#define HLAF_RUNTIMESTATE_ABORTED     2u
#define HLAF_RUNTIMESTATE_INVALID   255u

/*! night view object definition */
typedef struct
{
  uint8                             ui8_ID;                           /* object identification number             */
  RTE_HLAF_NightViewObjectType      e_ObjType;                        /* object type                              */
  RTE_HLAF_NightViewSpot            e_Spot;                           /* spot light request                       */
  float32                           f32_Distance_m;                   /* [m]object distance                       */
  float32                           f32_HorAng_rad;                   /* [rad] horizontal object angle (autosar)  */
} HLAF_t_NightViewObject;

typedef struct
{
  ARRAY(HLAF_t_NightViewObject, RTE_HLAF_NIGHTVIEW_OBJECT_LIST_LENGTH, as_Obj);  /* night view object */
} HLAF_t_NightView;
/*! Type definition for night view object */


/*****************************************************************/
/******* Blockage input definition *******************************/
/*****************************************************************/
/*! Type definition for the blockage weather conditions */
typedef uint8 HLAF_t_eBlockageWeather;
#define HLAF_BLOCKAGE_WEATHER_UNKNOWN     0x00u
#define HLAF_BLOCKAGE_WEATHER_RAIN_SNOW   0x02u
#define HLAF_BLOCKAGE_WEATHER_FOG         0x04u
#define HLAF_BLOCKAGE_WEATHER_GLARING_SUN 0x08u
#define HLAF_BLOCKAGE_WEATHER_INVALID     0xFFu

/*! Type definition for the blockage visibility capabilities */
typedef uint8 HLAF_t_eBlockageVisibility;
#define HLAF_BLOCKAGE_VISIBILITY_UNKNOWN  0u
#define HLAF_BLOCKAGE_VISIBILITY_CLEAR    1u
#define HLAF_BLOCKAGE_VISIBILITY_HIGH     2u
#define HLAF_BLOCKAGE_VISIBILITY_MEDIUM   3u
#define HLAF_BLOCKAGE_VISIBILITY_LOW      4u
#define HLAF_BLOCKAGE_VISIBILITY_INVALID  255u

/*! Type definition for Blockage status. */
typedef uint8 HLAF_t_eBlockageStatus;
#define HLAF_BLOCKAGE_STATUS_UNKNOWN                0u                /*!< Unknown status (init error, communication error,...) */
#define HLAF_BLOCKAGE_STATUS_NO_BLOCKAGE            1u                /*!< No Blockage */
#define HLAF_BLOCKAGE_STATUS_TOLERATED_BLOCKAGE     2u                /*!< Tolerated Blockage */
#define HLAF_BLOCKAGE_STATUS_CONDENSATION           3u                /*!< Condensation */
#define HLAF_BLOCKAGE_STATUS_TOP_PART_BLOCKAGE      4u                /*!< Partial Blockage */
#define HLAF_BLOCKAGE_STATUS_BOTTOM_PART_BLOCKAGE   5u                /*!< Partial Blockage */
#define HLAF_BLOCKAGE_STATUS_BLOCKAGE               6u                /*!< Blockage */
#define HLAF_BLOCKAGE_STATUS_INVALID                255u

/*! Type definition for a Blockage level information*/
typedef struct
{
  uint8                             ui8_Val;                          /*!< Blockage percentage */
  uint8                             ui8_Conf;                         /*!< Confidence */
} HLAF_t_BlockageInfo;

/*! Type definition for AOI definition*/
typedef struct
{
  uint8                             ui8_AoiIdx;                       /*!< index of the AOI */

  /*!< position of the AOI */
  uint16                            ui16_X1;
  uint16                            ui16_X2;
  uint16                            ui16_Y1;
  uint16                            ui16_Y2;
}  HLAF_t_BlockageAOIDefinition;

/*! Type definition for the blockage AOI */
typedef struct
{
  HLAF_t_BlockageAOIDefinition      s_AOIDef;                         /*!< current AOI definition */
  HLAF_t_BlockageInfo               s_BlockageInfo;                   /*!< Blockage level information */
} HLAF_t_BlockageAOI;

#define HLAF_BLOCKAGE_AOI           25                                /* number of AOIs (Area of interest) */

/*! Type definition for the output of the Generic Blockage */
typedef struct
{
  AlgoCycleCounter_t                uiFrameCnt;                       /*!< Frame counter */
  AlgoDataTimeStamp_t               uiTimeStamp;                      /*!< Timestamp */
  
  ARRAY(HLAF_t_BlockageAOI, HLAF_BLOCKAGE_AOI, as_AOI);               /*!< AOIs blockage percentage and confidence */
  HLAF_t_eBlockageStatus            e_BlockageStatus;                 /*!< HLAF blockage status */
  HLAF_t_eBlockageVisibility        e_BlockageVisibility;             /*!< HLAF blockage visibility */
  HLAF_t_eBlockageWeather           e_BlockageWeather;                /*!< HLAF blockage weather conditions */
} HLAF_t_Blockage;
/*****************************************************************/
/******* End of Blockage input definition ************************/
/*****************************************************************/


/* Type definition for objects from GEN */
typedef struct
{
  uint8                             numUsedObjects;                   /*!< Number of objects in array */
  EM_t_GenObjSortedIdxArray         iSortedObjectList;                /*!< Sorted indices of object array */
  EM_t_GenObjArray                  aObject;                          /*!< Objects in front of the vehicle */
} HLAF_t_StereoObjectList;

/* Type definition for closest vehicle */
typedef struct  
{
  float32                           f32_Distance;                     /* [m] object distance, measured from front axis */
  float32                           f32_HorAngle;                     /* [rad] horizontal object angle in world (Autosar) */
  float32                           f32_HorAngle_Cam;                 /* [rad] horizontal object angle with respect to camera coordinate system */
  float32                           f32_VerAngle_Cam;                 /* [rad] vertical   object angle with respect to camera coordinate system */

  uint8                             ui8_ExistenceProb;                /* [%] existence probability of vehicle(s) in the GFA */

  RTE_HLAF_ObjStatus                e_Status;                         /* object status (no object detected, unknown driving direction, oncoming veh., preceding veh.) */
  RTE_HLAF_ObjStatus                e_Type;                           /* object type (no object detected, unknown type, car, truck or motorcycle */
}HLAF_t_ClosestVeh_t;


#if (HLA_PROJECT == HLA_PROJECT_SMFC4B0)
/* HLA EcoLight control data */
typedef struct
{
  RTE_HLAF_EcoLight_eAvailabilityState  e_AvailabilityState;          /* Availability of EcoLight information */
  RTE_HLAF_EcoLight_eDetectionState     e_DetectionState;             /* Availability of Ecolight Detection */
  float32                               ObjectDist;                   /* Distance to preceeding object*/
  RTE_HLAF_EcoLight_eVehicleType        e_ObjectType;                 /* Type of preceeding vehicle (one track, two track) */
  RTE_HLAF_EcoLight_eVehicleLight       e_ObjectLightState;           /* Light status of preceeding vehicle */
} HLAF_EcoLight_t;
#endif

/* HLA dimming area */
typedef struct
{
  float32                           BndryLeft_Ang_Cam;                /* Angle of left boundary of dimming area */
  float32                           BndryRight_Ang_Cam;               /* Angle of right boundary of dimming area */
  float32                           BndryLower_Ang_Cam;               /* Angle of lower boundary of dimming area */
  RTE_HLAF_LightOutput              e_LightOutput;                    /* Light output used in dimming area */
} HLAF_DimmingArea_t;


/* HLA light dim down area signals (for bright reflecting areas) */
typedef struct
{
  ARRAY(RTE_HLAF_DimmingLevel, RTE_HLA_NUM_DIMM_AREAS, DimmingArea);  /* Status of each available dimming area */
  RTE_HLAF_DimmingStatus            eDimmingStatus;                   /* Status of dimming feature */
  uint32                            nDimmingArea;                     /* Number of used dimming areas*/
} HLAF_LightDimming_t;

/*! Type definition for HLA plus output data */
typedef struct
{
  /* environment data */
  RTE_HLA_TrafficStyle              e_TrafficStyle;                   /*!< HLA right/left hand traffic style */
  RTE_HLAR_CityState                e_CityState;                      /*!< HLA city detection */
  RTE_HLAR_WeatherState             e_WeatherState;                   /*!< HLA weather detection */
  RTE_HLAR_Tunnel                   e_TunnelState;                    /*!< HLA tunnel detection */
  RTE_HLAF_MotorwayState            e_MotorwayState;                  /*!< HLA motorway detection */
  RTE_HLAR_BrightnessState          e_BrightnessState;                /*!< HLA signal "Outside Brightness State" */
  RTE_HLA_SensMode                  e_SensMode;                       /*!< HLA sensitivity mode, e.g. US sensistivity mode */

  /* closest vehicle data (on own lane) */
  HLAF_t_ClosestVeh_t               s_ClosestVeh;                     /*!< HLA data of closest vehicle, independent of lane */
  HLAF_t_ClosestVeh_t               s_ClosestVehOwnLane;              /*!< HLA data of closest vehicle on own lane */

  RTE_HLAF_SpeedState               e_SpeedState;                     /*!< HLA Speed state */
  HLAF_t_RuntimeState               e_RuntimeState;                   /*!< HLA runtime time, e.g. reached runtime limit */
} HLAF_t_HeadlightControl_Common;


/*! Type definition for HLA plus, standard and light output data */
typedef struct
{
  /* HLA Light, Standard, Plus (Common outputs) */
  HLAF_t_LevelState                 e_LevelState;                     /*!< HLA optical headlight leveling state (on: hla active, off: hla not avl, too bright, not calibrated) */
  RTE_HLAF_HighBeamState            e_HighBeamState;                  /*!< HLA high beam state */
  HLA_t_fLightDistance              f32_LowBeamDist;                  /*!< HLA low beam distance, autosar coordinate system */
  HLA_t_fLightAngle                 f32_LowBeamAngle;                 /*!< HLA low beam object angle, autosar coordinate system */
  RTE_HLAF_ObjStatus                LowBeam_Status;
  /* change over speed from HB off to full HB or full HB to off */
  HLA_t_ui8ChangeoverLevel          ui8_ChangeoverLevel;              /*!< [0..15] HLA changeover level */
  RTE_HLAF_LightOutput              e_LightOutput_Lt;                 /*!< HLA plus signal "headlamp left light output" */
  RTE_HLAF_LightOutput              e_LightOutput_Rt;                 /*!< HLA plus signal "headlamp right light output" */

  /* HLA Plus */
  float32                           f32_RotAngleMin_Lt;               /*!< HLA plus signal "headlamp left rotation angle min" [°], autosar coordinate system  */
  float32                           f32_RotAngleMin_Rt;               /*!< HLA plus signal "headlamp right rotation angle min" [°], autosar coordinate system */
  RTE_HLAF_HighBeamState            e_HighBeamState_Lt;               /*!< HLA plus signal "high beam left state" */
  RTE_HLAF_HighBeamState            e_HighBeamState_Rt;               /*!< HLA plus signal "high beam right state" */
  /* change over speed from partial HB to full HB, off to full, full to partial, ... */
  HLA_t_ui8ChangeoverLevel          ui8_HLAPlus_ChangeoverLevel_Lt;           /*!< [0..7] HLA plus changeover level for left partial HB  */
  HLA_t_ui8ChangeoverLevel          ui8_HLAPlus_ChangeoverLevel_Rt;   /*!< [0..7] HLA plus changeover level for right partial HB */
} HLA_t_HeadlightControl_PlusStdLight;


typedef struct
{
  float32                           BndryLeft_Ang;
  float32                           BndryLeft_Dist;
  float32                           BndryLeft_Ang_Cam;
  
  float32                           BndryRight_Ang;
  float32                           BndryRight_Dist;
  float32                           BndryRight_Ang_Cam;
  
  float32                           BndryLower_Ang_Cam;
  float32                           ClosestObj_Dist;
  float32                           ClosestObj_Ang;

  float32                           MinLight_Dist;
  float32                           MinLight_Ang;
  float32                           ttb18Left;
  float32                           ttb18Right;
  RTE_HLAF_ObjStatus                BndryLeft_Status;
  RTE_HLAF_ObjStatus                BndryRight_Status;
  RTE_HLAF_ObjStatus                BndryLower_Status;
  RTE_HLAF_ObjStatus                ClosestObj_Status;
  RTE_HLAF_ObjStatus                MinLight_Status;
  RTE_HLAF_TTBStatus                ttb18Left_Status;
  RTE_HLAF_TTBStatus                ttb18Right_Status;
  uint8                             ExistenceProb;
} HLAF_t_MatrixGFA;


typedef struct
{
  ARRAY(HLAF_t_MatrixGFA, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS, GFA);
  uint32                            nGFA;
  RTE_HLAF_SignalStatus             GFAStatus;
  RTE_HLAF_HighBeamState            HighBeamState;
  float32                           LowBeam_Dist;
  float32                           LowBeam_Ang;
  RTE_HLAF_ObjStatus                LowBeam_Status;
  RTE_HLAF_MatrixTurnOffReason      TurnOffReason;
} HLAF_t_Matrix;


/*! Type definition for HLA output data */
typedef struct
{
  /* hla state and type */
  RTE_HLA_State                         e_State;                      /*!< HLA control state e.g. not available, idle, activated, temporarily not available */
  RTE_HLA_Type                          e_Type;                       /*!< HLA type e.g. Standard, Plus, Light, not available */
  HLAF_t_HeadlightControl_Common        s_Common;                     /*!< common hlaf output signals like: city, highway, brightness, traffic style or tunnel detection*/
  HLA_t_HeadlightControl_PlusStdLight   s_PlusStdLight;               /*!< HLA Plus, Standard, Light output data */
  HLAF_t_Matrix                         Matrix;                       /*!< HLA Matrix beam signals (glare free areas (GFA)) */
#if (HLA_PROJECT == HLA_PROJECT_SMFC4B0)
  HLAF_EcoLight_t                       EcoLight;                     /*!< Eco light signals */
#endif
  HLAF_LightDimming_t                   Dimming;                      /*!< Light Dimming Area signals */
} HLA_t_HeadlightControl;


/*! Type definition of the required input parameters for HLAF */
/* static inputs = parameter */
/* constant during runtime   */
typedef struct
{
  HLA_t_CameraParameter             *ps_CameraParameter;              /*!< camera parameter         */
  HLA_t_SensorSocket                *ps_SensorSocket;                 /*!< sensor socket parameters */
  HLA_t_SensorAngles                *ps_SensorAngles;                 /*!< sensor angles parameters */
  CPAR_HLA_Parameter_t              *ps_HlaPar;                       /*!< common hla parameter     */
  CPAR_HLAF_Parameter_t             s_HlafPar;                        /*!< hlaf parameter           */
} HLAF_t_InputParameters;

/*! Type definition of the required input signals for HLAF */
/* variable inputs             */
/* not constant during runtime */
typedef struct
{
  HLA_t_Availability                *ps_Avl;                          /*!< availability signal */
  HLA_t_ImagerState                 *ps_ImagerState;                  /*!< imager control state signal */
  HLA_t_MotionState                 *ps_MotionState;                  /*!< vehicle motion state signal */
  HLA_t_HeadlightState              *ps_HeadlightState;               /*!< head light state signal */
  HLA_t_VehicleState                *ps_VehicleState;                 /*!< vehicle state signal */
  HLA_t_CaliOnline                  *ps_CaliOnline;                   /*!< online calibration */
  HLA_t_ObjectList                  *ps_ObjectList;                   /*!< object list */
  HLA_t_EnvironmentData             *ps_Environment;                  /*!< environment data like brightness, city, highway, tunnel, driving direction, ... */
  HLAF_t_NightView                  s_NightView;                      /*!< night view objects */
  HLAF_t_Blockage                   s_Blockage;                       /*!< blockage */
  HLAF_t_StereoObjectList           s_StereoObjectList;               /*!< stereo object list */
} HLAF_t_InputSignals;

/*! Type definition of the required input */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;      /*!< HLAF input interface version number */
  AlgoCycleCounter_t                uiFrameCnt;                       /*!< Frame counter */
  AlgoDataTimeStamp_t               uiTimeStamp_HLA_us;               /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */
  AlgoDataTimeStamp_t               uiTimeStamp_VDY_us;               /*!< [us] VDY Timestamp, vdy ouput data */ 
  AlgoDataTimeStamp_t               uiTimeStamp_Image_us;             /*!< [us] Image Timestamp */
  AlgoCycleCounter_t                uiVDY_Cnt;                        /*!< VDY cycle counter    */
  HLAF_t_InputParameters            s_Par;                            /*!< input parameters     */
  HLAF_t_InputSignals               s_Sig;                            /*!< input signals        */
} HLAF_t_RequiredInputs;


/*! Type definition of the provided output */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;      /*!< HLAF output interface version number */
  uint32                            ui32_HLA_SWVersionNumber;         /*!< HLA Software version number */
  uint32                            ui32_HLAF_SWVersionNumber;        /*!< HLAF Software version number */
  AlgoCycleCounter_t                uiFrameCnt;                       /*!< Frame counter */
  AlgoCycleCounter_t                uiHLAF_Cnt;                       /*!< HLAF counter  */
  AlgoDataTimeStamp_t               uiTimeStamp_HLA_us;               /*!< [us] HLA Timestamp, hla input data */
  AlgoDataTimeStamp_t               uiTimeStamp_Image_us;             /*!< [us] Image Timestamp */
  HLA_t_DiagnosisDebugMsg           s_DiagnosisDebugMsg;              /*!< Diagnosis message for HLA debugging purposes */
  HLA_t_HeadlightControl            s_HeadlightControl;               /*!< head light control signal */
  HLA_t_Blockage                    s_Blockage;                       /*!< blockage output */
  HLAF_t_NightView                  s_NightView;                      /*!< night view object output */
} HLAF_t_ProvidedOutputs;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* Needed for HIL since it is written in c++ */
#ifdef __cplusplus
extern "C" {
#endif

/*! Initializes the HLAF-component only once after bootup */
void HLAF_v_Init( const HLAF_t_RequiredInputs  *ps_In,
                  HLAF_t_ProvidedOutputs       *ps_Out,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  const AS_t_ServiceFuncts     *Services
                 );

/*! Executes HLAF function. */
void HLAF_v_Exec( const HLAF_t_RequiredInputs  *ps_In,
                  HLAF_t_ProvidedOutputs       *ps_Out,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  const AS_t_ServiceFuncts     *Services
                 );


#ifdef __cplusplus
}
#endif /* __cplusplus */

/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef HLAF_EXT_INCLUDED */
