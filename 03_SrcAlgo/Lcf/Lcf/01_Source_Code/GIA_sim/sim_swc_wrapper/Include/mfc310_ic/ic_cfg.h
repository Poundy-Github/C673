/*
 * ic_cfg.h
 *
 *  Created on: 19.07.2011
 *      Author: uidt3974
 */

#ifndef IC_CFG_H_
#define IC_CFG_H_

#include "glob_type.h"
#include "ic_globdefs.h"
#include "ic_cfg_ext.h"

// ********************************************************************************
// **                           CONFIGURATION SWITCHES                           **
// ********************************************************************************

// Global project-common switches
#define IC_BLACKLEVEL_CALC_ENABLED          0
#define IC_REGISTER_CHECK_ENABLED           1
#define IC_REGISTER_CHECK_I2C_ENABLED       1
#define IC_REGISTER_CHECK_LEFT_ENABLED      1 /* Affects only stereo cameras */
#define IC_NOISECALC_ENABLED                1
#define IC_BIST_ENABLED                     1
#define IC_DATABUS_CHECK_STARTUP_ENABLED    1
#define IC_DATABUS_CHECK_VIA_NOISE_ENABLED  1
#define IC_CYCLIC_COLUMN_CORRECTION_ENABLED 1
#define IC_PROFILING_ENABLED                0 /* Should only be enabled on debug builds */

// Project specific switches
#if (CFG_MFC_MONO_ENTRY == 1)
    // Disable analog test on MFC316
    // NOTE: ATest can also be disabled when IC_e_Init() is called! ATW this is done
    //       for MFC312 with older HW revisions <C0.
    #define IC_ANALOG_TEST_ENABLED          0

    // Disable exposure measurement data output for even frame, is the frame is not used on MFC316
    #define IC_EXPOSURE_EVEN_MEASDATA       0

    // There is no LD on MFC316, so use HLA
    #define IC_ONLINECALIB_USE_LD           0
    #define IC_ONLINECALIB_USE_HLA          1

    // Small imager only has 2-point temperature calibration
    #define IC_TEMPCALIB_USE_FOURPOINT      0
#else
    #define IC_ANALOG_TEST_ENABLED          1

    // Enable exposure measurement data output for even frame
    #define IC_EXPOSURE_EVEN_MEASDATA       1

    // Use LD online calib if available
    #define IC_ONLINECALIB_USE_LD           1
    #define IC_ONLINECALIB_USE_HLA          0

    // Use 4-point temperature calibration for 'big' imager
    #define IC_TEMPCALIB_USE_FOURPOINT      1
#endif

// Test code
// >>>>> !!! DO NOT ENABLE IN RELEASES !!! >>>>>>>>>>>>>>
#define IC_FAKE_EMBEDDED_DATA_DESTRUCTION   0
#define IC_RAMPING_EXPOSURE_TEST            0
#define IC_I2C_LATE_ACK_TEST                0
// <<<<< !!! DO NOT ENABLE IN RELEASES !!! <<<<<<<<<<<<<<

// ********************************************************************************
// **                                GLOBAL STUFF                                **
// ********************************************************************************

// Set sensor type
#if (CFG_MFC_MONO_ENTRY == 1)
    #define ICCFG_SENSOR_ARX550
#else
    #define ICCFG_SENSOR_MT9M025
#endif

// ********************************************************************************
// **                          IMAGER INITIALIZATION                             **
// ********************************************************************************
#define ICCFG_cui8_INIT_IMAGERS_MAXTRIES    3

// This values set the imager output data path slew rate according to hardware requirements
// specification. On Stereo hardware, the right imager has high bus-load (MCU, DSP, FPGA,
// long lanes over ground-plane), so set slew rate control to high. The left imager is only
// connected to the FPGA with short traces, so set medium slew rate on Stereo boards to
// meet EMI limits: 0x9010 (imager default).
//
// According to the spec, the high slew rate for the right/mono imager must be set equal
// in all projects (MFC300, MFC312, MFC316)
#define ICCFG_cui16_IMAGER_DATAPATH_RIGHT 0xFC10
#define ICCFG_cui16_IMAGER_DATAPATH_LEFT  0x9010

