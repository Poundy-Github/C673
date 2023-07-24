/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_vdy

  MODULNAME:            interfacevehdyn

  DESCRIPTION:          veh dyn input types

  AUTHOR:               -

  CREATION DATE:        15.13.2012

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interfacevehdyn.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:27CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:26CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.11 2016/10/12 06:41:33CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              added handling for VehDyn interface version 32  for ARS510
  CHANGES:              Revision 1.10 2016/07/14 16:08:34CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              added handling for VehDyn interface version 9
  CHANGES:               for ARS510
  CHANGES:              Revision 1.9 2015/03/31 18:15:26CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:              added handling for VehDyn interface version 8
  CHANGES:              --- Added comments ---  eisenacherm [Mar 31, 2015 6:15:27 PM CEST]
  CHANGES:              Change Package : 320951:6 http://mks-psad:7002/im/viewissue?selection=320951
  CHANGES:              Revision 1.8 2015/01/27 13:22:03CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added VehDynV6_2 with size 172 and not updated version number (=6)
  CHANGES:              --- Added comments ---  berndtt1 [Jan 27, 2015 1:41:17 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.7 2014/01/28 15:37:16CET Wolter, Frank (wolterf) 
  CHANGES:              Added VehDyn V6
  CHANGES:              --- Added comments ---  wolterf [Jan 28, 2014 3:37:16 PM CET]
  CHANGES:              Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGES:              Revision 1.6 2013/03/26 09:07:26CET Westhofen, Daniel (uidt2642) 
  CHANGES:              temp bugfix for already defined constants
  CHANGES:              --- Added comments ---  uidt2642 [Mar 26, 2013 9:07:28 AM CET]
  CHANGES:              Change Package : 162889:17 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.5 2013/02/06 12:59:47CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:48 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.4 2013/01/21 09:43:35CET Spruck, Jochen (spruckj) 
  CHANGES:              define vdy valid flags only if not defined
  CHANGES:              --- Added comments ---  spruckj [Jan 21, 2013 9:43:40 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.3 2013/01/17 09:44:19CET Spruck, Jochen (spruckj) 
  CHANGES:              Update adapter
  CHANGES:              --- Added comments ---  spruckj [Jan 17, 2013 9:44:23 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.2 2013/01/16 13:06:08CET Spruck, Jochen (spruckj) 
  CHANGES:              Rename namespaces, because of conflicts
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 1:06:08 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.1 2013/01/16 11:34:46CET Spruck, Jochen (spruckj) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/03_Workspace/algo/vdy_sim/vdy_adapter/include/project.pj
  **************************************************************************** */
#ifndef interfacevehdyn_h__
#define interfacevehdyn_h__


#if !defined(fSpeed_t)
typedef f32_t fSpeed_t;
#endif
#if !defined(fAcceleration_t)
typedef f32_t fAcceleration_t;
#endif
#if !defined(times_t)
typedef unsigned __int16 times_t;
#endif


/*! @description: VDYIoState_t  
  @resolution: tbd   @unit: tbd   @min: 0     @max: tbd  */
typedef ui32_t VDYIoState_t;

#ifndef VDY_IO_STATE_BITMASK
#define VDY_IO_STATE_BITMASK                   ((VDYIoState_t) (0x3U))
#endif

#ifndef VDY_SET_IO_STATE
#define VDY_SET_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#endif

#ifndef VDY_GET_IO_STATE
#define VDY_GET_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif


/*! External interface states */
#define VDY_IO_STATE_NO_BIT            2UL
#if !defined(VDY_IO_STATE_VALID)
#define VDY_IO_STATE_VALID             ((VDYIoState_t) 0U)
#define VDY_IO_STATE_INVALID           ((VDYIoState_t) 1U)
#define VDY_IO_STATE_NOTAVAIL          ((VDYIoState_t) 2U)
#define VDY_IO_STATE_INIT              ((VDYIoState_t) 3U)
#endif

/*! Bit position of output signal states */
#ifndef VDY_SOUT_POS_CURVE
#define VDY_SOUT_POS_CURVE         (0UL)                           /*!< Curvature of vehicle tracetory                         */
#define VDY_SOUT_POS_YWR           (1UL * VDY_IO_STATE_NO_BIT)     /*!< Estimated vehicle yaw velocity                         */
#define VDY_SOUT_POS_DRCRV         (2UL * VDY_IO_STATE_NO_BIT)     /*!< Driver intended curvature                              */
#define VDY_SOUT_POS_VEL           (3UL * VDY_IO_STATE_NO_BIT)     /*!< Vehicle long. velocity                                 */
#define VDY_SOUT_POS_ACCEL         (4UL * VDY_IO_STATE_NO_BIT)     /*!< Vehicle long. acceleration                             */
#define VDY_SOUT_POS_MSTAT         (5UL * VDY_IO_STATE_NO_BIT)     /*!< Vehicle long. motion state                             */
#define VDY_SOUT_POS_VCORR         (6UL * VDY_IO_STATE_NO_BIT)     /*!< Velocity Correction                                    */
#define VDY_SOUT_POS_SSA           (7UL * VDY_IO_STATE_NO_BIT)     /*!< Side slip angle                                        */
#define VDY_SOUT_POS_LATACC        (8UL * VDY_IO_STATE_NO_BIT)     /*!< Lateral acceleration                                   */
#endif


namespace TPW_DYN_300 {


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

namespace RSP_DYN_300 {
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
#define RSP_M_STATE_REV     ((RSP_DYN_300::RSPMotionState_t) 0)
#endif
#ifndef RSP_M_STATE_FWD
#define RSP_M_STATE_FWD     ((RSP_DYN_300::RSPMotionState_t) 1)
#endif
#ifndef RSP_M_STATE_UNCLEAR
#define RSP_M_STATE_UNCLEAR ((RSP_DYN_300::RSPMotionState_t) 2)
#endif
#ifndef RSP_M_STATE_STDSTL
#define RSP_M_STATE_STDSTL  ((RSP_DYN_300::RSPMotionState_t) 3)
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

namespace VDY_DYN_300 {

#if !defined(VDY_LONG_MOT_STATE_MOVE) && !defined(VDY_LONG_MOT_STATE_MOVE_FWD) && !defined(VDY_LONG_MOT_STATE_MOVE_RWD) && !defined(VDY_LONG_MOT_STATE_STDST)
  typedef enum eMotState_t {
    VDY_LONG_MOT_STATE_MOVE     = (0U),
    VDY_LONG_MOT_STATE_MOVE_FWD = (1U),
    VDY_LONG_MOT_STATE_MOVE_RWD = (2U),
    VDY_LONG_MOT_STATE_STDST    = (3U)
  } eMotState_t;
#endif

  /*! @description: VDYIoState_t  
    @resolution: tbd   @unit: tbd   @min: 0     @max: tbd  */
  typedef ui8_t VDYErrState_t;

  /*! @description: VDYIoState_t  
    @resolution: tbd   @unit: tbd   @min: 0     @max: tbd  */
  typedef ui32_t VDYIoState_t;

  /*! @description: Longitudinal  motion state  
    @resolution: tbd    @unit: tbd  @min: 0     @max: tbd  */
  typedef ui8_t  VDYLongMotState_t;

  /*---- Output Data ----------------------------------------------------------*/

  /*! Estimated curvature of vehicle tracetory */
  typedef struct {
    fCurve_t     Curve;      /*!< Curvature in 1/Radius, 1/R > 0 -> left turn */
    fCurve_t     C1;         /*!< Curvature change as function of distance  d/ds (1/R) */
    fGradient_t  Gradient;   /*!< Curvature change as function of time  d/dt (1/R) */
    fVariance_t  varC0;      /*!< Variance of C0 estimation */
    fVariance_t  varC1;      /*!< Variance of C1 estimation */
    fQuality_t   Quality;    /*!< Quality of the vehicle curvature, uses all availabel offset states */
  } VDYOutCurvature_v1_t;
  /*! Estimated curvature of vehicle tracetory */
  typedef struct {
    fCurve_t     Curve;      /*!< Curvature in 1/Radius, 1/R > 0 -> left turn */
    fCurve_t     C1;         /*!< Curvature change as function of distance  d/ds (1/R) */
    fGradient_t  Gradient;   /*!< Curvature change as function of time  d/dt (1/R) */
    fVariance_t  varC0;      /*!< Variance of C0 estimation */
    fVariance_t  varC1;      /*!< Variance of C1 estimation */
  } VDYOutCurvature_v2_t;

  /*! Estimated vehicle yaw velocity  */
  typedef struct {
    fYawRate_t   Yawrate;   /*!< Vehicle yaw veloity along the vertical axis */
    fVariance_t  Variance;  /*!< Variance of estimation */
    fQuality_t   Quality;   /*!< Quality of the vehicle yaw velocity, uses all availabel offset states */
  } VDYOutYawRate_v1_t;
  /*! Estimated vehicle yaw velocity  */
  typedef struct {
    fYawRate_t   Yawrate;   /*!< Vehicle yaw veloity along the vertical axis */
    fVariance_t  Variance;  /*!< Variance of estimation */
  } VDYOutYawRate_v2_t;

  /*! Estimated sensor yaw velocity  */
  typedef struct {
    fYawRate_t   Yawrate;   /*!< Vehicle yaw veloity along the vertical axis */
    fVariance_t  Variance;  /*!< Variance of estimation */
    fQuality_t   Quality;   /*!< Quality of the sensor yaw velocity, use the yaw rate sensor offsets state / quality */
  } VDYOutSensorYawRate_t;

  /*! Estimated vehicle lateral acceleration */
  typedef struct {
    fAcceleration_t LatAccel;
    fVariance_t     Variance;
  } VDYOutLatAccel_t;

  /*! Estimated driver intended curvature */
  typedef struct {
    fCurve_t     Curve;      /*!< Estimated curvature */
    fVariance_t  Variance;   /*!< Variance of estimation */
    fGradient_t  Gradient;   /*!< Course curvature gradient d/dt (1/R) */
  } VDYOutDrvIntCrv_t;

  /*! Estimated vehicle body side slip angle */
  typedef struct {
    fAngle_t     SideSlipAngle;
    fVariance_t  Variance;
  } VDYOutSideSlipAngle_t;

  /*! Estimated vehicle long. motion state */
  typedef struct {
    VDYLongMotState_t   MotState;     /*!< Longitudinal motion state */
    ui8_t               Pad1;         /*!< Padding Byte for CSF sim   */
    ui8_t               Pad2;         /*!< Padding Byte for CSF sim   */
    ui8_t               Pad3;         /*!< Padding Byte for CSF sim   */
    fConfidence_t       Confidence;   /*!< Confidence of standstill or moving direction */
  } VDYOutLongMotState_t;

  /*! Estimated velocity correction by means of stationary targets */
  typedef struct {
    fRatio_t            corrFact;
    fVariance_t         corrVar;
    fVelocity_t         corrVelo;
    fVariance_t         corrVeloVar;
    fVelocity_t         minVelo;
    fVelocity_t         maxVelo;
  } VDYOutVelCorr_t;

  /*! Error indication output interface */
  typedef struct {
    VDYErrState_t YwrOffsRg;        /*!< Yaw rate offset range error */
    VDYErrState_t SwaOffsRg;        /*!< Steering wheel angle offset range error */
    VDYErrState_t AyOffsRg;         /*!< Lateral acceleration offset range error */
    VDYErrState_t VelCorrRg;        /*!< Velocity correction factor range error */
    VDYErrState_t NVMYwrOffsRg;     /*!< Eeprom Yaw rate offset range error */
    VDYErrState_t NVMSwaOffsRg;     /*!< Eeprom Steering wheel angle offset range error */
    VDYErrState_t NVMAyOffsRg;      /*!< EEprom Lateral acceleration offset range error */
    VDYErrState_t NVMVelCorrRg;     /*!< EEprom Velocity correction factor range error */
    VDYErrState_t VelCorrWin;       /*!< Velocity correction factor window error */
    VDYErrState_t VelMon;           /*!< Velocity monitoring error */
    VDYErrState_t VelMonLt;         /*!< Velocity monitoring long-term error */
    VDYErrState_t VelocityErr;      /*!< Velocity out of physical range error */
    VDYErrState_t YawRateErr;       /*!< Yaw rate out of physical range error */
    VDYErrState_t YwrMonVehHalt;    /*!< Yaw rate monitoring during vehicle halt */
    VDYErrState_t YwrMonVehDOff;    /*!< Yaw rate monitoring during vehicle drive off */
    VDYErrState_t YwrMonAdmWdrwl;   /*!< Yaw rate monitoring at admission and withdrawal of vehicle standstill */
    VDYErrState_t YwrACCMonAlignm;  /*!< ACC Yaw rate offset monitoring over alignment*/
    VDYErrState_t YwrCGMonAlignm;   /*!< CG Yaw rate offset monitoring over alignment*/
  } VDYOutError_v1_t;
  typedef struct {
    VDYErrState_t YwrOffsRg;        /*!< Yaw rate offset range error */
    VDYErrState_t SwaOffsRg;        /*!< Steering wheel angle offset range error */
    VDYErrState_t AyOffsRg;         /*!< Lateral acceleration offset range error */
    VDYErrState_t VelCorrRg;        /*!< Velocity correction factor range error */
    VDYErrState_t NVMYwrOffsRg;     /*!< Eeprom Yaw rate offset range error */
    VDYErrState_t NVMSwaOffsRg;     /*!< Eeprom Steering wheel angle offset range error */
    VDYErrState_t NVMAyOffsRg;      /*!< EEprom Lateral acceleration offset range error */
    VDYErrState_t NVMVelCorrRg;     /*!< EEprom Velocity correction factor range error */
    VDYErrState_t VelCorrWin;       /*!< Velocity correction factor window error */
    VDYErrState_t VelMon;           /*!< Velocity monitoring error */
    VDYErrState_t VelMonLt;         /*!< Velocity monitoring long-term error */
    VDYErrState_t VelocityErr;      /*!< Velocity out of physical range error */
    VDYErrState_t YawRateErr;       /*!< Yaw rate out of physical range error */
    VDYErrState_t YwrMonVehHalt;    /*!< Yaw rate monitoring during vehicle halt */
    VDYErrState_t YwrMonVehDOff;    /*!< Yaw rate monitoring during vehicle drive off */
    VDYErrState_t YwrMonAdmWdrwl;   /*!< Yaw rate monitoring at admission and withdrawal of vehicle standstill */
    VDYErrState_t YwrACCMonAlignm;  /*!< ACC Yaw rate offset monitoring over alignment*/
    VDYErrState_t YwrCGMonAlignm;   /*!< CG Yaw rate offset monitoring over alignment*/
    VDYErrState_t YwrMonVehHaltCal; /*!< Yaw rate calibration monitoring during vehicle halt */
  } VDYOutError_v2_t;
  /*! Error indication output interface */
  typedef struct {
    VDYErrState_t YwrOffsRg;        /*!< Yaw rate offset range error */
    VDYErrState_t SwaOffsRg;        /*!< Steering wheel angle offset range error */
    VDYErrState_t AyOffsRg;         /*!< Lateral acceleration offset range error */
    VDYErrState_t VelCorrRg;        /*!< Velocity correction factor range error */
    VDYErrState_t NVMYwrOffsRg;     /*!< Eeprom Yaw rate offset range error */
    VDYErrState_t NVMSwaOffsRg;     /*!< Eeprom Steering wheel angle offset range error */
    VDYErrState_t NVMAyOffsRg;      /*!< EEprom Lateral acceleration offset range error */
    VDYErrState_t NVMVelCorrRg;     /*!< EEprom Velocity correction factor range error */
    VDYErrState_t VelCorrWin;       /*!< Velocity correction factor window error */
    VDYErrState_t VelMon;           /*!< Velocity monitoring error */
    VDYErrState_t VelMonLt;         /*!< Velocity monitoring long-term error */
    VDYErrState_t VelocityErr;      /*!< Velocity out of physical range error */
    VDYErrState_t YawRateErr;       /*!< Yaw rate out of physical range error */
  } VDYOutError_v3_t;
  /*! Vehicle motion (velocity and accleration) estimation output */
  typedef struct {
    fVelocity_t         Velocity;    /*!< Estimated longitudinal vehicle velocity */
    fAcceleration_t     Accel;       /*!< Estimated longitudinal vehicle acceleration */
    fVariance_t         varVelocity;
    fVariance_t         varAccel;
  } VDYLongMotVar_t;

  /*! Steering wheel angle offset result */
  typedef struct {
    fAngle_t      Offset;
    fVariance_t   Variance;
    i32_t         State;
  } VDYSwaOffsetOut_t;

  /*! Yaw rate offset result */
  typedef struct {
    fYawRate_t    StandStillOffset;
    i32_t         StandStillState;
    fYawRate_t    DynOffset;
    fVariance_t   DynVariance;
  } VDYYwrOffsetOut_t;

  /*! Yaw rate offset result */
  typedef struct {
    fAngle_t      Offset;
    fVariance_t   Variance;
    i32_t         State;
  } VDYAyOffsetOut_t;

  /*! VDY offset results */
  typedef struct {
    VDYYwrOffsetOut_t Ywr;
    VDYSwaOffsetOut_t Swa;
    VDYAyOffsetOut_t Ay;
  } VDYOffsetsOut_t;

  #ifndef VDY_SOUT_SIZE_DW
  static const unsigned int VDY_SOUT_SIZE_DW  = (1U); /*!< Number of dwords necessary to store flags              */
  #endif

  /*! Result of the Vehicle Dynamics Module */
  typedef struct {
  #ifdef __PDO__
    VDYOutSignalState_t    State;
  #else
    VDYIoState_t           State[VDY_SOUT_SIZE_DW];   /*!< Output signal state             */
  #endif
    VDYOutCurvature_v1_t   Curve;                     /*!< Curvature of vehicle tracetory  */
    VDYOutYawRate_v1_t     YawRate;                   /*!< Estimated vehicle yaw velocity  */
    VDYOutSensorYawRate_t  SensorYawRate;             /*!< Estimated sensor yaw rate       */
    VDYOutLatAccel_t       LatAccel;                  /*!< Estimated lateral accleration   */
    VDYOutDrvIntCrv_t      DrvIntCrv;                 /*!< Driver intended curvature       */
    VDYLongMotVar_t        MotVar;                    /*!< Vehicle motion variables        */
    VDYOutLongMotState_t   MotState;                  /*!< Vehicle motion state            */
    VDYOutVelCorr_t        VelocityCorr;              /*!< Velocity correction factor      */
    VDYOutSideSlipAngle_t  BodySideSlipAngle;         /*!< Estimated side slip angle       */
    VDYOutError_v1_t       Error;                     /*!< Errors                          */
    VDYOffsetsOut_t        Offsets;                   /*!< ywr, swa, ay Offsets            */
  } VDYOutputData_v1_t;

  typedef struct {
  #ifdef __PDO__
    VDYOutSignalState_t    State;
  #else
    VDYIoState_t           State[VDY_SOUT_SIZE_DW];   /*!< Output signal state             */
  #endif
    VDYOutCurvature_v1_t   Curve;                     /*!< Curvature of vehicle tracetory  */
    VDYOutYawRate_v1_t     YawRate;                   /*!< Estimated vehicle yaw velocity  */
    VDYOutSensorYawRate_t  SensorYawRate;             /*!< Estimated sensor yaw rate       */
    VDYOutLatAccel_t       LatAccel;                  /*!< Estimated lateral accleration   */
    VDYOutDrvIntCrv_t      DrvIntCrv;                 /*!< Driver intended curvature       */
    VDYLongMotVar_t        MotVar;                    /*!< Vehicle motion variables        */
    VDYOutLongMotState_t   MotState;                  /*!< Vehicle motion state            */
    VDYOutVelCorr_t        VelocityCorr;              /*!< Velocity correction factor      */
    VDYOutSideSlipAngle_t  BodySideSlipAngle;         /*!< Estimated side slip angle       */
    VDYOutError_v2_t       Error;                     /*!< Errors                          */
    VDYOffsetsOut_t        Offsets;                   /*!< ywr, swa, ay Offsets            */
  } VDYOutputData_v2_t;
  /*! Result of the Vehicle Dynamics Module */
  typedef struct {
  #ifdef __PDO__
    VDYOutSignalState_t    State;
  #else
    VDYIoState_t           State[VDY_SOUT_SIZE_DW];   /*!< Output signal state             */
  #endif
    VDYOutCurvature_v2_t   Curve;                     /*!< Curvature of vehicle tracetory  */
    VDYOutYawRate_v2_t     YawRate;                   /*!< Estimated vehicle yaw velocity  */
    VDYOutLatAccel_t       LatAccel;                  /*!< Estimated lateral accleration   */
    VDYOutDrvIntCrv_t      DrvIntCrv;                 /*!< Driver intended curvature       */
    VDYLongMotVar_t        MotVar;                    /*!< Vehicle motion variables        */
    VDYOutLongMotState_t   MotState;                  /*!< Vehicle motion state            */
    VDYOutVelCorr_t        VelocityCorr;              /*!< Velocity correction factor      */
    VDYOutSideSlipAngle_t  BodySideSlipAngle;         /*!< Estimated side slip angle       */
    VDYOutError_v3_t       Error;                     /*!< Errors                          */
    VDYOffsetsOut_t        Offsets;                   /*!< ywr, swa, ay Offsets            */
  } VDYOutputData_v3_t;
}

/* ----------------------- VehDyn data types -------------------------*/

/* typedef MotState_t */
#ifndef   VDY_LONG_MOT_STATE_MOVE
#define VDY_LONG_MOT_STATE_MOVE	(0)
#endif
#ifndef   VDY_LONG_MOT_STATE_MOVE_FWD
#define VDY_LONG_MOT_STATE_MOVE_FWD	(1)
#endif
#ifndef   VDY_LONG_MOT_STATE_MOVE_RWD
#define VDY_LONG_MOT_STATE_MOVE_RWD	(2)
#endif
#ifndef   VDY_LONG_MOT_STATE_STDST
#define VDY_LONG_MOT_STATE_STDST	(3)
#endif

/* VehDyn_t Version 0 */
namespace VehDynV0
{

  typedef uint32                      State_array_t_1[2];          /* State of the values as bitfield () */	/* [Satisfies_rte sws 1189] */

  typedef uint8 MotState_t                /* Moving (forward or reverse)
                                          Moving forward
                                          Moving reverse
                                          Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 Velocity;                            /* Based on wheel speeds, slip compensated, uncorrected and without sign */
        float32 Accel;                               /* Longitudinal acceleration in travel direction (compensated for road gradients) */
        float32 varVelocity;                         /* Longitudinal velocity variance */
        float32 varAccel;                            /* Longitudinal acceleration variance */
      } MotVarVehDyn_t;			/* Longitudinal motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 corrFact;                            /* Velocity correction factor */
        float32 corrVar;                             /* Corrected  velocity variances */
        float32 corrVelo;                            /* Velocity with correction of forward looking beam sensor */
        float32 corrVeloVar;                         /* Corrected  velocity variances */
        float32 minVelo;                             /* Min velocity */
        float32 maxVelo;                             /* max velocity */
      } VeloCorrVehDyn_t;			/* Longitudinal Velocity correction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 corrAccel;                           /* Accel with correction of forward looking beam sensor */
        float32 corrAccelVar;                        /* Corrected  accel variances */
      } AccelCorrVehDyn_t;			/* Longitudinal acceleration correction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        MotVarVehDyn_t MotVar;                              /* Longitudinal motion variables */
        VeloCorrVehDyn_t VeloCorr;                            /* Longitudinal Velocity correction */
        AccelCorrVehDyn_t AccelCorr;                           /* Longitudinal acceleration correction */
      } Longitudinal_t;			/* Longitudinal motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 Curve;                               /* Driven vehicle curve as inverse radius (related to vehicle CoG) */
        float32 C1;                                  /* Driven vehicle curve c1 */
        float32 Gradient;                            /* Time derivative of course curvature */
        float32 varC0;                               /* Variance of course c0 curvature */
        float32 varC1;                               /* Variance of course c1 curvature */
        float32 Quality;                             /* Quality of course curvature */
      } CurveVehDyn_t;			/* Curve */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 Curve;                               /* Driver intended curvature (derived from steering wheel angle), related to vehicle CoG */
        float32 Variance;                            /* Driver intended curvature variance */
        float32 Gradient;                            /* Time derivative of dirver intended curvature */
      } DrvIntCurveVehDyn_t;			/* Driver intended curvature */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 LatAccel;                            /* Acceleration perpendicular to travel direction (road bank angle compensated), related to vehicle CoG */
        float32 Variance;                            /* Lateral acceleration variance */
      } LatAccelVehDyn_t;			/* Lateral acceleration */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 SideSlipAngle;                       /* Vehicle body side slip angle, related to CoG */
        float32 Variance;                            /* Vehicle side slip angle variance */
      } SideSlipVehDyn_t;			/* Vehice body side slip angle */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 YawRate;                             /* Estimated vehicle angular rate about vertical axis (offset compensated) */
        float32 Variance;                            /* Estimated vehicle yaw rate variance */
        float32 Quality;                             /* Estimated vehicle yaw rate quality */
      } YawRateVehDyn_t;			/* Yaw rate data */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        MotState_t MotState;                            /* Moving (forward or reverse)
  Moving forward
  Moving reverse
  Stand still */
        float32 Confidence;                          /* Confidence of motion state */
      } MotionStateVehDyn_t;			/* Lateral motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        YawRateVehDyn_t SenYawRate;                          /* Sensor yaw rate for alignment */
        float32 YawRateMaxJitter;                    /* Sync Object  (EM only) */
        boolean bStandStill;                         /* Stand Still flag */
      } LegacyVehDyn_t;			/* Vehicle sensor qualifiers */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        boolean bVelocityX;                          /* Velocity state flag */
        boolean bVelocityXCorr;                      /* Corrected velocity state flag */
        boolean bAccelY;                             /* lat accel state flag */
        boolean bAccelX;                             /* long accel statel flag */
        boolean bAccelXCorr;                         /* Corrected long accel state flag */
        boolean bYawRate;                            /* yaw rate state flag */
        boolean bSenYawRate;                         /* yaw rate state flag */
        boolean bCurve;                              /* curve state flag */
        boolean bDrvIntCurve;                        /* drv int curve state flag */
        boolean bSideSlipAngle;                      /* stide slip angel state flag */
        boolean bMotionState;                        /* motion state state flag */
      } StatesVehDyn_t;			/* Ego Dynamic states */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        YawRateVehDyn_t YawRate;                             /* Vehicle yaw rate */
        CurveVehDyn_t Curve;                               /* Curve */
        DrvIntCurveVehDyn_t DrvIntCurve;                         /* Driver intended curvature */
        LatAccelVehDyn_t Accel;                               /* Lateral acceleration */
        SideSlipVehDyn_t SlipAngle;                           /* Vehice body side slip angle */
      } Lateral_t;			/* Lateral motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        uint32 TimeStamp;                           /* Global Time Stamp */
        uint32 Version;                             /* Version of interface */
        Longitudinal_t Longitudinal;                        /* Longitudinal motion variables */
        Lateral_t Lateral;                             /* Lateral motion variables */
        MotionStateVehDyn_t MotionState;                         /* Lateral motion variables */
        LegacyVehDyn_t Legacy;                              /* Vehicle sensor qualifiers */
        State_array_t_1 State;                               /* State of the values as bitfield () */
        StatesVehDyn_t States;                              /* Ego Dynamic states */
      } VehDyn_t;		
}

