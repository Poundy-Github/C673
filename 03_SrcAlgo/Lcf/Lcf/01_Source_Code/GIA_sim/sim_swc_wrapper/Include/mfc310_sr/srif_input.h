/*! \file **********************************************************************

  COMPANY:           Continental, A.D.C. GmbH

  COMPONENT:         SR - sign recognition

  MODULNAME:         srif_input.h

  DESCRIPTION:       @brief input data interface of SR component

  CREATION DATE:     02.03.2010

  VERSION:           $Revision: 1.1 $

  CHANGES:

  ---*/ /*---

 CHANGE:                 $Log: srif_input.h  $
 CHANGE:                 Revision 1.1 2021/12/13 17:26:18CET Wang, David (Wangd3) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
 CHANGE:                 Revision 1.0 2017/03/03 10:37:24CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_sr/project.pj
 CHANGE:                 Revision 1.1 2014/03/13 15:12:54CET Sorge, Sven (uidg3181) 
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_sr/project.pj
 CHANGE:                 Revision 1.30 2012/05/05 12:03:33CEST Kristensen, Steen (kristensens) 
 CHANGE:                 added region code to SR input. Not used internally yet.
 CHANGE:                 --- Added comments ---  kristensens [May 5, 2012 12:03:33 PM CEST]
 CHANGE:                 Change Package : 116147:1 http://mks-psad:7002/im/viewissue?selection=116147
 CHANGE:                 Revision 1.29 2012/01/23 17:24:51CET Kristensen, Steen (kristensens) 
 CHANGE:                 added variable sign position to input
 CHANGE:                 Revision 1.28 2011/09/20 09:56:23CEST Zobel Matthias (zobelm) (zobelm) 
 CHANGE:                 - updated doxygen comments
 CHANGE:                 --- Added comments ---  zobelm [Sep 20, 2011 9:56:24 AM CEST]
 CHANGE:                 Change Package : 78978:1 http://mks-psad:7002/im/viewissue?selection=78978
 CHANGE:                 Revision 1.27 2011/08/30 22:24:10CEST Kristensen Steen (kristensens) (kristensens) 
 CHANGE:                 added reset counter to SR input. Validation, mapping to internal and unit tests done, signal not yet used internally.
 CHANGE:                 --- Added comments ---  kristensens [Aug 30, 2011 10:24:11 PM CEST]
 CHANGE:                 Change Package : 75043:1 http://mks-psad:7002/im/viewissue?selection=75043
 CHANGE:                 Revision 1.26 2011/07/06 10:33:59CEST Kristensen Steen (kristensens) (kristensens) 
 CHANGE:                 removed yaw rate offset from SR input, SR now becomes offset-compensated yaw rate
 CHANGE:                 Revision 1.25 2011/06/01 16:30:50CEST Kristensen Steen (kristensens) (kristensens) 
 CHANGE:                 finished input checking and internal error monitoring, unit tests still pending
 CHANGE:                 --- Added comments ---  kristensens [Jun 1, 2011 4:30:50 PM CEST]
 CHANGE:                 Change Package : 65224:2 http://mks-psad:7002/im/viewissue?selection=65224
 CHANGE:                 Revision 1.24 2011/05/26 11:38:33CEST Roth Axel (rotha1) (rotha1) 
 CHANGE:                 - added debug code to calculate additional IAX cutouts (should NOT affect ECU code)
 CHANGE:                 --- Added comments ---  rotha1 [May 26, 2011 11:38:33 AM CEST]
 CHANGE:                 Change Package : 54002:1 http://mks-psad:7002/im/viewissue?selection=54002
 CHANGE:                 Revision 1.23 2011/05/11 09:04:19CEST Kristensen Steen (kristensens) (kristensens) 
 CHANGE:                 first part of input validation, not done
 CHANGE:                 --- Added comments ---  kristensens [May 11, 2011 9:04:19 AM CEST]
 CHANGE:                 Change Package : 65224:2 http://mks-psad:7002/im/viewissue?selection=65224
 CHANGE:                 Revision 1.22 2011/03/23 08:58:15CET Kristensen Steen (kristensens) (kristensens) 
 CHANGE:                 added comment regarding signalling of contexts
 CHANGE:                 --- Added comments ---  kristensens [Mar 23, 2011 8:58:15 AM CET]
 CHANGE:                 Change Package : 62302:1 http://mks-psad:7002/im/viewissue?selection=62302
 CHANGE:                 Revision 1.21 2011/03/22 16:04:30CET Kristensen Steen (kristensens) (kristensens) 
 CHANGE:                 added context flags for residential area ("living street") and for changeable signs without outer circle
 CHANGE:                 --- Added comments ---  kristensens [Mar 22, 2011 4:04:30 PM CET]
 CHANGE:                 Change Package : 62302:1 http://mks-psad:7002/im/viewissue?selection=62302
 CHANGE:                 Revision 1.20 2011/03/11 11:13:33CET Zobel Matthias (zobelm) (zobelm) 
 CHANGE:                 - kernel side preparations for CR#61377 (new imager setup introduced for full frame processing during simulations)
 CHANGE:                 --- Added comments ---  zobelm [Mar 11, 2011 11:13:33 AM CET]
 CHANGE:                 Change Package : 61378:1 http://mks-psad:7002/im/viewissue?selection=61378
 CHANGE:                 Revision 1.19 2011/03/01 14:31:33CET Mari Hilario Joan (uidk7689) (uidk7689) 
 CHANGE:                 - #elif removed due to K&R incompatibility with lint
 CHANGE:                 - macro SR_STRUCT_ALIGN introduced to account for align diffs between ARM and DSP
 CHANGE:                 --- Added comments ---  uidk7689 [Mar 1, 2011 2:31:34 PM CET]
 CHANGE:                 Change Package : 57378:3 http://mks-psad:7002/im/viewissue?selection=57378
 CHANGE:                 Revision 1.18 2011/01/26 17:48:52CET Axel Roth (rotha1) 
 CHANGE:                 - added synchronization data for simulation
 CHANGE:                 --- Added comments ---  rotha1 [Jan 26, 2011 5:48:52 PM CET]
 CHANGE:                 Change Package : 57979:1 http://mks-psad:7002/im/viewissue?selection=57979
 CHANGE:                 Revision 1.17 2010/11/30 16:38:42MEZ Axel Roth (rotha1) 
 CHANGE:                 - Added cycleTimestamp to SRIFInput_t
 CHANGE:                 --- Added comments ---  rotha1 [Nov 30, 2010 4:38:42 PM CET]
 CHANGE:                 Change Package : 53985:1 http://mks-psad:7002/im/viewissue?selection=53985
 CHANGE:                 Revision 1.16 2010/09/10 18:04:18MESZ Matthias Zobel (zobelm) 
 CHANGE:                 - changed from fixed roi to floating roi
 CHANGE:                 - added fake output mode
 CHANGE:                 --- Added comments ---  zobelm [Sep 10, 2010 6:04:19 PM CEST]
 CHANGE:                 Change Package : 46267:1 http://mks-psad:7002/im/viewissue?selection=46267
 CHANGE:                 Revision 1.15 2010/08/26 15:58:27CEST Matthias Zobel (zobelm) 
 CHANGE:                 - implemented "Freeze-And-Return" requirement
 CHANGE:                 --- Added comments ---  zobelm [Aug 26, 2010 3:58:28 PM CEST]
 CHANGE:                 Change Package : 50363:1 http://mks-psad:7002/im/viewissue?selection=50363
 CHANGE:                 Revision 1.14 2010/07/07 16:11:45CEST mzobel 
 CHANGE:                 - updated SR interface
 CHANGE:                 --- Added comments ---  mzobel [2010/07/07 14:11:45Z]
 CHANGE:                 Change Package : 45244:3 http://LISS014:6001/im/viewissue?selection=45244
 CHANGE:                 Revision 1.13 2010/07/06 16:50:40CEST mzobel 
 CHANGE:                 - type Sceme -> Scheme corrected
 CHANGE:                 --- Added comments ---  mzobel [2010/07/06 14:50:41Z]
 CHANGE:                 Change Package : 45244:3 http://LISS014:6001/im/viewissue?selection=45244
 CHANGE:                 Revision 1.12 2010/04/13 11:04:08CEST mzobel 
 CHANGE:                 - adapted to use sr_glob_type.h instead of glob_type.he
 CHANGE:                 - many minor corrections
 CHANGE:                 --- Added comments ---  mzobel [2010/04/13 09:04:09Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.11 2010/04/12 08:47:31CEST mzobel 
 CHANGE:                 - modifications for implementing sr visualization
 CHANGE:                 - removed dependencies from glob to use onlysr_glob_type.h
 CHANGE:                 --- Added comments ---  mzobel [2010/04/12 06:47:31Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.10 2010/04/06 13:59:27CEST mzobel 
 CHANGE:                 - replaced CRC32 checksum calculation (using former SR version)
 CHANGE:                 - minor textual changes in interface definitions
 CHANGE:                 --- Added comments ---  mzobel [2010/04/06 11:59:27Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.9 2010/03/31 11:38:48CEST mzobel 
 CHANGE:                 - InputConfig and Input are now const to sr kernel and part of srif-state
 CHANGE:                 - added srif config file with option to enabled/disable expensive memory checksum tests
 CHANGE:                 --- Added comments ---  mzobel [2010/03/31 09:38:49Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.8 2010/03/30 14:07:17CEST mzobel 
 CHANGE:                 - integration of sr.lib into simv3 framework (compiles)
 CHANGE:                 --- Added comments ---  mzobel [2010/03/30 12:07:18Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.7 2010/03/25 09:24:24CET mzobel 
 CHANGE:                 - filled input wrapping routine
 CHANGE:                 --- Added comments ---  mzobel [2010/03/25 08:24:24Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.6 2010/03/17 13:08:10CET mzobel 
 CHANGE:                 - inputconfig wrapper implemented
 CHANGE:                 --- Added comments ---  mzobel [2010/03/17 12:08:10Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.5 2010/03/16 18:53:21CET mzobel 
 CHANGE:                 - adaptations to new srif/sr interface
 CHANGE:                 --- Added comments ---  mzobel [2010/03/16 17:53:21Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.4 2010/03/08 18:10:08CET mzobel 
 CHANGE:                 - added input wrapper
 CHANGE:                 - persistent state are abstract to srif
 CHANGE:                 - put SRState to seperate .h file
 CHANGE:                 --- Added comments ---  mzobel [2010/03/08 17:10:08Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.3 2010/03/08 15:15:12CET mzobel 
 CHANGE:                 - reworked implementation of SRIFInit()
 CHANGE:                 --- Added comments ---  mzobel [2010/03/08 14:15:12Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.2 2010/03/05 10:15:25CET mzobel 
 CHANGE:                 - corrected line endings
 CHANGE:                 --- Added comments ---  mzobel [2010/03/05 09:15:25Z]
 CHANGE:                 Change Package : 36262:3 http://LISS014:6001/im/viewissue?selection=36262
 CHANGE:                 Revision 1.1 2010/03/02 17:21:52CET mzobel
 CHANGE:                 Initial revision
 CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SR_SignRecognition/04_Engineering/01_Source_Code/algo/sr/srif/project.pj
**************************************************************************** */