// This is the delay time, which will be waited between setting imager  streaming mode to
// 'STREAMING_MODE_EXTTRIGGER' and setting imager trigger pin to HIGH. This is used on
// initial imager frame timing synchronisation.
#define ICCFG_cui32_TRIGGERPIN_DELAY_MS 50000

// ********************************************************************************
// **                              MTS INTERFACE                                 **
// ********************************************************************************

// MTS virtual address for Imager Exposure Control even frame
#define ICCFG_cui32_MeasVirtAddrICExpEven 0x200b0000

// MTS virtual address for Imager Exposure Control odd frame
#define ICCFG_cui32_MeasVirtAddrICExpOdd 0x200b4000

// MTS virtual address for Imager Control Adapter data
#define ICCFG_cui32_MeasVirtAddrIC 0x200bc000

// MTS function/cycle Id
#define ICCFG_cui8_MeasFuncChanId 61

// Magic number which identifies a valid SDL/CDL file
#define ICCFG_cui32_MAGIC_CDLCHECK 123456

// ********************************************************************************
// **                     IMAGER/FRAME OUTPUT SPECIFIC SETTINGS                  **
// ********************************************************************************

// Time of one pixel in microseconds
#define ICCFG_cf32_PixelTimeUs  0.0222222222222f

// Time of one line in microseconds
#define ICCFG_cf32_LineTimeUs (36.6666667f)

// Time of one line in nanoseconds
#define ICCFG_cui32_LineTimeNs 36667u

// Maximum possible value of T2 [lines]
#define ICCFG_cui16_MaxT2lines 42u

// Maximum possible value of T3 [pixelClocks]
#define ICCFG_cui16_MaxT3pixClk 4026

// Number of embedded statistic lines
#define ICCFG_cui16_NumEmbeddedStatLines ((uint16)2)

// Number of embedded statistic lines
#define ICCFG_cui16_NumEmbeddedRegLines ((uint16)2)

// Number of dark rows embedded into the image
#define ICCFG_cui16_NumDarkrows ((uint16)16)

// Number of embedded lines (dark rows, embedded registers) before optical image data
#define ICCFG_cui16_NumEmbeddedLinesPre (ICCFG_cui16_NumDarkrows + ICCFG_cui16_NumEmbeddedRegLines)

// Number of embedded lines (embedded statistics) after optical image data
#define ICCFG_cui16_NumEmbeddedLinesPost ((uint16)2)

// Total number of embedded lines in the image which are not part of the visible/optical image
#define ICCFG_cui16_NumEmbeddedLinesTotal (ICCFG_cui16_NumEmbeddedLinesPre + ICCFG_cui16_NumEmbeddedLinesPost)

// Maximum number of embedded data pixels per line, which include data (max of all embedded data lines)
#define ICCFG_cui16_NumEmbeddedPixelsMax 640

// Number of embedded statistic lines
#define ICCFG_cui16_EmbeddedRegLineStart ((uint16)16)

// Height and width of the active image pixel array
#if defined(ICCFG_SENSOR_MT9M025)
    #define ICCFG_cui16_ActiveImageWidth ((uint16)1288)
    #define ICCFG_cui16_ActiveImageHeight ((uint16)968)
#elif defined(ICCFG_SENSOR_ARX550)
    #define ICCFG_cui16_ActiveImageWidth ((uint16)848)
    #define ICCFG_cui16_ActiveImageHeight ((uint16)638)
#else
    #error "Unknown sensor-type!"
#endif

// Height/length of the frame without taking additional jittering into account (in lines)
#define ICCFG_cui16_FrameHeightTotal ((uint16)822)

// Maximum size of the image including any blanking and embedded data
#define ICCFG_cui16_MaximumFrameHeightTotal ((uint16)2047)

