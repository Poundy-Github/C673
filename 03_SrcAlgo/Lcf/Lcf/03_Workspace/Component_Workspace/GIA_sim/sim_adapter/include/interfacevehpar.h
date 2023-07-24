/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_vdy

  MODULNAME:            interfacevehpar

  DESCRIPTION:          veh par input types

  AUTHOR:               -

  CREATION DATE:        15.13.2012

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interfacevehpar.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:26CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.11 2016/10/27 17:09:18CEST Mani, Yugesh (uidj6870) 
  CHANGES:              -Adapted Sim parameter for the new SteeringWheelNumber parameter added in 9th Version
  CHANGES:              Revision 1.10 2014/01/28 15:38:05CET Wolter, Frank (wolterf) 
  CHANGES:              Added VehPar V8
  CHANGES:              - Added comments -  wolterf [Jan 28, 2014 3:38:05 PM CET]
  CHANGES:              Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGES:              Revision 1.9 2013/11/06 15:36:04CET Westhofen, Daniel (uidt2642) 
  CHANGES:              - Added VehParV6A to support SRLCAM4xx videos without VehicleLength in VehParAdd struct
  CHANGES:              --- Added comments ---  uidt2642 [Nov 6, 2013 3:36:04 PM CET]
  CHANGES:              Change Package : 198737:2 http://mks-psad:7002/im/viewissue?selection=198737
  CHANGES:              Revision 1.8 2013/07/24 14:29:16CEST Wolter, Frank (wolterf) 
  CHANGES:              added VehicleLength to VehParAdd in namespace 6
  CHANGES:              --- Added comments ---  wolterf [Jul 24, 2013 2:29:16 PM CEST]
  CHANGES:              Change Package : 189943:1 http://mks-psad:7002/im/viewissue?selection=189943
  CHANGES:              Revision 1.7 2013/07/24 13:23:50CEST Mueller, Reik (muellerr5) 
  CHANGES:              - added VehParV7 according to RTE update (SW_COMMON_03.04.00_INT-14)
  CHANGES:              --- Added comments ---  muellerr5 [Jul 24, 2013 1:23:50 PM CEST]
  CHANGES:              Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:              Revision 1.6 2013/03/08 11:01:46CET Spruck, Jochen (spruckj) 
  CHANGES:              Update veh par and veh sig adapter, add trail signal, ignition switch, wheel width and front axle to road data
  CHANGES:              --- Added comments ---  spruckj [Mar 8, 2013 11:01:47 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.5 2013/02/06 12:59:48CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:49 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.4 2013/01/23 09:14:11CET Spruck, Jochen (spruckj) 
  CHANGES:              Update VehParV5 with actual rte code
  CHANGES:              --- Added comments ---  spruckj [Jan 23, 2013 9:14:11 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.3 2013/01/22 11:01:11CET Bachmann, Alexander (uidt5584) 
  CHANGES:              apadted veh par and veh dyn to new structure
  CHANGES:              --- Added comments ---  uidt5584 [Jan 22, 2013 11:01:11 AM CET]
  CHANGES:              Change Package : 162889:21 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.2 2013/01/16 13:06:06CET Spruck, Jochen (spruckj) 
  CHANGES:              Rename namespaces, because of conflicts
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 1:06:07 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.1 2013/01/16 11:34:47CET Spruck, Jochen (spruckj) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/03_Workspace/algo/vdy_sim/vdy_adapter/include/project.pj
  **************************************************************************** */
#ifndef interfacevehpar_h__
#define interfacevehpar_h__

#if SRR_SWITCH
// SRR2xx
#ifndef REF_SPEED_NO_BINS
#define REF_SPEED_NO_BINS (40U)
#endif
#elif MFC_SWITCH
// MFC3xx
#ifndef REF_SPEED_NO_BINS
#define REF_SPEED_NO_BINS (40U)
#endif
#else
// ARS3xx
#ifndef REF_SPEED_NO_BINS
#define REF_SPEED_NO_BINS (81U)
#endif
#endif


namespace TPW_PAR_300 {

  typedef struct {
    /*! number of valid target in target list, 0 = no valid target */
    ui8_t NofTargets;
    /*! 0 = RSP_INVALID  !0 = RSP_VALID */
    ui8_t TargetListValid;
    /*! timestamp of acquisition raw data related to scan start [ms] */
    ui16_t TimeStamp;
  } TargetListInfo_t;

  typedef struct {
    fCurve_t    Curve;
    fGradient_t Gradient;
    f32_t       Variance;
    fQuality_t  Quality;
  } Curvature_t;

  typedef struct {
    fYawRate_t  YawRate;
    f32_t       Variance;
    fQuality_t  Quality;
  } YawRate_t;

  typedef struct {
    ui8_t DynStandStill;
    ui8_t DynVehicleSpeedCAN;
    ui8_t DynVehicleSpeedCorrected;
    ui8_t DynLongVehAccel;
    ui8_t StatSensHorizOffset;
    ui8_t DynVehCourseCurve;
    ui8_t DynEstYawrate;
    ui8_t DynDrvrIntStrAngle;
  } SignalState_t;


  typedef struct {
    ui8_t Versions[4];
    ui32_t Devel;
    f32_t ActSmallTargetThres;
    TargetListInfo_t TargetListInfoNear;
    TargetListInfo_t TargetListInfoFar;
    ui16_t StatClustValid;
    ui16_t NumOfClust;
    f32_t fTPWMeasRegionOfInterestMaxReqDist;
    f32_t fTPWMeasReqSmallTarThres;
    f32_t fTPWMeasRequRgLength;
    ui8_t bTPWMeasRSPCycleViolation;
    ui8_t bTPWMeasTPCycleViolation;
    ui8_t TPWMeasOpMode;
    ui8_t TPWMeasStandStill;
    fSpeed_t TPWMeasVehicleSpeedCAN;
    fSpeed_t TPWMeasVehicleSpeedCorrected;
    f32_t TPWMeasSensorPosition;
    Curvature_t CurveStandard;
    Curvature_t CurveFast;
    Curvature_t CurveYawRate;
    Curvature_t DrvIntCrv;
    YawRate_t YawRate;
    f32_t SideSlipAngleVariance;
    ui8_t VersionsOld[4];
    ui32_t DevelOld;
    f32_t ElevAng;
    ui8_t ElevChg;
    ui8_t PowRed;
    ui8_t Dummy[2];
    ui8_t SRDSysDampLocal;  
    ui8_t SignalStateDynSRRBlockage;
    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;
    fAcceleration_t TPWMeasEgoAcceleration;
    ui16_t TPWCycleTime;
    ui8_t SignalStateVehicleSpeed;
    ui8_t SignalStateSideSlipAngle;
    SignalState_t SignalState;
    f32_t MotionStatesConfidence;
    fSpeed_t TPWMeasVehicleSpeed;
    f32_t SideSlipAngle;
    f32_t TPWMeasEgoAccelerationVar;
    f32_t TPWMeasVehicleSpeedVar;
    f32_t TPWMeasVehicleSpeedCANVar;
    f32_t TPWMeasVehicleSpeedCorrectedVar;
    f32_t TPWMeasVehicleSpeedMin;
    f32_t TPWMeasVehicleSpeedMax;
    f32_t TrackWidthFront;
    f32_t WheelBase;    
    f32_t AxleLoadDistribution;
    f32_t SensorMountOffsetLong; 
    ui8_t SignalStateTrackWidthFront;
    ui8_t SignalStateWheelBase;
    ui8_t SignalStateAxleLoadDistribution;
    ui8_t SignalStateSensorMountOffsetLong;
    f32_t LaneChangeProbabilityLeft;
    f32_t LaneChangeProbabilityRight;
    ui8_t SignalStateLaneChangeProb;
    ui16_t uiVDYCycleCounter;
    ui8_t Dummy3;
    f32_t UsedAzimuthAngle;
    f32_t RecentAzimuthAngle;
    f32_t RecentAzimuthAngle_Dev;
    ui8_t RecentAzimuthMisalignmentAngleValid;
    ui8_t Reserve[3];
  } TPWInput_V11_t;


  typedef struct {
    ui8_t Versions[4];
    ui32_t Devel;
    f32_t ActSmallTargetThres;
    TargetListInfo_t TargetListInfoNear;
    TargetListInfo_t TargetListInfoFar;
    ui16_t StatClustValid;
    ui16_t NumOfClust;
    f32_t fTPWMeasRegionOfInterestMaxReqDist;
    f32_t fTPWMeasReqSmallTarThres;
    f32_t fTPWMeasRequRgLength;
    ui8_t bTPWMeasRSPCycleViolation;
    ui8_t bTPWMeasTPCycleViolation;
    ui8_t TPWMeasOpMode;
    ui8_t TPWMeasStandStill;
    fSpeed_t TPWMeasVehicleSpeedCAN;
    fSpeed_t TPWMeasVehicleSpeedCorrected;
    f32_t TPWMeasSensorPosition;
    Curvature_t CurveStandard;
    Curvature_t CurveFast;
    Curvature_t CurveYawRate;
    Curvature_t DrvIntCrv;
    YawRate_t YawRate;
    f32_t SideSlipAngleVariance;
    ui8_t VersionsOld[4];
    ui32_t DevelOld;
    f32_t ElevAng;
    ui8_t ElevChg;
    ui8_t PowRed;
    ui8_t Dummy[2];
    ui8_t SRDSysDampLocal;
    ui8_t SignalStateDynSRRBlockage;
    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;
    fAcceleration_t TPWMeasEgoAcceleration;
    ui16_t TPWCycleTime;
    ui8_t SignalStateVehicleSpeed;
    ui8_t SignalStateSideSlipAngle;
    SignalState_t SignalState;
    f32_t MotionStatesConfidence;
    fSpeed_t TPWMeasVehicleSpeed;
    f32_t SideSlipAngle;
    f32_t TPWMeasEgoAccelerationVar;
    f32_t TPWMeasVehicleSpeedVar;
    f32_t TPWMeasVehicleSpeedCANVar;
    f32_t TPWMeasVehicleSpeedCorrectedVar;
    f32_t TPWMeasVehicleSpeedMin;
    f32_t TPWMeasVehicleSpeedMax;
    f32_t TrackWidthFront;
    f32_t WheelBase;    
    f32_t AxleLoadDistribution;
    f32_t SensorMountOffsetLong; 
    ui8_t SignalStateTrackWidthFront;
    ui8_t SignalStateWheelBase;
    ui8_t SignalStateAxleLoadDistribution;
    ui8_t SignalStateSensorMountOffsetLong;
    f32_t LaneChangeProbabilityLeft;
    f32_t LaneChangeProbabilityRight;
    ui8_t SignalStateLaneChangeProb;
    /* error in 4byte alignment ui8_t followed by ui16_t */
    ui16_t uiVDYCycleCounter;
    ui8_t Dummy3;
    ui8_t Reserve[16];   
  } TPWInput_V10_t;
  /* This structure contains 253bytes which consumes 256bytes in 4byte alignment setups (3 additional bytes at the end) */

  typedef struct {
    ui8_t Versions[4];
    ui32_t Devel;
    f32_t ActSmallTargetThres;
    TargetListInfo_t TargetListInfoNear;
    TargetListInfo_t TargetListInfoFar;
    ui16_t StatClustValid;
    ui16_t NumOfClust;
    f32_t fTPWMeasRegionOfInterestMaxReqDist;
    f32_t fTPWMeasReqSmallTarThres;
    f32_t fTPWMeasRequRgLength;
    ui8_t bTPWMeasRSPCycleViolation;
    ui8_t bTPWMeasTPCycleViolation;
    ui8_t TPWMeasOpMode;
    ui8_t TPWMeasStandStill;
    fSpeed_t TPWMeasVehicleSpeedCAN;
    fSpeed_t TPWMeasVehicleSpeedCorrected;
    f32_t TPWMeasSensorPosition;
    Curvature_t CurveStandard;
    Curvature_t CurveFast;
    Curvature_t CurveYawRate;
    Curvature_t DrvIntCrv;
    YawRate_t YawRate;
    f32_t SideSlipAngleVariance;
    ui8_t VersionsOld[4];
    ui32_t DevelOld;
    f32_t ElevAng;
    ui8_t ElevChg;
    ui8_t PowRed;
    ui8_t Dummy[2];
    ui8_t SRDSysDampLocal;
    ui8_t SignalStateDynSRRBlockage;
    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;
    fAcceleration_t TPWMeasEgoAcceleration;
    ui16_t TPWCycleTime;
    ui8_t SignalStateVehicleSpeed;
    ui8_t SignalStateSideSlipAngle;
    SignalState_t SignalState;
    f32_t MotionStatesConfidence;
    fSpeed_t TPWMeasVehicleSpeed;
    f32_t SideSlipAngle;
    f32_t TPWMeasEgoAccelerationVar;
    f32_t TPWMeasVehicleSpeedVar;
    f32_t TPWMeasVehicleSpeedCANVar;
    f32_t TPWMeasVehicleSpeedCorrectedVar;
    f32_t TPWMeasVehicleSpeedMin;
    f32_t TPWMeasVehicleSpeedMax;
    f32_t TrackWidthFront;
    f32_t WheelBase;    
    f32_t AxleLoadDistribution;
    f32_t SensorMountOffsetLong; 
    ui8_t SignalStateTrackWidthFront;
    ui8_t SignalStateWheelBase;
    ui8_t SignalStateAxleLoadDistribution;
    ui8_t SignalStateSensorMountOffsetLong;
    f32_t LaneChangeProbabilityLeft;
    f32_t LaneChangeProbabilityRight;
    ui8_t SignalStateLaneChangeProb;
    ui8_t Dummy3[3];
    ui8_t Reserve[16];   
  } TPWInput_V9_t;


  /* Revision tpw.h 1.21 Version 8.0.0.0 */
  typedef struct { 
    ui8_t Versions[4];
    ui32_t Devel;
    f32_t ActSmallTargetThres;
    TargetListInfo_t TargetListInfoNear;
    TargetListInfo_t TargetListInfoFar;
    ui16_t StatClustValid;
    ui16_t NumOfClust;
    f32_t fTPWMeasRegionOfInterestMaxReqDist;
    f32_t fTPWMeasReqSmallTarThres;
    f32_t fTPWMeasRequRgLength;
    ui8_t bTPWMeasRSPCycleViolation;
    ui8_t bTPWMeasTPCycleViolation;
    ui8_t TPWMeasOpMode;
    ui8_t TPWMeasStandStill;
    fSpeed_t TPWMeasVehicleSpeedCAN;
    fSpeed_t TPWMeasVehicleSpeedCorrected;
    f32_t TPWMeasSensorPosition;
    Curvature_t CurveStandard;
    Curvature_t CurveFast;
    Curvature_t CurveYawRate;
    Curvature_t DrvIntCrv;
    YawRate_t YawRate;
    f32_t SideSlipAngleVariance;
    ui8_t VersionsOld[4];
    ui32_t DevelOld;
    f32_t ElevAng;
    ui8_t ElevChg;
    ui8_t PowRed;
    ui8_t Dummy[2];
    ui8_t SRDSysDampLocal;
    ui8_t SignalStateDynSRRBlockage;
    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;
    fAcceleration_t TPWMeasEgoAcceleration;
    ui16_t TPWCycleTime;
    ui8_t SignalStateVehicleSpeed;
    ui8_t SignalStateSideSlipAngle;
    SignalState_t SignalState;
    f32_t MotionStatesConfidence;
    fSpeed_t TPWMeasVehicleSpeed;
    f32_t SideSlipAngle;
    f32_t TPWMeasEgoAccelerationVar;
    f32_t TPWMeasVehicleSpeedVar;
    f32_t TPWMeasVehicleSpeedCANVar;
    f32_t TPWMeasVehicleSpeedCorrectedVar;
    f32_t TPWMeasVehicleSpeedMin;
    f32_t TPWMeasVehicleSpeedMax;
    f32_t TrackWidthFront;
    f32_t WheelBase;    
    f32_t AxleLoadDistribution;
    ui8_t SignalStateTrackWidthFront;
    ui8_t SignalStateWheelBase;
    ui8_t SignalStateAxleLoadDistribution;
    ui8_t Dummy2;
    f32_t LaneChangeProbabilityLeft;
    f32_t LaneChangeProbabilityRight;
    ui8_t SignalStateLaneChangeProb;
    ui8_t Dummy3[3];
    ui8_t Reserve[16];   
  } TPWInput_8_7_t;

  /* Revision tpw_input.c 1.48 Version 6.0.0.0 */
  typedef struct {

    ui8_t Versions[4];
    ui32_t Devel;
    f32_t ActSmallTargetThres;
    ui8_t NofTargetsNear;
    ui8_t TargetListValidNear;
    ui16_t TimeStampNear;
    ui8_t NofTargetsFar;
    ui8_t TargetListValidFar;
    ui16_t TimeStampFar;
    ui16_t StatClustValid;
    ui16_t NumOfClust;
    f32_t fTPWMeasRegionOfInterestMaxReqDist;
    f32_t fTPWMeasReqSmallTarThres;
    f32_t fTPWMeasRequRgLength;
    ui8_t bTPWMeasRSPCycleViolation;
    ui8_t bTPWMeasTPCycleViolation;
    ui8_t TPWMeasOpMode;
    ui8_t TPWMeasStandStill;
    fSpeed_t TPWMeasVehicleSpeedCAN;
    fSpeed_t TPWMeasVehicleSpeedCorrected;
    f32_t TPWMeasSensorPosition;
    fCurve_t CurveStandard;
    fGradient_t GradientStandard;
    f32_t QualityStandard;
    fCurve_t CurveFast;
    fGradient_t GradientFast;
    f32_t QualityFast;
    fCurve_t CurveYawRate;
    fGradient_t GradientYawRate;
    f32_t QualityYawRate;
    fCurve_t DrvIntCrv;
    fGradient_t DrvIntCrvGrad;
    f32_t DrvIntCrvVariance;
    fYawRate_t EstYawRate;
    f32_t EstYawRateVariance;
    f32_t SideSlipAngleVariance;
    ui8_t VersionsOld[4];
    ui32_t DevelOld;
    f32_t ElevAng;
    ui8_t ElevChg;
    ui8_t PowRed;
    ui8_t Dummy[2];
    ui8_t SRDSysDampLocal;
    ui8_t SignalStateDynSRRBlockage;
    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;
    fAcceleration_t TPWMeasEgoAcceleration;
    ui16_t TPWCycleTime;
    ui8_t SignalStateVehicleSpeed;
    ui8_t SignalStateSideSlipAngle;
    ui8_t SignalStateDynStandStill;
    ui8_t SignalStateDynVehicleSpeedCAN;
    ui8_t SignalStateDynVehicleSpeedCorrected;
    ui8_t SignalStateDynLongVehAccel;
    ui8_t SignalStateStatSensHorizOffset;
    ui8_t SignalStateDynVehCourseCurve;
    ui8_t SignalStateDynEstYawrate;
    ui8_t SignalStateDynDrvrIntStrAngle;
    f32_t MotionStatesConfidence;
    fSpeed_t TPWMeasVehicleSpeed;
    f32_t SideSlipAngle;
    f32_t TPWMeasEgoAccelerationVar;
    f32_t TPWMeasVehicleSpeedVar;
    f32_t TPWMeasVehicleSpeedCANVar;
    f32_t TPWMeasVehicleSpeedCorrectedVar;
    f32_t TPWMeasVehicleSpeedMin;
    f32_t TPWMeasVehicleSpeedMax;
    f32_t TrackWidthFront;
    f32_t WheelBase;    
    f32_t AxleLoadDistribution;
    ui8_t SignalStateTrackWidthFront;
    ui8_t SignalStateWheelBase;
    ui8_t SignalStateAxleLoadDistribution;
  } TPWInput_V6_t;

  typedef struct {
    /*! Version of measurement data block */
    ui8_t Versions[4];
    /*! Developer tag (name, signature) */
    ui32_t Devel;

    /*! Actual lowering of RCS-threshold (used for higher damping) */
    f32_t ActSmallTargetThres;

    /*! Data Pool for Target list near RSPTargetListNear_t TPWTargetListNear */
    /*! number of valid target in target list, 0 = no valid target */
    ui8_t NofTargetsNear;
    /*! 0 = RSP_INVALID  !0 = RSP_VALID */
    ui8_t TargetListValidNear;
    /*! timestamp of acquisition raw data related to scan start [ms] */
    ui16_t TimeStampNear;

    /*! Data Pool for Target list far RSPTargetListFar_t  TPWTargetListFar */
    /*! number of valid target in target list, 0 = no valid target */
    ui8_t NofTargetsFar;
    /*! 0 = RSP_INVALID  !0 = RSP_VALID */
    ui8_t TargetListValidFar;
    /*! timestamp of acquisition raw data related to scan start [ms] */
    ui16_t TimeStampFar;

    /*! Data Pool for stationary clusters RSPStatClustList_t TPWStatClusterList */
    /*! tells if stat cluster list is valid; 0 = RSP_INVALID; !0 = RSP_VALID*/  
    ui16_t StatClustValid;
    /*! num of cluster in cluster list */
    ui16_t NumOfClust;

    /*! Data Pool for region of interest RSPRegionOfInterst_t TPWRegionOfInterest */
    /*! maximum distance for which processing is wished range: 50 ... 200 m */
    f32_t fTPWMeasRegionOfInterestMaxReqDist;

    f32_t fTPWMeasReqSmallTarThres;

    /*! Required rangegate length: */
    f32_t fTPWMeasRequRgLength;

    /*! Information of cycle violation of RSP */
    ui8_t bTPWMeasRSPCycleViolation;

    /*! Information of cycle violation of TP */
    ui8_t bTPWMeasTPCycleViolation;

    /*! operation mode of TPW for all wrapped components: */
    ui8_t TPWMeasOpMode;

    ui8_t TPWMeasStandStill;

    fSpeed_t TPWMeasVehicleSpeedCAN;

    fSpeed_t TPWMeasVehicleSpeedCorrected;

    f32_t TPWMeasSensorPosition;

    fCurve_t CurveStandard;
    fGradient_t GradientStandard;
    f32_t QualityStandard;

    fCurve_t CurveFast;
    fGradient_t GradientFast;
    f32_t QualityFast;

    fCurve_t CurveYawRate;
    fGradient_t GradientYawRate;
    f32_t QualityYawRate;

    fCurve_t DrvIntCrv;
    fGradient_t DrvIntCrvGrad;
    f32_t DrvIntCrvVariance;

    fYawRate_t EstYawRate;
    f32_t EstYawRateVariance;

    /* fGradient_t EstYawRateGradient; */

    /*! @ todo sort this list, value is at the bottom of struct   */
    /*f32_t         SideSlipAngle;  */
    f32_t SideSlipAngleVariance;

    /*! for Data Block consistency: */
    ui8_t VersionsOld[4];
    ui32_t DevelOld;

    /*! Kontext data:RSPKontextData_t Data Pool for Kontext of RSP->TP */
    /*! elevation angle [°]*/
    f32_t ElevAng;
    /*! elevation is currently changing: 0 = elevation does not change, !0 = elevation changes */
    ui8_t ElevChg;
    /*! power reduction: 0 = power normal, !0 = power recuced */
    ui8_t PowRed;
    /*! IPC Dummy */
    ui8_t Dummy[2];

    /*! Blockage information */
    ui8_t SRDSysDampLocal;
    /*! Blockage information valid */
    ui8_t SignalStateDynSRRBlockage;

    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;

    /*! Vehicle ego acceleration */
    fAcceleration_t TPWMeasEgoAcceleration;

    /*! CycleTime by SYS */
    ui16_t TPWCycleTime;

    /*! Signal State of compensated vehicle speed */
    ui8_t SignalStateVehicleSpeed;

    /*! Signal State of side slip angle */
    ui8_t SignalStateSideSlipAngle;

    ui8_t SignalStateDynStandStill;

    ui8_t SignalStateDynVehicleSpeedCAN;

    ui8_t SignalStateDynVehicleSpeedCorrected;

    ui8_t SignalStateDynLongVehAccel;

    ui8_t SignalStateStatSensHorizOffset;

    ui8_t SignalStateDynVehCourseCurve;

    ui8_t SignalStateDynEstYawrate;

    ui8_t SignalStateDynDrvrIntStrAngle;

    f32_t MotionStatesConfidence;

    fSpeed_t TPWMeasVehicleSpeed;

    /*! @todo to be sorted  */
    f32_t SideSlipAngle;

    /* extension */
    f32_t TPWMeasEgoAccelerationVar;

    f32_t TPWMeasVehicleSpeedVar;

    f32_t TPWMeasVehicleSpeedCANVar;

    f32_t TPWMeasVehicleSpeedCorrectedVar;

    f32_t TPWMeasVehicleSpeedMin;

    f32_t TPWMeasVehicleSpeedMax;

    f32_t TrackWidthFront;

    f32_t WheelBase;    

    f32_t AxleLoadDistribution;

    ui8_t SignalStateTrackWidthFront;

    ui8_t SignalStateWheelBase;

    ui8_t SignalStateAxleLoadDistribution;

    f32_t LaneChangeProbabilityLeft;

    f32_t LaneChangeProbabilityRight;

    ui8_t SignalStateLaneChangeProb;

  } TPWInput_V7_ARS350_t;

  /* Revision tpw_input.c 1.54.1.1 Version 6.0.0.0 branch for ARS350*/
  typedef struct {
    /*! Version of measurement data block */
    ui8_t Versions[4];
    /*! Developer tag (name, signature) */
    ui32_t Devel;

    /*! Actual lowering of RCS-threshold (used for higher damping) */
    f32_t ActSmallTargetThres;

    /*! Data Pool for Target list near RSPTargetListNear_t TPWTargetListNear */
    /*! number of valid target in target list, 0 = no valid target */
    ui8_t NofTargetsNear;
    /*! 0 = RSP_INVALID  !0 = RSP_VALID */
    ui8_t TargetListValidNear;
    /*! timestamp of acquisition raw data related to scan start [ms] */
    ui16_t TimeStampNear;

    /*! Data Pool for Target list far RSPTargetListFar_t  TPWTargetListFar */
    /*! number of valid target in target list, 0 = no valid target */
    ui8_t NofTargetsFar;
    /*! 0 = RSP_INVALID  !0 = RSP_VALID */
    ui8_t TargetListValidFar;
    /*! timestamp of acquisition raw data related to scan start [ms] */
    ui16_t TimeStampFar;

    /*! Data Pool for stationary clusters RSPStatClustList_t TPWStatClusterList */
    /*! tells if stat cluster list is valid; 0 = RSP_INVALID; !0 = RSP_VALID*/  
    ui16_t StatClustValid;
    /*! num of cluster in cluster list */
    ui16_t NumOfClust;

    /*! Data Pool for region of interest RSPRegionOfInterst_t TPWRegionOfInterest */
    /*! maximum distance for which processing is wished range: 50 ... 200 m */
    f32_t fTPWMeasRegionOfInterestMaxReqDist;

    f32_t fTPWMeasReqSmallTarThres;

    /*! Required rangegate length: */
    f32_t fTPWMeasRequRgLength;

    /*! Information of cycle violation of RSP */
    ui8_t bTPWMeasRSPCycleViolation;

    /*! Information of cycle violation of TP */
    ui8_t bTPWMeasTPCycleViolation;

    /*! operation mode of TPW for all wrapped components: */
    ui8_t TPWMeasOpMode;

    ui8_t TPWMeasStandStill;

    fSpeed_t TPWMeasVehicleSpeedCAN;

    fSpeed_t TPWMeasVehicleSpeedCorrected;

    f32_t TPWMeasSensorPosition;

    fCurve_t CurveStandard;
    fGradient_t GradientStandard;
    f32_t QualityStandard;

    fCurve_t CurveFast;
    fGradient_t GradientFast;
    f32_t QualityFast;

    fCurve_t CurveYawRate;
    fGradient_t GradientYawRate;
    f32_t QualityYawRate;

    fCurve_t DrvIntCrv;
    fGradient_t DrvIntCrvGrad;
    f32_t DrvIntCrvVariance;

    fYawRate_t EstYawRate;
    f32_t EstYawRateVariance;

    /* fGradient_t EstYawRateGradient; */

    /*! @ todo sort this list, value is at the bottom of struct   */
    /*f32_t         SideSlipAngle;  */
    f32_t SideSlipAngleVariance;

    /*! for Data Block consistency: */
    ui8_t VersionsOld[4];
    ui32_t DevelOld;

    /*! Kontext data:RSPKontextData_t Data Pool for Kontext of RSP->TP */
    /*! elevation angle [°]*/
    f32_t ElevAng;
    /*! elevation is currently changing: 0 = elevation does not change, !0 = elevation changes */
    ui8_t ElevChg;
    /*! power reduction: 0 = power normal, !0 = power recuced */
    ui8_t PowRed;
    /*! IPC Dummy */
    ui8_t Dummy[2];

    /*! Blockage information */
    ui8_t SRDSysDampLocal;
    /*! Blockage information valid */
    ui8_t SignalStateDynSRRBlockage;

    ui8_t MotionStates;
    ui8_t SignalStateMotionStates;

    /*! Vehicle ego acceleration */
    fAcceleration_t TPWMeasEgoAcceleration;

    /*! CycleTime by SYS */
    ui16_t TPWCycleTime;

    /*! Signal State of compensated vehicle speed */
    ui8_t SignalStateVehicleSpeed;

    /*! Signal State of side slip angle */
    ui8_t SignalStateSideSlipAngle;

    ui8_t SignalStateDynStandStill;

    ui8_t SignalStateDynVehicleSpeedCAN;

    ui8_t SignalStateDynVehicleSpeedCorrected;

    ui8_t SignalStateDynLongVehAccel;

    ui8_t SignalStateStatSensHorizOffset;

    ui8_t SignalStateDynVehCourseCurve;

    ui8_t SignalStateDynEstYawrate;

    ui8_t SignalStateDynDrvrIntStrAngle;

    f32_t MotionStatesConfidence;

    fSpeed_t TPWMeasVehicleSpeed;

    /*! @todo to be sorted  */
    f32_t SideSlipAngle;

    /* extension */
    f32_t TPWMeasEgoAccelerationVar;

    f32_t TPWMeasVehicleSpeedVar;

    f32_t TPWMeasVehicleSpeedCANVar;

    f32_t TPWMeasVehicleSpeedCorrectedVar;

    f32_t TPWMeasVehicleSpeedMin;

    f32_t TPWMeasVehicleSpeedMax;

    f32_t TrackWidthFront;

    f32_t WheelBase;    

    f32_t AxleLoadDistribution;

    ui8_t SignalStateTrackWidthFront;

    ui8_t SignalStateWheelBase;

    ui8_t SignalStateAxleLoadDistribution;

    f32_t LaneChangeProbabilityLeft;

    f32_t LaneChangeProbabilityRight;

  } TPWInput_V6_ARS350_t;
}

namespace RSP_PAR_300 {
#define INTERFACE_VDATA_RSP_VIRTUAL_ADDRESS 0x06003000uL

#define LAST_KNOWN_INTERF_VERSION_VDATA_RSP INTERFACE_NO8
/*! Amount of RSP Input VData interface versions. Substractíon of one because one version (INTERFACE_NO1) is not used! */
/*! A check is made with these numbers ! */
#define VDATA_INTERFACE_VERSIONS (RSP_INTERF_VER_VDATA_RSP - 1)



typedef unsigned __int8 iRSPFlag_t;
typedef unsigned __int8 RSPValidFlag_t;
typedef float fRSPSystemTemp_t;
typedef float fRSPCovDamping_t;
typedef float fRSPSystemTemp_t;

typedef float fRSPAccel_t;
typedef unsigned __int16 iRSPLatency_t;
typedef unsigned __int8 RSPMotionState_t;

typedef float fRSPSensorHeight_t;
typedef float fRSPHeight_t;

typedef unsigned int iRSPInterfaceVersion_t_V11;
typedef float fRSPYawRate_t_V20;

/* 
  please remove the following  define-s when the 
  header file which owns them will be included
*/
#ifndef RSP_M_STATE_REV
#define RSP_M_STATE_REV     ((RSPMotionState_t) 0)
#endif
#ifndef RSP_M_STATE_FWD
#define RSP_M_STATE_FWD     ((RSPMotionState_t) 1)
#endif
#ifndef RSP_M_STATE_UNCLEAR
#define RSP_M_STATE_UNCLEAR ((RSPMotionState_t) 2)
#endif
#ifndef RSP_M_STATE_STDSTL
#define RSP_M_STATE_STDSTL  ((RSPMotionState_t) 3)
#endif


///////////////////////////////////////////////////////////////////////
// VData Input Data Version 1
///////////////////////////////////////////////////////////////////////

typedef struct
{
  float Curve;
  unsigned char Valid;
  unsigned char Dummy[3];
} RSPCurve_t_V1;

typedef enum
{
  /*! Sensor orientation normal */
  RSP_SENSOR_OR_NORMAL_1  =0, 
  /*! Sensor orientation rotated */
  RSP_SENSOR_OR_ROTATED_1 =!0
} eRSPSensorOrient_t_V1;
/*! Describes sensor mounting positon and orientation in vehicle */
typedef struct
{
  float Height;
  float Offset;
  eRSPSensorOrient_t_V1 Rotated;
} RSPSensorGeom_t_V1;
/*! RSP enviroment data such as vehicle data */ 

/*! RSP enviroment data such as vehicle data */ 
typedef struct
{ 
  /*! Vehicle speed form wheelspeeds [m/s] */
  float VehicleSpeed;
  /*! Vehicle speed form wheelspeeds corrected [m/s] */
  float VehicleSpeedCorr;
  /*! Actual curve  */
  RSPCurve_t_V1 Curve;
  /*! Mounting position of sensor */
  RSPSensorGeom_t_V1 SensorGeometry;
  /*! Sensor temperature [K] */
  fRSPSystemTemp_t SensorTemperature;
  /*! Cover damping [dB] */
  fRSPCovDamping_t CovDamping;
} RSPInputVData_t_V1;

///////////////////////////////////////////////////////////////////////
// VData Input Data Version 7
///////////////////////////////////////////////////////////////////////

/*! default vehicle speed variance */
#define RSP_V_SPEED_VAR_DEFAULT_V7  (float)         (2.8f)
/*! default vehicle acceleration */
#define RSP_ACCEL_DEFAULT_V7        (fRSPAccel_t)         (0.f)
/*! default vehicle acceleration variance */
#define RSP_ACCEL_VAR_DEFAULT_V7    (fRSPAccel_t)         (9.81f)
/*! default vehicle speed */
#define RSP_V_SPEED_DEFAULT_V7      (float)         (0.f)
/*! default vehicle speed variance */
#define RSP_V_SPEED_VAR_DEFAULT_V7  (float)         (2.8f)
/*! default latency time */
#define RSP_LATENCY_DEFAULT_V7      (iRSPLatency_t)       (10)

/*! default vehicle motion state */
#define RSP_MOTION_STATE_DEFAULT  (RSPMotionState_t)    RSP_M_STATE_FWD
/*! default vehicle motion state confidence */ 
#define RSP_MOTION_STATE_CONF_DEFAULT (f32_t)           (0.f)

typedef float fRSPAccel_t_V7;
typedef unsigned __int16 iRSPLatency_t_V7;

/*! RSP enviroment data such as vehicle data */ 
typedef struct
{ 
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_V1 Curve;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t_V7 VehicleLongAccel;
  fRSPAccel_t_V7 VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;  
  iRSPLatency_t_V7 VehicleSpeedLatency;
  iRSPLatency_t_V7 VehicleAccelLatency;
} RSPInputVData_t_V7;


/*! RSP enviroment data such as vehicle data RSP V10*/ 
typedef struct
{ 
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_V1 Curve;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax; 
  iRSPLatency_t VehicleSpeedLatency;
  iRSPLatency_t VehicleAccelLatency;
  RSPMotionState_t MotionState;
  ui8_t Dummy1[3];
  f32_t MotionStateConf;

} RSPInputVData_t_V10;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_V1 Curve;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;  
  iRSPLatency_t VehicleSpeedLatency;
  iRSPLatency_t VehicleAccelLatency;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy1;
  f32_t MotionStateConf;
} RSPInputVData_t_IV2;


namespace RSPEolMeasRange_IV3
{
  typedef f32_t fRSPDistance_t;
}

typedef struct
{
  /*! required measurement range */
  RSPEolMeasRange_IV3::fRSPDistance_t MeasurementRange;
  /*! gives information if the measurement range is trustworthy 
      0 = RSP_INVALID  1 = RSP_VALID                      */
  RSPValidFlag_t Valid;
  /*! IPC Dummy */
  ui8_t Dummy[3];

} RSPEolMeasRange_t_IV3;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_V1 Curve;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax; 
  iRSPLatency_t VehicleSpeedLatency;
  iRSPLatency_t VehicleAccelLatency;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy;
  f32_t MotionStateConf;
  RSPEolMeasRange_t_IV3 MeasurementRange;
} RSPInputVData_t_IV3;

typedef struct
{
  float Curve;
  float Variance;
  RSPValidFlag_t Valid;
  ui8_t Dummy[3];
} RSPCurve_t_IV4;

typedef struct
{
  float YawRate;
  float Variance;
  RSPValidFlag_t Valid;
  ui8_t Dummy[3];
} RSPYawRate_t_IV4;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_IV4 Curve;
  RSPYawRate_t_IV4 YawRate;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax; 
  iRSPLatency_t VehicleSpeedLatency;
  iRSPLatency_t VehicleAccelLatency;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy;
  f32_t MotionStateConf;
  RSPEolMeasRange_t_IV3 MeasurementRange;
} RSPInputVData_t_IV4;