#ifndef _SRIF_INPUT_H
#define _SRIF_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

/*===========================*/
/*        INCLUDES           */
/*===========================*/
#include "sr_glob_type.h"

/*===========================*/
/*        DEFINES            */
/*===========================*/

#if defined(__TMS470__) /*!< macro for equal structure alignment on ARM and DSP */
#define SR_STRUCT_ALIGN(ui_ByteAlign) __attribute__ ((aligned (ui_ByteAlign)))
#else
#define SR_STRUCT_ALIGN(ui_ByteAlign)
#endif

#define SRIF_IMAGER_SERIAL_STR_LEN              64  /*!< max length of imager identification string */
#define SRIF_ECU_SERIAL_STR_LEN                 64  /*!< max length of ECU identification string */
#define SRIF_IMAGER_RC_MAX_NUM_SUPPORT_POINTS   32  /*!< max number of support points for imager response curve */
#define SRIF_IMAGER_RC_MIN_NUM_SUPPORT_POINTS    2  /*!< min number of support points for imager response curve */

/*===========================*/
/*        TYPEDEFS           */
/*===========================*/

/*!
 * state of an input signal
 */
typedef enum
{
  SRIF_INPUT_SIGNAL_STATE_INIT    = 0,  /*!< input is on initialization value, i.e., never set */
  SRIF_INPUT_SIGNAL_STATE_OK      = 1,  /*!< input is set and is OK */
  SRIF_INPUT_SIGNAL_STATE_NOT_OK  = 2   /*!< input is *not* OK. */
} SRIFInputSignalState_t;