// Maximum width of the image including any blanking and embedded data
#define ICCFG_cui16_MaximumFrameWidthTotal ((uint16)1650)

// Bytes per pixel in image stream from
#define ICCFG_cui16_BytesPerPixel ((uint16)2)

//  Number of histogram values in the imager statistics data
#define ICCFG_cui16_NumHistogramValues ((uint16)244)

// Width and height of a single pixel on the optical active pixel array of the imager
#define ICCFG_cf32_PixelSizeInMeters ((float32)0.00000375f)

// Number of different color planes on the imager pixel array
#define ICCFG_cui16_NUM_COLOR_PLANES 4

// Period of a frame (without jittering taken into account, so its the average value)
#define ICCFG_cui32_FramePeriodUs ((uint32)((float32)ICCFG_cui16_FrameHeightTotal * ICCFG_cf32_LineTimeUs))

// ********************************************************************************
// **                               IC-ROI                                       **
// ********************************************************************************

// NOTE: Position and size of the IC-ROIs have been moved to 'ic_cfg_ext.h' !

// Minimum stage for considering the online calibration to be good enough
#define ICCFG_csi32_MinLDOnlineCalibQuality 2

// Filter constant for the online calibration angles
#define ICCFG_cf32_OnlineCalibFilterDamping 0.999f

// Maximum valid pitch from online calibration (rad)
#define ICCFG_cf32_OnlineCalibPitchMax ((4.0f / 180.0f) * 3.1415f)

// Minimum valid pitch from online calibration (rad)
#define ICCFG_cf32_OnlineCalibPitchMin ((-4.0f / 180.0f) * 3.1415f)

// Angle at which the pitch from relative LD online-cali-filter output is clamped (rad)
#define ICCFG_cf32_OnlineCalibPitchPostFiltClampMax  ((0.0f / 180.0f) * 3.1415f)

// Angle at which the pitch from relative LD online-cali-filter output is clamped (rad)
#define ICCFG_cf32_OnlineCalibPitchPostFiltClampMin ((-2.0f / 180.0f) * 3.1415f)

// Maximum allowed yaw-rate for trusting LD online-pitch
#define ICCFG_cf32_OnlineCalibYawrateMax ((5.5f / 180.0f) * 3.1415f)

// Minimum allowed speed for trusting LD online-pitch (2.777 m/s = 10 km/h)
#define ICCFG_cf32_OnlineCalibSpeedMin (2.777f)

// Filter constant for blacklevel estimation
#define ICCFG_cf32_BlEstimationFilterDamping 0.95f

// Y-Start position of the imager control ROI in degrees above horizon
// -0.013963 = -0.8°
#define ICCFG_cf32_IC_ROI_DESIRED_DELTA_ANGLE_TO_HORIZON (-0.013963f)

// Pixels per radian: 22 pix/degree <=> 1260 pix/rad
#define ICCFG_cf32_PIXELS_PER_RADIAN 1260.5f

// Maximum number of pixels the IC-ROI is allowed to move at bottom outside the frame
#define ICCFG_csi16_ICRoiMaxAllowedPixelsOutsideCroiBottom 100


// ********************************************************************************
// **                                 CROI                                       **
// ********************************************************************************

// First valid (inclusive) row/ciolumn for use as start-row for the CROIs.
// The active pixel array of the MT9M024 has four barrier pixels
// at each edge that should not be used for image data.
#define ICCFG_cui16_CROI_STARTY_MIN 4u
#define ICCFG_cui16_CROI_STARTX_MIN 4u

// Last valid (inclusive) row/column for use as end-row for the CROIs.
// The active pixel array of the MT9M024 has four barrier pixels
// at each edge that should not be used for image data.
#define ICCFG_cui16_CROI_ENDY_MAX   (ICCFG_cui16_ActiveImageHeight - 4u - 1u)
#define ICCFG_cui16_CROI_ENDX_MAX   (ICCFG_cui16_ActiveImageWidth  - 4u - 1u)