#define RSP_DIST_MID_ELEV_ANGLE_MIN_IV5 3
#define RSP_DIST_MID_ELEV_ANGLE_MAX_IV5 11
#define RSP_SIZE_DIST_MID_TAB_IV5  (RSP_DIST_MID_ELEV_ANGLE_MAX_IV5 - RSP_DIST_MID_ELEV_ANGLE_MIN_IV5 + 1)

typedef enum
{
  SA_PRIO_OT_OT_IV5,
  SA_PRIO_RB_RB_IV5,
  SA_PRIO_RB_OT_IV5,
  SA_PRIO_OT_RB_IV5
} RSPAlignWSPriority_t_IV5;

namespace RSPSlaveParameters_IV5
{
  typedef f32_t fRSPAngle_t;
  typedef f32_t fRSPDistance_t;
  typedef f32_t fRSPPowLog_t;
}

typedef struct
{
  RSPSlaveParameters_IV5::fRSPAngle_t EOLMaxMisalignElev;
  RSPSlaveParameters_IV5::fRSPAngle_t EOLMaxMisalignAzim;
  RSPSlaveParameters_IV5::fRSPAngle_t ServAlignMaxMisalignElev;
  RSPSlaveParameters_IV5::fRSPAngle_t ServAlignMaxMisalignAzim;
  RSPSlaveParameters_IV5::fRSPAngle_t AlignMonMaxMisalignElev;
  RSPSlaveParameters_IV5::fRSPAngle_t AlignMonMaxMisalignAzim;
  RSPSlaveParameters_IV5::fRSPAngle_t EOLScanRangeElev;
  RSPSlaveParameters_IV5::fRSPDistance_t EOLDistRefPlate;
  RSPAlignWSPriority_t_IV5 ServAlignPrio;
  RSPSlaveParameters_IV5::fRSPPowLog_t EOLPwrThreshTolerance;
  fRSPSensorHeight_t RdBmElArrayRefInstHeight;
  RSPSlaveParameters_IV5::fRSPDistance_t RdBmElDistMidTable[RSP_SIZE_DIST_MID_TAB_IV5]; 
  RSPSlaveParameters_IV5::fRSPAngle_t AlignMonMaxAdjustAzim;
  ui8_t MinSpeedServAlign;
  ui8_t MaxSpeedServAlign;
  ui8_t MinSpeedAlignMon;
  ui8_t MaxSpeedAlignMon;
} RSPSlaveParameters_t_IV5;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_IV4 Curve;
  RSPYawRate_t_IV4 YawRate;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;
  iRSPLatency_t VehicleSpeedLatency;
  iRSPLatency_t VehicleAccelLatency;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy;
  f32_t MotionStateConf;
  RSPEolMeasRange_t_IV3 MeasurementRange;
  RSPSlaveParameters_t_IV5 SlaveParameters;
} RSPInputVData_t_IV5;

