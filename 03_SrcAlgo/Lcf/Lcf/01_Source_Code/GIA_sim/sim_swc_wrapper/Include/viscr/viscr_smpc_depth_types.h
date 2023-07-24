/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      SAC - Stereo Auto Calibration

MODULNAME:      sac_smpc_depth_types.h

DESCRIPTION:    depth types for yaw angle calib vi radar object

AUTHOR:         J. Spruck

CREATION DATE:  16.09.2011

VERSION:        $Revision: 1.1 $

CHANGES:        $Log: viscr_smpc_depth_types.h  $
CHANGES:        Revision 1.1 2021/12/13 17:28:36CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:40:31CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
CHANGES:        Revision 1.13 2012/03/14 17:31:35CET Exner, Christian (uidt8578) 
CHANGES:        - bugfix: #endif followed by non-comment
CHANGES:        - Added comments -  uidt8578 [Mar 14, 2012 5:31:36 PM CET]
CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
CHANGES:        Revision 1.12 2011/11/14 16:07:50CET Spruck, Jochen (spruckj) 
CHANGES:        Init the not learnd buffer entries of yaw angle object median buffer with the yaw angle of the temp model
CHANGES:        --- Added comments ---  spruckj [Nov 14, 2011 4:07:50 PM CET]
CHANGES:        Change Package : 87958:1 http://mks-psad:7002/im/viewissue?selection=87958
CHANGES:        Revision 1.11 2011/11/12 17:54:57CET Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Yaw angle in Temp model should be updated if the object id changed
CHANGES:        --- Added comments ---  spruckj [Nov 12, 2011 5:54:57 PM CET]
CHANGES:        Change Package : 87855:1 http://mks-psad:7002/im/viewissue?selection=87855
CHANGES:        Revision 1.10 2011/11/09 18:16:02CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Bugfix-Papenburg
CHANGES:        --- Added comments ---  uidt6711 [Nov 9, 2011 6:16:02 PM CET]
CHANGES:        Change Package : 87467:1 http://mks-psad:7002/im/viewissue?selection=87467
CHANGES:        Revision 1.9 2011/10/20 19:57:53CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Radar yaw angle does not converge bug fix
CHANGES:        --- Added comments ---  spruckj [Oct 20, 2011 7:57:53 PM CEST]
CHANGES:        Change Package : 64567:4 http://mks-psad:7002/im/viewissue?selection=64567
CHANGES:        Revision 1.8 2011/10/11 15:39:37CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - Change enable radar yaw calib conition, if radar obj is valid for x cylces use the radar based calib
CHANGES:        - Put all quality infos to internal data struct
CHANGES:        - Add get quality interface
CHANGES:        - Add the raw yaw angle to internal date struct
CHANGES:        Revision 1.7 2011/10/06 16:41:25CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Add
CHANGES:        - Error if distance between radar and stereo dist is to high
CHANGES:        - Activate the radar bases yaw angle calibration only if the rectification error is low
CHANGES:        - Use the radar based yaw anlge output only if a radar object was pressent for a time of 1 minute
CHANGES:        Revision 1.6 2011/09/29 15:18:05CEST Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        Integrate Radar-based Yaw-Calibration
CHANGES:        --- Added comments ---  uidt6711 [Sep 29, 2011 3:18:05 PM CEST]
CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.5 2011/09/29 12:07:01CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Remove typing error
CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 12:07:01 PM CEST]
CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
CHANGES:        Revision 1.4 2011/09/29 10:42:48CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Add median calculation to the yaw angle delta
CHANGES:        --- Added comments ---  spruckj [Sep 29, 2011 10:42:48 AM CEST]
CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
CHANGES:        Revision 1.3 2011/09/28 15:42:51CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - add pod box criteria
CHANGES:        - reduce quality in case of low object changes
CHANGES:        Revision 1.2 2011/09/23 16:55:37CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        - Add quality calculation for the radar yaw angle error
CHANGES:        - Remove misra issues
CHANGES:        --- Added comments ---  spruckj [Sep 23, 2011 4:55:37 PM CEST]
CHANGES:        Change Package : 79036:2 http://mks-psad:7002/im/viewissue?selection=79036
CHANGES:        Revision 1.1 2011/09/20 14:38:17CEST Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */
#ifndef SAC_SMPC_DEPTH_TYPES
#define SAC_SMPC_DEPTH_TYPES