/* VehDyn_t Version 1 */
namespace VehDynV1
{
  typedef uint8 MotState_t                /* Moving (forward or reverse)
                                          Moving forward
                                          Moving reverse
                                          Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 Velocity;                            /* Based on wheel speeds, slip compensated, uncorrected and without sign @min:0.0 @max:128.0 */
        float32 Accel;                               /* Longitudinal acceleration in travel direction (compensated for road gradients) @min:-20.0 @max:20.0 */
        float32 varVelocity;                         /* Longitudinal velocity variance @min:0.0 @max:1000.0 */
        float32 varAccel;                            /* Longitudinal acceleration variance @min:1.0 @max:5.0 */
      } MotVarVehDyn_t;			/* Longitudinal motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 corrFact;                            /* Velocity correction factor @min:0.8 @max:1.2 */
        float32 corrVar;                             /* Corrected  velocity variances @min:0.0 @max:5.0 */
        float32 corrVelo;                            /* Velocity with correction of forward looking beam sensor @min:0.0 @max:128.0 */
        float32 corrVeloVar;                         /* Corrected  velocity variances @min:0.0 @max:5.0 */
        float32 minVelo;                             /* Min velocity @min:0.0 @max:128.0 */
        float32 maxVelo;                             /* max velocity @min:0.0 @max:128.0 */
      } VeloCorrVehDyn_t;			/* Longitudinal Velocity correction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 corrAccel;                           /* Accel with correction of forward looking beam sensor @min:-20.0 @max:20.0 */
        float32 corrAccelVar;                        /* Corrected  accel variances @min:1.0 @max:5.0 */
      } AccelCorrVehDyn_t;			/* Longitudinal acceleration correction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        MotVarVehDyn_t MotVar;                              /* Longitudinal motion variables */
        VeloCorrVehDyn_t VeloCorr;                            /* Longitudinal Velocity correction */
        AccelCorrVehDyn_t AccelCorr;                           /* Longitudinal acceleration correction */
      } Longitudinal_t;			/* Longitudinal motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 Curve;                               /* Driven vehicle curve as inverse radius (related to vehicle CoG) @min:0.1 @max:0.9 */
        float32 C1;                                  /* Driven vehicle curve c1 @min:0.1 @max:0.9 */
        float32 Gradient;                            /* Time derivative of course curvature @min:1.0 @max:30.0 */
        float32 varC0;                               /* Variance of course c0 curvature @min:-128.0 @max:128.0 */
        float32 varC1;                               /* Variance of course c1 curvature @min:-128.0 @max:128.0 */
        float32 Quality;                             /* Quality of course curvature @min:-128.0 @max:128.0 */
      } CurveVehDyn_t;			/* Curve */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 Curve;                               /* Driver intended curvature (derived from steering wheel angle), related to vehicle CoG @min:0.0 @max:3.0 */
        float32 Variance;                            /* Driver intended curvature variance @min:-25.0 @max:25.0 */
        float32 Gradient;                            /* Time derivative of dirver intended curvature @min:-25.0 @max:25.0 */
      } DrvIntCurveVehDyn_t;			/* Driver intended curvature */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 LatAccel;                            /* Acceleration perpendicular to travel direction (road bank angle compensated), related to vehicle CoG */
        float32 Variance;                            /* Lateral acceleration variance */
      } LatAccelVehDyn_t;			/* Lateral acceleration */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 SideSlipAngle;                       /* Vehicle body side slip angle, related to CoG */
        float32 Variance;                            /* Vehicle side slip angle variance */
      } SideSlipVehDyn_t;			/* Vehice body side slip angle */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 YawRate;                             /* Estimated vehicle angular rate about vertical axis (offset compensated) */
        float32 Variance;                            /* Estimated vehicle yaw rate variance */
        float32 Quality;                             /* Estimated vehicle yaw rate quality */
      } YawRateVehDyn_t;			/* Yaw rate data */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        MotState_t MotState;                            /* Moving (forward or reverse)
  Moving forward
  Moving reverse
  Stand still */
        float32 Confidence;                          /* Confidence of motion state @min:0.0 @max:100.0 */
      } MotionStateVehDyn_t;			/* Lateral motion variables */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        float32 YawRateMaxJitter;                    /* Sync Object  (EM only) */
        boolean bStandStill;                         /* Stand Still flag */
      } LegacyVehDyn_t;			/* Vehicle sensor qualifiers */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        boolean bVelocityX;                          /* Velocity state flag */
        boolean bVelocityXCorr;                      /* Corrected velocity state flag */
        boolean bAccelY;                             /* lat accel state flag */
        boolean bAccelX;                             /* long accel statel flag */
        boolean bAccelXCorr;                         /* Corrected long accel state flag */
        boolean bYawRate;                            /* yaw rate state flag */
        boolean bSenYawRate;                         /* yaw rate state flag */
        boolean bCurve;                              /* curve state flag */
        boolean bDrvIntCurve;                        /* drv int curve state flag */
        boolean bSideSlipAngle;                      /* stide slip angel state flag */
        boolean bMotionState;                        /* motion state state flag */
      } StatesVehDyn_t;			/* Ego Dynamic states */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        YawRateVehDyn_t YawRate;                             /* Vehicle yaw rate */
        CurveVehDyn_t Curve;                               /* Curve */
        DrvIntCurveVehDyn_t DrvIntCurve;                         /* Driver intended curvature */
        LatAccelVehDyn_t Accel;                               /* Lateral acceleration */
        SideSlipVehDyn_t SlipAngle;                           /* Vehice body side slip angle */
      } Lateral_t;			/* Lateral motion variables */

  typedef uint32                    	State_array_t_0[2];          /* State of the values as bitfield @values: struct VDYOutState */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
        uint32 uiVersionNumber;                     /* Version of interface @min:0.0 @max:16277215.0 */
        uint32 TimeStamp;                           /* Global Time Stamp */
        Longitudinal_t Longitudinal;                        /* Longitudinal motion variables */
        Lateral_t Lateral;                             /* Lateral motion variables */
        MotionStateVehDyn_t MotionState;                         /* Lateral motion variables */
        LegacyVehDyn_t Legacy;                              /* Vehicle sensor qualifiers */
        State_array_t_0 State;                               /* State of the values as bitfield @values: struct VDYOutState */
        StatesVehDyn_t States;                              /* Ego Dynamic states */
      } VehDyn_t;			/* Vehicle dynamic data (VDY output) */
}