namespace RSPYawRateSignal_IV6
{
  typedef f32_t fRSPQuality_t;
}

typedef struct
{
  fRSPYawRate_t_V20 YawRate;
  fRSPYawRate_t_V20 Variance;
  RSPYawRateSignal_IV6::fRSPQuality_t Quality;
  RSPValidFlag_t Valid;
  ui8_t Dummy[3];
} RSPYawRateSignal_t_IV6;

typedef struct
{
  RSPYawRateSignal_t_IV6 Vehicle;
  RSPYawRateSignal_t_IV6 Gyro;
} RSPYawRate_t_IV6;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_IV4 Curve;
  RSPYawRate_t_IV6 YawRate;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy;
  f32_t MotionStateConf;
  RSPEolMeasRange_t_IV3 MeasurementRange;
  RSPSlaveParameters_t_IV5 SlaveParameters;
} RSPInputVData_t_IV6;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_IV4 Curve;
  RSPYawRate_t_IV6 YawRate;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy;
  f32_t MotionStateConf;
  RSPEolMeasRange_t_IV3 MeasurementRange;
} RSPInputVData_t_IV7;

typedef struct
{
  iRSPFlag_t InRange;
  iRSPFlag_t Valid;
  ui8_t IPCDummy[2];
} RSPVehicleLevel_t_IV8;

typedef struct
{
  iRSPInterfaceVersion_t_V11 InterfaceVersion;
  float VehicleSpeed;
  float VehicleSpeedCorr;
  RSPCurve_t_IV4 Curve;
  RSPYawRate_t_IV6 YawRate;
  RSPSensorGeom_t_V1 SensorGeometry;
  fRSPSystemTemp_t SensorTemperature;
  fRSPCovDamping_t CovDamping;
  float VehicleSpeedVar;
  fRSPAccel_t VehicleLongAccel;
  fRSPAccel_t VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;
  RSPMotionState_t MotionState;
  iRSPFlag_t  VehicleSpeedCorrValid;
  iRSPFlag_t  VehicleLongAccelValid;
  ui8_t Dummy;
  f32_t MotionStateConf;
  RSPEolMeasRange_t_IV3 MeasurementRange;
  RSPVehicleLevel_t_IV8 VehicleLevel;
} RSPInputVData_t_IV8;


/************************* V-Data ****************************/

/*! sensor orientation can be normal or 180° rotated */
typedef enum
{
  /*! Sensor orientation normal */
  RSP_SENSOR_OR_NORMAL_L  =0, 
  /*! Sensor orientation rotated */
  RSP_SENSOR_OR_ROTATED_L =!0
} eRSPSensorOrient_t_IVL;
/*! structure for end-of-line-test measurement range */
typedef struct
{
  float MeasurementRange;
  unsigned char Valid;
  unsigned char Dummy[3];
} RSPEolMeasRange_t_IVL;
/*! Describes sensor mounting positon and orientation in vehicle */
typedef struct
{
  float Height;
  float Offset;
  eRSPSensorOrient_t_IVL Rotated;
} RSPSensorGeom_t_IVL;
/*! RSP enviroment data such as vehicle data */ 


typedef struct
{
  float YawRate;
  float Variance;
  float Quality;
  unsigned char Valid;
  /*! IPC Dummy */
  unsigned char Dummy[3];
} RSPYawRateSignal_t_IVL;
/*! structure for yaw rate information */
typedef struct
{
  RSPYawRateSignal_t_IVL Vehicle;
  RSPYawRateSignal_t_IVL Gyro;
} RSPYawRate_t_IVL;
/*! structure for curve information */
typedef struct
{
  float Curve;
  float Variance;
  unsigned char Valid;
  unsigned char Dummy[3];
} RSPCurve_t_IVL;
typedef struct
{
  float VehicleSpeed;
  float VehicleSpeedCorr;

  RSPCurve_t_IVL Curve;
  RSPYawRate_t_IVL YawRate;
  RSPSensorGeom_t_IVL SensorGeometry;

  fRSPSystemTemp_t SensorTemperature;

  float CovDamping;
  float VehicleSpeedVar;

  float VehicleLongAccel;
  float VehicleLongAccelVar;
  float VehicleSpeedCorrVar;
  float VehicleSpeedCorrMin;
  float VehicleSpeedCorrMax;
  unsigned char MotionState;
  unsigned char  VehicleSpeedCorrValid;
  unsigned char  VehicleLongAccelValid;
  unsigned char Dummy;
  float MotionStateConf;
  RSPEolMeasRange_t_IVL MeasurementRange;
} RSPVData_t_IVL;


/*! Struct for the RSP input data transmitted by VDATA */
typedef struct
{
  /*! VData -> RSP interface version */
  unsigned int InterfaceVersion;
  /*! Vehicle and enviromentdata input for RSP */
  RSPVData_t_IVL VData;
} RSPInputVData_t_IVL;




/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

//void SwapRSPInputVDataV1( RSPInputVData_t_V1* pRSPInputVDataIn, RSPInputVData_t* pRSPInputVDataOut );
//void SwapRSPInputVDataV7( RSPInputVData_t_V7* pRSPInputVDataIn, RSPInputVData_t* pRSPInputVDataOut );
//void SwapRSPInputVDataV10( RSPInputVData_t_V10* pRSPInputVDataIn, RSPInputVData_t* pRSPInputVDataOut );

//void InitRSPInputVData(/*SIMSIGNALARRAY &SimSignals*/);
//void GetRSPInputVData (/*SIMSIGNALARRAY &SimSignals, SIMPARAMETERARRAY &Simparameters, */RSPInputVData_t* RSPInputVData);

/* New VDATA System */
//int CheckRSPInputVData (/*SIMSIGNALARRAY &SimSignals, SIMPARAMETER &SimParaError, */DWORD InterfaceVersionIn, BYTE bUseRSPInputVData);
//void DefaultRSPInputVData (RSPVData_t *RSPVData);
//void GetVDataStaticData (/*SIMSIGNALARRAY &SimSignalsIn, */RSPInputVData_t *RSPInputVData, DWORD InterfaceVersionIn);
//void GetVDataDynamicData (/*SIMSIGNALARRAY &SimSignalsIn, */RSPInputVData_t *RSPInputVData, DWORD InterfaceVersionIn);
//void GetVDYDynamicData (/*SIMSIGNALARRAY &SimSignalsIn, */RSPInputVData_t *RSPInputVData, DWORD InterfaceVersionIn);
//void CopyDelayBuffersConditional (/*SIMSIGNALARRAY &SimSignalsIn, */RSPInputVData_t *RSPInputVData, DWORD InterfaceVersionIn, BYTE bUseRSPInputVData);
//void OffsetToRSPInputVData (/*SIMSIGNALARRAY &SimSignalsIn, */RSPInputVData_t *RSPInputVData, DWORD InterfaceVersionIn);
/* End New VDATA System */

/*! Convert VDY signal long motion state to VDATA signal */
/*! Longitudinal motion state values */
/*! Typedefinition for vehicle motion state. */

#define VDATA_SIG_STATUS_OK 1
#define VDATA_SIG_STATUS_NOT_OK 0
#define RSP_VDY_TO_VDATA_STATE(vdy_stat_)  (((vdy_stat_==VDY_IO_STATE_VALID) ? VDATA_SIG_STATUS_OK : VDATA_SIG_STATUS_NOT_OK))

}

