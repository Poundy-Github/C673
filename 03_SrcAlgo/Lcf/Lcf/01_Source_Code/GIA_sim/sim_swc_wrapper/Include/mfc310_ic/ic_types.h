//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_types.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:05CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_types
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_types.h
//  LOGIN:           uidt3974  
//  
//  This file stores all global datatypes, which are used within the IC. They are also
//  exported in the interface header file 'ic_interface.h'.
//  
//  As the structure of some datatypes depend on the IC configuration, the file 'ic_cfg.h'
//  is included here.
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 26, Oct 2012  12:06 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_types_H
#define ic_types_H

/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## dependency ic_errcodes */
#include "ic_errcodes.h"
/*## auto_generated */
#include "glob_type.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_types */
/*#[ ignore */
//  This file stores all global datatypes, which are used within the IC. They are also
//  exported in the interface header file 'ic_interface.h'.
//  
//  As the structure of some datatypes depend on the IC configuration, the file 'ic_cfg.h'
//  is included here.
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*#[ type IC_cui16_ATEST_NUM_MAXDEVIATIONS */
#define IC_cui16_ATEST_NUM_MAXDEVIATIONS 5
/*#]*/

/*#[ type IC_cui16_SPECIALADDR_DELAY */
#define IC_cui16_SPECIALADDR_DELAY 0xFFF0
/*#]*/

/*#[ type IC_cui16_RESP_CURVE_NUM_POINTS */
#define IC_cui16_RESP_CURVE_NUM_POINTS 5
/*#]*/

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 IC_E_DCG_STATE;
#define IC_e_DCG_LOW  (IC_E_DCG_STATE)(0)
#define IC_e_DCG_HIGH (IC_E_DCG_STATE)(1)
#else
//  Imager dual conversion gain (DCG) setting
/*#[ type IC_E_DCG_STATE */
typedef enum {
    IC_e_DCG_LOW,
    IC_e_DCG_HIGH
}  IC_E_DCG_STATE;
/*#]*/
#endif

//  Imager analog gain setting
/*#[ type IC_E_ANALOG_GAIN */
typedef enum {
    IC_e_ANALOG_GAIN_1X,
    IC_e_ANALOG_GAIN_2X,
    IC_e_ANALOG_GAIN_4X,
    IC_e_ANALOG_GAIN_8X
}  IC_E_ANALOG_GAIN;
/*#]*/

#if (CFG_USE_COMPACT_ENUMS)
typedef uint8 IC_E_INTRADAY_STATE;
#define IC_e_INTRADAY_STATE_NIGHT (IC_E_INTRADAY_STATE)(0)
#define IC_e_INTRADAY_STATE_DAY   (IC_E_INTRADAY_STATE)(1)
#else
//  Intradaystate of the exposure control.
//  
//  NIGHT means the imager exposure settings are set to NIGHT mode.
//  DAY means the imager exposure settings are set to DAY mode.
//  
//  The meaning of the flags depends on the imager exposure control
//  settings (see ic_cfg_exposure.c).
/*#[ type IC_E_INTRADAY_STATE */
typedef enum {
    IC_e_INTRADAY_STATE_NIGHT,
    IC_e_INTRADAY_STATE_DAY
}  IC_E_INTRADAY_STATE;
/*#]*/
#endif

//  Enumeration of available imagers.
//  
//  !!! WARNING !!! Always keep numbers for RIGHT and LEFT to 0/1,
//  because it's used as index for several arrays!
/*#[ type IC_E_Imager */
typedef enum {
    IC_e_IMAGER_RIGHT = 0,
#if (CFG_MFC_STEREO == 1)
    IC_e_IMAGER_LEFT  = 1,
#endif
    IC_e_IMAGER_ALL   = 2
}  IC_E_Imager;
/*#]*/