/* VehDyn_t Version 2 */
namespace VehDynV2
{
    typedef uint8 MotState_t                /* Moving (forward or reverse)
                                            Moving forward
                                            Moving reverse
                                            Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;

    typedef uint16 AlgoDataTimeStamp_t;

    typedef uint16 AlgoCycleCounter_t;

    typedef uint32 State_array_t_1[2];          /* State of the values as bitfield @values: struct VDYOutState */	/* [Satisfies_rte sws 1189] */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 Velocity;                            /* Based on wheel speeds, slip compensated, uncorrected and without sign @min:0.0 @max:128.0 */
      float32 Accel;                               /* Longitudinal acceleration in travel direction (compensated for road gradients) @min:-20.0 @max:20.0 */
      float32 varVelocity;                         /* Longitudinal velocity variance @min:0.0 @max:1000.0 */
      float32 varAccel;                            /* Longitudinal acceleration variance @min:1.0 @max:5.0 */
    } MotVarVehDyn_t;			/* Longitudinal motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 corrFact;                            /* Velocity correction factor @min:0.8 @max:1.2 */
      float32 corrVar;                             /* Corrected  velocity variances @min:0.0 @max:5.0 */
      float32 corrVelo;                            /* Velocity with correction of forward looking beam sensor @min:0.0 @max:128.0 */
      float32 corrVeloVar;                         /* Corrected  velocity variances @min:0.0 @max:5.0 */
      float32 minVelo;                             /* Min velocity @min:0.0 @max:128.0 */
      float32 maxVelo;                             /* max velocity @min:0.0 @max:128.0 */
    } VeloCorrVehDyn_t;			/* Longitudinal Velocity correction */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 corrAccel;                           /* Accel with correction of forward looking beam sensor @min:-20.0 @max:20.0 */
      float32 corrAccelVar;                        /* Corrected  accel variances @min:1.0 @max:5.0 */
    } AccelCorrVehDyn_t;			/* Longitudinal acceleration correction */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      MotVarVehDyn_t MotVar;                              /* Longitudinal motion variables */
      VeloCorrVehDyn_t VeloCorr;                            /* Longitudinal Velocity correction */
      AccelCorrVehDyn_t AccelCorr;                           /* Longitudinal acceleration correction */
    } Longitudinal_t;			/* Longitudinal motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 Curve;                               /* Driven vehicle curve as inverse radius (related to vehicle CoG) @min:0.1 @max:0.9 */
      float32 C1;                                  /* Driven vehicle curve c1 @min:0.1 @max:0.9 */
      float32 Gradient;                            /* Time derivative of course curvature @min:1.0 @max:30.0 */
      float32 varC0;                               /* Variance of course c0 curvature @min:-128.0 @max:128.0 */
      float32 varC1;                               /* Variance of course c1 curvature @min:-128.0 @max:128.0 */
      float32 Quality;                             /* Quality of course curvature @min:-128.0 @max:128.0 */
    } CurveVehDyn_t;			/* Curve */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 Curve;                               /* Driver intended curvature (derived from steering wheel angle), related to vehicle CoG @min:0.0 @max:3.0 */
      float32 Variance;                            /* Driver intended curvature variance @min:-25.0 @max:25.0 */
      float32 Gradient;                            /* Time derivative of dirver intended curvature @min:-25.0 @max:25.0 */
    } DrvIntCurveVehDyn_t;			/* Driver intended curvature */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 LatAccel;                            /* Acceleration perpendicular to travel direction (road bank angle compensated), related to vehicle CoG */
      float32 Variance;                            /* Lateral acceleration variance */
    } LatAccelVehDyn_t;			/* Lateral acceleration */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 SideSlipAngle;                       /* Vehicle body side slip angle, related to CoG */
      float32 Variance;                            /* Vehicle side slip angle variance */
    } SideSlipVehDyn_t;			/* Vehice body side slip angle */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 YawRate;                             /* Estimated vehicle angular rate about vertical axis (offset compensated) */
      float32 Variance;                            /* Estimated vehicle yaw rate variance */
      float32 Quality;                             /* Estimated vehicle yaw rate quality */
    } YawRateVehDyn_t;			/* Yaw rate data */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      MotState_t MotState;                            /* Moving (forward or reverse) Moving forward Moving reverse Stand still */
      float32 Confidence;                          /* Confidence of motion state @min:0.0 @max:100.0 */
    } MotionStateVehDyn_t;			/* Lateral motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 YawRateMaxJitter;                    /* Sync Object  (EM only) */
      boolean bStandStill;                         /* Stand Still flag */
    } LegacyVehDyn_t;			/* Vehicle sensor qualifiers */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      YawRateVehDyn_t YawRate;                             /* Vehicle yaw rate */
      CurveVehDyn_t Curve;                               /* Curve */
      DrvIntCurveVehDyn_t DrvIntCurve;                         /* Driver intended curvature */
      LatAccelVehDyn_t Accel;                               /* Lateral acceleration */
      SideSlipVehDyn_t SlipAngle;                           /* Vehice body side slip angle */
    } Lateral_t;			/* Lateral motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      uint32 uiVersionNumber;                     /* Version of interface @min:0.0 @max:16277215.0 */
      AlgoDataTimeStamp_t uiTimeStamp;                         /* Time stamp of data */
      AlgoCycleCounter_t uiCycleCounter;                      /* Cycle counter of producer algo */
      Longitudinal_t Longitudinal;                        /* Longitudinal motion variables */
      Lateral_t Lateral;                             /* Lateral motion variables */
      MotionStateVehDyn_t MotionState;                         /* Lateral motion variables */
      LegacyVehDyn_t Legacy;                              /* Vehicle sensor qualifiers */
      State_array_t_1 State;                               /* State of the values as bitfield @values: struct VDYOutState */
    } VehDyn_t;			/* Vehicle dynamic data (VDY output) */
  };  /* end of namespace VehDynV2 */

  /* VehDyn_t Version 2 */
  namespace VehDynV3
  {
    typedef uint8 MotState_t                /* Moving (forward or reverse)
                                            Moving forward
                                            Moving reverse
                                            Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;

    typedef uint16 AlgoDataTimeStamp_t;

    typedef uint16 AlgoCycleCounter_t;

    typedef uint8 CorrQual_t;                 /* Moving (forward or reverse)*/

    typedef uint32                    	State_array_t_4[2];          /* State of the values as bitfield @values: struct VDYOutState */	/* [Satisfies_rte sws 1189] */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 Velocity;                            /* Based on wheel speeds, slip compensated, uncorrected and without sign @min:0.0 @max:128.0 */
      float32 Accel;                               /* Longitudinal acceleration in travel direction (compensated for road gradients) @min:-20.0 @max:20.0 */
      float32 varVelocity;                         /* Longitudinal velocity variance @min:0.0 @max:1000.0 */
      float32 varAccel;                            /* Longitudinal acceleration variance @min:1.0 @max:5.0 */
    } MotVarVehDyn_t;			/* Longitudinal motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 corrFact;                            /* Velocity correction factor @min:0.8 @max:1.2 */
      float32 corrVar;                             /* Corrected  velocity variances @min:0.0 @max:5.0 */
      float32 corrVelo;                            /* Velocity with correction of forward looking beam sensor @min:0.0 @max:128.0 */
      float32 corrVeloVar;                         /* Corrected  velocity variances @min:0.0 @max:5.0 */
      float32 minVelo;                             /* Min velocity @min:0.0 @max:128.0 */
      float32 maxVelo;                             /* max velocity @min:0.0 @max:128.0 */
      CorrQual_t corrQual;                        /* Velocity correction quality flag */
    } VeloCorrVehDyn_t;			/* Longitudinal Velocity correction */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 corrAccel;                           /* Accel with correction of forward looking beam sensor @min:-20.0 @max:20.0 */
      float32 corrAccelVar;                        /* Corrected  accel variances @min:1.0 @max:5.0 */
    } AccelCorrVehDyn_t;			/* Longitudinal acceleration correction */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      MotVarVehDyn_t MotVar;                              /* Longitudinal motion variables */
      VeloCorrVehDyn_t VeloCorr;                            /* Longitudinal Velocity correction */
      AccelCorrVehDyn_t AccelCorr;                           /* Longitudinal acceleration correction */
    } Longitudinal_t;			/* Longitudinal motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 Curve;                               /* Driven vehicle curve as inverse radius (related to vehicle CoG) @min:0.1 @max:0.9 */
      float32 C1;                                  /* Driven vehicle curve c1 @min:0.1 @max:0.9 */
      float32 Gradient;                            /* Time derivative of course curvature @min:1.0 @max:30.0 */
      float32 varC0;                               /* Variance of course c0 curvature @min:-128.0 @max:128.0 */
      float32 varC1;                               /* Variance of course c1 curvature @min:-128.0 @max:128.0 */
      float32 Quality;                             /* Quality of course curvature @min:-128.0 @max:128.0 */
    } CurveVehDyn_t;			/* Curve */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 Curve;                               /* Driver intended curvature (derived from steering wheel angle), related to vehicle CoG @min:0.0 @max:3.0 */
      float32 Variance;                            /* Driver intended curvature variance @min:-25.0 @max:25.0 */
      float32 Gradient;                            /* Time derivative of dirver intended curvature @min:-25.0 @max:25.0 */
    } DrvIntCurveVehDyn_t;			/* Driver intended curvature */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 LatAccel;                            /* Acceleration perpendicular to travel direction (road bank angle compensated), related to vehicle CoG */
      float32 Variance;                            /* Lateral acceleration variance */
    } LatAccelVehDyn_t;			/* Lateral acceleration */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 SideSlipAngle;                       /* Vehicle body side slip angle, related to CoG */
      float32 Variance;                            /* Vehicle side slip angle variance */
    } SideSlipVehDyn_t;			/* Vehice body side slip angle */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 YawRate;                             /* Estimated vehicle angular rate about vertical axis (offset compensated) */
      float32 Variance;                            /* Estimated vehicle yaw rate variance */
      float32 Quality;                             /* Estimated vehicle yaw rate quality */
    } YawRateVehDyn_t;			/* Yaw rate data */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      MotState_t MotState;                            /* Moving (forward or reverse)
                                                      Moving forward
                                                      Moving reverse
                                                      Stand still */
      float32 Confidence;                          /* Confidence of motion state @min:0.0 @max:100.0 */
    } MotionStateVehDyn_t;			/* Lateral motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      float32 YawRateMaxJitter;                    /* Sync Object  (EM only) */
      boolean bStandStill;                         /* Stand Still flag */
    } LegacyVehDyn_t;			/* Vehicle sensor qualifiers */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      YawRateVehDyn_t YawRate;                             /* Vehicle yaw rate */
      CurveVehDyn_t Curve;                               /* Curve */
      DrvIntCurveVehDyn_t DrvIntCurve;                         /* Driver intended curvature */
      LatAccelVehDyn_t Accel;                               /* Lateral acceleration */
      SideSlipVehDyn_t SlipAngle;                           /* Vehice body side slip angle */
    } Lateral_t;			/* Lateral motion variables */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      uint32 uiVersionNumber;                     /* Version of interface @min:0.0 @max:16277215.0 */
      AlgoDataTimeStamp_t uiTimeStamp;                         /* Time stamp of data */
      AlgoCycleCounter_t uiCycleCounter;                      /* Cycle counter of producer algo */
      Longitudinal_t Longitudinal;                        /* Longitudinal motion variables */
      Lateral_t Lateral;                             /* Lateral motion variables */
      MotionStateVehDyn_t MotionState;                         /* Lateral motion variables */
      LegacyVehDyn_t Legacy;                              /* Vehicle sensor qualifiers */
      State_array_t_4 State;                               /* State of the values as bitfield @values: struct VDYOutState */
    } VehDyn_t;			/* Vehicle dynamic data (VDY output) */
  };  /* end of namespace VehDynV3 */

  namespace VehDynV5 {

    typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;
    typedef uint8 corrQual_t                /* Velocity correction quality flag @min: 0 @max:3 @values: enum { VDY_VELO_CORR_QUAL_RANGE_NVERIFIED=1,VDY_VELO_CORR_QUAL_RANGE_VERIFIED=2,VDY_VELO_CORR_QUAL_EEPROM=0,VDY_VELO_CORR_QUAL_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
    typedef uint8 MotState_t                /* Moving (forward or reverse)
                                            Moving forward
                                            Moving reverse
                                            Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;
    typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0.0 @max:65535.0 */	/* [Satisfies_rte sws 1188] */;
    typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0.0 @max:4294967295.0 */	/* [Satisfies_rte sws 1188] */;
    typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0.0 @max:4294967295.0 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
    typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

    /* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
    const AlgoSignalState_t AL_SIG_STATE_INIT    = (0);
#endif
#ifndef AL_SIG_STATE_OK
    const AlgoSignalState_t AL_SIG_STATE_OK      = (1);
#endif
#ifndef AL_SIG_STATE_INVALID
    const AlgoSignalState_t AL_SIG_STATE_INVALID = (2);
#endif

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      AlgoDataTimeStamp_t uiTimeStamp;
      AlgoCycleCounter_t uiMeasurementCounter;
      AlgoCycleCounter_t uiCycleCounter;
      AlgoSignalState_t eSigStatus;
    } SignalHeader_t;			/* Common header for all structured data types */

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

    typedef uint32                    	State_array_t[2];/* State of the values as bitfield @values: struct VDYOutState */	/* [Satisfies_rte sws 1189] */
    /* State of the values as bitfield @values: struct VDYOutState */			/* [Satisfies_rte_sws_1189] */
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
      SignalHeader_t sSignalHeader;
      Longitudinal_t Longitudinal;
      Lateral_t Lateral;
      MotionStateVehDyn_t MotionState;
      LegacyVehDyn_t Legacy;
      State_array_t State;
    } VehDyn_t;			/* Vehicle dynamic data (VDY output) @vaddr:RADAR_MEAS_ID_VEH_DYN, VDY_MEAS_ID_VEH_DYN @cycleid:RSP_ENV,vdy_cycle_id @vname:RadarVehDyn,VehDyn */
  }