namespace VDY_PAR_300 {
/* old vdy input data stuct versions  */

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*! @description: General activity state 
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t  VDYActState_t;

/*! @description: Understeer gradient 
  @resolution: tbd   @unit: rad/(m/s^2)    @min: 0     @max: 0.5 */
typedef f32_t fVDYSlfStGrad_t;

/*! @description: Wheel load dependency  
  @resolution: tbd   @unit: 1     @min: 1.0   @max: 2.0  */
typedef f32_t fVDYWhlLdDep_t;

/*! @description: VDYIoState_t  
  @resolution: tbd   @unit: tbd   @min: 0     @max: tbd  */
typedef ui32_t VDYIoState_t;

#if ((!defined(VDY_IO_STATE_VALID)) && (!defined(VDY_IO_STATE_INVALID)) && (!defined(VDY_IO_STATE_NOTAVAIL)))
/*! Values for the VDY I/O state 2 bit pairs */
typedef enum eVDYIoState_t {
  VDY_IO_STATE_VALID    = ((VDYIoState_t) 0U),
  VDY_IO_STATE_INVALID  = ((VDYIoState_t) 1U),
  VDY_IO_STATE_NOTAVAIL = ((VDYIoState_t) 2U)
} eVDYIoState_t;
#endif

/*! @description: VDYDriveAxle_t  
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t VDYAxle_t;

/*! @description: Vehicle motion state  
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t VDYVehMotState_t;

/*! @description: Longitudinal  motion state  
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t  VDYLongDirState_t;

/*! @description: Longitudinal  motion state  
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t  VDYLongDirState_t;

/*! @description: Wheel ticks (impulse) deviation
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t  VDYWhlTicksDev_t;

/*! @description: Actual state of gear box
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui8_t  VDYActGearPos_t;

/*! @description: Brake activity level (=torque or pressure in dependence of vehicle)
  @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
typedef ui16_t  VDYBrkActLevel_t;

/*! @description: Ticks (pulses) per revolution
  @resolution: tbd    @unit: 1/rev  @min: 0     @max: tbd  */
typedef ui8_t  VDYTcksPerRev_t;

typedef   f32_t fDimension_t;
typedef   f32_t fCornerStiff_t;
typedef   uint8 MotState_t                 /* Moving (forward or reverse) Moving forward, Moving reverse, Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

#if !defined(VDY_LONG_MOT_STATE_MOVE) && !defined(VDY_LONG_MOT_STATE_MOVE_FWD) && !defined(VDY_LONG_MOT_STATE_MOVE_RWD) && !defined(VDY_LONG_MOT_STATE_STDST)
typedef enum eMotState_t {
  VDY_LONG_MOT_STATE_MOVE     = (0U),
  VDY_LONG_MOT_STATE_MOVE_FWD = (1U),
  VDY_LONG_MOT_STATE_MOVE_RWD = (2U),
  VDY_LONG_MOT_STATE_STDST    = (3U)
} eMotState_t;
#endif

/*---- Input Data ----------------------------------------------------------*/

/*! @description: Yawrate offset error estimated by alignment monitoring */
typedef struct {
  fYawRate_t YawRate;        /*!< Yawrate offset             */
  fVariance_t Variance;      /*!< Yawrate offset variance    */
  fQuality_t Probability;    /*!< Yawrate offset Probability */
} YawOffsError_v1_t;
/*! @description: Yawrate offset error estimated by alignment monitoring */
typedef struct {
  fYawRate_t YawRate;        /*!< Yawrate offset             */
  fVariance_t Variance;      /*!< Yawrate offset variance    */
  fConfidence_t Confidence;  /*!< Yawrate offset confidence  */
} YawOffsError_v2_t;


typedef struct 			
{
	ui8_t       binVelRatio[REF_SPEED_NO_BINS];            /* Occurrences of velocity ratios within bounds */
	ui8_t       binVelRatOutLo;                      /* Occurrences of velocity ratios below lower bound */
	ui8_t       binVelRatOutHi;                      /* Occurrences of velocity ratios below higher bound */
	ui8_t       cntSample;                           /* Sample counter to recognize updated data */
	fVelocity_t refEgoVelo;                          /* Referenced, uncorrected ego velocity */
} RefSpeed_old_t;		

/*! bit field Configuration of the VDY Component */
typedef struct  {
        ubit32_t cfg_vdy_allrad  :1;        /*! Enable 4wd specific functions */
        ubit32_t cfg_vdy_adtr_curve  :1;    /*! Curve output for ADTR function  */
        ubit32_t cfg_vdy_wsp_rdyn  :1;      /*! Enable Wheel load dependency correction */
        ubit32_t cfg_vdy_swa_offs_err  :1;  /*! Steering wheel angle offset error indication */
        ubit32_t cfg_vdy_hgv_funcs  :1;     /*! Enable heavy vehicle functions  */
        ubit32_t cfg_vdy_yw_dyn_avg  :1;    /*! Enable dynamic gyro offst compensation */
        ubit32_t cfg_vdy_ex_ywr_nvm  :1;    /*! Enable offset storage  in nonvolatile Memory */
        ubit32_t cfg_vdy_int_gyro  :1;      /*! Enable internal yaw rate sensor processing */
        ubit32_t cfg_vdy_fpm_754  :1;       /*! Enable optimized math functio approximation  */
        ubit32_t cfg_vdy_use_ex_long_accel  :1; /*! Use external provided longitudinal acceleration signal  */
        ubit32_t cfg_vdy_use_ex_long_velo  :1;  /*! Use external provided longitudinal velocity signal  */
        ubit32_t cfg_vdy_mot_state  :1;         /*!  Enable motion state processing */
        ubit32_t cfg_vdy_exec_old_curve_too  :1;/*!  Enables also the execution of the old curve  */
        ubit32_t cfg_vdy_do_velocity_corr  :1;  /*!  Enables the velocity correction   */
        ubit32_t cfg_vdy_debug_output  :1;      /*!  Enables vdy debug calculations  */
        ubit32_t cfg_vdy_diag_data_active  :1;  /*! Enables interface for diagnostic ingerface  */
        ubit32_t cfg_vdy_use_ext_proc_curvature  :1;  /*! Enables usage of external curve as vdy output curve  */
        ubit32_t cfg_vdy_use_ext_proc_yaw_rate  :1;   /*! Enables usage of external yaw rate as vdy output yaw rate  */
        ubit32_t cfg_vdy_use_ext_proc_side_slip_angle  :1;  /*! Enables usage of external side slip angle as vdy ouput side slip angle  */
        ubit32_t cfg_vdy_dis_whs_offset_comp  :1;  /*! disable wheel speed sensor offset compenpensation */
        ubit32_t cfg_vdy_dis_wheel_pre_processing   :1; /*! disable wheel speed sensor pre processing */
        ubit32_t cfg_vdy_dis_ywr_offset_comp  :1;  /*! disable yaw rate sensor offset compensation */
        ubit32_t cfg_vdy_dis_yaw_sensor_pre_processing   :1; /*! disable yaw rate sensor pre processing */
        ubit32_t cfg_vdy_dis_swa_offset_comp  :1;  /*! disable steering wheel sensor offset compensation*/
        ubit32_t cfg_vdy_dis_stw_angle_sensor_pre_processing   :1; /*! disable steering wheel angle pre processing */
        ubit32_t cfg_vdy_dis_lat_offset_comp  :1;  /*! disable lateral accleration sensor offset compensation */
        ubit32_t cfg_vdy_dis_lat_accel_sensor_pre_processing   :1; /*! disable lateral acceleration sensor pre processing */
        ubit32_t cfg_vdy_dis_side_slip_angle_estimation   :1; /*! disable the internal side slip angle estimation */
        ubit32_t vdy_use_learned_understeer_grad   :1;  /*! If the learned understeer gradiend should be used */
        ubit32_t vdy_calc_vdy_timing   :1;              /*! If the timing should be calculated */
        ubit32_t vdy_calc_new_diff_whl_offsets   :1;    /*! Calculate the new wheel diff offset 0.9999 to 1.0001 and not 0.0000xx */
        ubit32_t vdy_use_est_wld_dep   :1;              /*! If the estimated wheel laod dep should be used */
} VDYConfig_t; 

/*! Velocity of assumed stationary targets of forward looking sensor */
typedef struct {
  ui8_t        binVelRatio[41];      /*!< Occurences of velocity ratios */
  fVelocity_t  refEgoVelo;           /*!< Referenced, uncorrected ego velocity */
  ui32_t       cntSample;            /*!< Sample counter to recognize updated data */
} VDYVelStatObjHist_t;

/*! Input Signals uncertainties of the vehicle dynamics module */
typedef struct {
  fUncertainty_t      YawRate;                 /*!< Yaw rate signal                                        */
  fUncertainty_t      LatAccel;                /*!< Lateral acceleration sensor signal                     */
  fUncertainty_t      LongAccel;               /*!< Longitudinal acceleration sensor signal                */
  fUncertainty_t      StWheelAngle;            /*!< Steering wheel angle signal                            */
  fUncertainty_t      VehVelocityExt;          /*!< External provided longitudinal velocity                */
  fUncertainty_t      VehLongAccelExt;         /*!< External longitudinal vehicle acceleration             */
  fUncertainty_t      CurveC0Ext;              /*!< External provided curvature 1/R                        */
  fUncertainty_t      CurveC1Ext;              /*!< External provided curvature change d/ds 1/R            */
  fUncertainty_t      SideSlipAngle;           /*!< External proveded side slip angle                      */
  fUncertainty_t      WhlVelFrLeft;            /*!< Wheel circumferential velocity front left              */
  fUncertainty_t      WhlVelFrRight;           /*!< Wheel circumferential velocity front right             */
  fUncertainty_t      WhlVelReLeft;            /*!< Wheel circumferential velocity rear left               */
  fUncertainty_t      WhlVelReRight;           /*!< Wheel circumferential velocity rear right              */
  fUncertainty_t      RearStAngle;             /*!< Rear axle steering wheel angle @NAME: RearWhlAngle     */
  i32_t               Reserved[3];             /*!< Reserved entries for future extensions                 */
} VDYInSigUnc_t;

/*! Some last valid Input Signals*/
typedef struct {
  fYawRate_t          YawRate;                 /*!< Yaw rate signal                                        */
  fAngle_t            StWheelAngle;            /*!< Steering wheel angle signal                            */
  fAcceleration_t     LatAccel;                /*!< Lateral acceleration sensor signal                     */
  fVelocity_t         WhlVelFrLeft;            /*!< Wheel circumferential velocity front left              */
  fVelocity_t         WhlVelFrRight;           /*!< Wheel circumferential velocity front right             */
  fVelocity_t         WhlVelReLeft;            /*!< Wheel circumferential velocity rear left               */
  fVelocity_t         WhlVelReRight;           /*!< Wheel circumferential velocity rear right              */
} VDYLastInSig_t;

/*! @description: VDYIoState_t  
  @resolution: tbd   @unit: tbd   @min: 0     @max: tbd  */
typedef ui8_t VDYErrState_t;

/*! Error indication input signal interface */
typedef struct {
  VDYErrState_t InputSignalError;        /*!< Input Signals error */
} VDYSigError_v1_t;

/*! Error indication input signal interface */
typedef struct {
  VDYErrState_t InputSignalError;            /*!< Input Signals error */
  VDYErrState_t InputSignalPeakError;        /*!< Input Signals error */
} VDYSigError_v2_t;

#ifndef VDY_SIN_SIZE_DW
static const unsigned int VDY_SIN_SIZE_DW = (2U);  /*!< Number of dwords necessary to store flags              */
#endif

/*! Input Signals of the Vehicle Dynamics Module */
typedef struct {
#ifdef __PDO__
  VDYInSignalState_t  State;                   /*!< Input signal states @NAME: Status                      */
#else
  VDYIoState_t        State[VDY_SIN_SIZE_DW];  /*!< Input signal states                                    */
#endif
  fYawRate_t          YawRate;                 /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateTemp;             /*!< Temperature of yaw rate sensor signal                  */
  fAngle_t            StWheelAngle;            /*!< Steering wheel angle sensor signal                     */
  fAcceleration_t     LatAccel;                /*!< Lateral acceleration sensor signal                     */
  fVelocity_t         WhlVelFrLeft;            /*!< Wheel circumferential velocity front left              */
  fVelocity_t         WhlVelFrRight;           /*!< Wheel circumferential velocity front right             */
  fVelocity_t         WhlVelReLeft;            /*!< Wheel circumferential velocity rear left               */
  fVelocity_t         WhlVelReRight;           /*!< Wheel circumferential velocity rear right              */
  fYawRate_t          YawRateInt;              /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateIntTemp;          /*!< Temperature of yaw rate sensor signal                  */
  fAcceleration_t     LongAccel;               /*!< Longitudinal acceleration sensor signal                */
  fAngle_t            RearWhlAngle;            /*!< Rear axle steering wheel angle                         */
  fVelocity_t         VehVelocityExt;          /*!< External provided longitudinal velocity @NAME: VehVelExt */
  fAcceleration_t     VehLongAccelExt;         /*!< External longitudinal vehicle acceleration @NAME: VehAccelExt */
  VDYLongDirState_t   WhlDirFrLeft;            /*!< Wheel rolling direction front left                     */
  VDYLongDirState_t   WhlDirFrRight;           /*!< Wheel rolling direction front right                    */
  VDYLongDirState_t   WhlDirReLeft;            /*!< Wheel rolling direction rear left                      */
  VDYLongDirState_t   WhlDirReRight;           /*!< Wheel rolling direction rear right                     */
  VDYWhlTicksDev_t    WhlTicksDevFrLeft;       /*!< Wheel ticks deviation front left to last cycle @NAME: WhlIcDevFrLeft */
  VDYWhlTicksDev_t    WhlTicksDevFrRight;      /*!< Wheel ticks deviation front right to last cycle @NAME: WhlIcDevFrRight */
  VDYWhlTicksDev_t    WhlTicksDevReLeft;       /*!< Wheel ticks deviation rear left to last cycle @NAME: WhlIcDevReLeft */
  VDYWhlTicksDev_t    WhlTicksDevReRight;      /*!< Wheel ticks deviation rear right to last cycle @NAME: WhlIcDevReRight */
  VDYActGearPos_t     ActGearPos;              /*!< Actual gear position                                   */
  VDYBrkActLevel_t    BrakeActLevel;           /*!< Brake activity level (torque or pressure)              */
  VDYActState_t       ParkBrakeState;          /*!< Status of park brake (false->released, true -> locked) @NAME: ParkBrkState */
  VDYLongDirState_t   VehLongDirExt;           /*!< External longitudinal direction state                  */
  VDYVehMotState_t    VehLongMotStateExt;      /*!< External vehicle standstill @NAME: VehLongMotExt       */
  fCurve_t            CurveC0Ext;              /*!< External provided curvature 1/R @NAME: CurveC0         */
  fCurve_t            CurveC1Ext;              /*!< External provided curvature change d/ds 1/R @NAME: CurveC1 */
  fAngle_t            SideSlipAngleExt;        /*!< External proveded side slip angle @NAME: SideSlipAngle */
  RefSpeed_old_t      VelStatObj;              /*!< Velocity ratio of assumed stationary objects @NAME: VDYVelCorr */
  VDYInSigUnc_t       Unc;                     /*!< Input signal uncertainties                             */
  VDYConfig_t         VDYConfig;                /*!< Configuration of the VDY Component                     */
  i32_t               Reserved[3];             /*!< Reserved entries for future extensions                 */
} VDYInputSignal_t;


/*! Input Signals of the Vehicle Dynamics Module */
typedef struct {
#ifdef __PDO__
  VDYInSignalState_t  State;                   /*!< Input signal states @NAME: Status                      */
#else
  VDYIoState_t        State[VDY_SIN_SIZE_DW];  /*!< Input signal states                                    */
#endif
  fYawRate_t          YawRate;                 /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateTemp;             /*!< Temperature of yaw rate sensor signal                  */
  fAngle_t            StWheelAngle;            /*!< Steering wheel angle sensor signal                     */
  fAcceleration_t     LatAccel;                /*!< Lateral acceleration sensor signal                     */
  fVelocity_t         WhlVelFrLeft;            /*!< Wheel circumferential velocity front left              */
  fVelocity_t         WhlVelFrRight;           /*!< Wheel circumferential velocity front right             */
  fVelocity_t         WhlVelReLeft;            /*!< Wheel circumferential velocity rear left               */
  fVelocity_t         WhlVelReRight;           /*!< Wheel circumferential velocity rear right              */
  fYawRate_t          YawRateInt;              /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateIntTemp;          /*!< Temperature of yaw rate sensor signal                  */
  fAcceleration_t     LongAccel;               /*!< Longitudinal acceleration sensor signal                */
  fAngle_t            RearWhlAngle;            /*!< Rear axle steering wheel angle                         */
  fVelocity_t         VehVelocityExt;          /*!< External provided longitudinal velocity @NAME: VehVelExt */
  fAcceleration_t     VehLongAccelExt;         /*!< External longitudinal vehicle acceleration @NAME: VehAccelExt */
  VDYLongDirState_t   WhlDirFrLeft;            /*!< Wheel rolling direction front left                     */
  VDYLongDirState_t   WhlDirFrRight;           /*!< Wheel rolling direction front right                    */
  VDYLongDirState_t   WhlDirReLeft;            /*!< Wheel rolling direction rear left                      */
  VDYLongDirState_t   WhlDirReRight;           /*!< Wheel rolling direction rear right                     */
  VDYWhlTicksDev_t    WhlTicksDevFrLeft;       /*!< Wheel ticks deviation front left to last cycle @NAME: WhlIcDevFrLeft */
  VDYWhlTicksDev_t    WhlTicksDevFrRight;      /*!< Wheel ticks deviation front right to last cycle @NAME: WhlIcDevFrRight */
  VDYWhlTicksDev_t    WhlTicksDevReLeft;       /*!< Wheel ticks deviation rear left to last cycle @NAME: WhlIcDevReLeft */
  VDYWhlTicksDev_t    WhlTicksDevReRight;      /*!< Wheel ticks deviation rear right to last cycle @NAME: WhlIcDevReRight */
  VDYActGearPos_t     ActGearPos;              /*!< Actual gear position                                   */
  VDYBrkActLevel_t    BrakeActLevel;           /*!< Brake activity level (torque or pressure)              */
  VDYActState_t       ParkBrakeState;          /*!< Status of park brake (false->released, true -> locked) @NAME: ParkBrkState */
  VDYLongDirState_t   VehLongDirExt;           /*!< External longitudinal direction state                  */
  VDYVehMotState_t    VehLongMotStateExt;      /*!< External vehicle standstill @NAME: VehLongMotExt       */
  fCurve_t            CurveC0Ext;              /*!< External provided curvature 1/R @NAME: CurveC0         */
  fCurve_t            CurveC1Ext;              /*!< External provided curvature change d/ds 1/R @NAME: CurveC1 */
  fAngle_t            SideSlipAngleExt;        /*!< External proveded side slip angle @NAME: SideSlipAngle */
  RefSpeed_old_t      VelStatObj;              /*!< Velocity ratio of assumed stationary objects @NAME: VDYVelCorr */
  YawOffsError_v1_t   YawOffsError;            /*!< Yawrate offset error esimated by alignment monitoring  */
  VDYInSigUnc_t       Unc;                     /*!< Input signal uncertainties                             */
  VDYConfig_t         VDYConfig;               /*!< Configuration of the VDY Component                     */
  VDYSigError_v1_t    Error;                   /*!< VDY input signal errors                                */
  i32_t               Reserved[3];             /*!< Reserved entries for future extensions                 */
} VDYInputSignal_v1_t;

/*! Input Signals of the Vehicle Dynamics Module */
typedef struct {
#ifdef __PDO__
  VDYInSignalState_t  State;                   /*!< Input signal states @NAME: Status                      */
#else
  VDYIoState_t        State[VDY_SIN_SIZE_DW];  /*!< Input signal states                                    */
#endif
  fYawRate_t          YawRate;                 /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateTemp;             /*!< Temperature of yaw rate sensor signal                  */
  fAngle_t            StWheelAngle;            /*!< Steering wheel angle sensor signal                     */
  fAcceleration_t     LatAccel;                /*!< Lateral acceleration sensor signal                     */
  fVelocity_t         WhlVelFrLeft;            /*!< Wheel circumferential velocity front left              */
  fVelocity_t         WhlVelFrRight;           /*!< Wheel circumferential velocity front right             */
  fVelocity_t         WhlVelReLeft;            /*!< Wheel circumferential velocity rear left               */
  fVelocity_t         WhlVelReRight;           /*!< Wheel circumferential velocity rear right              */
  fYawRate_t          YawRateInt;              /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateIntTemp;          /*!< Temperature of yaw rate sensor signal                  */
  fAcceleration_t     LongAccel;               /*!< Longitudinal acceleration sensor signal                */
  fAngle_t            RearWhlAngle;            /*!< Rear axle steering wheel angle                         */
  fVelocity_t         VehVelocityExt;          /*!< External provided longitudinal velocity @NAME: VehVelExt */
  fAcceleration_t     VehLongAccelExt;         /*!< External longitudinal vehicle acceleration @NAME: VehAccelExt */
  VDYLongDirState_t   WhlDirFrLeft;            /*!< Wheel rolling direction front left                     */
  VDYLongDirState_t   WhlDirFrRight;           /*!< Wheel rolling direction front right                    */
  VDYLongDirState_t   WhlDirReLeft;            /*!< Wheel rolling direction rear left                      */
  VDYLongDirState_t   WhlDirReRight;           /*!< Wheel rolling direction rear right                     */
  VDYWhlTicksDev_t    WhlTicksDevFrLeft;       /*!< Wheel ticks deviation front left to last cycle @NAME: WhlIcDevFrLeft */
  VDYWhlTicksDev_t    WhlTicksDevFrRight;      /*!< Wheel ticks deviation front right to last cycle @NAME: WhlIcDevFrRight */
  VDYWhlTicksDev_t    WhlTicksDevReLeft;       /*!< Wheel ticks deviation rear left to last cycle @NAME: WhlIcDevReLeft */
  VDYWhlTicksDev_t    WhlTicksDevReRight;      /*!< Wheel ticks deviation rear right to last cycle @NAME: WhlIcDevReRight */
  VDYActGearPos_t     ActGearPos;              /*!< Actual gear position                                   */
  VDYBrkActLevel_t    BrakeActLevel;           /*!< Brake activity level (torque or pressure)              */
  VDYActState_t       ParkBrakeState;          /*!< Status of park brake (false->released, true -> locked) @NAME: ParkBrkState */
  VDYLongDirState_t   VehLongDirExt;           /*!< External longitudinal direction state                  */
  VDYVehMotState_t    VehLongMotStateExt;      /*!< External vehicle standstill @NAME: VehLongMotExt       */
  fCurve_t            CurveC0Ext;              /*!< External provided curvature 1/R @NAME: CurveC0         */
  fCurve_t            CurveC1Ext;              /*!< External provided curvature change d/ds 1/R @NAME: CurveC1 */
  fAngle_t            SideSlipAngleExt;        /*!< External proveded side slip angle @NAME: SideSlipAngle */
  RefSpeed_old_t      VelStatObj;              /*!< Velocity ratio of assumed stationary objects @NAME: VDYVelCorr */
  YawOffsError_v2_t   YawOffsError;            /*!< Yawrate offset error esimated by alignment monitoring  */
  VDYInSigUnc_t       Unc;                     /*!< Input signal uncertainties                             */
  VDYConfig_t         VDYConfig;               /*!< Configuration of the VDY Component                     */
  VDYSigError_v1_t    Error;                   /*!< VDY input signal errors                                */
  i32_t               Reserved[3];             /*!< Reserved entries for future extensions                 */
} VDYInputSignal_v2_t;

/*! Input Signals of the Vehicle Dynamics Module */
typedef struct {
#ifdef __PDO__
  VDYInSignalState_t  State;                   /*!< Input signal states @NAME: Status                      */
#else
  VDYIoState_t        State[VDY_SIN_SIZE_DW];  /*!< Input signal states                                    */
#endif
  fYawRate_t          YawRate;                 /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateTemp;             /*!< Temperature of yaw rate sensor signal                  */
  fAngle_t            StWheelAngle;            /*!< Steering wheel angle sensor signal                     */
  fAcceleration_t     LatAccel;                /*!< Lateral acceleration sensor signal                     */
  fVelocity_t         WhlVelFrLeft;            /*!< Wheel circumferential velocity front left              */
  fVelocity_t         WhlVelFrRight;           /*!< Wheel circumferential velocity front right             */
  fVelocity_t         WhlVelReLeft;            /*!< Wheel circumferential velocity rear left               */
  fVelocity_t         WhlVelReRight;           /*!< Wheel circumferential velocity rear right              */
  fYawRate_t          YawRateInt;              /*!< Yaw rate sensor signal                                 */
  fTemperature_t      YawRateIntTemp;          /*!< Temperature of yaw rate sensor signal                  */
  fAcceleration_t     LongAccel;               /*!< Longitudinal acceleration sensor signal                */
  fAngle_t            RearWhlAngle;            /*!< Rear axle steering wheel angle                         */
  fVelocity_t         VehVelocityExt;          /*!< External provided longitudinal velocity @NAME: VehVelExt */
  fAcceleration_t     VehLongAccelExt;         /*!< External longitudinal vehicle acceleration @NAME: VehAccelExt */
  VDYLongDirState_t   WhlDirFrLeft;            /*!< Wheel rolling direction front left                     */
  VDYLongDirState_t   WhlDirFrRight;           /*!< Wheel rolling direction front right                    */
  VDYLongDirState_t   WhlDirReLeft;            /*!< Wheel rolling direction rear left                      */
  VDYLongDirState_t   WhlDirReRight;           /*!< Wheel rolling direction rear right                     */
  VDYWhlTicksDev_t    WhlTicksDevFrLeft;       /*!< Wheel ticks deviation front left to last cycle @NAME: WhlIcDevFrLeft */
  VDYWhlTicksDev_t    WhlTicksDevFrRight;      /*!< Wheel ticks deviation front right to last cycle @NAME: WhlIcDevFrRight */
  VDYWhlTicksDev_t    WhlTicksDevReLeft;       /*!< Wheel ticks deviation rear left to last cycle @NAME: WhlIcDevReLeft */
  VDYWhlTicksDev_t    WhlTicksDevReRight;      /*!< Wheel ticks deviation rear right to last cycle @NAME: WhlIcDevReRight */
  VDYActGearPos_t     ActGearPos;              /*!< Actual gear position                                   */
  VDYBrkActLevel_t    BrakeActLevel;           /*!< Brake activity level (torque or pressure)              */
  VDYActState_t       ParkBrakeState;          /*!< Status of park brake (false->released, true -> locked) @NAME: ParkBrkState */
  VDYLongDirState_t   VehLongDirExt;           /*!< External longitudinal direction state                  */
  VDYVehMotState_t    VehLongMotStateExt;      /*!< External vehicle standstill @NAME: VehLongMotExt       */
  fCurve_t            CurveC0Ext;              /*!< External provided curvature 1/R @NAME: CurveC0         */
  fCurve_t            CurveC1Ext;              /*!< External provided curvature change d/ds 1/R @NAME: CurveC1 */
  fAngle_t            SideSlipAngleExt;        /*!< External proveded side slip angle @NAME: SideSlipAngle */
  RefSpeed_old_t      VelStatObj;              /*!< Velocity ratio of assumed stationary objects @NAME: VDYVelCorr */
  YawOffsError_v2_t   YawOffsError;            /*!< Yawrate offset error esimated by alignment monitoring  */
  VDYInSigUnc_t       Unc;                     /*!< Input signal uncertainties                             */
  VDYLastInSig_t      LastInputSignals;        /*!< Some last input signals to detect peaks                */
  VDYConfig_t         VDYConfig;               /*!< Configuration of the VDY Component                     */
  VDYSigError_v2_t    Error;                   /*!< VDY input signal errors                                */
  i32_t               Reserved[3];             /*!< Reserved entries for future extensions                 */
} VDYInputSignal_v3_t;

#ifndef VDY_SWA_RAT_NO_ANGL
static const unsigned int VDY_SWA_RAT_NO_ANGL = 2;
#endif

#ifndef VDY_SWA_RAT_NO_VELO
static const unsigned int VDY_SWA_RAT_NO_VELO = 2;
#endif

/*! Steering ratio table */
/*! TotalRatio = swaRatio(angle) + velRatio(velocity), the ratio parts are linear 
    interpolated among the sample points */
typedef struct {
  struct {
    fAngle_t    ang[VDY_SWA_RAT_NO_ANGL];  /*!< Abscissa: Steering wheel angle sample points */
    fRatio_t    rat[VDY_SWA_RAT_NO_ANGL];  /*!< Ordinate: Base ratio sample points */
  } swa;        /*!< Table for base steering ratio in dependence of steering wheel angle */
  struct {
    fVelocity_t vel[VDY_SWA_RAT_NO_VELO];   /*!< Abscissa: Vehicle velocity sample points */
    fRatio_t    rat[VDY_SWA_RAT_NO_VELO];   /*!< Ordinate: Additional ratio by super-imposed steering */
  } vel;        /*!< Table for additional steering ratio part in dependence of velocity */
} VDYStRatio_t;

/*! Input parameters uncertainties of the vehicle dynamics module */
typedef struct {
  fUncertainty_t      SelfSteerGrad;           /*!< Understeer/Oversteer gradient            */
} VDYInParUnc_t;

/*! Error indication input parameter interface */
typedef struct {
  VDYErrState_t InputParameterError;        /*!< Input Parameter error */
} VDYParaError_t;

#ifndef VDY_PAR_SIZE_DW
static const unsigned int VDY_PAR_SIZE_DW = (2UL);  /*!< Number of dwords necessary to store flags              */
#endif

/*! Input Parameters of the Vehicle Dynamics Module */
typedef struct {
#ifdef __PDO__
  VDYParaState_t   State; 
#else
  VDYIoState_t     State[VDY_PAR_SIZE_DW];  /*!< Status of parameter set                     */
#endif
  fVDYSlfStGrad_t  SelfSteerGrad;           /*!< Understeer/Oversteer gradient               */
  VDYStRatio_t     SteeringRatio;           /*!< Overall steering ratio                      */
  fDimension_t     WheelBase;               /*!< Distance between front and rear axle        */
  fDimension_t     TrackWidthFront;         /*!< Track width front axle                      */
  fDimension_t     TrackWidthRear;          /*!< Track width rear axle                       */
  fWeight_t        VehWeight;               /*!< Vehicle weight @NAME: VehicleWeight */
  fDimension_t     CntrOfGravHeight;        /*!< Center of gravity height                    */
  fRatio_t         AxisLoadDistr;           /*!< Ratio between rear axle load and total load @NAME: AxleLdDistr */
  fVDYWhlLdDep_t   WhlLoadDepFrontAxle;     /*!< Wheel load dependency front axle @NAME: WhlLdDepFr */
  fVDYWhlLdDep_t   WhlLoadDepRearAxle;      /*!< Wheel load dependency rear axle  @NAME: WhlLdDepRe */
  fDimension_t     WhlCircumference;        /*!< Effective dynamic rolling circumference @NAME: WhlCircum */
  VDYAxle_t        DrvAxle;                 /*!< Powered Axle                                */
  VDYTcksPerRev_t  WhlTcksPerRev;           /*!< Impulse counter ticks per wheel revolution @NAME: WhlTicksPRev */
  fCornerStiff_t   FrCrnrStiff;             /*!< Front axle cornering stiffness  @NAME: CornStiffFr */
  fCornerStiff_t   ReCrnrStiff;             /*!< Rear axle cornering stiffness @NAME: CornStiffRe */
  VDYInParUnc_t    Unc;                     /*!< Parameter uncertainties                     */
  VDYParaError_t   Error;                    /*!< Input parameter errors                     */
  i32_t            Reserved[5];             /*!< Reserved entries for future extensions      */
} VDYInputPara_t;

typedef uint8 VDYCaliState_t             /* Calibration inhibition states @min: 0 @max:128 @values: enum { VDY_CAL_INIT=0,VDY_CAL_SWA_GRAD=64,VDY_CAL_YWR_OFFS_STST=1,VDY_CAL_YWR_OFFS_DYN=2,VDY_CAL_SWA_OFFS=16,VDY_CAL_WHS_OFFS=4,VDY_CAL_WHS_LOAD=128,VDY_CAL_LTA_OFFS=32,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
typedef uint8 VDYCtrlState_t             /* Operating modes of vdy component @min: 0 @max:2 @values: enum { VDY_CTRL_STATE_INIT=1,VDY_CTRL_STATE_STARTUP=0,VDY_CTRL_STATE_RUNNING=2,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

typedef struct {
  ui32_t         Version;     /*!< component version number         */
  times_t        CycleTime;   /*!< component cycle time             */
  ui16_t         CycleCnt;    /*!< vdy cycle counts                 */
  VDYCaliState_t CaliMode;    /*!< Calibration inhibition states    */
  VDYCtrlState_t CtrlMode;    /*!< Operating modes of vdy component */
} VDYInputFrame_t;