/* ------------------ */
/* ECU config section */
/* ------------------ */

/*!
 * ECU configuration information
 */
typedef struct
{
  sc_t                    ECUSerialNumber[SRIF_ECU_SERIAL_STR_LEN];   /* pointer to string with ECU serial number */
  SRIFInputSignalState_t  signalState;                                /* validity of this input value or struct */
} SRIFInputEcuConfig_t;

/* --------------------- */
/* imager config section */
/* --------------------- */

/*!
 * type of unique imager setup
 */
typedef enum
{
  SRIF_IMAGER_SETUP_UNKNOWN                                 = 0,    /*!< imager type not known */
  SRIF_IMAGER_SETUP_CSF_A_SAMPLE                            = 1,    /*!< imager from CSF A sample */
  SRIF_IMAGER_SETUP_CSF_B_SAMPLE_SINGLE_EXP                 = 2,    /*!< imager from CSF B sample with single exposure only */
  SRIF_IMAGER_SETUP_CSF_SERIES                              = 3,    /*!< imager from CSF series */
  SRIF_IMAGER_SETUP_KAFAS_SERIES                            = 4,    /*!< imager from KAFAS series */
  SRIF_IMAGER_SETUP_MFC_APTINA_M1000_REV3_B0_1              = 5,    /*!< imager is an Aptina M1000 revision 3 for MFC B01 sample 
                                                                      i.e., double exposure short: 7,5ms fixed and long: 20ms controlled 
                                                                      CROI = 1024*648   !!!NOT SUPPORTED!!!                        */
  SRIF_IMAGER_SETUP_MFC_APTINA_M1000_REV3_B1                = 6,    /*!< imager is an Aptina M1000 revision 3 for MFC B1 sample 
                                                                      i.e., double exposure short: 7,5ms fixed and long: 20ms controlled
                                                                      CROI = 1176*482 */
  SRIF_IMAGER_SETUP_MFC_APTINA_M1000_REV3_B1_SIM_FULL_FRAME = 7     /*!< like SRIF_IMAGER_SETUP_MFC_APTINA_M1000_REV3_B1 but ROI covers
                                                                         full frame for simulation purposes (cf. CR#61377) */
} SRIFInputImagerSetup_t;