// Position and size of the imager output frame (CROI)
//
// !!!!!! NOTE: THIS HAS BEEN MOVED TO EXTERNAL FILE: 'ic_cfg_ext.h' !!!!!!
//
// // Dimensions: MT9M025
// #define ICCFG_cui16_CROI_EVEN_HEIGHT     482u
// #define ICCFG_cui16_CROI_EVEN_WIDTH     1176u
// #define ICCFG_cui16_CROI_ODD_HEIGHT      640u
// #define ICCFG_cui16_CROI_ODD_WIDTH      1176u
//
// // Nominal position of CROI (in case SCN and intrinsic pitches are zero)
// #define ICCFG_cui16_CROI_EVEN_BASE_X      56u
// #define ICCFG_cui16_CROI_EVEN_BASE_Y     232u
// #define ICCFG_cui16_CROI_ODD_BASE_X       56u
// #define ICCFG_cui16_CROI_ODD_BASE_Y      232u

// Total image sizes
#define ICCFG_cui16_TOTAL_HEIGHT_EVEN (ICCFG_cui16_CROI_EVEN_HEIGHT + ICCFG_cui16_NumEmbeddedLinesTotal)
#define ICCFG_cui16_TOTAL_HEIGHT_ODD  (ICCFG_cui16_CROI_ODD_HEIGHT  + ICCFG_cui16_NumEmbeddedLinesTotal)

// Position of embedded data lines (line-number from interface function IC_e_LineFunc)
#define ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD    (ICCFG_cui16_CROI_ODD_HEIGHT  + 18)
#define ICCFG_cui_EMBEDDED_STAT_LINE_START_EVEN   (ICCFG_cui16_CROI_EVEN_HEIGHT + 18)

// ********************************************************************************
// **                        IMAGE SYNC and TIMING                               **
// ********************************************************************************

// Maximum total number of lines the left imager's vsync is allowed to start
// after the right's
#define ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX     25

// Minimum total number of lines the left imager's vsync is allowed to start
// after the right's (due this is negative, it starts _before_ the right)
#define ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN    (-25)

// Maximum number of lines the left imager's vsync can be adjusted within
// one step/frame
#define ICCFG_csi16_RESYNC_LEFT_LINES_STEP_MAX       9

// Minimum number of lines the left imager's vsync can be adjusted within
// one step/frame
#define ICCFG_csi16_RESYNC_LEFT_LINES_STEP_MIN      (-9)

// This is the number of lines the odd image is extended (and even is reduced) to achieve
// a jittering of the even image
#define ICCFG_caui_JITTER_SEQUENCE 0,17,51,102,170,255,85,204,68,221,119,34,238,187,153,136

// Maximum number of frames allowed until the requested image sync is measured by FPGA and
// fed back via StereoDSP/IPC path to the IC
#define ICCFG_cui32_MAX_ALLOWED_SYNC_FEEDBACK_DELAY  10


// ********************************************************************************
// **                             ERROR MANAGEMENT                               **
// ********************************************************************************

// Size of the error-list ringbuffer
#define ICCFG_cui32_ERRORLIST_SIZE  20

// Number of frames for skipping meas-interface releated errors at startup
#define ICCFG_cui32_MeasErrorFramesSkip     30

// Size of DEM extended/optional data (in bytes)
#define ICCFG_cui32_DEM_EXTDATA_SIZE  12

// ********************************************************************************
// **                              TEST FUNCTIONS                                **
// ********************************************************************************

// Position and size of the analog-test ROI that is used at _startup_.
// NOTE: Call from extern (XCP) can define another ROI that's used for analog test.
// NOTE: This is referenced to the RAW image (including embedded data)
#define ICCFG_cui16_ATEST_ROI_STARTX    0                           /* Use whole image width */
#define ICCFG_cui16_ATEST_ROI_STARTY    200
#define ICCFG_cui16_ATEST_ROI_WIDTH     ICCFG_cui16_CROI_ODD_WIDTH  /* Use whole image width */
#define ICCFG_cui16_ATEST_ROI_HEIGHT    200

