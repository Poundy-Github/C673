

/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_Type.h
CESSAR-CT Version: 4.0.3.4
RTE Version: 4.0.3.1.2.0p06
Generated on:	Fri Feb 28 17:44:41 CET 2014
**************************************************************************/

/**************************************************************************
The AUTOSAR Types header file contains the the AUTOSAR data types 
and RTE implementation types definitions. [Satisfies_rte_sws_1160].
**************************************************************************/


#ifndef _RTE_TYPE_H_
#define _RTE_TYPE_H_

#include "Rte.h"    /* [Satisfies_rte_sws_1163] */

#define DB_TRANS_TYPE_VERSION 29

#define IN
#define OUT
#define INOUT




#define RTE_VENDOR_ID          (8)    /* [BSW00402]. */
#define RTE_MODULE_ID          (2)    /* [BSW00402]. */
#define RTE_AR_RELEASE_MAJOR_VERSION   (4)    /* [BSW00402], [BSW00318], [BSW004]. */
#define RTE_AR_RELEASE_MINOR_VERSION   (0)    /* [BSW00402], [BSW00318], [BSW004]. */
#define RTE_AR_RELEASE_REVISION_VERSION   (3)    /* [BSW00402], [BSW00318], [BSW004]. */
#define RTE_SW_MAJOR_VERSION   (1)    /* [BSW00402], [BSW00318], [BSW004]. */
#define RTE_SW_MINOR_VERSION   (2)    /* [BSW00402], [BSW00318], [BSW004]. */
#define RTE_SW_PATCH_VERSION   (0)    /* [BSW00402], [BSW00318]. */



/**********************************************/
/* User data types                            */
/**/

/* The user Data section contains the C type definitions of all AUTOSAR data types */
/* irrespective of their use by the generated RTE [Satisfies_rte_sws_2648].        */
typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;
typedef uint8 CompErrorCode_t           /* The error code if in a error state @min: 0 @max:1 @values: enum { COMP_ERROR_NO_ERROR=0,COMP_ERROR_UNKNOWN=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 CompState_t               /* The state of the algo @min: 0 @max:6 @values: enum { COMP_STATE_TEMPORARY_ERROR=2,COMP_STATE_NOT_INITIALIZED=0,COMP_STATE_SUCCESS=4,COMP_STATE_REDUCED_AVAILABILITY=5,COMP_STATE_RUNNING=1,COMP_STATE_NOT_RUNNING=6,COMP_STATE_PERMANENT_ERROR=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eShedulerModeRequest_t    /* Mode request to sheduler @min: 0 @max:4 @values: enum { COMP_MODE_REQ_RUN=2,COMP_MODE_REQ_RESET=1,COMP_MODE_REQ_PARALLEL=4,COMP_MODE_REQ_STANDALONE=3,COMP_MODE_REQ_NONE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eAssociatedLane_t         /* Lane enumeration @min: 0 @max:5 @values: enum { ASSOC_LANE_LEFT=2,ASSOC_LANE_FAR_RIGHT=5,ASSOC_LANE_FAR_LEFT=1,ASSOC_LANE_UNKNOWN=0,ASSOC_LANE_RIGHT=4,ASSOC_LANE_EGO=3,} */	/* [Satisfies_rte sws 1188] */;
typedef sint8 eObjOOI_t                 /* Object of interest enumeration @min: -1 @max:5 @values: enum { OBJ_NEXT_LAT_LEFT_OOI=4,OBJ_NEXT_LONG_LEFT_OOI=2,OBJ_NOT_OOI=-1,OBJ_NEXT_LONG_RIGHT_OOI=3,OBJ_NEXT_LAT_RIGHT_OOI=5,OBJ_NEXT_OOI=0,OBJ_HIDDEN_NEXT_OOI=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eRelObjLossReason_t       /* Relevant object loss reason @min: 0 @max:10 @values: enum { OBJ_LOSS_CURVE_RIGHT=5,OBJ_LOSS_DISAPPEARED=1,OBJ_LOSS_CURVE_RIGHT_AHEAD=7,OBJ_LOSS_CURVE_LEFT=4,OBJ_LOSS_STEER_LEFT=8,OBJ_LOSS_RANGE_REDUCTION=10,OBJ_LOSS_LANE_CHG_RIGHT=3,OBJ_LOSS_CURVE_LEFT_AHEAD=6,OBJ_LOSS_LANE_CHG_LEFT=2,OBJ_LOSS_STEER_RIGHT=9,OBJ_LOSS_NO_INFO=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 BaseOpMode_t              /* Required operation mode @min: 0 @max:44 @values: enum { BASE_OM_DISTANCE_TEST=16,BASE_OM_RUN_ODD=5,BASE_OM_HLA_SEG=44,BASE_OM_RUN_EVEN=6,BASE_OM_VCL_POSTPROC=43,BASE_OM_EM_MAINTENANCE=35,BASE_OM_IDLE=0,BASE_OM_MAX_RUNTIME=2,BASE_OM_VODCA_CLASSIFY=39,BASE_OM_AUTO_CHOICE=12,BASE_OM_MEAS_ONLY=8,BASE_OM_SYNC=7,BASE_OM_PED_RUN_CLUSTERING=27,BASE_OM_VCL_TRACK=42,BASE_OM_AUTOCAL_COARSE=10,BASE_OM_EM_UPDATE_SPC=34,BASE_OM_VODCA_PREPROCESS=38,BASE_OM_FEX_RUN_STARTUP_TEST_FPGA=21,BASE_OM_PED_RUN_IMAGE_TRACKING=26,BASE_OM_PED_RUN_HYPGEN=25,BASE_OM_FEX_RUN_INIT_FPGA=20,BASE_OM_SIB_GEOMETRY=36,BASE_OM_NVM_CALIB_RESET=40,BASE_OM_MEMO_SYNCVDY=28,BASE_OM_INIT_LUT=9,BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA=22,BASE_OM_DEMO=3,BASE_OM_RESET=1,BASE_OM_ECM_RTE_EOL=19,BASE_OM_EM_PREDICT=30,BASE_OM_SELF_EVAL=14,BASE_OM_ECM_RTE_DEV=18,BASE_OM_EM_UPDATE_PED=32,BASE_OM_ECM_RTE_TRANSMIT=17,BASE_OM_TEST=15,BASE_OM_EOL_UPDATE=13,BASE_OM_SIB_DYNAMIC=37,BASE_OM_AUTOCAL_FINE=11,BASE_OM_NVM_RESET=41,BASE_OM_FEX_RUN_SAC_DATA=23,BASE_OM_VCL_ROIGEN=29,BASE_OM_RUN=4,BASE_OM_EM_UPDATE_GEN=31,BASE_OM_FEX_RUN_PED_DATA=24,BASE_OM_EM_UPDATE_VCL=33,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 BaseSchedulingMode_t      /* Current scheduling sub-mode set by GlobalScheduler @min: 0 @max:6 @values: enum { BASE_SM_DEMO=3,BASE_SM_RUN=4,BASE_SM_RESET=1,BASE_SM_MAX_RUNTIME=2,BASE_SM_PARALLEL=6,BASE_SM_STANDALONE=5,BASE_SM_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteBswSchedulingMode_t /* Defines the current mode of the framework software
00u,    undefined, do not react to it
10u,    Software framework is running SAC in StandAlone Mode
20u     Software framework is running SAC in parallel to other functions @min: 0 @max:2 @values: enum { SAC_RTE_BSW_MODE_IN_RUNPARALLEL=2,SAC_RTE_BSW_MODE_IN_DEFAULT=0,SAC_RTE_BSW_MODE_IN_STANDALONE=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteCalibQuality_t      /* SAC_RTE_CalibQuality_undefined         = 0u,    !< undefined, ignore result 
SAC_RTE_CalibQuality_good              = 1u,    !< good quality 
SAC_RTE_CalibQuality_sufficient        = 3u,   !< sufficient quality (fine calibration should be able to compensate) 
SAC_RTE_CalibQuality_insufficient      = 6u     !< insufficient quality (coarse calibration required) @min: 0 @max:6 @values: enum { SAC_RTE_CalibQuality_good=1,SAC_RTE_CalibQuality_insufficient=6,SAC_RTE_CalibQuality_sufficient=3,SAC_RTE_CalibQuality_undefined=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteCorrespondenceMode_t /* @min: 0 @max:2 @values: enum { SAC_RTE_CM_DEFAULT=0,SAC_RTE_CM_TEMPORAL=1,SAC_RTE_CM_SPACIAL=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteDistTestCoordinate_t /* SAC_RTE_DSTM_CoordinateSystem_None = 0u,                      !< No coordinate system           
SAC_RTE_DSTM_CoordinateSystem_Vehicle  = 2u,                  !< Direction : Camera Coordinate system, Position : Ground below front axles, Unit : Meter  
SAC_RTE_DSTM_CoordinateSystem_Camera_rectified_image = 50u,   !< Direction : Image Coordinate system, Position : Rectified right Image, Unit : Pixel      
SAC_RTE_DSTM_CoordinateSystem_Camera_disparity_image = 70u    !< Direction : Image Coordinate system, Position : Disparity Image, Unit : Pixel @min: 0 @max:70 @values: enum { SAC_RTE_DSTM_CoordinateSystem_Camera_rectified_image=50,SAC_RTE_DSTM_CoordinateSystem_Vehicle=2,SAC_RTE_DSTM_CoordinateSystem_Camera_disparity_image=70,SAC_RTE_DSTM_CoordinateSystem_None=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteDistTestMode_t      /* 0u,    !< default mode, distance test only determines the angles but does not apply them
1u     !< distance mode determines angles and uses them to initialize the calibration (i.e. temperature model, last calib result) @min: 0 @max:1 @values: enum { SAC_RTE_DSTM_EVALUATE=0,SAC_RTE_DSTM_CALIBRATE=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteGbBlockageStatus_t  /* Blockage Status @min: 0 @max:6 @values: enum { SAC_RTE_GB_CONDENSATION=3,SAC_RTE_GB_PART_BLOCKAGE=4,SAC_RTE_GB_NO_BLOCKAGE=1,SAC_RTE_GB_TOLERATED_BLOCKAGE=2,SAC_RTE_GB_BLOCKAGE=6,SAC_RTE_GB_LOW_VISIBILITY=5,SAC_RTE_GB_UNKNOWN_STATUS=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteResult_t            /* SAC_RTE_Result_Default = undefined, ignore result
SAC_RTE_Result_Usable = SAC output can be used by other algorithms
SAC_RTE_Result_NotUsable = SAC output shall not be used by other algorithms @min: 0 @max:2 @values: enum { SAC_RTE_RESULT_NOT_USABLE=2,SAC_RTE_RESULT_USABLE=1,SAC_RTE_RESULT_DEFAULT=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteReturnState_t       /* SAC_RTE_Mode_Default                   = 00u,    !< undefined 
SAC_RTE_Mode_Test_Running              = 11u,    !< test mode, send defined set of output data 
SAC_RTE_Mode_Test_Finished             = 12u,    !< test mode, send defined set of output data 
SAC_RTE_Mode_Test_Failed               = 13u,    !< test mode, send defined set of output data 
SAC_RTE_Mode_MeasOnly_Running          = 21u,    !< MeasFreeze mode running, send MeasFreeze data only, output data invalid 
SAC_RTE_Mode_MeasOnly_Finished         = 22u,    !< MeasFreeze mode finished, send MeasFreeze data only, output data invalid 
SAC_RTE_Mode_MeasOnly_Failed           = 23u,    !< MeasFreeze mode failed, currently not used 
SAC_RTE_Mode_InitLUT_Running           = 31u,    !< LUT init running 
SAC_RTE_Mode_InitLUT_Finished          = 32u,    !< LUT init finished, resulting LUT can be used 
SAC_RTE_Mode_InitLUT_Failed            = 33u,    !< LUT init failed, resulting LUT cannot be used 
SAC_RTE_Mode_AutoCalCoarse_Running     = 41u,    !< coarse autocalibration still running, do not use resulting parameters/LUT 
SAC_RTE_Mode_AutoCalCoarse_Finished    = 42u,    !< coarse autocalibration finished, resulting camera paramters and LUT can be used
SAC_RTE_Mode_AutoCalCoarse_Failed      = 43u,    !< coarse autocalibration failed, do not use resulting parameters/LUT 
SAC_RTE_Mode_AutoCalFine_Running       = 51u,    !< fine autocalibration still running, do not use resulting parameters/LUT 
SAC_RTE_Mode_AutoCalFine_Finished      = 52u,    !< fine autocalibrationfinished, resulting camera paramters and LUT can be used 
SAC_RTE_Mode_AutoCalFine_Failed        = 53u,    !< fine calibration cannot compensate decalibration any longer -> e.g. coarse mode is required
SAC_RTE_Mode_EOLUpdate_Running         = 61u,    !< End of line update mode is running 
SAC_RTE_Mode_EOLUpdate_Finished        = 62u,    !< End of line update mode is finished, data can be used and stored in nvm 
SAC_RTE_Mode_EOLUpdate_Failed          = 63u,    !< End of line update mode failed, data are marked as invalid (can also be stored) 
SAC_RTE_Mode_SelfEval_Running          = 71u,    !< SelfEvaluation mode is running 
SAC_RTE_Mode_SelfEval_Finished         = 72u,    !< SelfEvaluation mode is finished, output is valid 
SAC_RTE_Mode_SelfEval_Failed           = 73u,    !< SelfEvaluation mode has failed, output is marked as invalid 
SAC_RTE_Mode_DistTest_Running          = 81u,    !< Distance test is running 
SAC_RTE_Mode_DistTest_Finished         = 82u,    !< Distance test is finished 
SAC_RTE_Mode_DistTest_Failed           = 83u     !< Distance test failed @min: 0 @max:83 @values: enum { SAC_RTE_Mode_InitLUT_Failed=33,SAC_RTE_Mode_EOLUpdate_Finished=62,SAC_RTE_Mode_DistTest_Running=81,SAC_RTE_Mode_EOLUpdate_Failed=63,SAC_RTE_Mode_Test_Running=11,SAC_RTE_Mode_AutoCalCoarse_Finished=42,SAC_RTE_Mode_Default=0,SAC_RTE_Mode_SelfEval_Failed=73,SAC_RTE_Mode_AutoCalFine_Running=51,SAC_RTE_Mode_InitLUT_Running=31,SAC_RTE_Mode_SelfEval_Finished=72,SAC_RTE_Mode_DistTest_Failed=83,SAC_RTE_Mode_MeasOnly_Running=21,SAC_RTE_Mode_Test_Failed=13,SAC_RTE_Mode_EOLUpdate_Running=61,SAC_RTE_Mode_DistTest_Finished=82,SAC_RTE_Mode_Test_Finished=12,SAC_RTE_Mode_AutoCalFine_Failed=53,SAC_RTE_Mode_MeasOnly_Failed=23,SAC_RTE_Mode_InitLUT_Finished=32,SAC_RTE_Mode_AutoCalCoarse_Failed=43,SAC_RTE_Mode_SelfEval_Running=71,SAC_RTE_Mode_MeasOnly_Finished=22,SAC_RTE_Mode_AutoCalCoarse_Running=41,SAC_RTE_Mode_AutoCalFine_Finished=52,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteSource_t            /* 00u,    !< default, source and data are invalid
20u,    !< source is existing data in non volatile memory 
30u,    !< source is end of line calibration data
40u,    !< source is coarse calibration data
50u,    !< source is fine calibration data
60u,    !< source is data from end of line update mode
70u,    !< source is data form self evaluation mode
80u,    !< source is data form the temperature model
90u     !< source is data form the Conti-EOL distance test @min: 0 @max:90 @values: enum { SAC_RTE_SRC_TempModel=80,SAC_RTE_SRC_EOL=30,SAC_RTE_SRC_AutoCalCoarse=40,SAC_RTE_SRC_AutoCalFine=50,SAC_RTE_SRC_DistanceTest=90,SAC_RTE_SRC_NVM=20,SAC_RTE_SRC_EOLUpdate=60,SAC_RTE_SRC_Invalid=0,SAC_RTE_SRC_SelfEval=70,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 GB_t_eHeatingActivationRequest /* Heating activation request @min: 1 @max:16 @values: enum { GB_HEATING_ON_BLOCKAGE=4,GB_HEATING_ON_CONDENSATION=2,GB_HEATING_ON_RAIN=8,GB_HEATING_ON_FOG=16,GB_HEATING_ON_UNKNOWN=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 GB_t_eStereoBlockageType  /* Stereo Blockage type @min: 2 @max:4 @values: enum { GB_LEFT_CAM=4,GB_RIGHT_CAM=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 GB_t_eVisibilityRange     /* Visibility Range @min: 0 @max:4 @values: enum { GB_MEDIUM_VISIBILITY_RANGE=3,GB_CLEAR_VISIBILITY_RANGE=1,GB_LOW_VISIBILITY_RANGE=4,GB_UNKNOWN_VISIBILITY_RANGE=0,GB_HIGH_VISIBILITY_RANGE=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 GB_t_eWeatherCondition    /* Weather condition @min: 2 @max:8 @values: enum { GB_FOG=4,GB_RAIN_SNOW=2,GB_GLARING_SUN=8,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWRoadEdgeWarn_t /* @min: 0 @max:5 @values: enum { e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_SNOW=3,e_FCTIF_ALDW_ROAD_EDGE_WARNING_OFF=0,e_FCTIF_ALDW_ROAD_EDGE_WARNING_ON=1,e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_GRASS=2,e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_RAISED=5,e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_CURBS=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWWarnShiftBound_t /* @min: 0 @max:3 @values: enum { e_FCTIF_ALDW_WARNING_SHIFT_BOUND_RIGHT=2,e_FCTIF_ALDW_WARNING_SHIFT_BOUND_OFF=0,e_FCTIF_ALDW_WARNING_SHIFT_BOUND_BOTH=3,e_FCTIF_ALDW_WARNING_SHIFT_BOUND_LEFT=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 LKA_VELOCITY_UNIT_t       /* @min: 0 @max:1 @values: enum { e_FCTIF_ALDW_VELOCITY_UNIT_MPH=1,e_FCTIF_ALDW_VELOCITY_UNIT_KMH=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 EBACodingParam_t          /* @min: 1 @max:2147483648 @values: enum { EBA_CODING_CROSSING_WARN=33554432,EBA_CODING_CROSSING_BRAKE=67108864,EBA_CODING_PED_WARN=262144,EBA_CODING_VEHICLES_BRAKE=16777216,EBA_CODING_PED_PREFILL=2097152,EBA_CODING_DEBUGMESSAGES=32,EBA_CODING_IGNORE_ACT_SWITCH=128,EBA_CODING_LATENT_WARN=134217728,EBA_CODING_LOW_SPEED=1,EBA_CODING_VCL_PRECRASH=268435456,EBA_CODING_IGN_SCHK=8,EBA_CODING_NO_FAILUREHANDLING=16,EBA_CODING_COUNTRY_A=2,EBA_CODING_COUNTRY_B=4,EBA_CODING_OBJMOVE_PREFILL=65536,EBA_CODING_OBJMOVE_WARN=8192,EBA_CODING_PED_PRECRASH=1048576,EBA_CODING_DISTANCELIMIT=64,EBA_CODING_OBJMOVE_BRAKE=16384,EBA_CODING_PED_HBA=4194304,EBA_CODING_PED_BRAKE=524288,EBA_CODING_OBJSTAT_BRAKE=512,EBA_CODING_OBJSTAT_WARN=256,EBA_CODING_OBJMOVE_HBA=131072,EBA_CODING_OBJSTAT_HBA=4096,EBA_CODING_OBJMOVE_PRECRASH=32768,EBA_CODING_OBJSTAT_PREFILL=2048,EBA_CODING_MAX=2147483648,EBA_CODING_VEHICLES_WARN=8388608,EBA_CODING_OBJSTAT_PRECRASH=1024,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 DimmingDetection_t        /* When active (value=RTE_HLA_DIMMDET_ACTIVE), enables the dimming algorithm due to bright objects and enables the ECU to send a request for reducing brightness of high beam 
(default value = RTE_HLA_DIMMDET_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_DIMMDET_INACTIVE=1,RTE_HLA_DIMMDET_ACTIVE=2,RTE_HLA_DIMMDET_UNKNOWN=0,RTE_HLA_DIMMDET_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_BlockageManualOverwrite /* When active (value=RTE_HLA_BLOCKMANOW_ACTIVE), allows the car user to enable the manual overwrite during the the clearance measurement. The manual overwrite will send a HB recommendation when no other turn off reason is active. The HB on could help the Blockage detection to come out of the unknown state.
(Default value = RTE_HLA_BLOCKMANOW_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_BLOCKMANOW_UNKNOWN=0,RTE_HLA_BLOCKMANOW_ACTIVE=2,RTE_HLA_BLOCKMANOW_INACTIVE=1,RTE_HLA_BLOCKMANOW_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_BadPixelDetection /* When active (value=RTE_HLA_BADPIXELDET_ACTIVE), enables the bad pixel detection algorithm which detects hot pixels.
(default value = RTE_HLA_BADPIXELDET_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_BADPIXELDET_INACTIVE=1,RTE_HLA_BADPIXELDET_ACTIVE=2,RTE_HLA_BADPIXELDET_UNKNOWN=0,RTE_HLA_BADPIXELDET_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_BlockageDetection /* When active (value=RTE_HLA_BLOCKAGE_ACTIVE), enables the blockage detection algorithm and clearance measurement after startup of the camera and enables the ECU to send the high beam deactivation reason code "blockage". 
(default value = RTE_HLA_BLOCKDET_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_BLOCKDET_INVALID=255,RTE_HLA_BLOCKDET_INACTIVE=1,RTE_HLA_BLOCKDET_ACTIVE=2,RTE_HLA_BLOCKDET_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_CityDetection     /* When active (value=RTE_HLA_CITYDET_ACTIVE), enables the street lamp (city) detection algorithm and enables the ECU to send the high beam deactivation reason code "city".
(default value = RTE_HLA_CITYDET_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_CITYDET_ACTIVE=2,RTE_HLA_CITYDET_INACTIVE=1,RTE_HLA_CITYDET_UNKNOWN=0,RTE_HLA_CITYDET_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_CountryCode       /* When active (value=RTE_HLA_COUNTRY_CODE_JP), enables additional algorithms optimzied for a better performance in Japan (e.g. city detection logic).
(default value = RTE_HLA_COUNTRY_CODE_NORMAL) @min: 0 @max:255 @values: enum { RTE_HLA_COUNTRY_CODE_JP=2,RTE_HLA_COUNTRY_CODE_INVALID=255,RTE_HLA_COUNTRY_CODE_NORMAL=1,RTE_HLA_COUNTRY_CODE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_FogDetection      /* When active (value=RTE_HLA_FOGDET_ACTIVE), activates the fog detection algorithm and enables the ECU to send the high beam deactivation reason code "fog".
(default value = RTE_HLA_FOGDET_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_FOGDET_UNKNOWN=0,RTE_HLA_FOGDET_ACTIVE=2,RTE_HLA_FOGDET_INACTIVE=1,RTE_HLA_FOGDET_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_HeadLightMechanics /* head light mechanics (roller, aperture, none = pixel light)
(default value = RTE_HLA_LMECH_ROLLER) @min: 0 @max:255 @values: enum { RTE_HLA_LMECH_INVALID=255,RTE_HLA_LMECH_NONE=3,RTE_HLA_LMECH_UNKNOWN=0,RTE_HLA_LMECH_ROLLER=1,RTE_HLA_LMECH_APERTURE=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_HeadlightType     /* head light type (Xenon, halogene, LED, Pixel, Laser)
(default value = RTE_HLA_LTYPE_LED) @min: 0 @max:255 @values: enum { RTE_HLA_LTYPE_LASER=5,RTE_HLA_LTYPE_INVALID=255,RTE_HLA_LTYPE_XENON=2,RTE_HLA_LTYPE_PIXEL=4,RTE_HLA_LTYPE_LED=3,RTE_HLA_LTYPE_HALOGENE=1,RTE_HLA_LTYPE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_MultipleReflectors /* When active (value=RTE_HLA_MREFL_ACTIVE), enables additional algorithms for better differentiation between strong reflecting objects and traffic participants (e.g. actived in Japan or Korea).
(default value = RTE_HLA_MREFL_INACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_MREFL_INACTIVE=1,RTE_HLA_MREFL_ACTIVE=2,RTE_HLA_MREFL_UNKNOWN=0,RTE_HLA_MREFL_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_SpotLight         /* spot light installed (avl, not avl)
(default value = RTE_HLA_SPOTLIGHT_NAVL) @min: 0 @max:255 @values: enum { RTE_HLA_SPOTLIGHT_NAVL=2,RTE_HLA_SPOTLIGHT_INVALID=255,RTE_HLA_SPOTLIGHT_UNKNOWN=0,RTE_HLA_SPOTLIGHT_AVL=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_TestMode          /* When active (value=RTE_HLA_TESTMODE_SAE), some special Algos (Blockage detection, clearance measurement, Bad Pixel detection) will be switched off which interfere the Test, especially when the SAE test is done in lab.
(default value = RTE_HLA_TESTMODE_INACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_TESTMODE_INACTIVE=1,RTE_HLA_TESTMODE_TEST_IMAGE=7,RTE_HLA_TESTMODE_SEG_AUTOTHRES_OFF=4,RTE_HLA_TESTMODE_SEG_ALWAYS_ON=5,RTE_HLA_TESTMODE_LAB=8,RTE_HLA_TESTMODE_2=10,RTE_HLA_TESTMODE_INVALID=255,RTE_HLA_TESTMODE_4=12,RTE_HLA_TESTMODE_1=9,RTE_HLA_TESTMODE_NO_CLEARMEAS=6,RTE_HLA_TESTMODE_3=11,RTE_HLA_TESTMODE_SAE=2,RTE_HLA_TESTMODE_UNKNOWN=0,RTE_HLA_TESTMODE_ECE=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_TunnelDetection   /* When active (value=RTE_HLA_TUNNELDET_ACTIVE), enables the tunnel detection algorithm and enables the ECU to send the high beam deactivation reason code "tunnel".
(default value = RTE_HLA_TUNNELDET_ACTIVE) @min: 0 @max:255 @values: enum { RTE_HLA_TUNNELDET_ACTIVE=2,RTE_HLA_TUNNELDET_INACTIVE=1,RTE_HLA_TUNNELDET_UNKNOWN=0,RTE_HLA_TUNNELDET_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_WindshieldType    /* wind shield type (clear , green , blue, ...)
(default value = RTE_HLA_WTYPE_UNKNOWN) @min: 0 @max:255 @values: enum { RTE_HLA_WTYPE_UNKNOWN=0,RTE_HLA_WTYPE_INVALID=255,RTE_HLA_WTYPE_GREEN=3,RTE_HLA_WTYPE_BULLETPROOF=5,RTE_HLA_WTYPE_BLUE=4,RTE_HLA_WTYPE_CLEAR1=1,RTE_HLA_WTYPE_CLEAR2=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SrCountryVariationVehicle_t /* market for which vehicle was produced @min: 0 @max:2147483647 @values: enum { SR_RTE_COUNTRY_VARIATION_INT_MAX=2147483647,SR_RTE_COUNTRY_VARIATION_JPCN=6,SR_RTE_COUNTRY_VARIATION_GULF=2,SR_RTE_COUNTRY_VARIATION_ROW=5,SR_RTE_COUNTRY_VARIATION_CANADA=4,SR_RTE_COUNTRY_VARIATION_ECE=1,SR_RTE_COUNTRY_VARIATION_UNKNOWN=0,SR_RTE_COUNTRY_VARIATION_USA=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SrFeatureMaster_t         /* bitfield switches for various SR features, e.g. city limits, US signs, etc. @min: 0 @max:2147483647 @values: enum { SR_RTE_FEATURE_CONFIG_NOCIRCLE=2,SR_RTE_FEATURE_CONFIG_NONE=0,SR_RTE_FEATURE_CONFIG_CITYLIMIT=1,SR_RTE_FEATURE_CONFIG_INT_MAX=2147483647,SR_RTE_FEATURE_CONFIG_RECTANGULAR=64,SR_RTE_FEATURE_CONFIG_DISABLED=16,SR_RTE_FEATURE_CONFIG_SKIPFRAME=4,SR_RTE_FEATURE_CONFIG_CIRCLE=256,SR_RTE_FEATURE_CONFIG_TRUCKSTICKER=32,SR_RTE_FEATURE_CONFIG_PLAYSTREET=8,SR_RTE_FEATURE_CONFIG_DIAMOND=512,SR_RTE_FEATURE_CONFIG_TRIANGULAR=128,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SrTsmCountryVariation_t   /* market for which vehicle was produced @min: 1 @max:2147483647 @values: enum { SR_RTE_TSM_COUNTRY_VARIATION_ECE=1,SR_RTE_TSM_COUNTRY_VARIATION_GULF=6,SR_RTE_TSM_COUNTRY_VARIATION_USA=2,SR_RTE_TSM_COUNTRY_VARIATION_ENGLAND=4,SR_RTE_TSM_COUNTRY_VARIATION_AUSTRALIA=10,SR_RTE_TSM_COUNTRY_VARIATION_COREA=8,SR_RTE_TSM_COUNTRY_VARIATION_INT_MAX=2147483647,SR_RTE_TSM_COUNTRY_VARIATION_CHINA=7,SR_RTE_TSM_COUNTRY_VARIATION_GERMANY=3,SR_RTE_TSM_COUNTRY_VARIATION_JAPAN=9,SR_RTE_TSM_COUNTRY_VARIATION_CANADA=5,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteInputCheckerMode_t  /* switches input checker on or off @min: 0 @max:1 @values: enum { SAC_RTE_INPUT_CHECKER_MODE_OFF=1,SAC_RTE_INPUT_CHECKER_MODE_ON=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteOutputCheckerMode_t /* switches output checker on or off @min: 0 @max:1 @values: enum { SAC_RTE_OUTPUT_CHECKER_MODE_ON=0,SAC_RTE_OUTPUT_CHECKER_MODE_OFF=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaControlFlow_t          /* operating mode switch @min: 0 @max:3 @values: enum { TSA_RTE_CONTROL_FLOW_NORMAL=0,TSA_RTE_CONTROL_FLOW_SKIP_KERNEL=1,TSA_RTE_CONTROL_FLOW_DEBUG=3,TSA_RTE_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaCountryVariationVehicle_t /* market for which vehicle was produced @min: 0 @max:6 @values: enum { TSA_RTE_COUNTRY_VARIATION_ECE=1,TSA_RTE_COUNTRY_VARIATION_CANADA=4,TSA_RTE_COUNTRY_VARIATION_GULF=2,TSA_RTE_COUNTRY_VARIATION_USA=3,TSA_RTE_COUNTRY_VARIATION_ROW=5,TSA_RTE_COUNTRY_VARIATION_JPCN=6,TSA_RTE_COUNTRY_VARIATION_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 countryConfig_t           /* bitfield switches for various TSA features @min: 0 @max:2147483647 @values: enum { TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_ENABLED=64,TSA_RTE_COUNTRY_CONFIG_SLA_HMI_DISABLE_SPDLMT_END=0,TSA_RTE_COUNTRY_CONFIG_SLA_ENABLE_IMPLICIT_RULES=32,TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_MID=2,TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_OFF=0,TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_DISABLED=0,TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_IGNORE=12,TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_ENABLED=128,TSA_RTE_COUNTRY_CONFIG_SLA_DISABLE_IMPLICIT_RULES=0,TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_ALWAYS=0,TSA_RTE_COUNTRY_CONFIG_SLA_HMI_ENABLE_SPDLMT_END=16,TSA_RTE_COUNTRY_CONFIG_INT_MAX=2147483647,TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_HIGH=3,TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_ENTRY=1,TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_DISABLED=0,TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NOT_RESOLVED=4,TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NEVER=8,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 CippErrorCode_t           /* The error code if in a error state @min: 0 @max:17 @values: enum { CIPP_ERROR_UNKNOWN=1,CIPP_ERROR_INPUT_ODD_FRAMEFORMAT_NOT_SUPPORTED=11,CIPP_ERROR_INPUT_PORT_LIST_NULL_PTR=3,CIPP_ERROR_INPUT_CFA_ALIGNMENT_NOT_SUPPORTED=10,CIPP_ERROR_INPUT_SERVICE_NULL_PTR=6,CIPP_ERROR_INPUT_EVEN_FRAMEFORMAT_NOT_SUPPORTED=12,CIPP_ERROR_OUTPUT_BUFFER_NULL_PTR=9,CIPP_ERROR_INPUT_DATA_NULL_PTR=5,CIPP_ERROR_EVE_EVEN=15,CIPP_ERROR_OUTPUT_PORT_NULL_PTR=8,CIPP_ERROR_INPUT_SIG_STATE_INVALID=16,CIPP_ERROR_OUTPUT_PORT_LIST_NULL_PTR=7,CIPP_ERROR_INPUT_PORT_NULL_PTR=4,CIPP_ERROR_EVE_ODD=14,CIPP_ERROR_NO_ERROR=0,CIPP_ERROR_ALGO_NOT_INITIALIZED=17,CIPP_ERROR_OPMODE_NOT_SUPPORTED=2,CIPP_ERROR_RROI_FRAMEFORMAT_NOT_SUPPORTED=13,} */	/* [Satisfies_rte sws 1188] */;
typedef uint16 DisparityElement_t        /* Bitfield encoding the disparity (8.3bit signed) and the according valid bit */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_SensorSource       /* Enumberation to identify the sensor reporting an specific object list @min: 0 @max:9 @values: enum { EMB0_OBJECT_LIST_SOURCE_LRR=1,EMB0_OBJECT_LIST_SOURCE_SCAM=9,EMB0_OBJECT_LIST_SOURCE_MCAM=8,EMB0_OBJECT_LIST_SOURCE_SRL=7,EMB0_OBJECT_LIST_SOURCE_SRR_FR=4,EMB0_OBJECT_LIST_SOURCE_SRR_RR=6,EMB0_OBJECT_LIST_SOURCE_SRR_RL=5,EMB0_OBJECT_LIST_SOURCE_SRR_FL=3,EMB0_OBJECT_LIST_SOURCE_NONE=0,EMB0_OBJECT_LIST_SOURCE_MRR=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_Service            /* Common status qualifier. @min: 0 @max:255 @values: enum { EMB0_QS_NOT_OK=2,EMB0_QS_INIT=0,EMB0_QS_SNA=255,EMB0_QS_OK=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_DrivingTubeMapping /* Association to the driving lane of the object. @min: 0 @max:255 @values: enum { EMB0_DTM_SNA=255,EMB0_DTM_EGO_LANE=1,EMB0_DTM_NEXT_RIGHT=4,EMB0_DTM_FAR_RIGHT=5,EMB0_DTM_NEXT_LEFT=2,EMB0_DTM_FAR_LEFT=3,EMB0_DTM_INIT_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_EventDataQualifier /* The qualifier expresses whether the content of this event can be used or not. @min: 0 @max:255 @values: enum { EMB0_CEDQ_EVENT_DATA_AVAILABLE=0,EMB0_CEDQ_SNA=255,EMB0_CEDQ_EVENT_DATA_AVAILABLE_REDUCED=1,EMB0_CEDQ_EVENT_DATA_NOT_AVAILABLE=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ExtendedQualifier  /* The extendedQualifier describes the reason (not the effect) why the service is reduced or not available. @min: 0 @max:255 @values: enum { EMB0_CEQ_SENSOR_NOT_CALIBRATED=2,EMB0_CEQ_INTERNAL_REASON=8,EMB0_CEQ_INPUT_NOT_AVAILABLE=7,EMB0_CEQ_NORMAL_OPERATION_MODE=0,EMB0_CEQ_POWER_UP_OR_DOWN=1,EMB0_CEQ_SNA=255,EMB0_CEQ_BAD_SENSOR_ENVIRONMENTAL_CONDITION=5,EMB0_CEQ_SENSOR_BLOCKED=3,EMB0_CEQ_BEGINNING_BLOCKAGE=10,EMB0_CEQ_SENSOR_MISALIGNED=4,EMB0_CEQ_EXTERNAL_DISTORTION=9,EMB0_CEQ_REDUCED_FIELD_OF_VIEW=6,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 EMB0_t_Flags              /* Discribes the invalidity of separate object signals @min: 1 @max:2147483648 @values: enum { EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID=524288,EMB0_MSDVF_STD_DEV_ACCEL_YAW_ANGLE_INVALID=4194304,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID=2097152,EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID=8192,EMB0_DVF_WIDTH_INVALID=16,EMB0_DVF_LENGTH_INVALID=8,EMB0_MIVF_ACCEL_YAW_ANGLE_INVALID=1024,EMB0_DVF_HEIGHT_INVALID=32,EMB0_FLAGS_SNA=2147483648,EMB0_PVF_POSITION_Y_INVALID=2,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID=262144,EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID=64,EMB0_PSDVF_STD_DEV_WIDTH_INVALID=65536,EMB0_MSDVF_STD_DEV_ACCEL_YAW_SPEED_INVALID=8388608,EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID=128,EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID=256,EMB0_PVF_POSITION_X_INVALID=1,EMB0_PVF_POSITION_Z_INVALID=4,EMB0_MIVF_ACCEL_YAW_SPEED_INVALID=2048,EMB0_PSDVF_STD_DEV_HEIGHT_INVALID=131072,EMB0_PSDVF_STD_DEV_LENGTH_INVALID=32768,EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID=16384,EMB0_PSDVF_STD_DEV_POSITION_X_INVALID=4096,EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID=512,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID=1048576,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_MeasurementStatus  /* Measurement status of object, e.g. measured, predicted, etc. @min: 0 @max:255 @values: enum { EMB0_CMS_MEAS_PART_OCCL=3,EMB0_CMS_MEAS_NEW=0,EMB0_CMS_MEAS=2,EMB0_CMS_SNA=255,EMB0_CMS_MEAS_NEW_PART_OCCL=1,EMB0_CMS_PRED_PART_OCCL=5,EMB0_CMS_PRED=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ObjBrakeLightStat  /* This enum provides a status of the brake light of the object. @min: 0 @max:255 @values: enum { EMB0_BLS_NO_BRAKING=1,EMB0_BLS_REGULAR_BRAKING=2,EMB0_BLS_HEAVY_BREAKING=3,EMB0_BLS_STATUS_UNKNOWN=0,EMB0_BLS_SNA=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ObjFlashLightStat  /* Status of the flash light of the object. @min: 0 @max:255 @values: enum { EMB0_OFS_SNA=255,EMB0_OFS_HAZARD_FLASHING=4,EMB0_OFS_NO_FLASHING=1,EMB0_OFS_STATUS_UNKNOWN=0,EMB0_OFS_FLASHING_LEFT=2,EMB0_OFS_FLASHING_RIGHT=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ObjectModeLateral  /* Movement status lateral. @min: 0 @max:255 @values: enum { EMB0_OML_SNA=255,EMB0_OML_CUTTING_IN_FROM_LEFT=1,EMB0_OML_NONE=5,EMB0_OML_CUTTING_OUT_TO_LEFT=3,EMB0_OML_UNKNOWN=0,EMB0_OML_CUTTING_OUT_TO_RIGHT=4,EMB0_OML_CUTTING_IN_FROM_RIGHT=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ObjectMovementStatus /* Movement status of object, e.g. moving in own direction, stopped, etc. @min: 0 @max:255 @values: enum { EMB0_OMS_SNA=255,EMB0_OMS_STOPPED_WAS_ONGOING=2,EMB0_OMS_STATIONARY_PARKING=0,EMB0_OMS_STOPPED_WAS_UNKNOWN=3,EMB0_OMS_MOVING_ONGOING=5,EMB0_OMS_MOVING_ONCOMMING=4,EMB0_OMS_MOVING_DIR_UNKNOWN=6,EMB0_OMS_STOPPED_WAS_ONCOMING=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ObjectReferencePoint /* This enum identifies the corner of the object the sensor has observed. The whole measurement originates from the reference point. @min: 0 @max:255 @values: enum { EMB0_ORP_CORNER_FRONT_LEFT=0,EMB0_ORP_CORNER_REAR_LEFT=6,EMB0_ORP_MIDDLE_SIDE_RIGHT=3,EMB0_ORP_CORNER_REAR_RIGHT=4,EMB0_ORP_SNA=255,EMB0_ORP_MIDDLE_SIDE_LEFT=7,EMB0_ORP_MIDDLE_FRONT=1,EMB0_ORP_CORNER_FRONT_RIGHT=2,EMB0_ORP_MIDDLE_REAR=5,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EMB0_t_ObjectType         /* Discrete classification type based on probabilities within the classification vector. This is the most likely type of the object based on the classification. @min: 0 @max:255 @values: enum { EMB0_OT_ROAD_BOUNDARY=6,EMB0_OT_MOTORBIKE=2,EMB0_OT_TRUCK=4,EMB0_OT_SNA=255,EMB0_OT_UNKNOWN=8,EMB0_OT_CYCLIST=1,EMB0_OT_PEDESTRIAN=0,EMB0_OT_CAR=3,EMB0_OT_OTHER_VEHICLE=5,EMB0_OT_BRIDGE=7,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_CustomerProjectDef   /* Indicator to identify application projects @min: 0 @max:1 @values: enum { EM_PRJ_SMFC4B0=1,EM_PRJ_MFC400=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_CamObjAssociatedLane /* Mapping of the object to a lane @min: 0 @max:255 @values: enum { EM_CAM_OBJ_ASSOC_LANE_UNKNOWN=0,EM_CAM_OBJ_ASSOC_LANE_RIGHT=3,EM_CAM_OBJ_ASSOC_LANE_SNA=255,EM_CAM_OBJ_ASSOC_LANE_LEFT=2,EM_CAM_OBJ_ASSOC_LANE_OUTSIDE=4,EM_CAM_OBJ_ASSOC_LANE_EGO=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_CamObjStatusBrakeLight /* Status of brake light detection @min: 0 @max:255 @values: enum { EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING=1,EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING=3,EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN=0,EM_CAM_OBJ_BRAKE_LIGHT_SNA=255,EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_CamObjStatusFlashLight /* Status of flash light detection @min: 0 @max:255 @values: enum { EM_CAM_OBJ_FLASH_LIGHT_UNKNOWN=0,EM_CAM_OBJ_FLASH_LIGHT_FLASHING_LEFT=2,EM_CAM_OBJ_FLASH_LIGHT_HAZARD_FLASHING=4,EM_CAM_OBJ_FLASH_LIGHT_FLASHING_RIGHT=3,EM_CAM_OBJ_FLASH_LIGHT_SNA=255,EM_CAM_OBJ_FLASH_LIGHT_NO_FLASHING=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjClassification /* This signal indicates the class of the object.
Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles @min: 0 @max:8 @values: enum { EM_GEN_OBJECT_CLASS_TRUCK=2,EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES=8,EM_GEN_OBJECT_CLASS_WIDE=6,EM_GEN_OBJECT_CLASS_PEDESTRIAN=3,EM_GEN_OBJECT_CLASS_CAR=1,EM_GEN_OBJECT_CLASS_POINT=0,EM_GEN_OBJECT_CLASS_BICYCLE=5,EM_GEN_OBJECT_CLASS_MOTORCYCLE=4,EM_GEN_OBJECT_CLASS_UNCLASSIFIED=7,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjDynamicProperty /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:7 @values: enum { EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT=3,EM_GEN_OBJECT_DYN_PROPERTY_STOPPED=6,EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT=4,EM_GEN_OBJECT_DYN_PROPERTY_MOVING=0,EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING=2,EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY=1,EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN=5,EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES=7,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjEbaProhibit    /* Activation suppression in EBA @min: 0 @max:5 @values: enum { EM_EBA_PROHIBIT_MAX_DIFF_TYPES=5,EM_EBA_PROHIBIT_PREFILL=3,EM_EBA_PROHIBIT_ACUTEBRAKE=1,EM_EBA_PROHIBIT_WARN=4,EM_EBA_PROHIBIT_PREBRAKE=2,EM_EBA_PROHIBIT_NO=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjMaintenanceState /* Indicate the adminstration state of object @min: 0 @max:4 @values: enum { EM_GEN_OBJECT_MT_STATE_NEW=1,EM_GEN_OBJECT_MT_STATE_DELETED=0,EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES=4,EM_GEN_OBJECT_MT_STATE_MEASURED=2,EM_GEN_OBJECT_MT_STATE_PREDICTED=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjOcclusionState /* Describes if/how Object is covered by closer objects in sensing direction. @min: 0 @max:4 @values: enum { EM_GEN_OBJECT_OCCL_PARTLY=2,EM_GEN_OBJECT_OCCL_FULL=3,EM_GEN_OBJECT_OCCL_NONE=0,EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES=4,EM_GEN_OBJECT_OCCL_UNKNOWN=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint16 EM_t_GenObjSensorSource   /* Bitfield for a combination of given enum values to point out what sensor participated at measurement of the object. @min: 0 @max:512 @values: enum { EM_GEN_OBJECT_MS_NONE=0,EM_GEN_OBJECT_MS_LRR=1,EM_GEN_OBJECT_MS_SRR=4,EM_GEN_OBJECT_MS_MRR=2,EM_GEN_OBJECT_MS_MCAM=256,EM_GEN_OBJECT_MS_SCAM=512,EM_GEN_OBJECT_MS_SRL=16,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjShapePointState /* State of shape point at index @min: 0 @max:4 @values: enum { EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED=1,EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID=0,EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE=3,EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED=2,EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EM_t_GenObjSplitMergeState /* Additional Information indicating a merge or split operation @min: 0 @max:3 @values: enum { EM_GEN_OBJECT_SM_STATE_NONE=0,EM_GEN_OBJECT_SM_STATE_SPLIT=2,EM_GEN_OBJECT_SM_STATE_MERGE=1,EM_GEN_OBJECT_SM_STATE_MAX_DIFF_TYPES=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EcmRteOpMode_t            /* Required operation mode @min: 0 @max:6 @values: enum { ECM_RTE_OPMODE_IDLE=0,ECM_RTE_OPMODE_DEV=2,ECM_RTE_OPMODE_TRANSMIT=6,ECM_RTE_OPMODE_RESET=1,ECM_RTE_OPMODE_EOL=3,ECM_RTE_OPMODE_MAX_RUNTIME=4,ECM_RTE_OPMODE_DEMO=5,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EcmRteCurMarker_t         /* @min: 0 @max:2 @values: enum { ECM_RTE_LEFT_MARKER=1,ECM_RTE_MID_MARKER=0,ECM_RTE_RIGHT_MARKER=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 EcmRteError_t             /* detailed error state bitfield @min: 0 @max:1073741824 @values: enum { ECM_RTE_TYPE_ERR_PATTERN_POSITION_INVALID=134217728,ECM_RTE_TYPE_ERR_UNKNOWN_ECM_RTE_MODE=8192,ECM_RTE_TYPE_WARN_CONTRAST_ABOVE_RANGE=256,ECM_RTE_TYPE_ERR_UNKNOWN_PATTERN_TYPE=16384,ECM_RTE_TYPE_SUCCESS=2,ECM_RTE_TYPE_ERR_PATTERN_ECU_MOVING=67108864,ECM_RTE_TYPE_ERR_INTENSITY_BELOW_RANGE=262144,ECM_RTE_TYPE_ERR_RESULT_OUT_OF_RANGE=536870912,ECM_RTE_TYPE_ERR_UNCORRESPONDING_MARKERS=33554432,ECM_RTE_TYPE_ERR_TOO_MANY_MARKERS=16777216,ECM_RTE_TYPE_NOT_STARTED=0,ECM_RTE_TYPE_WARN_INTENSITY_ABOVE_RANGE=64,ECM_RTE_TYPE_WARN_OTHER=512,ECM_RTE_TYPE_ERR_VIN_INVALID=4096,ECM_RTE_TYPE_ERR_SYSTEM_NOT_ECMBRATED=2048,ECM_RTE_TYPE_ERR_OTHER=1073741824,ECM_RTE_TYPE_ERR_INTENSITY_INHOMOGEN=131072,ECM_RTE_TYPE_ERR_CONTRAST_BELOW_RANGE=1048576,ECM_RTE_TYPE_ERROR=4,ECM_RTE_TYPE_ERR_NUMERIECM_RTE_PROBLEM=268435456,ECM_RTE_TYPE_RUNNING=1,ECM_RTE_TYPE_ERR_NOT_ENOUGH_MARKERS=8388608,ECM_RTE_TYPE_ERR_PARAMETER_FALSE=65536,ECM_RTE_TYPE_WARN_CONTRAST_BELOW_RANGE=128,ECM_RTE_TYPE_ERR_INIT_DATA_FAILED=32768,ECM_RTE_TYPE_WARN_INTENSITY_INHOMOGEN=16,ECM_RTE_TYPE_ERR_CONTRAST_ABOVE_RANGE=2097152,ECM_RTE_TYPE_ERR_INTENSITY_ABOVE_RANGE=524288,ECM_RTE_TYPE_WARN_INTENSITY_BELOW_RANGE=32,ECM_RTE_TYPE_ERR_NO_MARKERS=4194304,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EcmRtePatPos_t            /* enum defining the pattern position on the calibration board
left calibration board position
mid calibration board position
right calibration board position @min: 0 @max:2 @values: enum { ECM_RTE_PAT_POS_MID=1,ECM_RTE_PAT_POS_RIGHT=2,ECM_RTE_PAT_POS_LEFT=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EcmRteProcRoiState_t      /* @min: 0 @max:9 @values: enum { ECM_RTE_PROC_SEARCH_CIRCLE_STATE=1,ECM_RTE_PROC_FINE_POSITIONING_STATE=2,ECM_RTE_PROC_ERROR=9,ECM_RTE_PROC_PATTERN_LOCATED=8,ECM_RTE_PROC_SAVE_CIRCLE_POS_STATE=3,ECM_RTE_PROC_FIND_CORRESPOND_CIRCLE_STATE=6,ECM_RTE_PROC_ECMC_CORRESPOND_CIRCLE_STATE=4,ECM_RTE_PROC_PATTERN_NOT_VERIFIED=7,ECM_RTE_PROC_INIT_STATE=0,ECM_RTE_PROC_CHANGE_PATTERN_STATE=5,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eConstructionSiteState_t  /* Indicates the state of the construction site detection. Construction site state is true if the vehicle moves inside a construction site area @min: 0 @max:4294967295 @values: enum { CS_State_init=0,CS_State_error=2147483647,CS_State_true=2,CS_State_unfilled=4294967295,CS_State_false=4,CS_State_notAvailable=252,CS_State_unknown=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eForesightIndicatorType_t /* Identifies the indicator that triggered the foresight flag. @min: 1 @max:4294967295 @values: enum { CS_FORESIGHT_Indicator_unexpOppTraffic=512,CS_FORESIGHT_Indicator_notAvailable=2147483647,CS_FORESIGHT_Indicator_singleMarker=16,CS_FORESIGHT_Indicator_init=1,CS_FORESIGHT_Indicator_undefType=1073741823,CS_FORESIGHT_Indicator_multMarkers=64,CS_FORESIGHT_Indicator_precedingVehicles=256,CS_FORESIGHT_Indicator_XingMarkers=8,CS_FORESIGHT_Indicator_unfilled=4294967295,CS_FORESIGHT_Indicator_doubleMarker=32,CS_FORESIGHT_Indicator_CSSign=2,CS_FORESIGHT_Indicator_egoSpeedProfile=128,CS_FORESIGHT_Indicator_SpeedLimitCascade=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eForesightState_t         /* Construction site indicators have been detected in front of the vehicle (characteristic markers) or  respectively in front of the construction site (traffic signs). @min: 1 @max:4294967295 @values: enum { CS_FORESIGHT_notAvailable=2147483647,CS_FORESIGHT_init=1,CS_FORESIGHT_true=4,CS_FORESIGHT_false=8,CS_FORESIGHT_unknown=2,CS_FORESIGHT_unfilled=4294967295,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDegradationReason_t      /* Cause of degradation if known @min: 0 @max:4 @values: enum { EM_VD_DR_RAIN=2,EM_VD_DR_UNKNOWN=0,EM_VD_DR_NONE=1,EM_VD_DR_DIRECT_SUN=4,EM_VD_DR_FOG=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 EmoAvailability_t         /* egomotion signal availability @min: 0 @max:3 @values: enum { EMO_AVAILABILITY_NOT_OK=0,EMO_AVAILABILITY_ERROR=3,EMO_AVAILABILITY_OK=2,EMO_AVAILABILITY_LIMITED=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eEmoInputSource_t         /* source of egomotion @min: 0 @max:2 @values: enum { EMO_SOURCE_VDY_ONLY=1,EMO_SOURCE_IMAGE_ONLY=0,EMO_SOURCE_IMAGE_AND_VDY=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eEmoMotState_t            /* Moving (forward or reverse)
Moving forward
Moving reverse
Stand still @min: 0 @max:3 @values: enum { EMO_MOT_STATE_MOVE_RWD=2,EMO_MOT_STATE_MOVE=0,EMO_MOT_STATE_STDST=3,EMO_MOT_STATE_MOVE_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 uiStatus_t                /* Online calibration status @min: 0 @max:5 @values: enum { EMO_MAC_STATUS_CALIBRATED=1,EMO_MAC_STATUS_ERROR_OTHER=5,EMO_MAC_STATUS_DIST_EXCEEDED=3,EMO_MAC_STATUS_ERROR_DEADJUSTMENT=4,EMO_MAC_STATUS_CAM_BLOCKED=2,EMO_MAC_STATUS_NOT_CALIBRATED=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eLkaAldwMode_t            /* ENUM selected ALDW mode @min: 0 @max:3 @values: enum { Lka_aldw_mode_off=0,Lka_aldw_mode_ldw=1,Lka_aldw_mode_aldw=3,Lka_aldw_mode_aldw_light=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWStatus_t      /* ALDW function status @min: 0 @max:2 @values: enum { e_FCTIF_ALDW_STATUS_ON_INACTIVE=1,e_FCTIF_ALDW_STATUS_ON_ACTIVE=2,e_FCTIF_ALDW_STATUS_OFF=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWWarnSuppStat_t /* Suppression status @min: 0 @max:9 @values: enum { e_FCTIF_ALDW_DRV_ACTV=2,e_FCTIF_ALDW_WARN=7,e_FCTIF_ALDW_DRV_DISTRACTION=4,e_FCTIF_ALDW_WARN_RDY=1,e_FCTIF_ALDW_WARN_DELAY=8,e_FCTIF_ALDW_DRV_ACTV_DELAY=3,e_FCTIF_ALDW_SYS_ACTIV=9,e_FCTIF_ALDW_TURN=5,e_FCTIF_ALDW_OFF_SPD=0,e_FCTIF_ALDW_TURN_DELAY=6,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWWarnVel_t     /* Velocity is in envelope where Warning algoritm can be available @min: 0 @max:1 @values: enum { e_FCTIF_ALDW_VEL_OFF=0,e_FCTIF_ALDW_VEL_ACTV=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWWrnMdRq_t     /* Warning mode request =Mode_1/Mode_2 @min: 0 @max:1 @values: enum { e_FCTIF_ALDW_MODE_2=1,e_FCTIF_ALDW_MODE_1=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 E_FCTIF_ALDWWrnRq_t       /* Warning request @min: 0 @max:2 @values: enum { e_FCTIF_ALDW_WARN_LT=1,e_FCTIF_ALDW_WARN_RT=2,e_FCTIF_ALDW_WARN_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 DIMInputSignalState_t     /* status of the steering wheel angle @min: 0 @max:5 @values: enum { DIMInputSignalState_OK=0,DIMInputSignalState_Default=1,DIMInputSignalState_BadQuality=3,DIMInputSignalState_Missing=2,DIMInputSignalState_Max=5,DIMInputSignalState_Suspicious=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDriverSetting_t          /* @min: 0 @max:3 @values: enum { eDriverSetting_Invalid=3,eDriverSetting_Late=2,eDriverSetting_Early=0,eDriverSetting_Middle=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eTurnIndicator_t          /* turn indicator information @min: 0 @max:4 @values: enum { eTurnIndicator_Right=2,eTurnIndicator_Invalid=4,eTurnIndicator_Left=1,eTurnIndicator_Off=0,eTurnIndicator_Both=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 DIMOutMonState_t          /* Availability of driver monitoring dependent on input signal states @min: 0 @max:2 @values: enum { eDimMonState_Limited=1,eDimMonState_NotPossible=0,eDimMonState_Unlimited=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDriverActivityState_t    /* Measure of the current driver activity @min: 0 @max:3 @values: enum { eDriverActivity_MissingConf=1,eDriverActivity_EmergencySteer=3,eDriverActivity_Inactive=0,eDriverActivity_VeryActive=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDriverAttentionState_t   /* Current attentiveness of the driver @min: 0 @max:5 @values: enum { eDriverAttentionState_Unattended=5,eDriverAttentionState_VeryHigh=4,eDriverAttentionState_Low=1,eDriverAttentionState_Unknown=0,eDriverAttentionState_High=2,eDriverAttentionState_Higher=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDriverFeedbackState_t    /* Drivers response to a current function activation. @min: 0 @max:5 @values: enum { eDriverFeedbackState_StrongPositive=5,eDriverFeedbackState_NoPositive=2,eDriverFeedbackState_NoNegative=1,eDriverFeedbackState_WeakPositive=3,eDriverFeedbackState_Positive=4,eDriverFeedbackState_Negativ=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 CodingParam_t             /* ContiGuard Coding byte from EEPROM @min: 1 @max:2147483648 @values: enum { HEAD_CODING_PED_WARN=1024,HEAD_CODING_IGN_SCHK=8,HEAD_CODING_COUNTRY=4,HEAD_CODING_PED_BRAKE=2048,HEAD_CODING_DEBUGMESSAGES=32,HEAD_CODING_OBJMOVE_BRAKE=32768,HEAD_CODING_MAX=2147483648,HEAD_CODING_IGNORE_ACT_SWITCH=128,HEAD_CODING_OBJSTAT_WARN=4096,HEAD_CODING_LOW_SPEED=2,HEAD_CODING_PED_PRECRASH=65536,HEAD_CODING_VCL_PRECRASH=524288,HEAD_CODING_OBJMOVE_PRECRASH=131072,HEAD_CODING_STAT_OBJ=1,HEAD_CODING_NO_FAILUREHANDLING=16,HEAD_CODING_OBJMOVE_WARN=16384,HEAD_CODING_OBJSTAT_PRECRASH=262144,HEAD_CODING_DISTANCELIMIT=64,HEAD_CODING_OBJSTAT_BRAKE=8192,HEAD_CODING_VEHICLES_BRAKE=512,HEAD_CODING_VEHICLES_WARN=256,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 FCTSubChainQualifier_t    /* Status of Brake System @min: 0 @max:1 @values: enum { eSystemOff=1,eSystemOn=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eFunctionSwitch_t         /* @min: 1 @max:2147483648 @values: enum { eFunctionSwitch_PedBrakePreCond=2,eFunctionSwitch_PedWarn=1,eFunctionSwitch_VehBrakeL1=128,eFunctionSwitch_VehBrakeL2=256,eFunctionSwitch_VehBrakeL3=512,eFunctionSwitch_VehLatentWarn=1024,eFunctionSwitch_UnknownBrakePreCond=4096,eFunctionSwitch_MAX=2147483648,eFunctionSwitch_UnknownLatentWarn=65536,eFunctionSwitch_VehBrakePreCond=64,eFunctionSwitch_UnknownBrakeL1=8192,eFunctionSwitch_UnknownWarn=2048,eFunctionSwitch_UnknownBrakeL3=32768,eFunctionSwitch_UnknownBrakeL2=16384,eFunctionSwitch_PedBrakeL2=8,eFunctionSwitch_PedBrakeL3=16,eFunctionSwitch_VehWarn=32,eFunctionSwitch_PedBrakeL1=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eMainSwitch_t             /* @min: 0 @max:3 @values: enum { eMainSwitch_NotUsed=2,eMainSwitch_Inactive=1,eMainSwitch_Active=0,eMainSwitch_Invalid=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eObjectSwitch_t           /* @min: 1 @max:2147483648 @values: enum { eObjectSwitch_MAX=2147483648,eObjectSwitch_Vehicles=2,eObjectSwitch_Unknown=4,eObjectSwitch_Pedestrians=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eAcuteDynWarning_t        /* Seperate Vehicle Warning Channel @min: 0 @max:3 @values: enum { eAcuteDynamicWarning_Moving=1,eAcuteDynamicWarning_Standing=2,eAcuteDynamicWarning_No=0,eAcuteDynamicWarning_Halted=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDistWarningDisplay_t     /* Distance Warning
Display output @min: 0 @max:3 @values: enum { eDistWarningDisplay_Far=1,eDistWarningDisplay_Near=3,eDistWarningDisplay_No=0,eDistWarningDisplay_Mid=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eFunctionQualifier_t      /* @min: 0 @max:3 @values: enum { eUnavailableError=2,eAvailableOn=1,eAvailableOff=0,eUnavailableCoded=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ePedWarning_t             /* Sperate Pedestrian Warning Channel @min: 0 @max:3 @values: enum { ePedWarning_No=0,ePedWarning_Standing=2,ePedWarning_Halted=3,ePedWarning_Moving=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ePreCrashLevel_t          /* @min: 0 @max:3 @values: enum { eCollision_Unavoidable=3,eCollision_RunUp=1,eCollision_Prob=2,eCollision_No=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ePreDynWarning_t          /* Seperate Vehicle Warning Channel @min: 0 @max:3 @values: enum { ePreDynamicWarning_Halted=3,ePreDynamicWarning_Standing=2,ePreDynamicWarning_No=0,ePreDynamicWarning_Moving=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 FCTStateSig_t             /* Common functional status signal @min: 0 @max:2 @values: enum { eFCT_STATE_SIG_ACTIVE=1,eFCT_STATE_SIG_INVALID=2,eFCT_STATE_SIG_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 FCT_OP_MODE_t             /* @min: 0 @max:7 @values: enum { FCT_MOD_STARTUP=0,FCT_MOD_END_OF_LINE=5,FCT_MOD_MON_INPUT_ACC=6,FCT_MOD_RUNNING=2,FCT_MOD_REDUCED_FUNC=7,FCT_MOD_INIT=1,FCT_MOD_SERVICEALIGNMENT=4,FCT_MOD_SHUTDOWN=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint16 times_t                   /* Integer time type @min:0 @max:65.535 @resolution:0.001 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 FexOpMode_t               /* Required operation mode @min: 0 @max:8 @values: enum { FEX_OPMODE_RESET=1,FEX_OPMODE_MAX_RUNTIME=7,FEX_OPMODE_RUN_PED_DATA=6,FEX_OPMODE_DEMO=8,FEX_OPMODE_RUN_INIT_FPGA=2,FEX_OPMODE_RUN_CYCLIC_TEST_FPGA=4,FEX_OPMODE_RUN_STARTUP_TEST_FPGA=3,FEX_OPMODE_RUN_SAC_DATA=5,FEX_OPMODE_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 FlowElement_t             /* Bitfield encoding the two components (8.4bit signed) of a flow vector along with the corresponding collision count (4 bit unsigned) */	/* [Satisfies_rte sws 1188] */;
typedef uint8 FlowImageCorrespondenceType_t /* Indicates temporal vs. R->L correspondences @min: 0 @max:3 @values: enum { FI_CORRESPONDENCE_TYPE_TEMPORAL_INVERSE=3,FI_CORRESPONDENCE_TYPE_TEMPORAL=1,FI_CORRESPONDENCE_TYPE_SPATIAL=2,FI_CORRESPONDENCE_TYPE_DEFAULT=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDynamicState_t           /* Characterisation of segment as either moving or static (wrt to ego vehicle) @min: 0 @max:1 @values: enum { FSD_MOVING=1,FSD_STATIC=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eServiceQualifier_t       /* quantifies availability of function @min: 0 @max:3 @values: enum { FSD_SERVICE_NOT_AVAILABLE=3,FSD_SERVICE_AVAILABLE=1,FSD_SERVICE_REDUCED=2,FSD_SERVICE_INIT=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eStatus_t                 /* Measurement status @min: 0 @max:3 @values: enum { FSD_MEAS_NOT_AVAILABLE=3,FSD_HYPOTHESIS=2,FSD_MEAS=0,FSD_MEAS_UP_VISIBILITY=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eValidFlags_t             /* Bitfield. If a bit is set, the corresponding measurement in this segment is valid. Otherwise it is invalid. @min: 1 @max:22 @values: enum { FSD_VALIDFLAG_MINDIST=1,FSD_VALIDFLAG_DYNSTATE=22,FSD_VALIDFLAG_MINDIST_STD=4,FSD_VALIDFLAG_HEIGHTTOP=2,FSD_VALIDFLAG_EXPROB=8,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 FtrcFeatureState_t        /* State of the track @min: 0 @max:3 @values: enum { FTRC_FEAT_STATE_TRACKED=2,FTRC_FEAT_STATE_LOST=1,FTRC_FEAT_STATE_FOUND=3,FTRC_FEAT_STATE_UNDEFINED=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eClusterType_t            /* Specifies geometric or geometric+flow  cluster. @min: 0 @max:2 @values: enum { GEN_CLUSTER_TYPE_GEOMETRIC=1,GEN_CLUSTER_TYPE_FLOW=2,GEN_CLUSTER_TYPE_UNDEFINED=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 t_HMI_On_Off_Switch_t     /* Common hmi on off switch signal @min: 0 @max:2 @values: enum { HMI_ONOFF_SWITCH_INVLAID=2,HMI_ONOFF_SWITCH_OFF=1,HMI_ONOFF_SWITCH_ON=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 t_HMI_Warning_Levels_t    /* Common hmi warning level signal @min: 0 @max:3 @values: enum { HMI_WARN_LEVEL_INVALID=3,HMI_WARN_LEVEL_EARLY=0,HMI_WARN_LEVEL_LATE=2,HMI_WARN_LEVEL_MID=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_SensMode          /* Sensitivity modes, i.e. for US @min: 0 @max:255 @values: enum { RTE_HLA_SENSMODE_UNKNOWN=0,RTE_HLA_SENSMODE_US=2,RTE_HLA_SENSMODE_NORMAL=1,RTE_HLA_SENSMODE_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_State             /* HLA state (navl, idle, activ, fault) @min: 0 @max:255 @values: enum { RTE_HLA_STATE_ACTV=3,RTE_HLA_STATE_IDLE=2,RTE_HLA_STATE_NAVL=1,RTE_HLA_STATE_FAULT=4,RTE_HLA_STATE_UNKNOWN=0,RTE_HLA_STATE_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_TrafficStyle      /* Traffic style detection (left or right hand traffic) @min: 0 @max:255 @values: enum { RTE_HLA_TRAFFIC_STYLE_LHD=2,RTE_HLA_TRAFFIC_STYLE_UNKNOWN=0,RTE_HLA_TRAFFIC_STYLE_INVALID=255,RTE_HLA_TRAFFIC_STYLE_RHD=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_Type              /* HLA type e.g. Matrix, Standard, Plus, Light, not available @min: 0 @max:255 @values: enum { RTE_HLA_TYPE_NAVL=1,RTE_HLA_TYPE_INVALID=255,RTE_HLA_TYPE_UNKNOWN=0,RTE_HLA_TYPE_PLUS=4,RTE_HLA_TYPE_LIGHT=2,RTE_HLA_TYPE_MATRIX=5,RTE_HLA_TYPE_STANDARD=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eCDHypothesisType_t       /* Type of hypothesis @min: 0 @max:11 @values: enum { CDHypothesisType_No=0,CDHypothesisType_ACC=5,CDHypothesisType_Collision=8,CDHypothesisType_PedCollision=10,CDHypothesisType_CollisionUnavoidable=9,CDHypothesisType_RunUpStationary=3,CDHypothesisType_Pass=6,CDHypothesisType_RunUp=1,CDHypothesisType_PedPass=11,CDHypothesisType_CutIn=7,CDHypothesisType_RunUpBraking=2,CDHypothesisType_Static=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eEBAObjectClass_t         /* Function Object Class for EBA @min: 0 @max:3 @values: enum { EBAObjectClass_Obstacle=3,EBAObjectClass_Vehicle=2,EBAObjectClass_Unknown=0,EBAObjectClass_Pedestrian=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 e_DcgState_t              /* State of the dual conversion gain (DCG) @min: 0 @max:1 @values: enum { IC_DCG_HIGH=1,IC_DCG_LOW=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 e_FrameType_t             /* Frame-type this data belongs to @min: 0 @max:1 @values: enum { IC_FRAME_TYPE_EVEN=0,IC_FRAME_TYPE_ODD=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 e_ImagerCFA_t             /* Imager color filter array @min: 0 @max:9 @values: enum { IC_IMAGER_CFA_BGGR=3,IC_IMAGER_CFA_GRBG=4,IC_IMAGER_CFA_GBRC=7,IC_IMAGER_CFA_CRBG=8,IC_IMAGER_CFA_RCGB=6,IC_IMAGER_CFA_GBRG=5,IC_IMAGER_CFA_UNKNOWN=0,IC_IMAGER_CFA_BGCR=9,IC_IMAGER_CFA_RGGB=2,IC_IMAGER_CFA_CCCC=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 e_IntradayState_t         /* Flag for day or night mode @min: 0 @max:1 @values: enum { IC_INTRADAY_STATE_NIGHT=0,IC_INTRADAY_STATE_DAY=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 InterfaceVersion          /* Interface version numbers */	/* [Satisfies_rte sws 1188] */;
typedef uint32 aiMarkerColors_t          /* @min: 0 @max:2147483647 @values: enum { LD_MC_RED=2,LD_MC_BLUE=3,LD_MC_GREEN=4,LD_MC_UNKNOWN=5,LD_MC_WHITE=0,LD_MC_BUGFIX=2147483647,LD_MC_YELLOW=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 aiMarkerTypes_t           /* @min: 0 @max:2147483647 @values: enum { LD_MT_BUGFIX=2147483647,LD_MT_WALL=13,LD_MT_HIGHCURB=11,LD_MT_DOTTED=6,LD_MT_UNCLASSIFIED=5,LD_MT_LOWCURB=10,LD_MT_NARROWDASHED=9,LD_MT_DECORATION=7,LD_MT_SEPARATING=8,LD_MT_RESERVED2=3,LD_MT_RESERVED1=2,LD_MT_DASHED=1,LD_MT_CONTINUOUS=0,LD_MT_ROADSHOULDER=14,LD_MT_NOLINEDETECTED=4,LD_MT_CRASHBARRIER=12,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eCoordinateSystem_t       /* @min: 0 @max:2147483647 @values: enum { LD_CS_REAR_AXLE=1,LD_CS_FRONT_AXLE=0,LD_CS_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eEventType_t              /* @min: 0 @max:2147483647 @values: enum { LD_LE_FORK_ENTRY=2,LD_LE_FORK_UNKNOWN_OPEN=3,LD_LE_CONSTRUCTION_START=5,LD_LE_FORK_EXIT=1,LD_LE_IDLE=0,LD_LE_CONSTRUCTION_CLOSE=6,LD_LE_FORK_UNKNOWN_CLOSE=4,LD_LE_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eParallelModel_t          /* @min: 0 @max:2147483647 @values: enum { LD_PM_NOT_PARALLEL=0,LD_PM_PARALLEL=1,LD_PM_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 eSteeringSide_t           /* @min: 0 @max:2147483647 @values: enum { LD_SS_NONE=3,LD_SS_RIGHT=1,LD_SS_BOTH=0,LD_SS_LEFT=2,LD_SS_BUGFIX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 MTS_VirtAddrs             /* MTS virtual addresses */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ImageDataFormat_t         /* Image data format enumeration @min: 0 @max:10 @values: enum { ICF_NONE=0,ICF_SATURATION=9,ICF_V=8,ICF_BAYER_GBRG=5,ICF_BAYER_GRBG=3,ICF_YCRCB_420=6,ICF_BAYER_BGGR=4,ICF_BAYER_RGGB=2,ICF_U=7,ICF_GRAY=1,ICF_2DVECTORFIELD=10,} */	/* [Satisfies_rte sws 1188] */;
typedef uint16 t_PixelData               /* Data of one Pixel @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eMonoCalibrationCameraType_t /* determines whether this calibration represents the physical, 
Cropped-ROI or S-ROI-Rectified camera
    MC_CAMERA_TYPE_IMAGER emitted by: Lane (Calibration and Dynamic pose set)
    MC_CAMERA_TYPE_CROI emitted by: Lane (Calibration and Dynamic pose set)
    MC_CAMERA_TYPE_RROI emitted by: Lane (Calibration and Dynamic pose set)
    MC_CAMERA_TYPE_RECTIFIED emitted by: Sac (Calibration and Dynamic pose set) @min: 0 @max:4 @values: enum { MC_CAMERA_TYPE_CROI=2,MC_CAMERA_TYPE_DEFAULT=0,MC_CAMERA_TYPE_IMAGER=1,MC_CAMERA_TYPE_RROI=3,MC_CAMERA_TYPE_RECTIFIED=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eMonoCalibrationSide_t    /* determines whether this calibration represents the right or the left camera @min: 0 @max:2 @values: enum { MC_CAMERA_DEFAULT=0,MC_CAMERA_LEFT=2,MC_CAMERA_RIGHT=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eMonoCalibrationVerificationStatus_t /* Angle with maximum absolute deviation is used to set this flag.
(Intervals: 0.10°-0.25°, 0.25°-0.50°, 0.50°-1.00°, >1.00° and not verified) @min: 0 @max:5 @values: enum { MC_ABS_DEVIATION_LESSEQUAL_0_25_DEG=4,MC_ABS_DEVIATION_LESSEQUAL_1_00_DEG=2,MC_ABS_DEVIATION_LESSEQUAL_0_10_DEG=5,MC_ABS_DEVIATION_GREATER_1_00_DEG=1,MC_ABS_DEVIATION_LESSEQUAL_0_50_DEG=3,MC_NO_VERIFICATION_DONE_YET=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_DefectPixelType  /* defect type of the pixel @min: 0 @max:255 @values: enum { RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX=2,RTE_HLAR_DEFECT_PIXEL_UNKNOWN=0,RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX=3,RTE_HLAR_DEFECT_PIXEL_PIX_OK=1,RTE_HLAR_DEFECT_PIXEL_DRK_PIX=4,RTE_HLAR_DEFECT_PIXEL_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_TrafficStyleLearningState /* Learning state @min: 0 @max:255 @values: enum { RTE_HLAR_TRAFFIC_LEARN_UNKNOWN=0,RTE_HLAR_TRAFFIC_LEARN_INVALID=255,RTE_HLAR_TRAFFIC_LEARN_LHD_2=6,RTE_HLAR_TRAFFIC_LEARN_LHD_3=7,RTE_HLAR_TRAFFIC_LEARN_LHD_1=5,RTE_HLAR_TRAFFIC_LEARN_0=1,RTE_HLAR_TRAFFIC_LEARN_RHD_1=2,RTE_HLAR_TRAFFIC_LEARN_RHD_2=3,RTE_HLAR_TRAFFIC_LEARN_RHD_3=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RtePvProcessingMode_t     /* PV processing mode @min: 0 @max:3 @values: enum { RTE_PV_PROC_MODE_ALGO_NO_MEAS=1,RTE_PV_PROC_MODE_MEAS_INPUT_ONLY=2,RTE_PV_PROC_MODE_DEFAULT=0,RTE_PV_PROC_MODE_TEST_OUTPUT=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 PcOpMode_t                /* Required operation mode @min: 0 @max:4 @values: enum { PC_OPMODE_IDLE=0,PC_OPMODE_DEMO=4,PC_OPMODE_MAX_RUNTIME=3,PC_OPMODE_RESET=1,PC_OPMODE_RUN=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eDimensionality_t         /* mode switch: switching between 
i) only horizontal (PC_X_) 
ii)horizontal and vertical (PC_XY_) refinement @min: 0 @max:1 @values: enum { PC_XY_=1,PC_X_=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eMaskingOut_t             /* switch: switching between
i) use all pixels on the patch (PC_MASK_OFF_)
ii) call a heuristic scheme based on the disparity map to mask background (and foreground) @min: 0 @max:1 @values: enum { PC_MASK_CREATE_=1,PC_MASK_OFF_=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eReconstruct_Intensity_t  /* mode switch: switching between
i) no consideration of illumination variations (PC_BIAS_GAIN_OFF_)
ii) reconstruct bias and gain together with the spatial (and other) parameters (PC_BIAS_GAIN_)
iii) only reconstruct bias together with the spatial (and other) parameters (PC_BIAS_) @min: 0 @max:2 @values: enum { PC_BIAS_=2,PC_BIAS_GAIN_=1,PC_BIAS_GAIN_OFF_=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eReconstruct_Scale_t      /* mode switch: switching between
i) no consideration of scale variations (PC_SCALE_OFF_)
ii)use the input scale, but do not vary it (PC_SCALE_FIXED_)
iii)  reconstruct the scale together with the spatial (and other) parameters (PC_SCALE_RECONSTRUCT_) @min: 0 @max:2 @values: enum { PC_SCALE_OFF_=0,PC_SCALE_FIXED_=1,PC_SCALE_RECONSTRUCT_=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eValidity_t               /* qualifier describing validity of result @min: 0 @max:4 @values: enum { PC_VALID_MATCH=1,PC_NO_MATCH_FOUND=0,PC_EXCEEDED=2,PC_INVALID_INPUT=4,PC_MEAN_DISPARITY=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 PedObjectClass_t          /* object class @min: 1 @max:4 @values: enum { ePedObjectClassCount=4,ePedObjectClass_Pedestrian=1,ePedObjectClass_BicycleFront=3,ePedObjectClass_BicycleSide=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 PedOpMode_t               /* Operational Modes für PED @min: 0 @max:5 @values: enum { ePedOpMode_MaxRunTime=3,ePedOpMode_Demo2=5,ePedOpMode_Idle=0,ePedOpMode_Demo1=4,ePedOpMode_Run=2,ePedOpMode_Reset=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 PvOpMode_t                /* Required operation mode @min: 0 @max:4 @values: enum { PV_OPMODE_MAX_RUNTIME=3,PV_OPMODE_IDLE=0,PV_OPMODE_RUN=2,PV_OPMODE_RESET=1,PV_OPMODE_DEMO=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 PvErrorCode_t             /* The error code if in a error state @min: 0 @max:8 @values: enum { PV_ERROR_UNKNOWN=1,PV_ERROR_OUTPUT_PORT_NULL_PTR=8,PV_ERROR_INPUT_SERVICE_NULL_PTR=6,PV_ERROR_INPUT_PORT_NULL_PTR=4,PV_ERROR_OPMODE_NOT_SUPPORTED=2,PV_ERROR_INPUT_SERVICE_LIST_NULL_PTR=5,PV_ERROR_INPUT_PORT_LIST_NULL_PTR=3,PV_ERROR_NO_ERROR=0,PV_ERROR_OUTPUT_PORT_LIST_NULL_PTR=7,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_DimmingLevel     /* List which holds the dimming areas @min: 0 @max:255 @values: enum { RTE_HLAF_DIMM_LEVEL_REDUCT_2=3,RTE_HLAF_DIMM_LEVEL_INVALID=255,RTE_HLAF_DIMM_LEVEL_NO_REDUCT=1,RTE_HLAF_DIMM_LEVEL_UNKNOWN=0,RTE_HLAF_DIMM_LEVEL_REDUCT_1=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_DimmingStatus    /* Status of the dimming function @min: 0 @max:255 @values: enum { RTE_HLAF_DIMM_STATE_INVALID=255,RTE_HLAF_DIMM_STATE_NAVL=3,RTE_HLAF_DIMM_STATE_ERROR=4,RTE_HLAF_DIMM_STATE_UNKNOWN=0,RTE_HLAF_DIMM_STATE_LIMITED=2,RTE_HLAF_DIMM_STATE_AVL=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_EcoLight_eAvailabilityState /* Availability of data @min: 0 @max:255 @values: enum { RTE_HLAF_ECOLIGHT_AVST_ERROR=3,RTE_HLAF_ECOLIGHT_AVST_AVAILABLE=1,RTE_HLAF_ECOLIGHT_AVST_UNKNOWN=0,RTE_HLAF_ECOLIGHT_AVST_INVALID=255,RTE_HLAF_ECOLIGHT_AVST_LIMITED=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_EcoLight_eDetectionState /* Detection status of preceeding object @min: 0 @max:255 @values: enum { RTE_HLAF_ECOLIGHT_DETST_INVALID=255,RTE_HLAF_ECOLIGHT_DETST_NAVL=4,RTE_HLAF_ECOLIGHT_DETST_UNKNOWN=0,RTE_HLAF_ECOLIGHT_DETST_ESTIM=3,RTE_HLAF_ECOLIGHT_DETST_ERROR=5,RTE_HLAF_ECOLIGHT_DETST_NEW_DTCD=1,RTE_HLAF_ECOLIGHT_DETST_DTCD=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_EcoLight_eVehicleLight /* State of light on preceeding vehicle @min: 0 @max:255 @values: enum { RTE_HLAF_ECOLIGHT_VEHLIGHT_UNKNOWN=0,RTE_HLAF_ECOLIGHT_VEHLIGHT_ON=1,RTE_HLAF_ECOLIGHT_VEHLIGHT_OFF=2,RTE_HLAF_ECOLIGHT_VEHLIGHT_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_EcoLight_eVehicleType /* Type of preceeding vehicle @min: 0 @max:255 @values: enum { RTE_HLAF_ECOLIGHT_VEHTYPE_UNKNOWN=0,RTE_HLAF_ECOLIGHT_VEHTYPE_INVALID=255,RTE_HLAF_ECOLIGHT_VEHTYPE_SINGLETRACK=1,RTE_HLAF_ECOLIGHT_VEHTYPE_TWOTRACK=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_HighBeamState    /* high beam state recommendation @min: 0 @max:255 @values: enum { RTE_HLAF_HB_STATE_SPOT=4,RTE_HLAF_HB_STATE_OFF=1,RTE_HLAF_HB_STATE_PARTIAL=3,RTE_HLAF_HB_STATE_FULL_ON=2,RTE_HLAF_HB_STATE_INVALID=255,RTE_HLAF_HB_STATE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_LightOutput      /* light output in this dimming area @min: 0 @max:255 @values: enum { RTE_HLAF_LIGHTOUTPUT_UNKNOWN=0,RTE_HLAF_LIGHTOUTPUT_STD=1,RTE_HLAF_LIGHTOUTPUT_MIN=2,RTE_HLAF_LIGHTOUTPUT_MAX=3,RTE_HLAF_LIGHTOUTPUT_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 RTE_HLAF_MatrixTurnOffReason /* HLA turn off reason @min: 0 @max:4294967295 @values: enum { RTE_HLAF_TURNOFFREASON_LOW_SPEED=4,RTE_HLAF_TURNOFFREASON_CITY=16,RTE_HLAF_TURNOFFREASON_DELAY=128,RTE_HLAF_TURNOFFREASON_PREC=2,RTE_HLAF_TURNOFFREASON_FOG=32,RTE_HLAF_TURNOFFREASON_UNKNOWN=0,RTE_HLAF_TURNOFFREASON_ONC=1,RTE_HLAF_TURNOFFREASON_INVALID=4294967295,RTE_HLAF_TURNOFFREASON_BRIGHTNESS=8,RTE_HLAF_TURNOFFREASON_BLOCKAGE=64,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_MotorwayState    /* HLA motorway detection @min: 0 @max:255 @values: enum { RTE_HLAF_MTWY_COUNTRY=1,RTE_HLAF_MTWY_UNKNOWN=0,RTE_HLAF_MTWY_INVALID=255,RTE_HLAF_MTWY_MOTORWAY=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_ObjStatus        /* object status of the vehicle which defines the low beam distance (preceding, oncoming car) @min: 0 @max:255 @values: enum { RTE_HLAF_OBJSTA_UNKNOWN_OBJ=2,RTE_HLAF_OBJSTA_NO_OBJ=1,RTE_HLAF_OBJSTA_PREC_OBJ=3,RTE_HLAF_OBJSTA_UNKNOWN=0,RTE_HLAF_OBJSTA_INVALID=255,RTE_HLAF_OBJSTA_ONC_OBJ=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_SignalStatus     /* glare free area status (GFA valid, GFA invalid, signal invalid) @min: 0 @max:255 @values: enum { RTE_HLAF_SIGSTAT_UNKNOWN=0,RTE_HLAF_SIGSTAT_DATA_VALID=2,RTE_HLAF_SIGSTAT_INVALID=255,RTE_HLAF_SIGSTAT_INIT=1,RTE_HLAF_SIGSTAT_DATA_INVALID=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_SpeedState       /* Speed state (speed to low for full HB) @min: 0 @max:255 @values: enum { RTE_HLAF_SPEEDSTATE_UNKNOWN=0,RTE_HLAF_SPEEDSTATE_HIGH=2,RTE_HLAF_SPEEDSTATE_LOW=1,RTE_HLAF_SPEEDSTATE_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_TTBStatus        /* Status of ttb18Left (moving direction) @min: 0 @max:255 @values: enum { RTE_HLAF_TTBSTA_NO_OBJ=1,RTE_HLAF_TTBSTA_DIR_UNKNOWN=2,RTE_HLAF_TTBSTA_INVALID=255,RTE_HLAF_TTBSTA_UNKNOWN=0,RTE_HLAF_TTBSTA_DIR_RIGHT=4,RTE_HLAF_TTBSTA_DIR_LEFT=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_NightViewObjectType /* @min: 0 @max:255 @values: enum { RTE_HLAF_NV_OBJ_ANIMAL_SMALL=4,RTE_HLAF_NV_OBJ_UNKNOWN_OBJ=2,RTE_HLAF_NV_OBJ_PEDESTRIAN=3,RTE_HLAF_NV_OBJ_ANIMAL_BIG=5,RTE_HLAF_NV_OBJ_INVALID=255,RTE_HLAF_NV_OBJ_NO_OBJ=1,RTE_HLAF_NV_OBJ_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAF_NightViewSpot    /* @min: 0 @max:255 @values: enum { RTE_HLAF_NV_SPOT_CONT=3,RTE_HLAF_NV_SPOT_INVALID=255,RTE_HLAF_NV_SPOT_OFF=1,RTE_HLAF_NV_SPOT_UNKNOWN=0,RTE_HLAF_NV_SPOT_BLINK=2,RTE_HLAF_NV_SPOT_ABORT=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_BrightnessState  /* Ambient brightness detection @min: 0 @max:255 @values: enum { RTE_HLAR_BRT_UNKNOWN=0,RTE_HLAR_BRT_DAY=1,RTE_HLAR_BRT_NIGHT=5,RTE_HLAR_BRT_TWLGT_2=3,RTE_HLAR_BRT_TWLGT_3=4,RTE_HLAR_BRT_TWLGT_1=2,RTE_HLAR_BRT_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_CityState        /* City detection @min: 0 @max:255 @values: enum { RTE_HLAR_CITY_MAYBE=3,RTE_HLAR_CITY_NOT_DTCD=1,RTE_HLAR_CITY_UNKNOWN=0,RTE_HLAR_CITY_INVALID=255,RTE_HLAR_CITY_DTCD=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_HighwayEgoMotionState /* Highway detection based on ego motion (EM) @min: 0 @max:255 @values: enum { RTE_HLAR_HIGHWAY_EM_NOT_DTCD=1,RTE_HLAR_HIGHWAY_EM_DTCD=2,RTE_HLAR_HIGHWAY_EM_UNKNOWN=0,RTE_HLAR_HIGHWAY_EM_LOW_SPEED=3,RTE_HLAR_HIGHWAY_EM_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_HighwayLatPosState /* Highway detection based on lateral position (LP) of  passed oncoming vehicles @min: 0 @max:255 @values: enum { RTE_HLAR_HIGHWAY_LP_DTCD=2,RTE_HLAR_HIGHWAY_LP_INVALID=255,RTE_HLAR_HIGHWAY_LP_NOT_DTCD=1,RTE_HLAR_HIGHWAY_LP_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_RedReflectorArea /* @min: 0 @max:255 @values: enum { RTE_HLAR_RED_REFLECTOR_AREA_DTCD=2,RTE_HLAR_RED_REFLECTOR_AREA_INVALID=255,RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD=1,RTE_HLAR_RED_REFLECTOR_AREA_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_TrafficStyleState /* Traffic style state (init, SCN , learned in this cycle, learned in last cycle) @min: 0 @max:255 @values: enum { RTE_HLAR_TRAFFIC_STATE_LEARN=2,RTE_HLAR_TRAFFIC_STATE_LAST_LEARNED=3,RTE_HLAR_TRAFFIC_STATE_SCN=1,RTE_HLAR_TRAFFIC_STATE_INVALID=255,RTE_HLAR_TRAFFIC_STATE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_Tunnel           /* @min: 0 @max:255 @values: enum { RTE_HLAR_TUNNEL_NOT_DTCD=1,RTE_HLAR_TUNNEL_INSIDE=3,RTE_HLAR_TUNNEL_UPFRONT=2,RTE_HLAR_TUNNEL_UNKNOWN=0,RTE_HLAR_TUNNEL_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_WeatherState     /* @min: 0 @max:255 @values: enum { RTE_HLAR_WEATHER_HEAVY_FOG=5,RTE_HLAR_WEATHER_INVALID=255,RTE_HLAR_WEATHER_GOOD=1,RTE_HLAR_WEATHER_BAD=2,RTE_HLAR_WEATHER_UNKNOWN=0,RTE_HLAR_WEATHER_MEDIUM_FOG=4,RTE_HLAR_WEATHER_LIGHT_FOG=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_eHighwayOcclusionState /* Highway detection based on the detection of a Premature Death of the track
  which could be due to an occlusion (OC) @min: 0 @max:255 @values: enum { RTE_HLAR_HIGHWAY_OC_UNKNOWN=0,RTE_HLAR_HIGHWAY_OC_INVALID=255,RTE_HLAR_HIGHWAY_OC_NOT_DTCD=1,RTE_HLAR_HIGHWAY_OC_DTCD=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_eHighwaySpeedDetectionState /* Highway detection based on high ego motion (EM) @min: 0 @max:255 @values: enum { RTE_HLAR_HIGHWAY_SP_DTCD=2,RTE_HLAR_HIGHWAY_SP_INVALID=255,RTE_HLAR_HIGHWAY_SP_NOT_DTCD=1,RTE_HLAR_HIGHWAY_SP_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLAR_ObjectIconStatus /* various status bits @min: 1 @max:128 @values: enum { RTE_HLAR_OBJ_ICON_STA_STREETLAMP_DET_CALLED=2,RTE_HLAR_OBJ_ICON_STA_BIT6=64,RTE_HLAR_OBJ_ICON_STA_BIT7=128,RTE_HLAR_OBJ_ICON_STA_BIT4=16,RTE_HLAR_OBJ_ICON_STA_BIT5=32,RTE_HLAR_OBJ_ICON_STA_SKIPPED_BAD_POS=8,RTE_HLAR_OBJ_ICON_STA_REDLIGHT_DET_CALLED=4,RTE_HLAR_OBJ_ICON_STA_LED_DET_CALLED=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 RTE_HLAR_ObjectStatus     /* object Status @min: 1 @max:2147483648 @values: enum { RTE_HLAR_OBJ_STA_TRACKER_CLASS_STATIC=134217728,RTE_HLAR_OBJ_STA_IS_TOO_BRIGHT=64,RTE_HLAR_OBJ_STA_BIT22=4194304,RTE_HLAR_OBJ_STA_BIT23=8388608,RTE_HLAR_OBJ_STA_IS_CHAIN_OF_LIGHT=1048576,RTE_HLAR_OBJ_STA_BIT29=536870912,RTE_HLAR_OBJ_STA_IS_ABOVE_ROI=131072,RTE_HLAR_OBJ_STA_IS_VEH_ONC=16,RTE_HLAR_OBJ_STA_IS_RED=128,RTE_HLAR_OBJ_STA_IS_MOVING_NON_WHITE=2048,RTE_HLAR_OBJ_STA_IS_ONC_PAIR=4096,RTE_HLAR_OBJ_STA_IS_TRACKED_IN_PAIR=16777216,RTE_HLAR_OBJ_STA_TRACKER_CLASS_DYNAMIC=268435456,RTE_HLAR_OBJ_STA_IS_BRIGHT_OBJECT=2097152,RTE_HLAR_OBJ_STA_IS_ONE2ONE_ASS=67108864,RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_ONC_1ST=1,RTE_HLAR_OBJ_STA_WILL_BE_REMOVED=33554432,RTE_HLAR_OBJ_STA_IS_VEH_PREC=32,RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_ONC_2ND=4,RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_PREC_1ST=2,RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_PREC_2ND=8,RTE_HLAR_OBJ_STA_IS_POT_VEH_HIGH_PROB=8192,RTE_HLAR_OBJ_STA_BIT31=2147483648,RTE_HLAR_OBJ_STA_BIT30=1073741824,RTE_HLAR_OBJ_STA_IS_3D_CORRECT=524288,RTE_HLAR_OBJ_STA_BIT15=32768,RTE_HLAR_OBJ_STA_BIT14=16384,RTE_HLAR_OBJ_STA_IS_STREET_LAMP=65536,RTE_HLAR_OBJ_STA_IS_MOVING_WHITE=1024,RTE_HLAR_OBJ_STA_IS_RED2=512,RTE_HLAR_OBJ_STA_IS_PULSED_LIGHT=256,RTE_HLAR_OBJ_STA_IS_INFINITE=262144,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_CutOffLineState   /* mandatory input signal for HLA std, plus and matrix,
light distance status (inactice, active, invalid) @min: 0 @max:255 @values: enum { RTE_HLA_CUTOFFLINE_INVALID=255,RTE_HLA_CUTOFFLINE_UNKNOWN=0,RTE_HLA_CUTOFFLINE_ACTIVE=2,RTE_HLA_CUTOFFLINE_INACTIVE=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_GlareReductionState /* not mandatory input signal, default = RTE_HLA_GR_INVALID 
glare reduction state @min: 0 @max:255 @values: enum { RTE_HLA_GR_UNKNOWN=0,RTE_HLA_GR_ACTIVE=2,RTE_HLA_GR_INACTIVE=1,RTE_HLA_GR_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_LightModuleState  /* mandatory input signal, Light Module state (navl, idle, fault, deact) @min: 0 @max:255 @values: enum { RTE_HLA_LTM_FAULT=3,RTE_HLA_LTM_INVALID=255,RTE_HLA_LTM_NAVL=1,RTE_HLA_LTM_DEACT=4,RTE_HLA_LTM_IDLE=2,RTE_HLA_LTM_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_LightStyle        /* mandatory input signal,  
left light style
(HB off = country (asymmetric), motorway (asymmetric) or  symmetric (tourism mode) light, partial HB, spot light, full HB) @min: 0 @max:255 @values: enum { RTE_HLA_LIGHTSTYLE_FULL_HB=5,RTE_HLA_LIGHTSTYLE_INVALID=255,RTE_HLA_LIGHTSTYLE_UNKNOWN=0,RTE_HLA_LIGHTSTYLE_COUNTRY=2,RTE_HLA_LIGHTSTYLE_PART_HB=4,RTE_HLA_LIGHTSTYLE_SYMM=1,RTE_HLA_LIGHTSTYLE_SPOT=6,RTE_HLA_LIGHTSTYLE_MOTORWAY=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_Seg_LightStatus   /* Light status @min: 1 @max:128 @values: enum { RTE_HLA_SEG_LIGHT_STA_SATURATED=8,RTE_HLA_SEG_LIGHT_STA_HOT_PIXEL=16,RTE_HLA_SEG_LIGHT_STA_POT_RED=1,RTE_HLA_SEG_LIGHT_STA_SATURATED_T1=4,RTE_HLA_SEG_LIGHT_STA_POT_FAR_PAIR_LIGHT=32,RTE_HLA_SEG_LIGHT_STA_DO_NOT_START_NEW_TRACK=128,RTE_HLA_SEG_LIGHT_STA_POT_LED=2,RTE_HLA_SEG_LIGHT_STA_ISOLATED=64,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RTE_HLA_US_Sens           /* US sensitivity mode signal from user
(default value = RTE_HLA_US_SENS_UNKNOWN) @min: 0 @max:255 @values: enum { RTE_HLA_US_SENS_ON=2,RTE_HLA_US_SENS_UNKNOWN=0,RTE_HLA_US_SENS_OFF=1,RTE_HLA_US_SENS_INVALID=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 MapProvider_t             /* Map Provider @min: 0 @max:7 @values: enum { INPUT_GPS_MAP_PROVIDER_RESERVED=5,INPUT_GPS_MAP_PROVIDER_NOT_AVAILABLE=6,INPUT_GPS_MAP_PROVIDER_NAVINFO=4,INPUT_GPS_MAP_PROVIDER_ZENRIN=2,INPUT_GPS_MAP_PROVIDER_ADF=3,INPUT_GPS_MAP_PROVIDER_NAVTEQ=0,INPUT_GPS_MAP_PROVIDER_INVALID=7,INPUT_GPS_MAP_PROVIDER_TELEATLAS=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RtePvTrackingState_t      /* Preview tracking state @min: 0 @max:2 @values: enum { RTE_PV_TRACKING_STATE_INIT=0,RTE_PV_TRACKING_STATE_ERROR=2,RTE_PV_TRACKING_STATE_RUN=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RtePvSignalState_t        /* signal state @min: 0 @max:2 @values: enum { RTE_PV_SIG_INIT=1,RTE_PV_SIG_NOT_OK=0,RTE_PV_SIG_OK=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 RtePvSignalType_t         /* sensor-signal type @min: 0 @max:9 @values: enum { RTE_PV_SIGTYPE_VEH_CURVATURE=7,RTE_PV_SIGTYPE_VEH_ATTA_ANGLE=8,RTE_PV_SIGTYPE_INVALID=0,RTE_PV_SIGTYPE_ODO_POS_Y_DELTA_ERR=5,RTE_PV_SIGTYPE_VEH_SPEED=9,RTE_PV_SIGTYPE_ODO_YAW_ANGLE=3,RTE_PV_SIGTYPE_ODO_POS_X_DELTA_ERR=4,RTE_PV_SIGTYPE_ODO_POS_Y=2,RTE_PV_SIGTYPE_ODO_POS_X=1,RTE_PV_SIGTYPE_ANGYAW_DELTA_ERR=6,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_ApplicationControlFlow_t /* application control flow @min: 0 @max:2147483647 @values: enum { SR_RTE_APPL_CONTROL_FLOW_DEBUG=3,SR_RTE_APPL_CONTROL_FLOW_NORMAL=0,SR_RTE_APPL_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT=2,SR_RTE_APPL_CONTROL_FLOW_SKIP_KERNEL=1,SR_RTE_APPL_CONTROL_FLOW_INT_MAX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_CalibrationStatus_t /* status of the SR calibration @min: 0 @max:2147483647 @values: enum { SR_RTE_CALIBRATION_STATUS_OK=1,SR_RTE_CALIBRATION_STATUS_NOT_OK=2,SR_RTE_CALIBRATION_STATUS_INT_MAX=2147483647,SR_RTE_CALIBRATION_STATUS_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_OutSupplSignPosition_t /* relative supplementary sign position @min: 0 @max:2147483647 @values: enum { SR_RTE_RESULT_TRACK_SUPPL_ABOVE=1,SR_RTE_RESULT_TRACK_SUPPL_INT_MAX=2147483647,SR_RTE_RESULT_TRACK_SUPPL_BELOW=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 classId_t                 /* id of the sign type @min: 0 @max:2147483647 @values: enum { SR_RTE_SIGN_CLASS_MAIN_SL_085_ACTIVE=274586,SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_JAM=124000,SR_RTE_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED=104911,SR_RTE_SIGN_CLASS_MAIN_SL_060_ACTIVE=274561,SR_RTE_SIGN_CLASS_DANGER_GRAVEL=116000,SR_RTE_SIGN_CLASS_MAIN_SL_070=274570,SR_RTE_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT=105010,SR_RTE_SIGN_CLASS_MAIN_SL_005=274505,SR_RTE_SIGN_CLASS_MAIN_SL_080=274580,SR_RTE_SIGN_CLASS_MAIN_PROHIB_ALL=250000,SR_RTE_SIGN_CLASS_MAIN_GENERAL_END=282000,SR_RTE_SIGN_CLASS_MAIN_SL_085=274585,SR_RTE_SIGN_CLASS_MAIN_SL_140_ACTIVE=274641,SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_GREEN=270110,SR_RTE_SIGN_CLASS_MAIN_ROUNDABOUT=215000,SR_RTE_SIGN_CLASS_MAIN_STOP=206000,SR_RTE_SIGN_CLASS_DANGER_HILL_UPWARDS=110000,SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_BEGIN=310000,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_SIDE_LEFT=211100,SR_RTE_SIGN_CLASS_DANGER_ANIMAL_CROSSING=142000,SR_RTE_SIGN_CLASS_MAIN_SL_100=274600,SR_RTE_SIGN_CLASS_MAIN_SL_105=274605,SR_RTE_SIGN_CLASS_MAIN_SL_005_ACTIVE=274506,SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_ACTIVE=276001,SR_RTE_SIGN_CLASS_MAIN_SL_065=274565,SR_RTE_SIGN_CLASS_MAIN_SL_060=274560,SR_RTE_SIGN_CLASS_MAIN_PROHIB_CAR=251000,SR_RTE_SIGN_CLASS_SUPPL_TRUCK_BUS=104812,SR_RTE_SIGN_CLASS_MAIN_SL_080_ACTIVE=274581,SR_RTE_SIGN_CLASS_MAIN_MOTORWAY_BEGIN=331000,SR_RTE_SIGN_CLASS_SUPPL_TIME_RESTRICTION=104030,SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_END=311000,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT=209300,SR_RTE_SIGN_CLASS_DANGER_PEDESTRIAN_ZEBRA_CROSSING=134000,SR_RTE_SIGN_CLASS_SUPPL_ONLY_INFORMATION_PICT=100600,SR_RTE_SIGN_CLASS_MAIN_GARBAGE_END=278990,SR_RTE_SIGN_CLASS_SUPPL_VALID_FOR_DISTANCE=100100,SR_RTE_SIGN_CLASS_SUPPL_ARROW_LEFT=100010,SR_RTE_SIGN_CLASS_CLUSTER_GARBAGE=999990,SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD=102000,SR_RTE_SIGN_CLASS_SUPPL_ONLY_INFORMATION_TEXT_ONE_ROW=100601,SR_RTE_SIGN_CLASS_DANGER_GARBAGE=109990,SR_RTE_SIGN_CLASS_MAIN_SL_075=274575,SR_RTE_SIGN_CLASS_MAIN_SL_110=274610,SR_RTE_SIGN_CLASS_MAIN_SL_030_ACTIVE=274531,SR_RTE_SIGN_CLASS_MAIN_SL_115=274615,SR_RTE_SIGN_CLASS_MAIN_SL_040_ACTIVE=274541,SR_RTE_SIGN_CLASS_DANGER_SLIPPERY_ROAD=114000,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_RIGHT=214200,SR_RTE_SIGN_CLASS_MAIN_BUNDLE_TWO_DIGIT_END=278200,SR_RTE_SIGN_CLASS_SUPPL_ARROW_RIGHT=100020,SR_RTE_SIGN_CLASS_DANGER_BUMPS=112000,SR_RTE_SIGN_CLASS_SUPPL_WEIGHT=105235,SR_RTE_SIGN_CLASS_MAIN_SL_070_ACTIVE=274571,SR_RTE_SIGN_CLASS_UNKNOWN=0,SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_LIGHTS=131000,SR_RTE_SIGN_CLASS_SUPPL_X_WAY=105240,SR_RTE_SIGN_CLASS_MAIN_SL_105_ACTIVE=274606,SR_RTE_SIGN_CLASS_DANGER_HILL_DOWNWARDS=108000,SR_RTE_SIGN_CLASS_MAIN_GARBAGE_ACTIVE=274991,SR_RTE_SIGN_CLASS_DANGER_WIND=117000,SR_RTE_SIGN_CLASS_DANGER_ROAD_WORK=123000,SR_RTE_SIGN_CLASS_DANGER_TRAIN_CROSS=151000,SR_RTE_SIGN_CLASS_MAIN_SL_045=274545,SR_RTE_SIGN_CLASS_MAIN_SL_040=274540,SR_RTE_SIGN_CLASS_DANGER_CYCLIST_CROSSING=138000,SR_RTE_SIGN_CLASS_DANGER_BUS=145000,SR_RTE_SIGN_CLASS_MAIN_GARBAGE_END_ACTIVE=278991,SR_RTE_SIGN_CLASS_DANGER_FALLING_ROCKS=115000,SR_RTE_SIGN_CLASS_SUPPL_ICY=105238,SR_RTE_SIGN_CLASS_DANGER_GIVE_WAY=205000,SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END=280100,SR_RTE_SIGN_CLASS_MAIN_SL_110_ACTIVE=274611,SR_RTE_SIGN_CLASS_MAIN_GENERAL_END_ACTIVE=282001,SR_RTE_SIGN_CLASS_MAIN_HIGHWAY_END=334000,SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_BEGIN=325000,SR_RTE_SIGN_CLASS_SUPPL_NIGHT=104040,SR_RTE_SIGN_CLASS_MAIN_GARBAGE=274990,SR_RTE_SIGN_CLASS_MAIN_GARBAGE_PROHIB=250990,SR_RTE_SIGN_CLASS_MAIN_SL_030=274530,SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END=270200,SR_RTE_SIGN_CLASS_MAIN_SL_035=274535,SR_RTE_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC=125000,SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SIDE=121010,SR_RTE_SIGN_CLASS_DANGER_PEDESTRIAN=133000,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_TURN_LEFT=209100,SR_RTE_SIGN_CLASS_MAIN_SL_125=274625,SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_END=326000,SR_RTE_SIGN_CLASS_MAIN_HIGHWAY_BEGIN=330000,SR_RTE_SIGN_CLASS_MAIN_PROHIB_MOTORBIKE_CAR=260000,SR_RTE_SIGN_CLASS_MAIN_SL_120=274620,SR_RTE_SIGN_CLASS_SUPPL_ZONE=100604,SR_RTE_SIGN_CLASS_SUPPL_PASSENGER_CAR=104810,SR_RTE_SIGN_CLASS_MAIN_SL_130_ACTIVE=274631,SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING=276000,SR_RTE_SIGN_CLASS_MAIN_BUNDLE_THREE_DIGIT_END=278300,SR_RTE_SIGN_CLASS_DANGER_BEND_LEFT=103010,SR_RTE_SIGN_CLASS_MAIN_SL_075_ACTIVE=274576,SR_RTE_SIGN_CLASS_MAIN_BUNDLE_THREE_DIGIT_END_ACTIVE=278301,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_PASS_LEFT=222100,SR_RTE_SIGN_CLASS_DANGER_SNOW=113000,SR_RTE_SIGN_CLASS_DANGER_DANGER_CHILDREN=136000,SR_RTE_SIGN_CLASS_MAIN_SL_045_ACTIVE=274546,SR_RTE_SIGN_CLASS_MAIN_SL_025=274525,SR_RTE_SIGN_CLASS_MAIN_SL_055_ACTIVE=274556,SR_RTE_SIGN_CLASS_MAIN_SL_090_ACTIVE=274591,SR_RTE_SIGN_CLASS_MAIN_SL_140=274640,SR_RTE_SIGN_CLASS_MAIN_SL_065_ACTIVE=274566,SR_RTE_SIGN_CLASS_MAIN_SL_130=274630,SR_RTE_SIGN_CLASS_DANGER_EXCLAMATION_MARK=101000,SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROAD=301000,SR_RTE_SIGN_CLASS_SUPPL_CURVED_ARROW_RIGHT=100021,SR_RTE_SIGN_CLASS_MAIN_BUNDLE_TWO_DIGIT_END_ACTIVE=278201,SR_RTE_SIGN_CLASS_SUPPL_SCHOOL=105239,SR_RTE_SIGN_CLASS_DANGER_CATTLE_CROSSING=140000,SR_RTE_SIGN_CLASS_MAIN_SL_035_ACTIVE=274536,SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SIDE=121020,SR_RTE_SIGN_CLASS_DANGER_BEND_RIGHT=103020,SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_ACTIVE=277001,SR_RTE_SIGN_CLASS_MAIN_SL_015_ACTIVE=274516,SR_RTE_SIGN_CLASS_SUPPL_WORKDAYS_AND_TIME=104231,SR_RTE_SIGN_CLASS_SUPPL_VALID_IN_DISTANCE=100400,SR_RTE_SIGN_CLASS_MAIN_NO_ENTRY=267000,SR_RTE_SIGN_CLASS_MAIN_SL_120_ACTIVE=274621,SR_RTE_SIGN_CLASS_MAIN_SL_050=274550,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_PASS_RIGHT=222200,SR_RTE_SIGN_CLASS_MAIN_SL_050_ACTIVE=274551,SR_RTE_SIGN_CLASS_SUPPL_CURVED_ARROW_LEFT=100011,SR_RTE_SIGN_CLASS_SUPPL_WET=105236,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_LEFT=214100,SR_RTE_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT=105020,SR_RTE_OUTPUT_FUNCTIONAL_SIGN_CLASS_INT_MAX=2147483647,SR_RTE_SIGN_CLASS_SUPPL_WORKDAYS=104230,SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING=277000,SR_RTE_SIGN_CLASS_MAIN_SL_020_ACTIVE=274521,SR_RTE_SIGN_CLASS_MAIN_SL_055=274555,SR_RTE_SIGN_CLASS_SUPPL_TRUCK_BUS_CAR_TRAILER=104913,SR_RTE_SIGN_CLASS_DANGER_AIR_TRAFFIC=144000,SR_RTE_SIGN_CLASS_MAIN_SL_025_ACTIVE=274526,SR_RTE_SIGN_CLASS_SUPPL_PASSENGER_CAR_TRAILER=104811,SR_RTE_SIGN_CLASS_MAIN_MOTORWAY_END=336000,SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SIDES=120000,SR_RTE_SIGN_CLASS_MAIN_GARBAGE_DIR_ARROW=209990,SR_RTE_SIGN_CLASS_SUPPL_FOGGY=105237,SR_RTE_SIGN_CLASS_MAIN_SL_125_ACTIVE=274626,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_SIDE_RIGHT=211200,SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE=280101,SR_RTE_SIGN_CLASS_MAIN_SL_095_ACTIVE=274596,SR_RTE_SIGN_CLASS_MAIN_SL_100_ACTIVE=274601,SR_RTE_SIGN_CLASS_MAIN_SL_010_ACTIVE=274511,SR_RTE_SIGN_CLASS_SUPPL_MON2FRI_AND_TIME=104233,SR_RTE_SIGN_CLASS_SUPPL_GARBAGE=100990,SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE=270100,SR_RTE_SIGN_CLASS_MAIN_SL_115_ACTIVE=274616,SR_RTE_SIGN_CLASS_MAIN_SL_015=274515,SR_RTE_SIGN_CLASS_MAIN_SL_020=274520,SR_RTE_SIGN_CLASS_MAIN_SL_010=274510,SR_RTE_SIGN_CLASS_MAIN_SL_095=274595,SR_RTE_SIGN_CLASS_SUPPL_RESTRICTED=100000,SR_RTE_SIGN_CLASS_MAIN_SL_090=274590,SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_TURN_RIGHT=209200,SR_RTE_SIGN_CLASS_SUPPL_MOTORCYCLE=104610,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_Brightness_t       /* brightness as classified by input data from image control @min: 0 @max:2147483647 @values: enum { SR_RTE_BRIGHTNESS_BRIGHT=2,SR_RTE_BRIGHTNESS_INT_MAX=2147483647,SR_RTE_BRIGHTNESS_UNKNOWN=0,SR_RTE_BRIGHTNESS_DARK=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_OutSignGeometry_t  /* general sign shape (circular, rectangular, ...) @min: 0 @max:2147483647 @values: enum { SR_RTE_RESULT_TRACK_SIGN_TRIANGULAR=2,SR_RTE_RESULT_TRACK_SIGN_DIAMOND=3,SR_RTE_RESULT_TRACK_SIGN_CIRCULAR=0,SR_RTE_RESULT_TRACK_SIGN_RECTANGULAR=1,SR_RTE_RESULT_TRACK_SIGN_INT_MAX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_OutputResultTrackStatus_t /* track status @min: 0 @max:2147483647 @values: enum { SR_RTE_RESULT_TRACK_STATUS_ENDED=1,SR_RTE_RESULT_TRACK_STATUS_PASSED=2,SR_RTE_RESULT_TRACK_STATUS_ACTIVE=0,SR_RTE_RESULT_TRACK_STATUS_FINISHED=3,SR_RTE_OUTPUT_RESULT_TRACK_STATUS_INT_MAX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 SR_RTE_OutputTrackCharacteristic_t /* characteristics of track @min: 0 @max:2147483647 @values: enum { SR_RTE_OUTPUT_TRACK_CHAR_INT_MAX=2147483647,SR_RTE_RESULT_TRACK_CHARAC_RESERVED=64,SR_RTE_RESULT_TRACK_CHARAC_ON_INFO_SIGN=4,SR_RTE_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL=16384,SR_RTE_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED=512,SR_RTE_RESULT_TRACK_CHARAC_DISABELED=4096,SR_RTE_RESULT_TRACK_CHARAC_ON_VEHICLE=2,SR_RTE_RESULT_TRACK_CHARAC_NEVER_PASSED=8,SR_RTE_RESULT_TRACK_CHARAC_IS_EMBEDDED=256,SR_RTE_RESULT_TRACK_CHARAC_CLASS_SHAKY=16,SR_RTE_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT=8192,SR_RTE_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN=1,SR_RTE_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND=1024,SR_RTE_RESULT_TRACK_CHARAC_NONE=0,SR_RTE_RESULT_TRACK_CHARAC_MODIFIED_CLASS=32768,SR_RTE_RESULT_TRACK_CHARAC_IS_PART_OF_GATE=128,SR_RTE_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED=2048,SR_RTE_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED=32,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 speedUnit_t               /* the estimated speed unit @min: 0 @max:2147483647 @values: enum { SR_RTE_RESULT_COUNTRY_UNIT_UNKNOWN=0,SR_RTE_RESULT_COUNTRY_UNIT_MPH_OR_KMH=3,SR_RTE_OUTPUT_COUNTRY_SPEED_LIMIT_UNIT_INT_MAX=2147483647,SR_RTE_RESULT_COUNTRY_UNIT_KMH=1,SR_RTE_RESULT_COUNTRY_UNIT_MPH=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 srStatus_t                /* current status of sign recognition process, see defines above @min: 0 @max:2147483647 @values: enum { SR_RTE_PROCESS_STATUS_RUNNING_OVERLOADED=6,SR_RTE_PROCESS_STATUS_ERROR=1,SR_RTE_PROCESS_STATUS_NO_COMPETENCE=3,SR_RTE_PROCESS_STATUS_NOT_RUNNING=0,SR_RTE_PROCESS_STATUS_MUST_RESET=8,SR_RTE_PROCESS_STATUS_BLOCKAGE=4,SR_RTE_PROCESS_STATUS_TEMP_ERROR=7,SR_RTE_PROCESS_STATUS_INIT=2,SR_RTE_OUTPUT_PROCESS_STATUS_INT_MAX=2147483647,SR_RTE_PROCESS_STATUS_RUNNING=5,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 trafficStyle_t            /* the estimated traffic style @min: 0 @max:2147483647 @values: enum { SR_RTE_RESULT_COUNTRY_TRAFFIC_STYLE_UNKNOWN=0,SR_RTE_RESULT_COUNTRY_LEFT_HAND_TRAFFIC=1,SR_RTE_RESULT_COUNTRY_RIGHT_HAND_TRAFFIC=2,SR_RTE_OUTPUT_COUNTRY_TRAFFIC_STYLE_INT_MAX=2147483647,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteOpMode_t            /* Required operation mode @min: 0 @max:14 @values: enum { SAC_RTE_OPMODE_RUN=2,SAC_RTE_OPMODE_SYNC=5,SAC_RTE_OPMODE_AUTO_CHOICE=10,SAC_RTE_OPMODE_IDLE=0,SAC_RTE_OPMODE_RESET=1,SAC_RTE_OPMODE_DISTANCE_TEST=14,SAC_RTE_OPMODE_EOL_UPDATE=11,SAC_RTE_OPMODE_DEMO=4,SAC_RTE_OPMODE_SELF_EVAL=12,SAC_RTE_OPMODE_MAX_RUNTIME=3,SAC_RTE_OPMODE_INIT_LUT=7,SAC_RTE_OPMODE_MEAS_ONLY=6,SAC_RTE_OPMODE_TEST=13,SAC_RTE_OPMODE_AUTOCAL_FINE=9,SAC_RTE_OPMODE_AUTOCAL_COARSE=8,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SacRteDistTestSigState_t  /* 0u,    !< default mode, values not initalized
1u,    !< outputs are valid and were determined in the distance test, w/o calibration
2u     !< outputs are valid and have been used for calibration @min: 0 @max:2 @values: enum { SAC_RTE_DSTMO_ValidCalibration=2,SAC_RTE_DSTMO_ValidDstTest=1,SAC_RTE_DSTMO_Default=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 AlgoApplicationNumber_t   /* Algo application number (differentiation between customers, vehicle platforms and projects) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 AlgoComponentVersionNumber_t /* Algo component version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 AlgoErrorState_t          /* Algo error state enumeration @min: 0 @max:2 @values: enum { AL_ERR_STATE_UNKNOWN=0,AL_ERR_STATE_ACTIVE=1,AL_ERR_STATE_INACTIVE=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 GenAlgoQualifiers_t       /* Generic algo qualifiers should be used on the algo component output, @min: 0 @max:4294967295 @values: enum { ALGO_QUAL_GENERAL_FUNCTION_ERROR=32,ALGO_QUAL_CALIBRATION_ERROR_TO_HIGHT=16,ALGO_QUAL_OK=0,ALGO_QUAL_CALIBRATION_RUNNING=256,ALGO_QUAL_LIMITED_VISIBILITY=128,ALGO_QUAL_BLOCKAGE=4,ALGO_QUAL_NO_VISIBILITY=64,ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR=2,ALGO_QUAL_CRITICAL_INPUT_ERROR=1,ALGO_QUAL_PARTIAL_BLOCKAGE=8,ALGO_QUAL_MAX=4294967295,} */	/* [Satisfies_rte sws 1188] */;
typedef sint8 ObjNumber_t               /* Object Number (Object ID) @min:-1 @max:128 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 ParameterID_t             /* Parameter Id used to sync/match interfaces @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SigState_t                /* Signal status @min: 0 @max:1 @values: enum { SIGNAL_INVALID=0,SIGNAL_VALID=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TraceID_t                 /* Trace index type @min:0 @max:10 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fAccelAbs_t               /* Magnitude of translatory acceleration, time-derivative of translatory velocity without sign, increase of velocity: positive, decrease of velocity: negative @min:-18 @max:18 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fAccel_t                  /* Translatory acceleration, time-derivative of translatory velocity with sign @min:-18 @max:18 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fAngleDeg_t               /* Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise @min:-360 @max:360 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fAngle_t                  /* Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise */	/* [Satisfies_rte sws 1188] */;
typedef float32 fConfidence_t             /* Trustiness of value, 0.0: no reliance, 1.0: full realiance @min:0 @max:1 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fCurve_t                  /* Curvature (inverse radius) of trajectory, left direction: positive, right direction negative @min:-1 @max:1 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fDistance_t               /* Straight stretch between points or objects @min:-500 @max:500 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fGradient_t               /* Gradient of a value @min:-3.4e+038 @max:3.4e+038 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fProbability_t            /* Propbability of a hypothesis, 0: no probability, 1: full probability @min:0 @max:1 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fQuality_t                /* Characteristic of a variable, 0: worst quality, 1.0 best quality @min:0 @max:1 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fRadius_t                 /* Radius of trajectory, left direction: positive, right direction negative @min:-100000 @max:100000 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fRatio_t                  /* Ratio of a value @min:0 @max:10000 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fStiffness_t              /* Stiffness of a value @min:0 @max:10000 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fTemperature_t            /* Thermal state @min:-300 @max:300 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fTime_t                   /* Period of time @min:0 @max:3.4e+038 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fUncertainty_t            /* Uncertainty of value, 0.0: no reliance, 1.0: full realiance @min:0 @max:1 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fVariance_t               /* The variance of a value @min:-100000 @max:100000 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fVelocityAbs_t            /* Magnitude of translatory velocity, time-derivative of distance without sign @min:0 @max:100 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fVelocity_t               /* Translatory velocity, time-derivative of distance with sign, forward direction positive, reverse direction negative @min:-100 @max:100 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fWeight_t                 /* Gravity load in unit of mass @min:0 @max:50000 */	/* [Satisfies_rte sws 1188] */;
typedef float32 fYawRate_t                /* Measure of yaw rate, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise */	/* [Satisfies_rte sws 1188] */;
typedef uint8 percentage_t              /* percentage @min:0 @max:100 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 quality_t                 /* quality 0 % ... 100 % @min:0 @max:100 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ucConfidence_t            /* Trustiness of value, 0: no reliance, 100: full realiance @min:0 @max:100 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 uiTime_t                  /* Period of time in ms @min:0 @max:62000 */	/* [Satisfies_rte sws 1188] */;
typedef sint32 SymbolicConstants         /* Symbolic constants */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCustomOutputEstTrafficStyle_t /* estimated Traffic Style @min: 0 @max:2 @values: enum { TSA_RTE_CUSTOM_EST_TRAFFIC_SYLE_SNA=0,TSA_RTE_CUSTOM_EST_TRAFFIC_STYLE_RH=2,TSA_RTE_CUSTOM_EST_TRAFFIC_STYLE_LH=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 blockageStatus_t          /* blockage status @min: 0 @max:4 @values: enum { TSA_RTE_BLOCKAGE_PART_BLOCKAGE=3,TSA_RTE_BLOCKAGE_NO_BLOCKAGE=1,TSA_RTE_BLOCKAGE_CONDENSATION=2,TSA_RTE_BLOCKAGE_UNKNOWN_STATUS=0,TSA_RTE_BLOCKAGE_BLOCKAGE=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 calibrationStatus_t       /* status of calibration @min: 0 @max:3 @values: enum { TSA_RTE_CUSTOM_CALIB_STATUS_OK=1,TSA_RTE_CUSTOM_CALIB_STATUS_NOK=2,TSA_RTE_CUSTOM_CALIB_STATUS_SNA=3,TSA_RTE_CUSTOM_CALIB_STATUS_UNK=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 timeOfDay_t               /* time of day @min: 0 @max:2 @values: enum { TSA_RTE_TIME_OF_DAY_UNKNOWN=0,TSA_RTE_TIME_OF_DAY_DAY=1,TSA_RTE_TIME_OF_DAY_NIGHT=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCustomSignFunctionalSignClassId_t /* sign class IDs (with meaning) only the classes actually output by SR are listed @min: 0 @max:254 @values: enum { TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TEXT=128,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GIVE_WAY_ROUNDABOUT=114,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT_FIR=93,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_100=24,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_105=25,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_FOR=42,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_END=82,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_IN=41,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TIME=38,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SPLIPPERY_ROAD=113,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GRAVEL=120,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SCHOOL=39,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_135=31,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_130=30,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_85=21,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_VEHICLES_PROHIBITED=80,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_80=20,TSA_RTE_CUSTOM_SIGN_CLASS_UNKNOWN=254,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_CAR=132,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_STRAIGHT=77,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_PASSING=1,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_END=86,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_10=6,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT=44,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ANIMAL_CROSSING=110,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_END=123,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_15=7,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRUCK=47,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT_BEND=45,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_DOWNWARDS=107,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CONCAVE=104,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_PEDESTRIAN_CROSSING=116,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_LEFT_45_DE=100,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_PICTURE=129,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_120=28,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_LIGHT=109,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_125=29,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_90=22,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ROUNDABOUT_SIGN=78,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_95=23,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_JAM=105,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_2_DIGITS=55,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT_FI=94,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_LEFT=91,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SID=96,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_65=17,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_UPWARDS=108,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_60=16,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_5=5,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_RIGHT=76,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_NIGHT=51,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERIC_SUPPLEMENTAL=127,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT=3,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITHOUT_=118,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW_RAIN=37,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_RIGHT_45_D=101,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD=98,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_NO_PASSING_SIGN=2,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SNOW=112,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_LEFT=75,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_START=85,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_75=19,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_70=18,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_HAZARDOUS=49,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_START=81,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_ENTRY=79,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_145=33,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SID=95,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CHILDREN=111,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_140=32,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GIVE_WAY=88,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED=48,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE=54,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE_ALLOWED=131,TSA_RTE_CUSTOM_SIGN_CLASS_NO_SIGN=0,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_RIGHT=92,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_START=83,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_END=84,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_40=12,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END=126,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_45=13,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_STOP_SIGN=87,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BYCICLE_CROSSING=117,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RESTRICTED=133,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW=36,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERAL_WITHDRAWAL=4,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_FOG=35,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_END=90,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC=121,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_3_DIGITS=56,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RAIN=34,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_IN=130,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_55=15,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_50=14,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_BUMP=103,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START=122,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ONE_BUMP=102,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_WIND_FROM_SIDE=115,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_WEIGHT=40,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROA=99,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_WORKS=106,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SI=97,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_20=8,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_25=9,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ZONE=52,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_START=89,TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITH_BAR=119,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_4WAY=53,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_110=26,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_115=27,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT_BEND=46,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT=43,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START_END=124,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_30=10,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_35=11,TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRAILER=50,TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_START=125,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCustomSignResultGeometry_t /* sign geometry @min: 0 @max:3 @values: enum { TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_RECTANGULAR=1,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_DIAMOND=3,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_TRIANGULAR=2,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_CIRCULAR=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 TsaRteCustomSignResultTrackCharacteristics_t /* @min: 0 @max:8388608 @values: enum { TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_OTHER_LANE=131072,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_CLASS_SHAKY=16,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DURING_TURN=4194304,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT=8192,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NONE=0,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_EMBEDDED=256,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_PART_OF_GATE=128,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_VEHICLE=2,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL=16384,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED=32,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN=1,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_INFO_SIGN=4,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED=2048,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DISABELED=4096,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_RESERVED=64,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HIGHWAY_EXIT=65536,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_PARALLEL_ROAD=262144,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND=1024,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_MODIFIED_CLASS=32768,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTIVE=8388608,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_DIVERTING_ROAD=524288,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FAR_IRRELEVANT=1048576,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED=512,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NEVER_PASSED=8,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_EGO_RELEVANCE_UNCLEAR=2097152,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCustomSignResultTrackState_t /* sign result track states @min: 0 @max:3 @values: enum { TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_FINISHED=3,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ENDED=1,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_PASSED=2,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCustomSignResultUnit_t /* sign unit @min: 0 @max:2 @values: enum { TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_UNKNOWN=0,TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_MPH=2,TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCustomSignSupplResultPosition_t /* relative supplementary sign position @min: 0 @max:1 @values: enum { TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_BELOW=0,TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_ABOVE=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteNpaIndicators_t     /* indicators for no passing status @min: 1 @max:128 @values: enum { TSA_RTE_NPA_INDICATOR_SIGN_TRAILER=32,TSA_RTE_NPA_INDICATOR_NO_DISPLAY=128,TSA_RTE_NPA_INDICATOR_LANE=4,TSA_RTE_NPA_INDICATOR_SIGN_RESTR=16,TSA_RTE_NPA_INDICATOR_SIGN=1,TSA_RTE_NPA_INDICATOR_GENERAL_CANCEL=64,TSA_RTE_NPA_INDICATOR_SIGN_CANCEL=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteNpaStatus_t         /* current no-passing information @min: 0 @max:3 @values: enum { TSA_RTE_NPA_PASSING_STATE_IDLE=0,TSA_RTE_NPA_PASSING_STATE_ALLOWED=1,TSA_RTE_NPA_PASSING_STATE_CANCEL=2,TSA_RTE_NPA_PASSING_STATE_FORBIDDEN=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteNpaSupplSignValState_t /* current suppl sign validity @min: 0 @max:3 @values: enum { TSA_RTE_NPA_SUPPLVALSTAT_VALID=2,TSA_RTE_NPA_SUPPLVALSTAT_INVALID=1,TSA_RTE_NPA_SUPPLVALSTAT_EXTRAPOL=3,TSA_RTE_NPA_SUPPLVALSTAT_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteNpaValidity_t       /* current sign validity @min: 0 @max:6 @values: enum { TSA_RTE_NPA_VALID_RESTRICTED=2,TSA_RTE_NPA_VALID_FOR_CAR=5,TSA_RTE_NPA_VALID_UNRESTRICTED=1,TSA_RTE_NPA_VALID_FOR_CAR_TRAILER=4,TSA_RTE_NPA_IDLE_VALIDITY=0,TSA_RTE_NPA_VALID_FOR_TRUCK=3,TSA_RTE_NPA_VALID_ARROW=6,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCurrentMotorway_t   /* @min: 0 @max:3 @values: enum { TSA_RTE_MOTORWAY_SNA=3,TSA_RTE_MOTORWAY_TRUE=1,TSA_RTE_MOTORWAY_UNKNOWN=0,TSA_RTE_MOTORWAY_FALSE=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteCurrentUrbanArea_t  /* @min: 0 @max:3 @values: enum { TSA_RTE_URBAN_AREA_FALSE=2,TSA_RTE_URBAN_AREA_SNA=3,TSA_RTE_URBAN_AREA_UNKNOWN=0,TSA_RTE_URBAN_AREA_TRUE=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteEstSpdUnt_t         /* the estimated speed unit @min: 0 @max:3 @values: enum { TSA_RTE_EST_SPD_UNT_MPH=2,TSA_RTE_EST_SPD_UNT_SNA=0,TSA_RTE_EST_SPD_UNT_BOTH=3,TSA_RTE_EST_SPD_UNT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteEstTrafficStyle_t   /* the estimated traffic style @min: 0 @max:2 @values: enum { TSA_RTE_EST_TRAFFIC_SYLE_SNA=0,TSA_RTE_EST_TRAFFIC_STYLE_RH=2,TSA_RTE_EST_TRAFFIC_STYLE_LH=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteUrbanAreaChange_t   /* @min: 0 @max:3 @values: enum { TSA_RTE_URBAN_AREA_CHANGE_UNKNOWN=0,TSA_RTE_URBAN_AREA_CHANGE_OUTSIDE_TO_INSIDE=2,TSA_RTE_URBAN_AREA_CHANGE_INSIDE_TO_OUTSIDE=3,TSA_RTE_URBAN_AREA_CHANGE_NO_CHANGE_AHEAD=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteRwfIndicators_t     /* indicators for recognized road works @min: 1 @max:128 @values: enum { TSA_RTE_RWF_INDICATOR_SPD_LMT_CAM_VS_MAP=1,TSA_RTE_RWF_INDICATOR_SIGN_BACK_COLOR=8,TSA_RTE_RWF_INDICATOR_RW_SIGN=128,TSA_RTE_RWF_INDICATOR_SIGN_REPET_RATE=4,TSA_RTE_RWF_INDICATOR_LANE_MARK_COLOR=16,TSA_RTE_RWF_INDICATOR_SIGN_INVALIDATED=32,TSA_RTE_RWF_INDICATOR_SPD_LMT_FUNNEL=2,TSA_RTE_RWF_INDICATOR_LANE_WIDTH=64,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteRwfStatus_t         /* current road works information @min: 0 @max:2 @values: enum { TSA_RTE_RWF_STATUS_NO=1,TSA_RTE_RWF_STATUS_YES=2,TSA_RTE_RWF_STATUS_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteSlaSpdLmtEnd_t      /* end of limit signs have been recognized @min: 0 @max:16 @values: enum { TSA_RTE_SLA_3_DIGIT_END=2,TSA_RTE_SLA_GENERAL_END=4,TSA_RTE_SLA_SPD_LMT_END_NOT_MATCHING=16,TSA_RTE_SLA_NO_SPD_LMT_END=0,TSA_RTE_SLA_2_DIGIT_END=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteSlaSpdLmtType_t     /* speed limit type @min: 0 @max:7 @values: enum { TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_UNLIM=6,TSA_RTE_SLA_SPDLIMTYPE_NDEF1=1,TSA_RTE_SLA_SPDLIMTYPE_IDLE=0,TSA_RTE_SLA_SPDLIMTYPE_IMPLICIT_URBAN=2,TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_REGULAR=4,TSA_RTE_SLA_SPDLIMTYPE_IMPLICIT_OVERLAND=3,TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_ALTER=5,TSA_RTE_SLA_SPDLIMTYPE_SNA=7,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteSlaSpdLmtVal_t      /* speed limit validity information @min: 0 @max:10 @values: enum { TSA_RTE_SLA_SPDLIMVALSTAT_TRAILER=9,TSA_RTE_SLA_SPDLIMVALSTAT_EXT_RGT=8,TSA_RTE_SLA_SPDLIMVALSTAT_WET=4,TSA_RTE_SLA_SPDLIMVALSTAT_UNLIM=1,TSA_RTE_SLA_SPDLIMVALSTAT_FOG=3,TSA_RTE_SLA_SPDLIMVALSTAT_ICY=2,TSA_RTE_SLA_SPDLIMVALSTAT_EXT_LFT=7,TSA_RTE_SLA_SPDLIMVALSTAT_IDLE=0,TSA_RTE_SLA_SPDLIMVALSTAT_DARK=6,TSA_RTE_SLA_SPDLIMVALSTAT_TIME=5,TSA_RTE_SLA_SPDLIMVALSTAT_RESTRICTED=10,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteSlaSpdUnit_t        /* speed unit @min: 0 @max:3 @values: enum { TSA_RTE_SLA_UNIT_MPH=1,TSA_RTE_SLA_UNIT_KMH=0,TSA_RTE_SLA_UNIT_NDEF2=2,TSA_RTE_SLA_UNIT_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TsaRteSlaSupSgnVal_t      /* validity of supplementary signs @min: 0 @max:3 @values: enum { TSA_RTE_SLA_SUPPLVALSTAT_EXTRAPOL=3,TSA_RTE_SLA_SUPPLVALSTAT_UNKNOWN=0,TSA_RTE_SLA_SUPPLVALSTAT_VALID=2,TSA_RTE_SLA_SUPPLVALSTAT_INVALID=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TSARteWwaStatus_t         /* current wrong way status @min: 0 @max:2 @values: enum { TSA_RTE_WWA_NOT_DRIVING_WRONG_WAY=1,TSA_RTE_WWA_DRIVING_WRONG_WAY=2,TSA_RTE_WWA_WRONG_WAY_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 LongDirState_t            /* Direction of movement @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VDYCaliState_t            /* Calibration inhibition states @min: 0 @max:128 @values: enum { VDY_CAL_INIT=0,VDY_CAL_SWA_GRAD=64,VDY_CAL_YWR_OFFS_STST=1,VDY_CAL_YWR_OFFS_DYN=2,VDY_CAL_SWA_OFFS=16,VDY_CAL_WHS_OFFS=4,VDY_CAL_WHS_LOAD=128,VDY_CAL_LTA_OFFS=32,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VDYCtrlState_t            /* Operating modes of vdy component @min: 0 @max:2 @values: enum { VDY_CTRL_STATE_INIT=1,VDY_CTRL_STATE_STARTUP=0,VDY_CTRL_STATE_RUNNING=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 VDYIoState_t              /* vdy io states type */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehDynStatePos_t          /* Position in VehDyn State array @min: 0 @max:12 @values: enum { VDY_SOUT_POS_VEL=3,VDY_SOUT_POS_LATACC=8,VDY_SOUT_POS_DRCRV=2,VDY_SOUT_POS_YWR=1,VDY_SOUT_POS_CURVE=0,VDY_SOUT_POS_VCORR=6,VDY_SOUT_POS_SSA=7,VDY_SOUT_POS_ACCEL=4,VDY_SOUT_POS_MSTAT=5,VDY_SOUT_POS_MAX=12,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehParAddStatePos_t       /* Position in VehPar.VehParAdd State array @min: 0 @max:12 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=2,VEH_PAR_ADD_PASSABLE_HEIGHT=7,VEH_PAR_ADD_OVERHANG_FRONT=3,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_MAX=12,VEH_PAR_ADD_DIST_CAMERA_HOOD_Y=9,VEH_PAR_ADD_FRONT_AXLE_ROAD=4,VEH_PAR_ADD_WHEEL_WIDTH=5,VEH_PAR_ADD_DIST_CAMERA_HOOD_X=8,VEH_PAR_ADD_VEHICLE_LENGTH=1,VEH_PAR_ADD_STEERING_VARIANT=6,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehParMainStatePos_t      /* Position in VehPar.VehParMain State array @min: 0 @max:16 @values: enum { VDY_PAR_POS_AXLD=7,VDY_PAR_POS_MAX=16,VDY_PAR_POS_WHLDRE=9,VDY_PAR_POS_DRVAXL=11,VDY_PAR_POS_TWDFR=3,VDY_PAR_POS_WTCKSREV=12,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=5,VDY_PAR_POS_CSFR=13,VDY_PAR_POS_COGH=6,VDY_PAR_POS_WHLDFR=8,VDY_PAR_POS_SWARAT=1,VDY_PAR_POS_WHLCIR=10,VDY_PAR_POS_WBASE=2,VDY_PAR_POS_CSRE=14,VDY_PAR_POS_TWDRE=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehParSenMountStatePos_t  /* Position in VehPar.SensorMounting State array @min: 0 @max:8 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=4,VEH_PAR_SEN_MOUNT_LONG_POS=1,VEH_PAR_SEN_MOUNT_MAX=8,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=3,VEH_PAR_SEN_MOUNT_YAW_ANGLE=6,VEH_PAR_SEN_MOUNT_ORIENTATION=5,VEH_PAR_SEN_MOUNT_VERT_POS=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehParSensorStatePos_t    /* Position in VehPar.Sensor State array @min: 0 @max:8 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=2,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=1,VEH_PAR_SENSOR_CYCLE_TIME=3,VEH_PAR_SENSOR_MAX=8,VEH_PAR_SENSOR_NO_OF_SCANS=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehSigAddStatePos_t       /* Position in VehSig.VehSigAdd State array @min: 0 @max:20 @values: enum { VEH_SIG_ADD_KICK_DOWN=13,VEH_SIG_ADD_SPEEDO_SPEED=17,VEH_SIG_ADD_WIPER_STATE=1,VEH_SIG_ADD_WIPER_WASHER_FRONT=4,VEH_SIG_ADD_TRAILER_CON=18,VEH_SIG_ADD_BRAKE_PEDAL_PRESSED=14,VEH_SIG_ADD_DRIVER_TIRED=15,VEH_SIG_ADD_SPEED_UNIT=16,VEH_SIG_ADD_ROAD_WHL_ANG_RE=10,VEH_SIG_ADD_ODOMETER=11,VEH_SIG_ADD_FOG_LAMP_REAR=8,VEH_SIG_ADD_RAIN_SENSOR=5,VEH_SIG_ADD_WIPER_OUT_PARK_POS=3,VEH_SIG_ADD_TURN_SIGNAL=6,VEH_SIG_ADD_GAS_PEDAL_POS=12,VEH_SIG_ADD_ROAD_WHL_ANG_FR=9,VEH_SIG_ADD_IGN_SWITCH=19,VEH_SIG_ADD_ENV_TEMP=0,VEH_SIG_ADD_MAX=20,VEH_SIG_ADD_FOG_LAMP_FRONT=7,VEH_SIG_ADD_WIPER_STAGE=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehSigBrakeStatePos_t     /* Position in VehSig.Brake State array @min: 0 @max:2 @values: enum { VEH_SIG_BRAKE_TSC=1,VEH_SIG_BRAKE_ABS=0,VEH_SIG_BRAKE_MAX=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehSigMainStatePos_t      /* Position in VehSig.VehSigMain State array @min: 0 @max:32 @values: enum { VDY_SIN_POS_YWR_TEMP=1,VDY_SIN_POS_YWRINT_TEMP=9,VDY_SIN_POS_WTCKS_RL=20,VDY_SIN_POS_WVEL_FL=4,VDY_SIN_POS_VMOT=26,VDY_SIN_POS_WVEL_FR=5,VDY_SIN_POS_MAX=32,VDY_SIN_POS_SSA=29,VDY_SIN_POS_WTCKS_RR=21,VDY_SIN_POS_BRAKE=23,VDY_SIN_POS_VDIR=25,VDY_SIN_POS_DUMMY=27,VDY_SIN_POS_LATA=3,VDY_SIN_POS_PBRK=24,VDY_SIN_POS_YWRINT=8,VDY_SIN_POS_LONGA=10,VDY_SIN_POS_WDIR_RR=17,VDY_SIN_POS_YWR=0,VDY_SIN_POS_VEHACL_EXT=13,VDY_SIN_POS_WDIR_RL=16,VDY_SIN_POS_GEAR=22,VDY_SIN_POS_WDIR_FL=14,VDY_SIN_POS_SWA=2,VDY_SIN_POS_RSTA=11,VDY_SIN_POS_VEHVEL_EXT=12,VDY_SIN_POS_CRV=28,VDY_SIN_POS_WTCKS_FR=19,VDY_SIN_POS_WVEL_RR=7,VDY_SIN_POS_WVEL_RL=6,VDY_SIN_POS_WTCKS_FL=18,VDY_SIN_POS_WDIR_FR=15,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehSigPowertrainStatePos_t /* Position in VehSig.Powertrain State array @min: 0 @max:3 @values: enum { VEH_SIG_POWERTRAIN_TARGETGEAR=1,VEH_SIG_POWERTRAIN_MAX=3,VEH_SIG_POWERTRAIN_ACTUALGEAR=0,VEH_SIG_POWERTRAIN_ENGINE_RUNNING=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VDYErrState_t             /* the vdy error state type @min: 0 @max:2 @values: enum { VDY_ERR_STATE_INACTIVE=2,VDY_ERR_STATE_ACTIVE=1,VDY_ERR_STATE_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint32 VdyNvmState_t             /* Read status respective write request @min: 0 @max:125000 @values: enum { VDY_NVM_POS_SWA=0,VDY_NVM_POS_SSG=2,VDY_NVM_POS_YWR=4,VDY_NVM_POS_LATACC=6,VDY_NVM_POS_WLD=10,VDY_NVM_POS_DUMMY=125000,VDY_NVM_POS_VELCORR=8,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 MotState_t                /* Moving (forward or reverse)
Moving forward
Moving reverse
Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 corrQual_t                /* Velocity correction quality flag @min: 0 @max:3 @values: enum { VDY_VELO_CORR_QUAL_RANGE_NVERIFIED=1,VDY_VELO_CORR_QUAL_RANGE_VERIFIED=2,VDY_VELO_CORR_QUAL_EEPROM=0,VDY_VELO_CORR_QUAL_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TrailerConnection_t       /* No trailer detected, Trailer detected, not defined,
Trailer signal is not available @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:255 @values: enum { DYN_GEAR_PARK_GEAR=11,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_POWER_FREE=12,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_POWER_INVALID=255,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:4 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_BOTH=4,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 VodcaOpMode_t             /* Operational Modes für VODCA @min: 0 @max:6 @values: enum { VODCA_OPMODE_RUN_CLASSIFY=4,VODCA_OPMODE_RUN_PREPROC=3,VODCA_OPMODE_RESET=1,VODCA_OPMODE_MAX_RUNTIME=5,VODCA_OPMODE_DEMO=6,VODCA_OPMODE_RUN=2,VODCA_OPMODE_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eChannelType_t            /* for each channel a channel type can be defined @min: 0 @max:7 @values: enum { eChannelType_Spare1=4,eChannelType_Spare3=6,eChannelType_Spare2=5,eChannelType_Spare4=7,eChannelType_UmV=3,eChannelType_U=1,eChannelType_Gray=0,eChannelType_V=2,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 eHOGFeatureType_t         /* possible special type of HOG features @min: 0 @max:1 @values: enum { eHOGFeatureType_Default=0,eHOGFeatureType_iHOG=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 Percentage_s_t            /* @min: 0 @max:100 @values: enum { Percentage_min=0,Percentage_max=100,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 True_False_s_t            /* @min: 0 @max:1 @values: enum { RTE_False=0,RTE_True=1,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 GB_t_eBlockageStatus      /* MPC function blockage status @min: 0 @max:6 @values: enum { GB_CONDENSATION=3,GB_BLOCKAGE=6,GB_UNKNOWN_STATUS=0,GB_TOP_PART_BLOCKAGE=4,GB_NO_BLOCKAGE=1,GB_BOTTOM_PART_BLOCKAGE=5,} */	/* [Satisfies_rte sws 1188] */;
typedef uint8 GB_t_eFctId               /* MPC function identifier @min: 0 @max:6 @values: enum { GB_LDW_FCT_ID=3,GB_SOD_FCT_ID=6,GB_SOD_L_FCT_ID=5,GB_SOD_R_FCT_ID=4,GB_TSA_FCT_ID=2,GB_HLA_FCT_ID=1,GB_UNKNOWN_FCT_ID=0,} */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q3_t                   /* signed 16-bit fixed-point type; number of fractional bits = 3 */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q4_t                   /* signed 16-bit fixed-point type; number of fractional bits = 4 */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q5_t                   /* signed 16-bit fixed-point type; number of fractional bits = 5 */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q6_t                   /* signed 16-bit fixed-point type; number of fractional bits = 6 */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q7_t                   /* signed 16-bit fixed-point type; number of fractional bits = 7 */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q8_t                   /* signed 16-bit fixed-point type; number of fractional bits = 8 */	/* [Satisfies_rte sws 1188] */;
typedef sint16 s16q9_t                   /* signed 16-bit fixed-point type; number of fractional bits = 9 */	/* [Satisfies_rte sws 1188] */;
typedef sint32 s32q18_t                  /* signed 32-bit fixed-point type; number of fractional bits = 18 */	/* [Satisfies_rte sws 1188] */;
typedef sint32 s32q24_t                  /* signed 32-bit fixed-point type; number of fractional bits = 24 */	/* [Satisfies_rte sws 1188] */;
typedef sint32 s32q3_t                   /* signed 32-bit fixed-point type; number of fractional bits = 3 */	/* [Satisfies_rte sws 1188] */;
typedef sint32 s32q4_t                   /* signed 32-bit fixed-point type; number of fractional bits = 4 */	/* [Satisfies_rte sws 1188] */;
typedef sint32 s32q7_t                   /* signed 32-bit fixed-point type; number of fractional bits = 7 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q3_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 3 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q4_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 4 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q5_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 5 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q6_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 6 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q7_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 7 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q8_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 8 */	/* [Satisfies_rte sws 1188] */;
typedef uint16 u16q9_t                   /* unsigned 16-bit fixed-point type; number of fractional bits = 9 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 u32q18_t                  /* unsigned 32-bit fixed-point type; number of fractional bits = 18 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 u32q24_t                  /* unsigned 32-bit fixed-point type; number of fractional bits = 24 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 u32q3_t                   /* unsigned 32-bit fixed-point type; number of fractional bits = 3 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 u32q4_t                   /* unsigned 32-bit fixed-point type; number of fractional bits = 4 */	/* [Satisfies_rte sws 1188] */;
typedef uint32 u32q7_t                   /* unsigned 32-bit fixed-point type; number of fractional bits = 7 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q1_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 1 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q2_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 2 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q3_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 3 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q4_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 4 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q5_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 5 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q6_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 6 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q7_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 7 */	/* [Satisfies_rte sws 1188] */;
typedef uint8 u8q8_t                    /* unsigned 8-bit fixed-point type; number of fractional bits = 8 */	/* [Satisfies_rte sws 1188] */;

typedef uint8                     	AlgoVersionInfo_array_t[51];/* Algo version Info string */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	AlgoComponentVersionNumber_t uiAlgoVersionNumber;
 	AlgoApplicationNumber_t ApplicationNumber;
 	AlgoVersionInfo_array_t AlgoVersionInfo;
 	CompState_t eCompState;
 	CompErrorCode_t eErrorCode;
 	eShedulerModeRequest_t eShedulerModeRequest;
 	GenAlgoQualifiers_t eGenAlgoQualifier;
 } AlgoCompState_t;			/* State of the algo components */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eAssociatedLane_t eAssociatedLane;
 	eAssociatedLane_t eFuncAssociatedLane;
 	uint8 uiCutInProbability;
 	uint8 uiCutOutProbability;
 } LaneInformation_t;			/* Object lane information */

typedef ObjNumber_t               	aiOOIList_array_t[6];/* Object of interest list @min:0 @max:40 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fDistToRef;
 	float32 CDObjectQuality;
 } LegacyAOL_t;			/* Legacy data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 cExternalID;
 	eObjOOI_t eObjOOI;
 } ObjOfInterest_t;			/* Object of intereset information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	LaneInformation_t LaneInformation;
 	ObjOfInterest_t ObjOfInterest;
 	LegacyAOL_t Legacy;
 } FCTPubObject_t;			/* Object list properties */

typedef FCTPubObject_t            	ObjList_array_t[40];/* Object list properties */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ObjNumber_t iNumOfUsedObjects;
 	uint8 iPadding;
 	aiOOIList_array_t aiOOIList;
 	eRelObjLossReason_t eRelObjLossReason;
 } HeaderAssessedObjList_t;			/* Object list properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoDataTimeStamp_t uiTimeStamp;
 	AlgoCycleCounter_t uiMeasurementCounter;
 	AlgoCycleCounter_t uiCycleCounter;
 	AlgoSignalState_t eSigStatus;
 } SignalHeader_t;			/* Common header for all structured data types */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	uiTime_t CycleTime;
 	VDYCaliState_t CaliMode;
 	VDYCtrlState_t CtrlMode;
 } BSW_s_VDYCtrlData_t;			/* @vaddr:0x20300000 @vaddr_defs: VDY_MEAS_ID_CTRLDATA @cycleid:vdy_cycle_id @vname:VDYCtrlData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	BaseOpMode_t eOpMode;
 	BaseSchedulingMode_t eSchedulingMode;
 } BaseCtrlData_t;			/* State of the algo components */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 uiBoundingBoxStartX;
 	uint16 uiBoundingBoxStartY;
 	uint16 uiBoundingBoxWidth;
 	uint16 uiBoundingBoxHeight;
 } SacRteBoundingBox_t;			/* image bounding box (=valid image area) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fU0;
 	float32 fV0;
 	float32 fU1;
 	float32 fV1;
 } SacRteEpipolarCorresp_t;			/* contains one epipolar point correspondence, sub-pixel accurate */

typedef float32                   	aErrorOutput_array_t[10];/* [0]: Rectification error result of SelfEval mode
[1]: Rectification error result of coarse calibration
[2]: Rectification error result of fine calibration
[3]: Deviation of SPOD distance and radar distance
[4]: Disparity map density from 0 to 100 
[5]...[9]: Reserve */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteGbBlockageStatus_t eBlockageStatus;
 	uint8 uiStatusConf;
 } SacRteGbFctBlockage_t;			/* For communication with non volatile memory (NVM) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uint16 ROIStartX;
 	uint16 ROIStartY;
 	uint16 ROIStartRelCroiX;
 	uint16 ROIStartRelCroiY;
 	uint16 ROIWidth;
 	uint16 ROIHeight;
 	uint16 ImgHeight;
 	uint16 ImgWidth;
 } SacRteImageAndRoiParameters_t;			/* start and size of ROI, size of complete image */

typedef sint16                    	aLutData_array_t[1122];/* LUT data */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 siAngle;
 	uint8 uiConfidence;
 } SacRteNvAngleLearnNode_t;			/* Defines the current mode of the framework software
00u,    !< undefined, do not react to it 
10u,    !< Software framework is running SAC in StandAlone Mode 
20u     !< Software framework is running SAC in parallel to other functions */

typedef SacRteNvAngleLearnNode_t  	aNode_array_t[16];/* Learning nodes */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fQThres;
 	bool8 bMode;
 } SacRteQThres_t;			/* Used for quality threshold array */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	sint32 siCrcChecksum;
 	sint32 siSeqCntr;
 	sint32 siRduDTQTimestamp;
 	sint32 siRduGlobTimestamp;
 	sint32 siFft;
 	float32 fXPosition;
 	float32 fVxSpeed;
 	float32 fYPosition;
 	sint32 siDataQuality;
 } SacRteRadarDistInput_t;			/* Radar data which can be used for yaw angle computation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 siImgSyncOffset;
 	sint32 siGlobROIShiftVert;
 	sint32 siGlobROIShiftHoriz;
 	float32 fRectScalefactor;
 	uint16 uiVanishingPointURight;
 	uint16 uiVanishingPointVRight;
 	uint16 uiVanishingPointULeft;
 	uint16 uiVanishingPointVLeft;
 } SacRteShiftedRoiData_t;			

typedef float32                   	aKmetersLastError_array_t[10];/* kilometers (odometer) of last error */	/* [Satisfies_rte sws 1189] */

typedef float32                   	SacRteWindshieldModelCoefficients_t[5];/* Model coefficients of windshield distortion model (M[4]*u*v^2 + M[3]*v^2 + M[2]*u*v + M[1]*v + M[0] = dv) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fXPosition;
 	float32 fQuality;
 	sint32 siValid;
 	uint32 uiObjID;
 	float32 y_bl_m;
 	float32 y_br_m;
 } SacRteStereoDistInput_t;			/* For communication with non volatile memory (NVM) */

typedef float32                   	fTemperat_array_t[10];/* array filled with temperatures: [0]: right imager temperature, 
                                                                [1]: left imager temperature,
                                                                [2]: MCU tempertaure
                                                                [3]: Stereo DSP temperature,
                                                                [4]: Mono DSP temperature
                                                                [5]: FPGA temperature
                                                                [6]: interior temperature
                                                                [7]: exterior temperature
                                                             [8..9]: reserved */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fA00;
 	float32 fA10;
 	float32 fA20;
 	float32 fA01;
 	float32 fA11;
 	float32 fA21;
 	float32 fA02;
 	float32 fA12;
 	float32 fA22;
 	float32 fA03;
 	float32 fA13;
 	float32 fA23;
 } Mat3x4_t;			/* 3x4 matrix type (1st index = row, 2nd index = column) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fU;
 	float32 fV;
 	float32 fD;
 } SacRteYawPoint_t;			/* A single stereo result for yaw angle estimation */

typedef SignalHeader_t            	aErrorTFstamp_array_t[10];/* [0]...[9]: Corresponding timestamp and framecounter information to ErrorOutput array */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteCalibQuality_t eOverall;
 	SacRteCalibQuality_t ePitch;
 	SacRteCalibQuality_t eRoll;
 	SacRteCalibQuality_t eYaw;
 	SacRteCalibQuality_t eDiparity;
 	aErrorOutput_array_t aErrorOutput;
 	aErrorTFstamp_array_t aErrorTFstamp;
 } SacRteEvalOutput_t;			/* Output of the SelfEvaluation mode and other quality measures from different sources */

typedef sint32                    	aLastError_array_t[10];/* number of last SAC error, corresponding to KmetersLastError */	/* [Satisfies_rte sws 1189] */

typedef uint32                    	aNumberUsedFramesHistogramBin_array_t[6];/* Bin 0:     0 < NoUsedFrames <=    10
Bin 1:    10 < NoUsedFrames <=   100
Bin 2:   100 < NoUsedFrames <=  1000
Bin 3:  1000 < NoUsedFrames <= 10000
Bin 4: 10000 < NoUsedFrames <= 20000
Bin 5:        NoUsedFrames >  20000 */	/* [Satisfies_rte sws 1189] */

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
 	ImageDataFormat_t eDataFormat;
 	ParameterID_t uiParameterId;
 	uint32 uiFingerprint;
 } ImageHeader_t;			/* Common header for all image (aka 2D array) types */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	aNode_array_t aNode;
 	uint16 uiStatusRead;
 	uint16 uiStatusWrite;
 	uint16 uiStatusWritePending;
 	sint16 siProductionAngle;
 } SacRteNvAngleLearnTable_t;			/* Learned temperature table in NVM */

typedef uint32                    	aRectificationErrorHistogramBin_array_t[12];/* Bin 0: Recterror == 0 (i.e. undefined)
Bin 1: 0   < Recterror <= 0.1
Bin 2: 0.1 < Recterror <= 0.2
Bin 3: 0.2 < recterror <= 0.3
Bin 4: 0.3 < Recterror <= 0.4
Bin 5: 0.4 < Recterror <= 0.5
Bin 6: 0.5 < Recterror <= 0.6
Bin 7: 0.6 < Recterror <= 0.7
Bin 8: 0.7 < Recterror <= 0.8
Bin 9: 0.8 < Recterror <= 0.9
Bin10: 0.9 < Recterror <= 1.0
Bin11:       Recterror >  1.0 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uint32 uiFlexrayBitfieldPartA;
 	uint32 uiFlexrayBitfieldPartB;
 	aRectificationErrorHistogramBin_array_t aRectificationErrorHistogramBin;
 	aNumberUsedFramesHistogramBin_array_t aNumberUsedFramesHistogramBin;
 	float32 fKmetersCurrent;
 	float32 fKmetersLastCoarseCalib;
 	float32 fKmetersLastFineCalib;
 	float32 fKmetersLastYawCalib;
 	aKmetersLastError_array_t aKmetersLastError;
 	float32 fKmetersStartOfStatistic;
 	aLastError_array_t aLastError;
 	float32 fCurrRecterror;
 	uint32 uiCurrNoUsedFrames;
 	float32 fMaxDistCalib;
 	uint32 uiMaxNoUsedFramesFine;
 	uint32 uiMaxNoUsedFramesCoarse;
 	float32 fMinPitch;
 	float32 fCurrPitch;
 	float32 fMaxPitch;
 	float32 fMinYaw;
 	float32 fCurrYaw;
 	float32 fMaxYaw;
 	float32 fMinRoll;
 	float32 fCurrRoll;
 	float32 fMaxRoll;
 	SacRteSource_t eSource;
 	AlgoSignalState_t eStatisticsState;
 	uint32 FrameCnt;
 	SacRteGbFctBlockage_t Blockage;
 	uint32 RadarCal;
 	uint32 BinFill;
 	SacRteBswSchedulingMode_t eCurrentSchedulingMode;
 	SacRteReturnState_t eAlgoReturnState;
 	AlgoComponentVersionNumber_t VersBugfx;
 	AlgoComponentVersionNumber_t VersMinor;
 	AlgoComponentVersionNumber_t VersMajor;
 } SacRteStatistics_t;			/* Output of sac statistics data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	fTemperat_array_t fTemperat;
 	uint16 uiNoOfEntries;
 } SacRteTempArray_t;			/* For communication with non volatile memory (NVM) */

typedef uint8                     	aDebugData_array_t[20];/* Array of debug data */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	aDebugData_array_t aDebugData;
 } BusDebugData_t;			/* Generic bus debug data array, with version number */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t s_SignalHeader;
 	GB_t_eHeatingActivationRequest ui8_HeatingActivationRequest;
 } CB_t_HeatingRequest_t;			/* Heating activation request from Camera Blockage @vaddr:0x20097000, 0x34087000 @vaddr_defs: CB_MEAS_ID_HEATING_REQUEST,SCB_MEAS_ID_HEATING_REQUEST @cycleid:CB_ENV,SCB_ENV @vname:pCbHeatingRequest,pScbHeatingRequest */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ui16_X;
 	uint16 ui16_Y;
 } GB_t_2DPoint_t;			/* Image point */

typedef float32                   	LKA_CUSTOM_DLC_DISPLACEM_CURVE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_CUSTOM_TLC_DISPLACEM_CURVE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_DLC_CURVE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_DLM_THRES_CURVE_INSIDE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_DLM_THRES_CURVE_OUTSIDE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_LANE_WIDENING_CURVE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_LATERAL_DEVIATION_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_SUPRESS_ACTIVITY_TIME_CURVE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef float32                   	LKA_TLC_CURVE_array_t[4];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 LKA_V_LKA_EXCEED_KMH;
 	float32 LKA_V_LKA_EXCEED_MPH;
 	float32 LKA_V_LKA_ACTIVE_KMH;
 	float32 LKA_V_LKA_ACTIVE_MPH;
 	float32 LKA_V_LKA_INACTIVE_KMH;
 	float32 LKA_V_LKA_INACTIVE_MPH;
 	LKA_VELOCITY_UNIT_t LKA_VELOCITY_UNIT;
 	float32 LKA_MIN_LANE_WIDTH;
 	float32 LKA_MIN_LANE_WIDTH_HYST;
 	float32 LKA_MAX_LANE_WIDTH;
 	float32 LKA_LANE_WIDTH_DEFAULT;
 	float32 LKA_MIN_LANE_WIDTH_ACTIVATION_HYST;
 	float32 LKA_MIN_LANE_WIDTH_DEACTIVATION_HYST;
 	float32 LKA_PRED_QUAL_ACTIVE;
 	float32 LKA_PRED_QUAL_INACTIVE;
 	float32 LKA_T_MIN_ALERT;
 	float32 LKA_T_MAX_ALERT;
 	float32 LKA_T_SUPP_ALERT;
 	float32 LKA_ALERT_TIME_HYSTERESIS;
 	float32 LKA_TIME_WARN;
 	LKA_TLC_CURVE_array_t LKA_TLC_CURVE;
 	float32 LKA_DISTANCE_WARN;
 	LKA_DLC_CURVE_array_t LKA_DLC_CURVE;
 	LKA_DLM_THRES_CURVE_INSIDE_array_t LKA_DLM_THRES_CURVE_INSIDE;
 	LKA_DLM_THRES_CURVE_OUTSIDE_array_t LKA_DLM_THRES_CURVE_OUTSIDE;
 	float32 LKA_T_CURVATURE_AHEAD;
 	LKA_LATERAL_DEVIATION_array_t LKA_LATERAL_DEVIATION;
 	LKA_LANE_WIDENING_CURVE_array_t LKA_LANE_WIDENING_CURVE;
 	float32 LKA_ACTIVITY_THRESHOLD;
 	float32 LKA_LANECHANGE_THRESHOLD;
 	float32 LKA_LIGHT_ACTIVITY_THRESHOLD;
 	float32 LKA_LIGHT_LANECHANGE_THRESHOLD;
 	float32 LKA_SUPRESS_ACTIVITY_TIME;
 	LKA_SUPRESS_ACTIVITY_TIME_CURVE_array_t LKA_SUPRESS_ACTIVITY_TIME_CURVE;
 	float32 LKA_SUPRESS_LANE_CHANGE_TIME;
 	float32 LKA_CHASSIS_CONTROL_EVENT_TIME;
 	float32 LKA_MAX_TURNLIGHT_TIME;
 	float32 LKA_TURNLIGHT_EXTEND_TIME;
 	float32 LKA_RESET_DIST_INNER;
 	float32 LKA_RESET_DIST_OUTER;
 	LKA_CUSTOM_TLC_DISPLACEM_CURVE_array_t LKA_CUSTOM_TLC_DISPLACEM_CURVE;
 	LKA_CUSTOM_DLC_DISPLACEM_CURVE_array_t LKA_CUSTOM_DLC_DISPLACEM_CURVE;
 	E_FCTIF_ALDWWarnShiftBound_t LKA_WARNING_SHIFT_BOUND;
 	E_FCTIF_ALDWRoadEdgeWarn_t LKA_ROAD_EDGE_WARNING;
 	float32 LKA_ROAD_EDGE_WARNING_LINE_SHIFT;
 	float32 LKA_WARNING_CANCEL_LATERAL_DISTANCE_INNER;
 	float32 LKA_WARNING_CANCEL_LATERAL_DISTANCE_OUTER;
 	float32 LKA_TLC_WARNING_LINE_OFFSET;
 	float32 LKA_ONE_SIDE_TLC_THRESHOLD_REDUCE;
 	float32 LKA_ONE_SIDE_TLC_WARNING_LINE_SHIFT;
 	float32 LKA_ONE_SIDE_DLC_WARNING_LINE_SHIFT;
 	float32 LKA_LDIM_STEERING_WHEEL_ANGLE_RATE_THRESHOLD;
 	float32 LKA_LDIM_BRAKE_TORQUE_THRESHOLD;
 } ALDW_Parameters_t;			/* standard ALDW parameters */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNr;
 	SignalHeader_t sSignalHeader;
 	ALDW_Parameters_t ALDW_Parameters;
 } CPAR_ALDW_Parameters_t;			/* @vaddr:0x202C9D00 @vaddr_defs: FCT_MEAS_ID_ALDW_PAR @cycleid:ALDW_VEH_IN @vname:pCPAR_ALDW_Parameters */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fWidth;
 	float32 fHeight;
 	float32 fDistanceCircle2Circle;
 	float32 fDistanceCircle2Center;
 	float32 fOuterCircleDiameter;
 	float32 fInnerCircleDiameter;
 } EcmRtePatternParameter_t;			/* parameters of the calibration pattern */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f32_Pitch;
 	float32 f32_Roll;
 	float32 f32_Yaw;
 	uint32 ui32_Quality;
 } EcmRteSensorAngles_t;			/* sensor angles */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EcmRteSensorAngles_t sTolerancePositive;
 	EcmRteSensorAngles_t sToleranceNegative;
 } EcmRteSensorAngularTolerances_t;			/* angular mounting tolerances of the sensor (wrt. To nominal orientation) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fCalibCamStartYaw;
 	float32 fCalibCamStartRoll;
 	float32 fCalibCamStartPitch;
 	float32 fCalibCamAbsDevYaw;
 	float32 fCalibCamAbsDevRoll;
 	float32 fCalibCamMinDevPitch;
 	float32 fCalibCamMaxDevPitch;
 	float32 fThreshCaliRollSigmaOk2Nok;
 	float32 fThreshCaliRollSigmaNok2Ok;
 	float32 fCaliRollSigmaWindowSize;
 	float32 fThreshCaliPitchSigmaOk2Nok;
 	float32 fThreshCaliPitchSigmaNok2Ok;
 	float32 fCaliPitchSigmaWindowSize;
 	float32 fThreshCaliYawSigmaOk2Nok;
 	float32 fThreshCaliYawSigmaNok2Ok;
 	float32 fCaliYawSigmaWindowSize;
 	float32 fThreshCaliHeightSigmaOk2Nok;
 	float32 fThreshCaliHeightSigmaNok2Ok;
 	float32 fCaliHeightSigmaWindowSize;
 	float32 fCalibMaxInitialDistance;
 } CPAR_Emo_t;			/* Egomotion coding parameters @vaddr:0x30B00200 @vaddr_defs: EMO_MEAS_ID_CPAR @cycleid:IPC_ENV @vname:pCPAR_Emo */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EBACodingParam_t EBACodingParam;
 	bool8 EBACodingParamValid;
 } CPAR_EBA_Parameters_t;			/* Coding Parameters for EBA Function */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNr;
 	SignalHeader_t sSigHeader;
 	CPAR_EBA_Parameters_t EBA;
 } CPAR_FCT_Parameters_t;			/* FCT Coding Parameters @vaddr:0x202CA400 @vaddr_defs: FCT_MEAS_ID_CPAR_FCT_PARAMETERS @cycleid:FCT_VEH,FCT_ENV @vname:pCPAR_FCT_Parameters */

typedef float32                   	AreaRightBorderArray_array_t[4];/* Right border of dimming areas, i.e.
(left Roi border, AreaRightBorderArray[0] ],  (AreaRightBorderArray[0], AreaRightBorderArray[1] ]
(AreaRightBorderArray[1], AreaRightBorderArray[2] ]
(AreaRightBorderArray[2], AreaRightBorderArray[3] ]
(default value: -7°, -3°, 3°, 7°) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 ConfidenceThreshold;
 	float32 ClearMeas2Blockage_DistThres;
 	float32 ClearMeas2Blockage_TimeThres;
 	float32 ClearMeas2NoBlockage_DistThres;
 	float32 NoBlockage2Blockage_DistThres;
 	float32 NoBlockage2Blockage_TimeThres;
 	float32 Blockage2NoBlockage_TimeThres;
 	RTE_HLA_BlockageManualOverwrite ManualOverwrite;
 } RTE_HLAF_ParameterBlockage_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	DimmingDetection_t DimmingDetection;
 	AreaRightBorderArray_array_t AreaRightBorderArray;
 	uint8 ReductThreshLevel1;
 	uint8 ReductThreshLevel2;
 	float32 TurnOnDelay;
 } RTE_HLAF_ParameterDimming_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ConfidenceThreshold;
 	uint16 Sensitivity;
 } RTE_HLAF_ParameterFog_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Radius2TurnsOnThres;
 	float32 TurnOnDelay;
 } RTE_HLAF_ParameterKeepOffSmallRadius_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLAF_ParameterKeepOffSmallRadius_t SmallRadius;
 } RTE_HLAF_ParameterKeepOff_t;			/* High beam keep off parameter. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 MaxNumGlarefreeArea;
 } RTE_HLAF_ParameterMatrixBeam_t;			

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
 } RTE_HLAF_ParameterSpeed_t;			/* Speed threshold for high beam activation/ deactivation. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 TTBThreshold;
 	float32 HorAngThreshold;
 } RTE_HLAF_ParameterTurnOff_t;			/* High beam turn off parameter. */

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
 } RTE_HLAF_ParameterTurnOnDelay_t;			/* High beam turn on delay. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLAF_ParameterTurnOff_t TurnOff;
 	RTE_HLAF_ParameterKeepOff_t KeepOff;
 	RTE_HLAF_ParameterTurnOnDelay_t TurnOnDelay;
 	RTE_HLAF_ParameterSpeed_t Speed;
 	RTE_HLAF_ParameterBlockage_t Blockage;
 	RTE_HLAF_ParameterFog_t Fog;
 	RTE_HLAF_ParameterMatrixBeam_t Matrix;
 	RTE_HLAF_ParameterDimming_t Dimming;
 } CPAR_HLAF_Parameter_t;			/* HLAF parameter @vaddr:0x31201000 @vaddr_defs: RTE_HLA_MEAS_VADDR_HLAF_PAR @cycleid:IPC_ENV @vname:RTE_CPAR_HLAF_Parameter */

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
 } RTE_HLAR_ParameterAmbient_t;			

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
 } RTE_HLAR_ParameterCity_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 LightHeight_Min;
 	float32 LightHeight_Max;
 	float32 DistFilterConst;
 } RTE_HLAR_ParameterDistEst_t;			/* Parameters used for distance estimation. */

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
 } RTE_HLAR_ParameterHighway_t;			

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
 } RTE_HLAR_ParameterLightPair_t;			/* Parameters used in pair tracker. */

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
 } RTE_HLAR_ParameterRoi_t;			/* definition of the function roi:                                                                                                              only in the function ROI HLA detects vehicles and the high beam will be swichted off                                                          lights above the function roi could be streetlamps but no relevant vehicle */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 ttbAngle;
 } RTE_HLAR_ParameterTTBEst_t;			/* Parameters used for time to border estimation. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 NumOncLightsThres;
 	uint16 NumOncLightsLock;
 } RTE_HLAR_ParameterTrafficStyle_t;			

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
 } RTE_HLAR_ParameterTunnel_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 OncSensitivity;
 	uint16 PrecSensitivity;
 } RTE_HLAR_ParameterVehDet_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLAR_ParameterRoi_t Roi;
 	RTE_HLAR_ParameterCity_t City;
 	RTE_HLAR_ParameterHighway_t Highway;
 	RTE_HLAR_ParameterTunnel_t Tunnel;
 	RTE_HLAR_ParameterTrafficStyle_t TrafficStyle;
 	RTE_HLAR_ParameterAmbient_t Ambient;
 	RTE_HLAR_ParameterVehDet_t Vehicle;
 	RTE_HLAR_ParameterLightPair_t LightPair;
 	RTE_HLAR_ParameterDistEst_t DistEst;
 	RTE_HLAR_ParameterTTBEst_t TTBEst;
 } CPAR_HLAR_Parameter_t;			/* HLAR parameter @vaddr:0x31200800 @vaddr_defs: RTE_HLA_MEAS_VADDR_HLAR_PAR @cycleid:IPC_ENV @vname:RTE_CPAR_HLAR_Parameter */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLA_TestMode TestMode;
 	RTE_HLA_CityDetection CityDetection;
 	RTE_HLA_TunnelDetection TunnelDetection;
 	RTE_HLA_BadPixelDetection BadPixelDetection;
 	RTE_HLA_FogDetection FogDetection;
 	RTE_HLA_BlockageDetection BlockageDetection;
 } RTE_HLA_ParameterAlgoCfg_t;			/* Algo configuration */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLA_TrafficStyle TrafficStyle;
 	RTE_HLA_SensMode SensitivityMode;
 	RTE_HLA_MultipleReflectors CountryWithMultipleReflectors;
 	RTE_HLA_CountryCode CountryCode;
 } RTE_HLA_ParameterCountry_t;			/* Country depending parameter */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLA_HeadlightType HeadLightType;
 	RTE_HLA_HeadLightMechanics HeadLightMechanics;
 	RTE_HLA_SpotLight SpotLight;
 	float32 SpotLightWidth;
 	float32 FullHBDefaultPos_Left;
 	float32 FullHBDefaultPos_Right;
 	float32 HeadLampLatency;
 	float32 SpotLightTolerance;
 } RTE_HLA_ParameterHeadlight_t;			/* Headlamp parameter */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLA_WindshieldType WindshieldType;
 } RTE_HLA_ParameterVehicle_t;			/* Vehicle parameter */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLA_Type HLAType;
 	RTE_HLA_ParameterAlgoCfg_t AlgoCfg;
 	RTE_HLA_ParameterHeadlight_t Headlight;
 	RTE_HLA_ParameterVehicle_t Vehicle;
 	RTE_HLA_ParameterCountry_t Country;
 } CPAR_HLA_Parameter_t;			/* HLA parameter for HLAR and HLAF @vaddr:0x31200050 @vaddr_defs: RTE_HLA_MEAS_VADDR_HLA_PAR @cycleid:IPC_ENV @vname:RTE_CPAR_HLA_Parameter */

typedef uint8                     	aubConfigData_array_t[8];/* Configuration */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	sint32 iMirroringFactorLengthSegmentOne;
 	float32 fMirroringMaxTangentAngle;
 	sint32 iCalibEnableMacSemoForLane;
 	aubConfigData_array_t aubConfigData;
 	float32 CALIB_CAM_R_START_YAW;
 	float32 CALIB_CAM_R_START_ROLL;
 	float32 CALIB_CAM_R_START_PITCH;
 	float32 CALIB_CAM_R_ABS_DEV_YAW;
 	float32 CALIB_CAM_R_ABS_DEV_ROLL;
 	float32 CALIB_CAM_R_MIN_DEV_PITCH;
 	float32 CALIB_CAM_R_MAX_DEV_PITCH;
 	float32 CALIB_MAX_DIST_INITAL_MAC_CALIB;
 } CPAR_Ld_t;			/* Coding parameters for LD @vaddr:0x30E48000 @vaddr_defs: LD_MEAS_ID_CPAR_DATA @cycleid:IPC_ENV @vname:pCParLd */

typedef uint8                     	SrCustomFeature_array_t[8];/* custom feature vector */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	bool8 enable;
 	SR_RTE_ApplicationControlFlow_t SrControlFlow;
 	SrCountryVariationVehicle_t SrCountryVariationVehicle;
 	SrTsmCountryVariation_t SrTsmCountryVariation;
 	SrFeatureMaster_t SrFeatureMaster;
 	SrCustomFeature_array_t SrCustomFeature;
 } CPAR_SR_RTE_parameters_t;			/* coding parameter input @vaddr:0x30D81000 @vaddr_defs: SR_RTE_MEAS_ID_CODING_PARAMS @cycleid:IPC_ENV @vname:SrRteCodingParams */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteWindshieldModelCoefficients_t aWindshieldModelCoefficients;
 	SacRteInputCheckerMode_t eInputCheckerMode;
 	SacRteOutputCheckerMode_t eOutputCheckerMode;
 	float32 fStandaloneModeCalibDistTheshold;
 	float32 fParallelModeCalibDistThreshold;
 	float32 fRectificationErrorThreshold;
 	float32 fDisparityDensityThreshold;
 } CPAR_SacRte_t;			/* CPAR private input structure for SAC @vaddr:0x30902000 @vaddr_defs: SAC_RTE_MEAS_ID_IN_CPAR @cycleid:IPC_ENV @vname:pCParSac */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	bool8 enable;
 	TsaControlFlow_t TsaControlFlow;
 	TsaCountryVariationVehicle_t TsaCountryVariationVehicle;
 	countryConfig_t countryConfig;
 } CPAR_TSA_RTE_parameters_t;			/* coding parameter input @vaddr:0x20044600 @vaddr_defs: TSA_RTE_MEAS_ID_CODING_PARAMS @cycleid:IPC_ENV @vname:TsaRteCodingParams */

typedef uint16                    	CippHistogram_array_t[256];/* Histogram array @min:0 @max:65535 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	CippHistogram_array_t aHistogramAboveHorizon;
 	CippHistogram_array_t aHistogramBelowHorizon;
 	CippHistogram_array_t aHistogramCompleteImage;
 } CippRteImageStatistics_t;			/* Image statistics of the CIPP output images @vaddr:0x30511900 @vaddr_defs: CIPP_MEAS_ID_IMG_STAT @cycleid:CIPP_ENV @vname:CippRteImageStatistics */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	sint32 s_WbStaticRed;
 	sint32 s_WbStaticBlue;
 	sint32 s_WbDynMeasRed;
 	sint32 s_WbDynMeasBlue;
 	sint32 s_WbDynUsedRed;
 	sint32 s_WbDynUsedBlue;
 	sint32 s_WbDynConfidenceRed;
 	sint32 s_WbDynConfidenceBlue;
 	float32 f_WbRatioStaticRed;
 	float32 f_WbRatioStaticBlue;
 	float32 f_WbRatioDynRed;
 	float32 f_WbRatioDynBlue;
 	float32 f_WbRatioUsedRed;
 	float32 f_WbRatioUsedBlue;
 } CippWhiteBalanceResult_t;			/* White balancing qualifiers of the CIPP result frames @vaddr:0x30511800 @vaddr_defs: CIPP_MEAS_ID_WBR @cycleid:CIPP_ENV @vname:CippWhiteBalanceResult */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	ImageHeader_t sImgHeader;
 	const  DisparityElement_t *   pDisparityData;
} DisparityImage_t;			/* Disparity map stored as 2D array */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_Length;
 	float32 f_Width;
 	float32 f_Height;
 } EMB0_t_ObjectDimensionInfo;			/* This data type summarizes object dimension information (e.g. length, width) of an object. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EMB0_t_ObjFlashLightStat statusFlashLight;
 	EMB0_t_ObjBrakeLightStat statusBrakingLight;
 	percentage_t percentageOwnDrivingLane;
 	percentage_t percentageSideDrivingLaneLeft;
 	percentage_t percentageSideDrivingLaneRight;
 	uint8 dummy_81;
 	uint8 dummy_82;
 	uint8 dummy_83;
 } EMB0_t_ObjectFrontCameraInfo;			/* This data type contains information provided by front camera only, e.g. brakelight status or status of blinker which is not visible for other sensors. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_SpeedAbsoluteX;
 	float32 f_SpeedAbsoluteY;
 	float32 f_AccelAbsoluteX;
 	float32 f_AccelAbsoluteY;
 	float32 f_YawAngle;
 	float32 f_YawSpeed;
 } EMB0_t_ObjectMovementInfo;			/* This data type summarizes absolute speed and yaw angle information of an object. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_StdDevSpeedAbsoluteX;
 	float32 f_StdDevSpeedAbsoluteY;
 	float32 f_StdDevAccelAbsoluteX;
 	float32 f_StdDevAccelAbsoluteY;
 	float32 f_StdDevYawAngle;
 	float32 f_StdDevYawSpeed;
 } EMB0_t_ObjectMovementStdDev;			/* This data types summarizes standard deviations for movement information of an object. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_PositionX;
 	float32 f_PositionY;
 	float32 f_PositionZ;
 } EMB0_t_ObjectPositionInfo;			/* This data type summarizes object position information. The coordinates are in vehicle coordinate system. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	percentage_t existenceProbability;
 	percentage_t probabilityPedestrian;
 	percentage_t probabilityCyclist;
 	percentage_t probabilityBike;
 	percentage_t probabilityCar;
 	percentage_t propabilityTruck;
 	percentage_t probabilityOtherVehicles;
 	percentage_t probabilityRoadBoundary;
 	percentage_t probabilityBridge;
 	percentage_t probabilityUnknown;
 	uint8 dummy_81;
 	uint8 dummy_82;
 } EMB0_t_ObjectProbabilityInfo;			/* This data type represents the classification vector of an object. An object can be classified with 80% as car and 20% as truck. The individual probabilities are stored in this data type. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 u_ObjectId;
 	EMB0_t_MeasurementStatus statusMeasurement;
 	EMB0_t_ObjectMovementStatus statusMovement;
 	EMB0_t_ObjectType classificationType;
 	EMB0_t_ObjectModeLateral modeLateral;
 	EMB0_t_DrivingTubeMapping drivingTubeMapping;
 	EMB0_t_ObjectReferencePoint referencePoint;
 	uint8 dummy_81;
 } EMB0_t_ObjectRecognitionInfo;			/* This datatype summarizes status information of an object. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_StdDevPositionX;
 	float32 f_StdDevPositionY;
 	float32 f_StdDevPositionZ;
 	float32 f_StdDevLength;
 	float32 f_StdDevWidth;
 	float32 f_StdDevHeight;
 } EMB0_t_ObjectPositionStdDev;			/* This data type summarizes standard deviations for position and extension information of an object. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EMB0_t_Flags flags;
 } EMB0_t_ObjectSignalInvalidFlags;			/* This data types summarizes standard deviations for movement information of an object. */

typedef EMB0_t_ObjectDimensionInfo 	EMB0_t_ScamOeiArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectFrontCameraInfo 	EMB0_t_ScamOfciArray[40];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 u_NumberOfPedestrians;
 	uint8 u_NumberOfCyclists;
 	uint8 u_NumberOfBikes;
 	uint8 u_NumberOfCars;
 	uint8 u_NumberOfTrucks;
 	uint8 u_NumberOfOtherVehicles;
 	uint8 u_NumberOfRoadBoundaries;
 	uint8 u_NumberOfBridges;
 	uint8 u_NumberOfUnknownObjects;
 	uint8 u_NumberOfFreeFormObjects;
 	uint8 dummy_82;
 	uint8 dummy_83;
 } EMB0_t_ObjectListCounts;			/* This data type provides a brief summary of object type distribution over in the lists (e.g. how many cars, how many bikes). */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_SwVersionNumber;
 	EMB0_t_Service dataComplete;
 	uint8 u_NumOfEventGroups;
 	EMB0_t_Service commonCRC_OK;
 	uint8 u_NumberOfObjects;
 	uint32 u_Counter;
 	uint32 u_Timestamp;
 	EMB0_t_EventDataQualifier eventDataQualifier;
 	EMB0_t_ExtendedQualifier extendedQualifier;
 } EMB0_t_ObjectListHeader;			/* This data type provides common status information about the object property lists. */

typedef EMB0_t_ObjectMovementInfo 	EMB0_t_ScamOmiArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectMovementStdDev 	EMB0_t_ScamOmsdArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectPositionInfo 	EMB0_t_ScamOpiArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectPositionStdDev 	EMB0_t_ScamPsdArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectProbabilityInfo 	EMB0_t_ScamOpriArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectRecognitionInfo 	EMB0_t_ScamOriArray[40];			/* [Satisfies_rte sws 1189] */

typedef EMB0_t_ObjectSignalInvalidFlags 	EMB0_t_ScamSigFlagArray[40];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t u_VersionNumber;
 	SignalHeader_t sSigHeader;
 	EMB0_t_SensorSource sensorSource;
 	uint32 u_CurrentExternalTime;
 	EMB0_t_ObjectListHeader objectListHeader;
 	EMB0_t_ObjectListCounts objectListCounts;
 	EMB0_t_ScamOriArray a_ObjRecognitionInfo;
 	EMB0_t_ScamOpiArray a_ObjPositionInfo;
 	EMB0_t_ScamOeiArray a_ObjDimensionInfo;
 	EMB0_t_ScamOmiArray a_ObjMovementInfo;
 	EMB0_t_ScamPsdArray a_ObjPositionStdDev;
 	EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
 	EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
 	EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
 	EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
 } EMB0_t_ObjectList_SCAM;			/* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ObjNumber_t u_ExternalID;
 } EM_t_Cust_ObjectData;			/* customer related data per internal object */

typedef EM_t_Cust_ObjectData      	EM_t_Cust_ObjectDataArray[40];/* customer related data per internal object */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t u_VersionNumber;
 	SignalHeader_t sSigHeader;
 	EM_t_Cust_ObjectDataArray CustObjects;
 } EM_t_ObjectList_Custom;			/* Custom Outputs for functional and customer requirements @vaddr:0x201FE000 @vaddr_defs: EM_MEAS_ID_CUSTOM_OUTPUT @cycleid:EM_ENV @vname:EMCustomerObjData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bTrackRequest;
 	float32 fTopLeftXpx;
 	float32 fTopLeftYpx;
 	float32 fBottomRightXpx;
 	float32 fBottomRightYpx;
 	float32 fStdDevXpx;
 	float32 fStdDevYpx;
 	float32 fStdDevHeightpx;
 	float32 fDistX;
 	float32 fDistY;
 	float32 fVelAbsX;
 	float32 fVelAbsY;
 } ImageTrackingData_t;			/* information for the pedestrian image tracker */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	uint8 uPriority;
 	ImageTrackingData_t ImageTrackingData;
 } PEDObjectData_t;			/* PED specific object data */

typedef PEDObjectData_t           	PEDObjectData_array_t[40];/* PED specific object data */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	PEDObjectData_array_t PEDObjectData;
 } EM_PED_Output_t;			/* PED specific object data sent from EM to PED expert @vaddr:0x20116200 @vaddr_defs: EM_MEAS_ID_PED_OUTPUT @cycleid:EM_ENV @vname:EMPEDObjData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	sint32 VCLObjID;
 } VCLObjectData_t;			/* VCL specific object data */

typedef VCLObjectData_t           	VCLObjectData_array_t[40];/* VCL specific object data */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	VCLObjectData_array_t VCLObjectData;
 } EM_VCL_Output_t;			/* VCL specific object data sent from EM to VCL expert @vaddr:0x20116000 @vaddr_defs: EM_MEAS_ID_VCL_OUTPUT @cycleid:EM_ENV @vname:EMVclObjData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EM_t_CamObjStatusBrakeLight eStatusBrakeLight;
 	EM_t_CamObjStatusFlashLight eStatusFlashLight;
 	EM_t_CamObjAssociatedLane eAssociatedLane;
 	percentage_t percentageOwnDrivingLane;
 	percentage_t percentageSideDrivingLaneLeft;
 	percentage_t percentageSideDrivingLaneRight;
 } EM_t_CamObjAttributes;			/* Camera specific attributes */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	percentage_t probabilityPedestrian;
 	percentage_t probabilityCyclist;
 	percentage_t probabilityMotorbike;
 	percentage_t probabilityCar;
 	percentage_t probabilityTruck;
 	percentage_t probabilityOtherVehicle;
 	percentage_t probabilityRoadBoundry;
 	percentage_t probabilityUnknown;
 } EM_t_CamObjClassification;			/* Object probabilty for specific object class */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fHeight;
 	float32 fHeightStd;
 	float32 fOffsetToGround;
 	float32 fOffsetToGroundStd;
 } EM_t_CamObjGeometry;			/* Object size related properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fDistZ;
 	float32 fDistZStd;
 } EM_t_CamObjKinematics;			/* Kinematic object properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EM_t_CamObjKinematics Kinematic;
 	EM_t_CamObjGeometry Geometry;
 	EM_t_CamObjClassification Classification;
 	EM_t_CamObjAttributes Attributes;
 } EM_t_CamObject;			/* Object list properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiVisibilityRange;
 	uint8 uiServiceDegradation;
 	uint32 uiQualityFlags;
 } EM_t_CamObjListQualifiers;			/* Object list global qualifiers */

typedef EM_t_CamObject            	EM_t_CamObjectArray[40];/* Objects */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	EM_t_CamObjListQualifiers Qualifiers;
 	EM_t_CamObjectArray aObject;
 } EM_t_CamObjectList;			/* Object list properties @vaddr:0x201B3000 @vaddr_defs: EM_MEAS_ID_CAM_OBJECT_LIST @cycleid:EM_ENV @vname:EmCamObjectList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EM_t_GenObjDynamicProperty eDynamicProperty;
 	uint8 uiDynConfidence;
 	EM_t_GenObjClassification eClassification;
 	uint8 uiClassConfidence;
 	EM_t_GenObjOcclusionState eObjectOcclusion;
 } EM_t_GenObjAttributes;			/* Dynamic object properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fLifeTime;
 	AlgoCycleCounter_t uiLifeCycles;
 	AlgoDataTimeStamp_t uiLastMeasuredTimeStamp;
 	AlgoCycleCounter_t uiLastMeasuredCycle;
 	EM_t_GenObjMaintenanceState eMaintenanceState;
 	uint8 uiID;
 	EM_t_GenObjSplitMergeState eSplitMergeState;
 	uint8 uiMergeID;
 	uint8 uiSplitID;
 	EM_t_GenObjSensorSource eSensorSource;
 } EM_t_GenObjGenerals;			/* Global object properities */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fPosX;
 	float32 fPosY;
 	uint16 uiPosXStd;
 	uint16 uiPosYStd;
 } EM_t_GenObjShapePointCoord;			/* Coordinates relative to the fDistX, fDistY point. To form the shape they should be connected neighbourwise. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fDistX;
 	float32 fDistXStd;
 	float32 fDistY;
 	float32 fDistYStd;
 	float32 fVrelX;
 	float32 fVrelXStd;
 	float32 fVrelY;
 	float32 fVrelYStd;
 	float32 fArelX;
 	float32 fArelXStd;
 	float32 fArelY;
 	float32 fArelYStd;
 	float32 fVabsX;
 	float32 fVabsXStd;
 	float32 fVabsY;
 	float32 fVabsYStd;
 	float32 fAabsX;
 	float32 fAabsXStd;
 	float32 fAabsY;
 	float32 fAabsYStd;
 } EM_t_GenObjKinematics;			/* Kinematic object properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiProbabilityOfExistence;
 	EM_t_GenObjEbaProhibit eEbaActivationProhibit;
 	uint8 uiEbaMovingObjQuality;
 	uint8 uiEbaStationaryObjQuality;
 	uint8 uiAccObjQuality;
 } EM_t_GenObjQualifiers;			/* Characteristic properties */

typedef EM_t_GenObjShapePointState 	EM_t_GenObjSPSArray_t[4];/* State of shape point at index */	/* [Satisfies_rte sws 1189] */

typedef EM_t_GenObjShapePointCoord 	EM_t_GenObjSPCArray_t[4];/* Coordinates relative to the fDistX, fDistY point. To form the shape they should be connected neighbourwise. */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EM_t_GenObjSPSArray_t aShapePointStates;
 	EM_t_GenObjSPCArray_t aShapePointCoordinates;
 } EM_t_GenObjGeometry;			/* Object size related properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EM_t_GenObjKinematics Kinematic;
 	EM_t_GenObjGeometry Geometry;
 	EM_t_GenObjAttributes Attributes;
 	EM_t_GenObjGenerals General;
 	EM_t_GenObjQualifiers Qualifiers;
 } EM_t_GenObject;			/* Object list properties */

typedef EM_t_GenObject            	EM_t_GenObjArray[40];/* Objects */	/* [Satisfies_rte sws 1189] */

typedef ObjNumber_t               	EM_t_GenObjSortedIdxArray[40];/* Array of object indexes sorted by assending longitudinal displacement @min:0 @max:40 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ObjNumber_t iNumOfUsedObjects;
 	EM_t_GenObjSortedIdxArray iSortedObjectList;
 } EM_t_GenObjListHeader;			/* Header Object list properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	EM_t_GenObjListHeader HeaderObjList;
 	EM_t_GenObjArray aObject;
 } EM_t_GenObjectList;			/* Object list properties @vaddr:0x201B0000 @vaddr_defs: EM_MEAS_ID_GEN_OBJECT_LIST @cycleid:EM_ENV @vname:EmGenObjectList */

typedef uint8                     	aCircleBuf_array_t[1024];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 x;
 	float32 y;
 } EcmRtePoint2DFloat32_t;			/* 2D point */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	EcmRteOpMode_t eOpMode;
 } EcmRteBSWCtrlData_t;			/* Control data for the ECM module @vaddr:0x30F00000 @vaddr_defs: ECM_RTE_MEAS_ID_CTRL_BSW_DATA @cycleid:ECM_ENV @vname:EcmRteBSWCtrlData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EcmRtePoint2DFloat32_t Pos;
 	float32 Dev;
 } EcmRteAlgoMarkerAttr_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EcmRtePoint2DFloat32_t P1;
 	EcmRtePoint2DFloat32_t P2;
 } EcmRteBoxCoordinates_t;			/* ECM coordinates of a box/rectangle */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 x;
 	sint16 y;
 } EcmRtePoint2DSI16_t;			/* 2D point */

typedef EcmRteAlgoMarkerAttr_t    	List_array_t[10];/* circles */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 uiMax;
 	uint16 uiSum;
 	EcmRtePoint2DSI16_t sIPos;
 	EcmRtePoint2DFloat32_t sFPos;
 	float32 fDev;
 	sint16 siDx;
 	sint16 siDy;
 	float32 fRatio;
 	sint16 siReturnReason;
 } EcmRteCircleBufMax_t;			/* circle buffer maximum */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	List_array_t List;
 	uint32 NoCircles;
 } EcmRteAlgoCircleList_t;			/* list of circles */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fSensorSocketPositionXMin;
 	float32 fSensorSocketPositionXMax;
 	float32 fSensorSocketPositionYMin;
 	float32 fSensorSocketPositionYMax;
 	float32 fSensorSocketPositionZMin;
 	float32 fSensorSocketPositionZMax;
 	float32 fBoardPositionXMin;
 	float32 fBoardPositionXMax;
 	float32 fBoardPositionYMin;
 	float32 fBoardPositionYMax;
 	float32 fBoardPositionZMin;
 	float32 fBoardPositionZMax;
 	float32 fMinContrast;
 	float32 fMaxContrast;
 	float32 fMinBrightness;
 	float32 fMaxBrightness;
 	float32 fMaxRuntimeMs;
 	float32 fMaxRuntimeCycles;
 	uint32 uiMaxPatternDimension;
 	uint32 uiMaxCircleListElements;
 	EcmRteSensorAngularTolerances_t sSensorOrientationTolerances;
 	EcmRtePatternParameter_t sPattern;
 } CPAR_EcmRte_t;			/* @vaddr:0x30F00300 @vaddr_defs: ECM_RTE_MEAS_ID_IN_CPAR @cycleid:IPC_ENV @vname:CPAR_EcmRte_t */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	EcmRtePatPos_t eCalPatPos;
 	EcmRteProcRoiState_t eProcState;
 	EcmRteCurMarker_t eCurMarker;
 	EcmRteBoxCoordinates_t sCalRoi;
 	EcmRteBoxCoordinates_t sWinRoi;
 	EcmRteBoxCoordinates_t sWin;
 	uint32 uiContrast;
 	uint32 uiBrightness;
 	uint32 uiEdgeThreshold;
 	aCircleBuf_array_t aCircleBuf;
 	EcmRteAlgoCircleList_t CircleList;
 	EcmRteCircleBufMax_t CircleBufMax;
 	uint32 uiDbgFineCircleSearch;
 } EcmRteAlgoHis_t;			/* @vaddr:0x30F12000 @vaddr_defs: ECM_RTE_MEAS_ID_OUT_ALGO_HIS @cycleid:ECM_ENV @vname:pEcmOutDebugAlgoHistory */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f32_Z;
 	float32 f32_Y;
 	float32 f32_X;
 } PatPosFromDiag_t;			/* pattern position from diagnostics */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f32_X;
 	float32 f32_Y;
 	float32 f32_Z;
 	uint32 ui32_Quality;
 } SensorSocketFromDiag_t;			/* sensor socket parameters from diagnostics (DEV Mode)[m] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	PatPosFromDiag_t PatPosFromDiag;
 	SensorSocketFromDiag_t SensorSocketFromDiag;
 } EcmRteDiagInput_t;			/* Ecmb diagnostic inputs @vaddr:0x30F000B0 @vaddr_defs: ECM_RTE_MEAS_ID_DIAG_INPUT @cycleid:IPC_ENV @vname:EcmRteDiagInput */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 ui32_Brightness;
 	uint32 ui32_Contrast;
 	uint32 ui32_RecPatternMarker;
 	float32 f32_VehLevFL;
 	float32 f32_VehLevFR;
 	float32 f32_VehLevRL;
 	float32 f32_VehLevRR;
 	float32 f32_CarbodyFL;
 	float32 f32_CarbodyFR;
 	float32 f32_CarbodyRL;
 	float32 f32_CarbodyRR;
 } EcmRteEnvData_t;			/* Ecmbration environment data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 ui32_FoVUL_X;
 	uint32 ui32_FoVUL_Y;
 	uint32 ui32_FoVUR_X;
 	uint32 ui32_FoVUR_Y;
 	uint32 ui32_FoVLL_X;
 	uint32 ui32_FoVLL_Y;
 	uint32 ui32_FoVLR_X;
 	uint32 ui32_FoVLR_Y;
 } EcmRteFieldOfView_t;			/* Camera Field Of View */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	EcmRteFieldOfView_t EcmRteFieldOfView;
 	EcmRteEnvData_t EcmRteEnvData;
 } EcmRteEnvFoVData_t;			/* Ecmbration environment data and Field of View @vaddr:0x30F10000 @vaddr_defs: ECM_RTE_MEAS_ID_ENV_FOV_DATA @cycleid:ECM_ENV @vname:EcmRteEnvFovData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fXDist;
 	float32 fYDist;
 } Vector2_f32_t;			/* Vector with x and y with f32 values */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fRoll;
 	float32 fPitch;
 	float32 fYaw;
 	float32 fRollSigma;
 	float32 fPitchSigma;
 	float32 fYawSigma;
 	uint8 uiRollQuality;
 	uint8 uiPitchQuality;
 	uint8 uiYawQuality;
 	uint8 uiTotalAngleQuality;
 	float32 fTx;
 	float32 fTy;
 	float32 fTz;
 	float32 fTxSigma;
 	float32 fTySigma;
 	float32 fTzSigma;
 	uint8 uiTxQuality;
 	uint8 uiTyQuality;
 	uint8 uiTzQuality;
 	uint8 uiTotalTranslQuality;
 	Mat3x4_t sTransform;
 } PoseParameters_t;			/* Translational and rotational (in Euler coordinates) pose parameters and variances */

typedef float32                   	aTemperature_array_t[10];/* [0]: right imager temperature, 
[1]: left imager temperature,
[2]: MCU tempertaure
[3]: Stereo DSP temperature,
[4]: Mono DSP temperature
[5]: FPGA temperature
[6]: interior temperature
[7]: exterior temperature
[8..9]: reserved */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	aTemperature_array_t aTemperature;
 	uint16 uiTemperatureValidEntryCount;
 } EcuState_t;			/* Disparity map stored as 2D array */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eForesightIndicatorType_t eForesightIndicatorType;
 	uint8 uiForesightIndicatorQuantity;
 } eForesightIndicator_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eConstructionSiteState_t eConstructionSiteState;
 	uint8 uiConstructionSiteConfidence;
 } ConstructionSiteState_t;			

typedef eForesightIndicator_t     	eForesightIndicator_array_t[10];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eForesightState_t eForesightState;
 	uint8 uiForesightCertainty;
 	float32 fForesightDistance;
 	eForesightIndicator_array_t eForesightIndicator;
 } ConstructionSiteForesight_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	ConstructionSiteForesight_t ConstructionSiteForesight;
 	ConstructionSiteState_t ConstructionSiteState;
 } EmConstructionSite_t;			/* @vaddr:0x20117000 @vaddr_defs: EM_MEAS_ID_CONSTRUCTION_SITE @cycleid:EM_ENV @vname:EmContructionSite */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	eDegradationReason_t eDegradationReason;
 	uint8 uDegradationReasonConfidence;
 	float32 uViewRange;
 	uint8 uViewRangeConfidence;
 } EmViewingDistance_t;			/* Viewing distance degradation estimation @vaddr:0x20120000 @vaddr_defs: EM_MEAS_ID_VIEWING_DISTANCE @cycleid:EM_ENV @vname:EmViewingDistance */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fA1;
 	float32 fA2;
 	float32 fA3;
 } EmoVanishingLine_t;			/* line equation a1*x_pix + a2*y_pix + a3 = 0 */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fX;
 	float32 fY;
 } EmoVanishingPoint_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 STATUS_MAC;
 	float32 PITCH_MAC;
 	float32 YAW_MAC;
 	float32 ROLL_MAC;
 	float32 PITCH_MAC_QUAL;
 	float32 YAW_MAC_QUAL;
 	float32 ROLL_MAC_QUAL;
 	uint8 ERROR_CODE_MAC;
 } EmoToDiagnotic_t;			/* Emo export to diagnostic */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	EmoAvailability_t eEmoAvailability;
 	uint32 uiEmoTimeStamp;
 	float32 fEmoPitchToTheGround;
 	float32 fEmoRollToTheGround;
 	float32 fEmoHeightToTheGround;
 	float32 fEmoPitchToTheGroundSigma;
 	float32 fEmoRollToTheGroundSigma;
 	float32 fEmoHeightToTheGroundSigma;
 	float32 fEmoAccumulatedYaw;
 	float32 fEmoAccumulatedDist;
 	float32 fEmoVehWroll;
 	float32 fEmoVehWpitch;
 	float32 fEmoVehWyaw;
 	float32 fEmoVehWrollSigma;
 	float32 fEmoVehWpitchSigma;
 	float32 fEmoVehWyawSigma;
 	float32 fEmoVehVx;
 	float32 fEmoVehVy;
 	float32 fEmoVehVz;
 	float32 fEmoVehVxSigma;
 	float32 fEmoVehVySigma;
 	float32 fEmoVehVzSigma;
 } EmoToEthernet_t;			/* Emo export to ethernet */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	EmoToEthernet_t EmoToEthernet;
 	EmoToDiagnotic_t EmoToDiagnotic;
 } EmoExport_t;			/* Ego motion output data to export out of SoC @vaddr:0x30B1C000 @vaddr_defs: EMO_MEAS_ID_EXPORT @cycleid:EMO_ENV @vname:pEmoExport */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fQroll;
 	float32 fQpitch;
 	float32 fQyaw;
 	float32 fQrollSigma;
 	float32 fQpitchSigma;
 	float32 fQyawSigma;
 	float32 fAx;
 	float32 fAy;
 	float32 fAz;
 	float32 fAxSigma;
 	float32 fAySigma;
 	float32 fAzSigma;
 } EmoAcceleration_t;			/* Ego motion acceleration estimate (6 dof) */

typedef float32                   	aEssentialMatrix_array_t[9];/* essential matrix */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fDeltaRoll;
 	float32 fDeltaPitch;
 	float32 fDeltaYaw;
 	float32 fDeltaHeight;
 	EmoVanishingPoint_t sVanishPoint;
 	EmoVanishingLine_t sHorizonLine;
 	float32 fCaliOdometer;
 	uiStatus_t uiStatus;
 	uint8 isRollCalibrated;
 	uint8 isPitchCalibrated;
 	uint8 isYawCalibrated;
 	uint8 isHeightCalibrated;
 } EmoOnlineCalibration_t;			/* Flow based online calibration */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiTimeMain;
 	uint32 uiTimeMeasCam2CamPrepare;
 	uint32 uiTimeMeasCam2CamLevenberg;
 	uint32 uiTimeMeasSlamFeature1;
 	uint32 uiTimeMeasSlamFeature2;
 	uint32 uiTimeMeasSlamFeature3;
 	uint32 uiTimeMeasGroundPlaneExtract;
 	uint32 uiTimeKalmanPredict;
 	uint32 uiTimeKalmanUpdateWithCam2Cam;
 	uint32 uiTimeKalmanUpdateWithSlamFeature;
 	uint32 uiTimeKalmanUpdateWithGroundPlane;
 	uint32 uiTimeKalmanCycleUpdate;
 	uint32 uiTimeKalmanRemoveSlamFeature;
 	uint32 uiTimeKalmanAddSlamFeature;
 	uint32 uiTimeFTRCDisparityUpdate;
 	uint32 uiTimeAvailability;
 } EmoTimeMeas_t;			/* Time measurements of the emo component */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fWroll;
 	float32 fWpitch;
 	float32 fWyaw;
 	float32 fWrollSigma;
 	float32 fWpitchSigma;
 	float32 fWyawSigma;
 	float32 fVx;
 	float32 fVy;
 	float32 fVz;
 	float32 fVxSigma;
 	float32 fVySigma;
 	float32 fVzSigma;
 } EmoVelocity_t;			/* Ego motion velocity estimate (6 dof) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	PoseParameters_t sPose;
 	EmoVanishingPoint_t sVanishPoint;
 	EmoVanishingLine_t sHorizonLine;
 } EmoWorldToCamInstant_t;			/* Calibration parameters: camera CS to vehicle fixed CS */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	PoseParameters_t sRotTrans;
 	EmoVelocity_t EmoVelocity;
 	EmoAcceleration_t EmoAcceleration;
 	eEmoMotState_t eEmoMotState;
 	float32 fDeltaT;
 	float32 fAccumulatedYaw;
 	float32 fAccumulatedDist;
 } EmoWorldToWorld_t;			/* Inter frame vehicle motion */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	PoseParameters_t sRotTrans;
 	aEssentialMatrix_array_t aEssentialMatrix;
 	float32 fDeltaT;
 } EmoCamToCam_t;			/* Inter frame camera motion */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	EmoAvailability_t eEmoAvailability;
 	eEmoInputSource_t eEmoInputSource;
 	uint32 uiNumUsableImageFeatures;
 	uint32 uiNumUsedImageFeatures;
 	float32 fPercentageStationaryFlow;
 	EmoWorldToWorld_t EmoWorldToWorld;
 	EmoWorldToCamInstant_t EmoWorldToCamInstant;
 	EmoCamToCam_t EmoCamToCam;
 	EmoOnlineCalibration_t EmoOnlineCalibration;
 	EmoTimeMeas_t EmoTimeMeas;
 } EmoOutput_t;			/* Ego motion output data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNr;
 	SignalHeader_t sSignalHeader;
 	eLkaAldwMode_t eLKAALDWMode;
 } FCTALDWInputGeneric_t;			/* @vaddr:0x20270200 @vaddr_defs: FCT_MEAS_ID_ALDW_INPUT_GEN @cycleid:ALDW_VEH_IN @vname:FCTAldwInputGen */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNr;
 	SignalHeader_t sSignalHeader;
 	E_FCTIF_ALDWStatus_t ALDWStatus;
 	E_FCTIF_ALDWWrnRq_t ALDWWarnRq;
 	E_FCTIF_ALDWWrnMdRq_t ALDWWarnMdRq;
 	E_FCTIF_ALDWWarnSuppStat_t ALDWWarnSuppStat;
 	uint8 ALDWWarnTLCLt;
 	uint8 ALDWWarnTLCRt;
 	uint8 ALDWWarnDLCLt;
 	uint8 ALDWWarnDLCRt;
 	E_FCTIF_ALDWWarnVel_t ALDWWarnVelocity;
 } FCTALDWOutputGeneric_t;			/* @vaddr:0x20270100 @vaddr_defs: FCT_MEAS_ID_ALDW_OUTPUT_GEN @cycleid:ALDW_VEH @vname:FCTAldwOutputGen */

typedef float32                   	AnecLong_array_t[12];/* Required acceleration to avoid crash @min:-20 @max:0 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AnecLong_array_t AnecLong;
 	float32 AllowedDistance;
 } iBrkOutput_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	iBrkOutput_t iBrkOutput;
 } FCTCDOutputCustom_t;			/* @vaddr:0x20281000 @vaddr_defs: FCT_MEAS_ID_CD_CUSTOM_OUTPUT @cycleid:FCT_ENV @vname:pCollDetOutput */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	FCT_OP_MODE_t OpMode;
 	float32 fCycleTime;
 } FCTCtrlData_t;			/* FCT control data @vaddr:0x20270320, 0x20270300 @vaddr_defs: FCT_MEAS_ID_VEH_CTRL_DATA,FCT_MEAS_ID_SEN_CTRL_DATA @cycleid:FCT_VEH,FCT_ENV @vname:FCTVehCtrlData,FCTSenCtrlData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	FCTStateSig_t eSpeedLimitActive;
 } DIMInputCustom_t;			/* @vaddr:0x20230300 @vaddr_defs: FCT_MEAS_ID_DIM_INPUT_CUSTOM @cycleid:FCT_VEH_IN @vname:DIMInputCustom */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	bool8 bACCActive;
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
 } DIMInputGeneric_t;			/* @vaddr:0x20230100 @vaddr_defs: FCT_MEAS_ID_DIM_INPUT_GENERIC @cycleid:FCT_VEH_IN @vname:DIMInputGeneric */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	DIMOutMonState_t eDriverMonitoringState;
 	eDriverAttentionState_t eDriverAttentionState;
 	sint8 iLaneChangeProbability;
 	eDriverFeedbackState_t eDriverFeedbackState;
 	eDriverActivityState_t eDriverActivityState;
 } DIMOutputCustom_t;			/* @vaddr:0x20230C00 @vaddr_defs: FCT_MEAS_ID_DIM_OUTPUT_CUSTOM @cycleid:FCT_VEH @vname:pDIMOutputCustom */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	CodingParam_t CodingParam;
 	bool8 CodingParamValid;
 	FCTSubChainQualifier_t eQualifierBrakeChain;
 	FCTSubChainQualifier_t eQualifierWarnChain;
 } HEADInputCustom_t;			/* @vaddr:0x20230700 @vaddr_defs: FCT_MEAS_ID_HEAD_INPUT_CUSTOM @cycleid:FCT_VEH_IN @vname:HEADInputCustom */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	eMainSwitch_t eMainSwitch;
 	eFunctionSwitch_t eFunctionSwitch;
 	eObjectSwitch_t eObjectSwitch;
 } HEADInputGeneric_t;			/* @vaddr:0x20230500 @vaddr_defs: FCT_MEAS_ID_HEAD_INPUT_GENERIC @cycleid:FCT_VEH_IN @vname:HEADInputGeneric */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bWarningsNotPossible;
 	bool8 bBrakePreCondNotPossible;
 	bool8 bPreBrakeNotPossible;
 	bool8 bPreCrashNotPossible;
 } HEADOutCustDegadationState_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fVelocityFactor;
 	ObjNumber_t iObjRef;
 	float32 fSafeObjDistance;
 } HEADOutCustFCTData_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eFunctionQualifier_t ePedFunctionQualifier;
 	eFunctionQualifier_t eVehFunctionQualifier;
 	eFunctionQualifier_t eUnclassifiedFunctionQualifier;
 	eFunctionQualifier_t ePreCrashFunctionQualifier;
 } HEADOutCustFCTQualifier_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fHBADecel;
 	uint8 uiHBALevel;
 	eEBAObjectClass_t eFunctionObjectClass;
 } HEADOutCustHBA_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bLatentPreWarningActive;
 	bool8 bLatentAcuteWarningActive;
 	bool8 bDynamicPreWarningActive;
 	bool8 bDynamicAcuteWarningActive;
 	bool8 bHBAActive;
 	bool8 bPreFillActive;
 	bool8 bPreBrakeActive;
 } HEADOutCustHypReactions_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fPreCrashTTC;
 	float32 fPreCrashCV;
 	bool8 bEMAActive;
 	eEBAObjectClass_t eFunctionObjectClass;
 	ePreCrashLevel_t ePreCrashLevel;
 } HEADOutCustPreCrash_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fPreBrakeDecel;
 	bool8 bPreBrakeDecelEnabled;
 	bool8 bPreBrakeStdstillRequest;
 	bool8 bPreBrakeEmergency;
 	eEBAObjectClass_t eFunctionObjectClass;
 } HEADOutCustPrebrake_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bPrefillActive;
 	bool8 bPreRunActive;
 	bool8 bGeneratorActive;
 	eEBAObjectClass_t eFunctionObjectClass;
 } HEADOutCustPrefill_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bPreStaticWarningVehicle;
 	bool8 bPreStaticWarning;
 	bool8 bAcuteStaticWarningVehicle;
 	bool8 bAcuteStaticWarning;
 	ePreDynWarning_t ePreDynamicWarningVehicle;
 	ePreDynWarning_t ePreDynamicWarning;
 	eAcuteDynWarning_t eAcuteDynamicWarningVehicle;
 	eAcuteDynWarning_t eAcuteDynamicWarning;
 	ePedWarning_t ePreWarningPedestrian;
 	ePedWarning_t eAcuteWarningPedestrian;
 	bool8 bDistWarningBuzzer;
 	eDistWarningDisplay_t eDistWarningDisplay;
 } HEADOutCustWarnings_t;			

typedef HEADOutCustHypReactions_t 	rgHypReactions_array_t[12];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	HEADOutCustDegadationState_t sDegradationState;
 	HEADOutCustHBA_t sHBA;
 	HEADOutCustPrefill_t sPrefill;
 	HEADOutCustPrebrake_t sPreBrake;
 	HEADOutCustWarnings_t sWarnings;
 	HEADOutCustPreCrash_t sPreCrash;
 	rgHypReactions_array_t rgHypReactions;
 	HEADOutCustFCTData_t sFCTData;
 	HEADOutCustFCTQualifier_t sFCTQualifiers;
 } HEADOutputCustom_t;			/* @vaddr:0x20230900 @vaddr_defs: FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM @cycleid:FCT_VEH @vname:pHEADOutputCustom */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 } HEADOutputGeneric_t;			/* @vaddr:0x20230A00 @vaddr_defs: FCT_MEAS_ID_HEAD_OUTPUT_GENERIC @cycleid:FCT_VEH @vname:pHEADOutputGeneric */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	AlgoErrorState_t ObjectNotMeasured;
 	AlgoErrorState_t ObjectNotMeasTmp;
 	AlgoErrorState_t Blockage;
 	AlgoErrorState_t IncreaseBlockage;
 	AlgoErrorState_t DecreaseBlockage;
 	bool8 bObjSelectionActive;
 	bool8 bCollisionAvoidActive;
 	bool8 bRequestRoadBeam;
 } FCTSenErrorOut_t;			/* FCTSen error output structure @vaddr:0x20217500 @vaddr_defs: FCT_MEAS_ID_SEN_ERROR_OUT_VADDR @cycleid:FCT_ENV @vname:FCTSenErrorOut */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_InR_DistMonoK1;
 	float32 f32_InR_DistMonoK2;
 } FLSPCalIntrDistRight_t;			/* Calibration intrinsic distance right @vaddr:0x80720380 @vaddr_defs: FLSP_MEAS_ID_CALL_INTR_DIST @cycleid:FLSP_ENV @vname:pFlspCallIntrDist */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_DCG_Factor;
 	uint16 ui16_T1_Production;
 	uint16 ui16_Actual_T2_right;
 	uint16 ui16_Actual_T3_right;
 	uint16 ui16_ResponseCurveIndex;
 	uint16 ui16_AnalogGainMinus40;
 	uint16 ui16_AnalogGainPlus25;
 	uint16 ui16_AnalogGainPlus85;
 	uint16 ui16_AnalogGainPlus105;
 	uint16 ui16_ConversionGainMinus40;
 	uint16 ui16_ConversionGainPlus25;
 	uint16 ui16_ConversionGainPlus85;
 	uint16 ui16_ConversionGainPlus105;
 	sint16 ui16_TemperatureImager;
 	sint16 ui16_GlobalGainAdjustedRegister;
 	float32 f32_Sensitivity;
 	float32 f32_Black_Level_DarkRows_Prod_T1_511_Left;
 	float32 f32_Black_Level_DarkRows_Prod_T1_016_Left;
 } FLSPImagerCharacteristicsLeft_t;			/* Imager Characteristics Left @vaddr:0x80720340 @vaddr_defs: FLSP_MEAS_ID_IMAGER_CHAR_LEFT @cycleid:FLSP_ENV @vname:pFlspImagerCharLeft */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_DCG_Factor;
 	uint16 ui16_T1_Production;
 	uint16 ui16_Actual_T2_right;
 	uint16 ui16_Actual_T3_right;
 	uint16 ui16_ResponseCurveIndex;
 	uint16 ui16_AnalogGainMinus40;
 	uint16 ui16_AnalogGainPlus25;
 	uint16 ui16_AnalogGainPlus85;
 	uint16 ui16_AnalogGainPlus105;
 	uint16 ui16_ConversionGainMinus40;
 	uint16 ui16_ConversionGainPlus25;
 	uint16 ui16_ConversionGainPlus85;
 	uint16 ui16_ConversionGainPlus105;
 	uint16 ui16_TemperatureImager;
 	float32 f32_Black_Level_DarkRows_Prod_T1_511_Right;
 	float32 f32_Black_Level_DarkRows_Prod_T1_016_Right;
 } FLSPImagerCharacteristicsRight_t;			/* Imager Characteristics Right @vaddr:0x80720300 @vaddr_defs: FLSP_MEAS_ID_IMAGER_CHAR_RIGHT @cycleid:FLSP_ENV @vname:pFlspImagerCharRight */

typedef uint8                     	uSerialNumber_array_t[26];/* Serial number */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	uTraceNumber_array_t[14];/* Trace number */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uSerialNumber_array_t uSerialNumber;
 	uTraceNumber_array_t uTraceNumber;
 } FLSPProductionData_t;			/* Production Intrinsic @vaddr:0x80720480 @vaddr_defs: FLSP_MEAS_ID_PROD_DATA @cycleid:FLSP_ENV @vname:pFlspProdData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_FocalLength;
 	float32 f32_LensDistortion;
 	float32 f32_IntrinsicRoll;
 	float32 f32_IntrinsicPitch;
 	float32 f32_IntrinsicYaw;
 	float32 f32_HPrinAxis;
 	float32 f32_VPrinAxis;
 	float32 f32_RedGreenRatio;
 	float32 f32_BlueGreenRatio;
 	float32 f32_GreenRefRatio;
 	float32 f32_MTF_red;
 	float32 f32_MTF_green;
 	float32 f32_MTF_blue;
 	float32 f32_streylighttest;
 	float32 f32_LensTangentialDistortion;
 } FLSPProductionIntrinsic_t;			/* Production Intrinsic @vaddr:0x80720420, 0x80730750 @vaddr_defs: FLSP_MEAS_ID_PROD_INTR_RIGHT,FLSP_MEAS_ID_PROD_INTR_LEFT @cycleid:FLSP_ENV,FLSP_ENV @vname:pFlspProductionIntrinsicRight,pFlspProductionIntrinsicLeft */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f32_Brightness;
 	float32 f32_OverallMeanBrightness;
 	float32 f32_RedPixMean;
 	float32 f32_GreenPixMean;
 	float32 f32_BluePixMean;
 } s_Buffer_t;			

typedef s_Buffer_t                	s_Buffer_array_t[12];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uint32 ui32_NumberOfImagerCharacteristicPoints;
 	s_Buffer_array_t s_Buffer;
 } FLSPResponseCurvePeriphery_t;			/* Response curves @vaddr:0x80720120 @vaddr_defs: FLSP_MEAS_ID_RESPONSE_CURVE @cycleid:FLSP_ENV @vname:pFlspResponseCurve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_InFocusX;
 	float32 f32_InFocusY;
 	float32 f32_InPrincipalPointXCoordinate;
 	float32 f32_InPrincipalPointYCoordinate;
 	float32 f32_RadialDistortionCoeff1;
 	float32 f32_RadialDistortionCoeff2;
 	float32 f32_RadialDistortionCoeff3;
 	float32 f32_RadialDistortionCoeff4;
 	float32 f32_RadialDistortionCoeff5;
 	float32 f32_RadialDistortionCoeff6;
 	float32 f32_RadialDistortionCoeff7;
 	float32 f32_RadialDistortionCoeff8;
 	float32 f32_RadialDistortionCoeff9;
 	float32 f32_RadialDistortionCoeff10;
 	uint32 ui32_ActualNumberOfCoeffients;
 } FLSPStereoCalIntrinsics_t;			/* Sereo Calibration Intrinsics @vaddr:0x80720040, 0x80730700 @vaddr_defs: FLSP_MEAS_ID_STEREP_CAL_INTR_RIGHT,FLSP_MEAS_ID_STEREP_CAL_INTR_LEFT @cycleid:FLSP_ENV,FLSP_ENV @vname:pFlspStereoCalIntrinsicsRight,pFlspStereoCalIntrinsicsLeft */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_Baseline;
 	float32 f32_TranslationX;
 	float32 f32_TranslationY;
 	float32 f32_TranslationZ;
 	float32 f32_RotMatrixR11;
 	float32 f32_RotMatrixR21;
 	float32 f32_RotMatrixR31;
 	float32 f32_RotMatrixR12;
 	float32 f32_RotMatrixR22;
 	float32 f32_RotMatrixR32;
 	float32 f32_RotMatrixR13;
 	float32 f32_RotMatrixR23;
 	float32 f32_RotMatrixR33;
 	float32 f32_ROIVShiftLeft;
 } FLSPStereoCalTransRot_t;			/* Stereo Calibration Translation and Rotation @vaddr:0x807200A0 @vaddr_defs: FLSP_MEAS_ID_STEREO_TRANS_ROT @cycleid:FLSP_ENV @vname:pFLSPStereoCalTransRot */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 siPitch;
 	sint16 siRoll;
 	sint16 siYaw;
 } FLSPTempCompAngle_t;			/* Type definition for FLSP TempCompAngle */

typedef FLSPTempCompAngle_t       	FLSPTempCompAngle_array_t[16];/* Type definition for FLSP TempCompAngle */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiConfidencePitch;
 	uint8 uiConfidenceRoll;
 	uint8 uiConfidenceYaw;
 	uint8 uiPaddingByte;
 } FLSPTempCompConfidence_t;			/* Type definition for FLSP TempCompConfidence */

typedef FLSPTempCompConfidence_t  	FLSPTempCompConfidence_array_t[16];/* Type definition for FLSP TempCompConfidence */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	AlgoApplicationNumber_t uiCurveVersion;
 	float32 fCurveCalibTemp;
 	FLSPTempCompAngle_array_t FLSPTempCompAngle;
 	FLSPTempCompConfidence_array_t FLSPTempCompConfidence;
 } FLSPTemperatureCompensationList_t;			/* Initial temp model determined by distance test at camera manufacturing @vaddr:0x80730540 @vaddr_defs: FLSP_MEAS_ID_TEMP_COMP @cycleid:FLSP_ENV @vname:pFlspTemperatureCompensationList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	FexOpMode_t eOpMode;
 } FexBSWCtrlData_t;			/* Control data for the FEX module @vaddr:0x30600000 @vaddr_defs: FEX_MEAS_ID_CTRL_BSW_DATA @cycleid:FEX_ENV @vname:FexBSWCtrlData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	ImageHeader_t sImgHeader;
 	FlowImageCorrespondenceType_t eCorrespondenceType;
 	sint8 iFlowScaleX;
 	sint8 iFlowScaleY;
 	const  FlowElement_t *   pFlowData;
} FlowImage_t;			/* Optical flow data stored as 2D map */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fMinDistToObstruction;
 	float32 fMinDistToObstructionStd;
 } PolarCoords_t;			/* Minimum segment obstruction border in polar coordinates and mean Angle */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	PolarCoords_t PolarCoords;
 	eStatus_t eStatus;
 	uint8 fExistenceProbability;
 	uint8 uiDebugState;
 	float32 fHeightTop;
 	eDynamicState_t eDynamicState;
 	eValidFlags_t eValidFlags;
 } FanSegment_t;			/* properties of one segment */

typedef FanSegment_t              	aSegmentArray_array_t[80];/* Fan model, consisting of N segments */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	eServiceQualifier_t eServiceQualifier;
 	uint16 uiNumberOfSegments;
 	float32 fSegmentApertureAngle;
 	float32 fOverheadClearance;
 	aSegmentArray_array_t aSegmentArray;
 	uint32 uiFanDebugInfo;
 } FsdFanModelData_t;			/* Free space description @vaddr:0x30715000 @vaddr_defs: FSD_MEAS_ID_FAN_MODEL_DATA @cycleid:FSD_ENV @vname:FsdFanModelData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	FtrcFeatureState_t eState;
 	uint8 uAge;
 	uint8 uInlierCount;
 	uint8 uSeedId;
 	u16q5_t fpX;
 	u16q5_t fpY;
 	u16q5_t fpFlowDx;
 	u16q5_t fpFlowDy;
 } FtrcFeature_t;			/* Tracked flow feature */

typedef FtrcFeature_t             	FtrcFeatureArray_t[500];/* Tracked flow feature */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	FtrcFeatureArray_t aFeatures;
 } FtrcFeatureList_t;			/* List of tracked flow features @vaddr:0x30B22000 @vaddr_defs: FTRC_MEAS_ID_TARGET_LIST @cycleid:FTRC_ENV @vname:FtrcFeatureList */

typedef bool8                     	FtrcKillFeatureArray_t[500];/* List of tracked flow features to kill. If certain index is set to TRUE, the feature is about to be killed in the next cycle. */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bValid;
 	sint16 iLeft;
 	sint16 iTop;
 	sint16 iRight;
 	sint16 iBottom;
 } FtrcSeedingRoi_t;			/* List of seeding areas in the image for initializing new features */

typedef FtrcSeedingRoi_t          	FtrcSeedingRoiArray_t[40];/* List of seeding areas in the image for initializing new features */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	FtrcSeedingRoiArray_t aSeedingROI;
 	FtrcKillFeatureArray_t aKillFeature;
 } FtrcSeedKillList_t;			/* List of seeding areas and features to be killed in the next cycle comming from an external module */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s16q7_t xEgo;
 	s16q4_t disparityRange;
 	uint8 disparityInliers;
 	uint8 dummyReserved;
 } GenFtrcDepthFeature_t;			/* Depth information extension of a FTRC flow track.
All ego-vehicle coordinates are originated at the center of the front axle, height of the road. */

typedef GenFtrcDepthFeature_t     	GenFtrcDepthFeatureArray_t[500];/* Depth information extension of a FTRC flow track.
All ego-vehicle coordinates are originated at the center of the front axle, height of the road. */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	GenFtrcDepthFeatureArray_t aFeatures;
 } GenFtrcDepthFeatureList_t;			/* Depth information extension for FTRC flow tracks.
All ego-vehicle coordinates are originated at the center of the front axle, height of the road. @vaddr:0x30114000 @vaddr_defs: GEN_MEAS_ID_FTRC_DEPTH_FEATURE_LIST @cycleid:GEN_ENV @vname:GenFtrcDepthFeatureList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s16q4_t fpMeanDu;
 	s16q4_t fpMeanDv;
 	s16q7_t fpX;
 	s16q7_t fpColLength;
 	s16q7_t fpBottomY;
 	s16q7_t fpBottomZ;
 	uint8 uiObjID;
 	u8q7_t fpValidDispRatio;
 	uint8 uiBottomFloxelRow;
 	uint8 uiTopFloxelRow;
 	s16q7_t fpBottomFloxelZrelRoadModel;
 } GenShapeFlowColumn_t;			/* Generic shape and flow information of targets. 
All ego-vehicle coordinates are originated at the center of the front axle, height of the road. */

typedef GenShapeFlowColumn_t      	GenShapeFlowColumnTable_t[850];/* Generic shape and flow information of targets. 
All ego-vehicle coordinates are originated at the center of the front axle, height of the road. */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiObjID;
 	uint8 uiShapeFlowRow;
 	uint8 uiShapeFlowColFirst;
 	uint8 uiShapeFlowColLast;
 	eClusterType_t eClusterType;
 	s16q7_t fpLength;
 	uint8 uiGeometricClusterID;
 } GenTarget_t;			/* Targets list properties */

typedef GenTarget_t               	GenTargetArray_t[80];/* Targets list properties */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	ImageHeader_t sImgHeaderDisparity;
 	ImageHeader_t sImgHeaderFlow;
 	GenShapeFlowColumnTable_t aShapeFlowColumns;
 	GenTargetArray_t aTargets;
 } GenTargetList_t;			/* Generic Targets list properties. 
All ego-vehicle coordinates are originated at the center of the front axle, height of the road. @vaddr:0x30110000 @vaddr_defs: GEN_MEAS_ID_TARGET_LIST @cycleid:GEN_ENV @vname:GenTargetList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bWindowButtonsPressed;
 	bool8 bMirrorButtonsPressed;
 	bool8 bIntLightsButtonsPressed;
 	bool8 bExtLightsButtonsPressed;
 	bool8 bSunRoofButtonsPressed;
 	bool8 bStWhlButtonsPressed;
 	bool8 bMidConsoleButtonsPressed;
 	bool8 bRadioButtonsPressed;
 	bool8 bOtherButtonsPressed;
 } t_HMI_Buttons;			/* HMI Buttons pressed signals */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	t_HMI_Buttons s_HMI_Buttons;
 } t_HMI_DynamicOnly;			/* HMI signals which can be dynamically changed, not relevant for NVM */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	t_HMI_On_Off_Switch_t FCT_EBA_VEH_Enable;
 	t_HMI_On_Off_Switch_t FCT_EBA_PED_Enable;
 	t_HMI_On_Off_Switch_t FCT_EBA_NOCLASS_Enable;
 	t_HMI_On_Off_Switch_t FCT_ALDW_Enable;
 	t_HMI_Warning_Levels_t FCT_EBA_VEH_SensitivityLevel;
 	t_HMI_Warning_Levels_t FCT_EBA_PED_SensitivityLevel;
 	t_HMI_Warning_Levels_t FCT_EBA_NOCLASS_SensitivityLevel;
 	t_HMI_Warning_Levels_t FCT_ALDW_SensitivityLevel;
 	t_HMI_On_Off_Switch_t FCT_LDP_Enable;
 } t_HMI_NVMRelevant;			/* HMI signals which can be dynamically changed, but relevant for NVM */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t s_VersionNumber;
 	SignalHeader_t s_Header;
 	t_HMI_DynamicOnly s_HMI_DynamicOnly;
 	t_HMI_NVMRelevant s_HMI_NVMRelevant;
 } t_HMI_Data_t;			/* HMI structure (from MCU to SoC) @vaddr:0x83000000 @vaddr_defs: HMI_MEAS_ID_INPUT_DATA @cycleid:HMI_ENV @vname:HMIInputData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fTTSEmergency;
 	float32 fTTSEmergencyStd;
 } HypoIntfCustom_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fMaxDistALN;
 	float32 fMaxDistHRZ;
 	float32 fMaxDistVIS;
 	float32 fMaxDist;
 } HypoIntfDegrPerf_t;			/* Performance Function Degradation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fMaxDistALN;
 	float32 fMaxDistHRZ;
 	float32 fMaxDistVIS;
 	float32 fMaxDist;
 } HypoIntfDegrSfty_t;			/* Safety Function Degradation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	HypoIntfDegrSfty_t Safety;
 	HypoIntfDegrPerf_t Performance;
 } HypoIntfDegr_t;			/* Function Degradation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiNumOfHypotheses;
 	uint8 uiPaddingByte;
 } HypoIntfHeader_t;			/* Object list properties */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ObjNumber_t uiObjectRef;
 	eCDHypothesisType_t eType;
 	uint8 uiObjectProbability;
 	eEBAObjectClass_t eEBAObjectClass;
 	uint8 uiHypothesisProbability;
 	float32 fHypothesisLifetime;
 	float32 fTTC;
 	float32 fTTCStd;
 	float32 fTTC2;
 	float32 fTTC2Std;
 	float32 fTTC3;
 	float32 fTTC3Std;
 	float32 fTTC4;
 	float32 fTTC4Std;
 	float32 fTTBPre;
 	float32 fTTBPreStd;
 	float32 fTTBAcute;
 	float32 fTTBAcuteStd;
 	float32 fTTSPre;
 	float32 fTTSPreStd;
 	float32 fTTSAcute;
 	float32 fTTSAcuteStd;
 	float32 fLongNecAccel;
 	float32 fLongNecAccelStd;
 	float32 fLatNecAccel;
 	float32 fLatNecAccelStd;
 	float32 fDistX;
 	float32 fDistXStd;
 	float32 fVrelX;
 	float32 fVrelXStd;
 	float32 fArelX;
 	float32 fArelXStd;
 	float32 fDistY;
 	float32 fDistYStd;
 	float32 fVrelY;
 	float32 fVrelYStd;
 	float32 fArelY;
 	float32 fArelYStd;
 	float32 fClosingVelocity;
 	float32 fClosingVelocityStd;
 	float32 fTTSPreLeft;
 	float32 fTTSPreLeftStd;
 	float32 fTTSPreRight;
 	float32 fTTSPreRightStd;
 	float32 fTTSAcuteLeft;
 	float32 fTTSAcuteLeftStd;
 	float32 fTTSAcuteRight;
 	float32 fTTSAcuteRightStd;
 	HypoIntfCustom_t Custom;
 } Hypothesis_t;			/* ContiGuard Hypothesis */

typedef Hypothesis_t              	Hypothesis_array_t[12];/* ContiGuard Hypothesis */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	HypoIntfHeader_t Header;
 	HypoIntfDegr_t Degradation;
 	Hypothesis_array_t Hypothesis;
 } HypothesisIntf_t;			/* EBA Hypothesis interface @vaddr:0x202C9100 @vaddr_defs: FCT_MEAS_ID_SEN_HYPO_OUT @cycleid:FCT_ENV @vname:pFCTCDHypotheses */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ui16_Width;
 	uint16 ui16_Height;
 } IcImagerSize_t;			/* Size of the Imager */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ui16_X;
 	uint16 ui16_Y;
 	uint16 ui16_Width;
 	uint16 ui16_Height;
 } IcRect_t;			/* Cropped ROI (on imager pixel array) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f32_BrightnessR;
 	float32 f32_BrightnessG;
 	float32 f32_BrightnessB;
 	uint16 ui16_GrayValue;
 } ImagerRespCurvePt_t;			/* Imager Response curve support point */

typedef ImagerRespCurvePt_t       	s_ResponseCurve_array_t[5];/* Imager Response curve support point */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	IcImagerSize_t s_ImagerSize;
 	IcRect_t s_ImagerCroi;
 	s_ResponseCurve_array_t s_ResponseCurve;
 	float32 f32_NoiseStdDev;
 	float32 f32_ActualSlopeR1;
 	float32 f32_ActualSlopeR2;
 	float32 f32_ExpTimeTotal;
 	float32 f32_ExpTimeT1;
 	float32 f32_ExpTimeT2;
 	float32 f32_ExpTimeT3;
 	float32 f32_LineTimeDt;
 	float32 f32_ImagerPixSize;
 	float32 f32_ImagerGainTotal;
 	uint16 ui16_RequestedSlopeR1;
 	uint16 ui16_RequestedSlopeR2;
 	uint16 ui16_BlackLevel;
 	uint16 ui16_ResponseCurveLen;
 	e_DcgState_t e_DcgState;
 	e_FrameType_t e_FrameType;
 	e_IntradayState_t e_IntradayState;
 	e_ImagerCFA_t e_ImagerCFA;
 } IcImageCharacteristics_t;			/* Image control Image Characteristics @vaddr:0x30010000, 0x30010200 @vaddr_defs: IC_MEAS_ID_IMAGE_CHARACTERISTICS_ODD_RIGHT,IC_MEAS_ID_IMAGE_CHARACTERISTICS_EVEN_RIGHT @cycleid:IC_ENV,IC_ENV @vname:IcImageCharacteristicsOddRight,IcImageCharacteristicsEvenRight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 f32_Brightness;
 	float32 f32_BrightnessWeighted;
 	uint32 ui32_MeanGvLin;
 	uint32 ui32_MeanGvLinWeighted;
 	uint16 ui16_MeanGvComp;
 	uint16 ui16_MeanGvWeightedComp;
 } IcStatisticalResults_t;			/* Image control Statistic Results @vaddr:0x30010100, 0x30010300 @vaddr_defs: IC_MEAS_ID_IMAGE_STATISTIC_ODD_RIGHT,IC_MEAS_ID_IMAGE_STATISTIC_EVEN_RIGHT @cycleid:IC_ENV,IC_ENV @vname:IcImageStatisticOddRight,IcImageStatisticEvenRight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	ImageHeader_t sImgHeader;
 	const  uint16 *   aImageData;
} ImageU16_t;			/* General data type for image data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	ImageHeader_t sImgHeader;
 	const  uint8 *   aImageData;
} ImageU8_t;			/* General data type for image data */

typedef float32                   	afMarkerDashLength_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	afMarkerDashVoidPhase_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	afMarkerHeights_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	afMarkerPositions_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	afMarkerVoidLength_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	afMarkerWidths_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	afModelResiduum_array_t[10];			/* [Satisfies_rte sws 1189] */

typedef aiMarkerColors_t          	aiMarkerColors_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef aiMarkerTypes_t           	aiMarkerTypes_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef sint32                    	aiTrackId_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 CS_MULTIPLE_MARKER;
 	sint32 CS_LEFT_BARRIER;
 	sint32 CS_RIGHT_BARRIER;
 	sint32 CS_CROSSING_MARKER;
 	sint32 CS_INHIBIT_SINGLE_LINE;
 	sint32 CS_HOLD;
 } sConstructionSite_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eEventType_t eEventType;
 	float32 fEventDist;
 	sint32 iEventQuality;
 	sint32 iMergeSplitToTrackId;
 } sEvent_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 iAvailable;
 	uint32 uiQuality;
 	float32 fDistance;
 	float32 fDistanceStdDev;
 	float32 fCurvature;
 	float32 fCurvatureStdDev;
 	float32 fCurvatureRate;
 	float32 fCurvatureRateStdDev;
 	float32 fSegmentDistFar;
 	float32 fYaw;
 	float32 fYawStdDev;
 	float32 fCurvatureFar;
 	float32 fCurvatureFarStdDev;
 	float32 fCurvatureRateFar;
 	float32 fCurvatureRateFarStdDev;
 	float32 fMarkerHeight;
 	float32 fMarkerHeightStdDev;
 	float32 fVerticalCurvature;
 	float32 fVerticalCurvatureStdDev;
 	float32 fVerticalCurvatureRate;
 	float32 fVerticalCurvatureRateStdDev;
 	float32 fVerticalPitch;
 	float32 fVerticalPitchStdDev;
 	float32 fLookaheadDistance;
 	afModelResiduum_array_t afModelResiduum;
 	sint32 iNumberOfMarkers;
 	aiMarkerTypes_array_t aiMarkerTypes;
 	aiMarkerColors_array_t aiMarkerColors;
 	afMarkerPositions_array_t afMarkerPositions;
 	afMarkerWidths_array_t afMarkerWidths;
 	afMarkerDashLength_array_t afMarkerDashLength;
 	afMarkerVoidLength_array_t afMarkerVoidLength;
 	afMarkerDashVoidPhase_array_t afMarkerDashVoidPhase;
 	afMarkerHeights_array_t afMarkerHeights;
 	aiTrackId_array_t aiTrackId;
 } sMarker_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	sMarker_t sLeftMarker;
 	sMarker_t sRightMarker;
 	sMarker_t sLeftAdjacentMarker;
 	sMarker_t sRightAdjacentMarker;
 	sMarker_t sLeftMarkerRear;
 	sMarker_t sRightMarkerRear;
 	sMarker_t sRightAdjacentMarkerRear;
 	sMarker_t sLeftAdjacentMarkerRear;
 	sEvent_t sLeftEvent;
 	sEvent_t sRightEvent;
 	sEvent_t sLeftAdjacentEvent;
 	sEvent_t sRightAdjacentEvent;
 	float32 fPitchAngleOnline;
 	float32 fRollAngleOnline;
 	sint32 iACSaveRequest;
 	sint32 iACPercentage;
 	eCoordinateSystem_t eCoordinateSystem;
 	eParallelModel_t eParallelModel;
 	sint32 iCameraMisaligned;
 	sint32 iACNotFinished;
 	sConstructionSite_t sConstructionSite;
 	sint32 iLaneChange;
 	sint32 iSmoothOperation;
 	eSteeringSide_t eSteeringSide;
 	sint32 iIndexEgoLane;
 	sint32 iNumberOfLanes;
 	sint32 uiOverallConfidence;
 	uint32 uiImageFingerPrint;
 	sint32 iVersionMajor;
 	sint32 iVersionMinor;
 	sint32 iVersionPatch;
 } LdOutputData_t;			/* Control data for the Ld module @vaddr:0x30E10000 @vaddr_defs: LD_MEAS_ID_OUTPUT_DATA @cycleid:LD_ENV @vname:LDLaneData */

typedef uint32                    	u_Reserved_Fields_array_t_0[7];/* Reserved for urgent cases if interface change in release not possible anymore */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint32 u_SynchTimeStampL;
 	uint32 u_SynchTimeStampH;
 	uint32 u_ACTLModeRequested;
 	u_Reserved_Fields_array_t_0 u_Reserved_Fields;
 } t_MCUSystemData_t;			/* Control Data from MCU to SoC @vaddr:0x83001000 @vaddr_defs: MEAS_ID_SYSDATA_MCU @cycleid:MEAS_CYCID_SYSDATA_MCU @vname:SYSDATA_MCU */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint32 u_SynchTimeStampL;
 	uint32 u_SynchTimeStampH;
 } t_MCUTimeStamp_t;			/* Time Stamp for time synchornization from MCU to SoC @vaddr:0x83004000 @vaddr_defs: MEAS_ID_TIMESTAMP_MCU @cycleid:MEAS_CYCID_TIMESTAMP_MCU @vname:TIMESTAMP_MCU */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiSize;
 	  uint8 *   pBuffer;
} Buffer_t;			/* Buffer specification including pointer and size in bytes */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	ImageHeader_t sImgHeader;
 	ParameterID_t uiParameterId;
 	AlgoSignalState_t eValid;
 	aLutData_array_t aLutData;
 } SacRteLut_t;			/* Look-up-table used for image rectification */

typedef float32                   	fDistortionCoefficients_array_t[10];/* Bouguet distortion model (radial: k0 k1 k4, tangential: k2 k3, currently unused: k5-k9)
Unused coefficients are to be set to 0. */	/* [Satisfies_rte sws 1189] */

typedef float32                   	fRectificationCoefficients_array_t[2];/* Inverse radial distortion (k0: px^2, k1: px^4)
Unused coefficients are to be set to 0. */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fFocalX;
 	float32 fFocalY;
 	float32 fCenterX;
 	float32 fCenterY;
 	fDistortionCoefficients_array_t fDistortionCoefficients;
 	fRectificationCoefficients_array_t fRectificationCoefficients;
 } MonoCalibrationIntrinsic_t;			/* intrinsic camera parameters */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 uiX;
 	uint16 uiY;
 	uint16 uiWidth;
 	uint16 uiHeight;
 } MonoCalibrationReducedRoi_t;			/* Reduced Roi (wrt. cropped roi) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	ParameterID_t uiParameterId;
 	MonoCalibrationIntrinsic_t IntrinsicPhysical;
 	PoseParameters_t sPoseEcm;
 	MonoCalibrationReducedRoi_t sReducedRoi;
 } MonoCalibrationEol_t;			/* Monocular End-of-line calibration supplied by ECM */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	ParameterID_t uiParameterId;
 	MonoCalibrationIntrinsic_t IntrinsicSROIRectified;
 	PoseParameters_t sPoseDeltaRectified;
 } MonoCalibrationRectification_t;			/* Monocular calibration parameters of the rectified camera */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 uiX;
 	uint16 uiY;
 	uint16 uiWidth;
 	uint16 uiHeight;
 } MonoCalibrationFreeFOV_t;			/* Free image area of the camera which is not covered by the engine hood, bracket or straylight cover.
The area is defined with respect to the provided roi (IMAGER, CROI, RROI, SROI). */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	ParameterID_t uiParameterId;
 	eMonoCalibrationSide_t eSide;
 	eMonoCalibrationCameraType_t eCameraType;
 	MonoCalibrationIntrinsic_t sIntrinsic;
 	PoseParameters_t sPoseCalibration;
 	PoseParameters_t sPoseDynamic;
 	eMonoCalibrationVerificationStatus_t eVerificationStatus;
 	MonoCalibrationFreeFOV_t sFreeFOV;
 } MonoCalibration_t;			/* Output data of monocular calibration */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint32 u_AlgoConfig_Mono;
 	uint32 u_AlgoConfig_Stereo;
 	uint32 u_LabMode;
 } t_NVMConfigECUSW_t;			/* ECU Frame SW Config @vaddr:0x83003000 @vaddr_defs: MEAS_ID_NVM_CONFIG_ECUSW @cycleid:MEAS_CYCID_NVM_CONFIG_ECUSW @vname:NVM_CONFIG_ECUSW */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fX;
 	float32 fY;
 	float32 fZ;
 } EcmRteSensorSocket_t;			/* definition of the target extraction */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	AlgoCompState_t sCompState;
 	EcmRteSensorAngles_t sSensorAnglesEol;
 	EcmRteSensorSocket_t sEcmRteSensorSocketEol;
 	PoseParameters_t sPoseCalibration;
 } NVM_EcmRte_t;			/* @vaddr:0x30F12500 @vaddr_defs: ECM_RTE_MEAS_ID_OUT_NVM @cycleid:ECM_ENV @vname:pNvmEcmRteOut */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fCaliDeltaRoll;
 	float32 fCaliDeltaPitch;
 	float32 fCaliDeltaYaw;
 	float32 fCaliDeltaHeight;
 	uint8 isRollCalibrated;
 	uint8 isPitchCalibrated;
 	uint8 isYawCalibrated;
 	uint8 isHeightCalibrated;
 	float32 fCaliTimer;
 	float32 fCaliOdometer;
 } NVM_Emo_t;			/* Egomotion interface to NVM @vaddr:0x30B17000 @vaddr_defs: EMO_MEAS_ID_EMO_TO_NVM @cycleid:EMO_ENV @vname:pNVM_EmoToNvm */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 xPos;
 	uint16 yPos;
 	RTE_HLAR_DefectPixelType DefectType;
 	uint16 Count;
 } RTE_HLAR_DefectPixel_t;			/* Detected defect pixel list. Stored in NVM. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Pitch;
 	float32 Yaw;
 	float32 Roll;
 	float32 OdoCali_m;
 } RTE_HLAR_CaliOnline_t;			/* HLA online calibration. Stored in NVM. */

typedef RTE_HLAR_DefectPixel_t    	DefectList_array_t[90];/* defect pixel list */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 DefectsListLength;
 	DefectList_array_t DefectList;
 } RTE_HLAR_DefectPixelList_t;			/* Detected defect pixel list. Stored in NVM. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLA_TrafficStyle LastLearned;
 	RTE_HLAR_TrafficStyleLearningState LearningState;
 } RTE_HLAR_TrafficStyleData_t;			/* Learned traffic style. Stored in NVM. */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLAR_TrafficStyleData_t TrafficStyle;
 	RTE_HLAR_CaliOnline_t CaliOnline;
 	RTE_HLAR_DefectPixelList_t DefectPixel;
 } NVM_HLAR_LearningValues_t;			/* HLAR Learning values (stored in NVM) @vaddr:0x31212800 @vaddr_defs: RTE_HLA_MEAS_VADDR_NVM_LEARN_VALUES_OUT @cycleid:HLA_ENV @vname:RTE_NVM_HLAR_LearningValues */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fPitchAngleAC;
 	sint32 iPitchACStage;
 	float32 fRollAngleAC;
 	sint32 iRollACStage;
 	float32 fCamYawAngleAC;
 	sint32 iCamYawACStage;
 } NVM_LdOnlineCaliData_t;			/* Control data for the Ld module @vaddr:0x30E20000 @vaddr_defs: LD_MEAS_ID_ONLINE_CALI_DATA @cycleid:LD_ENV @vname:NVM_LdOnlineCaliData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 StereoFilterWidth;
 	float32 StereoColumnStep;
 	float32 StereoDispSearchRange;
 	RtePvProcessingMode_t PvProcessingMode;
 } NVM_PvData_t;			/* Preview init data @vaddr:0x30800020 @vaddr_defs: PV_MEAS_ID_NVM_DATA @cycleid:PV_ENV @vname:NVM_PvData */

typedef uint8                     	NVM_SR_RTE_PersStateFPAbst_array_t[80];/* memory is stored at ignition off and keeps values even when a new SW version is flahsed (CRC32 checked) */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	NVM_SR_RTE_PersStateFVAbst_array_t[28];/* memory is stored at ignition off and is erased when a new SW version is flahsed (CRC32 checked) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	NVM_SR_RTE_PersStateFPAbst_array_t NVM_SR_RTE_PersStateFPAbst;
 	NVM_SR_RTE_PersStateFVAbst_array_t NVM_SR_RTE_PersStateFVAbst;
 } NVM_SR_RTE_PersistentStateAbstract_t;			/* memory for persistant state information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	NVM_SR_RTE_PersistentStateAbstract_t NVM_SR_RTE_PersistentStateAbstract;
 } NVM_SR_RTE_t;			/* nvm @vaddr:0x30D80000 @vaddr_defs: NVM_SR_RTE_MEAS_ID @cycleid:SR_ENV_B @vname:NVM_SR_RTE */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	PoseParameters_t sPoseCalibration;
 	PoseParameters_t sPoseDynamic;
 	eMonoCalibrationVerificationStatus_t eVerificationStatus;
 } SacRteNvmExtrinsicCalibrationLastResult_t;			/* Last extrinsic autocalibration and dynamic pose received */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	SignalHeader_t sSignalHeader;
 	SacRteNvAngleLearnTable_t sRollAngleNvData;
 	SacRteNvAngleLearnTable_t sPitchAngleNvData;
 	SacRteNvAngleLearnTable_t sYawAngleNvData;
 } SacRteNvmNvAngleData_t;			/* Learned temperature table from NVM */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fA00;
 	float32 fA10;
 	float32 fA20;
 	float32 fA01;
 	float32 fA11;
 	float32 fA21;
 	float32 fA02;
 	float32 fA12;
 	float32 fA22;
 } Mat3x3_t;			/* 3x3 matrix type (1st index = row, 2nd index = column) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	Mat3x3_t sR_left_right;
 	float32 fTx;
 	float32 fTy;
 	float32 fTz;
 } SacRteNvmStereoCalibrationState_t;			/* Last stereo-autocalibration state */

typedef uint8                     	aTsaRtePersStateFP[128];/* flash persistent memory */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	aTsaRtePersStateFV[96];/* flash volatile memory */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	aTsaRtePersStateFP persStateFPdata;
 	aTsaRtePersStateFV persStateFVdata;
 } TsaRtePersistentState_t;			/* persistent memory */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	TsaRtePersistentState_t persState;
 } NvmTsaRteState_t;			/* persitent state data @vaddr:0x20044500 @vaddr_defs: TSA_RTE_MEAS_ID_NVM_STATE @cycleid:TSA_ENV @vname:TsaRteNvmState */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	PcOpMode_t eOpMode;
 } PcBSWCtrlData_t;			/* Control data for the PC module @vaddr:0x30300000 @vaddr_defs: PC_MEAS_ID_CTRL_BSW_DATA @cycleid:PC_ENV @vname:PcBSWCtrlData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiID;
 	eDimensionality_t eDimensionality;
 	eReconstruct_Intensity_t eReconstruct_Intensity;
 	eReconstruct_Scale_t eReconstruct_Scale;
 	eMaskingOut_t eMaskingOut;
 	uint16 uiLowerLeftCornerPosHorizontal;
 	uint16 uiLowerLeftCornerPosVertical;
 	uint16 uiWidth;
 	uint16 uiHeight;
 	float32 fInitialShift_X;
 	float32 fInitialShift_Y;
 	uint8 uiSearchRangeHorizontal;
 	uint8 uiSearchRangeVertical;
 	sint8 siSearchRangeDisparity;
 	float32 fInitialScale;
 	float32 fInitialBias;
 	float32 fInitialGain;
 } PcInputPatch_t;			/* Array with patch information */

typedef PcInputPatch_t            	aPatchArray_array_t[100];/* array containing patch responses */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	aPatchArray_array_t aPatchArray;
 	uint8 uiValidPatches;
 } PcInputData_t;			/* Stereo patch correlator input data containing requested patch details @vaddr:0x30310000 @vaddr_defs: PC_MEAS_ID_INPUTDATA @cycleid:PC_ENV @vname:PCInputList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uiID;
 	eValidity_t eValidity;
 	float32 fShift_x;
 	float32 fShift_y;
 	float32 fPositionQuality;
 	float32 fMatchingQuality;
 	float32 fBias;
 	float32 fGain;
 	float32 fScale;
 } PcOutputPatch_t;			/* Array with patch information */

typedef PcOutputPatch_t           	aPatchArray_array_t_0[100];/* array containing patch responses */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	aPatchArray_array_t_0 aPatchArray;
 } PcOutputData_t;			/* Stereo patch correlator output data containing requested patch details @vaddr:0x303000D4 @vaddr_defs: PC_MEAS_ID_OUTPUTDATA @cycleid:PC_ENV @vname:PCOutputList */

typedef ObjNumber_t               	aReferenceObjects_array_t[10];/* list of reference object ids in the object list for this pedestrian hypothesis */	/* [Satisfies_rte sws 1189] */

typedef float32                   	fClassProbability_array_t[4];/* real probability based on classifier test set that this box is really on the right object class @min:0 @max:1 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fTopLeftXpx;
 	float32 fTopLeftYpx;
 	float32 fBottomRightXpx;
 	float32 fBottomRightYpx;
 	float32 fStdDevXpx;
 	float32 fStdDevYpx;
 	float32 fStdDevHeightpx;
 	float32 fQualityHOG;
 	float32 fQualityLRF;
 	float32 fQualityLRFDisparity;
 	fClassProbability_array_t fClassProbability;
 	sint32 sNrOfReferenceObjects;
 	aReferenceObjects_array_t aReferenceObjects;
 } ClassifiedBox_t;			/* ClassifiedBox */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	sint32 sIdx;
 	ClassifiedBox_t ClassifiedBox;
 } Pedestrian_t;			/* Information for each pedestrian */

typedef Pedestrian_t              	Pedestrian_array_t[15];/* Information for each pedestrian */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t Header;
 	uint32 uErrorCode;
 	sint32 sNrOfRelevantPedestrians;
 	Pedestrian_array_t Pedestrian;
 } PedClusteredPedestrians_t;			/* Single Frame Pedestrian Hypotheses @vaddr:0x30210000 @vaddr_defs: PED_MEAS_ID_CLUSTERED_PEDESTRIANS @cycleid:PED_ENV @vname:PedClusteredPedestrians */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fTopLeftXpx;
 	float32 fTopLeftYpx;
 	float32 fBottomRightXpx;
 	float32 fBottomRightYpx;
 	float32 fStdDevXpx;
 	float32 fStdDevYpx;
 	float32 fStdDevHeightpx;
 	float32 fMatchingQuality;
 	float32 fObjFlowValidationQuality;
 	float32 fObjFlowValidationConfidence;
 	sint16 sEMTrackIdx;
 } ImageTrackedBox_t;			/* Matching box of the image tracker */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	ImageTrackedBox_t ImageTrackedBox;
 } ImageTrackedPedestrian_t;			/* Information for each pedestrian */

typedef ImageTrackedPedestrian_t  	ImageTrackedPedestrian_array_t[15];/* Information for each pedestrian */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t Header;
 	uint32 uErrorCode;
 	sint32 sNrOfRelevantPedestrians;
 	ImageTrackedPedestrian_array_t ImageTrackedPedestrian;
 } PedImageTrackedPedestrians_t;			/* tracked pedestrian boxes  in the image (from t-1 --> t) @vaddr:0x30215000 @vaddr_defs: PED_MEAS_ID_IMGTRACKED_PEDESTRIANS @cycleid:PED_ENV @vname:PedImageTrackedPedestrians */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fTemperature;
 	SacRteStatistics_t sStatistics;
 	SacRteNvmStereoCalibrationState_t sStereoCalibrationState;
 	SacRteNvmExtrinsicCalibrationLastResult_t sExtrinsicCalibrationLastResult;
 	SacRteNvmNvAngleData_t sNvAngleData;
 } NVM_SacRte_t;			/* NVM private exchange structure for SAC @vaddr:0x30911400 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_NVM @cycleid:SAC_ENV @vname:pNvmSacOut */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	ParameterID_t uiParameterId;
 	float32 fBaseline;
 	PoseParameters_t sT_left_right;
 	SacRteWindshieldModelCoefficients_t aWindshieldModelCoefficients;
 	SacRteBoundingBox_t sBoundingBoxRight;
 	SacRteBoundingBox_t sBoundingBoxLeft;
 } SacRteStereoCalibration_t;			/* Binocular calibration data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	Vector2_f32_t LeftCircle;
 	Vector2_f32_t RightCircle;
 } EcmRteTargetExtraction_t;			/* definition of the target extraction */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	PvOpMode_t eOpMode;
 } PvBSWCtrlData_t;			/* Control data for the PV module */

typedef RTE_HLAF_DimmingLevel     	DimmingArea_array_t[5];/* List which holds the dimming areas */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
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
 	RTE_HLAF_ObjStatus BndryLeft_Status;
 	RTE_HLAF_ObjStatus BndryRight_Status;
 	RTE_HLAF_ObjStatus BndryLower_Status;
 	RTE_HLAF_ObjStatus ClosestObj_Status;
 	RTE_HLAF_ObjStatus MinLight_Status;
 	RTE_HLAF_TTBStatus ttb18Left_Status;
 	RTE_HLAF_TTBStatus ttb18Right_Status;
 	uint8 ExistenceProb;
 } RTE_HLAF_MatrixGFA_t;			

typedef RTE_HLAF_MatrixGFA_t      	LightAreas_array_t[5];/* BMW specific light areas */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 BndryLeft_Ang_Cam;
 	float32 BndryRight_Ang_Cam;
 	float32 BndryLower_Ang_Cam;
 	RTE_HLAF_LightOutput LightOutput;
 } RTE_HLAF_DimmingArea_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLAF_EcoLight_eAvailabilityState AvailabilityState;
 	RTE_HLAF_EcoLight_eDetectionState DetectionState;
 	float32 ObjectDist;
 	RTE_HLAF_EcoLight_eVehicleType ObjectType;
 	RTE_HLAF_EcoLight_eVehicleLight ObjectLightState;
 } RTE_HLAF_EcoLight_t;			/* HLA EcoLight control data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLA_TrafficStyle TrafficStyle;
 	RTE_HLAR_CityState CityState;
 	RTE_HLAR_WeatherState WeatherState;
 	RTE_HLAR_Tunnel TunnelState;
 	RTE_HLAF_MotorwayState MotorwayState;
 	RTE_HLAR_BrightnessState BrightnessState;
 	RTE_HLA_SensMode SensMode;
 	RTE_HLAF_SpeedState SpeedState;
 } RTE_HLAF_HeadlightControl_Common_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLAF_DimmingStatus DimmingStatus;
 	uint8 Padding;
 	DimmingArea_array_t DimmingArea;
 } RTE_HLAF_LightDimming_t;			/* HLA light dim down area signals (for bright reflecting areas) */

typedef RTE_HLAF_MatrixGFA_t      	GFA_array_t[5];/* glare free area list */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	GFA_array_t GFA;
 	LightAreas_array_t LightAreas;
 	uint32 nGFA;
 	uint32 nLightAreas;
 	RTE_HLAF_SignalStatus GFAStatus;
 	RTE_HLAF_HighBeamState HighBeamState;
 	float32 LowBeam_Dist;
 	float32 LowBeam_Ang;
 	RTE_HLAF_ObjStatus LowBeam_Status;
 	RTE_HLAF_MatrixTurnOffReason TurnOffReason;
 } RTE_HLAF_Matrix_t;			/* HLA Matrix beam signals (glare free areas (GFA)) */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLA_State State;
 	RTE_HLA_Type Type;
 	RTE_HLAF_HeadlightControl_Common_t Common;
 	RTE_HLAF_Matrix_t Matrix;
 	RTE_HLAF_LightDimming_t Dimming;
 	RTE_HLAF_EcoLight_t EcoLight;
 } RTE_HLAF_HeadlightControl_t;			/* Headlight Control data @vaddr:0x31213000 @vaddr_defs: RTE_HLA_MEAS_VADDR_HEADLIGHT_CTRL @cycleid:HLA_ENV @vname:RTE_HLAF_HeadlightControl */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 ID;
 	RTE_HLAF_NightViewObjectType ObjType;
 	RTE_HLAF_NightViewSpot e_Spot;
 	float32 Distance;
 	float32 HorAng;
 } RTE_HLAF_NightViewObject_t;			/* Night view object data */

typedef RTE_HLAF_NightViewObject_t 	Obj_array_t[2];/* night view object list */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	Obj_array_t Obj;
 } RTE_HLAF_NightView_t;			/* Night view object list */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLAR_HighwayLatPosState LateralPosition;
 	RTE_HLAR_HighwayEgoMotionState EgoMotion;
 	RTE_HLAR_eHighwayOcclusionState Occlusion;
 	RTE_HLAR_eHighwaySpeedDetectionState SpeedDetection;
 	float32 ConfLateralPosition;
 	float32 ConfEgoMotion;
 	float32 ConfOcclusion;
 } RTE_HLAR_Highway_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLAR_BrightnessState Brightness;
 	RTE_HLAR_CityState City;
 	RTE_HLA_TrafficStyle TrafficStyle;
 	RTE_HLAR_TrafficStyleState TrafficStyleState;
 	RTE_HLAR_Tunnel Tunnel;
 	RTE_HLAR_Highway_t Highway;
 	RTE_HLAR_WeatherState Weather;
 	RTE_HLAR_RedReflectorArea RedReflectorArea;
 } RTE_HLAR_EnvironmentData_t;			/* @vaddr:0x31212000 @vaddr_defs: RTE_HLA_MEAS_VADDR_ENV_DATA @cycleid:HLA_ENV @vname:RTE_HLAR_EnvironmentData */

typedef uint8                     	Dummy3_array_t[7];/* Dummy bytes (just for alignment) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 distMin_cm;
 	uint16 distMax_cm;
 } RTE_HLAR_ObjectDistance_t;			/* object distance */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	RTE_HLAR_ObjectIconStatus status;
 	uint8 classCnt;
 	uint8 Dummy;
 	sint16 classResultSum;
 } RTE_HLAR_ObjectIconState_t;			/* icon classification result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 X;
 	uint16 Y;
 } RTE_HLAR_ObjectFOE_t;			/* Focus of expansion in absolute imager coordinates */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 Id;
 	uint8 IdPairLight;
 	uint8 lost_time;
 	uint8 Light_Id;
 	uint16 trace_time;
 	uint16 blind_time;
 	sint16 xcenter;
 	sint16 ycenter;
 	sint16 delta_x;
 	sint16 delta_y;
 	sint16 delta_x_lp;
 	sint16 delta_y_lp;
 	RTE_HLAR_ObjectStatus Status;
 	uint16 Intensity_lux;
 	uint16 Dummy1;
 	uint16 ttb18Left_ms;
 	uint16 ttb18Right_ms;
 	sint16 xcenter_FD;
 	sint16 ycenter_FD;
 	RTE_HLAR_ObjectDistance_t LightDist;
 	RTE_HLAR_ObjectDistance_t ObjectPos_xw;
 	float32 ObjectHorAng;
 	sint16 ObjectPos_yw_cm;
 	sint16 ObjectPos_zw_cm;
 	RTE_HLAR_ObjectIconState_t IconState;
 	uint8 ExistenceProb;
 	Dummy3_array_t Dummy3;
 } RTE_HLAR_Object_t;			/* object list members */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 RoiX1;
 	uint16 RoiX2;
 	uint16 RoiY1;
 	uint16 RoiY2;
 	uint16 RoiYu;
 } RTE_HLAR_ObjectRoi_t;			/* absolute imager position of the HlaRoi = FunctionRoi + AboveRoi */

typedef RTE_HLAR_Object_t         	Object_array_t[35];/* object list */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLAR_ObjectRoi_t ObjectRoi;
 	RTE_HLAR_ObjectFOE_t ObjectFOE;
 	uint32 NumVehicles;
 	uint32 NumObjects;
 	Object_array_t Object;
 } RTE_HLAR_ObjectList_t;			/* Object list @vaddr:0x31210100 @vaddr_defs: RTE_HLA_MEAS_VADDR_OBJECT_LIST @cycleid:HLA_ENV @vname:RTE_HLAR_ObjectList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 PartHBCutOffAng_Lt;
 	float32 PartHBCutOffAng_Rt;
 	float32 HorCutOffAng;
 	float32 LightDistance;
 	RTE_HLA_CutOffLineState LightDistanceStatus;
 	RTE_HLA_CutOffLineState HorCutOffAngStatus;
 	RTE_HLA_LightStyle LightStyle_Lt;
 	RTE_HLA_LightStyle LightStyle_Rt;
 } RTE_HLA_MatrixGFAState_t;			/* glare free area state, reported from headlamps */

typedef RTE_HLA_MatrixGFAState_t  	GFA_array_t_0[5];/* mandatory input signal, glare free area list */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLA_LightModuleState LightModuleState;
 	GFA_array_t_0 GFA;
 	uint32 nGFA;
 	float32 CurveLightRotAng_Lt;
 	float32 CurveLightRotAng_Rt;
 	RTE_HLA_GlareReductionState GlareReductionState;
 	float32 LightOutput;
 } RTE_HLA_HeadlightState_t;			/* Headlight state, reported from headlamps @vaddr:0x31201800 @vaddr_defs: RTE_HLA_MEAS_VADDR_HEADLIGHT_STATE @cycleid:IPC_ENV @vname:RTE_HLA_HeadlightState */

typedef float32                   	Level_lux_array_t[8];/* region levels in Lux */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 Light_Id;
 	uint8 Region_Id;
 	uint16 MaxPos_x;
 	uint16 MaxPos_y;
 	uint8 R;
 	uint8 G;
 	uint8 B;
 	RTE_HLA_Seg_LightStatus Status;
 	uint16 MaxInt;
 } RTE_HLA_Seg_Light_t;			/* object list members */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	Level_lux_array_t Level_lux;
 } RTE_HLA_Seg_Level_t;			/* lux level which defines the regions in each level */

typedef RTE_HLA_Seg_Light_t       	Light_array_t[60];/* light list (the light ID is equal to the array index) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 Level;
 	uint8 RegionBelow_Id;
 	uint8 FillFactor;
 	uint8 Dummy;
 	uint16 x1;
 	uint16 y1;
 	uint16 x2;
 	uint16 y2;
 } RTE_HLA_Seg_Region_t;			/* segmentation region position and size */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 X1;
 	uint16 X2;
 	uint16 Y1;
 	uint16 Y2;
 } RTE_HLA_Seg_Roi_t;			/* absolute imager position of the segmentation ROI */

typedef RTE_HLA_Seg_Region_t      	Region_array_t[100];/* region list (the region ID is the equal to the array index) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	RTE_HLA_Seg_Level_t SegLevel;
 	RTE_HLA_Seg_Roi_t SegRoi;
 	uint32 NumLights;
 	Light_array_t Light;
 	Region_array_t Region;
 } RTE_HLA_Seg_LightList_t;			/* Light list @vaddr:0x31214000 @vaddr_defs: RTE_HLA_MEAS_VADDR_SEG_LIGHT_LIST @cycleid:HLA_ENV @vname:RTE_HLA_Seg_LightList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t VersionNumber;
 	SignalHeader_t Header;
 	float32 CycleTime;
 	RTE_HLA_US_Sens USSensitivity;
 	RTE_HLA_State HLAState;
 	RTE_HLA_Type HLAType;
 } RTE_HLA_Signals_t;			/* HLA signals @vaddr:0x31201B00 @vaddr_defs: RTE_HLA_MEAS_VADDR_HLA_SIG @cycleid:IPC_ENV @vname:RTE_HLA_Signals */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoSignalState_t signalState;
 	uint8 day;
 	uint8 month;
 	uint16 year;
 } RteDate_t;			/* date */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoSignalState_t signalState;
 	float32 latit;
 	float32 longit;
 } RteGpsPosition_t;			/* GPS position */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoSignalState_t signalState;
 	uint8 MapAgeInYears;
 	MapProvider_t MapProvider;
 	uint16 CountryCode;
 } RteMapInformation_t;			/* Map Information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoSignalState_t signalState;
 	uint8 hour;
 	uint8 minute;
 	uint8 second;
 } RteTimeOfDay_t;			/* time of day */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	RteDate_t date;
 	RteTimeOfDay_t timeOfDay;
 	RteGpsPosition_t gpsPosition;
 	RteMapInformation_t mapInfo;
 } RteInputGPS_t;			/* GPS input data @vaddr:0x20044100 @vaddr_defs: TSA_RTE_MEAS_ID_INPUT_GPS @cycleid:IPC_ENV @vname:TsaRteInputGPS */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 RelHgt;
 	float32 Qual;
 } RtePvRelProfileVal_t;			/* AbsoluteProfileValue */

typedef RtePvRelProfileVal_t      	RtTrkProfilePoint_array_t[72];/* relative profile values of right track points */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 AbsDist;
 	float32 AbsHgt;
 	float32 Qual;
 } RtePvAbsProfileVal_t;			/* AbsoluteProfileValue */

typedef RtePvRelProfileVal_t      	LtTrkProfilePoint_array_t[72];/* relative profile values of left  track points */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	RtePvTrackingState_t TrackingState;
 	RtePvAbsProfileVal_t LtTrkFirstPoint;
 	RtePvAbsProfileVal_t RtTrkFirstPoint;
 	float32 ShiftDelta_X;
 	float32 ShiftDelta_Y;
 	float32 ShiftDelta_Z;
 	float32 YawAngleDelta;
 	float32 PitchAngleDelta;
 	float32 RollAngleDelta;
 	uint8 NumValidLtTrkProfilePoints;
 	uint8 NumValidRtTrkProfilePoints;
 	LtTrkProfilePoint_array_t LtTrkProfilePoint;
 	RtTrkProfilePoint_array_t RtTrkProfilePoint;
 } RtePVOutputData_t;			/* PreView output data @vaddr:0x30810000 @vaddr_defs: PV_MEAS_ID_OUTPUT_DATA @cycleid:PV_ENV @vname:RtePVOutputData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Value;
 	uint32 TimeStamp;
 	RtePvSignalState_t SignalState;
 	RtePvSignalType_t SignalType;
 } RtePvSensorSignal_t;			/* sensor signal */

typedef RtePvSensorSignal_t       	SensorSignal_array_t[80];/* array of all vehicle signals relevant for this algo cycle */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uint8 NumSensorSignal;
 	SensorSignal_array_t SensorSignal;
 } RtePvVehicleData_t;			/* vehicle data @vaddr:0x30800050 @vaddr_defs: PV_MEAS_ID_VEHICLE_DATA @cycleid:IPC_ENV @vname:RtePvVehicleData */

typedef sint32                    	additionalInfo_array_t[3];/* specific data: for supplementary sign e.g. time, weight, etc. for normal signs track id of gate counterpart */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	classId_t classId;
 	additionalInfo_array_t additionalInfo;
 	float32 recogReliability;
 } SR_RTE_OutputResultClass_t;			/* result(s) for main sign */

typedef SR_RTE_OutputResultClass_t 	aOutputResults[5];/* result(s) for main sign */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 num;
 	aOutputResults results;
 } SR_RTE_OutputResult_t;			/* substruct for alternative sign result classes */

typedef uint8                     	aCommunicationBuffer[1468007];/* abstract communication buffer */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	aCommunicationBuffer bufferAbst;
 } SR_RTE_Communication_Buffer_t;			/* SRMainPart1 and SRMainPart2 communication buffer */

typedef uint8                     	aCurrentNumErrors[4];/* number of errors including input errors */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	trafficStyle_t trafficStyle;
 	speedUnit_t speedUnit;
 	sint32 countryCode;
 } SR_RTE_OutputCountryResults_t;			/* merged results of SR country estimation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 inputImageWidth;
 	uint32 inputImageHeight;
 	uint32 offsetX;
 	uint32 offsetY;
 	uint32 width;
 	uint32 height;
 	float32 pointOfExX;
 	float32 pointOfExY;
 	SR_RTE_Brightness_t brightness;
 } SR_RTE_OutputROIInformation_t;			/* information on the ROI used by SR for recognizing signs */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 id;
 	SR_RTE_OutputResultTrackStatus_t trackStatus;
 	SR_RTE_OutputTrackCharacteristic_t trackCharacteristics;
 	sint32 current;
 	sint32 x;
 	sint32 y;
 	sint32 w;
 	sint32 h;
 	SR_RTE_OutputResult_t mainClass;
 	SR_RTE_OutSignGeometry_t signGeometry;
 	SR_RTE_OutputResult_t supplClass1;
 	SR_RTE_OutSupplSignPosition_t supplPosition1;
 	SR_RTE_OutputResult_t supplClass2;
 	SR_RTE_OutSupplSignPosition_t supplPosition2;
 	float32 worldPosX;
 	float32 worldPosY;
 	float32 worldPosZ;
 	float32 deltaWorldPosX;
 	float32 deltaWorldPosY;
 	float32 deltaWorldPosZ;
 	float32 worldWidth;
 	float32 worldHeight;
 	float32 deltaWorldWidth;
 	float32 threeDQuality;
 	sint32 wholeLength;
 } SR_RTE_OutputResultTrack_t;			/* current results */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 sec;
 	sint32 usec;
 } SR_RTE_OutputTimestamp_t;			/* timestamp of input image for synchronizing SR output data with other input in further components */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 meanFramedroprate;
 	uint32 currentNumErrors;
 	aCurrentNumErrors firstErrors;
 	uint32 totalNumErrors;
 	uint32 resetCounter;
 	SR_RTE_ApplicationControlFlow_t applicationControlFlow;
 } SR_RTE_HealthStatus_t;			/* summary of sr health status */

typedef SR_RTE_OutputResultTrack_t 	aRteOutputTracks[16];/* current results */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uint32 rteWrpVersion;
 	uint32 frameNumber;
 	uint32 numberOfResultTracks;
 	SR_RTE_CalibrationStatus_t calibrationStatus;
 	srStatus_t srStatus;
 	SR_RTE_HealthStatus_t healthStatus;
 	SR_RTE_OutputTimestamp_t frameTimestamp;
 	aRteOutputTracks track;
 	SR_RTE_OutputCountryResults_t countryResults;
 	SR_RTE_OutputROIInformation_t roiInformation;
 } SR_RTE_Output_t;			/* compund struct for output of sign recognition @vaddr:0x30D41000 @vaddr_defs: SR_RTE_MEAS_ID_OUTPUT @cycleid:SR_ENV_B @vname:SR_RTE_Output */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteOpMode_t eOpMode;
 	uint32 uiDiagnoseDebugFlags;
 	uint8 uiSchedulingMode;
 } SacRteBswControlInput_t;			/* Control data for the SAC module @vaddr:0x30900000 @vaddr_defs: SAC_RTE_MEAS_ID_IN_BSW_CONTROL_INPUT @cycleid:SAC_ENV @vname:pGsOutBSWCtrlData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiTimelimit;
 	float32 fDistlimit;
 	bool8 bEnabled;
 } SacRteTimeout_t;			/* used for timeout checks */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteTimeout_t QCheckLR;
 	SacRteTimeout_t QCheckSGM;
 	SacRteTimeout_t CoarseCalib;
 	SacRteTimeout_t FineCalib;
 } SacRteComponentTimeout_t;			/* used for timeout checks */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteImageAndRoiParameters_t sCroppedRoiRight;
 	SacRteImageAndRoiParameters_t sCroppedRoiLeft;
 } SacRteCroppedRoiInput_t;			/* Cropped roi input data for SAC */

typedef uint32                    	aBinCntEpipolar_array_t[4];/* BINS_U*BINS_V */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aBinCntYaw_array_t[5];/* BINS_D */	/* [Satisfies_rte sws 1189] */

typedef SacRteEpipolarCorresp_t   	aEpicorresp_array_t[120];			/* [Satisfies_rte sws 1189] */

typedef uint8                     	aEpicorresp_new_array_t[120];/* indicate new epi points */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aMedianBufferRmseEpipolar_array_t[11];			/* [Satisfies_rte sws 1189] */

typedef float32                   	aMedianBufferRmseImprovement_array_t[11];			/* [Satisfies_rte sws 1189] */

typedef float32                   	aMedianBuffer_array_t[33];			/* [Satisfies_rte sws 1189] */

typedef float32                   	aTxtytzNew_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef float32                   	aTxtytzOld_array_t[3];			/* [Satisfies_rte sws 1189] */

typedef SacRteYawPoint_t          	aYaw_array_t[400];			/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiNumerOfUsedFrames;
 	Mat3x3_t sRotMatOld;
 	Mat3x3_t sRotMatNew;
 	float32 fTemperatureOld;
 	float32 fTemperatureNew;
 	Mat3x3_t sRotMatSACYawRadar;
 	Mat3x3_t sRotMatSACYawStereo;
 	aTxtytzOld_array_t aTxtytzOld;
 	aTxtytzNew_array_t aTxtytzNew;
 	aBinCntEpipolar_array_t aBinCntEpipolar;
 	aBinCntYaw_array_t aBinCntYaw;
 	aEpicorresp_array_t aEpicorresp;
 	aEpicorresp_new_array_t aEpicorresp_new;
 	aYaw_array_t aYaw;
 	uint32 uiMedianBufferEntries;
 	aMedianBuffer_array_t aMedianBuffer;
 	aMedianBufferRmseEpipolar_array_t aMedianBufferRmseEpipolar;
 	aMedianBufferRmseImprovement_array_t aMedianBufferRmseImprovement;
 	SacRteEvalOutput_t sEval;
 } SacRteCalibDbg_t;			/* Internal debug information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteStatistics_t sSacStatistics;
 	SacRteStereoCalibration_t sStereoCalibration;
 	SacRteLut_t sLutRight;
 	SacRteLut_t sLutLeft;
 	SacRteImageAndRoiParameters_t sImageRoiParametersRight;
 	SacRteImageAndRoiParameters_t sImageRoiParametersLeft;
 	SacRteImageAndRoiParameters_t sImageRoiParametersShiftRight;
 	SacRteImageAndRoiParameters_t sImageRoiParametersShiftLeft;
 	SacRteCalibDbg_t CalibDbg;
 } SacRteDebugOutput_t;			/* Debug information output data of SAC */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteLut_t sLutRight;
 	SacRteLut_t sLutLeft;
 	SacRteCorrespondenceMode_t eCorrespondenceMode;
 	SacRteImageAndRoiParameters_t sShiftedSRoiRight;
 	SacRteImageAndRoiParameters_t sShiftedSRoiLeft;
 } SacRteFexControlOutput_t;			/* FEX-Control data of the SAC module @vaddr:0x30910100 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_FEX_CONTROL @cycleid:SAC_ENV @vname:pSacOutFexControl */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	AlgoCompState_t sAlgoCompState;
 	SacRteReturnState_t eReturnState;
 	SacRteEvalOutput_t sEvalOutput;
 	uint32 uiSacWarnings;
 	SacRteCorrespondenceMode_t eCorrespondenceMode;
 	SacRteResult_t eResult;
 	sint32 siSACError;
 	ParameterID_t uiParameterId;
 	AlgoSignalState_t eExtrinsicRightToLeftUpdateValid;
 	SacRteShiftedRoiData_t sShiftedRoiData;
 } SacRteOutput_t;			/* @vaddr:0x30912700 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_OUTPUT @cycleid:SAC_ENV @vname:pSacOutput */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fXPosition;
 	float32 fYPosition;
 	float32 fVXSpeed;
 	sint32 dataQuality;
 } SacRteRduTargetList_t;			/* Targets list */

typedef SacRteRduTargetList_t     	RduTargetList_array_t[40];/* Targets list */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	RduTargetList_array_t RduTargetList;
 } SacRteRduInput_t;			/* Radar distance input data for SAC yaw-angle computation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	uint8 STATUS_SAC;
 	float32 PITCH_SAC;
 	float32 YAW_SAC;
 	float32 ROLL_SAC;
 	float32 PITCH_SAC_QUAL;
 	float32 YAW_SAC_QUAL;
 	float32 ROLL_SAC_QUAL;
 	float32 IMAGER_TEMP;
 	uint8 MAX_DEV_LANE_SEMO;
 } SacRteDiagStatusCalibStereo_t;			/* @vaddr:0x30918800 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_DIAG_STATUS_CALIB_STEREO @cycleid:SAC_ENV @vname:pSacOutDiagStatusCalibStereo */

typedef float32                   	aInitTmpModelPitch_array_t[16];/* values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aInitTmpModelRoll_array_t[16];/* values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aInitTmpModelYaw_array_t[16];/* slope of the yaw angle which is used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aP_BottomRight_array_t[2];/* X,Y-Position of top right corner of the area to be evaluated (meter or px) */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aP_TopLeft_array_t[2];/* X,Y-Position of top left corner of the area to be evaluated (meter or px) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteDistTestCoordinate_t sCoordinateSystem;
 	aP_TopLeft_array_t aP_TopLeft;
 	aP_BottomRight_array_t aP_BottomRight;
 	float32 fTargetDistanceNorm;
 	SacRteDistTestMode_t sMode;
 	float32 fReqRectError;
 	aInitTmpModelPitch_array_t aInitTmpModelPitch;
 	aInitTmpModelRoll_array_t aInitTmpModelRoll;
 	aInitTmpModelYaw_array_t aInitTmpModelYaw;
 } SacRteDistTestInput_t;			/* Information sent from diagnosis service to SAC @vaddr:0x30901900 @vaddr_defs: SAC_RTE_MEAS_ID_IN_DIST_TEST @cycleid:IPC_ENV @vname:pGdOutDistTest */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteDistTestSigState_t sState;
 	float32 fMeanDisparity;
 	float32 fDensityDisparity;
 	float32 fXTargetDistMeasured;
 	float32 fXTargetDistMeasured_std;
 	float32 fXTargetDistMeasured_min;
 	float32 fXTargetDistMeasured_max;
 	float32 fTargetDistanceNorm;
 	float32 fPitch;
 	float32 fRoll;
 	float32 fYaw;
 	float32 fRectError;
 	float32 fTemperature;
 	uint16 uiErrorCode;
 } SacRteDistTestOutput_t;			/* Information sent from diagnosis service to SAC @vaddr:0x30918600 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_DIST_TEST @cycleid:SAC_ENV @vname:pSacOutDistTest */

typedef float32                   	aInitTmpModelPitch_array_t_0[16];/* values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aInitTmpModelRoll_array_t_0[16];/* values from the PPAR which are used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */	/* [Satisfies_rte sws 1189] */

typedef float32                   	aInitTmpModelYaw_array_t_0[16];/* slope of the yaw angle which is used to initialize the temperature model entry 0: value for -40°C, entry 1: -30°C ... */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	float32 fTargetPosX;
 	float32 fTargetPosY;
 	float32 fTargetPosZ;
 	uint8 uiTargetNo;
 	float32 fXCircleLeft;
 	float32 fXCircleRight;
 	float32 fYCircleLeft;
 	float32 fYCircleRight;
 	aInitTmpModelPitch_array_t_0 aInitTmpModelPitch;
 	aInitTmpModelRoll_array_t_0 aInitTmpModelRoll;
 	aInitTmpModelYaw_array_t_0 aInitTmpModelYaw;
 } SacRteEcsInput_t;			/* ECS Information sent from diagnosis service to SAC @vaddr:0x30901700 @vaddr_defs: SAC_RTE_MEAS_ID_IN_ECS @cycleid:IPC_ENV @vname:pGdOutEcs */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	AlgoSignalState_t sState;
 	float32 fPitch;
 	float32 fRoll;
 	float32 fYaw;
 	float32 fQltyPitch;
 	float32 fQltyRoll;
 	float32 fQltyYaw;
 	float32 fOdometer;
 	float32 fTemperature;
 	float32 uiTargetNo;
 	float32 uiErrorCode;
 } SacRteEcsOutput_t;			/* Information sent from diagnosis service to SAC @vaddr:0x30918500 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_ECS @cycleid:SAC_ENV @vname:pSacOutEcs */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteImageAndRoiParameters_t sStereoRoiCurrentRight;
 	SacRteImageAndRoiParameters_t sStereoRoiCurrentLeft;
 } SacRteStereoRoiInput_t;			/* Stereo-Roi position+dimensions as given by FPGA and sent from Bsw to Sac @vaddr:0x30900900 @vaddr_defs: SAC_RTE_MEAS_ID_IN_STEREO_ROI @cycleid:SAC_ENV @vname:pGpmcOutStereoRoi */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	SacRteStereoCalibration_t sStereoCalibration;
 	SacRteImageAndRoiParameters_t sNominalSRoiRight;
 	SacRteImageAndRoiParameters_t sNominalSRoiLeft;
 	SacRteImageAndRoiParameters_t sShiftedSRoiRight;
 	SacRteImageAndRoiParameters_t sShiftedSRoiLeft;
 	sint32 uiImageDataLeft_SyncOffset;
 	SacRteShiftedRoiData_t sShiftedRoiData;
 } SacRteStereoCalibrationOutput_t;			/* Stereo calibration output data of SAC @vaddr:0x30912000 @vaddr_defs: SAC_RTE_MEAS_ID_OUT_STEREO_CALIBRATION @cycleid:SAC_ENV @vname:pSacOutStereoCalibration */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	u16q7_t uiDispAverage;
 	u16q7_t uiDispStd;
 	u16q7_t uiDispMin;
 	u16q7_t uiDispMax;
 } SibFloxelDisparity_t;			/* Floxel Disparity Information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s16q4_t fpFlowDuAverage;
 	s16q4_t fpFlowDuStaticArea;
 	s16q4_t fpFlowDvAverage;
 	s16q4_t fpFlowDvStaticArea;
 	uint8 uiNumValidFlows;
 	u8q6_t fpAverageNumFlowHypotheses;
 } SibFloxelFlow_t;			/* Floxel Flow Information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s16q7_t fpXPosAverage;
 	s16q7_t fpYPosAverage;
 	s16q7_t fpZPosAverage;
 	s16q7_t fpZPosAverageRelRoadModel;
 	uint8 uiNumValidDispAndStatus;
 	u8q8_t fpDynamicConfidence;
 } SibFloxelGeometry_t;			/* Floxel Geometry Information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ui16_Intensity;
 	uint16 ui16_Imin;
 	uint16 ui16_Imax;
 	uint16 ui16_MaxNeighbourDiff;
 } SibFloxelIntensity_t;			/* Floxel Intensity Information */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fLongPosHood;
 	float32 fLatPosHood;
 	float32 fVertPosHood;
 	uint16 uiUPosHood;
 	uint16 uiVPosHood;
 	float32 fLongRangeMax;
 	float32 fLatRange;
 	float32 fVertRangeTop;
 	float32 fVertRangeBottom;
 } SibPerVolConfig_t;			/* Defines the measurement volume of the harvester module */

typedef SibFloxelDisparity_t      	aDisparityTable_array_t[12410];/* Disparity related information */	/* [Satisfies_rte sws 1189] */

typedef SibFloxelFlow_t           	aFlowTable_array_t[12410];/* Flow related information */	/* [Satisfies_rte sws 1189] */

typedef SibFloxelGeometry_t       	aGeometryTable_array_t[12410];/* Geometry related information */	/* [Satisfies_rte sws 1189] */

typedef SibFloxelIntensity_t      	aIntensityTable_array_t[12410];/* Intensity related information */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	dummy1_alignTo128Byte_array_t[108];/* dummy member to ensure 128 byte alignment of the following table */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	dummy2_alignTo128Byte_array_t[60];/* dummy member to ensure 128 byte alignment of the following table */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	dummy3_alignTo128Byte_array_t[48];/* dummy member to ensure 128 byte alignment of the following table */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	dummy4_alignTo128Byte_array_t[60];/* dummy member to ensure 128 byte alignment of the following table */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	dummy5_alignTo128Byte_array_t[48];/* dummy member to ensure 128 byte alignment of the end of the table */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	sint16 iHarvesterParamsFingerprint;
 	SibPerVolConfig_t sPerceptionVolumeConfiguration;
 	ImageHeader_t sImgHeaderRectified;
 	ImageHeader_t sImgHeaderDisparity;
 	ImageHeader_t sImgHeaderFlow;
 	dummy1_alignTo128Byte_array_t dummy1_alignTo128Byte;
 	aGeometryTable_array_t aGeometryTable;
 	dummy2_alignTo128Byte_array_t dummy2_alignTo128Byte;
 	aDisparityTable_array_t aDisparityTable;
 	dummy3_alignTo128Byte_array_t dummy3_alignTo128Byte;
 	aFlowTable_array_t aFlowTable;
 	dummy4_alignTo128Byte_array_t dummy4_alignTo128Byte;
 	aIntensityTable_array_t aIntensityTable;
 	dummy5_alignTo128Byte_array_t dummy5_alignTo128Byte;
 } SibFloxelData_t;			/* Floxel data */

typedef float32                   	aModelParameters_array_t[50];/* Array containing road model parameters */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	aModelParameters_array_t aModelParameters;
 } SibRoadModelData_t;			/* Road model describing drivable ground in front of system vehicle @vaddr:0x30A1A000 @vaddr_defs: SIB_MEAS_ID_ROAD_MODEL_DATA @cycleid:SIB_ENV @vname:SibRoadModelData */

typedef uint8                     	u_CrashDumpBuffer_array_t[100];/* Failure information from SoC to MCU */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	u_CrashDumpBuffer_array_t u_CrashDumpBuffer;
 } t_SoCCrashDump_t;			/* Crash Dump from SoC to MCU */

typedef uint8                     	u_DemBuffer_array_t[1024];/* Data buffer for DEM event status and PreExtendedData */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	u_DemBuffer_array_t u_DemBuffer;
 } t_SoCDemSlaveEvents_t;			/* Control Data  from SoC to MCU */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_GsActState;
 } SoCGsActState_t;			/* Submode of the GS */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint16 u_StatCntryCodeValue;
 	uint32 u_StatOptimeTotalValue;
 	uint32 u_StatOptimeNightValue;
 	uint32 u_StatOptimeWiperValue;
 	uint32 u_StatDrivenDistTotalValue;
 	uint32 u_StatDrivenDistUrbanValue;
 	uint32 u_StatDrivenDistRuralValue;
 	uint32 u_StatDrivenDistMowayValue;
 	uint32 u_StatDrivenDistNaValue;
 	uint16 u_StatAmntEyeqResetValue;
 	uint16 u_StatAmntOnlineCalibValue;
 } t_SoCStatEcuData_t;			/* @vaddr:0x83005000 @vaddr_defs: MEAS_ID_STAT_ECU_DATA_SOC @cycleid:MEAS_CYCID_STAT_ECU_DATA_SOC @vname:STAT_ECU_DATA_SOC */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint8 u_LengthOfRightImageBuffers;
 } t_SoCSystemConfigInfo_t;			/* HW/Product specific configuration info */

typedef uint32                    	u_Reserved_Fields_array_t[7];/* Reserved for urgent cases if interface change in release not possible anymore */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint32 u_SynchTimeStampL;
 	uint32 u_SynchTimeStampH;
 	uint32 u_ACTLStateActual;
 	float32 f_TempSensorRight;
 	float32 f_TempSensorLeft;
 	u_Reserved_Fields_array_t u_Reserved_Fields;
 } t_SoCSystemData_t;			/* Control Data  from SoC to MCU @vaddr:0x83002000 @vaddr_defs: MEAS_ID_SYSDATA_SOC @cycleid:MEAS_CYCID_SYSDATA_SOC @vname:SYSDATA_SOC */

typedef uint8                     	u_Data_array_t_0[1024];/* Array for data */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint32 u_Receiver;
 	uint32 u_CmdIdentifier;
 	uint32 u_MemStart;
 	uint32 u_MemLength;
 	u_Data_array_t_0 u_Data;
 } t_SoCXcpRxData_t;			/* XCP container type for data forwarding to SoC */

typedef uint8                     	u_Data_array_t[1024];/* Array for data */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 u_VersionNumber;
 	uint32 u_ReadLength;
 	u_Data_array_t u_Data;
 } t_SoCXcpTxData_t;			/* XCP container type for data forwarding from SoC */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	HeaderAssessedObjList_t HeaderAssessedObjList;
 	ObjList_array_t ObjList;
 } AssessedObjList_t;			/* Assessed Object List (Lane assigned) @vaddr:0x20210000 @vaddr_defs: FCT_MEAS_ID_PUBLIC_OBJECT_LIST @cycleid:FCT_ENV @vname:FCTPublicObjData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	PoseParameters_t SensorPosition;
 	EcmRteError_t eError;
 	EcmRteTargetExtraction_t EcmRteTargetExtraction;
 } EcmRteOutput_t;			/* Ecmbration output data @vaddr:0x30F11200 @vaddr_defs: ECM_RTE_MEAS_ID_OUTPUT @cycleid:ECM_ENV @vname:pEcmOutput */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 nXDist;
 	sint16 nYDist;
 } Vector2_i16_t;			/* Vector with x and y with i16 values */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 nXDist;
 	sint32 nYDist;
 } Vector2_i32_t;			/* Vector with x and y with i32 values */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint8 nXDist;
 	sint8 nYDist;
 } Vector2_i8_t;			/* Vector with x and y with i8 values */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	bool8 bResetBlockageCriteria;
 } SysPerfMonStates_t;			/* @vaddr:0x20100010 @vaddr_defs: EM_MEAS_ID_SYS_PERF_MON_STATES @cycleid:FCT_ENV @vname:SysPerfMonStates */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 numberOfLanes;
 	uint8 presentLane;
 } TsaRteRoadCharacteristicsRc_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 numberEvents;
 	uint8 mppDeviate;
 	uint8 routingActive;
 	uint8 newEvents;
 	uint8 eventsPassed;
 	uint8 uiPaddingByte;
 } TsaRteRoadCharacteristicsStatus_t;			/* custom input data RoadCharacteristics */

typedef TsaRteRoadCharacteristicsRc_t 	aTsaRteRoadCharacteristicsRc[10];/* custom input data RoadForesight */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 crossroads;
 	uint8 branch;
 	uint8 trafficCircle;
 	uint8 streetTypeChange;
 	uint8 trafficLights;
 	uint8 uiPaddingByte;
 } TsaRteRoadForesightRoadTopologyEvent_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 streetType;
 	float32 directionChangeAngle;
 	float32 routeProbability;
 } TsaRteRoadForesightRoadTopologyMppRoadInfo_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 eventNumber;
 	uint16 startPosition;
 	TsaRteRoadForesightRoadTopologyEvent_t event;
 	TsaRteRoadForesightRoadTopologyMppRoadInfo_t mppRoadInfo;
 } TsaRteRoadForesightRoadTopology_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 angle;
 	float32 curvature;
 } TsaRteRoadForesightStatusBaseSegment_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 x;
 	float32 y;
 } TsaRteRoadForesightStatusPointSegment_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 numberEventsCurveForesight;
 	uint8 numberEventsRoadTopology;
 	uint8 qualityLevel;
 	uint8 mppDeviate;
 	uint8 routingActive;
 	TsaRteRoadForesightStatusPointSegment_t pointSegment;
 	TsaRteRoadForesightStatusBaseSegment_t baseSegment;
 } TsaRteRoadForesightStatus_t;			/* custom input data RoadForesight */

typedef TsaRteRoadForesightRoadTopology_t 	aTsaRteRoadTopology[10];/* custom input data RoadForesight */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 event;
 	uint16 startPosition;
 	uint16 eventId;
 	uint8 speedLimit;
 	uint8 conditionSpeedLimit;
 	uint8 timeStart;
 	uint8 timeEnd;
 	uint8 speedLimitUnit;
 } TsaRteSpeedForesightDataEvent_t;			/* custom input data SpeedForesightData */

typedef TsaRteSpeedForesightDataEvent_t 	aTsaRteSpeedForesightDataEvent[10];/* custom input data SpeedForesightData */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 E2E_ReceiverStatus;
 	uint16 timestamp;
 	uint8 eventDataQualifier;
 	uint8 extendedQualifier;
 	TsaRteRoadCharacteristicsStatus_t status;
 	aTsaRteRoadCharacteristicsRc roadCharacteristics;
 } TsaRteRoadCharacteristics_t;			/* custom input data RoadCharacteristics */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 E2E_ReceiverStatus;
 	uint16 timestamp;
 	uint8 eventDataQualifier;
 	uint8 extendedQualifier;
 	TsaRteRoadForesightStatus_t status;
 	aTsaRteRoadTopology roadTopology;
 } TsaRteRoadForesight_t;			/* custom input data RoadForesight */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 timestamp;
 	uint8 eventDataQualifier;
 	uint8 extendedQualifier;
 	uint16 eventsPassed;
 	uint16 newEvents;
 	uint8 numEvents;
 	aTsaRteSpeedForesightDataEvent events;
 } TsaRteSpeedForesightData_t;			/* custom input data SpeedForesightData */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	uint8 dummy;
 	TsaRteRoadForesight_t roadForesight;
 	TsaRteRoadCharacteristics_t roadCharacteristics;
 	TsaRteSpeedForesightData_t speedForesightData;
 } TsaRteCustomInput_t;			/* custom input data @vaddr:0x20044200 @vaddr_defs: TSA_RTE_MEAS_ID_CUSTOM_INPUT @cycleid:IPC_ENV @vname:TsaRteCustomInput */

typedef uint8                     	aRteHealthStatus[16];/* health / debug status output */	/* [Satisfies_rte sws 1189] */

typedef sint32                    	aRteCustomSignAdditionalInfo[2];/* specific data: for supplementary sign e.g. time, weight, etc. for normal signs track id of gate counterpart */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	TsaRteCustomSignFunctionalSignClassId_t classId;
 	sint32 recogReliability;
 	aRteCustomSignAdditionalInfo additionalInfo;
 } TsaRteCustomSignResultClass_t;			/* substruct for alternative sign result classes */

typedef TsaRteCustomSignResultClass_t 	aRteCustomSignResultsMainClass[5];/* result(s) for main sign */	/* [Satisfies_rte sws 1189] */

typedef TsaRteCustomSignResultClass_t 	aRteCustomSignResultsSupplClass[5];/* result(s) for first supplementary sign */	/* [Satisfies_rte sws 1189] */

typedef TsaRteCustomSignResultClass_t 	aRteCustomSignResultsSupplClass_0[5];/* result(s) for second supplementary sign */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 id;
 	TsaRteCustomSignResultTrackState_t trackStatus;
 	sint32 trackQuality;
 	TsaRteCustomSignResultTrackCharacteristics_t trackCharacteristics;
 	aRteCustomSignResultsMainClass mainClass;
 	TsaRteCustomSignResultGeometry_t signGeometry;
 	TsaRteCustomSignResultUnit_t signUnit;
 	aRteCustomSignResultsSupplClass supplClass1;
 	TsaRteCustomSignSupplResultPosition_t supplPosition1;
 	aRteCustomSignResultsSupplClass_0 supplClass2;
 	TsaRteCustomSignSupplResultPosition_t supplPosition2;
 	float32 worldPosX;
 	float32 worldPosY;
 	float32 worldPosZ;
 	float32 deltaWorldPosX;
 	float32 deltaWorldPosY;
 	float32 deltaWorldPosZ;
 	float32 worldWidth;
 	float32 deltaWorldWidth;
 } TsaRteCustomOutputSignResultTrack_t;			/* sign recognition result for a single track */

typedef TsaRteCustomOutputSignResultTrack_t 	aRteCustomOutputSignResultTracks[16];/* the tracks */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 numberOfResultTracks;
 	aRteCustomOutputSignResultTracks track;
 } TsaRteCustomOutputSignResults_t;			/* custom sign recognition result for all tracks */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	TsaRteCustomOutputSignResults_t signResults;
 	TsaRteCustomOutputEstTrafficStyle_t estTrafficStyle;
 	timeOfDay_t timeOfDay;
 	blockageStatus_t blockageStatus;
 	calibrationStatus_t calibrationStatus;
 	aRteHealthStatus healthStatus;
 } TsaRteCustomOutput_t;			/* custom output data @vaddr:0x20049000 @vaddr_defs: TSA_RTE_MEAS_ID_OUTPUT_CUSTOM @cycleid:TSA_ENV @vname:TsaRteOutputCustom */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	TsaRteNpaStatus_t noPassingStatus;
 	TsaRteNpaValidity_t noPassingValidity;
 	TsaRteNpaSupplSignValState_t noPassingSupplSignVal;
 	float32 noPassingChangeDist;
 	TsaRteNpaIndicators_t noPassingIndicators;
 } TsaRteOutputNpaResult_t;			/* NPA result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 estCountryCode;
 	TsaRteEstTrafficStyle_t estTrafficStyle;
 	TsaRteEstSpdUnt_t estSpdUnt;
 } TsaRteEstimationResults_t;			/* results from estimation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	TsaRteCurrentMotorway_t currentMotorway;
 	TsaRteCurrentUrbanArea_t currentUrbanArea;
 	TsaRteUrbanAreaChange_t urbanAreaChange;
 	float32 distToUrbanAreaChange;
 } TsaRteRoadInfo_t;			/* results from eHorizon Input */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	TsaRteRwfStatus_t roadWorksStatus;
 	TsaRteRwfIndicators_t roadWorksIndicators;
 	sint32 roadWorkSpeedValue;
 	float32 roadWorkReActDist;
 	bool8 roadWorkEndFlag;
 } TsaRteOutputRwfResult_t;			/* RWF result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 spdLmtValue;
 	TsaRteSlaSpdLmtType_t spdLmtType;
 	TsaRteSlaSpdLmtVal_t spdLmtValidity;
 	TsaRteSlaSupSgnVal_t supplSignValidityState;
 	TsaRteSlaSpdUnit_t spdUnit;
 	TsaRteSlaSpdLmtEnd_t endOfLimit;
 	float32 expirDistance;
 } TsaRteSlaSpdLmt_t;			/* speed limit */

typedef TsaRteSlaSpdLmt_t         	aRteSlaSpdLmt[2];/* speed limit */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	aRteSlaSpdLmt spdLmt;
 } TsaRteOutputSlaResult_t;			/* SLA result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	TSARteWwaStatus_t wrongWayStatus;
 	TSARteWwaStatus_t wronyWayLastStatus;
 	float32 wrongWayChangeDist;
 } TsaRteOutputWwaResult_t;			/* WWA result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t sSigHeader;
 	uint32 rteWrpVersion;
 	TsaRteOutputSlaResult_t slaResults;
 	TsaRteOutputNpaResult_t npaResults;
 	TsaRteOutputRwfResult_t rwfResults;
 	TsaRteOutputWwaResult_t wwaResults;
 	TsaRteEstimationResults_t countryEstimationResults;
 	TsaRteRoadInfo_t roadInfo;
 } TsaRteOutputResults_t;			/* output results data @vaddr:0x20045000 @vaddr_defs: TSA_RTE_MEAS_ID_OUTPUT_RESULTS @cycleid:TSA_ENV @vname:TsaRteOutputResults */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	VDYErrState_t YwrOffsRg;
 	VDYErrState_t SwaOffsRg;
 	VDYErrState_t AyOffsRg;
 	VDYErrState_t VelCorrRg;
 	VDYErrState_t NVMYwrOffsRg;
 	VDYErrState_t NVMSwaOffsRg;
 	VDYErrState_t NVMAyOffsRg;
 	VDYErrState_t NVMVelCorrRg;
 	VDYErrState_t VelCorrWin;
 	VDYErrState_t VelMon;
 	VDYErrState_t VelMonLt;
 	VDYErrState_t VelocityErr;
 	VDYErrState_t YawRateErr;
 	VDYErrState_t YwrMonVehHalt;
 	VDYErrState_t YwrMonVehDOff;
 	VDYErrState_t YwrMonAdmWdrwl;
 	VDYErrState_t YwrACCMonAlignm;
 	VDYErrState_t YwrCGMonAlignm;
 	VDYErrState_t YwrMonVehHaltCal;
 	VDYErrState_t VDY_FS_YR_VS_WSP;
 	VDYErrState_t VDY_FS_YR_VS_AY;
 	VDYErrState_t VDY_FS_YR_VS_SWA;
 	VDYErrState_t VDY_VEH_VEL_NOT_AVAILABLE;
 	VDYErrState_t VDY_VEH_YWR_NOT_AVAILABLE;
 	VDYErrState_t VDY_FS_VEH_CORR_MON;
 } OutPutErrors_t;			/* Output values and internalal errors */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	VDYErrState_t InputParameterError;
 } ParInputErrors_t;			/* Parameter input errors */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	VDYErrState_t InputSignalError;
 	VDYErrState_t InputSignalPeakError;
 } SignalInputErrors_t;			/* Signal input errors */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	SignalInputErrors_t SignalInputErrors;
 	ParInputErrors_t ParInputErrors;
 	OutPutErrors_t OutPutErrors;
 } VDYErrors_t;			/* The vdy errors input signals/parameters
Output errors, internal errors, @vaddr:0x20350300 @vaddr_defs: VDY_MEAS_ID_ERRORS @cycleid:vdy_cycle_id @vname:VDYErrors */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } AyCurve_t;			/* Lateral acceleration curve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } DrvIntCurve_t;			/* Steering wheel angle curve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } SwaCurve_t;			/* Steering angle yaw rate curve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } VehYawCurve_t;			/* Vehicle yaw rate curve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } WhlCurve_t;			/* Wheel speed curve all axles */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } WhlFrCurve_t;			/* Wheel speed curve front axle */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } WhlReCurve_t;			/* Wheel speed curve rear axle */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fCurve_t Curve;
 } YwRateCurve_t;			/* Yaw rate sensor curve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	WhlCurve_t Whl;
 	WhlFrCurve_t WhlFr;
 	WhlReCurve_t WhlRe;
 	YwRateCurve_t YwRate;
 	AyCurve_t Ay;
 	SwaCurve_t Swa;
 	DrvIntCurve_t DrvInt;
 	VehYawCurve_t VehYaw;
 } VDYEstCurves_t;			/* The vdy estimated curves @vaddr:0x20350700 @vaddr_defs: VDY_MEAS_ID_EST_CURVES @cycleid:vdy_cycle_id @vname:VDYCrv */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fAccel_t ZeroAccel;
 	uint32 CalStatus;
 } LatAcc_t;			/* Lateral accleration zero point offset estimation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 SlfStGrad;
 	uint8 SlfStGradMax;
 	uint8 SlfStGradMin;
 	sint8 CalStatus;
 	uint8 Dummy;
 } VDYNvSlfStGradCal_t;			/* Understeer / Oversteer gradient estimation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fAngle_t ZeroAngle;
 	uint32 CalStatus;
 } VDYNvStWhlAngCal_t;			/* Steering wheel angle zero point offset estimation */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Wld_front;
 	float32 Wld_rear;
 	uint8 Wld_front_quality;
 	uint8 Wld_rear_quality;
 } VDYNvWldCal_t;			/* Wheel load dependency */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fRatio_t CorrFact;
 	fVelocity_t Velo;
 	float32 Dev;
 } VelCorr_t;			/* Longitudinal velocity correction */

typedef VelCorr_t                 	VelCorr_array_t[3];/* Longitudinal velocity correction */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fYawRate_t ZeroRate;
 	fYawRate_t ZeroRateMin;
 	fYawRate_t ZeroRateMax;
 	uint32 CalStatus;
 } YwRate_t;			/* Yaw rate  zero point offset value */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	VDYNvStWhlAngCal_t StWhlAng;
 	VDYNvSlfStGradCal_t SlfstGrad;
 	YwRate_t YwRate;
 	LatAcc_t LatAcc;
 	VelCorr_array_t VelCorr;
 	VDYNvWldCal_t Wld;
 	VdyNvmState_t State;
 } VDYNvIoData_t;			/* The vdy nvm input and output data stuct @vaddr:0x20300400, 0x20350400 @vaddr_defs: VDY_MEAS_ID_NVM_READ,VDY_MEAS_ID_NVM_WRITE @cycleid:vdy_cycle_id @vname:VDYNvIoDataRD,VDYNvIoDataWR */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fAngle_t Offset;
 	fVariance_t Variance;
 	sint32 State;
 } Ay_t;			/* Lat accel offset result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fAngle_t Offset;
 	fVariance_t Variance;
 	sint32 State;
 } Swa_t;			/* Steering wheel angle offset result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	fYawRate_t StandStillOffset;
 	sint32 StandStillState;
 	fYawRate_t DynOffset;
 	fVariance_t DynVariance;
 } Ywr_t;			/* Yaw rate offset result */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	Ywr_t Ywr;
 	Swa_t Swa;
 	Ay_t Ay;
 } VDYOffsets_t;			/* The offsets of the vdy input signals like yaw rate @vaddr:0x20350200 @vaddr_defs: VDY_MEAS_ID_OFFSETS @cycleid:vdy_cycle_id @vname:VDYOffsets */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fXL;
 	float32 fXLStd;
 	float32 fXR;
 	float32 fXRStd;
 	float32 fYT;
 	float32 fYTStd;
 	float32 fYB;
 	float32 fYBStd;
 } VclBoundingBox_t;			/* Bounding Box of target */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	float32 fMeasQuality;
 	sint32 iMeasToObjID;
 } VclInfo_t;			/* specific info of vcl target */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 eObjClass;
 	float32 fClassConf;
 } VclType_t;			/* specific info of vcl target */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	float32 fXPos;
 	float32 fYPos;
 	float32 fWidth;
 	Mat3x3_t CovMatrix;
 	float32 fConf;
 } VclWorldPos_t;			/* Range estimation and transformation to 3D */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint32 EMObjId;
 	sint32 VCLObjId;
 } VclAssocList_t;			/* Association List VCL Object to EM Object */

typedef VclAssocList_t            	VclAssocList_array_t[80];/* Association List VCL Object to EM Object */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fDTime;
 	float32 fDx;
 	float32 fDy;
 	float32 fDScale;
 	float32 fDxVar;
 	float32 fDyVar;
 	float32 fDScaleVar;
 	float32 fCovDxDy;
 	float32 fCovDxDScale;
 	float32 fCovDyDScale;
 } VclDiff_t;			/* Image shift and scale change */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	VclInfo_t Info;
 	VclBoundingBox_t BoundingBox;
 	VclType_t Type;
 	VclDiff_t VclDiff;
 } VclDiffMeas_t;			/* Differential vehicle measurement (image shift and scale change) */

typedef VclDiffMeas_t             	VclDiffMeas_array_t[25];/* Differential vehicle measurement (image shift and scale change) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	VclInfo_t Info;
 	VclBoundingBox_t BoundingBox;
 	VclWorldPos_t WorldPosWi;
 	VclWorldPos_t WorldPosYb;
 	VclType_t Type;
 } VclEdgeMeas_t;			/* Vehicle bounding box measurement */

typedef VclEdgeMeas_t             	VclEdgeMeas_array_t[25];/* Vehicle bounding box measurement */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 bIsValid;
 	float32 fXImg;
 	float32 fXImgStd;
 	float32 fYImg;
 	float32 fYImgStd;
 	sint32 IDLight;
 } VclLight_t;			/* Single vehicle light */

typedef VclLight_t                	VclLight_array_t[10];/* Single vehicle light */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	VclInfo_t Info;
 	VclBoundingBox_t BoundingBox;
 	VclWorldPos_t WorldPos;
 	VclType_t Type;
 	VclLight_array_t VclLight;
 } VclLightCluster_t;			/* Vehicle lights measurement */

typedef VclLightCluster_t         	VclLightCluster_array_t[25];/* Vehicle lights measurement */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSignalHeader;
 	VclEdgeMeas_array_t VclEdgeMeas;
 	VclLightCluster_array_t VclLightCluster;
 	VclDiffMeas_array_t VclDiffMeas;
 	VclAssocList_array_t VclAssocList;
 } VclMeasList_t;			/* Vehicle measurement list properties @vaddr:0x30410000 @vaddr_defs: VCL_MEAS_ID_MEAS_LIST @cycleid:VCL_ENV @vname:VCLMeasList */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 corrAccel;
 	float32 corrAccelVar;
 } AccelCorrVehDyn_t;			/* Longitudinal acceleration correction */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Curve;
 	float32 C1;
 	float32 Gradient;
 	float32 varC0;
 	float32 varC1;
 	float32 Quality;
 	float32 CrvError;
 	uint8 CrvConf;
 } CurveVehDyn_t;			/* Curve */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Curve;
 	float32 Variance;
 	float32 Gradient;
 } DrvIntCurveVehDyn_t;			/* Driver intended curvature */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 LatAccel;
 	float32 Variance;
 } LatAccelVehDyn_t;			/* Lateral acceleration */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 SideSlipAngle;
 	float32 Variance;
 } SideSlipVehDyn_t;			/* Vehice body side slip angle */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 YawRateMaxJitter;
 	bool8 bStandStill;
 } LegacyVehDyn_t;			/* Vehicle sensor qualifiers */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 Velocity;
 	float32 Accel;
 	float32 varVelocity;
 	float32 varAccel;
 } MotVarVehDyn_t;			/* Longitudinal motion variables */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 corrFact;
 	float32 corrVar;
 	float32 corrVelo;
 	float32 corrVeloVar;
 	float32 minVelo;
 	float32 maxVelo;
 	corrQual_t corrQual;
 } VeloCorrVehDyn_t;			/* Longitudinal Velocity correction */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	MotState_t MotState;
 	float32 Confidence;
 } MotionStateVehDyn_t;			/* Lateral motion variables */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 YawRate;
 	float32 Variance;
 	float32 Quality;
 } YawRateVehDyn_t;			/* Yaw rate data */

typedef VDYIoStateTypes_t         	State_array_t[12];/* State of the VehDyn output as enum values of VDYIoStateTypes_t with the index VehDynStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	MotVarVehDyn_t MotVar;
 	VeloCorrVehDyn_t VeloCorr;
 	AccelCorrVehDyn_t AccelCorr;
 } Longitudinal_t;			/* Longitudinal motion variables */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	YawRateVehDyn_t YawRate;
 	CurveVehDyn_t Curve;
 	DrvIntCurveVehDyn_t DrvIntCurve;
 	LatAccelVehDyn_t Accel;
 	SideSlipVehDyn_t SlipAngle;
 } Lateral_t;			/* Lateral motion variables */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	Longitudinal_t Longitudinal;
 	Lateral_t Lateral;
 	MotionStateVehDyn_t MotionState;
 	LegacyVehDyn_t Legacy;
 	State_array_t State;
 } VehDyn_t;			/* Vehicle dynamic data (VDY output) @vaddr:0x20350000 @vaddr_defs: VDY_MEAS_ID_VEH_DYN @cycleid:vdy_cycle_id @vname:VehDyn */

typedef VDYIoStateTypes_t         	State_array_t_6[8];/* State of the sensor mounting parameter as enum values of VDYIoStateTypes_t with the index VehParSenMountStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef VDYIoStateTypes_t         	State_array_t_7[8];/* State of the sensor spefific parameter as enum values of VDYIoStateTypes_t with the index VehParSensorStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */

typedef VDYIoStateTypes_t         	State_array_t_4[16];/* State of the main vehicle parameter as enum values of VDYIoStateTypes_t with the index VehParMainStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef VDYIoStateTypes_t         	State_array_t_5[12];/* State of the additional vehicle parameter as enum values of VDYIoStateTypes_t with the index VehParAddStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	State_array_t_6 State;
 	float32 LatPos;
 	float32 LongPos;
 	float32 VertPos;
 	float32 LongPosToCoG;
 	float32 PitchAngle;
 	Orientation_t Orientation;
 	float32 RollAngle;
 	float32 YawAngle;
 } SensorMounting_t;			/* Sensor mounting geometry */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	State_array_t_7 State;
 	float32 CoverDamping;
 	float32 fCoverageAngle;
 	float32 fLobeAngle;
 	float32 fCycleTime;
 	uint8 uNoOfScans;
 } Sensor_t;			/* Sensor specific parameters */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	State_array_t_5 State;
 	float32 VehicleWidth;
 	float32 VehicleLength;
 	float32 CurbWeight;
 	float32 OverhangFront;
 	float32 FrontAxleRoadDist;
 	float32 WheelWidth;
 	float32 PassableHeight;
 	float32 DistCameraToHoodX;
 	float32 DistCameraToHoodY;
 	SteeringVariant_t SteeringVariant;
 } VehParAdd_t;			/* Vehicle additional parameters */

typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */

typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	ang_array_t ang;
 	rat_array_t rat;
 } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	vel_array_t vel;
 	rat_array_t_0 rat;
 } vel_t;			/* Table for additional steering ratio part in dependence of velocity */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	swa_t swa;
 	vel_t vel;
 } StRatio_t;			/* Steering ratio */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	State_array_t_4 State;
 	float32 SelfSteerGrad;
 	StRatio_t SteeringRatio;
 	float32 WheelBase;
 	float32 TrackWidthFront;
 	float32 TrackWidthRear;
 	float32 VehWeight;
 	float32 CntrOfGravHeight;
 	float32 AxisLoadDistr;
 	float32 WhlLoadDepFrontAxle;
 	float32 WhlLoadDepRearAxle;
 	float32 WhlCircumference;
 	uint8 DrvAxle;
 	uint8 WhlTcksPerRev;
 	float32 FrCrnrStiff;
 	float32 ReCrnrStiff;
 } VehParMain_t;			/* Vehicle main parameters */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	VehParMain_t VehParMain;
 	VehParAdd_t VehParAdd;
 	SensorMounting_t SensorMounting;
 	Sensor_t Sensor;
 } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300 @vaddr_defs: VDY_MEAS_ID_VEH_PAR @cycleid:vdy_in_cycle_id @vname:VehPar */

typedef VDYIoStateTypes_t         	State_array_t_3[2];/* State of the brake vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigBrakeStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef VDYIoStateTypes_t         	State_array_t_2[3];/* State of the powertrain vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigPowertrainStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef VDYIoStateTypes_t         	State_array_t_0[32];/* State of the main vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigMainStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef VDYIoStateTypes_t         	State_array_t_1[20];/* State of the add vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigAddStatePos_t */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	TransmissionGear_t ActualGear;
 	TransmissionGear_t TargetGear;
 	bool8 EngineRunning;
 	State_array_t_2 State;
 } PowerTrain_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	bool8 ABSCtrl;
 	bool8 TCSCtrl;
 	State_array_t_3 State;
 } Brake_t;			/* Sensor specific parameters */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	State_array_t_1 State;
 	float32 EnvTemp;
 	WiperState_t WiperState;
 	WiperStage_t WiperStage;
 	bool8 WiperOutParkPos;
 	WiperWasherFrontState_t WiperWasherFrontState;
 	bool8 RainSensor;
 	TurnSignal_t TurnSignal;
 	bool8 FogLampFront;
 	bool8 FogLampRear;
 	float32 RoadWhlAngFr;
 	float32 RoadWhlAngRe;
 	float32 Odometer;
 	float32 GasPedalPos;
 	bool8 KickDown;
 	bool8 BrakePedalPressed;
 	bool8 DriverTired;
 	SpeedUnit_t SpeedUnit;
 	float32 SpeedoSpeed;
 	TrailerConnection_t TrailerConnection;
 	IgnitionSwitch_t IgnitionSwitch;
 } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	State_array_t_0 State;
 	float32 YawRate;
 	float32 YawRateTemp;
 	float32 StWheelAngle;
 	float32 LatAccel;
 	float32 WhlVelFrLeft;
 	float32 WhlVelFrRight;
 	float32 WhlVelReLeft;
 	float32 WhlVelReRight;
 	float32 YawRateInt;
 	float32 YawRateIntTemp;
 	float32 LongAccel;
 	float32 RearWhlAngle;
 	float32 VehVelocityExt;
 	float32 VehLongAccelExt;
 	LongDirState_t WhlDirFrLeft;
 	LongDirState_t WhlDirFrRight;
 	LongDirState_t WhlDirReLeft;
 	LongDirState_t WhlDirReRight;
 	uint8 WhlTicksDevFrLeft;
 	uint8 WhlTicksDevFrRight;
 	uint8 WhlTicksDevReLeft;
 	uint8 WhlTicksDevReRight;
 	ActGearPos_t ActGearPos;
 	uint16 BrakeActLevel;
 	ParkBrakeState_t ParkBrakeState;
 	LongDirState_t VehLongDirExt;
 	VehLongMotStateExt_t VehLongMotStateExt;
 	float32 CurveC0Ext;
 	float32 CurveC1Ext;
 	float32 SideSlipAngleExt;
 } VehSigMain_t;			/* Main Vehicle dynacmis sensor signals */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t sSigHeader;
 	VehSigMain_t VehSigMain;
 	VehSigAdd_t VehSigAdd;
 	PowerTrain_t PowerTrain;
 	Brake_t Brake;
 } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:0x20300050 @vaddr_defs: VDY_MEAS_ID_VEH_SIG @cycleid:vdy_in_cycle_id @vname:VehSig */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	eChannelType_t eChannelType;
 	uint8 uNumberReceptiveFields;
 } ChannelInformation_t;			/* LRF channel information */

typedef ChannelInformation_t      	ChannelInformation_array_t[3];/* LRF channel information */	/* [Satisfies_rte sws 1189] */

typedef uint8                     	ClassifierName_array_t[64];/* String for the classifier name (e.g. "PedNight_ReleaseXYZ") @min:0 @max:255 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 uMaxBlackLevel;
 	uint8 uMaxBitshift;
 	uint16 uMaxSaturatedPixels;
 	uint8 uROIXMin;
 	uint8 uROIYMin;
 	uint8 uROIXMax;
 	uint8 uROIYMax;
 } ContrastNorm_t;			/* contrast normalisation for LRF channel */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fHOGBorderX;
 	float32 fHOGBorderY;
 	uint8 uLRFBorderXPixels;
 	uint8 uLRFBorderYPixels;
 } HOGPostProcessing_t;			/* information for HOG postprocessing (thresholding, scaling for LRF) */

typedef float32                   	afSVMVector_array_t[4096];/* classification vector (only the first "uNumberOfFeatures" elements are valid) @min:-4 @max:4 */	/* [Satisfies_rte sws 1189] */

typedef float32                   	afMLPBiases1_array_t[4];/* in SVM case: SVM bias, only the first value is valid
in MLP case: biases for the hidden neurons (only uNumberOfHiddenNeurons elements are valid) @min:-4 @max:4 */	/* [Satisfies_rte sws 1189] */

typedef float32                   	afMLPWeights1_array_t[25088];/* in SVM case: SVM weights, only uNumberOfFeatures values are valid
in MLP case: weights for the input neurons for each hidden neuron (only uNumberOfFeatures*uNumberOfHiddenNeurons are valid)
[hidden0weight0, hidden0weight1, … hidden0weightN, hidden1weight0, …, hiddenMweightN] @min:-4 @max:4 */	/* [Satisfies_rte sws 1189] */

typedef float32                   	afMLPWeights2_array_t[4];/* in SVM case: not used 
in MLP case: weights for the hidden neurons for the output neuron (uNumberOfHiddenNeurons elements are valid) @min:-4 @max:4 */	/* [Satisfies_rte sws 1189] */

typedef float32                   	afReceptiveFieldBias_array_t[48];/* biases for the receptive Fields (only the first uNumberOfReceptiveFields elements are valid) @min:-1 @max:1 */	/* [Satisfies_rte sws 1189] */

typedef float32                   	afReceptiveFields_array_t[1200];/* list of receptivefields in the following notation:
[rf0y0x0, rf0y0x1, …, rf0y0x4, rf0y1x0, …, rf0y4x4, rf1y0x0, …, rfny4x4]
this means every recptive field uses 25 elements (5x5), only the first uNumberOfReceptiveFields receptive fields are valid @min:-1 @max:1 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uLRFHypSizeX;
 	uint8 uLRFHypSizeY;
 	uint8 uNumberOfReceptiveFields;
 	afReceptiveFields_array_t afReceptiveFields;
 	afReceptiveFieldBias_array_t afReceptiveFieldBias;
 	uint8 uNumberOfHiddenNeurons;
 	uint16 uNumberOfFeatures;
 	afMLPWeights1_array_t afMLPWeights1;
 	afMLPBiases1_array_t afMLPBiases1;
 	afMLPWeights2_array_t afMLPWeights2;
 	float32 fMLPBias2;
 	uint8 uNumberOfChannels;
 } LRF_t;			/* classifier parameters for LRF based classifier */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint8 uNrOfXCells;
 	uint8 uNrOfYCells;
 	eHOGFeatureType_t eHOGFeatureType;
 	uint16 uNumberOfFeatures;
 	afSVMVector_array_t afSVMVector;
 	float32 fSVMBias;
 } HOG_t;			/* classifier parameters for HOG based classifier */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint32 uClassifierVersion;
 	uint8 uClassifierID;
 	ClassifierName_array_t ClassifierName;
 	float32 fMaxTruncationArea;
 	float32 fAspectRatio;
 	HOG_t HOG;
 	HOGPostProcessing_t HOGPostProcessing;
 	LRF_t LRF;
 	ChannelInformation_array_t ChannelInformation;
 	ContrastNorm_t ContrastNorm;
 } Classifier_t;			/* areas in the image for the classifier to search for objects */

typedef Classifier_t              	Classifier_array_t[8];/* areas in the image for the classifier to search for objects */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t Header;
 	uint32 uNrOfClassifiers;
 	Classifier_array_t Classifier;
 } VodcaClassifierDefinition_t;			/* Definition of the Obect Classifiers */

typedef float32                   	fScoreLRFHiddenNeuron_array_t[4];/* score of the hidden neurons of the LRF (after tanh) @min:-1 @max:1 */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 sTopLeftX;
 	sint16 sTopLeftY;
 	sint16 sBottomRightX;
 	sint16 sBottomRightY;
 	uint8 uClassifierID;
 	uint8 uNrOfValidLRFHiddenNeuronScores;
 	float32 fScoreHOG;
 	float32 fScoreLRF;
 	float32 fScoreLRFDisp;
 	fScoreLRFHiddenNeuron_array_t fScoreLRFHiddenNeuron;
 	uint16 uUniquePatchID;
 } LRFResults_t;			/* Results for the LRF Hypotheses */

typedef LRFResults_t              	LRFResults_array_t[512];/* Results for the LRF Hypotheses */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t Header;
 	sint32 sNumResults;
 	LRFResults_array_t LRFResults;
 } VodcaClassifierResults_t;			/* results of the classification process @vaddr:0x31320000 @vaddr_defs: VODCA_MEAS_ID_CLASS_RESULTS @cycleid:VODCA_ENV @vname:VodcaClassifierResults */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 fHOGThresholdForLRF;
 	float32 fLRFThresholdForDispLRF;
 	uint8 uClassifierID;
 } UsedClassifier_t;			/* information about the classifiers to be used for this patch */

typedef UsedClassifier_t          	UsedClassifier_array_t[4];/* information about the classifiers to be used for this patch */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 sTopLeftX;
 	sint16 sTopLeftY;
 	sint16 sBottomRightX;
 	sint16 sBottomRightY;
 	float32 fCellWidthPx;
 	float32 fCellHeightPx;
 	uint16 uImageToClassify;
 	sint16 sValidImageAreaTopLeftX;
 	sint16 sValidImageAreaTopLeftY;
 	sint16 sValidImageAreaBottomRightX;
 	sint16 sValidImageAreaBottomRightY;
 	uint8 uNrOfValidClassifiers;
 	bool8 bAllowMerge;
 	uint16 uUniqueID;
 	UsedClassifier_array_t UsedClassifier;
 } Patches_t;			/* areas for the classifier to search for objects */

typedef Patches_t                 	Patches_array_t[128];/* areas for the classifier to search for objects */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uVersionNumber;
 	SignalHeader_t Header;
 	sint32 sNrOfValidPatches;
 	Patches_array_t Patches;
 } VodcaPatchConfig_t;			/* Hypotheses for Classifier */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ui16_Val;
 	uint16 ui16_Conf;
 } GB_t_BlockageInfo_t;			/* Blockage data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoDataTimeStamp_t uiTimeStamp;
 	uint16 ui16_Val;
 	uint16 ui16_Conf;
 } GB_t_BlockageRawInfo_t;			/* Blockage raw data */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	uint16 ui16_X;
 	uint16 ui16_Y;
 	uint16 ui16_Width;
 	uint16 ui16_Height;
 } GB_t_ImageRoi_t;			/* Image Roi */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	GB_t_eFctId e_FctId;
 	GB_t_eBlockageStatus e_BlockageStatus;
 	uint16 ui16_StatusConf;
 } GB_t_FctBlockage_t;			

typedef GB_t_BlockageInfo_t       	s_Prob_array_t_0[5];/* Radial tiles blockage probability */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 si16_RadTileType;
 	sint16 si16_RadTileIdx;
 	uint16 ui16_D1;
 	uint16 ui16_D2;
 } GB_t_RadTileDefinition_t;			/* 2D definition of a radial tile */

typedef GB_t_RadTileDefinition_t  	as_RadTilesDef_array_t[5];			/* [Satisfies_rte sws 1189] */

typedef GB_t_BlockageRawInfo_t    	s_RawProb_array_t_0[5];/* Radial tiles raw blockage probability */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	GB_t_BlockageInfo_t s_SegProb;
 	s_Prob_array_t_0 s_Prob;
 } GB_t_RadTileBlockageArray_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 si16_RadSegIdxX;
 	sint16 si16_RadSegIdxY;
 	float32 f32_angle1;
 	float32 f32_angle2;
 	as_RadTilesDef_array_t as_RadTilesDef;
 } GB_t_RadSegDefinition_t;			/* 2D definition of a radial segment */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	GB_t_BlockageRawInfo_t s_SegRawProb;
 	s_RawProb_array_t_0 s_RawProb;
 } GB_t_RadTileRawBlockageArray_t;			

typedef GB_t_BlockageInfo_t       	s_Prob_array_t[25];/* Tiles blockage probability filtered in time */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 si16_TileIdxX;
 	sint16 si16_TileIdxY;
 	uint16 ui16_X1;
 	uint16 ui16_X2;
 	uint16 ui16_Y1;
 	uint16 ui16_Y2;
 } GB_t_TileDefinition_t;			/* 2D definition of a tile */

typedef GB_t_TileDefinition_t     	s_Def_array_t[25];/* Tiles definition (2D position in the image) */	/* [Satisfies_rte sws 1189] */

typedef GB_t_BlockageRawInfo_t    	s_RawProb_array_t[25];/* Tiles raw blockage probability */	/* [Satisfies_rte sws 1189] */

typedef GB_t_RadSegDefinition_t   	s_RadDef_array_t[8];/* Radial segments definition (2D position in the image) */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s_Def_array_t s_Def;
 } GB_t_TileDefinitionArray_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s_Prob_array_t s_Prob;
 } GB_t_TileBlockageArray_t;			

typedef GB_t_RadTileBlockageArray_t 	s_SegProb_array_t[8];/* Radial Segment Tiles blockage probability */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s_RadDef_array_t s_RadDef;
 } GB_t_RadSegDefinitionArray_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s_RawProb_array_t s_RawProb;
 } GB_t_TileRawBlockageArray_t;			

typedef GB_t_RadTileRawBlockageArray_t 	s_SegRawProb_array_t[8];/* Radial Segment Tiles raw blockage probability */	/* [Satisfies_rte sws 1189] */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s_SegProb_array_t s_SegProb;
 } GB_t_RadSegBlockageArray_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	s_SegRawProb_array_t s_SegRawProb;
 } GB_t_RadSegRawBlockageArray_t;			

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	AlgoInterfaceVersionNumber_t uiVersionNumber;
 	SignalHeader_t s_SignalHeader;
 	GB_t_ImageRoi_t s_BlockageRoi;
 	GB_t_2DPoint_t s_TilesCenter;
 	GB_t_TileDefinitionArray_t as_TilesDef;
 	GB_t_RadSegDefinitionArray_t as_RadSegDef;
 	GB_t_TileRawBlockageArray_t as_TilesRawBlockage;
 	GB_t_TileBlockageArray_t as_TilesBlockage;
 	GB_t_RadSegRawBlockageArray_t as_RadTilesRawBlockage;
 	GB_t_RadSegBlockageArray_t as_RadTilesBlockage;
 	GB_t_eBlockageStatus ui8_BlockageStatus;
 	GB_t_eStereoBlockageType ui8_StereoBlockageType;
 	GB_t_eWeatherCondition ui8_WeatherCondition;
 	GB_t_eVisibilityRange ui8_VisibilityRange;
 } CB_t_ProvidedOutputs_t;			/* Mono Camera Blockage provided outputs @vaddr:0x20098000, 0x3408D000 @vaddr_defs: CB_MEAS_ID_PROVIDED_OUTPUTS,SCB_MEAS_ID_PROVIDED_OUTPUTS @cycleid:CB_ENV,SCB_ENV @vname:pCbRteOut,pScbRteOut */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint16 s_Real;
 	sint16 s_Imag;
 } t_Complex16;			/* signed 16 bit integer complex */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	sint8 s_Real;
 	sint8 s_Imag;
 } t_Complex8;			/* signed 8 bit integer complex */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_Amplitude;
 	float32 f_Phase;
 } t_ComplexPolarf32;			/* complex float in polar coordinates */

typedef struct 			/* [Satisfies_rte sws 1191] */
{
	float32 f_Real;
 	float32 f_Imag;
 } t_Complexf32;			/* complex float in cartesian coordinates */



/**********************************************/
/* Mode management types                      */
/**/






/**/
/* Per instance memory (PIM)                  */
/**/



/**/
/* internal buffer for implicit communication */
/**/







/**/
/* internal buffer for client server          */
/**/



/**/
/* Calibration (CData,CalPrm)                 */
/**/







#endif