//  Enumeration of Frame-Types (even/odd). NOTE: Sometimes the
//  frametypes are also known as short/long, whereas the following
//  mapping applies:
//          even = short
//          odd  = long
/*#[ type IC_E_FRAMETYPE */
typedef enum {
    IC_e_FRAMETYPE_EVEN,
    IC_e_FRAMETYPE_ODD
}  IC_E_FRAMETYPE;
/*#]*/

//  Status of analog test execution
/*#[ type IC_E_ATEST_STATUS */
typedef enum {
    IC_e_ATEST_STATUS_NOT_STARTED,     /* AT has no been started yet          */
    IC_e_ATEST_STATUS_EXECUTING,       /* AT is currently executing           */
    IC_e_ATEST_STATUS_FINISHED_PASSED, /* AT finished executing, test passed  */
    IC_e_ATEST_STATUS_FINISHED_FAILED, /* AT finished executing, test FAILED! */
    IC_e_ATEST_STATUS_ERROR            /* Fatal error occurred during execution. Test not finished! */
}  IC_E_ATEST_STATUS;
/*#]*/

//  Voltage applied to imager analog test PIN during analog test execution.
/*#[ type IC_E_TESTVOLTAGE */
typedef enum {
    IC_e_TESTVOLTAGE_OMV = 0,
    IC_e_TESTVOLTAGE_ATV2 = 1,
    IC_e_TESTVOLTAGE_ATV1 = 2,
    IC_e_TESTVOLTAGE_ATV3 = 3
}  IC_E_TESTVOLTAGE;
/*#]*/

//  Description:  Vehicle motion state (input comming from VDY)
//  Range:        (enum)
//  Resolution:   none
//  Unit:         none
/*#[ type IC_E_VEH_MOTSTATE */
typedef enum {
    IC_e_VEH_MOTSTATE_STANDSTILL,
    IC_e_VEH_MOTSTATE_MOVING
}  IC_E_VEH_MOTSTATE;
/*#]*/

//  Status of a DEM
/*#[ type IC_E_DEMSTATUS */
typedef enum {
    IC_e_DEMSTATUS_NOT_TESTED,
    IC_e_DEMSTATUS_PASSED,
    IC_e_DEMSTATUS_FAILED
}  IC_E_DEMSTATUS;
/*#]*/

//  Definition of image integration time ratios.
//  
//  IMPORTANT: Do NOT change the values of this enum. They must match the values from the
//            imager's register definition (operation mode control register)
/*#[ type IC_E_INTEGR_RATIO */
typedef enum {
    IC_e_INTEGR_RATIO_4  = 0,
    IC_e_INTEGR_RATIO_8  = 1,
    IC_e_INTEGR_RATIO_16 = 2,
    IC_e_INTEGR_RATIO_32 = 3
}  IC_E_INTEGR_RATIO;
/*#]*/

/*#[ type IC_E_ROIID */
typedef enum {
    IC_e_ROIID_EMBEDDED,
    IC_e_ROIID_STATISTIC_EVEN,
    IC_e_ROIID_STATISTIC_ODD,
    IC_e_ROIID_TESTROI,
    IC_e_ROIID__NUM_ENTRIES__
}  IC_E_ROIID;
/*#]*/

//  Description:  Callback to notify end of analog test
//  Range:        (enum)
//  Resolution:   none
//  Unit:         none
/*#[ type IC_Fct_ATestFinishedCb */
typedef void  (* IC_Fct_ATestFinishedCb)(void) ;
/*#]*/

/*## type IC_S_Rect_ui16 */
typedef struct IC_S_Rect_ui16 {
    uint16 ui16_x1;		/*## attribute ui16_x1 */
    uint16 ui16_x2;		/*## attribute ui16_x2 */
    uint16 ui16_y1;		/*## attribute ui16_y1 */
    uint16 ui16_y2;		/*## attribute ui16_y2 */
} IC_S_Rect_ui16;