namespace VehDynV6
{
  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;
  typedef uint8 corrQual_t                /* Velocity correction quality flag @min: 0 @max:3 @values: enum { VDY_VELO_CORR_QUAL_RANGE_NVERIFIED=1,VDY_VELO_CORR_QUAL_RANGE_VERIFIED=2,VDY_VELO_CORR_QUAL_EEPROM=0,VDY_VELO_CORR_QUAL_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 MotState_t                /* Moving (forward or reverse)
                                          Moving forward
                                          Moving reverse
                                          Stand still @min: 0 @max:3 @values: enum { VDY_LONG_MOT_STATE_MOVE_RWD=2,VDY_LONG_MOT_STATE_STDST=3,VDY_LONG_MOT_STATE_MOVE_FWD=1,VDY_LONG_MOT_STATE_MOVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0.0 @max:65535.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0.0 @max:4294967295.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0.0 @max:4294967295.0 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  const AlgoSignalState_t AL_SIG_STATE_INIT    = (0);
#endif
#ifndef AL_SIG_STATE_OK
  const AlgoSignalState_t AL_SIG_STATE_OK      = (1);
#endif
#ifndef AL_SIG_STATE_INVALID
  const AlgoSignalState_t AL_SIG_STATE_INVALID = (2);
#endif

  /*! External interface states version 8 and higher */
  const uint8 VEH_DYN_IO_STATE_VALID = 0U;
  const uint8 VEH_DYN_IO_STATE_INVALID = 1U;
  const uint8 VEH_DYN_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_DYN_IO_STATE_DECREASED = 3U;
  const uint8 VEH_DYN_IO_STATE_SUBSTITUE = 4U;
  const uint8 VEH_DYN_IO_STATE_INIT = 15U;
  const uint8 VEH_DYN_IO_STATE_MAX = 255U;

