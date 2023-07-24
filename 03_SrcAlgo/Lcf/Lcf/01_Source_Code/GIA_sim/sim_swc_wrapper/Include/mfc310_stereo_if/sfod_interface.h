/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_interface.h  

  DESCRIPTION:    input/output structure handling for SFOD data

  AUTHOR:         J. Schmidt

  CREATION DATE:  20.07.2009

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: sfod_interface.h  $
  CHANGES:        Revision 1.1 2021/12/13 17:26:26CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:37:33CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.1 2014/03/13 15:12:59CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
  CHANGES:        Revision 1.20 2012/07/26 14:57:48CEST Bachmann, Alexander (uidt5584) 
  CHANGES:        Functional Review Comments of Priority 1 analyzed and fixed in agreement with B.Ramirez (only comments, no code changes)
  CHANGES:        --- Added comments ---  uidt5584 [Jul 26, 2012 2:57:48 PM CEST]
  CHANGES:        Change Package : 141706:1 http://mks-psad:7002/im/viewissue?selection=141706
  CHANGES:        Revision 1.19 2012/07/05 14:48:29CEST Vogel-EXT, Oliver (uidu7284) 
  CHANGES:        Code Review (Stein/Vogel)
  CHANGES:        --- Added comments ---  uidu7284 [Jul 5, 2012 2:48:29 PM CEST]
  CHANGES:        Change Package : 125408:1 http://mks-psad:7002/im/viewissue?selection=125408
  CHANGES:        Revision 1.18 2012/03/23 12:07:58CET Bachmann, Alexander (uidt5584) 
  CHANGES:        Interface Freeze 4.5.0
  CHANGES:        --- Added comments ---  uidt5584 [Mar 23, 2012 12:07:58 PM CET]
  CHANGES:        Change Package : 104452:1 http://mks-psad:7002/im/viewissue?selection=104452
  CHANGES:        Revision 1.17 2012/02/24 22:51:10CET Bachmann, Alexander (uidt5584) 
  CHANGES:        updated interface for 4.4.0: get blockage tile information from blockage module
  CHANGES:        --- Added comments ---  uidt5584 [Feb 24, 2012 10:51:10 PM CET]
  CHANGES:        Change Package : 100296:3 http://mks-psad:7002/im/viewissue?selection=100296
  CHANGES:        Revision 1.16 2012/02/24 08:51:59CET Bachmann, Alexander (uidt5584) 
  CHANGES:        Misra update (R.Burgmeier)
  CHANGES:        --- Added comments ---  uidt5584 [Feb 24, 2012 8:52:00 AM CET]
  CHANGES:        Change Package : 52130:5 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.15 2011/10/28 14:21:30CEST Bachmann, Alexander (uidt5584) 
  CHANGES:        Interface Freeze 03.02.01: added bottomClearanceMin_m
  CHANGES:        --- Added comments ---  uidt5584 [Oct 28, 2011 2:21:31 PM CEST]
  CHANGES:        Change Package : 52130:9 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.14 2011/09/21 15:58:08CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        made naming of blockage status unique
  CHANGES:        --- Added comments ---  uidt5584 [Sep 21, 2011 3:58:09 PM CEST]
  CHANGES:        Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.13 2011/09/05 18:16:20CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        changes related to blockage interface/system info and respective meas freeze
  CHANGES:        --- Added comments ---  uidt5584 [Sep 5, 2011 6:16:21 PM CEST]
  CHANGES:        Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.12 2011/09/01 17:36:08CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        introduced error state as new input argument to SFOD
  CHANGES:        Revision 1.11 2011/07/06 14:13:10CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        PED/HARVESTER relevant interface changes
  CHANGES:        --- Added comments ---  uidt5584 [Jul 6, 2011 2:13:10 PM CEST]
  CHANGES:        Change Package : 52130:1 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.10 2011/07/04 12:56:40CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        guarantee PDO compatibility
  CHANGES:        --- Added comments ---  uidt5584 [Jul 4, 2011 12:56:40 PM CEST]
  CHANGES:        Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.9 2011/05/11 13:52:49CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        added signals to interface according to REL2.5.1
  CHANGES:        --- Added comments ---  uidt5584 [May 11, 2011 1:52:49 PM CEST]
  CHANGES:        Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.8 2011/04/26 17:46:37CEST Eisenmann Thomas (uidt3978) (uidt3978) 
  CHANGES:        Change harvester interface structure
  CHANGES:        --- Added comments ---  uidt3978 [Apr 26, 2011 5:46:37 PM CEST]
  CHANGES:        Change Package : 49009:3 http://mks-psad:7002/im/viewissue?selection=49009
  CHANGES:        Revision 1.7 2011/04/18 12:25:54CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        bare floxel integration stuff
  CHANGES:        --- Added comments ---  uidt5584 [Apr 18, 2011 12:25:54 PM CEST]
  CHANGES:        Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.4 2011/04/01 18:38:15CEST Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        added SFODPostProcess()-routine, blame Alex
  CHANGES:        --- Added comments ---  uidt5584 [Apr 1, 2011 6:38:15 PM CEST]
  CHANGES:        Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.3 2011/03/25 14:49:36CET Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        interface adaptions according to REL2.5.0
  CHANGES:        --- Added comments ---  uidt5584 [Mar 25, 2011 2:49:36 PM CET]
  CHANGES:        Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
  CHANGES:        Revision 1.20 2010/12/17 13:29:50CET Bachmann Alexander (uidt5584) (uidt5584) 
  CHANGES:        Git update
  CHANGES:        Revision 1.16 2010/08/20 11:45:18CEST Eisenmann Thomas (uidt3978) (uidt3978) 
  CHANGES:        Spelling in corridor segment structure
  CHANGES:        --- Added comments ---  uidt3978 [Aug 20, 2010 11:45:18 AM CEST]
  CHANGES:        Change Package : 49009:1 http://mks-psad:7002/im/viewissue?selection=49009
  CHANGES:        Revision 1.15 2010/08/19 15:35:30CEST Eisenmann Thomas (uidt3978) (uidt3978) 
  CHANGES:        Changes in B2 sample: Spliiting Mode, Framecount in Input Structure for Disparity Image + Flow
  CHANGES:        --- Added comments ---  uidt3978 [Aug 19, 2010 3:35:31 PM CEST]
  CHANGES:        Change Package : 49009:1 http://mks-psad:7002/im/viewissue?selection=49009
  CHANGES:        Revision 1.14 2010/08/13 13:16:48CEST Stefan Hegemann (hegemanns) 
  CHANGES:        Change Interface for FOD --> POD
  CHANGES:        --- Added comments ---  hegemanns [Aug 13, 2010 1:16:48 PM CEST]
  CHANGES:        Change Package : 26830:1 http://mks-psad:7002/im/viewissue?selection=26830
  CHANGES:        Revision 1.12 2010/06/25 08:41:53CEST Stefan Hegemann 	 (shegemann) 
  CHANGES:        Add Flag for Working Mode (DebugMode for Testing the Interface)
  CHANGES:        --- Added comments ---  shegemann [2010/06/25 06:41:54Z]
  CHANGES:        Change Package : 26830:1 http://LISS014:6001/im/viewissue?selection=26830
  CHANGES:        Revision 1.11 2010/06/23 15:28:52CEST Stefan Hegemann 	 (shegemann) 
  CHANGES:        Change of the Interface (add TimeStamps)
  CHANGES:        --- Added comments ---  shegemann [2010/06/23 13:28:52Z]
  CHANGES:        Change Package : 26830:1 http://LISS014:6001/im/viewissue?selection=26830
  CHANGES:        Revision 1.10 2010/05/28 13:11:26CEST Stefan Hegemann 	 (shegemann) 
  CHANGES:        Merge with Fridtjof (remove STL)
  CHANGES:        --- Added comments ---  shegemann [2010/05/28 11:11:26Z]
  CHANGES:        Change Package : 26830:1 http://LISS014:6001/im/viewissue?selection=26830
  CHANGES:        Revision 1.9 2010/03/25 17:42:53CET Ulrich Wagner (uwagner) 
  CHANGES:        Pointer to local L2 memory is now provided as parameter in SFODRun()
  CHANGES:        --- Added comments ---  uwagner [2010/03/25 16:42:53Z]
  CHANGES:        Change Package : 37877:1 http://LISS014:6001/im/viewissue?selection=37877
  CHANGES:        Revision 1.8 2010/03/25 15:04:53CET Ulrich Wagner (uwagner) 
  CHANGES:        FW services for getting internal RAM modified: SFOD will now provide the amount of RAM that it needs.
  CHANGES:        --- Added comments ---  uwagner [2010/03/25 14:04:53Z]
  CHANGES:        Change Package : 37877:1 http://LISS014:6001/im/viewissue?selection=37877
  CHANGES:        Revision 1.7 2010/03/25 14:34:13CET Ulrich Wagner (uwagner) 
  CHANGES:        FW-services for internal DSP RAM (L1 & L2):
  CHANGES:        - Interface extended
  CHANGES:        - RAM-stack added to C_SFODService
  CHANGES:        --- Added comments ---  uwagner [2010/03/25 13:34:14Z]
  CHANGES:        Change Package : 37877:1 http://LISS014:6001/im/viewissue?selection=37877
  CHANGES:        Revision 1.6 2010/02/25 14:35:55CET jschmidt 
  CHANGES:        added disparity ROI start to interface
  CHANGES:        --- Added comments ---  jschmidt [2010/02/25 13:35:55Z]
  CHANGES:        Change Package : 37887:1 http://LISS014:6001/im/viewissue?selection=37887
  CHANGES:        Revision 1.5 2010/02/16 15:05:07CET jschmidt 
  CHANGES:        changed variable names
  CHANGES:        --- Added comments ---  jschmidt [2010/02/16 14:05:07Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.4 2010/02/15 15:47:05CET Ulrich Wagner (uwagner) 
  CHANGES:        Typing error corrected in SFODOpen
  CHANGES:        --- Added comments ---  uwagner [2010/02/15 14:47:05Z]
  CHANGES:        Change Package : 26829:3 http://LISS014:6001/im/viewissue?selection=26829
  CHANGES:        Revision 1.3 2010/02/15 13:40:08CET jschmidt 
  CHANGES:        added unit to baseline identifier
  CHANGES:        --- Added comments ---  jschmidt [2010/02/15 12:40:09Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.2 2010/02/15 09:12:14CET jschmidt 
  CHANGES:        changed day/rain flag
  CHANGES:        --- Added comments ---  jschmidt [2010/02/15 08:12:15Z]
  CHANGES:        Change Package : 26824:1 http://LISS014:6001/im/viewissue?selection=26824
  CHANGES:        Revision 1.1 2010/02/09 16:27:34CET jschmidt 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SFOD_StereoFastObjectDetection/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#ifndef SFOD_INTERFACE_H
#define SFOD_INTERFACE_H



// ~CodeReview ~ID:77934f03f2358c5a60091080fe37fbec ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Global: The following three files have to be removed from all files!!//B.Ramirez(uid07705) [2012/7/26, 11:33]: Original Prio:1 New Prio:3 Reason:Agree, but not Prio1.
#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifndef TARGET_DSP

#include "common_interface_defines.h"
#include "cct_type.h"


// interface to SPOD/PED (OUT =>)
#include "sfod_outputInterface.h"
// interface to PED (IN <=)
#include "ped_post_ext.h"
//error management
#include "sfod_errorState.h"

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus


static const ui32_t SFODWorkingMode_VersionNumber = 1;

/*! \brief  SFOD working mode */
typedef enum
{
  SFOD_WM_ON            = 0u,  /*!< SFOD on */ 
  SFOD_WM_SEND_DBG_DATA = 1u   /*!< SFOD send only Debug Pattern without working */ 
} SFODWorkingMode_t;



static const ui32_t SFODInterfaceCheck_VersionNumber = 1;  /*!< Version Number of enum SFODInterfaceCheck_t */

/*! \brief  SFOD interface check */
typedef enum
{
  SFOD_IC_ON              = 0u,  /*!< SFOD on */ 
  SFOD_IC_INTERFACE_CHECK = 1u   /*!< SFOD get input data and send only MeasFreaze data input */ 
} SFODInterfaceCheck_t;



static const ui32_t SFODSplittingMode_VersionNumber = 1;  /*!< Version Number of enum SFODSplittingMode_t */

/*! \brief  SFOD splitting mode */
typedef enum
{
  SFOD_EM_NORMAL     = 0u,  /*!< SFOD on */ 
  SFOD_EM_SPLIT_SFOD = 1u   /*!< SFOD execute algorithm distributed over several frames */
} SFODSplittingMode_t;


static const ui32_t SFODMountingCalibrationData_VersionNumber = 2;  /*!< Version Number of struct SFODMountingCalibrationData_t */
                                                                    /*!< 2: cast timestamp to 64 bit, rename */
typedef struct _SFODMountingCalibrationData_t
{
  DEFINE_VERSION_MEMBER(SFODMountingCalibrationData);

  /* cameraposition in AUTOSAR - coordinates  */
  f32_t  PositionX;                              /*!< X-position of camera in meters */
  f32_t  PositionY;                              /*!< Y-position of camera in meters */
  f32_t  PositionZ;                              /*!< Z-position of camera in meters */

  /* rotation from vehicle to camera coordinates
     right handed, image rows coincide with x-axis, columns with y-axis, z to optical axis */
  f32_t  Pitch;                                  /*!< x-rotation (pitch) [rad] */
  f32_t  Roll;                                   /*!< y-rotation (roll)  [rad] */
  f32_t  Yaw;                                    /*!< z-rotation (yaw)   [rad] */
  SFODSignalState_t SignalStateTimeStamp;        /*!< signal state of TimeStamp */
  ui64_t Timestamp_usec;                         /*!< time stamp when SFODMountingCalibrationData was changed by the SAC-Module in micro sec */
} SFODMountingCalibrationData_t;


static const ui32_t SFODRectifiedCalibrationData_VersionNumber = 2;  /*!< Version Number of struct SFODRectifiedCalibrationData_t */
                                                                     /*!< 2: cast Timestamp_usec to 64 bit, rename */

typedef struct _SFODRectifiedCalibrationData_t
{
  DEFINE_VERSION_MEMBER(SFODRectifiedCalibrationData);

  f32_t  FocalX;                                 /*!< camera X-coordinate focal length [pixel] */
  f32_t  FocalY;                                 /*!< camera Y-coordinate focal length [pixel] */
  f32_t  CenterX;                                /*!< X-coordinate of camera center point in image [pixel] */
  f32_t  CenterY;                                /*!< Y-coordinate of camera center point in image [pixel] */
  f32_t  Baseline_m;                             /*!< camera stereo baseline [m] */
  SFODSignalState_t SignalStateTimeStamp;        /*!< signal state of TimeStamp */
  ui64_t Timestamp_usec; /*!< time stamp when SFODRectifiedCalibrationData was changed by the SAC-Module in micro sec */
} SFODRectifiedCalibrationData_t;

typedef struct _SFODStaticInputData_t // TE: required for tests
{
  i32_t test;
} SFODStaticInputData_t;



static const ui32_t SFODVehicleData_VersionNumber = 3;  /*!< Version Number of struct SFODVehicleData_t */
                                                        /*!< 2: cast time stamps to 64 bit, rename */
                                                        /*!< 3: added bottomClearanceMin_m */

typedef struct _SFODVehicleData_t
{
  DEFINE_VERSION_MEMBER(SFODVehicleData);

  f32_t      velocity_m_per_s;
  ui64_t     velocityTimestamp_usec;                  /*!< time stamp when velocity was received in micro sec */
  SFODSignalState_t SignalStateVelocity;              /*!< signal state of velocity_m_per_s */

  f32_t      yawRate_rad_per_s;                       /*!< offset compensated */  
  ui64_t     yawRateTimestamp_usec;                   /*!< time stamp when yawRate was received in micro sec */
  SFODSignalState_t SignalStateYawRate_rad_per_s;     /*!< signal state of yawRate_rad_per_s */

  f32_t      steeringAngle_rad;                       /*!<  steering_Angle_rad = SteeringWheelAngle / SteeringRatio; */
  ui64_t     steeringAngleTimestamp_usec;             /*!< time stamp when steeringAnegle was received in micro sec */
  SFODSignalState_t SignalStateSteeringAngle_rad;     /*!< signal state of steeringAngle_rad */

  i32_t      IsRaining;                               /*!< set to 1, if rain detected by external sensor or algo, 0 if no rain detected, 2 if SNA */   

  f32_t      DistanceCOG2FrontAxis_m;                 /*!< distance of center of gravity to front axis, for Ackermann model, [m] */
  f32_t      DistanceCOG2RearAxis_m;                  /*!< distance of center of gravity to rear axis, for Ackermann model, [m] */

  f32_t      bottomClearanceMin_m;                    /*!< minimum height, the vehicle has to fit below [m] */

} SFODVehicleData_t;



static const ui32_t SFODImage_VersionNumber = 3;      /*!< Version Number of struct SFODImage_t */
                                                      /*!< 2: cast frameCounter to 32 bit, Timestamp_usec to 64 bit, rename */
                                                      /*!< 3: added "TimestampDelta_usec" */
typedef struct _SFODImage_t
{
  DEFINE_VERSION_MEMBER(SFODImage);

  ui16_t *image_p;
  i32_t   StartX_px;                                  /*!< Start of disparity ROI wrt image, x */
  i32_t   StartY_px;                                  /*!< Start of disparity ROI wrt image, y */
  i32_t   imageWidth_px; 
  i32_t   imageHeight_px;
  SFODSignalState_t SignalStateTimeStamp;             /*!< signal state of TimeStamp */
  ui64_t  Timestamp_usec;                             /*!< time stamp when SFODImage was received in micro sec */
  i32_t   TimestampDelta_usec;                         /*!< time stamp delta relative to Timestamp_usec in micro sec */
  ui32_t  frameCounter;                               /*!< Cyclic counter of frame, period 0x100, active beginning from B1 sample */

} SFODImage_t;


typedef struct _SFODOpticalFlowData_t // TE: NO VersionNumber for this struct
{
  i8_t DU;
  i8_t DV;
} SFODOpticalFlowData_t;



static const ui32_t SFODOpticalFlow_VersionNumber = 3;      /*!< Version Number of struct SFODOpticalFlow_t */
                                                            /*!< 2: cast frameCounterFlow to 32 bit, Timestamp_usec to 64 bit, rename */
                                                            /*!< 3: added "TimestampDelta_usec" */
typedef struct _SFODOpticalFlow_t
{
  DEFINE_VERSION_MEMBER(SFODOpticalFlow);

  SFODOpticalFlowData_t *data_p;
  i32_t   StartX_px;                        /*!< Start of optical flow ROI wrt image, x */
  i32_t   StartY_px;                        /*!< Start of optical flow ROI wrt image, y */
  i32_t   Width_px;                         /*!< Width of optical flow ROI */
  i32_t   Height_px;                        /*!< Height of optical flow ROI */
  SFODSignalState_t SignalStateTimeStamp;   /*!< signal state of TimeStamp */
  ui64_t  Timestamp_usec;                   /*!< time stamp when SFODOpticalFlow was received in micro sec */
  i32_t   TimestampDelta_usec;              /*!< time stamp delte in micro sec */
  ui32_t  NumberOfFlows;                    /*!< Numder of Flows computed of the FPGA in this cycle */
  ui32_t frameCounterFlow;                   /*< Cyclic counter of associated UV-map frame, periode 0x100, active beginning from B1 sample */

} SFODOpticalFlow_t;

/*! Type definition for SFODGlobalBlockageAOIDefinition_t. */
static const ui32_t SFODGlobalBlockageAOIDefinition_VersionNumber = 1;   /*!< Version Number of struct SFODGlobalBlockageAOIDefinition_t */

typedef struct _SFODGlobalBlockageAOIDefinition_t
{
	DEFINE_VERSION_MEMBER(SFODGlobalBlockageAOIDefinition);

	ui8_t			ui8_AoiIdx;			/*!< index of the AOI */
										/*!< position of the AOI */
	ui16_t			ui16_X1;	
	ui16_t			ui16_X2;
	ui16_t			ui16_Y1;
	ui16_t			ui16_Y2;
}	SFODGlobalBlockageAOIDefinition_t;

/*! Type definition for SFODGlobalBlockageInfo_t*/
static const ui32_t SFODGlobalBlockageInfo_VersionNumber = 1;		/*!< Version Number of struct SFODGlobalBlockageInfo_t */

typedef struct _SFODGlobalBlockageInfo_t
{
	DEFINE_VERSION_MEMBER(SFODGlobalBlockageInfo);

 // ~CodeReview ~ID:545e4a205a33fbdc8b423c1067625f1c ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Document range for confidence (0-100)
	/*
	ui8_Val = 
			0 means no blockage
			100 means full blockage
			between 0-100 it correspond to a level of blur
	ui8_Conf = 
			confidence on the blockage value
	*/
	ui8_t					ui8_Val;						/*!< Blockage percentage */
	ui8_t					ui8_Conf;						/*!< Confidence */

} SFODGlobalBlockageInfo_t;

/*! Type definition for SFODGlobalBlockageAOIBlockage. */
static const ui32_t  SFODGlobalBlockageAOIBlockage_VersionNumber = 1;		/*!< Version Number of struct SFODGlobalBlockageAOIBlockage */

typedef struct _SFODGlobalBlockageAOIBlockage_t
{
	DEFINE_VERSION_MEMBER(SFODGlobalBlockageAOIBlockage);

	SFODGlobalBlockageAOIDefinition_t		s_AOIDef;						/*!< current AOI definition */	
	SFODGlobalBlockageInfo_t				s_BlockageInfo;					/*!< Blockage level information */

} SFODGlobalBlockageAOIBlockage_t;

/*! Type definition for Blockage status. */
typedef enum
{
	SFOD_GB_UNKNOWN_STATUS	    = 0u,		/*!< Unknown status (init error, communication error,...) */
	SFOD_GB_NO_BLOCKAGE		    = 1u,		/*!< No Blockage */
	SFOD_GB_TOLERATED_BLOCKAGE	= 2u,		/*!< Tolerated Blockage */
	SFOD_GB_CONDENSATION		    = 3u,		/*!< Condensation */
	SFOD_GB_PART_BLOCKAGE		  = 4u,		/*!< Partial Blockage */
	SFOD_GB_LOW_VISIBILITY		  = 5u,		/*!< Low Visibility */
	SFOD_GB_BLOCKAGE			      = 6u		/*!< Blockage */
} SFODGlobalBlockageStatus_t;

/*! Type definition for the blockage of a MPC function */
static const ui32_t SFODFctGlobalBlockage_VersionNumber = 3;   /*!< Version Number of struct SFODFctGlobalBlockage_t */
															   /*!< 3: added "AOIBlockage" variable */	

typedef struct _SFODFctGlobalBlockage_t
{	
  DEFINE_VERSION_MEMBER(SFODFctGlobalBlockage);

	SFODGlobalBlockageStatus_t		globalBlockageStatus;		/*!< Blockage Status */
	ui8_t				            statusConf;			        /*!< confidence (0..100) */
	SFODGlobalBlockageAOIBlockage_t	AOIBlockage[15];				/* bad style: hard coded variable*/
} SFODFctGlobalBlockage_t;


static const ui32_t SFODDynamicInputData_VersionNumber = 7; /*!< Version Number of struct SFODDynamicInputData_t */
                                                            /*!< 2: added "Blank" variable */
                                                            /*!< 3: added  "bareFloxelTable_p"*/
                                                            /*!< 4: added  "bareFloxelTable_Height", "bareFloxelTable_Width", "bareFloxel_Size" */
                                                            /*!< 5: added  "bareFloxelTable_CheckSum" */
                                                            /*!< 6: added  "GlobalBlockageStatus" 
                                                            /*!< 7: added  "bareFloxelTable_FrameCounter" + "harvesterParameterSet_FingerPrint" */

typedef struct _SFODDynamicInputData_t
{
  DEFINE_VERSION_MEMBER(SFODDynamicInputData);

  SFODMountingCalibrationData_t  MountRight;                /*!< transformation vehicle to right camera coordinate system */
  SFODRectifiedCalibrationData_t RectifiedCalibrationData;  /*!< camera parameters of rectified stereo system */

  SFODVehicleData_t VehicleData;                            /*!< vehicle data required by SFOD */

  SFODImage_t DisparityImage;                               /*!< disparity map */

  SFODOpticalFlow_t OpticalFlow;                            /*!< optical flow data */

  SFODWorkingMode_t Mode;                                   /*!< Working Mode of the algorithm */

  SFODInterfaceCheck_t InterfaceCheck;                      /*!< Check the algorithm interface*/

  SFODSplittingMode_t SplittingMode;                        /*!< SFOD execute algorithm distributed over several frames */

  i32_t IsDay;                                              /*!< set to 1, if IC is in day mode, 0 if IC is in night mode, 2 if SNA */

  ui32_t Blank;                                             /*!< reserved */

  void  *bareFloxelTable_p;                                 /*!< pointer to array of bare floxels from FPGA (defined in "bare_floxel_table.h")*/

  i32_t bareFloxelTable_Height;                             /*!< height (number of lines) of bare floxel table */
  i32_t bareFloxelTable_Width;                              /*!< width (number of coloumns) of bare floxel table */
  i32_t bareFloxel_Size;                                    /*!< size of a single bare floxel in bytes */
  ui32_t bareFloxelTable_FrameCounter;                     /*!< frame counter */
  i16_t harvesterParameterSet_FingerPrint;                 /*!< unique harvester parameter set identifier */
  i32_t bareFloxelTable_CheckSum;                          /*!< bare floxel table checksum from FPGA */

  SFODFctGlobalBlockage_t GlobalBlockage;            /*!< global blockage status */

} SFODDynamicInputData_t;


/* interface typedefs of used services */
#ifndef __PDO__
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

#endif //__PDO__

/* *****************************************************************************
Functionname : SFODInit                                                    */ /*!
Description  : initialize SFOD algorithm with FW services

@param[in]     function pointers
@return        i32_SFOD_NO_ERROR or error code
@pre           -
@post          -
@author        Jochen Schmidt
**************************************************************************** */
// ~CodeReview ~ID:7f00a77b83cefb80d600950436470464 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODInit(
    Fct_v_CacheInvalidateAll pfct_v_CacheInvalidateAll,
    Fct_sl_DMACopy           pfct_sl_DMACopy,
    Fct_sl_DMACopy_2D        pfct_sl_DMACopy_2D,
    Fct_sl_DMACopyChained    pfct_sl_DMACopyChained,
    Fct_sl_DMAWait           pfct_sl_DMAWait,
    Fct_sl_MEASFreeze        pfct_sl_MEASFreeze,
    SFODSystemInfo_t         *pSystemInfo
);

/* *****************************************************************************
Functionname : SFODOpen                                                    */ /*!
Description  : open SFOD algorithm

@return        i32_SFOD_NO_ERROR or error code
@param[out]    pSystemInfo:       contains error and state information      -
@author        Jochen Schmidt
**************************************************************************** */
//i32_t SFODOpen(const SFODStaticInputData_t *pStaticInputData);
// presently no static input needed
// ~CodeReview ~ID:0a4b8e13aa6a9cce003d85d13b9b2bc8 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODOpen(SFODSystemInfo_t *pSystemInfo);

/* **************************************************************************** 
Functionname : SFODRun                                                    */ /*!  
Description  : run SFOD algorithm

@param[in]     pDynamicInputData: dynamic input data
@param[in]     pPEDInputData:     const pointer to PED Output Data from previous frame
@param[out]    pOutputData:       output data to fill
@param[out]    pSystemInfo:       contains error and state information

@return        i32_SFOD_NO_ERROR or error code
@pre           -
@post          -
@author        Jochen Schmidt
**************************************************************************** */
// ~CodeReview ~ID:06a173d0396dea206fdc60650b181bd3 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODRun(const SFODDynamicInputData_t *pDynamicInputData,
              const PEDPost_t_OutputData   *pPEDInputData,
              SFODOutputData_t             *pOutputData,
              SFODSystemInfo_t             *pSystemInfo,
              void                         *pvd_L2Ram,
              const                         i32_t i32_SizeOfL2Bytes
              );