/*!
 * type of color filter array on input image
 */
typedef enum
{
  SRIF_IMAGE_CFA_UNKNOWN = 0,  /*!< color filter array not known */
  SRIF_IMAGE_CFA_CLEAR   = 1,  /*!< no color filter array applied */
  SRIF_IMAGE_CFA_RGGB    = 2,  /*!< red, green, green, blue 2x2 color filter array */
  SRIF_IMAGE_CFA_BGGR    = 3,  /*!< blue, green, green, red 2x2 color filter array */
  SRIF_IMAGE_CFA_GRBG    = 4,  /*!< green, red, blue, green 2x2 color filter array */
  SRIF_IMAGE_CFA_GBRG    = 5,  /*!< green, blue, red, green 2x2 color filter array */
  SRIF_IMAGE_CFA_RCGB    = 6,  /*!< red, clear, green, blue 2x2 color filter array */
  SRIF_IMAGE_CFA_GBRC    = 7,  /*!< green, blue, red, clear 2x2 color filter array */
  SRIF_IMAGE_CFA_CRBG    = 8,  /*!< clear, red, blue, green 2x2 color filter array */
  SRIF_IMAGE_CFA_BGCR    = 9   /*!< blue, green, clear, red 2x2 color filter array */
} SRIFInputImageCFA_t;

/*!
 *  relative pixel brightness of the color filter array
 */
typedef struct
{
  f32_t red;    /*!< brightness of red pixels in relation to green pixels */
  f32_t green;  /*!< brightness of green pixels in relation to green pixels (should be approx. 1 :-] ) */
  f32_t blue;   /*!< brightness of blue pixels in relation to green pixels */
} SRIFInputCfaTransmittance_t;

/*!
 * imager configuration information
 */