  /* typedef VehDynStatePos_t */
  const uint8 VEH_DYN_SOUT_POS_CURVE = (0);
  const uint8 VEH_DYN_SOUT_POS_YWR = (1);
  const uint8 VEH_DYN_SOUT_POS_DRCRV = (2);
  const uint8 VEH_DYN_SOUT_POS_VEL = (3);
  const uint8 VEH_DYN_SOUT_POS_ACCEL = (4);
  const uint8 VEH_DYN_SOUT_POS_MSTAT = (5);
  const uint8 VEH_DYN_SOUT_POS_VCORR = (6);
  const uint8 VEH_DYN_SOUT_POS_SSA = (7);
  const uint8 VEH_DYN_SOUT_POS_LATACC = (8);
  const uint8 VEH_DYN_SOUT_POS_MAX = (12);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 corrAccel;
    float32 corrAccelVar;
  } AccelCorrVehDyn_t;			/* Longitudinal acceleration correction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float Curve;
    float C1;
    float Gradient;
    float varC0;
    float varC1;
    float Quality;
    float CrvError;
    unsigned char CrvConf;
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

  typedef uint8	State_array_t[VEH_DYN_SOUT_POS_MAX];/* State of the values as bitfield @values: struct VDYOutState */	/* [Satisfies_rte sws 1189] */

  /* State of the values as bitfield @values: struct VDYOutState */			/* [Satisfies_rte_sws_1189] */
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
  } VehDyn_t;			/* Vehicle dynamic data (VDY output) @vaddr:RADAR_MEAS_ID_VEH_DYN, VDY_MEAS_ID_VEH_DYN @cycleid:RSP_ENV,vdy_cycle_id @vname:RadarVehDyn,VehDyn */
} // end of VehDynV6