/*! Input of the Vehicle Dynamics Module */
typedef struct {
  VDYInputFrame_t  Frame;         /*!< Control frame */
  VDYInputPara_t   Parameter;     /*!< Vehicle parameters @NAME: Para */
  VDYInputSignal_v1_t Signals;       /*!< Vehicle sensor signals @NAME: Sig */
} VDYInputData_v1_t;

/*! Input of the Vehicle Dynamics Module */
typedef struct {
  VDYInputFrame_t  Frame;         /*!< Control frame */
  VDYInputPara_t   Parameter;     /*!< Vehicle parameters @NAME: Para */
  VDYInputSignal_v2_t Signals;       /*!< Vehicle sensor signals @NAME: Sig */
} VDYInputData_v2_t;
/*! Input of the Vehicle Dynamics Module */
typedef struct {
  VDYInputFrame_t  Frame;         /*!< Control frame */
  VDYInputPara_t   Parameter;     /*!< Vehicle parameters @NAME: Para */
  VDYInputSignal_v3_t Signals;       /*!< Vehicle sensor signals @NAME: Sig */
} VDYInputData_v3_t;


/*! Input Parameters of the Vehicle Dynamics Module */
typedef struct {
#ifdef __PDO__
  VDYParaState_t   State; 
#else
  VDYIoState_t     State[VDY_PAR_SIZE_DW];  /*!< Status of parameter set                     */
#endif
  fVDYSlfStGrad_t  SelfSteerGrad;           /*!< Understeer/Oversteer gradient               */
  VDYStRatio_t     SteeringRatio;           /*!< Overall steering ratio                      */
  fDimension_t     WheelBase;               /*!< Distance between front and rear axle        */
  fDimension_t     TrackWidthFront;         /*!< Track width front axle                      */
  fDimension_t     TrackWidthRear;          /*!< Track width rear axle                       */
  fWeight_t        VehWeight;               /*!< Vehicle weight @NAME: VehicleWeight */
  fDimension_t     CntrOfGravHeight;        /*!< Center of gravity height                    */
  fRatio_t         AxisLoadDistr;           /*!< Ratio between rear axle load and total load @NAME: AxleLdDistr */
  fVDYWhlLdDep_t   WhlLoadDepFrontAxle;     /*!< Wheel load dependency front axle @NAME: WhlLdDepFr */
  fVDYWhlLdDep_t   WhlLoadDepRearAxle;      /*!< Wheel load dependency rear axle  @NAME: WhlLdDepRe */
  fDimension_t     WhlCircumference;        /*!< Effective dynamic rolling circumference @NAME: WhlCircum */
  VDYAxle_t        DrvAxle;                 /*!< Powered Axle                                */
  VDYTcksPerRev_t  WhlTcksPerRev;           /*!< Impulse counter ticks per wheel revolution @NAME: WhlTicksPRev */
  fCornerStiff_t   FrCrnrStiff;             /*!< Front axle cornering stiffness  @NAME: CornStiffFr */
  fCornerStiff_t   ReCrnrStiff;             /*!< Rear axle cornering stiffness @NAME: CornStiffRe */
  VDYInParUnc_t    Unc;                     /*!< Parameter uncertainties                     */
  i32_t            Reserved[5];             /*!< Reserved entries for future extensions      */
} VDYInputPara_v2_t;


/*! Input of the Vehicle Dynamics Module */
typedef struct {
  VDYInputFrame_t   Frame;         /*!< Control frame */
  VDYInputPara_v2_t Parameter;     /*!< Vehicle parameters @NAME: Para */
  VDYInputSignal_t  Signals;       /*!< Vehicle sensor signals @NAME: Sig */
} VDYInputData_v4_t;  /*For version 02.09.04. */

}

/* used from VehPar */
typedef uint32                      State_array_V0_t_1[2];          /* State of the values as bitfield () */	/* [Satisfies_rte sws 1189] */
#define    SENSOR_OR_NORMAL  (0U)
#define    SENSOR_OR_ROTATED (1U)

/* ------------------------ VehPar data types ------------------------*/
// VehPar V0
namespace VehParV0 {

  typedef uint8 Orientation_t;              /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef float32                   ang_array_t[2];              /* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */


  typedef float32                   rat_array_t[2];              /* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */


  typedef float32                   vel_array_t[2];              /* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */


  typedef float32                   rat_array_t_0[2];            /* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */

  typedef uint32                    State_array_t_1[2];          /* vehicle parameter sensor mounting states */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 SelfSteerGrad;                       /* Uncertainty of Understeer/Oversteer gradient */
  } UncParameter_t;			/* Uncertainty of vehicle parameter */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    ang_array_t ang;                                 /* Abscissa: Steering wheel angle sample points */
    rat_array_t rat;                                 /* Ordinate: Base ratio sample points */
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 VehicleWidth;                        /* Vehicle width */
#if (SRR_SWITCH)
    float32 VehicleLength;                       /* Vehicle length */
#endif
    float32 CurbWeight;                          /* The weight of a fueled automobile with standard equipment but without cargo or passengers @min:100.0 @max:65000.0 @resolution:100.0 */
    float32 OverhangFront;                       /* Longitudinal distance from the center of front axle group to the front most point @min:0.0 @max:5.0 @resolution:0.01 */
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 LatPos;                              /* Lateral displacment related to vehicle reference point (+ left) @min:-25.0 @max:25.0 */
    float32 LongPos;                             /* Longitudinal displacment related to vehicle reference point (+ fwd) @min:-25.0 @max:25.0 */
    float32 VertPos;                             /* Vertical displacemnt (height) over ground @min:-25.0 @max:25.0 */
    float32 PitchAngle;                          /* Angular displacment about vehicle lateral axis @min:0.0 @max:40.0 */
    Orientation_t Orientation;                         /* Angular displacement about vehicle longitudinal axis */
    float32 YawAngle;                            /* Angular displacemnt about vehicle vertical axis @min:0.0 @max:40.0 */
  } SensorMounting_t;			/* Sensor mounting geometry */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 CoverDamping;                        /* Attenuation of secondary surface (two-way) in dB @max:25.0 */
    float32 fCoverageAngle;                      /* Coverage Angel @min:-25.0 @max:25.0 */
    float32 fLobeAngle;                          /* Lobe Angle @min:-25.0 @max:25.0 */
    float32 fCycleTime;                          /* Global Cycle Time of the radar cycle used by the components in the radar cycle task @min:0.0 @max:100.0 */
    uint8 uNoOfScans;                          /* Nubmer of scanns @min:1.0 @max:2.0 */
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    vel_array_t vel;                                 /* Ordinate: Additional ratio by super-imposed steering */
    rat_array_t_0 rat;                                 /* Abscissa: Vehicle velocity sample points */
  } vel_t;			/* Table for additional steering ratio part in dependence of velocity */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    swa_t swa;                                 /* Table for base steering ratio in dependence of steering wheel angle */
    vel_t vel;                                 /* Table for additional steering ratio part in dependence of velocity */
  } StRatio_t;			/* Steering ratio */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_1 State;                               /* vehicle parameter states @values: struct VDYParaState */
    float32 SelfSteerGrad;                       /* Rate of change in steering wheel angle with respect to change in steady-state lateral acceleration. @min:-128.0 @max:128.0 */
    StRatio_t SteeringRatio;                       /* Rate of change of steering wheel angle at given steering wheel trim position, with respect to change in average steer angel of a pair of steered wheels. In case of active steering systems this parameter is dependent additional vehicle states @min:1.0 @max:30.0 */
    float32 WheelBase;                           /* Longitudinal distance between  the center of tire contact of pair of wheels on same vehicle side @min:0.0 @max:10.0 */
    float32 TrackWidthFront;                     /* Lateral distance between the center of tire contact of pair of wheels on front vehicle axle @min:1.0 @max:5.0 */
    float32 TrackWidthRear;                      /* Lateral distance between the center of tire contact of pair of wheels on rear vehicle axle @min:1.0 @max:5.0 */
    float32 VehWeight;                           /* Vehicle weight @min:1.0 @max:60000.0 */
    float32 CntrOfGravHeight;                    /* Imaginary point where the total weight of the body may be thought to be concentrated @min:0.2 @max:3.0 */
    float32 AxisLoadDistr;                       /* The ratio of the vertical load at rear axle to total vehicle vertical load @min:0.1 @max:0.9 */
    float32 WhlLoadDepFrontAxle;                 /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at front axle @min:0.0 @max:3.0 */
    float32 WhlLoadDepRearAxle;                  /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at rear axle @min:0.0 @max:3.0 */
    float32 WhlCircumference;                    /* Dynamic wheel rolling circumference @min:1.0 @max:5.0 */
    uint8 DrvAxle;                             /* Powered Axle @min:1.0 @max:5.0 @resolution:0.001 */
    uint8 WhlTcksPerRev;                       /* Number of sensor pulses per wheel revolution @min:1.0 @max:5.0 @resolution:0.001 */
    float32 FrCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at front axle @min:-25.0 @max:25.0 */
    float32 ReCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at rear axle @min:-25.0 @max:25.0 */
    UncParameter_t Unc;                                 /* Uncertainty of vehicle parameter */
  } VehParMain_t;			/* Vehicle main parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehParMain_t VehParMain;                          /* Vehicle main parameters */
    VehParAdd_t VehParAdd;                           /* Vehicle additional parameters */
    SensorMounting_t SensorMounting;                      /* Sensor mounting geometry */
    Sensor_t Sensor;                              /* Sensor specific parameters */
  } VehPar_t;			/* Static Vehicle parameters */
};  // End of VehParV0 namespace

// VehPar V1
namespace VehParV1 {
    typedef uint8 Orientation_t              /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
#if !defined(SENSOR_OR_NORMAL) && !defined(SENSOR_OR_ROTATED)
    typedef enum {
        SENSOR_OR_NORMAL  = (0U),
        SENSOR_OR_ROTATED = (1U)
    } eOrientation_t;
#endif

  typedef uint32 State_array_t[2];            /* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */

  typedef float32 ang_array_t[2];              /* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */

  typedef float32 rat_array_t[2];              /* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */

  typedef float32 vel_array_t[2];              /* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */

  typedef float32 rat_array_t_0[2];            /* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 SelfSteerGrad;                       /* Uncertainty of Understeer/Oversteer gradient */
  } UncParameter_t;			/* Uncertainty of vehicle parameter */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV1::ang_array_t ang;                                 /* Abscissa: Steering wheel angle sample points */
    VehParV1::rat_array_t rat;                                 /* Ordinate: Base ratio sample points */
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 VehicleWidth;                        /* Vehicle width */
#if (SRR_SWITCH)
    float32 VehicleLength;                       /* Vehicle length */