typedef struct
{
  ui32_t                        imageWidth;                                       /*!< width of input ROI [pixels] */
  ui32_t                        imageHeight;                                      /*!< height of input ROI [pixels] */
  ui32_t                        numImageBitsReserved;                             /*!< number of bits per "storage element" of ROI pointer,
                                                                                      e.g. 16 if ROI points to ui16_t memory structure */
  ui32_t                        numImageBitsUsed;                                 /*!< actually filled number of bits per "storage element" of ROI pointer = image bit depth */
  sc_t                          imagerSerialNumber[SRIF_IMAGER_SERIAL_STR_LEN];   /*!< pointer to string with imager serial number */
  SRIFInputImagerSetup_t        imagerSetup;                                      /*!< unique ID of imager setup */
  SRIFInputImageCFA_t           imageCFA;                                         /*!< type of input image color filter array */
  SRIFInputCfaTransmittance_t   cfaTransmittance;                                 /*!< brightness ratio of the colour channels */
  f32_t                         pixelSize;                                        /*!< pixel size [m] */
  f32_t                         frameDeltaTime;                                   /*!< time between images [s]. On double exposure illu scheme time between each single frame */
  SRIFInputSignalState_t        signalState;                                      /*!< validity of this input value or struct */
} SRIFInputImagerConfig_t;

/* --------------------- */
/* camera config section */
/* --------------------- */

/*!
 * camera configuration information
 */
typedef struct
{
  f32_t                     focalLengthPix;         /*!< focal length of lens [pixels] */
  f32_t                     principalAxisX;         /*!< the principal X-axis point in the image. Top left corner of top left pixel is 0.0/0.0 */
  f32_t                     principalAxisY;         /*!< the principal Y-axis point in the image. Top left corner of top left pixel is 0.0/0.0 */
  f32_t                     lensDistortionParam1;   /*!< first lens distortion parameter (TBD) */
  f32_t                     lensDistortionParam2;   /*!< second lens distortion parameter (TBD) */
  f32_t                     camPosX;                /*!< camera X position in vehicle coordinates [m] */
  f32_t                     camPosY;                /*!< camera Y position in vehicle coordinates [m] */
  f32_t                     camPosZ;                /*!< camera Z position in vehicle coordinates [m] */
  f32_t                     camPitch;               /*!< camera pitch angle in vehicle coordinates [rad] */
  f32_t                     camYaw;                 /*!< camera yaw angle in vehicle coordinates [rad] */
  f32_t                     camRoll;                /*!< camera roll angle in vehicle coordinates [rad] */
  SRIFInputSignalState_t    signalState;            /*!< validity of this input value or struct */
} SRIFInputCameraConfig_t;

/* ---------------------- */
/* vehicle config section */
/* ---------------------- */

/*!
 * mounting position of steering wheel (in driving direction)
 */
typedef enum
{
  SRIF_VEHICLE_STEERING_VARIANT_UNKNOWN     = 0,  /*!< mounting position not known */
  SRIF_VEHICLE_STEERING_VARIANT_LEFT_SIDE   = 1,  /*!< steering wheel is mounted on left side */
  SRIF_VEHICLE_STEERING_VARIANT_RIGHT_SIDE  = 2   /*!< steering wheel is mounted on right side */
} SRIFInputVehicleSteeringVariant_t;

/*!
 * displayed speed unit in instrument cluster
 */
typedef enum
{
  SRIF_VEHICLE_INSTRUMENT_CLUSTER_UNIT_UNKNOWN  = 0,  /*!< displayed speed unit not known */
  SRIF_VEHICLE_INSTRUMENT_CLUSTER_UNIT_MPH      = 1,  /*!< speed is displayed in miles per hour */
  SRIF_VEHICLE_INSTRUMENT_CLUSTER_UNIT_KMH      = 2   /*!< speed is displayed in kilometers per hour */
} SRIFInputVehicleICUnit_t;

/*!
 * vehicle configuration information
 */
typedef struct
{
  f32_t                               wheelBase;        /*!< vehicle wheel base [m] */
  SRIFInputVehicleSteeringVariant_t   steeringVariant;  /*!< vehicle steering variant */
  SRIFInputVehicleICUnit_t            clusterUnit;      /*!< unit of instrument cluster */
  SRIFInputSignalState_t              signalState;      /*!< validity of this input value or struct */
} SRIFInputVehicleConfig_t;

/* ------------------------ */
/* parameter config section */
/* ------------------------ */

/*!
 * control flow alternatives
 */