namespace VehDynV6_2
{
	/*! External interface states version 8 and higher */
	  const uint8 VEH_DYN_IO_STATE_VALID = 0U;
	  const uint8 VEH_DYN_IO_STATE_INVALID = 1U;
	  const uint8 VEH_DYN_IO_STATE_NOTAVAIL = 2U;
	  const uint8 VEH_DYN_IO_STATE_DECREASED = 3U;
	  const uint8 VEH_DYN_IO_STATE_SUBSTITUE = 4U;
	  const uint8 VEH_DYN_IO_STATE_INIT = 15U;
	  const uint8 VEH_DYN_IO_STATE_MAX = 255U;
    
    /* typedef VehDynStatePos_t */
	  const uint8 VEH_DYN_SOUT_POS_CURVE = (0);
	  const uint8 VEH_DYN_SOUT_POS_YWR = (1);
	  const uint8 VEH_DYN_SOUT_POS_DRCRV = (2);
	  const uint8 VEH_DYN_SOUT_POS_VEL = (3);
	  const uint8 VEH_DYN_SOUT_POS_ACCEL = (4);
	  const uint8 VEH_DYN_SOUT_POS_MSTAT = (5);
	  const uint8 VEH_DYN_SOUT_POS_VCORR = (6);
	  const uint8 VEH_DYN_SOUT_POS_SSA = (7);
	  const uint8 VEH_DYN_SOUT_POS_LATACC = (8);
	  const uint8 VEH_DYN_SOUT_POS_MAX = (12);

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    VehDynV6::YawRateVehDyn_t YawRate;
    float OffCompStWheelAngle;
    VehDynV6::CurveVehDyn_t Curve;
    VehDynV6::DrvIntCurveVehDyn_t DrvIntCurve;
    VehDynV6::LatAccelVehDyn_t Accel;
    VehDynV6::SideSlipVehDyn_t SlipAngle;
  } Lateral_t;                                                       /* Lateral motion variables */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    VehDynV6::AlgoInterfaceVersionNumber_t uiVersionNumber;
    VehDynV6::SignalHeader_t sSigHeader;
    VehDynV6::Longitudinal_t Longitudinal;
    Lateral_t Lateral;
    VehDynV6::MotionStateVehDyn_t MotionState;
    VehDynV6::LegacyVehDyn_t Legacy;
    VehDynV6::State_array_t State;
  } VehDyn_t;                                                        /* Vehicle dynamic data (VDY output) @vaddr:RADAR_MEAS_ID_VEH_DYN, VDY_MEAS_ID_VEH_DYN @cycleid:RSP_ENV,vdy_cycle_id @vname:RadarVehDyn,VehDyn */
} // end of VehDynV6_2