#endif
    float32 CurbWeight;                          /* The weight of a fueled automobile with standard equipment but without cargo or passengers @min:100.0 @max:65000.0 @resolution:100.0 */
    float32 OverhangFront;                       /* Longitudinal distance from the center of front axle group to the front most point @min:0.0 @max:5.0 @resolution:0.01 */
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 LatPos;                              /* Lateral displacment related to vehicle reference point (+ left) @min:-25.0 @max:25.0 */
    float32 LongPos;                             /* Longitudinal displacment related to vehicle reference point (+ fwd) @min:-25.0 @max:25.0 */
    float32 VertPos;                             /* Vertical displacemnt (height) over ground @min:-25.0 @max:25.0 */
    float32 PitchAngle;                          /* Angular displacment about vehicle lateral axis @min:0.0 @max:40.0 */
    Orientation_t Orientation;                         /* Angular displacement about vehicle longitudinal axis */
    float32 YawAngle;                            /* Angular displacemnt about vehicle vertical axis @min:0.0 @max:40.0 */
  } SensorMounting_t;			/* Sensor mounting geometry */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 CoverDamping;                        /* Attenuation of secondary surface (two-way) in dB @min:-25.0 @max:25.0 */
    float32 fCoverageAngle;                      /* Coverage Angel @min:-25.0 @max:25.0 */
    float32 fLobeAngle;                          /* Lobe Angle @min:-25.0 @max:25.0 */
    float32 fCycleTime;                          /* Global Cycle Time of the radar cycle used by the components in the radar cycle task @min:0.0 @max:100.0 */
    uint8 uNoOfScans;                          /* Nubmer of scanns @min:1.0 @max:2.0 */
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV1::vel_array_t vel;                                 /* Ordinate: Additional ratio by super-imposed steering */
    VehParV1::rat_array_t_0 rat;                                 /* Abscissa: Vehicle velocity sample points */
  } vel_t;			/* Table for additional steering ratio part in dependence of velocity */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV1::swa_t swa;                                 /* Table for base steering ratio in dependence of steering wheel angle */
    VehParV1::vel_t vel;                                 /* Table for additional steering ratio part in dependence of velocity */
  } StRatio_t;			/* Steering ratio */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV1::State_array_t State;                               /* vehicle parameter states @values: struct VDYParaState */
    float32 SelfSteerGrad;                       /* Rate of change in steering wheel angle with respect to change in steady-state lateral acceleration. @min:-128.0 @max:128.0 */
    VehParV1::StRatio_t SteeringRatio;                       /* Rate of change of steering wheel angle at given steering wheel trim position, with respect to change in average steer angel of a pair of steered wheels. In case of active steering systems this parameter is dependent additional vehicle states @min:1.0 @max:30.0 */
    float32 WheelBase;                           /* Longitudinal distance between  the center of tire contact of pair of wheels on same vehicle side @min:0.0 @max:10.0 */
    float32 TrackWidthFront;                     /* Lateral distance between the center of tire contact of pair of wheels on front vehicle axle @min:1.0 @max:5.0 */
    float32 TrackWidthRear;                      /* Lateral distance between the center of tire contact of pair of wheels on rear vehicle axle @min:1.0 @max:5.0 */
    float32 VehWeight;                           /* Vehicle weight @min:1.0 @max:60000.0 */
    float32 CntrOfGravHeight;                    /* Imaginary point where the total weight of the body may be thought to be concentrated @min:0.2 @max:3.0 */
    float32 AxisLoadDistr;                       /* The ratio of the vertical load at rear axle to total vehicle vertical load @min:0.1 @max:0.9 */
    float32 WhlLoadDepFrontAxle;                 /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at front axle @min:0.0 @max:3.0 */
    float32 WhlLoadDepRearAxle;                  /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at rear axle @min:0.0 @max:3.0 */
    float32 WhlCircumference;                    /* Dynamic wheel rolling circumference @min:1.0 @max:5.0 */
    uint8 DrvAxle;                             /* Powered Axle @min:1.0 @max:5.0 @resolution:0.001 */
    uint8 WhlTcksPerRev;                       /* Number of sensor pulses per wheel revolution @min:1.0 @max:5.0 @resolution:0.001 */
    float32 FrCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at front axle @min:-25.0 @max:25.0 */
    float32 ReCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at rear axle @min:-25.0 @max:25.0 */
    VehParV1::UncParameter_t Unc;                                 /* Uncertainty of vehicle parameter */
  } VehParMain_t;			/* Vehicle main parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehParV1::VehParMain_t VehParMain;                          /* Vehicle main parameters */
    VehParV1::VehParAdd_t VehParAdd;                           /* Vehicle additional parameters */
    VehParV1::SensorMounting_t SensorMounting;                      /* Sensor mounting geometry */
    VehParV1::Sensor_t Sensor;                              /* Sensor specific parameters */
  } VehPar_t;			/* Static Vehicle parameters */
};  // End of VehParV1 namespace

// VehPar V2
namespace VehParV2 {

    typedef uint8 Orientation_t              /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
#if !defined(SENSOR_OR_NORMAL) && !defined(SENSOR_OR_ROTATED)
    typedef enum {
        SENSOR_OR_NORMAL  = (0U),
        SENSOR_OR_ROTATED = (1U)
    } eOrientation_t;
#endif

  typedef uint32                    	State_array_t[2];            /* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */

  typedef float32                   	ang_array_t[2];              /* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */

  typedef float32                   	rat_array_t[2];              /* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */

  typedef float32                   	vel_array_t[2];              /* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */

  typedef float32                   	rat_array_t_0[2];            /* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV2::ang_array_t ang;                                 /* Abscissa: Steering wheel angle sample points */
    VehParV2::rat_array_t rat;                                 /* Ordinate: Base ratio sample points */
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 VehicleWidth;                        /* Vehicle width */
#if (SRR_SWITCH)
    float32 VehicleLength;                       /* Vehicle length */
#endif
    float32 CurbWeight;                          /* The weight of a fueled automobile with standard equipment but without cargo or passengers @min:100.0 @max:65000.0 @resolution:100.0 */
    float32 OverhangFront;                       /* Longitudinal distance from the center of front axle group to the front most point @min:0.0 @max:5.0 @resolution:0.01 */
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 LatPos;                              /* Lateral displacment related to vehicle reference point (+ left) @min:-25.0 @max:25.0 */
    float32 LongPos;                             /* Longitudinal displacment related to vehicle reference point (+ fwd) @min:-25.0 @max:25.0 */
    float32 VertPos;                             /* Vertical displacemnt (height) over ground @min:-25.0 @max:25.0 */
    float32 LongPosToCoG;                        /* Longitudinal displacment related to vehicle center of gravity (+ fwd) @min:1.0 @max:4.0 */
    float32 PitchAngle;                          /* Angular displacment about vehicle lateral axis @min:0.0 @max:40.0 */
    Orientation_t Orientation;                         /* Angular displacement about vehicle longitudinal axis */
    float32 YawAngle;                            /* Angular displacemnt about vehicle vertical axis @min:0.0 @max:40.0 */
  } SensorMounting_t;			/* Sensor mounting geometry */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 CoverDamping;                        /* Attenuation of secondary surface (two-way) in dB @min:-25.0 @max:25.0 */
    float32 fCoverageAngle;                      /* Coverage Angel @min:-25.0 @max:25.0 */
    float32 fLobeAngle;                          /* Lobe Angle @min:-25.0 @max:25.0 */
    float32 fCycleTime;                          /* Global Cycle Time of the radar cycle used by the components in the radar cycle task @min:0.0 @max:100.0 */
    uint8 uNoOfScans;                          /* Nubmer of scanns @min:1.0 @max:2.0 */
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV2::vel_array_t vel;                                 /* Ordinate: Additional ratio by super-imposed steering */
    VehParV2::rat_array_t_0 rat;                                 /* Abscissa: Vehicle velocity sample points */
  } vel_t;			/* Table for additional steering ratio part in dependence of velocity */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV2::swa_t swa;                                 /* Table for base steering ratio in dependence of steering wheel angle */
    VehParV2::vel_t vel;                                 /* Table for additional steering ratio part in dependence of velocity */
  } StRatio_t;			/* Steering ratio */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t State;                               /* vehicle parameter states @values: struct VDYParaState */
    float32 SelfSteerGrad;                       /* Rate of change in steering wheel angle with respect to change in steady-state lateral acceleration. @min:-128.0 @max:128.0 */
    VehParV2::StRatio_t SteeringRatio;                       /* Rate of change of steering wheel angle at given steering wheel trim position, with respect to change in average steer angel of a pair of steered wheels. In case of active steering systems this parameter is dependent additional vehicle states @min:1.0 @max:30.0 */
    float32 WheelBase;                           /* Longitudinal distance between  the center of tire contact of pair of wheels on same vehicle side @min:0.0 @max:10.0 */
    float32 TrackWidthFront;                     /* Lateral distance between the center of tire contact of pair of wheels on front vehicle axle @min:1.0 @max:5.0 */
    float32 TrackWidthRear;                      /* Lateral distance between the center of tire contact of pair of wheels on rear vehicle axle @min:1.0 @max:5.0 */
    float32 VehWeight;                           /* Vehicle weight @min:1.0 @max:60000.0 */
    float32 CntrOfGravHeight;                    /* Imaginary point where the total weight of the body may be thought to be concentrated @min:0.2 @max:3.0 */
    float32 AxisLoadDistr;                       /* The ratio of the vertical load at rear axle to total vehicle vertical load @min:0.1 @max:0.9 */
    float32 WhlLoadDepFrontAxle;                 /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at front axle @min:0.0 @max:3.0 */
    float32 WhlLoadDepRearAxle;                  /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at rear axle @min:0.0 @max:3.0 */
    float32 WhlCircumference;                    /* Dynamic wheel rolling circumference @min:1.0 @max:5.0 */
    uint8 DrvAxle;                             /* Powered Axle @min:1.0 @max:5.0 @resolution:0.001 */
    uint8 WhlTcksPerRev;                       /* Number of sensor pulses per wheel revolution @min:1.0 @max:5.0 @resolution:0.001 */
    float32 FrCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at front axle @min:-25.0 @max:25.0 */
    float32 ReCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at rear axle @min:-25.0 @max:25.0 */
  } VehParMain_t;			/* Vehicle main parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehParV2::VehParMain_t VehParMain;                          /* Vehicle main parameters */
    VehParV2::VehParAdd_t VehParAdd;                           /* Vehicle additional parameters */
    VehParV2::SensorMounting_t SensorMounting;                      /* Sensor mounting geometry */
    VehParV2::Sensor_t Sensor;                              /* Sensor specific parameters */
  } VehPar_t;			/* Static Vehicle parameters */
};  // End of VehParV2 namespace

// VehPar V3
namespace VehParV3 {
    typedef uint8 Orientation_t              /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
#if !defined(SENSOR_OR_NORMAL) && !defined(SENSOR_OR_ROTATED)
    typedef enum {
        SENSOR_OR_NORMAL  = (0U),
        SENSOR_OR_ROTATED = (1U)
    } eOrientation_t;
#endif

  typedef uint32 VehParAddState_t           /* vehicle additional parameter states @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_DUMMY=1000000,} */			/* [Satisfies_rte sws 1182], [Satisfies_rte sws 1265] */;
  typedef uint32 VehParSenorMountingState_t  /* vehicle parameter sensor mounting states @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */			/* [Satisfies_rte sws 1182], [Satisfies_rte sws 1265] */;
  typedef uint32 VehParSenorState_t         /* vehicle parameter sensor parameter states @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */			/* [Satisfies_rte sws 1182], [Satisfies_rte sws 1265] */;

  typedef uint32                    	State_array_t[2];            /* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */


  typedef VehParAddState_t          	State_array_t_0[2];          /* vehicle additional parameter states */	/* [Satisfies_rte sws 1189] */


  typedef VehParSenorMountingState_t 	State_array_t_1[2];          /* vehicle parameter sensor mounting states */	/* [Satisfies_rte sws 1189] */


  typedef VehParSenorState_t        	State_array_t_2[2];          /* vehicle parameter sensor parameter states */	/* [Satisfies_rte sws 1189] */


  typedef float32                   	ang_array_t[2];              /* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */


  typedef float32                   	rat_array_t[2];              /* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */


  typedef float32                   	vel_array_t[2];              /* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */


  typedef float32                   	rat_array_t_0[2];            /* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV3::ang_array_t ang;                                 /* Abscissa: Steering wheel angle sample points */
    VehParV3::rat_array_t rat;                                 /* Ordinate: Base ratio sample points */
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_0 State;                               /* vehicle additional parameter states */
    float32 VehicleWidth;                        /* Vehicle width */
#if (SRR_SWITCH)
    float32 VehicleLength;                       /* Vehicle length */
#endif
    float32 CurbWeight;                          /* The weight of a fueled automobile with standard equipment but without cargo or passengers @min:100.0 @max:65000.0 */
    float32 OverhangFront;                       /* Longitudinal distance from the center of front axle group to the front most point @min:0.0 @max:5.0 */
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_1 State;                               /* vehicle parameter sensor mounting states */
    float32 LatPos;                              /* Lateral displacment related to vehicle reference point (+ left) @min:-25.0 @max:25.0 */
    float32 LongPos;                             /* Longitudinal displacment related to vehicle reference point (+ fwd) @min:-25.0 @max:25.0 */
    float32 VertPos;                             /* Vertical displacemnt (height) over ground @min:-25.0 @max:25.0 */
    float32 LongPosToCoG;                        /* Longitudinal displacment related to vehicle center of gravity (+ fwd) @min:1.0 @max:4.0 */
    float32 PitchAngle;                          /* Angular displacment about vehicle lateral axis @min:0.0 @max:40.0 */
    Orientation_t Orientation;                         /* Angular displacement about vehicle longitudinal axis */
    float32 YawAngle;                            /* Angular displacemnt about vehicle vertical axis @min:0.0 @max:40.0 */
  } SensorMounting_t;			/* Sensor mounting geometry */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_2 State;                               /* vehicle parameter sensor parameter states */
    float32 CoverDamping;                        /* Attenuation of secondary surface (two-way) in dB @min:-25.0 @max:25.0 */
    float32 fCoverageAngle;                      /* Coverage Angel @min:-25.0 @max:25.0 */
    float32 fLobeAngle;                          /* Lobe Angle @min:-25.0 @max:25.0 */
    float32 fCycleTime;                          /* Global Cycle Time of the radar cycle used by the components in the radar cycle task @min:0.0 @max:100.0 */
    uint8 uNoOfScans;                          /* Nubmer of scanns @min:1.0 @max:2.0 */
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV3::vel_array_t vel;                                 /* Ordinate: Additional ratio by super-imposed steering */
    VehParV3::rat_array_t_0 rat;                                 /* Abscissa: Vehicle velocity sample points */
  } vel_t;			/* Table for additional steering ratio part in dependence of velocity */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehParV3::swa_t swa;                                 /* Table for base steering ratio in dependence of steering wheel angle */
    VehParV3::vel_t vel;                                 /* Table for additional steering ratio part in dependence of velocity */
  } StRatio_t;			/* Steering ratio */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t State;                               /* vehicle parameter states @values: struct VDYParaState */
    float32 SelfSteerGrad;                       /* Rate of change in steering wheel angle with respect to change in steady-state lateral acceleration. @min:-128.0 @max:128.0 */
    VehParV3::StRatio_t SteeringRatio;                       /* Rate of change of steering wheel angle at given steering wheel trim position, with respect to change in average steer angel of a pair of steered wheels. In case of active steering systems this parameter is dependent additional vehicle states @min:1.0 @max:30.0 */
    float32 WheelBase;                           /* Longitudinal distance between  the center of tire contact of pair of wheels on same vehicle side @min:0.0 @max:10.0 */
    float32 TrackWidthFront;                     /* Lateral distance between the center of tire contact of pair of wheels on front vehicle axle @min:1.0 @max:5.0 */
    float32 TrackWidthRear;                      /* Lateral distance between the center of tire contact of pair of wheels on rear vehicle axle @min:1.0 @max:5.0 */
    float32 VehWeight;                           /* Vehicle weight @min:1.0 @max:60000.0 */
    float32 CntrOfGravHeight;                    /* Imaginary point where the total weight of the body may be thought to be concentrated @min:0.2 @max:3.0 */
    float32 AxisLoadDistr;                       /* The ratio of the vertical load at rear axle to total vehicle vertical load @min:0.1 @max:0.9 */
    float32 WhlLoadDepFrontAxle;                 /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at front axle @min:0.0 @max:3.0 */
    float32 WhlLoadDepRearAxle;                  /* Change of difference in wheel circumferential speed resulting from this load transfer during cornering at rear axle @min:0.0 @max:3.0 */
    float32 WhlCircumference;                    /* Dynamic wheel rolling circumference @min:1.0 @max:5.0 */
    uint8 DrvAxle;                             /* Powered Axle @min:1.0 @max:5.0 */
    uint8 WhlTcksPerRev;                       /* Number of sensor pulses per wheel revolution @min:1.0 @max:150.0 */
    float32 FrCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at front axle @min:-25.0 @max:25.0 */
    float32 ReCrnrStiff;                         /* The rate of change of lateral force with respect to change in side slip angle at rear axle @min:-25.0 @max:25.0 */
  } VehParMain_t;			/* Vehicle main parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehParV3::VehParMain_t VehParMain;                          /* Vehicle main parameters */
    VehParV3::VehParAdd_t VehParAdd;                           /* Vehicle additional parameters */
    VehParV3::SensorMounting_t SensorMounting;                      /* Sensor mounting geometry */
    VehParV3::Sensor_t Sensor;                              /* Sensor specific parameters */
  } VehPar_t;			/* Static Vehicle parameters */
};  // End of VehParV3 namespace

// VehPar V4
namespace VehParV4 {

  typedef VehParV3::VehPar_t VehPar_t;

};  // End of VehParV4 namespace

namespace VehParV5 {

  typedef sint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0.0 @max:65535.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0.0 @max:4294967295.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0.0 @max:4294967295.0 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef sint32 ParState_t                /* @min: 0 @max:1000000 @values: enum { VDY_PAR_POS_AXLD=14,VDY_PAR_POS_MAX=1000000,VDY_PAR_POS_WHLDRE=18,VDY_PAR_POS_TWDFR=6,VDY_PAR_POS_WTCKSREV=22,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=10,VDY_PAR_POS_CSFR=26,VDY_PAR_POS_COGH=12,VDY_PAR_POS_WHLDFR=16,VDY_PAR_POS_SWARAT=2,VDY_PAR_POS_WHLCIR=20,VDY_PAR_POS_WBASE=4,VDY_PAR_POS_CSRE=28,VDY_PAR_POS_TWDRE=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 VehParAddState_t          /* @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_DUMMY=1000000,VEH_PAR_ADD_STEERING_VARIANT=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorMountingState_t /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorState_t        /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef AlgoSignalState_t */
  const AlgoSignalState_t AL_SIG_STATE_INIT    = (0);
  const AlgoSignalState_t AL_SIG_STATE_OK      = (1);
  const AlgoSignalState_t AL_SIG_STATE_INVALID = (2);