/*## type IC_S_Croi */
typedef struct IC_S_Croi {
    uint16 ui16_StartX;		/*## attribute ui16_StartX */
    uint16 ui16_StartY;		/*## attribute ui16_StartY */
    uint16 ui16_Width;		/*## attribute ui16_Width */
    uint16 ui16_Height;		/*## attribute ui16_Height */
} IC_S_Croi;

/*## type IC_S_SensorIDs */
typedef struct IC_S_SensorIDs {
    uint64 ui64_SensorFuseId;		/*## attribute ui64_SensorFuseId */
    uint16 ui16_SensorModelId;		/*## attribute ui16_SensorModelId */
    uint8 ui8_SensorRevisionNumber;		/*## attribute ui8_SensorRevisionNumber */
} IC_S_SensorIDs;

/*## type IC_S_CamIntrinsics */
typedef struct IC_S_CamIntrinsics {
    float32 f32_Pitch;		/*## attribute f32_Pitch */
    float32 f32_Yaw;		/*## attribute f32_Yaw */
    uint16 ui16_PrincipalPointY;		/*## attribute ui16_PrincipalPointY */
    uint16 ui16_PrincipalPointX;		/*## attribute ui16_PrincipalPointX */
} IC_S_CamIntrinsics;

/*## type IC_S_CamParam */
typedef struct IC_S_CamParam {
    IC_S_CamIntrinsics s_IntrR;		/*## attribute s_IntrR */
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_S_CamIntrinsics s_IntrL;
    #endif		/*## attribute s_IntrL */
    float32 f32_EOLCalibPitch;		/*## attribute f32_EOLCalibPitch */
    float32 f32_EOLCalibYaw;		/*## attribute f32_EOLCalibYaw */
    float32 f32_CamPitchSCN;		/*## attribute f32_CamPitchSCN */
    float32 f32_GainFactorLR;		/*## attribute f32_GainFactorLR */
    float32 f32_BlacklevelOffset;		/*## attribute f32_BlacklevelOffset */
} IC_S_CamParam;

/*## type IC_S_ImgSyncRequest */
typedef struct IC_S_ImgSyncRequest {
    uint64 ui64_Timestamp;		/*## attribute ui64_Timestamp */
    sint16 si16_ImageSyncOffsetRequested;		/*## attribute si16_ImageSyncOffsetRequested */
} IC_S_ImgSyncRequest;

/*## type IC_S_ImgSyncMeasure */
typedef struct IC_S_ImgSyncMeasure {
    uint64 ui64_Timestamp;		/*## attribute ui64_Timestamp */
    sint16 si16_ImageSyncOffsetMeasured;		/*## attribute si16_ImageSyncOffsetMeasured */
} IC_S_ImgSyncMeasure;

/*## type IC_S_EmbeddedRegData */
typedef struct IC_S_EmbeddedRegData {
    uint64 ui64_FrameTimestamp_us;		/*## attribute ui64_FrameTimestamp_us */
    uint16 ui16_ExposureTimeT1_lines;		/*## attribute ui16_ExposureTimeT1_lines */
    uint16 ui16_ExposureTimeT1_us;		/*## attribute ui16_ExposureTimeT1_us */
    uint16 ui16_ExposureTimeT2_us;		/*## attribute ui16_ExposureTimeT2_us */
    uint16 ui16_ExposureTimeT3_us;		/*## attribute ui16_ExposureTimeT3_us */
    uint16 ui16_ExposureTimeTotal_us;		/*## attribute ui16_ExposureTimeTotal_us */
    uint16 ui16_FrameCounter;		/*## attribute ui16_FrameCounter */
    IC_E_DCG_STATE e_DcgState;		/*## attribute e_DcgState */
    IC_E_ANALOG_GAIN e_AnalogGain;		/*## attribute e_AnalogGain */
} IC_S_EmbeddedRegData;