namespace VehDynV8
{
  /*! External interface states version 8 and higher */
  const uint8 VEH_DYN_IO_STATE_VALID = 0U;
  const uint8 VEH_DYN_IO_STATE_INVALID = 1U;
  const uint8 VEH_DYN_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_DYN_IO_STATE_DECREASED = 3U;
  const uint8 VEH_DYN_IO_STATE_SUBSTITUE = 4U;
  const uint8 VEH_DYN_IO_STATE_INIT = 15U;
  const uint8 VEH_DYN_IO_STATE_MAX = 255U;

  /* typedef VehDynStatePos_t */
  const uint8 VEH_DYN_SOUT_POS_CURVE = (0);
  const uint8 VEH_DYN_SOUT_POS_YWR = (1);
  const uint8 VEH_DYN_SOUT_POS_DRCRV = (2);
  const uint8 VEH_DYN_SOUT_POS_VEL = (3);
  const uint8 VEH_DYN_SOUT_POS_ACCEL = (4);
  const uint8 VEH_DYN_SOUT_POS_MSTAT = (5);
  const uint8 VEH_DYN_SOUT_POS_VCORR = (6);
  const uint8 VEH_DYN_SOUT_POS_SSA = (7);
  const uint8 VEH_DYN_SOUT_POS_LATACC = (8);
  const uint8 VEH_DYN_SOUT_POS_MAX = (12);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 corrFact;
    float32 corrVar;
    float32 corrVelo;
    float32 corrVeloVar;
    float32 minVelo;
    float32 maxVelo;
    VehDynV6::corrQual_t corrQual;
    boolean bRollerTestBench;
  } VeloCorrVehDyn_t;			/* Longitudinal Velocity correction */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    VehDynV6::MotVarVehDyn_t MotVar;
    VeloCorrVehDyn_t VeloCorr;
    VehDynV6::AccelCorrVehDyn_t AccelCorr;
  } Longitudinal_t;			/* Longitudinal motion variables */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    VehDynV6::AlgoInterfaceVersionNumber_t uiVersionNumber;
    VehDynV6::SignalHeader_t sSigHeader;
    Longitudinal_t Longitudinal;
    VehDynV6_2::Lateral_t Lateral;
    VehDynV6::MotionStateVehDyn_t MotionState;
    VehDynV6::LegacyVehDyn_t Legacy;
    VehDynV6::State_array_t State;
  } VehDyn_t;                                                        /* Vehicle dynamic data (VDY output) @vaddr:RADAR_MEAS_ID_VEH_DYN, VDY_MEAS_ID_VEH_DYN @cycleid:RSP_ENV,vdy_cycle_id @vname:RadarVehDyn,VehDyn */
} // end of VehDynV8