typedef enum
{
  SRIF_APPL_CONTROL_FLOW_NORMAL                     = 0,  /*!< normal operations, no restriction applies */
  SRIF_APPL_CONTROL_FLOW_SKIP_KERNEL                = 1,  /*!< skip SR kernel, but collect debug output (aka as meas freeze data) */
  SRIF_APPL_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT    = 2,  /*!< skip SR kernel, but collect debug output, no input validation, fixed faked output */
  SRIF_APPL_CONTROL_FLOW_DEBUG                      = 3   /*!< special debug functionality enabled:
                                                                - execute all normalizations (e.g. IAX) independent of classification result */
} SRIFInputApplicationControlFlow_t;

/*!
 * SR parameter information
 */
typedef struct
{
  SRIFInputApplicationControlFlow_t   controlFlow;  /*!< alternatives of control flow */
  SRIFInputSignalState_t              signalState;  /*!< validity of this input value or struct */
} SRIFInputApplicationConfig_t;

/* ---------------------------- */
/* merged static config section */
/* ---------------------------- */

/*!
 * static input config data
 */ 
typedef struct
{
  SRIFInputEcuConfig_t          ECUConfig;          /*!< static ECU config */
  SRIFInputImagerConfig_t       imagerConfig;       /*!< static imager config */
  SRIFInputCameraConfig_t       cameraConfig;       /*!< static camera config */
  SRIFInputVehicleConfig_t      vehicleConfig;      /*!< static vehicle config */
  SRIFInputApplicationConfig_t  applicationConfig;  /*!< static SR application control parameters, NO algo tuning parameters!!! */
} SRIFInputConfig_t;

/* --------------------------------------- */
/* input timestamp and basic types section */
/* --------------------------------------- */

/*!
 * input data timestamp
 */
typedef struct               /* signed types to avoid casts when doing calculations with timestamp */
{
  i32_t sec;   /*!< seconds since ECU startup */
  i32_t usec;  /*!< microseconds since ECU startup */
} SRIFInputTimestamp_t;

/*!
 * compound 32 bit integer input type
 */
typedef struct
{
  i32_t                   value;        /*!< value of input integer data */
  SRIFInputTimestamp_t    timestamp;    /*!< timestamp for data creation */
  SRIFInputSignalState_t  signalState;  /*!< state of input */
} SRIFInputInt32_t;

/*!
 * compound 32 bit float input type
 */
typedef struct
{
  f32_t                   value;        /*!< value of input integer data */
  SRIFInputTimestamp_t    timestamp;    /*!< timestamp for data creation */
  SRIFInputSignalState_t  signalState;  /*!< state of input */
} SRIFInputFloat32_t;

/*!
 * type of vehicle motion
 */
typedef enum
{
  SRIF_VEHICLE_MOTION_STATE_UNKNOWN     = 0,  /*!< motion state not known */
  SRIF_VEHICLE_MOTION_STATE_FWD         = 1,  /*!< vehicle moves forwards */
  SRIF_VEHICLE_MOTION_STATE_REV         = 2,  /*!< vehicle moves backwards */
  SRIF_VEHICLE_MOTION_STATE_STANDSTILL  = 3   /*!< vehicle doesn't move */
} SRIFInputVehicleMotionType_t;

/*!
 * compound vehicle motion input
 */
typedef struct
{
  SRIFInputVehicleMotionType_t  value;          /*!< vehicle motion type */
  SRIFInputTimestamp_t          timestamp;      /*!< timestamp for data creation */
  SRIFInputSignalState_t        signalState;    /*!< state of input */
} SRIFInputVehicleMotionState_t;

/* ------------------- */
/* image input section */
/* ------------------- */

/*!
 * pixel type
 */
typedef ui16_t SRIFInputImagePixelData_t;

/*!
 * frame type of alternating exposure control
 */
typedef enum
{
  SRIF_FRAME_TYPE_UNKNOWN           = 0,  /*!< frame type not known */
  SRIF_FRAME_TYPE_SINGLE_EXP        = 1,  /*!< all frames of same type */
  SRIF_FRAME_TYPE_DOUBLE_EXP_0      = 2,  /*!< frame type two in double exposure concept: i.e. CSF: short frame, SRIF_IMAGER_SETUP_APTINA_M1000_REV3_B01: 7.5ms fixed */
  SRIF_FRAME_TYPE_DOUBLE_EXP_1      = 3,  /*!< frame type one in double exposure concept: i.e. CSF: long frame,  SRIF_IMAGER_SETUP_APTINA_M1000_REV3_B01: 20ms controlled */
  SRIF_FRAME_TYPE_KAFAS_SLI         = 4,  /*!< frame exposed in KAFAS SLI mode */
  SRIF_FRAME_TYPE_KAFAS_TLC         = 5,  /*!< frame exposed in KAFAS TLC mode */
  SRIF_FRAME_TYPE_KAFAS_FLA         = 6,  /*!< frame exposed in KAFAS FLA mode */
  SRIF_FRAME_TYPE_KAFAS_UNKNOWN     = 7   /*!< frame exposed in unknown KAFAS mode */
} SRIFInputFrameType_t;