/*## type IC_S_EmbeddedStatData */
typedef struct IC_S_EmbeddedStatData {
    float32 f32_PercLowEnd;		/*## attribute f32_PercLowEnd */
    uint16 ui16_FrameCounter;		/*## attribute ui16_FrameCounter */
    uint16 ui16_FrameId;		/*## attribute ui16_FrameId */
    uint32 ui32_LowEndMean;		/*## attribute ui32_LowEndMean */
    uint32 ui32_LumaMean;		/*## attribute ui32_LumaMean */
} IC_S_EmbeddedStatData;

/*## type IC_S_Roi */
typedef struct IC_S_Roi {
    uint16 ui16_StartX;		/*## attribute ui16_StartX */
    uint16 ui16_StartY;		/*## attribute ui16_StartY */
    uint16 ui16_Width;		/*## attribute ui16_Width */
    uint16 ui16_Height;		/*## attribute ui16_Height */
} IC_S_Roi;

/*## type IC_S_RegDataPair */
typedef struct IC_S_RegDataPair {
    uint16 ui16_Addr;		/*## attribute ui16_Addr */
    uint16 ui16_Data;		/*## attribute ui16_Data */
} IC_S_RegDataPair;

/*## type IC_S_LdOnlineCalib */
typedef struct IC_S_LdOnlineCalib {
    uint64 ui64_Timestamp;		/*## attribute ui64_Timestamp */
    float32 f32_ACPitch;		/*## attribute f32_ACPitch */
    float32 f32_ACYaw;		/*## attribute f32_ACYaw */
    float32 f32_OnlinePitch;		/*## attribute f32_OnlinePitch */
    float32 f32_OnlineYaw;		/*## attribute f32_OnlineYaw */
    sint32 si32_ACYawStage;		/*## attribute si32_ACYawStage */
    sint32 si32_ACPitchStage;		/*## attribute si32_ACPitchStage */
    sint32 si32_AvailableLeft;		/*## attribute si32_AvailableLeft */
    sint32 si32_AvailableRight;		/*## attribute si32_AvailableRight */
    sint32 si32_ConstructionSite;		/*## attribute si32_ConstructionSite */
} IC_S_LdOnlineCalib;

/*## type IC_S_HlaOnlineCalib */
typedef struct IC_S_HlaOnlineCalib {
    //  Description:   HLA Online Calibration Pitch
    //  Range:         -0.087 - 0.087
    //  Resolution:    none
    //  Unit:          rad
    float32 f32_Pitch;		/*## attribute f32_Pitch */
    //  Description:   HLA Online Calibration Roll
    //  Range:         -0.087 - 0.087
    //  Resolution:    none
    //  Unit:          rad
    float32 f32_Roll;		/*## attribute f32_Roll */
    //  Description:   HLA Online Calibration Yaw
    //  Range:         -0.087 - 0.087
    //  Resolution:    none
    //  Unit:          rad
    float32 f32_Yaw;		/*## attribute f32_Yaw */
} IC_S_HlaOnlineCalib;

/*## type IC_S_VehicleDyn */
typedef struct IC_S_VehicleDyn {
    uint64 ui64_Timestamp;		/*## attribute ui64_Timestamp */
    float32 f32_YawRate;		/*## attribute f32_YawRate */
    float32 f32_Velocity;		/*## attribute f32_Velocity */
    IC_E_VEH_MOTSTATE e_MotionState;		/*## attribute e_MotionState */
} IC_S_VehicleDyn;

/*## type IC_S_RegTransfResp */
typedef struct IC_S_RegTransfResp {
    uint64 ui64_Timestamp;		/*## attribute ui64_Timestamp */
    uint16 ui16_SequenceCounter;		/*## attribute ui16_SequenceCounter */
    uint16 ui16_ResponseCode;		/*## attribute ui16_ResponseCode */
    uint16 * paui16_Registers;		/*## attribute paui16_Registers */
} IC_S_RegTransfResp;