// Each n'th line is used for calculation of analog test. Higher numbers lower burst
// CPU load and may prevent line-drops
#define ICCFG_cui16_ATEST_ROI_MODULUS   3

// Size of one line copied to external memory buffer when ATest is triggered from extern
// (e.g. in production via XCP). NOTE: This is set to a multiple of 32 bytes as the DMA-Service
// currently only supports multiples of 32-bytes
#define ICCFG_cui16_ATEST_COPY_PIXELSPERLINE    1184

// Line used for testing databus on startup (for evaluation of testpattern)
#define ICCFG_cui16_DATABUSTEST_LINEY   200

// Line used for cyclic testing of lower databus lines by looking for
// all bit-combinations in dark-rows
#define ICCFG_cui16_DATABUSTEST_CYCLIC_LINEY   8

// Number of pixels per line that are analyzed in cyclic databus test
#define ICCFG_cui16_DATABUSTEST_CYCLIC_COLUMNS   (ICCFG_cui16_CROI_ODD_WIDTH)

// Maximum number of frames that are analyzed until the test is considered to be failed.
// Specification requires only detection time <10s ! We have a framerate of 33 fps, so
// use 30 frames to be safe:
#define ICCFG_cui32_DATABUSTEST_CYCLIC_MAXFRAMES  (30)

// The I2C slack is the difference between the frame-valid high edge and the finish-time
// of the part2 I2C transfer (transfer during FV low phase). Tests have shown that for the
// IC-ROI, which is written last, it's ok to finish writing within the Dark-Rows until
// line 16. This does not apply to other registers, which have to be written before FV high
// edge.
//
// With knowledge of this we are allowed to write ~240us (minimum transfer time of IC-ROI)
// into the beginning of next frame.
//
//    T_trans = (1/400kHz) * 9 Bits * 11
//
// 11 is the number of bytes transfered: 1 I2C Addr + 2 FirstRegAddress + 8 RegData.
// Each byte requires 9 bits (8+ACK) and we have an I2C clock of 400 kHz. Adding safety-margin
// yields 200us.
#define ICCFG_si16_I2C_PART2_MIN_SLACK_US    (-200)

// Minimum value of the calculated blacklevel, which is considered to be valid
#define ICCFG_cf32_BLACKLEVEL_PLAUSI_MIN    150.0f

// Maximum value of the calculated blacklevel, which is considered to be valid
#define ICCFG_cf32_BLACKLEVEL_PLAUSI_MAX    195.0f

// ********************************************************************************
// **                     COLUMN NOISE CORRECTION TRIGGER                        **
// ********************************************************************************

// Trigger if this temperature is reached and: We are in standstill or time threshold
// ICCFG_ui32_COLCORR_THRES1_TIME_MSEC reached
#define ICCFG_cf32_COLCORR_THRES1_CELSIUS    10.0f

// Trigger always when this threshold reached
#define ICCFG_cf32_COLCORR_THRES2_CELSIUS    20.0f

// Trigger always after this time if temperature is above threshold 1
#define ICCFG_ui32_COLCORR_THRES1_TIME_MSEC  (20*60*1000) /* 20 Minutes */

// ********************************************************************************
// **                             INPUT DATA CHECKS                              **
// ********************************************************************************

// Timeout for first data reception since IC has been started
#define ICCFG_cui32_INPUTTIMEOUT_FIRSTDATA_US   20000000 /*  20 Seconds      */

// Timeout value
#define ICCFG_cui32_INPUTTIMEOUT_MAXPERIOD_US     125000 /* 125 Milliseconds */

// Time until temperature value is invalidated when there is no new register data available
#define ICCFG_cui32_TEMPERATURE_MAXAGE_US  1000000 /* 1 Second */

#endif /* IC_CFG_H_ */