  /* typedef SteeringVariant_t */
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_UNKNOWN  = (0);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE  = (1);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE  = (2);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef VehParSenorMountingState_t 	State_array_t_4[2];/* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */			/* [Satisfies_rte_sws_1189] */
  typedef VehParSenorState_t        	State_array_t_5[2];/* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */			/* [Satisfies_rte_sws_1189] */
  typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */
  /* Abscissa: Steering wheel angle sample points */			/* [Satisfies_rte_sws_1189] */
  typedef ParState_t                	State_array_t_2[2];/* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter states @values: struct VDYParaState */			/* [Satisfies_rte_sws_1189] */
  typedef VehParAddState_t          	State_array_t_3[2];/* vehicle additional parameter states  @values: struct VDYParaAddState */	/* [Satisfies_rte sws 1189] */
  /* vehicle additional parameter states  @values: struct VDYParaAddState */			/* [Satisfies_rte_sws_1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_4 State;
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
    State_array_t_5 State;
    float32 CoverDamping;
    float32 fCoverageAngle;
    float32 fLobeAngle;
    float32 fCycleTime;
    uint8 uNoOfScans;
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_3 State;
    float32 VehicleWidth;
    float32 CurbWeight;
    float32 OverhangFront;
    SteeringVariant_t SteeringVariant;
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */
  /* Ordinate: Base ratio sample points */			/* [Satisfies_rte_sws_1189] */
  typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */
  /* Abscissa: Vehicle velocity sample points */			/* [Satisfies_rte_sws_1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    ang_array_t ang;
    rat_array_t rat;
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */
  /* Ordinate: Additional ratio by super-imposed steering */			/* [Satisfies_rte_sws_1189] */
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
    State_array_t_2 State;
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
    SignalHeader_t sSignalHeader;
    VehParMain_t VehParMain;
    VehParAdd_t VehParAdd;
    SensorMounting_t SensorMounting;
    Sensor_t Sensor;
  } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300, 0xFFFFFFFF @cycleid:vdy_cycle_id,RSP_ENV @vname:VehPar,RadarVehPar */
}

namespace VehParV6 {
/*
- Add WheelWith to add parameters
- Add FrontAxleRoadDist to add parameters
*/
  typedef sint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0.0 @max:65535.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0.0 @max:4294967295.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0.0 @max:4294967295.0 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef sint32 ParState_t                /* @min: 0 @max:1000000 @values: enum { VDY_PAR_POS_AXLD=14,VDY_PAR_POS_MAX=1000000,VDY_PAR_POS_WHLDRE=18,VDY_PAR_POS_TWDFR=6,VDY_PAR_POS_WTCKSREV=22,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=10,VDY_PAR_POS_CSFR=26,VDY_PAR_POS_COGH=12,VDY_PAR_POS_WHLDFR=16,VDY_PAR_POS_SWARAT=2,VDY_PAR_POS_WHLCIR=20,VDY_PAR_POS_WBASE=4,VDY_PAR_POS_CSRE=28,VDY_PAR_POS_TWDRE=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 VehParAddState_t          /* @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_DUMMY=1000000,VEH_PAR_ADD_STEERING_VARIANT=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorMountingState_t /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorState_t        /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef AlgoSignalState_t */
  const AlgoSignalState_t AL_SIG_STATE_INIT    = (0);
  const AlgoSignalState_t AL_SIG_STATE_OK      = (1);
  const AlgoSignalState_t AL_SIG_STATE_INVALID = (2);

  /* typedef ParState_t */
  const ParState_t VDY_PAR_POS_SSG  = (0);
  const ParState_t VDY_PAR_POS_SWARAT  = (2);
  const ParState_t VDY_PAR_POS_WBASE  = (4);
  const ParState_t VDY_PAR_POS_TWDFR  = (6);
  const ParState_t VDY_PAR_POS_TWDRE  = (8);
  const ParState_t VDY_PAR_POS_VEHWGT  = (10);
  const ParState_t VDY_PAR_POS_COGH  = (12);
  const ParState_t VDY_PAR_POS_AXLD  = (14);
  const ParState_t VDY_PAR_POS_WHLDFR  = (16);
  const ParState_t VDY_PAR_POS_WHLDRE  = (18);
  const ParState_t VDY_PAR_POS_WHLCIR  = (20);
  const ParState_t VDY_PAR_POS_WTCKSREV  = (22);
  const ParState_t VDY_PAR_POS_CSFR  = (26);
  const ParState_t VDY_PAR_POS_CSRE  = (28);
  const ParState_t VDY_PAR_POS_MAX  = (1000000);

  /* typedef VehParAddState_t */
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_WIDTH  = (0);
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_LENGTH  = (2);
  const VehParAddState_t VEH_PAR_ADD_CURB_WEIGHT  = (4);
  const VehParAddState_t VEH_PAR_ADD_OVERHANG_FRONT  = (6);
  const VehParAddState_t VEH_PAR_ADD_FRONT_AXLE_ROAD  = (8);
  const VehParAddState_t VEH_PAR_ADD_WHEEL_WIDTH  = (10);
  const VehParAddState_t VEH_PAR_ADD_STEERING_VARIANT  = (12);
  const VehParAddState_t VEH_PAR_ADD_DUMMY  = (1000000);

  /* typedef SteeringVariant_t */
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_UNKNOWN  = (0);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE  = (1);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE  = (2);

  /* typedef VehParSenorMountingState_t */
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_LAT_POS  = (0);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_LONG_POS  = (2);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_VERT_POS  = (4);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG  = (6);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_PITCH_ANGLE  = (8);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_ORIENTATION  = (10);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_YAW_ANGLE  = (12);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_DUMMY  = (1000000);

  /* typedef VehParSenorState_t */
  const VehParSenorState_t VEH_PAR_SENSOR_COVER_DAMPING  = (0);
  const VehParSenorState_t VEH_PAR_SENSOR_COVERAGE_ANGLE  = (2);
  const VehParSenorState_t VEH_PAR_SENSOR_LOBE_ANGLE  = (4);
  const VehParSenorState_t VEH_PAR_SENSOR_CYCLE_TIME  = (6);
  const VehParSenorState_t VEH_PAR_SENSOR_NO_OF_SCANS  = (8);
  const VehParSenorState_t VEH_PAR_SENSOR_DUMMY  = (1000000);


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef VehParSenorMountingState_t 	State_array_t_4[2];/* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */			/* [Satisfies_rte_sws_1189] */
  typedef VehParSenorState_t        	State_array_t_5[2];/* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */			/* [Satisfies_rte_sws_1189] */
  typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */
  /* Abscissa: Steering wheel angle sample points */			/* [Satisfies_rte_sws_1189] */
  typedef ParState_t                	State_array_t_2[2];/* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter states @values: struct VDYParaState */			/* [Satisfies_rte_sws_1189] */
  typedef VehParAddState_t          	State_array_t_3[2];/* vehicle additional parameter states  @values: struct VDYParaAddState */	/* [Satisfies_rte sws 1189] */
  /* vehicle additional parameter states  @values: struct VDYParaAddState */			/* [Satisfies_rte_sws_1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_4 State;
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
    State_array_t_5 State;
    float32 CoverDamping;
    float32 fCoverageAngle;
    float32 fLobeAngle;
    float32 fCycleTime;
    uint8 uNoOfScans;
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_3 State;
    float32 VehicleWidth;
 	  float32 VehicleLength;
    float32 CurbWeight;
    float32 OverhangFront;
    float32 FrontAxleRoadDist;
    float32 WheelWidth;
    SteeringVariant_t SteeringVariant;
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */
  /* Ordinate: Base ratio sample points */			/* [Satisfies_rte_sws_1189] */
  typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */
  /* Abscissa: Vehicle velocity sample points */			/* [Satisfies_rte_sws_1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    ang_array_t ang;
    rat_array_t rat;
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */
  /* Ordinate: Additional ratio by super-imposed steering */			/* [Satisfies_rte_sws_1189] */
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
    State_array_t_2 State;
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
    SignalHeader_t sSignalHeader;
    VehParMain_t VehParMain;
    VehParAdd_t VehParAdd;
    SensorMounting_t SensorMounting;
    Sensor_t Sensor;
  } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300, 0xFFFFFFFF @vaddr_defs: VDY_MEAS_ID_VEH_PAR,RADAR_MEAS_ID_VEH_PAR @cycleid:vdy_cycle_id,RSP_ENV @vname:VehPar,RadarVehPar */

}

namespace VehParV6A {
  /*
  - Add WheelWith to add parameters
  - Add FrontAxleRoadDist to add parameters
  */
  typedef sint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0.0 @max:65535.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0.0 @max:4294967295.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0.0 @max:4294967295.0 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef sint32 ParState_t                /* @min: 0 @max:1000000 @values: enum { VDY_PAR_POS_AXLD=14,VDY_PAR_POS_MAX=1000000,VDY_PAR_POS_WHLDRE=18,VDY_PAR_POS_TWDFR=6,VDY_PAR_POS_WTCKSREV=22,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=10,VDY_PAR_POS_CSFR=26,VDY_PAR_POS_COGH=12,VDY_PAR_POS_WHLDFR=16,VDY_PAR_POS_SWARAT=2,VDY_PAR_POS_WHLCIR=20,VDY_PAR_POS_WBASE=4,VDY_PAR_POS_CSRE=28,VDY_PAR_POS_TWDRE=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 VehParAddState_t          /* @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_DUMMY=1000000,VEH_PAR_ADD_STEERING_VARIANT=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorMountingState_t /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorState_t        /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef AlgoSignalState_t */
  const AlgoSignalState_t AL_SIG_STATE_INIT    = (0);
  const AlgoSignalState_t AL_SIG_STATE_OK      = (1);
  const AlgoSignalState_t AL_SIG_STATE_INVALID = (2);

  /* typedef ParState_t */
  const ParState_t VDY_PAR_POS_SSG  = (0);
  const ParState_t VDY_PAR_POS_SWARAT  = (2);
  const ParState_t VDY_PAR_POS_WBASE  = (4);
  const ParState_t VDY_PAR_POS_TWDFR  = (6);
  const ParState_t VDY_PAR_POS_TWDRE  = (8);
  const ParState_t VDY_PAR_POS_VEHWGT  = (10);
  const ParState_t VDY_PAR_POS_COGH  = (12);
  const ParState_t VDY_PAR_POS_AXLD  = (14);
  const ParState_t VDY_PAR_POS_WHLDFR  = (16);
  const ParState_t VDY_PAR_POS_WHLDRE  = (18);
  const ParState_t VDY_PAR_POS_WHLCIR  = (20);
  const ParState_t VDY_PAR_POS_WTCKSREV  = (22);
  const ParState_t VDY_PAR_POS_CSFR  = (26);
  const ParState_t VDY_PAR_POS_CSRE  = (28);
  const ParState_t VDY_PAR_POS_MAX  = (1000000);

  /* typedef VehParAddState_t */
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_WIDTH  = (0);
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_LENGTH  = (2);
  const VehParAddState_t VEH_PAR_ADD_CURB_WEIGHT  = (4);
  const VehParAddState_t VEH_PAR_ADD_OVERHANG_FRONT  = (6);
  const VehParAddState_t VEH_PAR_ADD_FRONT_AXLE_ROAD  = (8);
  const VehParAddState_t VEH_PAR_ADD_WHEEL_WIDTH  = (10);
  const VehParAddState_t VEH_PAR_ADD_STEERING_VARIANT  = (12);
  const VehParAddState_t VEH_PAR_ADD_DUMMY  = (1000000);

  /* typedef SteeringVariant_t */
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_UNKNOWN  = (0);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE  = (1);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE  = (2);

  /* typedef VehParSenorMountingState_t */
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_LAT_POS  = (0);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_LONG_POS  = (2);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_VERT_POS  = (4);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG  = (6);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_PITCH_ANGLE  = (8);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_ORIENTATION  = (10);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_YAW_ANGLE  = (12);
  const VehParSenorMountingState_t VEH_PAR_SEN_MOUNT_DUMMY  = (1000000);

  /* typedef VehParSenorState_t */
  const VehParSenorState_t VEH_PAR_SENSOR_COVER_DAMPING  = (0);
  const VehParSenorState_t VEH_PAR_SENSOR_COVERAGE_ANGLE  = (2);
  const VehParSenorState_t VEH_PAR_SENSOR_LOBE_ANGLE  = (4);
  const VehParSenorState_t VEH_PAR_SENSOR_CYCLE_TIME  = (6);
  const VehParSenorState_t VEH_PAR_SENSOR_NO_OF_SCANS  = (8);
  const VehParSenorState_t VEH_PAR_SENSOR_DUMMY  = (1000000);


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef VehParSenorMountingState_t 	State_array_t_4[2];/* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */			/* [Satisfies_rte_sws_1189] */
  typedef VehParSenorState_t        	State_array_t_5[2];/* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */			/* [Satisfies_rte_sws_1189] */
  typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */
  /* Abscissa: Steering wheel angle sample points */			/* [Satisfies_rte_sws_1189] */
  typedef ParState_t                	State_array_t_2[2];/* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */
  /* vehicle parameter states @values: struct VDYParaState */			/* [Satisfies_rte_sws_1189] */
  typedef VehParAddState_t          	State_array_t_3[2];/* vehicle additional parameter states  @values: struct VDYParaAddState */	/* [Satisfies_rte sws 1189] */
  /* vehicle additional parameter states  @values: struct VDYParaAddState */			/* [Satisfies_rte_sws_1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_4 State;
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
    State_array_t_5 State;
    float32 CoverDamping;
    float32 fCoverageAngle;
    float32 fLobeAngle;
    float32 fCycleTime;
    uint8 uNoOfScans;
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_3 State;
    float32 VehicleWidth;
    float32 CurbWeight;
    float32 OverhangFront;
    float32 FrontAxleRoadDist;
    float32 WheelWidth;
    SteeringVariant_t SteeringVariant;
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */
  /* Ordinate: Base ratio sample points */			/* [Satisfies_rte_sws_1189] */
  typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */
  /* Abscissa: Vehicle velocity sample points */			/* [Satisfies_rte_sws_1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    ang_array_t ang;
    rat_array_t rat;
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

  typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */
  /* Ordinate: Additional ratio by super-imposed steering */			/* [Satisfies_rte_sws_1189] */
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
    State_array_t_2 State;
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
    SignalHeader_t sSignalHeader;
    VehParMain_t VehParMain;
    VehParAdd_t VehParAdd;
    SensorMounting_t SensorMounting;
    Sensor_t Sensor;
  } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300, 0xFFFFFFFF @vaddr_defs: VDY_MEAS_ID_VEH_PAR,RADAR_MEAS_ID_VEH_PAR @cycleid:vdy_cycle_id,RSP_ENV @vname:VehPar,RadarVehPar */

}


namespace VehParV7 {

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 ParState_t                /* @min: 0 @max:1000000 @values: enum { VDY_PAR_POS_AXLD=14,VDY_PAR_POS_MAX=1000000,VDY_PAR_POS_WHLDRE=18,VDY_PAR_POS_TWDFR=6,VDY_PAR_POS_WTCKSREV=22,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=10,VDY_PAR_POS_CSFR=26,VDY_PAR_POS_COGH=12,VDY_PAR_POS_WHLDFR=16,VDY_PAR_POS_SWARAT=2,VDY_PAR_POS_WHLCIR=20,VDY_PAR_POS_WBASE=4,VDY_PAR_POS_CSRE=28,VDY_PAR_POS_TWDRE=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParAddState_t          /* @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_PASSABLE_HEIGHT=14,VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_DUMMY=1000000,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_DIST_CAMERA_HOOD_Y=18,VEH_PAR_ADD_FRONT_AXLE_ROAD=8,VEH_PAR_ADD_WHEEL_WIDTH=10,VEH_PAR_ADD_DIST_CAMERA_HOOD_X=16,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_STEERING_VARIANT=12,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSensorMountingState_t /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 VehParSenorState_t        /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef ParState_t */
  const ParState_t VDY_PAR_POS_SSG      = (0);
  const ParState_t VDY_PAR_POS_SWARAT   = (2);
  const ParState_t VDY_PAR_POS_WBASE    = (4);
  const ParState_t VDY_PAR_POS_TWDFR    = (6);
  const ParState_t VDY_PAR_POS_TWDRE    = (8);
  const ParState_t VDY_PAR_POS_VEHWGT   = (10);
  const ParState_t VDY_PAR_POS_COGH     = (12);
  const ParState_t VDY_PAR_POS_AXLD     = (14);
  const ParState_t VDY_PAR_POS_WHLDFR   = (16);
  const ParState_t VDY_PAR_POS_WHLDRE   = (18);
  const ParState_t VDY_PAR_POS_WHLCIR   = (20);
  const ParState_t VDY_PAR_POS_WTCKSREV = (22);
  const ParState_t VDY_PAR_POS_CSFR     = (26);
  const ParState_t VDY_PAR_POS_CSRE     = (28);
  const ParState_t VDY_PAR_POS_MAX      = (1000000);

  /* typedef VehParAddState_t */
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_WIDTH      = (0);
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_LENGTH     = (2);
  const VehParAddState_t VEH_PAR_ADD_CURB_WEIGHT        = (4);
  const VehParAddState_t VEH_PAR_ADD_OVERHANG_FRONT     = (6);
  const VehParAddState_t VEH_PAR_ADD_FRONT_AXLE_ROAD    = (8);
  const VehParAddState_t VEH_PAR_ADD_WHEEL_WIDTH        = (10);
  const VehParAddState_t VEH_PAR_ADD_STEERING_VARIANT   = (12);
  const VehParAddState_t VEH_PAR_ADD_PASSABLE_HEIGHT    = (14);
  const VehParAddState_t VEH_PAR_ADD_DIST_CAMERA_HOOD_X = (16);
  const VehParAddState_t VEH_PAR_ADD_DIST_CAMERA_HOOD_Y = (18);
  const VehParAddState_t VEH_PAR_ADD_DUMMY              = (1000000);

  /* typedef SteeringVariant_t */
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_UNKNOWN    = (0);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE  = (1);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE = (2);