/*## type IC_S_RegTransfReq */
typedef struct IC_S_RegTransfReq {
    uint16 ui16_SeqCounter;		/*## attribute ui16_SeqCounter */
    uint16 ui16_NumRegisters;		/*## attribute ui16_NumRegisters */
    uint16 ui16_RegistersetChangedCnt;		/*## attribute ui16_RegistersetChangedCnt */
    uint16 * pui16_Registers;		/*## attribute pui16_Registers */
    boolean b_RequestValid;		/*## attribute b_RequestValid */
} IC_S_RegTransfReq;

/*## type IC_S_ATestResults */
typedef struct IC_S_ATestResults {
    uint64 ui64_ImagerFuseId;		/*## attribute ui64_ImagerFuseId */
    uint16 aui16_HighestDeviationValues[IC_cui16_ATEST_NUM_MAXDEVIATIONS];		/*## attribute aui16_HighestDeviationValues */
    uint16 aui16_HighestDeviationPositions[IC_cui16_ATEST_NUM_MAXDEVIATIONS];		/*## attribute aui16_HighestDeviationPositions */
    uint16 ui16_RoiStartX;		/*## attribute ui16_RoiStartX */
    uint16 ui16_RoiStartY;		/*## attribute ui16_RoiStartY */
    uint16 ui16_RoiWidth;		/*## attribute ui16_RoiWidth */
    uint16 ui16_RoiHeight;		/*## attribute ui16_RoiHeight */
    uint16 ui16_RoiStepsizeY;		/*## attribute ui16_RoiStepsizeY */
    uint16 ui16_ATV1_mV;		/*## attribute ui16_ATV1_mV */
    uint16 ui16_ATV3_mV;		/*## attribute ui16_ATV3_mV */
    uint16 ui16_MeanATV1_1xGain;		/*## attribute ui16_MeanATV1_1xGain */
    uint16 ui16_MeanATV1_2xGain;		/*## attribute ui16_MeanATV1_2xGain */
    uint16 ui16_MeanATV3_1xGain;		/*## attribute ui16_MeanATV3_1xGain */
    IC_E_ATEST_STATUS e_TestResult;		/*## attribute e_TestResult */
    boolean b_ColumnCheckPassed;		/*## attribute b_ColumnCheckPassed */
} IC_S_ATestResults;

/*## type IC_S_ATestRefValues */
typedef struct IC_S_ATestRefValues {
    uint16 ui16_ATV1_mV;		/*## attribute ui16_ATV1_mV */
    uint16 ui16_ATV3_mV;		/*## attribute ui16_ATV3_mV */
    uint16 ui16_MeanATV1_1x_LinNorm;		/*## attribute ui16_MeanATV1_1x_LinNorm */
    uint16 ui16_MeanATV1_2x_LinNorm;		/*## attribute ui16_MeanATV1_2x_LinNorm */
    uint16 ui16_MeanATV3_1x_LinNorm;		/*## attribute ui16_MeanATV3_1x_LinNorm */
} IC_S_ATestRefValues;

/*## type IC_S_ATestMaxTols */
typedef struct IC_S_ATestMaxTols {
    //  Tolerance of the mean with 1xGain and ATV1 voltage setting
    float32 f32_MeanATV1_1xGain;		/*## attribute f32_MeanATV1_1xGain */
    //  Tolerance of the mean with 2xGain and ATV1 voltage setting
    float32 f32_MeanATV1_2xGain;		/*## attribute f32_MeanATV1_2xGain */
    //  Tolerance of the mean with 1xGain and ATV3 voltage setting
    float32 f32_MeanATV3_1xGain;		/*## attribute f32_MeanATV3_1xGain */
    float32 f32_ColMeanATV1_1xGain;		/*## attribute f32_ColMeanATV1_1xGain */
    float32 f32_ColMeanATV1_2xGain;		/*## attribute f32_ColMeanATV1_2xGain */
    float32 f32_ColMeanATV3_1xGain;		/*## attribute f32_ColMeanATV3_1xGain */
    float32 f32_RatioATV3_1xGain;		/*## attribute f32_RatioATV3_1xGain */
    float32 f32_RatioATV1_2xGain;		/*## attribute f32_RatioATV1_2xGain */
} IC_S_ATestMaxTols;