/*!
 * specification of imager's repsonse curve
 */
typedef struct
{
  ui32_t                    numberOfSupportPoints;                              /*!< number of sampling points available in lists below */
  SRIFInputImagePixelData_t gray[SRIF_IMAGER_RC_MAX_NUM_SUPPORT_POINTS];        /*!< gray values corresponding to brightness values */
  f32_t                     brightness[SRIF_IMAGER_RC_MAX_NUM_SUPPORT_POINTS];  /*!< brightness values corresponding to gray values */
} SRIFInputImagerResponceCurveDefinition_t;

/*!
 * compound image information
 */
typedef struct
{
  SRIFInputImagePixelData_t                   *image;                   /*!< pointer to input image */
  SRIFInputFrameType_t                        frameType;                /*!< current frame type */
  ui32_t                                      frameNumber;              /*!< current frame no */
  ui32_t                                      exposureTime;             /*!< exposure time of current (at least we hope so! :-| ) image [us] */
  ui32_t                                      brightness;               /*!< brightness of image */
  SRIFInputImagePixelData_t                   blackLevel;               /*!< black level of image */
  f32_t                                       noiseStdDeviation;        /*!< standard deviation of noise level in image */
  SRIFInputImagerResponceCurveDefinition_t    responseCurveDefinition;  /*!< current response curve definition to get mapping gray -> brightness */
  SRIFInputTimestamp_t                        timestamp;                /*!< time of start of exposure */
  SRIFInputSignalState_t                      signalState;              /*!< state of input image struct */
} SRIFInputImage_t;

/* -------------------------- */
/* environmental info section */
/* -------------------------- */

/*!
 * types of upcoming environmental area change events
 */
typedef enum
{
  SRIF_CONTEXT_CHANGE_UNKNOWN            = 0,  /*!< context change type not known */
  SRIF_CONTEXT_CHANGE_NO_CHANGE_AHEAD    = 1,  /*!< no context change ahead */
  SRIF_CONTEXT_CHANGE_OUTSIDE_TO_INSIDE  = 2,  /*!< context change from outside to inside ahead */
  SRIF_CONTEXT_CHANGE_INSIDE_TO_OUTSIDE  = 3   /*!< context change from inside to outside ahead */
} SRIFInputContextChangeType_t;

/*!
 *  compound context change input
 */
typedef struct
{
  SRIFInputContextChangeType_t  contextChangeType;        /*!< type of upcoming context change event
                                                               a change type with zero or negative distance means that
                                                               the type changed to is still valid, e.g.
                                                               SRIF_CONTEXT_CHANGE_OUTSIDE_TO_INSIDE with -2.5 meters
                                                               means that we are inside the given context */
  f32_t                         distanceToContextChange;  /*!< distance to next context change [m] */
} SRIFInputContextChangeInfo_t;

/*! type definition for bitfield bits of variable speed sign position */
typedef enum
{
   SRIF_VAR_SIGN_POS_UNKNOWN  = 0x0001, /*!< Position of Variable Speed Sign is not known/defined. */
   SRIF_VAR_SIGN_POS_LEFT     = 0x0002, /*!< Variable Speed Sign is located left of the road. */
   SRIF_VAR_SIGN_POS_RIGHT    = 0x0004, /*!< Variable Speed Sign is located right of the road. */
   SRIF_VAR_SIGN_POS_ABOVE    = 0x0008, /*!< Variable Speed Sign is located above road, but lane is unknown/undefined. */
   SRIF_VAR_SIGN_POS_EMLANE   = 0x0010, /*!< Variable Speed Sign is located above Emergency Lane. */
   SRIF_VAR_SIGN_POS_1ST_LANE = 0x0020, /*!< Variable Speed Sign is located above 1st lane from the right (left, in left-driving countries). */
   SRIF_VAR_SIGN_POS_2ND_LANE = 0x0040, /*!< Variable Speed Sign is located above 2nd lane from the right (left, in left-driving countries). */
   SRIF_VAR_SIGN_POS_3RD_LANE = 0x0080, /*!< Variable Speed Sign is located above 3rd lane from the right (left, in left-driving countries). */
   SRIF_VAR_SIGN_POS_4TH_LANE = 0x0100, /*!< Variable Speed Sign is located above 4th lane from the right (left, in left-driving countries). */
   SRIF_VAR_SIGN_POS_5TH_LANE = 0x0200  /*!< Variable Speed Sign is located above 5th lane from the right (left, in left-driving countries). */
} SRIFVariableSignPositionBitfield_t;