  /* typedef VehParSensorMountingState_t */
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LAT_POS        = (0);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LONG_POS       = (2);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_VERT_POS       = (4);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG = (6);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_PITCH_ANGLE    = (8);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_ORIENTATION    = (10);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_YAW_ANGLE      = (12);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_DUMMY          = (1000000);

  /* typedef VehParSenorState_t */
  const VehParSenorState_t VEH_PAR_SENSOR_COVER_DAMPING  = (0);
  const VehParSenorState_t VEH_PAR_SENSOR_COVERAGE_ANGLE = (2);
  const VehParSenorState_t VEH_PAR_SENSOR_LOBE_ANGLE     = (4);
  const VehParSenorState_t VEH_PAR_SENSOR_CYCLE_TIME     = (6);
  const VehParSenorState_t VEH_PAR_SENSOR_NO_OF_SCANS    = (8);
  const VehParSenorState_t VEH_PAR_SENSOR_DUMMY          = (1000000);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoDataTimeStamp_t uiTimeStamp;
 	  AlgoCycleCounter_t uiMeasurementCounter;
 	  AlgoCycleCounter_t uiCycleCounter;
 	  AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef ParState_t                	State_array_t_2[2];/* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */
  typedef VehParAddState_t          	State_array_t_3[2];/* vehicle additional parameter states  @values: struct VDYParaAddState */	/* [Satisfies_rte sws 1189] */
  typedef VehParSensorMountingState_t State_array_t_4[2];/* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */	/* [Satisfies_rte sws 1189] */
  typedef VehParSenorState_t        	State_array_t_5[2];/* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  ang_array_t ang;
 	  rat_array_t rat;
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

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
	  State_array_t_2 State;
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
	  State_array_t_3 State;
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

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  State_array_t_4 State;
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
	  State_array_t_5 State;
 	  float32 CoverDamping;
 	  float32 fCoverageAngle;
 	  float32 fLobeAngle;
 	  float32 fCycleTime;
 	  uint8 uNoOfScans;
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoInterfaceVersionNumber_t uiVersionNumber;
 	  SignalHeader_t sSignalHeader;
 	  VehParMain_t VehParMain;
 	  VehParAdd_t VehParAdd;
 	  SensorMounting_t SensorMounting;
 	  Sensor_t Sensor;
  } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300, 0x20800100 @vaddr_defs: VDY_MEAS_ID_VEH_PAR,RADAR_MEAS_ID_VEH_PAR @cycleid:vdy_cycle_id,RSP_ENV @vname:VehPar,RadarVehPar */

}


namespace VehParV8
{

  /*! External interface states version 8 and higher */
  const uint8 VEH_PAR_IO_STATE_VALID = 0U;
  const uint8 VEH_PAR_IO_STATE_INVALID = 1U;
  const uint8 VEH_PAR_IO_STATE_NOTAVAIL = 2U;
	const uint8 VEH_PAR_IO_STATE_DECREASED = 3U;
	const uint8 VEH_PAR_IO_STATE_SUBSTITUE = 4U;
	const uint8 VEH_PAR_IO_STATE_INIT = 15U;
	const uint8 VEH_PAR_IO_STATE_MAX = 255U;

  typedef unsigned char VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 ParState_t                /* @min: 0 @max:1000000 @values: enum { VDY_PAR_POS_AXLD=14,VDY_PAR_POS_MAX=1000000,VDY_PAR_POS_WHLDRE=18,VDY_PAR_POS_TWDFR=6,VDY_PAR_POS_WTCKSREV=22,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=10,VDY_PAR_POS_CSFR=26,VDY_PAR_POS_COGH=12,VDY_PAR_POS_WHLDFR=16,VDY_PAR_POS_SWARAT=2,VDY_PAR_POS_WHLCIR=20,VDY_PAR_POS_WBASE=4,VDY_PAR_POS_CSRE=28,VDY_PAR_POS_TWDRE=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehParAddState_t          /* @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_PASSABLE_HEIGHT=14,VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_DUMMY=1000000,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_DIST_CAMERA_HOOD_Y=18,VEH_PAR_ADD_FRONT_AXLE_ROAD=8,VEH_PAR_ADD_WHEEL_WIDTH=10,VEH_PAR_ADD_DIST_CAMERA_HOOD_X=16,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_STEERING_VARIANT=12,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehParSensorMountingState_t /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehParSenorState_t        /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef ParState_t */
  const ParState_t VEH_PAR_POS_SSG      = (0);
  const ParState_t VEH_PAR_POS_SWARAT   = (1);
  const ParState_t VEH_PAR_POS_WBASE    = (2);
  const ParState_t VEH_PAR_POS_TWDFR    = (3);
  const ParState_t VEH_PAR_POS_TWDRE    = (4);
  const ParState_t VEH_PAR_POS_VEHWGT   = (5);
  const ParState_t VEH_PAR_POS_COGH     = (6);
  const ParState_t VEH_PAR_POS_AXLD     = (7);
  const ParState_t VEH_PAR_POS_WHLDFR   = (8);
  const ParState_t VEH_PAR_POS_WHLDRE   = (9);
  const ParState_t VEH_PAR_POS_WHLCIR   = (10);
  const ParState_t VEH_PAR_POS_WTCKSREV = (11);
  const ParState_t VEH_PAR_POS_CSFR     = (12);
  const ParState_t VEH_PAR_POS_CSRE     = (14);
  const ParState_t VEH_PAR_POS_MAX      = (16);

  /* typedef VehParAddState_t */
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_WIDTH      = (0);
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_LENGTH     = (1);
  const VehParAddState_t VEH_PAR_ADD_CURB_WEIGHT        = (2);
  const VehParAddState_t VEH_PAR_ADD_OVERHANG_FRONT     = (3);
  const VehParAddState_t VEH_PAR_ADD_FRONT_AXLE_ROAD    = (4);
  const VehParAddState_t VEH_PAR_ADD_WHEEL_WIDTH        = (5);
  const VehParAddState_t VEH_PAR_ADD_STEERING_VARIANT   = (6);
  const VehParAddState_t VEH_PAR_ADD_PASSABLE_HEIGHT    = (7);
  const VehParAddState_t VEH_PAR_ADD_DIST_CAMERA_HOOD_X = (8);
  const VehParAddState_t VEH_PAR_ADD_DIST_CAMERA_HOOD_Y = (9);
  const VehParAddState_t VEH_PAR_ADD_MAX                = (12);

  /* typedef SteeringVariant_t */
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_UNKNOWN    = (0);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE  = (1);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE = (2);

  /* typedef VehParSensorMountingState_t */
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LAT_POS        = (0);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LONG_POS       = (1);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_VERT_POS       = (2);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG = (3);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_PITCH_ANGLE    = (4);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_ORIENTATION    = (5);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_YAW_ANGLE      = (6);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_MAX            = (8);

  /* typedef VehParSenorState_t */
  const VehParSenorState_t VEH_PAR_SENSOR_COVER_DAMPING  = (0);
  const VehParSenorState_t VEH_PAR_SENSOR_COVERAGE_ANGLE = (1);
  const VehParSenorState_t VEH_PAR_SENSOR_LOBE_ANGLE     = (2);
  const VehParSenorState_t VEH_PAR_SENSOR_CYCLE_TIME     = (3);
  const VehParSenorState_t VEH_PAR_SENSOR_NO_OF_SCANS    = (4);
  const VehParSenorState_t VEH_PAR_SENSOR_MAX            = (8);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoDataTimeStamp_t uiTimeStamp;
 	  AlgoCycleCounter_t uiMeasurementCounter;
 	  AlgoCycleCounter_t uiCycleCounter;
 	  AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef VDYIoStateTypes_t          	State_array_t_2[VEH_PAR_POS_MAX];/* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t          	State_array_t_3[VEH_PAR_ADD_MAX];/* vehicle additional parameter states  @values: struct VDYParaAddState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t           State_array_t_4[VEH_PAR_SEN_MOUNT_MAX];/* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t           State_array_t_5[VEH_PAR_SENSOR_MAX];/* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  ang_array_t ang;
 	  rat_array_t rat;
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

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
	  State_array_t_2 State;
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
	  State_array_t_3 State;
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

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  State_array_t_4 State;
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
	  State_array_t_5 State;
 	  float32 CoverDamping;
 	  float32 fCoverageAngle;
 	  float32 fLobeAngle;
 	  float32 fCycleTime;
 	  uint8 uNoOfScans;
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoInterfaceVersionNumber_t uiVersionNumber;
 	  SignalHeader_t sSigHeader;
 	  VehParMain_t VehParMain;
 	  VehParAdd_t VehParAdd;
 	  SensorMounting_t SensorMounting;
 	  Sensor_t Sensor;
  } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300, 0x20800100 @vaddr_defs: VDY_MEAS_ID_VEH_PAR,RADAR_MEAS_ID_VEH_PAR @cycleid:vdy_cycle_id,RSP_ENV @vname:VehPar,RadarVehPar */
}

namespace VehParV9
{

  /*! External interface states version 9 and higher */
  const uint8 VEH_PAR_IO_STATE_VALID = 0U;
  const uint8 VEH_PAR_IO_STATE_INVALID = 1U;
  const uint8 VEH_PAR_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_PAR_IO_STATE_DECREASED = 3U;
  const uint8 VEH_PAR_IO_STATE_SUBSTITUE = 4U;
  const uint8 VEH_PAR_IO_STATE_INIT = 15U;
  const uint8 VEH_PAR_IO_STATE_MAX = 255U;

  typedef unsigned char VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 ParState_t                /* @min: 0 @max:1000000 @values: enum { VDY_PAR_POS_AXLD=14,VDY_PAR_POS_MAX=1000000,VDY_PAR_POS_WHLDRE=18,VDY_PAR_POS_TWDFR=6,VDY_PAR_POS_WTCKSREV=22,VDY_PAR_POS_SSG=0,VDY_PAR_POS_VEHWGT=10,VDY_PAR_POS_CSFR=26,VDY_PAR_POS_COGH=12,VDY_PAR_POS_WHLDFR=16,VDY_PAR_POS_SWARAT=2,VDY_PAR_POS_WHLCIR=20,VDY_PAR_POS_WBASE=4,VDY_PAR_POS_CSRE=28,VDY_PAR_POS_TWDRE=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehParAddState_t          /* @min: 0 @max:1000000 @values: enum { VEH_PAR_ADD_CURB_WEIGHT=4,VEH_PAR_ADD_PASSABLE_HEIGHT=14,VEH_PAR_ADD_OVERHANG_FRONT=6,VEH_PAR_ADD_DUMMY=1000000,VEH_PAR_ADD_VEHICLE_WIDTH=0,VEH_PAR_ADD_DIST_CAMERA_HOOD_Y=18,VEH_PAR_ADD_FRONT_AXLE_ROAD=8,VEH_PAR_ADD_WHEEL_WIDTH=10,VEH_PAR_ADD_DIST_CAMERA_HOOD_X=16,VEH_PAR_ADD_VEHICLE_LENGTH=2,VEH_PAR_ADD_STEERING_VARIANT=12,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringVariant_t         /* Mounting position of steering wheel (in driving direction) @min: 0 @max:2 @values: enum { VEH_PAR_ADD_STEERING_VAR_UNKNOWN=0,VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE=2,VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehParSensorMountingState_t /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SEN_MOUNT_LAT_POS=0,VEH_PAR_SEN_MOUNT_DUMMY=1000000,VEH_PAR_SEN_MOUNT_PITCH_ANGLE=8,VEH_PAR_SEN_MOUNT_LONG_POS=2,VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG=6,VEH_PAR_SEN_MOUNT_YAW_ANGLE=12,VEH_PAR_SEN_MOUNT_ORIENTATION=10,VEH_PAR_SEN_MOUNT_VERT_POS=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 Orientation_t             /* Angular displacement about sensor longitudinal axis @min: 0 @max:1 @values: enum { SENSOR_OR_NORMAL=0,SENSOR_OR_ROTATED=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehParSenorState_t        /* @min: 0 @max:1000000 @values: enum { VEH_PAR_SENSOR_LOBE_ANGLE=4,VEH_PAR_SENSOR_COVER_DAMPING=0,VEH_PAR_SENSOR_COVERAGE_ANGLE=2,VEH_PAR_SENSOR_CYCLE_TIME=6,VEH_PAR_SENSOR_NO_OF_SCANS=8,VEH_PAR_SENSOR_DUMMY=1000000,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SteeringWheelNum_t         /* Steering wheel Number  @min: 1 @max:2 @values: enum {VEH_PAR_ADD_STEERING_WHEEL_TWO =1,VEH_PAR_ADD_STEERING_WHEEL_FOUR=2,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef ParState_t */
  const ParState_t VEH_PAR_POS_SSG      = (0);
  const ParState_t VEH_PAR_POS_SWARAT   = (1);
  const ParState_t VEH_PAR_POS_WBASE    = (2);
  const ParState_t VEH_PAR_POS_TWDFR    = (3);
  const ParState_t VEH_PAR_POS_TWDRE    = (4);
  const ParState_t VEH_PAR_POS_VEHWGT   = (5);
  const ParState_t VEH_PAR_POS_COGH     = (6);
  const ParState_t VEH_PAR_POS_AXLD     = (7);
  const ParState_t VEH_PAR_POS_WHLDFR   = (8);
  const ParState_t VEH_PAR_POS_WHLDRE   = (9);
  const ParState_t VEH_PAR_POS_WHLCIR   = (10);
  const ParState_t VEH_PAR_POS_WTCKSREV = (11);
  const ParState_t VEH_PAR_POS_CSFR     = (12);
  const ParState_t VEH_PAR_POS_CSRE     = (14);
  const ParState_t VEH_PAR_POS_MAX      = (16);

  /* typedef VehParAddState_t */
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_WIDTH      = (0);
  const VehParAddState_t VEH_PAR_ADD_VEHICLE_LENGTH     = (1);
  const VehParAddState_t VEH_PAR_ADD_CURB_WEIGHT        = (2);
  const VehParAddState_t VEH_PAR_ADD_OVERHANG_FRONT     = (3);
  const VehParAddState_t VEH_PAR_ADD_FRONT_AXLE_ROAD    = (4);
  const VehParAddState_t VEH_PAR_ADD_WHEEL_WIDTH        = (5);
  const VehParAddState_t VEH_PAR_ADD_STEERING_VARIANT   = (6);
  const VehParAddState_t VEH_PAR_ADD_PASSABLE_HEIGHT    = (7);
  const VehParAddState_t VEH_PAR_ADD_DIST_CAMERA_HOOD_X = (8);
  const VehParAddState_t VEH_PAR_ADD_DIST_CAMERA_HOOD_Y = (9);
  const VehParAddState_t VEH_PAR_ADD_STEERING_WHEEL     = (10);
  const VehParAddState_t VEH_PAR_ADD_MAX                = (12);

  /* typedef SteeringVariant_t */
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_UNKNOWN    = (0);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE  = (1);
  const SteeringVariant_t VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE = (2);

    /* typedef SteeringWheelNum_t */
  const SteeringWheelNum_t VEH_PAR_ADD_STEERING_WHEEL_TWO  = (1);
  const SteeringWheelNum_t VEH_PAR_ADD_STEERING_WHEEL_FOUR = (2);

  /* typedef VehParSensorMountingState_t */
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LAT_POS        = (0);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LONG_POS       = (1);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_VERT_POS       = (2);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG = (3);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_PITCH_ANGLE    = (4);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_ORIENTATION    = (5);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_YAW_ANGLE      = (6);
  const VehParSensorMountingState_t VEH_PAR_SEN_MOUNT_MAX            = (8);

  /* typedef VehParSenorState_t */
  const VehParSenorState_t VEH_PAR_SENSOR_COVER_DAMPING  = (0);
  const VehParSenorState_t VEH_PAR_SENSOR_COVERAGE_ANGLE = (1);
  const VehParSenorState_t VEH_PAR_SENSOR_LOBE_ANGLE     = (2);
  const VehParSenorState_t VEH_PAR_SENSOR_CYCLE_TIME     = (3);
  const VehParSenorState_t VEH_PAR_SENSOR_NO_OF_SCANS    = (4);
  const VehParSenorState_t VEH_PAR_SENSOR_MAX            = (8);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoDataTimeStamp_t uiTimeStamp;
 	  AlgoCycleCounter_t uiMeasurementCounter;
 	  AlgoCycleCounter_t uiCycleCounter;
 	  AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef VDYIoStateTypes_t          	State_array_t_2[VEH_PAR_POS_MAX];/* vehicle parameter states @values: struct VDYParaState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t          	State_array_t_3[VEH_PAR_ADD_MAX];/* vehicle additional parameter states  @values: struct VDYParaAddState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t           State_array_t_4[VEH_PAR_SEN_MOUNT_MAX];/* vehicle parameter sensor mounting states   @values: struct VDYParaSensorMountingState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t           State_array_t_5[VEH_PAR_SENSOR_MAX];/* vehicle parameter sensor parameter states   @values: struct VDYParaSensorState */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	ang_array_t[2];/* Abscissa: Steering wheel angle sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	rat_array_t[2];/* Ordinate: Base ratio sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	rat_array_t_0[2];/* Abscissa: Vehicle velocity sample points */	/* [Satisfies_rte sws 1189] */
  typedef float32                   	vel_array_t[2];/* Ordinate: Additional ratio by super-imposed steering */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  ang_array_t ang;
 	  rat_array_t rat;
  } swa_t;			/* Table for base steering ratio in dependence of steering wheel angle */

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
	  State_array_t_2 State;
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
	  State_array_t_3 State;
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
      SteeringWheelNum_t SteeringWheelNumber;
  } VehParAdd_t;			/* Vehicle additional parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  State_array_t_4 State;
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
	  State_array_t_5 State;
 	  float32 CoverDamping;
 	  float32 fCoverageAngle;
 	  float32 fLobeAngle;
 	  float32 fCycleTime;
 	  uint8 uNoOfScans;
  } Sensor_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoInterfaceVersionNumber_t uiVersionNumber;
 	  SignalHeader_t sSigHeader;
 	  VehParMain_t VehParMain;
 	  VehParAdd_t VehParAdd;
 	  SensorMounting_t SensorMounting;
 	  Sensor_t Sensor;
  } VehPar_t;			/* Static Vehicle parameters @vaddr:0x20300300, 0x20800100 @vaddr_defs: VDY_MEAS_ID_VEH_PAR,RADAR_MEAS_ID_VEH_PAR @cycleid:vdy_cycle_id,RSP_ENV @vname:VehPar,RadarVehPar */
}
#endif // interfacevehpar_h__