//  Paramters for analog test image RAW data acquisition. A buffer can be supplied which
//  stores image data which have been captured during analog test. The
/*## type IC_S_ATestAcquParams */
typedef struct IC_S_ATestAcquParams {
    //  Embedded data and 'ui16_NumLinesToAcquire' of image data is copied to
    //  this buffer when analog test is executed. This is done for all test-frames
    //  (atw: 3 frames). A nullpointer disables this feature.
    uint16 * pui16_RoiBuffer;		/*## attribute pui16_RoiBuffer */
    //  Description:  Size of pui16_RoiBuffer
    //  Range:        0-0xFFFFFFFF
    //  Resolution:   1
    //  Unit:         bytes
    uint32 ui32_BuffSizeBytes;		/*## attribute ui32_BuffSizeBytes */
    //  Description:  Number of active image lines per image to copy into ROI-Buffer
    //                (excluding embedded data!)
    //  Range:        0-0xFFFF
    //  Resolution:   1
    //  Unit:         lines
    uint16 ui16_NumLinesToAcquire;		/*## attribute ui16_NumLinesToAcquire */
} IC_S_ATestAcquParams;

/*## type IC_S_ATestExternParams */
typedef struct IC_S_ATestExternParams {
    //  Reference voltages and grayvalues for analog test
    IC_S_ATestRefValues s_ReferenceValues;		/*## attribute s_ReferenceValues */
    //  Parameters for acquiring pixel/embedded-data from the analog test images
    IC_S_ATestAcquParams s_AcquParameters;		/*## attribute s_AcquParameters */
    //  The ROI starting-line and height where the analog test starts calculation.
    //  It's referenced to the RAW-Image (including embedded data)
    uint16 ui16_RoiStartY;		/*## attribute ui16_RoiStartY */
    uint16 ui16_RoiHeight;		/*## attribute ui16_RoiHeight */
    //  Each 'ui16_RoiStepsizeY' line is actually used for calculation. The whole
    //  width is used, so it's not possible to set startX and width.
    uint16 ui16_RoiStepsizeY;		/*## attribute ui16_RoiStepsizeY */
    //  This function is called when analog test is finished
    IC_Fct_ATestFinishedCb pfct_FinishedCb;		/*## attribute pfct_FinishedCb */
} IC_S_ATestExternParams;

/*## type IRCC_S_PPARs */
typedef struct IRCC_S_PPARs {
    float32 f32_ACT_R1;		/*## attribute f32_ACT_R1 */
    float32 f32_ACT_R2;		/*## attribute f32_ACT_R2 */
    float32 f32_Analog_Gain;		/*## attribute f32_Analog_Gain */
    float32 f32_DCG_Factor;		/*## attribute f32_DCG_Factor */
    float32 f32_Digital_Gain;		/*## attribute f32_Digital_Gain */
    float32 f32_T1;		/*## attribute f32_T1 */
    float32 f32_X_BL_0;		/*## attribute f32_X_BL_0 */
    float32 f32_X_Meas_1500;		/*## attribute f32_X_Meas_1500 */
    float32 f32_X_Meas_2500;		/*## attribute f32_X_Meas_2500 */
    float32 f32_X_Meas_3500;		/*## attribute f32_X_Meas_3500 */
    float32 f32_Y_BL_0;		/*## attribute f32_Y_BL_0 */
    float32 f32_Y_Meas_1500;		/*## attribute f32_Y_Meas_1500 */
    float32 f32_Y_Meas_2500;		/*## attribute f32_Y_Meas_2500 */
    float32 f32_Y_Meas_3500;		/*## attribute f32_Y_Meas_3500 */
    float32 f32_RatioRedGreen;		/*## attribute f32_RatioRedGreen */
    float32 f32_RatioBlueGreen;		/*## attribute f32_RatioBlueGreen */
    uint16 ui16_DCG_State;		/*## attribute ui16_DCG_State */
    uint8 ui8_ResponseCurveFormIndex;		/*## attribute ui8_ResponseCurveFormIndex */
} IRCC_S_PPARs;