namespace VehDynV9                                                   /* For ARS510 */
{
  #define VAR(vartype, memclass) vartype

  typedef VAR(unsigned long, TYPEDEF) AlgoInterfaceVersionNumber_t;
  typedef VAR(float, TYPEDEF) fVelocity_t;
  typedef VAR(float, TYPEDEF) fAccel_t;
  typedef VAR(float, TYPEDEF) fVariance_t;
  typedef VAR(unsigned char, TYPEDEF) VelocityCorrectionQuality_t;
  typedef VAR(float, TYPEDEF) fYawRate_t;
  typedef VAR(float, TYPEDEF) fCurve_t;
  typedef VAR(unsigned char, TYPEDEF) MotState_t;
  typedef VAR(unsigned char, TYPEDEF) ucConfidence_t;
  typedef VAR(unsigned char, TYPEDEF) VDYIoStateTypes_t;
  typedef VAR(VDYIoStateTypes_t, TYPEDEF) State_array_t[8];

  typedef struct
  {
    VAR(fVelocity_t, TYPEDEF) Velocity;
    VAR(fAccel_t, TYPEDEF) Accel;
    VAR(fVariance_t, TYPEDEF) varVelocity;
    VAR(fVariance_t, TYPEDEF) varAccel;
    VAR(VelocityCorrectionQuality_t, TYPEDEF) VelocityCorrectionQuality;
  } Longitudinal_t;

  typedef struct
  {
    VAR(fYawRate_t, TYPEDEF) YawRate;
    VAR(fVariance_t, TYPEDEF) Variance;
  } YawRateVehDyn_t;

  typedef struct
  {
    VAR(fCurve_t, TYPEDEF) Curve;
    VAR(fVariance_t, TYPEDEF) VarCurve;
    VAR(float, TYPEDEF) CrvError;
    VAR(unsigned char, TYPEDEF) CrvConf;
  } CurveVehDyn_t;

  typedef struct
  {
    VAR(fCurve_t, TYPEDEF) Curve;
    VAR(fVariance_t, TYPEDEF) Variance;
  } DrvIntCurveVehDyn_t;

  typedef struct
  {
    VAR(float, TYPEDEF) LatAccel;
    VAR(fVariance_t, TYPEDEF) Variance;
  } LatAccelVehDyn_t;

  typedef struct
  {
    VAR(float, TYPEDEF) SideSlipAngle;
    VAR(float, TYPEDEF) Variance;
  } SideSlipVehDyn_t;

  typedef struct
  {
    VAR(YawRateVehDyn_t, TYPEDEF) YawRate;
    VAR(CurveVehDyn_t, TYPEDEF) Curve;
    VAR(DrvIntCurveVehDyn_t, TYPEDEF) DrvIntCurve;
    VAR(LatAccelVehDyn_t, TYPEDEF) Accel;
    VAR(SideSlipVehDyn_t, TYPEDEF) SlipAngle;
  } Lateral_t;

  typedef struct
  {
    VAR(MotState_t, TYPEDEF) MotState;
    VAR(ucConfidence_t, TYPEDEF) Confidence;
    VAR(boolean, TYPEDEF) bRollerTestBench;
  } MotionStateVehDyn_t;

  typedef struct
  {
    VAR(AlgoInterfaceVersionNumber_t, TYPEDEF) uiVersionNumber;
    VAR(VehDynV6::SignalHeader_t, TYPEDEF) sSigHeader;
    VAR(Longitudinal_t, TYPEDEF) Longitudinal;
    VAR(Lateral_t, TYPEDEF) Lateral;
    VAR(MotionStateVehDyn_t, TYPEDEF) MotionState;
    VAR(State_array_t, TYPEDEF) State;
  } VehDyn_t;
} // end of VehDynV9

namespace VehDynV32                                                  /* For ARS510 */
{
  #define VAR(vartype, memclass) vartype

  typedef VAR(unsigned long, TYPEDEF) AlgoInterfaceVersionNumber_t;
  typedef VAR(float, TYPEDEF) fCurve_t;
  typedef VAR(float, TYPEDEF) fVariance_t;

  typedef struct
  {
    VAR(fCurve_t, TYPEDEF) Curve;
    VAR(fVariance_t, TYPEDEF) Variance;
    VAR(float, TYPEDEF) Gradient;
  } DrvIntCurveVehDyn_t;

  typedef struct
  {
    VAR(VehDynV9::YawRateVehDyn_t, TYPEDEF) YawRate;
    VAR(VehDynV9::CurveVehDyn_t, TYPEDEF) Curve;
    VAR(DrvIntCurveVehDyn_t, TYPEDEF) DrvIntCurve;
    VAR(VehDynV9::LatAccelVehDyn_t, TYPEDEF) Accel;
    VAR(VehDynV9::SideSlipVehDyn_t, TYPEDEF) SlipAngle;
  } Lateral_t;

  typedef struct
  {
    VAR(AlgoInterfaceVersionNumber_t, TYPEDEF) uiVersionNumber;
    VAR(VehDynV6::SignalHeader_t, TYPEDEF) sSigHeader;
    VAR(VehDynV9::Longitudinal_t, TYPEDEF) Longitudinal;
    VAR(Lateral_t, TYPEDEF) Lateral;
    VAR(VehDynV9::MotionStateVehDyn_t, TYPEDEF) MotionState;
    VAR(VehDynV9::State_array_t, TYPEDEF) State;
  } VehDyn_t;
} // end of VehDynV32

#endif // interfacevehdyn_h__