/* **************************************************************************** 
Functionname : SFODPostProcess                                                    */ /*!  
Description  : incorporate PED output into SFOD output

@param[in]     pDynamicInputData: dynamic input data of PED
@param[out]    pOutputData:       output data to fill
@param[out]    pSystemInfo:       contains error and state information

@return        i32_SFOD_NO_ERROR or error code
@pre           -
@post          -
@author        Alexander Bachmann
**************************************************************************** */
// ~CodeReview ~ID:aa53d70ed8c3e93c2055f7eff445082a ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODPostProcess(const PEDPost_t_OutputData *pDynamicInputData,
                      SFODOutputData_t           *pOutputData,
                      SFODSystemInfo_t           *pSystemInfo);

/* **************************************************************************** 
Functionname : SFODGetFloxelParameterSet                                                  
Description  : xxx

@param[in]     xxx
@param[out]    xxx

@return        i32_SFOD_NO_ERROR or error code
@pre           -
@post          -
@author        Alexander Bachmann
**************************************************************************** */
// ~CodeReview ~ID:0a9f24dd1c2032a7887df57b72fa3fe5 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODGetFloxelParameterSet( const SFODOutputData_t *pInputData, SFODFloxelParamsFpga_t* pOutputData );


/* **************************************************************************** 
Functionname : SFODClose                                                  */ /*!  
Description  : close SFOD algorithm

@return        i32_SFOD_NO_ERROR or error code
@param[out]    pSystemInfo:       contains error and state information
@post          -
@author        Jochen Schmidt
**************************************************************************** */
// ~CodeReview ~ID:a958ae66512745b3125db0e815605c62 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODClose(SFODSystemInfo_t *pSystemInfo);