/*## type IRCC_S_ResponseCurve */
typedef struct IRCC_S_ResponseCurve {
    float32 f32_ActualSlopeR1;		/*## attribute f32_ActualSlopeR1 */
    float32 f32_ActualSlopeR2;		/*## attribute f32_ActualSlopeR2 */
    float32 f32_BrightnessR[IC_cui16_RESP_CURVE_NUM_POINTS];		/*## attribute f32_BrightnessR */
    float32 f32_BrightnessG[IC_cui16_RESP_CURVE_NUM_POINTS];		/*## attribute f32_BrightnessG */
    float32 f32_BrightnessB[IC_cui16_RESP_CURVE_NUM_POINTS];		/*## attribute f32_BrightnessB */
    float32 f32_BrightnessGAtGrey512;		/*## attribute f32_BrightnessGAtGrey512 */
    float32 f32_TotalGain;		/*## attribute f32_TotalGain */
    uint16 ui16_BlackLevel_0;		/*## attribute ui16_BlackLevel_0 */
    uint16 ui16_BlackLevel_1;		/*## attribute ui16_BlackLevel_1 */
    uint16 ui16_BlackLevel_2;		/*## attribute ui16_BlackLevel_2 */
    uint16 ui16_GreyValues[IC_cui16_RESP_CURVE_NUM_POINTS];		/*## attribute ui16_GreyValues */
    uint16 ui16_NumSupportPoints;		/*## attribute ui16_NumSupportPoints */
    uint16 ui16_RequestedSlopeR1;		/*## attribute ui16_RequestedSlopeR1 */
    uint16 ui16_RequestedSlopeR2;		/*## attribute ui16_RequestedSlopeR2 */
} IRCC_S_ResponseCurve;

/*## type IC_S_StaticInput */
typedef struct IC_S_StaticInput {
    //  Extrinsic and intrinsic static camera parameters
    IC_S_CamParam s_CamParam;		/*## attribute s_CamParam */
    IRCC_S_PPARs s_IrccPPars;		/*## attribute s_IrccPPars */
    #if (IC_ANALOG_TEST_ENABLED == 1)
    IC_S_ATestRefValues s_AnalogTestRefValues;
    #endif		/*## attribute s_AnalogTestRefValues */
} IC_S_StaticInput;

/*## type IC_S_Input */
typedef struct IC_S_Input {
    IC_S_ImgSyncRequest s_ImagerSyncReq;		/*## attribute s_ImagerSyncReq */
    IC_S_ImgSyncMeasure s_ImagerSyncMeas;		/*## attribute s_ImagerSyncMeas */
    #if (IC_ONLINECALIB_USE_LD == 1)
    IC_S_LdOnlineCalib s_LdOnlineCalib;
    #endif		/*## attribute s_LdOnlineCalib */
    #if (IC_ONLINECALIB_USE_HLA == 1)
    IC_S_HlaOnlineCalib s_HlaOnlineCalib;
    #endif		/*## attribute s_HlaOnlineCalib */
    IC_S_VehicleDyn s_VehicleDyn;		/*## attribute s_VehicleDyn */
    IC_S_RegTransfResp s_RegTransfResponse;		/*## attribute s_RegTransfResponse */
    boolean b_AlgosNotAvailable;		/*## attribute b_AlgosNotAvailable */
    boolean b_DSPNotAvailable;		/*## attribute b_DSPNotAvailable */
} IC_S_Input;

