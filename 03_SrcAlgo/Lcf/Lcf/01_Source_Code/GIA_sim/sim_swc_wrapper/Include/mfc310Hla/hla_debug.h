/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_debug.h

  DESCRIPTION:            Definition for debugging and evaluation

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          26-10-2010

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_debug.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:32CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:42CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:07CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.49 2014/03/13 10:15:10CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed adapter for HLAD
  CHANGES:                --- Added comments ---  uidv7867 [Mar 13, 2014 10:15:10 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.48 2014/03/12 18:07:14CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:15 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.47 2014/03/04 16:51:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:59 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.46 2014/02/11 17:23:47CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved peak time meas to a better place
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 5:23:48 PM CET]
  CHANGES:                Change Package : 207432:18 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.45 2014/02/11 12:34:39CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed analysis level 1 color internal time meas
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 12:34:40 PM CET]
  CHANGES:                Change Package : 207432:18 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.44 2014/02/11 09:20:02CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed time meas
  CHANGES:                Fixed dframe calculation on HIL
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:03 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.43 2014/02/07 16:32:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed dframe calculation
  CHANGES:                Updated time meas inside segmentation
  CHANGES:                Updated HIL according to latest changes
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2014 4:32:54 PM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.42 2014/02/06 16:01:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:14 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.41 2014/01/10 18:33:31CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:31 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.40 2014/01/08 17:10:12CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactored HLA_Exec() function
  CHANGES:                Replaced uint64 time stamps by uint32 ones
  CHANGES:                Smaller bug fixes
  CHANGES:                --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:13 PM CET]
  CHANGES:                Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.39 2013/11/21 17:53:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:09 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.38.1.1 2013/11/21 13:38:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved Icon normalize
  CHANGES:                Bug fixes in segmentation
  CHANGES:                Removed no longer compiler switches
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 1:38:09 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.38 2013/11/19 13:43:08CET Brunn, Marcus (brunnm) 
  CHANGES:                added detailed time measurement for segmentation
  CHANGES:                --- Added comments ---  brunnm [Nov 19, 2013 1:43:08 PM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.37 2013/10/24 12:20:05CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Added more time meas for segmentation internally
  CHANGES:                --- Added comments ---  uidv7867 [Oct 24, 2013 12:20:05 PM CEST]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.36 2013/10/24 10:44:17CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some not needed variables
  CHANGES:                Made HLA working on evalboard
  CHANGES:                --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:17 AM CEST]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.35 2013/08/05 20:41:04CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:05 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.34 2013/05/23 09:46:16CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed hlad out simulation adapter
  CHANGES:                --- Added comments ---  uidv7867 [May 23, 2013 9:46:16 AM CEST]
  CHANGES:                Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.33 2013/03/12 14:11:33CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2013 2:11:34 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.32 2013/03/06 12:47:55CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added new time measurements to HIL
  CHANGES:                Added hlaf debug structure to HIL
  CHANGES:                --- Added comments ---  uidv7867 [Mar 6, 2013 12:47:56 PM CET]
  CHANGES:                Change Package : 167173:24 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.31 2013/03/04 11:54:05CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added HLAF timemeas
  CHANGES:                Renamed tunnel timemeas
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2013 11:54:05 AM CET]
  CHANGES:                Change Package : 167173:27 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.30 2013/02/19 07:45:30CET Brunn, Marcus (brunnm) 
  CHANGES:                fixed measfreezes from DSP (little endian)
  CHANGES:                - added endianness to Interface version number
  CHANGES:                --- Added comments ---  brunnm [Feb 19, 2013 7:45:30 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.29 2013/01/30 10:51:28CET Brunn, Marcus (brunnm) 
  CHANGES:                renamed Highway variables:
  CHANGES:                - RdwayType -> LatPos
  CHANGES:                - HwayDction -> EgoMotion
  CHANGES:                --- Added comments ---  brunnm [Jan 30, 2013 10:51:29 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.28 2013/01/28 15:06:10CET Brunn, Marcus (brunnm) 
  CHANGES:                Switched to rte like types for
  CHANGES:                - HLA_t_eRedReflectorArea
  CHANGES:                - HLA_t_eHighwayLatPosState
  CHANGES:                - HLA_t_eHighwayEgoMotionState
  CHANGES:                - HLA_t_eHighwayOcclusionState
  CHANGES:                --- Added comments ---  brunnm [Jan 28, 2013 3:06:10 PM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.27 2013/01/23 17:57:29CET Brunn, Marcus (brunnm) 
  CHANGES:                Converted enum to rte like type for
  CHANGES:                - HLA_t_eCityState
  CHANGES:                - HLA_t_eWeatherState
  CHANGES:                --- Added comments ---  brunnm [Jan 23, 2013 5:57:29 PM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.26 2013/01/23 14:56:06CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Increased interface version number
**************************************************************************** */

#ifndef HLA_DEBUG_INCLUDED
#define HLA_DEBUG_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_eve_ext.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLAD_OUT_INTERFACE_VERSION_NUMBER_MAIN    4
#define HLAD_OUT_INTERFACE_VERSION_NUMBER_SUB     1
#define HLAD_OUT_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define HLAD_OUT_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN    << 24) \
                                           | (HLAD_OUT_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                           | (HLAD_OUT_INTERFACE_VERSION_NUMBER_SUB  << 8) \
                                           | (HLAD_OUT_INTERFACE_VERSION_NUMBER_BUGFIX))

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

typedef struct 
{
  float32 OdometerAll_m;          /* [m] odometer since startup         */
  float32 OdometerStandstill_m;   /* [m] odometer since last standstill */
  
  boolean bStandstill; /* used to find transition from standstill to moving */
  
} HLAOdometer_t;

/* HLATimeMeasEvmHil_t is only needed for eval board */
typedef struct {
  uint16      dTimeReset_us;            /* HLA time during reset opmode */
  uint16      dTimeRun_us;              /* HLA time during run opmode */
  uint16      dTimeWrapperReset_us;     /* wrapper time during reset opmode */
  uint16      dTimeWrapperRun_us;       /* wrapper time during run opmode */
} HLAEvmHilTimeMeas_t; 


/* output structure for Measfreeze */
typedef struct 
{
  uint16             dTimeInit_us;
  uint16             dTimeMain_us;
  uint16             dTimeMainPeak_us;
  AlgoCycleCounter_t frameCntMainPeak;

  uint16             dTimePreProcess_us;

  uint16             dTimeSegmentation_us;
  uint16             dTimeSegmentationPeak_us;
  AlgoCycleCounter_t frameCntSegmentationPeak;
  uint16             dTimeSegmentationPreProcImg_us;
  uint16             dTimeSegmentationBuildRegions_us;
  uint16             dTimeSegmentationBuildRelationship_us;
  uint16             dTimeSegmentationBuildLights_us;
  uint16             dTimeSegmentationFindMaximaGV_us;
  uint16             dTimeSegmentationPotentialLEDDetection_us;
  uint16             dTimeSegmentationCalcLuxInt_us;
  uint16             dTimeSegmentationFindMaximaLux_us;
  uint16             dTimeSegmentationCalcRGBGradientBasedInterp_us;
  uint16             dTimeSegmentationRedLightDetection_us;
  uint16             dTimeSegmentationSetLightPosition_us;
  uint16             dTimeSegmentationRemoveDarkLights_us;
  uint16             dTimeSegmentationBuildPairLights_us;
  uint16             dTimeSegmentationLightsReduction_us;
  uint16             dTimeSegmentationBuildChainOut_us;
  uint16             dTimeSegmentationFillRteOutput_us;

  uint16             dTimeBrightness_us;

  uint16             dTimeTrack_us;
  uint16             dTimeTrackPeak_us;
  AlgoCycleCounter_t frameCntTrackPeak;
  uint16             dTimeTrackPredict_us;
  uint16             dTimeTrackPredictFindBestPairs_us;
  uint16             dTimeTrackAssoc_us;
  uint16             dTimeTrackAssocTrack2Light_us;
  uint16             dTimeTrackAssocTrack2LightSolve_us;
  uint16             dTimeTrackUpdate_us;
  uint16             dTimeTrackUpdateEpipol_us;
  uint16             dTimeTrackUpdateSlam_us;
  uint16             dTimeTrackUpdatePair_us;
  uint16             dTimeTrackUpdateTracks_us;
  uint16             dTimeTrackAdd_us;
  uint16             dTimeTrackAddPair_us;
  uint16             dTimeTrackOther_us;

  uint16             dTimeHotPixels_us;

  uint16             dTimeAnalysis_us;
  uint16             dTimeAnalysisPeak_us;
  AlgoCycleCounter_t frameCntAnalysisPeak;
  uint16             dTimeAnalysisBase_us;
  uint16             dTimeAnalysisBaseWeather_us;
  uint16             dTimeAnalysisBaseTTB_us;
  uint16             dTimeAnalysisBaseChain_us;
  uint16             dTimeAnalysisBaseStreetLamps_us;
  uint16             dTimeAnalysisBaseHorizon_us;
  uint16             dTimeAnalysisBaseRedReflectorDensity_us;
  uint16             dTimeAnalysisLevel1st_us;
  uint16             dTimeAnalysisLevel1stIntensity_us;
  uint16             dTimeAnalysisLevel1stColor_us;
  uint16             dTimeAnalysisLevel1stPulsedLight_us;
  uint16             dTimeAnalysisLevel1stMisc_us;
  uint16             dTimeAnalysisLevel1stHighway_us;
  uint16             dTimeAnalysisLevel2nd_us;
  uint16             dTimeAnalysisLevel2ndNormalize_us;
  uint16             dTimeAnalysisLevel2ndPreProcess_us;
  uint16             dTimeAnalysisLevel2ndLRF_us;
  uint16             dTimeAnalysisLevel3rd_us;

  uint16             dTimeBrightObjects_us;
  uint16             dTimeHighway_us;
  uint16             dTimeCity_us;
  uint16             dTimeTrafficStyle_us;
  uint16             dTimeTunnel_us;
  uint16             dTimePostProcess_us;

  uint16             dTimeEvePeak_us;
  AlgoCycleCounter_t frameCntEvePeak;
} HLATimeMeasurement_t;


/* turn off reason */
typedef struct
{
  /* traffic oncoming */
  uint8 vehicleOncomingFoundLastCycle;
  uint8 vehicleOncomingFound;
  uint8 vehicleOncomingFRCnt; /* first   */
  uint8 vehicleOncomingCRCnt; /* current */

  /* traffic ahead */
  uint8 vehicleAheadFoundLastCycle;
  uint8 vehicleAheadFound;
  uint8 vehicleAheadFRCnt;  /* first   */
  uint8 vehicleAheadCRCnt;  /* current */

  uint32 TurnOffReason_Current;
  uint32 TurnOffReason_First;
} HLATurnOffReason_t;

/* Highway Internal Data */
typedef struct 
{
  /* Mean Death Area */
  ARRAY(HLAHighwayStatusOncoming_t, HLA_HIGHWAY_DEATH_AREA_NUM_MEAN, OncomingHist);
  uint8  DeathAreaInd;
  float32 DistToLastOncoming;
  sint16 MeanDeathAreaX;
  sint16 MeanDeathAreaY;

  /* Counters */
  uint16 CountOncoming;
  uint16 LastCount;
  uint8 NewDeathCount;
  uint8 NewPreDeathCount;
  boolean bLastCountFirstUpdate;
  boolean bLastCountSecondUpdate;

  /* Highway detection */
  float32 DistHwayDction;
  float32 DistHwayUndef;

  /* Occlusion Detection */
  sint16  ThreshPrematureX;
  sint16  ThreshPrematureY;
  sint32  OcclusionCount;

  /* Confidences */
  float32  ConfLatPos;
  float32  ConfEgoMotion;
  float32  ConfOcclDction;

  /* Results */
  RTE_HLAR_HighwayLatPosState          eLateralPosition;
  RTE_HLAR_HighwayEgoMotionState       eEgoMotion;
  RTE_HLAR_eHighwayOcclusionState      eOcclusionDetection;
  RTE_HLAR_eHighwaySpeedDetectionState e_SpeedDetection;

  /* Highway Exit Detection */
  float32  Curvature;
  float32  DistPossibleExit;
  float32  YawIntegrate;
  float32  YawIntegrateMin;
  float32  YawIntegrateMax;
  boolean  bHwayExit;

}HLADebugHighwayData_t;

/* output structure for debug data */
typedef struct
{
  uint32                  InterfaceVersionNumber;/*!< HLAD output interface version number */
  uint32                  HLA_SWVersionNumber;   /*!< HLA Software version number */
  uint32                  HLAR_SWVersionNumber;  /*!< HLAR Software version number */
  AlgoCycleCounter_t      FrameCnt;              /*!< Frame counter */
  AlgoCycleCounter_t      HLAR_Cnt;              /*!< HLAR cycle counter  */
  AlgoCycleCounter_t      HLAS_Cnt;              /*!< HLAS cycle counter  */
  AlgoDataTimeStamp_t     TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla input data */
  AlgoDataTimeStamp_t     TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  HLATurnOffReason_t      turnOffReason;
  HLADebugHighwayData_t   HighwayData;
  HLATimeMeasurement_t    timeMeas;
  HLAEveTimeMeas_t        timeMeasEve;
} HLADebugOutputs_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

#endif /* #ifndef HLA_DEBUG_INCLUDED */