#define VISCR_DEPTH_MEDIAN_BUFFER_LEN (15UL)

/*! Yaw angle delta median data */
typedef struct {
  SACRingBuffer_t RingBufferData;
  f32_t Buffer[VISCR_DEPTH_MEDIAN_BUFFER_LEN];
  f32_t fActMedian;
} SACMedianData_t;

/*! Yaw angle delta median data */
typedef struct {
  fAngle_t fYawAngle;                         /*!< Act yaw angle */
  f32_t    fQuality;                          /*!< Quality of the yaw angle from 0 to 1, 1 means high quality */
  f32_t    fDev;                              /*!< Deviation of the yaw angle delta */
} SACDepthYawAngleOutput_t;

/*! Yaw angle table data */
typedef struct {
  SACStatInterval_t  YawAngleInterval_1;       /*!< First stage sample interval yaw angle  */
  SACStatInterval_t  YawAngleInterval;         /*!< Final sample interval yaw angle */
  SACStatInterval_t  DeltaDistInterval_1;      /*!< First stage sample interval delta distance  */
  SACStatInterval_t  DeltaDistInterval;        /*!< Final sample interval delta distance */
  SACMedianData_t YawMedian;                   /*!< The yaw delta median informations */
  SACMedianData_t DistMedian;                  /*!< The distance median informations */
  SACMedianData_t AppliedYawAngleMedian;       /*!< Applied yaw angle median */
  SACStatInterval_t ObjIdYawAngleInterval;     /*!< Mean of yaw angle for one single obj ID */
  SACDepthYawAngleOutput_t LastObjYawAngle;    /*!< Yaw angle of last obj */
  ui32_t uiReinitAppliedMedianMask;            /*!< Reinit mask if bit is set to 1 the buffer index has to be reinit */
  f32_t  fYawAngleQuality;                     /*!< Quality of the yaw angel */
  f32_t  fYawAngleQualityStd;                  /*!< Quality of the yaw angel delta standard deviation*/
  f32_t  fYawAngleQualityDist;                 /*!< Quality of the mean delta distance */
  f32_t  fYawAngleQualityObj;                  /*!< Quality of the number of obj changes */
  f32_t  fDistDelta;                           /*!< ABS distance delta between radar and stereo obj */
  f32_t  fRadius;                              /*!< Actual absolut driven radius */
  f32_t  fRadarDistance_old;                   /*!< Radar distance from last valid cycle */
  f32_t  fStereoDistance_old;                  /*!< Stereo distance from last valid cycle */
  f32_t  fActDeltaYaw;                         /*!< Actual unfiltered yaw angle */
  f32_t  fRawYawAngle;                         /*!< Not corrected yaw angle */
  f32_t  fCorrYawAngle;                        /*!< Actual corrected yaw angle */
  ui32_t uiTotalCylces;                        /*!< Total cycles */
  ui32_t uiValidCycles;                        /*!< Valid cycles */
  ui32_t uiMaxDistCounter;                     /*!< Distance delta above thershold counter */
  i32_t  iErrorCode;                           /*!< Error code */
  f32_t  fAvailability;                        /*!< Actual availability of yaw angle radar calib */
  ui32_t uiLastObjId;                          /*!< Last object ID */
  ui8_t  uiObjectChanges;                      /*!< Object changes  */
  bool_t uiObjIdChanged;                       /*!< Flag if the Object id changes  */
  ui8_t  uiInitCycleCounter;                   /*!< Init cycle counter, if we have as stable object for about n InitCycleCounter the yaw angle delta ist used */
  bool_t bUseYawAngleDelta;                    /*!< Flag if the yaw angle delta should be used or not */
  bool_t bLinitationPassed;                    /*!< Flag if all the limitations are passed */
} SACDepthYawAngleData_t;


#endif //SAC_SMPC_DEPTH_TYPES