/*## type IC_S_DtcExtData */
typedef struct IC_S_DtcExtData {
    uint16 ui16_DemEventId;		/*## attribute ui16_DemEventId */
    IC_E_DEM e_IcDemId;		/*## attribute e_IcDemId */
    uint8 ui8_Reserved;		/*## attribute ui8_Reserved */
} IC_S_DtcExtData;

/*#[ type IC_S_DemExtDataIcState */
typedef struct
{
  uint8 ui2_Reserved  : 2;
  uint8 ui1_FrameType : 1;
  uint8 ui1_SubState  : 1;
  uint8 ui4_State     : 4;
} IC_S_DemExtDataIcState;
/*#]*/

/*## type IC_S_DemExtData */
typedef struct IC_S_DemExtData {
    IC_E_ERROR e_ErrCode;		/*## attribute e_ErrCode */
    uint8 ui8_Reserved;		/*## attribute ui8_Reserved */
    uint16 ui16_LineNum;		/*## attribute ui16_LineNum */
    sint32 si32_Hint;		/*## attribute si32_Hint */
    uint16 ui16_FrameCtr;		/*## attribute ui16_FrameCtr */
    sint8 si8_TempDegree;		/*## attribute si8_TempDegree */
    IC_S_DemExtDataIcState s_IcState;		/*## attribute s_IcState */
} IC_S_DemExtData;

//  Union is only used for optional debug data and makes viewing DEM/DTC data
//  in the debugger easier, so suppress QAC warning:
//  PRQA S 0750 2
/*## type IC_Un_DemDtcExtData */
typedef union IC_Un_DemDtcExtData {
    uint8 aui8_Bytes[ICCFG_cui32_DEM_EXTDATA_SIZE];		/*## attribute aui8_Bytes */
    IC_S_DemExtData s_DemExt;		/*## attribute s_DemExt */
    IC_S_DtcExtData s_DtcExt;		/*## attribute s_DtcExt */
} IC_Un_DemDtcExtData;

/*## type IC_S_Histogram */
typedef struct IC_S_Histogram {
    uint32 aui32_Bins[ICCFG_cui16_NumHistogramValues];		/*## attribute aui32_Bins */
} IC_S_Histogram;

/*## type IC_S_HistogramWeights */
typedef struct IC_S_HistogramWeights {
    uint16 aui16_Weights[ICCFG_cui16_NumHistogramValues];		/*## attribute aui16_Weights */
} IC_S_HistogramWeights;

/*## type IC_S_HistogramBinParams */
typedef struct IC_S_HistogramBinParams {
    uint32 aui32_CenterValue[ICCFG_cui16_NumHistogramValues];		/*## attribute aui32_CenterValue */
} IC_S_HistogramBinParams;

/*## type IC_S_ImageDataContainer */
typedef struct IC_S_ImageDataContainer {
    IC_S_EmbeddedRegData s_EmbeddedData;		/*## attribute s_EmbeddedData */
    IC_S_EmbeddedStatData s_StatisticsData;		/*## attribute s_StatisticsData */
    IC_S_Histogram s_HistogramData;		/*## attribute s_HistogramData */
    IC_E_FRAMETYPE e_FrameType;		/*## attribute e_FrameType */
} IC_S_ImageDataContainer;

/*#[ type IC_E_TRANSFMODE */
typedef enum
{
    IC_e_TRANSFMODE_RX,
    IC_e_TRANSFMODE_TX
}  IC_E_TRANSFMODE;
/*#]*/

/*## type IC_S_RegTransExtResult */
typedef struct IC_S_RegTransExtResult {
    uint16 ui16_RegAddress;		/*## attribute ui16_RegAddress */
    uint16 ui16_RegValue;		/*## attribute ui16_RegValue */
    IC_E_Imager e_Imager;		/*## attribute e_Imager */
    boolean b_Done;		/*## attribute b_Done */
    boolean b_Error;		/*## attribute b_Error */
} IC_S_RegTransExtResult;


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*## package Ic_Pkg */

/*## class TopLevel::ic_types */

#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_types.h
*********************************************************************/
