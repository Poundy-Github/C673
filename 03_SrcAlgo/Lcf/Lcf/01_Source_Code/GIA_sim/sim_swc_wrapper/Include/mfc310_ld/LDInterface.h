/*-------------------------------------------------------------------------
 |
 |  FILE NAME   :  $Source: LDInterface.h $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental AG 2010
 |  ALLE RECHTE VORBEHALTEN. ALL RIGHTS RESERVED.
 |
 |   The  reproduction,  transmission or  use  of  this  document or  its
 |   contents  is  not   permitted  without  express  written  authority.
 |   Offenders will  be liable for damages. All  rights, including rights
 |   created  by patent  grant  or  registration of  a  utility model  or
 |   design, are reserved.
 |
 | ------------------------------------------------------------------------
 |
 |  Description :
 |
 |  $Revision: 1.1 $
 |              
 +-------------------------------------------------------------------------*/

#ifndef LD_INTERFACE_H
#define LD_INTERFACE_H

#ifdef __cplusplus
extern "C" 
{
#endif

#if defined(_TMS320C6X)
    typedef unsigned long long T_LDIF_UINT64;
    typedef long long T_LDIF_SINT64;
    typedef int T_LDIF_SINT32;
    typedef unsigned int T_LDIF_UINT32;
    typedef float T_LDIF_FLOAT32;
    typedef short T_LDIF_SINT16;
    typedef unsigned short T_LDIF_UINT16;
    typedef char T_LDIF_UINT8;
#elif defined(__PC_SW)
    typedef unsigned long long T_LDIF_UINT64;
    typedef long long T_LDIF_SINT64;
    typedef int T_LDIF_SINT32;
    typedef unsigned int T_LDIF_UINT32;
    typedef float T_LDIF_FLOAT32;
    typedef short T_LDIF_SINT16;
    typedef unsigned short T_LDIF_UINT16;
    typedef char T_LDIF_UINT8;
#elif defined(__GOLDDUST__)
    #pragma enumsalwaysint on
    typedef unsigned long long T_LDIF_UINT64;
    typedef long long T_LDIF_SINT64;
    typedef sint32 T_LDIF_SINT32;
    typedef uint32 T_LDIF_UINT32;
    typedef float32 T_LDIF_FLOAT32;
    typedef short T_LDIF_SINT16;
    typedef unsigned short T_LDIF_UINT16;
    typedef uint8 T_LDIF_UINT8;
#elif defined(__POWERPC__)		// Any PPC
    #pragma enumsalwaysint on
    typedef unsigned long long T_LDIF_UINT64;
    typedef long long T_LDIF_SINT64;
    typedef int T_LDIF_SINT32;
    typedef unsigned int T_LDIF_UINT32;
    typedef float T_LDIF_FLOAT32;
    typedef short T_LDIF_SINT16;
    typedef unsigned short T_LDIF_UINT16;
    typedef char T_LDIF_UINT8;
#elif defined(__TMS470__)		// Any ARM
	#pragma enumsalwaysint on
    typedef unsigned long long T_LDIF_UINT64;
    typedef signed long long T_LDIF_SINT64;
    typedef signed int T_LDIF_SINT32;
    typedef unsigned int T_LDIF_UINT32;
    typedef float T_LDIF_FLOAT32;
    typedef signed short T_LDIF_SINT16;
    typedef unsigned short T_LDIF_UINT16;
    typedef unsigned char T_LDIF_UINT8;
#else
    #error "Unknown platform, using defaults"
#endif

#define LD_INTERFACE_NUM_MARKERS (14)

#define LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE (3)

#define LD_INTERFACE_MAX_MARKERFEATURES (50)

#define LD_INTERFACE_VERSION_INFO_LEN (32)

#define LD_MIN_SRAM_SIZE (65536)


#define LD_NUM_HOR_LUT_SAMPLEPOINTS  (33)
#define LD_NUM_VERT_LUT_SAMPLEPOINTS (16)    
    
// identifies internal interface changes
#define LD_INTERFACE_ID (02)

// Local Map will use Frame to Frame motion from the EmoOutput
// struct EmoWorldToWorld instead of VDY data
// Please define same as LM_USE_EMO (LDDefines.h, ld_main.cpp)
//#define LD_INTERFACE_LM_USE_EMO

typedef enum 
{
    e_LDIF_MT_CONTINUOUS     = 0,
    e_LDIF_MT_DASHED         = 1,
    e_LDIF_MT_RESERVED1      = 2,
    e_LDIF_MT_RESERVED2      = 3,
    e_LDIF_MT_NOLINEDETECTED = 4,
    e_LDIF_MT_UNCLASSIFIED   = 5,
    e_LDIF_MT_DOTTED         = 6,
    e_LDIF_MT_DECORATION     = 7,
    e_LDIF_MT_SEPARATING     = 8,
    e_LDIF_MT_NARROWDASHED   = 9,
    e_LDIF_MT_NUM_ENTRIES    = 10,
    e_LDIF_MT_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_MarkerType;

typedef enum 
{
    e_LDIF_MQ_NOMARKER    = 0,
    e_LDIF_MQ_VERYBAD     = 1,
    e_LDIF_MQ_BAD         = 2,
    e_LDIF_MQ_PREDICTED   = 3,
    e_LDIF_MQ_GOOD        = 4,
    e_LDIF_MQ_NUM_ENTRIES = 5,
    e_LDIF_MQ_BUGFIX      = 0x7FFFFFFF
}  E_LDIF_MarkerQuality;

typedef enum
{
    e_LDIF_MR_INVALID     = 0,
    e_LDIF_MR_LEFT        = 1,
    e_LDIF_MR_RIGHT       = 2,
    e_LDIF_MR_NO          = 3,
    e_LDIF_MR_NUM_ENTRIES = 4,
    e_LDIF_MR_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_MarkerRel;

typedef enum
{
    e_LDIF_MC_WHITE       = 0,
    e_LDIF_MC_YELLOW      = 1,
    e_LDIF_MC_RED         = 2,
    e_LDIF_MC_BLUE        = 3,
    e_LDIF_MC_GREEN       = 4,
    e_LDIF_MC_UNKNOWN     = 5,
    e_LDIF_MC_NUM_ENTRIES = 6,
    e_LDIF_MC_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_MarkerColor;

typedef enum
{
    e_LDIF_LE_IDLE               = 0,
    e_LDIF_LE_FORK_EXIT          = 1,
    e_LDIF_LE_FORK_ENTRY         = 2,
    e_LDIF_LE_FORK_UNKNOWN_OPEN  = 3,
    e_LDIF_LE_FORK_UNKNOWN_CLOSE = 4,
    e_LDIF_LE_CONSTRUCTION_START = 5,
    e_LDIF_LE_CONSTRUCTION_CLOSE = 6,
    e_LDIF_LE_NUM_ENTRIES        = 7,
    e_LDIF_LE_BUGFIX            = 0x7FFFFFFF
}  E_LDIF_Event;

typedef enum
{
    e_LDIF_OP_Reference     = 0,
    e_LDIF_OP_PPC_MGT5200   = 1,
    e_LDIF_OP_TMS320_DM64P  = 2,
    e_LDIF_OP_PPC5675K      = 3,
    e_LDIF_OP_NUM_ENTRIES   = 4,
    e_LDIF_OP_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_Platform;

typedef enum
{
    e_LDIF_FL_Stereo_ASIL   = 0,
    e_LDIF_FL_Stereo        = 1,
    e_LDIF_FL_Mono_ASIL     = 2,
    e_LDIF_FL_Mono          = 3,
    e_LDIF_FL_NUM_ENTRIES   = 4,
    e_LDIF_FL_BUGFIX        = 0x7FFFFFFF
}  E_LDIF_Level;

typedef enum
{
    e_LDIF_SID_AMIS                     = 0,
    e_LDIF_SID_MT9V023_BGGR             = 1,
    e_LDIF_SID_MI1000_REV2_GRBG_16x16   = 2, // results in 64 x 16 knee point ratio
    e_LDIF_SID_MI1000_REV2_GRBG_4x16    = 3, // results in 16 x 16 knee point ratio
    e_LDIF_SID_NUM_ENTRIES              = 4,
    e_LDIF_SID_BUGFIX                   = 0x7FFFFFFF
}  E_LDIF_SensorID;

typedef enum
{
    e_LDIF_LC_NONE = 0,
    e_LDIF_LC_LEFT_TO_RIGHT = 1,
    e_LDIF_LC_RIGHT_TO_LEFT = 2,
    e_LDIF_LC_NUM_ENTRIES   = 3,
    e_LDIF_LC_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_LaneChange;

typedef enum
{
    e_LDIF_SS_BOTH          = 0,
    e_LDIF_SS_RIGHT         = 1,
    e_LDIF_SS_LEFT          = 2,
    e_LDIF_SS_NONE          = 3,
    e_LDIF_SS_NUM_ENTRIES   = 4,
    e_LDIF_SS_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_SteeringSide;

typedef enum
{
    e_LDIF_RT_HIGHWAY      = 0,
    e_LDIF_RT_COUNTRY_ROAD = 1,
    e_LDIF_RT_URBAN_ROAD   = 2,
    e_LDIF_RT_UNKOWN       = 3,
    e_LDIF_RT_NUM_ENTRIES  = 4,
    e_LDIF_RT_BUGFIX         = 0x7FFFFFFF
}  E_LDIF_RoadType;

typedef enum
{
    LD_ERROR_CHECK_NOT_DONE         = 0,  /*!< status of error unknown, i.e. error was not (completely) checked */
    LD_ERROR_CHECK_DONE_AND_PASSED  = 1,  /*!< error did not occur */
    LD_ERROR_CHECK_DONE_AND_FAILED  = 2,  /*!< error did occur */
    LD_ERROR_BUGFIX         = 0x7FFFFFFF
} LDErrorStatus_t;

typedef enum
{
    LD_ERROR_PARAMETER        = 0,  /*!< = 0, error group: parameter --> error occurred during init */
    LD_ERROR_INPUT            = 1,  /*!< = 1, error group: (other) input error*/
    LD_ERROR_CALIBRATION      = 2,  /*!< = 2, error group: error in calibration input */
    LD_ERROR_SOFTWARE         = 3,  /*!< = 3, error group: software */
    LD_NUM_ERROR_LIST_ENTRIES = 4,  /*!< = 4, pseudo entry for number of errors */
    LD_ERROR_LIST_BUGFIX         = 0x7FFFFFFF
} LDErrorId_t;

typedef enum
{
    LD_STATE_NOT_INITIALIZED     = 0,  /*!< algo has not been initialized yet, state before init() function */
    LD_STATE_RUNNING             = 1,  /*!< algo has been initialized and is running fine */
    LD_STATE_TEMP_NOT_AVAILABLE  = 2,  /*!< algo has been initialized but is temporarily not available */
    LD_STATE_FAILURE             = 3,  /*!< algo is in failure mode, needs to be reinitialized by frame SW */
    LD_STATE_BUGFIX         = 0x7FFFFFFF
} LDState_t;

typedef enum
{
    LD_PL_Plausible   = 0,
    LD_PL_Implausible = 1,
    LD_PL_Ambiguous   = 2,
    LD_PL_BUGFIX      = 0x7FFFFFFF
} LDPlausibility;

typedef enum
{
    LD_AD_NO_VERIFICATION_DONE_YET   = 0,
    LD_AD_ABS_DEV_GREATER_1_00_DEG   = 1,
    LD_AD_ABS_DEV_LESSEQUAL_1_00_DEG = 2,
    LD_AD_ABS_DEV_LESSEQUAL_0_50_DEG = 3,
    LD_AD_ABS_DEV_LESSEQUAL_0_25_DEG = 4,
    LD_AD_ABS_DEV_LESSEQUAL_0_10_DEG = 5,
    LD_AD_ABS_BUGFIX                 = 0x7FFFFFFF
} LDAutocalDeviation;
#define LD_AUTOCAL_NUM_DEVIATION_BOUNDARIES 5 // Excludes NO_VERIFICATION_DONE_YET and BUGFIX

typedef struct
{
  LDErrorStatus_t  status;       /*!< status of error */
  T_LDIF_UINT32    optData;      /*!< optional data */
  T_LDIF_UINT32    file;         /*!< hash of filename where most severe error was raised */
  T_LDIF_UINT32    line;         /*!< line where most severe error was raised */
} LDError_t;

typedef struct
{
  LDError_t     error[LD_NUM_ERROR_LIST_ENTRIES];  /*!< error entries, indexed by XXXErrorId_t defined above */
} LDOutputErrors_t;

typedef struct
{
  T_LDIF_FLOAT32      m_f32_DeltaTime;
  T_LDIF_UINT32       m_FeatureNumberWriteBack;
  T_LDIF_UINT32       m_FeatureNumberVerified;
  T_LDIF_UINT32       m_a_ParameterSent[16];
  T_LDIF_UINT32       m_a_ParameterReturned[16];
}LD_EVE_Status;

typedef struct
{
    LDOutputErrors_t	  errors;
    LDState_t             state;
} LDSystemInfo_t;

typedef struct
{
    T_LDIF_FLOAT32 m_f32_Roll;
    T_LDIF_FLOAT32 m_f32_Pitch;
    T_LDIF_FLOAT32 m_f32_Yaw;
} S_LDCalibrationAngles_t;

typedef struct
{

    S_LDCalibrationAngles_t    s_MonoCaliSemoImager;
    S_LDCalibrationAngles_t    s_MonoCaliSemoCRoi  ;
    S_LDCalibrationAngles_t    s_MonoCaliSemoRRoi  ;

} S_LDExtCalibration_t;

typedef struct
{
    T_LDIF_FLOAT32 rl_Vx;
    T_LDIF_FLOAT32 rl_Vy;
    T_LDIF_FLOAT32 rl_Vz;
    T_LDIF_FLOAT32 rl_VxSigma;
    T_LDIF_FLOAT32 rl_VySigma;
    T_LDIF_FLOAT32 rl_VzSigma;
} S_LDEmoVelocity_t;

// [3x4] Rigid motion transform
typedef struct
{
    T_LDIF_FLOAT32 rl_A00;
    T_LDIF_FLOAT32 rl_A10;
    T_LDIF_FLOAT32 rl_A20;

    T_LDIF_FLOAT32 rl_A01;
    T_LDIF_FLOAT32 rl_A11;
    T_LDIF_FLOAT32 rl_A21;

    T_LDIF_FLOAT32 rl_A02;
    T_LDIF_FLOAT32 rl_A12;
    T_LDIF_FLOAT32 rl_A22;

    T_LDIF_FLOAT32 rl_A03;
    T_LDIF_FLOAT32 rl_A13;
    T_LDIF_FLOAT32 rl_A23;
} S_LDEmoTransform_t;

typedef struct  
{   
    T_LDIF_FLOAT32 rl_Roll;
    T_LDIF_FLOAT32 rl_Pitch;
    T_LDIF_FLOAT32 rl_Yaw;
    T_LDIF_FLOAT32 rl_RollSigma;
    T_LDIF_FLOAT32 rl_PitchSigma;
    T_LDIF_FLOAT32 rl_YawSigma;
    
    T_LDIF_FLOAT32 rl_Tx;
    T_LDIF_FLOAT32 rl_Ty;
    T_LDIF_FLOAT32 rl_Tz;
    T_LDIF_FLOAT32 rl_TxSigma;
    T_LDIF_FLOAT32 rl_TySigma;
    T_LDIF_FLOAT32 rl_TzSigma;
    
    T_LDIF_FLOAT32 rl_DeltaT;
    T_LDIF_FLOAT32 rl_AccumulatedYaw;
    T_LDIF_FLOAT32 rl_AccumulatedDist;
    
    S_LDEmoTransform_t m_s_WorldToWorldTransform;
} S_LDEmoWorldToWorld_t;

typedef struct
{
    T_LDIF_SINT32       m_i32_CheckDone;
    LDPlausibility      m_e_Plausibility;
} S_LDIFModelScopeResult;

typedef struct
{
    T_LDIF_SINT32       m_i32_CheckDoneLeft;
    T_LDIF_SINT32       m_i32_CheckDoneRight;
    LDPlausibility      m_e_PlausibilityLeft;
    LDPlausibility      m_e_PlausibilityRight;
} S_LDIFLaneScopeResult;

typedef struct
{
    S_LDIFModelScopeResult  m_s_CameraPitch;
    S_LDIFModelScopeResult  m_s_CameraRoll;
    S_LDIFModelScopeResult  m_s_CameraYaw;
    LDAutocalDeviation    m_e_WorstDeviation;
} S_LDAutocalPlausibilityResult;

typedef struct
{
    S_LDIFModelScopeResult          m_s_Speed;
    S_LDIFModelScopeResult          m_s_Pitch;
    S_LDIFModelScopeResult          m_s_YawRateBias;
    S_LDIFModelScopeResult          m_s_CameraHeight;
    S_LDIFModelScopeResult          m_s_FrameRate;
    S_LDAutocalPlausibilityResult m_s_Autocalibration;
} S_LDModelScope;

typedef struct
{
    S_LDIFLaneScopeResult m_s_VehicleCanFollowEstimate;
    S_LDIFLaneScopeResult m_s_VehicleFollowedHistoricLaneEstimate;
    S_LDIFLaneScopeResult m_s_LaneTrackCrossesRoadBoundary;
    S_LDIFLaneScopeResult m_s_LaneTrackBehindRoadBoundary;
    S_LDIFLaneScopeResult m_s_ParallelStructures;
} S_LDLaneScope;

typedef struct
{
    S_LDModelScope  m_s_ModelScope;
    S_LDLaneScope   m_s_LaneScope;
} S_LDPlausibilityMeasures;

typedef struct
{
    T_LDIF_FLOAT32  m_f32_PitchAngleNominal;
    T_LDIF_FLOAT32  m_f32_RollAngleNominal;
    T_LDIF_FLOAT32  m_f32_CamYawAngleNominal;

    T_LDIF_FLOAT32  m_f32_CamHeight;
    T_LDIF_FLOAT32  m_f32_CamOffset;
    T_LDIF_FLOAT32  m_f32_CamX;
    T_LDIF_FLOAT32  m_f32_Axis2Axis;
    T_LDIF_FLOAT32  m_f32_CamFocalLength;
    T_LDIF_FLOAT32  m_f32_CamDistortionK1;
    T_LDIF_FLOAT32  m_f32_CamDistortionK2;
    T_LDIF_SINT32   m_i32_CamMainPointX;
    T_LDIF_SINT32   m_i32_CamMainPointY;
    T_LDIF_FLOAT32  m_f32_VehicleWidth;

    T_LDIF_FLOAT32  m_f32_CameraAlignmentRangeMinimum;
    T_LDIF_FLOAT32  m_f32_CameraAlignmentRangeMaximum;

    E_LDIF_Level    m_i32_FunctionalLevel;

    E_LDIF_Platform m_i32_OptimizationPlatform;
    T_LDIF_SINT32   m_i32_HardwareClicksPerSecond;
} S_LDParameterIn;

typedef struct
{
    T_LDIF_FLOAT32  m_f32_PitchAngleAC;
    T_LDIF_SINT32   m_i32_PitchACStage;
    T_LDIF_FLOAT32  m_f32_RollAngleAC;
    T_LDIF_SINT32   m_i32_RollACStage;
    T_LDIF_FLOAT32  m_f32_CamYawAngleAC;
    T_LDIF_SINT32   m_i32_CamYawACStage;
} S_LDParameterInOut;


typedef struct
{
    T_LDIF_SINT16 sl_x;
    T_LDIF_SINT16 sl_y;
} S_LD_RectifierLUTDisplacementVec;


typedef struct
{
    /* input LUT Rect->RAW */
    S_LD_RectifierLUTDisplacementVec as_RectLut[LD_NUM_HOR_LUT_SAMPLEPOINTS * LD_NUM_VERT_LUT_SAMPLEPOINTS]; 
} S_LD_RectifierLUT;


// rebuild of the input / output in RTE style
// the following type defs are copyies of the RTE definitions without making a actual RTE include

// this will be the interface in the future, so the "original" interface will be deprecated


typedef T_LDIF_UINT32 aiMarkerColors_RTE_Style_t;          /* @min: 0 @max:2147483647 @values: enum { LD_MC_RED=2,LD_MC_BLUE=3,LD_MC_GREEN=4,LD_MC_UNKNOWN=5,LD_MC_WHITE=0,LD_MC_BUGFIX=2147483647,LD_MC_YELLOW=1,} */	/* [Satisfies_rte sws 1188] */
typedef T_LDIF_UINT32 aiMarkerTypes_RTE_Style_t;           /* @min: 0 @max:2147483647 @values: enum { LD_MT_BUGFIX=2147483647,LD_MT_WALL=13,LD_MT_HIGHCURB=11,LD_MT_DOTTED=6,LD_MT_UNCLASSIFIED=5,LD_MT_LOWCURB=10,LD_MT_NARROWDASHED=9,LD_MT_DECORATION=7,LD_MT_SEPARATING=8,LD_MT_RESERVED2=3,LD_MT_RESERVED1=2,LD_MT_DASHED=1,LD_MT_CONTINUOUS=0,LD_MT_ROADSHOULDER=14,LD_MT_NOLINEDETECTED=4,LD_MT_CRASHBARRIER=12,} */	/* [Satisfies_rte sws 1188] */
typedef T_LDIF_UINT32 eEventType_RTE_Style_t;              /* @min: 0 @max:2147483647 @values: enum { LD_LE_FORK_ENTRY=2,LD_LE_FORK_UNKNOWN_OPEN=3,LD_LE_CONSTRUCTION_START=5,LD_LE_FORK_EXIT=1,LD_LE_IDLE=0,LD_LE_CONSTRUCTION_CLOSE=6,LD_LE_FORK_UNKNOWN_CLOSE=4,LD_LE_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */
typedef T_LDIF_UINT32 eParallelModel_RTE_Style_t;          /* @min: 0 @max:2147483647 @values: enum { LD_PM_NOT_PARALLEL=0,LD_PM_PARALLEL=1,LD_PM_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */
typedef T_LDIF_UINT32 eSteeringSide_RTE_Style_t;           /* @min: 0 @max:2147483647 @values: enum { LD_SS_NONE=3,LD_SS_RIGHT=1,LD_SS_BOTH=0,LD_SS_LEFT=2,LD_SS_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */
typedef T_LDIF_UINT32 eCoordinateSystem_RTE_Style_t;       /* @min: 0 @max:2147483647 @values: enum { LD_CS_REAR_AXLE=1,LD_CS_FRONT_AXLE=0,LD_CS_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */

typedef T_LDIF_FLOAT32 afMarkerHeights_array_RTE_Style_t[3];			/* [Satisfies_rte sws 1189] */
/* [Satisfies_rte_sws_1189] */
typedef T_LDIF_FLOAT32 afMarkerPositions_array_RTE_Style_t[3];			/* [Satisfies_rte sws 1189] */
/**/
typedef T_LDIF_FLOAT32 afMarkerWidths_array_RTE_Style_t[3];			/* [Satisfies_rte sws 1189] */
/**/

typedef T_LDIF_FLOAT32 afMarkerDashLength_array_RTE_Style_t[3];

typedef T_LDIF_FLOAT32 afMarkerVoidLength_array_RTE_Style_t[3];

typedef T_LDIF_FLOAT32 afMarkerDashVoidPhase_array_RTE_Style_t[3];

typedef aiMarkerColors_RTE_Style_t aiMarkerColors_array_RTE_Style_t[3];			/* [Satisfies_rte sws 1189] */
/**/
typedef aiMarkerTypes_RTE_Style_t aiMarkerTypes_array_RTE_Style_t[3];			/* [Satisfies_rte sws 1189] */
/**/
typedef T_LDIF_SINT32 aiTrackID_array_RTE_Style_t[3];
/**/
typedef struct 			/* [Satisfies_rte sws 1191] */
{
	T_LDIF_SINT32 CS_MULTIPLE_MARKER;
	T_LDIF_SINT32 CS_LEFT_BARRIER;
	T_LDIF_SINT32 CS_RIGHT_BARRIER;
	T_LDIF_SINT32 CS_CROSSING_MARKER;
	T_LDIF_SINT32 CS_INHIBIT_SINGLE_LINE;
	T_LDIF_SINT32 CS_HOLD;
} sConstructionSite_RTE_Style_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eEventType_RTE_Style_t eEventType;
	T_LDIF_FLOAT32 fEventDist;
	T_LDIF_SINT32 iEventQuality;
} sEvent_RTE_Style_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	T_LDIF_SINT32 iAvailable;
	T_LDIF_UINT32 uiQuality;
	T_LDIF_FLOAT32 fDistance;
	T_LDIF_FLOAT32 fCurvature;
	T_LDIF_FLOAT32 fCurvatureRate;
	T_LDIF_FLOAT32 fSegmentDistFar;
	T_LDIF_FLOAT32 fYaw;
	T_LDIF_FLOAT32 fCurvatureFar;
	T_LDIF_FLOAT32 fCurvatureRateFar;
	T_LDIF_FLOAT32 fMarkerHeight;
	T_LDIF_FLOAT32 fVerticalCurvature;
	T_LDIF_FLOAT32 fVerticalCurvatureRate;
    T_LDIF_FLOAT32 fVerticalPitch;
    T_LDIF_FLOAT32 fLookaheadDistance;
	T_LDIF_SINT32 iNumberOfMarkers;
	aiMarkerTypes_array_RTE_Style_t         aiMarkerTypes;
	aiMarkerColors_array_RTE_Style_t        aiMarkerColors;
	afMarkerPositions_array_RTE_Style_t     afMarkerPositions;
	afMarkerWidths_array_RTE_Style_t        afMarkerWidths;
    afMarkerDashLength_array_RTE_Style_t    afMarkerDashLength;
    afMarkerVoidLength_array_RTE_Style_t    afMarkerVoidLength;
    afMarkerDashVoidPhase_array_RTE_Style_t afMarkerDashVoidPhase;
    afMarkerHeights_array_RTE_Style_t       afMarkerHeights;
    aiTrackID_array_RTE_Style_t             aiTrackId;
} sMarker_RTE_Style_t;			


typedef struct 			/* [Satisfies_rte sws 1191] */
{
	//AlgoInterfaceVersionNumber_t uVersionNumber;
	//SignalHeader_t sSignalHeader;
	sMarker_RTE_Style_t sLeftMarker;
	sMarker_RTE_Style_t sRightMarker;
	sMarker_RTE_Style_t sLeftAdjacentMarker;
	sMarker_RTE_Style_t sRightAdjacentMarker;
    sMarker_RTE_Style_t sLeftMarkerRear;
    sMarker_RTE_Style_t sRightMarkerRear;
    sMarker_RTE_Style_t sLeftAdjacentMarkerRear;
    sMarker_RTE_Style_t sRightAdjacentMarkerRear;
	sEvent_RTE_Style_t sLeftEvent;
	sEvent_RTE_Style_t sRightEvent;
	T_LDIF_FLOAT32 fPitchAngleOnline;
	T_LDIF_FLOAT32 fRollAngleOnline;
	T_LDIF_SINT32 iACSaveRequest;
	T_LDIF_SINT32 iACPercentage;
    eCoordinateSystem_RTE_Style_t eCoordinateSystem;
    eParallelModel_RTE_Style_t eParallelModel;
	T_LDIF_SINT32 iCameraMisaligned;
	T_LDIF_SINT32 iACNotFinished;
	sConstructionSite_RTE_Style_t sConstructionSite;
	T_LDIF_SINT32 iLaneChange;
	T_LDIF_SINT32 iSmoothOperation;
	eSteeringSide_RTE_Style_t eSteeringSide;
	T_LDIF_SINT32 iIndexEgoLane;
	T_LDIF_SINT32 iNumberOfLanes;
	T_LDIF_SINT32 uiOverallConfidence;
	T_LDIF_UINT32 uiImageFingerPrint;
	T_LDIF_SINT32 iVersionMajor;
	T_LDIF_SINT32 iVersionMinor;
	T_LDIF_SINT32 iVersionPatch;
} LdOutputData_RTE_Style_t;	


typedef struct 			/* [Satisfies_rte sws 1191] */
{
//	AlgoInterfaceVersionNumber_t uVersionNumber;
//	SignalHeader_t sSignalHeader;
	T_LDIF_FLOAT32 fPitchAngleAC;
	T_LDIF_SINT32 iPitchACStage;
	T_LDIF_FLOAT32 fRollAngleAC;
	T_LDIF_SINT32 iRollACStage;
	T_LDIF_FLOAT32 fCamYawAngleAC;
	T_LDIF_FLOAT32 iCamYawACStage;
} NVM_LdOnlineCaliData_RTE_Style_t;	



// end rebuild


typedef struct
{
    T_LDIF_FLOAT32          m_f32_InputSpeedSI;
    T_LDIF_FLOAT32          m_f32_InputYawRateSI;
    T_LDIF_SINT64           m_i64_InputSpeedTS;
    T_LDIF_SINT64           m_i64_InputYawTS;
    T_LDIF_SINT32           m_i32_InputYawRateValid;
    T_LDIF_UINT32           m_u32_InputImageFingerPrint;
    T_LDIF_SINT32           m_i32_InputImageFrameCounter;
    T_LDIF_SINT32           m_i32_InputPreventLaneChange;
    T_LDIF_FLOAT32          m_f32_InputDeltaTime;
    T_LDIF_SINT32           m_i32_InputCountryCode;
    T_LDIF_SINT32           m_i32_InputDefaultOutput;
    T_LDIF_SINT32           m_i32_InputConstructionSiteByTSR;
    T_LDIF_SINT64           m_i64_TimeStamp;
    S_LDExtCalibration_t    m_s_InputCalibrationExt;
    S_LDEmoVelocity_t       m_s_EmoVelocity;
#ifdef LD_INTERFACE_LM_USE_EMO
    S_LDEmoWorldToWorld_t   m_s_EmoWorldToWorld;
#endif /*LD_INTERFACE_LM_USE_EMO*/
} S_LDDynamicIn;

typedef struct
{
    T_LDIF_SINT32  m_i32_QualityLeft;
    T_LDIF_FLOAT32 m_f32_DistanceLeft;
    T_LDIF_FLOAT32 m_f32_CurvatureLeft;
    T_LDIF_FLOAT32 m_f32_CurvatureRateLeft;
    T_LDIF_FLOAT32 m_f32_YawLeft;
    T_LDIF_FLOAT32 m_f32_MarkerWidthLeft;
    E_LDIF_MarkerType m_i32_MarkerTypeLeft;
    E_LDIF_MarkerColor m_i32_MarkerColorLeft;
    T_LDIF_FLOAT32 m_f32_LookaheadDistanceLeft;
    T_LDIF_SINT32  m_i32_NumberOfMarkersLeft;
    T_LDIF_SINT32  m_ai32_MarkerTypesLeft[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE];
    E_LDIF_MarkerColor  m_ai32_MarkerColorsLeft[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE];
    T_LDIF_FLOAT32 m_af32_MarkerPositionsLeft[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE*2];
    T_LDIF_FLOAT32 m_af32_MarkerHeightsLeft[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE];
    //T_LDIF_SINT32  m_ai32_MarkerTrackIDsLeft[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE]; // needed if all 3 possible trackIds are sent to RTE

    T_LDIF_SINT32  m_i32_QualityRight;
    T_LDIF_FLOAT32 m_f32_DistanceRight;
    T_LDIF_FLOAT32 m_f32_CurvatureRight;
    T_LDIF_FLOAT32 m_f32_CurvatureRateRight;
    T_LDIF_FLOAT32 m_f32_YawRight;
    T_LDIF_FLOAT32 m_f32_MarkerWidthRight;
    E_LDIF_MarkerType  m_i32_MarkerTypeRight;
    E_LDIF_MarkerColor m_i32_MarkerColorRight;
    T_LDIF_FLOAT32 m_f32_LookaheadDistanceRight;
    T_LDIF_SINT32  m_i32_NumberOfMarkersRight;
    T_LDIF_SINT32  m_ai32_MarkerTypesRight[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE];
    E_LDIF_MarkerColor  m_ai32_MarkerColorsRight[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE];
    T_LDIF_FLOAT32 m_af32_MarkerPositionsRight[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE*2];
    T_LDIF_FLOAT32 m_af32_MarkerHeightsRight[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE];
    //T_LDIF_SINT32  m_ai32_MarkerTrackIDsRight[LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE]; // needed if all 3 possible trackIds are sent to RTE

    T_LDIF_FLOAT32 m_f32_PitchAngleOnline;
    T_LDIF_FLOAT32 m_f32_CamYawAngleOnline;
    T_LDIF_FLOAT32 m_f32_RollAngleOnline;

    T_LDIF_SINT32 m_i32_ACSaveRequest;
    T_LDIF_SINT32 m_i32_ACPercentage;

    T_LDIF_SINT32   m_i32_ParallelModel;
    T_LDIF_SINT32   m_i32_CameraMisaligned;
    T_LDIF_SINT32   m_i32_ACNotFinished;
    T_LDIF_SINT32   m_i32_ConstructionSite;
    T_LDIF_SINT32   m_i32_LaneChange;
    T_LDIF_SINT32   m_i32_SmoothOperation;
    T_LDIF_SINT32   m_i32_SteeringSide;
    E_LDIF_Event    m_i32_EventLeft;
    T_LDIF_FLOAT32  m_f32_EventLeftDist;
    T_LDIF_SINT32   m_i32_EventLeftQuality;
    T_LDIF_SINT32   m_i32_EventLeftMergeSplitToTrackId; // points to adjacent lane
    E_LDIF_Event    m_i32_EventRight;
    T_LDIF_FLOAT32  m_f32_EventRightDist;
    T_LDIF_SINT32   m_i32_EventRightQuality;
    T_LDIF_SINT32   m_i32_EventRightMergeSplitToTrackId; // points to adjacent lane
    // adjacent events     
    E_LDIF_Event    m_i32_EventLeftAdjacent;
    T_LDIF_FLOAT32  m_f32_EventLeftAdjacentDist;
    T_LDIF_SINT32   m_i32_EventLeftAdjacentQuality;
    T_LDIF_SINT32   m_i32_EventLeftAdjacentMergeSplitToTrackId;
    E_LDIF_Event    m_i32_EventRightAdjacent;
    T_LDIF_FLOAT32  m_f32_EventRightAdjacentDist;
    T_LDIF_SINT32   m_i32_EventRightAdjacentQuality;
    T_LDIF_SINT32   m_i32_EventRightAdjacentMergeSplitToTrackId;

    E_LDIF_RoadType m_i32_RoadType;  
    T_LDIF_SINT32   m_i32_IndexEgoLane;
    T_LDIF_SINT32   m_i32_NumberOfLanes;
    T_LDIF_SINT32   m_i32_AdditionalParallelMarkers;

    T_LDIF_SINT32 m_i32_AvailableLeft;
    T_LDIF_SINT32 m_i32_AvailableRight;

    S_LDPlausibilityMeasures m_s_PlausibilityMeasures;

    T_LDIF_SINT32 m_i32_Blockage;
    T_LDIF_SINT32 m_i32_Condensation;

    T_LDIF_UINT16 m_u16_InternalCounter;
    T_LDIF_SINT32 m_i32_ImageFrameCounter;
    T_LDIF_SINT64 m_i64_TimeStamp;
    T_LDIF_UINT32 m_ui32_ImageFingerPrint;

	LdOutputData_RTE_Style_t m_LDOutput_RTE_Style; 

    T_LDIF_SINT32 m_i32_VersionMajor;
    T_LDIF_SINT32 m_i32_VersionMinor;
    T_LDIF_SINT32 m_i32_VersionPatch;
    T_LDIF_UINT8  m_u8_VersionText[32];
    T_LDIF_UINT8  m_u8_DiagnosisOutput[8];

} S_LDOutput;

typedef struct
{
    E_LDIF_MarkerQuality m_i32_MarkerQuality;
    E_LDIF_MarkerRel     m_i32_MarkerRelation;
    T_LDIF_SINT32        m_i32_NumFeatures;
    E_LDIF_MarkerType    m_i32_MarkerType;
    T_LDIF_FLOAT32       m_f32_MarkerHeight;
    T_LDIF_FLOAT32       m_af32_FeaturePosU[LD_INTERFACE_MAX_MARKERFEATURES];
    T_LDIF_FLOAT32       m_af32_FeaturePosV[LD_INTERFACE_MAX_MARKERFEATURES];
} S_LDMarkerFeatures;

typedef struct
{
    S_LDMarkerFeatures m_as_MarkerFeatures[LD_INTERFACE_NUM_MARKERS];
    T_LDIF_SINT64      m_i64_TimeStamp;
} S_LDOutputExtension;

typedef struct 
{
    T_LDIF_UINT32 m_u32_Number;  
    T_LDIF_UINT8  m_u8_Info[LD_INTERFACE_VERSION_INFO_LEN];
} S_LDVersion;
/*
typedef enum
{
  EVE_NO_ERROR = 0,
  EVE_ERROR
}LD_t_EVEError;
*/

/* LD interface typedefs of used services */

// service for cache invalidation
typedef void  (* Fct_v_CacheInvalidateAll)() ;

typedef void  (* Fct_v_CacheInvalidate)(void *p_MemLoc, T_LDIF_UINT32 u_NumBytes) ;

// service for starting a DMA transfer 
// (pv_Src -> pv_Dest)[sl_Size] 
// Note, Rhapsody removes argument names from pointer to function prototypes. There the names are documented here:
// typedef T_LDIF_SINT32 (*Fct_sl_DMACopy)(void *pv_Dest, void *pv_Src, T_LDIF_SINT32 sl_Size, T_LDIF_SINT32 *psl_Handle);
typedef T_LDIF_SINT32  (* Fct_sl_DMACopy)(void * , void * , T_LDIF_SINT32, T_LDIF_SINT32 * ) ;

// service for starting a chained DMA transfer 
// (pv_PreSrc -> pv_PreDest)[sl_PreSize] followed by 
// (pv_PostSrc-> pv_PostDest)[sl_PostSize]
// Note, Rhapsody removes argument names from pointer to function prototypes. There the names are documented here:
// typedef T_LDIF_SINT32 (*Fct_sl_DMACopyChained)(void *pv_PreDest, void *pv_PreSrc, T_LDIF_SINT32 sl_PreSize,
// void *pv_PostDest, void *pv_PostSrc, T_LDIF_SINT32 sl_PostSize,
// T_LDIF_SINT32 *psl_PostHandle);
typedef T_LDIF_SINT32  (* Fct_sl_DMACopyChained)(void * , void * , T_LDIF_SINT32, void * , void * , T_LDIF_SINT32, T_LDIF_SINT32 * ) ;

// service for waiting for the DMA transfer specified by sl_Handle
// Note, Rhapsody removes argument names from pointer to function prototypes. There the names are documented here:
// typedef T_LDIF_SINT32 (*Fct_sl_DMAWait)(T_LDIF_SINT32 sl_Handle);
typedef T_LDIF_SINT32  (* Fct_sl_DMAWait)(T_LDIF_SINT32) ;

// service for transferring data on the measurement interface
// Note, Rhapsody removes argument names from pointer to function prototypes. There the names are documented here:
// typedef T_LDIF_SINT32 (*Fct_sl_MeasFreeze)(void *pv_Buffer, T_LDIF_SINT32 sl_Size, T_LDIF_SINT32 sl_VirtualAddress);
typedef T_LDIF_SINT32  (* Fct_sl_MeasFreeze)(void const * , const T_LDIF_SINT32, const T_LDIF_SINT32) ;

// service for getting the cpu clock
typedef T_LDIF_UINT64  (* Fct_ul_GetHardwareTime)() ;

typedef T_LDIF_SINT32 (*Fct_sl_EVETrigger) (void* pBuffer, T_LDIF_UINT32 uBufferSize, T_LDIF_UINT32 uLocalID);

typedef T_LDIF_SINT32 (*Fct_sl_EVEWait) (void);

// Memlock functions

typedef T_LDIF_SINT32 (*Fct_sl_MemLock)       (void ** p_L2Buffer, T_LDIF_SINT32 * p_L2BuffSize, void ** p_L3Buffer, T_LDIF_SINT32 * p_L3BuffSize);

typedef T_LDIF_SINT32 (*Fct_sl_MemUnlock)     (void);

typedef T_LDIF_SINT32 (*Fct_sl_MemLockL2)     (void ** p_L2Buffer, T_LDIF_SINT32 * p_L2BuffSize);

typedef T_LDIF_SINT32 (*Fct_sl_MemUnlockL2)   (void);

typedef T_LDIF_SINT32 (*Fct_sl_MemLockL3)     (void ** p_L2Buffer, T_LDIF_SINT32 * p_L2BuffSize, void ** p_L3Buffer, T_LDIF_SINT32 * p_L3BuffSize);

typedef T_LDIF_SINT32 (*Fct_sl_MemUnlockL3)   (void);

typedef T_LDIF_SINT32 (*Fct_sl_MemUnlockAll)  (void);


T_LDIF_SINT32 sl_LDOpen(LDSystemInfo_t            * const ps_SystemInfo, 
                        const S_LDParameterIn     * const ps_ParameterIn, 
                        const S_LDParameterInOut  * const ps_ParameterInOut, 
                        Fct_v_CacheInvalidateAll    const pfct_v_CacheInvalidateAll, 
                        Fct_v_CacheInvalidate       const pfct_v_CacheInvalidate, 
                        Fct_sl_DMACopy              const pfct_sl_DMACopy, 
                        Fct_sl_DMACopyChained       const pfct_sl_DMACopyChained, 
                        Fct_sl_DMAWait              const pfct_sl_DMAWait, 
                        Fct_sl_MeasFreeze           const pfct_sl_MeasFreeze, 
                        Fct_ul_GetHardwareTime      const pfct_ul_GetHardwareTime,
                        Fct_sl_EVETrigger           const pfct_sl_EveTrigger,
                        Fct_sl_EVEWait              const pfct_sl_EveWait,
                        Fct_sl_MemLock              const pfct_sl_MemLock,
                        Fct_sl_MemUnlock            const pfct_sl_MemUnlock,
                        Fct_sl_MemLockL2            const pfct_sl_MemLockL2,
                        Fct_sl_MemUnlockL2          const pfct_sl_MemUnlockL2,
                        Fct_sl_MemLockL3            const pfct_sl_MemLockL3,
                        Fct_sl_MemUnlockL3          const pfct_sl_MemUnlockL3,
                        Fct_sl_MemUnlockAll         const pfct_sl_MemUnlockAll);

T_LDIF_SINT32 sl_LDRun( LDSystemInfo_t            * const ps_SystemInfo, 
                        void                      * pCIPP_Data,
                        void                      * pSTEREO_Data, // STEREOPROCESSING
                        const S_LDDynamicIn       * ps_LDDynamicIn);

T_LDIF_SINT32 sl_LDClose();

T_LDIF_SINT32 sl_LDGetLaneOutput(S_LDParameterInOut * const ps_LDParameterInOut, S_LDOutput * const ps_LDOutput);

T_LDIF_SINT32 sl_LDGetExtensionOutput(S_LDOutputExtension * const ps_LDOutputExtension);

T_LDIF_SINT32 sl_LDGetInternalState(void ** const ps_LDState, T_LDIF_UINT32 * const pul_LDStateLen);

T_LDIF_SINT32 sl_LDGetVersion(S_LDVersion * const ps_LDVersion);

void v_MapClothoidToRearAxle(const T_LDIF_FLOAT32 rl_Distance, const T_LDIF_FLOAT32 rl_OffsetIn, const T_LDIF_FLOAT32 rl_AngleIn, const T_LDIF_FLOAT32 rl_CurvatureIn, const T_LDIF_FLOAT32 rl_CurvatureRateIn, T_LDIF_FLOAT32 *prl_OffsetOut, T_LDIF_FLOAT32 *prl_AngleOut, T_LDIF_FLOAT32 *prl_CurvatureOut, T_LDIF_FLOAT32 *prl_CurvatureRateOut);

// BEGIN - Functions adapted from BMW-Code
void v_MirrorLaneToRear(const sMarker_RTE_Style_t s_MarkerIn, sMarker_RTE_Style_t *ps_MarkerOut, const T_LDIF_FLOAT32 rl_FactorLength, const T_LDIF_FLOAT32 rl_MaxAngleRAD, const T_LDIF_FLOAT32 rl_MaxAngleSCurveRAD);
void v_DetermineValidLengthBasedOnTangentAngleWithCurvatureChange(const T_LDIF_FLOAT32 rl_Sign, const T_LDIF_FLOAT32 rl_MaxAngleRAD, sMarker_RTE_Style_t *ps_Marker);
void v_DetermineValidLengthBasedOnTangentAngleWithoutCurvatureChange(const T_LDIF_FLOAT32 rl_Sign, const T_LDIF_FLOAT32 rl_MaxAngleRAD, sMarker_RTE_Style_t *ps_Marker);
// END - Functions adapted from BMW-Code

#ifdef __PC_SW
void* p_LDGetInternalAlgoPtr();
#endif

#ifdef __cplusplus
}
#endif
#endif