/*! type definition for variable speed sign position */
typedef ui32_t SRIFVariableSignPosition_t;

/*!
 *  compound environmental input data
 */
typedef struct
{
  SRIFInputContextChangeInfo_t urbanAreaChangeInfo;            /*!< information on upcoming urban area change event */
  SRIFInputContextChangeInfo_t residentialAreaChangeInfo;      /*!< information on upcoming residential area change event */
  SRIFInputContextChangeInfo_t noCircleSignContextChangeInfo;  /*!< information on upcoming urban area change event */
  i32_t                        countryCode;                    /*!< current country code from navigation unit/frame, ISO3166-1 */
  ui32_t                       regionCode;                     /*!< current region code, from navigation unit/frame, ISO3166-2 */
  SRIFVariableSignPosition_t   varSignPosition;                /*!< position of variable signs, if any present */
  SRIFInputTimestamp_t         timestamp;                      /*!< timestamp */
  SRIFInputSignalState_t       signalState;                    /*!< state of input image struct */
} SRIFInputEnvironmentalInfo_t;

/* ------------------------------- */
/* online calibration info section */
/* ------------------------------- */

/*!
 *  compound online calibration input
 */
typedef struct
{
  f32_t                   yaw;          /*!< yaw angle from on-line camera calibration [rad] */
  f32_t                   pitch;        /*!< pitch angle from on-line camera calibration [rad] */
  f32_t                   roll;         /*!< roll angle from on-line camera calibration [rad] */
  SRIFInputTimestamp_t    timestamp;    /*!< timestamp */
  SRIFInputSignalState_t  signalState;  /*!< state of input image struct */
} SRIFInputOnlineCalibrationInfo_t;


/*!
 *  ECU trigger information needed for PC simulation only. TODO: Data should be transparent i.e. not be passed through the algo.
 */
typedef struct
{
  ui64_t                  srTriggerReference;   /*!< reference identifying the current SR cycle. Data is abstract. */
  ui64_t                  vdyTriggerReference;  /*!< reference identifying the current VDY cycle. Data is abstract. */
  ui64_t                  imageReference;       /*!< reference identifying the current input image. Data is abstract. */
} SRIFInputTriggerReference_t SR_STRUCT_ALIGN(8);



/*!
 * compound
 */

/* ---------------- */
/* sr input section */
/* ---------------- */

/*!
 * compound inputs to sign recognition
 */
typedef struct
{
  SRIFInputTimestamp_t              cycleTimestamp;         /*!< system time at which the current SR cycle was executed */
  SRIFInputImage_t                  image;                  /*!< input image */
  SRIFInputFloat32_t                velocity;               /*!< current velocity from VDY [meters/second] */
  SRIFInputFloat32_t                yawRate;                /*!< current offset compensated yaw rate from ESP [radians/second] */
  SRIFInputVehicleMotionState_t     motionState;            /*!< current vehicle motion state */
  SRIFInputEnvironmentalInfo_t      environmentalInfo;      /*!< current country code from navigation unit/frame, ISO3166 */
  SRIFInputOnlineCalibrationInfo_t  onlineCalibrationInfo;  /*!< yaw, pitch, and roll angles from on-line camera calibration [rad]  */
  SRIFInputInt32_t                  highBeamOn;             /*!< true if high beam is on */
  SRIFInputInt32_t                  numResets;              /*!< number of time the component was resetted by the frame (NOT counting the initial init) */
  SRIFInputTriggerReference_t       triggerReference;       /*!< ECU trigger information needed for PC simulation only */
} SRIFInput_t;

#ifdef __cplusplus
 }
#endif

#endif /* _SRIF_INPUT_H_ */
