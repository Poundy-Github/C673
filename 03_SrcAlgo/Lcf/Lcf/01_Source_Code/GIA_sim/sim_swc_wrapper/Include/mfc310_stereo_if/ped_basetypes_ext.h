/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      PED - Pedestrian Recognition

  MODULNAME:      ped_basetypes_ext.h  

  DESCRIPTION:    defines base types for pedestrian recognition interface

  AUTHOR:         Robert Thiel

  CREATION DATE:  20.01.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: ped_basetypes_ext.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:26:24CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:37:29CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.1 2014/03/13 15:12:57CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.17 2012/04/18 13:01:40CEST Thiel, Robert (thielr) 
  CHANGES:        removed some commas
  CHANGES:        --- Added comments ---  thielr [Apr 18, 2012 1:01:42 PM CEST]
  CHANGES:        Change Package : 60040:19 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.16 2012/03/22 08:41:07CET Thiel, Robert (thielr) 
  CHANGES:        added new error "PED_eErrorCode_ImagerBrightnessInvalid"
  CHANGES:        --- Added comments ---  thielr [Mar 22, 2012 8:41:09 AM CET]
  CHANGES:        Change Package : 60040:18 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.15 2012/03/21 15:06:46CET Thiel, Robert (thielr) 
  CHANGES:        removed dependency to HLA brightness and use ASIL confirmed brightness from IC
  CHANGES:        --- Added comments ---  thielr [Mar 21, 2012 3:06:46 PM CET]
  CHANGES:        Change Package : 60040:18 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.14 2012/03/19 17:13:33CET Thiel, Robert (thielr) 
  CHANGES:        for 4.5
  CHANGES:        --- Added comments ---  thielr [Mar 19, 2012 5:13:33 PM CET]
  CHANGES:        Change Package : 60040:15 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.13 2012/03/01 09:24:41CET Bachmann, Alexander (uidt5584) 
  CHANGES:        removed superfluid switches
  CHANGES:        --- Added comments ---  uidt5584 [Mar 1, 2012 9:24:44 AM CET]
  CHANGES:        Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.12 2011/09/27 16:25:35CEST Thiel, Robert (thielr) 
  CHANGES:        added error 26 (PED_eErrorCode_FPGAInputInvalid_CycleDifferent)
  CHANGES:        --- Added comments ---  thielr [Sep 27, 2011 4:25:35 PM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.11 2011/09/20 08:45:21CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added new errors regarding fpga output failures
  CHANGES:        --- Added comments ---  thielr [Sep 20, 2011 8:45:22 AM CEST]
  CHANGES:        Change Package : 60040:13 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.7 2011/08/02 08:17:58CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added error for fpga output data corruption
  CHANGES:        --- Added comments ---  thielr [Aug 2, 2011 8:17:59 AM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.6 2011/07/26 13:02:17CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added more error types
  CHANGES:        --- Added comments ---  thielr [Jul 26, 2011 1:02:17 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.5 2011/07/01 14:59:28CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added errorcode for output data check failed
  CHANGES:        --- Added comments ---  thielr [Jul 1, 2011 2:59:28 PM CEST]
  CHANGES:        Change Package : 60040:10 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.4 2011/05/27 13:49:07CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        added lots of new error types
  CHANGES:        --- Added comments ---  thielr [May 27, 2011 1:49:07 PM CEST]
  CHANGES:        Change Package : 60040:9 http://mks-psad:7002/im/viewissue?selection=60040
  CHANGES:        Revision 1.2 2011/04/06 15:52:37CEST Thiel Robert (thielr) (thielr) 
  CHANGES:        removed dependencies
  CHANGES:        Revision 1.1 2011/03/17 10:32:07CET Thiel Robert (thielr) (thielr) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/PED_PedestrianRecognition/04_Engineering/01_Source_Code/algo/common/project.pj
  
**************************************************************************** */

#ifndef PED_BASETYPES_EXT_H
#define PED_BASETYPES_EXT_H

#include "common_interface_defines.h"
#include "cct_type.h"

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/* -------------------- */
/* error output section */
/* -------------------- */

/*!
 * definition of external error check status type
 * check failed means that the check was performed and an error detected
 */
typedef enum
{
  PEDErrorStatus_CHECK_NOT_DONE         = 0,  /*!< status of error unknown, i.e. error was not (completely) checked */
  PEDErrorStatus_CHECK_DONE_AND_PASSED  = 1,  /*!< error did not occur */
  PEDErrorStatus_CHECK_DONE_AND_FAILED  = 2   /*!< error did occur */
} PEDErrorStatus_t;

/*!
 * definition of external error ids (basic categories; algo can define additional ones)
 * parameter: erroneous input parameter (static  "configuration" data)
 * blockage : function not available due to blockage
 * vehicle data : erroneous vehicle data input (speed, yaw rate, ...)
 * image data : erroneous image data (wrong size, timestamp delta too large/small, non-incrementing frame counter ...)
 * calibration: calibration data error (special case of input error since often encountered)
 * input: erroneous dynamic input data (other sources)
 * software: internal software error (index, pointer, function parameter etc.)
 * fatal: serious, non-recoverable error
 * NOTE: Assumption is that first error has value 0
 */
typedef enum
{
  PEDErrorId_PARAMETER        = 0,  /*!< = 0, error group: parameter --> error occurred during init */
  PEDErrorId_BLOCKAGE         = 1,  /*!< = 1, error group: blockage */
  PEDErrorId_VEHICLE_DATA     = 2,  /*!< = 2, error group: error in vehicle input data */
  PEDErrorId_IMAGE_DATA       = 3,  /*!< = 3, error group: error in image input data */
  PEDErrorId_CALIBRATION      = 4,  /*!< = 4, error group: error in calibration input */
  PEDErrorId_INPUT            = 5,  /*!< = 5, error group: (other) input error*/
  PEDErrorId_SOFTWARE         = 6,  /*!< = 6, error group: software */
  PEDErrorId_FATAL            = 7,  /*!< = 7, error group: fatal, e.g. HW-error */
  
  PED_NUM_ERROR_LIST_ENTRIES = 8   /*!< = 8, pseudo entry for number of errors */
} PEDErrorId_t;

/*!
 * definition of external error list entry type
 */
typedef struct _PEDError_t
{
  PEDErrorStatus_t status;      /*!< status of error */
  ui32_t           optData;	    /*!< optional data */
} PEDError_t;

/*!
 * definition of external error list
 */
typedef struct _PEDOutputErrors_t
{
  PEDError_t     error[PED_NUM_ERROR_LIST_ENTRIES];  /*!< error entries, indexed by PEDErrorId_t defined above */
} PEDOutputErrors_t;


/*!
 * definition of algo state type
 */
typedef enum
{
  PEDState_NOT_INITIALIZED     = 0,  /*!< algo has not been initialized yet, state before init() function */
  PEDState_RUNNING	           = 1,  /*!< algo has been initialized and is running fine */
  PEDState_TEMP_NOT_AVAILABLE  = 2,  /*!< algo has been initialized but is temporarily not available */
  PEDState_FAILURE             = 3  /*!< algo is in failure mode, needs to be reinitialized by frame SW */
} PEDState_t;

/*!
 * definition of system info type
 * this structure is passed to algo init() and run() functions as output argument, algo updates it at each call.
 * e.g. init(..., PEDSystemInfo_t *sysInfo, ...);
 */
typedef struct _PEDSystemInfo_t
{
  PEDOutputErrors_t	  errors;
  PEDState_t          state;
} PEDSystemInfo_t;



/*
 *	--------------------------------------------------------------------------------------------------------------------
 */

/*! \brief PED error codes*/
typedef enum
{
  PED_eErrorCode_NoError                        =     0u, /*!< function returns without an error                                                           */
  PED_eErrorCode_NULLPointer                    =     1u, /*!< a null pointer was given...                                                                 */
  PED_eErrorCode_NoCameraSet                    =     2u, /*!< camera parameters could not be set                                                          */
  PED_eErrorCode_NoCarpetSet                    =     3u, /*!< carpet parameters could not be set                                                          */
  PED_eErrorCode_RegionComputeFailed            =     4u, /*!< Region Generator could not compute results                                                  */
  PED_eErrorCode_NotInitialized                 =     5u, /*!< function is not initialized                                                                 */
  PED_eErrorCode_PatchMergeFailed               =     6u, /*!< patch merging failed                                                                        */
  PED_eErrorCode_WrongRectImgDimensions         =     7u, /*!< image dimensions not OK                                                                     */
  PED_eErrorCode_ImageTimeStampError            =     8u, /*!< image timestamp is not correct                                                              */
  PED_eErrorCode_MountRightStampError           =     9u, /*!< mount right timestamp is not correct                                                        */
  PED_eErrorCode_MountRightInvalid              =    10u, /*!< mount right is invalid                                                                      */
  PED_eErrorCode_CalibDataTimeStampError        =    11u, /*!< calibration data time stamp is not correct                                                  */
  PED_eErrorCode_CalibDataInvalid               =    12u, /*!< calibration data is invalid                                                                 */
  PED_eErrorCode_VehicleInputDrvIntCrvInvalid   =    13u, /*!< driver intendet curvature is invalid                                                        */
  PED_eErrorCode_VehicleInputOverallCrvInvalid  =    14u, /*!< overall curvature is invalid                                                                */
  PED_eErrorCode_VehicleInputVelocityInvalid    =    15u, /*!< velocity is not valid                                                                       */
  PED_eErrorCode_VehicleInputYawRateInvalid     =    16u, /*!< yaw rate is no valid                                                                        */
  PED_eErrorCode_FPGAInputInvalid               =    17u, /*!< classifier data invalid - fpga points to invalid patch                                      */
  PED_eErrorCode_FODDataInvalid                 =    18u, /*!< FOD data invalid                                                                            */
  PED_eErrorCode_ParameterInvalid               =    19u, /*!< parameter value is not in specified range                                                   */
  PED_eErrorCode_FPGAInputInvalid_TooManyPatches=    20u, /*!< classifier data invalid - fpga points to invalid patch                                      */
  PED_eErrorCode_FPGAInputInvalid_Checksum      =    21u, /*!< classifier data invalid - Checksum failed                                                   */
  PED_eErrorCode_FPGAInputInvalid_ScaleWrong    =    22u, /*!< classifier data invalid - scale conversion different                                        */
  PED_eErrorCode_FPGAInputInvalid_OutOfROI      =    23u, /*!< classifier data invalid - coordinate out of image                                           */
  PED_eErrorCode_FPGAInputInvalid_RefPatchError =    24u, /*!< classifier data invalid - reference patch data incorrect                                    */
  PED_eErrorCode_FPGAInputInvalid_ScaleError    =    25u, /*!< classifier data invalid - scale out of range                                                */
  PED_eErrorCode_FPGAInputInvalid_CycleDifferent=    26u, /*!< classifier data invalid - cycle counter from input does not match cycle counter from output */
  PED_eErrorCode_ImagerBrightnessInvalid        =    27u, /*!< value from IC (brightness) is not valid (<0)                                                */
  
  
  PED_eErrorCode_OutputDataCorrupted            =   512u, /*!< output data check failed                                                                    */
  PED_eErrorCode_OutputDataCorrupted_Patches    =   513u, /*!< output data check regarding patches failed                                                  */
  PED_eErrorCode_OutputDataCorrupted_Registers  =   514u, /*!< output data check regarding registers failed                                                */ 
  PED_eErrorCode_OutputDataCorrupted_NrRetHyps  =   515u, /*!< output data check regarding nr of returned ped hyps                                         */
  PED_eErrorCode_OutputDataCorrupted_RetHypInv  =   516u, /*!< output data check regarding returned ped hyps                                               */

  PED_eErrorCode_ScratchpadEmpty                =  1000u, /*!< scratchpad is empty                                                                         */
  PED_eErrorCode_WrongVersionNumber             = 65535u  /*!< version number is wrong!                                                                    */
} PED_t_eErrorCode;

/*! \brief  signal/variable state */
typedef enum
{
  PED_eSignalState_SigNotOK       = 0u,  /*!< signal not available */
  PED_eSignalState_SigOK          = 1u   /*!< signal available */
} PED_t_eSignalState;


static const ui32_t PEDMountingCalibrationData_VersionNumber = 1;  /*!< Version Number of struct PED_t_MountingCalibrationData */
/*!PED Camera Mounting Data*/                                                                  
typedef struct _PED_t_MountingCalibrationData
{
  DEFINE_VERSION_MEMBER(PEDMountingCalibrationData);

  /* cameraposition in AUTOSAR - coordinates  */
  f32_t  f_PositionX;                                  /*!< X-position of camera in meters */
  f32_t  f_PositionY;                                  /*!< Y-position of camera in meters */
  f32_t  f_PositionZ;                                  /*!< Z-position of camera in meters */

  /* rotation from vehicle to camera coordinates
     right handed, image rows coincide with x-axis, columns with y-axis, z to optical axis */
  f32_t  f_Pitch;                                      /*!< x-rotation (pitch) [rad] */
  f32_t  f_Roll;                                       /*!< y-rotation (roll)  [rad] */
  f32_t  f_Yaw;                                        /*!< z-rotation (yaw)   [rad] */
  PED_t_eSignalState eTimeStampSigStat;                /*!< signal state of TimeStamp */
  ui64_t u_Timestamp_usec;                             /*!< time stamp when PEDMountingCalibrationData was changed by the SAC-Module %unit:탎 */
} PED_t_MountingCalibrationData;


static const ui32_t PEDEnvironmentalData_VersionNumber = 1;  /*!< Version Number of struct PED_t_EnvironmentalData */
/*!PED Rectified Right Camera Calibration Data*/
typedef struct _PED_t_EnvironmentalData
{
  DEFINE_VERSION_MEMBER(PEDEnvironmentalData);
  
  f32_t f_BrightnessCdqm;             /*! brightness in cd/qm of the IC for the "long" image*/
} PED_t_EnvironmentalData;


static const ui32_t PEDRectifiedCalibrationData_VersionNumber = 1;  /*!< Version Number of struct PED_t_RectifiedCalibrationData */
/*!PED Rectified Right Camera Calibration Data*/
typedef struct _PED_t_RectifiedCalibrationData
{
  DEFINE_VERSION_MEMBER(PEDRectifiedCalibrationData);

  f32_t              f_FocalX;                         /*!< camera X-coordinate focal length %unit:pixel */
  f32_t              f_FocalY;                         /*!< camera Y-coordinate focal length %unit:pixel */
  f32_t              f_CenterX;                        /*!< X-coordinate of camera center point in image %unit:pixel */
  f32_t              f_CenterY;                        /*!< Y-coordinate of camera center point in image %unit:pixel */
  f32_t              f_Baseline_m;                     /*!< camera stereo baseline %unit:m */
  PED_t_eSignalState eTimeStampSigStat;                /*!< signal state of TimeStamp */
  ui64_t             u_Timestamp_usec;                 /*!< time stamp when PEDRectifiedCalibrationData was changed by the SAC-Module %unit:탎 */
} PED_t_RectifiedCalibrationData;



static const ui32_t PEDVehicleData_VersionNumber = 1;  /*!< Version Number of struct PED_t_VehicleData */
/*! PEDPre Vehicle Data*/   
typedef struct _PED_t_VehicleData
{
  DEFINE_VERSION_MEMBER(PEDVehicleData);

  f32_t              f_Velocity;                        /*!< Ego vehicle velocity %unit:m/s */
  ui64_t             u_VelocityTimestamp_usec;          /*!< time stamp when velocity was received %unit:탎 */
  PED_t_eSignalState eVelocitySigStat;                  /*!< signal state of f_Velocity */

  f32_t              f_YawRate;                         /*!< offset compensated %unit:rad/s */  
  ui64_t             u_YawRateTimestamp_usec;           /*!< time stamp when yawRate was received %unit:탎 */
  PED_t_eSignalState eYawRateSigStat;                   /*!< signal state of f_YawRate */

  f32_t              f_OverallCurvature;                /*!< VDY curvature %unit:1/m^2 */  
  ui64_t             u_OverallCurvatureTimestamp_usec;  /*!< time stamp when curvature was received %unit:탎 */
  PED_t_eSignalState eOverallCurvatureSigStat;          /*!< signal state of f_OverallCurvature */

  f32_t              f_DrvIntCurvature;                 /*!< VDY driver intended curvature %unit:1/m^2 */  
  ui64_t             u_DrvIntCurvatureTimestamp_usec;   /*!< time stamp when drvint curvature was received %unit:탎 */
  PED_t_eSignalState eDrvIntCurvatureSigStat;           /*!< signal state of f_DrvIntCurvature */

} PED_t_VehicleData;


static const ui32_t PEDImageInformation_VersionNumber = 1;      /*!< Version Number of struct PED_t_ImageInformation */
/*! PEDPre Image information (dimensions)*/                                     
typedef struct _PED_t_ImageInformation
{
  DEFINE_VERSION_MEMBER(PEDImageInformation);

  ui32_t              uImageWidth_px;                   /*!< image width %unit:pixel */
  ui32_t              uImageHeight_px;                  /*!< image height %unit:pixel */
  PED_t_eSignalState  eTimeStampSigStat;                /*!< signal state of TimeStamp */  
  ui32_t              u_frameCounter;                   /*!< Cyclic counter of frame, period 0x100, active beginning from B1 sample */

  ui64_t              u_Timestamp_usec;                 /*!< time stamp when image was changed %unit:탎 */
} PED_t_ImageInformation;






/*! PED Algo Version Entity */
typedef struct 
{
  ui32_t VersionNumber; /*!< The version number consists of three uint8 which are combined in the following way: 
                           version major <<16 + version minor << 8 + patchlevel. All other bits are set to 0.*/ 
  char   VersionInfo[51]; /*!<  Versioninfo is a null terminated string. The content is arbitrary for now. For debug 
                           versions it is recommeded to have at least a compile time/date in there and for 
                           checkpointed/released versions the checkpoint name. */
} PED_t_AlgoVersion;





/* interface typedefs of used services */

extern PEDSystemInfo_t * ClearPedSystemInfo(PEDSystemInfo_t *pPedSystemInfo);
extern void UpdateSystemInfo(PEDSystemInfo_t *pPedSystemInfo, const PED_t_eErrorCode eErrorCode);


/* service for cache invalidation */
typedef void (*Fct_v_CacheInvalidateAll)(void);

/* service for starting a DMA transfer 
(pv_Src -> pv_Dest)[sl_Size] */
typedef i32_t (*Fct_sl_DMACopy)(void *pv_Dest, void *pv_Src, i32_t sl_Size, i32_t *psl_Handle);

/* service for starting a 2D-DMA transfer */
typedef i32_t (*Fct_sl_DMACopy_2D)(void *pv_Dst, void *pv_Src,
                                   i32_t sl_DstPitch, i32_t sl_SrcPitch,
                                   i32_t sl_Width, i32_t sl_Height,
                                   i32_t *psl_Handle);

/* service for starting a chained DMA transfer 
(pv_PreSrc -> pv_PreDest)[sl_PreSize] followed by 
(pv_PostSrc-> pv_PostDest)[sl_PostSize] */
typedef i32_t (*Fct_sl_DMACopyChained)(void *pv_PreDest, void *pv_PreSrc, i32_t sl_PreSize,
                                       void *pv_PostDest, void *pv_PostSrc, i32_t sl_PostSize,
                                       i32_t *psl_PostHandle);

/* service for waiting for the DMA transfer specified by sl_Handle */
typedef i32_t (*Fct_sl_DMAWait)(i32_t sl_Handle);

/* MeasFreeze service */
typedef i32_t (*Fct_sl_MEASFreeze) (void *pData, i32_t size, i32_t VirtAddr);


#ifdef __cplusplus
  }
#endif // __cplusplus



#endif /* PED_BASETYPES_EXT_H */