/* **************************************************************************** 
Functionname : SFODGetInternalState
Description  : Acessor of SFOD algorithm state data

               The framework software will make a memcopy of the current algo state after execution of 
               the run function and the state will be freezed in severals chunks over more than one frame. 
               The simulation will later on collect these chunks and provide an initialization vector for 
               the simulation of an algo component.

               This function can be called every cycle after the execution of the run function. Framework 
               software will make a memcpy of the state referenced in PV_AlgoState and freeze the data over 
               several frames. Once the full state is freezed the procedure starts again.

               The Integrators will moderate the discussion for each processor how large the algo states 
               are allowed to be (restircitions are memory bandwidth, measfreeze bandwidthm etc.


@return        i32_SFOD_NO_ERROR or 
               error code 1, i.e. function is not available

@pre           pp_PV_AlgoState points to a legal pointer variable

@post          return value is 1 or 
               return value is i32_SFOD_NO_ERROR and (*pp_PV_AlgoState) points to state data

@author        Thomas Eisenmann
**************************************************************************** */
// ~CodeReview ~ID:d573d5514cc813f247b73bb60f67e75b ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODGetInternalState (const void ** pp_PV_AlgoState, const ui32_t* length);


/* Algo Version Entity */
typedef struct 
{
  ui32_t VersionNumber; /*!< The version number consists of three uint8 which are combined in the following way: 
                           (version major <<16) + (version minor << 8) + patchlevel. All other bits are set to 0.*/ 
  char VersionInfo[51]; /*!<  Versioninfo is a null terminated string. The content is arbitrary for now. For debug 
                           versions it is recommeded to have at least a compile time/date in there and for 
                           checkpointed/released versions the checkpoint name. */
} SFODAlgoVersion_t;


/* **************************************************************************** 
Functionname : SFODGetAlgoVersion
Description  : Acessor of pointer to persistent Algorithm Version Entity

               During the startup phase of the ECU the framework software will collect the version 
               information from each component. This version information is transmitted via the database 
               to the Golddust controller. GD will transmitt the collected information via MTS and 
               will make it available via diagosis.


@return        i32_SFOD_NO_ERROR or 
               error code 1, i.e. function is not available

@pre           p_AlgoVersion points to a legal pointer variable

@post          *pAlgoVersion is the a valid FODAlgoVersion_t instance
               representing data

@author        Thomas Eisenmann
**************************************************************************** */
// ~CodeReview ~ID:3d96c04046690688f072c5c378fba847 ~Reviewer:F.Stein/O.Vogel ~Date:7/4/2012 ~Priority:3 ~Comment:Replace all input pointers with references to ensure non-NULL input. Later assign member pointers with address of references, respectively.
i32_t SFODGetAlgoVersion( SFODAlgoVersion_t * p_AlgoVersion );



#ifdef __cplusplus
  }
#endif // __cplusplus



#endif /* SFOD_INTERFACE_H */

